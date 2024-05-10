/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_system_info.c

$Octasic_Copyright: $

Description:

Implementation of System Info command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       SystemInfoCommand

Description:    Displays information on system.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 SystemInfoCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD		SystemInfoCmd;
    tOCTVC1_OBM_MSG_SYSTEM_INFO_RSP		SystemInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32                         ulResult = cOCTVC1_RC_OK;
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

	// Send command Battery Stats.
	{
		/*
		 * Prepare command data for the Battery Stats.
		 */
		mOCTVC1_OBM_MSG_SYSTEM_INFO_CMD_DEF(&SystemInfoCmd);
		mOCTVC1_OBM_MSG_SYSTEM_INFO_CMD_SWAP(&SystemInfoCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &SystemInfoCmd;
		CmdExecuteParms.pRsp           = &SystemInfoRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(SystemInfoRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_SYSTEM_INFO_RSP_SWAP(&SystemInfoRsp);
	}


    /*
     * Print the information.
     */
	printf("+--------------------- SYSTEM INFORMATION ---------------------\n" );
	printf("| Obm DHCP Server Enable Flag   : %s\n", SystemInfoRsp.ulDhcpServerEnableFlag ? "TRUE" : "FALSE" );
	printf("| Obm TFTP Server Enable Flag   : %s\n", SystemInfoRsp.ulTftpServerEnableFlag ? "TRUE" : "FALSE" );

	printf("|\n\n");

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_SystemInfoCmd =
{
	SystemInfoCommand,
	"system_info", "si",
	"",
	"Print system information.",
	"\n"
};
