/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IRSC_EVT.h
Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the IRSC API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_IRSC_EVT_H__
#define __OCTVC1_IRSC_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_irsc_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT

 Members:
	Header
	hProcess
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;

} tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT;


#endif /* __OCTVC1_IRSC_EVT_H__ */

