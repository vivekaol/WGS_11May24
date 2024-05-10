/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_LOCAL.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_LOCAL_H__
#define __OCTTRANSAPI_LOCAL_H__

/*****************************  INCLUDE FILES  *******************************/
#include "octtransapi.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/


/*----------------------------------------------------------------------------
	Transport open
----------------------------------------------------------------------------*/
typedef struct _OCTTRANSAPI_LOCAL_OPEN_PARMS_
{
	tOCT_UINT32		ulReserved;
}tOCTTRANSAPI_LOCAL_OPEN_PARMS, *tPOCTTRANSAPI_LOCAL_OPEN_PARMS;

/*****************************  FUNCTIONS ************************************/
/*--------------------------------------------------------------------------
	OctTransApiLocalOpen

		This function opens a transport object.

  f_pParm				: IN Pointer to tOCTTRANSAPI_LOCAL_OPEN_PARMS structure.
  f_phTransport			: OUT Pointer to opened transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiLocalOpen( tPOCTTRANSAPI_LOCAL_OPEN_PARMS f_pParm, 
									   tOCTTRANSAPI_HANDLE *f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiLocalClose

		This function closes a transport object.

	f_hTransport			: IN transport object handle.

Return :	0 means success
			Negative value means error.

----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiLocalClose( tOCTTRANSAPI_HANDLE f_hTransport );

/*--------------------------------------------------------------------------
	OctTransApiLocalSend

		This function sends a buffer on a transport object.

  f_hTransport			: IN The transport handle.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

Return :	Size of the sent buffer in bytes
			Negative value means error.
			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiLocalSend( tOCTTRANSAPI_HANDLE f_hTransport, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength  );

/*--------------------------------------------------------------------------
	OctTransApiLocalRecv

		This function receives a buffer from a transport object.

  f_hTransport			: IN The transport handle.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiLocalRecv( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCT_UINT32 f_ulTimeoutMs, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_LOCAL_H__*/


