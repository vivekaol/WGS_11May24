/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_recog_RLCMAC.h"
#include "ed_lib.h"
#include "Downlink_RLC_MAC_RLCMAC.h"
#include "Uplink_RLC_MAC_RLCMAC.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


int SETPRESENT_TDownlink_RLC_MAC_Data (TDownlink_RLC_MAC_Data* sp, TDownlink_RLC_MAC_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TDownlink_RLC_MAC_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Order: {
			sp->Data.fld_c_Packet_Cell_Change_Order = (c_Packet_Cell_Change_Order*)EDAlloc (sizeof (c_Packet_Cell_Change_Order)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Cell_Change_Order == NULL)
			INIT_c_Packet_Cell_Change_Order (sp->Data.fld_c_Packet_Cell_Change_Order);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Downlink_Assignment: {
			sp->Data.fld_c_Packet_Downlink_Assignment = (c_Packet_Downlink_Assignment*)EDAlloc (sizeof (c_Packet_Downlink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Downlink_Assignment == NULL)
			INIT_c_Packet_Downlink_Assignment (sp->Data.fld_c_Packet_Downlink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Measurement_Order: {
			sp->Data.fld_c_Packet_Measurement_Order = (c_Packet_Measurement_Order*)EDAlloc (sizeof (c_Packet_Measurement_Order)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Measurement_Order == NULL)
			INIT_c_Packet_Measurement_Order (sp->Data.fld_c_Packet_Measurement_Order);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Polling_Request: {
			sp->Data.fld_c_Packet_Polling_Request = (c_Packet_Polling_Request*)EDAlloc (sizeof (c_Packet_Polling_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Polling_Request == NULL)
			INIT_c_Packet_Polling_Request (sp->Data.fld_c_Packet_Polling_Request);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Power_Control_Timing_Advance: {
			sp->Data.fld_c_Packet_Power_Control_Timing_Advance = (c_Packet_Power_Control_Timing_Advance*)EDAlloc (sizeof (c_Packet_Power_Control_Timing_Advance)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Power_Control_Timing_Advance == NULL)
			INIT_c_Packet_Power_Control_Timing_Advance (sp->Data.fld_c_Packet_Power_Control_Timing_Advance);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Queueing_Notification: {
			sp->Data.fld_c_Packet_Queueing_Notification = (c_Packet_Queueing_Notification*)EDAlloc (sizeof (c_Packet_Queueing_Notification)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Queueing_Notification == NULL)
			INIT_c_Packet_Queueing_Notification (sp->Data.fld_c_Packet_Queueing_Notification);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Timeslot_Reconfigure: {
			sp->Data.fld_c_Packet_Timeslot_Reconfigure = (c_Packet_Timeslot_Reconfigure*)EDAlloc (sizeof (c_Packet_Timeslot_Reconfigure)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Timeslot_Reconfigure == NULL)
			INIT_c_Packet_Timeslot_Reconfigure (sp->Data.fld_c_Packet_Timeslot_Reconfigure);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_TBF_Release: {
			sp->Data.fld_c_Packet_TBF_Release = (c_Packet_TBF_Release*)EDAlloc (sizeof (c_Packet_TBF_Release)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_TBF_Release == NULL)
			INIT_c_Packet_TBF_Release (sp->Data.fld_c_Packet_TBF_Release);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Uplink_Ack_Nack: {
			sp->Data.fld_c_Packet_Uplink_Ack_Nack = (c_Packet_Uplink_Ack_Nack*)EDAlloc (sizeof (c_Packet_Uplink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Uplink_Ack_Nack == NULL)
			INIT_c_Packet_Uplink_Ack_Nack (sp->Data.fld_c_Packet_Uplink_Ack_Nack);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Uplink_Assignment: {
			sp->Data.fld_c_Packet_Uplink_Assignment = (c_Packet_Uplink_Assignment*)EDAlloc (sizeof (c_Packet_Uplink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Uplink_Assignment == NULL)
			INIT_c_Packet_Uplink_Assignment (sp->Data.fld_c_Packet_Uplink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Continue: {
			sp->Data.fld_c_Packet_Cell_Change_Continue = (c_Packet_Cell_Change_Continue*)EDAlloc (sizeof (c_Packet_Cell_Change_Continue)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Cell_Change_Continue == NULL)
			INIT_c_Packet_Cell_Change_Continue (sp->Data.fld_c_Packet_Cell_Change_Continue);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Neighbour_Cell_Data: {
			sp->Data.fld_c_Packet_Neighbour_Cell_Data = (c_Packet_Neighbour_Cell_Data*)EDAlloc (sizeof (c_Packet_Neighbour_Cell_Data)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Neighbour_Cell_Data == NULL)
			INIT_c_Packet_Neighbour_Cell_Data (sp->Data.fld_c_Packet_Neighbour_Cell_Data);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_Data: {
			sp->Data.fld_c_Packet_Serving_Cell_Data = (c_Packet_Serving_Cell_Data*)EDAlloc (sizeof (c_Packet_Serving_Cell_Data)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Serving_Cell_Data == NULL)
			INIT_c_Packet_Serving_Cell_Data (sp->Data.fld_c_Packet_Serving_Cell_Data);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_DBPSCH_Assignment: {
			sp->Data.fld_c_Packet_DBPSCH_Assignment = (c_Packet_DBPSCH_Assignment*)EDAlloc (sizeof (c_Packet_DBPSCH_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_DBPSCH_Assignment == NULL)
			INIT_c_Packet_DBPSCH_Assignment (sp->Data.fld_c_Packet_DBPSCH_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Downlink_Assignment: {
			sp->Data.fld_c_Multiple_TBF_Downlink_Assignment = (c_Multiple_TBF_Downlink_Assignment*)EDAlloc (sizeof (c_Multiple_TBF_Downlink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Multiple_TBF_Downlink_Assignment == NULL)
			INIT_c_Multiple_TBF_Downlink_Assignment (sp->Data.fld_c_Multiple_TBF_Downlink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Access_Reject: {
			sp->Data.fld_c_Packet_Access_Reject = (c_Packet_Access_Reject*)EDAlloc (sizeof (c_Packet_Access_Reject)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Access_Reject == NULL)
			INIT_c_Packet_Access_Reject (sp->Data.fld_c_Packet_Access_Reject);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Paging_Request: {
			sp->Data.fld_c_Packet_Paging_Request = (c_Packet_Paging_Request*)EDAlloc (sizeof (c_Packet_Paging_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Paging_Request == NULL)
			INIT_c_Packet_Paging_Request (sp->Data.fld_c_Packet_Paging_Request);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_PDCH_Release: {
			sp->Data.fld_c_Packet_PDCH_Release = (c_Packet_PDCH_Release*)EDAlloc (sizeof (c_Packet_PDCH_Release)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_PDCH_Release == NULL)
			INIT_c_Packet_PDCH_Release (sp->Data.fld_c_Packet_PDCH_Release);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_PRACH_Parameters: {
			sp->Data.fld_c_Packet_PRACH_Parameters = (c_Packet_PRACH_Parameters*)EDAlloc (sizeof (c_Packet_PRACH_Parameters)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_PRACH_Parameters == NULL)
			INIT_c_Packet_PRACH_Parameters (sp->Data.fld_c_Packet_PRACH_Parameters);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Downlink_Dummy_Control_Block: {
			sp->Data.fld_c_Packet_Downlink_Dummy_Control_Block = (c_Packet_Downlink_Dummy_Control_Block*)EDAlloc (sizeof (c_Packet_Downlink_Dummy_Control_Block)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Downlink_Dummy_Control_Block == NULL)
			INIT_c_Packet_Downlink_Dummy_Control_Block (sp->Data.fld_c_Packet_Downlink_Dummy_Control_Block);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI16: {
			sp->Data.fld_c_PSI16 = (c_PSI16*)EDAlloc (sizeof (c_PSI16)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI16 == NULL)
			INIT_c_PSI16 (sp->Data.fld_c_PSI16);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI6: {
			sp->Data.fld_c_PSI6 = (c_PSI6*)EDAlloc (sizeof (c_PSI6)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI6 == NULL)
			INIT_c_PSI6 (sp->Data.fld_c_PSI6);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI1: {
			sp->Data.fld_c_PSI1 = (c_PSI1*)EDAlloc (sizeof (c_PSI1)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI1 == NULL)
			INIT_c_PSI1 (sp->Data.fld_c_PSI1);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI2: {
			sp->Data.fld_c_PSI2 = (c_PSI2*)EDAlloc (sizeof (c_PSI2)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI2 == NULL)
			INIT_c_PSI2 (sp->Data.fld_c_PSI2);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3: {
			sp->Data.fld_c_PSI3 = (c_PSI3*)EDAlloc (sizeof (c_PSI3)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI3 == NULL)
			INIT_c_PSI3 (sp->Data.fld_c_PSI3);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_bis: {
			sp->Data.fld_c_PSI3_bis = (c_PSI3_bis*)EDAlloc (sizeof (c_PSI3_bis)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI3_bis == NULL)
			INIT_c_PSI3_bis (sp->Data.fld_c_PSI3_bis);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI4: {
			sp->Data.fld_c_PSI4 = (c_PSI4*)EDAlloc (sizeof (c_PSI4)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI4 == NULL)
			INIT_c_PSI4 (sp->Data.fld_c_PSI4);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI5: {
			sp->Data.fld_c_PSI5 = (c_PSI5*)EDAlloc (sizeof (c_PSI5)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI5 == NULL)
			INIT_c_PSI5 (sp->Data.fld_c_PSI5);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI13: {
			sp->Data.fld_c_PSI13 = (c_PSI13*)EDAlloc (sizeof (c_PSI13)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI13 == NULL)
			INIT_c_PSI13 (sp->Data.fld_c_PSI13);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI7: {
			sp->Data.fld_c_PSI7 = (c_PSI7*)EDAlloc (sizeof (c_PSI7)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI7 == NULL)
			INIT_c_PSI7 (sp->Data.fld_c_PSI7);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI8: {
			sp->Data.fld_c_PSI8 = (c_PSI8*)EDAlloc (sizeof (c_PSI8)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI8 == NULL)
			INIT_c_PSI8 (sp->Data.fld_c_PSI8);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI14: {
			sp->Data.fld_c_PSI14 = (c_PSI14*)EDAlloc (sizeof (c_PSI14)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI14 == NULL)
			INIT_c_PSI14 (sp->Data.fld_c_PSI14);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_ter: {
			sp->Data.fld_c_PSI3_ter = (c_PSI3_ter*)EDAlloc (sizeof (c_PSI3_ter)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI3_ter == NULL)
			INIT_c_PSI3_ter (sp->Data.fld_c_PSI3_ter);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_quater: {
			sp->Data.fld_c_PSI3_quater = (c_PSI3_quater*)EDAlloc (sizeof (c_PSI3_quater)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI3_quater == NULL)
			INIT_c_PSI3_quater (sp->Data.fld_c_PSI3_quater);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI15: {
			sp->Data.fld_c_PSI15 = (c_PSI15*)EDAlloc (sizeof (c_PSI15)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PSI15 == NULL)
			INIT_c_PSI15 (sp->Data.fld_c_PSI15);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Uplink_Assignment: {
			sp->Data.fld_c_Multiple_TBF_Uplink_Assignment = (c_Multiple_TBF_Uplink_Assignment*)EDAlloc (sizeof (c_Multiple_TBF_Uplink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Multiple_TBF_Uplink_Assignment == NULL)
			INIT_c_Multiple_TBF_Uplink_Assignment (sp->Data.fld_c_Multiple_TBF_Uplink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Timeslot_Reconfigure: {
			sp->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure = (c_Multiple_TBF_Timeslot_Reconfigure*)EDAlloc (sizeof (c_Multiple_TBF_Timeslot_Reconfigure)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure == NULL)
			INIT_c_Multiple_TBF_Timeslot_Reconfigure (sp->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure);
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_MS_ID_Assignment: {
			sp->Data.fld_c_MBMS_MS_ID_Assignment = (c_MBMS_MS_ID_Assignment*)EDAlloc (sizeof (c_MBMS_MS_ID_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_MS_ID_Assignment == NULL)
			INIT_c_MBMS_MS_ID_Assignment (sp->Data.fld_c_MBMS_MS_ID_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Non_distribution: {
			sp->Data.fld_c_MBMS_Assignment_Non_distribution = (c_MBMS_Assignment_Non_distribution*)EDAlloc (sizeof (c_MBMS_Assignment_Non_distribution)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_Assignment_Non_distribution == NULL)
			INIT_c_MBMS_Assignment_Non_distribution (sp->Data.fld_c_MBMS_Assignment_Non_distribution);
			break;
		}
		
		case ID_Downlink_RLC_MAC_PS_Handover_Command: {
			sp->Data.fld_c_PS_Handover_Command = (c_PS_Handover_Command*)EDAlloc (sizeof (c_PS_Handover_Command)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_PS_Handover_Command == NULL)
			INIT_c_PS_Handover_Command (sp->Data.fld_c_PS_Handover_Command);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Physical_Information: {
			sp->Data.fld_c_Packet_Physical_Information = (c_Packet_Physical_Information*)EDAlloc (sizeof (c_Packet_Physical_Information)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Physical_Information == NULL)
			INIT_c_Packet_Physical_Information (sp->Data.fld_c_Packet_Physical_Information);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_SI: {
			sp->Data.fld_c_Packet_Serving_Cell_SI = (c_Packet_Serving_Cell_SI*)EDAlloc (sizeof (c_Packet_Serving_Cell_SI)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Serving_Cell_SI == NULL)
			INIT_c_Packet_Serving_Cell_SI (sp->Data.fld_c_Packet_Serving_Cell_SI);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_CS_Command: {
			sp->Data.fld_c_Packet_CS_Command = (c_Packet_CS_Command*)EDAlloc (sizeof (c_Packet_CS_Command)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_CS_Command == NULL)
			INIT_c_Packet_CS_Command (sp->Data.fld_c_Packet_CS_Command);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_CS_Release: {
			sp->Data.fld_c_Packet_CS_Release = (c_Packet_CS_Release*)EDAlloc (sizeof (c_Packet_CS_Release)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_CS_Release == NULL)
			INIT_c_Packet_CS_Release (sp->Data.fld_c_Packet_CS_Release);
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Distribution: {
			sp->Data.fld_c_MBMS_Assignment_Distribution = (c_MBMS_Assignment_Distribution*)EDAlloc (sizeof (c_MBMS_Assignment_Distribution)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_Assignment_Distribution == NULL)
			INIT_c_MBMS_Assignment_Distribution (sp->Data.fld_c_MBMS_Assignment_Distribution);
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Neighbouring_Cell_Information: {
			sp->Data.fld_c_MBMS_Neighbouring_Cell_Information = (c_MBMS_Neighbouring_Cell_Information*)EDAlloc (sizeof (c_MBMS_Neighbouring_Cell_Information)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_Neighbouring_Cell_Information == NULL)
			INIT_c_MBMS_Neighbouring_Cell_Information (sp->Data.fld_c_MBMS_Neighbouring_Cell_Information);
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_MBMS_Announcement: {
			sp->Data.fld_c_Packet_MBMS_Announcement = (c_Packet_MBMS_Announcement*)EDAlloc (sizeof (c_Packet_MBMS_Announcement)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_MBMS_Announcement == NULL)
			INIT_c_Packet_MBMS_Announcement (sp->Data.fld_c_Packet_MBMS_Announcement);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TDownlink_RLC_MAC_Data (TDownlink_RLC_MAC_Data* sp)
{
	switch (sp->Type) {
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Order: {
			FREE_c_Packet_Cell_Change_Order (sp->Data.fld_c_Packet_Cell_Change_Order);
	EDFree (sp->Data.fld_c_Packet_Cell_Change_Order );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Downlink_Assignment: {
			FREE_c_Packet_Downlink_Assignment (sp->Data.fld_c_Packet_Downlink_Assignment);
	EDFree (sp->Data.fld_c_Packet_Downlink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Measurement_Order: {
			FREE_c_Packet_Measurement_Order (sp->Data.fld_c_Packet_Measurement_Order);
	EDFree (sp->Data.fld_c_Packet_Measurement_Order );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Polling_Request: {
			FREE_c_Packet_Polling_Request (sp->Data.fld_c_Packet_Polling_Request);
	EDFree (sp->Data.fld_c_Packet_Polling_Request );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Power_Control_Timing_Advance: {
			FREE_c_Packet_Power_Control_Timing_Advance (sp->Data.fld_c_Packet_Power_Control_Timing_Advance);
	EDFree (sp->Data.fld_c_Packet_Power_Control_Timing_Advance );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Queueing_Notification: {
			FREE_c_Packet_Queueing_Notification (sp->Data.fld_c_Packet_Queueing_Notification);
	EDFree (sp->Data.fld_c_Packet_Queueing_Notification );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Timeslot_Reconfigure: {
			FREE_c_Packet_Timeslot_Reconfigure (sp->Data.fld_c_Packet_Timeslot_Reconfigure);
	EDFree (sp->Data.fld_c_Packet_Timeslot_Reconfigure );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_TBF_Release: {
			FREE_c_Packet_TBF_Release (sp->Data.fld_c_Packet_TBF_Release);
	EDFree (sp->Data.fld_c_Packet_TBF_Release );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Uplink_Ack_Nack: {
			FREE_c_Packet_Uplink_Ack_Nack (sp->Data.fld_c_Packet_Uplink_Ack_Nack);
	EDFree (sp->Data.fld_c_Packet_Uplink_Ack_Nack );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Uplink_Assignment: {
			FREE_c_Packet_Uplink_Assignment (sp->Data.fld_c_Packet_Uplink_Assignment);
	EDFree (sp->Data.fld_c_Packet_Uplink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Continue: {
			FREE_c_Packet_Cell_Change_Continue (sp->Data.fld_c_Packet_Cell_Change_Continue);
	EDFree (sp->Data.fld_c_Packet_Cell_Change_Continue );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Neighbour_Cell_Data: {
			FREE_c_Packet_Neighbour_Cell_Data (sp->Data.fld_c_Packet_Neighbour_Cell_Data);
	EDFree (sp->Data.fld_c_Packet_Neighbour_Cell_Data );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_Data: {
			FREE_c_Packet_Serving_Cell_Data (sp->Data.fld_c_Packet_Serving_Cell_Data);
	EDFree (sp->Data.fld_c_Packet_Serving_Cell_Data );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_DBPSCH_Assignment: {
			FREE_c_Packet_DBPSCH_Assignment (sp->Data.fld_c_Packet_DBPSCH_Assignment);
	EDFree (sp->Data.fld_c_Packet_DBPSCH_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Downlink_Assignment: {
			FREE_c_Multiple_TBF_Downlink_Assignment (sp->Data.fld_c_Multiple_TBF_Downlink_Assignment);
	EDFree (sp->Data.fld_c_Multiple_TBF_Downlink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Access_Reject: {
			FREE_c_Packet_Access_Reject (sp->Data.fld_c_Packet_Access_Reject);
	EDFree (sp->Data.fld_c_Packet_Access_Reject );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Paging_Request: {
			FREE_c_Packet_Paging_Request (sp->Data.fld_c_Packet_Paging_Request);
	EDFree (sp->Data.fld_c_Packet_Paging_Request );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_PDCH_Release: {
			FREE_c_Packet_PDCH_Release (sp->Data.fld_c_Packet_PDCH_Release);
	EDFree (sp->Data.fld_c_Packet_PDCH_Release );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_PRACH_Parameters: {
			FREE_c_Packet_PRACH_Parameters (sp->Data.fld_c_Packet_PRACH_Parameters);
	EDFree (sp->Data.fld_c_Packet_PRACH_Parameters );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Downlink_Dummy_Control_Block: {
			FREE_c_Packet_Downlink_Dummy_Control_Block (sp->Data.fld_c_Packet_Downlink_Dummy_Control_Block);
	EDFree (sp->Data.fld_c_Packet_Downlink_Dummy_Control_Block );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI16: {
			FREE_c_PSI16 (sp->Data.fld_c_PSI16);
	EDFree (sp->Data.fld_c_PSI16 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI6: {
			FREE_c_PSI6 (sp->Data.fld_c_PSI6);
	EDFree (sp->Data.fld_c_PSI6 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI1: {
			FREE_c_PSI1 (sp->Data.fld_c_PSI1);
	EDFree (sp->Data.fld_c_PSI1 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI2: {
			FREE_c_PSI2 (sp->Data.fld_c_PSI2);
	EDFree (sp->Data.fld_c_PSI2 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3: {
			FREE_c_PSI3 (sp->Data.fld_c_PSI3);
	EDFree (sp->Data.fld_c_PSI3 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_bis: {
			FREE_c_PSI3_bis (sp->Data.fld_c_PSI3_bis);
	EDFree (sp->Data.fld_c_PSI3_bis );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI4: {
			FREE_c_PSI4 (sp->Data.fld_c_PSI4);
	EDFree (sp->Data.fld_c_PSI4 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI5: {
			FREE_c_PSI5 (sp->Data.fld_c_PSI5);
	EDFree (sp->Data.fld_c_PSI5 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI13: {
			FREE_c_PSI13 (sp->Data.fld_c_PSI13);
	EDFree (sp->Data.fld_c_PSI13 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI7: {
			FREE_c_PSI7 (sp->Data.fld_c_PSI7);
	EDFree (sp->Data.fld_c_PSI7 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI8: {
			FREE_c_PSI8 (sp->Data.fld_c_PSI8);
	EDFree (sp->Data.fld_c_PSI8 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI14: {
			FREE_c_PSI14 (sp->Data.fld_c_PSI14);
	EDFree (sp->Data.fld_c_PSI14 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_ter: {
			FREE_c_PSI3_ter (sp->Data.fld_c_PSI3_ter);
	EDFree (sp->Data.fld_c_PSI3_ter );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI3_quater: {
			FREE_c_PSI3_quater (sp->Data.fld_c_PSI3_quater);
	EDFree (sp->Data.fld_c_PSI3_quater );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PSI15: {
			FREE_c_PSI15 (sp->Data.fld_c_PSI15);
	EDFree (sp->Data.fld_c_PSI15 );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Uplink_Assignment: {
			FREE_c_Multiple_TBF_Uplink_Assignment (sp->Data.fld_c_Multiple_TBF_Uplink_Assignment);
	EDFree (sp->Data.fld_c_Multiple_TBF_Uplink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Multiple_TBF_Timeslot_Reconfigure: {
			FREE_c_Multiple_TBF_Timeslot_Reconfigure (sp->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure);
	EDFree (sp->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure );
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_MS_ID_Assignment: {
			FREE_c_MBMS_MS_ID_Assignment (sp->Data.fld_c_MBMS_MS_ID_Assignment);
	EDFree (sp->Data.fld_c_MBMS_MS_ID_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Non_distribution: {
			FREE_c_MBMS_Assignment_Non_distribution (sp->Data.fld_c_MBMS_Assignment_Non_distribution);
	EDFree (sp->Data.fld_c_MBMS_Assignment_Non_distribution );
			break;
		}
		
		case ID_Downlink_RLC_MAC_PS_Handover_Command: {
			FREE_c_PS_Handover_Command (sp->Data.fld_c_PS_Handover_Command);
	EDFree (sp->Data.fld_c_PS_Handover_Command );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Physical_Information: {
			FREE_c_Packet_Physical_Information (sp->Data.fld_c_Packet_Physical_Information);
	EDFree (sp->Data.fld_c_Packet_Physical_Information );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_SI: {
			FREE_c_Packet_Serving_Cell_SI (sp->Data.fld_c_Packet_Serving_Cell_SI);
	EDFree (sp->Data.fld_c_Packet_Serving_Cell_SI );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_CS_Command: {
			FREE_c_Packet_CS_Command (sp->Data.fld_c_Packet_CS_Command);
	EDFree (sp->Data.fld_c_Packet_CS_Command );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_CS_Release: {
			FREE_c_Packet_CS_Release (sp->Data.fld_c_Packet_CS_Release);
	EDFree (sp->Data.fld_c_Packet_CS_Release );
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Distribution: {
			FREE_c_MBMS_Assignment_Distribution (sp->Data.fld_c_MBMS_Assignment_Distribution);
	EDFree (sp->Data.fld_c_MBMS_Assignment_Distribution );
			break;
		}
		
		case ID_Downlink_RLC_MAC_MBMS_Neighbouring_Cell_Information: {
			FREE_c_MBMS_Neighbouring_Cell_Information (sp->Data.fld_c_MBMS_Neighbouring_Cell_Information);
	EDFree (sp->Data.fld_c_MBMS_Neighbouring_Cell_Information );
			break;
		}
		
		case ID_Downlink_RLC_MAC_Packet_MBMS_Announcement: {
			FREE_c_Packet_MBMS_Announcement (sp->Data.fld_c_Packet_MBMS_Announcement);
	EDFree (sp->Data.fld_c_Packet_MBMS_Announcement );
			break;
		}
		
		default:;
	}

	sp->Type = ID_Downlink_RLC_MAC_Unrecognized;
}

int SETPRESENT_TUplink_RLC_MAC_Data (TUplink_RLC_MAC_Data* sp, TUplink_RLC_MAC_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TUplink_RLC_MAC_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Failure: {
			sp->Data.fld_c_Packet_Cell_Change_Failure = (c_Packet_Cell_Change_Failure*)EDAlloc (sizeof (c_Packet_Cell_Change_Failure)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Cell_Change_Failure == NULL)
			INIT_c_Packet_Cell_Change_Failure (sp->Data.fld_c_Packet_Cell_Change_Failure);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement: {
			sp->Data.fld_c_Packet_Control_Acknowledgement = (c_Packet_Control_Acknowledgement*)EDAlloc (sizeof (c_Packet_Control_Acknowledgement)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Control_Acknowledgement == NULL)
			INIT_c_Packet_Control_Acknowledgement (sp->Data.fld_c_Packet_Control_Acknowledgement);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_a: {
			sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_a = (c_Packet_Control_Acknowledgement_11bit_a*)EDAlloc (sizeof (c_Packet_Control_Acknowledgement_11bit_a)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_a == NULL)
			INIT_c_Packet_Control_Acknowledgement_11bit_a (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_a);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_b: {
			sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_b = (c_Packet_Control_Acknowledgement_11bit_b*)EDAlloc (sizeof (c_Packet_Control_Acknowledgement_11bit_b)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_b == NULL)
			INIT_c_Packet_Control_Acknowledgement_11bit_b (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_b);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_8bit: {
			sp->Data.fld_c_Packet_Control_Acknowledgement_8bit = (c_Packet_Control_Acknowledgement_8bit*)EDAlloc (sizeof (c_Packet_Control_Acknowledgement_8bit)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Control_Acknowledgement_8bit == NULL)
			INIT_c_Packet_Control_Acknowledgement_8bit (sp->Data.fld_c_Packet_Control_Acknowledgement_8bit);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Downlink_Ack_Nack: {
			sp->Data.fld_c_Packet_Downlink_Ack_Nack = (c_Packet_Downlink_Ack_Nack*)EDAlloc (sizeof (c_Packet_Downlink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Downlink_Ack_Nack == NULL)
			INIT_c_Packet_Downlink_Ack_Nack (sp->Data.fld_c_Packet_Downlink_Ack_Nack);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Uplink_Dummy_Control_Block: {
			sp->Data.fld_c_Packet_Uplink_Dummy_Control_Block = (c_Packet_Uplink_Dummy_Control_Block*)EDAlloc (sizeof (c_Packet_Uplink_Dummy_Control_Block)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Uplink_Dummy_Control_Block == NULL)
			INIT_c_Packet_Uplink_Dummy_Control_Block (sp->Data.fld_c_Packet_Uplink_Dummy_Control_Block);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Measurement_Report: {
			sp->Data.fld_c_Packet_Measurement_Report = (c_Packet_Measurement_Report*)EDAlloc (sizeof (c_Packet_Measurement_Report)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Measurement_Report == NULL)
			INIT_c_Packet_Measurement_Report (sp->Data.fld_c_Packet_Measurement_Report);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Resource_Request: {
			sp->Data.fld_c_Packet_Resource_Request = (c_Packet_Resource_Request*)EDAlloc (sizeof (c_Packet_Resource_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Resource_Request == NULL)
			INIT_c_Packet_Resource_Request (sp->Data.fld_c_Packet_Resource_Request);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Mobile_TBF_Status: {
			sp->Data.fld_c_Packet_Mobile_TBF_Status = (c_Packet_Mobile_TBF_Status*)EDAlloc (sizeof (c_Packet_Mobile_TBF_Status)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Mobile_TBF_Status == NULL)
			INIT_c_Packet_Mobile_TBF_Status (sp->Data.fld_c_Packet_Mobile_TBF_Status);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_PSI_Status: {
			sp->Data.fld_c_Packet_PSI_Status = (c_Packet_PSI_Status*)EDAlloc (sizeof (c_Packet_PSI_Status)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_PSI_Status == NULL)
			INIT_c_Packet_PSI_Status (sp->Data.fld_c_Packet_PSI_Status);
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack: {
			sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack = (c_EGPRS_Packet_Downlink_Ack_Nack*)EDAlloc (sizeof (c_EGPRS_Packet_Downlink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack == NULL)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Pause: {
			sp->Data.fld_c_Packet_Pause = (c_Packet_Pause*)EDAlloc (sizeof (c_Packet_Pause)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Pause == NULL)
			INIT_c_Packet_Pause (sp->Data.fld_c_Packet_Pause);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Enhanced_Measurement_Report: {
			sp->Data.fld_c_Packet_Enhanced_Measurement_Report = (c_Packet_Enhanced_Measurement_Report*)EDAlloc (sizeof (c_Packet_Enhanced_Measurement_Report)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Enhanced_Measurement_Report == NULL)
			INIT_c_Packet_Enhanced_Measurement_Report (sp->Data.fld_c_Packet_Enhanced_Measurement_Report);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Additional_MS_Radio_Access_Capabilities: {
			sp->Data.fld_c_Additional_MS_Radio_Access_Capabilities = (c_Additional_MS_Radio_Access_Capabilities*)EDAlloc (sizeof (c_Additional_MS_Radio_Access_Capabilities)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Additional_MS_Radio_Access_Capabilities == NULL)
			INIT_c_Additional_MS_Radio_Access_Capabilities (sp->Data.fld_c_Additional_MS_Radio_Access_Capabilities);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Notification: {
			sp->Data.fld_c_Packet_Cell_Change_Notification = (c_Packet_Cell_Change_Notification*)EDAlloc (sizeof (c_Packet_Cell_Change_Notification)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_Cell_Change_Notification == NULL)
			INIT_c_Packet_Cell_Change_Notification (sp->Data.fld_c_Packet_Cell_Change_Notification);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_SI_Status: {
			sp->Data.fld_c_Packet_SI_Status = (c_Packet_SI_Status*)EDAlloc (sizeof (c_Packet_SI_Status)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_SI_Status == NULL)
			INIT_c_Packet_SI_Status (sp->Data.fld_c_Packet_SI_Status);
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_CS_Request: {
			sp->Data.fld_c_Packet_CS_Request = (c_Packet_CS_Request*)EDAlloc (sizeof (c_Packet_CS_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_Packet_CS_Request == NULL)
			INIT_c_Packet_CS_Request (sp->Data.fld_c_Packet_CS_Request);
			break;
		}
		
		case ID_Uplink_RLC_MAC_MBMS_Service_Request: {
			sp->Data.fld_c_MBMS_Service_Request = (c_MBMS_Service_Request*)EDAlloc (sizeof (c_MBMS_Service_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_Service_Request == NULL)
			INIT_c_MBMS_Service_Request (sp->Data.fld_c_MBMS_Service_Request);
			break;
		}
		
		case ID_Uplink_RLC_MAC_MBMS_Downlink_Ack_Nack: {
			sp->Data.fld_c_MBMS_Downlink_Ack_Nack = (c_MBMS_Downlink_Ack_Nack*)EDAlloc (sizeof (c_MBMS_Downlink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_MBMS_Downlink_Ack_Nack == NULL)
			INIT_c_MBMS_Downlink_Ack_Nack (sp->Data.fld_c_MBMS_Downlink_Ack_Nack);
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_Type_3: {
			sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 = (c_EGPRS_Packet_Downlink_Ack_Nack_Type_3*)EDAlloc (sizeof (c_EGPRS_Packet_Downlink_Ack_Nack_Type_3)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 == NULL)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3);
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_DLMC: {
			sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC = (c_EGPRS_Packet_Downlink_Ack_Nack_DLMC*)EDAlloc (sizeof (c_EGPRS_Packet_Downlink_Ack_Nack_DLMC)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC == NULL)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TUplink_RLC_MAC_Data (TUplink_RLC_MAC_Data* sp)
{
	switch (sp->Type) {
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Failure: {
			FREE_c_Packet_Cell_Change_Failure (sp->Data.fld_c_Packet_Cell_Change_Failure);
	EDFree (sp->Data.fld_c_Packet_Cell_Change_Failure );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement: {
			FREE_c_Packet_Control_Acknowledgement (sp->Data.fld_c_Packet_Control_Acknowledgement);
	EDFree (sp->Data.fld_c_Packet_Control_Acknowledgement );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_a: {
			FREE_c_Packet_Control_Acknowledgement_11bit_a (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_a);
	EDFree (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_a );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_b: {
			FREE_c_Packet_Control_Acknowledgement_11bit_b (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_b);
	EDFree (sp->Data.fld_c_Packet_Control_Acknowledgement_11bit_b );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_8bit: {
			FREE_c_Packet_Control_Acknowledgement_8bit (sp->Data.fld_c_Packet_Control_Acknowledgement_8bit);
	EDFree (sp->Data.fld_c_Packet_Control_Acknowledgement_8bit );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Downlink_Ack_Nack: {
			FREE_c_Packet_Downlink_Ack_Nack (sp->Data.fld_c_Packet_Downlink_Ack_Nack);
	EDFree (sp->Data.fld_c_Packet_Downlink_Ack_Nack );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Uplink_Dummy_Control_Block: {
			FREE_c_Packet_Uplink_Dummy_Control_Block (sp->Data.fld_c_Packet_Uplink_Dummy_Control_Block);
	EDFree (sp->Data.fld_c_Packet_Uplink_Dummy_Control_Block );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Measurement_Report: {
			FREE_c_Packet_Measurement_Report (sp->Data.fld_c_Packet_Measurement_Report);
	EDFree (sp->Data.fld_c_Packet_Measurement_Report );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Resource_Request: {
			FREE_c_Packet_Resource_Request (sp->Data.fld_c_Packet_Resource_Request);
	EDFree (sp->Data.fld_c_Packet_Resource_Request );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Mobile_TBF_Status: {
			FREE_c_Packet_Mobile_TBF_Status (sp->Data.fld_c_Packet_Mobile_TBF_Status);
	EDFree (sp->Data.fld_c_Packet_Mobile_TBF_Status );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_PSI_Status: {
			FREE_c_Packet_PSI_Status (sp->Data.fld_c_Packet_PSI_Status);
	EDFree (sp->Data.fld_c_Packet_PSI_Status );
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack: {
			FREE_c_EGPRS_Packet_Downlink_Ack_Nack (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack);
	EDFree (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Pause: {
			FREE_c_Packet_Pause (sp->Data.fld_c_Packet_Pause);
	EDFree (sp->Data.fld_c_Packet_Pause );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Enhanced_Measurement_Report: {
			FREE_c_Packet_Enhanced_Measurement_Report (sp->Data.fld_c_Packet_Enhanced_Measurement_Report);
	EDFree (sp->Data.fld_c_Packet_Enhanced_Measurement_Report );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Additional_MS_Radio_Access_Capabilities: {
			FREE_c_Additional_MS_Radio_Access_Capabilities (sp->Data.fld_c_Additional_MS_Radio_Access_Capabilities);
	EDFree (sp->Data.fld_c_Additional_MS_Radio_Access_Capabilities );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Notification: {
			FREE_c_Packet_Cell_Change_Notification (sp->Data.fld_c_Packet_Cell_Change_Notification);
	EDFree (sp->Data.fld_c_Packet_Cell_Change_Notification );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_SI_Status: {
			FREE_c_Packet_SI_Status (sp->Data.fld_c_Packet_SI_Status);
	EDFree (sp->Data.fld_c_Packet_SI_Status );
			break;
		}
		
		case ID_Uplink_RLC_MAC_Packet_CS_Request: {
			FREE_c_Packet_CS_Request (sp->Data.fld_c_Packet_CS_Request);
	EDFree (sp->Data.fld_c_Packet_CS_Request );
			break;
		}
		
		case ID_Uplink_RLC_MAC_MBMS_Service_Request: {
			FREE_c_MBMS_Service_Request (sp->Data.fld_c_MBMS_Service_Request);
	EDFree (sp->Data.fld_c_MBMS_Service_Request );
			break;
		}
		
		case ID_Uplink_RLC_MAC_MBMS_Downlink_Ack_Nack: {
			FREE_c_MBMS_Downlink_Ack_Nack (sp->Data.fld_c_MBMS_Downlink_Ack_Nack);
	EDFree (sp->Data.fld_c_MBMS_Downlink_Ack_Nack );
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_Type_3: {
			FREE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3);
	EDFree (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 );
			break;
		}
		
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_DLMC: {
			FREE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC);
	EDFree (sp->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC );
			break;
		}
		
		default:;
	}

	sp->Type = ID_Uplink_RLC_MAC_Unrecognized;
}

#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_Downlink_RLC_MAC (const char* buffer, TDownlink_RLC_MAC_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])>> 2/*2*/;/*3*/
	data->MessageType = (int)key;
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF3F) {
			/* Detect signal Packet_Cell_Change_Order */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Cell_Change_Order), != ED_NO_ERRORS)
			INIT_c_Packet_Cell_Change_Order (data->Data.fld_c_Packet_Cell_Change_Order);
			retLen = DECODE_c_Packet_Cell_Change_Order (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Order, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Downlink_Assignment */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Downlink_Assignment), != ED_NO_ERRORS)
			INIT_c_Packet_Downlink_Assignment (data->Data.fld_c_Packet_Downlink_Assignment);
			retLen = DECODE_c_Packet_Downlink_Assignment (buffer, 0, data->Data.fld_c_Packet_Downlink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Measurement_Order */
		case 0x0003: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Measurement_Order), != ED_NO_ERRORS)
			INIT_c_Packet_Measurement_Order (data->Data.fld_c_Packet_Measurement_Order);
			retLen = DECODE_c_Packet_Measurement_Order (buffer, 0, data->Data.fld_c_Packet_Measurement_Order, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Polling_Request */
		case 0x0004: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Polling_Request), != ED_NO_ERRORS)
			INIT_c_Packet_Polling_Request (data->Data.fld_c_Packet_Polling_Request);
			retLen = DECODE_c_Packet_Polling_Request (buffer, 0, data->Data.fld_c_Packet_Polling_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Power_Control_Timing_Advance */
		case 0x0005: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Power_Control_Timing_Advance), != ED_NO_ERRORS)
			INIT_c_Packet_Power_Control_Timing_Advance (data->Data.fld_c_Packet_Power_Control_Timing_Advance);
			retLen = DECODE_c_Packet_Power_Control_Timing_Advance (buffer, 0, data->Data.fld_c_Packet_Power_Control_Timing_Advance, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Queueing_Notification */
		case 0x0006: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Queueing_Notification), != ED_NO_ERRORS)
			INIT_c_Packet_Queueing_Notification (data->Data.fld_c_Packet_Queueing_Notification);
			retLen = DECODE_c_Packet_Queueing_Notification (buffer, 0, data->Data.fld_c_Packet_Queueing_Notification, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Timeslot_Reconfigure */
		case 0x0007: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Timeslot_Reconfigure), != ED_NO_ERRORS)
			INIT_c_Packet_Timeslot_Reconfigure (data->Data.fld_c_Packet_Timeslot_Reconfigure);
			retLen = DECODE_c_Packet_Timeslot_Reconfigure (buffer, 0, data->Data.fld_c_Packet_Timeslot_Reconfigure, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_TBF_Release */
		case 0x0008: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_TBF_Release), != ED_NO_ERRORS)
			INIT_c_Packet_TBF_Release (data->Data.fld_c_Packet_TBF_Release);
			retLen = DECODE_c_Packet_TBF_Release (buffer, 0, data->Data.fld_c_Packet_TBF_Release, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Uplink_Ack_Nack */
		case 0x0009: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Uplink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_Packet_Uplink_Ack_Nack (data->Data.fld_c_Packet_Uplink_Ack_Nack);
			retLen = DECODE_c_Packet_Uplink_Ack_Nack (buffer, 0, data->Data.fld_c_Packet_Uplink_Ack_Nack, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Uplink_Assignment */
		case 0x000A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Uplink_Assignment), != ED_NO_ERRORS)
			INIT_c_Packet_Uplink_Assignment (data->Data.fld_c_Packet_Uplink_Assignment);
			retLen = DECODE_c_Packet_Uplink_Assignment (buffer, 0, data->Data.fld_c_Packet_Uplink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Cell_Change_Continue */
		case 0x000B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Cell_Change_Continue), != ED_NO_ERRORS)
			INIT_c_Packet_Cell_Change_Continue (data->Data.fld_c_Packet_Cell_Change_Continue);
			retLen = DECODE_c_Packet_Cell_Change_Continue (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Continue, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Neighbour_Cell_Data */
		case 0x000C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Neighbour_Cell_Data), != ED_NO_ERRORS)
			INIT_c_Packet_Neighbour_Cell_Data (data->Data.fld_c_Packet_Neighbour_Cell_Data);
			retLen = DECODE_c_Packet_Neighbour_Cell_Data (buffer, 0, data->Data.fld_c_Packet_Neighbour_Cell_Data, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Serving_Cell_Data */
		case 0x000D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Serving_Cell_Data), != ED_NO_ERRORS)
			INIT_c_Packet_Serving_Cell_Data (data->Data.fld_c_Packet_Serving_Cell_Data);
			retLen = DECODE_c_Packet_Serving_Cell_Data (buffer, 0, data->Data.fld_c_Packet_Serving_Cell_Data, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_DBPSCH_Assignment */
		case 0x000E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_DBPSCH_Assignment), != ED_NO_ERRORS)
			INIT_c_Packet_DBPSCH_Assignment (data->Data.fld_c_Packet_DBPSCH_Assignment);
			retLen = DECODE_c_Packet_DBPSCH_Assignment (buffer, 0, data->Data.fld_c_Packet_DBPSCH_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal Multiple_TBF_Downlink_Assignment */
		case 0x000F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Multiple_TBF_Downlink_Assignment), != ED_NO_ERRORS)
			INIT_c_Multiple_TBF_Downlink_Assignment (data->Data.fld_c_Multiple_TBF_Downlink_Assignment);
			retLen = DECODE_c_Multiple_TBF_Downlink_Assignment (buffer, 0, data->Data.fld_c_Multiple_TBF_Downlink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Access_Reject */
		case 0x0021: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Access_Reject), != ED_NO_ERRORS)
			INIT_c_Packet_Access_Reject (data->Data.fld_c_Packet_Access_Reject);
			retLen = DECODE_c_Packet_Access_Reject (buffer, 0, data->Data.fld_c_Packet_Access_Reject, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Paging_Request */
		case 0x0022: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Paging_Request), != ED_NO_ERRORS)
			INIT_c_Packet_Paging_Request (data->Data.fld_c_Packet_Paging_Request);
			retLen = DECODE_c_Packet_Paging_Request (buffer, 0, data->Data.fld_c_Packet_Paging_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_PDCH_Release */
		case 0x0023: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_PDCH_Release), != ED_NO_ERRORS)
			INIT_c_Packet_PDCH_Release (data->Data.fld_c_Packet_PDCH_Release);
			retLen = DECODE_c_Packet_PDCH_Release (buffer, 0, data->Data.fld_c_Packet_PDCH_Release, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_PRACH_Parameters */
		case 0x0024: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_PRACH_Parameters), != ED_NO_ERRORS)
			INIT_c_Packet_PRACH_Parameters (data->Data.fld_c_Packet_PRACH_Parameters);
			retLen = DECODE_c_Packet_PRACH_Parameters (buffer, 0, data->Data.fld_c_Packet_PRACH_Parameters, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Downlink_Dummy_Control_Block */
		case 0x0025: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Downlink_Dummy_Control_Block), != ED_NO_ERRORS)
			INIT_c_Packet_Downlink_Dummy_Control_Block (data->Data.fld_c_Packet_Downlink_Dummy_Control_Block);
			retLen = DECODE_c_Packet_Downlink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_Packet_Downlink_Dummy_Control_Block, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI16 */
		case 0x0028: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI16), != ED_NO_ERRORS)
			INIT_c_PSI16 (data->Data.fld_c_PSI16);
			retLen = DECODE_c_PSI16 (buffer, 0, data->Data.fld_c_PSI16, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI6 */
		case 0x0030: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI6), != ED_NO_ERRORS)
			INIT_c_PSI6 (data->Data.fld_c_PSI6);
			retLen = DECODE_c_PSI6 (buffer, 0, data->Data.fld_c_PSI6, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI1 */
		case 0x0031: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI1), != ED_NO_ERRORS)
			INIT_c_PSI1 (data->Data.fld_c_PSI1);
			retLen = DECODE_c_PSI1 (buffer, 0, data->Data.fld_c_PSI1, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI2 */
		case 0x0032: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI2), != ED_NO_ERRORS)
			INIT_c_PSI2 (data->Data.fld_c_PSI2);
			retLen = DECODE_c_PSI2 (buffer, 0, data->Data.fld_c_PSI2, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI3 */
		case 0x0033: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI3), != ED_NO_ERRORS)
			INIT_c_PSI3 (data->Data.fld_c_PSI3);
			retLen = DECODE_c_PSI3 (buffer, 0, data->Data.fld_c_PSI3, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI3_bis */
		case 0x0034: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI3_bis), != ED_NO_ERRORS)
			INIT_c_PSI3_bis (data->Data.fld_c_PSI3_bis);
			retLen = DECODE_c_PSI3_bis (buffer, 0, data->Data.fld_c_PSI3_bis, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI4 */
		case 0x0035: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI4), != ED_NO_ERRORS)
			INIT_c_PSI4 (data->Data.fld_c_PSI4);
			retLen = DECODE_c_PSI4 (buffer, 0, data->Data.fld_c_PSI4, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI5 */
		case 0x0036: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI5), != ED_NO_ERRORS)
			INIT_c_PSI5 (data->Data.fld_c_PSI5);
			retLen = DECODE_c_PSI5 (buffer, 0, data->Data.fld_c_PSI5, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI13 */
		case 0x0037: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI13), != ED_NO_ERRORS)
			INIT_c_PSI13 (data->Data.fld_c_PSI13);
			retLen = DECODE_c_PSI13 (buffer, 0, data->Data.fld_c_PSI13, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI7 */
		case 0x0038: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI7), != ED_NO_ERRORS)
			INIT_c_PSI7 (data->Data.fld_c_PSI7);
			retLen = DECODE_c_PSI7 (buffer, 0, data->Data.fld_c_PSI7, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI8 */
		case 0x0039: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI8), != ED_NO_ERRORS)
			INIT_c_PSI8 (data->Data.fld_c_PSI8);
			retLen = DECODE_c_PSI8 (buffer, 0, data->Data.fld_c_PSI8, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI14 */
		case 0x003A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI14), != ED_NO_ERRORS)
			INIT_c_PSI14 (data->Data.fld_c_PSI14);
			retLen = DECODE_c_PSI14 (buffer, 0, data->Data.fld_c_PSI14, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI3_ter */
		case 0x003C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI3_ter), != ED_NO_ERRORS)
			INIT_c_PSI3_ter (data->Data.fld_c_PSI3_ter);
			retLen = DECODE_c_PSI3_ter (buffer, 0, data->Data.fld_c_PSI3_ter, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI3_quater */
		case 0x003D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI3_quater), != ED_NO_ERRORS)
			INIT_c_PSI3_quater (data->Data.fld_c_PSI3_quater);
			retLen = DECODE_c_PSI3_quater (buffer, 0, data->Data.fld_c_PSI3_quater, bitLen);
		
			return retLen;
		}
		/* Detect signal PSI15 */
		case 0x003E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PSI15), != ED_NO_ERRORS)
			INIT_c_PSI15 (data->Data.fld_c_PSI15);
			retLen = DECODE_c_PSI15 (buffer, 0, data->Data.fld_c_PSI15, bitLen);
		
			return retLen;
		}
		/* Detect signal Multiple_TBF_Uplink_Assignment */
		case 0x0010: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Multiple_TBF_Uplink_Assignment), != ED_NO_ERRORS)
			INIT_c_Multiple_TBF_Uplink_Assignment (data->Data.fld_c_Multiple_TBF_Uplink_Assignment);
			retLen = DECODE_c_Multiple_TBF_Uplink_Assignment (buffer, 0, data->Data.fld_c_Multiple_TBF_Uplink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal Multiple_TBF_Timeslot_Reconfigure */
		case 0x0011: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Multiple_TBF_Timeslot_Reconfigure), != ED_NO_ERRORS)
			INIT_c_Multiple_TBF_Timeslot_Reconfigure (data->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure);
			retLen = DECODE_c_Multiple_TBF_Timeslot_Reconfigure (buffer, 0, data->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_MS_ID_Assignment */
		case 0x0013: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_MBMS_MS_ID_Assignment), != ED_NO_ERRORS)
			INIT_c_MBMS_MS_ID_Assignment (data->Data.fld_c_MBMS_MS_ID_Assignment);
			retLen = DECODE_c_MBMS_MS_ID_Assignment (buffer, 0, data->Data.fld_c_MBMS_MS_ID_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_Assignment_Non_distribution */
		case 0x0014: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_MBMS_Assignment_Non_distribution), != ED_NO_ERRORS)
			INIT_c_MBMS_Assignment_Non_distribution (data->Data.fld_c_MBMS_Assignment_Non_distribution);
			retLen = DECODE_c_MBMS_Assignment_Non_distribution (buffer, 0, data->Data.fld_c_MBMS_Assignment_Non_distribution, bitLen);
		
			return retLen;
		}
		/* Detect signal PS_Handover_Command */
		case 0x0015: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_PS_Handover_Command), != ED_NO_ERRORS)
			INIT_c_PS_Handover_Command (data->Data.fld_c_PS_Handover_Command);
			retLen = DECODE_c_PS_Handover_Command (buffer, 0, data->Data.fld_c_PS_Handover_Command, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Physical_Information */
		case 0x0016: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Physical_Information), != ED_NO_ERRORS)
			INIT_c_Packet_Physical_Information (data->Data.fld_c_Packet_Physical_Information);
			retLen = DECODE_c_Packet_Physical_Information (buffer, 0, data->Data.fld_c_Packet_Physical_Information, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Serving_Cell_SI */
		case 0x0020: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_Serving_Cell_SI), != ED_NO_ERRORS)
			INIT_c_Packet_Serving_Cell_SI (data->Data.fld_c_Packet_Serving_Cell_SI);
			retLen = DECODE_c_Packet_Serving_Cell_SI (buffer, 0, data->Data.fld_c_Packet_Serving_Cell_SI, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_CS_Command */
		case 0x0027: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_CS_Command), != ED_NO_ERRORS)
			INIT_c_Packet_CS_Command (data->Data.fld_c_Packet_CS_Command);
			retLen = DECODE_c_Packet_CS_Command (buffer, 0, data->Data.fld_c_Packet_CS_Command, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_CS_Release */
		case 0x0029: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_CS_Release), != ED_NO_ERRORS)
			INIT_c_Packet_CS_Release (data->Data.fld_c_Packet_CS_Release);
			retLen = DECODE_c_Packet_CS_Release (buffer, 0, data->Data.fld_c_Packet_CS_Release, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_Assignment_Distribution */
		case 0x002A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_MBMS_Assignment_Distribution), != ED_NO_ERRORS)
			INIT_c_MBMS_Assignment_Distribution (data->Data.fld_c_MBMS_Assignment_Distribution);
			retLen = DECODE_c_MBMS_Assignment_Distribution (buffer, 0, data->Data.fld_c_MBMS_Assignment_Distribution, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_Neighbouring_Cell_Information */
		case 0x002B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_MBMS_Neighbouring_Cell_Information), != ED_NO_ERRORS)
			INIT_c_MBMS_Neighbouring_Cell_Information (data->Data.fld_c_MBMS_Neighbouring_Cell_Information);
			retLen = DECODE_c_MBMS_Neighbouring_Cell_Information (buffer, 0, data->Data.fld_c_MBMS_Neighbouring_Cell_Information, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_MBMS_Announcement */
		case 0x002C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_Data (data, ID_Downlink_RLC_MAC_Packet_MBMS_Announcement), != ED_NO_ERRORS)
			INIT_c_Packet_MBMS_Announcement (data->Data.fld_c_Packet_MBMS_Announcement);
			retLen = DECODE_c_Packet_MBMS_Announcement (buffer, 0, data->Data.fld_c_Packet_MBMS_Announcement, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_Downlink_RLC_MAC_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Downlink_RLC_MAC (const char* buffer, int len, TDownlink_RLC_MAC_Data* data)
	{
		if (SetDecode_Downlink_RLC_MAC (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_Downlink_RLC_MAC (char* buffer, ED_EXLONG bitOffset, TDownlink_RLC_MAC_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Order: {
			retLen = ENCODE_c_Packet_Cell_Change_Order (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Order);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Downlink_Assignment: {
			retLen = ENCODE_c_Packet_Downlink_Assignment (buffer, 0, data->Data.fld_c_Packet_Downlink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Measurement_Order: {
			retLen = ENCODE_c_Packet_Measurement_Order (buffer, 0, data->Data.fld_c_Packet_Measurement_Order);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Polling_Request: {
			retLen = ENCODE_c_Packet_Polling_Request (buffer, 0, data->Data.fld_c_Packet_Polling_Request);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Power_Control_Timing_Advance: {
			retLen = ENCODE_c_Packet_Power_Control_Timing_Advance (buffer, 0, data->Data.fld_c_Packet_Power_Control_Timing_Advance);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Queueing_Notification: {
			retLen = ENCODE_c_Packet_Queueing_Notification (buffer, 0, data->Data.fld_c_Packet_Queueing_Notification);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Timeslot_Reconfigure: {
			retLen = ENCODE_c_Packet_Timeslot_Reconfigure (buffer, 0, data->Data.fld_c_Packet_Timeslot_Reconfigure);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_TBF_Release: {
			retLen = ENCODE_c_Packet_TBF_Release (buffer, 0, data->Data.fld_c_Packet_TBF_Release);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Uplink_Ack_Nack: {
			retLen = ENCODE_c_Packet_Uplink_Ack_Nack (buffer, 0, data->Data.fld_c_Packet_Uplink_Ack_Nack);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Uplink_Assignment: {
			retLen = ENCODE_c_Packet_Uplink_Assignment (buffer, 0, data->Data.fld_c_Packet_Uplink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Cell_Change_Continue: {
			retLen = ENCODE_c_Packet_Cell_Change_Continue (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Continue);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Neighbour_Cell_Data: {
			retLen = ENCODE_c_Packet_Neighbour_Cell_Data (buffer, 0, data->Data.fld_c_Packet_Neighbour_Cell_Data);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_Data: {
			retLen = ENCODE_c_Packet_Serving_Cell_Data (buffer, 0, data->Data.fld_c_Packet_Serving_Cell_Data);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_DBPSCH_Assignment: {
			retLen = ENCODE_c_Packet_DBPSCH_Assignment (buffer, 0, data->Data.fld_c_Packet_DBPSCH_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_Multiple_TBF_Downlink_Assignment: {
			retLen = ENCODE_c_Multiple_TBF_Downlink_Assignment (buffer, 0, data->Data.fld_c_Multiple_TBF_Downlink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Access_Reject: {
			retLen = ENCODE_c_Packet_Access_Reject (buffer, 0, data->Data.fld_c_Packet_Access_Reject);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Paging_Request: {
			retLen = ENCODE_c_Packet_Paging_Request (buffer, 0, data->Data.fld_c_Packet_Paging_Request);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_PDCH_Release: {
			retLen = ENCODE_c_Packet_PDCH_Release (buffer, 0, data->Data.fld_c_Packet_PDCH_Release);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_PRACH_Parameters: {
			retLen = ENCODE_c_Packet_PRACH_Parameters (buffer, 0, data->Data.fld_c_Packet_PRACH_Parameters);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Downlink_Dummy_Control_Block: {
			retLen = ENCODE_c_Packet_Downlink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_Packet_Downlink_Dummy_Control_Block);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI16: {
			retLen = ENCODE_c_PSI16 (buffer, 0, data->Data.fld_c_PSI16);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI6: {
			retLen = ENCODE_c_PSI6 (buffer, 0, data->Data.fld_c_PSI6);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI1: {
			retLen = ENCODE_c_PSI1 (buffer, 0, data->Data.fld_c_PSI1);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI2: {
			retLen = ENCODE_c_PSI2 (buffer, 0, data->Data.fld_c_PSI2);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI3: {
			retLen = ENCODE_c_PSI3 (buffer, 0, data->Data.fld_c_PSI3);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI3_bis: {
			retLen = ENCODE_c_PSI3_bis (buffer, 0, data->Data.fld_c_PSI3_bis);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI4: {
			retLen = ENCODE_c_PSI4 (buffer, 0, data->Data.fld_c_PSI4);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI5: {
			retLen = ENCODE_c_PSI5 (buffer, 0, data->Data.fld_c_PSI5);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI13: {
			retLen = ENCODE_c_PSI13 (buffer, 0, data->Data.fld_c_PSI13);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI7: {
			retLen = ENCODE_c_PSI7 (buffer, 0, data->Data.fld_c_PSI7);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI8: {
			retLen = ENCODE_c_PSI8 (buffer, 0, data->Data.fld_c_PSI8);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI14: {
			retLen = ENCODE_c_PSI14 (buffer, 0, data->Data.fld_c_PSI14);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI3_ter: {
			retLen = ENCODE_c_PSI3_ter (buffer, 0, data->Data.fld_c_PSI3_ter);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI3_quater: {
			retLen = ENCODE_c_PSI3_quater (buffer, 0, data->Data.fld_c_PSI3_quater);
			break;
		}
		case ID_Downlink_RLC_MAC_PSI15: {
			retLen = ENCODE_c_PSI15 (buffer, 0, data->Data.fld_c_PSI15);
			break;
		}
		case ID_Downlink_RLC_MAC_Multiple_TBF_Uplink_Assignment: {
			retLen = ENCODE_c_Multiple_TBF_Uplink_Assignment (buffer, 0, data->Data.fld_c_Multiple_TBF_Uplink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_Multiple_TBF_Timeslot_Reconfigure: {
			retLen = ENCODE_c_Multiple_TBF_Timeslot_Reconfigure (buffer, 0, data->Data.fld_c_Multiple_TBF_Timeslot_Reconfigure);
			break;
		}
		case ID_Downlink_RLC_MAC_MBMS_MS_ID_Assignment: {
			retLen = ENCODE_c_MBMS_MS_ID_Assignment (buffer, 0, data->Data.fld_c_MBMS_MS_ID_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Non_distribution: {
			retLen = ENCODE_c_MBMS_Assignment_Non_distribution (buffer, 0, data->Data.fld_c_MBMS_Assignment_Non_distribution);
			break;
		}
		case ID_Downlink_RLC_MAC_PS_Handover_Command: {
			retLen = ENCODE_c_PS_Handover_Command (buffer, 0, data->Data.fld_c_PS_Handover_Command);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Physical_Information: {
			retLen = ENCODE_c_Packet_Physical_Information (buffer, 0, data->Data.fld_c_Packet_Physical_Information);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_Serving_Cell_SI: {
			retLen = ENCODE_c_Packet_Serving_Cell_SI (buffer, 0, data->Data.fld_c_Packet_Serving_Cell_SI);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_CS_Command: {
			retLen = ENCODE_c_Packet_CS_Command (buffer, 0, data->Data.fld_c_Packet_CS_Command);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_CS_Release: {
			retLen = ENCODE_c_Packet_CS_Release (buffer, 0, data->Data.fld_c_Packet_CS_Release);
			break;
		}
		case ID_Downlink_RLC_MAC_MBMS_Assignment_Distribution: {
			retLen = ENCODE_c_MBMS_Assignment_Distribution (buffer, 0, data->Data.fld_c_MBMS_Assignment_Distribution);
			break;
		}
		case ID_Downlink_RLC_MAC_MBMS_Neighbouring_Cell_Information: {
			retLen = ENCODE_c_MBMS_Neighbouring_Cell_Information (buffer, 0, data->Data.fld_c_MBMS_Neighbouring_Cell_Information);
			break;
		}
		case ID_Downlink_RLC_MAC_Packet_MBMS_Announcement: {
			retLen = ENCODE_c_Packet_MBMS_Announcement (buffer, 0, data->Data.fld_c_Packet_MBMS_Announcement);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_Uplink_RLC_MAC (const char* buffer, TUplink_RLC_MAC_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])>> 2/*2*/;/*3*/
	data->MessageType = (int)key;
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF3F) {
			/* Detect signal Packet_Cell_Change_Failure */
		case 0x0000: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Cell_Change_Failure), != ED_NO_ERRORS)
			INIT_c_Packet_Cell_Change_Failure (data->Data.fld_c_Packet_Cell_Change_Failure);
			retLen = DECODE_c_Packet_Cell_Change_Failure (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Failure, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Control_Acknowledgement */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement), != ED_NO_ERRORS)
			INIT_c_Packet_Control_Acknowledgement (data->Data.fld_c_Packet_Control_Acknowledgement);
			retLen = DECODE_c_Packet_Control_Acknowledgement (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Control_Acknowledgement_11bit_a */
		case 0x003F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_a), != ED_NO_ERRORS)
			INIT_c_Packet_Control_Acknowledgement_11bit_a (data->Data.fld_c_Packet_Control_Acknowledgement_11bit_a);
			retLen = DECODE_c_Packet_Control_Acknowledgement_11bit_a (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_11bit_a, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Control_Acknowledgement_11bit_b */
		case 0x0037: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_b), != ED_NO_ERRORS)
			INIT_c_Packet_Control_Acknowledgement_11bit_b (data->Data.fld_c_Packet_Control_Acknowledgement_11bit_b);
			retLen = DECODE_c_Packet_Control_Acknowledgement_11bit_b (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_11bit_b, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Control_Acknowledgement_8bit */
		case 0x001F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_8bit), != ED_NO_ERRORS)
			INIT_c_Packet_Control_Acknowledgement_8bit (data->Data.fld_c_Packet_Control_Acknowledgement_8bit);
			retLen = DECODE_c_Packet_Control_Acknowledgement_8bit (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_8bit, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Downlink_Ack_Nack */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Downlink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_Packet_Downlink_Ack_Nack (data->Data.fld_c_Packet_Downlink_Ack_Nack);
			retLen = DECODE_c_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_Packet_Downlink_Ack_Nack, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Uplink_Dummy_Control_Block */
		case 0x0003: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Uplink_Dummy_Control_Block), != ED_NO_ERRORS)
			INIT_c_Packet_Uplink_Dummy_Control_Block (data->Data.fld_c_Packet_Uplink_Dummy_Control_Block);
			retLen = DECODE_c_Packet_Uplink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_Packet_Uplink_Dummy_Control_Block, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Measurement_Report */
		case 0x0004: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Measurement_Report), != ED_NO_ERRORS)
			INIT_c_Packet_Measurement_Report (data->Data.fld_c_Packet_Measurement_Report);
			retLen = DECODE_c_Packet_Measurement_Report (buffer, 0, data->Data.fld_c_Packet_Measurement_Report, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Resource_Request */
		case 0x0005: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Resource_Request), != ED_NO_ERRORS)
			INIT_c_Packet_Resource_Request (data->Data.fld_c_Packet_Resource_Request);
			retLen = DECODE_c_Packet_Resource_Request (buffer, 0, data->Data.fld_c_Packet_Resource_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Mobile_TBF_Status */
		case 0x0006: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Mobile_TBF_Status), != ED_NO_ERRORS)
			INIT_c_Packet_Mobile_TBF_Status (data->Data.fld_c_Packet_Mobile_TBF_Status);
			retLen = DECODE_c_Packet_Mobile_TBF_Status (buffer, 0, data->Data.fld_c_Packet_Mobile_TBF_Status, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_PSI_Status */
		case 0x0007: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_PSI_Status), != ED_NO_ERRORS)
			INIT_c_Packet_PSI_Status (data->Data.fld_c_Packet_PSI_Status);
			retLen = DECODE_c_Packet_PSI_Status (buffer, 0, data->Data.fld_c_Packet_PSI_Status, bitLen);
		
			return retLen;
		}
		/* Detect signal EGPRS_Packet_Downlink_Ack_Nack */
		case 0x0008: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack (data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack);
			retLen = DECODE_c_EGPRS_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Pause */
		case 0x0009: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Pause), != ED_NO_ERRORS)
			INIT_c_Packet_Pause (data->Data.fld_c_Packet_Pause);
			retLen = DECODE_c_Packet_Pause (buffer, 0, data->Data.fld_c_Packet_Pause, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Enhanced_Measurement_Report */
		case 0x000A: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Enhanced_Measurement_Report), != ED_NO_ERRORS)
			INIT_c_Packet_Enhanced_Measurement_Report (data->Data.fld_c_Packet_Enhanced_Measurement_Report);
			retLen = DECODE_c_Packet_Enhanced_Measurement_Report (buffer, 0, data->Data.fld_c_Packet_Enhanced_Measurement_Report, bitLen);
		
			return retLen;
		}
		/* Detect signal Additional_MS_Radio_Access_Capabilities */
		case 0x000B: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Additional_MS_Radio_Access_Capabilities), != ED_NO_ERRORS)
			INIT_c_Additional_MS_Radio_Access_Capabilities (data->Data.fld_c_Additional_MS_Radio_Access_Capabilities);
			retLen = DECODE_c_Additional_MS_Radio_Access_Capabilities (buffer, 0, data->Data.fld_c_Additional_MS_Radio_Access_Capabilities, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_Cell_Change_Notification */
		case 0x000C: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_Cell_Change_Notification), != ED_NO_ERRORS)
			INIT_c_Packet_Cell_Change_Notification (data->Data.fld_c_Packet_Cell_Change_Notification);
			retLen = DECODE_c_Packet_Cell_Change_Notification (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Notification, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_SI_Status */
		case 0x000D: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_SI_Status), != ED_NO_ERRORS)
			INIT_c_Packet_SI_Status (data->Data.fld_c_Packet_SI_Status);
			retLen = DECODE_c_Packet_SI_Status (buffer, 0, data->Data.fld_c_Packet_SI_Status, bitLen);
		
			return retLen;
		}
		/* Detect signal Packet_CS_Request */
		case 0x000E: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_Packet_CS_Request), != ED_NO_ERRORS)
			INIT_c_Packet_CS_Request (data->Data.fld_c_Packet_CS_Request);
			retLen = DECODE_c_Packet_CS_Request (buffer, 0, data->Data.fld_c_Packet_CS_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_Service_Request */
		case 0x000F: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_MBMS_Service_Request), != ED_NO_ERRORS)
			INIT_c_MBMS_Service_Request (data->Data.fld_c_MBMS_Service_Request);
			retLen = DECODE_c_MBMS_Service_Request (buffer, 0, data->Data.fld_c_MBMS_Service_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal MBMS_Downlink_Ack_Nack */
		case 0x0010: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_MBMS_Downlink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_MBMS_Downlink_Ack_Nack (data->Data.fld_c_MBMS_Downlink_Ack_Nack);
			retLen = DECODE_c_MBMS_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_MBMS_Downlink_Ack_Nack, bitLen);
		
			return retLen;
		}
		/* Detect signal EGPRS_Packet_Downlink_Ack_Nack_Type_3 */
		case 0x0012: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_Type_3), != ED_NO_ERRORS)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3);
			retLen = DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3, bitLen);
		
			return retLen;
		}
		/* Detect signal EGPRS_Packet_Downlink_Ack_Nack_DLMC */
		case 0x0013: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_Data (data, ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_DLMC), != ED_NO_ERRORS)
			INIT_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC);
			retLen = DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_Uplink_RLC_MAC_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Uplink_RLC_MAC (const char* buffer, int len, TUplink_RLC_MAC_Data* data)
	{
		if (SetDecode_Uplink_RLC_MAC (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_Uplink_RLC_MAC (char* buffer, ED_EXLONG bitOffset, TUplink_RLC_MAC_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Failure: {
			retLen = ENCODE_c_Packet_Cell_Change_Failure (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Failure);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement: {
			retLen = ENCODE_c_Packet_Control_Acknowledgement (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_a: {
			retLen = ENCODE_c_Packet_Control_Acknowledgement_11bit_a (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_11bit_a);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_b: {
			retLen = ENCODE_c_Packet_Control_Acknowledgement_11bit_b (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_11bit_b);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_8bit: {
			retLen = ENCODE_c_Packet_Control_Acknowledgement_8bit (buffer, 0, data->Data.fld_c_Packet_Control_Acknowledgement_8bit);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Downlink_Ack_Nack: {
			retLen = ENCODE_c_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_Packet_Downlink_Ack_Nack);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Uplink_Dummy_Control_Block: {
			retLen = ENCODE_c_Packet_Uplink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_Packet_Uplink_Dummy_Control_Block);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Measurement_Report: {
			retLen = ENCODE_c_Packet_Measurement_Report (buffer, 0, data->Data.fld_c_Packet_Measurement_Report);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Resource_Request: {
			retLen = ENCODE_c_Packet_Resource_Request (buffer, 0, data->Data.fld_c_Packet_Resource_Request);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Mobile_TBF_Status: {
			retLen = ENCODE_c_Packet_Mobile_TBF_Status (buffer, 0, data->Data.fld_c_Packet_Mobile_TBF_Status);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_PSI_Status: {
			retLen = ENCODE_c_Packet_PSI_Status (buffer, 0, data->Data.fld_c_Packet_PSI_Status);
			break;
		}
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack: {
			retLen = ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Pause: {
			retLen = ENCODE_c_Packet_Pause (buffer, 0, data->Data.fld_c_Packet_Pause);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Enhanced_Measurement_Report: {
			retLen = ENCODE_c_Packet_Enhanced_Measurement_Report (buffer, 0, data->Data.fld_c_Packet_Enhanced_Measurement_Report);
			break;
		}
		case ID_Uplink_RLC_MAC_Additional_MS_Radio_Access_Capabilities: {
			retLen = ENCODE_c_Additional_MS_Radio_Access_Capabilities (buffer, 0, data->Data.fld_c_Additional_MS_Radio_Access_Capabilities);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_Cell_Change_Notification: {
			retLen = ENCODE_c_Packet_Cell_Change_Notification (buffer, 0, data->Data.fld_c_Packet_Cell_Change_Notification);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_SI_Status: {
			retLen = ENCODE_c_Packet_SI_Status (buffer, 0, data->Data.fld_c_Packet_SI_Status);
			break;
		}
		case ID_Uplink_RLC_MAC_Packet_CS_Request: {
			retLen = ENCODE_c_Packet_CS_Request (buffer, 0, data->Data.fld_c_Packet_CS_Request);
			break;
		}
		case ID_Uplink_RLC_MAC_MBMS_Service_Request: {
			retLen = ENCODE_c_MBMS_Service_Request (buffer, 0, data->Data.fld_c_MBMS_Service_Request);
			break;
		}
		case ID_Uplink_RLC_MAC_MBMS_Downlink_Ack_Nack: {
			retLen = ENCODE_c_MBMS_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_MBMS_Downlink_Ack_Nack);
			break;
		}
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_Type_3: {
			retLen = ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3);
			break;
		}
		case ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_DLMC: {
			retLen = ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (buffer, 0, data->Data.fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC);
			break;
		}

		default:;
	}
	return retLen;
}

