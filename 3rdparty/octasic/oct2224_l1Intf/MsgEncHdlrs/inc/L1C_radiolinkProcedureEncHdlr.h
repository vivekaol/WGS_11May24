/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEncHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_RADIOLINKPROCEDUREENCHDLR_H_
#define _L1C_RADIOLINKPROCEDUREENCHDLR_H_
#include "l1MsgStatus.h"
#include "l1IntEnums.h"

void radiolinkSetupRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  );

void radiolinkReconfigPrepRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkReconfigPrepRequestProcEncCommit ( ProcedureStatus_e procStatus  );

void radiolinkReconfigCommitRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkReconfigCommitRequestProcEncCommit ( ProcedureStatus_e procStatus  );

void radiolinkDeleteRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkDeleteRequestProcEncCommit ( ProcedureStatus_e procStatus  );

void radiolinkReconfigCancelRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkReconfigCancelRequestProcEncCommit ( ProcedureStatus_e procStatus  );

#endif 
