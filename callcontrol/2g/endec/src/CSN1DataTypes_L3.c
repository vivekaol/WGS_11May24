/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "csn1clib.h"
#include "CSN1DataTypes_L3.h"
#include "ed_c_known_ie_L3.h"
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
int XENCODE_DATA_c_Classmark3Value (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_Classmark3Value
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_Classmark3Value* Source = (const c_Classmark3Value*)(FieldCallbackParam->Context->Data);
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
			case 33: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Multiband_supported), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'A5_7' */
			case 34: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_6' */
			case 35: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_5' */
			case 36: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_4' */
			case 37: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->A5_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Associated_Radio_Capability_2' */
			case 38: {
				/* The field 'Associated_Radio_Capability_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Associated_Radio_Capability_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Associated_Radio_Capability_2), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Associated_Radio_Capability_1' */
			case 39: {
				/* The field 'Associated_Radio_Capability_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Associated_Radio_Capability_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Associated_Radio_Capability_1), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'R_GSM_band_Associated_Radio_Capability' */
			case 40: {
				/* The field 'R_GSM_band_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->R_GSM_band_Associated_Radio_Capability), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'HSCSD_Multi_Slot_Class' */
			case 41: {
				/* The field 'HSCSD_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_HSCSD_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->HSCSD_Multi_Slot_Class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'UCS2_treatment' */
			case 42: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UCS2_treatment != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_Measurement_Capability' */
			case 43: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_Measurement_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SMS_VALUE' */
			case 44: {
				/* The field 'SMS_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_SMS_VALUE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SMS_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'SM_VALUE' */
			case 45: {
				/* The field 'SM_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_SM_VALUE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'MS_Positioning_Method' */
			case 46: {
				/* The field 'MS_Positioning_Method' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_MS_Positioning_Method (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_Positioning_Method), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'ECSD_Multi_Slot_Class' */
			case 47: {
				/* The field 'ECSD_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_ECSD_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ECSD_Multi_Slot_Class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'Modulation_Capability' */
			case 48: {
				/* The field 'Modulation_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Modulation_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Modulation_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field '_8_PSK_RF_Power_Capability_1' */
			case 49: {
				/* The field '_8_PSK_RF_Power_Capability_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_RF_Power_Capability_1), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8_PSK_RF_Power_Capability_2' */
			case 50: {
				/* The field '_8_PSK_RF_Power_Capability_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_RF_Power_Capability_2), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_400_Bands_Supported' */
			case 51: {
				/* The field 'GSM_400_Bands_Supported' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_400_Bands_Supported (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_400_Bands_Supported), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_400_Associated_Radio_Capability' */
			case 52: {
				/* The field 'GSM_400_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_400_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_400_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_850_Associated_Radio_Capability' */
			case 53: {
				/* The field 'GSM_850_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_850_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_850_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_1900_Associated_Radio_Capability' */
			case 54: {
				/* The field 'GSM_1900_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_1900_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_1900_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'UMTS_FDD_Radio_Access_Technology_Capability' */
			case 55: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_FDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 56: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CDMA_2000_Radio_Access_Technology_Capability' */
			case 57: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CDMA_2000_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_Multi_Slot_Class' */
			case 58: {
				/* The field 'DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Single_Slot_DTM' */
			case 59: {
				/* The field 'Single_Slot_DTM' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Single_Slot_DTM (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Single_Slot_DTM != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_EGPRS_Multi_Slot_Class' */
			case 60: {
				/* The field 'DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GSM_Band' */
			case 61: {
				/* The field 'GSM_Band' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_Band (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_Band), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GSM_750_Associated_Radio_Capability' */
			case 62: {
				/* The field 'GSM_750_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_750_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_750_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 63: {
				/* The field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Feature_Package_1' */
			case 64: {
				/* The field 'GERAN_Feature_Package_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GERAN_Feature_Package_1 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Feature_Package_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_DTM_GPRS_Multi_Slot_Class' */
			case 65: {
				/* The field 'Extended_DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Extended_DTM_EGPRS_Multi_Slot_Class' */
			case 66: {
				/* The field 'Extended_DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'High_Multislot_Capability' */
			case 67: {
				/* The field 'High_Multislot_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_High_Multislot_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->High_Multislot_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Length' */
			case 68: {
				/* The field 'Length' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Length (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Length), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'FLO_Iu_Capability' */
			case 69: {
				/* The field 'FLO_Iu_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_FLO_Iu_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->FLO_Iu_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Feature_Package_2' */
			case 70: {
				/* The field 'GERAN_Feature_Package_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GERAN_Feature_Package_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Feature_Package_2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GMSK_Multislot_Power_Profile' */
			case 71: {
				/* The field 'GMSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GMSK_Multislot_Power_Profile (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GMSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8_PSK_Multislot_Power_Profile' */
			case 72: {
				/* The field '_8_PSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value__8_PSK_Multislot_Power_Profile (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->_8_PSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'T_GSM_400_Bands_Supported' */
			case 73: {
				/* The field 'T_GSM_400_Bands_Supported' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_T_GSM_400_Bands_Supported (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_400_Bands_Supported), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'T_GSM_400_Associated_Radio_Capability' */
			case 74: {
				/* The field 'T_GSM_400_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_400_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'T_GSM_900_Associated_Radio_Capability' */
			case 75: {
				/* The field 'T_GSM_900_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_900_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Downlink_Advanced_Receiver_Performance' */
			case 76: {
				/* The field 'Downlink_Advanced_Receiver_Performance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Downlink_Advanced_Receiver_Performance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Downlink_Advanced_Receiver_Performance), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DTM_Enhancements_Capability' */
			case 77: {
				/* The field 'DTM_Enhancements_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_DTM_Enhancements_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_Enhancements_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_High_Multi_Slot_Class' */
			case 78: {
				/* The field 'DTM_GPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_GPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Offset_required' */
			case 79: {
				/* The field 'Offset_required' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Offset_required (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Offset_required != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_EGPRS_High_Multi_Slot_Class' */
			case 80: {
				/* The field 'DTM_EGPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DTM_EGPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Repeated_ACCH_Capability' */
			case 81: {
				/* The field 'Repeated_ACCH_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Repeated_ACCH_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Repeated_ACCH_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GSM_710_Associated_Radio_Capability' */
			case 82: {
				/* The field 'GSM_710_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GSM_710_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GSM_710_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'T_GSM_810_Associated_Radio_Capability' */
			case 83: {
				/* The field 'T_GSM_810_Associated_Radio_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_GSM_810_Associated_Radio_Capability), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Ciphering_Mode_Setting_Capability' */
			case 84: {
				/* The field 'Ciphering_Mode_Setting_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Ciphering_Mode_Setting_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Ciphering_Mode_Setting_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Additional_Positioning_Capabilities' */
			case 85: {
				/* The field 'Additional_Positioning_Capabilities' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Additional_Positioning_Capabilities (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Additional_Positioning_Capabilities != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_FDD_support' */
			case 86: {
				/* The field 'E_UTRA_FDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_E_UTRA_FDD_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_FDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_TDD_support' */
			case 87: {
				/* The field 'E_UTRA_TDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_E_UTRA_TDD_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_TDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Measurement_and_Reporting_support' */
			case 88: {
				/* The field 'E_UTRA_Measurement_and_Reporting_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Measurement_and_Reporting_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Priority_based_reselection_support' */
			case 89: {
				/* The field 'Priority_based_reselection_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Priority_based_reselection_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Priority_based_reselection_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_CSG_Cells_Reporting' */
			case 90: {
				/* The field 'UTRA_CSG_Cells_Reporting' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_UTRA_CSG_Cells_Reporting (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UTRA_CSG_Cells_Reporting != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'VAMOS_Level' */
			case 91: {
				/* The field 'VAMOS_Level' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_VAMOS_Level (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->VAMOS_Level), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'TIGHTER_Capability' */
			case 92: {
				/* The field 'TIGHTER_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_TIGHTER_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TIGHTER_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Selective_Ciphering_of_Downlink_SACCH' */
			case 93: {
				/* The field 'Selective_Ciphering_of_Downlink_SACCH' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Selective_Ciphering_of_Downlink_SACCH != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' */
			case 94: {
				/* The field 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CS_to_PS_SRVCC_from_GERAN_to_UTRA), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' */
			case 95: {
				/* The field 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GERAN_Network_Sharing_support' */
			case 96: {
				/* The field 'GERAN_Network_Sharing_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_GERAN_Network_Sharing_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_Network_Sharing_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Wideband_RSRQ_measurements_support' */
			case 97: {
				/* The field 'E_UTRA_Wideband_RSRQ_measurements_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Wideband_RSRQ_measurements_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ER_Band_Support' */
			case 98: {
				/* The field 'ER_Band_Support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_ER_Band_Support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ER_Band_Support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 99: {
				/* The field 'UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 100: {
				/* The field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->E_UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_TSC_Set_Capability_support' */
			case 101: {
				/* The field 'Extended_TSC_Set_Capability_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Extended_TSC_Set_Capability_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Extended_TSC_Set_Capability_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_EARFCN_value_range' */
			case 102: {
				/* The field 'Extended_EARFCN_value_range' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_Classmark3Value_Extended_EARFCN_value_range (&((*Source)))) return CSN1C_CB_BACKTRACK;
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
int XENCODE_DATA_c_ReceiveNPduNumbersList (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_ReceiveNPduNumbersList
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_ReceiveNPduNumbersList* Source = (const c_ReceiveNPduNumbersList*)(FieldCallbackParam->Context->Data);
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
			/* Field 'sapi' */
			case 119: {
				/* The field 'sapi' is optional. If missing, generate nothing. */
				if ((*Source).sapi.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->sapi.data[(Field)->Index]), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Receive_N_PDU_Number_value' */
			case 120: {
				/* The field 'Receive_N_PDU_Number_value' is optional. If missing, generate nothing. */
				if ((*Source).Receive_N_PDU_Number_value.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Receive_N_PDU_Number_value.data[(Field)->Index]), 8);
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
int XENCODE_DATA_c_MsNetwkCpblty (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_MsNetwkCpblty
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_MsNetwkCpblty* Source = (const c_MsNetwkCpblty*)(FieldCallbackParam->Context->Data);
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
			case 123: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SM_capabilities_via_dedicated_channels' */
			case 124: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_capabilities_via_dedicated_channels != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SM_capabilities_via_GPRS_channels' */
			case 125: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SM_capabilities_via_GPRS_channels != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UCS2_support' */
			case 126: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UCS2_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SS_Screening_Indicator' */
			case 127: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SS_Screening_Indicator), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'SoLSA_Capability' */
			case 128: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SoLSA_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Revision_level_indicator' */
			case 129: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Revision_level_indicator != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PFC_feature_mode' */
			case 130: {
				/* The field 'PFC_feature_mode' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_PFC_feature_mode (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PFC_feature_mode != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_2' */
			case 131: {
				/* The field 'GEA_2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_2 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_3' */
			case 132: {
				/* The field 'GEA_3' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_3 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_4' */
			case 133: {
				/* The field 'GEA_4' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_4 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_5' */
			case 134: {
				/* The field 'GEA_5' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_5 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_6' */
			case 135: {
				/* The field 'GEA_6' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_6 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GEA_7' */
			case 136: {
				/* The field 'GEA_7' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GEA_7 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GEA_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'LCS_VA_capability' */
			case 137: {
				/* The field 'LCS_VA_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_LCS_VA_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->LCS_VA_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' */
			case 138: {
				/* The field 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' */
			case 139: {
				/* The field 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EMM_Combined_procedures_Capability' */
			case 140: {
				/* The field 'EMM_Combined_procedures_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_EMM_Combined_procedures_Capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EMM_Combined_procedures_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ISR_support' */
			case 141: {
				/* The field 'ISR_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_ISR_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ISR_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SRVCC_to_GERAN_UTRAN_capability' */
			case 142: {
				/* The field 'SRVCC_to_GERAN_UTRAN_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->SRVCC_to_GERAN_UTRAN_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EPC_capability' */
			case 143: {
				/* The field 'EPC_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_EPC_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EPC_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'NF_capability' */
			case 144: {
				/* The field 'NF_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_NF_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->NF_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_network_sharing_capability' */
			case 145: {
				/* The field 'GERAN_network_sharing_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GERAN_network_sharing_capability (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GERAN_network_sharing_capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'User_plane_integrity_protection_support' */
			case 146: {
				/* The field 'User_plane_integrity_protection_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_User_plane_integrity_protection_support (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->User_plane_integrity_protection_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_4' */
			case 147: {
				/* The field 'GIA_4' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GIA_4 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_5' */
			case 148: {
				/* The field 'GIA_5' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GIA_5 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_6' */
			case 149: {
				/* The field 'GIA_6' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GIA_6 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GIA_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GIA_7' */
			case 150: {
				/* The field 'GIA_7' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsNetwkCpblty_GIA_7 (&((*Source)))) return CSN1C_CB_BACKTRACK;
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
int XENCODE_DATA_c_MsRadioAccessCpblty (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_MsRadioAccessCpblty
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_MsRadioAccessCpblty* Source = (const c_MsRadioAccessCpblty*)(FieldCallbackParam->Context->Data);
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
			/* Field 'MS_RA_capability_value' */
			case 159: {
				/* The field 'MS_RA_capability_value' is optional. If missing, generate nothing. */
				if (Source->MS_RA_capability_value_part.MS_RA_capability_value.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Access_Technology_Type' */
			case 160: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Index]->Access_Technology_Type), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'Access_capabilities' */
			case 161: {
				/* The field 'Access_capabilities' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Length' */
			case 164: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Index]->Access_capabilities->Length), 7);
				FieldCallbackParam->Length = 7;
				break;
			}
			/* Field 'RF_Power_Capability' */
			case 166: {
				/* The field 'RF_Power_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RF_Power_Capability), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'A5_bits' */
			case 167: {
				/* The field 'A5_bits' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'A5_1' */
			case 228: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_2' */
			case 229: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_2 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_3' */
			case 230: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_3 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_4' */
			case 231: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_4 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_5' */
			case 232: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_5 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_6' */
			case 233: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_6 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'A5_7' */
			case 234: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_7 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'ES_IND' */
			case 168: {
				/* The field 'ES_IND' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.ES_IND != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'PS' */
			case 169: {
				/* The field 'PS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'VGCS' */
			case 170: {
				/* The field 'VGCS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VGCS != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'VBS' */
			case 171: {
				/* The field 'VBS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VBS != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Multislot_capability' */
			case 172: {
				/* The field 'Multislot_capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'HSCSD_multislot_class' */
			case 235: {
				/* The field 'HSCSD_multislot_class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'GPRS_multislot_class' */
			case 236: {
				/* The field 'GPRS_multislot_class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'GPRS_Extended_Dynamic_Allocation_Capability' */
			case 237: {
				/* The field 'GPRS_Extended_Dynamic_Allocation_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'SMS_VALUE' */
			case 238: {
				/* The field 'SMS_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'SM_VALUE' */
			case 239: {
				/* The field 'SM_VALUE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'ECSD_multislot_class' */
			case 240: {
				/* The field 'ECSD_multislot_class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'EGPRS_multislot_class' */
			case 241: {
				/* The field 'EGPRS_multislot_class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'EGPRS_Extended_Dynamic_Allocation_Capability' */
			case 242: {
				/* The field 'EGPRS_Extended_Dynamic_Allocation_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_Multi_Slot_Class' */
			case 243: {
				/* The field 'DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Single_Slot_DTM' */
			case 244: {
				/* The field 'Single_Slot_DTM' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_EGPRS_Multi_Slot_Class' */
			case 245: {
				/* The field 'DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8PSK_Power_Capability' */
			case 173: {
				/* The field '_8PSK_Power_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8PSK_Power_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'COMPACT_Interference_Measurement_Capability' */
			case 174: {
				/* The field 'COMPACT_Interference_Measurement_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Revision_Level_Indicator' */
			case 175: {
				/* The field 'Revision_Level_Indicator' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Revision_Level_Indicator != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UMTS_FDD_Radio_Access_Technology_Capability' */
			case 176: {
				/* The field 'UMTS_FDD_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 177: {
				/* The field 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'CDMA_2000_Radio_Access_Technology_Capability' */
			case 178: {
				/* The field 'CDMA_2000_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' */
			case 179: {
				/* The field 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Feature_Package_1' */
			case 180: {
				/* The field 'GERAN_Feature_Package_1' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1 (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1 != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_DTM_GPRS_Multi_Slot_Class' */
			case 181: {
				/* The field 'Extended_DTM_GPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Extended_DTM_EGPRS_Multi_Slot_Class' */
			case 182: {
				/* The field 'Extended_DTM_EGPRS_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Modulation_based_multislot_class_support' */
			case 183: {
				/* The field 'Modulation_based_multislot_class_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'High_Multislot_Capability' */
			case 184: {
				/* The field 'High_Multislot_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.High_Multislot_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Length' */
			case 185: {
				/* The field 'Length' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Length), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'FLO_Iu_Capability' */
			case 186: {
				/* The field 'FLO_Iu_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FLO_Iu_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GMSK_Multislot_Power_Profile' */
			case 187: {
				/* The field 'GMSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field '_8_PSK_Multislot_Power_Profile' */
			case 188: {
				/* The field '_8_PSK_Multislot_Power_Profile' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Multiple_TBF_Capability' */
			case 189: {
				/* The field 'Multiple_TBF_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Downlink_Advanced_Receiver_Performance' */
			case 190: {
				/* The field 'Downlink_Advanced_Receiver_Performance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Extended_RLC_MAC_Control_Message_Segmentation_Capability' */
			case 191: {
				/* The field 'Extended_RLC_MAC_Control_Message_Segmentation_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_Enhancements_Capability' */
			case 192: {
				/* The field 'DTM_Enhancements_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_GPRS_High_Multi_Slot_Class' */
			case 193: {
				/* The field 'DTM_GPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'DTM_EGPRS_High_Multi_Slot_Class' */
			case 194: {
				/* The field 'DTM_EGPRS_High_Multi_Slot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'PS_Handover_Capability' */
			case 195: {
				/* The field 'PS_Handover_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS_Handover_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTM_Handover_Capability' */
			case 196: {
				/* The field 'DTM_Handover_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Handover_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' */
			case 197: {
				/* The field 'Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Downlink_Dual_Carrier_for_DTM_Capability' */
			case 198: {
				/* The field 'Downlink_Dual_Carrier_for_DTM_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Flexible_Timeslot_Assignment' */
			case 199: {
				/* The field 'Flexible_Timeslot_Assignment' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GAN_PS_Handover_Capability' */
			case 200: {
				/* The field 'GAN_PS_Handover_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'RLC_Non_persistent_Mode' */
			case 201: {
				/* The field 'RLC_Non_persistent_Mode' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Reduced_Latency_Capability' */
			case 202: {
				/* The field 'Reduced_Latency_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Uplink_EGPRS2' */
			case 203: {
				/* The field 'Uplink_EGPRS2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2 (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Uplink_EGPRS2), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Downlink_EGPRS2' */
			case 204: {
				/* The field 'Downlink_EGPRS2' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2 (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_EGPRS2), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'E_UTRA_FDD_support' */
			case 205: {
				/* The field 'E_UTRA_FDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_TDD_support' */
			case 206: {
				/* The field 'E_UTRA_TDD_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode' */
			case 207: {
				/* The field 'GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Priority_based_reselection_support' */
			case 208: {
				/* The field 'Priority_based_reselection_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Priority_based_reselection_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Enhanced_Flexible_Timeslot_Assignment' */
			case 209: {
				/* The field 'Enhanced_Flexible_Timeslot_Assignment' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Alternative_EFTA_Multislot_Class' */
			case 246: {
				/* The field 'Alternative_EFTA_Multislot_Class' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' */
			case 247: {
				/* The field 'EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM' */
			case 210: {
				/* The field 'Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EMST_Capability' */
			case 211: {
				/* The field 'EMST_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMST_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'MTTI_Capability' */
			case 212: {
				/* The field 'MTTI_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.MTTI_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_CSG_Cells_Reporting' */
			case 213: {
				/* The field 'UTRA_CSG_Cells_Reporting' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_CSG_Cells_Reporting' */
			case 214: {
				/* The field 'E_UTRA_CSG_Cells_Reporting' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DTR_Capability' */
			case 215: {
				/* The field 'DTR_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTR_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EMSR_Capability' */
			case 216: {
				/* The field 'EMSR_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMSR_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Fast_Downlink_Frequency_Switching_Capability' */
			case 217: {
				/* The field 'Fast_Downlink_Frequency_Switching_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'TIGHTER_Capability' */
			case 218: {
				/* The field 'TIGHTER_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.TIGHTER_Capability), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'FANR_Capability' */
			case 219: {
				/* The field 'FANR_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FANR_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'IPA_Capability' */
			case 220: {
				/* The field 'IPA_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.IPA_Capability != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GERAN_Network_Sharing_support' */
			case 221: {
				/* The field 'GERAN_Network_Sharing_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Wideband_RSRQ_measurements_support' */
			case 222: {
				/* The field 'E_UTRA_Wideband_RSRQ_measurements_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 223: {
				/* The field 'UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' */
			case 224: {
				/* The field 'E_UTRA_Multiple_Frequency_Band_Indicators_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DLMC_Capability' */
			case 225: {
				/* The field 'DLMC_Capability' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'DLMC_Non_contiguous_intra_band_reception' */
			case 248: {
				/* The field 'DLMC_Non_contiguous_intra_band_reception' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DLMC_Inter_band_reception' */
			case 249: {
				/* The field 'DLMC_Inter_band_reception' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DLMC_Maximum_Bandwidth' */
			case 250: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Bandwidth), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DLMC_Maximum_Number_of_Downlink_Timeslots' */
			case 251: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'DLMC_Maximum_Number_of_Downlink_Carriers' */
			case 252: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Extended_TSC_Set_Capability_support' */
			case 226: {
				/* The field 'Extended_TSC_Set_Capability_support' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Extended_EARFCN_value_range' */
			case 227: {
				/* The field 'Extended_EARFCN_value_range' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range (&(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Length' */
			case 162: {
				/* The field 'Length' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length (&((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Index]->Length), 7);
				FieldCallbackParam->Length = 7;
				break;
			}
			/* Field 'Additional_access_technologies' */
			case 163: {
				/* The field 'Additional_access_technologies' is optional. If missing, generate nothing. */
				if ((*(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[Field->Parent->Index])).Additional_access_technologies.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Access_Technology_Type' */
			case 253: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Index]->Additional_access_technologies.data[(Field)->Parent->Index]->Access_Technology_Type), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'GMSK_Power_Class' */
			case 254: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Index]->Additional_access_technologies.data[(Field)->Parent->Index]->GMSK_Power_Class), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field '_8PSK_Power_Class' */
			case 255: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_RA_capability_value_part.MS_RA_capability_value.data[(Field)->Parent->Parent->Index]->Additional_access_technologies.data[(Field)->Parent->Index]->_8PSK_Power_Class), 2);
				FieldCallbackParam->Length = 2;
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
int XENCODE_DATA_c_ProtocolCfgOpt (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_ProtocolCfgOpt
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_ProtocolCfgOpt* Source = (const c_ProtocolCfgOpt*)(FieldCallbackParam->Context->Data);
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
			/* Field 'ConfigurationProtocol' */
			case 349: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ConfigurationProtocol), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'ProtocolCfgs' */
			case 350: {
				/* The field 'ProtocolCfgs' is optional. If missing, generate nothing. */
				if ((*Source).ProtocolCfgs.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'ProtocolId' */
			case 352: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ProtocolCfgs.data[(Field)->Parent->Index]->ProtocolId), 16);
				FieldCallbackParam->Length = 16;
				break;
			}
			/* Field 'Length' */
			case 353: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ProtocolCfgs.data[(Field)->Parent->Index]->Length), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'Contents' */
			case 354: {
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), Source->ProtocolCfgs.data[(Field)->Parent->Index]->Contents.value, 0, Source->ProtocolCfgs.data[(Field)->Parent->Index]->Contents.usedBits);
				FieldCallbackParam->Length = Source->ProtocolCfgs.data[(Field)->Parent->Index]->Contents.usedBits;
				break;
			}
			/* Field 'ContainerCfgs' */
			case 351: {
				/* The field 'ContainerCfgs' is optional. If missing, generate nothing. */
				if ((*Source).ContainerCfgs.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'ContainerId' */
			case 355: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ContainerCfgs.data[(Field)->Parent->Index]->ContainerId), 16);
				FieldCallbackParam->Length = 16;
				break;
			}
			/* Field 'Length' */
			case 356: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ContainerCfgs.data[(Field)->Parent->Index]->Length), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'Contents' */
			case 357: {
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), Source->ContainerCfgs.data[(Field)->Parent->Index]->Contents.value, 0, Source->ContainerCfgs.data[(Field)->Parent->Index]->Contents.usedBits);
				FieldCallbackParam->Length = Source->ContainerCfgs.data[(Field)->Parent->Index]->Contents.usedBits;
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Classmark3Value (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Classmark3Value* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_Classmark3Value
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 186, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_Classmark3Value ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Classmark3Value (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Classmark3Value* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_Classmark3Value
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 186, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 33 /* Multiband_supported */: {
					Destin->Multiband_supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Multiband_supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 34 /* A5_7 */: {
					Destin->A5_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 35 /* A5_6 */: {
					Destin->A5_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 36 /* A5_5 */: {
					Destin->A5_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 37 /* A5_4 */: {
					Destin->A5_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->A5_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 38 /* Associated_Radio_Capability_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Associated_Radio_Capability_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Associated_Radio_Capability_2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Associated_Radio_Capability_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 39 /* Associated_Radio_Capability_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Associated_Radio_Capability_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Associated_Radio_Capability_1 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Associated_Radio_Capability_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 40 /* R_GSM_band_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->R_GSM_band_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->R_GSM_band_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 41 /* HSCSD_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_HSCSD_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->HSCSD_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->HSCSD_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 42 /* UCS2_treatment */: {
					Destin->UCS2_treatment = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UCS2_treatment___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 43 /* Extended_Measurement_Capability */: {
					Destin->Extended_Measurement_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_Measurement_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 44 /* SMS_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_SMS_VALUE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SMS_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SMS_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 45 /* SM_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_SM_VALUE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SM_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 46 /* MS_Positioning_Method */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_MS_Positioning_Method (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_Positioning_Method = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_Positioning_Method___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 47 /* ECSD_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_ECSD_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ECSD_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ECSD_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 48 /* Modulation_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Modulation_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Modulation_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Modulation_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 49 /* _8_PSK_RF_Power_Capability_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_RF_Power_Capability_1 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_RF_Power_Capability_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 50 /* _8_PSK_RF_Power_Capability_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_RF_Power_Capability_2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_RF_Power_Capability_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 51 /* GSM_400_Bands_Supported */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_400_Bands_Supported (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_400_Bands_Supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_400_Bands_Supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 52 /* GSM_400_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_400_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_400_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_400_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 53 /* GSM_850_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_850_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_850_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_850_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 54 /* GSM_1900_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_1900_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_1900_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_1900_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 55 /* UMTS_FDD_Radio_Access_Technology_Capability */: {
					Destin->UMTS_FDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_FDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 56 /* UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */: {
					Destin->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 57 /* CDMA_2000_Radio_Access_Technology_Capability */: {
					Destin->CDMA_2000_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CDMA_2000_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 58 /* DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 59 /* Single_Slot_DTM */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Single_Slot_DTM (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Single_Slot_DTM = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Single_Slot_DTM___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 60 /* DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 61 /* GSM_Band */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_Band (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_Band = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_Band___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 62 /* GSM_750_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_750_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_750_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_750_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 63 /* UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 64 /* GERAN_Feature_Package_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GERAN_Feature_Package_1 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Feature_Package_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Feature_Package_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 65 /* Extended_DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 66 /* Extended_DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 67 /* High_Multislot_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_High_Multislot_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->High_Multislot_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->High_Multislot_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 68 /* Length */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Length (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 69 /* FLO_Iu_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_FLO_Iu_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->FLO_Iu_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->FLO_Iu_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 70 /* GERAN_Feature_Package_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GERAN_Feature_Package_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Feature_Package_2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Feature_Package_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 71 /* GMSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GMSK_Multislot_Power_Profile (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GMSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GMSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 72 /* _8_PSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value__8_PSK_Multislot_Power_Profile (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->_8_PSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->_8_PSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 73 /* T_GSM_400_Bands_Supported */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_T_GSM_400_Bands_Supported (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_400_Bands_Supported = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_400_Bands_Supported___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 74 /* T_GSM_400_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_400_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_400_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 75 /* T_GSM_900_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_900_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_900_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 76 /* Downlink_Advanced_Receiver_Performance */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Downlink_Advanced_Receiver_Performance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Downlink_Advanced_Receiver_Performance = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Downlink_Advanced_Receiver_Performance___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 77 /* DTM_Enhancements_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_DTM_Enhancements_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_Enhancements_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_Enhancements_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 78 /* DTM_GPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_GPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_GPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 79 /* Offset_required */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Offset_required (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Offset_required = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Offset_required___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 80 /* DTM_EGPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DTM_EGPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DTM_EGPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 81 /* Repeated_ACCH_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Repeated_ACCH_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Repeated_ACCH_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Repeated_ACCH_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 82 /* GSM_710_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GSM_710_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GSM_710_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GSM_710_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 83 /* T_GSM_810_Associated_Radio_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_GSM_810_Associated_Radio_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_GSM_810_Associated_Radio_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 84 /* Ciphering_Mode_Setting_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Ciphering_Mode_Setting_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Ciphering_Mode_Setting_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Ciphering_Mode_Setting_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 85 /* Additional_Positioning_Capabilities */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Additional_Positioning_Capabilities (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Additional_Positioning_Capabilities = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Positioning_Capabilities___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 86 /* E_UTRA_FDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_E_UTRA_FDD_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_FDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_FDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 87 /* E_UTRA_TDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_E_UTRA_TDD_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_TDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_TDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 88 /* E_UTRA_Measurement_and_Reporting_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Measurement_and_Reporting_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Measurement_and_Reporting_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 89 /* Priority_based_reselection_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Priority_based_reselection_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Priority_based_reselection_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Priority_based_reselection_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 90 /* UTRA_CSG_Cells_Reporting */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_UTRA_CSG_Cells_Reporting (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UTRA_CSG_Cells_Reporting = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UTRA_CSG_Cells_Reporting___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 91 /* VAMOS_Level */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_VAMOS_Level (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->VAMOS_Level = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->VAMOS_Level___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 92 /* TIGHTER_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_TIGHTER_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TIGHTER_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TIGHTER_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 93 /* Selective_Ciphering_of_Downlink_SACCH */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Selective_Ciphering_of_Downlink_SACCH = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Selective_Ciphering_of_Downlink_SACCH___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 94 /* CS_to_PS_SRVCC_from_GERAN_to_UTRA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CS_to_PS_SRVCC_from_GERAN_to_UTRA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CS_to_PS_SRVCC_from_GERAN_to_UTRA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 95 /* CS_to_PS_SRVCC_from_GERAN_to_E_UTRA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 96 /* GERAN_Network_Sharing_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_GERAN_Network_Sharing_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_Network_Sharing_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_Network_Sharing_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 97 /* E_UTRA_Wideband_RSRQ_measurements_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Wideband_RSRQ_measurements_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Wideband_RSRQ_measurements_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 98 /* ER_Band_Support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_ER_Band_Support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ER_Band_Support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ER_Band_Support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 99 /* UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 100 /* E_UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->E_UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->E_UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 101 /* Extended_TSC_Set_Capability_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Extended_TSC_Set_Capability_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Extended_TSC_Set_Capability_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Extended_TSC_Set_Capability_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 102 /* Extended_EARFCN_value_range */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_Classmark3Value_Extended_EARFCN_value_range (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ReceiveNPduNumbersList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ReceiveNPduNumbersList* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_ReceiveNPduNumbersList
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 951, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 11;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_ReceiveNPduNumbersList ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ReceiveNPduNumbersList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ReceiveNPduNumbersList* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_ReceiveNPduNumbersList
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 951, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 11;
	
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
				case 119 /* sapi */: {
					if (SETITEMS_c_ReceiveNPduNumbersList_sapi (&((*Destin).sapi), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
					Destin->sapi.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index] = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->sapi.data___LOCATOR[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index]), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 120 /* Receive_N_PDU_Number_value */: {
					if (SETITEMS_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value (&((*Destin).Receive_N_PDU_Number_value), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
					Destin->Receive_N_PDU_Number_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index] = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Receive_N_PDU_Number_value.data___LOCATOR[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index]), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}

				default:;
			}
		}
	}
	
	exitFunc:
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MsNetwkCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MsNetwkCpblty* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_MsNetwkCpblty
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 964, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_MsNetwkCpblty ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MsNetwkCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MsNetwkCpblty* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_MsNetwkCpblty
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 964, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 123 /* GEA_1 */: {
					Destin->GEA_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 124 /* SM_capabilities_via_dedicated_channels */: {
					Destin->SM_capabilities_via_dedicated_channels = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_capabilities_via_dedicated_channels___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 125 /* SM_capabilities_via_GPRS_channels */: {
					Destin->SM_capabilities_via_GPRS_channels = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SM_capabilities_via_GPRS_channels___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 126 /* UCS2_support */: {
					Destin->UCS2_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UCS2_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 127 /* SS_Screening_Indicator */: {
					Destin->SS_Screening_Indicator = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SS_Screening_Indicator___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 128 /* SoLSA_Capability */: {
					Destin->SoLSA_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SoLSA_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 129 /* Revision_level_indicator */: {
					Destin->Revision_level_indicator = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Revision_level_indicator___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 130 /* PFC_feature_mode */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_PFC_feature_mode (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PFC_feature_mode = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PFC_feature_mode___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 131 /* GEA_2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_2 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 132 /* GEA_3 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_3 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 133 /* GEA_4 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_4 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 134 /* GEA_5 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_5 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 135 /* GEA_6 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_6 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 136 /* GEA_7 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GEA_7 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GEA_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GEA_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 137 /* LCS_VA_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_LCS_VA_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->LCS_VA_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->LCS_VA_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 138 /* PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 139 /* PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 140 /* EMM_Combined_procedures_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_EMM_Combined_procedures_Capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EMM_Combined_procedures_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EMM_Combined_procedures_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 141 /* ISR_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_ISR_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ISR_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ISR_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 142 /* SRVCC_to_GERAN_UTRAN_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->SRVCC_to_GERAN_UTRAN_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->SRVCC_to_GERAN_UTRAN_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 143 /* EPC_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_EPC_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EPC_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EPC_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 144 /* NF_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_NF_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->NF_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->NF_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 145 /* GERAN_network_sharing_capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GERAN_network_sharing_capability (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GERAN_network_sharing_capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GERAN_network_sharing_capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 146 /* User_plane_integrity_protection_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_User_plane_integrity_protection_support (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->User_plane_integrity_protection_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->User_plane_integrity_protection_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 147 /* GIA_4 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GIA_4 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 148 /* GIA_5 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GIA_5 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 149 /* GIA_6 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GIA_6 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GIA_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GIA_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 150 /* GIA_7 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsNetwkCpblty_GIA_7 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MsRadioAccessCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MsRadioAccessCpblty* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_MsRadioAccessCpblty
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 1833, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_MsRadioAccessCpblty ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MsRadioAccessCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MsRadioAccessCpblty* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_MsRadioAccessCpblty
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 1833, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 159: {
				if (SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
				break;
			}
			case 160 /* Access_Technology_Type */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Access_Technology_Type = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Access_Technology_Type___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 161: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 164 /* Length */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Access_capabilities->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Access_capabilities->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					break;
				}
			case 166 /* RF_Power_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RF_Power_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RF_Power_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 167: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 228 /* A5_1 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 229 /* A5_2 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_2 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 230 /* A5_3 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_3 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_3___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 231 /* A5_4 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_4 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_4___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 232 /* A5_5 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_5 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_5___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 233 /* A5_6 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_6 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_6___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 234 /* A5_7 */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_7 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.A5_bits->A5_7___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 168 /* ES_IND */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.ES_IND = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.ES_IND___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 169 /* PS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 170 /* VGCS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VGCS = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VGCS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 171 /* VBS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VBS = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.VBS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 172: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 235 /* HSCSD_multislot_class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 236 /* GPRS_multislot_class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 237 /* GPRS_Extended_Dynamic_Allocation_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 238 /* SMS_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 239 /* SM_VALUE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 240 /* ECSD_multislot_class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 241 /* EGPRS_multislot_class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 242 /* EGPRS_Extended_Dynamic_Allocation_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 243 /* DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 244 /* Single_Slot_DTM */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 245 /* DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 173 /* _8PSK_Power_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8PSK_Power_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8PSK_Power_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 174 /* COMPACT_Interference_Measurement_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 175 /* Revision_Level_Indicator */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Revision_Level_Indicator = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Revision_Level_Indicator___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 176 /* UMTS_FDD_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 177 /* UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 178 /* CDMA_2000_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 179 /* UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 180 /* GERAN_Feature_Package_1 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1 (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1 = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 181 /* Extended_DTM_GPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 182 /* Extended_DTM_EGPRS_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 183 /* Modulation_based_multislot_class_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 184 /* High_Multislot_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.High_Multislot_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.High_Multislot_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 185 /* Length */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 186 /* FLO_Iu_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FLO_Iu_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FLO_Iu_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 187 /* GMSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 188 /* _8_PSK_Multislot_Power_Profile */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 189 /* Multiple_TBF_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 190 /* Downlink_Advanced_Receiver_Performance */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 191 /* Extended_RLC_MAC_Control_Message_Segmentation_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 192 /* DTM_Enhancements_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 193 /* DTM_GPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 194 /* DTM_EGPRS_High_Multi_Slot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 195 /* PS_Handover_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS_Handover_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.PS_Handover_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 196 /* DTM_Handover_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Handover_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTM_Handover_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 197 /* Multislot_Capability_Reduction_for_Downlink_Dual_Carrier */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 198 /* Downlink_Dual_Carrier_for_DTM_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 199 /* Flexible_Timeslot_Assignment */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 200 /* GAN_PS_Handover_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 201 /* RLC_Non_persistent_Mode */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 202 /* Reduced_Latency_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 203 /* Uplink_EGPRS2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2 (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Uplink_EGPRS2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Uplink_EGPRS2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 204 /* Downlink_EGPRS2 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2 (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_EGPRS2 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Downlink_EGPRS2___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 205 /* E_UTRA_FDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 206 /* E_UTRA_TDD_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 207 /* GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 208 /* Priority_based_reselection_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Priority_based_reselection_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Priority_based_reselection_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 209: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 246 /* Alternative_EFTA_Multislot_Class */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 247 /* EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 210 /* Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 211 /* EMST_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMST_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMST_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 212 /* MTTI_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.MTTI_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.MTTI_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 213 /* UTRA_CSG_Cells_Reporting */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 214 /* E_UTRA_CSG_Cells_Reporting */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 215 /* DTR_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTR_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DTR_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 216 /* EMSR_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMSR_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.EMSR_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 217 /* Fast_Downlink_Frequency_Switching_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 218 /* TIGHTER_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.TIGHTER_Capability = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.TIGHTER_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 219 /* FANR_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FANR_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.FANR_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 220 /* IPA_Capability */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.IPA_Capability = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.IPA_Capability___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 221 /* GERAN_Network_Sharing_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 222 /* E_UTRA_Wideband_RSRQ_measurements_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 223 /* UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 224 /* E_UTRA_Multiple_Frequency_Band_Indicators_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 225: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 248 /* DLMC_Non_contiguous_intra_band_reception */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 249 /* DLMC_Inter_band_reception */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 250 /* DLMC_Maximum_Bandwidth */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Bandwidth = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Bandwidth___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 251 /* DLMC_Maximum_Number_of_Downlink_Timeslots */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 252 /* DLMC_Maximum_Number_of_Downlink_Carriers */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 226 /* Extended_TSC_Set_Capability_support */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 227 /* Extended_EARFCN_value_range */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range (&(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Parent->Index]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 162 /* Length */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					break;
				}
			case 163: {
				if (SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies (&((*(Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index])).Additional_access_technologies), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
				break;
			}
			case 253 /* Access_Technology_Type */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Access_Technology_Type = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Access_Technology_Type___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 254 /* GMSK_Power_Class */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->GMSK_Power_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->GMSK_Power_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 255 /* _8PSK_Power_Class */: {
					Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->_8PSK_Power_Class = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_RA_capability_value_part.MS_RA_capability_value.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Parent->Index]->Additional_access_technologies.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->_8PSK_Power_Class___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}

				default:;
			}
		}
	}
	
	exitFunc:
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ProtocolCfgOpt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ProtocolCfgOpt* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_ProtocolCfgOpt
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 69, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 27;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_ProtocolCfgOpt ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ProtocolCfgOpt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ProtocolCfgOpt* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_ProtocolCfgOpt
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_L3_Program, 69, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 27;
	
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
				case 349 /* ConfigurationProtocol */: {
					Destin->ConfigurationProtocol = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ConfigurationProtocol___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 350: {
				if (SETITEMS_c_ProtocolCfgOpt_ProtocolCfgs (&((*Destin).ProtocolCfgs), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
				break;
			}
			case 352 /* ProtocolId */: {
					Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->ProtocolId = (ED_SHORT)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 16);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->ProtocolId___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 16);
					break;
				}
			case 353 /* Length */: {
					Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 354 /* Contents */: {
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_ProtocolCfgOpt_ProtocolCfgs_data_Contents (&(Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents), CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.value) {
							EDCopyBits (Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->ProtocolCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 351: {
				if (SETITEMS_c_ProtocolCfgOpt_ContainerCfgs (&((*Destin).ContainerCfgs), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
				break;
			}
			case 355 /* ContainerId */: {
					Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->ContainerId = (ED_SHORT)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 16);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->ContainerId___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 16);
					break;
				}
			case 356 /* Length */: {
					Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Length___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 357 /* Contents */: {
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_ProtocolCfgOpt_ContainerCfgs_data_Contents (&(Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents), CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.value) {
							EDCopyBits (Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->ContainerCfgs.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Contents.usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}

				default:;
			}
		}
	}
	
	exitFunc:
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
const char* const Program_L3_Labels [] = {

	/*     0 */ "CSN1_A5_CM3_bits_A5_7",
	/*     1 */ "CSN1_A5_CM3_bits_A5_6",
	/*     2 */ "CSN1_A5_CM3_bits_A5_5",
	/*     3 */ "CSN1_A5_CM3_bits_A5_4",
	/*     4 */ "CSN1_GERAN_Iu_Mode_Capabilities_Length",
	/*     5 */ "CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability",
	/*     6 */ "CSN1_Receive_N_Pdu_Numbers_List_val_sapi",
	/*     7 */ "CSN1_Receive_N_Pdu_Numbers_List_val_Receive_N_PDU_Number_value",
	/*     8 */ "CSN1_ProtocolCfgOpt_ConfigurationProtocol",
	/*     9 */ "CSN1_ProtocolCfgOpt_ProtocolCfgs",
	/*    10 */ "CSN1_ProtocolCfgOpt_ProtocolId",
	/*    11 */ "CSN1_ProtocolCfgOpt_Length",
	/*    12 */ "CSN1_ProtocolCfgOpt_Contents",
	/*    13 */ "CSN1_ProtocolCfgOpt_ContainerCfgs",
	/*    14 */ "CSN1_ProtocolCfgOpt_ContainerId",
	/*    15 */ "CSN1_Classmark3Value_Multiband_supported",
	/*    16 */ "CSN1_Classmark3Value_Associated_Radio_Capability_2",
	/*    17 */ "CSN1_Classmark3Value_Associated_Radio_Capability_1",
	/*    18 */ "CSN1_R_Support_R_GSM_band_Associated_Radio_Capability",
	/*    19 */ "CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class",
	/*    20 */ "CSN1_Classmark3Value_UCS2_treatment",
	/*    21 */ "CSN1_Classmark3Value_Extended_Measurement_Capability",
	/*    22 */ "CSN1_MS_Measurement_capability_SMS_VALUE",
	/*    23 */ "CSN1_MS_Measurement_capability_SM_VALUE",
	/*    24 */ "CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method",
	/*    25 */ "CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class",
	/*    26 */ "CSN1__8_PSK_Struct_Modulation_Capability",
	/*    27 */ "CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1",
	/*    28 */ "CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2",
	/*    29 */ "CSN1_Classmark3Value_GSM_400_Bands_Supported",
	/*    30 */ "CSN1_Classmark3Value_GSM_400_Associated_Radio_Capability",
	/*    31 */ "CSN1_Classmark3Value_GSM_850_Associated_Radio_Capability",
	/*    32 */ "CSN1_Classmark3Value_GSM_1900_Associated_Radio_Capability",
	/*    33 */ "CSN1_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability",
	/*    34 */ "CSN1_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability",
	/*    35 */ "CSN1_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability",
	/*    36 */ "CSN1_Classmark3Value_DTM_GPRS_Multi_Slot_Class",
	/*    37 */ "CSN1_Classmark3Value_Single_Slot_DTM",
	/*    38 */ "CSN1_Classmark3Value_DTM_EGPRS_Multi_Slot_Class",
	/*    39 */ "CSN1_Single_Band_Support_GSM_Band",
	/*    40 */ "CSN1_Classmark3Value_GSM_750_Associated_Radio_Capability",
	/*    41 */ "CSN1_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability",
	/*    42 */ "CSN1_Classmark3Value_GERAN_Feature_Package_1",
	/*    43 */ "CSN1_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class",
	/*    44 */ "CSN1_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class",
	/*    45 */ "CSN1_Classmark3Value_High_Multislot_Capability",
	/*    46 */ "CSN1_Classmark3Value_GERAN_Feature_Package_2",
	/*    47 */ "CSN1_Classmark3Value_GMSK_Multislot_Power_Profile",
	/*    48 */ "CSN1_Classmark3Value__8_PSK_Multislot_Power_Profile",
	/*    49 */ "CSN1_Classmark3Value_T_GSM_400_Bands_Supported",
	/*    50 */ "CSN1_Classmark3Value_T_GSM_400_Associated_Radio_Capability",
	/*    51 */ "CSN1_Classmark3Value_T_GSM_900_Associated_Radio_Capability",
	/*    52 */ "CSN1_Classmark3Value_Downlink_Advanced_Receiver_Performance",
	/*    53 */ "CSN1_Classmark3Value_DTM_Enhancements_Capability",
	/*    54 */ "CSN1_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class",
	/*    55 */ "CSN1_Classmark3Value_Offset_required",
	/*    56 */ "CSN1_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class",
	/*    57 */ "CSN1_Classmark3Value_Repeated_ACCH_Capability",
	/*    58 */ "CSN1_Classmark3Value_GSM_710_Associated_Radio_Capability",
	/*    59 */ "CSN1_Classmark3Value_T_GSM_810_Associated_Radio_Capability",
	/*    60 */ "CSN1_Classmark3Value_Ciphering_Mode_Setting_Capability",
	/*    61 */ "CSN1_Classmark3Value_Additional_Positioning_Capabilities",
	/*    62 */ "CSN1_Classmark3Value_E_UTRA_FDD_support",
	/*    63 */ "CSN1_Classmark3Value_E_UTRA_TDD_support",
	/*    64 */ "CSN1_Classmark3Value_E_UTRA_Measurement_and_Reporting_support",
	/*    65 */ "CSN1_Classmark3Value_Priority_based_reselection_support",
	/*    66 */ "CSN1_Classmark3Value_UTRA_CSG_Cells_Reporting",
	/*    67 */ "CSN1_Classmark3Value_VAMOS_Level",
	/*    68 */ "CSN1_Classmark3Value_TIGHTER_Capability",
	/*    69 */ "CSN1_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH",
	/*    70 */ "CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA",
	/*    71 */ "CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA",
	/*    72 */ "CSN1_Classmark3Value_GERAN_Network_Sharing_support",
	/*    73 */ "CSN1_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support",
	/*    74 */ "CSN1_Classmark3Value_ER_Band_Support",
	/*    75 */ "CSN1_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*    76 */ "CSN1_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*    77 */ "CSN1_Classmark3Value_Extended_TSC_Set_Capability_support",
	/*    78 */ "CSN1_Classmark3Value_Extended_EARFCN_value_range",
	/*    79 */ "CSN1_GEA1_bits_GEA_1",
	/*    80 */ "CSN1_MsNetwkCpblty_SM_capabilities_via_dedicated_channels",
	/*    81 */ "CSN1_MsNetwkCpblty_SM_capabilities_via_GPRS_channels",
	/*    82 */ "CSN1_MsNetwkCpblty_UCS2_support",
	/*    83 */ "CSN1_MsNetwkCpblty_SS_Screening_Indicator",
	/*    84 */ "CSN1_MsNetwkCpblty_SoLSA_Capability",
	/*    85 */ "CSN1_MsNetwkCpblty_Revision_level_indicator",
	/*    86 */ "CSN1_MsNetwkCpblty_PFC_feature_mode",
	/*    87 */ "CSN1_Extended_GEA_bits_GEA_2",
	/*    88 */ "CSN1_Extended_GEA_bits_GEA_3",
	/*    89 */ "CSN1_Extended_GEA_bits_GEA_4",
	/*    90 */ "CSN1_Extended_GEA_bits_GEA_5",
	/*    91 */ "CSN1_Extended_GEA_bits_GEA_6",
	/*    92 */ "CSN1_Extended_GEA_bits_GEA_7",
	/*    93 */ "CSN1_MsNetwkCpblty_LCS_VA_capability",
	/*    94 */ "CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability",
	/*    95 */ "CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability",
	/*    96 */ "CSN1_MsNetwkCpblty_EMM_Combined_procedures_Capability",
	/*    97 */ "CSN1_MsNetwkCpblty_ISR_support",
	/*    98 */ "CSN1_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability",
	/*    99 */ "CSN1_MsNetwkCpblty_EPC_capability",
	/*   100 */ "CSN1_MsNetwkCpblty_NF_capability",
	/*   101 */ "CSN1_MsNetwkCpblty_GERAN_network_sharing_capability",
	/*   102 */ "CSN1_MsNetwkCpblty_User_plane_integrity_protection_support",
	/*   103 */ "CSN1_MsNetwkCpblty_GIA_4",
	/*   104 */ "CSN1_MsNetwkCpblty_GIA_5",
	/*   105 */ "CSN1_MsNetwkCpblty_GIA_6",
	/*   106 */ "CSN1_MsNetwkCpblty_GIA_7",
	/*   107 */ "CSN1_MS_RA_capability_value_part_struct_MS_RA_capability_value",
	/*   108 */ "CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type",
	/*   109 */ "CSN1_MS_RA_capability_value_part_struct_Access_capabilities",
	/*   110 */ "CSN1_Access_capabilities_struct_Length",
	/*   111 */ "CSN1_Access_capabilities_struct_Access_capabilities",
	/*   112 */ "CSN1_Content_RF_Power_Capability",
	/*   113 */ "CSN1_Content_A5_bits",
	/*   114 */ "CSN1_A5_5_12_bits_A5_1",
	/*   115 */ "CSN1_A5_5_12_bits_A5_2",
	/*   116 */ "CSN1_A5_5_12_bits_A5_3",
	/*   117 */ "CSN1_A5_5_12_bits_A5_4",
	/*   118 */ "CSN1_A5_5_12_bits_A5_5",
	/*   119 */ "CSN1_A5_5_12_bits_A5_6",
	/*   120 */ "CSN1_A5_5_12_bits_A5_7",
	/*   121 */ "CSN1_Content_ES_IND",
	/*   122 */ "CSN1_Content_PS",
	/*   123 */ "CSN1_Content_VGCS",
	/*   124 */ "CSN1_Content_VBS",
	/*   125 */ "CSN1_Content_Multislot_capability",
	/*   126 */ "CSN1_Multislot_capability_struct_HSCSD_multislot_class",
	/*   127 */ "CSN1_Multislot_capability_struct_GPRS_multislot_class",
	/*   128 */ "CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability",
	/*   129 */ "CSN1_Multislot_capability_struct_SMS_VALUE",
	/*   130 */ "CSN1_Multislot_capability_struct_SM_VALUE",
	/*   131 */ "CSN1_Multislot_capability_struct_ECSD_multislot_class",
	/*   132 */ "CSN1_Multislot_capability_struct_EGPRS_multislot_class",
	/*   133 */ "CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability",
	/*   134 */ "CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class",
	/*   135 */ "CSN1_Multislot_capability_struct_Single_Slot_DTM",
	/*   136 */ "CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class",
	/*   137 */ "CSN1_Content__8PSK_Power_Capability",
	/*   138 */ "CSN1_Content_COMPACT_Interference_Measurement_Capability",
	/*   139 */ "CSN1_Content_Revision_Level_Indicator",
	/*   140 */ "CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability",
	/*   141 */ "CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability",
	/*   142 */ "CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability",
	/*   143 */ "CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability",
	/*   144 */ "CSN1_Content_GERAN_Feature_Package_1",
	/*   145 */ "CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class",
	/*   146 */ "CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class",
	/*   147 */ "CSN1_Content_Modulation_based_multislot_class_support",
	/*   148 */ "CSN1_Content_High_Multislot_Capability",
	/*   149 */ "CSN1_Content_GMSK_Multislot_Power_Profile",
	/*   150 */ "CSN1_Content__8_PSK_Multislot_Power_Profile",
	/*   151 */ "CSN1_Content_Multiple_TBF_Capability",
	/*   152 */ "CSN1_Content_Downlink_Advanced_Receiver_Performance",
	/*   153 */ "CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability",
	/*   154 */ "CSN1_Content_DTM_Enhancements_Capability",
	/*   155 */ "CSN1_Content_DTM_GPRS_High_Multi_Slot_Class",
	/*   156 */ "CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class",
	/*   157 */ "CSN1_Content_PS_Handover_Capability",
	/*   158 */ "CSN1_Content_DTM_Handover_Capability",
	/*   159 */ "CSN1_Content_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier",
	/*   160 */ "CSN1_Content_Downlink_Dual_Carrier_for_DTM_Capability",
	/*   161 */ "CSN1_Content_Flexible_Timeslot_Assignment",
	/*   162 */ "CSN1_Content_GAN_PS_Handover_Capability",
	/*   163 */ "CSN1_Content_RLC_Non_persistent_Mode",
	/*   164 */ "CSN1_Content_Reduced_Latency_Capability",
	/*   165 */ "CSN1_Content_Uplink_EGPRS2",
	/*   166 */ "CSN1_Content_Downlink_EGPRS2",
	/*   167 */ "CSN1_Content_E_UTRA_FDD_support",
	/*   168 */ "CSN1_Content_E_UTRA_TDD_support",
	/*   169 */ "CSN1_Content_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode",
	/*   170 */ "CSN1_Content_Priority_based_reselection_support",
	/*   171 */ "CSN1_Content_Enhanced_Flexible_Timeslot_Assignment",
	/*   172 */ "CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_Alternative_EFTA_Multislot_Class",
	/*   173 */ "CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier",
	/*   174 */ "CSN1_Content_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM",
	/*   175 */ "CSN1_Content_EMST_Capability",
	/*   176 */ "CSN1_Content_MTTI_Capability",
	/*   177 */ "CSN1_Content_UTRA_CSG_Cells_Reporting",
	/*   178 */ "CSN1_Content_E_UTRA_CSG_Cells_Reporting",
	/*   179 */ "CSN1_Content_DTR_Capability",
	/*   180 */ "CSN1_Content_EMSR_Capability",
	/*   181 */ "CSN1_Content_Fast_Downlink_Frequency_Switching_Capability",
	/*   182 */ "CSN1_Content_TIGHTER_Capability",
	/*   183 */ "CSN1_Content_FANR_Capability",
	/*   184 */ "CSN1_Content_IPA_Capability",
	/*   185 */ "CSN1_Content_GERAN_Network_Sharing_support",
	/*   186 */ "CSN1_Content_E_UTRA_Wideband_RSRQ_measurements_support",
	/*   187 */ "CSN1_Content_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*   188 */ "CSN1_Content_E_UTRA_Multiple_Frequency_Band_Indicators_support",
	/*   189 */ "CSN1_Content_DLMC_Capability",
	/*   190 */ "CSN1_DLMC_Capability_struct_DLMC_Non_contiguous_intra_band_reception",
	/*   191 */ "CSN1_DLMC_Capability_struct_DLMC_Inter_band_reception",
	/*   192 */ "CSN1_DLMC_Capability_struct_DLMC_Maximum_Bandwidth",
	/*   193 */ "CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Timeslots",
	/*   194 */ "CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Carriers",
	/*   195 */ "CSN1_Content_Extended_TSC_Set_Capability_support",
	/*   196 */ "CSN1_Content_Extended_EARFCN_value_range",
	/*   197 */ "CSN1_MS_RA_capability_value_part_struct_Length",
	/*   198 */ "CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies",
	/*   199 */ "CSN1_Additional_access_technologies_struct_Access_Technology_Type",
	/*   200 */ "CSN1_Additional_access_technologies_struct_GMSK_Power_Class",
	/*   201 */ "CSN1_Additional_access_technologies_struct__8PSK_Power_Class",
	/*   202 */ "CSN1_MsRadioAccessCpblty_MS_RA_capability_value_part",
	NULL
};
#endif

#ifdef CSN1C_ENABLE_LABEL_SIZE
/* For each label id, there is an entry describing its size */
const unsigned char Program_L3_LabelSize [] = {

	/*     0 */ 1, /* CSN1_A5_CM3_bits_A5_7 */
	/*     1 */ 1, /* CSN1_A5_CM3_bits_A5_6 */
	/*     2 */ 1, /* CSN1_A5_CM3_bits_A5_5 */
	/*     3 */ 1, /* CSN1_A5_CM3_bits_A5_4 */
	/*     4 */ 4, /* CSN1_GERAN_Iu_Mode_Capabilities_Length */
	/*     5 */ 1, /* CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability */
	/*     6 */ 4, /* CSN1_Receive_N_Pdu_Numbers_List_val_sapi */
	/*     7 */ 8, /* CSN1_Receive_N_Pdu_Numbers_List_val_Receive_N_PDU_Number_value */
	/*     8 */ 3, /* CSN1_ProtocolCfgOpt_ConfigurationProtocol */
	/*     9 */ 0, /* CSN1_ProtocolCfgOpt_ProtocolCfgs */
	/*    10 */ 16, /* CSN1_ProtocolCfgOpt_ProtocolId */
	/*    11 */ 8, /* CSN1_ProtocolCfgOpt_Length */
	/*    12 */ 0, /* CSN1_ProtocolCfgOpt_Contents */
	/*    13 */ 0, /* CSN1_ProtocolCfgOpt_ContainerCfgs */
	/*    14 */ 16, /* CSN1_ProtocolCfgOpt_ContainerId */
	/*    15 */ 3, /* CSN1_Classmark3Value_Multiband_supported */
	/*    16 */ 4, /* CSN1_Classmark3Value_Associated_Radio_Capability_2 */
	/*    17 */ 4, /* CSN1_Classmark3Value_Associated_Radio_Capability_1 */
	/*    18 */ 3, /* CSN1_R_Support_R_GSM_band_Associated_Radio_Capability */
	/*    19 */ 5, /* CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class */
	/*    20 */ 1, /* CSN1_Classmark3Value_UCS2_treatment */
	/*    21 */ 1, /* CSN1_Classmark3Value_Extended_Measurement_Capability */
	/*    22 */ 4, /* CSN1_MS_Measurement_capability_SMS_VALUE */
	/*    23 */ 4, /* CSN1_MS_Measurement_capability_SM_VALUE */
	/*    24 */ 5, /* CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method */
	/*    25 */ 5, /* CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class */
	/*    26 */ 1, /* CSN1__8_PSK_Struct_Modulation_Capability */
	/*    27 */ 2, /* CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1 */
	/*    28 */ 2, /* CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2 */
	/*    29 */ 2, /* CSN1_Classmark3Value_GSM_400_Bands_Supported */
	/*    30 */ 4, /* CSN1_Classmark3Value_GSM_400_Associated_Radio_Capability */
	/*    31 */ 4, /* CSN1_Classmark3Value_GSM_850_Associated_Radio_Capability */
	/*    32 */ 4, /* CSN1_Classmark3Value_GSM_1900_Associated_Radio_Capability */
	/*    33 */ 1, /* CSN1_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability */
	/*    34 */ 1, /* CSN1_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */
	/*    35 */ 1, /* CSN1_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability */
	/*    36 */ 2, /* CSN1_Classmark3Value_DTM_GPRS_Multi_Slot_Class */
	/*    37 */ 1, /* CSN1_Classmark3Value_Single_Slot_DTM */
	/*    38 */ 2, /* CSN1_Classmark3Value_DTM_EGPRS_Multi_Slot_Class */
	/*    39 */ 4, /* CSN1_Single_Band_Support_GSM_Band */
	/*    40 */ 4, /* CSN1_Classmark3Value_GSM_750_Associated_Radio_Capability */
	/*    41 */ 1, /* CSN1_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */
	/*    42 */ 1, /* CSN1_Classmark3Value_GERAN_Feature_Package_1 */
	/*    43 */ 2, /* CSN1_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class */
	/*    44 */ 2, /* CSN1_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class */
	/*    45 */ 2, /* CSN1_Classmark3Value_High_Multislot_Capability */
	/*    46 */ 1, /* CSN1_Classmark3Value_GERAN_Feature_Package_2 */
	/*    47 */ 2, /* CSN1_Classmark3Value_GMSK_Multislot_Power_Profile */
	/*    48 */ 2, /* CSN1_Classmark3Value__8_PSK_Multislot_Power_Profile */
	/*    49 */ 2, /* CSN1_Classmark3Value_T_GSM_400_Bands_Supported */
	/*    50 */ 4, /* CSN1_Classmark3Value_T_GSM_400_Associated_Radio_Capability */
	/*    51 */ 4, /* CSN1_Classmark3Value_T_GSM_900_Associated_Radio_Capability */
	/*    52 */ 2, /* CSN1_Classmark3Value_Downlink_Advanced_Receiver_Performance */
	/*    53 */ 1, /* CSN1_Classmark3Value_DTM_Enhancements_Capability */
	/*    54 */ 3, /* CSN1_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class */
	/*    55 */ 1, /* CSN1_Classmark3Value_Offset_required */
	/*    56 */ 3, /* CSN1_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class */
	/*    57 */ 1, /* CSN1_Classmark3Value_Repeated_ACCH_Capability */
	/*    58 */ 4, /* CSN1_Classmark3Value_GSM_710_Associated_Radio_Capability */
	/*    59 */ 4, /* CSN1_Classmark3Value_T_GSM_810_Associated_Radio_Capability */
	/*    60 */ 1, /* CSN1_Classmark3Value_Ciphering_Mode_Setting_Capability */
	/*    61 */ 1, /* CSN1_Classmark3Value_Additional_Positioning_Capabilities */
	/*    62 */ 1, /* CSN1_Classmark3Value_E_UTRA_FDD_support */
	/*    63 */ 1, /* CSN1_Classmark3Value_E_UTRA_TDD_support */
	/*    64 */ 1, /* CSN1_Classmark3Value_E_UTRA_Measurement_and_Reporting_support */
	/*    65 */ 1, /* CSN1_Classmark3Value_Priority_based_reselection_support */
	/*    66 */ 1, /* CSN1_Classmark3Value_UTRA_CSG_Cells_Reporting */
	/*    67 */ 2, /* CSN1_Classmark3Value_VAMOS_Level */
	/*    68 */ 2, /* CSN1_Classmark3Value_TIGHTER_Capability */
	/*    69 */ 1, /* CSN1_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH */
	/*    70 */ 2, /* CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA */
	/*    71 */ 2, /* CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA */
	/*    72 */ 1, /* CSN1_Classmark3Value_GERAN_Network_Sharing_support */
	/*    73 */ 1, /* CSN1_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support */
	/*    74 */ 1, /* CSN1_Classmark3Value_ER_Band_Support */
	/*    75 */ 1, /* CSN1_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*    76 */ 1, /* CSN1_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*    77 */ 1, /* CSN1_Classmark3Value_Extended_TSC_Set_Capability_support */
	/*    78 */ 1, /* CSN1_Classmark3Value_Extended_EARFCN_value_range */
	/*    79 */ 1, /* CSN1_GEA1_bits_GEA_1 */
	/*    80 */ 1, /* CSN1_MsNetwkCpblty_SM_capabilities_via_dedicated_channels */
	/*    81 */ 1, /* CSN1_MsNetwkCpblty_SM_capabilities_via_GPRS_channels */
	/*    82 */ 1, /* CSN1_MsNetwkCpblty_UCS2_support */
	/*    83 */ 2, /* CSN1_MsNetwkCpblty_SS_Screening_Indicator */
	/*    84 */ 1, /* CSN1_MsNetwkCpblty_SoLSA_Capability */
	/*    85 */ 1, /* CSN1_MsNetwkCpblty_Revision_level_indicator */
	/*    86 */ 1, /* CSN1_MsNetwkCpblty_PFC_feature_mode */
	/*    87 */ 1, /* CSN1_Extended_GEA_bits_GEA_2 */
	/*    88 */ 1, /* CSN1_Extended_GEA_bits_GEA_3 */
	/*    89 */ 1, /* CSN1_Extended_GEA_bits_GEA_4 */
	/*    90 */ 1, /* CSN1_Extended_GEA_bits_GEA_5 */
	/*    91 */ 1, /* CSN1_Extended_GEA_bits_GEA_6 */
	/*    92 */ 1, /* CSN1_Extended_GEA_bits_GEA_7 */
	/*    93 */ 1, /* CSN1_MsNetwkCpblty_LCS_VA_capability */
	/*    94 */ 1, /* CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability */
	/*    95 */ 1, /* CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability */
	/*    96 */ 1, /* CSN1_MsNetwkCpblty_EMM_Combined_procedures_Capability */
	/*    97 */ 1, /* CSN1_MsNetwkCpblty_ISR_support */
	/*    98 */ 1, /* CSN1_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability */
	/*    99 */ 1, /* CSN1_MsNetwkCpblty_EPC_capability */
	/*   100 */ 1, /* CSN1_MsNetwkCpblty_NF_capability */
	/*   101 */ 1, /* CSN1_MsNetwkCpblty_GERAN_network_sharing_capability */
	/*   102 */ 1, /* CSN1_MsNetwkCpblty_User_plane_integrity_protection_support */
	/*   103 */ 1, /* CSN1_MsNetwkCpblty_GIA_4 */
	/*   104 */ 1, /* CSN1_MsNetwkCpblty_GIA_5 */
	/*   105 */ 1, /* CSN1_MsNetwkCpblty_GIA_6 */
	/*   106 */ 1, /* CSN1_MsNetwkCpblty_GIA_7 */
	/*   107 */ 0, /* CSN1_MS_RA_capability_value_part_struct_MS_RA_capability_value */
	/*   108 */ 4, /* CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type */
	/*   109 */ 0, /* CSN1_MS_RA_capability_value_part_struct_Access_capabilities */
	/*   110 */ 7, /* CSN1_Access_capabilities_struct_Length */
	/*   111 */ 0, /* CSN1_Access_capabilities_struct_Access_capabilities */
	/*   112 */ 3, /* CSN1_Content_RF_Power_Capability */
	/*   113 */ 7, /* CSN1_Content_A5_bits */
	/*   114 */ 1, /* CSN1_A5_5_12_bits_A5_1 */
	/*   115 */ 1, /* CSN1_A5_5_12_bits_A5_2 */
	/*   116 */ 1, /* CSN1_A5_5_12_bits_A5_3 */
	/*   117 */ 1, /* CSN1_A5_5_12_bits_A5_4 */
	/*   118 */ 1, /* CSN1_A5_5_12_bits_A5_5 */
	/*   119 */ 1, /* CSN1_A5_5_12_bits_A5_6 */
	/*   120 */ 1, /* CSN1_A5_5_12_bits_A5_7 */
	/*   121 */ 1, /* CSN1_Content_ES_IND */
	/*   122 */ 1, /* CSN1_Content_PS */
	/*   123 */ 1, /* CSN1_Content_VGCS */
	/*   124 */ 1, /* CSN1_Content_VBS */
	/*   125 */ 0, /* CSN1_Content_Multislot_capability */
	/*   126 */ 5, /* CSN1_Multislot_capability_struct_HSCSD_multislot_class */
	/*   127 */ 5, /* CSN1_Multislot_capability_struct_GPRS_multislot_class */
	/*   128 */ 1, /* CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability */
	/*   129 */ 4, /* CSN1_Multislot_capability_struct_SMS_VALUE */
	/*   130 */ 4, /* CSN1_Multislot_capability_struct_SM_VALUE */
	/*   131 */ 5, /* CSN1_Multislot_capability_struct_ECSD_multislot_class */
	/*   132 */ 5, /* CSN1_Multislot_capability_struct_EGPRS_multislot_class */
	/*   133 */ 1, /* CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability */
	/*   134 */ 2, /* CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class */
	/*   135 */ 1, /* CSN1_Multislot_capability_struct_Single_Slot_DTM */
	/*   136 */ 2, /* CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class */
	/*   137 */ 2, /* CSN1_Content__8PSK_Power_Capability */
	/*   138 */ 1, /* CSN1_Content_COMPACT_Interference_Measurement_Capability */
	/*   139 */ 1, /* CSN1_Content_Revision_Level_Indicator */
	/*   140 */ 1, /* CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability */
	/*   141 */ 1, /* CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability */
	/*   142 */ 1, /* CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability */
	/*   143 */ 1, /* CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability */
	/*   144 */ 1, /* CSN1_Content_GERAN_Feature_Package_1 */
	/*   145 */ 2, /* CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class */
	/*   146 */ 2, /* CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class */
	/*   147 */ 1, /* CSN1_Content_Modulation_based_multislot_class_support */
	/*   148 */ 2, /* CSN1_Content_High_Multislot_Capability */
	/*   149 */ 2, /* CSN1_Content_GMSK_Multislot_Power_Profile */
	/*   150 */ 2, /* CSN1_Content__8_PSK_Multislot_Power_Profile */
	/*   151 */ 1, /* CSN1_Content_Multiple_TBF_Capability */
	/*   152 */ 2, /* CSN1_Content_Downlink_Advanced_Receiver_Performance */
	/*   153 */ 1, /* CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability */
	/*   154 */ 1, /* CSN1_Content_DTM_Enhancements_Capability */
	/*   155 */ 3, /* CSN1_Content_DTM_GPRS_High_Multi_Slot_Class */
	/*   156 */ 3, /* CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class */
	/*   157 */ 1, /* CSN1_Content_PS_Handover_Capability */
	/*   158 */ 1, /* CSN1_Content_DTM_Handover_Capability */
	/*   159 */ 3, /* CSN1_Content_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier */
	/*   160 */ 1, /* CSN1_Content_Downlink_Dual_Carrier_for_DTM_Capability */
	/*   161 */ 1, /* CSN1_Content_Flexible_Timeslot_Assignment */
	/*   162 */ 1, /* CSN1_Content_GAN_PS_Handover_Capability */
	/*   163 */ 1, /* CSN1_Content_RLC_Non_persistent_Mode */
	/*   164 */ 1, /* CSN1_Content_Reduced_Latency_Capability */
	/*   165 */ 2, /* CSN1_Content_Uplink_EGPRS2 */
	/*   166 */ 2, /* CSN1_Content_Downlink_EGPRS2 */
	/*   167 */ 1, /* CSN1_Content_E_UTRA_FDD_support */
	/*   168 */ 1, /* CSN1_Content_E_UTRA_TDD_support */
	/*   169 */ 2, /* CSN1_Content_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode */
	/*   170 */ 1, /* CSN1_Content_Priority_based_reselection_support */
	/*   171 */ 0, /* CSN1_Content_Enhanced_Flexible_Timeslot_Assignment */
	/*   172 */ 4, /* CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_Alternative_EFTA_Multislot_Class */
	/*   173 */ 3, /* CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier */
	/*   174 */ 1, /* CSN1_Content_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM */
	/*   175 */ 1, /* CSN1_Content_EMST_Capability */
	/*   176 */ 1, /* CSN1_Content_MTTI_Capability */
	/*   177 */ 1, /* CSN1_Content_UTRA_CSG_Cells_Reporting */
	/*   178 */ 1, /* CSN1_Content_E_UTRA_CSG_Cells_Reporting */
	/*   179 */ 1, /* CSN1_Content_DTR_Capability */
	/*   180 */ 1, /* CSN1_Content_EMSR_Capability */
	/*   181 */ 1, /* CSN1_Content_Fast_Downlink_Frequency_Switching_Capability */
	/*   182 */ 2, /* CSN1_Content_TIGHTER_Capability */
	/*   183 */ 1, /* CSN1_Content_FANR_Capability */
	/*   184 */ 1, /* CSN1_Content_IPA_Capability */
	/*   185 */ 1, /* CSN1_Content_GERAN_Network_Sharing_support */
	/*   186 */ 1, /* CSN1_Content_E_UTRA_Wideband_RSRQ_measurements_support */
	/*   187 */ 1, /* CSN1_Content_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*   188 */ 1, /* CSN1_Content_E_UTRA_Multiple_Frequency_Band_Indicators_support */
	/*   189 */ 0, /* CSN1_Content_DLMC_Capability */
	/*   190 */ 2, /* CSN1_DLMC_Capability_struct_DLMC_Non_contiguous_intra_band_reception */
	/*   191 */ 1, /* CSN1_DLMC_Capability_struct_DLMC_Inter_band_reception */
	/*   192 */ 2, /* CSN1_DLMC_Capability_struct_DLMC_Maximum_Bandwidth */
	/*   193 */ 6, /* CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Timeslots */
	/*   194 */ 3, /* CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Carriers */
	/*   195 */ 1, /* CSN1_Content_Extended_TSC_Set_Capability_support */
	/*   196 */ 1, /* CSN1_Content_Extended_EARFCN_value_range */
	/*   197 */ 7, /* CSN1_MS_RA_capability_value_part_struct_Length */
	/*   198 */ 9, /* CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies */
	/*   199 */ 4, /* CSN1_Additional_access_technologies_struct_Access_Technology_Type */
	/*   200 */ 3, /* CSN1_Additional_access_technologies_struct_GMSK_Power_Class */
	/*   201 */ 2, /* CSN1_Additional_access_technologies_struct__8PSK_Power_Class */
	/*   202 */ 0  /* CSN1_MsRadioAccessCpblty_MS_RA_capability_value_part */
};
#endif

/* FieldId Pair Set */
static const CSN1C_PAIRSET_TYPE Program_L3_FieldIdPairSet [] = {
	/* 0000 (ID:0456:115615:115630) <A5_7> */ 0,1,34,2,103,
	/* 0005 (ID:0460:115630:115645) <A5_6> */ 1,1,35,2,104,
	/* 0010 (ID:0464:115645:115660) <A5_5> */ 2,1,36,2,105,
	/* 0015 (ID:0468:115660:115676) <A5_4> */ 3,1,37,2,106,
	/* 0020 (ID:0538:116749:116836) <Length> */ 4,1,68,10,117,22,281,165,185,
	/* 0029 (ID:0543:117018:117049) <FLO_Iu_Capability> */ 5,1,69,10,118,22,282,165,186,
	/* 0038 (ID:0557:167141:167162) <sapi> */ 6,11,119,12,121,
	/* 0043 (ID:0561:167162:167202) <Receive_N_PDU_Number_value> */ 7,11,120,12,122,
	/* 0048 (ID:1351:183376:183410) <ConfigurationProtocol> */ 8,27,349,
	/* 0051 (ID:1355:183410:183616) <ProtocolCfgs> */ 9,27,350,
	/* 0054 (ID:1358:183426:183566) <ProtocolId> */ 10,350,352,
	/* 0057 (ID:1364:183566:183584) <Length> */ 11,350,353,
	/* 0060 (ID:1368:183584:183615) <Contents> */ 12,350,354,
	/* 0063 (ID:1372:183622:184753) <ContainerCfgs> */ 13,27,351,
	/* 0066 (ID:1375:183639:184703) <ContainerId> */ 14,351,355,
	/* 0069 (ID:1379:184703:184721) <Length> */ 11,351,356,
	/* 0072 (ID:1383:184721:184752) <Contents> */ 12,351,357,
	/* 0075 (ID:0015:111007:111052) <Multiband_supported> */ 15,1,33,
	/* 0078 (ID:0028:111072:111119) <Associated_Radio_Capability_2> */ 16,1,38,
	/* 0081 (ID:0032:111119:111164) <Associated_Radio_Capability_1> */ 17,1,39,
	/* 0084 (ID:0037:111166:111217) <Multiband_supported> */ 15,1,33,
	/* 0087 (ID:0055:111258:111301) <Associated_Radio_Capability_1> */ 17,1,39,
	/* 0090 (ID:0005:110948:110986) <Multiband_supported> */ 15,1,33,
	/* 0093 (ID:0474:115704:115756) <R_GSM_band_Associated_Radio_Capability> */ 18,1,40,3,107,
	/* 0098 (ID:0480:115805:115842) <HSCSD_Multi_Slot_Class> */ 19,1,41,4,108,
	/* 0103 (ID:0071:111375:111401) <UCS2_treatment> */ 20,1,42,
	/* 0106 (ID:0075:111401:111445) <Extended_Measurement_Capability> */ 21,1,43,
	/* 0109 (ID:0486:115889:115915) <SMS_VALUE> */ 22,1,44,5,109,
	/* 0114 (ID:0490:115915:115938) <SM_VALUE> */ 23,1,45,5,110,
	/* 0119 (ID:0496:115992:116027) <MS_Positioning_Method> */ 24,1,46,6,111,
	/* 0124 (ID:0502:116075:116110) <ECSD_Multi_Slot_Class> */ 25,1,47,7,112,
	/* 0129 (ID:0508:116143:116177) <Modulation_Capability> */ 26,1,48,8,113,
	/* 0134 (ID:0517:116185:116225) <_8_PSK_RF_Power_Capability_1> */ 27,1,49,8,114,
	/* 0139 (ID:0526:116237:116277) <_8_PSK_RF_Power_Capability_2> */ 28,1,50,8,115,
	/* 0144 (ID:0108:111616:111849) <GSM_400_Bands_Supported> */ 29,1,51,
	/* 0147 (ID:0121:111849:111897) <GSM_400_Associated_Radio_Capability> */ 30,1,52,
	/* 0150 (ID:0130:111911:111959) <GSM_850_Associated_Radio_Capability> */ 31,1,53,
	/* 0153 (ID:0139:111971:112020) <GSM_1900_Associated_Radio_Capability> */ 32,1,54,
	/* 0156 (ID:0143:112024:112080) <UMTS_FDD_Radio_Access_Technology_Capability> */ 33,1,55,
	/* 0159 (ID:0147:112080:112146) <UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> */ 34,1,56,
	/* 0162 (ID:0151:112146:112205) <CDMA_2000_Radio_Access_Technology_Capability> */ 35,1,57,
	/* 0165 (ID:0160:112213:112256) <DTM_GPRS_Multi_Slot_Class> */ 36,1,58,
	/* 0168 (ID:0164:112256:112286) <Single_Slot_DTM> */ 37,1,59,
	/* 0171 (ID:0173:112292:112332) <DTM_EGPRS_Multi_Slot_Class> */ 38,1,60,
	/* 0174 (ID:0532:116319:116700) <GSM_Band> */ 39,1,61,9,116,
	/* 0179 (ID:0192:112433:112479) <GSM_750_Associated_Radio_Capability> */ 40,1,62,
	/* 0182 (ID:0196:112487:112554) <UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> */ 41,1,63,
	/* 0185 (ID:0200:112554:112594) <GERAN_Feature_Package_1> */ 42,1,64,
	/* 0188 (ID:0209:112602:112869) <Extended_DTM_GPRS_Multi_Slot_Class> */ 43,1,65,
	/* 0191 (ID:0213:112869:112918) <Extended_DTM_EGPRS_Multi_Slot_Class> */ 44,1,66,
	/* 0194 (ID:0226:112950:112989) <High_Multislot_Capability> */ 45,1,67,
	/* 0197 (ID:0236:113120:113162) <GERAN_Feature_Package_2> */ 46,1,70,
	/* 0200 (ID:0240:113162:113209) <GMSK_Multislot_Power_Profile> */ 47,1,71,
	/* 0203 (ID:0244:113209:113261) <_8_PSK_Multislot_Power_Profile> */ 48,1,72,
	/* 0206 (ID:0257:113286:113369) <T_GSM_400_Bands_Supported> */ 49,1,73,
	/* 0209 (ID:0270:113369:113419) <T_GSM_400_Associated_Radio_Capability> */ 50,1,74,
	/* 0212 (ID:0279:113439:113489) <T_GSM_900_Associated_Radio_Capability> */ 51,1,75,
	/* 0215 (ID:0283:113496:113558) <Downlink_Advanced_Receiver_Performance> */ 52,1,76,
	/* 0218 (ID:0287:113558:113606) <DTM_Enhancements_Capability> */ 53,1,77,
	/* 0221 (ID:0296:113614:113665) <DTM_GPRS_High_Multi_Slot_Class> */ 54,1,78,
	/* 0224 (ID:0300:113665:113697) <Offset_required> */ 55,1,79,
	/* 0227 (ID:0309:113705:113750) <DTM_EGPRS_High_Multi_Slot_Class> */ 56,1,80,
	/* 0230 (ID:0313:113764:113809) <Repeated_ACCH_Capability> */ 57,1,81,
	/* 0233 (ID:0326:113835:113881) <GSM_710_Associated_Radio_Capability> */ 58,1,82,
	/* 0236 (ID:0335:113925:113973) <T_GSM_810_Associated_Radio_Capability> */ 59,1,83,
	/* 0239 (ID:0339:113981:114037) <Ciphering_Mode_Setting_Capability> */ 60,1,84,
	/* 0242 (ID:0343:114037:114095) <Additional_Positioning_Capabilities> */ 61,1,85,
	/* 0245 (ID:0351:114114:114185) <E_UTRA_FDD_support> */ 62,1,86,
	/* 0248 (ID:0355:114185:114221) <E_UTRA_TDD_support> */ 63,1,87,
	/* 0251 (ID:0359:114221:114279) <E_UTRA_Measurement_and_Reporting_support> */ 64,1,88,
	/* 0254 (ID:0363:114279:114338) <Priority_based_reselection_support> */ 65,1,89,
	/* 0257 (ID:0371:114358:114432) <UTRA_CSG_Cells_Reporting> */ 66,1,90,
	/* 0260 (ID:0375:114432:114465) <VAMOS_Level> */ 67,1,91,
	/* 0263 (ID:0383:114487:114562) <TIGHTER_Capability> */ 68,1,92,
	/* 0266 (ID:0387:114562:114620) <Selective_Ciphering_of_Downlink_SACCH> */ 69,1,93,
	/* 0269 (ID:0395:114643:114729) <CS_to_PS_SRVCC_from_GERAN_to_UTRA> */ 70,1,94,
	/* 0272 (ID:0399:114729:114797) <CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> */ 71,1,95,
	/* 0275 (ID:0403:114797:114847) <GERAN_Network_Sharing_support> */ 72,1,96,
	/* 0278 (ID:0407:114847:114919) <E_UTRA_Wideband_RSRQ_measurements_support> */ 73,1,97,
	/* 0281 (ID:0415:114943:115016) <ER_Band_Support> */ 74,1,98,
	/* 0284 (ID:0419:115016:115085) <UTRA_Multiple_Frequency_Band_Indicators_support> */ 75,1,99,
	/* 0287 (ID:0423:115085:115155) <E_UTRA_Multiple_Frequency_Band_Indicators_support> */ 76,1,100,
	/* 0290 (ID:0427:115155:115211) <Extended_TSC_Set_Capability_support> */ 77,1,101,
	/* 0293 (ID:0431:115211:115305) <Extended_EARFCN_value_range> */ 78,1,102,
	/* 0296 (ID:0751:168598:168611) <GEA_1> */ 79,15,123,16,151,
	/* 0301 (ID:0659:167782:167832) <SM_capabilities_via_dedicated_channels> */ 80,15,124,
	/* 0304 (ID:0663:167832:167877) <SM_capabilities_via_GPRS_channels> */ 81,15,125,
	/* 0307 (ID:0667:167877:167901) <UCS2_support> */ 82,15,126,
	/* 0310 (ID:0671:167901:167938) <SS_Screening_Indicator> */ 83,15,127,
	/* 0313 (ID:0675:167938:167967) <SoLSA_Capability> */ 84,15,128,
	/* 0316 (ID:0679:167967:168003) <Revision_level_indicator> */ 85,15,129,
	/* 0319 (ID:0685:168010:168039) <PFC_feature_mode> */ 86,15,130,
	/* 0322 (ID:0757:168645:168656) <GEA_2> */ 87,15,131,17,152,
	/* 0327 (ID:0761:168656:168667) <GEA_3> */ 88,15,132,17,153,
	/* 0332 (ID:0765:168667:168680) <GEA_4> */ 89,15,133,17,154,
	/* 0337 (ID:0769:168680:168693) <GEA_5> */ 90,15,134,17,155,
	/* 0342 (ID:0773:168693:168706) <GEA_6> */ 91,15,135,17,156,
	/* 0347 (ID:0777:168706:168717) <GEA_7> */ 92,15,136,17,157,
	/* 0352 (ID:0690:168064:168091) <LCS_VA_capability> */ 93,15,137,
	/* 0355 (ID:0694:168091:168155) <PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> */ 94,15,138,
	/* 0358 (ID:0698:168155:168221) <PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> */ 95,15,139,
	/* 0361 (ID:0702:168221:168268) <EMM_Combined_procedures_Capability> */ 96,15,140,
	/* 0364 (ID:0706:168268:168289) <ISR_support> */ 97,15,141,
	/* 0367 (ID:0710:168289:168330) <SRVCC_to_GERAN_UTRAN_capability> */ 98,15,142,
	/* 0370 (ID:0714:168330:168354) <EPC_capability> */ 99,15,143,
	/* 0373 (ID:0718:168354:168377) <NF_capability> */ 100,15,144,
	/* 0376 (ID:0724:168392:168435) <GERAN_network_sharing_capability> */ 101,15,145,
	/* 0379 (ID:0728:168435:168485) <User_plane_integrity_protection_support> */ 102,15,146,
	/* 0382 (ID:0732:168485:168501) <GIA_4> */ 103,15,147,
	/* 0385 (ID:0736:168501:168517) <GIA_5> */ 104,15,148,
	/* 0388 (ID:0740:168517:168533) <GIA_6> */ 105,15,149,
	/* 0391 (ID:0744:168533:168548) <GIA_7> */ 106,15,150,
	/* 0394 (ID:0790:169161:170408) <MS_RA_capability_value> */ 107,19,256,158,159,
	/* 0399 (ID:0795:169189:169706) <Access_Technology_Type> */ 108,159,160,
	/* 0402 (ID:0805:169706:169763) <Access_capabilities> */ 109,159,161,
	/* 0405 (ID:0857:170663:170730) <Length> */ 110,21,260,161,164,
	/* 0410 (ID:0862:170882:170918) <Access_capabilities> */ 111,21,261,161,165,
	/* 0415 (ID:0874:171118:171155) <RF_Power_Capability> */ 112,22,262,165,166,
	/* 0420 (ID:0883:171163:171191) <A5_bits> */ 113,22,263,165,167,
	/* 0425 (ID:1301:176055:176069) <A5_1> */ 114,25,340,167,228,
	/* 0430 (ID:1305:176069:176082) <A5_2> */ 115,25,341,167,229,
	/* 0435 (ID:1309:176082:176095) <A5_3> */ 116,25,342,167,230,
	/* 0440 (ID:1313:176095:176108) <A5_4> */ 117,25,343,167,231,
	/* 0445 (ID:1317:176108:176121) <A5_5> */ 118,25,344,167,232,
	/* 0450 (ID:1321:176121:176134) <A5_6> */ 119,25,345,167,233,
	/* 0455 (ID:1325:176134:176146) <A5_7> */ 120,25,346,167,234,
	/* 0460 (ID:0887:171326:171346) <ES_IND> */ 121,22,264,165,168,
	/* 0465 (ID:0891:171346:171362) <PS> */ 122,22,265,165,169,
	/* 0470 (ID:0895:171362:171380) <VGCS> */ 123,22,266,165,170,
	/* 0475 (ID:0899:171380:171397) <VBS> */ 124,22,267,165,171,
	/* 0480 (ID:0908:171405:171460) <Multislot_capability> */ 125,22,268,165,172,
	/* 0485 (ID:1223:175320:175356) <HSCSD_multislot_class> */ 126,24,329,172,235,
	/* 0490 (ID:1232:175370:175405) <GPRS_multislot_class> */ 127,24,330,172,236,
	/* 0495 (ID:1236:175405:175459) <GPRS_Extended_Dynamic_Allocation_Capability> */ 128,24,331,172,237,
	/* 0500 (ID:1245:175473:175498) <SMS_VALUE> */ 129,24,332,172,238,
	/* 0505 (ID:1249:175498:175522) <SM_VALUE> */ 130,24,333,172,239,
	/* 0510 (ID:1260:175578:175613) <ECSD_multislot_class> */ 131,24,334,172,240,
	/* 0515 (ID:1269:175627:175663) <EGPRS_multislot_class> */ 132,24,335,172,241,
	/* 0520 (ID:1273:175663:175718) <EGPRS_Extended_Dynamic_Allocation_Capability> */ 133,24,336,172,242,
	/* 0525 (ID:1282:175731:175774) <DTM_GPRS_Multi_Slot_Class> */ 134,24,337,172,243,
	/* 0530 (ID:1286:175774:175904) <Single_Slot_DTM> */ 135,24,338,172,244,
	/* 0535 (ID:1295:175911:175949) <DTM_EGPRS_Multi_Slot_Class> */ 136,24,339,172,245,
	/* 0540 (ID:0919:171649:171683) <_8PSK_Power_Capability> */ 137,22,269,165,173,
	/* 0545 (ID:0923:171744:171801) <COMPACT_Interference_Measurement_Capability> */ 138,22,270,165,174,
	/* 0550 (ID:0927:171801:171839) <Revision_Level_Indicator> */ 139,22,271,165,175,
	/* 0555 (ID:0931:171839:171910) <UMTS_FDD_Radio_Access_Technology_Capability> */ 140,22,272,165,176,
	/* 0560 (ID:0935:171910:171988) <UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> */ 141,22,273,165,177,
	/* 0565 (ID:0939:171988:172059) <CDMA_2000_Radio_Access_Technology_Capability> */ 142,22,274,165,178,
	/* 0570 (ID:0945:172095:172171) <UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> */ 143,22,275,165,179,
	/* 0575 (ID:0949:172171:172208) <GERAN_Feature_Package_1> */ 144,22,276,165,180,
	/* 0580 (ID:0958:172216:172269) <Extended_DTM_GPRS_Multi_Slot_Class> */ 145,22,277,165,181,
	/* 0585 (ID:0962:172269:172318) <Extended_DTM_EGPRS_Multi_Slot_Class> */ 146,22,278,165,182,
	/* 0590 (ID:0966:172323:172376) <Modulation_based_multislot_class_support> */ 147,22,279,165,183,
	/* 0595 (ID:0977:172420:172459) <High_Multislot_Capability> */ 148,22,280,165,184,
	/* 0600 (ID:0987:172552:172598) <GMSK_Multislot_Power_Profile> */ 149,22,283,165,187,
	/* 0605 (ID:0991:172598:172645) <_8_PSK_Multislot_Power_Profile> */ 150,22,284,165,188,
	/* 0610 (ID:0997:172681:172718) <Multiple_TBF_Capability> */ 151,22,285,165,189,
	/* 0615 (ID:1001:172718:172773) <Downlink_Advanced_Receiver_Performance> */ 152,22,286,165,190,
	/* 0620 (ID:1005:172773:172843) <Extended_RLC_MAC_Control_Message_Segmentation_Capability> */ 153,22,287,165,191,
	/* 0625 (ID:1009:172843:172884) <DTM_Enhancements_Capability> */ 154,22,288,165,192,
	/* 0630 (ID:1018:172892:172941) <DTM_GPRS_High_Multi_Slot_Class> */ 155,22,289,165,193,
	/* 0635 (ID:1027:172949:172994) <DTM_EGPRS_High_Multi_Slot_Class> */ 156,22,290,165,194,
	/* 0640 (ID:1031:173001:173036) <PS_Handover_Capability> */ 157,22,291,165,195,
	/* 0645 (ID:1037:173072:173109) <DTM_Handover_Capability> */ 158,22,292,165,196,
	/* 0650 (ID:1046:173117:173192) <Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> */ 159,22,293,165,197,
	/* 0655 (ID:1050:173192:173242) <Downlink_Dual_Carrier_for_DTM_Capability> */ 160,22,294,165,198,
	/* 0660 (ID:1054:173247:173293) <Flexible_Timeslot_Assignment> */ 161,22,295,165,199,
	/* 0665 (ID:1058:173293:173333) <GAN_PS_Handover_Capability> */ 162,22,296,165,200,
	/* 0670 (ID:1062:173333:173370) <RLC_Non_persistent_Mode> */ 163,22,297,165,201,
	/* 0675 (ID:1066:173370:173410) <Reduced_Latency_Capability> */ 164,22,298,165,202,
	/* 0680 (ID:1070:173410:173441) <Uplink_EGPRS2> */ 165,22,299,165,203,
	/* 0685 (ID:1074:173441:173472) <Downlink_EGPRS2> */ 166,22,300,165,204,
	/* 0690 (ID:1080:173508:173541) <E_UTRA_FDD_support> */ 167,22,301,165,205,
	/* 0695 (ID:1084:173541:173573) <E_UTRA_TDD_support> */ 168,22,302,165,206,
	/* 0700 (ID:1088:173573:173642) <GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode> */ 169,22,303,165,207,
	/* 0705 (ID:1092:173642:173689) <Priority_based_reselection_support> */ 170,22,304,165,208,
	/* 0710 (ID:1098:173725:173816) <Enhanced_Flexible_Timeslot_Assignment> */ 171,22,305,165,209,
	/* 0715 (ID:1336:176222:176271) <Alternative_EFTA_Multislot_Class> */ 172,26,347,209,246,
	/* 0720 (ID:1340:176271:176346) <EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> */ 173,26,348,209,247,
	/* 0725 (ID:1102:173816:173887) <Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM> */ 174,22,306,165,210,
	/* 0730 (ID:1106:173887:173916) <EMST_Capability> */ 175,22,307,165,211,
	/* 0735 (ID:1110:173916:173945) <MTTI_Capability> */ 176,22,308,165,212,
	/* 0740 (ID:1114:173945:173983) <UTRA_CSG_Cells_Reporting> */ 177,22,309,165,213,
	/* 0745 (ID:1118:173983:174022) <E_UTRA_CSG_Cells_Reporting> */ 178,22,310,165,214,
	/* 0750 (ID:1124:174059:174087) <DTR_Capability> */ 179,22,311,165,215,
	/* 0755 (ID:1128:174087:174116) <EMSR_Capability> */ 180,22,312,165,216,
	/* 0760 (ID:1132:174116:174174) <Fast_Downlink_Frequency_Switching_Capability> */ 181,22,313,165,217,
	/* 0765 (ID:1136:174174:174208) <TIGHTER_Capability> */ 182,22,314,165,218,
	/* 0770 (ID:1142:174245:174274) <FANR_Capability> */ 183,22,315,165,219,
	/* 0775 (ID:1146:174274:174301) <IPA_Capability> */ 184,22,316,165,220,
	/* 0780 (ID:1150:174301:174343) <GERAN_Network_Sharing_support> */ 185,22,317,165,221,
	/* 0785 (ID:1154:174343:174396) <E_UTRA_Wideband_RSRQ_measurements_support> */ 186,22,318,165,222,
	/* 0790 (ID:1160:174433:174494) <UTRA_Multiple_Frequency_Band_Indicators_support> */ 187,22,319,165,223,
	/* 0795 (ID:1164:174494:174557) <E_UTRA_Multiple_Frequency_Band_Indicators_support> */ 188,22,320,165,224,
	/* 0800 (ID:1173:174593:174638) <DLMC_Capability> */ 189,22,321,165,225,
	/* 0805 (ID:1194:174992:175052) <DLMC_Non_contiguous_intra_band_reception> */ 190,23,324,225,248,
	/* 0810 (ID:1198:175052:175093) <DLMC_Inter_band_reception> */ 191,23,325,225,249,
	/* 0815 (ID:1202:175097:175137) <DLMC_Maximum_Bandwidth> */ 192,23,326,225,250,
	/* 0820 (ID:1206:175137:175196) <DLMC_Maximum_Number_of_Downlink_Timeslots> */ 193,23,327,225,251,
	/* 0825 (ID:1210:175196:175252) <DLMC_Maximum_Number_of_Downlink_Carriers> */ 194,23,328,225,252,
	/* 0830 (ID:1177:174643:174691) <Extended_TSC_Set_Capability_support> */ 195,22,322,165,226,
	/* 0835 (ID:1183:174742:174780) <Extended_EARFCN_value_range> */ 196,22,323,165,227,
	/* 0840 (ID:0812:169777:169876) <Access_Technology_Type> */ 108,159,160,
	/* 0843 (ID:0819:169876:169977) <Length> */ 197,159,162,
	/* 0846 (ID:0828:170140:170222) <Additional_access_technologies> */ 198,159,163,
	/* 0849 (ID:0843:170513:170552) <Access_Technology_Type> */ 199,20,257,163,253,
	/* 0854 (ID:0847:170552:170585) <GMSK_Power_Class> */ 200,20,258,163,254,
	/* 0859 (ID:0851:170585:170616) <_8PSK_Power_Class> */ 201,20,259,163,255,
	/* 0864 (ID:0783:168914:168988) <MS_RA_capability_value_part> */ 202,18,158

#ifndef NDEBUG
	, -1, -1 /* Used in conjunction with an assert */
#endif
};

/* CUSTOM EXPRESSION 0 (ID:1371:183595:183598, ID:1386:184732:184735) */
unsigned ED_EXLONG Program_L3_expr0000 (TCSN1CContext* Context) {
	ED_WARNING_REMOVER(Context);
	return (unsigned ED_EXLONG)(TAG(101)*8);
}
/* CUSTOM EXPRESSION 1 (ID:1404:210635:210642, ID:1413:210724:210731) */
unsigned ED_EXLONG Program_L3_expr0001 (TCSN1CContext* Context) {
	ED_WARNING_REMOVER(Context);
	return (unsigned ED_EXLONG)((8 - (CURPOS & 7)) & 7);
}
static const unsigned ED_EXLONG (*const Program_L3_ExpressionMap[]) (TCSN1CContext*) = {
	(const unsigned ED_EXLONG (*const) (TCSN1CContext*))Program_L3_expr0000,
	(const unsigned ED_EXLONG (*const) (TCSN1CContext*))Program_L3_expr0001};
/* CUSTOM ACTION 0 (ID:0542:116836:117018, ID:0823:169977:170131, ID:0861:170730:170882) */
void Program_L3_action0000 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	PUSH_TAG (2, CURPOS);
}}
/* CUSTOM ACTION 1 (ID:0542:116836:117018) */
void Program_L3_action0001 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	PUSH_TAG (1, Context->FinalOffset);	Context->FinalOffset = CURPOS+EDBitsToInt (BUFFER, CURPOS-4, 4);
}}
/* CUSTOM ACTION 2 (ID:0548:117102:117210) */
void Program_L3_action0002 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	EDIntToBits (BUFFER, TAG(2)-7, CURPOS-TAG(2), 4);
}}
/* CUSTOM ACTION 3 (ID:0548:117102:117210, ID:0834:170292:170401, ID:0867:170935:171042) */
void Program_L3_action0003 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	Context->FinalOffset = TAG(1);
}}
/* CUSTOM ACTION 4 (ID:0823:169977:170131, ID:0861:170730:170882) */
void Program_L3_action0004 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	PUSH_TAG (1, Context->FinalOffset);	Context->FinalOffset = CURPOS+EDBitsToInt (BUFFER, CURPOS-7, 7);
}}
/* CUSTOM ACTION 5 (ID:0834:170292:170401, ID:0867:170935:171042) */
void Program_L3_action0005 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	EDIntToBits (BUFFER, TAG(2)-7, CURPOS-TAG(2), 7);
}}
static const void (*const Program_L3_FunctionMap[]) (TCSN1CContext* ED_EXTRAPARAMS_DECL) = {
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0000,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0001,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0002,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0003,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0004,
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_L3_action0005};
/* PROGRAM CODE FOR PROGRAM 'Program_L3' */
static const unsigned char Program_L3_ProgramCode [] = {

	/*-----------------------------------------------------------------
		DEFINITION 'bit'
		DEFINITION FIELD-ID: 28  COMPLEXITY: 5
		SOURCE: ./TS_24.008_Rel13.src, 5830
	-----------------------------------------------------------------*/
	/* 000000 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000001 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bits'
		DEFINITION FIELD-ID: 29  COMPLEXITY: 5
		SOURCE: ./TS_24.008_Rel13.src, 5831
	-----------------------------------------------------------------*/
	/* 000002 */ CSN1C_BIT_A(1),                          /* (ID:1394:210588:210589) */
	/* 000003 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bit'
		DEFINITION FIELD-ID: 30  COMPLEXITY: 5
		SOURCE: ./TS_24.008_Rel13.src, 5832
	-----------------------------------------------------------------*/
	/* 000004 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 4, node 1, jump to 9 */
	/* 000006 */ CSN1C_BIT_L,                             /* (ID:1399:210610:210611) */
	/* 000007 */ CSN1C_GOTO(8),                           /* (ID:1397:210610:210613) jump at 15 */
	/* 000009 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 4, node 2, jump to 14 */
	/* 000011 */ CSN1C_BIT_H,                             /* (ID:1401:210612:210613) */
	/* 000012 */ CSN1C_GOTO(3),                           /* (ID:1397:210610:210613) jump at 15 */
	/* 000014 */ CSN1C_BACKTRACK,                         /* (ID:1397:210610:210613) Failure of choice begun at 4 */
	/* 000015 */ CSN1C_CHOICE_END,                        /* (ID:1397:210610:210613) End of choice begun at 4 */
	/* 000016 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'A5_CM3_bits'
		DEFINITION FIELD-ID: 2  COMPLEXITY: 18
		SOURCE: ./TS_24.008_Rel13.src, 2944
	-----------------------------------------------------------------*/
	/* 000017 */ CSN1C_LABEL_A, CSN1C_VAL1(1), CSN1C_VAL1(1), /* (ID:0456:115615:115630) Label=<A5_7> LabelId=0 */
	/* 000020 */ CSN1C_LABEL_A, CSN1C_VAL1(6), CSN1C_VAL1(1), /* (ID:0460:115630:115645) Label=<A5_6> LabelId=1 */
	/* 000023 */ CSN1C_LABEL_A, CSN1C_VAL1(11), CSN1C_VAL1(1), /* (ID:0464:115645:115660) Label=<A5_5> LabelId=2 */
	/* 000026 */ CSN1C_LABEL_A, CSN1C_VAL1(16), CSN1C_VAL1(1), /* (ID:0468:115660:115676) Label=<A5_4> LabelId=3 */
	/* 000029 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'GERAN_Iu_Mode_Capabilities'
		DEFINITION FIELD-ID: 10  COMPLEXITY: 13
		SOURCE: ./TS_24.008_Rel13.src, 2982
	-----------------------------------------------------------------*/
	/* 000030 */ CSN1C_LABEL_A, CSN1C_VAL1(21), CSN1C_VAL1(4), /* (ID:0538:116749:116836) Label=<Length> LabelId=4 */
	/* 000033 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000035 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(1),
	/* 000037 */ CSN1C_LABEL_A, CSN1C_VAL1(30), CSN1C_VAL1(1), /* (ID:0543:117018:117049) Label=<FLO_Iu_Capability> LabelId=5 */
	/* 000040 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0547:117049:117061) Infinite loop start, jump to 47 */
	/* 000044 */ CSN1C_BIT_A(1),                          /* (ID:1394:210588:210589) */
	/* 000045 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0547:117049:117061) Loop back to 44 */
	/* 000047 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(2),
	/* 000049 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(3),
	/* 000051 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'Receive_N_Pdu_Numbers_List_val'
		DEFINITION FIELD-ID: 12  COMPLEXITY: 15
		SOURCE: ./TS_24.008_Rel13.src, 4554
	-----------------------------------------------------------------*/
	/* 000052 */ CSN1C_LABEL_A, CSN1C_VAL1(39), CSN1C_VAL1(4), /* (ID:0557:167141:167162) Label=<sapi> LabelId=6 */
	/* 000055 */ CSN1C_LABEL_A, CSN1C_VAL1(44), CSN1C_VAL1(8), /* (ID:0561:167162:167202) Label=<Receive_N_PDU_Number_value> LabelId=7 */
	/* 000058 */ CSN1C_CHOICE_NODE(0,6),                  /* (ID:0565:167204:167245) VBIT choice at 58, node 1, jump to 64 */
	/* 000060 */ CSN1C_GOSUB, CSN1C_VAL1(52),             /* (ID:0567:167204:167238) Reference to 'Receive_N_Pdu_Numbers_List_val' */
	/* 000062 */ CSN1C_GOTO(5),                           /* (ID:0565:167204:167245) jump at 67 */
	/* 000064 */ CSN1C_GOTO(4),                           /* (ID:0565:167204:167245) jump at 69 */
	/* 000066 */ CSN1C_BACKTRACK,                         /* (ID:0565:167204:167245) Failure of choice begun at 58 */
	/* 000067 */ CSN1C_CHOICE_END,                        /* (ID:0565:167204:167245) End of choice begun at 58 */
	/* 000068 */ CSN1C_RETURN_LOOPING,
	/*-----------------------------------------------------------------
		DEFINITION 'ProtocolCfgOpt'
		DEFINITION FIELD-ID: 27  COMPLEXITY: 43
		SOURCE: ./TS_24.008_Rel13.src, 5080
	-----------------------------------------------------------------*/
	/* 000069 */ CSN1C_VALUE, CSN1C_VAL2(260),            /* (ID:1346:183369:183371..1350:183374:183376) Bit string '10000' */
	/* 000072 */ CSN1C_LABEL_A, CSN1C_VAL1(49), CSN1C_VAL1(3), /* (ID:1351:183376:183410) Label=<ConfigurationProtocol> LabelId=8 */
	/* 000075 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(82), /* (ID:1355:183410:183616) Infinite loop start, jump to 116 */
	/* 000079 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(104),      /* (ID:1355:183410:183616) Label=<ProtocolCfgs> Terminal=<0> LabelId=9 */
	/* 000081 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(111),      /* (ID:1358:183426:183566) Label=<ProtocolId> Terminal=<1> LabelId=10 */
	/* 000083 */ CSN1C_TAG_POS, CSN1C_VAL1(100),          /* (ID:1362::) Tag=<100> - Tagging position */
	/* 000085 */ CSN1C_BIT_A(16),                         /* (ID:1389:210565:210566) */
	/* 000086 */ CSN1C_SUBCLASS_RANGE, CSN1C_VAL1(100), CSN1C_VAL1(16), CSN1C_VAL3(65535), /* (ID:1363:183546:183562) Subclassing (:=16..65535) */
	/* 000092 */ CSN1C_LABEL_END, CSN1C_VAL1(111),        /* (ID:1358:183426:183566) Label=<ProtocolId> Terminal=<1> */
	/* 000094 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(117),      /* (ID:1364:183566:183584) Label=<Length> Terminal=<1> LabelId=11 */
	/* 000096 */ CSN1C_BIT_A(8),                          /* (ID:1389:210565:210566) */
	/* 000097 */ CSN1C_LABEL_END_TAG, CSN1C_VAL1(117), CSN1C_VAL1(101), /* (ID:1364:183566:183584) Label=<Length> Tag=<101> Terminal=<1> */
	/* 000100 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(123),      /* (ID:1368:183584:183615) Label=<Contents> Terminal=<1> LabelId=12 */
	/* 000102 */ CSN1C_LOOP_BEGIN_VAR_ED1, CSN1C_VAL3(17), CSN1C_VAL1(0), /* (ID:1371:183595:183598) Custom expression based loop. If expr returns 0, jump to 110 OPT=<> REP=<-1> ?Repetitions=<-1> extReps=<1> */
	/* 000107 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000108 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:1371:183595:183598) Loop back to 107 */
	/* 000110 */ CSN1C_LABEL_END, CSN1C_VAL1(123),        /* (ID:1368:183584:183615) Label=<Contents> Terminal=<1> */
	/* 000112 */ CSN1C_LABEL_END, CSN1C_VAL1(104),        /* (ID:1355:183410:183616) Label=<ProtocolCfgs> Terminal=<0> */
	/* 000114 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(35),        /* (ID:1355:183410:183616) Loop back to 79 */
	/* 000116 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(74), /* (ID:1372:183622:184753) Infinite loop start, jump to 153 */
	/* 000120 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(128),      /* (ID:1372:183622:184753) Label=<ContainerCfgs> Terminal=<0> LabelId=13 */
	/* 000123 */ CSN1C_LABEL_A, CSN1C_VAL1(67), CSN1C_VAL1(16), /* (ID:1375:183639:184703) Label=<ContainerId> LabelId=14 */
	/* 000126 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(141),      /* (ID:1379:184703:184721) Label=<Length> Terminal=<1> LabelId=11 */
	/* 000129 */ CSN1C_BIT_A(8),                          /* (ID:1389:210565:210566) */
	/* 000130 */ CSN1C_LABEL_END_TAG, CSN1C_VAL2(141), CSN1C_VAL1(101), /* (ID:1379:184703:184721) Label=<Length> Tag=<101> Terminal=<1> */
	/* 000134 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(147),      /* (ID:1383:184721:184752) Label=<Contents> Terminal=<1> LabelId=12 */
	/* 000137 */ CSN1C_LOOP_BEGIN_VAR_ED1, CSN1C_VAL3(17), CSN1C_VAL1(0), /* (ID:1386:184732:184735) Custom expression based loop. If expr returns 0, jump to 145 OPT=<> REP=<-1> ?Repetitions=<-1> extReps=<1> */
	/* 000142 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000143 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:1386:184732:184735) Loop back to 142 */
	/* 000145 */ CSN1C_LABEL_END, CSN1C_VAL2(147),        /* (ID:1383:184721:184752) Label=<Contents> Terminal=<1> */
	/* 000148 */ CSN1C_LABEL_END, CSN1C_VAL2(128),        /* (ID:1372:183622:184753) Label=<ContainerCfgs> Terminal=<0> */
	/* 000151 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(31),        /* (ID:1372:183622:184753) Loop back to 120 */
	/* 000153 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'zero_padding'
		DEFINITION FIELD-ID: 31  COMPLEXITY: 9
		SOURCE: ./TS_24.008_Rel13.src, 5833
	-----------------------------------------------------------------*/
	/* 000154 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(1), /* (ID:1404:210635:210642) When decoding infinite loop; at the end jump to 169 */
	/* 000159 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1404:210635:210642) Send construction; if encoding, jump to 166 */
	/* 000163 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000164 */ CSN1C_GOTO(3),                           /* (ID:1404:210635:210642) skip the encode part and jump to 167 */
	/* 000166 */ CSN1C_BIT_0,                             /* (ID:1410:210641:210642) */
	/* 000167 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1404:210635:210642) Loop back to 159 */
	/* 000169 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_padding'
		DEFINITION FIELD-ID: 32  COMPLEXITY: 9
		SOURCE: ./TS_24.008_Rel13.src, 5834
	-----------------------------------------------------------------*/
	/* 000170 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(1), /* (ID:1413:210724:210731) When decoding infinite loop; at the end jump to 185 */
	/* 000175 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1413:210724:210731) Send construction; if encoding, jump to 182 */
	/* 000179 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000180 */ CSN1C_GOTO(3),                           /* (ID:1413:210724:210731) skip the encode part and jump to 183 */
	/* 000182 */ CSN1C_BIT_L,                             /* (ID:1419:210730:210731) */
	/* 000183 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1413:210724:210731) Loop back to 175 */
	/* 000185 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'Classmark3Value'
		DEFINITION FIELD-ID: 1  COMPLEXITY: 454
		SOURCE: ./TS_24.008_Rel13.src, 2824
	-----------------------------------------------------------------*/
	/* 000186 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 186, node 1, jump to 191 */
	/* 000188 */ CSN1C_BIT_L,                             /* (ID:1399:210610:210611) */
	/* 000189 */ CSN1C_GOTO(8),                           /* (ID:1397:210610:210613) jump at 197 */
	/* 000191 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 186, node 2, jump to 196 */
	/* 000193 */ CSN1C_BIT_H,                             /* (ID:1401:210612:210613) */
	/* 000194 */ CSN1C_GOTO(3),                           /* (ID:1397:210610:210613) jump at 197 */
	/* 000196 */ CSN1C_BACKTRACK,                         /* (ID:1397:210610:210613) Failure of choice begun at 186 */
	/* 000197 */ CSN1C_CHOICE_END,                        /* (ID:1397:210610:210613) End of choice begun at 186 */
	/* 000198 */ CSN1C_CHOICE_NODE(0,32),                 /* (ID:0003:110948:111301) VBIT choice at 198, node 1, jump to 230 */
	/* 000200 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(153),      /* (ID:0015:111007:111052) Label=<Multiband_supported> Terminal=<1> LabelId=15 */
	/* 000203 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0018:111033:111043) FBIT choice at 203, node 1, jump to 209 */
	/* 000205 */ CSN1C_VALUE, CSN1C_VAL1(82),             /* (ID:0020:111033:111034..0022:111035:111037) Bit string '101' */
	/* 000207 */ CSN1C_GOTO(9),                           /* (ID:0018:111033:111043) jump at 216 */
	/* 000209 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0018:111033:111043) FBIT choice at 203, node 2, jump to 215 */
	/* 000211 */ CSN1C_VALUE, CSN1C_VAL1(98),             /* (ID:0024:111039:111040..0026:111041:111043) Bit string '110' */
	/* 000213 */ CSN1C_GOTO(3),                           /* (ID:0018:111033:111043) jump at 216 */
	/* 000215 */ CSN1C_BACKTRACK,                         /* (ID:0018:111033:111043) Failure of choice begun at 203 */
	/* 000216 */ CSN1C_CHOICE_END,                        /* (ID:0018:111033:111043) End of choice begun at 203 */
	/* 000217 */ CSN1C_LABEL_END, CSN1C_VAL2(153),        /* (ID:0015:111007:111052) Label=<Multiband_supported> Terminal=<1> */
	/* 000220 */ CSN1C_GOSUB, CSN1C_VAL1(17),             /* (ID:0027:111052:111072) Reference to 'A5_CM3_bits' */
	/* 000222 */ CSN1C_LABEL_A, CSN1C_VAL1(79), CSN1C_VAL1(4), /* (ID:0028:111072:111119) Label=<Associated_Radio_Capability_2> LabelId=16 */
	/* 000225 */ CSN1C_LABEL_A, CSN1C_VAL1(82), CSN1C_VAL1(4), /* (ID:0032:111119:111164) Label=<Associated_Radio_Capability_1> LabelId=17 */
	/* 000228 */ CSN1C_GOTO(64),                          /* (ID:0003:110948:111301) jump at 292 */
	/* 000230 */ CSN1C_CHOICE_NODE(0,54),                 /* (ID:0003:110948:111301) VBIT choice at 198, node 2, jump to 284 */
	/* 000232 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(171),      /* (ID:0037:111166:111217) Label=<Multiband_supported> Terminal=<1> LabelId=15 */
	/* 000235 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0040:111192:111208) FBIT choice at 235, node 1, jump to 241 */
	/* 000237 */ CSN1C_VALUE, CSN1C_VAL1(18),             /* (ID:0042:111192:111193..0044:111194:111196) Bit string '001' */
	/* 000239 */ CSN1C_GOTO(15),                          /* (ID:0040:111192:111208) jump at 254 */
	/* 000241 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0040:111192:111208) FBIT choice at 235, node 2, jump to 247 */
	/* 000243 */ CSN1C_VALUE, CSN1C_VAL1(34),             /* (ID:0046:111198:111199..0048:111200:111202) Bit string '010' */
	/* 000245 */ CSN1C_GOTO(9),                           /* (ID:0040:111192:111208) jump at 254 */
	/* 000247 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0040:111192:111208) FBIT choice at 235, node 3, jump to 253 */
	/* 000249 */ CSN1C_VALUE, CSN1C_VAL1(66),             /* (ID:0050:111204:111205..0052:111206:111208) Bit string '100' */
	/* 000251 */ CSN1C_GOTO(3),                           /* (ID:0040:111192:111208) jump at 254 */
	/* 000253 */ CSN1C_BACKTRACK,                         /* (ID:0040:111192:111208) Failure of choice begun at 235 */
	/* 000254 */ CSN1C_CHOICE_END,                        /* (ID:0040:111192:111208) End of choice begun at 235 */
	/* 000255 */ CSN1C_LABEL_END, CSN1C_VAL2(171),        /* (ID:0037:111166:111217) Label=<Multiband_supported> Terminal=<1> */
	/* 000258 */ CSN1C_GOSUB, CSN1C_VAL1(17),             /* (ID:0053:111217:111237) Reference to 'A5_CM3_bits' */
	/* 000260 */ CSN1C_LOOP_BEGIN_FIXED, CSN1C_VAL3(39), CSN1C_VAL1(4), /* (ID:1397:210610:210613) Loop start, exit to 279 */
	/* 000265 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 265, node 1, jump to 270 */
	/* 000267 */ CSN1C_BIT_L,                             /* (ID:1399:210610:210611) */
	/* 000268 */ CSN1C_GOTO(8),                           /* (ID:1397:210610:210613) jump at 276 */
	/* 000270 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1397:210610:210613) FBIT choice at 265, node 2, jump to 275 */
	/* 000272 */ CSN1C_BIT_H,                             /* (ID:1401:210612:210613) */
	/* 000273 */ CSN1C_GOTO(3),                           /* (ID:1397:210610:210613) jump at 276 */
	/* 000275 */ CSN1C_BACKTRACK,                         /* (ID:1397:210610:210613) Failure of choice begun at 265 */
	/* 000276 */ CSN1C_CHOICE_END,                        /* (ID:1397:210610:210613) End of choice begun at 265 */
	/* 000277 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(12),        /* (ID:1397:210610:210613) Loop back to 265 */
	/* 000279 */ CSN1C_LABEL_A, CSN1C_VAL1(88), CSN1C_VAL1(4), /* (ID:0055:111258:111301) Label=<Associated_Radio_Capability_1> LabelId=17 */
	/* 000282 */ CSN1C_GOTO(10),                          /* (ID:0003:110948:111301) jump at 292 */
	/* 000284 */ CSN1C_LABEL_VALUE, CSN1C_VAL1(91), CSN1C_VAL1(2), /* (ID:0005:110948:110986) Label=<Multiband_supported> LabelId=91 */
	/* 000287 */ CSN1C_GOSUB, CSN1C_VAL1(17),             /* (ID:0013:110986:111005) Reference to 'A5_CM3_bits' */
	/* 000289 */ CSN1C_GOTO(4),                           /* (ID:0003:110948:111301) jump at 294 */
	/* 000291 */ CSN1C_BACKTRACK,                         /* (ID:0003:110948:111301) Failure of choice begun at 198 */
	/* 000292 */ CSN1C_CHOICE_END,                        /* (ID:0003:110948:111301) End of choice begun at 198 */
	/* 000293 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:0059:111307:111327) VBIT choice at 293, node 1, jump to 301 */
	/* 000295 */ CSN1C_BIT_1,                             /* (ID:0063:111311:111313) */
	/* 000296 */ CSN1C_LABEL_A, CSN1C_VAL1(94), CSN1C_VAL1(3), /* (ID:0474:115704:115756) Label=<R_GSM_band_Associated_Radio_Capability> LabelId=18 */
	/* 000299 */ CSN1C_GOTO(8),                           /* (ID:0059:111307:111327) jump at 307 */
	/* 000301 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0059:111307:111327) FBIT choice at 293, node 2, jump to 306 */
	/* 000303 */ CSN1C_BIT_0,                             /* (ID:0061:111307:111309) */
	/* 000304 */ CSN1C_GOTO(3),                           /* (ID:0059:111307:111327) jump at 307 */
	/* 000306 */ CSN1C_BACKTRACK,                         /* (ID:0059:111307:111327) Failure of choice begun at 293 */
	/* 000307 */ CSN1C_CHOICE_END,                        /* (ID:0059:111307:111327) End of choice begun at 293 */
	/* 000308 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:0065:111333:111371) VBIT choice at 308, node 1, jump to 316 */
	/* 000310 */ CSN1C_BIT_1,                             /* (ID:0069:111337:111339) */
	/* 000311 */ CSN1C_LABEL_A, CSN1C_VAL1(99), CSN1C_VAL1(5), /* (ID:0480:115805:115842) Label=<HSCSD_Multi_Slot_Class> LabelId=19 */
	/* 000314 */ CSN1C_GOTO(8),                           /* (ID:0065:111333:111371) jump at 322 */
	/* 000316 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0065:111333:111371) FBIT choice at 308, node 2, jump to 321 */
	/* 000318 */ CSN1C_BIT_0,                             /* (ID:0067:111333:111335) */
	/* 000319 */ CSN1C_GOTO(3),                           /* (ID:0065:111333:111371) jump at 322 */
	/* 000321 */ CSN1C_BACKTRACK,                         /* (ID:0065:111333:111371) Failure of choice begun at 308 */
	/* 000322 */ CSN1C_CHOICE_END,                        /* (ID:0065:111333:111371) End of choice begun at 308 */
	/* 000323 */ CSN1C_LABEL_A, CSN1C_VAL1(104), CSN1C_VAL1(1), /* (ID:0071:111375:111401) Label=<UCS2_treatment> LabelId=20 */
	/* 000326 */ CSN1C_LABEL_A, CSN1C_VAL1(107), CSN1C_VAL1(1), /* (ID:0075:111401:111445) Label=<Extended_Measurement_Capability> LabelId=21 */
	/* 000329 */ CSN1C_CHOICE_NODE(0,11),                 /* (ID:0079:111447:111483) VBIT choice at 329, node 1, jump to 340 */
	/* 000331 */ CSN1C_BIT_1,                             /* (ID:0083:111451:111453) */
	/* 000332 */ CSN1C_LABEL_A, CSN1C_VAL1(110), CSN1C_VAL1(4), /* (ID:0486:115889:115915) Label=<SMS_VALUE> LabelId=22 */
	/* 000335 */ CSN1C_LABEL_A, CSN1C_VAL1(115), CSN1C_VAL1(4), /* (ID:0490:115915:115938) Label=<SM_VALUE> LabelId=23 */
	/* 000338 */ CSN1C_GOTO(8),                           /* (ID:0079:111447:111483) jump at 346 */
	/* 000340 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0079:111447:111483) FBIT choice at 329, node 2, jump to 345 */
	/* 000342 */ CSN1C_BIT_0,                             /* (ID:0081:111447:111449) */
	/* 000343 */ CSN1C_GOTO(3),                           /* (ID:0079:111447:111483) jump at 346 */
	/* 000345 */ CSN1C_BACKTRACK,                         /* (ID:0079:111447:111483) Failure of choice begun at 329 */
	/* 000346 */ CSN1C_CHOICE_END,                        /* (ID:0079:111447:111483) End of choice begun at 329 */
	/* 000347 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:0085:111489:111532) VBIT choice at 347, node 1, jump to 355 */
	/* 000349 */ CSN1C_BIT_1,                             /* (ID:0089:111493:111495) */
	/* 000350 */ CSN1C_LABEL_A, CSN1C_VAL1(120), CSN1C_VAL1(5), /* (ID:0496:115992:116027) Label=<MS_Positioning_Method> LabelId=24 */
	/* 000353 */ CSN1C_GOTO(8),                           /* (ID:0085:111489:111532) jump at 361 */
	/* 000355 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0085:111489:111532) FBIT choice at 347, node 2, jump to 360 */
	/* 000357 */ CSN1C_BIT_0,                             /* (ID:0087:111489:111491) */
	/* 000358 */ CSN1C_GOTO(3),                           /* (ID:0085:111489:111532) jump at 361 */
	/* 000360 */ CSN1C_BACKTRACK,                         /* (ID:0085:111489:111532) Failure of choice begun at 347 */
	/* 000361 */ CSN1C_CHOICE_END,                        /* (ID:0085:111489:111532) End of choice begun at 347 */
	/* 000362 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:0091:111538:111575) VBIT choice at 362, node 1, jump to 370 */
	/* 000364 */ CSN1C_BIT_1,                             /* (ID:0095:111542:111544) */
	/* 000365 */ CSN1C_LABEL_A, CSN1C_VAL1(125), CSN1C_VAL1(5), /* (ID:0502:116075:116110) Label=<ECSD_Multi_Slot_Class> LabelId=25 */
	/* 000368 */ CSN1C_GOTO(8),                           /* (ID:0091:111538:111575) jump at 376 */
	/* 000370 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0091:111538:111575) FBIT choice at 362, node 2, jump to 375 */
	/* 000372 */ CSN1C_BIT_0,                             /* (ID:0093:111538:111540) */
	/* 000373 */ CSN1C_GOTO(3),                           /* (ID:0091:111538:111575) jump at 376 */
	/* 000375 */ CSN1C_BACKTRACK,                         /* (ID:0091:111538:111575) Failure of choice begun at 362 */
	/* 000376 */ CSN1C_CHOICE_END,                        /* (ID:0091:111538:111575) End of choice begun at 362 */
	/* 000377 */ CSN1C_CHOICE_NODE(0,41),                 /* (ID:0097:111581:111604) VBIT choice at 377, node 1, jump to 418 */
	/* 000379 */ CSN1C_BIT_1,                             /* (ID:0101:111585:111587) */
	/* 000380 */ CSN1C_LABEL_A, CSN1C_VAL2(130), CSN1C_VAL1(1), /* (ID:0508:116143:116177) Label=<Modulation_Capability> LabelId=26 */
	/* 000384 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0512:116179:116225) VBIT choice at 384, node 1, jump to 393 */
	/* 000386 */ CSN1C_BIT_1,                             /* (ID:0516:116183:116185) */
	/* 000387 */ CSN1C_LABEL_A, CSN1C_VAL2(135), CSN1C_VAL1(2), /* (ID:0517:116185:116225) Label=<_8_PSK_RF_Power_Capability_1> LabelId=27 */
	/* 000391 */ CSN1C_GOTO(8),                           /* (ID:0512:116179:116225) jump at 399 */
	/* 000393 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0512:116179:116225) FBIT choice at 384, node 2, jump to 398 */
	/* 000395 */ CSN1C_BIT_0,                             /* (ID:0514:116179:116181) */
	/* 000396 */ CSN1C_GOTO(3),                           /* (ID:0512:116179:116225) jump at 399 */
	/* 000398 */ CSN1C_BACKTRACK,                         /* (ID:0512:116179:116225) Failure of choice begun at 384 */
	/* 000399 */ CSN1C_CHOICE_END,                        /* (ID:0512:116179:116225) End of choice begun at 384 */
	/* 000400 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0521:116231:116277) VBIT choice at 400, node 1, jump to 409 */
	/* 000402 */ CSN1C_BIT_1,                             /* (ID:0525:116235:116237) */
	/* 000403 */ CSN1C_LABEL_A, CSN1C_VAL2(140), CSN1C_VAL1(2), /* (ID:0526:116237:116277) Label=<_8_PSK_RF_Power_Capability_2> LabelId=28 */
	/* 000407 */ CSN1C_GOTO(8),                           /* (ID:0521:116231:116277) jump at 415 */
	/* 000409 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0521:116231:116277) FBIT choice at 400, node 2, jump to 414 */
	/* 000411 */ CSN1C_BIT_0,                             /* (ID:0523:116231:116233) */
	/* 000412 */ CSN1C_GOTO(3),                           /* (ID:0521:116231:116277) jump at 415 */
	/* 000414 */ CSN1C_BACKTRACK,                         /* (ID:0521:116231:116277) Failure of choice begun at 400 */
	/* 000415 */ CSN1C_CHOICE_END,                        /* (ID:0521:116231:116277) End of choice begun at 400 */
	/* 000416 */ CSN1C_GOTO(8),                           /* (ID:0097:111581:111604) jump at 424 */
	/* 000418 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0097:111581:111604) FBIT choice at 377, node 2, jump to 423 */
	/* 000420 */ CSN1C_BIT_0,                             /* (ID:0099:111581:111583) */
	/* 000421 */ CSN1C_GOTO(3),                           /* (ID:0097:111581:111604) jump at 424 */
	/* 000423 */ CSN1C_BACKTRACK,                         /* (ID:0097:111581:111604) Failure of choice begun at 377 */
	/* 000424 */ CSN1C_CHOICE_END,                        /* (ID:0097:111581:111604) End of choice begun at 377 */
	/* 000425 */ CSN1C_CHOICE_NODE(0,35),                 /* (ID:0103:111610:111897) VBIT choice at 425, node 1, jump to 460 */
	/* 000427 */ CSN1C_BIT_1,                             /* (ID:0107:111614:111616) */
	/* 000428 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(291),      /* (ID:0108:111616:111849) Label=<GSM_400_Bands_Supported> Terminal=<1> LabelId=29 */
	/* 000431 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0111:111828:111841) FBIT choice at 431, node 1, jump to 437 */
	/* 000433 */ CSN1C_VALUE, CSN1C_VAL1(17),             /* (ID:0113:111828:111829..0114:111829:111831) Bit string '01' */
	/* 000435 */ CSN1C_GOTO(15),                          /* (ID:0111:111828:111841) jump at 450 */
	/* 000437 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0111:111828:111841) FBIT choice at 431, node 2, jump to 443 */
	/* 000439 */ CSN1C_VALUE, CSN1C_VAL1(33),             /* (ID:0116:111833:111834..0117:111834:111836) Bit string '10' */
	/* 000441 */ CSN1C_GOTO(9),                           /* (ID:0111:111828:111841) jump at 450 */
	/* 000443 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0111:111828:111841) FBIT choice at 431, node 3, jump to 449 */
	/* 000445 */ CSN1C_VALUE, CSN1C_VAL1(49),             /* (ID:0119:111838:111839..0120:111839:111841) Bit string '11' */
	/* 000447 */ CSN1C_GOTO(3),                           /* (ID:0111:111828:111841) jump at 450 */
	/* 000449 */ CSN1C_BACKTRACK,                         /* (ID:0111:111828:111841) Failure of choice begun at 431 */
	/* 000450 */ CSN1C_CHOICE_END,                        /* (ID:0111:111828:111841) End of choice begun at 431 */
	/* 000451 */ CSN1C_LABEL_END, CSN1C_VAL2(291),        /* (ID:0108:111616:111849) Label=<GSM_400_Bands_Supported> Terminal=<1> */
	/* 000454 */ CSN1C_LABEL_A, CSN1C_VAL2(148), CSN1C_VAL1(4), /* (ID:0121:111849:111897) Label=<GSM_400_Associated_Radio_Capability> LabelId=30 */
	/* 000458 */ CSN1C_GOTO(8),                           /* (ID:0103:111610:111897) jump at 466 */
	/* 000460 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0103:111610:111897) FBIT choice at 425, node 2, jump to 465 */
	/* 000462 */ CSN1C_BIT_0,                             /* (ID:0105:111610:111612) */
	/* 000463 */ CSN1C_GOTO(3),                           /* (ID:0103:111610:111897) jump at 466 */
	/* 000465 */ CSN1C_BACKTRACK,                         /* (ID:0103:111610:111897) Failure of choice begun at 425 */
	/* 000466 */ CSN1C_CHOICE_END,                        /* (ID:0103:111610:111897) End of choice begun at 425 */
	/* 000467 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0125:111905:111959) VBIT choice at 467, node 1, jump to 476 */
	/* 000469 */ CSN1C_BIT_1,                             /* (ID:0129:111909:111911) */
	/* 000470 */ CSN1C_LABEL_A, CSN1C_VAL2(151), CSN1C_VAL1(4), /* (ID:0130:111911:111959) Label=<GSM_850_Associated_Radio_Capability> LabelId=31 */
	/* 000474 */ CSN1C_GOTO(8),                           /* (ID:0125:111905:111959) jump at 482 */
	/* 000476 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0125:111905:111959) FBIT choice at 467, node 2, jump to 481 */
	/* 000478 */ CSN1C_BIT_0,                             /* (ID:0127:111905:111907) */
	/* 000479 */ CSN1C_GOTO(3),                           /* (ID:0125:111905:111959) jump at 482 */
	/* 000481 */ CSN1C_BACKTRACK,                         /* (ID:0125:111905:111959) Failure of choice begun at 467 */
	/* 000482 */ CSN1C_CHOICE_END,                        /* (ID:0125:111905:111959) End of choice begun at 467 */
	/* 000483 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0134:111965:112020) VBIT choice at 483, node 1, jump to 492 */
	/* 000485 */ CSN1C_BIT_1,                             /* (ID:0138:111969:111971) */
	/* 000486 */ CSN1C_LABEL_A, CSN1C_VAL2(154), CSN1C_VAL1(4), /* (ID:0139:111971:112020) Label=<GSM_1900_Associated_Radio_Capability> LabelId=32 */
	/* 000490 */ CSN1C_GOTO(8),                           /* (ID:0134:111965:112020) jump at 498 */
	/* 000492 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0134:111965:112020) FBIT choice at 483, node 2, jump to 497 */
	/* 000494 */ CSN1C_BIT_0,                             /* (ID:0136:111965:111967) */
	/* 000495 */ CSN1C_GOTO(3),                           /* (ID:0134:111965:112020) jump at 498 */
	/* 000497 */ CSN1C_BACKTRACK,                         /* (ID:0134:111965:112020) Failure of choice begun at 483 */
	/* 000498 */ CSN1C_CHOICE_END,                        /* (ID:0134:111965:112020) End of choice begun at 483 */
	/* 000499 */ CSN1C_LABEL_A, CSN1C_VAL2(157), CSN1C_VAL1(1), /* (ID:0143:112024:112080) Label=<UMTS_FDD_Radio_Access_Technology_Capability> LabelId=33 */
	/* 000503 */ CSN1C_LABEL_A, CSN1C_VAL2(160), CSN1C_VAL1(1), /* (ID:0147:112080:112146) Label=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=34 */
	/* 000507 */ CSN1C_LABEL_A, CSN1C_VAL2(163), CSN1C_VAL1(1), /* (ID:0151:112146:112205) Label=<CDMA_2000_Radio_Access_Technology_Capability> LabelId=35 */
	/* 000511 */ CSN1C_CHOICE_NODE(0,29),                 /* (ID:0155:112207:112334) VBIT choice at 511, node 1, jump to 540 */
	/* 000513 */ CSN1C_BIT_1,                             /* (ID:0159:112211:112213) */
	/* 000514 */ CSN1C_LABEL_A, CSN1C_VAL2(166), CSN1C_VAL1(2), /* (ID:0160:112213:112256) Label=<DTM_GPRS_Multi_Slot_Class> LabelId=36 */
	/* 000518 */ CSN1C_LABEL_A, CSN1C_VAL2(169), CSN1C_VAL1(1), /* (ID:0164:112256:112286) Label=<Single_Slot_DTM> LabelId=37 */
	/* 000522 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0168:112287:112332) VBIT choice at 522, node 1, jump to 531 */
	/* 000524 */ CSN1C_BIT_1,                             /* (ID:0172:112291:112292) */
	/* 000525 */ CSN1C_LABEL_A, CSN1C_VAL2(172), CSN1C_VAL1(2), /* (ID:0173:112292:112332) Label=<DTM_EGPRS_Multi_Slot_Class> LabelId=38 */
	/* 000529 */ CSN1C_GOTO(8),                           /* (ID:0168:112287:112332) jump at 537 */
	/* 000531 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0168:112287:112332) FBIT choice at 522, node 2, jump to 536 */
	/* 000533 */ CSN1C_BIT_0,                             /* (ID:0170:112287:112289) */
	/* 000534 */ CSN1C_GOTO(3),                           /* (ID:0168:112287:112332) jump at 537 */
	/* 000536 */ CSN1C_BACKTRACK,                         /* (ID:0168:112287:112332) Failure of choice begun at 522 */
	/* 000537 */ CSN1C_CHOICE_END,                        /* (ID:0168:112287:112332) End of choice begun at 522 */
	/* 000538 */ CSN1C_GOTO(8),                           /* (ID:0155:112207:112334) jump at 546 */
	/* 000540 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0155:112207:112334) FBIT choice at 511, node 2, jump to 545 */
	/* 000542 */ CSN1C_BIT_0,                             /* (ID:0157:112207:112209) */
	/* 000543 */ CSN1C_GOTO(3),                           /* (ID:0155:112207:112334) jump at 546 */
	/* 000545 */ CSN1C_BACKTRACK,                         /* (ID:0155:112207:112334) Failure of choice begun at 511 */
	/* 000546 */ CSN1C_CHOICE_END,                        /* (ID:0155:112207:112334) End of choice begun at 511 */
	/* 000547 */ CSN1C_CHOICE_NODE(0,384),                /* (ID:0177:112340:115544) VBIT choice at 547, node 1, jump to 931 */
	/* 000549 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0181:112356:112386) VBIT choice at 549, node 1, jump to 558 */
	/* 000551 */ CSN1C_BIT_1,                             /* (ID:0185:112360:112362) */
	/* 000552 */ CSN1C_LABEL_A, CSN1C_VAL2(175), CSN1C_VAL1(4), /* (ID:0532:116319:116700) Label=<GSM_Band> LabelId=39 */
	/* 000556 */ CSN1C_GOTO(8),                           /* (ID:0181:112356:112386) jump at 564 */
	/* 000558 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0181:112356:112386) FBIT choice at 549, node 2, jump to 563 */
	/* 000560 */ CSN1C_BIT_0,                             /* (ID:0183:112356:112358) */
	/* 000561 */ CSN1C_GOTO(3),                           /* (ID:0181:112356:112386) jump at 564 */
	/* 000563 */ CSN1C_BACKTRACK,                         /* (ID:0181:112356:112386) Failure of choice begun at 549 */
	/* 000564 */ CSN1C_CHOICE_END,                        /* (ID:0181:112356:112386) End of choice begun at 549 */
	/* 000565 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0187:112427:112479) VBIT choice at 565, node 1, jump to 574 */
	/* 000567 */ CSN1C_BIT_1,                             /* (ID:0191:112431:112433) */
	/* 000568 */ CSN1C_LABEL_A, CSN1C_VAL2(180), CSN1C_VAL1(4), /* (ID:0192:112433:112479) Label=<GSM_750_Associated_Radio_Capability> LabelId=40 */
	/* 000572 */ CSN1C_GOTO(8),                           /* (ID:0187:112427:112479) jump at 580 */
	/* 000574 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0187:112427:112479) FBIT choice at 565, node 2, jump to 579 */
	/* 000576 */ CSN1C_BIT_0,                             /* (ID:0189:112427:112429) */
	/* 000577 */ CSN1C_GOTO(3),                           /* (ID:0187:112427:112479) jump at 580 */
	/* 000579 */ CSN1C_BACKTRACK,                         /* (ID:0187:112427:112479) Failure of choice begun at 565 */
	/* 000580 */ CSN1C_CHOICE_END,                        /* (ID:0187:112427:112479) End of choice begun at 565 */
	/* 000581 */ CSN1C_LABEL_A, CSN1C_VAL2(183), CSN1C_VAL1(1), /* (ID:0196:112487:112554) Label=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=41 */
	/* 000585 */ CSN1C_LABEL_A, CSN1C_VAL2(186), CSN1C_VAL1(1), /* (ID:0200:112554:112594) Label=<GERAN_Feature_Package_1> LabelId=42 */
	/* 000589 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0204:112596:112918) VBIT choice at 589, node 1, jump to 602 */
	/* 000591 */ CSN1C_BIT_1,                             /* (ID:0208:112600:112602) */
	/* 000592 */ CSN1C_LABEL_A, CSN1C_VAL2(189), CSN1C_VAL1(2), /* (ID:0209:112602:112869) Label=<Extended_DTM_GPRS_Multi_Slot_Class> LabelId=43 */
	/* 000596 */ CSN1C_LABEL_A, CSN1C_VAL2(192), CSN1C_VAL1(2), /* (ID:0213:112869:112918) Label=<Extended_DTM_EGPRS_Multi_Slot_Class> LabelId=44 */
	/* 000600 */ CSN1C_GOTO(8),                           /* (ID:0204:112596:112918) jump at 608 */
	/* 000602 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0204:112596:112918) FBIT choice at 589, node 2, jump to 607 */
	/* 000604 */ CSN1C_BIT_0,                             /* (ID:0206:112596:112598) */
	/* 000605 */ CSN1C_GOTO(3),                           /* (ID:0204:112596:112918) jump at 608 */
	/* 000607 */ CSN1C_BACKTRACK,                         /* (ID:0204:112596:112918) Failure of choice begun at 589 */
	/* 000608 */ CSN1C_CHOICE_END,                        /* (ID:0204:112596:112918) End of choice begun at 589 */
	/* 000609 */ CSN1C_CHOICE_NODE(0,316),                /* (ID:0217:112927:115519) VBIT choice at 609, node 1, jump to 925 */
	/* 000611 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0221:112944:112989) VBIT choice at 611, node 1, jump to 620 */
	/* 000613 */ CSN1C_BIT_1,                             /* (ID:0225:112948:112950) */
	/* 000614 */ CSN1C_LABEL_A, CSN1C_VAL2(195), CSN1C_VAL1(2), /* (ID:0226:112950:112989) Label=<High_Multislot_Capability> LabelId=45 */
	/* 000618 */ CSN1C_GOTO(8),                           /* (ID:0221:112944:112989) jump at 626 */
	/* 000620 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0221:112944:112989) FBIT choice at 611, node 2, jump to 625 */
	/* 000622 */ CSN1C_BIT_0,                             /* (ID:0223:112944:112946) */
	/* 000623 */ CSN1C_GOTO(3),                           /* (ID:0221:112944:112989) jump at 626 */
	/* 000625 */ CSN1C_BACKTRACK,                         /* (ID:0221:112944:112989) Failure of choice begun at 611 */
	/* 000626 */ CSN1C_CHOICE_END,                        /* (ID:0221:112944:112989) End of choice begun at 611 */
	/* 000627 */ CSN1C_CHOICE_NODE(0,7),                  /* (ID:0230:113034:113071) VBIT choice at 627, node 1, jump to 634 */
	/* 000629 */ CSN1C_BIT_1,                             /* (ID:0234:113038:113040) */
	/* 000630 */ CSN1C_GOSUB, CSN1C_VAL1(30),             /* (ID:0235:113040:113071) Reference to 'GERAN_Iu_Mode_Capabilities' */
	/* 000632 */ CSN1C_GOTO(8),                           /* (ID:0230:113034:113071) jump at 640 */
	/* 000634 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0230:113034:113071) FBIT choice at 627, node 2, jump to 639 */
	/* 000636 */ CSN1C_BIT_0,                             /* (ID:0232:113034:113036) */
	/* 000637 */ CSN1C_GOTO(3),                           /* (ID:0230:113034:113071) jump at 640 */
	/* 000639 */ CSN1C_BACKTRACK,                         /* (ID:0230:113034:113071) Failure of choice begun at 627 */
	/* 000640 */ CSN1C_CHOICE_END,                        /* (ID:0230:113034:113071) End of choice begun at 627 */
	/* 000641 */ CSN1C_LABEL_A, CSN1C_VAL2(198), CSN1C_VAL1(1), /* (ID:0236:113120:113162) Label=<GERAN_Feature_Package_2> LabelId=46 */
	/* 000645 */ CSN1C_LABEL_A, CSN1C_VAL2(201), CSN1C_VAL1(2), /* (ID:0240:113162:113209) Label=<GMSK_Multislot_Power_Profile> LabelId=47 */
	/* 000649 */ CSN1C_LABEL_A, CSN1C_VAL2(204), CSN1C_VAL1(2), /* (ID:0244:113209:113261) Label=<_8_PSK_Multislot_Power_Profile> LabelId=48 */
	/* 000653 */ CSN1C_CHOICE_NODE(0,266),                /* (ID:0248:113262:115493) VBIT choice at 653, node 1, jump to 919 */
	/* 000655 */ CSN1C_CHOICE_NODE(0,35),                 /* (ID:0252:113280:113419) VBIT choice at 655, node 1, jump to 690 */
	/* 000657 */ CSN1C_BIT_1,                             /* (ID:0256:113284:113286) */
	/* 000658 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(415),      /* (ID:0257:113286:113369) Label=<T_GSM_400_Bands_Supported> Terminal=<1> LabelId=49 */
	/* 000661 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0260:113318:113331) FBIT choice at 661, node 1, jump to 667 */
	/* 000663 */ CSN1C_VALUE, CSN1C_VAL1(17),             /* (ID:0262:113318:113319..0263:113319:113321) Bit string '01' */
	/* 000665 */ CSN1C_GOTO(15),                          /* (ID:0260:113318:113331) jump at 680 */
	/* 000667 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0260:113318:113331) FBIT choice at 661, node 2, jump to 673 */
	/* 000669 */ CSN1C_VALUE, CSN1C_VAL1(33),             /* (ID:0265:113323:113324..0266:113324:113326) Bit string '10' */
	/* 000671 */ CSN1C_GOTO(9),                           /* (ID:0260:113318:113331) jump at 680 */
	/* 000673 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0260:113318:113331) FBIT choice at 661, node 3, jump to 679 */
	/* 000675 */ CSN1C_VALUE, CSN1C_VAL1(49),             /* (ID:0268:113328:113329..0269:113329:113331) Bit string '11' */
	/* 000677 */ CSN1C_GOTO(3),                           /* (ID:0260:113318:113331) jump at 680 */
	/* 000679 */ CSN1C_BACKTRACK,                         /* (ID:0260:113318:113331) Failure of choice begun at 661 */
	/* 000680 */ CSN1C_CHOICE_END,                        /* (ID:0260:113318:113331) End of choice begun at 661 */
	/* 000681 */ CSN1C_LABEL_END, CSN1C_VAL2(415),        /* (ID:0257:113286:113369) Label=<T_GSM_400_Bands_Supported> Terminal=<1> */
	/* 000684 */ CSN1C_LABEL_A, CSN1C_VAL2(210), CSN1C_VAL1(4), /* (ID:0270:113369:113419) Label=<T_GSM_400_Associated_Radio_Capability> LabelId=50 */
	/* 000688 */ CSN1C_GOTO(8),                           /* (ID:0252:113280:113419) jump at 696 */
	/* 000690 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0252:113280:113419) FBIT choice at 655, node 2, jump to 695 */
	/* 000692 */ CSN1C_BIT_0,                             /* (ID:0254:113280:113282) */
	/* 000693 */ CSN1C_GOTO(3),                           /* (ID:0252:113280:113419) jump at 696 */
	/* 000695 */ CSN1C_BACKTRACK,                         /* (ID:0252:113280:113419) Failure of choice begun at 655 */
	/* 000696 */ CSN1C_CHOICE_END,                        /* (ID:0252:113280:113419) End of choice begun at 655 */
	/* 000697 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0274:113433:113489) VBIT choice at 697, node 1, jump to 706 */
	/* 000699 */ CSN1C_BIT_1,                             /* (ID:0278:113437:113439) */
	/* 000700 */ CSN1C_LABEL_A, CSN1C_VAL2(213), CSN1C_VAL1(4), /* (ID:0279:113439:113489) Label=<T_GSM_900_Associated_Radio_Capability> LabelId=51 */
	/* 000704 */ CSN1C_GOTO(8),                           /* (ID:0274:113433:113489) jump at 712 */
	/* 000706 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0274:113433:113489) FBIT choice at 697, node 2, jump to 711 */
	/* 000708 */ CSN1C_BIT_0,                             /* (ID:0276:113433:113435) */
	/* 000709 */ CSN1C_GOTO(3),                           /* (ID:0274:113433:113489) jump at 712 */
	/* 000711 */ CSN1C_BACKTRACK,                         /* (ID:0274:113433:113489) Failure of choice begun at 697 */
	/* 000712 */ CSN1C_CHOICE_END,                        /* (ID:0274:113433:113489) End of choice begun at 697 */
	/* 000713 */ CSN1C_LABEL_A, CSN1C_VAL2(216), CSN1C_VAL1(2), /* (ID:0283:113496:113558) Label=<Downlink_Advanced_Receiver_Performance> LabelId=52 */
	/* 000717 */ CSN1C_LABEL_A, CSN1C_VAL2(219), CSN1C_VAL1(1), /* (ID:0287:113558:113606) Label=<DTM_Enhancements_Capability> LabelId=53 */
	/* 000721 */ CSN1C_CHOICE_NODE(0,29),                 /* (ID:0291:113608:113752) VBIT choice at 721, node 1, jump to 750 */
	/* 000723 */ CSN1C_BIT_1,                             /* (ID:0295:113612:113614) */
	/* 000724 */ CSN1C_LABEL_A, CSN1C_VAL2(222), CSN1C_VAL1(3), /* (ID:0296:113614:113665) Label=<DTM_GPRS_High_Multi_Slot_Class> LabelId=54 */
	/* 000728 */ CSN1C_LABEL_A, CSN1C_VAL2(225), CSN1C_VAL1(1), /* (ID:0300:113665:113697) Label=<Offset_required> LabelId=55 */
	/* 000732 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0304:113699:113750) VBIT choice at 732, node 1, jump to 741 */
	/* 000734 */ CSN1C_BIT_1,                             /* (ID:0308:113703:113705) */
	/* 000735 */ CSN1C_LABEL_A, CSN1C_VAL2(228), CSN1C_VAL1(3), /* (ID:0309:113705:113750) Label=<DTM_EGPRS_High_Multi_Slot_Class> LabelId=56 */
	/* 000739 */ CSN1C_GOTO(8),                           /* (ID:0304:113699:113750) jump at 747 */
	/* 000741 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0304:113699:113750) FBIT choice at 732, node 2, jump to 746 */
	/* 000743 */ CSN1C_BIT_0,                             /* (ID:0306:113699:113701) */
	/* 000744 */ CSN1C_GOTO(3),                           /* (ID:0304:113699:113750) jump at 747 */
	/* 000746 */ CSN1C_BACKTRACK,                         /* (ID:0304:113699:113750) Failure of choice begun at 732 */
	/* 000747 */ CSN1C_CHOICE_END,                        /* (ID:0304:113699:113750) End of choice begun at 732 */
	/* 000748 */ CSN1C_GOTO(8),                           /* (ID:0291:113608:113752) jump at 756 */
	/* 000750 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0291:113608:113752) FBIT choice at 721, node 2, jump to 755 */
	/* 000752 */ CSN1C_BIT_0,                             /* (ID:0293:113608:113610) */
	/* 000753 */ CSN1C_GOTO(3),                           /* (ID:0291:113608:113752) jump at 756 */
	/* 000755 */ CSN1C_BACKTRACK,                         /* (ID:0291:113608:113752) Failure of choice begun at 721 */
	/* 000756 */ CSN1C_CHOICE_END,                        /* (ID:0291:113608:113752) End of choice begun at 721 */
	/* 000757 */ CSN1C_LABEL_A, CSN1C_VAL2(231), CSN1C_VAL1(1), /* (ID:0313:113764:113809) Label=<Repeated_ACCH_Capability> LabelId=57 */
	/* 000761 */ CSN1C_CHOICE_NODE(0,152),                /* (ID:0317:113810:115466) VBIT choice at 761, node 1, jump to 913 */
	/* 000763 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0321:113829:113881) VBIT choice at 763, node 1, jump to 772 */
	/* 000765 */ CSN1C_BIT_1,                             /* (ID:0325:113833:113835) */
	/* 000766 */ CSN1C_LABEL_A, CSN1C_VAL2(234), CSN1C_VAL1(4), /* (ID:0326:113835:113881) Label=<GSM_710_Associated_Radio_Capability> LabelId=58 */
	/* 000770 */ CSN1C_GOTO(8),                           /* (ID:0321:113829:113881) jump at 778 */
	/* 000772 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0321:113829:113881) FBIT choice at 763, node 2, jump to 777 */
	/* 000774 */ CSN1C_BIT_0,                             /* (ID:0323:113829:113831) */
	/* 000775 */ CSN1C_GOTO(3),                           /* (ID:0321:113829:113881) jump at 778 */
	/* 000777 */ CSN1C_BACKTRACK,                         /* (ID:0321:113829:113881) Failure of choice begun at 763 */
	/* 000778 */ CSN1C_CHOICE_END,                        /* (ID:0321:113829:113881) End of choice begun at 763 */
	/* 000779 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0330:113919:113973) VBIT choice at 779, node 1, jump to 788 */
	/* 000781 */ CSN1C_BIT_1,                             /* (ID:0334:113923:113925) */
	/* 000782 */ CSN1C_LABEL_A, CSN1C_VAL2(237), CSN1C_VAL1(4), /* (ID:0335:113925:113973) Label=<T_GSM_810_Associated_Radio_Capability> LabelId=59 */
	/* 000786 */ CSN1C_GOTO(8),                           /* (ID:0330:113919:113973) jump at 794 */
	/* 000788 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0330:113919:113973) FBIT choice at 779, node 2, jump to 793 */
	/* 000790 */ CSN1C_BIT_0,                             /* (ID:0332:113919:113921) */
	/* 000791 */ CSN1C_GOTO(3),                           /* (ID:0330:113919:113973) jump at 794 */
	/* 000793 */ CSN1C_BACKTRACK,                         /* (ID:0330:113919:113973) Failure of choice begun at 779 */
	/* 000794 */ CSN1C_CHOICE_END,                        /* (ID:0330:113919:113973) End of choice begun at 779 */
	/* 000795 */ CSN1C_LABEL_A, CSN1C_VAL2(240), CSN1C_VAL1(1), /* (ID:0339:113981:114037) Label=<Ciphering_Mode_Setting_Capability> LabelId=60 */
	/* 000799 */ CSN1C_LABEL_A, CSN1C_VAL2(243), CSN1C_VAL1(1), /* (ID:0343:114037:114095) Label=<Additional_Positioning_Capabilities> LabelId=61 */
	/* 000803 */ CSN1C_CHOICE_NODE(0,104),                /* (ID:0347:114096:115438) VBIT choice at 803, node 1, jump to 907 */
	/* 000805 */ CSN1C_LABEL_A, CSN1C_VAL2(246), CSN1C_VAL1(1), /* (ID:0351:114114:114185) Label=<E_UTRA_FDD_support> LabelId=62 */
	/* 000809 */ CSN1C_LABEL_A, CSN1C_VAL2(249), CSN1C_VAL1(1), /* (ID:0355:114185:114221) Label=<E_UTRA_TDD_support> LabelId=63 */
	/* 000813 */ CSN1C_LABEL_A, CSN1C_VAL2(252), CSN1C_VAL1(1), /* (ID:0359:114221:114279) Label=<E_UTRA_Measurement_and_Reporting_support> LabelId=64 */
	/* 000817 */ CSN1C_LABEL_A, CSN1C_VAL2(255), CSN1C_VAL1(1), /* (ID:0363:114279:114338) Label=<Priority_based_reselection_support> LabelId=65 */
	/* 000821 */ CSN1C_CHOICE_NODE(0,80),                 /* (ID:0367:114339:115409) VBIT choice at 821, node 1, jump to 901 */
	/* 000823 */ CSN1C_LABEL_A, CSN1C_VAL2(258), CSN1C_VAL1(1), /* (ID:0371:114358:114432) Label=<UTRA_CSG_Cells_Reporting> LabelId=66 */
	/* 000827 */ CSN1C_LABEL_A, CSN1C_VAL2(261), CSN1C_VAL1(2), /* (ID:0375:114432:114465) Label=<VAMOS_Level> LabelId=67 */
	/* 000831 */ CSN1C_CHOICE_NODE(0,64),                 /* (ID:0379:114466:115378) VBIT choice at 831, node 1, jump to 895 */
	/* 000833 */ CSN1C_LABEL_A, CSN1C_VAL2(264), CSN1C_VAL1(2), /* (ID:0383:114487:114562) Label=<TIGHTER_Capability> LabelId=68 */
	/* 000837 */ CSN1C_LABEL_A, CSN1C_VAL2(267), CSN1C_VAL1(1), /* (ID:0387:114562:114620) Label=<Selective_Ciphering_of_Downlink_SACCH> LabelId=69 */
	/* 000841 */ CSN1C_CHOICE_NODE(0,48),                 /* (ID:0391:114621:115346) VBIT choice at 841, node 1, jump to 889 */
	/* 000843 */ CSN1C_LABEL_A, CSN1C_VAL2(270), CSN1C_VAL1(2), /* (ID:0395:114643:114729) Label=<CS_to_PS_SRVCC_from_GERAN_to_UTRA> LabelId=70 */
	/* 000847 */ CSN1C_LABEL_A, CSN1C_VAL2(273), CSN1C_VAL1(2), /* (ID:0399:114729:114797) Label=<CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> LabelId=71 */
	/* 000851 */ CSN1C_LABEL_A, CSN1C_VAL2(276), CSN1C_VAL1(1), /* (ID:0403:114797:114847) Label=<GERAN_Network_Sharing_support> LabelId=72 */
	/* 000855 */ CSN1C_LABEL_A, CSN1C_VAL2(279), CSN1C_VAL1(1), /* (ID:0407:114847:114919) Label=<E_UTRA_Wideband_RSRQ_measurements_support> LabelId=73 */
	/* 000859 */ CSN1C_CHOICE_NODE(0,24),                 /* (ID:0411:114920:115313) VBIT choice at 859, node 1, jump to 883 */
	/* 000861 */ CSN1C_LABEL_A, CSN1C_VAL2(282), CSN1C_VAL1(1), /* (ID:0415:114943:115016) Label=<ER_Band_Support> LabelId=74 */
	/* 000865 */ CSN1C_LABEL_A, CSN1C_VAL2(285), CSN1C_VAL1(1), /* (ID:0419:115016:115085) Label=<UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=75 */
	/* 000869 */ CSN1C_LABEL_A, CSN1C_VAL2(288), CSN1C_VAL1(1), /* (ID:0423:115085:115155) Label=<E_UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=76 */
	/* 000873 */ CSN1C_LABEL_A, CSN1C_VAL2(291), CSN1C_VAL1(1), /* (ID:0427:115155:115211) Label=<Extended_TSC_Set_Capability_support> LabelId=77 */
	/* 000877 */ CSN1C_LABEL_A, CSN1C_VAL2(294), CSN1C_VAL1(1), /* (ID:0431:115211:115305) Label=<Extended_EARFCN_value_range> LabelId=78 */
	/* 000881 */ CSN1C_GOTO(5),                           /* (ID:0411:114920:115313) jump at 886 */
	/* 000883 */ CSN1C_GOTO(4),                           /* (ID:0411:114920:115313) jump at 888 */
	/* 000885 */ CSN1C_BACKTRACK,                         /* (ID:0411:114920:115313) Failure of choice begun at 859 */
	/* 000886 */ CSN1C_CHOICE_END,                        /* (ID:0411:114920:115313) End of choice begun at 859 */
	/* 000887 */ CSN1C_GOTO(5),                           /* (ID:0391:114621:115346) jump at 892 */
	/* 000889 */ CSN1C_GOTO(4),                           /* (ID:0391:114621:115346) jump at 894 */
	/* 000891 */ CSN1C_BACKTRACK,                         /* (ID:0391:114621:115346) Failure of choice begun at 841 */
	/* 000892 */ CSN1C_CHOICE_END,                        /* (ID:0391:114621:115346) End of choice begun at 841 */
	/* 000893 */ CSN1C_GOTO(5),                           /* (ID:0379:114466:115378) jump at 898 */
	/* 000895 */ CSN1C_GOTO(4),                           /* (ID:0379:114466:115378) jump at 900 */
	/* 000897 */ CSN1C_BACKTRACK,                         /* (ID:0379:114466:115378) Failure of choice begun at 831 */
	/* 000898 */ CSN1C_CHOICE_END,                        /* (ID:0379:114466:115378) End of choice begun at 831 */
	/* 000899 */ CSN1C_GOTO(5),                           /* (ID:0367:114339:115409) jump at 904 */
	/* 000901 */ CSN1C_GOTO(4),                           /* (ID:0367:114339:115409) jump at 906 */
	/* 000903 */ CSN1C_BACKTRACK,                         /* (ID:0367:114339:115409) Failure of choice begun at 821 */
	/* 000904 */ CSN1C_CHOICE_END,                        /* (ID:0367:114339:115409) End of choice begun at 821 */
	/* 000905 */ CSN1C_GOTO(5),                           /* (ID:0347:114096:115438) jump at 910 */
	/* 000907 */ CSN1C_GOTO(4),                           /* (ID:0347:114096:115438) jump at 912 */
	/* 000909 */ CSN1C_BACKTRACK,                         /* (ID:0347:114096:115438) Failure of choice begun at 803 */
	/* 000910 */ CSN1C_CHOICE_END,                        /* (ID:0347:114096:115438) End of choice begun at 803 */
	/* 000911 */ CSN1C_GOTO(5),                           /* (ID:0317:113810:115466) jump at 916 */
	/* 000913 */ CSN1C_GOTO(4),                           /* (ID:0317:113810:115466) jump at 918 */
	/* 000915 */ CSN1C_BACKTRACK,                         /* (ID:0317:113810:115466) Failure of choice begun at 761 */
	/* 000916 */ CSN1C_CHOICE_END,                        /* (ID:0317:113810:115466) End of choice begun at 761 */
	/* 000917 */ CSN1C_GOTO(5),                           /* (ID:0248:113262:115493) jump at 922 */
	/* 000919 */ CSN1C_GOTO(4),                           /* (ID:0248:113262:115493) jump at 924 */
	/* 000921 */ CSN1C_BACKTRACK,                         /* (ID:0248:113262:115493) Failure of choice begun at 653 */
	/* 000922 */ CSN1C_CHOICE_END,                        /* (ID:0248:113262:115493) End of choice begun at 653 */
	/* 000923 */ CSN1C_GOTO(5),                           /* (ID:0217:112927:115519) jump at 928 */
	/* 000925 */ CSN1C_GOTO(4),                           /* (ID:0217:112927:115519) jump at 930 */
	/* 000927 */ CSN1C_BACKTRACK,                         /* (ID:0217:112927:115519) Failure of choice begun at 609 */
	/* 000928 */ CSN1C_CHOICE_END,                        /* (ID:0217:112927:115519) End of choice begun at 609 */
	/* 000929 */ CSN1C_GOTO(5),                           /* (ID:0177:112340:115544) jump at 934 */
	/* 000931 */ CSN1C_GOTO(4),                           /* (ID:0177:112340:115544) jump at 936 */
	/* 000933 */ CSN1C_BACKTRACK,                         /* (ID:0177:112340:115544) Failure of choice begun at 547 */
	/* 000934 */ CSN1C_CHOICE_END,                        /* (ID:0177:112340:115544) End of choice begun at 547 */
	/* 000935 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(1), /* (ID:1413:210724:210731) When decoding infinite loop; at the end jump to 950 */
	/* 000940 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1413:210724:210731) Send construction; if encoding, jump to 947 */
	/* 000944 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 000945 */ CSN1C_GOTO(3),                           /* (ID:1413:210724:210731) skip the encode part and jump to 948 */
	/* 000947 */ CSN1C_BIT_L,                             /* (ID:1419:210730:210731) */
	/* 000948 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1413:210724:210731) Loop back to 940 */
	/* 000950 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'ReceiveNPduNumbersList'
		DEFINITION FIELD-ID: 11  COMPLEXITY: 6
		SOURCE: ./TS_24.008_Rel13.src, 4549
	-----------------------------------------------------------------*/
	/* 000951 */ CSN1C_GOSUB, CSN1C_VAL1(52),             /* (ID:0553:167036:167074) Reference to 'Receive_N_Pdu_Numbers_List_val' */
	/* 000953 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0648:167567:167578) FBIT choice at 953, node 1, jump to 959 */
	/* 000955 */ CSN1C_VALUE, CSN1C_VAL1(3),              /* (ID:0652:167574:167575..0655:167577:167578) Bit string '0000' */
	/* 000957 */ CSN1C_GOTO(5),                           /* (ID:0648:167567:167578) jump at 962 */
	/* 000959 */ CSN1C_GOTO(4),                           /* (ID:0648:167567:167578) jump at 964 */
	/* 000961 */ CSN1C_BACKTRACK,                         /* (ID:0648:167567:167578) Failure of choice begun at 953 */
	/* 000962 */ CSN1C_CHOICE_END,                        /* (ID:0648:167567:167578) End of choice begun at 953 */
	/* 000963 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'MsNetwkCpblty'
		DEFINITION FIELD-ID: 15  COMPLEXITY: 93
		SOURCE: ./TS_24.008_Rel13.src, 4578
	-----------------------------------------------------------------*/
	/* 000964 */ CSN1C_LABEL_A, CSN1C_VAL2(297), CSN1C_VAL1(1), /* (ID:0751:168598:168611) Label=<GEA_1> LabelId=79 */
	/* 000968 */ CSN1C_LABEL_A, CSN1C_VAL2(302), CSN1C_VAL1(1), /* (ID:0659:167782:167832) Label=<SM_capabilities_via_dedicated_channels> LabelId=80 */
	/* 000972 */ CSN1C_LABEL_A, CSN1C_VAL2(305), CSN1C_VAL1(1), /* (ID:0663:167832:167877) Label=<SM_capabilities_via_GPRS_channels> LabelId=81 */
	/* 000976 */ CSN1C_LABEL_A, CSN1C_VAL2(308), CSN1C_VAL1(1), /* (ID:0667:167877:167901) Label=<UCS2_support> LabelId=82 */
	/* 000980 */ CSN1C_LABEL_A, CSN1C_VAL2(311), CSN1C_VAL1(2), /* (ID:0671:167901:167938) Label=<SS_Screening_Indicator> LabelId=83 */
	/* 000984 */ CSN1C_LABEL_A, CSN1C_VAL2(314), CSN1C_VAL1(1), /* (ID:0675:167938:167967) Label=<SoLSA_Capability> LabelId=84 */
	/* 000988 */ CSN1C_LABEL_A, CSN1C_VAL2(317), CSN1C_VAL1(1), /* (ID:0679:167967:168003) Label=<Revision_level_indicator> LabelId=85 */
	/* 000992 */ CSN1C_CHOICE_NODE(0,97),                 /* (ID:0684:168010:168551) Truncable concatenation, entry 0, jump to 1089 */
	/* 000994 */ CSN1C_LABEL_A, CSN1C_VAL2(320), CSN1C_VAL1(1), /* (ID:0685:168010:168039) Label=<PFC_feature_mode> LabelId=86 */
	/* 000998 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 1 */
	/* 000999 */ CSN1C_LABEL_A, CSN1C_VAL2(323), CSN1C_VAL1(1), /* (ID:0757:168645:168656) Label=<GEA_2> LabelId=87 */
	/* 001003 */ CSN1C_LABEL_A, CSN1C_VAL2(328), CSN1C_VAL1(1), /* (ID:0761:168656:168667) Label=<GEA_3> LabelId=88 */
	/* 001007 */ CSN1C_LABEL_A, CSN1C_VAL2(333), CSN1C_VAL1(1), /* (ID:0765:168667:168680) Label=<GEA_4> LabelId=89 */
	/* 001011 */ CSN1C_LABEL_A, CSN1C_VAL2(338), CSN1C_VAL1(1), /* (ID:0769:168680:168693) Label=<GEA_5> LabelId=90 */
	/* 001015 */ CSN1C_LABEL_A, CSN1C_VAL2(343), CSN1C_VAL1(1), /* (ID:0773:168693:168706) Label=<GEA_6> LabelId=91 */
	/* 001019 */ CSN1C_LABEL_A, CSN1C_VAL2(348), CSN1C_VAL1(1), /* (ID:0777:168706:168717) Label=<GEA_7> LabelId=92 */
	/* 001023 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 2 */
	/* 001024 */ CSN1C_LABEL_A, CSN1C_VAL2(353), CSN1C_VAL1(1), /* (ID:0690:168064:168091) Label=<LCS_VA_capability> LabelId=93 */
	/* 001028 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 3 */
	/* 001029 */ CSN1C_LABEL_A, CSN1C_VAL2(356), CSN1C_VAL1(1), /* (ID:0694:168091:168155) Label=<PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> LabelId=94 */
	/* 001033 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 4 */
	/* 001034 */ CSN1C_LABEL_A, CSN1C_VAL2(359), CSN1C_VAL1(1), /* (ID:0698:168155:168221) Label=<PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> LabelId=95 */
	/* 001038 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 5 */
	/* 001039 */ CSN1C_LABEL_A, CSN1C_VAL2(362), CSN1C_VAL1(1), /* (ID:0702:168221:168268) Label=<EMM_Combined_procedures_Capability> LabelId=96 */
	/* 001043 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 6 */
	/* 001044 */ CSN1C_LABEL_A, CSN1C_VAL2(365), CSN1C_VAL1(1), /* (ID:0706:168268:168289) Label=<ISR_support> LabelId=97 */
	/* 001048 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 7 */
	/* 001049 */ CSN1C_LABEL_A, CSN1C_VAL2(368), CSN1C_VAL1(1), /* (ID:0710:168289:168330) Label=<SRVCC_to_GERAN_UTRAN_capability> LabelId=98 */
	/* 001053 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 8 */
	/* 001054 */ CSN1C_LABEL_A, CSN1C_VAL2(371), CSN1C_VAL1(1), /* (ID:0714:168330:168354) Label=<EPC_capability> LabelId=99 */
	/* 001058 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 9 */
	/* 001059 */ CSN1C_LABEL_A, CSN1C_VAL2(374), CSN1C_VAL1(1), /* (ID:0718:168354:168377) Label=<NF_capability> LabelId=100 */
	/* 001063 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0684:168010:168551) Truncable concatenation, entry 10 */
	/* 001064 */ CSN1C_LABEL_A, CSN1C_VAL2(377), CSN1C_VAL1(1), /* (ID:0724:168392:168435) Label=<GERAN_network_sharing_capability> LabelId=101 */
	/* 001068 */ CSN1C_LABEL_A, CSN1C_VAL2(380), CSN1C_VAL1(1), /* (ID:0728:168435:168485) Label=<User_plane_integrity_protection_support> LabelId=102 */
	/* 001072 */ CSN1C_LABEL_A, CSN1C_VAL2(383), CSN1C_VAL1(1), /* (ID:0732:168485:168501) Label=<GIA_4> LabelId=103 */
	/* 001076 */ CSN1C_LABEL_A, CSN1C_VAL2(386), CSN1C_VAL1(1), /* (ID:0736:168501:168517) Label=<GIA_5> LabelId=104 */
	/* 001080 */ CSN1C_LABEL_A, CSN1C_VAL2(389), CSN1C_VAL1(1), /* (ID:0740:168517:168533) Label=<GIA_6> LabelId=105 */
	/* 001084 */ CSN1C_LABEL_A, CSN1C_VAL2(392), CSN1C_VAL1(1), /* (ID:0744:168533:168548) Label=<GIA_7> LabelId=106 */
	/* 001088 */ CSN1C_CHOICE_END,
	/* 001089 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(1), /* (ID:1404:210635:210642) When decoding infinite loop; at the end jump to 1104 */
	/* 001094 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:1404:210635:210642) Send construction; if encoding, jump to 1101 */
	/* 001098 */ CSN1C_BIT_A(1),                          /* (ID:1389:210565:210566) */
	/* 001099 */ CSN1C_GOTO(3),                           /* (ID:1404:210635:210642) skip the encode part and jump to 1102 */
	/* 001101 */ CSN1C_BIT_0,                             /* (ID:1410:210641:210642) */
	/* 001102 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:1404:210635:210642) Loop back to 1094 */
	/* 001104 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'MS_RA_capability_value_part_struct'
		DEFINITION FIELD-ID: 19  COMPLEXITY: 53
		SOURCE: ./TS_24.008_Rel13.src, 4625
	-----------------------------------------------------------------*/
	/* 001105 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(790),      /* (ID:0790:169161:170408) Label=<MS_RA_capability_value> Terminal=<0> LabelId=107 */
	/* 001108 */ CSN1C_CHOICE_NODE(0,648),                /* (ID:0793:169189:170401) VBIT choice at 1108, node 1, jump to 1756 */
	/* 001110 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(801),      /* (ID:0795:169189:169706) Label=<Access_Technology_Type> Terminal=<1> LabelId=108 */
	/* 001113 */ CSN1C_PUSH_CURROFS,                      /* (ID:0797:169687:169702) Start of string that can be excluded */
	/* 001114 */ CSN1C_BIT_A(4),                          /* (ID:1389:210565:210566) */
	/* 001115 */ CSN1C_EXCLUSION_BEGIN, CSN1C_VAL3(8),    /* (ID:0797:169687:169702) Start of the string that must not matched; if not matched, jump to 1123 */
	/* 001119 */ CSN1C_VALUE, CSN1C_VAL2(243),            /* (ID:0801:169697:169698..0804:169700:169702) Bit string '1111' */
	/* 001122 */ CSN1C_EXCLUSION_END,                     /* (ID:0797:169687:169702) End of the exclusion string */
	/* 001123 */ CSN1C_LABEL_END, CSN1C_VAL2(801),        /* (ID:0795:169189:169706) Label=<Access_Technology_Type> Terminal=<1> */
	/* 001126 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(806),      /* (ID:0805:169706:169763) Label=<Access_capabilities> Terminal=<0> LabelId=109 */
	/* 001129 */ CSN1C_LABEL_A, CSN1C_VAL2(406), CSN1C_VAL1(7), /* (ID:0857:170663:170730) Label=<Length> LabelId=110 */
	/* 001133 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001135 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(4),
	/* 001137 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(822),      /* (ID:0862:170882:170918) Label=<Access_capabilities> Terminal=<0> LabelId=111 */
	/* 001140 */ CSN1C_CHOICE_NODE(0,597),                /* (ID:0871:171113:174797) Truncable concatenation, entry 0, jump to 1737 */
	/* 001142 */ CSN1C_LABEL_A, CSN1C_VAL2(416), CSN1C_VAL1(3), /* (ID:0874:171118:171155) Label=<RF_Power_Capability> LabelId=112 */
	/* 001146 */ CSN1C_CHOICE_NODE(0,39),                 /* (ID:0878:171157:171191) VBIT choice at 1146, node 1, jump to 1185 */
	/* 001148 */ CSN1C_BIT_1,                             /* (ID:0882:171161:171163) */
	/* 001149 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(842),      /* (ID:0883:171163:171191) Label=<A5_bits> Terminal=<0> LabelId=113 */
	/* 001152 */ CSN1C_LABEL_A, CSN1C_VAL2(426), CSN1C_VAL1(1), /* (ID:1301:176055:176069) Label=<A5_1> LabelId=114 */
	/* 001156 */ CSN1C_LABEL_A, CSN1C_VAL2(431), CSN1C_VAL1(1), /* (ID:1305:176069:176082) Label=<A5_2> LabelId=115 */
	/* 001160 */ CSN1C_LABEL_A, CSN1C_VAL2(436), CSN1C_VAL1(1), /* (ID:1309:176082:176095) Label=<A5_3> LabelId=116 */
	/* 001164 */ CSN1C_LABEL_A, CSN1C_VAL2(441), CSN1C_VAL1(1), /* (ID:1313:176095:176108) Label=<A5_4> LabelId=117 */
	/* 001168 */ CSN1C_LABEL_A, CSN1C_VAL2(446), CSN1C_VAL1(1), /* (ID:1317:176108:176121) Label=<A5_5> LabelId=118 */
	/* 001172 */ CSN1C_LABEL_A, CSN1C_VAL2(451), CSN1C_VAL1(1), /* (ID:1321:176121:176134) Label=<A5_6> LabelId=119 */
	/* 001176 */ CSN1C_LABEL_A, CSN1C_VAL2(456), CSN1C_VAL1(1), /* (ID:1325:176134:176146) Label=<A5_7> LabelId=120 */
	/* 001180 */ CSN1C_LABEL_END, CSN1C_VAL2(842),        /* (ID:0883:171163:171191) Label=<A5_bits> Terminal=<0> */
	/* 001183 */ CSN1C_GOTO(8),                           /* (ID:0878:171157:171191) jump at 1191 */
	/* 001185 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0878:171157:171191) FBIT choice at 1146, node 2, jump to 1190 */
	/* 001187 */ CSN1C_BIT_0,                             /* (ID:0880:171157:171159) */
	/* 001188 */ CSN1C_GOTO(3),                           /* (ID:0878:171157:171191) jump at 1191 */
	/* 001190 */ CSN1C_BACKTRACK,                         /* (ID:0878:171157:171191) Failure of choice begun at 1146 */
	/* 001191 */ CSN1C_CHOICE_END,                        /* (ID:0878:171157:171191) End of choice begun at 1146 */
	/* 001192 */ CSN1C_LABEL_A, CSN1C_VAL2(461), CSN1C_VAL1(1), /* (ID:0887:171326:171346) Label=<ES_IND> LabelId=121 */
	/* 001196 */ CSN1C_LABEL_A, CSN1C_VAL2(466), CSN1C_VAL1(1), /* (ID:0891:171346:171362) Label=<PS> LabelId=122 */
	/* 001200 */ CSN1C_LABEL_A, CSN1C_VAL2(471), CSN1C_VAL1(1), /* (ID:0895:171362:171380) Label=<VGCS> LabelId=123 */
	/* 001204 */ CSN1C_LABEL_A, CSN1C_VAL2(476), CSN1C_VAL1(1), /* (ID:0899:171380:171397) Label=<VBS> LabelId=124 */
	/* 001208 */ CSN1C_CHOICE_NODE(0,144),                /* (ID:0903:171399:171460) VBIT choice at 1208, node 1, jump to 1352 */
	/* 001210 */ CSN1C_BIT_1,                             /* (ID:0907:171403:171405) */
	/* 001211 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(962),      /* (ID:0908:171405:171460) Label=<Multislot_capability> Terminal=<0> LabelId=125 */
	/* 001214 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1218:175314:175356) VBIT choice at 1214, node 1, jump to 1223 */
	/* 001216 */ CSN1C_BIT_1,                             /* (ID:1222:175318:175320) */
	/* 001217 */ CSN1C_LABEL_A, CSN1C_VAL2(486), CSN1C_VAL1(5), /* (ID:1223:175320:175356) Label=<HSCSD_multislot_class> LabelId=126 */
	/* 001221 */ CSN1C_GOTO(8),                           /* (ID:1218:175314:175356) jump at 1229 */
	/* 001223 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1218:175314:175356) FBIT choice at 1214, node 2, jump to 1228 */
	/* 001225 */ CSN1C_BIT_0,                             /* (ID:1220:175314:175316) */
	/* 001226 */ CSN1C_GOTO(3),                           /* (ID:1218:175314:175356) jump at 1229 */
	/* 001228 */ CSN1C_BACKTRACK,                         /* (ID:1218:175314:175356) Failure of choice begun at 1214 */
	/* 001229 */ CSN1C_CHOICE_END,                        /* (ID:1218:175314:175356) End of choice begun at 1214 */
	/* 001230 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1227:175364:175459) VBIT choice at 1230, node 1, jump to 1243 */
	/* 001232 */ CSN1C_BIT_1,                             /* (ID:1231:175368:175370) */
	/* 001233 */ CSN1C_LABEL_A, CSN1C_VAL2(491), CSN1C_VAL1(5), /* (ID:1232:175370:175405) Label=<GPRS_multislot_class> LabelId=127 */
	/* 001237 */ CSN1C_LABEL_A, CSN1C_VAL2(496), CSN1C_VAL1(1), /* (ID:1236:175405:175459) Label=<GPRS_Extended_Dynamic_Allocation_Capability> LabelId=128 */
	/* 001241 */ CSN1C_GOTO(8),                           /* (ID:1227:175364:175459) jump at 1249 */
	/* 001243 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1227:175364:175459) FBIT choice at 1230, node 2, jump to 1248 */
	/* 001245 */ CSN1C_BIT_0,                             /* (ID:1229:175364:175366) */
	/* 001246 */ CSN1C_GOTO(3),                           /* (ID:1227:175364:175459) jump at 1249 */
	/* 001248 */ CSN1C_BACKTRACK,                         /* (ID:1227:175364:175459) Failure of choice begun at 1230 */
	/* 001249 */ CSN1C_CHOICE_END,                        /* (ID:1227:175364:175459) End of choice begun at 1230 */
	/* 001250 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1240:175467:175522) VBIT choice at 1250, node 1, jump to 1263 */
	/* 001252 */ CSN1C_BIT_1,                             /* (ID:1244:175471:175473) */
	/* 001253 */ CSN1C_LABEL_A, CSN1C_VAL2(501), CSN1C_VAL1(4), /* (ID:1245:175473:175498) Label=<SMS_VALUE> LabelId=129 */
	/* 001257 */ CSN1C_LABEL_A, CSN1C_VAL2(506), CSN1C_VAL1(4), /* (ID:1249:175498:175522) Label=<SM_VALUE> LabelId=130 */
	/* 001261 */ CSN1C_GOTO(8),                           /* (ID:1240:175467:175522) jump at 1269 */
	/* 001263 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1240:175467:175522) FBIT choice at 1250, node 2, jump to 1268 */
	/* 001265 */ CSN1C_BIT_0,                             /* (ID:1242:175467:175469) */
	/* 001266 */ CSN1C_GOTO(3),                           /* (ID:1240:175467:175522) jump at 1269 */
	/* 001268 */ CSN1C_BACKTRACK,                         /* (ID:1240:175467:175522) Failure of choice begun at 1250 */
	/* 001269 */ CSN1C_CHOICE_END,                        /* (ID:1240:175467:175522) End of choice begun at 1250 */
	/* 001270 */ CSN1C_CHOICE_NODE(0,77),                 /* (ID:1254:175570:175959) Truncable concatenation, entry 0, jump to 1347 */
	/* 001272 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1255:175572:175613) VBIT choice at 1272, node 1, jump to 1281 */
	/* 001274 */ CSN1C_BIT_1,                             /* (ID:1259:175576:175578) */
	/* 001275 */ CSN1C_LABEL_A, CSN1C_VAL2(511), CSN1C_VAL1(5), /* (ID:1260:175578:175613) Label=<ECSD_multislot_class> LabelId=131 */
	/* 001279 */ CSN1C_GOTO(8),                           /* (ID:1255:175572:175613) jump at 1287 */
	/* 001281 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1255:175572:175613) FBIT choice at 1272, node 2, jump to 1286 */
	/* 001283 */ CSN1C_BIT_0,                             /* (ID:1257:175572:175574) */
	/* 001284 */ CSN1C_GOTO(3),                           /* (ID:1255:175572:175613) jump at 1287 */
	/* 001286 */ CSN1C_BACKTRACK,                         /* (ID:1255:175572:175613) Failure of choice begun at 1272 */
	/* 001287 */ CSN1C_CHOICE_END,                        /* (ID:1255:175572:175613) End of choice begun at 1272 */
	/* 001288 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1254:175570:175959) Truncable concatenation, entry 1 */
	/* 001289 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1264:175621:175718) VBIT choice at 1289, node 1, jump to 1302 */
	/* 001291 */ CSN1C_BIT_1,                             /* (ID:1268:175625:175627) */
	/* 001292 */ CSN1C_LABEL_A, CSN1C_VAL2(516), CSN1C_VAL1(5), /* (ID:1269:175627:175663) Label=<EGPRS_multislot_class> LabelId=132 */
	/* 001296 */ CSN1C_LABEL_A, CSN1C_VAL2(521), CSN1C_VAL1(1), /* (ID:1273:175663:175718) Label=<EGPRS_Extended_Dynamic_Allocation_Capability> LabelId=133 */
	/* 001300 */ CSN1C_GOTO(8),                           /* (ID:1264:175621:175718) jump at 1308 */
	/* 001302 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1264:175621:175718) FBIT choice at 1289, node 2, jump to 1307 */
	/* 001304 */ CSN1C_BIT_0,                             /* (ID:1266:175621:175623) */
	/* 001305 */ CSN1C_GOTO(3),                           /* (ID:1264:175621:175718) jump at 1308 */
	/* 001307 */ CSN1C_BACKTRACK,                         /* (ID:1264:175621:175718) Failure of choice begun at 1289 */
	/* 001308 */ CSN1C_CHOICE_END,                        /* (ID:1264:175621:175718) End of choice begun at 1289 */
	/* 001309 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:1254:175570:175959) Truncable concatenation, entry 2 */
	/* 001310 */ CSN1C_CHOICE_NODE(0,29),                 /* (ID:1277:175725:175951) VBIT choice at 1310, node 1, jump to 1339 */
	/* 001312 */ CSN1C_BIT_1,                             /* (ID:1281:175729:175731) */
	/* 001313 */ CSN1C_LABEL_A, CSN1C_VAL2(526), CSN1C_VAL1(2), /* (ID:1282:175731:175774) Label=<DTM_GPRS_Multi_Slot_Class> LabelId=134 */
	/* 001317 */ CSN1C_LABEL_A, CSN1C_VAL2(531), CSN1C_VAL1(1), /* (ID:1286:175774:175904) Label=<Single_Slot_DTM> LabelId=135 */
	/* 001321 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1290:175905:175949) VBIT choice at 1321, node 1, jump to 1330 */
	/* 001323 */ CSN1C_BIT_1,                             /* (ID:1294:175909:175911) */
	/* 001324 */ CSN1C_LABEL_A, CSN1C_VAL2(536), CSN1C_VAL1(2), /* (ID:1295:175911:175949) Label=<DTM_EGPRS_Multi_Slot_Class> LabelId=136 */
	/* 001328 */ CSN1C_GOTO(8),                           /* (ID:1290:175905:175949) jump at 1336 */
	/* 001330 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1290:175905:175949) FBIT choice at 1321, node 2, jump to 1335 */
	/* 001332 */ CSN1C_BIT_0,                             /* (ID:1292:175905:175907) */
	/* 001333 */ CSN1C_GOTO(3),                           /* (ID:1290:175905:175949) jump at 1336 */
	/* 001335 */ CSN1C_BACKTRACK,                         /* (ID:1290:175905:175949) Failure of choice begun at 1321 */
	/* 001336 */ CSN1C_CHOICE_END,                        /* (ID:1290:175905:175949) End of choice begun at 1321 */
	/* 001337 */ CSN1C_GOTO(8),                           /* (ID:1277:175725:175951) jump at 1345 */
	/* 001339 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1277:175725:175951) FBIT choice at 1310, node 2, jump to 1344 */
	/* 001341 */ CSN1C_BIT_0,                             /* (ID:1279:175725:175727) */
	/* 001342 */ CSN1C_GOTO(3),                           /* (ID:1277:175725:175951) jump at 1345 */
	/* 001344 */ CSN1C_BACKTRACK,                         /* (ID:1277:175725:175951) Failure of choice begun at 1310 */
	/* 001345 */ CSN1C_CHOICE_END,                        /* (ID:1277:175725:175951) End of choice begun at 1310 */
	/* 001346 */ CSN1C_CHOICE_END,
	/* 001347 */ CSN1C_LABEL_END, CSN1C_VAL2(962),        /* (ID:0908:171405:171460) Label=<Multislot_capability> Terminal=<0> */
	/* 001350 */ CSN1C_GOTO(8),                           /* (ID:0903:171399:171460) jump at 1358 */
	/* 001352 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0903:171399:171460) FBIT choice at 1208, node 2, jump to 1357 */
	/* 001354 */ CSN1C_BIT_0,                             /* (ID:0905:171399:171401) */
	/* 001355 */ CSN1C_GOTO(3),                           /* (ID:0903:171399:171460) jump at 1358 */
	/* 001357 */ CSN1C_BACKTRACK,                         /* (ID:0903:171399:171460) Failure of choice begun at 1208 */
	/* 001358 */ CSN1C_CHOICE_END,                        /* (ID:0903:171399:171460) End of choice begun at 1208 */
	/* 001359 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 1 */
	/* 001360 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0914:171643:171683) VBIT choice at 1360, node 1, jump to 1369 */
	/* 001362 */ CSN1C_BIT_1,                             /* (ID:0918:171647:171649) */
	/* 001363 */ CSN1C_LABEL_A, CSN1C_VAL2(541), CSN1C_VAL1(2), /* (ID:0919:171649:171683) Label=<_8PSK_Power_Capability> LabelId=137 */
	/* 001367 */ CSN1C_GOTO(8),                           /* (ID:0914:171643:171683) jump at 1375 */
	/* 001369 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0914:171643:171683) FBIT choice at 1360, node 2, jump to 1374 */
	/* 001371 */ CSN1C_BIT_0,                             /* (ID:0916:171643:171645) */
	/* 001372 */ CSN1C_GOTO(3),                           /* (ID:0914:171643:171683) jump at 1375 */
	/* 001374 */ CSN1C_BACKTRACK,                         /* (ID:0914:171643:171683) Failure of choice begun at 1360 */
	/* 001375 */ CSN1C_CHOICE_END,                        /* (ID:0914:171643:171683) End of choice begun at 1360 */
	/* 001376 */ CSN1C_LABEL_A, CSN1C_VAL2(546), CSN1C_VAL1(1), /* (ID:0923:171744:171801) Label=<COMPACT_Interference_Measurement_Capability> LabelId=138 */
	/* 001380 */ CSN1C_LABEL_A, CSN1C_VAL2(551), CSN1C_VAL1(1), /* (ID:0927:171801:171839) Label=<Revision_Level_Indicator> LabelId=139 */
	/* 001384 */ CSN1C_LABEL_A, CSN1C_VAL2(556), CSN1C_VAL1(1), /* (ID:0931:171839:171910) Label=<UMTS_FDD_Radio_Access_Technology_Capability> LabelId=140 */
	/* 001388 */ CSN1C_LABEL_A, CSN1C_VAL2(561), CSN1C_VAL1(1), /* (ID:0935:171910:171988) Label=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=141 */
	/* 001392 */ CSN1C_LABEL_A, CSN1C_VAL2(566), CSN1C_VAL1(1), /* (ID:0939:171988:172059) Label=<CDMA_2000_Radio_Access_Technology_Capability> LabelId=142 */
	/* 001396 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 2 */
	/* 001397 */ CSN1C_LABEL_A, CSN1C_VAL2(571), CSN1C_VAL1(1), /* (ID:0945:172095:172171) Label=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> LabelId=143 */
	/* 001401 */ CSN1C_LABEL_A, CSN1C_VAL2(576), CSN1C_VAL1(1), /* (ID:0949:172171:172208) Label=<GERAN_Feature_Package_1> LabelId=144 */
	/* 001405 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0953:172210:172318) VBIT choice at 1405, node 1, jump to 1418 */
	/* 001407 */ CSN1C_BIT_1,                             /* (ID:0957:172214:172216) */
	/* 001408 */ CSN1C_LABEL_A, CSN1C_VAL2(581), CSN1C_VAL1(2), /* (ID:0958:172216:172269) Label=<Extended_DTM_GPRS_Multi_Slot_Class> LabelId=145 */
	/* 001412 */ CSN1C_LABEL_A, CSN1C_VAL2(586), CSN1C_VAL1(2), /* (ID:0962:172269:172318) Label=<Extended_DTM_EGPRS_Multi_Slot_Class> LabelId=146 */
	/* 001416 */ CSN1C_GOTO(8),                           /* (ID:0953:172210:172318) jump at 1424 */
	/* 001418 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0953:172210:172318) FBIT choice at 1405, node 2, jump to 1423 */
	/* 001420 */ CSN1C_BIT_0,                             /* (ID:0955:172210:172212) */
	/* 001421 */ CSN1C_GOTO(3),                           /* (ID:0953:172210:172318) jump at 1424 */
	/* 001423 */ CSN1C_BACKTRACK,                         /* (ID:0953:172210:172318) Failure of choice begun at 1405 */
	/* 001424 */ CSN1C_CHOICE_END,                        /* (ID:0953:172210:172318) End of choice begun at 1405 */
	/* 001425 */ CSN1C_LABEL_A, CSN1C_VAL2(591), CSN1C_VAL1(1), /* (ID:0966:172323:172376) Label=<Modulation_based_multislot_class_support> LabelId=147 */
	/* 001429 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 3 */
	/* 001430 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0972:172414:172459) VBIT choice at 1430, node 1, jump to 1439 */
	/* 001432 */ CSN1C_BIT_1,                             /* (ID:0976:172418:172420) */
	/* 001433 */ CSN1C_LABEL_A, CSN1C_VAL2(596), CSN1C_VAL1(2), /* (ID:0977:172420:172459) Label=<High_Multislot_Capability> LabelId=148 */
	/* 001437 */ CSN1C_GOTO(8),                           /* (ID:0972:172414:172459) jump at 1445 */
	/* 001439 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0972:172414:172459) FBIT choice at 1430, node 2, jump to 1444 */
	/* 001441 */ CSN1C_BIT_0,                             /* (ID:0974:172414:172416) */
	/* 001442 */ CSN1C_GOTO(3),                           /* (ID:0972:172414:172459) jump at 1445 */
	/* 001444 */ CSN1C_BACKTRACK,                         /* (ID:0972:172414:172459) Failure of choice begun at 1430 */
	/* 001445 */ CSN1C_CHOICE_END,                        /* (ID:0972:172414:172459) End of choice begun at 1430 */
	/* 001446 */ CSN1C_CHOICE_NODE(0,7),                  /* (ID:0981:172466:172503) VBIT choice at 1446, node 1, jump to 1453 */
	/* 001448 */ CSN1C_BIT_1,                             /* (ID:0985:172470:172472) */
	/* 001449 */ CSN1C_GOSUB, CSN1C_VAL1(30),             /* (ID:0986:172472:172503) Reference to 'GERAN_Iu_Mode_Capabilities' */
	/* 001451 */ CSN1C_GOTO(8),                           /* (ID:0981:172466:172503) jump at 1459 */
	/* 001453 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0981:172466:172503) FBIT choice at 1446, node 2, jump to 1458 */
	/* 001455 */ CSN1C_BIT_0,                             /* (ID:0983:172466:172468) */
	/* 001456 */ CSN1C_GOTO(3),                           /* (ID:0981:172466:172503) jump at 1459 */
	/* 001458 */ CSN1C_BACKTRACK,                         /* (ID:0981:172466:172503) Failure of choice begun at 1446 */
	/* 001459 */ CSN1C_CHOICE_END,                        /* (ID:0981:172466:172503) End of choice begun at 1446 */
	/* 001460 */ CSN1C_LABEL_A, CSN1C_VAL2(601), CSN1C_VAL1(2), /* (ID:0987:172552:172598) Label=<GMSK_Multislot_Power_Profile> LabelId=149 */
	/* 001464 */ CSN1C_LABEL_A, CSN1C_VAL2(606), CSN1C_VAL1(2), /* (ID:0991:172598:172645) Label=<_8_PSK_Multislot_Power_Profile> LabelId=150 */
	/* 001468 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 4 */
	/* 001469 */ CSN1C_LABEL_A, CSN1C_VAL2(611), CSN1C_VAL1(1), /* (ID:0997:172681:172718) Label=<Multiple_TBF_Capability> LabelId=151 */
	/* 001473 */ CSN1C_LABEL_A, CSN1C_VAL2(616), CSN1C_VAL1(2), /* (ID:1001:172718:172773) Label=<Downlink_Advanced_Receiver_Performance> LabelId=152 */
	/* 001477 */ CSN1C_LABEL_A, CSN1C_VAL2(621), CSN1C_VAL1(1), /* (ID:1005:172773:172843) Label=<Extended_RLC_MAC_Control_Message_Segmentation_Capability> LabelId=153 */
	/* 001481 */ CSN1C_LABEL_A, CSN1C_VAL2(626), CSN1C_VAL1(1), /* (ID:1009:172843:172884) Label=<DTM_Enhancements_Capability> LabelId=154 */
	/* 001485 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:1013:172886:172996) VBIT choice at 1485, node 1, jump to 1510 */
	/* 001487 */ CSN1C_BIT_1,                             /* (ID:1017:172890:172892) */
	/* 001488 */ CSN1C_LABEL_A, CSN1C_VAL2(631), CSN1C_VAL1(3), /* (ID:1018:172892:172941) Label=<DTM_GPRS_High_Multi_Slot_Class> LabelId=155 */
	/* 001492 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1022:172943:172994) VBIT choice at 1492, node 1, jump to 1501 */
	/* 001494 */ CSN1C_BIT_1,                             /* (ID:1026:172947:172949) */
	/* 001495 */ CSN1C_LABEL_A, CSN1C_VAL2(636), CSN1C_VAL1(3), /* (ID:1027:172949:172994) Label=<DTM_EGPRS_High_Multi_Slot_Class> LabelId=156 */
	/* 001499 */ CSN1C_GOTO(8),                           /* (ID:1022:172943:172994) jump at 1507 */
	/* 001501 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1022:172943:172994) FBIT choice at 1492, node 2, jump to 1506 */
	/* 001503 */ CSN1C_BIT_0,                             /* (ID:1024:172943:172945) */
	/* 001504 */ CSN1C_GOTO(3),                           /* (ID:1022:172943:172994) jump at 1507 */
	/* 001506 */ CSN1C_BACKTRACK,                         /* (ID:1022:172943:172994) Failure of choice begun at 1492 */
	/* 001507 */ CSN1C_CHOICE_END,                        /* (ID:1022:172943:172994) End of choice begun at 1492 */
	/* 001508 */ CSN1C_GOTO(8),                           /* (ID:1013:172886:172996) jump at 1516 */
	/* 001510 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1013:172886:172996) FBIT choice at 1485, node 2, jump to 1515 */
	/* 001512 */ CSN1C_BIT_0,                             /* (ID:1015:172886:172888) */
	/* 001513 */ CSN1C_GOTO(3),                           /* (ID:1013:172886:172996) jump at 1516 */
	/* 001515 */ CSN1C_BACKTRACK,                         /* (ID:1013:172886:172996) Failure of choice begun at 1485 */
	/* 001516 */ CSN1C_CHOICE_END,                        /* (ID:1013:172886:172996) End of choice begun at 1485 */
	/* 001517 */ CSN1C_LABEL_A, CSN1C_VAL2(641), CSN1C_VAL1(1), /* (ID:1031:173001:173036) Label=<PS_Handover_Capability> LabelId=157 */
	/* 001521 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 5 */
	/* 001522 */ CSN1C_LABEL_A, CSN1C_VAL2(646), CSN1C_VAL1(1), /* (ID:1037:173072:173109) Label=<DTM_Handover_Capability> LabelId=158 */
	/* 001526 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1041:173111:173242) VBIT choice at 1526, node 1, jump to 1539 */
	/* 001528 */ CSN1C_BIT_1,                             /* (ID:1045:173115:173117) */
	/* 001529 */ CSN1C_LABEL_A, CSN1C_VAL2(651), CSN1C_VAL1(3), /* (ID:1046:173117:173192) Label=<Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> LabelId=159 */
	/* 001533 */ CSN1C_LABEL_A, CSN1C_VAL2(656), CSN1C_VAL1(1), /* (ID:1050:173192:173242) Label=<Downlink_Dual_Carrier_for_DTM_Capability> LabelId=160 */
	/* 001537 */ CSN1C_GOTO(8),                           /* (ID:1041:173111:173242) jump at 1545 */
	/* 001539 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1041:173111:173242) FBIT choice at 1526, node 2, jump to 1544 */
	/* 001541 */ CSN1C_BIT_0,                             /* (ID:1043:173111:173113) */
	/* 001542 */ CSN1C_GOTO(3),                           /* (ID:1041:173111:173242) jump at 1545 */
	/* 001544 */ CSN1C_BACKTRACK,                         /* (ID:1041:173111:173242) Failure of choice begun at 1526 */
	/* 001545 */ CSN1C_CHOICE_END,                        /* (ID:1041:173111:173242) End of choice begun at 1526 */
	/* 001546 */ CSN1C_LABEL_A, CSN1C_VAL2(661), CSN1C_VAL1(1), /* (ID:1054:173247:173293) Label=<Flexible_Timeslot_Assignment> LabelId=161 */
	/* 001550 */ CSN1C_LABEL_A, CSN1C_VAL2(666), CSN1C_VAL1(1), /* (ID:1058:173293:173333) Label=<GAN_PS_Handover_Capability> LabelId=162 */
	/* 001554 */ CSN1C_LABEL_A, CSN1C_VAL2(671), CSN1C_VAL1(1), /* (ID:1062:173333:173370) Label=<RLC_Non_persistent_Mode> LabelId=163 */
	/* 001558 */ CSN1C_LABEL_A, CSN1C_VAL2(676), CSN1C_VAL1(1), /* (ID:1066:173370:173410) Label=<Reduced_Latency_Capability> LabelId=164 */
	/* 001562 */ CSN1C_LABEL_A, CSN1C_VAL2(681), CSN1C_VAL1(2), /* (ID:1070:173410:173441) Label=<Uplink_EGPRS2> LabelId=165 */
	/* 001566 */ CSN1C_LABEL_A, CSN1C_VAL2(686), CSN1C_VAL1(2), /* (ID:1074:173441:173472) Label=<Downlink_EGPRS2> LabelId=166 */
	/* 001570 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 6 */
	/* 001571 */ CSN1C_LABEL_A, CSN1C_VAL2(691), CSN1C_VAL1(1), /* (ID:1080:173508:173541) Label=<E_UTRA_FDD_support> LabelId=167 */
	/* 001575 */ CSN1C_LABEL_A, CSN1C_VAL2(696), CSN1C_VAL1(1), /* (ID:1084:173541:173573) Label=<E_UTRA_TDD_support> LabelId=168 */
	/* 001579 */ CSN1C_LABEL_A, CSN1C_VAL2(701), CSN1C_VAL1(2), /* (ID:1088:173573:173642) Label=<GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode> LabelId=169 */
	/* 001583 */ CSN1C_LABEL_A, CSN1C_VAL2(706), CSN1C_VAL1(1), /* (ID:1092:173642:173689) Label=<Priority_based_reselection_support> LabelId=170 */
	/* 001587 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 7 */
	/* 001588 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1422),     /* (ID:1098:173725:173816) Label=<Enhanced_Flexible_Timeslot_Assignment> Terminal=<0> LabelId=171 */
	/* 001591 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1331:176215:176346) VBIT choice at 1591, node 1, jump to 1604 */
	/* 001593 */ CSN1C_BIT_1,                             /* (ID:1335:176219:176222) */
	/* 001594 */ CSN1C_LABEL_A, CSN1C_VAL2(716), CSN1C_VAL1(4), /* (ID:1336:176222:176271) Label=<Alternative_EFTA_Multislot_Class> LabelId=172 */
	/* 001598 */ CSN1C_LABEL_A, CSN1C_VAL2(721), CSN1C_VAL1(3), /* (ID:1340:176271:176346) Label=<EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> LabelId=173 */
	/* 001602 */ CSN1C_GOTO(8),                           /* (ID:1331:176215:176346) jump at 1610 */
	/* 001604 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1331:176215:176346) FBIT choice at 1591, node 2, jump to 1609 */
	/* 001606 */ CSN1C_BIT_0,                             /* (ID:1333:176215:176217) */
	/* 001607 */ CSN1C_GOTO(3),                           /* (ID:1331:176215:176346) jump at 1610 */
	/* 001609 */ CSN1C_BACKTRACK,                         /* (ID:1331:176215:176346) Failure of choice begun at 1591 */
	/* 001610 */ CSN1C_CHOICE_END,                        /* (ID:1331:176215:176346) End of choice begun at 1591 */
	/* 001611 */ CSN1C_LABEL_END, CSN1C_VAL2(1422),       /* (ID:1098:173725:173816) Label=<Enhanced_Flexible_Timeslot_Assignment> Terminal=<0> */
	/* 001614 */ CSN1C_LABEL_A, CSN1C_VAL2(726), CSN1C_VAL1(1), /* (ID:1102:173816:173887) Label=<Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM> LabelId=174 */
	/* 001618 */ CSN1C_LABEL_A, CSN1C_VAL2(731), CSN1C_VAL1(1), /* (ID:1106:173887:173916) Label=<EMST_Capability> LabelId=175 */
	/* 001622 */ CSN1C_LABEL_A, CSN1C_VAL2(736), CSN1C_VAL1(1), /* (ID:1110:173916:173945) Label=<MTTI_Capability> LabelId=176 */
	/* 001626 */ CSN1C_LABEL_A, CSN1C_VAL2(741), CSN1C_VAL1(1), /* (ID:1114:173945:173983) Label=<UTRA_CSG_Cells_Reporting> LabelId=177 */
	/* 001630 */ CSN1C_LABEL_A, CSN1C_VAL2(746), CSN1C_VAL1(1), /* (ID:1118:173983:174022) Label=<E_UTRA_CSG_Cells_Reporting> LabelId=178 */
	/* 001634 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 8 */
	/* 001635 */ CSN1C_LABEL_A, CSN1C_VAL2(751), CSN1C_VAL1(1), /* (ID:1124:174059:174087) Label=<DTR_Capability> LabelId=179 */
	/* 001639 */ CSN1C_LABEL_A, CSN1C_VAL2(756), CSN1C_VAL1(1), /* (ID:1128:174087:174116) Label=<EMSR_Capability> LabelId=180 */
	/* 001643 */ CSN1C_LABEL_A, CSN1C_VAL2(761), CSN1C_VAL1(1), /* (ID:1132:174116:174174) Label=<Fast_Downlink_Frequency_Switching_Capability> LabelId=181 */
	/* 001647 */ CSN1C_LABEL_A, CSN1C_VAL2(766), CSN1C_VAL1(2), /* (ID:1136:174174:174208) Label=<TIGHTER_Capability> LabelId=182 */
	/* 001651 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 9 */
	/* 001652 */ CSN1C_LABEL_A, CSN1C_VAL2(771), CSN1C_VAL1(1), /* (ID:1142:174245:174274) Label=<FANR_Capability> LabelId=183 */
	/* 001656 */ CSN1C_LABEL_A, CSN1C_VAL2(776), CSN1C_VAL1(1), /* (ID:1146:174274:174301) Label=<IPA_Capability> LabelId=184 */
	/* 001660 */ CSN1C_LABEL_A, CSN1C_VAL2(781), CSN1C_VAL1(1), /* (ID:1150:174301:174343) Label=<GERAN_Network_Sharing_support> LabelId=185 */
	/* 001664 */ CSN1C_LABEL_A, CSN1C_VAL2(786), CSN1C_VAL1(1), /* (ID:1154:174343:174396) Label=<E_UTRA_Wideband_RSRQ_measurements_support> LabelId=186 */
	/* 001668 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 10 */
	/* 001669 */ CSN1C_LABEL_A, CSN1C_VAL2(791), CSN1C_VAL1(1), /* (ID:1160:174433:174494) Label=<UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=187 */
	/* 001673 */ CSN1C_LABEL_A, CSN1C_VAL2(796), CSN1C_VAL1(1), /* (ID:1164:174494:174557) Label=<E_UTRA_Multiple_Frequency_Band_Indicators_support> LabelId=188 */
	/* 001677 */ CSN1C_CHOICE_NODE(0,43),                 /* (ID:1168:174559:174638) VBIT choice at 1677, node 1, jump to 1720 */
	/* 001679 */ CSN1C_BIT_1,                             /* (ID:1172:174591:174593) */
	/* 001680 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1602),     /* (ID:1173:174593:174638) Label=<DLMC_Capability> Terminal=<0> LabelId=189 */
	/* 001683 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1189:174986:175093) VBIT choice at 1683, node 1, jump to 1696 */
	/* 001685 */ CSN1C_BIT_1,                             /* (ID:1193:174990:174992) */
	/* 001686 */ CSN1C_LABEL_A, CSN1C_VAL2(806), CSN1C_VAL1(2), /* (ID:1194:174992:175052) Label=<DLMC_Non_contiguous_intra_band_reception> LabelId=190 */
	/* 001690 */ CSN1C_LABEL_A, CSN1C_VAL2(811), CSN1C_VAL1(1), /* (ID:1198:175052:175093) Label=<DLMC_Inter_band_reception> LabelId=191 */
	/* 001694 */ CSN1C_GOTO(8),                           /* (ID:1189:174986:175093) jump at 1702 */
	/* 001696 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1189:174986:175093) FBIT choice at 1683, node 2, jump to 1701 */
	/* 001698 */ CSN1C_BIT_0,                             /* (ID:1191:174986:174988) */
	/* 001699 */ CSN1C_GOTO(3),                           /* (ID:1189:174986:175093) jump at 1702 */
	/* 001701 */ CSN1C_BACKTRACK,                         /* (ID:1189:174986:175093) Failure of choice begun at 1683 */
	/* 001702 */ CSN1C_CHOICE_END,                        /* (ID:1189:174986:175093) End of choice begun at 1683 */
	/* 001703 */ CSN1C_LABEL_A, CSN1C_VAL2(816), CSN1C_VAL1(2), /* (ID:1202:175097:175137) Label=<DLMC_Maximum_Bandwidth> LabelId=192 */
	/* 001707 */ CSN1C_LABEL_A, CSN1C_VAL2(821), CSN1C_VAL1(6), /* (ID:1206:175137:175196) Label=<DLMC_Maximum_Number_of_Downlink_Timeslots> LabelId=193 */
	/* 001711 */ CSN1C_LABEL_A, CSN1C_VAL2(826), CSN1C_VAL1(3), /* (ID:1210:175196:175252) Label=<DLMC_Maximum_Number_of_Downlink_Carriers> LabelId=194 */
	/* 001715 */ CSN1C_LABEL_END, CSN1C_VAL2(1602),       /* (ID:1173:174593:174638) Label=<DLMC_Capability> Terminal=<0> */
	/* 001718 */ CSN1C_GOTO(8),                           /* (ID:1168:174559:174638) jump at 1726 */
	/* 001720 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1168:174559:174638) FBIT choice at 1677, node 2, jump to 1725 */
	/* 001722 */ CSN1C_BIT_0,                             /* (ID:1170:174559:174589) */
	/* 001723 */ CSN1C_GOTO(3),                           /* (ID:1168:174559:174638) jump at 1726 */
	/* 001725 */ CSN1C_BACKTRACK,                         /* (ID:1168:174559:174638) Failure of choice begun at 1677 */
	/* 001726 */ CSN1C_CHOICE_END,                        /* (ID:1168:174559:174638) End of choice begun at 1677 */
	/* 001727 */ CSN1C_LABEL_A, CSN1C_VAL2(831), CSN1C_VAL1(1), /* (ID:1177:174643:174691) Label=<Extended_TSC_Set_Capability_support> LabelId=195 */
	/* 001731 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0871:171113:174797) Truncable concatenation, entry 11 */
	/* 001732 */ CSN1C_LABEL_A, CSN1C_VAL2(836), CSN1C_VAL1(1), /* (ID:1183:174742:174780) Label=<Extended_EARFCN_value_range> LabelId=196 */
	/* 001736 */ CSN1C_CHOICE_END,
	/* 001737 */ CSN1C_LABEL_END, CSN1C_VAL2(822),        /* (ID:0862:170882:170918) Label=<Access_capabilities> Terminal=<0> */
	/* 001740 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0866:170918:170930) Infinite loop start, jump to 1747 */
	/* 001744 */ CSN1C_BIT_A(1),                          /* (ID:1394:210588:210589) */
	/* 001745 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0866:170918:170930) Loop back to 1744 */
	/* 001747 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(5),
	/* 001749 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(3),
	/* 001751 */ CSN1C_LABEL_END, CSN1C_VAL2(806),        /* (ID:0805:169706:169763) Label=<Access_capabilities> Terminal=<0> */
	/* 001754 */ CSN1C_GOTO(59),                          /* (ID:0793:169189:170401) jump at 1813 */
	/* 001756 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1683),     /* (ID:0812:169777:169876) Label=<Access_Technology_Type> Terminal=<1> LabelId=108 */
	/* 001759 */ CSN1C_VALUE, CSN1C_VAL2(243),            /* (ID:0815:169803:169804..0818:169806:169808) Bit string '1111' */
	/* 001762 */ CSN1C_LABEL_END, CSN1C_VAL2(1683),       /* (ID:0812:169777:169876) Label=<Access_Technology_Type> Terminal=<1> */
	/* 001765 */ CSN1C_LABEL_A, CSN1C_VAL2(844), CSN1C_VAL1(7), /* (ID:0819:169876:169977) Label=<Length> LabelId=197 */
	/* 001769 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001771 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(4),
	/* 001773 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(50), /* (ID:0824:170138:170222) Infinite loop start, jump to 1798 */
	/* 001777 */ CSN1C_BIT_1,                             /* (ID:0827:170138:170140) */
	/* 001778 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1694),     /* (ID:0828:170140:170222) Label=<Additional_access_technologies> Terminal=<0> LabelId=198 */
	/* 001781 */ CSN1C_LABEL_A, CSN1C_VAL2(850), CSN1C_VAL1(4), /* (ID:0843:170513:170552) Label=<Access_Technology_Type> LabelId=199 */
	/* 001785 */ CSN1C_LABEL_A, CSN1C_VAL2(855), CSN1C_VAL1(3), /* (ID:0847:170552:170585) Label=<GMSK_Power_Class> LabelId=200 */
	/* 001789 */ CSN1C_LABEL_A, CSN1C_VAL2(860), CSN1C_VAL1(2), /* (ID:0851:170585:170616) Label=<_8PSK_Power_Class> LabelId=201 */
	/* 001793 */ CSN1C_LABEL_END, CSN1C_VAL2(1694),       /* (ID:0828:170140:170222) Label=<Additional_access_technologies> Terminal=<0> */
	/* 001796 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(19),        /* (ID:0824:170138:170222) Loop back to 1777 */
	/* 001798 */ CSN1C_BIT_0,                             /* (ID:0832:170230:170235) */
	/* 001799 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0833:170235:170247) Infinite loop start, jump to 1806 */
	/* 001803 */ CSN1C_BIT_A(1),                          /* (ID:1394:210588:210589) */
	/* 001804 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0833:170235:170247) Loop back to 1803 */
	/* 001806 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(5),
	/* 001808 */ CSN1C_EXECUTE_DEC, CSN1C_VAL1(3),
	/* 001810 */ CSN1C_GOTO(4),                           /* (ID:0793:169189:170401) jump at 1815 */
	/* 001812 */ CSN1C_BACKTRACK,                         /* (ID:0793:169189:170401) Failure of choice begun at 1108 */
	/* 001813 */ CSN1C_CHOICE_END,                        /* (ID:0793:169189:170401) End of choice begun at 1108 */
	/* 001814 */ CSN1C_LABEL_END, CSN1C_VAL2(790),        /* (ID:0790:169161:170408) Label=<MS_RA_capability_value> Terminal=<0> */
	/* 001817 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:0835:170410:170453) VBIT choice at 1817, node 1, jump to 1825 */
	/* 001819 */ CSN1C_BIT_1,                             /* (ID:0839:170414:170416) */
	/* 001820 */ CSN1C_GOSUB, CSN1C_VAL2(1105),           /* (ID:0840:170416:170453) Reference to 'MS_RA_capability_value_part_struct' */
	/* 001823 */ CSN1C_GOTO(8),                           /* (ID:0835:170410:170453) jump at 1831 */
	/* 001825 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0835:170410:170453) FBIT choice at 1817, node 2, jump to 1830 */
	/* 001827 */ CSN1C_BIT_0,                             /* (ID:0837:170410:170412) */
	/* 001828 */ CSN1C_GOTO(3),                           /* (ID:0835:170410:170453) jump at 1831 */
	/* 001830 */ CSN1C_BACKTRACK,                         /* (ID:0835:170410:170453) Failure of choice begun at 1817 */
	/* 001831 */ CSN1C_CHOICE_END,                        /* (ID:0835:170410:170453) End of choice begun at 1817 */
	/* 001832 */ CSN1C_RETURN_LOOPING,
	/*-----------------------------------------------------------------
		DEFINITION 'MsRadioAccessCpblty'
		DEFINITION FIELD-ID: 18  COMPLEXITY: 7
		SOURCE: ./TS_24.008_Rel13.src, 4620
	-----------------------------------------------------------------*/
	/* 001833 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1730),     /* (ID:0783:168914:168988) Label=<MS_RA_capability_value_part> Terminal=<0> LabelId=202 */
	/* 001836 */ CSN1C_GOSUB, CSN1C_VAL2(1105),           /* (ID:0786:168945:168983) Reference to 'MS_RA_capability_value_part_struct' */
	/* 001839 */ CSN1C_LABEL_END, CSN1C_VAL2(1730),       /* (ID:0783:168914:168988) Label=<MS_RA_capability_value_part> Terminal=<0> */
	/* 001842 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0787:168988:169000) Infinite loop start, jump to 1849 */
	/* 001846 */ CSN1C_BIT_A(1),                          /* (ID:1394:210588:210589) */
	/* 001847 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0787:168988:169000) Loop back to 1846 */
	/* 001849 */ CSN1C_RETURN,
	((unsigned char)0) /* END OF PROGRAM */
};

/* DEFINITION FOR PROGRAM 'Program_L3' */
TCSN1CProgram Program_L3_Program = {
	/* ProgramCode.......*/ Program_L3_ProgramCode,
	/* ProgramLength.....*/ 1850,
	/* FieldIdPairSet....*/ Program_L3_FieldIdPairSet,
#ifdef CSN1C_LABEL_NAMES
	/* LabelNames........*/ Program_L3_Labels,
#endif
	/* FunctionMap.......*/ (void (*const *) (void* ED_EXTRAPARAMS_DECL))Program_L3_FunctionMap,
	/* ExpressionMap.....*/ (unsigned ED_EXLONG (*const *) (void*))Program_L3_ExpressionMap,
#ifdef CSN1C_ENABLE_LABEL_SIZE
	/* LabelSizes........*/ Program_L3_LabelSize,
#endif
	/* FirstErrorLabelId.*/ 209
};

