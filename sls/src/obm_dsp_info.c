/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_dsp_info.c

$Octasic_Copyright: $

Description:

Implementation of the DSP info command

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


/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       DspInfoCommand

Description:    Retrieves information for a given dsp.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 DspInfoCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD	DspInfoCmd;
    tOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP	DspInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_UINT32							ulDspId = 0;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "psi:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
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
    mOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD_DEF(&DspInfoCmd);
	DspInfoCmd.ulBoardIndex = g_Context.ulBoardId;
	DspInfoCmd.ulDspId = ulDspId;

	mOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD_SWAP(&DspInfoCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &DspInfoCmd;
    CmdExecuteParms.pRsp           = &DspInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(DspInfoRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP_SWAP(&DspInfoRsp);

    /*
     * Print out the retrieved information.
     */
	printf("+-- BOARD %u, DSP %u INFORMATION ------------------------------------------------------\n", g_Context.ulBoardId, DspInfoRsp.ulDspId );
	printf("| Reset signal state           : %s\n", mOCTVC1_OBM_SIGNAL_STATE_TO_STRING(DspInfoRsp.ulResetState) );
	printf("| Mac Address                  : %02x:%02x:%02x:%02x:%02x:%02x\n",	DspInfoRsp.MacAddress.abyMacAddress[0],
																DspInfoRsp.MacAddress.abyMacAddress[1],
																DspInfoRsp.MacAddress.abyMacAddress[2],
																DspInfoRsp.MacAddress.abyMacAddress[3],
																DspInfoRsp.MacAddress.abyMacAddress[4],
																DspInfoRsp.MacAddress.abyMacAddress[5]);
	printf("| BootProgress                 : %s\n",	mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING(DspInfoRsp.ulBootProgress) );
	printf("| Running application          : %s\n",	DspInfoRsp.szRunningApplication );
	printf("| Last assigned IP             : %d.%d.%d.%d\n",	(DspInfoRsp.LastAssignedIpAddress.aulIpAddress[0] >> 24) & 0xff,
													(DspInfoRsp.LastAssignedIpAddress.aulIpAddress[0] >> 16) & 0xff,
													(DspInfoRsp.LastAssignedIpAddress.aulIpAddress[0] >>  8) & 0xff,
													(DspInfoRsp.LastAssignedIpAddress.aulIpAddress[0] >>  0) & 0xff );
	if( DspInfoRsp.ulOscillatorOwnershipFlag == cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		printf("| Oscillator ownership         : NOT AVAILABLE\n" );
	else
		printf("| Oscillator ownership         : %s\n",	(DspInfoRsp.ulOscillatorOwnershipFlag == cOCT_TRUE) ? "TRUE" : "FALSE");
	if( DspInfoRsp.ulMccInfractionCnt != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
	{
		printf("| MCC infraction count         : %d\n",	DspInfoRsp.ulMccInfractionCnt );
	}
	printf("| File to provide at next boot : %s\n",	DspInfoRsp.szBootFileName );
	printf("| File provided at last boot   : %s\n",	DspInfoRsp.szLastFileName );
    printf("|\n\n");

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_DspInfoCmd =
{	DspInfoCommand,
	"dsp_info",
	"di",
	"[-p|-s|-i 0..9]",
	"Display detailed DSP information.",
	"\n"
	"Valid Options:\n"
	" -p     : Act on primary DSP.\n"
	" -s     : Act on secondary DSP.\n"
	" -i ARG : Act on DSP ARG, where ARG is any value 0..9. Default is 0.\n"
	"\n"
};
