/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_dump_SMS_h_H
#define __ed_c_dump_SMS_h_H

#include "ed_c_SMS.h"
#include "ed_c_recog_SMS.h"
#include "ed_dump.h"
#ifdef __cplusplus
	extern "C" {
#endif

void Dump_c_TAddress (TEDOStream* OStream, const c_TAddress* Data);

void Dump_c_TEnVoiceMailNotificationItem (TEDOStream* OStream, const c_TEnVoiceMailNotificationItem* Data);

void Dump_c_TEnVoiceMailDeleteConfirmationItem (TEDOStream* OStream, const c_TEnVoiceMailDeleteConfirmationItem* Data);

void Dump_c_TEnVoiceMailNotification (TEDOStream* OStream, const c_TEnVoiceMailNotification* Data);

void Dump_c_TEnVoiceMailDeleteConfirmation (TEDOStream* OStream, const c_TEnVoiceMailDeleteConfirmation* Data);

void Dump_c_TConcShortMsgs8BitRefNum (TEDOStream* OStream, const c_TConcShortMsgs8BitRefNum* Data);

void Dump_c_TSpecialSmsMsgInd (TEDOStream* OStream, const c_TSpecialSmsMsgInd* Data);

void Dump_c_TApplPortAddrScheme8BitAddr (TEDOStream* OStream, const c_TApplPortAddrScheme8BitAddr* Data);

void Dump_c_TApplPortAddrScheme16BitAddr (TEDOStream* OStream, const c_TApplPortAddrScheme16BitAddr* Data);

void Dump_c_TSmscCtrlParams (TEDOStream* OStream, const c_TSmscCtrlParams* Data);

void Dump_c_TUdhSrcInd (TEDOStream* OStream, const c_TUdhSrcInd* Data);

void Dump_c_TConcShortMsg16BitRefNum (TEDOStream* OStream, const c_TConcShortMsg16BitRefNum* Data);

void Dump_c_TTextFmt (TEDOStream* OStream, const c_TTextFmt* Data);

void Dump_c_TPredefSound (TEDOStream* OStream, const c_TPredefSound* Data);

void Dump_c_TUserDefSound (TEDOStream* OStream, const c_TUserDefSound* Data);

void Dump_c_TPredefAnim (TEDOStream* OStream, const c_TPredefAnim* Data);

void Dump_c_TLargeAnim (TEDOStream* OStream, const c_TLargeAnim* Data);

void Dump_c_TSmallAnim (TEDOStream* OStream, const c_TSmallAnim* Data);

void Dump_c_TLargePict (TEDOStream* OStream, const c_TLargePict* Data);

void Dump_c_TSmallPict (TEDOStream* OStream, const c_TSmallPict* Data);

void Dump_c_TVarPict (TEDOStream* OStream, const c_TVarPict* Data);

void Dump_c_TUserPromptInd (TEDOStream* OStream, const c_TUserPromptInd* Data);

void Dump_c_TExtObj (TEDOStream* OStream, const c_TExtObj* Data);

void Dump_c_TReusedExtObj (TEDOStream* OStream, const c_TReusedExtObj* Data);

void Dump_c_TComprCtrl (TEDOStream* OStream, const c_TComprCtrl* Data);

void Dump_c_TObjDistrInd (TEDOStream* OStream, const c_TObjDistrInd* Data);

void Dump_c_TStdWvgObj (TEDOStream* OStream, const c_TStdWvgObj* Data);

void Dump_c_TCharSizeWvgObj (TEDOStream* OStream, const c_TCharSizeWvgObj* Data);

void Dump_c_TRfc822EMailHdr (TEDOStream* OStream, const c_TRfc822EMailHdr* Data);

void Dump_c_THyperlinkFmtElem (TEDOStream* OStream, const c_THyperlinkFmtElem* Data);

void Dump_c_TUnknownIE (TEDOStream* OStream, const c_TUnknownIE* Data);

void Dump_c_TEnVoiceMailInfo (TEDOStream* OStream, const c_TEnVoiceMailInfo* Data);

void Dump_c_TUserDataIEUnion (TEDOStream* OStream, const c_TUserDataIEUnion* Data);

void Dump_c_TUserDataIE (TEDOStream* OStream, const c_TUserDataIE* Data);

void Dump_c_TTimeStamp (TEDOStream* OStream, const c_TTimeStamp* Data);

void Dump_c_TP_PI (TEDOStream* OStream, const c_TP_PI* Data);

void Dump_c_TP_PID (TEDOStream* OStream, const c_TP_PID* Data);

void Dump_c_TP_DCS (TEDOStream* OStream, const c_TP_DCS* Data);

void Dump_c_TP_VP (TEDOStream* OStream, const c_TP_VP* Data);

void Dump_c_TP_CD (TEDOStream* OStream, const c_TP_CD* Data);

void Dump_c_TP_UD (TEDOStream* OStream, const c_TP_UD* Data);

void Dump_c_TP_MTI (TEDOStream* OStream, const c_TP_MTI* Data);

void Dump_c_SMS_UNKNOWN (TEDOStream* OStream, const c_SMS_UNKNOWN* Data);

void Dump_c_SMS_DELIVER (TEDOStream* OStream, const c_SMS_DELIVER* Data);

void Dump_c_SMS_STATUS_REPORT (TEDOStream* OStream, const c_SMS_STATUS_REPORT* Data);

void Dump_c_SMS_SUBMIT (TEDOStream* OStream, const c_SMS_SUBMIT* Data);

void Dump_c_SMS_COMMAND (TEDOStream* OStream, const c_SMS_COMMAND* Data);

void Dump_c_TRPCause (TEDOStream* OStream, const c_TRPCause* Data);

void Dump_c_T24011Address (TEDOStream* OStream, const c_T24011Address* Data);

void Dump_c_SMS_MS2SC (TEDOStream* OStream, const c_SMS_MS2SC* Data);

void Dump_c_SMS_SC2MS (TEDOStream* OStream, const c_SMS_SC2MS* Data);

void Dump_c_SMS_MS2SC_ERR (TEDOStream* OStream, const c_SMS_MS2SC_ERR* Data);

void Dump_c_SMS_MS2SC_ACK (TEDOStream* OStream, const c_SMS_MS2SC_ACK* Data);

void Dump_c_SMS_SC2MS_ERR (TEDOStream* OStream, const c_SMS_SC2MS_ERR* Data);

void Dump_c_SMS_SC2MS_ACK (TEDOStream* OStream, const c_SMS_SC2MS_ACK* Data);

void Dump_c_RP_UNKNOWN (TEDOStream* OStream, const c_RP_UNKNOWN* Data);

void Dump_c_RP_DATA_MSC2MS (TEDOStream* OStream, const c_RP_DATA_MSC2MS* Data);

void Dump_c_RP_RP_ACK_MSC2MS (TEDOStream* OStream, const c_RP_RP_ACK_MSC2MS* Data);

void Dump_c_RP_RP_ERROR_MSC2MS (TEDOStream* OStream, const c_RP_RP_ERROR_MSC2MS* Data);

void Dump_c_RP_DATA_MS2MSC (TEDOStream* OStream, const c_RP_DATA_MS2MSC* Data);

void Dump_c_RP_RP_SMMA_MS2MSC (TEDOStream* OStream, const c_RP_RP_SMMA_MS2MSC* Data);

void Dump_c_RP_RP_ACK_MS2MSC (TEDOStream* OStream, const c_RP_RP_ACK_MS2MSC* Data);

void Dump_c_RP_RP_ERROR_MS2MSC (TEDOStream* OStream, const c_RP_RP_ERROR_MS2MSC* Data);

void Dump_c_CPUserData (TEDOStream* OStream, const c_CPUserData* Data);

void Dump_c_CP_DATA (TEDOStream* OStream, const c_CP_DATA* Data);

void Dump_c_CP_ACK (TEDOStream* OStream, const c_CP_ACK* Data);

void Dump_c_CP_ERROR (TEDOStream* OStream, const c_CP_ERROR* Data);

void Dump_c_SMS_SUBMIT_REPORT_RP_ERROR (TEDOStream* OStream, const c_SMS_SUBMIT_REPORT_RP_ERROR* Data);

void Dump_c_SMS_SUBMIT_REPORT_RP_ACK (TEDOStream* OStream, const c_SMS_SUBMIT_REPORT_RP_ACK* Data);

void Dump_c_SMS_DELIVERY_REPORT_RP_ERROR (TEDOStream* OStream, const c_SMS_DELIVERY_REPORT_RP_ERROR* Data);

void Dump_c_SMS_DELIVERY_REPORT_RP_ACK (TEDOStream* OStream, const c_SMS_DELIVERY_REPORT_RP_ACK* Data);

void Dump_c_GenericTLV_SMS (TEDOStream* OStream, const c_GenericTLV_SMS* Data);

void Dump_CM_CP (TEDOStream* OStream, const TCM_CP_Data* Data);
void Dump_MSC2MS (TEDOStream* OStream, const TMSC2MS_Data* Data);
void Dump_MS2MSC (TEDOStream* OStream, const TMS2MSC_Data* Data);
void Dump_SC2MS (TEDOStream* OStream, const TSC2MS_Data* Data);
void Dump_SC2MS_ERR (TEDOStream* OStream, const TSC2MS_ERR_Data* Data);
void Dump_SC2MS_ACK (TEDOStream* OStream, const TSC2MS_ACK_Data* Data);
void Dump_MS2SC (TEDOStream* OStream, const TMS2SC_Data* Data);
void Dump_MS2SC_ERR (TEDOStream* OStream, const TMS2SC_ERR_Data* Data);
void Dump_MS2SC_ACK (TEDOStream* OStream, const TMS2SC_ACK_Data* Data);

#ifdef __cplusplus
	}
#endif

#endif

