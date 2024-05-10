/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_config_write.c

$Octasic_Copyright: $

Description:

Implementation of the configuration write command

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
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"


/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       ConfigWriteCommand

Description:    Write configuration to disk.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 ConfigWriteCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD	ConfigWriteCmd;
    tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_RSP	ConfigWriteRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS )) >=0)
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
    mOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD_DEF(&ConfigWriteCmd);

	mOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD_SWAP(&ConfigWriteCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &ConfigWriteCmd;
    CmdExecuteParms.pRsp           = &ConfigWriteRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(ConfigWriteRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_ConfigWriteCmd =
{	ConfigWriteCommand,
	"config_write", "cw",
	"",
	"Write configuration to disk.",
	"\n"
};
