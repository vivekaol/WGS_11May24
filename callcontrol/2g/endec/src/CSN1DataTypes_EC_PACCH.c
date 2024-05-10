/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "csn1clib.h"
#include "CSN1DataTypes_EC_PACCH.h"
#include "ed_c_known_ie_EC_PACCH.h"
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
int XENCODE_DATA_c_EC_Packet_Access_Reject_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Access_Reject_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Access_Reject_message_content* Source = (const c_EC_Packet_Access_Reject_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 42: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Reject' */
			case 43: {
				/* The field 'Reject' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Downlink_TFI' */
			case 46: {
				/* The field 'Downlink_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_Downlink_TFI (&((*(Source->Reject))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Reject->Downlink_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'WAIT_INDICATION' */
			case 47: {
				/* The field 'WAIT_INDICATION' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_WAIT_INDICATION (&((*(Source->Reject))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Reject->WAIT_INDICATION), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'WAIT__INDICATION_SIZE' */
			case 48: {
				/* The field 'WAIT__INDICATION_SIZE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_WAIT__INDICATION_SIZE (&((*(Source->Reject))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Reject->WAIT__INDICATION_SIZE != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Ignore' */
			case 49: {
				/* The field 'Ignore' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_Ignore (&((*(Source->Reject))))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Reject->Ignore)).value, 0, (*(Source->Reject->Ignore)).usedBits);
				FieldCallbackParam->Length = (*(Source->Reject->Ignore)).usedBits;
				break;
			}
			/* Field 'Additional_Reject' */
			case 44: {
				/* The field 'Additional_Reject' is optional. If missing, generate nothing. */
				if ((*Source).Additional_Reject.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Downlink_TFI' */
			case 50: {
				/* The field 'Downlink_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Downlink_TFI (&((*(Source->Additional_Reject.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Additional_Reject.data[(Field)->Parent->Index]->Downlink_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'WAIT_INDICATION' */
			case 51: {
				/* The field 'WAIT_INDICATION' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_WAIT_INDICATION (&((*(Source->Additional_Reject.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Additional_Reject.data[(Field)->Parent->Index]->WAIT_INDICATION), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'WAIT__INDICATION_SIZE' */
			case 52: {
				/* The field 'WAIT__INDICATION_SIZE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_WAIT__INDICATION_SIZE (&((*(Source->Additional_Reject.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Additional_Reject.data[(Field)->Parent->Index]->WAIT__INDICATION_SIZE != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Ignore' */
			case 53: {
				/* The field 'Ignore' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore (&((*(Source->Additional_Reject.data[Field->Parent->Index]))))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Additional_Reject.data[(Field)->Parent->Index]->Ignore)).value, 0, (*(Source->Additional_Reject.data[(Field)->Parent->Index]->Ignore)).usedBits);
				FieldCallbackParam->Length = (*(Source->Additional_Reject.data[(Field)->Parent->Index]->Ignore)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 45: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Access_Reject_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Control_Acknowledgement_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Control_Acknowledgement_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Control_Acknowledgement_message_content* Source = (const c_EC_Packet_Control_Acknowledgement_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'TLLI' */
			case 58: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TLLI), 32);
				FieldCallbackParam->Length = 32;
				break;
			}
			/* Field 'CTRL_ACK' */
			case 59: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CTRL_ACK), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'DL_CC_EST' */
			case 60: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_CC_EST), 4);
				FieldCallbackParam->Length = 4;
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
int XENCODE_DATA_c_EC_Packet_Control_Acknowledgement_11_bit_message (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Control_Acknowledgement_11_bit_message
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Control_Acknowledgement_11_bit_message* Source = (const c_EC_Packet_Control_Acknowledgement_11_bit_message*)(FieldCallbackParam->Context->Data);
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
			/* Field 'MESSAGE_TYPE' */
			case 61: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MESSAGE_TYPE), 7);
				FieldCallbackParam->Length = 7;
				break;
			}
			/* Field 'DL_CC_EST' */
			case 62: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_CC_EST), 4);
				FieldCallbackParam->Length = 4;
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
int XENCODE_DATA_c_EC_Packet_Downlink_Ack_Nack_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Ack_Nack_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Downlink_Ack_Nack_message_content* Source = (const c_EC_Packet_Downlink_Ack_Nack_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'DOWNLINK_TFI' */
			case 63: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'MS_OUT_OF_MEMORY' */
			case 64: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->MS_OUT_OF_MEMORY != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EC_Ack_Nack_Description' */
			case 65: {
				/* The field 'EC_Ack_Nack_Description' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'STARTING_SEQUENCE_NUMBER' */
			case 69: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'RECEIVED_BLOCK_BITMAP' */
			case 70: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP), 16);
				FieldCallbackParam->Length = 16;
				break;
			}
			/* Field 'EC_Channel_Quality_Report' */
			case 66: {
				/* The field 'EC_Channel_Quality_Report' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'GMSK_MEAN_BEP' */
			case 71: {
				/* The field 'GMSK_MEAN_BEP' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report_GMSK_MEAN_BEP (&((*(Source->EC_Channel_Quality_Report))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Quality_Report->GMSK_MEAN_BEP), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'GMSK_CV_BEP' */
			case 72: {
				/* The field 'GMSK_CV_BEP' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report_GMSK_CV_BEP (&((*(Source->EC_Channel_Quality_Report))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Quality_Report->GMSK_CV_BEP), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field '_8PSK_MEAN_BEP' */
			case 73: {
				/* The field '_8PSK_MEAN_BEP' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report__8PSK_MEAN_BEP (&((*(Source->EC_Channel_Quality_Report))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Quality_Report->_8PSK_MEAN_BEP), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field '_8PSK_CV_BEP' */
			case 74: {
				/* The field '_8PSK_CV_BEP' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report__8PSK_CV_BEP (&((*(Source->EC_Channel_Quality_Report))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Quality_Report->_8PSK_CV_BEP), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'C_VALUE' */
			case 75: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Quality_Report->C_VALUE), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'DL_CC_EST' */
			case 67: {
				/* The field 'DL_CC_EST' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_CC_EST), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'EC_Channel_Request_Description' */
			case 68: {
				/* The field 'EC_Channel_Request_Description' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'PRIORITY' */
			case 76: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Request_Description->PRIORITY != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'NUMBER_OF_UL_DATA_BLOCKS' */
			case 77: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS), 4);
				FieldCallbackParam->Length = 4;
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
int XENCODE_DATA_c_EC_Packet_Downlink_Assignment_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Assignment_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Downlink_Assignment_message_content* Source = (const c_EC_Packet_Downlink_Assignment_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 80: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Global_TFI' */
			case 81: {
				/* The field 'Global_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 99: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI_UPLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'DOWNLINK_TFI' */
			case 100: {
				/* The field 'DOWNLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI_DOWNLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'CONTROL_ACK' */
			case 82: {
				/* The field 'CONTROL_ACK' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CONTROL_ACK != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Frequency_Parameters' */
			case 83: {
				/* The field 'Frequency_Parameters' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'EC_MA_NUMBER' */
			case 101: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->EC_MA_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'TSC' */
			case 102: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->TSC), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Primary_TSC_Set' */
			case 103: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->Primary_TSC_Set != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DL_COVERAGE_CLASS' */
			case 84: {
				/* The field 'DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_DL_TIMESLOT' */
			case 85: {
				/* The field 'STARTING_DL_TIMESLOT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_DL_TIMESLOT), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'TIMESLOT_MULTIPLICATOR' */
			case 86: {
				/* The field 'TIMESLOT_MULTIPLICATOR' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TIMESLOT_MULTIPLICATOR), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'DOWNLINK_TFI_ASSIGNMENT' */
			case 87: {
				/* The field 'DOWNLINK_TFI_ASSIGNMENT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DOWNLINK_TFI_ASSIGNMENT), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'UL_COVERAGE_CLASS' */
			case 88: {
				/* The field 'UL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_UL_TIMESLOT_OFFSET' */
			case 89: {
				/* The field 'STARTING_UL_TIMESLOT_OFFSET' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_UL_TIMESLOT_OFFSET), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'EC_Packet_Timing_Advance' */
			case 90: {
				/* The field 'EC_Packet_Timing_Advance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'TIMING_ADVANCE_VALUE' */
			case 104: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'P0' */
			case 91: {
				/* The field 'P0' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_P0 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->P0), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'PR_MODE' */
			case 92: {
				/* The field 'PR_MODE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_PR_MODE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PR_MODE != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GAMMA' */
			case 93: {
				/* The field 'GAMMA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_GAMMA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GAMMA), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'ALPHA_Enable' */
			case 94: {
				/* The field 'ALPHA_Enable' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ALPHA_Enable != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 95: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 96: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Message_escape' */
			case 97: {
				/* The field 'Message_escape' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Message_escape (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Message_escape)).value, 0, (*(Source->Message_escape)).usedBits);
				FieldCallbackParam->Length = (*(Source->Message_escape)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 98: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Dummy_Control_Block_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Downlink_Dummy_Control_Block_message_content* Source = (const c_EC_Packet_Downlink_Dummy_Control_Block_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 108: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 109: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Polling_Request_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Polling_Request_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Polling_Request_message_content* Source = (const c_EC_Packet_Polling_Request_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 110: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Global_TFI' */
			case 111: {
				/* The field 'Global_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 117: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI_UPLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'DOWNLINK_TFI' */
			case 118: {
				/* The field 'DOWNLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI_DOWNLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'TYPE_OF_ACK' */
			case 112: {
				/* The field 'TYPE_OF_ACK' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TYPE_OF_ACK != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 113: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 114: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Message_escape' */
			case 115: {
				/* The field 'Message_escape' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Message_escape (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Message_escape)).value, 0, (*(Source->Message_escape)).usedBits);
				FieldCallbackParam->Length = (*(Source->Message_escape)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 116: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Polling_Request_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Power_Control_Timing_Advance_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Power_Control_Timing_Advance_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Power_Control_Timing_Advance_message_content* Source = (const c_EC_Packet_Power_Control_Timing_Advance_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 119: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Global_TFI' */
			case 120: {
				/* The field 'Global_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 127: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_UPLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'DOWNLINK_TFI' */
			case 128: {
				/* The field 'DOWNLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_DOWNLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'T_AVG_T' */
			case 121: {
				/* The field 'T_AVG_T' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T_AVG_T), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'EC_Packet_Timing_Advance' */
			case 122: {
				/* The field 'EC_Packet_Timing_Advance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'TIMING_ADVANCE_VALUE' */
			case 129: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'GAMMA' */
			case 123: {
				/* The field 'GAMMA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GAMMA), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 124: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 125: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 126: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_TBF_Release_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_TBF_Release_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_TBF_Release_message_content* Source = (const c_EC_Packet_TBF_Release_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 130: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'GLOBAL_TFI' */
			case 131: {
				/* The field 'GLOBAL_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 138: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI_UPLINK_TFI (&((*(Source->GLOBAL_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GLOBAL_TFI->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'DOWNLINK_TFI' */
			case 139: {
				/* The field 'DOWNLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI_DOWNLINK_TFI (&((*(Source->GLOBAL_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GLOBAL_TFI->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'TBF_RELEASE_CAUSE' */
			case 132: {
				/* The field 'TBF_RELEASE_CAUSE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TBF_RELEASE_CAUSE), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'WAIT_INDICATION' */
			case 133: {
				/* The field 'WAIT_INDICATION' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_WAIT_INDICATION (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->WAIT_INDICATION), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'WAIT__INDICATION_SIZE' */
			case 134: {
				/* The field 'WAIT__INDICATION_SIZE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->WAIT__INDICATION_SIZE != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 135: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 136: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 137: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_TBF_Release_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Uplink_Ack_Nack_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Ack_Nack_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Uplink_Ack_Nack_message_content* Source = (const c_EC_Packet_Uplink_Ack_Nack_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 140: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 141: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'EC_Ack_Nack_Description' */
			case 142: {
				/* The field 'EC_Ack_Nack_Description' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'STARTING_SEQUENCE_NUMBER' */
			case 163: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'RECEIVED_BLOCK_BITMAP' */
			case 164: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP), 16);
				FieldCallbackParam->Length = 16;
				break;
			}
			/* Field 'CONTENTION_RESOLUTION_TLLI' */
			case 143: {
				/* The field 'CONTENTION_RESOLUTION_TLLI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CONTENTION_RESOLUTION_TLLI), 32);
				FieldCallbackParam->Length = 32;
				break;
			}
			/* Field 'EC_Primary_Ack_Nack_Description' */
			case 144: {
				/* The field 'EC_Primary_Ack_Nack_Description' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'STARTING_SEQUENCE_NUMBER' */
			case 165: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'RECEIVED_BLOCK_BITMAP' */
			case 166: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'CONTENTION_RESOLUTION_rTLLI' */
			case 145: {
				/* The field 'CONTENTION_RESOLUTION_rTLLI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CONTENTION_RESOLUTION_rTLLI), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'PUAN_Fixed_Uplink_Allocation' */
			case 146: {
				/* The field 'PUAN_Fixed_Uplink_Allocation' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'BSN_OFFSET' */
			case 167: {
				/* The field 'BSN_OFFSET' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_BSN_OFFSET (&((*(Source->PUAN_Fixed_Uplink_Allocation))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'START_FIRST_UL_RLC_DATA_BLOCK' */
			case 168: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' */
			case 169: {
				/* The field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' is optional. If missing, generate nothing. */
				if ((*(Source->PUAN_Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(Field)->Index]), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'RESEGMENT' */
			case 147: {
				/* The field 'RESEGMENT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->RESEGMENT != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'EGPRS_Channel_Coding_Command' */
			case 148: {
				/* The field 'EGPRS_Channel_Coding_Command' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Scheme' */
			case 170: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EGPRS_Channel_Coding_Command->Scheme), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'UL_COVERAGE_CLASS' */
			case 149: {
				/* The field 'UL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_UL_TIMESLOT' */
			case 150: {
				/* The field 'STARTING_UL_TIMESLOT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_UL_TIMESLOT), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'DL_COVERAGE_CLASS' */
			case 151: {
				/* The field 'DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_DL_TIMESLOT_OFFSET' */
			case 152: {
				/* The field 'STARTING_DL_TIMESLOT_OFFSET' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_DL_TIMESLOT_OFFSET), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'TIMESLOT_MULTIPLICATOR' */
			case 153: {
				/* The field 'TIMESLOT_MULTIPLICATOR' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TIMESLOT_MULTIPLICATOR), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'T3238' */
			case 154: {
				/* The field 'T3238' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_T3238 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->T3238), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Initial_Waiting_Time' */
			case 155: {
				/* The field 'Initial_Waiting_Time' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Initial_Waiting_Time), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'EC_PACCH_Monitoring_Pattern' */
			case 156: {
				/* The field 'EC_PACCH_Monitoring_Pattern' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_PACCH_Monitoring_Pattern), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'EC_Packet_Timing_Advance' */
			case 157: {
				/* The field 'EC_Packet_Timing_Advance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'TIMING_ADVANCE_VALUE' */
			case 171: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'GAMMA' */
			case 158: {
				/* The field 'GAMMA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GAMMA), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'ALPHA_Enable' */
			case 159: {
				/* The field 'ALPHA_Enable' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ALPHA_Enable != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 160: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 161: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 162: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Uplink_Assignment_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Assignment_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Uplink_Assignment_message_content* Source = (const c_EC_Packet_Uplink_Assignment_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 175: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Global_TFI' */
			case 176: {
				/* The field 'Global_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 196: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI_UPLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'DOWNLINK_TFI' */
			case 197: {
				/* The field 'DOWNLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI_DOWNLINK_TFI (&((*(Source->Global_TFI))))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Global_TFI->DOWNLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'UPLINK_TFI_ASSIGNMENT' */
			case 177: {
				/* The field 'UPLINK_TFI_ASSIGNMENT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UPLINK_TFI_ASSIGNMENT), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'EGPRS_Channel_Coding_Command' */
			case 178: {
				/* The field 'EGPRS_Channel_Coding_Command' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'Scheme' */
			case 198: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EGPRS_Channel_Coding_Command->Scheme), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'OVERLAID_CDMA_CODE' */
			case 179: {
				/* The field 'OVERLAID_CDMA_CODE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->OVERLAID_CDMA_CODE), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'EC_Packet_Timing_Advance' */
			case 180: {
				/* The field 'EC_Packet_Timing_Advance' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'TIMING_ADVANCE_VALUE' */
			case 199: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE), 6);
				FieldCallbackParam->Length = 6;
				break;
			}
			/* Field 'Frequency_Parameters' */
			case 181: {
				/* The field 'Frequency_Parameters' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'EC_MA_NUMBER' */
			case 200: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->EC_MA_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'TSC' */
			case 201: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->TSC), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Primary_TSC_Set' */
			case 202: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Frequency_Parameters->Primary_TSC_Set != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'UL_COVERAGE_CLASS' */
			case 182: {
				/* The field 'UL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_UL_TIMESLOT' */
			case 183: {
				/* The field 'STARTING_UL_TIMESLOT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_UL_TIMESLOT), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'TIMESLOT_MULTIPLICATOR' */
			case 184: {
				/* The field 'TIMESLOT_MULTIPLICATOR' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->TIMESLOT_MULTIPLICATOR), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'Fixed_Uplink_Allocation' */
			case 185: {
				/* The field 'Fixed_Uplink_Allocation' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'START_FIRST_UL_RLC_DATA_BLOCK' */
			case 203: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' */
			case 204: {
				/* The field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' is optional. If missing, generate nothing. */
				if ((*(Source->Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(Field)->Index]), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'P0' */
			case 186: {
				/* The field 'P0' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_P0 (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->P0), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'PR_MODE' */
			case 187: {
				/* The field 'PR_MODE' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_PR_MODE (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PR_MODE != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'GAMMA' */
			case 188: {
				/* The field 'GAMMA' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_GAMMA (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->GAMMA), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'ALPHA_Enable' */
			case 189: {
				/* The field 'ALPHA_Enable' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->ALPHA_Enable != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'DL_COVERAGE_CLASS' */
			case 190: {
				/* The field 'DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'STARTING_DL_TIMESLOT_OFFSET' */
			case 191: {
				/* The field 'STARTING_DL_TIMESLOT_OFFSET' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->STARTING_DL_TIMESLOT_OFFSET), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 192: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 193: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Message_escape' */
			case 194: {
				/* The field 'Message_escape' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Message_escape (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Message_escape)).value, 0, (*(Source->Message_escape)).usedBits);
				FieldCallbackParam->Length = (*(Source->Message_escape)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 195: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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
int XENCODE_DATA_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (TCSN1CLabelCallback* FieldCallbackParam ED_EXTRAPARAMS_DECL)
{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	
	int Ret = CSN1C_CB_OK;
	
	const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* Source = (const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content*)(FieldCallbackParam->Context->Data);
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
			/* Field 'USED_DL_COVERAGE_CLASS' */
			case 207: {
				/* The field 'USED_DL_COVERAGE_CLASS' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->USED_DL_COVERAGE_CLASS), 2);
				FieldCallbackParam->Length = 2;
				break;
			}
			/* Field 'UPLINK_TFI' */
			case 208: {
				/* The field 'UPLINK_TFI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->UPLINK_TFI), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'CONTENTION_RESOLUTION_TLLI' */
			case 209: {
				/* The field 'CONTENTION_RESOLUTION_TLLI' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->CONTENTION_RESOLUTION_TLLI), 32);
				FieldCallbackParam->Length = 32;
				break;
			}
			/* Field 'EC_Primary_Ack_Nack_Description' */
			case 210: {
				/* The field 'EC_Primary_Ack_Nack_Description' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'STARTING_SEQUENCE_NUMBER' */
			case 216: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER), 5);
				FieldCallbackParam->Length = 5;
				break;
			}
			/* Field 'RECEIVED_BLOCK_BITMAP' */
			case 217: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP), 8);
				FieldCallbackParam->Length = 8;
				break;
			}
			/* Field 'PUANCR_Fixed_Uplink_Allocation' */
			case 211: {
				/* The field 'PUANCR_Fixed_Uplink_Allocation' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation (&((*Source)))) return CSN1C_CB_BACKTRACK;
				break;
			}
			/* Field 'START_FIRST_UL_RLC_DATA_BLOCK' */
			case 218: {
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK), 4);
				FieldCallbackParam->Length = 4;
				break;
			}
			/* Field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' */
			case 219: {
				/* The field 'DELAY_NEXT_UL_RLC_DATA_BLOCK' is optional. If missing, generate nothing. */
				if ((*(Source->PUANCR_Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK.items <= Field->Index) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(Field)->Index]), 3);
				FieldCallbackParam->Length = 3;
				break;
			}
			/* Field 'RESEGMENT' */
			case 212: {
				/* The field 'RESEGMENT' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDIntToBits (FieldCallbackParam->Context->Buffer, ((int)(FieldCallbackParam->Context->CurrOfs)), (int)(Source->RESEGMENT != 0 ? 1 : 0), 1);FieldCallbackParam->Length = 1;
				break;
			}
			/* Field 'Non_distribution_part_error' */
			case 213: {
				/* The field 'Non_distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Non_distribution_part_error)).value, 0, (*(Source->Non_distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Non_distribution_part_error)).usedBits;
				break;
			}
			/* Field 'Address_information_part_error' */
			case 214: {
				/* The field 'Address_information_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Address_information_part_error)).value, 0, (*(Source->Address_information_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Address_information_part_error)).usedBits;
				break;
			}
			/* Field 'Distribution_part_error' */
			case 215: {
				/* The field 'Distribution_part_error' is optional. If missing, generate nothing. */
				if (!GETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error (&((*Source)))) return CSN1C_CB_BACKTRACK;
				EDCopyBits (FieldCallbackParam->Context->Buffer, (int)(FieldCallbackParam->Context->CurrOfs), (*(Source->Distribution_part_error)).value, 0, (*(Source->Distribution_part_error)).usedBits);
				FieldCallbackParam->Length = (*(Source->Distribution_part_error)).usedBits;
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Access_Reject_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Access_Reject_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Access_Reject_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 155, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Access_Reject_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Access_Reject_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Access_Reject_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Access_Reject_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 155, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 42 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 43: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 46 /* Downlink_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_Downlink_TFI (&((*(Destin->Reject))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Reject->Downlink_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Reject->Downlink_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 47 /* WAIT_INDICATION */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_WAIT_INDICATION (&((*(Destin->Reject))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Reject->WAIT_INDICATION = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Reject->WAIT_INDICATION___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 48 /* WAIT__INDICATION_SIZE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_WAIT__INDICATION_SIZE (&((*(Destin->Reject))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Reject->WAIT__INDICATION_SIZE = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Reject->WAIT__INDICATION_SIZE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 49 /* Ignore */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_Ignore (&((*(Destin->Reject))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Reject->Ignore___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Access_Reject_message_content_Reject_Ignore (Destin->Reject->Ignore, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Reject->Ignore->value) {
							EDCopyBits (Destin->Reject->Ignore->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Reject->Ignore->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Reject->Ignore->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 44: {
				if (SETITEMS_c_EC_Packet_Access_Reject_message_content_Additional_Reject (&((*Destin).Additional_Reject), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
				break;
			}
			case 50 /* Downlink_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Downlink_TFI (&((*(Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Downlink_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Downlink_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 51 /* WAIT_INDICATION */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_WAIT_INDICATION (&((*(Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->WAIT_INDICATION = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->WAIT_INDICATION___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 52 /* WAIT__INDICATION_SIZE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_WAIT__INDICATION_SIZE (&((*(Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->WAIT__INDICATION_SIZE = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->WAIT__INDICATION_SIZE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 53 /* Ignore */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore (&((*(Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore (Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore->value) {
							EDCopyBits (Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Additional_Reject.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Parent->Index]->Ignore->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 45 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Access_Reject_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Access_Reject_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Control_Acknowledgement_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Control_Acknowledgement_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Control_Acknowledgement_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 224, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 13;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Control_Acknowledgement_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Control_Acknowledgement_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Control_Acknowledgement_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Control_Acknowledgement_message_content
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 224, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 13;
	
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
				case 58 /* TLLI */: {
					Destin->TLLI = (ED_LONG)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 32);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TLLI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 32);
					break;
				}
			case 59 /* CTRL_ACK */: {
					Destin->CTRL_ACK = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CTRL_ACK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 60 /* DL_CC_EST */: {
					Destin->DL_CC_EST = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_CC_EST___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}

				default:;
			}
		}
	}
	
	
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Control_Acknowledgement_11_bit_message (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Control_Acknowledgement_11_bit_message* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Control_Acknowledgement_11_bit_message
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 99, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 14;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Control_Acknowledgement_11_bit_message ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Control_Acknowledgement_11_bit_message (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Control_Acknowledgement_11_bit_message* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Control_Acknowledgement_11_bit_message
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 99, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 14;
	
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
				case 61 /* MESSAGE_TYPE */: {
					Destin->MESSAGE_TYPE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MESSAGE_TYPE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 7);
					break;
				}
			case 62 /* DL_CC_EST */: {
					Destin->DL_CC_EST = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_CC_EST___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}

				default:;
			}
		}
	}
	
	
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Ack_Nack_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Ack_Nack_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 242, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Downlink_Ack_Nack_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Downlink_Ack_Nack_message_content
	int Ret, i;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 242, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 63 /* DOWNLINK_TFI */: {
					Destin->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 64 /* MS_OUT_OF_MEMORY */: {
					Destin->MS_OUT_OF_MEMORY = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->MS_OUT_OF_MEMORY___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 65: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 69 /* STARTING_SEQUENCE_NUMBER */: {
					Destin->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 70 /* RECEIVED_BLOCK_BITMAP */: {
					Destin->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP = (ED_SHORT)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 16);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 16);
					break;
				}
			case 66: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 71 /* GMSK_MEAN_BEP */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report_GMSK_MEAN_BEP (&((*(Destin->EC_Channel_Quality_Report))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EC_Channel_Quality_Report->GMSK_MEAN_BEP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Quality_Report->GMSK_MEAN_BEP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 72 /* GMSK_CV_BEP */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report_GMSK_CV_BEP (&((*(Destin->EC_Channel_Quality_Report))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EC_Channel_Quality_Report->GMSK_CV_BEP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Quality_Report->GMSK_CV_BEP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 73 /* _8PSK_MEAN_BEP */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report__8PSK_MEAN_BEP (&((*(Destin->EC_Channel_Quality_Report))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EC_Channel_Quality_Report->_8PSK_MEAN_BEP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Quality_Report->_8PSK_MEAN_BEP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 74 /* _8PSK_CV_BEP */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report__8PSK_CV_BEP (&((*(Destin->EC_Channel_Quality_Report))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EC_Channel_Quality_Report->_8PSK_CV_BEP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Quality_Report->_8PSK_CV_BEP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 75 /* C_VALUE */: {
					Destin->EC_Channel_Quality_Report->C_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Quality_Report->C_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 67 /* DL_CC_EST */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DL_CC_EST = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_CC_EST___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 68: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 76 /* PRIORITY */: {
					Destin->EC_Channel_Request_Description->PRIORITY = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Request_Description->PRIORITY___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 77 /* NUMBER_OF_UL_DATA_BLOCKS */: {
					Destin->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
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

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Assignment_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Assignment_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 371, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 17;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Downlink_Assignment_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Downlink_Assignment_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 371, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 17;
	
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
				case 80 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 81: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 99 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI_UPLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 100 /* DOWNLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI_DOWNLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 82 /* CONTROL_ACK */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CONTROL_ACK = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CONTROL_ACK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 83: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 101 /* EC_MA_NUMBER */: {
					Destin->Frequency_Parameters->EC_MA_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->EC_MA_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 102 /* TSC */: {
					Destin->Frequency_Parameters->TSC = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->TSC___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 103 /* Primary_TSC_Set */: {
					Destin->Frequency_Parameters->Primary_TSC_Set = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->Primary_TSC_Set___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 84 /* DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 85 /* STARTING_DL_TIMESLOT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_DL_TIMESLOT = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_DL_TIMESLOT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 86 /* TIMESLOT_MULTIPLICATOR */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TIMESLOT_MULTIPLICATOR = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TIMESLOT_MULTIPLICATOR___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 87 /* DOWNLINK_TFI_ASSIGNMENT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DOWNLINK_TFI_ASSIGNMENT = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DOWNLINK_TFI_ASSIGNMENT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 88 /* UL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 89 /* STARTING_UL_TIMESLOT_OFFSET */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_UL_TIMESLOT_OFFSET = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_UL_TIMESLOT_OFFSET___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 90: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 104 /* TIMING_ADVANCE_VALUE */: {
					Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 91 /* P0 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_P0 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->P0 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->P0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 92 /* PR_MODE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_PR_MODE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PR_MODE = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PR_MODE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 93 /* GAMMA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_GAMMA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GAMMA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GAMMA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 94 /* ALPHA_Enable */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ALPHA_Enable = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ALPHA_Enable___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 95 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 96 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 97 /* Message_escape */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Message_escape (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Message_escape___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Downlink_Assignment_message_content_Message_escape (Destin->Message_escape, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Message_escape->value) {
							EDCopyBits (Destin->Message_escape->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Message_escape->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Message_escape->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 98 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Downlink_Dummy_Control_Block_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 629, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 19;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Downlink_Dummy_Control_Block_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Downlink_Dummy_Control_Block_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 629, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 19;
	
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
				case 108 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 109 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Polling_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Polling_Request_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Polling_Request_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 670, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 20;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Polling_Request_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Polling_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Polling_Request_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Polling_Request_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 670, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 20;
	
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
				case 110 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 111: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 117 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI_UPLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 118 /* DOWNLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI_DOWNLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 112 /* TYPE_OF_ACK */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TYPE_OF_ACK = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TYPE_OF_ACK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 113 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 114 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Polling_Request_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 115 /* Message_escape */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Message_escape (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Message_escape___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Polling_Request_message_content_Message_escape (Destin->Message_escape, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Message_escape->value) {
							EDCopyBits (Destin->Message_escape->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Message_escape->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Message_escape->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 116 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Polling_Request_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Polling_Request_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Power_Control_Timing_Advance_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Power_Control_Timing_Advance_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 808, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 21;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Power_Control_Timing_Advance_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Power_Control_Timing_Advance_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Power_Control_Timing_Advance_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 808, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 21;
	
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
				case 119 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 120: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 127 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_UPLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 128 /* DOWNLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_DOWNLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 121 /* T_AVG_T */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T_AVG_T = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T_AVG_T___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 122: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 129 /* TIMING_ADVANCE_VALUE */: {
					Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 123 /* GAMMA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GAMMA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GAMMA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 124 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 125 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 126 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_TBF_Release_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_TBF_Release_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_TBF_Release_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 969, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 22;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_TBF_Release_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_TBF_Release_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_TBF_Release_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_TBF_Release_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 969, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 22;
	
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
				case 130 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 131: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 138 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI_UPLINK_TFI (&((*(Destin->GLOBAL_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GLOBAL_TFI->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GLOBAL_TFI->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 139 /* DOWNLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI_DOWNLINK_TFI (&((*(Destin->GLOBAL_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GLOBAL_TFI->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GLOBAL_TFI->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 132 /* TBF_RELEASE_CAUSE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TBF_RELEASE_CAUSE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TBF_RELEASE_CAUSE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 133 /* WAIT_INDICATION */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_WAIT_INDICATION (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->WAIT_INDICATION = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->WAIT_INDICATION___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 134 /* WAIT__INDICATION_SIZE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->WAIT__INDICATION_SIZE = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->WAIT__INDICATION_SIZE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 135 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 136 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_TBF_Release_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 137 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_TBF_Release_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_TBF_Release_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Ack_Nack_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1278, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 23;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Uplink_Ack_Nack_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Uplink_Ack_Nack_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1278, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 23;
	
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
				case 140 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 141 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 142: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 163 /* STARTING_SEQUENCE_NUMBER */: {
					Destin->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 164 /* RECEIVED_BLOCK_BITMAP */: {
					Destin->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP = (ED_SHORT)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 16);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 16);
					break;
				}
			case 143 /* CONTENTION_RESOLUTION_TLLI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CONTENTION_RESOLUTION_TLLI = (ED_LONG)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 32);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CONTENTION_RESOLUTION_TLLI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 32);
					break;
				}
			case 144: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 165 /* STARTING_SEQUENCE_NUMBER */: {
					Destin->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 166 /* RECEIVED_BLOCK_BITMAP */: {
					Destin->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 145 /* CONTENTION_RESOLUTION_rTLLI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CONTENTION_RESOLUTION_rTLLI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CONTENTION_RESOLUTION_rTLLI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 146: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 167 /* BSN_OFFSET */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_BSN_OFFSET (&((*(Destin->PUAN_Fixed_Uplink_Allocation))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 168 /* START_FIRST_UL_RLC_DATA_BLOCK */: {
					Destin->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 169 /* DELAY_NEXT_UL_RLC_DATA_BLOCK */: {
					if (SETITEMS_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (&((*(Destin->PUAN_Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
					Destin->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index] = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index]), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 147 /* RESEGMENT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->RESEGMENT = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->RESEGMENT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 148: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 170 /* Scheme */: {
					Destin->EGPRS_Channel_Coding_Command->Scheme = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EGPRS_Channel_Coding_Command->Scheme___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 149 /* UL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 150 /* STARTING_UL_TIMESLOT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_UL_TIMESLOT = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_UL_TIMESLOT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 151 /* DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 152 /* STARTING_DL_TIMESLOT_OFFSET */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_DL_TIMESLOT_OFFSET = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_DL_TIMESLOT_OFFSET___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 153 /* TIMESLOT_MULTIPLICATOR */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TIMESLOT_MULTIPLICATOR = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TIMESLOT_MULTIPLICATOR___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 154 /* T3238 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_T3238 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->T3238 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->T3238___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 155 /* Initial_Waiting_Time */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Initial_Waiting_Time = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Initial_Waiting_Time___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 156 /* EC_PACCH_Monitoring_Pattern */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->EC_PACCH_Monitoring_Pattern = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_PACCH_Monitoring_Pattern___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 157: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 171 /* TIMING_ADVANCE_VALUE */: {
					Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 158 /* GAMMA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GAMMA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GAMMA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 159 /* ALPHA_Enable */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ALPHA_Enable = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ALPHA_Enable___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 160 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 161 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 162 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Assignment_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Assignment_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1634, Buffer, BitOffset, 0, 1);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 25;
	
	/* Set the data object */
	CSN1C_CONTEXT_PTR->Data = (void*)Source;

#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT
	CSN1C_USER_DEFINED_SETUP_CONTEXT
#endif
#ifdef CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
	CSN1C_USER_DEFINED_SETUP_CONTEXT_ENCODE
#endif

	/* Run the encoder */
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Uplink_Assignment_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Uplink_Assignment_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1634, (void*)Buffer, BitOffset, Length, 0);
	
	/* Prepare the stack host field id */
	CSN1C_CONTEXT_PTR->HostFieldId = 25;
	
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
				case 175 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 176: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 196 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI_UPLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 197 /* DOWNLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI_DOWNLINK_TFI (&((*(Destin->Global_TFI))), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->Global_TFI->DOWNLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Global_TFI->DOWNLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 177 /* UPLINK_TFI_ASSIGNMENT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UPLINK_TFI_ASSIGNMENT = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UPLINK_TFI_ASSIGNMENT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 178: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 198 /* Scheme */: {
					Destin->EGPRS_Channel_Coding_Command->Scheme = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EGPRS_Channel_Coding_Command->Scheme___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 179 /* OVERLAID_CDMA_CODE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->OVERLAID_CDMA_CODE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->OVERLAID_CDMA_CODE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 180: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 199 /* TIMING_ADVANCE_VALUE */: {
					Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 6);
					break;
				}
			case 181: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 200 /* EC_MA_NUMBER */: {
					Destin->Frequency_Parameters->EC_MA_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->EC_MA_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 201 /* TSC */: {
					Destin->Frequency_Parameters->TSC = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->TSC___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 202 /* Primary_TSC_Set */: {
					Destin->Frequency_Parameters->Primary_TSC_Set = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Frequency_Parameters->Primary_TSC_Set___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 182 /* UL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 183 /* STARTING_UL_TIMESLOT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_UL_TIMESLOT = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_UL_TIMESLOT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 184 /* TIMESLOT_MULTIPLICATOR */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->TIMESLOT_MULTIPLICATOR = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->TIMESLOT_MULTIPLICATOR___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 185: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 203 /* START_FIRST_UL_RLC_DATA_BLOCK */: {
					Destin->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 204 /* DELAY_NEXT_UL_RLC_DATA_BLOCK */: {
					if (SETITEMS_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (&((*(Destin->Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
					Destin->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index] = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index]), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 186 /* P0 */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_P0 (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->P0 = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->P0___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 187 /* PR_MODE */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_PR_MODE (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->PR_MODE = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PR_MODE___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 188 /* GAMMA */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_GAMMA (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->GAMMA = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->GAMMA___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 189 /* ALPHA_Enable */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->ALPHA_Enable = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->ALPHA_Enable___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 190 /* DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 191 /* STARTING_DL_TIMESLOT_OFFSET */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->STARTING_DL_TIMESLOT_OFFSET = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->STARTING_DL_TIMESLOT_OFFSET___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 192 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 193 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 194 /* Message_escape */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Message_escape (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Message_escape___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Assignment_message_content_Message_escape (Destin->Message_escape, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Message_escape->value) {
							EDCopyBits (Destin->Message_escape->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Message_escape->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Message_escape->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 195 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))

ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* ED_CONST Source))

{
#ifndef CSN1C_DISABLE_ENCODE_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content
	int Ret;

#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT

	/* Initialize the stack */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1124, Buffer, BitOffset, 0, 1);
	
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
	Ret = CSN1C_Process (CSN1C_CONTEXT_PTR, XENCODE_DATA_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content ED_EXTRAPARAMS_CALL);

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

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* ED_CONST Destin, ED_EXLONG Length))

{
#ifndef CSN1C_DISABLE_DECODE_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content
	int Ret, i, extTypeRet;
	
#ifdef CSN1C_DISABLE_ADT
#error "CSN.1 ADT DISABLED. ENCODE/DECODE FUNCTIONS MUST BE DISABLED WITH ED_CSN1_DISABLE_ADT TCL VARIABLE"
#endif
	CSN1C_DECLARE_CONTEXT
	
	/* Initialize the context */
	CSN1C_Init (CSN1C_CONTEXT_PTR, &Program_EC_PACCH_Program, 1124, (void*)Buffer, BitOffset, Length, 0);
	
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
				case 207 /* USED_DL_COVERAGE_CLASS */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->USED_DL_COVERAGE_CLASS = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->USED_DL_COVERAGE_CLASS___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 2);
					break;
				}
			case 208 /* UPLINK_TFI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->UPLINK_TFI = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->UPLINK_TFI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 209 /* CONTENTION_RESOLUTION_TLLI */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->CONTENTION_RESOLUTION_TLLI = (ED_LONG)EDBitsToInt (Buffer, (CSN1C_CONTEXT_PTR->Fields[i].Pos), 32);
					/* LOCATOR SETTINGS LOCINT */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->CONTENTION_RESOLUTION_TLLI___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 32);
					break;
				}
			case 210: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 216 /* STARTING_SEQUENCE_NUMBER */: {
					Destin->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 5);
					break;
				}
			case 217 /* RECEIVED_BLOCK_BITMAP */: {
					Destin->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 8);
					break;
				}
			case 211: {
				ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
				break;
			}
			case 218 /* START_FIRST_UL_RLC_DATA_BLOCK */: {
					Destin->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 4);
					break;
				}
			case 219 /* DELAY_NEXT_UL_RLC_DATA_BLOCK */: {
					if (SETITEMS_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (&((*(Destin->PUANCR_Fixed_Uplink_Allocation)).DELAY_NEXT_UL_RLC_DATA_BLOCK), CSN1C_CONTEXT_PTR->Fields[i].Index+1) != ED_NO_ERRORS) {Ret = ED_ARRAY_OVERFLOW; goto exitFunc;}
					Destin->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index] = (unsigned char)EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					/* LOCATOR SETTINGS LOCOCTET */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR[(&(CSN1C_CONTEXT_PTR->Fields[i]))->Index]), CSN1C_CONTEXT_PTR->Fields[i].Pos, 3);
					break;
				}
			case 212 /* RESEGMENT */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					Destin->RESEGMENT = (EDBitsToInt (Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, 1) != 0 ? ED_TRUE : ED_FALSE);
					/* LOCATOR SETTINGS LOCBOOL */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->RESEGMENT___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, 1);
					break;
				}
			case 213 /* Non_distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Non_distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error (Destin->Non_distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Non_distribution_part_error->value) {
							EDCopyBits (Destin->Non_distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Non_distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Non_distribution_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 214 /* Address_information_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Address_information_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error (Destin->Address_information_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Address_information_part_error->value) {
							EDCopyBits (Destin->Address_information_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Address_information_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Address_information_part_error->usedBits = 0;
							extTypeRet = ED_OUT_OF_MEMORY;
						}
					}
					else {
						extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
					}
					if (extTypeRet < 0) {Ret = extTypeRet; goto exitFunc;}
					break;
				}
			case 215 /* Distribution_part_error */: {
					ED_CHECK_OUT_OF_MEMORY_IF(/*SETP1*/SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error (&((*Destin)), ED_TRUE), != ED_NO_ERRORS, Ret = ED_OUT_OF_MEMORY; goto exitFunc;)
					/* LOCATOR SETTINGS LOCBIN2 */;
					ED_LOCATOR_SET (&(/*LOC60*/Destin->Distribution_part_error___LOCATOR), CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					if (CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos > 0) {
						/* BINDEC02 */
						ALLOC_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error (Destin->Distribution_part_error, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
					
						if (Destin->Distribution_part_error->value) {
							EDCopyBits (Destin->Distribution_part_error->value, 0, Buffer, CSN1C_CONTEXT_PTR->Fields[i].Pos, CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos);
							Destin->Distribution_part_error->usedBits = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
							extTypeRet = CSN1C_CONTEXT_PTR->Fields[i+1].Pos - CSN1C_CONTEXT_PTR->Fields[i].Pos;
					
						}
						else {
							Destin->Distribution_part_error->usedBits = 0;
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
const char* const Program_EC_PACCH_Labels [] = {

	/*     0 */ "CSN1_EC_Reject_struct_Downlink_TFI",
	/*     1 */ "CSN1_EC_Reject_struct_WAIT_INDICATION",
	/*     2 */ "CSN1_EC_Reject_struct_WAIT__INDICATION_SIZE",
	/*     3 */ "CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_MESSAGE_TYPE",
	/*     4 */ "CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_DL_CC_EST",
	/*     5 */ "CSN1_Frequency_Parameters_struct_EC_MA_NUMBER",
	/*     6 */ "CSN1_Frequency_Parameters_struct_TSC",
	/*     7 */ "CSN1_Frequency_Parameters_struct_Primary_TSC_Set",
	/*     8 */ "CSN1_Global_TFI_IE_UPLINK_TFI",
	/*     9 */ "CSN1_Global_TFI_IE_DOWNLINK_TFI",
	/*    10 */ "CSN1_EC_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER",
	/*    11 */ "CSN1_EC_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP",
	/*    12 */ "CSN1_EC_Primary_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER",
	/*    13 */ "CSN1_EC_Primary_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP",
	/*    14 */ "CSN1_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS",
	/*    15 */ "CSN1_EC_Packet_Access_Reject_message_content_Reject",
	/*    16 */ "CSN1_EC_Packet_Access_Reject_message_content_Additional_Reject",
	/*    17 */ "CSN1_EC_Packet_Control_Acknowledgement_message_content_TLLI",
	/*    18 */ "CSN1_EC_Packet_Control_Acknowledgement_message_content_CTRL_ACK",
	/*    19 */ "CSN1_EC_Packet_Control_Acknowledgement_message_content_DL_CC_EST",
	/*    20 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI",
	/*    21 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY",
	/*    22 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description",
	/*    23 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report",
	/*    24 */ "CSN1_EC_Channel_Quality_Report_IE_GMSK_MEAN_BEP",
	/*    25 */ "CSN1_EC_Channel_Quality_Report_IE_GMSK_CV_BEP",
	/*    26 */ "CSN1_EC_Channel_Quality_Report_IE__8PSK_MEAN_BEP",
	/*    27 */ "CSN1_EC_Channel_Quality_Report_IE__8PSK_CV_BEP",
	/*    28 */ "CSN1_EC_Channel_Quality_Report_IE_C_VALUE",
	/*    29 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST",
	/*    30 */ "CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description",
	/*    31 */ "CSN1_EC_Channel_Request_Description_struct_PRIORITY",
	/*    32 */ "CSN1_EC_Channel_Request_Description_struct_NUMBER_OF_UL_DATA_BLOCKS",
	/*    33 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS",
	/*    34 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Global_TFI",
	/*    35 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK",
	/*    36 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters",
	/*    37 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS",
	/*    38 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT",
	/*    39 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR",
	/*    40 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT",
	/*    41 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS",
	/*    42 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET",
	/*    43 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance",
	/*    44 */ "CSN1_EC_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE",
	/*    45 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_P0",
	/*    46 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_PR_MODE",
	/*    47 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_GAMMA",
	/*    48 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable",
	/*    49 */ "CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS",
	/*    50 */ "CSN1_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS",
	/*    51 */ "CSN1_EC_Packet_Polling_Request_message_content_Global_TFI",
	/*    52 */ "CSN1_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK",
	/*    53 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS",
	/*    54 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI",
	/*    55 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T",
	/*    56 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance",
	/*    57 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA",
	/*    58 */ "CSN1_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS",
	/*    59 */ "CSN1_EC_Packet_TBF_Release_message_content_GLOBAL_TFI",
	/*    60 */ "CSN1_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE",
	/*    61 */ "CSN1_EC_Packet_TBF_Release_message_content_WAIT_INDICATION",
	/*    62 */ "CSN1_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE",
	/*    63 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS",
	/*    64 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI",
	/*    65 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI",
	/*    66 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description",
	/*    67 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation",
	/*    68 */ "CSN1_PUANCR_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK",
	/*    69 */ "CSN1_PUANCR_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK",
	/*    70 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT",
	/*    71 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS",
	/*    72 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI",
	/*    73 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI",
	/*    74 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description",
	/*    75 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI",
	/*    76 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description",
	/*    77 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation",
	/*    78 */ "CSN1_PUAN_Fixed_Uplink_Allocation_struct_BSN_OFFSET",
	/*    79 */ "CSN1_PUAN_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK",
	/*    80 */ "CSN1_PUAN_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK",
	/*    81 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT",
	/*    82 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command",
	/*    83 */ "CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme",
	/*    84 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS",
	/*    85 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT",
	/*    86 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS",
	/*    87 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET",
	/*    88 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR",
	/*    89 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_T3238",
	/*    90 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time",
	/*    91 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern",
	/*    92 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance",
	/*    93 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA",
	/*    94 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable",
	/*    95 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS",
	/*    96 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Global_TFI",
	/*    97 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT",
	/*    98 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command",
	/*    99 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE",
	/*   100 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance",
	/*   101 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters",
	/*   102 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS",
	/*   103 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT",
	/*   104 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR",
	/*   105 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation",
	/*   106 */ "CSN1_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK",
	/*   107 */ "CSN1_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK",
	/*   108 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_P0",
	/*   109 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_PR_MODE",
	/*   110 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_GAMMA",
	/*   111 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable",
	/*   112 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS",
	/*   113 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET",
	/*   114 */ NULL, /* UNUSED */
	/*   115 */ NULL, /* UNUSED */
	/*   116 */ NULL, /* UNUSED */
	/*   117 */ NULL, /* UNUSED */
	/*   118 */ NULL, /* UNUSED */
	/*   119 */ NULL, /* UNUSED */
	/*   120 */ NULL, /* UNUSED */
	/*   121 */ "CSN1_EC_Reject_struct_Ignore",
	/*   122 */ "CSN1_EC_Packet_Access_Reject_message_content_Distribution_part_error",
	/*   123 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error",
	/*   124 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error",
	/*   125 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Message_escape",
	/*   126 */ "CSN1_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error",
	/*   127 */ "CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error",
	/*   128 */ "CSN1_EC_Packet_Polling_Request_message_content_Non_distribution_part_error",
	/*   129 */ "CSN1_EC_Packet_Polling_Request_message_content_Address_information_part_error",
	/*   130 */ "CSN1_EC_Packet_Polling_Request_message_content_Message_escape",
	/*   131 */ "CSN1_EC_Packet_Polling_Request_message_content_Distribution_part_error",
	/*   132 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error",
	/*   133 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error",
	/*   134 */ "CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error",
	/*   135 */ "CSN1_EC_Packet_TBF_Release_message_content_Non_distribution_part_error",
	/*   136 */ "CSN1_EC_Packet_TBF_Release_message_content_Address_information_part_error",
	/*   137 */ "CSN1_EC_Packet_TBF_Release_message_content_Distribution_part_error",
	/*   138 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error",
	/*   139 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error",
	/*   140 */ "CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error",
	/*   141 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error",
	/*   142 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error",
	/*   143 */ "CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error",
	/*   144 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error",
	/*   145 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error",
	/*   146 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Message_escape",
	/*   147 */ "CSN1_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error",
	NULL
};
#endif

#ifdef CSN1C_ENABLE_LABEL_SIZE
/* For each label id, there is an entry describing its size */
const unsigned char Program_EC_PACCH_LabelSize [] = {

	/*     0 */ 5, /* CSN1_EC_Reject_struct_Downlink_TFI */
	/*     1 */ 8, /* CSN1_EC_Reject_struct_WAIT_INDICATION */
	/*     2 */ 1, /* CSN1_EC_Reject_struct_WAIT__INDICATION_SIZE */
	/*     3 */ 7, /* CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_MESSAGE_TYPE */
	/*     4 */ 4, /* CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_DL_CC_EST */
	/*     5 */ 5, /* CSN1_Frequency_Parameters_struct_EC_MA_NUMBER */
	/*     6 */ 3, /* CSN1_Frequency_Parameters_struct_TSC */
	/*     7 */ 1, /* CSN1_Frequency_Parameters_struct_Primary_TSC_Set */
	/*     8 */ 5, /* CSN1_Global_TFI_IE_UPLINK_TFI */
	/*     9 */ 5, /* CSN1_Global_TFI_IE_DOWNLINK_TFI */
	/*    10 */ 5, /* CSN1_EC_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER */
	/*    11 */ 16, /* CSN1_EC_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP */
	/*    12 */ 5, /* CSN1_EC_Primary_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER */
	/*    13 */ 8, /* CSN1_EC_Primary_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP */
	/*    14 */ 2, /* CSN1_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS */
	/*    15 */ 0, /* CSN1_EC_Packet_Access_Reject_message_content_Reject */
	/*    16 */ 0, /* CSN1_EC_Packet_Access_Reject_message_content_Additional_Reject */
	/*    17 */ 32, /* CSN1_EC_Packet_Control_Acknowledgement_message_content_TLLI */
	/*    18 */ 2, /* CSN1_EC_Packet_Control_Acknowledgement_message_content_CTRL_ACK */
	/*    19 */ 4, /* CSN1_EC_Packet_Control_Acknowledgement_message_content_DL_CC_EST */
	/*    20 */ 5, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI */
	/*    21 */ 1, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY */
	/*    22 */ 21, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description */
	/*    23 */ 0, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report */
	/*    24 */ 5, /* CSN1_EC_Channel_Quality_Report_IE_GMSK_MEAN_BEP */
	/*    25 */ 3, /* CSN1_EC_Channel_Quality_Report_IE_GMSK_CV_BEP */
	/*    26 */ 5, /* CSN1_EC_Channel_Quality_Report_IE__8PSK_MEAN_BEP */
	/*    27 */ 3, /* CSN1_EC_Channel_Quality_Report_IE__8PSK_CV_BEP */
	/*    28 */ 6, /* CSN1_EC_Channel_Quality_Report_IE_C_VALUE */
	/*    29 */ 4, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST */
	/*    30 */ 5, /* CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description */
	/*    31 */ 1, /* CSN1_EC_Channel_Request_Description_struct_PRIORITY */
	/*    32 */ 4, /* CSN1_EC_Channel_Request_Description_struct_NUMBER_OF_UL_DATA_BLOCKS */
	/*    33 */ 2, /* CSN1_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS */
	/*    34 */ 6, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Global_TFI */
	/*    35 */ 1, /* CSN1_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK */
	/*    36 */ 9, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters */
	/*    37 */ 2, /* CSN1_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS */
	/*    38 */ 3, /* CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT */
	/*    39 */ 3, /* CSN1_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR */
	/*    40 */ 5, /* CSN1_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT */
	/*    41 */ 2, /* CSN1_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS */
	/*    42 */ 2, /* CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET */
	/*    43 */ 6, /* CSN1_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance */
	/*    44 */ 6, /* CSN1_EC_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE */
	/*    45 */ 4, /* CSN1_EC_Packet_Downlink_Assignment_message_content_P0 */
	/*    46 */ 1, /* CSN1_EC_Packet_Downlink_Assignment_message_content_PR_MODE */
	/*    47 */ 5, /* CSN1_EC_Packet_Downlink_Assignment_message_content_GAMMA */
	/*    48 */ 1, /* CSN1_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable */
	/*    49 */ 2, /* CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS */
	/*    50 */ 2, /* CSN1_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS */
	/*    51 */ 6, /* CSN1_EC_Packet_Polling_Request_message_content_Global_TFI */
	/*    52 */ 1, /* CSN1_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK */
	/*    53 */ 2, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS */
	/*    54 */ 6, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI */
	/*    55 */ 5, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T */
	/*    56 */ 6, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance */
	/*    57 */ 5, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA */
	/*    58 */ 2, /* CSN1_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS */
	/*    59 */ 6, /* CSN1_EC_Packet_TBF_Release_message_content_GLOBAL_TFI */
	/*    60 */ 4, /* CSN1_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE */
	/*    61 */ 8, /* CSN1_EC_Packet_TBF_Release_message_content_WAIT_INDICATION */
	/*    62 */ 1, /* CSN1_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE */
	/*    63 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS */
	/*    64 */ 5, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI */
	/*    65 */ 32, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI */
	/*    66 */ 13, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description */
	/*    67 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation */
	/*    68 */ 4, /* CSN1_PUANCR_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK */
	/*    69 */ 3, /* CSN1_PUANCR_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK */
	/*    70 */ 1, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT */
	/*    71 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS */
	/*    72 */ 5, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI */
	/*    73 */ 32, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI */
	/*    74 */ 13, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description */
	/*    75 */ 4, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI */
	/*    76 */ 21, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description */
	/*    77 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation */
	/*    78 */ 2, /* CSN1_PUAN_Fixed_Uplink_Allocation_struct_BSN_OFFSET */
	/*    79 */ 4, /* CSN1_PUAN_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK */
	/*    80 */ 3, /* CSN1_PUAN_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK */
	/*    81 */ 1, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT */
	/*    82 */ 4, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command */
	/*    83 */ 4, /* CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme */
	/*    84 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS */
	/*    85 */ 3, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT */
	/*    86 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS */
	/*    87 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET */
	/*    88 */ 3, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR */
	/*    89 */ 3, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_T3238 */
	/*    90 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time */
	/*    91 */ 2, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern */
	/*    92 */ 6, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance */
	/*    93 */ 5, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA */
	/*    94 */ 1, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable */
	/*    95 */ 2, /* CSN1_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS */
	/*    96 */ 6, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Global_TFI */
	/*    97 */ 5, /* CSN1_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT */
	/*    98 */ 4, /* CSN1_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command */
	/*    99 */ 2, /* CSN1_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE */
	/*   100 */ 6, /* CSN1_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance */
	/*   101 */ 9, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters */
	/*   102 */ 2, /* CSN1_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS */
	/*   103 */ 3, /* CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT */
	/*   104 */ 3, /* CSN1_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR */
	/*   105 */ 0, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation */
	/*   106 */ 4, /* CSN1_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK */
	/*   107 */ 3, /* CSN1_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK */
	/*   108 */ 4, /* CSN1_EC_Packet_Uplink_Assignment_message_content_P0 */
	/*   109 */ 1, /* CSN1_EC_Packet_Uplink_Assignment_message_content_PR_MODE */
	/*   110 */ 5, /* CSN1_EC_Packet_Uplink_Assignment_message_content_GAMMA */
	/*   111 */ 1, /* CSN1_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable */
	/*   112 */ 2, /* CSN1_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS */
	/*   113 */ 2, /* CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET */
	/*   114 */ 0, /* Undefined label id */
	/*   115 */ 0, /* Undefined label id */
	/*   116 */ 0, /* Undefined label id */
	/*   117 */ 0, /* Undefined label id */
	/*   118 */ 0, /* Undefined label id */
	/*   119 */ 0, /* Undefined label id */
	/*   120 */ 0, /* Undefined label id */
	/*   121 */ 0, /* CSN1_EC_Reject_struct_Ignore */
	/*   122 */ 0, /* CSN1_EC_Packet_Access_Reject_message_content_Distribution_part_error */
	/*   123 */ 0, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error */
	/*   124 */ 0, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error */
	/*   125 */ 0, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Message_escape */
	/*   126 */ 0, /* CSN1_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error */
	/*   127 */ 0, /* CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error */
	/*   128 */ 0, /* CSN1_EC_Packet_Polling_Request_message_content_Non_distribution_part_error */
	/*   129 */ 0, /* CSN1_EC_Packet_Polling_Request_message_content_Address_information_part_error */
	/*   130 */ 0, /* CSN1_EC_Packet_Polling_Request_message_content_Message_escape */
	/*   131 */ 0, /* CSN1_EC_Packet_Polling_Request_message_content_Distribution_part_error */
	/*   132 */ 0, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error */
	/*   133 */ 0, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error */
	/*   134 */ 0, /* CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error */
	/*   135 */ 0, /* CSN1_EC_Packet_TBF_Release_message_content_Non_distribution_part_error */
	/*   136 */ 0, /* CSN1_EC_Packet_TBF_Release_message_content_Address_information_part_error */
	/*   137 */ 0, /* CSN1_EC_Packet_TBF_Release_message_content_Distribution_part_error */
	/*   138 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error */
	/*   139 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error */
	/*   140 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error */
	/*   141 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error */
	/*   142 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error */
	/*   143 */ 0, /* CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error */
	/*   144 */ 0, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error */
	/*   145 */ 0, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error */
	/*   146 */ 0, /* CSN1_EC_Packet_Uplink_Assignment_message_content_Message_escape */
	/*   147 */ 0  /* CSN1_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error */
};
#endif

/* FieldId Pair Set */
static const CSN1C_PAIRSET_TYPE Program_EC_PACCH_FieldIdPairSet [] = {
	/* 0000 (ID:0091:3355:3384) <Downlink_TFI> */ 0,12,54,43,46,44,50,
	/* 0007 (ID:0100:3392:3426) <WAIT_INDICATION> */ 1,12,55,43,47,44,51,
	/* 0014 (ID:0104:3426:3462) <WAIT__INDICATION_SIZE> */ 2,12,56,43,48,44,52,
	/* 0021 (ID:0109:3468:3503) <Ignore> */ 121,12,57,43,49,44,53,
	/* 0028 (ID:0134:3951:3992) <MESSAGE_TYPE> */ 3,14,61,
	/* 0031 (ID:0146:3992:4016) <DL_CC_EST> */ 4,14,62,
	/* 0034 (ID:0335:6070:6099) <EC_MA_NUMBER> */ 5,18,105,83,101,181,200,
	/* 0041 (ID:0339:6099:6119) <TSC> */ 6,18,106,83,102,181,201,
	/* 0048 (ID:0343:6119:6148) <Primary_TSC_Set> */ 7,18,107,83,103,181,202,
	/* 0055 (ID:1023:13931:13958) <UPLINK_TFI> */ 8,29,222,81,99,111,117,120,127,131,138,176,196,
	/* 0068 (ID:1029:13962:13989) <DOWNLINK_TFI> */ 9,29,223,81,100,111,118,120,128,131,139,176,197,
	/* 0081 (ID:1038:14404:14445) <STARTING_SEQUENCE_NUMBER> */ 10,31,224,65,69,142,163,
	/* 0088 (ID:1042:14445:14481) <RECEIVED_BLOCK_BITMAP> */ 11,31,225,65,70,142,164,
	/* 0095 (ID:1048:14697:14738) <STARTING_SEQUENCE_NUMBER> */ 12,32,226,144,165,210,216,
	/* 0102 (ID:1052:14738:14773) <RECEIVED_BLOCK_BITMAP> */ 13,32,227,144,166,210,217,
	/* 0109 (ID:0060:3014:3075) <USED_DL_COVERAGE_CLASS> */ 14,11,42,
	/* 0112 (ID:0064:3075:3111) <Reject> */ 15,11,43,
	/* 0115 (ID:0074:3117:3161) <Additional_Reject> */ 16,11,44,
	/* 0118 (ID:0081:3263:3317) <Distribution_part_error> */ 122,11,45,
	/* 0121 (ID:0119:3767:3789) <TLLI> */ 17,13,58,
	/* 0124 (ID:0123:3789:3814) <CTRL_ACK> */ 18,13,59,
	/* 0127 (ID:0127:3814:3840) <DL_CC_EST> */ 19,13,60,
	/* 0130 (ID:0152:4235:4264) <DOWNLINK_TFI> */ 20,15,63,
	/* 0133 (ID:0156:4264:4295) <MS_OUT_OF_MEMORY> */ 21,15,64,
	/* 0136 (ID:0163:4299:4389) <EC_Ack_Nack_Description> */ 22,15,65,
	/* 0139 (ID:0176:4442:4511) <EC_Channel_Quality_Report> */ 23,15,66,
	/* 0142 (ID:1069:15221:15252) <GMSK_MEAN_BEP> */ 24,34,229,66,71,
	/* 0147 (ID:1073:15252:15278) <GMSK_CV_BEP> */ 25,34,230,66,72,
	/* 0152 (ID:1082:15290:15321) <_8PSK_MEAN_BEP> */ 26,34,231,66,73,
	/* 0157 (ID:1086:15321:15347) <_8PSK_CV_BEP> */ 27,34,232,66,74,
	/* 0162 (ID:1090:15351:15372) <C_VALUE> */ 28,34,233,66,75,
	/* 0167 (ID:0180:4511:4535) <DL_CC_EST> */ 29,15,67,
	/* 0170 (ID:0189:4549:4628) <EC_Channel_Request_Description> */ 30,15,68,
	/* 0173 (ID:0196:4706:4731) <PRIORITY> */ 31,16,78,68,76,
	/* 0178 (ID:0200:4731:4769) <NUMBER_OF_UL_DATA_BLOCKS> */ 32,16,79,68,77,
	/* 0183 (ID:0206:4992:5052) <USED_DL_COVERAGE_CLASS> */ 33,17,80,
	/* 0186 (ID:0213:5056:5095) <Global_TFI> */ 34,17,81,
	/* 0189 (ID:0221:5098:5129) <CONTROL_ACK> */ 35,17,82,
	/* 0192 (ID:0230:5137:5196) <Frequency_Parameters> */ 36,17,83,
	/* 0195 (ID:0234:5203:5240) <DL_COVERAGE_CLASS> */ 37,17,84,
	/* 0198 (ID:0238:5240:5280) <STARTING_DL_TIMESLOT> */ 38,17,85,
	/* 0201 (ID:0242:5280:5322) <TIMESLOT_MULTIPLICATOR> */ 39,17,86,
	/* 0204 (ID:0246:5322:5365) <DOWNLINK_TFI_ASSIGNMENT> */ 40,17,87,
	/* 0207 (ID:0250:5365:5402) <UL_COVERAGE_CLASS> */ 41,17,88,
	/* 0210 (ID:0254:5402:5449) <STARTING_UL_TIMESLOT_OFFSET> */ 42,17,89,
	/* 0213 (ID:0263:5457:5520) <EC_Packet_Timing_Advance> */ 43,17,90,
	/* 0216 (ID:1058:14975:15009) <TIMING_ADVANCE_VALUE> */ 44,33,228,90,104,122,129,157,171,180,199,
	/* 0227 (ID:0272:5535:5559) <P0> */ 45,17,91,
	/* 0230 (ID:0276:5559:5581) <PR_MODE> */ 46,17,92,
	/* 0233 (ID:0285:5596:5623) <GAMMA> */ 47,17,93,
	/* 0236 (ID:0289:5623:5650) <ALPHA_Enable> */ 48,17,94,
	/* 0239 (ID:0295:5748:5806) <Non_distribution_part_error> */ 123,17,95,
	/* 0242 (ID:0304:5814:5878) <Address_information_part_error> */ 124,17,96,
	/* 0245 (ID:0313:5880:5929) <Message_escape> */ 125,17,97,
	/* 0248 (ID:0325:5967:6021) <Distribution_part_error> */ 126,17,98,
	/* 0251 (ID:0349:6392:6452) <USED_DL_COVERAGE_CLASS> */ 49,19,108,
	/* 0254 (ID:0355:6473:6527) <Distribution_part_error> */ 127,19,109,
	/* 0257 (ID:0365:6742:6802) <USED_DL_COVERAGE_CLASS> */ 50,20,110,
	/* 0260 (ID:0372:6806:6845) <Global_TFI> */ 51,20,111,
	/* 0263 (ID:0378:6847:6878) <TYPE_OF_ACK> */ 52,20,112,
	/* 0266 (ID:0384:6902:6960) <Non_distribution_part_error> */ 128,20,113,
	/* 0269 (ID:0393:6968:7032) <Address_information_part_error> */ 129,20,114,
	/* 0272 (ID:0402:7034:7083) <Message_escape> */ 130,20,115,
	/* 0275 (ID:0414:7121:7175) <Distribution_part_error> */ 131,20,116,
	/* 0278 (ID:0424:7416:7476) <USED_DL_COVERAGE_CLASS> */ 53,21,119,
	/* 0281 (ID:0430:7478:7516) <Global_TFI> */ 54,21,120,
	/* 0284 (ID:0441:7526:7548) <T_AVG_T> */ 55,21,121,
	/* 0287 (ID:0450:7562:7624) <EC_Packet_Timing_Advance> */ 56,21,122,
	/* 0290 (ID:1058:14975:15009) <TIMING_ADVANCE_VALUE> */ 44,33,228,90,104,122,129,157,171,180,199,
	/* 0301 (ID:0459:7638:7658) <GAMMA> */ 57,21,123,
	/* 0304 (ID:0465:7687:7745) <Non_distribution_part_error> */ 132,21,124,
	/* 0307 (ID:0474:7752:7813) <Address_information_part_error> */ 133,21,125,
	/* 0310 (ID:0483:7819:7873) <Distribution_part_error> */ 134,21,126,
	/* 0313 (ID:0493:8080:8140) <USED_DL_COVERAGE_CLASS> */ 58,22,130,
	/* 0316 (ID:0500:8144:8178) <GLOBAL_TFI> */ 59,22,131,
	/* 0319 (ID:0506:8180:8234) <TBF_RELEASE_CAUSE> */ 60,22,132,
	/* 0322 (ID:0529:8242:8278) <WAIT_INDICATION> */ 61,22,133,
	/* 0325 (ID:0533:8278:8314) <WAIT__INDICATION_SIZE> */ 62,22,134,
	/* 0328 (ID:0539:8343:8401) <Non_distribution_part_error> */ 135,22,135,
	/* 0331 (ID:0548:8408:8469) <Address_information_part_error> */ 136,22,136,
	/* 0334 (ID:0557:8475:8529) <Distribution_part_error> */ 137,22,137,
	/* 0337 (ID:0940:12900:12960) <USED_DL_COVERAGE_CLASS> */ 63,27,207,
	/* 0340 (ID:0948:12964:12992) <UPLINK_TFI> */ 64,27,208,
	/* 0343 (ID:0954:12994:13040) <CONTENTION_RESOLUTION_TLLI> */ 65,27,209,
	/* 0346 (ID:0958:13040:13120) <EC_Primary_Ack_Nack_Description> */ 66,27,210,
	/* 0349 (ID:0962:13120:13203) <PUANCR_Fixed_Uplink_Allocation> */ 67,27,211,
	/* 0352 (ID:1000:13496:13542) <START_FIRST_UL_RLC_DATA_BLOCK> */ 68,28,220,211,218,
	/* 0357 (ID:1013:13651:13744) <DELAY_NEXT_UL_RLC_DATA_BLOCK> */ 69,28,221,211,219,
	/* 0362 (ID:0966:13203:13231) <RESEGMENT> */ 70,27,212,
	/* 0365 (ID:0972:13256:13312) <Non_distribution_part_error> */ 138,27,213,
	/* 0368 (ID:0981:13319:13378) <Address_information_part_error> */ 139,27,214,
	/* 0371 (ID:0990:13384:13436) <Distribution_part_error> */ 140,27,215,
	/* 0374 (ID:0567:8744:8804) <USED_DL_COVERAGE_CLASS> */ 71,23,140,
	/* 0377 (ID:0575:8808:8836) <UPLINK_TFI> */ 72,23,141,
	/* 0380 (ID:0597:8953:9003) <CONTENTION_RESOLUTION_TLLI> */ 73,23,143,
	/* 0383 (ID:0601:9003:9079) <EC_Primary_Ack_Nack_Description> */ 74,23,144,
	/* 0386 (ID:0610:9094:9144) <CONTENTION_RESOLUTION_rTLLI> */ 75,23,145,
	/* 0389 (ID:0614:9144:9220) <EC_Primary_Ack_Nack_Description> */ 74,23,144,
	/* 0392 (ID:0588:8880:8946) <EC_Ack_Nack_Description> */ 76,23,142,
	/* 0395 (ID:0618:9229:9309) <PUAN_Fixed_Uplink_Allocation> */ 77,23,146,
	/* 0398 (ID:0749:10469:10494) <BSN_OFFSET> */ 78,24,172,146,167,
	/* 0403 (ID:0753:10498:10550) <START_FIRST_UL_RLC_DATA_BLOCK> */ 79,24,173,146,168,
	/* 0408 (ID:0764:10558:10652) <DELAY_NEXT_UL_RLC_DATA_BLOCK> */ 80,24,174,146,169,
	/* 0413 (ID:0622:9309:9338) <RESEGMENT> */ 81,23,147,
	/* 0416 (ID:0631:9346:9422) <EGPRS_Channel_Coding_Command> */ 82,23,148,
	/* 0419 (ID:1105:15807:16080) <Scheme> */ 83,36,235,37,236,148,170,178,198,
	/* 0428 (ID:0640:9437:9476) <UL_COVERAGE_CLASS> */ 84,23,149,
	/* 0431 (ID:0644:9476:9518) <STARTING_UL_TIMESLOT> */ 85,23,150,
	/* 0434 (ID:0648:9518:9557) <DL_COVERAGE_CLASS> */ 86,23,151,
	/* 0437 (ID:0652:9557:9606) <STARTING_DL_TIMESLOT_OFFSET> */ 87,23,152,
	/* 0440 (ID:0656:9606:9643) <TIMESLOT_MULTIPLICATOR> */ 88,23,153,
	/* 0443 (ID:0669:9722:9764) <CONTENTION_RESOLUTION_TLLI> */ 73,23,143,
	/* 0446 (ID:0680:9865:9958) <T3238> */ 89,23,154,
	/* 0449 (ID:0684:9958:10001) <Initial_Waiting_Time> */ 90,23,155,
	/* 0452 (ID:0688:10001:10043) <EC_PACCH_Monitoring_Pattern> */ 91,23,156,
	/* 0455 (ID:0697:10061:10124) <EC_Packet_Timing_Advance> */ 92,23,157,
	/* 0458 (ID:1058:14975:15009) <TIMING_ADVANCE_VALUE> */ 44,33,228,90,104,122,129,157,171,180,199,
	/* 0469 (ID:0706:10138:10165) <GAMMA> */ 93,23,158,
	/* 0472 (ID:0710:10165:10192) <ALPHA_Enable> */ 94,23,159,
	/* 0475 (ID:0716:10223:10279) <Non_distribution_part_error> */ 141,23,160,
	/* 0478 (ID:0725:10286:10345) <Address_information_part_error> */ 142,23,161,
	/* 0481 (ID:0734:10351:10403) <Distribution_part_error> */ 143,23,162,
	/* 0484 (ID:0773:10976:11036) <USED_DL_COVERAGE_CLASS> */ 95,25,175,
	/* 0487 (ID:0782:11042:11081) <Global_TFI> */ 96,25,176,
	/* 0490 (ID:0793:11091:11127) <UPLINK_TFI_ASSIGNMENT> */ 97,25,177,
	/* 0493 (ID:0802:11142:11218) <EGPRS_Channel_Coding_Command> */ 98,25,178,
	/* 0496 (ID:1105:15807:16080) <Scheme> */ 83,36,235,37,236,148,170,178,198,
	/* 0505 (ID:0806:11225:11263) <OVERLAID_CDMA_CODE> */ 99,25,179,
	/* 0508 (ID:0815:11271:11334) <EC_Packet_Timing_Advance> */ 100,25,180,
	/* 0511 (ID:1058:14975:15009) <TIMING_ADVANCE_VALUE> */ 44,33,228,90,104,122,129,157,171,180,199,
	/* 0522 (ID:0824:11349:11408) <Frequency_Parameters> */ 101,25,181,
	/* 0525 (ID:0828:11415:11452) <UL_COVERAGE_CLASS> */ 102,25,182,
	/* 0528 (ID:0832:11452:11492) <STARTING_UL_TIMESLOT> */ 103,25,183,
	/* 0531 (ID:0836:11492:11534) <TIMESLOT_MULTIPLICATOR> */ 104,25,184,
	/* 0534 (ID:0840:11534:11604) <Fixed_Uplink_Allocation> */ 105,25,185,
	/* 0537 (ID:0920:12375:12421) <START_FIRST_UL_RLC_DATA_BLOCK> */ 106,26,205,185,203,
	/* 0542 (ID:0933:12531:12624) <DELAY_NEXT_UL_RLC_DATA_BLOCK> */ 107,26,206,185,204,
	/* 0547 (ID:0849:11612:11637) <P0> */ 108,25,186,
	/* 0550 (ID:0853:11637:11659) <PR_MODE> */ 109,25,187,
	/* 0553 (ID:0862:11674:11701) <GAMMA> */ 110,25,188,
	/* 0556 (ID:0866:11701:11728) <ALPHA_Enable> */ 111,25,189,
	/* 0559 (ID:0870:11735:11772) <DL_COVERAGE_CLASS> */ 112,25,190,
	/* 0562 (ID:0874:11772:11819) <STARTING_DL_TIMESLOT_OFFSET> */ 113,25,191,
	/* 0565 (ID:0880:11911:11969) <Non_distribution_part_error> */ 144,25,192,
	/* 0568 (ID:0889:11977:12041) <Address_information_part_error> */ 145,25,193,
	/* 0571 (ID:0898:12043:12092) <Message_escape> */ 146,25,194,
	/* 0574 (ID:0910:12130:12184) <Distribution_part_error> */ 147,25,195

#ifndef NDEBUG
	, -1, -1 /* Used in conjunction with an assert */
#endif
};

/* CUSTOM EXPRESSION 0 (ID:0026:671:678) */
unsigned ED_EXLONG Program_EC_PACCH_expr0000 (TCSN1CContext* Context) {
	ED_WARNING_REMOVER(Context);
	return (unsigned ED_EXLONG)((8 - (CURPOS & 7)) & 7);
}
static const unsigned ED_EXLONG (*const Program_EC_PACCH_ExpressionMap[]) (TCSN1CContext*) = {
	(const unsigned ED_EXLONG (*const) (TCSN1CContext*))Program_EC_PACCH_expr0000};
/* CUSTOM ACTION 0 (ID:0036:761:801) */
void Program_EC_PACCH_action0000 (TCSN1CContext* Context ED_EXTRAPARAMS_DECL) {
	ED_WARNING_REMOVER(Context);
	ED_EXTRAPARAMS_CODE
{
	CSN1_BACKTRACK;
}}
static const void (*const Program_EC_PACCH_FunctionMap[]) (TCSN1CContext* ED_EXTRAPARAMS_DECL) = {
	(const void (*const) (TCSN1CContext* ED_EXTRAPARAMS_DECL))Program_EC_PACCH_action0000};
/* PROGRAM CODE FOR PROGRAM 'Program_EC_PACCH' */
static const unsigned char Program_EC_PACCH_ProgramCode [] = {

	/*-----------------------------------------------------------------
		DEFINITION 'bit'
		DEFINITION FIELD-ID: 1  COMPLEXITY: 5
		SOURCE: ./csn1lib.src, 5
	-----------------------------------------------------------------*/
	/* 000000 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000001 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'bit_string'
		DEFINITION FIELD-ID: 2  COMPLEXITY: 5
		SOURCE: ./csn1lib.src, 6
	-----------------------------------------------------------------*/
	/* 000002 */ CSN1C_BIT_A(1),                          /* (ID:0007:558:559) */
	/* 000003 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_L'
		DEFINITION FIELD-ID: 3  COMPLEXITY: 3
		SOURCE: ./csn1lib.src, 7
	-----------------------------------------------------------------*/
	/* 000004 */ CSN1C_BIT_L,                             /* (ID:0012:578:579) */
	/* 000005 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bits'
		DEFINITION FIELD-ID: 4  COMPLEXITY: 5
		SOURCE: ./csn1lib.src, 8
	-----------------------------------------------------------------*/
	/* 000006 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0013:599:602) FBIT choice at 6, node 1, jump to 11 */
	/* 000008 */ CSN1C_BIT_L,                             /* (ID:0015:599:600) */
	/* 000009 */ CSN1C_GOTO(8),                           /* (ID:0013:599:602) jump at 17 */
	/* 000011 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0013:599:602) FBIT choice at 6, node 2, jump to 16 */
	/* 000013 */ CSN1C_BIT_H,                             /* (ID:0017:601:602) */
	/* 000014 */ CSN1C_GOTO(3),                           /* (ID:0013:599:602) jump at 17 */
	/* 000016 */ CSN1C_BACKTRACK,                         /* (ID:0013:599:602) Failure of choice begun at 6 */
	/* 000017 */ CSN1C_CHOICE_END,                        /* (ID:0013:599:602) End of choice begun at 6 */
	/* 000018 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'no_string'
		DEFINITION FIELD-ID: 8  COMPLEXITY: 4
		SOURCE: ./csn1lib.src, 12
	-----------------------------------------------------------------*/
	/* 000019 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000021 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_bit'
		DEFINITION FIELD-ID: 5  COMPLEXITY: 3
		SOURCE: ./csn1lib.src, 9
	-----------------------------------------------------------------*/
	/* 000022 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000023 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'octet'
		DEFINITION FIELD-ID: 6  COMPLEXITY: 3
		SOURCE: ./csn1lib.src, 10
	-----------------------------------------------------------------*/
	/* 000024 */ CSN1C_BIT_A(8),                          /* (ID:0002:535:536) */
	/* 000025 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'spare_padding'
		DEFINITION FIELD-ID: 7  COMPLEXITY: 9
		SOURCE: ./csn1lib.src, 11
	-----------------------------------------------------------------*/
	/* 000026 */ CSN1C_LOOP_BEGIN_VAR_ED_INF, CSN1C_VAL3(31), CSN1C_VAL1(0), /* (ID:0026:671:678) When decoding infinite loop; at the end jump to 41 */
	/* 000031 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:0026:671:678) Send construction; if encoding, jump to 38 */
	/* 000035 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000036 */ CSN1C_GOTO(3),                           /* (ID:0026:671:678) skip the encode part and jump to 39 */
	/* 000038 */ CSN1C_BIT_L,                             /* (ID:0032:677:678) */
	/* 000039 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(8),         /* (ID:0026:671:678) Loop back to 31 */
	/* 000041 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'padding_bits'
		DEFINITION FIELD-ID: 9  COMPLEXITY: 3
		SOURCE: ./csn1lib.src, 13
	-----------------------------------------------------------------*/
	/* 000042 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 49 */
	/* 000046 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000047 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 46 */
	/* 000049 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Reject_struct'
		DEFINITION FIELD-ID: 12  COMPLEXITY: 28
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 90
	-----------------------------------------------------------------*/
	/* 000050 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:0089:3355:3503) VBIT choice at 50, node 1, jump to 75 */
	/* 000052 */ CSN1C_LABEL_A, CSN1C_VAL1(1), CSN1C_VAL1(5), /* (ID:0091:3355:3384) Label=<Downlink_TFI> LabelId=0 */
	/* 000055 */ CSN1C_CHOICE_NODE(0,11),                 /* (ID:0095:3386:3462) VBIT choice at 55, node 1, jump to 66 */
	/* 000057 */ CSN1C_BIT_1,                             /* (ID:0099:3390:3392) */
	/* 000058 */ CSN1C_LABEL_A, CSN1C_VAL1(8), CSN1C_VAL1(8), /* (ID:0100:3392:3426) Label=<WAIT_INDICATION> LabelId=1 */
	/* 000061 */ CSN1C_LABEL_A, CSN1C_VAL1(15), CSN1C_VAL1(1), /* (ID:0104:3426:3462) Label=<WAIT__INDICATION_SIZE> LabelId=2 */
	/* 000064 */ CSN1C_GOTO(8),                           /* (ID:0095:3386:3462) jump at 72 */
	/* 000066 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0095:3386:3462) FBIT choice at 55, node 2, jump to 71 */
	/* 000068 */ CSN1C_BIT_0,                             /* (ID:0097:3386:3388) */
	/* 000069 */ CSN1C_GOTO(3),                           /* (ID:0095:3386:3462) jump at 72 */
	/* 000071 */ CSN1C_BACKTRACK,                         /* (ID:0095:3386:3462) Failure of choice begun at 55 */
	/* 000072 */ CSN1C_CHOICE_END,                        /* (ID:0095:3386:3462) End of choice begun at 55 */
	/* 000073 */ CSN1C_GOTO(24),                          /* (ID:0089:3355:3503) jump at 97 */
	/* 000075 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(45),       /* (ID:0109:3468:3503) Label=<Ignore> Terminal=<1> LabelId=121 */
	/* 000077 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0110:3479:3501) Send construction; if encoding, jump to 90 */
	/* 000081 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0113:3479:3483) Infinite loop start, jump to 88 */
	/* 000085 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000086 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0113:3479:3483) Loop back to 85 */
	/* 000088 */ CSN1C_GOTO(4),                           /* (ID:0110:3479:3501) skip the encode part and jump to 92 */
	/* 000090 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000092 */ CSN1C_LABEL_END, CSN1C_VAL1(45),         /* (ID:0109:3468:3503) Label=<Ignore> Terminal=<1> */
	/* 000094 */ CSN1C_GOTO(4),                           /* (ID:0089:3355:3503) jump at 99 */
	/* 000096 */ CSN1C_BACKTRACK,                         /* (ID:0089:3355:3503) Failure of choice begun at 50 */
	/* 000097 */ CSN1C_CHOICE_END,                        /* (ID:0089:3355:3503) End of choice begun at 50 */
	/* 000098 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Control_Acknowledgement_11_bit_message'
		DEFINITION FIELD-ID: 14  COMPLEXITY: 18
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 109
	-----------------------------------------------------------------*/
	/* 000099 */ CSN1C_LABEL_BEGIN, CSN1C_VAL1(59),       /* (ID:0134:3951:3992) Label=<MESSAGE_TYPE> Terminal=<1> LabelId=3 */
	/* 000101 */ CSN1C_PUSH_CURROFS,                      /* (ID:0135:3968:3988) Start of string that have to be intersected */
	/* 000102 */ CSN1C_BIT_A(7),                          /* (ID:0002:535:536) */
	/* 000103 */ CSN1C_INTERSECTION_BEGIN,                /* (ID:0135:3968:3988) Start of the intersection string */
	/* 000104 */ CSN1C_VALUE, CSN1C_VAL2(1910),           /* (ID:0139:3979:3980..0145:3986:3988) Bit string '1110111' */
	/* 000107 */ CSN1C_INTERSECTION_END,                  /* (ID:0135:3968:3988) End of the intersection string */
	/* 000108 */ CSN1C_LABEL_END, CSN1C_VAL1(59),         /* (ID:0134:3951:3992) Label=<MESSAGE_TYPE> Terminal=<1> */
	/* 000110 */ CSN1C_LABEL_A, CSN1C_VAL1(32), CSN1C_VAL1(4), /* (ID:0146:3992:4016) Label=<DL_CC_EST> LabelId=4 */
	/* 000113 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'Frequency_Parameters_struct'
		DEFINITION FIELD-ID: 18  COMPLEXITY: 14
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 166
	-----------------------------------------------------------------*/
	/* 000114 */ CSN1C_LABEL_A, CSN1C_VAL1(35), CSN1C_VAL1(5), /* (ID:0335:6070:6099) Label=<EC_MA_NUMBER> LabelId=5 */
	/* 000117 */ CSN1C_LABEL_A, CSN1C_VAL1(42), CSN1C_VAL1(3), /* (ID:0339:6099:6119) Label=<TSC> LabelId=6 */
	/* 000120 */ CSN1C_LABEL_A, CSN1C_VAL1(49), CSN1C_VAL1(1), /* (ID:0343:6119:6148) Label=<Primary_TSC_Set> LabelId=7 */
	/* 000123 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'Global_TFI_IE'
		DEFINITION FIELD-ID: 29  COMPLEXITY: 15
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 359
	-----------------------------------------------------------------*/
	/* 000124 */ CSN1C_CHOICE_NODE(0,8),                  /* (ID:1020:13929:13989) VBIT choice at 124, node 1, jump to 132 */
	/* 000126 */ CSN1C_BIT_0,                             /* (ID:1022:13929:13931) */
	/* 000127 */ CSN1C_LABEL_A, CSN1C_VAL1(56), CSN1C_VAL1(5), /* (ID:1023:13931:13958) Label=<UPLINK_TFI> LabelId=8 */
	/* 000130 */ CSN1C_GOTO(9),                           /* (ID:1020:13929:13989) jump at 139 */
	/* 000132 */ CSN1C_BIT_1,                             /* (ID:1028:13960:13962) */
	/* 000133 */ CSN1C_LABEL_A, CSN1C_VAL1(69), CSN1C_VAL1(5), /* (ID:1029:13962:13989) Label=<DOWNLINK_TFI> LabelId=9 */
	/* 000136 */ CSN1C_GOTO(4),                           /* (ID:1020:13929:13989) jump at 141 */
	/* 000138 */ CSN1C_BACKTRACK,                         /* (ID:1020:13929:13989) Failure of choice begun at 124 */
	/* 000139 */ CSN1C_CHOICE_END,                        /* (ID:1020:13929:13989) End of choice begun at 124 */
	/* 000140 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Ack_Nack_Description_IE'
		DEFINITION FIELD-ID: 31  COMPLEXITY: 10
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 380
	-----------------------------------------------------------------*/
	/* 000141 */ CSN1C_LABEL_A, CSN1C_VAL1(82), CSN1C_VAL1(5), /* (ID:1038:14404:14445) Label=<STARTING_SEQUENCE_NUMBER> LabelId=10 */
	/* 000144 */ CSN1C_LABEL_A, CSN1C_VAL1(89), CSN1C_VAL1(16), /* (ID:1042:14445:14481) Label=<RECEIVED_BLOCK_BITMAP> LabelId=11 */
	/* 000147 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Primary_Ack_Nack_Description_IE'
		DEFINITION FIELD-ID: 32  COMPLEXITY: 10
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 391
	-----------------------------------------------------------------*/
	/* 000148 */ CSN1C_LABEL_A, CSN1C_VAL1(96), CSN1C_VAL1(5), /* (ID:1048:14697:14738) Label=<STARTING_SEQUENCE_NUMBER> LabelId=12 */
	/* 000151 */ CSN1C_LABEL_A, CSN1C_VAL1(103), CSN1C_VAL1(8), /* (ID:1052:14738:14773) Label=<RECEIVED_BLOCK_BITMAP> LabelId=13 */
	/* 000154 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Access_Reject_message_content'
		DEFINITION FIELD-ID: 11  COMPLEXITY: 31
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 83
	-----------------------------------------------------------------*/
	/* 000155 */ CSN1C_CHOICE_NODE(0,43),                 /* (ID:0058:3014:3317) VBIT choice at 155, node 1, jump to 198 */
	/* 000157 */ CSN1C_LABEL_A, CSN1C_VAL1(110), CSN1C_VAL1(2), /* (ID:0060:3014:3075) Label=<USED_DL_COVERAGE_CLASS> LabelId=14 */
	/* 000160 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(226),      /* (ID:0064:3075:3111) Label=<Reject> Terminal=<0> LabelId=15 */
	/* 000163 */ CSN1C_GOSUB, CSN1C_VAL1(50),             /* (ID:0067:3086:3107) Reference to 'EC_Reject_struct' */
	/* 000165 */ CSN1C_LABEL_END, CSN1C_VAL2(226),        /* (ID:0064:3075:3111) Label=<Reject> Terminal=<0> */
	/* 000168 */ CSN1C_CHOICE_NODE(0,28),                 /* (ID:0069:3113:3187) Truncable concatenation, entry 0, jump to 196 */
	/* 000170 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(30), /* (ID:0070:3115:3161) Infinite loop start, jump to 185 */
	/* 000174 */ CSN1C_BIT_1,                             /* (ID:0073:3115:3117) */
	/* 000175 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(232),      /* (ID:0074:3117:3161) Label=<Additional_Reject> Terminal=<0> LabelId=16 */
	/* 000178 */ CSN1C_GOSUB, CSN1C_VAL1(50),             /* (ID:0077:3138:3159) Reference to 'EC_Reject_struct' */
	/* 000180 */ CSN1C_LABEL_END, CSN1C_VAL2(232),        /* (ID:0074:3117:3161) Label=<Additional_Reject> Terminal=<0> */
	/* 000183 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(9),         /* (ID:0070:3115:3161) Loop back to 174 */
	/* 000185 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0069:3113:3187) Truncable concatenation, entry 1 */
	/* 000186 */ CSN1C_BIT_0,                             /* (ID:0078:3166:3170) */
	/* 000187 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0069:3113:3187) Truncable concatenation, entry 2 */
	/* 000188 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 195 */
	/* 000192 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000193 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 192 */
	/* 000195 */ CSN1C_CHOICE_END,
	/* 000196 */ CSN1C_GOTO(26),                          /* (ID:0058:3014:3317) jump at 222 */
	/* 000198 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(239),      /* (ID:0081:3263:3317) Label=<Distribution_part_error> Terminal=<1> LabelId=122 */
	/* 000201 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0082:3291:3315) Send construction; if encoding, jump to 214 */
	/* 000205 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0085:3291:3295) Infinite loop start, jump to 212 */
	/* 000209 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000210 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0085:3291:3295) Loop back to 209 */
	/* 000212 */ CSN1C_GOTO(4),                           /* (ID:0082:3291:3315) skip the encode part and jump to 216 */
	/* 000214 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000216 */ CSN1C_LABEL_END, CSN1C_VAL2(239),        /* (ID:0081:3263:3317) Label=<Distribution_part_error> Terminal=<1> */
	/* 000219 */ CSN1C_GOTO(4),                           /* (ID:0058:3014:3317) jump at 224 */
	/* 000221 */ CSN1C_BACKTRACK,                         /* (ID:0058:3014:3317) Failure of choice begun at 155 */
	/* 000222 */ CSN1C_CHOICE_END,                        /* (ID:0058:3014:3317) End of choice begun at 155 */
	/* 000223 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Control_Acknowledgement_message_content'
		DEFINITION FIELD-ID: 13  COMPLEXITY: 15
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 103
	-----------------------------------------------------------------*/
	/* 000224 */ CSN1C_LABEL_A, CSN1C_VAL1(122), CSN1C_VAL1(32), /* (ID:0119:3767:3789) Label=<TLLI> LabelId=17 */
	/* 000227 */ CSN1C_LABEL_A, CSN1C_VAL1(125), CSN1C_VAL1(2), /* (ID:0123:3789:3814) Label=<CTRL_ACK> LabelId=18 */
	/* 000230 */ CSN1C_LABEL_A, CSN1C_VAL2(128), CSN1C_VAL1(4), /* (ID:0127:3814:3840) Label=<DL_CC_EST> LabelId=19 */
	/* 000234 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 241 */
	/* 000238 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000239 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 238 */
	/* 000241 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Downlink_Ack_Nack_message_content'
		DEFINITION FIELD-ID: 15  COMPLEXITY: 44
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 120
	-----------------------------------------------------------------*/
	/* 000242 */ CSN1C_LABEL_A, CSN1C_VAL2(131), CSN1C_VAL1(5), /* (ID:0152:4235:4264) Label=<DOWNLINK_TFI> LabelId=20 */
	/* 000246 */ CSN1C_LABEL_A, CSN1C_VAL2(134), CSN1C_VAL1(1), /* (ID:0156:4264:4295) Label=<MS_OUT_OF_MEMORY> LabelId=21 */
	/* 000250 */ CSN1C_CHOICE_NODE(0,14),                 /* (ID:0160:4297:4426) VBIT choice at 250, node 1, jump to 264 */
	/* 000252 */ CSN1C_BIT_0,                             /* (ID:0162:4297:4299) */
	/* 000253 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(274),      /* (ID:0163:4299:4389) Label=<EC_Ack_Nack_Description> Terminal=<0> LabelId=22 */
	/* 000256 */ CSN1C_GOSUB, CSN1C_VAL2(141),            /* (ID:0166:4327:4357) Reference to 'EC_Ack_Nack_Description_IE' */
	/* 000259 */ CSN1C_LABEL_END, CSN1C_VAL2(274),        /* (ID:0163:4299:4389) Label=<EC_Ack_Nack_Description> Terminal=<0> */
	/* 000262 */ CSN1C_GOTO(8),                           /* (ID:0160:4297:4426) jump at 270 */
	/* 000264 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0160:4297:4426) FBIT choice at 250, node 2, jump to 269 */
	/* 000266 */ CSN1C_BIT_1,                             /* (ID:0168:4391:4426) */
	/* 000267 */ CSN1C_GOTO(3),                           /* (ID:0160:4297:4426) jump at 270 */
	/* 000269 */ CSN1C_BACKTRACK,                         /* (ID:0160:4297:4426) Failure of choice begun at 250 */
	/* 000270 */ CSN1C_CHOICE_END,                        /* (ID:0160:4297:4426) End of choice begun at 250 */
	/* 000271 */ CSN1C_CHOICE_NODE(0,59),                 /* (ID:0169:4432:4537) VBIT choice at 271, node 1, jump to 330 */
	/* 000273 */ CSN1C_BIT_1,                             /* (ID:0173:4438:4440) */
	/* 000274 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(280),      /* (ID:0176:4442:4511) Label=<EC_Channel_Quality_Report> Terminal=<0> LabelId=23 */
	/* 000277 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1064:15215:15278) VBIT choice at 277, node 1, jump to 290 */
	/* 000279 */ CSN1C_BIT_1,                             /* (ID:1068:15219:15221) */
	/* 000280 */ CSN1C_LABEL_A, CSN1C_VAL2(143), CSN1C_VAL1(5), /* (ID:1069:15221:15252) Label=<GMSK_MEAN_BEP> LabelId=24 */
	/* 000284 */ CSN1C_LABEL_A, CSN1C_VAL2(148), CSN1C_VAL1(3), /* (ID:1073:15252:15278) Label=<GMSK_CV_BEP> LabelId=25 */
	/* 000288 */ CSN1C_GOTO(8),                           /* (ID:1064:15215:15278) jump at 296 */
	/* 000290 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1064:15215:15278) FBIT choice at 277, node 2, jump to 295 */
	/* 000292 */ CSN1C_BIT_0,                             /* (ID:1066:15215:15217) */
	/* 000293 */ CSN1C_GOTO(3),                           /* (ID:1064:15215:15278) jump at 296 */
	/* 000295 */ CSN1C_BACKTRACK,                         /* (ID:1064:15215:15278) Failure of choice begun at 277 */
	/* 000296 */ CSN1C_CHOICE_END,                        /* (ID:1064:15215:15278) End of choice begun at 277 */
	/* 000297 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:1077:15284:15347) VBIT choice at 297, node 1, jump to 310 */
	/* 000299 */ CSN1C_BIT_1,                             /* (ID:1081:15288:15290) */
	/* 000300 */ CSN1C_LABEL_A, CSN1C_VAL2(153), CSN1C_VAL1(5), /* (ID:1082:15290:15321) Label=<_8PSK_MEAN_BEP> LabelId=26 */
	/* 000304 */ CSN1C_LABEL_A, CSN1C_VAL2(158), CSN1C_VAL1(3), /* (ID:1086:15321:15347) Label=<_8PSK_CV_BEP> LabelId=27 */
	/* 000308 */ CSN1C_GOTO(8),                           /* (ID:1077:15284:15347) jump at 316 */
	/* 000310 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1077:15284:15347) FBIT choice at 297, node 2, jump to 315 */
	/* 000312 */ CSN1C_BIT_0,                             /* (ID:1079:15284:15286) */
	/* 000313 */ CSN1C_GOTO(3),                           /* (ID:1077:15284:15347) jump at 316 */
	/* 000315 */ CSN1C_BACKTRACK,                         /* (ID:1077:15284:15347) Failure of choice begun at 297 */
	/* 000316 */ CSN1C_CHOICE_END,                        /* (ID:1077:15284:15347) End of choice begun at 297 */
	/* 000317 */ CSN1C_LABEL_A, CSN1C_VAL2(163), CSN1C_VAL1(6), /* (ID:1090:15351:15372) Label=<C_VALUE> LabelId=28 */
	/* 000321 */ CSN1C_LABEL_END, CSN1C_VAL2(280),        /* (ID:0176:4442:4511) Label=<EC_Channel_Quality_Report> Terminal=<0> */
	/* 000324 */ CSN1C_LABEL_A, CSN1C_VAL2(168), CSN1C_VAL1(4), /* (ID:0180:4511:4535) Label=<DL_CC_EST> LabelId=29 */
	/* 000328 */ CSN1C_GOTO(8),                           /* (ID:0169:4432:4537) jump at 336 */
	/* 000330 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0169:4432:4537) FBIT choice at 271, node 2, jump to 335 */
	/* 000332 */ CSN1C_BIT_0,                             /* (ID:0171:4432:4436) */
	/* 000333 */ CSN1C_GOTO(3),                           /* (ID:0169:4432:4537) jump at 336 */
	/* 000335 */ CSN1C_BACKTRACK,                         /* (ID:0169:4432:4537) Failure of choice begun at 271 */
	/* 000336 */ CSN1C_CHOICE_END,                        /* (ID:0169:4432:4537) End of choice begun at 271 */
	/* 000337 */ CSN1C_CHOICE_NODE(0,19),                 /* (ID:0184:4543:4628) VBIT choice at 337, node 1, jump to 356 */
	/* 000339 */ CSN1C_BIT_1,                             /* (ID:0188:4547:4549) */
	/* 000340 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(342),      /* (ID:0189:4549:4628) Label=<EC_Channel_Request_Description> Terminal=<0> LabelId=30 */
	/* 000343 */ CSN1C_LABEL_A, CSN1C_VAL2(174), CSN1C_VAL1(1), /* (ID:0196:4706:4731) Label=<PRIORITY> LabelId=31 */
	/* 000347 */ CSN1C_LABEL_A, CSN1C_VAL2(179), CSN1C_VAL1(4), /* (ID:0200:4731:4769) Label=<NUMBER_OF_UL_DATA_BLOCKS> LabelId=32 */
	/* 000351 */ CSN1C_LABEL_END, CSN1C_VAL2(342),        /* (ID:0189:4549:4628) Label=<EC_Channel_Request_Description> Terminal=<0> */
	/* 000354 */ CSN1C_GOTO(8),                           /* (ID:0184:4543:4628) jump at 362 */
	/* 000356 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0184:4543:4628) FBIT choice at 337, node 2, jump to 361 */
	/* 000358 */ CSN1C_BIT_0,                             /* (ID:0186:4543:4545) */
	/* 000359 */ CSN1C_GOTO(3),                           /* (ID:0184:4543:4628) jump at 362 */
	/* 000361 */ CSN1C_BACKTRACK,                         /* (ID:0184:4543:4628) Failure of choice begun at 337 */
	/* 000362 */ CSN1C_CHOICE_END,                        /* (ID:0184:4543:4628) End of choice begun at 337 */
	/* 000363 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 370 */
	/* 000367 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000368 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 367 */
	/* 000370 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Downlink_Assignment_message_content'
		DEFINITION FIELD-ID: 17  COMPLEXITY: 129
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 143
	-----------------------------------------------------------------*/
	/* 000371 */ CSN1C_CHOICE_NODE(0,232),                /* (ID:0204:4992:6021) VBIT choice at 371, node 1, jump to 603 */
	/* 000373 */ CSN1C_LABEL_A, CSN1C_VAL2(184), CSN1C_VAL1(2), /* (ID:0206:4992:5052) Label=<USED_DL_COVERAGE_CLASS> LabelId=33 */
	/* 000377 */ CSN1C_CHOICE_NODE(0,173),                /* (ID:0210:5054:5929) VBIT choice at 377, node 1, jump to 550 */
	/* 000379 */ CSN1C_BIT_0,                             /* (ID:0212:5054:5056) */
	/* 000380 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(374),      /* (ID:0213:5056:5095) Label=<Global_TFI> Terminal=<0> LabelId=34 */
	/* 000383 */ CSN1C_GOSUB, CSN1C_VAL1(124),            /* (ID:0216:5071:5089) Reference to 'Global_TFI_IE' */
	/* 000385 */ CSN1C_LABEL_END, CSN1C_VAL2(374),        /* (ID:0213:5056:5095) Label=<Global_TFI> Terminal=<0> */
	/* 000388 */ CSN1C_CHOICE_NODE(0,135),                /* (ID:0217:5096:5806) VBIT choice at 388, node 1, jump to 523 */
	/* 000390 */ CSN1C_CHOICE_NODE(0,131),                /* (ID:0220:5098:5675) Truncable concatenation, entry 0, jump to 521 */
	/* 000392 */ CSN1C_LABEL_A, CSN1C_VAL2(190), CSN1C_VAL1(1), /* (ID:0221:5098:5129) Label=<CONTROL_ACK> LabelId=35 */
	/* 000396 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 1 */
	/* 000397 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0225:5131:5196) VBIT choice at 397, node 1, jump to 410 */
	/* 000399 */ CSN1C_BIT_1,                             /* (ID:0229:5135:5137) */
	/* 000400 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(386),      /* (ID:0230:5137:5196) Label=<Frequency_Parameters> Terminal=<0> LabelId=36 */
	/* 000403 */ CSN1C_GOSUB, CSN1C_VAL1(114),            /* (ID:0233:5162:5194) Reference to 'Frequency_Parameters_struct' */
	/* 000405 */ CSN1C_LABEL_END, CSN1C_VAL2(386),        /* (ID:0230:5137:5196) Label=<Frequency_Parameters> Terminal=<0> */
	/* 000408 */ CSN1C_GOTO(8),                           /* (ID:0225:5131:5196) jump at 416 */
	/* 000410 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0225:5131:5196) FBIT choice at 397, node 2, jump to 415 */
	/* 000412 */ CSN1C_BIT_0,                             /* (ID:0227:5131:5133) */
	/* 000413 */ CSN1C_GOTO(3),                           /* (ID:0225:5131:5196) jump at 416 */
	/* 000415 */ CSN1C_BACKTRACK,                         /* (ID:0225:5131:5196) Failure of choice begun at 397 */
	/* 000416 */ CSN1C_CHOICE_END,                        /* (ID:0225:5131:5196) End of choice begun at 397 */
	/* 000417 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 2 */
	/* 000418 */ CSN1C_LABEL_A, CSN1C_VAL2(196), CSN1C_VAL1(2), /* (ID:0234:5203:5240) Label=<DL_COVERAGE_CLASS> LabelId=37 */
	/* 000422 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 3 */
	/* 000423 */ CSN1C_LABEL_A, CSN1C_VAL2(199), CSN1C_VAL1(3), /* (ID:0238:5240:5280) Label=<STARTING_DL_TIMESLOT> LabelId=38 */
	/* 000427 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 4 */
	/* 000428 */ CSN1C_LABEL_A, CSN1C_VAL2(202), CSN1C_VAL1(3), /* (ID:0242:5280:5322) Label=<TIMESLOT_MULTIPLICATOR> LabelId=39 */
	/* 000432 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 5 */
	/* 000433 */ CSN1C_LABEL_A, CSN1C_VAL2(205), CSN1C_VAL1(5), /* (ID:0246:5322:5365) Label=<DOWNLINK_TFI_ASSIGNMENT> LabelId=40 */
	/* 000437 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 6 */
	/* 000438 */ CSN1C_LABEL_A, CSN1C_VAL2(208), CSN1C_VAL1(2), /* (ID:0250:5365:5402) Label=<UL_COVERAGE_CLASS> LabelId=41 */
	/* 000442 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 7 */
	/* 000443 */ CSN1C_LABEL_A, CSN1C_VAL2(211), CSN1C_VAL1(2), /* (ID:0254:5402:5449) Label=<STARTING_UL_TIMESLOT_OFFSET> LabelId=42 */
	/* 000447 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 8 */
	/* 000448 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0258:5451:5520) VBIT choice at 448, node 1, jump to 463 */
	/* 000450 */ CSN1C_BIT_1,                             /* (ID:0262:5455:5457) */
	/* 000451 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(428),      /* (ID:0263:5457:5520) Label=<EC_Packet_Timing_Advance> Terminal=<0> LabelId=43 */
	/* 000454 */ CSN1C_LABEL_A, CSN1C_VAL2(217), CSN1C_VAL1(6), /* (ID:1058:14975:15009) Label=<TIMING_ADVANCE_VALUE> LabelId=44 */
	/* 000458 */ CSN1C_LABEL_END, CSN1C_VAL2(428),        /* (ID:0263:5457:5520) Label=<EC_Packet_Timing_Advance> Terminal=<0> */
	/* 000461 */ CSN1C_GOTO(8),                           /* (ID:0258:5451:5520) jump at 469 */
	/* 000463 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0258:5451:5520) FBIT choice at 448, node 2, jump to 468 */
	/* 000465 */ CSN1C_BIT_0,                             /* (ID:0260:5451:5453) */
	/* 000466 */ CSN1C_GOTO(3),                           /* (ID:0258:5451:5520) jump at 469 */
	/* 000468 */ CSN1C_BACKTRACK,                         /* (ID:0258:5451:5520) Failure of choice begun at 448 */
	/* 000469 */ CSN1C_CHOICE_END,                        /* (ID:0258:5451:5520) End of choice begun at 448 */
	/* 000470 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 9 */
	/* 000471 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0267:5529:5581) VBIT choice at 471, node 1, jump to 484 */
	/* 000473 */ CSN1C_BIT_1,                             /* (ID:0271:5533:5535) */
	/* 000474 */ CSN1C_LABEL_A, CSN1C_VAL2(228), CSN1C_VAL1(4), /* (ID:0272:5535:5559) Label=<P0> LabelId=45 */
	/* 000478 */ CSN1C_LABEL_A, CSN1C_VAL2(231), CSN1C_VAL1(1), /* (ID:0276:5559:5581) Label=<PR_MODE> LabelId=46 */
	/* 000482 */ CSN1C_GOTO(8),                           /* (ID:0267:5529:5581) jump at 490 */
	/* 000484 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0267:5529:5581) FBIT choice at 471, node 2, jump to 489 */
	/* 000486 */ CSN1C_BIT_0,                             /* (ID:0269:5529:5531) */
	/* 000487 */ CSN1C_GOTO(3),                           /* (ID:0267:5529:5581) jump at 490 */
	/* 000489 */ CSN1C_BACKTRACK,                         /* (ID:0267:5529:5581) Failure of choice begun at 471 */
	/* 000490 */ CSN1C_CHOICE_END,                        /* (ID:0267:5529:5581) End of choice begun at 471 */
	/* 000491 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 10 */
	/* 000492 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0280:5590:5650) VBIT choice at 492, node 1, jump to 505 */
	/* 000494 */ CSN1C_BIT_1,                             /* (ID:0284:5594:5596) */
	/* 000495 */ CSN1C_LABEL_A, CSN1C_VAL2(234), CSN1C_VAL1(5), /* (ID:0285:5596:5623) Label=<GAMMA> LabelId=47 */
	/* 000499 */ CSN1C_LABEL_A, CSN1C_VAL2(237), CSN1C_VAL1(1), /* (ID:0289:5623:5650) Label=<ALPHA_Enable> LabelId=48 */
	/* 000503 */ CSN1C_GOTO(8),                           /* (ID:0280:5590:5650) jump at 511 */
	/* 000505 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0280:5590:5650) FBIT choice at 492, node 2, jump to 510 */
	/* 000507 */ CSN1C_BIT_0,                             /* (ID:0282:5590:5592) */
	/* 000508 */ CSN1C_GOTO(3),                           /* (ID:0280:5590:5650) jump at 511 */
	/* 000510 */ CSN1C_BACKTRACK,                         /* (ID:0280:5590:5650) Failure of choice begun at 492 */
	/* 000511 */ CSN1C_CHOICE_END,                        /* (ID:0280:5590:5650) End of choice begun at 492 */
	/* 000512 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0220:5098:5675) Truncable concatenation, entry 11 */
	/* 000513 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 520 */
	/* 000517 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000518 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 517 */
	/* 000520 */ CSN1C_CHOICE_END,
	/* 000521 */ CSN1C_GOTO(26),                          /* (ID:0217:5096:5806) jump at 547 */
	/* 000523 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(481),      /* (ID:0295:5748:5806) Label=<Non_distribution_part_error> Terminal=<1> LabelId=123 */
	/* 000526 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0296:5780:5804) Send construction; if encoding, jump to 539 */
	/* 000530 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0299:5780:5784) Infinite loop start, jump to 537 */
	/* 000534 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000535 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0299:5780:5784) Loop back to 534 */
	/* 000537 */ CSN1C_GOTO(4),                           /* (ID:0296:5780:5804) skip the encode part and jump to 541 */
	/* 000539 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000541 */ CSN1C_LABEL_END, CSN1C_VAL2(481),        /* (ID:0295:5748:5806) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 000544 */ CSN1C_GOTO(4),                           /* (ID:0217:5096:5806) jump at 549 */
	/* 000546 */ CSN1C_BACKTRACK,                         /* (ID:0217:5096:5806) Failure of choice begun at 388 */
	/* 000547 */ CSN1C_CHOICE_END,                        /* (ID:0217:5096:5806) End of choice begun at 388 */
	/* 000548 */ CSN1C_GOTO(52),                          /* (ID:0210:5054:5929) jump at 600 */
	/* 000550 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:0210:5054:5929) VBIT choice at 377, node 2, jump to 575 */
	/* 000552 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(487),      /* (ID:0304:5814:5878) Label=<Address_information_part_error> Terminal=<1> LabelId=124 */
	/* 000555 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0305:5849:5873) Send construction; if encoding, jump to 568 */
	/* 000559 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0308:5849:5853) Infinite loop start, jump to 566 */
	/* 000563 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000564 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0308:5849:5853) Loop back to 563 */
	/* 000566 */ CSN1C_GOTO(4),                           /* (ID:0305:5849:5873) skip the encode part and jump to 570 */
	/* 000568 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000570 */ CSN1C_LABEL_END, CSN1C_VAL2(487),        /* (ID:0304:5814:5878) Label=<Address_information_part_error> Terminal=<1> */
	/* 000573 */ CSN1C_GOTO(27),                          /* (ID:0210:5054:5929) jump at 600 */
	/* 000575 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(493),      /* (ID:0313:5880:5929) Label=<Message_escape> Terminal=<1> LabelId=125 */
	/* 000578 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(14),  /* (ID:0314:5899:5927) Send construction; if encoding, jump to 592 */
	/* 000582 */ CSN1C_BIT_1,                             /* (ID:0319:5901:5903) */
	/* 000583 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0320:5905:5909) Infinite loop start, jump to 590 */
	/* 000587 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000588 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0320:5905:5909) Loop back to 587 */
	/* 000590 */ CSN1C_GOTO(4),                           /* (ID:0314:5899:5927) skip the encode part and jump to 594 */
	/* 000592 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000594 */ CSN1C_LABEL_END, CSN1C_VAL2(493),        /* (ID:0313:5880:5929) Label=<Message_escape> Terminal=<1> */
	/* 000597 */ CSN1C_GOTO(4),                           /* (ID:0210:5054:5929) jump at 602 */
	/* 000599 */ CSN1C_BACKTRACK,                         /* (ID:0210:5054:5929) Failure of choice begun at 377 */
	/* 000600 */ CSN1C_CHOICE_END,                        /* (ID:0210:5054:5929) End of choice begun at 377 */
	/* 000601 */ CSN1C_GOTO(26),                          /* (ID:0204:4992:6021) jump at 627 */
	/* 000603 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(499),      /* (ID:0325:5967:6021) Label=<Distribution_part_error> Terminal=<1> LabelId=126 */
	/* 000606 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0326:5995:6019) Send construction; if encoding, jump to 619 */
	/* 000610 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0329:5995:5999) Infinite loop start, jump to 617 */
	/* 000614 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000615 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0329:5995:5999) Loop back to 614 */
	/* 000617 */ CSN1C_GOTO(4),                           /* (ID:0326:5995:6019) skip the encode part and jump to 621 */
	/* 000619 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000621 */ CSN1C_LABEL_END, CSN1C_VAL2(499),        /* (ID:0325:5967:6021) Label=<Distribution_part_error> Terminal=<1> */
	/* 000624 */ CSN1C_GOTO(4),                           /* (ID:0204:4992:6021) jump at 629 */
	/* 000626 */ CSN1C_BACKTRACK,                         /* (ID:0204:4992:6021) Failure of choice begun at 371 */
	/* 000627 */ CSN1C_CHOICE_END,                        /* (ID:0204:4992:6021) End of choice begun at 371 */
	/* 000628 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Downlink_Dummy_Control_Block_message_content'
		DEFINITION FIELD-ID: 19  COMPLEXITY: 16
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 180
	-----------------------------------------------------------------*/
	/* 000629 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0347:6392:6527) VBIT choice at 629, node 1, jump to 644 */
	/* 000631 */ CSN1C_LABEL_A, CSN1C_VAL2(252), CSN1C_VAL1(2), /* (ID:0349:6392:6452) Label=<USED_DL_COVERAGE_CLASS> LabelId=49 */
	/* 000635 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 642 */
	/* 000639 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000640 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 639 */
	/* 000642 */ CSN1C_GOTO(26),                          /* (ID:0347:6392:6527) jump at 668 */
	/* 000644 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(511),      /* (ID:0355:6473:6527) Label=<Distribution_part_error> Terminal=<1> LabelId=127 */
	/* 000647 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0356:6501:6525) Send construction; if encoding, jump to 660 */
	/* 000651 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0359:6501:6505) Infinite loop start, jump to 658 */
	/* 000655 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000656 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0359:6501:6505) Loop back to 655 */
	/* 000658 */ CSN1C_GOTO(4),                           /* (ID:0356:6501:6525) skip the encode part and jump to 662 */
	/* 000660 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000662 */ CSN1C_LABEL_END, CSN1C_VAL2(511),        /* (ID:0355:6473:6527) Label=<Distribution_part_error> Terminal=<1> */
	/* 000665 */ CSN1C_GOTO(4),                           /* (ID:0347:6392:6527) jump at 670 */
	/* 000667 */ CSN1C_BACKTRACK,                         /* (ID:0347:6392:6527) Failure of choice begun at 629 */
	/* 000668 */ CSN1C_CHOICE_END,                        /* (ID:0347:6392:6527) End of choice begun at 629 */
	/* 000669 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Polling_Request_message_content'
		DEFINITION FIELD-ID: 20  COMPLEXITY: 59
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 192
	-----------------------------------------------------------------*/
	/* 000670 */ CSN1C_CHOICE_NODE(0,112),                /* (ID:0363:6742:7175) VBIT choice at 670, node 1, jump to 782 */
	/* 000672 */ CSN1C_LABEL_A, CSN1C_VAL2(258), CSN1C_VAL1(2), /* (ID:0365:6742:6802) Label=<USED_DL_COVERAGE_CLASS> LabelId=50 */
	/* 000676 */ CSN1C_CHOICE_NODE(0,53),                 /* (ID:0369:6804:7083) VBIT choice at 676, node 1, jump to 729 */
	/* 000678 */ CSN1C_BIT_0,                             /* (ID:0371:6804:6806) */
	/* 000679 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(522),      /* (ID:0372:6806:6845) Label=<Global_TFI> Terminal=<0> LabelId=51 */
	/* 000682 */ CSN1C_GOSUB, CSN1C_VAL1(124),            /* (ID:0375:6821:6839) Reference to 'Global_TFI_IE' */
	/* 000684 */ CSN1C_LABEL_END, CSN1C_VAL2(522),        /* (ID:0372:6806:6845) Label=<Global_TFI> Terminal=<0> */
	/* 000687 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0376:6847:6960) VBIT choice at 687, node 1, jump to 702 */
	/* 000689 */ CSN1C_LABEL_A, CSN1C_VAL2(264), CSN1C_VAL1(1), /* (ID:0378:6847:6878) Label=<TYPE_OF_ACK> LabelId=52 */
	/* 000693 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 700 */
	/* 000697 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000698 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 697 */
	/* 000700 */ CSN1C_GOTO(26),                          /* (ID:0376:6847:6960) jump at 726 */
	/* 000702 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(535),      /* (ID:0384:6902:6960) Label=<Non_distribution_part_error> Terminal=<1> LabelId=128 */
	/* 000705 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0385:6934:6958) Send construction; if encoding, jump to 718 */
	/* 000709 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0388:6934:6938) Infinite loop start, jump to 716 */
	/* 000713 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000714 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0388:6934:6938) Loop back to 713 */
	/* 000716 */ CSN1C_GOTO(4),                           /* (ID:0385:6934:6958) skip the encode part and jump to 720 */
	/* 000718 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000720 */ CSN1C_LABEL_END, CSN1C_VAL2(535),        /* (ID:0384:6902:6960) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 000723 */ CSN1C_GOTO(4),                           /* (ID:0376:6847:6960) jump at 728 */
	/* 000725 */ CSN1C_BACKTRACK,                         /* (ID:0376:6847:6960) Failure of choice begun at 687 */
	/* 000726 */ CSN1C_CHOICE_END,                        /* (ID:0376:6847:6960) End of choice begun at 687 */
	/* 000727 */ CSN1C_GOTO(52),                          /* (ID:0369:6804:7083) jump at 779 */
	/* 000729 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:0369:6804:7083) VBIT choice at 676, node 2, jump to 754 */
	/* 000731 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(541),      /* (ID:0393:6968:7032) Label=<Address_information_part_error> Terminal=<1> LabelId=129 */
	/* 000734 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0394:7003:7027) Send construction; if encoding, jump to 747 */
	/* 000738 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0397:7003:7007) Infinite loop start, jump to 745 */
	/* 000742 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000743 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0397:7003:7007) Loop back to 742 */
	/* 000745 */ CSN1C_GOTO(4),                           /* (ID:0394:7003:7027) skip the encode part and jump to 749 */
	/* 000747 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000749 */ CSN1C_LABEL_END, CSN1C_VAL2(541),        /* (ID:0393:6968:7032) Label=<Address_information_part_error> Terminal=<1> */
	/* 000752 */ CSN1C_GOTO(27),                          /* (ID:0369:6804:7083) jump at 779 */
	/* 000754 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(547),      /* (ID:0402:7034:7083) Label=<Message_escape> Terminal=<1> LabelId=130 */
	/* 000757 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(14),  /* (ID:0403:7053:7081) Send construction; if encoding, jump to 771 */
	/* 000761 */ CSN1C_BIT_1,                             /* (ID:0408:7055:7057) */
	/* 000762 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0409:7059:7063) Infinite loop start, jump to 769 */
	/* 000766 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000767 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0409:7059:7063) Loop back to 766 */
	/* 000769 */ CSN1C_GOTO(4),                           /* (ID:0403:7053:7081) skip the encode part and jump to 773 */
	/* 000771 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000773 */ CSN1C_LABEL_END, CSN1C_VAL2(547),        /* (ID:0402:7034:7083) Label=<Message_escape> Terminal=<1> */
	/* 000776 */ CSN1C_GOTO(4),                           /* (ID:0369:6804:7083) jump at 781 */
	/* 000778 */ CSN1C_BACKTRACK,                         /* (ID:0369:6804:7083) Failure of choice begun at 676 */
	/* 000779 */ CSN1C_CHOICE_END,                        /* (ID:0369:6804:7083) End of choice begun at 676 */
	/* 000780 */ CSN1C_GOTO(26),                          /* (ID:0363:6742:7175) jump at 806 */
	/* 000782 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(553),      /* (ID:0414:7121:7175) Label=<Distribution_part_error> Terminal=<1> LabelId=131 */
	/* 000785 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0415:7149:7173) Send construction; if encoding, jump to 798 */
	/* 000789 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0418:7149:7153) Infinite loop start, jump to 796 */
	/* 000793 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000794 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0418:7149:7153) Loop back to 793 */
	/* 000796 */ CSN1C_GOTO(4),                           /* (ID:0415:7149:7173) skip the encode part and jump to 800 */
	/* 000798 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000800 */ CSN1C_LABEL_END, CSN1C_VAL2(553),        /* (ID:0414:7121:7175) Label=<Distribution_part_error> Terminal=<1> */
	/* 000803 */ CSN1C_GOTO(4),                           /* (ID:0363:6742:7175) jump at 808 */
	/* 000805 */ CSN1C_BACKTRACK,                         /* (ID:0363:6742:7175) Failure of choice begun at 670 */
	/* 000806 */ CSN1C_CHOICE_END,                        /* (ID:0363:6742:7175) End of choice begun at 670 */
	/* 000807 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Power_Control_Timing_Advance_message_content'
		DEFINITION FIELD-ID: 21  COMPLEXITY: 69
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 209
	-----------------------------------------------------------------*/
	/* 000808 */ CSN1C_CHOICE_NODE(0,135),                /* (ID:0422:7416:7873) VBIT choice at 808, node 1, jump to 943 */
	/* 000810 */ CSN1C_LABEL_A, CSN1C_VAL2(279), CSN1C_VAL1(2), /* (ID:0424:7416:7476) Label=<USED_DL_COVERAGE_CLASS> LabelId=53 */
	/* 000814 */ CSN1C_CHOICE_NODE(0,102),                /* (ID:0428:7478:7813) VBIT choice at 814, node 1, jump to 916 */
	/* 000816 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(564),      /* (ID:0430:7478:7516) Label=<Global_TFI> Terminal=<0> LabelId=54 */
	/* 000819 */ CSN1C_GOSUB, CSN1C_VAL1(124),            /* (ID:0433:7493:7511) Reference to 'Global_TFI_IE' */
	/* 000821 */ CSN1C_LABEL_END, CSN1C_VAL2(564),        /* (ID:0430:7478:7516) Label=<Global_TFI> Terminal=<0> */
	/* 000824 */ CSN1C_CHOICE_NODE(0,65),                 /* (ID:0434:7518:7745) VBIT choice at 824, node 1, jump to 889 */
	/* 000826 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0436:7520:7548) VBIT choice at 826, node 1, jump to 835 */
	/* 000828 */ CSN1C_BIT_1,                             /* (ID:0440:7524:7526) */
	/* 000829 */ CSN1C_LABEL_A, CSN1C_VAL2(285), CSN1C_VAL1(5), /* (ID:0441:7526:7548) Label=<T_AVG_T> LabelId=55 */
	/* 000833 */ CSN1C_GOTO(8),                           /* (ID:0436:7520:7548) jump at 841 */
	/* 000835 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0436:7520:7548) FBIT choice at 826, node 2, jump to 840 */
	/* 000837 */ CSN1C_BIT_0,                             /* (ID:0438:7520:7522) */
	/* 000838 */ CSN1C_GOTO(3),                           /* (ID:0436:7520:7548) jump at 841 */
	/* 000840 */ CSN1C_BACKTRACK,                         /* (ID:0436:7520:7548) Failure of choice begun at 826 */
	/* 000841 */ CSN1C_CHOICE_END,                        /* (ID:0436:7520:7548) End of choice begun at 826 */
	/* 000842 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0445:7556:7624) VBIT choice at 842, node 1, jump to 857 */
	/* 000844 */ CSN1C_BIT_1,                             /* (ID:0449:7560:7562) */
	/* 000845 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(576),      /* (ID:0450:7562:7624) Label=<EC_Packet_Timing_Advance> Terminal=<0> LabelId=56 */
	/* 000848 */ CSN1C_LABEL_A, CSN1C_VAL2(291), CSN1C_VAL1(6), /* (ID:1058:14975:15009) Label=<TIMING_ADVANCE_VALUE> LabelId=44 */
	/* 000852 */ CSN1C_LABEL_END, CSN1C_VAL2(576),        /* (ID:0450:7562:7624) Label=<EC_Packet_Timing_Advance> Terminal=<0> */
	/* 000855 */ CSN1C_GOTO(8),                           /* (ID:0445:7556:7624) jump at 863 */
	/* 000857 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0445:7556:7624) FBIT choice at 842, node 2, jump to 862 */
	/* 000859 */ CSN1C_BIT_0,                             /* (ID:0447:7556:7558) */
	/* 000860 */ CSN1C_GOTO(3),                           /* (ID:0445:7556:7624) jump at 863 */
	/* 000862 */ CSN1C_BACKTRACK,                         /* (ID:0445:7556:7624) Failure of choice begun at 842 */
	/* 000863 */ CSN1C_CHOICE_END,                        /* (ID:0445:7556:7624) End of choice begun at 842 */
	/* 000864 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0454:7632:7658) VBIT choice at 864, node 1, jump to 873 */
	/* 000866 */ CSN1C_BIT_1,                             /* (ID:0458:7636:7638) */
	/* 000867 */ CSN1C_LABEL_A, CSN1C_VAL2(302), CSN1C_VAL1(5), /* (ID:0459:7638:7658) Label=<GAMMA> LabelId=57 */
	/* 000871 */ CSN1C_GOTO(8),                           /* (ID:0454:7632:7658) jump at 879 */
	/* 000873 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0454:7632:7658) FBIT choice at 864, node 2, jump to 878 */
	/* 000875 */ CSN1C_BIT_0,                             /* (ID:0456:7632:7634) */
	/* 000876 */ CSN1C_GOTO(3),                           /* (ID:0454:7632:7658) jump at 879 */
	/* 000878 */ CSN1C_BACKTRACK,                         /* (ID:0454:7632:7658) Failure of choice begun at 864 */
	/* 000879 */ CSN1C_CHOICE_END,                        /* (ID:0454:7632:7658) End of choice begun at 864 */
	/* 000880 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 887 */
	/* 000884 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000885 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 884 */
	/* 000887 */ CSN1C_GOTO(26),                          /* (ID:0434:7518:7745) jump at 913 */
	/* 000889 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(611),      /* (ID:0465:7687:7745) Label=<Non_distribution_part_error> Terminal=<1> LabelId=132 */
	/* 000892 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0466:7719:7743) Send construction; if encoding, jump to 905 */
	/* 000896 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0469:7719:7723) Infinite loop start, jump to 903 */
	/* 000900 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000901 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0469:7719:7723) Loop back to 900 */
	/* 000903 */ CSN1C_GOTO(4),                           /* (ID:0466:7719:7743) skip the encode part and jump to 907 */
	/* 000905 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000907 */ CSN1C_LABEL_END, CSN1C_VAL2(611),        /* (ID:0465:7687:7745) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 000910 */ CSN1C_GOTO(4),                           /* (ID:0434:7518:7745) jump at 915 */
	/* 000912 */ CSN1C_BACKTRACK,                         /* (ID:0434:7518:7745) Failure of choice begun at 824 */
	/* 000913 */ CSN1C_CHOICE_END,                        /* (ID:0434:7518:7745) End of choice begun at 824 */
	/* 000914 */ CSN1C_GOTO(26),                          /* (ID:0428:7478:7813) jump at 940 */
	/* 000916 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(617),      /* (ID:0474:7752:7813) Label=<Address_information_part_error> Terminal=<1> LabelId=133 */
	/* 000919 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0475:7787:7811) Send construction; if encoding, jump to 932 */
	/* 000923 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0478:7787:7791) Infinite loop start, jump to 930 */
	/* 000927 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000928 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0478:7787:7791) Loop back to 927 */
	/* 000930 */ CSN1C_GOTO(4),                           /* (ID:0475:7787:7811) skip the encode part and jump to 934 */
	/* 000932 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000934 */ CSN1C_LABEL_END, CSN1C_VAL2(617),        /* (ID:0474:7752:7813) Label=<Address_information_part_error> Terminal=<1> */
	/* 000937 */ CSN1C_GOTO(4),                           /* (ID:0428:7478:7813) jump at 942 */
	/* 000939 */ CSN1C_BACKTRACK,                         /* (ID:0428:7478:7813) Failure of choice begun at 814 */
	/* 000940 */ CSN1C_CHOICE_END,                        /* (ID:0428:7478:7813) End of choice begun at 814 */
	/* 000941 */ CSN1C_GOTO(26),                          /* (ID:0422:7416:7873) jump at 967 */
	/* 000943 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(623),      /* (ID:0483:7819:7873) Label=<Distribution_part_error> Terminal=<1> LabelId=134 */
	/* 000946 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0484:7847:7871) Send construction; if encoding, jump to 959 */
	/* 000950 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0487:7847:7851) Infinite loop start, jump to 957 */
	/* 000954 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 000955 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0487:7847:7851) Loop back to 954 */
	/* 000957 */ CSN1C_GOTO(4),                           /* (ID:0484:7847:7871) skip the encode part and jump to 961 */
	/* 000959 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 000961 */ CSN1C_LABEL_END, CSN1C_VAL2(623),        /* (ID:0483:7819:7873) Label=<Distribution_part_error> Terminal=<1> */
	/* 000964 */ CSN1C_GOTO(4),                           /* (ID:0422:7416:7873) jump at 969 */
	/* 000966 */ CSN1C_BACKTRACK,                         /* (ID:0422:7416:7873) Failure of choice begun at 808 */
	/* 000967 */ CSN1C_CHOICE_END,                        /* (ID:0422:7416:7873) End of choice begun at 808 */
	/* 000968 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_TBF_Release_message_content'
		DEFINITION FIELD-ID: 22  COMPLEXITY: 74
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 227
	-----------------------------------------------------------------*/
	/* 000969 */ CSN1C_CHOICE_NODE(0,129),                /* (ID:0491:8080:8529) VBIT choice at 969, node 1, jump to 1098 */
	/* 000971 */ CSN1C_LABEL_A, CSN1C_VAL2(314), CSN1C_VAL1(2), /* (ID:0493:8080:8140) Label=<USED_DL_COVERAGE_CLASS> LabelId=58 */
	/* 000975 */ CSN1C_CHOICE_NODE(0,96),                 /* (ID:0497:8142:8469) VBIT choice at 975, node 1, jump to 1071 */
	/* 000977 */ CSN1C_BIT_0,                             /* (ID:0499:8142:8144) */
	/* 000978 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(634),      /* (ID:0500:8144:8178) Label=<GLOBAL_TFI> Terminal=<0> LabelId=59 */
	/* 000981 */ CSN1C_GOSUB, CSN1C_VAL1(124),            /* (ID:0503:8159:8173) Reference to 'Global_TFI_IE' */
	/* 000983 */ CSN1C_LABEL_END, CSN1C_VAL2(634),        /* (ID:0500:8144:8178) Label=<GLOBAL_TFI> Terminal=<0> */
	/* 000986 */ CSN1C_CHOICE_NODE(0,58),                 /* (ID:0504:8180:8401) VBIT choice at 986, node 1, jump to 1044 */
	/* 000988 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(641),      /* (ID:0506:8180:8234) Label=<TBF_RELEASE_CAUSE> Terminal=<1> LabelId=60 */
	/* 000991 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(7),   /* (ID:0507:8202:8228) Send construction; if encoding, jump to 998 */
	/* 000995 */ CSN1C_BIT_A(4),                          /* (ID:0002:535:536) */
	/* 000996 */ CSN1C_GOTO(16),                          /* (ID:0507:8202:8228) skip the encode part and jump to 1012 */
	/* 000998 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0513:8214:8226) FBIT choice at 998, node 1, jump to 1004 */
	/* 001000 */ CSN1C_VALUE, CSN1C_VAL1(3),              /* (ID:0515:8214:8215..0518:8217:8219) Bit string '0000' */
	/* 001002 */ CSN1C_GOTO(9),                           /* (ID:0513:8214:8226) jump at 1011 */
	/* 001004 */ CSN1C_CHOICE_NODE(1,6),                  /* (ID:0513:8214:8226) FBIT choice at 998, node 2, jump to 1010 */
	/* 001006 */ CSN1C_VALUE, CSN1C_VAL1(35),             /* (ID:0520:8221:8222..0523:8224:8226) Bit string '0010' */
	/* 001008 */ CSN1C_GOTO(3),                           /* (ID:0513:8214:8226) jump at 1011 */
	/* 001010 */ CSN1C_BACKTRACK,                         /* (ID:0513:8214:8226) Failure of choice begun at 998 */
	/* 001011 */ CSN1C_CHOICE_END,                        /* (ID:0513:8214:8226) End of choice begun at 998 */
	/* 001012 */ CSN1C_LABEL_END, CSN1C_VAL2(641),        /* (ID:0506:8180:8234) Label=<TBF_RELEASE_CAUSE> Terminal=<1> */
	/* 001015 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0524:8236:8314) VBIT choice at 1015, node 1, jump to 1028 */
	/* 001017 */ CSN1C_BIT_1,                             /* (ID:0528:8240:8242) */
	/* 001018 */ CSN1C_LABEL_A, CSN1C_VAL2(323), CSN1C_VAL1(8), /* (ID:0529:8242:8278) Label=<WAIT_INDICATION> LabelId=61 */
	/* 001022 */ CSN1C_LABEL_A, CSN1C_VAL2(326), CSN1C_VAL1(1), /* (ID:0533:8278:8314) Label=<WAIT__INDICATION_SIZE> LabelId=62 */
	/* 001026 */ CSN1C_GOTO(8),                           /* (ID:0524:8236:8314) jump at 1034 */
	/* 001028 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0524:8236:8314) FBIT choice at 1015, node 2, jump to 1033 */
	/* 001030 */ CSN1C_BIT_0,                             /* (ID:0526:8236:8238) */
	/* 001031 */ CSN1C_GOTO(3),                           /* (ID:0524:8236:8314) jump at 1034 */
	/* 001033 */ CSN1C_BACKTRACK,                         /* (ID:0524:8236:8314) Failure of choice begun at 1015 */
	/* 001034 */ CSN1C_CHOICE_END,                        /* (ID:0524:8236:8314) End of choice begun at 1015 */
	/* 001035 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 1042 */
	/* 001039 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001040 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 1039 */
	/* 001042 */ CSN1C_GOTO(26),                          /* (ID:0504:8180:8401) jump at 1068 */
	/* 001044 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(659),      /* (ID:0539:8343:8401) Label=<Non_distribution_part_error> Terminal=<1> LabelId=135 */
	/* 001047 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0540:8375:8399) Send construction; if encoding, jump to 1060 */
	/* 001051 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0543:8375:8379) Infinite loop start, jump to 1058 */
	/* 001055 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001056 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0543:8375:8379) Loop back to 1055 */
	/* 001058 */ CSN1C_GOTO(4),                           /* (ID:0540:8375:8399) skip the encode part and jump to 1062 */
	/* 001060 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001062 */ CSN1C_LABEL_END, CSN1C_VAL2(659),        /* (ID:0539:8343:8401) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 001065 */ CSN1C_GOTO(4),                           /* (ID:0504:8180:8401) jump at 1070 */
	/* 001067 */ CSN1C_BACKTRACK,                         /* (ID:0504:8180:8401) Failure of choice begun at 986 */
	/* 001068 */ CSN1C_CHOICE_END,                        /* (ID:0504:8180:8401) End of choice begun at 986 */
	/* 001069 */ CSN1C_GOTO(26),                          /* (ID:0497:8142:8469) jump at 1095 */
	/* 001071 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(665),      /* (ID:0548:8408:8469) Label=<Address_information_part_error> Terminal=<1> LabelId=136 */
	/* 001074 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0549:8443:8467) Send construction; if encoding, jump to 1087 */
	/* 001078 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0552:8443:8447) Infinite loop start, jump to 1085 */
	/* 001082 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001083 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0552:8443:8447) Loop back to 1082 */
	/* 001085 */ CSN1C_GOTO(4),                           /* (ID:0549:8443:8467) skip the encode part and jump to 1089 */
	/* 001087 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001089 */ CSN1C_LABEL_END, CSN1C_VAL2(665),        /* (ID:0548:8408:8469) Label=<Address_information_part_error> Terminal=<1> */
	/* 001092 */ CSN1C_GOTO(4),                           /* (ID:0497:8142:8469) jump at 1097 */
	/* 001094 */ CSN1C_BACKTRACK,                         /* (ID:0497:8142:8469) Failure of choice begun at 975 */
	/* 001095 */ CSN1C_CHOICE_END,                        /* (ID:0497:8142:8469) End of choice begun at 975 */
	/* 001096 */ CSN1C_GOTO(26),                          /* (ID:0491:8080:8529) jump at 1122 */
	/* 001098 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(671),      /* (ID:0557:8475:8529) Label=<Distribution_part_error> Terminal=<1> LabelId=137 */
	/* 001101 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0558:8503:8527) Send construction; if encoding, jump to 1114 */
	/* 001105 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0561:8503:8507) Infinite loop start, jump to 1112 */
	/* 001109 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001110 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0561:8503:8507) Loop back to 1109 */
	/* 001112 */ CSN1C_GOTO(4),                           /* (ID:0558:8503:8527) skip the encode part and jump to 1116 */
	/* 001114 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001116 */ CSN1C_LABEL_END, CSN1C_VAL2(671),        /* (ID:0557:8475:8529) Label=<Distribution_part_error> Terminal=<1> */
	/* 001119 */ CSN1C_GOTO(4),                           /* (ID:0491:8080:8529) jump at 1124 */
	/* 001121 */ CSN1C_BACKTRACK,                         /* (ID:0491:8080:8529) Failure of choice begun at 969 */
	/* 001122 */ CSN1C_CHOICE_END,                        /* (ID:0491:8080:8529) End of choice begun at 969 */
	/* 001123 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content'
		DEFINITION FIELD-ID: 27  COMPLEXITY: 60
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 333
	-----------------------------------------------------------------*/
	/* 001124 */ CSN1C_CHOICE_NODE(0,128),                /* (ID:0938:12900:13436) VBIT choice at 1124, node 1, jump to 1252 */
	/* 001126 */ CSN1C_LABEL_A, CSN1C_VAL2(338), CSN1C_VAL1(2), /* (ID:0940:12900:12960) Label=<USED_DL_COVERAGE_CLASS> LabelId=63 */
	/* 001130 */ CSN1C_CHOICE_NODE(0,95),                 /* (ID:0944:12962:13378) VBIT choice at 1130, node 1, jump to 1225 */
	/* 001132 */ CSN1C_CHOICE_NODE(0,66),                 /* (ID:0946:12964:13312) VBIT choice at 1132, node 1, jump to 1198 */
	/* 001134 */ CSN1C_LABEL_A, CSN1C_VAL2(341), CSN1C_VAL1(5), /* (ID:0948:12964:12992) Label=<UPLINK_TFI> LabelId=64 */
	/* 001138 */ CSN1C_LABEL_A, CSN1C_VAL2(344), CSN1C_VAL1(32), /* (ID:0954:12994:13040) Label=<CONTENTION_RESOLUTION_TLLI> LabelId=65 */
	/* 001142 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(694),      /* (ID:0958:13040:13120) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> LabelId=66 */
	/* 001145 */ CSN1C_GOSUB, CSN1C_VAL2(148),            /* (ID:0961:13076:13114) Reference to 'EC_Primary_Ack_Nack_Description_IE' */
	/* 001148 */ CSN1C_LABEL_END, CSN1C_VAL2(694),        /* (ID:0958:13040:13120) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> */
	/* 001151 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(700),      /* (ID:0962:13120:13203) Label=<PUANCR_Fixed_Uplink_Allocation> Terminal=<0> LabelId=67 */
	/* 001154 */ CSN1C_LABEL_A, CSN1C_VAL2(353), CSN1C_VAL1(4), /* (ID:1000:13496:13542) Label=<START_FIRST_UL_RLC_DATA_BLOCK> LabelId=68 */
	/* 001158 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(46), /* (ID:1004:13544:13746) Infinite loop start, jump to 1181 */
	/* 001162 */ CSN1C_BIT_1,                             /* (ID:1007:13544:13546) */
	/* 001163 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:1008:13548:13744) VBIT choice at 1163, node 1, jump to 1172 */
	/* 001165 */ CSN1C_BIT_1,                             /* (ID:1012:13649:13651) */
	/* 001166 */ CSN1C_LABEL_A, CSN1C_VAL2(358), CSN1C_VAL1(3), /* (ID:1013:13651:13744) Label=<DELAY_NEXT_UL_RLC_DATA_BLOCK> LabelId=69 */
	/* 001170 */ CSN1C_GOTO(8),                           /* (ID:1008:13548:13744) jump at 1178 */
	/* 001172 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:1008:13548:13744) FBIT choice at 1163, node 2, jump to 1177 */
	/* 001174 */ CSN1C_BIT_0,                             /* (ID:1010:13548:13647) */
	/* 001175 */ CSN1C_GOTO(3),                           /* (ID:1008:13548:13744) jump at 1178 */
	/* 001177 */ CSN1C_BACKTRACK,                         /* (ID:1008:13548:13744) Failure of choice begun at 1163 */
	/* 001178 */ CSN1C_CHOICE_END,                        /* (ID:1008:13548:13744) End of choice begun at 1163 */
	/* 001179 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(17),        /* (ID:1004:13544:13746) Loop back to 1162 */
	/* 001181 */ CSN1C_BIT_0,                             /* (ID:1017:13751:13752) */
	/* 001182 */ CSN1C_LABEL_END, CSN1C_VAL2(700),        /* (ID:0962:13120:13203) Label=<PUANCR_Fixed_Uplink_Allocation> Terminal=<0> */
	/* 001185 */ CSN1C_LABEL_A, CSN1C_VAL2(363), CSN1C_VAL1(1), /* (ID:0966:13203:13231) Label=<RESEGMENT> LabelId=70 */
	/* 001189 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 1196 */
	/* 001193 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001194 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 1193 */
	/* 001196 */ CSN1C_GOTO(26),                          /* (ID:0946:12964:13312) jump at 1222 */
	/* 001198 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(733),      /* (ID:0972:13256:13312) Label=<Non_distribution_part_error> Terminal=<1> LabelId=138 */
	/* 001201 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0973:13288:13310) Send construction; if encoding, jump to 1214 */
	/* 001205 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0976:13288:13292) Infinite loop start, jump to 1212 */
	/* 001209 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001210 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0976:13288:13292) Loop back to 1209 */
	/* 001212 */ CSN1C_GOTO(4),                           /* (ID:0973:13288:13310) skip the encode part and jump to 1216 */
	/* 001214 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001216 */ CSN1C_LABEL_END, CSN1C_VAL2(733),        /* (ID:0972:13256:13312) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 001219 */ CSN1C_GOTO(4),                           /* (ID:0946:12964:13312) jump at 1224 */
	/* 001221 */ CSN1C_BACKTRACK,                         /* (ID:0946:12964:13312) Failure of choice begun at 1132 */
	/* 001222 */ CSN1C_CHOICE_END,                        /* (ID:0946:12964:13312) End of choice begun at 1132 */
	/* 001223 */ CSN1C_GOTO(26),                          /* (ID:0944:12962:13378) jump at 1249 */
	/* 001225 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(739),      /* (ID:0981:13319:13378) Label=<Address_information_part_error> Terminal=<1> LabelId=139 */
	/* 001228 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0982:13354:13376) Send construction; if encoding, jump to 1241 */
	/* 001232 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0985:13354:13358) Infinite loop start, jump to 1239 */
	/* 001236 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001237 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0985:13354:13358) Loop back to 1236 */
	/* 001239 */ CSN1C_GOTO(4),                           /* (ID:0982:13354:13376) skip the encode part and jump to 1243 */
	/* 001241 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001243 */ CSN1C_LABEL_END, CSN1C_VAL2(739),        /* (ID:0981:13319:13378) Label=<Address_information_part_error> Terminal=<1> */
	/* 001246 */ CSN1C_GOTO(4),                           /* (ID:0944:12962:13378) jump at 1251 */
	/* 001248 */ CSN1C_BACKTRACK,                         /* (ID:0944:12962:13378) Failure of choice begun at 1130 */
	/* 001249 */ CSN1C_CHOICE_END,                        /* (ID:0944:12962:13378) End of choice begun at 1130 */
	/* 001250 */ CSN1C_GOTO(26),                          /* (ID:0938:12900:13436) jump at 1276 */
	/* 001252 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(745),      /* (ID:0990:13384:13436) Label=<Distribution_part_error> Terminal=<1> LabelId=140 */
	/* 001255 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0991:13412:13434) Send construction; if encoding, jump to 1268 */
	/* 001259 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0994:13412:13416) Infinite loop start, jump to 1266 */
	/* 001263 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001264 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0994:13412:13416) Loop back to 1263 */
	/* 001266 */ CSN1C_GOTO(4),                           /* (ID:0991:13412:13434) skip the encode part and jump to 1270 */
	/* 001268 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001270 */ CSN1C_LABEL_END, CSN1C_VAL2(745),        /* (ID:0990:13384:13436) Label=<Distribution_part_error> Terminal=<1> */
	/* 001273 */ CSN1C_GOTO(4),                           /* (ID:0938:12900:13436) jump at 1278 */
	/* 001275 */ CSN1C_BACKTRACK,                         /* (ID:0938:12900:13436) Failure of choice begun at 1124 */
	/* 001276 */ CSN1C_CHOICE_END,                        /* (ID:0938:12900:13436) End of choice begun at 1124 */
	/* 001277 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Uplink_Ack_Nack_message_content'
		DEFINITION FIELD-ID: 23  COMPLEXITY: 177
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 245
	-----------------------------------------------------------------*/
	/* 001278 */ CSN1C_CHOICE_NODE(0,330),                /* (ID:0565:8744:10403) VBIT choice at 1278, node 1, jump to 1608 */
	/* 001280 */ CSN1C_LABEL_A, CSN1C_VAL2(375), CSN1C_VAL1(2), /* (ID:0567:8744:8804) Label=<USED_DL_COVERAGE_CLASS> LabelId=71 */
	/* 001284 */ CSN1C_CHOICE_NODE(0,297),                /* (ID:0571:8806:10345) VBIT choice at 1284, node 1, jump to 1581 */
	/* 001286 */ CSN1C_CHOICE_NODE(0,268),                /* (ID:0573:8808:10279) VBIT choice at 1286, node 1, jump to 1554 */
	/* 001288 */ CSN1C_LABEL_A, CSN1C_VAL2(378), CSN1C_VAL1(5), /* (ID:0575:8808:8836) Label=<UPLINK_TFI> LabelId=72 */
	/* 001292 */ CSN1C_CHOICE_NODE(0,166),                /* (ID:0579:8838:10215) VBIT choice at 1292, node 1, jump to 1458 */
	/* 001294 */ CSN1C_BIT_0,                             /* (ID:0581:8838:8840) */
	/* 001295 */ CSN1C_CHOICE_NODE(0,19),                 /* (ID:0584:8877:9222) VBIT choice at 1295, node 1, jump to 1314 */
	/* 001297 */ CSN1C_VALUE, CSN1C_VAL1(17),             /* (ID:0593:8948:8949..0594:8949:8951) Bit string '01' */
	/* 001299 */ CSN1C_LABEL_A, CSN1C_VAL2(381), CSN1C_VAL1(32), /* (ID:0597:8953:9003) Label=<CONTENTION_RESOLUTION_TLLI> LabelId=73 */
	/* 001303 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(768),      /* (ID:0601:9003:9079) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> LabelId=74 */
	/* 001306 */ CSN1C_GOSUB, CSN1C_VAL2(148),            /* (ID:0604:9039:9077) Reference to 'EC_Primary_Ack_Nack_Description_IE' */
	/* 001309 */ CSN1C_LABEL_END, CSN1C_VAL2(768),        /* (ID:0601:9003:9079) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> */
	/* 001312 */ CSN1C_GOTO(35),                          /* (ID:0584:8877:9222) jump at 1347 */
	/* 001314 */ CSN1C_CHOICE_NODE(0,19),                 /* (ID:0584:8877:9222) VBIT choice at 1295, node 2, jump to 1333 */
	/* 001316 */ CSN1C_VALUE, CSN1C_VAL1(33),             /* (ID:0606:9089:9090..0607:9090:9092) Bit string '10' */
	/* 001318 */ CSN1C_LABEL_A, CSN1C_VAL2(387), CSN1C_VAL1(4), /* (ID:0610:9094:9144) Label=<CONTENTION_RESOLUTION_rTLLI> LabelId=75 */
	/* 001322 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(780),      /* (ID:0614:9144:9220) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> LabelId=74 */
	/* 001325 */ CSN1C_GOSUB, CSN1C_VAL2(148),            /* (ID:0617:9180:9218) Reference to 'EC_Primary_Ack_Nack_Description_IE' */
	/* 001328 */ CSN1C_LABEL_END, CSN1C_VAL2(780),        /* (ID:0614:9144:9220) Label=<EC_Primary_Ack_Nack_Description> Terminal=<0> */
	/* 001331 */ CSN1C_GOTO(16),                          /* (ID:0584:8877:9222) jump at 1347 */
	/* 001333 */ CSN1C_VALUE, CSN1C_VAL1(1),              /* (ID:0586:8877:8878..0587:8878:8880) Bit string '00' */
	/* 001335 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(786),      /* (ID:0588:8880:8946) Label=<EC_Ack_Nack_Description> Terminal=<0> LabelId=76 */
	/* 001338 */ CSN1C_GOSUB, CSN1C_VAL2(141),            /* (ID:0591:8908:8938) Reference to 'EC_Ack_Nack_Description_IE' */
	/* 001341 */ CSN1C_LABEL_END, CSN1C_VAL2(786),        /* (ID:0588:8880:8946) Label=<EC_Ack_Nack_Description> Terminal=<0> */
	/* 001344 */ CSN1C_GOTO(4),                           /* (ID:0584:8877:9222) jump at 1349 */
	/* 001346 */ CSN1C_BACKTRACK,                         /* (ID:0584:8877:9222) Failure of choice begun at 1295 */
	/* 001347 */ CSN1C_CHOICE_END,                        /* (ID:0584:8877:9222) End of choice begun at 1295 */
	/* 001348 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(792),      /* (ID:0618:9229:9309) Label=<PUAN_Fixed_Uplink_Allocation> Terminal=<0> LabelId=77 */
	/* 001351 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0744:10463:10494) VBIT choice at 1351, node 1, jump to 1360 */
	/* 001353 */ CSN1C_BIT_1,                             /* (ID:0748:10467:10469) */
	/* 001354 */ CSN1C_LABEL_A, CSN1C_VAL2(399), CSN1C_VAL1(2), /* (ID:0749:10469:10494) Label=<BSN_OFFSET> LabelId=78 */
	/* 001358 */ CSN1C_GOTO(8),                           /* (ID:0744:10463:10494) jump at 1366 */
	/* 001360 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0744:10463:10494) FBIT choice at 1351, node 2, jump to 1365 */
	/* 001362 */ CSN1C_BIT_0,                             /* (ID:0746:10463:10465) */
	/* 001363 */ CSN1C_GOTO(3),                           /* (ID:0744:10463:10494) jump at 1366 */
	/* 001365 */ CSN1C_BACKTRACK,                         /* (ID:0744:10463:10494) Failure of choice begun at 1351 */
	/* 001366 */ CSN1C_CHOICE_END,                        /* (ID:0744:10463:10494) End of choice begun at 1351 */
	/* 001367 */ CSN1C_LABEL_A, CSN1C_VAL2(404), CSN1C_VAL1(4), /* (ID:0753:10498:10550) Label=<START_FIRST_UL_RLC_DATA_BLOCK> LabelId=79 */
	/* 001371 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(46), /* (ID:0757:10552:10658) Infinite loop start, jump to 1394 */
	/* 001375 */ CSN1C_BIT_1,                             /* (ID:0760:10552:10554) */
	/* 001376 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0761:10556:10656) VBIT choice at 1376, node 1, jump to 1385 */
	/* 001378 */ CSN1C_BIT_0,                             /* (ID:0763:10556:10558) */
	/* 001379 */ CSN1C_LABEL_A, CSN1C_VAL2(409), CSN1C_VAL1(3), /* (ID:0764:10558:10652) Label=<DELAY_NEXT_UL_RLC_DATA_BLOCK> LabelId=80 */
	/* 001383 */ CSN1C_GOTO(8),                           /* (ID:0761:10556:10656) jump at 1391 */
	/* 001385 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0761:10556:10656) FBIT choice at 1376, node 2, jump to 1390 */
	/* 001387 */ CSN1C_BIT_1,                             /* (ID:0769:10654:10656) */
	/* 001388 */ CSN1C_GOTO(3),                           /* (ID:0761:10556:10656) jump at 1391 */
	/* 001390 */ CSN1C_BACKTRACK,                         /* (ID:0761:10556:10656) Failure of choice begun at 1376 */
	/* 001391 */ CSN1C_CHOICE_END,                        /* (ID:0761:10556:10656) End of choice begun at 1376 */
	/* 001392 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(17),        /* (ID:0757:10552:10658) Loop back to 1375 */
	/* 001394 */ CSN1C_BIT_0,                             /* (ID:0770:10663:10664) */
	/* 001395 */ CSN1C_LABEL_END, CSN1C_VAL2(792),        /* (ID:0618:9229:9309) Label=<PUAN_Fixed_Uplink_Allocation> Terminal=<0> */
	/* 001398 */ CSN1C_LABEL_A, CSN1C_VAL2(414), CSN1C_VAL1(1), /* (ID:0622:9309:9338) Label=<RESEGMENT> LabelId=81 */
	/* 001402 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0626:9340:9422) VBIT choice at 1402, node 1, jump to 1417 */
	/* 001404 */ CSN1C_BIT_1,                             /* (ID:0630:9344:9346) */
	/* 001405 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(834),      /* (ID:0631:9346:9422) Label=<EGPRS_Channel_Coding_Command> Terminal=<0> LabelId=82 */
	/* 001408 */ CSN1C_LABEL_A, CSN1C_VAL2(420), CSN1C_VAL1(4), /* (ID:1105:15807:16080) Label=<Scheme> LabelId=83 */
	/* 001412 */ CSN1C_LABEL_END, CSN1C_VAL2(834),        /* (ID:0631:9346:9422) Label=<EGPRS_Channel_Coding_Command> Terminal=<0> */
	/* 001415 */ CSN1C_GOTO(8),                           /* (ID:0626:9340:9422) jump at 1423 */
	/* 001417 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0626:9340:9422) FBIT choice at 1402, node 2, jump to 1422 */
	/* 001419 */ CSN1C_BIT_0,                             /* (ID:0628:9340:9342) */
	/* 001420 */ CSN1C_GOTO(3),                           /* (ID:0626:9340:9422) jump at 1423 */
	/* 001422 */ CSN1C_BACKTRACK,                         /* (ID:0626:9340:9422) Failure of choice begun at 1402 */
	/* 001423 */ CSN1C_CHOICE_END,                        /* (ID:0626:9340:9422) End of choice begun at 1402 */
	/* 001424 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:0635:9431:9643) VBIT choice at 1424, node 1, jump to 1449 */
	/* 001426 */ CSN1C_BIT_1,                             /* (ID:0639:9435:9437) */
	/* 001427 */ CSN1C_LABEL_A, CSN1C_VAL2(429), CSN1C_VAL1(2), /* (ID:0640:9437:9476) Label=<UL_COVERAGE_CLASS> LabelId=84 */
	/* 001431 */ CSN1C_LABEL_A, CSN1C_VAL2(432), CSN1C_VAL1(3), /* (ID:0644:9476:9518) Label=<STARTING_UL_TIMESLOT> LabelId=85 */
	/* 001435 */ CSN1C_LABEL_A, CSN1C_VAL2(435), CSN1C_VAL1(2), /* (ID:0648:9518:9557) Label=<DL_COVERAGE_CLASS> LabelId=86 */
	/* 001439 */ CSN1C_LABEL_A, CSN1C_VAL2(438), CSN1C_VAL1(2), /* (ID:0652:9557:9606) Label=<STARTING_DL_TIMESLOT_OFFSET> LabelId=87 */
	/* 001443 */ CSN1C_LABEL_A, CSN1C_VAL2(441), CSN1C_VAL1(3), /* (ID:0656:9606:9643) Label=<TIMESLOT_MULTIPLICATOR> LabelId=88 */
	/* 001447 */ CSN1C_GOTO(8),                           /* (ID:0635:9431:9643) jump at 1455 */
	/* 001449 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0635:9431:9643) FBIT choice at 1424, node 2, jump to 1454 */
	/* 001451 */ CSN1C_BIT_0,                             /* (ID:0637:9431:9433) */
	/* 001452 */ CSN1C_GOTO(3),                           /* (ID:0635:9431:9643) jump at 1455 */
	/* 001454 */ CSN1C_BACKTRACK,                         /* (ID:0635:9431:9643) Failure of choice begun at 1424 */
	/* 001455 */ CSN1C_CHOICE_END,                        /* (ID:0635:9431:9643) End of choice begun at 1424 */
	/* 001456 */ CSN1C_GOTO(95),                          /* (ID:0579:8838:10215) jump at 1551 */
	/* 001458 */ CSN1C_BIT_1,                             /* (ID:0661:9654:9656) */
	/* 001459 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0664:9710:9764) VBIT choice at 1459, node 1, jump to 1468 */
	/* 001461 */ CSN1C_BIT_1,                             /* (ID:0668:9720:9722) */
	/* 001462 */ CSN1C_LABEL_A, CSN1C_VAL2(444), CSN1C_VAL1(32), /* (ID:0669:9722:9764) Label=<CONTENTION_RESOLUTION_TLLI> LabelId=73 */
	/* 001466 */ CSN1C_GOTO(8),                           /* (ID:0664:9710:9764) jump at 1474 */
	/* 001468 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0664:9710:9764) FBIT choice at 1459, node 2, jump to 1473 */
	/* 001470 */ CSN1C_BIT_0,                             /* (ID:0666:9710:9718) */
	/* 001471 */ CSN1C_GOTO(3),                           /* (ID:0664:9710:9764) jump at 1474 */
	/* 001473 */ CSN1C_BACKTRACK,                         /* (ID:0664:9710:9764) Failure of choice begun at 1459 */
	/* 001474 */ CSN1C_CHOICE_END,                        /* (ID:0664:9710:9764) End of choice begun at 1459 */
	/* 001475 */ CSN1C_CHOICE_NODE(0,17),                 /* (ID:0673:9774:10045) VBIT choice at 1475, node 1, jump to 1492 */
	/* 001477 */ CSN1C_BIT_1,                             /* (ID:0677:9861:9863) */
	/* 001478 */ CSN1C_LABEL_A, CSN1C_VAL2(447), CSN1C_VAL1(3), /* (ID:0680:9865:9958) Label=<T3238> LabelId=89 */
	/* 001482 */ CSN1C_LABEL_A, CSN1C_VAL2(450), CSN1C_VAL1(2), /* (ID:0684:9958:10001) Label=<Initial_Waiting_Time> LabelId=90 */
	/* 001486 */ CSN1C_LABEL_A, CSN1C_VAL2(453), CSN1C_VAL1(2), /* (ID:0688:10001:10043) Label=<EC_PACCH_Monitoring_Pattern> LabelId=91 */
	/* 001490 */ CSN1C_GOTO(8),                           /* (ID:0673:9774:10045) jump at 1498 */
	/* 001492 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0673:9774:10045) FBIT choice at 1475, node 2, jump to 1497 */
	/* 001494 */ CSN1C_BIT_0,                             /* (ID:0675:9774:9859) */
	/* 001495 */ CSN1C_GOTO(3),                           /* (ID:0673:9774:10045) jump at 1498 */
	/* 001497 */ CSN1C_BACKTRACK,                         /* (ID:0673:9774:10045) Failure of choice begun at 1475 */
	/* 001498 */ CSN1C_CHOICE_END,                        /* (ID:0673:9774:10045) End of choice begun at 1475 */
	/* 001499 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0692:10055:10124) VBIT choice at 1499, node 1, jump to 1514 */
	/* 001501 */ CSN1C_BIT_1,                             /* (ID:0696:10059:10061) */
	/* 001502 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(912),      /* (ID:0697:10061:10124) Label=<EC_Packet_Timing_Advance> Terminal=<0> LabelId=92 */
	/* 001505 */ CSN1C_LABEL_A, CSN1C_VAL2(459), CSN1C_VAL1(6), /* (ID:1058:14975:15009) Label=<TIMING_ADVANCE_VALUE> LabelId=44 */
	/* 001509 */ CSN1C_LABEL_END, CSN1C_VAL2(912),        /* (ID:0697:10061:10124) Label=<EC_Packet_Timing_Advance> Terminal=<0> */
	/* 001512 */ CSN1C_GOTO(8),                           /* (ID:0692:10055:10124) jump at 1520 */
	/* 001514 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0692:10055:10124) FBIT choice at 1499, node 2, jump to 1519 */
	/* 001516 */ CSN1C_BIT_0,                             /* (ID:0694:10055:10057) */
	/* 001517 */ CSN1C_GOTO(3),                           /* (ID:0692:10055:10124) jump at 1520 */
	/* 001519 */ CSN1C_BACKTRACK,                         /* (ID:0692:10055:10124) Failure of choice begun at 1499 */
	/* 001520 */ CSN1C_CHOICE_END,                        /* (ID:0692:10055:10124) End of choice begun at 1499 */
	/* 001521 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0701:10132:10192) VBIT choice at 1521, node 1, jump to 1534 */
	/* 001523 */ CSN1C_BIT_1,                             /* (ID:0705:10136:10138) */
	/* 001524 */ CSN1C_LABEL_A, CSN1C_VAL2(470), CSN1C_VAL1(5), /* (ID:0706:10138:10165) Label=<GAMMA> LabelId=93 */
	/* 001528 */ CSN1C_LABEL_A, CSN1C_VAL2(473), CSN1C_VAL1(1), /* (ID:0710:10165:10192) Label=<ALPHA_Enable> LabelId=94 */
	/* 001532 */ CSN1C_GOTO(8),                           /* (ID:0701:10132:10192) jump at 1540 */
	/* 001534 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0701:10132:10192) FBIT choice at 1521, node 2, jump to 1539 */
	/* 001536 */ CSN1C_BIT_0,                             /* (ID:0703:10132:10134) */
	/* 001537 */ CSN1C_GOTO(3),                           /* (ID:0701:10132:10192) jump at 1540 */
	/* 001539 */ CSN1C_BACKTRACK,                         /* (ID:0701:10132:10192) Failure of choice begun at 1521 */
	/* 001540 */ CSN1C_CHOICE_END,                        /* (ID:0701:10132:10192) End of choice begun at 1521 */
	/* 001541 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 1548 */
	/* 001545 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001546 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 1545 */
	/* 001548 */ CSN1C_GOTO(4),                           /* (ID:0579:8838:10215) jump at 1553 */
	/* 001550 */ CSN1C_BACKTRACK,                         /* (ID:0579:8838:10215) Failure of choice begun at 1292 */
	/* 001551 */ CSN1C_CHOICE_END,                        /* (ID:0579:8838:10215) End of choice begun at 1292 */
	/* 001552 */ CSN1C_GOTO(26),                          /* (ID:0573:8808:10279) jump at 1578 */
	/* 001554 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(953),      /* (ID:0716:10223:10279) Label=<Non_distribution_part_error> Terminal=<1> LabelId=141 */
	/* 001557 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0717:10255:10277) Send construction; if encoding, jump to 1570 */
	/* 001561 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0720:10255:10259) Infinite loop start, jump to 1568 */
	/* 001565 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001566 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0720:10255:10259) Loop back to 1565 */
	/* 001568 */ CSN1C_GOTO(4),                           /* (ID:0717:10255:10277) skip the encode part and jump to 1572 */
	/* 001570 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001572 */ CSN1C_LABEL_END, CSN1C_VAL2(953),        /* (ID:0716:10223:10279) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 001575 */ CSN1C_GOTO(4),                           /* (ID:0573:8808:10279) jump at 1580 */
	/* 001577 */ CSN1C_BACKTRACK,                         /* (ID:0573:8808:10279) Failure of choice begun at 1286 */
	/* 001578 */ CSN1C_CHOICE_END,                        /* (ID:0573:8808:10279) End of choice begun at 1286 */
	/* 001579 */ CSN1C_GOTO(26),                          /* (ID:0571:8806:10345) jump at 1605 */
	/* 001581 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(959),      /* (ID:0725:10286:10345) Label=<Address_information_part_error> Terminal=<1> LabelId=142 */
	/* 001584 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0726:10321:10343) Send construction; if encoding, jump to 1597 */
	/* 001588 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0729:10321:10325) Infinite loop start, jump to 1595 */
	/* 001592 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001593 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0729:10321:10325) Loop back to 1592 */
	/* 001595 */ CSN1C_GOTO(4),                           /* (ID:0726:10321:10343) skip the encode part and jump to 1599 */
	/* 001597 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001599 */ CSN1C_LABEL_END, CSN1C_VAL2(959),        /* (ID:0725:10286:10345) Label=<Address_information_part_error> Terminal=<1> */
	/* 001602 */ CSN1C_GOTO(4),                           /* (ID:0571:8806:10345) jump at 1607 */
	/* 001604 */ CSN1C_BACKTRACK,                         /* (ID:0571:8806:10345) Failure of choice begun at 1284 */
	/* 001605 */ CSN1C_CHOICE_END,                        /* (ID:0571:8806:10345) End of choice begun at 1284 */
	/* 001606 */ CSN1C_GOTO(26),                          /* (ID:0565:8744:10403) jump at 1632 */
	/* 001608 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(965),      /* (ID:0734:10351:10403) Label=<Distribution_part_error> Terminal=<1> LabelId=143 */
	/* 001611 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0735:10379:10401) Send construction; if encoding, jump to 1624 */
	/* 001615 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0738:10379:10383) Infinite loop start, jump to 1622 */
	/* 001619 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001620 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0738:10379:10383) Loop back to 1619 */
	/* 001622 */ CSN1C_GOTO(4),                           /* (ID:0735:10379:10401) skip the encode part and jump to 1626 */
	/* 001624 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001626 */ CSN1C_LABEL_END, CSN1C_VAL2(965),        /* (ID:0734:10351:10403) Label=<Distribution_part_error> Terminal=<1> */
	/* 001629 */ CSN1C_GOTO(4),                           /* (ID:0565:8744:10403) jump at 1634 */
	/* 001631 */ CSN1C_BACKTRACK,                         /* (ID:0565:8744:10403) Failure of choice begun at 1278 */
	/* 001632 */ CSN1C_CHOICE_END,                        /* (ID:0565:8744:10403) End of choice begun at 1278 */
	/* 001633 */ CSN1C_RETURN,
	/*-----------------------------------------------------------------
		DEFINITION 'EC_Packet_Uplink_Assignment_message_content'
		DEFINITION FIELD-ID: 25  COMPLEXITY: 147
		SOURCE: ./TS_44.060_EC_PACCH_Rel13.src, 290
	-----------------------------------------------------------------*/
	/* 001634 */ CSN1C_CHOICE_NODE(0,302),                /* (ID:0771:10976:12184) VBIT choice at 1634, node 1, jump to 1936 */
	/* 001636 */ CSN1C_LABEL_A, CSN1C_VAL2(485), CSN1C_VAL1(2), /* (ID:0773:10976:11036) Label=<USED_DL_COVERAGE_CLASS> LabelId=95 */
	/* 001640 */ CSN1C_CHOICE_NODE(0,243),                /* (ID:0777:11038:12092) VBIT choice at 1640, node 1, jump to 1883 */
	/* 001642 */ CSN1C_CHOICE_NODE(0,214),                /* (ID:0779:11040:11969) VBIT choice at 1642, node 1, jump to 1856 */
	/* 001644 */ CSN1C_BIT_0,                             /* (ID:0781:11040:11042) */
	/* 001645 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(976),      /* (ID:0782:11042:11081) Label=<Global_TFI> Terminal=<0> LabelId=96 */
	/* 001648 */ CSN1C_GOSUB, CSN1C_VAL1(124),            /* (ID:0785:11057:11075) Reference to 'Global_TFI_IE' */
	/* 001650 */ CSN1C_LABEL_END, CSN1C_VAL2(976),        /* (ID:0782:11042:11081) Label=<Global_TFI> Terminal=<0> */
	/* 001653 */ CSN1C_CHOICE_NODE(0,201),                /* (ID:0787:11083:11835) Truncable concatenation, entry 0, jump to 1854 */
	/* 001655 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0788:11085:11127) VBIT choice at 1655, node 1, jump to 1664 */
	/* 001657 */ CSN1C_BIT_1,                             /* (ID:0792:11089:11091) */
	/* 001658 */ CSN1C_LABEL_A, CSN1C_VAL2(491), CSN1C_VAL1(5), /* (ID:0793:11091:11127) Label=<UPLINK_TFI_ASSIGNMENT> LabelId=97 */
	/* 001662 */ CSN1C_GOTO(8),                           /* (ID:0788:11085:11127) jump at 1670 */
	/* 001664 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0788:11085:11127) FBIT choice at 1655, node 2, jump to 1669 */
	/* 001666 */ CSN1C_BIT_0,                             /* (ID:0790:11085:11087) */
	/* 001667 */ CSN1C_GOTO(3),                           /* (ID:0788:11085:11127) jump at 1670 */
	/* 001669 */ CSN1C_BACKTRACK,                         /* (ID:0788:11085:11127) Failure of choice begun at 1655 */
	/* 001670 */ CSN1C_CHOICE_END,                        /* (ID:0788:11085:11127) End of choice begun at 1655 */
	/* 001671 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 1 */
	/* 001672 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0797:11136:11218) VBIT choice at 1672, node 1, jump to 1687 */
	/* 001674 */ CSN1C_BIT_1,                             /* (ID:0801:11140:11142) */
	/* 001675 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(988),      /* (ID:0802:11142:11218) Label=<EGPRS_Channel_Coding_Command> Terminal=<0> LabelId=98 */
	/* 001678 */ CSN1C_LABEL_A, CSN1C_VAL2(497), CSN1C_VAL1(4), /* (ID:1105:15807:16080) Label=<Scheme> LabelId=83 */
	/* 001682 */ CSN1C_LABEL_END, CSN1C_VAL2(988),        /* (ID:0802:11142:11218) Label=<EGPRS_Channel_Coding_Command> Terminal=<0> */
	/* 001685 */ CSN1C_GOTO(8),                           /* (ID:0797:11136:11218) jump at 1693 */
	/* 001687 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0797:11136:11218) FBIT choice at 1672, node 2, jump to 1692 */
	/* 001689 */ CSN1C_BIT_0,                             /* (ID:0799:11136:11138) */
	/* 001690 */ CSN1C_GOTO(3),                           /* (ID:0797:11136:11218) jump at 1693 */
	/* 001692 */ CSN1C_BACKTRACK,                         /* (ID:0797:11136:11218) Failure of choice begun at 1672 */
	/* 001693 */ CSN1C_CHOICE_END,                        /* (ID:0797:11136:11218) End of choice begun at 1672 */
	/* 001694 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 2 */
	/* 001695 */ CSN1C_LABEL_A, CSN1C_VAL2(506), CSN1C_VAL1(2), /* (ID:0806:11225:11263) Label=<OVERLAID_CDMA_CODE> LabelId=99 */
	/* 001699 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 3 */
	/* 001700 */ CSN1C_CHOICE_NODE(0,15),                 /* (ID:0810:11265:11334) VBIT choice at 1700, node 1, jump to 1715 */
	/* 001702 */ CSN1C_BIT_1,                             /* (ID:0814:11269:11271) */
	/* 001703 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1018),     /* (ID:0815:11271:11334) Label=<EC_Packet_Timing_Advance> Terminal=<0> LabelId=100 */
	/* 001706 */ CSN1C_LABEL_A, CSN1C_VAL2(512), CSN1C_VAL1(6), /* (ID:1058:14975:15009) Label=<TIMING_ADVANCE_VALUE> LabelId=44 */
	/* 001710 */ CSN1C_LABEL_END, CSN1C_VAL2(1018),       /* (ID:0815:11271:11334) Label=<EC_Packet_Timing_Advance> Terminal=<0> */
	/* 001713 */ CSN1C_GOTO(8),                           /* (ID:0810:11265:11334) jump at 1721 */
	/* 001715 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0810:11265:11334) FBIT choice at 1700, node 2, jump to 1720 */
	/* 001717 */ CSN1C_BIT_0,                             /* (ID:0812:11265:11267) */
	/* 001718 */ CSN1C_GOTO(3),                           /* (ID:0810:11265:11334) jump at 1721 */
	/* 001720 */ CSN1C_BACKTRACK,                         /* (ID:0810:11265:11334) Failure of choice begun at 1700 */
	/* 001721 */ CSN1C_CHOICE_END,                        /* (ID:0810:11265:11334) End of choice begun at 1700 */
	/* 001722 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 4 */
	/* 001723 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0819:11343:11408) VBIT choice at 1723, node 1, jump to 1736 */
	/* 001725 */ CSN1C_BIT_1,                             /* (ID:0823:11347:11349) */
	/* 001726 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1046),     /* (ID:0824:11349:11408) Label=<Frequency_Parameters> Terminal=<0> LabelId=101 */
	/* 001729 */ CSN1C_GOSUB, CSN1C_VAL1(114),            /* (ID:0827:11374:11406) Reference to 'Frequency_Parameters_struct' */
	/* 001731 */ CSN1C_LABEL_END, CSN1C_VAL2(1046),       /* (ID:0824:11349:11408) Label=<Frequency_Parameters> Terminal=<0> */
	/* 001734 */ CSN1C_GOTO(8),                           /* (ID:0819:11343:11408) jump at 1742 */
	/* 001736 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0819:11343:11408) FBIT choice at 1723, node 2, jump to 1741 */
	/* 001738 */ CSN1C_BIT_0,                             /* (ID:0821:11343:11345) */
	/* 001739 */ CSN1C_GOTO(3),                           /* (ID:0819:11343:11408) jump at 1742 */
	/* 001741 */ CSN1C_BACKTRACK,                         /* (ID:0819:11343:11408) Failure of choice begun at 1723 */
	/* 001742 */ CSN1C_CHOICE_END,                        /* (ID:0819:11343:11408) End of choice begun at 1723 */
	/* 001743 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 5 */
	/* 001744 */ CSN1C_LABEL_A, CSN1C_VAL2(526), CSN1C_VAL1(2), /* (ID:0828:11415:11452) Label=<UL_COVERAGE_CLASS> LabelId=102 */
	/* 001748 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 6 */
	/* 001749 */ CSN1C_LABEL_A, CSN1C_VAL2(529), CSN1C_VAL1(3), /* (ID:0832:11452:11492) Label=<STARTING_UL_TIMESLOT> LabelId=103 */
	/* 001753 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 7 */
	/* 001754 */ CSN1C_LABEL_A, CSN1C_VAL2(532), CSN1C_VAL1(3), /* (ID:0836:11492:11534) Label=<TIMESLOT_MULTIPLICATOR> LabelId=104 */
	/* 001758 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 8 */
	/* 001759 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1070),     /* (ID:0840:11534:11604) Label=<Fixed_Uplink_Allocation> Terminal=<0> LabelId=105 */
	/* 001762 */ CSN1C_LABEL_A, CSN1C_VAL2(538), CSN1C_VAL1(4), /* (ID:0920:12375:12421) Label=<START_FIRST_UL_RLC_DATA_BLOCK> LabelId=106 */
	/* 001766 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(46), /* (ID:0924:12423:12626) Infinite loop start, jump to 1789 */
	/* 001770 */ CSN1C_BIT_1,                             /* (ID:0927:12423:12425) */
	/* 001771 */ CSN1C_CHOICE_NODE(0,9),                  /* (ID:0928:12427:12624) VBIT choice at 1771, node 1, jump to 1780 */
	/* 001773 */ CSN1C_BIT_1,                             /* (ID:0932:12529:12531) */
	/* 001774 */ CSN1C_LABEL_A, CSN1C_VAL2(543), CSN1C_VAL1(3), /* (ID:0933:12531:12624) Label=<DELAY_NEXT_UL_RLC_DATA_BLOCK> LabelId=107 */
	/* 001778 */ CSN1C_GOTO(8),                           /* (ID:0928:12427:12624) jump at 1786 */
	/* 001780 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0928:12427:12624) FBIT choice at 1771, node 2, jump to 1785 */
	/* 001782 */ CSN1C_BIT_0,                             /* (ID:0930:12427:12527) */
	/* 001783 */ CSN1C_GOTO(3),                           /* (ID:0928:12427:12624) jump at 1786 */
	/* 001785 */ CSN1C_BACKTRACK,                         /* (ID:0928:12427:12624) Failure of choice begun at 1771 */
	/* 001786 */ CSN1C_CHOICE_END,                        /* (ID:0928:12427:12624) End of choice begun at 1771 */
	/* 001787 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(17),        /* (ID:0924:12423:12626) Loop back to 1770 */
	/* 001789 */ CSN1C_BIT_0,                             /* (ID:0937:12631:12632) */
	/* 001790 */ CSN1C_LABEL_END, CSN1C_VAL2(1070),       /* (ID:0840:11534:11604) Label=<Fixed_Uplink_Allocation> Terminal=<0> */
	/* 001793 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 9 */
	/* 001794 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0844:11606:11659) VBIT choice at 1794, node 1, jump to 1807 */
	/* 001796 */ CSN1C_BIT_1,                             /* (ID:0848:11610:11612) */
	/* 001797 */ CSN1C_LABEL_A, CSN1C_VAL2(548), CSN1C_VAL1(4), /* (ID:0849:11612:11637) Label=<P0> LabelId=108 */
	/* 001801 */ CSN1C_LABEL_A, CSN1C_VAL2(551), CSN1C_VAL1(1), /* (ID:0853:11637:11659) Label=<PR_MODE> LabelId=109 */
	/* 001805 */ CSN1C_GOTO(8),                           /* (ID:0844:11606:11659) jump at 1813 */
	/* 001807 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0844:11606:11659) FBIT choice at 1794, node 2, jump to 1812 */
	/* 001809 */ CSN1C_BIT_0,                             /* (ID:0846:11606:11608) */
	/* 001810 */ CSN1C_GOTO(3),                           /* (ID:0844:11606:11659) jump at 1813 */
	/* 001812 */ CSN1C_BACKTRACK,                         /* (ID:0844:11606:11659) Failure of choice begun at 1794 */
	/* 001813 */ CSN1C_CHOICE_END,                        /* (ID:0844:11606:11659) End of choice begun at 1794 */
	/* 001814 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 10 */
	/* 001815 */ CSN1C_CHOICE_NODE(0,13),                 /* (ID:0857:11668:11728) VBIT choice at 1815, node 1, jump to 1828 */
	/* 001817 */ CSN1C_BIT_1,                             /* (ID:0861:11672:11674) */
	/* 001818 */ CSN1C_LABEL_A, CSN1C_VAL2(554), CSN1C_VAL1(5), /* (ID:0862:11674:11701) Label=<GAMMA> LabelId=110 */
	/* 001822 */ CSN1C_LABEL_A, CSN1C_VAL2(557), CSN1C_VAL1(1), /* (ID:0866:11701:11728) Label=<ALPHA_Enable> LabelId=111 */
	/* 001826 */ CSN1C_GOTO(8),                           /* (ID:0857:11668:11728) jump at 1834 */
	/* 001828 */ CSN1C_CHOICE_NODE(1,5),                  /* (ID:0857:11668:11728) FBIT choice at 1815, node 2, jump to 1833 */
	/* 001830 */ CSN1C_BIT_0,                             /* (ID:0859:11668:11670) */
	/* 001831 */ CSN1C_GOTO(3),                           /* (ID:0857:11668:11728) jump at 1834 */
	/* 001833 */ CSN1C_BACKTRACK,                         /* (ID:0857:11668:11728) Failure of choice begun at 1815 */
	/* 001834 */ CSN1C_CHOICE_END,                        /* (ID:0857:11668:11728) End of choice begun at 1815 */
	/* 001835 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 11 */
	/* 001836 */ CSN1C_LABEL_A, CSN1C_VAL2(560), CSN1C_VAL1(2), /* (ID:0870:11735:11772) Label=<DL_COVERAGE_CLASS> LabelId=112 */
	/* 001840 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 12 */
	/* 001841 */ CSN1C_LABEL_A, CSN1C_VAL2(563), CSN1C_VAL1(2), /* (ID:0874:11772:11819) Label=<STARTING_DL_TIMESLOT_OFFSET> LabelId=113 */
	/* 001845 */ CSN1C_UPDATE_BACKTRACK,                  /* (ID:0787:11083:11835) Truncable concatenation, entry 13 */
	/* 001846 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0039:823:828) Infinite loop start, jump to 1853 */
	/* 001850 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001851 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0039:823:828) Loop back to 1850 */
	/* 001853 */ CSN1C_CHOICE_END,
	/* 001854 */ CSN1C_GOTO(26),                          /* (ID:0779:11040:11969) jump at 1880 */
	/* 001856 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1133),     /* (ID:0880:11911:11969) Label=<Non_distribution_part_error> Terminal=<1> LabelId=144 */
	/* 001859 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0881:11943:11967) Send construction; if encoding, jump to 1872 */
	/* 001863 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0884:11943:11947) Infinite loop start, jump to 1870 */
	/* 001867 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001868 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0884:11943:11947) Loop back to 1867 */
	/* 001870 */ CSN1C_GOTO(4),                           /* (ID:0881:11943:11967) skip the encode part and jump to 1874 */
	/* 001872 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001874 */ CSN1C_LABEL_END, CSN1C_VAL2(1133),       /* (ID:0880:11911:11969) Label=<Non_distribution_part_error> Terminal=<1> */
	/* 001877 */ CSN1C_GOTO(4),                           /* (ID:0779:11040:11969) jump at 1882 */
	/* 001879 */ CSN1C_BACKTRACK,                         /* (ID:0779:11040:11969) Failure of choice begun at 1642 */
	/* 001880 */ CSN1C_CHOICE_END,                        /* (ID:0779:11040:11969) End of choice begun at 1642 */
	/* 001881 */ CSN1C_GOTO(52),                          /* (ID:0777:11038:12092) jump at 1933 */
	/* 001883 */ CSN1C_CHOICE_NODE(0,25),                 /* (ID:0777:11038:12092) VBIT choice at 1640, node 2, jump to 1908 */
	/* 001885 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1139),     /* (ID:0889:11977:12041) Label=<Address_information_part_error> Terminal=<1> LabelId=145 */
	/* 001888 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0890:12012:12036) Send construction; if encoding, jump to 1901 */
	/* 001892 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0893:12012:12016) Infinite loop start, jump to 1899 */
	/* 001896 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001897 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0893:12012:12016) Loop back to 1896 */
	/* 001899 */ CSN1C_GOTO(4),                           /* (ID:0890:12012:12036) skip the encode part and jump to 1903 */
	/* 001901 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001903 */ CSN1C_LABEL_END, CSN1C_VAL2(1139),       /* (ID:0889:11977:12041) Label=<Address_information_part_error> Terminal=<1> */
	/* 001906 */ CSN1C_GOTO(27),                          /* (ID:0777:11038:12092) jump at 1933 */
	/* 001908 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1145),     /* (ID:0898:12043:12092) Label=<Message_escape> Terminal=<1> LabelId=146 */
	/* 001911 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(14),  /* (ID:0899:12062:12090) Send construction; if encoding, jump to 1925 */
	/* 001915 */ CSN1C_BIT_1,                             /* (ID:0904:12064:12066) */
	/* 001916 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0905:12068:12072) Infinite loop start, jump to 1923 */
	/* 001920 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001921 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0905:12068:12072) Loop back to 1920 */
	/* 001923 */ CSN1C_GOTO(4),                           /* (ID:0899:12062:12090) skip the encode part and jump to 1927 */
	/* 001925 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001927 */ CSN1C_LABEL_END, CSN1C_VAL2(1145),       /* (ID:0898:12043:12092) Label=<Message_escape> Terminal=<1> */
	/* 001930 */ CSN1C_GOTO(4),                           /* (ID:0777:11038:12092) jump at 1935 */
	/* 001932 */ CSN1C_BACKTRACK,                         /* (ID:0777:11038:12092) Failure of choice begun at 1640 */
	/* 001933 */ CSN1C_CHOICE_END,                        /* (ID:0777:11038:12092) End of choice begun at 1640 */
	/* 001934 */ CSN1C_GOTO(26),                          /* (ID:0771:10976:12184) jump at 1960 */
	/* 001936 */ CSN1C_LABEL_BEGIN, CSN1C_VAL2(1151),     /* (ID:0910:12130:12184) Label=<Distribution_part_error> Terminal=<1> LabelId=147 */
	/* 001939 */ CSN1C_JUMP_IF_ENCODING, CSN1C_VAL3(13),  /* (ID:0911:12158:12182) Send construction; if encoding, jump to 1952 */
	/* 001943 */ CSN1C_LOOP_BEGIN_INFINITE, CSN1C_VAL3(15), /* (ID:0914:12158:12162) Infinite loop start, jump to 1950 */
	/* 001947 */ CSN1C_BIT_A(1),                          /* (ID:0002:535:536) */
	/* 001948 */ CSN1C_LOOP_CYCLE, CSN1C_VAL1(1),         /* (ID:0914:12158:12162) Loop back to 1947 */
	/* 001950 */ CSN1C_GOTO(4),                           /* (ID:0911:12158:12182) skip the encode part and jump to 1954 */
	/* 001952 */ CSN1C_EXECUTE_ENC, CSN1C_VAL1(0),
	/* 001954 */ CSN1C_LABEL_END, CSN1C_VAL2(1151),       /* (ID:0910:12130:12184) Label=<Distribution_part_error> Terminal=<1> */
	/* 001957 */ CSN1C_GOTO(4),                           /* (ID:0771:10976:12184) jump at 1962 */
	/* 001959 */ CSN1C_BACKTRACK,                         /* (ID:0771:10976:12184) Failure of choice begun at 1634 */
	/* 001960 */ CSN1C_CHOICE_END,                        /* (ID:0771:10976:12184) End of choice begun at 1634 */
	/* 001961 */ CSN1C_RETURN,
	((unsigned char)0) /* END OF PROGRAM */
};

/* DEFINITION FOR PROGRAM 'Program_EC_PACCH' */
TCSN1CProgram Program_EC_PACCH_Program = {
	/* ProgramCode.......*/ Program_EC_PACCH_ProgramCode,
	/* ProgramLength.....*/ 1962,
	/* FieldIdPairSet....*/ Program_EC_PACCH_FieldIdPairSet,
#ifdef CSN1C_LABEL_NAMES
	/* LabelNames........*/ Program_EC_PACCH_Labels,
#endif
	/* FunctionMap.......*/ (void (*const *) (void* ED_EXTRAPARAMS_DECL))Program_EC_PACCH_FunctionMap,
	/* ExpressionMap.....*/ (unsigned ED_EXLONG (*const *) (void*))Program_EC_PACCH_ExpressionMap,
#ifdef CSN1C_ENABLE_LABEL_SIZE
	/* LabelSizes........*/ Program_EC_PACCH_LabelSize,
#endif
	/* FirstErrorLabelId.*/ 121
};

