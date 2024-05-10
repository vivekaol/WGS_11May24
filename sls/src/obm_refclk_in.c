/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_refclk_in.c

$Octasic_Copyright: $

Description:

Implementation of the reference clock input selection command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RefClkInCommand

Description:    Modifies the reference clock input.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RefClkInCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD    BoardModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RSP    BoardModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    tOCT_UINT32                       ulResult = cOCTVC1_RC_OK;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS)) >=0)
	{
		if(lOptRetval == '?') return -1;

		if( ProcessCommonOptions() < 0 )
		{
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_CMD_DEF(&BoardModifyCmd);
	BoardModifyCmd.ulBoardIndex = g_Context.ulBoardId;

	if( argc <= optind )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else if( argc > (optind + 1) )
	{
		printf( "Too many arguments\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else
	{
		if( !strcmp( argv[optind], "gps" ) )
			BoardModifyCmd.ulInputReferenceClock = cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_GPS;
		else if( !strcmp( argv[optind], "ext" ) )
			BoardModifyCmd.ulInputReferenceClock = cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_EXTERNAL;
		else if( !strcmp( argv[optind], "synce" ) )
			BoardModifyCmd.ulInputReferenceClock = cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_SYNCE;
		else if( !strcmp( argv[optind], "back" ) )
			BoardModifyCmd.ulInputReferenceClock = cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_BACKPLANE;
		else if( !strcmp( argv[optind], "disc" ) )
			BoardModifyCmd.ulInputReferenceClock = cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_DISCONNECTED;
		else
		{
			printf( "Invalid argument: \"%s\"\n", argv[optind] );
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}
	}

	mOCTVC1_OBM_MSG_BOARD_MODIFY_CMD_SWAP(&BoardModifyCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &BoardModifyCmd;
    CmdExecuteParms.pRsp           = &BoardModifyRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(BoardModifyRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_MODIFY_RSP_SWAP(&BoardModifyRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RefClkInCmd =
{
	RefClkInCommand,
	"refclk_in", "ci",
	"<gps|ext|synce|back|disc>",
	"Select the input reference clock.",
	"\n"
	"  Selects the source of the input reference clock.\n"
	"   gps  : Onboard GPS module (use the gps_reset command to ensure a reference pulse is provided)\n"
	"   ext  : External reference clock connector\n"
	"   synce: Synchronous Ethernet clock from the onboard ethernet switch\n"
	"   back : Backplane connector\n"
	"   disc : No reference clock is provided to the DSP(s)\n"
	"\n"
};
