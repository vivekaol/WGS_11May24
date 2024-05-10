/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_refclk_out.c

$Octasic_Copyright: $

Description:

Implementation of the reference clock output selection command

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

Function:       RefClkOutCommand

Description:    Modifies the reference clock output.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RefClkOutCommand( int argc, char* argv[] )
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
		if( !strcmp( argv[optind], "in" ) )
			BoardModifyCmd.ulOutputReferenceClock = cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INPUT_REFERENCE;
		else if( !strcmp( argv[optind], "local" ) )
			BoardModifyCmd.ulOutputReferenceClock = cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_LOCAL_MAIN_CLOCK;
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
tOBM_COMMAND_DESCRIPTOR g_RefClkOutCmd =
{
	RefClkOutCommand,
	"refclk_out", "co",
	"<in|local>",
	"Select the output reference clock.",
	"\n"
	"  Selects the source of the output reference clock.\n"
	"   in:    The selected refclk_in is also routed to the refclk_out connector\n"
	"   local: The local 30.72Mhz clock is routed to the refclk_out connector\n"
	"\n"
};
