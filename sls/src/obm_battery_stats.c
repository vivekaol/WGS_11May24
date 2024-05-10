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
#include <stdlib.h>
#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

#ifdef FXL_BOARD_STATUS
extern fxLObmBatteryStatusInd gBatteryStatusInd;
#endif

#ifdef OBM_BATTERY_STATUS
extern fxLObmBatteryStatusRsp gBatteryStatusRsp;
#endif

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       BatteryStatsCommand

Description:    Displays information on the board we are attached to.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BatteryStatsCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD		BatteryStatsCmd;
    tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_RSP		BatteryStatsRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS			CmdExecuteParms;
    tOCT_UINT32                         ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32							fMonitor = cOCT_FALSE;
	int									lOptRetval;
	tOCT_UINT32							ulBatteryId = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "mi:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'm':
				fMonitor = cOCT_TRUE;
				break;
			
			case 'i':
				ulBatteryId = strtoul(optarg, NULL, 0);
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

	// Send command Battery Stats.
	{
		/*
		 * Prepare command data for the Battery Stats.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD_DEF(&BatteryStatsCmd);
		BatteryStatsCmd.ulBoardIndex = g_Context.ulBoardId;
		BatteryStatsCmd.ulBatteryId = ulBatteryId;
		mOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD_SWAP(&BatteryStatsCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &BatteryStatsCmd;
		CmdExecuteParms.pRsp           = &BatteryStatsRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(BatteryStatsRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_RSP_SWAP(&BatteryStatsRsp);
	}

        /*
         * Fill the Battery Status Indication.
         */
#ifdef FXL_BOARD_STATUS
        gBatteryStatusInd.boardId              = BatteryStatsRsp.ulBoardIndex;
        gBatteryStatusInd.batteryId            = BatteryStatsRsp.ulBatteryId;
        gBatteryStatusInd.batteryPowerLevel    = BatteryStatsRsp.ulBatteryPowerLevel;
        gBatteryStatusInd.batteryChargingFlag  = BatteryStatsRsp.ulBatteryChargingFlag;
        gBatteryStatusInd.batteryFaultFlag     = BatteryStatsRsp.ulBatteryFaultFlag;
        gBatteryStatusInd.batteryTempFaultFlag = BatteryStatsRsp.ulBatteryTempFaultFlag;
        gBatteryStatusInd.batteryLowWaringFlag = BatteryStatsRsp.ulBatteryLowLevelWarnFlag;
#endif
        /*
         * Fill the Battery Status Response.
         */
#ifdef OBM_BATTERY_STATUS
        gBatteryStatusRsp.boardId              = BatteryStatsRsp.ulBoardIndex;
        gBatteryStatusRsp.batteryId            = BatteryStatsRsp.ulBatteryId;
        gBatteryStatusRsp.batteryPowerLevel    = BatteryStatsRsp.ulBatteryPowerLevel;
        gBatteryStatusRsp.batteryChargingFlag  = BatteryStatsRsp.ulBatteryChargingFlag;
        gBatteryStatusRsp.batteryFaultFlag     = BatteryStatsRsp.ulBatteryFaultFlag;
        gBatteryStatusRsp.batteryTempFaultFlag = BatteryStatsRsp.ulBatteryTempFaultFlag;
        gBatteryStatusRsp.batteryLowWaringFlag = BatteryStatsRsp.ulBatteryLowFlag;
#endif
        

    /*
     * Print the information.
     */
	printf("+-- BOARD %u BATTERY %u STATISTICS ------------------------------------------------------\n", BatteryStatsRsp.ulBoardIndex, BatteryStatsRsp.ulBatteryId );
	printf("| Battery power level      : %d %%\n", BatteryStatsRsp.ulBatteryPowerLevel );
	printf("| Battery Charging Flag    : %s\n", BatteryStatsRsp.ulBatteryChargingFlag ? "TRUE" : "FALSE" );
	printf("| Battery Fault Flag       : %s\n", BatteryStatsRsp.ulBatteryFaultFlag ? "TRUE" : "FALSE" );
	printf("| Battery Temp Fault Flag  : %s\n", BatteryStatsRsp.ulBatteryTempFaultFlag ? "TRUE" : "FALSE" );
	printf("| Battery Low  Flag        : %s\n", BatteryStatsRsp.ulBatteryLowFlag ? "TRUE" : "FALSE" );

	// Monitor for events...
	if( fMonitor )
	{
		union PAYLOAD_EVT
		{
			tOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EVT		Battery;

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
				if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EID )
				{
					mOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EVT_SWAP(&PayloadEvt.Battery);

					printf("Battery event! - id : %u\n", PayloadEvt.Battery.ulBatteryId);
					printf("BatteryChargingFlag     = %d\n", PayloadEvt.Battery.ulBatteryChargingFlag );
					printf("BatteryFaultFlag        = %d\n", PayloadEvt.Battery.ulBatteryFaultFlag );
					printf("BatteryTempFaultFlag    = %d\n", PayloadEvt.Battery.ulBatteryTempFaultFlag );
					printf("BatteryLowLevelWarnFlag = %d\n", PayloadEvt.Battery.ulBatteryLowLevelWarnFlag );
					printf("BatteryPowerLevel       = %d %%\n\n", PayloadEvt.Battery.ulBatteryPowerLevel );
				}
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE);
	}

	printf("|\n\n");

    return cOCTVC1_RC_OK;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BatteryStatsCmd =
{
	BatteryStatsCommand,
	"battery_stats", "bat",
	"[-i 0..9] [-m]",
	"Print board battery statistics.",
	"\n"
	"Options\n"
	" -i ARG : Act on Battery id, where ARG is any value 0..9. Default is 0.\n"
	" -m	: Monitor mode. Keep monitoring for reported battery events.\n"
	""
};
