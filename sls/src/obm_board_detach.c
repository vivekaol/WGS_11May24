/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_detach.c

$Octasic_Copyright: $

Description:

Implementation of the board detach command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       BoardDetachCommand

Description:    Requests that a dynamically loadable component be detached
				from the board.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardDetachCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_DETACH_CMD            BoardDetachCmd;
    tOCTVC1_OBM_MSG_BOARD_DETACH_RSP            BoardDetachRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS           CmdExecuteParms;
    tOCT_UINT32                                 ulResult = cOCTVC1_RC_OK;
    int                                         lOptRetval;
    tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM  ComponentType = cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND;
    char*                                       pszAntennaConnectorList = NULL;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "c:" )) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'c':
				pszAntennaConnectorList = optarg;
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
		}
	}

	if( argc > optind )
	{
		printf("Too many arguments!\n");
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
    mOCTVC1_OBM_MSG_BOARD_DETACH_CMD_DEF(&BoardDetachCmd);
	BoardDetachCmd.ulBoardIndex     = g_Context.ulBoardId; 
	BoardDetachCmd.ulComponentType  = ComponentType;       

	if( pszAntennaConnectorList )
	{
		char * pszNavigator = strtok(pszAntennaConnectorList, ":");
		do
		{
			unsigned ulTransceiverId, ulAntennaId;
			if(sscanf( pszNavigator, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
			{
				if(BoardDetachCmd.ulNumAntennaConnectors >= cOCTVC1_OBM_MAX_ANTENNA_CONNECTORS)
				{
					fprintf(stderr, "Too many antenna connectors!\n");
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
				else
				{
					BoardDetachCmd.aAntennaConnectors[BoardDetachCmd.ulNumAntennaConnectors].usTransceiverIndex = ulTransceiverId; 
					BoardDetachCmd.aAntennaConnectors[BoardDetachCmd.ulNumAntennaConnectors].usAntennaIndex     = ulAntennaId;
					BoardDetachCmd.ulNumAntennaConnectors++;
				}
			}
			else
			{
				fprintf(stderr, "Format error in the antenna connector ID list!\n");
				ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
				goto ErrorHandling;
			}

		} while ((pszNavigator = strtok(NULL, ":")));
	}

	mOCTVC1_OBM_MSG_BOARD_DETACH_CMD_SWAP(&BoardDetachCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &BoardDetachCmd;
    CmdExecuteParms.pRsp           = &BoardDetachRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(BoardDetachRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_DETACH_RSP_SWAP(&BoardDetachRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BoardDetachCmd =
{
	BoardDetachCommand,
	"board_detach", "bd",
	"[-c <Antenna connectors>]",
	"Dynamically detach a component from the board",
	"\n"
	"Arguments:\n"
	"  -c <AntennaConnectors>  : List of antenna connectors the Rf Frontend is attached to.\n"
	"                            If no antenna connector is provided, all attached RFE will be detached.\n"
	"                            This is a colon-separated list of antenna connector IDs, which is a comma-separated pair of\n"
	"                            transceiver and antenna connector Ids. Example:  0,0:0,1:1,0\n"
	"\n"
};
