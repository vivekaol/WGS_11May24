/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "csn1clib.h"
#include "CSN1DataTypes_EPS.h"
#include "ed_c_known_ie_EPS.h"
#include "ed_tlv.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef CURPOS
#undef CURPOS
#endif
#define CURPOS (Context->CurrOfs)

#ifdef BUFFER
#undef BUFFER
#endif
#define BUFFER ((unsigned char*)(Context->Buffer))

#ifdef CSN1_BACKTRACK
#undef CSN1_BACKTRACK
#endif
#define CSN1_BACKTRACK CSN1C_Backtrack(Context)

#ifdef PUSH_TAG
#undef PUSH_TAG
#endif
#define PUSH_TAG(Tag,Value) CSN1C_PushValue (Context, Tag, Value)

#ifdef EXISTS_TAG
#undef EXISTS_TAG
#endif
#define EXISTS_TAG(Tag) CSN1C_ExistsValue (Context, Tag)

#ifdef POP_TAGS
#undef POP_TAGS
#endif
#define POP_TAGS(Tag) CSN1C_PopValues (Context, Tag)

#ifdef TAG
#undef TAG
#endif
#define TAG(Tag) CSN1C_GetValue (Context, Tag)

#ifdef TAGZ
#undef TAGZ
#endif
#define TAGZ(Tag) CSN1C_GetValueOrZero (Context, Tag)

#ifdef SET_TAG
#undef SET_TAG
#endif
#define SET_TAG(Tag,Value) CSN1C_SetValue (Context, Tag, Value)


/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_UENetworkCapability (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_UENetworkCapability
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_UENetworkCapability* Source = (const c_UENetworkCapability*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'p128_EEA0' */
			case 25: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA1' */
			case 26: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA2' */
			case 27: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA3' */
			case 28: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA4' */
			case 29: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA5' */
			case 30: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA6' */
			case 31: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA7' */
			case 32: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA0' */
			case 33: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA1' */
			case 34: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA2' */
			case 35: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA3' */
			case 36: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA4' */
			case 37: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA5' */
			case 38: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA6' */
			case 39: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA7' */
			case 40: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'octet_5' */
			case 41: {
				/* The field 'octet_5' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UENetworkCapability_octet_5 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UEA0' */
			case 45: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA1' */
			case 46: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA2' */
			case 47: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA3' */
			case 48: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA4' */
			case 49: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA5' */
			case 50: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA6' */
			case 51: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA7' */
			case 52: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_5->UEA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'octet_6' */
			case 42: {
				/* The field 'octet_6' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UENetworkCapability_octet_6 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UCS2' */
			case 53: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UCS2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA1' */
			case 54: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA2' */
			case 55: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA3' */
			case 56: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA4' */
			case 57: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA5' */
			case 58: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA6' */
			case 59: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA7' */
			case 60: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_6->UIA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'octet_7' */
			case 43: {
				/* The field 'octet_7' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UENetworkCapability_octet_7 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'H245_ASH' */
			case 61: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->H245_ASH != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ACC_CSFB' */
			case 62: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->ACC_CSFB != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'LPP' */
			case 63: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->LPP != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'LCS' */
			case 64: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->LCS != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p1xSR_VCC' */
			case 65: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->p1xSR_VCC != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ISR' */
			case 66: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_7->ISR != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'octet_8' */
			case 44: {
				/* The field 'octet_8' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UENetworkCapability_octet_8 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'ePCO' */
			case 67: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->ePCO != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'HC_CP_CIoT' */
			case 68: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->HC_CP_CIoT != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ERw_oPDN' */
			case 69: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->ERw_oPDN != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'S1_U_data' */
			case 70: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->S1_U_data != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UP_CIoT' */
			case 71: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->UP_CIoT != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CP_CIoT' */
			case 72: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->CP_CIoT != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Prose_relay' */
			case 73: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->Prose_relay != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ProSe_dc' */
			case 74: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->octet_8->ProSe_dc != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_UESecurityCapability (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_UESecurityCapability
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_UESecurityCapability* Source = (const c_UESecurityCapability*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'p128_EEA0' */
			case 75: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA1' */
			case 76: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA2' */
			case 77: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EEA3' */
			case 78: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EEA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA4' */
			case 79: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA5' */
			case 80: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA6' */
			case 81: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EEA7' */
			case 82: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EEA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA0' */
			case 83: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA1' */
			case 84: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA2' */
			case 85: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'p128_EIA3' */
			case 86: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->p128_EIA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA4' */
			case 87: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA5' */
			case 88: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA6' */
			case 89: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EIA7' */
			case 90: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EIA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA_UIA' */
			case 91: {
				/* The field 'UEA_UIA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UESecurityCapability_UEA_UIA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UEA0' */
			case 93: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA0 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA1' */
			case 94: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA2' */
			case 95: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA3' */
			case 96: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA4' */
			case 97: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA5' */
			case 98: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA6' */
			case 99: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UEA7' */
			case 100: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UEA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA1' */
			case 101: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA2' */
			case 102: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA3' */
			case 103: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA4' */
			case 104: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA5' */
			case 105: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA6' */
			case 106: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UIA7' */
			case 107: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UEA_UIA->UIA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA' */
			case 92: {
				/* The field 'GEA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_UESecurityCapability_GEA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'GEA1' */
			case 108: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA2' */
			case 109: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA3' */
			case 110: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA4' */
			case 111: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA5' */
			case 112: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA6' */
			case 113: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA7' */
			case 114: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA->GEA7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_APNAggregateMaxBitRate (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_APNAggregateMaxBitRate
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_APNAggregateMaxBitRate* Source = (const c_APNAggregateMaxBitRate*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'APN_AMBRDownlink' */
			case 115: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->APN_AMBRDownlink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'APN_AMBRUplink' */
			case 116: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->APN_AMBRUplink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'ext' */
			case 117: {
				/* The field 'ext' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_APNAggregateMaxBitRate_ext (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'APN_AMBRDownlinkExt' */
			case 119: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext->APN_AMBRDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'APN_AMBRUplinkExt' */
			case 120: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext->APN_AMBRUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'ext2' */
			case 118: {
				/* The field 'ext2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_APNAggregateMaxBitRate_ext2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'APN_AMBRDownlinkExt2' */
			case 121: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2->APN_AMBRDownlinkExt2), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'APN_AMBRUplinkExt2' */
			case 122: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2->APN_AMBRUplinkExt2), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_EPS_QOS (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EPS_QOS
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EPS_QOS* Source = (const c_EPS_QOS*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'QCI' */
			case 123: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->QCI), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'basic' */
			case 124: {
				/* The field 'basic' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EPS_QOS_basic (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForUplink' */
			case 127: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->basic->MaximumBitRateForUplink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'MaximumBitRateForDownlink' */
			case 128: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->basic->MaximumBitRateForDownlink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForUplink' */
			case 129: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->basic->GuaranteedBitRateForUplink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlink' */
			case 130: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->basic->GuaranteedBitRateForDownlink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'extended' */
			case 125: {
				/* The field 'extended' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EPS_QOS_extended (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForUplinkExt' */
			case 131: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended->MaximumBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'MaximumBitRateForDownlinkExt' */
			case 132: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended->MaximumBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForUplinkExt' */
			case 133: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended->GuaranteedBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlinkExt' */
			case 134: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended->GuaranteedBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'extended2' */
			case 126: {
				/* The field 'extended2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EPS_QOS_extended2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForUplinkExt' */
			case 135: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended2->MaximumBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'MaximumBitRateForDownlinkExt' */
			case 136: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended2->MaximumBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForUplinkExt' */
			case 137: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended2->GuaranteedBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlinkExt' */
			case 138: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->extended2->GuaranteedBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_epsClassmark3Value (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_epsClassmark3Value
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_epsClassmark3Value* Source = (const c_epsClassmark3Value*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'Multiband_supported' */
			case 139: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Multiband_supported), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'A5_7' */
			case 140: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_6' */
			case 141: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_5' */
			case 142: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_4' */
			case 143: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Associated_Radio_Capability_2' */
			case 144: {
				/* The field 'Associated_Radio_Capability_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Associated_Radio_Capability_2), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Associated_Radio_Capability_1' */
			case 145: {
				/* The field 'Associated_Radio_Capability_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Associated_Radio_Capability_1), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'R_GSM_band_Associated_Radio_Capability' */
			case 146: {
				/* The field 'R_GSM_band_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->R_GSM_band_Associated_Radio_Capability), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'HSCSD_Multi_Slot_Class' */
			case 147: {
				/* The field 'HSCSD_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_HSCSD_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->HSCSD_Multi_Slot_Class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'UCS2_treatment' */
			case 148: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UCS2_treatment != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_Measurement_Capability' */
			case 149: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_Measurement_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SMS_VALUE' */
			case 150: {
				/* The field 'SMS_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_SMS_VALUE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SMS_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'SM_VALUE' */
			case 151: {
				/* The field 'SM_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_SM_VALUE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'MS_Positioning_Method' */
			case 152: {
				/* The field 'MS_Positioning_Method' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_MS_Positioning_Method (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_Positioning_Method), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'ECSD_Multi_Slot_Class' */
			case 153: {
				/* The field 'ECSD_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_ECSD_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ECSD_Multi_Slot_Class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'Modulation_Capability' */
			case 154: {
				/* The field 'Modulation_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Modulation_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Modulation_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field '_8_PSK_RF_Power_Capability_1' */
			case 155: {
				/* The field '_8_PSK_RF_Power_Capability_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_RF_Power_Capability_1), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8_PSK_RF_Power_Capability_2' */
			case 156: {
				/* The field '_8_PSK_RF_Power_Capability_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_RF_Power_Capability_2), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_400_Bands_Supported' */
			case 157: {
				/* The field 'GSM_400_Bands_Supported' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_400_Bands_Supported (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_400_Bands_Supported), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_400_Associated_Radio_Capability' */
			case 158: {
				/* The field 'GSM_400_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_400_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_850_Associated_Radio_Capability' */
			case 159: {
				/* The field 'GSM_850_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_850_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_1900_Associated_Radio_Capability' */
			case 160: {
				/* The field 'GSM_1900_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_1900_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'UMTS_FDD_Radio_Access_Technology_Capability' */
			case 161: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_FDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 162: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CDMA_2000_Radio_Access_Technology_Capability' */
			case 163: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CDMA_2000_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_Multi_Slot_Class' */
			case 164: {
				/* The field 'DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Single_Slot_DTM' */
			case 165: {
				/* The field 'Single_Slot_DTM' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Single_Slot_DTM (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Single_Slot_DTM != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_EGPRS_Multi_Slot_Class' */
			case 166: {
				/* The field 'DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_Band' */
			case 167: {
				/* The field 'GSM_Band' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_Band (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_Band), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_750_Associated_Radio_Capability' */
			case 168: {
				/* The field 'GSM_750_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_750_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 169: {
				/* The field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Feature_Package_1' */
			case 170: {
				/* The field 'GERAN_Feature_Package_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Feature_Package_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_DTM_GPRS_Multi_Slot_Class' */
			case 171: {
				/* The field 'Extended_DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Extended_DTM_EGPRS_Multi_Slot_Class' */
			case 172: {
				/* The field 'Extended_DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'High_Multislot_Capability' */
			case 173: {
				/* The field 'High_Multislot_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_High_Multislot_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->High_Multislot_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Length' */
			case 174: {
				/* The field 'Length' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Length (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Length), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'FLO_Iu_Capability' */
			case 175: {
				/* The field 'FLO_Iu_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_FLO_Iu_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->FLO_Iu_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Feature_Package_2' */
			case 176: {
				/* The field 'GERAN_Feature_Package_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Feature_Package_2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GMSK_Multislot_Power_Profile' */
			case 177: {
				/* The field 'GMSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GMSK_Multislot_Power_Profile (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GMSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8_PSK_Multislot_Power_Profile' */
			case 178: {
				/* The field '_8_PSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'T_GSM_400_Bands_Supported' */
			case 179: {
				/* The field 'T_GSM_400_Bands_Supported' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_T_GSM_400_Bands_Supported (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_400_Bands_Supported), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'T_GSM_400_Associated_Radio_Capability' */
			case 180: {
				/* The field 'T_GSM_400_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_400_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'T_GSM_900_Associated_Radio_Capability' */
			case 181: {
				/* The field 'T_GSM_900_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_900_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Downlink_Advanced_Receiver_Performance' */
			case 182: {
				/* The field 'Downlink_Advanced_Receiver_Performance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Downlink_Advanced_Receiver_Performance), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DTM_Enhancements_Capability' */
			case 183: {
				/* The field 'DTM_Enhancements_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_DTM_Enhancements_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_Enhancements_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_High_Multi_Slot_Class' */
			case 184: {
				/* The field 'DTM_GPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_GPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Offset_required' */
			case 185: {
				/* The field 'Offset_required' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Offset_required (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Offset_required != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_EGPRS_High_Multi_Slot_Class' */
			case 186: {
				/* The field 'DTM_EGPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_EGPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Repeated_ACCH_Capability' */
			case 187: {
				/* The field 'Repeated_ACCH_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Repeated_ACCH_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Repeated_ACCH_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GSM_710_Associated_Radio_Capability' */
			case 188: {
				/* The field 'GSM_710_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_710_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'T_GSM_810_Associated_Radio_Capability' */
			case 189: {
				/* The field 'T_GSM_810_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_810_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Ciphering_Mode_Setting_Capability' */
			case 190: {
				/* The field 'Ciphering_Mode_Setting_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Ciphering_Mode_Setting_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Additional_Positioning_Capabilities' */
			case 191: {
				/* The field 'Additional_Positioning_Capabilities' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Additional_Positioning_Capabilities (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Additional_Positioning_Capabilities != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_FDD_support' */
			case 192: {
				/* The field 'E_UTRA_FDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_E_UTRA_FDD_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_FDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_TDD_support' */
			case 193: {
				/* The field 'E_UTRA_TDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_E_UTRA_TDD_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_TDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Measurement_and_Reporting_support' */
			case 194: {
				/* The field 'E_UTRA_Measurement_and_Reporting_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Measurement_and_Reporting_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Priority_based_reselection_support' */
			case 195: {
				/* The field 'Priority_based_reselection_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Priority_based_reselection_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Priority_based_reselection_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_CSG_Cells_Reporting' */
			case 196: {
				/* The field 'UTRA_CSG_Cells_Reporting' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UTRA_CSG_Cells_Reporting != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'VAMOS_Level' */
			case 197: {
				/* The field 'VAMOS_Level' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_VAMOS_Level (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->VAMOS_Level), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'TIGHTER_Capability' */
			case 198: {
				/* The field 'TIGHTER_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_TIGHTER_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TIGHTER_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Selective_Ciphering_of_Downlink_SACCH' */
			case 199: {
				/* The field 'Selective_Ciphering_of_Downlink_SACCH' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Selective_Ciphering_of_Downlink_SACCH != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' */
			case 200: {
				/* The field 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CS_to_PS_SRVCC_from_GERAN_to_UTRA), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' */
			case 201: {
				/* The field 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GERAN_Network_Sharing_support' */
			case 202: {
				/* The field 'GERAN_Network_Sharing_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_GERAN_Network_Sharing_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Network_Sharing_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Wideband_RSRQ_measurements_support' */
			case 203: {
				/* The field 'E_UTRA_Wideband_RSRQ_measurements_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Wideband_RSRQ_measurements_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ER_Band_Support' */
			case 204: {
				/* The field 'ER_Band_Support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_ER_Band_Support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ER_Band_Support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 205: {
				/* The field 'UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 206: {
				/* The field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_TSC_Set_Capability_support' */
			case 207: {
				/* The field 'Extended_TSC_Set_Capability_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Extended_TSC_Set_Capability_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_TSC_Set_Capability_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_EARFCN_value_range' */
			case 208: {
				/* The field 'Extended_EARFCN_value_range' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsClassmark3Value_Extended_EARFCN_value_range (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_EARFCN_value_range != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_epsMsNetwkCpblty (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_epsMsNetwkCpblty
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_epsMsNetwkCpblty* Source = (const c_epsMsNetwkCpblty*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'GEA_1' */
			case 225: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SM_capabilities_via_dedicated_channels' */
			case 226: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_capabilities_via_dedicated_channels != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SM_capabilities_via_GPRS_channels' */
			case 227: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_capabilities_via_GPRS_channels != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UCS2_support' */
			case 228: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UCS2_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SS_Screening_Indicator' */
			case 229: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SS_Screening_Indicator), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'SoLSA_Capability' */
			case 230: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SoLSA_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Revision_level_indicator' */
			case 231: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Revision_level_indicator != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PFC_feature_mode' */
			case 232: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PFC_feature_mode != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_2' */
			case 233: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_3' */
			case 234: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_4' */
			case 235: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_5' */
			case 236: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_6' */
			case 237: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_7' */
			case 238: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'LCS_VA_capability' */
			case 239: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->LCS_VA_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' */
			case 240: {
				/* The field 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' */
			case 241: {
				/* The field 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EMM_Combined_procedures_Capability' */
			case 242: {
				/* The field 'EMM_Combined_procedures_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EMM_Combined_procedures_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ISR_support' */
			case 243: {
				/* The field 'ISR_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_ISR_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ISR_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SRVCC_to_GERAN_UTRAN_capability' */
			case 244: {
				/* The field 'SRVCC_to_GERAN_UTRAN_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SRVCC_to_GERAN_UTRAN_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EPC_capability' */
			case 245: {
				/* The field 'EPC_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_EPC_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EPC_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'NF_capability' */
			case 246: {
				/* The field 'NF_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_NF_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->NF_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_network_sharing_capability' */
			case 247: {
				/* The field 'GERAN_network_sharing_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_GERAN_network_sharing_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_network_sharing_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'User_plane_integrity_protection_support' */
			case 248: {
				/* The field 'User_plane_integrity_protection_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_User_plane_integrity_protection_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->User_plane_integrity_protection_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_4' */
			case 249: {
				/* The field 'GIA_4' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_GIA_4 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_5' */
			case 250: {
				/* The field 'GIA_5' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_GIA_5 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_6' */
			case 251: {
				/* The field 'GIA_6' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_GIA_6 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_7' */
			case 252: {
				/* The field 'GIA_7' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsMsNetwkCpblty_GIA_7 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
/*----------------------------------------------------------------------------
	Callback function used to encode Encodix ADTs
----------------------------------------------------------------------------*/
int XENCODE_DATA_c_epsQualityOfServ (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_epsQualityOfServ
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_epsQualityOfServ* Source = (const c_epsQualityOfServ*)(FieldCallbackParam->Context->Data);
	const TCSN1CFieldElement* Field;
	ED_EXTRAPARAMS_CODE
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Field);
	
	/* No fields detected? There is nothing we can do! */
	if (FieldCallbackParam->Context->FieldState.FieldsTop <= 0) {
		ED_ASSERT_FORCE_FAIL
		return CSN1C_CB_FAIL;
	}
	
	Field = &(FieldCallbackParam->Context->Fields[FieldCallbackParam->Context->FieldState.FieldsTop-1]);
	
	if (Field->Index >= 0) {
		switch (Field->FieldId) {
			/* Field 'DelayClass' */
			case 260: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DelayClass), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'ReliabilityClass' */
			case 261: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ReliabilityClass), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'PeakThroughput' */
			case 262: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PeakThroughput), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'PrecedenceClass' */
			case 263: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PrecedenceClass), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'MeanThroughput' */
			case 264: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MeanThroughput), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'TrafficClass' */
			case 265: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TrafficClass), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'DeliveryOrder' */
			case 266: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DeliveryOrder), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DeliveryOfErroneusSDU' */
			case 267: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DeliveryOfErroneusSDU), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'MaximumSDUSize' */
			case 268: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MaximumSDUSize), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'MaximumBitRateForUplink' */
			case 269: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MaximumBitRateForUplink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'MaximumBitRateForDownlink' */
			case 270: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MaximumBitRateForDownlink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'ResidualBER' */
			case 271: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ResidualBER), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'SDUErrorRatio' */
			case 272: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SDUErrorRatio), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'TransderDelay' */
			case 273: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TransderDelay), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'TrafficHandlingPriority' */
			case 274: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TrafficHandlingPriority), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GuaranteedBitRateForUplink' */
			case 275: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GuaranteedBitRateForUplink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlink' */
			case 276: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GuaranteedBitRateForDownlink), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'SignalingIndication' */
			case 277: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SignalingIndication != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SourceStatisticsDescriptor' */
			case 278: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SourceStatisticsDescriptor), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'downlink' */
			case 279: {
				/* The field 'downlink' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsQualityOfServ_downlink (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForDownlinkExt' */
			case 283: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->downlink->MaximumBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlinkExt' */
			case 284: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->downlink->GuaranteedBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'uplink' */
			case 280: {
				/* The field 'uplink' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsQualityOfServ_uplink (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForUplinkExt' */
			case 285: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->uplink->MaximumBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForUplinkExt' */
			case 286: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->uplink->GuaranteedBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'ext2downlink' */
			case 281: {
				/* The field 'ext2downlink' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsQualityOfServ_ext2downlink (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForDownlinkExt' */
			case 287: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2downlink->MaximumBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForDownlinkExt' */
			case 288: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2downlink->GuaranteedBitRateForDownlinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'ext2uplink' */
			case 282: {
				/* The field 'ext2uplink' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_epsQualityOfServ_ext2uplink (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'MaximumBitRateForUplinkExt' */
			case 289: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2uplink->MaximumBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'GuaranteedBitRateForUplinkExt' */
			case 290: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ext2uplink->GuaranteedBitRateForUplinkExt), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			default:;
		}
	}
	return Ret;
#else
ED_ASSERT_FORCE_FAIL
return ED_SYNTAX_ERROR;
#endif
}
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UENetworkCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UENetworkCapability* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_UENetworkCapability
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 1381, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 1;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_UENetworkCapability ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UENetworkCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UENetworkCapability* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_UENetworkCapability
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 1381, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 1;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 25 /* p128_EEA0 */: {
					Destin->p128_EEA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 26 /* p128_EEA1 */: {
					Destin->p128_EEA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 27 /* p128_EEA2 */: {
					Destin->p128_EEA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 28 /* p128_EEA3 */: {
					Destin->p128_EEA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 29 /* EEA4 */: {
					Destin->EEA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 30 /* EEA5 */: {
					Destin->EEA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 31 /* EEA6 */: {
					Destin->EEA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 32 /* EEA7 */: {
					Destin->EEA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 33 /* EIA0 */: {
					Destin->EIA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 34 /* p128_EIA1 */: {
					Destin->p128_EIA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 35 /* p128_EIA2 */: {
					Destin->p128_EIA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 36 /* p128_EIA3 */: {
					Destin->p128_EIA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 37 /* EIA4 */: {
					Destin->EIA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 38 /* EIA5 */: {
					Destin->EIA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 39 /* EIA6 */: {
					Destin->EIA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 40 /* EIA7 */: {
					Destin->EIA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 41: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UENetworkCapability_octet_5 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 45 /* UEA0 */: {
					Destin->octet_5->UEA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 46 /* UEA1 */: {
					Destin->octet_5->UEA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 47 /* UEA2 */: {
					Destin->octet_5->UEA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 48 /* UEA3 */: {
					Destin->octet_5->UEA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 49 /* UEA4 */: {
					Destin->octet_5->UEA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 50 /* UEA5 */: {
					Destin->octet_5->UEA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 51 /* UEA6 */: {
					Destin->octet_5->UEA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 52 /* UEA7 */: {
					Destin->octet_5->UEA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_5->UEA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 42: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UENetworkCapability_octet_6 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 53 /* UCS2 */: {
					Destin->octet_6->UCS2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UCS2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 54 /* UIA1 */: {
					Destin->octet_6->UIA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 55 /* UIA2 */: {
					Destin->octet_6->UIA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 56 /* UIA3 */: {
					Destin->octet_6->UIA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 57 /* UIA4 */: {
					Destin->octet_6->UIA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 58 /* UIA5 */: {
					Destin->octet_6->UIA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 59 /* UIA6 */: {
					Destin->octet_6->UIA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 60 /* UIA7 */: {
					Destin->octet_6->UIA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_6->UIA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 43: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UENetworkCapability_octet_7 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 61 /* H245_ASH */: {
					Destin->octet_7->H245_ASH = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->H245_ASH___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 62 /* ACC_CSFB */: {
					Destin->octet_7->ACC_CSFB = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->ACC_CSFB___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 63 /* LPP */: {
					Destin->octet_7->LPP = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->LPP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 64 /* LCS */: {
					Destin->octet_7->LCS = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->LCS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 65 /* p1xSR_VCC */: {
					Destin->octet_7->p1xSR_VCC = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->p1xSR_VCC___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 66 /* ISR */: {
					Destin->octet_7->ISR = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_7->ISR___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 44: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UENetworkCapability_octet_8 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 67 /* ePCO */: {
					Destin->octet_8->ePCO = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->ePCO___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 68 /* HC_CP_CIoT */: {
					Destin->octet_8->HC_CP_CIoT = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->HC_CP_CIoT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 69 /* ERw_oPDN */: {
					Destin->octet_8->ERw_oPDN = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->ERw_oPDN___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 70 /* S1_U_data */: {
					Destin->octet_8->S1_U_data = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->S1_U_data___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 71 /* UP_CIoT */: {
					Destin->octet_8->UP_CIoT = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->UP_CIoT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 72 /* CP_CIoT */: {
					Destin->octet_8->CP_CIoT = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->CP_CIoT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 73 /* Prose_relay */: {
					Destin->octet_8->Prose_relay = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->Prose_relay___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 74 /* ProSe_dc */: {
					Destin->octet_8->ProSe_dc = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->octet_8->ProSe_dc___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UESecurityCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UESecurityCapability* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_UESecurityCapability
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 19, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 2;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_UESecurityCapability ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UESecurityCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UESecurityCapability* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_UESecurityCapability
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 19, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 2;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 75 /* p128_EEA0 */: {
					Destin->p128_EEA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 76 /* p128_EEA1 */: {
					Destin->p128_EEA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 77 /* p128_EEA2 */: {
					Destin->p128_EEA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 78 /* p128_EEA3 */: {
					Destin->p128_EEA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EEA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 79 /* EEA4 */: {
					Destin->EEA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 80 /* EEA5 */: {
					Destin->EEA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 81 /* EEA6 */: {
					Destin->EEA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 82 /* EEA7 */: {
					Destin->EEA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EEA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 83 /* p128_EIA0 */: {
					Destin->p128_EIA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 84 /* p128_EIA1 */: {
					Destin->p128_EIA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 85 /* p128_EIA2 */: {
					Destin->p128_EIA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 86 /* p128_EIA3 */: {
					Destin->p128_EIA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->p128_EIA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 87 /* EIA4 */: {
					Destin->EIA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 88 /* EIA5 */: {
					Destin->EIA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 89 /* EIA6 */: {
					Destin->EIA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 90 /* EIA7 */: {
					Destin->EIA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EIA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 91: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UESecurityCapability_UEA_UIA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 93 /* UEA0 */: {
					Destin->UEA_UIA->UEA0 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 94 /* UEA1 */: {
					Destin->UEA_UIA->UEA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 95 /* UEA2 */: {
					Destin->UEA_UIA->UEA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 96 /* UEA3 */: {
					Destin->UEA_UIA->UEA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 97 /* UEA4 */: {
					Destin->UEA_UIA->UEA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 98 /* UEA5 */: {
					Destin->UEA_UIA->UEA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 99 /* UEA6 */: {
					Destin->UEA_UIA->UEA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 100 /* UEA7 */: {
					Destin->UEA_UIA->UEA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UEA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 101 /* UIA1 */: {
					Destin->UEA_UIA->UIA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 102 /* UIA2 */: {
					Destin->UEA_UIA->UIA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 103 /* UIA3 */: {
					Destin->UEA_UIA->UIA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 104 /* UIA4 */: {
					Destin->UEA_UIA->UIA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 105 /* UIA5 */: {
					Destin->UEA_UIA->UIA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 106 /* UIA6 */: {
					Destin->UEA_UIA->UIA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 107 /* UIA7 */: {
					Destin->UEA_UIA->UIA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UEA_UIA->UIA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 92: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_UESecurityCapability_GEA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 108 /* GEA1 */: {
					Destin->GEA->GEA1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 109 /* GEA2 */: {
					Destin->GEA->GEA2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 110 /* GEA3 */: {
					Destin->GEA->GEA3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 111 /* GEA4 */: {
					Destin->GEA->GEA4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 112 /* GEA5 */: {
					Destin->GEA->GEA5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 113 /* GEA6 */: {
					Destin->GEA->GEA6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 114 /* GEA7 */: {
					Destin->GEA->GEA7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA->GEA7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_APNAggregateMaxBitRate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_APNAggregateMaxBitRate* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_APNAggregateMaxBitRate
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 150, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 3;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_APNAggregateMaxBitRate ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_APNAggregateMaxBitRate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_APNAggregateMaxBitRate* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_APNAggregateMaxBitRate
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 150, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 3;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 115 /* APN_AMBRDownlink */: {
					Destin->APN_AMBRDownlink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->APN_AMBRDownlink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 116 /* APN_AMBRUplink */: {
					Destin->APN_AMBRUplink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->APN_AMBRUplink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 117: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_APNAggregateMaxBitRate_ext (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 119 /* APN_AMBRDownlinkExt */: {
					Destin->ext->APN_AMBRDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext->APN_AMBRDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 120 /* APN_AMBRUplinkExt */: {
					Destin->ext->APN_AMBRUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext->APN_AMBRUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 118: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_APNAggregateMaxBitRate_ext2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 121 /* APN_AMBRDownlinkExt2 */: {
					Destin->ext2->APN_AMBRDownlinkExt2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2->APN_AMBRDownlinkExt2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 122 /* APN_AMBRUplinkExt2 */: {
					Destin->ext2->APN_AMBRUplinkExt2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2->APN_AMBRUplinkExt2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_QOS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_QOS* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EPS_QOS
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 189, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 4;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EPS_QOS ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_QOS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_QOS* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EPS_QOS
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 189, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 4;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 123 /* QCI */: {
					Destin->QCI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->QCI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 124: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EPS_QOS_basic (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 127 /* MaximumBitRateForUplink */: {
					Destin->basic->MaximumBitRateForUplink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->basic->MaximumBitRateForUplink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 128 /* MaximumBitRateForDownlink */: {
					Destin->basic->MaximumBitRateForDownlink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->basic->MaximumBitRateForDownlink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 129 /* GuaranteedBitRateForUplink */: {
					Destin->basic->GuaranteedBitRateForUplink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->basic->GuaranteedBitRateForUplink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 130 /* GuaranteedBitRateForDownlink */: {
					Destin->basic->GuaranteedBitRateForDownlink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->basic->GuaranteedBitRateForDownlink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 125: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EPS_QOS_extended (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 131 /* MaximumBitRateForUplinkExt */: {
					Destin->extended->MaximumBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended->MaximumBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 132 /* MaximumBitRateForDownlinkExt */: {
					Destin->extended->MaximumBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended->MaximumBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 133 /* GuaranteedBitRateForUplinkExt */: {
					Destin->extended->GuaranteedBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended->GuaranteedBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 134 /* GuaranteedBitRateForDownlinkExt */: {
					Destin->extended->GuaranteedBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended->GuaranteedBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 126: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EPS_QOS_extended2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 135 /* MaximumBitRateForUplinkExt */: {
					Destin->extended2->MaximumBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended2->MaximumBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 136 /* MaximumBitRateForDownlinkExt */: {
					Destin->extended2->MaximumBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended2->MaximumBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 137 /* GuaranteedBitRateForUplinkExt */: {
					Destin->extended2->GuaranteedBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended2->GuaranteedBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 138 /* GuaranteedBitRateForDownlinkExt */: {
					Destin->extended2->GuaranteedBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->extended2->GuaranteedBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsClassmark3Value (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsClassmark3Value* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_epsClassmark3Value
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 457, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 5;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_epsClassmark3Value ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsClassmark3Value (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsClassmark3Value* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_epsClassmark3Value
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 457, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 5;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 139 /* Multiband_supported */: {
					Destin->Multiband_supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Multiband_supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 140 /* A5_7 */: {
					Destin->A5_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 141 /* A5_6 */: {
					Destin->A5_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 142 /* A5_5 */: {
					Destin->A5_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 143 /* A5_4 */: {
					Destin->A5_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 144 /* Associated_Radio_Capability_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Associated_Radio_Capability_2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Associated_Radio_Capability_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 145 /* Associated_Radio_Capability_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Associated_Radio_Capability_1 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Associated_Radio_Capability_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 146 /* R_GSM_band_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->R_GSM_band_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->R_GSM_band_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 147 /* HSCSD_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_HSCSD_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->HSCSD_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->HSCSD_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 148 /* UCS2_treatment */: {
					Destin->UCS2_treatment = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UCS2_treatment___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 149 /* Extended_Measurement_Capability */: {
					Destin->Extended_Measurement_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_Measurement_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 150 /* SMS_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_SMS_VALUE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SMS_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SMS_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 151 /* SM_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_SM_VALUE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SM_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 152 /* MS_Positioning_Method */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_MS_Positioning_Method (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_Positioning_Method = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_Positioning_Method___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 153 /* ECSD_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_ECSD_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ECSD_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ECSD_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 154 /* Modulation_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Modulation_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Modulation_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Modulation_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 155 /* _8_PSK_RF_Power_Capability_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_RF_Power_Capability_1 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_RF_Power_Capability_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 156 /* _8_PSK_RF_Power_Capability_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_RF_Power_Capability_2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_RF_Power_Capability_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 157 /* GSM_400_Bands_Supported */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_400_Bands_Supported (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_400_Bands_Supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_400_Bands_Supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 158 /* GSM_400_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_400_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_400_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 159 /* GSM_850_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_850_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_850_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 160 /* GSM_1900_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_1900_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_1900_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 161 /* UMTS_FDD_Radio_Access_Technology_Capability */: {
					Destin->UMTS_FDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_FDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 162 /* UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */: {
					Destin->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 163 /* CDMA_2000_Radio_Access_Technology_Capability */: {
					Destin->CDMA_2000_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CDMA_2000_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 164 /* DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 165 /* Single_Slot_DTM */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Single_Slot_DTM (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Single_Slot_DTM = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Single_Slot_DTM___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 166 /* DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 167 /* GSM_Band */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_Band (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_Band = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_Band___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 168 /* GSM_750_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_750_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_750_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 169 /* UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 170 /* GERAN_Feature_Package_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Feature_Package_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Feature_Package_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 171 /* Extended_DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 172 /* Extended_DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 173 /* High_Multislot_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_High_Multislot_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->High_Multislot_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->High_Multislot_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 174 /* Length */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Length (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 175 /* FLO_Iu_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_FLO_Iu_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->FLO_Iu_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->FLO_Iu_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 176 /* GERAN_Feature_Package_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Feature_Package_2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Feature_Package_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 177 /* GMSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GMSK_Multislot_Power_Profile (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GMSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GMSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 178 /* _8_PSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 179 /* T_GSM_400_Bands_Supported */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_T_GSM_400_Bands_Supported (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_400_Bands_Supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_400_Bands_Supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 180 /* T_GSM_400_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_400_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_400_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 181 /* T_GSM_900_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_900_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_900_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 182 /* Downlink_Advanced_Receiver_Performance */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Downlink_Advanced_Receiver_Performance = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Downlink_Advanced_Receiver_Performance___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 183 /* DTM_Enhancements_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_DTM_Enhancements_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_Enhancements_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_Enhancements_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 184 /* DTM_GPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_GPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_GPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 185 /* Offset_required */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Offset_required (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Offset_required = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Offset_required___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 186 /* DTM_EGPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_EGPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_EGPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 187 /* Repeated_ACCH_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Repeated_ACCH_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Repeated_ACCH_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Repeated_ACCH_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 188 /* GSM_710_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_710_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_710_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 189 /* T_GSM_810_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_810_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_810_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 190 /* Ciphering_Mode_Setting_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Ciphering_Mode_Setting_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Ciphering_Mode_Setting_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 191 /* Additional_Positioning_Capabilities */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Additional_Positioning_Capabilities (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Additional_Positioning_Capabilities = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Positioning_Capabilities___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 192 /* E_UTRA_FDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_E_UTRA_FDD_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_FDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_FDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 193 /* E_UTRA_TDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_E_UTRA_TDD_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_TDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_TDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 194 /* E_UTRA_Measurement_and_Reporting_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Measurement_and_Reporting_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Measurement_and_Reporting_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 195 /* Priority_based_reselection_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Priority_based_reselection_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Priority_based_reselection_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Priority_based_reselection_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 196 /* UTRA_CSG_Cells_Reporting */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UTRA_CSG_Cells_Reporting = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UTRA_CSG_Cells_Reporting___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 197 /* VAMOS_Level */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_VAMOS_Level (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->VAMOS_Level = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->VAMOS_Level___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 198 /* TIGHTER_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_TIGHTER_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TIGHTER_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TIGHTER_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 199 /* Selective_Ciphering_of_Downlink_SACCH */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Selective_Ciphering_of_Downlink_SACCH = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Selective_Ciphering_of_Downlink_SACCH___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 200 /* CS_to_PS_SRVCC_from_GERAN_to_UTRA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CS_to_PS_SRVCC_from_GERAN_to_UTRA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CS_to_PS_SRVCC_from_GERAN_to_UTRA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 201 /* CS_to_PS_SRVCC_from_GERAN_to_E_UTRA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 202 /* GERAN_Network_Sharing_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_GERAN_Network_Sharing_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Network_Sharing_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Network_Sharing_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 203 /* E_UTRA_Wideband_RSRQ_measurements_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Wideband_RSRQ_measurements_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Wideband_RSRQ_measurements_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 204 /* ER_Band_Support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_ER_Band_Support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ER_Band_Support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ER_Band_Support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 205 /* UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 206 /* E_UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 207 /* Extended_TSC_Set_Capability_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Extended_TSC_Set_Capability_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_TSC_Set_Capability_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_TSC_Set_Capability_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 208 /* Extended_EARFCN_value_range */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsClassmark3Value_Extended_EARFCN_value_range (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_EARFCN_value_range = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_EARFCN_value_range___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMsNetwkCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMsNetwkCpblty* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_epsMsNetwkCpblty
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 1250, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 15;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_epsMsNetwkCpblty ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMsNetwkCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMsNetwkCpblty* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_epsMsNetwkCpblty
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 1250, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 15;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 225 /* GEA_1 */: {
					Destin->GEA_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 226 /* SM_capabilities_via_dedicated_channels */: {
					Destin->SM_capabilities_via_dedicated_channels = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_capabilities_via_dedicated_channels___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 227 /* SM_capabilities_via_GPRS_channels */: {
					Destin->SM_capabilities_via_GPRS_channels = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_capabilities_via_GPRS_channels___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 228 /* UCS2_support */: {
					Destin->UCS2_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UCS2_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 229 /* SS_Screening_Indicator */: {
					Destin->SS_Screening_Indicator = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SS_Screening_Indicator___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 230 /* SoLSA_Capability */: {
					Destin->SoLSA_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SoLSA_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 231 /* Revision_level_indicator */: {
					Destin->Revision_level_indicator = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Revision_level_indicator___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 232 /* PFC_feature_mode */: {
					Destin->PFC_feature_mode = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PFC_feature_mode___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 233 /* GEA_2 */: {
					Destin->GEA_2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 234 /* GEA_3 */: {
					Destin->GEA_3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 235 /* GEA_4 */: {
					Destin->GEA_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 236 /* GEA_5 */: {
					Destin->GEA_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 237 /* GEA_6 */: {
					Destin->GEA_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 238 /* GEA_7 */: {
					Destin->GEA_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 239 /* LCS_VA_capability */: {
					Destin->LCS_VA_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->LCS_VA_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 240 /* PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 241 /* PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 242 /* EMM_Combined_procedures_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EMM_Combined_procedures_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EMM_Combined_procedures_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 243 /* ISR_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_ISR_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ISR_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ISR_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 244 /* SRVCC_to_GERAN_UTRAN_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SRVCC_to_GERAN_UTRAN_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SRVCC_to_GERAN_UTRAN_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 245 /* EPC_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_EPC_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EPC_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EPC_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 246 /* NF_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_NF_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->NF_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->NF_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 247 /* GERAN_network_sharing_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_GERAN_network_sharing_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_network_sharing_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_network_sharing_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 248 /* User_plane_integrity_protection_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_User_plane_integrity_protection_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->User_plane_integrity_protection_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->User_plane_integrity_protection_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 249 /* GIA_4 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_GIA_4 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 250 /* GIA_5 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_GIA_5 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 251 /* GIA_6 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_GIA_6 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 252 /* GIA_7 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsMsNetwkCpblty_GIA_7 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsQualityOfServ (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsQualityOfServ* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_epsQualityOfServ
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 282, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 18;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_epsQualityOfServ ED_EXTRAPARAMS_CALL);

	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsQualityOfServ (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsQualityOfServ* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_epsQualityOfServ
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EPS_Program, 282, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 18;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Destin;
	
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_DECODE
#endif

	/* Run the decoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, NULL ED_EXTRAPARAMS_CALL);

	for (i=0; i<CSN1C_CONTEXT_PTR->FieldState.FieldsTop; i++) {
		if (CSN1C_CONTEXT_PTR->Fields[i].Index >= 0) {
			switch (CSN1C_CONTEXT_PTR->Fields[i].FieldId) {
				case 260 /* DelayClass */: {
					Destin->DelayClass = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DelayClass___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 261 /* ReliabilityClass */: {
					Destin->ReliabilityClass = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ReliabilityClass___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 262 /* PeakThroughput */: {
					Destin->PeakThroughput = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PeakThroughput___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 263 /* PrecedenceClass */: {
					Destin->PrecedenceClass = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PrecedenceClass___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 264 /* MeanThroughput */: {
					Destin->MeanThroughput = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MeanThroughput___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 265 /* TrafficClass */: {
					Destin->TrafficClass = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TrafficClass___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 266 /* DeliveryOrder */: {
					Destin->DeliveryOrder = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DeliveryOrder___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 267 /* DeliveryOfErroneusSDU */: {
					Destin->DeliveryOfErroneusSDU = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DeliveryOfErroneusSDU___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 268 /* MaximumSDUSize */: {
					Destin->MaximumSDUSize = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MaximumSDUSize___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 269 /* MaximumBitRateForUplink */: {
					Destin->MaximumBitRateForUplink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MaximumBitRateForUplink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 270 /* MaximumBitRateForDownlink */: {
					Destin->MaximumBitRateForDownlink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MaximumBitRateForDownlink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 271 /* ResidualBER */: {
					Destin->ResidualBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ResidualBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 272 /* SDUErrorRatio */: {
					Destin->SDUErrorRatio = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SDUErrorRatio___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 273 /* TransderDelay */: {
					Destin->TransderDelay = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TransderDelay___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 274 /* TrafficHandlingPriority */: {
					Destin->TrafficHandlingPriority = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TrafficHandlingPriority___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 275 /* GuaranteedBitRateForUplink */: {
					Destin->GuaranteedBitRateForUplink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GuaranteedBitRateForUplink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 276 /* GuaranteedBitRateForDownlink */: {
					Destin->GuaranteedBitRateForDownlink = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GuaranteedBitRateForDownlink___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 277 /* SignalingIndication */: {
					Destin->SignalingIndication = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SignalingIndication___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 278 /* SourceStatisticsDescriptor */: {
					Destin->SourceStatisticsDescriptor = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SourceStatisticsDescriptor___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 279: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsQualityOfServ_downlink (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 283 /* MaximumBitRateForDownlinkExt */: {
					Destin->downlink->MaximumBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->downlink->MaximumBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 284 /* GuaranteedBitRateForDownlinkExt */: {
					Destin->downlink->GuaranteedBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->downlink->GuaranteedBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 280: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsQualityOfServ_uplink (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 285 /* MaximumBitRateForUplinkExt */: {
					Destin->uplink->MaximumBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->uplink->MaximumBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 286 /* GuaranteedBitRateForUplinkExt */: {
					Destin->uplink->GuaranteedBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->uplink->GuaranteedBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 281: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsQualityOfServ_ext2downlink (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 287 /* MaximumBitRateForDownlinkExt */: {
					Destin->ext2downlink->MaximumBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2downlink->MaximumBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 288 /* GuaranteedBitRateForDownlinkExt */: {
					Destin->ext2downlink->GuaranteedBitRateForDownlinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2downlink->GuaranteedBitRateForDownlinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 282: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_epsQualityOfServ_ext2uplink (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 289 /* MaximumBitRateForUplinkExt */: {
					Destin->ext2uplink->MaximumBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2uplink->MaximumBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 290 /* GuaranteedBitRateForUplinkExt */: {
					Destin->ext2uplink->GuaranteedBitRateForUplinkExt = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ext2uplink->GuaranteedBitRateForUplinkExt___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}

				default:;
			}
		}
	}
	
	ED_ON_CHECK_OUT_OF_MEMORY(exitFunc:)
	if (Ret < 0) CSN1C_CONTEXT_PTR->Failed = -1; 
	CSN1C_UNDECLARE_CONTEXT
	
	return Ret;
#else
	ED_ASSERT_FORCE_FAIL
	return ED_SYNTAX_ERROR;
#endif
}
#undef THIS
#undef ED_REMAINING_BITS
#ifdef CSN1C_LABEL_NAMES
/* List of label names */
const char* const Program_EPS_Labels [] = {

	/*     0 */ "CSN1_UESecurityCapability_p128_EEA0",
	/*     1 */ "CSN1_UESecurityCapability_p128_EEA1",
	/*     2 */ "CSN1_UESecurityCapability_p128_EEA2",
	/*     3 */ "CSN1_UESecurityCapability_p128_EEA3",
	/*     4 */ "CSN1_UESecurityCapability_EEA4",
	/*     5 */ "CSN1_UESecurityCapability_EEA5",
	/*     6 */ "CSN1_UESecurityCapability_EEA6",
	/*     7 */ "CSN1_UESecurityCapability_EEA7",
	/*     8 */ "CSN1_UESecurityCapability_p128_EIA0",
	/*     9 */ "CSN1_UESecurityCapability_p128_EIA1",
	/*    10 */ "CSN1_UESecurityCapability_p128_EIA2",
	/*    11 */ "CSN1_UESecurityCapability_p128_EIA3",
	/*    12 */ "CSN1_UESecurityCapability_EIA4",
	/*    13 */ "CSN1_UESecurityCapability_EIA5",
	/*    14 */ "CSN1_UESecurityCapability_EIA6",
	/*    15 */ "CSN1_UESecurityCapability_EIA7",
	/*    16 */ "CSN1_UESecurityCapability_UEA_UIA",
	/*    17 */ "CSN1_UESecurityCapability_UEA0",
	/*    18 */ "CSN1_UESecurityCapability_UEA1",
	/*    19 */ "CSN1_UESecurityCapability_UEA2",
	/*    20 */ "CSN1_UESecurityCapability_UEA3",
	/*    21 */ "CSN1_UESecurityCapability_UEA4",
	/*    22 */ "CSN1_UESecurityCapability_UEA5",
	/*    23 */ "CSN1_UESecurityCapability_UEA6",
	/*    24 */ "CSN1_UESecurityCapability_UEA7",
	/*    25 */ "CSN1_UESecurityCapability_UIA1",
	/*    26 */ "CSN1_UESecurityCapability_UIA2",
	/*    27 */ "CSN1_UESecurityCapability_UIA3",
	/*    28 */ "CSN1_UESecurityCapability_UIA4",
	/*    29 */ "CSN1_UESecurityCapability_UIA5",
	/*    30 */ "CSN1_UESecurityCapability_UIA6",
	/*    31 */ "CSN1_UESecurityCapability_UIA7",
	/*    32 */ "CSN1_UESecurityCapability_GEA",
	/*    33 */ "CSN1_UESecurityCapability_GEA1",
	/*    34 */ "CSN1_UESecurityCapability_GEA2",
	/*    35 */ "CSN1_UESecurityCapability_GEA3",
	/*    36 */ "CSN1_UESecurityCapability_GEA4",
	/*    37 */ "CSN1_UESecurityCapability_GEA5",
	/*    38 */ "CSN1_UESecurityCapability_GEA6",
	/*    39 */ "CSN1_UESecurityCapability_GEA7",
	/*    40 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRDownlink",
	/*    41 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRUplink",
	/*    42 */ "CSN1_APNAggregateMaxBitRate_ext",
	/*    43 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt",
	/*    44 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt",
	/*    45 */ "CSN1_APNAggregateMaxBitRate_ext2",
	/*    46 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt2",
	/*    47 */ "CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt2",
	/*    48 */ "CSN1_EPS_QOS_QCI",
	/*    49 */ "CSN1_EPS_QOS_basic",
	/*    50 */ "CSN1_EPS_QOS_MaximumBitRateForUplink",
	/*    51 */ "CSN1_EPS_QOS_MaximumBitRateForDownlink",
	/*    52 */ "CSN1_EPS_QOS_GuaranteedBitRateForUplink",
	/*    53 */ "CSN1_EPS_QOS_GuaranteedBitRateForDownlink",
	/*    54 */ "CSN1_EPS_QOS_extended",
	/*    55 */ "CSN1_EPS_QOS_MaximumBitRateForUplinkExt",
	/*    56 */ "CSN1_EPS_QOS_MaximumBitRateForDownlinkExt",
	/*    57 */ "CSN1_EPS_QOS_GuaranteedBitRateForUplinkExt",
	/*    58 */ "CSN1_EPS_QOS_GuaranteedBitRateForDownlinkExt",
	/*    59 */ "CSN1_EPS_QOS_extended2",
	/*    60 */ "CSN1_A5_CM3_bits_A5_7",
	/*    61 */ "CSN1_A5_CM3_bits_A5_6",
	/*    62 */ "CSN1_A5_CM3_bits_A5_5",
	/*    63 */ "CSN1_A5_CM3_bits_A5_4",
	/*    64 */ "CSN1_epsQualityOfServ_DelayClass",
	/*    65 */ "CSN1_epsQualityOfServ_ReliabilityClass",
	/*    66 */ "CSN1_epsQualityOfServ_PeakThroughput",
	/*    67 */ "CSN1_epsQualityOfServ_PrecedenceClass",
	/*    68 */ "CSN1_epsQualityOfServ_MeanThroughput",
	/*    69 */ "CSN1_epsQualityOfServ_TrafficClass",
	/*    70 */ "CSN1_epsQualityOfServ_DeliveryOrder",
	/*    71 */ "CSN1_epsQualityOfServ_DeliveryOfErroneusSDU",
	/*    72 */ "CSN1_epsQualityOfServ_MaximumSDUSize",
	/*    73 */ "CSN1_epsQualityOfServ_MaximumBitRateForUplink",
	/*    74 */ "CSN1_epsQualityOfServ_MaximumBitRateForDownlink",
	/*    75 */ "CSN1_epsQualityOfServ_ResidualBER",
	/*    76 */ "CSN1_epsQualityOfServ_SDUErrorRatio",
	/*    77 */ "CSN1_epsQualityOfServ_TransderDelay",
	/*    78 */ "CSN1_epsQualityOfServ_TrafficHandlingPriority",
	/*    79 */ "CSN1_epsQualityOfServ_GuaranteedBitRateForUplink",
	/*    80 */ "CSN1_epsQualityOfServ_GuaranteedBitRateForDownlink",
	/*    81 */ "CSN1_epsQualityOfServ_SignalingIndication",
	/*    82 */ "CSN1_epsQualityOfServ_SourceStatisticsDescriptor",
	/*    83 */ "CSN1_epsQualityOfServ_downlink",
	/*    84 */ "CSN1_epsQualityOfServ_MaximumBitRateForDownlinkExt",
	/*    85 */ "CSN1_epsQualityOfServ_GuaranteedBitRateForDownlinkExt",
	/*    86 */ "CSN1_epsQualityOfServ_uplink",
	/*    87 */ "CSN1_epsQualityOfServ_MaximumBitRateForUplinkExt",
	/*    88 */ "CSN1_epsQualityOfServ_GuaranteedBitRateForUplinkExt",
	/*    89 */ "CSN1_epsQualityOfServ_ext2downlink",
	/*    90 */ "CSN1_epsQualityOfServ_ext2uplink",
	/*    91 */ "CSN1_epsClassmark3Value_Multiband_supported",
	/*    92 */ "CSN1_epsClassmark3Value_Associated_Radio_Capability_2",
	/*    93 */ "CSN1_epsClassmark3Value_Associated_Radio_Capability_1",
	/*    94 */ "CSN1_R_Support_R_GSM_band_Associated_Radio_Capability",
	/*    95 */ "CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class",
	/*    96 */ "CSN1_epsClassmark3Value_UCS2_treatment",
	/*    97 */ "CSN1_epsClassmark3Value_Extended_Measurement_Capability",
	/*    98 */ "CSN1_MS_Measurement_capability_SMS_VALUE",
	/*    99 */ "CSN1_MS_Measurement_capability_SM_VALUE",
	/*   100 */ "CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method",
	/*   101 */ "CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class",
	/*   102 */ "CSN1__8_PSK_Struct_Modulation_Capability",
	/*   103 */ "CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1",
	/*   104 */ "CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2",
	/*   105 */ "CSN1_epsClassmark3Value_GSM_400_Bands_Supported",
	/*   106 */ "CSN1_epsClassmark3Value_GSM_400_Associated_Radio_Capability",
	/*   107 */ "CSN1_epsClassmark3Value_GSM_850_Associated_Radio_Capability",
	/*   108 */ "CSN1_epsClassmark3Value_GSM_1900_Associated_Radio_Capability",
	/*   109 */ "CSN1_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability",
	/*   110 */ "CSN1_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability",
	/*   111 */ "CSN1_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability",
	/*   112 */ "CSN1_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class",
	/*   113 */ "CSN1_epsClassmark3Value_Single_Slot_DTM",
	/*   114 */ "CSN1_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class",
	/*   115 */ "CSN1_Single_Band_Support_GSM_Band",
	/*   116 */ "CSN1_epsClassmark3Value_GSM_750_Associated_Radio_Capability",
	/*   117 */ "CSN1_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability",
	/*   118 */ "CSN1_epsClassmark3Value_GERAN_Feature_Package_1",
	/*   119 */ "CSN1_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class",
	/*   120 */ "CSN1_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class",
	/*   121 */ "CSN1_epsClassmark3Value_High_Multislot_Capability",
	/*   122 */ "CSN1_GERAN_Iu_Mode_Capabilities_Length",
	/*   123 */ "CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability",
	/*   124 */ "CSN1_epsClassmark3Value_GERAN_Feature_Package_2",
	/*   125 */ "CSN1_epsClassmark3Value_GMSK_Multislot_Power_Profile",
	/*   126 */ "CSN1_epsClassmark3Value__8_PSK_Multislot_Power_Profile",
	/*   127 */ "CSN1_epsClassmark3Value_T_GSM_400_Bands_Supported",
	/*   128 */ "CSN1_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability",
	/*   129 */ "CSN1_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability",
	/*   130 */ "CSN1_epsClassmark3Value_Downlink_Advanced_Receiver_Performance",
	/*   131 */ "CSN1_epsClassmark3Value_DTM_Enhancements_Capability",
	/*   132 */ "CSN1_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class",
	/*   133 */ "CSN1_epsClassmark3Value_Offset_required",
	/*   134 */ "CSN1_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class",
	/*   135 */ "CSN1_epsClassmark3Value_Repeated_ACCH_Capability",
	/*   136 */ "CSN1_epsClassmark3Value_GSM_710_Associated_Radio_Capability",
	/*   137 */ "CSN1_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability",
	/*   138 */ "CSN1_epsClassmark3Value_Ciphering_Mode_Setting_Capability",
	/*   139 */ "CSN1_epsClassmark3Value_Additional_Positioning_Capabilities",
	/*   140 */ "CSN1_epsClassmark3Value_E_UTRA_FDD_support",
	/*   141 */ "CSN1_epsClassmark3Value_E_UTRA_TDD_support",
	/*   142 */ "CSN1_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support",
	/*   143 */ "CSN1_epsClassmark3Value_Priority_based_reselection_support",
	/*   144 */ "CSN1_epsClassmark3Value_UTRA_CSG_Cells_Reporting",
	/*   145 */ "CSN1_epsClassmark3Value_VAMOS_Level",
	/*   146 */ "CSN1_epsClassmark3Value_TIGHTER_Capability",
	/*   147 */ "CSN1_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH",
	/*   148 */ "CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA",
	/*   149 */ "CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA",
	/*   150 */ "CSN1_epsClassmark3Value_GERAN_Network_Sharing_support",
	/*   151 */ "CSN1_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support",
	/*   152 */ "CSN1_epsClassmark3Value_ER_Band_Support",
	/*   153 */ "CSN1_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*   154 */ "CSN1_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*   155 */ "CSN1_epsClassmark3Value_Extended_TSC_Set_Capability_support",
	/*   156 */ "CSN1_epsClassmark3Value_Extended_EARFCN_value_range",
	/*   157 */ "CSN1_GEA1_bits_GEA_1",
	/*   158 */ "CSN1_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels",
	/*   159 */ "CSN1_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels",
	/*   160 */ "CSN1_epsMsNetwkCpblty_UCS2_support",
	/*   161 */ "CSN1_epsMsNetwkCpblty_SS_Screening_Indicator",
	/*   162 */ "CSN1_epsMsNetwkCpblty_SoLSA_Capability",
	/*   163 */ "CSN1_epsMsNetwkCpblty_Revision_level_indicator",
	/*   164 */ "CSN1_epsMsNetwkCpblty_PFC_feature_mode",
	/*   165 */ "CSN1_Extended_GEA_bits_GEA_2",
	/*   166 */ "CSN1_Extended_GEA_bits_GEA_3",
	/*   167 */ "CSN1_Extended_GEA_bits_GEA_4",
	/*   168 */ "CSN1_Extended_GEA_bits_GEA_5",
	/*   169 */ "CSN1_Extended_GEA_bits_GEA_6",
	/*   170 */ "CSN1_Extended_GEA_bits_GEA_7",
	/*   171 */ "CSN1_epsMsNetwkCpblty_LCS_VA_capability",
	/*   172 */ "CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability",
	/*   173 */ "CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability",
	/*   174 */ "CSN1_epsMsNetwkCpblty_EMM_Combined_procedures_Capability",
	/*   175 */ "CSN1_epsMsNetwkCpblty_ISR_support",
	/*   176 */ "CSN1_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability",
	/*   177 */ "CSN1_epsMsNetwkCpblty_EPC_capability",
	/*   178 */ "CSN1_epsMsNetwkCpblty_NF_capability",
	/*   179 */ "CSN1_epsMsNetwkCpblty_GERAN_network_sharing_capability",
	/*   180 */ "CSN1_epsMsNetwkCpblty_User_plane_integrity_protection_support",
	/*   181 */ "CSN1_epsMsNetwkCpblty_GIA_4",
	/*   182 */ "CSN1_epsMsNetwkCpblty_GIA_5",
	/*   183 */ "CSN1_epsMsNetwkCpblty_GIA_6",
	/*   184 */ "CSN1_epsMsNetwkCpblty_GIA_7",
	/*   185 */ "CSN1_UENetworkCapability_p128_EEA0",
	/*   186 */ "CSN1_UENetworkCapability_p128_EEA1",
	/*   187 */ "CSN1_UENetworkCapability_p128_EEA2",
	/*   188 */ "CSN1_UENetworkCapability_p128_EEA3",
	/*   189 */ "CSN1_UENetworkCapability_EEA4",
	/*   190 */ "CSN1_UENetworkCapability_EEA5",
	/*   191 */ "CSN1_UENetworkCapability_EEA6",
	/*   192 */ "CSN1_UENetworkCapability_EEA7",
	/*   193 */ "CSN1_UENetworkCapability_EIA0",
	/*   194 */ "CSN1_UENetworkCapability_p128_EIA1",
	/*   195 */ "CSN1_UENetworkCapability_p128_EIA2",
	/*   196 */ "CSN1_UENetworkCapability_p128_EIA3",
	/*   197 */ "CSN1_UENetworkCapability_EIA4",
	/*   198 */ "CSN1_UENetworkCapability_EIA5",
	/*   199 */ "CSN1_UENetworkCapability_EIA6",
	/*   200 */ "CSN1_UENetworkCapability_EIA7",
	/*   201 */ "CSN1_UENetworkCapability_octet_5",
	/*   202 */ "CSN1_UENetworkCapability_UEA0",
	/*   203 */ "CSN1_UENetworkCapability_UEA1",
	/*   204 */ "CSN1_UENetworkCapability_UEA2",
	/*   205 */ "CSN1_UENetworkCapability_UEA3",
	/*   206 */ "CSN1_UENetworkCapability_UEA4",
	/*   207 */ "CSN1_UENetworkCapability_UEA5",
	/*   208 */ "CSN1_UENetworkCapability_UEA6",
	/*   209 */ "CSN1_UENetworkCapability_UEA7",
	/*   210 */ "CSN1_UENetworkCapability_octet_6",
	/*   211 */ "CSN1_UENetworkCapability_UCS2",
	/*   212 */ "CSN1_UENetworkCapability_UIA1",
	/*   213 */ "CSN1_UENetworkCapability_UIA2",
	/*   214 */ "CSN1_UENetworkCapability_UIA3",
	/*   215 */ "CSN1_UENetworkCapability_UIA4",
	/*   216 */ "CSN1_UENetworkCapability_UIA5",
	/*   217 */ "CSN1_UENetworkCapability_UIA6",
	/*   218 */ "CSN1_UENetworkCapability_UIA7",
	/*   219 */ "CSN1_UENetworkCapability_octet_7",
	/*   220 */ "CSN1_UENetworkCapability_H245_ASH",
	/*   221 */ "CSN1_UENetworkCapability_ACC_CSFB",
	/*   222 */ "CSN1_UENetworkCapability_LPP",
	/*   223 */ "CSN1_UENetworkCapability_LCS",
	/*   224 */ "CSN1_UENetworkCapability_p1xSR_VCC",
	/*   225 */ "CSN1_UENetworkCapability_ISR",
	/*   226 */ "CSN1_UENetworkCapability_octet_8",
	/*   227 */ "CSN1_UENetworkCapability_ePCO",
	/*   228 */ "CSN1_UENetworkCapability_HC_CP_CIoT",
	/*   229 */ "CSN1_UENetworkCapability_ERw_oPDN",
	/*   230 */ "CSN1_UENetworkCapability_S1_U_data",
	/*   231 */ "CSN1_UENetworkCapability_UP_CIoT",
	/*   232 */ "CSN1_UENetworkCapability_CP_CIoT",
	/*   233 */ "CSN1_UENetworkCapability_Prose_relay",
	/*   234 */ "CSN1_UENetworkCapability_ProSe_dc",
	NULL
};
#endif

#ifdef CSN1C_ENABLE_LABEL_SIZE
/* For each label id, there is an entry describing its size */
const unsigned char Program_EPS_LabelSize [] = {

	/*     0 */ 1, /* CSN1_UESecurityCapability_p128_EEA0 */
	/*     1 */ 1, /* CSN1_UESecurityCapability_p128_EEA1 */
	/*     2 */ 1, /* CSN1_UESecurityCapability_p128_EEA2 */
	/*     3 */ 1, /* CSN1_UESecurityCapability_p128_EEA3 */
	/*     4 */ 1, /* CSN1_UESecurityCapability_EEA4 */
	/*     5 */ 1, /* CSN1_UESecurityCapability_EEA5 */
	/*     6 */ 1, /* CSN1_UESecurityCapability_EEA6 */
	/*     7 */ 1, /* CSN1_UESecurityCapability_EEA7 */
	/*     8 */ 1, /* CSN1_UESecurityCapability_p128_EIA0 */
	/*     9 */ 1, /* CSN1_UESecurityCapability_p128_EIA1 */
	/*    10 */ 1, /* CSN1_UESecurityCapability_p128_EIA2 */
	/*    11 */ 1, /* CSN1_UESecurityCapability_p128_EIA3 */
	/*    12 */ 1, /* CSN1_UESecurityCapability_EIA4 */
	/*    13 */ 1, /* CSN1_UESecurityCapability_EIA5 */
	/*    14 */ 1, /* CSN1_UESecurityCapability_EIA6 */
	/*    15 */ 1, /* CSN1_UESecurityCapability_EIA7 */
	/*    16 */ 16, /* CSN1_UESecurityCapability_UEA_UIA */
	/*    17 */ 1, /* CSN1_UESecurityCapability_UEA0 */
	/*    18 */ 1, /* CSN1_UESecurityCapability_UEA1 */
	/*    19 */ 1, /* CSN1_UESecurityCapability_UEA2 */
	/*    20 */ 1, /* CSN1_UESecurityCapability_UEA3 */
	/*    21 */ 1, /* CSN1_UESecurityCapability_UEA4 */
	/*    22 */ 1, /* CSN1_UESecurityCapability_UEA5 */
	/*    23 */ 1, /* CSN1_UESecurityCapability_UEA6 */
	/*    24 */ 1, /* CSN1_UESecurityCapability_UEA7 */
	/*    25 */ 1, /* CSN1_UESecurityCapability_UIA1 */
	/*    26 */ 1, /* CSN1_UESecurityCapability_UIA2 */
	/*    27 */ 1, /* CSN1_UESecurityCapability_UIA3 */
	/*    28 */ 1, /* CSN1_UESecurityCapability_UIA4 */
	/*    29 */ 1, /* CSN1_UESecurityCapability_UIA5 */
	/*    30 */ 1, /* CSN1_UESecurityCapability_UIA6 */
	/*    31 */ 1, /* CSN1_UESecurityCapability_UIA7 */
	/*    32 */ 8, /* CSN1_UESecurityCapability_GEA */
	/*    33 */ 1, /* CSN1_UESecurityCapability_GEA1 */
	/*    34 */ 1, /* CSN1_UESecurityCapability_GEA2 */
	/*    35 */ 1, /* CSN1_UESecurityCapability_GEA3 */
	/*    36 */ 1, /* CSN1_UESecurityCapability_GEA4 */
	/*    37 */ 1, /* CSN1_UESecurityCapability_GEA5 */
	/*    38 */ 1, /* CSN1_UESecurityCapability_GEA6 */
	/*    39 */ 1, /* CSN1_UESecurityCapability_GEA7 */
	/*    40 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRDownlink */
	/*    41 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRUplink */
	/*    42 */ 16, /* CSN1_APNAggregateMaxBitRate_ext */
	/*    43 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt */
	/*    44 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt */
	/*    45 */ 16, /* CSN1_APNAggregateMaxBitRate_ext2 */
	/*    46 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt2 */
	/*    47 */ 8, /* CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt2 */
	/*    48 */ 8, /* CSN1_EPS_QOS_QCI */
	/*    49 */ 32, /* CSN1_EPS_QOS_basic */
	/*    50 */ 8, /* CSN1_EPS_QOS_MaximumBitRateForUplink */
	/*    51 */ 8, /* CSN1_EPS_QOS_MaximumBitRateForDownlink */
	/*    52 */ 8, /* CSN1_EPS_QOS_GuaranteedBitRateForUplink */
	/*    53 */ 8, /* CSN1_EPS_QOS_GuaranteedBitRateForDownlink */
	/*    54 */ 32, /* CSN1_EPS_QOS_extended */
	/*    55 */ 8, /* CSN1_EPS_QOS_MaximumBitRateForUplinkExt */
	/*    56 */ 8, /* CSN1_EPS_QOS_MaximumBitRateForDownlinkExt */
	/*    57 */ 8, /* CSN1_EPS_QOS_GuaranteedBitRateForUplinkExt */
	/*    58 */ 8, /* CSN1_EPS_QOS_GuaranteedBitRateForDownlinkExt */
	/*    59 */ 32, /* CSN1_EPS_QOS_extended2 */
	/*    60 */ 1, /* CSN1_A5_CM3_bits_A5_7 */
	/*    61 */ 1, /* CSN1_A5_CM3_bits_A5_6 */
	/*    62 */ 1, /* CSN1_A5_CM3_bits_A5_5 */
	/*    63 */ 1, /* CSN1_A5_CM3_bits_A5_4 */
	/*    64 */ 3, /* CSN1_epsQualityOfServ_DelayClass */
	/*    65 */ 3, /* CSN1_epsQualityOfServ_ReliabilityClass */
	/*    66 */ 4, /* CSN1_epsQualityOfServ_PeakThroughput */
	/*    67 */ 3, /* CSN1_epsQualityOfServ_PrecedenceClass */
	/*    68 */ 5, /* CSN1_epsQualityOfServ_MeanThroughput */
	/*    69 */ 3, /* CSN1_epsQualityOfServ_TrafficClass */
	/*    70 */ 2, /* CSN1_epsQualityOfServ_DeliveryOrder */
	/*    71 */ 3, /* CSN1_epsQualityOfServ_DeliveryOfErroneusSDU */
	/*    72 */ 8, /* CSN1_epsQualityOfServ_MaximumSDUSize */
	/*    73 */ 8, /* CSN1_epsQualityOfServ_MaximumBitRateForUplink */
	/*    74 */ 8, /* CSN1_epsQualityOfServ_MaximumBitRateForDownlink */
	/*    75 */ 4, /* CSN1_epsQualityOfServ_ResidualBER */
	/*    76 */ 4, /* CSN1_epsQualityOfServ_SDUErrorRatio */
	/*    77 */ 6, /* CSN1_epsQualityOfServ_TransderDelay */
	/*    78 */ 2, /* CSN1_epsQualityOfServ_TrafficHandlingPriority */
	/*    79 */ 8, /* CSN1_epsQualityOfServ_GuaranteedBitRateForUplink */
	/*    80 */ 8, /* CSN1_epsQualityOfServ_GuaranteedBitRateForDownlink */
	/*    81 */ 1, /* CSN1_epsQualityOfServ_SignalingIndication */
	/*    82 */ 4, /* CSN1_epsQualityOfServ_SourceStatisticsDescriptor */
	/*    83 */ 16, /* CSN1_epsQualityOfServ_downlink */
	/*    84 */ 8, /* CSN1_epsQualityOfServ_MaximumBitRateForDownlinkExt */
	/*    85 */ 8, /* CSN1_epsQualityOfServ_GuaranteedBitRateForDownlinkExt */
	/*    86 */ 16, /* CSN1_epsQualityOfServ_uplink */
	/*    87 */ 8, /* CSN1_epsQualityOfServ_MaximumBitRateForUplinkExt */
	/*    88 */ 8, /* CSN1_epsQualityOfServ_GuaranteedBitRateForUplinkExt */
	/*    89 */ 16, /* CSN1_epsQualityOfServ_ext2downlink */
	/*    90 */ 16, /* CSN1_epsQualityOfServ_ext2uplink */
	/*    91 */ 3, /* CSN1_epsClassmark3Value_Multiband_supported */
	/*    92 */ 4, /* CSN1_epsClassmark3Value_Associated_Radio_Capability_2 */
	/*    93 */ 4, /* CSN1_epsClassmark3Value_Associated_Radio_Capability_1 */
	/*    94 */ 3, /* CSN1_R_Support_R_GSM_band_Associated_Radio_Capability */
	/*    95 */ 5, /* CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class */
	/*    96 */ 1, /* CSN1_epsClassmark3Value_UCS2_treatment */
	/*    97 */ 1, /* CSN1_epsClassmark3Value_Extended_Measurement_Capability */
	/*    98 */ 4, /* CSN1_MS_Measurement_capability_SMS_VALUE */
	/*    99 */ 4, /* CSN1_MS_Measurement_capability_SM_VALUE */
	/*   100 */ 5, /* CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method */
	/*   101 */ 5, /* CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class */
	/*   102 */ 1, /* CSN1__8_PSK_Struct_Modulation_Capability */
	/*   103 */ 2, /* CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1 */
	/*   104 */ 2, /* CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2 */
	/*   105 */ 2, /* CSN1_epsClassmark3Value_GSM_400_Bands_Supported */
	/*   106 */ 4, /* CSN1_epsClassmark3Value_GSM_400_Associated_Radio_Capability */
	/*   107 */ 4, /* CSN1_epsClassmark3Value_GSM_850_Associated_Radio_Capability */
	/*   108 */ 4, /* CSN1_epsClassmark3Value_GSM_1900_Associated_Radio_Capability */
	/*   109 */ 1, /* CSN1_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability */
	/*   110 */ 1, /* CSN1_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */
	/*   111 */ 1, /* CSN1_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability */
	/*   112 */ 2, /* CSN1_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class */
	/*   113 */ 1, /* CSN1_epsClassmark3Value_Single_Slot_DTM */
	/*   114 */ 2, /* CSN1_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class */
	/*   115 */ 4, /* CSN1_Single_Band_Support_GSM_Band */
	/*   116 */ 4, /* CSN1_epsClassmark3Value_GSM_750_Associated_Radio_Capability */
	/*   117 */ 1, /* CSN1_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */
	/*   118 */ 1, /* CSN1_epsClassmark3Value_GERAN_Feature_Package_1 */
	/*   119 */ 2, /* CSN1_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class */
	/*   120 */ 2, /* CSN1_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class */
	/*   121 */ 2, /* CSN1_epsClassmark3Value_High_Multislot_Capability */
	/*   122 */ 4, /* CSN1_GERAN_Iu_Mode_Capabilities_Length */
	/*   123 */ 1, /* CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability */
	/*   124 */ 1, /* CSN1_epsClassmark3Value_GERAN_Feature_Package_2 */
	/*   125 */ 2, /* CSN1_epsClassmark3Value_GMSK_Multislot_Power_Profile */
	/*   126 */ 2, /* CSN1_epsClassmark3Value__8_PSK_Multislot_Power_Profile */
	/*   127 */ 2, /* CSN1_epsClassmark3Value_T_GSM_400_Bands_Supported */
	/*   128 */ 4, /* CSN1_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability */
	/*   129 */ 4, /* CSN1_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability */
	/*   130 */ 2, /* CSN1_epsClassmark3Value_Downlink_Advanced_Receiver_Performance */
	/*   131 */ 1, /* CSN1_epsClassmark3Value_DTM_Enhancements_Capability */
	/*   132 */ 3, /* CSN1_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class */
	/*   133 */ 1, /* CSN1_epsClassmark3Value_Offset_required */
	/*   134 */ 3, /* CSN1_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class */
	/*   135 */ 1, /* CSN1_epsClassmark3Value_Repeated_ACCH_Capability */
	/*   136 */ 4, /* CSN1_epsClassmark3Value_GSM_710_Associated_Radio_Capability */
	/*   137 */ 4, /* CSN1_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability */
	/*   138 */ 1, /* CSN1_epsClassmark3Value_Ciphering_Mode_Setting_Capability */
	/*   139 */ 1, /* CSN1_epsClassmark3Value_Additional_Positioning_Capabilities */
	/*   140 */ 1, /* CSN1_epsClassmark3Value_E_UTRA_FDD_support */
	/*   141 */ 1, /* CSN1_epsClassmark3Value_E_UTRA_TDD_support */
	/*   142 */ 1, /* CSN1_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support */
	/*   143 */ 1, /* CSN1_epsClassmark3Value_Priority_based_reselection_support */
	/*   144 */ 1, /* CSN1_epsClassmark3Value_UTRA_CSG_Cells_Reporting */
	/*   145 */ 2, /* CSN1_epsClassmark3Value_VAMOS_Level */
	/*   146 */ 2, /* CSN1_epsClassmark3Value_TIGHTER_Capability */
	/*   147 */ 1, /* CSN1_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH */
	/*   148 */ 2, /* CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA */
	/*   149 */ 2, /* CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA */
	/*   150 */ 1, /* CSN1_epsClassmark3Value_GERAN_Network_Sharing_support */
	/*   151 */ 1, /* CSN1_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support */
	/*   152 */ 1, /* CSN1_epsClassmark3Value_ER_Band_Support */
	/*   153 */ 1, /* CSN1_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*   154 */ 1, /* CSN1_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*   155 */ 1, /* CSN1_epsClassmark3Value_Extended_TSC_Set_Capability_support */
	/*   156 */ 1, /* CSN1_epsClassmark3Value_Extended_EARFCN_value_range */
	/*   157 */ 1, /* CSN1_GEA1_bits_GEA_1 */
	/*   158 */ 1, /* CSN1_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels */
	/*   159 */ 1, /* CSN1_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels */
	/*   160 */ 1, /* CSN1_epsMsNetwkCpblty_UCS2_support */
	/*   161 */ 2, /* CSN1_epsMsNetwkCpblty_SS_Screening_Indicator */
	/*   162 */ 1, /* CSN1_epsMsNetwkCpblty_SoLSA_Capability */
	/*   163 */ 1, /* CSN1_epsMsNetwkCpblty_Revision_level_indicator */
	/*   164 */ 1, /* CSN1_epsMsNetwkCpblty_PFC_feature_mode */
	/*   165 */ 1, /* CSN1_Extended_GEA_bits_GEA_2 */
	/*   166 */ 1, /* CSN1_Extended_GEA_bits_GEA_3 */
	/*   167 */ 1, /* CSN1_Extended_GEA_bits_GEA_4 */
	/*   168 */ 1, /* CSN1_Extended_GEA_bits_GEA_5 */
	/*   169 */ 1, /* CSN1_Extended_GEA_bits_GEA_6 */
	/*   170 */ 1, /* CSN1_Extended_GEA_bits_GEA_7 */
	/*   171 */ 1, /* CSN1_epsMsNetwkCpblty_LCS_VA_capability */
	/*   172 */ 1, /* CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability */
	/*   173 */ 1, /* CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability */
	/*   174 */ 1, /* CSN1_epsMsNetwkCpblty_EMM_Combined_procedures_Capability */
	/*   175 */ 1, /* CSN1_epsMsNetwkCpblty_ISR_support */
	/*   176 */ 1, /* CSN1_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability */
	/*   177 */ 1, /* CSN1_epsMsNetwkCpblty_EPC_capability */
	/*   178 */ 1, /* CSN1_epsMsNetwkCpblty_NF_capability */
	/*   179 */ 1, /* CSN1_epsMsNetwkCpblty_GERAN_network_sharing_capability */
	/*   180 */ 1, /* CSN1_epsMsNetwkCpblty_User_plane_integrity_protection_support */
	/*   181 */ 1, /* CSN1_epsMsNetwkCpblty_GIA_4 */
	/*   182 */ 1, /* CSN1_epsMsNetwkCpblty_GIA_5 */
	/*   183 */ 1, /* CSN1_epsMsNetwkCpblty_GIA_6 */
	/*   184 */ 1, /* CSN1_epsMsNetwkCpblty_GIA_7 */
	/*   185 */ 1, /* CSN1_UENetworkCapability_p128_EEA0 */
	/*   186 */ 1, /* CSN1_UENetworkCapability_p128_EEA1 */
	/*   187 */ 1, /* CSN1_UENetworkCapability_p128_EEA2 */
	/*   188 */ 1, /* CSN1_UENetworkCapability_p128_EEA3 */
	/*   189 */ 1, /* CSN1_UENetworkCapability_EEA4 */
	/*   190 */ 1, /* CSN1_UENetworkCapability_EEA5 */
	/*   191 */ 1, /* CSN1_UENetworkCapability_EEA6 */
	/*   192 */ 1, /* CSN1_UENetworkCapability_EEA7 */
	/*   193 */ 1, /* CSN1_UENetworkCapability_EIA0 */
	/*   194 */ 1, /* CSN1_UENetworkCapability_p128_EIA1 */
	/*   195 */ 1, /* CSN1_UENetworkCapability_p128_EIA2 */
	/*   196 */ 1, /* CSN1_UENetworkCapability_p128_EIA3 */
	/*   197 */ 1, /* CSN1_UENetworkCapability_EIA4 */
	/*   198 */ 1, /* CSN1_UENetworkCapability_EIA5 */
	/*   199 */ 1, /* CSN1_UENetworkCapability_EIA6 */
	/*   200 */ 1, /* CSN1_UENetworkCapability_EIA7 */
	/*   201 */ 8, /* CSN1_UENetworkCapability_octet_5 */
	/*   202 */ 1, /* CSN1_UENetworkCapability_UEA0 */
	/*   203 */ 1, /* CSN1_UENetworkCapability_UEA1 */
	/*   204 */ 1, /* CSN1_UENetworkCapability_UEA2 */
	/*   205 */ 1, /* CSN1_UENetworkCapability_UEA3 */
	/*   206 */ 1, /* CSN1_UENetworkCapability_UEA4 */
	/*   207 */ 1, /* CSN1_UENetworkCapability_UEA5 */
	/*   208 */ 1, /* CSN1_UENetworkCapability_UEA6 */
	/*   209 */ 1, /* CSN1_UENetworkCapability_UEA7 */
	/*   210 */ 8, /* CSN1_UENetworkCapability_octet_6 */
	/*   211 */ 1, /* CSN1_UENetworkCapability_UCS2 */
	/*   212 */ 1, /* CSN1_UENetworkCapability_UIA1 */
	/*   213 */ 1, /* CSN1_UENetworkCapability_UIA2 */
	/*   214 */ 1, /* CSN1_UENetworkCapability_UIA3 */
	/*   215 */ 1, /* CSN1_UENetworkCapability_UIA4 */
	/*   216 */ 1, /* CSN1_UENetworkCapability_UIA5 */
	/*   217 */ 1, /* CSN1_UENetworkCapability_UIA6 */
	/*   218 */ 1, /* CSN1_UENetworkCapability_UIA7 */
	/*   219 */ 8, /* CSN1_UENetworkCapability_octet_7 */
	/*   220 */ 1, /* CSN1_UENetworkCapability_H245_ASH */
	/*   221 */ 1, /* CSN1_UENetworkCapability_ACC_CSFB */
	/*   222 */ 1, /* CSN1_UENetworkCapability_LPP */
	/*   223 */ 1, /* CSN1_UENetworkCapability_LCS */
	/*   224 */ 1, /* CSN1_UENetworkCapability_p1xSR_VCC */
	/*   225 */ 1, /* CSN1_UENetworkCapability_ISR */
	/*   226 */ 8, /* CSN1_UENetworkCapability_octet_8 */
	/*   227 */ 1, /* CSN1_UENetworkCapability_ePCO */
	/*   228 */ 1, /* CSN1_UENetworkCapability_HC_CP_CIoT */
	/*   229 */ 1, /* CSN1_UENetworkCapability_ERw_oPDN */
	/*   230 */ 1, /* CSN1_UENetworkCapability_S1_U_data */
	/*   231 */ 1, /* CSN1_UENetworkCapability_UP_CIoT */
	/*   232 */ 1, /* CSN1_UENetworkCapability_CP_CIoT */
	/*   233 */ 1, /* CSN1_UENetworkCapability_Prose_relay */
	/*   234 */ 1  /* CSN1_UENetworkCapability_ProSe_dc */
};
#endif

/* FieldId Pair Set */
static const CSN1C_PAIRSET_TYPE Program_EPS_FieldIdPairSet [] = {
	/* 0000 (ID:0212:124982:125001) <p128_EEA0> */ 0,2,75,
	/* 0003 (ID:0216:125001:125020) <p128_EEA1> */ 1,2,76,
	/* 0006 (ID:0220:125020:125039) <p128_EEA2> */ 2,2,77,
	/* 0009 (ID:0224:125039:125058) <p128_EEA3> */ 3,2,78,
	/* 0012 (ID:0228:125058:125072) <EEA4> */ 4,2,79,
	/* 0015 (ID:0232:125072:125086) <EEA5> */ 5,2,80,
	/* 0018 (ID:0236:125086:125100) <EEA6> */ 6,2,81,
	/* 0021 (ID:0240:125100:125139) <EEA7> */ 7,2,82,
	/* 0024 (ID:0244:125139:125158) <p128_EIA0> */ 8,2,83,
	/* 0027 (ID:0248:125158:125177) <p128_EIA1> */ 9,2,84,
	/* 0030 (ID:0252:125177:125196) <p128_EIA2> */ 10,2,85,
	/* 0033 (ID:0256:125196:125215) <p128_EIA3> */ 11,2,86,
	/* 0036 (ID:0260:125215:125229) <EIA4> */ 12,2,87,
	/* 0039 (ID:0264:125229:125243) <EIA5> */ 13,2,88,
	/* 0042 (ID:0268:125243:125257) <EIA6> */ 14,2,89,
	/* 0045 (ID:0272:125257:125272) <EIA7> */ 15,2,90,
	/* 0048 (ID:0278:125301:125578) <UEA_UIA> */ 16,2,91,
	/* 0051 (ID:0283:125316:125331) <UEA0> */ 17,91,93,
	/* 0054 (ID:0287:125331:125346) <UEA1> */ 18,91,94,
	/* 0057 (ID:0291:125346:125361) <UEA2> */ 19,91,95,
	/* 0060 (ID:0295:125361:125376) <UEA3> */ 20,91,96,
	/* 0063 (ID:0299:125376:125391) <UEA4> */ 21,91,97,
	/* 0066 (ID:0303:125391:125406) <UEA5> */ 22,91,98,
	/* 0069 (ID:0307:125406:125421) <UEA6> */ 23,91,99,
	/* 0072 (ID:0311:125421:125437) <UEA7> */ 24,91,100,
	/* 0075 (ID:0316:125446:125461) <UIA1> */ 25,91,101,
	/* 0078 (ID:0320:125461:125476) <UIA2> */ 26,91,102,
	/* 0081 (ID:0324:125476:125491) <UIA3> */ 27,91,103,
	/* 0084 (ID:0328:125491:125506) <UIA4> */ 28,91,104,
	/* 0087 (ID:0332:125506:125521) <UIA5> */ 29,91,105,
	/* 0090 (ID:0336:125521:125536) <UIA6> */ 30,91,106,
	/* 0093 (ID:0340:125536:125550) <UIA7> */ 31,91,107,
	/* 0096 (ID:0344:125578:125707) <GEA> */ 32,2,92,
	/* 0099 (ID:0350:125598:125613) <GEA1> */ 33,92,108,
	/* 0102 (ID:0354:125613:125628) <GEA2> */ 34,92,109,
	/* 0105 (ID:0358:125628:125643) <GEA3> */ 35,92,110,
	/* 0108 (ID:0362:125643:125658) <GEA4> */ 36,92,111,
	/* 0111 (ID:0366:125658:125673) <GEA5> */ 37,92,112,
	/* 0114 (ID:0370:125673:125688) <GEA6> */ 38,92,113,
	/* 0117 (ID:0374:125688:125702) <GEA7> */ 39,92,114,
	/* 0120 (ID:0382:126432:126466) <APN_AMBRDownlink> */ 40,3,115,
	/* 0123 (ID:0386:126466:126500) <APN_AMBRUplink> */ 41,3,116,
	/* 0126 (ID:0392:126533:126622) <ext> */ 42,3,117,
	/* 0129 (ID:0397:126545:126581) <APN_AMBRDownlinkExt> */ 43,117,119,
	/* 0132 (ID:0401:126581:126616) <APN_AMBRUplinkExt> */ 44,117,120,
	/* 0135 (ID:0405:126622:126711) <ext2> */ 45,3,118,
	/* 0138 (ID:0410:126635:126671) <APN_AMBRDownlinkExt2> */ 46,118,121,
	/* 0141 (ID:0414:126671:126706) <APN_AMBRUplinkExt2> */ 47,118,122,
	/* 0144 (ID:0422:126847:126863) <QCI> */ 48,4,123,
	/* 0147 (ID:0428:126868:127084) <basic> */ 49,4,124,
	/* 0150 (ID:0433:126887:126934) <MaximumBitRateForUplink> */ 50,124,127,
	/* 0153 (ID:0437:126934:126981) <MaximumBitRateForDownlink> */ 51,124,128,
	/* 0156 (ID:0441:126981:127028) <GuaranteedBitRateForUplink> */ 52,124,129,
	/* 0159 (ID:0445:127028:127074) <GuaranteedBitRateForDownlink> */ 53,124,130,
	/* 0162 (ID:0449:127084:127303) <extended> */ 54,4,125,
	/* 0165 (ID:0454:127106:127153) <MaximumBitRateForUplinkExt> */ 55,125,131,
	/* 0168 (ID:0458:127153:127200) <MaximumBitRateForDownlinkExt> */ 56,125,132,
	/* 0171 (ID:0462:127200:127247) <GuaranteedBitRateForUplinkExt> */ 57,125,133,
	/* 0174 (ID:0466:127247:127293) <GuaranteedBitRateForDownlinkExt> */ 58,125,134,
	/* 0177 (ID:0470:127303:127522) <extended2> */ 59,4,126,
	/* 0180 (ID:0475:127326:127373) <MaximumBitRateForUplinkExt> */ 55,126,135,
	/* 0183 (ID:0479:127373:127420) <MaximumBitRateForDownlinkExt> */ 56,126,136,
	/* 0186 (ID:0483:127420:127467) <GuaranteedBitRateForUplinkExt> */ 57,126,137,
	/* 0189 (ID:0487:127467:127513) <GuaranteedBitRateForDownlinkExt> */ 58,126,138,
	/* 0192 (ID:0941:147810:147825) <A5_7> */ 60,5,140,6,209,
	/* 0197 (ID:0945:147825:147840) <A5_6> */ 61,5,141,6,210,
	/* 0202 (ID:0949:147840:147855) <A5_5> */ 62,5,142,6,211,
	/* 0207 (ID:0953:147855:147871) <A5_4> */ 63,5,143,6,212,
	/* 0212 (ID:1162:165000:165216) <DelayClass> */ 64,18,260,
	/* 0215 (ID:1166:165216:165685) <ReliabilityClass> */ 65,18,261,
	/* 0218 (ID:1170:165685:166097) <PeakThroughput> */ 66,18,262,
	/* 0221 (ID:1175:166112:166309) <PrecedenceClass> */ 67,18,263,
	/* 0224 (ID:1180:166328:167013) <MeanThroughput> */ 68,18,264,
	/* 0227 (ID:1184:167013:167235) <TrafficClass> */ 69,18,265,
	/* 0230 (ID:1188:167235:167417) <DeliveryOrder> */ 70,18,266,
	/* 0233 (ID:1192:167417:167685) <DeliveryOfErroneusSDU> */ 71,18,267,
	/* 0236 (ID:1196:167685:167906) <MaximumSDUSize> */ 72,18,268,
	/* 0239 (ID:1200:167906:168637) <MaximumBitRateForUplink> */ 73,18,269,
	/* 0242 (ID:1204:168637:169370) <MaximumBitRateForDownlink> */ 74,18,270,
	/* 0245 (ID:1208:169370:169674) <ResidualBER> */ 75,18,271,
	/* 0248 (ID:1212:169674:169936) <SDUErrorRatio> */ 76,18,272,
	/* 0251 (ID:1216:169936:169962) <TransderDelay> */ 77,18,273,
	/* 0254 (ID:1220:169962:170165) <TrafficHandlingPriority> */ 78,18,274,
	/* 0257 (ID:1224:170165:170221) <GuaranteedBitRateForUplink> */ 79,18,275,
	/* 0260 (ID:1228:170221:170279) <GuaranteedBitRateForDownlink> */ 80,18,276,
	/* 0263 (ID:1233:170298:170438) <SignalingIndication> */ 81,18,277,
	/* 0266 (ID:1237:170438:170537) <SourceStatisticsDescriptor> */ 82,18,278,
	/* 0269 (ID:1243:170561:170691) <downlink> */ 83,18,279,
	/* 0272 (ID:1248:170578:170621) <MaximumBitRateForDownlinkExt> */ 84,279,283,
	/* 0275 (ID:1252:170621:170666) <GuaranteedBitRateForDownlinkExt> */ 85,279,284,
	/* 0278 (ID:1256:170691:170815) <uplink> */ 86,18,280,
	/* 0281 (ID:1261:170706:170747) <MaximumBitRateForUplinkExt> */ 87,280,285,
	/* 0284 (ID:1265:170747:170790) <GuaranteedBitRateForUplinkExt> */ 88,280,286,
	/* 0287 (ID:1269:170815:170949) <ext2downlink> */ 89,18,281,
	/* 0290 (ID:1274:170836:170879) <MaximumBitRateForDownlinkExt> */ 84,281,287,
	/* 0293 (ID:1278:170879:170924) <GuaranteedBitRateForDownlinkExt> */ 85,281,288,
	/* 0296 (ID:1282:170949:171057) <ext2uplink> */ 90,18,282,
	/* 0299 (ID:1287:170968:171009) <MaximumBitRateForUplinkExt> */ 87,282,289,
	/* 0302 (ID:1291:171009:171052) <GuaranteedBitRateForUplinkExt> */ 88,282,290,
	/* 0305 (ID:0506:143236:143281) <Multiband_supported> */ 91,5,139,
	/* 0308 (ID:0519:143301:143348) <Associated_Radio_Capability_2> */ 92,5,144,
	/* 0311 (ID:0523:143348:143393) <Associated_Radio_Capability_1> */ 93,5,145,
	/* 0314 (ID:0528:143395:143446) <Multiband_supported> */ 91,5,139,
	/* 0317 (ID:0546:143487:143530) <Associated_Radio_Capability_1> */ 93,5,145,
	/* 0320 (ID:0496:143177:143215) <Multiband_supported> */ 91,5,139,
	/* 0323 (ID:0959:147899:147951) <R_GSM_band_Associated_Radio_Capability> */ 94,5,146,7,213,
	/* 0328 (ID:0965:148000:148037) <HSCSD_Multi_Slot_Class> */ 95,5,147,8,214,
	/* 0333 (ID:0562:143604:143630) <UCS2_treatment> */ 96,5,148,
	/* 0336 (ID:0566:143630:143674) <Extended_Measurement_Capability> */ 97,5,149,
	/* 0339 (ID:0971:148084:148110) <SMS_VALUE> */ 98,5,150,9,215,
	/* 0344 (ID:0975:148110:148133) <SM_VALUE> */ 99,5,151,9,216,
	/* 0349 (ID:0981:148187:148222) <MS_Positioning_Method> */ 100,5,152,10,217,
	/* 0354 (ID:0987:148270:148305) <ECSD_Multi_Slot_Class> */ 101,5,153,11,218,
	/* 0359 (ID:0993:148338:148372) <Modulation_Capability> */ 102,5,154,12,219,
	/* 0364 (ID:1002:148380:148420) <_8_PSK_RF_Power_Capability_1> */ 103,5,155,12,220,
	/* 0369 (ID:1011:148432:148472) <_8_PSK_RF_Power_Capability_2> */ 104,5,156,12,221,
	/* 0374 (ID:0599:143845:144078) <GSM_400_Bands_Supported> */ 105,5,157,
	/* 0377 (ID:0612:144078:144126) <GSM_400_Associated_Radio_Capability> */ 106,5,158,
	/* 0380 (ID:0621:144140:144188) <GSM_850_Associated_Radio_Capability> */ 107,5,159,
	/* 0383 (ID:0630:144200:144249) <GSM_1900_Associated_Radio_Capability> */ 108,5,160,
	/* 0386 (ID:0634:144253:144309) <UMTS_FDD_Radio_Access_Technology_Capability> */ 109,5,161,
	/* 0389 (ID:0638:144309:144375) <UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> */ 110,5,162,
	/* 0392 (ID:0642:144375:144434) <CDMA_2000_Radio_Access_Technology_Capability> */ 111,5,163,
	/* 0395 (ID:0651:144442:144485) <DTM_GPRS_Multi_Slot_Class> */ 112,5,164,
	/* 0398 (ID:0655:144485:144515) <Single_Slot_DTM> */ 113,5,165,
	/* 0401 (ID:0664:144521:144561) <DTM_EGPRS_Multi_Slot_Class> */ 114,5,166,
	/* 0404 (ID:1017:148514:148895) <GSM_Band> */ 115,5,167,13,222,
	/* 0409 (ID:0683:144662:144708) <GSM_750_Associated_Radio_Capability> */ 116,5,168,
	/* 0412 (ID:0687:144716:144783) <UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> */ 117,5,169,
	/* 0415 (ID:0691:144783:144823) <GERAN_Feature_Package_1> */ 118,5,170,
	/* 0418 (ID:0700:144831:145098) <Extended_DTM_GPRS_Multi_Slot_Class> */ 119,5,171,
	/* 0421 (ID:0704:145098:145147) <Extended_DTM_EGPRS_Multi_Slot_Class> */ 120,5,172,
	/* 0424 (ID:0717:145179:145218) <High_Multislot_Capability> */ 121,5,173,
	/* 0427 (ID:1023:148944:149031) <Length> */ 122,5,174,14,223,
	/* 0432 (ID:1028:149213:149244) <FLO_Iu_Capability> */ 123,5,175,14,224,
	/* 0437 (ID:0727:145381:145423) <GERAN_Feature_Package_2> */ 124,5,176,
	/* 0440 (ID:0731:145423:145470) <GMSK_Multislot_Power_Profile> */ 125,5,177,
	/* 0443 (ID:0735:145470:145522) <_8_PSK_Multislot_Power_Profile> */ 126,5,178,
	/* 0446 (ID:0748:145547:145630) <T_GSM_400_Bands_Supported> */ 127,5,179,
	/* 0449 (ID:0761:145630:145680) <T_GSM_400_Associated_Radio_Capability> */ 128,5,180,
	/* 0452 (ID:0770:145700:145750) <T_GSM_900_Associated_Radio_Capability> */ 129,5,181,
	/* 0455 (ID:0774:145757:145819) <Downlink_Advanced_Receiver_Performance> */ 130,5,182,
	/* 0458 (ID:0778:145819:145867) <DTM_Enhancements_Capability> */ 131,5,183,
	/* 0461 (ID:0787:145875:145926) <DTM_GPRS_High_Multi_Slot_Class> */ 132,5,184,
	/* 0464 (ID:0791:145926:145958) <Offset_required> */ 133,5,185,
	/* 0467 (ID:0800:145966:146011) <DTM_EGPRS_High_Multi_Slot_Class> */ 134,5,186,
	/* 0470 (ID:0804:146025:146070) <Repeated_ACCH_Capability> */ 135,5,187,
	/* 0473 (ID:0817:146096:146142) <GSM_710_Associated_Radio_Capability> */ 136,5,188,
	/* 0476 (ID:0826:146186:146234) <T_GSM_810_Associated_Radio_Capability> */ 137,5,189,
	/* 0479 (ID:0830:146242:146298) <Ciphering_Mode_Setting_Capability> */ 138,5,190,
	/* 0482 (ID:0834:146298:146356) <Additional_Positioning_Capabilities> */ 139,5,191,
	/* 0485 (ID:0842:146375:146446) <E_UTRA_FDD_support> */ 140,5,192,
	/* 0488 (ID:0846:146446:146482) <E_UTRA_TDD_support> */ 141,5,193,
	/* 0491 (ID:0850:146482:146540) <E_UTRA_Measurement_and_Reporting_support> */ 142,5,194,
	/* 0494 (ID:0854:146540:146599) <Priority_based_reselection_support> */ 143,5,195,
	/* 0497 (ID:0862:146619:146693) <UTRA_CSG_Cells_Reporting> */ 144,5,196,
	/* 0500 (ID:0866:146693:146726) <VAMOS_Level> */ 145,5,197,
	/* 0503 (ID:0874:146748:146823) <TIGHTER_Capability> */ 146,5,198,
	/* 0506 (ID:0878:146823:146880) <Selective_Ciphering_of_Downlink_SACCH> */ 147,5,199,
	/* 0509 (ID:0886:146903:146989) <CS_to_PS_SRVCC_from_GERAN_to_UTRA> */ 148,5,200,
	/* 0512 (ID:0890:146989:147057) <CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> */ 149,5,201,
	/* 0515 (ID:0894:147057:147107) <GERAN_Network_Sharing_support> */ 150,5,202,
	/* 0518 (ID:0898:147107:147179) <E_UTRA_Wideband_RSRQ_measurements_support> */ 151,5,203,
	/* 0521 (ID:0902:147179:147251) <ER_Band_Support> */ 152,5,204,
	/* 0524 (ID:0906:147251:147319) <UTRA_Multiple_Frequency_Band_Indicators_support> */ 153,5,205,
	/* 0527 (ID:0910:147319:147388) <E_UTRA_Multiple_Frequency_Band_Indicators_support> */ 154,5,206,
	/* 0530 (ID:0914:147388:147443) <Extended_TSC_Set_Capability_support> */ 155,5,207,
	/* 0533 (ID:0918:147443:147531) <Extended_EARFCN_value_range> */ 156,5,208,
	/* 0536 (ID:1129:161419:161432) <GEA_1> */ 157,15,225,16,253,
	/* 0541 (ID:1037:160591:160641) <SM_capabilities_via_dedicated_channels> */ 158,15,226,
	/* 0544 (ID:1041:160641:160686) <SM_capabilities_via_GPRS_channels> */ 159,15,227,
	/* 0547 (ID:1045:160686:160710) <UCS2_support> */ 160,15,228,
	/* 0550 (ID:1049:160710:160747) <SS_Screening_Indicator> */ 161,15,229,
	/* 0553 (ID:1053:160747:160776) <SoLSA_Capability> */ 162,15,230,
	/* 0556 (ID:1057:160776:160812) <Revision_level_indicator> */ 163,15,231,
	/* 0559 (ID:1061:160812:160840) <PFC_feature_mode> */ 164,15,232,
	/* 0562 (ID:1135:161466:161477) <GEA_2> */ 165,15,233,17,254,
	/* 0567 (ID:1139:161477:161488) <GEA_3> */ 166,15,234,17,255,
	/* 0572 (ID:1143:161488:161501) <GEA_4> */ 167,15,235,17,256,
	/* 0577 (ID:1147:161501:161514) <GEA_5> */ 168,15,236,17,257,
	/* 0582 (ID:1151:161514:161527) <GEA_6> */ 169,15,237,17,258,
	/* 0587 (ID:1155:161527:161538) <GEA_7> */ 170,15,238,17,259,
	/* 0592 (ID:1066:160864:160893) <LCS_VA_capability> */ 171,15,239,
	/* 0595 (ID:1074:160906:160972) <PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> */ 172,15,240,
	/* 0598 (ID:1078:160972:161040) <PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> */ 173,15,241,
	/* 0601 (ID:1082:161040:161088) <EMM_Combined_procedures_Capability> */ 174,15,242,
	/* 0604 (ID:1086:161088:161111) <ISR_support> */ 175,15,243,
	/* 0607 (ID:1090:161111:161154) <SRVCC_to_GERAN_UTRAN_capability> */ 176,15,244,
	/* 0610 (ID:1094:161154:161180) <EPC_capability> */ 177,15,245,
	/* 0613 (ID:1098:161180:161205) <NF_capability> */ 178,15,246,
	/* 0616 (ID:1102:161205:161249) <GERAN_network_sharing_capability> */ 179,15,247,
	/* 0619 (ID:1106:161249:161300) <User_plane_integrity_protection_support> */ 180,15,248,
	/* 0622 (ID:1110:161300:161317) <GIA_4> */ 181,15,249,
	/* 0625 (ID:1114:161317:161334) <GIA_5> */ 182,15,250,
	/* 0628 (ID:1118:161334:161351) <GIA_6> */ 183,15,251,
	/* 0631 (ID:1122:161351:161367) <GIA_7> */ 184,15,252,
	/* 0634 (ID:0002:123834:123853) <p128_EEA0> */ 185,1,25,
	/* 0637 (ID:0006:123853:123872) <p128_EEA1> */ 186,1,26,
	/* 0640 (ID:0010:123872:123891) <p128_EEA2> */ 187,1,27,
	/* 0643 (ID:0014:123891:123910) <p128_EEA3> */ 188,1,28,
	/* 0646 (ID:0018:123910:123924) <EEA4> */ 189,1,29,
	/* 0649 (ID:0022:123924:123938) <EEA5> */ 190,1,30,
	/* 0652 (ID:0026:123938:123952) <EEA6> */ 191,1,31,
	/* 0655 (ID:0030:123952:123980) <EEA7> */ 192,1,32,
	/* 0658 (ID:0034:123980:123994) <EIA0> */ 193,1,33,
	/* 0661 (ID:0038:123994:124013) <p128_EIA1> */ 194,1,34,
	/* 0664 (ID:0042:124013:124032) <p128_EIA2> */ 195,1,35,
	/* 0667 (ID:0046:124032:124051) <p128_EIA3> */ 196,1,36,
	/* 0670 (ID:0050:124051:124065) <EIA4> */ 197,1,37,
	/* 0673 (ID:0054:124065:124079) <EIA5> */ 198,1,38,
	/* 0676 (ID:0058:124079:124093) <EIA6> */ 199,1,39,
	/* 0679 (ID:0062:124093:124107) <EIA7> */ 200,1,40,
	/* 0682 (ID:0068:124126:124289) <octet_5> */ 201,1,41,
	/* 0685 (ID:0073:124142:124158) <UEA0> */ 202,41,45,
	/* 0688 (ID:0077:124158:124174) <UEA1> */ 203,41,46,
	/* 0691 (ID:0081:124174:124190) <UEA2> */ 204,41,47,
	/* 0694 (ID:0085:124190:124206) <UEA3> */ 205,41,48,
	/* 0697 (ID:0089:124206:124222) <UEA4> */ 206,41,49,
	/* 0700 (ID:0093:124222:124238) <UEA5> */ 207,41,50,
	/* 0703 (ID:0097:124238:124254) <UEA6> */ 208,41,51,
	/* 0706 (ID:0101:124254:124269) <UEA7> */ 209,41,52,
	/* 0709 (ID:0105:124289:124452) <octet_6> */ 210,1,42,
	/* 0712 (ID:0110:124305:124321) <UCS2> */ 211,42,53,
	/* 0715 (ID:0114:124321:124337) <UIA1> */ 212,42,54,
	/* 0718 (ID:0118:124337:124353) <UIA2> */ 213,42,55,
	/* 0721 (ID:0122:124353:124369) <UIA3> */ 214,42,56,
	/* 0724 (ID:0126:124369:124385) <UIA4> */ 215,42,57,
	/* 0727 (ID:0130:124385:124401) <UIA5> */ 216,42,58,
	/* 0730 (ID:0134:124401:124417) <UIA6> */ 217,42,59,
	/* 0733 (ID:0138:124417:124432) <UIA7> */ 218,42,60,
	/* 0736 (ID:0142:124452:124614) <octet_7> */ 219,1,43,
	/* 0739 (ID:0148:124489:124509) <H245_ASH> */ 220,43,61,
	/* 0742 (ID:0152:124509:124529) <ACC_CSFB> */ 221,43,62,
	/* 0745 (ID:0156:124529:124544) <LPP> */ 222,43,63,
	/* 0748 (ID:0160:124544:124559) <LCS> */ 223,43,64,
	/* 0751 (ID:0164:124559:124580) <p1xSR_VCC> */ 224,43,65,
	/* 0754 (ID:0168:124580:124594) <ISR> */ 225,43,66,
	/* 0757 (ID:0172:124614:124794) <octet_8> */ 226,1,44,
	/* 0760 (ID:0177:124630:124646) <ePCO> */ 227,44,67,
	/* 0763 (ID:0181:124646:124668) <HC_CP_CIoT> */ 228,44,68,
	/* 0766 (ID:0185:124668:124688) <ERw_oPDN> */ 229,44,69,
	/* 0769 (ID:0189:124688:124709) <S1_U_data> */ 230,44,70,
	/* 0772 (ID:0193:124709:124728) <UP_CIoT> */ 231,44,71,
	/* 0775 (ID:0197:124728:124747) <CP_CIoT> */ 232,44,72,
	/* 0778 (ID:0201:124747:124770) <Prose_relay> */ 233,44,73,
	/* 0781 (ID:0205:124770:124789) <ProSe_dc> */ 234,44,74

#ifndef NDEBUG
	, -1, -1 /* Used in conjunction with an assert */
#endif
};

/* CUSTOM EXPRESSION 0 (ID:1317:185325:185332, ID:1326:185413:185420) */
unsigned ED_EXLONG Program_EPS_expr0000 (TCSN1CContext* Context) {
	ED_WARNING_REMOVER(Context);
	return (unsigned ED_EXLONG)((8 - (CURPOS & 7)) & 7);
}
static const unsigned ED_EXLONG (*const Program_EPS_ExpressionMap[]) (TCSN1CContext*) = {
	(const unsigned ED_EXLONG (*const) (TCSN1CContext*))Program_EPS_expr0000};
/* CUSTOM ACTION 0 (ID:1027:149031:149213) */
void Program_EPS_action0000 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	PUSH_TAG (2, CURPOS);
}}
/* CUSTOM ACTION 1 (ID:1027:149031:149213) */
void Program_EPS_action0001 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	PUSH_TAG (1, Context->FinalOffset);	Context->FinalOffset = CURPOS+EDBitsToInt (BUFFER, CURPOS-4, 4);
}}
/* CUSTOM ACTION 2 (ID:1033:149297:149405) */
void Program_EPS_action0002 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	EDIntToBits (BUFFER, TAG(2)-7, CURPOS-TAG(2), 4);
}}
/* CUSTOM ACTION 3 (ID:1033:149297:149405) */
void Program_EPS_action0003 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	Context->FinalOffset = TAG(1);
}}
static const void (*const Program_EPS_FunctionMap[]) (TCSN1CContext* ED_EXTRAPARAMS_DECL) = {
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_EPS_action0000,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_EPS_action0001,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_EPS_action0002,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_EPS_action0003};
/* PROGRAM CODE FOR PROGRAM 'Program_EPS' */
static const unsigned char Program_EPS_ProgramCode [] = {

	/*-----------------------------------------------------------------
		DEFINITION 'bit'
		DEFINITION FIELD-ID: 19  COMPLEXITY: 5
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1504
	-----------------------------------------------------------------*/
	/* 000000 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 000001 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bits'
		DEFINITION FIELD-ID: 20  COMPLEXITY: 5
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1505
	-----------------------------------------------------------------*/
	/* 000002 */ CSN1C_BIT_A(1),                          /* (ID:1302:185254:185255) */
	/* 000003 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bit'
		DEFINITION FIELD-ID: 21  COMPLEXITY: 5
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1506
	-----------------------------------------------------------------*/
	/* 000004 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 4, node 1, jump to 9 */
	/* 000006 */ CSN1C_BIT_L,                             /* (ID:1307:185276:185277) */
	/* 000007 */ CSN1C_GOTO(8),                           /* (ID:1305:185276:185279) jump at 15 */
	/* 000009 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 4, node 2, jump to 14 */
	/* 000011 */ CSN1C_BIT_H,                             /* (ID:1309:185278:185279) */
	/* 000012 */ CSN1C_GOTO(3),                           /* (ID:1305:185276:185279) jump at 15 */
	/* 000014 */ CSN1C_BACKTRACK,                         /* (ID:1305:185276:185279) Failure of choice begun at 4 */
	/* 000015 */ CSN1C_CHOICE_END,                        /* (ID:1305:185276:185279) End of choice begun at 4 */
	/* 000016 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_zero'
		DEFINITION FIELD-ID: 22  COMPLEXITY: 5
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1507
	-----------------------------------------------------------------*/
	/* 000017 */ CSN1C_BIT_A(1),                          /* (ID:1312:185299:185300) */
	/* 000018 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'UESecurityCapability'
		DEFINITION FIELD-ID: 2  COMPLEXITY: 168
		SOURCE: ./TS_24.301_core_R13.src, 2752
	-----------------------------------------------------------------*/
	/* 000019 */ CSN1C_LABEL_A, CSN1C_VAL1(1), CSN1C_VAL1(1), /* (ID:0212:124982:125001) Label=<p128_EEA0> LabelId=0 */
	/* 000022 */ CSN1C_LABEL_A, CSN1C_VAL1(4), CSN1C_VAL1(1), /* (ID:0216:125001:125020) Label=<p128_EEA1> LabelId=1 */
	/* 000025 */ CSN1C_LABEL_A, CSN1C_VAL1(7), CSN1C_VAL1(1), /* (ID:0220:125020:125039) Label=<p128_EEA2> LabelId=2 */
	/* 000028 */ CSN1C_LABEL_A, CSN1C_VAL1(10), CSN1C_VAL1(1), /* (ID:0224:125039:125058) Label=<p128_EEA3> LabelId=3 */
	/* 000031 */ CSN1C_LABEL_A, CSN1C_VAL1(13), CSN1C_VAL1(1), /* (ID:0228:125058:125072) Label=<EEA4> LabelId=4 */
	/* 000034 */ CSN1C_LABEL_A, CSN1C_VAL1(16), CSN1C_VAL1(1), /* (ID:0232:125072:125086) Label=<EEA5> LabelId=5 */
	/* 000037 */ CSN1C_LABEL_A, CSN1C_VAL1(19), CSN1C_VAL1(1), /* (ID:0236:125086:125100) Label=<EEA6> LabelId=6 */
	/* 000040 */ CSN1C_LABEL_A, CSN1C_VAL1(22), CSN1C_VAL1(1), /* (ID:0240:125100:125139) Label=<EEA7> LabelId=7 */
	/* 000043 */ CSN1C_LABEL_A, CSN1C_VAL1(25), CSN1C_VAL1(1), /* (ID:0244:125139:125158) Label=<p128_EIA0> LabelId=8 */
	/* 000046 */ CSN1C_LABEL_A, CSN1C_VAL1(28), CSN1C_VAL1(1), /* (ID:0248:125158:125177) Label=<p128_EIA1> LabelId=9 */
	/* 000049 */ CSN1C_LABEL_A, CSN1C_VAL1(31), CSN1C_VAL1(1), /* (ID:0252:125177:125196) Label=<p128_EIA2> LabelId=10 */
	/* 000052 */ CSN1C_LABEL_A, CSN1C_VAL1(34), CSN1C_VAL1(1), /* (ID:0256:125196:125215) Label=<p128_EIA3> LabelId=11 */
	/* 000055 */ CSN1C_LABEL_A, CSN1C_VAL1(37), CSN1C_VAL1(1), /* (ID:0260:125215:125229) Label=<EIA4> LabelId=12 */
	/* 000058 */ CSN1C_LABEL_A, CSN1C_VAL1(40), CSN1C_VAL1(1), /* (ID:0264:125229:125243) Label=<EIA5> LabelId=13 */
	/* 000061 */ CSN1C_LABEL_A, CSN1C_VAL1(43), CSN1C_VAL1(1), /* (ID:0268:125243:125257) Label=<EIA6> LabelId=14 */
	/* 000064 */ CSN1C_LABEL_A, CSN1C_VAL1(46), CSN1C_VAL1(1), /* (ID:0272:125257:125272) Label=<EIA7> LabelId=15 */
	/* 000067 */ CSN1C_CHOICE_NODE(0,82),                 /* (ID:0277:125301:125707) Truncable concatenation, entry 0, jump to 149 */
	/* 000069 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(98),       /* (ID:0278:125301:125578) Label=<UEA_UIA> Terminal=<0> LabelId=16 */
	/* 000071 */ CSN1C_LABEL_A, CSN1C_VAL1(52), CSN1C_VAL1(1), /* (ID:0283:125316:125331) Label=<UEA0> LabelId=17 */
	/* 000074 */ CSN1C_LABEL_A, CSN1C_VAL1(55), CSN1C_VAL1(1), /* (ID:0287:125331:125346) Label=<UEA1> LabelId=18 */
	/* 000077 */ CSN1C_LABEL_A, CSN1C_VAL1(58), CSN1C_VAL1(1), /* (ID:0291:125346:125361) Label=<UEA2> LabelId=19 */
	/* 000080 */ CSN1C_LABEL_A, CSN1C_VAL1(61), CSN1C_VAL1(1), /* (ID:0295:125361:125376) Label=<UEA3> LabelId=20 */
	/* 000083 */ CSN1C_LABEL_A, CSN1C_VAL1(64), CSN1C_VAL1(1), /* (ID:0299:125376:125391) Label=<UEA4> LabelId=21 */
	/* 000086 */ CSN1C_LABEL_A, CSN1C_VAL1(67), CSN1C_VAL1(1), /* (ID:0303:125391:125406) Label=<UEA5> LabelId=22 */
	/* 000089 */ CSN1C_LABEL_A, CSN1C_VAL1(70), CSN1C_VAL1(1), /* (ID:0307:125406:125421) Label=<UEA6> LabelId=23 */
	/* 000092 */ CSN1C_LABEL_A, CSN1C_VAL1(73), CSN1C_VAL1(1), /* (ID:0311:125421:125437) Label=<UEA7> LabelId=24 */
	/* 000095 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 000096 */ CSN1C_LABEL_A, CSN1C_VAL1(76), CSN1C_VAL1(1), /* (ID:0316:125446:125461) Label=<UIA1> LabelId=25 */
	/* 000099 */ CSN1C_LABEL_A, CSN1C_VAL1(79), CSN1C_VAL1(1), /* (ID:0320:125461:125476) Label=<UIA2> LabelId=26 */
	/* 000102 */ CSN1C_LABEL_A, CSN1C_VAL1(82), CSN1C_VAL1(1), /* (ID:0324:125476:125491) Label=<UIA3> LabelId=27 */
	/* 000105 */ CSN1C_LABEL_A, CSN1C_VAL1(85), CSN1C_VAL1(1), /* (ID:0328:125491:125506) Label=<UIA4> LabelId=28 */
	/* 000108 */ CSN1C_LABEL_A, CSN1C_VAL1(88), CSN1C_VAL1(1), /* (ID:0332:125506:125521) Label=<UIA5> LabelId=29 */
	/* 000111 */ CSN1C_LABEL_A, CSN1C_VAL1(91), CSN1C_VAL1(1), /* (ID:0336:125521:125536) Label=<UIA6> LabelId=30 */
	/* 000114 */ CSN1C_LABEL_A, CSN1C_VAL1(94), CSN1C_VAL1(1), /* (ID:0340:125536:125550) Label=<UIA7> LabelId=31 */
	/* 000117 */ CSN1C_LABEL_END, CSN1C_VAL1(98),         /* (ID:0278:125301:125578) Label=<UEA_UIA> Terminal=<0> */
	/* 000119 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0277:125301:125707) Truncable concatenation, entry 1 */
	/* 000120 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(194),      /* (ID:0344:125578:125707) Label=<GEA> Terminal=<0> LabelId=32 */
	/* 000123 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 000124 */ CSN1C_LABEL_A, CSN1C_VAL1(100), CSN1C_VAL1(1), /* (ID:0350:125598:125613) Label=<GEA1> LabelId=33 */
	/* 000127 */ CSN1C_LABEL_A, CSN1C_VAL1(103), CSN1C_VAL1(1), /* (ID:0354:125613:125628) Label=<GEA2> LabelId=34 */
	/* 000130 */ CSN1C_LABEL_A, CSN1C_VAL1(106), CSN1C_VAL1(1), /* (ID:0358:125628:125643) Label=<GEA3> LabelId=35 */
	/* 000133 */ CSN1C_LABEL_A, CSN1C_VAL1(109), CSN1C_VAL1(1), /* (ID:0362:125643:125658) Label=<GEA4> LabelId=36 */
	/* 000136 */ CSN1C_LABEL_A, CSN1C_VAL1(112), CSN1C_VAL1(1), /* (ID:0366:125658:125673) Label=<GEA5> LabelId=37 */
	/* 000139 */ CSN1C_LABEL_A, CSN1C_VAL1(115), CSN1C_VAL1(1), /* (ID:0370:125673:125688) Label=<GEA6> LabelId=38 */
	/* 000142 */ CSN1C_LABEL_A, CSN1C_VAL1(118), CSN1C_VAL1(1), /* (ID:0374:125688:125702) Label=<GEA7> LabelId=39 */
	/* 000145 */ CSN1C_LABEL_END, CSN1C_VAL2(194),        /* (ID:0344:125578:125707) Label=<GEA> Terminal=<0> */
	/* 000148 */ CSN1C_CHOICE_END,
	/* 000149 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'APNAggregateMaxBitRate'
		DEFINITION FIELD-ID: 3  COMPLEXITY: 40
		SOURCE: ./TS_24.301_core_R13.src, 2838
	-----------------------------------------------------------------*/
	/* 000150 */ CSN1C_LABEL_A, CSN1C_VAL1(121), CSN1C_VAL1(8), /* (ID:0382:126432:126466) Label=<APN_AMBRDownlink> LabelId=40 */
	/* 000153 */ CSN1C_LABEL_A, CSN1C_VAL1(124), CSN1C_VAL1(8), /* (ID:0386:126466:126500) Label=<APN_AMBRUplink> LabelId=41 */
	/* 000156 */ CSN1C_CHOICE_NODE(0,32),                 /* (ID:0391:126533:126711) Truncable concatenation, entry 0, jump to 188 */
	/* 000158 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(254),      /* (ID:0392:126533:126622) Label=<ext> Terminal=<0> LabelId=42 */
	/* 000161 */ CSN1C_LABEL_A, CSN1C_VAL2(130), CSN1C_VAL1(8), /* (ID:0397:126545:126581) Label=<APN_AMBRDownlinkExt> LabelId=43 */
	/* 000165 */ CSN1C_LABEL_A, CSN1C_VAL2(133), CSN1C_VAL1(8), /* (ID:0401:126581:126616) Label=<APN_AMBRUplinkExt> LabelId=44 */
	/* 000169 */ CSN1C_LABEL_END, CSN1C_VAL2(254),        /* (ID:0392:126533:126622) Label=<ext> Terminal=<0> */
	/* 000172 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0391:126533:126711) Truncable concatenation, entry 1 */
	/* 000173 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(272),      /* (ID:0405:126622:126711) Label=<ext2> Terminal=<0> LabelId=45 */
	/* 000176 */ CSN1C_LABEL_A, CSN1C_VAL2(139), CSN1C_VAL1(8), /* (ID:0410:126635:126671) Label=<APN_AMBRDownlinkExt2> LabelId=46 */
	/* 000180 */ CSN1C_LABEL_A, CSN1C_VAL2(142), CSN1C_VAL1(8), /* (ID:0414:126671:126706) Label=<APN_AMBRUplinkExt2> LabelId=47 */
	/* 000184 */ CSN1C_LABEL_END, CSN1C_VAL2(272),        /* (ID:0405:126622:126711) Label=<ext2> Terminal=<0> */
	/* 000187 */ CSN1C_CHOICE_END,
	/* 000188 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EPS_QOS'
		DEFINITION FIELD-ID: 4  COMPLEXITY: 73
		SOURCE: ./TS_24.301_core_R13.src, 2859
	-----------------------------------------------------------------*/
	/* 000189 */ CSN1C_LABEL_A, CSN1C_VAL2(145), CSN1C_VAL1(8), /* (ID:0422:126847:126863) Label=<QCI> LabelId=48 */
	/* 000193 */ CSN1C_CHOICE_NODE(0,71),                 /* (ID:0427:126868:127522) Truncable concatenation, entry 0, jump to 264 */
	/* 000195 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(296),      /* (ID:0428:126868:127084) Label=<basic> Terminal=<0> LabelId=49 */
	/* 000198 */ CSN1C_LABEL_A, CSN1C_VAL2(151), CSN1C_VAL1(8), /* (ID:0433:126887:126934) Label=<MaximumBitRateForUplink> LabelId=50 */
	/* 000202 */ CSN1C_LABEL_A, CSN1C_VAL2(154), CSN1C_VAL1(8), /* (ID:0437:126934:126981) Label=<MaximumBitRateForDownlink> LabelId=51 */
	/* 000206 */ CSN1C_LABEL_A, CSN1C_VAL2(157), CSN1C_VAL1(8), /* (ID:0441:126981:127028) Label=<GuaranteedBitRateForUplink> LabelId=52 */
	/* 000210 */ CSN1C_LABEL_A, CSN1C_VAL2(160), CSN1C_VAL1(8), /* (ID:0445:127028:127074) Label=<GuaranteedBitRateForDownlink> LabelId=53 */
	/* 000214 */ CSN1C_LABEL_END, CSN1C_VAL2(296),        /* (ID:0428:126868:127084) Label=<basic> Terminal=<0> */
	/* 000217 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0427:126868:127522) Truncable concatenation, entry 1 */
	/* 000218 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(326),      /* (ID:0449:127084:127303) Label=<extended> Terminal=<0> LabelId=54 */
	/* 000221 */ CSN1C_LABEL_A, CSN1C_VAL2(166), CSN1C_VAL1(8), /* (ID:0454:127106:127153) Label=<MaximumBitRateForUplinkExt> LabelId=55 */
	/* 000225 */ CSN1C_LABEL_A, CSN1C_VAL2(169), CSN1C_VAL1(8), /* (ID:0458:127153:127200) Label=<MaximumBitRateForDownlinkExt> LabelId=56 */
	/* 000229 */ CSN1C_LABEL_A, CSN1C_VAL2(172), CSN1C_VAL1(8), /* (ID:0462:127200:127247) Label=<GuaranteedBitRateForUplinkExt> LabelId=57 */
	/* 000233 */ CSN1C_LABEL_A, CSN1C_VAL2(175), CSN1C_VAL1(8), /* (ID:0466:127247:127293) Label=<GuaranteedBitRateForDownlinkExt> LabelId=58 */
	/* 000237 */ CSN1C_LABEL_END, CSN1C_VAL2(326),        /* (ID:0449:127084:127303) Label=<extended> Terminal=<0> */
	/* 000240 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0427:126868:127522) Truncable concatenation, entry 2 */
	/* 000241 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(356),      /* (ID:0470:127303:127522) Label=<extended2> Terminal=<0> LabelId=59 */
	/* 000244 */ CSN1C_LABEL_A, CSN1C_VAL2(181), CSN1C_VAL1(8), /* (ID:0475:127326:127373) Label=<MaximumBitRateForUplinkExt> LabelId=55 */
	/* 000248 */ CSN1C_LABEL_A, CSN1C_VAL2(184), CSN1C_VAL1(8), /* (ID:0479:127373:127420) Label=<MaximumBitRateForDownlinkExt> LabelId=56 */
	/* 000252 */ CSN1C_LABEL_A, CSN1C_VAL2(187), CSN1C_VAL1(8), /* (ID:0483:127420:127467) Label=<GuaranteedBitRateForUplinkExt> LabelId=57 */
	/* 000256 */ CSN1C_LABEL_A, CSN1C_VAL2(190), CSN1C_VAL1(8), /* (ID:0487:127467:127513) Label=<GuaranteedBitRateForDownlinkExt> LabelId=58 */
	/* 000260 */ CSN1C_LABEL_END, CSN1C_VAL2(356),        /* (ID:0470:127303:127522) Label=<extended2> Terminal=<0> */
	/* 000263 */ CSN1C_CHOICE_END,
	/* 000264 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'A5_CM3_bits'
		DEFINITION FIELD-ID: 6  COMPLEXITY: 18
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 389
	-----------------------------------------------------------------*/
	/* 000265 */ CSN1C_LABEL_A, CSN1C_VAL2(193), CSN1C_VAL1(1), /* (ID:0941:147810:147825) Label=<A5_7> LabelId=60 */
	/* 000269 */ CSN1C_LABEL_A, CSN1C_VAL2(198), CSN1C_VAL1(1), /* (ID:0945:147825:147840) Label=<A5_6> LabelId=61 */
	/* 000273 */ CSN1C_LABEL_A, CSN1C_VAL2(203), CSN1C_VAL1(1), /* (ID:0949:147840:147855) Label=<A5_5> LabelId=62 */
	/* 000277 */ CSN1C_LABEL_A, CSN1C_VAL2(208), CSN1C_VAL1(1), /* (ID:0953:147855:147871) Label=<A5_4> LabelId=63 */
	/* 000281 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'epsQualityOfServ'
		DEFINITION FIELD-ID: 18  COMPLEXITY: 136
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 957
	-----------------------------------------------------------------*/
	/* 000282 */ CSN1C_BIT_A(2),                          /* (ID:1312:185299:185300) */
	/* 000283 */ CSN1C_LABEL_A, CSN1C_VAL2(213), CSN1C_VAL1(3), /* (ID:1162:165000:165216) Label=<DelayClass> LabelId=64 */
	/* 000287 */ CSN1C_LABEL_A, CSN1C_VAL2(216), CSN1C_VAL1(3), /* (ID:1166:165216:165685) Label=<ReliabilityClass> LabelId=65 */
	/* 000291 */ CSN1C_LABEL_A, CSN1C_VAL2(219), CSN1C_VAL1(4), /* (ID:1170:165685:166097) Label=<PeakThroughput> LabelId=66 */
	/* 000295 */ CSN1C_BIT_A(1),                          /* (ID:1312:185299:185300) */
	/* 000296 */ CSN1C_LABEL_A, CSN1C_VAL2(222), CSN1C_VAL1(3), /* (ID:1175:166112:166309) Label=<PrecedenceClass> LabelId=67 */
	/* 000300 */ CSN1C_BIT_A(3),                          /* (ID:1312:185299:185300) */
	/* 000301 */ CSN1C_LABEL_A, CSN1C_VAL2(225), CSN1C_VAL1(5), /* (ID:1180:166328:167013) Label=<MeanThroughput> LabelId=68 */
	/* 000305 */ CSN1C_LABEL_A, CSN1C_VAL2(228), CSN1C_VAL1(3), /* (ID:1184:167013:167235) Label=<TrafficClass> LabelId=69 */
	/* 000309 */ CSN1C_LABEL_A, CSN1C_VAL2(231), CSN1C_VAL1(2), /* (ID:1188:167235:167417) Label=<DeliveryOrder> LabelId=70 */
	/* 000313 */ CSN1C_LABEL_A, CSN1C_VAL2(234), CSN1C_VAL1(3), /* (ID:1192:167417:167685) Label=<DeliveryOfErroneusSDU> LabelId=71 */
	/* 000317 */ CSN1C_LABEL_A, CSN1C_VAL2(237), CSN1C_VAL1(8), /* (ID:1196:167685:167906) Label=<MaximumSDUSize> LabelId=72 */
	/* 000321 */ CSN1C_LABEL_A, CSN1C_VAL2(240), CSN1C_VAL1(8), /* (ID:1200:167906:168637) Label=<MaximumBitRateForUplink> LabelId=73 */
	/* 000325 */ CSN1C_LABEL_A, CSN1C_VAL2(243), CSN1C_VAL1(8), /* (ID:1204:168637:169370) Label=<MaximumBitRateForDownlink> LabelId=74 */
	/* 000329 */ CSN1C_LABEL_A, CSN1C_VAL2(246), CSN1C_VAL1(4), /* (ID:1208:169370:169674) Label=<ResidualBER> LabelId=75 */
	/* 000333 */ CSN1C_LABEL_A, CSN1C_VAL2(249), CSN1C_VAL1(4), /* (ID:1212:169674:169936) Label=<SDUErrorRatio> LabelId=76 */
	/* 000337 */ CSN1C_LABEL_A, CSN1C_VAL2(252), CSN1C_VAL1(6), /* (ID:1216:169936:169962) Label=<TransderDelay> LabelId=77 */
	/* 000341 */ CSN1C_LABEL_A, CSN1C_VAL2(255), CSN1C_VAL1(2), /* (ID:1220:169962:170165) Label=<TrafficHandlingPriority> LabelId=78 */
	/* 000345 */ CSN1C_LABEL_A, CSN1C_VAL2(258), CSN1C_VAL1(8), /* (ID:1224:170165:170221) Label=<GuaranteedBitRateForUplink> LabelId=79 */
	/* 000349 */ CSN1C_LABEL_A, CSN1C_VAL2(261), CSN1C_VAL1(8), /* (ID:1228:170221:170279) Label=<GuaranteedBitRateForDownlink> LabelId=80 */
	/* 000353 */ CSN1C_BIT_A(3),                          /* (ID:1312:185299:185300) */
	/* 000354 */ CSN1C_LABEL_A, CSN1C_VAL2(264), CSN1C_VAL1(1), /* (ID:1233:170298:170438) Label=<SignalingIndication> LabelId=81 */
	/* 000358 */ CSN1C_LABEL_A, CSN1C_VAL2(267), CSN1C_VAL1(4), /* (ID:1237:170438:170537) Label=<SourceStatisticsDescriptor> LabelId=82 */
	/* 000362 */ CSN1C_CHOICE_NODE(0,62),                 /* (ID:1242:170561:171057) Truncable concatenation, entry 0, jump to 424 */
	/* 000364 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(540),      /* (ID:1243:170561:170691) Label=<downlink> Terminal=<0> LabelId=83 */
	/* 000367 */ CSN1C_LABEL_A, CSN1C_VAL2(273), CSN1C_VAL1(8), /* (ID:1248:170578:170621) Label=<MaximumBitRateForDownlinkExt> LabelId=84 */
	/* 000371 */ CSN1C_LABEL_A, CSN1C_VAL2(276), CSN1C_VAL1(8), /* (ID:1252:170621:170666) Label=<GuaranteedBitRateForDownlinkExt> LabelId=85 */
	/* 000375 */ CSN1C_LABEL_END, CSN1C_VAL2(540),        /* (ID:1243:170561:170691) Label=<downlink> Terminal=<0> */
	/* 000378 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1242:170561:171057) Truncable concatenation, entry 1 */
	/* 000379 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(558),      /* (ID:1256:170691:170815) Label=<uplink> Terminal=<0> LabelId=86 */
	/* 000382 */ CSN1C_LABEL_A, CSN1C_VAL2(282), CSN1C_VAL1(8), /* (ID:1261:170706:170747) Label=<MaximumBitRateForUplinkExt> LabelId=87 */
	/* 000386 */ CSN1C_LABEL_A, CSN1C_VAL2(285), CSN1C_VAL1(8), /* (ID:1265:170747:170790) Label=<GuaranteedBitRateForUplinkExt> LabelId=88 */
	/* 000390 */ CSN1C_LABEL_END, CSN1C_VAL2(558),        /* (ID:1256:170691:170815) Label=<uplink> Terminal=<0> */
	/* 000393 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1242:170561:171057) Truncable concatenation, entry 2 */
	/* 000394 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(576),      /* (ID:1269:170815:170949) Label=<ext2downlink> Terminal=<0> LabelId=89 */
	/* 000397 */ CSN1C_LABEL_A, CSN1C_VAL2(291), CSN1C_VAL1(8), /* (ID:1274:170836:170879) Label=<MaximumBitRateForDownlinkExt> LabelId=84 */
	/* 000401 */ CSN1C_LABEL_A, CSN1C_VAL2(294), CSN1C_VAL1(8), /* (ID:1278:170879:170924) Label=<GuaranteedBitRateForDownlinkExt> LabelId=85 */
	/* 000405 */ CSN1C_LABEL_END, CSN1C_VAL2(576),        /* (ID:1269:170815:170949) Label=<ext2downlink> Terminal=<0> */
	/* 000408 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1242:170561:171057) Truncable concatenation, entry 3 */
	/* 000409 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(594),      /* (ID:1282:170949:171057) Label=<ext2uplink> Terminal=<0> LabelId=90 */
	/* 000412 */ CSN1C_LABEL_A, CSN1C_VAL2(300), CSN1C_VAL1(8), /* (ID:1287:170968:171009) Label=<MaximumBitRateForUplinkExt> LabelId=87 */
	/* 000416 */ CSN1C_LABEL_A, CSN1C_VAL2(303), CSN1C_VAL1(8), /* (ID:1291:171009:171052) Label=<GuaranteedBitRateForUplinkExt> LabelId=88 */
	/* 000420 */ CSN1C_LABEL_END, CSN1C_VAL2(594),        /* (ID:1282:170949:171057) Label=<ext2uplink> Terminal=<0> */
	/* 000423 */ CSN1C_CHOICE_END,
	/* 000424 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_padding'
		DEFINITION FIELD-ID: 23  COMPLEXITY: 9
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1508
	-----------------------------------------------------------------*/
	/* 000425 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(0), /* (ID:1317:185325:185332) When decoding infinite loop; at the end jump to 440 */
	/* 000430 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1317:185325:185332) Send construction; if encoding, jump to 437 */
	/* 000434 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 000435 */ CSN1C_GOTO(3),                           /* (ID:1317:185325:185332) skip the encode part and jump to 438 */
	/* 000437 */ CSN1C_BIT_L,                             /* (ID:1323:185331:185332) */
	/* 000438 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1317:185325:185332) Loop back to 430 */
	/* 000440 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'zero_padding'
		DEFINITION FIELD-ID: 24  COMPLEXITY: 9
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 1509
	-----------------------------------------------------------------*/
	/* 000441 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(0), /* (ID:1326:185413:185420) When decoding infinite loop; at the end jump to 456 */
	/* 000446 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1326:185413:185420) Send construction; if encoding, jump to 453 */
	/* 000450 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 000451 */ CSN1C_GOTO(3),                           /* (ID:1326:185413:185420) skip the encode part and jump to 454 */
	/* 000453 */ CSN1C_BIT_0,                             /* (ID:1332:185419:185420) */
	/* 000454 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1326:185413:185420) Loop back to 446 */
	/* 000456 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'epsClassmark3Value'
		DEFINITION FIELD-ID: 5  COMPLEXITY: 448
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 272
	-----------------------------------------------------------------*/
	/* 000457 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 457, node 1, jump to 462 */
	/* 000459 */ CSN1C_BIT_L,                             /* (ID:1307:185276:185277) */
	/* 000460 */ CSN1C_GOTO(8),                           /* (ID:1305:185276:185279) jump at 468 */
	/* 000462 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 457, node 2, jump to 467 */
	/* 000464 */ CSN1C_BIT_H,                             /* (ID:1309:185278:185279) */
	/* 000465 */ CSN1C_GOTO(3),                           /* (ID:1305:185276:185279) jump at 468 */
	/* 000467 */ CSN1C_BACKTRACK,                         /* (ID:1305:185276:185279) Failure of choice begun at 457 */
	/* 000468 */ CSN1C_CHOICE_END,                        /* (ID:1305:185276:185279) End of choice begun at 457 */
	/* 000469 */ CSN1C_CHOICE_NODE(0,35),                 /* (ID:0494:143177:143530) VBIT choice at 469, node 1, jump to 504 */
	/* 000471 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(613),      /* (ID:0506:143236:143281) Label=<Multiband_supported> Terminal=<1> LabelId=91 */
	/* 000474 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0509:143262:143272) FBIT choice at 474, node 1, jump to 480 */
	/* 000476 */ CSN1C_VALUE, CSN1C_VAL1(82),             /* (ID:0511:143262:143263..0513:143264:143266) Bit string '101' */
	/* 000478 */ CSN1C_GOTO(9),                           /* (ID:0509:143262:143272) jump at 487 */
	/* 000480 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0509:143262:143272) FBIT choice at 474, node 2, jump to 486 */
	/* 000482 */ CSN1C_VALUE, CSN1C_VAL1(98),             /* (ID:0515:143268:143269..0517:143270:143272) Bit string '110' */
	/* 000484 */ CSN1C_GOTO(3),                           /* (ID:0509:143262:143272) jump at 487 */
	/* 000486 */ CSN1C_BACKTRACK,                         /* (ID:0509:143262:143272) Failure of choice begun at 474 */
	/* 000487 */ CSN1C_CHOICE_END,                        /* (ID:0509:143262:143272) End of choice begun at 474 */
	/* 000488 */ CSN1C_LABEL_END, CSN1C_VAL2(613),        /* (ID:0506:143236:143281) Label=<Multiband_supported> Terminal=<1> */
	/* 000491 */ CSN1C_GOSUB, CSN1C_VAL2(265),            /* (ID:0518:143281:143301) Reference to 'A5_CM3_bits' */
	/* 000494 */ CSN1C_LABEL_A, CSN1C_VAL2(309), CSN1C_VAL1(4), /* (ID:0519:143301:143348) Label=<Associated_Radio_Capability_2> LabelId=92 */
	/* 000498 */ CSN1C_LABEL_A, CSN1C_VAL2(312), CSN1C_VAL1(4), /* (ID:0523:143348:143393) Label=<Associated_Radio_Capability_1> LabelId=93 */
	/* 000502 */ CSN1C_GOTO(68),                          /* (ID:0494:143177:143530) jump at 570 */
	/* 000504 */ CSN1C_CHOICE_NODE(0,56),                 /* (ID:0494:143177:143530) VBIT choice at 469, node 2, jump to 560 */
	/* 000506 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(631),      /* (ID:0528:143395:143446) Label=<Multiband_supported> Terminal=<1> LabelId=91 */
	/* 000509 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0531:143421:143437) FBIT choice at 509, node 1, jump to 515 */
	/* 000511 */ CSN1C_VALUE, CSN1C_VAL1(18),             /* (ID:0533:143421:143422..0535:143423:143425) Bit string '001' */
	/* 000513 */ CSN1C_GOTO(15),                          /* (ID:0531:143421:143437) jump at 528 */
	/* 000515 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0531:143421:143437) FBIT choice at 509, node 2, jump to 521 */
	/* 000517 */ CSN1C_VALUE, CSN1C_VAL1(34),             /* (ID:0537:143427:143428..0539:143429:143431) Bit string '010' */
	/* 000519 */ CSN1C_GOTO(9),                           /* (ID:0531:143421:143437) jump at 528 */
	/* 000521 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0531:143421:143437) FBIT choice at 509, node 3, jump to 527 */
	/* 000523 */ CSN1C_VALUE, CSN1C_VAL1(66),             /* (ID:0541:143433:143434..0543:143435:143437) Bit string '100' */
	/* 000525 */ CSN1C_GOTO(3),                           /* (ID:0531:143421:143437) jump at 528 */
	/* 000527 */ CSN1C_BACKTRACK,                         /* (ID:0531:143421:143437) Failure of choice begun at 509 */
	/* 000528 */ CSN1C_CHOICE_END,                        /* (ID:0531:143421:143437) End of choice begun at 509 */
	/* 000529 */ CSN1C_LABEL_END, CSN1C_VAL2(631),        /* (ID:0528:143395:143446) Label=<Multiband_supported> Terminal=<1> */
	/* 000532 */ CSN1C_GOSUB, CSN1C_VAL2(265),            /* (ID:0544:143446:143466) Reference to 'A5_CM3_bits' */
	/* 000535 */ CSN1C_LOOP_BEGIN_FIXED, CSN1C_VAL3(39), CSN1C_VAL1(4), /* (ID:1305:185276:185279) Loop start, exit to 554 */
	/* 000540 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 540, node 1, jump to 545 */
	/* 000542 */ CSN1C_BIT_L,                             /* (ID:1307:185276:185277) */
	/* 000543 */ CSN1C_GOTO(8),                           /* (ID:1305:185276:185279) jump at 551 */
	/* 000545 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1305:185276:185279) FBIT choice at 540, node 2, jump to 550 */
	/* 000547 */ CSN1C_BIT_H,                             /* (ID:1309:185278:185279) */
	/* 000548 */ CSN1C_GOTO(3),                           /* (ID:1305:185276:185279) jump at 551 */
	/* 000550 */ CSN1C_BACKTRACK,                         /* (ID:1305:185276:185279) Failure of choice begun at 540 */
	/* 000551 */ CSN1C_CHOICE_END,                        /* (ID:1305:185276:185279) End of choice begun at 540 */
	/* 000552 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(12),        /* (ID:1305:185276:185279) Loop back to 540 */
	/* 000554 */ CSN1C_LABEL_A, CSN1C_VAL2(318), CSN1C_VAL1(4), /* (ID:0546:143487:143530) Label=<Associated_Radio_Capability_1> LabelId=93 */
	/* 000558 */ CSN1C_GOTO(12),                          /* (ID:0494:143177:143530) jump at 570 */
	/* 000560 */ CSN1C_LABEL_VALUE, CSN1C_VAL2(321), CSN1C_VAL1(2), /* (ID:0496:143177:143215) Label=<Multiband_supported> LabelId=321 */
	/* 000564 */ CSN1C_GOSUB, CSN1C_VAL2(265),            /* (ID:0504:143215:143234) Reference to 'A5_CM3_bits' */
	/* 000567 */ CSN1C_GOTO(4),                           /* (ID:0494:143177:143530) jump at 572 */
	/* 000569 */ CSN1C_BACKTRACK,                         /* (ID:0494:143177:143530) Failure of choice begun at 469 */
	/* 000570 */ CSN1C_CHOICE_END,                        /* (ID:0494:143177:143530) End of choice begun at 469 */
	/* 000571 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0550:143536:143556) VBIT choice at 571, node 1, jump to 580 */
	/* 000573 */ CSN1C_BIT_1,                             /* (ID:0554:143540:143542) */
	/* 000574 */ CSN1C_LABEL_A, CSN1C_VAL2(324), CSN1C_VAL1(3), /* (ID:0959:147899:147951) Label=<R_GSM_band_Associated_Radio_Capability> LabelId=94 */
	/* 000578 */ CSN1C_GOTO(8),                           /* (ID:0550:143536:143556) jump at 586 */
	/* 000580 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0550:143536:143556) FBIT choice at 571, node 2, jump to 585 */
	/* 000582 */ CSN1C_BIT_0,                             /* (ID:0552:143536:143538) */
	/* 000583 */ CSN1C_GOTO(3),                           /* (ID:0550:143536:143556) jump at 586 */
	/* 000585 */ CSN1C_BACKTRACK,                         /* (ID:0550:143536:143556) Failure of choice begun at 571 */
	/* 000586 */ CSN1C_CHOICE_END,                        /* (ID:0550:143536:143556) End of choice begun at 571 */
	/* 000587 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0556:143562:143600) VBIT choice at 587, node 1, jump to 596 */
	/* 000589 */ CSN1C_BIT_1,                             /* (ID:0560:143566:143568) */
	/* 000590 */ CSN1C_LABEL_A, CSN1C_VAL2(329), CSN1C_VAL1(5), /* (ID:0965:148000:148037) Label=<HSCSD_Multi_Slot_Class> LabelId=95 */
	/* 000594 */ CSN1C_GOTO(8),                           /* (ID:0556:143562:143600) jump at 602 */
	/* 000596 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0556:143562:143600) FBIT choice at 587, node 2, jump to 601 */
	/* 000598 */ CSN1C_BIT_0,                             /* (ID:0558:143562:143564) */
	/* 000599 */ CSN1C_GOTO(3),                           /* (ID:0556:143562:143600) jump at 602 */
	/* 000601 */ CSN1C_BACKTRACK,                         /* (ID:0556:143562:143600) Failure of choice begun at 587 */
	/* 000602 */ CSN1C_CHOICE_END,                        /* (ID:0556:143562:143600) End of choice begun at 587 */
	/* 000603 */ CSN1C_LABEL_A, CSN1C_VAL2(334), CSN1C_VAL1(1), /* (ID:0562:143604:143630) Label=<UCS2_treatment> LabelId=96 */
	/* 000607 */ CSN1C_LABEL_A, CSN1C_VAL2(337), CSN1C_VAL1(1), /* (ID:0566:143630:143674) Label=<Extended_Measurement_Capability> LabelId=97 */
	/* 000611 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0570:143676:143712) VBIT choice at 611, node 1, jump to 624 */
	/* 000613 */ CSN1C_BIT_1,                             /* (ID:0574:143680:143682) */
	/* 000614 */ CSN1C_LABEL_A, CSN1C_VAL2(340), CSN1C_VAL1(4), /* (ID:0971:148084:148110) Label=<SMS_VALUE> LabelId=98 */
	/* 000618 */ CSN1C_LABEL_A, CSN1C_VAL2(345), CSN1C_VAL1(4), /* (ID:0975:148110:148133) Label=<SM_VALUE> LabelId=99 */
	/* 000622 */ CSN1C_GOTO(8),                           /* (ID:0570:143676:143712) jump at 630 */
	/* 000624 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0570:143676:143712) FBIT choice at 611, node 2, jump to 629 */
	/* 000626 */ CSN1C_BIT_0,                             /* (ID:0572:143676:143678) */
	/* 000627 */ CSN1C_GOTO(3),                           /* (ID:0570:143676:143712) jump at 630 */
	/* 000629 */ CSN1C_BACKTRACK,                         /* (ID:0570:143676:143712) Failure of choice begun at 611 */
	/* 000630 */ CSN1C_CHOICE_END,                        /* (ID:0570:143676:143712) End of choice begun at 611 */
	/* 000631 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0576:143718:143761) VBIT choice at 631, node 1, jump to 640 */
	/* 000633 */ CSN1C_BIT_1,                             /* (ID:0580:143722:143724) */
	/* 000634 */ CSN1C_LABEL_A, CSN1C_VAL2(350), CSN1C_VAL1(5), /* (ID:0981:148187:148222) Label=<MS_Positioning_Method> LabelId=100 */
	/* 000638 */ CSN1C_GOTO(8),                           /* (ID:0576:143718:143761) jump at 646 */
	/* 000640 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0576:143718:143761) FBIT choice at 631, node 2, jump to 645 */
	/* 000642 */ CSN1C_BIT_0,                             /* (ID:0578:143718:143720) */
	/* 000643 */ CSN1C_GOTO(3),                           /* (ID:0576:143718:143761) jump at 646 */
	/* 000645 */ CSN1C_BACKTRACK,                         /* (ID:0576:143718:143761) Failure of choice begun at 631 */
	/* 000646 */ CSN1C_CHOICE_END,                        /* (ID:0576:143718:143761) End of choice begun at 631 */
	/* 000647 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0582:143767:143804) VBIT choice at 647, node 1, jump to 656 */
	/* 000649 */ CSN1C_BIT_1,                             /* (ID:0586:143771:143773) */
	/* 000650 */ CSN1C_LABEL_A, CSN1C_VAL2(355), CSN1C_VAL1(5), /* (ID:0987:148270:148305) Label=<ECSD_Multi_Slot_Class> LabelId=101 */
	/* 000654 */ CSN1C_GOTO(8),                           /* (ID:0582:143767:143804) jump at 662 */
	/* 000656 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0582:143767:143804) FBIT choice at 647, node 2, jump to 661 */
	/* 000658 */ CSN1C_BIT_0,                             /* (ID:0584:143767:143769) */
	/* 000659 */ CSN1C_GOTO(3),                           /* (ID:0582:143767:143804) jump at 662 */
	/* 000661 */ CSN1C_BACKTRACK,                         /* (ID:0582:143767:143804) Failure of choice begun at 647 */
	/* 000662 */ CSN1C_CHOICE_END,                        /* (ID:0582:143767:143804) End of choice begun at 647 */
	/* 000663 */ CSN1C_CHOICE_NODE(0,41),                 /* (ID:0588:143810:143833) VBIT choice at 663, node 1, jump to 704 */
	/* 000665 */ CSN1C_BIT_1,                             /* (ID:0592:143814:143816) */
	/* 000666 */ CSN1C_LABEL_A, CSN1C_VAL2(360), CSN1C_VAL1(1), /* (ID:0993:148338:148372) Label=<Modulation_Capability> LabelId=102 */
	/* 000670 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0997:148374:148420) VBIT choice at 670, node 1, jump to 679 */
	/* 000672 */ CSN1C_BIT_1,                             /* (ID:1001:148378:148380) */
	/* 000673 */ CSN1C_LABEL_A, CSN1C_VAL2(365), CSN1C_VAL1(2), /* (ID:1002:148380:148420) Label=<_8_PSK_RF_Power_Capability_1> LabelId=103 */
	/* 000677 */ CSN1C_GOTO(8),                           /* (ID:0997:148374:148420) jump at 685 */
	/* 000679 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0997:148374:148420) FBIT choice at 670, node 2, jump to 684 */
	/* 000681 */ CSN1C_BIT_0,                             /* (ID:0999:148374:148376) */
	/* 000682 */ CSN1C_GOTO(3),                           /* (ID:0997:148374:148420) jump at 685 */
	/* 000684 */ CSN1C_BACKTRACK,                         /* (ID:0997:148374:148420) Failure of choice begun at 670 */
	/* 000685 */ CSN1C_CHOICE_END,                        /* (ID:0997:148374:148420) End of choice begun at 670 */
	/* 000686 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1006:148426:148472) VBIT choice at 686, node 1, jump to 695 */
	/* 000688 */ CSN1C_BIT_1,                             /* (ID:1010:148430:148432) */
	/* 000689 */ CSN1C_LABEL_A, CSN1C_VAL2(370), CSN1C_VAL1(2), /* (ID:1011:148432:148472) Label=<_8_PSK_RF_Power_Capability_2> LabelId=104 */
	/* 000693 */ CSN1C_GOTO(8),                           /* (ID:1006:148426:148472) jump at 701 */
	/* 000695 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1006:148426:148472) FBIT choice at 686, node 2, jump to 700 */
	/* 000697 */ CSN1C_BIT_0,                             /* (ID:1008:148426:148428) */
	/* 000698 */ CSN1C_GOTO(3),                           /* (ID:1006:148426:148472) jump at 701 */
	/* 000700 */ CSN1C_BACKTRACK,                         /* (ID:1006:148426:148472) Failure of choice begun at 686 */
	/* 000701 */ CSN1C_CHOICE_END,                        /* (ID:1006:148426:148472) End of choice begun at 686 */
	/* 000702 */ CSN1C_GOTO(8),                           /* (ID:0588:143810:143833) jump at 710 */
	/* 000704 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0588:143810:143833) FBIT choice at 663, node 2, jump to 709 */
	/* 000706 */ CSN1C_BIT_0,                             /* (ID:0590:143810:143812) */
	/* 000707 */ CSN1C_GOTO(3),                           /* (ID:0588:143810:143833) jump at 710 */
	/* 000709 */ CSN1C_BACKTRACK,                         /* (ID:0588:143810:143833) Failure of choice begun at 663 */
	/* 000710 */ CSN1C_CHOICE_END,                        /* (ID:0588:143810:143833) End of choice begun at 663 */
	/* 000711 */ CSN1C_CHOICE_NODE(0,35),                 /* (ID:0594:143839:144126) VBIT choice at 711, node 1, jump to 746 */
	/* 000713 */ CSN1C_BIT_1,                             /* (ID:0598:143843:143845) */
	/* 000714 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(751),      /* (ID:0599:143845:144078) Label=<GSM_400_Bands_Supported> Terminal=<1> LabelId=105 */
	/* 000717 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0602:144057:144070) FBIT choice at 717, node 1, jump to 723 */
	/* 000719 */ CSN1C_VALUE, CSN1C_VAL1(17),             /* (ID:0604:144057:144058..0605:144058:144060) Bit string '01' */
	/* 000721 */ CSN1C_GOTO(15),                          /* (ID:0602:144057:144070) jump at 736 */
	/* 000723 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0602:144057:144070) FBIT choice at 717, node 2, jump to 729 */
	/* 000725 */ CSN1C_VALUE, CSN1C_VAL1(33),             /* (ID:0607:144062:144063..0608:144063:144065) Bit string '10' */
	/* 000727 */ CSN1C_GOTO(9),                           /* (ID:0602:144057:144070) jump at 736 */
	/* 000729 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0602:144057:144070) FBIT choice at 717, node 3, jump to 735 */
	/* 000731 */ CSN1C_VALUE, CSN1C_VAL1(49),             /* (ID:0610:144067:144068..0611:144068:144070) Bit string '11' */
	/* 000733 */ CSN1C_GOTO(3),                           /* (ID:0602:144057:144070) jump at 736 */
	/* 000735 */ CSN1C_BACKTRACK,                         /* (ID:0602:144057:144070) Failure of choice begun at 717 */
	/* 000736 */ CSN1C_CHOICE_END,                        /* (ID:0602:144057:144070) End of choice begun at 717 */
	/* 000737 */ CSN1C_LABEL_END, CSN1C_VAL2(751),        /* (ID:0599:143845:144078) Label=<GSM_400_Bands_Supported> Terminal=<1> */
	/* 000740 */ CSN1C_LABEL_A, CSN1C_VAL2(378), CSN1C_VAL1(4), /* (ID:0612:144078:144126) Label=<GSM_400_Associated_Radio_Capability> LabelId=106 */
	/* 000744 */ CSN1C_GOTO(8),                           /* (ID:0594:143839:144126) jump at 752 */
	/* 000746 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0594:143839:144126) FBIT choice at 711, node 2, jump to 751 */
	/* 000748 */ CSN1C_BIT_0,                             /* (ID:0596:143839:143841) */
	/* 000749 */ CSN1C_GOTO(3),                           /* (ID:0594:143839:144126) jump at 752 */
	/* 000751 */ CSN1C_BACKTRACK,                         /* (ID:0594:143839:144126) Failure of choice begun at 711 */
	/* 000752 */ CSN1C_CHOICE_END,                        /* (ID:0594:143839:144126) End of choice begun at 711 */
	/* 000753 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0616:144134:144188) VBIT choice at 753, node 1, jump to 762 */
	/* 000755 */ CSN1C_BIT_1,                             /* (ID:0620:144138:144140) */
	/* 000756 */ CSN1C_LABEL_A, CSN1C_VAL2(381), CSN1C_VAL1(4), /* (ID:0621:144140:144188) Label=<GSM_850_Associated_Radio_Capability> LabelId=107 */
	/* 000760 */ CSN1C_GOTO(8),                           /* (ID:0616:144134:144188) jump at 768 */
	/* 000762 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0616:144134:144188) FBIT choice at 753, node 2, jump to 767 */
	/* 000764 */ CSN1C_BIT_0,                             /* (ID:0618:144134:144136) */
	/* 000765 */ CSN1C_GOTO(3),                           /* (ID:0616:144134:144188) jump at 768 */
	/* 000767 */ CSN1C_BACKTRACK,                         /* (ID:0616:144134:144188) Failure of choice begun at 753 */
	/* 000768 */ CSN1C_CHOICE_END,                        /* (ID:0616:144134:144188) End of choice begun at 753 */
	/* 000769 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0625:144194:144249) VBIT choice at 769, node 1, jump to 778 */
	/* 000771 */ CSN1C_BIT_1,                             /* (ID:0629:144198:144200) */
	/* 000772 */ CSN1C_LABEL_A, CSN1C_VAL2(384), CSN1C_VAL1(4), /* (ID:0630:144200:144249) Label=<GSM_1900_Associated_Radio_Capability> LabelId=108 */
	/* 000776 */ CSN1C_GOTO(8),                           /* (ID:0625:144194:144249) jump at 784 */
	/* 000778 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0625:144194:144249) FBIT choice at 769, node 2, jump to 783 */
	/* 000780 */ CSN1C_BIT_0,                             /* (ID:0627:144194:144196) */
	/* 000781 */ CSN1C_GOTO(3),                           /* (ID:0625:144194:144249) jump at 784 */
	/* 000783 */ CSN1C_BACKTRACK,                         /* (ID:0625:144194:144249) Failure of choice begun at 769 */
	/* 000784 */ CSN1C_CHOICE_END,                        /* (ID:0625:144194:144249) End of choice begun at 769 */
	/* 000785 */ CSN1C_LABEL_A, CSN1C_VAL2(387), CSN1C_VAL1(1), /* (ID:0634:144253:144309) Label=<UMTS_FDD_Radio_Access_Technology_Capability> LabelId=109 */
	/* 000789 */ CSN1C_LABEL_A, CSN1C_VAL2(390), CSN1C_VAL1(1), /* (ID:0638:144309:144375) Label=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=110 */
	/* 000793 */ CSN1C_LABEL_A, CSN1C_VAL2(393), CSN1C_VAL1(1), /* (ID:0642:144375:144434) Label=<CDMA_2000_Radio_Access_Technology_Capability> LabelId=111 */
	/* 000797 */ CSN1C_CHOICE_NODE(0,29),                 /* (ID:0646:144436:144563) VBIT choice at 797, node 1, jump to 826 */
	/* 000799 */ CSN1C_BIT_1,                             /* (ID:0650:144440:144442) */
	/* 000800 */ CSN1C_LABEL_A, CSN1C_VAL2(396), CSN1C_VAL1(2), /* (ID:0651:144442:144485) Label=<DTM_GPRS_Multi_Slot_Class> LabelId=112 */
	/* 000804 */ CSN1C_LABEL_A, CSN1C_VAL2(399), CSN1C_VAL1(1), /* (ID:0655:144485:144515) Label=<Single_Slot_DTM> LabelId=113 */
	/* 000808 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0659:144516:144561) VBIT choice at 808, node 1, jump to 817 */
	/* 000810 */ CSN1C_BIT_1,                             /* (ID:0663:144520:144521) */
	/* 000811 */ CSN1C_LABEL_A, CSN1C_VAL2(402), CSN1C_VAL1(2), /* (ID:0664:144521:144561) Label=<DTM_EGPRS_Multi_Slot_Class> LabelId=114 */
	/* 000815 */ CSN1C_GOTO(8),                           /* (ID:0659:144516:144561) jump at 823 */
	/* 000817 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0659:144516:144561) FBIT choice at 808, node 2, jump to 822 */
	/* 000819 */ CSN1C_BIT_0,                             /* (ID:0661:144516:144518) */
	/* 000820 */ CSN1C_GOTO(3),                           /* (ID:0659:144516:144561) jump at 823 */
	/* 000822 */ CSN1C_BACKTRACK,                         /* (ID:0659:144516:144561) Failure of choice begun at 808 */
	/* 000823 */ CSN1C_CHOICE_END,                        /* (ID:0659:144516:144561) End of choice begun at 808 */
	/* 000824 */ CSN1C_GOTO(8),                           /* (ID:0646:144436:144563) jump at 832 */
	/* 000826 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0646:144436:144563) FBIT choice at 797, node 2, jump to 831 */
	/* 000828 */ CSN1C_BIT_0,                             /* (ID:0648:144436:144438) */
	/* 000829 */ CSN1C_GOTO(3),                           /* (ID:0646:144436:144563) jump at 832 */
	/* 000831 */ CSN1C_BACKTRACK,                         /* (ID:0646:144436:144563) Failure of choice begun at 797 */
	/* 000832 */ CSN1C_CHOICE_END,                        /* (ID:0646:144436:144563) End of choice begun at 797 */
	/* 000833 */ CSN1C_CHOICE_NODE(0,397),                /* (ID:0668:144569:147737) VBIT choice at 833, node 1, jump to 1230 */
	/* 000835 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0672:144585:144615) VBIT choice at 835, node 1, jump to 844 */
	/* 000837 */ CSN1C_BIT_1,                             /* (ID:0676:144589:144591) */
	/* 000838 */ CSN1C_LABEL_A, CSN1C_VAL2(405), CSN1C_VAL1(4), /* (ID:1017:148514:148895) Label=<GSM_Band> LabelId=115 */
	/* 000842 */ CSN1C_GOTO(8),                           /* (ID:0672:144585:144615) jump at 850 */
	/* 000844 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0672:144585:144615) FBIT choice at 835, node 2, jump to 849 */
	/* 000846 */ CSN1C_BIT_0,                             /* (ID:0674:144585:144587) */
	/* 000847 */ CSN1C_GOTO(3),                           /* (ID:0672:144585:144615) jump at 850 */
	/* 000849 */ CSN1C_BACKTRACK,                         /* (ID:0672:144585:144615) Failure of choice begun at 835 */
	/* 000850 */ CSN1C_CHOICE_END,                        /* (ID:0672:144585:144615) End of choice begun at 835 */
	/* 000851 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0678:144656:144708) VBIT choice at 851, node 1, jump to 860 */
	/* 000853 */ CSN1C_BIT_1,                             /* (ID:0682:144660:144662) */
	/* 000854 */ CSN1C_LABEL_A, CSN1C_VAL2(410), CSN1C_VAL1(4), /* (ID:0683:144662:144708) Label=<GSM_750_Associated_Radio_Capability> LabelId=116 */
	/* 000858 */ CSN1C_GOTO(8),                           /* (ID:0678:144656:144708) jump at 866 */
	/* 000860 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0678:144656:144708) FBIT choice at 851, node 2, jump to 865 */
	/* 000862 */ CSN1C_BIT_0,                             /* (ID:0680:144656:144658) */
	/* 000863 */ CSN1C_GOTO(3),                           /* (ID:0678:144656:144708) jump at 866 */
	/* 000865 */ CSN1C_BACKTRACK,                         /* (ID:0678:144656:144708) Failure of choice begun at 851 */
	/* 000866 */ CSN1C_CHOICE_END,                        /* (ID:0678:144656:144708) End of choice begun at 851 */
	/* 000867 */ CSN1C_LABEL_A, CSN1C_VAL2(413), CSN1C_VAL1(1), /* (ID:0687:144716:144783) Label=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=117 */
	/* 000871 */ CSN1C_LABEL_A, CSN1C_VAL2(416), CSN1C_VAL1(1), /* (ID:0691:144783:144823) Label=<GERAN_Feature_Package_1> LabelId=118 */
	/* 000875 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0695:144825:145147) VBIT choice at 875, node 1, jump to 888 */
	/* 000877 */ CSN1C_BIT_1,                             /* (ID:0699:144829:144831) */
	/* 000878 */ CSN1C_LABEL_A, CSN1C_VAL2(419), CSN1C_VAL1(2), /* (ID:0700:144831:145098) Label=<Extended_DTM_GPRS_Multi_Slot_Class> LabelId=119 */
	/* 000882 */ CSN1C_LABEL_A, CSN1C_VAL2(422), CSN1C_VAL1(2), /* (ID:0704:145098:145147) Label=<Extended_DTM_EGPRS_Multi_Slot_Class> LabelId=120 */
	/* 000886 */ CSN1C_GOTO(8),                           /* (ID:0695:144825:145147) jump at 894 */
	/* 000888 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0695:144825:145147) FBIT choice at 875, node 2, jump to 893 */
	/* 000890 */ CSN1C_BIT_0,                             /* (ID:0697:144825:144827) */
	/* 000891 */ CSN1C_GOTO(3),                           /* (ID:0695:144825:145147) jump at 894 */
	/* 000893 */ CSN1C_BACKTRACK,                         /* (ID:0695:144825:145147) Failure of choice begun at 875 */
	/* 000894 */ CSN1C_CHOICE_END,                        /* (ID:0695:144825:145147) End of choice begun at 875 */
	/* 000895 */ CSN1C_CHOICE_NODE(0,329),                /* (ID:0708:145156:147712) VBIT choice at 895, node 1, jump to 1224 */
	/* 000897 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0712:145173:145218) VBIT choice at 897, node 1, jump to 906 */
	/* 000899 */ CSN1C_BIT_1,                             /* (ID:0716:145177:145179) */
	/* 000900 */ CSN1C_LABEL_A, CSN1C_VAL2(425), CSN1C_VAL1(2), /* (ID:0717:145179:145218) Label=<High_Multislot_Capability> LabelId=121 */
	/* 000904 */ CSN1C_GOTO(8),                           /* (ID:0712:145173:145218) jump at 912 */
	/* 000906 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0712:145173:145218) FBIT choice at 897, node 2, jump to 911 */
	/* 000908 */ CSN1C_BIT_0,                             /* (ID:0714:145173:145175) */
	/* 000909 */ CSN1C_GOTO(3),                           /* (ID:0712:145173:145218) jump at 912 */
	/* 000911 */ CSN1C_BACKTRACK,                         /* (ID:0712:145173:145218) Failure of choice begun at 897 */
	/* 000912 */ CSN1C_CHOICE_END,                        /* (ID:0712:145173:145218) End of choice begun at 897 */
	/* 000913 */ CSN1C_CHOICE_NODE(0,28),                 /* (ID:0721:145263:145300) VBIT choice at 913, node 1, jump to 941 */
	/* 000915 */ CSN1C_BIT_1,                             /* (ID:0725:145267:145269) */
	/* 000916 */ CSN1C_LABEL_A, CSN1C_VAL2(428), CSN1C_VAL1(4), /* (ID:1023:148944:149031) Label=<Length> LabelId=122 */
	/* 000920 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000922 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(1),
	/* 000924 */ CSN1C_LABEL_A, CSN1C_VAL2(433), CSN1C_VAL1(1), /* (ID:1028:149213:149244) Label=<FLO_Iu_Capability> LabelId=123 */
	/* 000928 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:1032:149244:149256) Infinite loop start, jump to 935 */
	/* 000932 */ CSN1C_BIT_A(1),                          /* (ID:1302:185254:185255) */
	/* 000933 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:1032:149244:149256) Loop back to 932 */
	/* 000935 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(2),
	/* 000937 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(3),
	/* 000939 */ CSN1C_GOTO(8),                           /* (ID:0721:145263:145300) jump at 947 */
	/* 000941 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0721:145263:145300) FBIT choice at 913, node 2, jump to 946 */
	/* 000943 */ CSN1C_BIT_0,                             /* (ID:0723:145263:145265) */
	/* 000944 */ CSN1C_GOTO(3),                           /* (ID:0721:145263:145300) jump at 947 */
	/* 000946 */ CSN1C_BACKTRACK,                         /* (ID:0721:145263:145300) Failure of choice begun at 913 */
	/* 000947 */ CSN1C_CHOICE_END,                        /* (ID:0721:145263:145300) End of choice begun at 913 */
	/* 000948 */ CSN1C_LABEL_A, CSN1C_VAL2(438), CSN1C_VAL1(1), /* (ID:0727:145381:145423) Label=<GERAN_Feature_Package_2> LabelId=124 */
	/* 000952 */ CSN1C_LABEL_A, CSN1C_VAL2(441), CSN1C_VAL1(2), /* (ID:0731:145423:145470) Label=<GMSK_Multislot_Power_Profile> LabelId=125 */
	/* 000956 */ CSN1C_LABEL_A, CSN1C_VAL2(444), CSN1C_VAL1(2), /* (ID:0735:145470:145522) Label=<_8_PSK_Multislot_Power_Profile> LabelId=126 */
	/* 000960 */ CSN1C_CHOICE_NODE(0,258),                /* (ID:0739:145523:147686) VBIT choice at 960, node 1, jump to 1218 */
	/* 000962 */ CSN1C_CHOICE_NODE(0,35),                 /* (ID:0743:145541:145680) VBIT choice at 962, node 1, jump to 997 */
	/* 000964 */ CSN1C_BIT_1,                             /* (ID:0747:145545:145547) */
	/* 000965 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(895),      /* (ID:0748:145547:145630) Label=<T_GSM_400_Bands_Supported> Terminal=<1> LabelId=127 */
	/* 000968 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0751:145579:145592) FBIT choice at 968, node 1, jump to 974 */
	/* 000970 */ CSN1C_VALUE, CSN1C_VAL1(17),             /* (ID:0753:145579:145580..0754:145580:145582) Bit string '01' */
	/* 000972 */ CSN1C_GOTO(15),                          /* (ID:0751:145579:145592) jump at 987 */
	/* 000974 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0751:145579:145592) FBIT choice at 968, node 2, jump to 980 */
	/* 000976 */ CSN1C_VALUE, CSN1C_VAL1(33),             /* (ID:0756:145584:145585..0757:145585:145587) Bit string '10' */
	/* 000978 */ CSN1C_GOTO(9),                           /* (ID:0751:145579:145592) jump at 987 */
	/* 000980 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0751:145579:145592) FBIT choice at 968, node 3, jump to 986 */
	/* 000982 */ CSN1C_VALUE, CSN1C_VAL1(49),             /* (ID:0759:145589:145590..0760:145590:145592) Bit string '11' */
	/* 000984 */ CSN1C_GOTO(3),                           /* (ID:0751:145579:145592) jump at 987 */
	/* 000986 */ CSN1C_BACKTRACK,                         /* (ID:0751:145579:145592) Failure of choice begun at 968 */
	/* 000987 */ CSN1C_CHOICE_END,                        /* (ID:0751:145579:145592) End of choice begun at 968 */
	/* 000988 */ CSN1C_LABEL_END, CSN1C_VAL2(895),        /* (ID:0748:145547:145630) Label=<T_GSM_400_Bands_Supported> Terminal=<1> */
	/* 000991 */ CSN1C_LABEL_A, CSN1C_VAL2(450), CSN1C_VAL1(4), /* (ID:0761:145630:145680) Label=<T_GSM_400_Associated_Radio_Capability> LabelId=128 */
	/* 000995 */ CSN1C_GOTO(8),                           /* (ID:0743:145541:145680) jump at 1003 */
	/* 000997 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0743:145541:145680) FBIT choice at 962, node 2, jump to 1002 */
	/* 000999 */ CSN1C_BIT_0,                             /* (ID:0745:145541:145543) */
	/* 001000 */ CSN1C_GOTO(3),                           /* (ID:0743:145541:145680) jump at 1003 */
	/* 001002 */ CSN1C_BACKTRACK,                         /* (ID:0743:145541:145680) Failure of choice begun at 962 */
	/* 001003 */ CSN1C_CHOICE_END,                        /* (ID:0743:145541:145680) End of choice begun at 962 */
	/* 001004 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0765:145694:145750) VBIT choice at 1004, node 1, jump to 1013 */
	/* 001006 */ CSN1C_BIT_1,                             /* (ID:0769:145698:145700) */
	/* 001007 */ CSN1C_LABEL_A, CSN1C_VAL2(453), CSN1C_VAL1(4), /* (ID:0770:145700:145750) Label=<T_GSM_900_Associated_Radio_Capability> LabelId=129 */
	/* 001011 */ CSN1C_GOTO(8),                           /* (ID:0765:145694:145750) jump at 1019 */
	/* 001013 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0765:145694:145750) FBIT choice at 1004, node 2, jump to 1018 */
	/* 001015 */ CSN1C_BIT_0,                             /* (ID:0767:145694:145696) */
	/* 001016 */ CSN1C_GOTO(3),                           /* (ID:0765:145694:145750) jump at 1019 */
	/* 001018 */ CSN1C_BACKTRACK,                         /* (ID:0765:145694:145750) Failure of choice begun at 1004 */
	/* 001019 */ CSN1C_CHOICE_END,                        /* (ID:0765:145694:145750) End of choice begun at 1004 */
	/* 001020 */ CSN1C_LABEL_A, CSN1C_VAL2(456), CSN1C_VAL1(2), /* (ID:0774:145757:145819) Label=<Downlink_Advanced_Receiver_Performance> LabelId=130 */
	/* 001024 */ CSN1C_LABEL_A, CSN1C_VAL2(459), CSN1C_VAL1(1), /* (ID:0778:145819:145867) Label=<DTM_Enhancements_Capability> LabelId=131 */
	/* 001028 */ CSN1C_CHOICE_NODE(0,29),                 /* (ID:0782:145869:146013) VBIT choice at 1028, node 1, jump to 1057 */
	/* 001030 */ CSN1C_BIT_1,                             /* (ID:0786:145873:145875) */
	/* 001031 */ CSN1C_LABEL_A, CSN1C_VAL2(462), CSN1C_VAL1(3), /* (ID:0787:145875:145926) Label=<DTM_GPRS_High_Multi_Slot_Class> LabelId=132 */
	/* 001035 */ CSN1C_LABEL_A, CSN1C_VAL2(465), CSN1C_VAL1(1), /* (ID:0791:145926:145958) Label=<Offset_required> LabelId=133 */
	/* 001039 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0795:145960:146011) VBIT choice at 1039, node 1, jump to 1048 */
	/* 001041 */ CSN1C_BIT_1,                             /* (ID:0799:145964:145966) */
	/* 001042 */ CSN1C_LABEL_A, CSN1C_VAL2(468), CSN1C_VAL1(3), /* (ID:0800:145966:146011) Label=<DTM_EGPRS_High_Multi_Slot_Class> LabelId=134 */
	/* 001046 */ CSN1C_GOTO(8),                           /* (ID:0795:145960:146011) jump at 1054 */
	/* 001048 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0795:145960:146011) FBIT choice at 1039, node 2, jump to 1053 */
	/* 001050 */ CSN1C_BIT_0,                             /* (ID:0797:145960:145962) */
	/* 001051 */ CSN1C_GOTO(3),                           /* (ID:0795:145960:146011) jump at 1054 */
	/* 001053 */ CSN1C_BACKTRACK,                         /* (ID:0795:145960:146011) Failure of choice begun at 1039 */
	/* 001054 */ CSN1C_CHOICE_END,                        /* (ID:0795:145960:146011) End of choice begun at 1039 */
	/* 001055 */ CSN1C_GOTO(8),                           /* (ID:0782:145869:146013) jump at 1063 */
	/* 001057 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0782:145869:146013) FBIT choice at 1028, node 2, jump to 1062 */
	/* 001059 */ CSN1C_BIT_0,                             /* (ID:0784:145869:145871) */
	/* 001060 */ CSN1C_GOTO(3),                           /* (ID:0782:145869:146013) jump at 1063 */
	/* 001062 */ CSN1C_BACKTRACK,                         /* (ID:0782:145869:146013) Failure of choice begun at 1028 */
	/* 001063 */ CSN1C_CHOICE_END,                        /* (ID:0782:145869:146013) End of choice begun at 1028 */
	/* 001064 */ CSN1C_LABEL_A, CSN1C_VAL2(471), CSN1C_VAL1(1), /* (ID:0804:146025:146070) Label=<Repeated_ACCH_Capability> LabelId=135 */
	/* 001068 */ CSN1C_CHOICE_NODE(0,144),                /* (ID:0808:146071:147659) VBIT choice at 1068, node 1, jump to 1212 */
	/* 001070 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0812:146090:146142) VBIT choice at 1070, node 1, jump to 1079 */
	/* 001072 */ CSN1C_BIT_1,                             /* (ID:0816:146094:146096) */
	/* 001073 */ CSN1C_LABEL_A, CSN1C_VAL2(474), CSN1C_VAL1(4), /* (ID:0817:146096:146142) Label=<GSM_710_Associated_Radio_Capability> LabelId=136 */
	/* 001077 */ CSN1C_GOTO(8),                           /* (ID:0812:146090:146142) jump at 1085 */
	/* 001079 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0812:146090:146142) FBIT choice at 1070, node 2, jump to 1084 */
	/* 001081 */ CSN1C_BIT_0,                             /* (ID:0814:146090:146092) */
	/* 001082 */ CSN1C_GOTO(3),                           /* (ID:0812:146090:146142) jump at 1085 */
	/* 001084 */ CSN1C_BACKTRACK,                         /* (ID:0812:146090:146142) Failure of choice begun at 1070 */
	/* 001085 */ CSN1C_CHOICE_END,                        /* (ID:0812:146090:146142) End of choice begun at 1070 */
	/* 001086 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0821:146180:146234) VBIT choice at 1086, node 1, jump to 1095 */
	/* 001088 */ CSN1C_BIT_1,                             /* (ID:0825:146184:146186) */
	/* 001089 */ CSN1C_LABEL_A, CSN1C_VAL2(477), CSN1C_VAL1(4), /* (ID:0826:146186:146234) Label=<T_GSM_810_Associated_Radio_Capability> LabelId=137 */
	/* 001093 */ CSN1C_GOTO(8),                           /* (ID:0821:146180:146234) jump at 1101 */
	/* 001095 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0821:146180:146234) FBIT choice at 1086, node 2, jump to 1100 */
	/* 001097 */ CSN1C_BIT_0,                             /* (ID:0823:146180:146182) */
	/* 001098 */ CSN1C_GOTO(3),                           /* (ID:0821:146180:146234) jump at 1101 */
	/* 001100 */ CSN1C_BACKTRACK,                         /* (ID:0821:146180:146234) Failure of choice begun at 1086 */
	/* 001101 */ CSN1C_CHOICE_END,                        /* (ID:0821:146180:146234) End of choice begun at 1086 */
	/* 001102 */ CSN1C_LABEL_A, CSN1C_VAL2(480), CSN1C_VAL1(1), /* (ID:0830:146242:146298) Label=<Ciphering_Mode_Setting_Capability> LabelId=138 */
	/* 001106 */ CSN1C_LABEL_A, CSN1C_VAL2(483), CSN1C_VAL1(1), /* (ID:0834:146298:146356) Label=<Additional_Positioning_Capabilities> LabelId=139 */
	/* 001110 */ CSN1C_CHOICE_NODE(0,96),                 /* (ID:0838:146357:147631) VBIT choice at 1110, node 1, jump to 1206 */
	/* 001112 */ CSN1C_LABEL_A, CSN1C_VAL2(486), CSN1C_VAL1(1), /* (ID:0842:146375:146446) Label=<E_UTRA_FDD_support> LabelId=140 */
	/* 001116 */ CSN1C_LABEL_A, CSN1C_VAL2(489), CSN1C_VAL1(1), /* (ID:0846:146446:146482) Label=<E_UTRA_TDD_support> LabelId=141 */
	/* 001120 */ CSN1C_LABEL_A, CSN1C_VAL2(492), CSN1C_VAL1(1), /* (ID:0850:146482:146540) Label=<E_UTRA_Measurement_and_Reporting_support> LabelId=142 */
	/* 001124 */ CSN1C_LABEL_A, CSN1C_VAL2(495), CSN1C_VAL1(1), /* (ID:0854:146540:146599) Label=<Priority_based_reselection_support> LabelId=143 */
	/* 001128 */ CSN1C_CHOICE_NODE(0,72),                 /* (ID:0858:146600:147602) VBIT choice at 1128, node 1, jump to 1200 */
	/* 001130 */ CSN1C_LABEL_A, CSN1C_VAL2(498), CSN1C_VAL1(1), /* (ID:0862:146619:146693) Label=<UTRA_CSG_Cells_Reporting> LabelId=144 */
	/* 001134 */ CSN1C_LABEL_A, CSN1C_VAL2(501), CSN1C_VAL1(2), /* (ID:0866:146693:146726) Label=<VAMOS_Level> LabelId=145 */
	/* 001138 */ CSN1C_CHOICE_NODE(0,56),                 /* (ID:0870:146727:147571) VBIT choice at 1138, node 1, jump to 1194 */
	/* 001140 */ CSN1C_LABEL_A, CSN1C_VAL2(504), CSN1C_VAL1(2), /* (ID:0874:146748:146823) Label=<TIGHTER_Capability> LabelId=146 */
	/* 001144 */ CSN1C_LABEL_A, CSN1C_VAL2(507), CSN1C_VAL1(1), /* (ID:0878:146823:146880) Label=<Selective_Ciphering_of_Downlink_SACCH> LabelId=147 */
	/* 001148 */ CSN1C_CHOICE_NODE(0,40),                 /* (ID:0882:146881:147539) VBIT choice at 1148, node 1, jump to 1188 */
	/* 001150 */ CSN1C_LABEL_A, CSN1C_VAL2(510), CSN1C_VAL1(2), /* (ID:0886:146903:146989) Label=<CS_to_PS_SRVCC_from_GERAN_to_UTRA> LabelId=148 */
	/* 001154 */ CSN1C_LABEL_A, CSN1C_VAL2(513), CSN1C_VAL1(2), /* (ID:0890:146989:147057) Label=<CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> LabelId=149 */
	/* 001158 */ CSN1C_LABEL_A, CSN1C_VAL2(516), CSN1C_VAL1(1), /* (ID:0894:147057:147107) Label=<GERAN_Network_Sharing_support> LabelId=150 */
	/* 001162 */ CSN1C_LABEL_A, CSN1C_VAL2(519), CSN1C_VAL1(1), /* (ID:0898:147107:147179) Label=<E_UTRA_Wideband_RSRQ_measurements_support> LabelId=151 */
	/* 001166 */ CSN1C_LABEL_A, CSN1C_VAL2(522), CSN1C_VAL1(1), /* (ID:0902:147179:147251) Label=<ER_Band_Support> LabelId=152 */
	/* 001170 */ CSN1C_LABEL_A, CSN1C_VAL2(525), CSN1C_VAL1(1), /* (ID:0906:147251:147319) Label=<UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=153 */
	/* 001174 */ CSN1C_LABEL_A, CSN1C_VAL2(528), CSN1C_VAL1(1), /* (ID:0910:147319:147388) Label=<E_UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=154 */
	/* 001178 */ CSN1C_LABEL_A, CSN1C_VAL2(531), CSN1C_VAL1(1), /* (ID:0914:147388:147443) Label=<Extended_TSC_Set_Capability_support> LabelId=155 */
	/* 001182 */ CSN1C_LABEL_A, CSN1C_VAL2(534), CSN1C_VAL1(1), /* (ID:0918:147443:147531) Label=<Extended_EARFCN_value_range> LabelId=156 */
	/* 001186 */ CSN1C_GOTO(5),                           /* (ID:0882:146881:147539) jump at 1191 */
	/* 001188 */ CSN1C_GOTO(4),                           /* (ID:0882:146881:147539) jump at 1193 */
	/* 001190 */ CSN1C_BACKTRACK,                         /* (ID:0882:146881:147539) Failure of choice begun at 1148 */
	/* 001191 */ CSN1C_CHOICE_END,                        /* (ID:0882:146881:147539) End of choice begun at 1148 */
	/* 001192 */ CSN1C_GOTO(5),                           /* (ID:0870:146727:147571) jump at 1197 */
	/* 001194 */ CSN1C_GOTO(4),                           /* (ID:0870:146727:147571) jump at 1199 */
	/* 001196 */ CSN1C_BACKTRACK,                         /* (ID:0870:146727:147571) Failure of choice begun at 1138 */
	/* 001197 */ CSN1C_CHOICE_END,                        /* (ID:0870:146727:147571) End of choice begun at 1138 */
	/* 001198 */ CSN1C_GOTO(5),                           /* (ID:0858:146600:147602) jump at 1203 */
	/* 001200 */ CSN1C_GOTO(4),                           /* (ID:0858:146600:147602) jump at 1205 */
	/* 001202 */ CSN1C_BACKTRACK,                         /* (ID:0858:146600:147602) Failure of choice begun at 1128 */
	/* 001203 */ CSN1C_CHOICE_END,                        /* (ID:0858:146600:147602) End of choice begun at 1128 */
	/* 001204 */ CSN1C_GOTO(5),                           /* (ID:0838:146357:147631) jump at 1209 */
	/* 001206 */ CSN1C_GOTO(4),                           /* (ID:0838:146357:147631) jump at 1211 */
	/* 001208 */ CSN1C_BACKTRACK,                         /* (ID:0838:146357:147631) Failure of choice begun at 1110 */
	/* 001209 */ CSN1C_CHOICE_END,                        /* (ID:0838:146357:147631) End of choice begun at 1110 */
	/* 001210 */ CSN1C_GOTO(5),                           /* (ID:0808:146071:147659) jump at 1215 */
	/* 001212 */ CSN1C_GOTO(4),                           /* (ID:0808:146071:147659) jump at 1217 */
	/* 001214 */ CSN1C_BACKTRACK,                         /* (ID:0808:146071:147659) Failure of choice begun at 1068 */
	/* 001215 */ CSN1C_CHOICE_END,                        /* (ID:0808:146071:147659) End of choice begun at 1068 */
	/* 001216 */ CSN1C_GOTO(5),                           /* (ID:0739:145523:147686) jump at 1221 */
	/* 001218 */ CSN1C_GOTO(4),                           /* (ID:0739:145523:147686) jump at 1223 */
	/* 001220 */ CSN1C_BACKTRACK,                         /* (ID:0739:145523:147686) Failure of choice begun at 960 */
	/* 001221 */ CSN1C_CHOICE_END,                        /* (ID:0739:145523:147686) End of choice begun at 960 */
	/* 001222 */ CSN1C_GOTO(5),                           /* (ID:0708:145156:147712) jump at 1227 */
	/* 001224 */ CSN1C_GOTO(4),                           /* (ID:0708:145156:147712) jump at 1229 */
	/* 001226 */ CSN1C_BACKTRACK,                         /* (ID:0708:145156:147712) Failure of choice begun at 895 */
	/* 001227 */ CSN1C_CHOICE_END,                        /* (ID:0708:145156:147712) End of choice begun at 895 */
	/* 001228 */ CSN1C_GOTO(5),                           /* (ID:0668:144569:147737) jump at 1233 */
	/* 001230 */ CSN1C_GOTO(4),                           /* (ID:0668:144569:147737) jump at 1235 */
	/* 001232 */ CSN1C_BACKTRACK,                         /* (ID:0668:144569:147737) Failure of choice begun at 833 */
	/* 001233 */ CSN1C_CHOICE_END,                        /* (ID:0668:144569:147737) End of choice begun at 833 */
	/* 001234 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(0), /* (ID:1317:185325:185332) When decoding infinite loop; at the end jump to 1249 */
	/* 001239 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1317:185325:185332) Send construction; if encoding, jump to 1246 */
	/* 001243 */ CSN1C_BIT_A(1),                          /* (ID:1297:185231:185232) */
	/* 001244 */ CSN1C_GOTO(3),                           /* (ID:1317:185325:185332) skip the encode part and jump to 1247 */
	/* 001246 */ CSN1C_BIT_L,                             /* (ID:1323:185331:185332) */
	/* 001247 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1317:185325:185332) Loop back to 1239 */
	/* 001249 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'epsMsNetwkCpblty'
		DEFINITION FIELD-ID: 15  COMPLEXITY: 93
		SOURCE: ./TS_24.008_subset_for_24.301_R13.src, 809
	-----------------------------------------------------------------*/
	/* 001250 */ CSN1C_LABEL_A, CSN1C_VAL2(537), CSN1C_VAL1(1), /* (ID:1129:161419:161432) Label=<GEA_1> LabelId=157 */
	/* 001254 */ CSN1C_LABEL_A, CSN1C_VAL2(542), CSN1C_VAL1(1), /* (ID:1037:160591:160641) Label=<SM_capabilities_via_dedicated_channels> LabelId=158 */
	/* 001258 */ CSN1C_LABEL_A, CSN1C_VAL2(545), CSN1C_VAL1(1), /* (ID:1041:160641:160686) Label=<SM_capabilities_via_GPRS_channels> LabelId=159 */
	/* 001262 */ CSN1C_LABEL_A, CSN1C_VAL2(548), CSN1C_VAL1(1), /* (ID:1045:160686:160710) Label=<UCS2_support> LabelId=160 */
	/* 001266 */ CSN1C_LABEL_A, CSN1C_VAL2(551), CSN1C_VAL1(2), /* (ID:1049:160710:160747) Label=<SS_Screening_Indicator> LabelId=161 */
	/* 001270 */ CSN1C_LABEL_A, CSN1C_VAL2(554), CSN1C_VAL1(1), /* (ID:1053:160747:160776) Label=<SoLSA_Capability> LabelId=162 */
	/* 001274 */ CSN1C_LABEL_A, CSN1C_VAL2(557), CSN1C_VAL1(1), /* (ID:1057:160776:160812) Label=<Revision_level_indicator> LabelId=163 */
	/* 001278 */ CSN1C_LABEL_A, CSN1C_VAL2(560), CSN1C_VAL1(1), /* (ID:1061:160812:160840) Label=<PFC_feature_mode> LabelId=164 */
	/* 001282 */ CSN1C_LABEL_A, CSN1C_VAL2(563), CSN1C_VAL1(1), /* (ID:1135:161466:161477) Label=<GEA_2> LabelId=165 */
	/* 001286 */ CSN1C_LABEL_A, CSN1C_VAL2(568), CSN1C_VAL1(1), /* (ID:1139:161477:161488) Label=<GEA_3> LabelId=166 */
	/* 001290 */ CSN1C_LABEL_A, CSN1C_VAL2(573), CSN1C_VAL1(1), /* (ID:1143:161488:161501) Label=<GEA_4> LabelId=167 */
	/* 001294 */ CSN1C_LABEL_A, CSN1C_VAL2(578), CSN1C_VAL1(1), /* (ID:1147:161501:161514) Label=<GEA_5> LabelId=168 */
	/* 001298 */ CSN1C_LABEL_A, CSN1C_VAL2(583), CSN1C_VAL1(1), /* (ID:1151:161514:161527) Label=<GEA_6> LabelId=169 */
	/* 001302 */ CSN1C_LABEL_A, CSN1C_VAL2(588), CSN1C_VAL1(1), /* (ID:1155:161527:161538) Label=<GEA_7> LabelId=170 */
	/* 001306 */ CSN1C_LABEL_A, CSN1C_VAL2(593), CSN1C_VAL1(1), /* (ID:1066:160864:160893) Label=<LCS_VA_capability> LabelId=171 */
	/* 001310 */ CSN1C_CHOICE_NODE(0,67),                 /* (ID:1073:160906:161367) Truncable concatenation, entry 0, jump to 1377 */
	/* 001312 */ CSN1C_LABEL_A, CSN1C_VAL2(596), CSN1C_VAL1(1), /* (ID:1074:160906:160972) Label=<PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> LabelId=172 */
	/* 001316 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 1 */
	/* 001317 */ CSN1C_LABEL_A, CSN1C_VAL2(599), CSN1C_VAL1(1), /* (ID:1078:160972:161040) Label=<PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> LabelId=173 */
	/* 001321 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 2 */
	/* 001322 */ CSN1C_LABEL_A, CSN1C_VAL2(602), CSN1C_VAL1(1), /* (ID:1082:161040:161088) Label=<EMM_Combined_procedures_Capability> LabelId=174 */
	/* 001326 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 3 */
	/* 001327 */ CSN1C_LABEL_A, CSN1C_VAL2(605), CSN1C_VAL1(1), /* (ID:1086:161088:161111) Label=<ISR_support> LabelId=175 */
	/* 001331 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 4 */
	/* 001332 */ CSN1C_LABEL_A, CSN1C_VAL2(608), CSN1C_VAL1(1), /* (ID:1090:161111:161154) Label=<SRVCC_to_GERAN_UTRAN_capability> LabelId=176 */
	/* 001336 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 5 */
	/* 001337 */ CSN1C_LABEL_A, CSN1C_VAL2(611), CSN1C_VAL1(1), /* (ID:1094:161154:161180) Label=<EPC_capability> LabelId=177 */
	/* 001341 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 6 */
	/* 001342 */ CSN1C_LABEL_A, CSN1C_VAL2(614), CSN1C_VAL1(1), /* (ID:1098:161180:161205) Label=<NF_capability> LabelId=178 */
	/* 001346 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 7 */
	/* 001347 */ CSN1C_LABEL_A, CSN1C_VAL2(617), CSN1C_VAL1(1), /* (ID:1102:161205:161249) Label=<GERAN_network_sharing_capability> LabelId=179 */
	/* 001351 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 8 */
	/* 001352 */ CSN1C_LABEL_A, CSN1C_VAL2(620), CSN1C_VAL1(1), /* (ID:1106:161249:161300) Label=<User_plane_integrity_protection_support> LabelId=180 */
	/* 001356 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 9 */
	/* 001357 */ CSN1C_LABEL_A, CSN1C_VAL2(623), CSN1C_VAL1(1), /* (ID:1110:161300:161317) Label=<GIA_4> LabelId=181 */
	/* 001361 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 10 */
	/* 001362 */ CSN1C_LABEL_A, CSN1C_VAL2(626), CSN1C_VAL1(1), /* (ID:1114:161317:161334) Label=<GIA_5> LabelId=182 */
	/* 001366 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 11 */
	/* 001367 */ CSN1C_LABEL_A, CSN1C_VAL2(629), CSN1C_VAL1(1), /* (ID:1118:161334:161351) Label=<GIA_6> LabelId=183 */
	/* 001371 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1073:160906:161367) Truncable concatenation, entry 12 */
	/* 001372 */ CSN1C_LABEL_A, CSN1C_VAL2(632), CSN1C_VAL1(1), /* (ID:1122:161351:161367) Label=<GIA_7> LabelId=184 */
	/* 001376 */ CSN1C_CHOICE_END,
	/* 001377 */ CSN1C_GOSUB, CSN1C_VAL2(441),            /* (ID:1126:161378:161392) Reference to 'zero_padding' */
	/* 001380 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'UENetworkCapability'
		DEFINITION FIELD-ID: 1  COMPLEXITY: 210
		SOURCE: ./TS_24.301_core_R13.src, 2679
	-----------------------------------------------------------------*/
	/* 001381 */ CSN1C_LABEL_A, CSN1C_VAL2(635), CSN1C_VAL1(1), /* (ID:0002:123834:123853) Label=<p128_EEA0> LabelId=185 */
	/* 001385 */ CSN1C_LABEL_A, CSN1C_VAL2(638), CSN1C_VAL1(1), /* (ID:0006:123853:123872) Label=<p128_EEA1> LabelId=186 */
	/* 001389 */ CSN1C_LABEL_A, CSN1C_VAL2(641), CSN1C_VAL1(1), /* (ID:0010:123872:123891) Label=<p128_EEA2> LabelId=187 */
	/* 001393 */ CSN1C_LABEL_A, CSN1C_VAL2(644), CSN1C_VAL1(1), /* (ID:0014:123891:123910) Label=<p128_EEA3> LabelId=188 */
	/* 001397 */ CSN1C_LABEL_A, CSN1C_VAL2(647), CSN1C_VAL1(1), /* (ID:0018:123910:123924) Label=<EEA4> LabelId=189 */
	/* 001401 */ CSN1C_LABEL_A, CSN1C_VAL2(650), CSN1C_VAL1(1), /* (ID:0022:123924:123938) Label=<EEA5> LabelId=190 */
	/* 001405 */ CSN1C_LABEL_A, CSN1C_VAL2(653), CSN1C_VAL1(1), /* (ID:0026:123938:123952) Label=<EEA6> LabelId=191 */
	/* 001409 */ CSN1C_LABEL_A, CSN1C_VAL2(656), CSN1C_VAL1(1), /* (ID:0030:123952:123980) Label=<EEA7> LabelId=192 */
	/* 001413 */ CSN1C_LABEL_A, CSN1C_VAL2(659), CSN1C_VAL1(1), /* (ID:0034:123980:123994) Label=<EIA0> LabelId=193 */
	/* 001417 */ CSN1C_LABEL_A, CSN1C_VAL2(662), CSN1C_VAL1(1), /* (ID:0038:123994:124013) Label=<p128_EIA1> LabelId=194 */
	/* 001421 */ CSN1C_LABEL_A, CSN1C_VAL2(665), CSN1C_VAL1(1), /* (ID:0042:124013:124032) Label=<p128_EIA2> LabelId=195 */
	/* 001425 */ CSN1C_LABEL_A, CSN1C_VAL2(668), CSN1C_VAL1(1), /* (ID:0046:124032:124051) Label=<p128_EIA3> LabelId=196 */
	/* 001429 */ CSN1C_LABEL_A, CSN1C_VAL2(671), CSN1C_VAL1(1), /* (ID:0050:124051:124065) Label=<EIA4> LabelId=197 */
	/* 001433 */ CSN1C_LABEL_A, CSN1C_VAL2(674), CSN1C_VAL1(1), /* (ID:0054:124065:124079) Label=<EIA5> LabelId=198 */
	/* 001437 */ CSN1C_LABEL_A, CSN1C_VAL2(677), CSN1C_VAL1(1), /* (ID:0058:124079:124093) Label=<EIA6> LabelId=199 */
	/* 001441 */ CSN1C_LABEL_A, CSN1C_VAL2(680), CSN1C_VAL1(1), /* (ID:0062:124093:124107) Label=<EIA7> LabelId=200 */
	/* 001445 */ CSN1C_CHOICE_NODE(0,151),                /* (ID:0067:124126:124794) Truncable concatenation, entry 0, jump to 1596 */
	/* 001447 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1366),     /* (ID:0068:124126:124289) Label=<octet_5> Terminal=<0> LabelId=201 */
	/* 001450 */ CSN1C_LABEL_A, CSN1C_VAL2(686), CSN1C_VAL1(1), /* (ID:0073:124142:124158) Label=<UEA0> LabelId=202 */
	/* 001454 */ CSN1C_LABEL_A, CSN1C_VAL2(689), CSN1C_VAL1(1), /* (ID:0077:124158:124174) Label=<UEA1> LabelId=203 */
	/* 001458 */ CSN1C_LABEL_A, CSN1C_VAL2(692), CSN1C_VAL1(1), /* (ID:0081:124174:124190) Label=<UEA2> LabelId=204 */
	/* 001462 */ CSN1C_LABEL_A, CSN1C_VAL2(695), CSN1C_VAL1(1), /* (ID:0085:124190:124206) Label=<UEA3> LabelId=205 */
	/* 001466 */ CSN1C_LABEL_A, CSN1C_VAL2(698), CSN1C_VAL1(1), /* (ID:0089:124206:124222) Label=<UEA4> LabelId=206 */
	/* 001470 */ CSN1C_LABEL_A, CSN1C_VAL2(701), CSN1C_VAL1(1), /* (ID:0093:124222:124238) Label=<UEA5> LabelId=207 */
	/* 001474 */ CSN1C_LABEL_A, CSN1C_VAL2(704), CSN1C_VAL1(1), /* (ID:0097:124238:124254) Label=<UEA6> LabelId=208 */
	/* 001478 */ CSN1C_LABEL_A, CSN1C_VAL2(707), CSN1C_VAL1(1), /* (ID:0101:124254:124269) Label=<UEA7> LabelId=209 */
	/* 001482 */ CSN1C_LABEL_END, CSN1C_VAL2(1366),       /* (ID:0068:124126:124289) Label=<octet_5> Terminal=<0> */
	/* 001485 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0067:124126:124794) Truncable concatenation, entry 1 */
	/* 001486 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1420),     /* (ID:0105:124289:124452) Label=<octet_6> Terminal=<0> LabelId=210 */
	/* 001489 */ CSN1C_LABEL_A, CSN1C_VAL2(713), CSN1C_VAL1(1), /* (ID:0110:124305:124321) Label=<UCS2> LabelId=211 */
	/* 001493 */ CSN1C_LABEL_A, CSN1C_VAL2(716), CSN1C_VAL1(1), /* (ID:0114:124321:124337) Label=<UIA1> LabelId=212 */
	/* 001497 */ CSN1C_LABEL_A, CSN1C_VAL2(719), CSN1C_VAL1(1), /* (ID:0118:124337:124353) Label=<UIA2> LabelId=213 */
	/* 001501 */ CSN1C_LABEL_A, CSN1C_VAL2(722), CSN1C_VAL1(1), /* (ID:0122:124353:124369) Label=<UIA3> LabelId=214 */
	/* 001505 */ CSN1C_LABEL_A, CSN1C_VAL2(725), CSN1C_VAL1(1), /* (ID:0126:124369:124385) Label=<UIA4> LabelId=215 */
	/* 001509 */ CSN1C_LABEL_A, CSN1C_VAL2(728), CSN1C_VAL1(1), /* (ID:0130:124385:124401) Label=<UIA5> LabelId=216 */
	/* 001513 */ CSN1C_LABEL_A, CSN1C_VAL2(731), CSN1C_VAL1(1), /* (ID:0134:124401:124417) Label=<UIA6> LabelId=217 */
	/* 001517 */ CSN1C_LABEL_A, CSN1C_VAL2(734), CSN1C_VAL1(1), /* (ID:0138:124417:124432) Label=<UIA7> LabelId=218 */
	/* 001521 */ CSN1C_LABEL_END, CSN1C_VAL2(1420),       /* (ID:0105:124289:124452) Label=<octet_6> Terminal=<0> */
	/* 001524 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0067:124126:124794) Truncable concatenation, entry 2 */
	/* 001525 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1474),     /* (ID:0142:124452:124614) Label=<octet_7> Terminal=<0> LabelId=219 */
	/* 001528 */ CSN1C_BIT_A(2),                          /* (ID:1312:185299:185300) */
	/* 001529 */ CSN1C_LABEL_A, CSN1C_VAL2(740), CSN1C_VAL1(1), /* (ID:0148:124489:124509) Label=<H245_ASH> LabelId=220 */
	/* 001533 */ CSN1C_LABEL_A, CSN1C_VAL2(743), CSN1C_VAL1(1), /* (ID:0152:124509:124529) Label=<ACC_CSFB> LabelId=221 */
	/* 001537 */ CSN1C_LABEL_A, CSN1C_VAL2(746), CSN1C_VAL1(1), /* (ID:0156:124529:124544) Label=<LPP> LabelId=222 */
	/* 001541 */ CSN1C_LABEL_A, CSN1C_VAL2(749), CSN1C_VAL1(1), /* (ID:0160:124544:124559) Label=<LCS> LabelId=223 */
	/* 001545 */ CSN1C_LABEL_A, CSN1C_VAL2(752), CSN1C_VAL1(1), /* (ID:0164:124559:124580) Label=<p1xSR_VCC> LabelId=224 */
	/* 001549 */ CSN1C_LABEL_A, CSN1C_VAL2(755), CSN1C_VAL1(1), /* (ID:0168:124580:124594) Label=<ISR> LabelId=225 */
	/* 001553 */ CSN1C_LABEL_END, CSN1C_VAL2(1474),       /* (ID:0142:124452:124614) Label=<octet_7> Terminal=<0> */
	/* 001556 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0067:124126:124794) Truncable concatenation, entry 3 */
	/* 001557 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1516),     /* (ID:0172:124614:124794) Label=<octet_8> Terminal=<0> LabelId=226 */
	/* 001560 */ CSN1C_LABEL_A, CSN1C_VAL2(761), CSN1C_VAL1(1), /* (ID:0177:124630:124646) Label=<ePCO> LabelId=227 */
	/* 001564 */ CSN1C_LABEL_A, CSN1C_VAL2(764), CSN1C_VAL1(1), /* (ID:0181:124646:124668) Label=<HC_CP_CIoT> LabelId=228 */
	/* 001568 */ CSN1C_LABEL_A, CSN1C_VAL2(767), CSN1C_VAL1(1), /* (ID:0185:124668:124688) Label=<ERw_oPDN> LabelId=229 */
	/* 001572 */ CSN1C_LABEL_A, CSN1C_VAL2(770), CSN1C_VAL1(1), /* (ID:0189:124688:124709) Label=<S1_U_data> LabelId=230 */
	/* 001576 */ CSN1C_LABEL_A, CSN1C_VAL2(773), CSN1C_VAL1(1), /* (ID:0193:124709:124728) Label=<UP_CIoT> LabelId=231 */
	/* 001580 */ CSN1C_LABEL_A, CSN1C_VAL2(776), CSN1C_VAL1(1), /* (ID:0197:124728:124747) Label=<CP_CIoT> LabelId=232 */
	/* 001584 */ CSN1C_LABEL_A, CSN1C_VAL2(779), CSN1C_VAL1(1), /* (ID:0201:124747:124770) Label=<Prose_relay> LabelId=233 */
	/* 001588 */ CSN1C_LABEL_A, CSN1C_VAL2(782), CSN1C_VAL1(1), /* (ID:0205:124770:124789) Label=<ProSe_dc> LabelId=234 */
	/* 001592 */ CSN1C_LABEL_END, CSN1C_VAL2(1516),       /* (ID:0172:124614:124794) Label=<octet_8> Terminal=<0> */
	/* 001595 */ CSN1C_CHOICE_END,
	/* 001596 */ CSN1C_GOSUB, CSN1C_VAL2(441),            /* (ID:0209:124800:124816) Reference to 'zero_padding' */
	/* 001599 */ CSN1C_RETURN,
	((unsigned char)0) /* END OF PROGRAM */
};

/* DEFINITION FOR PROGRAM 'Program_EPS' */
TCSN1CProgram Program_EPS_Program = {
	/* ProgramCode.......*/ Program_EPS_ProgramCode,
	/* ProgramLength.....*/ 1600,
	/* FieldIdPairSet....*/ Program_EPS_FieldIdPairSet,
#ifdef CSN1C_LABEL_NAMES
	/* LabelNames........*/ Program_EPS_Labels,
#endif
	/* FunctionMap.......*/ (void (*const *) (void* ED_EXTRAPARAMS_DECL))Program_EPS_FunctionMap,
	/* ExpressionMap.....*/ (unsigned ED_EXLONG (*const *) (void*))Program_EPS_ExpressionMap,
#ifdef CSN1C_ENABLE_LABEL_SIZE
	/* LabelSizes........*/ Program_EPS_LabelSize,
#endif
	/* FirstErrorLabelId.*/ 246
};

