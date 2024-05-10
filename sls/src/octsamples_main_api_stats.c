/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octsamples_main_api_stats.c

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

    Vocallo Main API statistics.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: 37428 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <string.h>

/* Vocallo API header files */
#include "../inc/octvc1/main/octvc1_main_api.h"

/* Vocallo samples' common header files */
#include "../inc/octsamples_main_api_stats.h"
#include "../inc/octsamples_string_utils.h"

/***************************  PUBLIC FUNCTIONS  ******************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintEthPortConfigInfo

Description:    Prints the current Ethernet ports configuration parameters.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintEthPortConfigInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
#ifdef cOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CID

    tOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CMD EthInfoPortConfigCmd;
    tOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_RSP EthInfoPortConfigRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS         CmdExecuteParms;
    char                                      szMacAddr[20];
    tOCT_UINT32                               ulResult;
    tOCT_UINT32                               i;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CMD_DEF(&EthInfoPortConfigCmd);
    mOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CMD_SWAP(&EthInfoPortConfigCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &EthInfoPortConfigCmd;
    CmdExecuteParms.pRsp           = &EthInfoPortConfigRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(EthInfoPortConfigRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_RSP_SWAP(&EthInfoPortConfigRsp);

    /*
     * Print the information.
     */
    printf("+-- ETHERNET PORT CONFIGURATION ----------------------------------------------\n");
    for (i = 0; i < 2; i++)
    {
        printf("| Ethernet Port %u\n", i);
        printf("|  Dynamic Configuration\n");
        OctSamplesMacAddr2Str(szMacAddr, EthInfoPortConfigRsp.aDynamic[i].MacAddress.abyMacAddress);
        printf("|   EthPortEnableFlag       : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulEthPortEnableFlag);
        printf("|   MacAddress              : %s\n", szMacAddr);		
        printf("|   AcceptAllMacFlag        : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulAcceptAllMacFlag);
        printf("|   AcceptUnicastFlag       : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulAcceptUnicastFlag);
        printf("|   AcceptMulticastFlag     : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulAcceptMulticastFlag);
        printf("|   AcceptBadCrcPktFlag     : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulAcceptBadCrcPktFlag);
        printf("|   AcceptLongPktFormatFlag : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulAcceptLongPktFormatFlag);
        printf("|   BroadcastForwardPort    : 0x%08x\n", EthInfoPortConfigRsp.aDynamic[i].ulBroadcastForwardPort);
        printf("|   MulticastForwardPort    : 0x%08x\n", EthInfoPortConfigRsp.aDynamic[i].ulMulticastForwardPort);
        printf("|   UnicastForwardPort      : 0x%08x\n", EthInfoPortConfigRsp.aDynamic[i].ulUnicastForwardPort);
        printf("|   RxMirrorForwardPor      : 0x%08x\n", EthInfoPortConfigRsp.aDynamic[i].ulRxMirrorForwardPort);
        printf("|   RestrictedApiFlag       : %u\n", EthInfoPortConfigRsp.aDynamic[i].ulRestrictedApiFlag);
        printf("|  Static Configuration\n");     
        printf("|   InterfaceType           : %u\n", EthInfoPortConfigRsp.aStatic[i].ulInterfaceType);        
        printf("|   Mode                    : %u\n", EthInfoPortConfigRsp.aStatic[i].ulMode);
        printf("|   Speed                   : %u\n", EthInfoPortConfigRsp.aStatic[i].ulSpeed);
        printf("|   FullDuplexFlag          : %u\n", EthInfoPortConfigRsp.aStatic[i].ulFullDuplexFlag);
        printf("|   PhyAddress              : %u\n", EthInfoPortConfigRsp.aStatic[i].ulPhyAddress);
        printf("|   PktQueuesByteSize       : %u\n", EthInfoPortConfigRsp.aStatic[i].ulPktQueuesByteSize);
    }
    printf("\n");

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
#else
	printf( "tOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintFileInfo

Description:    Prints the list of files included in the Vocallo file system.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintFileInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
	tOCT_UINT32 ulResult;
	tOCT_UINT32	ulTotalFile=0;

#if defined( cOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CID ) && defined( cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CID )
	tOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CMD    FileListCmd;
    tOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_RSP    FileListRsp;
	tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;	
	
	FileListRsp.SubObjectIdGet.ulGetMode = cOCTVC1_OBJECT_CURSOR_ENUM_SUB_OBJECT_FIRST;
	FileListRsp.SubObjectIdGet.ulSubObjectId = 0;

	printf("+-- FILE LIST INFORMATION -----------------------------------------------------\n");

	do
	{
		mOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CMD_DEF(&FileListCmd);

		FileListCmd.SubObjectIdGet.hObject = 0;
		FileListCmd.SubObjectIdGet.ulGetMode = FileListRsp.SubObjectIdGet.ulGetMode;
		FileListCmd.SubObjectIdGet.ulSubObjectId = FileListRsp.SubObjectIdGet.ulSubObjectId;

		mOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CMD_SWAP(&FileListCmd);
		/*
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);

		CmdExecuteParms.pCmd           = &FileListCmd;
		CmdExecuteParms.pRsp           = &FileListRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(FileListRsp);
		ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);

		if (cOCTVC1_RC_OK == ulResult)
		{
			tOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CMD    FileInfoCmd;
			tOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_RSP    FileInfoRsp;
			tOCT_UINT32 i = 0;

			mOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_RSP_SWAP(&FileListRsp);

			mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
			CmdExecuteParms.pCmd           = &FileInfoCmd;
			CmdExecuteParms.pRsp           = &FileInfoRsp;
			CmdExecuteParms.ulMaxRspLength = sizeof(FileInfoRsp);

			for(i = 0; i < FileListRsp.FileNameList.ulNumObject; i++)
			{
				/*
				 * Prepare command data.
				 */
				mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CMD_DEF(&FileInfoCmd);
				FileInfoCmd.hFile = FileListRsp.FileNameList.aName128Object32[i].ulObject32;
				mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CMD_SWAP(&FileInfoCmd);
				/*
				 * Execute the command.
				 */
				ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
				if (cOCTVC1_RC_OK != ulResult)
				{
					goto ErrorHandling;
				}
				/*
				 * Swap the command response.
				 */
				mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_RSP_SWAP(&FileInfoRsp);
				/*
				 * Print the information.
				 */
				printf("| File %u\n", ulTotalFile);
				printf("|   FileName   : %s\n", FileInfoRsp.szFileName);
				printf("|        Owner : 0x%08x\n", FileInfoRsp.ulHostOwnerFlag);
				printf("| Current Size : 0x%08x\n", FileInfoRsp.ulFileSize);
				printf("|     Max Size : 0x%08x\n", FileInfoRsp.ulMaxFileSize);
				ulTotalFile++;
			}
		}
	}while( (cOCTVC1_RC_OK == ulResult) && ( FileListRsp.SubObjectIdGet.ulGetMode != cOCTVC1_OBJECT_CURSOR_ENUM_DONE ) );

#else
	printf( "tOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CMD or cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CID are not supported");
	return cOCTVC1_RC_OK;
#endif

	printf("\n");
    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintFileSystemInfo

Description:    Prints usage information about the file system.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintFileSystemInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
#ifdef cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CID
    tOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CMD FileSystemInfoCmd;
    tOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_RSP FileSystemInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS     CmdExecuteParms;
    tOCT_UINT32                           ulResult;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CMD_DEF(&FileSystemInfoCmd);
    mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CMD_SWAP(&FileSystemInfoCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &FileSystemInfoCmd;
    CmdExecuteParms.pRsp           = &FileSystemInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(FileSystemInfoRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_RSP_SWAP(&FileSystemInfoRsp);

    /*
     * Print the information.
     */
    printf("+-- FILE SYSTEM INFORMATION --------------------------------------------------\n");
	printf("| szName         : %s\n", FileSystemInfoRsp.InfoParms.szName);
	printf("| hFileSystem    : 0x%x\n", FileSystemInfoRsp.InfoParms.hFileSystem);
    printf("| ulFileCnt      : %u\n", FileSystemInfoRsp.InfoParms.ulFileCnt);
	printf("| szHostRootPath : %s\n", FileSystemInfoRsp.InfoParms.szHostRootPathName);
    printf("\n");

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
#else
	printf( "tOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceInfo

Description:    Prints the current hardware configuration parameters.

Noter           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_TARGET_INFO_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
#ifdef cOCTVC1_MAIN_MSG_TARGET_INFO_CID
    tOCTVC1_MAIN_MSG_TARGET_INFO_CMD  DeviceInfoCmd;
    tOCTVC1_MAIN_MSG_TARGET_INFO_RSP  DeviceInfoRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS CmdExecuteParms;
    char                              szDeviceType[20];
    char *                            szResult;
    tOCT_UINT32                       ulResult;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_CMD_DEF(&DeviceInfoCmd);
    mOCTVC1_MAIN_MSG_TARGET_INFO_CMD_SWAP(&DeviceInfoCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &DeviceInfoCmd;
    CmdExecuteParms.pRsp           = &DeviceInfoRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(DeviceInfoRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_RSP_SWAP(&DeviceInfoRsp);

    switch(DeviceInfoRsp.ulTargetType)
    {
    case cOCTDEV_DEVICES_TYPE_ENUM_INVALID:
        sprintf(szDeviceType, "INVALID");
        break;
    case cOCTDEV_DEVICES_TYPE_ENUM_OCT1010:
        sprintf(szDeviceType, "OCT1010");
        break;
    case cOCTDEV_DEVICES_TYPE_ENUM_OCT2200:
        sprintf(szDeviceType, "OCT2200");
        break;
    }

    /*
     * Print the information.
     */
    printf("+-- DEVICE INFORMATION ------------------------------------------------------\n");
    printf("| DeviceType           : %s\n", szDeviceType);
    printf("| DeviceInfo :\n");
    szResult = strtok( (char *)DeviceInfoRsp.abyTargetInfo, ";" );
    while(NULL != szResult)
    {
        printf("| %s\n",szResult);
        szResult = strtok( NULL, ";" );
    }
    printf("| \n");

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;

#else
	printf( "tOCTVC1_MAIN_MSG_TARGET_INFO_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceInfoOpusCore

Description:    Prints information about each core in the device.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceInfoOpusCore(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
#ifdef cOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CID
    tOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CMD DeviceInfoOpusCoreCmd;
    tOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_RSP DeviceInfoOpusCoreRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS          CmdExecuteParms;
    tOCT_UINT32                                ulResult;
    tOCT_UINT32                                i;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CMD_DEF(&DeviceInfoOpusCoreCmd);
    mOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CMD_SWAP(&DeviceInfoOpusCoreCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &DeviceInfoOpusCoreCmd;
    CmdExecuteParms.pRsp           = &DeviceInfoOpusCoreRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(DeviceInfoOpusCoreRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_RSP_SWAP(&DeviceInfoOpusCoreRsp);

    /*
     * Print the information.
     */
    printf("+-- OPUS CORE INFORMATION -------------------------------------------------\n");
    for (i = 0; i < cOCTVC1_MAIN_MAX_CORE_NUMBER; i++)
    {
        printf("| Core %u\n", i);
		printf("|  Process 			: %u\n", DeviceInfoOpusCoreRsp.aCoreInfo[i].hProcess);
        printf("|  PhysicalCoreId   : %u\n", DeviceInfoOpusCoreRsp.aCoreInfo[i].ulPhysicalCoreId);
		printf("|  ProcessImageType : %u\n", DeviceInfoOpusCoreRsp.aCoreInfo[i].ulProcessImageType);
    }
    printf("\n");

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;

#else
	printf( "tOCTVC1_MAIN_MSG_TARGET_INFO_OPUS_CORE_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceStatusOpusCore

Description:    Prints status of each core in the device.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceStatusOpusCore(tPOCTVC1_PKT_API_SESS f_pPktApiSess)
{
#ifdef cOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CID
    tOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CMD DeviceStatusOpusCoreCmd;
    tOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_RSP DeviceStatusOpusCoreRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS            CmdExecuteParms;
    tOCT_UINT32                                  ulResult;
    tOCT_UINT32                                  i;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CMD_DEF(&DeviceStatusOpusCoreCmd);
    mOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CMD_SWAP(&DeviceStatusOpusCoreCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &DeviceStatusOpusCoreCmd;
    CmdExecuteParms.pRsp           = &DeviceStatusOpusCoreRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(DeviceStatusOpusCoreRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_RSP_SWAP(&DeviceStatusOpusCoreRsp);

    /*
     * Print the information.
     */
    printf("+-- OPUS CORE STATUS ------------------------------------------------------\n");
    for (i = 0; i < cOCTVC1_MAIN_MAX_CORE_NUMBER; i++)
    {
        printf("| Core %u\n", i);
        printf("|  CoreStatus             : %u\n", DeviceStatusOpusCoreRsp.aCoreStatus[i].ulCoreStatus);
        printf("|  ProgramCounter         : 0x%08x\n", DeviceStatusOpusCoreRsp.aCoreStatus[i].ulProgramCounter);
        printf("|  FailureMask            : 0x%08x\n", DeviceStatusOpusCoreRsp.aCoreStatus[i].ulFailureMask);
        printf("|  AccessViolationAddress : 0x%08x\n", DeviceStatusOpusCoreRsp.aCoreStatus[i].ulAccessViolationAddress);
    }
    printf("\n");

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
#else
	printf( "tOCTVC1_MAIN_MSG_TARGET_STATUS_OPUS_CORE_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintProcessCpuUsageInfo

Description:    Prints the current CPU usage of a virtual process or of a
                VSPMGR process and of its associated threads.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintProcessCpuUsageInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess,
                                                  tOCT_UINT32           f_hProcess)
{
#ifdef cOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CID
    tOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CMD ProcessInfoCpuUsageCmd;
    tOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_RSP ProcessInfoCpuUsageRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS           CmdExecuteParms;
    tOCT_UINT32                                 ulResult;

    /*
     * Prepare command data.
     */
    mOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CMD_DEF(&ProcessInfoCpuUsageCmd);
    ProcessInfoCpuUsageCmd.hProcess = f_hProcess;
    mOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CMD_SWAP(&ProcessInfoCpuUsageCmd);

    /*
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &ProcessInfoCpuUsageCmd;
    CmdExecuteParms.pRsp           = &ProcessInfoCpuUsageRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(ProcessInfoCpuUsageRsp);
    ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_RSP_SWAP(&ProcessInfoCpuUsageRsp);

    /*
     * Print the information.
     */
    printf("+-- PROCESS CPU USAGE INFORMATION (%08x) -------------------------------\n",
            ProcessInfoCpuUsageRsp.hProcess);
    printf("| AlarmThresholdHighPercent : %u\n", ProcessInfoCpuUsageRsp.ulAlarmThresholdHighPercent);
    printf("| AlarmThresholdLowPercent  : %u\n", ProcessInfoCpuUsageRsp.ulAlarmThresholdLowPercent);
	printf("| MonitorFlag               : %d\n", ProcessInfoCpuUsageRsp.ulMonitorEnableFlag);
    
    printf("\n");

#ifdef cOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CID
	{
		tOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CMD ProcessStatsCpuUsageCmd;
		tOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_RSP ProcessStatsCpuUsageRsp;

		/*
		 * Prepare command data.
		 */
		mOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CMD_DEF(&ProcessStatsCpuUsageCmd);
		ProcessStatsCpuUsageCmd.hProcess = f_hProcess;
		mOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CMD_SWAP(&ProcessStatsCpuUsageCmd);

		/*
		 * Execute the command.
		 */
		mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
		CmdExecuteParms.pCmd           = &ProcessStatsCpuUsageCmd;
		CmdExecuteParms.pRsp           = &ProcessStatsCpuUsageRsp;
		CmdExecuteParms.ulMaxRspLength = sizeof(ProcessStatsCpuUsageRsp);
		ulResult = OctVc1PktApiSessCmdExecute(f_pPktApiSess, &CmdExecuteParms);
		if (cOCTVC1_RC_OK != ulResult)
		{
			goto ErrorHandling;
		}

		/*
		 * Swap the command response.
		 */
		mOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_RSP_SWAP(&ProcessStatsCpuUsageRsp);

		/*
		 * Print the information.
		 */
		printf("+-- PROCESS CPU USAGE STATS (%08x) -------------------------------\n",
				ProcessStatsCpuUsageRsp.hProcess);
		printf("| ProcessCpuUsagePercent    : %u\n", ProcessStatsCpuUsageRsp.ulProcessCpuUsagePercent);
		printf("| ProcessCpuUsageMinPercent : %u\n", ProcessStatsCpuUsageRsp.ulProcessCpuUsageMinPercent);
		printf("| ProcessCpuUsageMaxPercent : %u\n", ProcessStatsCpuUsageRsp.ulProcessCpuUsageMaxPercent);
	    
		printf("\n");
	}
#endif /* tOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CMD */

    return cOCTVC1_RC_OK;

ErrorHandling:
    return ulResult;
#else
	printf( "tOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CMD not supported\n");
	return cOCTVC1_RC_OK;
#endif

}

