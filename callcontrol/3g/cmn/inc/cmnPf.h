/*############################################################################
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
 ############################################################################*/

/*############################################################################
 * File Name   : cmnPf.h
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date	        Author                  Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 ############################################################################*/
#include "feaConfig.h"
#ifndef ___CMN_PF_H_
#define ___CMN_PF_H_

// QueueId value is also used as priority. Lowest QueueID ==> Highest Priority
// To Change Priority suffle values UP/DOWN in enum list 
typedef enum __MsgQueId{
   INVALID_MSG_QUEUE_ID,
   APP_RRC_TASK_QUEUE_E,
   L2_DL_DATA_TASK_QUEUE_E,
   L2_UL_DATA_TASK_QUEUE_E,
   L2_CFG_TASK_QUEUE_E,
   CL_L1C_SND_TASK_QUEUE_E,
   CL_L1C_RCV_TASK_QUEUE_E,  //NO Queue for CL RCV TASK, as its directly reading frm L1 
   MAX_MSG_QUEUE_NUM_E

} MsgQueId_e;

typedef enum __MsgType
{
   //NBAP CELL Related Message Type from CL to APP/RRC
   CL_NBAP_MODEM_SETUP_RSP_MSG_E,
   CL_NBAP_CELL_DELETE_RSP_E,
   CL_NBAP_CELL_SETUP_RSP_E,
   CL_NBAP_CELL_RECONFIG_RSP_E,
   CL_NBAP_SYSTEM_INFO_UPDATE_RSP_E,
   CL_NBAP_SCCPCH_SETUP_RSP_E,
   CL_NBAP_PRACH_SETUP_RSP_E,
   CL_NBAP_MSG_NUM_E,

   //NBAP UE SPECIFIC Message Type from CL to APP/RRC
   CL_NBAP_UE_RADIO_LINK_SETUP_RSP_E,
   CL_NBAP_UE_RADIO_LINK_FAILURE_E,
   CL_NBAP_UE_RADIO_LINK_DELETE_RSP_E,
   CL_NBAP_UE_RTT_DEDICATED_MEAS_INIT_RSP_E,
   CL_NBAP_UE_RSCP_DEDICATED_MEAS_INIT_RSP_E,
   CL_NBAP_UE_RTT_DEDICATED_MEAS_REPORT_E,
   CL_NBAP_UE_RSCP_DEDICATED_MEAS_REPORT_E,
   CL_NBAP_UE_RTT_DEDICATED_MEAS_TERM_RSP_E,
   CL_NBAP_UE_RSCP_DEDICATED_MEAS_TERM_RSP_E,
   CL_NBAP_UE_RADIO_LINK_RECONFIG_READY_E,

   //UE SPECIFIC Message Type from APP/SRC to CL
   CL_NBAP_UE_RADIO_LINK_SETUP_REQ_E,
   CL_NBAP_UE_RADIO_LINK_DELETE_REQ_E,
   CL_NBAP_UE_RTT_DEDICATED_MEAS_INIT_REQ_E,
   CL_NBAP_UE_RSCP_DEDICATED_MEAS_INIT_REQ_E,
   CL_NBAP_UE_RTT_DEDICATED_MEAS_TERM_REQ_E,
   CL_NBAP_UE_RSCP_DEDICATED_MEAS_TERM_REQ_E,
   CL_NBAP_UE_RTT_ON_DEMAND_MEAS_INIT_REQ_E,
   CL_NBAP_UE_RSCP_ON_DEMAND_MEAS_INIT_REQ_E,
   CL_NBAP_UE_RADIO_LINK_RECONFIG_PREP_REQ_E,
   CL_NBAP_UE_RADIO_LINK_RECONFIG_COMMIT_REQ_E,

   //Message Type for Message from CL to APP/RRC
   
   //Message Type for Message from CL to L2_DL_data
   CL_L2_DL_TTI_IND,
   //Message Type for Message from CL to L2_UL_data
   CL_L2_UL_RACH_DATA_IND,
   CL_L2_UL_DCH_DATA_IND,
   //Message Type for Message from CL to L2_UL_data

   //Message Type for Message from L2_UL_Data to APP/RRC
   L2_UL_CCCH_DATA_INDICATION_E,
   L2_UL_DCCH_DATA_INDICATION_E,

   //Message Type for Message from APP/RRC to L2_DL_Data
   L2_DL_CCCH_DATA_REQUEST_E,
   L2_DL_DCCH_DATA_REQUEST_E,
   L2_DL_PCCH_DATA_REQUEST_E,
   L2_DL_DEL_PCCH_DATA_REQUEST_E,
   L2_DL_PCCH_UE_OUT_OF_COVERAGE_E,

   //Message Type for Message from APP/RRC to L2_Cfg
   L2_CONFIG_REQUEST_E,
   L2_CONFIG_DEL_REQUEST_E,
   L2_CONFIG_DEL_PCH_DATA_REQUEST_E,

   //Message Type for Message from RLC to APP/RRC
   L2_RLC_ERROR_CALL_RLS_E,

   //Message Type for Message from TIMER to APP/RRC
   RRC_RL_SETUP_TIMEOUT_E,
   RRC_RL_DELETE_TIMEOUT_E,
   RRC_CONN_SETUP_TIMEOUT_E,
   RRC_IDENTITY_REQ_TIMEOUT_E,
   RRC_CONNECTION_REL_TIMEOUT_E,
   RRC_NAS_REJECT_TIMEOUT_E,
   RRC_DED_MEAS_INIT_REQ_TIMEOUT_E,
   RRC_DED_MEAS_TERM_REQ_TIMEOUT_E,
   RRC_PAGING_TYPE2_TIMEOUT_E,
   RRC_PHY_CH_RECONF_TIMEOUT_E,
   RRC_CHANGE_UE_UL_TX_PWR_E,
   RRC_REDIRECT_BL_UE_E,
   RRC_START_GPS_TIMEOUT_E,
   RRC_GPS_MEAS_CNTRL_REL_TIMEOUT_E,

	RRC_DEL_ID_LIST_E,
	
   //Message Type for Message from SOCK ITF to APP/RRC
   APP_STOP_ID_CATCHER_E,

   MAX_MSG_NUM

}MsgType_e;

typedef enum __TaskId
{
   INVALID_TASK_E,
   APP_RRC_TASK_E,
   L2_DL_DATA_TASK_E,
   L2_UL_DATA_TASK_E,
   L2_CFG_TASK_E,
   CL_L1C_RCV_TASK_E,   // TASK ID Added for CL as it will be sending Msg to Other task
   CL_L1C_SND_TASK_E,   // TASK ID Added for CL as it will be sending Msg to Other task
   SOCK_ITF_TASK_E,
   MAX_TASK_NUM_E
}TaskId_e;

typedef enum __ThrdId
{
   INVALID_THRD_ID_E,
   THRD_ID_STACK_APP_E,
   THRD_ID_CL_E,
   THRD_ID_SOCK_ITF_E,
   MAX_THREAD_NUM_E

} ThrdId_e;

typedef enum __BoolType
{
   FALSE_E,
   TRUE_E

} Booltype_e;

void TaskSchedulerPerThrd(ThrdId_e thrdId);

#endif
