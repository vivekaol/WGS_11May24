/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_API.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_API_H__
#define __OCTVC1_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_module.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_API_SESSION_INDEX_CURRENT_TRANSPORT			0xF0000000	 	/* Select the session used by the current transport. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_API_SESSION_INFO
 		API SESSION information

 Members:
	ulActiveFlag
 		Session active flag
	ulSessionId
 		Session id
	ulTransportSessionIndex
 		Session Index use to transport this command
	ulTransportSessionId
 		Session ID use to transport this command
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32		ulActiveFlag;
	tOCT_UINT32		ulSessionId;
	tOCTVC1_INDEX	ulTransportSessionIndex;
	tOCT_UINT32		ulTransportSessionId;

} tOCTVC1_API_SESSION_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK : 	API SYSTEM event module mask.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK			tOCT_UINT32

#define cOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_NONE		0x00000000	
#define cOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_MAIN		((tOCT_UINT32)(0x00000001<<cOCTVC1_MODULE_ID_ENUM_MAIN) )	
#define cOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_JOB		((tOCT_UINT32)(0x00000001<<cOCTVC1_MODULE_ID_ENUM_JOB) )	
#define cOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_HW		((tOCT_UINT32)(0x00000001<<cOCTVC1_MODULE_ID_ENUM_HW) )	
#define cOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_IRSC		((tOCT_UINT32)(0x00000001<<cOCTVC1_MODULE_ID_ENUM_IRSC) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_API_SESSION_EVT_INFO
 		API SESSION Event Info

 Members:
	ulEvtActiveFlag
 		Host event activate flag
	lEvtEnablerCnt
 		The number of entities that have enabled events on this session
	ulSystemEvtMask
 		System module enabled events on this session
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32									ulEvtActiveFlag;
	tOCT_INT32									lEvtEnablerCnt;
	tOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK	ulSystemEvtMask;

} tOCTVC1_API_SESSION_EVT_INFO;

/*-------------------------------------------------------------------------------------
 	API Version Format
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTVC1_API_VERSION_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_API_VERSION_MASK							tOCT_UINT32

#define cOCTVC1_API_VERSION_MASK_MAJOR_BIT_MASK				0x0000001F	
#define cOCTVC1_API_VERSION_MASK_MAJOR_BIT_OFFSET			27		
#define cOCTVC1_API_VERSION_MASK_MAJOR						((tOCT_UINT32)(cOCTVC1_API_VERSION_MASK_MAJOR_BIT_MASK<<cOCTVC1_API_VERSION_MASK_MAJOR_BIT_OFFSET) )	

#define cOCTVC1_API_VERSION_MASK_MINOR_BIT_MASK				0x0000003F	
#define cOCTVC1_API_VERSION_MASK_MINOR_BIT_OFFSET			21		
#define cOCTVC1_API_VERSION_MASK_MINOR						((tOCT_UINT32)(cOCTVC1_API_VERSION_MASK_MINOR_BIT_MASK<<cOCTVC1_API_VERSION_MASK_MINOR_BIT_OFFSET) )	

#define cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_MASK		0x0000003F	
#define cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_OFFSET		15		
#define cOCTVC1_API_VERSION_MASK_MAINTENANCE				((tOCT_UINT32)(cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_MASK<<cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_OFFSET) )	

#define cOCTVC1_API_VERSION_MASK_BUILD_BIT_MASK				0x00007FFF	
#define cOCTVC1_API_VERSION_MASK_BUILD_BIT_OFFSET			0		
#define cOCTVC1_API_VERSION_MASK_BUILD						((tOCT_UINT32)(cOCTVC1_API_VERSION_MASK_BUILD_BIT_MASK<<cOCTVC1_API_VERSION_MASK_BUILD_BIT_OFFSET) )	


#endif /* __OCTVC1_API_H__ */

