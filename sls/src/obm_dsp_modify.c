/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_dsp_modify.c

$Octasic_Copyright: $

Description:



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
#include <stdlib.h>
/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       DspModifyCommand

Description:    Modifies DSP configurations.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 DspModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD	DspModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_RSP	DspModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
	tOCTVC1_IP_ADDRESS						ulNextAssignedIp = { 0 };
    tOCT_UINT32							ulDspId = 0;
	int										lOptRetval;
	unsigned								ulSpecialOption = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "psi:y:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'y':
				{
					unsigned aulIp[4];

					ulSpecialOption++;

					if( sscanf(optarg, "%u.%u.%u.%u", &aulIp[0], &aulIp[1], &aulIp[2], &aulIp[3] ) == 4 )
					{
						ulNextAssignedIp.aulIpAddress[0] = 
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

			case 'p':
				ulDspId = 0;
				break;

			case 's':
				ulDspId = 1;
				break;

			case 'i':
				ulDspId = strtoul(optarg, NULL, 0);
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
		}
	}

	if( ulSpecialOption == 0 )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        return ulResult;
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
	 * Prepare command data
	 */
	mOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD_DEF(&DspModifyCmd);

	memcpy( DspModifyCmd.ulNextAssignedIp.aulIpAddress, ulNextAssignedIp.aulIpAddress, sizeof(DspModifyCmd.ulNextAssignedIp) );
	DspModifyCmd.ulDspId = ulDspId;

	mOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD_SWAP(&DspModifyCmd);

	/* 
	 * Execute the command.
	 */
	mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
	CmdExecuteParms.pCmd           = &DspModifyCmd;
	CmdExecuteParms.pRsp           = &DspModifyRsp;
	CmdExecuteParms.ulMaxRspLength = sizeof(DspModifyRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
	if (cOCTVC1_RC_OK != ulResult)
	{
		goto ErrorHandling;
	}

	/*
	 * Swap the command response.
	 */
	mOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_RSP_SWAP(&DspModifyRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_DspModifyCmd =
{
	DspModifyCommand,
	"dsp_modify", "dm",
	"[-p|-s|-i 0..9] [-y xxx.xxx.xxx.xxx]",
	"Modifies DSP configurations, such as next assigned IP address.",
	"\n"
	"Valid Options:\n"
	" -y ARG : Next IP address to assigned. example -y 192.168.1.60\n"
	" -p     : Act on primary DSP.\n"
	" -s     : Act on secondary DSP.\n"
	" -i ARG : Act on DSP ARG, where ARG is any value 0..9. Default is 0.\n"
	"\n"
};
