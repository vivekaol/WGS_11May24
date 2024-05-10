/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_RC.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_RC_H__
#define __OCTTRANSAPI_RC_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../include/octcommon_base.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
/*----------------------------------------------------------------------------
	Transport RC
----------------------------------------------------------------------------*/
#define tOCTTRANSAPI_RC_ERROR						tOCT_INT32

#define cOCTTRANSAPI_RC_ERROR_NONE					0		/* No error */
#define cOCTTRANSAPI_RC_ERROR_PORTING				-1		/* corruption in porting implementation */
#define cOCTTRANSAPI_RC_ERROR_TRANSPORT				-2		/* transport problem .. Destination disconnect, etc */
#define cOCTTRANSAPI_RC_ERROR_PARAM					-3		/* function param are not valid */

#define cOCTTRANSAPI_RC_ERROR_ALREADY_INIT			-4		/* Already init */
#define cOCTTRANSAPI_RC_ERROR_NOT_INIT				-5		/* Transport not initialised */
#define cOCTTRANSAPI_RC_ERROR_DESTINATION_CTX		-6		/* Not a valid Destination ctx */
#define cOCTTRANSAPI_RC_ERROR_NOMORE_DESTINATION	-7		/* No more Destination */
#define cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR		-8		/* Not a valid Destination address */
#define cOCTTRANSAPI_RC_ERROR_DESTINATION_HEADER	-9		/* Not a valid Destination header before payload */
#define cOCTTRANSAPI_RC_ERROR_NOT_SELECTABLE		-10		/* One of the supplied transport is not selectable */
#define cOCTTRANSAPI_RC_ERROR_SELECT_ABANDON		-11		/* One of the supplied transport did close */
#define cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE		-12		/* Not a valid transport type */
#define cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC			-13		/* Can't alloc memory */
#define cOCTTRANSAPI_RC_ERROR_DISPATCH_CTX			-14		/* Not a valid dispacth ctx */
#define cOCTTRANSAPI_RC_ERROR_NOMORE_DISPATCH		-15		/* No more dispatch ctx */
#define cOCTTRANSAPI_RC_ERROR_DISPATCH_FULL			-16		/* All dispatch transport are used */
#define cOCTTRANSAPI_RC_ERROR_NOMORE_INSTANCE		-17		/* No more transport instance (cOCTTRANSAPI_TRANSPORT_INSTANCE_MAX) */
#define cOCTTRANSAPI_RC_ERROR_BUSY_INSTANCE			-18		/* Instance is busy */
#define cOCTTRANSAPI_RC_ERROR_BUSY_DESTINATION		-19		/* Destination is busy */
#define cOCTTRANSAPI_RC_ERROR_DISPATCH_ASSIGNED		-20		/* Already in a dispatcher */
#define cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT	-21		/* Called select when Transport was open without select */
#define cOCTTRANSAPI_RC_ERROR_OPEN_NO_PERMISSION	-22		/* Can't open socket ... may not be ROOT */
#define cOCTTRANSAPI_RC_ERROR_DISPATCH_NO_RSP		-23		/* Dispatch thread does not respond */
#define cOCTTRANSAPI_RC_ERROR_REQUIRES_MULTI_THREAD	-24		/* Transport functionality requires multi threading support */
#define cOCTTRANSAPI_RC_ERROR_DISCONNECTED			-25		/* Connection has been lost */

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_H__*/


