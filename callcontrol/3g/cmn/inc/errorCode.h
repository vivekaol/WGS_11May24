/*
 *############################################################################
 *
 *                   *** FXLynx Technologies Ltd. ***
 *
 *     The information contained in this file is the property of FXLynx
 *     Technologies Ltd. Except as specifically authorized in writing by
 *     FXLynx Technologies Ltd. The user of this file shall keep information
 *     contained herein confidential and shall protect same in whole or in
 *     part from disclosure and dissemination to third parties.
 *
 *     Without prior written consent of FXLynx Technologies Ltd. you may not
 *     reproduce, represent, or download through any means, the information 
 *     contained herein in any way or in any form.
 *
 *       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
 *
 *############################################################################
 */

/*
 *############################################################################
 * File Name   : errorCode.h
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 *############################################################################
*/
#ifndef _ERROR_CODE_H_ 
#define _ERROR_CODE_H_

#include "feaConfig.h"

/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
 */
typedef enum _ErrorCode
{
    ERROR_GENERIC_FAILURE_E,
    ERROR_MSG_QUEUE_INVALID_E,
    ERROR_MSG_QUEUE_FULL_E,
    ERROR_L1_DECODE_FAIL_E,
    ERROR_L1_DATA_READ_FAIL_E,
    ERROR_L2_RACH_DATA_CRC_ERROR_E,
    ERROR_L2_DCH_DATA_CRC_ERROR_E,
    ERROR_CODE1_E,        /* Error Code Definition */
    ERROR_CODE2_E,        /* Error Code Definition */
    /* L2 ERROR CODES - Start */
    ERROR_L2_DATA_CRC_ERROR_E,
    ERROR_L2_RACH_HDR_DECODE_FAIL_E,

    // RLC-Error
    ERROR_INVALID_LOGCH_TYPE_E,
    ERROR_RLC_HDR_DECODE_FAIL_E,
    ERROR_RLC_AMD_RX_PDU_PROC_FAIL_E,
    ERROR_RLC_AMD_SDU_ASSMBLY_FAIL_E,
    ERROR_RLC_AMD_CTRL_PDU_FAIL_E,
    ERROR_RLC_AMD_STATUS_PDU_PENDING_E,
    ERROR_RLC_AMD_DATA_PDU_FAIL_E,
    ERROR_RLC_GENERIC_FAILURE_E,
    ERROR_RLC_UMD_RX_PDU_PROC_FAIL_E,
    ERROR_RLC_UMD_SDU_ASSMBLY_FAIL_E,
    /* L2 ERROR CODES - End*/
    ERROR_CODE3_E,        /* Failed to Open L1C port */
    ERROR_CODE4_E,        /* Rx Thread creation failed*/
    ERROR_CODE5_E,        /* Error Code Definition */
    ERROR_RADIO_LINK_FAILURE_E,
    ERROR_RADIO_LINK_RECONFIG_PREP_FAILURE_E,
    ERROR_RADIO_LINK_RECONFIG_READY_FAILURE_E,
    ERROR_RADIO_LINK_RECONFIG_COMMIT_FAILURE_E,
    ERROR_DEDICATED_MEAS_INIT_FAILURE_E,
    ERROR_DEDICATED_MEAS_INIT_RSP_FAILURE_E,
    ERROR_DEDICATED_MEAS_TERM_REQ_FAILURE_E,
    ERROR_DEDICATED_MEAS_REPORT_FAILURE_E,
    /*Keep Adding error cause here*/
    SUCCESS_E
	
} ErrorCode_e; /*ErrorCode_e*/

#endif

