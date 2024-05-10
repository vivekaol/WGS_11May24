/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_modemSetupEncHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Modem Setup Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef _L1C_MODEMSETUPENCHDLR_H_
#define _L1C_MODEMSETUPENCHDLR_H_
#include "l1MsgStatus.h"
#include "l1IntEnums.h"

void modemSetupRequestProcEncHdlr( L1CAPI_Msg_Status  *msgStatus );
void modemSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  );
#endif 
