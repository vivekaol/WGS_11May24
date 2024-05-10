/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __UserDefinedDataTypes_SMS_h
#define __UserDefinedDataTypes_SMS_h
/* ZZZ */

#include "ed_lib.h"
#include "ed_c_SMS.h"
#include "ed_user.h"
#include "endec_configs_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TTimeStamp".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TTimeStamp (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TTimeStamp* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TTimeStamp (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TTimeStamp* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_PI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_PI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_PI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_PI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_PI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_PID".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_PID (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_PID* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_PID (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_PID* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TConcShortMsgs8BitRefNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TConcShortMsgs8BitRefNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TConcShortMsgs8BitRefNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TConcShortMsgs8BitRefNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TConcShortMsgs8BitRefNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TSpecialSmsMsgInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSpecialSmsMsgInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSpecialSmsMsgInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSpecialSmsMsgInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSpecialSmsMsgInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TApplPortAddrScheme8BitAddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TApplPortAddrScheme8BitAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TApplPortAddrScheme8BitAddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TApplPortAddrScheme8BitAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TApplPortAddrScheme8BitAddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TApplPortAddrScheme16BitAddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TApplPortAddrScheme16BitAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TApplPortAddrScheme16BitAddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TApplPortAddrScheme16BitAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TApplPortAddrScheme16BitAddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TSmscCtrlParams".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmscCtrlParams (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmscCtrlParams* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmscCtrlParams (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmscCtrlParams* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TUdhSrcInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUdhSrcInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUdhSrcInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUdhSrcInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUdhSrcInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TConcShortMsg16BitRefNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TConcShortMsg16BitRefNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TConcShortMsg16BitRefNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TConcShortMsg16BitRefNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TConcShortMsg16BitRefNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TTextFmt".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TTextFmt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TTextFmt* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TTextFmt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TTextFmt* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TPredefSound".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TPredefSound (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TPredefSound* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TPredefSound (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TPredefSound* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TUserDefSound".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserDefSound (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserDefSound* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserDefSound (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserDefSound* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TPredefAnim".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TPredefAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TPredefAnim* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TPredefAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TPredefAnim* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TLargeAnim".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TLargeAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TLargeAnim* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TLargeAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TLargeAnim* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TSmallAnim".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmallAnim (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmallAnim* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmallAnim (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmallAnim* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TLargePict".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TLargePict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TLargePict* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TLargePict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TLargePict* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TSmallPict".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TSmallPict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TSmallPict* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TSmallPict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TSmallPict* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TVarPict".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TVarPict (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TVarPict* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TVarPict (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TVarPict* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TUserPromptInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserPromptInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserPromptInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserPromptInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserPromptInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TExtObj".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TExtObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TExtObj* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TExtObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TExtObj* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TReusedExtObj".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TReusedExtObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TReusedExtObj* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TReusedExtObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TReusedExtObj* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TComprCtrl".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TComprCtrl (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TComprCtrl* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TComprCtrl (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TComprCtrl* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TObjDistrInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TObjDistrInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TObjDistrInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TObjDistrInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TObjDistrInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TStdWvgObj".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TStdWvgObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TStdWvgObj* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TStdWvgObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TStdWvgObj* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TCharSizeWvgObj".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TCharSizeWvgObj (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TCharSizeWvgObj* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TCharSizeWvgObj (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TCharSizeWvgObj* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRfc822EMailHdr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRfc822EMailHdr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRfc822EMailHdr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRfc822EMailHdr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRfc822EMailHdr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "THyperlinkFmtElem".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_THyperlinkFmtElem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_THyperlinkFmtElem* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_THyperlinkFmtElem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_THyperlinkFmtElem* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRPCause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRPCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRPCause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRPCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRPCause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_UNKNOWN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_UNKNOWN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_UNKNOWN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_UNKNOWN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_UNKNOWN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RP_UNKNOWN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_UNKNOWN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_UNKNOWN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_UNKNOWN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_UNKNOWN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TUserDataIE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUserDataIE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUserDataIE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUserDataIE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUserDataIE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TAddress".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TAddress* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TAddress* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_DCS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_DCS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_DCS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_DCS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_DCS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_VP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_VP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_VP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_VP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_VP* ED_CONST Destin, ED_EXLONG Length, unsigned TV_VP));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_CD".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_CD (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_CD* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_CD (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_CD* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_UD".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_UD (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_UD* ED_CONST Source, ED_BOOLEAN TP_UDHI, const c_TP_DCS* TP_DCS));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_UD (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_UD* ED_CONST Destin, ED_EXLONG Length, ED_BOOLEAN TP_UDHI, c_TP_DCS* TP_DCS));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TP_MTI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TP_MTI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TP_MTI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TP_MTI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TP_MTI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TUnknownIE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TUnknownIE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TUnknownIE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TUnknownIE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TUnknownIE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TEnVoiceMailInfo".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailInfo (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailInfo* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailInfo (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailInfo* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TEnVoiceMailNotification".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailNotification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailNotification* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailNotification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailNotification* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TEnVoiceMailNotificationItem".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailNotificationItem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailNotificationItem* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailNotificationItem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailNotificationItem* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TEnVoiceMailDeleteConfirmation".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailDeleteConfirmation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailDeleteConfirmation* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailDeleteConfirmation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailDeleteConfirmation* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TEnVoiceMailDeleteConfirmationItem".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TEnVoiceMailDeleteConfirmationItem (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TEnVoiceMailDeleteConfirmationItem* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TEnVoiceMailDeleteConfirmationItem (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TEnVoiceMailDeleteConfirmationItem* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "T24011Address".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_T24011Address (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_T24011Address* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_T24011Address (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_T24011Address* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_MS2SC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_SC2MS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_MS2SC_ERR".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC_ERR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC_ERR* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC_ERR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC_ERR* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_MS2SC_ACK".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_MS2SC_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_MS2SC_ACK* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_MS2SC_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_MS2SC_ACK* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_SC2MS_ERR".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS_ERR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS_ERR* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS_ERR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS_ERR* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_SC2MS_ACK".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SC2MS_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SC2MS_ACK* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SC2MS_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SC2MS_ACK* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CPUserData".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CPUserData (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CPUserData* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CPUserData (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CPUserData* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GenericTLV_SMS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_SMS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_SMS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_SMS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_SMS* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

