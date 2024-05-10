/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_system_modify.c

$Octasic_Copyright: $

Description:



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
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       EthSwitchModifyCommand

Description:    Modifies system properties.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 EthSwitchModifyCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD		EthSwitchCmd;
    tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_RSP		EthSwitchRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
	tOCT_UINT32								ulPortId						= cOCTVC1_DO_NOT_MODIFY;
	tOCT_UINT32								ulPortVlanMask					= cOCTVC1_DO_NOT_MODIFY;
	tOCT_UINT32								ulPortMirrorSrcList				= cOCTVC1_DO_NOT_MODIFY;
	tOCT_UINT32								ulPortMirrorDst					= cOCTVC1_DO_NOT_MODIFY;
	tOCT_UINT32								ulRestartAutoNegotiationPortId	= cOCTVC1_DO_NOT_MODIFY;
	tOCT_UINT32								aPortVlanMapping[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT] = {	cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY,
																											cOCTVC1_DO_NOT_MODIFY	};
	int										lOptRetval;
	unsigned								ulSpecialOption = 0;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "p:w:v:n:")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'p':

				ulPortId = strtoul(optarg, NULL, 0);
				break;

			case 'n':

				ulSpecialOption++;

				ulRestartAutoNegotiationPortId = strtoul(optarg, NULL, 0);
				break;

			case 'w':

				ulSpecialOption++;

				if( strcmp( optarg, "no_mirror" ) == 0 )
				{
					ulPortMirrorSrcList = 0;
					ulPortMirrorDst		= cOCTVC1_OBM_ETHERNET_SWITCH_PORT_MIRROR_DST_NONE;
				}
				else if( strcmp( optarg, "mirror_dsp_cpu" ) == 0 )
				{
					ulPortMirrorSrcList = (1<<6)|(1<<5)|(1<<1);
					ulPortMirrorDst		= 0;
				}
				else
				{
					char * pch = optarg;
					char * pchEnd;

					ulPortMirrorSrcList = 0;

					while( 1 )
					{
						unsigned ulPort;

						ulPort = strtoul(pch, &pchEnd, 0);
						if( pch == pchEnd )
						{
							printf( "Invalid argument : %s\n", pch );
							ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
							return ulResult;
						}
						ulPortMirrorSrcList |= (1<<ulPort);
						pch = strchr( pch, ',' );
						if( pch == NULL )
							break;
						pch++;
					}
				}
				break;

			case 'v':

				ulSpecialOption++;

				if( strcmp( optarg, "default" ) == 0 )
				{
					tOCT_UINT32 DefaultMapping[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT] = { 0x7E, 0x7D, 0x7B, 0x77, 0x6F, 0x5F, 0x3F };

					memcpy( aPortVlanMapping, DefaultMapping, sizeof(aPortVlanMapping) );
				}
				else if( strcmp( optarg, "dsp_no_wan" ) == 0 )
				{
					tOCT_UINT32 DefaultMapping[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT] = { 0x1E, 0x7D, 0x7B, 0x17, 0x6F, 0x16, 0x16 };

					memcpy( aPortVlanMapping, DefaultMapping, sizeof(aPortVlanMapping) );
				}
				else
				{
					char * pch = optarg;
					char * pchEnd;

					ulPortVlanMask = 0;

					while( 1 )
					{
						unsigned ulPort;

						ulPort = strtoul(pch, &pchEnd, 0);
						if( pch == pchEnd )
						{
							printf( "Invalid argument : %s\n", pch );
							ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
							return ulResult;
						}
						ulPortVlanMask |= (1<<ulPort);
						pch = strchr( pch, ',' );
						if( pch == NULL )
							break;
						pch++;
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
	if( ulPortId != cOCTVC1_DO_NOT_MODIFY && aPortVlanMapping[0] != cOCTVC1_DO_NOT_MODIFY )
	{
		printf( "Invalid argument, cannot set port id while using VLAN template.\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        return ulResult;
	}
	if( ulPortId != cOCTVC1_DO_NOT_MODIFY && ulPortMirrorDst != cOCTVC1_DO_NOT_MODIFY )
	{
		printf( "Invalid argument, cannot set port id while using Mirror template.\n" );
		ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
        return ulResult;
	}

	// Set default Port Id to 0.
	if( ulPortId == cOCTVC1_DO_NOT_MODIFY )
	{
		ulPortId = 0;
	}

	if( ulPortMirrorSrcList != cOCTVC1_DO_NOT_MODIFY && ulPortMirrorDst == cOCTVC1_DO_NOT_MODIFY )
	{
		// Set ulPortMirrorDst.
		ulPortMirrorDst = ulPortId;
	}

	if( ulPortVlanMask != cOCTVC1_DO_NOT_MODIFY )
	{
		aPortVlanMapping[ulPortId] = ulPortVlanMask;
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
		 * Prepare command data.
		 */
		mOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD_DEF(&EthSwitchCmd);

		EthSwitchCmd.ulPortMirrorSrcList			= ulPortMirrorSrcList;
		EthSwitchCmd.ulPortMirrorDst				= ulPortMirrorDst;
		memcpy( EthSwitchCmd.aPortVlanMapping, aPortVlanMapping, sizeof(EthSwitchCmd.aPortVlanMapping) );
		EthSwitchCmd.ulRestartAutoNegotiationPortId	= ulRestartAutoNegotiationPortId;

		mOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD_SWAP(&EthSwitchCmd);

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
		mOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_RSP_SWAP(&EthSwitchRsp);
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_EthSwitchModifyCmd =
{
	EthSwitchModifyCommand,
	"eth_switch_modify", "esm",
	"[-p 0..6] -w 0,...,6 | -w no_mirror | -w mirror_dsp_cpu | [-p 0..6] -v 0,...,6 | -v default | -v dsp_no_wan",
	"Modifies ethernet switch configurations.",
	"\n"
	"Valid Options:\n"
	" -p ARG : Port identifier to apply configuration changes. This option in NOT valid with template, ARG is any value 0..6. Default is 0.\n"
	" -w ARG : Port mirroring argument. Here -p represents the port mirroring destination. ARG is one of:\n"
	"         '0,1,...,6       : list of port id to be mirrored.\n"
	"         'no_mirror'      : template used to disable mirroring.\n"
	"         'mirror_dsp_cpu' : template to mirror to the WAN all frames traveling between cpu and DSPs.\n"
	" -v ARG : Vlan mapping option. Here -p represents the port for which we want to modify its destinations. ARG is one of :\n"
	"         '0,1,...,6       : list of port id that represents which output ports it can send frames to.\n"
	"         'default'        : template that resets default configuration values.\n"
	"         'dsp_no_wan'     : template that disconnects the DSPs of the WAN.\n"
	"\n"
};
