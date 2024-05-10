/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_rf_info.c

$Octasic_Copyright: $

Description:

Implementation of the RF information command

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

unsigned char g_abyTestRfInfoSize[1500 - sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP)];

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       IsRfComponentContainingFilter

Description:    Return true if the RF Component contains frequency filter.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_BOOL32 IsRfComponentContainingFilter( tOCTVC1_OBM_RF_COMPONENT_DESC * f_pRfComponent, tOCT_UINT32 f_ulNumElement )
{
	unsigned i;

	for( i=0; i<f_ulNumElement; i++ )
	{
		if( f_pRfComponent[i].ulCenterFrequencyKHz != 0 )
			return cOCT_TRUE;
	}

	return cOCT_FALSE;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfOutputRfComponent

Description:    Print RF component to screen.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void RfOutputRfComponent( tOCTVC1_OBM_RF_COMPONENT_DESC * f_pRfComponent, tOCT_UINT32 f_ulNumElement, tOCT_UINT32 f_ulRfComponentIndex )
{
	unsigned i;

	if( IsRfComponentContainingFilter( f_pRfComponent, f_ulNumElement) )
	{
		printf("|            Center Freq | Bandwidth\n" );
	}

	printf("|            ------------+----------\n" );

	for( i=0; i<f_ulNumElement; i++ )
	{
		if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_OFF )
		{
			printf("|    %s[% 2u]           <Off>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_DIRECT )
		{
			printf("|    %s[% 2u]          <Direct>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_DIRECT_NO_PA )
		{
			printf("|    %s[% 2u]       <Direct no Pa>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_HIGH )
		{
			printf("|    %s[% 2u]         <High Freq>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_MID )
		{
			printf("|    %s[% 2u]         <Mid Freq>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_LOW )
		{
			printf("|    %s[% 2u]         <Low Freq>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FILTER )
		{
			printf("|    %s[% 2u]     % 7.1f |% 6.1f\n",	f_ulRfComponentIndex == i ? "-->" : "   ",
					i, 
					(float)f_pRfComponent[i].ulCenterFrequencyKHz/1000,
					(float)f_pRfComponent[i].ulBandwidthKHz/1000);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_GAIN )
		{
			if( f_pRfComponent[i].lGainDbQ9 == 0 )
			{
				printf("|    %s[% 2u]          <Direct>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
						i);
			}
			else
			{
				printf("|    %s[% 2u]         % 5.1f dB\n",	f_ulRfComponentIndex == i ? "-->" : "   ",
						i, 
						((double)f_pRfComponent[i].lGainDbQ9 / (1<<9)) );
			}
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_LNA )
		{
			printf("|    %s[% 2u]           <On>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
		else if( f_pRfComponent[i].ulType == cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_LNA_BYPASS )
		{
			printf("|    %s[% 2u]         <Bypass>\n", f_ulRfComponentIndex == i ? "-->" : "   ",
					i);
		}
	}
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       RfInfoCommand

Description:    Retrieves info on the current RF settings

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 RfInfoCommand( int argc, char* argv[] )
{
	tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD RfInfoCmd;
    tOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP RfInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    tOCT_UINT32                       ulResult = cOCTVC1_RC_OK;
	unsigned i;
	tOCT_UINT32							ulRfComponentBankIndex = 0;
	int									lOptRetval;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId = { 0 };

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "c:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
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
						fprintf(stderr, "Format error in the antenna connector ID list!\n");
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
    mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
	RfInfoCmd.ulBoardIndex = g_Context.ulBoardId;
	RfInfoCmd.AntennaConnectorId = AntennaConnectorId;

	mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &RfInfoCmd;
    CmdExecuteParms.pRsp           = &RfInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(RfInfoRsp);
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

	mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);

    /*
     * Print out the retrieved information.
     */
	printf("+-- BOARD %u, RF front-end INFORMATION ------------------------------------------------------\n", g_Context.ulBoardId );
	printf("|\n" );
	printf("| Manufacturer         : %s \n", RfInfoRsp.szManufacturer );

	if( strlen(RfInfoRsp.szSupplementalInfo) != 0 )
	{
		char achSerialKey[] = "Serial=";
		char achBomModelKey[] = "BOM=";
		char achPicBuildKey[] = "PicBuild=";
		char achKitSerialKey[] = "kit_serial=";
		char achKitModelKey[] = "kit_model=";
		char achSysSerialKey[] = "system_serial=";
		char achSysModelKey[] = "system_model=";
		char * pchString = RfInfoRsp.szSupplementalInfo;
		char * pchStart;
		char * pchEnd;

		pchStart = strstr( pchString, achSerialKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Serial Number        : %s\n", pchStart + strlen(achSerialKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achBomModelKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Model                : %s - %s \n", RfInfoRsp.szModel, pchStart + strlen(achBomModelKey) );
			pchString = pchEnd + 1;
		}
		else
		{
			printf("| Model                : %s \n", RfInfoRsp.szModel );
		}
		pchStart = strstr( pchString, achPicBuildKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| EMIC build number    : %s\n", pchStart + strlen(achPicBuildKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achKitSerialKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Kit Serial           : %s\n", pchStart + strlen(achKitSerialKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achSysSerialKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| System Serial        : %s\n", pchStart + strlen(achSysSerialKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achKitModelKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| Kit Model            : %s\n", pchStart + strlen(achKitModelKey) );
			pchString = pchEnd + 1;
		}
		pchStart = strstr( pchString, achSysModelKey );
		if( pchStart != NULL )
		{
			pchEnd = strchr( pchStart, ';');
			pchEnd[0] = 0;
			printf("| System Model         : %s\n", pchStart + strlen(achSysModelKey) );
			pchString = pchEnd + 1;
		}
	}
	else
	{
		printf("| Model                : %s \n", RfInfoRsp.szModel );
	}

	printf("|\n" );

	printf("| Radio profile        : %s\n", mOCTVC1_OBM_RADIO_PROFILE_TO_STRING(RfInfoRsp.ulRadioProfile) );
	printf("|\n" );
	if( RfInfoRsp.ulNumStagesOffered != 0 )
	{
		printf("| Amplification stages : %u out of %u enabled (%u requested by user)\n", 
					RfInfoRsp.ulNumStagesActive, RfInfoRsp.ulNumStagesOffered, RfInfoRsp.ulNumStagesRequested );
	}
	printf("| Duplex Mode          : %s \n", mOCTVC1_OBM_RF_DUPLEX_MODE_TO_STRING(RfInfoRsp.ulDuplexMode) );
	printf("| Management Mode      : %s \n", mOCTVC1_OBM_RF_MANAGEMENT_MODE_TO_STRING(RfInfoRsp.ulManagementMode) );
	printf("|\n" );
	if( RfInfoRsp.ulNumTxRfComponent == 0 && RfInfoRsp.ulNumRxRfComponent == 0 )
	{
		printf("| Antenna connector    : %u,%u\n", RfInfoRsp.AntennaConnectorId.usTransceiverIndex, RfInfoRsp.AntennaConnectorId.usAntennaIndex);
		printf("|\n" );
	}
	if(RfInfoRsp.ulNumTxRfComponent == 0)
	{
		printf("|   Tx : None\n" );
	}
	else
	{
		printf("|---------------------------------------------\n" );
		printf("|   Tx (antenna connector %u,%u):\n", RfInfoRsp.AntennaConnectorId.usTransceiverIndex, RfInfoRsp.AntennaConnectorId.usAntennaIndex);
		printf("|\n" );
		if( RfInfoRsp.lTargetTxPowerDbmQ9 != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			printf("|   Tx target power = %6.2f dBm\n", (float)RfInfoRsp.lTargetTxPowerDbmQ9 / (1<<9) );
		}
		if( RfInfoRsp.lTxGainDbQ9 != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			printf("|   Tx attenuation  = %6.2f dB\n", (float)RfInfoRsp.lTxGainDbQ9 / (1<<9) );
		}
		for( ulRfComponentBankIndex = 0; ulRfComponentBankIndex <  RfInfoRsp.ulNumTxRfComponentBanks; ulRfComponentBankIndex++ )
		{
			/* Fetch the characterstics of the RF Component bank (we actually end up doing this twice for bank 1) */
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
			RfInfoCmd.ulBoardIndex = g_Context.ulBoardId;
			RfInfoCmd.AntennaConnectorId = AntennaConnectorId;
			RfInfoCmd.ulTxRfComponentBankIndex = ulRfComponentBankIndex;
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);
			ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
			if (cOCTVC1_RC_OK != ulResult)
			{
				goto ErrorHandling;
			}
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);
	
			printf("|\n" );
			printf("|   Bank %u - %s\n", RfInfoRsp.ulTxRfComponentBankIndex, RfInfoRsp.szTxBankInfo );

			RfOutputRfComponent( RfInfoRsp.TxRfComponent, RfInfoRsp.ulNumTxRfComponent, RfInfoRsp.ulTxRfComponentIndex );

		} while ( RfInfoRsp.ulTxRfComponentBankIndex < RfInfoRsp.ulNumTxRfComponentBanks-1 );
	}
	printf("|\n" );
	if(RfInfoRsp.ulNumRxRfComponent == 0)
	{
		printf("|   Rx : None\n" );
	}
	else
	{
		printf("|---------------------------------------------\n" );
		printf("|   Rx (antenna connector %u,%u):\n", RfInfoRsp.AntennaConnectorId.usTransceiverIndex, RfInfoRsp.AntennaConnectorId.usAntennaIndex);
		if( RfInfoRsp.lRxGainDbQ9 != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
		{
			printf("|\n" );
			printf("|   Rx gain = %6.2f dB\n", (float)RfInfoRsp.lRxGainDbQ9 / (1<<9) );
		}
		for( ulRfComponentBankIndex = 0; ulRfComponentBankIndex <  RfInfoRsp.ulNumRxRfComponentBanks; ulRfComponentBankIndex++ )
		{
			/* Fetch the characterstics of the filter bank (we actually end up doing this twice for bank 1) */
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
			RfInfoCmd.ulBoardIndex = g_Context.ulBoardId;
			RfInfoCmd.AntennaConnectorId = AntennaConnectorId;
			RfInfoCmd.ulRxRfComponentBankIndex = ulRfComponentBankIndex;
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);
			ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
			if (cOCTVC1_RC_OK != ulResult)
			{
				goto ErrorHandling;
			}
			mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);

			printf("|\n" );
			printf("|   Bank %u - %s\n", RfInfoRsp.ulRxRfComponentBankIndex, RfInfoRsp.szRxBankInfo );

			RfOutputRfComponent( RfInfoRsp.RxRfComponent, RfInfoRsp.ulNumRxRfComponent, RfInfoRsp.ulRxRfComponentIndex );
		}
	}
	printf("|\n" );

	// Output Diverity path.
	for( i=0; i<RfInfoRsp.ulNumDiversityPath; i++ )
	{
		if(	AntennaConnectorId.usTransceiverIndex == RfInfoRsp.aDiversityPathAntennaConnectorId[i].usTransceiverIndex &&
			AntennaConnectorId.usAntennaIndex == RfInfoRsp.aDiversityPathAntennaConnectorId[i].usAntennaIndex	)
		{
			continue;
		}

		mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
		RfInfoCmd.ulBoardIndex			= g_Context.ulBoardId;
		RfInfoCmd.AntennaConnectorId	= RfInfoRsp.aDiversityPathAntennaConnectorId[i];
		mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}
		mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);

		if( RfInfoRsp.ulNumTxRfComponentBanks != 0 )
		{
			printf("|---------------------------------------------\n" );
			printf("|   Tx diversity path (antenna connector %u,%u):\n", 
					RfInfoRsp.AntennaConnectorId.usTransceiverIndex,
					RfInfoRsp.AntennaConnectorId.usAntennaIndex);
			if( RfInfoRsp.lTxGainDbQ9 != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
			{
				printf("|\n" );
				printf("|   Tx attenuation = %6.2f dB\n", (float)RfInfoRsp.lTxGainDbQ9 / (1<<9) );
			}

			for( ulRfComponentBankIndex = 0; ulRfComponentBankIndex <  RfInfoRsp.ulNumTxRfComponentBanks; ulRfComponentBankIndex++ )
			{
				/* Fetch the characterstics of the RF Component bank (we actually end up doing this twice for bank 1) */
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
				RfInfoCmd.ulBoardIndex				= g_Context.ulBoardId;
				RfInfoCmd.AntennaConnectorId		= RfInfoRsp.AntennaConnectorId;
				RfInfoCmd.ulTxRfComponentBankIndex	= ulRfComponentBankIndex;
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);
				ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
				if (cOCTVC1_RC_OK != ulResult)
				{
					goto ErrorHandling;
				}
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);
		
				printf("|\n" );
				printf("|   Bank %u - %s\n", RfInfoRsp.ulTxRfComponentBankIndex, RfInfoRsp.szTxBankInfo );

				RfOutputRfComponent( RfInfoRsp.TxRfComponent, RfInfoRsp.ulNumTxRfComponent, RfInfoRsp.ulTxRfComponentIndex );

			} while ( RfInfoRsp.ulTxRfComponentBankIndex < RfInfoRsp.ulNumTxRfComponentBanks-1 );
		}

		if( RfInfoRsp.ulNumRxRfComponentBanks != 0 )
		{
			printf("|---------------------------------------------\n" );
			printf("|   Rx diversity path (antenna connector %u,%u):\n", 
					RfInfoRsp.AntennaConnectorId.usTransceiverIndex,
					RfInfoRsp.AntennaConnectorId.usAntennaIndex);
			if( RfInfoRsp.lRxGainDbQ9 != cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE )
			{
				printf("|\n" );
				printf("|   Rx gain = %6.2f dB\n", (float)RfInfoRsp.lRxGainDbQ9 / (1<<9) );
			}

			for( ulRfComponentBankIndex = 0; ulRfComponentBankIndex <  RfInfoRsp.ulNumRxRfComponentBanks; ulRfComponentBankIndex++ )
			{
				/* Fetch the characterstics of the RF Component bank (we actually end up doing this twice for bank 1) */
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(&RfInfoCmd);
				RfInfoCmd.ulBoardIndex				= g_Context.ulBoardId;
				RfInfoCmd.AntennaConnectorId		= RfInfoRsp.AntennaConnectorId;
				RfInfoCmd.ulRxRfComponentBankIndex	= ulRfComponentBankIndex;
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_SWAP(&RfInfoCmd);
				ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
				if (cOCTVC1_RC_OK != ulResult)
				{
					goto ErrorHandling;
				}
				mOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP_SWAP(&RfInfoRsp);
		
				printf("|\n" );
				printf("|   Bank %u - %s\n", RfInfoRsp.ulRxRfComponentBankIndex, RfInfoRsp.szRxBankInfo );

				RfOutputRfComponent( RfInfoRsp.RxRfComponent, RfInfoRsp.ulNumRxRfComponent, RfInfoRsp.ulRxRfComponentIndex );

			} while ( RfInfoRsp.ulRxRfComponentBankIndex < RfInfoRsp.ulNumRxRfComponentBanks-1 );
		}
	}

	printf("|\n\n");

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_RfInfoCmd =
{
	RfInfoCommand,
	"rf_info", "ri",
	"[-c <Antenna connector Id>]",
	"Display RF section properties.",
	"\n"
	"Valid options:\n"
	" -c <Antenna connector Id> : One of the antenna connectors to which this Rf FrontEnd is attached.\n"
	"                             This is a comma-separated pair of transceiver and antenna indexes.\n"
	"                             Example: 1,0. Default: 0,0\n"
};
