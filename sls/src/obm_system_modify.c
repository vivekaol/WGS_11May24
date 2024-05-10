/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_system_modify.c

$Octasic_Copyright: $

Description:



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

Function:       SystemModifyCommand

Description:    Modifies system properties.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 SystemModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD		SysModifyCmd;
    tOCTVC1_OBM_MSG_SYSTEM_MODIFY_RSP		SysModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
	tOCT_BOOL32								DhcpEnableFlag = cOCTVC1_DO_NOT_MODIFY;
	tOCT_BOOL32								TftpEnableFlag = cOCTVC1_DO_NOT_MODIFY;
	int										lOptRetval;
	unsigned								ulSpecialOption = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "d:t:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'd':

				ulSpecialOption++;

				if( strcmp( optarg, "on" ) == 0 )
					DhcpEnableFlag = cOCT_TRUE;
				else if( strcmp( optarg, "off" ) == 0 )
					DhcpEnableFlag = cOCT_FALSE;
				else
				{
					printf("Unknown DHCP option: \"%s\"\n", optarg );
					return -1;
				}
				break;

			case 't':

				ulSpecialOption++;

				if( strcmp( optarg, "on" ) == 0 )
					TftpEnableFlag = cOCT_TRUE;
				else if( strcmp( optarg, "off" ) == 0 )
					TftpEnableFlag = cOCT_FALSE;
				else
				{
					printf("Unknown TFTP option: \"%s\"\n", optarg );
					return -1;
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

	// Send command Battery Stats.
	{
		/*
		 * Prepare command data for the Battery Stats.
		 */
		mOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD_DEF(&SysModifyCmd);

		SysModifyCmd.ulDhcpServerEnableFlag = DhcpEnableFlag;
		SysModifyCmd.ulTftpServerEnableFlag = TftpEnableFlag;

		mOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD_SWAP(&SysModifyCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &SysModifyCmd;
		CmdExecuteParms.pRsp           = &SysModifyRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(SysModifyRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_SYSTEM_MODIFY_RSP_SWAP(&SysModifyRsp);
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_SystemModifyCmd =
{
	SystemModifyCommand,
	"system_modify", "sm",
	"[-d on|off] [-t on|off]",
	"Modifies system services, such as DHCP and TFTP.",
	"\n"
	"Valid Options:\n"
	" -d ARG : DHCP switch argument. ARG is one of :\n"
	"    'on'  : Enables the built-in DHCP server.\n"
	"    'off' : Disables the built-in DHCP server.\n"
	" -t ARG : TFTP switch argument. ARG is one of :\n"
	"    'on'  : Enables the built-in TFTP server.\n"
	"    'off' : Disables the built-in TFTP server.\n"
	"\n"
};
