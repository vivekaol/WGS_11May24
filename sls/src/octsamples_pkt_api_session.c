/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octsamples_pkt_api_session.c

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: 41797 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/***************************  INCLUDE FILES  *********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Target API header files */
#include "../inc/octvc1/pkt_api/octvc1_pkt_api.h"
#include "../inc/octvc1/pkt_api/octvc1_pkt_api_default.h"
#include "../../common/octtransapi/octtransapi_eth/include/octtransapi_eth.h"
#include "../../common/octtransapi/octtransapi_eth/include/octtransapi_eth_default.h"
#include "../../common/octtransapi/include/octtransapi_default.h"
#include "../../common/octtransapi/include/octtransapi.h"

/* Target samples' common header files */
#include "../inc/octsamples_pkt_api_session.h"
#include "../inc/octsamples_string_utils.h"

/***************************  TYPE DEFINITIONS  ******************************/

/*
 * Device port information.
 */
typedef struct tOCTSAMPLES_DEV_PORT_INFO_TAG
{
    tOCT_UINT8  abyPort0MacAddr[6]; /* Target device's port 0 MAC address. */
    tOCT_UINT32 fIsPort0Reachable;  /* Flag: cOCT_TRUE if port 0 is reachable. */
    tOCT_UINT8  abyPort1MacAddr[6]; /* Target device's port 1 MAC address. */
    tOCT_UINT32 fIsPort1Reachable;  /* Flag: cOCT_TRUE if port 1 is reachable. */
} tOCTSAMPLES_DEV_PORT_INFO, *tPOCTSAMPLES_DEV_PORT_INFO, **tPPOCTSAMPLES_DEV_PORT_INFO;

/***************************  CONSTANTS  *************************************/

const tOCT_UINT8 g_abyNullMacAddr[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/***************************  PRIVATE FUNCTIONS  *****************************/



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       InitializePktApiInst

Description:    Initializes a packet API instance.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 InitializePktApiInst(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                        const tOCT_UINT8             f_abyLocalMacAddr[6])
{
    tOCTVC1_PKT_API_INST_GET_SIZE_PARMS InstGetSizeParms;
    tOCTVC1_PKT_API_INST_INIT_PARMS     InstInitParms;
    tOCT_UINT32                         ulResult;
    tOCT_UINT16                         usTime;

    /*
     * Get current time to create unique instance.
     */
    usTime = (tOCT_UINT16)OctOsalGetTimeMs();

    mOCTVC1_PKT_API_INST_GET_SIZE_PARMS_DEF(&InstGetSizeParms);
    InstGetSizeParms.pInitParms = &InstInitParms;

    mOCTVC1_PKT_API_INST_INIT_PARMS_DEF(&InstInitParms);
	InstInitParms.fUseExternalTransport = f_pPktApiInfo->fUseExternalTransport;
	InstInitParms.ulMaxConnection = (f_pPktApiInfo->fUseExternalTransport == cOCT_TRUE) ? 2 : 1;
    InstInitParms.ulMaxSession    = 1;
    InstInitParms.ulMaxSyncCmd    = 8;
    InstInitParms.ulMaxRetry      = 1;
    InstInitParms.ulMaxPendingEvt = 128;
	InstInitParms.ulMaxPendingData = 400;
    InstInitParms.usSessionInstanceStart = usTime;
    memcpy(&InstInitParms.abyLocalMac, f_abyLocalMacAddr, 6);

    /*
     * Get the size, in bytes, of the packet API instance.
     */
    ulResult = OctVc1PktApiInstGetSize(&InstGetSizeParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Allocate memory for the packet API instance.
     */
    f_pPktApiInfo->pPktApiInst = (tPOCTVC1_PKT_API_INST)malloc(InstGetSizeParms.ulRequiredSize);
    if (NULL == f_pPktApiInfo->pPktApiInst)
    {
        return cOCTVC1_PKT_API_RC_OS_ERROR;
    }

    /*
     * Initialize a packet API instance.
     */
    ulResult = OctVc1PktApiInstInit(f_pPktApiInfo->pPktApiInst, &InstInitParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    return cOCTVC1_RC_OK;

ErrorHandling:
    if (f_pPktApiInfo->pPktApiInst)
    {
        free(f_pPktApiInfo->pPktApiInst);
        f_pPktApiInfo->pPktApiInst = NULL;
    }

    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OpenPktApiCnct

Description:    Opens a connection between the transport packet API instance
                and the Target device.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 OpenPktApiCnct(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                  const tOCT_UINT8          f_abyRemoteMacAddr[6])
{
    tOCTVC1_PKT_API_CNCT_OPEN_PARMS CnctOpenParms;
    tOCT_UINT32                     ulResult = cOCTVC1_RC_OK;

    
	mOCTVC1_PKT_API_CNCT_OPEN_PARMS_DEF(&CnctOpenParms);

	f_pPktApiInfo->OctPktExt.hTransDest	  = CnctOpenParms.hTransDest;	/* Set to INVALID */
	f_pPktApiInfo->OctPktXlExt.hTransDest = CnctOpenParms.hTransDest;	/* Set to INVALID */

	if( f_pPktApiInfo->fUseExternalTransport )
	{
		/*Add destination*/
		tOCTDEV_MAC_ADDRESS					DestMacAddr;
		tOCTTRANSAPI_DESTINATION_ADD_PARMS	DestAdd;

		mOCTTRANSAPI_DESTINATION_ADD_PARMS_DEF( &DestAdd );

		memcpy(DestMacAddr.abyMacAddress,f_abyRemoteMacAddr,6);
		DestAdd.pDestinationAddr = &DestMacAddr;
		DestAdd.ulDestinationAddrSize = sizeof(DestMacAddr);

		/* OCTPKT */
		ulResult = OctTransApiDestinationAdd( f_pPktApiInfo->OctPktExt.hTrans, &DestAdd);
		
		/*OCTPKT_XL*/
		if(cOCTVC1_RC_OK == ulResult)
		{
			f_pPktApiInfo->OctPktExt.hTransDest = DestAdd.hDestination;
			ulResult = OctTransApiDestinationAdd( f_pPktApiInfo->OctPktXlExt.hTrans ,&DestAdd );
			if(cOCTVC1_RC_OK == ulResult)
			{
				f_pPktApiInfo->OctPktXlExt.hTransDest = DestAdd.hDestination;
			}
		}

	}
	
	/* Open Connection */
	{
		/* OCTPKT */
		if( f_pPktApiInfo->fUseExternalTransport )
		{
			CnctOpenParms.hTransDest = f_pPktApiInfo->OctPktExt.hTransDest;
		}
		else
		{
			memcpy(CnctOpenParms.abyRemoteMac, f_abyRemoteMacAddr, 6);
		}


   		ulResult = OctVc1PktApiCnctOpen(f_pPktApiInfo->pPktApiInst, &CnctOpenParms);
   		if(cOCTVC1_RC_OK == ulResult)
		{
   			f_pPktApiInfo->pPktApiCnct = CnctOpenParms.pConnection;
			if( f_pPktApiInfo->fUseExternalTransport )
			{
				/*OCTPKT_XL*/
				CnctOpenParms.hTransDest = f_pPktApiInfo->OctPktXlExt.hTransDest;
   				ulResult = OctVc1PktApiCnctOpen(f_pPktApiInfo->pPktApiInst, &CnctOpenParms);
				if( cOCTVC1_RC_OK == ulResult )
				{
   					f_pPktApiInfo->pPktApiCnctPktXl = CnctOpenParms.pConnection;
				}
			}
		}
		
		if( cOCTVC1_RC_OK != ulResult )
   		{
   		    goto ErrorHandling;
   		}


	}

    return cOCTVC1_RC_OK;

ErrorHandling:

    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       GetNumLocalNetworkAdapters

Description:    Returns the number of local network adapters present.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 GetNumLocalNetworkAdapters(void)
{
    tOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS SystemGetLocalMacAddrParms;

    for (SystemGetLocalMacAddrParms.ulAdaptorIndex = 0; cOCT_TRUE; SystemGetLocalMacAddrParms.ulAdaptorIndex++)
    {
        if (cOCTVC1_RC_OK !=  OctVc1PktApiGetLocalMacAddr(&SystemGetLocalMacAddrParms))
        {
            break;
        }
    }
    
    return (SystemGetLocalMacAddrParms.ulAdaptorIndex);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       SelectLocalMacAddr

Description:    Lets the user select a MAC address from the list of available
                local MAC addresses.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 SelectLocalMacAddr(tOCT_UINT8 f_abyLocalMacAddr[6])
{
    tOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS SystemGetLocalMacAddrParms;
    tOCT_UINT32                               ulSelectedAdapterIndex;
    tOCT_UINT32                               ulNumAdapters;
    tOCT_UINT32                               ulResult;

    /*
     * Get the number of local network adapters present.
     */
    ulNumAdapters = GetNumLocalNetworkAdapters();
    if (0 == ulNumAdapters)
    {
        printf("No network adapters found\n\n");
        return cOCTVC1_PKT_API_RC_LOCAL_MAC_INDEX_NOT_FOUND;
    }

    if (1 < ulNumAdapters)
    {
        /*
         * List all local network adapters.
         */
        printf("Local network adapters:\n");
        for (SystemGetLocalMacAddrParms.ulAdaptorIndex = 0; cOCT_TRUE; SystemGetLocalMacAddrParms.ulAdaptorIndex++)
        {
            char szMacAddr[18];

            ulResult = OctVc1PktApiGetLocalMacAddr(&SystemGetLocalMacAddrParms);
            if (cOCTVC1_RC_OK != ulResult)
            {
                break;
            }

            OctSamplesMacAddr2Str(szMacAddr, SystemGetLocalMacAddrParms.abyLocalMac);
            printf(" [%u]: %s\n", SystemGetLocalMacAddrParms.ulAdaptorIndex, szMacAddr);
        }

        /*
         * Prompt the user to select an adapter.
         */
        while (cOCT_TRUE)
        {
            char szChoice[80];

            printf("Select an adapter [default: 0]: ");
            fgets(szChoice, 80, stdin);

            ulSelectedAdapterIndex = atoi(szChoice);
            if (ulSelectedAdapterIndex < SystemGetLocalMacAddrParms.ulAdaptorIndex)
            {
                break;
            }
        }
        fputc('\n', stdout);
    }
    else
    {
        /*
         * Only one adapter is present.
         */
        ulSelectedAdapterIndex = 0;
    }

    /*
     * Return the selected network adapter's MAC address.
     */
    SystemGetLocalMacAddrParms.ulAdaptorIndex = ulSelectedAdapterIndex;
    ulResult = OctVc1PktApiGetLocalMacAddr(&SystemGetLocalMacAddrParms);
    memcpy(f_abyLocalMacAddr, SystemGetLocalMacAddrParms.abyLocalMac, 6);

    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       SelectRemoteMacAddr

Description:    Lets the user select a MAC address from the list of available
                remote MAC addresses.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 SelectRemoteMacAddr(const tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                       tOCT_UINT8                         f_abyRemoteMacAddr[6])
{
    tOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS InstDiscoverDevParms = { 0 };
    tOCT_UINT32                             ulDeviceIdx;
    tOCT_UINT32                             ulSelectedDevIndex;
    tPOCTVC1_PKT_API_DEV_INFO               pSelectedDevInfo = NULL;
    tOCTSAMPLES_DEV_PORT_INFO				DevPortInfo = { { 0 } };
    tOCT_UINT32                             ulPortIndex;
    tOCT_UINT32                             ulSelectedPortIndex = 0;

    /*
     * Discover the Target devices reachable through the specified instance.
     */
    mOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS_DEF(&InstDiscoverDevParms);
    InstDiscoverDevParms.ulTimeoutMs = 2000;
	if( f_pPktApiInfo->fUseExternalTransport )
	{
		if( f_pPktApiInfo->OctPktExt.hTrans != NULL )
		{
			InstDiscoverDevParms.ahTransport[InstDiscoverDevParms.ulTransportCnt] = f_pPktApiInfo->OctPktExt.hTrans;
			InstDiscoverDevParms.ulTransportCnt++;
		}
		/*
		if( f_pPktApiInfo->OctPktXlExt.hTrans != NULL )
		{
			InstDiscoverDevParms.ahTransport[InstDiscoverDevParms.ulTransportCnt] = f_pPktApiInfo->OctPktXlExt.hTrans;
			InstDiscoverDevParms.ulTransportCnt++;
		}*/
	}
    OctVc1PktApiInstDiscoverDev(f_pPktApiInfo->pPktApiInst, &InstDiscoverDevParms);

    if (0 == InstDiscoverDevParms.ulDeviceCnt)
    {
        printf("No Target device found\n\n");
        return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
    }

    if (1 < InstDiscoverDevParms.ulDeviceCnt)
    {
        /*
         * List all Target devices.
         */
        printf("Target devices:\n");
        for (ulDeviceIdx = 0; ulDeviceIdx < InstDiscoverDevParms.ulDeviceCnt; ulDeviceIdx++)
        {
            tPOCTVC1_PKT_API_DEV_INFO pDevInfo = &InstDiscoverDevParms.aDeviceInfo[ulDeviceIdx];

            printf(" [%u]: Target %u\n", ulDeviceIdx, ulDeviceIdx + 1);
            for (ulPortIndex = 0; ulPortIndex < pDevInfo->ulPortCnt; ulPortIndex++)
            {
                if (cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH == pDevInfo->aPortInfo[ulPortIndex].ulPortType)
                {
                    if (pDevInfo->aPortInfo[ulPortIndex].fReachable)
                    {
                        char szMacAddr[18];

                        OctSamplesMacAddr2Str(szMacAddr, pDevInfo->aPortInfo[ulPortIndex].Type.Eth.abyMacAddr);
                        printf("  Port %u: %s\n", pDevInfo->aPortInfo[ulPortIndex].Type.Eth.ulPortId, szMacAddr);
                    }
                }
				else if( cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_TRANSPORT == pDevInfo->aPortInfo[ulPortIndex].ulPortType  )
				{
					/* Send some packet using various size to check alignment */
					if ( pDevInfo->aPortInfo[ulPortIndex].fReachable )
					{
                        printf("  Port %u: %s\n", ulPortIndex, pDevInfo->aPortInfo[ulPortIndex].Type.Transport.szDestinationAddr);
					}
				}
            }
        }

        /*
         * Prompt the user to select a Target device.
         */
        while (cOCT_TRUE)
        {
            char szChoice[80];

            printf("Select a device [default: 0]: ");
            fgets(szChoice, 80, stdin);

            ulSelectedDevIndex = atoi(szChoice);
            if (ulSelectedDevIndex < ulDeviceIdx)
            {
                break;
            }
        }
        fputc('\n', stdout);
    }
    else
    {
        /*
         * Only one Target device is present.
         */
        ulSelectedDevIndex = 0;
    }
    pSelectedDevInfo = &InstDiscoverDevParms.aDeviceInfo[ulSelectedDevIndex];

    /*
     * Retrieve the port information of the selected device.
     */
    for (ulPortIndex = 0; ulPortIndex < pSelectedDevInfo->ulPortCnt; ulPortIndex++)
    {
        if (cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH == pSelectedDevInfo->aPortInfo[ulPortIndex].ulPortType)
        {
            if (0 == pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Eth.ulPortId)
            {
                /* Ethernet port 0. */
                memcpy(DevPortInfo.abyPort0MacAddr, pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Eth.abyMacAddr, 6);
                DevPortInfo.fIsPort0Reachable = pSelectedDevInfo->aPortInfo[ulPortIndex].fReachable;
            }
            else if (1 == pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Eth.ulPortId)
            {
                /* Ethernet port 1. */
                memcpy(DevPortInfo.abyPort1MacAddr, pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Eth.abyMacAddr, 6);
                DevPortInfo.fIsPort1Reachable = pSelectedDevInfo->aPortInfo[ulPortIndex].fReachable;
            }
        }
		else if( cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_TRANSPORT == pSelectedDevInfo->aPortInfo[ulPortIndex].ulPortType  )
		{
            // memcpy(DevPortInfo.abyPort0MacAddr, pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Transport.szDestinationAddr, 6);
			
			OctSamplesStr2MacAddr( DevPortInfo.abyPort0MacAddr, (const char*)pSelectedDevInfo->aPortInfo[ulPortIndex].Type.Transport.szDestinationAddr );
            DevPortInfo.fIsPort0Reachable = pSelectedDevInfo->aPortInfo[ulPortIndex].fReachable;
		}
    }

    if (DevPortInfo.fIsPort0Reachable && DevPortInfo.fIsPort1Reachable)
    {
        char szMacAddr[18];

        /*
         * List all reachable ports.
         */
        printf("Two reachable ports were found:\n");
        OctSamplesMacAddr2Str(szMacAddr, DevPortInfo.abyPort0MacAddr);
        printf(" [0]: Port 0: %s\n", szMacAddr);
        OctSamplesMacAddr2Str(szMacAddr, DevPortInfo.abyPort1MacAddr);
        printf(" [1]: Port 1: %s\n", szMacAddr);

        /*
         * Prompt the user to select a port.
         */
        while (cOCT_TRUE)
        {
            char szChoice[80];
            
            printf("Select a port [default: 0]: ");
            fgets(szChoice, 80, stdin);
            
            ulSelectedPortIndex = atoi(szChoice);
            if (ulSelectedPortIndex < 2)
            {
                break;
            }
        }
        fputc('\n', stdout);
    }
    else if (DevPortInfo.fIsPort0Reachable)
    {
        /*
         * Only Ethernet port 0 is reachable.
         */
        ulSelectedPortIndex = 0;
    }
    else if (DevPortInfo.fIsPort1Reachable)
    {
        /*
         * Only Ethernet port 1 is reachable.
         */
        ulSelectedPortIndex = 1;
    }

    /*
     * Return the selected port's MAC address.
     */
    if (0 == ulSelectedPortIndex)
    {
        memcpy(f_abyRemoteMacAddr, DevPortInfo.abyPort0MacAddr, 6);
        f_pPktApiInfo->ulPktApiCnctPortIdx = 0;
    }
    else
    {
        memcpy(f_abyRemoteMacAddr, DevPortInfo.abyPort1MacAddr, 6);
        f_pPktApiInfo->ulPktApiCnctPortIdx = 1;
    }

    return cOCTVC1_RC_OK;
}

/***************************  PUBLIC FUNCTIONS  ******************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesSelectLocalMacAddr

Description:    Allows the user to select a local MAC address.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctSamplesSelectLocalMacAddr( tOCT_UINT8 f_abyLocalMacAddr[6] )
{
    return SelectLocalMacAddr(f_abyLocalMacAddr);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesDiscoverDevice

Description:    Retreives a list of Target devices.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesDiscoverDevice( tPOCTVC1_PKT_API_INST                 f_pPktApiInst,
                                         tPOCTSAMPLES_DISCOVER_DEVICE_PARMS f_pDeviceParms )
{
    tOCT_UINT32   ulResult = cOCTVC1_RC_OK;

    /*
     * Discover any valid devices available through the local Mac Address.
     */
    {
        tOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS InstDiscoverDevParms = { 0 };
        
        /*
         * Discover the Target devices reachable through the specified instance.
         */
        mOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS_DEF(&InstDiscoverDevParms);
        InstDiscoverDevParms.ulTimeoutMs = 2000;
        OctVc1PktApiInstDiscoverDev(f_pPktApiInst, &InstDiscoverDevParms);

        /* 
         * Copy the device information into the sample discover structure.
         */
        memcpy( f_pDeviceParms->aDeviceInfo, InstDiscoverDevParms.aDeviceInfo, sizeof(InstDiscoverDevParms.aDeviceInfo));
        f_pDeviceParms->ulDeviceCnt = InstDiscoverDevParms.ulDeviceCnt;

        if (0 == InstDiscoverDevParms.ulDeviceCnt)
        {
            printf("ERROR: No Target device found\n\n");
            return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
        }
    }
    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSession

Description:    Opens a packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesOpenPktApiSessionExtDef( tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo )
{
	memset( f_pPktApiInfo, 0, sizeof(*f_pPktApiInfo) );
	f_pPktApiInfo->fUseExternalTransport = cOCT_TRUE;
}

static tOCT_UINT32 OpenPktApiTransportExternal( tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
												tOCT_UINT8               f_abyLocalMac[6])
{
	tOCT_UINT32 ulRc = cOCTVC1_RC_OK;

	/*Open External ETH transports*/
	tOCTTRANSAPI_ETH_OPEN	EthOpen;	

	/* Trans ini t*/
	{
		tOCT_INT32						transRc;
		tOCTTRANSAPI_INIT_PARMS	TransInitParms;
		mOCTTRANSAPI_INIT_PARMS_DEF( &TransInitParms );

		transRc = OctTransApiInit( &TransInitParms );
		if( transRc != cOCTTRANSAPI_RC_ERROR_NONE )
		{
			printf( "\nERROR: OctTransApiInit -(%d)\n", transRc );
			return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
		}
	}

	/* OCTPKT (control)*/
	mOCTTRANSAPI_ETH_OPEN_DEF(&EthOpen);
	EthOpen.ulCtrlProtoType		= cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET;
	EthOpen.usEtherType			= cOCTPKT_HDR_ETHERTYPE;
	EthOpen.ulMaxDestination = 2;
	memcpy( EthOpen.MacAddress.abyMacAddress, f_abyLocalMac, 6 );			
	ulRc = OctTransApiEthOpen( NULL, &EthOpen, &f_pPktApiInfo->OctPktExt.hTrans );

	if(cOCTVC1_RC_OK == ulRc)
	{
		/*OCTPKT_XL (Data) */
		mOCTTRANSAPI_ETH_OPEN_DEF(&EthOpen);			
		EthOpen.usEtherType=cOCTPKT_HDRXL_ETHERTYPE;
		EthOpen.ulMaxDestination = 1;
		memcpy(EthOpen.MacAddress.abyMacAddress,f_abyLocalMac,6);
		ulRc = OctTransApiEthOpen(NULL,&EthOpen,&f_pPktApiInfo->OctPktXlExt.hTrans);
	}

	return ulRc;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSessionExt

Description:    Opens a packet API session.
				Allow to open 2 external connection( one OCTPKT and one OCTPKT_XL)

				ATTENTION : Must call OctSamplesOpenPktApiSessionExtDef() before

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesOpenPktApiSessionExt(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                           tOCT_UINT8                   f_abyLocalMacAddr[6],
                                           tOCT_UINT8                   f_abyRemoteMacAddr[6])
{
    tOCTVC1_PKT_API_SESS_OPEN_PARMS SessOpenParms;
    tOCT_UINT32                     ulResult;

    /*
     * Make sure a local MAC address has been specified.
     */
    if (0 == memcmp(f_abyLocalMacAddr, g_abyNullMacAddr, 6))
    {
        ulResult = SelectLocalMacAddr(f_abyLocalMacAddr);
        if (cOCTVC1_RC_OK != ulResult)
        {
            goto ErrorHandling;
        }
    }
	else
	{
		char szMacAddr[18];
		OctSamplesMacAddr2Str(szMacAddr, f_abyLocalMacAddr);
		printf("Local mac address: %s\n", szMacAddr );
	}


	if( f_pPktApiInfo->fUseExternalTransport )
	{
		/* Open Transport */
		ulResult = OpenPktApiTransportExternal( f_pPktApiInfo, f_abyLocalMacAddr );
	}



    /*
     * Initialize a packet API instance on the specified local MAC address.
     */
    ulResult = InitializePktApiInst(f_pPktApiInfo, f_abyLocalMacAddr);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Make sure a remote MAC address has been specified.
     */
    if (0 == memcmp(f_abyRemoteMacAddr, g_abyNullMacAddr, 6))
    {
        ulResult = SelectRemoteMacAddr(f_pPktApiInfo, f_abyRemoteMacAddr);
        if (cOCTVC1_RC_OK != ulResult)
        {
            goto ErrorHandling;
        }
    }
	else
	{
		char szMacAddr[18];
		OctSamplesMacAddr2Str(szMacAddr, f_abyRemoteMacAddr);
		printf("Remote mac address: %s\n", szMacAddr );
	}

    /*
     * Open a connection between the transport packet API instance and the Target device.
     */
    ulResult = OpenPktApiCnct(f_pPktApiInfo, f_abyRemoteMacAddr);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Open a packet API session to communicate with the MGW process running on Target.
     */
    mOCTVC1_PKT_API_SESS_OPEN_PARMS_DEF(&SessOpenParms);
    SessOpenParms.ulControlProcessFifoId = cOCTVC1_FIFO_ID_CONTROL;

    ulResult = OctVc1PktApiSessOpen( f_pPktApiInfo->pPktApiCnct, &SessOpenParms );
    if( cOCTVC1_RC_OK != ulResult )
    {
        goto ErrorHandling;
    }
    f_pPktApiInfo->pPktApiSess = SessOpenParms.pSession;

    return cOCTVC1_RC_OK;

ErrorHandling:
    OctSamplesClosePktApiSession(f_pPktApiInfo);

    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesClosePktApiSession

Description:    Closes a packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesClosePktApiSession(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo)
{
    tOCT_UINT32 ulResult	 = cOCTVC1_RC_OK;
    tOCT_UINT32 ulTempResult = cOCTVC1_RC_OK;

    /*
     * Close the packet API session.
     */
    if (NULL != f_pPktApiInfo->pPktApiSess)
    {
        tOCTVC1_PKT_API_SESS_CLOSE_PARMS SessCloseParms;

        mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF(&SessCloseParms);

        ulTempResult = OctVc1PktApiSessClose(f_pPktApiInfo->pPktApiSess, &SessCloseParms);
		ulResult = ( ulResult == cOCTVC1_RC_OK) ? ulTempResult: ulResult;
		if( ulTempResult == cOCTVC1_RC_OK )
		{
			f_pPktApiInfo->pPktApiSess = NULL;
		}
    }

    /*
     * Close the packet API connection.
     */
	if( f_pPktApiInfo->pPktApiCnctPktXl )
	{
		tOCTVC1_PKT_API_CNCT_CLOSE_PARMS CnctCloseParms;
        mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF(&CnctCloseParms);
		ulTempResult = OctVc1PktApiCnctClose( f_pPktApiInfo->pPktApiCnctPktXl, &CnctCloseParms );
		ulResult = ( ulResult == cOCTVC1_RC_OK) ? ulTempResult: ulResult;
		f_pPktApiInfo->pPktApiCnctPktXl = NULL;
	}
	if( f_pPktApiInfo->pPktApiCnct )
	{
		tOCTVC1_PKT_API_CNCT_CLOSE_PARMS CnctCloseParms;
        mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF(&CnctCloseParms);
		ulTempResult = OctVc1PktApiCnctClose( f_pPktApiInfo->pPktApiCnct, &CnctCloseParms );
		ulResult = ( ulResult == cOCTVC1_RC_OK) ? ulTempResult: ulResult;
		f_pPktApiInfo->pPktApiCnct = NULL;
	}

	if( f_pPktApiInfo->OctPktXlExt.hTransDest != NULL )
	{
		ulTempResult = OctTransApiDestinationRemove( f_pPktApiInfo->OctPktXlExt.hTransDest );
		ulResult = ( ulResult == cOCTVC1_RC_OK) ? ulTempResult: ulResult;
		f_pPktApiInfo->OctPktXlExt.hTransDest = NULL;
	}

	if( f_pPktApiInfo->OctPktExt.hTransDest != NULL )
	{
		ulTempResult = OctTransApiDestinationRemove( f_pPktApiInfo->OctPktExt.hTransDest );
		ulResult = ( ulResult == cOCTVC1_RC_OK) ? ulTempResult: ulResult;
		f_pPktApiInfo->OctPktExt.hTransDest = NULL;
	}


    /*
     * Close the packet API instance.
     */
    if (NULL != f_pPktApiInfo->pPktApiInst)
    {
        tOCTVC1_PKT_API_INST_TERM_PARMS InstTermParms;
        mOCTVC1_PKT_API_INST_TERM_PARMS_DEF(&InstTermParms);

        ulResult = OctVc1PktApiInstTerm(f_pPktApiInfo->pPktApiInst, &InstTermParms);
        if (cOCTVC1_RC_OK != ulResult)
        {
            goto ErrorHandling;
        }
        free(f_pPktApiInfo->pPktApiInst);
        f_pPktApiInfo->pPktApiInst = NULL;
    }

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesOpenPktApiSession

Description:    Opens a packet API session.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesOpenPktApiSession(tPOCTSAMPLES_PKT_API_INFO f_pPktApiInfo,
                                           tOCT_UINT8             f_abyLocalMacAddr[6],
                                           tOCT_UINT8             f_abyRemoteMacAddr[6])
{
	OctSamplesOpenPktApiSessionExtDef( f_pPktApiInfo );
	f_pPktApiInfo->fUseExternalTransport = cOCT_FALSE;

	return OctSamplesOpenPktApiSessionExt( f_pPktApiInfo, f_abyLocalMacAddr, f_abyRemoteMacAddr );
}
