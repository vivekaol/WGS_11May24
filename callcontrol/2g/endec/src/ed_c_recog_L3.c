/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_recog_L3.h"
#include "ed_lib.h"
#include "L3Uplink_L3.h"
#include "L3Downlink_L3.h"
#include "XTIDUplink_L3.h"
#include "XTIDDownlink_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


int SETPRESENT_TL3Uplink_Data (TL3Uplink_Data* sp, TL3Uplink_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TL3Uplink_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_L3Uplink_AUTHENTICATION_RESPONSE_UP: {
			sp->Data.fld_c_AUTHENTICATION_RESPONSE_UP = (c_AUTHENTICATION_RESPONSE_UP*)EDAlloc (sizeof (c_AUTHENTICATION_RESPONSE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_RESPONSE_UP == NULL)
			INIT_c_AUTHENTICATION_RESPONSE_UP (sp->Data.fld_c_AUTHENTICATION_RESPONSE_UP);
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_FAILURE_UP: {
			sp->Data.fld_c_AUTHENTICATION_FAILURE_UP = (c_AUTHENTICATION_FAILURE_UP*)EDAlloc (sizeof (c_AUTHENTICATION_FAILURE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_FAILURE_UP == NULL)
			INIT_c_AUTHENTICATION_FAILURE_UP (sp->Data.fld_c_AUTHENTICATION_FAILURE_UP);
			break;
		}
		
		case ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP: {
			sp->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP = (c_CM_RE_ESTABLISHMENT_REQUEST_UP*)EDAlloc (sizeof (c_CM_RE_ESTABLISHMENT_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP == NULL)
			INIT_c_CM_RE_ESTABLISHMENT_REQUEST_UP (sp->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_CM_SERVICE_ABORT_UP: {
			sp->Data.fld_c_CM_SERVICE_ABORT_UP = (c_CM_SERVICE_ABORT_UP*)EDAlloc (sizeof (c_CM_SERVICE_ABORT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_SERVICE_ABORT_UP == NULL)
			INIT_c_CM_SERVICE_ABORT_UP (sp->Data.fld_c_CM_SERVICE_ABORT_UP);
			break;
		}
		
		case ID_L3Uplink_CM_SERVICE_REQUEST_UP: {
			sp->Data.fld_c_CM_SERVICE_REQUEST_UP = (c_CM_SERVICE_REQUEST_UP*)EDAlloc (sizeof (c_CM_SERVICE_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_SERVICE_REQUEST_UP == NULL)
			INIT_c_CM_SERVICE_REQUEST_UP (sp->Data.fld_c_CM_SERVICE_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_IDENTITY_RESPONSE_UP: {
			sp->Data.fld_c_IDENTITY_RESPONSE_UP = (c_IDENTITY_RESPONSE_UP*)EDAlloc (sizeof (c_IDENTITY_RESPONSE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_IDENTITY_RESPONSE_UP == NULL)
			INIT_c_IDENTITY_RESPONSE_UP (sp->Data.fld_c_IDENTITY_RESPONSE_UP);
			break;
		}
		
		case ID_L3Uplink_IMSI_DETACH_INDICATION_UP: {
			sp->Data.fld_c_IMSI_DETACH_INDICATION_UP = (c_IMSI_DETACH_INDICATION_UP*)EDAlloc (sizeof (c_IMSI_DETACH_INDICATION_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_IMSI_DETACH_INDICATION_UP == NULL)
			INIT_c_IMSI_DETACH_INDICATION_UP (sp->Data.fld_c_IMSI_DETACH_INDICATION_UP);
			break;
		}
		
		case ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP: {
			sp->Data.fld_c_LOCATION_UPDATING_REQUEST_UP = (c_LOCATION_UPDATING_REQUEST_UP*)EDAlloc (sizeof (c_LOCATION_UPDATING_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_LOCATION_UPDATING_REQUEST_UP == NULL)
			INIT_c_LOCATION_UPDATING_REQUEST_UP (sp->Data.fld_c_LOCATION_UPDATING_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_MM_STATUS: {
			sp->Data.fld_c_MM_STATUS = (c_MM_STATUS*)EDAlloc (sizeof (c_MM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MM_STATUS == NULL)
			INIT_c_MM_STATUS (sp->Data.fld_c_MM_STATUS);
			break;
		}
		
		case ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP: {
			sp->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP = (c_TMSI_REALLOCATION_COMPLETE_UP*)EDAlloc (sizeof (c_TMSI_REALLOCATION_COMPLETE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP == NULL)
			INIT_c_TMSI_REALLOCATION_COMPLETE_UP (sp->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP);
			break;
		}
		
		case ID_L3Uplink_MM_NULL_UP: {
			sp->Data.fld_c_MM_NULL_UP = (c_MM_NULL_UP*)EDAlloc (sizeof (c_MM_NULL_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MM_NULL_UP == NULL)
			INIT_c_MM_NULL_UP (sp->Data.fld_c_MM_NULL_UP);
			break;
		}
		
		case ID_L3Uplink_ALERTING_UP: {
			sp->Data.fld_c_ALERTING_UP = (c_ALERTING_UP*)EDAlloc (sizeof (c_ALERTING_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ALERTING_UP == NULL)
			INIT_c_ALERTING_UP (sp->Data.fld_c_ALERTING_UP);
			break;
		}
		
		case ID_L3Uplink_CALL_CONFIRMED_UP: {
			sp->Data.fld_c_CALL_CONFIRMED_UP = (c_CALL_CONFIRMED_UP*)EDAlloc (sizeof (c_CALL_CONFIRMED_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CALL_CONFIRMED_UP == NULL)
			INIT_c_CALL_CONFIRMED_UP (sp->Data.fld_c_CALL_CONFIRMED_UP);
			break;
		}
		
		case ID_L3Uplink_CONNECT_UP: {
			sp->Data.fld_c_CONNECT_UP = (c_CONNECT_UP*)EDAlloc (sizeof (c_CONNECT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CONNECT_UP == NULL)
			INIT_c_CONNECT_UP (sp->Data.fld_c_CONNECT_UP);
			break;
		}
		
		case ID_L3Uplink_CONNECT_ACKNOWLEDGE: {
			sp->Data.fld_c_CONNECT_ACKNOWLEDGE = (c_CONNECT_ACKNOWLEDGE*)EDAlloc (sizeof (c_CONNECT_ACKNOWLEDGE)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CONNECT_ACKNOWLEDGE == NULL)
			INIT_c_CONNECT_ACKNOWLEDGE (sp->Data.fld_c_CONNECT_ACKNOWLEDGE);
			break;
		}
		
		case ID_L3Uplink_DISCONNECT_UP: {
			sp->Data.fld_c_DISCONNECT_UP = (c_DISCONNECT_UP*)EDAlloc (sizeof (c_DISCONNECT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DISCONNECT_UP == NULL)
			INIT_c_DISCONNECT_UP (sp->Data.fld_c_DISCONNECT_UP);
			break;
		}
		
		case ID_L3Uplink_EMERGENCY_SETUP_UP: {
			sp->Data.fld_c_EMERGENCY_SETUP_UP = (c_EMERGENCY_SETUP_UP*)EDAlloc (sizeof (c_EMERGENCY_SETUP_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EMERGENCY_SETUP_UP == NULL)
			INIT_c_EMERGENCY_SETUP_UP (sp->Data.fld_c_EMERGENCY_SETUP_UP);
			break;
		}
		
		case ID_L3Uplink_FACILITY_UP: {
			sp->Data.fld_c_FACILITY_UP = (c_FACILITY_UP*)EDAlloc (sizeof (c_FACILITY_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_FACILITY_UP == NULL)
			INIT_c_FACILITY_UP (sp->Data.fld_c_FACILITY_UP);
			break;
		}
		
		case ID_L3Uplink_HOLD_UP: {
			sp->Data.fld_c_HOLD_UP = (c_HOLD_UP*)EDAlloc (sizeof (c_HOLD_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_HOLD_UP == NULL)
			INIT_c_HOLD_UP (sp->Data.fld_c_HOLD_UP);
			break;
		}
		
		case ID_L3Uplink_MODIFY: {
			sp->Data.fld_c_MODIFY = (c_MODIFY*)EDAlloc (sizeof (c_MODIFY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY == NULL)
			INIT_c_MODIFY (sp->Data.fld_c_MODIFY);
			break;
		}
		
		case ID_L3Uplink_MODIFY_COMPLETE: {
			sp->Data.fld_c_MODIFY_COMPLETE = (c_MODIFY_COMPLETE*)EDAlloc (sizeof (c_MODIFY_COMPLETE)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_COMPLETE == NULL)
			INIT_c_MODIFY_COMPLETE (sp->Data.fld_c_MODIFY_COMPLETE);
			break;
		}
		
		case ID_L3Uplink_MODIFY_REJECT: {
			sp->Data.fld_c_MODIFY_REJECT = (c_MODIFY_REJECT*)EDAlloc (sizeof (c_MODIFY_REJECT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_REJECT == NULL)
			INIT_c_MODIFY_REJECT (sp->Data.fld_c_MODIFY_REJECT);
			break;
		}
		
		case ID_L3Uplink_NOTIFY: {
			sp->Data.fld_c_NOTIFY = (c_NOTIFY*)EDAlloc (sizeof (c_NOTIFY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_NOTIFY == NULL)
			INIT_c_NOTIFY (sp->Data.fld_c_NOTIFY);
			break;
		}
		
		case ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP: {
			sp->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP = (c_CC_ESTABLISHMENT_CONFIRMED_UP*)EDAlloc (sizeof (c_CC_ESTABLISHMENT_CONFIRMED_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP == NULL)
			INIT_c_CC_ESTABLISHMENT_CONFIRMED_UP (sp->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP);
			break;
		}
		
		case ID_L3Uplink_RELEASE_UP: {
			sp->Data.fld_c_RELEASE_UP = (c_RELEASE_UP*)EDAlloc (sizeof (c_RELEASE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RELEASE_UP == NULL)
			INIT_c_RELEASE_UP (sp->Data.fld_c_RELEASE_UP);
			break;
		}
		
		case ID_L3Uplink_RELEASE_COMPLETE_UP: {
			sp->Data.fld_c_RELEASE_COMPLETE_UP = (c_RELEASE_COMPLETE_UP*)EDAlloc (sizeof (c_RELEASE_COMPLETE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RELEASE_COMPLETE_UP == NULL)
			INIT_c_RELEASE_COMPLETE_UP (sp->Data.fld_c_RELEASE_COMPLETE_UP);
			break;
		}
		
		case ID_L3Uplink_RETRIEVE_UP: {
			sp->Data.fld_c_RETRIEVE_UP = (c_RETRIEVE_UP*)EDAlloc (sizeof (c_RETRIEVE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RETRIEVE_UP == NULL)
			INIT_c_RETRIEVE_UP (sp->Data.fld_c_RETRIEVE_UP);
			break;
		}
		
		case ID_L3Uplink_SETUP_UP: {
			sp->Data.fld_c_SETUP_UP = (c_SETUP_UP*)EDAlloc (sizeof (c_SETUP_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SETUP_UP == NULL)
			INIT_c_SETUP_UP (sp->Data.fld_c_SETUP_UP);
			break;
		}
		
		case ID_L3Uplink_START_CC_UP: {
			sp->Data.fld_c_START_CC_UP = (c_START_CC_UP*)EDAlloc (sizeof (c_START_CC_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_START_CC_UP == NULL)
			INIT_c_START_CC_UP (sp->Data.fld_c_START_CC_UP);
			break;
		}
		
		case ID_L3Uplink_START_DTMF_UP: {
			sp->Data.fld_c_START_DTMF_UP = (c_START_DTMF_UP*)EDAlloc (sizeof (c_START_DTMF_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_START_DTMF_UP == NULL)
			INIT_c_START_DTMF_UP (sp->Data.fld_c_START_DTMF_UP);
			break;
		}
		
		case ID_L3Uplink_STATUS: {
			sp->Data.fld_c_STATUS = (c_STATUS*)EDAlloc (sizeof (c_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STATUS == NULL)
			INIT_c_STATUS (sp->Data.fld_c_STATUS);
			break;
		}
		
		case ID_L3Uplink_STATUS_ENQUIRY: {
			sp->Data.fld_c_STATUS_ENQUIRY = (c_STATUS_ENQUIRY*)EDAlloc (sizeof (c_STATUS_ENQUIRY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STATUS_ENQUIRY == NULL)
			INIT_c_STATUS_ENQUIRY (sp->Data.fld_c_STATUS_ENQUIRY);
			break;
		}
		
		case ID_L3Uplink_STOP_DTMF_UP: {
			sp->Data.fld_c_STOP_DTMF_UP = (c_STOP_DTMF_UP*)EDAlloc (sizeof (c_STOP_DTMF_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STOP_DTMF_UP == NULL)
			INIT_c_STOP_DTMF_UP (sp->Data.fld_c_STOP_DTMF_UP);
			break;
		}
		
		case ID_L3Uplink_USER_INFORMATION: {
			sp->Data.fld_c_USER_INFORMATION = (c_USER_INFORMATION*)EDAlloc (sizeof (c_USER_INFORMATION)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_USER_INFORMATION == NULL)
			INIT_c_USER_INFORMATION (sp->Data.fld_c_USER_INFORMATION);
			break;
		}
		
		case ID_L3Uplink_ATTACH_REQUEST_UP: {
			sp->Data.fld_c_ATTACH_REQUEST_UP = (c_ATTACH_REQUEST_UP*)EDAlloc (sizeof (c_ATTACH_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ATTACH_REQUEST_UP == NULL)
			INIT_c_ATTACH_REQUEST_UP (sp->Data.fld_c_ATTACH_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_ATTACH_COMPLETE_UP: {
			sp->Data.fld_c_ATTACH_COMPLETE_UP = (c_ATTACH_COMPLETE_UP*)EDAlloc (sizeof (c_ATTACH_COMPLETE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ATTACH_COMPLETE_UP == NULL)
			INIT_c_ATTACH_COMPLETE_UP (sp->Data.fld_c_ATTACH_COMPLETE_UP);
			break;
		}
		
		case ID_L3Uplink_DETACH_REQUEST_UP: {
			sp->Data.fld_c_DETACH_REQUEST_UP = (c_DETACH_REQUEST_UP*)EDAlloc (sizeof (c_DETACH_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DETACH_REQUEST_UP == NULL)
			INIT_c_DETACH_REQUEST_UP (sp->Data.fld_c_DETACH_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_DETACH_ACCEPT_UP: {
			sp->Data.fld_c_DETACH_ACCEPT_UP = (c_DETACH_ACCEPT_UP*)EDAlloc (sizeof (c_DETACH_ACCEPT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DETACH_ACCEPT_UP == NULL)
			INIT_c_DETACH_ACCEPT_UP (sp->Data.fld_c_DETACH_ACCEPT_UP);
			break;
		}
		
		case ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP: {
			sp->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP = (c_P_TMSI_REALLOCATION_COMPLETE_UP*)EDAlloc (sizeof (c_P_TMSI_REALLOCATION_COMPLETE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP == NULL)
			INIT_c_P_TMSI_REALLOCATION_COMPLETE_UP (sp->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP);
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP: {
			sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP = (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP*)EDAlloc (sizeof (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP == NULL)
			INIT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP);
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP: {
			sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP = (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP*)EDAlloc (sizeof (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP == NULL)
			INIT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP);
			break;
		}
		
		case ID_L3Uplink_IDENTITY_RESPONSE_B_UP: {
			sp->Data.fld_c_IDENTITY_RESPONSE_B_UP = (c_IDENTITY_RESPONSE_B_UP*)EDAlloc (sizeof (c_IDENTITY_RESPONSE_B_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_IDENTITY_RESPONSE_B_UP == NULL)
			INIT_c_IDENTITY_RESPONSE_B_UP (sp->Data.fld_c_IDENTITY_RESPONSE_B_UP);
			break;
		}
		
		case ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP: {
			sp->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP = (c_ROUTING_AREA_UPDATE_REQUEST_UP*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP == NULL)
			INIT_c_ROUTING_AREA_UPDATE_REQUEST_UP (sp->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP);
			break;
		}
		
		case ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP: {
			sp->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP = (c_ROUTING_AREA_UPDATE_COMPLETE_UP*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_COMPLETE_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP == NULL)
			INIT_c_ROUTING_AREA_UPDATE_COMPLETE_UP (sp->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP);
			break;
		}
		
		case ID_L3Uplink_GMM_STATUS: {
			sp->Data.fld_c_GMM_STATUS = (c_GMM_STATUS*)EDAlloc (sizeof (c_GMM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_GMM_STATUS == NULL)
			INIT_c_GMM_STATUS (sp->Data.fld_c_GMM_STATUS);
			break;
		}
		
		case ID_L3Uplink_SERVICE_REQUEST_UP: {
			sp->Data.fld_c_SERVICE_REQUEST_UP = (c_SERVICE_REQUEST_UP*)EDAlloc (sizeof (c_SERVICE_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SERVICE_REQUEST_UP == NULL)
			INIT_c_SERVICE_REQUEST_UP (sp->Data.fld_c_SERVICE_REQUEST_UP);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TL3Uplink_Data (TL3Uplink_Data* sp)
{
	switch (sp->Type) {
		case ID_L3Uplink_AUTHENTICATION_RESPONSE_UP: {
			FREE_c_AUTHENTICATION_RESPONSE_UP (sp->Data.fld_c_AUTHENTICATION_RESPONSE_UP);
	EDFree (sp->Data.fld_c_AUTHENTICATION_RESPONSE_UP );
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_FAILURE_UP: {
			FREE_c_AUTHENTICATION_FAILURE_UP (sp->Data.fld_c_AUTHENTICATION_FAILURE_UP);
	EDFree (sp->Data.fld_c_AUTHENTICATION_FAILURE_UP );
			break;
		}
		
		case ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP: {
			FREE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (sp->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP);
	EDFree (sp->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_CM_SERVICE_ABORT_UP: {
			FREE_c_CM_SERVICE_ABORT_UP (sp->Data.fld_c_CM_SERVICE_ABORT_UP);
	EDFree (sp->Data.fld_c_CM_SERVICE_ABORT_UP );
			break;
		}
		
		case ID_L3Uplink_CM_SERVICE_REQUEST_UP: {
			FREE_c_CM_SERVICE_REQUEST_UP (sp->Data.fld_c_CM_SERVICE_REQUEST_UP);
	EDFree (sp->Data.fld_c_CM_SERVICE_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_IDENTITY_RESPONSE_UP: {
			FREE_c_IDENTITY_RESPONSE_UP (sp->Data.fld_c_IDENTITY_RESPONSE_UP);
	EDFree (sp->Data.fld_c_IDENTITY_RESPONSE_UP );
			break;
		}
		
		case ID_L3Uplink_IMSI_DETACH_INDICATION_UP: {
			FREE_c_IMSI_DETACH_INDICATION_UP (sp->Data.fld_c_IMSI_DETACH_INDICATION_UP);
	EDFree (sp->Data.fld_c_IMSI_DETACH_INDICATION_UP );
			break;
		}
		
		case ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP: {
			FREE_c_LOCATION_UPDATING_REQUEST_UP (sp->Data.fld_c_LOCATION_UPDATING_REQUEST_UP);
	EDFree (sp->Data.fld_c_LOCATION_UPDATING_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_MM_STATUS: {
			FREE_c_MM_STATUS (sp->Data.fld_c_MM_STATUS);
	EDFree (sp->Data.fld_c_MM_STATUS );
			break;
		}
		
		case ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP: {
			FREE_c_TMSI_REALLOCATION_COMPLETE_UP (sp->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP);
	EDFree (sp->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP );
			break;
		}
		
		case ID_L3Uplink_MM_NULL_UP: {
			FREE_c_MM_NULL_UP (sp->Data.fld_c_MM_NULL_UP);
	EDFree (sp->Data.fld_c_MM_NULL_UP );
			break;
		}
		
		case ID_L3Uplink_ALERTING_UP: {
			FREE_c_ALERTING_UP (sp->Data.fld_c_ALERTING_UP);
	EDFree (sp->Data.fld_c_ALERTING_UP );
			break;
		}
		
		case ID_L3Uplink_CALL_CONFIRMED_UP: {
			FREE_c_CALL_CONFIRMED_UP (sp->Data.fld_c_CALL_CONFIRMED_UP);
	EDFree (sp->Data.fld_c_CALL_CONFIRMED_UP );
			break;
		}
		
		case ID_L3Uplink_CONNECT_UP: {
			FREE_c_CONNECT_UP (sp->Data.fld_c_CONNECT_UP);
	EDFree (sp->Data.fld_c_CONNECT_UP );
			break;
		}
		
		case ID_L3Uplink_CONNECT_ACKNOWLEDGE: {
			FREE_c_CONNECT_ACKNOWLEDGE (sp->Data.fld_c_CONNECT_ACKNOWLEDGE);
	EDFree (sp->Data.fld_c_CONNECT_ACKNOWLEDGE );
			break;
		}
		
		case ID_L3Uplink_DISCONNECT_UP: {
			FREE_c_DISCONNECT_UP (sp->Data.fld_c_DISCONNECT_UP);
	EDFree (sp->Data.fld_c_DISCONNECT_UP );
			break;
		}
		
		case ID_L3Uplink_EMERGENCY_SETUP_UP: {
			FREE_c_EMERGENCY_SETUP_UP (sp->Data.fld_c_EMERGENCY_SETUP_UP);
	EDFree (sp->Data.fld_c_EMERGENCY_SETUP_UP );
			break;
		}
		
		case ID_L3Uplink_FACILITY_UP: {
			FREE_c_FACILITY_UP (sp->Data.fld_c_FACILITY_UP);
	EDFree (sp->Data.fld_c_FACILITY_UP );
			break;
		}
		
		case ID_L3Uplink_HOLD_UP: {
			FREE_c_HOLD_UP (sp->Data.fld_c_HOLD_UP);
	EDFree (sp->Data.fld_c_HOLD_UP );
			break;
		}
		
		case ID_L3Uplink_MODIFY: {
			FREE_c_MODIFY (sp->Data.fld_c_MODIFY);
	EDFree (sp->Data.fld_c_MODIFY );
			break;
		}
		
		case ID_L3Uplink_MODIFY_COMPLETE: {
			FREE_c_MODIFY_COMPLETE (sp->Data.fld_c_MODIFY_COMPLETE);
	EDFree (sp->Data.fld_c_MODIFY_COMPLETE );
			break;
		}
		
		case ID_L3Uplink_MODIFY_REJECT: {
			FREE_c_MODIFY_REJECT (sp->Data.fld_c_MODIFY_REJECT);
	EDFree (sp->Data.fld_c_MODIFY_REJECT );
			break;
		}
		
		case ID_L3Uplink_NOTIFY: {
			FREE_c_NOTIFY (sp->Data.fld_c_NOTIFY);
	EDFree (sp->Data.fld_c_NOTIFY );
			break;
		}
		
		case ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP: {
			FREE_c_CC_ESTABLISHMENT_CONFIRMED_UP (sp->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP);
	EDFree (sp->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP );
			break;
		}
		
		case ID_L3Uplink_RELEASE_UP: {
			FREE_c_RELEASE_UP (sp->Data.fld_c_RELEASE_UP);
	EDFree (sp->Data.fld_c_RELEASE_UP );
			break;
		}
		
		case ID_L3Uplink_RELEASE_COMPLETE_UP: {
			FREE_c_RELEASE_COMPLETE_UP (sp->Data.fld_c_RELEASE_COMPLETE_UP);
	EDFree (sp->Data.fld_c_RELEASE_COMPLETE_UP );
			break;
		}
		
		case ID_L3Uplink_RETRIEVE_UP: {
			FREE_c_RETRIEVE_UP (sp->Data.fld_c_RETRIEVE_UP);
	EDFree (sp->Data.fld_c_RETRIEVE_UP );
			break;
		}
		
		case ID_L3Uplink_SETUP_UP: {
			FREE_c_SETUP_UP (sp->Data.fld_c_SETUP_UP);
	EDFree (sp->Data.fld_c_SETUP_UP );
			break;
		}
		
		case ID_L3Uplink_START_CC_UP: {
			FREE_c_START_CC_UP (sp->Data.fld_c_START_CC_UP);
	EDFree (sp->Data.fld_c_START_CC_UP );
			break;
		}
		
		case ID_L3Uplink_START_DTMF_UP: {
			FREE_c_START_DTMF_UP (sp->Data.fld_c_START_DTMF_UP);
	EDFree (sp->Data.fld_c_START_DTMF_UP );
			break;
		}
		
		case ID_L3Uplink_STATUS: {
			FREE_c_STATUS (sp->Data.fld_c_STATUS);
	EDFree (sp->Data.fld_c_STATUS );
			break;
		}
		
		case ID_L3Uplink_STATUS_ENQUIRY: {
			FREE_c_STATUS_ENQUIRY (sp->Data.fld_c_STATUS_ENQUIRY);
	EDFree (sp->Data.fld_c_STATUS_ENQUIRY );
			break;
		}
		
		case ID_L3Uplink_STOP_DTMF_UP: {
			FREE_c_STOP_DTMF_UP (sp->Data.fld_c_STOP_DTMF_UP);
	EDFree (sp->Data.fld_c_STOP_DTMF_UP );
			break;
		}
		
		case ID_L3Uplink_USER_INFORMATION: {
			FREE_c_USER_INFORMATION (sp->Data.fld_c_USER_INFORMATION);
	EDFree (sp->Data.fld_c_USER_INFORMATION );
			break;
		}
		
		case ID_L3Uplink_ATTACH_REQUEST_UP: {
			FREE_c_ATTACH_REQUEST_UP (sp->Data.fld_c_ATTACH_REQUEST_UP);
	EDFree (sp->Data.fld_c_ATTACH_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_ATTACH_COMPLETE_UP: {
			FREE_c_ATTACH_COMPLETE_UP (sp->Data.fld_c_ATTACH_COMPLETE_UP);
	EDFree (sp->Data.fld_c_ATTACH_COMPLETE_UP );
			break;
		}
		
		case ID_L3Uplink_DETACH_REQUEST_UP: {
			FREE_c_DETACH_REQUEST_UP (sp->Data.fld_c_DETACH_REQUEST_UP);
	EDFree (sp->Data.fld_c_DETACH_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_DETACH_ACCEPT_UP: {
			FREE_c_DETACH_ACCEPT_UP (sp->Data.fld_c_DETACH_ACCEPT_UP);
	EDFree (sp->Data.fld_c_DETACH_ACCEPT_UP );
			break;
		}
		
		case ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP: {
			FREE_c_P_TMSI_REALLOCATION_COMPLETE_UP (sp->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP);
	EDFree (sp->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP );
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP: {
			FREE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP);
	EDFree (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP );
			break;
		}
		
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP: {
			FREE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP);
	EDFree (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP );
			break;
		}
		
		case ID_L3Uplink_IDENTITY_RESPONSE_B_UP: {
			FREE_c_IDENTITY_RESPONSE_B_UP (sp->Data.fld_c_IDENTITY_RESPONSE_B_UP);
	EDFree (sp->Data.fld_c_IDENTITY_RESPONSE_B_UP );
			break;
		}
		
		case ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP: {
			FREE_c_ROUTING_AREA_UPDATE_REQUEST_UP (sp->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP);
	EDFree (sp->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP );
			break;
		}
		
		case ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP: {
			FREE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (sp->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP);
	EDFree (sp->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP );
			break;
		}
		
		case ID_L3Uplink_GMM_STATUS: {
			FREE_c_GMM_STATUS (sp->Data.fld_c_GMM_STATUS);
	EDFree (sp->Data.fld_c_GMM_STATUS );
			break;
		}
		
		case ID_L3Uplink_SERVICE_REQUEST_UP: {
			FREE_c_SERVICE_REQUEST_UP (sp->Data.fld_c_SERVICE_REQUEST_UP);
	EDFree (sp->Data.fld_c_SERVICE_REQUEST_UP );
			break;
		}
		
		default:;
	}

	sp->Type = ID_L3Uplink_Unrecognized;
}

int SETPRESENT_TDummyDownlink_Data (TDummyDownlink_Data* sp, TDummyDownlink_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TDummyDownlink_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_DummyDownlink_SETUP_UP: {
			sp->Data.fld_c_SETUP_UP = (c_SETUP_UP*)EDAlloc (sizeof (c_SETUP_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SETUP_UP == NULL)
			INIT_c_SETUP_UP (sp->Data.fld_c_SETUP_UP);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TDummyDownlink_Data (TDummyDownlink_Data* sp)
{
	switch (sp->Type) {
		case ID_DummyDownlink_SETUP_UP: {
			FREE_c_SETUP_UP (sp->Data.fld_c_SETUP_UP);
	EDFree (sp->Data.fld_c_SETUP_UP );
			break;
		}
		
		default:;
	}

	sp->Type = ID_DummyDownlink_Unrecognized;
}

int SETPRESENT_TL3Downlink_Data (TL3Downlink_Data* sp, TL3Downlink_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TL3Downlink_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_L3Downlink_AUTHENTICATION_REJECT_DN: {
			sp->Data.fld_c_AUTHENTICATION_REJECT_DN = (c_AUTHENTICATION_REJECT_DN*)EDAlloc (sizeof (c_AUTHENTICATION_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_REJECT_DN == NULL)
			INIT_c_AUTHENTICATION_REJECT_DN (sp->Data.fld_c_AUTHENTICATION_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_REQUEST_DN: {
			sp->Data.fld_c_AUTHENTICATION_REQUEST_DN = (c_AUTHENTICATION_REQUEST_DN*)EDAlloc (sizeof (c_AUTHENTICATION_REQUEST_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_REQUEST_DN == NULL)
			INIT_c_AUTHENTICATION_REQUEST_DN (sp->Data.fld_c_AUTHENTICATION_REQUEST_DN);
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_ACCEPT_DN: {
			sp->Data.fld_c_CM_SERVICE_ACCEPT_DN = (c_CM_SERVICE_ACCEPT_DN*)EDAlloc (sizeof (c_CM_SERVICE_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_SERVICE_ACCEPT_DN == NULL)
			INIT_c_CM_SERVICE_ACCEPT_DN (sp->Data.fld_c_CM_SERVICE_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_PROMPT_DN: {
			sp->Data.fld_c_CM_SERVICE_PROMPT_DN = (c_CM_SERVICE_PROMPT_DN*)EDAlloc (sizeof (c_CM_SERVICE_PROMPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_SERVICE_PROMPT_DN == NULL)
			INIT_c_CM_SERVICE_PROMPT_DN (sp->Data.fld_c_CM_SERVICE_PROMPT_DN);
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_REJECT_DN: {
			sp->Data.fld_c_CM_SERVICE_REJECT_DN = (c_CM_SERVICE_REJECT_DN*)EDAlloc (sizeof (c_CM_SERVICE_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CM_SERVICE_REJECT_DN == NULL)
			INIT_c_CM_SERVICE_REJECT_DN (sp->Data.fld_c_CM_SERVICE_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_ABORT_DN: {
			sp->Data.fld_c_ABORT_DN = (c_ABORT_DN*)EDAlloc (sizeof (c_ABORT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ABORT_DN == NULL)
			INIT_c_ABORT_DN (sp->Data.fld_c_ABORT_DN);
			break;
		}
		
		case ID_L3Downlink_IDENTITY_REQUEST_DN: {
			sp->Data.fld_c_IDENTITY_REQUEST_DN = (c_IDENTITY_REQUEST_DN*)EDAlloc (sizeof (c_IDENTITY_REQUEST_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_IDENTITY_REQUEST_DN == NULL)
			INIT_c_IDENTITY_REQUEST_DN (sp->Data.fld_c_IDENTITY_REQUEST_DN);
			break;
		}
		
		case ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN: {
			sp->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN = (c_LOCATION_UPDATING_ACCEPT_DN*)EDAlloc (sizeof (c_LOCATION_UPDATING_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN == NULL)
			INIT_c_LOCATION_UPDATING_ACCEPT_DN (sp->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_LOCATION_UPDATING_REJECT_DN: {
			sp->Data.fld_c_LOCATION_UPDATING_REJECT_DN = (c_LOCATION_UPDATING_REJECT_DN*)EDAlloc (sizeof (c_LOCATION_UPDATING_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_LOCATION_UPDATING_REJECT_DN == NULL)
			INIT_c_LOCATION_UPDATING_REJECT_DN (sp->Data.fld_c_LOCATION_UPDATING_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_MM_INFORMATION_DN: {
			sp->Data.fld_c_MM_INFORMATION_DN = (c_MM_INFORMATION_DN*)EDAlloc (sizeof (c_MM_INFORMATION_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MM_INFORMATION_DN == NULL)
			INIT_c_MM_INFORMATION_DN (sp->Data.fld_c_MM_INFORMATION_DN);
			break;
		}
		
		case ID_L3Downlink_MM_STATUS: {
			sp->Data.fld_c_MM_STATUS = (c_MM_STATUS*)EDAlloc (sizeof (c_MM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MM_STATUS == NULL)
			INIT_c_MM_STATUS (sp->Data.fld_c_MM_STATUS);
			break;
		}
		
		case ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN: {
			sp->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN = (c_TMSI_REALLOCATION_COMMAND_DN*)EDAlloc (sizeof (c_TMSI_REALLOCATION_COMMAND_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN == NULL)
			INIT_c_TMSI_REALLOCATION_COMMAND_DN (sp->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN);
			break;
		}
		
		case ID_L3Downlink_ALERTING_DN: {
			sp->Data.fld_c_ALERTING_DN = (c_ALERTING_DN*)EDAlloc (sizeof (c_ALERTING_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ALERTING_DN == NULL)
			INIT_c_ALERTING_DN (sp->Data.fld_c_ALERTING_DN);
			break;
		}
		
		case ID_L3Downlink_CALL_PROCEEDING_DN: {
			sp->Data.fld_c_CALL_PROCEEDING_DN = (c_CALL_PROCEEDING_DN*)EDAlloc (sizeof (c_CALL_PROCEEDING_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CALL_PROCEEDING_DN == NULL)
			INIT_c_CALL_PROCEEDING_DN (sp->Data.fld_c_CALL_PROCEEDING_DN);
			break;
		}
		
		case ID_L3Downlink_CONGESTION_CONTROL_DN: {
			sp->Data.fld_c_CONGESTION_CONTROL_DN = (c_CONGESTION_CONTROL_DN*)EDAlloc (sizeof (c_CONGESTION_CONTROL_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CONGESTION_CONTROL_DN == NULL)
			INIT_c_CONGESTION_CONTROL_DN (sp->Data.fld_c_CONGESTION_CONTROL_DN);
			break;
		}
		
		case ID_L3Downlink_CONNECT_DN: {
			sp->Data.fld_c_CONNECT_DN = (c_CONNECT_DN*)EDAlloc (sizeof (c_CONNECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CONNECT_DN == NULL)
			INIT_c_CONNECT_DN (sp->Data.fld_c_CONNECT_DN);
			break;
		}
		
		case ID_L3Downlink_CONNECT_ACKNOWLEDGE: {
			sp->Data.fld_c_CONNECT_ACKNOWLEDGE = (c_CONNECT_ACKNOWLEDGE*)EDAlloc (sizeof (c_CONNECT_ACKNOWLEDGE)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CONNECT_ACKNOWLEDGE == NULL)
			INIT_c_CONNECT_ACKNOWLEDGE (sp->Data.fld_c_CONNECT_ACKNOWLEDGE);
			break;
		}
		
		case ID_L3Downlink_DISCONNECT_DN: {
			sp->Data.fld_c_DISCONNECT_DN = (c_DISCONNECT_DN*)EDAlloc (sizeof (c_DISCONNECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DISCONNECT_DN == NULL)
			INIT_c_DISCONNECT_DN (sp->Data.fld_c_DISCONNECT_DN);
			break;
		}
		
		case ID_L3Downlink_FACILITY_DN: {
			sp->Data.fld_c_FACILITY_DN = (c_FACILITY_DN*)EDAlloc (sizeof (c_FACILITY_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_FACILITY_DN == NULL)
			INIT_c_FACILITY_DN (sp->Data.fld_c_FACILITY_DN);
			break;
		}
		
		case ID_L3Downlink_HOLD_ACKNOWLEDGE_DN: {
			sp->Data.fld_c_HOLD_ACKNOWLEDGE_DN = (c_HOLD_ACKNOWLEDGE_DN*)EDAlloc (sizeof (c_HOLD_ACKNOWLEDGE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_HOLD_ACKNOWLEDGE_DN == NULL)
			INIT_c_HOLD_ACKNOWLEDGE_DN (sp->Data.fld_c_HOLD_ACKNOWLEDGE_DN);
			break;
		}
		
		case ID_L3Downlink_HOLD_REJECT_DN: {
			sp->Data.fld_c_HOLD_REJECT_DN = (c_HOLD_REJECT_DN*)EDAlloc (sizeof (c_HOLD_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_HOLD_REJECT_DN == NULL)
			INIT_c_HOLD_REJECT_DN (sp->Data.fld_c_HOLD_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_MODIFY: {
			sp->Data.fld_c_MODIFY = (c_MODIFY*)EDAlloc (sizeof (c_MODIFY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY == NULL)
			INIT_c_MODIFY (sp->Data.fld_c_MODIFY);
			break;
		}
		
		case ID_L3Downlink_MODIFY_COMPLETE: {
			sp->Data.fld_c_MODIFY_COMPLETE = (c_MODIFY_COMPLETE*)EDAlloc (sizeof (c_MODIFY_COMPLETE)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_COMPLETE == NULL)
			INIT_c_MODIFY_COMPLETE (sp->Data.fld_c_MODIFY_COMPLETE);
			break;
		}
		
		case ID_L3Downlink_MODIFY_REJECT: {
			sp->Data.fld_c_MODIFY_REJECT = (c_MODIFY_REJECT*)EDAlloc (sizeof (c_MODIFY_REJECT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_REJECT == NULL)
			INIT_c_MODIFY_REJECT (sp->Data.fld_c_MODIFY_REJECT);
			break;
		}
		
		case ID_L3Downlink_NOTIFY: {
			sp->Data.fld_c_NOTIFY = (c_NOTIFY*)EDAlloc (sizeof (c_NOTIFY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_NOTIFY == NULL)
			INIT_c_NOTIFY (sp->Data.fld_c_NOTIFY);
			break;
		}
		
		case ID_L3Downlink_PROGRESS_DN: {
			sp->Data.fld_c_PROGRESS_DN = (c_PROGRESS_DN*)EDAlloc (sizeof (c_PROGRESS_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PROGRESS_DN == NULL)
			INIT_c_PROGRESS_DN (sp->Data.fld_c_PROGRESS_DN);
			break;
		}
		
		case ID_L3Downlink_CC_ESTABLISHMENT_DN: {
			sp->Data.fld_c_CC_ESTABLISHMENT_DN = (c_CC_ESTABLISHMENT_DN*)EDAlloc (sizeof (c_CC_ESTABLISHMENT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CC_ESTABLISHMENT_DN == NULL)
			INIT_c_CC_ESTABLISHMENT_DN (sp->Data.fld_c_CC_ESTABLISHMENT_DN);
			break;
		}
		
		case ID_L3Downlink_RELEASE_DN: {
			sp->Data.fld_c_RELEASE_DN = (c_RELEASE_DN*)EDAlloc (sizeof (c_RELEASE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RELEASE_DN == NULL)
			INIT_c_RELEASE_DN (sp->Data.fld_c_RELEASE_DN);
			break;
		}
		
		case ID_L3Downlink_RECALL_DN: {
			sp->Data.fld_c_RECALL_DN = (c_RECALL_DN*)EDAlloc (sizeof (c_RECALL_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RECALL_DN == NULL)
			INIT_c_RECALL_DN (sp->Data.fld_c_RECALL_DN);
			break;
		}
		
		case ID_L3Downlink_RELEASE_COMPLETE_DN: {
			sp->Data.fld_c_RELEASE_COMPLETE_DN = (c_RELEASE_COMPLETE_DN*)EDAlloc (sizeof (c_RELEASE_COMPLETE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RELEASE_COMPLETE_DN == NULL)
			INIT_c_RELEASE_COMPLETE_DN (sp->Data.fld_c_RELEASE_COMPLETE_DN);
			break;
		}
		
		case ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN: {
			sp->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN = (c_RETRIEVE_ACKNOWLEDGE_DN*)EDAlloc (sizeof (c_RETRIEVE_ACKNOWLEDGE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN == NULL)
			INIT_c_RETRIEVE_ACKNOWLEDGE_DN (sp->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN);
			break;
		}
		
		case ID_L3Downlink_RETRIEVE_REJECT_DN: {
			sp->Data.fld_c_RETRIEVE_REJECT_DN = (c_RETRIEVE_REJECT_DN*)EDAlloc (sizeof (c_RETRIEVE_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RETRIEVE_REJECT_DN == NULL)
			INIT_c_RETRIEVE_REJECT_DN (sp->Data.fld_c_RETRIEVE_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_SETUP_DN: {
			sp->Data.fld_c_SETUP_DN = (c_SETUP_DN*)EDAlloc (sizeof (c_SETUP_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SETUP_DN == NULL)
			INIT_c_SETUP_DN (sp->Data.fld_c_SETUP_DN);
			break;
		}
		
		case ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN: {
			sp->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN = (c_START_DTMF_ACKNOWLEDGE_DN*)EDAlloc (sizeof (c_START_DTMF_ACKNOWLEDGE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN == NULL)
			INIT_c_START_DTMF_ACKNOWLEDGE_DN (sp->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN);
			break;
		}
		
		case ID_L3Downlink_START_DTMF_REJECT_DN: {
			sp->Data.fld_c_START_DTMF_REJECT_DN = (c_START_DTMF_REJECT_DN*)EDAlloc (sizeof (c_START_DTMF_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_START_DTMF_REJECT_DN == NULL)
			INIT_c_START_DTMF_REJECT_DN (sp->Data.fld_c_START_DTMF_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_STATUS: {
			sp->Data.fld_c_STATUS = (c_STATUS*)EDAlloc (sizeof (c_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STATUS == NULL)
			INIT_c_STATUS (sp->Data.fld_c_STATUS);
			break;
		}
		
		case ID_L3Downlink_STATUS_ENQUIRY: {
			sp->Data.fld_c_STATUS_ENQUIRY = (c_STATUS_ENQUIRY*)EDAlloc (sizeof (c_STATUS_ENQUIRY)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STATUS_ENQUIRY == NULL)
			INIT_c_STATUS_ENQUIRY (sp->Data.fld_c_STATUS_ENQUIRY);
			break;
		}
		
		case ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN: {
			sp->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN = (c_STOP_DTMF_ACKNOWLEDGE_DN*)EDAlloc (sizeof (c_STOP_DTMF_ACKNOWLEDGE_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN == NULL)
			INIT_c_STOP_DTMF_ACKNOWLEDGE_DN (sp->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN);
			break;
		}
		
		case ID_L3Downlink_USER_INFORMATION: {
			sp->Data.fld_c_USER_INFORMATION = (c_USER_INFORMATION*)EDAlloc (sizeof (c_USER_INFORMATION)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_USER_INFORMATION == NULL)
			INIT_c_USER_INFORMATION (sp->Data.fld_c_USER_INFORMATION);
			break;
		}
		
		case ID_L3Downlink_ATTACH_REQUEST_UP: {
			sp->Data.fld_c_ATTACH_REQUEST_UP = (c_ATTACH_REQUEST_UP*)EDAlloc (sizeof (c_ATTACH_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ATTACH_REQUEST_UP == NULL)
			INIT_c_ATTACH_REQUEST_UP (sp->Data.fld_c_ATTACH_REQUEST_UP);
			break;
		}
		
		case ID_L3Downlink_ATTACH_ACCEPT_DN: {
			sp->Data.fld_c_ATTACH_ACCEPT_DN = (c_ATTACH_ACCEPT_DN*)EDAlloc (sizeof (c_ATTACH_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ATTACH_ACCEPT_DN == NULL)
			INIT_c_ATTACH_ACCEPT_DN (sp->Data.fld_c_ATTACH_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_ATTACH_REJECT_DN: {
			sp->Data.fld_c_ATTACH_REJECT_DN = (c_ATTACH_REJECT_DN*)EDAlloc (sizeof (c_ATTACH_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ATTACH_REJECT_DN == NULL)
			INIT_c_ATTACH_REJECT_DN (sp->Data.fld_c_ATTACH_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_DETACH_REQUEST_DN: {
			sp->Data.fld_c_DETACH_REQUEST_DN = (c_DETACH_REQUEST_DN*)EDAlloc (sizeof (c_DETACH_REQUEST_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DETACH_REQUEST_DN == NULL)
			INIT_c_DETACH_REQUEST_DN (sp->Data.fld_c_DETACH_REQUEST_DN);
			break;
		}
		
		case ID_L3Downlink_DETACH_ACCEPT_DN: {
			sp->Data.fld_c_DETACH_ACCEPT_DN = (c_DETACH_ACCEPT_DN*)EDAlloc (sizeof (c_DETACH_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DETACH_ACCEPT_DN == NULL)
			INIT_c_DETACH_ACCEPT_DN (sp->Data.fld_c_DETACH_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN: {
			sp->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN = (c_P_TMSI_REALLOCATION_COMMAND_DN*)EDAlloc (sizeof (c_P_TMSI_REALLOCATION_COMMAND_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN == NULL)
			INIT_c_P_TMSI_REALLOCATION_COMMAND_DN (sp->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN);
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN: {
			sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN = (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN*)EDAlloc (sizeof (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN == NULL)
			INIT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN);
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN: {
			sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN = (c_AUTHENTICATION_AND_CIPHERING_REJECT_DN*)EDAlloc (sizeof (c_AUTHENTICATION_AND_CIPHERING_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN == NULL)
			INIT_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_IDENTITY_REQUEST_B_DN: {
			sp->Data.fld_c_IDENTITY_REQUEST_B_DN = (c_IDENTITY_REQUEST_B_DN*)EDAlloc (sizeof (c_IDENTITY_REQUEST_B_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_IDENTITY_REQUEST_B_DN == NULL)
			INIT_c_IDENTITY_REQUEST_B_DN (sp->Data.fld_c_IDENTITY_REQUEST_B_DN);
			break;
		}
		
		case ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN: {
			sp->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN = (c_ROUTING_AREA_UPDATE_ACCEPT_DN*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN == NULL)
			INIT_c_ROUTING_AREA_UPDATE_ACCEPT_DN (sp->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN: {
			sp->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN = (c_ROUTING_AREA_UPDATE_REJECT_DN*)EDAlloc (sizeof (c_ROUTING_AREA_UPDATE_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN == NULL)
			INIT_c_ROUTING_AREA_UPDATE_REJECT_DN (sp->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN);
			break;
		}
		
		case ID_L3Downlink_GMM_STATUS: {
			sp->Data.fld_c_GMM_STATUS = (c_GMM_STATUS*)EDAlloc (sizeof (c_GMM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_GMM_STATUS == NULL)
			INIT_c_GMM_STATUS (sp->Data.fld_c_GMM_STATUS);
			break;
		}
		
		case ID_L3Downlink_GMM_INFORMATION_DN: {
			sp->Data.fld_c_GMM_INFORMATION_DN = (c_GMM_INFORMATION_DN*)EDAlloc (sizeof (c_GMM_INFORMATION_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_GMM_INFORMATION_DN == NULL)
			INIT_c_GMM_INFORMATION_DN (sp->Data.fld_c_GMM_INFORMATION_DN);
			break;
		}
		
		case ID_L3Downlink_SERVICE_ACCEPT_DN: {
			sp->Data.fld_c_SERVICE_ACCEPT_DN = (c_SERVICE_ACCEPT_DN*)EDAlloc (sizeof (c_SERVICE_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SERVICE_ACCEPT_DN == NULL)
			INIT_c_SERVICE_ACCEPT_DN (sp->Data.fld_c_SERVICE_ACCEPT_DN);
			break;
		}
		
		case ID_L3Downlink_SERVICE_REJECT_DN: {
			sp->Data.fld_c_SERVICE_REJECT_DN = (c_SERVICE_REJECT_DN*)EDAlloc (sizeof (c_SERVICE_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SERVICE_REJECT_DN == NULL)
			INIT_c_SERVICE_REJECT_DN (sp->Data.fld_c_SERVICE_REJECT_DN);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TL3Downlink_Data (TL3Downlink_Data* sp)
{
	switch (sp->Type) {
		case ID_L3Downlink_AUTHENTICATION_REJECT_DN: {
			FREE_c_AUTHENTICATION_REJECT_DN (sp->Data.fld_c_AUTHENTICATION_REJECT_DN);
	EDFree (sp->Data.fld_c_AUTHENTICATION_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_REQUEST_DN: {
			FREE_c_AUTHENTICATION_REQUEST_DN (sp->Data.fld_c_AUTHENTICATION_REQUEST_DN);
	EDFree (sp->Data.fld_c_AUTHENTICATION_REQUEST_DN );
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_ACCEPT_DN: {
			FREE_c_CM_SERVICE_ACCEPT_DN (sp->Data.fld_c_CM_SERVICE_ACCEPT_DN);
	EDFree (sp->Data.fld_c_CM_SERVICE_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_PROMPT_DN: {
			FREE_c_CM_SERVICE_PROMPT_DN (sp->Data.fld_c_CM_SERVICE_PROMPT_DN);
	EDFree (sp->Data.fld_c_CM_SERVICE_PROMPT_DN );
			break;
		}
		
		case ID_L3Downlink_CM_SERVICE_REJECT_DN: {
			FREE_c_CM_SERVICE_REJECT_DN (sp->Data.fld_c_CM_SERVICE_REJECT_DN);
	EDFree (sp->Data.fld_c_CM_SERVICE_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_ABORT_DN: {
			FREE_c_ABORT_DN (sp->Data.fld_c_ABORT_DN);
	EDFree (sp->Data.fld_c_ABORT_DN );
			break;
		}
		
		case ID_L3Downlink_IDENTITY_REQUEST_DN: {
			FREE_c_IDENTITY_REQUEST_DN (sp->Data.fld_c_IDENTITY_REQUEST_DN);
	EDFree (sp->Data.fld_c_IDENTITY_REQUEST_DN );
			break;
		}
		
		case ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN: {
			FREE_c_LOCATION_UPDATING_ACCEPT_DN (sp->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN);
	EDFree (sp->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_LOCATION_UPDATING_REJECT_DN: {
			FREE_c_LOCATION_UPDATING_REJECT_DN (sp->Data.fld_c_LOCATION_UPDATING_REJECT_DN);
	EDFree (sp->Data.fld_c_LOCATION_UPDATING_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_MM_INFORMATION_DN: {
			FREE_c_MM_INFORMATION_DN (sp->Data.fld_c_MM_INFORMATION_DN);
	EDFree (sp->Data.fld_c_MM_INFORMATION_DN );
			break;
		}
		
		case ID_L3Downlink_MM_STATUS: {
			FREE_c_MM_STATUS (sp->Data.fld_c_MM_STATUS);
	EDFree (sp->Data.fld_c_MM_STATUS );
			break;
		}
		
		case ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN: {
			FREE_c_TMSI_REALLOCATION_COMMAND_DN (sp->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN);
	EDFree (sp->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN );
			break;
		}
		
		case ID_L3Downlink_ALERTING_DN: {
			FREE_c_ALERTING_DN (sp->Data.fld_c_ALERTING_DN);
	EDFree (sp->Data.fld_c_ALERTING_DN );
			break;
		}
		
		case ID_L3Downlink_CALL_PROCEEDING_DN: {
			FREE_c_CALL_PROCEEDING_DN (sp->Data.fld_c_CALL_PROCEEDING_DN);
	EDFree (sp->Data.fld_c_CALL_PROCEEDING_DN );
			break;
		}
		
		case ID_L3Downlink_CONGESTION_CONTROL_DN: {
			FREE_c_CONGESTION_CONTROL_DN (sp->Data.fld_c_CONGESTION_CONTROL_DN);
	EDFree (sp->Data.fld_c_CONGESTION_CONTROL_DN );
			break;
		}
		
		case ID_L3Downlink_CONNECT_DN: {
			FREE_c_CONNECT_DN (sp->Data.fld_c_CONNECT_DN);
	EDFree (sp->Data.fld_c_CONNECT_DN );
			break;
		}
		
		case ID_L3Downlink_CONNECT_ACKNOWLEDGE: {
			FREE_c_CONNECT_ACKNOWLEDGE (sp->Data.fld_c_CONNECT_ACKNOWLEDGE);
	EDFree (sp->Data.fld_c_CONNECT_ACKNOWLEDGE );
			break;
		}
		
		case ID_L3Downlink_DISCONNECT_DN: {
			FREE_c_DISCONNECT_DN (sp->Data.fld_c_DISCONNECT_DN);
	EDFree (sp->Data.fld_c_DISCONNECT_DN );
			break;
		}
		
		case ID_L3Downlink_FACILITY_DN: {
			FREE_c_FACILITY_DN (sp->Data.fld_c_FACILITY_DN);
	EDFree (sp->Data.fld_c_FACILITY_DN );
			break;
		}
		
		case ID_L3Downlink_HOLD_ACKNOWLEDGE_DN: {
			FREE_c_HOLD_ACKNOWLEDGE_DN (sp->Data.fld_c_HOLD_ACKNOWLEDGE_DN);
	EDFree (sp->Data.fld_c_HOLD_ACKNOWLEDGE_DN );
			break;
		}
		
		case ID_L3Downlink_HOLD_REJECT_DN: {
			FREE_c_HOLD_REJECT_DN (sp->Data.fld_c_HOLD_REJECT_DN);
	EDFree (sp->Data.fld_c_HOLD_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_MODIFY: {
			FREE_c_MODIFY (sp->Data.fld_c_MODIFY);
	EDFree (sp->Data.fld_c_MODIFY );
			break;
		}
		
		case ID_L3Downlink_MODIFY_COMPLETE: {
			FREE_c_MODIFY_COMPLETE (sp->Data.fld_c_MODIFY_COMPLETE);
	EDFree (sp->Data.fld_c_MODIFY_COMPLETE );
			break;
		}
		
		case ID_L3Downlink_MODIFY_REJECT: {
			FREE_c_MODIFY_REJECT (sp->Data.fld_c_MODIFY_REJECT);
	EDFree (sp->Data.fld_c_MODIFY_REJECT );
			break;
		}
		
		case ID_L3Downlink_NOTIFY: {
			FREE_c_NOTIFY (sp->Data.fld_c_NOTIFY);
	EDFree (sp->Data.fld_c_NOTIFY );
			break;
		}
		
		case ID_L3Downlink_PROGRESS_DN: {
			FREE_c_PROGRESS_DN (sp->Data.fld_c_PROGRESS_DN);
	EDFree (sp->Data.fld_c_PROGRESS_DN );
			break;
		}
		
		case ID_L3Downlink_CC_ESTABLISHMENT_DN: {
			FREE_c_CC_ESTABLISHMENT_DN (sp->Data.fld_c_CC_ESTABLISHMENT_DN);
	EDFree (sp->Data.fld_c_CC_ESTABLISHMENT_DN );
			break;
		}
		
		case ID_L3Downlink_RELEASE_DN: {
			FREE_c_RELEASE_DN (sp->Data.fld_c_RELEASE_DN);
	EDFree (sp->Data.fld_c_RELEASE_DN );
			break;
		}
		
		case ID_L3Downlink_RECALL_DN: {
			FREE_c_RECALL_DN (sp->Data.fld_c_RECALL_DN);
	EDFree (sp->Data.fld_c_RECALL_DN );
			break;
		}
		
		case ID_L3Downlink_RELEASE_COMPLETE_DN: {
			FREE_c_RELEASE_COMPLETE_DN (sp->Data.fld_c_RELEASE_COMPLETE_DN);
	EDFree (sp->Data.fld_c_RELEASE_COMPLETE_DN );
			break;
		}
		
		case ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN: {
			FREE_c_RETRIEVE_ACKNOWLEDGE_DN (sp->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN);
	EDFree (sp->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN );
			break;
		}
		
		case ID_L3Downlink_RETRIEVE_REJECT_DN: {
			FREE_c_RETRIEVE_REJECT_DN (sp->Data.fld_c_RETRIEVE_REJECT_DN);
	EDFree (sp->Data.fld_c_RETRIEVE_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_SETUP_DN: {
			FREE_c_SETUP_DN (sp->Data.fld_c_SETUP_DN);
	EDFree (sp->Data.fld_c_SETUP_DN );
			break;
		}
		
		case ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN: {
			FREE_c_START_DTMF_ACKNOWLEDGE_DN (sp->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN);
	EDFree (sp->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN );
			break;
		}
		
		case ID_L3Downlink_START_DTMF_REJECT_DN: {
			FREE_c_START_DTMF_REJECT_DN (sp->Data.fld_c_START_DTMF_REJECT_DN);
	EDFree (sp->Data.fld_c_START_DTMF_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_STATUS: {
			FREE_c_STATUS (sp->Data.fld_c_STATUS);
	EDFree (sp->Data.fld_c_STATUS );
			break;
		}
		
		case ID_L3Downlink_STATUS_ENQUIRY: {
			FREE_c_STATUS_ENQUIRY (sp->Data.fld_c_STATUS_ENQUIRY);
	EDFree (sp->Data.fld_c_STATUS_ENQUIRY );
			break;
		}
		
		case ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN: {
			FREE_c_STOP_DTMF_ACKNOWLEDGE_DN (sp->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN);
	EDFree (sp->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN );
			break;
		}
		
		case ID_L3Downlink_USER_INFORMATION: {
			FREE_c_USER_INFORMATION (sp->Data.fld_c_USER_INFORMATION);
	EDFree (sp->Data.fld_c_USER_INFORMATION );
			break;
		}
		
		case ID_L3Downlink_ATTACH_REQUEST_UP: {
			FREE_c_ATTACH_REQUEST_UP (sp->Data.fld_c_ATTACH_REQUEST_UP);
	EDFree (sp->Data.fld_c_ATTACH_REQUEST_UP );
			break;
		}
		
		case ID_L3Downlink_ATTACH_ACCEPT_DN: {
			FREE_c_ATTACH_ACCEPT_DN (sp->Data.fld_c_ATTACH_ACCEPT_DN);
	EDFree (sp->Data.fld_c_ATTACH_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_ATTACH_REJECT_DN: {
			FREE_c_ATTACH_REJECT_DN (sp->Data.fld_c_ATTACH_REJECT_DN);
	EDFree (sp->Data.fld_c_ATTACH_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_DETACH_REQUEST_DN: {
			FREE_c_DETACH_REQUEST_DN (sp->Data.fld_c_DETACH_REQUEST_DN);
	EDFree (sp->Data.fld_c_DETACH_REQUEST_DN );
			break;
		}
		
		case ID_L3Downlink_DETACH_ACCEPT_DN: {
			FREE_c_DETACH_ACCEPT_DN (sp->Data.fld_c_DETACH_ACCEPT_DN);
	EDFree (sp->Data.fld_c_DETACH_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN: {
			FREE_c_P_TMSI_REALLOCATION_COMMAND_DN (sp->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN);
	EDFree (sp->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN );
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN: {
			FREE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN);
	EDFree (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN );
			break;
		}
		
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN: {
			FREE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN);
	EDFree (sp->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_IDENTITY_REQUEST_B_DN: {
			FREE_c_IDENTITY_REQUEST_B_DN (sp->Data.fld_c_IDENTITY_REQUEST_B_DN);
	EDFree (sp->Data.fld_c_IDENTITY_REQUEST_B_DN );
			break;
		}
		
		case ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN: {
			FREE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (sp->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN);
	EDFree (sp->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN: {
			FREE_c_ROUTING_AREA_UPDATE_REJECT_DN (sp->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN);
	EDFree (sp->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN );
			break;
		}
		
		case ID_L3Downlink_GMM_STATUS: {
			FREE_c_GMM_STATUS (sp->Data.fld_c_GMM_STATUS);
	EDFree (sp->Data.fld_c_GMM_STATUS );
			break;
		}
		
		case ID_L3Downlink_GMM_INFORMATION_DN: {
			FREE_c_GMM_INFORMATION_DN (sp->Data.fld_c_GMM_INFORMATION_DN);
	EDFree (sp->Data.fld_c_GMM_INFORMATION_DN );
			break;
		}
		
		case ID_L3Downlink_SERVICE_ACCEPT_DN: {
			FREE_c_SERVICE_ACCEPT_DN (sp->Data.fld_c_SERVICE_ACCEPT_DN);
	EDFree (sp->Data.fld_c_SERVICE_ACCEPT_DN );
			break;
		}
		
		case ID_L3Downlink_SERVICE_REJECT_DN: {
			FREE_c_SERVICE_REJECT_DN (sp->Data.fld_c_SERVICE_REJECT_DN);
	EDFree (sp->Data.fld_c_SERVICE_REJECT_DN );
			break;
		}
		
		default:;
	}

	sp->Type = ID_L3Downlink_Unrecognized;
}

int SETPRESENT_TXTIDUplink_Data (TXTIDUplink_Data* sp, TXTIDUplink_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TXTIDUplink_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP: {
			sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP = (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP == NULL)
			INIT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		
		case ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP: {
			sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP == NULL)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		
		case ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP: {
			sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP = (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP*)EDAlloc (sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP == NULL)
			INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP);
			break;
		}
		
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP: {
			sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP = (c_MODIFY_PDP_CONTEXT_REQUEST_UP*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP == NULL)
			INIT_c_MODIFY_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP: {
			sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP = (c_MODIFY_PDP_CONTEXT_ACCEPT_UP*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_UP)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP == NULL)
			INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP);
			break;
		}
		
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST = (c_DEACTIVATE_PDP_CONTEXT_REQUEST*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_REQUEST)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST == NULL)
			INIT_c_DEACTIVATE_PDP_CONTEXT_REQUEST (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			break;
		}
		
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT = (c_DEACTIVATE_PDP_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_ACCEPT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT == NULL)
			INIT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			break;
		}
		
		case ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT: {
			sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT = (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT*)EDAlloc (sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT == NULL)
			INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT);
			break;
		}
		
		case ID_XTIDUplink_SM_STATUS: {
			sp->Data.fld_c_SM_STATUS = (c_SM_STATUS*)EDAlloc (sizeof (c_SM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SM_STATUS == NULL)
			INIT_c_SM_STATUS (sp->Data.fld_c_SM_STATUS);
			break;
		}
		
		case ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST: {
			sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST = (c_ACTIVATE_MBMS_CONTEXT_REQUEST*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_REQUEST)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST == NULL)
			INIT_c_ACTIVATE_MBMS_CONTEXT_REQUEST (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST);
			break;
		}
		
		case ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT: {
			sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT = (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT*)EDAlloc (sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT == NULL)
			INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TXTIDUplink_Data (TXTIDUplink_Data* sp)
{
	switch (sp->Type) {
		case ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP: {
			FREE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP);
	EDFree (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP );
			break;
		}
		
		case ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP: {
			FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP);
	EDFree (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP );
			break;
		}
		
		case ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP: {
			FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP);
	EDFree (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP );
			break;
		}
		
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP: {
			FREE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP);
	EDFree (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP );
			break;
		}
		
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP: {
			FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP);
	EDFree (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP );
			break;
		}
		
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			FREE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
	EDFree (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST );
			break;
		}
		
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			FREE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
	EDFree (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT );
			break;
		}
		
		case ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT: {
			FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT);
	EDFree (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT );
			break;
		}
		
		case ID_XTIDUplink_SM_STATUS: {
			FREE_c_SM_STATUS (sp->Data.fld_c_SM_STATUS);
	EDFree (sp->Data.fld_c_SM_STATUS );
			break;
		}
		
		case ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST: {
			FREE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST);
	EDFree (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST );
			break;
		}
		
		case ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT: {
			FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT);
	EDFree (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT );
			break;
		}
		
		default:;
	}

	sp->Type = ID_XTIDUplink_Unrecognized;
}

int SETPRESENT_TXTIDDownlink_Data (TXTIDDownlink_Data* sp, TXTIDDownlink_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TXTIDDownlink_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN: {
			sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN = (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN == NULL)
			INIT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN: {
			sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN = (c_ACTIVATE_PDP_CONTEXT_REJECT_DN*)EDAlloc (sizeof (c_ACTIVATE_PDP_CONTEXT_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN == NULL)
			INIT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN);
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN: {
			sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN == NULL)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN: {
			sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN = (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN*)EDAlloc (sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN == NULL)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN);
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN: {
			sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN = (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN*)EDAlloc (sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN == NULL)
			INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN);
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN: {
			sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN = (c_MODIFY_PDP_CONTEXT_REQUEST_DN*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN == NULL)
			INIT_c_MODIFY_PDP_CONTEXT_REQUEST_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN);
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN: {
			sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN = (c_MODIFY_PDP_CONTEXT_ACCEPT_DN*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN == NULL)
			INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN: {
			sp->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN = (c_MODIFY_PDP_CONTEXT_REJECT_DN*)EDAlloc (sizeof (c_MODIFY_PDP_CONTEXT_REJECT_DN)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN == NULL)
			INIT_c_MODIFY_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN);
			break;
		}
		
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST = (c_DEACTIVATE_PDP_CONTEXT_REQUEST*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_REQUEST)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST == NULL)
			INIT_c_DEACTIVATE_PDP_CONTEXT_REQUEST (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			break;
		}
		
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT = (c_DEACTIVATE_PDP_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_DEACTIVATE_PDP_CONTEXT_ACCEPT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT == NULL)
			INIT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION: {
			sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION = (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION*)EDAlloc (sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION == NULL)
			INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION);
			break;
		}
		
		case ID_XTIDDownlink_NOTIFICATION: {
			sp->Data.fld_c_NOTIFICATION = (c_NOTIFICATION*)EDAlloc (sizeof (c_NOTIFICATION)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_NOTIFICATION == NULL)
			INIT_c_NOTIFICATION (sp->Data.fld_c_NOTIFICATION);
			break;
		}
		
		case ID_XTIDDownlink_SM_STATUS: {
			sp->Data.fld_c_SM_STATUS = (c_SM_STATUS*)EDAlloc (sizeof (c_SM_STATUS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SM_STATUS == NULL)
			INIT_c_SM_STATUS (sp->Data.fld_c_SM_STATUS);
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT: {
			sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT = (c_ACTIVATE_MBMS_CONTEXT_ACCEPT*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_ACCEPT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT == NULL)
			INIT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT);
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT: {
			sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT = (c_ACTIVATE_MBMS_CONTEXT_REJECT*)EDAlloc (sizeof (c_ACTIVATE_MBMS_CONTEXT_REJECT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT == NULL)
			INIT_c_ACTIVATE_MBMS_CONTEXT_REJECT (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT);
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION: {
			sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION = (c_REQUEST_MBMS_CONTEXT_ACTIVATION*)EDAlloc (sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION == NULL)
			INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TXTIDDownlink_Data (TXTIDDownlink_Data* sp)
{
	switch (sp->Type) {
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN: {
			FREE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN);
	EDFree (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN );
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN: {
			FREE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN);
	EDFree (sp->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN );
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN: {
			FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN);
	EDFree (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN );
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN: {
			FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN);
	EDFree (sp->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN );
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN: {
			FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN);
	EDFree (sp->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN );
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN: {
			FREE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN);
	EDFree (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN );
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN: {
			FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN);
	EDFree (sp->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN );
			break;
		}
		
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN: {
			FREE_c_MODIFY_PDP_CONTEXT_REJECT_DN (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN);
	EDFree (sp->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN );
			break;
		}
		
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			FREE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
	EDFree (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST );
			break;
		}
		
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			FREE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
	EDFree (sp->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT );
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION: {
			FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION);
	EDFree (sp->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION );
			break;
		}
		
		case ID_XTIDDownlink_NOTIFICATION: {
			FREE_c_NOTIFICATION (sp->Data.fld_c_NOTIFICATION);
	EDFree (sp->Data.fld_c_NOTIFICATION );
			break;
		}
		
		case ID_XTIDDownlink_SM_STATUS: {
			FREE_c_SM_STATUS (sp->Data.fld_c_SM_STATUS);
	EDFree (sp->Data.fld_c_SM_STATUS );
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT: {
			FREE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT);
	EDFree (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT );
			break;
		}
		
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT: {
			FREE_c_ACTIVATE_MBMS_CONTEXT_REJECT (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT);
	EDFree (sp->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT );
			break;
		}
		
		case ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION: {
			FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION);
	EDFree (sp->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION );
			break;
		}
		
		default:;
	}

	sp->Type = ID_XTIDDownlink_Unrecognized;
}

#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_L3Uplink (const char* buffer, TL3Uplink_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*/ = ((((unsigned char)buffer [0]) << 8) | ((unsigned char)buffer [1]))& 0x0FFF/*2*/;/*3*/
		data->ProtocolDiscriminator = (int)(((unsigned char)buffer [0]) & 0x0f);
		data->SkipIndicator = (int)((((unsigned char)buffer [0]) & 0xf0) >> 4);
	data->MessageType = (int)((unsigned char)buffer [1]);
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF3F) {
			/* Detect signal AUTHENTICATION_RESPONSE_UP */
		case 0x0514: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_AUTHENTICATION_RESPONSE_UP), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_RESPONSE_UP (data->Data.fld_c_AUTHENTICATION_RESPONSE_UP);
			retLen = DECODE_c_AUTHENTICATION_RESPONSE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_RESPONSE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_FAILURE_UP */
		case 0x051C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_AUTHENTICATION_FAILURE_UP), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_FAILURE_UP (data->Data.fld_c_AUTHENTICATION_FAILURE_UP);
			retLen = DECODE_c_AUTHENTICATION_FAILURE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_FAILURE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_RE_ESTABLISHMENT_REQUEST_UP */
		case 0x0528: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_CM_RE_ESTABLISHMENT_REQUEST_UP (data->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP);
			retLen = DECODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (buffer, 0, data->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_SERVICE_ABORT_UP */
		case 0x0523: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CM_SERVICE_ABORT_UP), != ED_NO_ERRORS)
			INIT_c_CM_SERVICE_ABORT_UP (data->Data.fld_c_CM_SERVICE_ABORT_UP);
			retLen = DECODE_c_CM_SERVICE_ABORT_UP (buffer, 0, data->Data.fld_c_CM_SERVICE_ABORT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_SERVICE_REQUEST_UP */
		case 0x0524: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CM_SERVICE_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_CM_SERVICE_REQUEST_UP (data->Data.fld_c_CM_SERVICE_REQUEST_UP);
			retLen = DECODE_c_CM_SERVICE_REQUEST_UP (buffer, 0, data->Data.fld_c_CM_SERVICE_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal IDENTITY_RESPONSE_UP */
		case 0x0519: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_IDENTITY_RESPONSE_UP), != ED_NO_ERRORS)
			INIT_c_IDENTITY_RESPONSE_UP (data->Data.fld_c_IDENTITY_RESPONSE_UP);
			retLen = DECODE_c_IDENTITY_RESPONSE_UP (buffer, 0, data->Data.fld_c_IDENTITY_RESPONSE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal IMSI_DETACH_INDICATION_UP */
		case 0x0501: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_IMSI_DETACH_INDICATION_UP), != ED_NO_ERRORS)
			INIT_c_IMSI_DETACH_INDICATION_UP (data->Data.fld_c_IMSI_DETACH_INDICATION_UP);
			retLen = DECODE_c_IMSI_DETACH_INDICATION_UP (buffer, 0, data->Data.fld_c_IMSI_DETACH_INDICATION_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal LOCATION_UPDATING_REQUEST_UP */
		case 0x0508: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_LOCATION_UPDATING_REQUEST_UP (data->Data.fld_c_LOCATION_UPDATING_REQUEST_UP);
			retLen = DECODE_c_LOCATION_UPDATING_REQUEST_UP (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal MM_STATUS */
		case 0x0531: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_MM_STATUS), != ED_NO_ERRORS)
			INIT_c_MM_STATUS (data->Data.fld_c_MM_STATUS);
			retLen = DECODE_c_MM_STATUS (buffer, 0, data->Data.fld_c_MM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal TMSI_REALLOCATION_COMPLETE_UP */
		case 0x051B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP), != ED_NO_ERRORS)
			INIT_c_TMSI_REALLOCATION_COMPLETE_UP (data->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP);
			retLen = DECODE_c_TMSI_REALLOCATION_COMPLETE_UP (buffer, 0, data->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal MM_NULL_UP */
		case 0x0530: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_MM_NULL_UP), != ED_NO_ERRORS)
			INIT_c_MM_NULL_UP (data->Data.fld_c_MM_NULL_UP);
			retLen = DECODE_c_MM_NULL_UP (buffer, 0, data->Data.fld_c_MM_NULL_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ALERTING_UP */
		case 0x0301: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_ALERTING_UP), != ED_NO_ERRORS)
			INIT_c_ALERTING_UP (data->Data.fld_c_ALERTING_UP);
			retLen = DECODE_c_ALERTING_UP (buffer, 0, data->Data.fld_c_ALERTING_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CALL_CONFIRMED_UP */
		case 0x0308: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CALL_CONFIRMED_UP), != ED_NO_ERRORS)
			INIT_c_CALL_CONFIRMED_UP (data->Data.fld_c_CALL_CONFIRMED_UP);
			retLen = DECODE_c_CALL_CONFIRMED_UP (buffer, 0, data->Data.fld_c_CALL_CONFIRMED_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CONNECT_UP */
		case 0x0307: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CONNECT_UP), != ED_NO_ERRORS)
			INIT_c_CONNECT_UP (data->Data.fld_c_CONNECT_UP);
			retLen = DECODE_c_CONNECT_UP (buffer, 0, data->Data.fld_c_CONNECT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal CONNECT_ACKNOWLEDGE */
		case 0x030F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CONNECT_ACKNOWLEDGE), != ED_NO_ERRORS)
			INIT_c_CONNECT_ACKNOWLEDGE (data->Data.fld_c_CONNECT_ACKNOWLEDGE);
			retLen = DECODE_c_CONNECT_ACKNOWLEDGE (buffer, 0, data->Data.fld_c_CONNECT_ACKNOWLEDGE, bitLen);
		
			return retLen;
		}
		/* Detect signal DISCONNECT_UP */
		case 0x0325: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_DISCONNECT_UP), != ED_NO_ERRORS)
			INIT_c_DISCONNECT_UP (data->Data.fld_c_DISCONNECT_UP);
			retLen = DECODE_c_DISCONNECT_UP (buffer, 0, data->Data.fld_c_DISCONNECT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal EMERGENCY_SETUP_UP */
		case 0x030E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_EMERGENCY_SETUP_UP), != ED_NO_ERRORS)
			INIT_c_EMERGENCY_SETUP_UP (data->Data.fld_c_EMERGENCY_SETUP_UP);
			retLen = DECODE_c_EMERGENCY_SETUP_UP (buffer, 0, data->Data.fld_c_EMERGENCY_SETUP_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal FACILITY_UP */
		case 0x033A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_FACILITY_UP), != ED_NO_ERRORS)
			INIT_c_FACILITY_UP (data->Data.fld_c_FACILITY_UP);
			retLen = DECODE_c_FACILITY_UP (buffer, 0, data->Data.fld_c_FACILITY_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal HOLD_UP */
		case 0x0318: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_HOLD_UP), != ED_NO_ERRORS)
			INIT_c_HOLD_UP (data->Data.fld_c_HOLD_UP);
			retLen = DECODE_c_HOLD_UP (buffer, 0, data->Data.fld_c_HOLD_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY */
		case 0x0317: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_MODIFY), != ED_NO_ERRORS)
			INIT_c_MODIFY (data->Data.fld_c_MODIFY);
			retLen = DECODE_c_MODIFY (buffer, 0, data->Data.fld_c_MODIFY, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_COMPLETE */
		case 0x031F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_MODIFY_COMPLETE), != ED_NO_ERRORS)
			INIT_c_MODIFY_COMPLETE (data->Data.fld_c_MODIFY_COMPLETE);
			retLen = DECODE_c_MODIFY_COMPLETE (buffer, 0, data->Data.fld_c_MODIFY_COMPLETE, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_REJECT */
		case 0x0313: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_MODIFY_REJECT), != ED_NO_ERRORS)
			INIT_c_MODIFY_REJECT (data->Data.fld_c_MODIFY_REJECT);
			retLen = DECODE_c_MODIFY_REJECT (buffer, 0, data->Data.fld_c_MODIFY_REJECT, bitLen);
		
			return retLen;
		}
		/* Detect signal NOTIFY */
		case 0x033E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_NOTIFY), != ED_NO_ERRORS)
			INIT_c_NOTIFY (data->Data.fld_c_NOTIFY);
			retLen = DECODE_c_NOTIFY (buffer, 0, data->Data.fld_c_NOTIFY, bitLen);
		
			return retLen;
		}
		/* Detect signal CC_ESTABLISHMENT_CONFIRMED_UP */
		case 0x0306: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP), != ED_NO_ERRORS)
			INIT_c_CC_ESTABLISHMENT_CONFIRMED_UP (data->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP);
			retLen = DECODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (buffer, 0, data->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal RELEASE_UP */
		case 0x032D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_RELEASE_UP), != ED_NO_ERRORS)
			INIT_c_RELEASE_UP (data->Data.fld_c_RELEASE_UP);
			retLen = DECODE_c_RELEASE_UP (buffer, 0, data->Data.fld_c_RELEASE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal RELEASE_COMPLETE_UP */
		case 0x032A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_RELEASE_COMPLETE_UP), != ED_NO_ERRORS)
			INIT_c_RELEASE_COMPLETE_UP (data->Data.fld_c_RELEASE_COMPLETE_UP);
			retLen = DECODE_c_RELEASE_COMPLETE_UP (buffer, 0, data->Data.fld_c_RELEASE_COMPLETE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal RETRIEVE_UP */
		case 0x031C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_RETRIEVE_UP), != ED_NO_ERRORS)
			INIT_c_RETRIEVE_UP (data->Data.fld_c_RETRIEVE_UP);
			retLen = DECODE_c_RETRIEVE_UP (buffer, 0, data->Data.fld_c_RETRIEVE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal SETUP_UP */
		case 0x0305: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_SETUP_UP), != ED_NO_ERRORS)
			INIT_c_SETUP_UP (data->Data.fld_c_SETUP_UP);
			retLen = DECODE_c_SETUP_UP (buffer, 0, data->Data.fld_c_SETUP_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal START_CC_UP */
		case 0x0309: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_START_CC_UP), != ED_NO_ERRORS)
			INIT_c_START_CC_UP (data->Data.fld_c_START_CC_UP);
			retLen = DECODE_c_START_CC_UP (buffer, 0, data->Data.fld_c_START_CC_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal START_DTMF_UP */
		case 0x0335: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_START_DTMF_UP), != ED_NO_ERRORS)
			INIT_c_START_DTMF_UP (data->Data.fld_c_START_DTMF_UP);
			retLen = DECODE_c_START_DTMF_UP (buffer, 0, data->Data.fld_c_START_DTMF_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal STATUS */
		case 0x033D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_STATUS), != ED_NO_ERRORS)
			INIT_c_STATUS (data->Data.fld_c_STATUS);
			retLen = DECODE_c_STATUS (buffer, 0, data->Data.fld_c_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal STATUS_ENQUIRY */
		case 0x0334: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_STATUS_ENQUIRY), != ED_NO_ERRORS)
			INIT_c_STATUS_ENQUIRY (data->Data.fld_c_STATUS_ENQUIRY);
			retLen = DECODE_c_STATUS_ENQUIRY (buffer, 0, data->Data.fld_c_STATUS_ENQUIRY, bitLen);
		
			return retLen;
		}
		/* Detect signal STOP_DTMF_UP */
		case 0x0331: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_STOP_DTMF_UP), != ED_NO_ERRORS)
			INIT_c_STOP_DTMF_UP (data->Data.fld_c_STOP_DTMF_UP);
			retLen = DECODE_c_STOP_DTMF_UP (buffer, 0, data->Data.fld_c_STOP_DTMF_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal USER_INFORMATION */
		case 0x0310: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_USER_INFORMATION), != ED_NO_ERRORS)
			INIT_c_USER_INFORMATION (data->Data.fld_c_USER_INFORMATION);
			retLen = DECODE_c_USER_INFORMATION (buffer, 0, data->Data.fld_c_USER_INFORMATION, bitLen);
		
			return retLen;
		}

		default:;
	}
	switch (key) {
			/* Detect signal ATTACH_REQUEST_UP */
		case 0x0801: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_ATTACH_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_ATTACH_REQUEST_UP (data->Data.fld_c_ATTACH_REQUEST_UP);
			retLen = DECODE_c_ATTACH_REQUEST_UP (buffer, 0, data->Data.fld_c_ATTACH_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ATTACH_COMPLETE_UP */
		case 0x0803: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_ATTACH_COMPLETE_UP), != ED_NO_ERRORS)
			INIT_c_ATTACH_COMPLETE_UP (data->Data.fld_c_ATTACH_COMPLETE_UP);
			retLen = DECODE_c_ATTACH_COMPLETE_UP (buffer, 0, data->Data.fld_c_ATTACH_COMPLETE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal DETACH_REQUEST_UP */
		case 0x0805: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_DETACH_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_DETACH_REQUEST_UP (data->Data.fld_c_DETACH_REQUEST_UP);
			retLen = DECODE_c_DETACH_REQUEST_UP (buffer, 0, data->Data.fld_c_DETACH_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal DETACH_ACCEPT_UP */
		case 0x0806: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_DETACH_ACCEPT_UP), != ED_NO_ERRORS)
			INIT_c_DETACH_ACCEPT_UP (data->Data.fld_c_DETACH_ACCEPT_UP);
			retLen = DECODE_c_DETACH_ACCEPT_UP (buffer, 0, data->Data.fld_c_DETACH_ACCEPT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal P_TMSI_REALLOCATION_COMPLETE_UP */
		case 0x0811: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP), != ED_NO_ERRORS)
			INIT_c_P_TMSI_REALLOCATION_COMPLETE_UP (data->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP);
			retLen = DECODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (buffer, 0, data->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_AND_CIPHERING_RESPONSE_UP */
		case 0x0813: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP);
			retLen = DECODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_AND_CIPHERING_FAILURE_UP */
		case 0x081C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP);
			retLen = DECODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal IDENTITY_RESPONSE_B_UP */
		case 0x0816: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_IDENTITY_RESPONSE_B_UP), != ED_NO_ERRORS)
			INIT_c_IDENTITY_RESPONSE_B_UP (data->Data.fld_c_IDENTITY_RESPONSE_B_UP);
			retLen = DECODE_c_IDENTITY_RESPONSE_B_UP (buffer, 0, data->Data.fld_c_IDENTITY_RESPONSE_B_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ROUTING_AREA_UPDATE_REQUEST_UP */
		case 0x0808: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_ROUTING_AREA_UPDATE_REQUEST_UP (data->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP);
			retLen = DECODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ROUTING_AREA_UPDATE_COMPLETE_UP */
		case 0x080A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP), != ED_NO_ERRORS)
			INIT_c_ROUTING_AREA_UPDATE_COMPLETE_UP (data->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP);
			retLen = DECODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal GMM_STATUS */
		case 0x0820: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_GMM_STATUS), != ED_NO_ERRORS)
			INIT_c_GMM_STATUS (data->Data.fld_c_GMM_STATUS);
			retLen = DECODE_c_GMM_STATUS (buffer, 0, data->Data.fld_c_GMM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal SERVICE_REQUEST_UP */
		case 0x080C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Uplink_Data (data, ID_L3Uplink_SERVICE_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_SERVICE_REQUEST_UP (data->Data.fld_c_SERVICE_REQUEST_UP);
			retLen = DECODE_c_SERVICE_REQUEST_UP (buffer, 0, data->Data.fld_c_SERVICE_REQUEST_UP, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_L3Uplink_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_L3Uplink (const char* buffer, int len, TL3Uplink_Data* data)
	{
		if (SetDecode_L3Uplink (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_L3Uplink (char* buffer, ED_EXLONG bitOffset, TL3Uplink_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_L3Uplink_AUTHENTICATION_RESPONSE_UP: {
			retLen = ENCODE_c_AUTHENTICATION_RESPONSE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_RESPONSE_UP);
			break;
		}
		case ID_L3Uplink_AUTHENTICATION_FAILURE_UP: {
			retLen = ENCODE_c_AUTHENTICATION_FAILURE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_FAILURE_UP);
			break;
		}
		case ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP: {
			retLen = ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (buffer, 0, data->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_CM_SERVICE_ABORT_UP: {
			retLen = ENCODE_c_CM_SERVICE_ABORT_UP (buffer, 0, data->Data.fld_c_CM_SERVICE_ABORT_UP);
			break;
		}
		case ID_L3Uplink_CM_SERVICE_REQUEST_UP: {
			retLen = ENCODE_c_CM_SERVICE_REQUEST_UP (buffer, 0, data->Data.fld_c_CM_SERVICE_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_IDENTITY_RESPONSE_UP: {
			retLen = ENCODE_c_IDENTITY_RESPONSE_UP (buffer, 0, data->Data.fld_c_IDENTITY_RESPONSE_UP);
			break;
		}
		case ID_L3Uplink_IMSI_DETACH_INDICATION_UP: {
			retLen = ENCODE_c_IMSI_DETACH_INDICATION_UP (buffer, 0, data->Data.fld_c_IMSI_DETACH_INDICATION_UP);
			break;
		}
		case ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP: {
			retLen = ENCODE_c_LOCATION_UPDATING_REQUEST_UP (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_MM_STATUS: {
			retLen = ENCODE_c_MM_STATUS (buffer, 0, data->Data.fld_c_MM_STATUS);
			break;
		}
		case ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP: {
			retLen = ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (buffer, 0, data->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP);
			break;
		}
		case ID_L3Uplink_MM_NULL_UP: {
			retLen = ENCODE_c_MM_NULL_UP (buffer, 0, data->Data.fld_c_MM_NULL_UP);
			break;
		}
		case ID_L3Uplink_ALERTING_UP: {
			retLen = ENCODE_c_ALERTING_UP (buffer, 0, data->Data.fld_c_ALERTING_UP);
			break;
		}
		case ID_L3Uplink_CALL_CONFIRMED_UP: {
			retLen = ENCODE_c_CALL_CONFIRMED_UP (buffer, 0, data->Data.fld_c_CALL_CONFIRMED_UP);
			break;
		}
		case ID_L3Uplink_CONNECT_UP: {
			retLen = ENCODE_c_CONNECT_UP (buffer, 0, data->Data.fld_c_CONNECT_UP);
			break;
		}
		case ID_L3Uplink_CONNECT_ACKNOWLEDGE: {
			retLen = ENCODE_c_CONNECT_ACKNOWLEDGE (buffer, 0, data->Data.fld_c_CONNECT_ACKNOWLEDGE);
			break;
		}
		case ID_L3Uplink_DISCONNECT_UP: {
			retLen = ENCODE_c_DISCONNECT_UP (buffer, 0, data->Data.fld_c_DISCONNECT_UP);
			break;
		}
		case ID_L3Uplink_EMERGENCY_SETUP_UP: {
			retLen = ENCODE_c_EMERGENCY_SETUP_UP (buffer, 0, data->Data.fld_c_EMERGENCY_SETUP_UP);
			break;
		}
		case ID_L3Uplink_FACILITY_UP: {
			retLen = ENCODE_c_FACILITY_UP (buffer, 0, data->Data.fld_c_FACILITY_UP);
			break;
		}
		case ID_L3Uplink_HOLD_UP: {
			retLen = ENCODE_c_HOLD_UP (buffer, 0, data->Data.fld_c_HOLD_UP);
			break;
		}
		case ID_L3Uplink_MODIFY: {
			retLen = ENCODE_c_MODIFY (buffer, 0, data->Data.fld_c_MODIFY);
			break;
		}
		case ID_L3Uplink_MODIFY_COMPLETE: {
			retLen = ENCODE_c_MODIFY_COMPLETE (buffer, 0, data->Data.fld_c_MODIFY_COMPLETE);
			break;
		}
		case ID_L3Uplink_MODIFY_REJECT: {
			retLen = ENCODE_c_MODIFY_REJECT (buffer, 0, data->Data.fld_c_MODIFY_REJECT);
			break;
		}
		case ID_L3Uplink_NOTIFY: {
			retLen = ENCODE_c_NOTIFY (buffer, 0, data->Data.fld_c_NOTIFY);
			break;
		}
		case ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP: {
			retLen = ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (buffer, 0, data->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP);
			break;
		}
		case ID_L3Uplink_RELEASE_UP: {
			retLen = ENCODE_c_RELEASE_UP (buffer, 0, data->Data.fld_c_RELEASE_UP);
			break;
		}
		case ID_L3Uplink_RELEASE_COMPLETE_UP: {
			retLen = ENCODE_c_RELEASE_COMPLETE_UP (buffer, 0, data->Data.fld_c_RELEASE_COMPLETE_UP);
			break;
		}
		case ID_L3Uplink_RETRIEVE_UP: {
			retLen = ENCODE_c_RETRIEVE_UP (buffer, 0, data->Data.fld_c_RETRIEVE_UP);
			break;
		}
		case ID_L3Uplink_SETUP_UP: {
			retLen = ENCODE_c_SETUP_UP (buffer, 0, data->Data.fld_c_SETUP_UP);
			break;
		}
		case ID_L3Uplink_START_CC_UP: {
			retLen = ENCODE_c_START_CC_UP (buffer, 0, data->Data.fld_c_START_CC_UP);
			break;
		}
		case ID_L3Uplink_START_DTMF_UP: {
			retLen = ENCODE_c_START_DTMF_UP (buffer, 0, data->Data.fld_c_START_DTMF_UP);
			break;
		}
		case ID_L3Uplink_STATUS: {
			retLen = ENCODE_c_STATUS (buffer, 0, data->Data.fld_c_STATUS);
			break;
		}
		case ID_L3Uplink_STATUS_ENQUIRY: {
			retLen = ENCODE_c_STATUS_ENQUIRY (buffer, 0, data->Data.fld_c_STATUS_ENQUIRY);
			break;
		}
		case ID_L3Uplink_STOP_DTMF_UP: {
			retLen = ENCODE_c_STOP_DTMF_UP (buffer, 0, data->Data.fld_c_STOP_DTMF_UP);
			break;
		}
		case ID_L3Uplink_USER_INFORMATION: {
			retLen = ENCODE_c_USER_INFORMATION (buffer, 0, data->Data.fld_c_USER_INFORMATION);
			break;
		}
		case ID_L3Uplink_ATTACH_REQUEST_UP: {
			retLen = ENCODE_c_ATTACH_REQUEST_UP (buffer, 0, data->Data.fld_c_ATTACH_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_ATTACH_COMPLETE_UP: {
			retLen = ENCODE_c_ATTACH_COMPLETE_UP (buffer, 0, data->Data.fld_c_ATTACH_COMPLETE_UP);
			break;
		}
		case ID_L3Uplink_DETACH_REQUEST_UP: {
			retLen = ENCODE_c_DETACH_REQUEST_UP (buffer, 0, data->Data.fld_c_DETACH_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_DETACH_ACCEPT_UP: {
			retLen = ENCODE_c_DETACH_ACCEPT_UP (buffer, 0, data->Data.fld_c_DETACH_ACCEPT_UP);
			break;
		}
		case ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP: {
			retLen = ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (buffer, 0, data->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP);
			break;
		}
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP: {
			retLen = ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP);
			break;
		}
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP: {
			retLen = ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP);
			break;
		}
		case ID_L3Uplink_IDENTITY_RESPONSE_B_UP: {
			retLen = ENCODE_c_IDENTITY_RESPONSE_B_UP (buffer, 0, data->Data.fld_c_IDENTITY_RESPONSE_B_UP);
			break;
		}
		case ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP: {
			retLen = ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP);
			break;
		}
		case ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP: {
			retLen = ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP);
			break;
		}
		case ID_L3Uplink_GMM_STATUS: {
			retLen = ENCODE_c_GMM_STATUS (buffer, 0, data->Data.fld_c_GMM_STATUS);
			break;
		}
		case ID_L3Uplink_SERVICE_REQUEST_UP: {
			retLen = ENCODE_c_SERVICE_REQUEST_UP (buffer, 0, data->Data.fld_c_SERVICE_REQUEST_UP);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_DummyDownlink (const char* buffer, TDummyDownlink_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*/ = ((((unsigned char)buffer [0]) << 8) | ((unsigned char)buffer [1]))& 0x0FFF/*2*/;/*3*/
		data->ProtocolDiscriminator = (int)(((unsigned char)buffer [0]) & 0x0f);
		data->SkipIndicator = (int)((((unsigned char)buffer [0]) & 0xf0) >> 4);
	data->MessageType = (int)((unsigned char)buffer [1]);
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF3F) {
			/* Detect signal SETUP_UP */
		case 0x0305: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDummyDownlink_Data (data, ID_DummyDownlink_SETUP_UP), != ED_NO_ERRORS)
			INIT_c_SETUP_UP (data->Data.fld_c_SETUP_UP);
			retLen = DECODE_c_SETUP_UP (buffer, 0, data->Data.fld_c_SETUP_UP, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_DummyDownlink_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_DummyDownlink (const char* buffer, int len, TDummyDownlink_Data* data)
	{
		if (SetDecode_DummyDownlink (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_DummyDownlink (char* buffer, ED_EXLONG bitOffset, TDummyDownlink_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_DummyDownlink_SETUP_UP: {
			retLen = ENCODE_c_SETUP_UP (buffer, 0, data->Data.fld_c_SETUP_UP);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_L3Downlink (const char* buffer, TL3Downlink_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*/ = ((((unsigned char)buffer [0]) << 8) | ((unsigned char)buffer [1]))& 0x0FFF/*2*/;/*3*/
		data->ProtocolDiscriminator = (int)(((unsigned char)buffer [0]) & 0x0f);
		data->SkipIndicator = (int)((((unsigned char)buffer [0]) & 0xf0) >> 4);
	data->MessageType = (int)((unsigned char)buffer [1]);
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF3F) {
			/* Detect signal AUTHENTICATION_REJECT_DN */
		case 0x0511: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_AUTHENTICATION_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_REJECT_DN (data->Data.fld_c_AUTHENTICATION_REJECT_DN);
			retLen = DECODE_c_AUTHENTICATION_REJECT_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_REQUEST_DN */
		case 0x0512: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_AUTHENTICATION_REQUEST_DN), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_REQUEST_DN (data->Data.fld_c_AUTHENTICATION_REQUEST_DN);
			retLen = DECODE_c_AUTHENTICATION_REQUEST_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_REQUEST_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_SERVICE_ACCEPT_DN */
		case 0x0521: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CM_SERVICE_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_CM_SERVICE_ACCEPT_DN (data->Data.fld_c_CM_SERVICE_ACCEPT_DN);
			retLen = DECODE_c_CM_SERVICE_ACCEPT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_SERVICE_PROMPT_DN */
		case 0x0525: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CM_SERVICE_PROMPT_DN), != ED_NO_ERRORS)
			INIT_c_CM_SERVICE_PROMPT_DN (data->Data.fld_c_CM_SERVICE_PROMPT_DN);
			retLen = DECODE_c_CM_SERVICE_PROMPT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_PROMPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CM_SERVICE_REJECT_DN */
		case 0x0522: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CM_SERVICE_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_CM_SERVICE_REJECT_DN (data->Data.fld_c_CM_SERVICE_REJECT_DN);
			retLen = DECODE_c_CM_SERVICE_REJECT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ABORT_DN */
		case 0x0529: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ABORT_DN), != ED_NO_ERRORS)
			INIT_c_ABORT_DN (data->Data.fld_c_ABORT_DN);
			retLen = DECODE_c_ABORT_DN (buffer, 0, data->Data.fld_c_ABORT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal IDENTITY_REQUEST_DN */
		case 0x0518: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_IDENTITY_REQUEST_DN), != ED_NO_ERRORS)
			INIT_c_IDENTITY_REQUEST_DN (data->Data.fld_c_IDENTITY_REQUEST_DN);
			retLen = DECODE_c_IDENTITY_REQUEST_DN (buffer, 0, data->Data.fld_c_IDENTITY_REQUEST_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal LOCATION_UPDATING_ACCEPT_DN */
		case 0x0502: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_LOCATION_UPDATING_ACCEPT_DN (data->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN);
			retLen = DECODE_c_LOCATION_UPDATING_ACCEPT_DN (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal LOCATION_UPDATING_REJECT_DN */
		case 0x0504: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_LOCATION_UPDATING_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_LOCATION_UPDATING_REJECT_DN (data->Data.fld_c_LOCATION_UPDATING_REJECT_DN);
			retLen = DECODE_c_LOCATION_UPDATING_REJECT_DN (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MM_INFORMATION_DN */
		case 0x0532: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_MM_INFORMATION_DN), != ED_NO_ERRORS)
			INIT_c_MM_INFORMATION_DN (data->Data.fld_c_MM_INFORMATION_DN);
			retLen = DECODE_c_MM_INFORMATION_DN (buffer, 0, data->Data.fld_c_MM_INFORMATION_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MM_STATUS */
		case 0x0531: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_MM_STATUS), != ED_NO_ERRORS)
			INIT_c_MM_STATUS (data->Data.fld_c_MM_STATUS);
			retLen = DECODE_c_MM_STATUS (buffer, 0, data->Data.fld_c_MM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal TMSI_REALLOCATION_COMMAND_DN */
		case 0x051A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN), != ED_NO_ERRORS)
			INIT_c_TMSI_REALLOCATION_COMMAND_DN (data->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN);
			retLen = DECODE_c_TMSI_REALLOCATION_COMMAND_DN (buffer, 0, data->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ALERTING_DN */
		case 0x0301: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ALERTING_DN), != ED_NO_ERRORS)
			INIT_c_ALERTING_DN (data->Data.fld_c_ALERTING_DN);
			retLen = DECODE_c_ALERTING_DN (buffer, 0, data->Data.fld_c_ALERTING_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CALL_PROCEEDING_DN */
		case 0x0302: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CALL_PROCEEDING_DN), != ED_NO_ERRORS)
			INIT_c_CALL_PROCEEDING_DN (data->Data.fld_c_CALL_PROCEEDING_DN);
			retLen = DECODE_c_CALL_PROCEEDING_DN (buffer, 0, data->Data.fld_c_CALL_PROCEEDING_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CONGESTION_CONTROL_DN */
		case 0x0339: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CONGESTION_CONTROL_DN), != ED_NO_ERRORS)
			INIT_c_CONGESTION_CONTROL_DN (data->Data.fld_c_CONGESTION_CONTROL_DN);
			retLen = DECODE_c_CONGESTION_CONTROL_DN (buffer, 0, data->Data.fld_c_CONGESTION_CONTROL_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CONNECT_DN */
		case 0x0307: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CONNECT_DN), != ED_NO_ERRORS)
			INIT_c_CONNECT_DN (data->Data.fld_c_CONNECT_DN);
			retLen = DECODE_c_CONNECT_DN (buffer, 0, data->Data.fld_c_CONNECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CONNECT_ACKNOWLEDGE */
		case 0x030F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CONNECT_ACKNOWLEDGE), != ED_NO_ERRORS)
			INIT_c_CONNECT_ACKNOWLEDGE (data->Data.fld_c_CONNECT_ACKNOWLEDGE);
			retLen = DECODE_c_CONNECT_ACKNOWLEDGE (buffer, 0, data->Data.fld_c_CONNECT_ACKNOWLEDGE, bitLen);
		
			return retLen;
		}
		/* Detect signal DISCONNECT_DN */
		case 0x0325: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_DISCONNECT_DN), != ED_NO_ERRORS)
			INIT_c_DISCONNECT_DN (data->Data.fld_c_DISCONNECT_DN);
			retLen = DECODE_c_DISCONNECT_DN (buffer, 0, data->Data.fld_c_DISCONNECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal FACILITY_DN */
		case 0x033A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_FACILITY_DN), != ED_NO_ERRORS)
			INIT_c_FACILITY_DN (data->Data.fld_c_FACILITY_DN);
			retLen = DECODE_c_FACILITY_DN (buffer, 0, data->Data.fld_c_FACILITY_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal HOLD_ACKNOWLEDGE_DN */
		case 0x0319: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_HOLD_ACKNOWLEDGE_DN), != ED_NO_ERRORS)
			INIT_c_HOLD_ACKNOWLEDGE_DN (data->Data.fld_c_HOLD_ACKNOWLEDGE_DN);
			retLen = DECODE_c_HOLD_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_HOLD_ACKNOWLEDGE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal HOLD_REJECT_DN */
		case 0x031A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_HOLD_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_HOLD_REJECT_DN (data->Data.fld_c_HOLD_REJECT_DN);
			retLen = DECODE_c_HOLD_REJECT_DN (buffer, 0, data->Data.fld_c_HOLD_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY */
		case 0x0317: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_MODIFY), != ED_NO_ERRORS)
			INIT_c_MODIFY (data->Data.fld_c_MODIFY);
			retLen = DECODE_c_MODIFY (buffer, 0, data->Data.fld_c_MODIFY, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_COMPLETE */
		case 0x031F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_MODIFY_COMPLETE), != ED_NO_ERRORS)
			INIT_c_MODIFY_COMPLETE (data->Data.fld_c_MODIFY_COMPLETE);
			retLen = DECODE_c_MODIFY_COMPLETE (buffer, 0, data->Data.fld_c_MODIFY_COMPLETE, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_REJECT */
		case 0x0313: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_MODIFY_REJECT), != ED_NO_ERRORS)
			INIT_c_MODIFY_REJECT (data->Data.fld_c_MODIFY_REJECT);
			retLen = DECODE_c_MODIFY_REJECT (buffer, 0, data->Data.fld_c_MODIFY_REJECT, bitLen);
		
			return retLen;
		}
		/* Detect signal NOTIFY */
		case 0x033E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_NOTIFY), != ED_NO_ERRORS)
			INIT_c_NOTIFY (data->Data.fld_c_NOTIFY);
			retLen = DECODE_c_NOTIFY (buffer, 0, data->Data.fld_c_NOTIFY, bitLen);
		
			return retLen;
		}
		/* Detect signal PROGRESS_DN */
		case 0x0303: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_PROGRESS_DN), != ED_NO_ERRORS)
			INIT_c_PROGRESS_DN (data->Data.fld_c_PROGRESS_DN);
			retLen = DECODE_c_PROGRESS_DN (buffer, 0, data->Data.fld_c_PROGRESS_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal CC_ESTABLISHMENT_DN */
		case 0x0304: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_CC_ESTABLISHMENT_DN), != ED_NO_ERRORS)
			INIT_c_CC_ESTABLISHMENT_DN (data->Data.fld_c_CC_ESTABLISHMENT_DN);
			retLen = DECODE_c_CC_ESTABLISHMENT_DN (buffer, 0, data->Data.fld_c_CC_ESTABLISHMENT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal RELEASE_DN */
		case 0x032D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_RELEASE_DN), != ED_NO_ERRORS)
			INIT_c_RELEASE_DN (data->Data.fld_c_RELEASE_DN);
			retLen = DECODE_c_RELEASE_DN (buffer, 0, data->Data.fld_c_RELEASE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal RECALL_DN */
		case 0x030B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_RECALL_DN), != ED_NO_ERRORS)
			INIT_c_RECALL_DN (data->Data.fld_c_RECALL_DN);
			retLen = DECODE_c_RECALL_DN (buffer, 0, data->Data.fld_c_RECALL_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal RELEASE_COMPLETE_DN */
		case 0x032A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_RELEASE_COMPLETE_DN), != ED_NO_ERRORS)
			INIT_c_RELEASE_COMPLETE_DN (data->Data.fld_c_RELEASE_COMPLETE_DN);
			retLen = DECODE_c_RELEASE_COMPLETE_DN (buffer, 0, data->Data.fld_c_RELEASE_COMPLETE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal RETRIEVE_ACKNOWLEDGE_DN */
		case 0x031D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN), != ED_NO_ERRORS)
			INIT_c_RETRIEVE_ACKNOWLEDGE_DN (data->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN);
			retLen = DECODE_c_RETRIEVE_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal RETRIEVE_REJECT_DN */
		case 0x031E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_RETRIEVE_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_RETRIEVE_REJECT_DN (data->Data.fld_c_RETRIEVE_REJECT_DN);
			retLen = DECODE_c_RETRIEVE_REJECT_DN (buffer, 0, data->Data.fld_c_RETRIEVE_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal SETUP_DN */
		case 0x0305: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_SETUP_DN), != ED_NO_ERRORS)
			INIT_c_SETUP_DN (data->Data.fld_c_SETUP_DN);
			retLen = DECODE_c_SETUP_DN (buffer, 0, data->Data.fld_c_SETUP_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal START_DTMF_ACKNOWLEDGE_DN */
		case 0x0336: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN), != ED_NO_ERRORS)
			INIT_c_START_DTMF_ACKNOWLEDGE_DN (data->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN);
			retLen = DECODE_c_START_DTMF_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal START_DTMF_REJECT_DN */
		case 0x0337: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_START_DTMF_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_START_DTMF_REJECT_DN (data->Data.fld_c_START_DTMF_REJECT_DN);
			retLen = DECODE_c_START_DTMF_REJECT_DN (buffer, 0, data->Data.fld_c_START_DTMF_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal STATUS */
		case 0x033D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_STATUS), != ED_NO_ERRORS)
			INIT_c_STATUS (data->Data.fld_c_STATUS);
			retLen = DECODE_c_STATUS (buffer, 0, data->Data.fld_c_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal STATUS_ENQUIRY */
		case 0x0334: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_STATUS_ENQUIRY), != ED_NO_ERRORS)
			INIT_c_STATUS_ENQUIRY (data->Data.fld_c_STATUS_ENQUIRY);
			retLen = DECODE_c_STATUS_ENQUIRY (buffer, 0, data->Data.fld_c_STATUS_ENQUIRY, bitLen);
		
			return retLen;
		}
		/* Detect signal STOP_DTMF_ACKNOWLEDGE_DN */
		case 0x0332: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN), != ED_NO_ERRORS)
			INIT_c_STOP_DTMF_ACKNOWLEDGE_DN (data->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN);
			retLen = DECODE_c_STOP_DTMF_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal USER_INFORMATION */
		case 0x0310: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_USER_INFORMATION), != ED_NO_ERRORS)
			INIT_c_USER_INFORMATION (data->Data.fld_c_USER_INFORMATION);
			retLen = DECODE_c_USER_INFORMATION (buffer, 0, data->Data.fld_c_USER_INFORMATION, bitLen);
		
			return retLen;
		}

		default:;
	}
	switch (key) {
			/* Detect signal ATTACH_REQUEST_UP */
		case 0x0801: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ATTACH_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_ATTACH_REQUEST_UP (data->Data.fld_c_ATTACH_REQUEST_UP);
			retLen = DECODE_c_ATTACH_REQUEST_UP (buffer, 0, data->Data.fld_c_ATTACH_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ATTACH_ACCEPT_DN */
		case 0x0802: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ATTACH_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_ATTACH_ACCEPT_DN (data->Data.fld_c_ATTACH_ACCEPT_DN);
			retLen = DECODE_c_ATTACH_ACCEPT_DN (buffer, 0, data->Data.fld_c_ATTACH_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ATTACH_REJECT_DN */
		case 0x0804: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ATTACH_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_ATTACH_REJECT_DN (data->Data.fld_c_ATTACH_REJECT_DN);
			retLen = DECODE_c_ATTACH_REJECT_DN (buffer, 0, data->Data.fld_c_ATTACH_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal DETACH_REQUEST_DN */
		case 0x0805: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_DETACH_REQUEST_DN), != ED_NO_ERRORS)
			INIT_c_DETACH_REQUEST_DN (data->Data.fld_c_DETACH_REQUEST_DN);
			retLen = DECODE_c_DETACH_REQUEST_DN (buffer, 0, data->Data.fld_c_DETACH_REQUEST_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal DETACH_ACCEPT_DN */
		case 0x0806: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_DETACH_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_DETACH_ACCEPT_DN (data->Data.fld_c_DETACH_ACCEPT_DN);
			retLen = DECODE_c_DETACH_ACCEPT_DN (buffer, 0, data->Data.fld_c_DETACH_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal P_TMSI_REALLOCATION_COMMAND_DN */
		case 0x0810: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN), != ED_NO_ERRORS)
			INIT_c_P_TMSI_REALLOCATION_COMMAND_DN (data->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN);
			retLen = DECODE_c_P_TMSI_REALLOCATION_COMMAND_DN (buffer, 0, data->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_AND_CIPHERING_REQUEST_DN */
		case 0x0812: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN);
			retLen = DECODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal AUTHENTICATION_AND_CIPHERING_REJECT_DN */
		case 0x0814: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN);
			retLen = DECODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal IDENTITY_REQUEST_B_DN */
		case 0x0815: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_IDENTITY_REQUEST_B_DN), != ED_NO_ERRORS)
			INIT_c_IDENTITY_REQUEST_B_DN (data->Data.fld_c_IDENTITY_REQUEST_B_DN);
			retLen = DECODE_c_IDENTITY_REQUEST_B_DN (buffer, 0, data->Data.fld_c_IDENTITY_REQUEST_B_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ROUTING_AREA_UPDATE_ACCEPT_DN */
		case 0x0809: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_ROUTING_AREA_UPDATE_ACCEPT_DN (data->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN);
			retLen = DECODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ROUTING_AREA_UPDATE_REJECT_DN */
		case 0x080B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_ROUTING_AREA_UPDATE_REJECT_DN (data->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN);
			retLen = DECODE_c_ROUTING_AREA_UPDATE_REJECT_DN (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal GMM_STATUS */
		case 0x0820: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_GMM_STATUS), != ED_NO_ERRORS)
			INIT_c_GMM_STATUS (data->Data.fld_c_GMM_STATUS);
			retLen = DECODE_c_GMM_STATUS (buffer, 0, data->Data.fld_c_GMM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal GMM_INFORMATION_DN */
		case 0x0821: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_GMM_INFORMATION_DN), != ED_NO_ERRORS)
			INIT_c_GMM_INFORMATION_DN (data->Data.fld_c_GMM_INFORMATION_DN);
			retLen = DECODE_c_GMM_INFORMATION_DN (buffer, 0, data->Data.fld_c_GMM_INFORMATION_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal SERVICE_ACCEPT_DN */
		case 0x080D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_SERVICE_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_SERVICE_ACCEPT_DN (data->Data.fld_c_SERVICE_ACCEPT_DN);
			retLen = DECODE_c_SERVICE_ACCEPT_DN (buffer, 0, data->Data.fld_c_SERVICE_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal SERVICE_REJECT_DN */
		case 0x080E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TL3Downlink_Data (data, ID_L3Downlink_SERVICE_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_SERVICE_REJECT_DN (data->Data.fld_c_SERVICE_REJECT_DN);
			retLen = DECODE_c_SERVICE_REJECT_DN (buffer, 0, data->Data.fld_c_SERVICE_REJECT_DN, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_L3Downlink_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_L3Downlink (const char* buffer, int len, TL3Downlink_Data* data)
	{
		if (SetDecode_L3Downlink (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_L3Downlink (char* buffer, ED_EXLONG bitOffset, TL3Downlink_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_L3Downlink_AUTHENTICATION_REJECT_DN: {
			retLen = ENCODE_c_AUTHENTICATION_REJECT_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_REJECT_DN);
			break;
		}
		case ID_L3Downlink_AUTHENTICATION_REQUEST_DN: {
			retLen = ENCODE_c_AUTHENTICATION_REQUEST_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_REQUEST_DN);
			break;
		}
		case ID_L3Downlink_CM_SERVICE_ACCEPT_DN: {
			retLen = ENCODE_c_CM_SERVICE_ACCEPT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_CM_SERVICE_PROMPT_DN: {
			retLen = ENCODE_c_CM_SERVICE_PROMPT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_PROMPT_DN);
			break;
		}
		case ID_L3Downlink_CM_SERVICE_REJECT_DN: {
			retLen = ENCODE_c_CM_SERVICE_REJECT_DN (buffer, 0, data->Data.fld_c_CM_SERVICE_REJECT_DN);
			break;
		}
		case ID_L3Downlink_ABORT_DN: {
			retLen = ENCODE_c_ABORT_DN (buffer, 0, data->Data.fld_c_ABORT_DN);
			break;
		}
		case ID_L3Downlink_IDENTITY_REQUEST_DN: {
			retLen = ENCODE_c_IDENTITY_REQUEST_DN (buffer, 0, data->Data.fld_c_IDENTITY_REQUEST_DN);
			break;
		}
		case ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN: {
			retLen = ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_LOCATION_UPDATING_REJECT_DN: {
			retLen = ENCODE_c_LOCATION_UPDATING_REJECT_DN (buffer, 0, data->Data.fld_c_LOCATION_UPDATING_REJECT_DN);
			break;
		}
		case ID_L3Downlink_MM_INFORMATION_DN: {
			retLen = ENCODE_c_MM_INFORMATION_DN (buffer, 0, data->Data.fld_c_MM_INFORMATION_DN);
			break;
		}
		case ID_L3Downlink_MM_STATUS: {
			retLen = ENCODE_c_MM_STATUS (buffer, 0, data->Data.fld_c_MM_STATUS);
			break;
		}
		case ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN: {
			retLen = ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (buffer, 0, data->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN);
			break;
		}
		case ID_L3Downlink_ALERTING_DN: {
			retLen = ENCODE_c_ALERTING_DN (buffer, 0, data->Data.fld_c_ALERTING_DN);
			break;
		}
		case ID_L3Downlink_CALL_PROCEEDING_DN: {
			retLen = ENCODE_c_CALL_PROCEEDING_DN (buffer, 0, data->Data.fld_c_CALL_PROCEEDING_DN);
			break;
		}
		case ID_L3Downlink_CONGESTION_CONTROL_DN: {
			retLen = ENCODE_c_CONGESTION_CONTROL_DN (buffer, 0, data->Data.fld_c_CONGESTION_CONTROL_DN);
			break;
		}
		case ID_L3Downlink_CONNECT_DN: {
			retLen = ENCODE_c_CONNECT_DN (buffer, 0, data->Data.fld_c_CONNECT_DN);
			break;
		}
		case ID_L3Downlink_CONNECT_ACKNOWLEDGE: {
			retLen = ENCODE_c_CONNECT_ACKNOWLEDGE (buffer, 0, data->Data.fld_c_CONNECT_ACKNOWLEDGE);
			break;
		}
		case ID_L3Downlink_DISCONNECT_DN: {
			retLen = ENCODE_c_DISCONNECT_DN (buffer, 0, data->Data.fld_c_DISCONNECT_DN);
			break;
		}
		case ID_L3Downlink_FACILITY_DN: {
			retLen = ENCODE_c_FACILITY_DN (buffer, 0, data->Data.fld_c_FACILITY_DN);
			break;
		}
		case ID_L3Downlink_HOLD_ACKNOWLEDGE_DN: {
			retLen = ENCODE_c_HOLD_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_HOLD_ACKNOWLEDGE_DN);
			break;
		}
		case ID_L3Downlink_HOLD_REJECT_DN: {
			retLen = ENCODE_c_HOLD_REJECT_DN (buffer, 0, data->Data.fld_c_HOLD_REJECT_DN);
			break;
		}
		case ID_L3Downlink_MODIFY: {
			retLen = ENCODE_c_MODIFY (buffer, 0, data->Data.fld_c_MODIFY);
			break;
		}
		case ID_L3Downlink_MODIFY_COMPLETE: {
			retLen = ENCODE_c_MODIFY_COMPLETE (buffer, 0, data->Data.fld_c_MODIFY_COMPLETE);
			break;
		}
		case ID_L3Downlink_MODIFY_REJECT: {
			retLen = ENCODE_c_MODIFY_REJECT (buffer, 0, data->Data.fld_c_MODIFY_REJECT);
			break;
		}
		case ID_L3Downlink_NOTIFY: {
			retLen = ENCODE_c_NOTIFY (buffer, 0, data->Data.fld_c_NOTIFY);
			break;
		}
		case ID_L3Downlink_PROGRESS_DN: {
			retLen = ENCODE_c_PROGRESS_DN (buffer, 0, data->Data.fld_c_PROGRESS_DN);
			break;
		}
		case ID_L3Downlink_CC_ESTABLISHMENT_DN: {
			retLen = ENCODE_c_CC_ESTABLISHMENT_DN (buffer, 0, data->Data.fld_c_CC_ESTABLISHMENT_DN);
			break;
		}
		case ID_L3Downlink_RELEASE_DN: {
			retLen = ENCODE_c_RELEASE_DN (buffer, 0, data->Data.fld_c_RELEASE_DN);
			break;
		}
		case ID_L3Downlink_RECALL_DN: {
			retLen = ENCODE_c_RECALL_DN (buffer, 0, data->Data.fld_c_RECALL_DN);
			break;
		}
		case ID_L3Downlink_RELEASE_COMPLETE_DN: {
			retLen = ENCODE_c_RELEASE_COMPLETE_DN (buffer, 0, data->Data.fld_c_RELEASE_COMPLETE_DN);
			break;
		}
		case ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN: {
			retLen = ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN);
			break;
		}
		case ID_L3Downlink_RETRIEVE_REJECT_DN: {
			retLen = ENCODE_c_RETRIEVE_REJECT_DN (buffer, 0, data->Data.fld_c_RETRIEVE_REJECT_DN);
			break;
		}
		case ID_L3Downlink_SETUP_DN: {
			retLen = ENCODE_c_SETUP_DN (buffer, 0, data->Data.fld_c_SETUP_DN);
			break;
		}
		case ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN: {
			retLen = ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN);
			break;
		}
		case ID_L3Downlink_START_DTMF_REJECT_DN: {
			retLen = ENCODE_c_START_DTMF_REJECT_DN (buffer, 0, data->Data.fld_c_START_DTMF_REJECT_DN);
			break;
		}
		case ID_L3Downlink_STATUS: {
			retLen = ENCODE_c_STATUS (buffer, 0, data->Data.fld_c_STATUS);
			break;
		}
		case ID_L3Downlink_STATUS_ENQUIRY: {
			retLen = ENCODE_c_STATUS_ENQUIRY (buffer, 0, data->Data.fld_c_STATUS_ENQUIRY);
			break;
		}
		case ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN: {
			retLen = ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (buffer, 0, data->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN);
			break;
		}
		case ID_L3Downlink_USER_INFORMATION: {
			retLen = ENCODE_c_USER_INFORMATION (buffer, 0, data->Data.fld_c_USER_INFORMATION);
			break;
		}
		case ID_L3Downlink_ATTACH_REQUEST_UP: {
			retLen = ENCODE_c_ATTACH_REQUEST_UP (buffer, 0, data->Data.fld_c_ATTACH_REQUEST_UP);
			break;
		}
		case ID_L3Downlink_ATTACH_ACCEPT_DN: {
			retLen = ENCODE_c_ATTACH_ACCEPT_DN (buffer, 0, data->Data.fld_c_ATTACH_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_ATTACH_REJECT_DN: {
			retLen = ENCODE_c_ATTACH_REJECT_DN (buffer, 0, data->Data.fld_c_ATTACH_REJECT_DN);
			break;
		}
		case ID_L3Downlink_DETACH_REQUEST_DN: {
			retLen = ENCODE_c_DETACH_REQUEST_DN (buffer, 0, data->Data.fld_c_DETACH_REQUEST_DN);
			break;
		}
		case ID_L3Downlink_DETACH_ACCEPT_DN: {
			retLen = ENCODE_c_DETACH_ACCEPT_DN (buffer, 0, data->Data.fld_c_DETACH_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN: {
			retLen = ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (buffer, 0, data->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN);
			break;
		}
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN: {
			retLen = ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN);
			break;
		}
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN: {
			retLen = ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (buffer, 0, data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN);
			break;
		}
		case ID_L3Downlink_IDENTITY_REQUEST_B_DN: {
			retLen = ENCODE_c_IDENTITY_REQUEST_B_DN (buffer, 0, data->Data.fld_c_IDENTITY_REQUEST_B_DN);
			break;
		}
		case ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN: {
			retLen = ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN: {
			retLen = ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (buffer, 0, data->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN);
			break;
		}
		case ID_L3Downlink_GMM_STATUS: {
			retLen = ENCODE_c_GMM_STATUS (buffer, 0, data->Data.fld_c_GMM_STATUS);
			break;
		}
		case ID_L3Downlink_GMM_INFORMATION_DN: {
			retLen = ENCODE_c_GMM_INFORMATION_DN (buffer, 0, data->Data.fld_c_GMM_INFORMATION_DN);
			break;
		}
		case ID_L3Downlink_SERVICE_ACCEPT_DN: {
			retLen = ENCODE_c_SERVICE_ACCEPT_DN (buffer, 0, data->Data.fld_c_SERVICE_ACCEPT_DN);
			break;
		}
		case ID_L3Downlink_SERVICE_REJECT_DN: {
			retLen = ENCODE_c_SERVICE_REJECT_DN (buffer, 0, data->Data.fld_c_SERVICE_REJECT_DN);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_XTIDUplink (const char* buffer, TXTIDUplink_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*//*2*/;/*3*/
		retLen = 1;
		if ((((unsigned char)buffer [0]) & 0x70) == 0x70) {
			do {
				retLen += 1;
			} while ((((unsigned char)buffer [retLen-1]) & 0x80) == 0);
		}
		key = ((((unsigned char)buffer [0]) << 8) | ((unsigned char)buffer [0+retLen]))& 0x0FFF;
			data->ProtocolDiscriminator = (int)(((unsigned char)buffer [0]) & 0x0f);
		data->SkipIndicator = (int)((((unsigned char)buffer [0]) & 0xf0) >> 4);
	data->MessageType = (int)((unsigned char)buffer [0+retLen]);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal ACTIVATE_PDP_CONTEXT_REQUEST_UP */
		case 0x0A41: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP);
			retLen = DECODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP */
		case 0x0A4D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP);
			retLen = DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP */
		case 0x0A45: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP), != ED_NO_ERRORS)
			INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP);
			retLen = DECODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (buffer, 0, data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_PDP_CONTEXT_REQUEST_UP */
		case 0x0A4A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP), != ED_NO_ERRORS)
			INIT_c_MODIFY_PDP_CONTEXT_REQUEST_UP (data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP);
			retLen = DECODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_PDP_CONTEXT_ACCEPT_UP */
		case 0x0A49: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP), != ED_NO_ERRORS)
			INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP);
			retLen = DECODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP, bitLen);
		
			return retLen;
		}
		/* Detect signal DEACTIVATE_PDP_CONTEXT_REQUEST */
		case 0x0A46: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST), != ED_NO_ERRORS)
			INIT_c_DEACTIVATE_PDP_CONTEXT_REQUEST (data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			retLen = DECODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST, bitLen);
		
			return retLen;
		}
		/* Detect signal DEACTIVATE_PDP_CONTEXT_ACCEPT */
		case 0x0A47: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT), != ED_NO_ERRORS)
			INIT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			retLen = DECODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT */
		case 0x0A5C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT), != ED_NO_ERRORS)
			INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT);
			retLen = DECODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (buffer, 0, data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT, bitLen);
		
			return retLen;
		}
		/* Detect signal SM_STATUS */
		case 0x0A55: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_SM_STATUS), != ED_NO_ERRORS)
			INIT_c_SM_STATUS (data->Data.fld_c_SM_STATUS);
			retLen = DECODE_c_SM_STATUS (buffer, 0, data->Data.fld_c_SM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_MBMS_CONTEXT_REQUEST */
		case 0x0A56: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_MBMS_CONTEXT_REQUEST (data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST);
			retLen = DECODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT */
		case 0x0A5A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDUplink_Data (data, ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT), != ED_NO_ERRORS)
			INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT);
			retLen = DECODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (buffer, 0, data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_XTIDUplink_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_XTIDUplink (const char* buffer, int len, TXTIDUplink_Data* data)
	{
		if (SetDecode_XTIDUplink (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_XTIDUplink (char* buffer, ED_EXLONG bitOffset, TXTIDUplink_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP: {
			retLen = ENCODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		case ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP: {
			retLen = ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		case ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP: {
			retLen = ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (buffer, 0, data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP);
			break;
		}
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP: {
			retLen = ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP);
			break;
		}
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP: {
			retLen = ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP);
			break;
		}
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			retLen = ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			break;
		}
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			retLen = ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			break;
		}
		case ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT: {
			retLen = ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (buffer, 0, data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT);
			break;
		}
		case ID_XTIDUplink_SM_STATUS: {
			retLen = ENCODE_c_SM_STATUS (buffer, 0, data->Data.fld_c_SM_STATUS);
			break;
		}
		case ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST: {
			retLen = ENCODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST);
			break;
		}
		case ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT: {
			retLen = ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (buffer, 0, data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_XTIDDownlink (const char* buffer, TXTIDDownlink_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*//*2*/;/*3*/
		retLen = 1;
		if ((((unsigned char)buffer [0]) & 0x70) == 0x70) {
			do {
				retLen += 1;
			} while ((((unsigned char)buffer [retLen-1]) & 0x80) == 0);
		}
		key = ((((unsigned char)buffer [0]) << 8) | ((unsigned char)buffer [0+retLen]))& 0x0FFF;
			data->ProtocolDiscriminator = (int)(((unsigned char)buffer [0]) & 0x0f);
		data->SkipIndicator = (int)((((unsigned char)buffer [0]) & 0xf0) >> 4);
	data->MessageType = (int)((unsigned char)buffer [0+retLen]);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal ACTIVATE_PDP_CONTEXT_ACCEPT_DN */
		case 0x0A42: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (data->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN);
			retLen = DECODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_PDP_CONTEXT_REJECT_DN */
		case 0x0A43: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN);
			retLen = DECODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN */
		case 0x0A4E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN);
			retLen = DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN */
		case 0x0A4F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN);
			retLen = DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_PDP_CONTEXT_ACTIVATION_DN */
		case 0x0A44: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN), != ED_NO_ERRORS)
			INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN);
			retLen = DECODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (buffer, 0, data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_PDP_CONTEXT_REQUEST_DN */
		case 0x0A48: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN), != ED_NO_ERRORS)
			INIT_c_MODIFY_PDP_CONTEXT_REQUEST_DN (data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN);
			retLen = DECODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_PDP_CONTEXT_ACCEPT_DN */
		case 0x0A4B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN), != ED_NO_ERRORS)
			INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN);
			retLen = DECODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal MODIFY_PDP_CONTEXT_REJECT_DN */
		case 0x0A4C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN), != ED_NO_ERRORS)
			INIT_c_MODIFY_PDP_CONTEXT_REJECT_DN (data->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN);
			retLen = DECODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN, bitLen);
		
			return retLen;
		}
		/* Detect signal DEACTIVATE_PDP_CONTEXT_REQUEST */
		case 0x0A46: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST), != ED_NO_ERRORS)
			INIT_c_DEACTIVATE_PDP_CONTEXT_REQUEST (data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			retLen = DECODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST, bitLen);
		
			return retLen;
		}
		/* Detect signal DEACTIVATE_PDP_CONTEXT_ACCEPT */
		case 0x0A47: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT), != ED_NO_ERRORS)
			INIT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			retLen = DECODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION */
		case 0x0A5B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION), != ED_NO_ERRORS)
			INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION);
			retLen = DECODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (buffer, 0, data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION, bitLen);
		
			return retLen;
		}
		/* Detect signal NOTIFICATION */
		case 0x0A5D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_NOTIFICATION), != ED_NO_ERRORS)
			INIT_c_NOTIFICATION (data->Data.fld_c_NOTIFICATION);
			retLen = DECODE_c_NOTIFICATION (buffer, 0, data->Data.fld_c_NOTIFICATION, bitLen);
		
			return retLen;
		}
		/* Detect signal SM_STATUS */
		case 0x0A55: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_SM_STATUS), != ED_NO_ERRORS)
			INIT_c_SM_STATUS (data->Data.fld_c_SM_STATUS);
			retLen = DECODE_c_SM_STATUS (buffer, 0, data->Data.fld_c_SM_STATUS, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_MBMS_CONTEXT_ACCEPT */
		case 0x0A57: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT);
			retLen = DECODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT, bitLen);
		
			return retLen;
		}
		/* Detect signal ACTIVATE_MBMS_CONTEXT_REJECT */
		case 0x0A58: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT), != ED_NO_ERRORS)
			INIT_c_ACTIVATE_MBMS_CONTEXT_REJECT (data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT);
			retLen = DECODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT, bitLen);
		
			return retLen;
		}
		/* Detect signal REQUEST_MBMS_CONTEXT_ACTIVATION */
		case 0x0A59: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TXTIDDownlink_Data (data, ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION), != ED_NO_ERRORS)
			INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION (data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION);
			retLen = DECODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (buffer, 0, data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_XTIDDownlink_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_XTIDDownlink (const char* buffer, int len, TXTIDDownlink_Data* data)
	{
		if (SetDecode_XTIDDownlink (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_XTIDDownlink (char* buffer, ED_EXLONG bitOffset, TXTIDDownlink_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN: {
			retLen = ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN: {
			retLen = ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN);
			break;
		}
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN: {
			retLen = ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN: {
			retLen = ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN);
			break;
		}
		case ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN: {
			retLen = ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (buffer, 0, data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN);
			break;
		}
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN: {
			retLen = ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN);
			break;
		}
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN: {
			retLen = ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN);
			break;
		}
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN: {
			retLen = ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (buffer, 0, data->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN);
			break;
		}
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST: {
			retLen = ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST);
			break;
		}
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT: {
			retLen = ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT);
			break;
		}
		case ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION: {
			retLen = ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (buffer, 0, data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION);
			break;
		}
		case ID_XTIDDownlink_NOTIFICATION: {
			retLen = ENCODE_c_NOTIFICATION (buffer, 0, data->Data.fld_c_NOTIFICATION);
			break;
		}
		case ID_XTIDDownlink_SM_STATUS: {
			retLen = ENCODE_c_SM_STATUS (buffer, 0, data->Data.fld_c_SM_STATUS);
			break;
		}
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT: {
			retLen = ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT);
			break;
		}
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT: {
			retLen = ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (buffer, 0, data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT);
			break;
		}
		case ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION: {
			retLen = ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (buffer, 0, data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION);
			break;
		}

		default:;
	}
	return retLen;
}

