/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_dump_EPS.h"
#include "ed_dump_val.h"

#define DUMPSTR(a) OStream->WriteString (OStream, a)
void Dump_c_RemoteUEContext_Identity (TEDOStream* OStream, const c_RemoteUEContext_Identity* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RemoteUEContext_Identity");
	ED_Dump_Struct_Begin_Field (OStream, "RemoteUEContext_Identity", "IdentityType");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<IdentityType> ACCESS=<Data->IdentityType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->IdentityType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "Encrypted IMSI"); break;
				case 2: OStream->WriteString (OStream, "IMSI"); break;
				case 3: OStream->WriteString (OStream, "MSISDN"); break;
				case 4: OStream->WriteString (OStream, "IMEI"); break;
				case 5: OStream->WriteString (OStream, "IMEISV"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "RemoteUEContext_Identity", "IdentityType");
	ED_Dump_Struct_Begin_Field (OStream, "RemoteUEContext_Identity", "IdentityDigit");
		/* SEQUENCE NAME=<IdentityDigit> ACCESS=<Data->IdentityDigit>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "IdentityDigit", Data->IdentityDigit.items);
		for (i0=0; i0<Data->IdentityDigit.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->IdentityDigit.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->IdentityDigit.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		}
		ED_Dump_Sequence_End (OStream, "IdentityDigit", Data->IdentityDigit.items);
	ED_Dump_Struct_End_Field (OStream, "RemoteUEContext_Identity", "IdentityDigit");
	ED_Dump_Struct_End (OStream, "RemoteUEContext_Identity");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsProtocolCfg (TEDOStream* OStream, const c_epsProtocolCfg* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsProtocolCfg");
	ED_Dump_Struct_Begin_Field (OStream, "epsProtocolCfg", "ProtocolId");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<ProtocolId> ACCESS=<Data->ProtocolId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->ProtocolId)
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
				case 12: OStream->WriteString (OStream, "P-CSCF IPv4 Address Request"); break;
				case 13: OStream->WriteString (OStream, "DNS Server IPv4 Address Request"); break;
				case 14: OStream->WriteString (OStream, "MSISDN Request"); break;
				case 15: OStream->WriteString (OStream, "IFOM-Support-Request"); break;
				case 16: OStream->WriteString (OStream, "IPv4 Link MTU Request"); break;
				case 17: OStream->WriteString (OStream, "MS support of Local address in TFT indicator"); break;
				case 18: OStream->WriteString (OStream, "P-CSCF Re-selection support"); break;
				case 19: OStream->WriteString (OStream, "NBIFOM request/accepted indicator"); break;
				case 20: OStream->WriteString (OStream, "NBIFOM mode"); break;
				case 21: OStream->WriteString (OStream, "Non-IP Link MTU Request"); break;
				case 22: OStream->WriteString (OStream, "APN rate control support indicator"); break;
				case 32801: OStream->WriteString (OStream, "IPCP"); break;
				case 49185: OStream->WriteString (OStream, "LCP"); break;
				case 49187: OStream->WriteString (OStream, "PAP"); break;
				case 49699: OStream->WriteString (OStream, "CHAP"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsProtocolCfg", "ProtocolId");
	ED_Dump_Struct_Begin_Field (OStream, "epsProtocolCfg", "Contents");
	  /* NAME=<Contents> ACCESS=<Data->Contents>  MAXBITSIZE=<512> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Contents.value, Data->Contents.usedBits);
	ED_Dump_Struct_End_Field (OStream, "epsProtocolCfg", "Contents");
	ED_Dump_Struct_End (OStream, "epsProtocolCfg");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RemoteUEContext_SingleContext (TEDOStream* OStream, const c_RemoteUEContext_SingleContext* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RemoteUEContext_SingleContext");
	ED_Dump_Struct_Begin_Field (OStream, "RemoteUEContext_SingleContext", "UserIDs");
		/* SEQUENCE NAME=<UserIDs> ACCESS=<Data->UserIDs>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "UserIDs", Data->UserIDs.items);
		for (i0=0; i0<Data->UserIDs.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "UserIDs", i0, Data->UserIDs.items);
		  /* STRUCTURAL=<1> TYPE=<c_RemoteUEContext_Identity> NAME=<data> ACCESS=<*(Data->UserIDs.data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_RemoteUEContext_Identity> */
		  Dump_c_RemoteUEContext_Identity (OStream, &(*(Data->UserIDs.data [i0])));
			ED_Dump_Sequence_End_Field (OStream, "UserIDs", i0, Data->UserIDs.items);
		}
		ED_Dump_Sequence_End (OStream, "UserIDs", Data->UserIDs.items);
	ED_Dump_Struct_End_Field (OStream, "RemoteUEContext_SingleContext", "UserIDs");
	ED_Dump_Struct_End (OStream, "RemoteUEContext_SingleContext");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentity_Type2 (TEDOStream* OStream, const c_PartialTrackingAreaIdentity_Type2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PartialTrackingAreaIdentity_Type2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentity_Type2", "TAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<TAC> ACCESS=<Data->TAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TAC);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentity_Type2", "TAC");
	ED_Dump_Struct_End (OStream, "PartialTrackingAreaIdentity_Type2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentityList_TACS (TEDOStream* OStream, const c_PartialTrackingAreaIdentityList_TACS* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<16> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<ED_SHORT> NAME=<data> ACCESS=<Data->data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->data [i0]);
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsProtocolCfgList (TEDOStream* OStream, const c_epsProtocolCfgList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<12> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_epsProtocolCfg> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_epsProtocolCfg> */
	  Dump_c_epsProtocolCfg (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentityList_Type0 (TEDOStream* OStream, const c_PartialTrackingAreaIdentityList_Type0* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PartialTrackingAreaIdentityList_Type0");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "TAC");
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_TACS> NAME=<TAC> ACCESS=<Data->TAC>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentityList_TACS> */
	  Dump_c_PartialTrackingAreaIdentityList_TACS (OStream, &(Data->TAC));
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type0", "TAC");
	ED_Dump_Struct_End (OStream, "PartialTrackingAreaIdentityList_Type0");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentityList_Type1 (TEDOStream* OStream, const c_PartialTrackingAreaIdentityList_Type1* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PartialTrackingAreaIdentityList_Type1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_Type1_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "TypeOfList");
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_Type1_TypeOfList> NAME=<TypeOfList> ACCESS=<Data->TypeOfList>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "TypeOfList");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "NumberOfElements");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumberOfElements> ACCESS=<Data->NumberOfElements>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NumberOfElements);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "NumberOfElements");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "TAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<TAC> ACCESS=<Data->TAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TAC);
	ED_Dump_Struct_End_Field (OStream, "PartialTrackingAreaIdentityList_Type1", "TAC");
	ED_Dump_Struct_End (OStream, "PartialTrackingAreaIdentityList_Type1");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PDNAddress (TEDOStream* OStream, const c_PDNAddress* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PDNAddress");
	ED_Dump_Struct_Begin_Field (OStream, "PDNAddress", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PDNAddress_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PDNAddress", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PDNAddress", "PDNType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PDNType> ACCESS=<Data->PDNType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PDNType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "IPv4"); break;
				case 2: OStream->WriteString (OStream, "IPv6"); break;
				case 3: OStream->WriteString (OStream, "IPv4v6"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDNAddress", "PDNType");
	ED_Dump_Struct_Begin_Field (OStream, "PDNAddress", "PDNAddressInformation");
	  /* NAME=<PDNAddressInformation> ACCESS=<Data->PDNAddressInformation>  MAXBITSIZE=<96> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->PDNAddressInformation.value, Data->PDNAddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "PDNAddress", "PDNAddressInformation");
	ED_Dump_Struct_End (OStream, "PDNAddress");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsReAttemptIndicator (TEDOStream* OStream, const c_epsReAttemptIndicator* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsReAttemptIndicator", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsReAttemptIndicator_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsReAttemptIndicator", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsReAttemptIndicator", "EPLMNC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EPLMNC> ACCESS=<Data->EPLMNC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->EPLMNC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "UE is allowed to re-attempt the procedure in an equivalent PLMN"); break;
				case 1: OStream->WriteString (OStream, "UE is not allowed to re-attempt the procedure in an equivalent PLMN"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsReAttemptIndicator", "EPLMNC");
	ED_Dump_Struct_Begin_Field (OStream, "epsReAttemptIndicator", "RATC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<RATC> ACCESS=<Data->RATC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->RATC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "UE is allowed to re-attempt the procedure in A/Gb mode or Iu mode"); break;
				case 1: OStream->WriteString (OStream, "UE is not allowed to re-attempt the procedure in A/Gb mode or Iu mode"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsReAttemptIndicator", "RATC");
	ED_Dump_Struct_End (OStream, "epsReAttemptIndicator");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PKMFAddress (TEDOStream* OStream, const c_PKMFAddress* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PKMFAddress");
	ED_Dump_Struct_Begin_Field (OStream, "PKMFAddress", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PKMFAddress_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PKMFAddress", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PKMFAddress", "addressType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<addressType> ACCESS=<Data->addressType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->addressType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "IPv4"); break;
				case 2: OStream->WriteString (OStream, "IPv6"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PKMFAddress", "addressType");
	ED_Dump_Struct_Begin_Field (OStream, "PKMFAddress", "AddressInformation");
	  /* NAME=<AddressInformation> ACCESS=<Data->AddressInformation>  MAXBITSIZE=<120> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AddressInformation.value, Data->AddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "PKMFAddress", "AddressInformation");
	ED_Dump_Struct_End (OStream, "PKMFAddress");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HeaderCompressionCfg (TEDOStream* OStream, const c_HeaderCompressionCfg* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HeaderCompressionCfg");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "Spare");
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfg_Spare> NAME=<Spare> ACCESS=<Data->Spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "Spare");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0104");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0104> ACCESS=<Data->P0x0104>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0104);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0104");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0103");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0103> ACCESS=<Data->P0x0103>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0103);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0103");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0102");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0102> ACCESS=<Data->P0x0102>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0102);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0102");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0006");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0006> ACCESS=<Data->P0x0006>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0006);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0006");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0004");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0004> ACCESS=<Data->P0x0004>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0004);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0004");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0003");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0003> ACCESS=<Data->P0x0003>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0003);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0003");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "P0x0002");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<P0x0002> ACCESS=<Data->P0x0002>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->P0x0002);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "P0x0002");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "MAX_CID");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<MAX_CID> ACCESS=<Data->MAX_CID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MAX_CID);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "MAX_CID");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfg", "Parameters");
	  /* NAME=<Parameters> ACCESS=<Data->Parameters>  MAXBITSIZE=<2016> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Parameters.value, Data->Parameters.usedBits);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfg", "Parameters");
	ED_Dump_Struct_End (OStream, "HeaderCompressionCfg");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsServCategory (TEDOStream* OStream, const c_epsServCategory* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsServCategory");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsServCategory_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "AutomaticallyInitiatedECall");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<AutomaticallyInitiatedECall> ACCESS=<Data->AutomaticallyInitiatedECall>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->AutomaticallyInitiatedECall);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "AutomaticallyInitiatedECall");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "ManuallyInitiatedECall");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ManuallyInitiatedECall> ACCESS=<Data->ManuallyInitiatedECall>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ManuallyInitiatedECall);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "ManuallyInitiatedECall");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "MountainRescue");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MountainRescue> ACCESS=<Data->MountainRescue>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MountainRescue);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "MountainRescue");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "MarineGuard");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MarineGuard> ACCESS=<Data->MarineGuard>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MarineGuard);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "MarineGuard");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "FireBrigade");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FireBrigade> ACCESS=<Data->FireBrigade>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->FireBrigade);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "FireBrigade");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "Ambulance");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Ambulance> ACCESS=<Data->Ambulance>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Ambulance);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "Ambulance");
	ED_Dump_Struct_Begin_Field (OStream, "epsServCategory", "Police");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Police> ACCESS=<Data->Police>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Police);
	ED_Dump_Struct_End_Field (OStream, "epsServCategory", "Police");
	ED_Dump_Struct_End (OStream, "epsServCategory");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsLlcServAccessPointId (TEDOStream* OStream, const c_epsLlcServAccessPointId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsLlcServAccessPointId");
	ED_Dump_Struct_Begin_Field (OStream, "epsLlcServAccessPointId", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsLlcServAccessPointId_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsLlcServAccessPointId", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsLlcServAccessPointId", "LLCSAPIValue");
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
	ED_Dump_Struct_End_Field (OStream, "epsLlcServAccessPointId", "LLCSAPIValue");
	ED_Dump_Struct_End (OStream, "epsLlcServAccessPointId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsPacketFlowIdentifie (TEDOStream* OStream, const c_epsPacketFlowIdentifie* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsPacketFlowIdentifie");
	ED_Dump_Struct_Begin_Field (OStream, "epsPacketFlowIdentifie", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsPacketFlowIdentifie_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsPacketFlowIdentifie", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsPacketFlowIdentifie", "PacketFlowIdentifierValue");
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
	ED_Dump_Struct_End_Field (OStream, "epsPacketFlowIdentifie", "PacketFlowIdentifierValue");
	ED_Dump_Struct_End (OStream, "epsPacketFlowIdentifie");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsConnectivityType (TEDOStream* OStream, const c_epsConnectivityType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsConnectivityType");
	ED_Dump_Struct_Begin_Field (OStream, "epsConnectivityType", "connType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<connType> ACCESS=<Data->connType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->connType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "The PDN connection is considered a LIPA PDN connection"); break;
				default: OStream->WriteString (OStream, "The PDN connection type is not indicated");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsConnectivityType", "connType");
	ED_Dump_Struct_End (OStream, "epsConnectivityType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsWLANOffloadAcceptability (TEDOStream* OStream, const c_epsWLANOffloadAcceptability* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsWLANOffloadAcceptability");
	ED_Dump_Struct_Begin_Field (OStream, "epsWLANOffloadAcceptability", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsWLANOffloadAcceptability_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsWLANOffloadAcceptability", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsWLANOffloadAcceptability", "UTRAN_Offload_Acceptability_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRAN_Offload_Acceptability_Value> ACCESS=<Data->UTRAN_Offload_Acceptability_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->UTRAN_Offload_Acceptability_Value)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is not acceptable"); break;
				case 1: OStream->WriteString (OStream, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is acceptable"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsWLANOffloadAcceptability", "UTRAN_Offload_Acceptability_Value");
	ED_Dump_Struct_Begin_Field (OStream, "epsWLANOffloadAcceptability", "EUTRAN_Offload_Acceptability_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EUTRAN_Offload_Acceptability_Value> ACCESS=<Data->EUTRAN_Offload_Acceptability_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->EUTRAN_Offload_Acceptability_Value)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is not acceptable"); break;
				case 1: OStream->WriteString (OStream, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is acceptable"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsWLANOffloadAcceptability", "EUTRAN_Offload_Acceptability_Value");
	ED_Dump_Struct_End (OStream, "epsWLANOffloadAcceptability");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsDeviceProperties (TEDOStream* OStream, const c_epsDeviceProperties* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsDeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "epsDeviceProperties", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsDeviceProperties", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsDeviceProperties", "lowPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<lowPriority> ACCESS=<Data->lowPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->lowPriority);
	ED_Dump_Struct_End_Field (OStream, "epsDeviceProperties", "lowPriority");
	ED_Dump_Struct_End (OStream, "epsDeviceProperties");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsProtocolCfgOpt (TEDOStream* OStream, const c_epsProtocolCfgOpt* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "epsProtocolCfgOpt", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsProtocolCfgOpt", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsProtocolCfgOpt", "ConfigurationProtocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ConfigurationProtocol> ACCESS=<Data->ConfigurationProtocol>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ConfigurationProtocol);
	ED_Dump_Struct_End_Field (OStream, "epsProtocolCfgOpt", "ConfigurationProtocol");
	ED_Dump_Struct_Begin_Field (OStream, "epsProtocolCfgOpt", "ProtocolCfgs");
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgList> NAME=<ProtocolCfgs> ACCESS=<Data->ProtocolCfgs>  OPTIONAL=<0> FUNC=<Dump_c_epsProtocolCfgList> */
	  Dump_c_epsProtocolCfgList (OStream, &(Data->ProtocolCfgs));
	ED_Dump_Struct_End_Field (OStream, "epsProtocolCfgOpt", "ProtocolCfgs");
	ED_Dump_Struct_End (OStream, "epsProtocolCfgOpt");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentityList_Type2 (TEDOStream* OStream, const c_PartialTrackingAreaIdentityList_Type2* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<8> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_PartialTrackingAreaIdentity_Type2> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentity_Type2> */
	  Dump_c_PartialTrackingAreaIdentity_Type2 (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_APNAggregateMaxBitRate (TEDOStream* OStream, const c_APNAggregateMaxBitRate* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "APNAggregateMaxBitRate");
	ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate", "APN_AMBRDownlink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRDownlink> ACCESS=<Data->APN_AMBRDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->APN_AMBRDownlink);
	ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate", "APN_AMBRDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate", "APN_AMBRUplink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRUplink> ACCESS=<Data->APN_AMBRUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->APN_AMBRUplink);
	ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate", "APN_AMBRUplink");
	ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate", "ext");
	if (!Data->ext_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "APNAggregateMaxBitRate_ext");
		ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate_ext", "APN_AMBRDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRDownlinkExt> ACCESS=<Data->ext->APN_AMBRDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext->APN_AMBRDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate_ext", "APN_AMBRDownlinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate_ext", "APN_AMBRUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRUplinkExt> ACCESS=<Data->ext->APN_AMBRUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext->APN_AMBRUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate_ext", "APN_AMBRUplinkExt");
		ED_Dump_Struct_End (OStream, "APNAggregateMaxBitRate_ext");
	}
	ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate", "ext2");
	if (!Data->ext2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "APNAggregateMaxBitRate_ext2");
		ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate_ext2", "APN_AMBRDownlinkExt2");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRDownlinkExt2> ACCESS=<Data->ext2->APN_AMBRDownlinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2->APN_AMBRDownlinkExt2);
		ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate_ext2", "APN_AMBRDownlinkExt2");
		ED_Dump_Struct_Begin_Field (OStream, "APNAggregateMaxBitRate_ext2", "APN_AMBRUplinkExt2");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<APN_AMBRUplinkExt2> ACCESS=<Data->ext2->APN_AMBRUplinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2->APN_AMBRUplinkExt2);
		ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate_ext2", "APN_AMBRUplinkExt2");
		ED_Dump_Struct_End (OStream, "APNAggregateMaxBitRate_ext2");
	}
	ED_Dump_Struct_End_Field (OStream, "APNAggregateMaxBitRate", "ext2");
	ED_Dump_Struct_End (OStream, "APNAggregateMaxBitRate");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_QOS (TEDOStream* OStream, const c_EPS_QOS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_QOS");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS", "QCI");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<QCI> ACCESS=<Data->QCI>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->QCI);
	ED_Dump_Struct_End_Field (OStream, "EPS_QOS", "QCI");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS", "basic");
	if (!Data->basic_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EPS_QOS_basic");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_basic", "MaximumBitRateForUplink");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplink> ACCESS=<Data->basic->MaximumBitRateForUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->basic->MaximumBitRateForUplink);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_basic", "MaximumBitRateForUplink");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_basic", "MaximumBitRateForDownlink");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlink> ACCESS=<Data->basic->MaximumBitRateForDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->basic->MaximumBitRateForDownlink);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_basic", "MaximumBitRateForDownlink");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_basic", "GuaranteedBitRateForUplink");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplink> ACCESS=<Data->basic->GuaranteedBitRateForUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->basic->GuaranteedBitRateForUplink);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_basic", "GuaranteedBitRateForUplink");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_basic", "GuaranteedBitRateForDownlink");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlink> ACCESS=<Data->basic->GuaranteedBitRateForDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->basic->GuaranteedBitRateForDownlink);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_basic", "GuaranteedBitRateForDownlink");
		ED_Dump_Struct_End (OStream, "EPS_QOS_basic");
	}
	ED_Dump_Struct_End_Field (OStream, "EPS_QOS", "basic");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS", "extended");
	if (!Data->extended_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EPS_QOS_extended");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended", "MaximumBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt> ACCESS=<Data->extended->MaximumBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended->MaximumBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended", "MaximumBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended", "MaximumBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt> ACCESS=<Data->extended->MaximumBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended->MaximumBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended", "MaximumBitRateForDownlinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended", "GuaranteedBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt> ACCESS=<Data->extended->GuaranteedBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended->GuaranteedBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended", "GuaranteedBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended", "GuaranteedBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt> ACCESS=<Data->extended->GuaranteedBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended->GuaranteedBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended", "GuaranteedBitRateForDownlinkExt");
		ED_Dump_Struct_End (OStream, "EPS_QOS_extended");
	}
	ED_Dump_Struct_End_Field (OStream, "EPS_QOS", "extended");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS", "extended2");
	if (!Data->extended2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EPS_QOS_extended2");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended2", "MaximumBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt> ACCESS=<Data->extended2->MaximumBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended2->MaximumBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended2", "MaximumBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended2", "MaximumBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt> ACCESS=<Data->extended2->MaximumBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended2->MaximumBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended2", "MaximumBitRateForDownlinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended2", "GuaranteedBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt> ACCESS=<Data->extended2->GuaranteedBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended2->GuaranteedBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended2", "GuaranteedBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "EPS_QOS_extended2", "GuaranteedBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt> ACCESS=<Data->extended2->GuaranteedBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->extended2->GuaranteedBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "EPS_QOS_extended2", "GuaranteedBitRateForDownlinkExt");
		ED_Dump_Struct_End (OStream, "EPS_QOS_extended2");
	}
	ED_Dump_Struct_End_Field (OStream, "EPS_QOS", "extended2");
	ED_Dump_Struct_End (OStream, "EPS_QOS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsQualityOfServ (TEDOStream* OStream, const c_epsQualityOfServ* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsQualityOfServ");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "DelayClass");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "DelayClass");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "ReliabilityClass");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "ReliabilityClass");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "PeakThroughput");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "PeakThroughput");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "PrecedenceClass");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "PrecedenceClass");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "MeanThroughput");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "MeanThroughput");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "TrafficClass");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "TrafficClass");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "DeliveryOrder");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "DeliveryOrder");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "DeliveryOfErroneusSDU");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "DeliveryOfErroneusSDU");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "MaximumSDUSize");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "MaximumSDUSize");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "MaximumBitRateForUplink");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "MaximumBitRateForUplink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "MaximumBitRateForDownlink");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "MaximumBitRateForDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "ResidualBER");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "ResidualBER");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "SDUErrorRatio");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "SDUErrorRatio");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "TransderDelay");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TransderDelay> ACCESS=<Data->TransderDelay>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TransderDelay);
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "TransderDelay");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "TrafficHandlingPriority");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "TrafficHandlingPriority");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "GuaranteedBitRateForUplink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplink> ACCESS=<Data->GuaranteedBitRateForUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GuaranteedBitRateForUplink);
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "GuaranteedBitRateForUplink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "GuaranteedBitRateForDownlink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlink> ACCESS=<Data->GuaranteedBitRateForDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GuaranteedBitRateForDownlink);
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "GuaranteedBitRateForDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "SignalingIndication");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "SignalingIndication");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "SourceStatisticsDescriptor");
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
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "SourceStatisticsDescriptor");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "downlink");
	if (!Data->downlink_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "epsQualityOfServ_downlink");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_downlink", "MaximumBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt> ACCESS=<Data->downlink->MaximumBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->downlink->MaximumBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_downlink", "MaximumBitRateForDownlinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_downlink", "GuaranteedBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt> ACCESS=<Data->downlink->GuaranteedBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->downlink->GuaranteedBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_downlink", "GuaranteedBitRateForDownlinkExt");
		ED_Dump_Struct_End (OStream, "epsQualityOfServ_downlink");
	}
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "downlink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "uplink");
	if (!Data->uplink_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "epsQualityOfServ_uplink");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_uplink", "MaximumBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt> ACCESS=<Data->uplink->MaximumBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->uplink->MaximumBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_uplink", "MaximumBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_uplink", "GuaranteedBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt> ACCESS=<Data->uplink->GuaranteedBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->uplink->GuaranteedBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_uplink", "GuaranteedBitRateForUplinkExt");
		ED_Dump_Struct_End (OStream, "epsQualityOfServ_uplink");
	}
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "uplink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "ext2downlink");
	if (!Data->ext2downlink_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "epsQualityOfServ_ext2downlink");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_ext2downlink", "MaximumBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt> ACCESS=<Data->ext2downlink->MaximumBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2downlink->MaximumBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_ext2downlink", "MaximumBitRateForDownlinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_ext2downlink", "GuaranteedBitRateForDownlinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt> ACCESS=<Data->ext2downlink->GuaranteedBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2downlink->GuaranteedBitRateForDownlinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_ext2downlink", "GuaranteedBitRateForDownlinkExt");
		ED_Dump_Struct_End (OStream, "epsQualityOfServ_ext2downlink");
	}
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "ext2downlink");
	ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ", "ext2uplink");
	if (!Data->ext2uplink_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "epsQualityOfServ_ext2uplink");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_ext2uplink", "MaximumBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt> ACCESS=<Data->ext2uplink->MaximumBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2uplink->MaximumBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_ext2uplink", "MaximumBitRateForUplinkExt");
		ED_Dump_Struct_Begin_Field (OStream, "epsQualityOfServ_ext2uplink", "GuaranteedBitRateForUplinkExt");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt> ACCESS=<Data->ext2uplink->GuaranteedBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->ext2uplink->GuaranteedBitRateForUplinkExt);
		ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ_ext2uplink", "GuaranteedBitRateForUplinkExt");
		ED_Dump_Struct_End (OStream, "epsQualityOfServ_ext2uplink");
	}
	ED_Dump_Struct_End_Field (OStream, "epsQualityOfServ", "ext2uplink");
	ED_Dump_Struct_End (OStream, "epsQualityOfServ");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RemoteUEContext (TEDOStream* OStream, const c_RemoteUEContext* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RemoteUEContext");
	ED_Dump_Struct_Begin_Field (OStream, "RemoteUEContext", "Contexts");
		/* SEQUENCE NAME=<Contexts> ACCESS=<Data->Contexts>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Contexts", Data->Contexts.items);
		for (i0=0; i0<Data->Contexts.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Contexts", i0, Data->Contexts.items);
		  /* STRUCTURAL=<1> TYPE=<c_RemoteUEContext_SingleContext> NAME=<data> ACCESS=<*(Data->Contexts.data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_RemoteUEContext_SingleContext> */
		  Dump_c_RemoteUEContext_SingleContext (OStream, &(*(Data->Contexts.data [i0])));
			ED_Dump_Sequence_End_Field (OStream, "Contexts", i0, Data->Contexts.items);
		}
		ED_Dump_Sequence_End (OStream, "Contexts", Data->Contexts.items);
	ED_Dump_Struct_End_Field (OStream, "RemoteUEContext", "Contexts");
	ED_Dump_Struct_End (OStream, "RemoteUEContext");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsLinkedTi (TEDOStream* OStream, const c_epsLinkedTi* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsLinkedTi");
	ED_Dump_Struct_Begin_Field (OStream, "epsLinkedTi", "TIValue");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TIValue> ACCESS=<Data->TIValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TIValue);
	ED_Dump_Struct_End_Field (OStream, "epsLinkedTi", "TIValue");
	ED_Dump_Struct_Begin_Field (OStream, "epsLinkedTi", "TIFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TIFlag> ACCESS=<Data->TIFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TIFlag);
	ED_Dump_Struct_End_Field (OStream, "epsLinkedTi", "TIFlag");
	ED_Dump_Struct_End (OStream, "epsLinkedTi");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsTrafficFlowTemplate (TEDOStream* OStream, const c_epsTrafficFlowTemplate* Data)
{
	int i0, i1;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsTrafficFlowTemplate");
	ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate", "TFTOperationCode");
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
	ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate", "TFTOperationCode");
	ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate", "PacketFilters");
		/* SEQUENCE NAME=<PacketFilters> ACCESS=<Data->PacketFilters>  ITEMS=<8> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "PacketFilters", Data->PacketFilters.items);
		for (i0=0; i0<Data->PacketFilters.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "PacketFilters", i0, Data->PacketFilters.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "epsTrafficFlowTemplate_PacketFilters_data");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterId");
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PacketFilterId> ACCESS=<Data->PacketFilters.data [i0]->PacketFilterId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->PacketFilters.data [i0]->PacketFilterId);
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterId");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterDirection");
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
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterDirection");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterEvalPrecedence");
			  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<PacketFilterEvalPrecedence> ACCESS=<Data->PacketFilters.data [i0]->PacketFilterEvalPrecedence>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
			  ED_Dump_Integer (OStream, Data->PacketFilters.data [i0]->PacketFilterEvalPrecedence);
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "PacketFilterEvalPrecedence");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "FilterContents");
				/* SEQUENCE NAME=<FilterContents> ACCESS=<Data->PacketFilters.data [i0]->FilterContents>  ITEMS=<7> OPTIONAL=<0> */
				ED_Dump_Sequence_Begin (OStream, "FilterContents", Data->PacketFilters.data [i0]->FilterContents.items);
				for (i1=0; i1<Data->PacketFilters.data [i0]->FilterContents.items; i1++) {
					ED_Dump_Sequence_Begin_Field (OStream, "FilterContents", i1, Data->PacketFilters.data [i0]->FilterContents.items);
				  /* STRUCT */
					ED_Dump_Struct_Begin (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data");
					ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentTypeId");
					  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ComponentTypeId> ACCESS=<Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentTypeId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentTypeId)
						{
							switch (DATA) {
								case 16: OStream->WriteString (OStream, "IPv4 remote address type"); break;
								case 32: OStream->WriteString (OStream, "IPv6 remote address type"); break;
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
					ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentTypeId");
					ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentData");
					  /* NAME=<ComponentData> ACCESS=<Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData>  MAXBITSIZE=<256> OPTIONAL=<0> */
					  ED_Dump_Binary (OStream, Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData.value, Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData.usedBits);
					ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentData");
					ED_Dump_Struct_End (OStream, "epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data");
					ED_Dump_Sequence_End_Field (OStream, "FilterContents", i1, Data->PacketFilters.data [i0]->FilterContents.items);
				}
				ED_Dump_Sequence_End (OStream, "FilterContents", Data->PacketFilters.data [i0]->FilterContents.items);
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketFilters_data", "FilterContents");
			ED_Dump_Struct_End (OStream, "epsTrafficFlowTemplate_PacketFilters_data");
			ED_Dump_Sequence_End_Field (OStream, "PacketFilters", i0, Data->PacketFilters.items);
		}
		ED_Dump_Sequence_End (OStream, "PacketFilters", Data->PacketFilters.items);
	ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate", "PacketFilters");
	ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate", "PacketParameters");
		/* SEQUENCE NAME=<PacketParameters> ACCESS=<Data->PacketParameters>  ITEMS=<16> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "PacketParameters", Data->PacketParameters.items);
		for (i0=0; i0<Data->PacketParameters.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "PacketParameters", i0, Data->PacketParameters.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "epsTrafficFlowTemplate_PacketParameters_data");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketParameters_data", "ParameterId");
			  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<ParameterId> ACCESS=<Data->PacketParameters.data [i0]->ParameterId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
			  ED_Dump_Integer (OStream, Data->PacketParameters.data [i0]->ParameterId);
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketParameters_data", "ParameterId");
			ED_Dump_Struct_Begin_Field (OStream, "epsTrafficFlowTemplate_PacketParameters_data", "Contents");
			  /* NAME=<Contents> ACCESS=<Data->PacketParameters.data [i0]->Contents>  MAXBITSIZE=<256> OPTIONAL=<0> */
			  ED_Dump_Binary (OStream, Data->PacketParameters.data [i0]->Contents.value, Data->PacketParameters.data [i0]->Contents.usedBits);
			ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate_PacketParameters_data", "Contents");
			ED_Dump_Struct_End (OStream, "epsTrafficFlowTemplate_PacketParameters_data");
			ED_Dump_Sequence_End_Field (OStream, "PacketParameters", i0, Data->PacketParameters.items);
		}
		ED_Dump_Sequence_End (OStream, "PacketParameters", Data->PacketParameters.items);
	ED_Dump_Struct_End_Field (OStream, "epsTrafficFlowTemplate", "PacketParameters");
	ED_Dump_Struct_End (OStream, "epsTrafficFlowTemplate");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsGprsTimer (TEDOStream* OStream, const c_epsGprsTimer* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsGprsTimer");
	ED_Dump_Struct_Begin_Field (OStream, "epsGprsTimer", "Unit");
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
	ED_Dump_Struct_End_Field (OStream, "epsGprsTimer", "Unit");
	ED_Dump_Struct_Begin_Field (OStream, "epsGprsTimer", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "epsGprsTimer", "TimerValue");
	ED_Dump_Struct_End (OStream, "epsGprsTimer");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (TEDOStream* OStream, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (TEDOStream* OStream, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (TEDOStream* OStream, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (TEDOStream* OStream, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BEARER_RESOURCE_ALLOCATION_REQUEST (TEDOStream* OStream, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "LinkedEPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LinkedEPSBearerIdentity> ACCESS=<Data->LinkedEPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LinkedEPSBearerIdentity)
		{
			switch (DATA) {
				case 5: OStream->WriteString (OStream, "EPS bearer identity value 5"); break;
				case 6: OStream->WriteString (OStream, "EPS bearer identity value 6"); break;
				case 7: OStream->WriteString (OStream, "EPS bearer identity value 7"); break;
				case 8: OStream->WriteString (OStream, "EPS bearer identity value 8"); break;
				case 9: OStream->WriteString (OStream, "EPS bearer identity value 9"); break;
				case 10: OStream->WriteString (OStream, "EPS bearer identity value 10"); break;
				case 11: OStream->WriteString (OStream, "EPS bearer identity value 11"); break;
				case 12: OStream->WriteString (OStream, "EPS bearer identity value 12"); break;
				case 13: OStream->WriteString (OStream, "EPS bearer identity value 13"); break;
				case 14: OStream->WriteString (OStream, "EPS bearer identity value 14"); break;
				case 15: OStream->WriteString (OStream, "EPS bearer identity value 15"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "LinkedEPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_ALLOCATION_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "TrafficFlowAggregate");
	  /* STRUCTURAL=<0> TYPE=<c_epsTrafficFlowTemplate> NAME=<TrafficFlowAggregate> ACCESS=<Data->TrafficFlowAggregate>  OPTIONAL=<0> FUNC=<Dump_c_epsTrafficFlowTemplate> */
	  Dump_c_epsTrafficFlowTemplate (OStream, &(Data->TrafficFlowAggregate));
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "TrafficFlowAggregate");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "RequiredTrafficFlowQoS");
	  /* STRUCTURAL=<0> TYPE=<c_EPS_QOS> NAME=<RequiredTrafficFlowQoS> ACCESS=<Data->RequiredTrafficFlowQoS>  OPTIONAL=<0> FUNC=<Dump_c_EPS_QOS> */
	  Dump_c_EPS_QOS (OStream, &(Data->RequiredTrafficFlowQoS));
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "RequiredTrafficFlowQoS");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "BEARER_RESOURCE_ALLOCATION_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BEARER_RESOURCE_MODIFICATION_REQUEST (TEDOStream* OStream, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "LinkedEPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LinkedEPSBearerIdentity> ACCESS=<Data->LinkedEPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LinkedEPSBearerIdentity)
		{
			switch (DATA) {
				case 5: OStream->WriteString (OStream, "EPS bearer identity value 5"); break;
				case 6: OStream->WriteString (OStream, "EPS bearer identity value 6"); break;
				case 7: OStream->WriteString (OStream, "EPS bearer identity value 7"); break;
				case 8: OStream->WriteString (OStream, "EPS bearer identity value 8"); break;
				case 9: OStream->WriteString (OStream, "EPS bearer identity value 9"); break;
				case 10: OStream->WriteString (OStream, "EPS bearer identity value 10"); break;
				case 11: OStream->WriteString (OStream, "EPS bearer identity value 11"); break;
				case 12: OStream->WriteString (OStream, "EPS bearer identity value 12"); break;
				case 13: OStream->WriteString (OStream, "EPS bearer identity value 13"); break;
				case 14: OStream->WriteString (OStream, "EPS bearer identity value 14"); break;
				case 15: OStream->WriteString (OStream, "EPS bearer identity value 15"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "LinkedEPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_MODIFICATION_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "TrafficFlowAggregate");
	  /* STRUCTURAL=<0> TYPE=<c_epsTrafficFlowTemplate> NAME=<TrafficFlowAggregate> ACCESS=<Data->TrafficFlowAggregate>  OPTIONAL=<0> FUNC=<Dump_c_epsTrafficFlowTemplate> */
	  Dump_c_epsTrafficFlowTemplate (OStream, &(Data->TrafficFlowAggregate));
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "TrafficFlowAggregate");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "RequiredTrafficFlowQoS");
	if (!Data->RequiredTrafficFlowQoS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPS_QOS> NAME=<RequiredTrafficFlowQoS> ACCESS=<*(Data->RequiredTrafficFlowQoS)>  OPTIONAL=<1> FUNC=<Dump_c_EPS_QOS> */
	  Dump_c_EPS_QOS (OStream, &(*(Data->RequiredTrafficFlowQoS)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "RequiredTrafficFlowQoS");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ESMCause");
	if (!Data->ESMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "HeaderCompressionCfg");
	if (!Data->HeaderCompressionCfg_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfg> NAME=<HeaderCompressionCfg> ACCESS=<*(Data->HeaderCompressionCfg)>  OPTIONAL=<1> FUNC=<Dump_c_HeaderCompressionCfg> */
	  Dump_c_HeaderCompressionCfg (OStream, &(*(Data->HeaderCompressionCfg)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "HeaderCompressionCfg");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "BEARER_RESOURCE_MODIFICATION_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (TEDOStream* OStream, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESM_DUMMY_MESSAGE (TEDOStream* OStream, const c_ESM_DUMMY_MESSAGE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ESM_DUMMY_MESSAGE");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DUMMY_MESSAGE", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_DUMMY_MESSAGE", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DUMMY_MESSAGE", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_DUMMY_MESSAGE", "ProcedureTransactionIdentity");
	ED_Dump_Struct_End (OStream, "ESM_DUMMY_MESSAGE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESM_INFORMATION_RESPONSE (TEDOStream* OStream, const c_ESM_INFORMATION_RESPONSE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ESM_INFORMATION_RESPONSE");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_RESPONSE", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_RESPONSE", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_RESPONSE", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_RESPONSE", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_RESPONSE", "AccessPointName");
	if (!Data->AccessPointName_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AccessPointName> ACCESS=<*(Data->AccessPointName)>  MAXBITSIZE=<800> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AccessPointName->value, Data->AccessPointName->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_RESPONSE", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_RESPONSE", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_RESPONSE", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_RESPONSE", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_RESPONSE", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ESM_INFORMATION_RESPONSE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESM_STATUS (TEDOStream* OStream, const c_ESM_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ESM_STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_STATUS", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_STATUS", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_STATUS", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_STATUS", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_STATUS", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ESM_STATUS", "ESMCause");
	ED_Dump_Struct_End (OStream, "ESM_STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (TEDOStream* OStream, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "MODIFY_EPS_BEARER_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (TEDOStream* OStream, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "MODIFY_EPS_BEARER_CONTEXT_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PDN_CONNECTIVITY_REQUEST (TEDOStream* OStream, const c_PDN_CONNECTIVITY_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PDN_CONNECTIVITY_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "RequestType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RequestType> ACCESS=<Data->RequestType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RequestType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "initial attach"); break;
				case 2: OStream->WriteString (OStream, "Handover"); break;
				default: OStream->WriteString (OStream, "initial attach");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "RequestType");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "PDNType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PDNType> ACCESS=<Data->PDNType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PDNType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "IPv4"); break;
				case 2: OStream->WriteString (OStream, "IPv6"); break;
				case 3: OStream->WriteString (OStream, "IPv4v6"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "PDNType");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ESMInformationTransferFlag");
	if (!Data->ESMInformationTransferFlag_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMInformationTransferFlag> ACCESS=<Data->ESMInformationTransferFlag>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMInformationTransferFlag)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "ESM information transfer not required"); break;
				case 1: OStream->WriteString (OStream, "ESM information transfer required"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ESMInformationTransferFlag");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "AccessPointName");
	if (!Data->AccessPointName_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AccessPointName> ACCESS=<*(Data->AccessPointName)>  MAXBITSIZE=<800> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AccessPointName->value, Data->AccessPointName->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "HeaderCompressionCfg");
	if (!Data->HeaderCompressionCfg_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfg> NAME=<HeaderCompressionCfg> ACCESS=<*(Data->HeaderCompressionCfg)>  OPTIONAL=<1> FUNC=<Dump_c_HeaderCompressionCfg> */
	  Dump_c_HeaderCompressionCfg (OStream, &(*(Data->HeaderCompressionCfg)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "HeaderCompressionCfg");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "PDN_CONNECTIVITY_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PDN_DISCONNECT_REQUEST (TEDOStream* OStream, const c_PDN_DISCONNECT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PDN_DISCONNECT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "LinkedEPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LinkedEPSBearerIdentity> ACCESS=<Data->LinkedEPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LinkedEPSBearerIdentity)
		{
			switch (DATA) {
				case 5: OStream->WriteString (OStream, "EPS bearer identity value 5"); break;
				case 6: OStream->WriteString (OStream, "EPS bearer identity value 6"); break;
				case 7: OStream->WriteString (OStream, "EPS bearer identity value 7"); break;
				case 8: OStream->WriteString (OStream, "EPS bearer identity value 8"); break;
				case 9: OStream->WriteString (OStream, "EPS bearer identity value 9"); break;
				case 10: OStream->WriteString (OStream, "EPS bearer identity value 10"); break;
				case 11: OStream->WriteString (OStream, "EPS bearer identity value 11"); break;
				case 12: OStream->WriteString (OStream, "EPS bearer identity value 12"); break;
				case 13: OStream->WriteString (OStream, "EPS bearer identity value 13"); break;
				case 14: OStream->WriteString (OStream, "EPS bearer identity value 14"); break;
				case 15: OStream->WriteString (OStream, "EPS bearer identity value 15"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "LinkedEPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_PDN_DISCONNECT_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "PDN_DISCONNECT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REMOTE_UE_REPORT (TEDOStream* OStream, const c_REMOTE_UE_REPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REMOTE_UE_REPORT");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT", "RemoteUEContextConnected");
	if (!Data->RemoteUEContextConnected_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RemoteUEContext> NAME=<RemoteUEContextConnected> ACCESS=<*(Data->RemoteUEContextConnected)>  OPTIONAL=<1> FUNC=<Dump_c_RemoteUEContext> */
	  Dump_c_RemoteUEContext (OStream, &(*(Data->RemoteUEContextConnected)));
	}
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT", "RemoteUEContextConnected");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT", "RemoteUEContextDisconnected");
	if (!Data->RemoteUEContextDisconnected_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RemoteUEContext> NAME=<RemoteUEContextDisconnected> ACCESS=<*(Data->RemoteUEContextDisconnected)>  OPTIONAL=<1> FUNC=<Dump_c_RemoteUEContext> */
	  Dump_c_RemoteUEContext (OStream, &(*(Data->RemoteUEContextDisconnected)));
	}
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT", "RemoteUEContextDisconnected");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT", "ProSeKeyManagementFunctionAddr");
	if (!Data->ProSeKeyManagementFunctionAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PKMFAddress> NAME=<ProSeKeyManagementFunctionAddr> ACCESS=<*(Data->ProSeKeyManagementFunctionAddr)>  OPTIONAL=<1> FUNC=<Dump_c_PKMFAddress> */
	  Dump_c_PKMFAddress (OStream, &(*(Data->ProSeKeyManagementFunctionAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT", "ProSeKeyManagementFunctionAddr");
	ED_Dump_Struct_End (OStream, "REMOTE_UE_REPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESM_DATA_TRANSPORT (TEDOStream* OStream, const c_ESM_DATA_TRANSPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ESM_DATA_TRANSPORT");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DATA_TRANSPORT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_DATA_TRANSPORT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DATA_TRANSPORT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_DATA_TRANSPORT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DATA_TRANSPORT", "UserDataContainer");
	  /* NAME=<UserDataContainer> ACCESS=<Data->UserDataContainer>  MAXBITSIZE=<4784> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->UserDataContainer.value, Data->UserDataContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "ESM_DATA_TRANSPORT", "UserDataContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_DATA_TRANSPORT", "ReleaseAssistanceIndication");
	if (!Data->ReleaseAssistanceIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ReleaseAssistanceIndication> ACCESS=<Data->ReleaseAssistanceIndication>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ReleaseAssistanceIndication)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No information available"); break;
				case 1: OStream->WriteString (OStream, "Downlink data transmission subsequent to the uplink data transmission is not expected"); break;
				case 2: OStream->WriteString (OStream, "Downlink data transmission subsequent to the uplink data transmission is expected"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "ESM_DATA_TRANSPORT", "ReleaseAssistanceIndication");
	ED_Dump_Struct_End (OStream, "ESM_DATA_TRANSPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (TEDOStream* OStream, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "LinkedEPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LinkedEPSBearerIdentity> ACCESS=<Data->LinkedEPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LinkedEPSBearerIdentity)
		{
			switch (DATA) {
				case 5: OStream->WriteString (OStream, "EPS bearer identity value 5"); break;
				case 6: OStream->WriteString (OStream, "EPS bearer identity value 6"); break;
				case 7: OStream->WriteString (OStream, "EPS bearer identity value 7"); break;
				case 8: OStream->WriteString (OStream, "EPS bearer identity value 8"); break;
				case 9: OStream->WriteString (OStream, "EPS bearer identity value 9"); break;
				case 10: OStream->WriteString (OStream, "EPS bearer identity value 10"); break;
				case 11: OStream->WriteString (OStream, "EPS bearer identity value 11"); break;
				case 12: OStream->WriteString (OStream, "EPS bearer identity value 12"); break;
				case 13: OStream->WriteString (OStream, "EPS bearer identity value 13"); break;
				case 14: OStream->WriteString (OStream, "EPS bearer identity value 14"); break;
				case 15: OStream->WriteString (OStream, "EPS bearer identity value 15"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "LinkedEPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "EPSQoS");
	  /* STRUCTURAL=<0> TYPE=<c_EPS_QOS> NAME=<EPSQoS> ACCESS=<Data->EPSQoS>  OPTIONAL=<0> FUNC=<Dump_c_EPS_QOS> */
	  Dump_c_EPS_QOS (OStream, &(Data->EPSQoS));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "EPSQoS");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "TFT");
	  /* STRUCTURAL=<0> TYPE=<c_epsTrafficFlowTemplate> NAME=<TFT> ACCESS=<Data->TFT>  OPTIONAL=<0> FUNC=<Dump_c_epsTrafficFlowTemplate> */
	  Dump_c_epsTrafficFlowTemplate (OStream, &(Data->TFT));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "TFT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "TransactionIdentifier");
	if (!Data->TransactionIdentifier_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLinkedTi> NAME=<TransactionIdentifier> ACCESS=<*(Data->TransactionIdentifier)>  OPTIONAL=<1> FUNC=<Dump_c_epsLinkedTi> */
	  Dump_c_epsLinkedTi (OStream, &(*(Data->TransactionIdentifier)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "TransactionIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedQoS");
	if (!Data->NegotiatedQoS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsQualityOfServ> NAME=<NegotiatedQoS> ACCESS=<*(Data->NegotiatedQoS)>  OPTIONAL=<1> FUNC=<Dump_c_epsQualityOfServ> */
	  Dump_c_epsQualityOfServ (OStream, &(*(Data->NegotiatedQoS)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedQoS");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	if (!Data->NegotiatedLLCSAPI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLlcServAccessPointId> NAME=<NegotiatedLLCSAPI> ACCESS=<*(Data->NegotiatedLLCSAPI)>  OPTIONAL=<1> FUNC=<Dump_c_epsLlcServAccessPointId> */
	  Dump_c_epsLlcServAccessPointId (OStream, &(*(Data->NegotiatedLLCSAPI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	if (!Data->RadioPriority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	if (!Data->PacketFlowIdentifier_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsPacketFlowIdentifie> NAME=<PacketFlowIdentifier> ACCESS=<*(Data->PacketFlowIdentifier)>  OPTIONAL=<1> FUNC=<Dump_c_epsPacketFlowIdentifie> */
	  Dump_c_epsPacketFlowIdentifie (OStream, &(*(Data->PacketFlowIdentifier)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsWLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_epsWLANOffloadAcceptability> */
	  Dump_c_epsWLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (TEDOStream* OStream, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "EPSQoS");
	  /* STRUCTURAL=<0> TYPE=<c_EPS_QOS> NAME=<EPSQoS> ACCESS=<Data->EPSQoS>  OPTIONAL=<0> FUNC=<Dump_c_EPS_QOS> */
	  Dump_c_EPS_QOS (OStream, &(Data->EPSQoS));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "EPSQoS");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "AccessPointName");
	  /* NAME=<AccessPointName> ACCESS=<Data->AccessPointName>  MAXBITSIZE=<800> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AccessPointName.value, Data->AccessPointName.usedBits);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "PDNAddress");
	  /* STRUCTURAL=<0> TYPE=<c_PDNAddress> NAME=<PDNAddress> ACCESS=<Data->PDNAddress>  OPTIONAL=<0> FUNC=<Dump_c_PDNAddress> */
	  Dump_c_PDNAddress (OStream, &(Data->PDNAddress));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "PDNAddress");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "TransactionIdentifier");
	if (!Data->TransactionIdentifier_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLinkedTi> NAME=<TransactionIdentifier> ACCESS=<*(Data->TransactionIdentifier)>  OPTIONAL=<1> FUNC=<Dump_c_epsLinkedTi> */
	  Dump_c_epsLinkedTi (OStream, &(*(Data->TransactionIdentifier)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "TransactionIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedQoS");
	if (!Data->NegotiatedQoS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsQualityOfServ> NAME=<NegotiatedQoS> ACCESS=<*(Data->NegotiatedQoS)>  OPTIONAL=<1> FUNC=<Dump_c_epsQualityOfServ> */
	  Dump_c_epsQualityOfServ (OStream, &(*(Data->NegotiatedQoS)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedQoS");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	if (!Data->NegotiatedLLCSAPI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLlcServAccessPointId> NAME=<NegotiatedLLCSAPI> ACCESS=<*(Data->NegotiatedLLCSAPI)>  OPTIONAL=<1> FUNC=<Dump_c_epsLlcServAccessPointId> */
	  Dump_c_epsLlcServAccessPointId (OStream, &(*(Data->NegotiatedLLCSAPI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	if (!Data->RadioPriority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	if (!Data->PacketFlowIdentifier_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsPacketFlowIdentifie> NAME=<PacketFlowIdentifier> ACCESS=<*(Data->PacketFlowIdentifier)>  OPTIONAL=<1> FUNC=<Dump_c_epsPacketFlowIdentifie> */
	  Dump_c_epsPacketFlowIdentifie (OStream, &(*(Data->PacketFlowIdentifier)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "APNAMBR");
	if (!Data->APNAMBR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_APNAggregateMaxBitRate> NAME=<APNAMBR> ACCESS=<*(Data->APNAMBR)>  OPTIONAL=<1> FUNC=<Dump_c_APNAggregateMaxBitRate> */
	  Dump_c_APNAggregateMaxBitRate (OStream, &(*(Data->APNAMBR)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "APNAMBR");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ESMCause");
	if (!Data->ESMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ConnectivityType");
	if (!Data->ConnectivityType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsConnectivityType> NAME=<ConnectivityType> ACCESS=<*(Data->ConnectivityType)>  OPTIONAL=<1> FUNC=<Dump_c_epsConnectivityType> */
	  Dump_c_epsConnectivityType (OStream, &(*(Data->ConnectivityType)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ConnectivityType");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsWLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_epsWLANOffloadAcceptability> */
	  Dump_c_epsWLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "HeaderCompressionCfg");
	if (!Data->HeaderCompressionCfg_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfg> NAME=<HeaderCompressionCfg> ACCESS=<*(Data->HeaderCompressionCfg)>  OPTIONAL=<1> FUNC=<Dump_c_HeaderCompressionCfg> */
	  Dump_c_HeaderCompressionCfg (OStream, &(*(Data->HeaderCompressionCfg)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "HeaderCompressionCfg");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ControlPlaneOnlyIndication");
	if (!Data->ControlPlaneOnlyIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ControlPlaneOnlyIndication> ACCESS=<Data->ControlPlaneOnlyIndication>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->ControlPlaneOnlyIndication);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ControlPlaneOnlyIndication");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ServingPLMNRateControl");
	if (!Data->ServingPLMNRateControl_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<ServingPLMNRateControl> ACCESS=<Data->ServingPLMNRateControl>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ServingPLMNRateControl);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST", "ServingPLMNRateControl");
	ED_Dump_Struct_End (OStream, "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BEARER_RESOURCE_ALLOCATION_REJECT (TEDOStream* OStream, const c_BEARER_RESOURCE_ALLOCATION_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "BackOffTimer");
	if (!Data->BackOffTimer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<BackOffTimer> ACCESS=<*(Data->BackOffTimer)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->BackOffTimer)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "BackOffTimer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_epsReAttemptIndicator> */
	  Dump_c_epsReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "BEARER_RESOURCE_ALLOCATION_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BEARER_RESOURCE_MODIFICATION_REJECT (TEDOStream* OStream, const c_BEARER_RESOURCE_MODIFICATION_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "BackOffTimer");
	if (!Data->BackOffTimer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<BackOffTimer> ACCESS=<*(Data->BackOffTimer)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->BackOffTimer)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "BackOffTimer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_epsReAttemptIndicator> */
	  Dump_c_epsReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "BEARER_RESOURCE_MODIFICATION_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (TEDOStream* OStream, const c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "T3396Value");
	if (!Data->T3396Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3396Value> ACCESS=<*(Data->T3396Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3396Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "T3396Value");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsWLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_epsWLANOffloadAcceptability> */
	  Dump_c_epsWLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESM_INFORMATION_REQUEST (TEDOStream* OStream, const c_ESM_INFORMATION_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ESM_INFORMATION_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ESM_INFORMATION_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "ESM_INFORMATION_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_End (OStream, "ESM_INFORMATION_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (TEDOStream* OStream, const c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NewEPSQoS");
	if (!Data->NewEPSQoS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPS_QOS> NAME=<NewEPSQoS> ACCESS=<*(Data->NewEPSQoS)>  OPTIONAL=<1> FUNC=<Dump_c_EPS_QOS> */
	  Dump_c_EPS_QOS (OStream, &(*(Data->NewEPSQoS)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NewEPSQoS");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "TFT");
	if (!Data->TFT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsTrafficFlowTemplate> NAME=<TFT> ACCESS=<*(Data->TFT)>  OPTIONAL=<1> FUNC=<Dump_c_epsTrafficFlowTemplate> */
	  Dump_c_epsTrafficFlowTemplate (OStream, &(*(Data->TFT)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "TFT");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NewQoS");
	if (!Data->NewQoS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsQualityOfServ> NAME=<NewQoS> ACCESS=<*(Data->NewQoS)>  OPTIONAL=<1> FUNC=<Dump_c_epsQualityOfServ> */
	  Dump_c_epsQualityOfServ (OStream, &(*(Data->NewQoS)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NewQoS");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	if (!Data->NegotiatedLLCSAPI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLlcServAccessPointId> NAME=<NegotiatedLLCSAPI> ACCESS=<*(Data->NegotiatedLLCSAPI)>  OPTIONAL=<1> FUNC=<Dump_c_epsLlcServAccessPointId> */
	  Dump_c_epsLlcServAccessPointId (OStream, &(*(Data->NegotiatedLLCSAPI)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NegotiatedLLCSAPI");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	if (!Data->RadioPriority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	if (!Data->PacketFlowIdentifier_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsPacketFlowIdentifie> NAME=<PacketFlowIdentifier> ACCESS=<*(Data->PacketFlowIdentifier)>  OPTIONAL=<1> FUNC=<Dump_c_epsPacketFlowIdentifie> */
	  Dump_c_epsPacketFlowIdentifie (OStream, &(*(Data->PacketFlowIdentifier)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "PacketFlowIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "APNAMBR");
	if (!Data->APNAMBR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_APNAggregateMaxBitRate> NAME=<APNAMBR> ACCESS=<*(Data->APNAMBR)>  OPTIONAL=<1> FUNC=<Dump_c_APNAggregateMaxBitRate> */
	  Dump_c_APNAggregateMaxBitRate (OStream, &(*(Data->APNAMBR)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "APNAMBR");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsWLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_epsWLANOffloadAcceptability> */
	  Dump_c_epsWLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "HeaderCompressionCfg");
	if (!Data->HeaderCompressionCfg_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfg> NAME=<HeaderCompressionCfg> ACCESS=<*(Data->HeaderCompressionCfg)>  OPTIONAL=<1> FUNC=<Dump_c_HeaderCompressionCfg> */
	  Dump_c_HeaderCompressionCfg (OStream, &(*(Data->HeaderCompressionCfg)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "HeaderCompressionCfg");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "MODIFY_EPS_BEARER_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_NOTIFICATION (TEDOStream* OStream, const c_EPS_NOTIFICATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_NOTIFICATION");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_NOTIFICATION", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "EPS_NOTIFICATION", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_NOTIFICATION", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "EPS_NOTIFICATION", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_NOTIFICATION", "NotificationIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NotificationIndicator> ACCESS=<Data->NotificationIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NotificationIndicator)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "SRVCC handover cancelled, IMS session re-establishment required"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPS_NOTIFICATION", "NotificationIndicator");
	ED_Dump_Struct_End (OStream, "EPS_NOTIFICATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PDN_CONNECTIVITY_REJECT (TEDOStream* OStream, const c_PDN_CONNECTIVITY_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PDN_CONNECTIVITY_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "BackOffTimer");
	if (!Data->BackOffTimer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<BackOffTimer> ACCESS=<*(Data->BackOffTimer)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->BackOffTimer)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "BackOffTimer");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_epsReAttemptIndicator> */
	  Dump_c_epsReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_CONNECTIVITY_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "PDN_CONNECTIVITY_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PDN_DISCONNECT_REJECT (TEDOStream* OStream, const c_PDN_DISCONNECT_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PDN_DISCONNECT_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REJECT", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REJECT", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REJECT", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REJECT", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REJECT", "ESMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ESMCause> ACCESS=<Data->ESMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ESMCause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDN type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "PTI already in use"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "EPS QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown EPS bearer context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "EPS bearer context without TFT already activated"); break;
				case 49: OStream->WriteString (OStream, "Last PDN disconnection not allowed"); break;
				case 50: OStream->WriteString (OStream, "PDN type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDN type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 53: OStream->WriteString (OStream, "ESM information not received"); break;
				case 54: OStream->WriteString (OStream, "PDN connection does not exist"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of EPS bearers reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid PTI value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active EPS bearer context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REJECT", "ESMCause");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REJECT", "ProtocolConfigurationOptions");
	if (!Data->ProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ProtocolConfigurationOptions> ACCESS=<*(Data->ProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REJECT", "ProtocolConfigurationOptions");
	ED_Dump_Struct_Begin_Field (OStream, "PDN_DISCONNECT_REJECT", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsProtocolCfgOpt> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<*(Data->ExtendedProtocolConfigurationOptions)>  OPTIONAL=<1> FUNC=<Dump_c_epsProtocolCfgOpt> */
	  Dump_c_epsProtocolCfgOpt (OStream, &(*(Data->ExtendedProtocolConfigurationOptions)));
	}
	ED_Dump_Struct_End_Field (OStream, "PDN_DISCONNECT_REJECT", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "PDN_DISCONNECT_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REMOTE_UE_REPORT_RESPONSE (TEDOStream* OStream, const c_REMOTE_UE_REPORT_RESPONSE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REMOTE_UE_REPORT_RESPONSE");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "EPSBearerIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSBearerIdentity> ACCESS=<Data->EPSBearerIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->EPSBearerIdentity);
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "EPSBearerIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "ProcedureTransactionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProcedureTransactionIdentity> ACCESS=<Data->ProcedureTransactionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ProcedureTransactionIdentity);
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "ProcedureTransactionIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "UserDataContainer");
	  /* NAME=<UserDataContainer> ACCESS=<Data->UserDataContainer>  MAXBITSIZE=<4784> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->UserDataContainer.value, Data->UserDataContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "UserDataContainer");
	ED_Dump_Struct_Begin_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "ExtendedProtocolConfigurationOptions");
	if (!Data->ExtendedProtocolConfigurationOptions_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ExtendedProtocolConfigurationOptions> ACCESS=<Data->ExtendedProtocolConfigurationOptions>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ExtendedProtocolConfigurationOptions)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No information available"); break;
				case 1: OStream->WriteString (OStream, "Downlink data transmission subsequent to the uplink data transmission is not expected"); break;
				case 2: OStream->WriteString (OStream, "Downlink data transmission subsequent to the uplink data transmission is expected"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "REMOTE_UE_REPORT_RESPONSE", "ExtendedProtocolConfigurationOptions");
	ED_Dump_Struct_End (OStream, "REMOTE_UE_REPORT_RESPONSE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSMobileIdentity_GUTI (TEDOStream* OStream, const c_EPSMobileIdentity_GUTI* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSMobileIdentity_GUTI");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity_GUTI_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "OddEven");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity_GUTI_OddEven> NAME=<OddEven> ACCESS=<Data->OddEven>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "OddEven");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "IdentityType");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity_GUTI_IdentityType> NAME=<IdentityType> ACCESS=<Data->IdentityType>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "IdentityType");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MMEGroupID");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<MMEGroupID> ACCESS=<Data->MMEGroupID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MMEGroupID);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MMEGroupID");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "MMECode");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MMECode> ACCESS=<Data->MMECode>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MMECode);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "MMECode");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_GUTI", "M_TMSI");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<M_TMSI> ACCESS=<Data->M_TMSI>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->M_TMSI);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_GUTI", "M_TMSI");
	ED_Dump_Struct_End (OStream, "EPSMobileIdentity_GUTI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMobileId_TMGI (TEDOStream* OStream, const c_epsMobileId_TMGI* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsMobileId_TMGI");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId_TMGI_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MBMSSessIdIndic");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MBMSSessIdIndic");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MCCMNCIndic");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MCCMNCIndic");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "OddEven");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId_TMGI_OddEven> NAME=<OddEven> ACCESS=<Data->OddEven>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "OddEven");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "IdentityType");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "IdentityType");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MBMSServiceID");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MBMSServiceID> ACCESS=<Data->MBMSServiceID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MBMSServiceID);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MBMSServiceID");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_TMGI", "MBMSSessionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MBMSSessionIdentity> ACCESS=<Data->MBMSSessionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MBMSSessionIdentity);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_TMGI", "MBMSSessionIdentity");
	ED_Dump_Struct_End (OStream, "epsMobileId_TMGI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsPlmn (TEDOStream* OStream, const c_epsPlmn* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsPlmn");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsPlmn", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "epsPlmn", "MNC1");
	ED_Dump_Struct_End (OStream, "epsPlmn");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSMobileIdentity_IMSI (TEDOStream* OStream, const c_EPSMobileIdentity_IMSI* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSMobileIdentity_IMSI");
	ED_Dump_Struct_Begin_Field (OStream, "EPSMobileIdentity_IMSI", "IdentityDigit");
		/* SEQUENCE NAME=<IdentityDigit> ACCESS=<Data->IdentityDigit>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "IdentityDigit", Data->IdentityDigit.items);
		for (i0=0; i0<Data->IdentityDigit.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->IdentityDigit.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->IdentityDigit.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		}
		ED_Dump_Sequence_End (OStream, "IdentityDigit", Data->IdentityDigit.items);
	ED_Dump_Struct_End_Field (OStream, "EPSMobileIdentity_IMSI", "IdentityDigit");
	ED_Dump_Struct_End (OStream, "EPSMobileIdentity_IMSI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TrackingAreaIdentityList_Item (TEDOStream* OStream, const c_TrackingAreaIdentityList_Item* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_TrackingAreaIdentityList_Item_Type0: {
		ED_Dump_Union_Begin (OStream, "TrackingAreaIdentityList_Item", "Type0");
		  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_Type0> NAME=<Type0> ACCESS=<*(Data->u.Type0)>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentityList_Type0> */
		  Dump_c_PartialTrackingAreaIdentityList_Type0 (OStream, &(*(Data->u.Type0)));
	ED_Dump_Union_End (OStream, "TrackingAreaIdentityList_Item", "Type0");
			break;
		}
	case U_c_TrackingAreaIdentityList_Item_Type1: {
		ED_Dump_Union_Begin (OStream, "TrackingAreaIdentityList_Item", "Type1");
		  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_Type1> NAME=<Type1> ACCESS=<*(Data->u.Type1)>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentityList_Type1> */
		  Dump_c_PartialTrackingAreaIdentityList_Type1 (OStream, &(*(Data->u.Type1)));
	ED_Dump_Union_End (OStream, "TrackingAreaIdentityList_Item", "Type1");
			break;
		}
	case U_c_TrackingAreaIdentityList_Item_Type2: {
		ED_Dump_Union_Begin (OStream, "TrackingAreaIdentityList_Item", "Type2");
		  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList_Type2> NAME=<Type2> ACCESS=<*(Data->u.Type2)>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentityList_Type2> */
		  Dump_c_PartialTrackingAreaIdentityList_Type2 (OStream, &(*(Data->u.Type2)));
	ED_Dump_Union_End (OStream, "TrackingAreaIdentityList_Item", "Type2");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMobileId_Identity (TEDOStream* OStream, const c_epsMobileId_Identity* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsMobileId_Identity");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_Identity", "IdentityDigit");
		/* SEQUENCE NAME=<IdentityDigit> ACCESS=<Data->IdentityDigit>  ITEMS=<17> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "IdentityDigit", Data->IdentityDigit.items);
		for (i0=0; i0<Data->IdentityDigit.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->IdentityDigit.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->IdentityDigit.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		}
		ED_Dump_Sequence_End (OStream, "IdentityDigit", Data->IdentityDigit.items);
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_Identity", "IdentityDigit");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileId_Identity", "IdentityType");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileId_Identity", "IdentityType");
	ED_Dump_Struct_End (OStream, "epsMobileId_Identity");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsTBCDEmergencyNumber (TEDOStream* OStream, const c_epsTBCDEmergencyNumber* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsTBCDEmergencyNumber");
	ED_Dump_Struct_Begin_Field (OStream, "epsTBCDEmergencyNumber", "ServiceCategory");
	  /* STRUCTURAL=<0> TYPE=<c_epsServCategory> NAME=<ServiceCategory> ACCESS=<Data->ServiceCategory>  OPTIONAL=<0> FUNC=<Dump_c_epsServCategory> */
	  Dump_c_epsServCategory (OStream, &(Data->ServiceCategory));
	ED_Dump_Struct_End_Field (OStream, "epsTBCDEmergencyNumber", "ServiceCategory");
	ED_Dump_Struct_Begin_Field (OStream, "epsTBCDEmergencyNumber", "Numbers");
		/* SEQUENCE NAME=<Numbers> ACCESS=<Data->Numbers>  ITEMS=<32> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Numbers", Data->Numbers.items);
		for (i0=0; i0<Data->Numbers.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Numbers", i0, Data->Numbers.items);
		  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Numbers.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Numbers.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "Numbers", i0, Data->Numbers.items);
		}
		ED_Dump_Sequence_End (OStream, "Numbers", Data->Numbers.items);
	ED_Dump_Struct_End_Field (OStream, "epsTBCDEmergencyNumber", "Numbers");
	ED_Dump_Struct_End (OStream, "epsTBCDEmergencyNumber");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsTBCDArray (TEDOStream* OStream, const c_epsTBCDArray* Data)
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
void Dump_c_epsSupportedCodec (TEDOStream* OStream, const c_epsSupportedCodec* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsSupportedCodec");
	ED_Dump_Struct_Begin_Field (OStream, "epsSupportedCodec", "SysId");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<SysId> ACCESS=<Data->SysId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SysId);
	ED_Dump_Struct_End_Field (OStream, "epsSupportedCodec", "SysId");
	ED_Dump_Struct_Begin_Field (OStream, "epsSupportedCodec", "CodecBitmap");
	  /* NAME=<CodecBitmap> ACCESS=<Data->CodecBitmap>  MAXBITSIZE=<64> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->CodecBitmap.value, Data->CodecBitmap.usedBits);
	ED_Dump_Struct_End_Field (OStream, "epsSupportedCodec", "CodecBitmap");
	ED_Dump_Struct_End (OStream, "epsSupportedCodec");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSBearerContextStatus (TEDOStream* OStream, const c_EPSBearerContextStatus* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSBearerContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI07");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI07> ACCESS=<Data->EBI07>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI07);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI07");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI06");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI06> ACCESS=<Data->EBI06>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI06);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI06");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI05");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI05> ACCESS=<Data->EBI05>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI05);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI05");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI04");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI04> ACCESS=<Data->EBI04>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI04);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI04");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI15");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI15> ACCESS=<Data->EBI15>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI15);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI15");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI14");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI14> ACCESS=<Data->EBI14>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI14);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI14");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI13");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI13> ACCESS=<Data->EBI13>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI13);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI13");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI12");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI12> ACCESS=<Data->EBI12>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI12);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI12");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI11");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI11> ACCESS=<Data->EBI11>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI11);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI11");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI10");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI10> ACCESS=<Data->EBI10>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI10);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI10");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI09");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI09> ACCESS=<Data->EBI09>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI09);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI09");
	ED_Dump_Struct_Begin_Field (OStream, "EPSBearerContextStatus", "EBI08");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI08> ACCESS=<Data->EBI08>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI08);
	ED_Dump_Struct_End_Field (OStream, "EPSBearerContextStatus", "EBI08");
	ED_Dump_Struct_End (OStream, "EPSBearerContextStatus");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AdditionalUpdateResult (TEDOStream* OStream, const c_AdditionalUpdateResult* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AdditionalUpdateResult");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateResult", "ANB_UP_CIOT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ANB_UP_CIOT> ACCESS=<Data->ANB_UP_CIOT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->ANB_UP_CIOT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "user plane EPS optimization not accepted"); break;
				case 1: OStream->WriteString (OStream, "user plane EPS optimization accepted"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateResult", "ANB_UP_CIOT");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateResult", "ANB_CP_CIOT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ANB_CP_CIOT> ACCESS=<Data->ANB_CP_CIOT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->ANB_CP_CIOT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "control plane CIoT EPS optimization not accepted"); break;
				case 1: OStream->WriteString (OStream, "control plane CIoT EPS optimization accepted"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateResult", "ANB_CP_CIOT");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateResult", "Additional_update_result");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Additional_update_result> ACCESS=<Data->Additional_update_result>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Additional_update_result)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no additional information"); break;
				case 1: OStream->WriteString (OStream, "CS Fallback not preferred"); break;
				case 2: OStream->WriteString (OStream, "SMS only"); break;
				case 3: OStream->WriteString (OStream, "reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateResult", "Additional_update_result");
	ED_Dump_Struct_End (OStream, "AdditionalUpdateResult");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsAdditionalUpdateType (TEDOStream* OStream, const c_epsAdditionalUpdateType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsAdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "epsAdditionalUpdateType", "PNB_CIoT");
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
	ED_Dump_Struct_End_Field (OStream, "epsAdditionalUpdateType", "PNB_CIoT");
	ED_Dump_Struct_Begin_Field (OStream, "epsAdditionalUpdateType", "SAF");
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
	ED_Dump_Struct_End_Field (OStream, "epsAdditionalUpdateType", "SAF");
	ED_Dump_Struct_Begin_Field (OStream, "epsAdditionalUpdateType", "AUTV");
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
	ED_Dump_Struct_End_Field (OStream, "epsAdditionalUpdateType", "AUTV");
	ED_Dump_Struct_End (OStream, "epsAdditionalUpdateType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSDetachType (TEDOStream* OStream, const c_EPSDetachType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSDetachType");
	ED_Dump_Struct_Begin_Field (OStream, "EPSDetachType", "SwitchOff");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SwitchOff> ACCESS=<Data->SwitchOff>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SwitchOff)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "normal detach"); break;
				case 1: OStream->WriteString (OStream, "switch off"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPSDetachType", "SwitchOff");
	ED_Dump_Struct_Begin_Field (OStream, "EPSDetachType", "Type");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Type> ACCESS=<Data->Type>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Type)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "EPS detach"); break;
				case 2: OStream->WriteString (OStream, "IMSI detach"); break;
				case 3: OStream->WriteString (OStream, "combined EPS/IMSI detach"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPSDetachType", "Type");
	ED_Dump_Struct_End (OStream, "EPSDetachType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSNetworkFeatureSupport (TEDOStream* OStream, const c_EPSNetworkFeatureSupport* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "CP_CIoT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CP_CIoT> ACCESS=<Data->CP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CP_CIoT);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "CP_CIoT");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "ERw_oPDN");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ERw_oPDN> ACCESS=<Data->ERw_oPDN>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ERw_oPDN);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "ERw_oPDN");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "ESR_PS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ESR_PS> ACCESS=<Data->ESR_PS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ESR_PS);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "ESR_PS");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "CS_LCS");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CS_LCS> ACCESS=<Data->CS_LCS>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CS_LCS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no information about support of location services via CS domain is available"); break;
				case 1: OStream->WriteString (OStream, "location services via CS domain supported"); break;
				case 2: OStream->WriteString (OStream, "location services via CS domain not supported"); break;
				case 3: OStream->WriteString (OStream, "reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "CS_LCS");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "EPC_LCS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EPC_LCS> ACCESS=<Data->EPC_LCS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EPC_LCS);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "EPC_LCS");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "EMC_BS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMC_BS> ACCESS=<Data->EMC_BS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EMC_BS);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "EMC_BS");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "IMS_VoPS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<IMS_VoPS> ACCESS=<Data->IMS_VoPS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->IMS_VoPS);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "IMS_VoPS");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_EPSNetworkFeatureSupport_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "ePCO");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ePCO> ACCESS=<Data->ePCO>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ePCO);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "ePCO");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "HC_CP_CIoT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<HC_CP_CIoT> ACCESS=<Data->HC_CP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->HC_CP_CIoT);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "HC_CP_CIoT");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "S1_U_data");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<S1_U_data> ACCESS=<Data->S1_U_data>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->S1_U_data);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "S1_U_data");
	ED_Dump_Struct_Begin_Field (OStream, "EPSNetworkFeatureSupport", "UP_CIoT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UP_CIoT> ACCESS=<Data->UP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UP_CIoT);
	ED_Dump_Struct_End_Field (OStream, "EPSNetworkFeatureSupport", "UP_CIoT");
	ED_Dump_Struct_End (OStream, "EPSNetworkFeatureSupport");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSUpdateType (TEDOStream* OStream, const c_EPSUpdateType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPSUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "EPSUpdateType", "Active");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Active> ACCESS=<Data->Active>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Active)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No bearer establishment requested"); break;
				case 1: OStream->WriteString (OStream, "Bearer establishment requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPSUpdateType", "Active");
	ED_Dump_Struct_Begin_Field (OStream, "EPSUpdateType", "EPSUpdTypeValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSUpdTypeValue> ACCESS=<Data->EPSUpdTypeValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EPSUpdTypeValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "TA updating"); break;
				case 1: OStream->WriteString (OStream, "Combined TA/LA updating"); break;
				case 2: OStream->WriteString (OStream, "Combined TA/LA updating with IMSI attach"); break;
				case 3: OStream->WriteString (OStream, "Periodic updating"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EPSUpdateType", "EPSUpdTypeValue");
	ED_Dump_Struct_End (OStream, "EPSUpdateType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_KSIAndSequenceNumber (TEDOStream* OStream, const c_KSIAndSequenceNumber* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "KSIAndSequenceNumber");
	ED_Dump_Struct_Begin_Field (OStream, "KSIAndSequenceNumber", "KSIasme");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<KSIasme> ACCESS=<Data->KSIasme>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->KSIasme);
	ED_Dump_Struct_End_Field (OStream, "KSIAndSequenceNumber", "KSIasme");
	ED_Dump_Struct_Begin_Field (OStream, "KSIAndSequenceNumber", "SequenceNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SequenceNumber> ACCESS=<Data->SequenceNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SequenceNumber);
	ED_Dump_Struct_End_Field (OStream, "KSIAndSequenceNumber", "SequenceNumber");
	ED_Dump_Struct_End (OStream, "KSIAndSequenceNumber");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NASKeySetIdentifier (TEDOStream* OStream, const c_NASKeySetIdentifier* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "NASKeySetIdentifier", "TSC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TSC> ACCESS=<Data->TSC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->TSC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "cached security context"); break;
				case 1: OStream->WriteString (OStream, "mapped security context"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NASKeySetIdentifier", "TSC");
	ED_Dump_Struct_Begin_Field (OStream, "NASKeySetIdentifier", "NASKeySetId");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NASKeySetId> ACCESS=<Data->NASKeySetId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->NASKeySetId);
	ED_Dump_Struct_End_Field (OStream, "NASKeySetIdentifier", "NASKeySetId");
	ED_Dump_Struct_End (OStream, "NASKeySetIdentifier");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NASSecurityAlgorithms (TEDOStream* OStream, const c_NASSecurityAlgorithms* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NASSecurityAlgorithms");
	ED_Dump_Struct_Begin_Field (OStream, "NASSecurityAlgorithms", "spare1");
	  /* STRUCTURAL=<0> TYPE=<c_NASSecurityAlgorithms_spare1> NAME=<spare1> ACCESS=<Data->spare1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NASSecurityAlgorithms", "spare1");
	ED_Dump_Struct_Begin_Field (OStream, "NASSecurityAlgorithms", "TypeOfCipheringAlg");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfCipheringAlg> ACCESS=<Data->TypeOfCipheringAlg>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfCipheringAlg)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "EPS encryption algorithm 128-EEA0 (ciphering not used)"); break;
				case 1: OStream->WriteString (OStream, "EPS encryption algorithm 128-EEA1"); break;
				case 2: OStream->WriteString (OStream, "EPS encryption algorithm 128-EEA2"); break;
				case 3: OStream->WriteString (OStream, "EPS encryption algorithm 128-EEA3"); break;
				case 4: OStream->WriteString (OStream, "EPS encryption algorithm EEA4"); break;
				case 5: OStream->WriteString (OStream, "EPS encryption algorithm EEA5"); break;
				case 6: OStream->WriteString (OStream, "EPS encryption algorithm EEA6"); break;
				case 7: OStream->WriteString (OStream, "EPS encryption algorithm EEA7"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NASSecurityAlgorithms", "TypeOfCipheringAlg");
	ED_Dump_Struct_Begin_Field (OStream, "NASSecurityAlgorithms", "spare2");
	  /* STRUCTURAL=<0> TYPE=<c_NASSecurityAlgorithms_spare2> NAME=<spare2> ACCESS=<Data->spare2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NASSecurityAlgorithms", "spare2");
	ED_Dump_Struct_Begin_Field (OStream, "NASSecurityAlgorithms", "TypeOfIntegrityProtectionAlg");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfIntegrityProtectionAlg> ACCESS=<Data->TypeOfIntegrityProtectionAlg>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfIntegrityProtectionAlg)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Reserved"); break;
				case 1: OStream->WriteString (OStream, "EPS integrity algorithm 128-EIA1"); break;
				case 2: OStream->WriteString (OStream, "EPS integrity algorithm 128-EIA2"); break;
				case 3: OStream->WriteString (OStream, "EPS integrity algorithm 128-EIA3"); break;
				case 4: OStream->WriteString (OStream, "EPS integrity algorithm EIA4"); break;
				case 5: OStream->WriteString (OStream, "EPS integrity algorithm EIA5"); break;
				case 6: OStream->WriteString (OStream, "EPS integrity algorithm EIA6"); break;
				case 7: OStream->WriteString (OStream, "EPS integrity algorithm EIA7"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NASSecurityAlgorithms", "TypeOfIntegrityProtectionAlg");
	ED_Dump_Struct_End (OStream, "NASSecurityAlgorithms");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ExtendedEMMCause (TEDOStream* OStream, const c_ExtendedEMMCause* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ExtendedEMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ExtendedEMMCause", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedEMMCause_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ExtendedEMMCause", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ExtendedEMMCause", "E_UTRAN_allowed");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRAN_allowed> ACCESS=<Data->E_UTRAN_allowed>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->E_UTRAN_allowed)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "E-UTRAN allowed"); break;
				case 1: OStream->WriteString (OStream, "E-UTRAN not allowed"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ExtendedEMMCause", "E_UTRAN_allowed");
	ED_Dump_Struct_End (OStream, "ExtendedEMMCause");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TrackingAreaIdentity (TEDOStream* OStream, const c_TrackingAreaIdentity* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TrackingAreaIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "TrackingAreaIdentity", "TAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<TAC> ACCESS=<Data->TAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TAC);
	ED_Dump_Struct_End_Field (OStream, "TrackingAreaIdentity", "TAC");
	ED_Dump_Struct_End (OStream, "TrackingAreaIdentity");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GUTIType (TEDOStream* OStream, const c_GUTIType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GUTIType");
	ED_Dump_Struct_Begin_Field (OStream, "GUTIType", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_GUTIType_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "GUTIType", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "GUTIType", "GUTIType");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GUTIType> ACCESS=<Data->GUTIType>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->GUTIType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Native GUTI"); break;
				case 1: OStream->WriteString (OStream, "Mapped GUTI"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "GUTIType", "GUTIType");
	ED_Dump_Struct_End (OStream, "GUTIType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DataServiceType (TEDOStream* OStream, const c_DataServiceType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DataServiceType");
	ED_Dump_Struct_Begin_Field (OStream, "DataServiceType", "ActiveFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ActiveFlag> ACCESS=<Data->ActiveFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ActiveFlag);
	ED_Dump_Struct_End_Field (OStream, "DataServiceType", "ActiveFlag");
	ED_Dump_Struct_Begin_Field (OStream, "DataServiceType", "Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Value> ACCESS=<Data->Value>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Value)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "mobile originating request"); break;
				case 1: OStream->WriteString (OStream, "mobile terminating request"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DataServiceType", "Value");
	ED_Dump_Struct_End (OStream, "DataServiceType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HeaderCompressionCfgStatus (TEDOStream* OStream, const c_HeaderCompressionCfgStatus* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HeaderCompressionCfgStatus");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_7> ACCESS=<Data->EBI_7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_7);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_7");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_6> ACCESS=<Data->EBI_6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_6);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_6");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_5> ACCESS=<Data->EBI_5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_5);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_5");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_4> ACCESS=<Data->EBI_4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_4);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_4");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_3> ACCESS=<Data->EBI_3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_3);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_3");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_2> ACCESS=<Data->EBI_2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_2);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_2");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_1> ACCESS=<Data->EBI_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_1);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_1");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_0");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_0> ACCESS=<Data->EBI_0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_0);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_0");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_15");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_15> ACCESS=<Data->EBI_15>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_15);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_15");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_14");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_14> ACCESS=<Data->EBI_14>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_14);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_14");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_13");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_13> ACCESS=<Data->EBI_13>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_13);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_13");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_12");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_12> ACCESS=<Data->EBI_12>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_12);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_12");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_11");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_11> ACCESS=<Data->EBI_11>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_11);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_11");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_10");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_10> ACCESS=<Data->EBI_10>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_10);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_10");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_9");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_9> ACCESS=<Data->EBI_9>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_9);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_9");
	ED_Dump_Struct_Begin_Field (OStream, "HeaderCompressionCfgStatus", "EBI_8");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EBI_8> ACCESS=<Data->EBI_8>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EBI_8);
	ED_Dump_Struct_End_Field (OStream, "HeaderCompressionCfgStatus", "EBI_8");
	ED_Dump_Struct_End (OStream, "HeaderCompressionCfgStatus");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsLocationAreaId (TEDOStream* OStream, const c_epsLocationAreaId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsLocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "epsLocationAreaId", "LAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<LAC> ACCESS=<Data->LAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LAC);
	ED_Dump_Struct_End_Field (OStream, "epsLocationAreaId", "LAC");
	ED_Dump_Struct_End (OStream, "epsLocationAreaId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMobileStationClassmark2 (TEDOStream* OStream, const c_epsMobileStationClassmark2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsMobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "spare1");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileStationClassmark2_spare1> NAME=<spare1> ACCESS=<Data->spare1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "spare1");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "RevisionLevel");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "RevisionLevel");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "EsInd");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "EsInd");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "A5_1");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "A5_1");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "RFPowerCapability");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "RFPowerCapability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "spare2");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileStationClassmark2_spare2> NAME=<spare2> ACCESS=<Data->spare2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "spare2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "PSCapability");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "PSCapability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "SSScreenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SSScreenIndicator> ACCESS=<Data->SSScreenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SSScreenIndicator);
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "SSScreenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "SMCapability");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "SMCapability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "VBS");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "VBS");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "VGCS");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "VGCS");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "FC");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "FC");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "CM3");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "CM3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "spare3");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileStationClassmark2_spare3> NAME=<spare3> ACCESS=<Data->spare3>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "spare3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "LCSVA_CAP");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "LCSVA_CAP");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "UCS2");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "UCS2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "SoLSA");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "SoLSA");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "CMSP");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "CMSP");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "A5_3");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "A5_3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMobileStationClassmark2", "A5_2");
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
	ED_Dump_Struct_End_Field (OStream, "epsMobileStationClassmark2", "A5_2");
	ED_Dump_Struct_End (OStream, "epsMobileStationClassmark2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMSNetworkFeatureSupport (TEDOStream* OStream, const c_epsMSNetworkFeatureSupport* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsMSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "epsMSNetworkFeatureSupport", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsMSNetworkFeatureSupport_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsMSNetworkFeatureSupport", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsMSNetworkFeatureSupport", "extendedPeriodicTimers");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<extendedPeriodicTimers> ACCESS=<Data->extendedPeriodicTimers>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->extendedPeriodicTimers);
	ED_Dump_Struct_End_Field (OStream, "epsMSNetworkFeatureSupport", "extendedPeriodicTimers");
	ED_Dump_Struct_End (OStream, "epsMSNetworkFeatureSupport");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsNetwkName (TEDOStream* OStream, const c_epsNetwkName* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsNetwkName");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetwkName", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_epsNetwkName_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsNetwkName", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetwkName", "CodingScheme");
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
	ED_Dump_Struct_End_Field (OStream, "epsNetwkName", "CodingScheme");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetwkName", "AddCI");
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
	ED_Dump_Struct_End_Field (OStream, "epsNetwkName", "AddCI");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetwkName", "SpareBitsInLastOctet");
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
	ED_Dump_Struct_End_Field (OStream, "epsNetwkName", "SpareBitsInLastOctet");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetwkName", "TextString");
	  /* NAME=<TextString> ACCESS=<Data->TextString>  MAXBITSIZE=<1992> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TextString.value, Data->TextString.usedBits);
	ED_Dump_Struct_End_Field (OStream, "epsNetwkName", "TextString");
	ED_Dump_Struct_End (OStream, "epsNetwkName");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsTimeZoneAndTime (TEDOStream* OStream, const c_epsTimeZoneAndTime* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsTimeZoneAndTime");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Year");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Year> ACCESS=<Data->Year>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Year);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Year");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Month");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Month> ACCESS=<Data->Month>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Month);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Month");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Day");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Day> ACCESS=<Data->Day>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Day);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Day");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Hour");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Hour> ACCESS=<Data->Hour>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Hour);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Hour");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Minute");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Minute> ACCESS=<Data->Minute>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Minute);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Minute");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "Second");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Second> ACCESS=<Data->Second>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Second);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "Second");
	ED_Dump_Struct_Begin_Field (OStream, "epsTimeZoneAndTime", "TimeZone");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimeZone> ACCESS=<Data->TimeZone>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimeZone);
	ED_Dump_Struct_End_Field (OStream, "epsTimeZoneAndTime", "TimeZone");
	ED_Dump_Struct_End (OStream, "epsTimeZoneAndTime");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsDaylightSavingTime (TEDOStream* OStream, const c_epsDaylightSavingTime* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsDaylightSavingTime");
	ED_Dump_Struct_Begin_Field (OStream, "epsDaylightSavingTime", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsDaylightSavingTime_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsDaylightSavingTime", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsDaylightSavingTime", "Value");
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
	ED_Dump_Struct_End_Field (OStream, "epsDaylightSavingTime", "Value");
	ED_Dump_Struct_End (OStream, "epsDaylightSavingTime");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsTmsiStatus (TEDOStream* OStream, const c_epsTmsiStatus* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsTmsiStatus");
	ED_Dump_Struct_Begin_Field (OStream, "epsTmsiStatus", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsTmsiStatus_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsTmsiStatus", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsTmsiStatus", "TMSIFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TMSIFlag> ACCESS=<Data->TMSIFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TMSIFlag);
	ED_Dump_Struct_End_Field (OStream, "epsTmsiStatus", "TMSIFlag");
	ED_Dump_Struct_End (OStream, "epsTmsiStatus");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsDrxParam (TEDOStream* OStream, const c_epsDrxParam* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsDrxParam");
	ED_Dump_Struct_Begin_Field (OStream, "epsDrxParam", "SplitPgCycleCode");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SplitPgCycleCode> ACCESS=<Data->SplitPgCycleCode>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SplitPgCycleCode);
	ED_Dump_Struct_End_Field (OStream, "epsDrxParam", "SplitPgCycleCode");
	ED_Dump_Struct_Begin_Field (OStream, "epsDrxParam", "CNSpecDRX");
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
	ED_Dump_Struct_End_Field (OStream, "epsDrxParam", "CNSpecDRX");
	ED_Dump_Struct_Begin_Field (OStream, "epsDrxParam", "SplitOnCCCH");
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
	ED_Dump_Struct_End_Field (OStream, "epsDrxParam", "SplitOnCCCH");
	ED_Dump_Struct_Begin_Field (OStream, "epsDrxParam", "nonDRXTimer");
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
	ED_Dump_Struct_End_Field (OStream, "epsDrxParam", "nonDRXTimer");
	ED_Dump_Struct_End (OStream, "epsDrxParam");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsVoiceDomainPreferenceAndUEsUsageSetting (TEDOStream* OStream, const c_epsVoiceDomainPreferenceAndUEsUsageSetting* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsVoiceDomainPreferenceAndUEsUsageSetting_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "UEUsageSetting");
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
	ED_Dump_Struct_End_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "UEUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "VoiceDomainPreferenceForEUTRAN");
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
	ED_Dump_Struct_End_Field (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting", "VoiceDomainPreferenceForEUTRAN");
	ED_Dump_Struct_End (OStream, "epsVoiceDomainPreferenceAndUEsUsageSetting");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsNetworkResourceIdentifierContainer (TEDOStream* OStream, const c_epsNetworkResourceIdentifierContainer* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsNetworkResourceIdentifierContainer");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetworkResourceIdentifierContainer", "NRIContainerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<NRIContainerValue> ACCESS=<Data->NRIContainerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NRIContainerValue);
	ED_Dump_Struct_End_Field (OStream, "epsNetworkResourceIdentifierContainer", "NRIContainerValue");
	ED_Dump_Struct_Begin_Field (OStream, "epsNetworkResourceIdentifierContainer", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsNetworkResourceIdentifierContainer_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsNetworkResourceIdentifierContainer", "spare");
	ED_Dump_Struct_End (OStream, "epsNetworkResourceIdentifierContainer");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsExtendedDRXParameters (TEDOStream* OStream, const c_epsExtendedDRXParameters* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsExtendedDRXParameters");
	ED_Dump_Struct_Begin_Field (OStream, "epsExtendedDRXParameters", "PagingTimeWindow");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PagingTimeWindow> ACCESS=<Data->PagingTimeWindow>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->PagingTimeWindow);
	ED_Dump_Struct_End_Field (OStream, "epsExtendedDRXParameters", "PagingTimeWindow");
	ED_Dump_Struct_Begin_Field (OStream, "epsExtendedDRXParameters", "eDRX");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<eDRX> ACCESS=<Data->eDRX>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->eDRX);
	ED_Dump_Struct_End_Field (OStream, "epsExtendedDRXParameters", "eDRX");
	ED_Dump_Struct_End (OStream, "epsExtendedDRXParameters");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsGprsTimer2 (TEDOStream* OStream, const c_epsGprsTimer2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsGprsTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "epsGprsTimer2", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "epsGprsTimer2", "TimerValue");
	ED_Dump_Struct_End (OStream, "epsGprsTimer2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsCallingPartyBcdNum (TEDOStream* OStream, const c_epsCallingPartyBcdNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsCallingPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "TypeOfNumber");
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
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "NumberingPlanIdent");
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
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "PresentationIndicator");
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
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "PresentationIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_epsCallingPartyBcdNum_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "ScreeningIndicator");
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
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "ScreeningIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsCallingPartyBcdNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_epsTBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_epsTBCDArray> */
	  Dump_c_epsTBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "epsCallingPartyBcdNum", "Number");
	ED_Dump_Struct_End (OStream, "epsCallingPartyBcdNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PartialTrackingAreaIdentityList (TEDOStream* OStream, const c_PartialTrackingAreaIdentityList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<16> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_TrackingAreaIdentityList_Item> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_TrackingAreaIdentityList_Item> */
	  Dump_c_TrackingAreaIdentityList_Item (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsPlmnList (TEDOStream* OStream, const c_epsPlmnList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<5> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_epsPlmn> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_epsPlmn> */
	  Dump_c_epsPlmn (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsEmergencyNumberList (TEDOStream* OStream, const c_epsEmergencyNumberList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<6> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_epsTBCDEmergencyNumber> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_epsTBCDEmergencyNumber> */
	  Dump_c_epsTBCDEmergencyNumber (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsSupportedCodecList (TEDOStream* OStream, const c_epsSupportedCodecList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<6> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_epsSupportedCodec> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_epsSupportedCodec> */
	  Dump_c_epsSupportedCodec (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UENetworkCapability (TEDOStream* OStream, const c_UENetworkCapability* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UENetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EEA0");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA0> ACCESS=<Data->p128_EEA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA0);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EEA0");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EEA1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA1> ACCESS=<Data->p128_EEA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA1);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EEA1");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EEA2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA2> ACCESS=<Data->p128_EEA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA2);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EEA2");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EEA3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA3> ACCESS=<Data->p128_EEA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA3);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EEA3");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EEA4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA4> ACCESS=<Data->EEA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA4);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EEA4");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EEA5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA5> ACCESS=<Data->EEA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA5);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EEA5");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EEA6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA6> ACCESS=<Data->EEA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA6);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EEA6");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EEA7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA7> ACCESS=<Data->EEA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA7);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EEA7");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EIA0");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA0> ACCESS=<Data->EIA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA0);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EIA0");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EIA1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA1> ACCESS=<Data->p128_EIA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA1);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EIA1");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EIA2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA2> ACCESS=<Data->p128_EIA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA2);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EIA2");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "p128_EIA3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA3> ACCESS=<Data->p128_EIA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA3);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "p128_EIA3");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EIA4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA4> ACCESS=<Data->EIA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA4);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EIA4");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EIA5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA5> ACCESS=<Data->EIA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA5);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EIA5");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EIA6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA6> ACCESS=<Data->EIA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA6);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EIA6");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "EIA7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA7> ACCESS=<Data->EIA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA7);
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "EIA7");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "octet_5");
	if (!Data->octet_5_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UENetworkCapability_octet_5");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA0");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA0> ACCESS=<Data->octet_5->UEA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA0);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA0");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA1");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA1> ACCESS=<Data->octet_5->UEA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA1);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA1");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA2> ACCESS=<Data->octet_5->UEA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA2);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA2");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA3");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA3> ACCESS=<Data->octet_5->UEA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA3);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA3");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA4");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA4> ACCESS=<Data->octet_5->UEA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA4);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA4");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA5");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA5> ACCESS=<Data->octet_5->UEA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA5);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA5");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA6");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA6> ACCESS=<Data->octet_5->UEA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA6);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA6");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_5", "UEA7");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA7> ACCESS=<Data->octet_5->UEA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_5->UEA7);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_5", "UEA7");
		ED_Dump_Struct_End (OStream, "UENetworkCapability_octet_5");
	}
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "octet_5");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "octet_6");
	if (!Data->octet_6_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UENetworkCapability_octet_6");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UCS2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2> ACCESS=<Data->octet_6->UCS2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UCS2);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UCS2");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA1");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA1> ACCESS=<Data->octet_6->UIA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA1);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA1");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA2> ACCESS=<Data->octet_6->UIA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA2);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA2");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA3");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA3> ACCESS=<Data->octet_6->UIA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA3);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA3");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA4");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA4> ACCESS=<Data->octet_6->UIA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA4);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA4");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA5");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA5> ACCESS=<Data->octet_6->UIA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA5);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA5");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA6");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA6> ACCESS=<Data->octet_6->UIA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA6);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA6");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_6", "UIA7");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA7> ACCESS=<Data->octet_6->UIA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_6->UIA7);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_6", "UIA7");
		ED_Dump_Struct_End (OStream, "UENetworkCapability_octet_6");
	}
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "octet_6");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "octet_7");
	if (!Data->octet_7_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UENetworkCapability_octet_7");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "H245_ASH");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<H245_ASH> ACCESS=<Data->octet_7->H245_ASH>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->H245_ASH);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "H245_ASH");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "ACC_CSFB");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ACC_CSFB> ACCESS=<Data->octet_7->ACC_CSFB>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->ACC_CSFB);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "ACC_CSFB");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "LPP");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LPP> ACCESS=<Data->octet_7->LPP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->LPP);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "LPP");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "LCS");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LCS> ACCESS=<Data->octet_7->LCS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->LCS);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "LCS");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "p1xSR_VCC");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p1xSR_VCC> ACCESS=<Data->octet_7->p1xSR_VCC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->p1xSR_VCC);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "p1xSR_VCC");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_7", "ISR");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ISR> ACCESS=<Data->octet_7->ISR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_7->ISR);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_7", "ISR");
		ED_Dump_Struct_End (OStream, "UENetworkCapability_octet_7");
	}
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "octet_7");
	ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability", "octet_8");
	if (!Data->octet_8_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UENetworkCapability_octet_8");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "ePCO");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ePCO> ACCESS=<Data->octet_8->ePCO>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->ePCO);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "ePCO");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "HC_CP_CIoT");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<HC_CP_CIoT> ACCESS=<Data->octet_8->HC_CP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->HC_CP_CIoT);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "HC_CP_CIoT");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "ERw_oPDN");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ERw_oPDN> ACCESS=<Data->octet_8->ERw_oPDN>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->ERw_oPDN);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "ERw_oPDN");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "S1_U_data");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<S1_U_data> ACCESS=<Data->octet_8->S1_U_data>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->S1_U_data);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "S1_U_data");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "UP_CIoT");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UP_CIoT> ACCESS=<Data->octet_8->UP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->UP_CIoT);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "UP_CIoT");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "CP_CIoT");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CP_CIoT> ACCESS=<Data->octet_8->CP_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->CP_CIoT);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "CP_CIoT");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "Prose_relay");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Prose_relay> ACCESS=<Data->octet_8->Prose_relay>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->Prose_relay);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "Prose_relay");
		ED_Dump_Struct_Begin_Field (OStream, "UENetworkCapability_octet_8", "ProSe_dc");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ProSe_dc> ACCESS=<Data->octet_8->ProSe_dc>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->octet_8->ProSe_dc);
		ED_Dump_Struct_End_Field (OStream, "UENetworkCapability_octet_8", "ProSe_dc");
		ED_Dump_Struct_End (OStream, "UENetworkCapability_octet_8");
	}
	ED_Dump_Struct_End_Field (OStream, "UENetworkCapability", "octet_8");
	ED_Dump_Struct_End (OStream, "UENetworkCapability");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UESecurityCapability (TEDOStream* OStream, const c_UESecurityCapability* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UESecurityCapability");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EEA0");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA0> ACCESS=<Data->p128_EEA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA0);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EEA0");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EEA1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA1> ACCESS=<Data->p128_EEA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA1);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EEA1");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EEA2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA2> ACCESS=<Data->p128_EEA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA2);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EEA2");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EEA3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EEA3> ACCESS=<Data->p128_EEA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EEA3);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EEA3");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EEA4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA4> ACCESS=<Data->EEA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA4);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EEA4");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EEA5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA5> ACCESS=<Data->EEA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA5);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EEA5");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EEA6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA6> ACCESS=<Data->EEA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA6);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EEA6");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EEA7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EEA7> ACCESS=<Data->EEA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EEA7);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EEA7");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EIA0");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA0> ACCESS=<Data->p128_EIA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA0);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EIA0");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EIA1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA1> ACCESS=<Data->p128_EIA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA1);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EIA1");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EIA2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA2> ACCESS=<Data->p128_EIA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA2);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EIA2");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "p128_EIA3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<p128_EIA3> ACCESS=<Data->p128_EIA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->p128_EIA3);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "p128_EIA3");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EIA4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA4> ACCESS=<Data->EIA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA4);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EIA4");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EIA5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA5> ACCESS=<Data->EIA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA5);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EIA5");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EIA6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA6> ACCESS=<Data->EIA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA6);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EIA6");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "EIA7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EIA7> ACCESS=<Data->EIA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EIA7);
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "EIA7");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "UEA_UIA");
	if (!Data->UEA_UIA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UESecurityCapability_UEA_UIA");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA0");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA0> ACCESS=<Data->UEA_UIA->UEA0>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA0);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA0");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA1");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA1> ACCESS=<Data->UEA_UIA->UEA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA1);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA1");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA2> ACCESS=<Data->UEA_UIA->UEA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA2);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA2");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA3");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA3> ACCESS=<Data->UEA_UIA->UEA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA3);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA3");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA4");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA4> ACCESS=<Data->UEA_UIA->UEA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA4);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA4");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA5");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA5> ACCESS=<Data->UEA_UIA->UEA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA5);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA5");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA6");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA6> ACCESS=<Data->UEA_UIA->UEA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA6);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA6");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA7");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEA7> ACCESS=<Data->UEA_UIA->UEA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UEA7);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UEA7");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA1");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA1> ACCESS=<Data->UEA_UIA->UIA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA1);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA1");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA2> ACCESS=<Data->UEA_UIA->UIA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA2);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA2");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA3");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA3> ACCESS=<Data->UEA_UIA->UIA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA3);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA3");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA4");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA4> ACCESS=<Data->UEA_UIA->UIA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA4);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA4");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA5");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA5> ACCESS=<Data->UEA_UIA->UIA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA5);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA5");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA6");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA6> ACCESS=<Data->UEA_UIA->UIA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA6);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA6");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA7");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UIA7> ACCESS=<Data->UEA_UIA->UIA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->UEA_UIA->UIA7);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_UEA_UIA", "UIA7");
		ED_Dump_Struct_End (OStream, "UESecurityCapability_UEA_UIA");
	}
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "UEA_UIA");
	ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability", "GEA");
	if (!Data->GEA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "UESecurityCapability_GEA");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA1");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA1> ACCESS=<Data->GEA->GEA1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA1);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA1");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA2");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA2> ACCESS=<Data->GEA->GEA2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA2);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA2");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA3");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA3> ACCESS=<Data->GEA->GEA3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA3);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA3");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA4");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA4> ACCESS=<Data->GEA->GEA4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA4);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA4");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA5");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA5> ACCESS=<Data->GEA->GEA5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA5);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA5");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA6");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA6> ACCESS=<Data->GEA->GEA6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA6);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA6");
		ED_Dump_Struct_Begin_Field (OStream, "UESecurityCapability_GEA", "GEA7");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA7> ACCESS=<Data->GEA->GEA7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->GEA->GEA7);
		ED_Dump_Struct_End_Field (OStream, "UESecurityCapability_GEA", "GEA7");
		ED_Dump_Struct_End (OStream, "UESecurityCapability_GEA");
	}
	ED_Dump_Struct_End_Field (OStream, "UESecurityCapability", "GEA");
	ED_Dump_Struct_End (OStream, "UESecurityCapability");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsClassmark3Value (TEDOStream* OStream, const c_epsClassmark3Value* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsClassmark3Value");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Multiband_supported");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Multiband_supported> ACCESS=<Data->Multiband_supported>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Multiband_supported);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Multiband_supported");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "A5_7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_7> ACCESS=<Data->A5_7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_7);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "A5_7");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "A5_6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_6> ACCESS=<Data->A5_6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_6);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "A5_6");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "A5_5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_5> ACCESS=<Data->A5_5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_5);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "A5_5");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "A5_4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_4> ACCESS=<Data->A5_4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_4);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "A5_4");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Associated_Radio_Capability_2");
	if (!Data->Associated_Radio_Capability_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Associated_Radio_Capability_2> ACCESS=<Data->Associated_Radio_Capability_2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Associated_Radio_Capability_2);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Associated_Radio_Capability_2");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Associated_Radio_Capability_1");
	if (!Data->Associated_Radio_Capability_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Associated_Radio_Capability_1> ACCESS=<Data->Associated_Radio_Capability_1>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Associated_Radio_Capability_1);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Associated_Radio_Capability_1");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "R_GSM_band_Associated_Radio_Capability");
	if (!Data->R_GSM_band_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<R_GSM_band_Associated_Radio_Capability> ACCESS=<Data->R_GSM_band_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->R_GSM_band_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "R_GSM_band_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "HSCSD_Multi_Slot_Class");
	if (!Data->HSCSD_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HSCSD_Multi_Slot_Class> ACCESS=<Data->HSCSD_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->HSCSD_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "HSCSD_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UCS2_treatment");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2_treatment> ACCESS=<Data->UCS2_treatment>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UCS2_treatment);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UCS2_treatment");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Extended_Measurement_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_Measurement_Capability> ACCESS=<Data->Extended_Measurement_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_Measurement_Capability);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Extended_Measurement_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "SMS_VALUE");
	if (!Data->SMS_VALUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SMS_VALUE> ACCESS=<Data->SMS_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SMS_VALUE);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "SMS_VALUE");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "SM_VALUE");
	if (!Data->SM_VALUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SM_VALUE> ACCESS=<Data->SM_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SM_VALUE);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "SM_VALUE");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "MS_Positioning_Method");
	if (!Data->MS_Positioning_Method_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MS_Positioning_Method> ACCESS=<Data->MS_Positioning_Method>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MS_Positioning_Method);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "MS_Positioning_Method");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "ECSD_Multi_Slot_Class");
	if (!Data->ECSD_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ECSD_Multi_Slot_Class> ACCESS=<Data->ECSD_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->ECSD_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "ECSD_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Modulation_Capability");
	if (!Data->Modulation_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Modulation_Capability> ACCESS=<Data->Modulation_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Modulation_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Modulation_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "_8_PSK_RF_Power_Capability_1");
	if (!Data->_8_PSK_RF_Power_Capability_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_RF_Power_Capability_1> ACCESS=<Data->_8_PSK_RF_Power_Capability_1>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_RF_Power_Capability_1);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "_8_PSK_RF_Power_Capability_1");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "_8_PSK_RF_Power_Capability_2");
	if (!Data->_8_PSK_RF_Power_Capability_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_RF_Power_Capability_2> ACCESS=<Data->_8_PSK_RF_Power_Capability_2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_RF_Power_Capability_2);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "_8_PSK_RF_Power_Capability_2");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_400_Bands_Supported");
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
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_400_Bands_Supported");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_400_Associated_Radio_Capability");
	if (!Data->GSM_400_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_400_Associated_Radio_Capability> ACCESS=<Data->GSM_400_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_400_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_400_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_850_Associated_Radio_Capability");
	if (!Data->GSM_850_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_850_Associated_Radio_Capability> ACCESS=<Data->GSM_850_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_850_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_850_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_1900_Associated_Radio_Capability");
	if (!Data->GSM_1900_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_1900_Associated_Radio_Capability> ACCESS=<Data->GSM_1900_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_1900_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_1900_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UMTS_FDD_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_FDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_FDD_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_FDD_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UMTS_FDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "CDMA_2000_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CDMA_2000_Radio_Access_Technology_Capability> ACCESS=<Data->CDMA_2000_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CDMA_2000_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "CDMA_2000_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "DTM_GPRS_Multi_Slot_Class");
	if (!Data->DTM_GPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_Multi_Slot_Class> ACCESS=<Data->DTM_GPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_GPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "DTM_GPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Single_Slot_DTM");
	if (!Data->Single_Slot_DTM_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Single_Slot_DTM> ACCESS=<Data->Single_Slot_DTM>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Single_Slot_DTM);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Single_Slot_DTM");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "DTM_EGPRS_Multi_Slot_Class");
	if (!Data->DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_EGPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "DTM_EGPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_Band");
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
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_Band");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_750_Associated_Radio_Capability");
	if (!Data->GSM_750_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_750_Associated_Radio_Capability> ACCESS=<Data->GSM_750_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_750_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_750_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
	if (!Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GERAN_Feature_Package_1");
	if (!Data->GERAN_Feature_Package_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Feature_Package_1> ACCESS=<Data->GERAN_Feature_Package_1>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Feature_Package_1);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GERAN_Feature_Package_1");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Extended_DTM_GPRS_Multi_Slot_Class");
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
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Extended_DTM_GPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Extended_DTM_EGPRS_Multi_Slot_Class");
	if (!Data->Extended_DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Extended_DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->Extended_DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Extended_DTM_EGPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Extended_DTM_EGPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "High_Multislot_Capability");
	if (!Data->High_Multislot_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<High_Multislot_Capability> ACCESS=<Data->High_Multislot_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->High_Multislot_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "High_Multislot_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Length");
	if (!Data->Length_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Length);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Length");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "FLO_Iu_Capability");
	if (!Data->FLO_Iu_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FLO_Iu_Capability> ACCESS=<Data->FLO_Iu_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->FLO_Iu_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "FLO_Iu_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GERAN_Feature_Package_2");
	if (!Data->GERAN_Feature_Package_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Feature_Package_2> ACCESS=<Data->GERAN_Feature_Package_2>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Feature_Package_2);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GERAN_Feature_Package_2");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GMSK_Multislot_Power_Profile");
	if (!Data->GMSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_Multislot_Power_Profile> ACCESS=<Data->GMSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GMSK_Multislot_Power_Profile);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GMSK_Multislot_Power_Profile");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "_8_PSK_Multislot_Power_Profile");
	if (!Data->_8_PSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_Multislot_Power_Profile> ACCESS=<Data->_8_PSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_Multislot_Power_Profile);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "_8_PSK_Multislot_Power_Profile");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "T_GSM_400_Bands_Supported");
	if (!Data->T_GSM_400_Bands_Supported_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_400_Bands_Supported> ACCESS=<Data->T_GSM_400_Bands_Supported>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_400_Bands_Supported);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "T_GSM_400_Bands_Supported");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "T_GSM_400_Associated_Radio_Capability");
	if (!Data->T_GSM_400_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_400_Associated_Radio_Capability> ACCESS=<Data->T_GSM_400_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_400_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "T_GSM_400_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "T_GSM_900_Associated_Radio_Capability");
	if (!Data->T_GSM_900_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_900_Associated_Radio_Capability> ACCESS=<Data->T_GSM_900_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_900_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "T_GSM_900_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Downlink_Advanced_Receiver_Performance");
	if (!Data->Downlink_Advanced_Receiver_Performance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_Advanced_Receiver_Performance> ACCESS=<Data->Downlink_Advanced_Receiver_Performance>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Downlink_Advanced_Receiver_Performance);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Downlink_Advanced_Receiver_Performance");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "DTM_Enhancements_Capability");
	if (!Data->DTM_Enhancements_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTM_Enhancements_Capability> ACCESS=<Data->DTM_Enhancements_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->DTM_Enhancements_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "DTM_Enhancements_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "DTM_GPRS_High_Multi_Slot_Class");
	if (!Data->DTM_GPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_High_Multi_Slot_Class> ACCESS=<Data->DTM_GPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_GPRS_High_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "DTM_GPRS_High_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Offset_required");
	if (!Data->Offset_required_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Offset_required> ACCESS=<Data->Offset_required>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Offset_required);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Offset_required");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "DTM_EGPRS_High_Multi_Slot_Class");
	if (!Data->DTM_EGPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_High_Multi_Slot_Class> ACCESS=<Data->DTM_EGPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_EGPRS_High_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "DTM_EGPRS_High_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Repeated_ACCH_Capability");
	if (!Data->Repeated_ACCH_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Repeated_ACCH_Capability> ACCESS=<Data->Repeated_ACCH_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Repeated_ACCH_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Repeated_ACCH_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GSM_710_Associated_Radio_Capability");
	if (!Data->GSM_710_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_710_Associated_Radio_Capability> ACCESS=<Data->GSM_710_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_710_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GSM_710_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "T_GSM_810_Associated_Radio_Capability");
	if (!Data->T_GSM_810_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_810_Associated_Radio_Capability> ACCESS=<Data->T_GSM_810_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_810_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "T_GSM_810_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Ciphering_Mode_Setting_Capability");
	if (!Data->Ciphering_Mode_Setting_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Ciphering_Mode_Setting_Capability> ACCESS=<Data->Ciphering_Mode_Setting_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Ciphering_Mode_Setting_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Ciphering_Mode_Setting_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Additional_Positioning_Capabilities");
	if (!Data->Additional_Positioning_Capabilities_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Additional_Positioning_Capabilities> ACCESS=<Data->Additional_Positioning_Capabilities>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Additional_Positioning_Capabilities);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Additional_Positioning_Capabilities");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "E_UTRA_FDD_support");
	if (!Data->E_UTRA_FDD_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_FDD_support> ACCESS=<Data->E_UTRA_FDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_FDD_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "E_UTRA_FDD_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "E_UTRA_TDD_support");
	if (!Data->E_UTRA_TDD_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_TDD_support> ACCESS=<Data->E_UTRA_TDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_TDD_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "E_UTRA_TDD_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "E_UTRA_Measurement_and_Reporting_support");
	if (!Data->E_UTRA_Measurement_and_Reporting_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Measurement_and_Reporting_support> ACCESS=<Data->E_UTRA_Measurement_and_Reporting_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Measurement_and_Reporting_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "E_UTRA_Measurement_and_Reporting_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Priority_based_reselection_support");
	if (!Data->Priority_based_reselection_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Priority_based_reselection_support> ACCESS=<Data->Priority_based_reselection_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Priority_based_reselection_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Priority_based_reselection_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UTRA_CSG_Cells_Reporting");
	if (!Data->UTRA_CSG_Cells_Reporting_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_CSG_Cells_Reporting> ACCESS=<Data->UTRA_CSG_Cells_Reporting>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UTRA_CSG_Cells_Reporting);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UTRA_CSG_Cells_Reporting");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "VAMOS_Level");
	if (!Data->VAMOS_Level_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VAMOS_Level> ACCESS=<Data->VAMOS_Level>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->VAMOS_Level);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "VAMOS_Level");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "TIGHTER_Capability");
	if (!Data->TIGHTER_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIGHTER_Capability> ACCESS=<Data->TIGHTER_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TIGHTER_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "TIGHTER_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Selective_Ciphering_of_Downlink_SACCH");
	if (!Data->Selective_Ciphering_of_Downlink_SACCH_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Selective_Ciphering_of_Downlink_SACCH> ACCESS=<Data->Selective_Ciphering_of_Downlink_SACCH>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Selective_Ciphering_of_Downlink_SACCH);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Selective_Ciphering_of_Downlink_SACCH");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_UTRA");
	if (!Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CS_to_PS_SRVCC_from_GERAN_to_UTRA> ACCESS=<Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_UTRA");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_E_UTRA");
	if (!Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> ACCESS=<Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_E_UTRA");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "GERAN_Network_Sharing_support");
	if (!Data->GERAN_Network_Sharing_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Network_Sharing_support> ACCESS=<Data->GERAN_Network_Sharing_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Network_Sharing_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "GERAN_Network_Sharing_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "E_UTRA_Wideband_RSRQ_measurements_support");
	if (!Data->E_UTRA_Wideband_RSRQ_measurements_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Wideband_RSRQ_measurements_support> ACCESS=<Data->E_UTRA_Wideband_RSRQ_measurements_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Wideband_RSRQ_measurements_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "E_UTRA_Wideband_RSRQ_measurements_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "ER_Band_Support");
	if (!Data->ER_Band_Support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ER_Band_Support> ACCESS=<Data->ER_Band_Support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ER_Band_Support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "ER_Band_Support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "UTRA_Multiple_Frequency_Band_Indicators_support");
	if (!Data->UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UTRA_Multiple_Frequency_Band_Indicators_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "UTRA_Multiple_Frequency_Band_Indicators_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
	if (!Data->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->E_UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Multiple_Frequency_Band_Indicators_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Extended_TSC_Set_Capability_support");
	if (!Data->Extended_TSC_Set_Capability_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_TSC_Set_Capability_support> ACCESS=<Data->Extended_TSC_Set_Capability_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_TSC_Set_Capability_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Extended_TSC_Set_Capability_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsClassmark3Value", "Extended_EARFCN_value_range");
	if (!Data->Extended_EARFCN_value_range_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_EARFCN_value_range> ACCESS=<Data->Extended_EARFCN_value_range>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_EARFCN_value_range);
	}
	ED_Dump_Struct_End_Field (OStream, "epsClassmark3Value", "Extended_EARFCN_value_range");
	ED_Dump_Struct_End (OStream, "epsClassmark3Value");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMsNetwkCpblty (TEDOStream* OStream, const c_epsMsNetwkCpblty* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsMsNetwkCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_1> ACCESS=<Data->GEA_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_1);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_1");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "SM_capabilities_via_dedicated_channels");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_capabilities_via_dedicated_channels> ACCESS=<Data->SM_capabilities_via_dedicated_channels>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_capabilities_via_dedicated_channels);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "SM_capabilities_via_dedicated_channels");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "SM_capabilities_via_GPRS_channels");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_capabilities_via_GPRS_channels> ACCESS=<Data->SM_capabilities_via_GPRS_channels>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_capabilities_via_GPRS_channels);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "SM_capabilities_via_GPRS_channels");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "UCS2_support");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2_support> ACCESS=<Data->UCS2_support>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UCS2_support);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "UCS2_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "SS_Screening_Indicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SS_Screening_Indicator> ACCESS=<Data->SS_Screening_Indicator>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SS_Screening_Indicator);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "SS_Screening_Indicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "SoLSA_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SoLSA_Capability> ACCESS=<Data->SoLSA_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SoLSA_Capability);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "SoLSA_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "Revision_level_indicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Revision_level_indicator> ACCESS=<Data->Revision_level_indicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Revision_level_indicator);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "Revision_level_indicator");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "PFC_feature_mode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PFC_feature_mode> ACCESS=<Data->PFC_feature_mode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PFC_feature_mode);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "PFC_feature_mode");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_2> ACCESS=<Data->GEA_2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_2);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_2");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_3> ACCESS=<Data->GEA_3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_3);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_3");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_4> ACCESS=<Data->GEA_4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_4);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_4");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_5> ACCESS=<Data->GEA_5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_5);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_5");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_6> ACCESS=<Data->GEA_6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_6);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_6");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GEA_7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_7> ACCESS=<Data->GEA_7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_7);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GEA_7");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "LCS_VA_capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LCS_VA_capability> ACCESS=<Data->LCS_VA_capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->LCS_VA_capability);
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "LCS_VA_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability");
	if (!Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> ACCESS=<Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability");
	if (!Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> ACCESS=<Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "EMM_Combined_procedures_Capability");
	if (!Data->EMM_Combined_procedures_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMM_Combined_procedures_Capability> ACCESS=<Data->EMM_Combined_procedures_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EMM_Combined_procedures_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "EMM_Combined_procedures_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "ISR_support");
	if (!Data->ISR_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ISR_support> ACCESS=<Data->ISR_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ISR_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "ISR_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "SRVCC_to_GERAN_UTRAN_capability");
	if (!Data->SRVCC_to_GERAN_UTRAN_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SRVCC_to_GERAN_UTRAN_capability> ACCESS=<Data->SRVCC_to_GERAN_UTRAN_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SRVCC_to_GERAN_UTRAN_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "SRVCC_to_GERAN_UTRAN_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "EPC_capability");
	if (!Data->EPC_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EPC_capability> ACCESS=<Data->EPC_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EPC_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "EPC_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "NF_capability");
	if (!Data->NF_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NF_capability> ACCESS=<Data->NF_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NF_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "NF_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GERAN_network_sharing_capability");
	if (!Data->GERAN_network_sharing_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_network_sharing_capability> ACCESS=<Data->GERAN_network_sharing_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_network_sharing_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GERAN_network_sharing_capability");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "User_plane_integrity_protection_support");
	if (!Data->User_plane_integrity_protection_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<User_plane_integrity_protection_support> ACCESS=<Data->User_plane_integrity_protection_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->User_plane_integrity_protection_support);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "User_plane_integrity_protection_support");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GIA_4");
	if (!Data->GIA_4_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_4> ACCESS=<Data->GIA_4>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_4);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GIA_4");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GIA_5");
	if (!Data->GIA_5_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_5> ACCESS=<Data->GIA_5>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_5);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GIA_5");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GIA_6");
	if (!Data->GIA_6_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_6> ACCESS=<Data->GIA_6>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_6);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GIA_6");
	ED_Dump_Struct_Begin_Field (OStream, "epsMsNetwkCpblty", "GIA_7");
	if (!Data->GIA_7_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_7> ACCESS=<Data->GIA_7>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_7);
	}
	ED_Dump_Struct_End_Field (OStream, "epsMsNetwkCpblty", "GIA_7");
	ED_Dump_Struct_End (OStream, "epsMsNetwkCpblty");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPSMobileIdentity (TEDOStream* OStream, const c_EPSMobileIdentity* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_EPSMobileIdentity_IMSI: {
		ED_Dump_Union_Begin (OStream, "EPSMobileIdentity", "IMSI");
		  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity_IMSI> NAME=<IMSI> ACCESS=<*(Data->u.IMSI)>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity_IMSI> */
		  Dump_c_EPSMobileIdentity_IMSI (OStream, &(*(Data->u.IMSI)));
	ED_Dump_Union_End (OStream, "EPSMobileIdentity", "IMSI");
			break;
		}
	case U_c_EPSMobileIdentity_GUTI: {
		ED_Dump_Union_Begin (OStream, "EPSMobileIdentity", "GUTI");
		  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity_GUTI> NAME=<GUTI> ACCESS=<*(Data->u.GUTI)>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity_GUTI> */
		  Dump_c_EPSMobileIdentity_GUTI (OStream, &(*(Data->u.GUTI)));
	ED_Dump_Union_End (OStream, "EPSMobileIdentity", "GUTI");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESMMessageUp (TEDOStream* OStream, const c_ESMMessageUp* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT> NAME=<pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT> ACCESS=<*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT> */
		  Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (OStream, &(*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT");
			break;
		}
	case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT> NAME=<pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT> ACCESS=<*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT> */
		  Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (OStream, &(*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT");
			break;
		}
	case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT> NAME=<pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT> ACCESS=<*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT> */
		  Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (OStream, &(*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT");
			break;
		}
	case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT> NAME=<pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT> ACCESS=<*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT> */
		  Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (OStream, &(*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT");
			break;
		}
	case U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pBEARER_RESOURCE_ALLOCATION_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_ALLOCATION_REQUEST> NAME=<pBEARER_RESOURCE_ALLOCATION_REQUEST> ACCESS=<*(Data->u.pBEARER_RESOURCE_ALLOCATION_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_BEARER_RESOURCE_ALLOCATION_REQUEST> */
		  Dump_c_BEARER_RESOURCE_ALLOCATION_REQUEST (OStream, &(*(Data->u.pBEARER_RESOURCE_ALLOCATION_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pBEARER_RESOURCE_ALLOCATION_REQUEST");
			break;
		}
	case U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pBEARER_RESOURCE_MODIFICATION_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_MODIFICATION_REQUEST> NAME=<pBEARER_RESOURCE_MODIFICATION_REQUEST> ACCESS=<*(Data->u.pBEARER_RESOURCE_MODIFICATION_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_BEARER_RESOURCE_MODIFICATION_REQUEST> */
		  Dump_c_BEARER_RESOURCE_MODIFICATION_REQUEST (OStream, &(*(Data->u.pBEARER_RESOURCE_MODIFICATION_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pBEARER_RESOURCE_MODIFICATION_REQUEST");
			break;
		}
	case U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT");
		  /* STRUCTURAL=<0> TYPE=<c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT> NAME=<pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT> ACCESS=<*(Data->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT)>  OPTIONAL=<0> FUNC=<Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT> */
		  Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (OStream, &(*(Data->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT");
			break;
		}
	case U_c_ESMMessageUp_pESM_DATA_TRANSPORT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pESM_DATA_TRANSPORT");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_DATA_TRANSPORT> NAME=<pESM_DATA_TRANSPORT> ACCESS=<*(Data->u.pESM_DATA_TRANSPORT)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_DATA_TRANSPORT> */
		  Dump_c_ESM_DATA_TRANSPORT (OStream, &(*(Data->u.pESM_DATA_TRANSPORT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pESM_DATA_TRANSPORT");
			break;
		}
	case U_c_ESMMessageUp_pESM_DUMMY_MESSAGE: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pESM_DUMMY_MESSAGE");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_DUMMY_MESSAGE> NAME=<pESM_DUMMY_MESSAGE> ACCESS=<*(Data->u.pESM_DUMMY_MESSAGE)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_DUMMY_MESSAGE> */
		  Dump_c_ESM_DUMMY_MESSAGE (OStream, &(*(Data->u.pESM_DUMMY_MESSAGE)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pESM_DUMMY_MESSAGE");
			break;
		}
	case U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pESM_INFORMATION_RESPONSE");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_INFORMATION_RESPONSE> NAME=<pESM_INFORMATION_RESPONSE> ACCESS=<*(Data->u.pESM_INFORMATION_RESPONSE)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_INFORMATION_RESPONSE> */
		  Dump_c_ESM_INFORMATION_RESPONSE (OStream, &(*(Data->u.pESM_INFORMATION_RESPONSE)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pESM_INFORMATION_RESPONSE");
			break;
		}
	case U_c_ESMMessageUp_pESM_STATUS: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pESM_STATUS");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_STATUS> NAME=<pESM_STATUS> ACCESS=<*(Data->u.pESM_STATUS)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_STATUS> */
		  Dump_c_ESM_STATUS (OStream, &(*(Data->u.pESM_STATUS)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pESM_STATUS");
			break;
		}
	case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pMODIFY_EPS_BEARER_CONTEXT_ACCEPT");
		  /* STRUCTURAL=<0> TYPE=<c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT> NAME=<pMODIFY_EPS_BEARER_CONTEXT_ACCEPT> ACCESS=<*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT)>  OPTIONAL=<0> FUNC=<Dump_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT> */
		  Dump_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (OStream, &(*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pMODIFY_EPS_BEARER_CONTEXT_ACCEPT");
			break;
		}
	case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pMODIFY_EPS_BEARER_CONTEXT_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_MODIFY_EPS_BEARER_CONTEXT_REJECT> NAME=<pMODIFY_EPS_BEARER_CONTEXT_REJECT> ACCESS=<*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_MODIFY_EPS_BEARER_CONTEXT_REJECT> */
		  Dump_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (OStream, &(*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pMODIFY_EPS_BEARER_CONTEXT_REJECT");
			break;
		}
	case U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pPDN_CONNECTIVITY_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_PDN_CONNECTIVITY_REQUEST> NAME=<pPDN_CONNECTIVITY_REQUEST> ACCESS=<*(Data->u.pPDN_CONNECTIVITY_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_PDN_CONNECTIVITY_REQUEST> */
		  Dump_c_PDN_CONNECTIVITY_REQUEST (OStream, &(*(Data->u.pPDN_CONNECTIVITY_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pPDN_CONNECTIVITY_REQUEST");
			break;
		}
	case U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pPDN_DISCONNECT_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_PDN_DISCONNECT_REQUEST> NAME=<pPDN_DISCONNECT_REQUEST> ACCESS=<*(Data->u.pPDN_DISCONNECT_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_PDN_DISCONNECT_REQUEST> */
		  Dump_c_PDN_DISCONNECT_REQUEST (OStream, &(*(Data->u.pPDN_DISCONNECT_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pPDN_DISCONNECT_REQUEST");
			break;
		}
	case U_c_ESMMessageUp_pREMOTE_UE_REPORT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageUp", "pREMOTE_UE_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_REMOTE_UE_REPORT> NAME=<pREMOTE_UE_REPORT> ACCESS=<*(Data->u.pREMOTE_UE_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_REMOTE_UE_REPORT> */
		  Dump_c_REMOTE_UE_REPORT (OStream, &(*(Data->u.pREMOTE_UE_REPORT)));
	ED_Dump_Union_End (OStream, "ESMMessageUp", "pREMOTE_UE_REPORT");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ESMMessageDn (TEDOStream* OStream, const c_ESMMessageDn* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST> NAME=<pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST> ACCESS=<*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST> */
		  Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (OStream, &(*(Data->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST");
			break;
		}
	case U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST> NAME=<pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST> ACCESS=<*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST> */
		  Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (OStream, &(*(Data->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST");
			break;
		}
	case U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pBEARER_RESOURCE_ALLOCATION_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_ALLOCATION_REJECT> NAME=<pBEARER_RESOURCE_ALLOCATION_REJECT> ACCESS=<*(Data->u.pBEARER_RESOURCE_ALLOCATION_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_BEARER_RESOURCE_ALLOCATION_REJECT> */
		  Dump_c_BEARER_RESOURCE_ALLOCATION_REJECT (OStream, &(*(Data->u.pBEARER_RESOURCE_ALLOCATION_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pBEARER_RESOURCE_ALLOCATION_REJECT");
			break;
		}
	case U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pBEARER_RESOURCE_MODIFICATION_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_BEARER_RESOURCE_MODIFICATION_REJECT> NAME=<pBEARER_RESOURCE_MODIFICATION_REJECT> ACCESS=<*(Data->u.pBEARER_RESOURCE_MODIFICATION_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_BEARER_RESOURCE_MODIFICATION_REJECT> */
		  Dump_c_BEARER_RESOURCE_MODIFICATION_REJECT (OStream, &(*(Data->u.pBEARER_RESOURCE_MODIFICATION_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pBEARER_RESOURCE_MODIFICATION_REJECT");
			break;
		}
	case U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST> NAME=<pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST> ACCESS=<*(Data->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST> */
		  Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (OStream, &(*(Data->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST");
			break;
		}
	case U_c_ESMMessageDn_pEPS_NOTIFICATION: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pEPS_NOTIFICATION");
		  /* STRUCTURAL=<0> TYPE=<c_EPS_NOTIFICATION> NAME=<pEPS_NOTIFICATION> ACCESS=<*(Data->u.pEPS_NOTIFICATION)>  OPTIONAL=<0> FUNC=<Dump_c_EPS_NOTIFICATION> */
		  Dump_c_EPS_NOTIFICATION (OStream, &(*(Data->u.pEPS_NOTIFICATION)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pEPS_NOTIFICATION");
			break;
		}
	case U_c_ESMMessageDn_pESM_DATA_TRANSPORT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pESM_DATA_TRANSPORT");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_DATA_TRANSPORT> NAME=<pESM_DATA_TRANSPORT> ACCESS=<*(Data->u.pESM_DATA_TRANSPORT)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_DATA_TRANSPORT> */
		  Dump_c_ESM_DATA_TRANSPORT (OStream, &(*(Data->u.pESM_DATA_TRANSPORT)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pESM_DATA_TRANSPORT");
			break;
		}
	case U_c_ESMMessageDn_pESM_DUMMY_MESSAGE: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pESM_DUMMY_MESSAGE");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_DUMMY_MESSAGE> NAME=<pESM_DUMMY_MESSAGE> ACCESS=<*(Data->u.pESM_DUMMY_MESSAGE)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_DUMMY_MESSAGE> */
		  Dump_c_ESM_DUMMY_MESSAGE (OStream, &(*(Data->u.pESM_DUMMY_MESSAGE)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pESM_DUMMY_MESSAGE");
			break;
		}
	case U_c_ESMMessageDn_pESM_INFORMATION_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pESM_INFORMATION_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_INFORMATION_REQUEST> NAME=<pESM_INFORMATION_REQUEST> ACCESS=<*(Data->u.pESM_INFORMATION_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_INFORMATION_REQUEST> */
		  Dump_c_ESM_INFORMATION_REQUEST (OStream, &(*(Data->u.pESM_INFORMATION_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pESM_INFORMATION_REQUEST");
			break;
		}
	case U_c_ESMMessageDn_pESM_STATUS: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pESM_STATUS");
		  /* STRUCTURAL=<0> TYPE=<c_ESM_STATUS> NAME=<pESM_STATUS> ACCESS=<*(Data->u.pESM_STATUS)>  OPTIONAL=<0> FUNC=<Dump_c_ESM_STATUS> */
		  Dump_c_ESM_STATUS (OStream, &(*(Data->u.pESM_STATUS)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pESM_STATUS");
			break;
		}
	case U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pMODIFY_EPS_BEARER_CONTEXT_REQUEST");
		  /* STRUCTURAL=<0> TYPE=<c_MODIFY_EPS_BEARER_CONTEXT_REQUEST> NAME=<pMODIFY_EPS_BEARER_CONTEXT_REQUEST> ACCESS=<*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST)>  OPTIONAL=<0> FUNC=<Dump_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST> */
		  Dump_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (OStream, &(*(Data->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pMODIFY_EPS_BEARER_CONTEXT_REQUEST");
			break;
		}
	case U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pPDN_CONNECTIVITY_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_PDN_CONNECTIVITY_REJECT> NAME=<pPDN_CONNECTIVITY_REJECT> ACCESS=<*(Data->u.pPDN_CONNECTIVITY_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_PDN_CONNECTIVITY_REJECT> */
		  Dump_c_PDN_CONNECTIVITY_REJECT (OStream, &(*(Data->u.pPDN_CONNECTIVITY_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pPDN_CONNECTIVITY_REJECT");
			break;
		}
	case U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pPDN_DISCONNECT_REJECT");
		  /* STRUCTURAL=<0> TYPE=<c_PDN_DISCONNECT_REJECT> NAME=<pPDN_DISCONNECT_REJECT> ACCESS=<*(Data->u.pPDN_DISCONNECT_REJECT)>  OPTIONAL=<0> FUNC=<Dump_c_PDN_DISCONNECT_REJECT> */
		  Dump_c_PDN_DISCONNECT_REJECT (OStream, &(*(Data->u.pPDN_DISCONNECT_REJECT)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pPDN_DISCONNECT_REJECT");
			break;
		}
	case U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE: {
		ED_Dump_Union_Begin (OStream, "ESMMessageDn", "pREMOTE_UE_REPORT_RESPONSE");
		  /* STRUCTURAL=<0> TYPE=<c_REMOTE_UE_REPORT_RESPONSE> NAME=<pREMOTE_UE_REPORT_RESPONSE> ACCESS=<*(Data->u.pREMOTE_UE_REPORT_RESPONSE)>  OPTIONAL=<0> FUNC=<Dump_c_REMOTE_UE_REPORT_RESPONSE> */
		  Dump_c_REMOTE_UE_REPORT_RESPONSE (OStream, &(*(Data->u.pREMOTE_UE_REPORT_RESPONSE)));
	ED_Dump_Union_End (OStream, "ESMMessageDn", "pREMOTE_UE_REPORT_RESPONSE");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsMobileId (TEDOStream* OStream, const c_epsMobileId* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_epsMobileId_Identity: {
		ED_Dump_Union_Begin (OStream, "epsMobileId", "Identity");
		  /* STRUCTURAL=<0> TYPE=<c_epsMobileId_Identity> NAME=<Identity> ACCESS=<*(Data->u.Identity)>  OPTIONAL=<0> FUNC=<Dump_c_epsMobileId_Identity> */
		  Dump_c_epsMobileId_Identity (OStream, &(*(Data->u.Identity)));
	ED_Dump_Union_End (OStream, "epsMobileId", "Identity");
			break;
		}
	case U_c_epsMobileId_TMGI: {
		ED_Dump_Union_Begin (OStream, "epsMobileId", "TMGI");
		  /* STRUCTURAL=<0> TYPE=<c_epsMobileId_TMGI> NAME=<TMGI> ACCESS=<*(Data->u.TMGI)>  OPTIONAL=<0> FUNC=<Dump_c_epsMobileId_TMGI> */
		  Dump_c_epsMobileId_TMGI (OStream, &(*(Data->u.TMGI)));
	ED_Dump_Union_End (OStream, "epsMobileId", "TMGI");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_COMPLETE (TEDOStream* OStream, const c_ATTACH_COMPLETE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_COMPLETE");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_COMPLETE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_COMPLETE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_COMPLETE", "ESMMessageContainer");
	  /* STRUCTURAL=<0> TYPE=<c_ESMMessageUp> NAME=<ESMMessageContainer> ACCESS=<Data->ESMMessageContainer>  OPTIONAL=<0> FUNC=<Dump_c_ESMMessageUp> */
	  Dump_c_ESMMessageUp (OStream, &(Data->ESMMessageContainer));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_COMPLETE", "ESMMessageContainer");
	ED_Dump_Struct_End (OStream, "ATTACH_COMPLETE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_REQUEST (TEDOStream* OStream, const c_ATTACH_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "EPSAttachType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSAttachType> ACCESS=<Data->EPSAttachType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EPSAttachType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "EPS attach"); break;
				case 2: OStream->WriteString (OStream, "combined EPS/IMSI attach"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "EPSAttachType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "EPSMobileIdentity");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<EPSMobileIdentity> ACCESS=<Data->EPSMobileIdentity>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(Data->EPSMobileIdentity));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "EPSMobileIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "UENetworkCapability");
	  /* STRUCTURAL=<0> TYPE=<c_UENetworkCapability> NAME=<UENetworkCapability> ACCESS=<Data->UENetworkCapability>  OPTIONAL=<0> FUNC=<Dump_c_UENetworkCapability> */
	  Dump_c_UENetworkCapability (OStream, &(Data->UENetworkCapability));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "UENetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "ESMMessageContainer");
	  /* STRUCTURAL=<0> TYPE=<c_ESMMessageUp> NAME=<ESMMessageContainer> ACCESS=<Data->ESMMessageContainer>  OPTIONAL=<0> FUNC=<Dump_c_ESMMessageUp> */
	  Dump_c_ESMMessageUp (OStream, &(Data->ESMMessageContainer));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "ESMMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "OldPTMSISignature");
	if (!Data->OldPTMSISignature_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldPTMSISignature> ACCESS=<Data->OldPTMSISignature>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldPTMSISignature, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "OldPTMSISignature");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "AdditionalGUTI");
	if (!Data->AdditionalGUTI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<AdditionalGUTI> ACCESS=<*(Data->AdditionalGUTI)>  OPTIONAL=<1> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(*(Data->AdditionalGUTI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "AdditionalGUTI");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "LastVisitedRegisteredTAI");
	if (!Data->LastVisitedRegisteredTAI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrackingAreaIdentity> NAME=<LastVisitedRegisteredTAI> ACCESS=<*(Data->LastVisitedRegisteredTAI)>  OPTIONAL=<1> FUNC=<Dump_c_TrackingAreaIdentity> */
	  Dump_c_TrackingAreaIdentity (OStream, &(*(Data->LastVisitedRegisteredTAI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "LastVisitedRegisteredTAI");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "DRXParameter");
	if (!Data->DRXParameter_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDrxParam> NAME=<DRXParameter> ACCESS=<*(Data->DRXParameter)>  OPTIONAL=<1> FUNC=<Dump_c_epsDrxParam> */
	  Dump_c_epsDrxParam (OStream, &(*(Data->DRXParameter)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "DRXParameter");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "MSNetworkCapability");
	if (!Data->MSNetworkCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMsNetwkCpblty> NAME=<MSNetworkCapability> ACCESS=<*(Data->MSNetworkCapability)>  OPTIONAL=<1> FUNC=<Dump_c_epsMsNetwkCpblty> */
	  Dump_c_epsMsNetwkCpblty (OStream, &(*(Data->MSNetworkCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "MSNetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "OldLocationAreaIdentification");
	if (!Data->OldLocationAreaIdentification_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLocationAreaId> NAME=<OldLocationAreaIdentification> ACCESS=<*(Data->OldLocationAreaIdentification)>  OPTIONAL=<1> FUNC=<Dump_c_epsLocationAreaId> */
	  Dump_c_epsLocationAreaId (OStream, &(*(Data->OldLocationAreaIdentification)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "OldLocationAreaIdentification");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "TMSIStatus");
	if (!Data->TMSIStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsTmsiStatus> NAME=<TMSIStatus> ACCESS=<*(Data->TMSIStatus)>  OPTIONAL=<1> FUNC=<Dump_c_epsTmsiStatus> */
	  Dump_c_epsTmsiStatus (OStream, &(*(Data->TMSIStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "TMSIStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "epsMobileStationClassmark2");
	if (!Data->epsMobileStationClassmark2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileStationClassmark2> NAME=<epsMobileStationClassmark2> ACCESS=<*(Data->epsMobileStationClassmark2)>  OPTIONAL=<1> FUNC=<Dump_c_epsMobileStationClassmark2> */
	  Dump_c_epsMobileStationClassmark2 (OStream, &(*(Data->epsMobileStationClassmark2)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "epsMobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "MobileStationClassmark3");
	if (!Data->MobileStationClassmark3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsClassmark3Value> NAME=<MobileStationClassmark3> ACCESS=<*(Data->MobileStationClassmark3)>  OPTIONAL=<1> FUNC=<Dump_c_epsClassmark3Value> */
	  Dump_c_epsClassmark3Value (OStream, &(*(Data->MobileStationClassmark3)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "MobileStationClassmark3");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsSupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_epsSupportedCodecList> */
	  Dump_c_epsSupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "AdditionalUpdateType");
	if (!Data->AdditionalUpdateType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsAdditionalUpdateType> NAME=<AdditionalUpdateType> ACCESS=<*(Data->AdditionalUpdateType)>  OPTIONAL=<1> FUNC=<Dump_c_epsAdditionalUpdateType> */
	  Dump_c_epsAdditionalUpdateType (OStream, &(*(Data->AdditionalUpdateType)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "AdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "VoiceDomainPref");
	if (!Data->VoiceDomainPref_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsVoiceDomainPreferenceAndUEsUsageSetting> NAME=<VoiceDomainPref> ACCESS=<*(Data->VoiceDomainPref)>  OPTIONAL=<1> FUNC=<Dump_c_epsVoiceDomainPreferenceAndUEsUsageSetting> */
	  Dump_c_epsVoiceDomainPreferenceAndUEsUsageSetting (OStream, &(*(Data->VoiceDomainPref)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "VoiceDomainPref");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "OldGUTIType");
	if (!Data->OldGUTIType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GUTIType> NAME=<OldGUTIType> ACCESS=<*(Data->OldGUTIType)>  OPTIONAL=<1> FUNC=<Dump_c_GUTIType> */
	  Dump_c_GUTIType (OStream, &(*(Data->OldGUTIType)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "OldGUTIType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "MSNetworkFeatureSupport");
	if (!Data->MSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMSNetworkFeatureSupport> NAME=<MSNetworkFeatureSupport> ACCESS=<*(Data->MSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_epsMSNetworkFeatureSupport> */
	  Dump_c_epsMSNetworkFeatureSupport (OStream, &(*(Data->MSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "MSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "TMSIBasedNRIContainer");
	if (!Data->TMSIBasedNRIContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsNetworkResourceIdentifierContainer> NAME=<TMSIBasedNRIContainer> ACCESS=<*(Data->TMSIBasedNRIContainer)>  OPTIONAL=<1> FUNC=<Dump_c_epsNetworkResourceIdentifierContainer> */
	  Dump_c_epsNetworkResourceIdentifierContainer (OStream, &(*(Data->TMSIBasedNRIContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "TMSIBasedNRIContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "T3324ValueGPRSTimer2");
	if (!Data->T3324ValueGPRSTimer2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3324ValueGPRSTimer2> ACCESS=<*(Data->T3324ValueGPRSTimer2)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3324ValueGPRSTimer2)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "T3324ValueGPRSTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "T3412ExtendedValue");
	if (!Data->T3412ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412ExtendedValue> ACCESS=<*(Data->T3412ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3412ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "T3412ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_epsExtendedDRXParameters> */
	  Dump_c_epsExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ATTACH_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_FAILURE (TEDOStream* OStream, const c_AUTHENTICATION_FAILURE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_FAILURE");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_FAILURE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_FAILURE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_FAILURE", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_FAILURE", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_FAILURE", "AuthenticationFailureParameter");
	if (!Data->AuthenticationFailureParameter_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthenticationFailureParameter> ACCESS=<Data->AuthenticationFailureParameter>  MAXBITSIZE=<112> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthenticationFailureParameter, 112);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_FAILURE", "AuthenticationFailureParameter");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_FAILURE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_RESPONSE (TEDOStream* OStream, const c_AUTHENTICATION_RESPONSE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_RESPONSE");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_RESPONSE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_RESPONSE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_RESPONSE", "AuthenticationResponseParameter");
	  /* NAME=<AuthenticationResponseParameter> ACCESS=<Data->AuthenticationResponseParameter>  MAXBITSIZE=<128> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AuthenticationResponseParameter.value, Data->AuthenticationResponseParameter.usedBits);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_RESPONSE", "AuthenticationResponseParameter");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_RESPONSE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_DETACH_ACCEPT_UP (TEDOStream* OStream, const c_EPS_DETACH_ACCEPT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_DETACH_ACCEPT_UP");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_ACCEPT_UP", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_ACCEPT_UP", "SecurityHeaderType");
	ED_Dump_Struct_End (OStream, "EPS_DETACH_ACCEPT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_DETACH_REQUEST_UP (TEDOStream* OStream, const c_EPS_DETACH_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_DETACH_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_UP", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_UP", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_UP", "DetachType");
	  /* STRUCTURAL=<0> TYPE=<c_EPSDetachType> NAME=<DetachType> ACCESS=<Data->DetachType>  OPTIONAL=<0> FUNC=<Dump_c_EPSDetachType> */
	  Dump_c_EPSDetachType (OStream, &(Data->DetachType));
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_UP", "DetachType");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_UP", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_UP", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_UP", "EPSMobileIdentity");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<EPSMobileIdentity> ACCESS=<Data->EPSMobileIdentity>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(Data->EPSMobileIdentity));
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_UP", "EPSMobileIdentity");
	ED_Dump_Struct_End (OStream, "EPS_DETACH_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EMM_STATUS (TEDOStream* OStream, const c_EMM_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EMM_STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_STATUS", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EMM_STATUS", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_STATUS", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "EMM_STATUS", "EMMCause");
	ED_Dump_Struct_End (OStream, "EMM_STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EXTENDED_SERVICE_REQUEST (TEDOStream* OStream, const c_EXTENDED_SERVICE_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EXTENDED_SERVICE_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "ServiceType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ServiceType> ACCESS=<Data->ServiceType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ServiceType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "mobile originating CS fallback"); break;
				case 1: OStream->WriteString (OStream, "mobile terminating CS fallback"); break;
				case 2: OStream->WriteString (OStream, "mobile originating CS fallback emergency call"); break;
				case 3: OStream->WriteString (OStream, "unused; shall be interpreted as 'mobile originating CS fallback or 1xCS fallback', if received by the network"); break;
				case 4: OStream->WriteString (OStream, "unused; shall be interpreted as 'mobile originating CS fallback or 1xCS fallback', if received by the network"); break;
				case 8: OStream->WriteString (OStream, "packet services via S1"); break;
				case 9: OStream->WriteString (OStream, "unused; shall be interpreted as 'packet services via S1', if received by the network"); break;
				case 10: OStream->WriteString (OStream, "unused; shall be interpreted as 'packet services via S1', if received by the network"); break;
				case 11: OStream->WriteString (OStream, "unused; shall be interpreted as 'packet services via S1', if received by the network"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "ServiceType");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "MTMSI");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId> NAME=<MTMSI> ACCESS=<Data->MTMSI>  OPTIONAL=<0> FUNC=<Dump_c_epsMobileId> */
	  Dump_c_epsMobileId (OStream, &(Data->MTMSI));
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "MTMSI");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "CSFBResponse");
	if (!Data->CSFBResponse_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CSFBResponse> ACCESS=<Data->CSFBResponse>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CSFBResponse)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "CS fallback rejected by the UE"); break;
				case 1: OStream->WriteString (OStream, "CS fallback accepted by the UE"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "CSFBResponse");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "EPSBearerContextStatus");
	if (!Data->EPSBearerContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus> NAME=<EPSBearerContextStatus> ACCESS=<*(Data->EPSBearerContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_EPSBearerContextStatus> */
	  Dump_c_EPSBearerContextStatus (OStream, &(*(Data->EPSBearerContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "EPSBearerContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "EXTENDED_SERVICE_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "EXTENDED_SERVICE_REQUEST", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "EXTENDED_SERVICE_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GUTI_REALLOCATION_COMPLETE (TEDOStream* OStream, const c_GUTI_REALLOCATION_COMPLETE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GUTI_REALLOCATION_COMPLETE");
	ED_Dump_Struct_Begin_Field (OStream, "GUTI_REALLOCATION_COMPLETE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "GUTI_REALLOCATION_COMPLETE", "SecurityHeaderType");
	ED_Dump_Struct_End (OStream, "GUTI_REALLOCATION_COMPLETE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_RESPONSE (TEDOStream* OStream, const c_IDENTITY_RESPONSE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_RESPONSE");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE", "MobileIdentity");
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId> NAME=<MobileIdentity> ACCESS=<Data->MobileIdentity>  OPTIONAL=<0> FUNC=<Dump_c_epsMobileId> */
	  Dump_c_epsMobileId (OStream, &(Data->MobileIdentity));
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE", "MobileIdentity");
	ED_Dump_Struct_End (OStream, "IDENTITY_RESPONSE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SECURITY_MODE_COMPLETE (TEDOStream* OStream, const c_SECURITY_MODE_COMPLETE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SECURITY_MODE_COMPLETE");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMPLETE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMPLETE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMPLETE", "IMEISV");
	if (!Data->IMEISV_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId> NAME=<IMEISV> ACCESS=<*(Data->IMEISV)>  OPTIONAL=<1> FUNC=<Dump_c_epsMobileId> */
	  Dump_c_epsMobileId (OStream, &(*(Data->IMEISV)));
	}
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMPLETE", "IMEISV");
	ED_Dump_Struct_End (OStream, "SECURITY_MODE_COMPLETE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SECURITY_MODE_REJECT (TEDOStream* OStream, const c_SECURITY_MODE_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SECURITY_MODE_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_REJECT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_REJECT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_REJECT", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_REJECT", "EMMCause");
	ED_Dump_Struct_End (OStream, "SECURITY_MODE_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SECURITY_PROTECTED_NAS_MESSAGE (TEDOStream* OStream, const c_SECURITY_PROTECTED_NAS_MESSAGE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SECURITY_PROTECTED_NAS_MESSAGE");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "MessageAuthenticationCode");
	  /* NAME=<MessageAuthenticationCode> ACCESS=<Data->MessageAuthenticationCode>  MAXBITSIZE=<32> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->MessageAuthenticationCode, 32);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "MessageAuthenticationCode");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "SequenceNumber");
	  /* NAME=<SequenceNumber> ACCESS=<Data->SequenceNumber>  MAXBITSIZE=<8> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->SequenceNumber, 8);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "SequenceNumber");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "NASMessage");
	  /* NAME=<NASMessage> ACCESS=<Data->NASMessage>  MAXBITSIZE=<4800> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->NASMessage.value, Data->NASMessage.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_PROTECTED_NAS_MESSAGE", "NASMessage");
	ED_Dump_Struct_End (OStream, "SECURITY_PROTECTED_NAS_MESSAGE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_REQUEST (TEDOStream* OStream, const c_SERVICE_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST", "KSIAndSequenceNumber");
	  /* STRUCTURAL=<0> TYPE=<c_KSIAndSequenceNumber> NAME=<KSIAndSequenceNumber> ACCESS=<Data->KSIAndSequenceNumber>  OPTIONAL=<0> FUNC=<Dump_c_KSIAndSequenceNumber> */
	  Dump_c_KSIAndSequenceNumber (OStream, &(Data->KSIAndSequenceNumber));
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST", "KSIAndSequenceNumber");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST", "MessageAuthenticationCodeShort");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<MessageAuthenticationCodeShort> ACCESS=<Data->MessageAuthenticationCodeShort>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MessageAuthenticationCodeShort);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST", "MessageAuthenticationCodeShort");
	ED_Dump_Struct_End (OStream, "SERVICE_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRACKING_AREA_UPDATE_COMPLETE (TEDOStream* OStream, const c_TRACKING_AREA_UPDATE_COMPLETE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRACKING_AREA_UPDATE_COMPLETE");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_COMPLETE", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_COMPLETE", "SecurityHeaderType");
	ED_Dump_Struct_End (OStream, "TRACKING_AREA_UPDATE_COMPLETE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRACKING_AREA_UPDATE_REQUEST (TEDOStream* OStream, const c_TRACKING_AREA_UPDATE_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRACKING_AREA_UPDATE_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "EPSUpdateType");
	  /* STRUCTURAL=<0> TYPE=<c_EPSUpdateType> NAME=<EPSUpdateType> ACCESS=<Data->EPSUpdateType>  OPTIONAL=<0> FUNC=<Dump_c_EPSUpdateType> */
	  Dump_c_EPSUpdateType (OStream, &(Data->EPSUpdateType));
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "EPSUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldGUTI");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<OldGUTI> ACCESS=<Data->OldGUTI>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(Data->OldGUTI));
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldGUTI");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NonCurrentNativeNASKeySetId");
	if (!Data->NonCurrentNativeNASKeySetId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NonCurrentNativeNASKeySetId> ACCESS=<*(Data->NonCurrentNativeNASKeySetId)>  OPTIONAL=<1> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(*(Data->NonCurrentNativeNASKeySetId)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NonCurrentNativeNASKeySetId");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "GPRSCipheringKeySequenceNumber");
	if (!Data->GPRSCipheringKeySequenceNumber_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GPRSCipheringKeySequenceNumber> ACCESS=<Data->GPRSCipheringKeySequenceNumber>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GPRSCipheringKeySequenceNumber);
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "GPRSCipheringKeySequenceNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldPTMSISignature");
	if (!Data->OldPTMSISignature_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldPTMSISignature> ACCESS=<Data->OldPTMSISignature>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldPTMSISignature, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldPTMSISignature");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "AdditionalGUTI");
	if (!Data->AdditionalGUTI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<AdditionalGUTI> ACCESS=<*(Data->AdditionalGUTI)>  OPTIONAL=<1> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(*(Data->AdditionalGUTI)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "AdditionalGUTI");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NonceUE");
	if (!Data->NonceUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<NonceUE> ACCESS=<Data->NonceUE>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NonceUE);
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "NonceUE");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "UENetworkCapability");
	if (!Data->UENetworkCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_UENetworkCapability> NAME=<UENetworkCapability> ACCESS=<*(Data->UENetworkCapability)>  OPTIONAL=<1> FUNC=<Dump_c_UENetworkCapability> */
	  Dump_c_UENetworkCapability (OStream, &(*(Data->UENetworkCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "UENetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "LastVisitedRegisteredTAI");
	if (!Data->LastVisitedRegisteredTAI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrackingAreaIdentity> NAME=<LastVisitedRegisteredTAI> ACCESS=<*(Data->LastVisitedRegisteredTAI)>  OPTIONAL=<1> FUNC=<Dump_c_TrackingAreaIdentity> */
	  Dump_c_TrackingAreaIdentity (OStream, &(*(Data->LastVisitedRegisteredTAI)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "LastVisitedRegisteredTAI");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "DRXParameter");
	if (!Data->DRXParameter_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDrxParam> NAME=<DRXParameter> ACCESS=<*(Data->DRXParameter)>  OPTIONAL=<1> FUNC=<Dump_c_epsDrxParam> */
	  Dump_c_epsDrxParam (OStream, &(*(Data->DRXParameter)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "DRXParameter");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "UERadioCapabilityInformationUpdateNeeded");
	if (!Data->UERadioCapabilityInformationUpdateNeeded_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UERadioCapabilityInformationUpdateNeeded> ACCESS=<Data->UERadioCapabilityInformationUpdateNeeded>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UERadioCapabilityInformationUpdateNeeded)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "UE radio capability information update not needed"); break;
				case 1: OStream->WriteString (OStream, "UE radio capability information update needed"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "UERadioCapabilityInformationUpdateNeeded");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "EPSBearerContextStatus");
	if (!Data->EPSBearerContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus> NAME=<EPSBearerContextStatus> ACCESS=<*(Data->EPSBearerContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_EPSBearerContextStatus> */
	  Dump_c_EPSBearerContextStatus (OStream, &(*(Data->EPSBearerContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "EPSBearerContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MSNetworkCapability");
	if (!Data->MSNetworkCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMsNetwkCpblty> NAME=<MSNetworkCapability> ACCESS=<*(Data->MSNetworkCapability)>  OPTIONAL=<1> FUNC=<Dump_c_epsMsNetwkCpblty> */
	  Dump_c_epsMsNetwkCpblty (OStream, &(*(Data->MSNetworkCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MSNetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldLocationAreaIdentification");
	if (!Data->OldLocationAreaIdentification_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLocationAreaId> NAME=<OldLocationAreaIdentification> ACCESS=<*(Data->OldLocationAreaIdentification)>  OPTIONAL=<1> FUNC=<Dump_c_epsLocationAreaId> */
	  Dump_c_epsLocationAreaId (OStream, &(*(Data->OldLocationAreaIdentification)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldLocationAreaIdentification");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "TMSIStatus");
	if (!Data->TMSIStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsTmsiStatus> NAME=<TMSIStatus> ACCESS=<*(Data->TMSIStatus)>  OPTIONAL=<1> FUNC=<Dump_c_epsTmsiStatus> */
	  Dump_c_epsTmsiStatus (OStream, &(*(Data->TMSIStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "TMSIStatus");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "epsMobileStationClassmark2");
	if (!Data->epsMobileStationClassmark2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileStationClassmark2> NAME=<epsMobileStationClassmark2> ACCESS=<*(Data->epsMobileStationClassmark2)>  OPTIONAL=<1> FUNC=<Dump_c_epsMobileStationClassmark2> */
	  Dump_c_epsMobileStationClassmark2 (OStream, &(*(Data->epsMobileStationClassmark2)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "epsMobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MobileStationClassmark3");
	if (!Data->MobileStationClassmark3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsClassmark3Value> NAME=<MobileStationClassmark3> ACCESS=<*(Data->MobileStationClassmark3)>  OPTIONAL=<1> FUNC=<Dump_c_epsClassmark3Value> */
	  Dump_c_epsClassmark3Value (OStream, &(*(Data->MobileStationClassmark3)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MobileStationClassmark3");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsSupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_epsSupportedCodecList> */
	  Dump_c_epsSupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "AdditionalUpdateType");
	if (!Data->AdditionalUpdateType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsAdditionalUpdateType> NAME=<AdditionalUpdateType> ACCESS=<*(Data->AdditionalUpdateType)>  OPTIONAL=<1> FUNC=<Dump_c_epsAdditionalUpdateType> */
	  Dump_c_epsAdditionalUpdateType (OStream, &(*(Data->AdditionalUpdateType)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "AdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "VoiceDomainPref");
	if (!Data->VoiceDomainPref_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsVoiceDomainPreferenceAndUEsUsageSetting> NAME=<VoiceDomainPref> ACCESS=<*(Data->VoiceDomainPref)>  OPTIONAL=<1> FUNC=<Dump_c_epsVoiceDomainPreferenceAndUEsUsageSetting> */
	  Dump_c_epsVoiceDomainPreferenceAndUEsUsageSetting (OStream, &(*(Data->VoiceDomainPref)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "VoiceDomainPref");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldGUTIType");
	if (!Data->OldGUTIType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GUTIType> NAME=<OldGUTIType> ACCESS=<*(Data->OldGUTIType)>  OPTIONAL=<1> FUNC=<Dump_c_GUTIType> */
	  Dump_c_GUTIType (OStream, &(*(Data->OldGUTIType)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "OldGUTIType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MSNetworkFeatureSupport");
	if (!Data->MSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMSNetworkFeatureSupport> NAME=<MSNetworkFeatureSupport> ACCESS=<*(Data->MSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_epsMSNetworkFeatureSupport> */
	  Dump_c_epsMSNetworkFeatureSupport (OStream, &(*(Data->MSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "MSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "TMSIBasedNRIContainer");
	if (!Data->TMSIBasedNRIContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsNetworkResourceIdentifierContainer> NAME=<TMSIBasedNRIContainer> ACCESS=<*(Data->TMSIBasedNRIContainer)>  OPTIONAL=<1> FUNC=<Dump_c_epsNetworkResourceIdentifierContainer> */
	  Dump_c_epsNetworkResourceIdentifierContainer (OStream, &(*(Data->TMSIBasedNRIContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "TMSIBasedNRIContainer");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "T3324ValueGPRSTimer2");
	if (!Data->T3324ValueGPRSTimer2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3324ValueGPRSTimer2> ACCESS=<*(Data->T3324ValueGPRSTimer2)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3324ValueGPRSTimer2)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "T3324ValueGPRSTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "T3412ExtendedValue");
	if (!Data->T3412ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412ExtendedValue> ACCESS=<*(Data->T3412ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3412ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "T3412ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_epsExtendedDRXParameters> */
	  Dump_c_epsExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REQUEST", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "TRACKING_AREA_UPDATE_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UPLINK_NAS_TRANSPORT (TEDOStream* OStream, const c_UPLINK_NAS_TRANSPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UPLINK_NAS_TRANSPORT");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_NAS_TRANSPORT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "UPLINK_NAS_TRANSPORT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_NAS_TRANSPORT", "NASMessageContainer");
	  /* NAME=<NASMessageContainer> ACCESS=<Data->NASMessageContainer>  MAXBITSIZE=<2008> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->NASMessageContainer.value, Data->NASMessageContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "UPLINK_NAS_TRANSPORT", "NASMessageContainer");
	ED_Dump_Struct_End (OStream, "UPLINK_NAS_TRANSPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UPLINK_GENERIC_NAS_TRANSPORT (TEDOStream* OStream, const c_UPLINK_GENERIC_NAS_TRANSPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UPLINK_GENERIC_NAS_TRANSPORT");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "NASMessageContainer");
	  /* NAME=<NASMessageContainer> ACCESS=<Data->NASMessageContainer>  MAXBITSIZE=<2008> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->NASMessageContainer.value, Data->NASMessageContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "NASMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainerType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GenericMessageContainerType> ACCESS=<Data->GenericMessageContainerType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->GenericMessageContainerType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "LTE Positioning Protocol (LPP) message container"); break;
				case 2: OStream->WriteString (OStream, "Location services message container"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainerType");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainer");
	  /* NAME=<GenericMessageContainer> ACCESS=<Data->GenericMessageContainer>  MAXBITSIZE=<4784> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->GenericMessageContainer.value, Data->GenericMessageContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "AdditionalInformation");
	if (!Data->AdditionalInformation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AdditionalInformation> ACCESS=<*(Data->AdditionalInformation)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AdditionalInformation->value, Data->AdditionalInformation->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "UPLINK_GENERIC_NAS_TRANSPORT", "AdditionalInformation");
	ED_Dump_Struct_End (OStream, "UPLINK_GENERIC_NAS_TRANSPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CONTROL_PLANE_SERVICE_REQUEST (TEDOStream* OStream, const c_CONTROL_PLANE_SERVICE_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CONTROL_PLANE_SERVICE_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "DataServiceType");
	  /* STRUCTURAL=<0> TYPE=<c_DataServiceType> NAME=<DataServiceType> ACCESS=<Data->DataServiceType>  OPTIONAL=<0> FUNC=<Dump_c_DataServiceType> */
	  Dump_c_DataServiceType (OStream, &(Data->DataServiceType));
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "DataServiceType");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "ESMMessageContainer");
	if (!Data->ESMMessageContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ESMMessageUp> NAME=<ESMMessageContainer> ACCESS=<*(Data->ESMMessageContainer)>  OPTIONAL=<1> FUNC=<Dump_c_ESMMessageUp> */
	  Dump_c_ESMMessageUp (OStream, &(*(Data->ESMMessageContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "ESMMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "NASMessageContainer");
	if (!Data->NASMessageContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NASMessageContainer> ACCESS=<*(Data->NASMessageContainer)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NASMessageContainer->value, Data->NASMessageContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "NASMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "EPSBearerContextStatus");
	if (!Data->EPSBearerContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus> NAME=<EPSBearerContextStatus> ACCESS=<*(Data->EPSBearerContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_EPSBearerContextStatus> */
	  Dump_c_EPSBearerContextStatus (OStream, &(*(Data->EPSBearerContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "EPSBearerContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_epsDeviceProperties> */
	  Dump_c_epsDeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONTROL_PLANE_SERVICE_REQUEST", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "CONTROL_PLANE_SERVICE_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_ACCEPT (TEDOStream* OStream, const c_ATTACH_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "EPSAttachResult");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSAttachResult> ACCESS=<Data->EPSAttachResult>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EPSAttachResult)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "EPS only"); break;
				case 2: OStream->WriteString (OStream, "combined EPS/IMSI attach"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "EPSAttachResult");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_ATTACH_ACCEPT_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "T3412Value");
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412Value> ACCESS=<Data->T3412Value>  OPTIONAL=<0> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(Data->T3412Value));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "T3412Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "TAIList");
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList> NAME=<TAIList> ACCESS=<Data->TAIList>  OPTIONAL=<0> FUNC=<Dump_c_PartialTrackingAreaIdentityList> */
	  Dump_c_PartialTrackingAreaIdentityList (OStream, &(Data->TAIList));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "TAIList");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "ESMMessageContainer");
	  /* STRUCTURAL=<0> TYPE=<c_ESMMessageDn> NAME=<ESMMessageContainer> ACCESS=<Data->ESMMessageContainer>  OPTIONAL=<0> FUNC=<Dump_c_ESMMessageDn> */
	  Dump_c_ESMMessageDn (OStream, &(Data->ESMMessageContainer));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "ESMMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "GUTI");
	if (!Data->GUTI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<GUTI> ACCESS=<*(Data->GUTI)>  OPTIONAL=<1> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(*(Data->GUTI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "GUTI");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "LocationAreaIdentification");
	if (!Data->LocationAreaIdentification_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLocationAreaId> NAME=<LocationAreaIdentification> ACCESS=<*(Data->LocationAreaIdentification)>  OPTIONAL=<1> FUNC=<Dump_c_epsLocationAreaId> */
	  Dump_c_epsLocationAreaId (OStream, &(*(Data->LocationAreaIdentification)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "LocationAreaIdentification");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "MSIdentity");
	if (!Data->MSIdentity_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId> NAME=<MSIdentity> ACCESS=<*(Data->MSIdentity)>  OPTIONAL=<1> FUNC=<Dump_c_epsMobileId> */
	  Dump_c_epsMobileId (OStream, &(*(Data->MSIdentity)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "MSIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "EMMCause");
	if (!Data->EMMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "T3402Value");
	if (!Data->T3402Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3402Value> ACCESS=<*(Data->T3402Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3402Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "T3402Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "T3423Value");
	if (!Data->T3423Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3423Value> ACCESS=<*(Data->T3423Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3423Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "T3423Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "EquivalentPLMNs");
	if (!Data->EquivalentPLMNs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsPlmnList> NAME=<EquivalentPLMNs> ACCESS=<*(Data->EquivalentPLMNs)>  OPTIONAL=<1> FUNC=<Dump_c_epsPlmnList> */
	  Dump_c_epsPlmnList (OStream, &(*(Data->EquivalentPLMNs)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "EquivalentPLMNs");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "epsEmergencyNumberList");
	if (!Data->epsEmergencyNumberList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsEmergencyNumberList> NAME=<epsEmergencyNumberList> ACCESS=<*(Data->epsEmergencyNumberList)>  OPTIONAL=<1> FUNC=<Dump_c_epsEmergencyNumberList> */
	  Dump_c_epsEmergencyNumberList (OStream, &(*(Data->epsEmergencyNumberList)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "epsEmergencyNumberList");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "EPSNetworkFeatureSupport");
	if (!Data->EPSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSNetworkFeatureSupport> NAME=<EPSNetworkFeatureSupport> ACCESS=<*(Data->EPSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_EPSNetworkFeatureSupport> */
	  Dump_c_EPSNetworkFeatureSupport (OStream, &(*(Data->EPSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "EPSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "AdditionalUpdateResult");
	if (!Data->AdditionalUpdateResult_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateResult> NAME=<AdditionalUpdateResult> ACCESS=<*(Data->AdditionalUpdateResult)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateResult> */
	  Dump_c_AdditionalUpdateResult (OStream, &(*(Data->AdditionalUpdateResult)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "AdditionalUpdateResult");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "T3412ExtendedValue");
	if (!Data->T3412ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412ExtendedValue> ACCESS=<*(Data->T3412ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3412ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "T3412ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "T3324ValueGPRSTimer2");
	if (!Data->T3324ValueGPRSTimer2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3324ValueGPRSTimer2> ACCESS=<*(Data->T3324ValueGPRSTimer2)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3324ValueGPRSTimer2)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "T3324ValueGPRSTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_epsExtendedDRXParameters> */
	  Dump_c_epsExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ATTACH_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_REJECT (TEDOStream* OStream, const c_ATTACH_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "ESMMessageContainer");
	if (!Data->ESMMessageContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ESMMessageDn> NAME=<ESMMessageContainer> ACCESS=<*(Data->ESMMessageContainer)>  OPTIONAL=<1> FUNC=<Dump_c_ESMMessageDn> */
	  Dump_c_ESMMessageDn (OStream, &(*(Data->ESMMessageContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "ESMMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "T3346Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "T3402Value");
	if (!Data->T3402Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3402Value> ACCESS=<*(Data->T3402Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3402Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "T3402Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT", "ExtendedEMMCause");
	if (!Data->ExtendedEMMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedEMMCause> NAME=<ExtendedEMMCause> ACCESS=<*(Data->ExtendedEMMCause)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedEMMCause> */
	  Dump_c_ExtendedEMMCause (OStream, &(*(Data->ExtendedEMMCause)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT", "ExtendedEMMCause");
	ED_Dump_Struct_End (OStream, "ATTACH_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_REJECT (TEDOStream* OStream, const c_AUTHENTICATION_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REJECT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REJECT", "SecurityHeaderType");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_REQUEST (TEDOStream* OStream, const c_AUTHENTICATION_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST", "NASKeySetIdentifierASME");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifierASME> ACCESS=<Data->NASKeySetIdentifierASME>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifierASME));
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST", "NASKeySetIdentifierASME");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_AUTHENTICATION_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST", "AuthenticationParameterRANDEPSChallenge");
	  /* NAME=<AuthenticationParameterRANDEPSChallenge> ACCESS=<Data->AuthenticationParameterRANDEPSChallenge>  MAXBITSIZE=<128> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AuthenticationParameterRANDEPSChallenge, 128);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST", "AuthenticationParameterRANDEPSChallenge");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST", "AuthenticationParameterAUTNEPSChallenge");
	  /* NAME=<AuthenticationParameterAUTNEPSChallenge> ACCESS=<Data->AuthenticationParameterAUTNEPSChallenge>  MAXBITSIZE=<128> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AuthenticationParameterAUTNEPSChallenge, 128);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST", "AuthenticationParameterAUTNEPSChallenge");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CS_SERVICE_NOTIFICATION (TEDOStream* OStream, const c_CS_SERVICE_NOTIFICATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CS_SERVICE_NOTIFICATION");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "PagingIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PagingIdentity> ACCESS=<Data->PagingIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PagingIdentity)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "IMSI"); break;
				case 1: OStream->WriteString (OStream, "TMSI"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "PagingIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "CLI");
	if (!Data->CLI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsCallingPartyBcdNum> NAME=<CLI> ACCESS=<*(Data->CLI)>  OPTIONAL=<1> FUNC=<Dump_c_epsCallingPartyBcdNum> */
	  Dump_c_epsCallingPartyBcdNum (OStream, &(*(Data->CLI)));
	}
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "CLI");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "SSCode");
	if (!Data->SSCode_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SSCode> ACCESS=<Data->SSCode>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SSCode);
	}
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "SSCode");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "LCSIndicator");
	if (!Data->LCSIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LCSIndicator> ACCESS=<Data->LCSIndicator>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->LCSIndicator);
	}
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "LCSIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "CS_SERVICE_NOTIFICATION", "LCSClientId");
	if (!Data->LCSClientId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LCSClientId> ACCESS=<*(Data->LCSClientId)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LCSClientId->value, Data->LCSClientId->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CS_SERVICE_NOTIFICATION", "LCSClientId");
	ED_Dump_Struct_End (OStream, "CS_SERVICE_NOTIFICATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_DETACH_ACCEPT_DN (TEDOStream* OStream, const c_EPS_DETACH_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_DETACH_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_ACCEPT_DN", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_ACCEPT_DN", "SecurityHeaderType");
	ED_Dump_Struct_End (OStream, "EPS_DETACH_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EPS_DETACH_REQUEST_DN (TEDOStream* OStream, const c_EPS_DETACH_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EPS_DETACH_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_DN", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_DN", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_DN", "DetachType");
	  /* STRUCTURAL=<0> TYPE=<c_EPSDetachType> NAME=<DetachType> ACCESS=<Data->DetachType>  OPTIONAL=<0> FUNC=<Dump_c_EPSDetachType> */
	  Dump_c_EPSDetachType (OStream, &(Data->DetachType));
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_DN", "DetachType");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_EPS_DETACH_REQUEST_DN_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "EPS_DETACH_REQUEST_DN", "EMMCause");
	if (!Data->EMMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	}
	ED_Dump_Struct_End_Field (OStream, "EPS_DETACH_REQUEST_DN", "EMMCause");
	ED_Dump_Struct_End (OStream, "EPS_DETACH_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DOWNLINK_NAS_TRANSPORT (TEDOStream* OStream, const c_DOWNLINK_NAS_TRANSPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DOWNLINK_NAS_TRANSPORT");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_NAS_TRANSPORT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_NAS_TRANSPORT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_NAS_TRANSPORT", "NASMessageContainer");
	  /* NAME=<NASMessageContainer> ACCESS=<Data->NASMessageContainer>  MAXBITSIZE=<2008> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->NASMessageContainer.value, Data->NASMessageContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_NAS_TRANSPORT", "NASMessageContainer");
	ED_Dump_Struct_End (OStream, "DOWNLINK_NAS_TRANSPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EMM_INFORMATION (TEDOStream* OStream, const c_EMM_INFORMATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EMM_INFORMATION");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "FullNameForNetwork");
	if (!Data->FullNameForNetwork_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsNetwkName> NAME=<FullNameForNetwork> ACCESS=<*(Data->FullNameForNetwork)>  OPTIONAL=<1> FUNC=<Dump_c_epsNetwkName> */
	  Dump_c_epsNetwkName (OStream, &(*(Data->FullNameForNetwork)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "FullNameForNetwork");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "ShortNameForNetwork");
	if (!Data->ShortNameForNetwork_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsNetwkName> NAME=<ShortNameForNetwork> ACCESS=<*(Data->ShortNameForNetwork)>  OPTIONAL=<1> FUNC=<Dump_c_epsNetwkName> */
	  Dump_c_epsNetwkName (OStream, &(*(Data->ShortNameForNetwork)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "ShortNameForNetwork");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "LocalTimeZone");
	if (!Data->LocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LocalTimeZone> ACCESS=<Data->LocalTimeZone>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LocalTimeZone);
	}
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "LocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "UniversalTimeAndLocalTimeZone");
	if (!Data->UniversalTimeAndLocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsTimeZoneAndTime> NAME=<UniversalTimeAndLocalTimeZone> ACCESS=<*(Data->UniversalTimeAndLocalTimeZone)>  OPTIONAL=<1> FUNC=<Dump_c_epsTimeZoneAndTime> */
	  Dump_c_epsTimeZoneAndTime (OStream, &(*(Data->UniversalTimeAndLocalTimeZone)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "UniversalTimeAndLocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "EMM_INFORMATION", "NetworkDaylightSavingTime");
	if (!Data->NetworkDaylightSavingTime_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsDaylightSavingTime> NAME=<NetworkDaylightSavingTime> ACCESS=<*(Data->NetworkDaylightSavingTime)>  OPTIONAL=<1> FUNC=<Dump_c_epsDaylightSavingTime> */
	  Dump_c_epsDaylightSavingTime (OStream, &(*(Data->NetworkDaylightSavingTime)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMM_INFORMATION", "NetworkDaylightSavingTime");
	ED_Dump_Struct_End (OStream, "EMM_INFORMATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GUTI_REALLOCATION_COMMAND (TEDOStream* OStream, const c_GUTI_REALLOCATION_COMMAND* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GUTI_REALLOCATION_COMMAND");
	ED_Dump_Struct_Begin_Field (OStream, "GUTI_REALLOCATION_COMMAND", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "GUTI_REALLOCATION_COMMAND", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "GUTI_REALLOCATION_COMMAND", "GUTI");
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<GUTI> ACCESS=<Data->GUTI>  OPTIONAL=<0> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(Data->GUTI));
	ED_Dump_Struct_End_Field (OStream, "GUTI_REALLOCATION_COMMAND", "GUTI");
	ED_Dump_Struct_Begin_Field (OStream, "GUTI_REALLOCATION_COMMAND", "TAIList");
	if (!Data->TAIList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList> NAME=<TAIList> ACCESS=<*(Data->TAIList)>  OPTIONAL=<1> FUNC=<Dump_c_PartialTrackingAreaIdentityList> */
	  Dump_c_PartialTrackingAreaIdentityList (OStream, &(*(Data->TAIList)));
	}
	ED_Dump_Struct_End_Field (OStream, "GUTI_REALLOCATION_COMMAND", "TAIList");
	ED_Dump_Struct_End (OStream, "GUTI_REALLOCATION_COMMAND");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_REQUEST (TEDOStream* OStream, const c_IDENTITY_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST", "IdentityType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IdentityType> ACCESS=<Data->IdentityType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->IdentityType);
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST", "IdentityType");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_IDENTITY_REQUEST_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST", "SpareHalfOctet");
	ED_Dump_Struct_End (OStream, "IDENTITY_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SECURITY_MODE_COMMAND (TEDOStream* OStream, const c_SECURITY_MODE_COMMAND* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SECURITY_MODE_COMMAND");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "SelectedNASSecurityAlgorithms");
	  /* STRUCTURAL=<0> TYPE=<c_NASSecurityAlgorithms> NAME=<SelectedNASSecurityAlgorithms> ACCESS=<Data->SelectedNASSecurityAlgorithms>  OPTIONAL=<0> FUNC=<Dump_c_NASSecurityAlgorithms> */
	  Dump_c_NASSecurityAlgorithms (OStream, &(Data->SelectedNASSecurityAlgorithms));
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "SelectedNASSecurityAlgorithms");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "NASKeySetIdentifier");
	  /* STRUCTURAL=<0> TYPE=<c_NASKeySetIdentifier> NAME=<NASKeySetIdentifier> ACCESS=<Data->NASKeySetIdentifier>  OPTIONAL=<0> FUNC=<Dump_c_NASKeySetIdentifier> */
	  Dump_c_NASKeySetIdentifier (OStream, &(Data->NASKeySetIdentifier));
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "NASKeySetIdentifier");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_SECURITY_MODE_COMMAND_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "ReplayedUESecurityCapabilities");
	  /* STRUCTURAL=<0> TYPE=<c_UESecurityCapability> NAME=<ReplayedUESecurityCapabilities> ACCESS=<Data->ReplayedUESecurityCapabilities>  OPTIONAL=<0> FUNC=<Dump_c_UESecurityCapability> */
	  Dump_c_UESecurityCapability (OStream, &(Data->ReplayedUESecurityCapabilities));
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "ReplayedUESecurityCapabilities");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "IMEISVRequest");
	if (!Data->IMEISVRequest_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IMEISVRequest> ACCESS=<Data->IMEISVRequest>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->IMEISVRequest);
	}
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "IMEISVRequest");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "ReplayedNonceUE");
	if (!Data->ReplayedNonceUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<ReplayedNonceUE> ACCESS=<Data->ReplayedNonceUE>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ReplayedNonceUE);
	}
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "ReplayedNonceUE");
	ED_Dump_Struct_Begin_Field (OStream, "SECURITY_MODE_COMMAND", "NonceMME");
	if (!Data->NonceMME_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<NonceMME> ACCESS=<Data->NonceMME>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NonceMME);
	}
	ED_Dump_Struct_End_Field (OStream, "SECURITY_MODE_COMMAND", "NonceMME");
	ED_Dump_Struct_End (OStream, "SECURITY_MODE_COMMAND");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_REJECT (TEDOStream* OStream, const c_SERVICE_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT", "T3442Value");
	if (!Data->T3442Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3442Value> ACCESS=<*(Data->T3442Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3442Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT", "T3442Value");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT", "T3346Value");
	ED_Dump_Struct_End (OStream, "SERVICE_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRACKING_AREA_UPDATE_ACCEPT (TEDOStream* OStream, const c_TRACKING_AREA_UPDATE_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRACKING_AREA_UPDATE_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSUpdateResult");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EPSUpdateResult> ACCESS=<Data->EPSUpdateResult>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EPSUpdateResult)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "TA updated"); break;
				case 1: OStream->WriteString (OStream, "combined TA/LA updated"); break;
				case 4: OStream->WriteString (OStream, "TA updated and ISR activated"); break;
				case 5: OStream->WriteString (OStream, "combined TA/LA updated and ISR activated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSUpdateResult");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<c_TRACKING_AREA_UPDATE_ACCEPT_SpareHalfOctet> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3412Value");
	if (!Data->T3412Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412Value> ACCESS=<*(Data->T3412Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3412Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3412Value");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "GUTI");
	if (!Data->GUTI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSMobileIdentity> NAME=<GUTI> ACCESS=<*(Data->GUTI)>  OPTIONAL=<1> FUNC=<Dump_c_EPSMobileIdentity> */
	  Dump_c_EPSMobileIdentity (OStream, &(*(Data->GUTI)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "GUTI");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "TAIList");
	if (!Data->TAIList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PartialTrackingAreaIdentityList> NAME=<TAIList> ACCESS=<*(Data->TAIList)>  OPTIONAL=<1> FUNC=<Dump_c_PartialTrackingAreaIdentityList> */
	  Dump_c_PartialTrackingAreaIdentityList (OStream, &(*(Data->TAIList)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "TAIList");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSBearerContextStatus");
	if (!Data->EPSBearerContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus> NAME=<EPSBearerContextStatus> ACCESS=<*(Data->EPSBearerContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_EPSBearerContextStatus> */
	  Dump_c_EPSBearerContextStatus (OStream, &(*(Data->EPSBearerContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSBearerContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "LocationAreaIdentification");
	if (!Data->LocationAreaIdentification_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsLocationAreaId> NAME=<LocationAreaIdentification> ACCESS=<*(Data->LocationAreaIdentification)>  OPTIONAL=<1> FUNC=<Dump_c_epsLocationAreaId> */
	  Dump_c_epsLocationAreaId (OStream, &(*(Data->LocationAreaIdentification)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "LocationAreaIdentification");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "MSIdentity");
	if (!Data->MSIdentity_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsMobileId> NAME=<MSIdentity> ACCESS=<*(Data->MSIdentity)>  OPTIONAL=<1> FUNC=<Dump_c_epsMobileId> */
	  Dump_c_epsMobileId (OStream, &(*(Data->MSIdentity)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "MSIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EMMCause");
	if (!Data->EMMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3402Value");
	if (!Data->T3402Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3402Value> ACCESS=<*(Data->T3402Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3402Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3402Value");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3423Value");
	if (!Data->T3423Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3423Value> ACCESS=<*(Data->T3423Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3423Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3423Value");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EquivalentPLMNs");
	if (!Data->EquivalentPLMNs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsPlmnList> NAME=<EquivalentPLMNs> ACCESS=<*(Data->EquivalentPLMNs)>  OPTIONAL=<1> FUNC=<Dump_c_epsPlmnList> */
	  Dump_c_epsPlmnList (OStream, &(*(Data->EquivalentPLMNs)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EquivalentPLMNs");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "epsEmergencyNumberList");
	if (!Data->epsEmergencyNumberList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsEmergencyNumberList> NAME=<epsEmergencyNumberList> ACCESS=<*(Data->epsEmergencyNumberList)>  OPTIONAL=<1> FUNC=<Dump_c_epsEmergencyNumberList> */
	  Dump_c_epsEmergencyNumberList (OStream, &(*(Data->epsEmergencyNumberList)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "epsEmergencyNumberList");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSNetworkFeatureSupport");
	if (!Data->EPSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSNetworkFeatureSupport> NAME=<EPSNetworkFeatureSupport> ACCESS=<*(Data->EPSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_EPSNetworkFeatureSupport> */
	  Dump_c_EPSNetworkFeatureSupport (OStream, &(*(Data->EPSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "EPSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "AdditionalUpdateResult");
	if (!Data->AdditionalUpdateResult_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateResult> NAME=<AdditionalUpdateResult> ACCESS=<*(Data->AdditionalUpdateResult)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateResult> */
	  Dump_c_AdditionalUpdateResult (OStream, &(*(Data->AdditionalUpdateResult)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "AdditionalUpdateResult");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3412ExtendedValue");
	if (!Data->T3412ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer> NAME=<T3412ExtendedValue> ACCESS=<*(Data->T3412ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer> */
	  Dump_c_epsGprsTimer (OStream, &(*(Data->T3412ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3412ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3324ValueGPRSTimer2");
	if (!Data->T3324ValueGPRSTimer2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3324ValueGPRSTimer2> ACCESS=<*(Data->T3324ValueGPRSTimer2)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3324ValueGPRSTimer2)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "T3324ValueGPRSTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_epsExtendedDRXParameters> */
	  Dump_c_epsExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "ExtendedDRXParameters");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "HeaderCompressionCfgStatus");
	if (!Data->HeaderCompressionCfgStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HeaderCompressionCfgStatus> NAME=<HeaderCompressionCfgStatus> ACCESS=<*(Data->HeaderCompressionCfgStatus)>  OPTIONAL=<1> FUNC=<Dump_c_HeaderCompressionCfgStatus> */
	  Dump_c_HeaderCompressionCfgStatus (OStream, &(*(Data->HeaderCompressionCfgStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_ACCEPT", "HeaderCompressionCfgStatus");
	ED_Dump_Struct_End (OStream, "TRACKING_AREA_UPDATE_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRACKING_AREA_UPDATE_REJECT (TEDOStream* OStream, const c_TRACKING_AREA_UPDATE_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRACKING_AREA_UPDATE_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "EMMCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EMMCause> ACCESS=<Data->EMMCause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EMMCause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HSS"); break;
				case 3: OStream->WriteString (OStream, "Illegal UE"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 7: OStream->WriteString (OStream, "EPS services not allowed"); break;
				case 8: OStream->WriteString (OStream, "EPS services and non-EPS services not allowed"); break;
				case 9: OStream->WriteString (OStream, "UE identity cannot be derived by the network"); break;
				case 10: OStream->WriteString (OStream, "Implicitly detached"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Tracking Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this tracking area"); break;
				case 14: OStream->WriteString (OStream, "EPS services not allowed in this PLMN"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In tracking area"); break;
				case 16: OStream->WriteString (OStream, "MSC temporarily not reachable"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 18: OStream->WriteString (OStream, "CS domain not available"); break;
				case 19: OStream->WriteString (OStream, "ESM failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "UE security capabilities mismatch"); break;
				case 24: OStream->WriteString (OStream, "Security mode rejected, unspecified"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 35: OStream->WriteString (OStream, "Requested service option not authorized in this PLMN"); break;
				case 38: OStream->WriteString (OStream, "CS fallback call establishment not allowed"); break;
				case 39: OStream->WriteString (OStream, "CS service temporarily not available"); break;
				case 40: OStream->WriteString (OStream, "No EPS bearer context activated"); break;
				case 42: OStream->WriteString (OStream, "Severe network failure"); break;
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
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "EMMCause");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_epsGprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_epsGprsTimer2> */
	  Dump_c_epsGprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "T3346Value");
	ED_Dump_Struct_Begin_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "ExtendedEMMCause");
	if (!Data->ExtendedEMMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedEMMCause> NAME=<ExtendedEMMCause> ACCESS=<*(Data->ExtendedEMMCause)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedEMMCause> */
	  Dump_c_ExtendedEMMCause (OStream, &(*(Data->ExtendedEMMCause)));
	}
	ED_Dump_Struct_End_Field (OStream, "TRACKING_AREA_UPDATE_REJECT", "ExtendedEMMCause");
	ED_Dump_Struct_End (OStream, "TRACKING_AREA_UPDATE_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DOWNLINK_GENERIC_NAS_TRANSPORT (TEDOStream* OStream, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainerType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GenericMessageContainerType> ACCESS=<Data->GenericMessageContainerType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->GenericMessageContainerType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "LTE Positioning Protocol (LPP) message container"); break;
				case 2: OStream->WriteString (OStream, "Location services message container"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainerType");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainer");
	  /* NAME=<GenericMessageContainer> ACCESS=<Data->GenericMessageContainer>  MAXBITSIZE=<4784> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->GenericMessageContainer.value, Data->GenericMessageContainer.usedBits);
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "GenericMessageContainer");
	ED_Dump_Struct_Begin_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "AdditionalInformation");
	if (!Data->AdditionalInformation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AdditionalInformation> ACCESS=<*(Data->AdditionalInformation)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AdditionalInformation->value, Data->AdditionalInformation->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT", "AdditionalInformation");
	ED_Dump_Struct_End (OStream, "DOWNLINK_GENERIC_NAS_TRANSPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_ACCEPT (TEDOStream* OStream, const c_SERVICE_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_ACCEPT", "SecurityHeaderType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SecurityHeaderType> ACCESS=<Data->SecurityHeaderType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SecurityHeaderType);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_ACCEPT", "SecurityHeaderType");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_ACCEPT", "EPSBearerContextStatus");
	if (!Data->EPSBearerContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EPSBearerContextStatus> NAME=<EPSBearerContextStatus> ACCESS=<*(Data->EPSBearerContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_EPSBearerContextStatus> */
	  Dump_c_EPSBearerContextStatus (OStream, &(*(Data->EPSBearerContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_ACCEPT", "EPSBearerContextStatus");
	ED_Dump_Struct_End (OStream, "SERVICE_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsGprsTimer3 (TEDOStream* OStream, const c_epsGprsTimer3* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsGprsTimer3");
	ED_Dump_Struct_Begin_Field (OStream, "epsGprsTimer3", "Unit");
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
				case 7: OStream->WriteString (OStream, "value indicates that the timer is deactivated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "epsGprsTimer3", "Unit");
	ED_Dump_Struct_Begin_Field (OStream, "epsGprsTimer3", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "epsGprsTimer3", "TimerValue");
	ED_Dump_Struct_End (OStream, "epsGprsTimer3");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_epsCalledPartyBcdNum (TEDOStream* OStream, const c_epsCalledPartyBcdNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "epsCalledPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "epsCalledPartyBcdNum", "TypeOfNumber");
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
	ED_Dump_Struct_End_Field (OStream, "epsCalledPartyBcdNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "epsCalledPartyBcdNum", "NumberingPlanIdent");
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
	ED_Dump_Struct_End_Field (OStream, "epsCalledPartyBcdNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "epsCalledPartyBcdNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_epsTBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_epsTBCDArray> */
	  Dump_c_epsTBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "epsCalledPartyBcdNum", "Number");
	ED_Dump_Struct_End (OStream, "epsCalledPartyBcdNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GenericTLV_EPS (TEDOStream* OStream, const c_GenericTLV_EPS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GenericTLV_EPS");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_EPS", "TLV_Tag");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TLV_Tag> ACCESS=<Data->TLV_Tag>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TLV_Tag);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_EPS", "TLV_Tag");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_EPS", "TLV_Data");
	  /* NAME=<TLV_Data> ACCESS=<Data->TLV_Data>  MAXBITSIZE=<8192> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TLV_Data.value, Data->TLV_Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_EPS", "TLV_Data");
	ED_Dump_Struct_End (OStream, "GenericTLV_EPS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_EPS_MM_Uplink (TEDOStream* OStream, const TEPS_MM_Uplink_Data* Data)
{
	switch (Data->Type) {
		case ID_EPS_MM_Uplink_ATTACH_COMPLETE: Dump_c_ATTACH_COMPLETE (OStream, Data->Data.fld_c_ATTACH_COMPLETE); break;
		case ID_EPS_MM_Uplink_ATTACH_REQUEST: Dump_c_ATTACH_REQUEST (OStream, Data->Data.fld_c_ATTACH_REQUEST); break;
		case ID_EPS_MM_Uplink_AUTHENTICATION_FAILURE: Dump_c_AUTHENTICATION_FAILURE (OStream, Data->Data.fld_c_AUTHENTICATION_FAILURE); break;
		case ID_EPS_MM_Uplink_AUTHENTICATION_RESPONSE: Dump_c_AUTHENTICATION_RESPONSE (OStream, Data->Data.fld_c_AUTHENTICATION_RESPONSE); break;
		case ID_EPS_MM_Uplink_EPS_DETACH_ACCEPT_UP: Dump_c_EPS_DETACH_ACCEPT_UP (OStream, Data->Data.fld_c_EPS_DETACH_ACCEPT_UP); break;
		case ID_EPS_MM_Uplink_EPS_DETACH_REQUEST_UP: Dump_c_EPS_DETACH_REQUEST_UP (OStream, Data->Data.fld_c_EPS_DETACH_REQUEST_UP); break;
		case ID_EPS_MM_Uplink_EMM_STATUS: Dump_c_EMM_STATUS (OStream, Data->Data.fld_c_EMM_STATUS); break;
		case ID_EPS_MM_Uplink_EXTENDED_SERVICE_REQUEST: Dump_c_EXTENDED_SERVICE_REQUEST (OStream, Data->Data.fld_c_EXTENDED_SERVICE_REQUEST); break;
		case ID_EPS_MM_Uplink_GUTI_REALLOCATION_COMPLETE: Dump_c_GUTI_REALLOCATION_COMPLETE (OStream, Data->Data.fld_c_GUTI_REALLOCATION_COMPLETE); break;
		case ID_EPS_MM_Uplink_IDENTITY_RESPONSE: Dump_c_IDENTITY_RESPONSE (OStream, Data->Data.fld_c_IDENTITY_RESPONSE); break;
		case ID_EPS_MM_Uplink_SECURITY_MODE_COMPLETE: Dump_c_SECURITY_MODE_COMPLETE (OStream, Data->Data.fld_c_SECURITY_MODE_COMPLETE); break;
		case ID_EPS_MM_Uplink_SECURITY_MODE_REJECT: Dump_c_SECURITY_MODE_REJECT (OStream, Data->Data.fld_c_SECURITY_MODE_REJECT); break;
		case ID_EPS_MM_Uplink_SECURITY_PROTECTED_NAS_MESSAGE: Dump_c_SECURITY_PROTECTED_NAS_MESSAGE (OStream, Data->Data.fld_c_SECURITY_PROTECTED_NAS_MESSAGE); break;
		case ID_EPS_MM_Uplink_SERVICE_REQUEST: Dump_c_SERVICE_REQUEST (OStream, Data->Data.fld_c_SERVICE_REQUEST); break;
		case ID_EPS_MM_Uplink_TRACKING_AREA_UPDATE_COMPLETE: Dump_c_TRACKING_AREA_UPDATE_COMPLETE (OStream, Data->Data.fld_c_TRACKING_AREA_UPDATE_COMPLETE); break;
		case ID_EPS_MM_Uplink_TRACKING_AREA_UPDATE_REQUEST: Dump_c_TRACKING_AREA_UPDATE_REQUEST (OStream, Data->Data.fld_c_TRACKING_AREA_UPDATE_REQUEST); break;
		case ID_EPS_MM_Uplink_UPLINK_NAS_TRANSPORT: Dump_c_UPLINK_NAS_TRANSPORT (OStream, Data->Data.fld_c_UPLINK_NAS_TRANSPORT); break;
		case ID_EPS_MM_Uplink_UPLINK_GENERIC_NAS_TRANSPORT: Dump_c_UPLINK_GENERIC_NAS_TRANSPORT (OStream, Data->Data.fld_c_UPLINK_GENERIC_NAS_TRANSPORT); break;
		case ID_EPS_MM_Uplink_CONTROL_PLANE_SERVICE_REQUEST: Dump_c_CONTROL_PLANE_SERVICE_REQUEST (OStream, Data->Data.fld_c_CONTROL_PLANE_SERVICE_REQUEST); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_EPS_MM_Downlink (TEDOStream* OStream, const TEPS_MM_Downlink_Data* Data)
{
	switch (Data->Type) {
		case ID_EPS_MM_Downlink_ATTACH_ACCEPT: Dump_c_ATTACH_ACCEPT (OStream, Data->Data.fld_c_ATTACH_ACCEPT); break;
		case ID_EPS_MM_Downlink_ATTACH_REJECT: Dump_c_ATTACH_REJECT (OStream, Data->Data.fld_c_ATTACH_REJECT); break;
		case ID_EPS_MM_Downlink_AUTHENTICATION_REJECT: Dump_c_AUTHENTICATION_REJECT (OStream, Data->Data.fld_c_AUTHENTICATION_REJECT); break;
		case ID_EPS_MM_Downlink_AUTHENTICATION_REQUEST: Dump_c_AUTHENTICATION_REQUEST (OStream, Data->Data.fld_c_AUTHENTICATION_REQUEST); break;
		case ID_EPS_MM_Downlink_CS_SERVICE_NOTIFICATION: Dump_c_CS_SERVICE_NOTIFICATION (OStream, Data->Data.fld_c_CS_SERVICE_NOTIFICATION); break;
		case ID_EPS_MM_Downlink_EPS_DETACH_ACCEPT_DN: Dump_c_EPS_DETACH_ACCEPT_DN (OStream, Data->Data.fld_c_EPS_DETACH_ACCEPT_DN); break;
		case ID_EPS_MM_Downlink_EPS_DETACH_REQUEST_DN: Dump_c_EPS_DETACH_REQUEST_DN (OStream, Data->Data.fld_c_EPS_DETACH_REQUEST_DN); break;
		case ID_EPS_MM_Downlink_DOWNLINK_NAS_TRANSPORT: Dump_c_DOWNLINK_NAS_TRANSPORT (OStream, Data->Data.fld_c_DOWNLINK_NAS_TRANSPORT); break;
		case ID_EPS_MM_Downlink_EMM_INFORMATION: Dump_c_EMM_INFORMATION (OStream, Data->Data.fld_c_EMM_INFORMATION); break;
		case ID_EPS_MM_Downlink_EMM_STATUS: Dump_c_EMM_STATUS (OStream, Data->Data.fld_c_EMM_STATUS); break;
		case ID_EPS_MM_Downlink_GUTI_REALLOCATION_COMMAND: Dump_c_GUTI_REALLOCATION_COMMAND (OStream, Data->Data.fld_c_GUTI_REALLOCATION_COMMAND); break;
		case ID_EPS_MM_Downlink_IDENTITY_REQUEST: Dump_c_IDENTITY_REQUEST (OStream, Data->Data.fld_c_IDENTITY_REQUEST); break;
		case ID_EPS_MM_Downlink_SECURITY_MODE_COMMAND: Dump_c_SECURITY_MODE_COMMAND (OStream, Data->Data.fld_c_SECURITY_MODE_COMMAND); break;
		case ID_EPS_MM_Downlink_SECURITY_PROTECTED_NAS_MESSAGE: Dump_c_SECURITY_PROTECTED_NAS_MESSAGE (OStream, Data->Data.fld_c_SECURITY_PROTECTED_NAS_MESSAGE); break;
		case ID_EPS_MM_Downlink_SERVICE_REJECT: Dump_c_SERVICE_REJECT (OStream, Data->Data.fld_c_SERVICE_REJECT); break;
		case ID_EPS_MM_Downlink_TRACKING_AREA_UPDATE_ACCEPT: Dump_c_TRACKING_AREA_UPDATE_ACCEPT (OStream, Data->Data.fld_c_TRACKING_AREA_UPDATE_ACCEPT); break;
		case ID_EPS_MM_Downlink_TRACKING_AREA_UPDATE_REJECT: Dump_c_TRACKING_AREA_UPDATE_REJECT (OStream, Data->Data.fld_c_TRACKING_AREA_UPDATE_REJECT); break;
		case ID_EPS_MM_Downlink_DOWNLINK_GENERIC_NAS_TRANSPORT: Dump_c_DOWNLINK_GENERIC_NAS_TRANSPORT (OStream, Data->Data.fld_c_DOWNLINK_GENERIC_NAS_TRANSPORT); break;
		case ID_EPS_MM_Downlink_SERVICE_ACCEPT: Dump_c_SERVICE_ACCEPT (OStream, Data->Data.fld_c_SERVICE_ACCEPT); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_EPS_SM_Uplink (TEDOStream* OStream, const TEPS_SM_Uplink_Data* Data)
{
	switch (Data->Type) {
		case ID_EPS_SM_Uplink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT: Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT); break;
		case ID_EPS_SM_Uplink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT: Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (OStream, Data->Data.fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT); break;
		case ID_EPS_SM_Uplink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT: Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT); break;
		case ID_EPS_SM_Uplink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT: Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (OStream, Data->Data.fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT); break;
		case ID_EPS_SM_Uplink_BEARER_RESOURCE_ALLOCATION_REQUEST: Dump_c_BEARER_RESOURCE_ALLOCATION_REQUEST (OStream, Data->Data.fld_c_BEARER_RESOURCE_ALLOCATION_REQUEST); break;
		case ID_EPS_SM_Uplink_BEARER_RESOURCE_MODIFICATION_REQUEST: Dump_c_BEARER_RESOURCE_MODIFICATION_REQUEST (OStream, Data->Data.fld_c_BEARER_RESOURCE_MODIFICATION_REQUEST); break;
		case ID_EPS_SM_Uplink_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT: Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT); break;
		case ID_EPS_SM_Uplink_ESM_DUMMY_MESSAGE: Dump_c_ESM_DUMMY_MESSAGE (OStream, Data->Data.fld_c_ESM_DUMMY_MESSAGE); break;
		case ID_EPS_SM_Uplink_ESM_INFORMATION_RESPONSE: Dump_c_ESM_INFORMATION_RESPONSE (OStream, Data->Data.fld_c_ESM_INFORMATION_RESPONSE); break;
		case ID_EPS_SM_Uplink_ESM_STATUS: Dump_c_ESM_STATUS (OStream, Data->Data.fld_c_ESM_STATUS); break;
		case ID_EPS_SM_Uplink_MODIFY_EPS_BEARER_CONTEXT_ACCEPT: Dump_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT); break;
		case ID_EPS_SM_Uplink_MODIFY_EPS_BEARER_CONTEXT_REJECT: Dump_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (OStream, Data->Data.fld_c_MODIFY_EPS_BEARER_CONTEXT_REJECT); break;
		case ID_EPS_SM_Uplink_PDN_CONNECTIVITY_REQUEST: Dump_c_PDN_CONNECTIVITY_REQUEST (OStream, Data->Data.fld_c_PDN_CONNECTIVITY_REQUEST); break;
		case ID_EPS_SM_Uplink_PDN_DISCONNECT_REQUEST: Dump_c_PDN_DISCONNECT_REQUEST (OStream, Data->Data.fld_c_PDN_DISCONNECT_REQUEST); break;
		case ID_EPS_SM_Uplink_REMOTE_UE_REPORT: Dump_c_REMOTE_UE_REPORT (OStream, Data->Data.fld_c_REMOTE_UE_REPORT); break;
		case ID_EPS_SM_Uplink_ESM_DATA_TRANSPORT: Dump_c_ESM_DATA_TRANSPORT (OStream, Data->Data.fld_c_ESM_DATA_TRANSPORT); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_EPS_SM_Downlink (TEDOStream* OStream, const TEPS_SM_Downlink_Data* Data)
{
	switch (Data->Type) {
		case ID_EPS_SM_Downlink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST: Dump_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (OStream, Data->Data.fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST); break;
		case ID_EPS_SM_Downlink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST: Dump_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (OStream, Data->Data.fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST); break;
		case ID_EPS_SM_Downlink_BEARER_RESOURCE_ALLOCATION_REJECT: Dump_c_BEARER_RESOURCE_ALLOCATION_REJECT (OStream, Data->Data.fld_c_BEARER_RESOURCE_ALLOCATION_REJECT); break;
		case ID_EPS_SM_Downlink_BEARER_RESOURCE_MODIFICATION_REJECT: Dump_c_BEARER_RESOURCE_MODIFICATION_REJECT (OStream, Data->Data.fld_c_BEARER_RESOURCE_MODIFICATION_REJECT); break;
		case ID_EPS_SM_Downlink_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST: Dump_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (OStream, Data->Data.fld_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST); break;
		case ID_EPS_SM_Downlink_ESM_DUMMY_MESSAGE: Dump_c_ESM_DUMMY_MESSAGE (OStream, Data->Data.fld_c_ESM_DUMMY_MESSAGE); break;
		case ID_EPS_SM_Downlink_ESM_INFORMATION_REQUEST: Dump_c_ESM_INFORMATION_REQUEST (OStream, Data->Data.fld_c_ESM_INFORMATION_REQUEST); break;
		case ID_EPS_SM_Downlink_ESM_STATUS: Dump_c_ESM_STATUS (OStream, Data->Data.fld_c_ESM_STATUS); break;
		case ID_EPS_SM_Downlink_MODIFY_EPS_BEARER_CONTEXT_REQUEST: Dump_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (OStream, Data->Data.fld_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST); break;
		case ID_EPS_SM_Downlink_EPS_NOTIFICATION: Dump_c_EPS_NOTIFICATION (OStream, Data->Data.fld_c_EPS_NOTIFICATION); break;
		case ID_EPS_SM_Downlink_PDN_CONNECTIVITY_REJECT: Dump_c_PDN_CONNECTIVITY_REJECT (OStream, Data->Data.fld_c_PDN_CONNECTIVITY_REJECT); break;
		case ID_EPS_SM_Downlink_PDN_DISCONNECT_REJECT: Dump_c_PDN_DISCONNECT_REJECT (OStream, Data->Data.fld_c_PDN_DISCONNECT_REJECT); break;
		case ID_EPS_SM_Downlink_REMOTE_UE_REPORT_RESPONSE: Dump_c_REMOTE_UE_REPORT_RESPONSE (OStream, Data->Data.fld_c_REMOTE_UE_REPORT_RESPONSE); break;
		case ID_EPS_SM_Downlink_ESM_DATA_TRANSPORT: Dump_c_ESM_DATA_TRANSPORT (OStream, Data->Data.fld_c_ESM_DATA_TRANSPORT); break;
		default:;
	}
}
