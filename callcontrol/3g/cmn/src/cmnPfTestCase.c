/*===============================================================
 *    TEST FILE FOR PLATFORM CODE
 *==============================================================*/
#include "msgQue.h"
#include "taskHndlr.h"

//#include "
//#include "
U16 rrcAppTaskHndlr(Msg_t msgBuf)
{
   printf("===== RRCAPP MESSAGE HANDLER CALLED\n");
   return ; //Dummy
}
U16 l2DlDataTaskHndlr(Msg_t msgBuf)
{
   U16 tmp = 0;
   tmp++;
   return ; //Dummy
}
void l2UlDataTaskHndlr(Msg_t msgBuf)
{
   return ; //Dummy
}
void l2CfgTaskHndlr(Msg_t msgBuf)
{
   return ; //Dummy
}
int main (void)
{
   // ----
   printf("===== INITIALIZE : Thread,MsgQueue and Thread Context =========\n");
   InitMsgQueCntxt();
   InitTaskCntxt();
   InitThrdCntxt(); 

   // ----
   printf("===== Create Thread Entries: Main Thread, CL Thread =========\n");
   CreateThrdCntxt(THRD_ID_STACK_APP_E, &gMsgQCntxt); // STACK&APP Thread MsgQueuContext mapped
   CreateThrdCntxt(THRD_ID_CL_E,         NULL);       // CL TASK: No MsgQueueContext

   // ----
   printf("===== Create Tasks Entries: RRC/APP, L2_DL, L2_UL, L2_CFG, CL_L1C =========\n");
   CreateTask(APP_RRC_TASK_E,    THRD_ID_STACK_APP_E, APP_RRC_TASK_QUEUE_E);
   CreateTask(L2_DL_DATA_TASK_E, THRD_ID_STACK_APP_E, L2_DL_DATA_TASK_QUEUE_E);
   CreateTask(L2_UL_DATA_TASK_E, THRD_ID_STACK_APP_E, L2_UL_DATA_TASK_QUEUE_E);
   CreateTask(L2_CFG_TASK_E,     THRD_ID_STACK_APP_E, L2_CFG_TASK_QUEUE_E);
   CreateTask(CL_L1C_SND_TASK_E, THRD_ID_STACK_APP_E, INVALID_MSG_QUEUE_ID);
   CreateTask(CL_L1C_RCV_TASK_E, THRD_ID_CL_E,        INVALID_MSG_QUEUE_ID);


   // ---- As CL Will be receiving Msg only from L1C, no need to have MsgQ with APP platform
   printf("===== Create Msg Q Entries: RRC/APP, L2_DL, L2_UL, L2_CFG =========\n");
   CreateMsgQue(APP_RRC_TASK_QUEUE_E,    rrcAppTaskHndlr);
   CreateMsgQue(L2_DL_DATA_TASK_QUEUE_E, l2DlDataTaskHndlr);
   CreateMsgQue(L2_UL_DATA_TASK_QUEUE_E, l2UlDataTaskHndlr);
   CreateMsgQue(L2_CFG_TASK_QUEUE_E,     l2CfgTaskHndlr);

   return 0;
}
