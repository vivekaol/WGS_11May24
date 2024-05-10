/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_gps_info.c

$Octasic_Copyright: $

Description:

Implementation of the GPS info command

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

extern int antennaType;

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       GpsInfoCommand

Description:    Retrieves information for a given gps.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 GpsInfoCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD	GpsInfoCmd;
    tOCTVC1_OBM_MSG_BOARD_INFO_GPS_RSP	GpsInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "psi:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
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
    mOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD_DEF(&GpsInfoCmd);
	GpsInfoCmd.ulBoardIndex = g_Context.ulBoardId;
	mOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD_SWAP(&GpsInfoCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &GpsInfoCmd;
    CmdExecuteParms.pRsp           = &GpsInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(GpsInfoRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_INFO_GPS_RSP_SWAP(&GpsInfoRsp);

    /*
     * Print out the retrieved information.
     */
	printf("+-- BOARD %u, GPS %u INFORMATION ------------------------------------------------------\n", g_Context.ulBoardId, GpsInfoRsp.ulGpsId );
	printf("| Description         : %s\n", GpsInfoRsp.szDescription );
	printf("| Reset signal state  : %s\n", mOCTVC1_OBM_SIGNAL_STATE_TO_STRING(GpsInfoRsp.ulResetState) );
	printf("| Antenna             : %s\n", mOCTVC1_OBM_GPS_ANTENNA_TO_STRING(GpsInfoRsp.ulAntenna) );
	printf("| Set system time     : %s\n", GpsInfoRsp.ulSetSystemTimeFlag == cOCT_FALSE ? "OFF" : "ON" );
    printf("|\n\n");

    antennaType = GpsInfoRsp.ulAntenna;

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_GpsInfoCmd =
{	GpsInfoCommand,
	"gps_info",
	"gi",
	"",
	"Display detailed GPS information.",
	""
};
