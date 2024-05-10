/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_dsp_reset.c

$Octasic_Copyright: $

Description:

Implementation of the DSP reset command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../common/octosal/include/octosal.h"

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"


/***************************  CONSTANTS  *****************************/

/* The DSP has 10 seconds to complete its boot process. */
#define cBOOT_WAIT_TIMEOUT_S	10

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       DspResetCommand

Description:    Resets the Dsp.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 DspResetCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD	ResetDspCmd;
    tOCTVC1_OBM_MSG_BOARD_RESET_DSP_RSP	ResetDspRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_UINT32							ulDspId = 0;
	tOCTVC1_OBM_SIGNAL_STATE_ENUM		SignalAction = cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "a:psi:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'a':
				if( strcmp( optarg, "on" ) == 0 )
					SignalAction = cOCTVC1_OBM_SIGNAL_STATE_ENUM_ASSERT;
				else if( strcmp( optarg, "off" ) == 0 )
					SignalAction = cOCTVC1_OBM_SIGNAL_STATE_ENUM_DEASSERT;
				else if( strcmp( optarg, "cycle" ) == 0 )
					SignalAction = cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE;
				else
				{
					printf("Unknown signal action: \"%s\"\n", optarg );
					return -1;
				}
				break;

			case 'p':
				ulDspId = 0;
				break;

			case 's':
				ulDspId = 1;
				break;

			case 'i':
				ulDspId = strtoul(optarg, NULL, 0);
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
    mOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD_DEF(&ResetDspCmd);
	ResetDspCmd.ulBoardIndex = g_Context.ulBoardId;

	if( argc > optind )
	{
		strncpy((char*)ResetDspCmd.szFileName, argv[optind], sizeof(ResetDspCmd.szFileName));
	}

	ResetDspCmd.ulDspId = ulDspId;
	ResetDspCmd.ulState = SignalAction;

	mOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD_SWAP(&ResetDspCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &ResetDspCmd;
    CmdExecuteParms.pRsp           = &ResetDspRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(ResetDspRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_RESET_DSP_RSP_SWAP(&ResetDspRsp);


	/* Wait for boot progress event */
	if( SignalAction == cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE )
	{
		union PAYLOAD_EVT
		{
			tOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EVT		BootProg;

		} PayloadEvt;

		tOCT_UINT32	ulTimeStart;
		tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM		LastBootProgress = cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_UNKNOWN;
		tOCTVC1_PKT_API_INST_RECV_PARMS			InstReceiveParms;
		mOCTVC1_PKT_API_INST_RECV_PARMS_DEF(&InstReceiveParms);


		InstReceiveParms.PktRcvMask = cOCTVC1_PKT_API_RCV_MASK_EVENT;
		InstReceiveParms.pPayload	= &PayloadEvt;
		InstReceiveParms.ulMaxPayloadLength = sizeof(PayloadEvt);
		InstReceiveParms.ulTimeoutMs = 100; // Add a timeout when waiting for events.

		ulTimeStart = OctOsalGetTimeMs();

		do
		{
			ulResult = OctVc1PktApiInstRecv( g_Context.pPktApiInstance, &InstReceiveParms );

			if(	(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE) &&
				InstReceiveParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT )
			{
				if( InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EID )
				{
					mOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EVT_SWAP(&PayloadEvt.BootProg);

					if( PayloadEvt.BootProg.ulDspId != ulDspId )
					{
						// This is not an event for us, skip this event.
						continue;
					}

					if( LastBootProgress != PayloadEvt.BootProg.ulBootProgress )
					{
						printf( "%s -> %s\n", mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING(LastBootProgress), mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING(PayloadEvt.BootProg.ulBootProgress) );
						LastBootProgress = PayloadEvt.BootProg.ulBootProgress;
					}
				}
			}

			if(	LastBootProgress == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_COMPLETE				||
				LastBootProgress == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_EXT_TFTP_STARTED		||
				LastBootProgress == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_END_WITH_ERROR		||
				LastBootProgress == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_STAGE1_ERROR			||
				(OctOsalGetTimeMs() - ulTimeStart) >= cBOOT_WAIT_TIMEOUT_S * 1000			)
			{
				break;
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE || ulResult == cOCTVC1_PKT_API_RC_TIMEOUT);

		switch( LastBootProgress )
		{
			case cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_STAGE1_ERROR:
			{
				tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD DspInfoCmd;
				tOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP DspInfoRsp;

				mOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD_DEF(&DspInfoCmd);

				DspInfoCmd.ulDspId = ulDspId;
				DspInfoCmd.ulBoardIndex = g_Context.ulBoardId;

				mOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD_SWAP(&DspInfoCmd);

				// Prepare command execution
				mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
				CmdExecuteParms.pCmd           = &DspInfoCmd;
				CmdExecuteParms.pRsp           = &DspInfoRsp;
				CmdExecuteParms.ulMaxRspLength = sizeof(DspInfoRsp);

				// 
				// Execute the command.
				//
				ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
				if (cOCTVC1_RC_OK != ulResult)
				{
					goto ErrorHandling;
				}

				mOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP_SWAP(&DspInfoRsp);

				printf("Boot process completes, with the Stage1 bootloader reporting 0x%08x (%s)\n", 
					DspInfoRsp.BootStatus.ulErrorCode, "");
			}
			break;

		case cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_END_WITH_ERROR:
			printf("Boot process ended with a DHCP/TFTP error\n");
			break;

		case cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_COMPLETE:
			printf("Boot process completed successfully.\n");
			break;

		case cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_EXT_TFTP_STARTED:
			printf("Boot process started from external TFTP server.\n");
			break;

		default:
			printf("Boot process timed out, with the DSP in the \"%s\" boot progress state.\n", mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING(LastBootProgress));
			break;
		}
	}

	return ulResult;

ErrorHandling:
	ClosePktApi();
        return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_DspResetCmd =
{	DspResetCommand,
	"dsp_reset",
	"dr",
	"[-a on|off|cycle] [-p|-s|-i 0..9] [filename]",
	"Cycle, set or clear reset state on a DSP.",
	"\n"
	" When a filename is specified, this file will be provided to the DSP\n"
	" at reboot. Otherwise, the previously configured file will be used.\n"
	"\n"
	" If the action is 'cycle', obm will wait until the DSP status indicates\n"
	" ERROR or COMPLETE before exiting, unless a " STR(cBOOT_WAIT_TIMEOUT_S) " second timeout expires.\n"
	"\n"
	"Valid Options:\n"
	" -a ARG : Action to perform on the reset pin. ARG is one of (default is 'cycle'):\n"
	"          'on'   : assert the reset signal (put the DSP in reset).\n"
	"          'off'  : deassert the reset signal (take the DSP out of reset).\n"
	"          'cycle': pulse the reset signal, effectively rebooting the DSP.\n"
	" -p     : Act on primary DSP.\n"
	" -s     : Act on secondary DSP.\n"
	" -i ARG : Act on DSP ARG, where ARG is any value 0..9. Default is 0.\n"
	"\n"
};
