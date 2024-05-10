/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm.c

$Octasic_Copyright: $

Description:

Command-line utility to interface with obmd, the obm daemon.

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#define OCTVC1_OPT_DECLARE_DEFAULTS

/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Octvc1 API header files */
//#include "main/octvc1_main_api.h"
//#include "main/octvc1_main_default.h"
//#include "main/octvc1_main_api_swap.h"
#include "octvc1_macro.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_version.h"

/* Verbose OCTVC1 return code */
//#define OCTVC1_RC2STRING_DECLARE
//#include "octvc1_rc2string.h"

#include "../../common/octtransapi/include/octtransapi.h"
#include "../../common/octtransapi/include/octtransapi_default.h"
#include "../../common/octtransapi/octtransapi_tcp/include/octtransapi_tcp.h"
#include "../../common/octtransapi/octtransapi_tcp/include/octtransapi_tcp_default.h"

#include "../inc/obm.h"

/***************************  TYPE DEFINITIONS  ******************************/

/***************************  GLOBAL VARIABLES  ******************************/

tOBM_CONTEXT g_Context = {0};

unsigned char initializationDone = 0;

extern tOBM_COMMAND_DESCRIPTOR g_HelpCmd;
tPOBM_COMMAND_DESCRIPTOR g_Commands[] = {

	&g_HelpCmd,
	&g_BatteryStatsCmd,
	&g_BoardInfoCmd,
	&g_BoardStopCmd,
	&g_BoardAttachCmd,
	&g_BoardDetachCmd,
	&g_BoardUpdateCmd,
	&g_BoardModifyCmd,
	&g_SystemInfoCmd,
	&g_SystemModifyCmd,
	&g_ConfigWriteCmd,
	&g_DspInfoCmd,
	&g_DspResetCmd,
	&g_DspModifyCmd,
	&g_EthSwitchStatsCmd,
	&g_EthSwitchModifyCmd,
	&g_EthSwitchInfoCmd,
	&g_GpsResetCmd,
	&g_GpsInfoCmd,
	&g_GpsModifyCmd,
	&g_GpsStatsCmd,
	&g_GpsAntennaCmd,
	&g_ReadI2cCmd,
	&g_WriteI2cCmd,
	&g_InfoCmd,
	&g_PowerSwitchCmd,
	&g_RefClkInCmd,
	&g_RefClkOutCmd,
	&g_RfInfoCmd,
	&g_RfModifyCmd,
	&g_RfStatsCmd,
	&g_RfAmplifierCmd,
	&g_RfFrequencyCmd,
};
#define cHELP_COMMAND_ID	(0)

/***************************  CONSTANTS  *****************************/

#ifndef cOBM_CLI_VERSION_STRING
#	define cOBM_CLI_VERSION_STRING	"<unversioned>"
#endif

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       Usage

Description:    Displays a help screen for the program.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static void Usage(void)
{
	int i;
	unsigned max_strlen = 0;

	printf("OctBts Board Management utility\n");
	printf("CLI version %s, API Version %02u.%02u.%02u-B%u\n", cOBM_CLI_VERSION_STRING,
		cOCTVC1_OBM_VERSION_MAJOR, cOCTVC1_OBM_VERSION_MINOR, cOCTVC1_OBM_VERSION_MAINTENANCE, cOCTVC1_OBM_VERSION_BUILD);
	printf("Built on " __DATE__ " " __TIME__ "\n");
	printf("Copyright (c) Octasic Inc. All rights reserved.\n\n\n");

    printf("Usage: obm <command> [options] [args]\n");
	printf("\n");
	printf("Application commands:\n");
	printf(" \n");
	for( i = 0; i < mCOUNTOF(g_Commands); ++i )
	{
		if( strlen(g_Commands[i]->szCommand) + strlen(g_Commands[i]->szShorthand) > max_strlen )
		{
			max_strlen = strlen(g_Commands[i]->szCommand) + strlen(g_Commands[i]->szShorthand);
		}
	}
	for( i = 0; i < mCOUNTOF(g_Commands); ++i )
	{
		unsigned cur_strlen = 0;
		unsigned j;

		printf("  %s", g_Commands[i]->szCommand);
		if( g_Commands[i]->szShorthand  )
		{
			printf(" (%s)", g_Commands[i]->szShorthand);
		}
		else
		{
			printf("     ", g_Commands[i]->szShorthand);
		}
		cur_strlen = strlen(g_Commands[i]->szCommand) + strlen(g_Commands[i]->szShorthand);

		printf(" " );
		for( j=0; j<max_strlen-cur_strlen; j++ )
			printf(" ");
		printf(": " );
		printf("%s\n", g_Commands[i]->szDesc );
	}
	printf("\n");
	printf("Common options:\n");
	printf("  -b ID : Board index to interoperate with. Default is 0.\n");
	printf("  -r IP : IP address of the daemon to interoperate with. Default is 127.0.0.1.\n");

}

#if 0
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       ParseCommandLine

Description:    Lookup command in command array

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int ParseCommandLine(int argc, char* argv[])
{
	int i;
	for( i = 0; i < mCOUNTOF(g_Commands); ++i )
	{
		if( strcmp( argv[1], g_Commands[i]->szCommand ) == 0 || 
			strcmp( argv[1], g_Commands[i]->szShorthand ) == 0 )
		{
			return i;
		}
	}

	printf( "Unknown command: \"%s\"\n", argv[1] );
	return -1;
}
#endif

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       ProcessCommonOptions

Description:    Process command-line options that are common to all ocmmands

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int ProcessCommonOptions( void )
{
	switch(optopt)
	{
		case 'b':
			g_Context.ulBoardId = strtoul(optarg, NULL, 0);
			break;

		case 'r':
			{
				unsigned aulIp[4];
				if( sscanf(optarg, "%u.%u.%u.%u", &aulIp[0], &aulIp[1], &aulIp[2], &aulIp[3] ) == 4)
				{
					g_Context.RemoteTcpAddress.IpAddress.aulIpAddress[0] = 
						((aulIp[0] & 0xff) << 24) |
						((aulIp[1] & 0xff) << 16) |
						((aulIp[2] & 0xff) <<  8) |
						((aulIp[3] & 0xff) <<  0) ;
				}
				else
				{
					printf("Invalid remote IP: \"%s\"\n", optarg );
					return -1;
				}
			}
			break;

		default:
			return -1;
	}

	return 0;
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       InitPktApi

Description:    Initiates a Packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 InitPktApi(void)
{
	tOCT_UINT32 ulResult;
	tOCTTRANSAPI_INIT_PARMS InitParms;
	tOCTVC1_PKT_API_INST_GET_SIZE_PARMS GetSizeParms;
	tOCTVC1_PKT_API_INST_INIT_PARMS		InstInitParms;
	tOCTVC1_PKT_API_CNCT_OPEN_PARMS		CnctOpenParms;
	tOCTVC1_PKT_API_SESS_OPEN_PARMS		SessionOpenParms;
	tOCTTRANSAPI_DESTINATION_ADD_PARMS	DestinationAddParms;

	mOCTTRANSAPI_INIT_PARMS_DEF( &InitParms );

        if((NULL == g_Context.pPktApiSession) || (NULL == g_Context.pPktApiConnection) || 
           (NULL == g_Context.pPktApiInstance) || (NULL == g_Context.hTransport)) 
        {
           g_Context.pPktApiSession = NULL; 
           g_Context.pPktApiConnection = NULL; 
           g_Context.pPktApiInstance = NULL; 
           g_Context.hTransport = NULL; 
           initializationDone = 0;
        }

        if (0 == initializationDone)
        {
            ulResult = OctTransApiInit( &InitParms );

            if(  cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		tOCTTRANSAPI_TCP_OPEN TcpOpenParm;

		mOCTTRANSAPI_TCP_OPEN_DEF( &TcpOpenParm );
		TcpOpenParm.fServer = cOCT_FALSE;
		TcpOpenParm.fUseSelect = cOCT_FALSE;
		TcpOpenParm.LocalTcpAddress.IpAddress.aulIpAddress[0] = 0;
		TcpOpenParm.LocalTcpAddress.IpAddress.ulIpVersion = cOCTDEV_IP_VERSION_ENUM_4;
		TcpOpenParm.LocalTcpAddress.ulTcpPort = 0;

		ulResult = OctTransApiTcpOpen( NULL, &TcpOpenParm, &g_Context.hTransport );
            }

            if(  cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		mOCTTRANSAPI_DESTINATION_ADD_PARMS_DEF( &DestinationAddParms );

		DestinationAddParms.ulDestinationAddrSize = sizeof(g_Context.RemoteTcpAddress);
		DestinationAddParms.pDestinationAddr = &g_Context.RemoteTcpAddress;

		ulResult = OctTransApiDestinationAdd( g_Context.hTransport, &DestinationAddParms );

            }

            if(  cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		mOCTVC1_PKT_API_INST_GET_SIZE_PARMS_DEF( &GetSizeParms );
		mOCTVC1_PKT_API_INST_INIT_PARMS_DEF( &InstInitParms );

		InstInitParms.ulMaxConnection = 1;
		InstInitParms.ulMaxSession    = 1;
		InstInitParms.ulMaxSyncCmd    = 8;
		InstInitParms.ulMaxRetry      = 1;
		InstInitParms.ulMaxPendingEvt = 16;
		InstInitParms.usSessionInstanceStart = 1;
		InstInitParms.fUseExternalTransport = cOCT_TRUE;
		InstInitParms.abyLocalMac[0] = 0xcc;

		GetSizeParms.pInitParms = &InstInitParms;

		ulResult = OctVc1PktApiInstGetSize( &GetSizeParms );
            }

            if(  cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		g_Context.pPktApiInstance = (tPOCTVC1_PKT_API_INST)calloc( 1, GetSizeParms.ulRequiredSize );
		ulResult = OctVc1PktApiInstInit( g_Context.pPktApiInstance, &InstInitParms );
            }

            if( cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		mOCTVC1_PKT_API_CNCT_OPEN_PARMS_DEF( &CnctOpenParms );

		CnctOpenParms.hTransDest = DestinationAddParms.hDestination;
		ulResult = OctVc1PktApiCnctOpen( g_Context.pPktApiInstance, &CnctOpenParms );
		g_Context.pPktApiConnection = CnctOpenParms.pConnection;
            }

            if(  cOCTTRANSAPI_RC_ERROR_NONE == ulResult )
            {
		mOCTVC1_PKT_API_SESS_OPEN_PARMS_DEF( &SessionOpenParms );
                SessionOpenParms.ulControlProcessFifoId = cOCTVC1_FIFO_ID_MGW_CONTROL;

		ulResult = OctVc1PktApiSessOpen(CnctOpenParms.pConnection, &SessionOpenParms );
		g_Context.pPktApiSession = SessionOpenParms.pSession;

                initializationDone = 1;
            }

            if( cOCTTRANSAPI_RC_ERROR_NONE != ulResult )
            {
		printf("Failed to communicate with the daemon\n");
            }
	}
        else
        {
            ulResult = cOCTTRANSAPI_RC_ERROR_NONE;
        }

	return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       ClosePktApi

Description:    Tears down the Packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void ClosePktApi(void)
{
	tOCTVC1_PKT_API_SESS_CLOSE_PARMS	SessionCloseParms;
	tOCTVC1_PKT_API_CNCT_CLOSE_PARMS	ConnectionCloseParms;
	tOCTVC1_PKT_API_INST_TERM_PARMS	InstanceTermParms;
	tOCTTRANSAPI_TERMINATE_PARMS TransTerm;

	mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF( &SessionCloseParms );
	mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF( &ConnectionCloseParms );
	mOCTVC1_PKT_API_INST_TERM_PARMS_DEF( &InstanceTermParms );
	mOCTTRANSAPI_TERMINATE_PARMS_DEF( &TransTerm );

	/* Close the PkatApi objects */
	if( NULL != g_Context.pPktApiSession )
	{
		OctVc1PktApiSessClose( g_Context.pPktApiSession, &SessionCloseParms );
		g_Context.pPktApiSession = NULL;
	}

	if( NULL != g_Context.pPktApiConnection )
	{
		OctVc1PktApiCnctClose( g_Context.pPktApiConnection, &ConnectionCloseParms );
		g_Context.pPktApiConnection = NULL;
	}

	if( NULL != g_Context.pPktApiInstance )
	{
		OctVc1PktApiInstTerm( g_Context.pPktApiInstance, &InstanceTermParms );
		free( g_Context.pPktApiInstance );
		g_Context.pPktApiInstance = NULL;
	}

	/* Close the transport */
	OctTransApiTcpClose( g_Context.hTransport );

	OctTransApiTerminate( &TransTerm );
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       initializeObm

Description:    Initialize OBM Context

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void initializeObm (void)
{
    printf("Initializing Board Management Utility\n");
    printf("CLI version %s, API Version %02u.%02u.%02u-B%u\n", 
           cOBM_CLI_VERSION_STRING, cOCTVC1_OBM_VERSION_MAJOR, 
           cOCTVC1_OBM_VERSION_MINOR, cOCTVC1_OBM_VERSION_MAINTENANCE,
           cOCTVC1_OBM_VERSION_BUILD);

    /* Set option defaults */
    g_Context.RemoteTcpAddress.IpAddress.aulIpAddress[0] = mBUILD_IP(127,0,0,1);
    g_Context.RemoteTcpAddress.IpAddress.ulIpVersion = cOCTDEV_IP_VERSION_ENUM_4;
    g_Context.RemoteTcpAddress.ulTcpPort = cOCTVC1_OBM_SERVER_PORT;
    g_Context.ulBoardId = 0;
}

#if 0
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       main

Description:    Main program.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

int main(int argc, char *argv[])
{
	int lCommandId;
	tOCT_UINT32 ulRc;

	printf("\n");

	/* Set option defaults */
	g_Context.RemoteTcpAddress.IpAddress.aulIpAddress[0] = mBUILD_IP(127,0,0,1);
	g_Context.RemoteTcpAddress.IpAddress.ulIpVersion = cOCTDEV_IP_VERSION_ENUM_4;
	g_Context.RemoteTcpAddress.ulTcpPort = cOCTVC1_OBM_SERVER_PORT;
	g_Context.ulBoardId = 0;

	if( argc < 2 )
	{
		printf("Type 'obm help' for usage.\n" );
		return 0;
	}

	lCommandId = ParseCommandLine(argc, argv);
	if( lCommandId < 0 )
		return -1;

	/* Run the command */
	ulRc = g_Commands[lCommandId]->pfctCallBack(argc-1, &argv[1]);

	/* Only output description for OBM error. */
	if( ( ulRc & 0xFFFF0000 ) == cOCTVC1_OBM_RC_BASE )
	{
		tOCT_UINT32 ulErrorDescRc;

		fprintf(stderr, "Error 0x%08x (%s)\n", ulRc, mOCTVC1_RC2STRING(ulRc) );

		ulErrorDescRc = InitPktApi();
		if( ulErrorDescRc == cOCTVC1_RC_OK )
		{
			tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD	LastErrorCmd;
			tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_RSP	LastErrorRsp;
			tOCTVC1_PKT_API_CMD_EXECUTE_PARMS			CmdExecuteParms;

			mOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD_DEF(&LastErrorCmd);
			mOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD_SWAP(&LastErrorCmd);

			mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
			CmdExecuteParms.pCmd           = &LastErrorCmd;
			CmdExecuteParms.pRsp           = &LastErrorRsp;
			CmdExecuteParms.ulMaxRspLength = sizeof(LastErrorRsp);

			ulErrorDescRc = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);

			mOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_RSP_SWAP(&LastErrorRsp);
			if( ulErrorDescRc == cOCTVC1_RC_OK )
			{
				fprintf( stderr, "Error description: %s\n", LastErrorRsp.szLastErrorMsg );
			}

			ClosePktApi();
		}
	}
	else if( ulRc )
	{
		fprintf(stderr, "Error 0x%08x (%s)\n", ulRc, mOCTVC1_RC2STRING(ulRc) );
	}

	/* API return codes are 32 bits trim to smaller values */
	return ulRc ? -2 : 0;
}
#endif

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       HelpCommand

Description:    Displays a help screen for the program.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 HelpCommand( int argc, char* argv[] )
{
    tOCT_UINT32     ulResult = cOCTVC1_RC_OK;

	if( argc == 1 )
	{
		Usage();
	}
	else
	{
		int i;
		for( i = 0; i < mCOUNTOF(g_Commands); ++i )
		{
			if( strcmp( argv[1], g_Commands[i]->szCommand ) == 0 || 
				strcmp( argv[1], g_Commands[i]->szShorthand ) == 0 )
			{
				printf( "%s\n\n", g_Commands[i]->szDesc);
				printf( "Usage: Obm %s %s\n%s", argv[1], g_Commands[i]->szSyntax, g_Commands[i]->szHelp);
				break;
			}
		}

		if( i == mCOUNTOF(g_Commands) )
		{
			fprintf( stderr, "Unknown command: \"%s\"\n", argv[1] );
			return -1;
		}
	}

	return ulResult;
}
/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_HelpCmd =
{
	HelpCommand,
	"help", "h",
	"",
	"Get help on a command.",
	""
};


