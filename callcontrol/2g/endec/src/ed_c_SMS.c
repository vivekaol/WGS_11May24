/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_SMS.h"
#include "ed_lib.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


/* Free function for variable-sized sequence c_TAddress_Address */
void FREE_c_TAddress_Address (c_TAddress_Address* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TAddress */
void FREE_c_TAddress (c_TAddress* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Address.data) {EDFree (sp->Address.data); sp->Address.data = NULL; sp->Address.allocatedItems=0; /*FR02A*/}
	if (sp->Address.data___LOCATOR) {EDFree (sp->Address.data___LOCATOR); sp->Address.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_TEnVoiceMailNotificationItem */
void FREE_c_TEnVoiceMailNotificationItem (c_TEnVoiceMailNotificationItem* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TAddress (&(sp->VM_MESSAGE_CALLING_LINE_IDENTITY));
	if (sp->VM_MESSAGE_EXTENSION_DATA.value != NULL) {
		EDFree (sp->VM_MESSAGE_EXTENSION_DATA.value);
		sp->VM_MESSAGE_EXTENSION_DATA.value = NULL;
	}
	sp->VM_MESSAGE_EXTENSION_DATA.usedBits = 0;

}

/* Free function for struct c_TEnVoiceMailDeleteConfirmationItem */
void FREE_c_TEnVoiceMailDeleteConfirmationItem (c_TEnVoiceMailDeleteConfirmationItem* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->VM_MESSAGE_EXTENSION_DATA.value != NULL) {
		EDFree (sp->VM_MESSAGE_EXTENSION_DATA.value);
		sp->VM_MESSAGE_EXTENSION_DATA.value = NULL;
	}
	sp->VM_MESSAGE_EXTENSION_DATA.usedBits = 0;

}

/* Free function for variable-sized sequence c_TEnVoiceMailNotification_VM_NOTIFICATIONS */
void FREE_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (c_TEnVoiceMailNotification_VM_NOTIFICATIONS* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_TEnVoiceMailNotificationItem (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TEnVoiceMailNotification */
void FREE_c_TEnVoiceMailNotification (c_TEnVoiceMailNotification* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	FREE_c_TAddress (&(sp->VM_MAILBOX_ACCESS_ADDRESS));
	if (sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value != NULL) {
		EDFree (sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value);
		sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value = NULL;
	}
	sp->VM_MAILBOX_STATUS_EXTENSION_DATA.usedBits = 0;
	for (i0=0; i0<sp->VM_NOTIFICATIONS.items; i0++) {
		FREE_c_TEnVoiceMailNotificationItem (sp->VM_NOTIFICATIONS.data[i0]);
		EDFree (sp->VM_NOTIFICATIONS.data[i0]);
	}
	if (sp->VM_NOTIFICATIONS.data) {EDFree (sp->VM_NOTIFICATIONS.data); sp->VM_NOTIFICATIONS.data = NULL; sp->VM_NOTIFICATIONS.allocatedItems=0; /*FR02A*/}
	if (sp->VM_NOTIFICATIONS.data___LOCATOR) {EDFree (sp->VM_NOTIFICATIONS.data___LOCATOR); sp->VM_NOTIFICATIONS.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS */
void FREE_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_TEnVoiceMailDeleteConfirmationItem (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TEnVoiceMailDeleteConfirmation */
void FREE_c_TEnVoiceMailDeleteConfirmation (c_TEnVoiceMailDeleteConfirmation* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	FREE_c_TAddress (&(sp->VM_MAILBOX_ACCESS_ADDRESS));
	if (sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value != NULL) {
		EDFree (sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value);
		sp->VM_MAILBOX_STATUS_EXTENSION_DATA.value = NULL;
	}
	sp->VM_MAILBOX_STATUS_EXTENSION_DATA.usedBits = 0;
	for (i0=0; i0<sp->VM_DELETE_CONFIRMATIONS.items; i0++) {
		FREE_c_TEnVoiceMailDeleteConfirmationItem (sp->VM_DELETE_CONFIRMATIONS.data[i0]);
		EDFree (sp->VM_DELETE_CONFIRMATIONS.data[i0]);
	}
	if (sp->VM_DELETE_CONFIRMATIONS.data) {EDFree (sp->VM_DELETE_CONFIRMATIONS.data); sp->VM_DELETE_CONFIRMATIONS.data = NULL; sp->VM_DELETE_CONFIRMATIONS.allocatedItems=0; /*FR02A*/}
	if (sp->VM_DELETE_CONFIRMATIONS.data___LOCATOR) {EDFree (sp->VM_DELETE_CONFIRMATIONS.data___LOCATOR); sp->VM_DELETE_CONFIRMATIONS.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_TConcShortMsgs8BitRefNum */
void FREE_c_TConcShortMsgs8BitRefNum (c_TConcShortMsgs8BitRefNum* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TSpecialSmsMsgInd */
void FREE_c_TSpecialSmsMsgInd (c_TSpecialSmsMsgInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TApplPortAddrScheme8BitAddr */
void FREE_c_TApplPortAddrScheme8BitAddr (c_TApplPortAddrScheme8BitAddr* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TApplPortAddrScheme16BitAddr */
void FREE_c_TApplPortAddrScheme16BitAddr (c_TApplPortAddrScheme16BitAddr* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TSmscCtrlParams */
void FREE_c_TSmscCtrlParams (c_TSmscCtrlParams* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TUdhSrcInd */
void FREE_c_TUdhSrcInd (c_TUdhSrcInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TConcShortMsg16BitRefNum */
void FREE_c_TConcShortMsg16BitRefNum (c_TConcShortMsg16BitRefNum* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TTextFmt */
void FREE_c_TTextFmt (c_TTextFmt* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TPredefSound */
void FREE_c_TPredefSound (c_TPredefSound* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TUserDefSound */
void FREE_c_TUserDefSound (c_TUserDefSound* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Sound.value != NULL) {
		EDFree (sp->Sound.value);
		sp->Sound.value = NULL;
	}
	sp->Sound.usedBits = 0;

}

/* Free function for struct c_TPredefAnim */
void FREE_c_TPredefAnim (c_TPredefAnim* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TLargeAnim */
void FREE_c_TLargeAnim (c_TLargeAnim* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Animation.value != NULL) {
		EDFree (sp->Animation.value);
		sp->Animation.value = NULL;
	}
	sp->Animation.usedBits = 0;

}

/* Free function for struct c_TSmallAnim */
void FREE_c_TSmallAnim (c_TSmallAnim* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Animation.value != NULL) {
		EDFree (sp->Animation.value);
		sp->Animation.value = NULL;
	}
	sp->Animation.usedBits = 0;

}

/* Free function for struct c_TLargePict */
void FREE_c_TLargePict (c_TLargePict* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Picture.value != NULL) {
		EDFree (sp->Picture.value);
		sp->Picture.value = NULL;
	}
	sp->Picture.usedBits = 0;

}

/* Free function for struct c_TSmallPict */
void FREE_c_TSmallPict (c_TSmallPict* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Picture.value != NULL) {
		EDFree (sp->Picture.value);
		sp->Picture.value = NULL;
	}
	sp->Picture.usedBits = 0;

}

/* Free function for struct c_TVarPict */
void FREE_c_TVarPict (c_TVarPict* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Animation.value != NULL) {
		EDFree (sp->Animation.value);
		sp->Animation.value = NULL;
	}
	sp->Animation.usedBits = 0;

}

/* Free function for struct c_TUserPromptInd */
void FREE_c_TUserPromptInd (c_TUserPromptInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TExtObj */
void FREE_c_TExtObj (c_TExtObj* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ExObjData.value != NULL) {
		EDFree (sp->ExObjData.value);
		sp->ExObjData.value = NULL;
	}
	sp->ExObjData.usedBits = 0;

}

/* Free function for struct c_TReusedExtObj */
void FREE_c_TReusedExtObj (c_TReusedExtObj* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TComprCtrl */
void FREE_c_TComprCtrl (c_TComprCtrl* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->CompressedData.value != NULL) {
		EDFree (sp->CompressedData.value);
		sp->CompressedData.value = NULL;
	}
	sp->CompressedData.usedBits = 0;

}

/* Free function for struct c_TObjDistrInd */
void FREE_c_TObjDistrInd (c_TObjDistrInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TStdWvgObj */
void FREE_c_TStdWvgObj (c_TStdWvgObj* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Data.value != NULL) {
		EDFree (sp->Data.value);
		sp->Data.value = NULL;
	}
	sp->Data.usedBits = 0;

}

/* Free function for struct c_TCharSizeWvgObj */
void FREE_c_TCharSizeWvgObj (c_TCharSizeWvgObj* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Data.value != NULL) {
		EDFree (sp->Data.value);
		sp->Data.value = NULL;
	}
	sp->Data.usedBits = 0;

}

/* Free function for struct c_TRfc822EMailHdr */
void FREE_c_TRfc822EMailHdr (c_TRfc822EMailHdr* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_THyperlinkFmtElem */
void FREE_c_THyperlinkFmtElem (c_THyperlinkFmtElem* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TUnknownIE */
void FREE_c_TUnknownIE (c_TUnknownIE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->RawData.value != NULL) {
		EDFree (sp->RawData.value);
		sp->RawData.value = NULL;
	}
	sp->RawData.usedBits = 0;

}

/* Free function for union c_TEnVoiceMailInfo */
void FREE_c_TEnVoiceMailInfo (c_TEnVoiceMailInfo* sp) {
	switch (sp->Present) {
		case U_c_TEnVoiceMailInfo_voiceMailNotification: {
			FREE_c_TEnVoiceMailNotification (sp->u.voiceMailNotification);
			EDFree (sp->u.voiceMailNotification);

			break;
		}
		case U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation: {
			FREE_c_TEnVoiceMailDeleteConfirmation (sp->u.voiceMailDeleteConfirmation);
			EDFree (sp->u.voiceMailDeleteConfirmation);

			break;
		}

		default:;
	}
	sp->Present = U_c_TEnVoiceMailInfo_NONE;
}

/* Set-present function for c_TEnVoiceMailInfo LEVEL = -1 */
int GLOB_SETPRESENT_c_TEnVoiceMailInfo (c_TEnVoiceMailInfo* sp, TPRESENT_c_TEnVoiceMailInfo toBeSetPresent) 
{
	FREE_c_TEnVoiceMailInfo (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_TEnVoiceMailInfo_voiceMailNotification: {
			sp->u.voiceMailNotification = (c_TEnVoiceMailNotification*)EDAlloc (sizeof (c_TEnVoiceMailNotification));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.voiceMailNotification)
			INIT_c_TEnVoiceMailNotification (sp->u.voiceMailNotification);

			break;
		}
		case U_c_TEnVoiceMailInfo_voiceMailDeleteConfirmation: {
			sp->u.voiceMailDeleteConfirmation = (c_TEnVoiceMailDeleteConfirmation*)EDAlloc (sizeof (c_TEnVoiceMailDeleteConfirmation));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.voiceMailDeleteConfirmation)
			INIT_c_TEnVoiceMailDeleteConfirmation (sp->u.voiceMailDeleteConfirmation);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_TUserDataIEUnion */
void FREE_c_TUserDataIEUnion (c_TUserDataIEUnion* sp) {
	switch (sp->Present) {
		case U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum: {
			FREE_c_TConcShortMsgs8BitRefNum (sp->u.ConcShortMsgs8BitRefNum);
			EDFree (sp->u.ConcShortMsgs8BitRefNum);

			break;
		}
		case U_c_TUserDataIEUnion_SpecialSmsMsgInd: {
			FREE_c_TSpecialSmsMsgInd (sp->u.SpecialSmsMsgInd);
			EDFree (sp->u.SpecialSmsMsgInd);

			break;
		}
		case U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr: {
			FREE_c_TApplPortAddrScheme8BitAddr (sp->u.ApplPortAddrScheme8BitAddr);
			EDFree (sp->u.ApplPortAddrScheme8BitAddr);

			break;
		}
		case U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr: {
			FREE_c_TApplPortAddrScheme16BitAddr (sp->u.ApplPortAddrScheme16BitAddr);
			EDFree (sp->u.ApplPortAddrScheme16BitAddr);

			break;
		}
		case U_c_TUserDataIEUnion_SmscCtrlParams: {
			FREE_c_TSmscCtrlParams (sp->u.SmscCtrlParams);
			EDFree (sp->u.SmscCtrlParams);

			break;
		}
		case U_c_TUserDataIEUnion_UdhSrcInd: {
			FREE_c_TUdhSrcInd (sp->u.UdhSrcInd);
			EDFree (sp->u.UdhSrcInd);

			break;
		}
		case U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum: {
			FREE_c_TConcShortMsg16BitRefNum (sp->u.ConcShortMsg16BitRefNum);
			EDFree (sp->u.ConcShortMsg16BitRefNum);

			break;
		}
		case U_c_TUserDataIEUnion_WirelessCtrlMsgProto: {
			if (sp->u.WirelessCtrlMsgProto->value != NULL) {
				EDFree (sp->u.WirelessCtrlMsgProto->value);
				sp->u.WirelessCtrlMsgProto->value = NULL;
			}
			sp->u.WirelessCtrlMsgProto->usedBits = 0;
			EDFree (sp->u.WirelessCtrlMsgProto);

			break;
		}
		case U_c_TUserDataIEUnion_TextFmt: {
			FREE_c_TTextFmt (sp->u.TextFmt);
			EDFree (sp->u.TextFmt);

			break;
		}
		case U_c_TUserDataIEUnion_PredefSound: {
			FREE_c_TPredefSound (sp->u.PredefSound);
			EDFree (sp->u.PredefSound);

			break;
		}
		case U_c_TUserDataIEUnion_UserDefSound: {
			FREE_c_TUserDefSound (sp->u.UserDefSound);
			EDFree (sp->u.UserDefSound);

			break;
		}
		case U_c_TUserDataIEUnion_PredefAnim: {
			FREE_c_TPredefAnim (sp->u.PredefAnim);
			EDFree (sp->u.PredefAnim);

			break;
		}
		case U_c_TUserDataIEUnion_LargeAnim: {
			FREE_c_TLargeAnim (sp->u.LargeAnim);
			EDFree (sp->u.LargeAnim);

			break;
		}
		case U_c_TUserDataIEUnion_SmallAnim: {
			FREE_c_TSmallAnim (sp->u.SmallAnim);
			EDFree (sp->u.SmallAnim);

			break;
		}
		case U_c_TUserDataIEUnion_LargePict: {
			FREE_c_TLargePict (sp->u.LargePict);
			EDFree (sp->u.LargePict);

			break;
		}
		case U_c_TUserDataIEUnion_SmallPict: {
			FREE_c_TSmallPict (sp->u.SmallPict);
			EDFree (sp->u.SmallPict);

			break;
		}
		case U_c_TUserDataIEUnion_VarPict: {
			FREE_c_TVarPict (sp->u.VarPict);
			EDFree (sp->u.VarPict);

			break;
		}
		case U_c_TUserDataIEUnion_UserPromptInd: {
			FREE_c_TUserPromptInd (sp->u.UserPromptInd);
			EDFree (sp->u.UserPromptInd);

			break;
		}
		case U_c_TUserDataIEUnion_ExtObj: {
			FREE_c_TExtObj (sp->u.ExtObj);
			EDFree (sp->u.ExtObj);

			break;
		}
		case U_c_TUserDataIEUnion_ReusedExtObj: {
			FREE_c_TReusedExtObj (sp->u.ReusedExtObj);
			EDFree (sp->u.ReusedExtObj);

			break;
		}
		case U_c_TUserDataIEUnion_ComprCtrl: {
			FREE_c_TComprCtrl (sp->u.ComprCtrl);
			EDFree (sp->u.ComprCtrl);

			break;
		}
		case U_c_TUserDataIEUnion_ObjDistrInd: {
			FREE_c_TObjDistrInd (sp->u.ObjDistrInd);
			EDFree (sp->u.ObjDistrInd);

			break;
		}
		case U_c_TUserDataIEUnion_StdWvgObj: {
			FREE_c_TStdWvgObj (sp->u.StdWvgObj);
			EDFree (sp->u.StdWvgObj);

			break;
		}
		case U_c_TUserDataIEUnion_CharSizeWvgObj: {
			FREE_c_TCharSizeWvgObj (sp->u.CharSizeWvgObj);
			EDFree (sp->u.CharSizeWvgObj);

			break;
		}
		case U_c_TUserDataIEUnion_Rfc822EMailHdr: {
			FREE_c_TRfc822EMailHdr (sp->u.Rfc822EMailHdr);
			EDFree (sp->u.Rfc822EMailHdr);

			break;
		}
		case U_c_TUserDataIEUnion_HyperlinkFmtElem: {
			FREE_c_THyperlinkFmtElem (sp->u.HyperlinkFmtElem);
			EDFree (sp->u.HyperlinkFmtElem);

			break;
		}
		case U_c_TUserDataIEUnion_ReplyAddrElem: {
			if (sp->u.ReplyAddrElem->value != NULL) {
				EDFree (sp->u.ReplyAddrElem->value);
				sp->u.ReplyAddrElem->value = NULL;
			}
			sp->u.ReplyAddrElem->usedBits = 0;
			EDFree (sp->u.ReplyAddrElem);

			break;
		}
		case U_c_TUserDataIEUnion_EnVoiceMailInfo: {
			FREE_c_TEnVoiceMailInfo (sp->u.EnVoiceMailInfo);
			EDFree (sp->u.EnVoiceMailInfo);

			break;
		}
		case U_c_TUserDataIEUnion_UnknownIE: {
			FREE_c_TUnknownIE (sp->u.UnknownIE);
			EDFree (sp->u.UnknownIE);

			break;
		}

		default:;
	}
	sp->Present = U_c_TUserDataIEUnion_NONE;
}

/* Set-present function for c_TUserDataIEUnion LEVEL = -1 */
int GLOB_SETPRESENT_c_TUserDataIEUnion (c_TUserDataIEUnion* sp, TPRESENT_c_TUserDataIEUnion toBeSetPresent) 
{
	FREE_c_TUserDataIEUnion (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_TUserDataIEUnion_ConcShortMsgs8BitRefNum: {
			sp->u.ConcShortMsgs8BitRefNum = (c_TConcShortMsgs8BitRefNum*)EDAlloc (sizeof (c_TConcShortMsgs8BitRefNum));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ConcShortMsgs8BitRefNum)
			INIT_c_TConcShortMsgs8BitRefNum (sp->u.ConcShortMsgs8BitRefNum);

			break;
		}
		case U_c_TUserDataIEUnion_SpecialSmsMsgInd: {
			sp->u.SpecialSmsMsgInd = (c_TSpecialSmsMsgInd*)EDAlloc (sizeof (c_TSpecialSmsMsgInd));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SpecialSmsMsgInd)
			INIT_c_TSpecialSmsMsgInd (sp->u.SpecialSmsMsgInd);

			break;
		}
		case U_c_TUserDataIEUnion_ApplPortAddrScheme8BitAddr: {
			sp->u.ApplPortAddrScheme8BitAddr = (c_TApplPortAddrScheme8BitAddr*)EDAlloc (sizeof (c_TApplPortAddrScheme8BitAddr));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ApplPortAddrScheme8BitAddr)
			INIT_c_TApplPortAddrScheme8BitAddr (sp->u.ApplPortAddrScheme8BitAddr);

			break;
		}
		case U_c_TUserDataIEUnion_ApplPortAddrScheme16BitAddr: {
			sp->u.ApplPortAddrScheme16BitAddr = (c_TApplPortAddrScheme16BitAddr*)EDAlloc (sizeof (c_TApplPortAddrScheme16BitAddr));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ApplPortAddrScheme16BitAddr)
			INIT_c_TApplPortAddrScheme16BitAddr (sp->u.ApplPortAddrScheme16BitAddr);

			break;
		}
		case U_c_TUserDataIEUnion_SmscCtrlParams: {
			sp->u.SmscCtrlParams = (c_TSmscCtrlParams*)EDAlloc (sizeof (c_TSmscCtrlParams));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SmscCtrlParams)
			INIT_c_TSmscCtrlParams (sp->u.SmscCtrlParams);

			break;
		}
		case U_c_TUserDataIEUnion_UdhSrcInd: {
			sp->u.UdhSrcInd = (c_TUdhSrcInd*)EDAlloc (sizeof (c_TUdhSrcInd));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.UdhSrcInd)
			INIT_c_TUdhSrcInd (sp->u.UdhSrcInd);

			break;
		}
		case U_c_TUserDataIEUnion_ConcShortMsg16BitRefNum: {
			sp->u.ConcShortMsg16BitRefNum = (c_TConcShortMsg16BitRefNum*)EDAlloc (sizeof (c_TConcShortMsg16BitRefNum));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ConcShortMsg16BitRefNum)
			INIT_c_TConcShortMsg16BitRefNum (sp->u.ConcShortMsg16BitRefNum);

			break;
		}
		case U_c_TUserDataIEUnion_WirelessCtrlMsgProto: {
			sp->u.WirelessCtrlMsgProto = (c_TUserDataIEUnion_WirelessCtrlMsgProto*)EDAlloc (sizeof (c_TUserDataIEUnion_WirelessCtrlMsgProto));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.WirelessCtrlMsgProto)
			
			sp->u.WirelessCtrlMsgProto->value = NULL;
			sp->u.WirelessCtrlMsgProto->usedBits = 0;

			break;
		}
		case U_c_TUserDataIEUnion_TextFmt: {
			sp->u.TextFmt = (c_TTextFmt*)EDAlloc (sizeof (c_TTextFmt));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.TextFmt)
			INIT_c_TTextFmt (sp->u.TextFmt);

			break;
		}
		case U_c_TUserDataIEUnion_PredefSound: {
			sp->u.PredefSound = (c_TPredefSound*)EDAlloc (sizeof (c_TPredefSound));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.PredefSound)
			INIT_c_TPredefSound (sp->u.PredefSound);

			break;
		}
		case U_c_TUserDataIEUnion_UserDefSound: {
			sp->u.UserDefSound = (c_TUserDefSound*)EDAlloc (sizeof (c_TUserDefSound));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.UserDefSound)
			INIT_c_TUserDefSound (sp->u.UserDefSound);

			break;
		}
		case U_c_TUserDataIEUnion_PredefAnim: {
			sp->u.PredefAnim = (c_TPredefAnim*)EDAlloc (sizeof (c_TPredefAnim));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.PredefAnim)
			INIT_c_TPredefAnim (sp->u.PredefAnim);

			break;
		}
		case U_c_TUserDataIEUnion_LargeAnim: {
			sp->u.LargeAnim = (c_TLargeAnim*)EDAlloc (sizeof (c_TLargeAnim));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.LargeAnim)
			INIT_c_TLargeAnim (sp->u.LargeAnim);

			break;
		}
		case U_c_TUserDataIEUnion_SmallAnim: {
			sp->u.SmallAnim = (c_TSmallAnim*)EDAlloc (sizeof (c_TSmallAnim));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SmallAnim)
			INIT_c_TSmallAnim (sp->u.SmallAnim);

			break;
		}
		case U_c_TUserDataIEUnion_LargePict: {
			sp->u.LargePict = (c_TLargePict*)EDAlloc (sizeof (c_TLargePict));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.LargePict)
			INIT_c_TLargePict (sp->u.LargePict);

			break;
		}
		case U_c_TUserDataIEUnion_SmallPict: {
			sp->u.SmallPict = (c_TSmallPict*)EDAlloc (sizeof (c_TSmallPict));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SmallPict)
			INIT_c_TSmallPict (sp->u.SmallPict);

			break;
		}
		case U_c_TUserDataIEUnion_VarPict: {
			sp->u.VarPict = (c_TVarPict*)EDAlloc (sizeof (c_TVarPict));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.VarPict)
			INIT_c_TVarPict (sp->u.VarPict);

			break;
		}
		case U_c_TUserDataIEUnion_UserPromptInd: {
			sp->u.UserPromptInd = (c_TUserPromptInd*)EDAlloc (sizeof (c_TUserPromptInd));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.UserPromptInd)
			INIT_c_TUserPromptInd (sp->u.UserPromptInd);

			break;
		}
		case U_c_TUserDataIEUnion_ExtObj: {
			sp->u.ExtObj = (c_TExtObj*)EDAlloc (sizeof (c_TExtObj));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ExtObj)
			INIT_c_TExtObj (sp->u.ExtObj);

			break;
		}
		case U_c_TUserDataIEUnion_ReusedExtObj: {
			sp->u.ReusedExtObj = (c_TReusedExtObj*)EDAlloc (sizeof (c_TReusedExtObj));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ReusedExtObj)
			INIT_c_TReusedExtObj (sp->u.ReusedExtObj);

			break;
		}
		case U_c_TUserDataIEUnion_ComprCtrl: {
			sp->u.ComprCtrl = (c_TComprCtrl*)EDAlloc (sizeof (c_TComprCtrl));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ComprCtrl)
			INIT_c_TComprCtrl (sp->u.ComprCtrl);

			break;
		}
		case U_c_TUserDataIEUnion_ObjDistrInd: {
			sp->u.ObjDistrInd = (c_TObjDistrInd*)EDAlloc (sizeof (c_TObjDistrInd));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ObjDistrInd)
			INIT_c_TObjDistrInd (sp->u.ObjDistrInd);

			break;
		}
		case U_c_TUserDataIEUnion_StdWvgObj: {
			sp->u.StdWvgObj = (c_TStdWvgObj*)EDAlloc (sizeof (c_TStdWvgObj));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.StdWvgObj)
			INIT_c_TStdWvgObj (sp->u.StdWvgObj);

			break;
		}
		case U_c_TUserDataIEUnion_CharSizeWvgObj: {
			sp->u.CharSizeWvgObj = (c_TCharSizeWvgObj*)EDAlloc (sizeof (c_TCharSizeWvgObj));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.CharSizeWvgObj)
			INIT_c_TCharSizeWvgObj (sp->u.CharSizeWvgObj);

			break;
		}
		case U_c_TUserDataIEUnion_ExtObjDataReqCmd: {

			break;
		}
		case U_c_TUserDataIEUnion_Rfc822EMailHdr: {
			sp->u.Rfc822EMailHdr = (c_TRfc822EMailHdr*)EDAlloc (sizeof (c_TRfc822EMailHdr));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Rfc822EMailHdr)
			INIT_c_TRfc822EMailHdr (sp->u.Rfc822EMailHdr);

			break;
		}
		case U_c_TUserDataIEUnion_HyperlinkFmtElem: {
			sp->u.HyperlinkFmtElem = (c_THyperlinkFmtElem*)EDAlloc (sizeof (c_THyperlinkFmtElem));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.HyperlinkFmtElem)
			INIT_c_THyperlinkFmtElem (sp->u.HyperlinkFmtElem);

			break;
		}
		case U_c_TUserDataIEUnion_ReplyAddrElem: {
			sp->u.ReplyAddrElem = (c_TUserDataIEUnion_ReplyAddrElem*)EDAlloc (sizeof (c_TUserDataIEUnion_ReplyAddrElem));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.ReplyAddrElem)
			
			sp->u.ReplyAddrElem->value = NULL;
			sp->u.ReplyAddrElem->usedBits = 0;

			break;
		}
		case U_c_TUserDataIEUnion_EnVoiceMailInfo: {
			sp->u.EnVoiceMailInfo = (c_TEnVoiceMailInfo*)EDAlloc (sizeof (c_TEnVoiceMailInfo));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.EnVoiceMailInfo)
			INIT_c_TEnVoiceMailInfo (sp->u.EnVoiceMailInfo);

			break;
		}
		case U_c_TUserDataIEUnion_NationalLangSingleShift: {
			(sp->u.NationalLangSingleShift) = 0;

			break;
		}
		case U_c_TUserDataIEUnion_NationalLangLockingShift: {
			(sp->u.NationalLangLockingShift) = 0;

			break;
		}
		case U_c_TUserDataIEUnion_UnknownIE: {
			sp->u.UnknownIE = (c_TUnknownIE*)EDAlloc (sizeof (c_TUnknownIE));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.UnknownIE)
			INIT_c_TUnknownIE (sp->u.UnknownIE);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_TUserDataIE */
void FREE_c_TUserDataIE (c_TUserDataIE* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_TUserDataIEUnion (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_TUserDataIE'. Existing items are not changed. */
int SETITEMS_c_TUserDataIE (c_TUserDataIE* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TUserDataIEUnion** tmp;
		tmp = (c_TUserDataIEUnion**)EDAlloc (sizeof (c_TUserDataIEUnion*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TUserDataIEUnion*) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			sequence->data[i] = (c_TUserDataIEUnion*)EDAlloc (sizeof (c_TUserDataIEUnion));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_TUserDataIEUnion (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_TUserDataIEUnion (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_TTimeStamp */
void FREE_c_TTimeStamp (c_TTimeStamp* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TP_PI */
void FREE_c_TP_PI (c_TP_PI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TP_PID */
void FREE_c_TP_PID (c_TP_PID* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TP_DCS */
void FREE_c_TP_DCS (c_TP_DCS* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for fixed sequence c_TP_VP_Absolute */
void FREE_c_TP_VP_Absolute (ED_OCTET* sp) {
	int i;
	for (i=0; i<14; i++) {
	}
}
/* Free function for fixed sequence c_TP_VP_Enhanced_Extension_RelativeSemiOctet */
void FREE_c_TP_VP_Enhanced_Extension_RelativeSemiOctet (ED_OCTET* sp) {
	int i;
	for (i=0; i<6; i++) {
	}
}
/* Free function for fixed sequence c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets */
void FREE_c_TP_VP_Enhanced_Extension_UnknownExtension_UnknownOctets (ED_OCTET* sp) {
	int i;
	for (i=0; i<6; i++) {
	}
}
/* Free function for union c_TP_VP_Enhanced_Extension */
void FREE_c_TP_VP_Enhanced_Extension (c_TP_VP_Enhanced_Extension* sp) {
	switch (sp->Present) {
		case U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet: {
			EDFree (sp->u.RelativeSemiOctet) /*FR01*/;

			break;
		}
		case U_c_TP_VP_Enhanced_Extension_UnknownExtension: {
			EDFree (sp->u.UnknownExtension);
			sp->u.UnknownExtension = NULL;

			break;
		}

		default:;
	}
	sp->Present = U_c_TP_VP_Enhanced_Extension_NONE;
}

/* Free function for union c_TP_VP */
void FREE_c_TP_VP (c_TP_VP* sp) {
	switch (sp->Present) {
		case U_c_TP_VP_Absolute: {
			EDFree (sp->u.Absolute) /*FR01*/;

			break;
		}
		case U_c_TP_VP_Enhanced: {
			FREE_c_TP_VP_Enhanced_Extension (&(sp->u.Enhanced->Extension));
			EDFree (sp->u.Enhanced);
			sp->u.Enhanced = NULL;

			break;
		}

		default:;
	}
	sp->Present = U_c_TP_VP_NONE;
}

/* Set-present function for c_TP_VP LEVEL = 0 */
int GLOB_SETPRESENT_c_TP_VP (c_TP_VP* sp, TPRESENT_c_TP_VP toBeSetPresent) 
{
	int i0;
	FREE_c_TP_VP (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_TP_VP_Relative: {
			(sp->u.Relative) = 0;

			break;
		}
		case U_c_TP_VP_Absolute: {
			sp->u.Absolute = (ED_OCTET*)EDAlloc (sizeof (ED_OCTET[14]));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Absolute)
			for (i0=0; i0<14; i0++) {
				(sp->u.Absolute[i0]) = 0;
			}

			break;
		}
		case U_c_TP_VP_Enhanced: {
			sp->u.Enhanced = (c_TP_VP_Enhanced*)EDAlloc (sizeof (c_TP_VP_Enhanced));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Enhanced)
			ED_RESET_MEM (sp->u.Enhanced, sizeof (c_TP_VP_Enhanced));
			(sp->u.Enhanced->SingleShotSM) = 0;
			(sp->u.Enhanced->ValidityPeriodFormat) = 0;
			ED_RESET_MEM (&(sp->u.Enhanced->Extension), sizeof (c_TP_VP_Enhanced_Extension));

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_TP_CD */
void FREE_c_TP_CD (c_TP_CD* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_TP_CD'. Existing items are not changed. */
int SETITEMS_c_TP_CD (c_TP_CD* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_OCTET* tmp;
		tmp = (ED_OCTET*)EDAlloc (sizeof (ED_OCTET) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_OCTET) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			(sequence->data[i]) = 0;
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_TP_UD_Message */
void FREE_c_TP_UD_Message (c_TP_UD_Message* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TP_UD */
void FREE_c_TP_UD (c_TP_UD* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TUserDataIE (&(sp->Header));
	if (sp->Message.data) {EDFree (sp->Message.data); sp->Message.data = NULL; sp->Message.allocatedItems=0; /*FR02A*/}
	if (sp->Message.data___LOCATOR) {EDFree (sp->Message.data___LOCATOR); sp->Message.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_TP_MTI */
void FREE_c_TP_MTI (c_TP_MTI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SMS_UNKNOWN */
void FREE_c_SMS_UNKNOWN (c_SMS_UNKNOWN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->UnknownSMSData.value != NULL) {
		EDFree (sp->UnknownSMSData.value);
		sp->UnknownSMSData.value = NULL;
	}
	sp->UnknownSMSData.usedBits = 0;

}

/* Free function for struct c_SMS_DELIVER */
void FREE_c_SMS_DELIVER (c_SMS_DELIVER* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TAddress (&(sp->TP_OA));
	FREE_c_TP_PID (&(sp->TP_PID));
	FREE_c_TP_DCS (&(sp->TP_DCS));
	FREE_c_TTimeStamp (&(sp->TP_SCTS));
	FREE_c_TP_UD (&(sp->TP_UD));
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

/* Free function for struct c_SMS_STATUS_REPORT */
void FREE_c_SMS_STATUS_REPORT (c_SMS_STATUS_REPORT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TAddress (&(sp->TP_RA));
	FREE_c_TTimeStamp (&(sp->TP_SCTS));
	FREE_c_TTimeStamp (&(sp->TP_DT));
	if (sp->TP_PI_Present) {
		FREE_c_TP_PI (sp->TP_PI);
		EDFree (sp->TP_PI);
		sp->TP_PI_Present = ED_FALSE;
	}
	if (sp->TP_PID_Present) {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
		sp->TP_PID_Present = ED_FALSE;
	}
	if (sp->TP_DCS_Present) {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
		sp->TP_DCS_Present = ED_FALSE;
	}
	if (sp->TP_UD_Present) {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
		sp->TP_UD_Present = ED_FALSE;
	}
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_STATUS_REPORT_TP_PI (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PI_Present == present) return ED_NO_ERRORS;
	sp->TP_PI_Present = present;
	if (present) {
		/*-->*/sp->TP_PI = (c_TP_PI*)EDAlloc (sizeof (c_TP_PI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PI)
		INIT_c_TP_PI (sp->TP_PI);
	} else {
		FREE_c_TP_PI (sp->TP_PI);
		EDFree (sp->TP_PI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_STATUS_REPORT_TP_PID (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PID_Present == present) return ED_NO_ERRORS;
	sp->TP_PID_Present = present;
	if (present) {
		/*-->*/sp->TP_PID = (c_TP_PID*)EDAlloc (sizeof (c_TP_PID));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PID)
		INIT_c_TP_PID (sp->TP_PID);
	} else {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_STATUS_REPORT_TP_DCS (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_DCS_Present == present) return ED_NO_ERRORS;
	sp->TP_DCS_Present = present;
	if (present) {
		/*-->*/sp->TP_DCS = (c_TP_DCS*)EDAlloc (sizeof (c_TP_DCS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_DCS)
		INIT_c_TP_DCS (sp->TP_DCS);
	} else {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_STATUS_REPORT_TP_UD (c_SMS_STATUS_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_UD_Present == present) return ED_NO_ERRORS;
	sp->TP_UD_Present = present;
	if (present) {
		/*-->*/sp->TP_UD = (c_TP_UD*)EDAlloc (sizeof (c_TP_UD));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_UD)
		INIT_c_TP_UD (sp->TP_UD);
	} else {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SMS_SUBMIT */
void FREE_c_SMS_SUBMIT (c_SMS_SUBMIT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TAddress (&(sp->TP_DA));
	FREE_c_TP_PID (&(sp->TP_PID));
	FREE_c_TP_DCS (&(sp->TP_DCS));
	if (sp->TP_VP_Present) {
		FREE_c_TP_VP (sp->TP_VP);
		EDFree (sp->TP_VP);
		sp->TP_VP_Present = ED_FALSE;
	}
	FREE_c_TP_UD (&(sp->TP_UD));
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_SUBMIT_TP_VP (c_SMS_SUBMIT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_VP_Present == present) return ED_NO_ERRORS;
	sp->TP_VP_Present = present;
	if (present) {
		/*-->*/sp->TP_VP = (c_TP_VP*)EDAlloc (sizeof (c_TP_VP));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_VP)
		INIT_c_TP_VP (sp->TP_VP);
	} else {
		FREE_c_TP_VP (sp->TP_VP);
		EDFree (sp->TP_VP);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SMS_COMMAND */
void FREE_c_SMS_COMMAND (c_SMS_COMMAND* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TP_PID (&(sp->TP_PID));
	FREE_c_TAddress (&(sp->TP_DA));
	FREE_c_TP_CD (&(sp->TP_CD));
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

/* Free function for struct c_TRPCause */
void FREE_c_TRPCause (c_TRPCause* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_T24011Address_Addr_Address */
void FREE_c_T24011Address_Addr_Address (c_T24011Address_Addr_Address* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_T24011Address */
void FREE_c_T24011Address (c_T24011Address* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Addr_Present) {
		if (sp->Addr->Address.data) {EDFree (sp->Addr->Address.data); sp->Addr->Address.data = NULL; sp->Addr->Address.allocatedItems=0; /*FR02A*/}
		if (sp->Addr->Address.data___LOCATOR) {EDFree (sp->Addr->Address.data___LOCATOR); sp->Addr->Address.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->Addr);
		sp->Addr = NULL;
		sp->Addr_Present = ED_FALSE;
	}

}

int SETPRESENT_c_T24011Address_Addr (c_T24011Address* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Addr_Present == present) return ED_NO_ERRORS;
	sp->Addr_Present = present;
	if (present) {
		/*-->*/sp->Addr = (c_T24011Address_Addr*)EDAlloc (sizeof (c_T24011Address_Addr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Addr)
		ED_RESET_MEM (sp->Addr, sizeof (c_T24011Address_Addr));
		(sp->Addr->TypeOfNumber) = 0;
		(sp->Addr->NumPlanId) = 0;
		sp->Addr->Address.items = 0;
	} else {
		if (sp->Addr->Address.data) {EDFree (sp->Addr->Address.data); sp->Addr->Address.data = NULL; sp->Addr->Address.allocatedItems=0; /*FR02A*/}
		if (sp->Addr->Address.data___LOCATOR) {EDFree (sp->Addr->Address.data___LOCATOR); sp->Addr->Address.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->Addr);
		sp->Addr = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_MS2SC */
void FREE_c_SMS_MS2SC (c_SMS_MS2SC* sp) {
	switch (sp->Present) {
		case U_c_SMS_MS2SC_SMS_SUBMIT: {
			FREE_c_SMS_SUBMIT (sp->u.SMS_SUBMIT);
			EDFree (sp->u.SMS_SUBMIT);

			break;
		}
		case U_c_SMS_MS2SC_SMS_COMMAND: {
			FREE_c_SMS_COMMAND (sp->u.SMS_COMMAND);
			EDFree (sp->u.SMS_COMMAND);

			break;
		}
		case U_c_SMS_MS2SC_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_MS2SC_NONE;
}

/* Set-present function for c_SMS_MS2SC LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_MS2SC (c_SMS_MS2SC* sp, TPRESENT_c_SMS_MS2SC toBeSetPresent) 
{
	FREE_c_SMS_MS2SC (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_MS2SC_SMS_SUBMIT: {
			sp->u.SMS_SUBMIT = (c_SMS_SUBMIT*)EDAlloc (sizeof (c_SMS_SUBMIT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_SUBMIT)
			INIT_c_SMS_SUBMIT (sp->u.SMS_SUBMIT);

			break;
		}
		case U_c_SMS_MS2SC_SMS_COMMAND: {
			sp->u.SMS_COMMAND = (c_SMS_COMMAND*)EDAlloc (sizeof (c_SMS_COMMAND));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_COMMAND)
			INIT_c_SMS_COMMAND (sp->u.SMS_COMMAND);

			break;
		}
		case U_c_SMS_MS2SC_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_SC2MS */
void FREE_c_SMS_SC2MS (c_SMS_SC2MS* sp) {
	switch (sp->Present) {
		case U_c_SMS_SC2MS_SMS_DELIVER: {
			FREE_c_SMS_DELIVER (sp->u.SMS_DELIVER);
			EDFree (sp->u.SMS_DELIVER);

			break;
		}
		case U_c_SMS_SC2MS_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);
			EDFree (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_SC2MS_NONE;
}

/* Set-present function for c_SMS_SC2MS LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_SC2MS (c_SMS_SC2MS* sp, TPRESENT_c_SMS_SC2MS toBeSetPresent) 
{
	FREE_c_SMS_SC2MS (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_SC2MS_SMS_DELIVER: {
			sp->u.SMS_DELIVER = (c_SMS_DELIVER*)EDAlloc (sizeof (c_SMS_DELIVER));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_DELIVER)
			INIT_c_SMS_DELIVER (sp->u.SMS_DELIVER);

			break;
		}
		case U_c_SMS_SC2MS_SMS_STATUS_REPORT: {
			sp->u.SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_STATUS_REPORT)
			INIT_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_MS2SC_ERR */
void FREE_c_SMS_MS2SC_ERR (c_SMS_MS2SC_ERR* sp) {
	switch (sp->Present) {
		case U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);
			EDFree (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_MS2SC_ERR_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_MS2SC_ERR_NONE;
}

/* Set-present function for c_SMS_MS2SC_ERR LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_MS2SC_ERR (c_SMS_MS2SC_ERR* sp, TPRESENT_c_SMS_MS2SC_ERR toBeSetPresent) 
{
	FREE_c_SMS_MS2SC_ERR (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_MS2SC_ERR_SMS_STATUS_REPORT: {
			sp->u.SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_STATUS_REPORT)
			INIT_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_MS2SC_ERR_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_MS2SC_ACK */
void FREE_c_SMS_MS2SC_ACK (c_SMS_MS2SC_ACK* sp) {
	switch (sp->Present) {
		case U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);
			EDFree (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_MS2SC_ACK_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_MS2SC_ACK_NONE;
}

/* Set-present function for c_SMS_MS2SC_ACK LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_MS2SC_ACK (c_SMS_MS2SC_ACK* sp, TPRESENT_c_SMS_MS2SC_ACK toBeSetPresent) 
{
	FREE_c_SMS_MS2SC_ACK (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_MS2SC_ACK_SMS_STATUS_REPORT: {
			sp->u.SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_STATUS_REPORT)
			INIT_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_MS2SC_ACK_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_SC2MS_ERR */
void FREE_c_SMS_SC2MS_ERR (c_SMS_SC2MS_ERR* sp) {
	switch (sp->Present) {
		case U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);
			EDFree (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_ERR_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_SC2MS_ERR_NONE;
}

/* Set-present function for c_SMS_SC2MS_ERR LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_SC2MS_ERR (c_SMS_SC2MS_ERR* sp, TPRESENT_c_SMS_SC2MS_ERR toBeSetPresent) 
{
	FREE_c_SMS_SC2MS_ERR (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_SC2MS_ERR_SMS_STATUS_REPORT: {
			sp->u.SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_STATUS_REPORT)
			INIT_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_ERR_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_SMS_SC2MS_ACK */
void FREE_c_SMS_SC2MS_ACK (c_SMS_SC2MS_ACK* sp) {
	switch (sp->Present) {
		case U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);
			EDFree (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_ACK_SMS_UNKNOWN: {
			FREE_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);
			EDFree (sp->u.SMS_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_SMS_SC2MS_ACK_NONE;
}

/* Set-present function for c_SMS_SC2MS_ACK LEVEL = -1 */
int GLOB_SETPRESENT_c_SMS_SC2MS_ACK (c_SMS_SC2MS_ACK* sp, TPRESENT_c_SMS_SC2MS_ACK toBeSetPresent) 
{
	FREE_c_SMS_SC2MS_ACK (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_SMS_SC2MS_ACK_SMS_STATUS_REPORT: {
			sp->u.SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_STATUS_REPORT)
			INIT_c_SMS_STATUS_REPORT (sp->u.SMS_STATUS_REPORT);

			break;
		}
		case U_c_SMS_SC2MS_ACK_SMS_UNKNOWN: {
			sp->u.SMS_UNKNOWN = (c_SMS_UNKNOWN*)EDAlloc (sizeof (c_SMS_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.SMS_UNKNOWN)
			INIT_c_SMS_UNKNOWN (sp->u.SMS_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RP_UNKNOWN */
void FREE_c_RP_UNKNOWN (c_RP_UNKNOWN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TransportedData.value != NULL) {
		EDFree (sp->TransportedData.value);
		sp->TransportedData.value = NULL;
	}
	sp->TransportedData.usedBits = 0;

}

/* Free function for struct c_RP_DATA_MSC2MS */
void FREE_c_RP_DATA_MSC2MS (c_RP_DATA_MSC2MS* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_T24011Address (&(sp->RP_OriginatorAddress));
	FREE_c_T24011Address (&(sp->RP_DestinationAddress));
	FREE_c_SMS_SC2MS (&(sp->RP_UserData));

}

/* Free function for struct c_RP_RP_ACK_MSC2MS */
void FREE_c_RP_RP_ACK_MSC2MS (c_RP_RP_ACK_MSC2MS* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->RP_UserData_Present) {
		FREE_c_SMS_SC2MS_ACK (sp->RP_UserData);
		EDFree (sp->RP_UserData);
		sp->RP_UserData_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RP_RP_ACK_MSC2MS_RP_UserData (c_RP_RP_ACK_MSC2MS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RP_UserData_Present == present) return ED_NO_ERRORS;
	sp->RP_UserData_Present = present;
	if (present) {
		/*-->*/sp->RP_UserData = (c_SMS_SC2MS_ACK*)EDAlloc (sizeof (c_SMS_SC2MS_ACK));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RP_UserData)
		INIT_c_SMS_SC2MS_ACK (sp->RP_UserData);
	} else {
		FREE_c_SMS_SC2MS_ACK (sp->RP_UserData);
		EDFree (sp->RP_UserData);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RP_RP_ERROR_MSC2MS */
void FREE_c_RP_RP_ERROR_MSC2MS (c_RP_RP_ERROR_MSC2MS* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TRPCause (&(sp->RP_Cause));
	if (sp->RP_UserData_Present) {
		FREE_c_SMS_SC2MS_ERR (sp->RP_UserData);
		EDFree (sp->RP_UserData);
		sp->RP_UserData_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RP_RP_ERROR_MSC2MS_RP_UserData (c_RP_RP_ERROR_MSC2MS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RP_UserData_Present == present) return ED_NO_ERRORS;
	sp->RP_UserData_Present = present;
	if (present) {
		/*-->*/sp->RP_UserData = (c_SMS_SC2MS_ERR*)EDAlloc (sizeof (c_SMS_SC2MS_ERR));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RP_UserData)
		INIT_c_SMS_SC2MS_ERR (sp->RP_UserData);
	} else {
		FREE_c_SMS_SC2MS_ERR (sp->RP_UserData);
		EDFree (sp->RP_UserData);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RP_DATA_MS2MSC */
void FREE_c_RP_DATA_MS2MSC (c_RP_DATA_MS2MSC* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_T24011Address (&(sp->RP_OriginatorAddress));
	FREE_c_T24011Address (&(sp->RP_DestinationAddress));
	FREE_c_SMS_MS2SC (&(sp->RP_UserData));

}

/* Free function for struct c_RP_RP_SMMA_MS2MSC */
void FREE_c_RP_RP_SMMA_MS2MSC (c_RP_RP_SMMA_MS2MSC* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RP_RP_ACK_MS2MSC */
void FREE_c_RP_RP_ACK_MS2MSC (c_RP_RP_ACK_MS2MSC* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->RP_UserData_Present) {
		FREE_c_SMS_MS2SC_ACK (sp->RP_UserData);
		EDFree (sp->RP_UserData);
		sp->RP_UserData_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (c_RP_RP_ACK_MS2MSC* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RP_UserData_Present == present) return ED_NO_ERRORS;
	sp->RP_UserData_Present = present;
	if (present) {
		/*-->*/sp->RP_UserData = (c_SMS_MS2SC_ACK*)EDAlloc (sizeof (c_SMS_MS2SC_ACK));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RP_UserData)
		INIT_c_SMS_MS2SC_ACK (sp->RP_UserData);
	} else {
		FREE_c_SMS_MS2SC_ACK (sp->RP_UserData);
		EDFree (sp->RP_UserData);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RP_RP_ERROR_MS2MSC */
void FREE_c_RP_RP_ERROR_MS2MSC (c_RP_RP_ERROR_MS2MSC* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TRPCause (&(sp->RP_Cause));
	if (sp->RP_UserData_Present) {
		FREE_c_SMS_MS2SC_ERR (sp->RP_UserData);
		EDFree (sp->RP_UserData);
		sp->RP_UserData_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (c_RP_RP_ERROR_MS2MSC* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RP_UserData_Present == present) return ED_NO_ERRORS;
	sp->RP_UserData_Present = present;
	if (present) {
		/*-->*/sp->RP_UserData = (c_SMS_MS2SC_ERR*)EDAlloc (sizeof (c_SMS_MS2SC_ERR));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RP_UserData)
		INIT_c_SMS_MS2SC_ERR (sp->RP_UserData);
	} else {
		FREE_c_SMS_MS2SC_ERR (sp->RP_UserData);
		EDFree (sp->RP_UserData);
	}
	return ED_NO_ERRORS;
}

/* Free function for union c_CPUserData */
void FREE_c_CPUserData (c_CPUserData* sp) {
	switch (sp->Present) {
		case U_c_CPUserData_RP_DATA_MSC2MS: {
			FREE_c_RP_DATA_MSC2MS (sp->u.RP_DATA_MSC2MS);
			EDFree (sp->u.RP_DATA_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_DATA_MS2MSC: {
			FREE_c_RP_DATA_MS2MSC (sp->u.RP_DATA_MS2MSC);
			EDFree (sp->u.RP_DATA_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_SMMA_MS2MSC: {
			FREE_c_RP_RP_SMMA_MS2MSC (sp->u.RP_RP_SMMA_MS2MSC);
			EDFree (sp->u.RP_RP_SMMA_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ACK_MS2MSC: {
			FREE_c_RP_RP_ACK_MS2MSC (sp->u.RP_RP_ACK_MS2MSC);
			EDFree (sp->u.RP_RP_ACK_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ACK_MSC2MS: {
			FREE_c_RP_RP_ACK_MSC2MS (sp->u.RP_RP_ACK_MSC2MS);
			EDFree (sp->u.RP_RP_ACK_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_RP_ERROR_MS2MSC: {
			FREE_c_RP_RP_ERROR_MS2MSC (sp->u.RP_RP_ERROR_MS2MSC);
			EDFree (sp->u.RP_RP_ERROR_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ERROR_MSC2MS: {
			FREE_c_RP_RP_ERROR_MSC2MS (sp->u.RP_RP_ERROR_MSC2MS);
			EDFree (sp->u.RP_RP_ERROR_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_UNKNOWN: {
			FREE_c_RP_UNKNOWN (sp->u.RP_UNKNOWN);
			EDFree (sp->u.RP_UNKNOWN);

			break;
		}

		default:;
	}
	sp->Present = U_c_CPUserData_NONE;
}

/* Set-present function for c_CPUserData LEVEL = -1 */
int GLOB_SETPRESENT_c_CPUserData (c_CPUserData* sp, TPRESENT_c_CPUserData toBeSetPresent) 
{
	FREE_c_CPUserData (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_CPUserData_RP_DATA_MSC2MS: {
			sp->u.RP_DATA_MSC2MS = (c_RP_DATA_MSC2MS*)EDAlloc (sizeof (c_RP_DATA_MSC2MS));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_DATA_MSC2MS)
			INIT_c_RP_DATA_MSC2MS (sp->u.RP_DATA_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_DATA_MS2MSC: {
			sp->u.RP_DATA_MS2MSC = (c_RP_DATA_MS2MSC*)EDAlloc (sizeof (c_RP_DATA_MS2MSC));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_DATA_MS2MSC)
			INIT_c_RP_DATA_MS2MSC (sp->u.RP_DATA_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_SMMA_MS2MSC: {
			sp->u.RP_RP_SMMA_MS2MSC = (c_RP_RP_SMMA_MS2MSC*)EDAlloc (sizeof (c_RP_RP_SMMA_MS2MSC));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_RP_SMMA_MS2MSC)
			INIT_c_RP_RP_SMMA_MS2MSC (sp->u.RP_RP_SMMA_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ACK_MS2MSC: {
			sp->u.RP_RP_ACK_MS2MSC = (c_RP_RP_ACK_MS2MSC*)EDAlloc (sizeof (c_RP_RP_ACK_MS2MSC));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_RP_ACK_MS2MSC)
			INIT_c_RP_RP_ACK_MS2MSC (sp->u.RP_RP_ACK_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ACK_MSC2MS: {
			sp->u.RP_RP_ACK_MSC2MS = (c_RP_RP_ACK_MSC2MS*)EDAlloc (sizeof (c_RP_RP_ACK_MSC2MS));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_RP_ACK_MSC2MS)
			INIT_c_RP_RP_ACK_MSC2MS (sp->u.RP_RP_ACK_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_RP_ERROR_MS2MSC: {
			sp->u.RP_RP_ERROR_MS2MSC = (c_RP_RP_ERROR_MS2MSC*)EDAlloc (sizeof (c_RP_RP_ERROR_MS2MSC));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_RP_ERROR_MS2MSC)
			INIT_c_RP_RP_ERROR_MS2MSC (sp->u.RP_RP_ERROR_MS2MSC);

			break;
		}
		case U_c_CPUserData_RP_RP_ERROR_MSC2MS: {
			sp->u.RP_RP_ERROR_MSC2MS = (c_RP_RP_ERROR_MSC2MS*)EDAlloc (sizeof (c_RP_RP_ERROR_MSC2MS));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_RP_ERROR_MSC2MS)
			INIT_c_RP_RP_ERROR_MSC2MS (sp->u.RP_RP_ERROR_MSC2MS);

			break;
		}
		case U_c_CPUserData_RP_UNKNOWN: {
			sp->u.RP_UNKNOWN = (c_RP_UNKNOWN*)EDAlloc (sizeof (c_RP_UNKNOWN));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RP_UNKNOWN)
			INIT_c_RP_UNKNOWN (sp->u.RP_UNKNOWN);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CP_DATA */
void FREE_c_CP_DATA (c_CP_DATA* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_CPUserData (&(sp->CPUserData));

}

/* Free function for struct c_CP_ACK */
void FREE_c_CP_ACK (c_CP_ACK* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CP_ERROR */
void FREE_c_CP_ERROR (c_CP_ERROR* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SMS_SUBMIT_REPORT_RP_ERROR */
void FREE_c_SMS_SUBMIT_REPORT_RP_ERROR (c_SMS_SUBMIT_REPORT_RP_ERROR* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TP_PI (&(sp->TP_PI));
	FREE_c_TTimeStamp (&(sp->TP_SCTS));
	if (sp->TP_PID_Present) {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
		sp->TP_PID_Present = ED_FALSE;
	}
	if (sp->TP_DCS_Present) {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
		sp->TP_DCS_Present = ED_FALSE;
	}
	if (sp->TP_UD_Present) {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
		sp->TP_UD_Present = ED_FALSE;
	}
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_PID (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PID_Present == present) return ED_NO_ERRORS;
	sp->TP_PID_Present = present;
	if (present) {
		/*-->*/sp->TP_PID = (c_TP_PID*)EDAlloc (sizeof (c_TP_PID));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PID)
		INIT_c_TP_PID (sp->TP_PID);
	} else {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_DCS (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_DCS_Present == present) return ED_NO_ERRORS;
	sp->TP_DCS_Present = present;
	if (present) {
		/*-->*/sp->TP_DCS = (c_TP_DCS*)EDAlloc (sizeof (c_TP_DCS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_DCS)
		INIT_c_TP_DCS (sp->TP_DCS);
	} else {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ERROR_TP_UD (c_SMS_SUBMIT_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_UD_Present == present) return ED_NO_ERRORS;
	sp->TP_UD_Present = present;
	if (present) {
		/*-->*/sp->TP_UD = (c_TP_UD*)EDAlloc (sizeof (c_TP_UD));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_UD)
		INIT_c_TP_UD (sp->TP_UD);
	} else {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SMS_SUBMIT_REPORT_RP_ACK */
void FREE_c_SMS_SUBMIT_REPORT_RP_ACK (c_SMS_SUBMIT_REPORT_RP_ACK* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TP_PI (&(sp->TP_PI));
	FREE_c_TTimeStamp (&(sp->TP_SCTS));
	if (sp->TP_PID_Present) {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
		sp->TP_PID_Present = ED_FALSE;
	}
	if (sp->TP_DCS_Present) {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
		sp->TP_DCS_Present = ED_FALSE;
	}
	if (sp->TP_UD_Present) {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
		sp->TP_UD_Present = ED_FALSE;
	}
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_PID (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PID_Present == present) return ED_NO_ERRORS;
	sp->TP_PID_Present = present;
	if (present) {
		/*-->*/sp->TP_PID = (c_TP_PID*)EDAlloc (sizeof (c_TP_PID));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PID)
		INIT_c_TP_PID (sp->TP_PID);
	} else {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_DCS (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_DCS_Present == present) return ED_NO_ERRORS;
	sp->TP_DCS_Present = present;
	if (present) {
		/*-->*/sp->TP_DCS = (c_TP_DCS*)EDAlloc (sizeof (c_TP_DCS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_DCS)
		INIT_c_TP_DCS (sp->TP_DCS);
	} else {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_SUBMIT_REPORT_RP_ACK_TP_UD (c_SMS_SUBMIT_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_UD_Present == present) return ED_NO_ERRORS;
	sp->TP_UD_Present = present;
	if (present) {
		/*-->*/sp->TP_UD = (c_TP_UD*)EDAlloc (sizeof (c_TP_UD));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_UD)
		INIT_c_TP_UD (sp->TP_UD);
	} else {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SMS_DELIVERY_REPORT_RP_ERROR */
void FREE_c_SMS_DELIVERY_REPORT_RP_ERROR (c_SMS_DELIVERY_REPORT_RP_ERROR* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TP_PI (&(sp->TP_PI));
	if (sp->TP_PID_Present) {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
		sp->TP_PID_Present = ED_FALSE;
	}
	if (sp->TP_DCS_Present) {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
		sp->TP_DCS_Present = ED_FALSE;
	}
	if (sp->TP_UD_Present) {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
		sp->TP_UD_Present = ED_FALSE;
	}
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_PID (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PID_Present == present) return ED_NO_ERRORS;
	sp->TP_PID_Present = present;
	if (present) {
		/*-->*/sp->TP_PID = (c_TP_PID*)EDAlloc (sizeof (c_TP_PID));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PID)
		INIT_c_TP_PID (sp->TP_PID);
	} else {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_DCS (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_DCS_Present == present) return ED_NO_ERRORS;
	sp->TP_DCS_Present = present;
	if (present) {
		/*-->*/sp->TP_DCS = (c_TP_DCS*)EDAlloc (sizeof (c_TP_DCS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_DCS)
		INIT_c_TP_DCS (sp->TP_DCS);
	} else {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ERROR_TP_UD (c_SMS_DELIVERY_REPORT_RP_ERROR* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_UD_Present == present) return ED_NO_ERRORS;
	sp->TP_UD_Present = present;
	if (present) {
		/*-->*/sp->TP_UD = (c_TP_UD*)EDAlloc (sizeof (c_TP_UD));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_UD)
		INIT_c_TP_UD (sp->TP_UD);
	} else {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SMS_DELIVERY_REPORT_RP_ACK */
void FREE_c_SMS_DELIVERY_REPORT_RP_ACK (c_SMS_DELIVERY_REPORT_RP_ACK* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_MTI (&(sp->header));
	FREE_c_TP_PI (&(sp->TP_PI));
	if (sp->TP_PID_Present) {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
		sp->TP_PID_Present = ED_FALSE;
	}
	if (sp->TP_DCS_Present) {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
		sp->TP_DCS_Present = ED_FALSE;
	}
	if (sp->TP_UD_Present) {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
		sp->TP_UD_Present = ED_FALSE;
	}
	if (sp->spare.value != NULL) {
		EDFree (sp->spare.value);
		sp->spare.value = NULL;
	}
	sp->spare.usedBits = 0;

}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_PID_Present == present) return ED_NO_ERRORS;
	sp->TP_PID_Present = present;
	if (present) {
		/*-->*/sp->TP_PID = (c_TP_PID*)EDAlloc (sizeof (c_TP_PID));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_PID)
		INIT_c_TP_PID (sp->TP_PID);
	} else {
		FREE_c_TP_PID (sp->TP_PID);
		EDFree (sp->TP_PID);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_DCS_Present == present) return ED_NO_ERRORS;
	sp->TP_DCS_Present = present;
	if (present) {
		/*-->*/sp->TP_DCS = (c_TP_DCS*)EDAlloc (sizeof (c_TP_DCS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_DCS)
		INIT_c_TP_DCS (sp->TP_DCS);
	} else {
		FREE_c_TP_DCS (sp->TP_DCS);
		EDFree (sp->TP_DCS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD (c_SMS_DELIVERY_REPORT_RP_ACK* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TP_UD_Present == present) return ED_NO_ERRORS;
	sp->TP_UD_Present = present;
	if (present) {
		/*-->*/sp->TP_UD = (c_TP_UD*)EDAlloc (sizeof (c_TP_UD));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TP_UD)
		INIT_c_TP_UD (sp->TP_UD);
	} else {
		FREE_c_TP_UD (sp->TP_UD);
		EDFree (sp->TP_UD);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GenericTLV_SMS */
void FREE_c_GenericTLV_SMS (c_GenericTLV_SMS* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TLV_Data.value != NULL) {
		EDFree (sp->TLV_Data.value);
		sp->TLV_Data.value = NULL;
	}
	sp->TLV_Data.usedBits = 0;

}

/* SETITEMS commands for type 'c_TAddress_Address'. Existing items are not changed. */
int SETITEMS_c_TAddress_Address (c_TAddress_Address* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_OCTET* tmp;
		tmp = (ED_OCTET*)EDAlloc (sizeof (ED_OCTET) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_OCTET) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			(sequence->data[i]) = 0;
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* SETITEMS commands for type 'c_TEnVoiceMailNotification_VM_NOTIFICATIONS'. Existing items are not changed. */
int SETITEMS_c_TEnVoiceMailNotification_VM_NOTIFICATIONS (c_TEnVoiceMailNotification_VM_NOTIFICATIONS* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TEnVoiceMailNotificationItem** tmp;
		tmp = (c_TEnVoiceMailNotificationItem**)EDAlloc (sizeof (c_TEnVoiceMailNotificationItem*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TEnVoiceMailNotificationItem*) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			sequence->data[i] = (c_TEnVoiceMailNotificationItem*)EDAlloc (sizeof (c_TEnVoiceMailNotificationItem));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_TEnVoiceMailNotificationItem (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_TEnVoiceMailNotificationItem (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* SETITEMS commands for type 'c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS'. Existing items are not changed. */
int SETITEMS_c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS (c_TEnVoiceMailDeleteConfirmation_VM_DELETE_CONFIRMATIONS* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TEnVoiceMailDeleteConfirmationItem** tmp;
		tmp = (c_TEnVoiceMailDeleteConfirmationItem**)EDAlloc (sizeof (c_TEnVoiceMailDeleteConfirmationItem*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TEnVoiceMailDeleteConfirmationItem*) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			sequence->data[i] = (c_TEnVoiceMailDeleteConfirmationItem*)EDAlloc (sizeof (c_TEnVoiceMailDeleteConfirmationItem));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_TEnVoiceMailDeleteConfirmationItem (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_TEnVoiceMailDeleteConfirmationItem (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_TP_VP_Enhanced */
void FREE_c_TP_VP_Enhanced (c_TP_VP_Enhanced* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TP_VP_Enhanced_Extension (&(sp->Extension));

}

/* Set-present function for c_TP_VP_Enhanced_Extension LEVEL = 0 */
int GLOB_SETPRESENT_c_TP_VP_Enhanced_Extension (c_TP_VP_Enhanced_Extension* sp, TPRESENT_c_TP_VP_Enhanced_Extension toBeSetPresent) 
{
	int i0;
	FREE_c_TP_VP_Enhanced_Extension (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_TP_VP_Enhanced_Extension_NoValidityPeriod: {
			(sp->u.NoValidityPeriod) = 0;

			break;
		}
		case U_c_TP_VP_Enhanced_Extension_Relative: {
			(sp->u.Relative) = 0;

			break;
		}
		case U_c_TP_VP_Enhanced_Extension_RelativeInteger: {
			(sp->u.RelativeInteger) = 0;

			break;
		}
		case U_c_TP_VP_Enhanced_Extension_RelativeSemiOctet: {
			sp->u.RelativeSemiOctet = (ED_OCTET*)EDAlloc (sizeof (ED_OCTET[6]));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.RelativeSemiOctet)
			for (i0=0; i0<6; i0++) {
				(sp->u.RelativeSemiOctet[i0]) = 0;
			}

			break;
		}
		case U_c_TP_VP_Enhanced_Extension_UnknownExtension: {
			sp->u.UnknownExtension = (c_TP_VP_Enhanced_Extension_UnknownExtension*)EDAlloc (sizeof (c_TP_VP_Enhanced_Extension_UnknownExtension));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.UnknownExtension)
			ED_RESET_MEM (sp->u.UnknownExtension, sizeof (c_TP_VP_Enhanced_Extension_UnknownExtension));
			(sp->u.UnknownExtension->ExtensionBit) = 0;
			for (i0=0; i0<6; i0++) {
				(sp->u.UnknownExtension->UnknownOctets[i0]) = 0;
			}
			

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_TP_VP_Enhanced_Extension_UnknownExtension */
void FREE_c_TP_VP_Enhanced_Extension_UnknownExtension (c_TP_VP_Enhanced_Extension_UnknownExtension* sp) {
ED_WARNING_REMOVER(sp);

}

/* SETITEMS commands for type 'c_TP_UD_Message'. Existing items are not changed. */
int SETITEMS_c_TP_UD_Message (c_TP_UD_Message* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_LONG* tmp;
		tmp = (ED_LONG*)EDAlloc (sizeof (ED_LONG) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_LONG) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			(sequence->data[i]) = 0;
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_T24011Address_Addr */
void FREE_c_T24011Address_Addr (c_T24011Address_Addr* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Address.data) {EDFree (sp->Address.data); sp->Address.data = NULL; sp->Address.allocatedItems=0; /*FR02A*/}
	if (sp->Address.data___LOCATOR) {EDFree (sp->Address.data___LOCATOR); sp->Address.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_T24011Address_Addr_Address'. Existing items are not changed. */
int SETITEMS_c_T24011Address_Addr_Address (c_T24011Address_Addr_Address* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_OCTET* tmp;
		tmp = (ED_OCTET*)EDAlloc (sizeof (ED_OCTET) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_OCTET) * (size_t)sequence->items);
			}
			EDFree (sequence->data);
		}
		sequence->allocatedItems = newSize;
		sequence->data = tmp;
	
		tmpLoc = (ED_LOCATOR*)EDAlloc (sizeof (ED_LOCATOR) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmpLoc)
		if (tmpLoc != NULL && sequence->items > 0) {
			ED_MEM_COPY (tmpLoc, sequence->data___LOCATOR, sizeof (ED_LOCATOR) * (size_t)sequence->items);
		}
		if (sequence->data___LOCATOR) EDFree (sequence->data___LOCATOR);
		sequence->data___LOCATOR = tmpLoc;
	}

	if (desiredItems > sequence->items) {
		for (i=sequence->items; i<desiredItems; i++) {
			(sequence->data[i]) = 0;
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

