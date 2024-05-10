/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_EPS.h"
#include "ed_lib.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


/* Free function for variable-sized sequence c_RemoteUEContext_Identity_IdentityDigit */
void FREE_c_RemoteUEContext_Identity_IdentityDigit (c_RemoteUEContext_Identity_IdentityDigit* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_RemoteUEContext_Identity */
void FREE_c_RemoteUEContext_Identity (c_RemoteUEContext_Identity* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->IdentityDigit.data) {EDFree (sp->IdentityDigit.data); sp->IdentityDigit.data = NULL; sp->IdentityDigit.allocatedItems=0; /*FR02A*/}
	if (sp->IdentityDigit.data___LOCATOR) {EDFree (sp->IdentityDigit.data___LOCATOR); sp->IdentityDigit.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_epsProtocolCfg */
void FREE_c_epsProtocolCfg (c_epsProtocolCfg* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Contents.value != NULL) {
		EDFree (sp->Contents.value);
		sp->Contents.value = NULL;
	}
	sp->Contents.usedBits = 0;

}

/* Free function for variable-sized sequence c_RemoteUEContext_SingleContext_UserIDs */
void FREE_c_RemoteUEContext_SingleContext_UserIDs (c_RemoteUEContext_SingleContext_UserIDs* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_RemoteUEContext_Identity (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_RemoteUEContext_SingleContext */
void FREE_c_RemoteUEContext_SingleContext (c_RemoteUEContext_SingleContext* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->UserIDs.items; i0++) {
		FREE_c_RemoteUEContext_Identity (sp->UserIDs.data[i0]);
		EDFree (sp->UserIDs.data[i0]);
	}
	if (sp->UserIDs.data) {EDFree (sp->UserIDs.data); sp->UserIDs.data = NULL; sp->UserIDs.allocatedItems=0; /*FR02A*/}
	if (sp->UserIDs.data___LOCATOR) {EDFree (sp->UserIDs.data___LOCATOR); sp->UserIDs.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_PartialTrackingAreaIdentity_Type2 */
void FREE_c_PartialTrackingAreaIdentity_Type2 (c_PartialTrackingAreaIdentity_Type2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_PartialTrackingAreaIdentityList_TACS */
void FREE_c_PartialTrackingAreaIdentityList_TACS (c_PartialTrackingAreaIdentityList_TACS* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_PartialTrackingAreaIdentityList_TACS'. Existing items are not changed. */
int SETITEMS_c_PartialTrackingAreaIdentityList_TACS (c_PartialTrackingAreaIdentityList_TACS* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		ED_SHORT* tmp;
		tmp = (ED_SHORT*)EDAlloc (sizeof (ED_SHORT) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (ED_SHORT) * (size_t)sequence->items);
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

/* Free function for variable-sized sequence c_epsProtocolCfgList */
void FREE_c_epsProtocolCfgList (c_epsProtocolCfgList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_epsProtocolCfg (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_epsProtocolCfgList'. Existing items are not changed. */
int SETITEMS_c_epsProtocolCfgList (c_epsProtocolCfgList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsProtocolCfg** tmp;
		tmp = (c_epsProtocolCfg**)EDAlloc (sizeof (c_epsProtocolCfg*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsProtocolCfg*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsProtocolCfg*)EDAlloc (sizeof (c_epsProtocolCfg));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_epsProtocolCfg (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_epsProtocolCfg (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_PartialTrackingAreaIdentityList_Type0 */
void FREE_c_PartialTrackingAreaIdentityList_Type0 (c_PartialTrackingAreaIdentityList_Type0* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_PartialTrackingAreaIdentityList_TACS (&(sp->TAC));

}

/* Free function for struct c_PartialTrackingAreaIdentityList_Type1 */
void FREE_c_PartialTrackingAreaIdentityList_Type1 (c_PartialTrackingAreaIdentityList_Type1* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PDNAddress */
void FREE_c_PDNAddress (c_PDNAddress* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->PDNAddressInformation.value != NULL) {
		EDFree (sp->PDNAddressInformation.value);
		sp->PDNAddressInformation.value = NULL;
	}
	sp->PDNAddressInformation.usedBits = 0;

}

/* Free function for struct c_epsReAttemptIndicator */
void FREE_c_epsReAttemptIndicator (c_epsReAttemptIndicator* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PKMFAddress */
void FREE_c_PKMFAddress (c_PKMFAddress* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AddressInformation.value != NULL) {
		EDFree (sp->AddressInformation.value);
		sp->AddressInformation.value = NULL;
	}
	sp->AddressInformation.usedBits = 0;

}

/* Free function for struct c_HeaderCompressionCfg */
void FREE_c_HeaderCompressionCfg (c_HeaderCompressionCfg* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Parameters.value != NULL) {
		EDFree (sp->Parameters.value);
		sp->Parameters.value = NULL;
	}
	sp->Parameters.usedBits = 0;

}

/* Free function for struct c_epsServCategory */
void FREE_c_epsServCategory (c_epsServCategory* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsLlcServAccessPointId */
void FREE_c_epsLlcServAccessPointId (c_epsLlcServAccessPointId* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsPacketFlowIdentifie */
void FREE_c_epsPacketFlowIdentifie (c_epsPacketFlowIdentifie* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsConnectivityType */
void FREE_c_epsConnectivityType (c_epsConnectivityType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsWLANOffloadAcceptability */
void FREE_c_epsWLANOffloadAcceptability (c_epsWLANOffloadAcceptability* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsDeviceProperties */
void FREE_c_epsDeviceProperties (c_epsDeviceProperties* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsProtocolCfgOpt */
void FREE_c_epsProtocolCfgOpt (c_epsProtocolCfgOpt* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsProtocolCfgList (&(sp->ProtocolCfgs));

}

/* Free function for variable-sized sequence c_PartialTrackingAreaIdentityList_Type2 */
void FREE_c_PartialTrackingAreaIdentityList_Type2 (c_PartialTrackingAreaIdentityList_Type2* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_PartialTrackingAreaIdentity_Type2 (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_PartialTrackingAreaIdentityList_Type2'. Existing items are not changed. */
int SETITEMS_c_PartialTrackingAreaIdentityList_Type2 (c_PartialTrackingAreaIdentityList_Type2* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_PartialTrackingAreaIdentity_Type2** tmp;
		tmp = (c_PartialTrackingAreaIdentity_Type2**)EDAlloc (sizeof (c_PartialTrackingAreaIdentity_Type2*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_PartialTrackingAreaIdentity_Type2*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_PartialTrackingAreaIdentity_Type2*)EDAlloc (sizeof (c_PartialTrackingAreaIdentity_Type2));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_PartialTrackingAreaIdentity_Type2 (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_PartialTrackingAreaIdentity_Type2 (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_APNAggregateMaxBitRate */
void FREE_c_APNAggregateMaxBitRate (c_APNAggregateMaxBitRate* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ext_Present) {
		EDFree (sp->ext);
		sp->ext = NULL;
		sp->ext_Present = ED_FALSE;
	}
	if (sp->ext2_Present) {
		EDFree (sp->ext2);
		sp->ext2 = NULL;
		sp->ext2_Present = ED_FALSE;
	}

}

int SETPRESENT_c_APNAggregateMaxBitRate_ext (c_APNAggregateMaxBitRate* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ext_Present == present) return ED_NO_ERRORS;
	sp->ext_Present = present;
	if (present) {
		/*-->*/sp->ext = (c_APNAggregateMaxBitRate_ext*)EDAlloc (sizeof (c_APNAggregateMaxBitRate_ext));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ext)
		ED_RESET_MEM (sp->ext, sizeof (c_APNAggregateMaxBitRate_ext));
		(sp->ext->APN_AMBRDownlinkExt) = 0;
		(sp->ext->APN_AMBRUplinkExt) = 0;
	} else {
		EDFree (sp->ext);
		sp->ext = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_APNAggregateMaxBitRate_ext2 (c_APNAggregateMaxBitRate* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ext2_Present == present) return ED_NO_ERRORS;
	sp->ext2_Present = present;
	if (present) {
		/*-->*/sp->ext2 = (c_APNAggregateMaxBitRate_ext2*)EDAlloc (sizeof (c_APNAggregateMaxBitRate_ext2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ext2)
		ED_RESET_MEM (sp->ext2, sizeof (c_APNAggregateMaxBitRate_ext2));
		(sp->ext2->APN_AMBRDownlinkExt2) = 0;
		(sp->ext2->APN_AMBRUplinkExt2) = 0;
	} else {
		EDFree (sp->ext2);
		sp->ext2 = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EPS_QOS */
void FREE_c_EPS_QOS (c_EPS_QOS* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->basic_Present) {
		EDFree (sp->basic);
		sp->basic = NULL;
		sp->basic_Present = ED_FALSE;
	}
	if (sp->extended_Present) {
		EDFree (sp->extended);
		sp->extended = NULL;
		sp->extended_Present = ED_FALSE;
	}
	if (sp->extended2_Present) {
		EDFree (sp->extended2);
		sp->extended2 = NULL;
		sp->extended2_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EPS_QOS_basic (c_EPS_QOS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->basic_Present == present) return ED_NO_ERRORS;
	sp->basic_Present = present;
	if (present) {
		/*-->*/sp->basic = (c_EPS_QOS_basic*)EDAlloc (sizeof (c_EPS_QOS_basic));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->basic)
		ED_RESET_MEM (sp->basic, sizeof (c_EPS_QOS_basic));
		(sp->basic->MaximumBitRateForUplink) = 0;
		(sp->basic->MaximumBitRateForDownlink) = 0;
		(sp->basic->GuaranteedBitRateForUplink) = 0;
		(sp->basic->GuaranteedBitRateForDownlink) = 0;
	} else {
		EDFree (sp->basic);
		sp->basic = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EPS_QOS_extended (c_EPS_QOS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->extended_Present == present) return ED_NO_ERRORS;
	sp->extended_Present = present;
	if (present) {
		/*-->*/sp->extended = (c_EPS_QOS_extended*)EDAlloc (sizeof (c_EPS_QOS_extended));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->extended)
		ED_RESET_MEM (sp->extended, sizeof (c_EPS_QOS_extended));
		(sp->extended->MaximumBitRateForUplinkExt) = 0;
		(sp->extended->MaximumBitRateForDownlinkExt) = 0;
		(sp->extended->GuaranteedBitRateForUplinkExt) = 0;
		(sp->extended->GuaranteedBitRateForDownlinkExt) = 0;
	} else {
		EDFree (sp->extended);
		sp->extended = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EPS_QOS_extended2 (c_EPS_QOS* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->extended2_Present == present) return ED_NO_ERRORS;
	sp->extended2_Present = present;
	if (present) {
		/*-->*/sp->extended2 = (c_EPS_QOS_extended2*)EDAlloc (sizeof (c_EPS_QOS_extended2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->extended2)
		ED_RESET_MEM (sp->extended2, sizeof (c_EPS_QOS_extended2));
		(sp->extended2->MaximumBitRateForUplinkExt) = 0;
		(sp->extended2->MaximumBitRateForDownlinkExt) = 0;
		(sp->extended2->GuaranteedBitRateForUplinkExt) = 0;
		(sp->extended2->GuaranteedBitRateForDownlinkExt) = 0;
	} else {
		EDFree (sp->extended2);
		sp->extended2 = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_epsQualityOfServ */
void FREE_c_epsQualityOfServ (c_epsQualityOfServ* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->downlink_Present) {
		EDFree (sp->downlink);
		sp->downlink = NULL;
		sp->downlink_Present = ED_FALSE;
	}
	if (sp->uplink_Present) {
		EDFree (sp->uplink);
		sp->uplink = NULL;
		sp->uplink_Present = ED_FALSE;
	}
	if (sp->ext2downlink_Present) {
		EDFree (sp->ext2downlink);
		sp->ext2downlink = NULL;
		sp->ext2downlink_Present = ED_FALSE;
	}
	if (sp->ext2uplink_Present) {
		EDFree (sp->ext2uplink);
		sp->ext2uplink = NULL;
		sp->ext2uplink_Present = ED_FALSE;
	}

}

int SETPRESENT_c_epsQualityOfServ_downlink (c_epsQualityOfServ* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->downlink_Present == present) return ED_NO_ERRORS;
	sp->downlink_Present = present;
	if (present) {
		/*-->*/sp->downlink = (c_epsQualityOfServ_downlink*)EDAlloc (sizeof (c_epsQualityOfServ_downlink));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->downlink)
		ED_RESET_MEM (sp->downlink, sizeof (c_epsQualityOfServ_downlink));
		(sp->downlink->MaximumBitRateForDownlinkExt) = 0;
		(sp->downlink->GuaranteedBitRateForDownlinkExt) = 0;
	} else {
		EDFree (sp->downlink);
		sp->downlink = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_epsQualityOfServ_uplink (c_epsQualityOfServ* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->uplink_Present == present) return ED_NO_ERRORS;
	sp->uplink_Present = present;
	if (present) {
		/*-->*/sp->uplink = (c_epsQualityOfServ_uplink*)EDAlloc (sizeof (c_epsQualityOfServ_uplink));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->uplink)
		ED_RESET_MEM (sp->uplink, sizeof (c_epsQualityOfServ_uplink));
		(sp->uplink->MaximumBitRateForUplinkExt) = 0;
		(sp->uplink->GuaranteedBitRateForUplinkExt) = 0;
	} else {
		EDFree (sp->uplink);
		sp->uplink = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_epsQualityOfServ_ext2downlink (c_epsQualityOfServ* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ext2downlink_Present == present) return ED_NO_ERRORS;
	sp->ext2downlink_Present = present;
	if (present) {
		/*-->*/sp->ext2downlink = (c_epsQualityOfServ_ext2downlink*)EDAlloc (sizeof (c_epsQualityOfServ_ext2downlink));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ext2downlink)
		ED_RESET_MEM (sp->ext2downlink, sizeof (c_epsQualityOfServ_ext2downlink));
		(sp->ext2downlink->MaximumBitRateForDownlinkExt) = 0;
		(sp->ext2downlink->GuaranteedBitRateForDownlinkExt) = 0;
	} else {
		EDFree (sp->ext2downlink);
		sp->ext2downlink = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_epsQualityOfServ_ext2uplink (c_epsQualityOfServ* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ext2uplink_Present == present) return ED_NO_ERRORS;
	sp->ext2uplink_Present = present;
	if (present) {
		/*-->*/sp->ext2uplink = (c_epsQualityOfServ_ext2uplink*)EDAlloc (sizeof (c_epsQualityOfServ_ext2uplink));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ext2uplink)
		ED_RESET_MEM (sp->ext2uplink, sizeof (c_epsQualityOfServ_ext2uplink));
		(sp->ext2uplink->MaximumBitRateForUplinkExt) = 0;
		(sp->ext2uplink->GuaranteedBitRateForUplinkExt) = 0;
	} else {
		EDFree (sp->ext2uplink);
		sp->ext2uplink = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_RemoteUEContext_Contexts */
void FREE_c_RemoteUEContext_Contexts (c_RemoteUEContext_Contexts* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_RemoteUEContext_SingleContext (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_RemoteUEContext */
void FREE_c_RemoteUEContext (c_RemoteUEContext* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	for (i0=0; i0<sp->Contexts.items; i0++) {
		FREE_c_RemoteUEContext_SingleContext (sp->Contexts.data[i0]);
		EDFree (sp->Contexts.data[i0]);
	}
	if (sp->Contexts.data) {EDFree (sp->Contexts.data); sp->Contexts.data = NULL; sp->Contexts.allocatedItems=0; /*FR02A*/}
	if (sp->Contexts.data___LOCATOR) {EDFree (sp->Contexts.data___LOCATOR); sp->Contexts.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for struct c_epsLinkedTi */
void FREE_c_epsLinkedTi (c_epsLinkedTi* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents */
void FREE_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents* sp) {
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
/* Free function for variable-sized sequence c_epsTrafficFlowTemplate_PacketFilters */
void FREE_c_epsTrafficFlowTemplate_PacketFilters (c_epsTrafficFlowTemplate_PacketFilters* sp) {
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
/* Free function for variable-sized sequence c_epsTrafficFlowTemplate_PacketParameters */
void FREE_c_epsTrafficFlowTemplate_PacketParameters (c_epsTrafficFlowTemplate_PacketParameters* sp) {
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
/* Free function for struct c_epsTrafficFlowTemplate */
void FREE_c_epsTrafficFlowTemplate (c_epsTrafficFlowTemplate* sp) {
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

/* Free function for struct c_epsGprsTimer */
void FREE_c_epsGprsTimer (c_epsGprsTimer* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT */
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT */
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT */
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT */
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_BEARER_RESOURCE_ALLOCATION_REQUEST */
void FREE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsTrafficFlowTemplate (&(sp->TrafficFlowAggregate));
	FREE_c_EPS_QOS (&(sp->RequiredTrafficFlowQoS));
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_BEARER_RESOURCE_MODIFICATION_REQUEST */
void FREE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsTrafficFlowTemplate (&(sp->TrafficFlowAggregate));
	if (sp->RequiredTrafficFlowQoS_Present) {
		FREE_c_EPS_QOS (sp->RequiredTrafficFlowQoS);
		EDFree (sp->RequiredTrafficFlowQoS);
		sp->RequiredTrafficFlowQoS_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
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
	if (sp->HeaderCompressionCfg_Present) {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
		sp->HeaderCompressionCfg_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RequiredTrafficFlowQoS_Present == present) return ED_NO_ERRORS;
	sp->RequiredTrafficFlowQoS_Present = present;
	if (present) {
		/*-->*/sp->RequiredTrafficFlowQoS = (c_EPS_QOS*)EDAlloc (sizeof (c_EPS_QOS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RequiredTrafficFlowQoS)
		INIT_c_EPS_QOS (sp->RequiredTrafficFlowQoS);
	} else {
		FREE_c_EPS_QOS (sp->RequiredTrafficFlowQoS);
		EDFree (sp->RequiredTrafficFlowQoS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HeaderCompressionCfg_Present == present) return ED_NO_ERRORS;
	sp->HeaderCompressionCfg_Present = present;
	if (present) {
		/*-->*/sp->HeaderCompressionCfg = (c_HeaderCompressionCfg*)EDAlloc (sizeof (c_HeaderCompressionCfg));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HeaderCompressionCfg)
		INIT_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
	} else {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT */
void FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer*)EDAlloc (sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ESM_DUMMY_MESSAGE */
void FREE_c_ESM_DUMMY_MESSAGE (c_ESM_DUMMY_MESSAGE* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ESM_INFORMATION_RESPONSE */
void FREE_c_ESM_INFORMATION_RESPONSE (c_ESM_INFORMATION_RESPONSE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AccessPointName_Present) {
		if (sp->AccessPointName->value != NULL) {
			EDFree (sp->AccessPointName->value);
			sp->AccessPointName->value = NULL;
		}
		sp->AccessPointName->usedBits = 0;
		EDFree (sp->AccessPointName);
		sp->AccessPointName_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AccessPointName_Present == present) return ED_NO_ERRORS;
	sp->AccessPointName_Present = present;
	if (present) {
		/*-->*/sp->AccessPointName = (c_ESM_INFORMATION_RESPONSE_AccessPointName*)EDAlloc (sizeof (c_ESM_INFORMATION_RESPONSE_AccessPointName));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AccessPointName)
		
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

int SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ESM_STATUS */
void FREE_c_ESM_STATUS (c_ESM_STATUS* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT */
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_MODIFY_EPS_BEARER_CONTEXT_REJECT */
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_PDN_CONNECTIVITY_REQUEST */
void FREE_c_PDN_CONNECTIVITY_REQUEST (c_PDN_CONNECTIVITY_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AccessPointName_Present) {
		if (sp->AccessPointName->value != NULL) {
			EDFree (sp->AccessPointName->value);
			sp->AccessPointName->value = NULL;
		}
		sp->AccessPointName->usedBits = 0;
		EDFree (sp->AccessPointName);
		sp->AccessPointName_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
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
	if (sp->HeaderCompressionCfg_Present) {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
		sp->HeaderCompressionCfg_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AccessPointName_Present == present) return ED_NO_ERRORS;
	sp->AccessPointName_Present = present;
	if (present) {
		/*-->*/sp->AccessPointName = (c_PDN_CONNECTIVITY_REQUEST_AccessPointName*)EDAlloc (sizeof (c_PDN_CONNECTIVITY_REQUEST_AccessPointName));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AccessPointName)
		
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

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HeaderCompressionCfg_Present == present) return ED_NO_ERRORS;
	sp->HeaderCompressionCfg_Present = present;
	if (present) {
		/*-->*/sp->HeaderCompressionCfg = (c_HeaderCompressionCfg*)EDAlloc (sizeof (c_HeaderCompressionCfg));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HeaderCompressionCfg)
		INIT_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
	} else {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_PDN_DISCONNECT_REQUEST */
void FREE_c_PDN_DISCONNECT_REQUEST (c_PDN_DISCONNECT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (c_PDN_DISCONNECT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (c_PDN_DISCONNECT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REMOTE_UE_REPORT */
void FREE_c_REMOTE_UE_REPORT (c_REMOTE_UE_REPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->RemoteUEContextConnected_Present) {
		FREE_c_RemoteUEContext (sp->RemoteUEContextConnected);
		EDFree (sp->RemoteUEContextConnected);
		sp->RemoteUEContextConnected_Present = ED_FALSE;
	}
	if (sp->RemoteUEContextDisconnected_Present) {
		FREE_c_RemoteUEContext (sp->RemoteUEContextDisconnected);
		EDFree (sp->RemoteUEContextDisconnected);
		sp->RemoteUEContextDisconnected_Present = ED_FALSE;
	}
	if (sp->ProSeKeyManagementFunctionAddr_Present) {
		FREE_c_PKMFAddress (sp->ProSeKeyManagementFunctionAddr);
		EDFree (sp->ProSeKeyManagementFunctionAddr);
		sp->ProSeKeyManagementFunctionAddr_Present = ED_FALSE;
	}

}

int SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RemoteUEContextConnected_Present == present) return ED_NO_ERRORS;
	sp->RemoteUEContextConnected_Present = present;
	if (present) {
		/*-->*/sp->RemoteUEContextConnected = (c_RemoteUEContext*)EDAlloc (sizeof (c_RemoteUEContext));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RemoteUEContextConnected)
		INIT_c_RemoteUEContext (sp->RemoteUEContextConnected);
	} else {
		FREE_c_RemoteUEContext (sp->RemoteUEContextConnected);
		EDFree (sp->RemoteUEContextConnected);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->RemoteUEContextDisconnected_Present == present) return ED_NO_ERRORS;
	sp->RemoteUEContextDisconnected_Present = present;
	if (present) {
		/*-->*/sp->RemoteUEContextDisconnected = (c_RemoteUEContext*)EDAlloc (sizeof (c_RemoteUEContext));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->RemoteUEContextDisconnected)
		INIT_c_RemoteUEContext (sp->RemoteUEContextDisconnected);
	} else {
		FREE_c_RemoteUEContext (sp->RemoteUEContextDisconnected);
		EDFree (sp->RemoteUEContextDisconnected);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProSeKeyManagementFunctionAddr_Present == present) return ED_NO_ERRORS;
	sp->ProSeKeyManagementFunctionAddr_Present = present;
	if (present) {
		/*-->*/sp->ProSeKeyManagementFunctionAddr = (c_PKMFAddress*)EDAlloc (sizeof (c_PKMFAddress));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProSeKeyManagementFunctionAddr)
		INIT_c_PKMFAddress (sp->ProSeKeyManagementFunctionAddr);
	} else {
		FREE_c_PKMFAddress (sp->ProSeKeyManagementFunctionAddr);
		EDFree (sp->ProSeKeyManagementFunctionAddr);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ESM_DATA_TRANSPORT */
void FREE_c_ESM_DATA_TRANSPORT (c_ESM_DATA_TRANSPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->UserDataContainer.value != NULL) {
		EDFree (sp->UserDataContainer.value);
		sp->UserDataContainer.value = NULL;
	}
	sp->UserDataContainer.usedBits = 0;

}

/* Free function for struct c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST */
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPS_QOS (&(sp->EPSQoS));
	FREE_c_epsTrafficFlowTemplate (&(sp->TFT));
	if (sp->TransactionIdentifier_Present) {
		FREE_c_epsLinkedTi (sp->TransactionIdentifier);
		EDFree (sp->TransactionIdentifier);
		sp->TransactionIdentifier_Present = ED_FALSE;
	}
	if (sp->NegotiatedQoS_Present) {
		FREE_c_epsQualityOfServ (sp->NegotiatedQoS);
		EDFree (sp->NegotiatedQoS);
		sp->NegotiatedQoS_Present = ED_FALSE;
	}
	if (sp->NegotiatedLLCSAPI_Present) {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
		sp->NegotiatedLLCSAPI_Present = ED_FALSE;
	}
	if (sp->PacketFlowIdentifier_Present) {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
		sp->PacketFlowIdentifier_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TransactionIdentifier_Present == present) return ED_NO_ERRORS;
	sp->TransactionIdentifier_Present = present;
	if (present) {
		/*-->*/sp->TransactionIdentifier = (c_epsLinkedTi*)EDAlloc (sizeof (c_epsLinkedTi));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TransactionIdentifier)
		INIT_c_epsLinkedTi (sp->TransactionIdentifier);
	} else {
		FREE_c_epsLinkedTi (sp->TransactionIdentifier);
		EDFree (sp->TransactionIdentifier);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedQoS_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedQoS_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedQoS = (c_epsQualityOfServ*)EDAlloc (sizeof (c_epsQualityOfServ));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedQoS)
		INIT_c_epsQualityOfServ (sp->NegotiatedQoS);
	} else {
		FREE_c_epsQualityOfServ (sp->NegotiatedQoS);
		EDFree (sp->NegotiatedQoS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedLLCSAPI_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedLLCSAPI_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedLLCSAPI = (c_epsLlcServAccessPointId*)EDAlloc (sizeof (c_epsLlcServAccessPointId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedLLCSAPI)
		INIT_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
	} else {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowIdentifier_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowIdentifier_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowIdentifier = (c_epsPacketFlowIdentifie*)EDAlloc (sizeof (c_epsPacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowIdentifier)
		INIT_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
	} else {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_epsWLANOffloadAcceptability*)EDAlloc (sizeof (c_epsWLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST */
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPS_QOS (&(sp->EPSQoS));
	if (sp->AccessPointName.value != NULL) {
		EDFree (sp->AccessPointName.value);
		sp->AccessPointName.value = NULL;
	}
	sp->AccessPointName.usedBits = 0;
	FREE_c_PDNAddress (&(sp->PDNAddress));
	if (sp->TransactionIdentifier_Present) {
		FREE_c_epsLinkedTi (sp->TransactionIdentifier);
		EDFree (sp->TransactionIdentifier);
		sp->TransactionIdentifier_Present = ED_FALSE;
	}
	if (sp->NegotiatedQoS_Present) {
		FREE_c_epsQualityOfServ (sp->NegotiatedQoS);
		EDFree (sp->NegotiatedQoS);
		sp->NegotiatedQoS_Present = ED_FALSE;
	}
	if (sp->NegotiatedLLCSAPI_Present) {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
		sp->NegotiatedLLCSAPI_Present = ED_FALSE;
	}
	if (sp->PacketFlowIdentifier_Present) {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
		sp->PacketFlowIdentifier_Present = ED_FALSE;
	}
	if (sp->APNAMBR_Present) {
		FREE_c_APNAggregateMaxBitRate (sp->APNAMBR);
		EDFree (sp->APNAMBR);
		sp->APNAMBR_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ConnectivityType_Present) {
		FREE_c_epsConnectivityType (sp->ConnectivityType);
		EDFree (sp->ConnectivityType);
		sp->ConnectivityType_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
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
	if (sp->HeaderCompressionCfg_Present) {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
		sp->HeaderCompressionCfg_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TransactionIdentifier_Present == present) return ED_NO_ERRORS;
	sp->TransactionIdentifier_Present = present;
	if (present) {
		/*-->*/sp->TransactionIdentifier = (c_epsLinkedTi*)EDAlloc (sizeof (c_epsLinkedTi));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TransactionIdentifier)
		INIT_c_epsLinkedTi (sp->TransactionIdentifier);
	} else {
		FREE_c_epsLinkedTi (sp->TransactionIdentifier);
		EDFree (sp->TransactionIdentifier);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedQoS_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedQoS_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedQoS = (c_epsQualityOfServ*)EDAlloc (sizeof (c_epsQualityOfServ));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedQoS)
		INIT_c_epsQualityOfServ (sp->NegotiatedQoS);
	} else {
		FREE_c_epsQualityOfServ (sp->NegotiatedQoS);
		EDFree (sp->NegotiatedQoS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedLLCSAPI_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedLLCSAPI_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedLLCSAPI = (c_epsLlcServAccessPointId*)EDAlloc (sizeof (c_epsLlcServAccessPointId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedLLCSAPI)
		INIT_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
	} else {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowIdentifier_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowIdentifier_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowIdentifier = (c_epsPacketFlowIdentifie*)EDAlloc (sizeof (c_epsPacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowIdentifier)
		INIT_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
	} else {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->APNAMBR_Present == present) return ED_NO_ERRORS;
	sp->APNAMBR_Present = present;
	if (present) {
		/*-->*/sp->APNAMBR = (c_APNAggregateMaxBitRate*)EDAlloc (sizeof (c_APNAggregateMaxBitRate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->APNAMBR)
		INIT_c_APNAggregateMaxBitRate (sp->APNAMBR);
	} else {
		FREE_c_APNAggregateMaxBitRate (sp->APNAMBR);
		EDFree (sp->APNAMBR);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ConnectivityType_Present == present) return ED_NO_ERRORS;
	sp->ConnectivityType_Present = present;
	if (present) {
		/*-->*/sp->ConnectivityType = (c_epsConnectivityType*)EDAlloc (sizeof (c_epsConnectivityType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ConnectivityType)
		INIT_c_epsConnectivityType (sp->ConnectivityType);
	} else {
		FREE_c_epsConnectivityType (sp->ConnectivityType);
		EDFree (sp->ConnectivityType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_epsWLANOffloadAcceptability*)EDAlloc (sizeof (c_epsWLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HeaderCompressionCfg_Present == present) return ED_NO_ERRORS;
	sp->HeaderCompressionCfg_Present = present;
	if (present) {
		/*-->*/sp->HeaderCompressionCfg = (c_HeaderCompressionCfg*)EDAlloc (sizeof (c_HeaderCompressionCfg));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HeaderCompressionCfg)
		INIT_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
	} else {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_BEARER_RESOURCE_ALLOCATION_REJECT */
void FREE_c_BEARER_RESOURCE_ALLOCATION_REJECT (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->BackOffTimer_Present) {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
		sp->BackOffTimer_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BackOffTimer_Present == present) return ED_NO_ERRORS;
	sp->BackOffTimer_Present = present;
	if (present) {
		/*-->*/sp->BackOffTimer = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BackOffTimer)
		INIT_c_epsGprsTimer (sp->BackOffTimer);
	} else {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_epsReAttemptIndicator*)EDAlloc (sizeof (c_epsReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_BEARER_RESOURCE_MODIFICATION_REJECT */
void FREE_c_BEARER_RESOURCE_MODIFICATION_REJECT (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->BackOffTimer_Present) {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
		sp->BackOffTimer_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BackOffTimer_Present == present) return ED_NO_ERRORS;
	sp->BackOffTimer_Present = present;
	if (present) {
		/*-->*/sp->BackOffTimer = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BackOffTimer)
		INIT_c_epsGprsTimer (sp->BackOffTimer);
	} else {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_epsReAttemptIndicator*)EDAlloc (sizeof (c_epsReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST */
void FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->T3396Value_Present) {
		FREE_c_epsGprsTimer (sp->T3396Value);
		EDFree (sp->T3396Value);
		sp->T3396Value_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3396Value_Present == present) return ED_NO_ERRORS;
	sp->T3396Value_Present = present;
	if (present) {
		/*-->*/sp->T3396Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3396Value)
		INIT_c_epsGprsTimer (sp->T3396Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3396Value);
		EDFree (sp->T3396Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_epsWLANOffloadAcceptability*)EDAlloc (sizeof (c_epsWLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ESM_INFORMATION_REQUEST */
void FREE_c_ESM_INFORMATION_REQUEST (c_ESM_INFORMATION_REQUEST* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_MODIFY_EPS_BEARER_CONTEXT_REQUEST */
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NewEPSQoS_Present) {
		FREE_c_EPS_QOS (sp->NewEPSQoS);
		EDFree (sp->NewEPSQoS);
		sp->NewEPSQoS_Present = ED_FALSE;
	}
	if (sp->TFT_Present) {
		FREE_c_epsTrafficFlowTemplate (sp->TFT);
		EDFree (sp->TFT);
		sp->TFT_Present = ED_FALSE;
	}
	if (sp->NewQoS_Present) {
		FREE_c_epsQualityOfServ (sp->NewQoS);
		EDFree (sp->NewQoS);
		sp->NewQoS_Present = ED_FALSE;
	}
	if (sp->NegotiatedLLCSAPI_Present) {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
		sp->NegotiatedLLCSAPI_Present = ED_FALSE;
	}
	if (sp->PacketFlowIdentifier_Present) {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
		sp->PacketFlowIdentifier_Present = ED_FALSE;
	}
	if (sp->APNAMBR_Present) {
		FREE_c_APNAggregateMaxBitRate (sp->APNAMBR);
		EDFree (sp->APNAMBR);
		sp->APNAMBR_Present = ED_FALSE;
	}
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->WLANOffloadIndication_Present) {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
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
	if (sp->HeaderCompressionCfg_Present) {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
		sp->HeaderCompressionCfg_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NewEPSQoS_Present == present) return ED_NO_ERRORS;
	sp->NewEPSQoS_Present = present;
	if (present) {
		/*-->*/sp->NewEPSQoS = (c_EPS_QOS*)EDAlloc (sizeof (c_EPS_QOS));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NewEPSQoS)
		INIT_c_EPS_QOS (sp->NewEPSQoS);
	} else {
		FREE_c_EPS_QOS (sp->NewEPSQoS);
		EDFree (sp->NewEPSQoS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TFT_Present == present) return ED_NO_ERRORS;
	sp->TFT_Present = present;
	if (present) {
		/*-->*/sp->TFT = (c_epsTrafficFlowTemplate*)EDAlloc (sizeof (c_epsTrafficFlowTemplate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TFT)
		INIT_c_epsTrafficFlowTemplate (sp->TFT);
	} else {
		FREE_c_epsTrafficFlowTemplate (sp->TFT);
		EDFree (sp->TFT);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NewQoS_Present == present) return ED_NO_ERRORS;
	sp->NewQoS_Present = present;
	if (present) {
		/*-->*/sp->NewQoS = (c_epsQualityOfServ*)EDAlloc (sizeof (c_epsQualityOfServ));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NewQoS)
		INIT_c_epsQualityOfServ (sp->NewQoS);
	} else {
		FREE_c_epsQualityOfServ (sp->NewQoS);
		EDFree (sp->NewQoS);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NegotiatedLLCSAPI_Present == present) return ED_NO_ERRORS;
	sp->NegotiatedLLCSAPI_Present = present;
	if (present) {
		/*-->*/sp->NegotiatedLLCSAPI = (c_epsLlcServAccessPointId*)EDAlloc (sizeof (c_epsLlcServAccessPointId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NegotiatedLLCSAPI)
		INIT_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
	} else {
		FREE_c_epsLlcServAccessPointId (sp->NegotiatedLLCSAPI);
		EDFree (sp->NegotiatedLLCSAPI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PacketFlowIdentifier_Present == present) return ED_NO_ERRORS;
	sp->PacketFlowIdentifier_Present = present;
	if (present) {
		/*-->*/sp->PacketFlowIdentifier = (c_epsPacketFlowIdentifie*)EDAlloc (sizeof (c_epsPacketFlowIdentifie));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PacketFlowIdentifier)
		INIT_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
	} else {
		FREE_c_epsPacketFlowIdentifie (sp->PacketFlowIdentifier);
		EDFree (sp->PacketFlowIdentifier);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->APNAMBR_Present == present) return ED_NO_ERRORS;
	sp->APNAMBR_Present = present;
	if (present) {
		/*-->*/sp->APNAMBR = (c_APNAggregateMaxBitRate*)EDAlloc (sizeof (c_APNAggregateMaxBitRate));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->APNAMBR)
		INIT_c_APNAggregateMaxBitRate (sp->APNAMBR);
	} else {
		FREE_c_APNAggregateMaxBitRate (sp->APNAMBR);
		EDFree (sp->APNAMBR);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->WLANOffloadIndication_Present == present) return ED_NO_ERRORS;
	sp->WLANOffloadIndication_Present = present;
	if (present) {
		/*-->*/sp->WLANOffloadIndication = (c_epsWLANOffloadAcceptability*)EDAlloc (sizeof (c_epsWLANOffloadAcceptability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->WLANOffloadIndication)
		INIT_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
	} else {
		FREE_c_epsWLANOffloadAcceptability (sp->WLANOffloadIndication);
		EDFree (sp->WLANOffloadIndication);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HeaderCompressionCfg_Present == present) return ED_NO_ERRORS;
	sp->HeaderCompressionCfg_Present = present;
	if (present) {
		/*-->*/sp->HeaderCompressionCfg = (c_HeaderCompressionCfg*)EDAlloc (sizeof (c_HeaderCompressionCfg));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HeaderCompressionCfg)
		INIT_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
	} else {
		FREE_c_HeaderCompressionCfg (sp->HeaderCompressionCfg);
		EDFree (sp->HeaderCompressionCfg);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EPS_NOTIFICATION */
void FREE_c_EPS_NOTIFICATION (c_EPS_NOTIFICATION* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_PDN_CONNECTIVITY_REJECT */
void FREE_c_PDN_CONNECTIVITY_REJECT (c_PDN_CONNECTIVITY_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->BackOffTimer_Present) {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
		sp->BackOffTimer_Present = ED_FALSE;
	}
	if (sp->ReAttemptIndicator_Present) {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
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
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->BackOffTimer_Present == present) return ED_NO_ERRORS;
	sp->BackOffTimer_Present = present;
	if (present) {
		/*-->*/sp->BackOffTimer = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->BackOffTimer)
		INIT_c_epsGprsTimer (sp->BackOffTimer);
	} else {
		FREE_c_epsGprsTimer (sp->BackOffTimer);
		EDFree (sp->BackOffTimer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ReAttemptIndicator_Present == present) return ED_NO_ERRORS;
	sp->ReAttemptIndicator_Present = present;
	if (present) {
		/*-->*/sp->ReAttemptIndicator = (c_epsReAttemptIndicator*)EDAlloc (sizeof (c_epsReAttemptIndicator));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ReAttemptIndicator)
		INIT_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
	} else {
		FREE_c_epsReAttemptIndicator (sp->ReAttemptIndicator);
		EDFree (sp->ReAttemptIndicator);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NBIFOMContainer_Present == present) return ED_NO_ERRORS;
	sp->NBIFOMContainer_Present = present;
	if (present) {
		/*-->*/sp->NBIFOMContainer = (c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer*)EDAlloc (sizeof (c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NBIFOMContainer)
		
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

int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_PDN_DISCONNECT_REJECT */
void FREE_c_PDN_DISCONNECT_REJECT (c_PDN_DISCONNECT_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
		sp->ProtocolConfigurationOptions_Present = ED_FALSE;
	}
	if (sp->ExtendedProtocolConfigurationOptions_Present) {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
		sp->ExtendedProtocolConfigurationOptions_Present = ED_FALSE;
	}

}

int SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (c_PDN_DISCONNECT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ProtocolConfigurationOptions);
		EDFree (sp->ProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (c_PDN_DISCONNECT_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedProtocolConfigurationOptions_Present == present) return ED_NO_ERRORS;
	sp->ExtendedProtocolConfigurationOptions_Present = present;
	if (present) {
		/*-->*/sp->ExtendedProtocolConfigurationOptions = (c_epsProtocolCfgOpt*)EDAlloc (sizeof (c_epsProtocolCfgOpt));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedProtocolConfigurationOptions)
		INIT_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
	} else {
		FREE_c_epsProtocolCfgOpt (sp->ExtendedProtocolConfigurationOptions);
		EDFree (sp->ExtendedProtocolConfigurationOptions);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_REMOTE_UE_REPORT_RESPONSE */
void FREE_c_REMOTE_UE_REPORT_RESPONSE (c_REMOTE_UE_REPORT_RESPONSE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->UserDataContainer.value != NULL) {
		EDFree (sp->UserDataContainer.value);
		sp->UserDataContainer.value = NULL;
	}
	sp->UserDataContainer.usedBits = 0;

}

/* Free function for struct c_EPSMobileIdentity_GUTI */
void FREE_c_EPSMobileIdentity_GUTI (c_EPSMobileIdentity_GUTI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsMobileId_TMGI */
void FREE_c_epsMobileId_TMGI (c_epsMobileId_TMGI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsPlmn */
void FREE_c_epsPlmn (c_epsPlmn* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for variable-sized sequence c_EPSMobileIdentity_IMSI_IdentityDigit */
void FREE_c_EPSMobileIdentity_IMSI_IdentityDigit (c_EPSMobileIdentity_IMSI_IdentityDigit* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_EPSMobileIdentity_IMSI */
void FREE_c_EPSMobileIdentity_IMSI (c_EPSMobileIdentity_IMSI* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->IdentityDigit.data) {EDFree (sp->IdentityDigit.data); sp->IdentityDigit.data = NULL; sp->IdentityDigit.allocatedItems=0; /*FR02A*/}
	if (sp->IdentityDigit.data___LOCATOR) {EDFree (sp->IdentityDigit.data___LOCATOR); sp->IdentityDigit.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for union c_TrackingAreaIdentityList_Item */
void FREE_c_TrackingAreaIdentityList_Item (c_TrackingAreaIdentityList_Item* sp) {
	switch (sp->Present) {
		case U_c_TrackingAreaIdentityList_Item_Type0: {
			FREE_c_PartialTrackingAreaIdentityList_Type0 (sp->u.Type0);
			EDFree (sp->u.Type0);

			break;
		}
		case U_c_TrackingAreaIdentityList_Item_Type1: {
			FREE_c_PartialTrackingAreaIdentityList_Type1 (sp->u.Type1);
			EDFree (sp->u.Type1);

			break;
		}
		case U_c_TrackingAreaIdentityList_Item_Type2: {
			FREE_c_PartialTrackingAreaIdentityList_Type2 (sp->u.Type2);
			EDFree (sp->u.Type2);

			break;
		}

		default:;
	}
	sp->Present = U_c_TrackingAreaIdentityList_Item_NONE;
}

/* Set-present function for c_TrackingAreaIdentityList_Item LEVEL = -1 */
int GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item (c_TrackingAreaIdentityList_Item* sp, TPRESENT_c_TrackingAreaIdentityList_Item toBeSetPresent) 
{
	FREE_c_TrackingAreaIdentityList_Item (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_TrackingAreaIdentityList_Item_Type0: {
			sp->u.Type0 = (c_PartialTrackingAreaIdentityList_Type0*)EDAlloc (sizeof (c_PartialTrackingAreaIdentityList_Type0));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Type0)
			INIT_c_PartialTrackingAreaIdentityList_Type0 (sp->u.Type0);

			break;
		}
		case U_c_TrackingAreaIdentityList_Item_Type1: {
			sp->u.Type1 = (c_PartialTrackingAreaIdentityList_Type1*)EDAlloc (sizeof (c_PartialTrackingAreaIdentityList_Type1));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Type1)
			INIT_c_PartialTrackingAreaIdentityList_Type1 (sp->u.Type1);

			break;
		}
		case U_c_TrackingAreaIdentityList_Item_Type2: {
			sp->u.Type2 = (c_PartialTrackingAreaIdentityList_Type2*)EDAlloc (sizeof (c_PartialTrackingAreaIdentityList_Type2));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Type2)
			INIT_c_PartialTrackingAreaIdentityList_Type2 (sp->u.Type2);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_epsMobileId_Identity_IdentityDigit */
void FREE_c_epsMobileId_Identity_IdentityDigit (c_epsMobileId_Identity_IdentityDigit* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_epsMobileId_Identity */
void FREE_c_epsMobileId_Identity (c_epsMobileId_Identity* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->IdentityDigit.data) {EDFree (sp->IdentityDigit.data); sp->IdentityDigit.data = NULL; sp->IdentityDigit.allocatedItems=0; /*FR02A*/}
	if (sp->IdentityDigit.data___LOCATOR) {EDFree (sp->IdentityDigit.data___LOCATOR); sp->IdentityDigit.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_epsTBCDEmergencyNumber_Numbers */
void FREE_c_epsTBCDEmergencyNumber_Numbers (c_epsTBCDEmergencyNumber_Numbers* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_epsTBCDEmergencyNumber */
void FREE_c_epsTBCDEmergencyNumber (c_epsTBCDEmergencyNumber* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsServCategory (&(sp->ServiceCategory));
	if (sp->Numbers.data) {EDFree (sp->Numbers.data); sp->Numbers.data = NULL; sp->Numbers.allocatedItems=0; /*FR02A*/}
	if (sp->Numbers.data___LOCATOR) {EDFree (sp->Numbers.data___LOCATOR); sp->Numbers.data___LOCATOR = NULL; /*FR02AL*/}

}

/* Free function for variable-sized sequence c_epsTBCDArray */
void FREE_c_epsTBCDArray (c_epsTBCDArray* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_epsTBCDArray'. Existing items are not changed. */
int SETITEMS_c_epsTBCDArray (c_epsTBCDArray* sequence, int desiredItems)
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

/* Free function for struct c_epsSupportedCodec */
void FREE_c_epsSupportedCodec (c_epsSupportedCodec* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->CodecBitmap.value != NULL) {
		EDFree (sp->CodecBitmap.value);
		sp->CodecBitmap.value = NULL;
	}
	sp->CodecBitmap.usedBits = 0;

}

/* Free function for struct c_EPSBearerContextStatus */
void FREE_c_EPSBearerContextStatus (c_EPSBearerContextStatus* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AdditionalUpdateResult */
void FREE_c_AdditionalUpdateResult (c_AdditionalUpdateResult* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsAdditionalUpdateType */
void FREE_c_epsAdditionalUpdateType (c_epsAdditionalUpdateType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPSDetachType */
void FREE_c_EPSDetachType (c_EPSDetachType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPSNetworkFeatureSupport */
void FREE_c_EPSNetworkFeatureSupport (c_EPSNetworkFeatureSupport* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPSUpdateType */
void FREE_c_EPSUpdateType (c_EPSUpdateType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_KSIAndSequenceNumber */
void FREE_c_KSIAndSequenceNumber (c_KSIAndSequenceNumber* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NASKeySetIdentifier */
void FREE_c_NASKeySetIdentifier (c_NASKeySetIdentifier* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_NASSecurityAlgorithms */
void FREE_c_NASSecurityAlgorithms (c_NASSecurityAlgorithms* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_ExtendedEMMCause */
void FREE_c_ExtendedEMMCause (c_ExtendedEMMCause* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TrackingAreaIdentity */
void FREE_c_TrackingAreaIdentity (c_TrackingAreaIdentity* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_GUTIType */
void FREE_c_GUTIType (c_GUTIType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_DataServiceType */
void FREE_c_DataServiceType (c_DataServiceType* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_HeaderCompressionCfgStatus */
void FREE_c_HeaderCompressionCfgStatus (c_HeaderCompressionCfgStatus* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsLocationAreaId */
void FREE_c_epsLocationAreaId (c_epsLocationAreaId* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsMobileStationClassmark2 */
void FREE_c_epsMobileStationClassmark2 (c_epsMobileStationClassmark2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsMSNetworkFeatureSupport */
void FREE_c_epsMSNetworkFeatureSupport (c_epsMSNetworkFeatureSupport* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsNetwkName */
void FREE_c_epsNetwkName (c_epsNetwkName* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TextString.value != NULL) {
		EDFree (sp->TextString.value);
		sp->TextString.value = NULL;
	}
	sp->TextString.usedBits = 0;

}

/* Free function for struct c_epsTimeZoneAndTime */
void FREE_c_epsTimeZoneAndTime (c_epsTimeZoneAndTime* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsDaylightSavingTime */
void FREE_c_epsDaylightSavingTime (c_epsDaylightSavingTime* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsTmsiStatus */
void FREE_c_epsTmsiStatus (c_epsTmsiStatus* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsDrxParam */
void FREE_c_epsDrxParam (c_epsDrxParam* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsVoiceDomainPreferenceAndUEsUsageSetting */
void FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (c_epsVoiceDomainPreferenceAndUEsUsageSetting* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsNetworkResourceIdentifierContainer */
void FREE_c_epsNetworkResourceIdentifierContainer (c_epsNetworkResourceIdentifierContainer* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsExtendedDRXParameters */
void FREE_c_epsExtendedDRXParameters (c_epsExtendedDRXParameters* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsGprsTimer2 */
void FREE_c_epsGprsTimer2 (c_epsGprsTimer2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsCallingPartyBcdNum */
void FREE_c_epsCallingPartyBcdNum (c_epsCallingPartyBcdNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsTBCDArray (&(sp->Number));

}

/* Free function for variable-sized sequence c_PartialTrackingAreaIdentityList */
void FREE_c_PartialTrackingAreaIdentityList (c_PartialTrackingAreaIdentityList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_TrackingAreaIdentityList_Item (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_PartialTrackingAreaIdentityList'. Existing items are not changed. */
int SETITEMS_c_PartialTrackingAreaIdentityList (c_PartialTrackingAreaIdentityList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_TrackingAreaIdentityList_Item** tmp;
		tmp = (c_TrackingAreaIdentityList_Item**)EDAlloc (sizeof (c_TrackingAreaIdentityList_Item*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_TrackingAreaIdentityList_Item*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_TrackingAreaIdentityList_Item*)EDAlloc (sizeof (c_TrackingAreaIdentityList_Item));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_TrackingAreaIdentityList_Item (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_TrackingAreaIdentityList_Item (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_epsPlmnList */
void FREE_c_epsPlmnList (c_epsPlmnList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_epsPlmn (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_epsPlmnList'. Existing items are not changed. */
int SETITEMS_c_epsPlmnList (c_epsPlmnList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsPlmn** tmp;
		tmp = (c_epsPlmn**)EDAlloc (sizeof (c_epsPlmn*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsPlmn*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsPlmn*)EDAlloc (sizeof (c_epsPlmn));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_epsPlmn (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_epsPlmn (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_epsEmergencyNumberList */
void FREE_c_epsEmergencyNumberList (c_epsEmergencyNumberList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_epsTBCDEmergencyNumber (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_epsEmergencyNumberList'. Existing items are not changed. */
int SETITEMS_c_epsEmergencyNumberList (c_epsEmergencyNumberList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsTBCDEmergencyNumber** tmp;
		tmp = (c_epsTBCDEmergencyNumber**)EDAlloc (sizeof (c_epsTBCDEmergencyNumber*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsTBCDEmergencyNumber*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsTBCDEmergencyNumber*)EDAlloc (sizeof (c_epsTBCDEmergencyNumber));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_epsTBCDEmergencyNumber (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_epsTBCDEmergencyNumber (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_epsSupportedCodecList */
void FREE_c_epsSupportedCodecList (c_epsSupportedCodecList* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		FREE_c_epsSupportedCodec (sp->data[i]);
		EDFree (sp->data[i]);
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* SETITEMS commands for type 'c_epsSupportedCodecList'. Existing items are not changed. */
int SETITEMS_c_epsSupportedCodecList (c_epsSupportedCodecList* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsSupportedCodec** tmp;
		tmp = (c_epsSupportedCodec**)EDAlloc (sizeof (c_epsSupportedCodec*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsSupportedCodec*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsSupportedCodec*)EDAlloc (sizeof (c_epsSupportedCodec));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_epsSupportedCodec (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_epsSupportedCodec (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_UENetworkCapability */
void FREE_c_UENetworkCapability (c_UENetworkCapability* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->octet_5_Present) {
		EDFree (sp->octet_5);
		sp->octet_5 = NULL;
		sp->octet_5_Present = ED_FALSE;
	}
	if (sp->octet_6_Present) {
		EDFree (sp->octet_6);
		sp->octet_6 = NULL;
		sp->octet_6_Present = ED_FALSE;
	}
	if (sp->octet_7_Present) {
		EDFree (sp->octet_7);
		sp->octet_7 = NULL;
		sp->octet_7_Present = ED_FALSE;
	}
	if (sp->octet_8_Present) {
		EDFree (sp->octet_8);
		sp->octet_8 = NULL;
		sp->octet_8_Present = ED_FALSE;
	}

}

int SETPRESENT_c_UENetworkCapability_octet_5 (c_UENetworkCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->octet_5_Present == present) return ED_NO_ERRORS;
	sp->octet_5_Present = present;
	if (present) {
		/*-->*/sp->octet_5 = (c_UENetworkCapability_octet_5*)EDAlloc (sizeof (c_UENetworkCapability_octet_5));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->octet_5)
		ED_RESET_MEM (sp->octet_5, sizeof (c_UENetworkCapability_octet_5));
		(sp->octet_5->UEA0) = 0;
		(sp->octet_5->UEA1) = 0;
		(sp->octet_5->UEA2) = 0;
		(sp->octet_5->UEA3) = 0;
		(sp->octet_5->UEA4) = 0;
		(sp->octet_5->UEA5) = 0;
		(sp->octet_5->UEA6) = 0;
		(sp->octet_5->UEA7) = 0;
	} else {
		EDFree (sp->octet_5);
		sp->octet_5 = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_UENetworkCapability_octet_6 (c_UENetworkCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->octet_6_Present == present) return ED_NO_ERRORS;
	sp->octet_6_Present = present;
	if (present) {
		/*-->*/sp->octet_6 = (c_UENetworkCapability_octet_6*)EDAlloc (sizeof (c_UENetworkCapability_octet_6));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->octet_6)
		ED_RESET_MEM (sp->octet_6, sizeof (c_UENetworkCapability_octet_6));
		(sp->octet_6->UCS2) = 0;
		(sp->octet_6->UIA1) = 0;
		(sp->octet_6->UIA2) = 0;
		(sp->octet_6->UIA3) = 0;
		(sp->octet_6->UIA4) = 0;
		(sp->octet_6->UIA5) = 0;
		(sp->octet_6->UIA6) = 0;
		(sp->octet_6->UIA7) = 0;
	} else {
		EDFree (sp->octet_6);
		sp->octet_6 = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_UENetworkCapability_octet_7 (c_UENetworkCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->octet_7_Present == present) return ED_NO_ERRORS;
	sp->octet_7_Present = present;
	if (present) {
		/*-->*/sp->octet_7 = (c_UENetworkCapability_octet_7*)EDAlloc (sizeof (c_UENetworkCapability_octet_7));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->octet_7)
		ED_RESET_MEM (sp->octet_7, sizeof (c_UENetworkCapability_octet_7));
		(sp->octet_7->H245_ASH) = 0;
		(sp->octet_7->ACC_CSFB) = 0;
		(sp->octet_7->LPP) = 0;
		(sp->octet_7->LCS) = 0;
		(sp->octet_7->p1xSR_VCC) = 0;
		(sp->octet_7->ISR) = 0;
	} else {
		EDFree (sp->octet_7);
		sp->octet_7 = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_UENetworkCapability_octet_8 (c_UENetworkCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->octet_8_Present == present) return ED_NO_ERRORS;
	sp->octet_8_Present = present;
	if (present) {
		/*-->*/sp->octet_8 = (c_UENetworkCapability_octet_8*)EDAlloc (sizeof (c_UENetworkCapability_octet_8));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->octet_8)
		ED_RESET_MEM (sp->octet_8, sizeof (c_UENetworkCapability_octet_8));
		(sp->octet_8->ePCO) = 0;
		(sp->octet_8->HC_CP_CIoT) = 0;
		(sp->octet_8->ERw_oPDN) = 0;
		(sp->octet_8->S1_U_data) = 0;
		(sp->octet_8->UP_CIoT) = 0;
		(sp->octet_8->CP_CIoT) = 0;
		(sp->octet_8->Prose_relay) = 0;
		(sp->octet_8->ProSe_dc) = 0;
	} else {
		EDFree (sp->octet_8);
		sp->octet_8 = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_UESecurityCapability */
void FREE_c_UESecurityCapability (c_UESecurityCapability* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->UEA_UIA_Present) {
		EDFree (sp->UEA_UIA);
		sp->UEA_UIA = NULL;
		sp->UEA_UIA_Present = ED_FALSE;
	}
	if (sp->GEA_Present) {
		EDFree (sp->GEA);
		sp->GEA = NULL;
		sp->GEA_Present = ED_FALSE;
	}

}

int SETPRESENT_c_UESecurityCapability_UEA_UIA (c_UESecurityCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UEA_UIA_Present == present) return ED_NO_ERRORS;
	sp->UEA_UIA_Present = present;
	if (present) {
		/*-->*/sp->UEA_UIA = (c_UESecurityCapability_UEA_UIA*)EDAlloc (sizeof (c_UESecurityCapability_UEA_UIA));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UEA_UIA)
		ED_RESET_MEM (sp->UEA_UIA, sizeof (c_UESecurityCapability_UEA_UIA));
		(sp->UEA_UIA->UEA0) = 0;
		(sp->UEA_UIA->UEA1) = 0;
		(sp->UEA_UIA->UEA2) = 0;
		(sp->UEA_UIA->UEA3) = 0;
		(sp->UEA_UIA->UEA4) = 0;
		(sp->UEA_UIA->UEA5) = 0;
		(sp->UEA_UIA->UEA6) = 0;
		(sp->UEA_UIA->UEA7) = 0;
		(sp->UEA_UIA->UIA1) = 0;
		(sp->UEA_UIA->UIA2) = 0;
		(sp->UEA_UIA->UIA3) = 0;
		(sp->UEA_UIA->UIA4) = 0;
		(sp->UEA_UIA->UIA5) = 0;
		(sp->UEA_UIA->UIA6) = 0;
		(sp->UEA_UIA->UIA7) = 0;
	} else {
		EDFree (sp->UEA_UIA);
		sp->UEA_UIA = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_UESecurityCapability_GEA (c_UESecurityCapability* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->GEA_Present == present) return ED_NO_ERRORS;
	sp->GEA_Present = present;
	if (present) {
		/*-->*/sp->GEA = (c_UESecurityCapability_GEA*)EDAlloc (sizeof (c_UESecurityCapability_GEA));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->GEA)
		ED_RESET_MEM (sp->GEA, sizeof (c_UESecurityCapability_GEA));
		(sp->GEA->GEA1) = 0;
		(sp->GEA->GEA2) = 0;
		(sp->GEA->GEA3) = 0;
		(sp->GEA->GEA4) = 0;
		(sp->GEA->GEA5) = 0;
		(sp->GEA->GEA6) = 0;
		(sp->GEA->GEA7) = 0;
	} else {
		EDFree (sp->GEA);
		sp->GEA = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_epsClassmark3Value */
void FREE_c_epsClassmark3Value (c_epsClassmark3Value* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsMsNetwkCpblty */
void FREE_c_epsMsNetwkCpblty (c_epsMsNetwkCpblty* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for union c_EPSMobileIdentity */
void FREE_c_EPSMobileIdentity (c_EPSMobileIdentity* sp) {
	switch (sp->Present) {
		case U_c_EPSMobileIdentity_IMSI: {
			FREE_c_EPSMobileIdentity_IMSI (sp->u.IMSI);
			EDFree (sp->u.IMSI);

			break;
		}
		case U_c_EPSMobileIdentity_GUTI: {
			FREE_c_EPSMobileIdentity_GUTI (sp->u.GUTI);
			EDFree (sp->u.GUTI);

			break;
		}

		default:;
	}
	sp->Present = U_c_EPSMobileIdentity_NONE;
}

/* Set-present function for c_EPSMobileIdentity LEVEL = -1 */
int GLOB_SETPRESENT_c_EPSMobileIdentity (c_EPSMobileIdentity* sp, TPRESENT_c_EPSMobileIdentity toBeSetPresent) 
{
	FREE_c_EPSMobileIdentity (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_EPSMobileIdentity_IMSI: {
			sp->u.IMSI = (c_EPSMobileIdentity_IMSI*)EDAlloc (sizeof (c_EPSMobileIdentity_IMSI));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.IMSI)
			INIT_c_EPSMobileIdentity_IMSI (sp->u.IMSI);

			break;
		}
		case U_c_EPSMobileIdentity_GUTI: {
			sp->u.GUTI = (c_EPSMobileIdentity_GUTI*)EDAlloc (sizeof (c_EPSMobileIdentity_GUTI));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.GUTI)
			INIT_c_EPSMobileIdentity_GUTI (sp->u.GUTI);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_ESMMessageUp */
void FREE_c_ESMMessageUp (c_ESMMessageUp* sp) {
	switch (sp->Present) {
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT: {
			FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT);
			EDFree (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT: {
			FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT);
			EDFree (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT: {
			FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT);
			EDFree (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT: {
			FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT);
			EDFree (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST: {
			FREE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (sp->u.pBEARER_RESOURCE_ALLOCATION_REQUEST);
			EDFree (sp->u.pBEARER_RESOURCE_ALLOCATION_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST: {
			FREE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (sp->u.pBEARER_RESOURCE_MODIFICATION_REQUEST);
			EDFree (sp->u.pBEARER_RESOURCE_MODIFICATION_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT: {
			FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT);
			EDFree (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pESM_DATA_TRANSPORT: {
			FREE_c_ESM_DATA_TRANSPORT (sp->u.pESM_DATA_TRANSPORT);
			EDFree (sp->u.pESM_DATA_TRANSPORT);

			break;
		}
		case U_c_ESMMessageUp_pESM_DUMMY_MESSAGE: {
			FREE_c_ESM_DUMMY_MESSAGE (sp->u.pESM_DUMMY_MESSAGE);
			EDFree (sp->u.pESM_DUMMY_MESSAGE);

			break;
		}
		case U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE: {
			FREE_c_ESM_INFORMATION_RESPONSE (sp->u.pESM_INFORMATION_RESPONSE);
			EDFree (sp->u.pESM_INFORMATION_RESPONSE);

			break;
		}
		case U_c_ESMMessageUp_pESM_STATUS: {
			FREE_c_ESM_STATUS (sp->u.pESM_STATUS);
			EDFree (sp->u.pESM_STATUS);

			break;
		}
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT: {
			FREE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT);
			EDFree (sp->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT: {
			FREE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT);
			EDFree (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST: {
			FREE_c_PDN_CONNECTIVITY_REQUEST (sp->u.pPDN_CONNECTIVITY_REQUEST);
			EDFree (sp->u.pPDN_CONNECTIVITY_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST: {
			FREE_c_PDN_DISCONNECT_REQUEST (sp->u.pPDN_DISCONNECT_REQUEST);
			EDFree (sp->u.pPDN_DISCONNECT_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pREMOTE_UE_REPORT: {
			FREE_c_REMOTE_UE_REPORT (sp->u.pREMOTE_UE_REPORT);
			EDFree (sp->u.pREMOTE_UE_REPORT);

			break;
		}

		default:;
	}
	sp->Present = U_c_ESMMessageUp_NONE;
}

/* Set-present function for c_ESMMessageUp LEVEL = -1 */
int GLOB_SETPRESENT_c_ESMMessageUp (c_ESMMessageUp* sp, TPRESENT_c_ESMMessageUp toBeSetPresent) 
{
	FREE_c_ESMMessageUp (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT: {
			sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT)
			INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT: {
			sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT)
			INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT: {
			sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT = (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT)
			INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT: {
			sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT = (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT*)EDAlloc (sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT)
			INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST: {
			sp->u.pBEARER_RESOURCE_ALLOCATION_REQUEST = (c_BEARER_RESOURCE_ALLOCATION_REQUEST*)EDAlloc (sizeof (c_BEARER_RESOURCE_ALLOCATION_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pBEARER_RESOURCE_ALLOCATION_REQUEST)
			INIT_c_BEARER_RESOURCE_ALLOCATION_REQUEST (sp->u.pBEARER_RESOURCE_ALLOCATION_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST: {
			sp->u.pBEARER_RESOURCE_MODIFICATION_REQUEST = (c_BEARER_RESOURCE_MODIFICATION_REQUEST*)EDAlloc (sizeof (c_BEARER_RESOURCE_MODIFICATION_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pBEARER_RESOURCE_MODIFICATION_REQUEST)
			INIT_c_BEARER_RESOURCE_MODIFICATION_REQUEST (sp->u.pBEARER_RESOURCE_MODIFICATION_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT: {
			sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT = (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT)
			INIT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pESM_DATA_TRANSPORT: {
			sp->u.pESM_DATA_TRANSPORT = (c_ESM_DATA_TRANSPORT*)EDAlloc (sizeof (c_ESM_DATA_TRANSPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_DATA_TRANSPORT)
			INIT_c_ESM_DATA_TRANSPORT (sp->u.pESM_DATA_TRANSPORT);

			break;
		}
		case U_c_ESMMessageUp_pESM_DUMMY_MESSAGE: {
			sp->u.pESM_DUMMY_MESSAGE = (c_ESM_DUMMY_MESSAGE*)EDAlloc (sizeof (c_ESM_DUMMY_MESSAGE));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_DUMMY_MESSAGE)
			INIT_c_ESM_DUMMY_MESSAGE (sp->u.pESM_DUMMY_MESSAGE);

			break;
		}
		case U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE: {
			sp->u.pESM_INFORMATION_RESPONSE = (c_ESM_INFORMATION_RESPONSE*)EDAlloc (sizeof (c_ESM_INFORMATION_RESPONSE));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_INFORMATION_RESPONSE)
			INIT_c_ESM_INFORMATION_RESPONSE (sp->u.pESM_INFORMATION_RESPONSE);

			break;
		}
		case U_c_ESMMessageUp_pESM_STATUS: {
			sp->u.pESM_STATUS = (c_ESM_STATUS*)EDAlloc (sizeof (c_ESM_STATUS));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_STATUS)
			INIT_c_ESM_STATUS (sp->u.pESM_STATUS);

			break;
		}
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT: {
			sp->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT = (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT)
			INIT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (sp->u.pMODIFY_EPS_BEARER_CONTEXT_ACCEPT);

			break;
		}
		case U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT: {
			sp->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT = (c_MODIFY_EPS_BEARER_CONTEXT_REJECT*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT)
			INIT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REJECT);

			break;
		}
		case U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST: {
			sp->u.pPDN_CONNECTIVITY_REQUEST = (c_PDN_CONNECTIVITY_REQUEST*)EDAlloc (sizeof (c_PDN_CONNECTIVITY_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pPDN_CONNECTIVITY_REQUEST)
			INIT_c_PDN_CONNECTIVITY_REQUEST (sp->u.pPDN_CONNECTIVITY_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST: {
			sp->u.pPDN_DISCONNECT_REQUEST = (c_PDN_DISCONNECT_REQUEST*)EDAlloc (sizeof (c_PDN_DISCONNECT_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pPDN_DISCONNECT_REQUEST)
			INIT_c_PDN_DISCONNECT_REQUEST (sp->u.pPDN_DISCONNECT_REQUEST);

			break;
		}
		case U_c_ESMMessageUp_pREMOTE_UE_REPORT: {
			sp->u.pREMOTE_UE_REPORT = (c_REMOTE_UE_REPORT*)EDAlloc (sizeof (c_REMOTE_UE_REPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pREMOTE_UE_REPORT)
			INIT_c_REMOTE_UE_REPORT (sp->u.pREMOTE_UE_REPORT);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_ESMMessageDn */
void FREE_c_ESMMessageDn (c_ESMMessageDn* sp) {
	switch (sp->Present) {
		case U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST: {
			FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST);
			EDFree (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST: {
			FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST);
			EDFree (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT: {
			FREE_c_BEARER_RESOURCE_ALLOCATION_REJECT (sp->u.pBEARER_RESOURCE_ALLOCATION_REJECT);
			EDFree (sp->u.pBEARER_RESOURCE_ALLOCATION_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT: {
			FREE_c_BEARER_RESOURCE_MODIFICATION_REJECT (sp->u.pBEARER_RESOURCE_MODIFICATION_REJECT);
			EDFree (sp->u.pBEARER_RESOURCE_MODIFICATION_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST: {
			FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST);
			EDFree (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pEPS_NOTIFICATION: {
			FREE_c_EPS_NOTIFICATION (sp->u.pEPS_NOTIFICATION);
			EDFree (sp->u.pEPS_NOTIFICATION);

			break;
		}
		case U_c_ESMMessageDn_pESM_DATA_TRANSPORT: {
			FREE_c_ESM_DATA_TRANSPORT (sp->u.pESM_DATA_TRANSPORT);
			EDFree (sp->u.pESM_DATA_TRANSPORT);

			break;
		}
		case U_c_ESMMessageDn_pESM_DUMMY_MESSAGE: {
			FREE_c_ESM_DUMMY_MESSAGE (sp->u.pESM_DUMMY_MESSAGE);
			EDFree (sp->u.pESM_DUMMY_MESSAGE);

			break;
		}
		case U_c_ESMMessageDn_pESM_INFORMATION_REQUEST: {
			FREE_c_ESM_INFORMATION_REQUEST (sp->u.pESM_INFORMATION_REQUEST);
			EDFree (sp->u.pESM_INFORMATION_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pESM_STATUS: {
			FREE_c_ESM_STATUS (sp->u.pESM_STATUS);
			EDFree (sp->u.pESM_STATUS);

			break;
		}
		case U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST: {
			FREE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST);
			EDFree (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT: {
			FREE_c_PDN_CONNECTIVITY_REJECT (sp->u.pPDN_CONNECTIVITY_REJECT);
			EDFree (sp->u.pPDN_CONNECTIVITY_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT: {
			FREE_c_PDN_DISCONNECT_REJECT (sp->u.pPDN_DISCONNECT_REJECT);
			EDFree (sp->u.pPDN_DISCONNECT_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE: {
			FREE_c_REMOTE_UE_REPORT_RESPONSE (sp->u.pREMOTE_UE_REPORT_RESPONSE);
			EDFree (sp->u.pREMOTE_UE_REPORT_RESPONSE);

			break;
		}

		default:;
	}
	sp->Present = U_c_ESMMessageDn_NONE;
}

/* Set-present function for c_ESMMessageDn LEVEL = -1 */
int GLOB_SETPRESENT_c_ESMMessageDn (c_ESMMessageDn* sp, TPRESENT_c_ESMMessageDn toBeSetPresent) 
{
	FREE_c_ESMMessageDn (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST: {
			sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST = (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST*)EDAlloc (sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST)
			INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (sp->u.pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST: {
			sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST = (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST*)EDAlloc (sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST)
			INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (sp->u.pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT: {
			sp->u.pBEARER_RESOURCE_ALLOCATION_REJECT = (c_BEARER_RESOURCE_ALLOCATION_REJECT*)EDAlloc (sizeof (c_BEARER_RESOURCE_ALLOCATION_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pBEARER_RESOURCE_ALLOCATION_REJECT)
			INIT_c_BEARER_RESOURCE_ALLOCATION_REJECT (sp->u.pBEARER_RESOURCE_ALLOCATION_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT: {
			sp->u.pBEARER_RESOURCE_MODIFICATION_REJECT = (c_BEARER_RESOURCE_MODIFICATION_REJECT*)EDAlloc (sizeof (c_BEARER_RESOURCE_MODIFICATION_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pBEARER_RESOURCE_MODIFICATION_REJECT)
			INIT_c_BEARER_RESOURCE_MODIFICATION_REJECT (sp->u.pBEARER_RESOURCE_MODIFICATION_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST: {
			sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST = (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST*)EDAlloc (sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST)
			INIT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (sp->u.pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pEPS_NOTIFICATION: {
			sp->u.pEPS_NOTIFICATION = (c_EPS_NOTIFICATION*)EDAlloc (sizeof (c_EPS_NOTIFICATION));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pEPS_NOTIFICATION)
			INIT_c_EPS_NOTIFICATION (sp->u.pEPS_NOTIFICATION);

			break;
		}
		case U_c_ESMMessageDn_pESM_DATA_TRANSPORT: {
			sp->u.pESM_DATA_TRANSPORT = (c_ESM_DATA_TRANSPORT*)EDAlloc (sizeof (c_ESM_DATA_TRANSPORT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_DATA_TRANSPORT)
			INIT_c_ESM_DATA_TRANSPORT (sp->u.pESM_DATA_TRANSPORT);

			break;
		}
		case U_c_ESMMessageDn_pESM_DUMMY_MESSAGE: {
			sp->u.pESM_DUMMY_MESSAGE = (c_ESM_DUMMY_MESSAGE*)EDAlloc (sizeof (c_ESM_DUMMY_MESSAGE));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_DUMMY_MESSAGE)
			INIT_c_ESM_DUMMY_MESSAGE (sp->u.pESM_DUMMY_MESSAGE);

			break;
		}
		case U_c_ESMMessageDn_pESM_INFORMATION_REQUEST: {
			sp->u.pESM_INFORMATION_REQUEST = (c_ESM_INFORMATION_REQUEST*)EDAlloc (sizeof (c_ESM_INFORMATION_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_INFORMATION_REQUEST)
			INIT_c_ESM_INFORMATION_REQUEST (sp->u.pESM_INFORMATION_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pESM_STATUS: {
			sp->u.pESM_STATUS = (c_ESM_STATUS*)EDAlloc (sizeof (c_ESM_STATUS));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pESM_STATUS)
			INIT_c_ESM_STATUS (sp->u.pESM_STATUS);

			break;
		}
		case U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST: {
			sp->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST = (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST*)EDAlloc (sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST)
			INIT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (sp->u.pMODIFY_EPS_BEARER_CONTEXT_REQUEST);

			break;
		}
		case U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT: {
			sp->u.pPDN_CONNECTIVITY_REJECT = (c_PDN_CONNECTIVITY_REJECT*)EDAlloc (sizeof (c_PDN_CONNECTIVITY_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pPDN_CONNECTIVITY_REJECT)
			INIT_c_PDN_CONNECTIVITY_REJECT (sp->u.pPDN_CONNECTIVITY_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT: {
			sp->u.pPDN_DISCONNECT_REJECT = (c_PDN_DISCONNECT_REJECT*)EDAlloc (sizeof (c_PDN_DISCONNECT_REJECT));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pPDN_DISCONNECT_REJECT)
			INIT_c_PDN_DISCONNECT_REJECT (sp->u.pPDN_DISCONNECT_REJECT);

			break;
		}
		case U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE: {
			sp->u.pREMOTE_UE_REPORT_RESPONSE = (c_REMOTE_UE_REPORT_RESPONSE*)EDAlloc (sizeof (c_REMOTE_UE_REPORT_RESPONSE));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.pREMOTE_UE_REPORT_RESPONSE)
			INIT_c_REMOTE_UE_REPORT_RESPONSE (sp->u.pREMOTE_UE_REPORT_RESPONSE);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for union c_epsMobileId */
void FREE_c_epsMobileId (c_epsMobileId* sp) {
	switch (sp->Present) {
		case U_c_epsMobileId_Identity: {
			FREE_c_epsMobileId_Identity (sp->u.Identity);
			EDFree (sp->u.Identity);

			break;
		}
		case U_c_epsMobileId_TMGI: {
			FREE_c_epsMobileId_TMGI (sp->u.TMGI);
			EDFree (sp->u.TMGI);

			break;
		}

		default:;
	}
	sp->Present = U_c_epsMobileId_NONE;
}

/* Set-present function for c_epsMobileId LEVEL = -1 */
int GLOB_SETPRESENT_c_epsMobileId (c_epsMobileId* sp, TPRESENT_c_epsMobileId toBeSetPresent) 
{
	FREE_c_epsMobileId (sp);
	sp->Present = toBeSetPresent;
	
	switch (toBeSetPresent) {
		case U_c_epsMobileId_Identity: {
			sp->u.Identity = (c_epsMobileId_Identity*)EDAlloc (sizeof (c_epsMobileId_Identity));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.Identity)
			INIT_c_epsMobileId_Identity (sp->u.Identity);

			break;
		}
		case U_c_epsMobileId_TMGI: {
			sp->u.TMGI = (c_epsMobileId_TMGI*)EDAlloc (sizeof (c_epsMobileId_TMGI));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->u.TMGI)
			INIT_c_epsMobileId_TMGI (sp->u.TMGI);

			break;
		}
		default:;	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ATTACH_COMPLETE */
void FREE_c_ATTACH_COMPLETE (c_ATTACH_COMPLETE* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_ESMMessageUp (&(sp->ESMMessageContainer));

}

/* Free function for struct c_ATTACH_REQUEST */
void FREE_c_ATTACH_REQUEST (c_ATTACH_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	FREE_c_EPSMobileIdentity (&(sp->EPSMobileIdentity));
	FREE_c_UENetworkCapability (&(sp->UENetworkCapability));
	FREE_c_ESMMessageUp (&(sp->ESMMessageContainer));
	if (sp->OldPTMSISignature_Present) {
		EDFree (sp->OldPTMSISignature);
		sp->OldPTMSISignature_Present = ED_FALSE;
	}
	if (sp->AdditionalGUTI_Present) {
		FREE_c_EPSMobileIdentity (sp->AdditionalGUTI);
		EDFree (sp->AdditionalGUTI);
		sp->AdditionalGUTI_Present = ED_FALSE;
	}
	if (sp->LastVisitedRegisteredTAI_Present) {
		FREE_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
		EDFree (sp->LastVisitedRegisteredTAI);
		sp->LastVisitedRegisteredTAI_Present = ED_FALSE;
	}
	if (sp->DRXParameter_Present) {
		FREE_c_epsDrxParam (sp->DRXParameter);
		EDFree (sp->DRXParameter);
		sp->DRXParameter_Present = ED_FALSE;
	}
	if (sp->MSNetworkCapability_Present) {
		FREE_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
		EDFree (sp->MSNetworkCapability);
		sp->MSNetworkCapability_Present = ED_FALSE;
	}
	if (sp->OldLocationAreaIdentification_Present) {
		FREE_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
		EDFree (sp->OldLocationAreaIdentification);
		sp->OldLocationAreaIdentification_Present = ED_FALSE;
	}
	if (sp->TMSIStatus_Present) {
		FREE_c_epsTmsiStatus (sp->TMSIStatus);
		EDFree (sp->TMSIStatus);
		sp->TMSIStatus_Present = ED_FALSE;
	}
	if (sp->epsMobileStationClassmark2_Present) {
		FREE_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
		EDFree (sp->epsMobileStationClassmark2);
		sp->epsMobileStationClassmark2_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark3_Present) {
		FREE_c_epsClassmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
		sp->MobileStationClassmark3_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_epsSupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateType_Present) {
		FREE_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
		sp->AdditionalUpdateType_Present = ED_FALSE;
	}
	if (sp->VoiceDomainPref_Present) {
		FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
		EDFree (sp->VoiceDomainPref);
		sp->VoiceDomainPref_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->OldGUTIType_Present) {
		FREE_c_GUTIType (sp->OldGUTIType);
		EDFree (sp->OldGUTIType);
		sp->OldGUTIType_Present = ED_FALSE;
	}
	if (sp->MSNetworkFeatureSupport_Present) {
		FREE_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
		sp->MSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->TMSIBasedNRIContainer_Present) {
		FREE_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
		sp->TMSIBasedNRIContainer_Present = ED_FALSE;
	}
	if (sp->T3324ValueGPRSTimer2_Present) {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
		sp->T3324ValueGPRSTimer2_Present = ED_FALSE;
	}
	if (sp->T3412ExtendedValue_Present) {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
		sp->T3412ExtendedValue_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldPTMSISignature_Present == present) return ED_NO_ERRORS;
	sp->OldPTMSISignature_Present = present;
	if (present) {
		/*-->*/sp->OldPTMSISignature = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldPTMSISignature)
		ED_RESET_MEM (sp->OldPTMSISignature, 3);
	} else {
		EDFree (sp->OldPTMSISignature);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalGUTI_Present == present) return ED_NO_ERRORS;
	sp->AdditionalGUTI_Present = present;
	if (present) {
		/*-->*/sp->AdditionalGUTI = (c_EPSMobileIdentity*)EDAlloc (sizeof (c_EPSMobileIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalGUTI)
		INIT_c_EPSMobileIdentity (sp->AdditionalGUTI);
	} else {
		FREE_c_EPSMobileIdentity (sp->AdditionalGUTI);
		EDFree (sp->AdditionalGUTI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LastVisitedRegisteredTAI_Present == present) return ED_NO_ERRORS;
	sp->LastVisitedRegisteredTAI_Present = present;
	if (present) {
		/*-->*/sp->LastVisitedRegisteredTAI = (c_TrackingAreaIdentity*)EDAlloc (sizeof (c_TrackingAreaIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LastVisitedRegisteredTAI)
		INIT_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
	} else {
		FREE_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
		EDFree (sp->LastVisitedRegisteredTAI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_DRXParameter (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DRXParameter_Present == present) return ED_NO_ERRORS;
	sp->DRXParameter_Present = present;
	if (present) {
		/*-->*/sp->DRXParameter = (c_epsDrxParam*)EDAlloc (sizeof (c_epsDrxParam));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DRXParameter)
		INIT_c_epsDrxParam (sp->DRXParameter);
	} else {
		FREE_c_epsDrxParam (sp->DRXParameter);
		EDFree (sp->DRXParameter);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkCapability_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkCapability_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkCapability = (c_epsMsNetwkCpblty*)EDAlloc (sizeof (c_epsMsNetwkCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkCapability)
		INIT_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
	} else {
		FREE_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
		EDFree (sp->MSNetworkCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldLocationAreaIdentification_Present == present) return ED_NO_ERRORS;
	sp->OldLocationAreaIdentification_Present = present;
	if (present) {
		/*-->*/sp->OldLocationAreaIdentification = (c_epsLocationAreaId*)EDAlloc (sizeof (c_epsLocationAreaId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldLocationAreaIdentification)
		INIT_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
	} else {
		FREE_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
		EDFree (sp->OldLocationAreaIdentification);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_TMSIStatus (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIStatus_Present == present) return ED_NO_ERRORS;
	sp->TMSIStatus_Present = present;
	if (present) {
		/*-->*/sp->TMSIStatus = (c_epsTmsiStatus*)EDAlloc (sizeof (c_epsTmsiStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIStatus)
		INIT_c_epsTmsiStatus (sp->TMSIStatus);
	} else {
		FREE_c_epsTmsiStatus (sp->TMSIStatus);
		EDFree (sp->TMSIStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->epsMobileStationClassmark2_Present == present) return ED_NO_ERRORS;
	sp->epsMobileStationClassmark2_Present = present;
	if (present) {
		/*-->*/sp->epsMobileStationClassmark2 = (c_epsMobileStationClassmark2*)EDAlloc (sizeof (c_epsMobileStationClassmark2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->epsMobileStationClassmark2)
		INIT_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
	} else {
		FREE_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
		EDFree (sp->epsMobileStationClassmark2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark3_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark3_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark3 = (c_epsClassmark3Value*)EDAlloc (sizeof (c_epsClassmark3Value));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark3)
		INIT_c_epsClassmark3Value (sp->MobileStationClassmark3);
	} else {
		FREE_c_epsClassmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_epsSupportedCodecList*)EDAlloc (sizeof (c_epsSupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_epsSupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_epsSupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateType_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateType_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateType = (c_epsAdditionalUpdateType*)EDAlloc (sizeof (c_epsAdditionalUpdateType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateType)
		INIT_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
	} else {
		FREE_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->VoiceDomainPref_Present == present) return ED_NO_ERRORS;
	sp->VoiceDomainPref_Present = present;
	if (present) {
		/*-->*/sp->VoiceDomainPref = (c_epsVoiceDomainPreferenceAndUEsUsageSetting*)EDAlloc (sizeof (c_epsVoiceDomainPreferenceAndUEsUsageSetting));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->VoiceDomainPref)
		INIT_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
	} else {
		FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
		EDFree (sp->VoiceDomainPref);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_DeviceProperties (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_OldGUTIType (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldGUTIType_Present == present) return ED_NO_ERRORS;
	sp->OldGUTIType_Present = present;
	if (present) {
		/*-->*/sp->OldGUTIType = (c_GUTIType*)EDAlloc (sizeof (c_GUTIType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldGUTIType)
		INIT_c_GUTIType (sp->OldGUTIType);
	} else {
		FREE_c_GUTIType (sp->OldGUTIType);
		EDFree (sp->OldGUTIType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkFeatureSupport = (c_epsMSNetworkFeatureSupport*)EDAlloc (sizeof (c_epsMSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkFeatureSupport)
		INIT_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
	} else {
		FREE_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIBasedNRIContainer_Present == present) return ED_NO_ERRORS;
	sp->TMSIBasedNRIContainer_Present = present;
	if (present) {
		/*-->*/sp->TMSIBasedNRIContainer = (c_epsNetworkResourceIdentifierContainer*)EDAlloc (sizeof (c_epsNetworkResourceIdentifierContainer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIBasedNRIContainer)
		INIT_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
	} else {
		FREE_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324ValueGPRSTimer2_Present == present) return ED_NO_ERRORS;
	sp->T3324ValueGPRSTimer2_Present = present;
	if (present) {
		/*-->*/sp->T3324ValueGPRSTimer2 = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324ValueGPRSTimer2)
		INIT_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3412ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3412ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3412ExtendedValue = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3412ExtendedValue)
		INIT_c_epsGprsTimer (sp->T3412ExtendedValue);
	} else {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (c_ATTACH_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_epsExtendedDRXParameters*)EDAlloc (sizeof (c_epsExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_FAILURE */
void FREE_c_AUTHENTICATION_FAILURE (c_AUTHENTICATION_FAILURE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthenticationFailureParameter_Present) {
		EDFree (sp->AuthenticationFailureParameter);
		sp->AuthenticationFailureParameter_Present = ED_FALSE;
	}

}

int SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (c_AUTHENTICATION_FAILURE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AuthenticationFailureParameter_Present == present) return ED_NO_ERRORS;
	sp->AuthenticationFailureParameter_Present = present;
	if (present) {
		/*-->*/sp->AuthenticationFailureParameter = (ED_BYTE*)EDAlloc ((size_t)14);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AuthenticationFailureParameter)
		ED_RESET_MEM (sp->AuthenticationFailureParameter, 14);
	} else {
		EDFree (sp->AuthenticationFailureParameter);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_RESPONSE */
void FREE_c_AUTHENTICATION_RESPONSE (c_AUTHENTICATION_RESPONSE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->AuthenticationResponseParameter.value != NULL) {
		EDFree (sp->AuthenticationResponseParameter.value);
		sp->AuthenticationResponseParameter.value = NULL;
	}
	sp->AuthenticationResponseParameter.usedBits = 0;

}

/* Free function for struct c_EPS_DETACH_ACCEPT_UP */
void FREE_c_EPS_DETACH_ACCEPT_UP (c_EPS_DETACH_ACCEPT_UP* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPS_DETACH_REQUEST_UP */
void FREE_c_EPS_DETACH_REQUEST_UP (c_EPS_DETACH_REQUEST_UP* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPSDetachType (&(sp->DetachType));
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	FREE_c_EPSMobileIdentity (&(sp->EPSMobileIdentity));

}

/* Free function for struct c_EMM_STATUS */
void FREE_c_EMM_STATUS (c_EMM_STATUS* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EXTENDED_SERVICE_REQUEST */
void FREE_c_EXTENDED_SERVICE_REQUEST (c_EXTENDED_SERVICE_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	FREE_c_epsMobileId (&(sp->MTMSI));
	if (sp->EPSBearerContextStatus_Present) {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
		sp->EPSBearerContextStatus_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (c_EXTENDED_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSBearerContextStatus_Present == present) return ED_NO_ERRORS;
	sp->EPSBearerContextStatus_Present = present;
	if (present) {
		/*-->*/sp->EPSBearerContextStatus = (c_EPSBearerContextStatus*)EDAlloc (sizeof (c_EPSBearerContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSBearerContextStatus)
		INIT_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
	} else {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties (c_EXTENDED_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GUTI_REALLOCATION_COMPLETE */
void FREE_c_GUTI_REALLOCATION_COMPLETE (c_GUTI_REALLOCATION_COMPLETE* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_IDENTITY_RESPONSE */
void FREE_c_IDENTITY_RESPONSE (c_IDENTITY_RESPONSE* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsMobileId (&(sp->MobileIdentity));

}

/* Free function for struct c_SECURITY_MODE_COMPLETE */
void FREE_c_SECURITY_MODE_COMPLETE (c_SECURITY_MODE_COMPLETE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->IMEISV_Present) {
		FREE_c_epsMobileId (sp->IMEISV);
		EDFree (sp->IMEISV);
		sp->IMEISV_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (c_SECURITY_MODE_COMPLETE* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->IMEISV_Present == present) return ED_NO_ERRORS;
	sp->IMEISV_Present = present;
	if (present) {
		/*-->*/sp->IMEISV = (c_epsMobileId*)EDAlloc (sizeof (c_epsMobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->IMEISV)
		INIT_c_epsMobileId (sp->IMEISV);
	} else {
		FREE_c_epsMobileId (sp->IMEISV);
		EDFree (sp->IMEISV);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SECURITY_MODE_REJECT */
void FREE_c_SECURITY_MODE_REJECT (c_SECURITY_MODE_REJECT* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SECURITY_PROTECTED_NAS_MESSAGE */
void FREE_c_SECURITY_PROTECTED_NAS_MESSAGE (c_SECURITY_PROTECTED_NAS_MESSAGE* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NASMessage.value != NULL) {
		EDFree (sp->NASMessage.value);
		sp->NASMessage.value = NULL;
	}
	sp->NASMessage.usedBits = 0;

}

/* Free function for struct c_SERVICE_REQUEST */
void FREE_c_SERVICE_REQUEST (c_SERVICE_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_KSIAndSequenceNumber (&(sp->KSIAndSequenceNumber));

}

/* Free function for struct c_TRACKING_AREA_UPDATE_COMPLETE */
void FREE_c_TRACKING_AREA_UPDATE_COMPLETE (c_TRACKING_AREA_UPDATE_COMPLETE* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_TRACKING_AREA_UPDATE_REQUEST */
void FREE_c_TRACKING_AREA_UPDATE_REQUEST (c_TRACKING_AREA_UPDATE_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPSUpdateType (&(sp->EPSUpdateType));
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	FREE_c_EPSMobileIdentity (&(sp->OldGUTI));
	if (sp->NonCurrentNativeNASKeySetId_Present) {
		FREE_c_NASKeySetIdentifier (sp->NonCurrentNativeNASKeySetId);
		EDFree (sp->NonCurrentNativeNASKeySetId);
		sp->NonCurrentNativeNASKeySetId_Present = ED_FALSE;
	}
	if (sp->OldPTMSISignature_Present) {
		EDFree (sp->OldPTMSISignature);
		sp->OldPTMSISignature_Present = ED_FALSE;
	}
	if (sp->AdditionalGUTI_Present) {
		FREE_c_EPSMobileIdentity (sp->AdditionalGUTI);
		EDFree (sp->AdditionalGUTI);
		sp->AdditionalGUTI_Present = ED_FALSE;
	}
	if (sp->UENetworkCapability_Present) {
		FREE_c_UENetworkCapability (sp->UENetworkCapability);
		EDFree (sp->UENetworkCapability);
		sp->UENetworkCapability_Present = ED_FALSE;
	}
	if (sp->LastVisitedRegisteredTAI_Present) {
		FREE_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
		EDFree (sp->LastVisitedRegisteredTAI);
		sp->LastVisitedRegisteredTAI_Present = ED_FALSE;
	}
	if (sp->DRXParameter_Present) {
		FREE_c_epsDrxParam (sp->DRXParameter);
		EDFree (sp->DRXParameter);
		sp->DRXParameter_Present = ED_FALSE;
	}
	if (sp->EPSBearerContextStatus_Present) {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
		sp->EPSBearerContextStatus_Present = ED_FALSE;
	}
	if (sp->MSNetworkCapability_Present) {
		FREE_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
		EDFree (sp->MSNetworkCapability);
		sp->MSNetworkCapability_Present = ED_FALSE;
	}
	if (sp->OldLocationAreaIdentification_Present) {
		FREE_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
		EDFree (sp->OldLocationAreaIdentification);
		sp->OldLocationAreaIdentification_Present = ED_FALSE;
	}
	if (sp->TMSIStatus_Present) {
		FREE_c_epsTmsiStatus (sp->TMSIStatus);
		EDFree (sp->TMSIStatus);
		sp->TMSIStatus_Present = ED_FALSE;
	}
	if (sp->epsMobileStationClassmark2_Present) {
		FREE_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
		EDFree (sp->epsMobileStationClassmark2);
		sp->epsMobileStationClassmark2_Present = ED_FALSE;
	}
	if (sp->MobileStationClassmark3_Present) {
		FREE_c_epsClassmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
		sp->MobileStationClassmark3_Present = ED_FALSE;
	}
	if (sp->SupportedCodecs_Present) {
		FREE_c_epsSupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
		sp->SupportedCodecs_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateType_Present) {
		FREE_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
		sp->AdditionalUpdateType_Present = ED_FALSE;
	}
	if (sp->VoiceDomainPref_Present) {
		FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
		EDFree (sp->VoiceDomainPref);
		sp->VoiceDomainPref_Present = ED_FALSE;
	}
	if (sp->OldGUTIType_Present) {
		FREE_c_GUTIType (sp->OldGUTIType);
		EDFree (sp->OldGUTIType);
		sp->OldGUTIType_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}
	if (sp->MSNetworkFeatureSupport_Present) {
		FREE_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
		sp->MSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->TMSIBasedNRIContainer_Present) {
		FREE_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
		sp->TMSIBasedNRIContainer_Present = ED_FALSE;
	}
	if (sp->T3324ValueGPRSTimer2_Present) {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
		sp->T3324ValueGPRSTimer2_Present = ED_FALSE;
	}
	if (sp->T3412ExtendedValue_Present) {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
		sp->T3412ExtendedValue_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NonCurrentNativeNASKeySetId_Present == present) return ED_NO_ERRORS;
	sp->NonCurrentNativeNASKeySetId_Present = present;
	if (present) {
		/*-->*/sp->NonCurrentNativeNASKeySetId = (c_NASKeySetIdentifier*)EDAlloc (sizeof (c_NASKeySetIdentifier));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NonCurrentNativeNASKeySetId)
		INIT_c_NASKeySetIdentifier (sp->NonCurrentNativeNASKeySetId);
	} else {
		FREE_c_NASKeySetIdentifier (sp->NonCurrentNativeNASKeySetId);
		EDFree (sp->NonCurrentNativeNASKeySetId);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldPTMSISignature_Present == present) return ED_NO_ERRORS;
	sp->OldPTMSISignature_Present = present;
	if (present) {
		/*-->*/sp->OldPTMSISignature = (ED_BYTE*)EDAlloc ((size_t)3);
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldPTMSISignature)
		ED_RESET_MEM (sp->OldPTMSISignature, 3);
	} else {
		EDFree (sp->OldPTMSISignature);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalGUTI_Present == present) return ED_NO_ERRORS;
	sp->AdditionalGUTI_Present = present;
	if (present) {
		/*-->*/sp->AdditionalGUTI = (c_EPSMobileIdentity*)EDAlloc (sizeof (c_EPSMobileIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalGUTI)
		INIT_c_EPSMobileIdentity (sp->AdditionalGUTI);
	} else {
		FREE_c_EPSMobileIdentity (sp->AdditionalGUTI);
		EDFree (sp->AdditionalGUTI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UENetworkCapability_Present == present) return ED_NO_ERRORS;
	sp->UENetworkCapability_Present = present;
	if (present) {
		/*-->*/sp->UENetworkCapability = (c_UENetworkCapability*)EDAlloc (sizeof (c_UENetworkCapability));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UENetworkCapability)
		INIT_c_UENetworkCapability (sp->UENetworkCapability);
	} else {
		FREE_c_UENetworkCapability (sp->UENetworkCapability);
		EDFree (sp->UENetworkCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LastVisitedRegisteredTAI_Present == present) return ED_NO_ERRORS;
	sp->LastVisitedRegisteredTAI_Present = present;
	if (present) {
		/*-->*/sp->LastVisitedRegisteredTAI = (c_TrackingAreaIdentity*)EDAlloc (sizeof (c_TrackingAreaIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LastVisitedRegisteredTAI)
		INIT_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
	} else {
		FREE_c_TrackingAreaIdentity (sp->LastVisitedRegisteredTAI);
		EDFree (sp->LastVisitedRegisteredTAI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DRXParameter_Present == present) return ED_NO_ERRORS;
	sp->DRXParameter_Present = present;
	if (present) {
		/*-->*/sp->DRXParameter = (c_epsDrxParam*)EDAlloc (sizeof (c_epsDrxParam));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DRXParameter)
		INIT_c_epsDrxParam (sp->DRXParameter);
	} else {
		FREE_c_epsDrxParam (sp->DRXParameter);
		EDFree (sp->DRXParameter);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSBearerContextStatus_Present == present) return ED_NO_ERRORS;
	sp->EPSBearerContextStatus_Present = present;
	if (present) {
		/*-->*/sp->EPSBearerContextStatus = (c_EPSBearerContextStatus*)EDAlloc (sizeof (c_EPSBearerContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSBearerContextStatus)
		INIT_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
	} else {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkCapability_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkCapability_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkCapability = (c_epsMsNetwkCpblty*)EDAlloc (sizeof (c_epsMsNetwkCpblty));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkCapability)
		INIT_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
	} else {
		FREE_c_epsMsNetwkCpblty (sp->MSNetworkCapability);
		EDFree (sp->MSNetworkCapability);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldLocationAreaIdentification_Present == present) return ED_NO_ERRORS;
	sp->OldLocationAreaIdentification_Present = present;
	if (present) {
		/*-->*/sp->OldLocationAreaIdentification = (c_epsLocationAreaId*)EDAlloc (sizeof (c_epsLocationAreaId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldLocationAreaIdentification)
		INIT_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
	} else {
		FREE_c_epsLocationAreaId (sp->OldLocationAreaIdentification);
		EDFree (sp->OldLocationAreaIdentification);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIStatus_Present == present) return ED_NO_ERRORS;
	sp->TMSIStatus_Present = present;
	if (present) {
		/*-->*/sp->TMSIStatus = (c_epsTmsiStatus*)EDAlloc (sizeof (c_epsTmsiStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIStatus)
		INIT_c_epsTmsiStatus (sp->TMSIStatus);
	} else {
		FREE_c_epsTmsiStatus (sp->TMSIStatus);
		EDFree (sp->TMSIStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->epsMobileStationClassmark2_Present == present) return ED_NO_ERRORS;
	sp->epsMobileStationClassmark2_Present = present;
	if (present) {
		/*-->*/sp->epsMobileStationClassmark2 = (c_epsMobileStationClassmark2*)EDAlloc (sizeof (c_epsMobileStationClassmark2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->epsMobileStationClassmark2)
		INIT_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
	} else {
		FREE_c_epsMobileStationClassmark2 (sp->epsMobileStationClassmark2);
		EDFree (sp->epsMobileStationClassmark2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MobileStationClassmark3_Present == present) return ED_NO_ERRORS;
	sp->MobileStationClassmark3_Present = present;
	if (present) {
		/*-->*/sp->MobileStationClassmark3 = (c_epsClassmark3Value*)EDAlloc (sizeof (c_epsClassmark3Value));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MobileStationClassmark3)
		INIT_c_epsClassmark3Value (sp->MobileStationClassmark3);
	} else {
		FREE_c_epsClassmark3Value (sp->MobileStationClassmark3);
		EDFree (sp->MobileStationClassmark3);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->SupportedCodecs_Present == present) return ED_NO_ERRORS;
	sp->SupportedCodecs_Present = present;
	if (present) {
		/*-->*/sp->SupportedCodecs = (c_epsSupportedCodecList*)EDAlloc (sizeof (c_epsSupportedCodecList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->SupportedCodecs)
		INIT_c_epsSupportedCodecList (sp->SupportedCodecs);
	} else {
		FREE_c_epsSupportedCodecList (sp->SupportedCodecs);
		EDFree (sp->SupportedCodecs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateType_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateType_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateType = (c_epsAdditionalUpdateType*)EDAlloc (sizeof (c_epsAdditionalUpdateType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateType)
		INIT_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
	} else {
		FREE_c_epsAdditionalUpdateType (sp->AdditionalUpdateType);
		EDFree (sp->AdditionalUpdateType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->VoiceDomainPref_Present == present) return ED_NO_ERRORS;
	sp->VoiceDomainPref_Present = present;
	if (present) {
		/*-->*/sp->VoiceDomainPref = (c_epsVoiceDomainPreferenceAndUEsUsageSetting*)EDAlloc (sizeof (c_epsVoiceDomainPreferenceAndUEsUsageSetting));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->VoiceDomainPref)
		INIT_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
	} else {
		FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (sp->VoiceDomainPref);
		EDFree (sp->VoiceDomainPref);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->OldGUTIType_Present == present) return ED_NO_ERRORS;
	sp->OldGUTIType_Present = present;
	if (present) {
		/*-->*/sp->OldGUTIType = (c_GUTIType*)EDAlloc (sizeof (c_GUTIType));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->OldGUTIType)
		INIT_c_GUTIType (sp->OldGUTIType);
	} else {
		FREE_c_GUTIType (sp->OldGUTIType);
		EDFree (sp->OldGUTIType);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->MSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->MSNetworkFeatureSupport = (c_epsMSNetworkFeatureSupport*)EDAlloc (sizeof (c_epsMSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSNetworkFeatureSupport)
		INIT_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
	} else {
		FREE_c_epsMSNetworkFeatureSupport (sp->MSNetworkFeatureSupport);
		EDFree (sp->MSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TMSIBasedNRIContainer_Present == present) return ED_NO_ERRORS;
	sp->TMSIBasedNRIContainer_Present = present;
	if (present) {
		/*-->*/sp->TMSIBasedNRIContainer = (c_epsNetworkResourceIdentifierContainer*)EDAlloc (sizeof (c_epsNetworkResourceIdentifierContainer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TMSIBasedNRIContainer)
		INIT_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
	} else {
		FREE_c_epsNetworkResourceIdentifierContainer (sp->TMSIBasedNRIContainer);
		EDFree (sp->TMSIBasedNRIContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324ValueGPRSTimer2_Present == present) return ED_NO_ERRORS;
	sp->T3324ValueGPRSTimer2_Present = present;
	if (present) {
		/*-->*/sp->T3324ValueGPRSTimer2 = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324ValueGPRSTimer2)
		INIT_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3412ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3412ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3412ExtendedValue = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3412ExtendedValue)
		INIT_c_epsGprsTimer (sp->T3412ExtendedValue);
	} else {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_epsExtendedDRXParameters*)EDAlloc (sizeof (c_epsExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_UPLINK_NAS_TRANSPORT */
void FREE_c_UPLINK_NAS_TRANSPORT (c_UPLINK_NAS_TRANSPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NASMessageContainer.value != NULL) {
		EDFree (sp->NASMessageContainer.value);
		sp->NASMessageContainer.value = NULL;
	}
	sp->NASMessageContainer.usedBits = 0;

}

/* Free function for struct c_UPLINK_GENERIC_NAS_TRANSPORT */
void FREE_c_UPLINK_GENERIC_NAS_TRANSPORT (c_UPLINK_GENERIC_NAS_TRANSPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NASMessageContainer.value != NULL) {
		EDFree (sp->NASMessageContainer.value);
		sp->NASMessageContainer.value = NULL;
	}
	sp->NASMessageContainer.usedBits = 0;
	if (sp->GenericMessageContainer.value != NULL) {
		EDFree (sp->GenericMessageContainer.value);
		sp->GenericMessageContainer.value = NULL;
	}
	sp->GenericMessageContainer.usedBits = 0;
	if (sp->AdditionalInformation_Present) {
		if (sp->AdditionalInformation->value != NULL) {
			EDFree (sp->AdditionalInformation->value);
			sp->AdditionalInformation->value = NULL;
		}
		sp->AdditionalInformation->usedBits = 0;
		EDFree (sp->AdditionalInformation);
		sp->AdditionalInformation_Present = ED_FALSE;
	}

}

int SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (c_UPLINK_GENERIC_NAS_TRANSPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalInformation_Present == present) return ED_NO_ERRORS;
	sp->AdditionalInformation_Present = present;
	if (present) {
		/*-->*/sp->AdditionalInformation = (c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation*)EDAlloc (sizeof (c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalInformation)
		
		sp->AdditionalInformation->value = NULL;
		sp->AdditionalInformation->usedBits = 0;
	} else {
		if (sp->AdditionalInformation->value != NULL) {
			EDFree (sp->AdditionalInformation->value);
			sp->AdditionalInformation->value = NULL;
		}
		sp->AdditionalInformation->usedBits = 0;
		EDFree (sp->AdditionalInformation);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_CONTROL_PLANE_SERVICE_REQUEST */
void FREE_c_CONTROL_PLANE_SERVICE_REQUEST (c_CONTROL_PLANE_SERVICE_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_DataServiceType (&(sp->DataServiceType));
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	if (sp->ESMMessageContainer_Present) {
		FREE_c_ESMMessageUp (sp->ESMMessageContainer);
		EDFree (sp->ESMMessageContainer);
		sp->ESMMessageContainer_Present = ED_FALSE;
	}
	if (sp->NASMessageContainer_Present) {
		if (sp->NASMessageContainer->value != NULL) {
			EDFree (sp->NASMessageContainer->value);
			sp->NASMessageContainer->value = NULL;
		}
		sp->NASMessageContainer->usedBits = 0;
		EDFree (sp->NASMessageContainer);
		sp->NASMessageContainer_Present = ED_FALSE;
	}
	if (sp->EPSBearerContextStatus_Present) {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
		sp->EPSBearerContextStatus_Present = ED_FALSE;
	}
	if (sp->DeviceProperties_Present) {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
		sp->DeviceProperties_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ESMMessageContainer_Present == present) return ED_NO_ERRORS;
	sp->ESMMessageContainer_Present = present;
	if (present) {
		/*-->*/sp->ESMMessageContainer = (c_ESMMessageUp*)EDAlloc (sizeof (c_ESMMessageUp));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ESMMessageContainer)
		INIT_c_ESMMessageUp (sp->ESMMessageContainer);
	} else {
		FREE_c_ESMMessageUp (sp->ESMMessageContainer);
		EDFree (sp->ESMMessageContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NASMessageContainer_Present == present) return ED_NO_ERRORS;
	sp->NASMessageContainer_Present = present;
	if (present) {
		/*-->*/sp->NASMessageContainer = (c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer*)EDAlloc (sizeof (c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NASMessageContainer)
		
		sp->NASMessageContainer->value = NULL;
		sp->NASMessageContainer->usedBits = 0;
	} else {
		if (sp->NASMessageContainer->value != NULL) {
			EDFree (sp->NASMessageContainer->value);
			sp->NASMessageContainer->value = NULL;
		}
		sp->NASMessageContainer->usedBits = 0;
		EDFree (sp->NASMessageContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSBearerContextStatus_Present == present) return ED_NO_ERRORS;
	sp->EPSBearerContextStatus_Present = present;
	if (present) {
		/*-->*/sp->EPSBearerContextStatus = (c_EPSBearerContextStatus*)EDAlloc (sizeof (c_EPSBearerContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSBearerContextStatus)
		INIT_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
	} else {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->DeviceProperties_Present == present) return ED_NO_ERRORS;
	sp->DeviceProperties_Present = present;
	if (present) {
		/*-->*/sp->DeviceProperties = (c_epsDeviceProperties*)EDAlloc (sizeof (c_epsDeviceProperties));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->DeviceProperties)
		INIT_c_epsDeviceProperties (sp->DeviceProperties);
	} else {
		FREE_c_epsDeviceProperties (sp->DeviceProperties);
		EDFree (sp->DeviceProperties);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ATTACH_ACCEPT */
void FREE_c_ATTACH_ACCEPT (c_ATTACH_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsGprsTimer (&(sp->T3412Value));
	FREE_c_PartialTrackingAreaIdentityList (&(sp->TAIList));
	FREE_c_ESMMessageDn (&(sp->ESMMessageContainer));
	if (sp->GUTI_Present) {
		FREE_c_EPSMobileIdentity (sp->GUTI);
		EDFree (sp->GUTI);
		sp->GUTI_Present = ED_FALSE;
	}
	if (sp->LocationAreaIdentification_Present) {
		FREE_c_epsLocationAreaId (sp->LocationAreaIdentification);
		EDFree (sp->LocationAreaIdentification);
		sp->LocationAreaIdentification_Present = ED_FALSE;
	}
	if (sp->MSIdentity_Present) {
		FREE_c_epsMobileId (sp->MSIdentity);
		EDFree (sp->MSIdentity);
		sp->MSIdentity_Present = ED_FALSE;
	}
	if (sp->T3402Value_Present) {
		FREE_c_epsGprsTimer (sp->T3402Value);
		EDFree (sp->T3402Value);
		sp->T3402Value_Present = ED_FALSE;
	}
	if (sp->T3423Value_Present) {
		FREE_c_epsGprsTimer (sp->T3423Value);
		EDFree (sp->T3423Value);
		sp->T3423Value_Present = ED_FALSE;
	}
	if (sp->EquivalentPLMNs_Present) {
		FREE_c_epsPlmnList (sp->EquivalentPLMNs);
		EDFree (sp->EquivalentPLMNs);
		sp->EquivalentPLMNs_Present = ED_FALSE;
	}
	if (sp->epsEmergencyNumberList_Present) {
		FREE_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
		EDFree (sp->epsEmergencyNumberList);
		sp->epsEmergencyNumberList_Present = ED_FALSE;
	}
	if (sp->EPSNetworkFeatureSupport_Present) {
		FREE_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
		EDFree (sp->EPSNetworkFeatureSupport);
		sp->EPSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateResult_Present) {
		FREE_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
		EDFree (sp->AdditionalUpdateResult);
		sp->AdditionalUpdateResult_Present = ED_FALSE;
	}
	if (sp->T3412ExtendedValue_Present) {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
		sp->T3412ExtendedValue_Present = ED_FALSE;
	}
	if (sp->T3324ValueGPRSTimer2_Present) {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
		sp->T3324ValueGPRSTimer2_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_ACCEPT_GUTI (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->GUTI_Present == present) return ED_NO_ERRORS;
	sp->GUTI_Present = present;
	if (present) {
		/*-->*/sp->GUTI = (c_EPSMobileIdentity*)EDAlloc (sizeof (c_EPSMobileIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->GUTI)
		INIT_c_EPSMobileIdentity (sp->GUTI);
	} else {
		FREE_c_EPSMobileIdentity (sp->GUTI);
		EDFree (sp->GUTI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LocationAreaIdentification_Present == present) return ED_NO_ERRORS;
	sp->LocationAreaIdentification_Present = present;
	if (present) {
		/*-->*/sp->LocationAreaIdentification = (c_epsLocationAreaId*)EDAlloc (sizeof (c_epsLocationAreaId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LocationAreaIdentification)
		INIT_c_epsLocationAreaId (sp->LocationAreaIdentification);
	} else {
		FREE_c_epsLocationAreaId (sp->LocationAreaIdentification);
		EDFree (sp->LocationAreaIdentification);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSIdentity_Present == present) return ED_NO_ERRORS;
	sp->MSIdentity_Present = present;
	if (present) {
		/*-->*/sp->MSIdentity = (c_epsMobileId*)EDAlloc (sizeof (c_epsMobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSIdentity)
		INIT_c_epsMobileId (sp->MSIdentity);
	} else {
		FREE_c_epsMobileId (sp->MSIdentity);
		EDFree (sp->MSIdentity);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_T3402Value (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3402Value_Present == present) return ED_NO_ERRORS;
	sp->T3402Value_Present = present;
	if (present) {
		/*-->*/sp->T3402Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3402Value)
		INIT_c_epsGprsTimer (sp->T3402Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3402Value);
		EDFree (sp->T3402Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_T3423Value (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3423Value_Present == present) return ED_NO_ERRORS;
	sp->T3423Value_Present = present;
	if (present) {
		/*-->*/sp->T3423Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3423Value)
		INIT_c_epsGprsTimer (sp->T3423Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3423Value);
		EDFree (sp->T3423Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EquivalentPLMNs_Present == present) return ED_NO_ERRORS;
	sp->EquivalentPLMNs_Present = present;
	if (present) {
		/*-->*/sp->EquivalentPLMNs = (c_epsPlmnList*)EDAlloc (sizeof (c_epsPlmnList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EquivalentPLMNs)
		INIT_c_epsPlmnList (sp->EquivalentPLMNs);
	} else {
		FREE_c_epsPlmnList (sp->EquivalentPLMNs);
		EDFree (sp->EquivalentPLMNs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->epsEmergencyNumberList_Present == present) return ED_NO_ERRORS;
	sp->epsEmergencyNumberList_Present = present;
	if (present) {
		/*-->*/sp->epsEmergencyNumberList = (c_epsEmergencyNumberList*)EDAlloc (sizeof (c_epsEmergencyNumberList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->epsEmergencyNumberList)
		INIT_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
	} else {
		FREE_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
		EDFree (sp->epsEmergencyNumberList);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->EPSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->EPSNetworkFeatureSupport = (c_EPSNetworkFeatureSupport*)EDAlloc (sizeof (c_EPSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSNetworkFeatureSupport)
		INIT_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
	} else {
		FREE_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
		EDFree (sp->EPSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateResult_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateResult_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateResult = (c_AdditionalUpdateResult*)EDAlloc (sizeof (c_AdditionalUpdateResult));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateResult)
		INIT_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
	} else {
		FREE_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
		EDFree (sp->AdditionalUpdateResult);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3412ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3412ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3412ExtendedValue = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3412ExtendedValue)
		INIT_c_epsGprsTimer (sp->T3412ExtendedValue);
	} else {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324ValueGPRSTimer2_Present == present) return ED_NO_ERRORS;
	sp->T3324ValueGPRSTimer2_Present = present;
	if (present) {
		/*-->*/sp->T3324ValueGPRSTimer2 = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324ValueGPRSTimer2)
		INIT_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_epsExtendedDRXParameters*)EDAlloc (sizeof (c_epsExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_ATTACH_REJECT */
void FREE_c_ATTACH_REJECT (c_ATTACH_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ESMMessageContainer_Present) {
		FREE_c_ESMMessageDn (sp->ESMMessageContainer);
		EDFree (sp->ESMMessageContainer);
		sp->ESMMessageContainer_Present = ED_FALSE;
	}
	if (sp->T3346Value_Present) {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}
	if (sp->T3402Value_Present) {
		FREE_c_epsGprsTimer2 (sp->T3402Value);
		EDFree (sp->T3402Value);
		sp->T3402Value_Present = ED_FALSE;
	}
	if (sp->ExtendedEMMCause_Present) {
		FREE_c_ExtendedEMMCause (sp->ExtendedEMMCause);
		EDFree (sp->ExtendedEMMCause);
		sp->ExtendedEMMCause_Present = ED_FALSE;
	}

}

int SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (c_ATTACH_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ESMMessageContainer_Present == present) return ED_NO_ERRORS;
	sp->ESMMessageContainer_Present = present;
	if (present) {
		/*-->*/sp->ESMMessageContainer = (c_ESMMessageDn*)EDAlloc (sizeof (c_ESMMessageDn));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ESMMessageContainer)
		INIT_c_ESMMessageDn (sp->ESMMessageContainer);
	} else {
		FREE_c_ESMMessageDn (sp->ESMMessageContainer);
		EDFree (sp->ESMMessageContainer);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REJECT_T3346Value (c_ATTACH_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_epsGprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REJECT_T3402Value (c_ATTACH_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3402Value_Present == present) return ED_NO_ERRORS;
	sp->T3402Value_Present = present;
	if (present) {
		/*-->*/sp->T3402Value = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3402Value)
		INIT_c_epsGprsTimer2 (sp->T3402Value);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3402Value);
		EDFree (sp->T3402Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause (c_ATTACH_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedEMMCause_Present == present) return ED_NO_ERRORS;
	sp->ExtendedEMMCause_Present = present;
	if (present) {
		/*-->*/sp->ExtendedEMMCause = (c_ExtendedEMMCause*)EDAlloc (sizeof (c_ExtendedEMMCause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedEMMCause)
		INIT_c_ExtendedEMMCause (sp->ExtendedEMMCause);
	} else {
		FREE_c_ExtendedEMMCause (sp->ExtendedEMMCause);
		EDFree (sp->ExtendedEMMCause);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_AUTHENTICATION_REJECT */
void FREE_c_AUTHENTICATION_REJECT (c_AUTHENTICATION_REJECT* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_AUTHENTICATION_REQUEST */
void FREE_c_AUTHENTICATION_REQUEST (c_AUTHENTICATION_REQUEST* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifierASME));

}

/* Free function for struct c_CS_SERVICE_NOTIFICATION */
void FREE_c_CS_SERVICE_NOTIFICATION (c_CS_SERVICE_NOTIFICATION* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->CLI_Present) {
		FREE_c_epsCallingPartyBcdNum (sp->CLI);
		EDFree (sp->CLI);
		sp->CLI_Present = ED_FALSE;
	}
	if (sp->LCSClientId_Present) {
		if (sp->LCSClientId->value != NULL) {
			EDFree (sp->LCSClientId->value);
			sp->LCSClientId->value = NULL;
		}
		sp->LCSClientId->usedBits = 0;
		EDFree (sp->LCSClientId);
		sp->LCSClientId_Present = ED_FALSE;
	}

}

int SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (c_CS_SERVICE_NOTIFICATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->CLI_Present == present) return ED_NO_ERRORS;
	sp->CLI_Present = present;
	if (present) {
		/*-->*/sp->CLI = (c_epsCallingPartyBcdNum*)EDAlloc (sizeof (c_epsCallingPartyBcdNum));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->CLI)
		INIT_c_epsCallingPartyBcdNum (sp->CLI);
	} else {
		FREE_c_epsCallingPartyBcdNum (sp->CLI);
		EDFree (sp->CLI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (c_CS_SERVICE_NOTIFICATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LCSClientId_Present == present) return ED_NO_ERRORS;
	sp->LCSClientId_Present = present;
	if (present) {
		/*-->*/sp->LCSClientId = (c_CS_SERVICE_NOTIFICATION_LCSClientId*)EDAlloc (sizeof (c_CS_SERVICE_NOTIFICATION_LCSClientId));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LCSClientId)
		
		sp->LCSClientId->value = NULL;
		sp->LCSClientId->usedBits = 0;
	} else {
		if (sp->LCSClientId->value != NULL) {
			EDFree (sp->LCSClientId->value);
			sp->LCSClientId->value = NULL;
		}
		sp->LCSClientId->usedBits = 0;
		EDFree (sp->LCSClientId);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EPS_DETACH_ACCEPT_DN */
void FREE_c_EPS_DETACH_ACCEPT_DN (c_EPS_DETACH_ACCEPT_DN* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPS_DETACH_REQUEST_DN */
void FREE_c_EPS_DETACH_REQUEST_DN (c_EPS_DETACH_REQUEST_DN* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPSDetachType (&(sp->DetachType));

}

/* Free function for struct c_DOWNLINK_NAS_TRANSPORT */
void FREE_c_DOWNLINK_NAS_TRANSPORT (c_DOWNLINK_NAS_TRANSPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->NASMessageContainer.value != NULL) {
		EDFree (sp->NASMessageContainer.value);
		sp->NASMessageContainer.value = NULL;
	}
	sp->NASMessageContainer.usedBits = 0;

}

/* Free function for struct c_EMM_INFORMATION */
void FREE_c_EMM_INFORMATION (c_EMM_INFORMATION* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->FullNameForNetwork_Present) {
		FREE_c_epsNetwkName (sp->FullNameForNetwork);
		EDFree (sp->FullNameForNetwork);
		sp->FullNameForNetwork_Present = ED_FALSE;
	}
	if (sp->ShortNameForNetwork_Present) {
		FREE_c_epsNetwkName (sp->ShortNameForNetwork);
		EDFree (sp->ShortNameForNetwork);
		sp->ShortNameForNetwork_Present = ED_FALSE;
	}
	if (sp->UniversalTimeAndLocalTimeZone_Present) {
		FREE_c_epsTimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
		sp->UniversalTimeAndLocalTimeZone_Present = ED_FALSE;
	}
	if (sp->NetworkDaylightSavingTime_Present) {
		FREE_c_epsDaylightSavingTime (sp->NetworkDaylightSavingTime);
		EDFree (sp->NetworkDaylightSavingTime);
		sp->NetworkDaylightSavingTime_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (c_EMM_INFORMATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->FullNameForNetwork_Present == present) return ED_NO_ERRORS;
	sp->FullNameForNetwork_Present = present;
	if (present) {
		/*-->*/sp->FullNameForNetwork = (c_epsNetwkName*)EDAlloc (sizeof (c_epsNetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->FullNameForNetwork)
		INIT_c_epsNetwkName (sp->FullNameForNetwork);
	} else {
		FREE_c_epsNetwkName (sp->FullNameForNetwork);
		EDFree (sp->FullNameForNetwork);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (c_EMM_INFORMATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ShortNameForNetwork_Present == present) return ED_NO_ERRORS;
	sp->ShortNameForNetwork_Present = present;
	if (present) {
		/*-->*/sp->ShortNameForNetwork = (c_epsNetwkName*)EDAlloc (sizeof (c_epsNetwkName));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ShortNameForNetwork)
		INIT_c_epsNetwkName (sp->ShortNameForNetwork);
	} else {
		FREE_c_epsNetwkName (sp->ShortNameForNetwork);
		EDFree (sp->ShortNameForNetwork);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone (c_EMM_INFORMATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->UniversalTimeAndLocalTimeZone_Present == present) return ED_NO_ERRORS;
	sp->UniversalTimeAndLocalTimeZone_Present = present;
	if (present) {
		/*-->*/sp->UniversalTimeAndLocalTimeZone = (c_epsTimeZoneAndTime*)EDAlloc (sizeof (c_epsTimeZoneAndTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->UniversalTimeAndLocalTimeZone)
		INIT_c_epsTimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
	} else {
		FREE_c_epsTimeZoneAndTime (sp->UniversalTimeAndLocalTimeZone);
		EDFree (sp->UniversalTimeAndLocalTimeZone);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (c_EMM_INFORMATION* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->NetworkDaylightSavingTime_Present == present) return ED_NO_ERRORS;
	sp->NetworkDaylightSavingTime_Present = present;
	if (present) {
		/*-->*/sp->NetworkDaylightSavingTime = (c_epsDaylightSavingTime*)EDAlloc (sizeof (c_epsDaylightSavingTime));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->NetworkDaylightSavingTime)
		INIT_c_epsDaylightSavingTime (sp->NetworkDaylightSavingTime);
	} else {
		FREE_c_epsDaylightSavingTime (sp->NetworkDaylightSavingTime);
		EDFree (sp->NetworkDaylightSavingTime);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_GUTI_REALLOCATION_COMMAND */
void FREE_c_GUTI_REALLOCATION_COMMAND (c_GUTI_REALLOCATION_COMMAND* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EPSMobileIdentity (&(sp->GUTI));
	if (sp->TAIList_Present) {
		FREE_c_PartialTrackingAreaIdentityList (sp->TAIList);
		EDFree (sp->TAIList);
		sp->TAIList_Present = ED_FALSE;
	}

}

int SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (c_GUTI_REALLOCATION_COMMAND* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TAIList_Present == present) return ED_NO_ERRORS;
	sp->TAIList_Present = present;
	if (present) {
		/*-->*/sp->TAIList = (c_PartialTrackingAreaIdentityList*)EDAlloc (sizeof (c_PartialTrackingAreaIdentityList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TAIList)
		INIT_c_PartialTrackingAreaIdentityList (sp->TAIList);
	} else {
		FREE_c_PartialTrackingAreaIdentityList (sp->TAIList);
		EDFree (sp->TAIList);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_IDENTITY_REQUEST */
void FREE_c_IDENTITY_REQUEST (c_IDENTITY_REQUEST* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_SECURITY_MODE_COMMAND */
void FREE_c_SECURITY_MODE_COMMAND (c_SECURITY_MODE_COMMAND* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_NASSecurityAlgorithms (&(sp->SelectedNASSecurityAlgorithms));
	FREE_c_NASKeySetIdentifier (&(sp->NASKeySetIdentifier));
	FREE_c_UESecurityCapability (&(sp->ReplayedUESecurityCapabilities));

}

/* Free function for struct c_SERVICE_REJECT */
void FREE_c_SERVICE_REJECT (c_SERVICE_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3442Value_Present) {
		FREE_c_epsGprsTimer (sp->T3442Value);
		EDFree (sp->T3442Value);
		sp->T3442Value_Present = ED_FALSE;
	}
	if (sp->T3346Value_Present) {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SERVICE_REJECT_T3442Value (c_SERVICE_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3442Value_Present == present) return ED_NO_ERRORS;
	sp->T3442Value_Present = present;
	if (present) {
		/*-->*/sp->T3442Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3442Value)
		INIT_c_epsGprsTimer (sp->T3442Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3442Value);
		EDFree (sp->T3442Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_SERVICE_REJECT_T3346Value (c_SERVICE_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_epsGprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_TRACKING_AREA_UPDATE_ACCEPT */
void FREE_c_TRACKING_AREA_UPDATE_ACCEPT (c_TRACKING_AREA_UPDATE_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3412Value_Present) {
		FREE_c_epsGprsTimer (sp->T3412Value);
		EDFree (sp->T3412Value);
		sp->T3412Value_Present = ED_FALSE;
	}
	if (sp->GUTI_Present) {
		FREE_c_EPSMobileIdentity (sp->GUTI);
		EDFree (sp->GUTI);
		sp->GUTI_Present = ED_FALSE;
	}
	if (sp->TAIList_Present) {
		FREE_c_PartialTrackingAreaIdentityList (sp->TAIList);
		EDFree (sp->TAIList);
		sp->TAIList_Present = ED_FALSE;
	}
	if (sp->EPSBearerContextStatus_Present) {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
		sp->EPSBearerContextStatus_Present = ED_FALSE;
	}
	if (sp->LocationAreaIdentification_Present) {
		FREE_c_epsLocationAreaId (sp->LocationAreaIdentification);
		EDFree (sp->LocationAreaIdentification);
		sp->LocationAreaIdentification_Present = ED_FALSE;
	}
	if (sp->MSIdentity_Present) {
		FREE_c_epsMobileId (sp->MSIdentity);
		EDFree (sp->MSIdentity);
		sp->MSIdentity_Present = ED_FALSE;
	}
	if (sp->T3402Value_Present) {
		FREE_c_epsGprsTimer (sp->T3402Value);
		EDFree (sp->T3402Value);
		sp->T3402Value_Present = ED_FALSE;
	}
	if (sp->T3423Value_Present) {
		FREE_c_epsGprsTimer (sp->T3423Value);
		EDFree (sp->T3423Value);
		sp->T3423Value_Present = ED_FALSE;
	}
	if (sp->EquivalentPLMNs_Present) {
		FREE_c_epsPlmnList (sp->EquivalentPLMNs);
		EDFree (sp->EquivalentPLMNs);
		sp->EquivalentPLMNs_Present = ED_FALSE;
	}
	if (sp->epsEmergencyNumberList_Present) {
		FREE_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
		EDFree (sp->epsEmergencyNumberList);
		sp->epsEmergencyNumberList_Present = ED_FALSE;
	}
	if (sp->EPSNetworkFeatureSupport_Present) {
		FREE_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
		EDFree (sp->EPSNetworkFeatureSupport);
		sp->EPSNetworkFeatureSupport_Present = ED_FALSE;
	}
	if (sp->AdditionalUpdateResult_Present) {
		FREE_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
		EDFree (sp->AdditionalUpdateResult);
		sp->AdditionalUpdateResult_Present = ED_FALSE;
	}
	if (sp->T3412ExtendedValue_Present) {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
		sp->T3412ExtendedValue_Present = ED_FALSE;
	}
	if (sp->T3324ValueGPRSTimer2_Present) {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
		sp->T3324ValueGPRSTimer2_Present = ED_FALSE;
	}
	if (sp->ExtendedDRXParameters_Present) {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
		sp->ExtendedDRXParameters_Present = ED_FALSE;
	}
	if (sp->HeaderCompressionCfgStatus_Present) {
		FREE_c_HeaderCompressionCfgStatus (sp->HeaderCompressionCfgStatus);
		EDFree (sp->HeaderCompressionCfgStatus);
		sp->HeaderCompressionCfgStatus_Present = ED_FALSE;
	}

}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3412Value_Present == present) return ED_NO_ERRORS;
	sp->T3412Value_Present = present;
	if (present) {
		/*-->*/sp->T3412Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3412Value)
		INIT_c_epsGprsTimer (sp->T3412Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3412Value);
		EDFree (sp->T3412Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->GUTI_Present == present) return ED_NO_ERRORS;
	sp->GUTI_Present = present;
	if (present) {
		/*-->*/sp->GUTI = (c_EPSMobileIdentity*)EDAlloc (sizeof (c_EPSMobileIdentity));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->GUTI)
		INIT_c_EPSMobileIdentity (sp->GUTI);
	} else {
		FREE_c_EPSMobileIdentity (sp->GUTI);
		EDFree (sp->GUTI);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->TAIList_Present == present) return ED_NO_ERRORS;
	sp->TAIList_Present = present;
	if (present) {
		/*-->*/sp->TAIList = (c_PartialTrackingAreaIdentityList*)EDAlloc (sizeof (c_PartialTrackingAreaIdentityList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->TAIList)
		INIT_c_PartialTrackingAreaIdentityList (sp->TAIList);
	} else {
		FREE_c_PartialTrackingAreaIdentityList (sp->TAIList);
		EDFree (sp->TAIList);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSBearerContextStatus_Present == present) return ED_NO_ERRORS;
	sp->EPSBearerContextStatus_Present = present;
	if (present) {
		/*-->*/sp->EPSBearerContextStatus = (c_EPSBearerContextStatus*)EDAlloc (sizeof (c_EPSBearerContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSBearerContextStatus)
		INIT_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
	} else {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->LocationAreaIdentification_Present == present) return ED_NO_ERRORS;
	sp->LocationAreaIdentification_Present = present;
	if (present) {
		/*-->*/sp->LocationAreaIdentification = (c_epsLocationAreaId*)EDAlloc (sizeof (c_epsLocationAreaId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->LocationAreaIdentification)
		INIT_c_epsLocationAreaId (sp->LocationAreaIdentification);
	} else {
		FREE_c_epsLocationAreaId (sp->LocationAreaIdentification);
		EDFree (sp->LocationAreaIdentification);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->MSIdentity_Present == present) return ED_NO_ERRORS;
	sp->MSIdentity_Present = present;
	if (present) {
		/*-->*/sp->MSIdentity = (c_epsMobileId*)EDAlloc (sizeof (c_epsMobileId));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->MSIdentity)
		INIT_c_epsMobileId (sp->MSIdentity);
	} else {
		FREE_c_epsMobileId (sp->MSIdentity);
		EDFree (sp->MSIdentity);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3402Value_Present == present) return ED_NO_ERRORS;
	sp->T3402Value_Present = present;
	if (present) {
		/*-->*/sp->T3402Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3402Value)
		INIT_c_epsGprsTimer (sp->T3402Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3402Value);
		EDFree (sp->T3402Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3423Value_Present == present) return ED_NO_ERRORS;
	sp->T3423Value_Present = present;
	if (present) {
		/*-->*/sp->T3423Value = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3423Value)
		INIT_c_epsGprsTimer (sp->T3423Value);
	} else {
		FREE_c_epsGprsTimer (sp->T3423Value);
		EDFree (sp->T3423Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EquivalentPLMNs_Present == present) return ED_NO_ERRORS;
	sp->EquivalentPLMNs_Present = present;
	if (present) {
		/*-->*/sp->EquivalentPLMNs = (c_epsPlmnList*)EDAlloc (sizeof (c_epsPlmnList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EquivalentPLMNs)
		INIT_c_epsPlmnList (sp->EquivalentPLMNs);
	} else {
		FREE_c_epsPlmnList (sp->EquivalentPLMNs);
		EDFree (sp->EquivalentPLMNs);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->epsEmergencyNumberList_Present == present) return ED_NO_ERRORS;
	sp->epsEmergencyNumberList_Present = present;
	if (present) {
		/*-->*/sp->epsEmergencyNumberList = (c_epsEmergencyNumberList*)EDAlloc (sizeof (c_epsEmergencyNumberList));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->epsEmergencyNumberList)
		INIT_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
	} else {
		FREE_c_epsEmergencyNumberList (sp->epsEmergencyNumberList);
		EDFree (sp->epsEmergencyNumberList);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSNetworkFeatureSupport_Present == present) return ED_NO_ERRORS;
	sp->EPSNetworkFeatureSupport_Present = present;
	if (present) {
		/*-->*/sp->EPSNetworkFeatureSupport = (c_EPSNetworkFeatureSupport*)EDAlloc (sizeof (c_EPSNetworkFeatureSupport));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSNetworkFeatureSupport)
		INIT_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
	} else {
		FREE_c_EPSNetworkFeatureSupport (sp->EPSNetworkFeatureSupport);
		EDFree (sp->EPSNetworkFeatureSupport);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalUpdateResult_Present == present) return ED_NO_ERRORS;
	sp->AdditionalUpdateResult_Present = present;
	if (present) {
		/*-->*/sp->AdditionalUpdateResult = (c_AdditionalUpdateResult*)EDAlloc (sizeof (c_AdditionalUpdateResult));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalUpdateResult)
		INIT_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
	} else {
		FREE_c_AdditionalUpdateResult (sp->AdditionalUpdateResult);
		EDFree (sp->AdditionalUpdateResult);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3412ExtendedValue_Present == present) return ED_NO_ERRORS;
	sp->T3412ExtendedValue_Present = present;
	if (present) {
		/*-->*/sp->T3412ExtendedValue = (c_epsGprsTimer*)EDAlloc (sizeof (c_epsGprsTimer));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3412ExtendedValue)
		INIT_c_epsGprsTimer (sp->T3412ExtendedValue);
	} else {
		FREE_c_epsGprsTimer (sp->T3412ExtendedValue);
		EDFree (sp->T3412ExtendedValue);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3324ValueGPRSTimer2_Present == present) return ED_NO_ERRORS;
	sp->T3324ValueGPRSTimer2_Present = present;
	if (present) {
		/*-->*/sp->T3324ValueGPRSTimer2 = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3324ValueGPRSTimer2)
		INIT_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3324ValueGPRSTimer2);
		EDFree (sp->T3324ValueGPRSTimer2);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedDRXParameters_Present == present) return ED_NO_ERRORS;
	sp->ExtendedDRXParameters_Present = present;
	if (present) {
		/*-->*/sp->ExtendedDRXParameters = (c_epsExtendedDRXParameters*)EDAlloc (sizeof (c_epsExtendedDRXParameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedDRXParameters)
		INIT_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
	} else {
		FREE_c_epsExtendedDRXParameters (sp->ExtendedDRXParameters);
		EDFree (sp->ExtendedDRXParameters);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->HeaderCompressionCfgStatus_Present == present) return ED_NO_ERRORS;
	sp->HeaderCompressionCfgStatus_Present = present;
	if (present) {
		/*-->*/sp->HeaderCompressionCfgStatus = (c_HeaderCompressionCfgStatus*)EDAlloc (sizeof (c_HeaderCompressionCfgStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->HeaderCompressionCfgStatus)
		INIT_c_HeaderCompressionCfgStatus (sp->HeaderCompressionCfgStatus);
	} else {
		FREE_c_HeaderCompressionCfgStatus (sp->HeaderCompressionCfgStatus);
		EDFree (sp->HeaderCompressionCfgStatus);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_TRACKING_AREA_UPDATE_REJECT */
void FREE_c_TRACKING_AREA_UPDATE_REJECT (c_TRACKING_AREA_UPDATE_REJECT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->T3346Value_Present) {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
		sp->T3346Value_Present = ED_FALSE;
	}
	if (sp->ExtendedEMMCause_Present) {
		FREE_c_ExtendedEMMCause (sp->ExtendedEMMCause);
		EDFree (sp->ExtendedEMMCause);
		sp->ExtendedEMMCause_Present = ED_FALSE;
	}

}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (c_TRACKING_AREA_UPDATE_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->T3346Value_Present == present) return ED_NO_ERRORS;
	sp->T3346Value_Present = present;
	if (present) {
		/*-->*/sp->T3346Value = (c_epsGprsTimer2*)EDAlloc (sizeof (c_epsGprsTimer2));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->T3346Value)
		INIT_c_epsGprsTimer2 (sp->T3346Value);
	} else {
		FREE_c_epsGprsTimer2 (sp->T3346Value);
		EDFree (sp->T3346Value);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause (c_TRACKING_AREA_UPDATE_REJECT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->ExtendedEMMCause_Present == present) return ED_NO_ERRORS;
	sp->ExtendedEMMCause_Present = present;
	if (present) {
		/*-->*/sp->ExtendedEMMCause = (c_ExtendedEMMCause*)EDAlloc (sizeof (c_ExtendedEMMCause));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->ExtendedEMMCause)
		INIT_c_ExtendedEMMCause (sp->ExtendedEMMCause);
	} else {
		FREE_c_ExtendedEMMCause (sp->ExtendedEMMCause);
		EDFree (sp->ExtendedEMMCause);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_DOWNLINK_GENERIC_NAS_TRANSPORT */
void FREE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (c_DOWNLINK_GENERIC_NAS_TRANSPORT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->GenericMessageContainer.value != NULL) {
		EDFree (sp->GenericMessageContainer.value);
		sp->GenericMessageContainer.value = NULL;
	}
	sp->GenericMessageContainer.usedBits = 0;
	if (sp->AdditionalInformation_Present) {
		if (sp->AdditionalInformation->value != NULL) {
			EDFree (sp->AdditionalInformation->value);
			sp->AdditionalInformation->value = NULL;
		}
		sp->AdditionalInformation->usedBits = 0;
		EDFree (sp->AdditionalInformation);
		sp->AdditionalInformation_Present = ED_FALSE;
	}

}

int SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (c_DOWNLINK_GENERIC_NAS_TRANSPORT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->AdditionalInformation_Present == present) return ED_NO_ERRORS;
	sp->AdditionalInformation_Present = present;
	if (present) {
		/*-->*/sp->AdditionalInformation = (c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation*)EDAlloc (sizeof (c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->AdditionalInformation)
		
		sp->AdditionalInformation->value = NULL;
		sp->AdditionalInformation->usedBits = 0;
	} else {
		if (sp->AdditionalInformation->value != NULL) {
			EDFree (sp->AdditionalInformation->value);
			sp->AdditionalInformation->value = NULL;
		}
		sp->AdditionalInformation->usedBits = 0;
		EDFree (sp->AdditionalInformation);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_SERVICE_ACCEPT */
void FREE_c_SERVICE_ACCEPT (c_SERVICE_ACCEPT* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->EPSBearerContextStatus_Present) {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
		sp->EPSBearerContextStatus_Present = ED_FALSE;
	}

}

int SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (c_SERVICE_ACCEPT* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EPSBearerContextStatus_Present == present) return ED_NO_ERRORS;
	sp->EPSBearerContextStatus_Present = present;
	if (present) {
		/*-->*/sp->EPSBearerContextStatus = (c_EPSBearerContextStatus*)EDAlloc (sizeof (c_EPSBearerContextStatus));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EPSBearerContextStatus)
		INIT_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
	} else {
		FREE_c_EPSBearerContextStatus (sp->EPSBearerContextStatus);
		EDFree (sp->EPSBearerContextStatus);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_epsGprsTimer3 */
void FREE_c_epsGprsTimer3 (c_epsGprsTimer3* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsCalledPartyBcdNum */
void FREE_c_epsCalledPartyBcdNum (c_epsCalledPartyBcdNum* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_epsTBCDArray (&(sp->Number));

}

/* Free function for struct c_GenericTLV_EPS */
void FREE_c_GenericTLV_EPS (c_GenericTLV_EPS* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TLV_Data.value != NULL) {
		EDFree (sp->TLV_Data.value);
		sp->TLV_Data.value = NULL;
	}
	sp->TLV_Data.usedBits = 0;

}

/* SETITEMS commands for type 'c_RemoteUEContext_Identity_IdentityDigit'. Existing items are not changed. */
int SETITEMS_c_RemoteUEContext_Identity_IdentityDigit (c_RemoteUEContext_Identity_IdentityDigit* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_RemoteUEContext_SingleContext_UserIDs'. Existing items are not changed. */
int SETITEMS_c_RemoteUEContext_SingleContext_UserIDs (c_RemoteUEContext_SingleContext_UserIDs* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_RemoteUEContext_Identity** tmp;
		tmp = (c_RemoteUEContext_Identity**)EDAlloc (sizeof (c_RemoteUEContext_Identity*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_RemoteUEContext_Identity*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_RemoteUEContext_Identity*)EDAlloc (sizeof (c_RemoteUEContext_Identity));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_RemoteUEContext_Identity (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_RemoteUEContext_Identity (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_APNAggregateMaxBitRate_ext */
void FREE_c_APNAggregateMaxBitRate_ext (c_APNAggregateMaxBitRate_ext* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_APNAggregateMaxBitRate_ext2 */
void FREE_c_APNAggregateMaxBitRate_ext2 (c_APNAggregateMaxBitRate_ext2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPS_QOS_basic */
void FREE_c_EPS_QOS_basic (c_EPS_QOS_basic* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPS_QOS_extended */
void FREE_c_EPS_QOS_extended (c_EPS_QOS_extended* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EPS_QOS_extended2 */
void FREE_c_EPS_QOS_extended2 (c_EPS_QOS_extended2* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsQualityOfServ_downlink */
void FREE_c_epsQualityOfServ_downlink (c_epsQualityOfServ_downlink* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsQualityOfServ_uplink */
void FREE_c_epsQualityOfServ_uplink (c_epsQualityOfServ_uplink* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsQualityOfServ_ext2downlink */
void FREE_c_epsQualityOfServ_ext2downlink (c_epsQualityOfServ_ext2downlink* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_epsQualityOfServ_ext2uplink */
void FREE_c_epsQualityOfServ_ext2uplink (c_epsQualityOfServ_ext2uplink* sp) {
ED_WARNING_REMOVER(sp);

}

/* SETITEMS commands for type 'c_RemoteUEContext_Contexts'. Existing items are not changed. */
int SETITEMS_c_RemoteUEContext_Contexts (c_RemoteUEContext_Contexts* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_RemoteUEContext_SingleContext** tmp;
		tmp = (c_RemoteUEContext_SingleContext**)EDAlloc (sizeof (c_RemoteUEContext_SingleContext*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_RemoteUEContext_SingleContext*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_RemoteUEContext_SingleContext*)EDAlloc (sizeof (c_RemoteUEContext_SingleContext));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			INIT_c_RemoteUEContext_SingleContext (sequence->data[i]);
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				FREE_c_RemoteUEContext_SingleContext (sequence->data[i]);
				EDFree (sequence->data[i]);
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* SETITEMS commands for type 'c_epsTrafficFlowTemplate_PacketFilters'. Existing items are not changed. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketFilters (c_epsTrafficFlowTemplate_PacketFilters* sequence, int desiredItems)
{
	int i, i0;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsTrafficFlowTemplate_PacketFilters_data** tmp;
		tmp = (c_epsTrafficFlowTemplate_PacketFilters_data**)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketFilters_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsTrafficFlowTemplate_PacketFilters_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsTrafficFlowTemplate_PacketFilters_data*)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketFilters_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_epsTrafficFlowTemplate_PacketFilters_data));
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

/* Free function for struct c_epsTrafficFlowTemplate_PacketFilters_data */
void FREE_c_epsTrafficFlowTemplate_PacketFilters_data (c_epsTrafficFlowTemplate_PacketFilters_data* sp) {
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

/* SETITEMS commands for type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents'. Existing items are not changed. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data** tmp;
		tmp = (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data**)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data*)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data));
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

/* Free function for struct c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data */
void FREE_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->ComponentData.value != NULL) {
		EDFree (sp->ComponentData.value);
		sp->ComponentData.value = NULL;
	}
	sp->ComponentData.usedBits = 0;

}

/* SETITEMS commands for type 'c_epsTrafficFlowTemplate_PacketParameters'. Existing items are not changed. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketParameters (c_epsTrafficFlowTemplate_PacketParameters* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_epsTrafficFlowTemplate_PacketParameters_data** tmp;
		tmp = (c_epsTrafficFlowTemplate_PacketParameters_data**)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketParameters_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_epsTrafficFlowTemplate_PacketParameters_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_epsTrafficFlowTemplate_PacketParameters_data*)EDAlloc (sizeof (c_epsTrafficFlowTemplate_PacketParameters_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_epsTrafficFlowTemplate_PacketParameters_data));
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

/* Free function for struct c_epsTrafficFlowTemplate_PacketParameters_data */
void FREE_c_epsTrafficFlowTemplate_PacketParameters_data (c_epsTrafficFlowTemplate_PacketParameters_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Contents.value != NULL) {
		EDFree (sp->Contents.value);
		sp->Contents.value = NULL;
	}
	sp->Contents.usedBits = 0;

}

/* SETITEMS commands for type 'c_EPSMobileIdentity_IMSI_IdentityDigit'. Existing items are not changed. */
int SETITEMS_c_EPSMobileIdentity_IMSI_IdentityDigit (c_EPSMobileIdentity_IMSI_IdentityDigit* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_epsMobileId_Identity_IdentityDigit'. Existing items are not changed. */
int SETITEMS_c_epsMobileId_Identity_IdentityDigit (c_epsMobileId_Identity_IdentityDigit* sequence, int desiredItems)
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

/* SETITEMS commands for type 'c_epsTBCDEmergencyNumber_Numbers'. Existing items are not changed. */
int SETITEMS_c_epsTBCDEmergencyNumber_Numbers (c_epsTBCDEmergencyNumber_Numbers* sequence, int desiredItems)
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

/* Free function for struct c_UENetworkCapability_octet_5 */
void FREE_c_UENetworkCapability_octet_5 (c_UENetworkCapability_octet_5* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UENetworkCapability_octet_6 */
void FREE_c_UENetworkCapability_octet_6 (c_UENetworkCapability_octet_6* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UENetworkCapability_octet_7 */
void FREE_c_UENetworkCapability_octet_7 (c_UENetworkCapability_octet_7* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UENetworkCapability_octet_8 */
void FREE_c_UENetworkCapability_octet_8 (c_UENetworkCapability_octet_8* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UESecurityCapability_UEA_UIA */
void FREE_c_UESecurityCapability_UEA_UIA (c_UESecurityCapability_UEA_UIA* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_UESecurityCapability_GEA */
void FREE_c_UESecurityCapability_GEA (c_UESecurityCapability_GEA* sp) {
ED_WARNING_REMOVER(sp);

}

