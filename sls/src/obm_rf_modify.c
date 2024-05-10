/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_rf_modify.c

$Octasic_Copyright: $

Description:



$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfModifyCommand

Description:    Modifies system properties.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RfModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD		RfModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP		RfModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
	tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM			ulDuplexMode = cOCTVC1_DO_NOT_MODIFY;
	tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM		ulManagementMode = cOCTVC1_DO_NOT_MODIFY;
	tOCT_INT32								lTxGainDbQ9 = cOCTVC1_DO_NOT_MODIFY;
	tOCT_INT32								lRxGainDbQ9 = cOCTVC1_DO_NOT_MODIFY;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID		AntennaConnectorId = { 0 };
	int										lOptRetval;
	unsigned								ulSpecialOption = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "d:o:a:g:c:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'd':

				ulSpecialOption++;

				if( strcmp( optarg, "fdd" ) == 0 )
					ulDuplexMode = cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_FDD;
				else if( strcmp( optarg, "tdd" ) == 0 )
					ulDuplexMode = cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_TDD;
				else
				{
					printf("Unknown duplex mode option: \"%s\"\n", optarg );
					return -1;
				}
				break;

			case 'o':

				ulSpecialOption++;

				if( strcmp( optarg, "auto" ) == 0 )
					ulManagementMode = cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_AUTOMATIC;
				else if( strcmp( optarg, "man" ) == 0 )
					ulManagementMode = cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_MANUAL;
				else
				{
					printf("Unknown management mode option: \"%s\"\n", optarg );
					return -1;
				}
				break;

			case 'a':

				ulSpecialOption++;

				lTxGainDbQ9 = (tOCT_INT32)(atof( optarg ) * 512);
				break;

			case 'g':

				ulSpecialOption++;

				lRxGainDbQ9 = (tOCT_INT32)(atof( optarg ) * 512);
				break;

			case 'c':
				{
					unsigned ulTransceiverId, ulAntennaId;
					if(sscanf( optarg, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
					{
						AntennaConnectorId.usTransceiverIndex = ulTransceiverId; 
						AntennaConnectorId.usAntennaIndex     = ulAntennaId;
					}
					else
					{
						fprintf(stderr, "Format error in the antenna connector ID!\n");
						ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
						goto ErrorHandling;
					}
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
		mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_DEF(&RfModifyCmd);

		RfModifyCmd.ulBoardIndex		= g_Context.ulBoardId;
		RfModifyCmd.AntennaConnectorId	= AntennaConnectorId;
		RfModifyCmd.ulDuplexMode		= ulDuplexMode;       
		RfModifyCmd.ulManagementMode	= ulManagementMode;
		RfModifyCmd.lTxGainDbQ9			= lTxGainDbQ9;  
		RfModifyCmd.lRxGainDbQ9			= lRxGainDbQ9;         

		mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_SWAP(&RfModifyCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &RfModifyCmd;
		CmdExecuteParms.pRsp           = &RfModifyRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(RfModifyRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP_SWAP(&RfModifyRsp);
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RfModifyCmd =
{
	RfModifyCommand,
	"rf_modify", "rm",
	"[-c <Antenna connector Id>] [-d fdd|tdd] [-a attenuation] [-g gain] [-o management_mode]",
	"Modifies rf settings.",
	"\n"
	"Valid Options:\n"
	"  -c <Antenna connector ID> : One of the antenna connectors to which this Rf FrontEnd is attached. \n"
	"                              This is a comma-separated pair of transceiver and antenna indexes.\n"
	" -d ARG : Duplex Mode argument. ARG is one of :\n"
	"    'fdd' : Full duplex mode.\n"
	"    'tdd' : Half duplex mode.\n"
	" -o ARG : Management Mode argument defining how the algorithms to adjust rf components, such as\n"
 	"          the LNA, the attenuator..., are handled.. ARG is one of :\n"
	"    'auto' : Automatic mode.\n"
	"    'man'  : Manual mode.\n"
	" -a ARG : Tx attenuation that should be applied, in DBs (1/4 of DBs are allowed)\n"
	" -g ARG : Rx gain that should be applied, in DBs (fraction of DBs are NOT allowed)\n"
	"\n"
};
