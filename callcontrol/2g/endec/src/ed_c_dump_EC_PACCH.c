/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_dump_EC_PACCH.h"
#include "ed_dump_val.h"

#define DUMPSTR(a) OStream->WriteString (OStream, a)
void Dump_c_EC_Packet_Access_Reject_message_content (TEDOStream* OStream, const c_EC_Packet_Access_Reject_message_content* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Access_Reject_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content", "Reject");
	if (!Data->Reject_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Access_Reject_message_content_Reject");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "Downlink_TFI");
		if (!Data->Reject->Downlink_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_TFI> ACCESS=<Data->Reject->Downlink_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Reject->Downlink_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "Downlink_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "WAIT_INDICATION");
		if (!Data->Reject->WAIT_INDICATION_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<WAIT_INDICATION> ACCESS=<Data->Reject->WAIT_INDICATION>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Reject->WAIT_INDICATION);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "WAIT_INDICATION");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "WAIT__INDICATION_SIZE");
		if (!Data->Reject->WAIT__INDICATION_SIZE_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<WAIT__INDICATION_SIZE> ACCESS=<Data->Reject->WAIT__INDICATION_SIZE>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->Reject->WAIT__INDICATION_SIZE);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "WAIT__INDICATION_SIZE");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "Ignore");
		if (!Data->Reject->Ignore_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* NAME=<Ignore> ACCESS=<*(Data->Reject->Ignore)>  MAXBITSIZE=<64> OPTIONAL=<1> */
		  ED_Dump_Binary (OStream, Data->Reject->Ignore->value, Data->Reject->Ignore->usedBits);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Reject", "Ignore");
		ED_Dump_Struct_End (OStream, "EC_Packet_Access_Reject_message_content_Reject");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content", "Reject");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content", "Additional_Reject");
		/* SEQUENCE NAME=<Additional_Reject> ACCESS=<Data->Additional_Reject>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Additional_Reject", Data->Additional_Reject.items);
		for (i0=0; i0<Data->Additional_Reject.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Additional_Reject", i0, Data->Additional_Reject.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data");
			ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "Downlink_TFI");
			if (!Data->Additional_Reject.data [i0]->Downlink_TFI_Present) ED_Dump_Not_Present (OStream);
			else {
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_TFI> ACCESS=<Data->Additional_Reject.data [i0]->Downlink_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->Additional_Reject.data [i0]->Downlink_TFI);
			}
			ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "Downlink_TFI");
			ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "WAIT_INDICATION");
			if (!Data->Additional_Reject.data [i0]->WAIT_INDICATION_Present) ED_Dump_Not_Present (OStream);
			else {
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<WAIT_INDICATION> ACCESS=<Data->Additional_Reject.data [i0]->WAIT_INDICATION>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->Additional_Reject.data [i0]->WAIT_INDICATION);
			}
			ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "WAIT_INDICATION");
			ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "WAIT__INDICATION_SIZE");
			if (!Data->Additional_Reject.data [i0]->WAIT__INDICATION_SIZE_Present) ED_Dump_Not_Present (OStream);
			else {
			  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<WAIT__INDICATION_SIZE> ACCESS=<Data->Additional_Reject.data [i0]->WAIT__INDICATION_SIZE>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
			  ED_Dump_Boolean (OStream, Data->Additional_Reject.data [i0]->WAIT__INDICATION_SIZE);
			}
			ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "WAIT__INDICATION_SIZE");
			ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "Ignore");
			if (!Data->Additional_Reject.data [i0]->Ignore_Present) ED_Dump_Not_Present (OStream);
			else {
			  /* NAME=<Ignore> ACCESS=<*(Data->Additional_Reject.data [i0]->Ignore)>  MAXBITSIZE=<64> OPTIONAL=<1> */
			  ED_Dump_Binary (OStream, Data->Additional_Reject.data [i0]->Ignore->value, Data->Additional_Reject.data [i0]->Ignore->usedBits);
			}
			ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data", "Ignore");
			ED_Dump_Struct_End (OStream, "EC_Packet_Access_Reject_message_content_Additional_Reject_data");
			ED_Dump_Sequence_End_Field (OStream, "Additional_Reject", i0, Data->Additional_Reject.items);
		}
		ED_Dump_Sequence_End (OStream, "Additional_Reject", Data->Additional_Reject.items);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content", "Additional_Reject");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Access_Reject_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Control_Acknowledgement_message_content (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Control_Acknowledgement_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "TLLI");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TLLI> ACCESS=<Data->TLLI>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TLLI);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "TLLI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "CTRL_ACK");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CTRL_ACK> ACCESS=<Data->CTRL_ACK>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CTRL_ACK);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "CTRL_ACK");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "DL_CC_EST");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_CC_EST> ACCESS=<Data->DL_CC_EST>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_CC_EST);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement_message_content", "DL_CC_EST");
	ED_Dump_Struct_End (OStream, "EC_Packet_Control_Acknowledgement_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Ack_Nack_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Ack_Nack_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Ack_Nack_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "DOWNLINK_TFI");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->DOWNLINK_TFI>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DOWNLINK_TFI);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "DOWNLINK_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "MS_OUT_OF_MEMORY");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MS_OUT_OF_MEMORY> ACCESS=<Data->MS_OUT_OF_MEMORY>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MS_OUT_OF_MEMORY);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "MS_OUT_OF_MEMORY");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Ack_Nack_Description");
	if (!Data->EC_Ack_Nack_Description_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_SEQUENCE_NUMBER> ACCESS=<Data->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<RECEIVED_BLOCK_BITMAP> ACCESS=<Data->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Ack_Nack_Description");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Channel_Quality_Report");
	if (!Data->EC_Channel_Quality_Report_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "GMSK_MEAN_BEP");
		if (!Data->EC_Channel_Quality_Report->GMSK_MEAN_BEP_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_MEAN_BEP> ACCESS=<Data->EC_Channel_Quality_Report->GMSK_MEAN_BEP>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Quality_Report->GMSK_MEAN_BEP);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "GMSK_MEAN_BEP");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "GMSK_CV_BEP");
		if (!Data->EC_Channel_Quality_Report->GMSK_CV_BEP_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_CV_BEP> ACCESS=<Data->EC_Channel_Quality_Report->GMSK_CV_BEP>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Quality_Report->GMSK_CV_BEP);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "GMSK_CV_BEP");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "_8PSK_MEAN_BEP");
		if (!Data->EC_Channel_Quality_Report->_8PSK_MEAN_BEP_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8PSK_MEAN_BEP> ACCESS=<Data->EC_Channel_Quality_Report->_8PSK_MEAN_BEP>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Quality_Report->_8PSK_MEAN_BEP);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "_8PSK_MEAN_BEP");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "_8PSK_CV_BEP");
		if (!Data->EC_Channel_Quality_Report->_8PSK_CV_BEP_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8PSK_CV_BEP> ACCESS=<Data->EC_Channel_Quality_Report->_8PSK_CV_BEP>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Quality_Report->_8PSK_CV_BEP);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "_8PSK_CV_BEP");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "C_VALUE");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<C_VALUE> ACCESS=<Data->EC_Channel_Quality_Report->C_VALUE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Quality_Report->C_VALUE);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report", "C_VALUE");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Channel_Quality_Report");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "DL_CC_EST");
	if (!Data->DL_CC_EST_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_CC_EST> ACCESS=<Data->DL_CC_EST>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_CC_EST);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "DL_CC_EST");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Channel_Request_Description");
	if (!Data->EC_Channel_Request_Description_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description", "PRIORITY");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PRIORITY> ACCESS=<Data->EC_Channel_Request_Description->PRIORITY>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->EC_Channel_Request_Description->PRIORITY);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description", "PRIORITY");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description", "NUMBER_OF_UL_DATA_BLOCKS");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NUMBER_OF_UL_DATA_BLOCKS> ACCESS=<Data->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Channel_Request_Description->NUMBER_OF_UL_DATA_BLOCKS);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description", "NUMBER_OF_UL_DATA_BLOCKS");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack_message_content", "EC_Channel_Request_Description");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Ack_Nack_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Assignment_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Assignment_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Assignment_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Global_TFI");
	if (!Data->Global_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI", "UPLINK_TFI");
		if (!Data->Global_TFI->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->Global_TFI->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->UPLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI", "UPLINK_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI", "DOWNLINK_TFI");
		if (!Data->Global_TFI->DOWNLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->Global_TFI->DOWNLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->DOWNLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI", "DOWNLINK_TFI");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Assignment_message_content_Global_TFI");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Global_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "CONTROL_ACK");
	if (!Data->CONTROL_ACK_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CONTROL_ACK> ACCESS=<Data->CONTROL_ACK>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CONTROL_ACK);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "CONTROL_ACK");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Frequency_Parameters");
	if (!Data->Frequency_Parameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "EC_MA_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EC_MA_NUMBER> ACCESS=<Data->Frequency_Parameters->EC_MA_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Frequency_Parameters->EC_MA_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "EC_MA_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "TSC");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TSC> ACCESS=<Data->Frequency_Parameters->TSC>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Frequency_Parameters->TSC);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "TSC");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "Primary_TSC_Set");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Primary_TSC_Set> ACCESS=<Data->Frequency_Parameters->Primary_TSC_Set>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->Frequency_Parameters->Primary_TSC_Set);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters", "Primary_TSC_Set");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Frequency_Parameters");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "DL_COVERAGE_CLASS");
	if (!Data->DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_COVERAGE_CLASS> ACCESS=<Data->DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "STARTING_DL_TIMESLOT");
	if (!Data->STARTING_DL_TIMESLOT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_DL_TIMESLOT> ACCESS=<Data->STARTING_DL_TIMESLOT>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_DL_TIMESLOT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "STARTING_DL_TIMESLOT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "TIMESLOT_MULTIPLICATOR");
	if (!Data->TIMESLOT_MULTIPLICATOR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMESLOT_MULTIPLICATOR> ACCESS=<Data->TIMESLOT_MULTIPLICATOR>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TIMESLOT_MULTIPLICATOR);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "TIMESLOT_MULTIPLICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "DOWNLINK_TFI_ASSIGNMENT");
	if (!Data->DOWNLINK_TFI_ASSIGNMENT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI_ASSIGNMENT> ACCESS=<Data->DOWNLINK_TFI_ASSIGNMENT>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DOWNLINK_TFI_ASSIGNMENT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "DOWNLINK_TFI_ASSIGNMENT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "UL_COVERAGE_CLASS");
	if (!Data->UL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UL_COVERAGE_CLASS> ACCESS=<Data->UL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "UL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "STARTING_UL_TIMESLOT_OFFSET");
	if (!Data->STARTING_UL_TIMESLOT_OFFSET_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_UL_TIMESLOT_OFFSET> ACCESS=<Data->STARTING_UL_TIMESLOT_OFFSET>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_UL_TIMESLOT_OFFSET);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "STARTING_UL_TIMESLOT_OFFSET");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "EC_Packet_Timing_Advance");
	if (!Data->EC_Packet_Timing_Advance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMING_ADVANCE_VALUE> ACCESS=<Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "EC_Packet_Timing_Advance");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "P0");
	if (!Data->P0_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<P0> ACCESS=<Data->P0>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->P0);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "P0");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "PR_MODE");
	if (!Data->PR_MODE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PR_MODE> ACCESS=<Data->PR_MODE>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PR_MODE);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "PR_MODE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "GAMMA");
	if (!Data->GAMMA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GAMMA> ACCESS=<Data->GAMMA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GAMMA);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "GAMMA");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "ALPHA_Enable");
	if (!Data->ALPHA_Enable_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ALPHA_Enable> ACCESS=<Data->ALPHA_Enable>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ALPHA_Enable);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "ALPHA_Enable");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Message_escape");
	if (!Data->Message_escape_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Message_escape> ACCESS=<*(Data->Message_escape)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Message_escape->value, Data->Message_escape->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Message_escape");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Assignment_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Dummy_Control_Block_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Dummy_Control_Block_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Polling_Request_message_content (TEDOStream* OStream, const c_EC_Packet_Polling_Request_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Polling_Request_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "Global_TFI");
	if (!Data->Global_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI", "UPLINK_TFI");
		if (!Data->Global_TFI->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->Global_TFI->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->UPLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI", "UPLINK_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI", "DOWNLINK_TFI");
		if (!Data->Global_TFI->DOWNLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->Global_TFI->DOWNLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->DOWNLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI", "DOWNLINK_TFI");
		ED_Dump_Struct_End (OStream, "EC_Packet_Polling_Request_message_content_Global_TFI");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "Global_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "TYPE_OF_ACK");
	if (!Data->TYPE_OF_ACK_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TYPE_OF_ACK> ACCESS=<Data->TYPE_OF_ACK>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TYPE_OF_ACK);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "TYPE_OF_ACK");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "Message_escape");
	if (!Data->Message_escape_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Message_escape> ACCESS=<*(Data->Message_escape)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Message_escape->value, Data->Message_escape->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "Message_escape");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Polling_Request_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Power_Control_Timing_Advance_message_content (TEDOStream* OStream, const c_EC_Packet_Power_Control_Timing_Advance_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Global_TFI");
	if (!Data->Global_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI", "UPLINK_TFI");
		if (!Data->Global_TFI->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->Global_TFI->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->UPLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI", "UPLINK_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI", "DOWNLINK_TFI");
		if (!Data->Global_TFI->DOWNLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->Global_TFI->DOWNLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->DOWNLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI", "DOWNLINK_TFI");
		ED_Dump_Struct_End (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Global_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "T_AVG_T");
	if (!Data->T_AVG_T_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_AVG_T> ACCESS=<Data->T_AVG_T>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_AVG_T);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "T_AVG_T");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "EC_Packet_Timing_Advance");
	if (!Data->EC_Packet_Timing_Advance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMING_ADVANCE_VALUE> ACCESS=<Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		ED_Dump_Struct_End (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "EC_Packet_Timing_Advance");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "GAMMA");
	if (!Data->GAMMA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GAMMA> ACCESS=<Data->GAMMA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GAMMA);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "GAMMA");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Power_Control_Timing_Advance_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_TBF_Release_message_content (TEDOStream* OStream, const c_EC_Packet_TBF_Release_message_content* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_TBF_Release_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "GLOBAL_TFI");
	if (!Data->GLOBAL_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI", "UPLINK_TFI");
		if (!Data->GLOBAL_TFI->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->GLOBAL_TFI->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->GLOBAL_TFI->UPLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI", "UPLINK_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI", "DOWNLINK_TFI");
		if (!Data->GLOBAL_TFI->DOWNLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->GLOBAL_TFI->DOWNLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->GLOBAL_TFI->DOWNLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI", "DOWNLINK_TFI");
		ED_Dump_Struct_End (OStream, "EC_Packet_TBF_Release_message_content_GLOBAL_TFI");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "GLOBAL_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "TBF_RELEASE_CAUSE");
	if (!Data->TBF_RELEASE_CAUSE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TBF_RELEASE_CAUSE> ACCESS=<Data->TBF_RELEASE_CAUSE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TBF_RELEASE_CAUSE);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "TBF_RELEASE_CAUSE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "WAIT_INDICATION");
	if (!Data->WAIT_INDICATION_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<WAIT_INDICATION> ACCESS=<Data->WAIT_INDICATION>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->WAIT_INDICATION);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "WAIT_INDICATION");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "WAIT__INDICATION_SIZE");
	if (!Data->WAIT__INDICATION_SIZE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<WAIT__INDICATION_SIZE> ACCESS=<Data->WAIT__INDICATION_SIZE>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->WAIT__INDICATION_SIZE);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "WAIT__INDICATION_SIZE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_TBF_Release_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Ack_Nack_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_message_content* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "UPLINK_TFI");
	if (!Data->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UPLINK_TFI);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "UPLINK_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Ack_Nack_Description");
	if (!Data->EC_Ack_Nack_Description_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_SEQUENCE_NUMBER> ACCESS=<Data->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<RECEIVED_BLOCK_BITMAP> ACCESS=<Data->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->EC_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Ack_Nack_Description");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "CONTENTION_RESOLUTION_TLLI");
	if (!Data->CONTENTION_RESOLUTION_TLLI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<CONTENTION_RESOLUTION_TLLI> ACCESS=<Data->CONTENTION_RESOLUTION_TLLI>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CONTENTION_RESOLUTION_TLLI);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "CONTENTION_RESOLUTION_TLLI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Primary_Ack_Nack_Description");
	if (!Data->EC_Primary_Ack_Nack_Description_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_SEQUENCE_NUMBER> ACCESS=<Data->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RECEIVED_BLOCK_BITMAP> ACCESS=<Data->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Primary_Ack_Nack_Description");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "CONTENTION_RESOLUTION_rTLLI");
	if (!Data->CONTENTION_RESOLUTION_rTLLI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CONTENTION_RESOLUTION_rTLLI> ACCESS=<Data->CONTENTION_RESOLUTION_rTLLI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CONTENTION_RESOLUTION_rTLLI);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "CONTENTION_RESOLUTION_rTLLI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "PUAN_Fixed_Uplink_Allocation");
	if (!Data->PUAN_Fixed_Uplink_Allocation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "BSN_OFFSET");
		if (!Data->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<BSN_OFFSET> ACCESS=<Data->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->PUAN_Fixed_Uplink_Allocation->BSN_OFFSET);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "BSN_OFFSET");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<START_FIRST_UL_RLC_DATA_BLOCK> ACCESS=<Data->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->PUAN_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
			/* SEQUENCE NAME=<DELAY_NEXT_UL_RLC_DATA_BLOCK> ACCESS=<Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK>  ITEMS=<20> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			for (i0=0; i0<Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]);
				ED_Dump_Sequence_End_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			}
			ED_Dump_Sequence_End (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->PUAN_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "PUAN_Fixed_Uplink_Allocation");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "RESEGMENT");
	if (!Data->RESEGMENT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<RESEGMENT> ACCESS=<Data->RESEGMENT>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->RESEGMENT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "RESEGMENT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EGPRS_Channel_Coding_Command");
	if (!Data->EGPRS_Channel_Coding_Command_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command", "Scheme");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Scheme> ACCESS=<Data->EGPRS_Channel_Coding_Command->Scheme>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EGPRS_Channel_Coding_Command->Scheme)
			{
				switch (DATA) {
					case 0: OStream->WriteString (OStream, "MCS-1"); break;
					case 1: OStream->WriteString (OStream, "MCS-2"); break;
					case 2: OStream->WriteString (OStream, "MCS-3"); break;
					case 3: OStream->WriteString (OStream, "MCS-4"); break;
					case 4: OStream->WriteString (OStream, "MCS-5"); break;
					case 5: OStream->WriteString (OStream, "MCS-6"); break;
					case 6: OStream->WriteString (OStream, "MCS-7"); break;
					case 7: OStream->WriteString (OStream, "MCS-8"); break;
					case 8: OStream->WriteString (OStream, "MCS-9"); break;
					case 9: OStream->WriteString (OStream, "MCS-5-7"); break;
					case 10: OStream->WriteString (OStream, "MCS-6-9"); break;
					default: OStream->WriteString (OStream, "reserved");
				}
			}
#undef DATA
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command", "Scheme");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EGPRS_Channel_Coding_Command");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "UL_COVERAGE_CLASS");
	if (!Data->UL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UL_COVERAGE_CLASS> ACCESS=<Data->UL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "UL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "STARTING_UL_TIMESLOT");
	if (!Data->STARTING_UL_TIMESLOT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_UL_TIMESLOT> ACCESS=<Data->STARTING_UL_TIMESLOT>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_UL_TIMESLOT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "STARTING_UL_TIMESLOT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "DL_COVERAGE_CLASS");
	if (!Data->DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_COVERAGE_CLASS> ACCESS=<Data->DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "STARTING_DL_TIMESLOT_OFFSET");
	if (!Data->STARTING_DL_TIMESLOT_OFFSET_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_DL_TIMESLOT_OFFSET> ACCESS=<Data->STARTING_DL_TIMESLOT_OFFSET>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_DL_TIMESLOT_OFFSET);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "STARTING_DL_TIMESLOT_OFFSET");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "TIMESLOT_MULTIPLICATOR");
	if (!Data->TIMESLOT_MULTIPLICATOR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMESLOT_MULTIPLICATOR> ACCESS=<Data->TIMESLOT_MULTIPLICATOR>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TIMESLOT_MULTIPLICATOR);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "TIMESLOT_MULTIPLICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "T3238");
	if (!Data->T3238_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T3238> ACCESS=<Data->T3238>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T3238);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "T3238");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Initial_Waiting_Time");
	if (!Data->Initial_Waiting_Time_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Initial_Waiting_Time> ACCESS=<Data->Initial_Waiting_Time>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Initial_Waiting_Time);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Initial_Waiting_Time");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_PACCH_Monitoring_Pattern");
	if (!Data->EC_PACCH_Monitoring_Pattern_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EC_PACCH_Monitoring_Pattern> ACCESS=<Data->EC_PACCH_Monitoring_Pattern>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->EC_PACCH_Monitoring_Pattern);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_PACCH_Monitoring_Pattern");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Packet_Timing_Advance");
	if (!Data->EC_Packet_Timing_Advance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMING_ADVANCE_VALUE> ACCESS=<Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "EC_Packet_Timing_Advance");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "GAMMA");
	if (!Data->GAMMA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GAMMA> ACCESS=<Data->GAMMA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GAMMA);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "GAMMA");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "ALPHA_Enable");
	if (!Data->ALPHA_Enable_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ALPHA_Enable> ACCESS=<Data->ALPHA_Enable>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ALPHA_Enable);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "ALPHA_Enable");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Assignment_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Assignment_message_content* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Global_TFI");
	if (!Data->Global_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI", "UPLINK_TFI");
		if (!Data->Global_TFI->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->Global_TFI->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->UPLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI", "UPLINK_TFI");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI", "DOWNLINK_TFI");
		if (!Data->Global_TFI->DOWNLINK_TFI_Present) ED_Dump_Not_Present (OStream);
		else {
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DOWNLINK_TFI> ACCESS=<Data->Global_TFI->DOWNLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Global_TFI->DOWNLINK_TFI);
		}
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI", "DOWNLINK_TFI");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content_Global_TFI");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Global_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "UPLINK_TFI_ASSIGNMENT");
	if (!Data->UPLINK_TFI_ASSIGNMENT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI_ASSIGNMENT> ACCESS=<Data->UPLINK_TFI_ASSIGNMENT>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UPLINK_TFI_ASSIGNMENT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "UPLINK_TFI_ASSIGNMENT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "EGPRS_Channel_Coding_Command");
	if (!Data->EGPRS_Channel_Coding_Command_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command", "Scheme");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Scheme> ACCESS=<Data->EGPRS_Channel_Coding_Command->Scheme>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->EGPRS_Channel_Coding_Command->Scheme)
			{
				switch (DATA) {
					case 0: OStream->WriteString (OStream, "MCS-1"); break;
					case 1: OStream->WriteString (OStream, "MCS-2"); break;
					case 2: OStream->WriteString (OStream, "MCS-3"); break;
					case 3: OStream->WriteString (OStream, "MCS-4"); break;
					case 4: OStream->WriteString (OStream, "MCS-5"); break;
					case 5: OStream->WriteString (OStream, "MCS-6"); break;
					case 6: OStream->WriteString (OStream, "MCS-7"); break;
					case 7: OStream->WriteString (OStream, "MCS-8"); break;
					case 8: OStream->WriteString (OStream, "MCS-9"); break;
					case 9: OStream->WriteString (OStream, "MCS-5-7"); break;
					case 10: OStream->WriteString (OStream, "MCS-6-9"); break;
					default: OStream->WriteString (OStream, "reserved");
				}
			}
#undef DATA
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command", "Scheme");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "EGPRS_Channel_Coding_Command");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "OVERLAID_CDMA_CODE");
	if (!Data->OVERLAID_CDMA_CODE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OVERLAID_CDMA_CODE> ACCESS=<Data->OVERLAID_CDMA_CODE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->OVERLAID_CDMA_CODE);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "OVERLAID_CDMA_CODE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "EC_Packet_Timing_Advance");
	if (!Data->EC_Packet_Timing_Advance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMING_ADVANCE_VALUE> ACCESS=<Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Packet_Timing_Advance->TIMING_ADVANCE_VALUE);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance", "TIMING_ADVANCE_VALUE");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "EC_Packet_Timing_Advance");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Frequency_Parameters");
	if (!Data->Frequency_Parameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "EC_MA_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EC_MA_NUMBER> ACCESS=<Data->Frequency_Parameters->EC_MA_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Frequency_Parameters->EC_MA_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "EC_MA_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "TSC");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TSC> ACCESS=<Data->Frequency_Parameters->TSC>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Frequency_Parameters->TSC);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "TSC");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "Primary_TSC_Set");
		  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Primary_TSC_Set> ACCESS=<Data->Frequency_Parameters->Primary_TSC_Set>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
		  ED_Dump_Boolean (OStream, Data->Frequency_Parameters->Primary_TSC_Set);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters", "Primary_TSC_Set");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Frequency_Parameters");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "UL_COVERAGE_CLASS");
	if (!Data->UL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UL_COVERAGE_CLASS> ACCESS=<Data->UL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "UL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "STARTING_UL_TIMESLOT");
	if (!Data->STARTING_UL_TIMESLOT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_UL_TIMESLOT> ACCESS=<Data->STARTING_UL_TIMESLOT>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_UL_TIMESLOT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "STARTING_UL_TIMESLOT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "TIMESLOT_MULTIPLICATOR");
	if (!Data->TIMESLOT_MULTIPLICATOR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIMESLOT_MULTIPLICATOR> ACCESS=<Data->TIMESLOT_MULTIPLICATOR>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TIMESLOT_MULTIPLICATOR);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "TIMESLOT_MULTIPLICATOR");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Fixed_Uplink_Allocation");
	if (!Data->Fixed_Uplink_Allocation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<START_FIRST_UL_RLC_DATA_BLOCK> ACCESS=<Data->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
			/* SEQUENCE NAME=<DELAY_NEXT_UL_RLC_DATA_BLOCK> ACCESS=<Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK>  ITEMS=<20> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			for (i0=0; i0<Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]);
				ED_Dump_Sequence_End_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			}
			ED_Dump_Sequence_End (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Fixed_Uplink_Allocation");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "P0");
	if (!Data->P0_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<P0> ACCESS=<Data->P0>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->P0);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "P0");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "PR_MODE");
	if (!Data->PR_MODE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PR_MODE> ACCESS=<Data->PR_MODE>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PR_MODE);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "PR_MODE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "GAMMA");
	if (!Data->GAMMA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GAMMA> ACCESS=<Data->GAMMA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GAMMA);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "GAMMA");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "ALPHA_Enable");
	if (!Data->ALPHA_Enable_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ALPHA_Enable> ACCESS=<Data->ALPHA_Enable>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ALPHA_Enable);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "ALPHA_Enable");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "DL_COVERAGE_CLASS");
	if (!Data->DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_COVERAGE_CLASS> ACCESS=<Data->DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "STARTING_DL_TIMESLOT_OFFSET");
	if (!Data->STARTING_DL_TIMESLOT_OFFSET_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_DL_TIMESLOT_OFFSET> ACCESS=<Data->STARTING_DL_TIMESLOT_OFFSET>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->STARTING_DL_TIMESLOT_OFFSET);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "STARTING_DL_TIMESLOT_OFFSET");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Message_escape");
	if (!Data->Message_escape_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Message_escape> ACCESS=<*(Data->Message_escape)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Message_escape->value, Data->Message_escape->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Message_escape");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "USED_DL_COVERAGE_CLASS");
	if (!Data->USED_DL_COVERAGE_CLASS_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USED_DL_COVERAGE_CLASS> ACCESS=<Data->USED_DL_COVERAGE_CLASS>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->USED_DL_COVERAGE_CLASS);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "USED_DL_COVERAGE_CLASS");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "UPLINK_TFI");
	if (!Data->UPLINK_TFI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UPLINK_TFI> ACCESS=<Data->UPLINK_TFI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UPLINK_TFI);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "UPLINK_TFI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "CONTENTION_RESOLUTION_TLLI");
	if (!Data->CONTENTION_RESOLUTION_TLLI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<CONTENTION_RESOLUTION_TLLI> ACCESS=<Data->CONTENTION_RESOLUTION_TLLI>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CONTENTION_RESOLUTION_TLLI);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "CONTENTION_RESOLUTION_TLLI");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "EC_Primary_Ack_Nack_Description");
	if (!Data->EC_Primary_Ack_Nack_Description_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<STARTING_SEQUENCE_NUMBER> ACCESS=<Data->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Primary_Ack_Nack_Description->STARTING_SEQUENCE_NUMBER);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description", "STARTING_SEQUENCE_NUMBER");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RECEIVED_BLOCK_BITMAP> ACCESS=<Data->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->EC_Primary_Ack_Nack_Description->RECEIVED_BLOCK_BITMAP);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description", "RECEIVED_BLOCK_BITMAP");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "EC_Primary_Ack_Nack_Description");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "PUANCR_Fixed_Uplink_Allocation");
	if (!Data->PUANCR_Fixed_Uplink_Allocation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<START_FIRST_UL_RLC_DATA_BLOCK> ACCESS=<Data->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->PUANCR_Fixed_Uplink_Allocation->START_FIRST_UL_RLC_DATA_BLOCK);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation", "START_FIRST_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
			/* SEQUENCE NAME=<DELAY_NEXT_UL_RLC_DATA_BLOCK> ACCESS=<Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK>  ITEMS=<20> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			for (i0=0; i0<Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.data [i0]);
				ED_Dump_Sequence_End_Field (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", i0, Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
			}
			ED_Dump_Sequence_End (OStream, "DELAY_NEXT_UL_RLC_DATA_BLOCK", Data->PUANCR_Fixed_Uplink_Allocation->DELAY_NEXT_UL_RLC_DATA_BLOCK.items);
		ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation", "DELAY_NEXT_UL_RLC_DATA_BLOCK");
		ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation");
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "PUANCR_Fixed_Uplink_Allocation");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "RESEGMENT");
	if (!Data->RESEGMENT_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<RESEGMENT> ACCESS=<Data->RESEGMENT>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->RESEGMENT);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "RESEGMENT");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Non_distribution_part_error");
	if (!Data->Non_distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Non_distribution_part_error> ACCESS=<*(Data->Non_distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Non_distribution_part_error->value, Data->Non_distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Non_distribution_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Address_information_part_error");
	if (!Data->Address_information_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Address_information_part_error> ACCESS=<*(Data->Address_information_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Address_information_part_error->value, Data->Address_information_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Address_information_part_error");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Distribution_part_error");
	if (!Data->Distribution_part_error_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Distribution_part_error> ACCESS=<*(Data->Distribution_part_error)>  MAXBITSIZE=<64> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Distribution_part_error->value, Data->Distribution_part_error->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content", "Distribution_part_error");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Access_Reject (TEDOStream* OStream, const c_EC_Packet_Access_Reject* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Access_Reject");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Access_Reject", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Access_Reject_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Access_Reject_message_content> */
	  Dump_c_EC_Packet_Access_Reject_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Access_Reject", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Access_Reject");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Assignment (TEDOStream* OStream, const c_EC_Packet_Downlink_Assignment* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Assignment");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Assignment", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Downlink_Assignment_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Downlink_Assignment_message_content> */
	  Dump_c_EC_Packet_Downlink_Assignment_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Assignment", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Assignment");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Polling_Request (TEDOStream* OStream, const c_EC_Packet_Polling_Request* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Polling_Request");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Polling_Request", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Polling_Request_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Polling_Request_message_content> */
	  Dump_c_EC_Packet_Polling_Request_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Polling_Request", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Polling_Request");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Power_Control_Timing_Advance (TEDOStream* OStream, const c_EC_Packet_Power_Control_Timing_Advance* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Power_Control_Timing_Advance");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Power_Control_Timing_Advance", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Power_Control_Timing_Advance_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Power_Control_Timing_Advance_message_content> */
	  Dump_c_EC_Packet_Power_Control_Timing_Advance_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Power_Control_Timing_Advance", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Power_Control_Timing_Advance");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_TBF_Release (TEDOStream* OStream, const c_EC_Packet_TBF_Release* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_TBF_Release");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_TBF_Release", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_TBF_Release_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_TBF_Release_message_content> */
	  Dump_c_EC_Packet_TBF_Release_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_TBF_Release", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_TBF_Release");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Ack_Nack (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Uplink_Ack_Nack_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Uplink_Ack_Nack_message_content> */
	  Dump_c_EC_Packet_Uplink_Ack_Nack_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Assignment (TEDOStream* OStream, const c_EC_Packet_Uplink_Assignment* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Assignment");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Assignment", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Uplink_Assignment_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Uplink_Assignment_message_content> */
	  Dump_c_EC_Packet_Uplink_Assignment_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Assignment", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Assignment");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content> */
	  Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Dummy_Control_Block (TEDOStream* OStream, const c_EC_Packet_Downlink_Dummy_Control_Block* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Dummy_Control_Block");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Downlink_Dummy_Control_Block_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Downlink_Dummy_Control_Block_message_content> */
	  Dump_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Dummy_Control_Block", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Dummy_Control_Block");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Control_Acknowledgement (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Control_Acknowledgement");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Control_Acknowledgement_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Control_Acknowledgement_message_content> */
	  Dump_c_EC_Packet_Control_Acknowledgement_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Control_Acknowledgement");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Downlink_Ack_Nack (TEDOStream* OStream, const c_EC_Packet_Downlink_Ack_Nack* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Downlink_Ack_Nack");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Downlink_Ack_Nack", "contents");
	  /* STRUCTURAL=<0> TYPE=<c_EC_Packet_Downlink_Ack_Nack_message_content> NAME=<contents> ACCESS=<Data->contents>  OPTIONAL=<0> FUNC=<Dump_c_EC_Packet_Downlink_Ack_Nack_message_content> */
	  Dump_c_EC_Packet_Downlink_Ack_Nack_message_content (OStream, &(Data->contents));
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Downlink_Ack_Nack", "contents");
	ED_Dump_Struct_End (OStream, "EC_Packet_Downlink_Ack_Nack");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EC_Packet_Control_Acknowledgement_11_bit_message (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement_11_bit_message* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message", "MESSAGE_TYPE");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MESSAGE_TYPE> ACCESS=<Data->MESSAGE_TYPE>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MESSAGE_TYPE);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message", "MESSAGE_TYPE");
	ED_Dump_Struct_Begin_Field (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message", "DL_CC_EST");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DL_CC_EST> ACCESS=<Data->DL_CC_EST>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DL_CC_EST);
	ED_Dump_Struct_End_Field (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message", "DL_CC_EST");
	ED_Dump_Struct_End (OStream, "EC_Packet_Control_Acknowledgement_11_bit_message");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GenericTLV_EC_PACCH (TEDOStream* OStream, const c_GenericTLV_EC_PACCH* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GenericTLV_EC_PACCH");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_EC_PACCH", "TLV_Tag");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TLV_Tag> ACCESS=<Data->TLV_Tag>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TLV_Tag);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_EC_PACCH", "TLV_Tag");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_EC_PACCH", "TLV_Data");
	  /* NAME=<TLV_Data> ACCESS=<Data->TLV_Data>  MAXBITSIZE=<8192> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TLV_Data.value, Data->TLV_Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_EC_PACCH", "TLV_Data");
	ED_Dump_Struct_End (OStream, "GenericTLV_EC_PACCH");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_Downlink_RLC_MAC_EC_PACCH (TEDOStream* OStream, const TDownlink_RLC_MAC_EC_PACCH_Data* Data)
{
	switch (Data->Type) {
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject: Dump_c_EC_Packet_Access_Reject (OStream, Data->Data.fld_c_EC_Packet_Access_Reject); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment: Dump_c_EC_Packet_Downlink_Assignment (OStream, Data->Data.fld_c_EC_Packet_Downlink_Assignment); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request: Dump_c_EC_Packet_Polling_Request (OStream, Data->Data.fld_c_EC_Packet_Polling_Request); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance: Dump_c_EC_Packet_Power_Control_Timing_Advance (OStream, Data->Data.fld_c_EC_Packet_Power_Control_Timing_Advance); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release: Dump_c_EC_Packet_TBF_Release (OStream, Data->Data.fld_c_EC_Packet_TBF_Release); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack: Dump_c_EC_Packet_Uplink_Ack_Nack (OStream, Data->Data.fld_c_EC_Packet_Uplink_Ack_Nack); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment: Dump_c_EC_Packet_Uplink_Assignment (OStream, Data->Data.fld_c_EC_Packet_Uplink_Assignment); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution: Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (OStream, Data->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution); break;
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block: Dump_c_EC_Packet_Downlink_Dummy_Control_Block (OStream, Data->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_Uplink_RLC_MAC_EC_PACCH (TEDOStream* OStream, const TUplink_RLC_MAC_EC_PACCH_Data* Data)
{
	switch (Data->Type) {
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement: Dump_c_EC_Packet_Control_Acknowledgement (OStream, Data->Data.fld_c_EC_Packet_Control_Acknowledgement); break;
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack: Dump_c_EC_Packet_Downlink_Ack_Nack (OStream, Data->Data.fld_c_EC_Packet_Downlink_Ack_Nack); break;
		default:;
	}
}
