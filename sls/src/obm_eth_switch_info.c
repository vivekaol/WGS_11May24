/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_eth_switch_info.c

$Octasic_Copyright: $

Description:

Implementation of Ethernet Switch Info command

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

Function:       OutputLinkMode

Description:    Displays link mode information.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OutputLinkMode( char f_szPhyName[], tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_MODE * f_pLinkMode )
{
	char  szLinkMode[256] = "";

	printf("| %s link modes: \n", f_szPhyName );

	if( f_pLinkMode->ulHalfDuplex10BaseTFlag )
	{
		strcat( szLinkMode, "                       10baseT/Half     " );
	}
	if( f_pLinkMode->ulFullDuplex10BaseTFlag )
	{
		if( !f_pLinkMode->ulHalfDuplex10BaseTFlag )
		{
			strcat( szLinkMode, "                       " );
		}
		strcat( szLinkMode, "10baseT/Full" );
	}
	if( strcmp( "", szLinkMode ) != 0 )
	{
		printf("| %s\n", szLinkMode );
	}


	strcpy( szLinkMode, "" );
	if( f_pLinkMode->ulHalfDuplex100BaseXFlag )
	{
		strcat( szLinkMode, "                       100baseX/Half    " );
	}
	if( f_pLinkMode->ulFullDuplex100BaseXFlag )
	{
		if( !f_pLinkMode->ulHalfDuplex100BaseXFlag )
		{
			strcat( szLinkMode, "                       " );
		}
		strcat( szLinkMode, "100baseX/Full" );
	}
	if( strcmp( "", szLinkMode ) != 0 )
	{
		printf("| %s\n", szLinkMode );
	}


	strcpy( szLinkMode, "" );
	if( f_pLinkMode->ulHalfDuplex100BaseTXFlag )
	{
		strcat( szLinkMode, "                       100baseTX/Half   " );
	}
	if( f_pLinkMode->ulHalfDuplex100BaseTXFlag )
	{
		if( !f_pLinkMode->ulHalfDuplex100BaseTXFlag )
		{
			strcat( szLinkMode, "                       " );
		}
		strcat( szLinkMode, "100baseTX/Full" );
	}
	if( strcmp( "", szLinkMode ) != 0 )
	{
		printf("| %s\n", szLinkMode );
	}

	strcpy( szLinkMode, "" );
	if( f_pLinkMode->ulHalfDuplex1000BaseTFlag )
	{
		strcat( szLinkMode, "                       1000baseT/Half   " );
	}
	if( f_pLinkMode->ulFullDuplex1000BaseTFlag )
	{
		if( !f_pLinkMode->ulHalfDuplex1000BaseTFlag )
		{
			strcat( szLinkMode, "                       " );
		}
		strcat( szLinkMode, "1000baseT/Full" );
	}
	if( strcmp( "", szLinkMode ) != 0 )
	{
		printf("| %s\n", szLinkMode );
	}

	if( f_pLinkMode->ulPauseCapableFlag )
	{
		printf("| %s pause frame use:  Yes\n", f_szPhyName );
	}
	else
	{
		printf("| %s pause frame use:  No\n", f_szPhyName );
	}

	if( f_pLinkMode->ulAutoNegotiationAbilityFlag )
	{
		printf("| %s auto-negotiation: Yes\n", f_szPhyName );
	}
	else
	{
		printf("| %s auto-negotiation: No\n", f_szPhyName );
	}
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       EthSwitchInfoCommand

Description:    Displays information on system.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 EthSwitchInfoCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD		EthSwitchCmd;
    tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_RSP		EthSwitchRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
	tOCT_UINT32							ulLinkStatusPortId = 0;
    tOCT_UINT32                         ulResult = cOCTVC1_RC_OK;
	int									lOptRetval, i;
	char								PortNameLookupTbl[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT][128] = {
		{ "(wan)  " },
		{ "(cpu)  " },
		{ "       " },
		{ "       " },
		{ "       " },
		{ "(dsp 0)" },
		{ "(dsp 1)" }
	};

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "s:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 's':

				ulLinkStatusPortId = strtoul(optarg, NULL, 0);
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

	// Send command Battery Stats.
	{
		/*
		 * Prepare command data for the Battery Stats.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD_DEF(&EthSwitchCmd);

		EthSwitchCmd.ulLinkStatusPortId = ulLinkStatusPortId;

		mOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD_SWAP(&EthSwitchCmd);

		/* 
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &EthSwitchCmd;
		CmdExecuteParms.pRsp           = &EthSwitchRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(EthSwitchRsp);
		ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_RSP_SWAP(&EthSwitchRsp);
	}


    /*
     * Print the information.
     */
	printf("+-- BOARD %u ETHERNET SWITCH INFO ------------------------------------------------------\n", EthSwitchRsp.ulBoardIndex );
	printf("|\n" );
	if( EthSwitchRsp.ulPortMirrorSrcList == 0 || EthSwitchRsp.ulPortMirrorDst == cOCTVC1_OBM_ETHERNET_SWITCH_PORT_MIRROR_DST_NONE )
	{
		printf("| Mirroring : Not enabled.\n" );
	}
	else
	{
		tOCT_BOOL32	ulNeedCommaFlag = cOCT_FALSE;
		printf("| Mirroring\n" );
		printf("|   Source : " );
		for( i=0; i<cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT; i++ )
		{
			if( ((EthSwitchRsp.ulPortMirrorSrcList >> i) & 0x1) == 1 )
			{
				if( ulNeedCommaFlag )
					printf("," );

				printf("%d", i );
				ulNeedCommaFlag = cOCT_TRUE;
			}
		}
		printf(" => Destination : %d %s\n", EthSwitchRsp.ulPortMirrorDst, PortNameLookupTbl[EthSwitchRsp.ulPortMirrorDst] );
	}
	printf("|\n");
	printf("| Vlan mapping\n" );
	printf("|\n");
	printf("|   Port      | Destination\n" );
	printf("|  -----------+-------------\n" );
	for( i=0; i<cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT; i++ )
	{
		tOCT_BOOL32	ulNeedCommaFlag = cOCT_FALSE;
		int j;

		printf("|   %d %s | ", i, PortNameLookupTbl[i] );
		for( j=0; j<cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT; j++ )
		{
			if( ((EthSwitchRsp.aPortVlanMapping[i] >> j) & 0x1) == 1 )
			{
				if( ulNeedCommaFlag )
					printf("," );

				printf("%d", j );
				ulNeedCommaFlag = cOCT_TRUE;
			}
		}
		printf("\n");
		printf("|  -----------+-------------\n" );
	}

	// Output Link Status
	{
		printf("|\n");
		printf("|\n");
		printf("| Link status for port %d:\n", EthSwitchRsp.ulLinkStatusPortId );
		printf("|\n");
		printf("|\n");

		OutputLinkMode( "Supported", &EthSwitchRsp.LinkStatus.SupportedLinkMode );
		printf("|\n");
		OutputLinkMode( "Advertised", &EthSwitchRsp.LinkStatus.AdvertisedLinkMode );
		printf("|\n");

		if( EthSwitchRsp.LinkStatus.ulLinkSpeed != cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_UNKNOWN )
		{
			printf("| Link Speed:       %s\n", mOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_TO_STRING(EthSwitchRsp.LinkStatus.ulLinkSpeed) );
		}
		if( EthSwitchRsp.LinkStatus.ulLinkDuplex != cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_UNKNOWN )
		{
			printf("| Duplex:           %s\n", mOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_TO_STRING(EthSwitchRsp.LinkStatus.ulLinkDuplex) );
		}

		if( EthSwitchRsp.LinkStatus.ulAutoNegotiationCompleteFlag )
		{
			printf("| Auto-negotiation: on\n" );
		}
		else
		{
			printf("| Auto-negotiation: not complete\n" );
		}

		if( EthSwitchRsp.LinkStatus.ulLinkDetectedFlag )
		{
			printf("| Link detected:    yes\n" );
		}
		else
		{
			printf("| Link detected:    no\n" );
		}
		printf("|\n\n");
	}

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_EthSwitchInfoCmd =
{
	EthSwitchInfoCommand,
	"eth_switch_info", "esi",
	"[-s 0..1]",
	"Display detailed ethernet switch information.",
	"\n"
	"Valid Options:\n"
	" -s ARG : Link status port identifier to read link status information. ARG is any value 0..1. Default is 0.\n"
	"\n"
};
