/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_i2c_read.c

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
#include <ctype.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"


/***************************  CONSTANTS  *****************************/
#define cBYTES_PER_LINE	(8)

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       ReadI2cCommand

Description:    Reads data from the i2c bus.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 ReadI2cCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD	ReadI2cCmd;
    tOCTVC1_OBM_MSG_BOARD_READ_I2C_RSP	ReadI2cRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_UINT32							ulNumBytes;
	tOCTVC1_SUB_OBJECT_ID				ulBusId = 0;
	unsigned							i,j;
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
    mOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD_DEF(&ReadI2cCmd);
	ReadI2cCmd.ulBoardIndex = g_Context.ulBoardId;

	if( argc <= optind )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else if( argc > (optind + 2) )
	{
		printf( "Too many arguments\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else
	{
		ReadI2cCmd.ulBusId = ulBusId;
		ReadI2cCmd.bySlave = (tOCT_UINT8)strtoul(argv[optind], NULL, 0);
		if(argc > (optind + 1))
		{
			ReadI2cCmd.ulNumBytes = strtoul(argv[optind+1], NULL, 0);
		}
		
		if(ReadI2cCmd.ulNumBytes > cOCTVC1_OBM_MAX_I2C_BYTES || ReadI2cCmd.ulNumBytes == 0)
		{
			printf( "Invalid number of bytes: \"%s\"\n", argv[optind+1] );
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}

		ulNumBytes = ReadI2cCmd.ulNumBytes;
	}

	mOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD_SWAP(&ReadI2cCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &ReadI2cCmd;
    CmdExecuteParms.pRsp           = &ReadI2cRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(ReadI2cRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_READ_I2C_RSP_SWAP(&ReadI2cRsp);

	for( i = 0; i < ulNumBytes; i += cBYTES_PER_LINE )
	{
		unsigned ulBytesToPrint = mMIN(ulNumBytes - i, cBYTES_PER_LINE);
		printf( "0x%02x : ", i );

		for( j=0; j < ulBytesToPrint; ++j )
			printf( "%02x ", ReadI2cRsp.abyData[i + j] );
		for( ; j < cBYTES_PER_LINE; ++j )
			printf( "   " );

		printf( " | " );

		for( j=0; j < ulBytesToPrint; ++j )
			printf( "%c", isprint(ReadI2cRsp.abyData[i + j]) ? ReadI2cRsp.abyData[i + j] : '.' );
		for( ; j < cBYTES_PER_LINE; ++j )
			printf( " " );
		printf( " |\n" );
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_ReadI2cCmd =
{
	ReadI2cCommand,
	"i2c_read", "ir",
	"[-i 0..9] <slave> [num_bytes]",
	"Perform an I2C read operation.",
	"\n"
	"   slave    : 7-bit address of the i2c device to read from. May be hex or decimal.\n"
	"   num_bytes: Number of bytes to read from the i2c bus (default is 1)\n"
	"\n"
	"Valid Options:\n"
	" -i ARG : Perform transaction on i2c bus ID ARG. Default is 0.\n"
};
