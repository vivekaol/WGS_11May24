/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_commonMeasProcedureEncHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Common Measurement Procedures Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_COMMONMEASPROCEDUREENCHDLR_H_
#define _L1C_COMMONMEASPROCEDUREENCHDLR_H_

#include "l1MsgStatus.h"

void commonMeasInitRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );
void commonMeasTermRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus );

#endif
