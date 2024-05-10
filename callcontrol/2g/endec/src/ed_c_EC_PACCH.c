/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_EC_PACCH.h"
#include "ed_lib.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


/* Free function for variable-sized sequence c_EC_Packet_Access_Reject_message_content_Additional_Reject */
void FREE_c_EC_Packet_Access_Reject_message_content_Additional_Reject (c_EC_Packet_Access_Reject_message_content_Additional_Reject* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
		if (sp->data[i]->Downlink_TFI_Present) {
		}
		if (sp->data[i]->WAIT_INDICATION_Present) {
		}
		if (sp->data[i]->WAIT__INDICATION_SIZE_Present) {
		}
		if (sp->data[i]->Ignore_Present) {
			if (sp->data[i]->Ignore->value != NULL) {
				EDFree (sp->data[i]->Ignore->value);
				sp->data[i]->Ignore->value = NULL;
			}
			sp->data[i]->Ignore->usedBits = 0;
			EDFree (sp->data[i]->Ignore);
		}
		EDFree (sp->data[i]);
		sp->data[i] = NULL;
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_EC_Packet_Access_Reject_message_content */
void FREE_c_EC_Packet_Access_Reject_message_content (c_EC_Packet_Access_Reject_message_content* sp) {
	int i0;
ED_WARNING_REMOVER(sp);
	if (sp->Reject_Present) {
		if (sp->Reject->Downlink_TFI_Present) {
		}
		if (sp->Reject->WAIT_INDICATION_Present) {
		}
		if (sp->Reject->WAIT__INDICATION_SIZE_Present) {
		}
		if (sp->Reject->Ignore_Present) {
			if (sp->Reject->Ignore->value != NULL) {
				EDFree (sp->Reject->Ignore->value);
				sp->Reject->Ignore->value = NULL;
			}
			sp->Reject->Ignore->usedBits = 0;
			EDFree (sp->Reject->Ignore);
		}
		EDFree (sp->Reject);
		sp->Reject = NULL;
		sp->Reject_Present = ED_FALSE;
	}
	for (i0=0; i0<sp->Additional_Reject.items; i0++) {
		if (sp->Additional_Reject.data[i0]->Downlink_TFI_Present) {
		}
		if (sp->Additional_Reject.data[i0]->WAIT_INDICATION_Present) {
		}
		if (sp->Additional_Reject.data[i0]->WAIT__INDICATION_SIZE_Present) {
		}
		if (sp->Additional_Reject.data[i0]->Ignore_Present) {
			if (sp->Additional_Reject.data[i0]->Ignore->value != NULL) {
				EDFree (sp->Additional_Reject.data[i0]->Ignore->value);
				sp->Additional_Reject.data[i0]->Ignore->value = NULL;
			}
			sp->Additional_Reject.data[i0]->Ignore->usedBits = 0;
			EDFree (sp->Additional_Reject.data[i0]->Ignore);
		}
		EDFree (sp->Additional_Reject.data[i0]);
		sp->Additional_Reject.data[i0] = NULL;
	}
	if (sp->Additional_Reject.data) {EDFree (sp->Additional_Reject.data); sp->Additional_Reject.data = NULL; sp->Additional_Reject.allocatedItems=0; /*FR02A*/}
	if (sp->Additional_Reject.data___LOCATOR) {EDFree (sp->Additional_Reject.data___LOCATOR); sp->Additional_Reject.data___LOCATOR = NULL; /*FR02AL*/}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject (c_EC_Packet_Access_Reject_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Reject_Present == present) return ED_NO_ERRORS;
	sp->Reject_Present = present;
	if (present) {
		/*-->*/sp->Reject = (c_EC_Packet_Access_Reject_message_content_Reject*)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Reject));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Reject)
		ED_RESET_MEM (sp->Reject, sizeof (c_EC_Packet_Access_Reject_message_content_Reject));
	} else {
		if (sp->Reject->Downlink_TFI_Present) {
		}
		if (sp->Reject->WAIT_INDICATION_Present) {
		}
		if (sp->Reject->WAIT__INDICATION_SIZE_Present) {
		}
		if (sp->Reject->Ignore_Present) {
			if (sp->Reject->Ignore->value != NULL) {
				EDFree (sp->Reject->Ignore->value);
				sp->Reject->Ignore->value = NULL;
			}
			sp->Reject->Ignore->usedBits = 0;
			EDFree (sp->Reject->Ignore);
		}
		EDFree (sp->Reject);
		sp->Reject = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Access_Reject_message_content_Distribution_part_error (c_EC_Packet_Access_Reject_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Access_Reject_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Control_Acknowledgement_message_content */
void FREE_c_EC_Packet_Control_Acknowledgement_message_content (c_EC_Packet_Control_Acknowledgement_message_content* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Ack_Nack_message_content */
void FREE_c_EC_Packet_Downlink_Ack_Nack_message_content (c_EC_Packet_Downlink_Ack_Nack_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->EC_Ack_Nack_Description_Present) {
		EDFree (sp->EC_Ack_Nack_Description);
		sp->EC_Ack_Nack_Description = NULL;
		sp->EC_Ack_Nack_Description_Present = ED_FALSE;
	}
	if (sp->EC_Channel_Quality_Report_Present) {
		if (sp->EC_Channel_Quality_Report->GMSK_MEAN_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->GMSK_CV_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->_8PSK_MEAN_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->_8PSK_CV_BEP_Present) {
		}
		EDFree (sp->EC_Channel_Quality_Report);
		sp->EC_Channel_Quality_Report = NULL;
		sp->EC_Channel_Quality_Report_Present = ED_FALSE;
	}
	if (sp->EC_Channel_Request_Description_Present) {
		EDFree (sp->EC_Channel_Request_Description);
		sp->EC_Channel_Request_Description = NULL;
		sp->EC_Channel_Request_Description_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description (c_EC_Packet_Downlink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Ack_Nack_Description_Present == present) return ED_NO_ERRORS;
	sp->EC_Ack_Nack_Description_Present = present;
	if (present) {
		/*-->*/sp->EC_Ack_Nack_Description = (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description*)EDAlloc (sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Ack_Nack_Description)
		ED_RESET_MEM (sp->EC_Ack_Nack_Description, sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description));
		(sp->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER) = 0;
		(sp->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP) = 0;
	} else {
		EDFree (sp->EC_Ack_Nack_Description);
		sp->EC_Ack_Nack_Description = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report (c_EC_Packet_Downlink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Channel_Quality_Report_Present == present) return ED_NO_ERRORS;
	sp->EC_Channel_Quality_Report_Present = present;
	if (present) {
		/*-->*/sp->EC_Channel_Quality_Report = (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report*)EDAlloc (sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Channel_Quality_Report)
		ED_RESET_MEM (sp->EC_Channel_Quality_Report, sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report));
		(sp->EC_Channel_Quality_Report->C_VALUE) = 0;
	} else {
		if (sp->EC_Channel_Quality_Report->GMSK_MEAN_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->GMSK_CV_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->_8PSK_MEAN_BEP_Present) {
		}
		if (sp->EC_Channel_Quality_Report->_8PSK_CV_BEP_Present) {
		}
		EDFree (sp->EC_Channel_Quality_Report);
		sp->EC_Channel_Quality_Report = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description (c_EC_Packet_Downlink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Channel_Request_Description_Present == present) return ED_NO_ERRORS;
	sp->EC_Channel_Request_Description_Present = present;
	if (present) {
		/*-->*/sp->EC_Channel_Request_Description = (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description*)EDAlloc (sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Channel_Request_Description)
		ED_RESET_MEM (sp->EC_Channel_Request_Description, sizeof (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description));
		(sp->EC_Channel_Request_Description->PRIORITY) = 0;
		(sp->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS) = 0;
	} else {
		EDFree (sp->EC_Channel_Request_Description);
		sp->EC_Channel_Request_Description = NULL;
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Downlink_Assignment_message_content */
void FREE_c_EC_Packet_Downlink_Assignment_message_content (c_EC_Packet_Downlink_Assignment_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Global_TFI_Present) {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
		sp->Global_TFI_Present = ED_FALSE;
	}
	if (sp->Frequency_Parameters_Present) {
		EDFree (sp->Frequency_Parameters);
		sp->Frequency_Parameters = NULL;
		sp->Frequency_Parameters_Present = ED_FALSE;
	}
	if (sp->EC_Packet_Timing_Advance_Present) {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
		sp->EC_Packet_Timing_Advance_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Message_escape_Present) {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
		sp->Message_escape_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Global_TFI_Present == present) return ED_NO_ERRORS;
	sp->Global_TFI_Present = present;
	if (present) {
		/*-->*/sp->Global_TFI = (c_EC_Packet_Downlink_Assignment_message_content_Global_TFI*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Global_TFI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Global_TFI)
		ED_RESET_MEM (sp->Global_TFI, sizeof (c_EC_Packet_Downlink_Assignment_message_content_Global_TFI));
	} else {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Frequency_Parameters_Present == present) return ED_NO_ERRORS;
	sp->Frequency_Parameters_Present = present;
	if (present) {
		/*-->*/sp->Frequency_Parameters = (c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Frequency_Parameters)
		ED_RESET_MEM (sp->Frequency_Parameters, sizeof (c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters));
		(sp->Frequency_Parameters->EC_MA_NUMBER) = 0;
		(sp->Frequency_Parameters->TSC) = 0;
		(sp->Frequency_Parameters->Primary_TSC_Set) = 0;
	} else {
		EDFree (sp->Frequency_Parameters);
		sp->Frequency_Parameters = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Packet_Timing_Advance_Present == present) return ED_NO_ERRORS;
	sp->EC_Packet_Timing_Advance_Present = present;
	if (present) {
		/*-->*/sp->EC_Packet_Timing_Advance = (c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Packet_Timing_Advance)
		ED_RESET_MEM (sp->EC_Packet_Timing_Advance, sizeof (c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance));
		(sp->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE) = 0;
	} else {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Message_escape (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Message_escape_Present == present) return ED_NO_ERRORS;
	sp->Message_escape_Present = present;
	if (present) {
		/*-->*/sp->Message_escape = (c_EC_Packet_Downlink_Assignment_message_content_Message_escape*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Message_escape));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Message_escape)
		
		sp->Message_escape->value = NULL;
		sp->Message_escape->usedBits = 0;
	} else {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error (c_EC_Packet_Downlink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Downlink_Dummy_Control_Block_message_content */
void FREE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (c_EC_Packet_Downlink_Dummy_Control_Block_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error (c_EC_Packet_Downlink_Dummy_Control_Block_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Polling_Request_message_content */
void FREE_c_EC_Packet_Polling_Request_message_content (c_EC_Packet_Polling_Request_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Global_TFI_Present) {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
		sp->Global_TFI_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Message_escape_Present) {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
		sp->Message_escape_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Polling_Request_message_content_Global_TFI (c_EC_Packet_Polling_Request_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Global_TFI_Present == present) return ED_NO_ERRORS;
	sp->Global_TFI_Present = present;
	if (present) {
		/*-->*/sp->Global_TFI = (c_EC_Packet_Polling_Request_message_content_Global_TFI*)EDAlloc (sizeof (c_EC_Packet_Polling_Request_message_content_Global_TFI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Global_TFI)
		ED_RESET_MEM (sp->Global_TFI, sizeof (c_EC_Packet_Polling_Request_message_content_Global_TFI));
	} else {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error (c_EC_Packet_Polling_Request_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Polling_Request_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Polling_Request_message_content_Address_information_part_error (c_EC_Packet_Polling_Request_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Polling_Request_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Polling_Request_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Polling_Request_message_content_Message_escape (c_EC_Packet_Polling_Request_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Message_escape_Present == present) return ED_NO_ERRORS;
	sp->Message_escape_Present = present;
	if (present) {
		/*-->*/sp->Message_escape = (c_EC_Packet_Polling_Request_message_content_Message_escape*)EDAlloc (sizeof (c_EC_Packet_Polling_Request_message_content_Message_escape));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Message_escape)
		
		sp->Message_escape->value = NULL;
		sp->Message_escape->usedBits = 0;
	} else {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Polling_Request_message_content_Distribution_part_error (c_EC_Packet_Polling_Request_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Polling_Request_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Polling_Request_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Power_Control_Timing_Advance_message_content */
void FREE_c_EC_Packet_Power_Control_Timing_Advance_message_content (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Global_TFI_Present) {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
		sp->Global_TFI_Present = ED_FALSE;
	}
	if (sp->EC_Packet_Timing_Advance_Present) {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
		sp->EC_Packet_Timing_Advance_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Global_TFI_Present == present) return ED_NO_ERRORS;
	sp->Global_TFI_Present = present;
	if (present) {
		/*-->*/sp->Global_TFI = (c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Global_TFI)
		ED_RESET_MEM (sp->Global_TFI, sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI));
	} else {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Packet_Timing_Advance_Present == present) return ED_NO_ERRORS;
	sp->EC_Packet_Timing_Advance_Present = present;
	if (present) {
		/*-->*/sp->EC_Packet_Timing_Advance = (c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Packet_Timing_Advance)
		ED_RESET_MEM (sp->EC_Packet_Timing_Advance, sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance));
		(sp->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE) = 0;
	} else {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error (c_EC_Packet_Power_Control_Timing_Advance_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_TBF_Release_message_content */
void FREE_c_EC_Packet_TBF_Release_message_content (c_EC_Packet_TBF_Release_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->GLOBAL_TFI_Present) {
		if (sp->GLOBAL_TFI->UPLINK_TFI_Present) {
		}
		if (sp->GLOBAL_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->GLOBAL_TFI);
		sp->GLOBAL_TFI = NULL;
		sp->GLOBAL_TFI_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI (c_EC_Packet_TBF_Release_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->GLOBAL_TFI_Present == present) return ED_NO_ERRORS;
	sp->GLOBAL_TFI_Present = present;
	if (present) {
		/*-->*/sp->GLOBAL_TFI = (c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI*)EDAlloc (sizeof (c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->GLOBAL_TFI)
		ED_RESET_MEM (sp->GLOBAL_TFI, sizeof (c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI));
	} else {
		if (sp->GLOBAL_TFI->UPLINK_TFI_Present) {
		}
		if (sp->GLOBAL_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->GLOBAL_TFI);
		sp->GLOBAL_TFI = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error (c_EC_Packet_TBF_Release_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_TBF_Release_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_TBF_Release_message_content_Address_information_part_error (c_EC_Packet_TBF_Release_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_TBF_Release_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_TBF_Release_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_TBF_Release_message_content_Distribution_part_error (c_EC_Packet_TBF_Release_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_TBF_Release_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_TBF_Release_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content (c_EC_Packet_Uplink_Ack_Nack_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->EC_Ack_Nack_Description_Present) {
		EDFree (sp->EC_Ack_Nack_Description);
		sp->EC_Ack_Nack_Description = NULL;
		sp->EC_Ack_Nack_Description_Present = ED_FALSE;
	}
	if (sp->EC_Primary_Ack_Nack_Description_Present) {
		EDFree (sp->EC_Primary_Ack_Nack_Description);
		sp->EC_Primary_Ack_Nack_Description = NULL;
		sp->EC_Primary_Ack_Nack_Description_Present = ED_FALSE;
	}
	if (sp->PUAN_Fixed_Uplink_Allocation_Present) {
		if (sp->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET_Present) {
		}
		if (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->PUAN_Fixed_Uplink_Allocation);
		sp->PUAN_Fixed_Uplink_Allocation = NULL;
		sp->PUAN_Fixed_Uplink_Allocation_Present = ED_FALSE;
	}
	if (sp->EGPRS_Channel_Coding_Command_Present) {
		EDFree (sp->EGPRS_Channel_Coding_Command);
		sp->EGPRS_Channel_Coding_Command = NULL;
		sp->EGPRS_Channel_Coding_Command_Present = ED_FALSE;
	}
	if (sp->EC_Packet_Timing_Advance_Present) {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
		sp->EC_Packet_Timing_Advance_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Ack_Nack_Description_Present == present) return ED_NO_ERRORS;
	sp->EC_Ack_Nack_Description_Present = present;
	if (present) {
		/*-->*/sp->EC_Ack_Nack_Description = (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Ack_Nack_Description)
		ED_RESET_MEM (sp->EC_Ack_Nack_Description, sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description));
		(sp->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER) = 0;
		(sp->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP) = 0;
	} else {
		EDFree (sp->EC_Ack_Nack_Description);
		sp->EC_Ack_Nack_Description = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Primary_Ack_Nack_Description_Present == present) return ED_NO_ERRORS;
	sp->EC_Primary_Ack_Nack_Description_Present = present;
	if (present) {
		/*-->*/sp->EC_Primary_Ack_Nack_Description = (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Primary_Ack_Nack_Description)
		ED_RESET_MEM (sp->EC_Primary_Ack_Nack_Description, sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description));
		(sp->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER) = 0;
		(sp->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP) = 0;
	} else {
		EDFree (sp->EC_Primary_Ack_Nack_Description);
		sp->EC_Primary_Ack_Nack_Description = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PUAN_Fixed_Uplink_Allocation_Present == present) return ED_NO_ERRORS;
	sp->PUAN_Fixed_Uplink_Allocation_Present = present;
	if (present) {
		/*-->*/sp->PUAN_Fixed_Uplink_Allocation = (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PUAN_Fixed_Uplink_Allocation)
		ED_RESET_MEM (sp->PUAN_Fixed_Uplink_Allocation, sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation));
		(sp->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK) = 0;
		sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items = 0;
	} else {
		if (sp->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET_Present) {
		}
		if (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->PUAN_Fixed_Uplink_Allocation);
		sp->PUAN_Fixed_Uplink_Allocation = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EGPRS_Channel_Coding_Command_Present == present) return ED_NO_ERRORS;
	sp->EGPRS_Channel_Coding_Command_Present = present;
	if (present) {
		/*-->*/sp->EGPRS_Channel_Coding_Command = (c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EGPRS_Channel_Coding_Command)
		ED_RESET_MEM (sp->EGPRS_Channel_Coding_Command, sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command));
		(sp->EGPRS_Channel_Coding_Command->Scheme) = 0;
	} else {
		EDFree (sp->EGPRS_Channel_Coding_Command);
		sp->EGPRS_Channel_Coding_Command = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Packet_Timing_Advance_Present == present) return ED_NO_ERRORS;
	sp->EC_Packet_Timing_Advance_Present = present;
	if (present) {
		/*-->*/sp->EC_Packet_Timing_Advance = (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Packet_Timing_Advance)
		ED_RESET_MEM (sp->EC_Packet_Timing_Advance, sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance));
		(sp->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE) = 0;
	} else {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error (c_EC_Packet_Uplink_Ack_Nack_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content */
void FREE_c_EC_Packet_Uplink_Assignment_message_content (c_EC_Packet_Uplink_Assignment_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Global_TFI_Present) {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
		sp->Global_TFI_Present = ED_FALSE;
	}
	if (sp->EGPRS_Channel_Coding_Command_Present) {
		EDFree (sp->EGPRS_Channel_Coding_Command);
		sp->EGPRS_Channel_Coding_Command = NULL;
		sp->EGPRS_Channel_Coding_Command_Present = ED_FALSE;
	}
	if (sp->EC_Packet_Timing_Advance_Present) {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
		sp->EC_Packet_Timing_Advance_Present = ED_FALSE;
	}
	if (sp->Frequency_Parameters_Present) {
		EDFree (sp->Frequency_Parameters);
		sp->Frequency_Parameters = NULL;
		sp->Frequency_Parameters_Present = ED_FALSE;
	}
	if (sp->Fixed_Uplink_Allocation_Present) {
		if (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->Fixed_Uplink_Allocation);
		sp->Fixed_Uplink_Allocation = NULL;
		sp->Fixed_Uplink_Allocation_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Message_escape_Present) {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
		sp->Message_escape_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Global_TFI_Present == present) return ED_NO_ERRORS;
	sp->Global_TFI_Present = present;
	if (present) {
		/*-->*/sp->Global_TFI = (c_EC_Packet_Uplink_Assignment_message_content_Global_TFI*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Global_TFI));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Global_TFI)
		ED_RESET_MEM (sp->Global_TFI, sizeof (c_EC_Packet_Uplink_Assignment_message_content_Global_TFI));
	} else {
		if (sp->Global_TFI->UPLINK_TFI_Present) {
		}
		if (sp->Global_TFI->DOWNLINK_TFI_Present) {
		}
		EDFree (sp->Global_TFI);
		sp->Global_TFI = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EGPRS_Channel_Coding_Command_Present == present) return ED_NO_ERRORS;
	sp->EGPRS_Channel_Coding_Command_Present = present;
	if (present) {
		/*-->*/sp->EGPRS_Channel_Coding_Command = (c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EGPRS_Channel_Coding_Command)
		ED_RESET_MEM (sp->EGPRS_Channel_Coding_Command, sizeof (c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command));
		(sp->EGPRS_Channel_Coding_Command->Scheme) = 0;
	} else {
		EDFree (sp->EGPRS_Channel_Coding_Command);
		sp->EGPRS_Channel_Coding_Command = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Packet_Timing_Advance_Present == present) return ED_NO_ERRORS;
	sp->EC_Packet_Timing_Advance_Present = present;
	if (present) {
		/*-->*/sp->EC_Packet_Timing_Advance = (c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Packet_Timing_Advance)
		ED_RESET_MEM (sp->EC_Packet_Timing_Advance, sizeof (c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance));
		(sp->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE) = 0;
	} else {
		EDFree (sp->EC_Packet_Timing_Advance);
		sp->EC_Packet_Timing_Advance = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Frequency_Parameters_Present == present) return ED_NO_ERRORS;
	sp->Frequency_Parameters_Present = present;
	if (present) {
		/*-->*/sp->Frequency_Parameters = (c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Frequency_Parameters)
		ED_RESET_MEM (sp->Frequency_Parameters, sizeof (c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters));
		(sp->Frequency_Parameters->EC_MA_NUMBER) = 0;
		(sp->Frequency_Parameters->TSC) = 0;
		(sp->Frequency_Parameters->Primary_TSC_Set) = 0;
	} else {
		EDFree (sp->Frequency_Parameters);
		sp->Frequency_Parameters = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Fixed_Uplink_Allocation_Present == present) return ED_NO_ERRORS;
	sp->Fixed_Uplink_Allocation_Present = present;
	if (present) {
		/*-->*/sp->Fixed_Uplink_Allocation = (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Fixed_Uplink_Allocation)
		ED_RESET_MEM (sp->Fixed_Uplink_Allocation, sizeof (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation));
		(sp->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK) = 0;
		sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items = 0;
	} else {
		if (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->Fixed_Uplink_Allocation);
		sp->Fixed_Uplink_Allocation = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Message_escape (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Message_escape_Present == present) return ED_NO_ERRORS;
	sp->Message_escape_Present = present;
	if (present) {
		/*-->*/sp->Message_escape = (c_EC_Packet_Uplink_Assignment_message_content_Message_escape*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Message_escape));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Message_escape)
		
		sp->Message_escape->value = NULL;
		sp->Message_escape->usedBits = 0;
	} else {
		if (sp->Message_escape->value != NULL) {
			EDFree (sp->Message_escape->value);
			sp->Message_escape->value = NULL;
		}
		sp->Message_escape->usedBits = 0;
		EDFree (sp->Message_escape);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error (c_EC_Packet_Uplink_Assignment_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for variable-sized sequence c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK */
void FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sp) {
	int i;
	for (i=0; i<sp->items; i++) {
	}

	if (sp->data) {EDFree (sp->data); sp->data=NULL; sp->allocatedItems = 0;/*FR03*/}

	if (sp->data___LOCATOR) {EDFree (sp->data___LOCATOR); sp->data___LOCATOR=NULL; /*FR03L*/}

}
/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content */
void FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->EC_Primary_Ack_Nack_Description_Present) {
		EDFree (sp->EC_Primary_Ack_Nack_Description);
		sp->EC_Primary_Ack_Nack_Description = NULL;
		sp->EC_Primary_Ack_Nack_Description_Present = ED_FALSE;
	}
	if (sp->PUANCR_Fixed_Uplink_Allocation_Present) {
		if (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->PUANCR_Fixed_Uplink_Allocation);
		sp->PUANCR_Fixed_Uplink_Allocation = NULL;
		sp->PUANCR_Fixed_Uplink_Allocation_Present = ED_FALSE;
	}
	if (sp->Non_distribution_part_error_Present) {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
		sp->Non_distribution_part_error_Present = ED_FALSE;
	}
	if (sp->Address_information_part_error_Present) {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
		sp->Address_information_part_error_Present = ED_FALSE;
	}
	if (sp->Distribution_part_error_Present) {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
		sp->Distribution_part_error_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->EC_Primary_Ack_Nack_Description_Present == present) return ED_NO_ERRORS;
	sp->EC_Primary_Ack_Nack_Description_Present = present;
	if (present) {
		/*-->*/sp->EC_Primary_Ack_Nack_Description = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->EC_Primary_Ack_Nack_Description)
		ED_RESET_MEM (sp->EC_Primary_Ack_Nack_Description, sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description));
		(sp->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER) = 0;
		(sp->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP) = 0;
	} else {
		EDFree (sp->EC_Primary_Ack_Nack_Description);
		sp->EC_Primary_Ack_Nack_Description = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->PUANCR_Fixed_Uplink_Allocation_Present == present) return ED_NO_ERRORS;
	sp->PUANCR_Fixed_Uplink_Allocation_Present = present;
	if (present) {
		/*-->*/sp->PUANCR_Fixed_Uplink_Allocation = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->PUANCR_Fixed_Uplink_Allocation)
		ED_RESET_MEM (sp->PUANCR_Fixed_Uplink_Allocation, sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation));
		(sp->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK) = 0;
		sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items = 0;
	} else {
		if (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
		if (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}
		EDFree (sp->PUANCR_Fixed_Uplink_Allocation);
		sp->PUANCR_Fixed_Uplink_Allocation = NULL;
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Non_distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Non_distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Non_distribution_part_error = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Non_distribution_part_error)
		
		sp->Non_distribution_part_error->value = NULL;
		sp->Non_distribution_part_error->usedBits = 0;
	} else {
		if (sp->Non_distribution_part_error->value != NULL) {
			EDFree (sp->Non_distribution_part_error->value);
			sp->Non_distribution_part_error->value = NULL;
		}
		sp->Non_distribution_part_error->usedBits = 0;
		EDFree (sp->Non_distribution_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Address_information_part_error_Present == present) return ED_NO_ERRORS;
	sp->Address_information_part_error_Present = present;
	if (present) {
		/*-->*/sp->Address_information_part_error = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Address_information_part_error)
		
		sp->Address_information_part_error->value = NULL;
		sp->Address_information_part_error->usedBits = 0;
	} else {
		if (sp->Address_information_part_error->value != NULL) {
			EDFree (sp->Address_information_part_error->value);
			sp->Address_information_part_error->value = NULL;
		}
		sp->Address_information_part_error->usedBits = 0;
		EDFree (sp->Address_information_part_error);
	}
	return ED_NO_ERRORS;
}

int SETPRESENT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Distribution_part_error_Present == present) return ED_NO_ERRORS;
	sp->Distribution_part_error_Present = present;
	if (present) {
		/*-->*/sp->Distribution_part_error = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Distribution_part_error)
		
		sp->Distribution_part_error->value = NULL;
		sp->Distribution_part_error->usedBits = 0;
	} else {
		if (sp->Distribution_part_error->value != NULL) {
			EDFree (sp->Distribution_part_error->value);
			sp->Distribution_part_error->value = NULL;
		}
		sp->Distribution_part_error->usedBits = 0;
		EDFree (sp->Distribution_part_error);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Access_Reject */
void FREE_c_EC_Packet_Access_Reject (c_EC_Packet_Access_Reject* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Access_Reject_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Downlink_Assignment */
void FREE_c_EC_Packet_Downlink_Assignment (c_EC_Packet_Downlink_Assignment* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Downlink_Assignment_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Polling_Request */
void FREE_c_EC_Packet_Polling_Request (c_EC_Packet_Polling_Request* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Polling_Request_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Power_Control_Timing_Advance */
void FREE_c_EC_Packet_Power_Control_Timing_Advance (c_EC_Packet_Power_Control_Timing_Advance* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Power_Control_Timing_Advance_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_TBF_Release */
void FREE_c_EC_Packet_TBF_Release (c_EC_Packet_TBF_Release* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_TBF_Release_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack */
void FREE_c_EC_Packet_Uplink_Ack_Nack (c_EC_Packet_Uplink_Ack_Nack* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Uplink_Ack_Nack_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Uplink_Assignment */
void FREE_c_EC_Packet_Uplink_Assignment (c_EC_Packet_Uplink_Assignment* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Uplink_Assignment_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution */
void FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Downlink_Dummy_Control_Block */
void FREE_c_EC_Packet_Downlink_Dummy_Control_Block (c_EC_Packet_Downlink_Dummy_Control_Block* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Control_Acknowledgement */
void FREE_c_EC_Packet_Control_Acknowledgement (c_EC_Packet_Control_Acknowledgement* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Control_Acknowledgement_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Downlink_Ack_Nack */
void FREE_c_EC_Packet_Downlink_Ack_Nack (c_EC_Packet_Downlink_Ack_Nack* sp) {
ED_WARNING_REMOVER(sp);
	FREE_c_EC_Packet_Downlink_Ack_Nack_message_content (&(sp->contents));

}

/* Free function for struct c_EC_Packet_Control_Acknowledgement_11_bit_message */
void FREE_c_EC_Packet_Control_Acknowledgement_11_bit_message (c_EC_Packet_Control_Acknowledgement_11_bit_message* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_GenericTLV_EC_PACCH */
void FREE_c_GenericTLV_EC_PACCH (c_GenericTLV_EC_PACCH* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->TLV_Data.value != NULL) {
		EDFree (sp->TLV_Data.value);
		sp->TLV_Data.value = NULL;
	}
	sp->TLV_Data.usedBits = 0;

}

/* Free function for struct c_EC_Packet_Access_Reject_message_content_Reject */
void FREE_c_EC_Packet_Access_Reject_message_content_Reject (c_EC_Packet_Access_Reject_message_content_Reject* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Ignore_Present) {
		if (sp->Ignore->value != NULL) {
			EDFree (sp->Ignore->value);
			sp->Ignore->value = NULL;
		}
		sp->Ignore->usedBits = 0;
		EDFree (sp->Ignore);
		sp->Ignore_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Access_Reject_message_content_Reject_Ignore (c_EC_Packet_Access_Reject_message_content_Reject* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Ignore_Present == present) return ED_NO_ERRORS;
	sp->Ignore_Present = present;
	if (present) {
		/*-->*/sp->Ignore = (c_EC_Packet_Access_Reject_message_content_Reject_Ignore*)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Reject_Ignore));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Ignore)
		
		sp->Ignore->value = NULL;
		sp->Ignore->usedBits = 0;
	} else {
		if (sp->Ignore->value != NULL) {
			EDFree (sp->Ignore->value);
			sp->Ignore->value = NULL;
		}
		sp->Ignore->usedBits = 0;
		EDFree (sp->Ignore);
	}
	return ED_NO_ERRORS;
}

/* SETITEMS commands for type 'c_EC_Packet_Access_Reject_message_content_Additional_Reject'. Existing items are not changed. */
int SETITEMS_c_EC_Packet_Access_Reject_message_content_Additional_Reject (c_EC_Packet_Access_Reject_message_content_Additional_Reject* sequence, int desiredItems)
{
	int i;
	/* ALK-UNI */
	if (sequence->allocatedItems < desiredItems) {
		ED_LOCATOR* tmpLoc;
		int newSize = desiredItems + 0;
		c_EC_Packet_Access_Reject_message_content_Additional_Reject_data** tmp;
		tmp = (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data**)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data*) * (size_t)(newSize));
		ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == tmp)
		if (sequence->data) {
			if (tmp != NULL && sequence->items > 0) {
				ED_MEM_COPY (tmp, sequence->data, sizeof (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data*) * (size_t)sequence->items);
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
			sequence->data[i] = (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data*)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data));
			ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sequence->data[i])
			ED_RESET_MEM (sequence->data[i], sizeof (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data));
			
			sequence->data___LOCATOR[i] = ED_STANDARD_LOCATOR_INVALID;
		}
	}
	 else {
		for (i=desiredItems; i<sequence->items; i++) {
				if (sequence->data[i]->Downlink_TFI_Present) {
				}
				if (sequence->data[i]->WAIT_INDICATION_Present) {
				}
				if (sequence->data[i]->WAIT__INDICATION_SIZE_Present) {
				}
				if (sequence->data[i]->Ignore_Present) {
					if (sequence->data[i]->Ignore->value != NULL) {
						EDFree (sequence->data[i]->Ignore->value);
						sequence->data[i]->Ignore->value = NULL;
					}
					sequence->data[i]->Ignore->usedBits = 0;
					EDFree (sequence->data[i]->Ignore);
				}
				EDFree (sequence->data[i]);
				sequence->data[i] = NULL;
			}
	}

	sequence->items = desiredItems;
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Access_Reject_message_content_Additional_Reject_data */
void FREE_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->Ignore_Present) {
		if (sp->Ignore->value != NULL) {
			EDFree (sp->Ignore->value);
			sp->Ignore->value = NULL;
		}
		sp->Ignore->usedBits = 0;
		EDFree (sp->Ignore);
		sp->Ignore_Present = ED_FALSE;
	}

}

int SETPRESENT_c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data* sp, ED_BOOLEAN present)
{
	/* Do nothing if already compliant to the request */
	if (sp->Ignore_Present == present) return ED_NO_ERRORS;
	sp->Ignore_Present = present;
	if (present) {
		/*-->*/sp->Ignore = (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore*)EDAlloc (sizeof (c_EC_Packet_Access_Reject_message_content_Additional_Reject_data_Ignore));ED_CHECK_OUT_OF_MEMORY_DISCARD(NULL == sp->Ignore)
		
		sp->Ignore->value = NULL;
		sp->Ignore->usedBits = 0;
	} else {
		if (sp->Ignore->value != NULL) {
			EDFree (sp->Ignore->value);
			sp->Ignore->value = NULL;
		}
		sp->Ignore->usedBits = 0;
		EDFree (sp->Ignore);
	}
	return ED_NO_ERRORS;
}

/* Free function for struct c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description */
void FREE_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report */
void FREE_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description */
void FREE_c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description (c_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Assignment_message_content_Global_TFI */
void FREE_c_EC_Packet_Downlink_Assignment_message_content_Global_TFI (c_EC_Packet_Downlink_Assignment_message_content_Global_TFI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters */
void FREE_c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters (c_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance */
void FREE_c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Polling_Request_message_content_Global_TFI */
void FREE_c_EC_Packet_Polling_Request_message_content_Global_TFI (c_EC_Packet_Polling_Request_message_content_Global_TFI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI */
void FREE_c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI (c_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance */
void FREE_c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI */
void FREE_c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI (c_EC_Packet_TBF_Release_message_content_GLOBAL_TFI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK'. Existing items are not changed. */
int SETITEMS_c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sequence, int desiredItems)
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

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command (c_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance */
void FREE_c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content_Global_TFI */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_Global_TFI (c_EC_Packet_Uplink_Assignment_message_content_Global_TFI* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command (c_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance (c_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters (c_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation */
void FREE_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK'. Existing items are not changed. */
int SETITEMS_c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sequence, int desiredItems)
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

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description */
void FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description* sp) {
ED_WARNING_REMOVER(sp);

}

/* Free function for struct c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation */
void FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation* sp) {
ED_WARNING_REMOVER(sp);
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data = NULL; sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.allocatedItems=0; /*FR02A*/}
	if (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR) {EDFree (sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR); sp->DELAY_NEXT_UL_RLC_DATA_BLOCK.data___LOCATOR = NULL; /*FR02AL*/}

}

/* SETITEMS commands for type 'c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK'. Existing items are not changed. */
int SETITEMS_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_DELAY_NEXT_UL_RLC_DATA_BLOCK* sequence, int desiredItems)
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

