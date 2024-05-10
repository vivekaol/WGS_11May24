/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_attach.c

$Octasic_Copyright: $

Description:

Implementation of the board attach command

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

Function:       BoardAttachCommand

Description:    Requests that the board power off, waking up at a later point
				in time.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardAttachCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD            BoardAttachCmd;
    tOCTVC1_OBM_MSG_BOARD_ATTACH_RSP            BoardAttachRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS           CmdExecuteParms;
    tOCT_UINT32                                 ulResult = cOCTVC1_RC_OK;
    int                                         lOptRetval;
    tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM  ComponentType = cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND;
    char*                                       pszManufacturer = NULL;
    char*                                       pszModel = NULL;
    char*                                       pszAdditionalInfo = NULL;
    char*                                       pszAntennaConnectorList = NULL;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "a:f:c:" )) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'a':
				pszAdditionalInfo = optarg;
				break;

			case 'c':
				pszAntennaConnectorList = optarg;
				break;

			case 'f':
				pszManufacturer = optarg;
				pszModel = strchr(optarg, ':');
				if(pszModel)
				{
					*pszModel = 0;
					pszModel++;
				}
				else
				{
					printf("Missing model information!");
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
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
    mOCTVC1_OBM_MSG_BOARD_ATTACH_CMD_DEF(&BoardAttachCmd);
	BoardAttachCmd.ulBoardIndex     = g_Context.ulBoardId; 
	BoardAttachCmd.ulComponentType  = ComponentType;       

	if( pszManufacturer )
	{
		strncpy( BoardAttachCmd.szManufacturer, pszManufacturer, sizeof(BoardAttachCmd.szManufacturer ) );
	}
	if( pszModel )
	{
		strncpy( BoardAttachCmd.szModel, pszModel, sizeof(BoardAttachCmd.szModel ) );
	}
	if( pszAdditionalInfo )
	{
		strncpy( BoardAttachCmd.szAttachInfo, pszAdditionalInfo, sizeof(BoardAttachCmd.szAttachInfo ) );
	}
	if( pszAntennaConnectorList )
	{
		char * pszNavigator = strtok(pszAntennaConnectorList, ":");

		if( pszManufacturer == NULL || pszModel == NULL )
		{
			fprintf(stderr, "Must provide option -f <manufacturer:model>.\n" );
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}

		do
		{
			unsigned ulTransceiverId, ulAntennaId;
			if(sscanf( pszNavigator, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
			{
				if(BoardAttachCmd.ulNumAntennaConnectors >= cOCTVC1_OBM_MAX_ANTENNA_CONNECTORS)
				{
					fprintf(stderr, "Too many antenna connectors!\n");
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
				else
				{
					BoardAttachCmd.aAntennaConnectors[BoardAttachCmd.ulNumAntennaConnectors].usTransceiverIndex = ulTransceiverId; 
					BoardAttachCmd.aAntennaConnectors[BoardAttachCmd.ulNumAntennaConnectors].usAntennaIndex     = ulAntennaId;
					BoardAttachCmd.ulNumAntennaConnectors++;
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

	mOCTVC1_OBM_MSG_BOARD_ATTACH_CMD_SWAP(&BoardAttachCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &BoardAttachCmd;
    CmdExecuteParms.pRsp           = &BoardAttachRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(BoardAttachRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_ATTACH_RSP_SWAP(&BoardAttachRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BoardAttachCmd =
{
	BoardAttachCommand,
	"board_attach", "ba",
	"[-f <manufacturer:model> -c <Antenna connectors>] [-a <supplemental info>]",
	"Dynamically attach a component to the board",
	"\n"
	"Arguments:\n"
	"  -f <manufacturer:model> : Attach an RF Frontend to the board. Manufacturer and model information must match that of an available plugin.\n"
	"  -c <AntennaConnectors>  : List of antenna connectors the Rf Frontend is connected to.\n"
	"                            If no antenna connector is provided, board will probe for all available plugin.\n"
	"                            This is a colon-separated list of antenna connector IDs, which is a comma-separated pair of\n"
	"                            transceiver and antenna connector Ids. Example:  0,0:0,1:1,0\n"
	"  [-a <supplemental info>]: Provide additional information to the managing plugin. This is plugin-specific, but typically identifies the location of the component on the board.\n"
	"\n"
};
