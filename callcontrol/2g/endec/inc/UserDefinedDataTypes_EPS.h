/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __UserDefinedDataTypes_EPS_h
#define __UserDefinedDataTypes_EPS_h
/* ZZZ */

#include "ed_lib.h"
#include "ed_c_EPS.h"
#include "ed_user.h"
#include "endec_configs_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSBearerContextStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSBearerContextStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSBearerContextStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSBearerContextStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSBearerContextStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AdditionalUpdateResult".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AdditionalUpdateResult (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AdditionalUpdateResult* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AdditionalUpdateResult (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AdditionalUpdateResult* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsAdditionalUpdateType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsAdditionalUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsAdditionalUpdateType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsAdditionalUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsAdditionalUpdateType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSDetachType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSDetachType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSDetachType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSDetachType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSDetachType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSMobileIdentity_GUTI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity_GUTI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity_GUTI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity_GUTI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity_GUTI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSNetworkFeatureSupport".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSNetworkFeatureSupport* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSUpdateType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSUpdateType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSUpdateType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSUpdateType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSUpdateType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "KSIAndSequenceNumber".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_KSIAndSequenceNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_KSIAndSequenceNumber* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_KSIAndSequenceNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_KSIAndSequenceNumber* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NASKeySetIdentifier".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NASKeySetIdentifier (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NASKeySetIdentifier* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NASKeySetIdentifier (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NASKeySetIdentifier* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NASSecurityAlgorithms".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NASSecurityAlgorithms (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NASSecurityAlgorithms* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NASSecurityAlgorithms (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NASSecurityAlgorithms* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ExtendedEMMCause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ExtendedEMMCause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ExtendedEMMCause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ExtendedEMMCause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ExtendedEMMCause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TrackingAreaIdentity".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrackingAreaIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrackingAreaIdentity* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrackingAreaIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrackingAreaIdentity* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentityList_Type0".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type0 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type0* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type0 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type0* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentityList_Type1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentity_Type2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentity_Type2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentity_Type2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentity_Type2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentity_Type2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GUTIType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTIType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTIType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTIType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTIType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DataServiceType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DataServiceType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DataServiceType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DataServiceType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DataServiceType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PDNAddress".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDNAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDNAddress* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDNAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDNAddress* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsReAttemptIndicator".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsReAttemptIndicator (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsReAttemptIndicator* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsReAttemptIndicator (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsReAttemptIndicator* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PKMFAddress".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PKMFAddress (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PKMFAddress* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PKMFAddress (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PKMFAddress* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HeaderCompressionCfg".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HeaderCompressionCfg (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HeaderCompressionCfg* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HeaderCompressionCfg (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HeaderCompressionCfg* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HeaderCompressionCfgStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HeaderCompressionCfgStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HeaderCompressionCfgStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HeaderCompressionCfgStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HeaderCompressionCfgStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsLocationAreaId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLocationAreaId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLocationAreaId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLocationAreaId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLocationAreaId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMobileId_TMGI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId_TMGI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId_TMGI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId_TMGI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId_TMGI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMobileStationClassmark2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileStationClassmark2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileStationClassmark2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileStationClassmark2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileStationClassmark2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsPlmn".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPlmn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPlmn* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPlmn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPlmn* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMSNetworkFeatureSupport".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMSNetworkFeatureSupport (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMSNetworkFeatureSupport* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMSNetworkFeatureSupport (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMSNetworkFeatureSupport* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsNetwkName".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsNetwkName (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsNetwkName* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsNetwkName (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsNetwkName* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsTimeZoneAndTime".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTimeZoneAndTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTimeZoneAndTime* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTimeZoneAndTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTimeZoneAndTime* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsDaylightSavingTime".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDaylightSavingTime (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDaylightSavingTime* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDaylightSavingTime (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDaylightSavingTime* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsServCategory".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsServCategory (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsServCategory* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsServCategory (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsServCategory* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsTmsiStatus".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTmsiStatus (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTmsiStatus* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTmsiStatus (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTmsiStatus* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsDrxParam".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDrxParam (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDrxParam* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDrxParam (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDrxParam* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsVoiceDomainPreferenceAndUEsUsageSetting".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsVoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsVoiceDomainPreferenceAndUEsUsageSetting* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsNetworkResourceIdentifierContainer".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsNetworkResourceIdentifierContainer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsNetworkResourceIdentifierContainer* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsNetworkResourceIdentifierContainer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsNetworkResourceIdentifierContainer* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsExtendedDRXParameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsExtendedDRXParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsExtendedDRXParameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsExtendedDRXParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsExtendedDRXParameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsLlcServAccessPointId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLlcServAccessPointId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLlcServAccessPointId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLlcServAccessPointId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLlcServAccessPointId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsPacketFlowIdentifie".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPacketFlowIdentifie (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPacketFlowIdentifie* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPacketFlowIdentifie (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPacketFlowIdentifie* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsConnectivityType".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsConnectivityType (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsConnectivityType* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsConnectivityType (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsConnectivityType* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsWLANOffloadAcceptability".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsWLANOffloadAcceptability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsWLANOffloadAcceptability* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsWLANOffloadAcceptability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsWLANOffloadAcceptability* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsGprsTimer".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsGprsTimer2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsGprsTimer3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsGprsTimer3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsGprsTimer3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsGprsTimer3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsGprsTimer3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsDeviceProperties".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsDeviceProperties (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsDeviceProperties* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsDeviceProperties (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsDeviceProperties* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsCalledPartyBcdNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsCalledPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsCalledPartyBcdNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsCalledPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsCalledPartyBcdNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsCallingPartyBcdNum".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsCallingPartyBcdNum (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsCallingPartyBcdNum* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsCallingPartyBcdNum (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsCallingPartyBcdNum* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsProtocolCfgOpt".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfgOpt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfgOpt* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfgOpt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfgOpt* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentityList_TACS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_TACS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_TACS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_TACS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_TACS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentityList_Type2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList_Type2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList_Type2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList_Type2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList_Type2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PartialTrackingAreaIdentityList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PartialTrackingAreaIdentityList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PartialTrackingAreaIdentityList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PartialTrackingAreaIdentityList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PartialTrackingAreaIdentityList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsPlmnList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsPlmnList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsPlmnList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsPlmnList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsPlmnList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsEmergencyNumberList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsEmergencyNumberList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsEmergencyNumberList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsEmergencyNumberList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsEmergencyNumberList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsSupportedCodecList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsSupportedCodecList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsSupportedCodecList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsSupportedCodecList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsSupportedCodecList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsProtocolCfgList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfgList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfgList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfgList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfgList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSMobileIdentity_IMSI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity_IMSI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity_IMSI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity_IMSI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity_IMSI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPSMobileIdentity".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPSMobileIdentity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPSMobileIdentity* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPSMobileIdentity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPSMobileIdentity* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESMMessageUp".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESMMessageUp (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESMMessageUp* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESMMessageUp (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESMMessageUp* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESMMessageDn".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESMMessageDn (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESMMessageDn* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESMMessageDn (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESMMessageDn* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TrackingAreaIdentityList_Item".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TrackingAreaIdentityList_Item (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TrackingAreaIdentityList_Item* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TrackingAreaIdentityList_Item (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TrackingAreaIdentityList_Item* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RemoteUEContext_Identity".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext_Identity* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext_Identity* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RemoteUEContext_SingleContext".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext_SingleContext (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext_SingleContext* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext_SingleContext (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext_SingleContext* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RemoteUEContext".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RemoteUEContext (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RemoteUEContext* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RemoteUEContext (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RemoteUEContext* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMobileId_Identity".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId_Identity (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId_Identity* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId_Identity (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId_Identity* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMobileId".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMobileId (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMobileId* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMobileId (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMobileId* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsTBCDEmergencyNumber".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTBCDEmergencyNumber (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTBCDEmergencyNumber* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTBCDEmergencyNumber (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTBCDEmergencyNumber* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsTBCDArray".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTBCDArray (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTBCDArray* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTBCDArray (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTBCDArray* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsSupportedCodec".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsSupportedCodec (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsSupportedCodec* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsSupportedCodec (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsSupportedCodec* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsProtocolCfg".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsProtocolCfg (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsProtocolCfg* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsProtocolCfg (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsProtocolCfg* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsLinkedTi".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsLinkedTi (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsLinkedTi* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsLinkedTi (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsLinkedTi* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsTrafficFlowTemplate".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsTrafficFlowTemplate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsTrafficFlowTemplate* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsTrafficFlowTemplate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsTrafficFlowTemplate* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GenericTLV_EPS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_EPS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_EPS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_EPS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_EPS* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

