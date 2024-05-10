/*
*############################################################################
*
*                   *** FXLynx Technologies Ltd. ***
*
*     The information contained in this file is the property of FXLynx
*     Technologies Ltd. Except as specifically authorized in writing by
*     FXLynx Technologies Ltd. The user of this file shall keep information
*     contained herein confidential and shall protect same in whole or in
*     part from disclosure and dissemination to third parties.
*
*     Without prior written consent of FXLynx Technologies Ltd. you may not
*     reproduce, represent, or download through any means, the information
 *     contained herein in any way or in any form.
*
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : main.c
 *
* Description : Main Program for bts
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/01/2015          Anand Kashikar    File Creation
*############################################################################
*/

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/types.h>
#include "l1Constants.h"
#include "logManager.h"
#include "ratSocketItf.h"

FILE *pIdCatcherFile = NULL;
time_t ltime;
struct tm * timeinfo;
extern tOCT_UINT32 currentDspImage;

#ifdef WGS_LICENSING
extern unsigned int wgsFileSystemLicenseInit();
#endif
extern uint8_t L1CReadConfigParams();
extern void destroy4gContext(void);
extern void deleteLteScanData();
extern void timerDestroy (void);
extern void destroySharedMemory();
extern int octasicBtsStop();
extern void deleteGsmLatchedUsers();
extern signed char destroyThreadsForGsmNativeApp();
extern fxLResult stopListenModeApplication();
extern unsigned int fillSibCfgParams();
extern tOCT_UINT8 isItPrimaryDsp();
extern void setNetworkDriverPriorityForLte(unsigned char setPriority);


int main(int argc, char **argv)
{
    int seedValue = 1;

    printf("############################################################################\n");
    printf("*\n");
    printf("*  2G/3G/4G SCANNER AND IDCATCHER for V_%.3f WITH MINOR VERSION V_%d \n", FXL_SOCKETINTERFACEAPI_VERSION,FXL_MINOR_VERSION);
    printf(("*\n"));
    printf(("*\n"));
    printf(("############################################################################\n"));
	signal(SIGPIPE , SIG_IGN);
	setNetworkDriverPriorityForLte(FALSE);

    // Perform initialization tasks required by the application.
    if(L1CReadConfigParams() == 0)
    {
        printf("\nParsing MAC Address from config file Failed with error \n");
        exit(1);
    }
    logManagerInit();

    /* Set the seed based on current time which will 
     * be used by random number generator function 
     */
    seedValue = (int) time(NULL);

    if(isItPrimaryDsp() == FALSE)
    {
        /* Change the seedValue if running for sec DSP */
        seedValue = seedValue + 1;
    }
    srand(seedValue);
#ifdef WGS_LICENSING
	assert(wgsFileSystemLicenseInit()==0);
#endif
    createSharedMemoryStoringIdLists();
    initializeConfigUeIdList(&configUeIdList);

    if(createAndWaitSocketServerInterface() != 0)
    {
    	 printf("External socket Creation Failed\n");
    	 exit(1);
    }

   fillSibCfgParams();
 
   externalSocketMsgHandler(); // Lock on to TCP Receive on main thread
   return 1;
} //end main


