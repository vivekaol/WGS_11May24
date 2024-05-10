/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "UserDefinedDataTypes_EPS.h"
#include "ed_c_known_ie_EPS.h"
#include "ed_tlv.h"
#include "EPS_SM_Uplink_EPS.h"
#include "EPS_SM_Downlink_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSBearerContextStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSBearerContextStatus* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).EBI07 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1293> Error encoding subfield EBI07\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).EBI06 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1294> Error encoding subfield EBI06\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).EBI05 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1295> Error encoding subfield EBI05\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EBI04 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1296> Error encoding subfield EBI04\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1297> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).EBI15 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1298> Error encoding subfield EBI15\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).EBI14 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1299> Error encoding subfield EBI14\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).EBI13 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1300> Error encoding subfield EBI13\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).EBI12 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1301> Error encoding subfield EBI12\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).EBI11 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1302> Error encoding subfield EBI11\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).EBI10 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1303> Error encoding subfield EBI10\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).EBI09 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1304> Error encoding subfield EBI09\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).EBI08 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1305> Error encoding subfield EBI08\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSBearerContextStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSBearerContextStatus* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).EBI07 = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI07___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1306> Error decoding subfield EBI07\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1306)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).EBI06 = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI06___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1307> Error decoding subfield EBI06\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1307)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).EBI05 = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI05___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1308> Error decoding subfield EBI05\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1308)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EBI04 = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI04___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1309> Error decoding subfield EBI04\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1309)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1310> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1310)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).EBI15 = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI15___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1311> Error decoding subfield EBI15\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1311)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).EBI14 = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI14___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1312> Error decoding subfield EBI14\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1312)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).EBI13 = (EDBitsToInt (Buffer, CurrOfs+10, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI13___LOCATOR), CurrOfs+10, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1313> Error decoding subfield EBI13\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1313)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).EBI12 = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI12___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1314> Error decoding subfield EBI12\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1314)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).EBI11 = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI11___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1315> Error decoding subfield EBI11\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1315)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).EBI10 = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI10___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1316> Error decoding subfield EBI10\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1316)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).EBI09 = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI09___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1317> Error decoding subfield EBI09\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1317)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).EBI08 = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI08___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1318> Error decoding subfield EBI08\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1318)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateResult* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ANB_UP_CIOT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1319> Error encoding subfield ANB_UP_CIOT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ANB_CP_CIOT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1320> Error encoding subfield ANB_CP_CIOT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).Additional_update_result), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1321> Error encoding subfield Additional_update_result\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateResult* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ANB_UP_CIOT = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ANB_UP_CIOT___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1322> Error decoding subfield ANB_UP_CIOT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1322)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).ANB_CP_CIOT = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ANB_CP_CIOT___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1323> Error decoding subfield ANB_CP_CIOT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1323)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).Additional_update_result = (unsigned char)EDBitsToInt (Buffer, CurrOfs+2, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Additional_update_result___LOCATOR), CurrOfs+2, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1324> Error decoding subfield Additional_update_result\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1324)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsAdditionalUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsAdditionalUpdateType* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1325> Error encoding subfield PNB_CIoT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).SAF != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1326> Error encoding subfield SAF\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).AUTV != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1327> Error encoding subfield AUTV\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsAdditionalUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsAdditionalUpdateType* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1328> Error decoding subfield PNB_CIoT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1328)
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
		ED_SIGNAL_ERROR ("<ERRID:1329> Error decoding subfield SAF\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1329)
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
		ED_SIGNAL_ERROR ("<ERRID:1330> Error decoding subfield AUTV\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1330)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSDetachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSDetachType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).SwitchOff != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1331> Error encoding subfield SwitchOff\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).Type), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1332> Error encoding subfield Type\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSDetachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSDetachType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).SwitchOff = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).SwitchOff___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1333> Error decoding subfield SwitchOff\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1333)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).Type = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Type___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1334> Error decoding subfield Type\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1334)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity_GUTI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity_GUTI* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 88;
	EDIntToBits (Buffer, CurrOfs, 15, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1335> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1336> Error encoding subfield OddEven\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+5, 6, 3);Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1337> Error encoding subfield IdentityType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1338> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1339> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1340> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1341> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1342> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+28), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1343> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).MMEGroupID), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1344> Error encoding subfield MMEGroupID\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).MMECode), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1345> Error encoding subfield MMECode\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+56), (int)((*Source).M_TMSI), 32);
	Ret = 32;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1346> Error encoding subfield M_TMSI\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity_GUTI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity_GUTI* ED_CONST Destin, ED_EXLONG Length))
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
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1347> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1347)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1348> Error decoding subfield OddEven\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1348)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1349> Error decoding subfield IdentityType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1349)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1350> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1350)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1351> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1351)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1352> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1352)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1353> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1353)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+24, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1354> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1354)
	} 
#endif
	Len += Ret;
	
	/* FromBit=28 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+28), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+28, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1355> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1355)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MMEGroupID = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+32), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MMEGroupID___LOCATOR), CurrOfs+32, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1356> Error decoding subfield MMEGroupID\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1356)
	} 
#endif
	Len += Ret;
	
	/* FromBit=48 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).MMECode = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+48), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MMECode___LOCATOR), CurrOfs+48, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1357> Error decoding subfield MMECode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1357)
	} 
#endif
	Len += Ret;
	
	/* FromBit=56 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).M_TMSI = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs+56), 32);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).M_TMSI___LOCATOR), CurrOfs+56, 32);
	Ret = 32;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1358> Error decoding subfield M_TMSI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1358)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSNetworkFeatureSupport* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).CP_CIoT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1359> Error encoding subfield CP_CIoT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).ERw_oPDN != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1360> Error encoding subfield ERw_oPDN\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).ESR_PS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1361> Error encoding subfield ESR_PS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).CS_LCS), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1362> Error encoding subfield CS_LCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).EPC_LCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1363> Error encoding subfield EPC_LCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).EMC_BS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1364> Error encoding subfield EMC_BS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).IMS_VoPS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1365> Error encoding subfield IMS_VoPS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 4);Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1366> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).ePCO != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1367> Error encoding subfield ePCO\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).HC_CP_CIoT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1368> Error encoding subfield HC_CP_CIoT\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).S1_U_data != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1369> Error encoding subfield S1_U_data\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).UP_CIoT != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1370> Error encoding subfield UP_CIoT\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).CP_CIoT = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).CP_CIoT___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1371> Error decoding subfield CP_CIoT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1371)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ERw_oPDN = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ERw_oPDN___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1372> Error decoding subfield ERw_oPDN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1372)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ESR_PS = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ESR_PS___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1373> Error decoding subfield ESR_PS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1373)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).CS_LCS = (unsigned char)EDBitsToInt (Buffer, CurrOfs+3, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).CS_LCS___LOCATOR), CurrOfs+3, 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1374> Error decoding subfield CS_LCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1374)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).EPC_LCS = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EPC_LCS___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1375> Error decoding subfield EPC_LCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1375)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).EMC_BS = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EMC_BS___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1376> Error decoding subfield EMC_BS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1376)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).IMS_VoPS = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).IMS_VoPS___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1377> Error decoding subfield IMS_VoPS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1377)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1378> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1378)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).ePCO = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ePCO___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1379> Error decoding subfield ePCO\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1379)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).HC_CP_CIoT = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).HC_CP_CIoT___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1380> Error decoding subfield HC_CP_CIoT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1380)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).S1_U_data = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).S1_U_data___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1381> Error decoding subfield S1_U_data\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1381)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	(*Destin).UP_CIoT = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UP_CIoT___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1382> Error decoding subfield UP_CIoT\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1382)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSUpdateType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).Active != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1383> Error encoding subfield Active\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).EPSUpdTypeValue), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1384> Error encoding subfield EPSUpdTypeValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSUpdateType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).Active = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).Active___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1385> Error decoding subfield Active\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1385)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).EPSUpdTypeValue = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).EPSUpdTypeValue___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1386> Error decoding subfield EPSUpdTypeValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1386)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_KSIAndSequenceNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_KSIAndSequenceNumber* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).KSIasme), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1387> Error encoding subfield KSIasme\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).SequenceNumber), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1388> Error encoding subfield SequenceNumber\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_KSIAndSequenceNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_KSIAndSequenceNumber* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).KSIasme = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).KSIasme___LOCATOR), CurrOfs, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1389> Error decoding subfield KSIasme\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1389)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).SequenceNumber = (unsigned char)EDBitsToInt (Buffer, CurrOfs+3, 5);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).SequenceNumber___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1390> Error decoding subfield SequenceNumber\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1390)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NASKeySetIdentifier (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NASKeySetIdentifier* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).TSC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1391> Error encoding subfield TSC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).NASKeySetId), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1392> Error encoding subfield NASKeySetId\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NASKeySetIdentifier (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NASKeySetIdentifier* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).TSC = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).TSC___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1393> Error decoding subfield TSC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1393)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).NASKeySetId = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).NASKeySetId___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1394> Error decoding subfield NASKeySetId\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1394)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NASSecurityAlgorithms (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NASSecurityAlgorithms* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1395> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).TypeOfCipheringAlg), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1396> Error encoding subfield TypeOfCipheringAlg\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1397> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).TypeOfIntegrityProtectionAlg), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1398> Error encoding subfield TypeOfIntegrityProtectionAlg\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NASSecurityAlgorithms (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NASSecurityAlgorithms* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1399> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1399)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).TypeOfCipheringAlg = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfCipheringAlg___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1400> Error decoding subfield TypeOfCipheringAlg\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1400)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1401> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1401)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).TypeOfIntegrityProtectionAlg = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).TypeOfIntegrityProtectionAlg___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1402> Error decoding subfield TypeOfIntegrityProtectionAlg\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1402)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtendedEMMCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtendedEMMCause* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1403> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).E_UTRAN_allowed != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1404> Error encoding subfield E_UTRAN_allowed\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtendedEMMCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtendedEMMCause* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1405> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1405)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).E_UTRAN_allowed = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).E_UTRAN_allowed___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1406> Error decoding subfield E_UTRAN_allowed\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1406)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrackingAreaIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrackingAreaIdentity* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1407> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1408> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1409> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1410> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1411> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1412> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).TAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1413> Error encoding subfield TAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrackingAreaIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrackingAreaIdentity* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1414> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1414)
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
		ED_SIGNAL_ERROR ("<ERRID:1415> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1415)
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
		ED_SIGNAL_ERROR ("<ERRID:1416> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1416)
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
		ED_SIGNAL_ERROR ("<ERRID:1417> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1417)
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
		ED_SIGNAL_ERROR ("<ERRID:1418> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1418)
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
		ED_SIGNAL_ERROR ("<ERRID:1419> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1419)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).TAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TAC___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1420> Error decoding subfield TAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1420)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type0 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type0* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1421> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1422> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1423> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1424> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1425> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1426> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	Ret = ENCODE_c_PartialTrackingAreaIdentityList_TACS (Buffer, CurrOfs+24, (&((*Source).TAC)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1427> Error encoding subfield TAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type0 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type0* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1428> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1428)
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
		ED_SIGNAL_ERROR ("<ERRID:1429> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1429)
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
		ED_SIGNAL_ERROR ("<ERRID:1430> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1430)
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
		ED_SIGNAL_ERROR ("<ERRID:1431> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1431)
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
		ED_SIGNAL_ERROR ("<ERRID:1432> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1432)
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
		ED_SIGNAL_ERROR ("<ERRID:1433> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1433)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	Ret = DECODE_c_PartialTrackingAreaIdentityList_TACS (Buffer, CurrOfs+24, (&((*Destin).TAC)), (Length - 24));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1434> Error decoding subfield TAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1434)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type1* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 48;
	EDIntToBits (Buffer, CurrOfs, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1435> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+1, 1, 2);Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1436> Error encoding subfield TypeOfList\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).NumberOfElements), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1437> Error encoding subfield NumberOfElements\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1438> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1439> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1440> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1441> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1442> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+28), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1443> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).TAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1444> Error encoding subfield TAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type1* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1445> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1445)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1446> Error decoding subfield TypeOfList\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1446)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).NumberOfElements = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+3), 5);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).NumberOfElements___LOCATOR), CurrOfs+3, 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1447> Error decoding subfield NumberOfElements\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1447)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MCC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+8), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC2___LOCATOR), CurrOfs+8, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1448> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1448)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).MCC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+12), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC1___LOCATOR), CurrOfs+12, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1449> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1449)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	(*Destin).MNC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+16), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC3___LOCATOR), CurrOfs+16, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1450> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1450)
	} 
#endif
	Len += Ret;
	
	/* FromBit=20 */
	(*Destin).MCC3 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+20), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MCC3___LOCATOR), CurrOfs+20, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1451> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1451)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).MNC2 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+24), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC2___LOCATOR), CurrOfs+24, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1452> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1452)
	} 
#endif
	Len += Ret;
	
	/* FromBit=28 */
	(*Destin).MNC1 = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs+28), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MNC1___LOCATOR), CurrOfs+28, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1453> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1453)
	} 
#endif
	Len += Ret;
	
	/* FromBit=32 */
	(*Destin).TAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+32), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TAC___LOCATOR), CurrOfs+32, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1454> Error decoding subfield TAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1454)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentity_Type2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentity_Type2* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1455> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1456> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1457> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1458> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1459> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1460> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).TAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1461> Error encoding subfield TAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentity_Type2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentity_Type2* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1462> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1462)
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
		ED_SIGNAL_ERROR ("<ERRID:1463> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1463)
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
		ED_SIGNAL_ERROR ("<ERRID:1464> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1464)
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
		ED_SIGNAL_ERROR ("<ERRID:1465> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1465)
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
		ED_SIGNAL_ERROR ("<ERRID:1466> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1466)
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
		ED_SIGNAL_ERROR ("<ERRID:1467> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1467)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	(*Destin).TAC = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+24), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TAC___LOCATOR), CurrOfs+24, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1468> Error decoding subfield TAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1468)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTIType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTIType* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1469> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).GUTIType != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1470> Error encoding subfield GUTIType\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTIType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTIType* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1471> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1471)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).GUTIType = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).GUTIType___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1472> Error decoding subfield GUTIType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1472)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DataServiceType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DataServiceType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).ActiveFlag != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1473> Error encoding subfield ActiveFlag\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).Value), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1474> Error encoding subfield Value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DataServiceType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DataServiceType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).ActiveFlag = (EDBitsToInt (Buffer, CurrOfs, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).ActiveFlag___LOCATOR), CurrOfs, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1475> Error decoding subfield ActiveFlag\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1475)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).Value = (unsigned char)EDBitsToInt (Buffer, CurrOfs+1, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).Value___LOCATOR), CurrOfs+1, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1476> Error decoding subfield Value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1476)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDNAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDNAddress* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1477> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).PDNType), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1478> Error encoding subfield PDNType\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).PDNAddressInformation.value, 0, (*Source).PDNAddressInformation.usedBits);
	Ret = (*Source).PDNAddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1479> Error encoding subfield PDNAddressInformation\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDNAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDNAddress* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1480> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1480)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).PDNType = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PDNType___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1481> Error decoding subfield PDNType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1481)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).PDNAddressInformation___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_PDNAddress_PDNAddressInformation (&((*Destin).PDNAddressInformation), (Length - 8));
	
		if ((*Destin).PDNAddressInformation.value) {
			EDCopyBits ((*Destin).PDNAddressInformation.value, 0, Buffer, CurrOfs+8, (Length - 8));
			(*Destin).PDNAddressInformation.usedBits = (Length - 8);
			Ret = (Length - 8);
	
		}
		else {
			(*Destin).PDNAddressInformation.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 8);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1482> Error decoding subfield PDNAddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1482)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsReAttemptIndicator (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsReAttemptIndicator* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1483> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).EPLMNC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1484> Error encoding subfield EPLMNC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).RATC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1485> Error encoding subfield RATC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsReAttemptIndicator (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsReAttemptIndicator* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1486> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1486)
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
		ED_SIGNAL_ERROR ("<ERRID:1487> Error decoding subfield EPLMNC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1487)
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
		ED_SIGNAL_ERROR ("<ERRID:1488> Error decoding subfield RATC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1488)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PKMFAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PKMFAddress* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, CurrOfs, 0, 5);Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1489> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).addressType), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1490> Error encoding subfield addressType\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+16, (*Source).AddressInformation.value, 0, (*Source).AddressInformation.usedBits);
	Ret = (*Source).AddressInformation.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1491> Error encoding subfield AddressInformation\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PKMFAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PKMFAddress* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1492> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1492)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).addressType = (unsigned char)EDBitsToInt (Buffer, CurrOfs+5, 3);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).addressType___LOCATOR), CurrOfs+5, 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1493> Error decoding subfield addressType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1493)
	} 
#endif
	Len += Ret;
	
	/* FromBit=16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).AddressInformation___LOCATOR), CurrOfs+16, (Length - 16));
	if ((Length - 16) > 0) {
		/* BINDEC02 */
		ALLOC_c_PKMFAddress_AddressInformation (&((*Destin).AddressInformation), (Length - 16));
	
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
		ED_SIGNAL_ERROR ("<ERRID:1494> Error decoding subfield AddressInformation\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1494)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HeaderCompressionCfg (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HeaderCompressionCfg* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1495> Error encoding subfield Spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).P0x0104 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1496> Error encoding subfield P0x0104\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).P0x0103 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1497> Error encoding subfield P0x0103\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).P0x0102 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1498> Error encoding subfield P0x0102\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).P0x0006 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1499> Error encoding subfield P0x0006\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).P0x0004 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1500> Error encoding subfield P0x0004\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).P0x0003 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1501> Error encoding subfield P0x0003\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).P0x0002 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1502> Error encoding subfield P0x0002\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MAX_CID), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1503> Error encoding subfield MAX_CID\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+24, (*Source).Parameters.value, 0, (*Source).Parameters.usedBits);
	Ret = (*Source).Parameters.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1504> Error encoding subfield Parameters\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HeaderCompressionCfg (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HeaderCompressionCfg* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1505> Error decoding subfield Spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1505)
	} 
#endif
	Len += Ret;
	
	/* FromBit=1 */
	(*Destin).P0x0104 = (EDBitsToInt (Buffer, CurrOfs+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0104___LOCATOR), CurrOfs+1, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1506> Error decoding subfield P0x0104\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1506)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).P0x0103 = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0103___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1507> Error decoding subfield P0x0103\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1507)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).P0x0102 = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0102___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1508> Error decoding subfield P0x0102\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1508)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).P0x0006 = (EDBitsToInt (Buffer, CurrOfs+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0006___LOCATOR), CurrOfs+4, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1509> Error decoding subfield P0x0006\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1509)
	} 
#endif
	Len += Ret;
	
	/* FromBit=5 */
	(*Destin).P0x0004 = (EDBitsToInt (Buffer, CurrOfs+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0004___LOCATOR), CurrOfs+5, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1510> Error decoding subfield P0x0004\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1510)
	} 
#endif
	Len += Ret;
	
	/* FromBit=6 */
	(*Destin).P0x0003 = (EDBitsToInt (Buffer, CurrOfs+6, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0003___LOCATOR), CurrOfs+6, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1511> Error decoding subfield P0x0003\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1511)
	} 
#endif
	Len += Ret;
	
	/* FromBit=7 */
	(*Destin).P0x0002 = (EDBitsToInt (Buffer, CurrOfs+7, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).P0x0002___LOCATOR), CurrOfs+7, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1512> Error decoding subfield P0x0002\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1512)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).MAX_CID = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs+8), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).MAX_CID___LOCATOR), CurrOfs+8, 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1513> Error decoding subfield MAX_CID\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1513)
	} 
#endif
	Len += Ret;
	
	/* FromBit=24 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).Parameters___LOCATOR), CurrOfs+24, (Length - 24));
	if ((Length - 24) > 0) {
		/* BINDEC02 */
		ALLOC_c_HeaderCompressionCfg_Parameters (&((*Destin).Parameters), (Length - 24));
	
		if ((*Destin).Parameters.value) {
			EDCopyBits ((*Destin).Parameters.value, 0, Buffer, CurrOfs+24, (Length - 24));
			(*Destin).Parameters.usedBits = (Length - 24);
			Ret = (Length - 24);
	
		}
		else {
			(*Destin).Parameters.usedBits = 0;
			Ret = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Ret = (Length - 24);
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1514> Error decoding subfield Parameters\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1514)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HeaderCompressionCfgStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HeaderCompressionCfgStatus* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 16;
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).EBI_7 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1515> Error encoding subfield EBI_7\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).EBI_6 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1516> Error encoding subfield EBI_6\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).EBI_5 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1517> Error encoding subfield EBI_5\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).EBI_4 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1518> Error encoding subfield EBI_4\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).EBI_3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1519> Error encoding subfield EBI_3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).EBI_2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1520> Error encoding subfield EBI_2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).EBI_1 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1521> Error encoding subfield EBI_1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).EBI_0 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1522> Error encoding subfield EBI_0\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).EBI_15 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1523> Error encoding subfield EBI_15\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).EBI_14 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1524> Error encoding subfield EBI_14\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).EBI_13 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1525> Error encoding subfield EBI_13\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+11), (int)((*Source).EBI_12 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1526> Error encoding subfield EBI_12\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).EBI_11 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1527> Error encoding subfield EBI_11\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).EBI_10 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1528> Error encoding subfield EBI_10\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).EBI_9 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1529> Error encoding subfield EBI_9\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).EBI_8 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1530> Error encoding subfield EBI_8\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HeaderCompressionCfgStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HeaderCompressionCfgStatus* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	/* FromBit=8 */
	(*Destin).EBI_7 = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_7___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1531> Error decoding subfield EBI_7\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1531)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).EBI_6 = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_6___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1532> Error decoding subfield EBI_6\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1532)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).EBI_5 = (EDBitsToInt (Buffer, CurrOfs+10, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_5___LOCATOR), CurrOfs+10, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1533> Error decoding subfield EBI_5\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1533)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).EBI_4 = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_4___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1534> Error decoding subfield EBI_4\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1534)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).EBI_3 = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_3___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1535> Error decoding subfield EBI_3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1535)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).EBI_2 = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_2___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1536> Error decoding subfield EBI_2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1536)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).EBI_1 = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_1___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1537> Error decoding subfield EBI_1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1537)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).EBI_0 = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_0___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1538> Error decoding subfield EBI_0\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1538)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	(*Destin).EBI_15 = (EDBitsToInt (Buffer, CurrOfs+8, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_15___LOCATOR), CurrOfs+8, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1539> Error decoding subfield EBI_15\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1539)
	} 
#endif
	Len += Ret;
	
	/* FromBit=9 */
	(*Destin).EBI_14 = (EDBitsToInt (Buffer, CurrOfs+9, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_14___LOCATOR), CurrOfs+9, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1540> Error decoding subfield EBI_14\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1540)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	(*Destin).EBI_13 = (EDBitsToInt (Buffer, CurrOfs+10, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_13___LOCATOR), CurrOfs+10, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1541> Error decoding subfield EBI_13\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1541)
	} 
#endif
	Len += Ret;
	
	/* FromBit=11 */
	(*Destin).EBI_12 = (EDBitsToInt (Buffer, CurrOfs+11, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_12___LOCATOR), CurrOfs+11, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1542> Error decoding subfield EBI_12\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1542)
	} 
#endif
	Len += Ret;
	
	/* FromBit=12 */
	(*Destin).EBI_11 = (EDBitsToInt (Buffer, CurrOfs+12, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_11___LOCATOR), CurrOfs+12, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1543> Error decoding subfield EBI_11\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1543)
	} 
#endif
	Len += Ret;
	
	/* FromBit=13 */
	(*Destin).EBI_10 = (EDBitsToInt (Buffer, CurrOfs+13, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_10___LOCATOR), CurrOfs+13, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1544> Error decoding subfield EBI_10\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1544)
	} 
#endif
	Len += Ret;
	
	/* FromBit=14 */
	(*Destin).EBI_9 = (EDBitsToInt (Buffer, CurrOfs+14, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_9___LOCATOR), CurrOfs+14, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1545> Error decoding subfield EBI_9\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1545)
	} 
#endif
	Len += Ret;
	
	/* FromBit=15 */
	(*Destin).EBI_8 = (EDBitsToInt (Buffer, CurrOfs+15, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EBI_8___LOCATOR), CurrOfs+15, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1546> Error decoding subfield EBI_8\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1546)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLocationAreaId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLocationAreaId* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1547> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1548> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1549> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1550> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1551> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1552> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).LAC), 16);
	Ret = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1553> Error encoding subfield LAC\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLocationAreaId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLocationAreaId* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1554> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1554)
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
		ED_SIGNAL_ERROR ("<ERRID:1555> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1555)
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
		ED_SIGNAL_ERROR ("<ERRID:1556> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1556)
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
		ED_SIGNAL_ERROR ("<ERRID:1557> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1557)
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
		ED_SIGNAL_ERROR ("<ERRID:1558> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1558)
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
		ED_SIGNAL_ERROR ("<ERRID:1559> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1559)
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
		ED_SIGNAL_ERROR ("<ERRID:1560> Error decoding subfield LAC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1560)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId_TMGI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId_TMGI* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1561> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).MBMSSessIdIndic != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1562> Error encoding subfield MBMSSessIdIndic\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).MCCMNCIndic != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1563> Error encoding subfield MCCMNCIndic\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+4, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1564> Error encoding subfield OddEven\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).IdentityType), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1565> Error encoding subfield IdentityType\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MBMSServiceID), 24);
	Ret = 24;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1566> Error encoding subfield MBMSServiceID\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).MCC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1567> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+36), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1568> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1569> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+44), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1570> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1571> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+52), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1572> Error encoding subfield MNC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+56), (int)((*Source).MBMSSessionIdentity), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1573> Error encoding subfield MBMSSessionIdentity\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId_TMGI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId_TMGI* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1574> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1574)
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
		ED_SIGNAL_ERROR ("<ERRID:1575> Error decoding subfield MBMSSessIdIndic\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1575)
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
		ED_SIGNAL_ERROR ("<ERRID:1576> Error decoding subfield MCCMNCIndic\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1576)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	/* Allow truncation */
	if (Len >= Length) return Len;
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1577> Error decoding subfield OddEven\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1577)
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
		ED_SIGNAL_ERROR ("<ERRID:1578> Error decoding subfield IdentityType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1578)
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
		ED_SIGNAL_ERROR ("<ERRID:1579> Error decoding subfield MBMSServiceID\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1579)
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
		ED_SIGNAL_ERROR ("<ERRID:1580> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1580)
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
		ED_SIGNAL_ERROR ("<ERRID:1581> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1581)
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
		ED_SIGNAL_ERROR ("<ERRID:1582> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1582)
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
		ED_SIGNAL_ERROR ("<ERRID:1583> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1583)
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
		ED_SIGNAL_ERROR ("<ERRID:1584> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1584)
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
		ED_SIGNAL_ERROR ("<ERRID:1585> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1585)
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
		ED_SIGNAL_ERROR ("<ERRID:1586> Error decoding subfield MBMSSessionIdentity\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1586)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileStationClassmark2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileStationClassmark2* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1587> Error encoding subfield spare1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).RevisionLevel), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1588> Error encoding subfield RevisionLevel\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EsInd != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1589> Error encoding subfield EsInd\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).A5_1 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1590> Error encoding subfield A5_1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).RFPowerCapability), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1591> Error encoding subfield RFPowerCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+8, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1592> Error encoding subfield spare2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+9), (int)((*Source).PSCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1593> Error encoding subfield PSCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+10), (int)((*Source).SSScreenIndicator), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1594> Error encoding subfield SSScreenIndicator\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).SMCapability != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1595> Error encoding subfield SMCapability\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).VBS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1596> Error encoding subfield VBS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+14), (int)((*Source).VGCS != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1597> Error encoding subfield VGCS\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+15), (int)((*Source).FC != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1598> Error encoding subfield FC\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).CM3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1599> Error encoding subfield CM3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+17, 0, 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1600> Error encoding subfield spare3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+18), (int)((*Source).LCSVA_CAP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1601> Error encoding subfield LCSVA_CAP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+19), (int)((*Source).UCS2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1602> Error encoding subfield UCS2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).SoLSA != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1603> Error encoding subfield SoLSA\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+21), (int)((*Source).CMSP != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1604> Error encoding subfield CMSP\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+22), (int)((*Source).A5_3 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1605> Error encoding subfield A5_3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+23), (int)((*Source).A5_2 != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1606> Error encoding subfield A5_2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileStationClassmark2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileStationClassmark2* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1607> Error decoding subfield spare1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1607)
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
		ED_SIGNAL_ERROR ("<ERRID:1608> Error decoding subfield RevisionLevel\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1608)
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
		ED_SIGNAL_ERROR ("<ERRID:1609> Error decoding subfield EsInd\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1609)
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
		ED_SIGNAL_ERROR ("<ERRID:1610> Error decoding subfield A5_1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1610)
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
		ED_SIGNAL_ERROR ("<ERRID:1611> Error decoding subfield RFPowerCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1611)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1612> Error decoding subfield spare2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1612)
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
		ED_SIGNAL_ERROR ("<ERRID:1613> Error decoding subfield PSCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1613)
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
		ED_SIGNAL_ERROR ("<ERRID:1614> Error decoding subfield SSScreenIndicator\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1614)
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
		ED_SIGNAL_ERROR ("<ERRID:1615> Error decoding subfield SMCapability\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1615)
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
		ED_SIGNAL_ERROR ("<ERRID:1616> Error decoding subfield VBS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1616)
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
		ED_SIGNAL_ERROR ("<ERRID:1617> Error decoding subfield VGCS\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1617)
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
		ED_SIGNAL_ERROR ("<ERRID:1618> Error decoding subfield FC\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1618)
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
		ED_SIGNAL_ERROR ("<ERRID:1619> Error decoding subfield CM3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1619)
	} 
#endif
	Len += Ret;
	
	/* FromBit=17 */
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1620> Error decoding subfield spare3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1620)
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
		ED_SIGNAL_ERROR ("<ERRID:1621> Error decoding subfield LCSVA_CAP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1621)
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
		ED_SIGNAL_ERROR ("<ERRID:1622> Error decoding subfield UCS2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1622)
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
		ED_SIGNAL_ERROR ("<ERRID:1623> Error decoding subfield SoLSA\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1623)
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
		ED_SIGNAL_ERROR ("<ERRID:1624> Error decoding subfield CMSP\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1624)
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
		ED_SIGNAL_ERROR ("<ERRID:1625> Error decoding subfield A5_3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1625)
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
		ED_SIGNAL_ERROR ("<ERRID:1626> Error decoding subfield A5_2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1626)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPlmn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPlmn* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1627> Error encoding subfield MCC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MCC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1628> Error encoding subfield MCC1\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).MNC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1629> Error encoding subfield MNC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).MCC3), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1630> Error encoding subfield MCC3\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).MNC2), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1631> Error encoding subfield MNC2\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+20), (int)((*Source).MNC1), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1632> Error encoding subfield MNC1\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPlmn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPlmn* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1633> Error decoding subfield MCC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1633)
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
		ED_SIGNAL_ERROR ("<ERRID:1634> Error decoding subfield MCC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1634)
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
		ED_SIGNAL_ERROR ("<ERRID:1635> Error decoding subfield MNC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1635)
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
		ED_SIGNAL_ERROR ("<ERRID:1636> Error decoding subfield MCC3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1636)
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
		ED_SIGNAL_ERROR ("<ERRID:1637> Error decoding subfield MNC2\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1637)
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
		ED_SIGNAL_ERROR ("<ERRID:1638> Error decoding subfield MNC1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1638)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMSNetworkFeatureSupport* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1639> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).extendedPeriodicTimers != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1640> Error encoding subfield extendedPeriodicTimers\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1641> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1641)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).extendedPeriodicTimers = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).extendedPeriodicTimers___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1642> Error decoding subfield extendedPeriodicTimers\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1642)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsNetwkName (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsNetwkName* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1643> Error encoding subfield ext\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).CodingScheme), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1644> Error encoding subfield CodingScheme\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).AddCI != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1645> Error encoding subfield AddCI\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).SpareBitsInLastOctet), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1646> Error encoding subfield SpareBitsInLastOctet\n");
		return -1;
	} 
#endif
	EDCopyBits (Buffer, CurrOfs+8, (*Source).TextString.value, 0, (*Source).TextString.usedBits);
	Ret = (*Source).TextString.usedBits;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1647> Error encoding subfield TextString\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsNetwkName (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsNetwkName* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1648> Error decoding subfield ext\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1648)
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
		ED_SIGNAL_ERROR ("<ERRID:1649> Error decoding subfield CodingScheme\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1649)
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
		ED_SIGNAL_ERROR ("<ERRID:1650> Error decoding subfield AddCI\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1650)
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
		ED_SIGNAL_ERROR ("<ERRID:1651> Error decoding subfield SpareBitsInLastOctet\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1651)
	} 
#endif
	Len += Ret;
	
	/* FromBit=8 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&((*Destin).TextString___LOCATOR), CurrOfs+8, (Length - 8));
	if ((Length - 8) > 0) {
		/* BINDEC02 */
		ALLOC_c_epsNetwkName_TextString (&((*Destin).TextString), (Length - 8));
	
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
		ED_SIGNAL_ERROR ("<ERRID:1652> Error decoding subfield TextString\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1652)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTimeZoneAndTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTimeZoneAndTime* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1653> Error encoding subfield Year\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).Month), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1654> Error encoding subfield Month\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+16), (int)((*Source).Day), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1655> Error encoding subfield Day\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+24), (int)((*Source).Hour), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1656> Error encoding subfield Hour\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+32), (int)((*Source).Minute), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1657> Error encoding subfield Minute\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+40), (int)((*Source).Second), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1658> Error encoding subfield Second\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+48), (int)((*Source).TimeZone), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1659> Error encoding subfield TimeZone\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTimeZoneAndTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTimeZoneAndTime* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1660> Error decoding subfield Year\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1660)
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
		ED_SIGNAL_ERROR ("<ERRID:1661> Error decoding subfield Month\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1661)
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
		ED_SIGNAL_ERROR ("<ERRID:1662> Error decoding subfield Day\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1662)
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
		ED_SIGNAL_ERROR ("<ERRID:1663> Error decoding subfield Hour\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1663)
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
		ED_SIGNAL_ERROR ("<ERRID:1664> Error decoding subfield Minute\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1664)
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
		ED_SIGNAL_ERROR ("<ERRID:1665> Error decoding subfield Second\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1665)
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
		ED_SIGNAL_ERROR ("<ERRID:1666> Error decoding subfield TimeZone\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1666)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDaylightSavingTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDaylightSavingTime* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1667> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Value), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1668> Error encoding subfield Value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDaylightSavingTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDaylightSavingTime* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1669> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1669)
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
		ED_SIGNAL_ERROR ("<ERRID:1670> Error decoding subfield Value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1670)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsServCategory (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsServCategory* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1671> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).AutomaticallyInitiatedECall != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1672> Error encoding subfield AutomaticallyInitiatedECall\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).ManuallyInitiatedECall != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1673> Error encoding subfield ManuallyInitiatedECall\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).MountainRescue != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1674> Error encoding subfield MountainRescue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).MarineGuard != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1675> Error encoding subfield MarineGuard\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).FireBrigade != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1676> Error encoding subfield FireBrigade\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).Ambulance != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1677> Error encoding subfield Ambulance\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+7), (int)((*Source).Police != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1678> Error encoding subfield Police\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsServCategory (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsServCategory* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1679> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1679)
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
		ED_SIGNAL_ERROR ("<ERRID:1680> Error decoding subfield AutomaticallyInitiatedECall\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1680)
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
		ED_SIGNAL_ERROR ("<ERRID:1681> Error decoding subfield ManuallyInitiatedECall\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1681)
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
		ED_SIGNAL_ERROR ("<ERRID:1682> Error decoding subfield MountainRescue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1682)
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
		ED_SIGNAL_ERROR ("<ERRID:1683> Error decoding subfield MarineGuard\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1683)
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
		ED_SIGNAL_ERROR ("<ERRID:1684> Error decoding subfield FireBrigade\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1684)
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
		ED_SIGNAL_ERROR ("<ERRID:1685> Error decoding subfield Ambulance\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1685)
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
		ED_SIGNAL_ERROR ("<ERRID:1686> Error decoding subfield Police\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1686)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTmsiStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTmsiStatus* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1687> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TMSIFlag != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1688> Error encoding subfield TMSIFlag\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTmsiStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTmsiStatus* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1689> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1689)
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
		ED_SIGNAL_ERROR ("<ERRID:1690> Error decoding subfield TMSIFlag\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1690)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDrxParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDrxParam* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1691> Error encoding subfield SplitPgCycleCode\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+8), (int)((*Source).CNSpecDRX), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1692> Error encoding subfield CNSpecDRX\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+12), (int)((*Source).SplitOnCCCH != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1693> Error encoding subfield SplitOnCCCH\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+13), (int)((*Source).nonDRXTimer), 3);
	Ret = 3;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1694> Error encoding subfield nonDRXTimer\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDrxParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDrxParam* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1695> Error decoding subfield SplitPgCycleCode\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1695)
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
		ED_SIGNAL_ERROR ("<ERRID:1696> Error decoding subfield CNSpecDRX\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1696)
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
		ED_SIGNAL_ERROR ("<ERRID:1697> Error decoding subfield SplitOnCCCH\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1697)
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
		ED_SIGNAL_ERROR ("<ERRID:1698> Error decoding subfield nonDRXTimer\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1698)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsVoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1699> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+5), (int)((*Source).UEUsageSetting != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1700> Error encoding subfield UEUsageSetting\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+6), (int)((*Source).VoiceDomainPreferenceForEUTRAN), 2);
	Ret = 2;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1701> Error encoding subfield VoiceDomainPreferenceForEUTRAN\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsVoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1702> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1702)
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
		ED_SIGNAL_ERROR ("<ERRID:1703> Error decoding subfield UEUsageSetting\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1703)
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
		ED_SIGNAL_ERROR ("<ERRID:1704> Error decoding subfield VoiceDomainPreferenceForEUTRAN\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1704)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsNetworkResourceIdentifierContainer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsNetworkResourceIdentifierContainer* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1705> Error encoding subfield NRIContainerValue\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, CurrOfs+10, 0, 6);Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1706> Error encoding subfield spare\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsNetworkResourceIdentifierContainer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsNetworkResourceIdentifierContainer* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1707> Error decoding subfield NRIContainerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1707)
	} 
#endif
	Len += Ret;
	
	/* FromBit=10 */
	Ret = 6;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1708> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1708)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsExtendedDRXParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsExtendedDRXParameters* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1709> Error encoding subfield PagingTimeWindow\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).eDRX), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1710> Error encoding subfield eDRX\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsExtendedDRXParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsExtendedDRXParameters* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1711> Error decoding subfield PagingTimeWindow\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1711)
	} 
#endif
	Len += Ret;
	
	/* FromBit=4 */
	(*Destin).eDRX = (unsigned char)EDBitsToInt (Buffer, CurrOfs+4, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).eDRX___LOCATOR), CurrOfs+4, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1712> Error decoding subfield eDRX\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1712)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLlcServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLlcServAccessPointId* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1713> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+4), (int)((*Source).LLCSAPIValue), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1714> Error encoding subfield LLCSAPIValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLlcServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLlcServAccessPointId* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1715> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1715)
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
		ED_SIGNAL_ERROR ("<ERRID:1716> Error decoding subfield LLCSAPIValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1716)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPacketFlowIdentifie (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPacketFlowIdentifie* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1717> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+1), (int)((*Source).PacketFlowIdentifierValue), 7);
	Ret = 7;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1718> Error encoding subfield PacketFlowIdentifierValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPacketFlowIdentifie (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPacketFlowIdentifie* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1719> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1719)
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
		ED_SIGNAL_ERROR ("<ERRID:1720> Error decoding subfield PacketFlowIdentifierValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1720)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsConnectivityType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsConnectivityType* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 4;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).connType), 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1721> Error encoding subfield connType\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsConnectivityType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsConnectivityType* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).connType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).connType___LOCATOR), CurrOfs, 4);
	Ret = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1722> Error decoding subfield connType\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1722)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsWLANOffloadAcceptability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsWLANOffloadAcceptability* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1723> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+2), (int)((*Source).UTRAN_Offload_Acceptability_Value != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1724> Error encoding subfield UTRAN_Offload_Acceptability_Value\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).EUTRAN_Offload_Acceptability_Value != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1725> Error encoding subfield EUTRAN_Offload_Acceptability_Value\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsWLANOffloadAcceptability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsWLANOffloadAcceptability* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1726> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1726)
	} 
#endif
	Len += Ret;
	
	/* FromBit=2 */
	(*Destin).UTRAN_Offload_Acceptability_Value = (EDBitsToInt (Buffer, CurrOfs+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).UTRAN_Offload_Acceptability_Value___LOCATOR), CurrOfs+2, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1727> Error decoding subfield UTRAN_Offload_Acceptability_Value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1727)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).EUTRAN_Offload_Acceptability_Value = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).EUTRAN_Offload_Acceptability_Value___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1728> Error decoding subfield EUTRAN_Offload_Acceptability_Value\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1728)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1729> Error encoding subfield Unit\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TimerValue), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1730> Error encoding subfield TimerValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1731> Error decoding subfield Unit\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1731)
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
		ED_SIGNAL_ERROR ("<ERRID:1732> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1732)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer2* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 8;
	EDIntToBits (Buffer, (CurrOfs), (int)((*Source).TimerValue), 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1733> Error encoding subfield TimerValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer2* ED_CONST Destin, ED_EXLONG Length))
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
	(*Destin).TimerValue = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).TimerValue___LOCATOR), CurrOfs, 8);
	Ret = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1734> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1734)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer3* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1735> Error encoding subfield Unit\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).TimerValue), 5);
	Ret = 5;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1736> Error encoding subfield TimerValue\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer3* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1737> Error decoding subfield Unit\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1737)
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
		ED_SIGNAL_ERROR ("<ERRID:1738> Error decoding subfield TimerValue\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1738)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDeviceProperties (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDeviceProperties* ED_CONST Source))
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
		ED_SIGNAL_ERROR ("<ERRID:1739> Error encoding subfield spare\n");
		return -1;
	} 
#endif
	EDIntToBits (Buffer, (CurrOfs+3), (int)((*Source).lowPriority != 0 ? 1 : 0), 1);Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1740> Error encoding subfield lowPriority\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDeviceProperties (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDeviceProperties* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1741> Error decoding subfield spare\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1741)
	} 
#endif
	Len += Ret;
	
	/* FromBit=3 */
	(*Destin).lowPriority = (EDBitsToInt (Buffer, CurrOfs+3, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&((*Destin).lowPriority___LOCATOR), CurrOfs+3, 1);
	Ret = 1;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1742> Error decoding subfield lowPriority\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1742)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsCalledPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsCalledPartyBcdNum* ED_CONST Source))
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
	Ret = ENCODE_c_epsTBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1743> Error encoding remainder of epsCalledPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1743)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsCalledPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsCalledPartyBcdNum* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1744> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1744)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:1745> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1745)
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
	Ret = DECODE_c_epsTBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1748> Error decoding remainder of epsCalledPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1748)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsCallingPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsCallingPartyBcdNum* ED_CONST Source))
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
	Ret = ENCODE_c_epsTBCDArray (Buffer, CurrOfs, (&((*Source).Number)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1749> Error encoding remainder of epsCallingPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1749)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsCallingPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsCallingPartyBcdNum* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1750> Error decoding 0/1ext IE: missing mandatory group 3\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1750)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:1751> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1751)
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
		ED_SIGNAL_ERROR ("<ERRID:1754> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1754)
	}
	(*Destin).PresentationIndicator = (unsigned char)EDBitsToInt (Buffer, (CurrOfs)+1, 2);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&((*Destin).PresentationIndicator___LOCATOR), (CurrOfs)+1, 2);
	ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_epsCallingPartyBcdNum_PresentationIndicator (&((*Destin)), ED_TRUE), != ED_NO_ERRORS)
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
	Ret = DECODE_c_epsTBCDArray (Buffer, CurrOfs, (&((*Destin).Number)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1758> Error decoding remainder of epsCallingPartyBcdNum\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1758)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfgOpt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfgOpt* ED_CONST Source))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	{
	Len = 0;
	
	/* GROUP LEADER 1 OPT=0 */
	EDIntToBits (Buffer, CurrOfs, 1, 1);
	EDIntToBits (Buffer, (CurrOfs)+1, 0, 4);
	EDIntToBits (Buffer, ((CurrOfs)+5), (int)((*Source).ConfigurationProtocol), 3);
	
	CurrOfs += 8;
	
	/* ProtocolCfgs REMAINDER */
	Ret = ENCODE_c_epsProtocolCfgList (Buffer, CurrOfs, (&((*Source).ProtocolCfgs)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1759> Error encoding remainder of epsProtocolCfgOpt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1759)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfgOpt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfgOpt* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG Len = 0, Ret = 0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	{
	
	/* GROUP LEADER 1 OPT=0 */
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:1760> Error decoding 0/1ext IE: missing mandatory group 1\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1760)
	}
	if (CurrOfs >= Length+BitOffset) {
		ED_SIGNAL_ERROR ("<ERRID:1761> Error decoding 0/1ext IE: information element too short\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1761)
	}
	/* spare octet <1> <4>-<7> */
	(*Destin).ConfigurationProtocol = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs)+5), 3);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&((*Destin).ConfigurationProtocol___LOCATOR), (CurrOfs)+5, 3);
	/* ConfigurationProtocol octet <1> <1>-<3> */
	/* Unexpected extensions may follow: skip them */
	while (EDBitsToInt (Buffer, CurrOfs, 1) == 0 && CurrOfs < (BitOffset+Length)) CurrOfs += 8;
	CurrOfs += 8;
	
	/* ProtocolCfgs REMAINDER */
	Ret = DECODE_c_epsProtocolCfgList (Buffer, CurrOfs, (&((*Destin).ProtocolCfgs)), (Length+BitOffset - CurrOfs));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Ret < 0) {
		ED_SIGNAL_ERROR ("<ERRID:1764> Error decoding remainder of epsProtocolCfgOpt\n");
		ED_HANDLE_IE_SYNTAX_ERROR (1764)
	} 
#endif

	return CurrOfs-BitOffset+Ret;
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_TACS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_TACS* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		EDIntToBits (Buffer, (CurrOfs), (int)(Source->data[i]), 16);
		length = 16;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1765> Error encoding sequence PartialTrackingAreaIdentityList_TACS\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_TACS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_TACS* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<16) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_PartialTrackingAreaIdentityList_TACS (Destin, i+1)
, != ED_NO_ERRORS)


		Destin->data[i] = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(Destin->data___LOCATOR[i]), CurrOfs, 16);
		ret = 16;

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1766> Error decoding sequence PartialTrackingAreaIdentityList_TACS\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1766)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type2* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_PartialTrackingAreaIdentity_Type2 (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1767> Error encoding sequence PartialTrackingAreaIdentityList_Type2\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type2* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<8) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_PartialTrackingAreaIdentityList_Type2 (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_PartialTrackingAreaIdentity_Type2 (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1768> Error decoding sequence PartialTrackingAreaIdentityList_Type2\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1768)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_TrackingAreaIdentityList_Item (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1769> Error encoding sequence PartialTrackingAreaIdentityList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<16) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_PartialTrackingAreaIdentityList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_TrackingAreaIdentityList_Item (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1770> Error decoding sequence PartialTrackingAreaIdentityList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1770)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPlmnList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPlmnList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_epsPlmn (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1771> Error encoding sequence epsPlmnList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPlmnList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPlmnList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<5) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_epsPlmnList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_epsPlmn (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1772> Error decoding sequence epsPlmnList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1772)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsEmergencyNumberList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsEmergencyNumberList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_epsTBCDEmergencyNumber (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1773> Error encoding sequence epsEmergencyNumberList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsEmergencyNumberList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsEmergencyNumberList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<6) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_epsEmergencyNumberList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_epsTBCDEmergencyNumber (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1774> Error decoding sequence epsEmergencyNumberList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1774)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsSupportedCodecList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsSupportedCodecList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_epsSupportedCodec (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1775> Error encoding sequence epsSupportedCodecList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsSupportedCodecList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsSupportedCodecList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<6) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_epsSupportedCodecList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_epsSupportedCodec (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1776> Error decoding sequence epsSupportedCodecList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1776)
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
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfgList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfgList* ED_CONST Source))
{
	int i;
	ED_EXLONG length = 0, ret=0;
	ED_EXLONG CurrOfs = BitOffset;
	for (i=0; i<(*Source).items; i++) {

		length = ENCODE_c_epsProtocolCfg (Buffer, CurrOfs, Source->data[i]);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (length < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1777> Error encoding sequence epsProtocolCfgList\n");
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfgList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfgList* ED_CONST Destin, ED_EXLONG Length))
{
	int i;
	ED_EXLONG ret=0, len=0;
	ED_EXLONG CurrOfs = BitOffset;
	Destin->items = 0;
	for (i=0; (i<12) && (Length>0); i++) {
ED_CHECK_OUT_OF_MEMORY_KEEP(		SETITEMS_c_epsProtocolCfgList (Destin, i+1)
, != ED_NO_ERRORS)


		ret = DECODE_c_epsProtocolCfg (Buffer, CurrOfs, Destin->data[i], Length);

#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (ret < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1778> Error decoding sequence epsProtocolCfgList\n");
			ED_HANDLE_IE_SYNTAX_ERROR (1778)
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity_IMSI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity_IMSI* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i;

  	/* Push digit 1 */
 		PUSH_INT (Source->IdentityDigit.items == 0? 15 : Source->IdentityDigit.data [0], 4);

 		/* Push odd/even indicator */
  	PUSH_INT ((Source->IdentityDigit.items & 1) ? 1 : 0, 1);

  	/* Push identity type */
  	PUSH_INT (1 /* 1=IMSI */, 3);

  	/* Push remaining digits */
  	for (i=1; i<Source->IdentityDigit.items; i+=2) {
  		PUSH_INT (i+1 >= Source->IdentityDigit.items? 15 : Source->IdentityDigit.data [i+1], 4);
  		PUSH_INT (Source->IdentityDigit.data [i], 4);
  	}
		return ((Source->IdentityDigit.items >> 1) << 3) + 8;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity_IMSI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity_IMSI* ED_CONST Destin, ED_EXLONG Length))
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
  	SETITEMS_c_EPSMobileIdentity_IMSI_IdentityDigit (&Destin->IdentityDigit, (Length >> 2) - (odd ? 1 : 2));

  	/* Now we know whether digit 1 is valid or not */
  	if (Destin->IdentityDigit.items > 0) Destin->IdentityDigit.data [0] = i;

		/* Skip identity type */
		SHIFT_INT (3);

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
		return Length;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	if (GETPRESENT_c_EPSMobileIdentity_IMSI (Source)) {
  		return ENCODE_c_EPSMobileIdentity_IMSI (Buffer, BitOffset, PTR_c_EPSMobileIdentity_IMSI (Source->u.IMSI));
  	}
  	else if (GETPRESENT_c_EPSMobileIdentity_GUTI (Source)) {
  		return ENCODE_c_EPSMobileIdentity_GUTI (Buffer, BitOffset, PTR_c_EPSMobileIdentity_GUTI (Source->u.GUTI));
  	} else {
  		return 0;
  	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	if (EDBitsToInt (Buffer, CURPOS+5, 3) == 6) {
	  	SETPRESENT_c_EPSMobileIdentity_GUTI (Destin);
	 		return DECODE_c_EPSMobileIdentity_GUTI (Buffer, BitOffset, PTR_c_EPSMobileIdentity_GUTI (Destin->u.GUTI), Length);
  	} else {
	  	SETPRESENT_c_EPSMobileIdentity_IMSI (Destin);
	 		return DECODE_c_EPSMobileIdentity_IMSI (Buffer, BitOffset, PTR_c_EPSMobileIdentity_IMSI (Destin->u.IMSI), Length);
	 	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESMMessageUp (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESMMessageUp* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	switch (GETPRESENT_c_ESMMessageUp (Source)) {
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT: return ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT));
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT: return ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT));
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT: return ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT));
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT: return ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT));
		case U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST: return ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pBEARER_RESOURCE_ALLOCATION_REQUEST));
		case U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST: return ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pBEARER_RESOURCE_MODIFICATION_REQUEST));
		case U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT: return ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Source->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT));
		case U_c_ESMMessageUp_pESM_DATA_TRANSPORT: return ENCODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, ED_AMP(Source->u.pESM_DATA_TRANSPORT));
		case U_c_ESMMessageUp_pESM_DUMMY_MESSAGE: return ENCODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, ED_AMP(Source->u.pESM_DUMMY_MESSAGE));
		case U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE: return ENCODE_c_ESM_INFORMATION_RESPONSE (Buffer, BitOffset, ED_AMP(Source->u.pESM_INFORMATION_RESPONSE));
		case U_c_ESMMessageUp_pESM_STATUS: return ENCODE_c_ESM_STATUS (Buffer, BitOffset, ED_AMP(Source->u.pESM_STATUS));
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT: return ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Source->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT));
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT: return ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT));
		case U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST: return ENCODE_c_PDN_CONNECTIVITY_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pPDN_CONNECTIVITY_REQUEST));
		case U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST: return ENCODE_c_PDN_DISCONNECT_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pPDN_DISCONNECT_REQUEST));
		case U_c_ESMMessageUp_pREMOTE_UE_REPORT: return ENCODE_c_REMOTE_UE_REPORT (Buffer, BitOffset, ED_AMP(Source->u.pREMOTE_UE_REPORT));
 		default:;
  	}
		return 0;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESMMessageUp (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESMMessageUp* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	unsigned char messageType;
  	/* MessageType is third octet. See 8.3.2 */
  	if (Length < 24) return 0;

		messageType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+16, 8);
		switch (messageType) {
			case 198: {
				SETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Destin);
				return DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT), Length);
			}
			case 199: {
				SETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Destin);
				return DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT), Length);
			}
			case 194: {
				SETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Destin);
				return DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT), Length);
			}
			case 195: {
				SETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Destin);
				return DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT), Length);
			}
			case 212: {
				SETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST (Destin);
				return DECODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pBEARER_RESOURCE_ALLOCATION_REQUEST), Length);
			}
			case 214: {
				SETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST (Destin);
				return DECODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pBEARER_RESOURCE_MODIFICATION_REQUEST), Length);
			}
			case 206: {
				SETPRESENT_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Destin);
				return DECODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Destin->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT), Length);
			}
			case 235: {
				SETPRESENT_c_ESMMessageUp_pESM_DATA_TRANSPORT (Destin);
				return DECODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, ED_AMP(Destin->u.pESM_DATA_TRANSPORT), Length);
			}
			case 220: {
				SETPRESENT_c_ESMMessageUp_pESM_DUMMY_MESSAGE (Destin);
				return DECODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, ED_AMP(Destin->u.pESM_DUMMY_MESSAGE), Length);
			}
			case 218: {
				SETPRESENT_c_ESMMessageUp_pESM_INFORMATION_RESPONSE (Destin);
				return DECODE_c_ESM_INFORMATION_RESPONSE (Buffer, BitOffset, ED_AMP(Destin->u.pESM_INFORMATION_RESPONSE), Length);
			}
			case 232: {
				SETPRESENT_c_ESMMessageUp_pESM_STATUS (Destin);
				return DECODE_c_ESM_STATUS (Buffer, BitOffset, ED_AMP(Destin->u.pESM_STATUS), Length);
			}
			case 202: {
				SETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT (Destin);
				return DECODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, ED_AMP(Destin->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT), Length);
			}
			case 203: {
				SETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT (Destin);
				return DECODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT), Length);
			}
			case 208: {
				SETPRESENT_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST (Destin);
				return DECODE_c_PDN_CONNECTIVITY_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pPDN_CONNECTIVITY_REQUEST), Length);
			}
			case 210: {
				SETPRESENT_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST (Destin);
				return DECODE_c_PDN_DISCONNECT_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pPDN_DISCONNECT_REQUEST), Length);
			}
			case 233: {
				SETPRESENT_c_ESMMessageUp_pREMOTE_UE_REPORT (Destin);
				return DECODE_c_REMOTE_UE_REPORT (Buffer, BitOffset, ED_AMP(Destin->u.pREMOTE_UE_REPORT), Length);
			}
		}
		return 0;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESMMessageDn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESMMessageDn* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	switch (GETPRESENT_c_ESMMessageDn (Source)) {
		case U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST: return ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST));
		case U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST: return ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST));
		case U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT: return ENCODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pBEARER_RESOURCE_ALLOCATION_REJECT));
		case U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT: return ENCODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pBEARER_RESOURCE_MODIFICATION_REJECT));
		case U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST: return ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST));
		case U_c_ESMMessageDn_pEPS_NOTIFICATION: return ENCODE_c_EPS_NOTIFICATION (Buffer, BitOffset, ED_AMP(Source->u.pEPS_NOTIFICATION));
		case U_c_ESMMessageDn_pESM_DATA_TRANSPORT: return ENCODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, ED_AMP(Source->u.pESM_DATA_TRANSPORT));
		case U_c_ESMMessageDn_pESM_DUMMY_MESSAGE: return ENCODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, ED_AMP(Source->u.pESM_DUMMY_MESSAGE));
		case U_c_ESMMessageDn_pESM_INFORMATION_REQUEST: return ENCODE_c_ESM_INFORMATION_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pESM_INFORMATION_REQUEST));
		case U_c_ESMMessageDn_pESM_STATUS: return ENCODE_c_ESM_STATUS (Buffer, BitOffset, ED_AMP(Source->u.pESM_STATUS));
		case U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST: return ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Source->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST));
		case U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT: return ENCODE_c_PDN_CONNECTIVITY_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pPDN_CONNECTIVITY_REJECT));
		case U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT: return ENCODE_c_PDN_DISCONNECT_REJECT (Buffer, BitOffset, ED_AMP(Source->u.pPDN_DISCONNECT_REJECT));
		case U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE: return ENCODE_c_REMOTE_UE_REPORT_RESPONSE (Buffer, BitOffset, ED_AMP(Source->u.pREMOTE_UE_REPORT_RESPONSE));
 		default:;
  	}
		return 0;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESMMessageDn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESMMessageDn* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	unsigned char messageType;
  	/* MessageType is third octet. See 8.3.2 */
  	if (Length < 24) return 0;

		messageType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+16, 8);
		switch (messageType) {
			case 197: {
				SETPRESENT_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Destin);
				return DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST), Length);
			}
			case 193: {
				SETPRESENT_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Destin);
				return DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST), Length);
			}
			case 213: {
				SETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT (Destin);
				return DECODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pBEARER_RESOURCE_ALLOCATION_REJECT), Length);
			}
			case 215: {
				SETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT (Destin);
				return DECODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pBEARER_RESOURCE_MODIFICATION_REJECT), Length);
			}
			case 205: {
				SETPRESENT_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Destin);
				return DECODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST), Length);
			}
			case 219: {
				SETPRESENT_c_ESMMessageDn_pEPS_NOTIFICATION (Destin);
				return DECODE_c_EPS_NOTIFICATION (Buffer, BitOffset, ED_AMP(Destin->u.pEPS_NOTIFICATION), Length);
			}
			case 235: {
				SETPRESENT_c_ESMMessageDn_pESM_DATA_TRANSPORT (Destin);
				return DECODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, ED_AMP(Destin->u.pESM_DATA_TRANSPORT), Length);
			}
			case 220: {
				SETPRESENT_c_ESMMessageDn_pESM_DUMMY_MESSAGE (Destin);
				return DECODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, ED_AMP(Destin->u.pESM_DUMMY_MESSAGE), Length);
			}
			case 217: {
				SETPRESENT_c_ESMMessageDn_pESM_INFORMATION_REQUEST (Destin);
				return DECODE_c_ESM_INFORMATION_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pESM_INFORMATION_REQUEST), Length);
			}
			case 232: {
				SETPRESENT_c_ESMMessageDn_pESM_STATUS (Destin);
				return DECODE_c_ESM_STATUS (Buffer, BitOffset, ED_AMP(Destin->u.pESM_STATUS), Length);
			}
			case 201: {
				SETPRESENT_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST (Destin);
				return DECODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, ED_AMP(Destin->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST), Length);
			}
			case 209: {
				SETPRESENT_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT (Destin);
				return DECODE_c_PDN_CONNECTIVITY_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pPDN_CONNECTIVITY_REJECT), Length);
			}
			case 211: {
				SETPRESENT_c_ESMMessageDn_pPDN_DISCONNECT_REJECT (Destin);
				return DECODE_c_PDN_DISCONNECT_REJECT (Buffer, BitOffset, ED_AMP(Destin->u.pPDN_DISCONNECT_REJECT), Length);
			}
			case 234: {
				SETPRESENT_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE (Destin);
				return DECODE_c_REMOTE_UE_REPORT_RESPONSE (Buffer, BitOffset, ED_AMP(Destin->u.pREMOTE_UE_REPORT_RESPONSE), Length);
			}
		}
		return 0;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrackingAreaIdentityList_Item (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrackingAreaIdentityList_Item* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int Items;
  	if (GETPRESENT_c_TrackingAreaIdentityList_Item_Type0 (Source)) {
  		Items = PTR_c_TrackingAreaIdentityList_Item_Type0 (Source->u.Type0)->TAC.items;
  		PUSH_INT (0, 3);
  		PUSH_INT (Items-1, 5);
  		return ENCODE_c_PartialTrackingAreaIdentityList_Type0 (Buffer, BitOffset+8, PTR_c_TrackingAreaIdentityList_Item_Type0 (Source->u.Type0))+8;
  	}
  	else if (GETPRESENT_c_TrackingAreaIdentityList_Item_Type1 (Source)) {
  		return ENCODE_c_PartialTrackingAreaIdentityList_Type1 (Buffer, BitOffset, PTR_c_TrackingAreaIdentityList_Item_Type1 (Source->u.Type1));
  	}
  	else if (GETPRESENT_c_TrackingAreaIdentityList_Item_Type2 (Source)) {
  		Items = PTR_c_TrackingAreaIdentityList_Item_Type2 (Source->u.Type2)->items;
  		PUSH_INT (2, 3);
  		PUSH_INT (Items-1, 5);
  		return ENCODE_c_PartialTrackingAreaIdentityList_Type2 (Buffer, BitOffset+8, PTR_c_TrackingAreaIdentityList_Item_Type2 (Source->u.Type2))+8;
  	} else {
  		return 0;
  	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrackingAreaIdentityList_Item (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrackingAreaIdentityList_Item* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int ListType, Items;

  	ListType = EDBitsToInt (Buffer, CURPOS+1, 2);
  	Items = EDBitsToInt (Buffer, CURPOS+4, 4)+1;

  	switch (ListType) {
  		case 0: {
  			SETPRESENT_c_TrackingAreaIdentityList_Item_Type0 (Destin);
  			return DECODE_c_PartialTrackingAreaIdentityList_Type0 (Buffer, BitOffset+8, PTR_c_TrackingAreaIdentityList_Item_Type0 (Destin->u.Type0), (3 + Items * 2)*8)+8;
  		}

  		case 1: {
  			SETPRESENT_c_TrackingAreaIdentityList_Item_Type1 (Destin);
  			return DECODE_c_PartialTrackingAreaIdentityList_Type1 (Buffer, BitOffset, PTR_c_TrackingAreaIdentityList_Item_Type1 (Destin->u.Type1), 48);
  		}

  		case 2: {
  			SETPRESENT_c_TrackingAreaIdentityList_Item_Type2 (Destin);
  			return DECODE_c_PartialTrackingAreaIdentityList_Type2 (Buffer, BitOffset+8, PTR_c_TrackingAreaIdentityList_Item_Type2 (Destin->u.Type2), Items * 40)+8;
  		}

  		default: return ED_SYNTAX_ERROR;
  	}

  	return 0;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext_Identity* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i;

		/* Push the length */
		PUSH_INT ((Source->IdentityDigit.items >> 1) + 1, 8);

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
		return ((Source->IdentityDigit.items >> 1) << 3) + 16;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext_Identity* ED_CONST Destin, ED_EXLONG Length))
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

		/* Shift the length */
		Length = SHIFT_INT (8) * 8;

  	/* Shift digit 1 (we don't know yet whether it is valid or not) */
  	i = SHIFT_INT (4);

  	/* Shift odd indicator */
  	odd = SHIFT_INT (1);

		/* Now we know exactly how many items to expect */
  	SETITEMS_c_RemoteUEContext_Identity_IdentityDigit (&Destin->IdentityDigit, (Length >> 2) - (odd ? 1 : 2));

  	/* Now we know whether digit 1 is valid or not */
  	if (Destin->IdentityDigit.items > 0) Destin->IdentityDigit.data [0] = i;

		/* Read identity type */
		Destin->IdentityType = SHIFT_INT (3);

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
		return Length + 8;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext_SingleContext (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext_SingleContext* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i, ret, lengthPosition;

		/* Skip the length position; it will be encoded at the end */
		lengthPosition = CurrOfs;
		CurrOfs += 8;

		/* Encode the number of items */
		PUSH_INT (Source->UserIDs.items, 8);

  	/* Push the various contests */
  	for (i=0; i<Source->UserIDs.items; i++) {
  		ret = ENCODE_c_RemoteUEContext_Identity (Buffer, CurrOfs, PTR_c_RemoteUEContext_SingleContext_UserIDs_data(Source->UserIDs.data [i]));
  		if (ret < 0) return ret;
  		CurrOfs += ret;
  	}
  	
  	/* Write back the length */
  	EDIntToBits (Buffer, lengthPosition, (CurrOfs-lengthPosition-8)/8, 8);

		return CurrOfs - BitOffset;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext_SingleContext (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext_SingleContext* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i, lastOffs, noOfEntries, ret;
  	int len = SHIFT_INT(8) * 8;
  	if (len+8 > Length) return ED_MESSAGE_TOO_SHORT;
  	lastOffs = CurrOfs + len;
  	
  	noOfEntries = SHIFT_INT(8);
  	SETITEMS_c_RemoteUEContext_SingleContext_UserIDs (&Destin->UserIDs, noOfEntries);
  	
  	for (i=0; i<noOfEntries; i++) {
  		ret = DECODE_c_RemoteUEContext_Identity (Buffer, CurrOfs, PTR_c_RemoteUEContext_SingleContext_UserIDs_data(Destin->UserIDs.data [i]), lastOffs-CurrOfs);
  		if (ret < 0) return ret;
  		CurrOfs += ret;
  		if (CurrOfs > lastOffs) return ED_MESSAGE_TOO_SHORT;
  	}
  	
  
		return CurrOfs-BitOffset;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i, ret;

		/* Encode the number of items */
		PUSH_INT (Source->Contexts.items, 8);

  	/* Push the various contests */
  	for (i=0; i<Source->Contexts.items; i++) {
  		ret = ENCODE_c_RemoteUEContext_SingleContext (Buffer, CurrOfs, PTR_c_RemoteUEContext_Contexts_data(Source->Contexts.data [i]));
  		if (ret < 0) return ret;
  		CurrOfs += ret;
  	}
  	
		return CurrOfs - BitOffset;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	int i, lastOffs, noOfEntries, ret;
  	lastOffs = CurrOfs + Length;
  	
  	noOfEntries = SHIFT_INT(8);
  	SETITEMS_c_RemoteUEContext_Contexts (&Destin->Contexts, noOfEntries);
  	
  	for (i=0; i<noOfEntries; i++) {
  		ret = DECODE_c_RemoteUEContext_SingleContext (Buffer, CurrOfs, PTR_c_RemoteUEContext_Contexts_data(Destin->Contexts.data [i]), lastOffs-CurrOfs);
  		if (ret < 0) return ret;
  		CurrOfs += ret;
  		if (CurrOfs > lastOffs) return ED_MESSAGE_TOO_SHORT;
  	}
  	
  
		return Length;
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId_Identity* ED_CONST Source))
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId_Identity* ED_CONST Destin, ED_EXLONG Length))
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
  	SETITEMS_c_epsMobileId_Identity_IdentityDigit (&Destin->IdentityDigit, (Length >> 2) - (odd ? 1 : 2));

  	/* Now we know whether digit 1 is valid or not */
  	if (Destin->IdentityDigit.items > 0) Destin->IdentityDigit.data [0] = i;

		/* Extract identity type */
		Destin->IdentityType = SHIFT_INT (3);
	
		/* If decoding a TMSI/P-TMSI, just get the following bytes */
		if (Destin->IdentityType == 4) {
			SETITEMS_c_epsMobileId_Identity_IdentityDigit (&(Destin->IdentityDigit), (Length>>3) - 1);
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

  	if (GETPRESENT_c_epsMobileId_Identity (Source)) {
  		return ENCODE_c_epsMobileId_Identity (Buffer, BitOffset, PTR_c_epsMobileId_Identity (Source->u.Identity));
  	}
  	else if (GETPRESENT_c_epsMobileId_TMGI (Source)) {
  		return ENCODE_c_epsMobileId_TMGI (Buffer, BitOffset, PTR_c_epsMobileId_TMGI (Source->u.TMGI));
  	} else {
  		return 0;
  	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId* ED_CONST Destin, ED_EXLONG Length))
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
	  	SETPRESENT_c_epsMobileId_TMGI (Destin);
	 		return DECODE_c_epsMobileId_TMGI (Buffer, BitOffset, PTR_c_epsMobileId_TMGI (Destin->u.TMGI), Length);
  	} else {
	  	SETPRESENT_c_epsMobileId_Identity (Destin);
	 		return DECODE_c_epsMobileId_Identity (Buffer, BitOffset, PTR_c_epsMobileId_Identity (Destin->u.Identity), Length);
	 	}
  
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTBCDEmergencyNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTBCDEmergencyNumber* ED_CONST Source))
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
  	Ret = ENCODE_c_epsServCategory (Buffer, CurrOfs, &(Source->ServiceCategory));
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTBCDEmergencyNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTBCDEmergencyNumber* ED_CONST Destin, ED_EXLONG Length))
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
  	Ret = DECODE_c_epsServCategory (Buffer, CurrOfs, &(Destin->ServiceCategory), 8);
  	if (Ret < 0) return Ret;
  	CurrOfs += Ret;
  	
  	/* Convert IELength from octets to bits */
  	IELength = (IELength - 1) * 8;
  	
  	/* Calculate the number of expected nibbles */
  	nibbles = IELength >> 2;
  	
  	/* Find out too see whether items are odd or even */
  	odd = (EDBitsToInt (Buffer, CURPOS+IELength-8, 4) == 15);
  	
  	SETITEMS_c_epsTBCDEmergencyNumber_Numbers (&(Destin->Numbers), (odd? nibbles-1 : nibbles));
  	
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTBCDArray (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTBCDArray* ED_CONST Source))
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTBCDArray (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTBCDArray* ED_CONST Destin, ED_EXLONG Length))
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
  	SETITEMS_c_epsTBCDArray (Destin, (odd? nibbles-1 : nibbles));
  	
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsSupportedCodec (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsSupportedCodec* ED_CONST Source))
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsSupportedCodec (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsSupportedCodec* ED_CONST Destin, ED_EXLONG Length))
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
		ALLOC_c_epsSupportedCodec_CodecBitmap (&(Destin->CodecBitmap), SHIFT_INT (8) << 3);
		SHIFT_BIN (Destin->CodecBitmap.value, Destin->CodecBitmap.usedBits);
		return Destin->CodecBitmap.usedBits + 16;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfg (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfg* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(Source);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		PUSH_INT (Source->ProtocolId, 16);
		PUSH_INT (Source->Contents.usedBits >> 3, 8);
		PUSH_BIN (Source->Contents.value, Source->Contents.usedBits);
		return Source->Contents.usedBits + 24;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfg (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfg* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER(CurrOfs);
	ED_WARNING_REMOVER(Length);
	ED_WARNING_REMOVER(Destin);
	ED_WARNING_REMOVER(Buffer);
	ED_WARNING_REMOVER(BitOffset);
	ED_EXTRAPARAMS_CODE
	
	{

		Destin->ProtocolId = SHIFT_INT (16);
		ALLOC_c_epsProtocolCfg_Contents (&(Destin->Contents), SHIFT_INT (8) << 3);
		SHIFT_BIN (Destin->Contents.value, Destin->Contents.usedBits);
		return Destin->Contents.usedBits + 24;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLinkedTi (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLinkedTi* ED_CONST Source))
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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLinkedTi (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLinkedTi* ED_CONST Destin, ED_EXLONG Length))
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTrafficFlowTemplate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTrafficFlowTemplate* ED_CONST Source))
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
						PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterDirection, 2);
						PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterId, 4);
						ret += 8;
						break;
					case 1: /* Create new TFT */
					case 3: /* Add packet filters to existing TFT */
					case 4: /* Replace packet filters in existing */
						contentsSizeInBits = 0;
						for (j=0; j<VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.items; j++) {
							contentsSizeInBits += 8 + VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits;
						}
					
						PUSH_INT (0, 2);
						PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterDirection, 2);
						PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterId, 4);
						PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).PacketFilterEvalPrecedence, 8);
						PUSH_INT (contentsSizeInBits/8, 8);
						for (j=0; j<VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.items; j++) {
							PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentTypeId, 8);
							PUSH_BIN (VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.value, VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Source->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits);
						}
						ret += 24 + contentsSizeInBits;
						break;
				}
			}
		}
		for (i=0; i<Source->PacketParameters.items; i++) {
			PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).ParameterId, 8);
			PUSH_INT (VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits >> 3, 8);
			PUSH_BIN (VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.value, VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits);
			ret += 16 + VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Source->PacketParameters.data [i]).Contents.usedBits;
		}
		return ret;
	
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTrafficFlowTemplate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTrafficFlowTemplate* ED_CONST Destin, ED_EXLONG Length))
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
		SETITEMS_c_epsTrafficFlowTemplate_PacketFilters (&(Destin->PacketFilters), SHIFT_INT (4));
		for (i=0; i<Destin->PacketFilters.items; i++) {
			switch (Destin->TFTOperationCode) {
				case 5: /* Delete packet filters from existing TFT */
					SHIFT_INT (2);
					VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterDirection = (ED_OCTET)SHIFT_INT (2);
					VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterId = (ED_OCTET)SHIFT_INT (4);
					ret += 8;
					break;
				case 1: /* Create new TFT */
				case 3: /* Add packet filters to existing TFT */
				case 4: /* Replace packet filters in existing */
					SHIFT_INT (2);
					VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterDirection = (ED_OCTET)SHIFT_INT (2);
					VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterId = (ED_OCTET)SHIFT_INT (4);
					VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).PacketFilterEvalPrecedence = SHIFT_INT (8);
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
							ADDITEMS_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (PTR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents), 1);
							VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentTypeId = (ED_OCTET)componentId;
							ALLOC_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData (
								&(VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentData)
							, contentBits);

							SHIFT_BIN (
								VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData (
									VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (
										VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j])).ComponentData.value
							, contentBits);
							VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (VAR_c_epsTrafficFlowTemplate_PacketFilters_data (Destin->PacketFilters.data [i]).FilterContents.data [j]).ComponentData.usedBits = contentBits;
							j++;
						}
						remainingContentSizeInBits -= (8 + contentBits);
					}
					
					ret += 24 + contentSizeInBits;
					break;
			}
		}
		SETITEMS_c_epsTrafficFlowTemplate_PacketParameters (&(Destin->PacketParameters), 0);
		if (Ebit) {
			i = 0;
			while (ret < Length) {
				ADDITEMS_c_epsTrafficFlowTemplate_PacketParameters (&(Destin->PacketParameters), 1);
				Destin->PacketParameters.items++;
				VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).ParameterId = SHIFT_INT (8);
				ALLOC_c_epsTrafficFlowTemplate_PacketParameters_data_Contents (&(VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents), (SHIFT_INT (8) << 3));
				SHIFT_BIN (VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.value, VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.usedBits);
				ret += 16 + VAR_c_epsTrafficFlowTemplate_PacketParameters_data (Destin->PacketParameters.data [i]).Contents.usedBits;
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
/* IEEE 802.16 GENERIC TLV ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_EPS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_EPS* ED_CONST Source))
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_EPS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_EPS* ED_CONST Destin, ED_EXLONG Length))
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
		ALLOC_c_GenericTLV_EPS_TLV_Data (&(Destin->TLV_Data), DataLength);

		
		/* Save the bits in the binary data */
		EDCopyBits (Destin->TLV_Data.value, 0, Buffer, CurrOfs, DataLength);
		CurrOfs += (ED_EXLONG)EffectiveDataLength;
	}
	
	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
