/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_gps_reset.c

$Octasic_Copyright: $

Description:

Implementation of the GPS reset command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>

#include "../../common/octosal/include/octosal.h"

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  CONSTANTS  *****************************/

/* The GPS has 5 secopnds to complete its boot process.
 * WARNING: Update the command help if you change this value. */
#define cBOOT_WAIT_TIMEOUT_MS	(5000)	

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       GpsResetCommand

Description:    Resets the Gps.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 GpsResetCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD	ResetGpsCmd;
    tOCTVC1_OBM_MSG_BOARD_RESET_GPS_RSP	ResetGpsRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32							fColdStart = cOCT_FALSE;
	tOCTVC1_OBM_SIGNAL_STATE_ENUM		SignalAction = cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "ca:")) >=0)
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

			case 'c':
				fColdStart = cOCT_TRUE;
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
    mOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD_DEF(&ResetGpsCmd);
	ResetGpsCmd.ulBoardIndex = g_Context.ulBoardId;
	ResetGpsCmd.ulState = SignalAction;
	ResetGpsCmd.ulColdStartFlag = fColdStart;

	mOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD_SWAP(&ResetGpsCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &ResetGpsCmd;
    CmdExecuteParms.pRsp           = &ResetGpsRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(ResetGpsRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_RESET_GPS_RSP_SWAP(&ResetGpsRsp);

    return ulResult;

ErrorHandling:
	ClosePktApi();
    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_GpsResetCmd =
{	GpsResetCommand,
	"gps_reset",
	"gr",
	"[-a on|off|cycle] [-c]",
	"Cycle, set or clear reset state on a GPS.",
	"\n"
	"Valid Options:\n"
	" -a ARG : Action to perform on the reset pin. ARG is one of (default is 'cycle'):\n"
	"          'on'   : assert the reset signal (put the GPS in reset).\n"
	"          'off'  : deassert the reset signal (take the GPS out of reset).\n"
	"          'cycle': pulse the reset signal.\n"
	" -c     : Perform a cold start upon reset release\n"
	"\n"
};
