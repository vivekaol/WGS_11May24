/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "UserDefinedDataTypes_L3.h"
#include "ed_c_known_ie_L3.h"
#include "ed_tlv.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LocationAreaId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LocationAreaId* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 40;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2135> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2136> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2137> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2138> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2139> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2140> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2141> Error encoding subfield LAC\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LocationAreaId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LocationAreaId* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2142> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2142)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2143> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2143)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2144> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2144)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2145> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2145)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2146> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2146)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2147> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2147)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).LAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).LAC___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2148> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2148)
	} 
#endif
	Len += Ret;
	

	}
	return 40;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId_TMGI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId_TMGI* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 64;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2149> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).MBMSSessIdIndic != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2150> Error encoding subfield MBMSSessIdIndic\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).MCCMNCIndic != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2151> Error encoding subfield MCCMNCIndic\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2152> Error encoding subfield OddEven\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).IdentityType), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2153> Error encoding subfield IdentityType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MBMSServiceID), 24);
	Ret = 24;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2154> Error encoding subfield MBMSServiceID\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2155> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+36), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2156> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2157> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+44), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2158> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2159> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+52), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2160> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+56), (int)((*Source).MBMSSessionIdentity), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2161> Error encoding subfield MBMSSessionIdentity\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId_TMGI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId_TMGI* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2162> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2162)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MBMSSessIdIndic = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MBMSSessIdIndic___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2163> Error decoding subfield MBMSSessIdIndic\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2163)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCCMNCIndic = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MCCMNCIndic___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2164> Error decoding subfield MCCMNCIndic\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2164)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2165> Error decoding subfield OddEven\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2165)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).IdentityType = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).IdentityType___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2166> Error decoding subfield IdentityType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2166)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MBMSServiceID = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs+8), 24);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MBMSServiceID___LOCATOR), CurrOfs+8, 24);
	Ret = 24;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2167> Error decoding subfield MBMSServiceID\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2167)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+32), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs+32, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2168> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2168)
	} 
#endif
	Len += Ret;
	
	/* FromBit=36 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+36), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+36, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2169> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2169)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+40), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+40, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2170> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2170)
	} 
#endif
	Len += Ret;
	
	/* FromBit=44 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+44), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+44, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2171> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2171)
	} 
#endif
	Len += Ret;
	
	/* FromBit=48 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+48), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+48, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2172> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2172)
	} 
#endif
	Len += Ret;
	
	/* FromBit=52 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+52), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+52, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2173> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2173)
	} 
#endif
	Len += Ret;
	
	/* FromBit=56 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MBMSSessionIdentity = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+56), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MBMSSessionIdentity___LOCATOR), CurrOfs+56, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2174> Error decoding subfield MBMSSessionIdentity\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2174)
	} 
#endif
	Len += Ret;
	

	}
	return 64;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileStationClassmark1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileStationClassmark1* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2175> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).RevisionLevel), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2176> Error encoding subfield RevisionLevel\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EsInd != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2177> Error encoding subfield EsInd\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).A5_1 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2178> Error encoding subfield A5_1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).RfPowerCapability), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2179> Error encoding subfield RfPowerCapability\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileStationClassmark1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileStationClassmark1* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2180> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2180)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).RevisionLevel = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RevisionLevel___LOCATOR), CurrOfs+1, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2181> Error decoding subfield RevisionLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2181)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EsInd = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EsInd___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2182> Error decoding subfield EsInd\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2182)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).A5_1 = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).A5_1___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2183> Error decoding subfield A5_1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2183)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).RfPowerCapability = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RfPowerCapability___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2184> Error decoding subfield RfPowerCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2184)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileStationClassmark2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileStationClassmark2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2185> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).RevisionLevel), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2186> Error encoding subfield RevisionLevel\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EsInd != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2187> Error encoding subfield EsInd\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).A5_1 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2188> Error encoding subfield A5_1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).RFPowerCapability), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2189> Error encoding subfield RFPowerCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2190> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).PSCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2191> Error encoding subfield PSCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).SSScreenIndicator), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2192> Error encoding subfield SSScreenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).SMCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2193> Error encoding subfield SMCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).VBS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2194> Error encoding subfield VBS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).VGCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2195> Error encoding subfield VGCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).FC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2196> Error encoding subfield FC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).CM3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2197> Error encoding subfield CM3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+17, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2198> Error encoding subfield spare3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).LCSVA_CAP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2199> Error encoding subfield LCSVA_CAP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).UCS2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2200> Error encoding subfield UCS2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).SoLSA != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2201> Error encoding subfield SoLSA\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+21), (int)((*Source).CMSP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2202> Error encoding subfield CMSP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).A5_3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2203> Error encoding subfield A5_3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+23), (int)((*Source).A5_2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2204> Error encoding subfield A5_2\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileStationClassmark2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileStationClassmark2* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2205> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2205)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).RevisionLevel = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RevisionLevel___LOCATOR), CurrOfs+1, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2206> Error decoding subfield RevisionLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2206)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EsInd = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EsInd___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2207> Error decoding subfield EsInd\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2207)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).A5_1 = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).A5_1___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2208> Error decoding subfield A5_1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2208)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).RFPowerCapability = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RFPowerCapability___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2209> Error decoding subfield RFPowerCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2209)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2210> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2210)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).PSCapability = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PSCapability___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2211> Error decoding subfield PSCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2211)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).SSScreenIndicator = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+10), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SSScreenIndicator___LOCATOR), CurrOfs+10, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2212> Error decoding subfield SSScreenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2212)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).SMCapability = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SMCapability___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2213> Error decoding subfield SMCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2213)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).VBS = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).VBS___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2214> Error decoding subfield VBS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2214)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).VGCS = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).VGCS___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2215> Error decoding subfield VGCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2215)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).FC = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FC___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2216> Error decoding subfield FC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2216)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).CM3 = (EDBitsToInt (Buffer, CurrOfs+16, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CM3___LOCATOR), CurrOfs+16, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2217> Error decoding subfield CM3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2217)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2218> Error decoding subfield spare3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2218)
	} 
#endif
	Len += Ret;
	
	/* FromBit=18 */
	(*Destin).LCSVA_CAP = (EDBitsToInt (Buffer, CurrOfs+18, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LCSVA_CAP___LOCATOR), CurrOfs+18, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2219> Error decoding subfield LCSVA_CAP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2219)
	} 
#endif
	Len += Ret;
	
	/* FromBit=19 */
	(*Destin).UCS2 = (EDBitsToInt (Buffer, CurrOfs+19, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UCS2___LOCATOR), CurrOfs+19, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2220> Error decoding subfield UCS2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2220)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).SoLSA = (EDBitsToInt (Buffer, CurrOfs+20, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SoLSA___LOCATOR), CurrOfs+20, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2221> Error decoding subfield SoLSA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2221)
	} 
#endif
	Len += Ret;
	
	/* FromBit=21 */
	(*Destin).CMSP = (EDBitsToInt (Buffer, CurrOfs+21, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CMSP___LOCATOR), CurrOfs+21, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2222> Error decoding subfield CMSP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2222)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).A5_3 = (EDBitsToInt (Buffer, CurrOfs+22, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).A5_3___LOCATOR), CurrOfs+22, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2223> Error decoding subfield A5_3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2223)
	} 
#endif
	Len += Ret;
	
	/* FromBit=23 */
	(*Destin).A5_2 = (EDBitsToInt (Buffer, CurrOfs+23, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).A5_2___LOCATOR), CurrOfs+23, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2224> Error decoding subfield A5_2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2224)
	} 
#endif
	Len += Ret;
	

	}
	return 24;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PdAndSapiCcbs (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PdAndSapiCcbs* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2225> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).SAPI), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2226> Error encoding subfield SAPI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).PD), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2227> Error encoding subfield PD\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PdAndSapiCcbs (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PdAndSapiCcbs* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2228> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2228)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).SAPI = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SAPI___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2229> Error decoding subfield SAPI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2229)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).PD = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PD___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2230> Error decoding subfield PD\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2230)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PriorityLevel (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PriorityLevel* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2231> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CallPriority), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2232> Error encoding subfield CallPriority\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PriorityLevel (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PriorityLevel* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2233> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2233)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).CallPriority = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CallPriority___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2234> Error decoding subfield CallPriority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2234)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Plmn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Plmn* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2235> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2236> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2237> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2238> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2239> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2240> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Plmn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Plmn* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2241> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2241)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2242> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2242)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2243> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2243)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2244> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2244)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2245> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2245)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2246> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2246)
	} 
#endif
	Len += Ret;
	

	}
	return 24;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MSNetworkFeatureSupport* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2247> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).ExtendedPeriodicTimers != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2248> Error encoding subfield ExtendedPeriodicTimers\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2249> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2249)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).ExtendedPeriodicTimers = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ExtendedPeriodicTimers___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2250> Error decoding subfield ExtendedPeriodicTimers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2250)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LocationUpdatingType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LocationUpdatingType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).xFOR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2251> Error encoding subfield xFOR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2252> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).LUT), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2253> Error encoding subfield LUT\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LocationUpdatingType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LocationUpdatingType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).xFOR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).xFOR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2254> Error decoding subfield xFOR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2254)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2255> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2255)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).LUT = (unsigned char)EDBitsToInt (Buffer, CurrOfs+2, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).LUT___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2256> Error decoding subfield LUT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2256)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkName (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkName* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2257> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CodingScheme), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2258> Error encoding subfield CodingScheme\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).AddCI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2259> Error encoding subfield AddCI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).SpareBitsInLastOctet), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2260> Error encoding subfield SpareBitsInLastOctet\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).TextString.value, 0, (*Source).TextString.usedBits);
	Ret = (*Source).TextString.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2261> Error encoding subfield TextString\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkName (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkName* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2262> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2262)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).CodingScheme = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CodingScheme___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2263> Error decoding subfield CodingScheme\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2263)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).AddCI = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AddCI___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2264> Error decoding subfield AddCI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2264)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).SpareBitsInLastOctet = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SpareBitsInLastOctet___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2265> Error decoding subfield SpareBitsInLastOctet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2265)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).TextString___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_NetwkName_TextString (&((*Destin).TextString), (Length - 8));
	
		if ((*Destin).TextString.value) {
			EDCopyBits ((*Destin).TextString.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).TextString.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).TextString.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2266> Error decoding subfield TextString\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2266)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RejectCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RejectCause* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Cause), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2267> Error encoding subfield Cause\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RejectCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RejectCause* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Cause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Cause___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2268> Error decoding subfield Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2268)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TimeZoneAndTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TimeZoneAndTime* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 56;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Year), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2269> Error encoding subfield Year\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Month), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2270> Error encoding subfield Month\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).Day), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2271> Error encoding subfield Day\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).Hour), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2272> Error encoding subfield Hour\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).Minute), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2273> Error encoding subfield Minute\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).Second), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2274> Error encoding subfield Second\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).TimeZone), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2275> Error encoding subfield TimeZone\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TimeZoneAndTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TimeZoneAndTime* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Year = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Year___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2276> Error decoding subfield Year\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2276)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Month = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Month___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2277> Error decoding subfield Month\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2277)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).Day = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Day___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2278> Error decoding subfield Day\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2278)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).Hour = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Hour___LOCATOR), CurrOfs+24, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2279> Error decoding subfield Hour\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2279)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).Minute = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+32), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Minute___LOCATOR), CurrOfs+32, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2280> Error decoding subfield Minute\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2280)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).Second = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+40), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Second___LOCATOR), CurrOfs+40, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2281> Error decoding subfield Second\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2281)
	} 
#endif
	Len += Ret;
	
	/* FromBit=48 */
	(*Destin).TimeZone = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+48), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TimeZone___LOCATOR), CurrOfs+48, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2282> Error decoding subfield TimeZone\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2282)
	} 
#endif
	Len += Ret;
	

	}
	return 56;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DaylightSavingTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DaylightSavingTime* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 6);Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2283> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Value), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2284> Error encoding subfield Value\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DaylightSavingTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DaylightSavingTime* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2285> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2285)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).Value = (unsigned char)EDBitsToInt (Buffer, CurrOfs+6, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Value___LOCATOR), CurrOfs+6, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2286> Error decoding subfield Value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2286)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateParameters* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2287> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CSMO != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2288> Error encoding subfield CSMO\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).CSMT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2289> Error encoding subfield CSMT\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateParameters* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2290> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2290)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).CSMO = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CSMO___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2291> Error decoding subfield CSMO\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2291)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).CSMT = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CSMT___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2292> Error decoding subfield CSMT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2292)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AuxiliaryStates (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AuxiliaryStates* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2293> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2294> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).HoldAuxState), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2295> Error encoding subfield HoldAuxState\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).MPTYAuxState), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2296> Error encoding subfield MPTYAuxState\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AuxiliaryStates (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AuxiliaryStates* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2297> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2297)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2298> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2298)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).HoldAuxState = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).HoldAuxState___LOCATOR), CurrOfs+4, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2299> Error decoding subfield HoldAuxState\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2299)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).MPTYAuxState = (unsigned char)EDBitsToInt (Buffer, CurrOfs+6, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MPTYAuxState___LOCATOR), CurrOfs+6, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2300> Error decoding subfield MPTYAuxState\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2300)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallControlCapabil (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallControlCapabil* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MaximumSupportedBearers), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2301> Error encoding subfield MaximumSupportedBearers\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCAT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2302> Error encoding subfield MCAT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).ENICM != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2303> Error encoding subfield ENICM\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).PCP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2304> Error encoding subfield PCP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).DTMF != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2305> Error encoding subfield DTMF\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2306> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MaximumNumOfBearers), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2307> Error encoding subfield MaximumNumOfBearers\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallControlCapabil (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallControlCapabil* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumSupportedBearers = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumSupportedBearers___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2308> Error decoding subfield MaximumSupportedBearers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2308)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCAT = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MCAT___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2309> Error decoding subfield MCAT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2309)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ENICM = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ENICM___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2310> Error decoding subfield ENICM\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2310)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).PCP = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PCP___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2311> Error decoding subfield PCP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2311)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).DTMF = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DTMF___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2312> Error decoding subfield DTMF\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2312)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2313> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2313)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumNumOfBearers = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumNumOfBearers___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2314> Error decoding subfield MaximumNumOfBearers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2314)
	} 
#endif
	Len += Ret;
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallState (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallState* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).CodingStandard), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2315> Error encoding subfield CodingStandard\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CallStateValue), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2316> Error encoding subfield CallStateValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallState (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallState* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).CodingStandard = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CodingStandard___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2317> Error decoding subfield CodingStandard\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2317)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).CallStateValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+2, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CallStateValue___LOCATOR), CurrOfs+2, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2318> Error decoding subfield CallStateValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2318)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CalledPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CalledPartySubaddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2319> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfSubaddress), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2320> Error encoding subfield TypeOfSubaddress\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).OddEvenIndicator != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2321> Error encoding subfield OddEvenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2322> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).SubaddressInformation.value, 0, (*Source).SubaddressInformation.usedBits);
	Ret = (*Source).SubaddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2323> Error encoding subfield SubaddressInformation\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CalledPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CalledPartySubaddr* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2324> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2324)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfSubaddress = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfSubaddress___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2325> Error decoding subfield TypeOfSubaddress\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2325)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).OddEvenIndicator = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OddEvenIndicator___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2326> Error decoding subfield OddEvenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2326)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2327> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2327)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).SubaddressInformation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_CalledPartySubaddr_SubaddressInformation (&((*Destin).SubaddressInformation), (Length - 8));
	
		if ((*Destin).SubaddressInformation.value) {
			EDCopyBits ((*Destin).SubaddressInformation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).SubaddressInformation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).SubaddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2328> Error decoding subfield SubaddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2328)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallingPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallingPartySubaddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2329> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfSubaddress), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2330> Error encoding subfield TypeOfSubaddress\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).OddEvenIndicator != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2331> Error encoding subfield OddEvenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2332> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).SubaddressInformation.value, 0, (*Source).SubaddressInformation.usedBits);
	Ret = (*Source).SubaddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2333> Error encoding subfield SubaddressInformation\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallingPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallingPartySubaddr* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2334> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2334)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfSubaddress = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfSubaddress___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2335> Error decoding subfield TypeOfSubaddress\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2335)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).OddEvenIndicator = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OddEvenIndicator___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2336> Error decoding subfield OddEvenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2336)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2337> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2337)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).SubaddressInformation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_CallingPartySubaddr_SubaddressInformation (&((*Destin).SubaddressInformation), (Length - 8));
	
		if ((*Destin).SubaddressInformation.value) {
			EDCopyBits ((*Destin).SubaddressInformation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).SubaddressInformation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).SubaddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2338> Error decoding subfield SubaddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2338)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ConnSubaddres (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ConnSubaddres* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2339> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfSubaddress), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2340> Error encoding subfield TypeOfSubaddress\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).OddEvenIndicator != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2341> Error encoding subfield OddEvenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2342> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).SubaddressInformation.value, 0, (*Source).SubaddressInformation.usedBits);
	Ret = (*Source).SubaddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2343> Error encoding subfield SubaddressInformation\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ConnSubaddres (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ConnSubaddres* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2344> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2344)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfSubaddress = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TypeOfSubaddress___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2345> Error decoding subfield TypeOfSubaddress\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2345)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).OddEvenIndicator = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OddEvenIndicator___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2346> Error decoding subfield OddEvenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2346)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2347> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2347)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).SubaddressInformation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_ConnSubaddres_SubaddressInformation (&((*Destin).SubaddressInformation), (Length - 8));
	
		if ((*Destin).SubaddressInformation.value) {
			EDCopyBits ((*Destin).SubaddressInformation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).SubaddressInformation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).SubaddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2348> Error decoding subfield SubaddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2348)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_KeypadFacility (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_KeypadFacility* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2349> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).KeypadInfo), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2350> Error encoding subfield KeypadInfo\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_KeypadFacility (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_KeypadFacility* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2351> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2351)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).KeypadInfo = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).KeypadInfo___LOCATOR), CurrOfs+1, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2352> Error decoding subfield KeypadInfo\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2352)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NotifInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NotifInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2353> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).NotificationDescription), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2354> Error encoding subfield NotificationDescription\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NotifInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NotifInd* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2355> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2355)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).NotificationDescription = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 7);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NotificationDescription___LOCATOR), CurrOfs+1, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2356> Error decoding subfield NotificationDescription\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2356)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ProgrInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ProgrInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2357> Error encoding subfield ext1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CodingStandard), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2358> Error encoding subfield CodingStandard\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+3, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2359> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).location), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2360> Error encoding subfield location\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2361> Error encoding subfield ext2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).ProgressDescription), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2362> Error encoding subfield ProgressDescription\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ProgrInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ProgrInd* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2363> Error decoding subfield ext1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2363)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).CodingStandard = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CodingStandard___LOCATOR), CurrOfs+1, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2364> Error decoding subfield CodingStandard\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2364)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2365> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2365)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).location = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).location___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2366> Error decoding subfield location\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2366)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2367> Error decoding subfield ext2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2367)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).ProgressDescription = (unsigned char)EDBitsToInt (Buffer, CurrOfs+9, 7);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ProgressDescription___LOCATOR), CurrOfs+9, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2368> Error decoding subfield ProgressDescription\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2368)
	} 
#endif
	Len += Ret;
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RecallType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RecallType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 5);Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2369> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).RecallType), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2370> Error encoding subfield RecallType\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RecallType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RecallType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2371> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2371)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).RecallType = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RecallType___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2372> Error decoding subfield RecallType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2372)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RedirPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RedirPartySubaddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 1, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2373> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfSubaddress), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2374> Error encoding subfield TypeOfSubaddress\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).OddEvenIndicator != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2375> Error encoding subfield OddEvenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2376> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).SubaddressInformation.value, 0, (*Source).SubaddressInformation.usedBits);
	Ret = (*Source).SubaddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2377> Error encoding subfield SubaddressInformation\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RedirPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RedirPartySubaddr* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2378> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2378)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfSubaddress = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TypeOfSubaddress___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2379> Error decoding subfield TypeOfSubaddress\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2379)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).OddEvenIndicator = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OddEvenIndicator___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2380> Error decoding subfield OddEvenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2380)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2381> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2381)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).SubaddressInformation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_RedirPartySubaddr_SubaddressInformation (&((*Destin).SubaddressInformation), (Length - 8));
	
		if ((*Destin).SubaddressInformation.value) {
			EDCopyBits ((*Destin).SubaddressInformation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).SubaddressInformation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).SubaddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2382> Error decoding subfield SubaddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2382)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AlertingPattern (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AlertingPattern* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2383> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).AlertingPatternValue), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2384> Error encoding subfield AlertingPatternValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AlertingPattern (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AlertingPattern* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2385> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2385)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).AlertingPatternValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).AlertingPatternValue___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2386> Error decoding subfield AlertingPatternValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2386)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AllowedActionsCcbs (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AllowedActionsCcbs* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).CCBSAct != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2387> Error encoding subfield CCBSAct\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 7);Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2388> Error encoding subfield spare\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AllowedActionsCcbs (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AllowedActionsCcbs* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).CCBSAct = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CCBSAct___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2389> Error decoding subfield CCBSAct\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2389)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2390> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2390)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkCallControlCapabil (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkCallControlCapabil* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 7);Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2391> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).MCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2392> Error encoding subfield MCS\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkCallControlCapabil (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkCallControlCapabil* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2393> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2393)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).MCS = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MCS___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2394> Error decoding subfield MCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2394)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ServCategory (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ServCategory* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2395> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).AutomaticallyInitiatedECall != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2396> Error encoding subfield AutomaticallyInitiatedECall\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).ManuallyInitiatedECall != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2397> Error encoding subfield ManuallyInitiatedECall\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).MountainRescue != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2398> Error encoding subfield MountainRescue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MarineGuard != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2399> Error encoding subfield MarineGuard\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).FireBrigade != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2400> Error encoding subfield FireBrigade\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Ambulance != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2401> Error encoding subfield Ambulance\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).Police != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2402> Error encoding subfield Police\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ServCategory (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ServCategory* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2403> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2403)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).AutomaticallyInitiatedECall = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AutomaticallyInitiatedECall___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2404> Error decoding subfield AutomaticallyInitiatedECall\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2404)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).ManuallyInitiatedECall = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ManuallyInitiatedECall___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2405> Error decoding subfield ManuallyInitiatedECall\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2405)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).MountainRescue = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MountainRescue___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2406> Error decoding subfield MountainRescue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2406)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).MarineGuard = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MarineGuard___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2407> Error decoding subfield MarineGuard\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2407)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).FireBrigade = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FireBrigade___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2408> Error decoding subfield FireBrigade\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2408)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).Ambulance = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Ambulance___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2409> Error decoding subfield Ambulance\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2409)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).Police = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Police___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2410> Error decoding subfield Police\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2410)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).PNB_CIoT), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2411> Error encoding subfield PNB_CIoT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).SAF != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2412> Error encoding subfield SAF\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).AUTV != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2413> Error encoding subfield AUTV\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).PNB_CIoT = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PNB_CIoT___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2414> Error decoding subfield PNB_CIoT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2414)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).SAF = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SAF___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2415> Error decoding subfield SAF\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2415)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).AUTV = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AUTV___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2416> Error decoding subfield AUTV\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2416)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AttachResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AttachResult* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).FOP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2417> Error encoding subfield FOP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ResultOfAttach), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2418> Error encoding subfield ResultOfAttach\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AttachResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AttachResult* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).FOP = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FOP___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2419> Error decoding subfield FOP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2419)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ResultOfAttach = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ResultOfAttach___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2420> Error decoding subfield ResultOfAttach\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2420)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AttachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AttachType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).xFOR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2421> Error encoding subfield xFOR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfAttach), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2422> Error encoding subfield TypeOfAttach\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AttachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AttachType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).xFOR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).xFOR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2423> Error decoding subfield xFOR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2423)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfAttach = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfAttach___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2424> Error decoding subfield TypeOfAttach\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2424)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IntegrityProtectionAlgorithm (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IntegrityProtectionAlgorithm* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 5);Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2425> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TypeOfAlgorithm), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2426> Error encoding subfield TypeOfAlgorithm\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IntegrityProtectionAlgorithm (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IntegrityProtectionAlgorithm* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2427> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2427)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TypeOfAlgorithm = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfAlgorithm___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2428> Error decoding subfield TypeOfAlgorithm\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2428)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TmsiStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TmsiStatus* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2429> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TMSIFlag != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2430> Error encoding subfield TMSIFlag\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TmsiStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TmsiStatus* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2431> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2431)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TMSIFlag = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TMSIFlag___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2432> Error decoding subfield TMSIFlag\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2432)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DetachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DetachType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).PowerOff != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2433> Error encoding subfield PowerOff\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfDetach), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2434> Error encoding subfield TypeOfDetach\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DetachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DetachType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).PowerOff = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PowerOff___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2435> Error decoding subfield PowerOff\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2435)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfDetach = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfDetach___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2436> Error decoding subfield TypeOfDetach\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2436)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DrxParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DrxParam* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).SplitPgCycleCode), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2437> Error encoding subfield SplitPgCycleCode\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).CNSpecDRX), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2438> Error encoding subfield CNSpecDRX\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).SplitOnCCCH != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2439> Error encoding subfield SplitOnCCCH\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).nonDRXTimer), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2440> Error encoding subfield nonDRXTimer\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DrxParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DrxParam* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).SplitPgCycleCode = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SplitPgCycleCode___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2441> Error decoding subfield SplitPgCycleCode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2441)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).CNSpecDRX = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CNSpecDRX___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2442> Error decoding subfield CNSpecDRX\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2442)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).SplitOnCCCH = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SplitOnCCCH___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2443> Error decoding subfield SplitOnCCCH\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2443)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).nonDRXTimer = (unsigned char)EDBitsToInt (Buffer, CurrOfs+13, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).nonDRXTimer___LOCATOR), CurrOfs+13, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2444> Error decoding subfield nonDRXTimer\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2444)
	} 
#endif
	Len += Ret;
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RoutingAreaIdenti (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RoutingAreaIdenti* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 48;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2445> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2446> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2447> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2448> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2449> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2450> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2451> Error encoding subfield LAC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).RAC), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2452> Error encoding subfield RAC\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RoutingAreaIdenti (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RoutingAreaIdenti* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2453> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2453)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2454> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2454)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2455> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2455)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2456> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2456)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2457> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2457)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2458> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2458)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).LAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).LAC___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2459> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2459)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).RAC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+40), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RAC___LOCATOR), CurrOfs+40, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2460> Error decoding subfield RAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2460)
	} 
#endif
	Len += Ret;
	

	}
	return 48;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RoutingAreaIdenti2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RoutingAreaIdenti2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 48;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2461> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2462> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2463> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2464> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2465> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2466> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2467> Error encoding subfield LAC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).RAC), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2468> Error encoding subfield RAC\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RoutingAreaIdenti2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RoutingAreaIdenti2* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2469> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2469)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2470> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2470)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2471> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2471)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2472> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2472)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2473> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2473)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2474> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2474)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).LAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).LAC___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2475> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2475)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).RAC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+40), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RAC___LOCATOR), CurrOfs+40, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2476> Error decoding subfield RAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2476)
	} 
#endif
	Len += Ret;
	

	}
	return 48;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UpdateType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).xFOR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2477> Error encoding subfield xFOR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).UpdateTypeValue), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2478> Error encoding subfield UpdateTypeValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UpdateType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).xFOR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).xFOR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2479> Error decoding subfield xFOR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2479)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).UpdateTypeValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UpdateTypeValue___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2480> Error decoding subfield UpdateTypeValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2480)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSLCSCapabilit (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSLCSCapabilit* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2481> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).APC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2482> Error encoding subfield APC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).OTD_A != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2483> Error encoding subfield OTD_A\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).OTD_B != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2484> Error encoding subfield OTD_B\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).GPS_A != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2485> Error encoding subfield GPS_A\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).GPS_B != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2486> Error encoding subfield GPS_B\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).GPS_C != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2487> Error encoding subfield GPS_C\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSLCSCapabilit (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSLCSCapabilit* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2488> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2488)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).APC = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).APC___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2489> Error decoding subfield APC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2489)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).OTD_A = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OTD_A___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2490> Error decoding subfield OTD_A\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2490)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).OTD_B = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).OTD_B___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2491> Error decoding subfield OTD_B\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2491)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).GPS_A = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).GPS_A___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2492> Error decoding subfield GPS_A\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2492)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).GPS_B = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).GPS_B___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2493> Error decoding subfield GPS_B\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2493)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).GPS_C = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).GPS_C___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2494> Error decoding subfield GPS_C\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2494)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetworkFeatureSupport* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).LCS_MOLR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2495> Error encoding subfield LCS_MOLR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).MBMS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2496> Error encoding subfield MBMS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).IMSVoPS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2497> Error encoding subfield IMSVoPS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EMCBS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2498> Error encoding subfield EMCBS\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).LCS_MOLR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LCS_MOLR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2499> Error decoding subfield LCS_MOLR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2499)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).MBMS = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MBMS___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2500> Error decoding subfield MBMS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2500)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).IMSVoPS = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).IMSVoPS___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2501> Error decoding subfield IMSVoPS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2501)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EMCBS = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EMCBS___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2502> Error decoding subfield EMCBS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2502)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalNetworkFeatureSupport* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 7);Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2503> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).GPRS_SMS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2504> Error encoding subfield GPRS_SMS\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2505> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2505)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).GPRS_SMS = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).GPRS_SMS___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2506> Error decoding subfield GPRS_SMS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2506)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RequestedMSInformation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RequestedMSInformation* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).I_RAT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2507> Error encoding subfield I_RAT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).I_RAT2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2508> Error encoding subfield I_RAT2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+2, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2509> Error encoding subfield spare\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RequestedMSInformation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RequestedMSInformation* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).I_RAT = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).I_RAT___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2510> Error decoding subfield I_RAT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2510)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).I_RAT2 = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).I_RAT2___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2511> Error decoding subfield I_RAT2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2511)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2512> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2512)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VoiceDomainPreferenceAndUEsUsageSetting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 5);Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2513> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).UEUsageSetting != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2514> Error encoding subfield UEUsageSetting\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).VoiceDomainPreferenceForEUTRAN), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2515> Error encoding subfield VoiceDomainPreferenceForEUTRAN\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VoiceDomainPreferenceAndUEsUsageSetting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2516> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2516)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).UEUsageSetting = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UEUsageSetting___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2517> Error decoding subfield UEUsageSetting\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2517)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).VoiceDomainPreferenceForEUTRAN = (unsigned char)EDBitsToInt (Buffer, CurrOfs+6, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).VoiceDomainPreferenceForEUTRAN___LOCATOR), CurrOfs+6, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2518> Error decoding subfield VoiceDomainPreferenceForEUTRAN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2518)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PTMSI_Type (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PTMSI_Type* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2519> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).PTMSI_Type != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2520> Error encoding subfield PTMSI_Type\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PTMSI_Type (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PTMSI_Type* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2521> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2521)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).PTMSI_Type = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PTMSI_Type___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2522> Error decoding subfield PTMSI_Type\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2522)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetworkResourceIdContainer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetworkResourceIdContainer* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).NRIContainerValue), 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2523> Error encoding subfield NRIContainerValue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+10, 0, 6);Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2524> Error encoding subfield spare\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetworkResourceIdContainer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetworkResourceIdContainer* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).NRIContainerValue = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NRIContainerValue___LOCATOR), CurrOfs, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2525> Error decoding subfield NRIContainerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2525)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2526> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2526)
	} 
#endif
	Len += Ret;
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtendedDRXParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtendedDRXParameters* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).PagingTimeWindow), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2527> Error encoding subfield PagingTimeWindow\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).eDRXValue), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2528> Error encoding subfield eDRXValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtendedDRXParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtendedDRXParameters* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).PagingTimeWindow = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PagingTimeWindow___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2529> Error decoding subfield PagingTimeWindow\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2529)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).eDRXValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).eDRXValue___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2530> Error decoding subfield eDRXValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2530)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkServAccessPointId* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2531> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).NSAPIValue), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2532> Error encoding subfield NSAPIValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkServAccessPointId* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2533> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2533)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).NSAPIValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NSAPIValue___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2534> Error decoding subfield NSAPIValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2534)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PacketDataProtocolAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PacketDataProtocolAddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, CurrOfs, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2535> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).PDPTypeOrganisation), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2536> Error encoding subfield PDPTypeOrganisation\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).PDPTypeNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2537> Error encoding subfield PDPTypeNumber\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+16, (*Source).AddressInformation.value, 0, (*Source).AddressInformation.usedBits);
	Ret = (*Source).AddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2538> Error encoding subfield AddressInformation\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PacketDataProtocolAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PacketDataProtocolAddr* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2539> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2539)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).PDPTypeOrganisation = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PDPTypeOrganisation___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2540> Error decoding subfield PDPTypeOrganisation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2540)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).PDPTypeNumber = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PDPTypeNumber___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2541> Error decoding subfield PDPTypeNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2541)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).AddressInformation___LOCATOR), CurrOfs+16, (Length - 16));
	if ((Length - 16) > 0) {
		/* BINDEC02 */
		ALLOC_c_PacketDataProtocolAddr_AddressInformation (&((*Destin).AddressInformation), (Length - 16));
	
		if ((*Destin).AddressInformation.value) {
			EDCopyBits ((*Destin).AddressInformation.value, 0, Buffer, CurrOfs+16, (Length - 16));
			(*Destin).AddressInformation.usedBits = (Length - 16);
			Ret = (Length - 16);
	
		}
		else {
			(*Destin).AddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 16);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2542> Error decoding subfield AddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2542)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_QualityOfServ (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_QualityOfServ* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 128;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2543> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).DelayClass), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2544> Error encoding subfield DelayClass\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).ReliabilityClass), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2545> Error encoding subfield ReliabilityClass\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).PeakThroughput), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2546> Error encoding subfield PeakThroughput\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+12, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2547> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).PrecedenceClass), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2548> Error encoding subfield PrecedenceClass\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+16, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2549> Error encoding subfield spare3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).MeanThroughput), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2550> Error encoding subfield MeanThroughput\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).TrafficClass), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2551> Error encoding subfield TrafficClass\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+27), (int)((*Source).DeliveryOrder), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2552> Error encoding subfield DeliveryOrder\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+29), (int)((*Source).DeliveryOfErroneusSDU), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2553> Error encoding subfield DeliveryOfErroneusSDU\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).MaximumSDUSize), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2554> Error encoding subfield MaximumSDUSize\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).MaximumBitRateForUplink), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2555> Error encoding subfield MaximumBitRateForUplink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).MaximumBitRateForDownlink), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2556> Error encoding subfield MaximumBitRateForDownlink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+56), (int)((*Source).ResidualBER), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2557> Error encoding subfield ResidualBER\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+60), (int)((*Source).SDUErrorRatio), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2558> Error encoding subfield SDUErrorRatio\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+64), (int)((*Source).TransderDelay), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2559> Error encoding subfield TransderDelay\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+70), (int)((*Source).TrafficHandlingPriority), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2560> Error encoding subfield TrafficHandlingPriority\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+72), (int)((*Source).GuaranteedBitRateForUplink), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2561> Error encoding subfield GuaranteedBitRateForUplink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+80), (int)((*Source).GuaranteedBitRateForDownlink), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2562> Error encoding subfield GuaranteedBitRateForDownlink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+88, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2563> Error encoding subfield spare4\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+91), (int)((*Source).SignalingIndication != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2564> Error encoding subfield SignalingIndication\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+92), (int)((*Source).SourceStatisticsDescriptor), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2565> Error encoding subfield SourceStatisticsDescriptor\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+96), (int)((*Source).MaximumBitRateForDownlinkExt), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2566> Error encoding subfield MaximumBitRateForDownlinkExt\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+104), (int)((*Source).GuaranteedBitRateForDownlinkExt), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2567> Error encoding subfield GuaranteedBitRateForDownlinkExt\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+112), (int)((*Source).MaximumBitRateForUplinkExt), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2568> Error encoding subfield MaximumBitRateForUplinkExt\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+120), (int)((*Source).GuaranteedBitRateForUplinkExt), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2569> Error encoding subfield GuaranteedBitRateForUplinkExt\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+128), (int)((*Source).MaximumBitRateForDownlinkExt2), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2570> Error encoding subfield MaximumBitRateForDownlinkExt2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+136), (int)((*Source).GuaranteedBitRateForDownlinkExt2), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2571> Error encoding subfield GuaranteedBitRateForDownlinkExt2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+144), (int)((*Source).MaximumBitRateForUplinkExt2), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2572> Error encoding subfield MaximumBitRateForUplinkExt2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+152), (int)((*Source).GuaranteedBitRateForUplinkExt2), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2573> Error encoding subfield GuaranteedBitRateForUplinkExt2\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_QualityOfServ (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_QualityOfServ* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2574> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2574)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).DelayClass = (unsigned char)EDBitsToInt (Buffer, CurrOfs+2, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).DelayClass___LOCATOR), CurrOfs+2, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2575> Error decoding subfield DelayClass\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2575)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ReliabilityClass = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ReliabilityClass___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2576> Error decoding subfield ReliabilityClass\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2576)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).PeakThroughput = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PeakThroughput___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2577> Error decoding subfield PeakThroughput\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2577)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2578> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2578)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).PrecedenceClass = (unsigned char)EDBitsToInt (Buffer, CurrOfs+13, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PrecedenceClass___LOCATOR), CurrOfs+13, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2579> Error decoding subfield PrecedenceClass\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2579)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2580> Error decoding subfield spare3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2580)
	} 
#endif
	Len += Ret;
	
	/* FromBit=19 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MeanThroughput = (unsigned char)EDBitsToInt (Buffer, CurrOfs+19, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MeanThroughput___LOCATOR), CurrOfs+19, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2581> Error decoding subfield MeanThroughput\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2581)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).TrafficClass = (unsigned char)EDBitsToInt (Buffer, CurrOfs+24, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TrafficClass___LOCATOR), CurrOfs+24, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2582> Error decoding subfield TrafficClass\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2582)
	} 
#endif
	Len += Ret;
	
	/* FromBit=27 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).DeliveryOrder = (unsigned char)EDBitsToInt (Buffer, CurrOfs+27, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).DeliveryOrder___LOCATOR), CurrOfs+27, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2583> Error decoding subfield DeliveryOrder\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2583)
	} 
#endif
	Len += Ret;
	
	/* FromBit=29 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).DeliveryOfErroneusSDU = (unsigned char)EDBitsToInt (Buffer, CurrOfs+29, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).DeliveryOfErroneusSDU___LOCATOR), CurrOfs+29, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2584> Error decoding subfield DeliveryOfErroneusSDU\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2584)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumSDUSize = (unsigned char)EDBitsToInt (Buffer, CurrOfs+32, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaximumSDUSize___LOCATOR), CurrOfs+32, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2585> Error decoding subfield MaximumSDUSize\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2585)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForUplink = (unsigned char)EDBitsToInt (Buffer, CurrOfs+40, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForUplink___LOCATOR), CurrOfs+40, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2586> Error decoding subfield MaximumBitRateForUplink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2586)
	} 
#endif
	Len += Ret;
	
	/* FromBit=48 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForDownlink = (unsigned char)EDBitsToInt (Buffer, CurrOfs+48, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForDownlink___LOCATOR), CurrOfs+48, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2587> Error decoding subfield MaximumBitRateForDownlink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2587)
	} 
#endif
	Len += Ret;
	
	/* FromBit=56 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ResidualBER = (unsigned char)EDBitsToInt (Buffer, CurrOfs+56, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ResidualBER___LOCATOR), CurrOfs+56, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2588> Error decoding subfield ResidualBER\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2588)
	} 
#endif
	Len += Ret;
	
	/* FromBit=60 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).SDUErrorRatio = (unsigned char)EDBitsToInt (Buffer, CurrOfs+60, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SDUErrorRatio___LOCATOR), CurrOfs+60, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2589> Error decoding subfield SDUErrorRatio\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2589)
	} 
#endif
	Len += Ret;
	
	/* FromBit=64 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).TransderDelay = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+64), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TransderDelay___LOCATOR), CurrOfs+64, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2590> Error decoding subfield TransderDelay\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2590)
	} 
#endif
	Len += Ret;
	
	/* FromBit=70 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).TrafficHandlingPriority = (unsigned char)EDBitsToInt (Buffer, CurrOfs+70, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TrafficHandlingPriority___LOCATOR), CurrOfs+70, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2591> Error decoding subfield TrafficHandlingPriority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2591)
	} 
#endif
	Len += Ret;
	
	/* FromBit=72 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForUplink = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+72), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForUplink___LOCATOR), CurrOfs+72, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2592> Error decoding subfield GuaranteedBitRateForUplink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2592)
	} 
#endif
	Len += Ret;
	
	/* FromBit=80 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForDownlink = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+80), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForDownlink___LOCATOR), CurrOfs+80, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2593> Error decoding subfield GuaranteedBitRateForDownlink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2593)
	} 
#endif
	Len += Ret;
	
	/* FromBit=88 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2594> Error decoding subfield spare4\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2594)
	} 
#endif
	Len += Ret;
	
	/* FromBit=91 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).SignalingIndication = (EDBitsToInt (Buffer, CurrOfs+91, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SignalingIndication___LOCATOR), CurrOfs+91, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2595> Error decoding subfield SignalingIndication\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2595)
	} 
#endif
	Len += Ret;
	
	/* FromBit=92 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).SourceStatisticsDescriptor = (unsigned char)EDBitsToInt (Buffer, CurrOfs+92, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SourceStatisticsDescriptor___LOCATOR), CurrOfs+92, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2596> Error decoding subfield SourceStatisticsDescriptor\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2596)
	} 
#endif
	Len += Ret;
	
	/* FromBit=96 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForDownlinkExt = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+96), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForDownlinkExt___LOCATOR), CurrOfs+96, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2597> Error decoding subfield MaximumBitRateForDownlinkExt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2597)
	} 
#endif
	Len += Ret;
	
	/* FromBit=104 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForDownlinkExt = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+104), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForDownlinkExt___LOCATOR), CurrOfs+104, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2598> Error decoding subfield GuaranteedBitRateForDownlinkExt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2598)
	} 
#endif
	Len += Ret;
	
	/* FromBit=112 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForUplinkExt = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+112), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForUplinkExt___LOCATOR), CurrOfs+112, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2599> Error decoding subfield MaximumBitRateForUplinkExt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2599)
	} 
#endif
	Len += Ret;
	
	/* FromBit=120 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForUplinkExt = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+120), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForUplinkExt___LOCATOR), CurrOfs+120, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2600> Error decoding subfield GuaranteedBitRateForUplinkExt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2600)
	} 
#endif
	Len += Ret;
	
	/* FromBit=128 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForDownlinkExt2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+128), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForDownlinkExt2___LOCATOR), CurrOfs+128, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2601> Error decoding subfield MaximumBitRateForDownlinkExt2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2601)
	} 
#endif
	Len += Ret;
	
	/* FromBit=136 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForDownlinkExt2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+136), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForDownlinkExt2___LOCATOR), CurrOfs+136, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2602> Error decoding subfield GuaranteedBitRateForDownlinkExt2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2602)
	} 
#endif
	Len += Ret;
	
	/* FromBit=144 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MaximumBitRateForUplinkExt2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+144), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateForUplinkExt2___LOCATOR), CurrOfs+144, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2603> Error decoding subfield MaximumBitRateForUplinkExt2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2603)
	} 
#endif
	Len += Ret;
	
	/* FromBit=152 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).GuaranteedBitRateForUplinkExt2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+152), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GuaranteedBitRateForUplinkExt2___LOCATOR), CurrOfs+152, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2604> Error decoding subfield GuaranteedBitRateForUplinkExt2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2604)
	} 
#endif
	Len += Ret;
	

	}
	return 128;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ReAttemptIndicator (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ReAttemptIndicator* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 6);Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2605> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).EPLMNC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2606> Error encoding subfield EPLMNC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).RATC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2607> Error encoding subfield RATC\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ReAttemptIndicator (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ReAttemptIndicator* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2608> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2608)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).EPLMNC = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EPLMNC___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2609> Error decoding subfield EPLMNC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2609)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).RATC = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).RATC___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2610> Error decoding subfield RATC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2610)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMCause* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Cause), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2611> Error encoding subfield Cause\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMCause* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Cause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Cause___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2612> Error decoding subfield Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2612)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LlcServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LlcServAccessPointId* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2613> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).LLCSAPIValue), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2614> Error encoding subfield LLCSAPIValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LlcServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LlcServAccessPointId* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2615> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2615)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).LLCSAPIValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).LLCSAPIValue___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2616> Error decoding subfield LLCSAPIValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2616)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TearDownInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TearDownInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2617> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TDIFlag != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2618> Error encoding subfield TDIFlag\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TearDownInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TearDownInd* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2619> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2619)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TDIFlag = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TDIFlag___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2620> Error decoding subfield TDIFlag\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2620)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PacketFlowIdentifie (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PacketFlowIdentifie* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2621> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).PacketFlowIdentifierValue), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2622> Error encoding subfield PacketFlowIdentifierValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PacketFlowIdentifie (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PacketFlowIdentifie* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2623> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2623)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).PacketFlowIdentifierValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 7);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PacketFlowIdentifierValue___LOCATOR), CurrOfs+1, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2624> Error decoding subfield PacketFlowIdentifierValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2624)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TempMobileNumbers (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TempMobileNumbers* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2625> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+28), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2626> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2627> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+36), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2628> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2629> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+44), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2630> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TempMobileNumbers (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TempMobileNumbers* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=24 */
	(*Destin).MCC2 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+24, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs+24, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2631> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2631)
	} 
#endif
	Len += Ret;
	
	/* FromBit=28 */
	(*Destin).MCC1 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+28, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+28, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2632> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2632)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).MNC3 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+32, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+32, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2633> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2633)
	} 
#endif
	Len += Ret;
	
	/* FromBit=36 */
	(*Destin).MCC3 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+36, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+36, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2634> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2634)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).MNC2 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+40, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+40, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2635> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2635)
	} 
#endif
	Len += Ret;
	
	/* FromBit=44 */
	(*Destin).MNC1 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+44, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+44, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2636> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2636)
	} 
#endif
	Len += Ret;
	

	}
	return 24;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TempMobileGroupId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TempMobileGroupId* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MBMSServiceId), 24);
	Ret = 24;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2637> Error encoding subfield MBMSServiceId\n");
		return -1;
	} 
#endif
	Ret = ENCODE_c_TempMobileNumbers (Buffer, CurrOfs+24, (&((*Source).Numbers)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2638> Error encoding subfield Numbers\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TempMobileGroupId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TempMobileGroupId* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MBMSServiceId = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 24);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MBMSServiceId___LOCATOR), CurrOfs, 24);
	Ret = 24;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2639> Error decoding subfield MBMSServiceId\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2639)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	Ret = DECODE_c_TempMobileNumbers (Buffer, CurrOfs+24, (&((*Destin).Numbers)), (Length - 24));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2640> Error decoding subfield Numbers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2640)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMSBearerCapabilities (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMSBearerCapabilities* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MaximumBitRateDownlink), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2641> Error encoding subfield MaximumBitRateDownlink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MaximumBitRateDownlinkExt), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2642> Error encoding subfield MaximumBitRateDownlinkExt\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMSBearerCapabilities (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMSBearerCapabilities* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).MaximumBitRateDownlink = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateDownlink___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2643> Error decoding subfield MaximumBitRateDownlink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2643)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MaximumBitRateDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaximumBitRateDownlinkExt___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2644> Error decoding subfield MaximumBitRateDownlinkExt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2644)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_WLANOffloadAcceptability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_WLANOffloadAcceptability* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2645> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).UTRANOffloadAcceptabilityValue != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2646> Error encoding subfield UTRANOffloadAcceptabilityValue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EUTRANOffloadAcceptabilityValue != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2647> Error encoding subfield EUTRANOffloadAcceptabilityValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_WLANOffloadAcceptability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_WLANOffloadAcceptability* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2648> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2648)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).UTRANOffloadAcceptabilityValue = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UTRANOffloadAcceptabilityValue___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2649> Error decoding subfield UTRANOffloadAcceptabilityValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2649)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EUTRANOffloadAcceptabilityValue = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EUTRANOffloadAcceptabilityValue___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2650> Error decoding subfield EUTRANOffloadAcceptabilityValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2650)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Unit), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2651> Error encoding subfield Unit\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TimerValue), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2652> Error encoding subfield TimerValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Unit = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Unit___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2653> Error decoding subfield Unit\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2653)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TimerValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TimerValue___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2654> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2654)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Unit), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2655> Error encoding subfield Unit\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TimerValue), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2656> Error encoding subfield TimerValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer2* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Unit = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Unit___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2657> Error decoding subfield Unit\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2657)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TimerValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TimerValue___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2658> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2658)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer3* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Unit), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2659> Error encoding subfield Unit\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TimerValue), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2660> Error encoding subfield TimerValue\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer3* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).Unit = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Unit___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2661> Error decoding subfield Unit\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2661)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TimerValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TimerValue___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2662> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2662)
	} 
#endif
	Len += Ret;
	

	}
	return 8;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UplinkDataStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UplinkDataStatus* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).NSAPI_07 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2663> Error encoding subfield NSAPI_07\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).NSAPI_06 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2664> Error encoding subfield NSAPI_06\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).NSAPI_05 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2665> Error encoding subfield NSAPI_05\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+3, 0, 5);Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2666> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).NSAPI_15 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2667> Error encoding subfield NSAPI_15\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).NSAPI_14 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2668> Error encoding subfield NSAPI_14\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).NSAPI_13 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2669> Error encoding subfield NSAPI_13\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).NSAPI_12 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2670> Error encoding subfield NSAPI_12\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).NSAPI_11 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2671> Error encoding subfield NSAPI_11\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).NSAPI_10 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2672> Error encoding subfield NSAPI_10\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).NSAPI_09 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2673> Error encoding subfield NSAPI_09\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).NSAPI_08 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2674> Error encoding subfield NSAPI_08\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UplinkDataStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UplinkDataStatus* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	(*Destin).NSAPI_07 = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_07___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2675> Error decoding subfield NSAPI_07\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2675)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).NSAPI_06 = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_06___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2676> Error decoding subfield NSAPI_06\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2676)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).NSAPI_05 = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_05___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2677> Error decoding subfield NSAPI_05\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2677)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2678> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2678)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).NSAPI_15 = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_15___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2679> Error decoding subfield NSAPI_15\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2679)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).NSAPI_14 = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_14___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2680> Error decoding subfield NSAPI_14\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2680)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).NSAPI_13 = (EDBitsToInt (Buffer, CurrOfs+10, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_13___LOCATOR), CurrOfs+10, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2681> Error decoding subfield NSAPI_13\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2681)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).NSAPI_12 = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_12___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2682> Error decoding subfield NSAPI_12\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2682)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).NSAPI_11 = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_11___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2683> Error decoding subfield NSAPI_11\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2683)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).NSAPI_10 = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_10___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2684> Error decoding subfield NSAPI_10\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2684)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).NSAPI_09 = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_09___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2685> Error decoding subfield NSAPI_09\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2685)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).NSAPI_08 = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NSAPI_08___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2686> Error decoding subfield NSAPI_08\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2686)
	} 
#endif
	Len += Ret;
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DeviceProperties (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DeviceProperties* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2687> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).LowPriority != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2688> Error encoding subfield LowPriority\n");
		return -1;
	} 
#endif

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DeviceProperties (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DeviceProperties* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2689> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2689)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).LowPriority = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LowPriority___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2690> Error decoding subfield LowPriority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2690)
	} 
#endif
	Len += Ret;
	

	}
	return 4;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ASCII (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ASCII* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	EDCopyBits (Buffer, CurrOfs, (*Source).text.value, 0, (*Source).text.usedBits);
	Ret = (*Source).text.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2691> Error encoding subfield text\n");
		return -1;
	} 
#endif
	Len += Ret;

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ASCII (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ASCII* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=0 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).text___LOCATOR), CurrOfs, (Length - 0));
	if ((Length - 0) > 0) {
		/* BINDEC02 */
		ALLOC_c_ASCII_text (&((*Destin).text), (Length - 0));
	
		if ((*Destin).text.value) {
			EDCopyBits ((*Destin).text.value, 0, Buffer, CurrOfs, (Length - 0));
			(*Destin).text.usedBits = (Length - 0);
			Ret = (Length - 0);
	
		}
		else {
			(*Destin).text.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 0);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2692> Error decoding subfield text\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2692)
	} 
#endif
	Len += Ret;
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BackupBearerCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BackupBearerCapability* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).RadioChannelRequirement), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).CodingStd != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).TransferMode != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).InformationTransferCapability), 3);
	
	CurrOfs += 8;
	
	/* GROUP LEADER 4 OPT=1 */
	if (!(*Source).Compress_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Compress != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).Structure), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).DuplMode != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).Configured != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).NIRR != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+7), (int)((*Source).Established != 0 ? 1 : 0), 1);
	CurrOfs += 8;
	
	/* GROUP LEADER 5 OPT=1 */
	if (!(*Source).AccessId_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, (CurrOfs)+1, 0, 2);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).RateAdaption), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).SignallinAccessProtocol), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <5> */
	
	/* GROUP 5a OPT=1 */
	if (!(*Source).OtherITC_Present) goto end_of_group_2;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).OtherITC), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).OtherRateAdaption), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+5, 0, 3);
	CurrOfs += 8;
	
	end_of_group_2: /* END OF GROUP LEADER <5a> */
	
	/* GROUP LEADER 6 OPT=1 */
	if (!(*Source).Layer1id_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, (CurrOfs)+1, 1, 2);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).UserInfoLayer1Protocol), 4);
	
	EDIntToBits (Buffer, ((CurrOfs)+7), (int)((*Source).Asynchronous != 0 ? 1 : 0), 1);
	CurrOfs += 8;
	/* END OF GROUP <6> */
	
	/* GROUP 6a OPT=1 */
	if (!(*Source).NumbStopBits_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).NumbStopBits), 1);
	
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).Negotiations != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).NumbDataBits != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).UserRate), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <6a> */
	
	/* GROUP 6b OPT=1 */
	if (!(*Source).IntermedRate_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).IntermedRate), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).NIConTX != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NIConRX != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).Parity), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <6b> */
	
	/* GROUP 6c OPT=1 */
	if (!(*Source).ConnectionElement_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).ConnectionElement), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).ModemType), 5);
	
	CurrOfs += 8;
	/* END OF GROUP <6c> */
	
	/* GROUP 6d OPT=1 */
	if (!(*Source).OtherModemType_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).OtherModemType), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).FixedNetworkUserRate), 5);
	
	CurrOfs += 8;
	/* END OF GROUP <6d> */
	
	/* GROUP 6e OPT=1 */
	if (!(*Source).AcceptableChannelCodings_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).AcceptableChannelCodings), 4);
	
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).MaxNumOfTrafficChannels), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <6e> */
	
	/* GROUP 6f OPT=1 */
	if (!(*Source).UIMI_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).UIMI), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).WantedAirInterfUserRate), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <6f> */
	
	/* GROUP 6g OPT=1 */
	if (!(*Source).AcceptableChCodingsExt_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).AcceptableChCodingsExt), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).AsymmetryInd), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+6, 0, 2);
	CurrOfs += 8;
	
	end_of_group_3: /* END OF GROUP LEADER <6g> */
	
	/* GROUP LEADER 7 OPT=1 */
	if (!(*Source).Layer2id_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, (CurrOfs)+1, 2, 2);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).USerInfoLayer2Protocol), 5);
	
	CurrOfs += 8;
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BackupBearerCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BackupBearerCapability* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2693> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2693)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2694> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2694)
	}
	(*Destin).RadioChannelRequirement = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RadioChannelRequirement___LOCATOR), (CurrOfs)+1, 2);
	/* RadioChannelRequirement octet <3> <6>-<7> */
	(*Destin).CodingStd = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CodingStd___LOCATOR), (CurrOfs)+3, 1);
	/* CodingStd octet <3> <5>-<5> */
	(*Destin).TransferMode = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TransferMode___LOCATOR), (CurrOfs)+4, 1);
	/* TransferMode octet <3> <4>-<4> */
	(*Destin).InformationTransferCapability = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).InformationTransferCapability___LOCATOR), (CurrOfs)+5, 3);
	/* InformationTransferCapability octet <3> <1>-<3> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* GROUP LEADER 4 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2699> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2699)
	}
	(*Destin).Compress = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Compress___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_Compress (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Compress octet <4> <7>-<7> */
	(*Destin).Structure = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+2, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Structure___LOCATOR), (CurrOfs)+2, 2);
	/* Structure octet <4> <5>-<6> */
	(*Destin).DuplMode = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DuplMode___LOCATOR), (CurrOfs)+4, 1);
	/* DuplMode octet <4> <4>-<4> */
	(*Destin).Configured = (EDBitsToInt (Buffer, (CurrOfs)+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Configured___LOCATOR), (CurrOfs)+5, 1);
	/* Configured octet <4> <3>-<3> */
	(*Destin).NIRR = (EDBitsToInt (Buffer, (CurrOfs)+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NIRR___LOCATOR), (CurrOfs)+6, 1);
	/* NIRR octet <4> <2>-<2> */
	(*Destin).Established = (EDBitsToInt (Buffer, (CurrOfs)+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Established___LOCATOR), (CurrOfs)+7, 1);
	/* Established octet <4> <1>-<1> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* GROUP LEADER 5 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2706> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2706)
	}
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK14*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_AccessId (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* AccessId octet <5> <6>-<7> */
	(*Destin).RateAdaption = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RateAdaption___LOCATOR), (CurrOfs)+3, 2);
	/* RateAdaption octet <5> <4>-<5> */
	(*Destin).SignallinAccessProtocol = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SignallinAccessProtocol___LOCATOR), (CurrOfs)+5, 3);
	/* SignallinAccessProtocol octet <5> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <5> */
	
	/* GROUP 5a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_2;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2710> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2710)
	}
	(*Destin).OtherITC = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherITC___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_OtherITC (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* OtherITC octet <5a> <6>-<7> */
	(*Destin).OtherRateAdaption = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherRateAdaption___LOCATOR), (CurrOfs)+3, 2);
	/* OtherRateAdaption octet <5a> <4>-<5> */
	/* spare5a octet <5a> <1>-<3> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_2: /* END OF GROUP LEADER <5a> REP=<1> */
	
	/* GROUP LEADER 6 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2714> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2714)
	}
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK14*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_Layer1id (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Layer1id octet <6> <6>-<7> */
	(*Destin).UserInfoLayer1Protocol = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UserInfoLayer1Protocol___LOCATOR), (CurrOfs)+3, 4);
	/* UserInfoLayer1Protocol octet <6> <2>-<5> */
	(*Destin).Asynchronous = (EDBitsToInt (Buffer, (CurrOfs)+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Asynchronous___LOCATOR), (CurrOfs)+7, 1);
	/* Asynchronous octet <6> <1>-<1> */
	CurrOfs += 8;
	/* END OF GROUP <6> */
	
	/* GROUP 6a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2718> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2718)
	}
	(*Destin).NumbStopBits = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 1);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NumbStopBits___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_NumbStopBits (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* NumbStopBits octet <6a> <7>-<7> */
	(*Destin).Negotiations = (EDBitsToInt (Buffer, (CurrOfs)+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Negotiations___LOCATOR), (CurrOfs)+2, 1);
	/* Negotiations octet <6a> <6>-<6> */
	(*Destin).NumbDataBits = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NumbDataBits___LOCATOR), (CurrOfs)+3, 1);
	/* NumbDataBits octet <6a> <5>-<5> */
	(*Destin).UserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UserRate___LOCATOR), (CurrOfs)+4, 4);
	/* UserRate octet <6a> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <6a> */
	
	/* GROUP 6b OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2723> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2723)
	}
	(*Destin).IntermedRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).IntermedRate___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_IntermedRate (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* IntermedRate octet <6b> <6>-<7> */
	(*Destin).NIConTX = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NIConTX___LOCATOR), (CurrOfs)+3, 1);
	/* NIConTX octet <6b> <5>-<5> */
	(*Destin).NIConRX = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NIConRX___LOCATOR), (CurrOfs)+4, 1);
	/* NIConRX octet <6b> <4>-<4> */
	(*Destin).Parity = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Parity___LOCATOR), (CurrOfs)+5, 3);
	/* Parity octet <6b> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <6b> */
	
	/* GROUP 6c OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2728> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2728)
	}
	(*Destin).ConnectionElement = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ConnectionElement___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_ConnectionElement (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* ConnectionElement octet <6c> <6>-<7> */
	(*Destin).ModemType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ModemType___LOCATOR), (CurrOfs)+3, 5);
	/* ModemType octet <6c> <1>-<5> */
	CurrOfs += 8;
	/* END OF GROUP <6c> */
	
	/* GROUP 6d OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2731> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2731)
	}
	(*Destin).OtherModemType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherModemType___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_OtherModemType (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* OtherModemType octet <6d> <6>-<7> */
	(*Destin).FixedNetworkUserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).FixedNetworkUserRate___LOCATOR), (CurrOfs)+3, 5);
	/* FixedNetworkUserRate octet <6d> <1>-<5> */
	CurrOfs += 8;
	/* END OF GROUP <6d> */
	
	/* GROUP 6e OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2734> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2734)
	}
	(*Destin).AcceptableChannelCodings = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).AcceptableChannelCodings___LOCATOR), (CurrOfs)+1, 4);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_AcceptableChannelCodings (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* AcceptableChannelCodings octet <6e> <4>-<7> */
	(*Destin).MaxNumOfTrafficChannels = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaxNumOfTrafficChannels___LOCATOR), (CurrOfs)+5, 3);
	/* MaxNumOfTrafficChannels octet <6e> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <6e> */
	
	/* GROUP 6f OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2737> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2737)
	}
	(*Destin).UIMI = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UIMI___LOCATOR), (CurrOfs)+1, 3);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_UIMI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* UIMI octet <6f> <5>-<7> */
	(*Destin).WantedAirInterfUserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).WantedAirInterfUserRate___LOCATOR), (CurrOfs)+4, 4);
	/* WantedAirInterfUserRate octet <6f> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <6f> */
	
	/* GROUP 6g OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2740> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2740)
	}
	(*Destin).AcceptableChCodingsExt = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).AcceptableChCodingsExt___LOCATOR), (CurrOfs)+1, 3);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_AcceptableChCodingsExt (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* AcceptableChCodingsExt octet <6g> <5>-<7> */
	(*Destin).AsymmetryInd = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).AsymmetryInd___LOCATOR), (CurrOfs)+4, 2);
	/* AsymmetryInd octet <6g> <3>-<4> */
	/* spare6g octet <6g> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_3: /* END OF GROUP LEADER <6g> REP=<1> */
	
	/* GROUP LEADER 7 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2744> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2744)
	}
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK14*/(/*SETP2*/SETPRESENT_c_BackupBearerCapability_Layer2id (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Layer2id octet <7> <6>-<7> */
	(*Destin).USerInfoLayer2Protocol = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).USerInfoLayer2Protocol___LOCATOR), (CurrOfs)+3, 5);
	/* USerInfoLayer2Protocol octet <7> <1>-<5> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BearerCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BearerCpblty* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).RadioChannelRequirement), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).CodingStd != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).TransferMode != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).InformationTransferCapability), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (!(*Source).Coding1_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Coding1 != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).CTM != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+3, 0, 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).SpeechVersionIndicator1), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3a> */
	
	/* GROUP 3b OPT=1 */
	if (!(*Source).Coding2_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Coding2 != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+2, 0, 2);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).SpeechVersionIndicator2), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3b> */
	
	/* GROUP 3c OPT=1 */
	if (!(*Source).Coding3_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Coding3 != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+2, 0, 2);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).SpeechVersionIndicator3), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3c> */
	
	/* GROUP 3d OPT=1 */
	if (!(*Source).Coding4_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Coding4 != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+2, 0, 2);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).SpeechVersionIndicator4), 4);
	
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3d> */
	
	/* GROUP LEADER 4 OPT=1 */
	if (!(*Source).Compress_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Compress != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).Structure), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).DuplMode != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).Configuration != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).NIRR != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+7), (int)((*Source).Establishment != 0 ? 1 : 0), 1);
	CurrOfs += 8;
	
	/* GROUP LEADER 5 OPT=1 */
	if (!(*Source).AccessId_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).AccessId), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).RateAdaption), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).SignallingAccessProtocol), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <5> */
	
	/* GROUP 5a OPT=1 */
	if (!(*Source).OtherITC_Present) goto end_of_group_2;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).OtherITC), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).OtherRateAdaption), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+5, 0, 3);
	CurrOfs += 8;
	/* END OF GROUP <5a> */
	
	/* GROUP 5b OPT=1 */
	if (!(*Source).HDR_Present) goto end_of_group_2;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).HDR != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).MultiFrame != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).Mode != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).LLI != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).AssigNorE != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).IbmNeg != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+7, 0, 1);
	CurrOfs += 8;
	
	end_of_group_2: /* END OF GROUP LEADER <5b> */
	
	/* GROUP LEADER 6 OPT=1 */
	if (!(*Source).Layer1ID_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Layer1ID), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).UserInfoLayer1Protocol), 4);
	
	EDIntToBits (Buffer, ((CurrOfs)+7), (int)((*Source).ASync != 0 ? 1 : 0), 1);
	CurrOfs += 8;
	/* END OF GROUP <6> */
	
	/* GROUP 6a OPT=1 */
	if (!(*Source).NumbStopBits_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).NumbStopBits), 1);
	
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).Negotiation != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).NumbDataBits != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).UserRate), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <6a> */
	
	/* GROUP 6b OPT=1 */
	if (!(*Source).IntermediateRate_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).IntermediateRate), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).NICOnTX != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NICOnRX != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).Parity), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <6b> */
	
	/* GROUP 6c OPT=1 */
	if (!(*Source).ConnectionElement_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).ConnectionElement), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).ModemType), 5);
	
	CurrOfs += 8;
	/* END OF GROUP <6c> */
	
	/* GROUP 6d OPT=1 */
	if (!(*Source).OtherModemType_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).OtherModemType), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).FixedNetworkUserRate), 5);
	
	CurrOfs += 8;
	/* END OF GROUP <6d> */
	
	/* GROUP 6e OPT=1 */
	if (!(*Source).TCH_F14_4_acceptable_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TCH_F14_4_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, (CurrOfs)+2, 0, 1);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).TCH_F9_6_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).TCH_F4_8_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).MaxNumberOfTrafficChannels), 3);
	
	CurrOfs += 8;
	/* END OF GROUP <6e> */
	
	/* GROUP 6f OPT=1 */
	if (!(*Source).UIMI_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).UIMI), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).WantedAirInterfaceUserRate), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <6f> */
	
	/* GROUP 6g OPT=1 */
	if (!(*Source).TCH_F28_8_acceptable_Present) goto end_of_group_3;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TCH_F28_8_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+2), (int)((*Source).TCH_F32_0_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).TCH_F43_2_acceptable != 0 ? 1 : 0), 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).AsymmetryIndication), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+6, 0, 2);
	CurrOfs += 8;
	
	end_of_group_3: /* END OF GROUP LEADER <6g> */
	
	/* GROUP LEADER 7 OPT=1 */
	if (!(*Source).Layer2ID_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, (CurrOfs)+1, 2, 2);
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).UserInfoLayer2Protocol), 5);
	
	CurrOfs += 8;
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BearerCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BearerCpblty* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2747> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2747)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2748> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2748)
	}
	(*Destin).RadioChannelRequirement = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RadioChannelRequirement___LOCATOR), (CurrOfs)+1, 2);
	/* RadioChannelRequirement octet <3> <6>-<7> */
	(*Destin).CodingStd = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CodingStd___LOCATOR), (CurrOfs)+3, 1);
	/* CodingStd octet <3> <5>-<5> */
	(*Destin).TransferMode = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TransferMode___LOCATOR), (CurrOfs)+4, 1);
	/* TransferMode octet <3> <4>-<4> */
	(*Destin).InformationTransferCapability = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).InformationTransferCapability___LOCATOR), (CurrOfs)+5, 3);
	/* InformationTransferCapability octet <3> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2753> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2753)
	}
	(*Destin).Coding1 = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Coding1___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Coding1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Coding1 octet <3a> <7>-<7> */
	(*Destin).CTM = (EDBitsToInt (Buffer, (CurrOfs)+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CTM___LOCATOR), (CurrOfs)+2, 1);
	/* CTM octet <3a> <6>-<6> */
	/* spare3a octet <3a> <5>-<5> */
	(*Destin).SpeechVersionIndicator1 = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SpeechVersionIndicator1___LOCATOR), (CurrOfs)+4, 4);
	/* SpeechVersionIndicator1 octet <3a> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3a> */
	
	/* GROUP 3b OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2758> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2758)
	}
	(*Destin).Coding2 = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Coding2___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Coding2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Coding2 octet <3b> <7>-<7> */
	/* spare3b octet <3b> <5>-<6> */
	(*Destin).SpeechVersionIndicator2 = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SpeechVersionIndicator2___LOCATOR), (CurrOfs)+4, 4);
	/* SpeechVersionIndicator2 octet <3b> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3b> */
	
	/* GROUP 3c OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2762> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2762)
	}
	(*Destin).Coding3 = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Coding3___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Coding3 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Coding3 octet <3c> <7>-<7> */
	/* spare3c octet <3c> <5>-<6> */
	(*Destin).SpeechVersionIndicator3 = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SpeechVersionIndicator3___LOCATOR), (CurrOfs)+4, 4);
	/* SpeechVersionIndicator3 octet <3c> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3c> */
	
	/* GROUP 3d OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2766> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2766)
	}
	(*Destin).Coding4 = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Coding4___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Coding4 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Coding4 octet <3d> <7>-<7> */
	/* spare3d octet <3d> <5>-<6> */
	(*Destin).SpeechVersionIndicator4 = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SpeechVersionIndicator4___LOCATOR), (CurrOfs)+4, 4);
	/* SpeechVersionIndicator4 octet <3d> <1>-<4> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3d> REP=<1> */
	
	/* GROUP LEADER 4 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2770> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2770)
	}
	(*Destin).Compress = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Compress___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Compress (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Compress octet <4> <7>-<7> */
	(*Destin).Structure = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+2, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Structure___LOCATOR), (CurrOfs)+2, 2);
	/* Structure octet <4> <5>-<6> */
	(*Destin).DuplMode = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DuplMode___LOCATOR), (CurrOfs)+4, 1);
	/* DuplMode octet <4> <4>-<4> */
	(*Destin).Configuration = (EDBitsToInt (Buffer, (CurrOfs)+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Configuration___LOCATOR), (CurrOfs)+5, 1);
	/* Configuration octet <4> <3>-<3> */
	(*Destin).NIRR = (EDBitsToInt (Buffer, (CurrOfs)+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NIRR___LOCATOR), (CurrOfs)+6, 1);
	/* NIRR octet <4> <2>-<2> */
	(*Destin).Establishment = (EDBitsToInt (Buffer, (CurrOfs)+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Establishment___LOCATOR), (CurrOfs)+7, 1);
	/* Establishment octet <4> <1>-<1> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* GROUP LEADER 5 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2777> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2777)
	}
	(*Destin).AccessId = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).AccessId___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_AccessId (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* AccessId octet <5> <6>-<7> */
	(*Destin).RateAdaption = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).RateAdaption___LOCATOR), (CurrOfs)+3, 2);
	/* RateAdaption octet <5> <4>-<5> */
	(*Destin).SignallingAccessProtocol = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SignallingAccessProtocol___LOCATOR), (CurrOfs)+5, 3);
	/* SignallingAccessProtocol octet <5> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <5> */
	
	/* GROUP 5a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_2;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2781> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2781)
	}
	(*Destin).OtherITC = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherITC___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_OtherITC (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* OtherITC octet <5a> <6>-<7> */
	(*Destin).OtherRateAdaption = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherRateAdaption___LOCATOR), (CurrOfs)+3, 2);
	/* OtherRateAdaption octet <5a> <4>-<5> */
	/* spare5a octet <5a> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <5a> */
	
	/* GROUP 5b OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_2;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2785> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2785)
	}
	(*Destin).HDR = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).HDR___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_HDR (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* HDR octet <5b> <7>-<7> */
	(*Destin).MultiFrame = (EDBitsToInt (Buffer, (CurrOfs)+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MultiFrame___LOCATOR), (CurrOfs)+2, 1);
	/* MultiFrame octet <5b> <6>-<6> */
	(*Destin).Mode = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Mode___LOCATOR), (CurrOfs)+3, 1);
	/* Mode octet <5b> <5>-<5> */
	(*Destin).LLI = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LLI___LOCATOR), (CurrOfs)+4, 1);
	/* LLI octet <5b> <4>-<4> */
	(*Destin).AssigNorE = (EDBitsToInt (Buffer, (CurrOfs)+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AssigNorE___LOCATOR), (CurrOfs)+5, 1);
	/* AssigNorE octet <5b> <3>-<3> */
	(*Destin).IbmNeg = (EDBitsToInt (Buffer, (CurrOfs)+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).IbmNeg___LOCATOR), (CurrOfs)+6, 1);
	/* IbmNeg octet <5b> <2>-<2> */
	/* spare5b octet <5b> <1>-<1> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_2: /* END OF GROUP LEADER <5b> REP=<1> */
	
	/* GROUP LEADER 6 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2793> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2793)
	}
	(*Destin).Layer1ID = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Layer1ID___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Layer1ID (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Layer1ID octet <6> <6>-<7> */
	(*Destin).UserInfoLayer1Protocol = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+3), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).UserInfoLayer1Protocol___LOCATOR), (CurrOfs)+3, 4);
	/* UserInfoLayer1Protocol octet <6> <2>-<5> */
	(*Destin).ASync = (EDBitsToInt (Buffer, (CurrOfs)+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ASync___LOCATOR), (CurrOfs)+7, 1);
	/* ASync octet <6> <1>-<1> */
	CurrOfs += 8;
	/* END OF GROUP <6> */
	
	/* GROUP 6a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2797> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2797)
	}
	(*Destin).NumbStopBits = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 1);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NumbStopBits___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_NumbStopBits (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* NumbStopBits octet <6a> <7>-<7> */
	(*Destin).Negotiation = (EDBitsToInt (Buffer, (CurrOfs)+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Negotiation___LOCATOR), (CurrOfs)+2, 1);
	/* Negotiation octet <6a> <6>-<6> */
	(*Destin).NumbDataBits = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NumbDataBits___LOCATOR), (CurrOfs)+3, 1);
	/* NumbDataBits octet <6a> <5>-<5> */
	(*Destin).UserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UserRate___LOCATOR), (CurrOfs)+4, 4);
	/* UserRate octet <6a> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <6a> */
	
	/* GROUP 6b OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2802> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2802)
	}
	(*Destin).IntermediateRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).IntermediateRate___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_IntermediateRate (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* IntermediateRate octet <6b> <6>-<7> */
	(*Destin).NICOnTX = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NICOnTX___LOCATOR), (CurrOfs)+3, 1);
	/* NICOnTX octet <6b> <5>-<5> */
	(*Destin).NICOnRX = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NICOnRX___LOCATOR), (CurrOfs)+4, 1);
	/* NICOnRX octet <6b> <4>-<4> */
	(*Destin).Parity = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Parity___LOCATOR), (CurrOfs)+5, 3);
	/* Parity octet <6b> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <6b> */
	
	/* GROUP 6c OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2807> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2807)
	}
	(*Destin).ConnectionElement = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ConnectionElement___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_ConnectionElement (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* ConnectionElement octet <6c> <6>-<7> */
	(*Destin).ModemType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ModemType___LOCATOR), (CurrOfs)+3, 5);
	/* ModemType octet <6c> <1>-<5> */
	CurrOfs += 8;
	/* END OF GROUP <6c> */
	
	/* GROUP 6d OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2810> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2810)
	}
	(*Destin).OtherModemType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).OtherModemType___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_OtherModemType (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* OtherModemType octet <6d> <6>-<7> */
	(*Destin).FixedNetworkUserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).FixedNetworkUserRate___LOCATOR), (CurrOfs)+3, 5);
	/* FixedNetworkUserRate octet <6d> <1>-<5> */
	CurrOfs += 8;
	/* END OF GROUP <6d> */
	
	/* GROUP 6e OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2813> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2813)
	}
	(*Destin).TCH_F14_4_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F14_4_acceptable___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_TCH_F14_4_acceptable (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* TCH_F14_4_acceptable octet <6e> <7>-<7> */
	/* spare6e octet <6e> <6>-<6> */
	(*Destin).TCH_F9_6_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F9_6_acceptable___LOCATOR), (CurrOfs)+3, 1);
	/* TCH_F9_6_acceptable octet <6e> <5>-<5> */
	(*Destin).TCH_F4_8_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F4_8_acceptable___LOCATOR), (CurrOfs)+4, 1);
	/* TCH_F4_8_acceptable octet <6e> <4>-<4> */
	(*Destin).MaxNumberOfTrafficChannels = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).MaxNumberOfTrafficChannels___LOCATOR), (CurrOfs)+5, 3);
	/* MaxNumberOfTrafficChannels octet <6e> <1>-<3> */
	CurrOfs += 8;
	/* END OF GROUP <6e> */
	
	/* GROUP 6f OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2819> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2819)
	}
	(*Destin).UIMI = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UIMI___LOCATOR), (CurrOfs)+1, 3);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_UIMI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* UIMI octet <6f> <5>-<7> */
	(*Destin).WantedAirInterfaceUserRate = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).WantedAirInterfaceUserRate___LOCATOR), (CurrOfs)+4, 4);
	/* WantedAirInterfaceUserRate octet <6f> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <6f> */
	
	/* GROUP 6g OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_3;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2822> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2822)
	}
	(*Destin).TCH_F28_8_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F28_8_acceptable___LOCATOR), (CurrOfs)+1, 1);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BearerCpblty_TCH_F28_8_acceptable (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* TCH_F28_8_acceptable octet <6g> <7>-<7> */
	(*Destin).TCH_F32_0_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F32_0_acceptable___LOCATOR), (CurrOfs)+2, 1);
	/* TCH_F32_0_acceptable octet <6g> <6>-<6> */
	(*Destin).TCH_F43_2_acceptable = (EDBitsToInt (Buffer, (CurrOfs)+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TCH_F43_2_acceptable___LOCATOR), (CurrOfs)+3, 1);
	/* TCH_F43_2_acceptable octet <6g> <5>-<5> */
	(*Destin).AsymmetryIndication = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).AsymmetryIndication___LOCATOR), (CurrOfs)+4, 2);
	/* AsymmetryIndication octet <6g> <3>-<4> */
	/* spare6g octet <6g> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_3: /* END OF GROUP LEADER <6g> REP=<1> */
	
	/* GROUP LEADER 7 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2828> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2828)
	}
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK14*/(/*SETP2*/SETPRESENT_c_BearerCpblty_Layer2ID (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Layer2ID octet <7> <6>-<7> */
	(*Destin).UserInfoLayer2Protocol = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).UserInfoLayer2Protocol___LOCATOR), (CurrOfs)+3, 5);
	/* UserInfoLayer2Protocol octet <7> <1>-<5> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CalledPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CalledPartyBcdNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TypeOfNumber), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NumberingPlanIdent), 4);
	
	CurrOfs += 8;
	
	/* Number REMAINDER */
	Ret = ENCODE_c_TBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2831> Error encoding remainder of CalledPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2831)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CalledPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CalledPartyBcdNum* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2832> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2832)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2833> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2833)
	}
	(*Destin).TypeOfNumber = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfNumber___LOCATOR), (CurrOfs)+1, 3);
	/* TypeOfNumber octet <3> <5>-<7> */
	(*Destin).NumberingPlanIdent = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NumberingPlanIdent___LOCATOR), (CurrOfs)+4, 4);
	/* NumberingPlanIdent octet <3> <1>-<4> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* Number REMAINDER */
	Ret = DECODE_c_TBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2836> Error decoding remainder of CalledPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2836)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallingPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallingPartyBcdNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TypeOfNumber), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NumberingPlanIdent), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (!(*Source).PresentationIndicator_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).PresentationIndicator), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+3, 0, 3);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).ScreeningIndicator), 2);
	
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> */
	
	/* Number REMAINDER */
	Ret = ENCODE_c_TBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2837> Error encoding remainder of CallingPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2837)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallingPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallingPartyBcdNum* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2838> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2838)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2839> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2839)
	}
	(*Destin).TypeOfNumber = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfNumber___LOCATOR), (CurrOfs)+1, 3);
	/* TypeOfNumber octet <3> <5>-<7> */
	(*Destin).NumberingPlanIdent = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NumberingPlanIdent___LOCATOR), (CurrOfs)+4, 4);
	/* NumberingPlanIdent octet <3> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2842> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2842)
	}
	(*Destin).PresentationIndicator = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PresentationIndicator___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CallingPartyBcdNum_PresentationIndicator (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* PresentationIndicator octet <3a> <6>-<7> */
	/* spare octet <3a> <3>-<5> */
	(*Destin).ScreeningIndicator = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+6, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ScreeningIndicator___LOCATOR), (CurrOfs)+6, 2);
	/* ScreeningIndicator octet <3a> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> REP=<1> */
	
	/* Number REMAINDER */
	Ret = DECODE_c_TBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2846> Error decoding remainder of CallingPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2846)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Cause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Cause* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).CodingStandard), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+3, 0, 1);
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).Location), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (!(*Source).Recommendation_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).Recommendation), 7);
	
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> */
	
	/* GROUP LEADER 4 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).CauseValue), 7);
	
	CurrOfs += 8;
	
	/* diagnostic REMAINDER */
	EDCopyBits (Buffer, CurrOfs, (*Source).diagnostic.value, 0, (*Source).diagnostic.usedBits);
	Ret = (*Source).diagnostic.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2847> Error encoding remainder of Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2847)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Cause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Cause* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2848> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2848)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2849> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2849)
	}
	(*Destin).CodingStandard = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CodingStandard___LOCATOR), (CurrOfs)+1, 2);
	/* CodingStandard octet <3> <6>-<7> */
	/* spare octet <3> <5>-<5> */
	(*Destin).Location = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Location___LOCATOR), (CurrOfs)+4, 4);
	/* Location octet <3> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2853> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2853)
	}
	(*Destin).Recommendation = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Recommendation___LOCATOR), (CurrOfs)+1, 7);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_Cause_Recommendation (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* Recommendation octet <3a> <1>-<7> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> REP=<1> */
	
	/* GROUP LEADER 4 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2855> Error decoding 0/1ext IE: missing mandatory group 4\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2855)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2856> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2856)
	}
	(*Destin).CauseValue = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 7);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CauseValue___LOCATOR), (CurrOfs)+1, 7);
	/* CauseValue octet <4> <1>-<7> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* diagnostic REMAINDER */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).diagnostic___LOCATOR), CurrOfs, (Length+BitOffset - CurrOfs));
	if ((Length+BitOffset - CurrOfs) > 0) {
		/* BINDEC02 */
		ALLOC_c_Cause_diagnostic (&((*Destin).diagnostic), (Length+BitOffset - CurrOfs));
	
		if ((*Destin).diagnostic.value) {
			EDCopyBits ((*Destin).diagnostic.value, 0, Buffer, CurrOfs, (Length+BitOffset - CurrOfs));
			(*Destin).diagnostic.usedBits = (Length+BitOffset - CurrOfs);
			Ret = (Length+BitOffset - CurrOfs);
	
		}
		else {
			(*Destin).diagnostic.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length+BitOffset - CurrOfs);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2858> Error decoding remainder of Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2858)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ConnNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ConnNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TypeOfNumber), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NumberingPlanIdent), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (!(*Source).PresentationIndicator_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).PresentationIndicator), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+3, 0, 3);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).ScreeningIndicator), 2);
	
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> */
	
	/* Number REMAINDER */
	Ret = ENCODE_c_TBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2859> Error encoding remainder of ConnNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2859)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ConnNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ConnNum* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2860> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2860)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2861> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2861)
	}
	(*Destin).TypeOfNumber = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TypeOfNumber___LOCATOR), (CurrOfs)+1, 3);
	/* TypeOfNumber octet <3> <5>-<7> */
	(*Destin).NumberingPlanIdent = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NumberingPlanIdent___LOCATOR), (CurrOfs)+4, 4);
	/* NumberingPlanIdent octet <3> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2864> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2864)
	}
	(*Destin).PresentationIndicator = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PresentationIndicator___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ConnNum_PresentationIndicator (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* PresentationIndicator octet <3a> <6>-<7> */
	/* spare octet <3a> <3>-<5> */
	(*Destin).ScreeningIndicator = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+6), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ScreeningIndicator___LOCATOR), (CurrOfs)+6, 2);
	/* ScreeningIndicator octet <3a> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> REP=<1> */
	
	/* Number REMAINDER */
	Ret = DECODE_c_TBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2868> Error decoding remainder of ConnNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2868)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HighLayerCpbility (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HighLayerCpbility* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=1 */
	if (!(*Source).CodingStandard_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).CodingStandard), 2);
	
	EDIntToBits (Buffer, ((CurrOfs)+3), (int)((*Source).Interpretation), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).PresentationMethod), 2);
	
	CurrOfs += 8;
	
	/* GROUP LEADER 4 OPT=1 */
	if (!(*Source).HighLayerCharacteristicsId_Present) goto opt_exit;
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).HighLayerCharacteristicsId), 7);
	
	CurrOfs += 8;
	/* END OF GROUP <4> */
	
	/* GROUP 4a OPT=1 */
	if (!(*Source).ExtHighLayerCharacteristicsId_Present) goto end_of_group_1;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).ExtHighLayerCharacteristicsId), 7);
	
	CurrOfs += 8;
	
	end_of_group_1: /* END OF GROUP LEADER <4a> */
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HighLayerCpbility (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HighLayerCpbility* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2869> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2869)
	}
	(*Destin).CodingStandard = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CodingStandard___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_HighLayerCpbility_CodingStandard (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* CodingStandard octet <3> <6>-<7> */
	(*Destin).Interpretation = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+3), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Interpretation___LOCATOR), (CurrOfs)+3, 3);
	/* Interpretation octet <3> <3>-<5> */
	(*Destin).PresentationMethod = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+6), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PresentationMethod___LOCATOR), (CurrOfs)+6, 2);
	/* PresentationMethod octet <3> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* GROUP LEADER 4 OPT=1 */
	if (CurrOfs >= Length+BitOffset)  goto opt_exit;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2873> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2873)
	}
	(*Destin).HighLayerCharacteristicsId = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HighLayerCharacteristicsId___LOCATOR), (CurrOfs)+1, 7);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_HighLayerCpbility_HighLayerCharacteristicsId (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* HighLayerCharacteristicsId octet <4> <1>-<7> */
	CurrOfs += 8;
	/* END OF GROUP <4> */
	
	/* GROUP 4a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_1;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2875> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2875)
	}
	(*Destin).ExtHighLayerCharacteristicsId = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ExtHighLayerCharacteristicsId___LOCATOR), (CurrOfs)+1, 7);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_HighLayerCpbility_ExtHighLayerCharacteristicsId (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* ExtHighLayerCharacteristicsId octet <4a> <1>-<7> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_1: /* END OF GROUP LEADER <4a> REP=<1> */
	opt_exit:

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RedirPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RedirPartyBcdNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 3 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).TypeOfNumber), 3);
	
	EDIntToBits (Buffer, ((CurrOfs)+4), (int)((*Source).NumberingPlanIdent), 4);
	
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (!(*Source).PresentationIndicator_Present) goto end_of_group_0;
	EDIntToBits (Buffer, CurrOfs-8, 0, 1); /* Set previous octet 0/1ext bit to 0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, ((CurrOfs)+1), (int)((*Source).PresentationIndicator), 2);
	
	EDIntToBits (Buffer, (CurrOfs)+3, 0, 3);
	EDIntToBits (Buffer, ((CurrOfs)+6), (int)((*Source).ScreeningIndicator), 2);
	
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> */
	
	/* Number REMAINDER */
	Ret = ENCODE_c_TBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2877> Error encoding remainder of RedirPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2877)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RedirPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RedirPartyBcdNum* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 3 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2878> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2878)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2879> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2879)
	}
	(*Destin).TypeOfNumber = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TypeOfNumber___LOCATOR), (CurrOfs)+1, 3);
	/* TypeOfNumber octet <3> <5>-<7> */
	(*Destin).NumberingPlanIdent = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NumberingPlanIdent___LOCATOR), (CurrOfs)+4, 4);
	/* NumberingPlanIdent octet <3> <1>-<4> */
	CurrOfs += 8;
	/* END OF GROUP <3> */
	
	/* GROUP 3a OPT=1 */
	if (EDBitsToInt (Buffer, CurrOfs-8, 1) != 0) goto end_of_group_0;
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:2882> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2882)
	}
	(*Destin).PresentationIndicator = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+1), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PresentationIndicator___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RedirPartyBcdNum_PresentationIndicator (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	/* PresentationIndicator octet <3a> <6>-<7> */
	/* spare octet <3a> <3>-<5> */
	(*Destin).ScreeningIndicator = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+6), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ScreeningIndicator___LOCATOR), (CurrOfs)+6, 2);
	/* ScreeningIndicator octet <3a> <1>-<2> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	end_of_group_0: /* END OF GROUP LEADER <3a> REP=<1> */
	
	/* Number REMAINDER */
	Ret = DECODE_c_TBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:2886> Error decoding remainder of RedirPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (2886)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PlmnList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PlmnList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_Plmn (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2887> Error encoding sequence PlmnList\n");
			return -1;
		} 
#endif

		CurrOfs += length;
		ret += length;
	}
	return ret;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PlmnList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PlmnList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<5) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_PlmnList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_Plmn (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2888> Error decoding sequence PlmnList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (2888)
		} 
#endif
		len += ret;
		CurrOfs += ret;
		Length -= ret;
	}
	return len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EmergencyNumberList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EmergencyNumberList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_TBCDEmergencyNumber (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2889> Error encoding sequence EmergencyNumberList\n");
			return -1;
		} 
#endif

		CurrOfs += length;
		ret += length;
	}
	return ret;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EmergencyNumberList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EmergencyNumberList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<6) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_EmergencyNumberList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_TBCDEmergencyNumber (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2890> Error decoding sequence EmergencyNumberList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (2890)
		} 
#endif
		len += ret;
		CurrOfs += ret;
		Length -= ret;
	}
	return len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SupportedCodecList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SupportedCodecList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_SupportedCodec (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2891> Error encoding sequence SupportedCodecList\n");
			return -1;
		} 
#endif

		CurrOfs += length;
		ret += length;
	}
	return ret;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SupportedCodecList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SupportedCodecList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<6) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_SupportedCodecList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_SupportedCodec (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2892> Error decoding sequence SupportedCodecList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (2892)
		} 
#endif
		len += ret;
		CurrOfs += ret;
		Length -= ret;
	}
	return len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId_Identity* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i;
		
		if (Source->IdentityType == 4) {
	  	/* Push digit 1 */
 			PUSH_INT (0xf4, 8);
 			
 			/* Push the values */
 			for (i=0; i<Source->IdentityDigit.items; i++) {
 				PUSH_INT (Source->IdentityDigit.data [i], 8);
 			}
			return (Source->IdentityDigit.items + 1) << 3;
		} else {
			
	  	/* Push digit 1 */
	 		PUSH_INT (Source->IdentityDigit.items == 0? 15 : Source->IdentityDigit.data [0], 4);
	
	 		/* Push odd/even indicator */
	  	PUSH_INT ((Source->IdentityDigit.items & 1) ? 1 : 0, 1);
	
	  	/* Push identity type */
	  	PUSH_INT (Source->IdentityType, 3);
			
	  	/* Push remaining digits */
	  	for (i=1; i<Source->IdentityDigit.items; i+=2) {
	  		PUSH_INT (i+1 >= Source->IdentityDigit.items? 15 : Source->IdentityDigit.data [i+1], 4);
	  		PUSH_INT (Source->IdentityDigit.data [i], 4);
	  	}
			return ((Source->IdentityDigit.items >> 1) << 3) + 8;
	  }
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId_Identity* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i, odd;

  	/* Shift digit 1 (we don't know yet whether it is valid or not) */
  	i = SHIFT_INT (4);

  	/* Shift odd indicator */
  	odd = SHIFT_INT (1);

		/* Now we know exactly how many items to expect */
  	ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_MobileId_Identity_IdentityDigit (&Destin->IdentityDigit, (Length >> 2) - (odd ? 1 : 2)), != ED_NO_ERRORS)

  	/* Now we know whether digit 1 is valid or not */
  	if (Destin->IdentityDigit.items > 0) Destin->IdentityDigit.data [0] = i;

		/* Extract identity type */
		Destin->IdentityType = SHIFT_INT (3);
	
		/* If decoding a TMSI/P-TMSI, just get the following bytes */
		if (Destin->IdentityType == 4) {
			ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_MobileId_Identity_IdentityDigit (&(Destin->IdentityDigit), (Length>>3) - 1), != ED_NO_ERRORS)
			for (i=0; i < Destin->IdentityDigit.items; i++) {
				Destin->IdentityDigit.data [i] = SHIFT_INT (8);
			}
		}
		else {
	  	/* Get the remaining digits */
	  	for (i=1; i < Destin->IdentityDigit.items; i+=2) {
	  		if (i+1 >= Destin->IdentityDigit.items) {
	  			SHIFT_INT (4); /* Discard it! */
	  		}
	  		else {
	  			Destin->IdentityDigit.data [i+1] = SHIFT_INT (4);
	  		}
	 			Destin->IdentityDigit.data [i] = SHIFT_INT (4);
	  	}
		}
		return Length;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	if (GETPRESENT_c_MobileId_Identity (Source)) {
  		return ENCODE_c_MobileId_Identity (Buffer, BitOffset, PTR_c_MobileId_Identity (Source->u.Identity));
  	}
  	else if (GETPRESENT_c_MobileId_TMGI (Source)) {
  		return ENCODE_c_MobileId_TMGI (Buffer, BitOffset, PTR_c_MobileId_TMGI (Source->u.TMGI));
  	} else {
  		return 0;
  	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	if (EDBitsToInt (Buffer, CURPOS+5, 3) == 5) {
	  	ED_CHECK_OUT_OF_MEMORY_KEEP(SETPRESENT_c_MobileId_TMGI (Destin), != ED_NO_ERRORS)
	 		return DECODE_c_MobileId_TMGI (Buffer, BitOffset, PTR_c_MobileId_TMGI (Destin->u.TMGI), Length);
  	} else {
	  	ED_CHECK_OUT_OF_MEMORY_KEEP(SETPRESENT_c_MobileId_Identity (Destin), != ED_NO_ERRORS)
	 		return DECODE_c_MobileId_Identity (Buffer, BitOffset, PTR_c_MobileId_Identity (Destin->u.Identity), Length);
	 	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TBCDEmergencyNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TBCDEmergencyNumber* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, Ret;

		/* Skip the place where the length is saved */
		CurrOfs += 8;

  	/* Encode the ServiceCategory */
  	Ret = ENCODE_c_ServCategory (Buffer, CurrOfs, &(Source->ServiceCategory));
  	if (Ret < 0) return Ret;
  	CurrOfs += Ret;

  	/* Encode the numbers */
		for (i=0; i < Source->Numbers.items; i+=2) {
			if (i+1 >= Source->Numbers.items) PUSH_INT (15, 4);
			else PUSH_INT (Source->Numbers.data [i+1], 4);
			PUSH_INT (Source->Numbers.data [i], 4);
		}

		/* Encode back the length */
		EDIntToBits (Buffer, BitOffset, (CurrOfs - BitOffset - 8) >> 3, 8);

		return (CurrOfs - BitOffset);
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TBCDEmergencyNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TBCDEmergencyNumber* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int IELength, Ret;
  	int nibbles;
  	int i, odd;
  	
  	/* Read the IE Length */
  	IELength = SHIFT_INT (8);
  	
  	/* Decode the ServiceCategory */
  	Ret = DECODE_c_ServCategory (Buffer, CurrOfs, &(Destin->ServiceCategory), 8);
  	if (Ret < 0) return Ret;
  	CurrOfs += Ret;
  	
  	/* Convert IELength from octets to bits */
  	IELength = (IELength - 1) * 8;
  	
  	/* Calculate the number of expected nibbles */
  	nibbles = IELength >> 2;
  	
  	/* Find out too see whether items are odd or even */
  	odd = (EDBitsToInt (Buffer, CURPOS+IELength-8, 4) == 15);
  	
  	ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_TBCDEmergencyNumber_Numbers (&(Destin->Numbers), (odd? nibbles-1 : nibbles)), != ED_NO_ERRORS)
  	
  	for (i=0; i<nibbles && i<32; i+=2) {
  		if (!odd || i<nibbles-2) Destin->Numbers.data [i+1] = (ED_OCTET)SHIFT_INT (4);
  		else CurrOfs += 4;
  		Destin->Numbers.data [i] = (ED_OCTET)SHIFT_INT (4);
  	}

		return (CurrOfs - BitOffset);
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TBCDArray (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TBCDArray* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
		for (i=0; i < Source->items; i+=2) {
			if (i+1 >= Source->items) PUSH_INT (15, 4);
			else PUSH_INT (Source->data [i+1], 4);
			PUSH_INT (Source->data [i], 4);
		}
		return i<<2;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TBCDArray (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TBCDArray* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int nibbles = Length >> 2;
  	int i, odd;
  	
  	/* Find out too see whether items are odd or even */
  	odd = (EDBitsToInt (Buffer, CURPOS+Length-8, 4) == 15);
  	ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_TBCDArray (Destin, (odd? nibbles-1 : nibbles)), != ED_NO_ERRORS)
  	
  	for (i=0; i<nibbles && i<32; i+=2) {
  		if (!odd || i<nibbles-2) Destin->data [i+1] = SHIFT_INT (4);
  		else CurrOfs += 4;
  		Destin->data [i] = SHIFT_INT (4);
  	}

		return Length;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SupportedCodec (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SupportedCodec* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		PUSH_INT (Source->SysId, 8);
		PUSH_INT (Source->CodecBitmap.usedBits >> 3, 8);
		PUSH_BIN ((const char*)Source->CodecBitmap.value, Source->CodecBitmap.usedBits);
		return Source->CodecBitmap.usedBits + 16;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SupportedCodec (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SupportedCodec* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		Destin->SysId = SHIFT_INT (8);
		ALLOC_c_SupportedCodec_CodecBitmap (&(Destin->CodecBitmap), SHIFT_INT (8) << 3);
		SHIFT_BIN (Destin->CodecBitmap.value, Destin->CodecBitmap.usedBits);
		return Destin->CodecBitmap.usedBits + 16;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LinkedTi (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LinkedTi* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		PUSH_INT (Source->TIFlag, 1);
		if (Source->TIValue > 6) {
			/* We need double byte encoding */
			PUSH_INT (7, 3);
			PUSH_INT (0, 4);
			PUSH_INT (1, 1);
			PUSH_INT (Source->TIValue, 7);
			return 16;
		}
		else {
			PUSH_INT (Source->TIValue, 3);
			PUSH_INT (0, 4);
			return 8;
		}
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LinkedTi (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LinkedTi* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		Destin->TIFlag = (ED_OCTET)SHIFT_INT (1);
		Destin->TIValue = SHIFT_INT (3);
		SHIFT_INT (4);
		if (Destin->TIValue >= 7) {
			SHIFT_INT (1);
			Destin->TIValue = SHIFT_INT (7);
			return 16;
		}
		return 8;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrafficFlowTemplate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrafficFlowTemplate* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, j, ret=8;
		unsigned contentsSizeInBits;
		
		PUSH_INT (Source->TFTOperationCode, 3);
		PUSH_INT ((Source->PacketParameters.items > 0? 1 : 0), 1); /* E bit */
		if (Source->TFTOperationCode == 2 /* Delete existing TFT */) {
			PUSH_INT (0, 4);
		}
		else {
			PUSH_INT (Source->PacketFilters.items, 4);
			for (i=0; i<Source->PacketFilters.items; i++) {
				switch (Source->TFTOperationCode) {
					case 5: /* Delete packet filters from existing TFT */
						PUSH_INT (0, 2);
						PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterDirection, 2);
						PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterId, 4);
						ret += 8;
						break;
					case 1: /* Create new TFT */
					case 3: /* Add packet filters to existing TFT */
					case 4: /* Replace packet filters in existing */
						contentsSizeInBits = 0;
						for (j=0; j<VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.items; j++) {
							contentsSizeInBits += 8 + VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits;
						}
					
						PUSH_INT (0, 2);
						PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterDirection, 2);
						PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterId, 4);
						PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterEvalPrecedence, 8);
						PUSH_INT (contentsSizeInBits/8, 8);
						for (j=0; j<VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.items; j++) {
							PUSH_INT (VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentTypeId, 8);
							PUSH_BIN (VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.value, VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits);
						}
						ret += 24 + contentsSizeInBits;
						break;
				}
			}
		}
		for (i=0; i<Source->PacketParameters.items; i++) {
			PUSH_INT (VAR_c_TrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).ParameterId, 8);
			PUSH_INT (VAR_c_TrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits >> 3, 8);
			PUSH_BIN (VAR_c_TrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.value, VAR_c_TrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits);
			ret += 16 + VAR_c_TrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits;
		}
		return ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrafficFlowTemplate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrafficFlowTemplate* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, ret=8, Ebit, j, componentId, contentBits;
		unsigned contentSizeInBits, remainingContentSizeInBits;
		Destin->TFTOperationCode = (ED_OCTET)SHIFT_INT (3);
		Ebit = SHIFT_INT (1); /* Read the E-bit: if true, parameters follow */
		ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_TrafficFlowTemplate_PacketFilters (&(Destin->PacketFilters), SHIFT_INT (4)), != ED_NO_ERRORS)
		for (i=0; i<Destin->PacketFilters.items; i++) {
			switch (Destin->TFTOperationCode) {
				case 5: /* Delete packet filters from existing TFT */
					SHIFT_INT (2);
					VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterDirection = (ED_OCTET)SHIFT_INT (2);
					VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterId = (ED_OCTET)SHIFT_INT (4);
					ret += 8;
					break;
				case 1: /* Create new TFT */
				case 3: /* Add packet filters to existing TFT */
				case 4: /* Replace packet filters in existing */
					SHIFT_INT (2);
					VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterDirection = (ED_OCTET)SHIFT_INT (2);
					VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterId = (ED_OCTET)SHIFT_INT (4);
					VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterEvalPrecedence = SHIFT_INT (8);
					contentSizeInBits = (SHIFT_INT (8) << 3);
					remainingContentSizeInBits = contentSizeInBits;
					j=0;
					while (remainingContentSizeInBits && j < 7) {
						componentId = SHIFT_INT (8);
						switch (componentId) {
							case 16:  contentBits=8 * 8 ; break; /* IPv4 remote address type             */
							case 32:  contentBits=8 * 32; break; /* IPv6 remote address type             */
							case 48:  contentBits=8 * 1 ; break; /* Protocol identifier/Next header type */
							case 64:  contentBits=8 * 2 ; break; /* Single local port type               */
							case 65:  contentBits=8 * 4 ; break; /* Local port range type                */
							case 80:  contentBits=8 * 2 ; break; /* Single remote port type              */
							case 81:  contentBits=8 * 4 ; break; /* Remote port range type               */
							case 96:  contentBits=8 * 4 ; break; /* Security parameter index type        */
							case 112: contentBits=8 * 2 ; break; /* Type of service/Traffic class type   */
							case 128: contentBits=8 * 3 ; break; /* Flow label type                      */
							default: contentBits = 0;
						}
						if (contentBits) {
							ADDITEMS_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (PTR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents), 1);
							VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentTypeId = (ED_OCTET)componentId;
							ALLOC_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData (
								&(VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentData)
							, contentBits);

							SHIFT_BIN (
								VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData (
									VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (
										VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j])).ComponentData.value
							, contentBits);
							VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_TrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits = contentBits;
							j++;
						}
						remainingContentSizeInBits -= (8 + contentBits);
					}
					
					ret += 24 + contentSizeInBits;
					break;
			}
		}
		ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_TrafficFlowTemplate_PacketParameters (&(Destin->PacketParameters), 0), != ED_NO_ERRORS)
		if (Ebit) {
			i = 0;
			while (ret < Length) {
				ADDITEMS_c_TrafficFlowTemplate_PacketParameters (&(Destin->PacketParameters), 1);
				VAR_c_TrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).ParameterId = SHIFT_INT (8);
				ALLOC_c_TrafficFlowTemplate_PacketParameters_data_Contents (&(VAR_c_TrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents), (SHIFT_INT (8) << 3));
				SHIFT_BIN (VAR_c_TrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.value, VAR_c_TrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.usedBits);
				ret += 16 + VAR_c_TrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.usedBits;
				i++;
			}
		}
		return ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PdpContextStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PdpContextStatus* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
		for (i=7; i>=0; i--) {
			PUSH_INT (Source->data [i] != 0? 1 : 0, 1);
		}
		for (i=15; i>=8; i--) {
			PUSH_INT (Source->data [i] != 0? 1 : 0, 1);
		}
		return 16;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PdpContextStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PdpContextStatus* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
		ED_CHECK_OUT_OF_MEMORY_KEEP(SETITEMS_c_PdpContextStatus (Destin, 16), != ED_NO_ERRORS)
		for (i=7; i>=0; i--) {
			Destin->data [i] = (ED_OCTET)SHIFT_INT (1);
		}
		for (i=15; i>=8; i--) {
			Destin->data [i] = (ED_OCTET)SHIFT_INT (1);
		}
		return 16;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_L3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_L3* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG BinaryDataLength;
	


	
	ED_EXTRAPARAMS_CODE
						
	/* Encode the tag */
	EDIntToBits (Buffer, CurrOfs, Source->TLV_Tag, 8);
	CurrOfs += 8;
	
	/* Calculate the binary length */
	BinaryDataLength = Source->TLV_Data.usedBits;
	
	/* Encode the length rounded up to the nearest octet */
	CurrOfs += EDEncodeDefiniteFormLength (Buffer, CurrOfs, (((unsigned ED_EXLONG)BinaryDataLength)+7)>>3);
	
	/* Encode the bits of the binary data */
	EDCopyBits (Buffer, CurrOfs, Source->TLV_Data.value, 0, BinaryDataLength);
	CurrOfs += BinaryDataLength;
	
	/* Pad the remaining part */
	EDIntToBits (Buffer, CurrOfs, 0, BITS_TO_OCTET_PAD (CurrOfs-BitOffset));
	CurrOfs += BITS_TO_OCTET_PAD (CurrOfs-BitOffset);
	

	return (CurrOfs - BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV DECODER */
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_L3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_L3* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG DataLength;
	ED_EXLONG EffectiveDataLength;
	ED_EXLONG RetLen;

	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER(RetLen);
	/* Is there room for tag and length? */
	if (Length < 16) return ED_MESSAGE_TOO_SHORT;

	/* Decode the tag */
	Destin->TLV_Tag = (ED_LONG)EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	
	/* Decode the length */
	RetLen = EDDecodeDefiniteFormLength (Buffer, CurrOfs, &DataLength);
	if (RetLen < 0) return RetLen;
	DataLength = DataLength * 8;
	EffectiveDataLength = DataLength;
	CurrOfs += RetLen;
	if ((CurrOfs-BitOffset) > Length) return ED_MESSAGE_TOO_SHORT;
	if ((CurrOfs + (ED_EXLONG)DataLength)-BitOffset > Length) return ED_MESSAGE_TOO_SHORT;
	

	
	if (DataLength > 0) {
		/* Allocate 'DataLength' bits */
		ALLOC_c_GenericTLV_L3_TLV_Data (&(Destin->TLV_Data), DataLength);

		
		/* Save the bits in the binary data */
		EDCopyBits (Destin->TLV_Data.value, 0, Buffer, CurrOfs, DataLength);
		CurrOfs += (ED_EXLONG)EffectiveDataLength;
	}
	
	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
