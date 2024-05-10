/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_SMS_h_H
#define __ed_c_SMS_h_H

#include "ed_dynamic.h"
#include "ed_data.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#ifndef ED_HAS_ACCESS_LOCATOR
#define ED_HAS_ACCESS_LOCATOR
#endif
#ifndef ED_DOT
#define ED_DOT ->
#endif
#ifndef ED_AMP
#define ED_AMP(a) a
#endif
#define ED_DYNAMIC_DEFAULT 1

#ifdef __cplusplus
extern "C" {
#endif


/* Access member 'TypeOfNumber' of type 'c_TAddress' as a variable reference */
#define VAR_c_TAddress_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_TAddress' as a pointer */
#define PTR_c_TAddress_TypeOfNumber(var) (&var)

/* Access member 'NumPlanId' of type 'c_TAddress' as a variable reference */
#define VAR_c_TAddress_NumPlanId(var) var

/* Access member 'NumPlanId' of type 'c_TAddress' as a pointer */
#define PTR_c_TAddress_NumPlanId(var) (&var)

/* Access member 'data' of type 'c_TAddress_Address' as a variable reference */
#define VAR_c_TAddress_Address_data(var) var

/* Access member 'data' of type 'c_TAddress_Address' as a pointer */
#define PTR_c_TAddress_Address_data(var) (&var)

/* Access member 'Address' of type 'c_TAddress' as a variable reference */
#define VAR_c_TAddress_Address(var) var

/* Access member 'Address' of type 'c_TAddress' as a pointer */
#define PTR_c_TAddress_Address(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_TAddress_Address */
typedef struct _c_TAddress_Address {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-3195=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TAddress_Address;


/*-A----------------------------------*/
typedef struct _c_TAddress {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumPlanId___LOCATOR; /* QUI2 */

	ED_LONG TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_LONG NumPlanId; /* ODY01a *//*GBD01b*/
	c_TAddress_Address Address;/*GFB09*//*GBD01b*/

}	c_TAddress;
#define INIT_c_TAddress(sp) ED_RESET_MEM ((sp), sizeof (c_TAddress))
/*FRK03a*/
void FREE_c_TAddress(c_TAddress* sp);

/* Access member 'VM_MESSAGE_ID' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_ID(var) var

/* Access member 'VM_MESSAGE_ID' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_ID(var) (&var)

/* Access member 'VM_MESSAGE_LENGTH' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_LENGTH(var) var

/* Access member 'VM_MESSAGE_LENGTH' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_LENGTH(var) (&var)

/* Access member 'VM_MESSAGE_RETENTION_DAYS' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_RETENTION_DAYS(var) var

/* Access member 'VM_MESSAGE_RETENTION_DAYS' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_RETENTION_DAYS(var) (&var)

/* Access member 'VM_MESSAGE_PRIORITY_INDICATION' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_PRIORITY_INDICATION(var) var

/* Access member 'VM_MESSAGE_PRIORITY_INDICATION' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_PRIORITY_INDICATION(var) (&var)

/* Access member 'VM_MESSAGE_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_INDICATOR(var) var

/* Access member 'VM_MESSAGE_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_INDICATOR(var) (&var)

/* Access member 'VM_MESSAGE_CALLING_LINE_IDENTITY' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_CALLING_LINE_IDENTITY(var) var

/* Access member 'VM_MESSAGE_CALLING_LINE_IDENTITY' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_CALLING_LINE_IDENTITY(var) (&var)

/* Access member 'VM_MESSAGE_EXTENSION_DATA' of type 'c_TEnVoiceMailNotificationItem' as a variable reference */
#define VAR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA(var) var

/* Access member 'VM_MESSAGE_EXTENSION_DATA' of type 'c_TEnVoiceMailNotificationItem' as a pointer */
#define PTR_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA(var) (&var)

/* DEFINITION OF BINARY c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA */
typedef struct _c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TEnVoiceMailNotificationItem {
	ED_LOCATOR VM_MESSAGE_ID___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_LENGTH___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_RETENTION_DAYS___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_PRIORITY_INDICATION___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_EXTENSION_INDICATOR___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_EXTENSION_DATA___LOCATOR  /*LBD02*/;

	ED_LONG VM_MESSAGE_ID; /* ODY01a *//*GBD01b*/
	ED_OCTET VM_MESSAGE_LENGTH; /* ODY01a *//*GBD01b*/
	ED_OCTET VM_MESSAGE_RETENTION_DAYS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MESSAGE_PRIORITY_INDICATION; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MESSAGE_EXTENSION_INDICATOR; /* ODY01a *//*GBD01b*/
	c_TAddress VM_MESSAGE_CALLING_LINE_IDENTITY; /* ODY01a *//*GBD01b*/
	c_TEnVoiceMailNotificationItem_VM_MESSAGE_EXTENSION_DATA VM_MESSAGE_EXTENSION_DATA; /* Static, variable size; bits needed 2040 *//*GBD01b*/

}	c_TEnVoiceMailNotificationItem;
#define INIT_c_TEnVoiceMailNotificationItem(sp) ED_RESET_MEM ((sp), sizeof (c_TEnVoiceMailNotificationItem))
/*FRK03a*/
void FREE_c_TEnVoiceMailNotificationItem(c_TEnVoiceMailNotificationItem* sp);

/* Access member 'VM_MESSAGE_ID' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_ID(var) var

/* Access member 'VM_MESSAGE_ID' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_ID(var) (&var)

/* Access member 'VM_MESSAGE_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_INDICATOR(var) var

/* Access member 'VM_MESSAGE_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_INDICATOR(var) (&var)

/* Access member 'VM_MESSAGE_EXTENSION_DATA' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA(var) var

/* Access member 'VM_MESSAGE_EXTENSION_DATA' of type 'c_TEnVoiceMailDeleteConfirmationItem' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA(var) (&var)

/* DEFINITION OF BINARY c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA */
typedef struct _c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TEnVoiceMailDeleteConfirmationItem {
	ED_LOCATOR VM_MESSAGE_ID___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_EXTENSION_INDICATOR___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MESSAGE_EXTENSION_DATA___LOCATOR  /*LBD02*/;

	ED_LONG VM_MESSAGE_ID; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MESSAGE_EXTENSION_INDICATOR; /* ODY01a *//*GBD01b*/
	c_TEnVoiceMailDeleteConfirmationItem_VM_MESSAGE_EXTENSION_DATA VM_MESSAGE_EXTENSION_DATA; /* Static, variable size; bits needed 2040 *//*GBD01b*/

}	c_TEnVoiceMailDeleteConfirmationItem;
#define INIT_c_TEnVoiceMailDeleteConfirmationItem(sp) ED_RESET_MEM ((sp), sizeof (c_TEnVoiceMailDeleteConfirmationItem))
/*FRK03a*/
void FREE_c_TEnVoiceMailDeleteConfirmationItem(c_TEnVoiceMailDeleteConfirmationItem* sp);

/* Access member 'ENHANCED_VOICE_MAIL_PDU_TYPE' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_ENHANCED_VOICE_MAIL_PDU_TYPE(var) var

/* Access member 'ENHANCED_VOICE_MAIL_PDU_TYPE' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_ENHANCED_VOICE_MAIL_PDU_TYPE(var) (&var)

/* Access member 'MULTIPLE_SUBSCRIBER_PROFILE' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_MULTIPLE_SUBSCRIBER_PROFILE(var) var

/* Access member 'MULTIPLE_SUBSCRIBER_PROFILE' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_MULTIPLE_SUBSCRIBER_PROFILE(var) (&var)

/* Access member 'SM_STORAGE' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_SM_STORAGE(var) var

/* Access member 'SM_STORAGE' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_SM_STORAGE(var) (&var)

/* Access member 'VM_MAILBOX_ALMOST_FULL' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_MAILBOX_ALMOST_FULL(var) var

/* Access member 'VM_MAILBOX_ALMOST_FULL' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_MAILBOX_ALMOST_FULL(var) (&var)

/* Access member 'VM_MAILBOX_FULL' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_MAILBOX_FULL(var) var

/* Access member 'VM_MAILBOX_FULL' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_MAILBOX_FULL(var) (&var)

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_INDICATOR(var) var

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_INDICATOR(var) (&var)

/* Access member 'VM_MAILBOX_ACCESS_ADDRESS' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_MAILBOX_ACCESS_ADDRESS(var) var

/* Access member 'VM_MAILBOX_ACCESS_ADDRESS' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_MAILBOX_ACCESS_ADDRESS(var) (&var)

/* Access member 'NUMBER_OF_VOICE_MESSAGES' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_NUMBER_OF_VOICE_MESSAGES(var) var

/* Access member 'NUMBER_OF_VOICE_MESSAGES' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_NUMBER_OF_VOICE_MESSAGES(var) (&var)

/* Access member 'NUMBER_OF_VM_NOTIFICATIONS' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_NUMBER_OF_VM_NOTIFICATIONS(var) var

/* Access member 'NUMBER_OF_VM_NOTIFICATIONS' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_NUMBER_OF_VM_NOTIFICATIONS(var) (&var)

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_DATA' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA(var) var

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_DATA' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA(var) (&var)

/* Access member 'data' of type 'c_TEnVoiceMailNotification_VM_NOTIFICATIONS' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS_data(var) (*var)

/* Access member 'data' of type 'c_TEnVoiceMailNotification_VM_NOTIFICATIONS' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS_data(var) var

/* Access member 'VM_NOTIFICATIONS' of type 'c_TEnVoiceMailNotification' as a variable reference */
#define VAR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS(var) var

/* Access member 'VM_NOTIFICATIONS' of type 'c_TEnVoiceMailNotification' as a pointer */
#define PTR_c_TEnVoiceMailNotification_VM_NOTIFICATIONS(var) (&var)

/* DEFINITION OF BINARY c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA */
typedef struct _c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_TEnVoiceMailNotification_VM_NOTIFICATIONS */
typedef struct _c_TEnVoiceMailNotification_VM_NOTIFICATIONS {

	c_TEnVoiceMailNotificationItem **data; /* NDY01 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TEnVoiceMailNotification_VM_NOTIFICATIONS;


/*-A----------------------------------*/
typedef struct _c_TEnVoiceMailNotification {
	ED_LOCATOR ENHANCED_VOICE_MAIL_PDU_TYPE___LOCATOR; /* QUI2 */
	ED_LOCATOR MULTIPLE_SUBSCRIBER_PROFILE___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_STORAGE___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_ALMOST_FULL___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_FULL___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_STATUS_EXTENSION_INDICATOR___LOCATOR; /* QUI2 */
	ED_LOCATOR NUMBER_OF_VOICE_MESSAGES___LOCATOR; /* QUI2 */
	ED_LOCATOR NUMBER_OF_VM_NOTIFICATIONS___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_STATUS_EXTENSION_DATA___LOCATOR  /*LBD02*/;

	ED_BOOLEAN ENHANCED_VOICE_MAIL_PDU_TYPE; /* ODY01a *//*GBD01b*/
	ED_OCTET MULTIPLE_SUBSCRIBER_PROFILE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_STORAGE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_ALMOST_FULL; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_FULL; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_STATUS_EXTENSION_INDICATOR; /* ODY01a *//*GBD01b*/
	c_TAddress VM_MAILBOX_ACCESS_ADDRESS; /* ODY01a *//*GBD01b*/
	ED_OCTET NUMBER_OF_VOICE_MESSAGES; /* ODY01a *//*GBD01b*/
	ED_OCTET NUMBER_OF_VM_NOTIFICATIONS; /* ODY01a *//*GBD01b*/
	c_TEnVoiceMailNotification_VM_MAILBOX_STATUS_EXTENSION_DATA VM_MAILBOX_STATUS_EXTENSION_DATA; /* Static, variable size; bits needed 2040 *//*GBD01b*/
	c_TEnVoiceMailNotification_VM_NOTIFICATIONS VM_NOTIFICATIONS;/*GFB09*//*GBD01b*/

}	c_TEnVoiceMailNotification;
#define INIT_c_TEnVoiceMailNotification(sp) ED_RESET_MEM ((sp), sizeof (c_TEnVoiceMailNotification))
/*FRK03a*/
void FREE_c_TEnVoiceMailNotification(c_TEnVoiceMailNotification* sp);

/* Access member 'ENHANCED_VOICE_MAIL_PDU_TYPE' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_ENHANCED_VOICE_MAIL_PDU_TYPE(var) var

/* Access member 'ENHANCED_VOICE_MAIL_PDU_TYPE' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_ENHANCED_VOICE_MAIL_PDU_TYPE(var) (&var)

/* Access member 'MULTIPLE_SUBSCRIBER_PROFILE' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_MULTIPLE_SUBSCRIBER_PROFILE(var) var

/* Access member 'MULTIPLE_SUBSCRIBER_PROFILE' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_MULTIPLE_SUBSCRIBER_PROFILE(var) (&var)

/* Access member 'SM_STORAGE' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_SM_STORAGE(var) var

/* Access member 'SM_STORAGE' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_SM_STORAGE(var) (&var)

/* Access member 'VM_MAILBOX_ALMOST_FULL' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_ALMOST_FULL(var) var

/* Access member 'VM_MAILBOX_ALMOST_FULL' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_ALMOST_FULL(var) (&var)

/* Access member 'VM_MAILBOX_FULL' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_FULL(var) var

/* Access member 'VM_MAILBOX_FULL' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_FULL(var) (&var)

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_INDICATOR(var) var

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_INDICATOR' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_INDICATOR(var) (&var)

/* Access member 'VM_MAILBOX_ACCESS_ADDRESS' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_ACCESS_ADDRESS(var) var

/* Access member 'VM_MAILBOX_ACCESS_ADDRESS' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_ACCESS_ADDRESS(var) (&var)

/* Access member 'NUMBER_OF_VOICE_MESSAGES' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_NUMBER_OF_VOICE_MESSAGES(var) var

/* Access member 'NUMBER_OF_VOICE_MESSAGES' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_NUMBER_OF_VOICE_MESSAGES(var) (&var)

/* Access member 'NUMBER_OF_VM_DELETES' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_NUMBER_OF_VM_DELETES(var) var

/* Access member 'NUMBER_OF_VM_DELETES' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_NUMBER_OF_VM_DELETES(var) (&var)

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_DATA' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA(var) var

/* Access member 'VM_MAILBOX_STATUS_EXTENSION_DATA' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA(var) (&var)

/* Access member 'data' of type 'c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS_data(var) (*var)

/* Access member 'data' of type 'c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS_data(var) var

/* Access member 'VM_DELETE_CONFIRMATIONS' of type 'c_TEnVoiceMailDeleteConfirmation' as a variable reference */
#define VAR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS(var) var

/* Access member 'VM_DELETE_CONFIRMATIONS' of type 'c_TEnVoiceMailDeleteConfirmation' as a pointer */
#define PTR_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS(var) (&var)

/* DEFINITION OF BINARY c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA */
typedef struct _c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS */
typedef struct _c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS {

	c_TEnVoiceMailDeleteConfirmationItem **data; /* NDY01 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS;


/*-A----------------------------------*/
typedef struct _c_TEnVoiceMailDeleteConfirmation {
	ED_LOCATOR ENHANCED_VOICE_MAIL_PDU_TYPE___LOCATOR; /* QUI2 */
	ED_LOCATOR MULTIPLE_SUBSCRIBER_PROFILE___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_STORAGE___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_ALMOST_FULL___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_FULL___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_STATUS_EXTENSION_INDICATOR___LOCATOR; /* QUI2 */
	ED_LOCATOR NUMBER_OF_VOICE_MESSAGES___LOCATOR; /* QUI2 */
	ED_LOCATOR NUMBER_OF_VM_DELETES___LOCATOR; /* QUI2 */
	ED_LOCATOR VM_MAILBOX_STATUS_EXTENSION_DATA___LOCATOR  /*LBD02*/;

	ED_BOOLEAN ENHANCED_VOICE_MAIL_PDU_TYPE; /* ODY01a *//*GBD01b*/
	ED_OCTET MULTIPLE_SUBSCRIBER_PROFILE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_STORAGE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_ALMOST_FULL; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_FULL; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VM_MAILBOX_STATUS_EXTENSION_INDICATOR; /* ODY01a *//*GBD01b*/
	c_TAddress VM_MAILBOX_ACCESS_ADDRESS; /* ODY01a *//*GBD01b*/
	ED_OCTET NUMBER_OF_VOICE_MESSAGES; /* ODY01a *//*GBD01b*/
	ED_OCTET NUMBER_OF_VM_DELETES; /* ODY01a *//*GBD01b*/
	c_TEnVoiceMailDeleteConfirmation_VM_MAILBOX_STATUS_EXTENSION_DATA VM_MAILBOX_STATUS_EXTENSION_DATA; /* Static, variable size; bits needed 2040 *//*GBD01b*/
	c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS VM_DELETE_CONFIRMATIONS;/*GFB09*//*GBD01b*/

}	c_TEnVoiceMailDeleteConfirmation;
#define INIT_c_TEnVoiceMailDeleteConfirmation(sp) ED_RESET_MEM ((sp), sizeof (c_TEnVoiceMailDeleteConfirmation))
/*FRK03a*/
void FREE_c_TEnVoiceMailDeleteConfirmation(c_TEnVoiceMailDeleteConfirmation* sp);

/* Access member 'RefNumber' of type 'c_TConcShortMsgs8BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsgs8BitRefNum_RefNumber(var) var

/* Access member 'RefNumber' of type 'c_TConcShortMsgs8BitRefNum' as a pointer */
#define PTR_c_TConcShortMsgs8BitRefNum_RefNumber(var) (&var)

/* Access member 'MaxMesgs' of type 'c_TConcShortMsgs8BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsgs8BitRefNum_MaxMesgs(var) var

/* Access member 'MaxMesgs' of type 'c_TConcShortMsgs8BitRefNum' as a pointer */
#define PTR_c_TConcShortMsgs8BitRefNum_MaxMesgs(var) (&var)

/* Access member 'SeqNumber' of type 'c_TConcShortMsgs8BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsgs8BitRefNum_SeqNumber(var) var

/* Access member 'SeqNumber' of type 'c_TConcShortMsgs8BitRefNum' as a pointer */
#define PTR_c_TConcShortMsgs8BitRefNum_SeqNumber(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TConcShortMsgs8BitRefNum {
	ED_LOCATOR RefNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR MaxMesgs___LOCATOR; /* QUI2 */
	ED_LOCATOR SeqNumber___LOCATOR; /* QUI2 */

	ED_OCTET RefNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET MaxMesgs; /* ODY01a *//*GBD01b*/
	ED_OCTET SeqNumber; /* ODY01a *//*GBD01b*/

}	c_TConcShortMsgs8BitRefNum;
#define INIT_c_TConcShortMsgs8BitRefNum(sp) ED_RESET_MEM ((sp), sizeof (c_TConcShortMsgs8BitRefNum))
/*FRK03a*/
void FREE_c_TConcShortMsgs8BitRefNum(c_TConcShortMsgs8BitRefNum* sp);

/* Access member 'StoreMessage' of type 'c_TSpecialSmsMsgInd' as a variable reference */
#define VAR_c_TSpecialSmsMsgInd_StoreMessage(var) var

/* Access member 'StoreMessage' of type 'c_TSpecialSmsMsgInd' as a pointer */
#define PTR_c_TSpecialSmsMsgInd_StoreMessage(var) (&var)

/* Access member 'ExtendedIndication' of type 'c_TSpecialSmsMsgInd' as a variable reference */
#define VAR_c_TSpecialSmsMsgInd_ExtendedIndication(var) var

/* Access member 'ExtendedIndication' of type 'c_TSpecialSmsMsgInd' as a pointer */
#define PTR_c_TSpecialSmsMsgInd_ExtendedIndication(var) (&var)

/* Access member 'Indication' of type 'c_TSpecialSmsMsgInd' as a variable reference */
#define VAR_c_TSpecialSmsMsgInd_Indication(var) var

/* Access member 'Indication' of type 'c_TSpecialSmsMsgInd' as a pointer */
#define PTR_c_TSpecialSmsMsgInd_Indication(var) (&var)

/* Access member 'MsgCount' of type 'c_TSpecialSmsMsgInd' as a variable reference */
#define VAR_c_TSpecialSmsMsgInd_MsgCount(var) var

/* Access member 'MsgCount' of type 'c_TSpecialSmsMsgInd' as a pointer */
#define PTR_c_TSpecialSmsMsgInd_MsgCount(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TSpecialSmsMsgInd {
	ED_LOCATOR StoreMessage___LOCATOR; /* QUI2 */
	ED_LOCATOR ExtendedIndication___LOCATOR; /* QUI2 */
	ED_LOCATOR Indication___LOCATOR; /* QUI2 */
	ED_LOCATOR MsgCount___LOCATOR; /* QUI2 */

	ED_BOOLEAN StoreMessage; /* ODY01a *//*GBD01b*/
	ED_OCTET ExtendedIndication; /* ODY01a *//*GBD01b*/
	ED_OCTET Indication; /* ODY01a *//*GBD01b*/
	ED_OCTET MsgCount; /* ODY01a *//*GBD01b*/

}	c_TSpecialSmsMsgInd;
#define INIT_c_TSpecialSmsMsgInd(sp) ED_RESET_MEM ((sp), sizeof (c_TSpecialSmsMsgInd))
/*FRK03a*/
void FREE_c_TSpecialSmsMsgInd(c_TSpecialSmsMsgInd* sp);

/* Access member 'DestPort' of type 'c_TApplPortAddrScheme8BitAddr' as a variable reference */
#define VAR_c_TApplPortAddrScheme8BitAddr_DestPort(var) var

/* Access member 'DestPort' of type 'c_TApplPortAddrScheme8BitAddr' as a pointer */
#define PTR_c_TApplPortAddrScheme8BitAddr_DestPort(var) (&var)

/* Access member 'OrigPort' of type 'c_TApplPortAddrScheme8BitAddr' as a variable reference */
#define VAR_c_TApplPortAddrScheme8BitAddr_OrigPort(var) var

/* Access member 'OrigPort' of type 'c_TApplPortAddrScheme8BitAddr' as a pointer */
#define PTR_c_TApplPortAddrScheme8BitAddr_OrigPort(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TApplPortAddrScheme8BitAddr {
	ED_LOCATOR DestPort___LOCATOR; /* QUI2 */
	ED_LOCATOR OrigPort___LOCATOR; /* QUI2 */

	ED_OCTET DestPort; /* ODY01a *//*GBD01b*/
	ED_OCTET OrigPort; /* ODY01a *//*GBD01b*/

}	c_TApplPortAddrScheme8BitAddr;
#define INIT_c_TApplPortAddrScheme8BitAddr(sp) ED_RESET_MEM ((sp), sizeof (c_TApplPortAddrScheme8BitAddr))
/*FRK03a*/
void FREE_c_TApplPortAddrScheme8BitAddr(c_TApplPortAddrScheme8BitAddr* sp);

/* Access member 'DestPort' of type 'c_TApplPortAddrScheme16BitAddr' as a variable reference */
#define VAR_c_TApplPortAddrScheme16BitAddr_DestPort(var) var

/* Access member 'DestPort' of type 'c_TApplPortAddrScheme16BitAddr' as a pointer */
#define PTR_c_TApplPortAddrScheme16BitAddr_DestPort(var) (&var)

/* Access member 'OrigPort' of type 'c_TApplPortAddrScheme16BitAddr' as a variable reference */
#define VAR_c_TApplPortAddrScheme16BitAddr_OrigPort(var) var

/* Access member 'OrigPort' of type 'c_TApplPortAddrScheme16BitAddr' as a pointer */
#define PTR_c_TApplPortAddrScheme16BitAddr_OrigPort(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TApplPortAddrScheme16BitAddr {
	ED_LOCATOR DestPort___LOCATOR; /* QUI2 */
	ED_LOCATOR OrigPort___LOCATOR; /* QUI2 */

	ED_SHORT DestPort; /* ODY01a *//*GBD01b*/
	ED_SHORT OrigPort; /* ODY01a *//*GBD01b*/

}	c_TApplPortAddrScheme16BitAddr;
#define INIT_c_TApplPortAddrScheme16BitAddr(sp) ED_RESET_MEM ((sp), sizeof (c_TApplPortAddrScheme16BitAddr))
/*FRK03a*/
void FREE_c_TApplPortAddrScheme16BitAddr(c_TApplPortAddrScheme16BitAddr* sp);

/* Access member 'StatusRepCompleted' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_StatusRepCompleted(var) var

/* Access member 'StatusRepCompleted' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_StatusRepCompleted(var) (&var)

/* Access member 'StatusRepPermError' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_StatusRepPermError(var) var

/* Access member 'StatusRepPermError' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_StatusRepPermError(var) (&var)

/* Access member 'StatusRepTempError' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_StatusRepTempError(var) var

/* Access member 'StatusRepTempError' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_StatusRepTempError(var) (&var)

/* Access member 'StatusRepTempErrorSMStillTrying' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_StatusRepTempErrorSMStillTrying(var) var

/* Access member 'StatusRepTempErrorSMStillTrying' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_StatusRepTempErrorSMStillTrying(var) (&var)

/* Access member 'reserved' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_reserved(var) var

/* Access member 'reserved' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_reserved(var) (&var)

/* Access member 'CancelConcat' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_CancelConcat(var) var

/* Access member 'CancelConcat' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_CancelConcat(var) (&var)

/* Access member 'IncludeOrigUDHInStatusRep' of type 'c_TSmscCtrlParams' as a variable reference */
#define VAR_c_TSmscCtrlParams_IncludeOrigUDHInStatusRep(var) var

/* Access member 'IncludeOrigUDHInStatusRep' of type 'c_TSmscCtrlParams' as a pointer */
#define PTR_c_TSmscCtrlParams_IncludeOrigUDHInStatusRep(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TSmscCtrlParams {
	ED_LOCATOR StatusRepCompleted___LOCATOR; /* QUI2 */
	ED_LOCATOR StatusRepPermError___LOCATOR; /* QUI2 */
	ED_LOCATOR StatusRepTempError___LOCATOR; /* QUI2 */
	ED_LOCATOR StatusRepTempErrorSMStillTrying___LOCATOR; /* QUI2 */
	ED_LOCATOR CancelConcat___LOCATOR; /* QUI2 */
	ED_LOCATOR IncludeOrigUDHInStatusRep___LOCATOR; /* QUI2 */

	ED_BOOLEAN StatusRepCompleted; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StatusRepPermError; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StatusRepTempError; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StatusRepTempErrorSMStillTrying; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN CancelConcat; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IncludeOrigUDHInStatusRep; /* ODY01a *//*GBD01b*/

}	c_TSmscCtrlParams;
#define INIT_c_TSmscCtrlParams(sp) ED_RESET_MEM ((sp), sizeof (c_TSmscCtrlParams))
/*FRK03a*/
void FREE_c_TSmscCtrlParams(c_TSmscCtrlParams* sp);

/* Access member 'value' of type 'c_TUdhSrcInd' as a variable reference */
#define VAR_c_TUdhSrcInd_value(var) var

/* Access member 'value' of type 'c_TUdhSrcInd' as a pointer */
#define PTR_c_TUdhSrcInd_value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TUdhSrcInd {
	ED_LOCATOR value___LOCATOR; /* QUI2 */

	ED_OCTET value; /* ODY01a *//*GBD01b*/

}	c_TUdhSrcInd;
#define INIT_c_TUdhSrcInd(sp) ED_RESET_MEM ((sp), sizeof (c_TUdhSrcInd))
/*FRK03a*/
void FREE_c_TUdhSrcInd(c_TUdhSrcInd* sp);

/* Access member 'RefNumber' of type 'c_TConcShortMsg16BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsg16BitRefNum_RefNumber(var) var

/* Access member 'RefNumber' of type 'c_TConcShortMsg16BitRefNum' as a pointer */
#define PTR_c_TConcShortMsg16BitRefNum_RefNumber(var) (&var)

/* Access member 'MaxMesgs' of type 'c_TConcShortMsg16BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsg16BitRefNum_MaxMesgs(var) var

/* Access member 'MaxMesgs' of type 'c_TConcShortMsg16BitRefNum' as a pointer */
#define PTR_c_TConcShortMsg16BitRefNum_MaxMesgs(var) (&var)

/* Access member 'SeqNumber' of type 'c_TConcShortMsg16BitRefNum' as a variable reference */
#define VAR_c_TConcShortMsg16BitRefNum_SeqNumber(var) var

/* Access member 'SeqNumber' of type 'c_TConcShortMsg16BitRefNum' as a pointer */
#define PTR_c_TConcShortMsg16BitRefNum_SeqNumber(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TConcShortMsg16BitRefNum {
	ED_LOCATOR RefNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR MaxMesgs___LOCATOR; /* QUI2 */
	ED_LOCATOR SeqNumber___LOCATOR; /* QUI2 */

	ED_SHORT RefNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET MaxMesgs; /* ODY01a *//*GBD01b*/
	ED_OCTET SeqNumber; /* ODY01a *//*GBD01b*/

}	c_TConcShortMsg16BitRefNum;
#define INIT_c_TConcShortMsg16BitRefNum(sp) ED_RESET_MEM ((sp), sizeof (c_TConcShortMsg16BitRefNum))
/*FRK03a*/
void FREE_c_TConcShortMsg16BitRefNum(c_TConcShortMsg16BitRefNum* sp);

/* Access member 'StartPosition' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_StartPosition(var) (&var)

/* Access member 'Length' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Length(var) var

/* Access member 'Length' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Length(var) (&var)

/* Access member 'Alignment' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Alignment(var) var

/* Access member 'Alignment' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Alignment(var) (&var)

/* Access member 'FontSize' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_FontSize(var) var

/* Access member 'FontSize' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_FontSize(var) (&var)

/* Access member 'Bold' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Bold(var) var

/* Access member 'Bold' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Bold(var) (&var)

/* Access member 'Italic' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Italic(var) var

/* Access member 'Italic' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Italic(var) (&var)

/* Access member 'Underlined' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Underlined(var) var

/* Access member 'Underlined' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Underlined(var) (&var)

/* Access member 'Striketrhrough' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_Striketrhrough(var) var

/* Access member 'Striketrhrough' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_Striketrhrough(var) (&var)

/* Access member 'TextColor' of type 'c_TTextFmt' as a variable reference */
#define VAR_c_TTextFmt_TextColor(var) var

/* Access member 'TextColor' of type 'c_TTextFmt' as a pointer */
#define PTR_c_TTextFmt_TextColor(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TTextFmt {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR Alignment___LOCATOR; /* QUI2 */
	ED_LOCATOR FontSize___LOCATOR; /* QUI2 */
	ED_LOCATOR Bold___LOCATOR; /* QUI2 */
	ED_LOCATOR Italic___LOCATOR; /* QUI2 */
	ED_LOCATOR Underlined___LOCATOR; /* QUI2 */
	ED_LOCATOR Striketrhrough___LOCATOR; /* QUI2 */
	ED_LOCATOR TextColor___LOCATOR; /* QUI2 */

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	ED_OCTET Alignment; /* ODY01a *//*GBD01b*/
	ED_OCTET FontSize; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Bold; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Italic; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Underlined; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Striketrhrough; /* ODY01a *//*GBD01b*/
	ED_OCTET TextColor; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TextColor_Present;

}	c_TTextFmt;
#define INIT_c_TTextFmt(sp) ED_RESET_MEM ((sp), sizeof (c_TTextFmt))
/*FRK03a*/
void FREE_c_TTextFmt(c_TTextFmt* sp);
#define SETPRESENT_c_TTextFmt_TextColor(sp,present) (((sp)->TextColor_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TTextFmt_TextColor(sp) ((sp)->TextColor_Present)

/* Access member 'StartPosition' of type 'c_TPredefSound' as a variable reference */
#define VAR_c_TPredefSound_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TPredefSound' as a pointer */
#define PTR_c_TPredefSound_StartPosition(var) (&var)

/* Access member 'SoundNumber' of type 'c_TPredefSound' as a variable reference */
#define VAR_c_TPredefSound_SoundNumber(var) var

/* Access member 'SoundNumber' of type 'c_TPredefSound' as a pointer */
#define PTR_c_TPredefSound_SoundNumber(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TPredefSound {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR SoundNumber___LOCATOR; /* QUI2 */

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	ED_OCTET SoundNumber; /* ODY01a *//*GBD01b*/

}	c_TPredefSound;
#define INIT_c_TPredefSound(sp) ED_RESET_MEM ((sp), sizeof (c_TPredefSound))
/*FRK03a*/
void FREE_c_TPredefSound(c_TPredefSound* sp);

/* Access member 'StartPosition' of type 'c_TUserDefSound' as a variable reference */
#define VAR_c_TUserDefSound_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TUserDefSound' as a pointer */
#define PTR_c_TUserDefSound_StartPosition(var) (&var)

/* Access member 'Sound' of type 'c_TUserDefSound' as a variable reference */
#define VAR_c_TUserDefSound_Sound(var) var

/* Access member 'Sound' of type 'c_TUserDefSound' as a pointer */
#define PTR_c_TUserDefSound_Sound(var) (&var)

/* DEFINITION OF BINARY c_TUserDefSound_Sound */
typedef struct _c_TUserDefSound_Sound {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TUserDefSound_Sound;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TUserDefSound_Sound(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TUserDefSound {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Sound___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	c_TUserDefSound_Sound Sound; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TUserDefSound;
#define INIT_c_TUserDefSound(sp) ED_RESET_MEM ((sp), sizeof (c_TUserDefSound))
/*FRK03a*/
void FREE_c_TUserDefSound(c_TUserDefSound* sp);

/* Access member 'StartPosition' of type 'c_TPredefAnim' as a variable reference */
#define VAR_c_TPredefAnim_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TPredefAnim' as a pointer */
#define PTR_c_TPredefAnim_StartPosition(var) (&var)

/* Access member 'AnimationNumber' of type 'c_TPredefAnim' as a variable reference */
#define VAR_c_TPredefAnim_AnimationNumber(var) var

/* Access member 'AnimationNumber' of type 'c_TPredefAnim' as a pointer */
#define PTR_c_TPredefAnim_AnimationNumber(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TPredefAnim {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR AnimationNumber___LOCATOR; /* QUI2 */

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	ED_OCTET AnimationNumber; /* ODY01a *//*GBD01b*/

}	c_TPredefAnim;
#define INIT_c_TPredefAnim(sp) ED_RESET_MEM ((sp), sizeof (c_TPredefAnim))
/*FRK03a*/
void FREE_c_TPredefAnim(c_TPredefAnim* sp);

/* Access member 'StartPosition' of type 'c_TLargeAnim' as a variable reference */
#define VAR_c_TLargeAnim_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TLargeAnim' as a pointer */
#define PTR_c_TLargeAnim_StartPosition(var) (&var)

/* Access member 'Animation' of type 'c_TLargeAnim' as a variable reference */
#define VAR_c_TLargeAnim_Animation(var) var

/* Access member 'Animation' of type 'c_TLargeAnim' as a pointer */
#define PTR_c_TLargeAnim_Animation(var) (&var)

/* DEFINITION OF BINARY c_TLargeAnim_Animation */
typedef struct _c_TLargeAnim_Animation {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TLargeAnim_Animation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TLargeAnim_Animation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TLargeAnim {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Animation___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	c_TLargeAnim_Animation Animation; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TLargeAnim;
#define INIT_c_TLargeAnim(sp) ED_RESET_MEM ((sp), sizeof (c_TLargeAnim))
/*FRK03a*/
void FREE_c_TLargeAnim(c_TLargeAnim* sp);

/* Access member 'StartPosition' of type 'c_TSmallAnim' as a variable reference */
#define VAR_c_TSmallAnim_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TSmallAnim' as a pointer */
#define PTR_c_TSmallAnim_StartPosition(var) (&var)

/* Access member 'Animation' of type 'c_TSmallAnim' as a variable reference */
#define VAR_c_TSmallAnim_Animation(var) var

/* Access member 'Animation' of type 'c_TSmallAnim' as a pointer */
#define PTR_c_TSmallAnim_Animation(var) (&var)

/* DEFINITION OF BINARY c_TSmallAnim_Animation */
typedef struct _c_TSmallAnim_Animation {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TSmallAnim_Animation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TSmallAnim_Animation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TSmallAnim {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Animation___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	c_TSmallAnim_Animation Animation; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TSmallAnim;
#define INIT_c_TSmallAnim(sp) ED_RESET_MEM ((sp), sizeof (c_TSmallAnim))
/*FRK03a*/
void FREE_c_TSmallAnim(c_TSmallAnim* sp);

/* Access member 'StartPosition' of type 'c_TLargePict' as a variable reference */
#define VAR_c_TLargePict_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TLargePict' as a pointer */
#define PTR_c_TLargePict_StartPosition(var) (&var)

/* Access member 'Picture' of type 'c_TLargePict' as a variable reference */
#define VAR_c_TLargePict_Picture(var) var

/* Access member 'Picture' of type 'c_TLargePict' as a pointer */
#define PTR_c_TLargePict_Picture(var) (&var)

/* DEFINITION OF BINARY c_TLargePict_Picture */
typedef struct _c_TLargePict_Picture {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TLargePict_Picture;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TLargePict_Picture(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TLargePict {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Picture___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	c_TLargePict_Picture Picture; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TLargePict;
#define INIT_c_TLargePict(sp) ED_RESET_MEM ((sp), sizeof (c_TLargePict))
/*FRK03a*/
void FREE_c_TLargePict(c_TLargePict* sp);

/* Access member 'StartPosition' of type 'c_TSmallPict' as a variable reference */
#define VAR_c_TSmallPict_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TSmallPict' as a pointer */
#define PTR_c_TSmallPict_StartPosition(var) (&var)

/* Access member 'Picture' of type 'c_TSmallPict' as a variable reference */
#define VAR_c_TSmallPict_Picture(var) var

/* Access member 'Picture' of type 'c_TSmallPict' as a pointer */
#define PTR_c_TSmallPict_Picture(var) (&var)

/* DEFINITION OF BINARY c_TSmallPict_Picture */
typedef struct _c_TSmallPict_Picture {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TSmallPict_Picture;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TSmallPict_Picture(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TSmallPict {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR Picture___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	c_TSmallPict_Picture Picture; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TSmallPict;
#define INIT_c_TSmallPict(sp) ED_RESET_MEM ((sp), sizeof (c_TSmallPict))
/*FRK03a*/
void FREE_c_TSmallPict(c_TSmallPict* sp);

/* Access member 'StartPosition' of type 'c_TVarPict' as a variable reference */
#define VAR_c_TVarPict_StartPosition(var) var

/* Access member 'StartPosition' of type 'c_TVarPict' as a pointer */
#define PTR_c_TVarPict_StartPosition(var) (&var)

/* Access member 'HSize' of type 'c_TVarPict' as a variable reference */
#define VAR_c_TVarPict_HSize(var) var

/* Access member 'HSize' of type 'c_TVarPict' as a pointer */
#define PTR_c_TVarPict_HSize(var) (&var)

/* Access member 'VSize' of type 'c_TVarPict' as a variable reference */
#define VAR_c_TVarPict_VSize(var) var

/* Access member 'VSize' of type 'c_TVarPict' as a pointer */
#define PTR_c_TVarPict_VSize(var) (&var)

/* Access member 'Animation' of type 'c_TVarPict' as a variable reference */
#define VAR_c_TVarPict_Animation(var) var

/* Access member 'Animation' of type 'c_TVarPict' as a pointer */
#define PTR_c_TVarPict_Animation(var) (&var)

/* DEFINITION OF BINARY c_TVarPict_Animation */
typedef struct _c_TVarPict_Animation {
	ED_BYTE* value; /* Variable size; bits needed 1008 */
	int usedBits;
} c_TVarPict_Animation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TVarPict_Animation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TVarPict {
	ED_LOCATOR StartPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR HSize___LOCATOR; /* QUI2 */
	ED_LOCATOR VSize___LOCATOR; /* QUI2 */
	ED_LOCATOR Animation___LOCATOR  /*LBD02*/;

	ED_OCTET StartPosition; /* ODY01a *//*GBD01b*/
	ED_OCTET HSize; /* ODY01a *//*GBD01b*/
	ED_OCTET VSize; /* ODY01a *//*GBD01b*/
	c_TVarPict_Animation Animation; /* Static, variable size; bits needed 1008 *//*GBD01b*/

}	c_TVarPict;
#define INIT_c_TVarPict(sp) ED_RESET_MEM ((sp), sizeof (c_TVarPict))
/*FRK03a*/
void FREE_c_TVarPict(c_TVarPict* sp);

/* Access member 'NumOfCorrespObj' of type 'c_TUserPromptInd' as a variable reference */
#define VAR_c_TUserPromptInd_NumOfCorrespObj(var) var

/* Access member 'NumOfCorrespObj' of type 'c_TUserPromptInd' as a pointer */
#define PTR_c_TUserPromptInd_NumOfCorrespObj(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TUserPromptInd {
	ED_LOCATOR NumOfCorrespObj___LOCATOR; /* QUI2 */

	ED_OCTET NumOfCorrespObj; /* ODY01a *//*GBD01b*/

}	c_TUserPromptInd;
#define INIT_c_TUserPromptInd(sp) ED_RESET_MEM ((sp), sizeof (c_TUserPromptInd))
/*FRK03a*/
void FREE_c_TUserPromptInd(c_TUserPromptInd* sp);

/* Access member 'ExObjRefNum' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_ExObjRefNum(var) var

/* Access member 'ExObjRefNum' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_ExObjRefNum(var) (&var)

/* Access member 'Length' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_Length(var) var

/* Access member 'Length' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_Length(var) (&var)

/* Access member 'DoNotForward' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_DoNotForward(var) var

/* Access member 'DoNotForward' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_DoNotForward(var) (&var)

/* Access member 'UserPrompt' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_UserPrompt(var) var

/* Access member 'UserPrompt' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_UserPrompt(var) (&var)

/* Access member 'Reserved' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_Reserved(var) var

/* Access member 'Reserved' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_Reserved(var) (&var)

/* Access member 'ExObjType' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_ExObjType(var) var

/* Access member 'ExObjType' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_ExObjType(var) (&var)

/* Access member 'ExObjPosition' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_ExObjPosition(var) var

/* Access member 'ExObjPosition' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_ExObjPosition(var) (&var)

/* Access member 'ExObjData' of type 'c_TExtObj' as a variable reference */
#define VAR_c_TExtObj_ExObjData(var) var

/* Access member 'ExObjData' of type 'c_TExtObj' as a pointer */
#define PTR_c_TExtObj_ExObjData(var) (&var)

/* DEFINITION OF BINARY c_TExtObj_ExObjData */
typedef struct _c_TExtObj_ExObjData {
	ED_BYTE* value; /* Variable size; bits needed 976 */
	int usedBits;
} c_TExtObj_ExObjData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TExtObj_ExObjData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TExtObj {
	ED_LOCATOR ExObjRefNum___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR DoNotForward___LOCATOR; /* QUI2 */
	ED_LOCATOR UserPrompt___LOCATOR; /* QUI2 */
	ED_LOCATOR ExObjType___LOCATOR; /* QUI2 */
	ED_LOCATOR ExObjPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR ExObjData___LOCATOR  /*LBD02*/;

	ED_OCTET ExObjRefNum; /* ODY01a *//*GBD01b*/
	ED_SHORT Length; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DoNotForward; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UserPrompt; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET ExObjType; /* ODY01a *//*GBD01b*/
	ED_SHORT ExObjPosition; /* ODY01a *//*GBD01b*/
	c_TExtObj_ExObjData ExObjData; /* Static, variable size; bits needed 976 *//*GBD01b*/

}	c_TExtObj;
#define INIT_c_TExtObj(sp) ED_RESET_MEM ((sp), sizeof (c_TExtObj))
/*FRK03a*/
void FREE_c_TExtObj(c_TExtObj* sp);

/* Access member 'RefNumber' of type 'c_TReusedExtObj' as a variable reference */
#define VAR_c_TReusedExtObj_RefNumber(var) var

/* Access member 'RefNumber' of type 'c_TReusedExtObj' as a pointer */
#define PTR_c_TReusedExtObj_RefNumber(var) (&var)

/* Access member 'Position' of type 'c_TReusedExtObj' as a variable reference */
#define VAR_c_TReusedExtObj_Position(var) var

/* Access member 'Position' of type 'c_TReusedExtObj' as a pointer */
#define PTR_c_TReusedExtObj_Position(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TReusedExtObj {
	ED_LOCATOR RefNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR Position___LOCATOR; /* QUI2 */

	ED_OCTET RefNumber; /* ODY01a *//*GBD01b*/
	ED_SHORT Position; /* ODY01a *//*GBD01b*/

}	c_TReusedExtObj;
#define INIT_c_TReusedExtObj(sp) ED_RESET_MEM ((sp), sizeof (c_TReusedExtObj))
/*FRK03a*/
void FREE_c_TReusedExtObj(c_TReusedExtObj* sp);

/* Access member 'ComprAlgo' of type 'c_TComprCtrl' as a variable reference */
#define VAR_c_TComprCtrl_ComprAlgo(var) var

/* Access member 'ComprAlgo' of type 'c_TComprCtrl' as a pointer */
#define PTR_c_TComprCtrl_ComprAlgo(var) (&var)

/* Access member 'reserved' of type 'c_TComprCtrl' as a variable reference */
#define VAR_c_TComprCtrl_reserved(var) var

/* Access member 'reserved' of type 'c_TComprCtrl' as a pointer */
#define PTR_c_TComprCtrl_reserved(var) (&var)

/* Access member 'Length' of type 'c_TComprCtrl' as a variable reference */
#define VAR_c_TComprCtrl_Length(var) var

/* Access member 'Length' of type 'c_TComprCtrl' as a pointer */
#define PTR_c_TComprCtrl_Length(var) (&var)

/* Access member 'CompressedData' of type 'c_TComprCtrl' as a variable reference */
#define VAR_c_TComprCtrl_CompressedData(var) var

/* Access member 'CompressedData' of type 'c_TComprCtrl' as a pointer */
#define PTR_c_TComprCtrl_CompressedData(var) (&var)

/* DEFINITION OF BINARY c_TComprCtrl_CompressedData */
typedef struct _c_TComprCtrl_CompressedData {
	ED_BYTE* value; /* Variable size; bits needed 1008 */
	int usedBits;
} c_TComprCtrl_CompressedData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TComprCtrl_CompressedData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TComprCtrl {
	ED_LOCATOR ComprAlgo___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR CompressedData___LOCATOR  /*LBD02*/;

	ED_OCTET ComprAlgo; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_SHORT Length; /* ODY01a *//*GBD01b*/
	c_TComprCtrl_CompressedData CompressedData; /* Static, variable size; bits needed 1008 *//*GBD01b*/

}	c_TComprCtrl;
#define INIT_c_TComprCtrl(sp) ED_RESET_MEM ((sp), sizeof (c_TComprCtrl))
/*FRK03a*/
void FREE_c_TComprCtrl(c_TComprCtrl* sp);

/* Access member 'NumOfIEs' of type 'c_TObjDistrInd' as a variable reference */
#define VAR_c_TObjDistrInd_NumOfIEs(var) var

/* Access member 'NumOfIEs' of type 'c_TObjDistrInd' as a pointer */
#define PTR_c_TObjDistrInd_NumOfIEs(var) (&var)

/* Access member 'DontForward' of type 'c_TObjDistrInd' as a variable reference */
#define VAR_c_TObjDistrInd_DontForward(var) var

/* Access member 'DontForward' of type 'c_TObjDistrInd' as a pointer */
#define PTR_c_TObjDistrInd_DontForward(var) (&var)

/* Access member 'reserved' of type 'c_TObjDistrInd' as a variable reference */
#define VAR_c_TObjDistrInd_reserved(var) var

/* Access member 'reserved' of type 'c_TObjDistrInd' as a pointer */
#define PTR_c_TObjDistrInd_reserved(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TObjDistrInd {
	ED_LOCATOR NumOfIEs___LOCATOR; /* QUI2 */
	ED_LOCATOR DontForward___LOCATOR; /* QUI2 */

	ED_OCTET NumOfIEs; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DontForward; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_TObjDistrInd;
#define INIT_c_TObjDistrInd(sp) ED_RESET_MEM ((sp), sizeof (c_TObjDistrInd))
/*FRK03a*/
void FREE_c_TObjDistrInd(c_TObjDistrInd* sp);

/* Access member 'Position' of type 'c_TStdWvgObj' as a variable reference */
#define VAR_c_TStdWvgObj_Position(var) var

/* Access member 'Position' of type 'c_TStdWvgObj' as a pointer */
#define PTR_c_TStdWvgObj_Position(var) (&var)

/* Access member 'Data' of type 'c_TStdWvgObj' as a variable reference */
#define VAR_c_TStdWvgObj_Data(var) var

/* Access member 'Data' of type 'c_TStdWvgObj' as a pointer */
#define PTR_c_TStdWvgObj_Data(var) (&var)

/* DEFINITION OF BINARY c_TStdWvgObj_Data */
typedef struct _c_TStdWvgObj_Data {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TStdWvgObj_Data;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TStdWvgObj_Data(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TStdWvgObj {
	ED_LOCATOR Position___LOCATOR; /* QUI2 */
	ED_LOCATOR Data___LOCATOR  /*LBD02*/;

	ED_OCTET Position; /* ODY01a *//*GBD01b*/
	c_TStdWvgObj_Data Data; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TStdWvgObj;
#define INIT_c_TStdWvgObj(sp) ED_RESET_MEM ((sp), sizeof (c_TStdWvgObj))
/*FRK03a*/
void FREE_c_TStdWvgObj(c_TStdWvgObj* sp);

/* Access member 'Position' of type 'c_TCharSizeWvgObj' as a variable reference */
#define VAR_c_TCharSizeWvgObj_Position(var) var

/* Access member 'Position' of type 'c_TCharSizeWvgObj' as a pointer */
#define PTR_c_TCharSizeWvgObj_Position(var) (&var)

/* Access member 'Data' of type 'c_TCharSizeWvgObj' as a variable reference */
#define VAR_c_TCharSizeWvgObj_Data(var) var

/* Access member 'Data' of type 'c_TCharSizeWvgObj' as a pointer */
#define PTR_c_TCharSizeWvgObj_Data(var) (&var)

/* DEFINITION OF BINARY c_TCharSizeWvgObj_Data */
typedef struct _c_TCharSizeWvgObj_Data {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TCharSizeWvgObj_Data;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TCharSizeWvgObj_Data(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TCharSizeWvgObj {
	ED_LOCATOR Position___LOCATOR; /* QUI2 */
	ED_LOCATOR Data___LOCATOR  /*LBD02*/;

	ED_OCTET Position; /* ODY01a *//*GBD01b*/
	c_TCharSizeWvgObj_Data Data; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TCharSizeWvgObj;
#define INIT_c_TCharSizeWvgObj(sp) ED_RESET_MEM ((sp), sizeof (c_TCharSizeWvgObj))
/*FRK03a*/
void FREE_c_TCharSizeWvgObj(c_TCharSizeWvgObj* sp);

/* Access member 'Length' of type 'c_TRfc822EMailHdr' as a variable reference */
#define VAR_c_TRfc822EMailHdr_Length(var) var

/* Access member 'Length' of type 'c_TRfc822EMailHdr' as a pointer */
#define PTR_c_TRfc822EMailHdr_Length(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TRfc822EMailHdr {
	ED_LOCATOR Length___LOCATOR; /* QUI2 */

	ED_OCTET Length; /* ODY01a *//*GBD01b*/

}	c_TRfc822EMailHdr;
#define INIT_c_TRfc822EMailHdr(sp) ED_RESET_MEM ((sp), sizeof (c_TRfc822EMailHdr))
/*FRK03a*/
void FREE_c_TRfc822EMailHdr(c_TRfc822EMailHdr* sp);

/* Access member 'AbsElemPosition' of type 'c_THyperlinkFmtElem' as a variable reference */
#define VAR_c_THyperlinkFmtElem_AbsElemPosition(var) var

/* Access member 'AbsElemPosition' of type 'c_THyperlinkFmtElem' as a pointer */
#define PTR_c_THyperlinkFmtElem_AbsElemPosition(var) (&var)

/* Access member 'HyperLinkTitleLen' of type 'c_THyperlinkFmtElem' as a variable reference */
#define VAR_c_THyperlinkFmtElem_HyperLinkTitleLen(var) var

/* Access member 'HyperLinkTitleLen' of type 'c_THyperlinkFmtElem' as a pointer */
#define PTR_c_THyperlinkFmtElem_HyperLinkTitleLen(var) (&var)

/* Access member 'URLLen' of type 'c_THyperlinkFmtElem' as a variable reference */
#define VAR_c_THyperlinkFmtElem_URLLen(var) var

/* Access member 'URLLen' of type 'c_THyperlinkFmtElem' as a pointer */
#define PTR_c_THyperlinkFmtElem_URLLen(var) (&var)


/*-A----------------------------------*/
typedef struct _c_THyperlinkFmtElem {
	ED_LOCATOR AbsElemPosition___LOCATOR; /* QUI2 */
	ED_LOCATOR HyperLinkTitleLen___LOCATOR; /* QUI2 */
	ED_LOCATOR URLLen___LOCATOR; /* QUI2 */

	ED_SHORT AbsElemPosition; /* ODY01a *//*GBD01b*/
	ED_OCTET HyperLinkTitleLen; /* ODY01a *//*GBD01b*/
	ED_OCTET URLLen; /* ODY01a *//*GBD01b*/

}	c_THyperlinkFmtElem;
#define INIT_c_THyperlinkFmtElem(sp) ED_RESET_MEM ((sp), sizeof (c_THyperlinkFmtElem))
/*FRK03a*/
void FREE_c_THyperlinkFmtElem(c_THyperlinkFmtElem* sp);

/* Access member 'IEI' of type 'c_TUnknownIE' as a variable reference */
#define VAR_c_TUnknownIE_IEI(var) var

/* Access member 'IEI' of type 'c_TUnknownIE' as a pointer */
#define PTR_c_TUnknownIE_IEI(var) (&var)

/* Access member 'RawData' of type 'c_TUnknownIE' as a variable reference */
#define VAR_c_TUnknownIE_RawData(var) var

/* Access member 'RawData' of type 'c_TUnknownIE' as a pointer */
#define PTR_c_TUnknownIE_RawData(var) (&var)

/* DEFINITION OF BINARY c_TUnknownIE_RawData */
typedef struct _c_TUnknownIE_RawData {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TUnknownIE_RawData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TUnknownIE_RawData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_TUnknownIE {
	ED_LOCATOR IEI___LOCATOR; /* QUI2 */
	ED_LOCATOR RawData___LOCATOR  /*LBD02*/;

	ED_LONG IEI; /* ODY01a *//*GBD01b*/
	c_TUnknownIE_RawData RawData; /* Static, variable size; bits needed 1024 *//*GBD01b*/

}	c_TUnknownIE;
#define INIT_c_TUnknownIE(sp) ED_RESET_MEM ((sp), sizeof (c_TUnknownIE))
/*FRK03a*/
void FREE_c_TUnknownIE(c_TUnknownIE* sp);

/* Access member 'voiceMailNotification' of type 'c_TEnVoiceMailInfo' as a variable reference */
#define VAR_c_TEnVoiceMailInfo_voiceMailNotification(var) (*var)

/* Access member 'voiceMailNotification' of type 'c_TEnVoiceMailInfo' as a pointer */
#define PTR_c_TEnVoiceMailInfo_voiceMailNotification(var) var

/* Access member 'voiceMailDeleteConfirmation' of type 'c_TEnVoiceMailInfo' as a variable reference */
#define VAR_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation(var) (*var)

/* Access member 'voiceMailDeleteConfirmation' of type 'c_TEnVoiceMailInfo' as a pointer */
#define PTR_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_TEnVoiceMailInfo_NONE,
	U_c_TEnVoiceMailInfo_voiceMailNotification,
	U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation
} TPRESENT_c_TEnVoiceMailInfo;

typedef struct _c_TEnVoiceMailInfo {

		TPRESENT_c_TEnVoiceMailInfo Present;
		union {
			c_TEnVoiceMailNotification *voiceMailNotification; /* ODY01 *//*GBD01b*/
		
			c_TEnVoiceMailDeleteConfirmation *voiceMailDeleteConfirmation; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_TEnVoiceMailInfo;
#define INIT_c_TEnVoiceMailInfo(sp) ED_RESET_MEM ((sp), sizeof (c_TEnVoiceMailInfo))
/*FRK01a*/
void FREE_c_TEnVoiceMailInfo (c_TEnVoiceMailInfo* sp);

/* SETPRESENT commands for type 'c_TEnVoiceMailInfo' */
int GLOB_SETPRESENT_c_TEnVoiceMailInfo (c_TEnVoiceMailInfo* sp, TPRESENT_c_TEnVoiceMailInfo toBeSetPresent);
#define SETPRESENT_c_TEnVoiceMailInfo_NONE(sp) GLOB_SETPRESENT_c_TEnVoiceMailInfo(sp, U_c_TEnVoiceMailInfo_NONE)
#define GETPRESENT_c_TEnVoiceMailInfo_NONE(sp) ((sp)->Present == U_c_TEnVoiceMailInfo_NONE)
#define SETPRESENT_c_TEnVoiceMailInfo_voiceMailNotification(sp) GLOB_SETPRESENT_c_TEnVoiceMailInfo(sp, U_c_TEnVoiceMailInfo_voiceMailNotification)
#define GETPRESENT_c_TEnVoiceMailInfo_voiceMailNotification(sp) ((sp)->Present == U_c_TEnVoiceMailInfo_voiceMailNotification)
#define SETPRESENT_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation(sp) GLOB_SETPRESENT_c_TEnVoiceMailInfo(sp, U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation)
#define GETPRESENT_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation(sp) ((sp)->Present == U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation)
#define GETPRESENT_c_TEnVoiceMailInfo(sp) ((sp)->Present)


/* Access member 'ConcShortMsgs8BitRefNum' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum(var) (*var)

/* Access member 'ConcShortMsgs8BitRefNum' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum(var) var

/* Access member 'SpecialSmsMsgInd' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_SpecialSmsMsgInd(var) (*var)

/* Access member 'SpecialSmsMsgInd' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_SpecialSmsMsgInd(var) var

/* Access member 'ApplPortAddrScheme8BitAddr' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr(var) (*var)

/* Access member 'ApplPortAddrScheme8BitAddr' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr(var) var

/* Access member 'ApplPortAddrScheme16BitAddr' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr(var) (*var)

/* Access member 'ApplPortAddrScheme16BitAddr' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr(var) var

/* Access member 'SmscCtrlParams' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_SmscCtrlParams(var) (*var)

/* Access member 'SmscCtrlParams' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_SmscCtrlParams(var) var

/* Access member 'UdhSrcInd' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_UdhSrcInd(var) (*var)

/* Access member 'UdhSrcInd' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_UdhSrcInd(var) var

/* Access member 'ConcShortMsg16BitRefNum' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ConcShortMsg16BitRefNum(var) (*var)

/* Access member 'ConcShortMsg16BitRefNum' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ConcShortMsg16BitRefNum(var) var

/* Access member 'WirelessCtrlMsgProto' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_WirelessCtrlMsgProto(var) (*var)

/* Access member 'WirelessCtrlMsgProto' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_WirelessCtrlMsgProto(var) var

/* Access member 'TextFmt' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_TextFmt(var) (*var)

/* Access member 'TextFmt' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_TextFmt(var) var

/* Access member 'PredefSound' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_PredefSound(var) (*var)

/* Access member 'PredefSound' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_PredefSound(var) var

/* Access member 'UserDefSound' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_UserDefSound(var) (*var)

/* Access member 'UserDefSound' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_UserDefSound(var) var

/* Access member 'PredefAnim' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_PredefAnim(var) (*var)

/* Access member 'PredefAnim' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_PredefAnim(var) var

/* Access member 'LargeAnim' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_LargeAnim(var) (*var)

/* Access member 'LargeAnim' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_LargeAnim(var) var

/* Access member 'SmallAnim' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_SmallAnim(var) (*var)

/* Access member 'SmallAnim' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_SmallAnim(var) var

/* Access member 'LargePict' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_LargePict(var) (*var)

/* Access member 'LargePict' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_LargePict(var) var

/* Access member 'SmallPict' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_SmallPict(var) (*var)

/* Access member 'SmallPict' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_SmallPict(var) var

/* Access member 'VarPict' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_VarPict(var) (*var)

/* Access member 'VarPict' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_VarPict(var) var

/* Access member 'UserPromptInd' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_UserPromptInd(var) (*var)

/* Access member 'UserPromptInd' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_UserPromptInd(var) var

/* Access member 'ExtObj' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ExtObj(var) (*var)

/* Access member 'ExtObj' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ExtObj(var) var

/* Access member 'ReusedExtObj' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ReusedExtObj(var) (*var)

/* Access member 'ReusedExtObj' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ReusedExtObj(var) var

/* Access member 'ComprCtrl' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ComprCtrl(var) (*var)

/* Access member 'ComprCtrl' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ComprCtrl(var) var

/* Access member 'ObjDistrInd' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ObjDistrInd(var) (*var)

/* Access member 'ObjDistrInd' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ObjDistrInd(var) var

/* Access member 'StdWvgObj' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_StdWvgObj(var) (*var)

/* Access member 'StdWvgObj' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_StdWvgObj(var) var

/* Access member 'CharSizeWvgObj' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_CharSizeWvgObj(var) (*var)

/* Access member 'CharSizeWvgObj' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_CharSizeWvgObj(var) var

/* Access member 'ExtObjDataReqCmd' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ExtObjDataReqCmd(var) var

/* Access member 'ExtObjDataReqCmd' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ExtObjDataReqCmd(var) (&var)

/* Access member 'Rfc822EMailHdr' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_Rfc822EMailHdr(var) (*var)

/* Access member 'Rfc822EMailHdr' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_Rfc822EMailHdr(var) var

/* Access member 'HyperlinkFmtElem' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_HyperlinkFmtElem(var) (*var)

/* Access member 'HyperlinkFmtElem' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_HyperlinkFmtElem(var) var

/* Access member 'ReplyAddrElem' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_ReplyAddrElem(var) (*var)

/* Access member 'ReplyAddrElem' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_ReplyAddrElem(var) var

/* Access member 'EnVoiceMailInfo' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_EnVoiceMailInfo(var) (*var)

/* Access member 'EnVoiceMailInfo' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_EnVoiceMailInfo(var) var

/* Access member 'NationalLangSingleShift' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_NationalLangSingleShift(var) var

/* Access member 'NationalLangSingleShift' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_NationalLangSingleShift(var) (&var)

/* Access member 'NationalLangLockingShift' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_NationalLangLockingShift(var) var

/* Access member 'NationalLangLockingShift' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_NationalLangLockingShift(var) (&var)

/* Access member 'UnknownIE' of type 'c_TUserDataIEUnion' as a variable reference */
#define VAR_c_TUserDataIEUnion_UnknownIE(var) (*var)

/* Access member 'UnknownIE' of type 'c_TUserDataIEUnion' as a pointer */
#define PTR_c_TUserDataIEUnion_UnknownIE(var) var

/* DEFINITION OF BINARY c_TUserDataIEUnion_WirelessCtrlMsgProto */
typedef struct _c_TUserDataIEUnion_WirelessCtrlMsgProto {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TUserDataIEUnion_WirelessCtrlMsgProto;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TUserDataIEUnion_WirelessCtrlMsgProto(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_TUserDataIEUnion_ReplyAddrElem */
typedef struct _c_TUserDataIEUnion_ReplyAddrElem {
	ED_BYTE* value; /* Variable size; bits needed 1024 */
	int usedBits;
} c_TUserDataIEUnion_ReplyAddrElem;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TUserDataIEUnion_ReplyAddrElem(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef enum {
	U_c_TUserDataIEUnion_NONE,
	U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum,
	U_c_TUserDataIEUnion_SpecialSmsMsgInd,
	U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr,
	U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr,
	U_c_TUserDataIEUnion_SmscCtrlParams,
	U_c_TUserDataIEUnion_UdhSrcInd,
	U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum,
	U_c_TUserDataIEUnion_WirelessCtrlMsgProto,
	U_c_TUserDataIEUnion_TextFmt,
	U_c_TUserDataIEUnion_PredefSound,
	U_c_TUserDataIEUnion_UserDefSound,
	U_c_TUserDataIEUnion_PredefAnim,
	U_c_TUserDataIEUnion_LargeAnim,
	U_c_TUserDataIEUnion_SmallAnim,
	U_c_TUserDataIEUnion_LargePict,
	U_c_TUserDataIEUnion_SmallPict,
	U_c_TUserDataIEUnion_VarPict,
	U_c_TUserDataIEUnion_UserPromptInd,
	U_c_TUserDataIEUnion_ExtObj,
	U_c_TUserDataIEUnion_ReusedExtObj,
	U_c_TUserDataIEUnion_ComprCtrl,
	U_c_TUserDataIEUnion_ObjDistrInd,
	U_c_TUserDataIEUnion_StdWvgObj,
	U_c_TUserDataIEUnion_CharSizeWvgObj,
	U_c_TUserDataIEUnion_ExtObjDataReqCmd,
	U_c_TUserDataIEUnion_Rfc822EMailHdr,
	U_c_TUserDataIEUnion_HyperlinkFmtElem,
	U_c_TUserDataIEUnion_ReplyAddrElem,
	U_c_TUserDataIEUnion_EnVoiceMailInfo,
	U_c_TUserDataIEUnion_NationalLangSingleShift,
	U_c_TUserDataIEUnion_NationalLangLockingShift,
	U_c_TUserDataIEUnion_UnknownIE
} TPRESENT_c_TUserDataIEUnion;

typedef struct _c_TUserDataIEUnion {

		TPRESENT_c_TUserDataIEUnion Present;
		union {
			c_TConcShortMsgs8BitRefNum *ConcShortMsgs8BitRefNum; /* ODY01 *//*GBD01b*/
		
			c_TSpecialSmsMsgInd *SpecialSmsMsgInd; /* ODY01 *//*GBD01b*/
		
			c_TApplPortAddrScheme8BitAddr *ApplPortAddrScheme8BitAddr; /* ODY01 *//*GBD01b*/
		
			c_TApplPortAddrScheme16BitAddr *ApplPortAddrScheme16BitAddr; /* ODY01 *//*GBD01b*/
		
			c_TSmscCtrlParams *SmscCtrlParams; /* ODY01 *//*GBD01b*/
		
			c_TUdhSrcInd *UdhSrcInd; /* ODY01 *//*GBD01b*/
		
			c_TConcShortMsg16BitRefNum *ConcShortMsg16BitRefNum; /* ODY01 *//*GBD01b*/
		
			c_TUserDataIEUnion_WirelessCtrlMsgProto* WirelessCtrlMsgProto; /* Dynamic, variable size; bits needed 1024 ODY02b *//*GBD01b*/
		
			c_TTextFmt *TextFmt; /* ODY01 *//*GBD01b*/
		
			c_TPredefSound *PredefSound; /* ODY01 *//*GBD01b*/
		
			c_TUserDefSound *UserDefSound; /* ODY01 *//*GBD01b*/
		
			c_TPredefAnim *PredefAnim; /* ODY01 *//*GBD01b*/
		
			c_TLargeAnim *LargeAnim; /* ODY01 *//*GBD01b*/
		
			c_TSmallAnim *SmallAnim; /* ODY01 *//*GBD01b*/
		
			c_TLargePict *LargePict; /* ODY01 *//*GBD01b*/
		
			c_TSmallPict *SmallPict; /* ODY01 *//*GBD01b*/
		
			c_TVarPict *VarPict; /* ODY01 *//*GBD01b*/
		
			c_TUserPromptInd *UserPromptInd; /* ODY01 *//*GBD01b*/
		
			c_TExtObj *ExtObj; /* ODY01 *//*GBD01b*/
		
			c_TReusedExtObj *ReusedExtObj; /* ODY01 *//*GBD01b*/
		
			c_TComprCtrl *ComprCtrl; /* ODY01 *//*GBD01b*/
		
			c_TObjDistrInd *ObjDistrInd; /* ODY01 *//*GBD01b*/
		
			c_TStdWvgObj *StdWvgObj; /* ODY01 *//*GBD01b*/
		
			c_TCharSizeWvgObj *CharSizeWvgObj; /* ODY01 *//*GBD01b*/
		
			/*GBD01b*/
		
			c_TRfc822EMailHdr *Rfc822EMailHdr; /* ODY01 *//*GBD01b*/
		
			c_THyperlinkFmtElem *HyperlinkFmtElem; /* ODY01 *//*GBD01b*/
		
			c_TUserDataIEUnion_ReplyAddrElem* ReplyAddrElem; /* Dynamic, variable size; bits needed 1024 ODY02b *//*GBD01b*/
		
			c_TEnVoiceMailInfo *EnVoiceMailInfo; /* ODY01 *//*GBD01b*/
		
			ED_OCTET NationalLangSingleShift; /* ODY01a *//*GBD01b*/
		
			ED_OCTET NationalLangLockingShift; /* ODY01a *//*GBD01b*/
		
			c_TUnknownIE *UnknownIE; /* ODY01 *//*GBD01b*/
		
		} u;
			union {
				ED_LOCATOR WirelessCtrlMsgProto___LOCATOR  /*LBD01*/;
				ED_LOCATOR ReplyAddrElem___LOCATOR  /*LBD01*/;
				ED_LOCATOR NationalLangSingleShift___LOCATOR; /* QUI2 */
				ED_LOCATOR NationalLangLockingShift___LOCATOR; /* QUI2 */
			} u_locator;

}	c_TUserDataIEUnion;
#define INIT_c_TUserDataIEUnion(sp) ED_RESET_MEM ((sp), sizeof (c_TUserDataIEUnion))
/*FRK01a*/
void FREE_c_TUserDataIEUnion (c_TUserDataIEUnion* sp);

/* SETPRESENT commands for type 'c_TUserDataIEUnion' */
int GLOB_SETPRESENT_c_TUserDataIEUnion (c_TUserDataIEUnion* sp, TPRESENT_c_TUserDataIEUnion toBeSetPresent);
#define SETPRESENT_c_TUserDataIEUnion_NONE(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_NONE)
#define GETPRESENT_c_TUserDataIEUnion_NONE(sp) ((sp)->Present == U_c_TUserDataIEUnion_NONE)
#define SETPRESENT_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum)
#define GETPRESENT_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum(sp) ((sp)->Present == U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum)
#define SETPRESENT_c_TUserDataIEUnion_SpecialSmsMsgInd(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_SpecialSmsMsgInd)
#define GETPRESENT_c_TUserDataIEUnion_SpecialSmsMsgInd(sp) ((sp)->Present == U_c_TUserDataIEUnion_SpecialSmsMsgInd)
#define SETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr)
#define GETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr(sp) ((sp)->Present == U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr)
#define SETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr)
#define GETPRESENT_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr(sp) ((sp)->Present == U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr)
#define SETPRESENT_c_TUserDataIEUnion_SmscCtrlParams(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_SmscCtrlParams)
#define GETPRESENT_c_TUserDataIEUnion_SmscCtrlParams(sp) ((sp)->Present == U_c_TUserDataIEUnion_SmscCtrlParams)
#define SETPRESENT_c_TUserDataIEUnion_UdhSrcInd(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_UdhSrcInd)
#define GETPRESENT_c_TUserDataIEUnion_UdhSrcInd(sp) ((sp)->Present == U_c_TUserDataIEUnion_UdhSrcInd)
#define SETPRESENT_c_TUserDataIEUnion_ConcShortMsg16BitRefNum(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum)
#define GETPRESENT_c_TUserDataIEUnion_ConcShortMsg16BitRefNum(sp) ((sp)->Present == U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum)
#define SETPRESENT_c_TUserDataIEUnion_WirelessCtrlMsgProto(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_WirelessCtrlMsgProto)
#define GETPRESENT_c_TUserDataIEUnion_WirelessCtrlMsgProto(sp) ((sp)->Present == U_c_TUserDataIEUnion_WirelessCtrlMsgProto)
#define SETPRESENT_c_TUserDataIEUnion_TextFmt(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_TextFmt)
#define GETPRESENT_c_TUserDataIEUnion_TextFmt(sp) ((sp)->Present == U_c_TUserDataIEUnion_TextFmt)
#define SETPRESENT_c_TUserDataIEUnion_PredefSound(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_PredefSound)
#define GETPRESENT_c_TUserDataIEUnion_PredefSound(sp) ((sp)->Present == U_c_TUserDataIEUnion_PredefSound)
#define SETPRESENT_c_TUserDataIEUnion_UserDefSound(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_UserDefSound)
#define GETPRESENT_c_TUserDataIEUnion_UserDefSound(sp) ((sp)->Present == U_c_TUserDataIEUnion_UserDefSound)
#define SETPRESENT_c_TUserDataIEUnion_PredefAnim(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_PredefAnim)
#define GETPRESENT_c_TUserDataIEUnion_PredefAnim(sp) ((sp)->Present == U_c_TUserDataIEUnion_PredefAnim)
#define SETPRESENT_c_TUserDataIEUnion_LargeAnim(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_LargeAnim)
#define GETPRESENT_c_TUserDataIEUnion_LargeAnim(sp) ((sp)->Present == U_c_TUserDataIEUnion_LargeAnim)
#define SETPRESENT_c_TUserDataIEUnion_SmallAnim(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_SmallAnim)
#define GETPRESENT_c_TUserDataIEUnion_SmallAnim(sp) ((sp)->Present == U_c_TUserDataIEUnion_SmallAnim)
#define SETPRESENT_c_TUserDataIEUnion_LargePict(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_LargePict)
#define GETPRESENT_c_TUserDataIEUnion_LargePict(sp) ((sp)->Present == U_c_TUserDataIEUnion_LargePict)
#define SETPRESENT_c_TUserDataIEUnion_SmallPict(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_SmallPict)
#define GETPRESENT_c_TUserDataIEUnion_SmallPict(sp) ((sp)->Present == U_c_TUserDataIEUnion_SmallPict)
#define SETPRESENT_c_TUserDataIEUnion_VarPict(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_VarPict)
#define GETPRESENT_c_TUserDataIEUnion_VarPict(sp) ((sp)->Present == U_c_TUserDataIEUnion_VarPict)
#define SETPRESENT_c_TUserDataIEUnion_UserPromptInd(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_UserPromptInd)
#define GETPRESENT_c_TUserDataIEUnion_UserPromptInd(sp) ((sp)->Present == U_c_TUserDataIEUnion_UserPromptInd)
#define SETPRESENT_c_TUserDataIEUnion_ExtObj(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ExtObj)
#define GETPRESENT_c_TUserDataIEUnion_ExtObj(sp) ((sp)->Present == U_c_TUserDataIEUnion_ExtObj)
#define SETPRESENT_c_TUserDataIEUnion_ReusedExtObj(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ReusedExtObj)
#define GETPRESENT_c_TUserDataIEUnion_ReusedExtObj(sp) ((sp)->Present == U_c_TUserDataIEUnion_ReusedExtObj)
#define SETPRESENT_c_TUserDataIEUnion_ComprCtrl(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ComprCtrl)
#define GETPRESENT_c_TUserDataIEUnion_ComprCtrl(sp) ((sp)->Present == U_c_TUserDataIEUnion_ComprCtrl)
#define SETPRESENT_c_TUserDataIEUnion_ObjDistrInd(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ObjDistrInd)
#define GETPRESENT_c_TUserDataIEUnion_ObjDistrInd(sp) ((sp)->Present == U_c_TUserDataIEUnion_ObjDistrInd)
#define SETPRESENT_c_TUserDataIEUnion_StdWvgObj(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_StdWvgObj)
#define GETPRESENT_c_TUserDataIEUnion_StdWvgObj(sp) ((sp)->Present == U_c_TUserDataIEUnion_StdWvgObj)
#define SETPRESENT_c_TUserDataIEUnion_CharSizeWvgObj(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_CharSizeWvgObj)
#define GETPRESENT_c_TUserDataIEUnion_CharSizeWvgObj(sp) ((sp)->Present == U_c_TUserDataIEUnion_CharSizeWvgObj)
#define SETPRESENT_c_TUserDataIEUnion_ExtObjDataReqCmd(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ExtObjDataReqCmd)
#define GETPRESENT_c_TUserDataIEUnion_ExtObjDataReqCmd(sp) ((sp)->Present == U_c_TUserDataIEUnion_ExtObjDataReqCmd)
#define SETPRESENT_c_TUserDataIEUnion_Rfc822EMailHdr(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_Rfc822EMailHdr)
#define GETPRESENT_c_TUserDataIEUnion_Rfc822EMailHdr(sp) ((sp)->Present == U_c_TUserDataIEUnion_Rfc822EMailHdr)
#define SETPRESENT_c_TUserDataIEUnion_HyperlinkFmtElem(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_HyperlinkFmtElem)
#define GETPRESENT_c_TUserDataIEUnion_HyperlinkFmtElem(sp) ((sp)->Present == U_c_TUserDataIEUnion_HyperlinkFmtElem)
#define SETPRESENT_c_TUserDataIEUnion_ReplyAddrElem(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_ReplyAddrElem)
#define GETPRESENT_c_TUserDataIEUnion_ReplyAddrElem(sp) ((sp)->Present == U_c_TUserDataIEUnion_ReplyAddrElem)
#define SETPRESENT_c_TUserDataIEUnion_EnVoiceMailInfo(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_EnVoiceMailInfo)
#define GETPRESENT_c_TUserDataIEUnion_EnVoiceMailInfo(sp) ((sp)->Present == U_c_TUserDataIEUnion_EnVoiceMailInfo)
#define SETPRESENT_c_TUserDataIEUnion_NationalLangSingleShift(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_NationalLangSingleShift)
#define GETPRESENT_c_TUserDataIEUnion_NationalLangSingleShift(sp) ((sp)->Present == U_c_TUserDataIEUnion_NationalLangSingleShift)
#define SETPRESENT_c_TUserDataIEUnion_NationalLangLockingShift(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_NationalLangLockingShift)
#define GETPRESENT_c_TUserDataIEUnion_NationalLangLockingShift(sp) ((sp)->Present == U_c_TUserDataIEUnion_NationalLangLockingShift)
#define SETPRESENT_c_TUserDataIEUnion_UnknownIE(sp) GLOB_SETPRESENT_c_TUserDataIEUnion(sp, U_c_TUserDataIEUnion_UnknownIE)
#define GETPRESENT_c_TUserDataIEUnion_UnknownIE(sp) ((sp)->Present == U_c_TUserDataIEUnion_UnknownIE)
#define GETPRESENT_c_TUserDataIEUnion(sp) ((sp)->Present)


/* Access member 'data' of type 'c_TUserDataIE' as a variable reference */
#define VAR_c_TUserDataIE_data(var) (*var)

/* Access member 'data' of type 'c_TUserDataIE' as a pointer */
#define PTR_c_TUserDataIE_data(var) var


/*-A----------------------------------*/
typedef struct _c_TUserDataIE {

		c_TUserDataIEUnion **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_TUserDataIE;
#define INIT_c_TUserDataIE(sp) ED_RESET_MEM ((sp), sizeof (c_TUserDataIE))
/*FRK02b*/
void FREE_c_TUserDataIE (c_TUserDataIE* sp);
/* SETITEMS/ADDITEMS commands for type 'c_TUserDataIE'. */
int SETITEMS_c_TUserDataIE (c_TUserDataIE* sequence, int desiredItems);
#define ADDITEMS_c_TUserDataIE(sequence, itemsToBeAdded) SETITEMS_c_TUserDataIE (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'Year' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Year(var) var

/* Access member 'Year' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Year(var) (&var)

/* Access member 'Month' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Month(var) var

/* Access member 'Month' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Month(var) (&var)

/* Access member 'Day' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Day(var) var

/* Access member 'Day' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Day(var) (&var)

/* Access member 'Hour' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Hour(var) var

/* Access member 'Hour' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Hour(var) (&var)

/* Access member 'Minute' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Minute(var) var

/* Access member 'Minute' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Minute(var) (&var)

/* Access member 'Second' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_Second(var) var

/* Access member 'Second' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_Second(var) (&var)

/* Access member 'TimeZone' of type 'c_TTimeStamp' as a variable reference */
#define VAR_c_TTimeStamp_TimeZone(var) var

/* Access member 'TimeZone' of type 'c_TTimeStamp' as a pointer */
#define PTR_c_TTimeStamp_TimeZone(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TTimeStamp {
	ED_LOCATOR Year___LOCATOR; /* QUI2 */
	ED_LOCATOR Month___LOCATOR; /* QUI2 */
	ED_LOCATOR Day___LOCATOR; /* QUI2 */
	ED_LOCATOR Hour___LOCATOR; /* QUI2 */
	ED_LOCATOR Minute___LOCATOR; /* QUI2 */
	ED_LOCATOR Second___LOCATOR; /* QUI2 */
	ED_LOCATOR TimeZone___LOCATOR; /* QUI2 */

	ED_OCTET Year; /* ODY01a *//*GBD01b*/
	ED_OCTET Month; /* ODY01a *//*GBD01b*/
	ED_OCTET Day; /* ODY01a *//*GBD01b*/
	ED_OCTET Hour; /* ODY01a *//*GBD01b*/
	ED_OCTET Minute; /* ODY01a *//*GBD01b*/
	ED_OCTET Second; /* ODY01a *//*GBD01b*/
	ED_OCTET TimeZone; /* ODY01a *//*GBD01b*/

}	c_TTimeStamp;
#define INIT_c_TTimeStamp(sp) ED_RESET_MEM ((sp), sizeof (c_TTimeStamp))
/*FRK03a*/
void FREE_c_TTimeStamp(c_TTimeStamp* sp);

/* Access member 'Extension' of type 'c_TP_PI' as a variable reference */
#define VAR_c_TP_PI_Extension(var) var

/* Access member 'Extension' of type 'c_TP_PI' as a pointer */
#define PTR_c_TP_PI_Extension(var) (&var)

/* Access member 'Reserved' of type 'c_TP_PI' as a variable reference */
#define VAR_c_TP_PI_Reserved(var) var

/* Access member 'Reserved' of type 'c_TP_PI' as a pointer */
#define PTR_c_TP_PI_Reserved(var) (&var)

/* Access member 'TP_UDL' of type 'c_TP_PI' as a variable reference */
#define VAR_c_TP_PI_TP_UDL(var) var

/* Access member 'TP_UDL' of type 'c_TP_PI' as a pointer */
#define PTR_c_TP_PI_TP_UDL(var) (&var)

/* Access member 'TP_DCS' of type 'c_TP_PI' as a variable reference */
#define VAR_c_TP_PI_TP_DCS(var) var

/* Access member 'TP_DCS' of type 'c_TP_PI' as a pointer */
#define PTR_c_TP_PI_TP_DCS(var) (&var)

/* Access member 'TP_PID' of type 'c_TP_PI' as a variable reference */
#define VAR_c_TP_PI_TP_PID(var) var

/* Access member 'TP_PID' of type 'c_TP_PI' as a pointer */
#define PTR_c_TP_PI_TP_PID(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TP_PI {
	ED_LOCATOR Extension___LOCATOR; /* QUI2 */
	ED_LOCATOR Reserved___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_UDL___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_DCS___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_PID___LOCATOR; /* QUI2 */

	ED_BOOLEAN Extension; /* ODY01a *//*GBD01b*/
	ED_OCTET Reserved; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDL; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_DCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_PID; /* ODY01a *//*GBD01b*/

}	c_TP_PI;
#define INIT_c_TP_PI(sp) ED_RESET_MEM ((sp), sizeof (c_TP_PI))
/*FRK03a*/
void FREE_c_TP_PI(c_TP_PI* sp);

/* Access member 'PIDType' of type 'c_TP_PID' as a variable reference */
#define VAR_c_TP_PID_PIDType(var) var

/* Access member 'PIDType' of type 'c_TP_PID' as a pointer */
#define PTR_c_TP_PID_PIDType(var) (&var)

/* Access member 'TelematicInterneworking' of type 'c_TP_PID' as a variable reference */
#define VAR_c_TP_PID_TelematicInterneworking(var) var

/* Access member 'TelematicInterneworking' of type 'c_TP_PID' as a pointer */
#define PTR_c_TP_PID_TelematicInterneworking(var) (&var)

/* Access member 'TelematicInterneworkingType' of type 'c_TP_PID' as a variable reference */
#define VAR_c_TP_PID_TelematicInterneworkingType(var) var

/* Access member 'TelematicInterneworkingType' of type 'c_TP_PID' as a pointer */
#define PTR_c_TP_PID_TelematicInterneworkingType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TP_PID {
	ED_LOCATOR PIDType___LOCATOR; /* QUI2 */
	ED_LOCATOR TelematicInterneworking___LOCATOR; /* QUI2 */
	ED_LOCATOR TelematicInterneworkingType___LOCATOR; /* QUI2 */

	ED_OCTET PIDType; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TelematicInterneworking; /* ODY01a *//*GBD01b*/
	ED_OCTET TelematicInterneworkingType; /* ODY01a *//*GBD01b*/

}	c_TP_PID;
#define INIT_c_TP_PID(sp) ED_RESET_MEM ((sp), sizeof (c_TP_PID))
/*FRK03a*/
void FREE_c_TP_PID(c_TP_PID* sp);

/* Access member 'RawData' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_RawData(var) var

/* Access member 'RawData' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_RawData(var) (&var)

/* Access member 'Content' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_Content(var) var

/* Access member 'Content' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_Content(var) (&var)

/* Access member 'Compressed' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_Compressed(var) var

/* Access member 'Compressed' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_Compressed(var) (&var)

/* Access member 'MessageClass' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_MessageClass(var) var

/* Access member 'MessageClass' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_MessageClass(var) (&var)

/* Access member 'CharSet' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_CharSet(var) var

/* Access member 'CharSet' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_CharSet(var) (&var)

/* Access member 'SetIndicationActive' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_SetIndicationActive(var) var

/* Access member 'SetIndicationActive' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_SetIndicationActive(var) (&var)

/* Access member 'IndicationType' of type 'c_TP_DCS' as a variable reference */
#define VAR_c_TP_DCS_IndicationType(var) var

/* Access member 'IndicationType' of type 'c_TP_DCS' as a pointer */
#define PTR_c_TP_DCS_IndicationType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TP_DCS {
	ED_LOCATOR RawData___LOCATOR; /* QUI2 */
	ED_LOCATOR Content___LOCATOR; /* QUI2 */
	ED_LOCATOR Compressed___LOCATOR; /* QUI2 */
	ED_LOCATOR MessageClass___LOCATOR; /* QUI2 */
	ED_LOCATOR CharSet___LOCATOR; /* QUI2 */
	ED_LOCATOR SetIndicationActive___LOCATOR; /* QUI2 */
	ED_LOCATOR IndicationType___LOCATOR; /* QUI2 */

	ED_OCTET RawData; /* ODY01a *//*GBD01b*/
	ED_LONG Content; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Compressed; /* ODY01a *//*GBD01b*/
	ED_LONG MessageClass; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MessageClass_Present;
	ED_LONG CharSet; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SetIndicationActive; /* ODY01a *//*GBD01b*/
	ED_LONG IndicationType; /* ODY01a *//*GBD01b*/

}	c_TP_DCS;
#define INIT_c_TP_DCS(sp) ED_RESET_MEM ((sp), sizeof (c_TP_DCS))
/*FRK03a*/
void FREE_c_TP_DCS(c_TP_DCS* sp);
#define SETPRESENT_c_TP_DCS_MessageClass(sp,present) (((sp)->MessageClass_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TP_DCS_MessageClass(sp) ((sp)->MessageClass_Present)

/* Access member 'Relative' of type 'c_TP_VP' as a variable reference */
#define VAR_c_TP_VP_Relative(var) var

/* Access member 'Relative' of type 'c_TP_VP' as a pointer */
#define PTR_c_TP_VP_Relative(var) (&var)

/* Access member 'Absolute' of type 'c_TP_VP_Absolute' as a variable reference */
#define VAR_c_TP_VP_Absolute_Absolute(var) var

/* Access member 'Absolute' of type 'c_TP_VP_Absolute' as a pointer */
#define PTR_c_TP_VP_Absolute_Absolute(var) (&var)

/* Access member 'Absolute' of type 'c_TP_VP' as a variable reference */
#define VAR_c_TP_VP_Absolute(var) (*var)

/* Access member 'Absolute' of type 'c_TP_VP' as a pointer */
#define PTR_c_TP_VP_Absolute(var) var

/* Access member 'SingleShotSM' of type 'c_TP_VP_Enhanced' as a variable reference */
#define VAR_c_TP_VP_Enhanced_SingleShotSM(var) var

/* Access member 'SingleShotSM' of type 'c_TP_VP_Enhanced' as a pointer */
#define PTR_c_TP_VP_Enhanced_SingleShotSM(var) (&var)

/* Access member 'ValidityPeriodFormat' of type 'c_TP_VP_Enhanced' as a variable reference */
#define VAR_c_TP_VP_Enhanced_ValidityPeriodFormat(var) var

/* Access member 'ValidityPeriodFormat' of type 'c_TP_VP_Enhanced' as a pointer */
#define PTR_c_TP_VP_Enhanced_ValidityPeriodFormat(var) (&var)

/* Access member 'NoValidityPeriod' of type 'c_TP_VP_Enhanced_Extension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_NoValidityPeriod(var) var

/* Access member 'NoValidityPeriod' of type 'c_TP_VP_Enhanced_Extension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_NoValidityPeriod(var) (&var)

/* Access member 'Relative' of type 'c_TP_VP_Enhanced_Extension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_Relative(var) var

/* Access member 'Relative' of type 'c_TP_VP_Enhanced_Extension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_Relative(var) (&var)

/* Access member 'RelativeInteger' of type 'c_TP_VP_Enhanced_Extension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_RelativeInteger(var) var

/* Access member 'RelativeInteger' of type 'c_TP_VP_Enhanced_Extension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_RelativeInteger(var) (&var)

/* Access member 'RelativeSemiOctet' of type 'c_TP_VP_Enhanced_Extension_RelativeSemiOctet' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_RelativeSemiOctet_RelativeSemiOctet(var) var

/* Access member 'RelativeSemiOctet' of type 'c_TP_VP_Enhanced_Extension_RelativeSemiOctet' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_RelativeSemiOctet_RelativeSemiOctet(var) (&var)

/* Access member 'RelativeSemiOctet' of type 'c_TP_VP_Enhanced_Extension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_RelativeSemiOctet(var) (*var)

/* Access member 'RelativeSemiOctet' of type 'c_TP_VP_Enhanced_Extension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_RelativeSemiOctet(var) var

/* Access member 'ExtensionBit' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_UnknownExtension_ExtensionBit(var) var

/* Access member 'ExtensionBit' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_UnknownExtension_ExtensionBit(var) (&var)

/* Access member 'UnknownOctets' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets_UnknownOctets(var) var

/* Access member 'UnknownOctets' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets_UnknownOctets(var) (&var)

/* Access member 'UnknownOctets' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets(var) var

/* Access member 'UnknownOctets' of type 'c_TP_VP_Enhanced_Extension_UnknownExtension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets(var) (&var)

/* Access member 'UnknownExtension' of type 'c_TP_VP_Enhanced_Extension' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension_UnknownExtension(var) (*var)

/* Access member 'UnknownExtension' of type 'c_TP_VP_Enhanced_Extension' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension_UnknownExtension(var) var

/* Access member 'Extension' of type 'c_TP_VP_Enhanced' as a variable reference */
#define VAR_c_TP_VP_Enhanced_Extension(var) var

/* Access member 'Extension' of type 'c_TP_VP_Enhanced' as a pointer */
#define PTR_c_TP_VP_Enhanced_Extension(var) (&var)

/* Access member 'Enhanced' of type 'c_TP_VP' as a variable reference */
#define VAR_c_TP_VP_Enhanced(var) (*var)

/* Access member 'Enhanced' of type 'c_TP_VP' as a pointer */
#define PTR_c_TP_VP_Enhanced(var) var

/* DEFINITION OF SUB-STRUCTURE c_TP_VP_Enhanced_Extension_UnknownExtension */
typedef struct _c_TP_VP_Enhanced_Extension_UnknownExtension {
	ED_LOCATOR ExtensionBit___LOCATOR; /* QUI2 */
	ED_LOCATOR UnknownOctets___LOCATOR [6]; /* QUI2 */

	ED_BOOLEAN ExtensionBit; /* ODY01a *//*GBD01b*/
	ED_OCTET UnknownOctets [6]/*GAD01*/; /* ODY01a *//*GBD01b*//*GAD01a*//*GFBA-2*//*GFBA-3*//*GBD01b*/

} c_TP_VP_Enhanced_Extension_UnknownExtension;

/* DEFINITION OF SUB-STRUCTURE c_TP_VP_Enhanced_Extension */
typedef enum {
	U_c_TP_VP_Enhanced_Extension_NONE,
	U_c_TP_VP_Enhanced_Extension_NoValidityPeriod,
	U_c_TP_VP_Enhanced_Extension_Relative,
	U_c_TP_VP_Enhanced_Extension_RelativeInteger,
	U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet,
	U_c_TP_VP_Enhanced_Extension_UnknownExtension
} TPRESENT_c_TP_VP_Enhanced_Extension;

typedef struct _c_TP_VP_Enhanced_Extension {

	TPRESENT_c_TP_VP_Enhanced_Extension Present;
	union {
		ED_BOOLEAN NoValidityPeriod; /* ODY01a *//*GBD01b*/
	
		ED_OCTET Relative; /* ODY01a *//*GBD01b*/
	
		ED_OCTET RelativeInteger; /* ODY01a *//*GBD01b*/
	
		ED_OCTET* RelativeSemiOctet ; /*  Dynamic array locator  *//*GBD01b*/
	
		c_TP_VP_Enhanced_Extension_UnknownExtension *UnknownExtension; /* ODY03 <> *//*GBD01b*/
	
	} u;
		union {
			ED_LOCATOR NoValidityPeriod___LOCATOR; /* QUI2 */
			ED_LOCATOR Relative___LOCATOR; /* QUI2 */
			ED_LOCATOR RelativeInteger___LOCATOR; /* QUI2 */
			ED_LOCATOR RelativeSemiOctet___LOCATOR [6]; /* QUI2 */
		} u_locator;

} c_TP_VP_Enhanced_Extension;

/* DEFINITION OF SUB-STRUCTURE c_TP_VP_Enhanced */
typedef struct _c_TP_VP_Enhanced {
	ED_LOCATOR SingleShotSM___LOCATOR; /* QUI2 */
	ED_LOCATOR ValidityPeriodFormat___LOCATOR; /* QUI2 */

	ED_BOOLEAN SingleShotSM; /* ODY01a *//*GBD01b*/
	ED_LONG ValidityPeriodFormat; /* ODY01a *//*GBD01b*/
	c_TP_VP_Enhanced_Extension Extension;/*GBD01b*/

} c_TP_VP_Enhanced;


/*-A----------------------------------*/
typedef enum {
	U_c_TP_VP_NONE,
	U_c_TP_VP_Relative,
	U_c_TP_VP_Absolute,
	U_c_TP_VP_Enhanced
} TPRESENT_c_TP_VP;

typedef struct _c_TP_VP {

		TPRESENT_c_TP_VP Present;
		union {
			ED_OCTET Relative; /* ODY01a *//*GBD01b*/
		
			ED_OCTET* Absolute ; /*  Dynamic array locator  *//*GBD01b*/
		
			c_TP_VP_Enhanced *Enhanced; /* ODY03 <> *//*GBD01b*/
		
		} u;
			union {
				ED_LOCATOR Relative___LOCATOR; /* QUI2 */
				ED_LOCATOR Absolute___LOCATOR [14]; /* QUI2 */
			} u_locator;

}	c_TP_VP;
#define INIT_c_TP_VP(sp) ED_RESET_MEM ((sp), sizeof (c_TP_VP))
/*FRK01a*/
void FREE_c_TP_VP (c_TP_VP* sp);

/* SETPRESENT commands for type 'c_TP_VP' */
int GLOB_SETPRESENT_c_TP_VP (c_TP_VP* sp, TPRESENT_c_TP_VP toBeSetPresent);
#define SETPRESENT_c_TP_VP_NONE(sp) GLOB_SETPRESENT_c_TP_VP(sp, U_c_TP_VP_NONE)
#define GETPRESENT_c_TP_VP_NONE(sp) ((sp)->Present == U_c_TP_VP_NONE)
#define SETPRESENT_c_TP_VP_Relative(sp) GLOB_SETPRESENT_c_TP_VP(sp, U_c_TP_VP_Relative)
#define GETPRESENT_c_TP_VP_Relative(sp) ((sp)->Present == U_c_TP_VP_Relative)
#define SETPRESENT_c_TP_VP_Absolute(sp) GLOB_SETPRESENT_c_TP_VP(sp, U_c_TP_VP_Absolute)
#define GETPRESENT_c_TP_VP_Absolute(sp) ((sp)->Present == U_c_TP_VP_Absolute)
#define SETPRESENT_c_TP_VP_Enhanced(sp) GLOB_SETPRESENT_c_TP_VP(sp, U_c_TP_VP_Enhanced)
#define GETPRESENT_c_TP_VP_Enhanced(sp) ((sp)->Present == U_c_TP_VP_Enhanced)
#define GETPRESENT_c_TP_VP(sp) ((sp)->Present)


/* Access member 'data' of type 'c_TP_CD' as a variable reference */
#define VAR_c_TP_CD_data(var) var

/* Access member 'data' of type 'c_TP_CD' as a pointer */
#define PTR_c_TP_CD_data(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TP_CD {

		ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-3249=EDCore::TDMSequence)  */
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_TP_CD;
#define INIT_c_TP_CD(sp) ED_RESET_MEM ((sp), sizeof (c_TP_CD))
/*FRK02b*/
void FREE_c_TP_CD (c_TP_CD* sp);
/* SETITEMS/ADDITEMS commands for type 'c_TP_CD'. */
int SETITEMS_c_TP_CD (c_TP_CD* sequence, int desiredItems);
#define ADDITEMS_c_TP_CD(sequence, itemsToBeAdded) SETITEMS_c_TP_CD (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'Header' of type 'c_TP_UD' as a variable reference */
#define VAR_c_TP_UD_Header(var) var

/* Access member 'Header' of type 'c_TP_UD' as a pointer */
#define PTR_c_TP_UD_Header(var) (&var)

/* Access member 'data' of type 'c_TP_UD_Message' as a variable reference */
#define VAR_c_TP_UD_Message_data(var) var

/* Access member 'data' of type 'c_TP_UD_Message' as a pointer */
#define PTR_c_TP_UD_Message_data(var) (&var)

/* Access member 'Message' of type 'c_TP_UD' as a variable reference */
#define VAR_c_TP_UD_Message(var) var

/* Access member 'Message' of type 'c_TP_UD' as a pointer */
#define PTR_c_TP_UD_Message(var) (&var)

/* Access member 'CharSet' of type 'c_TP_UD' as a variable reference */
#define VAR_c_TP_UD_CharSet(var) var

/* Access member 'CharSet' of type 'c_TP_UD' as a pointer */
#define PTR_c_TP_UD_CharSet(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_TP_UD_Message */
typedef struct _c_TP_UD_Message {

	ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-3257=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TP_UD_Message;


/*-A----------------------------------*/
typedef struct _c_TP_UD {
	ED_LOCATOR CharSet___LOCATOR; /* QUI2 */

	c_TUserDataIE Header; /* ODY01a *//*GBD01b*/
	c_TP_UD_Message Message;/*GFB09*//*GBD01b*/
	ED_LONG CharSet; /* ODY01a *//*GBD01b*/

}	c_TP_UD;
#define INIT_c_TP_UD(sp) ED_RESET_MEM ((sp), sizeof (c_TP_UD))
/*FRK03a*/
void FREE_c_TP_UD(c_TP_UD* sp);

/* Access member 'TP_MTI' of type 'c_TP_MTI' as a variable reference */
#define VAR_c_TP_MTI_TP_MTI(var) var

/* Access member 'TP_MTI' of type 'c_TP_MTI' as a pointer */
#define PTR_c_TP_MTI_TP_MTI(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TP_MTI {
	ED_LOCATOR TP_MTI___LOCATOR; /* QUI2 */

	ED_LONG TP_MTI; /* ODY01a *//*GBD01b*/

}	c_TP_MTI;
#define INIT_c_TP_MTI(sp) ED_RESET_MEM ((sp), sizeof (c_TP_MTI))
/*FRK03a*/
void FREE_c_TP_MTI(c_TP_MTI* sp);

/* Access member 'UnknownSMSData' of type 'c_SMS_UNKNOWN' as a variable reference */
#define VAR_c_SMS_UNKNOWN_UnknownSMSData(var) var

/* Access member 'UnknownSMSData' of type 'c_SMS_UNKNOWN' as a pointer */
#define PTR_c_SMS_UNKNOWN_UnknownSMSData(var) (&var)

/* DEFINITION OF BINARY c_SMS_UNKNOWN_UnknownSMSData */
typedef struct _c_SMS_UNKNOWN_UnknownSMSData {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_UNKNOWN_UnknownSMSData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_UNKNOWN_UnknownSMSData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_UNKNOWN {
	ED_LOCATOR UnknownSMSData___LOCATOR  /*LBD02*/;

	c_SMS_UNKNOWN_UnknownSMSData UnknownSMSData; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_UNKNOWN;
#define INIT_c_SMS_UNKNOWN(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_UNKNOWN))
/*FRK03a*/
void FREE_c_SMS_UNKNOWN(c_SMS_UNKNOWN* sp);

/* Access member 'header' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_header(var) var

/* Access member 'header' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_header(var) (&var)

/* Access member 'TP_MMS' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_MMS(var) var

/* Access member 'TP_MMS' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_MMS(var) (&var)

/* Access member 'TP_LO' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_LO(var) var

/* Access member 'TP_LO' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_LO(var) (&var)

/* Access member 'TP_RP' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_RP(var) var

/* Access member 'TP_RP' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_RP(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_UDHI(var) (&var)

/* Access member 'TP_SRI' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_SRI(var) var

/* Access member 'TP_SRI' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_SRI(var) (&var)

/* Access member 'TP_OA' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_OA(var) var

/* Access member 'TP_OA' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_OA(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_PID(var) var

/* Access member 'TP_PID' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_PID(var) (&var)

/* Access member 'TP_DCS' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_DCS(var) var

/* Access member 'TP_DCS' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_DCS(var) (&var)

/* Access member 'TP_SCTS' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_SCTS(var) var

/* Access member 'TP_SCTS' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_SCTS(var) (&var)

/* Access member 'TP_UD' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_TP_UD(var) var

/* Access member 'TP_UD' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_TP_UD(var) (&var)

/* Access member 'spare' of type 'c_SMS_DELIVER' as a variable reference */
#define VAR_c_SMS_DELIVER_spare(var) var

/* Access member 'spare' of type 'c_SMS_DELIVER' as a pointer */
#define PTR_c_SMS_DELIVER_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_DELIVER_spare */
typedef struct _c_SMS_DELIVER_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_DELIVER_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_DELIVER_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_DELIVER {
	ED_LOCATOR TP_MMS___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_LO___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_RP___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_SRI___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_MMS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_LO; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_RP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_SRI; /* ODY01a *//*GBD01b*/
	c_TAddress TP_OA; /* ODY01a *//*GBD01b*/
	c_TP_PID TP_PID; /* ODY01a *//*GBD01b*/
	c_TP_DCS TP_DCS; /* ODY01a *//*GBD01b*/
	c_TTimeStamp TP_SCTS; /* ODY01a *//*GBD01b*/
	c_TP_UD TP_UD; /* ODY01a *//*GBD01b*/
	c_SMS_DELIVER_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_DELIVER;
#define INIT_c_SMS_DELIVER(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_DELIVER))
/*FRK03a*/
void FREE_c_SMS_DELIVER(c_SMS_DELIVER* sp);

/* Access member 'header' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_header(var) var

/* Access member 'header' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_UDHI(var) (&var)

/* Access member 'TP_LO' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_LO(var) var

/* Access member 'TP_LO' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_LO(var) (&var)

/* Access member 'TP_MMS' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_MMS(var) var

/* Access member 'TP_MMS' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_MMS(var) (&var)

/* Access member 'TP_SRQ' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_SRQ(var) var

/* Access member 'TP_SRQ' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_SRQ(var) (&var)

/* Access member 'TP_MR' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_MR(var) var

/* Access member 'TP_MR' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_MR(var) (&var)

/* Access member 'TP_RA' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_RA(var) var

/* Access member 'TP_RA' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_RA(var) (&var)

/* Access member 'TP_SCTS' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_SCTS(var) var

/* Access member 'TP_SCTS' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_SCTS(var) (&var)

/* Access member 'TP_DT' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_DT(var) var

/* Access member 'TP_DT' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_DT(var) (&var)

/* Access member 'TP_ST' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_ST(var) var

/* Access member 'TP_ST' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_ST(var) (&var)

/* Access member 'TP_PI' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_PI(var) (*var)

/* Access member 'TP_PI' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_PI(var) var

/* Access member 'TP_PID' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_PID(var) (*var)

/* Access member 'TP_PID' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_PID(var) var

/* Access member 'TP_DCS' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_DCS(var) (*var)

/* Access member 'TP_DCS' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_DCS(var) var

/* Access member 'TP_UD' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_TP_UD(var) (*var)

/* Access member 'TP_UD' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_TP_UD(var) var

/* Access member 'spare' of type 'c_SMS_STATUS_REPORT' as a variable reference */
#define VAR_c_SMS_STATUS_REPORT_spare(var) var

/* Access member 'spare' of type 'c_SMS_STATUS_REPORT' as a pointer */
#define PTR_c_SMS_STATUS_REPORT_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_STATUS_REPORT_spare */
typedef struct _c_SMS_STATUS_REPORT_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_STATUS_REPORT_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_STATUS_REPORT_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_STATUS_REPORT {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_LO___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_MMS___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_SRQ___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_MR___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_ST___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_LO; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_MMS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_SRQ; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_MR; /* ODY01a *//*GBD01b*/
	c_TAddress TP_RA; /* ODY01a *//*GBD01b*/
	c_TTimeStamp TP_SCTS; /* ODY01a *//*GBD01b*/
	c_TTimeStamp TP_DT; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_ST; /* ODY01a *//*GBD01b*/
	c_TP_PI *TP_PI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PI_Present;
	c_TP_PID *TP_PID; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PID_Present;
	c_TP_DCS *TP_DCS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_DCS_Present;
	c_TP_UD *TP_UD; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_UD_Present;
	c_SMS_STATUS_REPORT_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_STATUS_REPORT;
#define INIT_c_SMS_STATUS_REPORT(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_STATUS_REPORT))
/*FRK03a*/
void FREE_c_SMS_STATUS_REPORT(c_SMS_STATUS_REPORT* sp);
int SETPRESENT_c_SMS_STATUS_REPORT_TP_PI (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_STATUS_REPORT_TP_PI(sp) ((sp)->TP_PI_Present)
int SETPRESENT_c_SMS_STATUS_REPORT_TP_PID (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_STATUS_REPORT_TP_PID(sp) ((sp)->TP_PID_Present)
int SETPRESENT_c_SMS_STATUS_REPORT_TP_DCS (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_STATUS_REPORT_TP_DCS(sp) ((sp)->TP_DCS_Present)
int SETPRESENT_c_SMS_STATUS_REPORT_TP_UD (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_STATUS_REPORT_TP_UD(sp) ((sp)->TP_UD_Present)

/* Access member 'header' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_header(var) var

/* Access member 'header' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_header(var) (&var)

/* Access member 'TP_RD' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_RD(var) var

/* Access member 'TP_RD' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_RD(var) (&var)

/* Access member 'TP_VPF' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_VPF(var) var

/* Access member 'TP_VPF' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_VPF(var) (&var)

/* Access member 'TP_RP' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_RP(var) var

/* Access member 'TP_RP' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_RP(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_UDHI(var) (&var)

/* Access member 'TP_SRR' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_SRR(var) var

/* Access member 'TP_SRR' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_SRR(var) (&var)

/* Access member 'TP_MR' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_MR(var) var

/* Access member 'TP_MR' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_MR(var) (&var)

/* Access member 'TP_DA' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_DA(var) var

/* Access member 'TP_DA' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_DA(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_PID(var) var

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_PID(var) (&var)

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_DCS(var) var

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_DCS(var) (&var)

/* Access member 'TP_VP' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_VP(var) (*var)

/* Access member 'TP_VP' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_VP(var) var

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_TP_UD(var) var

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_TP_UD(var) (&var)

/* Access member 'spare' of type 'c_SMS_SUBMIT' as a variable reference */
#define VAR_c_SMS_SUBMIT_spare(var) var

/* Access member 'spare' of type 'c_SMS_SUBMIT' as a pointer */
#define PTR_c_SMS_SUBMIT_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_SUBMIT_spare */
typedef struct _c_SMS_SUBMIT_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_SUBMIT_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_SUBMIT_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_SUBMIT {
	ED_LOCATOR TP_RD___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_VPF___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_RP___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_SRR___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_MR___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_RD; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_VPF; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_RP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_SRR; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_MR; /* ODY01a *//*GBD01b*/
	c_TAddress TP_DA; /* ODY01a *//*GBD01b*/
	c_TP_PID TP_PID; /* ODY01a *//*GBD01b*/
	c_TP_DCS TP_DCS; /* ODY01a *//*GBD01b*/
	c_TP_VP *TP_VP; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_VP_Present;
	c_TP_UD TP_UD; /* ODY01a *//*GBD01b*/
	c_SMS_SUBMIT_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_SUBMIT;
#define INIT_c_SMS_SUBMIT(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SUBMIT))
/*FRK03a*/
void FREE_c_SMS_SUBMIT(c_SMS_SUBMIT* sp);
int SETPRESENT_c_SMS_SUBMIT_TP_VP (c_SMS_SUBMIT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_TP_VP(sp) ((sp)->TP_VP_Present)

/* Access member 'header' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_header(var) var

/* Access member 'header' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_UDHI(var) (&var)

/* Access member 'TP_SRR' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_SRR(var) var

/* Access member 'TP_SRR' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_SRR(var) (&var)

/* Access member 'TP_MR' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_MR(var) var

/* Access member 'TP_MR' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_MR(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_PID(var) var

/* Access member 'TP_PID' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_PID(var) (&var)

/* Access member 'TP_CT' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_CT(var) var

/* Access member 'TP_CT' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_CT(var) (&var)

/* Access member 'TP_MN' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_MN(var) var

/* Access member 'TP_MN' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_MN(var) (&var)

/* Access member 'TP_DA' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_DA(var) var

/* Access member 'TP_DA' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_DA(var) (&var)

/* Access member 'TP_CD' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_TP_CD(var) var

/* Access member 'TP_CD' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_TP_CD(var) (&var)

/* Access member 'spare' of type 'c_SMS_COMMAND' as a variable reference */
#define VAR_c_SMS_COMMAND_spare(var) var

/* Access member 'spare' of type 'c_SMS_COMMAND' as a pointer */
#define PTR_c_SMS_COMMAND_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_COMMAND_spare */
typedef struct _c_SMS_COMMAND_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_COMMAND_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_COMMAND_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_COMMAND {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_SRR___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_MR___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_CT___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_MN___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_SRR; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_MR; /* ODY01a *//*GBD01b*/
	c_TP_PID TP_PID; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_CT; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_MN; /* ODY01a *//*GBD01b*/
	c_TAddress TP_DA; /* ODY01a *//*GBD01b*/
	c_TP_CD TP_CD; /* ODY01a *//*GBD01b*/
	c_SMS_COMMAND_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_COMMAND;
#define INIT_c_SMS_COMMAND(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_COMMAND))
/*FRK03a*/
void FREE_c_SMS_COMMAND(c_SMS_COMMAND* sp);

/* Access member 'Cause' of type 'c_TRPCause' as a variable reference */
#define VAR_c_TRPCause_Cause(var) var

/* Access member 'Cause' of type 'c_TRPCause' as a pointer */
#define PTR_c_TRPCause_Cause(var) (&var)

/* Access member 'Diagnostic' of type 'c_TRPCause' as a variable reference */
#define VAR_c_TRPCause_Diagnostic(var) var

/* Access member 'Diagnostic' of type 'c_TRPCause' as a pointer */
#define PTR_c_TRPCause_Diagnostic(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TRPCause {
	ED_LOCATOR Cause___LOCATOR; /* QUI2 */
	ED_LOCATOR Diagnostic___LOCATOR; /* QUI2 */

	ED_OCTET Cause; /* ODY01a *//*GBD01b*/
	ED_OCTET Diagnostic; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Diagnostic_Present;

}	c_TRPCause;
#define INIT_c_TRPCause(sp) ED_RESET_MEM ((sp), sizeof (c_TRPCause))
/*FRK03a*/
void FREE_c_TRPCause(c_TRPCause* sp);
#define SETPRESENT_c_TRPCause_Diagnostic(sp,present) (((sp)->Diagnostic_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TRPCause_Diagnostic(sp) ((sp)->Diagnostic_Present)

/* Access member 'TypeOfNumber' of type 'c_T24011Address_Addr' as a variable reference */
#define VAR_c_T24011Address_Addr_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_T24011Address_Addr' as a pointer */
#define PTR_c_T24011Address_Addr_TypeOfNumber(var) (&var)

/* Access member 'NumPlanId' of type 'c_T24011Address_Addr' as a variable reference */
#define VAR_c_T24011Address_Addr_NumPlanId(var) var

/* Access member 'NumPlanId' of type 'c_T24011Address_Addr' as a pointer */
#define PTR_c_T24011Address_Addr_NumPlanId(var) (&var)

/* Access member 'data' of type 'c_T24011Address_Addr_Address' as a variable reference */
#define VAR_c_T24011Address_Addr_Address_data(var) var

/* Access member 'data' of type 'c_T24011Address_Addr_Address' as a pointer */
#define PTR_c_T24011Address_Addr_Address_data(var) (&var)

/* Access member 'Address' of type 'c_T24011Address_Addr' as a variable reference */
#define VAR_c_T24011Address_Addr_Address(var) var

/* Access member 'Address' of type 'c_T24011Address_Addr' as a pointer */
#define PTR_c_T24011Address_Addr_Address(var) (&var)

/* Access member 'Addr' of type 'c_T24011Address' as a variable reference */
#define VAR_c_T24011Address_Addr(var) (*var)

/* Access member 'Addr' of type 'c_T24011Address' as a pointer */
#define PTR_c_T24011Address_Addr(var) var

/* DEFINITION OF SUB-STRUCTURE c_T24011Address_Addr_Address */
typedef struct _c_T24011Address_Addr_Address {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-3363=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_T24011Address_Addr_Address;

/* DEFINITION OF SUB-STRUCTURE c_T24011Address_Addr */
typedef struct _c_T24011Address_Addr {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumPlanId___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumPlanId; /* ODY01a *//*GBD01b*/
	c_T24011Address_Addr_Address Address;/*GFB09*//*GBD01b*/

} c_T24011Address_Addr;


/*-A----------------------------------*/
typedef struct _c_T24011Address {

	c_T24011Address_Addr *Addr; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN Addr_Present;

}	c_T24011Address;
#define INIT_c_T24011Address(sp) ED_RESET_MEM ((sp), sizeof (c_T24011Address))
/*FRK03a*/
void FREE_c_T24011Address(c_T24011Address* sp);
int SETPRESENT_c_T24011Address_Addr (c_T24011Address* sp, ED_BOOLEAN present);
#define GETPRESENT_c_T24011Address_Addr(sp) ((sp)->Addr_Present)

/* Access member 'SMS_SUBMIT' of type 'c_SMS_MS2SC' as a variable reference */
#define VAR_c_SMS_MS2SC_SMS_SUBMIT(var) (*var)

/* Access member 'SMS_SUBMIT' of type 'c_SMS_MS2SC' as a pointer */
#define PTR_c_SMS_MS2SC_SMS_SUBMIT(var) var

/* Access member 'SMS_COMMAND' of type 'c_SMS_MS2SC' as a variable reference */
#define VAR_c_SMS_MS2SC_SMS_COMMAND(var) (*var)

/* Access member 'SMS_COMMAND' of type 'c_SMS_MS2SC' as a pointer */
#define PTR_c_SMS_MS2SC_SMS_COMMAND(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC' as a variable reference */
#define VAR_c_SMS_MS2SC_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC' as a pointer */
#define PTR_c_SMS_MS2SC_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_MS2SC_NONE,
	U_c_SMS_MS2SC_SMS_SUBMIT,
	U_c_SMS_MS2SC_SMS_COMMAND,
	U_c_SMS_MS2SC_SMS_UNKNOWN
} TPRESENT_c_SMS_MS2SC;

typedef struct _c_SMS_MS2SC {

		TPRESENT_c_SMS_MS2SC Present;
		union {
			c_SMS_SUBMIT *SMS_SUBMIT; /* ODY01 *//*GBD01b*/
		
			c_SMS_COMMAND *SMS_COMMAND; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_MS2SC;
#define INIT_c_SMS_MS2SC(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_MS2SC))
/*FRK01a*/
void FREE_c_SMS_MS2SC (c_SMS_MS2SC* sp);

/* SETPRESENT commands for type 'c_SMS_MS2SC' */
int GLOB_SETPRESENT_c_SMS_MS2SC (c_SMS_MS2SC* sp, TPRESENT_c_SMS_MS2SC toBeSetPresent);
#define SETPRESENT_c_SMS_MS2SC_NONE(sp) GLOB_SETPRESENT_c_SMS_MS2SC(sp, U_c_SMS_MS2SC_NONE)
#define GETPRESENT_c_SMS_MS2SC_NONE(sp) ((sp)->Present == U_c_SMS_MS2SC_NONE)
#define SETPRESENT_c_SMS_MS2SC_SMS_SUBMIT(sp) GLOB_SETPRESENT_c_SMS_MS2SC(sp, U_c_SMS_MS2SC_SMS_SUBMIT)
#define GETPRESENT_c_SMS_MS2SC_SMS_SUBMIT(sp) ((sp)->Present == U_c_SMS_MS2SC_SMS_SUBMIT)
#define SETPRESENT_c_SMS_MS2SC_SMS_COMMAND(sp) GLOB_SETPRESENT_c_SMS_MS2SC(sp, U_c_SMS_MS2SC_SMS_COMMAND)
#define GETPRESENT_c_SMS_MS2SC_SMS_COMMAND(sp) ((sp)->Present == U_c_SMS_MS2SC_SMS_COMMAND)
#define SETPRESENT_c_SMS_MS2SC_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_MS2SC(sp, U_c_SMS_MS2SC_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_MS2SC_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC(sp) ((sp)->Present)


/* Access member 'SMS_DELIVER' of type 'c_SMS_SC2MS' as a variable reference */
#define VAR_c_SMS_SC2MS_SMS_DELIVER(var) (*var)

/* Access member 'SMS_DELIVER' of type 'c_SMS_SC2MS' as a pointer */
#define PTR_c_SMS_SC2MS_SMS_DELIVER(var) var

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS' as a variable reference */
#define VAR_c_SMS_SC2MS_SMS_STATUS_REPORT(var) (*var)

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS' as a pointer */
#define PTR_c_SMS_SC2MS_SMS_STATUS_REPORT(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS' as a variable reference */
#define VAR_c_SMS_SC2MS_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS' as a pointer */
#define PTR_c_SMS_SC2MS_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_SC2MS_NONE,
	U_c_SMS_SC2MS_SMS_DELIVER,
	U_c_SMS_SC2MS_SMS_STATUS_REPORT,
	U_c_SMS_SC2MS_SMS_UNKNOWN
} TPRESENT_c_SMS_SC2MS;

typedef struct _c_SMS_SC2MS {

		TPRESENT_c_SMS_SC2MS Present;
		union {
			c_SMS_DELIVER *SMS_DELIVER; /* ODY01 *//*GBD01b*/
		
			c_SMS_STATUS_REPORT *SMS_STATUS_REPORT; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_SC2MS;
#define INIT_c_SMS_SC2MS(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SC2MS))
/*FRK01a*/
void FREE_c_SMS_SC2MS (c_SMS_SC2MS* sp);

/* SETPRESENT commands for type 'c_SMS_SC2MS' */
int GLOB_SETPRESENT_c_SMS_SC2MS (c_SMS_SC2MS* sp, TPRESENT_c_SMS_SC2MS toBeSetPresent);
#define SETPRESENT_c_SMS_SC2MS_NONE(sp) GLOB_SETPRESENT_c_SMS_SC2MS(sp, U_c_SMS_SC2MS_NONE)
#define GETPRESENT_c_SMS_SC2MS_NONE(sp) ((sp)->Present == U_c_SMS_SC2MS_NONE)
#define SETPRESENT_c_SMS_SC2MS_SMS_DELIVER(sp) GLOB_SETPRESENT_c_SMS_SC2MS(sp, U_c_SMS_SC2MS_SMS_DELIVER)
#define GETPRESENT_c_SMS_SC2MS_SMS_DELIVER(sp) ((sp)->Present == U_c_SMS_SC2MS_SMS_DELIVER)
#define SETPRESENT_c_SMS_SC2MS_SMS_STATUS_REPORT(sp) GLOB_SETPRESENT_c_SMS_SC2MS(sp, U_c_SMS_SC2MS_SMS_STATUS_REPORT)
#define GETPRESENT_c_SMS_SC2MS_SMS_STATUS_REPORT(sp) ((sp)->Present == U_c_SMS_SC2MS_SMS_STATUS_REPORT)
#define SETPRESENT_c_SMS_SC2MS_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_SC2MS(sp, U_c_SMS_SC2MS_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_SC2MS_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS(sp) ((sp)->Present)


/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_MS2SC_ERR' as a variable reference */
#define VAR_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT(var) (*var)

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_MS2SC_ERR' as a pointer */
#define PTR_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC_ERR' as a variable reference */
#define VAR_c_SMS_MS2SC_ERR_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC_ERR' as a pointer */
#define PTR_c_SMS_MS2SC_ERR_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_MS2SC_ERR_NONE,
	U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT,
	U_c_SMS_MS2SC_ERR_SMS_UNKNOWN
} TPRESENT_c_SMS_MS2SC_ERR;

typedef struct _c_SMS_MS2SC_ERR {

		TPRESENT_c_SMS_MS2SC_ERR Present;
		union {
			c_SMS_STATUS_REPORT *SMS_STATUS_REPORT; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_MS2SC_ERR;
#define INIT_c_SMS_MS2SC_ERR(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_MS2SC_ERR))
/*FRK01a*/
void FREE_c_SMS_MS2SC_ERR (c_SMS_MS2SC_ERR* sp);

/* SETPRESENT commands for type 'c_SMS_MS2SC_ERR' */
int GLOB_SETPRESENT_c_SMS_MS2SC_ERR (c_SMS_MS2SC_ERR* sp, TPRESENT_c_SMS_MS2SC_ERR toBeSetPresent);
#define SETPRESENT_c_SMS_MS2SC_ERR_NONE(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ERR(sp, U_c_SMS_MS2SC_ERR_NONE)
#define GETPRESENT_c_SMS_MS2SC_ERR_NONE(sp) ((sp)->Present == U_c_SMS_MS2SC_ERR_NONE)
#define SETPRESENT_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ERR(sp, U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT)
#define GETPRESENT_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT(sp) ((sp)->Present == U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT)
#define SETPRESENT_c_SMS_MS2SC_ERR_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ERR(sp, U_c_SMS_MS2SC_ERR_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC_ERR_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_MS2SC_ERR_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC_ERR(sp) ((sp)->Present)


/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_MS2SC_ACK' as a variable reference */
#define VAR_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT(var) (*var)

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_MS2SC_ACK' as a pointer */
#define PTR_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC_ACK' as a variable reference */
#define VAR_c_SMS_MS2SC_ACK_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_MS2SC_ACK' as a pointer */
#define PTR_c_SMS_MS2SC_ACK_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_MS2SC_ACK_NONE,
	U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT,
	U_c_SMS_MS2SC_ACK_SMS_UNKNOWN
} TPRESENT_c_SMS_MS2SC_ACK;

typedef struct _c_SMS_MS2SC_ACK {

		TPRESENT_c_SMS_MS2SC_ACK Present;
		union {
			c_SMS_STATUS_REPORT *SMS_STATUS_REPORT; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_MS2SC_ACK;
#define INIT_c_SMS_MS2SC_ACK(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_MS2SC_ACK))
/*FRK01a*/
void FREE_c_SMS_MS2SC_ACK (c_SMS_MS2SC_ACK* sp);

/* SETPRESENT commands for type 'c_SMS_MS2SC_ACK' */
int GLOB_SETPRESENT_c_SMS_MS2SC_ACK (c_SMS_MS2SC_ACK* sp, TPRESENT_c_SMS_MS2SC_ACK toBeSetPresent);
#define SETPRESENT_c_SMS_MS2SC_ACK_NONE(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ACK(sp, U_c_SMS_MS2SC_ACK_NONE)
#define GETPRESENT_c_SMS_MS2SC_ACK_NONE(sp) ((sp)->Present == U_c_SMS_MS2SC_ACK_NONE)
#define SETPRESENT_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ACK(sp, U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT)
#define GETPRESENT_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT(sp) ((sp)->Present == U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT)
#define SETPRESENT_c_SMS_MS2SC_ACK_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_MS2SC_ACK(sp, U_c_SMS_MS2SC_ACK_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC_ACK_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_MS2SC_ACK_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_MS2SC_ACK(sp) ((sp)->Present)


/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS_ERR' as a variable reference */
#define VAR_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT(var) (*var)

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS_ERR' as a pointer */
#define PTR_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS_ERR' as a variable reference */
#define VAR_c_SMS_SC2MS_ERR_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS_ERR' as a pointer */
#define PTR_c_SMS_SC2MS_ERR_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_SC2MS_ERR_NONE,
	U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT,
	U_c_SMS_SC2MS_ERR_SMS_UNKNOWN
} TPRESENT_c_SMS_SC2MS_ERR;

typedef struct _c_SMS_SC2MS_ERR {

		TPRESENT_c_SMS_SC2MS_ERR Present;
		union {
			c_SMS_STATUS_REPORT *SMS_STATUS_REPORT; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_SC2MS_ERR;
#define INIT_c_SMS_SC2MS_ERR(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SC2MS_ERR))
/*FRK01a*/
void FREE_c_SMS_SC2MS_ERR (c_SMS_SC2MS_ERR* sp);

/* SETPRESENT commands for type 'c_SMS_SC2MS_ERR' */
int GLOB_SETPRESENT_c_SMS_SC2MS_ERR (c_SMS_SC2MS_ERR* sp, TPRESENT_c_SMS_SC2MS_ERR toBeSetPresent);
#define SETPRESENT_c_SMS_SC2MS_ERR_NONE(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ERR(sp, U_c_SMS_SC2MS_ERR_NONE)
#define GETPRESENT_c_SMS_SC2MS_ERR_NONE(sp) ((sp)->Present == U_c_SMS_SC2MS_ERR_NONE)
#define SETPRESENT_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ERR(sp, U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT)
#define GETPRESENT_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT(sp) ((sp)->Present == U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT)
#define SETPRESENT_c_SMS_SC2MS_ERR_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ERR(sp, U_c_SMS_SC2MS_ERR_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS_ERR_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_SC2MS_ERR_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS_ERR(sp) ((sp)->Present)


/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS_ACK' as a variable reference */
#define VAR_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT(var) (*var)

/* Access member 'SMS_STATUS_REPORT' of type 'c_SMS_SC2MS_ACK' as a pointer */
#define PTR_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT(var) var

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS_ACK' as a variable reference */
#define VAR_c_SMS_SC2MS_ACK_SMS_UNKNOWN(var) (*var)

/* Access member 'SMS_UNKNOWN' of type 'c_SMS_SC2MS_ACK' as a pointer */
#define PTR_c_SMS_SC2MS_ACK_SMS_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_SMS_SC2MS_ACK_NONE,
	U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT,
	U_c_SMS_SC2MS_ACK_SMS_UNKNOWN
} TPRESENT_c_SMS_SC2MS_ACK;

typedef struct _c_SMS_SC2MS_ACK {

		TPRESENT_c_SMS_SC2MS_ACK Present;
		union {
			c_SMS_STATUS_REPORT *SMS_STATUS_REPORT; /* ODY01 *//*GBD01b*/
		
			c_SMS_UNKNOWN *SMS_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_SMS_SC2MS_ACK;
#define INIT_c_SMS_SC2MS_ACK(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SC2MS_ACK))
/*FRK01a*/
void FREE_c_SMS_SC2MS_ACK (c_SMS_SC2MS_ACK* sp);

/* SETPRESENT commands for type 'c_SMS_SC2MS_ACK' */
int GLOB_SETPRESENT_c_SMS_SC2MS_ACK (c_SMS_SC2MS_ACK* sp, TPRESENT_c_SMS_SC2MS_ACK toBeSetPresent);
#define SETPRESENT_c_SMS_SC2MS_ACK_NONE(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ACK(sp, U_c_SMS_SC2MS_ACK_NONE)
#define GETPRESENT_c_SMS_SC2MS_ACK_NONE(sp) ((sp)->Present == U_c_SMS_SC2MS_ACK_NONE)
#define SETPRESENT_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ACK(sp, U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT)
#define GETPRESENT_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT(sp) ((sp)->Present == U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT)
#define SETPRESENT_c_SMS_SC2MS_ACK_SMS_UNKNOWN(sp) GLOB_SETPRESENT_c_SMS_SC2MS_ACK(sp, U_c_SMS_SC2MS_ACK_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS_ACK_SMS_UNKNOWN(sp) ((sp)->Present == U_c_SMS_SC2MS_ACK_SMS_UNKNOWN)
#define GETPRESENT_c_SMS_SC2MS_ACK(sp) ((sp)->Present)


/* Access member 'MessageType' of type 'c_RP_UNKNOWN' as a variable reference */
#define VAR_c_RP_UNKNOWN_MessageType(var) var

/* Access member 'MessageType' of type 'c_RP_UNKNOWN' as a pointer */
#define PTR_c_RP_UNKNOWN_MessageType(var) (&var)

/* Access member 'TransportedData' of type 'c_RP_UNKNOWN' as a variable reference */
#define VAR_c_RP_UNKNOWN_TransportedData(var) var

/* Access member 'TransportedData' of type 'c_RP_UNKNOWN' as a pointer */
#define PTR_c_RP_UNKNOWN_TransportedData(var) (&var)

/* DEFINITION OF BINARY c_RP_UNKNOWN_TransportedData */
typedef struct _c_RP_UNKNOWN_TransportedData {
	ED_BYTE* value; /* Variable size; bits needed 1992 */
	int usedBits;
} c_RP_UNKNOWN_TransportedData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RP_UNKNOWN_TransportedData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RP_UNKNOWN {
	ED_LOCATOR MessageType___LOCATOR; /* QUI2 */
	ED_LOCATOR TransportedData___LOCATOR  /*LBD02*/;

	ED_OCTET MessageType; /* ODY01a *//*GBD01b*/
	c_RP_UNKNOWN_TransportedData TransportedData; /* Static, variable size; bits needed 1992 *//*GBD01b*/

}	c_RP_UNKNOWN;
#define INIT_c_RP_UNKNOWN(sp) ED_RESET_MEM ((sp), sizeof (c_RP_UNKNOWN))
/*FRK03a*/
void FREE_c_RP_UNKNOWN(c_RP_UNKNOWN* sp);

/* Access member 'RP_MessageReference' of type 'c_RP_DATA_MSC2MS' as a variable reference */
#define VAR_c_RP_DATA_MSC2MS_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_DATA_MSC2MS' as a pointer */
#define PTR_c_RP_DATA_MSC2MS_RP_MessageReference(var) (&var)

/* Access member 'RP_OriginatorAddress' of type 'c_RP_DATA_MSC2MS' as a variable reference */
#define VAR_c_RP_DATA_MSC2MS_RP_OriginatorAddress(var) var

/* Access member 'RP_OriginatorAddress' of type 'c_RP_DATA_MSC2MS' as a pointer */
#define PTR_c_RP_DATA_MSC2MS_RP_OriginatorAddress(var) (&var)

/* Access member 'RP_DestinationAddress' of type 'c_RP_DATA_MSC2MS' as a variable reference */
#define VAR_c_RP_DATA_MSC2MS_RP_DestinationAddress(var) var

/* Access member 'RP_DestinationAddress' of type 'c_RP_DATA_MSC2MS' as a pointer */
#define PTR_c_RP_DATA_MSC2MS_RP_DestinationAddress(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_DATA_MSC2MS' as a variable reference */
#define VAR_c_RP_DATA_MSC2MS_RP_UserData(var) var

/* Access member 'RP_UserData' of type 'c_RP_DATA_MSC2MS' as a pointer */
#define PTR_c_RP_DATA_MSC2MS_RP_UserData(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RP_DATA_MSC2MS {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_T24011Address RP_OriginatorAddress; /* ODY01a *//*GBD01b*/
	c_T24011Address RP_DestinationAddress; /* ODY01a *//*GBD01b*/
	c_SMS_SC2MS RP_UserData; /* ODY01a *//*GBD01b*/

}	c_RP_DATA_MSC2MS;
#define INIT_c_RP_DATA_MSC2MS(sp) ED_RESET_MEM ((sp), sizeof (c_RP_DATA_MSC2MS))
/*FRK03a*/
void FREE_c_RP_DATA_MSC2MS(c_RP_DATA_MSC2MS* sp);

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ACK_MSC2MS' as a variable reference */
#define VAR_c_RP_RP_ACK_MSC2MS_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ACK_MSC2MS' as a pointer */
#define PTR_c_RP_RP_ACK_MSC2MS_RP_MessageReference(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ACK_MSC2MS' as a variable reference */
#define VAR_c_RP_RP_ACK_MSC2MS_RP_UserData(var) (*var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ACK_MSC2MS' as a pointer */
#define PTR_c_RP_RP_ACK_MSC2MS_RP_UserData(var) var


/*-A----------------------------------*/
typedef struct _c_RP_RP_ACK_MSC2MS {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_SMS_SC2MS_ACK *RP_UserData; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RP_UserData_Present;

}	c_RP_RP_ACK_MSC2MS;
#define INIT_c_RP_RP_ACK_MSC2MS(sp) ED_RESET_MEM ((sp), sizeof (c_RP_RP_ACK_MSC2MS))
/*FRK03a*/
void FREE_c_RP_RP_ACK_MSC2MS(c_RP_RP_ACK_MSC2MS* sp);
int SETPRESENT_c_RP_RP_ACK_MSC2MS_RP_UserData (c_RP_RP_ACK_MSC2MS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RP_RP_ACK_MSC2MS_RP_UserData(sp) ((sp)->RP_UserData_Present)

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ERROR_MSC2MS' as a variable reference */
#define VAR_c_RP_RP_ERROR_MSC2MS_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ERROR_MSC2MS' as a pointer */
#define PTR_c_RP_RP_ERROR_MSC2MS_RP_MessageReference(var) (&var)

/* Access member 'RP_Cause' of type 'c_RP_RP_ERROR_MSC2MS' as a variable reference */
#define VAR_c_RP_RP_ERROR_MSC2MS_RP_Cause(var) var

/* Access member 'RP_Cause' of type 'c_RP_RP_ERROR_MSC2MS' as a pointer */
#define PTR_c_RP_RP_ERROR_MSC2MS_RP_Cause(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ERROR_MSC2MS' as a variable reference */
#define VAR_c_RP_RP_ERROR_MSC2MS_RP_UserData(var) (*var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ERROR_MSC2MS' as a pointer */
#define PTR_c_RP_RP_ERROR_MSC2MS_RP_UserData(var) var


/*-A----------------------------------*/
typedef struct _c_RP_RP_ERROR_MSC2MS {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_TRPCause RP_Cause; /* ODY01a *//*GBD01b*/
	c_SMS_SC2MS_ERR *RP_UserData; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RP_UserData_Present;

}	c_RP_RP_ERROR_MSC2MS;
#define INIT_c_RP_RP_ERROR_MSC2MS(sp) ED_RESET_MEM ((sp), sizeof (c_RP_RP_ERROR_MSC2MS))
/*FRK03a*/
void FREE_c_RP_RP_ERROR_MSC2MS(c_RP_RP_ERROR_MSC2MS* sp);
int SETPRESENT_c_RP_RP_ERROR_MSC2MS_RP_UserData (c_RP_RP_ERROR_MSC2MS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RP_RP_ERROR_MSC2MS_RP_UserData(sp) ((sp)->RP_UserData_Present)

/* Access member 'RP_MessageReference' of type 'c_RP_DATA_MS2MSC' as a variable reference */
#define VAR_c_RP_DATA_MS2MSC_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_DATA_MS2MSC' as a pointer */
#define PTR_c_RP_DATA_MS2MSC_RP_MessageReference(var) (&var)

/* Access member 'RP_OriginatorAddress' of type 'c_RP_DATA_MS2MSC' as a variable reference */
#define VAR_c_RP_DATA_MS2MSC_RP_OriginatorAddress(var) var

/* Access member 'RP_OriginatorAddress' of type 'c_RP_DATA_MS2MSC' as a pointer */
#define PTR_c_RP_DATA_MS2MSC_RP_OriginatorAddress(var) (&var)

/* Access member 'RP_DestinationAddress' of type 'c_RP_DATA_MS2MSC' as a variable reference */
#define VAR_c_RP_DATA_MS2MSC_RP_DestinationAddress(var) var

/* Access member 'RP_DestinationAddress' of type 'c_RP_DATA_MS2MSC' as a pointer */
#define PTR_c_RP_DATA_MS2MSC_RP_DestinationAddress(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_DATA_MS2MSC' as a variable reference */
#define VAR_c_RP_DATA_MS2MSC_RP_UserData(var) var

/* Access member 'RP_UserData' of type 'c_RP_DATA_MS2MSC' as a pointer */
#define PTR_c_RP_DATA_MS2MSC_RP_UserData(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RP_DATA_MS2MSC {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_T24011Address RP_OriginatorAddress; /* ODY01a *//*GBD01b*/
	c_T24011Address RP_DestinationAddress; /* ODY01a *//*GBD01b*/
	c_SMS_MS2SC RP_UserData; /* ODY01a *//*GBD01b*/

}	c_RP_DATA_MS2MSC;
#define INIT_c_RP_DATA_MS2MSC(sp) ED_RESET_MEM ((sp), sizeof (c_RP_DATA_MS2MSC))
/*FRK03a*/
void FREE_c_RP_DATA_MS2MSC(c_RP_DATA_MS2MSC* sp);

/* Access member 'RP_MessageReference' of type 'c_RP_RP_SMMA_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_SMMA_MS2MSC_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_RP_SMMA_MS2MSC' as a pointer */
#define PTR_c_RP_RP_SMMA_MS2MSC_RP_MessageReference(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RP_RP_SMMA_MS2MSC {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/

}	c_RP_RP_SMMA_MS2MSC;
#define INIT_c_RP_RP_SMMA_MS2MSC(sp) ED_RESET_MEM ((sp), sizeof (c_RP_RP_SMMA_MS2MSC))
/*FRK03a*/
void FREE_c_RP_RP_SMMA_MS2MSC(c_RP_RP_SMMA_MS2MSC* sp);

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ACK_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_ACK_MS2MSC_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ACK_MS2MSC' as a pointer */
#define PTR_c_RP_RP_ACK_MS2MSC_RP_MessageReference(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ACK_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_ACK_MS2MSC_RP_UserData(var) (*var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ACK_MS2MSC' as a pointer */
#define PTR_c_RP_RP_ACK_MS2MSC_RP_UserData(var) var


/*-A----------------------------------*/
typedef struct _c_RP_RP_ACK_MS2MSC {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_SMS_MS2SC_ACK *RP_UserData; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RP_UserData_Present;

}	c_RP_RP_ACK_MS2MSC;
#define INIT_c_RP_RP_ACK_MS2MSC(sp) ED_RESET_MEM ((sp), sizeof (c_RP_RP_ACK_MS2MSC))
/*FRK03a*/
void FREE_c_RP_RP_ACK_MS2MSC(c_RP_RP_ACK_MS2MSC* sp);
int SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (c_RP_RP_ACK_MS2MSC* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData(sp) ((sp)->RP_UserData_Present)

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ERROR_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_ERROR_MS2MSC_RP_MessageReference(var) var

/* Access member 'RP_MessageReference' of type 'c_RP_RP_ERROR_MS2MSC' as a pointer */
#define PTR_c_RP_RP_ERROR_MS2MSC_RP_MessageReference(var) (&var)

/* Access member 'RP_Cause' of type 'c_RP_RP_ERROR_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_ERROR_MS2MSC_RP_Cause(var) var

/* Access member 'RP_Cause' of type 'c_RP_RP_ERROR_MS2MSC' as a pointer */
#define PTR_c_RP_RP_ERROR_MS2MSC_RP_Cause(var) (&var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ERROR_MS2MSC' as a variable reference */
#define VAR_c_RP_RP_ERROR_MS2MSC_RP_UserData(var) (*var)

/* Access member 'RP_UserData' of type 'c_RP_RP_ERROR_MS2MSC' as a pointer */
#define PTR_c_RP_RP_ERROR_MS2MSC_RP_UserData(var) var


/*-A----------------------------------*/
typedef struct _c_RP_RP_ERROR_MS2MSC {
	ED_LOCATOR RP_MessageReference___LOCATOR; /* QUI2 */

	ED_OCTET RP_MessageReference; /* ODY01a *//*GBD01b*/
	c_TRPCause RP_Cause; /* ODY01a *//*GBD01b*/
	c_SMS_MS2SC_ERR *RP_UserData; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RP_UserData_Present;

}	c_RP_RP_ERROR_MS2MSC;
#define INIT_c_RP_RP_ERROR_MS2MSC(sp) ED_RESET_MEM ((sp), sizeof (c_RP_RP_ERROR_MS2MSC))
/*FRK03a*/
void FREE_c_RP_RP_ERROR_MS2MSC(c_RP_RP_ERROR_MS2MSC* sp);
int SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (c_RP_RP_ERROR_MS2MSC* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData(sp) ((sp)->RP_UserData_Present)

/* Access member 'RP_DATA_MSC2MS' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_DATA_MSC2MS(var) (*var)

/* Access member 'RP_DATA_MSC2MS' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_DATA_MSC2MS(var) var

/* Access member 'RP_DATA_MS2MSC' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_DATA_MS2MSC(var) (*var)

/* Access member 'RP_DATA_MS2MSC' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_DATA_MS2MSC(var) var

/* Access member 'RP_RP_SMMA_MS2MSC' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_RP_SMMA_MS2MSC(var) (*var)

/* Access member 'RP_RP_SMMA_MS2MSC' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_RP_SMMA_MS2MSC(var) var

/* Access member 'RP_RP_ACK_MS2MSC' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_RP_ACK_MS2MSC(var) (*var)

/* Access member 'RP_RP_ACK_MS2MSC' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_RP_ACK_MS2MSC(var) var

/* Access member 'RP_RP_ACK_MSC2MS' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_RP_ACK_MSC2MS(var) (*var)

/* Access member 'RP_RP_ACK_MSC2MS' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_RP_ACK_MSC2MS(var) var

/* Access member 'RP_RP_ERROR_MS2MSC' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_RP_ERROR_MS2MSC(var) (*var)

/* Access member 'RP_RP_ERROR_MS2MSC' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_RP_ERROR_MS2MSC(var) var

/* Access member 'RP_RP_ERROR_MSC2MS' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_RP_ERROR_MSC2MS(var) (*var)

/* Access member 'RP_RP_ERROR_MSC2MS' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_RP_ERROR_MSC2MS(var) var

/* Access member 'RP_UNKNOWN' of type 'c_CPUserData' as a variable reference */
#define VAR_c_CPUserData_RP_UNKNOWN(var) (*var)

/* Access member 'RP_UNKNOWN' of type 'c_CPUserData' as a pointer */
#define PTR_c_CPUserData_RP_UNKNOWN(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_CPUserData_NONE,
	U_c_CPUserData_RP_DATA_MSC2MS,
	U_c_CPUserData_RP_DATA_MS2MSC,
	U_c_CPUserData_RP_RP_SMMA_MS2MSC,
	U_c_CPUserData_RP_RP_ACK_MS2MSC,
	U_c_CPUserData_RP_RP_ACK_MSC2MS,
	U_c_CPUserData_RP_RP_ERROR_MS2MSC,
	U_c_CPUserData_RP_RP_ERROR_MSC2MS,
	U_c_CPUserData_RP_UNKNOWN
} TPRESENT_c_CPUserData;

typedef struct _c_CPUserData {

		TPRESENT_c_CPUserData Present;
		union {
			c_RP_DATA_MSC2MS *RP_DATA_MSC2MS; /* ODY01 *//*GBD01b*/
		
			c_RP_DATA_MS2MSC *RP_DATA_MS2MSC; /* ODY01 *//*GBD01b*/
		
			c_RP_RP_SMMA_MS2MSC *RP_RP_SMMA_MS2MSC; /* ODY01 *//*GBD01b*/
		
			c_RP_RP_ACK_MS2MSC *RP_RP_ACK_MS2MSC; /* ODY01 *//*GBD01b*/
		
			c_RP_RP_ACK_MSC2MS *RP_RP_ACK_MSC2MS; /* ODY01 *//*GBD01b*/
		
			c_RP_RP_ERROR_MS2MSC *RP_RP_ERROR_MS2MSC; /* ODY01 *//*GBD01b*/
		
			c_RP_RP_ERROR_MSC2MS *RP_RP_ERROR_MSC2MS; /* ODY01 *//*GBD01b*/
		
			c_RP_UNKNOWN *RP_UNKNOWN; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_CPUserData;
#define INIT_c_CPUserData(sp) ED_RESET_MEM ((sp), sizeof (c_CPUserData))
/*FRK01a*/
void FREE_c_CPUserData (c_CPUserData* sp);

/* SETPRESENT commands for type 'c_CPUserData' */
int GLOB_SETPRESENT_c_CPUserData (c_CPUserData* sp, TPRESENT_c_CPUserData toBeSetPresent);
#define SETPRESENT_c_CPUserData_NONE(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_NONE)
#define GETPRESENT_c_CPUserData_NONE(sp) ((sp)->Present == U_c_CPUserData_NONE)
#define SETPRESENT_c_CPUserData_RP_DATA_MSC2MS(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_DATA_MSC2MS)
#define GETPRESENT_c_CPUserData_RP_DATA_MSC2MS(sp) ((sp)->Present == U_c_CPUserData_RP_DATA_MSC2MS)
#define SETPRESENT_c_CPUserData_RP_DATA_MS2MSC(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_DATA_MS2MSC)
#define GETPRESENT_c_CPUserData_RP_DATA_MS2MSC(sp) ((sp)->Present == U_c_CPUserData_RP_DATA_MS2MSC)
#define SETPRESENT_c_CPUserData_RP_RP_SMMA_MS2MSC(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_RP_SMMA_MS2MSC)
#define GETPRESENT_c_CPUserData_RP_RP_SMMA_MS2MSC(sp) ((sp)->Present == U_c_CPUserData_RP_RP_SMMA_MS2MSC)
#define SETPRESENT_c_CPUserData_RP_RP_ACK_MS2MSC(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_RP_ACK_MS2MSC)
#define GETPRESENT_c_CPUserData_RP_RP_ACK_MS2MSC(sp) ((sp)->Present == U_c_CPUserData_RP_RP_ACK_MS2MSC)
#define SETPRESENT_c_CPUserData_RP_RP_ACK_MSC2MS(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_RP_ACK_MSC2MS)
#define GETPRESENT_c_CPUserData_RP_RP_ACK_MSC2MS(sp) ((sp)->Present == U_c_CPUserData_RP_RP_ACK_MSC2MS)
#define SETPRESENT_c_CPUserData_RP_RP_ERROR_MS2MSC(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_RP_ERROR_MS2MSC)
#define GETPRESENT_c_CPUserData_RP_RP_ERROR_MS2MSC(sp) ((sp)->Present == U_c_CPUserData_RP_RP_ERROR_MS2MSC)
#define SETPRESENT_c_CPUserData_RP_RP_ERROR_MSC2MS(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_RP_ERROR_MSC2MS)
#define GETPRESENT_c_CPUserData_RP_RP_ERROR_MSC2MS(sp) ((sp)->Present == U_c_CPUserData_RP_RP_ERROR_MSC2MS)
#define SETPRESENT_c_CPUserData_RP_UNKNOWN(sp) GLOB_SETPRESENT_c_CPUserData(sp, U_c_CPUserData_RP_UNKNOWN)
#define GETPRESENT_c_CPUserData_RP_UNKNOWN(sp) ((sp)->Present == U_c_CPUserData_RP_UNKNOWN)
#define GETPRESENT_c_CPUserData(sp) ((sp)->Present)


/* Access member 'CPUserData' of type 'c_CP_DATA' as a variable reference */
#define VAR_c_CP_DATA_CPUserData(var) var

/* Access member 'CPUserData' of type 'c_CP_DATA' as a pointer */
#define PTR_c_CP_DATA_CPUserData(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CP_DATA {

	c_CPUserData CPUserData; /* ODY01a *//*GBD01b*/

}	c_CP_DATA;
#define INIT_c_CP_DATA(sp) ED_RESET_MEM ((sp), sizeof (c_CP_DATA))
/*FRK03a*/
void FREE_c_CP_DATA(c_CP_DATA* sp);


/*-A----------------------------------*/
typedef struct _c_CP_ACK {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_CP_ACK;
#define INIT_c_CP_ACK(sp) ED_RESET_MEM ((sp), sizeof (c_CP_ACK))
/*FRK03a*/
void FREE_c_CP_ACK(c_CP_ACK* sp);

/* Access member 'CPCause' of type 'c_CP_ERROR' as a variable reference */
#define VAR_c_CP_ERROR_CPCause(var) var

/* Access member 'CPCause' of type 'c_CP_ERROR' as a pointer */
#define PTR_c_CP_ERROR_CPCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CP_ERROR {
	ED_LOCATOR CPCause___LOCATOR  /*LBD02*/;

	ED_BYTE CPCause [1]; /* Static, fixed size; bits needed 8 *//*GBD01b*/

}	c_CP_ERROR;
#define INIT_c_CP_ERROR(sp) ED_RESET_MEM ((sp), sizeof (c_CP_ERROR))
/*FRK03a*/
void FREE_c_CP_ERROR(c_CP_ERROR* sp);

/* Access member 'header' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_header(var) var

/* Access member 'header' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UDHI(var) (&var)

/* Access member 'TP_FCS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_FCS(var) var

/* Access member 'TP_FCS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_FCS(var) (&var)

/* Access member 'TP_PI' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PI(var) var

/* Access member 'TP_PI' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PI(var) (&var)

/* Access member 'TP_SCTS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_SCTS(var) var

/* Access member 'TP_SCTS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_SCTS(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PID(var) (*var)

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PID(var) var

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_DCS(var) (*var)

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_DCS(var) var

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UD(var) (*var)

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UD(var) var

/* Access member 'spare' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ERROR_spare(var) var

/* Access member 'spare' of type 'c_SMS_SUBMIT_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ERROR_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_SUBMIT_REPORT_RP_ERROR_spare */
typedef struct _c_SMS_SUBMIT_REPORT_RP_ERROR_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_SUBMIT_REPORT_RP_ERROR_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_SUBMIT_REPORT_RP_ERROR_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_SUBMIT_REPORT_RP_ERROR {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_FCS___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_FCS; /* ODY01a *//*GBD01b*/
	c_TP_PI TP_PI; /* ODY01a *//*GBD01b*/
	c_TTimeStamp TP_SCTS; /* ODY01a *//*GBD01b*/
	c_TP_PID *TP_PID; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PID_Present;
	c_TP_DCS *TP_DCS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_DCS_Present;
	c_TP_UD *TP_UD; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_UD_Present;
	c_SMS_SUBMIT_REPORT_RP_ERROR_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_SUBMIT_REPORT_RP_ERROR;
#define INIT_c_SMS_SUBMIT_REPORT_RP_ERROR(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SUBMIT_REPORT_RP_ERROR))
/*FRK03a*/
void FREE_c_SMS_SUBMIT_REPORT_RP_ERROR(c_SMS_SUBMIT_REPORT_RP_ERROR* sp);
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PID (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PID(sp) ((sp)->TP_PID_Present)
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_DCS (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_DCS(sp) ((sp)->TP_DCS_Present)
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UD (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UD(sp) ((sp)->TP_UD_Present)

/* Access member 'header' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_header(var) var

/* Access member 'header' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UDHI(var) (&var)

/* Access member 'TP_PI' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PI(var) var

/* Access member 'TP_PI' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PI(var) (&var)

/* Access member 'TP_SCTS' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_SCTS(var) var

/* Access member 'TP_SCTS' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_SCTS(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PID(var) (*var)

/* Access member 'TP_PID' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PID(var) var

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_DCS(var) (*var)

/* Access member 'TP_DCS' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_DCS(var) var

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UD(var) (*var)

/* Access member 'TP_UD' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UD(var) var

/* Access member 'spare' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_SUBMIT_REPORT_RP_ACK_spare(var) var

/* Access member 'spare' of type 'c_SMS_SUBMIT_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_SUBMIT_REPORT_RP_ACK_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_SUBMIT_REPORT_RP_ACK_spare */
typedef struct _c_SMS_SUBMIT_REPORT_RP_ACK_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_SUBMIT_REPORT_RP_ACK_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_SUBMIT_REPORT_RP_ACK_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_SUBMIT_REPORT_RP_ACK {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	c_TP_PI TP_PI; /* ODY01a *//*GBD01b*/
	c_TTimeStamp TP_SCTS; /* ODY01a *//*GBD01b*/
	c_TP_PID *TP_PID; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PID_Present;
	c_TP_DCS *TP_DCS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_DCS_Present;
	c_TP_UD *TP_UD; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_UD_Present;
	c_SMS_SUBMIT_REPORT_RP_ACK_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_SUBMIT_REPORT_RP_ACK;
#define INIT_c_SMS_SUBMIT_REPORT_RP_ACK(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_SUBMIT_REPORT_RP_ACK))
/*FRK03a*/
void FREE_c_SMS_SUBMIT_REPORT_RP_ACK(c_SMS_SUBMIT_REPORT_RP_ACK* sp);
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PID (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PID(sp) ((sp)->TP_PID_Present)
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_DCS (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_DCS(sp) ((sp)->TP_DCS_Present)
int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UD (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UD(sp) ((sp)->TP_UD_Present)

/* Access member 'header' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_header(var) var

/* Access member 'header' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UDHI(var) (&var)

/* Access member 'TP_FCS' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_FCS(var) var

/* Access member 'TP_FCS' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_FCS(var) (&var)

/* Access member 'TP_PI' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PI(var) var

/* Access member 'TP_PI' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PI(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PID(var) (*var)

/* Access member 'TP_PID' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PID(var) var

/* Access member 'TP_DCS' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_DCS(var) (*var)

/* Access member 'TP_DCS' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_DCS(var) var

/* Access member 'TP_UD' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UD(var) (*var)

/* Access member 'TP_UD' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UD(var) var

/* Access member 'spare' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ERROR_spare(var) var

/* Access member 'spare' of type 'c_SMS_DELIVERY_REPORT_RP_ERROR' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ERROR_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_DELIVERY_REPORT_RP_ERROR_spare */
typedef struct _c_SMS_DELIVERY_REPORT_RP_ERROR_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_DELIVERY_REPORT_RP_ERROR_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_DELIVERY_REPORT_RP_ERROR_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_DELIVERY_REPORT_RP_ERROR {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR TP_FCS___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	ED_OCTET TP_FCS; /* ODY01a *//*GBD01b*/
	c_TP_PI TP_PI; /* ODY01a *//*GBD01b*/
	c_TP_PID *TP_PID; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PID_Present;
	c_TP_DCS *TP_DCS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_DCS_Present;
	c_TP_UD *TP_UD; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_UD_Present;
	c_SMS_DELIVERY_REPORT_RP_ERROR_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_DELIVERY_REPORT_RP_ERROR;
#define INIT_c_SMS_DELIVERY_REPORT_RP_ERROR(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_DELIVERY_REPORT_RP_ERROR))
/*FRK03a*/
void FREE_c_SMS_DELIVERY_REPORT_RP_ERROR(c_SMS_DELIVERY_REPORT_RP_ERROR* sp);
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PID (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PID(sp) ((sp)->TP_PID_Present)
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_DCS (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_DCS(sp) ((sp)->TP_DCS_Present)
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UD (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UD(sp) ((sp)->TP_UD_Present)

/* Access member 'header' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_header(var) var

/* Access member 'header' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_header(var) (&var)

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UDHI(var) var

/* Access member 'TP_UDHI' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UDHI(var) (&var)

/* Access member 'TP_PI' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PI(var) var

/* Access member 'TP_PI' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PI(var) (&var)

/* Access member 'TP_PID' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID(var) (*var)

/* Access member 'TP_PID' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID(var) var

/* Access member 'TP_DCS' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS(var) (*var)

/* Access member 'TP_DCS' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS(var) var

/* Access member 'TP_UD' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD(var) (*var)

/* Access member 'TP_UD' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD(var) var

/* Access member 'spare' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a variable reference */
#define VAR_c_SMS_DELIVERY_REPORT_RP_ACK_spare(var) var

/* Access member 'spare' of type 'c_SMS_DELIVERY_REPORT_RP_ACK' as a pointer */
#define PTR_c_SMS_DELIVERY_REPORT_RP_ACK_spare(var) (&var)

/* DEFINITION OF BINARY c_SMS_DELIVERY_REPORT_RP_ACK_spare */
typedef struct _c_SMS_DELIVERY_REPORT_RP_ACK_spare {
	ED_BYTE* value; /* Variable size; bits needed 1864 */
	int usedBits;
} c_SMS_DELIVERY_REPORT_RP_ACK_spare;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SMS_DELIVERY_REPORT_RP_ACK_spare(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SMS_DELIVERY_REPORT_RP_ACK {
	ED_LOCATOR TP_UDHI___LOCATOR; /* QUI2 */
	ED_LOCATOR spare___LOCATOR  /*LBD02*/;

	c_TP_MTI header; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TP_UDHI; /* ODY01a *//*GBD01b*/
	c_TP_PI TP_PI; /* ODY01a *//*GBD01b*/
	c_TP_PID *TP_PID; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_PID_Present;
	c_TP_DCS *TP_DCS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_DCS_Present;
	c_TP_UD *TP_UD; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TP_UD_Present;
	c_SMS_DELIVERY_REPORT_RP_ACK_spare spare; /* Static, variable size; bits needed 1864 *//*GBD01b*/

}	c_SMS_DELIVERY_REPORT_RP_ACK;
#define INIT_c_SMS_DELIVERY_REPORT_RP_ACK(sp) ED_RESET_MEM ((sp), sizeof (c_SMS_DELIVERY_REPORT_RP_ACK))
/*FRK03a*/
void FREE_c_SMS_DELIVERY_REPORT_RP_ACK(c_SMS_DELIVERY_REPORT_RP_ACK* sp);
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID(sp) ((sp)->TP_PID_Present)
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS(sp) ((sp)->TP_DCS_Present)
int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD(sp) ((sp)->TP_UD_Present)

/* Access member 'TLV_Tag' of type 'c_GenericTLV_SMS' as a variable reference */
#define VAR_c_GenericTLV_SMS_TLV_Tag(var) var

/* Access member 'TLV_Tag' of type 'c_GenericTLV_SMS' as a pointer */
#define PTR_c_GenericTLV_SMS_TLV_Tag(var) (&var)

/* Access member 'TLV_Data' of type 'c_GenericTLV_SMS' as a variable reference */
#define VAR_c_GenericTLV_SMS_TLV_Data(var) var

/* Access member 'TLV_Data' of type 'c_GenericTLV_SMS' as a pointer */
#define PTR_c_GenericTLV_SMS_TLV_Data(var) (&var)

/* DEFINITION OF BINARY c_GenericTLV_SMS_TLV_Data */
typedef struct _c_GenericTLV_SMS_TLV_Data {
	ED_BYTE* value; /* Variable size; bits needed 8192 */
	int usedBits;
} c_GenericTLV_SMS_TLV_Data;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_GenericTLV_SMS_TLV_Data(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_GenericTLV_SMS {
	ED_LOCATOR TLV_Tag___LOCATOR; /* QUI2 */
	ED_LOCATOR TLV_Data___LOCATOR  /*LBD02*/;

	ED_LONG TLV_Tag; /* ODY01a *//*GBD01b*/
	c_GenericTLV_SMS_TLV_Data TLV_Data; /* Static, variable size; bits needed 8192 *//*GBD01b*/

}	c_GenericTLV_SMS;
#define INIT_c_GenericTLV_SMS(sp) ED_RESET_MEM ((sp), sizeof (c_GenericTLV_SMS))
/*FRK03a*/
void FREE_c_GenericTLV_SMS(c_GenericTLV_SMS* sp);

/* SETITEMS/ADDITEMS commands for type 'c_TAddress_Address'. */
int SETITEMS_c_TAddress_Address (c_TAddress_Address* sequence, int desiredItems);
#define ADDITEMS_c_TAddress_Address(sequence, itemsToBeAdded) SETITEMS_c_TAddress_Address (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TEnVoiceMailNotification_VM_NOTIFICATIONS'. */
int SETITEMS_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (c_TEnVoiceMailNotification_VM_NOTIFICATIONS* sequence, int desiredItems);
#define ADDITEMS_c_TEnVoiceMailNotification_VM_NOTIFICATIONS(sequence, itemsToBeAdded) SETITEMS_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS'. */
int SETITEMS_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS* sequence, int desiredItems);
#define ADDITEMS_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS(sequence, itemsToBeAdded) SETITEMS_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (sequence, (sequence)->items+itemsToBeAdded)

/* SETPRESENT commands for type 'c_TP_VP_Enhanced_Extension' */
int GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension (c_TP_VP_Enhanced_Extension* sp, TPRESENT_c_TP_VP_Enhanced_Extension toBeSetPresent);
#define SETPRESENT_c_TP_VP_Enhanced_Extension_NONE(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_NONE)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_NONE(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_NONE)
#define SETPRESENT_c_TP_VP_Enhanced_Extension_NoValidityPeriod(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_NoValidityPeriod)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_NoValidityPeriod(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_NoValidityPeriod)
#define SETPRESENT_c_TP_VP_Enhanced_Extension_Relative(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_Relative)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_Relative(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_Relative)
#define SETPRESENT_c_TP_VP_Enhanced_Extension_RelativeInteger(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_RelativeInteger)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_RelativeInteger(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_RelativeInteger)
#define SETPRESENT_c_TP_VP_Enhanced_Extension_RelativeSemiOctet(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_RelativeSemiOctet(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet)
#define SETPRESENT_c_TP_VP_Enhanced_Extension_UnknownExtension(sp) GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension(sp, U_c_TP_VP_Enhanced_Extension_UnknownExtension)
#define GETPRESENT_c_TP_VP_Enhanced_Extension_UnknownExtension(sp) ((sp)->Present == U_c_TP_VP_Enhanced_Extension_UnknownExtension)
#define GETPRESENT_c_TP_VP_Enhanced_Extension(sp) ((sp)->Present)

/* SETITEMS/ADDITEMS commands for type 'c_TP_UD_Message'. */
int SETITEMS_c_TP_UD_Message (c_TP_UD_Message* sequence, int desiredItems);
#define ADDITEMS_c_TP_UD_Message(sequence, itemsToBeAdded) SETITEMS_c_TP_UD_Message (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_T24011Address_Addr_Address'. */
int SETITEMS_c_T24011Address_Addr_Address (c_T24011Address_Addr_Address* sequence, int desiredItems);
#define ADDITEMS_c_T24011Address_Addr_Address(sequence, itemsToBeAdded) SETITEMS_c_T24011Address_Addr_Address (sequence, (sequence)->items+itemsToBeAdded)

#ifdef __cplusplus
}
#endif

#endif

