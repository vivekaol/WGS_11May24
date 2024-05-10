/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "UserDefinedDataTypes_SMS.h"
#include "ed_c_known_ie_SMS.h"
#include "ed_tlv.h"
#include "MS2SC_SMS.h"
#include "SC2MS_SMS.h"
#include "MSC2MS_SMS.h"
#include "MS2MSC_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TTimeStamp (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TTimeStamp* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:205> Error encoding subfield Year\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Month), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:206> Error encoding subfield Month\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).Day), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:207> Error encoding subfield Day\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).Hour), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:208> Error encoding subfield Hour\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).Minute), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:209> Error encoding subfield Minute\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).Second), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:210> Error encoding subfield Second\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).TimeZone), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:211> Error encoding subfield TimeZone\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TTimeStamp (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TTimeStamp* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Year = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Year___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:212> Error decoding subfield Year\n");
		ED_HANDLE_IE_SYNTAX_ERROR (212)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Month = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Month___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:213> Error decoding subfield Month\n");
		ED_HANDLE_IE_SYNTAX_ERROR (213)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).Day = (unsigned char)EDBitsToInt (Buffer, CurrOfs+16, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Day___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:214> Error decoding subfield Day\n");
		ED_HANDLE_IE_SYNTAX_ERROR (214)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).Hour = (unsigned char)EDBitsToInt (Buffer, CurrOfs+24, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Hour___LOCATOR), CurrOfs+24, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:215> Error decoding subfield Hour\n");
		ED_HANDLE_IE_SYNTAX_ERROR (215)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).Minute = (unsigned char)EDBitsToInt (Buffer, CurrOfs+32, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Minute___LOCATOR), CurrOfs+32, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:216> Error decoding subfield Minute\n");
		ED_HANDLE_IE_SYNTAX_ERROR (216)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).Second = (unsigned char)EDBitsToInt (Buffer, CurrOfs+40, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Second___LOCATOR), CurrOfs+40, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:217> Error decoding subfield Second\n");
		ED_HANDLE_IE_SYNTAX_ERROR (217)
	} 
#endif
	Len += Ret;
	
	/* FromBit=48 */
	(*Destin).TimeZone = (unsigned char)EDBitsToInt (Buffer, CurrOfs+48, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TimeZone___LOCATOR), CurrOfs+48, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:218> Error decoding subfield TimeZone\n");
		ED_HANDLE_IE_SYNTAX_ERROR (218)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_PI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_PI* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Extension != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:219> Error encoding subfield Extension\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).Reserved), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:220> Error encoding subfield Reserved\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TP_UDL != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:221> Error encoding subfield TP_UDL\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).TP_DCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:222> Error encoding subfield TP_DCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).TP_PID != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:223> Error encoding subfield TP_PID\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_PI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_PI* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Extension = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Extension___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:224> Error decoding subfield Extension\n");
		ED_HANDLE_IE_SYNTAX_ERROR (224)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).Reserved = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Reserved___LOCATOR), CurrOfs+1, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:225> Error decoding subfield Reserved\n");
		ED_HANDLE_IE_SYNTAX_ERROR (225)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TP_UDL = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TP_UDL___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:226> Error decoding subfield TP_UDL\n");
		ED_HANDLE_IE_SYNTAX_ERROR (226)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).TP_DCS = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TP_DCS___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:227> Error decoding subfield TP_DCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (227)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).TP_PID = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TP_PID___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:228> Error decoding subfield TP_PID\n");
		ED_HANDLE_IE_SYNTAX_ERROR (228)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_PID (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_PID* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).PIDType), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:229> Error encoding subfield PIDType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).TelematicInterneworking != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:230> Error encoding subfield TelematicInterneworking\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TelematicInterneworkingType), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:231> Error encoding subfield TelematicInterneworkingType\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_PID (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_PID* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).PIDType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PIDType___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:232> Error decoding subfield PIDType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (232)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).TelematicInterneworking = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TelematicInterneworking___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:233> Error decoding subfield TelematicInterneworking\n");
		ED_HANDLE_IE_SYNTAX_ERROR (233)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).TelematicInterneworkingType = (unsigned char)EDBitsToInt (Buffer, CurrOfs+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TelematicInterneworkingType___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:234> Error decoding subfield TelematicInterneworkingType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (234)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TConcShortMsgs8BitRefNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TConcShortMsgs8BitRefNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).RefNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:235> Error encoding subfield RefNumber\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MaxMesgs), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:236> Error encoding subfield MaxMesgs\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).SeqNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:237> Error encoding subfield SeqNumber\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TConcShortMsgs8BitRefNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TConcShortMsgs8BitRefNum* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).RefNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RefNumber___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:238> Error decoding subfield RefNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (238)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MaxMesgs = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaxMesgs___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:239> Error decoding subfield MaxMesgs\n");
		ED_HANDLE_IE_SYNTAX_ERROR (239)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).SeqNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SeqNumber___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:240> Error decoding subfield SeqNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (240)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSpecialSmsMsgInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSpecialSmsMsgInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StoreMessage != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:241> Error encoding subfield StoreMessage\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ExtendedIndication), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:242> Error encoding subfield ExtendedIndication\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Indication), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:243> Error encoding subfield Indication\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MsgCount), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:244> Error encoding subfield MsgCount\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSpecialSmsMsgInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSpecialSmsMsgInd* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StoreMessage = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).StoreMessage___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:245> Error decoding subfield StoreMessage\n");
		ED_HANDLE_IE_SYNTAX_ERROR (245)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ExtendedIndication = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ExtendedIndication___LOCATOR), CurrOfs+1, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:246> Error decoding subfield ExtendedIndication\n");
		ED_HANDLE_IE_SYNTAX_ERROR (246)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).Indication = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+6), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Indication___LOCATOR), CurrOfs+6, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:247> Error decoding subfield Indication\n");
		ED_HANDLE_IE_SYNTAX_ERROR (247)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MsgCount = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MsgCount___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:248> Error decoding subfield MsgCount\n");
		ED_HANDLE_IE_SYNTAX_ERROR (248)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TApplPortAddrScheme8BitAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TApplPortAddrScheme8BitAddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).DestPort), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:249> Error encoding subfield DestPort\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).OrigPort), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:250> Error encoding subfield OrigPort\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TApplPortAddrScheme8BitAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TApplPortAddrScheme8BitAddr* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).DestPort = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).DestPort___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:251> Error decoding subfield DestPort\n");
		ED_HANDLE_IE_SYNTAX_ERROR (251)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).OrigPort = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).OrigPort___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:252> Error decoding subfield OrigPort\n");
		ED_HANDLE_IE_SYNTAX_ERROR (252)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TApplPortAddrScheme16BitAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TApplPortAddrScheme16BitAddr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 32;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).DestPort), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:253> Error encoding subfield DestPort\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).OrigPort), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:254> Error encoding subfield OrigPort\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TApplPortAddrScheme16BitAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TApplPortAddrScheme16BitAddr* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).DestPort = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).DestPort___LOCATOR), CurrOfs, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:255> Error decoding subfield DestPort\n");
		ED_HANDLE_IE_SYNTAX_ERROR (255)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).OrigPort = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+16), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).OrigPort___LOCATOR), CurrOfs+16, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:256> Error decoding subfield OrigPort\n");
		ED_HANDLE_IE_SYNTAX_ERROR (256)
	} 
#endif
	Len += Ret;
	

	}
	return 32;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmscCtrlParams (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmscCtrlParams* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).StatusRepCompleted != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:257> Error encoding subfield StatusRepCompleted\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).StatusRepPermError != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:258> Error encoding subfield StatusRepPermError\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).StatusRepTempError != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:259> Error encoding subfield StatusRepTempError\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).StatusRepTempErrorSMStillTrying != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:260> Error encoding subfield StatusRepTempErrorSMStillTrying\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+2, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:261> Error encoding subfield reserved\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CancelConcat != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:262> Error encoding subfield CancelConcat\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).IncludeOrigUDHInStatusRep != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:263> Error encoding subfield IncludeOrigUDHInStatusRep\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmscCtrlParams (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmscCtrlParams* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=7 */
	(*Destin).StatusRepCompleted = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).StatusRepCompleted___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:264> Error decoding subfield StatusRepCompleted\n");
		ED_HANDLE_IE_SYNTAX_ERROR (264)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).StatusRepPermError = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).StatusRepPermError___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:265> Error decoding subfield StatusRepPermError\n");
		ED_HANDLE_IE_SYNTAX_ERROR (265)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).StatusRepTempError = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).StatusRepTempError___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:266> Error decoding subfield StatusRepTempError\n");
		ED_HANDLE_IE_SYNTAX_ERROR (266)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).StatusRepTempErrorSMStillTrying = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).StatusRepTempErrorSMStillTrying___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:267> Error decoding subfield StatusRepTempErrorSMStillTrying\n");
		ED_HANDLE_IE_SYNTAX_ERROR (267)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:268> Error decoding subfield reserved\n");
		ED_HANDLE_IE_SYNTAX_ERROR (268)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).CancelConcat = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CancelConcat___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:269> Error decoding subfield CancelConcat\n");
		ED_HANDLE_IE_SYNTAX_ERROR (269)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	(*Destin).IncludeOrigUDHInStatusRep = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).IncludeOrigUDHInStatusRep___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:270> Error decoding subfield IncludeOrigUDHInStatusRep\n");
		ED_HANDLE_IE_SYNTAX_ERROR (270)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUdhSrcInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUdhSrcInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).value), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:271> Error encoding subfield value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUdhSrcInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUdhSrcInd* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).value = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).value___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:272> Error decoding subfield value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (272)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TConcShortMsg16BitRefNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TConcShortMsg16BitRefNum* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 32;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).RefNumber), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:273> Error encoding subfield RefNumber\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MaxMesgs), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:274> Error encoding subfield MaxMesgs\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).SeqNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:275> Error encoding subfield SeqNumber\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TConcShortMsg16BitRefNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TConcShortMsg16BitRefNum* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).RefNumber = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RefNumber___LOCATOR), CurrOfs, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:276> Error decoding subfield RefNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (276)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MaxMesgs = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaxMesgs___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:277> Error decoding subfield MaxMesgs\n");
		ED_HANDLE_IE_SYNTAX_ERROR (277)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).SeqNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SeqNumber___LOCATOR), CurrOfs+24, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:278> Error decoding subfield SeqNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (278)
	} 
#endif
	Len += Ret;
	

	}
	return 32;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TTextFmt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TTextFmt* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:279> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Length), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:280> Error encoding subfield Length\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).Alignment), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:281> Error encoding subfield Alignment\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).FontSize), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:282> Error encoding subfield FontSize\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).Bold != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:283> Error encoding subfield Bold\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).Italic != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:284> Error encoding subfield Italic\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+17), (int)((*Source).Underlined != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:285> Error encoding subfield Underlined\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).Striketrhrough != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:286> Error encoding subfield Striketrhrough\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (
#ifdef ED_IS_ENCODING
				GETPRESENT_c_TTextFmt_TextColor (&DATA)
#else 
				Length > 24
#endif
		) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).TextColor), 8);
		Ret = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:287> Error encoding subfield TextColor\n");
			return -1;
		} 
#endif
		Len += Ret;
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TTextFmt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TTextFmt* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:288> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (288)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Length = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Length___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:289> Error decoding subfield Length\n");
		ED_HANDLE_IE_SYNTAX_ERROR (289)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).Alignment = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+22), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Alignment___LOCATOR), CurrOfs+22, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:290> Error decoding subfield Alignment\n");
		ED_HANDLE_IE_SYNTAX_ERROR (290)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).FontSize = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).FontSize___LOCATOR), CurrOfs+20, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:291> Error decoding subfield FontSize\n");
		ED_HANDLE_IE_SYNTAX_ERROR (291)
	} 
#endif
	Len += Ret;
	
	/* FromBit=19 */
	(*Destin).Bold = (EDBitsToInt (Buffer, CurrOfs+19, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Bold___LOCATOR), CurrOfs+19, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:292> Error decoding subfield Bold\n");
		ED_HANDLE_IE_SYNTAX_ERROR (292)
	} 
#endif
	Len += Ret;
	
	/* FromBit=18 */
	(*Destin).Italic = (EDBitsToInt (Buffer, CurrOfs+18, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Italic___LOCATOR), CurrOfs+18, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:293> Error decoding subfield Italic\n");
		ED_HANDLE_IE_SYNTAX_ERROR (293)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	(*Destin).Underlined = (EDBitsToInt (Buffer, CurrOfs+17, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Underlined___LOCATOR), CurrOfs+17, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:294> Error decoding subfield Underlined\n");
		ED_HANDLE_IE_SYNTAX_ERROR (294)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).Striketrhrough = (EDBitsToInt (Buffer, CurrOfs+16, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Striketrhrough___LOCATOR), CurrOfs+16, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:295> Error decoding subfield Striketrhrough\n");
		ED_HANDLE_IE_SYNTAX_ERROR (295)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* isConditional=1 beginOfGroupCondition=0 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (
#ifdef ED_IS_ENCODING
				GETPRESENT_c_TTextFmt_TextColor (&DATA)
#else 
				Length > 24
#endif
		) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TTextFmt_TextColor (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).TextColor = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).TextColor___LOCATOR), CurrOfs+24, 8);
		Ret = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:296> Error decoding subfield TextColor\n");
			ED_HANDLE_IE_SYNTAX_ERROR (296)
		} 
#endif
		Len += Ret;
	}
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TPredefSound (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TPredefSound* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:297> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).SoundNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:298> Error encoding subfield SoundNumber\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TPredefSound (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TPredefSound* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:299> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (299)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).SoundNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SoundNumber___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:300> Error decoding subfield SoundNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (300)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserDefSound (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserDefSound* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:301> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Sound.value, 0, (*Source).Sound.usedBits);
	Ret = (*Source).Sound.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:302> Error encoding subfield Sound\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserDefSound (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserDefSound* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:303> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (303)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Sound___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TUserDefSound_Sound (&((*Destin).Sound), (Length - 8));
	
		if ((*Destin).Sound.value) {
			EDCopyBits ((*Destin).Sound.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Sound.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Sound.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:304> Error decoding subfield Sound\n");
		ED_HANDLE_IE_SYNTAX_ERROR (304)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TPredefAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TPredefAnim* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:305> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).AnimationNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:306> Error encoding subfield AnimationNumber\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TPredefAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TPredefAnim* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:307> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (307)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).AnimationNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).AnimationNumber___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:308> Error decoding subfield AnimationNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (308)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TLargeAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TLargeAnim* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:309> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Animation.value, 0, (*Source).Animation.usedBits);
	Ret = (*Source).Animation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:310> Error encoding subfield Animation\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TLargeAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TLargeAnim* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:311> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (311)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Animation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TLargeAnim_Animation (&((*Destin).Animation), (Length - 8));
	
		if ((*Destin).Animation.value) {
			EDCopyBits ((*Destin).Animation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Animation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Animation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:312> Error decoding subfield Animation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (312)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmallAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmallAnim* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:313> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Animation.value, 0, (*Source).Animation.usedBits);
	Ret = (*Source).Animation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:314> Error encoding subfield Animation\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmallAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmallAnim* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:315> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (315)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Animation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TSmallAnim_Animation (&((*Destin).Animation), (Length - 8));
	
		if ((*Destin).Animation.value) {
			EDCopyBits ((*Destin).Animation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Animation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Animation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:316> Error decoding subfield Animation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (316)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TLargePict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TLargePict* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:317> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Picture.value, 0, (*Source).Picture.usedBits);
	Ret = (*Source).Picture.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:318> Error encoding subfield Picture\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TLargePict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TLargePict* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:319> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (319)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Picture___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TLargePict_Picture (&((*Destin).Picture), (Length - 8));
	
		if ((*Destin).Picture.value) {
			EDCopyBits ((*Destin).Picture.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Picture.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Picture.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:320> Error decoding subfield Picture\n");
		ED_HANDLE_IE_SYNTAX_ERROR (320)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmallPict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmallPict* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:321> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Picture.value, 0, (*Source).Picture.usedBits);
	Ret = (*Source).Picture.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:322> Error encoding subfield Picture\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmallPict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmallPict* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:323> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (323)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Picture___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TSmallPict_Picture (&((*Destin).Picture), (Length - 8));
	
		if ((*Destin).Picture.value) {
			EDCopyBits ((*Destin).Picture.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Picture.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Picture.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:324> Error decoding subfield Picture\n");
		ED_HANDLE_IE_SYNTAX_ERROR (324)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TVarPict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TVarPict* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).StartPosition), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:325> Error encoding subfield StartPosition\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).HSize), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:326> Error encoding subfield HSize\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).VSize), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:327> Error encoding subfield VSize\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+24, (*Source).Animation.value, 0, (*Source).Animation.usedBits);
	Ret = (*Source).Animation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:328> Error encoding subfield Animation\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TVarPict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TVarPict* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).StartPosition = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).StartPosition___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:329> Error decoding subfield StartPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (329)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).HSize = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSize___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:330> Error decoding subfield HSize\n");
		ED_HANDLE_IE_SYNTAX_ERROR (330)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).VSize = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).VSize___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:331> Error decoding subfield VSize\n");
		ED_HANDLE_IE_SYNTAX_ERROR (331)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Animation___LOCATOR), CurrOfs+24, (Length - 24));
	if ((Length - 24) > 0) {
		/* BINDEC02 */
		ALLOC_c_TVarPict_Animation (&((*Destin).Animation), (Length - 24));
	
		if ((*Destin).Animation.value) {
			EDCopyBits ((*Destin).Animation.value, 0, Buffer, CurrOfs+24, (Length - 24));
			(*Destin).Animation.usedBits = (Length - 24);
			Ret = (Length - 24);
	
		}
		else {
			(*Destin).Animation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 24);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:332> Error decoding subfield Animation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (332)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserPromptInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserPromptInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).NumOfCorrespObj), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:333> Error encoding subfield NumOfCorrespObj\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserPromptInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserPromptInd* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).NumOfCorrespObj = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NumOfCorrespObj___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:334> Error decoding subfield NumOfCorrespObj\n");
		ED_HANDLE_IE_SYNTAX_ERROR (334)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TExtObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TExtObj* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 56;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ExObjRefNum), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:335> Error encoding subfield ExObjRefNum\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Length), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:336> Error encoding subfield Length\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+31), (int)((*Source).DoNotForward != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:337> Error encoding subfield DoNotForward\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+30), (int)((*Source).UserPrompt != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:338> Error encoding subfield UserPrompt\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+24, 0, 6);Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:339> Error encoding subfield Reserved\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).ExObjType), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:340> Error encoding subfield ExObjType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).ExObjPosition), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:341> Error encoding subfield ExObjPosition\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+56, (*Source).ExObjData.value, 0, (*Source).ExObjData.usedBits);
	Ret = (*Source).ExObjData.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:342> Error encoding subfield ExObjData\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TExtObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TExtObj* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ExObjRefNum = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ExObjRefNum___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:343> Error decoding subfield ExObjRefNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (343)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Length = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+8), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Length___LOCATOR), CurrOfs+8, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:344> Error decoding subfield Length\n");
		ED_HANDLE_IE_SYNTAX_ERROR (344)
	} 
#endif
	Len += Ret;
	
	/* FromBit=31 */
	(*Destin).DoNotForward = (EDBitsToInt (Buffer, CurrOfs+31, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DoNotForward___LOCATOR), CurrOfs+31, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:345> Error decoding subfield DoNotForward\n");
		ED_HANDLE_IE_SYNTAX_ERROR (345)
	} 
#endif
	Len += Ret;
	
	/* FromBit=30 */
	(*Destin).UserPrompt = (EDBitsToInt (Buffer, CurrOfs+30, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UserPrompt___LOCATOR), CurrOfs+30, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:346> Error decoding subfield UserPrompt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (346)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:347> Error decoding subfield Reserved\n");
		ED_HANDLE_IE_SYNTAX_ERROR (347)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).ExObjType = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+32), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ExObjType___LOCATOR), CurrOfs+32, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:348> Error decoding subfield ExObjType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (348)
	} 
#endif
	Len += Ret;
	
	/* FromBit=40 */
	(*Destin).ExObjPosition = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+40), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ExObjPosition___LOCATOR), CurrOfs+40, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:349> Error decoding subfield ExObjPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (349)
	} 
#endif
	Len += Ret;
	
	/* FromBit=56 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).ExObjData___LOCATOR), CurrOfs+56, (Length - 56));
	if ((Length - 56) > 0) {
		/* BINDEC02 */
		ALLOC_c_TExtObj_ExObjData (&((*Destin).ExObjData), (Length - 56));
	
		if ((*Destin).ExObjData.value) {
			EDCopyBits ((*Destin).ExObjData.value, 0, Buffer, CurrOfs+56, (Length - 56));
			(*Destin).ExObjData.usedBits = (Length - 56);
			Ret = (Length - 56);
	
		}
		else {
			(*Destin).ExObjData.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 56);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:350> Error decoding subfield ExObjData\n");
		ED_HANDLE_IE_SYNTAX_ERROR (350)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TReusedExtObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TReusedExtObj* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).RefNumber), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:351> Error encoding subfield RefNumber\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Position), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:352> Error encoding subfield Position\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TReusedExtObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TReusedExtObj* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).RefNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RefNumber___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:353> Error decoding subfield RefNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (353)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Position = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+8), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Position___LOCATOR), CurrOfs+8, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:354> Error decoding subfield Position\n");
		ED_HANDLE_IE_SYNTAX_ERROR (354)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TComprCtrl (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TComprCtrl* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).ComprAlgo), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:355> Error encoding subfield ComprAlgo\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:356> Error encoding subfield reserved\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Length), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:357> Error encoding subfield Length\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+24, (*Source).CompressedData.value, 0, (*Source).CompressedData.usedBits);
	Ret = (*Source).CompressedData.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:358> Error encoding subfield CompressedData\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TComprCtrl (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TComprCtrl* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=4 */
	(*Destin).ComprAlgo = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ComprAlgo___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:359> Error decoding subfield ComprAlgo\n");
		ED_HANDLE_IE_SYNTAX_ERROR (359)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:360> Error decoding subfield reserved\n");
		ED_HANDLE_IE_SYNTAX_ERROR (360)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).Length = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+8), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Length___LOCATOR), CurrOfs+8, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:361> Error decoding subfield Length\n");
		ED_HANDLE_IE_SYNTAX_ERROR (361)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).CompressedData___LOCATOR), CurrOfs+24, (Length - 24));
	if ((Length - 24) > 0) {
		/* BINDEC02 */
		ALLOC_c_TComprCtrl_CompressedData (&((*Destin).CompressedData), (Length - 24));
	
		if ((*Destin).CompressedData.value) {
			EDCopyBits ((*Destin).CompressedData.value, 0, Buffer, CurrOfs+24, (Length - 24));
			(*Destin).CompressedData.usedBits = (Length - 24);
			Ret = (Length - 24);
	
		}
		else {
			(*Destin).CompressedData.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 24);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:362> Error decoding subfield CompressedData\n");
		ED_HANDLE_IE_SYNTAX_ERROR (362)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TObjDistrInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TObjDistrInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).NumOfIEs), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:363> Error encoding subfield NumOfIEs\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).DontForward != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:364> Error encoding subfield DontForward\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 7);Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:365> Error encoding subfield reserved\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TObjDistrInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TObjDistrInd* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).NumOfIEs = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NumOfIEs___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:366> Error decoding subfield NumOfIEs\n");
		ED_HANDLE_IE_SYNTAX_ERROR (366)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).DontForward = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DontForward___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:367> Error decoding subfield DontForward\n");
		ED_HANDLE_IE_SYNTAX_ERROR (367)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:368> Error decoding subfield reserved\n");
		ED_HANDLE_IE_SYNTAX_ERROR (368)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TStdWvgObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TStdWvgObj* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Position), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:369> Error encoding subfield Position\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Data.value, 0, (*Source).Data.usedBits);
	Ret = (*Source).Data.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:370> Error encoding subfield Data\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TStdWvgObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TStdWvgObj* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Position = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Position___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:371> Error decoding subfield Position\n");
		ED_HANDLE_IE_SYNTAX_ERROR (371)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Data___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TStdWvgObj_Data (&((*Destin).Data), (Length - 8));
	
		if ((*Destin).Data.value) {
			EDCopyBits ((*Destin).Data.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Data.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Data.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:372> Error decoding subfield Data\n");
		ED_HANDLE_IE_SYNTAX_ERROR (372)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TCharSizeWvgObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TCharSizeWvgObj* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Position), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:373> Error encoding subfield Position\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).Data.value, 0, (*Source).Data.usedBits);
	Ret = (*Source).Data.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:374> Error encoding subfield Data\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TCharSizeWvgObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TCharSizeWvgObj* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Position = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Position___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:375> Error decoding subfield Position\n");
		ED_HANDLE_IE_SYNTAX_ERROR (375)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Data___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TCharSizeWvgObj_Data (&((*Destin).Data), (Length - 8));
	
		if ((*Destin).Data.value) {
			EDCopyBits ((*Destin).Data.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).Data.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).Data.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:376> Error decoding subfield Data\n");
		ED_HANDLE_IE_SYNTAX_ERROR (376)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRfc822EMailHdr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRfc822EMailHdr* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Length), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:377> Error encoding subfield Length\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRfc822EMailHdr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRfc822EMailHdr* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Length = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Length___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:378> Error decoding subfield Length\n");
		ED_HANDLE_IE_SYNTAX_ERROR (378)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_THyperlinkFmtElem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_THyperlinkFmtElem* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 32;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).AbsElemPosition), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:379> Error encoding subfield AbsElemPosition\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).HyperLinkTitleLen), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:380> Error encoding subfield HyperLinkTitleLen\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).URLLen), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:381> Error encoding subfield URLLen\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_THyperlinkFmtElem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_THyperlinkFmtElem* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).AbsElemPosition = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).AbsElemPosition___LOCATOR), CurrOfs, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:382> Error decoding subfield AbsElemPosition\n");
		ED_HANDLE_IE_SYNTAX_ERROR (382)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).HyperLinkTitleLen = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HyperLinkTitleLen___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:383> Error decoding subfield HyperLinkTitleLen\n");
		ED_HANDLE_IE_SYNTAX_ERROR (383)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).URLLen = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).URLLen___LOCATOR), CurrOfs+24, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:384> Error decoding subfield URLLen\n");
		ED_HANDLE_IE_SYNTAX_ERROR (384)
	} 
#endif
	Len += Ret;
	

	}
	return 32;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRPCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRPCause* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:385> Error encoding subfield Cause\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (
#ifdef ED_IS_ENCODING
				GETPRESENT_c_TRPCause_Diagnostic (&DATA)
#else 
				Length > 8
#endif
		) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Diagnostic), 8);
		Ret = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:386> Error encoding subfield Diagnostic\n");
			return -1;
		} 
#endif
		Len += Ret;
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRPCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRPCause* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Cause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Cause___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:387> Error decoding subfield Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (387)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* isConditional=1 beginOfGroupCondition=0 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (
#ifdef ED_IS_ENCODING
				GETPRESENT_c_TRPCause_Diagnostic (&DATA)
#else 
				Length > 8
#endif
		) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TRPCause_Diagnostic (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).Diagnostic = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).Diagnostic___LOCATOR), CurrOfs+8, 8);
		Ret = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:388> Error decoding subfield Diagnostic\n");
			ED_HANDLE_IE_SYNTAX_ERROR (388)
		} 
#endif
		Len += Ret;
	}
	

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_UNKNOWN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_UNKNOWN* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	EDCopyBits (Buffer, CurrOfs, (*Source).UnknownSMSData.value, 0, (*Source).UnknownSMSData.usedBits);
	Ret = (*Source).UnknownSMSData.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:389> Error encoding subfield UnknownSMSData\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_UNKNOWN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_UNKNOWN* ED_CONST Destin, ED_EXLONG Length))
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
	ED_LOCATOR_SET (&((*Destin).UnknownSMSData___LOCATOR), CurrOfs, (Length - 0));
	if ((Length - 0) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_UNKNOWN_UnknownSMSData (&((*Destin).UnknownSMSData), (Length - 0));
	
		if ((*Destin).UnknownSMSData.value) {
			EDCopyBits ((*Destin).UnknownSMSData.value, 0, Buffer, CurrOfs, (Length - 0));
			(*Destin).UnknownSMSData.usedBits = (Length - 0);
			Ret = (Length - 0);
	
		}
		else {
			(*Destin).UnknownSMSData.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 0);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:390> Error decoding subfield UnknownSMSData\n");
		ED_HANDLE_IE_SYNTAX_ERROR (390)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_UNKNOWN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_UNKNOWN* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MessageType), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:391> Error encoding subfield MessageType\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).TransportedData.value, 0, (*Source).TransportedData.usedBits);
	Ret = (*Source).TransportedData.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:392> Error encoding subfield TransportedData\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_UNKNOWN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_UNKNOWN* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).MessageType = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MessageType___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:393> Error decoding subfield MessageType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (393)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).TransportedData___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_RP_UNKNOWN_TransportedData (&((*Destin).TransportedData), (Length - 8));
	
		if ((*Destin).TransportedData.value) {
			EDCopyBits ((*Destin).TransportedData.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).TransportedData.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).TransportedData.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:394> Error decoding subfield TransportedData\n");
		ED_HANDLE_IE_SYNTAX_ERROR (394)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserDataIE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserDataIE* ED_CONST Source))
{
	ED_EXLONG Len = 0;
	ED_EXLONG CurrOfs = BitOffset;
	int IEI;
	int i0;
	/* OBJPRESENT=<Source->data [i0]> */
	
	for (i0=0; i0<(*Source).items; i0++) {
		switch (GETPRESENT_c_TUserDataIEUnion (Source->data [i0])) {
			/* IEI=0 NAME=ConcShortMsgs8BitRefNum */
			case U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum: {
				IEI = 0;
				Len = ENCODE_c_TConcShortMsgs8BitRefNum (Buffer, CurrOfs+16, Source->data [i0]->u.ConcShortMsgs8BitRefNum);
				break;
			}
			/* IEI=1 NAME=SpecialSmsMsgInd */
			case U_c_TUserDataIEUnion_SpecialSmsMsgInd: {
				IEI = 1;
				Len = ENCODE_c_TSpecialSmsMsgInd (Buffer, CurrOfs+16, Source->data [i0]->u.SpecialSmsMsgInd);
				break;
			}
			/* IEI=4 NAME=ApplPortAddrScheme8BitAddr */
			case U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr: {
				IEI = 4;
				Len = ENCODE_c_TApplPortAddrScheme8BitAddr (Buffer, CurrOfs+16, Source->data [i0]->u.ApplPortAddrScheme8BitAddr);
				break;
			}
			/* IEI=5 NAME=ApplPortAddrScheme16BitAddr */
			case U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr: {
				IEI = 5;
				Len = ENCODE_c_TApplPortAddrScheme16BitAddr (Buffer, CurrOfs+16, Source->data [i0]->u.ApplPortAddrScheme16BitAddr);
				break;
			}
			/* IEI=6 NAME=SmscCtrlParams */
			case U_c_TUserDataIEUnion_SmscCtrlParams: {
				IEI = 6;
				Len = ENCODE_c_TSmscCtrlParams (Buffer, CurrOfs+16, Source->data [i0]->u.SmscCtrlParams);
				break;
			}
			/* IEI=7 NAME=UdhSrcInd */
			case U_c_TUserDataIEUnion_UdhSrcInd: {
				IEI = 7;
				Len = ENCODE_c_TUdhSrcInd (Buffer, CurrOfs+16, Source->data [i0]->u.UdhSrcInd);
				break;
			}
			/* IEI=8 NAME=ConcShortMsg16BitRefNum */
			case U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum: {
				IEI = 8;
				Len = ENCODE_c_TConcShortMsg16BitRefNum (Buffer, CurrOfs+16, Source->data [i0]->u.ConcShortMsg16BitRefNum);
				break;
			}
			/* IEI=9 NAME=WirelessCtrlMsgProto */
			case U_c_TUserDataIEUnion_WirelessCtrlMsgProto: {
				IEI = 9;
				EDCopyBits (Buffer, CurrOfs+16, Source->data [i0]->u.WirelessCtrlMsgProto->value, 0, Source->data [i0]->u.WirelessCtrlMsgProto->usedBits);
				Len = Source->data [i0]->u.WirelessCtrlMsgProto->usedBits;
				break;
			}
			/* IEI=10 NAME=TextFmt */
			case U_c_TUserDataIEUnion_TextFmt: {
				IEI = 10;
				Len = ENCODE_c_TTextFmt (Buffer, CurrOfs+16, Source->data [i0]->u.TextFmt);
				break;
			}
			/* IEI=11 NAME=PredefSound */
			case U_c_TUserDataIEUnion_PredefSound: {
				IEI = 11;
				Len = ENCODE_c_TPredefSound (Buffer, CurrOfs+16, Source->data [i0]->u.PredefSound);
				break;
			}
			/* IEI=12 NAME=UserDefSound */
			case U_c_TUserDataIEUnion_UserDefSound: {
				IEI = 12;
				Len = ENCODE_c_TUserDefSound (Buffer, CurrOfs+16, Source->data [i0]->u.UserDefSound);
				break;
			}
			/* IEI=13 NAME=PredefAnim */
			case U_c_TUserDataIEUnion_PredefAnim: {
				IEI = 13;
				Len = ENCODE_c_TPredefAnim (Buffer, CurrOfs+16, Source->data [i0]->u.PredefAnim);
				break;
			}
			/* IEI=14 NAME=LargeAnim */
			case U_c_TUserDataIEUnion_LargeAnim: {
				IEI = 14;
				Len = ENCODE_c_TLargeAnim (Buffer, CurrOfs+16, Source->data [i0]->u.LargeAnim);
				break;
			}
			/* IEI=15 NAME=SmallAnim */
			case U_c_TUserDataIEUnion_SmallAnim: {
				IEI = 15;
				Len = ENCODE_c_TSmallAnim (Buffer, CurrOfs+16, Source->data [i0]->u.SmallAnim);
				break;
			}
			/* IEI=16 NAME=LargePict */
			case U_c_TUserDataIEUnion_LargePict: {
				IEI = 16;
				Len = ENCODE_c_TLargePict (Buffer, CurrOfs+16, Source->data [i0]->u.LargePict);
				break;
			}
			/* IEI=17 NAME=SmallPict */
			case U_c_TUserDataIEUnion_SmallPict: {
				IEI = 17;
				Len = ENCODE_c_TSmallPict (Buffer, CurrOfs+16, Source->data [i0]->u.SmallPict);
				break;
			}
			/* IEI=18 NAME=VarPict */
			case U_c_TUserDataIEUnion_VarPict: {
				IEI = 18;
				Len = ENCODE_c_TVarPict (Buffer, CurrOfs+16, Source->data [i0]->u.VarPict);
				break;
			}
			/* IEI=19 NAME=UserPromptInd */
			case U_c_TUserDataIEUnion_UserPromptInd: {
				IEI = 19;
				Len = ENCODE_c_TUserPromptInd (Buffer, CurrOfs+16, Source->data [i0]->u.UserPromptInd);
				break;
			}
			/* IEI=20 NAME=ExtObj */
			case U_c_TUserDataIEUnion_ExtObj: {
				IEI = 20;
				Len = ENCODE_c_TExtObj (Buffer, CurrOfs+16, Source->data [i0]->u.ExtObj);
				break;
			}
			/* IEI=21 NAME=ReusedExtObj */
			case U_c_TUserDataIEUnion_ReusedExtObj: {
				IEI = 21;
				Len = ENCODE_c_TReusedExtObj (Buffer, CurrOfs+16, Source->data [i0]->u.ReusedExtObj);
				break;
			}
			/* IEI=22 NAME=ComprCtrl */
			case U_c_TUserDataIEUnion_ComprCtrl: {
				IEI = 22;
				Len = ENCODE_c_TComprCtrl (Buffer, CurrOfs+16, Source->data [i0]->u.ComprCtrl);
				break;
			}
			/* IEI=23 NAME=ObjDistrInd */
			case U_c_TUserDataIEUnion_ObjDistrInd: {
				IEI = 23;
				Len = ENCODE_c_TObjDistrInd (Buffer, CurrOfs+16, Source->data [i0]->u.ObjDistrInd);
				break;
			}
			/* IEI=24 NAME=StdWvgObj */
			case U_c_TUserDataIEUnion_StdWvgObj: {
				IEI = 24;
				Len = ENCODE_c_TStdWvgObj (Buffer, CurrOfs+16, Source->data [i0]->u.StdWvgObj);
				break;
			}
			/* IEI=25 NAME=CharSizeWvgObj */
			case U_c_TUserDataIEUnion_CharSizeWvgObj: {
				IEI = 25;
				Len = ENCODE_c_TCharSizeWvgObj (Buffer, CurrOfs+16, Source->data [i0]->u.CharSizeWvgObj);
				break;
			}
			/* IEI=26 NAME=ExtObjDataReqCmd */
			case U_c_TUserDataIEUnion_ExtObjDataReqCmd: {
				IEI = 26;
				Len = 0;
				break;
			}
			/* IEI=32 NAME=Rfc822EMailHdr */
			case U_c_TUserDataIEUnion_Rfc822EMailHdr: {
				IEI = 32;
				Len = ENCODE_c_TRfc822EMailHdr (Buffer, CurrOfs+16, Source->data [i0]->u.Rfc822EMailHdr);
				break;
			}
			/* IEI=33 NAME=HyperlinkFmtElem */
			case U_c_TUserDataIEUnion_HyperlinkFmtElem: {
				IEI = 33;
				Len = ENCODE_c_THyperlinkFmtElem (Buffer, CurrOfs+16, Source->data [i0]->u.HyperlinkFmtElem);
				break;
			}
			/* IEI=34 NAME=ReplyAddrElem */
			case U_c_TUserDataIEUnion_ReplyAddrElem: {
				IEI = 34;
				EDCopyBits (Buffer, CurrOfs+16, Source->data [i0]->u.ReplyAddrElem->value, 0, Source->data [i0]->u.ReplyAddrElem->usedBits);
				Len = Source->data [i0]->u.ReplyAddrElem->usedBits;
				break;
			}
			/* IEI=35 NAME=EnVoiceMailInfo */
			case U_c_TUserDataIEUnion_EnVoiceMailInfo: {
				IEI = 35;
				Len = ENCODE_c_TEnVoiceMailInfo (Buffer, CurrOfs+16, Source->data [i0]->u.EnVoiceMailInfo);
				break;
			}
			/* IEI=36 NAME=NationalLangSingleShift */
			case U_c_TUserDataIEUnion_NationalLangSingleShift: {
				IEI = 36;
				EDIntToBits (Buffer, (CurrOfs+16), (int)(Source->data [i0]->u.NationalLangSingleShift), 8);
				Len = 8;
				break;
			}
			/* IEI=37 NAME=NationalLangLockingShift */
			case U_c_TUserDataIEUnion_NationalLangLockingShift: {
				IEI = 37;
				EDIntToBits (Buffer, (CurrOfs+16), (int)(Source->data [i0]->u.NationalLangLockingShift), 8);
				Len = 8;
				break;
			}
			/* DEFAULT NAME=UnknownIE */
			case U_c_TUserDataIEUnion_UnknownIE: {
				IEI = -1;
				Len = ENCODE_c_TUnknownIE (Buffer, CurrOfs, Source->data [i0]->u.UnknownIE);
				CurrOfs += Len;
	break;
			}
			default: IEI=-1;
		}
		if (IEI >= 0) {
			EDIntToBits (Buffer, CurrOfs, IEI, 8);
			CurrOfs += 8;
			EDIntToBits (Buffer, CurrOfs, (Len+7)>>3, 8);
			CurrOfs += 8 + ((Len+7)&~7); /* The 'Len' value is rounded up to a full octet */
		}
	}
	return CurrOfs-BitOffset;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserDataIE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserDataIE* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0;
	ED_EXLONG CurrOfs = BitOffset;
	int IEI, IEILen;
	int i0 = (*Destin).items;
	while (CurrOfs <= (BitOffset+Length-16)) {
		IEI = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		IEILen = EDBitsToInt (Buffer, CurrOfs, 8);
		IEILen <<= 3;
		CurrOfs += 8;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:395> Message too short decoding subfield\n");
			ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (IEI, 395, NULL)
		} 
#endif
		
		switch (IEI) {
			/* IEI=0 NAME=ConcShortMsgs8BitRefNum */
			case 0: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TConcShortMsgs8BitRefNum (Buffer, CurrOfs, Destin->data [i0]->u.ConcShortMsgs8BitRefNum, IEILen);
				i0++;
				break;
			}
			/* IEI=1 NAME=SpecialSmsMsgInd */
			case 1: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_SpecialSmsMsgInd (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TSpecialSmsMsgInd (Buffer, CurrOfs, Destin->data [i0]->u.SpecialSmsMsgInd, IEILen);
				i0++;
				break;
			}
			/* IEI=4 NAME=ApplPortAddrScheme8BitAddr */
			case 4: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TApplPortAddrScheme8BitAddr (Buffer, CurrOfs, Destin->data [i0]->u.ApplPortAddrScheme8BitAddr, IEILen);
				i0++;
				break;
			}
			/* IEI=5 NAME=ApplPortAddrScheme16BitAddr */
			case 5: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TApplPortAddrScheme16BitAddr (Buffer, CurrOfs, Destin->data [i0]->u.ApplPortAddrScheme16BitAddr, IEILen);
				i0++;
				break;
			}
			/* IEI=6 NAME=SmscCtrlParams */
			case 6: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_SmscCtrlParams (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TSmscCtrlParams (Buffer, CurrOfs, Destin->data [i0]->u.SmscCtrlParams, IEILen);
				i0++;
				break;
			}
			/* IEI=7 NAME=UdhSrcInd */
			case 7: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_UdhSrcInd (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TUdhSrcInd (Buffer, CurrOfs, Destin->data [i0]->u.UdhSrcInd, IEILen);
				i0++;
				break;
			}
			/* IEI=8 NAME=ConcShortMsg16BitRefNum */
			case 8: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ConcShortMsg16BitRefNum (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TConcShortMsg16BitRefNum (Buffer, CurrOfs, Destin->data [i0]->u.ConcShortMsg16BitRefNum, IEILen);
				i0++;
				break;
			}
			/* IEI=9 NAME=WirelessCtrlMsgProto */
			case 9: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_WirelessCtrlMsgProto (Destin->data [i0]), != ED_NO_ERRORS)
				/* LOCATOR SETTINGS LOCBIN2 */;
				ED_LOCATOR_SET (&(/*LOC63*/Destin->data___LOCATOR [i0])/*LOC62*/, CurrOfs, IEILen);
				if (IEILen > 0) {
					/* BINDEC02 */
					ALLOC_c_TUserDataIEUnion_WirelessCtrlMsgProto (Destin->data [i0]->u.WirelessCtrlMsgProto, IEILen);
				
					if (Destin->data [i0]->u.WirelessCtrlMsgProto->value) {
						EDCopyBits (Destin->data [i0]->u.WirelessCtrlMsgProto->value, 0, Buffer, CurrOfs, IEILen);
						Destin->data [i0]->u.WirelessCtrlMsgProto->usedBits = IEILen;
						Len = IEILen;
				
					}
					else {
						Destin->data [i0]->u.WirelessCtrlMsgProto->usedBits = 0;
						Len = ED_OUT_OF_MEMORY;
					}
				}
				else {
					Len = IEILen;
				
				}
				i0++;
				break;
			}
			/* IEI=10 NAME=TextFmt */
			case 10: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_TextFmt (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TTextFmt (Buffer, CurrOfs, Destin->data [i0]->u.TextFmt, IEILen);
				i0++;
				break;
			}
			/* IEI=11 NAME=PredefSound */
			case 11: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_PredefSound (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TPredefSound (Buffer, CurrOfs, Destin->data [i0]->u.PredefSound, IEILen);
				i0++;
				break;
			}
			/* IEI=12 NAME=UserDefSound */
			case 12: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_UserDefSound (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TUserDefSound (Buffer, CurrOfs, Destin->data [i0]->u.UserDefSound, IEILen);
				i0++;
				break;
			}
			/* IEI=13 NAME=PredefAnim */
			case 13: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_PredefAnim (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TPredefAnim (Buffer, CurrOfs, Destin->data [i0]->u.PredefAnim, IEILen);
				i0++;
				break;
			}
			/* IEI=14 NAME=LargeAnim */
			case 14: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_LargeAnim (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TLargeAnim (Buffer, CurrOfs, Destin->data [i0]->u.LargeAnim, IEILen);
				i0++;
				break;
			}
			/* IEI=15 NAME=SmallAnim */
			case 15: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_SmallAnim (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TSmallAnim (Buffer, CurrOfs, Destin->data [i0]->u.SmallAnim, IEILen);
				i0++;
				break;
			}
			/* IEI=16 NAME=LargePict */
			case 16: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_LargePict (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TLargePict (Buffer, CurrOfs, Destin->data [i0]->u.LargePict, IEILen);
				i0++;
				break;
			}
			/* IEI=17 NAME=SmallPict */
			case 17: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_SmallPict (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TSmallPict (Buffer, CurrOfs, Destin->data [i0]->u.SmallPict, IEILen);
				i0++;
				break;
			}
			/* IEI=18 NAME=VarPict */
			case 18: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_VarPict (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TVarPict (Buffer, CurrOfs, Destin->data [i0]->u.VarPict, IEILen);
				i0++;
				break;
			}
			/* IEI=19 NAME=UserPromptInd */
			case 19: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_UserPromptInd (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TUserPromptInd (Buffer, CurrOfs, Destin->data [i0]->u.UserPromptInd, IEILen);
				i0++;
				break;
			}
			/* IEI=20 NAME=ExtObj */
			case 20: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ExtObj (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TExtObj (Buffer, CurrOfs, Destin->data [i0]->u.ExtObj, IEILen);
				i0++;
				break;
			}
			/* IEI=21 NAME=ReusedExtObj */
			case 21: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ReusedExtObj (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TReusedExtObj (Buffer, CurrOfs, Destin->data [i0]->u.ReusedExtObj, IEILen);
				i0++;
				break;
			}
			/* IEI=22 NAME=ComprCtrl */
			case 22: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ComprCtrl (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TComprCtrl (Buffer, CurrOfs, Destin->data [i0]->u.ComprCtrl, IEILen);
				i0++;
				break;
			}
			/* IEI=23 NAME=ObjDistrInd */
			case 23: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ObjDistrInd (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TObjDistrInd (Buffer, CurrOfs, Destin->data [i0]->u.ObjDistrInd, IEILen);
				i0++;
				break;
			}
			/* IEI=24 NAME=StdWvgObj */
			case 24: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_StdWvgObj (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TStdWvgObj (Buffer, CurrOfs, Destin->data [i0]->u.StdWvgObj, IEILen);
				i0++;
				break;
			}
			/* IEI=25 NAME=CharSizeWvgObj */
			case 25: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_CharSizeWvgObj (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TCharSizeWvgObj (Buffer, CurrOfs, Destin->data [i0]->u.CharSizeWvgObj, IEILen);
				i0++;
				break;
			}
			/* IEI=26 NAME=ExtObjDataReqCmd */
			case 26: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ExtObjDataReqCmd (Destin->data [i0]), != ED_NO_ERRORS)
				Len = 0;
				i0++;
				break;
			}
			/* IEI=32 NAME=Rfc822EMailHdr */
			case 32: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_Rfc822EMailHdr (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TRfc822EMailHdr (Buffer, CurrOfs, Destin->data [i0]->u.Rfc822EMailHdr, IEILen);
				i0++;
				break;
			}
			/* IEI=33 NAME=HyperlinkFmtElem */
			case 33: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_HyperlinkFmtElem (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_THyperlinkFmtElem (Buffer, CurrOfs, Destin->data [i0]->u.HyperlinkFmtElem, IEILen);
				i0++;
				break;
			}
			/* IEI=34 NAME=ReplyAddrElem */
			case 34: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_ReplyAddrElem (Destin->data [i0]), != ED_NO_ERRORS)
				/* LOCATOR SETTINGS LOCBIN2 */;
				ED_LOCATOR_SET (&(/*LOC63*/Destin->data___LOCATOR [i0])/*LOC62*/, CurrOfs, IEILen);
				if (IEILen > 0) {
					/* BINDEC02 */
					ALLOC_c_TUserDataIEUnion_ReplyAddrElem (Destin->data [i0]->u.ReplyAddrElem, IEILen);
				
					if (Destin->data [i0]->u.ReplyAddrElem->value) {
						EDCopyBits (Destin->data [i0]->u.ReplyAddrElem->value, 0, Buffer, CurrOfs, IEILen);
						Destin->data [i0]->u.ReplyAddrElem->usedBits = IEILen;
						Len = IEILen;
				
					}
					else {
						Destin->data [i0]->u.ReplyAddrElem->usedBits = 0;
						Len = ED_OUT_OF_MEMORY;
					}
				}
				else {
					Len = IEILen;
				
				}
				i0++;
				break;
			}
			/* IEI=35 NAME=EnVoiceMailInfo */
			case 35: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_EnVoiceMailInfo (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TEnVoiceMailInfo (Buffer, CurrOfs, Destin->data [i0]->u.EnVoiceMailInfo, IEILen);
				i0++;
				break;
			}
			/* IEI=36 NAME=NationalLangSingleShift */
			case 36: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_NationalLangSingleShift (Destin->data [i0]), != ED_NO_ERRORS)
				Destin->data [i0]->u.NationalLangSingleShift = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
				/* LOCATOR SETTINGS LOCOCTET */;
				ED_LOCATOR_SET (&(/*LOC63*/Destin->data___LOCATOR [i0])/*LOC62*/, CurrOfs, 8);
				Len = 8;
				i0++;
				break;
			}
			/* IEI=37 NAME=NationalLangLockingShift */
			case 37: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_NationalLangLockingShift (Destin->data [i0]), != ED_NO_ERRORS)
				Destin->data [i0]->u.NationalLangLockingShift = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
				/* LOCATOR SETTINGS LOCOCTET */;
				ED_LOCATOR_SET (&(/*LOC63*/Destin->data___LOCATOR [i0])/*LOC62*/, CurrOfs, 8);
				Len = 8;
				i0++;
				break;
			}
			/* DEFAULT ENTRY NAME=UnknownIE */
			default: {
				ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK12*/(SETITEMS_c_TUserDataIE (Destin, i0+1), != ED_NO_ERRORS)
				ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK01*/(/*SETP3*/SETPRESENT_c_TUserDataIEUnion_UnknownIE (Destin->data [i0]), != ED_NO_ERRORS)
				Len = DECODE_c_TUnknownIE (Buffer, CurrOfs-16, Destin->data [i0]->u.UnknownIE, IEILen);
				i0++;
	Len -= 16;
				break;
			}
		}
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != IEILen) {
			ED_SIGNAL_ERROR ("<ERRID:395> Size error decoding IE\n");
			ED_HANDLE_IE_SIZE_ERROR (IEI, 395, NULL)
		} 
#endif
		CurrOfs += IEILen;
	}
	return CurrOfs-BitOffset;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TAddress* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#ifndef __LIB_23_040_H
#error "INCLUDE lib_23.040.h IN YOUR ed_user.h FILE"
#endif
		unsigned ret;
		int i;
		if (Source->TypeOfNumber == 5) {
			PUSH_INT (Source->Address.items * 7 / 4, 8);
		}
		else {
			PUSH_INT (Source->Address.items, 8);
		}
		PUSH_INT (1, 1);
		PUSH_INT (Source->TypeOfNumber, 3);
		PUSH_INT (Source->NumPlanId, 4);

		if (Source->TypeOfNumber == 5) {
			for (i=0; i<Source->Address.items; i++) {
				PUSH_INT (Source->Address.data [i], 7);
			}
			/* Fill remainder */
			if (CURPOS & 0x7) {
				PUSH_INT (0, 8-(CURPOS & 0x7));
			}
		}
		else {
			ret = ED23040_EncodeSemiOctet (Source->Address.items, Source->Address.data, Buffer, CURPOS);
			CURPOS += (ret << 3);
		}
		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TAddress* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned expectedItems, realItems, i;
		expectedItems = SHIFT_INT (8);
		SHIFT_INT (1); /* This is always set to 1 */
		Destin->TypeOfNumber = SHIFT_INT (3);
		Destin->NumPlanId = SHIFT_INT (4);
		/* Alphabetic encoding according to 3GPP TS 23.038 [9] GSM 7 bit default alphabet */
		if (Destin->TypeOfNumber == 5) {
			realItems = expectedItems * 4 / 7;
			SETITEMS_c_TAddress_Address (&(Destin->Address), realItems);
			for (i=0; i<realItems; i++) {
				Destin->Address.data [i] = (ED_OCTET)EDBitsToInt (Buffer, CURPOS+7*i, 7);
			}
		}
		else {
			SETITEMS_c_TAddress_Address (&(Destin->Address), expectedItems);
			realItems = ED23040_DecodeSemiOctet (expectedItems, Buffer, CURPOS, Destin->Address.data);
			SETITEMS_c_TAddress_Address (&(Destin->Address), realItems);
		}
		CURPOS += (((expectedItems+1) & ~1) << 2);
		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_DCS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_DCS* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		switch (Source->Content) {
			case 0:
			case 4: {
				PUSH_INT (Source->Content >> 2, 2);
				PUSH_BOOL (Source->Compressed);
				PUSH_BOOL (GETPRESENT_c_TP_DCS_MessageClass (Source));
				PUSH_INT (Source->CharSet, 2);
				if (GETPRESENT_c_TP_DCS_MessageClass (Source)) {
					PUSH_INT (Source->MessageClass, 2);
				} else {
					PUSH_INT (0, 2);
				}
				break;
			}
			case 12:
			case 13:
			case 14: {
				PUSH_INT (Source->Content, 4);
				PUSH_BOOL (Source->SetIndicationActive);
				PUSH_INT (0, 1);
				PUSH_INT (Source->IndicationType, 2);
				break;				
			}
			case 15: {
				PUSH_INT (Source->Content, 4);
				PUSH_INT (0, 1); /* Bit 3 is reserved */
				PUSH_BOOL (Source->CharSet != 0);
				PUSH_INT (Source->MessageClass, 2);
			}
			default: {
				PUSH_INT (Source->Content, 4);
				PUSH_INT (0, 4);
			}
		}
		return 8;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_DCS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_DCS* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int HasMessageClass = 0;
		Destin->RawData = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 8);
		
		/* Decode the first two bits and shift them two steps on the left */
		Destin->Content = (SHIFT_INT (2) << 2);
		
		/* If the decoded bits are not 00xx or 01xx, we decode the following
		   two bits as well. */
		if (Destin->Content != 0 && Destin->Content != 4) {
			Destin->Content |= SHIFT_INT (2);
		}
		
		switch (Destin->Content) {
			case 0:
			case 4: {
				Destin->Compressed = (SHIFT_INT (1)? ED_TRUE : ED_FALSE);
				HasMessageClass = (SHIFT_INT (1)? ED_TRUE : ED_FALSE);
				Destin->CharSet = SHIFT_INT (2);
				if (HasMessageClass) {
					SETPRESENT_c_TP_DCS_MessageClass (Destin, ED_TRUE);
					Destin->MessageClass = SHIFT_INT (2);
				} else {
					SETPRESENT_c_TP_DCS_MessageClass (Destin, ED_FALSE);
					Destin->MessageClass = 0;
				}
				break;
			}
			case 12:
			case 13:
			case 14: {
				Destin->Compressed = ED_FALSE;
				SETPRESENT_c_TP_DCS_MessageClass (Destin, ED_FALSE);
				Destin->SetIndicationActive = (SHIFT_INT (1)? ED_TRUE : ED_FALSE);
				SHIFT_INT (1); /* Bit 2 is reserved */
				Destin->IndicationType = SHIFT_INT (2);
				if (Destin->Content == 14) Destin->CharSet = 2;
				else Destin->CharSet = 0;
				break;				
			}
			case 15: {
				SHIFT_INT (1); /* Bit 3 is reserved */
				Destin->CharSet = (SHIFT_INT (1)? 1 : 0);
				SETPRESENT_c_TP_DCS_MessageClass (Destin, ED_TRUE);
				Destin->MessageClass = SHIFT_INT (2);
			}
			default: {
				Destin->Compressed = ED_FALSE;
				HasMessageClass = ED_FALSE;
				Destin->CharSet = 0;
				SETPRESENT_c_TP_DCS_MessageClass (Destin, ED_FALSE);
				Destin->MessageClass = 0;
			}
		}
		return 8;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_VP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_VP* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
		switch (GETPRESENT_c_TP_VP (Source)) {
			case U_c_TP_VP_Relative: PUSH_INT (Source->u.Relative, 8); return 8;
			case U_c_TP_VP_Absolute: ED23040_EncodeSemiOctet (14, Source->u.Absolute, Buffer, CURPOS); return 56;
			case U_c_TP_VP_Enhanced: {
#define ENHV VAR_c_TP_VP_Enhanced (Source->u.Enhanced)
#define EXTP PTR_c_TP_VP_Enhanced_Extension (ENHV.Extension)
				/* Zero all the buffer */
				for (i=0; i<7; i++) {
					EDIntToBits (Buffer, CURPOS+(i<<3), 0, 8);
				}
				if (ENHV.SingleShotSM) EDIntToBits (Buffer, CURPOS+1, 1, 1);
				EDIntToBits (Buffer, CURPOS+5, ENHV.ValidityPeriodFormat, 3);
				
				switch (GETPRESENT_c_TP_VP_Enhanced_Extension (EXTP)) {
					case U_c_TP_VP_Enhanced_Extension_NoValidityPeriod: {
						break;
					}
					case U_c_TP_VP_Enhanced_Extension_Relative: {
						/* Set the extension bit */
						EDIntToBits (Buffer, CURPOS, 1, 1);
						EDIntToBits (Buffer, CURPOS+8, EXTP->u.Relative, 8);
						break;
					}
					case U_c_TP_VP_Enhanced_Extension_RelativeInteger: {
						/* Set the extension bit */
						EDIntToBits (Buffer, CURPOS, 1, 1);
						EDIntToBits (Buffer, CURPOS+8, EXTP->u.RelativeInteger, 8);
						break;
					}
					case U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet: {
						/* Set the extension bit */
						EDIntToBits (Buffer, CURPOS, 1, 1);
						ED23040_EncodeSemiOctet (6, EXTP->u.RelativeSemiOctet, Buffer, CURPOS+8);
						break;
					}
					case U_c_TP_VP_Enhanced_Extension_UnknownExtension: {
#define UNEXV VAR_c_TP_VP_Enhanced_Extension_UnknownExtension (EXTP->u.UnknownExtension)
						/* Set the extension bit */
						EDIntToBits (Buffer, CURPOS, (UNEXV.ExtensionBit? 1 : 0), 1);
						/* Write the extension octets if present */
						for (i=0; i<6; i++) {
							EDIntToBits (Buffer, CURPOS+((i+1)<<3), UNEXV.UnknownOctets [i], 8);
						}
#undef UNEXV
						break;
					}
					default: return ED_SYNTAX_ERROR;
				}
				return 56;
#undef ENHV
#undef EXTP
			}
		}
		return ED_SYNTAX_ERROR;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_VP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_VP* ED_CONST Destin, ED_EXLONG Length, unsigned TV_VP))
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
		switch (TV_VP) {
			/* Enhanced format */
			case 1: {
#define ENHV VAR_c_TP_VP_Enhanced (Destin->u.Enhanced)
#define EXTP PTR_c_TP_VP_Enhanced_Extension (ENHV.Extension)
				SETPRESENT_c_TP_VP_Enhanced (Destin);
				ENHV.SingleShotSM = (EDBitsToInt (Buffer, CURPOS+1, 1) ? ED_TRUE : ED_FALSE);
				ENHV.ValidityPeriodFormat = EDBitsToInt (Buffer, CURPOS+5, 3);
				
				switch (ENHV.ValidityPeriodFormat) {
					case 0: {
						SETPRESENT_c_TP_VP_Enhanced_Extension_NoValidityPeriod (EXTP);
						break;
					}
					case 1: {
						SETPRESENT_c_TP_VP_Enhanced_Extension_Relative (EXTP); 
						EXTP->u.Relative = (ED_OCTET)EDBitsToInt (Buffer, CURPOS+8, 8);
						break;
					}
					case 2: {
						SETPRESENT_c_TP_VP_Enhanced_Extension_RelativeInteger (EXTP); 
						EXTP->u.RelativeInteger = (ED_OCTET)EDBitsToInt (Buffer, CURPOS+8, 8);
						break;
					}
					case 3: {
						SETPRESENT_c_TP_VP_Enhanced_Extension_RelativeSemiOctet (EXTP); 
						ED23040_DecodeSemiOctet (6, Buffer, CURPOS+8, EXTP->u.RelativeSemiOctet);
						break;
					}
					default: {
#define UNEXV VAR_c_TP_VP_Enhanced_Extension_UnknownExtension (EXTP->u.UnknownExtension)
						SETPRESENT_c_TP_VP_Enhanced_Extension_UnknownExtension (EXTP); 
						/* Get the extension bit */
						UNEXV.ExtensionBit = (EDBitsToInt (Buffer, CURPOS, 1) ? ED_TRUE : ED_FALSE);
						for (i=0; i<6; i++) {
							UNEXV.UnknownOctets [i] = (ED_OCTET)EDBitsToInt (Buffer, CURPOS+((i+1)<<3), 8);
						}
#undef UNEXV
					}
				}		
				
#undef ENHV
#undef EXTP
				return 56;
			}
			/* Relative format */
			case 2: {
				SETPRESENT_c_TP_VP_Relative (Destin);
				Destin->u.Relative = (ED_OCTET)SHIFT_INT (8);
				return 8;
			}
			/* Absolute format */
			case 3: {
				SETPRESENT_c_TP_VP_Absolute (Destin);
				ED23040_DecodeSemiOctet (14, Buffer, CURPOS, Destin->u.Absolute);
				return 56;
			}
			default: return ED_SYNTAX_ERROR; /* Invalid length! */
		}
		return 0;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_CD (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_CD* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
		PUSH_INT (Source->items, 8);
		for (i=0; i<Source->items; i++) {
			PUSH_INT (Source->data [i], 8);
		}
		return (CURPOS-BitOffset);
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_CD (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_CD* ED_CONST Destin, ED_EXLONG Length))
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
		int len = SHIFT_INT (8);
		SETITEMS_c_TP_CD (Destin, len);
		for (i=0; i<len; i++) {
			Destin->data [i] = (ED_OCTET)SHIFT_INT (8);
		}
		return (CURPOS-BitOffset);
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_UD (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_UD* ED_CONST Source, ED_BOOLEAN TP_UDHI, const c_TP_DCS* TP_DCS))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i;
	
		/* Size of the message character, in bits */
		int MsgCharSizeInBits = 8;
		
		/* Move after TP_UDL */
		CURPOS+=8;

		/* Does it have an header? */
		if (TP_UDHI) {
			int Encoded;
			Encoded = ENCODE_c_TUserDataIE (Buffer, CURPOS+8, &(Source->Header));
			if (Encoded < 0) return Encoded;
			PUSH_INT (Encoded>>3, 8);
			CURPOS += Encoded;			
		}

		/* If working with 7-bit words... */		
		if (TP_DCS->CharSet == 0 && !TP_DCS->Compressed) {
			MsgCharSizeInBits = 7;
			
			/* We must round up the current position to the first septet boundary writing zeroes */
			ZIF_PUSH_INT (0, (7-(CURPOS-BitOffset-8) % 7)%7);
		}

		/* If working with 16-bit words... */		
		if (TP_DCS->CharSet == 2 && !TP_DCS->Compressed) {
			MsgCharSizeInBits = 16;
		}
		
		for (i=0; i<Source->Message.items; i++) {
			ZIF_PUSH_INT (Source->Message.data [i], MsgCharSizeInBits);
		}

		/* Write UDL value */
		if (MsgCharSizeInBits == 16) {
			EDIntToBits (Buffer, BitOffset, Source->Message.items*2, 8);
		}
		else {
		EDIntToBits (Buffer, BitOffset, (CURPOS-BitOffset-8)/MsgCharSizeInBits, 8);
		}

		/* Fill the remainder with zeroes */
		ZIF_PUSH_INT (0, (8 - ((CURPOS-BitOffset) & 7)) & 7);

		return (CURPOS-BitOffset);
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_UD (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_UD* ED_CONST Destin, ED_EXLONG Length, ED_BOOLEAN TP_UDHI, c_TP_DCS* TP_DCS))
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
	
		/* Size of the message character, in bits */
		int MsgCharSizeInBits = 8;
		
		/* Read UDL value */
		int UDL = SHIFT_INT (8);
		
		Destin->CharSet = TP_DCS->CharSet;
		
		/* Does it have an header? */
		if (TP_UDHI) {
			int Decoded;
			int HeaderSizeInBits = (SHIFT_INT (8) << 3);
			Decoded = DECODE_c_TUserDataIE (Buffer, CURPOS, &(Destin->Header), HeaderSizeInBits);
			if (Decoded != HeaderSizeInBits) {
				return ED_SYNTAX_ERROR;
			}
			CURPOS += Decoded;			
		}
		
		/* If working with 7-bit words... */		
		if (TP_DCS->CharSet == 0 && !TP_DCS->Compressed) {
			MsgCharSizeInBits = 7;
			
			/* We must round up the current position to the first septet boundary */
			CURPOS = (((CURPOS-BitOffset-8)+6)/7*7)+BitOffset+8;
		}

		/* If working with 16-bit words... */		
		if (TP_DCS->CharSet == 2 && !TP_DCS->Compressed) {
			MsgCharSizeInBits = 16;
			UDL /= 2;
		}
		else {
		/* Calculate the remaining items */
		UDL -= (CURPOS-BitOffset-8)/MsgCharSizeInBits;
		}
		
		/* Do we have enough bits left? */
		if ((UDL * MsgCharSizeInBits) > (Length - (CURPOS-BitOffset-8))) {
			return ED_SYNTAX_ERROR;
		}
		
		SETITEMS_c_TP_UD_Message (&(Destin->Message), UDL);
		
		for (i=0; i<UDL; i++) {
			Destin->Message.data [i] = ZIF_SHIFT_INT (MsgCharSizeInBits);
		}
		
		/* Return the length rounded up to next octet boundary */
		return ((CURPOS-BitOffset)+7)&~7;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_MTI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_MTI* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		return 0;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_MTI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_MTI* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		Destin->TP_MTI = EDBitsToInt (Buffer, BitOffset-8, 8) & 3;
		return 0;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUnknownIE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUnknownIE* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		/* Write the IEI */
		PUSH_INT (VAR_c_TUnknownIE_IEI (Source->IEI), 8);
		/* Write the length in octets, rounded up to the nearest integer */
		PUSH_INT ((VAR_c_TUnknownIE_RawData (Source->RawData).usedBits + 7) >> 3, 8);
		/* Write the data */
		EDCopyBits (Buffer, CURPOS, VAR_c_TUnknownIE_RawData (Source->RawData).value, 0, VAR_c_TUnknownIE_RawData (Source->RawData).usedBits);
		CURPOS += VAR_c_TUnknownIE_RawData (Source->RawData).usedBits;
		/* Pad with zero if not exactly at the octet boundary */
		PUSH_INT (0, (8 - ((CURPOS-BitOffset) & 7)) & 7);
		return CURPOS-BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUnknownIE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUnknownIE* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int lenInBits;
		
		/* Read the IEI */
		VAR_c_TUnknownIE_IEI (Destin->IEI) = SHIFT_INT (8);
		/* Read the length in octets and convert it in bits */
		lenInBits = SHIFT_INT (8) << 3;
		/* Allocate the data */
		ALLOC_c_TUnknownIE_RawData (PTR_c_TUnknownIE_RawData (Destin->RawData), lenInBits);
		VAR_c_TUnknownIE_RawData (Destin->RawData).usedBits = lenInBits;
		/* Read the data */
		EDCopyBits (VAR_c_TUnknownIE_RawData (Destin->RawData).value, 0, Buffer, CURPOS, lenInBits);
		CURPOS += lenInBits;

		return CURPOS-BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailInfo (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailInfo* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int Length = 0;
		switch (GETPRESENT_c_TEnVoiceMailInfo (Source)) {
			case U_c_TEnVoiceMailInfo_voiceMailNotification: {
				Length = ENCODE_c_TEnVoiceMailNotification (Buffer, BitOffset, ED_AMP(Source->u.voiceMailNotification));
				break;
			}
			case U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation: {
				Length = ENCODE_c_TEnVoiceMailDeleteConfirmation (Buffer, BitOffset, ED_AMP(Source->u.voiceMailDeleteConfirmation));
				break;
			}
		}
		return Length;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailInfo (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailInfo* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int Ret = 0;
		int ENHANCED_VOICE_MAIL_PDU_TYPE = EDZIFBitsToInt (Buffer, BitOffset, 1);
		if (ENHANCED_VOICE_MAIL_PDU_TYPE == 0) {
			SETPRESENT_c_TEnVoiceMailInfo_voiceMailNotification (Destin);
			Ret = DECODE_c_TEnVoiceMailNotification (Buffer, BitOffset, ED_AMP(Destin->u.voiceMailNotification), Length);
		}
		else {
			SETPRESENT_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation (Destin);
			Ret = DECODE_c_TEnVoiceMailDeleteConfirmation (Buffer, BitOffset, ED_AMP(Destin->u.voiceMailDeleteConfirmation), Length);
		}
		if (Ret > Length) return ED_MESSAGE_TOO_SHORT;
		return Ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailNotification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailNotification* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		int i;
		
		ZIF_PUSH_INT (Source->ENHANCED_VOICE_MAIL_PDU_TYPE, 1);
		ZIF_PUSH_INT (0, 1);
		ZIF_PUSH_INT (Source->MULTIPLE_SUBSCRIBER_PROFILE, 2);
		ZIF_PUSH_INT (Source->SM_STORAGE, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_ALMOST_FULL, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_FULL, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_STATUS_EXTENSION_INDICATOR, 1);
		
		ret = ENCODE_c_TAddress (Buffer, CURPOS, &(Source->VM_MAILBOX_ACCESS_ADDRESS));
		if (ret < 0) return ret;
		CURPOS += ret;
		
		ZIF_PUSH_INT (Source->NUMBER_OF_VOICE_MESSAGES, 8);
		ZIF_PUSH_INT (Source->NUMBER_OF_VM_NOTIFICATIONS, 4);
		ZIF_PUSH_INT (0, 4);

		if (Source->VM_MAILBOX_STATUS_EXTENSION_INDICATOR) {
			octets = VAR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA (Source->VM_MAILBOX_STATUS_EXTENSION_DATA).usedBits / 8;
			ZIF_PUSH_INT (octets, 8);
			PUSH_BIN (VAR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA (Source->VM_MAILBOX_STATUS_EXTENSION_DATA).value, octets * 8);
		}

		for (i=0; i<PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (Source->VM_NOTIFICATIONS)->items; i++) {
			ret = ENCODE_c_TEnVoiceMailNotificationItem (Buffer, CURPOS, ED_AMP (PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (Source->VM_NOTIFICATIONS)->data [i]));
			if (ret < 0) return ret;
			CURPOS += ret;
		}
		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailNotification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailNotification* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		int i;
		
		Destin->ENHANCED_VOICE_MAIL_PDU_TYPE = ZIF_SHIFT_INT (1);
		CURPOS++; /* Skip RESERVED_FOR_FUTURE_USE */
		Destin->MULTIPLE_SUBSCRIBER_PROFILE = ZIF_SHIFT_INT (2);
		Destin->SM_STORAGE = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_ALMOST_FULL = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_FULL = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_STATUS_EXTENSION_INDICATOR = ZIF_SHIFT_INT (1);

		ret = DECODE_c_TAddress (Buffer, CURPOS, &(Destin->VM_MAILBOX_ACCESS_ADDRESS), Length-CURPOS);
		if (ret < 0) return ret;
		CURPOS += ret;

		Destin->NUMBER_OF_VOICE_MESSAGES = ZIF_SHIFT_INT (8);
		Destin->NUMBER_OF_VM_NOTIFICATIONS = ZIF_SHIFT_INT (4);
		CURPOS+=4;

		if (Destin->VM_MAILBOX_STATUS_EXTENSION_INDICATOR) {
			octets = ZIF_SHIFT_INT (8);
			ALLOC_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA (PTR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA (Destin->VM_MAILBOX_STATUS_EXTENSION_DATA), octets*8);
		}
		
		SETITEMS_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (Destin->VM_NOTIFICATIONS), Destin->NUMBER_OF_VM_NOTIFICATIONS);
		for (i=0; i<Destin->NUMBER_OF_VM_NOTIFICATIONS; i++) {
			ret = DECODE_c_TEnVoiceMailNotificationItem (Buffer, CURPOS, ED_AMP (PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (Destin->VM_NOTIFICATIONS)->data [i]), Length-CURPOS);
			if (ret < 0) return ret;
			CURPOS += ret;
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailNotificationItem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailNotificationItem* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		ZIF_PUSH_INT (Source->VM_MESSAGE_ID, 16);
		ZIF_PUSH_INT (Source->VM_MESSAGE_LENGTH, 8);
		ZIF_PUSH_INT (Source->VM_MESSAGE_RETENTION_DAYS, 5);
		ZIF_PUSH_INT (0, 1);
		ZIF_PUSH_INT (Source->VM_MESSAGE_PRIORITY_INDICATION, 1);
		ZIF_PUSH_INT (Source->VM_MESSAGE_EXTENSION_INDICATOR, 1);

		ret = ENCODE_c_TAddress (Buffer, CURPOS, &(Source->VM_MESSAGE_CALLING_LINE_IDENTITY));
		if (ret < 0) return ret;
		CURPOS += ret;

		if (Source->VM_MESSAGE_EXTENSION_INDICATOR) {
			octets = VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (Source->VM_MESSAGE_EXTENSION_DATA).usedBits / 8;
			ZIF_PUSH_INT (octets, 8);
			PUSH_BIN (VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (Source->VM_MESSAGE_EXTENSION_DATA).value, octets * 8);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailNotificationItem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailNotificationItem* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		
		Destin->VM_MESSAGE_ID = ZIF_SHIFT_INT (16);
		Destin->VM_MESSAGE_LENGTH = ZIF_SHIFT_INT (8);
		Destin->VM_MESSAGE_RETENTION_DAYS = ZIF_SHIFT_INT (5);
		CURPOS++;
		Destin->VM_MESSAGE_PRIORITY_INDICATION = ZIF_SHIFT_INT (1);
		Destin->VM_MESSAGE_EXTENSION_INDICATOR = ZIF_SHIFT_INT (1);

		ret = DECODE_c_TAddress (Buffer, CURPOS, &(Destin->VM_MESSAGE_CALLING_LINE_IDENTITY), Length-CURPOS);
		if (ret < 0) return ret;
		CURPOS += ret;

		if (Destin->VM_MESSAGE_EXTENSION_INDICATOR) {
			octets = ZIF_SHIFT_INT (8);
			ALLOC_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (Destin->VM_MESSAGE_EXTENSION_DATA), octets*8);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailDeleteConfirmation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailDeleteConfirmation* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		int i;
		
		ZIF_PUSH_INT (Source->ENHANCED_VOICE_MAIL_PDU_TYPE, 1);
		ZIF_PUSH_INT (0, 1);
		ZIF_PUSH_INT (Source->MULTIPLE_SUBSCRIBER_PROFILE, 2);
		ZIF_PUSH_INT (Source->SM_STORAGE, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_ALMOST_FULL, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_FULL, 1);
		ZIF_PUSH_INT (Source->VM_MAILBOX_STATUS_EXTENSION_INDICATOR, 1);

		ret = ENCODE_c_TAddress (Buffer, CURPOS, &(Source->VM_MAILBOX_ACCESS_ADDRESS));
		if (ret < 0) return ret;
		CURPOS += ret;

		ZIF_PUSH_INT (Source->NUMBER_OF_VOICE_MESSAGES, 8);
		ZIF_PUSH_INT (Source->NUMBER_OF_VM_DELETES, 4);
		ZIF_PUSH_INT (0, 4);

		if (Source->VM_MAILBOX_STATUS_EXTENSION_INDICATOR) {
			octets = VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA (Source->VM_MAILBOX_STATUS_EXTENSION_DATA).usedBits / 8;
			ZIF_PUSH_INT (octets, 8);
			PUSH_BIN (VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA (Source->VM_MAILBOX_STATUS_EXTENSION_DATA).value, octets * 8);
		}

		for (i=0; i<PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (Source->VM_DELETE_CONFIRMATIONS)->items; i++) {
			ret = ENCODE_c_TEnVoiceMailDeleteConfirmationItem (Buffer, CURPOS, ED_AMP (PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (Source->VM_DELETE_CONFIRMATIONS)->data [i]));
			if (ret < 0) return ret;
			CURPOS += ret;
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailDeleteConfirmation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailDeleteConfirmation* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret;
		int octets;
		int i;
		
		Destin->ENHANCED_VOICE_MAIL_PDU_TYPE = ZIF_SHIFT_INT (1);
		CURPOS++; /* Skip RESERVED_FOR_FUTURE_USE */
		Destin->MULTIPLE_SUBSCRIBER_PROFILE = ZIF_SHIFT_INT (2);
		Destin->SM_STORAGE = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_ALMOST_FULL = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_FULL = ZIF_SHIFT_INT (1);
		Destin->VM_MAILBOX_STATUS_EXTENSION_INDICATOR = ZIF_SHIFT_INT (1);

		ret = DECODE_c_TAddress (Buffer, CURPOS, &(Destin->VM_MAILBOX_ACCESS_ADDRESS), Length-CURPOS);
		if (ret < 0) return ret;
		CURPOS += ret;

		Destin->NUMBER_OF_VOICE_MESSAGES = ZIF_SHIFT_INT (8);
		Destin->NUMBER_OF_VM_DELETES = ZIF_SHIFT_INT (4);
		CURPOS+=4; /* Skip RESERVED_FOR_FUTURE_USE */

		if (Destin->VM_MAILBOX_STATUS_EXTENSION_INDICATOR) {
			octets = ZIF_SHIFT_INT (8);
			ALLOC_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA (PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA (Destin->VM_MAILBOX_STATUS_EXTENSION_DATA), octets*8);
		}

		SETITEMS_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (Destin->VM_DELETE_CONFIRMATIONS), Destin->NUMBER_OF_VM_DELETES);
		for (i=0; i<Destin->NUMBER_OF_VM_DELETES; i++) {
			ret = DECODE_c_TEnVoiceMailDeleteConfirmationItem (Buffer, CURPOS, ED_AMP (PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (Destin->VM_DELETE_CONFIRMATIONS)->data [i]), Length-CURPOS);
			if (ret < 0) return ret;
			CURPOS += ret;
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailDeleteConfirmationItem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailDeleteConfirmationItem* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int octets;
		ZIF_PUSH_INT (Source->VM_MESSAGE_ID, 16);
		ZIF_PUSH_INT (0, 7);
		ZIF_PUSH_INT (Source->VM_MESSAGE_EXTENSION_INDICATOR, 1);

		if (Source->VM_MESSAGE_EXTENSION_INDICATOR) {
			octets = VAR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA (Source->VM_MESSAGE_EXTENSION_DATA).usedBits / 8;
			ZIF_PUSH_INT (octets, 8);
			PUSH_BIN (VAR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA (Source->VM_MESSAGE_EXTENSION_DATA).value, octets * 8);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailDeleteConfirmationItem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailDeleteConfirmationItem* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int octets;
		
		Destin->VM_MESSAGE_ID = ZIF_SHIFT_INT (16);
		CURPOS += 7;
		Destin->VM_MESSAGE_EXTENSION_INDICATOR = ZIF_SHIFT_INT (1);

		if (Destin->VM_MESSAGE_EXTENSION_INDICATOR) {
			octets = ZIF_SHIFT_INT (8);
			ALLOC_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA (Destin->VM_MESSAGE_EXTENSION_DATA), octets*8);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_T24011Address (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_T24011Address* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#ifndef __LIB_23_040_H
#error "INCLUDE lib_23.040.h IN YOUR ed_user.h FILE"
#endif
		unsigned ret;
		if (!GETPRESENT_c_T24011Address_Addr (Source)) return 0;
#define ADDR VAR_c_T24011Address_Addr(Source->Addr)
		PUSH_INT (1, 1);
		PUSH_INT (VAR_c_T24011Address_Addr_TypeOfNumber (ADDR.TypeOfNumber), 3);
		PUSH_INT (VAR_c_T24011Address_Addr_NumPlanId (ADDR.NumPlanId), 4);
		ret = ED23040_EncodeSemiOctet (
			VAR_c_T24011Address_Addr_Address (ADDR.Address).items,
			VAR_c_T24011Address_Addr_Address_data (VAR_c_T24011Address_Addr_Address (ADDR.Address).data), 
			Buffer, CURPOS);
		CURPOS += (ret << 3);
		return CURPOS - BitOffset;
#undef ADDR
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_T24011Address (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_T24011Address* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned expectedItems, realItems;
		if (Length <= 0) {
			SETPRESENT_c_T24011Address_Addr (Destin, ED_FALSE);
			return 0;
		}
#define ADDR VAR_c_T24011Address_Addr(Destin->Addr)
		SETPRESENT_c_T24011Address_Addr (Destin, ED_TRUE);
		expectedItems = (Length - 8) >> 2;
		SHIFT_INT (1); /* This is always set to 1 */
		VAR_c_T24011Address_Addr_TypeOfNumber (ADDR.TypeOfNumber) = (ED_OCTET)SHIFT_INT (3);
		VAR_c_T24011Address_Addr_NumPlanId (ADDR.NumPlanId) = (ED_OCTET)SHIFT_INT (4);
		SETITEMS_c_T24011Address_Addr_Address (PTR_c_T24011Address_Addr_Address (ADDR.Address), expectedItems);
		realItems = ED23040_DecodeSemiOctet (expectedItems, Buffer, CURPOS, VAR_c_T24011Address_Addr_Address_data (VAR_c_T24011Address_Addr_Address (ADDR.Address).data));
		SETITEMS_c_T24011Address_Addr_Address (PTR_c_T24011Address_Addr_Address (ADDR.Address), realItems);
		CURPOS += (((expectedItems+1) & ~1) << 2);
		return CURPOS - BitOffset;
#undef ADDR
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_MS2SC_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_MS2SC (Source)) {
			SMS_ENCODE(SMS_SUBMIT);
			SMS_ENCODE(SMS_COMMAND);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_MS2SC_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 1: SMS_DECODE(SMS_SUBMIT); break;
			case 2: SMS_DECODE(SMS_COMMAND); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_SC2MS_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_SC2MS (Source)) {
			SMS_ENCODE(SMS_DELIVER);
			SMS_ENCODE(SMS_STATUS_REPORT);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_SC2MS_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 0: SMS_DECODE(SMS_DELIVER); break;
			case 2: SMS_DECODE(SMS_STATUS_REPORT); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC_ERR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC_ERR* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_MS2SC_ERR_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_MS2SC_ERR (Source)) {
			SMS_ENCODE(SMS_STATUS_REPORT);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC_ERR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC_ERR* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_MS2SC_ERR_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 0: SMS_DECODE(SMS_STATUS_REPORT); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC_ACK* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_MS2SC_ACK_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_MS2SC_ACK (Source)) {
			SMS_ENCODE(SMS_STATUS_REPORT);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC_ACK* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_MS2SC_ACK_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 0: SMS_DECODE(SMS_STATUS_REPORT); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS_ERR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS_ERR* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_SC2MS_ERR_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_SC2MS_ERR (Source)) {
			SMS_ENCODE(SMS_STATUS_REPORT);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS_ERR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS_ERR* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_SC2MS_ERR_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 1: SMS_DECODE(SMS_STATUS_REPORT); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS_ACK* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define SMS_ENCODE(TYPNAM) case U_c_SMS_SC2MS_ACK_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_SMS_SC2MS_ACK (Source)) {
			SMS_ENCODE(SMS_STATUS_REPORT);
			SMS_ENCODE(SMS_UNKNOWN);
		}

		return ret;
#undef SMS_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS_ACK* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8) & 0x03;

#define SMS_DECODE(TYPNAM) {SETPRESENT_c_SMS_SC2MS_ACK_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 1: SMS_DECODE(SMS_STATUS_REPORT); break;
			default: SMS_DECODE(SMS_UNKNOWN); break;
		}
		return ret;
#undef SMS_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CPUserData (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CPUserData* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret=0;
#define CP_ENCODE(TYPNAM) case U_c_CPUserData_##TYPNAM: ret = ENCODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Source->u.TYPNAM)); break;

		switch (GETPRESENT_c_CPUserData (Source)) {
			CP_ENCODE(RP_DATA_MS2MSC);
			CP_ENCODE(RP_DATA_MSC2MS);
			CP_ENCODE(RP_RP_ACK_MS2MSC);
			CP_ENCODE(RP_RP_ACK_MSC2MS);
			CP_ENCODE(RP_RP_ERROR_MS2MSC);
			CP_ENCODE(RP_RP_ERROR_MSC2MS);
			CP_ENCODE(RP_RP_SMMA_MS2MSC);
			CP_ENCODE(RP_UNKNOWN);
		}

		return ret;
#undef CP_ENCODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CPUserData (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CPUserData* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned id;
		int ret;

		id = SHIFT_INT (8);

#define CP_DECODE(TYPNAM) {SETPRESENT_c_CPUserData_##TYPNAM (Destin); ret = DECODE_c_##TYPNAM (Buffer, BitOffset, ED_AMP(Destin->u.TYPNAM), Length);}

		switch (id) {
			case 0: CP_DECODE(RP_DATA_MS2MSC); break;
			case 1: CP_DECODE(RP_DATA_MSC2MS); break;
			case 2: CP_DECODE(RP_RP_ACK_MS2MSC); break;
			case 3: CP_DECODE(RP_RP_ACK_MSC2MS); break;
			case 4: CP_DECODE(RP_RP_ERROR_MS2MSC); break;
			case 5: CP_DECODE(RP_RP_ERROR_MSC2MS); break;
			case 6: CP_DECODE(RP_RP_SMMA_MS2MSC); break;
			default: CP_DECODE(RP_UNKNOWN); break;
		}
		return ret;
#undef CP_DECODE
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_SMS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_SMS* ED_CONST Source))
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_SMS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_SMS* ED_CONST Destin, ED_EXLONG Length))
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
		ALLOC_c_GenericTLV_SMS_TLV_Data (&(Destin->TLV_Data), DataLength);

		
		/* Save the bits in the binary data */
		EDCopyBits (Destin->TLV_Data.value, 0, Buffer, CurrOfs, DataLength);
		CurrOfs += (ED_EXLONG)EffectiveDataLength;
	}
	
	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
