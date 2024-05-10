/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_gps_modify.c

$Octasic_Copyright: $

Description:

Implementation of the GPS modify command

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

Function:       GpsModifyCommand

Description:    Modifies the GPS antenna selection.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 GpsModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD    GpsModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_RSP    GpsModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
    tOCT_UINT32								ulGpsId = 0;
    tOCT_BOOL32								fSetSystemTime = cOCTVC1_DO_NOT_MODIFY;
	int										lOptRetval;
    tOCT_UINT32								ulMandatoryOption = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "t:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 't':
				if( strcmp( optarg, "on" ) == 0 )
					fSetSystemTime = cOCT_TRUE;
				else if( strcmp( optarg, "off" ) == 0 )
					fSetSystemTime = cOCT_FALSE;
				else
				{
					printf("Unknown option: \"%s\"\n", optarg );
					return -1;
				}
				ulMandatoryOption++;
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
		}
	}

	if( ulMandatoryOption == 0 )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else if( argc > optind )
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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD_DEF(&GpsModifyCmd);

	GpsModifyCmd.ulBoardIndex			= g_Context.ulBoardId;
	GpsModifyCmd.ulGpsId				= ulGpsId;
	GpsModifyCmd.ulSetSystemTimeFlag	= fSetSystemTime;


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
tOBM_COMMAND_DESCRIPTOR g_GpsModifyCmd =
{
	GpsModifyCommand,
	"gps_modify", "gm",
	"[-t on|off]",
	"Modifies GPS configurations, such as updating system time.",
	"\n"
	"Valid Options:\n"
	" -t ARG : Enable system time updates from GPS. ARG is one of :\n"
	"     'on'  : The system's time will be set using GPS module's time if valid (default).\n"
	"     'off' : The system time will not be set.\n"
	"\n"
};
