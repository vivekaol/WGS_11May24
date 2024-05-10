/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octvc1_id2string_priv.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

This file contains the id2string implementation for package OCTVC1

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.3.2-B385 (09/01/2018)

$Revision:  $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef __OCTVC1_ID2STRING_PRIV__
#define __OCTVC1_ID2STRING_PRIV__

#include "../octdev_types.h"
#include "octvc1_id2string.h"
/* -------------------------------------------------------------------------------------
	OCTVC1_ID2STRING_PRIV
   -------------------------------------------------------------------------------------*/
#define mOCTVC1_ID2STRING_PRIV( _f_ulId ) \
	octvc1_id2string_priv( _f_ulId )

#ifndef OCTVC1_ID2STRING_PRIV_DECLARE
extern const char * octvc1_id2string_priv( tOCT_UINT32 f_ulId );
#endif 


#ifdef OCTVC1_ID2STRING_PRIV_DECLARE
#include <stdio.h>
#include "test/octvc1_test_id_priv.h"
#include "hw/octvc1_hw_id_priv.h"
#include "main/octvc1_main_id_priv.h"

#include "octvc1_module.h"
/* -------------------------------------------------------------------------------------
	octvc1_id2string_priv
   -------------------------------------------------------------------------------------*/
const char * octvc1_id2string_priv( tOCT_UINT32 f_ulId )
{
	static char g_szUnknownoctvc1_id2string_priv[32];
	switch( f_ulId & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET ))
	{
		/* OCTVC1_TEST */
		case cOCTVC1_TEST_MSG_DESCR_LIST_CID:
			return "cOCTVC1_TEST_MSG_DESCR_LIST_CID";
		case cOCTVC1_TEST_MSG_DESCR_INFO_CID:
			return "cOCTVC1_TEST_MSG_DESCR_INFO_CID";
		case cOCTVC1_TEST_MSG_DESCR_INFO_BY_NAME_CID:
			return "cOCTVC1_TEST_MSG_DESCR_INFO_BY_NAME_CID";
		case cOCTVC1_TEST_MSG_DESCR_STATS_CID:
			return "cOCTVC1_TEST_MSG_DESCR_STATS_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_INFO_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_INFO_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_STATS_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_STATS_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_START_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_START_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_STOP_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_STOP_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_ADD_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_ADD_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_REMOVE_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_REMOVE_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_LIST_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_LIST_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_INFO_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_INFO_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_STATS_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_STATS_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_START_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_START_TEST_CID";
		case cOCTVC1_TEST_MSG_RUNNER_SERVER_STOP_TEST_CID:
			return "cOCTVC1_TEST_MSG_RUNNER_SERVER_STOP_TEST_CID";
		/* OCTVC1_GENERIC */
		case ( cOCTVC1_MAIN_MSG_LICENSING_INFO_INFRACTION_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_LICENSING_INFO_INFRACTION_CID";
		case ( cOCTVC1_MAIN_MSG_LICENSING_LIST_INFRACTION_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_LICENSING_LIST_INFRACTION_CID";
		case ( cOCTVC1_MAIN_MSG_LICENSING_INFO_INFRACTION_CONFIG_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_LICENSING_INFO_INFRACTION_CONFIG_CID";
		case ( cOCTVC1_MAIN_MSG_LICENSING_MODIFY_INFRACTION_CONFIG_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_LICENSING_MODIFY_INFRACTION_CONFIG_CID";
		case ( cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_INFO_MODULE_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_INFO_MODULE_CID";
		case ( cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_MODIFY_MODULE_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_MODIFY_MODULE_CID";
		case ( cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_RELOAD_MODULE_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_APPLICATION_CONFIG_RELOAD_MODULE_CID";
		case (cOCTVC1_MAIN_MSG_LICENSING_INFRACTION_STATE_CHANGE_EID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_MAIN_MSG_LICENSING_INFRACTION_STATE_CHANGE_EID";
		case ( cOCTVC1_HW_MSG_ETH_PORT_RESTRICTED_UNBLOCK_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_HW_MSG_ETH_PORT_RESTRICTED_UNBLOCK_CID";
		case ( cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_CID";
		case ( cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_CID";
		case ( cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_MODIFY_SYNCHRO_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_MODIFY_SYNCHRO_CID";
		case ( cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_EXT_CID & ~( cOCTVC1_MSG_FLAGS_BIT_MASK << cOCTVC1_MSG_FLAGS_BIT_OFFSET )):
			return "cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_EXT_CID";

		default:
			break;

	}
	return octvc1_id2string( f_ulId );
}
#endif 

#endif /* __OCTVC1_ID2STRING_PRIV__ */
