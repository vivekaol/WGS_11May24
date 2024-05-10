/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_stop.c

$Octasic_Copyright: $

Description:

Implementation of the board stop command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       BoardStopCommand

Description:    Requests that the board power off, waking up at a later point
				in time.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardStopCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_STOP_CMD		BoardStopCmd;
    tOCTVC1_OBM_MSG_BOARD_STOP_RSP		BoardStopRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCTVC1_OBM_BOARD_STOP_ACTION_ENUM  ulAction = cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN;
	int									lOptRetval;

    mOCTVC1_OBM_MSG_BOARD_STOP_CMD_DEF(&BoardStopCmd);

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "nw:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'n':
				if( ulAction != cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN )
				{
					printf( "'-n' used with incompatible option\n" );
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
				else
				{
					ulAction = cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_REBOOT;
				}
				break;

			case 'w':
				if( ulAction != cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN )
				{
					printf( "'-w' used with incompatible option\n" );
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
				else
				{
					int lNumItemsScan = 0;
					ulAction = cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_WAKEUP_AT_DATE;

					// Parse the time information
					lNumItemsScan = sscanf( optarg, "%u:%u:%u",	&BoardStopCmd.WakeupDateTime.ulHour,
																&BoardStopCmd.WakeupDateTime.ulMinutes,
																&BoardStopCmd.WakeupDateTime.ulSeconds	);
					if( lNumItemsScan != 3 )
					{
						printf( "Invalid time format\n" );
						ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
						goto ErrorHandling;
					}

					if( argc > optind && argv[optind][0] != '-' )
					{
						lNumItemsScan = sscanf( argv[optind], "%u/%u/%u",	&BoardStopCmd.WakeupDateTime.ulDay,
																			&BoardStopCmd.WakeupDateTime.ulMonth,
																			&BoardStopCmd.WakeupDateTime.ulYear		);
						if( lNumItemsScan != 3 )
						{
							printf( "Invalid date format\n" );
							ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
							goto ErrorHandling;
						}
						optind++;
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

	if( argc < optind )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else if( argc > (optind + 2) )
	{
		printf( "Too many arguments\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
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
	BoardStopCmd.ulBoardIndex = g_Context.ulBoardId;

	/* Set Action. */
	BoardStopCmd.ulAction = ulAction;

	mOCTVC1_OBM_MSG_BOARD_STOP_CMD_SWAP(&BoardStopCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &BoardStopCmd;
    CmdExecuteParms.pRsp           = &BoardStopRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(BoardStopRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_STOP_RSP_SWAP(&BoardStopRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BoardStopCmd =
{
	BoardStopCommand,
	"board_stop", "bs",
	"[-n | -w h:m:s [d/m/y]]",
	"Power off the board, optionally waking it back up at a later point in time.",
	"When no options are provided, the board shuts down immediately (and does not reboot).\n"
	"\n"
	"Options:\n"
	" -w h:m:s [d/m/y]:  Shut down and wakeup at specific time/date. Time is in 24h format.\n"
	"                    If no date is specified, it is assumed that the board is to wakeup\n"
	"                    at the next occurrence of the specified time.\n"
	" -n              :  Shut down and reboot now.\n"
	"\n"
};
