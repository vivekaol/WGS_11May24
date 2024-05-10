/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octsamples_pkt_api_session.h

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: 27374 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTSAMPLES_PKT_API_SESSION_H__
#define __OCTSAMPLES_PKT_API_SESSION_H__

#include "octvc1/pkt_api/octvc1_pkt_api.h"
#include "../../common/octosal/include/octosal.h"

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

/***************************  TYPE DEFINITIONS  ******************************/

#define cOCTSAMPLES_PKT_API_SESSION_MAX_CNCT           8
#define cOCTSAMPLES_PKT_API_SESSION_MAX_SESS           8


	
typedef struct tOCTSAMPLES_PKT_API_CNCT_EXTERNAL_TAG
{
	tOCTTRANSAPI_HANDLE				hTrans;
	tOCTTRANSAPI_DESTINATION_HANDLE	hTransDest;

} tOCTSAMPLES_PKT_API_CNCT_EXTERNAL, *tPOCTSAMPLES_PKT_API_CNCT_EXTERNAL, **tPPOCTSAMPLES_PKT_API_CNCT_EXTERNAL;

/*
 * Packet API information.
 */
typedef struct tOCTSAMPLES_PKT_API_INFO_TAG
{
	tOCT_BOOL32			  fUseExternalTransport;/* if true use external transport for octpkt and octpkt_xl */
    tPOCTVC1_PKT_API_INST pPktApiInst;          /* Packet API instance. */
    tPOCTVC1_PKT_API_CNCT pPktApiCnct;          /* Packet API connection. */
    tPOCTVC1_PKT_API_CNCT pPktApiCnctPktXl;     /* Packet OCTPKT XL connect. */
    tPOCTVC1_PKT_API_SESS pPktApiSess;          /* Packet API session. */
    tOCT_UINT32           ulPktApiCnctPortIdx;  /* Packet API connection port index. */

	tOCTSAMPLES_PKT_API_CNCT_EXTERNAL	OctPktExt;	 /* OCTPKT External connect information. */
	tOCTSAMPLES_PKT_API_CNCT_EXTERNAL	OctPktXlExt; /* OCTPKT_XL External connect information. */
	
} tOCTSAMPLES_PKT_API_INFO, *tPOCTSAMPLES_PKT_API_INFO, **tPPOCTSAMPLES_PKT_API_INFO;

typedef struct tOCTSAMPLES_DISCOVER_DEVICE_PARMS_TAG
{
    /* OUT */
    tOCTVC1_PKT_API_DEV_INFO     aDeviceInfo[cOCTVC1_PKT_API_DEV_MAX];   /* Array of Vocallo MGw capable devices */
    tOCT_UINT32                  ulDeviceCnt;
    
} tOCTSAMPLES_DISCOVER_DEVICE_PARMS, *tPOCTSAMPLES_DISCOVER_DEVICE_PARMS, **tPPOCTSAMPLES_DISCOVER_DEVICE_PARMS;


/***************************  FUNCTION PROTOTYPES  ***************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesSelectLocalMacAddr

Description:    Allows the user to select a local MAC address.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesSelectLocalMacAddr( tOCT_UINT8 f_abyLocalMacAddr[6] );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesDiscoverDevice

Description:    Returns a list of Vocallo MGw capable devices.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesDiscoverDevice( tPOCTVC1_PKT_API_INST                 f_pPktApiInst,
                                         tPOCTSAMPLES_DISCOVER_DEVICE_PARMS f_pDeviceParms );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSession

Description:    Opens a packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesOpenPktApiSession(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                           tOCT_UINT8                   f_abyLocalMacAddr[6],
                                           tOCT_UINT8                   f_abyRemoteMacAddr[6]);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSessionExtDef

Description:    Set tPOCTSAMPLES_PKT_API_INFO to default value to 
				open 2 external connection( one OCTPKT and one OCTPKT_XL)

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OctSamplesOpenPktApiSessionExtDef( tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSessionExt

Description:    Opens a packet API session.
				Allow to open 2 external connection( one OCTPKT and one OCTPKT_XL)

				ATTENTION : Must call OctSamplesOpenPktApiSessionExtDef() before

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctSamplesOpenPktApiSessionExt( tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo ,
                                            tOCT_UINT8                   f_abyLocalMacAddr[6],
                                            tOCT_UINT8                   f_abyRemoteMacAddr[6] );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesClosePktApiSession

Description:    Closes a packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesClosePktApiSession(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo);

#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

#endif /* __OCTSAMPLES_PKT_API_SESSION_H__ */

