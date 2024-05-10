/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "UserDefinedDataTypes_RR.h"
#include "ed_c_known_ie_RR.h"
#include "ed_tlv.h"
#include "CSN1DataTypes_RR.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SCH_SYNC_CHANNEL_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SCH_SYNC_CHANNEL_INFORMATION* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 25;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).BSIC), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1397> Error encoding subfield BSIC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).T1), 11);
	Ret = 11;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1398> Error encoding subfield T1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+17), (int)((*Source).T2), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1399> Error encoding subfield T2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).T3), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1400> Error encoding subfield T3\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SCH_SYNC_CHANNEL_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SCH_SYNC_CHANNEL_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).BSIC = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).BSIC___LOCATOR), CurrOfs, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1401> Error decoding subfield BSIC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1401)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).T1 = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+6), 11);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T1___LOCATOR), CurrOfs+6, 11);
	Ret = 11;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1402> Error decoding subfield T1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1402)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	(*Destin).T2 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+17, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T2___LOCATOR), CurrOfs+17, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1403> Error decoding subfield T2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1403)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).T3 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+22, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T3___LOCATOR), CurrOfs+22, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1404> Error decoding subfield T3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1404)
	} 
#endif
	Len += Ret;
	

	}
	return 25;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CSCH_SYNC_CHANNEL_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CSCH_SYNC_CHANNEL_INFORMATION* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 25;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).BSIC), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1405> Error encoding subfield BSIC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).R1), 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1406> Error encoding subfield R1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).R2), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1407> Error encoding subfield R2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).TG), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1408> Error encoding subfield TG\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+24, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1409> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CSCH_SYNC_CHANNEL_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CSCH_SYNC_CHANNEL_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).BSIC = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).BSIC___LOCATOR), CurrOfs, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1410> Error decoding subfield BSIC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1410)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).R1 = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+6), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).R1___LOCATOR), CurrOfs+6, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1411> Error decoding subfield R1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1411)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).R2 = (unsigned char)EDBitsToInt (Buffer, CurrOfs+16, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).R2___LOCATOR), CurrOfs+16, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1412> Error decoding subfield R2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1412)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).TG = (unsigned char)EDBitsToInt (Buffer, CurrOfs+22, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TG___LOCATOR), CurrOfs+22, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1413> Error decoding subfield TG\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1413)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1414> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1414)
	} 
#endif
	Len += Ret;
	

	}
	return 25;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_SCH_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_SCH_INFORMATION* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 32;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).T1_Hi), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1415> Error encoding subfield T1_Hi\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).BSIC_Hi), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1416> Error encoding subfield BSIC_Hi\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).T2_Hi), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1417> Error encoding subfield T2_Hi\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).T1_Low), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1418> Error encoding subfield T1_Low\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).RACHAccessControl != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1419> Error encoding subfield RACHAccessControl\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+17), (int)((*Source).EC_BCCH_ChangeMark), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1420> Error encoding subfield EC_BCCH_ChangeMark\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).ImplicitRejectStatus), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1421> Error encoding subfield ImplicitRejectStatus\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).T2_Low), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1422> Error encoding subfield T2_Low\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+26), (int)((*Source).BSIC_Low), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1423> Error encoding subfield BSIC_Low\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+29, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1424> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_SCH_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_SCH_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).T1_Hi = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T1_Hi___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1425> Error decoding subfield T1_Hi\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1425)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).BSIC_Hi = (unsigned char)EDBitsToInt (Buffer, CurrOfs+2, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).BSIC_Hi___LOCATOR), CurrOfs+2, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1426> Error decoding subfield BSIC_Hi\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1426)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).T2_Hi = (unsigned char)EDBitsToInt (Buffer, CurrOfs+8, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T2_Hi___LOCATOR), CurrOfs+8, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1427> Error decoding subfield T2_Hi\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1427)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).T1_Low = (unsigned char)EDBitsToInt (Buffer, CurrOfs+10, 6);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T1_Low___LOCATOR), CurrOfs+10, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1428> Error decoding subfield T1_Low\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1428)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).RACHAccessControl = (EDBitsToInt (Buffer, CurrOfs+16, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).RACHAccessControl___LOCATOR), CurrOfs+16, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1429> Error decoding subfield RACHAccessControl\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1429)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	(*Destin).EC_BCCH_ChangeMark = (unsigned char)EDBitsToInt (Buffer, CurrOfs+17, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).EC_BCCH_ChangeMark___LOCATOR), CurrOfs+17, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1430> Error decoding subfield EC_BCCH_ChangeMark\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1430)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).ImplicitRejectStatus = (unsigned char)EDBitsToInt (Buffer, CurrOfs+20, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).ImplicitRejectStatus___LOCATOR), CurrOfs+20, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1431> Error decoding subfield ImplicitRejectStatus\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1431)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).T2_Low = (unsigned char)EDBitsToInt (Buffer, CurrOfs+22, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).T2_Low___LOCATOR), CurrOfs+22, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1432> Error decoding subfield T2_Low\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1432)
	} 
#endif
	Len += Ret;
	
	/* FromBit=26 */
	(*Destin).BSIC_Low = (unsigned char)EDBitsToInt (Buffer, CurrOfs+26, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).BSIC_Low___LOCATOR), CurrOfs+26, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1433> Error decoding subfield BSIC_Low\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1433)
	} 
#endif
	Len += Ret;
	
	/* FromBit=29 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1434> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1434)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CipheringKeySequenceNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CipheringKeySequenceNumber* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).KeySequence), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1435> Error encoding subfield KeySequence\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1436> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CipheringKeySequenceNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CipheringKeySequenceNumber* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=1 */
	(*Destin).KeySequence = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).KeySequence___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1437> Error decoding subfield KeySequence\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1437)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1438> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1438)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DescGrpOrBcastCallRef (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DescGrpOrBcastCallRef* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 40;
	EDCopyBits (Buffer, CurrOfs, ((*Source).BinaryCoding), 0, 27);
	Ret = 27;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1439> Error encoding subfield BinaryCoding\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+27), (int)((*Source).SF != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1440> Error encoding subfield SF\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+29), (int)((*Source).CallPriority), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1441> Error encoding subfield CallPriority\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).CypheringInfo), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1442> Error encoding subfield CypheringInfo\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+36, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1443> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DescGrpOrBcastCallRef (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DescGrpOrBcastCallRef* ED_CONST Destin, ED_EXLONG Length))
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
	EDCopyBits ((*Destin).BinaryCoding, 0, Buffer, CurrOfs, 27);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&((*Destin).BinaryCoding___LOCATOR), CurrOfs, 27);
	Ret = 27;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1444> Error decoding subfield BinaryCoding\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1444)
	} 
#endif
	Len += Ret;
	
	/* FromBit=27 */
	(*Destin).SF = (EDBitsToInt (Buffer, CurrOfs+27, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SF___LOCATOR), CurrOfs+27, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1445> Error decoding subfield SF\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1445)
	} 
#endif
	Len += Ret;
	
	/* FromBit=29 */
	(*Destin).CallPriority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+29), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CallPriority___LOCATOR), CurrOfs+29, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1446> Error decoding subfield CallPriority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1446)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).CypheringInfo = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+32), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CypheringInfo___LOCATOR), CurrOfs+32, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1447> Error decoding subfield CypheringInfo\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1447)
	} 
#endif
	Len += Ret;
	
	/* FromBit=36 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1448> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1448)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CellDescription (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CellDescription* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).BCCHArfcnHi), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1449> Error encoding subfield BCCHArfcnHi\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).NCC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1450> Error encoding subfield NCC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).BCC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1451> Error encoding subfield BCC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).BCCHArfcnLo), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1452> Error encoding subfield BCCHArfcnLo\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CellDescription (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CellDescription* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).BCCHArfcnHi = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).BCCHArfcnHi___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1453> Error decoding subfield BCCHArfcnHi\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1453)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).NCC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NCC___LOCATOR), CurrOfs+2, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1454> Error decoding subfield NCC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1454)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).BCC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).BCC___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1455> Error decoding subfield BCC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1455)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).BCCHArfcnLo = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).BCCHArfcnLo___LOCATOR), CurrOfs+8, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1456> Error decoding subfield BCCHArfcnLo\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1456)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CellOptions (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CellOptions* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).DN_IND != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1457> Error encoding subfield DN_IND\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).PWRC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1458> Error encoding subfield PWRC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).DTX), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1459> Error encoding subfield DTX\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).RadioLinkTimeout), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1460> Error encoding subfield RadioLinkTimeout\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CellOptions (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CellOptions* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).DN_IND = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DN_IND___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1461> Error decoding subfield DN_IND\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1461)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).PWRC = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PWRC___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1462> Error decoding subfield PWRC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1462)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).DTX = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).DTX___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1463> Error decoding subfield DTX\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1463)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).RadioLinkTimeout = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RadioLinkTimeout___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1464> Error decoding subfield RadioLinkTimeout\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1464)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CellSelParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CellSelParam* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).CellReseHyst), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1465> Error encoding subfield CellReseHyst\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).MsTxpwrMaxCch), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1466> Error encoding subfield MsTxpwrMaxCch\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).ACS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1467> Error encoding subfield ACS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).NECI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1468> Error encoding subfield NECI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).RxLevAccessMin), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1469> Error encoding subfield RxLevAccessMin\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CellSelParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CellSelParam* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).CellReseHyst = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CellReseHyst___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1470> Error decoding subfield CellReseHyst\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1470)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).MsTxpwrMaxCch = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MsTxpwrMaxCch___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1471> Error decoding subfield MsTxpwrMaxCch\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1471)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).ACS = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ACS___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1472> Error decoding subfield ACS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1472)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).NECI = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NECI___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1473> Error decoding subfield NECI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1473)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).RxLevAccessMin = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+10), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RxLevAccessMin___LOCATOR), CurrOfs+10, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1474> Error decoding subfield RxLevAccessMin\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1474)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MACModeAndChCodReq (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MACModeAndChCodReq* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Mac0Mode), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1475> Error encoding subfield Mac0Mode\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CS), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1476> Error encoding subfield CS\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MACModeAndChCodReq (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MACModeAndChCodReq* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Mac0Mode = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Mac0Mode___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1477> Error decoding subfield Mac0Mode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1477)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).CS = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CS___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1478> Error decoding subfield CS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1478)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TChDesc (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TChDesc* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	Ret = ENCODE_c_TChType (Buffer, CurrOfs, (&((*Source).ChType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1479> Error encoding subfield ChType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TN), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1480> Error encoding subfield TN\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).TSC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1481> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).H != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1482> Error encoding subfield H\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MAIO), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1483> Error encoding subfield MAIO\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).HSN), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1484> Error encoding subfield HSN\n");
			return -1;
		} 
#endif
	}
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+12, 0, 2);Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1485> Error encoding subfield spare\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).ARFCN), 10);
		Ret = 10;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1486> Error encoding subfield ARFCN\n");
			return -1;
		} 
#endif
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TChDesc (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TChDesc* ED_CONST Destin, ED_EXLONG Length))
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
	Ret = DECODE_c_TChType (Buffer, CurrOfs, (&((*Destin).ChType)), 5);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1487> Error decoding subfield ChType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1487)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TN___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1488> Error decoding subfield TN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1488)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).TSC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs+8, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1489> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1489)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).H = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).H___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1490> Error decoding subfield H\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1490)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc_MAIO (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).MAIO = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 6);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).MAIO___LOCATOR), CurrOfs+12, 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1491> Error decoding subfield MAIO\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1491)
		} 
#endif
		Len += Ret;
	
	/* FromBit=18 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc_HSN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).HSN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+18), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSN___LOCATOR), CurrOfs+18, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1492> Error decoding subfield HSN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1492)
	} 
#endif
	Len += Ret;
	}
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc_spare (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1493> Error decoding subfield spare\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1493)
		} 
#endif
		Len += Ret;
	
	/* FromBit=14 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc_ARFCN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).ARFCN = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+14), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ARFCN___LOCATOR), CurrOfs+14, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1494> Error decoding subfield ARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1494)
	} 
#endif
	Len += Ret;
	}
	

	}
	return 24;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TChDesc2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TChDesc2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	Ret = ENCODE_c_TChType2 (Buffer, CurrOfs, (&((*Source).ChType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1495> Error encoding subfield ChType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TN), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1496> Error encoding subfield TN\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).TSC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1497> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).H != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1498> Error encoding subfield H\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MAIO), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1499> Error encoding subfield MAIO\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).HSN), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1500> Error encoding subfield HSN\n");
			return -1;
		} 
#endif
	}
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+12, 0, 2);Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1501> Error encoding subfield spare\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).ARFCN), 10);
		Ret = 10;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1502> Error encoding subfield ARFCN\n");
			return -1;
		} 
#endif
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TChDesc2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TChDesc2* ED_CONST Destin, ED_EXLONG Length))
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
	Ret = DECODE_c_TChType2 (Buffer, CurrOfs, (&((*Destin).ChType)), 5);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1503> Error decoding subfield ChType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1503)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TN___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1504> Error decoding subfield TN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1504)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).TSC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs+8, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1505> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1505)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).H = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).H___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1506> Error decoding subfield H\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1506)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc2_MAIO (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).MAIO = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 6);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).MAIO___LOCATOR), CurrOfs+12, 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1507> Error decoding subfield MAIO\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1507)
		} 
#endif
		Len += Ret;
	
	/* FromBit=18 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc2_HSN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).HSN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+18), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSN___LOCATOR), CurrOfs+18, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1508> Error decoding subfield HSN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1508)
	} 
#endif
	Len += Ret;
	}
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc2_spare (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1509> Error decoding subfield spare\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1509)
		} 
#endif
		Len += Ret;
	
	/* FromBit=14 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc2_ARFCN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).ARFCN = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+14), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ARFCN___LOCATOR), CurrOfs+14, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1510> Error decoding subfield ARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1510)
	} 
#endif
	Len += Ret;
	}
	

	}
	return 24;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TChDesc3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TChDesc3* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).TSC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1511> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).H != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1512> Error encoding subfield H\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MAIO), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1513> Error encoding subfield MAIO\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).HSN), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1514> Error encoding subfield HSN\n");
			return -1;
		} 
#endif
	}
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+4, 0, 2);Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1515> Error encoding subfield spare\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).ARFCN), 10);
		Ret = 10;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1516> Error encoding subfield ARFCN\n");
			return -1;
		} 
#endif
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TChDesc3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TChDesc3* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).TSC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1517> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1517)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).H = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).H___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1518> Error decoding subfield H\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1518)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc3_MAIO (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).MAIO = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 6);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).MAIO___LOCATOR), CurrOfs+4, 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1519> Error decoding subfield MAIO\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1519)
		} 
#endif
		Len += Ret;
	
	/* FromBit=10 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc3_HSN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).HSN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+10), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSN___LOCATOR), CurrOfs+10, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1520> Error decoding subfield HSN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1520)
	} 
#endif
	Len += Ret;
	}
	
	/* FromBit=4 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc3_spare (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1521> Error decoding subfield spare\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1521)
		} 
#endif
		Len += Ret;
	
	/* FromBit=6 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_TChDesc3_ARFCN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).ARFCN = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+6), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ARFCN___LOCATOR), CurrOfs+6, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1522> Error decoding subfield ARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1522)
	} 
#endif
	Len += Ret;
	}
	

	}
	return 16;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ChannelMode (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ChannelMode* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Mode), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1523> Error encoding subfield Mode\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ChannelMode (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ChannelMode* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Mode = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Mode___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1524> Error decoding subfield Mode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1524)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ClassmarkEnquiryMask (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ClassmarkEnquiryMask* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ClassmarkChange != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1525> Error encoding subfield ClassmarkChange\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).UTRANClassmarkChange), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1526> Error encoding subfield UTRANClassmarkChange\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).CDMAClassmarkChange != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1527> Error encoding subfield CDMAClassmarkChange\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1528> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ClassmarkEnquiryMask (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ClassmarkEnquiryMask* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ClassmarkChange = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ClassmarkChange___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1529> Error decoding subfield ClassmarkChange\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1529)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).UTRANClassmarkChange = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).UTRANClassmarkChange___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1530> Error decoding subfield UTRANClassmarkChange\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1530)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).CDMAClassmarkChange = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CDMAClassmarkChange___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1531> Error decoding subfield CDMAClassmarkChange\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1531)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1532> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1532)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ChannelNeeded (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ChannelNeeded* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).Channel1), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1533> Error encoding subfield Channel1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Channel2), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1534> Error encoding subfield Channel2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ChannelNeeded (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ChannelNeeded* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=2 */
	(*Destin).Channel1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Channel1___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1535> Error decoding subfield Channel1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1535)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	(*Destin).Channel2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Channel2___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1536> Error decoding subfield Channel2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1536)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ChannelRequestDesc (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ChannelRequestDesc* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 40;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MTMO != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1537> Error encoding subfield MTMO\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if ( !DATA.MTMO ) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+1, 0, 39);Ret = 39;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1538> Error encoding subfield spare\n");
			return -1;
		} 
#endif
	}
#define ED_IS_ENCODING
#define DATA ((*Source))
	if ( DATA.MTMO ) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+1, 0, 3);Ret = 3;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1539> Error encoding subfield spare2\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).Priority), 2);
		Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1540> Error encoding subfield Priority\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).RLCMode != 0 ? 1 : 0), 1);Ret = 1;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1541> Error encoding subfield RLCMode\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).LLCFramType != 0 ? 1 : 0), 1);Ret = 1;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1542> Error encoding subfield LLCFramType\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).ReqBandwidth), 16);
		Ret = 16;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1543> Error encoding subfield ReqBandwidth\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).RLCOctetCount), 16);
		Ret = 16;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1544> Error encoding subfield RLCOctetCount\n");
			return -1;
		} 
#endif
	}

	}
	return Len;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ChannelRequestDesc (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ChannelRequestDesc* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).MTMO = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MTMO___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1545> Error decoding subfield MTMO\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1545)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if ( !DATA.MTMO ) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_spare (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 39;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1546> Error decoding subfield spare\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1546)
		} 
#endif
		Len += Ret;
	}
	
	/* FromBit=1 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if ( DATA.MTMO ) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_spare2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 3;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1547> Error decoding subfield spare2\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1547)
		} 
#endif
		Len += Ret;
	
	/* FromBit=4 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_Priority (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).Priority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Priority___LOCATOR), CurrOfs+4, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1548> Error decoding subfield Priority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1548)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_RLCMode (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).RLCMode = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).RLCMode___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1549> Error decoding subfield RLCMode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1549)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_LLCFramType (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).LLCFramType = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LLCFramType___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1550> Error decoding subfield LLCFramType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1550)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_ReqBandwidth (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).ReqBandwidth = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+8), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ReqBandwidth___LOCATOR), CurrOfs+8, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1551> Error decoding subfield ReqBandwidth\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1551)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_ChannelRequestDesc_RLCOctetCount (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).RLCOctetCount = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RLCOctetCount___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1552> Error decoding subfield RLCOctetCount\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1552)
	} 
#endif
	Len += Ret;
	}
	

	}
	return 40;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CipherModeSetting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CipherModeSetting* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).SC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1553> Error encoding subfield SC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).AlgIdent), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1554> Error encoding subfield AlgIdent\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CipherModeSetting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CipherModeSetting* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=3 */
	(*Destin).SC = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SC___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1555> Error decoding subfield SC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1555)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	(*Destin).AlgIdent = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).AlgIdent___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1556> Error decoding subfield AlgIdent\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1556)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CipherResponse (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CipherResponse* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).CR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1557> Error encoding subfield CR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1558> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CipherResponse (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CipherResponse* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=3 */
	(*Destin).CR = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CR___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1559> Error decoding subfield CR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1559)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1560> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1560)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CtrlChannelDesc (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CtrlChannelDesc* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MSCR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1561> Error encoding subfield MSCR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ATT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1562> Error encoding subfield ATT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).BsAgBlksRes), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1563> Error encoding subfield BsAgBlksRes\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).CCCHConf), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1564> Error encoding subfield CCCHConf\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1565> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).CBQ3), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1566> Error encoding subfield CBQ3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+11, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1567> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).BsPaMfrms), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1568> Error encoding subfield BsPaMfrms\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).T3212TimeOutValue), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1569> Error encoding subfield T3212TimeOutValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CtrlChannelDesc (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CtrlChannelDesc* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).MSCR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MSCR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1570> Error decoding subfield MSCR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1570)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ATT = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ATT___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1571> Error decoding subfield ATT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1571)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).BsAgBlksRes = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).BsAgBlksRes___LOCATOR), CurrOfs+2, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1572> Error decoding subfield BsAgBlksRes\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1572)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).CCCHConf = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CCCHConf___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1573> Error decoding subfield CCCHConf\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1573)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1574> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1574)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).CBQ3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+9), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CBQ3___LOCATOR), CurrOfs+9, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1575> Error decoding subfield CBQ3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1575)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1576> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1576)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).BsPaMfrms = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+13), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).BsPaMfrms___LOCATOR), CurrOfs+13, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1577> Error decoding subfield BsPaMfrms\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1577)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).T3212TimeOutValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T3212TimeOutValue___LOCATOR), CurrOfs+16, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1578> Error decoding subfield T3212TimeOutValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1578)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FreqChannelSeq (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FreqChannelSeq* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 72;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1579> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).LowestARFCN), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1580> Error encoding subfield LowestARFCN\n");
		return -1;
	} 
#endif
	Ret = ENCODE_c_IncSkipOfARFCN (Buffer, CurrOfs+72, (&((*Source).IncSkipOfARFCN)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1581> Error encoding subfield IncSkipOfARFCN\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FreqChannelSeq (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FreqChannelSeq* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1582> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1582)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).LowestARFCN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).LowestARFCN___LOCATOR), CurrOfs+1, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1583> Error decoding subfield LowestARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1583)
	} 
#endif
	Len += Ret;
	
	/* FromBit=72 */
	Ret = DECODE_c_IncSkipOfARFCN (Buffer, CurrOfs+72, (&((*Destin).IncSkipOfARFCN)), (Length - 72));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1584> Error decoding subfield IncSkipOfARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1584)
	} 
#endif
	Len += Ret;
	

	}
	return 72;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GrpChannelDesc (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GrpChannelDesc* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	Ret = ENCODE_c_TChType (Buffer, CurrOfs, (&((*Source).ChType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1585> Error encoding subfield ChType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TN), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1586> Error encoding subfield TN\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).TSC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1587> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).H != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1588> Error encoding subfield H\n");
		return -1;
	} 
#endif
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MAIO), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1589> Error encoding subfield MAIO\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).HSN), 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1590> Error encoding subfield HSN\n");
			return -1;
		} 
#endif
	}
#define ED_IS_ENCODING
#define DATA ((*Source))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_ENCODING
		EDIntToBits (Buffer, CurrOfs+12, 0, 2);Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1591> Error encoding subfield spare\n");
			return -1;
		} 
#endif
		EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).ARFCN), 10);
		Ret = 10;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1592> Error encoding subfield ARFCN\n");
			return -1;
		} 
#endif
	}
	Ret = ENCODE_c_GrpChannelMA (Buffer, CurrOfs+24, (&((*Source).MA)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1593> Error encoding subfield MA\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GrpChannelDesc (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GrpChannelDesc* ED_CONST Destin, ED_EXLONG Length))
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
	Ret = DECODE_c_TChType (Buffer, CurrOfs, (&((*Destin).ChType)), 5);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1594> Error decoding subfield ChType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1594)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TN___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1595> Error decoding subfield TN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1595)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).TSC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs+8, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1596> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1596)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).H = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).H___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1597> Error decoding subfield H\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1597)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_GrpChannelDesc_MAIO (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		(*Destin).MAIO = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 6);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&((*Destin).MAIO___LOCATOR), CurrOfs+12, 6);
		Ret = 6;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1598> Error decoding subfield MAIO\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1598)
		} 
#endif
		Len += Ret;
	
	/* FromBit=18 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_GrpChannelDesc_HSN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).HSN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+18), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSN___LOCATOR), CurrOfs+18, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1599> Error decoding subfield HSN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1599)
	} 
#endif
	Len += Ret;
	}
	
	/* FromBit=12 */
	/* isConditional=0 beginOfGroupCondition=1 */
#define ED_IS_DECODING
#define DATA ((*Destin))
	if (!DATA.H) {
#undef DATA
#undef ED_IS_DECODING
		ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_GrpChannelDesc_spare (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
		Ret = 2;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1600> Error decoding subfield spare\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1600)
		} 
#endif
		Len += Ret;
	
	/* FromBit=14 */
	ED_CHECK_OUT_OF_MEMORY_KEEP/*KOOMK09*/(/*SETP1*/SETPRESENT_c_GrpChannelDesc_ARFCN (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
	(*Destin).ARFCN = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+14), 10);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ARFCN___LOCATOR), CurrOfs+14, 10);
	Ret = 10;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1601> Error decoding subfield ARFCN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1601)
	} 
#endif
	Len += Ret;
	}
	
	/* FromBit=24 */
	Ret = DECODE_c_GrpChannelMA (Buffer, CurrOfs+24, (&((*Destin).MA)), (Length - 24));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1602> Error decoding subfield MA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1602)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GPRSResumption (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GPRSResumption* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).ACK != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1603> Error encoding subfield ACK\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1604> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GPRSResumption (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GPRSResumption* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=3 */
	(*Destin).ACK = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ACK___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1605> Error decoding subfield ACK\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1605)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1606> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1606)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GroupChannelDescription2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GroupChannelDescription2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 88;
	Ret = ENCODE_c_TChType (Buffer, CurrOfs, (&((*Source).ChType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1607> Error encoding subfield ChType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TN), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1608> Error encoding subfield TN\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).TSC), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1609> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+11, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1610> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MAIO), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1611> Error encoding subfield MAIO\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).HSN), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1612> Error encoding subfield HSN\n");
		return -1;
	} 
#endif
	Ret = ENCODE_c_CellChannel (Buffer, CurrOfs+88, (&((*Source).FrequencyList)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1613> Error encoding subfield FrequencyList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GroupChannelDescription2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GroupChannelDescription2* ED_CONST Destin, ED_EXLONG Length))
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
	Ret = DECODE_c_TChType (Buffer, CurrOfs, (&((*Destin).ChType)), 5);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1614> Error decoding subfield ChType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1614)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TN___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1615> Error decoding subfield TN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1615)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).TSC = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs+8, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1616> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1616)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1617> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1617)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MAIO = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MAIO___LOCATOR), CurrOfs+12, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1618> Error decoding subfield MAIO\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1618)
	} 
#endif
	Len += Ret;
	
	/* FromBit=18 */
	(*Destin).HSN = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+18), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).HSN___LOCATOR), CurrOfs+18, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1619> Error decoding subfield HSN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1619)
	} 
#endif
	Len += Ret;
	
	/* FromBit=88 */
	Ret = DECODE_c_CellChannel (Buffer, CurrOfs+88, (&((*Destin).FrequencyList)), (Length - 88));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1620> Error decoding subfield FrequencyList\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1620)
	} 
#endif
	Len += Ret;
	

	}
	return 88;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GPRSMeasurementResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GPRSMeasurementResult* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).C_VALUE), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1621> Error encoding subfield C_VALUE\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).RXQUAL), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1622> Error encoding subfield RXQUAL\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+9, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1623> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).SIGN_VAR), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1624> Error encoding subfield SIGN_VAR\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GPRSMeasurementResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GPRSMeasurementResult* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).C_VALUE = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).C_VALUE___LOCATOR), CurrOfs, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1625> Error decoding subfield C_VALUE\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1625)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).RXQUAL = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+6), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RXQUAL___LOCATOR), CurrOfs+6, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1626> Error decoding subfield RXQUAL\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1626)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1627> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1627)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).SIGN_VAR = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+10), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SIGN_VAR___LOCATOR), CurrOfs+10, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1628> Error decoding subfield SIGN_VAR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1628)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileTimeDiff (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileTimeDiff* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MobileTimeDiff), 21);
	Ret = 21;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1629> Error encoding subfield MobileTimeDiff\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+21, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1630> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileTimeDiff (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileTimeDiff* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).MobileTimeDiff = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 21);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MobileTimeDiff___LOCATOR), CurrOfs, 21);
	Ret = 21;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1631> Error decoding subfield MobileTimeDiff\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1631)
	} 
#endif
	Len += Ret;
	
	/* FromBit=21 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1632> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1632)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileTimeDiffHyperframe (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileTimeDiffHyperframe* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 40;
	EDCopyBits (Buffer, CurrOfs, ((*Source).MobileTimeDifferenceOnHyperframeLevelValue), 0, 33);
	Ret = 33;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1633> Error encoding subfield MobileTimeDifferenceOnHyperframeLevelValue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+33, 0, 7);Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1634> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileTimeDiffHyperframe (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileTimeDiffHyperframe* ED_CONST Destin, ED_EXLONG Length))
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
	EDCopyBits ((*Destin).MobileTimeDifferenceOnHyperframeLevelValue, 0, Buffer, CurrOfs, 33);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&((*Destin).MobileTimeDifferenceOnHyperframeLevelValue___LOCATOR), CurrOfs, 33);
	Ret = 33;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1635> Error decoding subfield MobileTimeDifferenceOnHyperframeLevelValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1635)
	} 
#endif
	Len += Ret;
	
	/* FromBit=33 */
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1636> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1636)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NCMode (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NCMode* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1637> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).NCMode), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1638> Error encoding subfield NCMode\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NCMode (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NCMode* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1639> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1639)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).NCMode = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NCMode___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1640> Error decoding subfield NCMode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1640)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DedicatedModeOrTBF (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DedicatedModeOrTBF* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).TD != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1641> Error encoding subfield TD\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Downlink != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1642> Error encoding subfield Downlink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TMA != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1643> Error encoding subfield TMA\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1644> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).DedicatedMode != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1645> Error encoding subfield DedicatedMode\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DedicatedModeOrTBF (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DedicatedModeOrTBF* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).TD = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TD___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1646> Error decoding subfield TD\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1646)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).Downlink = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Downlink___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1647> Error decoding subfield Downlink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1647)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TMA = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TMA___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1648> Error decoding subfield TMA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1648)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1649> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1649)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	(*Destin).DedicatedMode = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DedicatedMode___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1650> Error decoding subfield DedicatedMode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1650)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DedicatedModeOrTBF4b (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DedicatedModeOrTBF4b* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TD != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1651> Error encoding subfield TD\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).Downlink != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1652> Error encoding subfield Downlink\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TMA != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1653> Error encoding subfield TMA\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DedicatedModeOrTBF4b (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DedicatedModeOrTBF4b* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=3 */
	(*Destin).TD = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TD___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1654> Error decoding subfield TD\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1654)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).Downlink = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Downlink___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1655> Error decoding subfield Downlink\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1655)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TMA = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TMA___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1656> Error decoding subfield TMA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1656)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PageMode (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PageMode* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).PM), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1657> Error encoding subfield PM\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1658> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PageMode (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PageMode* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=2 */
	(*Destin).PM = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PM___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1659> Error decoding subfield PM\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1659)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1660> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1660)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PowerCommand (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PowerCommand* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, CurrOfs, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1661> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).PowerLevel), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1662> Error encoding subfield PowerLevel\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PowerCommand (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PowerCommand* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1663> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1663)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).PowerLevel = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PowerLevel___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1664> Error decoding subfield PowerLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1664)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PowerCommandAndAccessType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PowerCommandAndAccessType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ATC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1665> Error encoding subfield ATC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1666> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).FPC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1667> Error encoding subfield FPC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).PowerLevel), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1668> Error encoding subfield PowerLevel\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PowerCommandAndAccessType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PowerCommandAndAccessType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ATC = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ATC___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1669> Error decoding subfield ATC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1669)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1670> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1670)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).FPC = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FPC___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1671> Error decoding subfield FPC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1671)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).PowerLevel = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PowerLevel___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1672> Error decoding subfield PowerLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1672)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RACHCtrlParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RACHCtrlParam* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).MaxRetrans), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1673> Error encoding subfield MaxRetrans\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).Tx), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1674> Error encoding subfield Tx\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).CellBarrAccess != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1675> Error encoding subfield CellBarrAccess\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).RE != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1676> Error encoding subfield RE\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).AC_C15 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1677> Error encoding subfield AC_C15\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).AC_C14 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1678> Error encoding subfield AC_C14\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).AC_C13 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1679> Error encoding subfield AC_C13\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).AC_C12 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1680> Error encoding subfield AC_C12\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).AC_C11 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1681> Error encoding subfield AC_C11\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).EC_C10 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1682> Error encoding subfield EC_C10\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).AC_C09 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1683> Error encoding subfield AC_C09\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).AC_C08 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1684> Error encoding subfield AC_C08\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).AC_C07 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1685> Error encoding subfield AC_C07\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+17), (int)((*Source).AC_C06 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1686> Error encoding subfield AC_C06\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).AC_C05 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1687> Error encoding subfield AC_C05\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).AC_C04 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1688> Error encoding subfield AC_C04\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).AC_C03 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1689> Error encoding subfield AC_C03\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+21), (int)((*Source).AC_C02 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1690> Error encoding subfield AC_C02\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).AC_C01 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1691> Error encoding subfield AC_C01\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+23), (int)((*Source).AC_C00 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1692> Error encoding subfield AC_C00\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RACHCtrlParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RACHCtrlParam* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).MaxRetrans = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MaxRetrans___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1693> Error decoding subfield MaxRetrans\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1693)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).Tx = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Tx___LOCATOR), CurrOfs+2, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1694> Error decoding subfield Tx\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1694)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).CellBarrAccess = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CellBarrAccess___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1695> Error decoding subfield CellBarrAccess\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1695)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).RE = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).RE___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1696> Error decoding subfield RE\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1696)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).AC_C15 = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C15___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1697> Error decoding subfield AC_C15\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1697)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).AC_C14 = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C14___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1698> Error decoding subfield AC_C14\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1698)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).AC_C13 = (EDBitsToInt (Buffer, CurrOfs+10, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C13___LOCATOR), CurrOfs+10, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1699> Error decoding subfield AC_C13\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1699)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).AC_C12 = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C12___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1700> Error decoding subfield AC_C12\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1700)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).AC_C11 = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C11___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1701> Error decoding subfield AC_C11\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1701)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).EC_C10 = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EC_C10___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1702> Error decoding subfield EC_C10\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1702)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).AC_C09 = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C09___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1703> Error decoding subfield AC_C09\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1703)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).AC_C08 = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C08___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1704> Error decoding subfield AC_C08\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1704)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).AC_C07 = (EDBitsToInt (Buffer, CurrOfs+16, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C07___LOCATOR), CurrOfs+16, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1705> Error decoding subfield AC_C07\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1705)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	(*Destin).AC_C06 = (EDBitsToInt (Buffer, CurrOfs+17, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C06___LOCATOR), CurrOfs+17, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1706> Error decoding subfield AC_C06\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1706)
	} 
#endif
	Len += Ret;
	
	/* FromBit=18 */
	(*Destin).AC_C05 = (EDBitsToInt (Buffer, CurrOfs+18, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C05___LOCATOR), CurrOfs+18, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1707> Error decoding subfield AC_C05\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1707)
	} 
#endif
	Len += Ret;
	
	/* FromBit=19 */
	(*Destin).AC_C04 = (EDBitsToInt (Buffer, CurrOfs+19, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C04___LOCATOR), CurrOfs+19, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1708> Error decoding subfield AC_C04\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1708)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).AC_C03 = (EDBitsToInt (Buffer, CurrOfs+20, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C03___LOCATOR), CurrOfs+20, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1709> Error decoding subfield AC_C03\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1709)
	} 
#endif
	Len += Ret;
	
	/* FromBit=21 */
	(*Destin).AC_C02 = (EDBitsToInt (Buffer, CurrOfs+21, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C02___LOCATOR), CurrOfs+21, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1710> Error decoding subfield AC_C02\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1710)
	} 
#endif
	Len += Ret;
	
	/* FromBit=22 */
	(*Destin).AC_C01 = (EDBitsToInt (Buffer, CurrOfs+22, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C01___LOCATOR), CurrOfs+22, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1711> Error decoding subfield AC_C01\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1711)
	} 
#endif
	Len += Ret;
	
	/* FromBit=23 */
	(*Destin).AC_C00 = (EDBitsToInt (Buffer, CurrOfs+23, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AC_C00___LOCATOR), CurrOfs+23, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1712> Error decoding subfield AC_C00\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1712)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RequestReference (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RequestReference* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 24;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).RA), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1713> Error encoding subfield RA\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).T1), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1714> Error encoding subfield T1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).T3), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1715> Error encoding subfield T3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).T2), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1716> Error encoding subfield T2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RequestReference (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RequestReference* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).RA = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RA___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1717> Error decoding subfield RA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1717)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).T1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T1___LOCATOR), CurrOfs+8, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1718> Error decoding subfield T1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1718)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).T3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+13), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T3___LOCATOR), CurrOfs+13, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1719> Error decoding subfield T3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1719)
	} 
#endif
	Len += Ret;
	
	/* FromBit=19 */
	(*Destin).T2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+19), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T2___LOCATOR), CurrOfs+19, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1720> Error decoding subfield T2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1720)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EstablishmentCauseRandomReference (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EstablishmentCauseRandomReference* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).EstablishmentCause), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1721> Error encoding subfield EstablishmentCause\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).RandomReference), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1722> Error encoding subfield RandomReference\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EstablishmentCauseRandomReference (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EstablishmentCauseRandomReference* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).EstablishmentCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).EstablishmentCause___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1723> Error decoding subfield EstablishmentCause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1723)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).RandomReference = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).RandomReference___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1724> Error decoding subfield RandomReference\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1724)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRCause* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1725> Error encoding subfield Cause\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRCause* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1726> Error decoding subfield Cause\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1726)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_StartingTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_StartingTime* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).T1), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1727> Error encoding subfield T1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).T3), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1728> Error encoding subfield T3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).T2), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1729> Error encoding subfield T2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_StartingTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_StartingTime* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).T1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T1___LOCATOR), CurrOfs, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1730> Error decoding subfield T1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1730)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).T3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T3___LOCATOR), CurrOfs+5, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1731> Error decoding subfield T3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1731)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).T2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+11), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).T2___LOCATOR), CurrOfs+11, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1732> Error decoding subfield T2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1732)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SyncInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SyncInd* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).NCI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1733> Error encoding subfield NCI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ROT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1734> Error encoding subfield ROT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).SI), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1735> Error encoding subfield SI\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SyncInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SyncInd* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).NCI = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).NCI___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1736> Error decoding subfield NCI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1736)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ROT = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ROT___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1737> Error decoding subfield ROT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1737)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).SI = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SI___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1738> Error decoding subfield SI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1738)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TimingAdvance (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TimingAdvance* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1739> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).value), 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1740> Error encoding subfield value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TimingAdvance (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TimingAdvance* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1741> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1741)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).value = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 6);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).value___LOCATOR), CurrOfs+2, 6);
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1742> Error decoding subfield value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1742)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCSTargeModeIndication (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCSTargeModeIndication* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).TargetMode), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1743> Error encoding subfield TargetMode\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).GroupCipherKeyNumber), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1744> Error encoding subfield GroupCipherKeyNumber\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+6, 0, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1745> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCSTargeModeIndication (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCSTargeModeIndication* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).TargetMode = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TargetMode___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1746> Error decoding subfield TargetMode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1746)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).GroupCipherKeyNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).GroupCipherKeyNumber___LOCATOR), CurrOfs+2, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1747> Error decoding subfield GroupCipherKeyNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1747)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1748> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1748)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtMeasurementResults (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtMeasurementResults* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 2;
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).DTXUsed != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1749> Error encoding subfield DTXUsed\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).SCUsed != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1750> Error encoding subfield SCUsed\n");
		return -1;
	} 
#endif
	Ret = ENCODE_c_TRXLEVCarriers (Buffer, CurrOfs+2, (&((*Source).RXLEVCarriers)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1751> Error encoding subfield RXLEVCarriers\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtMeasurementResults (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtMeasurementResults* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=1 */
	(*Destin).DTXUsed = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DTXUsed___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1752> Error decoding subfield DTXUsed\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1752)
	} 
#endif
	Len += Ret;
	
	/* FromBit=0 */
	(*Destin).SCUsed = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SCUsed___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1753> Error decoding subfield SCUsed\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1753)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	Ret = DECODE_c_TRXLEVCarriers (Buffer, CurrOfs+2, (&((*Destin).RXLEVCarriers)), (Length - 2));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1754> Error decoding subfield RXLEVCarriers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1754)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_APDUFlags (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_APDUFlags* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1755> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1756> Error encoding subfield CR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).FirstSet != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1757> Error encoding subfield FirstSet\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).LastSet != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1758> Error encoding subfield LastSet\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_APDUFlags (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_APDUFlags* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1759> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1759)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).CR = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CR___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1760> Error decoding subfield CR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1760)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).FirstSet = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FirstSet___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1761> Error decoding subfield FirstSet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1761)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).LastSet = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).LastSet___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1762> Error decoding subfield LastSet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1762)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ServiceSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ServiceSupport* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1763> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).MBMSMulticast != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1764> Error encoding subfield MBMSMulticast\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).MBMSBroadcast != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1765> Error encoding subfield MBMSBroadcast\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ServiceSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ServiceSupport* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1766> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1766)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).MBMSMulticast = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MBMSMulticast___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1767> Error decoding subfield MBMSMulticast\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1767)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).MBMSBroadcast = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).MBMSBroadcast___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1768> Error decoding subfield MBMSBroadcast\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1768)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DedicatedServiceInformation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DedicatedServiceInformation* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1769> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).SIS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1770> Error encoding subfield SIS\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DedicatedServiceInformation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DedicatedServiceInformation* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1771> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1771)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).SIS = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SIS___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1772> Error decoding subfield SIS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1772)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ReducedGroupCallReference (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ReducedGroupCallReference* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 32;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Reference), 27);
	Ret = 27;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1773> Error encoding subfield Reference\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+27), (int)((*Source).SF != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1774> Error encoding subfield SF\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+28, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1775> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ReducedGroupCallReference (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ReducedGroupCallReference* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Reference = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 27);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Reference___LOCATOR), CurrOfs, 27);
	Ret = 27;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1776> Error decoding subfield Reference\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1776)
	} 
#endif
	Len += Ret;
	
	/* FromBit=27 */
	(*Destin).SF = (EDBitsToInt (Buffer, CurrOfs+27, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SF___LOCATOR), CurrOfs+27, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1777> Error decoding subfield SF\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1777)
	} 
#endif
	Len += Ret;
	
	/* FromBit=28 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1778> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1778)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TalkerPriorityStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TalkerPriorityStatus* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ES != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1779> Error encoding subfield ES\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1780> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).UAI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1781> Error encoding subfield UAI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).Priority), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1782> Error encoding subfield Priority\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TalkerPriorityStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TalkerPriorityStatus* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ES = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ES___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1783> Error decoding subfield ES\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1783)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1784> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1784)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).UAI = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UAI___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1785> Error decoding subfield UAI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1785)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).Priority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).Priority___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1786> Error decoding subfield Priority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1786)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TalkerIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TalkerIdentity* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1787> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).FillerBits), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1788> Error encoding subfield FillerBits\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).TalkerIdentityfield.value, 0, (*Source).TalkerIdentityfield.usedBits);
	Ret = (*Source).TalkerIdentityfield.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1789> Error encoding subfield TalkerIdentityfield\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TalkerIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TalkerIdentity* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1790> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1790)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).FillerBits = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).FillerBits___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1791> Error decoding subfield FillerBits\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1791)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).TalkerIdentityfield___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_TalkerIdentity_TalkerIdentityfield (&((*Destin).TalkerIdentityfield), (Length - 8));
	
		if ((*Destin).TalkerIdentityfield.value) {
			EDCopyBits ((*Destin).TalkerIdentityfield.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).TalkerIdentityfield.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).TalkerIdentityfield.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1792> Error decoding subfield TalkerIdentityfield\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1792)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCSAMRConfiguration (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCSAMRConfiguration* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).AMRConfiguration), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1793> Error encoding subfield AMRConfiguration\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1794> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCSAMRConfiguration (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCSAMRConfiguration* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).AMRConfiguration = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).AMRConfiguration___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1795> Error decoding subfield AMRConfiguration\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1795)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1796> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1796)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DataIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DataIdentity* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).DistributeToTalkersAndListeners != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1797> Error encoding subfield DistributeToTalkersAndListeners\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).DistributeToDispatchers != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1798> Error encoding subfield DistributeToDispatchers\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).DistributeToNetworkApplication != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1799> Error encoding subfield DistributeToNetworkApplication\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).DI), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1800> Error encoding subfield DI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).AI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1801> Error encoding subfield AI\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DataIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DataIdentity* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).DistributeToTalkersAndListeners = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DistributeToTalkersAndListeners___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1802> Error decoding subfield DistributeToTalkersAndListeners\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1802)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).DistributeToDispatchers = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DistributeToDispatchers___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1803> Error decoding subfield DistributeToDispatchers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1803)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).DistributeToNetworkApplication = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).DistributeToNetworkApplication___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1804> Error decoding subfield DistributeToNetworkApplication\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1804)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).DI = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).DI___LOCATOR), CurrOfs+3, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1805> Error decoding subfield DI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1805)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).AI = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).AI___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1806> Error decoding subfield AI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1806)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FeatureIndicator (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FeatureIndicator* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).PEO_BCCH_CHANGE_MARK), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1807> Error encoding subfield PEO_BCCH_CHANGE_MARK\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CS_IR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1808> Error encoding subfield CS_IR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).PS_IR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1809> Error encoding subfield PS_IR\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FeatureIndicator (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FeatureIndicator* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).PEO_BCCH_CHANGE_MARK = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PEO_BCCH_CHANGE_MARK___LOCATOR), CurrOfs, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1810> Error decoding subfield PEO_BCCH_CHANGE_MARK\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1810)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).CS_IR = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CS_IR___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1811> Error decoding subfield CS_IR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1811)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).PS_IR = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).PS_IR___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1812> Error decoding subfield PS_IR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1812)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtendedTSCSet (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtendedTSCSet* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).SecondaryPSDomainTSCValue), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1813> Error encoding subfield SecondaryPSDomainTSCValue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).SecondaryPSDomainTSCSet), 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1814> Error encoding subfield SecondaryPSDomainTSCSet\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).PrimaryPSDomainTSCSet), 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1815> Error encoding subfield PrimaryPSDomainTSCSet\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).SecondPSDomainTSCAssigned), 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1816> Error encoding subfield SecondPSDomainTSCAssigned\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).CSDomainTSCSet), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1817> Error encoding subfield CSDomainTSCSet\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtendedTSCSet (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtendedTSCSet* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).SecondaryPSDomainTSCValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SecondaryPSDomainTSCValue___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1818> Error decoding subfield SecondaryPSDomainTSCValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1818)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).SecondaryPSDomainTSCSet = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 1);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SecondaryPSDomainTSCSet___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1819> Error decoding subfield SecondaryPSDomainTSCSet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1819)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).PrimaryPSDomainTSCSet = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+4), 1);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).PrimaryPSDomainTSCSet___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1820> Error decoding subfield PrimaryPSDomainTSCSet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1820)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).SecondPSDomainTSCAssigned = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+5), 1);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).SecondPSDomainTSCAssigned___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1821> Error decoding subfield SecondPSDomainTSCAssigned\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1821)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).CSDomainTSCSet = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+6), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CSDomainTSCSet___LOCATOR), CurrOfs+6, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1822> Error decoding subfield CSDomainTSCSet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1822)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LocationUpdType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LocationUpdType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).FOR != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1823> Error encoding subfield FOR\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1824> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).LUT), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1825> Error encoding subfield LUT\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LocationUpdType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LocationUpdType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).FOR = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).FOR___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1826> Error decoding subfield FOR\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1826)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1827> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1827)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).LUT = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).LUT___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1828> Error decoding subfield LUT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1828)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UpdateResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UpdateResult* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1829> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).value), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1830> Error encoding subfield value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UpdateResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UpdateResult* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1831> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1831)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).value = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+1), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).value___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1832> Error decoding subfield value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1832)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRLocationAreaId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRLocationAreaId* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1833> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1834> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1835> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1836> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1837> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1838> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1839> Error encoding subfield LAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRLocationAreaId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRLocationAreaId* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1840> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1840)
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
		ED_SIGNAL_ERROR ("<ERRID:1841> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1841)
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
		ED_SIGNAL_ERROR ("<ERRID:1842> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1842)
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
		ED_SIGNAL_ERROR ("<ERRID:1843> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1843)
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
		ED_SIGNAL_ERROR ("<ERRID:1844> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1844)
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
		ED_SIGNAL_ERROR ("<ERRID:1845> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1845)
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
		ED_SIGNAL_ERROR ("<ERRID:1846> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1846)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRAdditionalUpdateParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRAdditionalUpdateParameters* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1847> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CSMO != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1848> Error encoding subfield CSMO\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).CSMT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1849> Error encoding subfield CSMT\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRAdditionalUpdateParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRAdditionalUpdateParameters* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1850> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1850)
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
		ED_SIGNAL_ERROR ("<ERRID:1851> Error decoding subfield CSMO\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1851)
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
		ED_SIGNAL_ERROR ("<ERRID:1852> Error decoding subfield CSMT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1852)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRRoutingAreaIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRRoutingAreaIdentity* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1853> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1854> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1855> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1856> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1857> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1858> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1859> Error encoding subfield LAC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).RAC), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1860> Error encoding subfield RAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRRoutingAreaIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRRoutingAreaIdentity* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1861> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1861)
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
		ED_SIGNAL_ERROR ("<ERRID:1862> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1862)
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
		ED_SIGNAL_ERROR ("<ERRID:1863> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1863)
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
		ED_SIGNAL_ERROR ("<ERRID:1864> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1864)
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
		ED_SIGNAL_ERROR ("<ERRID:1865> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1865)
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
		ED_SIGNAL_ERROR ("<ERRID:1866> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1866)
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
		ED_SIGNAL_ERROR ("<ERRID:1867> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1867)
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
		ED_SIGNAL_ERROR ("<ERRID:1868> Error decoding subfield RAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1868)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRMobileStationClassmark2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRMobileStationClassmark2* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1869> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).RevisionLevel), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1870> Error encoding subfield RevisionLevel\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EsInd != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1871> Error encoding subfield EsInd\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).A5_1 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1872> Error encoding subfield A5_1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).RFPowerCapability), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1873> Error encoding subfield RFPowerCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1874> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).PSCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1875> Error encoding subfield PSCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).SSScreenIndicator), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1876> Error encoding subfield SSScreenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).SMCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1877> Error encoding subfield SMCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).VBS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1878> Error encoding subfield VBS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).VGCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1879> Error encoding subfield VGCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).FC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1880> Error encoding subfield FC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).CM3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1881> Error encoding subfield CM3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+17, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1882> Error encoding subfield spare3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).LCSVA_CAP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1883> Error encoding subfield LCSVA_CAP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).UCS2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1884> Error encoding subfield UCS2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).SoLSA != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1885> Error encoding subfield SoLSA\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+21), (int)((*Source).CMSP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1886> Error encoding subfield CMSP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).A5_3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1887> Error encoding subfield A5_3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+23), (int)((*Source).A5_2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1888> Error encoding subfield A5_2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRMobileStationClassmark2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRMobileStationClassmark2* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1889> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1889)
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
		ED_SIGNAL_ERROR ("<ERRID:1890> Error decoding subfield RevisionLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1890)
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
		ED_SIGNAL_ERROR ("<ERRID:1891> Error decoding subfield EsInd\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1891)
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
		ED_SIGNAL_ERROR ("<ERRID:1892> Error decoding subfield A5_1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1892)
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
		ED_SIGNAL_ERROR ("<ERRID:1893> Error decoding subfield RFPowerCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1893)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1894> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1894)
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
		ED_SIGNAL_ERROR ("<ERRID:1895> Error decoding subfield PSCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1895)
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
		ED_SIGNAL_ERROR ("<ERRID:1896> Error decoding subfield SSScreenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1896)
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
		ED_SIGNAL_ERROR ("<ERRID:1897> Error decoding subfield SMCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1897)
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
		ED_SIGNAL_ERROR ("<ERRID:1898> Error decoding subfield VBS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1898)
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
		ED_SIGNAL_ERROR ("<ERRID:1899> Error decoding subfield VGCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1899)
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
		ED_SIGNAL_ERROR ("<ERRID:1900> Error decoding subfield FC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1900)
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
		ED_SIGNAL_ERROR ("<ERRID:1901> Error decoding subfield CM3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1901)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1902> Error decoding subfield spare3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1902)
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
		ED_SIGNAL_ERROR ("<ERRID:1903> Error decoding subfield LCSVA_CAP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1903)
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
		ED_SIGNAL_ERROR ("<ERRID:1904> Error decoding subfield UCS2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1904)
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
		ED_SIGNAL_ERROR ("<ERRID:1905> Error decoding subfield SoLSA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1905)
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
		ED_SIGNAL_ERROR ("<ERRID:1906> Error decoding subfield CMSP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1906)
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
		ED_SIGNAL_ERROR ("<ERRID:1907> Error decoding subfield A5_3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1907)
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
		ED_SIGNAL_ERROR ("<ERRID:1908> Error decoding subfield A5_2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1908)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FDD_CELL_INFORMATION_ITEM (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FDD_CELL_INFORMATION_ITEM* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 10;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Diversity != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1909> Error encoding subfield Diversity\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ScramblingCode), 9);
	Ret = 9;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1910> Error encoding subfield ScramblingCode\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FDD_CELL_INFORMATION_ITEM (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FDD_CELL_INFORMATION_ITEM* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Diversity = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Diversity___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1911> Error decoding subfield Diversity\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1911)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ScramblingCode = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+1), 9);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ScramblingCode___LOCATOR), CurrOfs+1, 9);
	Ret = 9;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1912> Error decoding subfield ScramblingCode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1912)
	} 
#endif
	Len += Ret;
	

	}
	return 10;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TDD_CELL_INFORMATION_ITEM (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TDD_CELL_INFORMATION_ITEM* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 9;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Diversity != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1913> Error encoding subfield Diversity\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).SyncCaseTSTD != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1914> Error encoding subfield SyncCaseTSTD\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).CellParameter), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1915> Error encoding subfield CellParameter\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TDD_CELL_INFORMATION_ITEM (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TDD_CELL_INFORMATION_ITEM* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Diversity = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Diversity___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1916> Error decoding subfield Diversity\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1916)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).SyncCaseTSTD = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SyncCaseTSTD___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1917> Error decoding subfield SyncCaseTSTD\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1917)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).CellParameter = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+2), 7);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).CellParameter___LOCATOR), CurrOfs+2, 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1918> Error decoding subfield CellParameter\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1918)
	} 
#endif
	Len += Ret;
	

	}
	return 9;
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IncSkipOfARFCN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IncSkipOfARFCN* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		EDIntToBits (Buffer, (CurrOfs), (int)(Source->data[i]), 4);
		length = 4;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1919> Error encoding sequence IncSkipOfARFCN\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IncSkipOfARFCN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IncSkipOfARFCN* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<16) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_IncSkipOfARFCN (Destin, i+1)
, != ED_NO_ERRORS)


		Destin->data[i] = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(Destin->data___LOCATOR[i]), CurrOfs, 4);
		ret = 4;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1920> Error decoding sequence IncSkipOfARFCN\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1920)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GrpChannelMA (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GrpChannelMA* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		EDIntToBits (Buffer, (CurrOfs), (int)(Source->data[i] != 0 ? 1 : 0), 1);length = 1;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1921> Error encoding sequence GrpChannelMA\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GrpChannelMA (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GrpChannelMA* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<72) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_GrpChannelMA (Destin, i+1)
, != ED_NO_ERRORS)


		Destin->data[i] = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
		/* LOCATOR SETTINGS LOCBOOL */;
		ED_LOCATOR_SET (&(Destin->data___LOCATOR[i]), CurrOfs, 1);
		ret = 1;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1922> Error decoding sequence GrpChannelMA\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1922)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRXLEVCarriers (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRXLEVCarriers* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		EDIntToBits (Buffer, (CurrOfs), (int)(Source->data[i]), 6);
		length = 6;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1923> Error encoding sequence TRXLEVCarriers\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRXLEVCarriers (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRXLEVCarriers* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<21) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_TRXLEVCarriers (Destin, i+1)
, != ED_NO_ERRORS)


		Destin->data[i] = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 6);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(Destin->data___LOCATOR[i]), CurrOfs, 6);
		ret = 6;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1924> Error decoding sequence TRXLEVCarriers\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1924)
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BitmapTypeReporting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BitmapTypeReporting* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, j;
		j = 0;
		for (i=0; i<Source->BitmapLength; i++) {
			if (j < Source->BitmapReporting.items && i == VAR_c_BitmapTypeReporting_BitmapReporting_data (Source->BitmapReporting.data [j]).Index) {
				PUSH_INT (1, 1);
				PUSH_INT (VAR_c_BitmapTypeReporting_BitmapReporting_data (Source->BitmapReporting.data [j]).REPORTING_QUANTITY, 6);
				j++;
			}
			else {
				PUSH_INT (0, 1);
			}
		}

		return (CurrOfs - BitOffset);
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BitmapTypeReporting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BitmapTypeReporting* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int Ret, Discriminator;
  	long LastBit;

  	LastBit = BitOffset + Length;
  	Destin->BitmapLength = 0;

		while (CurrOfs < LastBit) {

			Discriminator = SHIFT_INT (1);

			/* Get 0 or 1 */
			if (Discriminator) {
				if (LastBit - CurrOfs >= 6) {
					Ret = ADDITEMS_c_BitmapTypeReporting_BitmapReporting (&(Destin->BitmapReporting), 1);
					if (Ret != ED_NO_ERRORS) return Ret; /* Too many items. Enlarge 'BitmapReporting' */
					VAR_c_BitmapTypeReporting_BitmapReporting_data (Destin->BitmapReporting.data [Destin->BitmapReporting.items - 1]).REPORTING_QUANTITY = (unsigned char)SHIFT_INT (6);
					VAR_c_BitmapTypeReporting_BitmapReporting_data (Destin->BitmapReporting.data [Destin->BitmapReporting.items - 1]).Index = Destin->BitmapLength;
				}
				/* No more bits */
				else {
					CurrOfs--;
					break;
				}
			}
			Destin->BitmapLength++;
		}

		return (CurrOfs - BitOffset);
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LHBit (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LHBit* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ExpectedLBit = (0x2B >> (7-(CURPOS & 7))) & 1;
		PUSH_INT (Source->LHValue ? !ExpectedLBit : ExpectedLBit, 1);
		return 1;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LHBit (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LHBit* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		unsigned ExpectedLBit = (0x2B >> (7-(CURPOS & 7))) & 1;
		Destin->LHValue = (unsigned char)(SHIFT_INT (1) == (int)ExpectedLBit ? 0 : 1);
		return 1;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ChannelRequest (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ChannelRequest* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		PUSH_INT (Source->MessageContent, 8);
		return 8;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ChannelRequest (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ChannelRequest* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	Destin->MessageContent = (unsigned char)SHIFT_INT (8);
		if ((Destin->MessageContent & 0xE0) == 0xA0) {Destin->Description =  0; Destin->RandomReference = Destin->MessageContent & 0x1F;} /* Case 101xxxxx */
		else if ((Destin->MessageContent & 0xE0) == 0xC0) {Destin->Description =  1; Destin->RandomReference = Destin->MessageContent & 0x1F;} /* Case 110xxxxx */
		else if ((Destin->MessageContent & 0xFC) == 0x68) {Destin->Description =  2; Destin->RandomReference = Destin->MessageContent & 0x03;} /* Case 011010xx */
		else if ((Destin->MessageContent & 0xFC) == 0x6C) {Destin->Description =  3; Destin->RandomReference = Destin->MessageContent & 0x03;} /* Case 011011xx */
		else if ((Destin->MessageContent & 0xE0) == 0x80) {Destin->Description =  4; Destin->RandomReference = Destin->MessageContent & 0x1F;} /* Case 100xxxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x10) {Destin->Description =  5; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0001xxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x20) {Destin->Description =  6; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0010xxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x30) {Destin->Description =  7; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0011xxxx */
		else if ((Destin->MessageContent & 0xE0) == 0xE0) {Destin->Description =  8; Destin->RandomReference = Destin->MessageContent & 0x1F;} /* Case 111xxxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x40) {Destin->Description =  9; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0100xxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x50) {Destin->Description = 10; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0101xxxx */
		else if ((Destin->MessageContent & 0xE0) == 0x00) {Destin->Description = 11; Destin->RandomReference = Destin->MessageContent & 0x1F;} /* Case 000xxxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x00) {Destin->Description = 12; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0000xxxx */
		else if ((Destin->MessageContent & 0xF0) == 0x10) {Destin->Description = 13; Destin->RandomReference = Destin->MessageContent & 0x0F;} /* Case 0001xxxx */
		else if ((Destin->MessageContent & 0xFC) == 0x78) {Destin->Description = 14; Destin->RandomReference = Destin->MessageContent & 0x03;} /* Case 011110xx */
		else if ((Destin->MessageContent & 0xFA) == 0x78) {Destin->Description = 14; Destin->RandomReference = ((Destin->MessageContent & 0x04) >> 1)|(Destin->MessageContent & 0x01);} /* Case 01111x0x */
		else if ((Destin->MessageContent & 0xF9) == 0x78) {Destin->Description = 14; Destin->RandomReference = (Destin->MessageContent & 0x07)>>1;} /* Case 01111xx0 */
		else if ((Destin->MessageContent & 0xF8) == 0x70) {Destin->Description = 15; Destin->RandomReference = Destin->MessageContent & 0x07;} /* Case 01110xxx */
		else if ((Destin->MessageContent & 0xFF) == 0x67) {Destin->Description = 16;} /* Case 01100111 */
		else if ((Destin->MessageContent & 0xF9) == 0x60) {Destin->Description = 17; Destin->RandomReference = (Destin->MessageContent & 0x07)>>1;} /* Case 01100xx0 */
		else if ((Destin->MessageContent & 0xFB) == 0x61) {Destin->Description = 18; Destin->RandomReference = (Destin->MessageContent & 0x07)>>2;} /* Case 01100x01 */
		else if ((Destin->MessageContent & 0xFF) == 0x63) {Destin->Description = 18;} /* Case 01100011 */
		else if ((Destin->MessageContent & 0xFF) == 0x7F) {Destin->Description = 18;} /* Case 01111111 */

		return 8;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_BCCH (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_BCCH* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#ifdef EC_MSGTYPE_SIZE
#undef EC_MSGTYPE_SIZE
#endif
#define EC_MSGTYPE_SIZE 3
  	
  	int paramRet;
  	int ret = EC_MSGTYPE_SIZE;
  	

  	/* Push MessageType */
  	PUSH_INT (Source->MessageType, EC_MSGTYPE_SIZE);

#ifdef ENCMESSAGE
#undef ENCMESSAGE
#endif
#ifndef ED_EXTRAPARAMS_CALL
#define ED_EXTRAPARAMS_CALL
#endif
#define ENCMESSAGE(TYPNAM) if (GETPRESENT_c_EC_BCCH_contents_p_##TYPNAM (&Source->contents)) {\
			paramRet = ENCODE_c_##TYPNAM (Buffer, BitOffset+EC_MSGTYPE_SIZE, ED_AMP(Source->contents.u.p_##TYPNAM) ED_EXTRAPARAMS_CALL);\
			if (paramRet < 0) ret = paramRet;\
			else ret += paramRet;\
		}\

		switch (Source->MessageType) {
			case  1: ENCMESSAGE(EC_System_Information_Type_1); break;
			case  2: ENCMESSAGE(EC_System_Information_Type_2); break;
			case  3: ENCMESSAGE(EC_System_Information_Type_3); break;
			case  4: ENCMESSAGE(EC_System_Information_Type_4); break;
			default: {
				if (GETPRESENT_c_EC_BCCH_contents_p_UnknownMessage (&Source->contents)) {
					EDCopyBits (Buffer, EC_MSGTYPE_SIZE, Source->contents.u.p_UnknownMessage->value, 0, Source->contents.u.p_UnknownMessage->usedBits);
					ret += Source->contents.u.p_UnknownMessage->usedBits;
				}
			}
		}

		return ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_BCCH (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_BCCH* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret = EC_MSGTYPE_SIZE;
		int paramRet;

		/* Set the locator */
		ED_LOCATOR_SET (&(Destin->MessageType___LOCATOR), CurrOfs, EC_MSGTYPE_SIZE);

		/* Read message type */
		Destin->MessageType = (ED_OCTET)SHIFT_INT (EC_MSGTYPE_SIZE);
		

#ifdef DECMESSAGE
#undef DECMESSAGE
#endif
#ifndef ED_EXTRAPARAMS_CALL
#define ED_EXTRAPARAMS_CALL
#endif
#define DECMESSAGE(TYPNAM) {SETPRESENT_c_EC_BCCH_contents_p_##TYPNAM (&Destin->contents);\
		paramRet = DECODE_c_##TYPNAM (Buffer, BitOffset+EC_MSGTYPE_SIZE, ED_AMP(Destin->contents.u.p_##TYPNAM), Length-EC_MSGTYPE_SIZE ED_EXTRAPARAMS_CALL); if (paramRet<0) return paramRet;}

		/* Decode contents */
		switch (Destin->MessageType) {
			case  1: DECMESSAGE(EC_System_Information_Type_1); break;
			case  2: DECMESSAGE(EC_System_Information_Type_2); break;
			case  3: DECMESSAGE(EC_System_Information_Type_3); break;
			case  4: DECMESSAGE(EC_System_Information_Type_4); break;
			default: {
				SETPRESENT_c_EC_BCCH_contents_p_UnknownMessage (&Destin->contents);
				ED_LOCATOR_SET (&(Destin->contents.u_locator.p_UnknownMessage___LOCATOR), CurrOfs, Length-EC_MSGTYPE_SIZE);
				ALLOC_c_EC_BCCH_contents_p_UnknownMessage(Destin->contents.u.p_UnknownMessage, Length-EC_MSGTYPE_SIZE);
				EDCopyBits (Destin->contents.u.p_UnknownMessage->value, 0, Buffer, EC_MSGTYPE_SIZE, Length-EC_MSGTYPE_SIZE);
				paramRet = Length-EC_MSGTYPE_SIZE;
			}
		}

		return ret + paramRet;
#undef EC_MSGTYPE_SIZE
 
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_CCCH (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_CCCH* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#ifdef EC_MSGTYPE_SIZE
#undef EC_MSGTYPE_SIZE
#endif
#define EC_MSGTYPE_SIZE 4
  	
  	int paramRet;
  	int ret = EC_MSGTYPE_SIZE;
  	

  	/* Push MessageType */
  	PUSH_INT (Source->MessageType, EC_MSGTYPE_SIZE);

#ifdef ENCMESSAGE
#undef ENCMESSAGE
#endif
#ifndef ED_EXTRAPARAMS_CALL
#define ED_EXTRAPARAMS_CALL
#endif
#define ENCMESSAGE(TYPNAM) if (GETPRESENT_c_EC_CCCH_contents_p_##TYPNAM (&Source->contents)) {\
			paramRet = ENCODE_c_##TYPNAM (Buffer, BitOffset+EC_MSGTYPE_SIZE, ED_AMP(Source->contents.u.p_##TYPNAM) ED_EXTRAPARAMS_CALL);\
			if (paramRet < 0) ret = paramRet;\
			else ret += paramRet;\
		}\

		switch (Source->MessageType) {
			case  1: ENCMESSAGE(EC_IMMEDIATE_ASSIGNMENT_TYPE_2); break;
			case  2: ENCMESSAGE(EC_IMMEDIATE_ASSIGNMENT_REJECT); break;
			case  3: ENCMESSAGE(EC_DUMMY                      ); break;
			case  4: ENCMESSAGE(EC_DOWNLINK_ASSIGNMENT        ); break;
			case  5: ENCMESSAGE(EC_PAGING_REQUEST             ); break;
			default: {
				if (GETPRESENT_c_EC_CCCH_contents_p_UnknownMessage (&Source->contents)) {
					EDCopyBits (Buffer, EC_MSGTYPE_SIZE, Source->contents.u.p_UnknownMessage->value, 0, Source->contents.u.p_UnknownMessage->usedBits);
					ret += Source->contents.u.p_UnknownMessage->usedBits;
				}
			}
		}

		return ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_CCCH (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_CCCH* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int ret = EC_MSGTYPE_SIZE;
		int paramRet;

		/* Set the locator */
		ED_LOCATOR_SET (&(Destin->MessageType___LOCATOR), CurrOfs, EC_MSGTYPE_SIZE);

		/* Read message type */
		Destin->MessageType = (ED_OCTET)SHIFT_INT (EC_MSGTYPE_SIZE);
		

#ifdef DECMESSAGE
#undef DECMESSAGE
#endif
#ifndef ED_EXTRAPARAMS_CALL
#define ED_EXTRAPARAMS_CALL
#endif
#define DECMESSAGE(TYPNAM) {SETPRESENT_c_EC_CCCH_contents_p_##TYPNAM (&Destin->contents);\
		paramRet = DECODE_c_##TYPNAM (Buffer, BitOffset+EC_MSGTYPE_SIZE, ED_AMP(Destin->contents.u.p_##TYPNAM), Length-EC_MSGTYPE_SIZE ED_EXTRAPARAMS_CALL); if (paramRet<0) return paramRet;}

		/* Decode contents */
		switch (Destin->MessageType) {
			case  1: DECMESSAGE(EC_IMMEDIATE_ASSIGNMENT_TYPE_2); break;
			case  2: DECMESSAGE(EC_IMMEDIATE_ASSIGNMENT_REJECT); break;
			case  3: DECMESSAGE(EC_DUMMY                      ); break;
			case  4: DECMESSAGE(EC_DOWNLINK_ASSIGNMENT        ); break;
			case  5: DECMESSAGE(EC_PAGING_REQUEST             ); break;
			default: {
				SETPRESENT_c_EC_CCCH_contents_p_UnknownMessage (&Destin->contents);
				ED_LOCATOR_SET (&(Destin->contents.u_locator.p_UnknownMessage___LOCATOR), CurrOfs, Length-EC_MSGTYPE_SIZE);
				ALLOC_c_EC_CCCH_contents_p_UnknownMessage(Destin->contents.u.p_UnknownMessage, Length-EC_MSGTYPE_SIZE);
				EDCopyBits (Destin->contents.u.p_UnknownMessage->value, 0, Buffer, EC_MSGTYPE_SIZE, Length-EC_MSGTYPE_SIZE);
				paramRet = Length-EC_MSGTYPE_SIZE;
			}
		}

		return ret + paramRet;
#undef EC_MSGTYPE_SIZE
 
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BaRange (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BaRange* ED_CONST Source))
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

		/* Write the 10-bits fields */
		for (i=0; i<Source->items; i++) {
			PUSH_INT (VAR_c_BaRange_data (Source->data [i]).Lower, 10);
			PUSH_INT (VAR_c_BaRange_data (Source->data [i]).Higher, 10);
		}

		/* Calculate how many bits are left to complete an octet */
		i = 8 - (CURPOS & 7);
		if (i != 8) PUSH_INT (0, i);

		return CURPOS-BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BaRange (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BaRange* ED_CONST Destin, ED_EXLONG Length))
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

		SETITEMS_c_BaRange (Destin, SHIFT_INT (8));

		/* Read the 10-bits fields */
		for (i=0; i<Destin->items; i++) {
			VAR_c_BaRange_data (Destin->data [i]).Lower = SHIFT_INT (10);
			VAR_c_BaRange_data (Destin->data [i]).Higher = SHIFT_INT (10);
		}

		/* Calculate how many bits are left to complete an octet */
		i = 8 - (CURPOS & 7);

		if (i != 8) CURPOS += i;

		return CURPOS-BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CellChannel (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CellChannel* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, len;
		switch (GETPRESENT_c_CellChannel (Source)) {
			/*---------------------------------------------------------
				DETECT BITMAP 0 FORMAT (signature 00XXX)
			---------------------------------------------------------*/
			case U_c_CellChannel_BitMap0: {
				PUSH_INT (0, 4); /* Signature */
				for (i=0; i<VAR_c_CellChannel_BitMap0 (Source->u.BitMap0).items; i++) {
					PUSH_INT ((VAR_c_CellChannel_BitMap0 (Source->u.BitMap0).data [(VAR_c_CellChannel_BitMap0 (Source->u.BitMap0).items)-i-1]? 1 : 0), 1);
				}
				break;
			}
			/*---------------------------------------------------------
				DETECT BITMAP 1024 RANGE (signature 10000XX)
			---------------------------------------------------------*/
			case U_c_CellChannel_Range1024: {
				PUSH_INT (0x10, 5); /* Signature */

				PUSH_INT ((VAR_c_CellChannel_Range1024 (Source->u.Range1024).F0? 1 : 0), 1);

				for (i=0; i < VAR_c_CellChannel_Range1024 (Source->u.Range1024).W.items; i++) {
					if (i==0) len = 10;
					else if (i>=1 && i<=2) len = 9;
					else if (i>=3 && i<=6) len = 8;
					else if (i>=7 && i<=14) len = 7;
					else if (i>=15 && i<=30) len = 6;
					else if (i>=31 && i<=62) len = 5;
					else if (i>=63 && i<=126) len = 4;
					else len = 3;
					PUSH_INT (VAR_c_CellChannel_Range1024 (Source->u.Range1024).W.data [i], len);
				}
				break;
			}
			/*---------------------------------------------------------
				DETECT BITMAP 512 RANGE (signature 1000100)
			---------------------------------------------------------*/
			case U_c_CellChannel_Range512: {
				PUSH_INT (0x44, 7); /* Signature */

				PUSH_INT (VAR_c_CellChannel_Range512 (Source->u.Range512).OrigARFCN, 10);

				for (i=0; i < VAR_c_CellChannel_Range512 (Source->u.Range512).W.items; i++) {
					if (i==0) len = 9;
					else if (i>=1 && i<=2) len = 8;
					else if (i>=3 && i<=6) len = 7;
					else if (i>=7 && i<=14) len = 6;
					else if (i>=15 && i<=30) len = 5;
					else if (i>=31 && i<=62) len = 4;
					else if (i>=63 && i<=126) len = 3;
					else len = 2;
					PUSH_INT (VAR_c_CellChannel_Range512 (Source->u.Range512).W.data [i], len);
				}

				break;
			}
			/*---------------------------------------------------------
				DETECT BITMAP 256 RANGE (signature 1000101)
			---------------------------------------------------------*/
			case U_c_CellChannel_Range256: {
				PUSH_INT (0x45, 7); /* Signature */

				PUSH_INT (VAR_c_CellChannel_Range256 (Source->u.Range256).OrigARFCN, 10);

				for (i=0; i<VAR_c_CellChannel_Range256 (Source->u.Range256).W.items; i++) {
					if (i==0) len = 8;
					else if (i>=1 && i<=2) len = 7;
					else if (i>=3 && i<=6) len = 6;
					else if (i>=7 && i<=14) len = 5;
					else if (i>=15 && i<=30) len = 4;
					else if (i>=31 && i<=62) len = 3;
					else if (i>=63 && i<=126) len = 2;
					else len = 1;
					PUSH_INT (VAR_c_CellChannel_Range256 (Source->u.Range256).W.data [i], len);
				}

				break;
			}
			/*---------------------------------------------------------
				DETECT BITMAP 128 RANGE (signature 1000110)
			---------------------------------------------------------*/
			case U_c_CellChannel_Range128: {
				PUSH_INT (0x46, 7); /* Signature */

				PUSH_INT (VAR_c_CellChannel_Range128 (Source->u.Range128).OrigARFCN, 10);

				for (i=0; i<VAR_c_CellChannel_Range128 (Source->u.Range128).W.items; i++) {
					if (i==0) len = 7;
					else if (i>=1 && i<=2) len = 6;
					else if (i>=3 && i<=6) len = 5;
					else if (i>=7 && i<=14) len = 4;
					else if (i>=15 && i<=30) len = 3;
					else if (i>=31 && i<=62) len = 2;
					else len = 1;

					PUSH_INT (VAR_c_CellChannel_Range128 (Source->u.Range128).W.data [i], len);
				}

				break;
			}
			/*---------------------------------------------------------
				DETECT BITMAP VARIABLE (signature 1000111)
			---------------------------------------------------------*/
			case U_c_CellChannel_Variable: {
				PUSH_INT (0x47, 7); /* Signature */

				PUSH_INT (VAR_c_CellChannel_Variable (Source->u.Variable).OrigARFCN, 10);

				for (i=0; i<VAR_c_CellChannel_Variable (Source->u.Variable).RRFCN.items; i++) {
					PUSH_INT (VAR_c_CellChannel_Variable (Source->u.Variable).RRFCN.data [i], 1);
				}

				break;
			}
			/*---------------------------------------------------------
				UNKNOWN CODING!
			---------------------------------------------------------*/
			default: return ED_SYNTAX_ERROR;
		}

		/* Pad with zeroes */
		len = (8 - (CURPOS & 7)) & 7;
		if (len > 0) PUSH_INT (0, len);

		return CURPOS-BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CellChannel (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CellChannel* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		int i, len;

		/* Determine which type of encoding we have */
		int Signature = EDBitsToInt (Buffer, CURPOS, 7);

		/* Make sure spare bits are set to 0 */
		Signature &= 0x47;

		/*---------------------------------------------------------
			DETECT BITMAP 0 FORMAT (signature 00XXX)
		---------------------------------------------------------*/
		if ((Signature & 0x60) == 0x00) {
			int len = Length-4;
			if (len > 124) len = 124;
			SETPRESENT_c_CellChannel_BitMap0 (Destin);
			CURPOS += 4;
			ADDITEMS_c_CellChannel_BitMap0 (&(VAR_c_CellChannel_BitMap0 (Destin->u.BitMap0)), len);
			for (i=0; i<len; i++) {
				ED_LOCATOR_SET (&(VAR_c_CellChannel_BitMap0 (Destin->u.BitMap0).data___LOCATOR [len-i-1]), CURPOS, 1);
				VAR_c_CellChannel_BitMap0 (Destin->u.BitMap0).data [len-i-1] = (unsigned char)SHIFT_INT (1);
			}
			VAR_c_CellChannel_BitMap0 (Destin->u.BitMap0).items = i;
		}
		/*---------------------------------------------------------
			DETECT BITMAP 1024 RANGE (signature 10000XX)
		---------------------------------------------------------*/
		else if ((Signature & 0x64) == 0x40) {
			SETPRESENT_c_CellChannel_Range1024 (Destin);
			CURPOS += 5;
			VAR_c_CellChannel_Range1024 (Destin->u.Range1024).F0 = (unsigned char)SHIFT_INT (1);

			for (i=0; i<64; i++) {
				if (i==0) len = 10;
				else if (i>=1 && i<=2) len = 9;
				else if (i>=3 && i<=6) len = 8;
				else if (i>=7 && i<=14) len = 7;
				else if (i>=15 && i<=30) len = 6;
				else if (i>=31 && i<=62) len = 5;
				else if (i>=63 && i<=126) len = 4;
				else len = 3;
				if (CURPOS - BitOffset + len > Length) break;
				ADDITEMS_c_CellChannel_Range1024_W (&(VAR_c_CellChannel_Range1024 (Destin->u.Range1024).W), 1);
				ED_LOCATOR_SET (&(VAR_c_CellChannel_Range1024 (Destin->u.Range1024).W.data___LOCATOR [i]), CURPOS, len);
				VAR_c_CellChannel_Range1024 (Destin->u.Range1024).W.data [i] = SHIFT_INT (len);
			}
			VAR_c_CellChannel_Range1024 (Destin->u.Range1024).W.items = i;
		}
		/*---------------------------------------------------------
			DETECT BITMAP 512 RANGE (signature 1000100)
		---------------------------------------------------------*/
		else if ((Signature & 0x67) == 0x44) {
			SETPRESENT_c_CellChannel_Range512 (Destin);
			CURPOS += 7;
			VAR_c_CellChannel_Range512 (Destin->u.Range512).OrigARFCN = SHIFT_INT (10);

			for (i=0; i<64; i++) {
				if (i==0) len = 9;
				else if (i>=1 && i<=2) len = 8;
				else if (i>=3 && i<=6) len = 7;
				else if (i>=7 && i<=14) len = 6;
				else if (i>=15 && i<=30) len = 5;
				else if (i>=31 && i<=62) len = 4;
				else if (i>=63 && i<=126) len = 3;
				else len = 2;
				if (CURPOS - BitOffset + len > Length) break;
				ADDITEMS_c_CellChannel_Range512_W (&(VAR_c_CellChannel_Range512 (Destin->u.Range512).W), 1);
				ED_LOCATOR_SET (&(VAR_c_CellChannel_Range512 (Destin->u.Range512).W.data___LOCATOR [i]), CURPOS, len);
				VAR_c_CellChannel_Range512 (Destin->u.Range512).W.data [i] = SHIFT_INT (len);
			}
			VAR_c_CellChannel_Range512 (Destin->u.Range512).W.items = i;
		}
		/*---------------------------------------------------------
			DETECT BITMAP 256 RANGE (signature 1000101)
		---------------------------------------------------------*/
		else if ((Signature & 0x67) == 0x45) {
			SETPRESENT_c_CellChannel_Range256 (Destin);
			CURPOS += 7;
			VAR_c_CellChannel_Range256 (Destin->u.Range256).OrigARFCN = SHIFT_INT (10);

			for (i=0; i<64; i++) {
				if (i==0) len = 8;
				else if (i>=1 && i<=2) len = 7;
				else if (i>=3 && i<=6) len = 6;
				else if (i>=7 && i<=14) len = 5;
				else if (i>=15 && i<=30) len = 4;
				else if (i>=31 && i<=62) len = 3;
				else if (i>=63 && i<=126) len = 2;
				else len = 1;
				if (CURPOS - BitOffset + len > Length) break;
				ADDITEMS_c_CellChannel_Range256_W (&(VAR_c_CellChannel_Range256 (Destin->u.Range256).W), 1);
				ED_LOCATOR_SET (&(VAR_c_CellChannel_Range256 (Destin->u.Range256).W.data___LOCATOR [i]), CURPOS, len);
				VAR_c_CellChannel_Range256 (Destin->u.Range256).W.data [i] = SHIFT_INT (len);
			}
			VAR_c_CellChannel_Range256 (Destin->u.Range256).W.items = i;
		}
		/*---------------------------------------------------------
			DETECT BITMAP 128 RANGE (signature 1000110)
		---------------------------------------------------------*/
		else if ((Signature & 0x67) == 0x46) {
			SETPRESENT_c_CellChannel_Range128 (Destin);
			CURPOS += 7;

			VAR_c_CellChannel_Range128 (Destin->u.Range128).OrigARFCN = SHIFT_INT (10);

			for (i=0; i<64; i++) {
				if (i==0) len = 7;
				else if (i>=1 && i<=2) len = 6;
				else if (i>=3 && i<=6) len = 5;
				else if (i>=7 && i<=14) len = 4;
				else if (i>=15 && i<=30) len = 3;
				else if (i>=31 && i<=62) len = 2;
				else len = 1;
				if (CURPOS - BitOffset + len > Length) break;
				ADDITEMS_c_CellChannel_Range128_W (&(VAR_c_CellChannel_Range128 (Destin->u.Range128).W), 1);
				ED_LOCATOR_SET (&(VAR_c_CellChannel_Range128 (Destin->u.Range128).W.data___LOCATOR [i]), CURPOS, len);
				VAR_c_CellChannel_Range128 (Destin->u.Range128).W.data [i] = SHIFT_INT (len);
			}
			VAR_c_CellChannel_Range128 (Destin->u.Range128).W.items = i;
		}
		/*---------------------------------------------------------
			DETECT BITMAP VARIABLE (signature 1000111)
		---------------------------------------------------------*/
		else if ((Signature & 0x67) == 0x47) {
			SETPRESENT_c_CellChannel_Variable (Destin);
			CURPOS += 7;

			VAR_c_CellChannel_Variable (Destin->u.Variable).OrigARFCN = SHIFT_INT (10);
			for (i=0; (CURPOS - BitOffset < Length) && i<111; i++) {
				ADDITEMS_c_CellChannel_Variable_RRFCN (&(VAR_c_CellChannel_Variable (Destin->u.Variable).RRFCN), 1);
				ED_LOCATOR_SET (&(VAR_c_CellChannel_Variable (Destin->u.Variable).RRFCN.data___LOCATOR [i]), CURPOS, 1);
				VAR_c_CellChannel_Variable (Destin->u.Variable).RRFCN.data [i] = (unsigned char)SHIFT_INT (1);
			}
			VAR_c_CellChannel_Variable (Destin->u.Variable).RRFCN.items = i;
		}
		/*---------------------------------------------------------
			UNKNOWN CODING!
		---------------------------------------------------------*/
		else {
			return ED_SYNTAX_ERROR;
		}

		return CURPOS - BitOffset + ((8 - (CURPOS & 7)) & 7);
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TChType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TChType* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int Value = 0;
    int EncodeSBit = 0;
    switch (Source->ChType) {
      case 1: Value = 1; EncodeSBit=1; break;
      case 2: Value = 2 | (Source->Subchannel & 0x01); EncodeSBit=1; break;
      case 4: Value = 4 | (Source->Subchannel & 0x03); break;
      case 8: Value = 8 | (Source->Subchannel & 0x07); break;
    }
    
    /* Encode the S (TCSSet) bit */
    if (EncodeSBit && GETPRESENT_c_TChType_TSCSet (Source) && Source->TSCSet) {
    	Value |= 16;
    }
    
    PUSH_INT (Value, 5);
    return 5;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TChType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TChType* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int Value;
    int DecodeSBit = 0;
    int Start = (int)BitOffset;
		ED_LOCATOR_SET (&(Destin->ChType___LOCATOR), Start, 5);
		
    Value = SHIFT_INT (5);
    if ((Value & 0x0F) == 1) {
      Destin->Subchannel = 0;
      Destin->ChType = 1;
      DecodeSBit = 1;
    }
    else if ((Value & 0x18) == 0x08) {
      Destin->Subchannel = Value & 0x07;
      Destin->ChType = 8;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+2, 3);
    }
    else if ((Value & 0x1C) == 0x04) {
      Destin->Subchannel = Value & 0x03;
      Destin->ChType = 4;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+3, 2);
    }
    else if ((Value & 0x0E) == 0x02) {
      Destin->Subchannel = Value & 0x01;
      Destin->ChType = 2;
      DecodeSBit = 1;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+4, 1);
    }
    if (DecodeSBit) {
    	SETPRESENT_c_TChType_TSCSet (Destin, ED_TRUE);
    	Destin->TSCSet = (((Value & 0x10) == 0x10) ? ED_TRUE : ED_FALSE);
			ED_LOCATOR_SET (&(Destin->TSCSet___LOCATOR), Start, 1);
    }

    return 5;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TChType2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TChType2* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int Value = 0;
    switch (Source->ChType) {
      case 1: Value = 1; break;
      case 2: Value = 2 | (Source->Subchannel & 0x01); break;
      case 4: Value = 4 | (Source->Subchannel & 0x03); break;
      case 8: Value = 8 | (Source->Subchannel & 0x07); break;
      case 28: Value = 28 | (Source->Subchannel & 0x01); break;
      default: Value = Source->ChType;
    }
    
    PUSH_INT (Value, 5);
    return 5;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TChType2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TChType2* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int Start = (int)BitOffset;
    int Value = SHIFT_INT (5);
		ED_LOCATOR_SET (&(Destin->ChType___LOCATOR), Start, 5);
    if ((Value & 0x1E) == 0x1C) {
      Destin->Subchannel = Value & 0x01;
      Destin->ChType = 0x1C;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+4, 1);
    }
    else if ((Value & 0x18) == 0x08) {
      Destin->Subchannel = Value & 0x07;
      Destin->ChType = 8;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+2, 3);
    }
    else if ((Value & 0x1C) == 0x04) {
      Destin->Subchannel = Value & 0x03;
      Destin->ChType = 4;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+3, 2);
    }
    else if ((Value & 0x1E) == 0x02) {
      Destin->Subchannel = Value & 0x01;
      Destin->ChType = 2;
			ED_LOCATOR_SET (&(Destin->Subchannel___LOCATOR), Start+4, 1);
    }
    else {Destin->ChType = Value;}

    return 5;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileAllocation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileAllocation* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i;

		/* Push the values */
		for (i=0; i<Source->items; i++) {
			PUSH_INT (Source->data [Source->items-i-1], 1);
		}
		return Source->items;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileAllocation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileAllocation* ED_CONST Destin, ED_EXLONG Length))
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

		/* Now we know exactly how many items to expect */
  	SETITEMS_c_MobileAllocation (Destin, Length);

  	/* Now we know whether digit 1 is valid or not */
		for (i=0; i < Length; i++) {
			ED_LOCATOR_SET(&(Destin->data___LOCATOR [Length-i-1]), BitOffset, 1);
			Destin->data [Length-i-1] = (unsigned char)SHIFT_INT (1);
		}
		return Length;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NeighbourCellDescription (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NeighbourCellDescription* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int ret = ENCODE_c_CellChannel (Buffer, BitOffset, PTR_c_NeighbourCellDescription_CellDescription (THIS->CellDescription));
    EDIntToBits (Buffer, BitOffset+2, (THIS->ExtInd? 1 : 0), 1);
    EDIntToBits (Buffer, BitOffset+3, (THIS->BAInd? 1 : 0), 1);
    return ret;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NeighbourCellDescription (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NeighbourCellDescription* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int ret = DECODE_c_CellChannel (Buffer, BitOffset, PTR_c_NeighbourCellDescription_CellDescription (THIS->CellDescription), Length);
    THIS->ExtInd = (EDBitsToInt (Buffer, BitOffset+2, 1) ? ED_TRUE : ED_FALSE);
    THIS->BAInd = (EDBitsToInt (Buffer, BitOffset+3, 1) ? ED_TRUE : ED_FALSE);
    return ret;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NeighbourCellDescription2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NeighbourCellDescription2* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int ret = ENCODE_c_CellChannel (Buffer, BitOffset, PTR_c_NeighbourCellDescription_CellDescription (THIS->CellDescription));
    EDIntToBits (Buffer, BitOffset+1, THIS->MultibandReporting, 2);
    EDIntToBits (Buffer, BitOffset+3, (THIS->BAInd? 1 : 0), 1);
    return ret;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NeighbourCellDescription2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NeighbourCellDescription2* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

    int ret = DECODE_c_CellChannel (Buffer, BitOffset, PTR_c_NeighbourCellDescription_CellDescription (THIS->CellDescription), Length);
    THIS->MultibandReporting = (unsigned char)EDBitsToInt (Buffer, BitOffset+1, 2);
    THIS->BAInd = (EDBitsToInt (Buffer, BitOffset+3, 1) ? ED_TRUE : ED_FALSE);
    return ret;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRMobileId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRMobileId* ED_CONST Source))
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRMobileId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRMobileId* ED_CONST Destin, ED_EXLONG Length))
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
  	SETITEMS_c_RRMobileId_IdentityDigit (&Destin->IdentityDigit, (Length >> 2) - (odd ? 1 : 2));

  	/* Now we know whether digit 1 is valid or not */
  	if (Destin->IdentityDigit.items > 0) Destin->IdentityDigit.data [0] = i;

		/* Extract identity type */
		Destin->IdentityType = SHIFT_INT (3);

		/* If decoding a TMSI/P-TMSI, just get the following bytes */
		if (Destin->IdentityType == 4) {
			SETITEMS_c_RRMobileId_IdentityDigit (&(Destin->IdentityDigit), (Length>>3) - 1);
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FDD_CELL_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FDD_CELL_INFORMATION* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#define MAX_FDD_Ws 32
#define MAX_FDD_CellInfo 32
		unsigned W [MAX_FDD_Ws];
		unsigned CellInfo [MAX_FDD_CellInfo];
		int FDD_Indic0;
		int records;
		int i;
		
		for (i=0; i<Source->items; i++) {
			CellInfo [i] = (VAR_c_FDD_CELL_INFORMATION_data (Source->data [i]).Diversity ? 0x200 : 0) | (VAR_c_FDD_CELL_INFORMATION_data (Source->data [i]).ScramblingCode & 0x1FF);
		}

		records = ENCODE_AnnexJ (CellInfo, Source->items, W, sizeof(W)/sizeof(W[0]), 1023, &FDD_Indic0);
		if (records < 0) return records;
		
		/* Encode FDD_Indic0 */
		EDIntToBits (Buffer, BitOffset-6, (FDD_Indic0 ? 1 : 0), 1);

		/* Encode NR_OF_FDD_CELLS */
		EDIntToBits (Buffer, BitOffset-5, Source->items - (FDD_Indic0 ? 1 : 0), 5);
		
		/* Encode the binary data */
		for (i=0; i<records; i++) {
			PUSH_INT (W[i], AnnexJ_R1024 [i]);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FDD_CELL_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FDD_CELL_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		/* FDD "W" words, encoded in Range-1024 format */
		unsigned W [MAX_FDD_Ws];
		unsigned CellInfo [MAX_FDD_CellInfo];
		unsigned remaining = (unsigned)(Length < 0 ? 0 : Length);
		unsigned i;
		int used = 0;
		int FDD_Indic0;
		int records;
		
		/* Decode the FDD_Indic0 bit */
		FDD_Indic0 = EDBitsToInt (Buffer, BitOffset-6, 1);
		
		/* Decode the Range-1024 bits locally */
		for (i=0; i<MAX_FDD_Ws; i++) {
			if (remaining >= AnnexJ_R1024 [i]) {
				W [i] = SHIFT_INT (AnnexJ_R1024 [i]);
				remaining -= AnnexJ_R1024 [i];
				used ++;
			}
			else break;
		}
		
		records = DECODE_AnnexJ (W, used, CellInfo, sizeof(CellInfo)/sizeof(CellInfo[0]), 1023, FDD_Indic0);
		if (records < 0) return records;
		
		SETITEMS_c_FDD_CELL_INFORMATION (Destin, records);
		for (i=0; (int)i<records; i++) {
			VAR_c_FDD_CELL_INFORMATION_data (Destin->data [i]).Diversity = ((CellInfo[i] & 0x200) != 0);
			VAR_c_FDD_CELL_INFORMATION_data (Destin->data [i]).ScramblingCode = (CellInfo[i] & 0x1FF);
		}
		
		return Length;
#undef MAX_FDD_Ws
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TDD_CELL_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TDD_CELL_INFORMATION* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

#define MAX_TDD_Ws 32
#define MAX_TDD_CellInfo 32
		unsigned W [MAX_TDD_Ws];
		unsigned CellInfo [MAX_TDD_CellInfo];
		int TDD_Indic0;
		int records;
		int i;
		
		for (i=0; i<Source->items; i++) {
			CellInfo [i] = 
				(VAR_c_TDD_CELL_INFORMATION_data (Source->data [i]).Diversity ? 0x100 : 0) | 
				(VAR_c_TDD_CELL_INFORMATION_data (Source->data [i]).SyncCaseTSTD ? 0x80 : 0) |
				(VAR_c_TDD_CELL_INFORMATION_data (Source->data [i]).CellParameter & 0x7f)
			;
		}

		records = ENCODE_AnnexJ (CellInfo, Source->items, W, sizeof(W)/sizeof(W[0]), 511, &TDD_Indic0);
		if (records < 0) return records;
		
		/* Encode TDD_Indic0 */
		EDIntToBits (Buffer, BitOffset-6, (TDD_Indic0 ? 1 : 0), 1);

		/* Encode NR_OF_TDD_CELLS */
		EDIntToBits (Buffer, BitOffset-5, Source->items - (TDD_Indic0 ? 1 : 0), 5);
		
		/* Encode the binary data */
		for (i=0; i<records; i++) {
			PUSH_INT (W[i], AnnexJ_R512 [i]);
		}

		return CURPOS - BitOffset;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TDD_CELL_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TDD_CELL_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		/* TDD "W" words, encoded in Range-512 format */
		unsigned W [MAX_TDD_Ws];
		unsigned CellInfo [MAX_TDD_CellInfo];
		unsigned remaining = (unsigned)(Length < 0 ? 0 : Length);
		unsigned i;
		int used = 0;
		int TDD_Indic0;
		int records;
		
		/* Decode the TDD_Indic0 bit */
		TDD_Indic0 = EDBitsToInt (Buffer, BitOffset-6, 1);
		
		/* Decode the Range-512 bits locally */
		for (i=0; i<MAX_TDD_Ws; i++) {
			if (remaining >= AnnexJ_R512 [i]) {
				W [i] = SHIFT_INT (AnnexJ_R512 [i]);
				remaining -= AnnexJ_R512 [i];
				used ++;
			}
			else break;
		}
		
		records = DECODE_AnnexJ (W, used, CellInfo, sizeof(CellInfo)/sizeof(CellInfo[0]), 511, TDD_Indic0);
		if (records < 0) return records;
		
		SETITEMS_c_TDD_CELL_INFORMATION (Destin, records);
		for (i=0; (int)i<records; i++) {
			VAR_c_TDD_CELL_INFORMATION_data (Destin->data [i]).Diversity = ((CellInfo[i] & 0x100) != 0);
			VAR_c_TDD_CELL_INFORMATION_data (Destin->data [i]).SyncCaseTSTD = ((CellInfo[i] & 0x80) != 0);
			VAR_c_TDD_CELL_INFORMATION_data (Destin->data [i]).CellParameter = (CellInfo[i] & 0x7f);
		}
		
		return Length;
#undef MAX_TDD_Ws
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_RR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_RR* ED_CONST Source))
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_RR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_RR* ED_CONST Destin, ED_EXLONG Length))
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
		ALLOC_c_GenericTLV_RR_TLV_Data (&(Destin->TLV_Data), DataLength);

		
		/* Save the bits in the binary data */
		EDCopyBits (Destin->TLV_Data.value, 0, Buffer, CurrOfs, DataLength);
		CurrOfs += (ED_EXLONG)EffectiveDataLength;
	}
	
	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
