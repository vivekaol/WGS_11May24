/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sysInfoEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control System Information Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>
#include "L1C_sysInfoEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"

static void bcchSib7InfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                    void * pSrc)
{
    L1CAPI_BCCH_SIB7_Info *pBcchSib7Inf = (L1CAPI_BCCH_SIB7_Info *)pSrc;

START_BLOCK_TRACE
    ADD_WORD_VAL(pBcchSib7Inf->sibPos);
    ADD_BYTE_VAL(pBcchSib7Inf->sibRep);
END_BLOCK_TRACE

	return;
}

void systemInfoUpdateRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_BCH_SIM_DATA * pOpSysInfo = (uint8_t* )pHostDLMsg;
	L1CAPI_BCCH_SIB7_Info *pBcchSib7Inf;
    uint8_t * wrPtr = NULL;
    uint16_t sysInfoBytes;
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;

	pBcchSib7Inf = &pOpSysInfo->sib7Info;
    wrPtr = getCurrentBodyWrPtr();
        
    //L1 accepts only 2048 bytes of BCH SIB Data
    //Default value is 2048 bytes. Can be set upto maximum 8192 bytes from 03.15.00 
    sysInfoBytes = 2048;
    //WARNING: Currently assuming any Stack except CCPU will use 64 TTIs / 128 TTIs / 256 TTIs of BCH SIB Data    
    memcpy(wrPtr,pOpSysInfo,sysInfoBytes);

	addBodyWrOffset(2048);

PRINTF("L23--> System Information Update Request \n");

#ifdef L1C_TRACE_CONTENT
        
    {
        uint32_t rowcount, colcount, offset, nRows;
        offset=0;
        nRows = sysInfoBytes>>5;
        PRINTF("L1C systemInfoUpdateRequestProcEncHdlr: System Information Dump - %d bytes (%d rows by 32 columns) \n\n", sysInfoBytes, nRows);
        
        for (rowcount=0; rowcount<nRows; rowcount++)
        {   
            PRINTF("       ");
            for (colcount=0; colcount<32; colcount++)
            {
                PRINTF("0x%-2x,", pOpSysInfo->data[offset]);
                offset++;
            }
            PRINTF("\n");
        }
    
    }
    PRINTF("\n\n"); 

#endif    

	/*BCCH SIB7 info*/
    bcchSib7InfoProcEncHdlr(msgStatus,pBcchSib7Inf);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }

    return;
}

void systemInfoUpdateRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

} 
