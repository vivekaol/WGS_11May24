/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcDecHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Response Procedure Decode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef _L1C_RESPONSEPROCDECHDLR_H_
#define _L1C_RESPONSEPROCDECHDLR_H_
#include "l1MsgStatus.h"
#include "l1IntEnums.h"

void genericResponseProcDecHdlr( L1MsgStatus_t *msgStatus);
void genericResponseProcDecCommit ( ProcedureStatus_e procStatus  );

void cmnTrchPrachSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus );
void cmnTrchPrachSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  );

void cmnTrchSccpchSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus );
void cmnTrchSccpchSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  );

void commonMeasInitResponseProcDecHdlr( L1MsgStatus_t *msgStatus );
void commonMeasReportProcDecHdlr( L1MsgStatus_t *msgStatus );
void commonMeasFailIndicationProcDecHdlr( L1MsgStatus_t *msgStatus );

void radiolinkSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus );
void radiolinkSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  );

void radiolinkReconfigReadyProcDecHdlr( L1MsgStatus_t *msgStatus );
void radiolinkReconfigReadyProcDecCommit ( ProcedureStatus_e procStatus  );

void radiolinkFailureIndicationProcDecHdlr( L1MsgStatus_t *msgStatus );
void radiolinkRestoreIndicationProcDecHdlr( L1MsgStatus_t *msgStatus );

void dedicatedMeasInitResponseProcDecHdlr( L1MsgStatus_t *msgStatus );
void dedicatedMeasReportProcDecHdlr( L1MsgStatus_t *msgStatus );
void dedicatedMeasFailIndicationProcDecHdlr( L1MsgStatus_t *msgStatus );

#endif 
