/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_gps_antenna.c

$Octasic_Copyright: $

Description:

Implementation of the GPS antenna selection command

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
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       GpsAntennaCommand

Description:    Modifies the GPS antenna selection.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 GpsAntennaCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD    GpsModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_RSP    GpsModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
    tOCT_UINT32								ulGpsId = 0;
	int										lOptRetval;

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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD_DEF(&GpsModifyCmd);
	GpsModifyCmd.ulBoardIndex	= g_Context.ulBoardId;
	GpsModifyCmd.ulGpsId		= ulGpsId;

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
		if( !strcmp( argv[optind], "on" ) )
			GpsModifyCmd.ulAntennaSelection = cOCTVC1_OBM_GPS_ANTENNA_ENUM_ONBOARD;
		else if( !strcmp( argv[optind], "ext" ) )
			GpsModifyCmd.ulAntennaSelection = cOCTVC1_OBM_GPS_ANTENNA_ENUM_BOARD_CONNECTOR;
		else
		{
			printf( "Invalid argument: \"%s\"\n", argv[optind] );
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}
	}

	mOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD_SWAP(&GpsModifyCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &GpsModifyCmd;
    CmdExecuteParms.pRsp           = &GpsModifyRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(GpsModifyRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_RSP_SWAP(&GpsModifyRsp);

    return ulResult;

ErrorHandling:
	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_GpsAntennaCmd =
{
	GpsAntennaCommand,
	"gps_antenna", "ga",
	"<on|ext>",
	"Select the GPS antenna.",
	"\n"
	"  Selects the source of the GPS antenna.\n"
	"   on : GPS use an onboard antenna( welded on the PCB ).\n"
	"   ext: GPS use an external connector for the antenna.\n"
	"\n"
};
