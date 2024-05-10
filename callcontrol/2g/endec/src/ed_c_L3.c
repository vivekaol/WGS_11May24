/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_L3.h"
#include "ed_lib.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


/* Free function for struct c_ServCategory */
void FREE_c_ServCategory (c_ServCategory* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_TBCDArray */
void FREE_c_TBCDArray (c_TBCDArray* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_TBCDArray'. Existing items are not changed. */
int SETITEMS_c_TBCDArray (c_TBCDArray* sequence, int desiredItems)
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

/* Free function for struct c_SupportedCodec */
void FREE_c_SupportedCodec (c_SupportedCodec* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->CodecBitmap.value != NULL) {
		EDFree (sp->CodecBitmap.value);
		sp->CodecBitmap.value = NULL;
	}
	sp->CodecBitmap.usedBits = 0;

}

/* Free function for struct c_MobileId_TMGI */
void FREE_c_MobileId_TMGI (c_MobileId_TMGI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_Plmn */
void FREE_c_Plmn (c_Plmn* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TempMobileNumbers */
void FREE_c_TempMobileNumbers (c_TempMobileNumbers* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_MobileId_Identity_IdentityDigit */
void FREE_c_MobileId_Identity_IdentityDigit (c_MobileId_Identity_IdentityDigit* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_MobileId_Identity */
void FREE_c_MobileId_Identity (c_MobileId_Identity* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->IdentityDigit.data) {EDFree (sp->IdentityDigit.data); sp->IdentityDigit.data = NULL; sp->IdentityDigit.allocatedItems=0; /*FR02A*/}
	if (sp->IdentityDigit.data___LOCATOR) {EDFree (sp->IdentityDigit.data___LOCATOR); sp->IdentityDigit.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_TBCDEmergencyNumber_Numbers */
void FREE_c_TBCDEmergencyNumber_Numbers (c_TBCDEmergencyNumber_Numbers* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TBCDEmergencyNumber */
void FREE_c_TBCDEmergencyNumber (c_TBCDEmergencyNumber* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_ServCategory (&(sp->ServiceCategory));
	if (sp->Numbers.data) {EDFree (sp->Numbers.data); sp->Numbers.data = NULL; sp->Numbers.allocatedItems=0; /*FR02A*/}
	if (sp->Numbers.data___LOCATOR) {EDFree (sp->Numbers.data___LOCATOR); sp->Numbers.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_CallControlCapabil */
void FREE_c_CallControlCapabil (c_CallControlCapabil* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CalledPartySubaddr */
void FREE_c_CalledPartySubaddr (c_CalledPartySubaddr* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->SubaddressInformation.value != NULL) {
		EDFree (sp->SubaddressInformation.value);
		sp->SubaddressInformation.value = NULL;
	}
	sp->SubaddressInformation.usedBits = 0;

}

/* Free function for struct c_CallingPartySubaddr */
void FREE_c_CallingPartySubaddr (c_CallingPartySubaddr* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->SubaddressInformation.value != NULL) {
		EDFree (sp->SubaddressInformation.value);
		sp->SubaddressInformation.value = NULL;
	}
	sp->SubaddressInformation.usedBits = 0;

}

/* Free function for struct c_BearerCpblty */
void FREE_c_BearerCpblty (c_BearerCpblty* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CalledPartyBcdNum */
void FREE_c_CalledPartyBcdNum (c_CalledPartyBcdNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TBCDArray (&(sp->Number));

}

/* Free function for struct c_HighLayerCpbility */
void FREE_c_HighLayerCpbility (c_HighLayerCpbility* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_SupportedCodecList */
void FREE_c_SupportedCodecList (c_SupportedCodecList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_SupportedCodec (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_SupportedCodecList'. Existing items are not changed. */
int SETITEMS_c_SupportedCodecList (c_SupportedCodecList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_SupportedCodec** tmp;
		tmp = (c_SupportedCodec**)EDAlloc (sizeof (c_SupportedCodec*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_SupportedCodec*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_SupportedCodec*)EDAlloc (sizeof (c_SupportedCodec));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_SupportedCodec (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_SupportedCodec (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_LocationAreaId */
void FREE_c_LocationAreaId (c_LocationAreaId* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MobileStationClassmark1 */
void FREE_c_MobileStationClassmark1 (c_MobileStationClassmark1* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MobileStationClassmark2 */
void FREE_c_MobileStationClassmark2 (c_MobileStationClassmark2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PdAndSapiCcbs */
void FREE_c_PdAndSapiCcbs (c_PdAndSapiCcbs* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PriorityLevel */
void FREE_c_PriorityLevel (c_PriorityLevel* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MSNetworkFeatureSupport */
void FREE_c_MSNetworkFeatureSupport (c_MSNetworkFeatureSupport* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_LocationUpdatingType */
void FREE_c_LocationUpdatingType (c_LocationUpdatingType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NetwkName */
void FREE_c_NetwkName (c_NetwkName* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TextString.value != NULL) {
		EDFree (sp->TextString.value);
		sp->TextString.value = NULL;
	}
	sp->TextString.usedBits = 0;

}

/* Free function for struct c_RejectCause */
void FREE_c_RejectCause (c_RejectCause* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TimeZoneAndTime */
void FREE_c_TimeZoneAndTime (c_TimeZoneAndTime* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DaylightSavingTime */
void FREE_c_DaylightSavingTime (c_DaylightSavingTime* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AdditionalUpdateParameters */
void FREE_c_AdditionalUpdateParameters (c_AdditionalUpdateParameters* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AuxiliaryStates */
void FREE_c_AuxiliaryStates (c_AuxiliaryStates* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CallState */
void FREE_c_CallState (c_CallState* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ConnSubaddres */
void FREE_c_ConnSubaddres (c_ConnSubaddres* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->SubaddressInformation.value != NULL) {
		EDFree (sp->SubaddressInformation.value);
		sp->SubaddressInformation.value = NULL;
	}
	sp->SubaddressInformation.usedBits = 0;

}

/* Free function for struct c_KeypadFacility */
void FREE_c_KeypadFacility (c_KeypadFacility* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NotifInd */
void FREE_c_NotifInd (c_NotifInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ProgrInd */
void FREE_c_ProgrInd (c_ProgrInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RecallType */
void FREE_c_RecallType (c_RecallType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RedirPartySubaddr */
void FREE_c_RedirPartySubaddr (c_RedirPartySubaddr* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->SubaddressInformation.value != NULL) {
		EDFree (sp->SubaddressInformation.value);
		sp->SubaddressInformation.value = NULL;
	}
	sp->SubaddressInformation.usedBits = 0;

}

/* Free function for struct c_AlertingPattern */
void FREE_c_AlertingPattern (c_AlertingPattern* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AllowedActionsCcbs */
void FREE_c_AllowedActionsCcbs (c_AllowedActionsCcbs* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NetwkCallControlCapabil */
void FREE_c_NetwkCallControlCapabil (c_NetwkCallControlCapabil* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AdditionalUpdateType */
void FREE_c_AdditionalUpdateType (c_AdditionalUpdateType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AttachResult */
void FREE_c_AttachResult (c_AttachResult* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AttachType */
void FREE_c_AttachType (c_AttachType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_IntegrityProtectionAlgorithm */
void FREE_c_IntegrityProtectionAlgorithm (c_IntegrityProtectionAlgorithm* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TmsiStatus */
void FREE_c_TmsiStatus (c_TmsiStatus* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DetachType */
void FREE_c_DetachType (c_DetachType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DrxParam */
void FREE_c_DrxParam (c_DrxParam* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RoutingAreaIdenti */
void FREE_c_RoutingAreaIdenti (c_RoutingAreaIdenti* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RoutingAreaIdenti2 */
void FREE_c_RoutingAreaIdenti2 (c_RoutingAreaIdenti2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UpdateType */
void FREE_c_UpdateType (c_UpdateType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PSLCSCapabilit */
void FREE_c_PSLCSCapabilit (c_PSLCSCapabilit* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NetworkFeatureSupport */
void FREE_c_NetworkFeatureSupport (c_NetworkFeatureSupport* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AdditionalNetworkFeatureSupport */
void FREE_c_AdditionalNetworkFeatureSupport (c_AdditionalNetworkFeatureSupport* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RequestedMSInformation */
void FREE_c_RequestedMSInformation (c_RequestedMSInformation* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_VoiceDomainPreferenceAndUEsUsageSetting */
void FREE_c_VoiceDomainPreferenceAndUEsUsageSetting (c_VoiceDomainPreferenceAndUEsUsageSetting* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PTMSI_Type */
void FREE_c_PTMSI_Type (c_PTMSI_Type* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NetworkResourceIdContainer */
void FREE_c_NetworkResourceIdContainer (c_NetworkResourceIdContainer* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ExtendedDRXParameters */
void FREE_c_ExtendedDRXParameters (c_ExtendedDRXParameters* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NetwkServAccessPointId */
void FREE_c_NetwkServAccessPointId (c_NetwkServAccessPointId* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PacketDataProtocolAddr */
void FREE_c_PacketDataProtocolAddr (c_PacketDataProtocolAddr* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AddressInformation.value != NULL) {
		EDFree (sp->AddressInformation.value);
		sp->AddressInformation.value = NULL;
	}
	sp->AddressInformation.usedBits = 0;

}

/* Free function for struct c_QualityOfServ */
void FREE_c_QualityOfServ (c_QualityOfServ* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ReAttemptIndicator */
void FREE_c_ReAttemptIndicator (c_ReAttemptIndicator* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SMCause */
void FREE_c_SMCause (c_SMCause* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_LlcServAccessPointId */
void FREE_c_LlcServAccessPointId (c_LlcServAccessPointId* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TearDownInd */
void FREE_c_TearDownInd (c_TearDownInd* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PacketFlowIdentifie */
void FREE_c_PacketFlowIdentifie (c_PacketFlowIdentifie* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TempMobileGroupId */
void FREE_c_TempMobileGroupId (c_TempMobileGroupId* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TempMobileNumbers (&(sp->Numbers));

}

/* Free function for struct c_MBMSBearerCapabilities */
void FREE_c_MBMSBearerCapabilities (c_MBMSBearerCapabilities* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_WLANOffloadAcceptability */
void FREE_c_WLANOffloadAcceptability (c_WLANOffloadAcceptability* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_GprsTimer */
void FREE_c_GprsTimer (c_GprsTimer* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_GprsTimer2 */
void FREE_c_GprsTimer2 (c_GprsTimer2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_GprsTimer3 */
void FREE_c_GprsTimer3 (c_GprsTimer3* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UplinkDataStatus */
void FREE_c_UplinkDataStatus (c_UplinkDataStatus* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DeviceProperties */
void FREE_c_DeviceProperties (c_DeviceProperties* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ASCII */
void FREE_c_ASCII (c_ASCII* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->text.value != NULL) {
		EDFree (sp->text.value);
		sp->text.value = NULL;
	}
	sp->text.usedBits = 0;

}

/* Free function for struct c_BackupBearerCapability */
void FREE_c_BackupBearerCapability (c_BackupBearerCapability* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CallingPartyBcdNum */
void FREE_c_CallingPartyBcdNum (c_CallingPartyBcdNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TBCDArray (&(sp->Number));

}

/* Free function for struct c_Cause */
void FREE_c_Cause (c_Cause* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->diagnostic.value != NULL) {
		EDFree (sp->diagnostic.value);
		sp->diagnostic.value = NULL;
	}
	sp->diagnostic.usedBits = 0;

}

/* Free function for struct c_ConnNum */
void FREE_c_ConnNum (c_ConnNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TBCDArray (&(sp->Number));

}

/* Free function for struct c_RedirPartyBcdNum */
void FREE_c_RedirPartyBcdNum (c_RedirPartyBcdNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TBCDArray (&(sp->Number));

}

/* Free function for variable-sized sequence c_PlmnList */
void FREE_c_PlmnList (c_PlmnList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_Plmn (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_PlmnList'. Existing items are not changed. */
int SETITEMS_c_PlmnList (c_PlmnList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_Plmn** tmp;
		tmp = (c_Plmn**)EDAlloc (sizeof (c_Plmn*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_Plmn*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_Plmn*)EDAlloc (sizeof (c_Plmn));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_Plmn (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_Plmn (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_EmergencyNumberList */
void FREE_c_EmergencyNumberList (c_EmergencyNumberList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_TBCDEmergencyNumber (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_EmergencyNumberList'. Existing items are not changed. */
int SETITEMS_c_EmergencyNumberList (c_EmergencyNumberList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TBCDEmergencyNumber** tmp;
		tmp = (c_TBCDEmergencyNumber**)EDAlloc (sizeof (c_TBCDEmergencyNumber*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TBCDEmergencyNumber*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_TBCDEmergencyNumber*)EDAlloc (sizeof (c_TBCDEmergencyNumber));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_TBCDEmergencyNumber (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_TBCDEmergencyNumber (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_Classmark3Value */
void FREE_c_Classmark3Value (c_Classmark3Value* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_ReceiveNPduNumbersList_sapi */
void FREE_c_ReceiveNPduNumbersList_sapi (c_ReceiveNPduNumbersList_sapi* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for variable-sized sequence c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value */
void FREE_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value (c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_ReceiveNPduNumbersList */
void FREE_c_ReceiveNPduNumbersList (c_ReceiveNPduNumbersList* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->sapi.data) {EDFree (sp->sapi.data); sp->sapi.data = NULL; sp->sapi.allocatedItems=0; /*FR02A*/}
	if (sp->sapi.data___LOCATOR) {EDFree (sp->sapi.data___LOCATOR); sp->sapi.data___LOCATOR = NULL; /*FR02AL*/}
	if (sp->Receive_N_PDU_Number_value.data) {EDFree (sp->Receive_N_PDU_Number_value.data); sp->Receive_N_PDU_Number_value.data = NULL; sp->Receive_N_PDU_Number_value.allocatedItems=0; /*FR02A*/}
	if (sp->Receive_N_PDU_Number_value.data___LOCATOR) {EDFree (sp->Receive_N_PDU_Number_value.data___LOCATOR); sp->Receive_N_PDU_Number_value.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_MsNetwkCpblty */
void FREE_c_MsNetwkCpblty (c_MsNetwkCpblty* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for variable-sized sequence c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value* sp) {
	int i, i0;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->Access_capabilities_Present) {
			if (sp->data[i]->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.A5_bits_Present) {
				EDFree (sp->data[i]->Access_capabilities->Access_capabilities.A5_bits);
				sp->data[i]->Access_capabilities->Access_capabilities.A5_bits = NULL;
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.ES_IND_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.PS_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.VGCS_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.VBS_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
				}
				EDFree (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability);
				sp->data[i]->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Length_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
				if (sp->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
				}
				EDFree (sp->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
				sp->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
				if (sp->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
				}
				if (sp->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
				}
				EDFree (sp->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability);
				sp->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
			}
			if (sp->data[i]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
			}
			EDFree (sp->data[i]->Access_capabilities);
			sp->data[i]->Access_capabilities = NULL;
		}
		if (sp->data[i]->Length_Present) {
		}
		for (i0=0; i0<sp->data[i]->Additional_access_technologies.items; i0++) {
			EDFree (sp->data[i]->Additional_access_technologies.data[i0]);
			sp->data[i]->Additional_access_technologies.data[i0] = NULL;
		}
		if (sp->data[i]->Additional_access_technologies.data) {EDFree (sp->data[i]->Additional_access_technologies.data); sp->data[i]->Additional_access_technologies.data = NULL; sp->data[i]->Additional_access_technologies.allocatedItems=0; /*FR02A*/}
		if (sp->data[i]->Additional_access_technologies.data___LOCATOR) {EDFree (sp->data[i]->Additional_access_technologies.data___LOCATOR); sp->data[i]->Additional_access_technologies.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_MsRadioAccessCpblty */
void FREE_c_MsRadioAccessCpblty (c_MsRadioAccessCpblty* sp) {
	int i0;
	int i1;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->MS_RA_capability_value_part.MS_RA_capability_value.items; i0++) {
		if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities_Present) {
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits_Present) {
				EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits);
				sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits = NULL;
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.ES_IND_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.PS_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.VGCS_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.VBS_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
				}
				EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability);
				sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Length_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
				}
				EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
				sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
				}
				if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
				}
				EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability);
				sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
			}
			if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
			}
			EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities);
			sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Access_capabilities = NULL;
		}
		if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Length_Present) {
		}
		for (i1=0; i1<sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.items; i1++) {
			EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data[i1]);
			sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data[i1] = NULL;
		}
		if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data) {EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data); sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data = NULL; sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.allocatedItems=0; /*FR02A*/}
		if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR) {EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR); sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0]);
		sp->MS_RA_capability_value_part.MS_RA_capability_value.data[i0] = NULL;
	}
	if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data) {EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data); sp->MS_RA_capability_value_part.MS_RA_capability_value.data = NULL; sp->MS_RA_capability_value_part.MS_RA_capability_value.allocatedItems=0; /*FR02A*/}
	if (sp->MS_RA_capability_value_part.MS_RA_capability_value.data___LOCATOR) {EDFree (sp->MS_RA_capability_value_part.MS_RA_capability_value.data___LOCATOR); sp->MS_RA_capability_value_part.MS_RA_capability_value.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_ProtocolCfgOpt_ProtocolCfgs */
void FREE_c_ProtocolCfgOpt_ProtocolCfgs (c_ProtocolCfgOpt_ProtocolCfgs* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->Contents.value != NULL) {
			EDFree (sp->data[i]->Contents.value);
			sp->data[i]->Contents.value = NULL;
		}
		sp->data[i]->Contents.usedBits = 0;
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for variable-sized sequence c_ProtocolCfgOpt_ContainerCfgs */
void FREE_c_ProtocolCfgOpt_ContainerCfgs (c_ProtocolCfgOpt_ContainerCfgs* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->Contents.value != NULL) {
			EDFree (sp->data[i]->Contents.value);
			sp->data[i]->Contents.value = NULL;
		}
		sp->data[i]->Contents.usedBits = 0;
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_ProtocolCfgOpt */
void FREE_c_ProtocolCfgOpt (c_ProtocolCfgOpt* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->ProtocolCfgs.items; i0++) {
		if (sp->ProtocolCfgs.data[i0]->Contents.value != NULL) {
			EDFree (sp->ProtocolCfgs.data[i0]->Contents.value);
			sp->ProtocolCfgs.data[i0]->Contents.value = NULL;
		}
		sp->ProtocolCfgs.data[i0]->Contents.usedBits = 0;
		EDFree (sp->ProtocolCfgs.data[i0]);
		sp->ProtocolCfgs.data[i0] = NULL;
	}
	if (sp->ProtocolCfgs.data) {EDFree (sp->ProtocolCfgs.data); sp->ProtocolCfgs.data = NULL; sp->ProtocolCfgs.allocatedItems=0; /*FR02A*/}
	if (sp->ProtocolCfgs.data___LOCATOR) {EDFree (sp->ProtocolCfgs.data___LOCATOR); sp->ProtocolCfgs.data___LOCATOR = NULL; /*FR02AL*/}
	for (i0=0; i0<sp->ContainerCfgs.items; i0++) {
		if (sp->ContainerCfgs.data[i0]->Contents.value != NULL) {
			EDFree (sp->ContainerCfgs.data[i0]->Contents.value);
			sp->ContainerCfgs.data[i0]->Contents.value = NULL;
		}
		sp->ContainerCfgs.data[i0]->Contents.usedBits = 0;
		EDFree (sp->ContainerCfgs.data[i0]);
		sp->ContainerCfgs.data[i0] = NULL;
	}
	if (sp->ContainerCfgs.data) {EDFree (sp->ContainerCfgs.data); sp->ContainerCfgs.data = NULL; sp->ContainerCfgs.allocatedItems=0; /*FR02A*/}
	if (sp->ContainerCfgs.data___LOCATOR) {EDFree (sp->ContainerCfgs.data___LOCATOR); sp->ContainerCfgs.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for union c_MobileId */
void FREE_c_MobileId (c_MobileId* sp) {
	switch (sp->Present) {
		case U_c_MobileId_Identity: {
			FREE_c_MobileId_Identity (sp->u.Identity);
			EDFree (sp->u.Identity);

			break;
		}
		case U_c_MobileId_TMGI: {
			FREE_c_MobileId_TMGI (sp->u.TMGI);
			EDFree (sp->u.TMGI);

			break;
		}

		default:;
	}
	sp->Present = U_c_MobileId_NONE;
}

/* Set-present function for c_MobileId LEVEL = -1 */
int GLOB_SETPRESENT_c_MobileId (c_MobileId* sp, TPRESENT_c_MobileId toBeSetPresent) 
{
	FREE_c_MobileId (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_MobileId_Identity: {
			sp->u.Identity = (c_MobileId_Identity*)EDAlloc (sizeof (c_MobileId_Identity));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Identity)
			INIT_c_MobileId_Identity (sp->u.Identity);

			break;
		}
		case U_c_MobileId_TMGI: {
			sp->u.TMGI = (c_MobileId_TMGI*)EDAlloc (sizeof (c_MobileId_TMGI));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.TMGI)
			INIT_c_MobileId_TMGI (sp->u.TMGI);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_LinkedTi */
void FREE_c_LinkedTi (c_LinkedTi* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_TrafficFlowTemplate_PacketFilters_data_FilterContents */
void FREE_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (c_TrafficFlowTemplate_PacketFilters_data_FilterContents* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->ComponentData.value != NULL) {
			EDFree (sp->data[i]->ComponentData.value);
			sp->data[i]->ComponentData.value = NULL;
		}
		sp->data[i]->ComponentData.usedBits = 0;
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for variable-sized sequence c_TrafficFlowTemplate_PacketFilters */
void FREE_c_TrafficFlowTemplate_PacketFilters (c_TrafficFlowTemplate_PacketFilters* sp) {
	int i, i0;
	for (i=0; i<sp->items; i++) {
		for (i0=0; i0<sp->data[i]->FilterContents.items; i0++) {
			if (sp->data[i]->FilterContents.data[i0]->ComponentData.value != NULL) {
				EDFree (sp->data[i]->FilterContents.data[i0]->ComponentData.value);
				sp->data[i]->FilterContents.data[i0]->ComponentData.value = NULL;
			}
			sp->data[i]->FilterContents.data[i0]->ComponentData.usedBits = 0;
			EDFree (sp->data[i]->FilterContents.data[i0]);
			sp->data[i]->FilterContents.data[i0] = NULL;
		}
		if (sp->data[i]->FilterContents.data) {EDFree (sp->data[i]->FilterContents.data); sp->data[i]->FilterContents.data = NULL; sp->data[i]->FilterContents.allocatedItems=0; /*FR02A*/}
		if (sp->data[i]->FilterContents.data___LOCATOR) {EDFree (sp->data[i]->FilterContents.data___LOCATOR); sp->data[i]->FilterContents.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for variable-sized sequence c_TrafficFlowTemplate_PacketParameters */
void FREE_c_TrafficFlowTemplate_PacketParameters (c_TrafficFlowTemplate_PacketParameters* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->Contents.value != NULL) {
			EDFree (sp->data[i]->Contents.value);
			sp->data[i]->Contents.value = NULL;
		}
		sp->data[i]->Contents.usedBits = 0;
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_TrafficFlowTemplate */
void FREE_c_TrafficFlowTemplate (c_TrafficFlowTemplate* sp) {
	int i0;
	int i1;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->PacketFilters.items; i0++) {
		for (i1=0; i1<sp->PacketFilters.data[i0]->FilterContents.items; i1++) {
			if (sp->PacketFilters.data[i0]->FilterContents.data[i1]->ComponentData.value != NULL) {
				EDFree (sp->PacketFilters.data[i0]->FilterContents.data[i1]->ComponentData.value);
				sp->PacketFilters.data[i0]->FilterContents.data[i1]->ComponentData.value = NULL;
			}
			sp->PacketFilters.data[i0]->FilterContents.data[i1]->ComponentData.usedBits = 0;
			EDFree (sp->PacketFilters.data[i0]->FilterContents.data[i1]);
			sp->PacketFilters.data[i0]->FilterContents.data[i1] = NULL;
		}
		if (sp->PacketFilters.data[i0]->FilterContents.data) {EDFree (sp->PacketFilters.data[i0]->FilterContents.data); sp->PacketFilters.data[i0]->FilterContents.data = NULL; sp->PacketFilters.data[i0]->FilterContents.allocatedItems=0; /*FR02A*/}
		if (sp->PacketFilters.data[i0]->FilterContents.data___LOCATOR) {EDFree (sp->PacketFilters.data[i0]->FilterContents.data___LOCATOR); sp->PacketFilters.data[i0]->FilterContents.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->PacketFilters.data[i0]);
		sp->PacketFilters.data[i0] = NULL;
	}
	if (sp->PacketFilters.data) {EDFree (sp->PacketFilters.data); sp->PacketFilters.data = NULL; sp->PacketFilters.allocatedItems=0; /*FR02A*/}
	if (sp->PacketFilters.data___LOCATOR) {EDFree (sp->PacketFilters.data___LOCATOR); sp->PacketFilters.data___LOCATOR = NULL; /*FR02AL*/}
	for (i0=0; i0<sp->PacketParameters.items; i0++) {
		if (sp->PacketParameters.data[i0]->Contents.value != NULL) {
			EDFree (sp->PacketParameters.data[i0]->Contents.value);
			sp->PacketParameters.data[i0]->Contents.value = NULL;
		}
		sp->PacketParameters.data[i0]->Contents.usedBits = 0;
		EDFree (sp->PacketParameters.data[i0]);
		sp->PacketParameters.data[i0] = NULL;
	}
	if (sp->PacketParameters.data) {EDFree (sp->PacketParameters.data); sp->PacketParameters.data = NULL; sp->PacketParameters.allocatedItems=0; /*FR02A*/}
	if (sp->PacketParameters.data___LOCATOR) {EDFree (sp->PacketParameters.data___LOCATOR); sp->PacketParameters.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_PdpContextStatus */
void FREE_c_PdpContextStatus (c_PdpContextStatus* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_PdpContextStatus'. Existing items are not changed. */
int SETITEMS_c_PdpContextStatus (c_PdpContextStatus* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_BOOLEAN* tmp;
		tmp = (ED_BOOLEAN*)EDAlloc (sizeof (ED_BOOLEAN) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_BOOLEAN) * (size_t)sequence->items);
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

/* Free function for struct c_SETUP_UP */
void FREE_c_SETUP_UP (c_SETUP_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_BearerCpblty (&(sp->BearerCpblty1));
	if (sp->BearerCpblty2_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
		sp->BearerCpblty2_Present = ED_FALSE;
	}
	if (sp->FacilitySimpleRecallAlignment_Present) {
		if (sp->FacilitySimpleRecallAlignment->value != NULL) {
			EDFree (sp->FacilitySimpleRecallAlignment->value);
			sp->FacilitySimpleRecallAlignment->value = NULL;
		}
		sp->FacilitySimpleRecallAlignment->usedBits = 0;
		EDFree (sp->FacilitySimpleRecallAlignment);
		sp->FacilitySimpleRecallAlignment_Present = ED_FALSE;
	}
	if (sp->CallingPartySubAddr_Present) {
		FREE_c_CallingPartySubaddr (sp->CallingPartySubAddr);
		EDFree (sp->CallingPartySubAddr);
		sp->CallingPartySubAddr_Present = ED_FALSE;
	}
	FREE_c_CalledPartyBcdNum (&(sp->CalledPartyBcdNum));
	if (sp->CalledPartySubAddr_Present) {
		FREE_c_CalledPartySubaddr (sp->CalledPartySubAddr);
		EDFree (sp->CalledPartySubAddr);
		sp->CalledPartySubAddr_Present = ED_FALSE;
	}
	if (sp->LowLayerCpbilityI_Present) {
		if (sp->LowLayerCpbilityI->value != NULL) {
			EDFree (sp->LowLayerCpbilityI->value);
			sp->LowLayerCpbilityI->value = NULL;
		}
		sp->LowLayerCpbilityI->usedBits = 0;
		EDFree (sp->LowLayerCpbilityI);
		sp->LowLayerCpbilityI_Present = ED_FALSE;
	}
	if (sp->LowLayerCpbilityIi_Present) {
		if (sp->LowLayerCpbilityIi->value != NULL) {
			EDFree (sp->LowLayerCpbilityIi->value);
			sp->LowLayerCpbilityIi->value = NULL;
		}
		sp->LowLayerCpbilityIi->usedBits = 0;
		EDFree (sp->LowLayerCpbilityIi);
		sp->LowLayerCpbilityIi_Present = ED_FALSE;
	}
	if (sp->HighLayerCpbilityI_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityI);
		EDFree (sp->HighLayerCpbilityI);
		sp->HighLayerCpbilityI_Present = ED_FALSE;
	}
	if (sp->HighLayerCpbilityIi_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
		EDFree (sp->HighLayerCpbilityIi);
		sp->HighLayerCpbilityIi_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}
	if (sp->CcCapabil_Present) {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
		sp->CcCapabil_Present = ED_FALSE;
	}
	if (sp->FacilityCcbsAdvancedRecallAlignment_Present) {
		if (sp->FacilityCcbsAdvancedRecallAlignment->value != NULL) {
			EDFree (sp->FacilityCcbsAdvancedRecallAlignment->value);
			sp->FacilityCcbsAdvancedRecallAlignment->value = NULL;
		}
		sp->FacilityCcbsAdvancedRecallAlignment->usedBits = 0;
		EDFree (sp->FacilityCcbsAdvancedRecallAlignment);
		sp->FacilityCcbsAdvancedRecallAlignment_Present = ED_FALSE;
	}
	if (sp->FacilityRecallAlignmentNotEssentialCcbs_Present) {
		if (sp->FacilityRecallAlignmentNotEssentialCcbs->value != NULL) {
			EDFree (sp->FacilityRecallAlignmentNotEssentialCcbs->value);
			sp->FacilityRecallAlignmentNotEssentialCcbs->value = NULL;
		}
		sp->FacilityRecallAlignmentNotEssentialCcbs->usedBits = 0;
		EDFree (sp->FacilityRecallAlignmentNotEssentialCcbs);
		sp->FacilityRecallAlignmentNotEssentialCcbs_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SETUP_UP_BearerCpblty2 (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty2_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty2_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty2 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty2)
		INIT_c_BearerCpblty (sp->BearerCpblty2);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FacilitySimpleRecallAlignment_Present == present) return ED_NO_ERRORS;
	sp->FacilitySimpleRecallAlignment_Present = present;
	if (present) {
		/*-->*/sp->FacilitySimpleRecallAlignment = (c_SETUP_UP_FacilitySimpleRecallAlignment*)EDAlloc (sizeof (c_SETUP_UP_FacilitySimpleRecallAlignment));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FacilitySimpleRecallAlignment)
		
		sp->FacilitySimpleRecallAlignment->value = NULL;
		sp->FacilitySimpleRecallAlignment->usedBits = 0;
	} else {
		if (sp->FacilitySimpleRecallAlignment->value != NULL) {
			EDFree (sp->FacilitySimpleRecallAlignment->value);
			sp->FacilitySimpleRecallAlignment->value = NULL;
		}
		sp->FacilitySimpleRecallAlignment->usedBits = 0;
		EDFree (sp->FacilitySimpleRecallAlignment);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_CallingPartySubAddr (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CallingPartySubAddr_Present == present) return ED_NO_ERRORS;
	sp->CallingPartySubAddr_Present = present;
	if (present) {
		/*-->*/sp->CallingPartySubAddr = (c_CallingPartySubaddr*)EDAlloc (sizeof (c_CallingPartySubaddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CallingPartySubAddr)
		INIT_c_CallingPartySubaddr (sp->CallingPartySubAddr);
	} else {
		FREE_c_CallingPartySubaddr (sp->CallingPartySubAddr);
		EDFree (sp->CallingPartySubAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_CalledPartySubAddr (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CalledPartySubAddr_Present == present) return ED_NO_ERRORS;
	sp->CalledPartySubAddr_Present = present;
	if (present) {
		/*-->*/sp->CalledPartySubAddr = (c_CalledPartySubaddr*)EDAlloc (sizeof (c_CalledPartySubaddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CalledPartySubAddr)
		INIT_c_CalledPartySubaddr (sp->CalledPartySubAddr);
	} else {
		FREE_c_CalledPartySubaddr (sp->CalledPartySubAddr);
		EDFree (sp->CalledPartySubAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerCpbilityI_Present == present) return ED_NO_ERRORS;
	sp->LowLayerCpbilityI_Present = present;
	if (present) {
		/*-->*/sp->LowLayerCpbilityI = (c_SETUP_UP_LowLayerCpbilityI*)EDAlloc (sizeof (c_SETUP_UP_LowLayerCpbilityI));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerCpbilityI)
		
		sp->LowLayerCpbilityI->value = NULL;
		sp->LowLayerCpbilityI->usedBits = 0;
	} else {
		if (sp->LowLayerCpbilityI->value != NULL) {
			EDFree (sp->LowLayerCpbilityI->value);
			sp->LowLayerCpbilityI->value = NULL;
		}
		sp->LowLayerCpbilityI->usedBits = 0;
		EDFree (sp->LowLayerCpbilityI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerCpbilityIi_Present == present) return ED_NO_ERRORS;
	sp->LowLayerCpbilityIi_Present = present;
	if (present) {
		/*-->*/sp->LowLayerCpbilityIi = (c_SETUP_UP_LowLayerCpbilityIi*)EDAlloc (sizeof (c_SETUP_UP_LowLayerCpbilityIi));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerCpbilityIi)
		
		sp->LowLayerCpbilityIi->value = NULL;
		sp->LowLayerCpbilityIi->usedBits = 0;
	} else {
		if (sp->LowLayerCpbilityIi->value != NULL) {
			EDFree (sp->LowLayerCpbilityIi->value);
			sp->LowLayerCpbilityIi->value = NULL;
		}
		sp->LowLayerCpbilityIi->usedBits = 0;
		EDFree (sp->LowLayerCpbilityIi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerCpbilityI_Present == present) return ED_NO_ERRORS;
	sp->HighLayerCpbilityI_Present = present;
	if (present) {
		/*-->*/sp->HighLayerCpbilityI = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerCpbilityI)
		INIT_c_HighLayerCpbility (sp->HighLayerCpbilityI);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityI);
		EDFree (sp->HighLayerCpbilityI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerCpbilityIi_Present == present) return ED_NO_ERRORS;
	sp->HighLayerCpbilityIi_Present = present;
	if (present) {
		/*-->*/sp->HighLayerCpbilityIi = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerCpbilityIi)
		INIT_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
		EDFree (sp->HighLayerCpbilityIi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_UserUser (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_SETUP_UP_UserUser*)EDAlloc (sizeof (c_SETUP_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_SsVer (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_SETUP_UP_SsVer*)EDAlloc (sizeof (c_SETUP_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_CcCapabil (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CcCapabil_Present == present) return ED_NO_ERRORS;
	sp->CcCapabil_Present = present;
	if (present) {
		/*-->*/sp->CcCapabil = (c_CallControlCapabil*)EDAlloc (sizeof (c_CallControlCapabil));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CcCapabil)
		INIT_c_CallControlCapabil (sp->CcCapabil);
	} else {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FacilityCcbsAdvancedRecallAlignment_Present == present) return ED_NO_ERRORS;
	sp->FacilityCcbsAdvancedRecallAlignment_Present = present;
	if (present) {
		/*-->*/sp->FacilityCcbsAdvancedRecallAlignment = (c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment*)EDAlloc (sizeof (c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FacilityCcbsAdvancedRecallAlignment)
		
		sp->FacilityCcbsAdvancedRecallAlignment->value = NULL;
		sp->FacilityCcbsAdvancedRecallAlignment->usedBits = 0;
	} else {
		if (sp->FacilityCcbsAdvancedRecallAlignment->value != NULL) {
			EDFree (sp->FacilityCcbsAdvancedRecallAlignment->value);
			sp->FacilityCcbsAdvancedRecallAlignment->value = NULL;
		}
		sp->FacilityCcbsAdvancedRecallAlignment->usedBits = 0;
		EDFree (sp->FacilityCcbsAdvancedRecallAlignment);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FacilityRecallAlignmentNotEssentialCcbs_Present == present) return ED_NO_ERRORS;
	sp->FacilityRecallAlignmentNotEssentialCcbs_Present = present;
	if (present) {
		/*-->*/sp->FacilityRecallAlignmentNotEssentialCcbs = (c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs*)EDAlloc (sizeof (c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FacilityRecallAlignmentNotEssentialCcbs)
		
		sp->FacilityRecallAlignmentNotEssentialCcbs->value = NULL;
		sp->FacilityRecallAlignmentNotEssentialCcbs->usedBits = 0;
	} else {
		if (sp->FacilityRecallAlignmentNotEssentialCcbs->value != NULL) {
			EDFree (sp->FacilityRecallAlignmentNotEssentialCcbs->value);
			sp->FacilityRecallAlignmentNotEssentialCcbs->value = NULL;
		}
		sp->FacilityRecallAlignmentNotEssentialCcbs->usedBits = 0;
		EDFree (sp->FacilityRecallAlignmentNotEssentialCcbs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_UP_SupportedCodecs (c_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_RESPONSE_UP */
void FREE_c_AUTHENTICATION_RESPONSE_UP (c_AUTHENTICATION_RESPONSE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthRespParamExt_Present) {
		if (sp->AuthRespParamExt->value != NULL) {
			EDFree (sp->AuthRespParamExt->value);
			sp->AuthRespParamExt->value = NULL;
		}
		sp->AuthRespParamExt->usedBits = 0;
		EDFree (sp->AuthRespParamExt);
		sp->AuthRespParamExt_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (c_AUTHENTICATION_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthRespParamExt_Present == present) return ED_NO_ERRORS;
	sp->AuthRespParamExt_Present = present;
	if (present) {
		/*-->*/sp->AuthRespParamExt = (c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt*)EDAlloc (sizeof (c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthRespParamExt)
		
		sp->AuthRespParamExt->value = NULL;
		sp->AuthRespParamExt->usedBits = 0;
	} else {
		if (sp->AuthRespParamExt->value != NULL) {
			EDFree (sp->AuthRespParamExt->value);
			sp->AuthRespParamExt->value = NULL;
		}
		sp->AuthRespParamExt->usedBits = 0;
		EDFree (sp->AuthRespParamExt);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_FAILURE_UP */
void FREE_c_AUTHENTICATION_FAILURE_UP (c_AUTHENTICATION_FAILURE_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RejectCause (&(sp->RejCause));
	if (sp->AuthFailureParam_Present) {
		EDFree (sp->AuthFailureParam);
		sp->AuthFailureParam_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (c_AUTHENTICATION_FAILURE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthFailureParam_Present == present) return ED_NO_ERRORS;
	sp->AuthFailureParam_Present = present;
	if (present) {
		/*-->*/sp->AuthFailureParam = (ED_BYTE*)EDAlloc ((size_t)14);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthFailureParam)
		ED_RESET_MEM (sp->AuthFailureParam, 14);
	} else {
		EDFree (sp->AuthFailureParam);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CM_RE_ESTABLISHMENT_REQUEST_UP */
void FREE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileStationClassmark2 (&(sp->MobileStationClassmark));
	FREE_c_MobileId (&(sp->MobileId));
	if (sp->LocationAreaId_Present) {
		FREE_c_LocationAreaId (sp->LocationAreaId);
		EDFree (sp->LocationAreaId);
		sp->LocationAreaId_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId (c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LocationAreaId_Present == present) return ED_NO_ERRORS;
	sp->LocationAreaId_Present = present;
	if (present) {
		/*-->*/sp->LocationAreaId = (c_LocationAreaId*)EDAlloc (sizeof (c_LocationAreaId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LocationAreaId)
		INIT_c_LocationAreaId (sp->LocationAreaId);
	} else {
		FREE_c_LocationAreaId (sp->LocationAreaId);
		EDFree (sp->LocationAreaId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties (c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CM_SERVICE_ABORT_UP */
void FREE_c_CM_SERVICE_ABORT_UP (c_CM_SERVICE_ABORT_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CM_SERVICE_REQUEST_UP */
void FREE_c_CM_SERVICE_REQUEST_UP (c_CM_SERVICE_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileStationClassmark2 (&(sp->MobileStationClassmark));
	FREE_c_MobileId (&(sp->MobileId));
	if (sp->Priority_Present) {
		FREE_c_PriorityLevel (sp->Priority);
		EDFree (sp->Priority);
		sp->Priority_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateParameters_Present) {
		FREE_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
		EDFree (sp->AdditionalUpdateParameters);
		sp->AdditionalUpdateParameters_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Priority_Present == present) return ED_NO_ERRORS;
	sp->Priority_Present = present;
	if (present) {
		/*-->*/sp->Priority = (c_PriorityLevel*)EDAlloc (sizeof (c_PriorityLevel));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Priority)
		INIT_c_PriorityLevel (sp->Priority);
	} else {
		FREE_c_PriorityLevel (sp->Priority);
		EDFree (sp->Priority);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateParameters_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateParameters_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateParameters = (c_AdditionalUpdateParameters*)EDAlloc (sizeof (c_AdditionalUpdateParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateParameters)
		INIT_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
	} else {
		FREE_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
		EDFree (sp->AdditionalUpdateParameters);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_IDENTITY_RESPONSE_UP */
void FREE_c_IDENTITY_RESPONSE_UP (c_IDENTITY_RESPONSE_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileId (&(sp->MobileId));
	if (sp->PTMSI_Present) {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
		sp->PTMSI_Present = ED_FALSE;
	}
	if (sp->AdditionalOldRoutingAreaIdent_Present) {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
		EDFree (sp->AdditionalOldRoutingAreaIdent);
		sp->AdditionalOldRoutingAreaIdent_Present = ED_FALSE;
	}
	if (sp->PTmsiSign_Present) {
		EDFree (sp->PTmsiSign);
		sp->PTmsiSign_Present = ED_FALSE;
	}

}

int SETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTMSI_Present == present) return ED_NO_ERRORS;
	sp->PTMSI_Present = present;
	if (present) {
		/*-->*/sp->PTMSI = (c_PTMSI_Type*)EDAlloc (sizeof (c_PTMSI_Type));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTMSI)
		INIT_c_PTMSI_Type (sp->PTMSI);
	} else {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalOldRoutingAreaIdent_Present == present) return ED_NO_ERRORS;
	sp->AdditionalOldRoutingAreaIdent_Present = present;
	if (present) {
		/*-->*/sp->AdditionalOldRoutingAreaIdent = (c_RoutingAreaIdenti2*)EDAlloc (sizeof (c_RoutingAreaIdenti2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalOldRoutingAreaIdent)
		INIT_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
	} else {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
		EDFree (sp->AdditionalOldRoutingAreaIdent);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->PTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->PTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsiSign)
		ED_RESET_MEM (sp->PTmsiSign, 3);
	} else {
		EDFree (sp->PTmsiSign);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_IMSI_DETACH_INDICATION_UP */
void FREE_c_IMSI_DETACH_INDICATION_UP (c_IMSI_DETACH_INDICATION_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileStationClassmark1 (&(sp->MobileStationClassmark));
	FREE_c_MobileId (&(sp->MobileId));

}

/* Free function for struct c_LOCATION_UPDATING_REQUEST_UP */
void FREE_c_LOCATION_UPDATING_REQUEST_UP (c_LOCATION_UPDATING_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LocationUpdatingType (&(sp->LocationUpdatingType));
	FREE_c_LocationAreaId (&(sp->LocationAreaId));
	FREE_c_MobileStationClassmark1 (&(sp->MobileStationClassmark));
	FREE_c_MobileId (&(sp->MobileId));
	if (sp->MobileStationClassmarkForUmts_Present) {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmarkForUmts);
		EDFree (sp->MobileStationClassmarkForUmts);
		sp->MobileStationClassmarkForUmts_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateParameters_Present) {
		FREE_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
		EDFree (sp->AdditionalUpdateParameters);
		sp->AdditionalUpdateParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (c_LOCATION_UPDATING_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmarkForUmts_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmarkForUmts_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmarkForUmts = (c_MobileStationClassmark2*)EDAlloc (sizeof (c_MobileStationClassmark2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmarkForUmts)
		INIT_c_MobileStationClassmark2 (sp->MobileStationClassmarkForUmts);
	} else {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmarkForUmts);
		EDFree (sp->MobileStationClassmarkForUmts);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters (c_LOCATION_UPDATING_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateParameters_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateParameters_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateParameters = (c_AdditionalUpdateParameters*)EDAlloc (sizeof (c_AdditionalUpdateParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateParameters)
		INIT_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
	} else {
		FREE_c_AdditionalUpdateParameters (sp->AdditionalUpdateParameters);
		EDFree (sp->AdditionalUpdateParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MM_STATUS */
void FREE_c_MM_STATUS (c_MM_STATUS* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RejectCause (&(sp->RejCause));

}

/* Free function for struct c_TMSI_REALLOCATION_COMPLETE_UP */
void FREE_c_TMSI_REALLOCATION_COMPLETE_UP (c_TMSI_REALLOCATION_COMPLETE_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MM_NULL_UP */
void FREE_c_MM_NULL_UP (c_MM_NULL_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ALERTING_UP */
void FREE_c_ALERTING_UP (c_ALERTING_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ALERTING_UP_Facility (c_ALERTING_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_ALERTING_UP_Facility*)EDAlloc (sizeof (c_ALERTING_UP_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ALERTING_UP_UserUser (c_ALERTING_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_ALERTING_UP_UserUser*)EDAlloc (sizeof (c_ALERTING_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ALERTING_UP_SsVer (c_ALERTING_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_ALERTING_UP_SsVer*)EDAlloc (sizeof (c_ALERTING_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CALL_CONFIRMED_UP */
void FREE_c_CALL_CONFIRMED_UP (c_CALL_CONFIRMED_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->BearerCpblty1_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
		sp->BearerCpblty1_Present = ED_FALSE;
	}
	if (sp->BearerCpblty2_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
		sp->BearerCpblty2_Present = ED_FALSE;
	}
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->CcCapabil_Present) {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
		sp->CcCapabil_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty1_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty1_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty1 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty1)
		INIT_c_BearerCpblty (sp->BearerCpblty1);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty2_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty2_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty2 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty2)
		INIT_c_BearerCpblty (sp->BearerCpblty2);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_CONFIRMED_UP_Cause (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CcCapabil_Present == present) return ED_NO_ERRORS;
	sp->CcCapabil_Present = present;
	if (present) {
		/*-->*/sp->CcCapabil = (c_CallControlCapabil*)EDAlloc (sizeof (c_CallControlCapabil));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CcCapabil)
		INIT_c_CallControlCapabil (sp->CcCapabil);
	} else {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CONNECT_UP */
void FREE_c_CONNECT_UP (c_CONNECT_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ConnSubaddr_Present) {
		FREE_c_ConnSubaddres (sp->ConnSubaddr);
		EDFree (sp->ConnSubaddr);
		sp->ConnSubaddr_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CONNECT_UP_Facility (c_CONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_CONNECT_UP_Facility*)EDAlloc (sizeof (c_CONNECT_UP_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_UP_ConnSubaddr (c_CONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ConnSubaddr_Present == present) return ED_NO_ERRORS;
	sp->ConnSubaddr_Present = present;
	if (present) {
		/*-->*/sp->ConnSubaddr = (c_ConnSubaddres*)EDAlloc (sizeof (c_ConnSubaddres));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ConnSubaddr)
		INIT_c_ConnSubaddres (sp->ConnSubaddr);
	} else {
		FREE_c_ConnSubaddres (sp->ConnSubaddr);
		EDFree (sp->ConnSubaddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_UP_UserUser (c_CONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_CONNECT_UP_UserUser*)EDAlloc (sizeof (c_CONNECT_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_UP_SsVer (c_CONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_CONNECT_UP_SsVer*)EDAlloc (sizeof (c_CONNECT_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CONNECT_ACKNOWLEDGE */
void FREE_c_CONNECT_ACKNOWLEDGE (c_CONNECT_ACKNOWLEDGE* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DISCONNECT_UP */
void FREE_c_DISCONNECT_UP (c_DISCONNECT_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DISCONNECT_UP_Facility (c_DISCONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_DISCONNECT_UP_Facility*)EDAlloc (sizeof (c_DISCONNECT_UP_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DISCONNECT_UP_UserUser (c_DISCONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_DISCONNECT_UP_UserUser*)EDAlloc (sizeof (c_DISCONNECT_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DISCONNECT_UP_SsVer (c_DISCONNECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_DISCONNECT_UP_SsVer*)EDAlloc (sizeof (c_DISCONNECT_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EMERGENCY_SETUP_UP */
void FREE_c_EMERGENCY_SETUP_UP (c_EMERGENCY_SETUP_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->BearerCpblty_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty);
		EDFree (sp->BearerCpblty);
		sp->BearerCpblty_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}
	if (sp->EmergencyCategory_Present) {
		FREE_c_ServCategory (sp->EmergencyCategory);
		EDFree (sp->EmergencyCategory);
		sp->EmergencyCategory_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty)
		INIT_c_BearerCpblty (sp->BearerCpblty);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty);
		EDFree (sp->BearerCpblty);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EmergencyCategory_Present == present) return ED_NO_ERRORS;
	sp->EmergencyCategory_Present = present;
	if (present) {
		/*-->*/sp->EmergencyCategory = (c_ServCategory*)EDAlloc (sizeof (c_ServCategory));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EmergencyCategory)
		INIT_c_ServCategory (sp->EmergencyCategory);
	} else {
		FREE_c_ServCategory (sp->EmergencyCategory);
		EDFree (sp->EmergencyCategory);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_FACILITY_UP */
void FREE_c_FACILITY_UP (c_FACILITY_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility.value != NULL) {
		EDFree (sp->Facility.value);
		sp->Facility.value = NULL;
	}
	sp->Facility.usedBits = 0;
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_FACILITY_UP_SsVer (c_FACILITY_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_FACILITY_UP_SsVer*)EDAlloc (sizeof (c_FACILITY_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_HOLD_UP */
void FREE_c_HOLD_UP (c_HOLD_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MODIFY */
void FREE_c_MODIFY (c_MODIFY* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_BearerCpblty (&(sp->BearerCpblty));
	if (sp->LowLayerComp_Present) {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
		sp->LowLayerComp_Present = ED_FALSE;
	}
	if (sp->HighLayerComp_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
		sp->HighLayerComp_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_LowLayerComp (c_MODIFY* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerComp_Present == present) return ED_NO_ERRORS;
	sp->LowLayerComp_Present = present;
	if (present) {
		/*-->*/sp->LowLayerComp = (c_MODIFY_LowLayerComp*)EDAlloc (sizeof (c_MODIFY_LowLayerComp));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerComp)
		
		sp->LowLayerComp->value = NULL;
		sp->LowLayerComp->usedBits = 0;
	} else {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_HighLayerComp (c_MODIFY* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerComp_Present == present) return ED_NO_ERRORS;
	sp->HighLayerComp_Present = present;
	if (present) {
		/*-->*/sp->HighLayerComp = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerComp)
		INIT_c_HighLayerCpbility (sp->HighLayerComp);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_COMPLETE */
void FREE_c_MODIFY_COMPLETE (c_MODIFY_COMPLETE* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_BearerCpblty (&(sp->BearerCpblty));
	if (sp->LowLayerComp_Present) {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
		sp->LowLayerComp_Present = ED_FALSE;
	}
	if (sp->HighLayerComp_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
		sp->HighLayerComp_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (c_MODIFY_COMPLETE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerComp_Present == present) return ED_NO_ERRORS;
	sp->LowLayerComp_Present = present;
	if (present) {
		/*-->*/sp->LowLayerComp = (c_MODIFY_COMPLETE_LowLayerComp*)EDAlloc (sizeof (c_MODIFY_COMPLETE_LowLayerComp));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerComp)
		
		sp->LowLayerComp->value = NULL;
		sp->LowLayerComp->usedBits = 0;
	} else {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (c_MODIFY_COMPLETE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerComp_Present == present) return ED_NO_ERRORS;
	sp->HighLayerComp_Present = present;
	if (present) {
		/*-->*/sp->HighLayerComp = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerComp)
		INIT_c_HighLayerCpbility (sp->HighLayerComp);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_REJECT */
void FREE_c_MODIFY_REJECT (c_MODIFY_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_BearerCpblty (&(sp->BearerCpblty));
	FREE_c_Cause (&(sp->Cause));
	if (sp->LowLayerComp_Present) {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
		sp->LowLayerComp_Present = ED_FALSE;
	}
	if (sp->HighLayerComp_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
		sp->HighLayerComp_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_REJECT_LowLayerComp (c_MODIFY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerComp_Present == present) return ED_NO_ERRORS;
	sp->LowLayerComp_Present = present;
	if (present) {
		/*-->*/sp->LowLayerComp = (c_MODIFY_REJECT_LowLayerComp*)EDAlloc (sizeof (c_MODIFY_REJECT_LowLayerComp));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerComp)
		
		sp->LowLayerComp->value = NULL;
		sp->LowLayerComp->usedBits = 0;
	} else {
		if (sp->LowLayerComp->value != NULL) {
			EDFree (sp->LowLayerComp->value);
			sp->LowLayerComp->value = NULL;
		}
		sp->LowLayerComp->usedBits = 0;
		EDFree (sp->LowLayerComp);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_REJECT_HighLayerComp (c_MODIFY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerComp_Present == present) return ED_NO_ERRORS;
	sp->HighLayerComp_Present = present;
	if (present) {
		/*-->*/sp->HighLayerComp = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerComp)
		INIT_c_HighLayerCpbility (sp->HighLayerComp);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerComp);
		EDFree (sp->HighLayerComp);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_NOTIFY */
void FREE_c_NOTIFY (c_NOTIFY* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NotifInd (&(sp->NotifInd));

}

/* Free function for struct c_CC_ESTABLISHMENT_CONFIRMED_UP */
void FREE_c_CC_ESTABLISHMENT_CONFIRMED_UP (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_BearerCpblty (&(sp->BearerCpblty1));
	if (sp->BearerCpblty2_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
		sp->BearerCpblty2_Present = ED_FALSE;
	}
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty2_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty2_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty2 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty2)
		INIT_c_BearerCpblty (sp->BearerCpblty2);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RELEASE_UP */
void FREE_c_RELEASE_UP (c_RELEASE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->SecondCause_Present) {
		FREE_c_Cause (sp->SecondCause);
		EDFree (sp->SecondCause);
		sp->SecondCause_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RELEASE_UP_Cause (c_RELEASE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_UP_SecondCause (c_RELEASE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SecondCause_Present == present) return ED_NO_ERRORS;
	sp->SecondCause_Present = present;
	if (present) {
		/*-->*/sp->SecondCause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SecondCause)
		INIT_c_Cause (sp->SecondCause);
	} else {
		FREE_c_Cause (sp->SecondCause);
		EDFree (sp->SecondCause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_UP_Facility (c_RELEASE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_RELEASE_UP_Facility*)EDAlloc (sizeof (c_RELEASE_UP_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_UP_UserUser (c_RELEASE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_RELEASE_UP_UserUser*)EDAlloc (sizeof (c_RELEASE_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_UP_SsVer (c_RELEASE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_RELEASE_UP_SsVer*)EDAlloc (sizeof (c_RELEASE_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RELEASE_COMPLETE_UP */
void FREE_c_RELEASE_COMPLETE_UP (c_RELEASE_COMPLETE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->SsVer_Present) {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
		sp->SsVer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_RELEASE_COMPLETE_UP_Facility*)EDAlloc (sizeof (c_RELEASE_COMPLETE_UP_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_RELEASE_COMPLETE_UP_UserUser*)EDAlloc (sizeof (c_RELEASE_COMPLETE_UP_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SsVer_Present == present) return ED_NO_ERRORS;
	sp->SsVer_Present = present;
	if (present) {
		/*-->*/sp->SsVer = (c_RELEASE_COMPLETE_UP_SsVer*)EDAlloc (sizeof (c_RELEASE_COMPLETE_UP_SsVer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SsVer)
		
		sp->SsVer->value = NULL;
		sp->SsVer->usedBits = 0;
	} else {
		if (sp->SsVer->value != NULL) {
			EDFree (sp->SsVer->value);
			sp->SsVer->value = NULL;
		}
		sp->SsVer->usedBits = 0;
		EDFree (sp->SsVer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RETRIEVE_UP */
void FREE_c_RETRIEVE_UP (c_RETRIEVE_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_START_CC_UP */
void FREE_c_START_CC_UP (c_START_CC_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->CcCapabil_Present) {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
		sp->CcCapabil_Present = ED_FALSE;
	}

}

int SETPRESENT_c_START_CC_UP_CcCapabil (c_START_CC_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CcCapabil_Present == present) return ED_NO_ERRORS;
	sp->CcCapabil_Present = present;
	if (present) {
		/*-->*/sp->CcCapabil = (c_CallControlCapabil*)EDAlloc (sizeof (c_CallControlCapabil));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CcCapabil)
		INIT_c_CallControlCapabil (sp->CcCapabil);
	} else {
		FREE_c_CallControlCapabil (sp->CcCapabil);
		EDFree (sp->CcCapabil);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_START_DTMF_UP */
void FREE_c_START_DTMF_UP (c_START_DTMF_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_KeypadFacility (&(sp->KeypadFacility));

}

/* Free function for struct c_STATUS */
void FREE_c_STATUS (c_STATUS* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));
	FREE_c_CallState (&(sp->CallState));
	if (sp->AuxiliaryStates_Present) {
		FREE_c_AuxiliaryStates (sp->AuxiliaryStates);
		EDFree (sp->AuxiliaryStates);
		sp->AuxiliaryStates_Present = ED_FALSE;
	}

}

int SETPRESENT_c_STATUS_AuxiliaryStates (c_STATUS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuxiliaryStates_Present == present) return ED_NO_ERRORS;
	sp->AuxiliaryStates_Present = present;
	if (present) {
		/*-->*/sp->AuxiliaryStates = (c_AuxiliaryStates*)EDAlloc (sizeof (c_AuxiliaryStates));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuxiliaryStates)
		INIT_c_AuxiliaryStates (sp->AuxiliaryStates);
	} else {
		FREE_c_AuxiliaryStates (sp->AuxiliaryStates);
		EDFree (sp->AuxiliaryStates);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_STATUS_ENQUIRY */
void FREE_c_STATUS_ENQUIRY (c_STATUS_ENQUIRY* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_STOP_DTMF_UP */
void FREE_c_STOP_DTMF_UP (c_STOP_DTMF_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_USER_INFORMATION */
void FREE_c_USER_INFORMATION (c_USER_INFORMATION* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->UserUser.value != NULL) {
		EDFree (sp->UserUser.value);
		sp->UserUser.value = NULL;
	}
	sp->UserUser.usedBits = 0;

}

/* Free function for struct c_ATTACH_REQUEST_UP */
void FREE_c_ATTACH_REQUEST_UP (c_ATTACH_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MsNetwkCpblty (&(sp->MsNetwkCpblty));
	FREE_c_AttachType (&(sp->AttachType));
	FREE_c_DrxParam (&(sp->DrxParam));
	FREE_c_MobileId (&(sp->MobileIdentity));
	FREE_c_RoutingAreaIdenti (&(sp->OldRoutingAreaId));
	FREE_c_MsRadioAccessCpblty (&(sp->MsRadioAccessCpblty));
	if (sp->OldPTmsiSign_Present) {
		EDFree (sp->OldPTmsiSign);
		sp->OldPTmsiSign_Present = ED_FALSE;
	}
	if (sp->ReqRdyTimerValue_Present) {
		FREE_c_GprsTimer (sp->ReqRdyTimerValue);
		EDFree (sp->ReqRdyTimerValue);
		sp->ReqRdyTimerValue_Present = ED_FALSE;
	}
	if (sp->TmsiStatus_Present) {
		FREE_c_TmsiStatus (sp->TmsiStatus);
		EDFree (sp->TmsiStatus);
		sp->TmsiStatus_Present = ED_FALSE;
	}
	if (sp->PSLCSCapability_Present) {
		FREE_c_PSLCSCapabilit (sp->PSLCSCapability);
		EDFree (sp->PSLCSCapability);
		sp->PSLCSCapability_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark2_Present) {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
		EDFree (sp->MobileStationClassmark2);
		sp->MobileStationClassmark2_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark3_Present) {
		FREE_c_Classmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
		sp->MobileStationClassmark3_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}
	if (sp->UENetworkCapability_Present) {
		if (sp->UENetworkCapability->value != NULL) {
			EDFree (sp->UENetworkCapability->value);
			sp->UENetworkCapability->value = NULL;
		}
		sp->UENetworkCapability->usedBits = 0;
		EDFree (sp->UENetworkCapability);
		sp->UENetworkCapability_Present = ED_FALSE;
	}
	if (sp->AdditionalMobileIdentity_Present) {
		FREE_c_MobileId (sp->AdditionalMobileIdentity);
		EDFree (sp->AdditionalMobileIdentity);
		sp->AdditionalMobileIdentity_Present = ED_FALSE;
	}
	if (sp->AdditionalOldRoutingAreaId_Present) {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaId);
		EDFree (sp->AdditionalOldRoutingAreaId);
		sp->AdditionalOldRoutingAreaId_Present = ED_FALSE;
	}
	if (sp->VoiceDomainPrefUEUsageSetting_Present) {
		FREE_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
		EDFree (sp->VoiceDomainPrefUEUsageSetting);
		sp->VoiceDomainPrefUEUsageSetting_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->PTMSI_Present) {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
		sp->PTMSI_Present = ED_FALSE;
	}
	if (sp->MSNetworkFeatureSupport_Present) {
		FREE_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
		sp->MSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->OldLocationAreaIdentification_Present) {
		EDFree (sp->OldLocationAreaIdentification);
		sp->OldLocationAreaIdentification_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateType_Present) {
		FREE_c_AdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
		sp->AdditionalUpdateType_Present = ED_FALSE;
	}
	if (sp->TMSIBasedNRIContainer_Present) {
		FREE_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
		sp->TMSIBasedNRIContainer_Present = ED_FALSE;
	}
	if (sp->T3324Value_Present) {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
		sp->T3324Value_Present = ED_FALSE;
	}
	if (sp->T3312ExtendedValue_Present) {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
		sp->T3312ExtendedValue_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldPTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->OldPTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->OldPTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldPTmsiSign)
		ED_RESET_MEM (sp->OldPTmsiSign, 3);
	} else {
		EDFree (sp->OldPTmsiSign);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReqRdyTimerValue_Present == present) return ED_NO_ERRORS;
	sp->ReqRdyTimerValue_Present = present;
	if (present) {
		/*-->*/sp->ReqRdyTimerValue = (c_GprsTimer*)EDAlloc (sizeof (c_GprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReqRdyTimerValue)
		INIT_c_GprsTimer (sp->ReqRdyTimerValue);
	} else {
		FREE_c_GprsTimer (sp->ReqRdyTimerValue);
		EDFree (sp->ReqRdyTimerValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TmsiStatus_Present == present) return ED_NO_ERRORS;
	sp->TmsiStatus_Present = present;
	if (present) {
		/*-->*/sp->TmsiStatus = (c_TmsiStatus*)EDAlloc (sizeof (c_TmsiStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TmsiStatus)
		INIT_c_TmsiStatus (sp->TmsiStatus);
	} else {
		FREE_c_TmsiStatus (sp->TmsiStatus);
		EDFree (sp->TmsiStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PSLCSCapability_Present == present) return ED_NO_ERRORS;
	sp->PSLCSCapability_Present = present;
	if (present) {
		/*-->*/sp->PSLCSCapability = (c_PSLCSCapabilit*)EDAlloc (sizeof (c_PSLCSCapabilit));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PSLCSCapability)
		INIT_c_PSLCSCapabilit (sp->PSLCSCapability);
	} else {
		FREE_c_PSLCSCapabilit (sp->PSLCSCapability);
		EDFree (sp->PSLCSCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark2_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark2_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark2 = (c_MobileStationClassmark2*)EDAlloc (sizeof (c_MobileStationClassmark2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark2)
		INIT_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
	} else {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
		EDFree (sp->MobileStationClassmark2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark3_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark3_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark3 = (c_Classmark3Value*)EDAlloc (sizeof (c_Classmark3Value));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark3)
		INIT_c_Classmark3Value (sp->MobileStationClassmark3);
	} else {
		FREE_c_Classmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UENetworkCapability_Present == present) return ED_NO_ERRORS;
	sp->UENetworkCapability_Present = present;
	if (present) {
		/*-->*/sp->UENetworkCapability = (c_ATTACH_REQUEST_UP_UENetworkCapability*)EDAlloc (sizeof (c_ATTACH_REQUEST_UP_UENetworkCapability));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UENetworkCapability)
		
		sp->UENetworkCapability->value = NULL;
		sp->UENetworkCapability->usedBits = 0;
	} else {
		if (sp->UENetworkCapability->value != NULL) {
			EDFree (sp->UENetworkCapability->value);
			sp->UENetworkCapability->value = NULL;
		}
		sp->UENetworkCapability->usedBits = 0;
		EDFree (sp->UENetworkCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalMobileIdentity_Present == present) return ED_NO_ERRORS;
	sp->AdditionalMobileIdentity_Present = present;
	if (present) {
		/*-->*/sp->AdditionalMobileIdentity = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalMobileIdentity)
		INIT_c_MobileId (sp->AdditionalMobileIdentity);
	} else {
		FREE_c_MobileId (sp->AdditionalMobileIdentity);
		EDFree (sp->AdditionalMobileIdentity);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalOldRoutingAreaId_Present == present) return ED_NO_ERRORS;
	sp->AdditionalOldRoutingAreaId_Present = present;
	if (present) {
		/*-->*/sp->AdditionalOldRoutingAreaId = (c_RoutingAreaIdenti2*)EDAlloc (sizeof (c_RoutingAreaIdenti2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalOldRoutingAreaId)
		INIT_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaId);
	} else {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaId);
		EDFree (sp->AdditionalOldRoutingAreaId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->VoiceDomainPrefUEUsageSetting_Present == present) return ED_NO_ERRORS;
	sp->VoiceDomainPrefUEUsageSetting_Present = present;
	if (present) {
		/*-->*/sp->VoiceDomainPrefUEUsageSetting = (c_VoiceDomainPreferenceAndUEsUsageSetting*)EDAlloc (sizeof (c_VoiceDomainPreferenceAndUEsUsageSetting));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->VoiceDomainPrefUEUsageSetting)
		INIT_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
	} else {
		FREE_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
		EDFree (sp->VoiceDomainPrefUEUsageSetting);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_PTMSI (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTMSI_Present == present) return ED_NO_ERRORS;
	sp->PTMSI_Present = present;
	if (present) {
		/*-->*/sp->PTMSI = (c_PTMSI_Type*)EDAlloc (sizeof (c_PTMSI_Type));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTMSI)
		INIT_c_PTMSI_Type (sp->PTMSI);
	} else {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkFeatureSupport = (c_MSNetworkFeatureSupport*)EDAlloc (sizeof (c_MSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkFeatureSupport)
		INIT_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
	} else {
		FREE_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldLocationAreaIdentification_Present == present) return ED_NO_ERRORS;
	sp->OldLocationAreaIdentification_Present = present;
	if (present) {
		/*-->*/sp->OldLocationAreaIdentification = (ED_BYTE*)EDAlloc ((size_t)5);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldLocationAreaIdentification)
		ED_RESET_MEM (sp->OldLocationAreaIdentification, 5);
	} else {
		EDFree (sp->OldLocationAreaIdentification);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateType_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateType_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateType = (c_AdditionalUpdateType*)EDAlloc (sizeof (c_AdditionalUpdateType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateType)
		INIT_c_AdditionalUpdateType (sp->AdditionalUpdateType);
	} else {
		FREE_c_AdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIBasedNRIContainer_Present == present) return ED_NO_ERRORS;
	sp->TMSIBasedNRIContainer_Present = present;
	if (present) {
		/*-->*/sp->TMSIBasedNRIContainer = (c_NetworkResourceIdContainer*)EDAlloc (sizeof (c_NetworkResourceIdContainer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIBasedNRIContainer)
		INIT_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
	} else {
		FREE_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324Value_Present == present) return ED_NO_ERRORS;
	sp->T3324Value_Present = present;
	if (present) {
		/*-->*/sp->T3324Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324Value)
		INIT_c_GprsTimer2 (sp->T3324Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3312ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3312ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3312ExtendedValue = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3312ExtendedValue)
		INIT_c_GprsTimer3 (sp->T3312ExtendedValue);
	} else {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_ExtendedDRXParameters*)EDAlloc (sizeof (c_ExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ATTACH_COMPLETE_UP */
void FREE_c_ATTACH_COMPLETE_UP (c_ATTACH_COMPLETE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->InterRATHandoverInfo_Present) {
		if (sp->InterRATHandoverInfo->value != NULL) {
			EDFree (sp->InterRATHandoverInfo->value);
			sp->InterRATHandoverInfo->value = NULL;
		}
		sp->InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->InterRATHandoverInfo);
		sp->InterRATHandoverInfo_Present = ED_FALSE;
	}
	if (sp->E_UTRAN_InterRATHandoverInfo_Present) {
		if (sp->E_UTRAN_InterRATHandoverInfo->value != NULL) {
			EDFree (sp->E_UTRAN_InterRATHandoverInfo->value);
			sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		}
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->E_UTRAN_InterRATHandoverInfo);
		sp->E_UTRAN_InterRATHandoverInfo_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (c_ATTACH_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->InterRATHandoverInfo_Present == present) return ED_NO_ERRORS;
	sp->InterRATHandoverInfo_Present = present;
	if (present) {
		/*-->*/sp->InterRATHandoverInfo = (c_ATTACH_COMPLETE_UP_InterRATHandoverInfo*)EDAlloc (sizeof (c_ATTACH_COMPLETE_UP_InterRATHandoverInfo));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->InterRATHandoverInfo)
		
		sp->InterRATHandoverInfo->value = NULL;
		sp->InterRATHandoverInfo->usedBits = 0;
	} else {
		if (sp->InterRATHandoverInfo->value != NULL) {
			EDFree (sp->InterRATHandoverInfo->value);
			sp->InterRATHandoverInfo->value = NULL;
		}
		sp->InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->InterRATHandoverInfo);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (c_ATTACH_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->E_UTRAN_InterRATHandoverInfo_Present == present) return ED_NO_ERRORS;
	sp->E_UTRAN_InterRATHandoverInfo_Present = present;
	if (present) {
		/*-->*/sp->E_UTRAN_InterRATHandoverInfo = (c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo*)EDAlloc (sizeof (c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->E_UTRAN_InterRATHandoverInfo)
		
		sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
	} else {
		if (sp->E_UTRAN_InterRATHandoverInfo->value != NULL) {
			EDFree (sp->E_UTRAN_InterRATHandoverInfo->value);
			sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		}
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->E_UTRAN_InterRATHandoverInfo);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DETACH_REQUEST_UP */
void FREE_c_DETACH_REQUEST_UP (c_DETACH_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_DetachType (&(sp->DetachType));
	if (sp->PTmsi_Present) {
		FREE_c_MobileId (sp->PTmsi);
		EDFree (sp->PTmsi);
		sp->PTmsi_Present = ED_FALSE;
	}
	if (sp->PTmsiSign_Present) {
		EDFree (sp->PTmsiSign);
		sp->PTmsiSign_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (c_DETACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsi_Present == present) return ED_NO_ERRORS;
	sp->PTmsi_Present = present;
	if (present) {
		/*-->*/sp->PTmsi = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsi)
		INIT_c_MobileId (sp->PTmsi);
	} else {
		FREE_c_MobileId (sp->PTmsi);
		EDFree (sp->PTmsi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (c_DETACH_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->PTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->PTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsiSign)
		ED_RESET_MEM (sp->PTmsiSign, 3);
	} else {
		EDFree (sp->PTmsiSign);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DETACH_ACCEPT_UP */
void FREE_c_DETACH_ACCEPT_UP (c_DETACH_ACCEPT_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_P_TMSI_REALLOCATION_COMPLETE_UP */
void FREE_c_P_TMSI_REALLOCATION_COMPLETE_UP (c_P_TMSI_REALLOCATION_COMPLETE_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP */
void FREE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Imeisv_Present) {
		FREE_c_MobileId (sp->Imeisv);
		EDFree (sp->Imeisv);
		sp->Imeisv_Present = ED_FALSE;
	}
	if (sp->AuthRespParamExt_Present) {
		if (sp->AuthRespParamExt->value != NULL) {
			EDFree (sp->AuthRespParamExt->value);
			sp->AuthRespParamExt->value = NULL;
		}
		sp->AuthRespParamExt->usedBits = 0;
		EDFree (sp->AuthRespParamExt);
		sp->AuthRespParamExt_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Imeisv_Present == present) return ED_NO_ERRORS;
	sp->Imeisv_Present = present;
	if (present) {
		/*-->*/sp->Imeisv = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Imeisv)
		INIT_c_MobileId (sp->Imeisv);
	} else {
		FREE_c_MobileId (sp->Imeisv);
		EDFree (sp->Imeisv);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthRespParamExt_Present == present) return ED_NO_ERRORS;
	sp->AuthRespParamExt_Present = present;
	if (present) {
		/*-->*/sp->AuthRespParamExt = (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt*)EDAlloc (sizeof (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthRespParamExt)
		
		sp->AuthRespParamExt->value = NULL;
		sp->AuthRespParamExt->usedBits = 0;
	} else {
		if (sp->AuthRespParamExt->value != NULL) {
			EDFree (sp->AuthRespParamExt->value);
			sp->AuthRespParamExt->value = NULL;
		}
		sp->AuthRespParamExt->usedBits = 0;
		EDFree (sp->AuthRespParamExt);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP */
void FREE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthFailureParam_Present) {
		EDFree (sp->AuthFailureParam);
		sp->AuthFailureParam_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthFailureParam_Present == present) return ED_NO_ERRORS;
	sp->AuthFailureParam_Present = present;
	if (present) {
		/*-->*/sp->AuthFailureParam = (ED_BYTE*)EDAlloc ((size_t)14);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthFailureParam)
		ED_RESET_MEM (sp->AuthFailureParam, 14);
	} else {
		EDFree (sp->AuthFailureParam);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_IDENTITY_RESPONSE_B_UP */
void FREE_c_IDENTITY_RESPONSE_B_UP (c_IDENTITY_RESPONSE_B_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileId (&(sp->MobileId));

}

/* Free function for struct c_ROUTING_AREA_UPDATE_REQUEST_UP */
void FREE_c_ROUTING_AREA_UPDATE_REQUEST_UP (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_UpdateType (&(sp->UpdateType));
	FREE_c_RoutingAreaIdenti (&(sp->OldRoutingAreaId));
	FREE_c_MsRadioAccessCpblty (&(sp->MsRadioAccessCpblty));
	if (sp->OldPTmsiSign_Present) {
		EDFree (sp->OldPTmsiSign);
		sp->OldPTmsiSign_Present = ED_FALSE;
	}
	if (sp->ReqRdyTimerValue_Present) {
		FREE_c_GprsTimer (sp->ReqRdyTimerValue);
		EDFree (sp->ReqRdyTimerValue);
		sp->ReqRdyTimerValue_Present = ED_FALSE;
	}
	if (sp->DrxParam_Present) {
		FREE_c_DrxParam (sp->DrxParam);
		EDFree (sp->DrxParam);
		sp->DrxParam_Present = ED_FALSE;
	}
	if (sp->TmsiStatus_Present) {
		FREE_c_TmsiStatus (sp->TmsiStatus);
		EDFree (sp->TmsiStatus);
		sp->TmsiStatus_Present = ED_FALSE;
	}
	if (sp->PTmsi_Present) {
		FREE_c_MobileId (sp->PTmsi);
		EDFree (sp->PTmsi);
		sp->PTmsi_Present = ED_FALSE;
	}
	if (sp->MsNetwkCpblty_Present) {
		FREE_c_MsNetwkCpblty (sp->MsNetwkCpblty);
		EDFree (sp->MsNetwkCpblty);
		sp->MsNetwkCpblty_Present = ED_FALSE;
	}
	if (sp->PdpContextStatus_Present) {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
		sp->PdpContextStatus_Present = ED_FALSE;
	}
	if (sp->PSLCSCapability_Present) {
		FREE_c_PSLCSCapabilit (sp->PSLCSCapability);
		EDFree (sp->PSLCSCapability);
		sp->PSLCSCapability_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}
	if (sp->UENetworkCapability_Present) {
		if (sp->UENetworkCapability->value != NULL) {
			EDFree (sp->UENetworkCapability->value);
			sp->UENetworkCapability->value = NULL;
		}
		sp->UENetworkCapability->usedBits = 0;
		EDFree (sp->UENetworkCapability);
		sp->UENetworkCapability_Present = ED_FALSE;
	}
	if (sp->AdditionalMobileIdentity_Present) {
		FREE_c_MobileId (sp->AdditionalMobileIdentity);
		EDFree (sp->AdditionalMobileIdentity);
		sp->AdditionalMobileIdentity_Present = ED_FALSE;
	}
	if (sp->AdditionalOldRoutingAreaIdent_Present) {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
		EDFree (sp->AdditionalOldRoutingAreaIdent);
		sp->AdditionalOldRoutingAreaIdent_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark2_Present) {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
		EDFree (sp->MobileStationClassmark2);
		sp->MobileStationClassmark2_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark3_Present) {
		FREE_c_Classmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
		sp->MobileStationClassmark3_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}
	if (sp->VoiceDomainPrefUEUsageSetting_Present) {
		FREE_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
		EDFree (sp->VoiceDomainPrefUEUsageSetting);
		sp->VoiceDomainPrefUEUsageSetting_Present = ED_FALSE;
	}
	if (sp->PTMSI_Present) {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
		sp->PTMSI_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->MSNetworkFeatureSupport_Present) {
		FREE_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
		sp->MSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->OldLocationAreaId_Present) {
		EDFree (sp->OldLocationAreaId);
		sp->OldLocationAreaId_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateType_Present) {
		FREE_c_AdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
		sp->AdditionalUpdateType_Present = ED_FALSE;
	}
	if (sp->TMSIBasedNRIContainer_Present) {
		FREE_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
		sp->TMSIBasedNRIContainer_Present = ED_FALSE;
	}
	if (sp->T3324Value_Present) {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
		sp->T3324Value_Present = ED_FALSE;
	}
	if (sp->T3312ExtendedValue_Present) {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
		sp->T3312ExtendedValue_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldPTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->OldPTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->OldPTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldPTmsiSign)
		ED_RESET_MEM (sp->OldPTmsiSign, 3);
	} else {
		EDFree (sp->OldPTmsiSign);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReqRdyTimerValue_Present == present) return ED_NO_ERRORS;
	sp->ReqRdyTimerValue_Present = present;
	if (present) {
		/*-->*/sp->ReqRdyTimerValue = (c_GprsTimer*)EDAlloc (sizeof (c_GprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReqRdyTimerValue)
		INIT_c_GprsTimer (sp->ReqRdyTimerValue);
	} else {
		FREE_c_GprsTimer (sp->ReqRdyTimerValue);
		EDFree (sp->ReqRdyTimerValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DrxParam_Present == present) return ED_NO_ERRORS;
	sp->DrxParam_Present = present;
	if (present) {
		/*-->*/sp->DrxParam = (c_DrxParam*)EDAlloc (sizeof (c_DrxParam));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DrxParam)
		INIT_c_DrxParam (sp->DrxParam);
	} else {
		FREE_c_DrxParam (sp->DrxParam);
		EDFree (sp->DrxParam);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TmsiStatus_Present == present) return ED_NO_ERRORS;
	sp->TmsiStatus_Present = present;
	if (present) {
		/*-->*/sp->TmsiStatus = (c_TmsiStatus*)EDAlloc (sizeof (c_TmsiStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TmsiStatus)
		INIT_c_TmsiStatus (sp->TmsiStatus);
	} else {
		FREE_c_TmsiStatus (sp->TmsiStatus);
		EDFree (sp->TmsiStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsi_Present == present) return ED_NO_ERRORS;
	sp->PTmsi_Present = present;
	if (present) {
		/*-->*/sp->PTmsi = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsi)
		INIT_c_MobileId (sp->PTmsi);
	} else {
		FREE_c_MobileId (sp->PTmsi);
		EDFree (sp->PTmsi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MsNetwkCpblty_Present == present) return ED_NO_ERRORS;
	sp->MsNetwkCpblty_Present = present;
	if (present) {
		/*-->*/sp->MsNetwkCpblty = (c_MsNetwkCpblty*)EDAlloc (sizeof (c_MsNetwkCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MsNetwkCpblty)
		INIT_c_MsNetwkCpblty (sp->MsNetwkCpblty);
	} else {
		FREE_c_MsNetwkCpblty (sp->MsNetwkCpblty);
		EDFree (sp->MsNetwkCpblty);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpContextStatus_Present == present) return ED_NO_ERRORS;
	sp->PdpContextStatus_Present = present;
	if (present) {
		/*-->*/sp->PdpContextStatus = (c_PdpContextStatus*)EDAlloc (sizeof (c_PdpContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpContextStatus)
		INIT_c_PdpContextStatus (sp->PdpContextStatus);
	} else {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PSLCSCapability_Present == present) return ED_NO_ERRORS;
	sp->PSLCSCapability_Present = present;
	if (present) {
		/*-->*/sp->PSLCSCapability = (c_PSLCSCapabilit*)EDAlloc (sizeof (c_PSLCSCapabilit));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PSLCSCapability)
		INIT_c_PSLCSCapabilit (sp->PSLCSCapability);
	} else {
		FREE_c_PSLCSCapabilit (sp->PSLCSCapability);
		EDFree (sp->PSLCSCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UENetworkCapability_Present == present) return ED_NO_ERRORS;
	sp->UENetworkCapability_Present = present;
	if (present) {
		/*-->*/sp->UENetworkCapability = (c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UENetworkCapability)
		
		sp->UENetworkCapability->value = NULL;
		sp->UENetworkCapability->usedBits = 0;
	} else {
		if (sp->UENetworkCapability->value != NULL) {
			EDFree (sp->UENetworkCapability->value);
			sp->UENetworkCapability->value = NULL;
		}
		sp->UENetworkCapability->usedBits = 0;
		EDFree (sp->UENetworkCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalMobileIdentity_Present == present) return ED_NO_ERRORS;
	sp->AdditionalMobileIdentity_Present = present;
	if (present) {
		/*-->*/sp->AdditionalMobileIdentity = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalMobileIdentity)
		INIT_c_MobileId (sp->AdditionalMobileIdentity);
	} else {
		FREE_c_MobileId (sp->AdditionalMobileIdentity);
		EDFree (sp->AdditionalMobileIdentity);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalOldRoutingAreaIdent_Present == present) return ED_NO_ERRORS;
	sp->AdditionalOldRoutingAreaIdent_Present = present;
	if (present) {
		/*-->*/sp->AdditionalOldRoutingAreaIdent = (c_RoutingAreaIdenti2*)EDAlloc (sizeof (c_RoutingAreaIdenti2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalOldRoutingAreaIdent)
		INIT_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
	} else {
		FREE_c_RoutingAreaIdenti2 (sp->AdditionalOldRoutingAreaIdent);
		EDFree (sp->AdditionalOldRoutingAreaIdent);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark2_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark2_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark2 = (c_MobileStationClassmark2*)EDAlloc (sizeof (c_MobileStationClassmark2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark2)
		INIT_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
	} else {
		FREE_c_MobileStationClassmark2 (sp->MobileStationClassmark2);
		EDFree (sp->MobileStationClassmark2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark3_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark3_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark3 = (c_Classmark3Value*)EDAlloc (sizeof (c_Classmark3Value));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark3)
		INIT_c_Classmark3Value (sp->MobileStationClassmark3);
	} else {
		FREE_c_Classmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_SupportedCodecList*)EDAlloc (sizeof (c_SupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_SupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_SupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->VoiceDomainPrefUEUsageSetting_Present == present) return ED_NO_ERRORS;
	sp->VoiceDomainPrefUEUsageSetting_Present = present;
	if (present) {
		/*-->*/sp->VoiceDomainPrefUEUsageSetting = (c_VoiceDomainPreferenceAndUEsUsageSetting*)EDAlloc (sizeof (c_VoiceDomainPreferenceAndUEsUsageSetting));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->VoiceDomainPrefUEUsageSetting)
		INIT_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
	} else {
		FREE_c_VoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPrefUEUsageSetting);
		EDFree (sp->VoiceDomainPrefUEUsageSetting);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTMSI_Present == present) return ED_NO_ERRORS;
	sp->PTMSI_Present = present;
	if (present) {
		/*-->*/sp->PTMSI = (c_PTMSI_Type*)EDAlloc (sizeof (c_PTMSI_Type));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTMSI)
		INIT_c_PTMSI_Type (sp->PTMSI);
	} else {
		FREE_c_PTMSI_Type (sp->PTMSI);
		EDFree (sp->PTMSI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkFeatureSupport = (c_MSNetworkFeatureSupport*)EDAlloc (sizeof (c_MSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkFeatureSupport)
		INIT_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
	} else {
		FREE_c_MSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldLocationAreaId_Present == present) return ED_NO_ERRORS;
	sp->OldLocationAreaId_Present = present;
	if (present) {
		/*-->*/sp->OldLocationAreaId = (ED_BYTE*)EDAlloc ((size_t)5);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldLocationAreaId)
		ED_RESET_MEM (sp->OldLocationAreaId, 5);
	} else {
		EDFree (sp->OldLocationAreaId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateType_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateType_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateType = (c_AdditionalUpdateType*)EDAlloc (sizeof (c_AdditionalUpdateType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateType)
		INIT_c_AdditionalUpdateType (sp->AdditionalUpdateType);
	} else {
		FREE_c_AdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIBasedNRIContainer_Present == present) return ED_NO_ERRORS;
	sp->TMSIBasedNRIContainer_Present = present;
	if (present) {
		/*-->*/sp->TMSIBasedNRIContainer = (c_NetworkResourceIdContainer*)EDAlloc (sizeof (c_NetworkResourceIdContainer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIBasedNRIContainer)
		INIT_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
	} else {
		FREE_c_NetworkResourceIdContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324Value_Present == present) return ED_NO_ERRORS;
	sp->T3324Value_Present = present;
	if (present) {
		/*-->*/sp->T3324Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324Value)
		INIT_c_GprsTimer2 (sp->T3324Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3312ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3312ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3312ExtendedValue = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3312ExtendedValue)
		INIT_c_GprsTimer3 (sp->T3312ExtendedValue);
	} else {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_ExtendedDRXParameters*)EDAlloc (sizeof (c_ExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ROUTING_AREA_UPDATE_COMPLETE_UP */
void FREE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ListOfReceiveNPduNumbers_Present) {
		FREE_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
		EDFree (sp->ListOfReceiveNPduNumbers);
		sp->ListOfReceiveNPduNumbers_Present = ED_FALSE;
	}
	if (sp->InterRATHandoverInfo_Present) {
		if (sp->InterRATHandoverInfo->value != NULL) {
			EDFree (sp->InterRATHandoverInfo->value);
			sp->InterRATHandoverInfo->value = NULL;
		}
		sp->InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->InterRATHandoverInfo);
		sp->InterRATHandoverInfo_Present = ED_FALSE;
	}
	if (sp->E_UTRAN_InterRATHandoverInfo_Present) {
		if (sp->E_UTRAN_InterRATHandoverInfo->value != NULL) {
			EDFree (sp->E_UTRAN_InterRATHandoverInfo->value);
			sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		}
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->E_UTRAN_InterRATHandoverInfo);
		sp->E_UTRAN_InterRATHandoverInfo_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ListOfReceiveNPduNumbers_Present == present) return ED_NO_ERRORS;
	sp->ListOfReceiveNPduNumbers_Present = present;
	if (present) {
		/*-->*/sp->ListOfReceiveNPduNumbers = (c_ReceiveNPduNumbersList*)EDAlloc (sizeof (c_ReceiveNPduNumbersList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ListOfReceiveNPduNumbers)
		INIT_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
	} else {
		FREE_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
		EDFree (sp->ListOfReceiveNPduNumbers);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->InterRATHandoverInfo_Present == present) return ED_NO_ERRORS;
	sp->InterRATHandoverInfo_Present = present;
	if (present) {
		/*-->*/sp->InterRATHandoverInfo = (c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->InterRATHandoverInfo)
		
		sp->InterRATHandoverInfo->value = NULL;
		sp->InterRATHandoverInfo->usedBits = 0;
	} else {
		if (sp->InterRATHandoverInfo->value != NULL) {
			EDFree (sp->InterRATHandoverInfo->value);
			sp->InterRATHandoverInfo->value = NULL;
		}
		sp->InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->InterRATHandoverInfo);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->E_UTRAN_InterRATHandoverInfo_Present == present) return ED_NO_ERRORS;
	sp->E_UTRAN_InterRATHandoverInfo_Present = present;
	if (present) {
		/*-->*/sp->E_UTRAN_InterRATHandoverInfo = (c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->E_UTRAN_InterRATHandoverInfo)
		
		sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
	} else {
		if (sp->E_UTRAN_InterRATHandoverInfo->value != NULL) {
			EDFree (sp->E_UTRAN_InterRATHandoverInfo->value);
			sp->E_UTRAN_InterRATHandoverInfo->value = NULL;
		}
		sp->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
		EDFree (sp->E_UTRAN_InterRATHandoverInfo);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GMM_STATUS */
void FREE_c_GMM_STATUS (c_GMM_STATUS* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SERVICE_REQUEST_UP */
void FREE_c_SERVICE_REQUEST_UP (c_SERVICE_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileId (&(sp->PTmsi));
	if (sp->PdpContextStatus_Present) {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
		sp->PdpContextStatus_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}
	if (sp->UplinkDataStatus_Present) {
		FREE_c_UplinkDataStatus (sp->UplinkDataStatus);
		EDFree (sp->UplinkDataStatus);
		sp->UplinkDataStatus_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpContextStatus_Present == present) return ED_NO_ERRORS;
	sp->PdpContextStatus_Present = present;
	if (present) {
		/*-->*/sp->PdpContextStatus = (c_PdpContextStatus*)EDAlloc (sizeof (c_PdpContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpContextStatus)
		INIT_c_PdpContextStatus (sp->PdpContextStatus);
	} else {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_SERVICE_REQUEST_UP_MBMSContextStatus*)EDAlloc (sizeof (c_SERVICE_REQUEST_UP_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UplinkDataStatus_Present == present) return ED_NO_ERRORS;
	sp->UplinkDataStatus_Present = present;
	if (present) {
		/*-->*/sp->UplinkDataStatus = (c_UplinkDataStatus*)EDAlloc (sizeof (c_UplinkDataStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UplinkDataStatus)
		INIT_c_UplinkDataStatus (sp->UplinkDataStatus);
	} else {
		FREE_c_UplinkDataStatus (sp->UplinkDataStatus);
		EDFree (sp->UplinkDataStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_REJECT_DN */
void FREE_c_AUTHENTICATION_REJECT_DN (c_AUTHENTICATION_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AUTHENTICATION_REQUEST_DN */
void FREE_c_AUTHENTICATION_REQUEST_DN (c_AUTHENTICATION_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthParamAutn_Present) {
		EDFree (sp->AuthParamAutn);
		sp->AuthParamAutn_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (c_AUTHENTICATION_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthParamAutn_Present == present) return ED_NO_ERRORS;
	sp->AuthParamAutn_Present = present;
	if (present) {
		/*-->*/sp->AuthParamAutn = (ED_BYTE*)EDAlloc ((size_t)16);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthParamAutn)
		ED_RESET_MEM (sp->AuthParamAutn, 16);
	} else {
		EDFree (sp->AuthParamAutn);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CM_SERVICE_ACCEPT_DN */
void FREE_c_CM_SERVICE_ACCEPT_DN (c_CM_SERVICE_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_CM_SERVICE_PROMPT_DN */
void FREE_c_CM_SERVICE_PROMPT_DN (c_CM_SERVICE_PROMPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_PdAndSapiCcbs (&(sp->PdAndSapiOfCm));

}

/* Free function for struct c_CM_SERVICE_REJECT_DN */
void FREE_c_CM_SERVICE_REJECT_DN (c_CM_SERVICE_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RejectCause (&(sp->RejCause));

}

/* Free function for struct c_ABORT_DN */
void FREE_c_ABORT_DN (c_ABORT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RejectCause (&(sp->RejCause));

}

/* Free function for struct c_IDENTITY_REQUEST_DN */
void FREE_c_IDENTITY_REQUEST_DN (c_IDENTITY_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_LOCATION_UPDATING_ACCEPT_DN */
void FREE_c_LOCATION_UPDATING_ACCEPT_DN (c_LOCATION_UPDATING_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LocationAreaId (&(sp->LocationAreaId));
	if (sp->MobileId_Present) {
		FREE_c_MobileId (sp->MobileId);
		EDFree (sp->MobileId);
		sp->MobileId_Present = ED_FALSE;
	}
	if (sp->EquivPlmns_Present) {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
		sp->EquivPlmns_Present = ED_FALSE;
	}
	if (sp->EmergencyNumberList_Present) {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
		sp->EmergencyNumberList_Present = ED_FALSE;
	}

}

int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileId_Present == present) return ED_NO_ERRORS;
	sp->MobileId_Present = present;
	if (present) {
		/*-->*/sp->MobileId = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileId)
		INIT_c_MobileId (sp->MobileId);
	} else {
		FREE_c_MobileId (sp->MobileId);
		EDFree (sp->MobileId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EquivPlmns_Present == present) return ED_NO_ERRORS;
	sp->EquivPlmns_Present = present;
	if (present) {
		/*-->*/sp->EquivPlmns = (c_PlmnList*)EDAlloc (sizeof (c_PlmnList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EquivPlmns)
		INIT_c_PlmnList (sp->EquivPlmns);
	} else {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EmergencyNumberList_Present == present) return ED_NO_ERRORS;
	sp->EmergencyNumberList_Present = present;
	if (present) {
		/*-->*/sp->EmergencyNumberList = (c_EmergencyNumberList*)EDAlloc (sizeof (c_EmergencyNumberList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EmergencyNumberList)
		INIT_c_EmergencyNumberList (sp->EmergencyNumberList);
	} else {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_LOCATION_UPDATING_REJECT_DN */
void FREE_c_LOCATION_UPDATING_REJECT_DN (c_LOCATION_UPDATING_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RejectCause (&(sp->RejCause));

}

/* Free function for struct c_MM_INFORMATION_DN */
void FREE_c_MM_INFORMATION_DN (c_MM_INFORMATION_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->FullNameForNetwk_Present) {
		FREE_c_NetwkName (sp->FullNameForNetwk);
		EDFree (sp->FullNameForNetwk);
		sp->FullNameForNetwk_Present = ED_FALSE;
	}
	if (sp->ShortNameForNetwk_Present) {
		FREE_c_NetwkName (sp->ShortNameForNetwk);
		EDFree (sp->ShortNameForNetwk);
		sp->ShortNameForNetwk_Present = ED_FALSE;
	}
	if (sp->UniversalTimeAndLocalTimeZone_Present) {
		FREE_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
		sp->UniversalTimeAndLocalTimeZone_Present = ED_FALSE;
	}
	if (sp->LsaId_Present) {
		if (sp->LsaId->value != NULL) {
			EDFree (sp->LsaId->value);
			sp->LsaId->value = NULL;
		}
		sp->LsaId->usedBits = 0;
		EDFree (sp->LsaId);
		sp->LsaId_Present = ED_FALSE;
	}
	if (sp->NetwkDaylightSavingTime_Present) {
		FREE_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
		EDFree (sp->NetwkDaylightSavingTime);
		sp->NetwkDaylightSavingTime_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FullNameForNetwk_Present == present) return ED_NO_ERRORS;
	sp->FullNameForNetwk_Present = present;
	if (present) {
		/*-->*/sp->FullNameForNetwk = (c_NetwkName*)EDAlloc (sizeof (c_NetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FullNameForNetwk)
		INIT_c_NetwkName (sp->FullNameForNetwk);
	} else {
		FREE_c_NetwkName (sp->FullNameForNetwk);
		EDFree (sp->FullNameForNetwk);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ShortNameForNetwk_Present == present) return ED_NO_ERRORS;
	sp->ShortNameForNetwk_Present = present;
	if (present) {
		/*-->*/sp->ShortNameForNetwk = (c_NetwkName*)EDAlloc (sizeof (c_NetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ShortNameForNetwk)
		INIT_c_NetwkName (sp->ShortNameForNetwk);
	} else {
		FREE_c_NetwkName (sp->ShortNameForNetwk);
		EDFree (sp->ShortNameForNetwk);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UniversalTimeAndLocalTimeZone_Present == present) return ED_NO_ERRORS;
	sp->UniversalTimeAndLocalTimeZone_Present = present;
	if (present) {
		/*-->*/sp->UniversalTimeAndLocalTimeZone = (c_TimeZoneAndTime*)EDAlloc (sizeof (c_TimeZoneAndTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UniversalTimeAndLocalTimeZone)
		INIT_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
	} else {
		FREE_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MM_INFORMATION_DN_LsaId (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LsaId_Present == present) return ED_NO_ERRORS;
	sp->LsaId_Present = present;
	if (present) {
		/*-->*/sp->LsaId = (c_MM_INFORMATION_DN_LsaId*)EDAlloc (sizeof (c_MM_INFORMATION_DN_LsaId));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LsaId)
		
		sp->LsaId->value = NULL;
		sp->LsaId->usedBits = 0;
	} else {
		if (sp->LsaId->value != NULL) {
			EDFree (sp->LsaId->value);
			sp->LsaId->value = NULL;
		}
		sp->LsaId->usedBits = 0;
		EDFree (sp->LsaId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetwkDaylightSavingTime_Present == present) return ED_NO_ERRORS;
	sp->NetwkDaylightSavingTime_Present = present;
	if (present) {
		/*-->*/sp->NetwkDaylightSavingTime = (c_DaylightSavingTime*)EDAlloc (sizeof (c_DaylightSavingTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetwkDaylightSavingTime)
		INIT_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
	} else {
		FREE_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
		EDFree (sp->NetwkDaylightSavingTime);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_TMSI_REALLOCATION_COMMAND_DN */
void FREE_c_TMSI_REALLOCATION_COMMAND_DN (c_TMSI_REALLOCATION_COMMAND_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LocationAreaId (&(sp->LocationAreaId));
	FREE_c_MobileId (&(sp->MobileId));

}

/* Free function for struct c_ALERTING_DN */
void FREE_c_ALERTING_DN (c_ALERTING_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ProgrInd_Present) {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
		sp->ProgrInd_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ALERTING_DN_Facility (c_ALERTING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_ALERTING_DN_Facility*)EDAlloc (sizeof (c_ALERTING_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ALERTING_DN_ProgrInd (c_ALERTING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProgrInd_Present == present) return ED_NO_ERRORS;
	sp->ProgrInd_Present = present;
	if (present) {
		/*-->*/sp->ProgrInd = (c_ProgrInd*)EDAlloc (sizeof (c_ProgrInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProgrInd)
		INIT_c_ProgrInd (sp->ProgrInd);
	} else {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ALERTING_DN_UserUser (c_ALERTING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_ALERTING_DN_UserUser*)EDAlloc (sizeof (c_ALERTING_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CALL_PROCEEDING_DN */
void FREE_c_CALL_PROCEEDING_DN (c_CALL_PROCEEDING_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->BearerCpblty1_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
		sp->BearerCpblty1_Present = ED_FALSE;
	}
	if (sp->BearerCpblty2_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
		sp->BearerCpblty2_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ProgrInd_Present) {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
		sp->ProgrInd_Present = ED_FALSE;
	}
	if (sp->PriorityGranted_Present) {
		FREE_c_PriorityLevel (sp->PriorityGranted);
		EDFree (sp->PriorityGranted);
		sp->PriorityGranted_Present = ED_FALSE;
	}
	if (sp->NetwkCallControlCapabil_Present) {
		FREE_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
		EDFree (sp->NetwkCallControlCapabil);
		sp->NetwkCallControlCapabil_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty1_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty1_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty1 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty1)
		INIT_c_BearerCpblty (sp->BearerCpblty1);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty2_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty2_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty2 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty2)
		INIT_c_BearerCpblty (sp->BearerCpblty2);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_PROCEEDING_DN_Facility (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_CALL_PROCEEDING_DN_Facility*)EDAlloc (sizeof (c_CALL_PROCEEDING_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProgrInd_Present == present) return ED_NO_ERRORS;
	sp->ProgrInd_Present = present;
	if (present) {
		/*-->*/sp->ProgrInd = (c_ProgrInd*)EDAlloc (sizeof (c_ProgrInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProgrInd)
		INIT_c_ProgrInd (sp->ProgrInd);
	} else {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PriorityGranted_Present == present) return ED_NO_ERRORS;
	sp->PriorityGranted_Present = present;
	if (present) {
		/*-->*/sp->PriorityGranted = (c_PriorityLevel*)EDAlloc (sizeof (c_PriorityLevel));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PriorityGranted)
		INIT_c_PriorityLevel (sp->PriorityGranted);
	} else {
		FREE_c_PriorityLevel (sp->PriorityGranted);
		EDFree (sp->PriorityGranted);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetwkCallControlCapabil_Present == present) return ED_NO_ERRORS;
	sp->NetwkCallControlCapabil_Present = present;
	if (present) {
		/*-->*/sp->NetwkCallControlCapabil = (c_NetwkCallControlCapabil*)EDAlloc (sizeof (c_NetwkCallControlCapabil));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetwkCallControlCapabil)
		INIT_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
	} else {
		FREE_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
		EDFree (sp->NetwkCallControlCapabil);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CONGESTION_CONTROL_DN */
void FREE_c_CONGESTION_CONTROL_DN (c_CONGESTION_CONTROL_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (c_CONGESTION_CONTROL_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CONNECT_DN */
void FREE_c_CONNECT_DN (c_CONNECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ProgrInd_Present) {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
		sp->ProgrInd_Present = ED_FALSE;
	}
	if (sp->ConnNum_Present) {
		FREE_c_ConnNum (sp->ConnNum);
		EDFree (sp->ConnNum);
		sp->ConnNum_Present = ED_FALSE;
	}
	if (sp->ConnSubaddr_Present) {
		FREE_c_ConnSubaddres (sp->ConnSubaddr);
		EDFree (sp->ConnSubaddr);
		sp->ConnSubaddr_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CONNECT_DN_Facility (c_CONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_CONNECT_DN_Facility*)EDAlloc (sizeof (c_CONNECT_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_DN_ProgrInd (c_CONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProgrInd_Present == present) return ED_NO_ERRORS;
	sp->ProgrInd_Present = present;
	if (present) {
		/*-->*/sp->ProgrInd = (c_ProgrInd*)EDAlloc (sizeof (c_ProgrInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProgrInd)
		INIT_c_ProgrInd (sp->ProgrInd);
	} else {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_DN_ConnNum (c_CONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ConnNum_Present == present) return ED_NO_ERRORS;
	sp->ConnNum_Present = present;
	if (present) {
		/*-->*/sp->ConnNum = (c_ConnNum*)EDAlloc (sizeof (c_ConnNum));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ConnNum)
		INIT_c_ConnNum (sp->ConnNum);
	} else {
		FREE_c_ConnNum (sp->ConnNum);
		EDFree (sp->ConnNum);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_DN_ConnSubaddr (c_CONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ConnSubaddr_Present == present) return ED_NO_ERRORS;
	sp->ConnSubaddr_Present = present;
	if (present) {
		/*-->*/sp->ConnSubaddr = (c_ConnSubaddres*)EDAlloc (sizeof (c_ConnSubaddres));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ConnSubaddr)
		INIT_c_ConnSubaddres (sp->ConnSubaddr);
	} else {
		FREE_c_ConnSubaddres (sp->ConnSubaddr);
		EDFree (sp->ConnSubaddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONNECT_DN_UserUser (c_CONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_CONNECT_DN_UserUser*)EDAlloc (sizeof (c_CONNECT_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DISCONNECT_DN */
void FREE_c_DISCONNECT_DN (c_DISCONNECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ProgrInd_Present) {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
		sp->ProgrInd_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->AllowedActionsCcbs_Present) {
		FREE_c_AllowedActionsCcbs (sp->AllowedActionsCcbs);
		EDFree (sp->AllowedActionsCcbs);
		sp->AllowedActionsCcbs_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DISCONNECT_DN_Facility (c_DISCONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_DISCONNECT_DN_Facility*)EDAlloc (sizeof (c_DISCONNECT_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DISCONNECT_DN_ProgrInd (c_DISCONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProgrInd_Present == present) return ED_NO_ERRORS;
	sp->ProgrInd_Present = present;
	if (present) {
		/*-->*/sp->ProgrInd = (c_ProgrInd*)EDAlloc (sizeof (c_ProgrInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProgrInd)
		INIT_c_ProgrInd (sp->ProgrInd);
	} else {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DISCONNECT_DN_UserUser (c_DISCONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_DISCONNECT_DN_UserUser*)EDAlloc (sizeof (c_DISCONNECT_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (c_DISCONNECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AllowedActionsCcbs_Present == present) return ED_NO_ERRORS;
	sp->AllowedActionsCcbs_Present = present;
	if (present) {
		/*-->*/sp->AllowedActionsCcbs = (c_AllowedActionsCcbs*)EDAlloc (sizeof (c_AllowedActionsCcbs));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AllowedActionsCcbs)
		INIT_c_AllowedActionsCcbs (sp->AllowedActionsCcbs);
	} else {
		FREE_c_AllowedActionsCcbs (sp->AllowedActionsCcbs);
		EDFree (sp->AllowedActionsCcbs);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_FACILITY_DN */
void FREE_c_FACILITY_DN (c_FACILITY_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Facility.value != NULL) {
		EDFree (sp->Facility.value);
		sp->Facility.value = NULL;
	}
	sp->Facility.usedBits = 0;

}

/* Free function for struct c_HOLD_ACKNOWLEDGE_DN */
void FREE_c_HOLD_ACKNOWLEDGE_DN (c_HOLD_ACKNOWLEDGE_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_HOLD_REJECT_DN */
void FREE_c_HOLD_REJECT_DN (c_HOLD_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));

}

/* Free function for struct c_PROGRESS_DN */
void FREE_c_PROGRESS_DN (c_PROGRESS_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_ProgrInd (&(sp->ProgrInd));
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}

}

int SETPRESENT_c_PROGRESS_DN_UserUser (c_PROGRESS_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_PROGRESS_DN_UserUser*)EDAlloc (sizeof (c_PROGRESS_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CC_ESTABLISHMENT_DN */
void FREE_c_CC_ESTABLISHMENT_DN (c_CC_ESTABLISHMENT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SETUP_UP (&(sp->SetupContainer));

}

/* Free function for struct c_RELEASE_DN */
void FREE_c_RELEASE_DN (c_RELEASE_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->SecondCause_Present) {
		FREE_c_Cause (sp->SecondCause);
		EDFree (sp->SecondCause);
		sp->SecondCause_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RELEASE_DN_Cause (c_RELEASE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_DN_SecondCause (c_RELEASE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SecondCause_Present == present) return ED_NO_ERRORS;
	sp->SecondCause_Present = present;
	if (present) {
		/*-->*/sp->SecondCause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SecondCause)
		INIT_c_Cause (sp->SecondCause);
	} else {
		FREE_c_Cause (sp->SecondCause);
		EDFree (sp->SecondCause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_DN_Facility (c_RELEASE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_RELEASE_DN_Facility*)EDAlloc (sizeof (c_RELEASE_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_DN_UserUser (c_RELEASE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_RELEASE_DN_UserUser*)EDAlloc (sizeof (c_RELEASE_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RECALL_DN */
void FREE_c_RECALL_DN (c_RECALL_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_RecallType (&(sp->RecallType));
	if (sp->Facility.value != NULL) {
		EDFree (sp->Facility.value);
		sp->Facility.value = NULL;
	}
	sp->Facility.usedBits = 0;

}

/* Free function for struct c_RELEASE_COMPLETE_DN */
void FREE_c_RELEASE_COMPLETE_DN (c_RELEASE_COMPLETE_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Cause_Present) {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
		sp->Cause_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}

}

int SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Cause_Present == present) return ED_NO_ERRORS;
	sp->Cause_Present = present;
	if (present) {
		/*-->*/sp->Cause = (c_Cause*)EDAlloc (sizeof (c_Cause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Cause)
		INIT_c_Cause (sp->Cause);
	} else {
		FREE_c_Cause (sp->Cause);
		EDFree (sp->Cause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_RELEASE_COMPLETE_DN_Facility*)EDAlloc (sizeof (c_RELEASE_COMPLETE_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_RELEASE_COMPLETE_DN_UserUser*)EDAlloc (sizeof (c_RELEASE_COMPLETE_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_RETRIEVE_ACKNOWLEDGE_DN */
void FREE_c_RETRIEVE_ACKNOWLEDGE_DN (c_RETRIEVE_ACKNOWLEDGE_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_RETRIEVE_REJECT_DN */
void FREE_c_RETRIEVE_REJECT_DN (c_RETRIEVE_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));

}

/* Free function for struct c_SETUP_DN */
void FREE_c_SETUP_DN (c_SETUP_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->BearerCpblty1_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
		sp->BearerCpblty1_Present = ED_FALSE;
	}
	if (sp->BearerCpblty2_Present) {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
		sp->BearerCpblty2_Present = ED_FALSE;
	}
	if (sp->Facility_Present) {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
		sp->Facility_Present = ED_FALSE;
	}
	if (sp->ProgrInd_Present) {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
		sp->ProgrInd_Present = ED_FALSE;
	}
	if (sp->CallingPartyBcdNum_Present) {
		FREE_c_CallingPartyBcdNum (sp->CallingPartyBcdNum);
		EDFree (sp->CallingPartyBcdNum);
		sp->CallingPartyBcdNum_Present = ED_FALSE;
	}
	if (sp->CallingPartySubAddr_Present) {
		FREE_c_CallingPartySubaddr (sp->CallingPartySubAddr);
		EDFree (sp->CallingPartySubAddr);
		sp->CallingPartySubAddr_Present = ED_FALSE;
	}
	if (sp->CalledPartyBcdNum_Present) {
		FREE_c_CalledPartyBcdNum (sp->CalledPartyBcdNum);
		EDFree (sp->CalledPartyBcdNum);
		sp->CalledPartyBcdNum_Present = ED_FALSE;
	}
	if (sp->CalledPartySubAddr_Present) {
		FREE_c_CalledPartySubaddr (sp->CalledPartySubAddr);
		EDFree (sp->CalledPartySubAddr);
		sp->CalledPartySubAddr_Present = ED_FALSE;
	}
	if (sp->RedirPartyBcdNum_Present) {
		FREE_c_RedirPartyBcdNum (sp->RedirPartyBcdNum);
		EDFree (sp->RedirPartyBcdNum);
		sp->RedirPartyBcdNum_Present = ED_FALSE;
	}
	if (sp->RedirPartySubAddr_Present) {
		FREE_c_RedirPartySubaddr (sp->RedirPartySubAddr);
		EDFree (sp->RedirPartySubAddr);
		sp->RedirPartySubAddr_Present = ED_FALSE;
	}
	if (sp->LowLayerCpbilityI_Present) {
		if (sp->LowLayerCpbilityI->value != NULL) {
			EDFree (sp->LowLayerCpbilityI->value);
			sp->LowLayerCpbilityI->value = NULL;
		}
		sp->LowLayerCpbilityI->usedBits = 0;
		EDFree (sp->LowLayerCpbilityI);
		sp->LowLayerCpbilityI_Present = ED_FALSE;
	}
	if (sp->LowLayerCpbilityIi_Present) {
		if (sp->LowLayerCpbilityIi->value != NULL) {
			EDFree (sp->LowLayerCpbilityIi->value);
			sp->LowLayerCpbilityIi->value = NULL;
		}
		sp->LowLayerCpbilityIi->usedBits = 0;
		EDFree (sp->LowLayerCpbilityIi);
		sp->LowLayerCpbilityIi_Present = ED_FALSE;
	}
	if (sp->HighLayerCpbilityI_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityI);
		EDFree (sp->HighLayerCpbilityI);
		sp->HighLayerCpbilityI_Present = ED_FALSE;
	}
	if (sp->HighLayerCpbilityIi_Present) {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
		EDFree (sp->HighLayerCpbilityIi);
		sp->HighLayerCpbilityIi_Present = ED_FALSE;
	}
	if (sp->UserUser_Present) {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
		sp->UserUser_Present = ED_FALSE;
	}
	if (sp->Priority_Present) {
		FREE_c_PriorityLevel (sp->Priority);
		EDFree (sp->Priority);
		sp->Priority_Present = ED_FALSE;
	}
	if (sp->Alert_Present) {
		FREE_c_AlertingPattern (sp->Alert);
		EDFree (sp->Alert);
		sp->Alert_Present = ED_FALSE;
	}
	if (sp->NetwkCallControlCapabil_Present) {
		FREE_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
		EDFree (sp->NetwkCallControlCapabil);
		sp->NetwkCallControlCapabil_Present = ED_FALSE;
	}
	if (sp->BackupBearerCapability_Present) {
		FREE_c_BackupBearerCapability (sp->BackupBearerCapability);
		EDFree (sp->BackupBearerCapability);
		sp->BackupBearerCapability_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SETUP_DN_BearerCpblty1 (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty1_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty1_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty1 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty1)
		INIT_c_BearerCpblty (sp->BearerCpblty1);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty1);
		EDFree (sp->BearerCpblty1);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_BearerCpblty2 (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BearerCpblty2_Present == present) return ED_NO_ERRORS;
	sp->BearerCpblty2_Present = present;
	if (present) {
		/*-->*/sp->BearerCpblty2 = (c_BearerCpblty*)EDAlloc (sizeof (c_BearerCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BearerCpblty2)
		INIT_c_BearerCpblty (sp->BearerCpblty2);
	} else {
		FREE_c_BearerCpblty (sp->BearerCpblty2);
		EDFree (sp->BearerCpblty2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_Facility (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Facility_Present == present) return ED_NO_ERRORS;
	sp->Facility_Present = present;
	if (present) {
		/*-->*/sp->Facility = (c_SETUP_DN_Facility*)EDAlloc (sizeof (c_SETUP_DN_Facility));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Facility)
		
		sp->Facility->value = NULL;
		sp->Facility->usedBits = 0;
	} else {
		if (sp->Facility->value != NULL) {
			EDFree (sp->Facility->value);
			sp->Facility->value = NULL;
		}
		sp->Facility->usedBits = 0;
		EDFree (sp->Facility);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_ProgrInd (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProgrInd_Present == present) return ED_NO_ERRORS;
	sp->ProgrInd_Present = present;
	if (present) {
		/*-->*/sp->ProgrInd = (c_ProgrInd*)EDAlloc (sizeof (c_ProgrInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProgrInd)
		INIT_c_ProgrInd (sp->ProgrInd);
	} else {
		FREE_c_ProgrInd (sp->ProgrInd);
		EDFree (sp->ProgrInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CallingPartyBcdNum_Present == present) return ED_NO_ERRORS;
	sp->CallingPartyBcdNum_Present = present;
	if (present) {
		/*-->*/sp->CallingPartyBcdNum = (c_CallingPartyBcdNum*)EDAlloc (sizeof (c_CallingPartyBcdNum));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CallingPartyBcdNum)
		INIT_c_CallingPartyBcdNum (sp->CallingPartyBcdNum);
	} else {
		FREE_c_CallingPartyBcdNum (sp->CallingPartyBcdNum);
		EDFree (sp->CallingPartyBcdNum);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_CallingPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CallingPartySubAddr_Present == present) return ED_NO_ERRORS;
	sp->CallingPartySubAddr_Present = present;
	if (present) {
		/*-->*/sp->CallingPartySubAddr = (c_CallingPartySubaddr*)EDAlloc (sizeof (c_CallingPartySubaddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CallingPartySubAddr)
		INIT_c_CallingPartySubaddr (sp->CallingPartySubAddr);
	} else {
		FREE_c_CallingPartySubaddr (sp->CallingPartySubAddr);
		EDFree (sp->CallingPartySubAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CalledPartyBcdNum_Present == present) return ED_NO_ERRORS;
	sp->CalledPartyBcdNum_Present = present;
	if (present) {
		/*-->*/sp->CalledPartyBcdNum = (c_CalledPartyBcdNum*)EDAlloc (sizeof (c_CalledPartyBcdNum));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CalledPartyBcdNum)
		INIT_c_CalledPartyBcdNum (sp->CalledPartyBcdNum);
	} else {
		FREE_c_CalledPartyBcdNum (sp->CalledPartyBcdNum);
		EDFree (sp->CalledPartyBcdNum);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_CalledPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CalledPartySubAddr_Present == present) return ED_NO_ERRORS;
	sp->CalledPartySubAddr_Present = present;
	if (present) {
		/*-->*/sp->CalledPartySubAddr = (c_CalledPartySubaddr*)EDAlloc (sizeof (c_CalledPartySubaddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CalledPartySubAddr)
		INIT_c_CalledPartySubaddr (sp->CalledPartySubAddr);
	} else {
		FREE_c_CalledPartySubaddr (sp->CalledPartySubAddr);
		EDFree (sp->CalledPartySubAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RedirPartyBcdNum_Present == present) return ED_NO_ERRORS;
	sp->RedirPartyBcdNum_Present = present;
	if (present) {
		/*-->*/sp->RedirPartyBcdNum = (c_RedirPartyBcdNum*)EDAlloc (sizeof (c_RedirPartyBcdNum));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RedirPartyBcdNum)
		INIT_c_RedirPartyBcdNum (sp->RedirPartyBcdNum);
	} else {
		FREE_c_RedirPartyBcdNum (sp->RedirPartyBcdNum);
		EDFree (sp->RedirPartyBcdNum);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_RedirPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RedirPartySubAddr_Present == present) return ED_NO_ERRORS;
	sp->RedirPartySubAddr_Present = present;
	if (present) {
		/*-->*/sp->RedirPartySubAddr = (c_RedirPartySubaddr*)EDAlloc (sizeof (c_RedirPartySubaddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RedirPartySubAddr)
		INIT_c_RedirPartySubaddr (sp->RedirPartySubAddr);
	} else {
		FREE_c_RedirPartySubaddr (sp->RedirPartySubAddr);
		EDFree (sp->RedirPartySubAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerCpbilityI_Present == present) return ED_NO_ERRORS;
	sp->LowLayerCpbilityI_Present = present;
	if (present) {
		/*-->*/sp->LowLayerCpbilityI = (c_SETUP_DN_LowLayerCpbilityI*)EDAlloc (sizeof (c_SETUP_DN_LowLayerCpbilityI));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerCpbilityI)
		
		sp->LowLayerCpbilityI->value = NULL;
		sp->LowLayerCpbilityI->usedBits = 0;
	} else {
		if (sp->LowLayerCpbilityI->value != NULL) {
			EDFree (sp->LowLayerCpbilityI->value);
			sp->LowLayerCpbilityI->value = NULL;
		}
		sp->LowLayerCpbilityI->usedBits = 0;
		EDFree (sp->LowLayerCpbilityI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LowLayerCpbilityIi_Present == present) return ED_NO_ERRORS;
	sp->LowLayerCpbilityIi_Present = present;
	if (present) {
		/*-->*/sp->LowLayerCpbilityIi = (c_SETUP_DN_LowLayerCpbilityIi*)EDAlloc (sizeof (c_SETUP_DN_LowLayerCpbilityIi));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LowLayerCpbilityIi)
		
		sp->LowLayerCpbilityIi->value = NULL;
		sp->LowLayerCpbilityIi->usedBits = 0;
	} else {
		if (sp->LowLayerCpbilityIi->value != NULL) {
			EDFree (sp->LowLayerCpbilityIi->value);
			sp->LowLayerCpbilityIi->value = NULL;
		}
		sp->LowLayerCpbilityIi->usedBits = 0;
		EDFree (sp->LowLayerCpbilityIi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerCpbilityI_Present == present) return ED_NO_ERRORS;
	sp->HighLayerCpbilityI_Present = present;
	if (present) {
		/*-->*/sp->HighLayerCpbilityI = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerCpbilityI)
		INIT_c_HighLayerCpbility (sp->HighLayerCpbilityI);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityI);
		EDFree (sp->HighLayerCpbilityI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HighLayerCpbilityIi_Present == present) return ED_NO_ERRORS;
	sp->HighLayerCpbilityIi_Present = present;
	if (present) {
		/*-->*/sp->HighLayerCpbilityIi = (c_HighLayerCpbility*)EDAlloc (sizeof (c_HighLayerCpbility));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HighLayerCpbilityIi)
		INIT_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
	} else {
		FREE_c_HighLayerCpbility (sp->HighLayerCpbilityIi);
		EDFree (sp->HighLayerCpbilityIi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_UserUser (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UserUser_Present == present) return ED_NO_ERRORS;
	sp->UserUser_Present = present;
	if (present) {
		/*-->*/sp->UserUser = (c_SETUP_DN_UserUser*)EDAlloc (sizeof (c_SETUP_DN_UserUser));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UserUser)
		
		sp->UserUser->value = NULL;
		sp->UserUser->usedBits = 0;
	} else {
		if (sp->UserUser->value != NULL) {
			EDFree (sp->UserUser->value);
			sp->UserUser->value = NULL;
		}
		sp->UserUser->usedBits = 0;
		EDFree (sp->UserUser);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_Priority (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Priority_Present == present) return ED_NO_ERRORS;
	sp->Priority_Present = present;
	if (present) {
		/*-->*/sp->Priority = (c_PriorityLevel*)EDAlloc (sizeof (c_PriorityLevel));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Priority)
		INIT_c_PriorityLevel (sp->Priority);
	} else {
		FREE_c_PriorityLevel (sp->Priority);
		EDFree (sp->Priority);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_Alert (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Alert_Present == present) return ED_NO_ERRORS;
	sp->Alert_Present = present;
	if (present) {
		/*-->*/sp->Alert = (c_AlertingPattern*)EDAlloc (sizeof (c_AlertingPattern));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Alert)
		INIT_c_AlertingPattern (sp->Alert);
	} else {
		FREE_c_AlertingPattern (sp->Alert);
		EDFree (sp->Alert);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetwkCallControlCapabil_Present == present) return ED_NO_ERRORS;
	sp->NetwkCallControlCapabil_Present = present;
	if (present) {
		/*-->*/sp->NetwkCallControlCapabil = (c_NetwkCallControlCapabil*)EDAlloc (sizeof (c_NetwkCallControlCapabil));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetwkCallControlCapabil)
		INIT_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
	} else {
		FREE_c_NetwkCallControlCapabil (sp->NetwkCallControlCapabil);
		EDFree (sp->NetwkCallControlCapabil);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SETUP_DN_BackupBearerCapability (c_SETUP_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BackupBearerCapability_Present == present) return ED_NO_ERRORS;
	sp->BackupBearerCapability_Present = present;
	if (present) {
		/*-->*/sp->BackupBearerCapability = (c_BackupBearerCapability*)EDAlloc (sizeof (c_BackupBearerCapability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BackupBearerCapability)
		INIT_c_BackupBearerCapability (sp->BackupBearerCapability);
	} else {
		FREE_c_BackupBearerCapability (sp->BackupBearerCapability);
		EDFree (sp->BackupBearerCapability);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_START_DTMF_ACKNOWLEDGE_DN */
void FREE_c_START_DTMF_ACKNOWLEDGE_DN (c_START_DTMF_ACKNOWLEDGE_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_KeypadFacility (&(sp->KeypadFacility));

}

/* Free function for struct c_START_DTMF_REJECT_DN */
void FREE_c_START_DTMF_REJECT_DN (c_START_DTMF_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_Cause (&(sp->Cause));

}

/* Free function for struct c_STOP_DTMF_ACKNOWLEDGE_DN */
void FREE_c_STOP_DTMF_ACKNOWLEDGE_DN (c_STOP_DTMF_ACKNOWLEDGE_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ATTACH_ACCEPT_DN */
void FREE_c_ATTACH_ACCEPT_DN (c_ATTACH_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_AttachResult (&(sp->AttachResult));
	FREE_c_GprsTimer (&(sp->PeriodicRaUpdateTimer));
	FREE_c_RoutingAreaIdenti (&(sp->RoutingAreaId));
	if (sp->PTmsiSign_Present) {
		EDFree (sp->PTmsiSign);
		sp->PTmsiSign_Present = ED_FALSE;
	}
	if (sp->NegotiatedRdyTimerValue_Present) {
		FREE_c_GprsTimer (sp->NegotiatedRdyTimerValue);
		EDFree (sp->NegotiatedRdyTimerValue);
		sp->NegotiatedRdyTimerValue_Present = ED_FALSE;
	}
	if (sp->AllocatedPTmsi_Present) {
		FREE_c_MobileId (sp->AllocatedPTmsi);
		EDFree (sp->AllocatedPTmsi);
		sp->AllocatedPTmsi_Present = ED_FALSE;
	}
	if (sp->MsId_Present) {
		FREE_c_MobileId (sp->MsId);
		EDFree (sp->MsId);
		sp->MsId_Present = ED_FALSE;
	}
	if (sp->T3302Value_Present) {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
		sp->T3302Value_Present = ED_FALSE;
	}
	if (sp->EquivPlmns_Present) {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
		sp->EquivPlmns_Present = ED_FALSE;
	}
	if (sp->NetworkFeatureSupport_Present) {
		FREE_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
		EDFree (sp->NetworkFeatureSupport);
		sp->NetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->EmergencyNumberList_Present) {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
		sp->EmergencyNumberList_Present = ED_FALSE;
	}
	if (sp->RequestedMSInformation_Present) {
		FREE_c_RequestedMSInformation (sp->RequestedMSInformation);
		EDFree (sp->RequestedMSInformation);
		sp->RequestedMSInformation_Present = ED_FALSE;
	}
	if (sp->T3319Value_Present) {
		FREE_c_GprsTimer2 (sp->T3319Value);
		EDFree (sp->T3319Value);
		sp->T3319Value_Present = ED_FALSE;
	}
	if (sp->T3323Value_Present) {
		FREE_c_GprsTimer2 (sp->T3323Value);
		EDFree (sp->T3323Value);
		sp->T3323Value_Present = ED_FALSE;
	}
	if (sp->T3312ExtendedValue_Present) {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
		sp->T3312ExtendedValue_Present = ED_FALSE;
	}
	if (sp->AdditionalNetworkFeatureSupport_Present) {
		FREE_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
		EDFree (sp->AdditionalNetworkFeatureSupport);
		sp->AdditionalNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->T3324Value_Present) {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
		sp->T3324Value_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->PTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->PTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsiSign)
		ED_RESET_MEM (sp->PTmsiSign, 3);
	} else {
		EDFree (sp->PTmsiSign);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedRdyTimerValue_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedRdyTimerValue_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedRdyTimerValue = (c_GprsTimer*)EDAlloc (sizeof (c_GprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedRdyTimerValue)
		INIT_c_GprsTimer (sp->NegotiatedRdyTimerValue);
	} else {
		FREE_c_GprsTimer (sp->NegotiatedRdyTimerValue);
		EDFree (sp->NegotiatedRdyTimerValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AllocatedPTmsi_Present == present) return ED_NO_ERRORS;
	sp->AllocatedPTmsi_Present = present;
	if (present) {
		/*-->*/sp->AllocatedPTmsi = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AllocatedPTmsi)
		INIT_c_MobileId (sp->AllocatedPTmsi);
	} else {
		FREE_c_MobileId (sp->AllocatedPTmsi);
		EDFree (sp->AllocatedPTmsi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MsId_Present == present) return ED_NO_ERRORS;
	sp->MsId_Present = present;
	if (present) {
		/*-->*/sp->MsId = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MsId)
		INIT_c_MobileId (sp->MsId);
	} else {
		FREE_c_MobileId (sp->MsId);
		EDFree (sp->MsId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3302Value_Present == present) return ED_NO_ERRORS;
	sp->T3302Value_Present = present;
	if (present) {
		/*-->*/sp->T3302Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3302Value)
		INIT_c_GprsTimer2 (sp->T3302Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EquivPlmns_Present == present) return ED_NO_ERRORS;
	sp->EquivPlmns_Present = present;
	if (present) {
		/*-->*/sp->EquivPlmns = (c_PlmnList*)EDAlloc (sizeof (c_PlmnList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EquivPlmns)
		INIT_c_PlmnList (sp->EquivPlmns);
	} else {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->NetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->NetworkFeatureSupport = (c_NetworkFeatureSupport*)EDAlloc (sizeof (c_NetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetworkFeatureSupport)
		INIT_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
	} else {
		FREE_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
		EDFree (sp->NetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EmergencyNumberList_Present == present) return ED_NO_ERRORS;
	sp->EmergencyNumberList_Present = present;
	if (present) {
		/*-->*/sp->EmergencyNumberList = (c_EmergencyNumberList*)EDAlloc (sizeof (c_EmergencyNumberList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EmergencyNumberList)
		INIT_c_EmergencyNumberList (sp->EmergencyNumberList);
	} else {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RequestedMSInformation_Present == present) return ED_NO_ERRORS;
	sp->RequestedMSInformation_Present = present;
	if (present) {
		/*-->*/sp->RequestedMSInformation = (c_RequestedMSInformation*)EDAlloc (sizeof (c_RequestedMSInformation));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RequestedMSInformation)
		INIT_c_RequestedMSInformation (sp->RequestedMSInformation);
	} else {
		FREE_c_RequestedMSInformation (sp->RequestedMSInformation);
		EDFree (sp->RequestedMSInformation);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3319Value_Present == present) return ED_NO_ERRORS;
	sp->T3319Value_Present = present;
	if (present) {
		/*-->*/sp->T3319Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3319Value)
		INIT_c_GprsTimer2 (sp->T3319Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3319Value);
		EDFree (sp->T3319Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3323Value_Present == present) return ED_NO_ERRORS;
	sp->T3323Value_Present = present;
	if (present) {
		/*-->*/sp->T3323Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3323Value)
		INIT_c_GprsTimer2 (sp->T3323Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3323Value);
		EDFree (sp->T3323Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3312ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3312ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3312ExtendedValue = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3312ExtendedValue)
		INIT_c_GprsTimer3 (sp->T3312ExtendedValue);
	} else {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->AdditionalNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->AdditionalNetworkFeatureSupport = (c_AdditionalNetworkFeatureSupport*)EDAlloc (sizeof (c_AdditionalNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalNetworkFeatureSupport)
		INIT_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
	} else {
		FREE_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
		EDFree (sp->AdditionalNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324Value_Present == present) return ED_NO_ERRORS;
	sp->T3324Value_Present = present;
	if (present) {
		/*-->*/sp->T3324Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324Value)
		INIT_c_GprsTimer2 (sp->T3324Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_ExtendedDRXParameters*)EDAlloc (sizeof (c_ExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ATTACH_REJECT_DN */
void FREE_c_ATTACH_REJECT_DN (c_ATTACH_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3302Value_Present) {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
		sp->T3302Value_Present = ED_FALSE;
	}
	if (sp->T3346Value_Present) {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (c_ATTACH_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3302Value_Present == present) return ED_NO_ERRORS;
	sp->T3302Value_Present = present;
	if (present) {
		/*-->*/sp->T3302Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3302Value)
		INIT_c_GprsTimer2 (sp->T3302Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (c_ATTACH_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_GprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DETACH_REQUEST_DN */
void FREE_c_DETACH_REQUEST_DN (c_DETACH_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_DetachType (&(sp->DetachType));

}

/* Free function for struct c_DETACH_ACCEPT_DN */
void FREE_c_DETACH_ACCEPT_DN (c_DETACH_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_P_TMSI_REALLOCATION_COMMAND_DN */
void FREE_c_P_TMSI_REALLOCATION_COMMAND_DN (c_P_TMSI_REALLOCATION_COMMAND_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_MobileId (&(sp->AllocatedPTmsi));
	FREE_c_RoutingAreaIdenti (&(sp->RoutingAreaId));
	if (sp->PTmsiSign_Present) {
		EDFree (sp->PTmsiSign);
		sp->PTmsiSign_Present = ED_FALSE;
	}

}

int SETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign (c_P_TMSI_REALLOCATION_COMMAND_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->PTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->PTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsiSign)
		ED_RESET_MEM (sp->PTmsiSign, 3);
	} else {
		EDFree (sp->PTmsiSign);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN */
void FREE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthParamRand_Present) {
		EDFree (sp->AuthParamRand);
		sp->AuthParamRand_Present = ED_FALSE;
	}
	if (sp->AuthParamAutn_Present) {
		EDFree (sp->AuthParamAutn);
		sp->AuthParamAutn_Present = ED_FALSE;
	}
	if (sp->MsNetwkCpblty_Present) {
		FREE_c_MsNetwkCpblty (sp->MsNetwkCpblty);
		EDFree (sp->MsNetwkCpblty);
		sp->MsNetwkCpblty_Present = ED_FALSE;
	}
	if (sp->IntegrityProtectionAlgorithm_Present) {
		FREE_c_IntegrityProtectionAlgorithm (sp->IntegrityProtectionAlgorithm);
		EDFree (sp->IntegrityProtectionAlgorithm);
		sp->IntegrityProtectionAlgorithm_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthParamRand_Present == present) return ED_NO_ERRORS;
	sp->AuthParamRand_Present = present;
	if (present) {
		/*-->*/sp->AuthParamRand = (ED_BYTE*)EDAlloc ((size_t)16);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthParamRand)
		ED_RESET_MEM (sp->AuthParamRand, 16);
	} else {
		EDFree (sp->AuthParamRand);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthParamAutn_Present == present) return ED_NO_ERRORS;
	sp->AuthParamAutn_Present = present;
	if (present) {
		/*-->*/sp->AuthParamAutn = (ED_BYTE*)EDAlloc ((size_t)16);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthParamAutn)
		ED_RESET_MEM (sp->AuthParamAutn, 16);
	} else {
		EDFree (sp->AuthParamAutn);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MsNetwkCpblty_Present == present) return ED_NO_ERRORS;
	sp->MsNetwkCpblty_Present = present;
	if (present) {
		/*-->*/sp->MsNetwkCpblty = (c_MsNetwkCpblty*)EDAlloc (sizeof (c_MsNetwkCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MsNetwkCpblty)
		INIT_c_MsNetwkCpblty (sp->MsNetwkCpblty);
	} else {
		FREE_c_MsNetwkCpblty (sp->MsNetwkCpblty);
		EDFree (sp->MsNetwkCpblty);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->IntegrityProtectionAlgorithm_Present == present) return ED_NO_ERRORS;
	sp->IntegrityProtectionAlgorithm_Present = present;
	if (present) {
		/*-->*/sp->IntegrityProtectionAlgorithm = (c_IntegrityProtectionAlgorithm*)EDAlloc (sizeof (c_IntegrityProtectionAlgorithm));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->IntegrityProtectionAlgorithm)
		INIT_c_IntegrityProtectionAlgorithm (sp->IntegrityProtectionAlgorithm);
	} else {
		FREE_c_IntegrityProtectionAlgorithm (sp->IntegrityProtectionAlgorithm);
		EDFree (sp->IntegrityProtectionAlgorithm);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_AND_CIPHERING_REJECT_DN */
void FREE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_IDENTITY_REQUEST_B_DN */
void FREE_c_IDENTITY_REQUEST_B_DN (c_IDENTITY_REQUEST_B_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ROUTING_AREA_UPDATE_ACCEPT_DN */
void FREE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_GprsTimer (&(sp->PeriodicRaUpdateTimer));
	FREE_c_RoutingAreaIdenti (&(sp->RoutingAreaId));
	if (sp->PTmsiSign_Present) {
		EDFree (sp->PTmsiSign);
		sp->PTmsiSign_Present = ED_FALSE;
	}
	if (sp->AllocatedPTmsi_Present) {
		FREE_c_MobileId (sp->AllocatedPTmsi);
		EDFree (sp->AllocatedPTmsi);
		sp->AllocatedPTmsi_Present = ED_FALSE;
	}
	if (sp->MsId_Present) {
		FREE_c_MobileId (sp->MsId);
		EDFree (sp->MsId);
		sp->MsId_Present = ED_FALSE;
	}
	if (sp->ListOfReceiveNPduNumbers_Present) {
		FREE_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
		EDFree (sp->ListOfReceiveNPduNumbers);
		sp->ListOfReceiveNPduNumbers_Present = ED_FALSE;
	}
	if (sp->NegotiatedRdyTimerValue_Present) {
		FREE_c_GprsTimer (sp->NegotiatedRdyTimerValue);
		EDFree (sp->NegotiatedRdyTimerValue);
		sp->NegotiatedRdyTimerValue_Present = ED_FALSE;
	}
	if (sp->T3302Value_Present) {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
		sp->T3302Value_Present = ED_FALSE;
	}
	if (sp->EquivPlmns_Present) {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
		sp->EquivPlmns_Present = ED_FALSE;
	}
	if (sp->PdpContextStatus_Present) {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
		sp->PdpContextStatus_Present = ED_FALSE;
	}
	if (sp->NetworkFeatureSupport_Present) {
		FREE_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
		EDFree (sp->NetworkFeatureSupport);
		sp->NetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->EmergencyNumberList_Present) {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
		sp->EmergencyNumberList_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}
	if (sp->RequestedMSInformation_Present) {
		FREE_c_RequestedMSInformation (sp->RequestedMSInformation);
		EDFree (sp->RequestedMSInformation);
		sp->RequestedMSInformation_Present = ED_FALSE;
	}
	if (sp->T3319Value_Present) {
		FREE_c_GprsTimer2 (sp->T3319Value);
		EDFree (sp->T3319Value);
		sp->T3319Value_Present = ED_FALSE;
	}
	if (sp->T3323Value_Present) {
		FREE_c_GprsTimer2 (sp->T3323Value);
		EDFree (sp->T3323Value);
		sp->T3323Value_Present = ED_FALSE;
	}
	if (sp->T3312ExtendedValue_Present) {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
		sp->T3312ExtendedValue_Present = ED_FALSE;
	}
	if (sp->AdditionalNetworkFeatureSupport_Present) {
		FREE_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
		EDFree (sp->AdditionalNetworkFeatureSupport);
		sp->AdditionalNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->T3324Value_Present) {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
		sp->T3324Value_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PTmsiSign_Present == present) return ED_NO_ERRORS;
	sp->PTmsiSign_Present = present;
	if (present) {
		/*-->*/sp->PTmsiSign = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PTmsiSign)
		ED_RESET_MEM (sp->PTmsiSign, 3);
	} else {
		EDFree (sp->PTmsiSign);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AllocatedPTmsi_Present == present) return ED_NO_ERRORS;
	sp->AllocatedPTmsi_Present = present;
	if (present) {
		/*-->*/sp->AllocatedPTmsi = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AllocatedPTmsi)
		INIT_c_MobileId (sp->AllocatedPTmsi);
	} else {
		FREE_c_MobileId (sp->AllocatedPTmsi);
		EDFree (sp->AllocatedPTmsi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MsId_Present == present) return ED_NO_ERRORS;
	sp->MsId_Present = present;
	if (present) {
		/*-->*/sp->MsId = (c_MobileId*)EDAlloc (sizeof (c_MobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MsId)
		INIT_c_MobileId (sp->MsId);
	} else {
		FREE_c_MobileId (sp->MsId);
		EDFree (sp->MsId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ListOfReceiveNPduNumbers_Present == present) return ED_NO_ERRORS;
	sp->ListOfReceiveNPduNumbers_Present = present;
	if (present) {
		/*-->*/sp->ListOfReceiveNPduNumbers = (c_ReceiveNPduNumbersList*)EDAlloc (sizeof (c_ReceiveNPduNumbersList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ListOfReceiveNPduNumbers)
		INIT_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
	} else {
		FREE_c_ReceiveNPduNumbersList (sp->ListOfReceiveNPduNumbers);
		EDFree (sp->ListOfReceiveNPduNumbers);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedRdyTimerValue_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedRdyTimerValue_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedRdyTimerValue = (c_GprsTimer*)EDAlloc (sizeof (c_GprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedRdyTimerValue)
		INIT_c_GprsTimer (sp->NegotiatedRdyTimerValue);
	} else {
		FREE_c_GprsTimer (sp->NegotiatedRdyTimerValue);
		EDFree (sp->NegotiatedRdyTimerValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3302Value_Present == present) return ED_NO_ERRORS;
	sp->T3302Value_Present = present;
	if (present) {
		/*-->*/sp->T3302Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3302Value)
		INIT_c_GprsTimer2 (sp->T3302Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EquivPlmns_Present == present) return ED_NO_ERRORS;
	sp->EquivPlmns_Present = present;
	if (present) {
		/*-->*/sp->EquivPlmns = (c_PlmnList*)EDAlloc (sizeof (c_PlmnList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EquivPlmns)
		INIT_c_PlmnList (sp->EquivPlmns);
	} else {
		FREE_c_PlmnList (sp->EquivPlmns);
		EDFree (sp->EquivPlmns);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpContextStatus_Present == present) return ED_NO_ERRORS;
	sp->PdpContextStatus_Present = present;
	if (present) {
		/*-->*/sp->PdpContextStatus = (c_PdpContextStatus*)EDAlloc (sizeof (c_PdpContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpContextStatus)
		INIT_c_PdpContextStatus (sp->PdpContextStatus);
	} else {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->NetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->NetworkFeatureSupport = (c_NetworkFeatureSupport*)EDAlloc (sizeof (c_NetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetworkFeatureSupport)
		INIT_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
	} else {
		FREE_c_NetworkFeatureSupport (sp->NetworkFeatureSupport);
		EDFree (sp->NetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EmergencyNumberList_Present == present) return ED_NO_ERRORS;
	sp->EmergencyNumberList_Present = present;
	if (present) {
		/*-->*/sp->EmergencyNumberList = (c_EmergencyNumberList*)EDAlloc (sizeof (c_EmergencyNumberList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EmergencyNumberList)
		INIT_c_EmergencyNumberList (sp->EmergencyNumberList);
	} else {
		FREE_c_EmergencyNumberList (sp->EmergencyNumberList);
		EDFree (sp->EmergencyNumberList);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RequestedMSInformation_Present == present) return ED_NO_ERRORS;
	sp->RequestedMSInformation_Present = present;
	if (present) {
		/*-->*/sp->RequestedMSInformation = (c_RequestedMSInformation*)EDAlloc (sizeof (c_RequestedMSInformation));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RequestedMSInformation)
		INIT_c_RequestedMSInformation (sp->RequestedMSInformation);
	} else {
		FREE_c_RequestedMSInformation (sp->RequestedMSInformation);
		EDFree (sp->RequestedMSInformation);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3319Value_Present == present) return ED_NO_ERRORS;
	sp->T3319Value_Present = present;
	if (present) {
		/*-->*/sp->T3319Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3319Value)
		INIT_c_GprsTimer2 (sp->T3319Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3319Value);
		EDFree (sp->T3319Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3323Value_Present == present) return ED_NO_ERRORS;
	sp->T3323Value_Present = present;
	if (present) {
		/*-->*/sp->T3323Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3323Value)
		INIT_c_GprsTimer2 (sp->T3323Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3323Value);
		EDFree (sp->T3323Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3312ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3312ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3312ExtendedValue = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3312ExtendedValue)
		INIT_c_GprsTimer3 (sp->T3312ExtendedValue);
	} else {
		FREE_c_GprsTimer3 (sp->T3312ExtendedValue);
		EDFree (sp->T3312ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->AdditionalNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->AdditionalNetworkFeatureSupport = (c_AdditionalNetworkFeatureSupport*)EDAlloc (sizeof (c_AdditionalNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalNetworkFeatureSupport)
		INIT_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
	} else {
		FREE_c_AdditionalNetworkFeatureSupport (sp->AdditionalNetworkFeatureSupport);
		EDFree (sp->AdditionalNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324Value_Present == present) return ED_NO_ERRORS;
	sp->T3324Value_Present = present;
	if (present) {
		/*-->*/sp->T3324Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324Value)
		INIT_c_GprsTimer2 (sp->T3324Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3324Value);
		EDFree (sp->T3324Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_ExtendedDRXParameters*)EDAlloc (sizeof (c_ExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_ExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ROUTING_AREA_UPDATE_REJECT_DN */
void FREE_c_ROUTING_AREA_UPDATE_REJECT_DN (c_ROUTING_AREA_UPDATE_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3302Value_Present) {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
		sp->T3302Value_Present = ED_FALSE;
	}
	if (sp->T3346Value_Present) {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (c_ROUTING_AREA_UPDATE_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3302Value_Present == present) return ED_NO_ERRORS;
	sp->T3302Value_Present = present;
	if (present) {
		/*-->*/sp->T3302Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3302Value)
		INIT_c_GprsTimer2 (sp->T3302Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3302Value);
		EDFree (sp->T3302Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (c_ROUTING_AREA_UPDATE_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_GprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GMM_INFORMATION_DN */
void FREE_c_GMM_INFORMATION_DN (c_GMM_INFORMATION_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->FullNameForNetwk_Present) {
		FREE_c_NetwkName (sp->FullNameForNetwk);
		EDFree (sp->FullNameForNetwk);
		sp->FullNameForNetwk_Present = ED_FALSE;
	}
	if (sp->ShortNameForNetwk_Present) {
		FREE_c_NetwkName (sp->ShortNameForNetwk);
		EDFree (sp->ShortNameForNetwk);
		sp->ShortNameForNetwk_Present = ED_FALSE;
	}
	if (sp->UniversalTimeAndLocalTimeZone_Present) {
		FREE_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
		sp->UniversalTimeAndLocalTimeZone_Present = ED_FALSE;
	}
	if (sp->LsaId_Present) {
		if (sp->LsaId->value != NULL) {
			EDFree (sp->LsaId->value);
			sp->LsaId->value = NULL;
		}
		sp->LsaId->usedBits = 0;
		EDFree (sp->LsaId);
		sp->LsaId_Present = ED_FALSE;
	}
	if (sp->NetwkDaylightSavingTime_Present) {
		FREE_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
		EDFree (sp->NetwkDaylightSavingTime);
		sp->NetwkDaylightSavingTime_Present = ED_FALSE;
	}

}

int SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FullNameForNetwk_Present == present) return ED_NO_ERRORS;
	sp->FullNameForNetwk_Present = present;
	if (present) {
		/*-->*/sp->FullNameForNetwk = (c_NetwkName*)EDAlloc (sizeof (c_NetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FullNameForNetwk)
		INIT_c_NetwkName (sp->FullNameForNetwk);
	} else {
		FREE_c_NetwkName (sp->FullNameForNetwk);
		EDFree (sp->FullNameForNetwk);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ShortNameForNetwk_Present == present) return ED_NO_ERRORS;
	sp->ShortNameForNetwk_Present = present;
	if (present) {
		/*-->*/sp->ShortNameForNetwk = (c_NetwkName*)EDAlloc (sizeof (c_NetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ShortNameForNetwk)
		INIT_c_NetwkName (sp->ShortNameForNetwk);
	} else {
		FREE_c_NetwkName (sp->ShortNameForNetwk);
		EDFree (sp->ShortNameForNetwk);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UniversalTimeAndLocalTimeZone_Present == present) return ED_NO_ERRORS;
	sp->UniversalTimeAndLocalTimeZone_Present = present;
	if (present) {
		/*-->*/sp->UniversalTimeAndLocalTimeZone = (c_TimeZoneAndTime*)EDAlloc (sizeof (c_TimeZoneAndTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UniversalTimeAndLocalTimeZone)
		INIT_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
	} else {
		FREE_c_TimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_GMM_INFORMATION_DN_LsaId (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LsaId_Present == present) return ED_NO_ERRORS;
	sp->LsaId_Present = present;
	if (present) {
		/*-->*/sp->LsaId = (c_GMM_INFORMATION_DN_LsaId*)EDAlloc (sizeof (c_GMM_INFORMATION_DN_LsaId));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LsaId)
		
		sp->LsaId->value = NULL;
		sp->LsaId->usedBits = 0;
	} else {
		if (sp->LsaId->value != NULL) {
			EDFree (sp->LsaId->value);
			sp->LsaId->value = NULL;
		}
		sp->LsaId->usedBits = 0;
		EDFree (sp->LsaId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetwkDaylightSavingTime_Present == present) return ED_NO_ERRORS;
	sp->NetwkDaylightSavingTime_Present = present;
	if (present) {
		/*-->*/sp->NetwkDaylightSavingTime = (c_DaylightSavingTime*)EDAlloc (sizeof (c_DaylightSavingTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetwkDaylightSavingTime)
		INIT_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
	} else {
		FREE_c_DaylightSavingTime (sp->NetwkDaylightSavingTime);
		EDFree (sp->NetwkDaylightSavingTime);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SERVICE_ACCEPT_DN */
void FREE_c_SERVICE_ACCEPT_DN (c_SERVICE_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->PdpContextStatus_Present) {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
		sp->PdpContextStatus_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (c_SERVICE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpContextStatus_Present == present) return ED_NO_ERRORS;
	sp->PdpContextStatus_Present = present;
	if (present) {
		/*-->*/sp->PdpContextStatus = (c_PdpContextStatus*)EDAlloc (sizeof (c_PdpContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpContextStatus)
		INIT_c_PdpContextStatus (sp->PdpContextStatus);
	} else {
		FREE_c_PdpContextStatus (sp->PdpContextStatus);
		EDFree (sp->PdpContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (c_SERVICE_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_SERVICE_ACCEPT_DN_MBMSContextStatus*)EDAlloc (sizeof (c_SERVICE_ACCEPT_DN_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SERVICE_REJECT_DN */
void FREE_c_SERVICE_REJECT_DN (c_SERVICE_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3346Value_Present) {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (c_SERVICE_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_GprsTimer2*)EDAlloc (sizeof (c_GprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_GprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_GprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_PDP_CONTEXT_REQUEST_UP */
void FREE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NetwkServAccessPointId (&(sp->ReqNsapi));
	FREE_c_LlcServAccessPointId (&(sp->ReqLlcSapi));
	FREE_c_QualityOfServ (&(sp->ReqQos));
	FREE_c_PacketDataProtocolAddr (&(sp->ReqPdpAddr));
	if (sp->AccessPointName_Present) {
		FREE_c_ASCII (sp->AccessPointName);
		EDFree (sp->AccessPointName);
		sp->AccessPointName_Present = ED_FALSE;
	}
	if (sp->ProtocolCfgOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
		sp->ProtocolCfgOpt_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AccessPointName_Present == present) return ED_NO_ERRORS;
	sp->AccessPointName_Present = present;
	if (present) {
		/*-->*/sp->AccessPointName = (c_ASCII*)EDAlloc (sizeof (c_ASCII));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AccessPointName)
		INIT_c_ASCII (sp->AccessPointName);
	} else {
		FREE_c_ASCII (sp->AccessPointName);
		EDFree (sp->AccessPointName);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolCfgOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolCfgOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolCfgOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolCfgOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP */
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NetwkServAccessPointId (&(sp->ReqNsapi));
	FREE_c_LlcServAccessPointId (&(sp->ReqLlcSapi));
	FREE_c_QualityOfServ (&(sp->ReqQos));
	FREE_c_LinkedTi (&(sp->LinkedTi));
	if (sp->Tft_Present) {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
		sp->Tft_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Tft_Present == present) return ED_NO_ERRORS;
	sp->Tft_Present = present;
	if (present) {
		/*-->*/sp->Tft = (c_TrafficFlowTemplate*)EDAlloc (sizeof (c_TrafficFlowTemplate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Tft)
		INIT_c_TrafficFlowTemplate (sp->Tft);
	} else {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP */
void FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer*)EDAlloc (sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_PDP_CONTEXT_REQUEST_UP */
void FREE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ReqLlcSapi_Present) {
		FREE_c_LlcServAccessPointId (sp->ReqLlcSapi);
		EDFree (sp->ReqLlcSapi);
		sp->ReqLlcSapi_Present = ED_FALSE;
	}
	if (sp->ReqNewQos_Present) {
		FREE_c_QualityOfServ (sp->ReqNewQos);
		EDFree (sp->ReqNewQos);
		sp->ReqNewQos_Present = ED_FALSE;
	}
	if (sp->NewTft_Present) {
		FREE_c_TrafficFlowTemplate (sp->NewTft);
		EDFree (sp->NewTft);
		sp->NewTft_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReqLlcSapi_Present == present) return ED_NO_ERRORS;
	sp->ReqLlcSapi_Present = present;
	if (present) {
		/*-->*/sp->ReqLlcSapi = (c_LlcServAccessPointId*)EDAlloc (sizeof (c_LlcServAccessPointId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReqLlcSapi)
		INIT_c_LlcServAccessPointId (sp->ReqLlcSapi);
	} else {
		FREE_c_LlcServAccessPointId (sp->ReqLlcSapi);
		EDFree (sp->ReqLlcSapi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReqNewQos_Present == present) return ED_NO_ERRORS;
	sp->ReqNewQos_Present = present;
	if (present) {
		/*-->*/sp->ReqNewQos = (c_QualityOfServ*)EDAlloc (sizeof (c_QualityOfServ));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReqNewQos)
		INIT_c_QualityOfServ (sp->ReqNewQos);
	} else {
		FREE_c_QualityOfServ (sp->ReqNewQos);
		EDFree (sp->ReqNewQos);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NewTft_Present == present) return ED_NO_ERRORS;
	sp->NewTft_Present = present;
	if (present) {
		/*-->*/sp->NewTft = (c_TrafficFlowTemplate*)EDAlloc (sizeof (c_TrafficFlowTemplate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NewTft)
		INIT_c_TrafficFlowTemplate (sp->NewTft);
	} else {
		FREE_c_TrafficFlowTemplate (sp->NewTft);
		EDFree (sp->NewTft);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_PDP_CONTEXT_ACCEPT_UP */
void FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DEACTIVATE_PDP_CONTEXT_REQUEST */
void FREE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->TearDownInd_Present) {
		FREE_c_TearDownInd (sp->TearDownInd);
		EDFree (sp->TearDownInd);
		sp->TearDownInd_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}
	if (sp->T3396Value_Present) {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
		sp->T3396Value_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TearDownInd_Present == present) return ED_NO_ERRORS;
	sp->TearDownInd_Present = present;
	if (present) {
		/*-->*/sp->TearDownInd = (c_TearDownInd*)EDAlloc (sizeof (c_TearDownInd));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TearDownInd)
		INIT_c_TearDownInd (sp->TearDownInd);
	} else {
		FREE_c_TearDownInd (sp->TearDownInd);
		EDFree (sp->TearDownInd);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3396Value_Present == present) return ED_NO_ERRORS;
	sp->T3396Value_Present = present;
	if (present) {
		/*-->*/sp->T3396Value = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3396Value)
		INIT_c_GprsTimer3 (sp->T3396Value);
	} else {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DEACTIVATE_PDP_CONTEXT_ACCEPT */
void FREE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->MBMSContextStatus_Present) {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
		sp->MBMSContextStatus_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSContextStatus_Present == present) return ED_NO_ERRORS;
	sp->MBMSContextStatus_Present = present;
	if (present) {
		/*-->*/sp->MBMSContextStatus = (c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSContextStatus)
		
		sp->MBMSContextStatus->value = NULL;
		sp->MBMSContextStatus->usedBits = 0;
	} else {
		if (sp->MBMSContextStatus->value != NULL) {
			EDFree (sp->MBMSContextStatus->value);
			sp->MBMSContextStatus->value = NULL;
		}
		sp->MBMSContextStatus->usedBits = 0;
		EDFree (sp->MBMSContextStatus);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT */
void FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->ProtocolCfgOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
		sp->ProtocolCfgOpt_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolCfgOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolCfgOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolCfgOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolCfgOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SM_STATUS */
void FREE_c_SM_STATUS (c_SM_STATUS* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));

}

/* Free function for struct c_ACTIVATE_MBMS_CONTEXT_REQUEST */
void FREE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LlcServAccessPointId (&(sp->ReqLlcSapi));
	FREE_c_MBMSBearerCapabilities (&(sp->SupportedMBMSBearerCapabilities));
	FREE_c_PacketDataProtocolAddr (&(sp->RequestedMulticastAddress));
	if (sp->AccessPointName.value != NULL) {
		EDFree (sp->AccessPointName.value);
		sp->AccessPointName.value = NULL;
	}
	sp->AccessPointName.usedBits = 0;
	if (sp->MBMSProtocolConfigOpts_Present) {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
		sp->MBMSProtocolConfigOpts_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSProtocolConfigOpts_Present == present) return ED_NO_ERRORS;
	sp->MBMSProtocolConfigOpts_Present = present;
	if (present) {
		/*-->*/sp->MBMSProtocolConfigOpts = (c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSProtocolConfigOpts)
		
		sp->MBMSProtocolConfigOpts->value = NULL;
		sp->MBMSProtocolConfigOpts->usedBits = 0;
	} else {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties (c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_DeviceProperties*)EDAlloc (sizeof (c_DeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_DeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_DeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT */
void FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->MBMSProtocolConfigOpts_Present) {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
		sp->MBMSProtocolConfigOpts_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSProtocolConfigOpts_Present == present) return ED_NO_ERRORS;
	sp->MBMSProtocolConfigOpts_Present = present;
	if (present) {
		/*-->*/sp->MBMSProtocolConfigOpts = (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts*)EDAlloc (sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSProtocolConfigOpts)
		
		sp->MBMSProtocolConfigOpts->value = NULL;
		sp->MBMSProtocolConfigOpts->usedBits = 0;
	} else {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN */
void FREE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LlcServAccessPointId (&(sp->NegotiatedLlcSapi));
	FREE_c_QualityOfServ (&(sp->NegotiatedQos));
	if (sp->PdpAddr_Present) {
		FREE_c_PacketDataProtocolAddr (sp->PdpAddr);
		EDFree (sp->PdpAddr);
		sp->PdpAddr_Present = ED_FALSE;
	}
	if (sp->ProtocolCfgOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
		sp->ProtocolCfgOpt_Present = ED_FALSE;
	}
	if (sp->PacketFlowId_Present) {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
		sp->PacketFlowId_Present = ED_FALSE;
	}
	if (sp->SMCause_Present) {
		FREE_c_SMCause (sp->SMCause);
		EDFree (sp->SMCause);
		sp->SMCause_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpAddr_Present == present) return ED_NO_ERRORS;
	sp->PdpAddr_Present = present;
	if (present) {
		/*-->*/sp->PdpAddr = (c_PacketDataProtocolAddr*)EDAlloc (sizeof (c_PacketDataProtocolAddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpAddr)
		INIT_c_PacketDataProtocolAddr (sp->PdpAddr);
	} else {
		FREE_c_PacketDataProtocolAddr (sp->PdpAddr);
		EDFree (sp->PdpAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolCfgOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolCfgOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolCfgOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolCfgOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowId_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowId_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowId = (c_PacketFlowIdentifie*)EDAlloc (sizeof (c_PacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowId)
		INIT_c_PacketFlowIdentifie (sp->PacketFlowId);
	} else {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SMCause_Present == present) return ED_NO_ERRORS;
	sp->SMCause_Present = present;
	if (present) {
		/*-->*/sp->SMCause = (c_SMCause*)EDAlloc (sizeof (c_SMCause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SMCause)
		INIT_c_SMCause (sp->SMCause);
	} else {
		FREE_c_SMCause (sp->SMCause);
		EDFree (sp->SMCause);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_PDP_CONTEXT_REJECT_DN */
void FREE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->ProtocolCfgOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
		sp->ProtocolCfgOpt_Present = ED_FALSE;
	}
	if (sp->T3396Value_Present) {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
		sp->T3396Value_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
		sp->ReAttemptIndicator_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolCfgOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolCfgOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolCfgOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolCfgOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolCfgOpt);
		EDFree (sp->ProtocolCfgOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3396Value_Present == present) return ED_NO_ERRORS;
	sp->T3396Value_Present = present;
	if (present) {
		/*-->*/sp->T3396Value = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3396Value)
		INIT_c_GprsTimer3 (sp->T3396Value);
	} else {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_ReAttemptIndicator*)EDAlloc (sizeof (c_ReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_ReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN */
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LlcServAccessPointId (&(sp->NegotiatedLlcSapi));
	FREE_c_QualityOfServ (&(sp->NegotiatedQos));
	if (sp->PacketFlowId_Present) {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
		sp->PacketFlowId_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowId_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowId_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowId = (c_PacketFlowIdentifie*)EDAlloc (sizeof (c_PacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowId)
		INIT_c_PacketFlowIdentifie (sp->PacketFlowId);
	} else {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN */
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->T3396Value_Present) {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
		sp->T3396Value_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
		sp->ReAttemptIndicator_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3396Value_Present == present) return ED_NO_ERRORS;
	sp->T3396Value_Present = present;
	if (present) {
		/*-->*/sp->T3396Value = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3396Value)
		INIT_c_GprsTimer3 (sp->T3396Value);
	} else {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_ReAttemptIndicator*)EDAlloc (sizeof (c_ReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_ReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_PDP_CONTEXT_ACTIVATION_DN */
void FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_PacketDataProtocolAddr (&(sp->OfferedPdpAddr));
	if (sp->AccessPointName_Present) {
		if (sp->AccessPointName->value != NULL) {
			EDFree (sp->AccessPointName->value);
			sp->AccessPointName->value = NULL;
		}
		sp->AccessPointName->usedBits = 0;
		EDFree (sp->AccessPointName);
		sp->AccessPointName_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AccessPointName_Present == present) return ED_NO_ERRORS;
	sp->AccessPointName_Present = present;
	if (present) {
		/*-->*/sp->AccessPointName = (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName*)EDAlloc (sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AccessPointName)
		
		sp->AccessPointName->value = NULL;
		sp->AccessPointName->usedBits = 0;
	} else {
		if (sp->AccessPointName->value != NULL) {
			EDFree (sp->AccessPointName->value);
			sp->AccessPointName->value = NULL;
		}
		sp->AccessPointName->usedBits = 0;
		EDFree (sp->AccessPointName);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer*)EDAlloc (sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_PDP_CONTEXT_REQUEST_DN */
void FREE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_LlcServAccessPointId (&(sp->ReqLlcSapi));
	FREE_c_QualityOfServ (&(sp->NewQos));
	if (sp->PdpAddr_Present) {
		FREE_c_PacketDataProtocolAddr (sp->PdpAddr);
		EDFree (sp->PdpAddr);
		sp->PdpAddr_Present = ED_FALSE;
	}
	if (sp->PacketFlowId_Present) {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
		sp->PacketFlowId_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->Tft_Present) {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
		sp->Tft_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PdpAddr_Present == present) return ED_NO_ERRORS;
	sp->PdpAddr_Present = present;
	if (present) {
		/*-->*/sp->PdpAddr = (c_PacketDataProtocolAddr*)EDAlloc (sizeof (c_PacketDataProtocolAddr));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PdpAddr)
		INIT_c_PacketDataProtocolAddr (sp->PdpAddr);
	} else {
		FREE_c_PacketDataProtocolAddr (sp->PdpAddr);
		EDFree (sp->PdpAddr);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowId_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowId_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowId = (c_PacketFlowIdentifie*)EDAlloc (sizeof (c_PacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowId)
		INIT_c_PacketFlowIdentifie (sp->PacketFlowId);
	} else {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Tft_Present == present) return ED_NO_ERRORS;
	sp->Tft_Present = present;
	if (present) {
		/*-->*/sp->Tft = (c_TrafficFlowTemplate*)EDAlloc (sizeof (c_TrafficFlowTemplate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Tft)
		INIT_c_TrafficFlowTemplate (sp->Tft);
	} else {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_PDP_CONTEXT_ACCEPT_DN */
void FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NegotiatedQos_Present) {
		FREE_c_QualityOfServ (sp->NegotiatedQos);
		EDFree (sp->NegotiatedQos);
		sp->NegotiatedQos_Present = ED_FALSE;
	}
	if (sp->NegotiatedLlcSapi_Present) {
		FREE_c_LlcServAccessPointId (sp->NegotiatedLlcSapi);
		EDFree (sp->NegotiatedLlcSapi);
		sp->NegotiatedLlcSapi_Present = ED_FALSE;
	}
	if (sp->PacketFlowId_Present) {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
		sp->PacketFlowId_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedQos_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedQos_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedQos = (c_QualityOfServ*)EDAlloc (sizeof (c_QualityOfServ));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedQos)
		INIT_c_QualityOfServ (sp->NegotiatedQos);
	} else {
		FREE_c_QualityOfServ (sp->NegotiatedQos);
		EDFree (sp->NegotiatedQos);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedLlcSapi_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedLlcSapi_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedLlcSapi = (c_LlcServAccessPointId*)EDAlloc (sizeof (c_LlcServAccessPointId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedLlcSapi)
		INIT_c_LlcServAccessPointId (sp->NegotiatedLlcSapi);
	} else {
		FREE_c_LlcServAccessPointId (sp->NegotiatedLlcSapi);
		EDFree (sp->NegotiatedLlcSapi);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowId_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowId_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowId = (c_PacketFlowIdentifie*)EDAlloc (sizeof (c_PacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowId)
		INIT_c_PacketFlowIdentifie (sp->PacketFlowId);
	} else {
		FREE_c_PacketFlowIdentifie (sp->PacketFlowId);
		EDFree (sp->PacketFlowId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_PDP_CONTEXT_REJECT_DN */
void FREE_c_MODIFY_PDP_CONTEXT_REJECT_DN (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->T3396Value_Present) {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
		sp->T3396Value_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
		sp->ReAttemptIndicator_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3396Value_Present == present) return ED_NO_ERRORS;
	sp->T3396Value_Present = present;
	if (present) {
		/*-->*/sp->T3396Value = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3396Value)
		INIT_c_GprsTimer3 (sp->T3396Value);
	} else {
		FREE_c_GprsTimer3 (sp->T3396Value);
		EDFree (sp->T3396Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_ReAttemptIndicator*)EDAlloc (sizeof (c_ReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_ReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION */
void FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_QualityOfServ (&(sp->ReqQos));
	FREE_c_LinkedTi (&(sp->LinkedTi));
	if (sp->Tft_Present) {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
		sp->Tft_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigOpt_Present) {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
		sp->ProtocolConfigOpt_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
		sp->WLANOffloadIndication_Present = ED_FALSE;
	}
	if (sp->NBIFOMContainer_Present) {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
		sp->NBIFOMContainer_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Tft_Present == present) return ED_NO_ERRORS;
	sp->Tft_Present = present;
	if (present) {
		/*-->*/sp->Tft = (c_TrafficFlowTemplate*)EDAlloc (sizeof (c_TrafficFlowTemplate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Tft)
		INIT_c_TrafficFlowTemplate (sp->Tft);
	} else {
		FREE_c_TrafficFlowTemplate (sp->Tft);
		EDFree (sp->Tft);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigOpt_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigOpt_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigOpt = (c_ProtocolCfgOpt*)EDAlloc (sizeof (c_ProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigOpt)
		INIT_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
	} else {
		FREE_c_ProtocolCfgOpt (sp->ProtocolConfigOpt);
		EDFree (sp->ProtocolConfigOpt);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_WLANOffloadAcceptability*)EDAlloc (sizeof (c_WLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_WLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer*)EDAlloc (sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
		sp->NBIFOMContainer->value = NULL;
		sp->NBIFOMContainer->usedBits = 0;
	} else {
		if (sp->NBIFOMContainer->value != NULL) {
			EDFree (sp->NBIFOMContainer->value);
			sp->NBIFOMContainer->value = NULL;
		}
		sp->NBIFOMContainer->usedBits = 0;
		EDFree (sp->NBIFOMContainer);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_NOTIFICATION */
void FREE_c_NOTIFICATION (c_NOTIFICATION* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ACTIVATE_MBMS_CONTEXT_ACCEPT */
void FREE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (c_ACTIVATE_MBMS_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_TempMobileGroupId (&(sp->TempMobileGroupId));
	FREE_c_LlcServAccessPointId (&(sp->NegotiatedLlcSapi));
	if (sp->MBMSProtocolConfigOpts_Present) {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
		sp->MBMSProtocolConfigOpts_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSProtocolConfigOpts_Present == present) return ED_NO_ERRORS;
	sp->MBMSProtocolConfigOpts_Present = present;
	if (present) {
		/*-->*/sp->MBMSProtocolConfigOpts = (c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSProtocolConfigOpts)
		
		sp->MBMSProtocolConfigOpts->value = NULL;
		sp->MBMSProtocolConfigOpts->usedBits = 0;
	} else {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_MBMS_CONTEXT_REJECT */
void FREE_c_ACTIVATE_MBMS_CONTEXT_REJECT (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_SMCause (&(sp->SmCause));
	if (sp->MBMSProtocolConfigOpts_Present) {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
		sp->MBMSProtocolConfigOpts_Present = ED_FALSE;
	}
	if (sp->BackOffTimerValue_Present) {
		FREE_c_GprsTimer3 (sp->BackOffTimerValue);
		EDFree (sp->BackOffTimerValue);
		sp->BackOffTimerValue_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
		sp->ReAttemptIndicator_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSProtocolConfigOpts_Present == present) return ED_NO_ERRORS;
	sp->MBMSProtocolConfigOpts_Present = present;
	if (present) {
		/*-->*/sp->MBMSProtocolConfigOpts = (c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSProtocolConfigOpts)
		
		sp->MBMSProtocolConfigOpts->value = NULL;
		sp->MBMSProtocolConfigOpts->usedBits = 0;
	} else {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BackOffTimerValue_Present == present) return ED_NO_ERRORS;
	sp->BackOffTimerValue_Present = present;
	if (present) {
		/*-->*/sp->BackOffTimerValue = (c_GprsTimer3*)EDAlloc (sizeof (c_GprsTimer3));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BackOffTimerValue)
		INIT_c_GprsTimer3 (sp->BackOffTimerValue);
	} else {
		FREE_c_GprsTimer3 (sp->BackOffTimerValue);
		EDFree (sp->BackOffTimerValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_ReAttemptIndicator*)EDAlloc (sizeof (c_ReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_ReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_ReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REQUEST_MBMS_CONTEXT_ACTIVATION */
void FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (c_REQUEST_MBMS_CONTEXT_ACTIVATION* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NetwkServAccessPointId (&(sp->LinkedNSAPI));
	FREE_c_PacketDataProtocolAddr (&(sp->OfferedMulticastAddr));
	if (sp->AccessPointName.value != NULL) {
		EDFree (sp->AccessPointName.value);
		sp->AccessPointName.value = NULL;
	}
	sp->AccessPointName.usedBits = 0;
	if (sp->MBMSProtocolConfigOpts_Present) {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
		sp->MBMSProtocolConfigOpts_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (c_REQUEST_MBMS_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MBMSProtocolConfigOpts_Present == present) return ED_NO_ERRORS;
	sp->MBMSProtocolConfigOpts_Present = present;
	if (present) {
		/*-->*/sp->MBMSProtocolConfigOpts = (c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts*)EDAlloc (sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MBMSProtocolConfigOpts)
		
		sp->MBMSProtocolConfigOpts->value = NULL;
		sp->MBMSProtocolConfigOpts->usedBits = 0;
	} else {
		if (sp->MBMSProtocolConfigOpts->value != NULL) {
			EDFree (sp->MBMSProtocolConfigOpts->value);
			sp->MBMSProtocolConfigOpts->value = NULL;
		}
		sp->MBMSProtocolConfigOpts->usedBits = 0;
		EDFree (sp->MBMSProtocolConfigOpts);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GenericTLV_L3 */
void FREE_c_GenericTLV_L3 (c_GenericTLV_L3* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TLV_Data.value != NULL) {
		EDFree (sp->TLV_Data.value);
		sp->TLV_Data.value = NULL;
	}
	sp->TLV_Data.usedBits = 0;

}

/* SETITEMS commands for type 'c_MobileId_Identity_IdentityDigit'. Existing items are not changed. */
int SETITEMS_c_MobileId_Identity_IdentityDigit (c_MobileId_Identity_IdentityDigit* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_TBCDEmergencyNumber_Numbers'. Existing items are not changed. */
int SETITEMS_c_TBCDEmergencyNumber_Numbers (c_TBCDEmergencyNumber_Numbers* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_ReceiveNPduNumbersList_sapi'. Existing items are not changed. */
int SETITEMS_c_ReceiveNPduNumbersList_sapi (c_ReceiveNPduNumbersList_sapi* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value'. Existing items are not changed. */
int SETITEMS_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value (c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value* sequence, int desiredItems)
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

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part (c_MsRadioAccessCpblty_MS_RA_capability_value_part* sp) {
	int i0;
	int i1;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->MS_RA_capability_value.items; i0++) {
		if (sp->MS_RA_capability_value.data[i0]->Access_capabilities_Present) {
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits_Present) {
				EDFree (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits);
				sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.A5_bits = NULL;
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.ES_IND_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.PS_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.VGCS_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.VBS_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
				}
				EDFree (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability);
				sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Length_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
				}
				EDFree (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
				sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
				}
				if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
				}
				EDFree (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability);
				sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
			}
			if (sp->MS_RA_capability_value.data[i0]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
			}
			EDFree (sp->MS_RA_capability_value.data[i0]->Access_capabilities);
			sp->MS_RA_capability_value.data[i0]->Access_capabilities = NULL;
		}
		if (sp->MS_RA_capability_value.data[i0]->Length_Present) {
		}
		for (i1=0; i1<sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.items; i1++) {
			EDFree (sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data[i1]);
			sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data[i1] = NULL;
		}
		if (sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data) {EDFree (sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data); sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data = NULL; sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.allocatedItems=0; /*FR02A*/}
		if (sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR) {EDFree (sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR); sp->MS_RA_capability_value.data[i0]->Additional_access_technologies.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->MS_RA_capability_value.data[i0]);
		sp->MS_RA_capability_value.data[i0] = NULL;
	}
	if (sp->MS_RA_capability_value.data) {EDFree (sp->MS_RA_capability_value.data); sp->MS_RA_capability_value.data = NULL; sp->MS_RA_capability_value.allocatedItems=0; /*FR02A*/}
	if (sp->MS_RA_capability_value.data___LOCATOR) {EDFree (sp->MS_RA_capability_value.data___LOCATOR); sp->MS_RA_capability_value.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value'. Existing items are not changed. */
int SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value* sequence, int desiredItems)
{
	int i, i0;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data** tmp;
		tmp = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data**)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data));
			(sequence->data[i]->Access_Technology_Type) = 0;
			sequence->data[i]->Additional_access_technologies.items = 0;
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->Access_capabilities_Present) {
					if (sequence->data[i]->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.A5_bits_Present) {
						EDFree (sequence->data[i]->Access_capabilities->Access_capabilities.A5_bits);
						sequence->data[i]->Access_capabilities->Access_capabilities.A5_bits = NULL;
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.ES_IND_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.PS_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.VGCS_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.VBS_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
						}
						EDFree (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability);
						sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Length_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
						}
						EDFree (sequence->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
						sequence->data[i]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
						if (sequence->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
						}
						if (sequence->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
						}
						EDFree (sequence->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability);
						sequence->data[i]->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
					}
					if (sequence->data[i]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
					}
					EDFree (sequence->data[i]->Access_capabilities);
					sequence->data[i]->Access_capabilities = NULL;
				}
				if (sequence->data[i]->Length_Present) {
				}
				for (i0=0; i0<sequence->data[i]->Additional_access_technologies.items; i0++) {
					EDFree (sequence->data[i]->Additional_access_technologies.data[i0]);
					sequence->data[i]->Additional_access_technologies.data[i0] = NULL;
				}
				if (sequence->data[i]->Additional_access_technologies.data) {EDFree (sequence->data[i]->Additional_access_technologies.data); sequence->data[i]->Additional_access_technologies.data = NULL; sequence->data[i]->Additional_access_technologies.allocatedItems=0; /*FR02A*/}
				if (sequence->data[i]->Additional_access_technologies.data___LOCATOR) {EDFree (sequence->data[i]->Additional_access_technologies.data___LOCATOR); sequence->data[i]->Additional_access_technologies.data___LOCATOR = NULL; /*FR02AL*/}
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	if (sp->Access_capabilities_Present) {
		if (sp->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.A5_bits_Present) {
			EDFree (sp->Access_capabilities->Access_capabilities.A5_bits);
			sp->Access_capabilities->Access_capabilities.A5_bits = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.ES_IND_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.PS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.VGCS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.VBS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.Multislot_capability);
			sp->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Length_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
			if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
			sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
			if (sp->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.DLMC_Capability);
			sp->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
		}
		EDFree (sp->Access_capabilities);
		sp->Access_capabilities = NULL;
		sp->Access_capabilities_Present = ED_FALSE;
	}
	for (i0=0; i0<sp->Additional_access_technologies.items; i0++) {
		EDFree (sp->Additional_access_technologies.data[i0]);
		sp->Additional_access_technologies.data[i0] = NULL;
	}
	if (sp->Additional_access_technologies.data) {EDFree (sp->Additional_access_technologies.data); sp->Additional_access_technologies.data = NULL; sp->Additional_access_technologies.allocatedItems=0; /*FR02A*/}
	if (sp->Additional_access_technologies.data___LOCATOR) {EDFree (sp->Additional_access_technologies.data___LOCATOR); sp->Additional_access_technologies.data___LOCATOR = NULL; /*FR02AL*/}

}

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Access_capabilities_Present == present) return ED_NO_ERRORS;
	sp->Access_capabilities_Present = present;
	if (present) {
		/*-->*/sp->Access_capabilities = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Access_capabilities)
		ED_RESET_MEM (sp->Access_capabilities, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities));
		(sp->Access_capabilities->Length) = 0;
	} else {
		if (sp->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.A5_bits_Present) {
			EDFree (sp->Access_capabilities->Access_capabilities.A5_bits);
			sp->Access_capabilities->Access_capabilities.A5_bits = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.ES_IND_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.PS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.VGCS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.VBS_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multislot_capability_Present) {
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.Multislot_capability);
			sp->Access_capabilities->Access_capabilities.Multislot_capability = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Length_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
			if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
			sp->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.EMST_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.MTTI_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DTR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.EMSR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.FANR_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.IPA_Capability_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.DLMC_Capability_Present) {
			if (sp->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
			}
			if (sp->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
			}
			EDFree (sp->Access_capabilities->Access_capabilities.DLMC_Capability);
			sp->Access_capabilities->Access_capabilities.DLMC_Capability = NULL;
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
		}
		if (sp->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) {
		}
		EDFree (sp->Access_capabilities);
		sp->Access_capabilities = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Access_capabilities.RF_Power_Capability_Present) {
	}
	if (sp->Access_capabilities.A5_bits_Present) {
		EDFree (sp->Access_capabilities.A5_bits);
		sp->Access_capabilities.A5_bits = NULL;
	}
	if (sp->Access_capabilities.ES_IND_Present) {
	}
	if (sp->Access_capabilities.PS_Present) {
	}
	if (sp->Access_capabilities.VGCS_Present) {
	}
	if (sp->Access_capabilities.VBS_Present) {
	}
	if (sp->Access_capabilities.Multislot_capability_Present) {
		if (sp->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->SMS_VALUE_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->SM_VALUE_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) {
		}
		if (sp->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
		}
		EDFree (sp->Access_capabilities.Multislot_capability);
		sp->Access_capabilities.Multislot_capability = NULL;
	}
	if (sp->Access_capabilities._8PSK_Power_Capability_Present) {
	}
	if (sp->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) {
	}
	if (sp->Access_capabilities.Revision_Level_Indicator_Present) {
	}
	if (sp->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) {
	}
	if (sp->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
	}
	if (sp->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) {
	}
	if (sp->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) {
	}
	if (sp->Access_capabilities.GERAN_Feature_Package_1_Present) {
	}
	if (sp->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) {
	}
	if (sp->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) {
	}
	if (sp->Access_capabilities.Modulation_based_multislot_class_support_Present) {
	}
	if (sp->Access_capabilities.High_Multislot_Capability_Present) {
	}
	if (sp->Access_capabilities.Length_Present) {
	}
	if (sp->Access_capabilities.FLO_Iu_Capability_Present) {
	}
	if (sp->Access_capabilities.GMSK_Multislot_Power_Profile_Present) {
	}
	if (sp->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) {
	}
	if (sp->Access_capabilities.Multiple_TBF_Capability_Present) {
	}
	if (sp->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) {
	}
	if (sp->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) {
	}
	if (sp->Access_capabilities.DTM_Enhancements_Capability_Present) {
	}
	if (sp->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) {
	}
	if (sp->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) {
	}
	if (sp->Access_capabilities.PS_Handover_Capability_Present) {
	}
	if (sp->Access_capabilities.DTM_Handover_Capability_Present) {
	}
	if (sp->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
	}
	if (sp->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) {
	}
	if (sp->Access_capabilities.Flexible_Timeslot_Assignment_Present) {
	}
	if (sp->Access_capabilities.GAN_PS_Handover_Capability_Present) {
	}
	if (sp->Access_capabilities.RLC_Non_persistent_Mode_Present) {
	}
	if (sp->Access_capabilities.Reduced_Latency_Capability_Present) {
	}
	if (sp->Access_capabilities.Uplink_EGPRS2_Present) {
	}
	if (sp->Access_capabilities.Downlink_EGPRS2_Present) {
	}
	if (sp->Access_capabilities.E_UTRA_FDD_support_Present) {
	}
	if (sp->Access_capabilities.E_UTRA_TDD_support_Present) {
	}
	if (sp->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) {
	}
	if (sp->Access_capabilities.Priority_based_reselection_support_Present) {
	}
	if (sp->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) {
		if (sp->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
		}
		if (sp->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
		}
		EDFree (sp->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment);
		sp->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment = NULL;
	}
	if (sp->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) {
	}
	if (sp->Access_capabilities.EMST_Capability_Present) {
	}
	if (sp->Access_capabilities.MTTI_Capability_Present) {
	}
	if (sp->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) {
	}
	if (sp->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) {
	}
	if (sp->Access_capabilities.DTR_Capability_Present) {
	}
	if (sp->Access_capabilities.EMSR_Capability_Present) {
	}
	if (sp->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) {
	}
	if (sp->Access_capabilities.TIGHTER_Capability_Present) {
	}
	if (sp->Access_capabilities.FANR_Capability_Present) {
	}
	if (sp->Access_capabilities.IPA_Capability_Present) {
	}
	if (sp->Access_capabilities.GERAN_Network_Sharing_support_Present) {
	}
	if (sp->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) {
	}
	if (sp->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
	}
	if (sp->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) {
	}
	if (sp->Access_capabilities.DLMC_Capability_Present) {
		if (sp->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
		}
		if (sp->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) {
		}
		EDFree (sp->Access_capabilities.DLMC_Capability);
		sp->Access_capabilities.DLMC_Capability = NULL;
	}
	if (sp->Access_capabilities.Extended_TSC_Set_Capability_support_Present) {
	}
	if (sp->Access_capabilities.Extended_EARFCN_value_range_Present) {
	}

}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->A5_bits_Present) {
		EDFree (sp->A5_bits);
		sp->A5_bits = NULL;
		sp->A5_bits_Present = ED_FALSE;
	}
	if (sp->Multislot_capability_Present) {
		if (sp->Multislot_capability->HSCSD_multislot_class_Present) {
		}
		if (sp->Multislot_capability->GPRS_multislot_class_Present) {
		}
		if (sp->Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Multislot_capability->SMS_VALUE_Present) {
		}
		if (sp->Multislot_capability->SM_VALUE_Present) {
		}
		if (sp->Multislot_capability->ECSD_multislot_class_Present) {
		}
		if (sp->Multislot_capability->EGPRS_multislot_class_Present) {
		}
		if (sp->Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Multislot_capability->Single_Slot_DTM_Present) {
		}
		if (sp->Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
		}
		EDFree (sp->Multislot_capability);
		sp->Multislot_capability = NULL;
		sp->Multislot_capability_Present = ED_FALSE;
	}
	if (sp->Enhanced_Flexible_Timeslot_Assignment_Present) {
		if (sp->Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
		}
		if (sp->Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
		}
		EDFree (sp->Enhanced_Flexible_Timeslot_Assignment);
		sp->Enhanced_Flexible_Timeslot_Assignment = NULL;
		sp->Enhanced_Flexible_Timeslot_Assignment_Present = ED_FALSE;
	}
	if (sp->DLMC_Capability_Present) {
		if (sp->DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
		}
		if (sp->DLMC_Capability->DLMC_Inter_band_reception_Present) {
		}
		EDFree (sp->DLMC_Capability);
		sp->DLMC_Capability = NULL;
		sp->DLMC_Capability_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->A5_bits_Present == present) return ED_NO_ERRORS;
	sp->A5_bits_Present = present;
	if (present) {
		/*-->*/sp->A5_bits = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->A5_bits)
		ED_RESET_MEM (sp->A5_bits, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits));
		(sp->A5_bits->A5_1) = 0;
		(sp->A5_bits->A5_2) = 0;
		(sp->A5_bits->A5_3) = 0;
		(sp->A5_bits->A5_4) = 0;
		(sp->A5_bits->A5_5) = 0;
		(sp->A5_bits->A5_6) = 0;
		(sp->A5_bits->A5_7) = 0;
	} else {
		EDFree (sp->A5_bits);
		sp->A5_bits = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Multislot_capability_Present == present) return ED_NO_ERRORS;
	sp->Multislot_capability_Present = present;
	if (present) {
		/*-->*/sp->Multislot_capability = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Multislot_capability)
		ED_RESET_MEM (sp->Multislot_capability, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability));
	} else {
		if (sp->Multislot_capability->HSCSD_multislot_class_Present) {
		}
		if (sp->Multislot_capability->GPRS_multislot_class_Present) {
		}
		if (sp->Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Multislot_capability->SMS_VALUE_Present) {
		}
		if (sp->Multislot_capability->SM_VALUE_Present) {
		}
		if (sp->Multislot_capability->ECSD_multislot_class_Present) {
		}
		if (sp->Multislot_capability->EGPRS_multislot_class_Present) {
		}
		if (sp->Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) {
		}
		if (sp->Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) {
		}
		if (sp->Multislot_capability->Single_Slot_DTM_Present) {
		}
		if (sp->Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) {
		}
		EDFree (sp->Multislot_capability);
		sp->Multislot_capability = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Enhanced_Flexible_Timeslot_Assignment_Present == present) return ED_NO_ERRORS;
	sp->Enhanced_Flexible_Timeslot_Assignment_Present = present;
	if (present) {
		/*-->*/sp->Enhanced_Flexible_Timeslot_Assignment = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Enhanced_Flexible_Timeslot_Assignment)
		ED_RESET_MEM (sp->Enhanced_Flexible_Timeslot_Assignment, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment));
	} else {
		if (sp->Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) {
		}
		if (sp->Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) {
		}
		EDFree (sp->Enhanced_Flexible_Timeslot_Assignment);
		sp->Enhanced_Flexible_Timeslot_Assignment = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DLMC_Capability_Present == present) return ED_NO_ERRORS;
	sp->DLMC_Capability_Present = present;
	if (present) {
		/*-->*/sp->DLMC_Capability = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DLMC_Capability)
		ED_RESET_MEM (sp->DLMC_Capability, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability));
		(sp->DLMC_Capability->DLMC_Maximum_Bandwidth) = 0;
		(sp->DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots) = 0;
		(sp->DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers) = 0;
	} else {
		if (sp->DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) {
		}
		if (sp->DLMC_Capability->DLMC_Inter_band_reception_Present) {
		}
		EDFree (sp->DLMC_Capability);
		sp->DLMC_Capability = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability* sp) {
ED_WARNING_REMOVER(sp);

}

/* SETITEMS commands for type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies'. Existing items are not changed. */
int SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data** tmp;
		tmp = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data**)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data*)EDAlloc (sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data));
			(sequence->data[i]->Access_Technology_Type) = 0;
			(sequence->data[i]->GMSK_Power_Class) = 0;
			(sequence->data[i]->_8PSK_Power_Class) = 0;
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data */
void FREE_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data* sp) {
ED_WARNING_REMOVER(sp);

}

/* SETITEMS commands for type 'c_ProtocolCfgOpt_ProtocolCfgs'. Existing items are not changed. */
int SETITEMS_c_ProtocolCfgOpt_ProtocolCfgs (c_ProtocolCfgOpt_ProtocolCfgs* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_ProtocolCfgOpt_ProtocolCfgs_data** tmp;
		tmp = (c_ProtocolCfgOpt_ProtocolCfgs_data**)EDAlloc (sizeof (c_ProtocolCfgOpt_ProtocolCfgs_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_ProtocolCfgOpt_ProtocolCfgs_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_ProtocolCfgOpt_ProtocolCfgs_data*)EDAlloc (sizeof (c_ProtocolCfgOpt_ProtocolCfgs_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_ProtocolCfgOpt_ProtocolCfgs_data));
			(sequence->data[i]->ProtocolId) = 0;
			(sequence->data[i]->Length) = 0;
			sequence->data[i]->Contents.value = NULL;
			sequence->data[i]->Contents.usedBits = 0;
			
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->Contents.value != NULL) {
					EDFree (sequence->data[i]->Contents.value);
					sequence->data[i]->Contents.value = NULL;
				}
				sequence->data[i]->Contents.usedBits = 0;
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_ProtocolCfgOpt_ProtocolCfgs_data */
void FREE_c_ProtocolCfgOpt_ProtocolCfgs_data (c_ProtocolCfgOpt_ProtocolCfgs_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Contents.value != NULL) {
		EDFree (sp->Contents.value);
		sp->Contents.value = NULL;
	}
	sp->Contents.usedBits = 0;

}

/* SETITEMS commands for type 'c_ProtocolCfgOpt_ContainerCfgs'. Existing items are not changed. */
int SETITEMS_c_ProtocolCfgOpt_ContainerCfgs (c_ProtocolCfgOpt_ContainerCfgs* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_ProtocolCfgOpt_ContainerCfgs_data** tmp;
		tmp = (c_ProtocolCfgOpt_ContainerCfgs_data**)EDAlloc (sizeof (c_ProtocolCfgOpt_ContainerCfgs_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_ProtocolCfgOpt_ContainerCfgs_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_ProtocolCfgOpt_ContainerCfgs_data*)EDAlloc (sizeof (c_ProtocolCfgOpt_ContainerCfgs_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_ProtocolCfgOpt_ContainerCfgs_data));
			(sequence->data[i]->ContainerId) = 0;
			(sequence->data[i]->Length) = 0;
			sequence->data[i]->Contents.value = NULL;
			sequence->data[i]->Contents.usedBits = 0;
			
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->Contents.value != NULL) {
					EDFree (sequence->data[i]->Contents.value);
					sequence->data[i]->Contents.value = NULL;
				}
				sequence->data[i]->Contents.usedBits = 0;
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_ProtocolCfgOpt_ContainerCfgs_data */
void FREE_c_ProtocolCfgOpt_ContainerCfgs_data (c_ProtocolCfgOpt_ContainerCfgs_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Contents.value != NULL) {
		EDFree (sp->Contents.value);
		sp->Contents.value = NULL;
	}
	sp->Contents.usedBits = 0;

}

/* SETITEMS commands for type 'c_TrafficFlowTemplate_PacketFilters'. Existing items are not changed. */
int SETITEMS_c_TrafficFlowTemplate_PacketFilters (c_TrafficFlowTemplate_PacketFilters* sequence, int desiredItems)
{
	int i, i0;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TrafficFlowTemplate_PacketFilters_data** tmp;
		tmp = (c_TrafficFlowTemplate_PacketFilters_data**)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketFilters_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TrafficFlowTemplate_PacketFilters_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_TrafficFlowTemplate_PacketFilters_data*)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketFilters_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_TrafficFlowTemplate_PacketFilters_data));
			(sequence->data[i]->PacketFilterId) = 0;
			(sequence->data[i]->PacketFilterDirection) = 0;
			(sequence->data[i]->PacketFilterEvalPrecedence) = 0;
			sequence->data[i]->FilterContents.items = 0;
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				for (i0=0; i0<sequence->data[i]->FilterContents.items; i0++) {
					if (sequence->data[i]->FilterContents.data[i0]->ComponentData.value != NULL) {
						EDFree (sequence->data[i]->FilterContents.data[i0]->ComponentData.value);
						sequence->data[i]->FilterContents.data[i0]->ComponentData.value = NULL;
					}
					sequence->data[i]->FilterContents.data[i0]->ComponentData.usedBits = 0;
					EDFree (sequence->data[i]->FilterContents.data[i0]);
					sequence->data[i]->FilterContents.data[i0] = NULL;
				}
				if (sequence->data[i]->FilterContents.data) {EDFree (sequence->data[i]->FilterContents.data); sequence->data[i]->FilterContents.data = NULL; sequence->data[i]->FilterContents.allocatedItems=0; /*FR02A*/}
				if (sequence->data[i]->FilterContents.data___LOCATOR) {EDFree (sequence->data[i]->FilterContents.data___LOCATOR); sequence->data[i]->FilterContents.data___LOCATOR = NULL; /*FR02AL*/}
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_TrafficFlowTemplate_PacketFilters_data */
void FREE_c_TrafficFlowTemplate_PacketFilters_data (c_TrafficFlowTemplate_PacketFilters_data* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->FilterContents.items; i0++) {
		if (sp->FilterContents.data[i0]->ComponentData.value != NULL) {
			EDFree (sp->FilterContents.data[i0]->ComponentData.value);
			sp->FilterContents.data[i0]->ComponentData.value = NULL;
		}
		sp->FilterContents.data[i0]->ComponentData.usedBits = 0;
		EDFree (sp->FilterContents.data[i0]);
		sp->FilterContents.data[i0] = NULL;
	}
	if (sp->FilterContents.data) {EDFree (sp->FilterContents.data); sp->FilterContents.data = NULL; sp->FilterContents.allocatedItems=0; /*FR02A*/}
	if (sp->FilterContents.data___LOCATOR) {EDFree (sp->FilterContents.data___LOCATOR); sp->FilterContents.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents'. Existing items are not changed. */
int SETITEMS_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (c_TrafficFlowTemplate_PacketFilters_data_FilterContents* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data** tmp;
		tmp = (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data**)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data*)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data));
			(sequence->data[i]->ComponentTypeId) = 0;
			sequence->data[i]->ComponentData.value = NULL;
			sequence->data[i]->ComponentData.usedBits = 0;
			
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->ComponentData.value != NULL) {
					EDFree (sequence->data[i]->ComponentData.value);
					sequence->data[i]->ComponentData.value = NULL;
				}
				sequence->data[i]->ComponentData.usedBits = 0;
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data */
void FREE_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data (c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ComponentData.value != NULL) {
		EDFree (sp->ComponentData.value);
		sp->ComponentData.value = NULL;
	}
	sp->ComponentData.usedBits = 0;

}

/* SETITEMS commands for type 'c_TrafficFlowTemplate_PacketParameters'. Existing items are not changed. */
int SETITEMS_c_TrafficFlowTemplate_PacketParameters (c_TrafficFlowTemplate_PacketParameters* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TrafficFlowTemplate_PacketParameters_data** tmp;
		tmp = (c_TrafficFlowTemplate_PacketParameters_data**)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketParameters_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TrafficFlowTemplate_PacketParameters_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_TrafficFlowTemplate_PacketParameters_data*)EDAlloc (sizeof (c_TrafficFlowTemplate_PacketParameters_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_TrafficFlowTemplate_PacketParameters_data));
			(sequence->data[i]->ParameterId) = 0;
			sequence->data[i]->Contents.value = NULL;
			sequence->data[i]->Contents.usedBits = 0;
			
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->Contents.value != NULL) {
					EDFree (sequence->data[i]->Contents.value);
					sequence->data[i]->Contents.value = NULL;
				}
				sequence->data[i]->Contents.usedBits = 0;
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_TrafficFlowTemplate_PacketParameters_data */
void FREE_c_TrafficFlowTemplate_PacketParameters_data (c_TrafficFlowTemplate_PacketParameters_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Contents.value != NULL) {
		EDFree (sp->Contents.value);
		sp->Contents.value = NULL;
	}
	sp->Contents.usedBits = 0;

}

