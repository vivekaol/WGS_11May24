/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_power_switch.c

$Octasic_Copyright: $

Description:

Implementation of the board power switch command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <stdlib.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       PowerSwitchCommand

Description:    Configures the board's power switch parameters.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 PowerSwitchCommand( int argc, char* argv[] )
{
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS			CmdExecuteParms;
    tOCT_UINT32									ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32									fMonitor = cOCT_FALSE;
    tOCT_BOOL32									fBypass = cOCTVC1_DO_NOT_MODIFY;
    tOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM	ulBypassMode = cOCTVC1_DO_NOT_MODIFY;
	int											lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "mx:y:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'x':
				if( strcmp( optarg, "on" ) == 0 )
					fBypass = cOCT_TRUE;
				else if( strcmp( optarg, "off" ) == 0 )
					fBypass = cOCT_FALSE;
				else
				{
					printf("Unknown option: \"%s\"\n", optarg );
					return -1;
				}
				break;
			case 'y':
				if( strcmp( optarg, "no_bat" ) == 0 )
					ulBypassMode = cOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM_NO_BATTERY;
				else if( strcmp( optarg, "always" ) == 0 )
					ulBypassMode = cOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM_ALWAYS;
				else
				{
					printf("Unknown option: \"%s\"\n", optarg );
					return -1;
				}
				break;

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

	/*
	 * No args; Report current settings.
	 */
	if( argc <= optind && fBypass == cOCTVC1_DO_NOT_MODIFY && ulBypassMode == cOCTVC1_DO_NOT_MODIFY )
	{
		tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD    PowerSwitchInfoCmd;
		tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_RSP    PowerSwitchInfoRsp;

		/*
		 * Prepare command data.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD_DEF(&PowerSwitchInfoCmd);
		PowerSwitchInfoCmd.ulBoardIndex = g_Context.ulBoardId;
		mOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD_SWAP(&PowerSwitchInfoCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &PowerSwitchInfoCmd;
		CmdExecuteParms.pRsp           = &PowerSwitchInfoRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(PowerSwitchInfoRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_RSP_SWAP(&PowerSwitchInfoRsp);

		/*
		 * Print the information.
		 */
		printf("+-- BOARD %u POWER SWITCH INFORMATION ------------------------------------------------------\n", g_Context.ulBoardId );
		printf("| Hold the switch  %ums to power up.\n",   PowerSwitchInfoRsp.ulUpEventTimeMs);
		printf("| Hold the switch %ums to power down.\n", PowerSwitchInfoRsp.ulDownEventTimeMs);
		printf("|\n");
		if( PowerSwitchInfoRsp.ulBypassFlag != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			printf("| Power switch bypass flag : %s\n", PowerSwitchInfoRsp.ulBypassFlag == 0 ? "OFF" : "ON" );
		}
		if( PowerSwitchInfoRsp.ulBypassMode != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			printf("| Power switch bypass mode : %s\n", PowerSwitchInfoRsp.ulBypassMode == cOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM_NO_BATTERY ? "NO BATTERY" : "ALWAYS" );
		}
		printf("|\n\n");
	}
	else if( argc > (optind + 2) )
	{
		printf( "Too many arguments\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}

	/*
	 * Args; Modify the Power switch behavior.
	 */
	else
	{
		tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD    PowerSwitchModifyCmd;
		tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_RSP    PowerSwitchModifyRsp;

		/*
		 * Prepare command data.
		 */
		mOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD_DEF(&PowerSwitchModifyCmd);
		PowerSwitchModifyCmd.ulBoardIndex = g_Context.ulBoardId;

		if( argc > optind )
		{
			PowerSwitchModifyCmd.ulUpEventTimeMs = strtoul(argv[optind], NULL, 0 );

			if( argc == (optind + 2) )
			{
				PowerSwitchModifyCmd.ulDownEventTimeMs = strtoul(argv[optind+1], NULL, 0);
			}
			else
			{
				PowerSwitchModifyCmd.ulDownEventTimeMs= PowerSwitchModifyCmd.ulUpEventTimeMs;
			}
		}

		PowerSwitchModifyCmd.ulBypassFlag = fBypass;
		PowerSwitchModifyCmd.ulBypassMode = ulBypassMode;

		mOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD_SWAP(&PowerSwitchModifyCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &PowerSwitchModifyCmd;
		CmdExecuteParms.pRsp           = &PowerSwitchModifyRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(PowerSwitchModifyRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_RSP_SWAP(&PowerSwitchModifyRsp);
	}

	if( fMonitor )
	{
		tOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EVT PowerSwitchEvt;
		tOCTVC1_PKT_API_INST_RECV_PARMS			InstReceiveParms;
		mOCTVC1_PKT_API_INST_RECV_PARMS_DEF(&InstReceiveParms)

		InstReceiveParms.PktRcvMask = cOCTVC1_PKT_API_RCV_MASK_EVENT;
		InstReceiveParms.pPayload = &PowerSwitchEvt;
		InstReceiveParms.ulMaxPayloadLength = sizeof(PowerSwitchEvt);

		printf("Waiting for incoming Power switch events; type ctrl-c to exit.\n" );

		do
		{
			ulResult = OctVc1PktApiInstRecv(g_Context.pPktApiInstance, &InstReceiveParms );

			if(	(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE) &&
				InstReceiveParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT				&&
				InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EID )
			{
				mOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EVT_SWAP(&PowerSwitchEvt);

				if( PowerSwitchEvt.ulOffMs == cOCTVC1_OBM_POWER_SWITCH_INFINITE_DURATION )
				{
					printf("Power switch has toggled! Had been off for infinite duration, has been on for %ums\n", PowerSwitchEvt.ulOnMs );
				}
				else
				{
					printf("Power switch has toggled! Had been off for %ums, has been on for %ums\n", PowerSwitchEvt.ulOffMs, PowerSwitchEvt.ulOnMs );
				}
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE);
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_PowerSwitchCmd =
{
	PowerSwitchCommand,
	"power_switch", "ps",
	"[-m] [-x on|off] [-y no_bat|always] [delay|up_delay down_delay]",
	"Report or configure the board's power switch behavior",
	"\n"
	" When no arguments are provided, reports the current power switch settings.\n"
	" When arguments are provided, configures the power switch.\n"
	"\n"
	"  [delay|up_delay down_delay]: Sets the time the switch must be in the on position before considering\n"
	"                               that an action is requested. If only one argument is provided, the\n"
	"                               delay will apply to both power up and power down requests. Otherwise, delay\n"
	"                               values are set independently. Value is in milliseconds; Hardware will honor\n"
	"                               the value within a 100ms granularity.\n"
	"\n"
	"Options\n"
	" -m : Monitor mode. Keep monitoring for reported power switch events.\n"
	" -x ARG : Power switch bypass functionality. ARG is one of :\n"
	"        'on'  : Power up the board immediately when a power supply is connected.\n"
	"        'off' : Power up the board only when the power switch is toggled.\n"
	" -y ARG : Power switch bypass mode (applicable only if bypass functionality is enabled). ARG is one of :\n"
	"     'no_bat' : Power switch bypass functionality applies only if no battery is present in the unit (default).\n"
	"     'always' : Power switch bypass functionality applies whether or not a battery is present in the unit.\n"
	"\n"
};
