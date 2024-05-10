/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_modify.c

$Octasic_Copyright: $

Description:

Implementation of the board modification command

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

Function:       BoardModifyCommand

Description:    Modifies the Transceivers mode.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD    BoardModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RSP    BoardModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS   CmdExecuteParms;
    tOCT_UINT32                         ulResult = cOCTVC1_RC_OK;
	int									lOptRetval;
	tOCTVC1_OBM_RF_MUXING_MODE_ENUM		ulRfMuxingMode = cOCTVC1_DO_NOT_MODIFY;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "x:" )) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'x':
				if( strcmp( optarg, "standard" ) == 0 )
					ulRfMuxingMode = cOCTVC1_OBM_RF_MUXING_MODE_ENUM_STANDARD;
				else if( strcmp( optarg, "cross" ) == 0 )
					ulRfMuxingMode = cOCTVC1_OBM_RF_MUXING_MODE_ENUM_CROSS;
				else if( strcmp( optarg, "1dsp2radio" ) == 0 )
					ulRfMuxingMode = cOCTVC1_OBM_RF_MUXING_MODE_ENUM_SINGLE_DSP_DUAL_RADIO;
				else if( strcmp( optarg, "2dsp1radio" ) == 0 )
					ulRfMuxingMode = cOCTVC1_OBM_RF_MUXING_MODE_ENUM_DUAL_DSP_SINGLE_RADIO;
				else
				{
					printf("Unknown rf muxing mode: \"%s\"\n", optarg );
					return -1;
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

	if( ulRfMuxingMode == cOCTVC1_DO_NOT_MODIFY )
	{
		fprintf( stderr, "No option provided; Notinh to do!\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}

	if( argc > (optind + 1) )
	{
		fprintf( stderr, "Too many arguments\n" );
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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_CMD_DEF(&BoardModifyCmd);
	BoardModifyCmd.ulBoardIndex = g_Context.ulBoardId;
	BoardModifyCmd.ulRfMuxingMode = ulRfMuxingMode;

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
tOBM_COMMAND_DESCRIPTOR g_BoardModifyCmd =
{
	BoardModifyCommand,
	"board_modify", "bm",
	"-x <standard|cross|1dsp2radio|2dsp1radio>",
	"Modify board-level properties.",
	"\n"
	" -x ARG: Select the rf muxing of board. ARG is one of:\n"
	"         standard	: Standard mode\n"
	"         cross	    : Cross Radio mode\n"
	"         1dsp2radio: Primary DSP with both Radios\n"
	"         2dsp1radio: Primary DSP(Tx) and Secondary DSP(Rx) with Radio1\n"
	"\n"
};
