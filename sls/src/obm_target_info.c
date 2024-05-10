/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_target_info.c

$Octasic_Copyright: $

Description:

Implementation of the DSP reset command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <string.h>

#include "../inc/obm.h"
#include "../inc/octvc1/main/octvc1_main_api.h"
#include "../inc/octvc1/main/octvc1_main_default.h"
#include "../inc/octvc1/main/octvc1_main_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       InfoCommand

Description:    Displays a help screen for the program.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 InfoCommand( int argc, char* argv[] )
{
    tOCTVC1_MAIN_MSG_TARGET_INFO_CMD  DeviceInfoCmd;
    tOCTVC1_MAIN_MSG_TARGET_INFO_RSP  DeviceInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    char                              szDeviceType[20];
    char *                            szResult;
    tOCT_UINT32                       ulResult = cOCTVC1_RC_OK;
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

	/*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_CMD_DEF(&DeviceInfoCmd);
    mOCTVC1_MAIN_MSG_TARGET_INFO_CMD_SWAP(&DeviceInfoCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &DeviceInfoCmd;
    CmdExecuteParms.pRsp           = &DeviceInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(DeviceInfoRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_RSP_SWAP(&DeviceInfoRsp);

    switch(DeviceInfoRsp.ulTargetType)
    {
    case cOCTDEV_DEVICES_TYPE_ENUM_INVALID:
        sprintf(szDeviceType, "INVALID");
        break;
    case cOCTDEV_DEVICES_TYPE_ENUM_OCT1010:
        sprintf(szDeviceType, "OCT1010");
        break;
    case cOCTDEV_DEVICES_TYPE_ENUM_OCT2200:
        sprintf(szDeviceType, "OCT2200");
        break;
    case cOCTDEV_DEVICES_TYPE_ENUM_CPU:
        sprintf(szDeviceType, "CPU");
        break;
    }

    /*
     * Print the information.
     */
    printf("+-- DEVICE INFORMATION ------------------------------------------------------\n");
    printf("| DeviceType : %s\n", szDeviceType);
    printf("| DeviceInfo :\n");
    szResult = strtok( (char *)DeviceInfoRsp.abyTargetInfo, ";" );
    while(NULL != szResult)
    {
        printf("| %s\n",szResult);
        szResult = strtok( NULL, ";" );
    }
    printf("| \n");
    printf("| UserInfo :\n");
    szResult = strtok( (char *)DeviceInfoRsp.abyUserInfo, ";\n" );
	{
		char achBoardModelKey[] = "BoardModel=";
		char achNumDSPKey[] = "NumDSP=";

		while(NULL != szResult)
		{
			char * pchTokenBoard;
			char * pchTokenDsp;

			// Do not display BoardModel and NumDSP.
			pchTokenBoard = strstr( szResult, achBoardModelKey );
			pchTokenDsp = strstr( szResult, achNumDSPKey );
			if( pchTokenBoard == NULL && pchTokenDsp == NULL )
			{
				printf("| %s\n",szResult);
			}
			szResult = strtok( NULL, ";\n" );
		}
	}
    printf("|\n\n");

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_InfoCmd =
{
	InfoCommand,
	"info", "in",
	"",
	"Display daemon information.",
	""
};
