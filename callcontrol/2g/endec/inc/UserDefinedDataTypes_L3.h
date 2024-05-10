/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __UserDefinedDataTypes_L3_h
#define __UserDefinedDataTypes_L3_h
/* ZZZ */

#include "ed_lib.h"
#include "ed_c_L3.h"
#include "ed_user.h"
#include "endec_configs_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LocationAreaId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LocationAreaId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LocationAreaId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LocationAreaId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LocationAreaId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MobileId_TMGI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId_TMGI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId_TMGI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId_TMGI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId_TMGI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MobileStationClassmark1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileStationClassmark1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileStationClassmark1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileStationClassmark1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileStationClassmark1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MobileStationClassmark2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileStationClassmark2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileStationClassmark2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileStationClassmark2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileStationClassmark2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PdAndSapiCcbs".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PdAndSapiCcbs (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PdAndSapiCcbs* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PdAndSapiCcbs (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PdAndSapiCcbs* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PriorityLevel".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PriorityLevel (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PriorityLevel* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PriorityLevel (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PriorityLevel* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Plmn".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Plmn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Plmn* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Plmn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Plmn* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MSNetworkFeatureSupport".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MSNetworkFeatureSupport* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LocationUpdatingType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LocationUpdatingType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LocationUpdatingType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LocationUpdatingType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LocationUpdatingType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NetwkName".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkName (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkName* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkName (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkName* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RejectCause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RejectCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RejectCause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RejectCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RejectCause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TimeZoneAndTime".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TimeZoneAndTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TimeZoneAndTime* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TimeZoneAndTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TimeZoneAndTime* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DaylightSavingTime".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DaylightSavingTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DaylightSavingTime* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DaylightSavingTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DaylightSavingTime* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AdditionalUpdateParameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateParameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateParameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AuxiliaryStates".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AuxiliaryStates (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AuxiliaryStates* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AuxiliaryStates (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AuxiliaryStates* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CallControlCapabil".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallControlCapabil (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallControlCapabil* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallControlCapabil (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallControlCapabil* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CallState".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallState (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallState* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallState (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallState* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CalledPartySubaddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CalledPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CalledPartySubaddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CalledPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CalledPartySubaddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CallingPartySubaddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallingPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallingPartySubaddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallingPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallingPartySubaddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ConnSubaddres".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ConnSubaddres (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ConnSubaddres* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ConnSubaddres (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ConnSubaddres* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "KeypadFacility".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_KeypadFacility (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_KeypadFacility* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_KeypadFacility (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_KeypadFacility* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NotifInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NotifInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NotifInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NotifInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NotifInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ProgrInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ProgrInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ProgrInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ProgrInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ProgrInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RecallType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RecallType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RecallType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RecallType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RecallType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RedirPartySubaddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RedirPartySubaddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RedirPartySubaddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RedirPartySubaddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RedirPartySubaddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AlertingPattern".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AlertingPattern (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AlertingPattern* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AlertingPattern (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AlertingPattern* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AllowedActionsCcbs".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AllowedActionsCcbs (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AllowedActionsCcbs* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AllowedActionsCcbs (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AllowedActionsCcbs* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NetwkCallControlCapabil".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkCallControlCapabil (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkCallControlCapabil* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkCallControlCapabil (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkCallControlCapabil* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ServCategory".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ServCategory (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ServCategory* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ServCategory (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ServCategory* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AdditionalUpdateType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AttachResult".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AttachResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AttachResult* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AttachResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AttachResult* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AttachType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AttachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AttachType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AttachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AttachType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IntegrityProtectionAlgorithm".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IntegrityProtectionAlgorithm (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IntegrityProtectionAlgorithm* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IntegrityProtectionAlgorithm (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IntegrityProtectionAlgorithm* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TmsiStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TmsiStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TmsiStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TmsiStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TmsiStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DetachType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DetachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DetachType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DetachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DetachType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DrxParam".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DrxParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DrxParam* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DrxParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DrxParam* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RoutingAreaIdenti".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RoutingAreaIdenti (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RoutingAreaIdenti* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RoutingAreaIdenti (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RoutingAreaIdenti* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RoutingAreaIdenti2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RoutingAreaIdenti2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RoutingAreaIdenti2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RoutingAreaIdenti2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RoutingAreaIdenti2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UpdateType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UpdateType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UpdateType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSLCSCapabilit".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSLCSCapabilit (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSLCSCapabilit* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSLCSCapabilit (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSLCSCapabilit* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NetworkFeatureSupport".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetworkFeatureSupport* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AdditionalNetworkFeatureSupport".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalNetworkFeatureSupport* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RequestedMSInformation".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RequestedMSInformation (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RequestedMSInformation* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RequestedMSInformation (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RequestedMSInformation* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VoiceDomainPreferenceAndUEsUsageSetting".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VoiceDomainPreferenceAndUEsUsageSetting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VoiceDomainPreferenceAndUEsUsageSetting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PTMSI_Type".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PTMSI_Type (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PTMSI_Type* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PTMSI_Type (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PTMSI_Type* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NetworkResourceIdContainer".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetworkResourceIdContainer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetworkResourceIdContainer* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetworkResourceIdContainer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetworkResourceIdContainer* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ExtendedDRXParameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtendedDRXParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtendedDRXParameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtendedDRXParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtendedDRXParameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NetwkServAccessPointId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NetwkServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NetwkServAccessPointId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NetwkServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NetwkServAccessPointId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PacketDataProtocolAddr".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PacketDataProtocolAddr (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PacketDataProtocolAddr* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PacketDataProtocolAddr (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PacketDataProtocolAddr* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "QualityOfServ".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_QualityOfServ (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_QualityOfServ* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_QualityOfServ (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_QualityOfServ* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ReAttemptIndicator".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ReAttemptIndicator (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ReAttemptIndicator* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ReAttemptIndicator (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ReAttemptIndicator* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMCause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMCause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMCause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LlcServAccessPointId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LlcServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LlcServAccessPointId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LlcServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LlcServAccessPointId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TearDownInd".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TearDownInd (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TearDownInd* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TearDownInd (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TearDownInd* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PacketFlowIdentifie".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PacketFlowIdentifie (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PacketFlowIdentifie* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PacketFlowIdentifie (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PacketFlowIdentifie* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TempMobileNumbers".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TempMobileNumbers (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TempMobileNumbers* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TempMobileNumbers (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TempMobileNumbers* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TempMobileGroupId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TempMobileGroupId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TempMobileGroupId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TempMobileGroupId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TempMobileGroupId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMSBearerCapabilities".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMSBearerCapabilities (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMSBearerCapabilities* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMSBearerCapabilities (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMSBearerCapabilities* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "WLANOffloadAcceptability".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_WLANOffloadAcceptability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_WLANOffloadAcceptability* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_WLANOffloadAcceptability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_WLANOffloadAcceptability* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GprsTimer".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GprsTimer2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GprsTimer3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GprsTimer3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GprsTimer3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GprsTimer3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GprsTimer3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UplinkDataStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UplinkDataStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UplinkDataStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UplinkDataStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UplinkDataStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DeviceProperties".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DeviceProperties (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DeviceProperties* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DeviceProperties (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DeviceProperties* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ASCII".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ASCII (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ASCII* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ASCII (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ASCII* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "BackupBearerCapability".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BackupBearerCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BackupBearerCapability* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BackupBearerCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BackupBearerCapability* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "BearerCpblty".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BearerCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BearerCpblty* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BearerCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BearerCpblty* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CalledPartyBcdNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CalledPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CalledPartyBcdNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CalledPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CalledPartyBcdNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CallingPartyBcdNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CallingPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CallingPartyBcdNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CallingPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CallingPartyBcdNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Cause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Cause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Cause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Cause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Cause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ConnNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ConnNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ConnNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ConnNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ConnNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HighLayerCpbility".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HighLayerCpbility (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HighLayerCpbility* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HighLayerCpbility (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HighLayerCpbility* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RedirPartyBcdNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RedirPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RedirPartyBcdNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RedirPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RedirPartyBcdNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PlmnList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PlmnList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PlmnList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PlmnList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PlmnList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EmergencyNumberList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EmergencyNumberList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EmergencyNumberList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EmergencyNumberList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EmergencyNumberList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SupportedCodecList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SupportedCodecList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SupportedCodecList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SupportedCodecList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SupportedCodecList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MobileId_Identity".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId_Identity* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId_Identity* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MobileId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MobileId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MobileId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MobileId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MobileId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TBCDEmergencyNumber".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TBCDEmergencyNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TBCDEmergencyNumber* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TBCDEmergencyNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TBCDEmergencyNumber* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TBCDArray".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TBCDArray (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TBCDArray* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TBCDArray (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TBCDArray* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SupportedCodec".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SupportedCodec (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SupportedCodec* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SupportedCodec (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SupportedCodec* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LinkedTi".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LinkedTi (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LinkedTi* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LinkedTi (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LinkedTi* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TrafficFlowTemplate".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrafficFlowTemplate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrafficFlowTemplate* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrafficFlowTemplate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrafficFlowTemplate* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PdpContextStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PdpContextStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PdpContextStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PdpContextStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PdpContextStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GenericTLV_L3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_L3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_L3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_L3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_L3* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

