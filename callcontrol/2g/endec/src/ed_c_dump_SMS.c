/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_dump_SMS.h"
#include "ed_dump_val.h"

#define DUMPSTR(a) OStream->WriteString (OStream, a)
void Dump_c_TAddress (TEDOStream* OStream, const c_TAddress* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TAddress");
	ED_Dump_Struct_Begin_Field (OStream, "TAddress", "TypeOfNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TypeOfNumber> ACCESS=<Data->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->TypeOfNumber)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Unknown"); break;
				case 1: OStream->WriteString (OStream, "International number"); break;
				case 2: OStream->WriteString (OStream, "National number"); break;
				case 3: OStream->WriteString (OStream, "Network specific number"); break;
				case 4: OStream->WriteString (OStream, "Subscriber number"); break;
				case 5: OStream->WriteString (OStream, "Alphanumeric"); break;
				case 6: OStream->WriteString (OStream, "Abbreviated number"); break;
				case 7: OStream->WriteString (OStream, "Reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TAddress", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TAddress", "NumPlanId");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<NumPlanId> ACCESS=<Data->NumPlanId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->NumPlanId)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Unknown"); break;
				case 1: OStream->WriteString (OStream, "ISDN/telephone numbering plan (E.164 [17]/E.163[18])"); break;
				case 3: OStream->WriteString (OStream, "Data numbering plan (X.121)"); break;
				case 4: OStream->WriteString (OStream, "Telex numbering plan"); break;
				case 5: OStream->WriteString (OStream, "Service Centre Specific plan"); break;
				case 6: OStream->WriteString (OStream, "Service Centre Specific plan"); break;
				case 8: OStream->WriteString (OStream, "National numbering plan"); break;
				case 9: OStream->WriteString (OStream, "Private numbering plan"); break;
				case 10: OStream->WriteString (OStream, "ERMES numbering plan (ETSI DE/PS 3 01 3)"); break;
				case 15: OStream->WriteString (OStream, "Reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TAddress", "NumPlanId");
	ED_Dump_Struct_Begin_Field (OStream, "TAddress", "Address");
		/* SEQUENCE NAME=<Address> ACCESS=<Data->Address>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Address", Data->Address.items);
		for (i0=0; i0<Data->Address.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Address", i0, Data->Address.items);
		  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Address.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Address.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "Address", i0, Data->Address.items);
		}
		ED_Dump_Sequence_End (OStream, "Address", Data->Address.items);
	ED_Dump_Struct_End_Field (OStream, "TAddress", "Address");
	ED_Dump_Struct_End (OStream, "TAddress");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TEnVoiceMailNotificationItem (TEDOStream* OStream, const c_TEnVoiceMailNotificationItem* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TEnVoiceMailNotificationItem");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_ID");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<VM_MESSAGE_ID> ACCESS=<Data->VM_MESSAGE_ID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->VM_MESSAGE_ID);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_ID");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_LENGTH");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VM_MESSAGE_LENGTH> ACCESS=<Data->VM_MESSAGE_LENGTH>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->VM_MESSAGE_LENGTH);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_LENGTH");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_RETENTION_DAYS");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VM_MESSAGE_RETENTION_DAYS> ACCESS=<Data->VM_MESSAGE_RETENTION_DAYS>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->VM_MESSAGE_RETENTION_DAYS);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_RETENTION_DAYS");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_PRIORITY_INDICATION");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MESSAGE_PRIORITY_INDICATION> ACCESS=<Data->VM_MESSAGE_PRIORITY_INDICATION>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MESSAGE_PRIORITY_INDICATION);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_PRIORITY_INDICATION");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_EXTENSION_INDICATOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MESSAGE_EXTENSION_INDICATOR> ACCESS=<Data->VM_MESSAGE_EXTENSION_INDICATOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MESSAGE_EXTENSION_INDICATOR);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_EXTENSION_INDICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_CALLING_LINE_IDENTITY");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<VM_MESSAGE_CALLING_LINE_IDENTITY> ACCESS=<Data->VM_MESSAGE_CALLING_LINE_IDENTITY>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->VM_MESSAGE_CALLING_LINE_IDENTITY));
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_CALLING_LINE_IDENTITY");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_EXTENSION_DATA");
	  /* NAME=<VM_MESSAGE_EXTENSION_DATA> ACCESS=<Data->VM_MESSAGE_EXTENSION_DATA>  MAXBITSIZE=<2040> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->VM_MESSAGE_EXTENSION_DATA.value, Data->VM_MESSAGE_EXTENSION_DATA.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotificationItem", "VM_MESSAGE_EXTENSION_DATA");
	ED_Dump_Struct_End (OStream, "TEnVoiceMailNotificationItem");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TEnVoiceMailDeleteConfirmationItem (TEDOStream* OStream, const c_TEnVoiceMailDeleteConfirmationItem* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TEnVoiceMailDeleteConfirmationItem");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_ID");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<VM_MESSAGE_ID> ACCESS=<Data->VM_MESSAGE_ID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->VM_MESSAGE_ID);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_ID");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_EXTENSION_INDICATOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MESSAGE_EXTENSION_INDICATOR> ACCESS=<Data->VM_MESSAGE_EXTENSION_INDICATOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MESSAGE_EXTENSION_INDICATOR);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_EXTENSION_INDICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_EXTENSION_DATA");
	  /* NAME=<VM_MESSAGE_EXTENSION_DATA> ACCESS=<Data->VM_MESSAGE_EXTENSION_DATA>  MAXBITSIZE=<2040> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->VM_MESSAGE_EXTENSION_DATA.value, Data->VM_MESSAGE_EXTENSION_DATA.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmationItem", "VM_MESSAGE_EXTENSION_DATA");
	ED_Dump_Struct_End (OStream, "TEnVoiceMailDeleteConfirmationItem");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TEnVoiceMailNotification (TEDOStream* OStream, const c_TEnVoiceMailNotification* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TEnVoiceMailNotification");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "ENHANCED_VOICE_MAIL_PDU_TYPE");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ENHANCED_VOICE_MAIL_PDU_TYPE> ACCESS=<Data->ENHANCED_VOICE_MAIL_PDU_TYPE>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ENHANCED_VOICE_MAIL_PDU_TYPE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "ENHANCED_VOICE_MAIL_PDU_TYPE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "MULTIPLE_SUBSCRIBER_PROFILE");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MULTIPLE_SUBSCRIBER_PROFILE> ACCESS=<Data->MULTIPLE_SUBSCRIBER_PROFILE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MULTIPLE_SUBSCRIBER_PROFILE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "MULTIPLE_SUBSCRIBER_PROFILE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "SM_STORAGE");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_STORAGE> ACCESS=<Data->SM_STORAGE>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_STORAGE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "SM_STORAGE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_ALMOST_FULL");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_ALMOST_FULL> ACCESS=<Data->VM_MAILBOX_ALMOST_FULL>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_ALMOST_FULL);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_ALMOST_FULL");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_FULL");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_FULL> ACCESS=<Data->VM_MAILBOX_FULL>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_FULL);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_FULL");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_STATUS_EXTENSION_INDICATOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_STATUS_EXTENSION_INDICATOR> ACCESS=<Data->VM_MAILBOX_STATUS_EXTENSION_INDICATOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_STATUS_EXTENSION_INDICATOR);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_STATUS_EXTENSION_INDICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_ACCESS_ADDRESS");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<VM_MAILBOX_ACCESS_ADDRESS> ACCESS=<Data->VM_MAILBOX_ACCESS_ADDRESS>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->VM_MAILBOX_ACCESS_ADDRESS));
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_ACCESS_ADDRESS");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "NUMBER_OF_VOICE_MESSAGES");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NUMBER_OF_VOICE_MESSAGES> ACCESS=<Data->NUMBER_OF_VOICE_MESSAGES>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->NUMBER_OF_VOICE_MESSAGES);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "NUMBER_OF_VOICE_MESSAGES");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "NUMBER_OF_VM_NOTIFICATIONS");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NUMBER_OF_VM_NOTIFICATIONS> ACCESS=<Data->NUMBER_OF_VM_NOTIFICATIONS>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->NUMBER_OF_VM_NOTIFICATIONS);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "NUMBER_OF_VM_NOTIFICATIONS");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_STATUS_EXTENSION_DATA");
	  /* NAME=<VM_MAILBOX_STATUS_EXTENSION_DATA> ACCESS=<Data->VM_MAILBOX_STATUS_EXTENSION_DATA>  MAXBITSIZE=<2040> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->VM_MAILBOX_STATUS_EXTENSION_DATA.value, Data->VM_MAILBOX_STATUS_EXTENSION_DATA.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_MAILBOX_STATUS_EXTENSION_DATA");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailNotification", "VM_NOTIFICATIONS");
		/* SEQUENCE NAME=<VM_NOTIFICATIONS> ACCESS=<Data->VM_NOTIFICATIONS>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "VM_NOTIFICATIONS", Data->VM_NOTIFICATIONS.items);
		for (i0=0; i0<Data->VM_NOTIFICATIONS.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "VM_NOTIFICATIONS", i0, Data->VM_NOTIFICATIONS.items);
		  /* STRUCTURAL=<1> TYPE=<c_TEnVoiceMailNotificationItem> NAME=<data> ACCESS=<*(Data->VM_NOTIFICATIONS.data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_TEnVoiceMailNotificationItem> */
		  Dump_c_TEnVoiceMailNotificationItem (OStream, &(*(Data->VM_NOTIFICATIONS.data [i0])));
			ED_Dump_Sequence_End_Field (OStream, "VM_NOTIFICATIONS", i0, Data->VM_NOTIFICATIONS.items);
		}
		ED_Dump_Sequence_End (OStream, "VM_NOTIFICATIONS", Data->VM_NOTIFICATIONS.items);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailNotification", "VM_NOTIFICATIONS");
	ED_Dump_Struct_End (OStream, "TEnVoiceMailNotification");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TEnVoiceMailDeleteConfirmation (TEDOStream* OStream, const c_TEnVoiceMailDeleteConfirmation* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TEnVoiceMailDeleteConfirmation");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "ENHANCED_VOICE_MAIL_PDU_TYPE");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ENHANCED_VOICE_MAIL_PDU_TYPE> ACCESS=<Data->ENHANCED_VOICE_MAIL_PDU_TYPE>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ENHANCED_VOICE_MAIL_PDU_TYPE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "ENHANCED_VOICE_MAIL_PDU_TYPE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "MULTIPLE_SUBSCRIBER_PROFILE");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MULTIPLE_SUBSCRIBER_PROFILE> ACCESS=<Data->MULTIPLE_SUBSCRIBER_PROFILE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MULTIPLE_SUBSCRIBER_PROFILE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "MULTIPLE_SUBSCRIBER_PROFILE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "SM_STORAGE");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_STORAGE> ACCESS=<Data->SM_STORAGE>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_STORAGE);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "SM_STORAGE");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_ALMOST_FULL");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_ALMOST_FULL> ACCESS=<Data->VM_MAILBOX_ALMOST_FULL>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_ALMOST_FULL);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_ALMOST_FULL");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_FULL");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_FULL> ACCESS=<Data->VM_MAILBOX_FULL>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_FULL);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_FULL");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_STATUS_EXTENSION_INDICATOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VM_MAILBOX_STATUS_EXTENSION_INDICATOR> ACCESS=<Data->VM_MAILBOX_STATUS_EXTENSION_INDICATOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->VM_MAILBOX_STATUS_EXTENSION_INDICATOR);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_STATUS_EXTENSION_INDICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_ACCESS_ADDRESS");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<VM_MAILBOX_ACCESS_ADDRESS> ACCESS=<Data->VM_MAILBOX_ACCESS_ADDRESS>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->VM_MAILBOX_ACCESS_ADDRESS));
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_ACCESS_ADDRESS");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "NUMBER_OF_VOICE_MESSAGES");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NUMBER_OF_VOICE_MESSAGES> ACCESS=<Data->NUMBER_OF_VOICE_MESSAGES>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->NUMBER_OF_VOICE_MESSAGES);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "NUMBER_OF_VOICE_MESSAGES");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "NUMBER_OF_VM_DELETES");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NUMBER_OF_VM_DELETES> ACCESS=<Data->NUMBER_OF_VM_DELETES>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->NUMBER_OF_VM_DELETES);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "NUMBER_OF_VM_DELETES");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_STATUS_EXTENSION_DATA");
	  /* NAME=<VM_MAILBOX_STATUS_EXTENSION_DATA> ACCESS=<Data->VM_MAILBOX_STATUS_EXTENSION_DATA>  MAXBITSIZE=<2040> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->VM_MAILBOX_STATUS_EXTENSION_DATA.value, Data->VM_MAILBOX_STATUS_EXTENSION_DATA.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_MAILBOX_STATUS_EXTENSION_DATA");
	ED_Dump_Struct_Begin_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_DELETE_CONFIRMATIONS");
		/* SEQUENCE NAME=<VM_DELETE_CONFIRMATIONS> ACCESS=<Data->VM_DELETE_CONFIRMATIONS>  ITEMS=<15> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "VM_DELETE_CONFIRMATIONS", Data->VM_DELETE_CONFIRMATIONS.items);
		for (i0=0; i0<Data->VM_DELETE_CONFIRMATIONS.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "VM_DELETE_CONFIRMATIONS", i0, Data->VM_DELETE_CONFIRMATIONS.items);
		  /* STRUCTURAL=<1> TYPE=<c_TEnVoiceMailDeleteConfirmationItem> NAME=<data> ACCESS=<*(Data->VM_DELETE_CONFIRMATIONS.data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_TEnVoiceMailDeleteConfirmationItem> */
		  Dump_c_TEnVoiceMailDeleteConfirmationItem (OStream, &(*(Data->VM_DELETE_CONFIRMATIONS.data [i0])));
			ED_Dump_Sequence_End_Field (OStream, "VM_DELETE_CONFIRMATIONS", i0, Data->VM_DELETE_CONFIRMATIONS.items);
		}
		ED_Dump_Sequence_End (OStream, "VM_DELETE_CONFIRMATIONS", Data->VM_DELETE_CONFIRMATIONS.items);
	ED_Dump_Struct_End_Field (OStream, "TEnVoiceMailDeleteConfirmation", "VM_DELETE_CONFIRMATIONS");
	ED_Dump_Struct_End (OStream, "TEnVoiceMailDeleteConfirmation");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TConcShortMsgs8BitRefNum (TEDOStream* OStream, const c_TConcShortMsgs8BitRefNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TConcShortMsgs8BitRefNum");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsgs8BitRefNum", "RefNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RefNumber> ACCESS=<Data->RefNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RefNumber);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsgs8BitRefNum", "RefNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsgs8BitRefNum", "MaxMesgs");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaxMesgs> ACCESS=<Data->MaxMesgs>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaxMesgs);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsgs8BitRefNum", "MaxMesgs");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsgs8BitRefNum", "SeqNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SeqNumber> ACCESS=<Data->SeqNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SeqNumber);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsgs8BitRefNum", "SeqNumber");
	ED_Dump_Struct_End (OStream, "TConcShortMsgs8BitRefNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TSpecialSmsMsgInd (TEDOStream* OStream, const c_TSpecialSmsMsgInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TSpecialSmsMsgInd");
	ED_Dump_Struct_Begin_Field (OStream, "TSpecialSmsMsgInd", "StoreMessage");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<StoreMessage> ACCESS=<Data->StoreMessage>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->StoreMessage);
	ED_Dump_Struct_End_Field (OStream, "TSpecialSmsMsgInd", "StoreMessage");
	ED_Dump_Struct_Begin_Field (OStream, "TSpecialSmsMsgInd", "ExtendedIndication");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ExtendedIndication> ACCESS=<Data->ExtendedIndication>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ExtendedIndication);
	ED_Dump_Struct_End_Field (OStream, "TSpecialSmsMsgInd", "ExtendedIndication");
	ED_Dump_Struct_Begin_Field (OStream, "TSpecialSmsMsgInd", "Indication");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Indication> ACCESS=<Data->Indication>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Indication);
	ED_Dump_Struct_End_Field (OStream, "TSpecialSmsMsgInd", "Indication");
	ED_Dump_Struct_Begin_Field (OStream, "TSpecialSmsMsgInd", "MsgCount");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MsgCount> ACCESS=<Data->MsgCount>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MsgCount);
	ED_Dump_Struct_End_Field (OStream, "TSpecialSmsMsgInd", "MsgCount");
	ED_Dump_Struct_End (OStream, "TSpecialSmsMsgInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TApplPortAddrScheme8BitAddr (TEDOStream* OStream, const c_TApplPortAddrScheme8BitAddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TApplPortAddrScheme8BitAddr");
	ED_Dump_Struct_Begin_Field (OStream, "TApplPortAddrScheme8BitAddr", "DestPort");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DestPort> ACCESS=<Data->DestPort>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->DestPort);
	ED_Dump_Struct_End_Field (OStream, "TApplPortAddrScheme8BitAddr", "DestPort");
	ED_Dump_Struct_Begin_Field (OStream, "TApplPortAddrScheme8BitAddr", "OrigPort");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OrigPort> ACCESS=<Data->OrigPort>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->OrigPort);
	ED_Dump_Struct_End_Field (OStream, "TApplPortAddrScheme8BitAddr", "OrigPort");
	ED_Dump_Struct_End (OStream, "TApplPortAddrScheme8BitAddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TApplPortAddrScheme16BitAddr (TEDOStream* OStream, const c_TApplPortAddrScheme16BitAddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TApplPortAddrScheme16BitAddr");
	ED_Dump_Struct_Begin_Field (OStream, "TApplPortAddrScheme16BitAddr", "DestPort");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<DestPort> ACCESS=<Data->DestPort>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->DestPort);
	ED_Dump_Struct_End_Field (OStream, "TApplPortAddrScheme16BitAddr", "DestPort");
	ED_Dump_Struct_Begin_Field (OStream, "TApplPortAddrScheme16BitAddr", "OrigPort");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<OrigPort> ACCESS=<Data->OrigPort>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->OrigPort);
	ED_Dump_Struct_End_Field (OStream, "TApplPortAddrScheme16BitAddr", "OrigPort");
	ED_Dump_Struct_End (OStream, "TApplPortAddrScheme16BitAddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TSmscCtrlParams (TEDOStream* OStream, const c_TSmscCtrlParams* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TSmscCtrlParams");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "StatusRepCompleted");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<StatusRepCompleted> ACCESS=<Data->StatusRepCompleted>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->StatusRepCompleted);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "StatusRepCompleted");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "StatusRepPermError");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<StatusRepPermError> ACCESS=<Data->StatusRepPermError>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->StatusRepPermError);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "StatusRepPermError");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "StatusRepTempError");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<StatusRepTempError> ACCESS=<Data->StatusRepTempError>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->StatusRepTempError);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "StatusRepTempError");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "StatusRepTempErrorSMStillTrying");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<StatusRepTempErrorSMStillTrying> ACCESS=<Data->StatusRepTempErrorSMStillTrying>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->StatusRepTempErrorSMStillTrying);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "StatusRepTempErrorSMStillTrying");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "reserved");
	  /* STRUCTURAL=<0> TYPE=<c_TSmscCtrlParams_reserved> NAME=<reserved> ACCESS=<Data->reserved>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "reserved");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "CancelConcat");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CancelConcat> ACCESS=<Data->CancelConcat>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CancelConcat);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "CancelConcat");
	ED_Dump_Struct_Begin_Field (OStream, "TSmscCtrlParams", "IncludeOrigUDHInStatusRep");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<IncludeOrigUDHInStatusRep> ACCESS=<Data->IncludeOrigUDHInStatusRep>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->IncludeOrigUDHInStatusRep);
	ED_Dump_Struct_End_Field (OStream, "TSmscCtrlParams", "IncludeOrigUDHInStatusRep");
	ED_Dump_Struct_End (OStream, "TSmscCtrlParams");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUdhSrcInd (TEDOStream* OStream, const c_TUdhSrcInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TUdhSrcInd");
	ED_Dump_Struct_Begin_Field (OStream, "TUdhSrcInd", "value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<value> ACCESS=<Data->value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->value);
	ED_Dump_Struct_End_Field (OStream, "TUdhSrcInd", "value");
	ED_Dump_Struct_End (OStream, "TUdhSrcInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TConcShortMsg16BitRefNum (TEDOStream* OStream, const c_TConcShortMsg16BitRefNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TConcShortMsg16BitRefNum");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsg16BitRefNum", "RefNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<RefNumber> ACCESS=<Data->RefNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RefNumber);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsg16BitRefNum", "RefNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsg16BitRefNum", "MaxMesgs");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaxMesgs> ACCESS=<Data->MaxMesgs>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaxMesgs);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsg16BitRefNum", "MaxMesgs");
	ED_Dump_Struct_Begin_Field (OStream, "TConcShortMsg16BitRefNum", "SeqNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SeqNumber> ACCESS=<Data->SeqNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SeqNumber);
	ED_Dump_Struct_End_Field (OStream, "TConcShortMsg16BitRefNum", "SeqNumber");
	ED_Dump_Struct_End (OStream, "TConcShortMsg16BitRefNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TTextFmt (TEDOStream* OStream, const c_TTextFmt* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TTextFmt");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Length");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Length);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Length");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Alignment");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Alignment> ACCESS=<Data->Alignment>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Alignment);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Alignment");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "FontSize");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<FontSize> ACCESS=<Data->FontSize>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->FontSize);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "FontSize");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Bold");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Bold> ACCESS=<Data->Bold>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Bold);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Bold");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Italic");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Italic> ACCESS=<Data->Italic>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Italic);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Italic");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Underlined");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Underlined> ACCESS=<Data->Underlined>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Underlined);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Underlined");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "Striketrhrough");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Striketrhrough> ACCESS=<Data->Striketrhrough>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Striketrhrough);
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "Striketrhrough");
	ED_Dump_Struct_Begin_Field (OStream, "TTextFmt", "TextColor");
	if (!Data->TextColor_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TextColor> ACCESS=<Data->TextColor>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TextColor);
	}
	ED_Dump_Struct_End_Field (OStream, "TTextFmt", "TextColor");
	ED_Dump_Struct_End (OStream, "TTextFmt");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TPredefSound (TEDOStream* OStream, const c_TPredefSound* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TPredefSound");
	ED_Dump_Struct_Begin_Field (OStream, "TPredefSound", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TPredefSound", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TPredefSound", "SoundNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SoundNumber> ACCESS=<Data->SoundNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SoundNumber);
	ED_Dump_Struct_End_Field (OStream, "TPredefSound", "SoundNumber");
	ED_Dump_Struct_End (OStream, "TPredefSound");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUserDefSound (TEDOStream* OStream, const c_TUserDefSound* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TUserDefSound");
	ED_Dump_Struct_Begin_Field (OStream, "TUserDefSound", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TUserDefSound", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TUserDefSound", "Sound");
	  /* NAME=<Sound> ACCESS=<Data->Sound>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Sound.value, Data->Sound.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TUserDefSound", "Sound");
	ED_Dump_Struct_End (OStream, "TUserDefSound");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TPredefAnim (TEDOStream* OStream, const c_TPredefAnim* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TPredefAnim");
	ED_Dump_Struct_Begin_Field (OStream, "TPredefAnim", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TPredefAnim", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TPredefAnim", "AnimationNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AnimationNumber> ACCESS=<Data->AnimationNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AnimationNumber);
	ED_Dump_Struct_End_Field (OStream, "TPredefAnim", "AnimationNumber");
	ED_Dump_Struct_End (OStream, "TPredefAnim");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TLargeAnim (TEDOStream* OStream, const c_TLargeAnim* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TLargeAnim");
	ED_Dump_Struct_Begin_Field (OStream, "TLargeAnim", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TLargeAnim", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TLargeAnim", "Animation");
	  /* NAME=<Animation> ACCESS=<Data->Animation>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Animation.value, Data->Animation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TLargeAnim", "Animation");
	ED_Dump_Struct_End (OStream, "TLargeAnim");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TSmallAnim (TEDOStream* OStream, const c_TSmallAnim* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TSmallAnim");
	ED_Dump_Struct_Begin_Field (OStream, "TSmallAnim", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TSmallAnim", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TSmallAnim", "Animation");
	  /* NAME=<Animation> ACCESS=<Data->Animation>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Animation.value, Data->Animation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TSmallAnim", "Animation");
	ED_Dump_Struct_End (OStream, "TSmallAnim");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TLargePict (TEDOStream* OStream, const c_TLargePict* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TLargePict");
	ED_Dump_Struct_Begin_Field (OStream, "TLargePict", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TLargePict", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TLargePict", "Picture");
	  /* NAME=<Picture> ACCESS=<Data->Picture>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Picture.value, Data->Picture.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TLargePict", "Picture");
	ED_Dump_Struct_End (OStream, "TLargePict");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TSmallPict (TEDOStream* OStream, const c_TSmallPict* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TSmallPict");
	ED_Dump_Struct_Begin_Field (OStream, "TSmallPict", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TSmallPict", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TSmallPict", "Picture");
	  /* NAME=<Picture> ACCESS=<Data->Picture>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Picture.value, Data->Picture.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TSmallPict", "Picture");
	ED_Dump_Struct_End (OStream, "TSmallPict");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TVarPict (TEDOStream* OStream, const c_TVarPict* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TVarPict");
	ED_Dump_Struct_Begin_Field (OStream, "TVarPict", "StartPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StartPosition> ACCESS=<Data->StartPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StartPosition);
	ED_Dump_Struct_End_Field (OStream, "TVarPict", "StartPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TVarPict", "HSize");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HSize> ACCESS=<Data->HSize>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->HSize);
	ED_Dump_Struct_End_Field (OStream, "TVarPict", "HSize");
	ED_Dump_Struct_Begin_Field (OStream, "TVarPict", "VSize");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VSize> ACCESS=<Data->VSize>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->VSize);
	ED_Dump_Struct_End_Field (OStream, "TVarPict", "VSize");
	ED_Dump_Struct_Begin_Field (OStream, "TVarPict", "Animation");
	  /* NAME=<Animation> ACCESS=<Data->Animation>  MAXBITSIZE=<1008> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Animation.value, Data->Animation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TVarPict", "Animation");
	ED_Dump_Struct_End (OStream, "TVarPict");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUserPromptInd (TEDOStream* OStream, const c_TUserPromptInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TUserPromptInd");
	ED_Dump_Struct_Begin_Field (OStream, "TUserPromptInd", "NumOfCorrespObj");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumOfCorrespObj> ACCESS=<Data->NumOfCorrespObj>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NumOfCorrespObj);
	ED_Dump_Struct_End_Field (OStream, "TUserPromptInd", "NumOfCorrespObj");
	ED_Dump_Struct_End (OStream, "TUserPromptInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TExtObj (TEDOStream* OStream, const c_TExtObj* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TExtObj");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "ExObjRefNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ExObjRefNum> ACCESS=<Data->ExObjRefNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ExObjRefNum);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "ExObjRefNum");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "Length");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Length);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "Length");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "DoNotForward");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DoNotForward> ACCESS=<Data->DoNotForward>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->DoNotForward);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "DoNotForward");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "UserPrompt");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UserPrompt> ACCESS=<Data->UserPrompt>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UserPrompt);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "UserPrompt");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "Reserved");
	  /* STRUCTURAL=<0> TYPE=<c_TExtObj_Reserved> NAME=<Reserved> ACCESS=<Data->Reserved>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "Reserved");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "ExObjType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ExObjType> ACCESS=<Data->ExObjType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ExObjType);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "ExObjType");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "ExObjPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<ExObjPosition> ACCESS=<Data->ExObjPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ExObjPosition);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "ExObjPosition");
	ED_Dump_Struct_Begin_Field (OStream, "TExtObj", "ExObjData");
	  /* NAME=<ExObjData> ACCESS=<Data->ExObjData>  MAXBITSIZE=<976> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->ExObjData.value, Data->ExObjData.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TExtObj", "ExObjData");
	ED_Dump_Struct_End (OStream, "TExtObj");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TReusedExtObj (TEDOStream* OStream, const c_TReusedExtObj* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TReusedExtObj");
	ED_Dump_Struct_Begin_Field (OStream, "TReusedExtObj", "RefNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RefNumber> ACCESS=<Data->RefNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RefNumber);
	ED_Dump_Struct_End_Field (OStream, "TReusedExtObj", "RefNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TReusedExtObj", "Position");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<Position> ACCESS=<Data->Position>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Position);
	ED_Dump_Struct_End_Field (OStream, "TReusedExtObj", "Position");
	ED_Dump_Struct_End (OStream, "TReusedExtObj");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TComprCtrl (TEDOStream* OStream, const c_TComprCtrl* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TComprCtrl");
	ED_Dump_Struct_Begin_Field (OStream, "TComprCtrl", "ComprAlgo");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ComprAlgo> ACCESS=<Data->ComprAlgo>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ComprAlgo);
	ED_Dump_Struct_End_Field (OStream, "TComprCtrl", "ComprAlgo");
	ED_Dump_Struct_Begin_Field (OStream, "TComprCtrl", "reserved");
	  /* STRUCTURAL=<0> TYPE=<c_TComprCtrl_reserved> NAME=<reserved> ACCESS=<Data->reserved>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TComprCtrl", "reserved");
	ED_Dump_Struct_Begin_Field (OStream, "TComprCtrl", "Length");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Length);
	ED_Dump_Struct_End_Field (OStream, "TComprCtrl", "Length");
	ED_Dump_Struct_Begin_Field (OStream, "TComprCtrl", "CompressedData");
	  /* NAME=<CompressedData> ACCESS=<Data->CompressedData>  MAXBITSIZE=<1008> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->CompressedData.value, Data->CompressedData.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TComprCtrl", "CompressedData");
	ED_Dump_Struct_End (OStream, "TComprCtrl");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TObjDistrInd (TEDOStream* OStream, const c_TObjDistrInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TObjDistrInd");
	ED_Dump_Struct_Begin_Field (OStream, "TObjDistrInd", "NumOfIEs");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumOfIEs> ACCESS=<Data->NumOfIEs>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NumOfIEs);
	ED_Dump_Struct_End_Field (OStream, "TObjDistrInd", "NumOfIEs");
	ED_Dump_Struct_Begin_Field (OStream, "TObjDistrInd", "DontForward");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DontForward> ACCESS=<Data->DontForward>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->DontForward);
	ED_Dump_Struct_End_Field (OStream, "TObjDistrInd", "DontForward");
	ED_Dump_Struct_Begin_Field (OStream, "TObjDistrInd", "reserved");
	  /* STRUCTURAL=<0> TYPE=<c_TObjDistrInd_reserved> NAME=<reserved> ACCESS=<Data->reserved>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TObjDistrInd", "reserved");
	ED_Dump_Struct_End (OStream, "TObjDistrInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TStdWvgObj (TEDOStream* OStream, const c_TStdWvgObj* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TStdWvgObj");
	ED_Dump_Struct_Begin_Field (OStream, "TStdWvgObj", "Position");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Position> ACCESS=<Data->Position>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Position);
	ED_Dump_Struct_End_Field (OStream, "TStdWvgObj", "Position");
	ED_Dump_Struct_Begin_Field (OStream, "TStdWvgObj", "Data");
	  /* NAME=<Data> ACCESS=<Data->Data>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Data.value, Data->Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TStdWvgObj", "Data");
	ED_Dump_Struct_End (OStream, "TStdWvgObj");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TCharSizeWvgObj (TEDOStream* OStream, const c_TCharSizeWvgObj* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TCharSizeWvgObj");
	ED_Dump_Struct_Begin_Field (OStream, "TCharSizeWvgObj", "Position");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Position> ACCESS=<Data->Position>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Position);
	ED_Dump_Struct_End_Field (OStream, "TCharSizeWvgObj", "Position");
	ED_Dump_Struct_Begin_Field (OStream, "TCharSizeWvgObj", "Data");
	  /* NAME=<Data> ACCESS=<Data->Data>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Data.value, Data->Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TCharSizeWvgObj", "Data");
	ED_Dump_Struct_End (OStream, "TCharSizeWvgObj");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRfc822EMailHdr (TEDOStream* OStream, const c_TRfc822EMailHdr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRfc822EMailHdr");
	ED_Dump_Struct_Begin_Field (OStream, "TRfc822EMailHdr", "Length");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Length);
	ED_Dump_Struct_End_Field (OStream, "TRfc822EMailHdr", "Length");
	ED_Dump_Struct_End (OStream, "TRfc822EMailHdr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_THyperlinkFmtElem (TEDOStream* OStream, const c_THyperlinkFmtElem* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "THyperlinkFmtElem");
	ED_Dump_Struct_Begin_Field (OStream, "THyperlinkFmtElem", "AbsElemPosition");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<AbsElemPosition> ACCESS=<Data->AbsElemPosition>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AbsElemPosition);
	ED_Dump_Struct_End_Field (OStream, "THyperlinkFmtElem", "AbsElemPosition");
	ED_Dump_Struct_Begin_Field (OStream, "THyperlinkFmtElem", "HyperLinkTitleLen");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HyperLinkTitleLen> ACCESS=<Data->HyperLinkTitleLen>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->HyperLinkTitleLen);
	ED_Dump_Struct_End_Field (OStream, "THyperlinkFmtElem", "HyperLinkTitleLen");
	ED_Dump_Struct_Begin_Field (OStream, "THyperlinkFmtElem", "URLLen");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<URLLen> ACCESS=<Data->URLLen>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->URLLen);
	ED_Dump_Struct_End_Field (OStream, "THyperlinkFmtElem", "URLLen");
	ED_Dump_Struct_End (OStream, "THyperlinkFmtElem");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUnknownIE (TEDOStream* OStream, const c_TUnknownIE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TUnknownIE");
	ED_Dump_Struct_Begin_Field (OStream, "TUnknownIE", "IEI");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<IEI> ACCESS=<Data->IEI>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->IEI);
	ED_Dump_Struct_End_Field (OStream, "TUnknownIE", "IEI");
	ED_Dump_Struct_Begin_Field (OStream, "TUnknownIE", "RawData");
	  /* NAME=<RawData> ACCESS=<Data->RawData>  MAXBITSIZE=<1024> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->RawData.value, Data->RawData.usedBits);
	ED_Dump_Struct_End_Field (OStream, "TUnknownIE", "RawData");
	ED_Dump_Struct_End (OStream, "TUnknownIE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TEnVoiceMailInfo (TEDOStream* OStream, const c_TEnVoiceMailInfo* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_TEnVoiceMailInfo_voiceMailNotification: {
		ED_Dump_Union_Begin (OStream, "TEnVoiceMailInfo", "voiceMailNotification");
		  /* STRUCTURAL=<0> TYPE=<c_TEnVoiceMailNotification> NAME=<voiceMailNotification> ACCESS=<*(Data->u.voiceMailNotification)>  OPTIONAL=<0> FUNC=<Dump_c_TEnVoiceMailNotification> */
		  Dump_c_TEnVoiceMailNotification (OStream, &(*(Data->u.voiceMailNotification)));
	ED_Dump_Union_End (OStream, "TEnVoiceMailInfo", "voiceMailNotification");
			break;
		}
	case U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation: {
		ED_Dump_Union_Begin (OStream, "TEnVoiceMailInfo", "voiceMailDeleteConfirmation");
		  /* STRUCTURAL=<0> TYPE=<c_TEnVoiceMailDeleteConfirmation> NAME=<voiceMailDeleteConfirmation> ACCESS=<*(Data->u.voiceMailDeleteConfirmation)>  OPTIONAL=<0> FUNC=<Dump_c_TEnVoiceMailDeleteConfirmation> */
		  Dump_c_TEnVoiceMailDeleteConfirmation (OStream, &(*(Data->u.voiceMailDeleteConfirmation)));
	ED_Dump_Union_End (OStream, "TEnVoiceMailInfo", "voiceMailDeleteConfirmation");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUserDataIEUnion (TEDOStream* OStream, const c_TUserDataIEUnion* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ConcShortMsgs8BitRefNum");
		  /* STRUCTURAL=<0> TYPE=<c_TConcShortMsgs8BitRefNum> NAME=<ConcShortMsgs8BitRefNum> ACCESS=<*(Data->u.ConcShortMsgs8BitRefNum)>  OPTIONAL=<0> FUNC=<Dump_c_TConcShortMsgs8BitRefNum> */
		  Dump_c_TConcShortMsgs8BitRefNum (OStream, &(*(Data->u.ConcShortMsgs8BitRefNum)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ConcShortMsgs8BitRefNum");
			break;
		}
	case U_c_TUserDataIEUnion_SpecialSmsMsgInd: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "SpecialSmsMsgInd");
		  /* STRUCTURAL=<0> TYPE=<c_TSpecialSmsMsgInd> NAME=<SpecialSmsMsgInd> ACCESS=<*(Data->u.SpecialSmsMsgInd)>  OPTIONAL=<0> FUNC=<Dump_c_TSpecialSmsMsgInd> */
		  Dump_c_TSpecialSmsMsgInd (OStream, &(*(Data->u.SpecialSmsMsgInd)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "SpecialSmsMsgInd");
			break;
		}
	case U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ApplPortAddrScheme8BitAddr");
		  /* STRUCTURAL=<0> TYPE=<c_TApplPortAddrScheme8BitAddr> NAME=<ApplPortAddrScheme8BitAddr> ACCESS=<*(Data->u.ApplPortAddrScheme8BitAddr)>  OPTIONAL=<0> FUNC=<Dump_c_TApplPortAddrScheme8BitAddr> */
		  Dump_c_TApplPortAddrScheme8BitAddr (OStream, &(*(Data->u.ApplPortAddrScheme8BitAddr)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ApplPortAddrScheme8BitAddr");
			break;
		}
	case U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ApplPortAddrScheme16BitAddr");
		  /* STRUCTURAL=<0> TYPE=<c_TApplPortAddrScheme16BitAddr> NAME=<ApplPortAddrScheme16BitAddr> ACCESS=<*(Data->u.ApplPortAddrScheme16BitAddr)>  OPTIONAL=<0> FUNC=<Dump_c_TApplPortAddrScheme16BitAddr> */
		  Dump_c_TApplPortAddrScheme16BitAddr (OStream, &(*(Data->u.ApplPortAddrScheme16BitAddr)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ApplPortAddrScheme16BitAddr");
			break;
		}
	case U_c_TUserDataIEUnion_SmscCtrlParams: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "SmscCtrlParams");
		  /* STRUCTURAL=<0> TYPE=<c_TSmscCtrlParams> NAME=<SmscCtrlParams> ACCESS=<*(Data->u.SmscCtrlParams)>  OPTIONAL=<0> FUNC=<Dump_c_TSmscCtrlParams> */
		  Dump_c_TSmscCtrlParams (OStream, &(*(Data->u.SmscCtrlParams)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "SmscCtrlParams");
			break;
		}
	case U_c_TUserDataIEUnion_UdhSrcInd: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "UdhSrcInd");
		  /* STRUCTURAL=<0> TYPE=<c_TUdhSrcInd> NAME=<UdhSrcInd> ACCESS=<*(Data->u.UdhSrcInd)>  OPTIONAL=<0> FUNC=<Dump_c_TUdhSrcInd> */
		  Dump_c_TUdhSrcInd (OStream, &(*(Data->u.UdhSrcInd)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "UdhSrcInd");
			break;
		}
	case U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ConcShortMsg16BitRefNum");
		  /* STRUCTURAL=<0> TYPE=<c_TConcShortMsg16BitRefNum> NAME=<ConcShortMsg16BitRefNum> ACCESS=<*(Data->u.ConcShortMsg16BitRefNum)>  OPTIONAL=<0> FUNC=<Dump_c_TConcShortMsg16BitRefNum> */
		  Dump_c_TConcShortMsg16BitRefNum (OStream, &(*(Data->u.ConcShortMsg16BitRefNum)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ConcShortMsg16BitRefNum");
			break;
		}
	case U_c_TUserDataIEUnion_WirelessCtrlMsgProto: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "WirelessCtrlMsgProto");
		  /* NAME=<WirelessCtrlMsgProto> ACCESS=<*(Data->u.WirelessCtrlMsgProto)>  MAXBITSIZE=<1024> OPTIONAL=<0> */
		  ED_Dump_Binary (OStream, Data->u.WirelessCtrlMsgProto->value, Data->u.WirelessCtrlMsgProto->usedBits);
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "WirelessCtrlMsgProto");
			break;
		}
	case U_c_TUserDataIEUnion_TextFmt: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "TextFmt");
		  /* STRUCTURAL=<0> TYPE=<c_TTextFmt> NAME=<TextFmt> ACCESS=<*(Data->u.TextFmt)>  OPTIONAL=<0> FUNC=<Dump_c_TTextFmt> */
		  Dump_c_TTextFmt (OStream, &(*(Data->u.TextFmt)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "TextFmt");
			break;
		}
	case U_c_TUserDataIEUnion_PredefSound: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "PredefSound");
		  /* STRUCTURAL=<0> TYPE=<c_TPredefSound> NAME=<PredefSound> ACCESS=<*(Data->u.PredefSound)>  OPTIONAL=<0> FUNC=<Dump_c_TPredefSound> */
		  Dump_c_TPredefSound (OStream, &(*(Data->u.PredefSound)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "PredefSound");
			break;
		}
	case U_c_TUserDataIEUnion_UserDefSound: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "UserDefSound");
		  /* STRUCTURAL=<0> TYPE=<c_TUserDefSound> NAME=<UserDefSound> ACCESS=<*(Data->u.UserDefSound)>  OPTIONAL=<0> FUNC=<Dump_c_TUserDefSound> */
		  Dump_c_TUserDefSound (OStream, &(*(Data->u.UserDefSound)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "UserDefSound");
			break;
		}
	case U_c_TUserDataIEUnion_PredefAnim: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "PredefAnim");
		  /* STRUCTURAL=<0> TYPE=<c_TPredefAnim> NAME=<PredefAnim> ACCESS=<*(Data->u.PredefAnim)>  OPTIONAL=<0> FUNC=<Dump_c_TPredefAnim> */
		  Dump_c_TPredefAnim (OStream, &(*(Data->u.PredefAnim)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "PredefAnim");
			break;
		}
	case U_c_TUserDataIEUnion_LargeAnim: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "LargeAnim");
		  /* STRUCTURAL=<0> TYPE=<c_TLargeAnim> NAME=<LargeAnim> ACCESS=<*(Data->u.LargeAnim)>  OPTIONAL=<0> FUNC=<Dump_c_TLargeAnim> */
		  Dump_c_TLargeAnim (OStream, &(*(Data->u.LargeAnim)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "LargeAnim");
			break;
		}
	case U_c_TUserDataIEUnion_SmallAnim: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "SmallAnim");
		  /* STRUCTURAL=<0> TYPE=<c_TSmallAnim> NAME=<SmallAnim> ACCESS=<*(Data->u.SmallAnim)>  OPTIONAL=<0> FUNC=<Dump_c_TSmallAnim> */
		  Dump_c_TSmallAnim (OStream, &(*(Data->u.SmallAnim)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "SmallAnim");
			break;
		}
	case U_c_TUserDataIEUnion_LargePict: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "LargePict");
		  /* STRUCTURAL=<0> TYPE=<c_TLargePict> NAME=<LargePict> ACCESS=<*(Data->u.LargePict)>  OPTIONAL=<0> FUNC=<Dump_c_TLargePict> */
		  Dump_c_TLargePict (OStream, &(*(Data->u.LargePict)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "LargePict");
			break;
		}
	case U_c_TUserDataIEUnion_SmallPict: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "SmallPict");
		  /* STRUCTURAL=<0> TYPE=<c_TSmallPict> NAME=<SmallPict> ACCESS=<*(Data->u.SmallPict)>  OPTIONAL=<0> FUNC=<Dump_c_TSmallPict> */
		  Dump_c_TSmallPict (OStream, &(*(Data->u.SmallPict)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "SmallPict");
			break;
		}
	case U_c_TUserDataIEUnion_VarPict: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "VarPict");
		  /* STRUCTURAL=<0> TYPE=<c_TVarPict> NAME=<VarPict> ACCESS=<*(Data->u.VarPict)>  OPTIONAL=<0> FUNC=<Dump_c_TVarPict> */
		  Dump_c_TVarPict (OStream, &(*(Data->u.VarPict)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "VarPict");
			break;
		}
	case U_c_TUserDataIEUnion_UserPromptInd: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "UserPromptInd");
		  /* STRUCTURAL=<0> TYPE=<c_TUserPromptInd> NAME=<UserPromptInd> ACCESS=<*(Data->u.UserPromptInd)>  OPTIONAL=<0> FUNC=<Dump_c_TUserPromptInd> */
		  Dump_c_TUserPromptInd (OStream, &(*(Data->u.UserPromptInd)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "UserPromptInd");
			break;
		}
	case U_c_TUserDataIEUnion_ExtObj: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ExtObj");
		  /* STRUCTURAL=<0> TYPE=<c_TExtObj> NAME=<ExtObj> ACCESS=<*(Data->u.ExtObj)>  OPTIONAL=<0> FUNC=<Dump_c_TExtObj> */
		  Dump_c_TExtObj (OStream, &(*(Data->u.ExtObj)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ExtObj");
			break;
		}
	case U_c_TUserDataIEUnion_ReusedExtObj: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ReusedExtObj");
		  /* STRUCTURAL=<0> TYPE=<c_TReusedExtObj> NAME=<ReusedExtObj> ACCESS=<*(Data->u.ReusedExtObj)>  OPTIONAL=<0> FUNC=<Dump_c_TReusedExtObj> */
		  Dump_c_TReusedExtObj (OStream, &(*(Data->u.ReusedExtObj)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ReusedExtObj");
			break;
		}
	case U_c_TUserDataIEUnion_ComprCtrl: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ComprCtrl");
		  /* STRUCTURAL=<0> TYPE=<c_TComprCtrl> NAME=<ComprCtrl> ACCESS=<*(Data->u.ComprCtrl)>  OPTIONAL=<0> FUNC=<Dump_c_TComprCtrl> */
		  Dump_c_TComprCtrl (OStream, &(*(Data->u.ComprCtrl)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ComprCtrl");
			break;
		}
	case U_c_TUserDataIEUnion_ObjDistrInd: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ObjDistrInd");
		  /* STRUCTURAL=<0> TYPE=<c_TObjDistrInd> NAME=<ObjDistrInd> ACCESS=<*(Data->u.ObjDistrInd)>  OPTIONAL=<0> FUNC=<Dump_c_TObjDistrInd> */
		  Dump_c_TObjDistrInd (OStream, &(*(Data->u.ObjDistrInd)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ObjDistrInd");
			break;
		}
	case U_c_TUserDataIEUnion_StdWvgObj: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "StdWvgObj");
		  /* STRUCTURAL=<0> TYPE=<c_TStdWvgObj> NAME=<StdWvgObj> ACCESS=<*(Data->u.StdWvgObj)>  OPTIONAL=<0> FUNC=<Dump_c_TStdWvgObj> */
		  Dump_c_TStdWvgObj (OStream, &(*(Data->u.StdWvgObj)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "StdWvgObj");
			break;
		}
	case U_c_TUserDataIEUnion_CharSizeWvgObj: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "CharSizeWvgObj");
		  /* STRUCTURAL=<0> TYPE=<c_TCharSizeWvgObj> NAME=<CharSizeWvgObj> ACCESS=<*(Data->u.CharSizeWvgObj)>  OPTIONAL=<0> FUNC=<Dump_c_TCharSizeWvgObj> */
		  Dump_c_TCharSizeWvgObj (OStream, &(*(Data->u.CharSizeWvgObj)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "CharSizeWvgObj");
			break;
		}
	case U_c_TUserDataIEUnion_ExtObjDataReqCmd: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ExtObjDataReqCmd");
		  /* STRUCTURAL=<0> TYPE=<c_TUserDataIEUnion_ExtObjDataReqCmd> NAME=<ExtObjDataReqCmd> ACCESS=<Data->u.ExtObjDataReqCmd>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
		  ED_Dump_Void_Present (OStream);
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ExtObjDataReqCmd");
			break;
		}
	case U_c_TUserDataIEUnion_Rfc822EMailHdr: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "Rfc822EMailHdr");
		  /* STRUCTURAL=<0> TYPE=<c_TRfc822EMailHdr> NAME=<Rfc822EMailHdr> ACCESS=<*(Data->u.Rfc822EMailHdr)>  OPTIONAL=<0> FUNC=<Dump_c_TRfc822EMailHdr> */
		  Dump_c_TRfc822EMailHdr (OStream, &(*(Data->u.Rfc822EMailHdr)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "Rfc822EMailHdr");
			break;
		}
	case U_c_TUserDataIEUnion_HyperlinkFmtElem: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "HyperlinkFmtElem");
		  /* STRUCTURAL=<0> TYPE=<c_THyperlinkFmtElem> NAME=<HyperlinkFmtElem> ACCESS=<*(Data->u.HyperlinkFmtElem)>  OPTIONAL=<0> FUNC=<Dump_c_THyperlinkFmtElem> */
		  Dump_c_THyperlinkFmtElem (OStream, &(*(Data->u.HyperlinkFmtElem)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "HyperlinkFmtElem");
			break;
		}
	case U_c_TUserDataIEUnion_ReplyAddrElem: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "ReplyAddrElem");
		  /* NAME=<ReplyAddrElem> ACCESS=<*(Data->u.ReplyAddrElem)>  MAXBITSIZE=<1024> OPTIONAL=<0> */
		  ED_Dump_Binary (OStream, Data->u.ReplyAddrElem->value, Data->u.ReplyAddrElem->usedBits);
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "ReplyAddrElem");
			break;
		}
	case U_c_TUserDataIEUnion_EnVoiceMailInfo: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "EnVoiceMailInfo");
		  /* STRUCTURAL=<0> TYPE=<c_TEnVoiceMailInfo> NAME=<EnVoiceMailInfo> ACCESS=<*(Data->u.EnVoiceMailInfo)>  OPTIONAL=<0> FUNC=<Dump_c_TEnVoiceMailInfo> */
		  Dump_c_TEnVoiceMailInfo (OStream, &(*(Data->u.EnVoiceMailInfo)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "EnVoiceMailInfo");
			break;
		}
	case U_c_TUserDataIEUnion_NationalLangSingleShift: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "NationalLangSingleShift");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NationalLangSingleShift> ACCESS=<Data->u.NationalLangSingleShift>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->u.NationalLangSingleShift);
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "NationalLangSingleShift");
			break;
		}
	case U_c_TUserDataIEUnion_NationalLangLockingShift: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "NationalLangLockingShift");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NationalLangLockingShift> ACCESS=<Data->u.NationalLangLockingShift>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->u.NationalLangLockingShift);
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "NationalLangLockingShift");
			break;
		}
	case U_c_TUserDataIEUnion_UnknownIE: {
		ED_Dump_Union_Begin (OStream, "TUserDataIEUnion", "UnknownIE");
		  /* STRUCTURAL=<0> TYPE=<c_TUnknownIE> NAME=<UnknownIE> ACCESS=<*(Data->u.UnknownIE)>  OPTIONAL=<0> FUNC=<Dump_c_TUnknownIE> */
		  Dump_c_TUnknownIE (OStream, &(*(Data->u.UnknownIE)));
	ED_Dump_Union_End (OStream, "TUserDataIEUnion", "UnknownIE");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TUserDataIE (TEDOStream* OStream, const c_TUserDataIE* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<20> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_TUserDataIEUnion> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_TUserDataIEUnion> */
	  Dump_c_TUserDataIEUnion (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TTimeStamp (TEDOStream* OStream, const c_TTimeStamp* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TTimeStamp");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Year");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Year> ACCESS=<Data->Year>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Year);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Year");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Month");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Month> ACCESS=<Data->Month>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Month);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Month");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Day");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Day> ACCESS=<Data->Day>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Day);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Day");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Hour");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Hour> ACCESS=<Data->Hour>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Hour);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Hour");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Minute");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Minute> ACCESS=<Data->Minute>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Minute);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Minute");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "Second");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Second> ACCESS=<Data->Second>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Second);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "Second");
	ED_Dump_Struct_Begin_Field (OStream, "TTimeStamp", "TimeZone");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimeZone> ACCESS=<Data->TimeZone>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TimeZone);
	ED_Dump_Struct_End_Field (OStream, "TTimeStamp", "TimeZone");
	ED_Dump_Struct_End (OStream, "TTimeStamp");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_PI (TEDOStream* OStream, const c_TP_PI* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PI", "Extension");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extension> ACCESS=<Data->Extension>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extension);
	ED_Dump_Struct_End_Field (OStream, "TP_PI", "Extension");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PI", "Reserved");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Reserved> ACCESS=<Data->Reserved>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Reserved);
	ED_Dump_Struct_End_Field (OStream, "TP_PI", "Reserved");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PI", "TP_UDL");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDL> ACCESS=<Data->TP_UDL>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDL);
	ED_Dump_Struct_End_Field (OStream, "TP_PI", "TP_UDL");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PI", "TP_DCS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_DCS> ACCESS=<Data->TP_DCS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_DCS);
	ED_Dump_Struct_End_Field (OStream, "TP_PI", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PI", "TP_PID");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_PID> ACCESS=<Data->TP_PID>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_PID);
	ED_Dump_Struct_End_Field (OStream, "TP_PI", "TP_PID");
	ED_Dump_Struct_End (OStream, "TP_PI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_PID (TEDOStream* OStream, const c_TP_PID* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PID", "PIDType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PIDType> ACCESS=<Data->PIDType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PIDType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Assigns bits 0..5 as defined below 0"); break;
				case 1: OStream->WriteString (OStream, "Assigns bits 0..5 as defined below 1"); break;
				case 10: OStream->WriteString (OStream, "reserved"); break;
				case 11: OStream->WriteString (OStream, "Assigns bits 0 5 for SC specific use"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_PID", "PIDType");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PID", "TelematicInterneworking");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TelematicInterneworking> ACCESS=<Data->TelematicInterneworking>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->TelematicInterneworking)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no interworking, but SME to SME protocol"); break;
				case 1: OStream->WriteString (OStream, "telematic interworking"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_PID", "TelematicInterneworking");
	ED_Dump_Struct_Begin_Field (OStream, "TP_PID", "TelematicInterneworkingType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TelematicInterneworkingType> ACCESS=<Data->TelematicInterneworkingType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TelematicInterneworkingType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "implicit device type is specific to this SC, or can be concluded on the basis of the address"); break;
				case 1: OStream->WriteString (OStream, "telex (or teletex reduced to telex format)"); break;
				case 10: OStream->WriteString (OStream, "group 3 telefax"); break;
				case 11: OStream->WriteString (OStream, "group 4 telefax"); break;
				case 100: OStream->WriteString (OStream, "voice telephone (i.e. conversion to speech)"); break;
				case 101: OStream->WriteString (OStream, "ERMES (European Radio Messaging System)"); break;
				case 110: OStream->WriteString (OStream, "National Paging system (known to the SC)"); break;
				case 111: OStream->WriteString (OStream, "Videotex (T.100 [20] /T.101 [21])"); break;
				case 1000: OStream->WriteString (OStream, "teletex, carrier unspecified"); break;
				case 1001: OStream->WriteString (OStream, "teletex, in PSPDN"); break;
				case 1010: OStream->WriteString (OStream, "teletex, in CSPDN"); break;
				case 1011: OStream->WriteString (OStream, "teletex, in analog PSTN"); break;
				case 1100: OStream->WriteString (OStream, "teletex, in digital ISDN"); break;
				case 1101: OStream->WriteString (OStream, "UCI (Universal Computer Interface, ETSI DE/PS 3 01 3)"); break;
				case 10000: OStream->WriteString (OStream, "a message handling facility (known to the SC)"); break;
				case 10001: OStream->WriteString (OStream, "any public X.400 based message handling system"); break;
				case 10010: OStream->WriteString (OStream, "nternet Electronic Mail"); break;
				case 11000: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11001: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11010: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11011: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11100: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11101: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				case 11110: OStream->WriteString (OStream, "value specific to each SC, usage based on mutual agreement between the SME and the SC"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_PID", "TelematicInterneworkingType");
	ED_Dump_Struct_End (OStream, "TP_PID");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_DCS (TEDOStream* OStream, const c_TP_DCS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "RawData");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RawData> ACCESS=<Data->RawData>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->RawData);
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "RawData");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "Content");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<Content> ACCESS=<Data->Content>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->Content)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "General Coding Indication"); break;
				case 4: OStream->WriteString (OStream, "Message Marked for Automatic Deletion Group"); break;
				case 12: OStream->WriteString (OStream, "Message Waiting Indication Group: Discard Message"); break;
				case 13: OStream->WriteString (OStream, "Message Waiting Indication Group: Store Message"); break;
				case 14: OStream->WriteString (OStream, "Message Waiting Indication Group: Store Message UCS-2"); break;
				case 15: OStream->WriteString (OStream, "Data coding/message class"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "Content");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "Compressed");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Compressed> ACCESS=<Data->Compressed>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Compressed);
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "Compressed");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "MessageClass");
	if (!Data->MessageClass_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MessageClass> ACCESS=<Data->MessageClass>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MessageClass);
	}
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "MessageClass");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "CharSet");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<CharSet> ACCESS=<Data->CharSet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->CharSet)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM 7 bit default alphabet"); break;
				case 1: OStream->WriteString (OStream, "8 bit data"); break;
				case 2: OStream->WriteString (OStream, "UCS2 (16 bit)"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "CharSet");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "SetIndicationActive");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SetIndicationActive> ACCESS=<Data->SetIndicationActive>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SetIndicationActive);
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "SetIndicationActive");
	ED_Dump_Struct_Begin_Field (OStream, "TP_DCS", "IndicationType");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<IndicationType> ACCESS=<Data->IndicationType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->IndicationType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Voicemail Message Waiting"); break;
				case 1: OStream->WriteString (OStream, "Fax Message Waiting"); break;
				case 2: OStream->WriteString (OStream, "Electronic Mail Message Waiting"); break;
				case 3: OStream->WriteString (OStream, "Other Message Waiting"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_DCS", "IndicationType");
	ED_Dump_Struct_End (OStream, "TP_DCS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_VP (TEDOStream* OStream, const c_TP_VP* Data)
{
	int i0;
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_TP_VP_Relative: {
		ED_Dump_Union_Begin (OStream, "TP_VP", "Relative");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Relative> ACCESS=<Data->u.Relative>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->u.Relative);
	ED_Dump_Union_End (OStream, "TP_VP", "Relative");
			break;
		}
	case U_c_TP_VP_Absolute: {
		ED_Dump_Union_Begin (OStream, "TP_VP", "Absolute");
			/* SEQUENCE NAME=<Absolute> ACCESS=<*(Data->u.Absolute)>  ITEMS=<14> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "Absolute", 14);
			for (i0=0; i0<14; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "Absolute", i0, 14);
			  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<Absolute> ACCESS=<Data->u.Absolute [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->u.Absolute [i0]);
				ED_Dump_Sequence_End_Field (OStream, "Absolute", i0, 14);
			}
			ED_Dump_Sequence_End (OStream, "Absolute", 14);
	ED_Dump_Union_End (OStream, "TP_VP", "Absolute");
			break;
		}
	case U_c_TP_VP_Enhanced: {
		ED_Dump_Union_Begin (OStream, "TP_VP", "Enhanced");
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "TP_VP_Enhanced");
			ED_Dump_Struct_Begin_Field (OStream, "TP_VP_Enhanced", "SingleShotSM");
			  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SingleShotSM> ACCESS=<Data->u.Enhanced->SingleShotSM>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
			  ED_Dump_Boolean (OStream, Data->u.Enhanced->SingleShotSM);
			ED_Dump_Struct_End_Field (OStream, "TP_VP_Enhanced", "SingleShotSM");
			ED_Dump_Struct_Begin_Field (OStream, "TP_VP_Enhanced", "ValidityPeriodFormat");
			  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<ValidityPeriodFormat> ACCESS=<Data->u.Enhanced->ValidityPeriodFormat>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
			  ED_Dump_Integer (OStream, Data->u.Enhanced->ValidityPeriodFormat);
			ED_Dump_Struct_End_Field (OStream, "TP_VP_Enhanced", "ValidityPeriodFormat");
			ED_Dump_Struct_Begin_Field (OStream, "TP_VP_Enhanced", "Extension");
			  /* UNION ACCESS=<Data->u.Enhanced->Extension> */
				switch (Data->u.Enhanced->Extension.Present) {
				case U_c_TP_VP_Enhanced_Extension_NoValidityPeriod: {
					ED_Dump_Union_Begin (OStream, "TP_VP_Enhanced_Extension", "NoValidityPeriod");
					  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NoValidityPeriod> ACCESS=<Data->u.Enhanced->Extension.u.NoValidityPeriod>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
					  ED_Dump_Boolean (OStream, Data->u.Enhanced->Extension.u.NoValidityPeriod);
				ED_Dump_Union_End (OStream, "TP_VP_Enhanced_Extension", "NoValidityPeriod");
						break;
					}
				case U_c_TP_VP_Enhanced_Extension_Relative: {
					ED_Dump_Union_Begin (OStream, "TP_VP_Enhanced_Extension", "Relative");
					  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Relative> ACCESS=<Data->u.Enhanced->Extension.u.Relative>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
					  ED_Dump_Octet (OStream, Data->u.Enhanced->Extension.u.Relative);
				ED_Dump_Union_End (OStream, "TP_VP_Enhanced_Extension", "Relative");
						break;
					}
				case U_c_TP_VP_Enhanced_Extension_RelativeInteger: {
					ED_Dump_Union_Begin (OStream, "TP_VP_Enhanced_Extension", "RelativeInteger");
					  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RelativeInteger> ACCESS=<Data->u.Enhanced->Extension.u.RelativeInteger>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
					  ED_Dump_Octet (OStream, Data->u.Enhanced->Extension.u.RelativeInteger);
				ED_Dump_Union_End (OStream, "TP_VP_Enhanced_Extension", "RelativeInteger");
						break;
					}
				case U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet: {
					ED_Dump_Union_Begin (OStream, "TP_VP_Enhanced_Extension", "RelativeSemiOctet");
						/* SEQUENCE NAME=<RelativeSemiOctet> ACCESS=<*(Data->u.Enhanced->Extension.u.RelativeSemiOctet)>  ITEMS=<6> OPTIONAL=<0> */
						ED_Dump_Sequence_Begin (OStream, "RelativeSemiOctet", 6);
						for (i0=0; i0<6; i0++) {
							ED_Dump_Sequence_Begin_Field (OStream, "RelativeSemiOctet", i0, 6);
						  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<RelativeSemiOctet> ACCESS=<Data->u.Enhanced->Extension.u.RelativeSemiOctet [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->u.Enhanced->Extension.u.RelativeSemiOctet [i0]);
							ED_Dump_Sequence_End_Field (OStream, "RelativeSemiOctet", i0, 6);
						}
						ED_Dump_Sequence_End (OStream, "RelativeSemiOctet", 6);
				ED_Dump_Union_End (OStream, "TP_VP_Enhanced_Extension", "RelativeSemiOctet");
						break;
					}
				case U_c_TP_VP_Enhanced_Extension_UnknownExtension: {
					ED_Dump_Union_Begin (OStream, "TP_VP_Enhanced_Extension", "UnknownExtension");
					  /* STRUCT */
						ED_Dump_Struct_Begin (OStream, "TP_VP_Enhanced_Extension_UnknownExtension");
						ED_Dump_Struct_Begin_Field (OStream, "TP_VP_Enhanced_Extension_UnknownExtension", "ExtensionBit");
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ExtensionBit> ACCESS=<Data->u.Enhanced->Extension.u.UnknownExtension->ExtensionBit>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->u.Enhanced->Extension.u.UnknownExtension->ExtensionBit);
						ED_Dump_Struct_End_Field (OStream, "TP_VP_Enhanced_Extension_UnknownExtension", "ExtensionBit");
						ED_Dump_Struct_Begin_Field (OStream, "TP_VP_Enhanced_Extension_UnknownExtension", "UnknownOctets");
							/* SEQUENCE NAME=<UnknownOctets> ACCESS=<Data->u.Enhanced->Extension.u.UnknownExtension->UnknownOctets>  ITEMS=<6> OPTIONAL=<0> */
							ED_Dump_Sequence_Begin (OStream, "UnknownOctets", 6);
							for (i0=0; i0<6; i0++) {
								ED_Dump_Sequence_Begin_Field (OStream, "UnknownOctets", i0, 6);
							  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<UnknownOctets> ACCESS=<Data->u.Enhanced->Extension.u.UnknownExtension->UnknownOctets [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->u.Enhanced->Extension.u.UnknownExtension->UnknownOctets [i0]);
								ED_Dump_Sequence_End_Field (OStream, "UnknownOctets", i0, 6);
							}
							ED_Dump_Sequence_End (OStream, "UnknownOctets", 6);
						ED_Dump_Struct_End_Field (OStream, "TP_VP_Enhanced_Extension_UnknownExtension", "UnknownOctets");
						ED_Dump_Struct_End (OStream, "TP_VP_Enhanced_Extension_UnknownExtension");
				ED_Dump_Union_End (OStream, "TP_VP_Enhanced_Extension", "UnknownExtension");
						break;
					}
				default:;
			}
			ED_Dump_Struct_End_Field (OStream, "TP_VP_Enhanced", "Extension");
			ED_Dump_Struct_End (OStream, "TP_VP_Enhanced");
	ED_Dump_Union_End (OStream, "TP_VP", "Enhanced");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_CD (TEDOStream* OStream, const c_TP_CD* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<157> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->data [i0]);
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_UD (TEDOStream* OStream, const c_TP_UD* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "TP_UD", "Header");
	  /* STRUCTURAL=<0> TYPE=<c_TUserDataIE> NAME=<Header> ACCESS=<Data->Header>  OPTIONAL=<0> FUNC=<Dump_c_TUserDataIE> */
	  Dump_c_TUserDataIE (OStream, &(Data->Header));
	ED_Dump_Struct_End_Field (OStream, "TP_UD", "Header");
	ED_Dump_Struct_Begin_Field (OStream, "TP_UD", "Message");
		/* SEQUENCE NAME=<Message> ACCESS=<Data->Message>  ITEMS=<160> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Message", Data->Message.items);
		for (i0=0; i0<Data->Message.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Message", i0, Data->Message.items);
		  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->Message.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->Message.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "Message", i0, Data->Message.items);
		}
		ED_Dump_Sequence_End (OStream, "Message", Data->Message.items);
	ED_Dump_Struct_End_Field (OStream, "TP_UD", "Message");
	ED_Dump_Struct_Begin_Field (OStream, "TP_UD", "CharSet");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<CharSet> ACCESS=<Data->CharSet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->CharSet)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM 7 bit default alphabet"); break;
				case 1: OStream->WriteString (OStream, "8 bit data"); break;
				case 2: OStream->WriteString (OStream, "UCS2 (16bit)"); break;
				case 3: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TP_UD", "CharSet");
	ED_Dump_Struct_End (OStream, "TP_UD");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TP_MTI (TEDOStream* OStream, const c_TP_MTI* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TP_MTI");
	ED_Dump_Struct_Begin_Field (OStream, "TP_MTI", "TP_MTI");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TP_MTI> ACCESS=<Data->TP_MTI>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_MTI);
	ED_Dump_Struct_End_Field (OStream, "TP_MTI", "TP_MTI");
	ED_Dump_Struct_End (OStream, "TP_MTI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_UNKNOWN (TEDOStream* OStream, const c_SMS_UNKNOWN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_UNKNOWN");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_UNKNOWN", "UnknownSMSData");
	  /* NAME=<UnknownSMSData> ACCESS=<Data->UnknownSMSData>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->UnknownSMSData.value, Data->UnknownSMSData.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_UNKNOWN", "UnknownSMSData");
	ED_Dump_Struct_End (OStream, "SMS_UNKNOWN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_DELIVER (TEDOStream* OStream, const c_SMS_DELIVER* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_DELIVER");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_MMS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_MMS> ACCESS=<Data->TP_MMS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_MMS);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_MMS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_LO");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_LO> ACCESS=<Data->TP_LO>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_LO);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_LO");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_RP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_RP> ACCESS=<Data->TP_RP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_RP);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_RP");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_SRI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_SRI> ACCESS=<Data->TP_SRI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_SRI);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_SRI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_OA");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<TP_OA> ACCESS=<Data->TP_OA>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->TP_OA));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_OA");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_PID");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<Data->TP_PID>  OPTIONAL=<0> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(Data->TP_PID));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_DCS");
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<Data->TP_DCS>  OPTIONAL=<0> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(Data->TP_DCS));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_SCTS");
	  /* STRUCTURAL=<0> TYPE=<c_TTimeStamp> NAME=<TP_SCTS> ACCESS=<Data->TP_SCTS>  OPTIONAL=<0> FUNC=<Dump_c_TTimeStamp> */
	  Dump_c_TTimeStamp (OStream, &(Data->TP_SCTS));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_SCTS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "TP_UD");
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<Data->TP_UD>  OPTIONAL=<0> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(Data->TP_UD));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVER", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVER", "spare");
	ED_Dump_Struct_End (OStream, "SMS_DELIVER");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_STATUS_REPORT (TEDOStream* OStream, const c_SMS_STATUS_REPORT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_STATUS_REPORT");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_LO");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_LO> ACCESS=<Data->TP_LO>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_LO);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_LO");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_MMS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_MMS> ACCESS=<Data->TP_MMS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_MMS);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_MMS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_SRQ");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_SRQ> ACCESS=<Data->TP_SRQ>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_SRQ);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_SRQ");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_MR");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_MR> ACCESS=<Data->TP_MR>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_MR);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_MR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_RA");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<TP_RA> ACCESS=<Data->TP_RA>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->TP_RA));
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_RA");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_SCTS");
	  /* STRUCTURAL=<0> TYPE=<c_TTimeStamp> NAME=<TP_SCTS> ACCESS=<Data->TP_SCTS>  OPTIONAL=<0> FUNC=<Dump_c_TTimeStamp> */
	  Dump_c_TTimeStamp (OStream, &(Data->TP_SCTS));
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_SCTS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_DT");
	  /* STRUCTURAL=<0> TYPE=<c_TTimeStamp> NAME=<TP_DT> ACCESS=<Data->TP_DT>  OPTIONAL=<0> FUNC=<Dump_c_TTimeStamp> */
	  Dump_c_TTimeStamp (OStream, &(Data->TP_DT));
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_DT");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_ST");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_ST> ACCESS=<Data->TP_ST>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TP_ST);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_ST");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_PI");
	if (!Data->TP_PI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PI> NAME=<TP_PI> ACCESS=<*(Data->TP_PI)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PI> */
	  Dump_c_TP_PI (OStream, &(*(Data->TP_PI)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_PID");
	if (!Data->TP_PID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<*(Data->TP_PID)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(*(Data->TP_PID)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_DCS");
	if (!Data->TP_DCS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<*(Data->TP_DCS)>  OPTIONAL=<1> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(*(Data->TP_DCS)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "TP_UD");
	if (!Data->TP_UD_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<*(Data->TP_UD)>  OPTIONAL=<1> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(*(Data->TP_UD)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_STATUS_REPORT", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_STATUS_REPORT", "spare");
	ED_Dump_Struct_End (OStream, "SMS_STATUS_REPORT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SUBMIT (TEDOStream* OStream, const c_SMS_SUBMIT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_SUBMIT");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_RD");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_RD> ACCESS=<Data->TP_RD>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_RD);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_RD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_VPF");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_VPF> ACCESS=<Data->TP_VPF>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_VPF);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_VPF");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_RP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_RP> ACCESS=<Data->TP_RP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_RP);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_RP");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_SRR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_SRR> ACCESS=<Data->TP_SRR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_SRR);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_SRR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_MR");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_MR> ACCESS=<Data->TP_MR>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_MR);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_MR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_DA");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<TP_DA> ACCESS=<Data->TP_DA>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->TP_DA));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_DA");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_PID");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<Data->TP_PID>  OPTIONAL=<0> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(Data->TP_PID));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_DCS");
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<Data->TP_DCS>  OPTIONAL=<0> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(Data->TP_DCS));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_VP");
	if (!Data->TP_VP_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_VP> NAME=<TP_VP> ACCESS=<*(Data->TP_VP)>  OPTIONAL=<1> FUNC=<Dump_c_TP_VP> */
	  Dump_c_TP_VP (OStream, &(*(Data->TP_VP)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_VP");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "TP_UD");
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<Data->TP_UD>  OPTIONAL=<0> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(Data->TP_UD));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT", "spare");
	ED_Dump_Struct_End (OStream, "SMS_SUBMIT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_COMMAND (TEDOStream* OStream, const c_SMS_COMMAND* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_COMMAND");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_SRR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_SRR> ACCESS=<Data->TP_SRR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_SRR);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_SRR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_MR");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_MR> ACCESS=<Data->TP_MR>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_MR);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_MR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_PID");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<Data->TP_PID>  OPTIONAL=<0> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(Data->TP_PID));
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_CT");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_CT> ACCESS=<Data->TP_CT>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TP_CT);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_CT");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_MN");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_MN> ACCESS=<Data->TP_MN>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TP_MN);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_MN");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_DA");
	  /* STRUCTURAL=<0> TYPE=<c_TAddress> NAME=<TP_DA> ACCESS=<Data->TP_DA>  OPTIONAL=<0> FUNC=<Dump_c_TAddress> */
	  Dump_c_TAddress (OStream, &(Data->TP_DA));
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_DA");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "TP_CD");
	  /* STRUCTURAL=<0> TYPE=<c_TP_CD> NAME=<TP_CD> ACCESS=<Data->TP_CD>  OPTIONAL=<0> FUNC=<Dump_c_TP_CD> */
	  Dump_c_TP_CD (OStream, &(Data->TP_CD));
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "TP_CD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_COMMAND", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_COMMAND", "spare");
	ED_Dump_Struct_End (OStream, "SMS_COMMAND");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TRPCause (TEDOStream* OStream, const c_TRPCause* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TRPCause");
	ED_Dump_Struct_Begin_Field (OStream, "TRPCause", "Cause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Cause);
	ED_Dump_Struct_End_Field (OStream, "TRPCause", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "TRPCause", "Diagnostic");
	if (!Data->Diagnostic_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Diagnostic> ACCESS=<Data->Diagnostic>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Diagnostic);
	}
	ED_Dump_Struct_End_Field (OStream, "TRPCause", "Diagnostic");
	ED_Dump_Struct_End (OStream, "TRPCause");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_T24011Address (TEDOStream* OStream, const c_T24011Address* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "T24011Address");
	ED_Dump_Struct_Begin_Field (OStream, "T24011Address", "Addr");
	if (!Data->Addr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "T24011Address_Addr");
		ED_Dump_Struct_Begin_Field (OStream, "T24011Address_Addr", "TypeOfNumber");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfNumber> ACCESS=<Data->Addr->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Addr->TypeOfNumber);
		ED_Dump_Struct_End_Field (OStream, "T24011Address_Addr", "TypeOfNumber");
		ED_Dump_Struct_Begin_Field (OStream, "T24011Address_Addr", "NumPlanId");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumPlanId> ACCESS=<Data->Addr->NumPlanId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Addr->NumPlanId);
		ED_Dump_Struct_End_Field (OStream, "T24011Address_Addr", "NumPlanId");
		ED_Dump_Struct_Begin_Field (OStream, "T24011Address_Addr", "Address");
			/* SEQUENCE NAME=<Address> ACCESS=<Data->Addr->Address>  ITEMS=<20> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "Address", Data->Addr->Address.items);
			for (i0=0; i0<Data->Addr->Address.items; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "Address", i0, Data->Addr->Address.items);
			  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Addr->Address.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->Addr->Address.data [i0]);
				ED_Dump_Sequence_End_Field (OStream, "Address", i0, Data->Addr->Address.items);
			}
			ED_Dump_Sequence_End (OStream, "Address", Data->Addr->Address.items);
		ED_Dump_Struct_End_Field (OStream, "T24011Address_Addr", "Address");
		ED_Dump_Struct_End (OStream, "T24011Address_Addr");
	}
	ED_Dump_Struct_End_Field (OStream, "T24011Address", "Addr");
	ED_Dump_Struct_End (OStream, "T24011Address");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_MS2SC (TEDOStream* OStream, const c_SMS_MS2SC* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_MS2SC_SMS_SUBMIT: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC", "SMS_SUBMIT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_SUBMIT> NAME=<SMS_SUBMIT> ACCESS=<*(Data->u.SMS_SUBMIT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_SUBMIT> */
		  Dump_c_SMS_SUBMIT (OStream, &(*(Data->u.SMS_SUBMIT)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC", "SMS_SUBMIT");
			break;
		}
	case U_c_SMS_MS2SC_SMS_COMMAND: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC", "SMS_COMMAND");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_COMMAND> NAME=<SMS_COMMAND> ACCESS=<*(Data->u.SMS_COMMAND)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_COMMAND> */
		  Dump_c_SMS_COMMAND (OStream, &(*(Data->u.SMS_COMMAND)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC", "SMS_COMMAND");
			break;
		}
	case U_c_SMS_MS2SC_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SC2MS (TEDOStream* OStream, const c_SMS_SC2MS* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_SC2MS_SMS_DELIVER: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS", "SMS_DELIVER");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_DELIVER> NAME=<SMS_DELIVER> ACCESS=<*(Data->u.SMS_DELIVER)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_DELIVER> */
		  Dump_c_SMS_DELIVER (OStream, &(*(Data->u.SMS_DELIVER)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS", "SMS_DELIVER");
			break;
		}
	case U_c_SMS_SC2MS_SMS_STATUS_REPORT: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS", "SMS_STATUS_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_STATUS_REPORT> NAME=<SMS_STATUS_REPORT> ACCESS=<*(Data->u.SMS_STATUS_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_STATUS_REPORT> */
		  Dump_c_SMS_STATUS_REPORT (OStream, &(*(Data->u.SMS_STATUS_REPORT)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS", "SMS_STATUS_REPORT");
			break;
		}
	case U_c_SMS_SC2MS_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_MS2SC_ERR (TEDOStream* OStream, const c_SMS_MS2SC_ERR* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC_ERR", "SMS_STATUS_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_STATUS_REPORT> NAME=<SMS_STATUS_REPORT> ACCESS=<*(Data->u.SMS_STATUS_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_STATUS_REPORT> */
		  Dump_c_SMS_STATUS_REPORT (OStream, &(*(Data->u.SMS_STATUS_REPORT)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC_ERR", "SMS_STATUS_REPORT");
			break;
		}
	case U_c_SMS_MS2SC_ERR_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC_ERR", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC_ERR", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_MS2SC_ACK (TEDOStream* OStream, const c_SMS_MS2SC_ACK* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC_ACK", "SMS_STATUS_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_STATUS_REPORT> NAME=<SMS_STATUS_REPORT> ACCESS=<*(Data->u.SMS_STATUS_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_STATUS_REPORT> */
		  Dump_c_SMS_STATUS_REPORT (OStream, &(*(Data->u.SMS_STATUS_REPORT)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC_ACK", "SMS_STATUS_REPORT");
			break;
		}
	case U_c_SMS_MS2SC_ACK_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_MS2SC_ACK", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_MS2SC_ACK", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SC2MS_ERR (TEDOStream* OStream, const c_SMS_SC2MS_ERR* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS_ERR", "SMS_STATUS_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_STATUS_REPORT> NAME=<SMS_STATUS_REPORT> ACCESS=<*(Data->u.SMS_STATUS_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_STATUS_REPORT> */
		  Dump_c_SMS_STATUS_REPORT (OStream, &(*(Data->u.SMS_STATUS_REPORT)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS_ERR", "SMS_STATUS_REPORT");
			break;
		}
	case U_c_SMS_SC2MS_ERR_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS_ERR", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS_ERR", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SC2MS_ACK (TEDOStream* OStream, const c_SMS_SC2MS_ACK* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS_ACK", "SMS_STATUS_REPORT");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_STATUS_REPORT> NAME=<SMS_STATUS_REPORT> ACCESS=<*(Data->u.SMS_STATUS_REPORT)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_STATUS_REPORT> */
		  Dump_c_SMS_STATUS_REPORT (OStream, &(*(Data->u.SMS_STATUS_REPORT)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS_ACK", "SMS_STATUS_REPORT");
			break;
		}
	case U_c_SMS_SC2MS_ACK_SMS_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "SMS_SC2MS_ACK", "SMS_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_SMS_UNKNOWN> NAME=<SMS_UNKNOWN> ACCESS=<*(Data->u.SMS_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_SMS_UNKNOWN> */
		  Dump_c_SMS_UNKNOWN (OStream, &(*(Data->u.SMS_UNKNOWN)));
	ED_Dump_Union_End (OStream, "SMS_SC2MS_ACK", "SMS_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_UNKNOWN (TEDOStream* OStream, const c_RP_UNKNOWN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_UNKNOWN");
	ED_Dump_Struct_Begin_Field (OStream, "RP_UNKNOWN", "MessageType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MessageType> ACCESS=<Data->MessageType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MessageType);
	ED_Dump_Struct_End_Field (OStream, "RP_UNKNOWN", "MessageType");
	ED_Dump_Struct_Begin_Field (OStream, "RP_UNKNOWN", "TransportedData");
	  /* NAME=<TransportedData> ACCESS=<Data->TransportedData>  MAXBITSIZE=<1992> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TransportedData.value, Data->TransportedData.usedBits);
	ED_Dump_Struct_End_Field (OStream, "RP_UNKNOWN", "TransportedData");
	ED_Dump_Struct_End (OStream, "RP_UNKNOWN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_DATA_MSC2MS (TEDOStream* OStream, const c_RP_DATA_MSC2MS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_DATA_MSC2MS");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MSC2MS", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MSC2MS", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MSC2MS", "RP_OriginatorAddress");
	  /* STRUCTURAL=<0> TYPE=<c_T24011Address> NAME=<RP_OriginatorAddress> ACCESS=<Data->RP_OriginatorAddress>  OPTIONAL=<0> FUNC=<Dump_c_T24011Address> */
	  Dump_c_T24011Address (OStream, &(Data->RP_OriginatorAddress));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MSC2MS", "RP_OriginatorAddress");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MSC2MS", "RP_DestinationAddress");
	  /* STRUCTURAL=<0> TYPE=<c_T24011Address> NAME=<RP_DestinationAddress> ACCESS=<Data->RP_DestinationAddress>  OPTIONAL=<0> FUNC=<Dump_c_T24011Address> */
	  Dump_c_T24011Address (OStream, &(Data->RP_DestinationAddress));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MSC2MS", "RP_DestinationAddress");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MSC2MS", "RP_UserData");
	  /* STRUCTURAL=<0> TYPE=<c_SMS_SC2MS> NAME=<RP_UserData> ACCESS=<Data->RP_UserData>  OPTIONAL=<0> FUNC=<Dump_c_SMS_SC2MS> */
	  Dump_c_SMS_SC2MS (OStream, &(Data->RP_UserData));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MSC2MS", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_DATA_MSC2MS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_RP_ACK_MSC2MS (TEDOStream* OStream, const c_RP_RP_ACK_MSC2MS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_RP_ACK_MSC2MS");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ACK_MSC2MS", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ACK_MSC2MS", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ACK_MSC2MS", "RP_UserData");
	if (!Data->RP_UserData_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SMS_SC2MS_ACK> NAME=<RP_UserData> ACCESS=<*(Data->RP_UserData)>  OPTIONAL=<1> FUNC=<Dump_c_SMS_SC2MS_ACK> */
	  Dump_c_SMS_SC2MS_ACK (OStream, &(*(Data->RP_UserData)));
	}
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ACK_MSC2MS", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_RP_ACK_MSC2MS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_RP_ERROR_MSC2MS (TEDOStream* OStream, const c_RP_RP_ERROR_MSC2MS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_RP_ERROR_MSC2MS");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_Cause");
	  /* STRUCTURAL=<0> TYPE=<c_TRPCause> NAME=<RP_Cause> ACCESS=<Data->RP_Cause>  OPTIONAL=<0> FUNC=<Dump_c_TRPCause> */
	  Dump_c_TRPCause (OStream, &(Data->RP_Cause));
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_UserData");
	if (!Data->RP_UserData_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SMS_SC2MS_ERR> NAME=<RP_UserData> ACCESS=<*(Data->RP_UserData)>  OPTIONAL=<1> FUNC=<Dump_c_SMS_SC2MS_ERR> */
	  Dump_c_SMS_SC2MS_ERR (OStream, &(*(Data->RP_UserData)));
	}
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MSC2MS", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_RP_ERROR_MSC2MS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_DATA_MS2MSC (TEDOStream* OStream, const c_RP_DATA_MS2MSC* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_DATA_MS2MSC");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MS2MSC", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MS2MSC", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MS2MSC", "RP_OriginatorAddress");
	  /* STRUCTURAL=<0> TYPE=<c_T24011Address> NAME=<RP_OriginatorAddress> ACCESS=<Data->RP_OriginatorAddress>  OPTIONAL=<0> FUNC=<Dump_c_T24011Address> */
	  Dump_c_T24011Address (OStream, &(Data->RP_OriginatorAddress));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MS2MSC", "RP_OriginatorAddress");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MS2MSC", "RP_DestinationAddress");
	  /* STRUCTURAL=<0> TYPE=<c_T24011Address> NAME=<RP_DestinationAddress> ACCESS=<Data->RP_DestinationAddress>  OPTIONAL=<0> FUNC=<Dump_c_T24011Address> */
	  Dump_c_T24011Address (OStream, &(Data->RP_DestinationAddress));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MS2MSC", "RP_DestinationAddress");
	ED_Dump_Struct_Begin_Field (OStream, "RP_DATA_MS2MSC", "RP_UserData");
	  /* STRUCTURAL=<0> TYPE=<c_SMS_MS2SC> NAME=<RP_UserData> ACCESS=<Data->RP_UserData>  OPTIONAL=<0> FUNC=<Dump_c_SMS_MS2SC> */
	  Dump_c_SMS_MS2SC (OStream, &(Data->RP_UserData));
	ED_Dump_Struct_End_Field (OStream, "RP_DATA_MS2MSC", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_DATA_MS2MSC");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_RP_SMMA_MS2MSC (TEDOStream* OStream, const c_RP_RP_SMMA_MS2MSC* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_RP_SMMA_MS2MSC");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_SMMA_MS2MSC", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_RP_SMMA_MS2MSC", "RP_MessageReference");
	ED_Dump_Struct_End (OStream, "RP_RP_SMMA_MS2MSC");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_RP_ACK_MS2MSC (TEDOStream* OStream, const c_RP_RP_ACK_MS2MSC* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_RP_ACK_MS2MSC");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ACK_MS2MSC", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ACK_MS2MSC", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ACK_MS2MSC", "RP_UserData");
	if (!Data->RP_UserData_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SMS_MS2SC_ACK> NAME=<RP_UserData> ACCESS=<*(Data->RP_UserData)>  OPTIONAL=<1> FUNC=<Dump_c_SMS_MS2SC_ACK> */
	  Dump_c_SMS_MS2SC_ACK (OStream, &(*(Data->RP_UserData)));
	}
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ACK_MS2MSC", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_RP_ACK_MS2MSC");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RP_RP_ERROR_MS2MSC (TEDOStream* OStream, const c_RP_RP_ERROR_MS2MSC* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RP_RP_ERROR_MS2MSC");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_MessageReference");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RP_MessageReference> ACCESS=<Data->RP_MessageReference>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RP_MessageReference);
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_MessageReference");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_Cause");
	  /* STRUCTURAL=<0> TYPE=<c_TRPCause> NAME=<RP_Cause> ACCESS=<Data->RP_Cause>  OPTIONAL=<0> FUNC=<Dump_c_TRPCause> */
	  Dump_c_TRPCause (OStream, &(Data->RP_Cause));
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_UserData");
	if (!Data->RP_UserData_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SMS_MS2SC_ERR> NAME=<RP_UserData> ACCESS=<*(Data->RP_UserData)>  OPTIONAL=<1> FUNC=<Dump_c_SMS_MS2SC_ERR> */
	  Dump_c_SMS_MS2SC_ERR (OStream, &(*(Data->RP_UserData)));
	}
	ED_Dump_Struct_End_Field (OStream, "RP_RP_ERROR_MS2MSC", "RP_UserData");
	ED_Dump_Struct_End (OStream, "RP_RP_ERROR_MS2MSC");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CPUserData (TEDOStream* OStream, const c_CPUserData* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_CPUserData_RP_DATA_MSC2MS: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_DATA_MSC2MS");
		  /* STRUCTURAL=<0> TYPE=<c_RP_DATA_MSC2MS> NAME=<RP_DATA_MSC2MS> ACCESS=<*(Data->u.RP_DATA_MSC2MS)>  OPTIONAL=<0> FUNC=<Dump_c_RP_DATA_MSC2MS> */
		  Dump_c_RP_DATA_MSC2MS (OStream, &(*(Data->u.RP_DATA_MSC2MS)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_DATA_MSC2MS");
			break;
		}
	case U_c_CPUserData_RP_DATA_MS2MSC: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_DATA_MS2MSC");
		  /* STRUCTURAL=<0> TYPE=<c_RP_DATA_MS2MSC> NAME=<RP_DATA_MS2MSC> ACCESS=<*(Data->u.RP_DATA_MS2MSC)>  OPTIONAL=<0> FUNC=<Dump_c_RP_DATA_MS2MSC> */
		  Dump_c_RP_DATA_MS2MSC (OStream, &(*(Data->u.RP_DATA_MS2MSC)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_DATA_MS2MSC");
			break;
		}
	case U_c_CPUserData_RP_RP_SMMA_MS2MSC: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_RP_SMMA_MS2MSC");
		  /* STRUCTURAL=<0> TYPE=<c_RP_RP_SMMA_MS2MSC> NAME=<RP_RP_SMMA_MS2MSC> ACCESS=<*(Data->u.RP_RP_SMMA_MS2MSC)>  OPTIONAL=<0> FUNC=<Dump_c_RP_RP_SMMA_MS2MSC> */
		  Dump_c_RP_RP_SMMA_MS2MSC (OStream, &(*(Data->u.RP_RP_SMMA_MS2MSC)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_RP_SMMA_MS2MSC");
			break;
		}
	case U_c_CPUserData_RP_RP_ACK_MS2MSC: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_RP_ACK_MS2MSC");
		  /* STRUCTURAL=<0> TYPE=<c_RP_RP_ACK_MS2MSC> NAME=<RP_RP_ACK_MS2MSC> ACCESS=<*(Data->u.RP_RP_ACK_MS2MSC)>  OPTIONAL=<0> FUNC=<Dump_c_RP_RP_ACK_MS2MSC> */
		  Dump_c_RP_RP_ACK_MS2MSC (OStream, &(*(Data->u.RP_RP_ACK_MS2MSC)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_RP_ACK_MS2MSC");
			break;
		}
	case U_c_CPUserData_RP_RP_ACK_MSC2MS: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_RP_ACK_MSC2MS");
		  /* STRUCTURAL=<0> TYPE=<c_RP_RP_ACK_MSC2MS> NAME=<RP_RP_ACK_MSC2MS> ACCESS=<*(Data->u.RP_RP_ACK_MSC2MS)>  OPTIONAL=<0> FUNC=<Dump_c_RP_RP_ACK_MSC2MS> */
		  Dump_c_RP_RP_ACK_MSC2MS (OStream, &(*(Data->u.RP_RP_ACK_MSC2MS)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_RP_ACK_MSC2MS");
			break;
		}
	case U_c_CPUserData_RP_RP_ERROR_MS2MSC: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_RP_ERROR_MS2MSC");
		  /* STRUCTURAL=<0> TYPE=<c_RP_RP_ERROR_MS2MSC> NAME=<RP_RP_ERROR_MS2MSC> ACCESS=<*(Data->u.RP_RP_ERROR_MS2MSC)>  OPTIONAL=<0> FUNC=<Dump_c_RP_RP_ERROR_MS2MSC> */
		  Dump_c_RP_RP_ERROR_MS2MSC (OStream, &(*(Data->u.RP_RP_ERROR_MS2MSC)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_RP_ERROR_MS2MSC");
			break;
		}
	case U_c_CPUserData_RP_RP_ERROR_MSC2MS: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_RP_ERROR_MSC2MS");
		  /* STRUCTURAL=<0> TYPE=<c_RP_RP_ERROR_MSC2MS> NAME=<RP_RP_ERROR_MSC2MS> ACCESS=<*(Data->u.RP_RP_ERROR_MSC2MS)>  OPTIONAL=<0> FUNC=<Dump_c_RP_RP_ERROR_MSC2MS> */
		  Dump_c_RP_RP_ERROR_MSC2MS (OStream, &(*(Data->u.RP_RP_ERROR_MSC2MS)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_RP_ERROR_MSC2MS");
			break;
		}
	case U_c_CPUserData_RP_UNKNOWN: {
		ED_Dump_Union_Begin (OStream, "CPUserData", "RP_UNKNOWN");
		  /* STRUCTURAL=<0> TYPE=<c_RP_UNKNOWN> NAME=<RP_UNKNOWN> ACCESS=<*(Data->u.RP_UNKNOWN)>  OPTIONAL=<0> FUNC=<Dump_c_RP_UNKNOWN> */
		  Dump_c_RP_UNKNOWN (OStream, &(*(Data->u.RP_UNKNOWN)));
	ED_Dump_Union_End (OStream, "CPUserData", "RP_UNKNOWN");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CP_DATA (TEDOStream* OStream, const c_CP_DATA* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CP_DATA");
	ED_Dump_Struct_Begin_Field (OStream, "CP_DATA", "CPUserData");
	  /* STRUCTURAL=<0> TYPE=<c_CPUserData> NAME=<CPUserData> ACCESS=<Data->CPUserData>  OPTIONAL=<0> FUNC=<Dump_c_CPUserData> */
	  Dump_c_CPUserData (OStream, &(Data->CPUserData));
	ED_Dump_Struct_End_Field (OStream, "CP_DATA", "CPUserData");
	ED_Dump_Struct_End (OStream, "CP_DATA");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CP_ACK (TEDOStream* OStream, const c_CP_ACK* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CP_ACK");
	ED_Dump_Struct_End (OStream, "CP_ACK");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CP_ERROR (TEDOStream* OStream, const c_CP_ERROR* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CP_ERROR");
	ED_Dump_Struct_Begin_Field (OStream, "CP_ERROR", "CPCause");
	  /* NAME=<CPCause> ACCESS=<Data->CPCause>  MAXBITSIZE=<8> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->CPCause, 8);
	ED_Dump_Struct_End_Field (OStream, "CP_ERROR", "CPCause");
	ED_Dump_Struct_End (OStream, "CP_ERROR");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SUBMIT_REPORT_RP_ERROR (TEDOStream* OStream, const c_SMS_SUBMIT_REPORT_RP_ERROR* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_SUBMIT_REPORT_RP_ERROR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_FCS");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_FCS> ACCESS=<Data->TP_FCS>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_FCS);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_FCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_PI");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PI> NAME=<TP_PI> ACCESS=<Data->TP_PI>  OPTIONAL=<0> FUNC=<Dump_c_TP_PI> */
	  Dump_c_TP_PI (OStream, &(Data->TP_PI));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_SCTS");
	  /* STRUCTURAL=<0> TYPE=<c_TTimeStamp> NAME=<TP_SCTS> ACCESS=<Data->TP_SCTS>  OPTIONAL=<0> FUNC=<Dump_c_TTimeStamp> */
	  Dump_c_TTimeStamp (OStream, &(Data->TP_SCTS));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_SCTS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_PID");
	if (!Data->TP_PID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<*(Data->TP_PID)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(*(Data->TP_PID)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_DCS");
	if (!Data->TP_DCS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<*(Data->TP_DCS)>  OPTIONAL=<1> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(*(Data->TP_DCS)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_UD");
	if (!Data->TP_UD_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<*(Data->TP_UD)>  OPTIONAL=<1> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(*(Data->TP_UD)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ERROR", "spare");
	ED_Dump_Struct_End (OStream, "SMS_SUBMIT_REPORT_RP_ERROR");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_SUBMIT_REPORT_RP_ACK (TEDOStream* OStream, const c_SMS_SUBMIT_REPORT_RP_ACK* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_SUBMIT_REPORT_RP_ACK");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_PI");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PI> NAME=<TP_PI> ACCESS=<Data->TP_PI>  OPTIONAL=<0> FUNC=<Dump_c_TP_PI> */
	  Dump_c_TP_PI (OStream, &(Data->TP_PI));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_SCTS");
	  /* STRUCTURAL=<0> TYPE=<c_TTimeStamp> NAME=<TP_SCTS> ACCESS=<Data->TP_SCTS>  OPTIONAL=<0> FUNC=<Dump_c_TTimeStamp> */
	  Dump_c_TTimeStamp (OStream, &(Data->TP_SCTS));
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_SCTS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_PID");
	if (!Data->TP_PID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<*(Data->TP_PID)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(*(Data->TP_PID)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_DCS");
	if (!Data->TP_DCS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<*(Data->TP_DCS)>  OPTIONAL=<1> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(*(Data->TP_DCS)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_UD");
	if (!Data->TP_UD_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<*(Data->TP_UD)>  OPTIONAL=<1> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(*(Data->TP_UD)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_SUBMIT_REPORT_RP_ACK", "spare");
	ED_Dump_Struct_End (OStream, "SMS_SUBMIT_REPORT_RP_ACK");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_DELIVERY_REPORT_RP_ERROR (TEDOStream* OStream, const c_SMS_DELIVERY_REPORT_RP_ERROR* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_DELIVERY_REPORT_RP_ERROR");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_FCS");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TP_FCS> ACCESS=<Data->TP_FCS>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TP_FCS);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_FCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_PI");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PI> NAME=<TP_PI> ACCESS=<Data->TP_PI>  OPTIONAL=<0> FUNC=<Dump_c_TP_PI> */
	  Dump_c_TP_PI (OStream, &(Data->TP_PI));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_PID");
	if (!Data->TP_PID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<*(Data->TP_PID)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(*(Data->TP_PID)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_DCS");
	if (!Data->TP_DCS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<*(Data->TP_DCS)>  OPTIONAL=<1> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(*(Data->TP_DCS)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_UD");
	if (!Data->TP_UD_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<*(Data->TP_UD)>  OPTIONAL=<1> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(*(Data->TP_UD)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ERROR", "spare");
	ED_Dump_Struct_End (OStream, "SMS_DELIVERY_REPORT_RP_ERROR");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMS_DELIVERY_REPORT_RP_ACK (TEDOStream* OStream, const c_SMS_DELIVERY_REPORT_RP_ACK* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMS_DELIVERY_REPORT_RP_ACK");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "header");
	  /* STRUCTURAL=<0> TYPE=<c_TP_MTI> NAME=<header> ACCESS=<Data->header>  OPTIONAL=<0> FUNC=<Dump_c_TP_MTI> */
	  Dump_c_TP_MTI (OStream, &(Data->header));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "header");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_UDHI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TP_UDHI> ACCESS=<Data->TP_UDHI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TP_UDHI);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_UDHI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_PI");
	  /* STRUCTURAL=<0> TYPE=<c_TP_PI> NAME=<TP_PI> ACCESS=<Data->TP_PI>  OPTIONAL=<0> FUNC=<Dump_c_TP_PI> */
	  Dump_c_TP_PI (OStream, &(Data->TP_PI));
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_PI");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_PID");
	if (!Data->TP_PID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_PID> NAME=<TP_PID> ACCESS=<*(Data->TP_PID)>  OPTIONAL=<1> FUNC=<Dump_c_TP_PID> */
	  Dump_c_TP_PID (OStream, &(*(Data->TP_PID)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_PID");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_DCS");
	if (!Data->TP_DCS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_DCS> NAME=<TP_DCS> ACCESS=<*(Data->TP_DCS)>  OPTIONAL=<1> FUNC=<Dump_c_TP_DCS> */
	  Dump_c_TP_DCS (OStream, &(*(Data->TP_DCS)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_DCS");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_UD");
	if (!Data->TP_UD_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TP_UD> NAME=<TP_UD> ACCESS=<*(Data->TP_UD)>  OPTIONAL=<1> FUNC=<Dump_c_TP_UD> */
	  Dump_c_TP_UD (OStream, &(*(Data->TP_UD)));
	}
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "TP_UD");
	ED_Dump_Struct_Begin_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "spare");
	  /* NAME=<spare> ACCESS=<Data->spare>  MAXBITSIZE=<1864> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->spare.value, Data->spare.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SMS_DELIVERY_REPORT_RP_ACK", "spare");
	ED_Dump_Struct_End (OStream, "SMS_DELIVERY_REPORT_RP_ACK");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GenericTLV_SMS (TEDOStream* OStream, const c_GenericTLV_SMS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GenericTLV_SMS");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_SMS", "TLV_Tag");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TLV_Tag> ACCESS=<Data->TLV_Tag>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TLV_Tag);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_SMS", "TLV_Tag");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_SMS", "TLV_Data");
	  /* NAME=<TLV_Data> ACCESS=<Data->TLV_Data>  MAXBITSIZE=<8192> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TLV_Data.value, Data->TLV_Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_SMS", "TLV_Data");
	ED_Dump_Struct_End (OStream, "GenericTLV_SMS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_CM_CP (TEDOStream* OStream, const TCM_CP_Data* Data)
{
	switch (Data->Type) {
		case ID_CM_CP_CP_DATA: Dump_c_CP_DATA (OStream, Data->Data.fld_c_CP_DATA); break;
		case ID_CM_CP_CP_ACK: Dump_c_CP_ACK (OStream, Data->Data.fld_c_CP_ACK); break;
		case ID_CM_CP_CP_ERROR: Dump_c_CP_ERROR (OStream, Data->Data.fld_c_CP_ERROR); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_MSC2MS (TEDOStream* OStream, const TMSC2MS_Data* Data)
{
	switch (Data->Type) {
		case ID_MSC2MS_RP_DATA_MSC2MS: Dump_c_RP_DATA_MSC2MS (OStream, Data->Data.fld_c_RP_DATA_MSC2MS); break;
		case ID_MSC2MS_RP_RP_ACK_MSC2MS: Dump_c_RP_RP_ACK_MSC2MS (OStream, Data->Data.fld_c_RP_RP_ACK_MSC2MS); break;
		case ID_MSC2MS_RP_RP_ERROR_MSC2MS: Dump_c_RP_RP_ERROR_MSC2MS (OStream, Data->Data.fld_c_RP_RP_ERROR_MSC2MS); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_MS2MSC (TEDOStream* OStream, const TMS2MSC_Data* Data)
{
	switch (Data->Type) {
		case ID_MS2MSC_RP_DATA_MS2MSC: Dump_c_RP_DATA_MS2MSC (OStream, Data->Data.fld_c_RP_DATA_MS2MSC); break;
		case ID_MS2MSC_RP_RP_SMMA_MS2MSC: Dump_c_RP_RP_SMMA_MS2MSC (OStream, Data->Data.fld_c_RP_RP_SMMA_MS2MSC); break;
		case ID_MS2MSC_RP_RP_ACK_MS2MSC: Dump_c_RP_RP_ACK_MS2MSC (OStream, Data->Data.fld_c_RP_RP_ACK_MS2MSC); break;
		case ID_MS2MSC_RP_RP_ERROR_MS2MSC: Dump_c_RP_RP_ERROR_MS2MSC (OStream, Data->Data.fld_c_RP_RP_ERROR_MS2MSC); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_SC2MS (TEDOStream* OStream, const TSC2MS_Data* Data)
{
	switch (Data->Type) {
		case ID_SC2MS_SMS_DELIVER: Dump_c_SMS_DELIVER (OStream, Data->Data.fld_c_SMS_DELIVER); break;
		case ID_SC2MS_SMS_STATUS_REPORT: Dump_c_SMS_STATUS_REPORT (OStream, Data->Data.fld_c_SMS_STATUS_REPORT); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_SC2MS_ERR (TEDOStream* OStream, const TSC2MS_ERR_Data* Data)
{
	switch (Data->Type) {
		case ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR: Dump_c_SMS_SUBMIT_REPORT_RP_ERROR (OStream, Data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_SC2MS_ACK (TEDOStream* OStream, const TSC2MS_ACK_Data* Data)
{
	switch (Data->Type) {
		case ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK: Dump_c_SMS_SUBMIT_REPORT_RP_ACK (OStream, Data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_MS2SC (TEDOStream* OStream, const TMS2SC_Data* Data)
{
	switch (Data->Type) {
		case ID_MS2SC_SMS_SUBMIT: Dump_c_SMS_SUBMIT (OStream, Data->Data.fld_c_SMS_SUBMIT); break;
		case ID_MS2SC_SMS_COMMAND: Dump_c_SMS_COMMAND (OStream, Data->Data.fld_c_SMS_COMMAND); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_MS2SC_ERR (TEDOStream* OStream, const TMS2SC_ERR_Data* Data)
{
	switch (Data->Type) {
		case ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR: Dump_c_SMS_DELIVERY_REPORT_RP_ERROR (OStream, Data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_MS2SC_ACK (TEDOStream* OStream, const TMS2SC_ACK_Data* Data)
{
	switch (Data->Type) {
		case ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK: Dump_c_SMS_DELIVERY_REPORT_RP_ACK (OStream, Data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK); break;
		default:;
	}
}
