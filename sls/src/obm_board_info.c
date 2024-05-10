/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_info.c

$Octasic_Copyright: $

Description:

Implementation of the DSP reset command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "fxLSocketInterfaceApi.h"
#ifdef OBM_TEMPERATURE_STATUS
extern fxLObmTemperatureStatusRsp gTemperatureStatusRsp;
#endif

extern unsigned int numberOfDsp;


/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       BoardInfoCommand

Description:    Displays information on the board we are attached to.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardInfoCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_INFO_CMD				BoardInfoCmd;
    tOCTVC1_OBM_MSG_BOARD_INFO_RSP				BoardInfoRsp;
    tOCTVC1_OBM_MSG_BOARD_STATS_CMD				BoardStatsCmd;
    tOCTVC1_OBM_MSG_BOARD_STATS_RSP				BoardStatsRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS			CmdExecuteParms;
    tOCT_UINT32                         ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32							fMonitor = cOCT_FALSE;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "m")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'm':
				fMonitor = cOCT_TRUE;
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
		}
	}

    /*
     * Init the API component we depend on.
     */
	ulResult = InitPktApi();
    if (cOCTVC1_RC_OK != ulResult)
    {
		return ulResult;
    }

	// Send command Board Info.
	{
		/*
		 * Prepare command data.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_CMD_DEF(&BoardInfoCmd);
		BoardInfoCmd.ulBoardIndex = g_Context.ulBoardId;
		mOCTVC1_OBM_MSG_BOARD_INFO_CMD_SWAP(&BoardInfoCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &BoardInfoCmd;
		CmdExecuteParms.pRsp           = &BoardInfoRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(BoardInfoRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_RSP_SWAP(&BoardInfoRsp);
	}

	// Send command Board Stats.
	{
		/*
		 * Prepare command data for the Board Stats.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_CMD_DEF(&BoardStatsCmd);
		BoardStatsCmd.ulBoardIndex = g_Context.ulBoardId;
		mOCTVC1_OBM_MSG_BOARD_STATS_CMD_SWAP(&BoardStatsCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &BoardStatsCmd;
		CmdExecuteParms.pRsp           = &BoardStatsRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(BoardStatsRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_RSP_SWAP(&BoardStatsRsp);
	}


    /*
     * Print the information.
     */
	printf("+-- BOARD %u INFORMATION ------------------------------------------------------\n", BoardInfoRsp.ulBoardIndex );
	printf("| \n" );
	printf("| Model                       : %s\n", BoardInfoRsp.szModel);
	printf("| Serial Number               : %s\n", BoardInfoRsp.szSerial);
	printf("| ProjectId                   : %s\n", BoardInfoRsp.szProjectId);
	if( strlen(BoardInfoRsp.szSupplementalInfo) != 0 )
	{
		char achBpIdKey[] = "bp_id=";
		char achKitSerialKey[] = "kit_serial=";
		char achKitModelKey[] = "kit_model=";
		char achSysSerialKey[] = "system_serial=";
		char achSysModelKey[] = "system_model=";
		char * pchString = BoardInfoRsp.szSupplementalInfo;
		char * pchStart;
		char * pchEnd;

		pchStart = strstr( pchString, achBpIdKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| BP ID                       : %s\n", pchStart + strlen(achBpIdKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achKitSerialKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Kit Serial                  : %s\n", pchStart + strlen(achKitSerialKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achSysSerialKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| System Serial               : %s\n", pchStart + strlen(achSysSerialKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achKitModelKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Kit Model                   : %s\n", pchStart + strlen(achKitModelKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achSysModelKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| System Model                : %s\n", pchStart + strlen(achSysModelKey) );
			pchString = pchEnd + 1;
		}
	}
	printf("| EMIC version                : %d\n", BoardInfoRsp.ulEmicVersion );
	if( BoardInfoRsp.ulEmicBuildNumber != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("| EMIC build number           : %d\n", BoardInfoRsp.ulEmicBuildNumber );
	}
	if( BoardInfoRsp.ulCpldVersion != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("| CPLD version                : %d\n", BoardInfoRsp.ulCpldVersion );
	}
	printf("| Number of DSPs              : %u\n", BoardInfoRsp.ulNumDsp );
	printf("| Number of GPSs              : %u\n", BoardInfoRsp.ulNumGps );
	printf("| Number of RF Front Ends     : %u\n", BoardInfoRsp.ulNumRfFrontEnds );
	printf("| Number of Batteries         : %u\n", BoardInfoRsp.ulNumBatteries );
	printf("| Power Source                : %s\n", mOCTVC1_OBM_POWER_SOURCE_TO_STRING(BoardInfoRsp.ulPowerSource) );	
	printf("| Ethernet Switch Present     : %s\n", BoardInfoRsp.ulEthernetSwitchFlag ? "TRUE" : "FALSE" );
	printf("| DSP-facing base MAC         : %02x:%02x:%02x:%02x:%02x:%02x\n",
		BoardInfoRsp.MacAddress.abyMacAddress[0], BoardInfoRsp.MacAddress.abyMacAddress[1],
		BoardInfoRsp.MacAddress.abyMacAddress[2], BoardInfoRsp.MacAddress.abyMacAddress[3],
		BoardInfoRsp.MacAddress.abyMacAddress[4], BoardInfoRsp.MacAddress.abyMacAddress[5]);
	printf("| RfMuxing mode               : %s\n", mOCTVC1_OBM_RF_MUXING_MODE_TO_STRING(BoardInfoRsp.ulRfMuxingMode) );
	printf("| Last powerup type           : %s\n", mOCTVC1_OBM_POWER_UP_TYPE_TO_STRING(BoardInfoRsp.ulPowerUpType) );
	if( BoardInfoRsp.ulLastSleepDuration != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("| Last sleep lasted           : %u seconds\n", BoardInfoRsp.ulLastSleepDuration );
	}
	printf("| \n" );
	printf("| Clocking \n" );
	printf("| \n" );
	if( BoardInfoRsp.ulOscillatorOwner == cOCTVC1_OBM_DSP_ID_ENUM_UNKNOWN )
	{
		printf("|  Oscillator Owner            : UNKNOWN\n" );
	}
	else
	{
		printf("|  Oscillator Owner            : %s\n", BoardInfoRsp.ulOscillatorOwner == cOCTVC1_OBM_DSP_ID_ENUM_PRIMARY ? "PRIMARY DSP" : "SECONDARY DSP" );
	}
	printf("|  Clock Tracking Converged    : %s\n", BoardInfoRsp.ulClockTrackingConvergedFlag ? "TRUE" : "FALSE" );
	printf("|  Clock manager mode          : %s\n", mOCTVC1_OBM_CLOCK_MGR_MODE_TO_STRING(BoardInfoRsp.ulClockManagerMode) );
	printf("|  Clock manager diagnostic    : %s\n", mOCTVC1_OBM_CLOCK_MGR_DIAG_TO_STRING(BoardInfoRsp.ulClockManagerDiag) );
	printf("|  Input ref clock Active      : %s\n", mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING(BoardInfoRsp.ulInputReferenceClock) );
	printf("|  Input ref clock Requested   : %s\n", mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING(BoardInfoRsp.ulInputReferenceClockRequested) );
	printf("|  Input reference clock state : %s\n", mOCTVC1_OBM_REFERENCE_CLOCK_STATE_TO_STRING(BoardInfoRsp.ulInputReferenceClockState) );
	printf("|  Output reference clock      : %s\n", mOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_TO_STRING(BoardInfoRsp.ulOutputReferenceClock) );

	printf("| \n" );
	printf("| Board health \n" );
	printf("| \n" );

        /* Number of DSP */
        numberOfDsp = BoardInfoRsp.ulNumDsp;

	if( BoardStatsRsp.ulVoltage != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("|  Voltage                     : %.3f V\n", ((float)BoardStatsRsp.ulVoltage)/10 );
	}
	if( BoardStatsRsp.lDspSensorTemp != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("|  DSP Sensor Temperature      : %.3f degree Celsius\n", ((float)BoardStatsRsp.lDspSensorTemp)/16 );
#ifdef OBM_TEMPERATURE_STATUS
                gTemperatureStatusRsp.dspTemperature =  ((float)BoardStatsRsp.lDspSensorTemp)/16;
#endif

	}
	if( BoardStatsRsp.lRfSensorTemp != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("|  RF Sensor Temperature       : %.3f degree Celsius\n", ((float)BoardStatsRsp.lRfSensorTemp)/16 );
#ifdef OBM_TEMPERATURE_STATUS
                gTemperatureStatusRsp.rfTemperature = ((float)BoardStatsRsp.lRfSensorTemp)/16;
#endif
	}
	if( BoardStatsRsp.ulFanErrorFlag != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("|  Fan Error Flag              : %s\n", BoardStatsRsp.ulFanErrorFlag ? "TRUE" : "FALSE" );
	}

	// Monitor for events...
	if( fMonitor )
	{
		union PAYLOAD_EVT
		{
			tOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EVT		Alarm;
			tOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EVT				Fan;
			tOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EVT	RefClock;

		} PayloadEvt;

		tOCTVC1_PKT_API_INST_RECV_PARMS			   InstReceiveParms;
		mOCTVC1_PKT_API_INST_RECV_PARMS_DEF(&InstReceiveParms);


		InstReceiveParms.PktRcvMask = cOCTVC1_PKT_API_RCV_MASK_EVENT;
		InstReceiveParms.pPayload	= &PayloadEvt;
		InstReceiveParms.ulMaxPayloadLength = sizeof(PayloadEvt);

		printf("\n\n");
		printf("Waiting for incoming events; type ctrl-c to exit.\n" );

		do
		{
			ulResult = OctVc1PktApiInstRecv( g_Context.pPktApiInstance, &InstReceiveParms );

			if(	(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE) &&
				InstReceiveParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT )
			{
				if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EID )
				{
					float	fDspSensorTemp;

					mOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EVT_SWAP(&PayloadEvt.Alarm);

					fDspSensorTemp	= (float)PayloadEvt.Alarm.lDspSensorTemp;

					printf("Temperature event!\n");
					printf("HighTempWarningFlag = %d\n", PayloadEvt.Alarm.ulHighTempWarningFlag );
					printf("LowTempWarningFlag  = %d\n", PayloadEvt.Alarm.ulLowTempWarningFlag );
					printf("DspSensorTemp       = %.3f\n", fDspSensorTemp / 16 );
				}
				else if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EID )
				{
					mOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EVT_SWAP(&PayloadEvt.Fan);

					printf("Fan event!\n");
					printf("FanErrorFlag         = %d\n", PayloadEvt.Fan.ulFanErrorFlag );
				}
				else if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EID )
				{
					mOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EVT_SWAP(&PayloadEvt.RefClock);

					printf("Ref Clock Overridden event!\n");
					printf("Input ref clock Active      : %s\n", mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING(PayloadEvt.RefClock.ulInputReferenceClock) );
					printf("Input ref clock Requested   : %s\n", mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING(PayloadEvt.RefClock.ulInputReferenceClockRequested) );
				}
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE);
	}

	printf("|\n\n");

	return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BoardInfoCmd =
{
	BoardInfoCommand,
	"board_info", "bi",
	"[-m]",
	"Print board information.",
	"\n"
	"Options\n"
	" -m : Monitor mode. Keep monitoring for events reported by fan, temperature and reference clock.\n"
	""
};
