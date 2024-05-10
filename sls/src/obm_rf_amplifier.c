/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_rf_amplifier.c

$Octasic_Copyright: $

Description:

Implementation of the RF amplifier command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfAmplifierCommand

Description:    Configures the RF amplifiers that are in path.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RfAmplifierCommand( int argc, char* argv[] )
{
	tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD RfModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP RfModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    tOCT_UINT32                       ulResult = cOCTVC1_RC_OK;
    tOCT_INT32							lTargetTxPowerDbm = 0;
	unsigned							ulUsingTargetPowerFlag = 0;
	int									lOptRetval;
	char*                               pszAntennaConnector = "0,0";

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "c:p:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'c':
				pszAntennaConnector = optarg;
				break;

			case 'p':
				lTargetTxPowerDbm = (tOCT_INT32)(atof(optarg) * (1<<9));
				ulUsingTargetPowerFlag = 1;
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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_DEF(&RfModifyCmd);
	RfModifyCmd.ulBoardIndex = g_Context.ulBoardId;

	if( ulUsingTargetPowerFlag )
	{
		if( argc > optind )
		{
			printf( "Too many arguments\n" );
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}

		RfModifyCmd.lTargetTxPowerDbmQ9 = lTargetTxPowerDbm;
	}
	else
	{
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
			if( !strcmp( argv[optind], "off" ) ||
					!strcmp( argv[optind], "0" ) )
				RfModifyCmd.ulNumStagesActive = 0;
			else if( !strcmp( argv[optind], "1" ) )
				RfModifyCmd.ulNumStagesActive = 1;
			else if( !strcmp( argv[optind], "2" ) )
				RfModifyCmd.ulNumStagesActive = 2;
			else if( !strcmp( argv[optind], "3" ) )
				RfModifyCmd.ulNumStagesActive = 3;
			else
			{
				printf( "Invalid argument: \"%s\"\n", argv[optind] );
				ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
				goto ErrorHandling;
			}
		}
	}

	if( pszAntennaConnector )
	{
			unsigned ulTransceiverId, ulAntennaId;
			if(sscanf( pszAntennaConnector, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
			{
				RfModifyCmd.AntennaConnectorId.usTransceiverIndex = ulTransceiverId; 
				RfModifyCmd.AntennaConnectorId.usAntennaIndex     = ulAntennaId;
			}
			else
			{
				fprintf(stderr, "Format error in the antenna connector ID list!\n");
				ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
				goto ErrorHandling;
			}
	}

	mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_SWAP(&RfModifyCmd);

	/* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &RfModifyCmd;
    CmdExecuteParms.pRsp           = &RfModifyRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(RfModifyRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

	/* See if the changes were immediately applied by the HW */
	{
		tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD RfInfoCmd;
		tOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP RfInfoRsp;

		mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
		RfInfoCmd.ulBoardIndex = g_Context.ulBoardId;

		mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &RfInfoCmd;
		CmdExecuteParms.pRsp           = &RfInfoRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(RfInfoRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);

		/* Was the HW able to fulfill our requests? */
		if( RfInfoRsp.ulNumStagesActive != RfInfoRsp.ulNumStagesRequested )
		{
			printf("Warning: %u stages are active instead of %u. The requested amplification\n",
				RfInfoRsp.ulNumStagesActive, RfInfoRsp.ulNumStagesRequested);
			printf("may not be applied with the current filter settings. Update your filter\n");
			printf("settings for the changes to take effect. Refer to the board user guide\n");
			printf("to see which amplifier, driver & filter combinations are possible.\n");
		}
		else
		{
			/* No news is good news */
		}
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RfAmplifierCmd =
{
	RfAmplifierCommand,
	"rf_amplifier", "ra",
	"[-c <Antenna connector Id>] <off|1|2|3> | -p <power Dbm>",
	"Configure RF section Tx amplifiers and drivers.",
	"\n"
	"  Sets the desired Tx output power. This can be done in one of 2 ways: explicit enablement\n" 
	"  of active components OR desired output Tx power.\n"
	"\n"
	"  When explicit enablement is selected, sets the number of driver & amplification stages\n"
	"  that are active on a Tx path. These may be completely switched off or activated\n"
	"  incrementally (i.e. drivers & amplifiers are not controlled independently, but rather\n"
	"  activates on top of the other).\n"
	"\n"
	"  When specifying by output power, the Rf Frontend driver automatically sets amplification\n"
	"  stages and tx attenuation such that the targeted power is achieved, if possible. Depends\n"
	"  on support from DSP application and Rf Front-end driver.\n"
	"\n"
	"Valid options:\n"
	"  -c <Antenna connector ID> : One of the antenna connectors to which this Rf FrontEnd is attached.\n"
	"                              This is a comma-separated pair of transceiver and antenna indexes.\n"
	"                              Example: 1,0. Default: 0,0\n"
	"  -p <Power Dbm>            : Specify the target output power in dBm.\n"
};
