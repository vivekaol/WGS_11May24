/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_dsp_modify.c

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

Function:       EthSwitchStatsCommand

Description:    Reads and clear ethernet switch statistisc.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 EthSwitchStatsCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD	EthSwitchCmd;
    tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_RSP	EthSwitchRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS		CmdExecuteParms;
    tOCT_UINT32								ulResult = cOCTVC1_RC_OK;
	tOCT_UINT32								ulPortId = 0;
	tOCT_BOOL32								ulResetStatsFlag = cOCT_FALSE;
	int										lOptRetval;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "p:k")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'p':
				ulPortId = strtoul(optarg, NULL, 0);
				break;

			case 'k':
				ulResetStatsFlag = cOCT_TRUE;
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

	// Send command Ethernet Switch Stats.
	{
		/*
		 * Prepare command data.
		 */
		mOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD_DEF(&EthSwitchCmd);

		EthSwitchCmd.ulPortId				= ulPortId;
		EthSwitchCmd.ulResetStatsFlag	= ulResetStatsFlag;

		mOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD_SWAP(&EthSwitchCmd);

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
		mOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_RSP_SWAP(&EthSwitchRsp);

		/*
		 * Print the information.
		 */
		{
			unsigned long long InGoodOctets;
			unsigned long long InDiscards;
			unsigned long long OutOctets;

			InGoodOctets = ((unsigned long long)EthSwitchRsp.PortStats.ulInGoodOctetsSumHi << 32) |
			               EthSwitchRsp.PortStats.ulInGoodOctetsSumLo;
			InDiscards = ((unsigned long long)EthSwitchRsp.PortStats.ulInDiscardsCntHi << 32) |
			               EthSwitchRsp.PortStats.ulInDiscardsCntLo;
			OutOctets = ((unsigned long long)EthSwitchRsp.PortStats.ulOutOctetsSumHi << 32) |
			               EthSwitchRsp.PortStats.ulOutOctetsSumLo;

			printf("+-- BOARD %u ETHERNET SWITCH PORT %u STATISTICS ------------------------------------------------------\n", EthSwitchRsp.ulBoardIndex, EthSwitchRsp.ulPortId );
			printf("| InGoodOctets            : %llu \n", InGoodOctets );
			printf("| InBadOctets             : %lu \n", EthSwitchRsp.PortStats.ulInBadOctetsSum);
			printf("| InUnicast               : %lu \n", EthSwitchRsp.PortStats.ulInUnicastCnt);
			printf("| InBroadcast             : %lu \n", EthSwitchRsp.PortStats.ulInBroadcastCnt);
			printf("| InMulticast             : %lu \n", EthSwitchRsp.PortStats.ulInMulticastCnt);
			printf("| InPause                 : %lu \n", EthSwitchRsp.PortStats.ulInPauseCnt);
			printf("| InUndersize             : %lu \n", EthSwitchRsp.PortStats.ulInUndersizeCnt);
			printf("| InFragment              : %lu \n", EthSwitchRsp.PortStats.ulInFragmentCnt);
			printf("| InOversize              : %lu \n", EthSwitchRsp.PortStats.ulInOversizeCnt);
			printf("| InJabber                : %lu \n", EthSwitchRsp.PortStats.ulInJabberCnt);
			printf("| InRxErr                 : %lu \n", EthSwitchRsp.PortStats.ulInRxErrorCnt);
			printf("| InFCSErr                : %lu \n", EthSwitchRsp.PortStats.ulInFCSErrorCnt);
			printf("| InFiltered              : %lu \n", EthSwitchRsp.PortStats.ulInFilteredCnt);
			printf("| InDiscards              : %llu \n", InDiscards );
			printf("| OutOctets               : %lu \n", OutOctets );
			printf("| OutUnicast              : %lu \n", EthSwitchRsp.PortStats.ulOutUnicastCnt);
			printf("| OutBroadcast            : %lu \n", EthSwitchRsp.PortStats.ulOutBroadcastCnt);
			printf("| OutMulticast            : %lu \n", EthSwitchRsp.PortStats.ulOutMulticastCnt);
			printf("| OutPause                : %lu \n", EthSwitchRsp.PortStats.ulOutPauseCnt);
			printf("| Deferred                : %lu \n", EthSwitchRsp.PortStats.ulDeferredCnt);
			printf("| Collision               : %lu \n", EthSwitchRsp.PortStats.ulCollisionCnt);
			printf("| SingleCollision         : %lu \n", EthSwitchRsp.PortStats.ulSingleCollisionCnt);
			printf("| MultipleCollisions      : %lu \n", EthSwitchRsp.PortStats.ulMultipleCollisionsCnt);
			printf("| ExcessiveCollisions     : %lu \n", EthSwitchRsp.PortStats.ulExcessiveCollisionsCnt);
			printf("| LateCollision           : %lu \n", EthSwitchRsp.PortStats.ulLateCollisionsCnt);
			printf("| OutFCSErr               : %lu \n", EthSwitchRsp.PortStats.ulOutFcsErrorCnt);
			printf("| FrameCnt64Octets        : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt64Octets);
			printf("| FrameCnt65_127Octets    : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt65_127Octets);
			printf("| FrameCnt128_255Octets   : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt128_255Octets);
			printf("| FrameCnt256_511Octets   : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt256_511Octets);
			printf("| FrameCnt512_1023Octets  : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt512_1023Octets);
			printf("| FrameCnt1024_MaxOctets  : %lu \n", EthSwitchRsp.PortStats.ulFrameCnt1024_MaxOctets);
		}

	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}


/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_EthSwitchStatsCmd =
{
	EthSwitchStatsCommand,
	"eth_switch_stats", "ess",
	"[-p 0..6] [-k]",
	"Reads all the counters for a single physical port.",
	"\n"
	"Valid Options:\n"
	" -p ARG : Port identifier to read and clear all the statistic counters. example obm ess -p 1\n"
	" -k     : Clears all the counters after read. example obm ess -k\n"
	"\n"
};
