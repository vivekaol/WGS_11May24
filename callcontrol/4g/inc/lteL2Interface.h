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
 * File Name   : lteL2Interface.h
 *
 * Description : This is header file for L2 interface. It has definition of 
 *               data structures for l2 interface.
 *
 * History     :
 *
 * Date	        Author                  Details
 * ---------------------------------------------------------------------------
 * 21/03/2015   Kuldeep S. Chauhan      File Creation
 ############################################################################*/
#ifndef _L2_INTERFACE_H_
#define _L2_INTERFACE_H_
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "lteCmnDef.h"

/* -----------------------------------------------------
 *           MACRO Definitions 
 * ----------------------------------------------------- */
/* -----------------------------------------------------
 *           Data Structures for L2 Msg 
 * ----------------------------------------------------- */
typedef enum _LteMsgType_e
{
   LTE_MSG_INVALID_E = 0,
   LTE_MSG_RRC_UL_DATA_IND_E = 1,
   LTE_MSG_MAC_RLC_ACK_CTRL_PDU_E = 2,
   LTE_MSG_IDENTITY_REQ_DL_DCH_SDU_REQ_E = 3,
   LTE_MSG_ATTACH_REJ_DL_DCH_SDU_REQ_E = 4,
   LTE_MSG_TAU_REJ_DL_DCH_SDU_REQ_E = 5,
   LTE_MSG_RRC_CONN_REL_DL_DCH_SDU_REQ_E = 6,
   LTE_MSG_RRC_CONN_REDIRECT_DL_DCH_SDU_REQ_E = 7,
   LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E = 8,
   LTE_MSG_MAC_RESET_REQ_E = 9,
   LTE_MSG_RLC_RESET_REQ_E = 10,
   LTE_MSG_RELEASE_UE_TO_NETWORK_REQ_E = 11,
   LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E = 12,
   LTE_MSG_PAGING_START_REQ_E = 13,
   LTE_MSG_RRC_UECAPA_ENQ_REQ_E = 14,
   LTE_MSG_RRC_RESTART_SIB_CHANGE_PAGING_TIMER_E = 15,
   LTE_MSG_RRC_MEAS_REQ_E = 16,
   LTE_MSG_RRC_DELETE_BLACKLIST_USER_E = 17,
   LTE_MSG_RRC_BLACKLIST_TEST_PAGE_SIBMOD = 18,
   LTE_MSG_PAGING_STOP_REQ_E = 19,
   LTE_MSG_UPDATE_PHR_RSSI_IN_SILENT_CALL_E = 20,
   LTE_MSG_TRIGGER_RRC_RECONFIG_REQ_E = 21,
   LTE_MSG_RRC_RECONFIG_REQ_E = 22,
   LTE_MSG_RRC_START_IDENTITY_REQ_TIMER_E = 23,
   LTE_MSG_RRC_NEIGH_MEAS_REQ_E = 24,
   LTE_MSG_MAX_NUM_E = 0xFF

}lteMsgType_e;

typedef struct _LteL2IntfData_t
{
   uint16   crnti;
   uint16   size;
   uint16   PO; // In Downlink it is PO , In Uplink it is firstByte - PHR , secondByte - RSRP/PRB (negative value)
   uint16   PF; //In Downlink it PF , in Uplink this is Timing Advance.
   sint16   snr; 
   uint16   emeCallInd; 
   //Kept it in end so that it is easy to convert to Variable length array if needed
   uint8    dataBuf[LTE_MAX_RRC_MSG_SIZE];
   void*   spare;
}lteL2IntfData_t;

typedef struct _LteL2IntfMsg_t
{
   lteMsgType_e     msgType;
   lteL2IntfData_t  l2Data;

}lteL2InftMsg_t;


#endif
