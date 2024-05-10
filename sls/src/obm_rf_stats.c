/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_rf_stats.c

$Octasic_Copyright: $

Description:

Implementation of the RF stats command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>
#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

/***************************  PRIVATE FUNCTIONS  *****************************/


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfOutputAlarmInfo

Description:    Print RF alarm infot to screen.
				Return number of lines used in the printf output.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

unsigned RfOutputAlarmInfo( tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	* pAntennaConnectorId, tOCTVC1_OBM_RF_ALARM_INFO *	f_pAlarmInfo )
{
	unsigned ulNumLines = 11;

    printf("|\n");
	printf("| Alarm info ( antenna connector %u,%u ):\n", pAntennaConnectorId->usTransceiverIndex, pAntennaConnectorId->usAntennaIndex );
    printf("|\n");
	printf("| ulTxPowerOverloadFlag  : %d\n", f_pAlarmInfo->ulTxPowerOverloadFlag );
	printf("| ulRxPowerOverloadFlag  : %d\n", f_pAlarmInfo->ulRxPowerOverloadFlag );
	printf("| ulTxFaultFlag          : %d\n", f_pAlarmInfo->ulTxFaultFlag );
	printf("| ulRxFaultFlag          : %d\n", f_pAlarmInfo->ulRxFaultFlag );
	printf("| ulTemperatureFaultFlag : %d\n", f_pAlarmInfo->ulTemperatureFaultFlag );
	printf("| ulOvercurrentFlag      : %d\n", f_pAlarmInfo->ulOvercurrentFlag );
	printf("| ulPowerFailureFlag     : %d\n", f_pAlarmInfo->ulPowerFailureFlag );
	printf("| ulFanFlag              : %d\n", f_pAlarmInfo->ulFanFlag );
	if( f_pAlarmInfo->ulOtherFlag == cOCT_TRUE && f_pAlarmInfo->szNotificationInfo[0] != 0 )
	{
		printf("| NotificationInfo       : %s\n", f_pAlarmInfo->szNotificationInfo );
		ulNumLines++;
	}

	return ulNumLines;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfStatsCommand

Description:    Retrieves statistics for a given rf.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RfStatsCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD	RfStatsCmd;
    tOCTVC1_OBM_MSG_BOARD_STATS_RF_RSP	RfStatsRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32							fMonitor = cOCT_FALSE;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId = { 0 };
	int									lOptRetval;
	tOCT_BOOL32							ulResetStatsFlag = cOCT_FALSE;
    tOCT_BOOL32							fVerbose = cOCT_FALSE;
	unsigned 							i;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "vkmc:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'k':
				ulResetStatsFlag = cOCT_TRUE;
				break;

			case 'm':
				fMonitor = cOCT_TRUE;
				break;

			case 'v':
				fVerbose = cOCT_TRUE;
				break;

			case 'c':
				{
					unsigned ulTransceiverId, ulAntennaId;
					if(sscanf( optarg, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
					{
						AntennaConnectorId.usTransceiverIndex = ulTransceiverId; 
						AntennaConnectorId.usAntennaIndex     = ulAntennaId;
					}
					else
					{
						fprintf(stderr, "Format error in the antenna connector ID list!\n");
						ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
						goto ErrorHandling;
					}
				}
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

    /*
     * Prepare command data.
     */
    mOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD_DEF(&RfStatsCmd);
	RfStatsCmd.ulBoardIndex			= g_Context.ulBoardId;
	RfStatsCmd.AntennaConnectorId	= AntennaConnectorId;
	RfStatsCmd.ulResetStatsFlag		= ulResetStatsFlag;

	mOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD_SWAP(&RfStatsCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &RfStatsCmd;
    CmdExecuteParms.pRsp           = &RfStatsRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(RfStatsRsp);

	while( 1 )
	{
		unsigned ulCursorLineCount = 0;

		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_RF_RSP_SWAP(&RfStatsRsp);

		/*
		 * Print out the retrieved statsrmation.
		 */
		ulCursorLineCount = 3;

		printf("+-- BOARD %u, RF STATISTICS ----------------------------------\n", g_Context.ulBoardId );
		printf("|\n");
		ulCursorLineCount += RfOutputAlarmInfo( &RfStatsRsp.AntennaConnectorId, &RfStatsRsp.AlarmInfo );
		printf("| ulPowerConsumptionMw   : %d\n", RfStatsRsp.ulPowerConsumptionMw );

		if( RfStatsRsp.alTemperature[0] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			ulCursorLineCount += 2;
			printf("| \n" );
			printf("| Temperature : \n" );
			for( i=0; i<cOCTVC1_OBM_MAX_TEMP_SENSORS; i++ )
			{
				if( RfStatsRsp.alTemperature[i] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
				{
					printf("|    Sensor %d : %.3f degree Celsius\n", i, ((float)RfStatsRsp.alTemperature[i])/16 );
					ulCursorLineCount++;
				}
			}
		}
		if( RfStatsRsp.alMeasuredTxPowerDbmQ9[0] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			ulCursorLineCount += 2;
			printf("| \n" );
			printf("| MeasuredTxPowerDbm : \n" );
			for( i=0; i<cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS; i++ )
			{
				if( RfStatsRsp.alMeasuredTxPowerDbmQ9[i] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
				{
					if( RfStatsRsp.alMeasuredTxPowerDbmQ9[i] == cOCTVC1_OBM_RF_DBM_Q9_VALUE_POWER_OFF )
					{
						printf("|    PowerDetector %d : OFF\n", i );
					}
					else if( RfStatsRsp.alMeasuredTxPowerDbmQ9[i] == cOCTVC1_OBM_RF_DBM_Q9_VALUE_POWER_ON )
					{
						printf("|    PowerDetector %d : ON\n", i );
					}
					else
					{
						printf("|    PowerDetector %d : %.1f dBm\n", i, ((float)RfStatsRsp.alMeasuredTxPowerDbmQ9[i])/(1<<9) );
					}
					ulCursorLineCount++;
				}
			}
		}
		if( RfStatsRsp.alAdjustedTxPowerDbmQ9[0] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			ulCursorLineCount += 2;
			printf("| \n" );
			printf("| AdjustedTxPowerDbm : \n" );
			for( i=0; i<cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS; i++ )
			{
				if( RfStatsRsp.alAdjustedTxPowerDbmQ9[i] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
				{
					printf("|    PowerDetector %d : %.1f dBm\n", i, ((float)RfStatsRsp.alAdjustedTxPowerDbmQ9[i])/(1<<9) );
					ulCursorLineCount++;
				}
			}
		}
		if( RfStatsRsp.alMeasuredRxPowerDbmQ9[0] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			ulCursorLineCount += 2;
			printf("| \n" );
			printf("| MeasuredRxPowerDbm : \n" );
			for( i=0; i<cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS; i++ )
			{
				if( RfStatsRsp.alMeasuredRxPowerDbmQ9[i] != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
				{
					printf("|    PowerDetector %d : %.1f dBm\n", i, ((float)RfStatsRsp.alMeasuredRxPowerDbmQ9[i])/(1<<9) );
					ulCursorLineCount++;
				}
			}
		}
		printf("|\n\n");
		ulCursorLineCount += 2;

		if( fVerbose == cOCT_FALSE )
		{
			break;
		}

		// Wait for 300 ms
		OctOsalSleepMs(300);

		/* VT100 Cursor control
		- Cursor Home:		\x1B[{ROW};{COLUMN}H	or		\x1B[H
		- Cursor up:		\x1B[{ROW}A
		- Cursor down:		\x1B[{ROW}B
		- Cursor Forward:	\x1B[{COLUMN}C
		- Cursor Backward:	\x1B[{COLUMN}D
		*/
		for( i=0; i<ulCursorLineCount; i++ )
		{
			printf("\x1B[2K");	// Erase Line
			printf("\x1B[A");	// Move cursor up by 1 line.
		}
	}

	// Monitor for events...
	if( fMonitor )
	{
		tOCTVC1_OBM_MSG_BOARD_RF_ALARM_EVT			RfAlarm;
		tOCTVC1_PKT_API_INST_RECV_PARMS				InstReceiveParms;
		mOCTVC1_PKT_API_INST_RECV_PARMS_DEF(&InstReceiveParms);


		InstReceiveParms.PktRcvMask = cOCTVC1_PKT_API_RCV_MASK_EVENT;
		InstReceiveParms.pPayload	= &RfAlarm;
		InstReceiveParms.ulMaxPayloadLength = sizeof(RfAlarm);

		printf("\n\n");
		printf("Waiting for incoming events; type ctrl-c to exit.\n" );
		printf("\n\n");

		do
		{
			ulResult = OctVc1PktApiInstRecv( g_Context.pPktApiInstance, &InstReceiveParms );

			if(	(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE) &&
				InstReceiveParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT )
			{
				if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_RF_ALARM_EID )
				{
					mOCTVC1_OBM_MSG_BOARD_RF_ALARM_EVT_SWAP(&RfAlarm);

					printf("| RF Alarm event!\n" );
					RfOutputAlarmInfo( &RfAlarm.AntennaConnectorId, &RfAlarm .AlarmInfo);
				}
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE);

		printf("|\n\n");
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RfStatsCmd =
{	RfStatsCommand,
	"rf_stats",
	"rs",
	"[-c <Antenna connector Id>] [-k]"
	"",
	"Display detailed RF statistics.",
	"\n"
	"Valid options:\n"
	" -c <Antenna connector Id> : One of the antenna connectors to which this Rf FrontEnd is attached.\n"
	"                             This is a comma-separated pair of transceiver and antenna indexes.\n"
	"                             Example: 1,0. Default: 0,0\n"
	" -k     : Clears all the counters after read. example obm rs -k\n"
};
