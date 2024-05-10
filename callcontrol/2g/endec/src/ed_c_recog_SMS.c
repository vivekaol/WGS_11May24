/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_recog_SMS.h"
#include "ed_lib.h"
#include "CM_CP_SMS.h"
#include "MSC2MS_SMS.h"
#include "MS2MSC_SMS.h"
#include "SC2MS_SMS.h"
#include "SC2MS_ERR_SMS.h"
#include "SC2MS_ACK_SMS.h"
#include "MS2SC_SMS.h"
#include "MS2SC_ERR_SMS.h"
#include "MS2SC_ACK_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


int SETPRESENT_TCM_CP_Data (TCM_CP_Data* sp, TCM_CP_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TCM_CP_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_CM_CP_CP_DATA: {
			sp->Data.fld_c_CP_DATA = (c_CP_DATA*)EDAlloc (sizeof (c_CP_DATA)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CP_DATA == NULL)
			INIT_c_CP_DATA (sp->Data.fld_c_CP_DATA);
			break;
		}
		
		case ID_CM_CP_CP_ACK: {
			sp->Data.fld_c_CP_ACK = (c_CP_ACK*)EDAlloc (sizeof (c_CP_ACK)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CP_ACK == NULL)
			INIT_c_CP_ACK (sp->Data.fld_c_CP_ACK);
			break;
		}
		
		case ID_CM_CP_CP_ERROR: {
			sp->Data.fld_c_CP_ERROR = (c_CP_ERROR*)EDAlloc (sizeof (c_CP_ERROR)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_CP_ERROR == NULL)
			INIT_c_CP_ERROR (sp->Data.fld_c_CP_ERROR);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TCM_CP_Data (TCM_CP_Data* sp)
{
	switch (sp->Type) {
		case ID_CM_CP_CP_DATA: {
			FREE_c_CP_DATA (sp->Data.fld_c_CP_DATA);
	EDFree (sp->Data.fld_c_CP_DATA );
			break;
		}
		
		case ID_CM_CP_CP_ACK: {
			FREE_c_CP_ACK (sp->Data.fld_c_CP_ACK);
	EDFree (sp->Data.fld_c_CP_ACK );
			break;
		}
		
		case ID_CM_CP_CP_ERROR: {
			FREE_c_CP_ERROR (sp->Data.fld_c_CP_ERROR);
	EDFree (sp->Data.fld_c_CP_ERROR );
			break;
		}
		
		default:;
	}

	sp->Type = ID_CM_CP_Unrecognized;
}

int SETPRESENT_TMSC2MS_Data (TMSC2MS_Data* sp, TMSC2MS_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TMSC2MS_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_MSC2MS_RP_DATA_MSC2MS: {
			sp->Data.fld_c_RP_DATA_MSC2MS = (c_RP_DATA_MSC2MS*)EDAlloc (sizeof (c_RP_DATA_MSC2MS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_DATA_MSC2MS == NULL)
			INIT_c_RP_DATA_MSC2MS (sp->Data.fld_c_RP_DATA_MSC2MS);
			break;
		}
		
		case ID_MSC2MS_RP_RP_ACK_MSC2MS: {
			sp->Data.fld_c_RP_RP_ACK_MSC2MS = (c_RP_RP_ACK_MSC2MS*)EDAlloc (sizeof (c_RP_RP_ACK_MSC2MS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_RP_ACK_MSC2MS == NULL)
			INIT_c_RP_RP_ACK_MSC2MS (sp->Data.fld_c_RP_RP_ACK_MSC2MS);
			break;
		}
		
		case ID_MSC2MS_RP_RP_ERROR_MSC2MS: {
			sp->Data.fld_c_RP_RP_ERROR_MSC2MS = (c_RP_RP_ERROR_MSC2MS*)EDAlloc (sizeof (c_RP_RP_ERROR_MSC2MS)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_RP_ERROR_MSC2MS == NULL)
			INIT_c_RP_RP_ERROR_MSC2MS (sp->Data.fld_c_RP_RP_ERROR_MSC2MS);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TMSC2MS_Data (TMSC2MS_Data* sp)
{
	switch (sp->Type) {
		case ID_MSC2MS_RP_DATA_MSC2MS: {
			FREE_c_RP_DATA_MSC2MS (sp->Data.fld_c_RP_DATA_MSC2MS);
	EDFree (sp->Data.fld_c_RP_DATA_MSC2MS );
			break;
		}
		
		case ID_MSC2MS_RP_RP_ACK_MSC2MS: {
			FREE_c_RP_RP_ACK_MSC2MS (sp->Data.fld_c_RP_RP_ACK_MSC2MS);
	EDFree (sp->Data.fld_c_RP_RP_ACK_MSC2MS );
			break;
		}
		
		case ID_MSC2MS_RP_RP_ERROR_MSC2MS: {
			FREE_c_RP_RP_ERROR_MSC2MS (sp->Data.fld_c_RP_RP_ERROR_MSC2MS);
	EDFree (sp->Data.fld_c_RP_RP_ERROR_MSC2MS );
			break;
		}
		
		default:;
	}

	sp->Type = ID_MSC2MS_Unrecognized;
}

int SETPRESENT_TMS2MSC_Data (TMS2MSC_Data* sp, TMS2MSC_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TMS2MSC_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_MS2MSC_RP_DATA_MS2MSC: {
			sp->Data.fld_c_RP_DATA_MS2MSC = (c_RP_DATA_MS2MSC*)EDAlloc (sizeof (c_RP_DATA_MS2MSC)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_DATA_MS2MSC == NULL)
			INIT_c_RP_DATA_MS2MSC (sp->Data.fld_c_RP_DATA_MS2MSC);
			break;
		}
		
		case ID_MS2MSC_RP_RP_SMMA_MS2MSC: {
			sp->Data.fld_c_RP_RP_SMMA_MS2MSC = (c_RP_RP_SMMA_MS2MSC*)EDAlloc (sizeof (c_RP_RP_SMMA_MS2MSC)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_RP_SMMA_MS2MSC == NULL)
			INIT_c_RP_RP_SMMA_MS2MSC (sp->Data.fld_c_RP_RP_SMMA_MS2MSC);
			break;
		}
		
		case ID_MS2MSC_RP_RP_ACK_MS2MSC: {
			sp->Data.fld_c_RP_RP_ACK_MS2MSC = (c_RP_RP_ACK_MS2MSC*)EDAlloc (sizeof (c_RP_RP_ACK_MS2MSC)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_RP_ACK_MS2MSC == NULL)
			INIT_c_RP_RP_ACK_MS2MSC (sp->Data.fld_c_RP_RP_ACK_MS2MSC);
			break;
		}
		
		case ID_MS2MSC_RP_RP_ERROR_MS2MSC: {
			sp->Data.fld_c_RP_RP_ERROR_MS2MSC = (c_RP_RP_ERROR_MS2MSC*)EDAlloc (sizeof (c_RP_RP_ERROR_MS2MSC)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_RP_RP_ERROR_MS2MSC == NULL)
			INIT_c_RP_RP_ERROR_MS2MSC (sp->Data.fld_c_RP_RP_ERROR_MS2MSC);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TMS2MSC_Data (TMS2MSC_Data* sp)
{
	switch (sp->Type) {
		case ID_MS2MSC_RP_DATA_MS2MSC: {
			FREE_c_RP_DATA_MS2MSC (sp->Data.fld_c_RP_DATA_MS2MSC);
	EDFree (sp->Data.fld_c_RP_DATA_MS2MSC );
			break;
		}
		
		case ID_MS2MSC_RP_RP_SMMA_MS2MSC: {
			FREE_c_RP_RP_SMMA_MS2MSC (sp->Data.fld_c_RP_RP_SMMA_MS2MSC);
	EDFree (sp->Data.fld_c_RP_RP_SMMA_MS2MSC );
			break;
		}
		
		case ID_MS2MSC_RP_RP_ACK_MS2MSC: {
			FREE_c_RP_RP_ACK_MS2MSC (sp->Data.fld_c_RP_RP_ACK_MS2MSC);
	EDFree (sp->Data.fld_c_RP_RP_ACK_MS2MSC );
			break;
		}
		
		case ID_MS2MSC_RP_RP_ERROR_MS2MSC: {
			FREE_c_RP_RP_ERROR_MS2MSC (sp->Data.fld_c_RP_RP_ERROR_MS2MSC);
	EDFree (sp->Data.fld_c_RP_RP_ERROR_MS2MSC );
			break;
		}
		
		default:;
	}

	sp->Type = ID_MS2MSC_Unrecognized;
}

int SETPRESENT_TSC2MS_Data (TSC2MS_Data* sp, TSC2MS_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TSC2MS_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_SC2MS_SMS_DELIVER: {
			sp->Data.fld_c_SMS_DELIVER = (c_SMS_DELIVER*)EDAlloc (sizeof (c_SMS_DELIVER)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_DELIVER == NULL)
			INIT_c_SMS_DELIVER (sp->Data.fld_c_SMS_DELIVER);
			break;
		}
		
		case ID_SC2MS_SMS_STATUS_REPORT: {
			sp->Data.fld_c_SMS_STATUS_REPORT = (c_SMS_STATUS_REPORT*)EDAlloc (sizeof (c_SMS_STATUS_REPORT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_STATUS_REPORT == NULL)
			INIT_c_SMS_STATUS_REPORT (sp->Data.fld_c_SMS_STATUS_REPORT);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TSC2MS_Data (TSC2MS_Data* sp)
{
	switch (sp->Type) {
		case ID_SC2MS_SMS_DELIVER: {
			FREE_c_SMS_DELIVER (sp->Data.fld_c_SMS_DELIVER);
	EDFree (sp->Data.fld_c_SMS_DELIVER );
			break;
		}
		
		case ID_SC2MS_SMS_STATUS_REPORT: {
			FREE_c_SMS_STATUS_REPORT (sp->Data.fld_c_SMS_STATUS_REPORT);
	EDFree (sp->Data.fld_c_SMS_STATUS_REPORT );
			break;
		}
		
		default:;
	}

	sp->Type = ID_SC2MS_Unrecognized;
}

int SETPRESENT_TSC2MS_ERR_Data (TSC2MS_ERR_Data* sp, TSC2MS_ERR_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TSC2MS_ERR_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR: {
			sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR = (c_SMS_SUBMIT_REPORT_RP_ERROR*)EDAlloc (sizeof (c_SMS_SUBMIT_REPORT_RP_ERROR)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR == NULL)
			INIT_c_SMS_SUBMIT_REPORT_RP_ERROR (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TSC2MS_ERR_Data (TSC2MS_ERR_Data* sp)
{
	switch (sp->Type) {
		case ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR: {
			FREE_c_SMS_SUBMIT_REPORT_RP_ERROR (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR);
	EDFree (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR );
			break;
		}
		
		default:;
	}

	sp->Type = ID_SC2MS_ERR_Unrecognized;
}

int SETPRESENT_TSC2MS_ACK_Data (TSC2MS_ACK_Data* sp, TSC2MS_ACK_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TSC2MS_ACK_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK: {
			sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK = (c_SMS_SUBMIT_REPORT_RP_ACK*)EDAlloc (sizeof (c_SMS_SUBMIT_REPORT_RP_ACK)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK == NULL)
			INIT_c_SMS_SUBMIT_REPORT_RP_ACK (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TSC2MS_ACK_Data (TSC2MS_ACK_Data* sp)
{
	switch (sp->Type) {
		case ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK: {
			FREE_c_SMS_SUBMIT_REPORT_RP_ACK (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK);
	EDFree (sp->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK );
			break;
		}
		
		default:;
	}

	sp->Type = ID_SC2MS_ACK_Unrecognized;
}

int SETPRESENT_TMS2SC_Data (TMS2SC_Data* sp, TMS2SC_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TMS2SC_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_MS2SC_SMS_SUBMIT: {
			sp->Data.fld_c_SMS_SUBMIT = (c_SMS_SUBMIT*)EDAlloc (sizeof (c_SMS_SUBMIT)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_SUBMIT == NULL)
			INIT_c_SMS_SUBMIT (sp->Data.fld_c_SMS_SUBMIT);
			break;
		}
		
		case ID_MS2SC_SMS_COMMAND: {
			sp->Data.fld_c_SMS_COMMAND = (c_SMS_COMMAND*)EDAlloc (sizeof (c_SMS_COMMAND)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_COMMAND == NULL)
			INIT_c_SMS_COMMAND (sp->Data.fld_c_SMS_COMMAND);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TMS2SC_Data (TMS2SC_Data* sp)
{
	switch (sp->Type) {
		case ID_MS2SC_SMS_SUBMIT: {
			FREE_c_SMS_SUBMIT (sp->Data.fld_c_SMS_SUBMIT);
	EDFree (sp->Data.fld_c_SMS_SUBMIT );
			break;
		}
		
		case ID_MS2SC_SMS_COMMAND: {
			FREE_c_SMS_COMMAND (sp->Data.fld_c_SMS_COMMAND);
	EDFree (sp->Data.fld_c_SMS_COMMAND );
			break;
		}
		
		default:;
	}

	sp->Type = ID_MS2SC_Unrecognized;
}

int SETPRESENT_TMS2SC_ERR_Data (TMS2SC_ERR_Data* sp, TMS2SC_ERR_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TMS2SC_ERR_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR: {
			sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR = (c_SMS_DELIVERY_REPORT_RP_ERROR*)EDAlloc (sizeof (c_SMS_DELIVERY_REPORT_RP_ERROR)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR == NULL)
			INIT_c_SMS_DELIVERY_REPORT_RP_ERROR (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TMS2SC_ERR_Data (TMS2SC_ERR_Data* sp)
{
	switch (sp->Type) {
		case ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR: {
			FREE_c_SMS_DELIVERY_REPORT_RP_ERROR (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR);
	EDFree (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR );
			break;
		}
		
		default:;
	}

	sp->Type = ID_MS2SC_ERR_Unrecognized;
}

int SETPRESENT_TMS2SC_ACK_Data (TMS2SC_ACK_Data* sp, TMS2SC_ACK_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TMS2SC_ACK_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK: {
			sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK = (c_SMS_DELIVERY_REPORT_RP_ACK*)EDAlloc (sizeof (c_SMS_DELIVERY_REPORT_RP_ACK)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK == NULL)
			INIT_c_SMS_DELIVERY_REPORT_RP_ACK (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TMS2SC_ACK_Data (TMS2SC_ACK_Data* sp)
{
	switch (sp->Type) {
		case ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK: {
			FREE_c_SMS_DELIVERY_REPORT_RP_ACK (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK);
	EDFree (sp->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK );
			break;
		}
		
		default:;
	}

	sp->Type = ID_MS2SC_ACK_Unrecognized;
}

#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_CM_CP (const char* buffer, TCM_CP_Data* data, int bitLen)
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
	switch (key) {
			/* Detect signal CP_DATA */
		case 0x0901: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TCM_CP_Data (data, ID_CM_CP_CP_DATA), != ED_NO_ERRORS)
			INIT_c_CP_DATA (data->Data.fld_c_CP_DATA);
			retLen = DECODE_c_CP_DATA (buffer, 0, data->Data.fld_c_CP_DATA, bitLen);
		
			return retLen;
		}
		/* Detect signal CP_ACK */
		case 0x0904: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TCM_CP_Data (data, ID_CM_CP_CP_ACK), != ED_NO_ERRORS)
			INIT_c_CP_ACK (data->Data.fld_c_CP_ACK);
			retLen = DECODE_c_CP_ACK (buffer, 0, data->Data.fld_c_CP_ACK, bitLen);
		
			return retLen;
		}
		/* Detect signal CP_ERROR */
		case 0x0910: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TCM_CP_Data (data, ID_CM_CP_CP_ERROR), != ED_NO_ERRORS)
			INIT_c_CP_ERROR (data->Data.fld_c_CP_ERROR);
			retLen = DECODE_c_CP_ERROR (buffer, 0, data->Data.fld_c_CP_ERROR, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_CM_CP_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_CM_CP (const char* buffer, int len, TCM_CP_Data* data)
	{
		if (SetDecode_CM_CP (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_CM_CP (char* buffer, ED_EXLONG bitOffset, TCM_CP_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_CM_CP_CP_DATA: {
			retLen = ENCODE_c_CP_DATA (buffer, 0, data->Data.fld_c_CP_DATA);
			break;
		}
		case ID_CM_CP_CP_ACK: {
			retLen = ENCODE_c_CP_ACK (buffer, 0, data->Data.fld_c_CP_ACK);
			break;
		}
		case ID_CM_CP_CP_ERROR: {
			retLen = ENCODE_c_CP_ERROR (buffer, 0, data->Data.fld_c_CP_ERROR);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_MSC2MS (const char* buffer, TMSC2MS_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0]);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal RP_DATA_MSC2MS */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMSC2MS_Data (data, ID_MSC2MS_RP_DATA_MSC2MS), != ED_NO_ERRORS)
			INIT_c_RP_DATA_MSC2MS (data->Data.fld_c_RP_DATA_MSC2MS);
			retLen = DECODE_c_RP_DATA_MSC2MS (buffer, 0, data->Data.fld_c_RP_DATA_MSC2MS, bitLen);
		
			return retLen;
		}
		/* Detect signal RP_RP_ACK_MSC2MS */
		case 0x0003: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMSC2MS_Data (data, ID_MSC2MS_RP_RP_ACK_MSC2MS), != ED_NO_ERRORS)
			INIT_c_RP_RP_ACK_MSC2MS (data->Data.fld_c_RP_RP_ACK_MSC2MS);
			retLen = DECODE_c_RP_RP_ACK_MSC2MS (buffer, 0, data->Data.fld_c_RP_RP_ACK_MSC2MS, bitLen);
		
			return retLen;
		}
		/* Detect signal RP_RP_ERROR_MSC2MS */
		case 0x0005: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMSC2MS_Data (data, ID_MSC2MS_RP_RP_ERROR_MSC2MS), != ED_NO_ERRORS)
			INIT_c_RP_RP_ERROR_MSC2MS (data->Data.fld_c_RP_RP_ERROR_MSC2MS);
			retLen = DECODE_c_RP_RP_ERROR_MSC2MS (buffer, 0, data->Data.fld_c_RP_RP_ERROR_MSC2MS, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_MSC2MS_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MSC2MS (const char* buffer, int len, TMSC2MS_Data* data)
	{
		if (SetDecode_MSC2MS (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_MSC2MS (char* buffer, ED_EXLONG bitOffset, TMSC2MS_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_MSC2MS_RP_DATA_MSC2MS: {
			retLen = ENCODE_c_RP_DATA_MSC2MS (buffer, 0, data->Data.fld_c_RP_DATA_MSC2MS);
			break;
		}
		case ID_MSC2MS_RP_RP_ACK_MSC2MS: {
			retLen = ENCODE_c_RP_RP_ACK_MSC2MS (buffer, 0, data->Data.fld_c_RP_RP_ACK_MSC2MS);
			break;
		}
		case ID_MSC2MS_RP_RP_ERROR_MSC2MS: {
			retLen = ENCODE_c_RP_RP_ERROR_MSC2MS (buffer, 0, data->Data.fld_c_RP_RP_ERROR_MSC2MS);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_MS2MSC (const char* buffer, TMS2MSC_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0]);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal RP_DATA_MS2MSC */
		case 0x0000: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2MSC_Data (data, ID_MS2MSC_RP_DATA_MS2MSC), != ED_NO_ERRORS)
			INIT_c_RP_DATA_MS2MSC (data->Data.fld_c_RP_DATA_MS2MSC);
			retLen = DECODE_c_RP_DATA_MS2MSC (buffer, 0, data->Data.fld_c_RP_DATA_MS2MSC, bitLen);
		
			return retLen;
		}
		/* Detect signal RP_RP_SMMA_MS2MSC */
		case 0x0006: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2MSC_Data (data, ID_MS2MSC_RP_RP_SMMA_MS2MSC), != ED_NO_ERRORS)
			INIT_c_RP_RP_SMMA_MS2MSC (data->Data.fld_c_RP_RP_SMMA_MS2MSC);
			retLen = DECODE_c_RP_RP_SMMA_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_SMMA_MS2MSC, bitLen);
		
			return retLen;
		}
		/* Detect signal RP_RP_ACK_MS2MSC */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2MSC_Data (data, ID_MS2MSC_RP_RP_ACK_MS2MSC), != ED_NO_ERRORS)
			INIT_c_RP_RP_ACK_MS2MSC (data->Data.fld_c_RP_RP_ACK_MS2MSC);
			retLen = DECODE_c_RP_RP_ACK_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_ACK_MS2MSC, bitLen);
		
			return retLen;
		}
		/* Detect signal RP_RP_ERROR_MS2MSC */
		case 0x0004: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2MSC_Data (data, ID_MS2MSC_RP_RP_ERROR_MS2MSC), != ED_NO_ERRORS)
			INIT_c_RP_RP_ERROR_MS2MSC (data->Data.fld_c_RP_RP_ERROR_MS2MSC);
			retLen = DECODE_c_RP_RP_ERROR_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_ERROR_MS2MSC, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_MS2MSC_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2MSC (const char* buffer, int len, TMS2MSC_Data* data)
	{
		if (SetDecode_MS2MSC (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_MS2MSC (char* buffer, ED_EXLONG bitOffset, TMS2MSC_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_MS2MSC_RP_DATA_MS2MSC: {
			retLen = ENCODE_c_RP_DATA_MS2MSC (buffer, 0, data->Data.fld_c_RP_DATA_MS2MSC);
			break;
		}
		case ID_MS2MSC_RP_RP_SMMA_MS2MSC: {
			retLen = ENCODE_c_RP_RP_SMMA_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_SMMA_MS2MSC);
			break;
		}
		case ID_MS2MSC_RP_RP_ACK_MS2MSC: {
			retLen = ENCODE_c_RP_RP_ACK_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_ACK_MS2MSC);
			break;
		}
		case ID_MS2MSC_RP_RP_ERROR_MS2MSC: {
			retLen = ENCODE_c_RP_RP_ERROR_MS2MSC (buffer, 0, data->Data.fld_c_RP_RP_ERROR_MS2MSC);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_SC2MS (const char* buffer, TSC2MS_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_DELIVER */
		case 0x0000: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TSC2MS_Data (data, ID_SC2MS_SMS_DELIVER), != ED_NO_ERRORS)
			INIT_c_SMS_DELIVER (data->Data.fld_c_SMS_DELIVER);
			retLen = DECODE_c_SMS_DELIVER (buffer, 0, data->Data.fld_c_SMS_DELIVER, bitLen);
		
			return retLen;
		}
		/* Detect signal SMS_STATUS_REPORT */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TSC2MS_Data (data, ID_SC2MS_SMS_STATUS_REPORT), != ED_NO_ERRORS)
			INIT_c_SMS_STATUS_REPORT (data->Data.fld_c_SMS_STATUS_REPORT);
			retLen = DECODE_c_SMS_STATUS_REPORT (buffer, 0, data->Data.fld_c_SMS_STATUS_REPORT, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_SC2MS_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS (const char* buffer, int len, TSC2MS_Data* data)
	{
		if (SetDecode_SC2MS (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_SC2MS (char* buffer, ED_EXLONG bitOffset, TSC2MS_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_SC2MS_SMS_DELIVER: {
			retLen = ENCODE_c_SMS_DELIVER (buffer, 0, data->Data.fld_c_SMS_DELIVER);
			break;
		}
		case ID_SC2MS_SMS_STATUS_REPORT: {
			retLen = ENCODE_c_SMS_STATUS_REPORT (buffer, 0, data->Data.fld_c_SMS_STATUS_REPORT);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_SC2MS_ERR (const char* buffer, TSC2MS_ERR_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_SUBMIT_REPORT_RP_ERROR */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TSC2MS_ERR_Data (data, ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR), != ED_NO_ERRORS)
			INIT_c_SMS_SUBMIT_REPORT_RP_ERROR (data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR);
			retLen = DECODE_c_SMS_SUBMIT_REPORT_RP_ERROR (buffer, 0, data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_SC2MS_ERR_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS_ERR (const char* buffer, int len, TSC2MS_ERR_Data* data)
	{
		if (SetDecode_SC2MS_ERR (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_SC2MS_ERR (char* buffer, ED_EXLONG bitOffset, TSC2MS_ERR_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR: {
			retLen = ENCODE_c_SMS_SUBMIT_REPORT_RP_ERROR (buffer, 0, data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ERROR);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_SC2MS_ACK (const char* buffer, TSC2MS_ACK_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_SUBMIT_REPORT_RP_ACK */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TSC2MS_ACK_Data (data, ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK), != ED_NO_ERRORS)
			INIT_c_SMS_SUBMIT_REPORT_RP_ACK (data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK);
			retLen = DECODE_c_SMS_SUBMIT_REPORT_RP_ACK (buffer, 0, data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_SC2MS_ACK_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS_ACK (const char* buffer, int len, TSC2MS_ACK_Data* data)
	{
		if (SetDecode_SC2MS_ACK (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_SC2MS_ACK (char* buffer, ED_EXLONG bitOffset, TSC2MS_ACK_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK: {
			retLen = ENCODE_c_SMS_SUBMIT_REPORT_RP_ACK (buffer, 0, data->Data.fld_c_SMS_SUBMIT_REPORT_RP_ACK);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_MS2SC (const char* buffer, TMS2SC_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_SUBMIT */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2SC_Data (data, ID_MS2SC_SMS_SUBMIT), != ED_NO_ERRORS)
			INIT_c_SMS_SUBMIT (data->Data.fld_c_SMS_SUBMIT);
			retLen = DECODE_c_SMS_SUBMIT (buffer, 0, data->Data.fld_c_SMS_SUBMIT, bitLen);
		
			return retLen;
		}
		/* Detect signal SMS_COMMAND */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2SC_Data (data, ID_MS2SC_SMS_COMMAND), != ED_NO_ERRORS)
			INIT_c_SMS_COMMAND (data->Data.fld_c_SMS_COMMAND);
			retLen = DECODE_c_SMS_COMMAND (buffer, 0, data->Data.fld_c_SMS_COMMAND, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_MS2SC_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC (const char* buffer, int len, TMS2SC_Data* data)
	{
		if (SetDecode_MS2SC (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_MS2SC (char* buffer, ED_EXLONG bitOffset, TMS2SC_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_MS2SC_SMS_SUBMIT: {
			retLen = ENCODE_c_SMS_SUBMIT (buffer, 0, data->Data.fld_c_SMS_SUBMIT);
			break;
		}
		case ID_MS2SC_SMS_COMMAND: {
			retLen = ENCODE_c_SMS_COMMAND (buffer, 0, data->Data.fld_c_SMS_COMMAND);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_MS2SC_ERR (const char* buffer, TMS2SC_ERR_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_DELIVERY_REPORT_RP_ERROR */
		case 0x0000: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2SC_ERR_Data (data, ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR), != ED_NO_ERRORS)
			INIT_c_SMS_DELIVERY_REPORT_RP_ERROR (data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR);
			retLen = DECODE_c_SMS_DELIVERY_REPORT_RP_ERROR (buffer, 0, data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_MS2SC_ERR_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC_ERR (const char* buffer, int len, TMS2SC_ERR_Data* data)
	{
		if (SetDecode_MS2SC_ERR (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_MS2SC_ERR (char* buffer, ED_EXLONG bitOffset, TMS2SC_ERR_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR: {
			retLen = ENCODE_c_SMS_DELIVERY_REPORT_RP_ERROR (buffer, 0, data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ERROR);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_MS2SC_ACK (const char* buffer, TMS2SC_ACK_Data* data, int bitLen)
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
	unsigned /****/ int key /*1*/= (unsigned)((unsigned char)buffer [0] & 3)/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0] & 3);
	
	ED_WARNING_REMOVER(key);
	switch (key) {
			/* Detect signal SMS_DELIVERY_REPORT_RP_ACK */
		case 0x0000: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TMS2SC_ACK_Data (data, ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK), != ED_NO_ERRORS)
			INIT_c_SMS_DELIVERY_REPORT_RP_ACK (data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK);
			retLen = DECODE_c_SMS_DELIVERY_REPORT_RP_ACK (buffer, 0, data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_MS2SC_ACK_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC_ACK (const char* buffer, int len, TMS2SC_ACK_Data* data)
	{
		if (SetDecode_MS2SC_ACK (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_MS2SC_ACK (char* buffer, ED_EXLONG bitOffset, TMS2SC_ACK_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK: {
			retLen = ENCODE_c_SMS_DELIVERY_REPORT_RP_ACK (buffer, 0, data->Data.fld_c_SMS_DELIVERY_REPORT_RP_ACK);
			break;
		}

		default:;
	}
	return retLen;
}

