/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_i2c_write.c

$Octasic_Copyright: $

Description:

Implementation of the reference clock input selection command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       WriteI2cCommand

Description:    Writes data from the i2c bus.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 WriteI2cCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD    WriteI2cCmd;
    tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_RSP    WriteI2cRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
	tOCTVC1_SUB_OBJECT_ID				ulBusId = 0;
	int									lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "i:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'i':
				ulBusId = strtoul(optarg, NULL, 0);
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
    mOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD_DEF(&WriteI2cCmd);
	WriteI2cCmd.ulBoardIndex = g_Context.ulBoardId;

	if( argc <= optind+1 )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else
	{
		int i;

		WriteI2cCmd.ulBusId = ulBusId;
		WriteI2cCmd.bySlave = (tOCT_UINT8)strtoul(argv[optind], NULL, 0);

		for(i = 0; i < (argc-optind-1); ++i)
		{
			if( i >= cOCTVC1_OBM_MAX_I2C_BYTES )
			{
				printf( "Too many bytes to write!\n" );
				ulResult = cOCTVC1_GENERIC_RC_FULL;
				goto ErrorHandling;
			}

			WriteI2cCmd.abyData[i] = (tOCT_UINT8)strtoul(argv[optind + i + 1], NULL, 0);
			WriteI2cCmd.ulNumBytes++;
		}
	}

	mOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD_SWAP(&WriteI2cCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &WriteI2cCmd;
    CmdExecuteParms.pRsp           = &WriteI2cRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(WriteI2cRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_WRITE_I2C_RSP_SWAP(&WriteI2cRsp);

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_WriteI2cCmd =
{
	WriteI2cCommand,
	"i2c_write", "iw",
	"[-i 0..9] <slave> <data [...]>",
	"Perform an I2c write operation.",
	"\n"
	"   slave: 7-bit address of the i2c device to write from. May be hex or decimal.\n"
	"   data:  Data to write to the i2c bus (max " STR(cOCTVC1_OBM_MAX_I2C_BYTES) " bytes). May be hex.\n"
	"\n"
	"Valid Options:\n"
	" -i ARG : Perform transaction on i2c bus ID ARG. Default is 0.\n"
};
