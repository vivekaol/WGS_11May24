/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octsamples_main_api_stats.h

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

    Main API statistics.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: 29379 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTSAMPLES_MAIN_API_STATS_H__
#define __OCTSAMPLES_MAIN_API_STATS_H__

#include "octvc1/main/octvc1_main_api.h"
#include "octvc1/main/octvc1_main_default.h"
#include "octvc1/main/octvc1_main_api_swap.h"
#include "octvc1/pkt_api/octvc1_pkt_api.h"
#include "octvc1/pkt_api/octvc1_pkt_api_default.h"

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

/***************************  FUNCTION PROTOTYPES  ***************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintEthPortConfigInfo

Description:    Prints the current Ethernet ports configuration parameters.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_ETH_INFO_PORT_CONFIG_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintEthPortConfigInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintFileInfo

Description:    Prints the list of files included in the Vocallo file system.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintFileInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintFileSystemInfo

Description:    Prints usage information about the file system.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintFileSystemInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess);



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceInfo

Description:    Prints the current hardware configuration parameters.

Noter           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_DEVICE_INFO_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess);


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceInfoOpusCore

Description:    Prints information about each core in the device.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_DEVICE_INFO_OPUS_CORE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceInfoOpusCore(tPOCTVC1_PKT_API_SESS f_pPktApiSess);


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintDeviceStatusOpusCore

Description:    Prints status of each core in the device.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_DEVICE_STATUS_OPUS_CORE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintDeviceStatusOpusCore(tPOCTVC1_PKT_API_SESS f_pPktApiSess);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesPrintProcessCpuUsageInfo

Description:    Prints the current CPU usage of a virtual process or of a
                VSPMGR process and of its associated threads.

Note:           See the Main API documentation for the
                cOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CID command.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OctSamplesPrintProcessCpuUsageInfo(tPOCTVC1_PKT_API_SESS f_pPktApiSess,
                                                  tOCT_UINT32           f_hProcess);

#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

#endif /* __OctSamples_MAIN_API_STATS_H__ */

