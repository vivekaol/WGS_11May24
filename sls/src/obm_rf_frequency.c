/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_rf_frequency.c

$Octasic_Copyright: $

Description:

Implementation of the RF frequency command

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

tOCT_UINT32 RfFrequencyFilterGet( char* f_pchFilterOption, unsigned * f_pulIndex, unsigned * f_pulBank, unsigned * f_pulFrequencyKhz, unsigned * f_pulBandwidthKhz )
{
	if( atof(f_pchFilterOption) > cOCTVC1_OBM_MAX_RF_COMPONENT_DESC )
	{
		/* Frequency-based selection */ 
		float fFrequencyMhz;
		float fBandwidthMhz = 0;

		if( sscanf( f_pchFilterOption, "%f,%f", &fFrequencyMhz, &fBandwidthMhz ) == 0 )
		{
			fprintf(stderr, "Invalid Frequency parameter\n");
			return cOCTVC1_GENERIC_RC_BAD_PARAM;
		}

		*f_pulFrequencyKhz = (tOCT_UINT32)(fFrequencyMhz * 1000);
		if( fBandwidthMhz != 0 )
		{
			*f_pulBandwidthKhz = (tOCT_UINT32)(fBandwidthMhz * 1000);
			// Round up
			*f_pulBandwidthKhz = ((*f_pulBandwidthKhz) + 1) & (~0x1);
		}
	}
	else
	{
		/* filter-based selection */
		if( sscanf( f_pchFilterOption, "%u,%u", f_pulIndex, f_pulBank ) == 0 )
		{
			fprintf(stderr, "Invalid Tx filter index\n");
			return cOCTVC1_GENERIC_RC_BAD_PARAM;
		}
	}

	return cOCTVC1_RC_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfFrequencyCommand

Description:    Configures the RF filders & attenuators that are in path.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RfFrequencyCommand( int argc, char* argv[] )
{
	tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD RfModifyCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP RfModifyRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    tOCT_UINT32                       ulResult = cOCTVC1_RC_OK;
	int									lOptRetval;
	char*                               pszAntennaConnector = "0,0";

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "c:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'c':
				pszAntennaConnector = optarg;
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
				break;
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
    mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_DEF(&RfModifyCmd);
	RfModifyCmd.ulBoardIndex = g_Context.ulBoardId;

	if( argc <= optind + 1 )
	{
		printf( "Missing argument\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        goto ErrorHandling;
	}
	else
	{
		if( strcmp( argv[optind], "tx" ) == 0 )
		{
			optind++;
			// Get Tx parameter.
			ulResult = RfFrequencyFilterGet( argv[optind++], &RfModifyCmd.ulTxRfComponentIndex, &RfModifyCmd.ulTxRfComponentBankIndex, &RfModifyCmd.ulTxFrequencyKhz, &RfModifyCmd.ulTxBandwidthKhz );
			if( ulResult != cOCTVC1_RC_OK )
			{
				goto ErrorHandling;
			}
		}
		else if( strcmp( argv[optind], "rx" ) == 0 )
		{
			optind++;
			// Get Rx parameter.
			ulResult = RfFrequencyFilterGet( argv[optind++], &RfModifyCmd.ulRxRfComponentIndex, &RfModifyCmd.ulRxRfComponentBankIndex, &RfModifyCmd.ulRxFrequencyKhz, &RfModifyCmd.ulRxBandwidthKhz );
			if( ulResult != cOCTVC1_RC_OK )
			{
				goto ErrorHandling;
			}
		}
		/* Band-based selection? */
		else if( strcmp( argv[optind], "bts" ) == 0 || strcmp( argv[optind], "ue" ) == 0 )
		{
			RfModifyCmd.ulPhyRole = strcmp( argv[optind++], "bts" ) == 0 ? 
										cOCTVC1_OBM_PHY_ROLE_ENUM_BASE_STATION : cOCTVC1_OBM_PHY_ROLE_ENUM_UE;

			if( strlen(argv[optind]) <= sizeof(RfModifyCmd.szBand) )
			{
				strcpy( RfModifyCmd.szBand, argv[optind++] );
			}
			else
			{
				fprintf(stderr, "Too many character for band.\n");
				ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
				goto ErrorHandling;
			}
		}
		else
		{
			// Both parameters (tx and rx) should be passed.

			// Get Tx parameter.
			ulResult = RfFrequencyFilterGet( argv[optind++], &RfModifyCmd.ulTxRfComponentIndex, &RfModifyCmd.ulTxRfComponentBankIndex, &RfModifyCmd.ulTxFrequencyKhz, &RfModifyCmd.ulTxBandwidthKhz );
			if( ulResult != cOCTVC1_RC_OK )
			{
				goto ErrorHandling;
			}

			// Get Rx parameter.
			ulResult = RfFrequencyFilterGet( argv[optind++], &RfModifyCmd.ulRxRfComponentIndex, &RfModifyCmd.ulRxRfComponentBankIndex, &RfModifyCmd.ulRxFrequencyKhz, &RfModifyCmd.ulRxBandwidthKhz );
			if( ulResult != cOCTVC1_RC_OK )
			{
				goto ErrorHandling;
			}
		}
	}

	if( pszAntennaConnector )
	{
		unsigned ulTransceiverId, ulAntennaId;
		if(sscanf( pszAntennaConnector, "%u,%u", &ulTransceiverId, &ulAntennaId ) == 2)
		{
			RfModifyCmd.AntennaConnectorId.usTransceiverIndex = ulTransceiverId; 
			RfModifyCmd.AntennaConnectorId.usAntennaIndex     = ulAntennaId;
		}
		else
		{
			fprintf(stderr, "Format error in the antenna connector ID list!\n");
			ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
			goto ErrorHandling;
		}
	}

	RfModifyCmd.ulAllowMissingFiltersFlag = cOCT_FALSE;

	mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_SWAP(&RfModifyCmd);

	/* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &RfModifyCmd;
    CmdExecuteParms.pRsp           = &RfModifyRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(RfModifyRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if( ulResult == cOCTVC1_OBM_RC_RF_FRONTEND_UNHANDLED_FREQUENCY )
    {
		// Re-execute the command and show the warning.
		mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_SWAP(&RfModifyCmd);
		RfModifyCmd.ulAllowMissingFiltersFlag = cOCT_TRUE;
		mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_SWAP(&RfModifyCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &RfModifyCmd;
		CmdExecuteParms.pRsp           = &RfModifyRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(RfModifyRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);

		if( ulResult == cOCTVC1_RC_OK )
		{
			fprintf(stderr, "Notice: No filter available, bypassing filter stage.\n\n");
		}
    }

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RfFrequencyCmd =
{
	RfFrequencyCommand,
	"rf_frequency", "rf",
	"[-c <Antenna connector Id>] <0.." STR(cOCTVC1_OBM_MAX_RF_COMPONENT_DESC) "[,bank]> <0.." STR(cOCTVC1_OBM_MAX_RF_COMPONENT_DESC) " [,bank]>\n"
	"              [-c <Antenna connector Id>] <tx_freq[,bandwidth]> <rx_freq[,bandwidth]>\n"
	"              [-c <Antenna connector Id>] <tx|rx> <0.." STR(cOCTVC1_OBM_MAX_RF_COMPONENT_DESC) "[,bank]>\n"
	"              [-c <Antenna connector Id>] <tx|rx> <freq[,bandwidth]>\n"
	"              [-c <Antenna connector Id>] <bts|ue> <band>",
	"Configure RF section filters, attenuators, amplifiers, etc.",
	"\n"
	"  Selects the components in the tx, rx paths. Add a comma followed by a bank index to specify the"
	"  bank to which the component change should apply (default is bank 0). The first parameter applies to the tx path,\n"
	"  the second applies to the Rx path.\n"
	"  \n"
	"  Use the Rf information command to find out what RF paths are available on this board (including externally attached\n"
	"  Rf FrontEnds), as well as what components are present in each.\n"
	"  \n"
	"  When values provided are greater than " STR(cOCTVC1_OBM_MAX_RF_COMPONENT_DESC) ", selection by frequency is assumed.\n"
	"  Values are in Mhz and decimals are allowed. Add a comma followed by a bandwidth value in MHz to specify the bandwidth\n"
	"  of the frequency. Obmd will then automatically select the appropriate filter (for all banks),\n"
	"  falling back to a direct path if no suitable filter is available, or returning an error if a direct path setting is not\n"
	"  available either.\n"
	"  \n"
	"  When the first argument provided is \"bts\" or \"ue\", selection by band is assumed. The filter appropriate for\n"
	"  the specified band is then selected, if available. As with frequency-based selection, 1) fallback to the direct path\n"
	"  is done or an error is returned, 2) all banks within a path are configured at once.\n"
	"\n"
	"Valid options:\n"
	"  -c <Antenna connector ID> : One of the antenna connectors to which this Rf FrontEnd is attached. Note that\n"
	"                              this option allows to target a complete Rf frontend, not just a specific path.\n"
	"                              This is a comma-separated pair of transceiver and antenna indexes.\n"
	"                              Example: 1,0. Default: 0,0\n"
};
