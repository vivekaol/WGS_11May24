/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_board_update.c

$Octasic_Copyright: $

Description:

Implementation of the board update command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#endif

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       BoardUpdateCommand

Description:    Requests that the board power off, waking up at a later point
				in time.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 BoardUpdateCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD            BoardUpdateCmd;
    tOCTVC1_OBM_MSG_BOARD_UPDATE_RSP            BoardUpdateRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS           CmdExecuteParms;
    tOCT_UINT32                                 ulResult = cOCTVC1_RC_OK;
    int                                         lOptRetval;
    tOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM  ComponentType = cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_EMIC;
    char*                                       pszUpdateFilename = NULL;
	char*										pszAntennaConnector = "0,0";

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "e:f:c:" )) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'e':
				ComponentType = cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_EMIC;
				pszUpdateFilename = optarg;
				break;

			case 'f':
				ComponentType = cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND;
				pszUpdateFilename = optarg;
				break;

			case 'c':
				pszAntennaConnector = optarg;
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
    mOCTVC1_OBM_MSG_BOARD_UPDATE_CMD_DEF(&BoardUpdateCmd);
	BoardUpdateCmd.ulBoardIndex = g_Context.ulBoardId;
	BoardUpdateCmd.ulComponentType = ComponentType;

	if( pszUpdateFilename )
	{
		/*
		 * Make the command easier to use - if obm is running locally and we are given a relative path, prepend the
		 * current working directory, so as to provide an absolute path to obmd...
		 */
		if( g_Context.RemoteTcpAddress.IpAddress.aulIpAddress[0] == mBUILD_IP(127,0,0,1) &&
#ifndef _WIN32
			!(pszUpdateFilename[0] == '/') )
#else
			!(pszUpdateFilename[0] == '\\' || ( isalpha( pszUpdateFilename[0] ) && pszUpdateFilename[1] == ':' ) ) )
#endif
		{
			getcwd(BoardUpdateCmd.szFilename, sizeof(BoardUpdateCmd.szFilename));
#ifndef _WIN32
			strncat( BoardUpdateCmd.szFilename, "/", sizeof(BoardUpdateCmd.szFilename) - strlen(BoardUpdateCmd.szFilename) );
#else
			strncat( BoardUpdateCmd.szFilename, "\\", sizeof(BoardUpdateCmd.szFilename) - strlen(BoardUpdateCmd.szFilename) );
#endif
		}
		else
		{
			BoardUpdateCmd.szFilename[0] = 0;
		}
		strncat( BoardUpdateCmd.szFilename, pszUpdateFilename, sizeof(BoardUpdateCmd.szFilename) - strlen(BoardUpdateCmd.szFilename) );
	}

	if( pszAntennaConnector )
	{
		unsigned ulTransceiverId, ulAntennaId;
		if(sscanf( pszAntennaConnector, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
		{
			BoardUpdateCmd.AntennaConnectorId.usTransceiverIndex = ulTransceiverId; 
			BoardUpdateCmd.AntennaConnectorId.usAntennaIndex     = ulAntennaId;
		}
		else
		{
			fprintf(stderr, "Format error in the antenna connector ID list!\n");
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}
	}

	mOCTVC1_OBM_MSG_BOARD_UPDATE_CMD_SWAP(&BoardUpdateCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &BoardUpdateCmd;
    CmdExecuteParms.pRsp           = &BoardUpdateRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(BoardUpdateRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_UPDATE_RSP_SWAP(&BoardUpdateRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_BoardUpdateCmd =
{
	BoardUpdateCommand,
	"board_update", "bu",
	"<-e | -f> <filename> [-c <AntennaConnectorId>]",
	"Update a board component",
	"\n"
	"Arguments:\n"
	"  -e <filename>: Update the board's EMIC firmware. Provided filename needs to be accessible to obmd's local filesystem.\n"
	"  -f <filename>: Update the board's Rf FrontEnd firmware. Provided filename needs to be accessible to obmd's local filesystem.\n"
	"  -c <Antenna connector ID> : One of the antenna connectors to which the Rf FrontEnd to be updated is attached.\n"
	"                              This is a comma-separated pair of transceiver and antenna indexes.\n"
	"                              Example: 1,0. Default: 0,0\n"
	"\n"
};
