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
 * File Name   : ratSocketItf.c
 *
 * Description : External Socket interface handler file
 *
 * History     :
 *
 * Date                                  Author                     Details
 * ---------------------------------------------------------------------------
 * 25/11/2014          				  Anand Kashikar			   Initial File Creation
 *############################################################################
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <sys/select.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <sched.h>
#include "oct_l1cIoApi.h"
#include "oct_l1cIoInit.h"
#include "logManager.h"
#include "ratSocketItf.h"
#include "fxLSocketInterfaceApi.h"
#include "userManager.h"
#include "cleanChannelSelectionManager.h"
#include "transactionMemoryManager.h"
#include "l1InterfaceManager.h"
#include "rtsTxMsgHandler.h"
#include "dataIndMsgHandler.h"
#ifdef WGS_LICENSING
#include "octvc1_wgs_lic.h"
#endif
#ifdef FEA_GPRS
#include "gprs.h"
#endif

#include "umtsCfg.h"
#include "cmnDs.h"
#include "cmnPf.h"
#include "cmnDebug.h"
#include "lteL1Defs.h"
#include "rawSocketApi.h"
#include "lteLayer1IfManager.h"
#include "lteAsn1IntfcHandler.h"
#include "lteMacIntfcHandler.h"
#include "lteUserManager.h"
#include "lteRrcIntfcHandler.h"
#include "linkedlist.h"
#include "slsDecode2g.h"
#include "feaConfig.h"
#include "sms.h"
#include "lteRrcMain.h"
#include "clContext.h"
#include "errorCode.h"
#include "l1capi_datastruct.h"
#include "oct_l1cIoApi.h"
#include "obm.h"
#include "time.h"
#include "gsmCommon.h"
#include "sysInfo.h"

#ifdef FXL_BOARD_STATUS
#include "pthread.h"
pthread_t gBoardMonitorThreadId;
pthread_attr_t gBoardMonitorThreadAttr;
fxLObmBatteryStatusInd gBatteryStatusInd;
#endif

#ifdef OBM_BATTERY_STATUS
fxLObmBatteryStatusRsp gBatteryStatusRsp;
#endif

#ifdef OBM_TEMPERATURE_STATUS
fxLObmTemperatureStatusRsp gTemperatureStatusRsp;
#endif

unsigned int numberOfDsp = 0;
int antennaType = -1;

#define SHARED_MEM_SIZE_TO_STORE_IDLIST 1024 * 2
#define SET_GSM_BAND_850 0x01
#define SET_GSM_BAND_900 0x02
#define SET_GSM_BAND_1800 0x04
#define SET_GSM_BAND_1900 0x08
#define SET_GSM_BAND_R900 0x10
#define SET_GSM_BAND_E900 0x20
#define SET_GSM_BAND_450 0x40
pthread_t lteL1MsgHandlerThread, lteTimerThread, lteRrcIndThread, gsmDataIndThread, rlcDataIndThread, llcDataIndThread;
int exitRatListenMode = 0;
int exitRatBassMode = 0;
int exitLteApp = FALSE;
int changeEarfcn = FALSE;
pthread_t ratListenModeThreadId;
pthread_t ratBassModeThreadId;
oneBinState currentOneBinState = ONEBIN_STATE_IDLE;
uint8 stopCmdBuf[128];
void checkAndSetOnBinState(void);
extern unsigned char boardDspType;
extern gsm_trx *trx_g;
extern tOCTVC1_SUB_OBJECT_ID bcchBufferCellId;
extern int si1Cell;
extern int si2Cell;
extern int si2qCell;
extern int si2bisCell;
extern int si2terCell;
extern int si3Cell;
extern int si4Cell;
extern L1CAPI_Cell_Reconfig_Request gCellReconfigReq;
extern pthread_mutex_t mutexLteBlackListQ;
extern uint8 checkDefaultconfigOfList();
extern void handle4gScSibPageRetransmitTimeoutRrcThrd(tcbTimer_t *pTimer, void *blUsr);

extern void pushPagingReqToPageQ(blackListedUserInfo *info);
extern void blacklistUserInfoTimerCbFunction(tcbTimer_t *tmr, void *infoPtr);
extern int octasicBtsInit();
extern int octasicBtsStop();
extern int GsmTrxModifyRf(tOCT_UINT32 TxAttenuationInDb);
extern int GsmTrxResetDigitalScaling(void);
extern void configureWnmParameters(fxL2gListenModeConfigureBandsCmd *cmd);
extern fxLResult stopListenModeApplication();
extern void *ratListenMode(void *nothing);
extern void *ratBassMode(void *nothing);
extern void *l1MsgHandler(void *nothing);
extern void deleteGsmLatchedUsers();
extern unsigned int getNumOfGsmUeLatched(void);
extern unsigned int getAllRegisteredUesInGsm(void);
extern fxL3gListenModeSystemInfoInd g3gListenModeSysInfo;
volatile int clientFd = -1;
char clientIP[16];
int serverFd = -1;
tOCT_UINT8 clientMsgBuf[EXTERNAL_MESSAGE_SIZE] = {0};
static tOCT_UINT8 msgBuf[EXTERNAL_MESSAGE_SIZE] = {0};
extern pthread_mutex_t mutexPagingQ;
extern pthread_mutex_t mutexTransactionQ;
extern pthread_mutex_t mutexUserMgr;
extern pthread_mutex_t mutexGsmChannelMgr;
extern pthread_mutex_t mutexBlacklistUserQ;
extern pthread_cond_t conddataInd;
extern pthread_mutex_t mutexdataInd;
// extern pthread_cond_t      condTimerTickInd  ;
// extern pthread_mutex_t     mutexTimerTickInd ;
extern eLteBw lteSelectedBandwidth;
#ifdef FEA_GPRS
extern pthread_cond_t condRlcInd;
extern pthread_mutex_t mutexRlcInd;
extern pthread_cond_t condLlcInd;
extern pthread_mutex_t mutexLlcInd;
#endif
elteDupMode lteDuplxMode;
L1CAPI_Cell_Delete_Request gCellDeleteReq;
tOCT_UINT32 currentDspImage = 0xFF;
static int realNwTac = 0;
fxL4gConfigureIdCatcherParamsCmd lastLteIdCatcherConfigCmd;
extern int exitGsmAppThreads;
fxLTxRxAntennaId txAntennaIdPri = FXL_TX_RX_ANTENNA_ID_0;
fxLTxRxAntennaId rxAntennaIdPri = FXL_TX_RX_ANTENNA_ID_0;
fxLTxRxAntennaId txAntennaIdSec = FXL_TX_RX_ANTENNA_ID_0;
fxLTxRxAntennaId rxAntennaIdSec = FXL_TX_RX_ANTENNA_ID_0;

fxLScanType scanMode = FXL_SCAN_TYPE_EXHAUSTIVE;

#ifdef CELL_ANTENNA_CHANGE
void configureCellAntennaPA(char dspType, int band, char mode);
#endif
uint8 reInitialiseGsmScanData(fxL2gListenModeConfigureBandsCmd *cmd);
void getRssiGpsCordinatesCmdHandler(tOCT_UINT8 *inMsgBuf);
void handshakeMsgHandler(tOCT_UINT8 *inMsgBuf);
void configureIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf, unsigned int is3GAutoCfg);
void deleteEntryInIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf);
void resetIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf);
void enableGpsCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenModePriorityScanHandler(unsigned char *inMsgBuf);
void configureBasestationParamsCmdHandler(tOCT_UINT8 *inMsgBuf);
void startBasestationCmdHandler(tOCT_UINT8 *inMsgBuf);
void gsmRfModifyCmdHandler(tOCT_UINT8 *inMsgBuf);
#ifdef FEA_2G_DYNAMIC_SYS_INFO_CONFIG
void gsmSysInfoModifyCmdHandler(tOCT_UINT8 *inMsgBuf);
#endif
void getBlockedCallCounterCmdHandler(tOCT_UINT8 *inMsgBuf);
#ifdef FEA_SILENT_CALL
void startSilentCallCmdHandler(tOCT_UINT8 *inMsgBuf);
void modifyUeTxPowerCmdHandler(tOCT_UINT8 *inMsgBuf);
void endSilentCallCmdHandler(tOCT_UINT8 *inMsgBuf);
void silentCallDedSysInfoModifyCmd(tOCT_UINT8 *inMsgBuf);
extern void periodicTimerexpiry(tcbTimer_t *tmr, void *infoPtr);
#endif
#ifdef FEA_MT_SMS
extern void buildCpData(tOCT_UINT8 *outPtr, char *smsMsg, char *moMsisdn);
void sendIndividualSmsCmdHandler(tOCT_UINT8 *inMsgBuf);
void sendBroadcastSmsCmdHandler(tOCT_UINT8 *inMsgBuf);
#endif
void redirectTo2gCellCmdHandler(tOCT_UINT8 *inMsgBuf);
void getPhyChannelsUsageStatusCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenModeConfigureBandsCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenModeStartScanCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenModeStopScanCmdHandler(tOCT_UINT8 *inMsgBuf);
void bootL1CmdHandler(tOCT_UINT8 *inMsgBuf);
void stop2gIdcatcherCmdHandler(tOCT_UINT8 *inMsgBuf);
void configureGsmFreqForSelectiveScanCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenMode4gConfigureBandsCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenMode4gStartScanCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenMode4gStopScanCmdHandler(tOCT_UINT8 *inMsgBuf);
void listenModeConfigHandler(unsigned char *inMsgBuf);
void listenModeStartStopHandler(unsigned char *inMsgBuf);
void umtsConfigureIdCatcherParams(unsigned char *inMsgBuf);
void umtsStartIdCatcher(unsigned char *inMsgBuf);
void umtsStopIdCatcher(unsigned char *inMsgBuf);
void umtsAutoConfig(unsigned char *inMsgBuf);
void umtsAutoConfigStop(unsigned char *inMsgBuf);
void umtsGetNumOfUeWithinRange(unsigned char *inMsgBuf);
void ratGetNumOfUeWithinRange(unsigned char *inMsgBuf);
void initializeSystemInformationInd(void);
void send3gListenModeScanCompInd(unsigned int result);
void autoBootL1Image(void);
void sendListenModeSysInfoInd(void);
fxLResult createAndStart3gIdCatcherThread(void);
fxLResult stop3gIdCatcherThread(void);
// void umtsConfigureIdentityList (unsigned char* inMsgBuf);
extern void configureRrcIdentityList(fxLConfigureIdentityListCmd *pIdentityList);
extern void configureListenMode(fxL3gListenModeConfigureBandsCmd *cmd);
extern void configureUmtsIdCatcherParameters(fxL3gConfigureIdCatcherParamsCmd *pIdCatcherParams);
extern void autoConfigureListenMode(fxL3gAutoConfigCmd *cmd);
void autoConfigureRrcIdentityList(fxL3gAutoConfigCmd *pIdentityList);
extern void sendSystemInfoUpdateRsp(unsigned char success);
extern unsigned int getNumOfUeLatched(void);
extern void *umtsIdCatcher(void *nothing);
extern int LteCellModifyRf(int txAttnDb);
extern int lteEnodebConfig(lteRfConfig *rfConfig);
extern void destroy4gContext(void);
extern void stopLteScForAllBlUser(void);
extern void *timerTickHandler(void *nothing);
extern fxLResult configureGsmFreqForSelectiveScan(fxL2gListenModeConfigureSelectiveFreqCmd *cmd);
extern fxLResult configureLteFreqForSelectiveScan(fxL4gListenModeConfigureSelectiveFreqCmd *cmd);
extern void buildAndSendPhyStopReq();
extern uint8 searchLteScanDataToFindAutoConfigParams(fxL4gConfigureIdCatcherParamsCmd *lteParams);
extern void deleteLteScanData();
extern void setNetworkDriverPriorityForLte(unsigned char setPriority);
void lteConfigureIdCatcherParamsHandler(tOCT_UINT8 *inMsgBuf);
void lteStartIdCatcherHandler(tOCT_UINT8 *inMsgBuf);
void lteStopIdCatcherHandler(tOCT_UINT8 *inMsgBuf);
void configure4gWnmParameters(fxL4gListenModeConfigureBandsCmd *cmd);
void alertBlacklist(tOCT_UINT8 *inMsgBuf);
#ifdef FEA_VOICE_CALL_TO_TARGET
void setMoMsisdnForTargetVoiceCall(tOCT_UINT8 *inMsgBuf);
#endif
void configureLteFreqForSelectiveScanCmdHandler(tOCT_UINT8 *inMsgBuf);
uint32 reInitialiseLteScanData(fxL4gListenModeConfigureBandsCmd *cmd);
void searchAndUpdateIdDbForDuplicateEntries(fxLConfigureIdentityListCmd *cmd, tOCT_UINT8 *sharedMemPtr);
void lteStartSilentCallCommandHandler(uint8 *inMsgBuf);
void lteStopSilentCallCommandHandler(uint8 *inMsgBuf);
void lteRfModifyCmdHandler(tOCT_UINT8 *inMsgBuf);

#ifdef WGS_LICENSING
extern unsigned char checkWgsFeatureLicense(tOCT_UINT32 ulLicenseId);
#endif

#ifdef FXL_3G_TX_JAMMER
void umtsStartTxJammer(unsigned char *inMsgBuf);
void umtsStopTxJammer(unsigned char *inMsgBuf);
void *umtsTxJammer(void *pJammerParams);
pthread_t umtsTxJammerThreadId;
int exitUmtsTxJammer = 0;
extern jammerPscInfo jammer3gPsc;
#endif // FXL_3G_TX_JAMMER

#ifdef FXL_4G_TX_JAMMER
void lteStartTxJammer(unsigned char *inMsgBuf);
void lteStopTxJammer(unsigned char *inMsgBuf);
void *lteTxJammer(void *pEarfcn);
extern uint8 searchLteScanDataToFindJammerConfigParams(fxL4gConfigureIdCatcherParamsCmd *lteParams);
pthread_t lteTxJammerThreadId;
int exitLteTxJammer = 0;
extern int lteJamCellFound;
extern int lteJamThreadsCreated;
#endif // FXL_4G_TX_JAMMER

void lteBlUeRedirectCmdHandler(uint8 *inMsgBuf);
void updateAndBuildRrcConRelWithRedirect(int ueIndex,
                                         fxLRedirectionFrom4gType redirectionType,
                                         fxLRedirectionFrom4gInfo redirectionInfo);
int getLteUeIndxFromImsi(char *imsi);

AutoConfigCfg gAutoConfigCfg;
extern UmtsConfigControlBlock gUmtsConfig;
pthread_attr_t gListenModeAttr;
pthread_t gUmtsIdCatcherThreadId;
pthread_attr_t gUmtsIdCatcherAttr;
pthread_attr_t gLteIdCatcherAttr;
pthread_t gGpsMonitorThreadId;
pthread_attr_t gGpsMonitorAttr;
extern pthread_t gL1RcvThreadId;
int exitUmtsL1RcvThread = 0;
extern pthread_attr_t gL1RcvThreadAttr;
extern pthread_cond_t lteCondTimerTickInd;
extern pthread_mutex_t lteMutexTimerTickInd;
extern pthread_cond_t condlteRrcInd;
extern pthread_mutex_t mutexlteRrcInd;
extern uint16 LTE_PHYSICAL_CELL_ID_VALUE;
unsigned int bootL1InProgress;
static uint8 bandMap = 0;
static uint8 ltebandMap = 0;
/* OBM Integration */
extern void initializeObm(void);
extern tPOBM_COMMAND_DESCRIPTOR g_Commands[33];
fxLGpsLocation idCatcherGpsLoc;
fxLGpsFixType idCatcherGpsFix;
extern int optreset;
uint8 lteSilentCallStarted = FALSE;
uint8 lteIdCatcherRunning = 0;
#ifdef FEA_MT_SMS
tOCT_UINT8 mtBroadcastSmsL3Pdu[SMS_CP_DATA_MAX_LENGTH];
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET
extern callContext targetVoiceCallCntxt;
#endif

#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
tOCT_UINT8 sendSmsDuringRegistrationL3Pdu[SMS_CP_DATA_MAX_LENGTH];
#endif

int gsmRxGainInDb = 70;
int gsmTxAttenuationInDb = 0;
#ifdef FEA_REJECT_CAUSE_CONTROL
unsigned int gsmDefaultWLRejectCause;
#endif /* FEA_REJECT_CAUSE_CONTROL */
tOCT_UINT8 checkForInactive2gBLUsers = FALSE;
ScanResult gScanResult = {0};
int scanNotRequired = 0;
int idCatcherLteBand;
int idCatcherLteEarfcn;
int idCatcherLteWlRedirEarfcn;
unsigned int pilot_boost_enabled = 0;
int gpsStarted = 0;

#ifdef CELL_ANTENNA_CHANGE
FILE *pBandFreqFile;
#endif

extern volatile signed char noOfAllocatedLogicalChannels;
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
extern volatile signed char noOfAllocatedFullTrafficChannels;
extern volatile signed char noOfAllocatedHalfTrafficChannels;
#endif
#ifdef FEA_GPRS
extern volatile signed char noOfAllocatedPdtchChannels;
#endif
extern listNode *headForBlacklistedUserQ;
extern pthread_mutex_t mutexBlacklistUserQ;
extern unsigned int modemSetupRequired;
extern unsigned int isCellSetupRequired;
extern fxLDspType dspType;
extern uint8 lteRrcRedirectFlag;
unsigned int minRachTaValue;
unsigned int maxRachTaValue;
extern uint8 lteRrcPrmRedirectFlag;
extern tOCT_UINT8 maxSdcchChannel;
extern tOCT_UINT8 maxTchfChannel;
extern tOCT_UINT8 maxTchhChannel;
extern tOCT_UINT8 tchSilentCallUnderProgress;
extern tOCT_UINT8 cellBarDuringTchSilentCall;
extern tOCT_UINT8 maxPdtchChannel;
extern tOCT_UINT8 logicalChannels[MAX_TS][MAX_SUBCHAN_TIMESLOT];

uint8 lteRelUeFlag = FALSE;

#ifdef FEA_SILENT_CALL
extern tOCT_UINT8 si5Buf[GSM_MACBLOCK_LEN - 4];
#endif

extern LteRrcMeasurementControlData gLteRrcMeasData;
extern asnLteNeighborConfig gAsnLteNeighConfigData;

#ifdef FEA_PICSIX_CHANGE
fxLCurrentTask runningTask;
tcbTimer_t systemStatusTimer;
int send4gStatusInd;
#define SYSTEM_STATUS_TIMEOUT_FOR_4G 9000
#define SYSTEM_STATUS_TIMEOUT_FOR_3G 900
#define SYSTEM_STATUS_TIMEOUT_FOR_2G 11000
#endif

tOCT_UINT8 isItPrimaryDsp()
{
    logPrint(LOG_ERR, "Board DSP Type = %d \n", boardDspType);
    if (boardDspType == 0)
        return TRUE;
    else
        return FALSE;
}

sint8 createThreadsForGsmNativeApp()
{
    deleteAllUsers();
    deleteAllBlacklistUsers();
    destroy2gContext();
    createAndInit2gContext();

    pthread_mutex_init(&mutexPagingQ, NULL);
    pthread_mutex_init(&mutexTransactionQ, NULL);
    pthread_mutex_init(&mutexUserMgr, NULL);
    pthread_mutex_init(&mutexGsmChannelMgr, NULL);
    pthread_mutex_init(&mutexBlacklistUserQ, NULL);
    pthread_mutex_init(&mutexdataInd, NULL);
    pthread_cond_init(&conddataInd, NULL);
    if (pthread_create(&gsmDataIndThread, NULL, dataIndMsgHandler, NULL))
    {
        logPrint(LOG_ERR, "DataInd Thread creation failed");
        return -1;
    }

#if 0
	pthread_mutex_init(&mutexTimerTickInd, NULL);
	pthread_cond_init(&condTimerTickInd , NULL);
    // Create receiver thread for handling timer-Tick.
    if(pthread_create(&gsmTimerTickThread, NULL, timerTickHandler,NULL) )
    {
   	 	logPrint(LOG_ERR , "Timer-Tick Handler Thread creation failed");
        return -1;
    }
#endif
#ifdef FEA_GPRS
    pthread_mutex_init(&mutexRlcInd, NULL);
    pthread_cond_init(&condRlcInd, NULL);
    if (pthread_create(&rlcDataIndThread, NULL, rlcIndMsgHandler, NULL))
    {
        logPrint(LOG_ERR, "GPRS Thread creation failed");
        return -1;
    }

    pthread_mutex_init(&mutexLlcInd, NULL);
    pthread_cond_init(&condLlcInd, NULL);
    if (pthread_create(&llcDataIndThread, NULL, llcIndMsgHandler, NULL))
    {
        logPrint(LOG_ERR, "LLC Thread creation failed");
        return -1;
    }
#endif

    return 0;
}

sint8 destroyThreadsForGsmNativeApp()
{
    sint8 ret = 0;

#if 0
    if(pthread_cancel(gsmDataIndThread) )
    {
    	logPrint(LOG_ERR , "DataInd Thread cancellation failed");
    	ret = -1;
    }
    else
    {
        pthread_detach(gsmDataIndThread);
    }
#endif

    memset(&gsmDataIndThread, 0, sizeof(gsmDataIndThread));

#if 0
    if(pthread_cancel(gsmTimerTickThread))
    {
    	logPrint(LOG_ERR , "Timer-Tick Thread cancellation failed");
    	ret = -1;
    }
    else
    {
		pthread_detach(gsmTimerTickThread);
    }

	memset (&gsmTimerTickThread, 0, sizeof (gsmTimerTickThread));
#endif

#ifdef FEA_GPRS
    memset(&rlcDataIndThread, 0, sizeof(rlcDataIndThread));
    memset(&llcDataIndThread, 0, sizeof(llcDataIndThread));
    pthread_cond_destroy(&condRlcInd);
    pthread_mutex_destroy(&mutexRlcInd);
    pthread_cond_destroy(&condLlcInd);
    pthread_mutex_destroy(&mutexLlcInd);
#endif

    pthread_mutex_destroy(&mutexPagingQ);
    pthread_mutex_destroy(&mutexTransactionQ);
    pthread_mutex_destroy(&mutexUserMgr);
    pthread_mutex_destroy(&mutexGsmChannelMgr);
    pthread_mutex_destroy(&mutexBlacklistUserQ);
    pthread_cond_destroy(&conddataInd);
    pthread_mutex_destroy(&mutexdataInd);
    //	pthread_cond_destroy(&condTimerTickInd);
    //	pthread_mutex_destroy(&mutexTimerTickInd);

    destroy2gContext();
    return ret;
}

sint8 createAndStartBassModeThread()
{
    if (pthread_create(&ratBassModeThreadId, NULL, ratBassMode, NULL))
    {
        logPrint(LOG_ERR, "Bass Mode Thread creation failed");
        return -1;
    }
    sleep(1);
    return 0;
}

sint8 destroyBassModeThread()
{
    sint8 ret = 0;

    exitRatBassMode = 1;

    while (1)
    {
        if (pthread_tryjoin_np(ratBassModeThreadId, NULL))
        {
            // logPrint(LOG_ERR , "Bass Mode Thread join failed");
        }
        else
            break;
    }

    memset(&ratBassModeThreadId, 0, sizeof(ratBassModeThreadId));
    return ret;
}

sint8 createAndStartListenModeThread()
{
    struct sched_param params;
    int coreId = 0;

    setNetworkDriverPriorityForLte(TRUE);

    if (pthread_attr_init(&gListenModeAttr))
    {
        logPrint(LOG_ERR, "Listen Mode Thread Init Atrribute set failed");
        return -1;
    }

    if (pthread_attr_setstacksize(&gListenModeAttr, 100 * 1024) < 0)
    {
        logPrint(LOG_ERR, "Listen Mode Thread Atrribute set failed");
        return -1;
    }

    if (pthread_create(&ratListenModeThreadId, &gListenModeAttr, ratListenMode, NULL))
    {
        logPrint(LOG_ERR, "Listen Mode Thread creation failed");
        return -1;
    }

    params.sched_priority = 90;
    pthread_setschedparam(ratListenModeThreadId, SCHED_FIFO, &params);

    if (TRUE == isItPrimaryDsp())
    {
        coreId = 1;
    }
    else
    {
        coreId = 2;
    }

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(coreId, &cpuset);
    if (pthread_setaffinity_np(ratListenModeThreadId, sizeof(cpu_set_t), &cpuset))
    {

        logPrint(LOG_ERR, "WARNING Listen Mode SetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d ,	%s \n", coreId, errno, strerror(errno));
        printf("WARNING Listen Mode SetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d , %s \n", coreId, errno, strerror(errno));

        if (pthread_getaffinity_np(ratListenModeThreadId, sizeof(cpu_set_t), &cpuset))
        {
            logPrint(LOG_ERR, "WARNING Listen Mode GetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d ,  %s \n", coreId, errno, strerror(errno));
            printf("WARNING Listen Mode GetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d , %s \n", coreId, errno, strerror(errno));
        }
        else
        {
            logPrint(LOG_DEBUG, "Listen Mode L1 Interface Thread affinity details : \n");
            printf("Listen Mode L1 Interface Thread affinity details : \n");
            int j = 0;
            for (j = 0; j < CPU_SETSIZE; j++)
            {
                if (CPU_ISSET(j, &cpuset))
                {
                    logPrint(LOG_DEBUG, "Listen Mode CPU-%d \n", j);
                    printf("Listen Mode CPU-%d \n", j);
                }
            }
        }
    }

    sleep(1);
    return 0;
}

sint8 destroyListenModeThread()
{
    sint8 ret = 0;

    exitRatListenMode = 1;

    while (1)
    {
        if (pthread_tryjoin_np(ratListenModeThreadId, NULL))
        {
            // logPrint(LOG_ERR , "Listen Mode Thread join failed");
        }
        else
            break;
    }

#if 0
    if(pthread_cancel(ratListenModeThreadId) )
    {
    	logPrint(LOG_ERR , "Listen Mode Thread cancellation failed");
    	ret = -1;
    }
    else
    {
    	pthread_detach(ratListenModeThreadId);
    }
#endif

    memset(&ratListenModeThreadId, 0, sizeof(ratListenModeThreadId));

    return ret;
}

int setNonBlockingSocket(int fd)
{
    return fcntl(fd, F_SETFL, O_NONBLOCK);
}
tOCT_UINT8 createAndWaitSocketServerInterface(void)
{
    int clientSockLen;
    struct sockaddr_in server, client;
    int enable = 1;

    // Create TCP socket
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1)
    {
        logPrint(LOG_ERR, "Could not create socket for external interface \n");
    }

    /* Reuse the address */
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    {
        logPrint(LOG_ERR, "Error : failed to set socket option for reuse\n");
        return 1;
    }

    /* Set Send Buffer Size */
    enable = 1024 * 32;
    if (setsockopt(serverFd, SOL_SOCKET, SO_SNDBUF, &enable, sizeof(int)) < 0)
    {
        logPrint(LOG_ERR, "Error : failed to set socket option for send buffer size\n");
        return 1;
    }

    /* Set Recv Buffer Size */
    enable = 1024 * 32;
    if (setsockopt(serverFd, SOL_SOCKET, SO_RCVBUF, &enable, sizeof(int)) < 0)
    {
        logPrint(LOG_ERR, "Error : failed to set socket option for recv buffer size\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    if (isItPrimaryDsp() == TRUE)
        server.sin_port = htons(SERVER_PORT_FOR_PRI);
    else
        server.sin_port = htons(SERVER_PORT_FOR_SEC);

    // Bind
    if (bind(serverFd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        // print the error messageLooping through
        logPrint(LOG_ERR, "Socket Bind failed for external Interface \n");
        return 1;
    }
    // Listen
    listen(serverFd, 1); // We need only 1 client connection

    clientSockLen = sizeof(struct sockaddr_in);

    logPrint(LOG_INFO, "Waiting for client to Connect with our application \n");
    // accept connection from an incoming client
    clientFd = accept(serverFd, (struct sockaddr *)&client, (socklen_t *)&clientSockLen);
    if (clientFd < 0)
    {
        logPrint(LOG_ERR, "External Client accept failed \n");
        return 1;
    }
    else
    {
        logPrint(LOG_ERR, "External Client connected with Clientfd Value = %d\n", clientFd);
        strncpy(clientIP, inet_ntoa(client.sin_addr), 16);
        logPrint(LOG_ERR, "External Client IP Address = %s\n", clientIP);
    }

    return 0;
}

void writeToExternalSocketInterface(tOCT_UINT8 *msgBuf, tOCT_UINT16 msgLen)
{
    fxLHeader *hdr = NULL;
    hdr = (fxLHeader *)msgBuf;
    int writeBytes = -1;
    if (/*((fcntl(clientFd, F_GETFL) != -1) || (errno != EBADF)) &&*/ (clientFd != -1))
    {
        uint16 n = 0, bytesLeft = msgLen;
        while (n < msgLen)
        {
            writeBytes = write(clientFd, msgBuf + n, bytesLeft);
            if (writeBytes < 0)
            {
                logPrint(LOG_ERR, "Write Error to External Socket Interface \n");
                return;
            }
            n = n + writeBytes;
            bytesLeft = bytesLeft - writeBytes;
            // logPrint(LOG_INFO, "msgLen = %d, write Bytes = %d\, Bytes Left = %d, n = %d \n", msgLen,writeBytes,bytesLeft,n);
        }
        if (hdr->msgType != FXL_4G_MEASUREMENT_REPORT_IND)
            logPrint(LOG_INFO, "Client Message sent MsgType = %d\n", hdr->msgType);
    }
    return;
}

void closeSocketServerInterface(void)
{
    close(serverFd);
}

sint32 recvFromExternalSocketInterface(tOCT_UINT8 *rcvbuffer, tOCT_UINT32 size_bytes)
{
    sint32 length = -1;
    fxLHeader *hdr;
    logPrint(LOG_DEBUG, "recvFromExternalSocketInterface called with recvFd = %d \n", clientFd);
    length = recv(clientFd, rcvbuffer, size_bytes, 0);

    if (length <= 0)
    {
        logPrint(LOG_ERR, "External Client disconnected \n");
        close(clientFd);
        clientFd = -1;
        checkAndSetOnBinState();
    }
    else
    {
        hdr = (fxLHeader *)rcvbuffer;
        logPrint(LOG_INFO, "Client Message received MsgType = %d\n", hdr->msgType);
        switch (hdr->msgType)
        {
        case FXL_HANDSHAKE_CMD:
            handshakeMsgHandler(rcvbuffer);
            break;

        case FXL_BOOT_L1_CMD:
            bootL1CmdHandler(rcvbuffer);
            break;

        case FXL_CONFIGURE_IDENTITY_LIST_CMD:
            configureIdentityListCmdHandler(rcvbuffer, 0);
            break;

        case FXL_DELETE_ENTRY_IN_IDENTITY_LIST_CMD:
            deleteEntryInIdentityListCmdHandler(rcvbuffer);
            break;

        case FXL_RESET_IDENTITY_LIST_CMD:
            resetIdentityListCmdHandler(rcvbuffer);
            break;
        case FXL_ENABLE_GPS_CMD:
            enableGpsCmdHandler(rcvbuffer);
            break;

        case FXL_STOP_GPS_CMD:
            stopGpsCmdHandler(rcvbuffer);
            break;

        case FXL_CHANGE_TX_RX_ANTENNA_ID_CMD:
            changeTxRxAntennaIdCmdHandler(rcvbuffer);
            break;

        case FXL_ENABLE_TX_CALIBRATION_CMD:
            enableTxCalibration(rcvbuffer);
            break;

        case FXL_2G_CONFIGURE_IDCATCHER_PARAMS_CMD:
            currentOneBinState = ONEBIN_STATE_2G_IDCATCHING;
            configureBasestationParamsCmdHandler(rcvbuffer);
            break;

        case FXL_2G_START_IDCATCHER_CMD:
            startBasestationCmdHandler(rcvbuffer);
            break;
        case FXL_2G_IDCATCHER_RF_MODIFY_CMD:
            gsmRfModifyCmdHandler(rcvbuffer);
            break;
#ifdef FEA_2G_DYNAMIC_SYS_INFO_CONFIG
        case FXL_2G_SYS_INFO_MODIFY_CMD:
            gsmSysInfoModifyCmdHandler(rcvbuffer);
            break;
#endif
        case FXL_2G_GET_RSSI_GPS_COORDINATES_CMD:
            getRssiGpsCordinatesCmdHandler(rcvbuffer);
            break;

        case FXL_2G_GET_BLOCKED_CALL_COUNTER_CMD:
            getBlockedCallCounterCmdHandler(rcvbuffer);
            break;

#ifdef FEA_SILENT_CALL
        case FXL_2G_START_SILENT_CALL_CMD:
            startSilentCallCmdHandler(rcvbuffer);
            break;

        case FXL_2G_MODIFY_UE_TX_POWER_CMD:
            modifyUeTxPowerCmdHandler(rcvbuffer);
            break;

        case FXL_2G_END_SILENT_CALL_CMD:
            endSilentCallCmdHandler(rcvbuffer);
            break;

        case FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_CMD:
            silentCallDedSysInfoModifyCmd(rcvbuffer);
            break;
#endif

#ifdef FEA_MT_SMS
        case FXL_2G_SEND_INDIVIDUAL_SMS_CMD:
            sendIndividualSmsCmdHandler(rcvbuffer);
            break;

        case FXL_2G_SEND_BROADCAST_SMS_CMD:
            sendBroadcastSmsCmdHandler(rcvbuffer);
            break;
#endif

        case FXL_2G_REDIRECT_TO_2G_CELL_CMD:
            redirectTo2gCellCmdHandler(rcvbuffer);
            break;

        case FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_CMD:
            listenModeConfigureBandsCmdHandler(rcvbuffer);
            break;

        case FXL_2G_LISTEN_MODE_START_SCAN_CMD:
            listenModeStartScanCmdHandler(rcvbuffer);
            break;

        case FXL_2G_LISTEN_MODE_STOP_SCAN_CMD:
            listenModeStopScanCmdHandler(rcvbuffer);
            break;

        case FXL_2G_STOP_IDCATCHER_CMD:
            currentOneBinState = ONEBIN_STATE_IDLE;
            stop2gIdcatcherCmdHandler(rcvbuffer);
            break;

        case FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD:
            configureGsmFreqForSelectiveScanCmdHandler(rcvbuffer);
            break;

#ifdef FEA_ALERT
        case FXL_2G_ALERT_BLACKLIST_CMD:
            alertBlacklist(rcvbuffer);
            break;
#endif

#ifdef FEA_2G_RELEASE_BL_USER
        case FXL_2G_BL_USER_RELEASE_CMD:
            gsmBlUserReleaseCmdHandler(rcvbuffer);
            break;

        case FXL_2G_ALL_BL_USER_RELEASE_CMD:
            allBlUserReleaseCmdHandler(rcvbuffer);
            break;
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET
        case FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_CMD:
            setMoMsisdnForTargetVoiceCall(rcvbuffer);
            break;
#endif

        case FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_CMD:
            listenModeConfigHandler(rcvbuffer);
            break;

        case FXL_3G_LISTEN_MODE_PRIORITY_SCAN_CMD:
            listenModePriorityScanHandler(rcvbuffer);
            break;

        case FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_CMD:
            listenModeStartStopHandler(rcvbuffer);
            break;

        case FXL_3G_CONFIGURE_IDCATCHER_PARAMS_CMD:
            umtsConfigureIdCatcherParams(rcvbuffer);
            break;

        case FXL_3G_START_IDCATCHER_CMD:
            currentOneBinState = ONEBIN_STATE_3G_IDCATCHING;
            umtsStartIdCatcher(rcvbuffer);
            break;
        case FXL_3G_STOP_IDCATCHER_CMD:
            currentOneBinState = ONEBIN_STATE_IDLE;
            umtsStopIdCatcher(rcvbuffer);
            break;
        case FXL_3G_AUTO_CONFIG_CMD:
            currentOneBinState = ONEBIN_STATE_3G_AUTOCONFIG;
            umtsAutoConfig(rcvbuffer);
            break;

        case FXL_3G_AUTO_CONFIG_STOP_CMD:
            currentOneBinState = ONEBIN_STATE_IDLE;
            umtsAutoConfigStop(rcvbuffer);
            // close (clientFd);
            // clientFd = -1;
            break;

        case FXL_3G_SYSINFO_CONFIG_CMD:
            umtsSysInfoConfigHndlr(rcvbuffer);
            break;

        case FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_CMD:
            umtsChangeTxAttnCpichTxPwr(rcvbuffer);
            break;
        case FXL_3G_START_SILENT_CALL_CMD:
            umtsStartSilentCallCmd(rcvbuffer);
            break;

        case FXL_3G_END_SILENT_CALL_CMD:
            umtsEndSilentCallCmd(rcvbuffer);
            break;

        case FXL_3G_CHANGE_UE_UL_TX_PWR_CMD:
            umtsChangeUeUlTxPwr(rcvbuffer);
            break;

        case FXL_3G_BL_UE_REDIRECT_CMD:
            umtsRedirectBlUe(rcvbuffer);
            break;

#ifdef FXL_3G_TX_JAMMER
        case FXL_3G_TX_JAMMER_START_CMD:
            umtsStartTxJammer(rcvbuffer);
            break;

        case FXL_3G_TX_JAMMER_STOP_CMD:
            umtsStopTxJammer(rcvbuffer);
            break;
#endif // FXL_3G_TX_JAMMER
        case FXL_GET_UE_WITHIN_RANGE_CMD:
            ratGetNumOfUeWithinRange(rcvbuffer);
            break;

        case FXL_4G_CONFIGURE_IDCATCHER_PARAMS_CMD:
            currentOneBinState = ONEBIN_STATE_4G_IDCATCHING;
            lteConfigureIdCatcherParamsHandler(rcvbuffer);
            break;

        case FXL_4G_START_IDCATCHER_CMD:
            lteStartIdCatcherHandler(rcvbuffer);
            break;

        case FXL_4G_STOP_IDCATCHER_CMD:
            currentOneBinState = ONEBIN_STATE_IDLE;
            lteStopIdCatcherHandler(rcvbuffer);
            break;
        case FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_CMD:
            listenMode4gConfigureBandsCmdHandler(rcvbuffer);
            break;

        case FXL_4G_LISTEN_MODE_START_SCAN_CMD:
            listenMode4gStartScanCmdHandler(rcvbuffer);
            break;

        case FXL_4G_LISTEN_MODE_STOP_SCAN_CMD:
            listenMode4gStopScanCmdHandler(rcvbuffer);
            break;

        case FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD:
            configureLteFreqForSelectiveScanCmdHandler(rcvbuffer);
            break;
        case FXL_4G_START_SILENT_CALL_CMD:
            lteStartSilentCallCommandHandler(rcvbuffer);
            break;

        case FXL_4G_END_SILENT_CALL_CMD:
            lteStopSilentCallCommandHandler(rcvbuffer);
            break;

        case FXL_4G_IDCATCHER_RF_MODIFY_CMD:
            lteRfModifyCmdHandler(rcvbuffer);
            break;

        case FXL_4G_BL_UE_REDIRECT_CMD:
            lteBlUeRedirectCmdHandler(rcvbuffer);
            break;

        case FXL_4G_BL_USER_RELEASE_CMD:
            lteBlUserReleaseCmdHandler(rcvbuffer);
            break;

        case FXL_4G_MODIFY_EARFCN_CMD:
            lteModifyEarfcnCmdHandler(rcvbuffer);
            break;

        case FXL_4G_UE_MEASUREMENT_CONFIG_CMD:
            lteUeMeasurementCfgHndlr(rcvbuffer);
            break;

#ifdef FXL_4G_TX_JAMMER
        case FXL_4G_TX_JAMMER_START_CMD:
            lteStartTxJammer(rcvbuffer);
            break;

        case FXL_4G_TX_JAMMER_STOP_CMD:
            lteStopTxJammer(rcvbuffer);
            break;
#endif // FXL_4G_TX_JAMMER

        case FXL_4G_SYS_INFO_MODIFY_CMD:
            lteSysInfoModifyCmdHandler(rcvbuffer);
            break;
        case FXL_4G_CONFIGURE_NEIGHBOR_CMD:
            lteConfigureNeighborCmdHandler(rcvbuffer);
            break;

        case FXL_2G_BASS_MODE_CONFIGURE_BANDS_CMD:
            gsmBassModeConfigureBandsCmdHandler(rcvbuffer);
            break;

        case FXL_2G_BASS_MODE_START_CMD:
            currentOneBinState = ONEBIN_STATE_2G_BASS;
            gsmBassModeStartCmdHandler(rcvbuffer);
            break;

        case FXL_2G_BASS_MODE_STOP_CMD:
            currentOneBinState = ONEBIN_STATE_IDLE;
            gsmBassModeStopCmdHandler(rcvbuffer);
            break;

#ifdef OBM_PA_BTS8000
        case FXL_OBM_RA_RF_CTRL_CMD:
            obmRaRfCtrlCmdHandler(rcvbuffer);
            break;
#endif

#ifdef OBM_PA_BTS8500_NW
        case FXL_OBM_RA_RF_CTRL_CMD:
            obmRaRfNWCtrlCmdHandler(rcvbuffer);
            break;
#endif
#ifdef OBM_PA_BTS8500_WW
        case FXL_OBM_RA_RF_CTRL_CMD:
            obmRaRfWWCtrlCmdHandler(rcvbuffer);
            break;
#endif

        case FXL_OBM_SWITCH_OFF_BOARD_CMD:
            obmSwitchOffBoardCmdHandler(rcvbuffer);
            break;

#ifdef OBM_BATTERY_STATUS
        case FXL_OBM_BATTERY_STATUS_CMD:
            obmBatteryStatusCmdHandler(rcvbuffer);
            break;
#endif

#ifdef OBM_TEMPERATURE_STATUS
        case FXL_OBM_TEMPERATURE_STATUS_CMD:
            obmTemperatureStatusCmdHandler(rcvbuffer);
            break;
#endif

        default:
            break;
        }
    }

    return length;
}

unsigned char convertFxTo3gppLteBand(unsigned char band)
{
    int bandValue = 0;

    if (band <= FXL_BAND_LTE_48)
    {
        bandValue = band + 1;
    }
    else if (band == FXL_BAND_LTE_50 || band == FXL_BAND_LTE_51)
    {
        bandValue = band + 2;
    }
    else if ((band >= FXL_BAND_LTE_65) && (band <= FXL_BAND_LTE_72))
    {
        bandValue = band + 15;
    }
    else if ((band >= FXL_BAND_LTE_74) && (band <= FXL_BAND_LTE_76))
    {
        bandValue = band + 16;
    }
    else
    {
        logPrint(LOG_ERR, "Wrong Band Selection in CellAntenna PA Configuration for LTE ID Catcher \n");
    }
    return bandValue;
}

int getGsmBand(int band)
{

    int bandValue = 0;

    switch (band)
    {
    case FXL_BAND_GSM_850:
        bandValue = 5;
        break;

    case FXL_BAND_R_GSM:
    case FXL_BAND_E_GSM:
    case FXL_BAND_GSM_900:
        bandValue = 8;
        break;

    case FXL_BAND_DCS_1800:
        bandValue = 3;
        break;

    case FXL_BAND_PCS_1900:
        bandValue = 2;
        break;

    case FXL_BAND_GSM_450:
        bandValue = 31;
        break;

    default:
        break;
    }

    return bandValue;
}

#ifdef OBM_BATTERY_STATUS
/*############################################################################
 * Method Name : obmBatteryStatusCmdHandler
 *
 * Description : This procedure handles the battery status command from external
 *               client and sends response with battery and temperature status.
 *
 * Parameters  : In Message Buffer
 *
 * Returns     : None
 ############################################################################*/
void obmBatteryStatusCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    unsigned int retCode = 0;
    fxLObmBatteryStatusCmd *cmd = (fxLObmBatteryStatusCmd *)inMsgBuf;
    fxLObmBatteryStatusRsp *rsp = (fxLObmBatteryStatusRsp *)msgBuf;

    memset((fxLObmBatteryStatusRsp *)&gBatteryStatusRsp, 0, sizeof(fxLObmBatteryStatusRsp));

    /* Get the Battery Status */
    char *batArgValue[2] = {"bat", "0"};
    optreset = 1;

    retCode = g_Commands[1]->pfctCallBack(2, batArgValue);
    if (0 == retCode)
    {
        rsp->result = FXL_SUCCESS;
    }
    else
    {
        logPrint(LOG_DEBUG, "Getting Battery Status failed\n");
        rsp->result = FXL_FAILURE;
    }

    rsp->hdr.msgLength = sizeof(fxLObmBatteryStatusRsp);
    rsp->hdr.msgType = FXL_OBM_BATTERY_STATUS_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    rsp->boardId = gBatteryStatusRsp.boardId;
    rsp->batteryId = gBatteryStatusRsp.batteryId;
    rsp->batteryPowerLevel = gBatteryStatusRsp.batteryPowerLevel;
    rsp->batteryChargingFlag = gBatteryStatusRsp.batteryChargingFlag;
    rsp->batteryFaultFlag = gBatteryStatusRsp.batteryFaultFlag;
    rsp->batteryTempFaultFlag = gBatteryStatusRsp.batteryTempFaultFlag;
    rsp->batteryLowWaringFlag = gBatteryStatusRsp.batteryLowWaringFlag;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLObmBatteryStatusRsp));
    return;
}
#endif

#ifdef OBM_TEMPERATURE_STATUS
/*############################################################################
 * Method Name : obmTemperatureStatusCmdHandler
 *
 * Description : This procedure handles the battery status command from external
 *               client and sends response with battery and temperature status.
 *
 * Parameters  : In Message Buffer
 *
 * Returns     : None
 ############################################################################*/

void obmTemperatureStatusCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    unsigned int retCode = 0;
    fxLObmTemperatureStatusCmd *cmd = (fxLObmTemperatureStatusCmd *)inMsgBuf;
    fxLObmTemperatureStatusRsp *rsp = (fxLObmTemperatureStatusRsp *)msgBuf;

    memset((fxLObmTemperatureStatusRsp *)&gTemperatureStatusRsp, 0, sizeof(fxLObmTemperatureStatusRsp));

    char *boardInfoArgValue[1] = {"bi"};
    optreset = 1;

    retCode = g_Commands[2]->pfctCallBack(1, boardInfoArgValue);
    if (0 == retCode)
    {
        rsp->result = FXL_SUCCESS;
    }
    else
    {
        logPrint(LOG_INFO, "Getting Board Info failed\n");
        rsp->result = FXL_FAILURE;
    }

    rsp->hdr.msgLength = sizeof(fxLObmTemperatureStatusRsp);
    rsp->hdr.msgType = FXL_OBM_TEMPERATURE_STATUS_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    rsp->dspTemperature = gTemperatureStatusRsp.dspTemperature;
    rsp->rfTemperature = gTemperatureStatusRsp.rfTemperature;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLObmTemperatureStatusRsp));
    return;
}
#endif

/*############################################################################
 * Method Name : obmSwitchOffBoardCmdHandler
 *
 * Description : This procedure switches off the board;
 *
 * Parameters  : In Message Buffer
 *
 * Returns     : None
 ############################################################################*/
void obmSwitchOffBoardCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    if (system("poweroff") == -1)
    {
        logPrint(LOG_ERR, "Failed to Power Off the board\n");
    }
#if 0
    /* Stop the Board */
    char *bsArgValue[1] = { "bs" };
    optreset = 1;

    retCode = g_Commands[3]->pfctCallBack(1, bsArgValue); 
    if (0 == retCode)
    {
	logPrint(LOG_DEBUG , "Board Stop is successful\n");
    }
    else
    {
	logPrint(LOG_DEBUG , "Board Stop is failed\n");
    }
#endif

    /* No need to send response as board is off */
}

#ifdef FXL_BOARD_STATUS
/*############################################################################
 * Method Name : buildAndSendBatteryStatusInd
 *
 * Description : This procedure fills and battery status indication to External
 *               Client.
 *
 * Parameters	: None
 *
 * Returns 	: None
 ############################################################################*/
void buildAndSendBatteryStatusInd(void)
{
    /* Fill the Header Part */
    gBatteryStatusInd.hdr.msgLength = sizeof(fxLObmBatteryStatusInd);
    gBatteryStatusInd.hdr.rat = FXL_RAT_NONE;
    gBatteryStatusInd.hdr.msgType = FXL_OBM_BATTERY_STATUS_IND;

    if (-1 != clientFd)
    {
        if (send(clientFd, &gBatteryStatusInd, sizeof(fxLObmBatteryStatusInd), 0) < 0)
        {
            logPrint(LOG_DEBUG, "Send Battery Status Indication is failed....\n");
        }
        else
        {
            logPrint(LOG_DEBUG, "Battery Status Indication is sent....\n");
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "Send Battery Status Indication is failed, clientFd = -1....\n");
    }
}

/*############################################################################
 * Method Name : boardMonitor
 *
 * Description : This procedure monitors the board status and sends indication
 *               to the External Client.
 *
 * Parameters	:
 *  dummy		  Dummy
 *
 * Returns 	: NULLP, if exits
 *                None,  waits forever
 ############################################################################ */
void *boardMonitor(void *dummy)
{
    struct timespec sleepTime;
    unsigned int retCode = 0;

    while (1)
    {
        memset((fxLObmBatteryStatusInd *)&gBatteryStatusInd, 0, sizeof(fxLObmBatteryStatusInd));

        /* Get the Battery Status */
        char *batArgValue[2] = {"bat", "0"};
        optreset = 1;

        retCode = g_Commands[1]->pfctCallBack(2, batArgValue);
        if (0 == retCode)
        {
            buildAndSendBatteryStatusInd();
        }
        else
        {
            logPrint(LOG_DEBUG, "Getting Battery Status failed\n");
        }

        /* Wakeup after each 5 minutes */
        sleepTime.tv_sec = 60;
        sleepTime.tv_nsec = 0;
        nanosleep(&sleepTime, NULL);
    }
}
#endif

void externalSocketMsgHandler()
{
    char *pCommand = NULL;
    int status = 0;
    fd_set readFds;
    struct timeval selTimeout;
    struct sockaddr_in client;
    int clientSockLen = sizeof(struct sockaddr_in);

    logPrint(LOG_DEBUG, "externalSocketMsgHandler Thread Initialized\n");

    /* Initialize OBM */
    initializeObm();

#ifdef FXL_BOARD_STATUS
    /* Create a Board Monitoring Thread for BTS8000 */
    if (pthread_attr_init(&gBoardMonitorThreadAttr))
    {
        logPrint(LOG_DEBUG, "Board Monitoring Thread Attribute Initialization failed\n");
        exit(0);
    }

    if (pthread_create(&gBoardMonitorThreadId, &gBoardMonitorThreadAttr, boardMonitor, NULL))
    {
        logPrint(LOG_DEBUG, "Board Monitoring Thread Creation failed\n");
        exit(0);
    }
#endif

    while (TRUE)
    {
        if (clientFd == -1) // When there is no client wait on accept
        {
            logPrint(LOG_DEBUG, "Waiting for New Client Connection\n");
            clientFd = accept(serverFd, (struct sockaddr *)&client, (socklen_t *)&clientSockLen);
            if (clientFd < 0)
            {
                logPrint(LOG_ERR, "External Client accept failed \n");
            }
            else
            {
                logPrint(LOG_ERR, "New Client interface create with ClientFd Value = %d\n", clientFd);
                strncpy(clientIP, inet_ntoa(client.sin_addr), 16);
                logPrint(LOG_ERR, "External Client IP Address = %s\n", clientIP);
            }
        }
        else // When there is a client then wait on select
        {
            /* Wait on Select for Client */
            FD_ZERO(&readFds);
            FD_SET(clientFd, &readFds);

            /* Set Select Timeout */
            selTimeout.tv_sec = 10;
            selTimeout.tv_usec = 0;

            /* Call Select */
            status = select((clientFd + 1), &readFds, NULL, NULL, &selTimeout);

            if (0 == status)
            {
                /* Timeout Case, Ping the client to check the Ethernet Connection */
                asprintf(&pCommand, "ping -c 1 %s", clientIP);

                status = system(pCommand);
                if (WEXITSTATUS(status) == 0)
                {
                    // Do Nothing, Wait on Select again
                    logPrint(LOG_ERR, " WEXITSTATUS is 0 \n");
                }
                else
                {
                    logPrint(LOG_ERR, "Ping Failure for Client IP = %s, status = %d\n",
                             clientIP, status);
                    printf("Ethernet Connection disconnected between Client and WGS \n");
                    close(clientFd);
                    clientFd = -1;
                    checkAndSetOnBinState();
                }

                if (NULL != pCommand)
                {
                    free(pCommand);
                    pCommand = NULL;
                }
            }
            else if (0 > status)
            {
                logPrint(LOG_ERR, "Select failed for Client IP Address = %s\n",
                         clientIP);
            }
            else
            {

                logPrint(LOG_ERR, " calling FD_ISSET \n");
                if (FD_ISSET(clientFd, &readFds))
                {
                    memset(clientMsgBuf, 0, EXTERNAL_MESSAGE_SIZE);
                    recvFromExternalSocketInterface(clientMsgBuf, EXTERNAL_MESSAGE_SIZE);
                }
            }
        }
    }
    return;
}

void handshakeMsgHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLHandShakeCmd *cmd = (fxLHandShakeCmd *)inMsgBuf;
    fxLHandShakeRsp *rsp = (fxLHandShakeRsp *)msgBuf;
    logPrint(LOG_INFO, "VERSION  = %f\n", cmd->clientSocketApiVersion);

    rsp->FeatureEnabled = FEATURE_SCANNER;

    rsp->FeatureEnabled |= FEATURE_2G_IDCATCHER;
    rsp->FeatureEnabled |= FEATURE_3G_IDCATCHER;
    rsp->FeatureEnabled |= FEATURE_4G_FDD_IDCATCHER;
    rsp->FeatureEnabled |= FEATURE_4G_TDD_IDCATCHER;
    logPrint(LOG_DEBUG, " Feature Status (%0x) , Minor Version = %d", rsp->FeatureEnabled, FXL_MINOR_VERSION);

    if (cmd->clientSocketApiVersion == (float)(FXL_SOCKETINTERFACEAPI_VERSION))
    {
        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
    }
    rsp->ServerSocketApiVersion = FXL_SOCKETINTERFACEAPI_VERSION;
    rsp->minorVersion = FXL_MINOR_VERSION;
    rsp->hdr.msgLength = sizeof(fxLHandShakeRsp);
    rsp->hdr.msgType = FXL_HANDSHAKE_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLHandShakeRsp));

    return;
    // Do some initialization here if needed
}

void getRssiGpsCordinatesCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gGetRssiGpsCoordinatesCmd *getGps = (fxL2gGetRssiGpsCoordinatesCmd *)inMsgBuf;
    fxL2gGetRssiGpsCoordinatesRsp *rsp = (fxL2gGetRssiGpsCoordinatesRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(getGps->imsiStr), FALSE, FALSE);
    // TBD Implement search based on UeIndex
    if (blackUserInfo != NULL)
    {
        if (getGps->startStopTrigger == FXL_START_CONTINUOUS_TRIGGER)
        {
            if (getGps->measTriggerType == FXL_MEAS_TRIGGER_CONTINUOUS)
            {
                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS;
            }
            else
            {
                // Stop timer after receiveing paging response for one shot case
                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT;
            }

            blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
        }
        else if (getGps->startStopTrigger == FXL_STOP_CONTINUOUS_TRIGGER)
        {
            blackUserInfo->triggerPagingReq = FALSE;
            blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_RSSI_GPS_IND;

            if (isTimerRunning(&blackUserInfo->tmr) == TRUE)
            {
                timerStop(&blackUserInfo->tmr);
            }
        }

        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in blacklist list\n");
    }

    memcpy(rsp->imsiStr, getGps->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gGetRssiGpsCoordinatesRsp);
    rsp->hdr.msgType = FXL_2G_GET_RSSI_GPS_COORDINATES_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gGetRssiGpsCoordinatesRsp));
    return;
}

void searchAndUpdateIdDbForDuplicateEntries(fxLConfigureIdentityListCmd *cmd, tOCT_UINT8 *sharedMemPtr)
{
    tOCT_UINT16 i = 0;
    tOCT_UINT8 j = 0;
    tOCT_UINT8 duplicateEntryFound = FALSE;

    /* Remove duplicate entries in the cmd list first */
    for (i = 0; i < cmd->noOfEntries;)
    {
        for (j = i + 1; j < cmd->noOfEntries; j++)
        {
            if ((cmd->configList[j].idType == cmd->configList[i].idType) &&
                (memcmp(cmd->configList[j].identity, cmd->configList[i].identity, MAX_IDENTITY_LENGTH_STR) == 0))
            {
                /* Duplicate Entry, Move the last entry in the list to current entry and decrement the entry count by 1 */
                memcpy(&cmd->configList[i], &cmd->configList[cmd->noOfEntries - 1], sizeof(fxLIdentityConfig));
                cmd->noOfEntries--;

                duplicateEntryFound = TRUE;
                break;
            }
        }
        if (duplicateEntryFound)
        {
            duplicateEntryFound = FALSE;
        }
        else
            i++;
    }

    configUeIdList.configId = (IdentityConfigStr *)(sharedMemPtr + CONFIG_DATA_SIZE);

    /* Check the shared memory to check if entries exist already */
    for (i = 0; i < cmd->noOfEntries;)
    {
        for (j = 0; j < configUeIdList.numbOfIds; j++)
        {
            if (((configUeIdList.configId + j)->idType == cmd->configList[i].idType) &&
                (memcmp((configUeIdList.configId + j)->identity, cmd->configList[i].identity, MAX_IDENTITY_LENGTH_STR) == 0))
            {
                /* Duplicate Entry Found */

                /* Delete the Blacklisted User if configuration is changed from BL to WL */
                if (((configUeIdList.configId + j)->listType == BLACKLIST) && (cmd->configList[i].listType == WHITELIST))
                {
                    logPrint(LOG_DEBUG, "Case -1(RAT : %d)\n", cmd->hdr.rat);
                    if (cmd->hdr.rat == FXL_RAT_2G)
                    {
                        blackListedUserInfo *blackUserInfo = NULL;
                        if ((configUeIdList.configId + j)->idType == IMEI)
                            blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)cmd->configList[i].identity, FALSE, TRUE);
                        else
                            blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)cmd->configList[i].identity, FALSE, FALSE);

                        if (blackUserInfo != NULL)
                        {
                            // Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
                            send2gBlUePowerOffInd(blackUserInfo, FXL_ID_CONFIG_CHANGED);
#else
                            sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
                            delete2gBlackListUserFromLinkedList(blackUserInfo);
                        }
                    }
                    else if (cmd->hdr.rat == FXL_RAT_3G)
                    {
                        logPrint(LOG_DEBUG, "3G Case \n");
                    }
                    else if (cmd->hdr.rat == FXL_RAT_4G) // Delete BL configuration for BL->WL Update
                    {
                        logPrint(LOG_DEBUG, "4G Case-1 \n");
                        lteblackListedUserInfo *blackUserDelInfo = blacklistLteUserFindUsingIdentity((uint8 *)cmd->configList[i].identity, FALSE);
                        if (blackUserDelInfo != NULL)
                        {
                            logPrint(LOG_DEBUG, "Delete old Configuration for IMSI (%s)\n", cmd->configList[i].identity);
                            logPrint(LOG_DEBUG, "Value of lteRelUeFlag is %d\n", lteRelUeFlag);
                            if (lteRelUeFlag == FALSE)
                            {
                                sendMsgToMacToRemovePagingReq(blackUserDelInfo); // to stop paging for this IMSI
                                deleteBlackListUserFromLinkedList(searchBlNodeUsingBlUsrInfo(blackUserDelInfo));
                            }
                        }
                    }
                    else
                    {
                    }
                }

                /*Overwrite the Shared Memory */
                (configUeIdList.configId + j)->listType = cmd->configList[i].listType;
                (configUeIdList.configId + j)->rejectCauseIfWhitelist = cmd->configList[i].rejectCauseIfWhitelist;

                /* Also move the last entry in the list to current entry and decrement the entry count by 1 */
                if (cmd->noOfEntries != 1)
                    memcpy(&cmd->configList[i], &cmd->configList[cmd->noOfEntries - 1], sizeof(fxLIdentityConfig));
                cmd->noOfEntries--;

                duplicateEntryFound = TRUE;
                break;
            }
        }

        if (duplicateEntryFound)
        {
            duplicateEntryFound = FALSE;
        }
        else
            i++;
    }
    lteRelUeFlag = FALSE;
}

void configureIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf, unsigned int is3GAutoCfg)
{
    // This needs to be put into shared memory
    fxLConfigureIdentityListCmd *cmd = (fxLConfigureIdentityListCmd *)inMsgBuf;
    fxLConfigureIdentityListRsp *rsp = (fxLConfigureIdentityListRsp *)msgBuf;
    tOCT_UINT8 i;

    rsp->result = FXL_FAILURE;

    if (cmd->noOfEntries > MAX_NO_OF_IDS_PER_TRANSACTION)
    {
        logPrint(LOG_ERR, "configureIdentityListCmdHandler: cmd->noOfEntries > MAX_NO_OF_IDS_PER_TRANSACTION\n");
        if (is3GAutoCfg == 1)
        {
            return; // Should not have reached here
        }
        // Not applying wrong configuration. No Need to stop Complete App for wrong configuration.
        rsp->hdr.msgLength = sizeof(fxLConfigureIdentityListRsp);
        rsp->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_RSP;
        rsp->hdr.rat = cmd->hdr.rat;
        rsp->result = FXL_FAILURE;

        writeToExternalSocketInterface(msgBuf, sizeof(fxLConfigureIdentityListRsp));
        return;
    }
    // NOTE: No need of RAT check as same Identity list handling for all RATs.

    tOCT_UINT8 *sharedMem = (tOCT_UINT8 *)getAccessToIdList();
    tOCT_UINT8 *initialAddress = sharedMem;
    ConfigList *configData = NULL;
    logPrint(LOG_INFO, "=========================== IDENTITY LIST CONFIGURATION ===========================\n");
    logPrint(LOG_INFO, "DEFAULT CONFIG = %s\n", cmd->defaultListConfig == 0 ? "WHITELIST" : "BLACKLIST");
    logPrint(LOG_INFO, "NUM-OF-IDS = %d\n", cmd->noOfEntries);
    for (i = 0; i < cmd->noOfEntries; i++)
    {
        logPrint(LOG_INFO, "%d : IDENTITY = %s, ID-TYPE = %s, LIST-TYPE = %s, REJ-CAUSE = %d\n", i + 1,
                 cmd->configList[i].identity,
                 cmd->configList[i].idType == 0 ? "IMSI" : "IMEI",
                 cmd->configList[i].listType == 0 ? "WHITELIST" : "BLACKLIST",
                 cmd->configList[i].rejectCauseIfWhitelist);
    }

    if (sharedMem != NULL)
    {
        configData = (ConfigList *)initialAddress;
        configData->defaultConfig = configUeIdList.defaultConfig = cmd->defaultListConfig;
        if (configUeIdList.numbOfIds <= MAX_NO_OF_IDS)
        {
            searchAndUpdateIdDbForDuplicateEntries(cmd, sharedMem);

            sharedMem = sharedMem + configUeIdList.numbOfIds * sizeof(IdentityConfigStr) + CONFIG_DATA_SIZE;
            if ((configUeIdList.numbOfIds + cmd->noOfEntries) > MAX_NO_OF_IDS)
            {
                cmd->noOfEntries = MAX_NO_OF_IDS - configUeIdList.numbOfIds; // These many entries we can accomodate
                configData->numbOfIds = configUeIdList.numbOfIds = MAX_NO_OF_IDS;
            }
            else
            {
                configData->numbOfIds = configUeIdList.numbOfIds = configUeIdList.numbOfIds + cmd->noOfEntries;
            }
            rsp->result = FXL_SUCCESS;

            configUeIdList.configId = (IdentityConfigStr *)(sharedMem);
            for (i = 0; i < cmd->noOfEntries; i++)
            {
                memcpy((configUeIdList.configId + i)->identity, cmd->configList[i].identity, SIZE_OF_IDENTITY_STR);
                (configUeIdList.configId + i)->idType = cmd->configList[i].idType;
                (configUeIdList.configId + i)->listType = cmd->configList[i].listType;
                (configUeIdList.configId + i)->rejectCauseIfWhitelist = cmd->configList[i].rejectCauseIfWhitelist;
            }
        }
    }

    releaseAccessToIdList(initialAddress);

    if (currentOneBinState == ONEBIN_STATE_4G_IDCATCHING)
    {
        ltePageAllConfifguredTargetPhone();
    }

    if (currentOneBinState == ONEBIN_STATE_3G_IDCATCHING)
    {
        pageAllConfiguredTargetPhone();
    }

    if (is3GAutoCfg == 1)
    {
        // For 3G AutoConfig response will go from calling function.
        return;
    }
    rsp->hdr.msgLength = sizeof(fxLConfigureIdentityListRsp);
    rsp->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLConfigureIdentityListRsp));

    return;
}
void autoConfigureRrcIdentityList(fxL3gAutoConfigCmd *cmd)
{
    fxLConfigureIdentityListCmd *identityListcmd = NULL;

    identityListcmd = (fxLConfigureIdentityListCmd *)malloc(sizeof(fxLConfigureIdentityListCmd));
    identityListcmd->hdr.msgLength = sizeof(fxLConfigureIdentityListCmd);
    identityListcmd->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_CMD;
    identityListcmd->hdr.rat = FXL_RAT_3G;
    identityListcmd->defaultListConfig = cmd->defaultListConfig;
    identityListcmd->noOfEntries = cmd->noOfEntries;
    memcpy(identityListcmd->configList, cmd->configList, MAX_NO_OF_IDS_PER_TRANSACTION * sizeof(fxLIdentityConfig));

    configureIdentityListCmdHandler(identityListcmd, 1);

    free(identityListcmd);
    identityListcmd = NULL;

    return;
}

void deleteEntryInIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLDeleteEntryInIdentityListCmd *cmd = (fxLDeleteEntryInIdentityListCmd *)inMsgBuf;
    fxLDeleteEntryInIdentityListRsp *rsp = (fxLDeleteEntryInIdentityListRsp *)msgBuf;
    tOCT_UINT16 i;
    tOCT_UINT8 *sharedMem = NULL;
    ConfigList *configData = NULL;
    DelConfigIdList *pDelConfigId = NULL;

    rsp->result = FXL_FAILURE;

    logPrint(LOG_INFO, "Delete Entry In Identity List Cmd: IdType(%d), Identity(%s)\n", cmd->idType, cmd->identity);

    sharedMem = (tOCT_UINT8 *)getAccessToIdList();

    if (sharedMem != NULL)
    {
        configData = (ConfigList *)sharedMem;
        configUeIdList.configId = (IdentityConfigStr *)(sharedMem + CONFIG_DATA_SIZE);

        for (i = 0; i < configUeIdList.numbOfIds; i++)
        {
            if (cmd->idType == FXL_IDENTITY_IMSI)
            {
                if (((configUeIdList.configId + i)->idType == IMSI) &&
                    (memcmp((configUeIdList.configId + i)->identity, cmd->identity, MAX_IDENTITY_LENGTH_STR) == 0))
                {
                    // Delete if a blacklist user exists with this identity.
                    if (cmd->hdr.rat == FXL_RAT_2G)
                    {
                        if ((configUeIdList.configId + i)->listType == BLACKLIST)
                        {
                            blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)cmd->identity, FALSE, FALSE);
                            if (blackUserInfo != NULL)
                            {
                                // Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
                                send2gBlUePowerOffInd(blackUserInfo, FXL_ID_CONFIG_CHANGED);
#else
                                sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
                                delete2gBlackListUserFromLinkedList(blackUserInfo);
                            }
                        }
                    }
                    else if (cmd->hdr.rat == FXL_RAT_3G)
                    {
                        if (BLACKLIST == (configUeIdList.configId + i)->listType)
                        {
                            pDelConfigId = (DelConfigIdList *)malloc(sizeof(DelConfigIdList));
                            memset((DelConfigIdList *)pDelConfigId, 0, sizeof(DelConfigIdList));

                            strncpy(pDelConfigId->identity, cmd->identity, SIZE_OF_IDENTITY_STR);
                            pDelConfigId->idType = 0;

                            SendMsgToTask(SOCK_ITF_TASK_E, APP_RRC_TASK_E, RRC_DEL_ID_LIST_E, pDelConfigId);
                        }
                    }
                    else if (cmd->hdr.rat == FXL_RAT_4G)
                    {
                        lteblackListedUserInfo *blackUserDelInfo = blacklistLteUserFindUsingIdentity((uint8 *)cmd->identity, FALSE);
                        if (blackUserDelInfo != NULL)
                        {
                            sendMsgToMacToRemovePagingReq(blackUserDelInfo); // to stop paging for this IMSI
                            deleteBlackListUserFromLinkedList(searchBlNodeUsingBlUsrInfo(blackUserDelInfo));
                        }
                    }

                    // Overwrite with the last element in the shared memory list and decrement the count
                    if (i == configUeIdList.numbOfIds - 1)
                    {
                        memset((configUeIdList.configId + (configUeIdList.numbOfIds - 1)), 0, sizeof(IdentityConfigStr));
                    }
                    else
                    {
                        memcpy((configUeIdList.configId + i), (configUeIdList.configId + (configUeIdList.numbOfIds - 1)), sizeof(IdentityConfigStr));
                        memset((configUeIdList.configId + (configUeIdList.numbOfIds - 1)), 0, sizeof(IdentityConfigStr));
                    }

                    configUeIdList.numbOfIds--;
                    configData->numbOfIds = configUeIdList.numbOfIds;
                    rsp->result = FXL_SUCCESS;
                    break;
                }
            }
            else
            {
                if (((configUeIdList.configId + i)->idType == IMEI) &&
                    (memcmp((configUeIdList.configId + i)->identity, cmd->identity, MAX_IDENTITY_LENGTH_STR) == 0))
                {

                    // Delete if a blacklist user exists with this identity.
                    if ((configUeIdList.configId + i)->listType == BLACKLIST)
                    {
                        blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)cmd->identity, FALSE, TRUE);

                        if (blackUserInfo != NULL)
                        {
                            // Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
                            send2gBlUePowerOffInd(blackUserInfo, FXL_ID_CONFIG_CHANGED);
#else
                            sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
                            delete2gBlackListUserFromLinkedList(blackUserInfo);
                        }
                    }
                    else if (cmd->hdr.rat == FXL_RAT_3G)
                    {
                        if (BLACKLIST == (configUeIdList.configId + i)->listType)
                        {
                            pDelConfigId = (DelConfigIdList *)malloc(sizeof(DelConfigIdList));
                            memset((DelConfigIdList *)pDelConfigId, 0, sizeof(DelConfigIdList));

                            strncpy(pDelConfigId->identity, cmd->identity, SIZE_OF_IDENTITY_STR);
                            pDelConfigId->idType = 1;

                            SendMsgToTask(SOCK_ITF_TASK_E, APP_RRC_TASK_E, RRC_DEL_ID_LIST_E, pDelConfigId);
                        }
                    }

                    // Overwrite with the last element in the shared memory list and decrement the count
                    if (i == configUeIdList.numbOfIds - 1)
                    {
                        memset((configUeIdList.configId + (configUeIdList.numbOfIds - 1)), 0, sizeof(IdentityConfigStr));
                    }
                    else
                    {
                        memcpy((configUeIdList.configId + i), (configUeIdList.configId + (configUeIdList.numbOfIds - 1)), sizeof(IdentityConfigStr));
                        memset((configUeIdList.configId + (configUeIdList.numbOfIds - 1)), 0, sizeof(IdentityConfigStr));
                    }

                    configUeIdList.numbOfIds--;
                    configData->numbOfIds = configUeIdList.numbOfIds;
                    rsp->result = FXL_SUCCESS;
                    break;
                }
            }
        }
    }
    rsp->hdr.msgLength = sizeof(fxLDeleteEntryInIdentityListRsp);
    rsp->hdr.msgType = FXL_DELETE_ENTRY_IN_IDENTITY_LIST_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLDeleteEntryInIdentityListRsp));

    releaseAccessToIdList(sharedMem);
}
void resetIdentityListCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLResetIdentityListCmd *cmd = (fxLResetIdentityListCmd *)inMsgBuf;
    fxLResetIdentityListRsp *rsp = (fxLResetIdentityListRsp *)msgBuf;

    tOCT_UINT8 *sharedMem = (tOCT_UINT8 *)getAccessToIdList();

    if (sharedMem != NULL)
    {
        memset(sharedMem, 0, SHARED_MEM_SIZE_TO_STORE_IDLIST);
        configUeIdList.defaultConfig = WHITELIST;
        configUeIdList.numbOfIds = 0;

        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
    }
    rsp->hdr.msgLength = sizeof(fxLResetIdentityListRsp);
    rsp->hdr.msgType = FXL_RESET_IDENTITY_LIST_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLResetIdentityListRsp));

    releaseAccessToIdList(sharedMem);
}

void configureBasestationParamsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gConfigureIdCatcherParamsCmd *cmd = (fxL2gConfigureIdCatcherParamsCmd *)inMsgBuf;
    fxL2gConfigureIdCatcherParamsRsp *rsp = (fxL2gConfigureIdCatcherParamsRsp *)msgBuf;
#ifndef PUMP_REG_DATA
    int i;
    logPrint(LOG_DEBUG, "2G_CONFIGURE_IDCATCHER_PARAMS_CMD Received :\n");
    logPrint(LOG_DEBUG, "ARFCN = %d, BAND = %s\n", cmd->Arfcn, WnmGetBandString(cOCTVC1_RADIO_STANDARD_ENUM_GSM, convertToOct2gBandFromFxL(cmd->Band)));
    logPrint(LOG_DEBUG, "PLMN-MCC: Length = %d, Mcc-1 = %d , Mcc-2 = %d , Mcc-3 = %d\n", cmd->plmn.mccLength, cmd->plmn.mcc[0], cmd->plmn.mcc[1], cmd->plmn.mcc[2]);
    logPrint(LOG_DEBUG, "PLMN-MNC: Length = %d ,Mnc-1 = %d , Mnc-2 = %d , Mnc-3 = %d\n", cmd->plmn.mncLength, cmd->plmn.mnc[0], cmd->plmn.mnc[1], cmd->plmn.mnc[2]);
    logPrint(LOG_DEBUG, "AUTO_CONFIG = %d\n", cmd->AutoConfigureEnabled);
    logPrint(LOG_DEBUG, "NCC: %d, BCC: %d, LAC: %d, CELL-ID: %d\n", cmd->ncc, cmd->bcc, cmd->Lac, cmd->Ci);
    logPrint(LOG_DEBUG, "DEFAULT_REJ_CAUSE_CONTROL: TO BE CHANGED = %d, DEFAULT_REJ_CAUSE = %d\n", cmd->changeWLDefaultRejectCause, cmd->defaultWLRejectCause);
    logPrint(LOG_DEBUG, "RX_GAIN = %d, TX_ATTN = %d\n", cmd->RxGainInDb, cmd->TxAttenuationInDb);
    logPrint(LOG_DEBUG, "TA_FILTER = %d \n", cmd->timingAdvanceFilter);

    gsmRxGainInDb = 70;
    gsmTxAttenuationInDb = 0;
    if ((currentDspImage == FXL_L1_GSM_NATIVE_IMAGE))
    {
        // Socket is created Successfully
        if (createThreadsForGsmNativeApp() == -1)
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Threads are not created \n");
            currentOneBinState = ONEBIN_STATE_IDLE;
        }
        else
        {
            assert(trx_g != NULL);

#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION

            if (cmd->sendSmsDuringRegistration)
            {
                trx_g->bts.sendSmsDuringRegistration = TRUE;
                memset(sendSmsDuringRegistrationL3Pdu, 0, SMS_CP_DATA_MAX_LENGTH);
                buildCpData(sendSmsDuringRegistrationL3Pdu, cmd->smsMessage, cmd->moMsisdnNoStr);
            }
            else
                trx_g->bts.sendSmsDuringRegistration = FALSE;
#endif
            /* Initialize MCC */
            trx_g->bts.network.mcc_length = 0;
            for (i = 0; i < GSM_MAX_MCC_LENGTH; i++)
            {
                trx_g->bts.network.mcc[i] = 0xF;
            }

            /* Fill MCC */
            trx_g->bts.network.mcc_length = cmd->plmn.mccLength;
            for (i = 0; i < cmd->plmn.mccLength; i++)
            {
                trx_g->bts.network.mcc[i] = cmd->plmn.mcc[i];
            }

            /* Initialize MNC */
            trx_g->bts.network.mnc_length = 0;
            for (i = 0; i < GSM_MAX_MNC_LENGTH; i++)
            {
                trx_g->bts.network.mnc[i] = 0xF;
            }

            /* Fill MNC */
            trx_g->bts.network.mnc_length = cmd->plmn.mncLength;
            for (i = 0; i < cmd->plmn.mncLength; i++)
            {
                trx_g->bts.network.mnc[i] = cmd->plmn.mnc[i];
            }

            trx_g->arfcn = cmd->Arfcn;
            trx_g->bts.band = cmd->Band;
            trx_g->bts.bsic = (tOCT_UINT8)((((cmd->ncc) & 0x07) << 3) | ((cmd->bcc) & 0x07));
            trx_g->bts.location_area_code = cmd->Lac;
            trx_g->bts.cell_identity = cmd->Ci;
            trx_g->tsNum = 0xff;
            trx_g->bts.tsc = trx_g->bts.bsic & 7;
            trx_g->trx_id = 0;
            trx_g->bts.redirType = FXL_GSM_NO_REDIR;
#ifdef FEA_EMER
            logPrint(LOG_DEBUG, "Emergencyredirectenable received = %d , ncc = %d,bcc=%d , bandIndicator = %d,arfcn=%d ", cmd->emergengyredirectenable, cmd->emergencyredirNcc, cmd->emergencyredirBcc, cmd->emergencyRedirectinfo.bandIndicator, cmd->emergencyRedirectinfo.startingarfcn);
            trx_g->bts.Emergencyredirectenable = cmd->emergengyredirectenable;
            trx_g->bts.Redirectemergencyinfo.bsic = (tOCT_UINT8)((((cmd->emergencyredirNcc) & 0x07) << 3) | ((cmd->emergencyredirBcc) & 0x07));
            trx_g->bts.Redirectemergencyinfo.bandIndicator = cmd->emergencyRedirectinfo.bandIndicator;
            trx_g->bts.Redirectemergencyinfo.arfcn = cmd->emergencyRedirectinfo.startingarfcn;
#endif

            // TA Filter
            trx_g->bts.ta_filter_start = 0;
            trx_g->bts.ta_filter_stop = (tOCT_UINT8)(cmd->timingAdvanceFilter);

            for (i = 0; i < MAX_TS; i++)
            {
                trx_g->ts[i].ts_num = i;
                trx_g->ts[i].tsc = -1; // use BTS TSC
            }

            /* 6 min periodic update interval as default */
            trx_g->bts.t3212 = 1;

#ifdef MM_INFO
            // Copy Network Name
            if ((strlen(cmd->nwName)) == 0)
            {
                trx_g->bts.nwNameLen = 0;
            }
            else
            {
                uint8 *user_data_ptr = &(trx_g->bts.nwName[0]), data_length = 0, character_count = 0;
                trx_g->bts.nwNameLen = create_sms_data(SMS_GSM_7BIT_CS, (tOCT_UINT8 *)cmd->nwName, &character_count, &user_data_ptr);
            }
            logPrint(LOG_DEBUG, "Network Name received = %s , Converted to GSM-7Bit-CS = %s , NwNameLength = %d\n ", cmd->nwName, trx_g->bts.nwName, trx_g->bts.nwNameLen);
#endif
            maxSdcchChannel = 0;
            maxTchfChannel = 0;
            maxTchhChannel = 0;
            maxPdtchChannel = 0;

            trx_g->ts[0].lchan = FCCH_SCH_BCCH_CCCH;

            trx_g->ts[1].lchan = SDCCH8_SACCHC8;
            maxSdcchChannel += 8;

            trx_g->ts[2].lchan = SDCCH8_SACCHC8;
            maxSdcchChannel += 8;

            trx_g->ts[3].lchan = SDCCH8_SACCHC8;
            maxSdcchChannel += 8;

            trx_g->ts[4].lchan = SDCCH8_SACCHC8;
            maxSdcchChannel += 8;

            trx_g->ts[5].lchan = TCHF_FACCHF_SACCHTF;
            maxTchfChannel += 1;

#ifdef FEA_GPRS
            trx_g->ts[6].lchan = PDTCHF_PACCHF_PTCCHF;
            maxPdtchChannel += 8;
#else
            trx_g->ts[6].lchan = SDCCH8_SACCHC8;
            maxSdcchChannel += 8;
#endif

            trx_g->ts[7].lchan = TCHF_FACCHF_SACCHTF;
            maxTchfChannel += 1;

            if (cmd->RxGainInDb > 73)
            {
                cmd->RxGainInDb = 73;
            }
            else if (cmd->RxGainInDb < 0)
            {
                cmd->RxGainInDb = 70;
            }
            gsmRxGainInDb = cmd->RxGainInDb;
            if (cmd->TxAttenuationInDb > 359)
            {
                cmd->TxAttenuationInDb = 359;
            }
            else if (cmd->TxAttenuationInDb < 0)
            {
                cmd->TxAttenuationInDb = 0;
            }
            gsmTxAttenuationInDb = cmd->TxAttenuationInDb;

#ifdef FEA_REJECT_CAUSE_CONTROL
            if (cmd->changeWLDefaultRejectCause == 0)
            {
                gsmDefaultWLRejectCause = FXL_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LA;
            }
            else
            {
                gsmDefaultWLRejectCause = cmd->defaultWLRejectCause;
            }
#endif
            rsp->result = FXL_SUCCESS;

            logPrint(LOG_DEBUG, "Auto-configuration = %d\n", cmd->AutoConfigureEnabled);

            if (cmd->AutoConfigureEnabled == TRUE)
            {
                if (parseGsmSysInfo(&cmd->plmn, (tOCT_UINT16 *)&cmd->Lac) == -1)
                {
                    logPrint(LOG_ERR, "Unable to open GsmSysInfo.txt file --------\n");
                    logPrint(LOG_DEBUG, "\n\nID Catcher Configuration Failed !\n");
                    rsp->result = FXL_FAILURE;
                    currentOneBinState = ONEBIN_STATE_IDLE;
                }
                else
                {
                    tOCT_UINT8 band;
                    selectCleanChannelFromParsedData((tOCT_UINT16 *)&cmd->Arfcn, &band);
                    if (cmd->Arfcn != 0)
                    {
                        trx_g->bts.band = band;
                        trx_g->arfcn = cmd->Arfcn;
                        trx_g->bts.location_area_code = cmd->Lac;
                        trx_g->bts.bsic = (tOCT_UINT8)gsmCommRand(0, 63); // generate a random bsic in the valid range
                        trx_g->bts.tsc = trx_g->bts.bsic & 7;
                        trx_g->bts.cell_identity = (tOCT_UINT16)gsmCommRand(0, 65535); // generate a random Cell Identity in the valid range

                        logPrint(LOG_DEBUG, "Gsm System Information Parsing Successful , Selected clean channel Arfcn = %d & Band = %s Lac = %d\n", cmd->Arfcn, WnmGetBandString(cOCTVC1_RADIO_STANDARD_ENUM_GSM, convertToOct2gBandFromFxL(band)), cmd->Lac);

                        fxL2gAutoConfigArfcnInd arfcnInd;
                        arfcnInd.hdr.msgLength = sizeof(fxL2gAutoConfigArfcnInd);
                        arfcnInd.hdr.msgType = FXL_2G_AUTO_CONFIG_ARFCN_IND;
                        arfcnInd.hdr.rat = FXL_RAT_2G;
                        arfcnInd.arfcn = trx_g->arfcn;
                        arfcnInd.band = trx_g->bts.band;
                        arfcnInd.ncc = (trx_g->bts.bsic >> 3) & 0x07;
                        arfcnInd.bcc = trx_g->bts.bsic & 0x07;
                        arfcnInd.lac = trx_g->bts.location_area_code;
                        arfcnInd.cellId = trx_g->bts.cell_identity;
                        writeToExternalSocketInterface((tOCT_UINT8 *)&arfcnInd, sizeof(fxL2gAutoConfigArfcnInd));

                        printf("\n\nID Catcher Configuration Successful !\n");
                        printf("MCC\t\t:\t");
                        for (i = 0; i < trx_g->bts.network.mcc_length; i++)
                            printf("%d", trx_g->bts.network.mcc[i]);
                        printf("\n");
                        printf("MNC\t\t:\t");
                        for (i = 0; i < trx_g->bts.network.mnc_length; i++)
                            printf("%d", trx_g->bts.network.mnc[i]);
                        printf("\n");
                        printf("ARFCN\t\t:\t%d\nBAND\t\t:\t%s\nBSIC(NCC|BCC)\t:\t%o\nLAC\t\t:\t%d\nCELL-ID\t\t:\t%d\n\n", trx_g->arfcn, WnmGetBandString(cOCTVC1_RADIO_STANDARD_ENUM_GSM, convertToOct2gBandFromFxL(trx_g->bts.band)), trx_g->bts.bsic, trx_g->bts.location_area_code, trx_g->bts.cell_identity);
                    }
                    else // Couldn't find cell through Auto-configuration.
                    {
                        logPrint(LOG_DEBUG, "Gsm System Information Parsing not Successful, couldn't find clean channel through Auto-Configuration\n");
                        logPrint(LOG_DEBUG, "\n\nID Catcher Configuration Failed !\n");
                        rsp->result = FXL_FAILURE;
                        currentOneBinState = ONEBIN_STATE_IDLE;
                    }
                }
            }
            else
            {
                printf("\n\nID Catcher Configuration Successful !\n");
                printf("MCC\t\t:\t");
                for (i = 0; i < trx_g->bts.network.mcc_length; i++)
                    printf("%d", trx_g->bts.network.mcc[i]);
                printf("\n");
                printf("MNC\t\t:\t");
                for (i = 0; i < trx_g->bts.network.mnc_length; i++)
                    printf("%d", trx_g->bts.network.mnc[i]);
                printf("\n");
                printf("ARFCN\t\t:\t%d\nBAND\t\t:\t%s\nBSIC(NCC|BCC)\t:\t%o\nLAC\t\t:\t%d\nCELL-ID\t\t:\t%d\n\n", trx_g->arfcn, WnmGetBandString(cOCTVC1_RADIO_STANDARD_ENUM_GSM, convertToOct2gBandFromFxL(trx_g->bts.band)), trx_g->bts.bsic, trx_g->bts.location_area_code, trx_g->bts.cell_identity);
            }

#ifdef CELL_ANTENNA_CHANGE
            int bandValue = 0;
            bandValue = getGsmBand(trx_g->bts.band);
            /* Set the CellAntenna PA */
            char dspType;
            if (TRUE == isItPrimaryDsp())
            {
                dspType = '1';
            }
            else
            {
                dspType = '2';
            }
            configureCellAntennaPA(dspType, bandValue, 'i');
#endif
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        currentOneBinState = ONEBIN_STATE_IDLE;
    }
#else
    rsp->result = FXL_SUCCESS;
#endif
    rsp->hdr.msgLength = sizeof(fxL2gConfigureIdCatcherParamsRsp);
    rsp->hdr.msgType = FXL_2G_CONFIGURE_IDCATCHER_PARAMS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gConfigureIdCatcherParamsRsp));
    return;
}

void startBasestationCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gStartIdCatcherRsp *rsp = (fxL2gStartIdCatcherRsp *)msgBuf;
#ifndef PUMP_REG_DATA

#if defined(OBM_PA_BTS8500_NW) || defined(OBM_PA_BTS8500_WW)
    system("obm rf 1 1");
#endif

    if ((currentDspImage == FXL_L1_GSM_NATIVE_IMAGE)) // First time we are getting configuration

    { /* Flexera changes start*/
        generateSysInfoMsgs();
        setNetworkDriverPriorityForLte(TRUE);
        if (octasicBtsInit() == 1)
        {
            rsp->result = FXL_FAILURE;
            currentOneBinState = ONEBIN_STATE_IDLE;
        }
        else
        {
            tchSilentCallUnderProgress = FALSE;
            cellBarDuringTchSilentCall = FALSE;
            rsp->result = FXL_SUCCESS;
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        currentOneBinState = ONEBIN_STATE_IDLE;
    }
#else
    rsp->result = FXL_SUCCESS;
#endif
    rsp->hdr.msgLength = sizeof(fxL2gStartIdCatcherRsp);
    rsp->hdr.msgType = FXL_2G_START_IDCATCHER_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gStartIdCatcherRsp));
#ifdef PUMP_REG_DATA
    sleep(1);
    startPumpData();
#endif

    return;
}

void gsmRfModifyCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gIdCatcherRfModifyCmd *cmd = (fxL2gIdCatcherRfModifyCmd *)inMsgBuf;
    fxL2gIdCatcherRfModifyRsp *rsp = (fxL2gIdCatcherRfModifyRsp *)msgBuf;

    // Range check
    if (cmd->TxAttenuationInDb > 359)
    {
        cmd->TxAttenuationInDb = 359;
    }
    else if (cmd->TxAttenuationInDb < 0)
    {
        cmd->TxAttenuationInDb = 0;
    }
    else
    {
    }

    if (GsmTrxModifyRf(cmd->TxAttenuationInDb) != cOCTVC1_RC_OK)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        rsp->result = FXL_SUCCESS;
    }

    rsp->hdr.msgLength = sizeof(fxL2gIdCatcherRfModifyRsp);
    rsp->hdr.msgType = FXL_2G_IDCATCHER_RF_MODIFY_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gIdCatcherRfModifyRsp));
    return;
}

#ifdef FEA_2G_DYNAMIC_SYS_INFO_CONFIG
void gsmSysInfoModifyCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    tOCT_UINT8 i, j;
    fxL2gSysInfoModifyCmd *cmd = (fxL2gSysInfoModifyCmd *)inMsgBuf;
    fxL2gSysInfoModifyRsp *rsp = (fxL2gSysInfoModifyRsp *)msgBuf;
    fxLResult result = FXL_SUCCESS;
#ifndef PUMP_REG_DATA

    logPrint(LOG_DEBUG, "** 2G_SYS_INFO_MODIFY_CMD Received : ** \n");
    logPrint(LOG_DEBUG, "** CELL-ID = %d, LAC = %d **\n", cmd->cellIdentity, cmd->lac);
    logPrint(LOG_DEBUG, "** RX_LEV_ACC_MIN = %d, CELL_RESEL_HYST = %d, MS_TX_PWR_MAX_CCCH = %d ** \n", cmd->rxlevAccMin, cmd->cellReselHyst, cmd->msTxpwrMaxCcch);
    logPrint(LOG_DEBUG, "** CBQ = %d, CRO = %d, TEMP_OFFSET = %d, PENALTY_TIME = %d ** \n", cmd->cbq, cmd->cro, cmd->tempOffset, cmd->penaltyTime);
    logPrint(LOG_DEBUG, "** Access-Class-List = %d **", cmd->accessClassList);
    logPrint(LOG_DEBUG, "** Cell-Barred = %d **", cmd->cellBarred);
    logPrint(LOG_DEBUG, "** No-Of-Neighbours    = %d: ** \n", cmd->noOfNeighbors);
    for (i = 0; i < cmd->noOfNeighbors; i++)
        logPrint(LOG_DEBUG, "** Neighbour ARFCN[%d] = %d **", i + 1, cmd->arfcnNeighbors[i]);

    logPrint(LOG_DEBUG, "** T3212     = %d: ** \n", cmd->t3212);

#ifdef FEA_2G_INTER_RAT_MEAS
    logPrint(LOG_DEBUG, "** InterRat Neighbour Info Present = %d: **", cmd->interRatInfoPresent);
    if (cmd->interRatInfoPresent)
    {
        logPrint(LOG_DEBUG, "** ServCell Prio Params: Present = %d", cmd->interRatInfo.servCellPrioParams.scellPrioParamsPresent);
        logPrint(LOG_DEBUG, "** ServCell Prio Params: Geran Priority = %d", cmd->interRatInfo.servCellPrioParams.geranPriority);
        logPrint(LOG_DEBUG, "** ServCell Prio Params: Thresh Prio Search = %d", cmd->interRatInfo.servCellPrioParams.threshPrioSearch);
        logPrint(LOG_DEBUG, "** ServCell Prio Params: Thresh GSM low = %d", cmd->interRatInfo.servCellPrioParams.threshGsmLow);
        logPrint(LOG_DEBUG, "** ServCell Prio Params: H-Prio = %d", cmd->interRatInfo.servCellPrioParams.hPrio);
        logPrint(LOG_DEBUG, "** ServCell Prio Params: T-Reslection = %d", cmd->interRatInfo.servCellPrioParams.tReselection);
    }

    logPrint(LOG_DEBUG, "** 3G Meas Params: QSearch_I = %d **", cmd->interRatInfo.umtsMeasParams.qSearchI);
    logPrint(LOG_DEBUG, "** 3G Meas Params: qSearchCInit = %d **", cmd->interRatInfo.umtsMeasParams.qSearchCInit);
    logPrint(LOG_DEBUG, "** 3G Meas Params: fddParamsPresent = %d **", cmd->interRatInfo.umtsMeasParams.fddParamsPresent);
    if (cmd->interRatInfo.umtsMeasParams.fddParamsPresent)
    {
        logPrint(LOG_DEBUG, "** 3G Meas Params: fddQmin = %d **", cmd->interRatInfo.umtsMeasParams.fddParams.fddQmin);
        logPrint(LOG_DEBUG, "** 3G Meas Params: fddQoffset = %d **", cmd->interRatInfo.umtsMeasParams.fddParams.fddQoffset);
        logPrint(LOG_DEBUG, "** 3G Meas Params: fddRepQuant = %d **", cmd->interRatInfo.umtsMeasParams.fddParams.fddRepQuant);
        logPrint(LOG_DEBUG, "** 3G Meas Params: fddMultiratReporting = %d **", cmd->interRatInfo.umtsMeasParams.fddParams.fddMultiratReporting);
    }

    logPrint(LOG_DEBUG, "** 3G Default Prio Params: priorityParamsPresent = %d **", cmd->interRatInfo.umtsDefaultPrioParams.priorityParamsPresent);
    if (cmd->interRatInfo.umtsDefaultPrioParams.priorityParamsPresent)
    {
        logPrint(LOG_DEBUG, "** 3G Default Prio Params: utranPriority = %d **", cmd->interRatInfo.umtsDefaultPrioParams.utranPriority);
        logPrint(LOG_DEBUG, "** 3G Default Prio Params: utranQrxlevminDbm = %d **", cmd->interRatInfo.umtsDefaultPrioParams.utranQrxlevminDbm);
        logPrint(LOG_DEBUG, "** 3G Default Prio Params: threshUtranDb = %d **", cmd->interRatInfo.umtsDefaultPrioParams.threshUtranDb);
    }

    logPrint(LOG_DEBUG, "** 3G Neighbor Info: No Of FDD UARFCNS = %d **", cmd->interRatInfo.umtsNeighbors.noOfFddUarfcns);
    for (i = 0; i < cmd->interRatInfo.umtsNeighbors.noOfFddUarfcns; i++)
    {
        logPrint(LOG_DEBUG, "** 3G Neighbor Info: UARFCN[%d] = %d **", i, cmd->interRatInfo.umtsNeighbors.neighFddUarfcn[i].uarfcn);
        logPrint(LOG_DEBUG, "** 3G Neighbor Info: No Of Fdd Cells = %d **", cmd->interRatInfo.umtsNeighbors.neighFddUarfcn[i].noOfCells);
        for (j = 0; j < cmd->interRatInfo.umtsNeighbors.neighFddUarfcn[i].noOfCells; j++)
        {
            logPrint(LOG_DEBUG, "** 3G Neighbor Info: [%d]: PSC               = %d **", j, cmd->interRatInfo.umtsNeighbors.neighFddUarfcn[i].neighFddCell[j].psc);
            logPrint(LOG_DEBUG, "** 3G Neighbor Info:      Diversity-Applied = %d **", cmd->interRatInfo.umtsNeighbors.neighFddUarfcn[i].neighFddCell[j].diversityApplied);
        }
    }

    logPrint(LOG_DEBUG, "** 4G Neighbor Info: No Of EARFCNS = %d **", cmd->interRatInfo.lteNeighbors.noEutranFreqs);
    for (i = 0; i < cmd->interRatInfo.lteNeighbors.noEutranFreqs; i++)
    {
        logPrint(LOG_DEBUG, "** 4G Neighbor Info: [%d]:EARFCN        = %d **", i, cmd->interRatInfo.lteNeighbors.eutranFreq[i].earfcn);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      Meas_BW       = %d **", cmd->interRatInfo.lteNeighbors.eutranFreq[i].eutranMeasBwNrb);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      Priority      = %d **", cmd->interRatInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.eutranPriority);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      Thresh_E_High = %d **", cmd->interRatInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.threshEutranHighDb);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      Thresh_E_Low  = %d **", cmd->interRatInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.threshEutranLowDb);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      E_Qrxlevmin   = %d **", cmd->interRatInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.eutranQrxlevminDbm);
    }
#endif /* FEA_2G_INTER_RAT_MEAS */

    logPrint(LOG_DEBUG, "** No-Of-Hopping Freqs = %d: ** \n", cmd->noOfHoppingNeighbors);
    for (i = 0; i < cmd->noOfHoppingNeighbors; i++)
        logPrint(LOG_DEBUG, "** Hopping ARFCN[%d]   = %d **", i + 1, cmd->hoppingArfcnNeighbors[i]);

    if (trx_g == NULL)
    {
        result = FXL_FAILURE;
    }
    else
    {
        if (cmd->cellIdentity != -1)
        {
            if ((cmd->cellIdentity >= 0) && (cmd->cellIdentity <= 65535))
            {
                trx_g->bts.cell_identity = cmd->cellIdentity;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->lac != -1)
        {
            if ((cmd->lac >= 0) && (cmd->lac <= 65535))
            {
                trx_g->bts.location_area_code = cmd->lac;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->rxlevAccMin != -1)
        {
            if ((cmd->rxlevAccMin >= 0) && (cmd->rxlevAccMin <= 63))
            {
                trx_g->bts.cell_sel_par.rxlev_acc_min = cmd->rxlevAccMin;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->cellReselHyst != -1)
        {
            if ((cmd->cellReselHyst >= 0) && (cmd->cellReselHyst <= 7))
            {
                trx_g->bts.cell_sel_par.cell_resel_hyst = cmd->cellReselHyst;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->msTxpwrMaxCcch != -1)
        {
            if ((cmd->msTxpwrMaxCcch >= 0) && (cmd->msTxpwrMaxCcch <= 31))
            {
                trx_g->bts.cell_sel_par.ms_txpwr_max_ccch = cmd->msTxpwrMaxCcch;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->cbq != -1)
        {
            if ((cmd->cbq >= 0) && (cmd->cbq <= 1))
            {
                trx_g->bts.opt_cell_sel_par.cell_bar_qualify = cmd->cbq;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->cro != -1)
        {
            if ((cmd->cro >= 0) && (cmd->cro <= 63))
            {
                trx_g->bts.opt_cell_sel_par.cell_reselect_offset = cmd->cro;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->tempOffset != -1)
        {
            if ((cmd->tempOffset >= 0) && (cmd->tempOffset <= 7))
            {
                trx_g->bts.opt_cell_sel_par.temp_offset = cmd->tempOffset;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->penaltyTime != -1)
        {
            if ((cmd->penaltyTime >= 0) && (cmd->penaltyTime <= 31))
            {
                trx_g->bts.opt_cell_sel_par.penalty_time = cmd->penaltyTime;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->accessClassList != -1)
        {
            if ((cmd->accessClassList >= 0) && (cmd->accessClassList <= 65535))
            {
                trx_g->bts.access_class_list = cmd->accessClassList;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->cellBarred != -1)
        {
            if ((cmd->cellBarred >= 0) && (cmd->cellBarred <= 1))
            {
                trx_g->bts.rach_ctrl_par.cell_bar = cmd->cellBarred;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->noOfNeighbors != -1)
        {
            if (cmd->noOfNeighbors == 0)
            {
                trx_g->bts.neigh_list.nbr_of_arfcns = 0;
                for (i = 0; i < GERAN_ARFCN_LIST_LENGTH; i++)
                {
                    trx_g->bts.neigh_list.arfcns[i] = END_OF_LIST;
                }
            }
            else if ((cmd->noOfNeighbors > 0) && (cmd->noOfNeighbors <= GERAN_ARFCN_LIST_LENGTH))
            {
                tOCT_UINT8 ignoreList = FALSE;
                for (i = 0; i < cmd->noOfNeighbors; i++)
                {
                    if (cmd->arfcnNeighbors[i] != -1)
                    {
                        /* Only Neighbour ARFCNs belonging to same band are allowed */

                        if (trx_g->bts.band == GSM_450 &&
                            !((cmd->arfcnNeighbors[i] >= 259) && (cmd->arfcnNeighbors[i] <= 293)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_850 &&
                                 !((cmd->arfcnNeighbors[i] >= 128) && (cmd->arfcnNeighbors[i] <= 251)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_900 &&
                                 !((cmd->arfcnNeighbors[i] >= 1) && (cmd->arfcnNeighbors[i] <= 124)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == E_GSM &&
                                 !(((cmd->arfcnNeighbors[i] >= 0) && (cmd->arfcnNeighbors[i] <= 124)) || ((cmd->arfcnNeighbors[i] >= 975) && (cmd->arfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == R_GSM &&
                                 !(((cmd->arfcnNeighbors[i] >= 0) && (cmd->arfcnNeighbors[i] <= 124)) || ((cmd->arfcnNeighbors[i] >= 955) && (cmd->arfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == DCS_1800 &&
                                 !((cmd->arfcnNeighbors[i] >= 512) && (cmd->arfcnNeighbors[i] <= 885)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == PCS_1900 &&
                                 !((cmd->arfcnNeighbors[i] >= 512) && (cmd->arfcnNeighbors[i] <= 810)))
                        {
                            ignoreList = TRUE;
                        }

                        if (ignoreList == FALSE)
                        {
                            trx_g->bts.neigh_list.nbr_of_arfcns = i + 1;
                            trx_g->bts.neigh_list.arfcns[i] = cmd->arfcnNeighbors[i];
                        }
                        else
                            break;
                    }
                }
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->t3212 != -1)
        {
            if ((cmd->t3212 >= 0) && (cmd->t3212 <= 255))
            {
                trx_g->bts.t3212 = cmd->t3212;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

#ifdef FEA_2G_INTER_RAT_MEAS
        if (cmd->interRatInfoPresent > 0)
        {
            memcpy(&trx_g->bts.interRatInfo, &cmd->interRatInfo, sizeof(fxL2gInterRatInfo));

            /* Form the 3G Neighbor cell List from the 3G Neighbor info */
            int j = 0, k = 0, l = 0;

            for (j = 0; j < trx_g->bts.interRatInfo.umtsNeighbors.noOfFddUarfcns; j++)
            {
                for (k = 0; k < trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[j].noOfCells; k++)
                {
                    trx_g->bts.gsm3gNeighCellList[l].uarfcn = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[j].uarfcn;
                    trx_g->bts.gsm3gNeighCellList[l].psc = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[j].neighFddCell[k].psc;
                    l++;
                }
            }
        }
#endif /* FEA_2G_INTER_RAT_MEAS */

        if (cmd->noOfHoppingNeighbors != -1)
        {
            if (cmd->noOfHoppingNeighbors == 0)
            {
                trx_g->bts.neigh_ca_list.nbr_of_arfcns = 0;
                for (i = 0; i < SIZE_OF_HOPPING_LIST; i++)
                {
                    trx_g->bts.neigh_ca_list.arfcns[i] = END_OF_LIST;
                }
            }
            else if ((cmd->noOfHoppingNeighbors > 0) && (cmd->noOfHoppingNeighbors <= SIZE_OF_HOPPING_LIST))
            {
                tOCT_UINT8 ignoreList = FALSE;
                for (i = 0; i < cmd->noOfHoppingNeighbors; i++)
                {
                    if (cmd->hoppingArfcnNeighbors[i] != -1)
                    {
                        /* Only Neighbour ARFCNs belonging to same band are allowed */

                        if (trx_g->bts.band == GSM_450 &&
                            !((cmd->hoppingArfcnNeighbors[i] >= 259) && (cmd->hoppingArfcnNeighbors[i] <= 293)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_850 &&
                                 !((cmd->hoppingArfcnNeighbors[i] >= 128) && (cmd->hoppingArfcnNeighbors[i] <= 251)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_900 &&
                                 !((cmd->hoppingArfcnNeighbors[i] >= 1) && (cmd->hoppingArfcnNeighbors[i] <= 124)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == E_GSM &&
                                 !(((cmd->hoppingArfcnNeighbors[i] >= 0) && (cmd->hoppingArfcnNeighbors[i] <= 124)) ||
                                   ((cmd->hoppingArfcnNeighbors[i] >= 975) && (cmd->hoppingArfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == R_GSM &&
                                 !(((cmd->hoppingArfcnNeighbors[i] >= 0) && (cmd->hoppingArfcnNeighbors[i] <= 124)) ||
                                   ((cmd->hoppingArfcnNeighbors[i] >= 955) && (cmd->hoppingArfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == DCS_1800 &&
                                 !((cmd->hoppingArfcnNeighbors[i] >= 512) && (cmd->hoppingArfcnNeighbors[i] <= 885)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == PCS_1900 &&
                                 !((cmd->hoppingArfcnNeighbors[i] >= 512) && (cmd->hoppingArfcnNeighbors[i] <= 810)))
                        {
                            ignoreList = TRUE;
                        }

                        if (ignoreList == FALSE)
                        {
                            trx_g->bts.neigh_ca_list.nbr_of_arfcns = i + 1;
                            trx_g->bts.neigh_ca_list.arfcns[i] = cmd->hoppingArfcnNeighbors[i];
                        }
                        else
                            break;
                    }
                }
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (result == FXL_SUCCESS)
        {
            if (generateSysInfoMsgs() < 0)
                result = FXL_FAILURE;
        }
    }
#endif
    rsp->result = result;
    rsp->hdr.msgLength = sizeof(fxL2gSysInfoModifyRsp);
    rsp->hdr.msgType = FXL_2G_SYS_INFO_MODIFY_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gSysInfoModifyRsp));
    return;
}
#endif /* FEA_2G_DYNAMIC_SYS_INFO_CONFIG */

void getBlockedCallCounterCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gGetBlockedCallCounterCmd *cmd = (fxL2gGetBlockedCallCounterCmd *)inMsgBuf;
    fxL2gGetBlockedCallCounterRsp *rsp = (fxL2gGetBlockedCallCounterRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);
    // TBD Implement search based on UeIndex
    if (blackUserInfo != NULL)
    {
        rsp->result = FXL_SUCCESS;
        rsp->blockedCallCounter = blackUserInfo->blockedMoCallsCounter;
    }
    else
    {
        rsp->result = FXL_FAILURE;
    }
    rsp->hdr.msgLength = sizeof(fxL2gGetBlockedCallCounterRsp);
    rsp->hdr.msgType = FXL_2G_GET_BLOCKED_CALL_COUNTER_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gGetBlockedCallCounterRsp));
    return;
}

#if 0
void getPhyChannelsUsageStatusCmdHandler(tOCT_UINT8* inMsgBuf)
{
    fxL2gGetPhyChannelsUsageStatusCmd *cmd = (fxL2gGetPhyChannelsUsageStatusCmd*)inMsgBuf;
    fxL2gGetPhyChannelsUsageStatusRsp *rsp = (fxL2gGetPhyChannelsUsageStatusRsp*)msgBuf;

    rsp->hdr.msgLength = sizeof(fxL2gGetPhyChannelsUsageStatusRsp);
    rsp->hdr.msgType = FXL_2G_GET_PHY_CHANNELS_USAGE_STATUS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    rsp->noOfAvailableSDCCH = maxSdcchChannel;
    rsp->noOfUsedSDCCH      = noOfAllocatedLogicalChannels;

    rsp->noOfAvailableTCHF  = maxTchfChannel;
    rsp->noOfUsedTCHF       = noOfAllocatedFullTrafficChannels;

    rsp->noOfAvailableTCHH  = maxTchhChannel;
    rsp->noOfUsedTCHH       = noOfAllocatedHalfTrafficChannels;
    
    rsp->noOfAvailablePDTCH = maxPdtchChannel;
#ifdef FEA_GPRS
    rsp->noOfUsedPDTCH      = noOfAllocatedPdtchChannels;
#else
    rsp->noOfUsedPDTCH      = 0;
#endif
    writeToExternalSocketInterface(msgBuf , sizeof(fxL2gGetPhyChannelsUsageStatusRsp));
    return;
}
#endif

void listenModeConfigureBandsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gListenModeConfigureBandsCmd *cmd = (fxL2gListenModeConfigureBandsCmd *)inMsgBuf;
    fxL2gListenModeConfigureBandsRsp *rsp = (fxL2gListenModeConfigureBandsRsp *)msgBuf;
    static uint8 firstTimeScan = TRUE;
    rsp->result = FXL_FAILURE;
    if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
        currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
        currentDspImage == FXL_L1_LTE_SLS_IMAGE)
    {

        configureWnmParameters(cmd);
        logPrint(LOG_DEBUG, "GSM scan listenModeConfigureBandsCmdHandler :: ConfigurewnmParameters \n");
        rsp->result = FXL_SUCCESS;
    }
    rsp->hdr.msgLength = sizeof(fxL2gListenModeConfigureBandsRsp);
    rsp->hdr.msgType = FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gListenModeConfigureBandsRsp));

    if ((reInitialiseGsmScanData(cmd) != FALSE) || (firstTimeScan == TRUE))
    {
        bandMap = 0;
        // Create SI info file, erase if already exist(older run)
        FILE *siInfoFile = NULL;
        char *FileName = "/home/wgs/GsmSysInfo.txt";

        siInfoFile = fopen(FileName, "wt");
        if (siInfoFile != NULL)
        {
            fclose(siInfoFile);
            siInfoFile = NULL;
        }
        else
        {
            fprintf(stderr, "Error: can't create %s\n", FileName);
        }
    }
    firstTimeScan = FALSE;
    return;
}

void listenModeStartScanCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gListenModeStartScanCmd *cmd = (fxL2gListenModeStartScanCmd *)inMsgBuf;
    fxL2gListenModeStartScanRsp *rsp = (fxL2gListenModeStartScanRsp *)msgBuf;
    rsp->result = FXL_FAILURE;
    if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
        currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
        currentDspImage == FXL_L1_LTE_SLS_IMAGE)
    {
        scanMode = cmd->scanType;
        if (createAndStartListenModeThread() == -1)
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Threads are not created \n");
        }
        else
        {
            logPrint(LOG_DEBUG, "Starting GSM Scanner....\n");
            currentOneBinState = ONEBIN_STATE_2G_SCANNING;
            rsp->result = FXL_SUCCESS;
        }
    }
    rsp->hdr.msgLength = sizeof(fxL2gListenModeStartScanRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_LISTEN_MODE_START_SCAN_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gListenModeStartScanRsp));

    return;
}

void listenModeStopScanCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gListenModeStopScanCmd *cmd = (fxL2gListenModeStopScanCmd *)inMsgBuf;
    fxL2gListenModeStopScanRsp *rsp = (fxL2gListenModeStopScanRsp *)msgBuf;
    rsp->result = FXL_FAILURE;

    if (currentOneBinState == ONEBIN_STATE_2G_SCANNING)
    {
        currentOneBinState = ONEBIN_STATE_IDLE;

        if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
            currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
            currentDspImage == FXL_L1_LTE_SLS_IMAGE)
        {
            rsp->result = stopListenModeApplication();

            if (rsp->result == FXL_SUCCESS)
            {
                // clear the global variale context of earlier run
                bcchBufferCellId = 0xFFFF;
                si1Cell = 0xFFFFFFF0;
                si2Cell = 0xFFFFFFF1;
                si2qCell = 0xFFFFFFF2;
                si2bisCell = 0xFFFFFFF3;
                si2terCell = 0xFFFFFFF4;
                si3Cell = 0xFFFFFFF5;
                si4Cell = 0xFFFFFFF6;
                scanMode = FXL_SCAN_TYPE_EXHAUSTIVE;
            }
        }

        if (cmd->dspResetNeeded == 1)
        {
            unsigned int retCode = 0;
            /* Fill the Details */
            if ((isItPrimaryDsp() == TRUE))
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                retCode = g_Commands[12]->pfctCallBack(2, argValue);
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "Reset the primary DSP retCode = %d\n", retCode);
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                retCode = g_Commands[12]->pfctCallBack(2, argValue);
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "Reset the secondary DSP retCode = %d\n", retCode);
            }
        }
    }

    rsp->hdr.msgLength = sizeof(fxL2gListenModeStopScanRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_LISTEN_MODE_STOP_SCAN_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gListenModeStopScanRsp));

    return;
}

unsigned int checkAndLoadRUSL1Image(fxLDspType dspType)
{
    unsigned int retCode = -1;
    if (dspType == FXL_PRIMARY_DSP)
    {
        char *argValue[3] = {"dr", "-p", "RAT_SLS.img"};
        optreset = 1;
        retCode = g_Commands[12]->pfctCallBack(3, argValue);
    }
    else
    {
        char *argValue[3] = {"dr", "-s", "RAT_SLS.img"};
        optreset = 1;
        retCode = g_Commands[12]->pfctCallBack(3, argValue);
    }

    return retCode;
}
void bootL1CmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLBootL1Cmd *cmd = (fxLBootL1Cmd *)inMsgBuf;
    fxLBootL1Rsp *rsp = (fxLBootL1Rsp *)msgBuf;
    rsp->result = FXL_FAILURE;
#ifndef PUMP_REG_DATA
    bootL1InProgress = 1;
    setNetworkDriverPriorityForLte(FALSE);

#ifdef FXL_3G_TX_JAMMER
    jammer3gPsc.dspType = cmd->dspType;
#endif

    /* BASS */
    if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_BASS_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-p", "RAT_BASS.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_BASS_IMAGE;
        }

        rsp->hdr.rat = cmd->hdr.rat;
    }

    if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_BASS_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-s", "RAT_BASS.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_BASS_IMAGE;
        }

        rsp->hdr.rat = cmd->hdr.rat;
    }

    /* 2G */
    if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_GSM_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_GSM_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_2G;
    }
    else if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_GSM_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-p", "GSM_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_GSM_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_2G;
    }
    if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_GSM_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_GSM_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_2G;
    }
    else if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_GSM_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-s", "GSM_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_GSM_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_2G;
    }
    // UMTS
    if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_UMTS_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_UMTS_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_3G;
    }
    else if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_UMTS_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-p", "UMTS_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_UMTS_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_3G;
    }
    if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_UMTS_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_UMTS_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_3G;
    }
    else if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_UMTS_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-s", "UMTS_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_UMTS_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_3G;
    }
    // LTE
    if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_LTE_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_LTE_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_4G;
    }
    else if ((isItPrimaryDsp() == TRUE) && (cmd->dspType == FXL_PRIMARY_DSP) && (cmd->l1ImageType == FXL_L1_LTE_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-p", "LTE_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_LTE_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_4G;
    }
    if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_LTE_SLS_IMAGE))
    {
        if (checkAndLoadRUSL1Image(cmd->dspType) == 0)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_LTE_SLS_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_4G;
    }
    else if ((isItPrimaryDsp() == FALSE) && (cmd->dspType == FXL_SECONDARY_DSP) && (cmd->l1ImageType == FXL_L1_LTE_NATIVE_IMAGE))
    {
        unsigned int retCode = 0;

        /* Fill the Details */
        char *argValue[3] = {"dr", "-s", "LTE_NATIVE.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, argValue);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            currentDspImage = FXL_L1_LTE_NATIVE_IMAGE;
        }

        rsp->hdr.rat = FXL_RAT_4G;
    }

    sleep(6);

    if (isItPrimaryDsp() == TRUE)
    {
        dspType = FXL_PRIMARY_DSP;

        {
            if (-1 == system("/home/wgs/scripts/setGPSPri.sh"))
            {
                logPrint(LOG_DEBUG, ": GPS setting failed\n");
            }
        }
    }
    else
    {
        dspType = FXL_SECONDARY_DSP;
        {
            if (-1 == system("/home/wgs/scripts/setGPSSec.sh"))
            {
                logPrint(LOG_DEBUG, ": GPS setting failed\n");
            }
        }
    }

#else
    rsp->result = FXL_SUCCESS;
    currentDspImage = cmd->l1ImageType;
#endif
    logPrint(LOG_DEBUG, "Boot L1 cmd received with dspType = %d , imageType = %d , result = %d \n", cmd->dspType, cmd->l1ImageType, rsp->result);
    rsp->hdr.msgLength = sizeof(fxLBootL1Rsp);
    rsp->hdr.msgType = FXL_BOOT_L1_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLBootL1Rsp));

    bootL1InProgress = 0;

    return;
}

void buildAndSendGpsStatusInd(fxLRat ratType)
{
    fxLGpsStatusInd gpsStatusInd;

    /* Send GPS Status Indication to External Client */
    memset((fxLGpsStatusInd *)&gpsStatusInd, 0, sizeof(fxLGpsStatusInd));

    /* Fill Header */
    gpsStatusInd.hdr.msgLength = sizeof(fxLGpsStatusInd);
    gpsStatusInd.hdr.rat = ratType;
    gpsStatusInd.hdr.msgType = FXL_GPS_STATUS_IND;

    /* Fill GPS Fix Value */
    gpsStatusInd.gpsFixType = idCatcherGpsFix;

    /* Fill GPS Location */
    gpsStatusInd.gpsLocation.latitude = idCatcherGpsLoc.latitude;
    gpsStatusInd.gpsLocation.longitude = idCatcherGpsLoc.longitude;
    gpsStatusInd.gpsLocation.altitude = idCatcherGpsLoc.altitude;

    if (-1 != clientFd)
    {
        if (send(clientFd, &gpsStatusInd, sizeof(fxLGpsStatusInd), 0) < 0)
        {
            logPrint(LOG_DEBUG, "Send GPS Status Indication is failed....\n");
        }
        else
        {
            logPrint(LOG_DEBUG, "GPS Status Indication is sent....\n");
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "Send GPS Status Indication failed, clientFd = -1....\n");
    }
}

void *gpsMonitor(fxLRat *ratType)
{
    struct timespec sleepTime;
    unsigned int retCode = 0;

    while (1)
    {
        sleepTime.tv_sec = 2;
        sleepTime.tv_nsec = 0;
        nanosleep(&sleepTime, NULL);

        /* Get Gps Status */
        char *gsArgValue[1] = {"gs"};
        optreset = 1;

        retCode = g_Commands[20]->pfctCallBack(1, gsArgValue);

        if (0 == retCode)
        {
            if (FXL_GPS_FIX_NONE != idCatcherGpsFix)
            {
                /* Read register value and store value in a file */
                if (-1 == system("oct2200cat r 0x9009c018 > /home/wgs/scripts/gps_val.bin"))
                {
                    logPrint(LOG_DEBUG, "Reading GPS value from register failed...\n");
                }

                /* Send GPS Status Indication */
                buildAndSendGpsStatusInd(*ratType);

                if (FXL_GPS_FIX_3D == idCatcherGpsFix)
                {
                    /* Write DAC value */
                    char *cwArgValue[1] = {"cw"};
                    optreset = 1;
                    retCode = g_Commands[10]->pfctCallBack(1, cwArgValue);
                }
                sleepTime.tv_sec = 2;
                sleepTime.tv_nsec = 0;
                nanosleep(&sleepTime, NULL);
            }
        }
        else
        {
            logPrint(LOG_DEBUG, "gps_status failed....\n");
        }
    }

    return NULL;
}

void enableGpsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLEnableGpsCmd *cmd = (fxLEnableGpsCmd *)inMsgBuf;
    fxLEnableGpsRsp *rsp = (fxLEnableGpsRsp *)msgBuf;

    rsp->result = FXL_FAILURE;

    /* Clear the GPS Location Information */
    memset((fxLGpsLocation *)&idCatcherGpsLoc, 0, sizeof(fxLGpsLocation));
    idCatcherGpsFix = FXL_GPS_FIX_NONE;

    unsigned int retCode = 0;

    char *boardInfoArgValue[1] = {"bi"};
    optreset = 1;

    retCode = g_Commands[2]->pfctCallBack(1, boardInfoArgValue);
    if (2 == numberOfDsp)
    {
        /* Fill the Details */
        char *drArgValue[3] = {"dr", "-s", "RAT_SLS.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, drArgValue);

        logPrint(LOG_DEBUG, "Sec DSP reset for GPS settings ....\n");
        if (0 != retCode)
        {
            logPrint(LOG_DEBUG, "Sec DSP reset failed ....\n");
        }
        sleep(5);
    }
    {
        /* Fill the Details */
        char *drArgValue[3] = {"dr", "-p", "RAT_SLS.img"};
        optreset = 1;

        retCode = g_Commands[12]->pfctCallBack(3, drArgValue);

        if (0 == retCode)
        {
            sleep(5);

            sleep(2);
            /* Set Clock Input as GPS */
            char *ciArgValue[2] = {"ci", "gps"};
            optreset = 1;

            retCode = g_Commands[26]->pfctCallBack(2, ciArgValue);

            if (0 == retCode)
            {
                if (0 == pthread_attr_init(&gGpsMonitorAttr))
                {
                    if (0 == pthread_create(&gGpsMonitorThreadId, &gGpsMonitorAttr, gpsMonitor, &cmd->hdr.rat))
                    {
                        gpsStarted = 1;
                        rsp->result = FXL_SUCCESS;
                    }
                    else
                    {
                        logPrint(LOG_DEBUG, "GPS Monitor Thread Creation failed....\n");
                    }
                }
                else
                {
                    logPrint(LOG_DEBUG, "GPS Monitor Thread Attribute Init failed....\n");
                }
            }
            else
            {
                logPrint(LOG_DEBUG, "ref_clock_in gps failed....\n");
            }
        }
        else
        {
            logPrint(LOG_DEBUG, "Loading Packet API Image failed....\n");
        }
    }
    sleep(2);
    rsp->hdr.msgLength = sizeof(fxLEnableGpsRsp);
    rsp->hdr.msgType = FXL_ENABLE_GPS_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLEnableGpsRsp));
}

void stopGpsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLStopGpsCmd *cmd = (fxLStopGpsCmd *)inMsgBuf;
    fxLStopGpsRsp *rsp = (fxLStopGpsRsp *)msgBuf;
    gpsStarted = 0;

    if (pthread_cancel(gGpsMonitorThreadId))
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        rsp->result = FXL_SUCCESS;
        memset((pthread_t *)&gGpsMonitorThreadId, 0, sizeof(pthread_t));
        memset((pthread_attr_t *)&gGpsMonitorAttr, 0, sizeof(pthread_attr_t));
    }

    char *argValue[2] = {"dr", "-p"};
    optreset = 1;
    g_Commands[12]->pfctCallBack(2, argValue);

    rsp->hdr.msgLength = sizeof(fxLStopGpsRsp);
    rsp->hdr.msgType = FXL_STOP_GPS_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLStopGpsRsp));

    return;
}

void sendTxCalibrationRsp(fxLResult result, int cause, fxLRat ratType)
{
    fxLEnableTxCalibrationRsp txCalibrationRsp;

    /* Send GPS Status Indication to External Client */
    memset((fxLEnableTxCalibrationRsp *)&txCalibrationRsp, 0, sizeof(fxLEnableTxCalibrationRsp));

    /* Fill Header */
    txCalibrationRsp.hdr.msgLength = sizeof(fxLEnableTxCalibrationRsp);
    txCalibrationRsp.hdr.rat = ratType;
    txCalibrationRsp.hdr.msgType = FXL_ENABLE_TX_CALIBRATION_RSP;

    txCalibrationRsp.result = result;
    txCalibrationRsp.failureCause = cause;

    if (-1 != clientFd)
    {
        if (send(clientFd, &txCalibrationRsp, sizeof(fxLEnableTxCalibrationRsp), 0) < 0)
        {
            logPrint(LOG_DEBUG, "Send TX Calibration Response failed....\n");
        }
        else
        {
            logPrint(LOG_DEBUG, "TX Calibration Response is sent....\n");
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "Send TX Calibration Response failed, clientFd = -1....\n");
    }
}

void enableTxCalibration(tOCT_UINT8 *inMsgBuf)
{
    fxLEnableTxCalibrationCmd *cmd = (fxLEnableTxCalibrationCmd *)inMsgBuf;

    if (currentOneBinState == ONEBIN_STATE_2G_IDCATCHING)
    {
        enableTxCalibrationFor2G();
    }
    else if (currentOneBinState == ONEBIN_STATE_4G_IDCATCHING)
    {
        enableTxCalibrationFor4G();
    }
    else if (currentOneBinState == ONEBIN_STATE_3G_IDCATCHING)
    {
        enableTxCalibrationFor3G();
    }
    else
    {
        sendTxCalibrationRsp(FXL_FAILURE, 0, cmd->hdr.rat);
    }
}

void changeTxRxAntennaIdCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxLChangeTxRxAntennaIdCmd *cmd = (fxLChangeTxRxAntennaIdCmd *)inMsgBuf;
    fxLChangeTxRxAntennaIdRsp *rsp = (fxLChangeTxRxAntennaIdRsp *)msgBuf;

    if ((FXL_TX_RX_ANTENNA_ID_0 == cmd->txAntennaId) || (FXL_TX_RX_ANTENNA_ID_1 == cmd->txAntennaId) ||
        (FXL_TX_RX_ANTENNA_ID_0 == cmd->rxAntennaId) || (FXL_TX_RX_ANTENNA_ID_1 == cmd->rxAntennaId))
    {
        if ((TRUE == isItPrimaryDsp()) && (FXL_PRIMARY_DSP == cmd->dspType))
        {
            txAntennaIdPri = cmd->txAntennaId;
            rxAntennaIdPri = cmd->rxAntennaId;
            rsp->result = FXL_SUCCESS;
        }
        else if ((FALSE == isItPrimaryDsp()) && (FXL_SECONDARY_DSP == cmd->dspType))
        {
            txAntennaIdSec = cmd->txAntennaId;
            rxAntennaIdSec = cmd->rxAntennaId;
            rsp->result = FXL_SUCCESS;
        }
        else
        {
            rsp->result = FXL_FAILURE;
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
    }
    rsp->hdr.msgLength = sizeof(fxLChangeTxRxAntennaIdRsp);
    rsp->hdr.msgType = FXL_CHANGE_TX_RX_ANTENNA_ID_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLChangeTxRxAntennaIdRsp));

    return;
}

void stop2gIdcatcherCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gStopIdCatcherRsp *rsp = (fxL2gStopIdCatcherRsp *)msgBuf;
    fxL2gStopIdCatcherCmd *cmd = (fxL2gStopIdCatcherCmd *)inMsgBuf;
#ifndef PUMP_REG_DATA
    rsp->result = FXL_FAILURE;

#ifdef FEA_PICSIX_CHANGE
    timerStop(&systemStatusTimer);

    if (NULL != systemStatusTimer.parm)
    {
        free(systemStatusTimer.parm);
        systemStatusTimer.parm = NULL;
    }
    memset((tcbTimer_t *)&systemStatusTimer, 0, sizeof(tcbTimer_t));
#endif

    if (currentDspImage == FXL_L1_GSM_NATIVE_IMAGE)
    {
        exitGsmAppThreads = 1;
        rsp->result = octasicBtsStop();
        exitGsmAppThreads = 0;
        deleteAllUsers();
        deleteGsmLatchedUsers();
        deleteAllBlacklistUsers();
#ifdef FEA_GPRS
        deleteAllGprsUsers();
#endif
        destroyThreadsForGsmNativeApp();

        if (cmd->dspResetNeeded == TRUE)
        {
            if (isItPrimaryDsp() == TRUE)
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
        }
    }
#else
    rsp->result = FXL_SUCCESS;
    stopPumpData();
#endif
    rsp->hdr.msgLength = sizeof(fxL2gStopIdCatcherRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_STOP_IDCATCHER_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gStopIdCatcherRsp));

    return;
}

void configureGsmFreqForSelectiveScanCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gListenModeConfigureSelectiveFreqRsp *rsp = (fxL2gListenModeConfigureSelectiveFreqRsp *)msgBuf;
    fxL2gListenModeConfigureSelectiveFreqCmd *cmd = (fxL2gListenModeConfigureSelectiveFreqCmd *)inMsgBuf;

    rsp->result = configureGsmFreqForSelectiveScan(cmd);
    rsp->hdr.msgLength = sizeof(fxL2gListenModeConfigureSelectiveFreqRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gListenModeConfigureSelectiveFreqRsp));

    return;
}
#ifdef FEA_SILENT_CALL

void startSilentCallCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gStartSilentCallCmd *cmd = (fxL2gStartSilentCallCmd *)inMsgBuf;
    fxL2gStartSilentCallRsp *rsp = (fxL2gStartSilentCallRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = NULL;
    logPrint(LOG_DEBUG, "** 2G_START_SILENT_CALL_CMD Received : IMSI = %s, Purpose = %d  \n", cmd->imsiStr, cmd->purpose);
#ifdef CELL_BAR_IN_GSM_TCH_SC
    logPrint(LOG_DEBUG, "Cell-Bar = %d **\n", cmd->cellBarOption);
#endif
    tOCT_UINT8 tchAvailable = FALSE;

    pthread_mutex_lock(&mutexGsmChannelMgr);
    if ((noOfAllocatedFullTrafficChannels < maxTchfChannel) ||
        (noOfAllocatedHalfTrafficChannels < maxTchhChannel))
        tchAvailable = TRUE;
    pthread_mutex_unlock(&mutexGsmChannelMgr);

    if (cmd->purpose == FXL_TCH_SILENT_CALL && tchAvailable == FALSE)
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "All TCH Channels are already occupied");
    }
    else if (cmd->purpose == FXL_TCH_SILENT_CALL && isTimeSlotTypeSupportsTCHF(7) == FALSE)
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Configured Timeslot(7) doesn't support TCH/F\n");
    }
    else if (cmd->purpose == FXL_TCH_SILENT_CALL && logicalChannels[7][0] != EMPTY)
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Requested TS(7) for TCH Silent Call is already occupied");
    }
    else if (cmd->purpose == FXL_TCH_SILENT_CALL && tchSilentCallUnderProgress == TRUE)
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Other TCH silent call under progress\n");
    }
    else if (targetVoiceCallCntxt.isOnGoingCall &&
             (((targetVoiceCallCntxt.moImsiStr != NULL) && (memcmp(cmd->imsiStr, targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0)) ||
              ((targetVoiceCallCntxt.mtImsiStr != NULL) && (memcmp(cmd->imsiStr, targetVoiceCallCntxt.mtImsiStr, MAX_IDENTITY_LENGTH_STR) == 0))))
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Silent call cannot be started as voice call is in progress for the IMSI(%s)", cmd->imsiStr);
    }
    else
    {
        blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);
        // TBD Implement search based on UeIndex

        if (blackUserInfo != NULL)
        {
            if (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
                ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))
            {
                rsp->result = FXL_FAILURE;
                logPrint(LOG_ERR, "Silent Call is already in progress for this IMSI(%s)", cmd->imsiStr);
            }
            else
            {
                if (cmd->purpose == FXL_TCH_SILENT_CALL)
                {
                    blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_TCH_SILENT_CALL;
                    tchSilentCallUnderProgress = TRUE;
#ifdef CELL_BAR_IN_GSM_TCH_SC
                    if (cmd->cellBarOption == FXL_TCH_SILENT_CALL_CELL_BARRED_ON)
                        cellBarDuringTchSilentCall = TRUE;
                    else
#endif
                        cellBarDuringTchSilentCall = FALSE;
                }
                else
                    blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_SDCCH_SILENT_CALL;

                blackUserInfo->muteDlPwrDuringSilentCall = FALSE;
                blackUserInfo->timeSlotForTchSilentCall = 7;

                blackUserInfo->triggerPagingReq = TRUE;
                pushPagingReqToPageQ(blackUserInfo);

                rsp->result = FXL_SUCCESS;
            }
        }
        else
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Could not find IMSI in blacklist list\n");
        }
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gStartSilentCallRsp);
    rsp->hdr.msgType = FXL_2G_START_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gStartSilentCallRsp));
    return;
}

void modifyUeTxPowerCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gModifyUeTxPowerCmd *cmd = (fxL2gModifyUeTxPowerCmd *)inMsgBuf;
    fxL2gModifyUeTxPowerRsp *rsp = (fxL2gModifyUeTxPowerRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);
    // TBD Implement search based on UeIndex
    if (blackUserInfo != NULL)
    {
        if (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)
#ifdef FEA_2G_ENH_TCH_SILENT_CALL
            || ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
#endif
        )
        {
            blackUserInfo->uplinkPowerdBm = cmd->newPowerLeveldBm;
            rsp->result = FXL_SUCCESS;
        }
        else
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Tx Power modification can be done only if Silent Call is going on\n");
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in blacklist list\n");
    }
    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gModifyUeTxPowerRsp);
    rsp->hdr.msgType = FXL_2G_MODIFY_UE_TX_POWER_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gModifyUeTxPowerRsp));
    return;
}

void endSilentCallCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gEndSilentCallCmd *cmd = (fxL2gEndSilentCallCmd *)inMsgBuf;
    fxL2gEndSilentCallRsp *rsp = (fxL2gEndSilentCallRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);

    // TBD Implement search based on UeIndex
    if (blackUserInfo != NULL)
    {
        if ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
        {
            tchSilentCallUnderProgress = FALSE;
            cellBarDuringTchSilentCall = FALSE;
        }

        if (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL) ||
            ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL))
        {
            blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_END_SILENT_CALL;
            blackUserInfo->triggerPagingReq = FALSE;

            if (blackUserInfo->muteDlPwrDuringSilentCall == TRUE)
            {
                blackUserInfo->muteDlPwrDuringSilentCall = FALSE;

                /* Reset TS Digital Scaling */
                GsmTrxResetDigitalScaling();
            }
            /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
            if ((isTimerRunning(&blackUserInfo->tmr) == TRUE) && (configUeIdList.defaultConfig == BLACKLIST))
            {
                tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr, (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212), (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212), &periodicTimerexpiry, blackUserInfo);
                if (retVal == RC_TCB_OK)
                    logPrint(LOG_DEBUG, "PERIODIC LOCATION UPDATE timer restarted after silent call ");
            }
            rsp->result = FXL_SUCCESS;
        }
        else
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Silent Call was not started for this user\n");
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in blacklist list\n");
    }
    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gEndSilentCallRsp);
    rsp->hdr.msgType = FXL_2G_END_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gEndSilentCallRsp));
    return;
}

void silentCallDedSysInfoModifyCmd(tOCT_UINT8 *inMsgBuf)
{
    fxL2gSilentCallDedSysInfoModifyCmd *cmd = (fxL2gSilentCallDedSysInfoModifyCmd *)inMsgBuf;
    fxL2gSilentCallDedSysInfoModifyRsp *rsp = (fxL2gSilentCallDedSysInfoModifyRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);
    fxLResult result = FXL_SUCCESS;
    uint8 i, j = 0;

    logPrint(LOG_DEBUG, "** 2G_SILENT_CALL_DED_SYS_INFO_MODIFY_CMD Received : ** \n");
    logPrint(LOG_DEBUG, "** SI6: CELL-ID = %d, LAC = %d **\n", cmd->si6Info.cellId, cmd->si6Info.lac);
    logPrint(LOG_DEBUG, "** SI5: No-Of-Neighbours    = %d: ** \n", cmd->si5Info.noOfNeighbors);
    for (i = 0; i < cmd->si5Info.noOfNeighbors; i++)
        logPrint(LOG_DEBUG, "** Neighbour ARFCN[%d] = %d **", i + 1, cmd->si5Info.arfcnNeighbors[i]);
#ifdef FEA_2G_INTER_RAT_MEAS

    logPrint(LOG_DEBUG, "** 3G Meas Params: QSearch_C = %d **", cmd->measInfo.umtsMeasParams.qSearchC);
    logPrint(LOG_DEBUG, "** 3G Meas Params: fddRepQuant = %d **", cmd->measInfo.umtsMeasParams.fddRepQuant);
    logPrint(LOG_DEBUG, "** 3G Meas Params: fddMultiratReporting = %d **", cmd->measInfo.umtsMeasParams.fddMultiratReporting);

    logPrint(LOG_DEBUG, "** 3G Neighbor Info: No Of FDD UARFCNS = %d **", cmd->measInfo.umtsNeighbors.noOfFddUarfcns);
    for (i = 0; i < cmd->measInfo.umtsNeighbors.noOfFddUarfcns; i++)
    {
        logPrint(LOG_DEBUG, "** 3G Neighbor Info: UARFCN[%d] = %d **", i, cmd->measInfo.umtsNeighbors.neighFddUarfcn[i].uarfcn);
        logPrint(LOG_DEBUG, "** 3G Neighbor Info: No Of Fdd Cells = %d **", cmd->measInfo.umtsNeighbors.neighFddUarfcn[i].noOfCells);
        for (j = 0; j < cmd->measInfo.umtsNeighbors.neighFddUarfcn[i].noOfCells; j++)
        {
            logPrint(LOG_DEBUG, "** 3G Neighbor Info: [%d]: PSC               = %d **", j, cmd->measInfo.umtsNeighbors.neighFddUarfcn[i].neighFddCell[j].psc);
            logPrint(LOG_DEBUG, "** 3G Neighbor Info:      Diversity-Applied = %d **", cmd->measInfo.umtsNeighbors.neighFddUarfcn[i].neighFddCell[j].diversityApplied);
        }
    }

    logPrint(LOG_DEBUG, "** 4G Meas Params: QSearch_C_EUTRAN = %d **", cmd->measInfo.lteMeasParams.qSearchC_Eutran);
    logPrint(LOG_DEBUG, "** 4G Meas Params: eutranRepQuant = %d **", cmd->measInfo.lteMeasParams.eutranRepQuant);
    logPrint(LOG_DEBUG, "** 4G Meas Params: eutranMultiratReporting = %d **", cmd->measInfo.lteMeasParams.eutranMultiratReporting);

    logPrint(LOG_DEBUG, "** 4G Neighbor Info: No Of EARFCNS = %d **", cmd->measInfo.lteNeighbors.noEutranFreqs);
    for (i = 0; i < cmd->measInfo.lteNeighbors.noEutranFreqs; i++)
    {
        logPrint(LOG_DEBUG, "** 4G Neighbor Info: [%d]: EARFCN        = %d **", i, cmd->measInfo.lteNeighbors.eutranFreq[i].earfcn);
        logPrint(LOG_DEBUG, "** 4G Neighbor Info:      Meas_BW       = %d **", cmd->measInfo.lteNeighbors.eutranFreq[i].eutranMeasBwNrb);
    }
#endif /* FEA_2G_INTER_RAT_MEAS */

    if (blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
                                  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)))
    {
        if (cmd->si5Info.noOfNeighbors != -1)
        {
            tOCT_UINT8 i = 0;

            if (cmd->si5Info.noOfNeighbors == 0)
            {
                memcpy(blackUserInfo->si5Buf, si5Buf, GSM_MACBLOCK_LEN - 4);

                blackUserInfo->si5Neighbors.nbr_of_arfcns = 0;
                for (i = 0; i < GERAN_ARFCN_LIST_LENGTH; i++)
                {
                    blackUserInfo->si5Neighbors.arfcns[i] = END_OF_LIST;
                }
            }
            else if ((cmd->si5Info.noOfNeighbors > 0) && (cmd->si5Info.noOfNeighbors <= GERAN_ARFCN_LIST_LENGTH))
            {
                tOCT_UINT8 ignoreList = FALSE, ret = 0;

                for (i = 0; i < cmd->si5Info.noOfNeighbors; i++)
                {
                    if (cmd->si5Info.arfcnNeighbors[i] != -1)
                    {
                        /* Only Neighbour ARFCNs belonging to same band are allowed */

                        if (trx_g->bts.band == GSM_450 &&
                            !((cmd->si5Info.arfcnNeighbors[i] >= 259) && (cmd->si5Info.arfcnNeighbors[i] <= 293)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_850 &&
                                 !((cmd->si5Info.arfcnNeighbors[i] >= 128) && (cmd->si5Info.arfcnNeighbors[i] <= 251)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == GSM_900 &&
                                 !((cmd->si5Info.arfcnNeighbors[i] >= 1) && (cmd->si5Info.arfcnNeighbors[i] <= 124)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == E_GSM &&
                                 !(((cmd->si5Info.arfcnNeighbors[i] >= 0) && (cmd->si5Info.arfcnNeighbors[i] <= 124)) || ((cmd->si5Info.arfcnNeighbors[i] >= 975) && (cmd->si5Info.arfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == R_GSM &&
                                 !(((cmd->si5Info.arfcnNeighbors[i] >= 0) && (cmd->si5Info.arfcnNeighbors[i] <= 124)) || ((cmd->si5Info.arfcnNeighbors[i] >= 955) && (cmd->si5Info.arfcnNeighbors[i] <= 1023))))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == DCS_1800 &&
                                 !((cmd->si5Info.arfcnNeighbors[i] >= 512) && (cmd->si5Info.arfcnNeighbors[i] <= 885)))
                        {
                            ignoreList = TRUE;
                        }
                        else if (trx_g->bts.band == PCS_1900 &&
                                 !((cmd->si5Info.arfcnNeighbors[i] >= 512) && (cmd->si5Info.arfcnNeighbors[i] <= 810)))
                        {
                            ignoreList = TRUE;
                        }

                        if (ignoreList == FALSE)
                        {
                            blackUserInfo->si5Neighbors.nbr_of_arfcns = i + 1;
                            blackUserInfo->si5Neighbors.arfcns[i] = cmd->si5Info.arfcnNeighbors[i];
                        }
                        else
                            break;
                    }
                }

                if (blackUserInfo->si5Neighbors.nbr_of_arfcns > 0)
                {
                    ret = generate_bcch_frequency_list(&blackUserInfo->si5Buf[3], blackUserInfo->si5Neighbors.nbr_of_arfcns, blackUserInfo->si5Neighbors.arfcns);

                    if (ret < 0)
                        result = FXL_FAILURE;
                }
                else
                {
                    memcpy(blackUserInfo->si5Buf, si5Buf, GSM_MACBLOCK_LEN - 4);
                }
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->si6Info.cellId != -1)
        {
            if ((cmd->si6Info.cellId >= 0) && (cmd->si6Info.cellId <= 65535))
            {
                tOCT_UINT16 cellId = htons((tOCT_UINT16)cmd->si6Info.cellId);
                memcpy(&blackUserInfo->si6Buf[3], &cellId, sizeof(tOCT_UINT16));
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

        if (cmd->si6Info.lac != -1)
        {
            if ((cmd->si6Info.lac >= 0) && (cmd->si6Info.lac <= 65535))
            {
                memcpy(&blackUserInfo->si6Buf[5], getLaiFromSysInfo(), 5);

                blackUserInfo->si6Buf[8] = cmd->si6Info.lac >> 8;
                blackUserInfo->si6Buf[9] = cmd->si6Info.lac & 0xFF;
            }
            else
            {
                result = FXL_FAILURE;
            }
        }

#ifdef FEA_2G_INTER_RAT_MEAS
        if (cmd->interRatMeasInfoPresent > 0)
        {
            memcpy(&blackUserInfo->measInfo, &cmd->measInfo, sizeof(fxL2gInterRatMeasInfo));

            /* Form the 3G Neighbor cell List from the 3G Neighbor info */
            int j = 0, k = 0, l = 0;

            for (j = 0; j < blackUserInfo->measInfo.umtsNeighbors.noOfFddUarfcns; j++)
            {
                for (k = 0; k < blackUserInfo->measInfo.umtsNeighbors.neighFddUarfcn[j].noOfCells; k++)
                {
                    blackUserInfo->gsm3gNeighCellList[l].uarfcn = blackUserInfo->measInfo.umtsNeighbors.neighFddUarfcn[j].uarfcn;
                    blackUserInfo->gsm3gNeighCellList[l].psc = blackUserInfo->measInfo.umtsNeighbors.neighFddUarfcn[j].neighFddCell[k].psc;
                    l++;
                }
            }

            /* Generate MI Buffers */
            generateMeasInfoBuffers(blackUserInfo);
        }
#endif /* FEA_2G_INTER_RAT_MEAS */
    }
    else
    {
        result = FXL_FAILURE;
        logPrint(LOG_ERR, "Dedicated SYS-INFO modification can be done only if Silent Call is going on\n");
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->result = result;
    rsp->hdr.msgLength = sizeof(fxL2gSilentCallDedSysInfoModifyRsp);
    rsp->hdr.msgType = FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gSilentCallDedSysInfoModifyRsp));
    return;
}
#endif /* FEA_SILENT_CALL */

void send2gListenModeScanCompInd(void)
{

    fxL2gListenModeScanCompleteInd *ind = (fxL2gListenModeScanCompleteInd *)msgBuf;

    ind->hdr.msgLength = sizeof(fxL2gListenModeScanCompleteInd);
    ind->hdr.msgType = FXL_2G_LISTEN_MODE_SCAN_COMPLETE_IND;
    ind->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gListenModeScanCompleteInd));

    return;
}

#ifdef FEA_MT_SMS
void sendIndividualSmsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gSendIndividualSmsCmd *sendSms = (fxL2gSendIndividualSmsCmd *)inMsgBuf;
    fxL2gSendIndividualSmsRsp *rsp = (fxL2gSendIndividualSmsRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(sendSms->imsiStr), FALSE, FALSE);

    /* Check the validity of MSISDN,
     * i.e., first char is '+' and rest are all numbers
     * with total length not exceeding 15 characters and
     * follwed by a '\0' character.
     */
    tOCT_UINT8 i, isValidMsIsdn = FALSE;
    char *msIsdnStr;

    if (sendSms->moMsisdnNoStr[0] == '+')
    {
        isValidMsIsdn = TRUE;
        msIsdnStr = &sendSms->moMsisdnNoStr[1];
        i = 1;
        while (*msIsdnStr)
        {
            if (isdigit(*msIsdnStr++) == 0)
            {
                isValidMsIsdn = FALSE;
                break;
            }
            i++;
        }

        /* Check if the non null characters exceeds 15 digits */
        if (i > MAX_IDENTITY_LENGTH_STR)
            isValidMsIsdn = FALSE;
    }

    if ((isValidMsIsdn == FALSE) || (blackUserInfo == NULL))
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "IMSI not in blacklist list\n");
    }
    else
    {
        blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_SMS;
        blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_INDIVIDUAL_SMS;
        blackUserInfo->triggerPagingReq = TRUE;

        blackUserInfo->mtSmsL3Pdu = (tOCT_UINT8 *)malloc(SMS_CP_DATA_MAX_LENGTH);
        assert(blackUserInfo->mtSmsL3Pdu != NULL);
        memset(blackUserInfo->mtSmsL3Pdu, 0, SMS_CP_DATA_MAX_LENGTH);
        buildCpData(blackUserInfo->mtSmsL3Pdu, sendSms->smsMessage, sendSms->moMsisdnNoStr);

        pushPagingReqToPageQ(blackUserInfo);

        rsp->result = FXL_SUCCESS;
    }

    memcpy(rsp->imsiStr, sendSms->imsiStr, SIZE_OF_IDENTITY_STR);

    rsp->hdr.msgLength = sizeof(fxL2gSendIndividualSmsRsp);
    rsp->hdr.msgType = FXL_2G_SEND_INDIVIDUAL_SMS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gSendIndividualSmsRsp));
    return;
}

void sendBroadcastSmsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    blackListedUserInfo *blackUserInfo = NULL;

    pthread_mutex_lock(&mutexBlacklistUserQ);
    listNode *current = headForBlacklistedUserQ;

    fxL2gSendBroadcastSmsCmd *sendSms = (fxL2gSendBroadcastSmsCmd *)inMsgBuf;
    fxL2gSendBroadcastSmsRsp *rsp = (fxL2gSendBroadcastSmsRsp *)msgBuf;

    /* Check the validity of MSISDN,
     * i.e., first char is '+' and rest are all numbers
     * with total length not exceeding 15 characters and
     * follwed by a '\0' character.
     */
    tOCT_UINT8 i, isValidMsIsdn = FALSE;
    char *msIsdnStr;

    if (sendSms->moMsisdnNoStr[0] == '+')
    {
        isValidMsIsdn = TRUE;
        msIsdnStr = &sendSms->moMsisdnNoStr[1];
        i = 1;
        while (*msIsdnStr)
        {
            if (isdigit(*msIsdnStr++) == 0)
            {
                isValidMsIsdn = FALSE;
                break;
            }
            i++;
        }

        /* Check if the non null characters exceeds 15 digits */
        if (i > MAX_IDENTITY_LENGTH_STR)
            isValidMsIsdn = FALSE;
    }

    if ((isValidMsIsdn == FALSE) || (current == NULL))
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "No IMSI's in blacklist list\n");
    }
    else
    {
        memset(mtBroadcastSmsL3Pdu, 0, SMS_CP_DATA_MAX_LENGTH);
        buildCpData(mtBroadcastSmsL3Pdu, sendSms->smsMessage, sendSms->moMsisdnNoStr);

        while (current != NULL)
        {
            blackUserInfo = (blackListedUserInfo *)(current->msg);

            if (blackUserInfo != NULL)
            {

                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_SMS;
                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_BROADCAST_SMS;
                blackUserInfo->triggerPagingReq = TRUE;

                pushPagingReqToPageQ(blackUserInfo);
            }

            current = current->next;
        }
        rsp->result = FXL_SUCCESS;
    }

    pthread_mutex_unlock(&mutexBlacklistUserQ);

    rsp->hdr.msgLength = sizeof(fxL2gSendBroadcastSmsRsp);
    rsp->hdr.msgType = FXL_2G_SEND_BROADCAST_SMS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gSendBroadcastSmsRsp));
    return;
}
#endif /* FEA_MT_SMS */

#ifdef FEA_2G_RELEASE_BL_USER
void gsmBlUserReleaseCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gBlUserReleaseCmd *releaseCmd = (fxL2gBlUserReleaseCmd *)inMsgBuf;
    fxL2gBlUserReleaseRsp *releaseRsp = (fxL2gBlUserReleaseRsp *)msgBuf;
    releaseRsp->result = FXL_SUCCESS;
    uint8 i = 0;

    logPrint(LOG_DEBUG, "** 2G_BL_USER_RELEASE_CMD Received : ** \n");
    logPrint(LOG_DEBUG, "** No-Of-Users-To-Release = %d: ** \n", releaseCmd->noOfusersToRelease);
    for (i = 0; i < releaseCmd->noOfusersToRelease; i++)
        logPrint(LOG_DEBUG, "** Release User[%d]: IMSI = %s, REJ-CAUSE = %d **", i + 1, releaseCmd->releaseBlUsers[i].imsiStr, releaseCmd->releaseBlUsers[i].rejectCause);

    if (releaseCmd->noOfusersToRelease > MAX_NO_OF_IDS_TO_RELEASE)
    {
        logPrint(LOG_DEBUG, "noOfusersToRelease(%d) > MAX_NO_OF_IDS_TO_RELEASE(%d), ", releaseCmd->noOfusersToRelease, MAX_NO_OF_IDS_TO_RELEASE);
        releaseRsp->result = FXL_FAILURE;
    }
    else
    {
        for (i = 0; i < releaseCmd->noOfusersToRelease; i++)
        {
            blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(releaseCmd->releaseBlUsers[i].imsiStr), FALSE, FALSE);

            if (blackUserInfo != NULL)
            {
                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_RELEASE;
                blackUserInfo->triggerPagingReq = TRUE;

                blackUserInfo->wlRejectCause = releaseCmd->releaseBlUsers[i].rejectCause;

                pushPagingReqToPageQ(blackUserInfo);
            }
            else
            {
                releaseRsp->result = FXL_FAILURE;
                logPrint(LOG_ERR, "Could not find IMSI(%s) in blacklist list", releaseCmd->releaseBlUsers[i].imsiStr);
            }
        }
    }
    releaseRsp->hdr.msgLength = sizeof(fxL2gBlUserReleaseRsp);
    releaseRsp->hdr.msgType = FXL_2G_BL_USER_RELEASE_RSP;
    releaseRsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gBlUserReleaseRsp));
    return;
}

void allBlUserReleaseCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    blackListedUserInfo *blackUserInfo = NULL;

    pthread_mutex_lock(&mutexBlacklistUserQ);

    listNode *current = headForBlacklistedUserQ;

    fxL2gAllBlUserReleaseCmd *releaseCmd = (fxL2gAllBlUserReleaseCmd *)inMsgBuf;
    fxL2gAllBlUserReleaseRsp *releaseRsp = (fxL2gAllBlUserReleaseRsp *)msgBuf;

    if (current == NULL)
    {
        releaseRsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "No IMSI's in blacklist list\n");
    }
    else
    {
        while (current != NULL)
        {
            blackUserInfo = (blackListedUserInfo *)(current->msg);

            if (blackUserInfo != NULL)
            {
                blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_RELEASE;
                blackUserInfo->triggerPagingReq = TRUE;

                blackUserInfo->wlRejectCause = releaseCmd->rejectCause;

                pushPagingReqToPageQ(blackUserInfo);
            }
            current = current->next;
        }
        releaseRsp->result = FXL_SUCCESS;
    }

    pthread_mutex_unlock(&mutexBlacklistUserQ);

    releaseRsp->hdr.msgLength = sizeof(fxL2gAllBlUserReleaseRsp);
    releaseRsp->hdr.msgType = FXL_2G_ALL_BL_USER_RELEASE_RSP;
    releaseRsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gAllBlUserReleaseRsp));
    return;
}

#endif /* FEA_2G_RELEASE_BL_USER */

void redirectTo2gCellCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gRedirectTo2gCellCmd *redirectCmd = (fxL2gRedirectTo2gCellCmd *)inMsgBuf;
    fxL2gRedirectTo2gCellRsp *rsp = (fxL2gRedirectTo2gCellRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(redirectCmd->imsiStr), FALSE, FALSE);

    if (blackUserInfo != NULL)
    {
        blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_REDIRECTION;
        blackUserInfo->triggerPagingReq = TRUE;

        blackUserInfo->redirectInfo.arfcn = redirectCmd->gsmRedirectinfo.startingarfcn;
        blackUserInfo->redirectInfo.bandIndicator = redirectCmd->gsmRedirectinfo.bandIndicator;
        blackUserInfo->redirectInfo.bsic = (((redirectCmd->ncc) & 0x07) << 3) | ((redirectCmd->bcc) & 0x07);

        pushPagingReqToPageQ(blackUserInfo);

        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in blacklist list\n");
    }

    memcpy(rsp->imsiStr, redirectCmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gRedirectTo2gCellRsp);
    rsp->hdr.msgType = FXL_2G_REDIRECT_TO_2G_CELL_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gRedirectTo2gCellRsp));
    return;
}

tOCT_UINT8 *sharedMemoryPtr = NULL;
void destroySharedMemory()
{
    free(sharedMemoryPtr);
    sharedMemoryPtr = NULL;
}

void createSharedMemoryStoringIdLists()
{
    sharedMemoryPtr = (tOCT_UINT8 *)malloc(SHARED_MEM_SIZE_TO_STORE_IDLIST);
    memset(sharedMemoryPtr, 0, SHARED_MEM_SIZE_TO_STORE_IDLIST);
}
tOCT_UINT8 *getAccessToIdList()
{
    return sharedMemoryPtr;
}

void releaseAccessToIdList(tOCT_UINT8 *sharedMemory)
{
#if 0
	shmdt(sharedMemory);
#endif
}

/*
 * Listen mode config handler
 */
void listenModeConfigHandler(unsigned char *inMsgBuf)
{
    fxL3gListenModeConfigureBandsCmd *cmd = (fxL3gListenModeConfigureBandsCmd *)inMsgBuf;
    fxL3gListenModeConfigureBandsRsp *rsp = (fxL3gListenModeConfigureBandsRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Configure Bands Command received....\n");
    configureListenMode(cmd);

    rsp->result = FXL_SUCCESS;
    rsp->hdr.msgLength = sizeof(fxL3gListenModeConfigureBandsRsp);
    rsp->hdr.msgType = FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_RSP;
    rsp->hdr.rat = FXL_RAT_3G;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gListenModeConfigureBandsRsp));

    return;
}

/*
 *  * Listen mode priority scan handler
 *   */
void listenModePriorityScanHandler(unsigned char *inMsgBuf)
{
    fxL3gListenModeConfigureUarfcnCmd *cmd = (fxL3gListenModeConfigureUarfcnCmd *)inMsgBuf;
    fxL3gListenModeConfigureUarfcnRsp *rsp = (fxL3gListenModeConfigureUarfcnRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Configure UARFCN Command received......\n");

    rsp->result = priorityScanListenMode(cmd);
    rsp->hdr.msgLength = sizeof(fxL3gListenModeConfigureUarfcnRsp);
    rsp->hdr.msgType = FXL_3G_LISTEN_MODE_PRIORITY_SCAN_RSP;
    rsp->hdr.rat = FXL_RAT_3G;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gListenModeConfigureUarfcnRsp));
}

/*
 * Listen mode start stop handler
 */
void listenModeStartStopHandler(unsigned char *inMsgBuf)
{
    fxL3gListenModeStartStopScanCmd *cmd = (fxL3gListenModeStartStopScanCmd *)inMsgBuf;
    fxLResult resultValue = FXL_FAILURE;

    if (cmd->startStopScan == FXL_START_CONTINUOUS_TRIGGER)
    {
        delstore3gScanResult();
        logPrint(LOG_DEBUG, "Start 3G Scanner....\n");
        scanMode = cmd->scanType;
        resultValue = createAndStartListenModeThread();

        if (resultValue == FXL_SUCCESS)
            currentOneBinState = ONEBIN_STATE_3G_SCANNING;
    }
    else
    {
        if (currentOneBinState == ONEBIN_STATE_3G_SCANNING)
        {
            logPrint(LOG_DEBUG, "Stop 3G Scanner....\n");
            resultValue = stopListenModeApplication();
            currentOneBinState = ONEBIN_STATE_IDLE;
            scanMode = FXL_SCAN_TYPE_EXHAUSTIVE;
            if (cmd->dspResetNeeded == 1)
            {
                unsigned int retCode = 0;
                /* Fill the Details */
                if ((isItPrimaryDsp() == TRUE))
                {
                    char *argValue[2] = {"dr", "-p"};
                    optreset = 1;
                    retCode = g_Commands[12]->pfctCallBack(2, argValue);
                    resultValue = FXL_SUCCESS;
                    logPrint(LOG_DEBUG, "Reset the primary DSP \n");
                }
                else
                {
                    char *argValue[2] = {"dr", "-s"};
                    optreset = 1;
                    retCode = g_Commands[12]->pfctCallBack(2, argValue);
                    resultValue = FXL_SUCCESS;
                    logPrint(LOG_DEBUG, "Reset the secondary DSP \n");
                }
            }
        }
    }

    fxL3gListenModeStartStopScanRsp *rsp = (fxL3gListenModeStartStopScanRsp *)msgBuf;

    rsp->result = resultValue;
    rsp->hdr.msgLength = sizeof(fxL3gListenModeStartStopScanRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gListenModeStartStopScanRsp));
    return;
}

/*
 * UMTS Native Configure Id Catcher Params
 */
void umtsConfigureIdCatcherParams(unsigned char *inMsgBuf)
{
    fxL3gConfigureIdCatcherParamsCmd *cmd = (fxL3gConfigureIdCatcherParamsCmd *)inMsgBuf;
    fxL3gConfigureIdCatcherParamsRsp *rsp = (fxL3gConfigureIdCatcherParamsRsp *)msgBuf;

    logPrint(LOG_DEBUG, "3G Id Catcher Parameters Configuration Command received...\n");
    configureUmtsIdCatcherParameters(cmd);
    rsp->result = FXL_SUCCESS;
    rsp->hdr.msgLength = sizeof(fxL3gConfigureIdCatcherParamsRsp);
    rsp->hdr.msgType = FXL_3G_CONFIGURE_IDCATCHER_PARAMS_RSP;
    rsp->hdr.rat = FXL_RAT_3G;
    // modemSetupRequired = 1;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gConfigureIdCatcherParamsRsp));

    return;
}

/*
 * UMTS Id Catcher Start handler
 */
void umtsStartIdCatcher(unsigned char *inMsgBuf)
{
#if defined(OBM_PA_BTS8500_NW) || defined(OBM_PA_BTS8500_WW)
    system("obm rf 1 1");
#endif

    fxL3gStartIdCatcherRsp *rsp = (fxL3gStartIdCatcherRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Start 3G Id Catcher....\n");

    rsp->hdr.msgLength = sizeof(fxL3gStartIdCatcherRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_START_IDCATCHER_RSP;
#ifdef PUMP_REG_DATA
    rsp->result = FXL_SUCCESS;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gStartIdCatcherRsp));
    sleep(1);
    startPumpData();
    return;
#endif

    setNetworkDriverPriorityForLte(TRUE);
    rsp->result = createAndStart3gIdCatcherThread();

    if (rsp->result == FXL_FAILURE)
    {
        currentOneBinState = ONEBIN_STATE_IDLE;
        modemSetupRequired = 1;
        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gStartIdCatcherRsp));
    }

    return;
}

/*
 * UMTS Id Catcher Stop handler
 */
void umtsStopIdCatcher(unsigned char *inMsgBuf)
{

    fxL3gStopIdCatcherCmd *cmd = (fxL3gStopIdCatcherCmd *)inMsgBuf;
    fxL3gStopIdCatcherRsp *rsp = (fxL3gStopIdCatcherRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Stop 3G Id Catcher....\n");

    rsp->hdr.msgLength = sizeof(fxL3gStopIdCatcherRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_STOP_IDCATCHER_RSP;
#ifndef PUMP_REG_DATA
    if (1 == bootL1InProgress)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
#ifdef FEA_PICSIX_CHANGE
        timerStop(&systemStatusTimer);

        if (NULL != systemStatusTimer.parm)
        {
            free(systemStatusTimer.parm);
            systemStatusTimer.parm = NULL;
        }
        memset((tcbTimer_t *)&systemStatusTimer, 0, sizeof(tcbTimer_t));
#endif
        rsp->result = stop3gIdCatcherThread();

        if (cmd->dspResetNeeded == 1)
        {
            L1API_Close(NULL);

            if (isItPrimaryDsp() == TRUE)
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }

            modemSetupRequired = 1;
        }
        else
        {
            gCellDeleteReq.cId = gUmtsConfig.cellId;
            oct_cell_delete_req(&gCellDeleteReq);
            isCellSetupRequired = 0;
        }
    }
#else
    rsp->result = FXL_SUCCESS;
    stopPumpData();
#endif
    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gStopIdCatcherRsp));

    return;
}

/*
 * UMTS Auto Start handler
 */
void umtsAutoConfig(unsigned char *inMsgBuf)
{
    unsigned int idx = 0;
    fxL3gAutoConfigCmd *cmd = (fxL3gAutoConfigCmd *)inMsgBuf;
    fxL3gAutoConfigRsp *rsp = (fxL3gAutoConfigRsp *)msgBuf;

#if defined(OBM_PA_BTS8500_NW) || defined(OBM_PA_BTS8500_WW)
    system("obm rf 1 1");
#endif

#if EVAL_IDR_TECH
    fxL3gPlmn operator1Plmn;
    fxL3gPlmn operator2Plmn;

    operator1Plmn.mccLength = 3;
    operator1Plmn.mcc[0] = 3;
    operator1Plmn.mcc[1] = 3;
    operator1Plmn.mcc[2] = 4;
    operator1Plmn.mncLength = 2;
    operator1Plmn.mnc[0] = 0;
    operator1Plmn.mnc[1] = 2;
    operator2Plmn.mccLength = 3;
    operator2Plmn.mcc[0] = 3;
    operator2Plmn.mcc[1] = 3;
    operator2Plmn.mcc[2] = 4;
    operator2Plmn.mncLength = 2;
    operator2Plmn.mnc[0] = 0;
    operator2Plmn.mnc[1] = 3;
#endif
    logPrint(LOG_DEBUG, "Auto Start 3G Id Catcher....\n");

    rsp->hdr.msgLength = sizeof(fxL3gAutoConfigRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_AUTO_CONFIG_RSP;

    if (cmd->noOfEntries > MAX_NO_OF_IDS_PER_TRANSACTION)
    {
        rsp->result = FXL_FAILURE;
        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gAutoConfigRsp));
        currentOneBinState = ONEBIN_STATE_IDLE;
    }
    else
    {

#if EVAL_IDR_TECH
        if ((operator1Plmn.mcc[0] == cmd->plmn.mcc[0]) && (operator1Plmn.mcc[1] == cmd->plmn.mcc[1]) && (operator1Plmn.mcc[2] == cmd->plmn.mcc[2]))
        {
            if (((operator1Plmn.mnc[0] == cmd->plmn.mnc[0]) && (operator1Plmn.mnc[1] == cmd->plmn.mnc[1])) || ((operator2Plmn.mnc[0] == cmd->plmn.mnc[0]) && (operator2Plmn.mnc[1] == cmd->plmn.mnc[1])))
            {
            }
            else
            {
                DEBUGMSG(("\n Invalid MNC Configured\n"));
                return;
            }
        }
        else
        {
            DEBUGMSG(("\n Invalid MCC Configured\n"));
            return;
        }
#endif
        /* Initialize MCC */
        gUmtsConfig.plmn[0].mccLength = 0;
        for (idx = 0; idx < FXL_UMTS_MAX_MCC_LEN; idx++)
        {
            gUmtsConfig.plmn[0].mcc[idx] = 0xFFFFFFFF;
        }

        /* Fill MCC */
        gUmtsConfig.plmn[0].mccLength = cmd->plmn.mccLength;
        for (idx = 0; idx < cmd->plmn.mccLength; idx++)
        {
            gUmtsConfig.plmn[0].mcc[idx] = cmd->plmn.mcc[idx];
        }

        /* Initialize MNC */
        gUmtsConfig.plmn[0].mncLength = 0;
        for (idx = 0; idx < FXL_UMTS_MAX_MNC_LEN; idx++)
        {
            gUmtsConfig.plmn[0].mnc[idx] = 0xFFFFFFFF;
        }

        /* Fill MNC */
        gUmtsConfig.plmn[0].mncLength = cmd->plmn.mncLength;
        for (idx = 0; idx < cmd->plmn.mncLength; idx++)
        {
            gUmtsConfig.plmn[0].mnc[idx] = cmd->plmn.mnc[idx];
        }

        /*Check for DSP */
        if (isItPrimaryDsp() == TRUE)
        {
            /* Fill LAC */
            gUmtsConfig.lac[0] = gsmCommRand(1, 254);
            gUmtsConfig.lac[1] = gsmCommRand(1, 254);

            /* Fill RAC */
            gUmtsConfig.rac = gsmCommRand(1, 254);
        }
        else
        {
            /* Fill LAC */
            gUmtsConfig.lac[0] = ((gsmCommRand(1, 254) + 10) % 254);
            gUmtsConfig.lac[1] = ((gsmCommRand(1, 254) + 10) % 254);

            /* Fill RAC */
            gUmtsConfig.rac = ((gsmCommRand(1, 254) + 10) % 254);
        }

        /* Fill txAttn */
        gUmtsConfig.txAttn = cmd->txAttn;

        /* Fill Redirection Type */
        gUmtsConfig.redirectionType = cmd->redirectionType;

        /* Fill Redirection Info */
        if (FXL_UMTS_REDIRECTION_TO_2G == cmd->redirectionType)
        {
            gUmtsConfig.redirectionInfo.gsmRedirectinfo.startingarfcn =
                cmd->redirectionInfo.gsmRedirectinfo.startingarfcn;

            gUmtsConfig.redirectionInfo.gsmRedirectinfo.bandIndicator =
                cmd->redirectionInfo.gsmRedirectinfo.bandIndicator;
        }
        else if (FXL_UMTS_REDIRECTION_TO_3G == cmd->redirectionType)
        {
            gUmtsConfig.redirectionInfo.dlUarfcn = cmd->redirectionInfo.dlUarfcn;
        }
        else
        {
            memset((fxL3gRedirectionInfo *)&gUmtsConfig.redirectionInfo, 0,
                   sizeof(fxL3gRedirectionInfo));
        }

        memset((fxL3gRedirectionInfo *)&gUmtsConfig.wlUserRedirectionInfo, 0,
               sizeof(fxL3gRedirectionInfo));
#if 0
        {  // Redirection Info for WL User
            /* Fill Redirection Type */
            gUmtsConfig.wlUserRedirectionType = cmd->wlUserRedirectionType;
         
            /* Fill Redirection Info */
            if (FXL_UMTS_REDIRECTION_TO_2G == cmd->wlUserRedirectionType)
            {
                gUmtsConfig.wlUserRedirectionInfo.gsmRedirectinfo.startingarfcn = 
                                   cmd->wlUserRedirectionInfo.gsmRedirectinfo.startingarfcn;
         
                gUmtsConfig.wlUserRedirectionInfo.gsmRedirectinfo.bandIndicator = 
                                   cmd->wlUserRedirectionInfo.gsmRedirectinfo.bandIndicator;
            }
            else if (FXL_UMTS_REDIRECTION_TO_3G == cmd->wlUserRedirectionType)
            {
                gUmtsConfig.wlUserRedirectionInfo.dlUarfcn = cmd->wlUserRedirectionInfo.dlUarfcn;
            }
            else
            {
                memset((fxL3gRedirectionInfo *)&gUmtsConfig.wlUserRedirectionInfo, 0, 
                       sizeof(fxL3gRedirectionInfo));
            }
        }
#endif

        if (0 != cmd->rejectCauseEnable)
        {
            gUmtsConfig.wlRejectCauseCfgEnable = 1;
            gUmtsConfig.wlRejectCause = cmd->rejectCause;
        }
        else
        {
            gUmtsConfig.wlRejectCauseCfgEnable = 0;
            gUmtsConfig.wlRejectCause = 0;
        }

        /* Fill CPICH Tx Pwr */
        gUmtsConfig.cpichTxPwr = cmd->cpichTxPwr;

        /* Fill emergency call rejection flag */
        gUmtsConfig.enableEmergencyCallRejection = cmd->enableEmergencyRejection;

        /* Fill Emergency call Redirection Type */
        gUmtsConfig.emergencyCallRedirectionType = cmd->emergencyCallRedirectionType;

        /* Fill Emergency call Redirection Info */
        if (FXL_UMTS_REDIRECTION_TO_2G == cmd->emergencyCallRedirectionType)
        {
            gUmtsConfig.emergencyCallRedirectionInfo.gsmRedirectinfo.startingarfcn =
                cmd->emergencyCallRedirectionInfo.gsmRedirectinfo.startingarfcn;

            gUmtsConfig.emergencyCallRedirectionInfo.gsmRedirectinfo.bandIndicator =
                cmd->emergencyCallRedirectionInfo.gsmRedirectinfo.bandIndicator;
        }
        else if (FXL_UMTS_REDIRECTION_TO_3G == cmd->emergencyCallRedirectionType)
        {
            gUmtsConfig.emergencyCallRedirectionInfo.dlUarfcn = cmd->emergencyCallRedirectionInfo.dlUarfcn;
        }
        else
        {
            memset((fxL3gRedirectionInfo *)&gUmtsConfig.emergencyCallRedirectionInfo, 0,
                   sizeof(fxL3gRedirectionInfo));
        }

        /* Fill pilot_boost_enable flag */
        gUmtsConfig.pilot_boost_enable = cmd->pilot_boost_enable;
        if (true == gUmtsConfig.pilot_boost_enable)
        {
            gUmtsConfig.sib5Info.pichPwr = -8; // DEF_PICH_Power;
            gUmtsConfig.sib5Info.aichPwr = -8; // DEF_AICH_Power;
        }
        else
        {
            gUmtsConfig.sib5Info.pichPwr = -5; // DEF_PICH_Power;
            gUmtsConfig.sib5Info.aichPwr = -5; // DEF_AICH_Power;
        }

        /* Fill Rx Gain */
        gUmtsConfig.rxGain = cmd->ulRxGainDb;
        logPrint(LOG_DEBUG, "RX GAIN = %d \n", gUmtsConfig.rxGain);

        scanNotRequired = findAutoConfigPlmnInScanResult(cmd);
        // modemSetupRequired = gAutoConfigCfg.dspResetNeeded = cmd->dspResetNeeded;
        // Temporary hard coding, as Corresponding GUI is sending wrong value of dspResetNeeded.
        modemSetupRequired = gAutoConfigCfg.dspResetNeeded = 1;
        if (gScanResult.numOfValidOperator == 0)
        {
            autoConfigureRrcIdentityList(cmd);
            rsp->result = FXL_SUCCESS;
            writeToExternalSocketInterface(msgBuf, sizeof(fxL3gAutoConfigRsp));

            gAutoConfigCfg.autoConfig3g = 1;
            gAutoConfigCfg.dspType = cmd->dspType;

            gAutoConfigCfg.l1Image = FXL_L1_UMTS_SLS_IMAGE;
            autoConfigureListenMode(cmd);
            bootL1InProgress = 1;
            autoBootL1Image();
            bootL1InProgress = 0;
            logPrint(LOG_DEBUG, "Start 3G Scanner....\n");
            createAndStartListenModeThread();
        }
        else if (scanNotRequired == 1)
        {
            autoConfigureRrcIdentityList(cmd);
            rsp->result = FXL_SUCCESS;
            writeToExternalSocketInterface(msgBuf, sizeof(fxL3gAutoConfigRsp));
            gAutoConfigCfg.autoConfig3g = 1;
            gAutoConfigCfg.dspType = cmd->dspType;
            createAndStartListenModeThread();
        }
        else
        {
            rsp->result = FXL_FAILURE;
            writeToExternalSocketInterface(msgBuf, sizeof(fxL3gAutoConfigRsp));
            currentOneBinState = ONEBIN_STATE_IDLE;
        }
    }

    return;
}

/*
 * UMTS Auto Config Stop handler
 */
void umtsAutoConfigStop(unsigned char *inMsgBuf)
{
    fxL3gAutoConfigStopCmd *cmd = (fxL3gAutoConfigStopCmd *)inMsgBuf;
    fxL3gAutoConfigStopRsp *rsp = (fxL3gAutoConfigStopRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Stop Auto Config ....\n");

    rsp->hdr.msgLength = sizeof(fxL3gAutoConfigStopRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_AUTO_CONFIG_STOP_RSP;

    if (1 == bootL1InProgress)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        if (FXL_L1_UMTS_SLS_IMAGE == gAutoConfigCfg.l1Image)
        {
            rsp->result = stopListenModeApplication();
        }
        else if (FXL_L1_UMTS_NATIVE_IMAGE == gAutoConfigCfg.l1Image)
        {
#ifdef FEA_PICSIX_CHANGE
            timerStop(&systemStatusTimer);

            if (NULL != systemStatusTimer.parm)
            {
                free(systemStatusTimer.parm);
                systemStatusTimer.parm = NULL;
            }
            memset((tcbTimer_t *)&systemStatusTimer, 0, sizeof(tcbTimer_t));
#endif
            rsp->result = stop3gIdCatcherThread();
        }
        else
        {
            rsp->result = FXL_SUCCESS;
        }

        memset((AutoConfigCfg *)&gAutoConfigCfg, 0, sizeof(gAutoConfigCfg));

        if (cmd->dspResetNeeded == 1)
        {
            L1API_Close(NULL);

            if (isItPrimaryDsp() == TRUE)
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
            modemSetupRequired = 1;
        }
        else
        {
            gCellDeleteReq.cId = gUmtsConfig.cellId;
            oct_cell_delete_req(&gCellDeleteReq);
            isCellSetupRequired = 0;
        }
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gAutoConfigStopRsp));

    return;
}

/*
 * UMTS Configure SysInfo Config Command handler
 * Currently only Neighbour Info is configurable
 */
void umtsSysInfoConfigHndlr(unsigned char *inMsgBuf)
{
    unsigned int idx, idx1 = 0;
    fxL3gSysInfoConfigCmd *cmd = (fxL3gSysInfoConfigCmd *)inMsgBuf;

    logPrint(LOG_DEBUG, "Umts SysInfo Config Command Received....\n");
#ifndef PUMP_REG_DATA
    if (cmd->numOfPlmn != 0xFFFF)
    {
        /* Fill number of Plmn*/
        gUmtsConfig.numOfPlmn = cmd->numOfPlmn;

        /* Initialize MCC and MNC */
        for (idx = 0; idx < 6; idx++)
        {
            gUmtsConfig.plmn[idx].mccLength = 0;
            gUmtsConfig.plmn[idx].mncLength = 0;

            for (idx1 = 0; idx1 < FXL_UMTS_MAX_MCC_LEN; idx1++)
            {
                gUmtsConfig.plmn[idx].mcc[idx1] = 0xFFFFFFFF;
                gUmtsConfig.plmn[idx].mnc[idx1] = 0xFFFFFFFF;
            }
        }

        /* Fill MCC and MNC */
        for (idx = 0; idx < gUmtsConfig.numOfPlmn; idx++)
        {
            gUmtsConfig.plmn[idx].mccLength = cmd->plmn[idx].mccLength;
            for (idx1 = 0; idx1 < cmd->plmn[idx].mccLength; idx1++)
            {
                gUmtsConfig.plmn[idx].mcc[idx1] = cmd->plmn[idx].mcc[idx1];
            }

            gUmtsConfig.plmn[idx].mncLength = cmd->plmn[idx].mncLength;
            for (idx1 = 0; idx1 < cmd->plmn[idx].mncLength; idx1++)
            {
                gUmtsConfig.plmn[idx].mnc[idx1] = cmd->plmn[idx].mnc[idx1];
            }
        }
    }

    /* Fill LAC */
    ASSIGN_NON_NEGATIVE(cmd->lac[0], gUmtsConfig.lac[0]);
    ASSIGN_NON_NEGATIVE(cmd->lac[1], gUmtsConfig.lac[1]);

    ASSIGN_NON_NEGATIVE(cmd->rac, gUmtsConfig.rac);
    ASSIGN_NON_NEGATIVE(cmd->t3212, gUmtsConfig.t3212);
    ASSIGN_NON_NEGATIVE(cmd->att, gUmtsConfig.att);
    ASSIGN_NON_NEGATIVE(cmd->nmo, gUmtsConfig.nmo);

    ASSIGN_NON_NEGATIVE(cmd->mibValueTag, gUmtsConfig.mibValueTag);

    if (cmd->sib1CfgPres)
    { // Negative Value is treated as Invlid value. So update all non negative values.
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T300, gUmtsConfig.sib1Info.T300);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.N300, gUmtsConfig.sib1Info.N300);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T301, gUmtsConfig.sib1Info.T301);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T302, gUmtsConfig.sib1Info.T302);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T304, gUmtsConfig.sib1Info.T304);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T305, gUmtsConfig.sib1Info.T305);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T307, gUmtsConfig.sib1Info.T307);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T308, gUmtsConfig.sib1Info.T308);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T310, gUmtsConfig.sib1Info.T310);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T311, gUmtsConfig.sib1Info.T311);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T312, gUmtsConfig.sib1Info.T312);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.N312, gUmtsConfig.sib1Info.N312);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.N313, gUmtsConfig.sib1Info.N313);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T314, gUmtsConfig.sib1Info.T314);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T315, gUmtsConfig.sib1Info.T315);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.N315, gUmtsConfig.sib1Info.N315);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T316, gUmtsConfig.sib1Info.T316);
        ASSIGN_NON_NEGATIVE(cmd->sib1Info.T317, gUmtsConfig.sib1Info.T317);
    }
    

        if (cmd->sib2CfgPres)
    {
        gUmtsConfig.sib2Info.numUraIdentity = 1; // cmd->sib2Info.numUraIdentity;
        // Flip 1st and second byte.
        gUmtsConfig.sib2Info.uraIdentityLst[0] = 0xFF & cmd->sib2Info.uraIdentityLst[0];
        gUmtsConfig.sib2Info.uraIdentityLst[0] = (gUmtsConfig.sib2Info.uraIdentityLst[0] << 8) | ((cmd->sib2Info.uraIdentityLst[0] >> 8) & 0xFF);
    }

    if (cmd->sib3CfgPres)
    {
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.sib4Indicator, gUmtsConfig.sib3Info.sib4Indicator);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.cellId, gUmtsConfig.cellId);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.cellSelQualMeas, gUmtsConfig.cellSelQualMeas);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.qHyst2S, gUmtsConfig.sib3Info.qHyst2S);
        gUmtsConfig.qHyst2S = gUmtsConfig.sib3Info.qHyst2S;
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.sIntraSearch, gUmtsConfig.sib3Info.sIntraSearch);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.sInterSearch, gUmtsConfig.sib3Info.sInterSearch);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.sSearchHCS, gUmtsConfig.sib3Info.sSearchHCS);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.ratSearch, gUmtsConfig.sib3Info.ratSearch);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.sLimitSearchRAT, gUmtsConfig.sib3Info.sLimitSearchRAT);
        {
            gUmtsConfig.cellReselectUsrCfgStatus = 1;
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.sLimitSearchRAT, gUmtsConfig.sib3Info.sLimitSearchRAT);
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.qQualMin, gUmtsConfig.qQualMin);
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.qRxLevMin, gUmtsConfig.qRxLevMin);
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.qHystLS, gUmtsConfig.qHystLS);
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.tReselect, gUmtsConfig.tReselec);
            ASSIGN_NON_NEGATIVE(cmd->sib3Info.maxULTxPower, gUmtsConfig.maxUlTxPwr);
        }

        ASSIGN_NON_NEGATIVE(cmd->sib3Info.cellBarredInfo.status, gUmtsConfig.sib3Info.cellBarredInfo.status);
        if (0 == cmd->sib3Info.cellBarredInfo.status) // Only if valid value filled as barred.
        {
            gUmtsConfig.sib3Info.cellBarredInfo.intraFreqCellReselectionInd = cmd->sib3Info.cellBarredInfo.intraFreqCellReselectionInd;
            gUmtsConfig.sib3Info.cellBarredInfo.T_Barred = cmd->sib3Info.cellBarredInfo.T_Barred;
        }
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.cellReservedForOperatiorUse, gUmtsConfig.sib3Info.cellReservedForOperatiorUse);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.cellReservationExtention, gUmtsConfig.sib3Info.cellReservationExtention);
        ASSIGN_NON_NEGATIVE(cmd->sib3Info.accessClassBarredLstPres, gUmtsConfig.sib3Info.accessClassBarredLstPres);
        if (gUmtsConfig.sib3Info.accessClassBarredLstPres)
        {
            for (idx = 0; idx < 16; idx++)
            {
                gUmtsConfig.sib3Info.accessClassBarredLst[idx] = cmd->sib3Info.accessClassBarredLst[idx];
            }
        }
    }

    if (cmd->sib5CfgPres)
    {

        ASSIGN_NON_NEGATIVE(cmd->sib5Info.sib6indicator, gUmtsConfig.sib5Info.sib6indicator);
        ASSIGN_NON_NEGATIVE(cmd->sib5Info.pichPwr, gUmtsConfig.sib5Info.pichPwr);
        ASSIGN_NON_NEGATIVE(cmd->sib5Info.aichPwr, gUmtsConfig.sib5Info.aichPwr);
        ASSIGN_NON_NEGATIVE(cmd->sib5Info.prachPowerRampStep, gUmtsConfig.sib5Info.prachPowerRampStep);
        ASSIGN_NON_NEGATIVE(cmd->sib5Info.prachpreambleRetransMax, gUmtsConfig.sib5Info.prachpreambleRetransMax);
    }

    if (cmd->sib7CfgPres)
    { // Mendatory if sib7CfgPres != 0
        ASSIGN_NON_NEGATIVE(cmd->sib7Info.ulInterference, gUmtsConfig.sib7Info.ulInterference);
    }
    if (cmd->sib11CfgPres)
    {
        ASSIGN_NON_NEGATIVE(cmd->sib11Info.sib12indicator, gUmtsConfig.sib11Info.sib12indicator);
        ASSIGN_NON_NEGATIVE(cmd->sib11Info.hscUsed, gUmtsConfig.sib11Info.hscUsed);
        gUmtsConfig.sib11Info.hscUsed = 0; // Hardcoded as of now
        gUmtsConfig.sib11Info.numInterFreqNeighbr = cmd->sib11Info.numInterFreqNeighbr;
        for (idx = 0; idx < gUmtsConfig.sib11Info.numInterFreqNeighbr; idx++)
        {
            gUmtsConfig.sib11Info.interFreqNeighbrList[idx] = cmd->sib11Info.interFreqNeighbrList[idx];
        }
        gUmtsConfig.sib11Info.numIntraFreqNeighbr = cmd->sib11Info.numIntraFreqNeighbr;
        for (idx = 0; idx < gUmtsConfig.sib11Info.numIntraFreqNeighbr; idx++)
        {
            gUmtsConfig.sib11Info.intraFreqNeighbrList[idx] = cmd->sib11Info.intraFreqNeighbrList[idx];
        }
    }

    //  If cell is active send updated SIB. If Id catcher not running Update parameter Value only
    if (gClCntxt.cellState == CL_CELL_ACTIVE)
    {
        /* Send SIB Update for change of SIB Parameters */
        if (1 == buildAndSendL1SibMessage())
        {
            logPrint(LOG_DEBUG, "Sending SYSTEM_INFO_UPDATE_REQUEST to L1 failed \n");
        }
    }
    else // Only Config Parameter updated. SIB Change will take effect during Next Start.
    {
        sendSystemInfoUpdateRsp(1); // With Success
    }

#else
    sendSystemInfoUpdateRsp(1); // With Success
#endif

    return;
}

/*
 * UMTS Change Tx Attn & CPICH Tx Pwr Command handler
 */
void umtsChangeTxAttnCpichTxPwr(unsigned char *inMsgBuf)
{
    unsigned int sendFailureResponse = 0;

    fxL3gChgTxAttnCpichTxPwrCmd *cmd = (fxL3gChgTxAttnCpichTxPwrCmd *)inMsgBuf;
    fxL3gChgTxAttnCpichTxPwrRsp *rsp = (fxL3gChgTxAttnCpichTxPwrRsp *)msgBuf;

    logPrint(LOG_DEBUG, "Change TxAttn & CPICH Tx Pwr Command Received....\n");

    logPrint(LOG_DEBUG, "TX ATTN = %d , CPICH = %d \n", cmd->txAttn, cmd->cpichTxPwr);

    if (gClCntxt.cellState == CL_CELL_ACTIVE)
    {
        /* Update txAttn & CPICH Tx Pwr */
        gUmtsConfig.txAttn = cmd->txAttn;
        gUmtsConfig.cpichTxPwr = cmd->cpichTxPwr;

        fillCellReconfigReq();
        if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
        {
            logPrint(LOG_DEBUG, "Sending Cell Reconfig to L1 failed....\n");
            sendFailureResponse = 1;
        }
    }
    else
    {
        sendFailureResponse = 1;
    }

    if (1 == sendFailureResponse)
    {
        rsp->hdr.msgLength = sizeof(fxL3gChgTxAttnCpichTxPwrRsp);
        rsp->hdr.rat = FXL_RAT_3G;
        rsp->hdr.msgType = FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_RSP;
        rsp->result = FXL_FAILURE;
        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gChgTxAttnCpichTxPwrRsp));
        return;
    }
}

/*
 * Change UE UL Tx Power in 3G
 */
void umtsChangeUeUlTxPwr(unsigned char *inMsgBuf)
{
    fxL3gChangeUeUlTxPwrCmd *cmd = (fxL3gChangeUeUlTxPwrCmd *)inMsgBuf;

    if ((FXL_RAT_3G == cmd->hdr.rat) &&
        (sizeof(fxL3gChangeUeUlTxPwrCmd) == cmd->hdr.msgLength))
    {
        UeUlTxPwrData *pUeUlTxPwr = (UeUlTxPwrData *)malloc(sizeof(UeUlTxPwrData));
        memset((UeUlTxPwrData *)pUeUlTxPwr, 0, sizeof(UeUlTxPwrData));

        strncpy(pUeUlTxPwr->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
        pUeUlTxPwr->maxUlTxPwr = cmd->maxUlTxPwr;

        SendMsgToTask(SOCK_ITF_TASK_E, APP_RRC_TASK_E, RRC_CHANGE_UE_UL_TX_PWR_E, pUeUlTxPwr);
    }

    return;
}

/*
 * Redirect BL UE in 3G
 */
void umtsRedirectBlUe(unsigned char *inMsgBuf)
{
    fxL3gBLUeRedirectCmd *cmd = (fxL3gBLUeRedirectCmd *)inMsgBuf;

    if ((FXL_RAT_3G == cmd->hdr.rat) &&
        (sizeof(fxL3gBLUeRedirectCmd) == cmd->hdr.msgLength))
    {
        UmtsBlUeRedirectInfo *p3gBlUeRedirect = (UmtsBlUeRedirectInfo *)malloc(sizeof(UmtsBlUeRedirectInfo));
        memset((UmtsBlUeRedirectInfo *)p3gBlUeRedirect, 0, sizeof(UmtsBlUeRedirectInfo));

        strncpy(p3gBlUeRedirect->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
        p3gBlUeRedirect->redirectionType = cmd->redirectionType;
        p3gBlUeRedirect->redirectionInfo.gsmRedirectinfo = cmd->redirectionInfo.gsmRedirectinfo;
        p3gBlUeRedirect->redirectionInfo.dlUarfcn = cmd->redirectionInfo.dlUarfcn;

        SendMsgToTask(SOCK_ITF_TASK_E, APP_RRC_TASK_E, RRC_REDIRECT_BL_UE_E, p3gBlUeRedirect);
    }

    return;
}

/* * Start umts Silent Call*/
void umtsStartSilentCallCmd(unsigned char *inMsgBuf)
{
    fxLResult result;
    fxL3gStartSilentCallCmd *cmd = (fxL3gStartSilentCallCmd *)inMsgBuf;
    fxL3gStartSilentCallRsp *rsp = (fxL3gStartSilentCallRsp *)msgBuf;

    rsp->hdr.msgLength = sizeof(fxL3gStartSilentCallRsp);
    rsp->hdr.msgType = FXL_3G_START_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_3G;

    rsp->result = configureSilentCallStart(cmd);

    strncpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gStartSilentCallRsp));
    return;
}

/* * Stop umts Silent Call*/
void umtsEndSilentCallCmd(unsigned char *inMsgBuf)
{
    fxLResult result;
    fxL3gEndSilentCallCmd *cmd = (fxL3gEndSilentCallCmd *)inMsgBuf;
    fxL3gEndSilentCallRsp *rsp = (fxL3gEndSilentCallRsp *)msgBuf;

    rsp->hdr.msgLength = sizeof(fxL3gEndSilentCallRsp);
    rsp->hdr.msgType = FXL_3G_END_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->result = configureSilentCallStop(cmd);
    strncpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);

    if (rsp->result == FXL_FAILURE)
        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gEndSilentCallRsp));

    return;
}

/*
 * RAT Get Number of UEs within range
 */
void ratGetNumOfUeWithinRange(unsigned char *inMsgBuf)
{
    fxLGetUeWithinRangeCmd *cmd = (fxLGetUeWithinRangeCmd *)inMsgBuf;
    fxLGetUeWithinRangeRsp *rsp = (fxLGetUeWithinRangeRsp *)msgBuf;

    rsp->hdr.msgLength = sizeof(fxLGetUeWithinRangeRsp);
    rsp->hdr.msgType = FXL_GET_UE_WITHIN_RANGE_RSP;

    if (FXL_RAT_3G == cmd->hdr.rat)
    {
        rsp->hdr.rat = FXL_RAT_3G;
        rsp->result = FXL_SUCCESS;
        rsp->numOfUe = getNumOfUeLatched();
    }
    else if (FXL_RAT_2G == cmd->hdr.rat)
    {
        rsp->hdr.rat = FXL_RAT_2G;
        rsp->result = FXL_SUCCESS;
        rsp->numOfUe = getAllRegisteredUesInGsm();
    }
    else
    {
        rsp->hdr.rat = cmd->hdr.rat;
        rsp->result = FXL_FAILURE;
        rsp->numOfUe = 0;
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxLGetUeWithinRangeRsp));

    return;
}

void initializeSystemInformationInd(void)
{
    unsigned int idx = 0, idx1 = 0;

    g3gListenModeSysInfo.band = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.uarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.lac = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.numOfCell = 0;
    g3gListenModeSysInfo.pci = FXL_UMTS_VALUE_NOT_APPLICABLE;

    for (idx = 0; idx < 6; idx++)
    {
        g3gListenModeSysInfo.plmn[idx].mccLength = 0;
        g3gListenModeSysInfo.plmn[idx].mcc[0] = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.plmn[idx].mcc[1] = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.plmn[idx].mcc[2] = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.plmn[idx].mncLength = 0;
        g3gListenModeSysInfo.plmn[idx].mnc[0] = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.plmn[idx].mnc[1] = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.plmn[idx].mnc[2] = FXL_UMTS_VALUE_NOT_APPLICABLE;
    }

    for (idx = 0; idx < FXL_UMTS_MAX_CELL_INFO; idx++)
    {
        g3gListenModeSysInfo.cellInfo[idx].rssi = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].rscp = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].ecio = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].psc = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].networkCellId = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qQualMin = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qRxLevMin = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qHystLS = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qHyst2S = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.tReselS = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.maxAllowedULTxPower = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sIntraSearch = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sInterSearch = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sSearchHCS = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.ratSearch = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sLimitSearchRAT = FXL_UMTS_VALUE_NOT_APPLICABLE;
        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST; idx1++)
        {
            g3gListenModeSysInfo.cellInfo[idx].intraFreqCellList[idx1].cellId = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].intraFreqCellList[idx1].psc = FXL_UMTS_VALUE_NOT_APPLICABLE;
        }

        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTER_FREQ_CELL_LIST; idx1++)
        {
            g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].cellId = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].psc = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].dlUarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].ulUarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
        }

        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTER_RAT_CELL_LIST; idx1++)
        {
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].cellId = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].band = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].arfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].ncc = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].bcc = FXL_UMTS_VALUE_NOT_APPLICABLE;
            g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].qRxLevMin = FXL_UMTS_VALUE_NOT_APPLICABLE;
        }
    }

    g3gListenModeSysInfo.priorityCellInfo.servingCellPriority = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch1 = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch2 = FXL_UMTS_VALUE_NOT_APPLICABLE;
    g3gListenModeSysInfo.priorityCellInfo.threshServingLow = FXL_UMTS_VALUE_NOT_APPLICABLE;
    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].uarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].priority = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXhigh = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXlow = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qQualMinFdd = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qRxLevMinFdd = FXL_UMTS_VALUE_NOT_APPLICABLE;
    }

    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].arfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].bandIndicator = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].priority = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].qRxLevMinGSM = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXhigh = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXlow = FXL_UMTS_VALUE_NOT_APPLICABLE;
    }

    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].earfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].priority = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].qRxLevMinEUTRA = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXhigh = FXL_UMTS_VALUE_NOT_APPLICABLE;
        g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXlow = FXL_UMTS_VALUE_NOT_APPLICABLE;
    }
}

void send3gListenModeScanCompInd(unsigned int result)
{
    memset(clientMsgBuf, 0, EXTERNAL_MESSAGE_SIZE);

    fxL3gListenModeScanCompInd *ind = (fxL3gListenModeScanCompInd *)msgBuf;

    ind->hdr.msgLength = sizeof(fxL3gListenModeScanCompInd);
    ind->hdr.msgType = FXL_3G_LISTEN_MODE_SCAN_COMP_IND;
    ind->hdr.rat = FXL_RAT_3G;

    if (0 == result)
    {
        ind->result = FXL_SUCCESS;
    }
    else
    {
        ind->result = FXL_FAILURE;
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gListenModeScanCompInd));

    return;
}

/*
 * Auto Boot L1 Image
 */
void autoBootL1Image(void)
{
    setNetworkDriverPriorityForLte(FALSE);

    switch (gAutoConfigCfg.dspType)
    {
    case FXL_PRIMARY_DSP:
        if (FXL_L1_UMTS_SLS_IMAGE == gAutoConfigCfg.l1Image)
        {
            unsigned int retCode = 0;

            /* Fill the Details */
            char *argValue[3] = {"dr", "RAT_SLS.img"};
            optreset = 1;

            retCode = g_Commands[12]->pfctCallBack(3, argValue);

            if (0 != retCode)
            {
                logPrint(LOG_DEBUG, "Loading UMTS SLS image on Primary DSP failed\n");
            }
        }
        else if (FXL_L1_UMTS_NATIVE_IMAGE == gAutoConfigCfg.l1Image)
        {
            unsigned int retCode = 0;

            /* Fill the Details */
            char *argValue[3] = {"dr", "-p", "UMTS_NATIVE.img"};
            optreset = 1;

            retCode = g_Commands[12]->pfctCallBack(3, argValue);

            if (0 != retCode)
            {
                logPrint(LOG_DEBUG, "Loading UMTS NATIVE image on Primary DSP failed\n");
            }
        }
        else
        {
            // Nothing to do
        }
        dspType = FXL_PRIMARY_DSP;
        sleep(3);
        if (-1 == system("/home/wgs/scripts/setGPSPri.sh"))
        {
            logPrint(LOG_DEBUG, "GPS setting failed\n");
        }
        break;

    case FXL_SECONDARY_DSP:
        if (FXL_L1_UMTS_SLS_IMAGE == gAutoConfigCfg.l1Image)
        {
            unsigned int retCode = 0;

            /* Fill the Details */
            char *argValue[3] = {"dr", "-s", "RAT_SLS.img"};
            optreset = 1;

            retCode = g_Commands[12]->pfctCallBack(3, argValue);

            if (0 != retCode)
            {
                logPrint(LOG_DEBUG, "Loading UMTS SLS image on Secondary DSP failed\n");
            }
        }
        else if (FXL_L1_UMTS_NATIVE_IMAGE == gAutoConfigCfg.l1Image)
        {
            unsigned int retCode = 0;

            /* Fill the Details */
            char *argValue[3] = {"dr", "-s", "UMTS_NATIVE.img"};
            optreset = 1;

            retCode = g_Commands[12]->pfctCallBack(3, argValue);

            if (0 != retCode)
            {
                logPrint(LOG_DEBUG, "Loading UMTS NATIVE image on Secondary DSP failed\n");
            }
        }
        else
        {
            // Nothing to do
        }
        dspType = FXL_SECONDARY_DSP;
        sleep(3);
        if (-1 == system("/home/wgs/scripts/setGPSSec.sh"))
        {
            logPrint(LOG_DEBUG, "GPS setting failed\n");
        }
        break;

    default:
        break;
    }
}

void sendListenModeSysInfoInd(void)
{
    int idx = 0, idx1 = 0;

    memset(clientMsgBuf, 0, EXTERNAL_MESSAGE_SIZE);

    fxL3gListenModeSystemInfoInd *ind = (fxL3gListenModeSystemInfoInd *)msgBuf;

    ind->hdr.msgLength = sizeof(fxL3gListenModeSystemInfoInd);
    ind->hdr.msgType = FXL_3G_LISTEN_MODE_SYSTEM_INFO_IND;
    ind->hdr.rat = FXL_RAT_3G;

    ind->band = g3gListenModeSysInfo.band;
    ind->uarfcn = g3gListenModeSysInfo.uarfcn;
    ind->lac = g3gListenModeSysInfo.lac;
    ind->rac = g3gListenModeSysInfo.rac;
    ind->t3212 = g3gListenModeSysInfo.t3212;
    ind->nmo = g3gListenModeSysInfo.nmo;

    ind->numOfPlmn = g3gListenModeSysInfo.numOfPlmn;

    for (idx1 = 0; idx1 < g3gListenModeSysInfo.numOfPlmn; idx1++)
    {
        if (g3gListenModeSysInfo.plmn[idx1].mccLength <= FXL_UMTS_MAX_MCC_LEN)
        {
            ind->plmn[idx1].mccLength = g3gListenModeSysInfo.plmn[idx1].mccLength;
            for (idx = 0; idx < ind->plmn[idx1].mccLength; idx++)
            {
                ind->plmn[idx1].mcc[idx] = g3gListenModeSysInfo.plmn[idx1].mcc[idx];
            }
        }
        else
        {
            ind->plmn[idx1].mccLength = 0;
            ind->plmn[idx1].mcc[0] = 0;
            ind->plmn[idx1].mcc[1] = 0;
            ind->plmn[idx1].mcc[2] = 0;
        }

        if (g3gListenModeSysInfo.plmn[idx1].mncLength <= FXL_UMTS_MAX_MNC_LEN)
        {
            ind->plmn[idx1].mncLength = g3gListenModeSysInfo.plmn[idx1].mncLength;
            for (idx = 0; idx < ind->plmn[idx1].mncLength; idx++)
            {
                ind->plmn[idx1].mnc[idx] = g3gListenModeSysInfo.plmn[idx1].mnc[idx];
            }
        }
        else
        {
            ind->plmn[idx1].mncLength = 0;
            ind->plmn[idx1].mnc[0] = 0;
            ind->plmn[idx1].mnc[1] = 0;
            ind->plmn[idx1].mnc[2] = 0;
        }
    }

    ind->pci = g3gListenModeSysInfo.pci;

    ind->numOfCell = 1;
    for (idx = 0; idx < ind->numOfCell; idx++)
    {
        ind->cellInfo[idx].rssi = g3gListenModeSysInfo.cellInfo[idx].rssi;
        ind->cellInfo[idx].rscp = g3gListenModeSysInfo.cellInfo[idx].rscp;
        ind->cellInfo[idx].ecio = g3gListenModeSysInfo.cellInfo[idx].ecio;
        ind->cellInfo[idx].psc = g3gListenModeSysInfo.cellInfo[idx].psc;
        ind->cellInfo[idx].cellSelReselInfo.qQualMin =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qQualMin;
        ind->cellInfo[idx].cellSelReselInfo.qRxLevMin =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qRxLevMin;
        ind->cellInfo[idx].cellSelReselInfo.qHystLS =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qHystLS;
        ind->cellInfo[idx].cellSelReselInfo.qHyst2S =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.qHyst2S;
        ind->cellInfo[idx].cellSelReselInfo.tReselS =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.tReselS;
        ind->cellInfo[idx].networkCellId = g3gListenModeSysInfo.cellInfo[idx].networkCellId;
        ind->cellInfo[idx].cellSelReselInfo.maxAllowedULTxPower =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.maxAllowedULTxPower;
        ind->cellInfo[idx].cellSelReselInfo.sIntraSearch =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sIntraSearch;
        ind->cellInfo[idx].cellSelReselInfo.sInterSearch =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sInterSearch;
        ind->cellInfo[idx].cellSelReselInfo.sSearchHCS =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sSearchHCS;
        ind->cellInfo[idx].cellSelReselInfo.ratSearch =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.ratSearch;
        ind->cellInfo[idx].cellSelReselInfo.sLimitSearchRAT =
            g3gListenModeSysInfo.cellInfo[idx].cellSelReselInfo.sLimitSearchRAT;
        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST; idx1++)
        {
            ind->cellInfo[idx].intraFreqCellList[idx1].psc = g3gListenModeSysInfo.cellInfo[idx].intraFreqCellList[idx1].psc;
            ind->cellInfo[idx].intraFreqCellList[idx1].cellId = g3gListenModeSysInfo.cellInfo[idx].intraFreqCellList[idx1].cellId;
        }

        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTER_FREQ_CELL_LIST; idx1++)
        {
            ind->cellInfo[idx].interFreqCellList[idx1].psc = g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].psc;
            ind->cellInfo[idx].interFreqCellList[idx1].cellId = g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].cellId;
            ind->cellInfo[idx].interFreqCellList[idx1].dlUarfcn = g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].dlUarfcn;
            ind->cellInfo[idx].interFreqCellList[idx1].ulUarfcn = g3gListenModeSysInfo.cellInfo[idx].interFreqCellList[idx1].ulUarfcn;
        }

        for (idx1 = 0; idx1 < FXL_UMTS_MAX_INTER_RAT_CELL_LIST; idx1++)
        {
            ind->cellInfo[idx].interRATCellList[idx1].ncc = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].ncc;
            ind->cellInfo[idx].interRATCellList[idx1].bcc = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].bcc;
            ind->cellInfo[idx].interRATCellList[idx1].band = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].band;
            ind->cellInfo[idx].interRATCellList[idx1].arfcn = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].arfcn;
            ind->cellInfo[idx].interRATCellList[idx1].cellId = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].cellId;
            ind->cellInfo[idx].interRATCellList[idx1].qRxLevMin = g3gListenModeSysInfo.cellInfo[idx].interRATCellList[idx1].qRxLevMin;
        }
    }

    ind->priorityCellInfo.servingCellPriority = g3gListenModeSysInfo.priorityCellInfo.servingCellPriority;
    ind->priorityCellInfo.s_PrioritySearch1 = g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch1;
    ind->priorityCellInfo.s_PrioritySearch2 = g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch2;
    ind->priorityCellInfo.threshServingLow = g3gListenModeSysInfo.priorityCellInfo.threshServingLow;

    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        ind->priorityCellInfo.fddPriorityCellInfo[idx].uarfcn = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].uarfcn;
        ind->priorityCellInfo.fddPriorityCellInfo[idx].priority = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].priority;
        ind->priorityCellInfo.fddPriorityCellInfo[idx].threshXhigh = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXhigh;
        ind->priorityCellInfo.fddPriorityCellInfo[idx].threshXlow = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXlow;
        ind->priorityCellInfo.fddPriorityCellInfo[idx].qQualMinFdd = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qQualMinFdd;
        ind->priorityCellInfo.fddPriorityCellInfo[idx].qRxLevMinFdd = g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qRxLevMinFdd;
    }

    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].arfcn = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].arfcn;
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].bandIndicator = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].bandIndicator;
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].priority = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].priority;
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].qRxLevMinGSM = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].qRxLevMinGSM;
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].threshXhigh = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXhigh;
        ind->priorityCellInfo.gsmPriorityCellInfo[idx].threshXlow = g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXlow;
    }

    for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
    {
        ind->priorityCellInfo.ltePriorityCellInfo[idx].earfcn = g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].earfcn;
        ind->priorityCellInfo.ltePriorityCellInfo[idx].priority = g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].priority;
        ind->priorityCellInfo.ltePriorityCellInfo[idx].qRxLevMinEUTRA = g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].qRxLevMinEUTRA;
        ind->priorityCellInfo.ltePriorityCellInfo[idx].threshXhigh = g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXhigh;
        ind->priorityCellInfo.ltePriorityCellInfo[idx].threshXlow = g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXlow;
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gListenModeSystemInfoInd));

    return;
}

/*
 * Stop UMTS Id Catcher
 */
fxLResult stop3gIdCatcherThread(void)
{
    SendMsgToTask(SOCK_ITF_TASK_E, APP_RRC_TASK_E, APP_STOP_ID_CATCHER_E, NULL);

    while (1)
    {
        if (pthread_tryjoin_np(gUmtsIdCatcherThreadId, NULL))
        {
            // logPrint(LOG_ERR , "UMTS ID Catcher Thread Join Failed\n");
        }
        else
            break;
    }

    /* Delete TCB */
    timerDestroy();
    pthread_mutex_destroy(&timerMutexLock);

    exitUmtsL1RcvThread = 1;
    while (1)
    {
        if (pthread_tryjoin_np(gL1RcvThreadId, NULL))
        {
            // logPrint(LOG_ERR , "UMTS Layer1 Recv Thread Join Failed\n");
        }
        else
            break;
    }
    exitUmtsL1RcvThread = 0;

    gClCntxt.cellState = CL_CELL_IDLE;
    memset(&gUmtsIdCatcherThreadId, 0, sizeof(gUmtsIdCatcherThreadId));
    memset(&gUmtsIdCatcherAttr, 0, sizeof(gUmtsIdCatcherAttr));
    memset(&gL1RcvThreadId, 0, sizeof(gL1RcvThreadId));
    memset(&gL1RcvThreadAttr, 0, sizeof(gL1RcvThreadAttr));

    return (FXL_SUCCESS);
}

/*
 * UMTS Native Configure Identity List
 */
#if 0
void umtsConfigureIdentityList (unsigned char* inMsgBuf)
{
    fxLConfigureIdentityListCmd *cmd = (fxLConfigureIdentityListCmd *)inMsgBuf;
    fxLConfigureIdentityListRsp *rsp = (fxLConfigureIdentityListRsp *)msgBuf;

    printf ("3G Identity List Configuration Command received...\n");
    rsp->hdr.msgLength = sizeof(fxLConfigureIdentityListRsp);
    rsp->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_RSP;
    rsp->hdr.rat = FXL_RAT_3G;

    if (cmd->noOfEntries > MAX_NO_OF_IDS_PER_TRANSACTION)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        configureRrcIdentityList (cmd);
        rsp->result = FXL_SUCCESS;
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxLConfigureIdentityListRsp));

    return;
}
#endif
/*
 * Create and Start UMTS Id Catcher
 */
fxLResult createAndStart3gIdCatcherThread(void)
{
    if (pthread_attr_init(&gUmtsIdCatcherAttr))
    {
        //        DEBUG1(("3G Id Catcher Thread Attribute creation failed\n"));
        return FXL_FAILURE;
    }

    if (pthread_attr_setstacksize(&gUmtsIdCatcherAttr, 100 * 1024) < 0)
    {
        //     DEBUG1(("3G Id Catcher Thread Attribute Stack Size failed\n"));
        return FXL_FAILURE;
    }

    if (pthread_create(&gUmtsIdCatcherThreadId, &gUmtsIdCatcherAttr, umtsIdCatcher, NULL))
    {
        //      DEBUG1(("3G Id Catcher Creation failed\n"));
        return FXL_FAILURE;
    }

    return FXL_SUCCESS;
}

void createAndInit4gContext(fxL4gConfigureIdCatcherParamsCmd *cmd)
{
    destroy4gContext();
    // Initialize SysLog
    logPrint(LOG_INFO, "############################################################################\n");
    logPrint(LOG_INFO, "*\n");
    logPrint(LOG_INFO, "*                             lteEnodeB\n");
    logPrint(LOG_INFO, "*\n");
    logPrint(LOG_INFO, "############################################################################\n");

    LTE_PHYSICAL_CELL_ID_VALUE = cmd->phyCellId;
    // Pre-Allocate Data Buffers
    allocateUlTxDataBuffer();
    allocateRrcDataBuffer();
    allocateDlConfigBuffer();
    allocateDlTxDataBuffer();
    allocateUlConfigBuffer();
    // Generate Sib1/2/3/4/5
    generateSib1(cmd);
    generateSibs(cmd);
    generateRrcConnectionRelmessage();

    lteRrcRedirectFlag = cmd->redirectionType;

    lteRrcPrmRedirectFlag = cmd->enablePrmredirectCfg;
    if (lteRrcPrmRedirectFlag)
        logPrint(LOG_DEBUG, "lteRrcPrmRedirectFlag:%d\n", lteRrcPrmRedirectFlag);

    generateRrcConnectionRelWithRedirect(cmd);
    generateIDTImeimessage();
    generateIDTImsimessage();
    generateAttachRejmessage(cmd);
    generateTAURejmessage();
    if (lteDuplxMode)
    {
        generateRrcConnectionSetupTDD();
    }
    else
    {
        generateRrcConnectionSetup();
    }
    generateRrcConnReestabReject();
    generateRrcUeCapaEnqMsg();
    generateRrcMeasConfigMsg(cmd);
    generateRrcReconfigReqMsg();
    lteUserManagerInit();
}
sint8 createThreadsForLteNativeApp()
{
    struct sched_param params;
    int coreId = 0;

    pthread_mutex_init(&mutexLteBlackListQ, NULL);
    pthread_mutex_init(&mutexlteRrcInd, NULL);
    pthread_cond_init(&condlteRrcInd, NULL);
    // Create Rx Thread for RRC Pdus
    if (pthread_create(&lteRrcIndThread, NULL, lteRrcIndMsgHandler, NULL))
    {
        logPrint(LOG_ERR, " RRC-Indication Thread creation failed");
        return -1;
    }

    usleep(100);
    pthread_mutex_init(&lteMutexTimerTickInd, NULL);
    pthread_cond_init(&lteCondTimerTickInd, NULL);
    // Create Timer Thread
    if (pthread_create(&lteTimerThread, NULL, lteTimerTickHandler, NULL))
    {
        logPrint(LOG_ERR, " Lte Timer Thread creation failed");
        return -1;
    }
    usleep(100);

    if (pthread_attr_init(&gLteIdCatcherAttr))
    {
        return -1;
    }

    if (pthread_attr_setstacksize(&gLteIdCatcherAttr, 100 * 1024) < 0)
    {
        return -1;
    }

    // Create receiver thread for Octasic L1 messages
    if (pthread_create(&lteL1MsgHandlerThread, &gLteIdCatcherAttr, lteL1MsgHandler, NULL))
    {
        logPrint(LOG_ERR, " L1 Interface Thread creation failed");
        return -1;
    }
    params.sched_priority = 90;
    pthread_setschedparam(lteL1MsgHandlerThread, SCHED_FIFO, &params);

    if (TRUE == isItPrimaryDsp())
    {
        coreId = 1;
    }
    else
    {
        coreId = 2;
    }

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(coreId, &cpuset);
    if (pthread_setaffinity_np(lteL1MsgHandlerThread, sizeof(cpu_set_t), &cpuset))
    {

        logPrint(LOG_ERR, "WARNING SetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d ,	%s \n", coreId, errno, strerror(errno));
        printf("WARNING SetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d , %s \n", coreId, errno, strerror(errno));

        if (pthread_getaffinity_np(lteL1MsgHandlerThread, sizeof(cpu_set_t), &cpuset))
        {
            logPrint(LOG_ERR, "WARNING GetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d ,  %s \n", coreId, errno, strerror(errno));
            printf("WARNING GetAffinity FAILEDDDDDDDDD Core Id = %d , Error No. = %d , %s \n", coreId, errno, strerror(errno));
        }
        else
        {
            logPrint(LOG_DEBUG, "L1 Interface Thread affinity details : \n");
            printf("L1 Interface Thread affinity details : \n");
            int j = 0;
            for (j = 0; j < CPU_SETSIZE; j++)
            {
                if (CPU_ISSET(j, &cpuset))
                {
                    logPrint(LOG_DEBUG, "CPU-%d \n", j);
                    printf("CPU-%d \n", j);
                }
            }
        }
    }

    pthread_mutex_init(&timerMutexLock, NULL);
    if (timerCreate(TCB_SIZE_4G, TCB_RESOLUTION_4G, "Timer Control Block") != 0)
    {
        logPrint(LOG_ERR, "Timer Creation FAILED with error \n");
        assert(0);
    }

    return 0;
}

sint8 destroyThreadsForLteNativeApp()
{
    sint8 ret = 0;
    exitLteApp = TRUE;
    usleep(5000);

    if (lteRrcIndThread != 0)
    {
        pthread_cancel(lteRrcIndThread);
    }
    if (lteTimerThread != 0)
    {
        pthread_cancel(lteTimerThread);
    }
    if (lteL1MsgHandlerThread != 0)
    {
        pthread_cancel(lteL1MsgHandlerThread);
    }

    currentOneBinState = ONEBIN_STATE_IDLE;
    memset(&lteRrcIndThread, 0, sizeof(lteRrcIndThread));
    memset(&lteTimerThread, 0, sizeof(lteTimerThread));
    memset(&lteL1MsgHandlerThread, 0, sizeof(lteL1MsgHandlerThread));
    memset(&gLteIdCatcherAttr, 0, sizeof(gLteIdCatcherAttr));
    pthread_mutex_destroy(&lteMutexTimerTickInd);
    pthread_cond_destroy(&lteCondTimerTickInd);
    pthread_mutex_destroy(&mutexlteRrcInd);
    pthread_cond_destroy(&condlteRrcInd);
    pthread_mutex_destroy(&mutexLteBlackListQ);
    return ret;
}

void listenMode4gConfigureBandsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gListenModeConfigureBandsCmd *cmd = (fxL4gListenModeConfigureBandsCmd *)inMsgBuf;
    fxL4gListenModeConfigureBandsRsp *rsp = (fxL4gListenModeConfigureBandsRsp *)msgBuf;
    static uint8 firstTimeLteScan = TRUE;
    rsp->result = FXL_FAILURE;
    if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
        currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
        currentDspImage == FXL_L1_LTE_SLS_IMAGE)
    {
        if ((reInitialiseLteScanData(cmd) != FALSE) || (firstTimeLteScan == TRUE))
        {
            ltebandMap = 0;
            deleteLteScanData();
        }
        configure4gWnmParameters(cmd);
        rsp->result = FXL_SUCCESS;
    }
    rsp->hdr.msgLength = sizeof(fxL4gListenModeConfigureBandsRsp);
    rsp->hdr.msgType = FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_RSP;
    rsp->hdr.rat = FXL_RAT_4G;
    firstTimeLteScan = FALSE;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gListenModeConfigureBandsRsp));

    return;
}

void listenMode4gStartScanCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gListenModeStartScanCmd *cmd = (fxL4gListenModeStartScanCmd *)inMsgBuf;
    fxL4gListenModeStartScanRsp *rsp = (fxL4gListenModeStartScanRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    rsp->result = FXL_FAILURE;
    if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
        currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
        currentDspImage == FXL_L1_LTE_SLS_IMAGE)
    {
        scanMode = cmd->scanType;
        if (createAndStartListenModeThread() == -1)
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Threads are not created \n");
        }
        else
        {
            logPrint(LOG_DEBUG, "Starting LTE Scanner....\n");
            currentOneBinState = ONEBIN_STATE_4G_SCANNING;
            rsp->result = FXL_SUCCESS;
        }
    }
    rsp->hdr.msgLength = sizeof(fxL4gListenModeStartScanRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_LISTEN_MODE_START_SCAN_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gListenModeStartScanRsp));

    return;
}

void listenMode4gStopScanCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gListenModeStopScanCmd *cmd = (fxL4gListenModeStopScanCmd *)inMsgBuf;
    fxL4gListenModeStopScanRsp *rsp = (fxL4gListenModeStopScanRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    rsp->result = FXL_FAILURE;

    if (currentOneBinState == ONEBIN_STATE_4G_SCANNING)
    {
        if ((currentDspImage == FXL_L1_GSM_SLS_IMAGE) ||
            (currentDspImage == FXL_L1_UMTS_SLS_IMAGE) ||
            (currentDspImage == FXL_L1_LTE_SLS_IMAGE))
        {
            currentOneBinState = ONEBIN_STATE_IDLE;
            scanMode = FXL_SCAN_TYPE_EXHAUSTIVE;
            rsp->result = stopListenModeApplication();
        }

        if (cmd->dspResetNeeded == 1)
        {
            unsigned int retCode = 0;
            /* Fill the Details */
            if ((isItPrimaryDsp() == TRUE))
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                retCode = g_Commands[12]->pfctCallBack(2, argValue);
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "Reset the primary DSP \n");
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                retCode = g_Commands[12]->pfctCallBack(2, argValue);
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "Reset the secondary DSP \n");
            }
        }
    }

    rsp->hdr.msgLength = sizeof(fxL4gListenModeStopScanRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_LISTEN_MODE_STOP_SCAN_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gListenModeStopScanRsp));

    return;
}

void send4gListenModeScanCompInd(void)
{
    fxL4gListenModeScanCompleteInd *ind = (fxL4gListenModeScanCompleteInd *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    ind->hdr.msgLength = sizeof(fxL4gListenModeScanCompleteInd);
    ind->hdr.msgType = FXL_4G_LISTEN_MODE_SCAN_COMPLETE_IND;
    ind->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gListenModeScanCompleteInd));

    return;
}

void updateLteDuplexMode(uint8 band)
{
    if ((band >= FXL_BAND_LTE_1) && (band <= FXL_BAND_LTE_32))
        lteDuplxMode = LTE_FDD;
    else if ((band >= FXL_BAND_LTE_33) && (band <= FXL_BAND_LTE_51))
        lteDuplxMode = LTE_TDD;
    else if (band == FXL_BAND_LTE_52)
        lteDuplxMode = LTE_TDD;
    else if ((band >= FXL_BAND_LTE_65) && (band <= FXL_BAND_LTE_85))
        lteDuplxMode = LTE_FDD;
    else
        lteDuplxMode = 2;
}

void lteConfigureIdCatcherParamsHandler(tOCT_UINT8 *inMsgBuf)
{
    uint8 i = 0, licCheck = cOCT_TRUE;
    fxL4gConfigureIdCatcherParamsCmd *cmd = (fxL4gConfigureIdCatcherParamsCmd *)inMsgBuf;
    fxL4gConfigureIdCatcherParamsRsp *rsp = (fxL4gConfigureIdCatcherParamsRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    rsp->result = FXL_SUCCESS;
#ifndef PUMP_REG_DATA
    idCatcherLteBand = cmd->bandIndicator; // Matching the enum value
    updateLteDuplexMode((uint8)cmd->bandIndicator);
    logPrint(LOG_DEBUG, "LTE DUPLEX MODE : (%d)", lteDuplxMode);
    cmd->bandIndicator = convertFxTo3gppLteBand(cmd->bandIndicator);
    logPrint(LOG_DEBUG, "EARFCN = %d , BandIndicator = %d , PhyCellId = %d\n", cmd->earfcn, cmd->bandIndicator, cmd->phyCellId);
    logPrint(LOG_DEBUG, "Tx-Attn = %d , RxGaindB = %d , BW = %d \n", cmd->txAttndB, cmd->ulRxGainDb, cmd->lteBandwidth);
    logPrint(LOG_DEBUG, "relativeD = %d \n", cmd->reserved);

    logPrint(LOG_DEBUG, "LTE Number of PLMN = %d\n", cmd->numOfPlmn);
    for (i = 0; i < cmd->numOfPlmn; i++)
    {
        logPrint(LOG_DEBUG, "MCC Length = %d\n", cmd->plmn[i].mccLength);
        logPrint(LOG_DEBUG, "PLMN[%d]-MCC Mcc-1 = %d , Mcc-2 = %d , Mcc-3 = %d\n", i, cmd->plmn[i].mcc[0], cmd->plmn[i].mcc[1], cmd->plmn[i].mcc[2]);
        logPrint(LOG_DEBUG, "MNC Length = %d\n", cmd->plmn[i].mncLength);
        logPrint(LOG_DEBUG, "PLMN[%d]-MNC Mnc-1 = %d , Mnc-2 = %d , Mnc-3 = %d\n", i, cmd->plmn[i].mnc[0], cmd->plmn[i].mnc[1], cmd->plmn[i].mnc[2]);
    }

#ifdef WGS_LICENSING
    if (lteDuplxMode == LTE_FDD)
    {
        licCheck = checkWgsFeatureLicense(cOCTVC1_WGS_LIC_LTE_FDD_ENABLE);
    }
    else if (lteDuplxMode == LTE_TDD)
    {
        licCheck = checkWgsFeatureLicense(cOCTVC1_WGS_LIC_LTE_TDD_ENABLE);
    }
#endif

    if ((lteDuplxMode > LTE_TDD) || (licCheck == cOCT_FALSE))
    {
        logPrint(LOG_ERR, "Wrong Configuration = %d or License Check = %d Failed for LTE ID Catcher \n", lteDuplxMode, licCheck);
        rsp->result = FXL_FAILURE;
        rsp->hdr.msgLength = sizeof(fxL4gConfigureIdCatcherParamsRsp);
        rsp->hdr.msgType = FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP;
        rsp->hdr.rat = FXL_RAT_4G;
        writeToExternalSocketInterface(msgBuf, sizeof(fxL4gConfigureIdCatcherParamsRsp));
        return;
    }
    if (cmd->redirectionType == REDIRECTION_TO_2G)
    {
        logPrint(LOG_DEBUG, "Redirected GSM-ARFCN = %d , BandIndicator = %d \n", cmd->redirectionInfo.gsmRedirectinfo.startingarfcn, cmd->redirectionInfo.gsmRedirectinfo.bandIndicator);
        if ((cmd->redirectionInfo.gsmRedirectinfo.bandIndicator > PCS1900) || (cmd->redirectionInfo.gsmRedirectinfo.bandIndicator < DCS1800))
            cmd->redirectionInfo.gsmRedirectinfo.bandIndicator = DCS1800;
    }
    else if (cmd->redirectionType == REDIRECTION_TO_3G)
    {
        logPrint(LOG_DEBUG, "Redirected UMTS-ARFCN = %d \n", cmd->redirectionInfo.utraFDDUARFCN);
    }
    else if (cmd->redirectionType == REDIRECTION_TO_4G)
    {
        logPrint(LOG_DEBUG, "Redirected LTE-EARFCN = %d \n", cmd->redirectionInfo.eutraEARFCN);
    }
    else if (cmd->redirectionType == REDIRECTION_TO_CDMA)
    {
        logPrint(LOG_DEBUG, "Redirected CDMA-ARFCN = %d , BandIndicator = %d \n", cmd->redirectionInfo.cdmaRedirectinfo.startingarfcn, cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator);
        if ((cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator < FXL_CDMA_BAND_0) || (cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator >= FXL_CDMA_MAX_BAND_SUPPORTED))
        {
            cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator = FXL_CDMA_BAND_0;
        }
    }

    if (cmd->AutoConfigureEnabled == TRUE)
    {
        if (searchLteScanDataToFindAutoConfigParams(cmd) == TRUE)
        {
            updateLteDuplexMode((uint8)cmd->bandIndicator);
            logPrint(LOG_DEBUG, "LTE DUPLEX MODE : (%s)", (lteDuplxMode == 0) ? "LTE_FDD" : "LTE_TDD");
            logPrint(LOG_DEBUG, "Auto Config Chosen EARFCN = %d , BandIndicator = %d , PhyCellId = %d\n", cmd->earfcn, cmd->bandIndicator, cmd->phyCellId);
            logPrint(LOG_DEBUG, "Layer3CellId = %d , TAC = %d , Bandwidth = %d \n", cmd->layer3CellId, cmd->tac, lteSelectedBandwidth);
            logPrint(LOG_DEBUG, "relativeD = %d \n", cmd->reserved);
        }
        else
        {
            logPrint(LOG_ERR, "Wrong Input/No Scan Data in AutoConfig \n");
            rsp->result = FXL_FAILURE;
            rsp->hdr.msgLength = sizeof(fxL4gConfigureIdCatcherParamsRsp);
            rsp->hdr.msgType = FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP;
            rsp->hdr.rat = FXL_RAT_4G;
            writeToExternalSocketInterface(msgBuf, sizeof(fxL4gConfigureIdCatcherParamsRsp));
            return;
        }
    }
    else
    {
        if (lteDuplxMode == LTE_FDD)
        {
            if ((cmd->lteBandwidth == LTE_BW_N6) || (cmd->lteBandwidth == LTE_BW_N15) || (cmd->lteBandwidth == LTE_BW_N25) || (cmd->lteBandwidth == LTE_BW_N50) || (cmd->lteBandwidth == LTE_BW_N100))
                lteSelectedBandwidth = cmd->lteBandwidth;
            else
                lteSelectedBandwidth = LTE_BW_N50;
        }
        else
        {
            if ((cmd->lteBandwidth == LTE_BW_N25) || (cmd->lteBandwidth == LTE_BW_N50) ||
                (cmd->lteBandwidth == LTE_BW_N100) || (cmd->lteBandwidth == LTE_BW_N75))
                lteSelectedBandwidth = cmd->lteBandwidth;
            else
                lteSelectedBandwidth = LTE_BW_N50;
        }
    }
    logPrint(LOG_DEBUG, "Layer3CellId = %d , TAC = %d, Bandwidth = %d \n", cmd->layer3CellId, cmd->tac, lteSelectedBandwidth);

    if ((cmd->maxTaValue > 0) && (cmd->maxTaValue <= 63))
    {
        minRachTaValue = cmd->minTaValue;
        maxRachTaValue = cmd->maxTaValue;
    }
    else
    {
        minRachTaValue = 0;
        maxRachTaValue = LTE_RACH_TA_DEFAULT; // default value
    }
    pilot_boost_enabled = cmd->pilot_boost_enable;

    logPrint(LOG_DEBUG, "value of cmd->minTaValue is %d Min RachTaValue = %d \n", cmd->minTaValue, minRachTaValue);
    logPrint(LOG_DEBUG, "value of cmd->maxTaValue is %d Max RachTaValue = %d \n", cmd->maxTaValue, maxRachTaValue);
    logPrint(LOG_DEBUG, "Pilot Boost Enable = %d \n", pilot_boost_enabled);

    idCatcherLteEarfcn = cmd->earfcn;
    idCatcherLteWlRedirEarfcn = cmd->wlRedirectEarfcn;

    gLteRrcMeasData.dlEarfcn = cmd->earfcn;
    gLteRrcMeasData.bandWidth = lteSelectedBandwidth;
    gLteRrcMeasData.pci = cmd->phyCellId;
    // cmd->ulRxGainDb = 45;

    if (currentDspImage == FXL_L1_LTE_NATIVE_IMAGE) // First time we are getting configuration
    {
        lteRfConfig rfConfig = {0};
        rfConfig.earfcn = cmd->earfcn;
        rfConfig.txAttnDb = cmd->txAttndB;
        rfConfig.ulRxGainDb = cmd->ulRxGainDb;
        rfConfig.cellBandWidth = (int)lteSelectedBandwidth;
        rfConfig.f_enodebStartOrStop = TRUE;
        rfConfig.islteTDD = (int)lteDuplxMode;
        rfConfig.relativeD = cmd->reserved;
        // Set RF first
        if (lteEnodebConfig(&rfConfig) != 0)
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "LTE RF Band/Frequency configuration Failed\n");
            if (isItPrimaryDsp() == TRUE)
            {
                char *argValue[2] = {"dr", "-p"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
            else
            {
                char *argValue[2] = {"dr", "-s"};
                optreset = 1;
                g_Commands[12]->pfctCallBack(2, argValue);
            }
        }
        else
        {
            if (lteOpenRawSocketInterface() != L1IF_NO_ERROR)
            {
                rsp->result = FXL_FAILURE;
                logPrint(LOG_ERR, "RAW Socket OPEN Failed\n");
            }
            else
            {
                /*if(lastLteIdCatcherConfigCmd.hdr.msgLength != 0) //Not the first time
                {
                    //Set the TAC 1 plus from the earlier used running value
                    cmd->tac = ++lastLteIdCatcherConfigCmd.tac;
                }*/
                createAndInit4gContext(cmd);
                logPrint(LOG_DEBUG, "LTE ID Catcher Configuration Successful ! \n");
            }
        }
        cmd->hdr.rat = cmd->tac; // saving start value of tac here.
        memcpy((uint8 *)&lastLteIdCatcherConfigCmd, (uint8 *)cmd, sizeof(fxL4gConfigureIdCatcherParamsCmd));
        logPrint(LOG_DEBUG, "Layer3CellId = %d , TAC = %d , redirectionType = %d\n", cmd->layer3CellId, cmd->tac, cmd->redirectionType);

        lteIdCatcherRunning = 1;
#ifdef CELL_ANTENNA_CHANGE
        char dspType;
        int bandValue = 0;
        if (TRUE == isItPrimaryDsp())
        {
            dspType = '1';
        }
        else
        {
            dspType = '2';
        }

        bandValue = lastLteIdCatcherConfigCmd.bandIndicator;

        configureCellAntennaPA(dspType, bandValue, 'i');
#endif
    }
    else
    {
        rsp->result = FXL_FAILURE;
        lteIdCatcherRunning = 0;
    }
#endif
    rsp->hdr.msgLength = sizeof(fxL4gConfigureIdCatcherParamsRsp);
    rsp->hdr.msgType = FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gConfigureIdCatcherParamsRsp));
#ifndef PUMP_REG_DATA
    usleep(1000);
    if (cmd->AutoConfigureEnabled == TRUE)
    {
        fxL4gAutoConfigEarfcnInd earfcnInd;
        memset(&earfcnInd, 0, sizeof(fxL4gAutoConfigEarfcnInd));
        earfcnInd.hdr.msgLength = sizeof(fxL4gAutoConfigEarfcnInd);
        earfcnInd.hdr.msgType = FXL_4G_AUTO_CONFIG_EARFCN_IND;
        earfcnInd.hdr.rat = FXL_RAT_4G;
        earfcnInd.earfcn = cmd->earfcn;
        earfcnInd.phyCellId = cmd->phyCellId;
        earfcnInd.layer3CellId = cmd->layer3CellId;
        earfcnInd.tac = cmd->tac;
        earfcnInd.bandIndicator = idCatcherLteBand;
        earfcnInd.bandwidth = lteSelectedBandwidth;
        writeToExternalSocketInterface((tOCT_UINT8 *)&earfcnInd, sizeof(fxL4gAutoConfigEarfcnInd));
    }
#endif
    return;
}

void lteStartIdCatcherHandler(tOCT_UINT8 *inMsgBuf)
{
    uint8 i = 0, j = 0;
    fxL4gStartIdCatcherRsp *rsp = (fxL4gStartIdCatcherRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    realNwTac = 0;
#ifdef FEA_PICSIX_CHANGE
    send4gStatusInd = FALSE;
#endif

#ifndef PUMP_REG_DATA
#ifdef FXL_4G_TX_JAMMER
    lteJamCellFound = FALSE;
#endif

#if defined(OBM_PA_BTS8500_NW) || defined(OBM_PA_BTS8500_WW)
    system("obm rf 1 1");
#endif
    if (currentDspImage == FXL_L1_LTE_NATIVE_IMAGE) // First time we are getting configuration
    {

        if (createThreadsForLteNativeApp() == -1)
        {
            lteIdCatcherRunning = 0;
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "LTE Threads are not created \n");
        }
        else
        {
            rsp->result = FXL_SUCCESS;
            printf("\n######################################################\n");
            printf("LTE ID Catcher is UP & RUNNING ! \n");
            printf("Number of PLMN = %d\n", lastLteIdCatcherConfigCmd.numOfPlmn);
            for (i = 0; i < lastLteIdCatcherConfigCmd.numOfPlmn; i++)
            {
                printf("PLMN[%d] MCC Length = %d\n", i, lastLteIdCatcherConfigCmd.plmn[i].mccLength);
                for (j = 0; j < lastLteIdCatcherConfigCmd.plmn[i].mccLength; j++)
                {
                    printf("MCC[%d] = %d ", j, lastLteIdCatcherConfigCmd.plmn[i].mcc[j]);
                }
                printf("\n");

                printf("PLMN[%d] MNC Length = %d\n", i, lastLteIdCatcherConfigCmd.plmn[i].mncLength);
                for (j = 0; j < lastLteIdCatcherConfigCmd.plmn[i].mncLength; j++)
                {
                    printf("MNC[%d] = %d ", j, lastLteIdCatcherConfigCmd.plmn[i].mnc[j]);
                }
                printf("\n");
            }
            printf("Layer3CellId = %d , TAC = %d , PhyCellId = %d\n", lastLteIdCatcherConfigCmd.layer3CellId, lastLteIdCatcherConfigCmd.tac, lastLteIdCatcherConfigCmd.phyCellId);
            printf("\n######################################################\n");
            ltePageAllConfifguredTargetPhone();
        }
    }
    else
    {
        lteIdCatcherRunning = 0;
        rsp->result = FXL_FAILURE;
    }
#else
    rsp->result = FXL_SUCCESS;
#endif

    rsp->hdr.msgLength = sizeof(fxL4gStartIdCatcherRsp);
    rsp->hdr.msgType = FXL_4G_START_IDCATCHER_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gStartIdCatcherRsp));
#ifdef PUMP_REG_DATA
    sleep(1);
    startPumpData();
#endif

#ifdef FEA_PICSIX_CHANGE
    if (rsp->result == FXL_SUCCESS && send4gStatusInd == FALSE)
    {
        /* Send system status indication */
        sendSystemStatusIndication(FXL_4G_IDC, FXL_STARTED);
    }
#endif
    return;
}

void lteStopIdCatcherHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gStopIdCatcherRsp *rsp = (fxL4gStopIdCatcherRsp *)msgBuf;
    fxL4gStopIdCatcherCmd *cmd = (fxL4gStopIdCatcherCmd *)inMsgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
#ifndef PUMP_REG_DATA
    lteIdCatcherRunning = 0;
    stopLteScForAllBlUser();
    // usleep(4500);

    lteRfConfig rfConfig = {0};
    rfConfig.earfcn = cmd->dspResetNeeded;
    rfConfig.txAttnDb = 0;
    rfConfig.ulRxGainDb = 0;
    rfConfig.cellBandWidth = (int)lteSelectedBandwidth;
    rfConfig.f_enodebStartOrStop = FALSE;
    rfConfig.islteTDD = (int)lteDuplxMode;
    rfConfig.relativeD = 0;

#ifdef FEA_PICSIX_CHANGE
    timerStop(&systemStatusTimer);
    if (NULL != systemStatusTimer.parm)
    {
        free(systemStatusTimer.parm);
        systemStatusTimer.parm = NULL;
    }
    memset((tcbTimer_t *)&systemStatusTimer, 0, sizeof(tcbTimer_t));
#endif

    memset(rsp, 0, sizeof(fxL4gStopIdCatcherRsp));
    destroyThreadsForLteNativeApp();
    buildAndSendPhyStopReq(); // Calling after read loop is broken. Read loop breaks on every subframe indication
    usleep(500);
    // setNetworkDriverPriorityForLte(FALSE);

    if (lteEnodebConfig(&rfConfig) != 0) // Enodeb cell Stop
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "LTE ENodeB Stop Failed\n");
    }

    lteCloseRawSocketInterface();
    lteSelectedBandwidth = LTE_BW_N50;
    minRachTaValue = 0;
    maxRachTaValue = LTE_RACH_TA_DEFAULT;
    memset((asnLteNeighborConfig *)&gAsnLteNeighConfigData, 0, sizeof(gAsnLteNeighConfigData));

#ifdef FXL_4G_TX_JAMMER
    lteJamCellFound = FALSE;
#endif
    if (cmd->dspResetNeeded == TRUE)
    {
        if (isItPrimaryDsp() == TRUE)
        {
            char *argValue[2] = {"dr", "-p"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }
        else
        {
            char *argValue[2] = {"dr", "-s"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }
    }
#else
    stopPumpData();
#endif
    rsp->result = FXL_SUCCESS;
    rsp->hdr.msgLength = sizeof(fxL4gStopIdCatcherRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_STOP_IDCATCHER_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gStopIdCatcherRsp));
#ifndef PUMP_REG_DATA
    destroy4gContext();
    exitLteApp = FALSE;
#endif
    return;
}

void sendModifyEarfcnRsp(unsigned char success)
{
    fxL4gModifyEarfcnRsp modifyEarfcnRsp;
    memset((fxL4gModifyEarfcnRsp *)&modifyEarfcnRsp, 0, sizeof(fxL4gModifyEarfcnRsp));

    modifyEarfcnRsp.hdr.msgLength = sizeof(fxL4gModifyEarfcnRsp);
    modifyEarfcnRsp.hdr.rat = FXL_RAT_4G;
    modifyEarfcnRsp.hdr.msgType = FXL_4G_MODIFY_EARFCN_RSP;

    if (1 == success)
    {
        modifyEarfcnRsp.result = FXL_SUCCESS;
    }
    else
    {
        modifyEarfcnRsp.result = FXL_FAILURE;
    }

    logPrint(LOG_INFO, "Send Modify EARFCN Response with status as %d\n", modifyEarfcnRsp.result);
    writeToExternalSocketInterface((uint8 *)&modifyEarfcnRsp, sizeof(fxL4gModifyEarfcnRsp));
}

void lteModifyEarfcnCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gModifyEarfcnCmd *cmd = (fxL4gModifyEarfcnCmd *)inMsgBuf;
    unsigned int receivedBand;

    /* Check Configured EARFCN & Received EARFCN is within same band or not */
    receivedBand = getLteBandFromEARFCN(cmd->dlEarfcn);
    logPrint(LOG_ERR, "old earfcn was %d\n", idCatcherLteEarfcn);
    logPrint(LOG_ERR, "new earfcn is %d, configuredBand and receivedBand are %d %d\n", cmd->dlEarfcn, idCatcherLteBand + 1, receivedBand + 1);

    if (idCatcherLteBand != receivedBand)
    {
        logPrint(LOG_ERR, "Configured DL EARFCN (%d) should be within the range of Band%d\n",
                 cmd->dlEarfcn, (idCatcherLteBand + 1));
        sendModifyEarfcnRsp(0);
        return;
    }

    stopLteScForAllBlUser();
    usleep(5000);
    changeEarfcn = TRUE;
    deleteAllUserForChangeEarfcn();

    if (0 != LteCellModifyRfEARFCN(cmd->dlEarfcn))
    {
        sendModifyEarfcnRsp(0);
    }
    else
    {
        idCatcherLteEarfcn = cmd->dlEarfcn;
        lastLteIdCatcherConfigCmd.earfcn = cmd->dlEarfcn;
        sendModifyEarfcnRsp(1);
    }
    changeEarfcn = FALSE;
}

uint8 reInitialiseGsmScanData(fxL2gListenModeConfigureBandsCmd *cmd)
{
    uint8 ret = FALSE;
    for (uint8 i = 0; i < cmd->noOfBandsToScan; i++)
    {
        if (cmd->band[i] == FXL_BAND_GSM_850)
        {
            if ((bandMap & SET_GSM_BAND_850) == SET_GSM_BAND_850)
            {
                ret = ret | SET_GSM_BAND_850;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_850;
            }
        }
        else if (cmd->band[i] == FXL_BAND_DCS_1800)
        {
            if ((bandMap & SET_GSM_BAND_1800) == SET_GSM_BAND_1800)
            {
                ret = ret | SET_GSM_BAND_1800;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_1800;
            }
        }
        else if (cmd->band[i] == FXL_BAND_PCS_1900)
        {
            if ((bandMap & SET_GSM_BAND_1900) == SET_GSM_BAND_1900)
            {
                ret = ret | SET_GSM_BAND_1900;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_1900;
            }
        }
        else if (cmd->band[i] == FXL_BAND_E_GSM)
        {
            if ((bandMap & SET_GSM_BAND_E900) == SET_GSM_BAND_E900)
            {
                ret = ret | SET_GSM_BAND_E900;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_E900;
            }
        }
        else if (cmd->band[i] == FXL_BAND_R_GSM)
        {
            if ((bandMap & SET_GSM_BAND_R900) == SET_GSM_BAND_R900)
            {
                ret = ret | SET_GSM_BAND_R900;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_R900;
            }
        }
        else if (cmd->band[i] == FXL_BAND_GSM_450)
        {
            if ((bandMap & SET_GSM_BAND_450) == SET_GSM_BAND_450)
            {
                ret = ret | SET_GSM_BAND_450;
            }
            else
            {
                bandMap = bandMap | SET_GSM_BAND_450;
            }
        }
    }

    if (ret != FALSE)
        bandMap = ret; // Reinitialise again
    return ret;
}

#ifdef FEA_ALERT
void alertBlacklist(tOCT_UINT8 *inMsgBuf)
{
    fxL2gStartAlertBlacklistCmd *cmd = (fxL2gStartAlertBlacklistCmd *)inMsgBuf;
    fxL2gStartAlertBlacklistRsp *rsp = (fxL2gStartAlertBlacklistRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);

    // TBD Implement search based on UeIndex
    if ((blackUserInfo != NULL) && (blackUserInfo->bitMaskForTriggers != SET_TRIGGER_FOR_ALERTING))
    {
        blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_ALERTING;

        logPrint(LOG_DEBUG, "Trigger for Alerting set : Curr val 0x%x\n", blackUserInfo->bitMaskForTriggers);
        logPrint(LOG_DEBUG, "MSISDN rcvd is %s\n", cmd->callingPartyIsdnStr);

        // Check the validity of MSISDN, i.e., Either NULL or first char is '+' and rest are all numbers
        tOCT_UINT8 isValidMsIsdn = FALSE;
        char *msIsdnStr;

        if (cmd->callingPartyIsdnStr == NULL)
        {
            isValidMsIsdn = TRUE;
        }
        else
        {
            if (cmd->callingPartyIsdnStr[0] == '+')
            {
                isValidMsIsdn = TRUE;
                msIsdnStr = &cmd->callingPartyIsdnStr[1];
                while (*msIsdnStr)
                {
                    if (isdigit(*msIsdnStr++) == 0)
                    {
                        isValidMsIsdn = FALSE;
                        break;
                    }
                }
            }
        }

        if (isValidMsIsdn)
        {
            if (cmd->callingPartyIsdnStr == NULL)
            {
                logPrint(LOG_DEBUG, "MSISDN is UNKNOWN\n");
                memset(blackUserInfo->alertIsdn_str, 0, MAX_IDENTITY_LENGTH_STR);
            }
            else
            {
                logPrint(LOG_DEBUG, "MSISDN is %s\n", cmd->callingPartyIsdnStr);
                memcpy(blackUserInfo->alertIsdn_str, cmd->callingPartyIsdnStr, MAX_IDENTITY_LENGTH_STR);
            }

            pushPagingReqToPageQ(blackUserInfo);

            blackUserInfo->triggerPagingReq = TRUE;

            rsp->result = FXL_SUCCESS;
        }
        else
        {
            blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_ALERTING;
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Invalid ISDN\n");
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in blacklist list OR Already Alerting");
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gStartAlertBlacklistRsp);
    rsp->hdr.msgType = FXL_2G_ALERT_BLACKLIST_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gStartAlertBlacklistRsp));
    return;
}
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET
void setMoMsisdnForTargetVoiceCall(tOCT_UINT8 *inMsgBuf)
{
    fxL2gSetMoMsisdnForTargetVoiceCallCmd *cmd = (fxL2gSetMoMsisdnForTargetVoiceCallCmd *)inMsgBuf;
    fxL2gSetMoMsisdnForTargetVoiceCallRsp *rsp = (fxL2gSetMoMsisdnForTargetVoiceCallRsp *)msgBuf;
    blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE, FALSE);

    /* TBD Implement search based on UeIndex */
    if (blackUserInfo != NULL)
    {
        logPrint(LOG_DEBUG, "MO-MSISDN(%s) received for Target Voice Call(IMSI = %s)", cmd->moMsIsdnStr, cmd->imsiStr);

        // Check the validity of MSISDN, first char is '+' and rest are all numbers
        tOCT_UINT8 isValidMsIsdn = FALSE;
        char *msIsdnStr;

        if (cmd->moMsIsdnStr != NULL)
        {
            if (cmd->moMsIsdnStr[0] == '+')
            {
                isValidMsIsdn = TRUE;
                msIsdnStr = &cmd->moMsIsdnStr[1];
                while (*msIsdnStr)
                {
                    if (isdigit(*msIsdnStr++) == 0)
                    {
                        isValidMsIsdn = FALSE;
                        break;
                    }
                }
            }
        }

        if (isValidMsIsdn)
        {
            memset(targetVoiceCallCntxt.moMsIsdnStr, 0, MAX_IDENTITY_LENGTH_STR);
            memcpy(targetVoiceCallCntxt.moMsIsdnStr, cmd->moMsIsdnStr, MAX_IDENTITY_LENGTH_STR);

            memset(targetVoiceCallCntxt.moImsiStr, 0, MAX_IDENTITY_LENGTH_STR);
            memcpy(targetVoiceCallCntxt.moImsiStr, cmd->imsiStr, MAX_IDENTITY_LENGTH_STR);

            logPrint(LOG_DEBUG, "Call Context updated(MO-MSISDN = %s, MO-IMSI = %s)", targetVoiceCallCntxt.moMsIsdnStr, targetVoiceCallCntxt.moImsiStr);

            rsp->result = FXL_SUCCESS;
        }
        else
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Invalid MO-MSISDN\n");
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "setMoMsisdnForTargetVoiceCall(): Could not find IMSI in blacklist list");
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL2gSetMoMsisdnForTargetVoiceCallRsp);
    rsp->hdr.msgType = FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gSetMoMsisdnForTargetVoiceCallRsp));
    return;
}
#endif /* FEA_VOICE_CALL_TO_TARGET */

void generateSib1WithNewTA()
{
    uint8 systemInfoTag = 0;
    static uint8 counter = 1;

    if ((realNwTac == 0) && (lastLteIdCatcherConfigCmd.AutoConfigureEnabled == TRUE))
    {
        realNwTac = lastLteIdCatcherConfigCmd.tac - 1;
    }
    lastLteIdCatcherConfigCmd.tac++;
    if (lastLteIdCatcherConfigCmd.tac == 0x0000FFFF)
    {
        lastLteIdCatcherConfigCmd.tac = 0;
    }

    if ((lastLteIdCatcherConfigCmd.tac == realNwTac) && (lastLteIdCatcherConfigCmd.AutoConfigureEnabled == TRUE))
    {
        lastLteIdCatcherConfigCmd.tac++;
    }
    generateSib1(&lastLteIdCatcherConfigCmd);

    fxL4gNewConfiguredTacInd newTacInd;
    memset(&newTacInd, 0, sizeof(fxL4gNewConfiguredTacInd));
    newTacInd.hdr.msgLength = sizeof(fxL4gNewConfiguredTacInd);
    newTacInd.hdr.msgType = FXL_4G_NEW_CONFIGURED_TAC_IND;
    newTacInd.hdr.rat = FXL_RAT_4G;
    newTacInd.tac = lastLteIdCatcherConfigCmd.tac;
    writeToExternalSocketInterface((tOCT_UINT8 *)&newTacInd, sizeof(fxL4gNewConfiguredTacInd));

    /*
       logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[0],asn1EncodedSib1[1],asn1EncodedSib1[2],asn1EncodedSib1[3],asn1EncodedSib1[4],asn1EncodedSib1[5]);
       logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[6],asn1EncodedSib1[7],asn1EncodedSib1[8],asn1EncodedSib1[9],asn1EncodedSib1[10],asn1EncodedSib1[11]);
       logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[12],asn1EncodedSib1[13],asn1EncodedSib1[14],asn1EncodedSib1[15],asn1EncodedSib1[16],asn1EncodedSib1[17]);
       */
}

void generateSib1WithNewTARrcThrd()
{
    uint8 systemInfoTag = 0;
    static uint8 counter = 1;

    if ((realNwTac == 0) && (lastLteIdCatcherConfigCmd.AutoConfigureEnabled == TRUE))
    {
        realNwTac = lastLteIdCatcherConfigCmd.tac - 1;
    }
    lastLteIdCatcherConfigCmd.tac++;
    if (lastLteIdCatcherConfigCmd.tac == 0x0000FFFF)
    {
        lastLteIdCatcherConfigCmd.tac = 0;
    }

    if ((lastLteIdCatcherConfigCmd.tac == realNwTac) && (lastLteIdCatcherConfigCmd.AutoConfigureEnabled == TRUE))
    {
        lastLteIdCatcherConfigCmd.tac++;
    }
    generateSib1RrcThrd(&lastLteIdCatcherConfigCmd);

    fxL4gNewConfiguredTacInd newTacInd;
    memset(&newTacInd, 0, sizeof(fxL4gNewConfiguredTacInd));
    newTacInd.hdr.msgLength = sizeof(fxL4gNewConfiguredTacInd);
    newTacInd.hdr.msgType = FXL_4G_NEW_CONFIGURED_TAC_IND;
    newTacInd.hdr.rat = FXL_RAT_4G;
    newTacInd.tac = lastLteIdCatcherConfigCmd.tac;
    writeToExternalSocketInterface((tOCT_UINT8 *)&newTacInd, sizeof(fxL4gNewConfiguredTacInd));

    /*
        logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[0],asn1EncodedSib1[1],asn1EncodedSib1[2],asn1EncodedSib1[3],asn1EncodedSib1[4],asn1EncodedSib1[5]);
        logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[6],asn1EncodedSib1[7],asn1EncodedSib1[8],asn1EncodedSib1[9],asn1EncodedSib1[10],asn1EncodedSib1[11]);
        logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",asn1EncodedSib1[12],asn1EncodedSib1[13],asn1EncodedSib1[14],asn1EncodedSib1[15],asn1EncodedSib1[16],asn1EncodedSib1[17]);
    */
}

void configureLteFreqForSelectiveScanCmdHandler(uint8 *inMsgBuf)
{
    fxL4gListenModeConfigureSelectiveFreqRsp *rsp = (fxL4gListenModeConfigureSelectiveFreqRsp *)msgBuf;
    fxL4gListenModeConfigureSelectiveFreqCmd *cmd = (fxL4gListenModeConfigureSelectiveFreqCmd *)inMsgBuf;

    rsp->result = configureLteFreqForSelectiveScan(cmd);
    rsp->hdr.msgLength = sizeof(fxL4gListenModeConfigureSelectiveFreqRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gListenModeConfigureSelectiveFreqRsp));

    return;
}

void lteBlUeRedirectCmdHandler(uint8 *inMsgBuf)
{
    fxL4gBLUeRedirectCmd *cmd = (fxL4gBLUeRedirectCmd *)inMsgBuf;
    fxL4gBLUeRedirectRsp *rsp = (fxL4gBLUeRedirectRsp *)msgBuf;

    lteblackListedUserInfo *blackUserInfo = blacklistLteUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE);
    int ueIndex = getLteUeIndxFromImsi(cmd->imsiStr);
    if ((blackUserInfo != NULL) && (0xFFFFFFFF != ueIndex))
    {
        updateAndBuildRrcConRelWithRedirect(ueIndex, cmd->redirectionType, cmd->redirectionInfo);
        buildAndSendSibChangePagingMsg(blackUserInfo, TRUE);
        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI in lte blacklist list\n");
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL4gBLUeRedirectRsp);
    rsp->hdr.msgType = FXL_4G_BL_UE_REDIRECT_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gBLUeRedirectRsp));
    return;
}

void lteBlUserReleaseCmdHandler(unsigned char *inMsgBuf)
{
    fxL4gRlsBlUsersCmd *cmd = (fxL4gRlsBlUsersCmd *)inMsgBuf;
    fxL4gRlsBlUsersRsp *rsp = (fxL4gRlsBlUsersRsp *)msgBuf;
    fxLConfigureIdentityListCmd *identityListcmd = NULL;
    lteRelUeFlag = TRUE;
    unsigned int idx = 0;
    char *imsiStr = NULL;
    logPrint(LOG_DEBUG, "4G Release BL Users Command received...\n");
    { // User Identity list configuration Modification  from BL to WL
        identityListcmd = (fxLConfigureIdentityListCmd *)malloc(sizeof(fxLConfigureIdentityListCmd));
        identityListcmd->hdr.msgLength = sizeof(fxLConfigureIdentityListCmd);
        identityListcmd->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_CMD;
        identityListcmd->hdr.rat = FXL_RAT_4G;
        identityListcmd->noOfEntries = cmd->noOfEntries;
        memcpy(identityListcmd->configList, cmd->blRlsUserList, MAX_NO_OF_IDS_PER_TRANSACTION * sizeof(fxLIdentityConfig));
        configureIdentityListCmdHandler(identityListcmd, 2);
    }

    for (idx = 0; idx < cmd->noOfEntries; idx++)
    {
        imsiStr = (char *)malloc(SIZE_OF_IDENTITY_STR * sizeof(char));
        memset((char *)imsiStr, 0, (SIZE_OF_IDENTITY_STR * sizeof(char)));

        strncpy(imsiStr, cmd->blRlsUserList[idx].identity, SIZE_OF_IDENTITY_STR);

        lteblackListedUserInfo *blackUserInfo = blacklistLteUserFindUsingIdentity(imsiStr, FALSE);
        int ueIndex = getLteBLUeIndxFromImsi(imsiStr);
        logPrint(LOG_DEBUG, "BL User  IMSI %s,UeIndex %d\n", imsiStr, ueIndex);
        if ((blackUserInfo != NULL) && (0xFFFFFFFF != ueIndex))
        {
            blackUserInfo->lteSilentCallStarted = FALSE;
            lteSilentCallStarted = FALSE;
            buildAndEncodeAttachRejMsg(ueIndex);
            updateAndBuildRrcConRel(ueIndex);
            buildAndSendSibChangePagingMsg(blackUserInfo, TRUE);
            logPrint(LOG_DEBUG, "updateandBuildRrcConnRel for IMSI %s,UeIndex %d\n", imsiStr, ueIndex);
        }
    }

    rsp->hdr.msgLength = sizeof(fxL4gRlsBlUsersRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_BL_USER_RELEASE_RSP;
    rsp->result = FXL_SUCCESS;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gRlsBlUsersRsp));
    free(identityListcmd);
    identityListcmd = NULL;
    return;
}

void lteStartSilentCallCommandHandler(uint8 *inMsgBuf)
{
    fxL4gStartSilentCallCmd *cmd = (fxL4gStartSilentCallCmd *)inMsgBuf;
    fxL4gStartSilentCallRsp *rsp = (fxL4gStartSilentCallRsp *)msgBuf;
    lteblackListedUserInfo *blackUserInfo = NULL;
    memset(msgBuf, 0, sizeof(msgBuf));
    if (lastLteIdCatcherConfigCmd.redirectionType == NO_REDIRECTION)
    {
        blackUserInfo = blacklistLteUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE);
    }
    cmd->measType = FXL_4G_OWN_CELL_MEASUREMENT; // Currently supporting only serving cell measurement

    if (blackUserInfo != NULL)
    {
        if (cmd->measType == FXL_4G_OWN_CELL_MEASUREMENT)
        {
            if (checkDefaultconfigOfList() == BLACKLIST)
            {
                if (isTimerRunning(&blackUserInfo->blTimer) == FALSE)
                {
                    timerStart(&blackUserInfo->blTimer,
                               TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT,
                               TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT,
                               &handle4gScSibPageRetransmitTimeoutRrcThrd,
                               blackUserInfo);
                }
            }
            blackUserInfo->lteSilentCallStarted = TRUE;
            blackUserInfo->measurementType = cmd->measType;
            rsp->result = FXL_SUCCESS;
            lteSilentCallStarted = TRUE;
        }
        else if (cmd->measType == FXL_4G_NEIGHBOR_CELL_MEASUREMENT)
        {
            if (asn1EncodedRrcNeighMeasCntrlReqLen != 0)
            {
                if (checkDefaultconfigOfList() == BLACKLIST)
                {
                    if (isTimerRunning(&blackUserInfo->blTimer) == FALSE)
                    {
                        timerStart(&blackUserInfo->blTimer,
                                   TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT,
                                   TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT,
                                   &handle4gScSibPageRetransmitTimeoutRrcThrd,
                                   blackUserInfo);
                    }
                }
                blackUserInfo->lteSilentCallStarted = TRUE;
                blackUserInfo->measurementType = cmd->measType;
                rsp->result = FXL_SUCCESS;
                lteSilentCallStarted = TRUE;
            }
            else
            {
                rsp->result = FXL_FAILURE;
                logPrint(LOG_ERR, "Neighbor cell not configured \n");
            }
        }
        else
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Wrong LTE Silent call Measurement configured \n");
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI = %s in lte blacklist list\n", cmd->imsiStr);
    }

    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL4gStartSilentCallRsp);
    rsp->hdr.msgType = FXL_4G_START_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gStartSilentCallRsp));
    return;
}

void lteStopSilentCallCommandHandler(uint8 *inMsgBuf)
{
    fxL4gEndSilentCallCmd *cmd = (fxL4gEndSilentCallCmd *)inMsgBuf;
    fxL4gEndSilentCallRsp *rsp = (fxL4gEndSilentCallRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));
    lteblackListedUserInfo *blackUserInfo = NULL;
    if (lastLteIdCatcherConfigCmd.redirectionType == NO_REDIRECTION)
    {
        blackUserInfo = blacklistLteUserFindUsingIdentity((tOCT_UINT8 *)(cmd->imsiStr), FALSE);
    }
    if (blackUserInfo != NULL)
    {
        rsp->result = FXL_SUCCESS;
    }
    else
    {
        rsp->result = FXL_FAILURE;
        logPrint(LOG_ERR, "Could not find IMSI = %s in blacklist list\n", cmd->imsiStr);
    }
    lteSilentCallStarted = FALSE;
    memcpy(rsp->imsiStr, cmd->imsiStr, SIZE_OF_IDENTITY_STR);
    rsp->hdr.msgLength = sizeof(fxL4gEndSilentCallRsp);
    rsp->hdr.msgType = FXL_4G_END_SILENT_CALL_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gEndSilentCallRsp));
    return;
}

void lteRfModifyCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gIdCatcherRfModifyCmd *cmd = (fxL4gIdCatcherRfModifyCmd *)inMsgBuf;
    fxL4gIdCatcherRfModifyRsp *rsp = (fxL4gIdCatcherRfModifyRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));

    // Range check
    if (cmd->TxAttenuationInDb > 359)
    {
        cmd->TxAttenuationInDb = 359;
    }
    else if (cmd->TxAttenuationInDb < 0)
    {
        cmd->TxAttenuationInDb = 0;
    }
    else
    {
    }

    if (LteCellModifyRf(cmd->TxAttenuationInDb) != 0)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        rsp->result = FXL_SUCCESS;
    }
    rsp->hdr.msgLength = sizeof(fxL4gIdCatcherRfModifyRsp);
    rsp->hdr.msgType = FXL_4G_IDCATCHER_RF_MODIFY_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    logPrint(LOG_DEBUG, "lteRfModifyCmdHandler Tx-Attenuation = %d, Response = %d \n", cmd->TxAttenuationInDb, rsp->result);
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gIdCatcherRfModifyRsp));
    return;
}

#ifdef OBM_PA_BTS8000
void obmRaRfCtrlCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    logPrint(LOG_ERR, "obmRaRfCtrlCmdHandler function for BTS8000\n");
    unsigned int retCode = 0;
    unsigned int umtsTxAttn = 0;
    unsigned int gsmTxAttn = 0;
    int lteTxAttn = 0;
    unsigned int sendFailureResponse = 0;
    unsigned int isBand4 = 0;

    char *txFilterBand4[3] = {"rf", "7", "8"};

    fxL3gBandType umtsBand;

    fxLObmRaRfCtrlCmd *cmd = (fxLObmRaRfCtrlCmd *)inMsgBuf;
    fxLObmRaRfCtrlRsp *rsp = (fxLObmRaRfCtrlRsp *)msgBuf;

    rsp->result = FXL_FAILURE;

    if (cmd->raVal == FXL_OBM_RA_OFF)
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn off the PA \n");

        /* Fill the Details */
        char *rfCtrl[2] = {"ra", "1"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, rfCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned off \n");
        }
        char *txFilter[3] = {"rf", "0", "1"};

        optreset = 1;

        retCode = g_Commands[32]->pfctCallBack(3, txFilter);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n Filters is successfully reset \n");
        }

        if ((FXL_RAT_2G == cmd->hdr.rat) && (FXL_L1_GSM_NATIVE_IMAGE == currentDspImage))
        {
            gsmTxAttn = 0;
            if (0 != GsmTrxModifyRf(gsmTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in GSM failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_3G == cmd->hdr.rat) && (FXL_L1_UMTS_NATIVE_IMAGE == currentDspImage))
        {
            umtsTxAttn = 0;
            gUmtsConfig.txAttn = umtsTxAttn;
            gUmtsConfig.cpichTxPwr = 3;

            fillCellReconfigReq();
            if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 & CPICH to 3 in UMTS failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_4G == cmd->hdr.rat) && (FXL_L1_LTE_NATIVE_IMAGE == currentDspImage))
        {
            lteTxAttn = 0;
            if (0 != LteCellModifyRf(lteTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in LTE failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else
        {
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn on the PA \n");
        // Filters settings
        char *txFilter[3] = {"rf", "1", "1"};
        if (cmd->hdr.rat == FXL_RAT_2G)
        {
            switch (trx_g->bts.band)
            {
            case FXL_BAND_GSM_850:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 850MHz \n");
                txFilter[1] = "3";
                txFilter[2] = "6";
                gsmTxAttn = 66;
            }
            break;

            case FXL_BAND_GSM_900:
            case FXL_BAND_E_GSM:
            case FXL_BAND_R_GSM:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 900MHz \n");
                txFilter[1] = "4";
                txFilter[2] = "7";
                gsmTxAttn = 64;
            }
            break;

            case FXL_BAND_DCS_1800:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1800MHz \n");
                txFilter[1] = "5";
                txFilter[2] = "8";
                gsmTxAttn = 46;
            }
            break;

            case FXL_BAND_PCS_1900:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1900MHz \n");
                txFilter[1] = "6";
                txFilter[2] = "9";
                gsmTxAttn = 60;
            }
            break;
            default:
            {
                logPrint(LOG_DEBUG, " GSM: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (GsmTrxModifyRf(gsmTxAttn) == cOCTVC1_RC_OK)
            {
                rsp->result = FXL_SUCCESS;
            }
        }
        else if (cmd->hdr.rat == FXL_RAT_3G)
        {
            umtsBand = CalculateBandUsingUarfcn(gUmtsConfig.dlUarfcn);

            switch (umtsBand)
            {
            case FXL_UMTS_BAND_1:
            case FXL_UMTS_BAND_10:
            {
                txFilter[1] = "7";
                txFilter[2] = "10";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 2100MHz \n");
                umtsTxAttn = 50;
            }
            break;

            case FXL_UMTS_BAND_2:
            case FXL_UMTS_ADDITIONAL_BAND_2:
            {
                txFilter[1] = "6";
                txFilter[2] = "9";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1900MHz \n");
                umtsTxAttn = 60;
            }
            break;

            case FXL_UMTS_BAND_3:
            case FXL_UMTS_BAND_9:
            {
                txFilter[1] = "5";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1800MHz \n");
                umtsTxAttn = 62;
            }
            break;

            case FXL_UMTS_BAND_4:
            case FXL_UMTS_ADDITIONAL_BAND_4:
            {
                txFilter[1] = "7";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band4  \n");
                umtsTxAttn = 50;
            }
            break;

            case FXL_UMTS_BAND_5:
            case FXL_UMTS_ADDITIONAL_BAND_5:
            {
                txFilter[1] = "3";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 850MHz \n");
                umtsTxAttn = 80;
            }
            break;

            case FXL_UMTS_BAND_8:
            {
                txFilter[1] = "4";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 900MHz \n");
                umtsTxAttn = 75;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " UMTS: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (gClCntxt.cellState == CL_CELL_ACTIVE)
            {
                /* Update txAttn & CPICH Tx Pwr */
                gUmtsConfig.txAttn = umtsTxAttn;
                gUmtsConfig.cpichTxPwr = 23;

                fillCellReconfigReq();
                if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
                {
                    logPrint(LOG_DEBUG, "Sending Cell Reconfig to L1 failed....\n");
                    sendFailureResponse = 1;
                }
            }
            else
            {
                sendFailureResponse = 1;
            }

            if (1 == sendFailureResponse)
            {
                logPrint(LOG_DEBUG, " UMTS: Unable to set the default Tx attenuation \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
        }
        else
        {
            switch (idCatcherLteBand)
            {
            case FXL_BAND_LTE_1:
            {
                txFilter[1] = "7";
                txFilter[2] = "10";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2100MHz \n");
                lteTxAttn = 48;
            }
            break;

            case FXL_BAND_LTE_2:
            {
                txFilter[1] = "6";
                txFilter[2] = "9";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1900MHz \n");
                lteTxAttn = 60;
            }
            break;

            case FXL_BAND_LTE_3:
            {
                txFilter[1] = "5";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1800MHz \n");
                lteTxAttn = 48; // 64;
            }
            break;

            case FXL_BAND_LTE_4:
            {
                txFilter[1] = "7";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band4  \n");
                lteTxAttn = 44;
            }
            break;
            case FXL_BAND_LTE_19:
            case FXL_BAND_LTE_5:
            {
                txFilter[1] = "3";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 850MHz \n");
                lteTxAttn = 80;
            }
            break;

            case FXL_BAND_LTE_7:
            {
                txFilter[1] = "8";
                txFilter[2] = "11";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2600MHz \n");
                lteTxAttn = 40;
            }
            break;

            case FXL_BAND_LTE_8:
            {
                txFilter[1] = "4";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 900MHz \n");
                lteTxAttn = 76;
            }
            break;

            case FXL_BAND_LTE_17:
            {
                txFilter[1] = "2";
                txFilter[2] = "5";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 700MHz \n");
                lteTxAttn = 88;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " LTE: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }

            if (LteCellModifyRf(lteTxAttn) != 0)
            {
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            // sleep(1);
            usleep(1000);
        }

        /* Fill the Details */
        char *raCtrl[2] = {"ra", "3"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, raCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned on \n");

            // sleep(5);
            usleep(5000);
            optreset = 1;

            retCode = g_Commands[32]->pfctCallBack(3, txFilter);
            if (0 == retCode)
            {
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "\n Filter value applied is %s, %s\n", txFilter[1], txFilter[2]);
            }
        }
    }

    if (0 == retCode)
    {
        rsp->result = FXL_SUCCESS;
        logPrint(LOG_DEBUG, "\n Filters settings successfully applied \n");
    }
    rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
    rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
    return;
}
#endif

#ifdef OBM_PA_BTS8500_WW
void obmRaRfWWCtrlCmdHandler(tOCT_UINT8 *inMsgBuf)
{

    logPrint(LOG_ERR, "obmRaRfWWCtrlCmdHandler function for BTS8500\n");
    unsigned int retCode = 0;
    unsigned int umtsTxAttn = 0;
    unsigned int gsmTxAttn = 0;
    int lteTxAttn = 0;
    unsigned int sendFailureResponse = 0;
    unsigned int isBand4 = 0;

    char *txFilterBand4[3] = {"rf", "7", "8"};

    fxL3gBandType umtsBand;

    fxLObmRaRfCtrlCmd *cmd = (fxLObmRaRfCtrlCmd *)inMsgBuf;
    fxLObmRaRfCtrlRsp *rsp = (fxLObmRaRfCtrlRsp *)msgBuf;

    rsp->result = FXL_FAILURE;

    if (cmd->raVal == FXL_OBM_RA_OFF)
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn off the PA \n");

        /* Fill the Details */
        char *rfCtrl[2] = {"ra", "1"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, rfCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned off \n");
        }
        char *txFilter[3] = {"rf", "1", "1"};
        optreset = 1;

        retCode = g_Commands[32]->pfctCallBack(3, txFilter);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n Filters is successfully reset \n");
        }

        if ((FXL_RAT_2G == cmd->hdr.rat) && (FXL_L1_GSM_NATIVE_IMAGE == currentDspImage))
        {
            gsmTxAttn = 0;
            if (0 != GsmTrxModifyRf(gsmTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in GSM failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_3G == cmd->hdr.rat) && (FXL_L1_UMTS_NATIVE_IMAGE == currentDspImage))
        {
            umtsTxAttn = 0;
            gUmtsConfig.txAttn = umtsTxAttn;
            gUmtsConfig.cpichTxPwr = 3;

            fillCellReconfigReq();
            if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 & CPICH to 3 in UMTS failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_4G == cmd->hdr.rat) && (FXL_L1_LTE_NATIVE_IMAGE == currentDspImage))
        {
            lteTxAttn = 0;
            if (0 != LteCellModifyRf(lteTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in LTE failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else
        {
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn on the PA \n");
        // Filters settings
        char *txFilter[3] = {"rf", "1", "1"};
        if (cmd->hdr.rat == FXL_RAT_2G)
        {
            switch (trx_g->bts.band)
            {
            case FXL_BAND_GSM_850:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 850MHz \n");
                txFilter[1] = "7";
                txFilter[2] = "4";
                gsmTxAttn = 100;
            }
            break;

            case FXL_BAND_GSM_900:
            case FXL_BAND_E_GSM:
            case FXL_BAND_R_GSM:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 900MHz \n");
                txFilter[1] = "8";
                txFilter[2] = "6";
                gsmTxAttn = 100;
            }
            break;

            case FXL_BAND_DCS_1800:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1800MHz \n");
                txFilter[1] = "9";
                txFilter[2] = "7";
                gsmTxAttn = 112;
            }
            break;

            case FXL_BAND_PCS_1900:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1900MHz \n");
                txFilter[1] = "11";
                txFilter[2] = "8";
                gsmTxAttn = 108;
            }
            break;
            default:
            {
                logPrint(LOG_DEBUG, " GSM: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (GsmTrxModifyRf(gsmTxAttn) == cOCTVC1_RC_OK)
            {
                rsp->result = FXL_SUCCESS;
            }
        }
        else if (cmd->hdr.rat == FXL_RAT_3G)
        {
            umtsBand = CalculateBandUsingUarfcn(gUmtsConfig.dlUarfcn);

            switch (umtsBand)
            {
            case FXL_UMTS_BAND_1:
            {
                txFilter[1] = "12";
                txFilter[2] = "10";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 2100MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_2:
            case FXL_UMTS_ADDITIONAL_BAND_2:
            {
                txFilter[1] = "11";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1900MHz \n");
                umtsTxAttn = 96;
            }
            break;

            case FXL_UMTS_BAND_3:
            case FXL_UMTS_BAND_9:
            {
                txFilter[1] = "9";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1800MHz \n");
                umtsTxAttn = 100;
            }
            break;

            case FXL_UMTS_BAND_4:
            case FXL_UMTS_ADDITIONAL_BAND_4:
            {
                txFilter[1] = "12";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band4  \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_5:
            case FXL_UMTS_ADDITIONAL_BAND_5:
            {
                txFilter[1] = "7";
                txFilter[2] = "4";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 850MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_8:
            {
                txFilter[1] = "8";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 900MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_10:
            {
                txFilter[1] = "12";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 2100MHz \n");
                umtsTxAttn = 88;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " UMTS: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (gClCntxt.cellState == CL_CELL_ACTIVE)
            {
                /* Update txAttn & CPICH Tx Pwr */
                gUmtsConfig.txAttn = umtsTxAttn;
                gUmtsConfig.cpichTxPwr = 23;

                fillCellReconfigReq();
                if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
                {
                    logPrint(LOG_DEBUG, "Sending Cell Reconfig to L1 failed....\n");
                    sendFailureResponse = 1;
                }
            }
            else
            {
                sendFailureResponse = 1;
            }

            if (1 == sendFailureResponse)
            {
                logPrint(LOG_DEBUG, " UMTS: Unable to set the default Tx attenuation \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
        }
        else
        {
            switch (idCatcherLteBand)
            {
            case FXL_BAND_LTE_1:
            {
                txFilter[1] = "12";
                txFilter[2] = "10";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2100MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_2:
            {
                txFilter[1] = "11";
                txFilter[2] = "8";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1900MHz \n");
                lteTxAttn = 80;
            }
            break;

            case FXL_BAND_LTE_3:
            {
                txFilter[1] = "9";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1800MHz \n");
                lteTxAttn = 84;
            }
            break;

            case FXL_BAND_LTE_4:
            {
                txFilter[1] = "12";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band4  \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_5:
            {
                txFilter[1] = "7";
                txFilter[2] = "4";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 850MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_7:
            {
                txFilter[1] = "15";
                txFilter[2] = "12";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2600MHz \n");
                lteTxAttn = 48;
            }
            break;

            case FXL_BAND_LTE_8:
            {
                txFilter[1] = "8";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 900MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_17:
            {
                txFilter[1] = "4";
                txFilter[2] = "2";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 700MHz \n");
                lteTxAttn = 84;
            }
            break;

            case FXL_BAND_LTE_19:
            {
                txFilter[1] = "7";
                txFilter[2] = "4";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 850MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_20:
            {
                txFilter[1] = "6";
                txFilter[2] = "5";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 800MHz \n");
                lteTxAttn = 80;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " LTE: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }

            if (LteCellModifyRf(lteTxAttn) != 0)
            {
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            // sleep(1);
            usleep(1000);
        }

        /* Fill the Details */
        char *raCtrl[2] = {"ra", "3"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, raCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned on \n");

            // sleep(5);
            usleep(5000);
            optreset = 1;

            retCode = g_Commands[32]->pfctCallBack(3, txFilter);
            if (0 == retCode)
            {
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "\n Filter value applied is %s, %s\n", txFilter[1], txFilter[2]);
            }
        }
    }

    if (0 == retCode)
    {
        rsp->result = FXL_SUCCESS;
        logPrint(LOG_DEBUG, "\n Filters settings successfully applied \n");
    }
    rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
    rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
    return;
}

#endif

#ifdef OBM_PA_BTS8500_NW
void obmRaRfNWCtrlCmdHandler(tOCT_UINT8 *inMsgBuf)
{

    logPrint(LOG_ERR, "obmRaRfNWCtrlCmdHandler function for BTS8500\n");
    unsigned int retCode = 0;
    unsigned int umtsTxAttn = 0;
    unsigned int gsmTxAttn = 0;
    int lteTxAttn = 0;
    unsigned int sendFailureResponse = 0;
    unsigned int isBand4 = 0;

    char *txFilterBand4[3] = {"rf", "7", "8"};

    fxL3gBandType umtsBand;

    fxLObmRaRfCtrlCmd *cmd = (fxLObmRaRfCtrlCmd *)inMsgBuf;
    fxLObmRaRfCtrlRsp *rsp = (fxLObmRaRfCtrlRsp *)msgBuf;

    rsp->result = FXL_FAILURE;

    if (cmd->raVal == FXL_OBM_RA_OFF)
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn off the PA \n");

        /* Fill the Details */
        char *rfCtrl[2] = {"ra", "1"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, rfCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned off \n");
        }
        char *txFilter[3] = {"rf", "1", "1"};
        optreset = 1;

        retCode = g_Commands[32]->pfctCallBack(3, txFilter);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n Filters is successfully reset \n");
        }

        if ((FXL_RAT_2G == cmd->hdr.rat) && (FXL_L1_GSM_NATIVE_IMAGE == currentDspImage))
        {
            gsmTxAttn = 0;
            if (0 != GsmTrxModifyRf(gsmTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in GSM failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_3G == cmd->hdr.rat) && (FXL_L1_UMTS_NATIVE_IMAGE == currentDspImage))
        {
            umtsTxAttn = 0;
            gUmtsConfig.txAttn = umtsTxAttn;
            gUmtsConfig.cpichTxPwr = 3;

            fillCellReconfigReq();
            if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 & CPICH to 3 in UMTS failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else if ((FXL_RAT_4G == cmd->hdr.rat) && (FXL_L1_LTE_NATIVE_IMAGE == currentDspImage))
        {
            lteTxAttn = 0;
            if (0 != LteCellModifyRf(lteTxAttn))
            {
                logPrint(LOG_DEBUG, "Setting Tx Attenuation to 0 in LTE failed\n");
                rsp->result = FXL_FAILURE;
            }
        }
        else
        {
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "\n Recieved API command to turn on the PA \n");
        // Filters settings
        char *txFilter[3] = {"rf", "1", "1"};
        if (cmd->hdr.rat == FXL_RAT_2G)
        {
            switch (trx_g->bts.band)
            {
            case FXL_BAND_GSM_850:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 850MHz \n");
                txFilter[1] = "7";
                txFilter[2] = "5";
                // gsmTxAttn = 100;//not working .. celliber data
                gsmTxAttn = 112;
            }
            break;

            case FXL_BAND_GSM_900:
            case FXL_BAND_E_GSM:
            case FXL_BAND_R_GSM:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 900MHz \n");
                // txFilter[1] =  "8";  on NW baord type 900 filter not supported
                // txFilter[2] =  "6";

                txFilter[1] = "2";
                txFilter[2] = "1";
                gsmTxAttn = 100;
            }
            break;

            case FXL_BAND_DCS_1800:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1800MHz \n");
                txFilter[1] = "8";
                txFilter[2] = "6";
                gsmTxAttn = 112;
            }
            break;

            case FXL_BAND_PCS_1900:
            {
                logPrint(LOG_DEBUG, "\n GSM: Filters configured for band 1900MHz \n");
                txFilter[1] = "10";
                txFilter[2] = "7";
                gsmTxAttn = 108;
            }
            break;
            default:
            {
                logPrint(LOG_DEBUG, " GSM: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (GsmTrxModifyRf(gsmTxAttn) == cOCTVC1_RC_OK)
            {
                rsp->result = FXL_SUCCESS;
            }
        }
        else if (cmd->hdr.rat == FXL_RAT_3G)
        {
            umtsBand = CalculateBandUsingUarfcn(gUmtsConfig.dlUarfcn);

            switch (umtsBand)
            {
            case FXL_UMTS_BAND_1:
            {
                txFilter[1] = "11";
                txFilter[2] = "9";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 2100MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_10:
            {
                txFilter[1] = "11";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 2100MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_2:
            case FXL_UMTS_ADDITIONAL_BAND_2:
            {
                txFilter[1] = "10";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1900MHz \n");
                umtsTxAttn = 96;
            }
            break;

            case FXL_UMTS_BAND_3:
            case FXL_UMTS_BAND_9:
            {
                txFilter[1] = "8";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 1800MHz \n");
                umtsTxAttn = 100;
            }
            break;

            case FXL_UMTS_BAND_4:
            case FXL_UMTS_ADDITIONAL_BAND_4:
            {
                txFilter[1] = "11";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band4  \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_5:
            case FXL_UMTS_ADDITIONAL_BAND_5:
            {
                txFilter[1] = "7";
                txFilter[2] = "5";
                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 850MHz \n");
                umtsTxAttn = 88;
            }
            break;

            case FXL_UMTS_BAND_8:
            {
                // txFilter[1] =  "8";  NW baord type not supported
                // txFilter[2] =  "6";

                txFilter[1] = "2";
                txFilter[2] = "1";

                logPrint(LOG_DEBUG, "\n UMTS: Filters configured for band 900MHz \n");
                umtsTxAttn = 88;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " UMTS: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }
            if (gClCntxt.cellState == CL_CELL_ACTIVE)
            {
                /* Update txAttn & CPICH Tx Pwr */
                gUmtsConfig.txAttn = umtsTxAttn;
                gUmtsConfig.cpichTxPwr = 23;
                logPrint(LOG_DEBUG, "gUmtsConfig.txAttn ,gUmtsConfig.cpichTxPwr for TX filter in CL_CELL_ACTIVE state %d\t%d", gUmtsConfig.txAttn, gUmtsConfig.cpichTxPwr);

                fillCellReconfigReq();
                if (SUCCESS_E != oct_cell_reconfig_req(&gCellReconfigReq))
                {
                    logPrint(LOG_DEBUG, "Sending Cell Reconfig to L1 failed....\n");
                    sendFailureResponse = 1;
                }
            }
            else
            {
                sendFailureResponse = 1;
            }

            if (1 == sendFailureResponse)
            {
                logPrint(LOG_DEBUG, " UMTS: Unable to set the default Tx attenuation \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
        }
        else
        {
            switch (idCatcherLteBand)
            {
            case FXL_BAND_LTE_1:
            {
                txFilter[1] = "11";
                txFilter[2] = "9";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2100MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_2:
            {
                txFilter[1] = "10";
                txFilter[2] = "7";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1900MHz \n");
                lteTxAttn = 80;
            }
            break;

            case FXL_BAND_LTE_3:
            {
                txFilter[1] = "8";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 1800MHz \n");
                lteTxAttn = 84;
            }
            break;

            case FXL_BAND_LTE_4:
            {
                txFilter[1] = "11";
                txFilter[2] = "6";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band4  \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_5:
            {
                txFilter[1] = "7";
                txFilter[2] = "5";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 850MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_7:
            {
                txFilter[1] = "14";
                txFilter[2] = "11";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 2600MHz \n");
                lteTxAttn = 48;
            }
            break;

            case FXL_BAND_LTE_8:
            {
                // txFilter[1] =  "8";  // NW band NW supported
                // txFilter[2] =  "6";

                txFilter[1] = "2";
                txFilter[2] = "1";

                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 900MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_17:
            {
                txFilter[1] = "4";
                txFilter[2] = "2";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 700MHz \n");
                lteTxAttn = 84;
            }
            break;

            case FXL_BAND_LTE_19:
            {
                txFilter[1] = "7";
                txFilter[2] = "4";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 850MHz \n");
                lteTxAttn = 72;
            }
            break;

            case FXL_BAND_LTE_20:
            {
                txFilter[1] = "2"; // NW board type .. setting to lower frequency
                txFilter[2] = "1";
                logPrint(LOG_DEBUG, "\n LTE: Filters configured for band 800MHz \n");
                lteTxAttn = 80;
            }
            break;

            default:
            {
                logPrint(LOG_DEBUG, " LTE: Invalid band for filters settings \n");
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            }

            if (LteCellModifyRf(lteTxAttn) != 0)
            {
                rsp->result = FXL_FAILURE;
                rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
                rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
                rsp->hdr.rat = cmd->hdr.rat;

                writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
                return;
            }
            // sleep(1);
            usleep(1000);
        }

        /* Fill the Details */
        char *raCtrl[2] = {"ra", "3"};

        optreset = 1;

        retCode = g_Commands[31]->pfctCallBack(2, raCtrl);

        if (0 == retCode)
        {
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "\n PA is successfully turned on \n");

            // sleep(5);
            usleep(5000);
            optreset = 1;

            retCode = g_Commands[32]->pfctCallBack(3, txFilter);
            if (0 == retCode)
            {
                rsp->result = FXL_SUCCESS;
                logPrint(LOG_DEBUG, "\n Filter value applied is %s, %s\n", txFilter[1], txFilter[2]);
            }
        }
    }

    if (0 == retCode)
    {
        rsp->result = FXL_SUCCESS;
        logPrint(LOG_DEBUG, "\n Filters settings successfully applied \n");
    }
    rsp->hdr.msgLength = sizeof(fxLObmRaRfCtrlRsp);
    rsp->hdr.msgType = FXL_OBM_RA_RF_CTRL_RSP;
    rsp->hdr.rat = cmd->hdr.rat;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLObmRaRfCtrlRsp));
    return;
}

#endif

uint32 reInitialiseLteScanData(fxL4gListenModeConfigureBandsCmd *cmd)
{
    uint32 ret = FALSE;
    for (uint8 i = 0; i < cmd->noOfBandsToScan; i++)
    {
        if (cmd->band[i] == FXL_BAND_LTE_1)
        {
            if ((ltebandMap & SET_LTE_BAND_1) == SET_LTE_BAND_1)
            {
                ret = ret | SET_LTE_BAND_1;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_1;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_2)
        {
            if ((ltebandMap & SET_LTE_BAND_2) == SET_LTE_BAND_2)
            {
                ret = ret | SET_LTE_BAND_2;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_2;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_3)
        {
            if ((ltebandMap & SET_LTE_BAND_3) == SET_LTE_BAND_3)
            {
                ret = ret | SET_LTE_BAND_3;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_3;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_4)
        {
            if ((ltebandMap & SET_LTE_BAND_4) == SET_LTE_BAND_4)
            {
                ret = ret | SET_LTE_BAND_4;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_4;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_5)
        {
            if ((ltebandMap & SET_LTE_BAND_5) == SET_LTE_BAND_5)
            {
                ret = ret | SET_LTE_BAND_5;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_5;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_6)
        {
            if ((ltebandMap & SET_LTE_BAND_6) == SET_LTE_BAND_6)
            {
                ret = ret | SET_LTE_BAND_6;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_6;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_7)
        {
            if ((ltebandMap & SET_LTE_BAND_7) == SET_LTE_BAND_7)
            {
                ret = ret | SET_LTE_BAND_7;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_7;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_8)
        {
            if ((ltebandMap & SET_LTE_BAND_8) == SET_LTE_BAND_8)
            {
                ret = ret | SET_LTE_BAND_8;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_8;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_9)
        {
            if ((ltebandMap & SET_LTE_BAND_9) == SET_LTE_BAND_9)
            {
                ret = ret | SET_LTE_BAND_9;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_9;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_10)
        {
            if ((ltebandMap & SET_LTE_BAND_10) == SET_LTE_BAND_10)
            {
                ret = ret | SET_LTE_BAND_10;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_10;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_11)
        {
            if ((ltebandMap & SET_LTE_BAND_11) == SET_LTE_BAND_11)
            {
                ret = ret | SET_LTE_BAND_11;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_11;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_12)
        {
            if ((ltebandMap & SET_LTE_BAND_12) == SET_LTE_BAND_12)
            {
                ret = ret | SET_LTE_BAND_12;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_12;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_13)
        {
            if ((ltebandMap & SET_LTE_BAND_13) == SET_LTE_BAND_13)
            {
                ret = ret | SET_LTE_BAND_13;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_13;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_14)
        {
            if ((ltebandMap & SET_LTE_BAND_14) == SET_LTE_BAND_14)
            {
                ret = ret | SET_LTE_BAND_14;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_14;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_15)
        {
            if ((ltebandMap & SET_LTE_BAND_15) == SET_LTE_BAND_15)
            {
                ret = ret | SET_LTE_BAND_15;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_15;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_16)
        {
            if ((ltebandMap & SET_LTE_BAND_16) == SET_LTE_BAND_16)
            {
                ret = ret | SET_LTE_BAND_16;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_16;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_17)
        {
            if ((ltebandMap & SET_LTE_BAND_17) == SET_LTE_BAND_17)
            {
                ret = ret | SET_LTE_BAND_17;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_17;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_18)
        {
            if ((ltebandMap & SET_LTE_BAND_18) == SET_LTE_BAND_18)
            {
                ret = ret | SET_LTE_BAND_18;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_18;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_19)
        {
            if ((ltebandMap & SET_LTE_BAND_19) == SET_LTE_BAND_19)
            {
                ret = ret | SET_LTE_BAND_19;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_19;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_20)
        {
            if ((ltebandMap & SET_LTE_BAND_20) == SET_LTE_BAND_20)
            {
                ret = ret | SET_LTE_BAND_20;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_20;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_21)
        {
            if ((ltebandMap & SET_LTE_BAND_21) == SET_LTE_BAND_21)
            {
                ret = ret | SET_LTE_BAND_21;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_21;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_22)
        {
            if ((ltebandMap & SET_LTE_BAND_22) == SET_LTE_BAND_22)
            {
                ret = ret | SET_LTE_BAND_22;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_22;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_23)
        {
            if ((ltebandMap & SET_LTE_BAND_23) == SET_LTE_BAND_23)
            {
                ret = ret | SET_LTE_BAND_23;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_23;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_24)
        {
            if ((ltebandMap & SET_LTE_BAND_24) == SET_LTE_BAND_24)
            {
                ret = ret | SET_LTE_BAND_24;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_24;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_25)
        {
            if ((ltebandMap & SET_LTE_BAND_25) == SET_LTE_BAND_25)
            {
                ret = ret | SET_LTE_BAND_25;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_25;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_26)
        {
            if ((ltebandMap & SET_LTE_BAND_26) == SET_LTE_BAND_26)
            {
                ret = ret | SET_LTE_BAND_26;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_26;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_27)
        {
            if ((ltebandMap & SET_LTE_BAND_27) == SET_LTE_BAND_27)
            {
                ret = ret | SET_LTE_BAND_27;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_27;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_28)
        {
            if ((ltebandMap & SET_LTE_BAND_28) == SET_LTE_BAND_28)
            {
                ret = ret | SET_LTE_BAND_28;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_28;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_29)
        {
            if ((ltebandMap & SET_LTE_BAND_29) == SET_LTE_BAND_29)
            {
                ret = ret | SET_LTE_BAND_29;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_29;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_30)
        {
            if ((ltebandMap & SET_LTE_BAND_30) == SET_LTE_BAND_30)
            {
                ret = ret | SET_LTE_BAND_30;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_30;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_31)
        {
            if ((ltebandMap & SET_LTE_BAND_31) == SET_LTE_BAND_31)
            {
                ret = ret | SET_LTE_BAND_31;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_31;
            }
        }
        else if (cmd->band[i] == FXL_BAND_LTE_32)
        {
            if ((ltebandMap & SET_LTE_BAND_32) == SET_LTE_BAND_32)
            {
                ret = ret | SET_LTE_BAND_32;
            }
            else
            {
                ltebandMap = ltebandMap | SET_LTE_BAND_32;
            }
        }
    }

    if (ret != FALSE)
        ltebandMap = ret; // Reinitialise again
    return ret;
}

#ifdef CELL_ANTENNA_CHANGE
void configureCellAntennaPA(char dspType, int band, char mode)
{
    char inputString[64];

    logPrint(LOG_ERR, "Configure CellAntennaPA Mode = %c , Band = %d , DspType = %c \n", mode, band, dspType);

    if ('t' == mode) // Setting for scanner case
    {
        sprintf(inputString, "/home/wgs/scripts/setTREX.bin %c %d %c", mode, band, dspType);

        if (system(inputString) == -1)
        {
            logPrint(LOG_ERR, "Loading CellAntenna PA Configuration for Scanning failed\n");
        }
        else
        {
            logPrint(LOG_ERR, "Loading CellAntenna PA Configuration for Scanning Success\n");
        }
    }
    else if ('i' == mode)
    {
        if ((lteIdCatcherRunning) && (lastLteIdCatcherConfigCmd.bandIndicator == 28))
        {
            if (lastLteIdCatcherConfigCmd.earfcn <= 9410)
            {
                sprintf(inputString, "/home/wgs/scripts/setTREX.bin %c %s %c", mode, "28a", dspType);
            }
            else
            {
                sprintf(inputString, "/home/wgs/scripts/setTREX.bin %c %s %c", mode, "28b", dspType);
            }
        }
        else
        {
            sprintf(inputString, "/home/wgs/scripts/setTREX.bin %c %d %c", mode, band, dspType);
        }

        if (system(inputString) == -1)
        {
            logPrint(LOG_ERR, "Loading CellAntenna PA Configuration for ID Catcher failed\n");
        }
        else
        {
            logPrint(LOG_ERR, "Loading CellAntenna PA Configuration for ID Catcher Success\n");
        }
    }
    else
    {
        logPrint(LOG_ERR, "Invalid Mode for CellAntenna PA Configuration\n");
    }

    return;
}

#endif // Cell_antenna_change

#ifdef FXL_3G_TX_JAMMER
/*
 * Start 3G Tx Jammer
 */
void umtsStartTxJammer(unsigned char *inMsgBuf)
{
    umtsJammerParams *pJammerParams = NULL;
    fxL3gTxJammerStartCmd *cmd = (fxL3gTxJammerStartCmd *)inMsgBuf;
    fxL3gTxJammerStartRsp *rsp = (fxL3gTxJammerStartRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));

    rsp->result = FXL_SUCCESS;

    pJammerParams = (umtsJammerParams *)malloc(sizeof(umtsJammerParams));
    pJammerParams->uarfcn = cmd->uarfcn;
    pJammerParams->band = cmd->band;

    if (pthread_create(&umtsTxJammerThreadId, NULL, umtsTxJammer, (void *)pJammerParams))
    {
        logPrint(LOG_ERR, "UMTS Tx Jammer Thread creation failed");
        rsp->result = FXL_FAILURE;
    }

    rsp->hdr.msgLength = sizeof(fxL3gTxJammerStartRsp);
    rsp->hdr.rat = FXL_RAT_3G;
    rsp->hdr.msgType = FXL_3G_TX_JAMMER_START_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gTxJammerStartRsp));
    return;
}

/*
 * Stop 3G Tx Jammer
 */
void umtsStopTxJammer(unsigned char *inMsgBuf)
{
    fxL3gTxJammerStopCmd *cmd = (fxL3gTxJammerStopCmd *)inMsgBuf;
    fxL3gTxJammerStopRsp *rsp = (fxL3gTxJammerStopRsp *)msgBuf;
    rsp->result = FXL_SUCCESS;

    if (1 == bootL1InProgress)
    {
        rsp->result = FXL_FAILURE;
        rsp->hdr.msgLength = sizeof(fxL3gTxJammerStopRsp);
        rsp->hdr.rat = FXL_RAT_3G;
        rsp->hdr.msgType = FXL_3G_TX_JAMMER_STOP_RSP;

        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gTxJammerStopRsp));
        return;
    }
    else
    {
        exitUmtsTxJammer = 1;

        while (1)
        {
            if (pthread_tryjoin_np(umtsTxJammerThreadId, NULL))
            {
                logPrint(LOG_ERR, "UMTS Tx Jammer Thread Join failed");
            }
            else
                break;
        }
        memset(&umtsTxJammerThreadId, 0, sizeof(umtsTxJammerThreadId));

        rsp->hdr.msgLength = sizeof(fxL3gTxJammerStopRsp);
        rsp->hdr.rat = FXL_RAT_3G;
        rsp->hdr.msgType = FXL_3G_TX_JAMMER_STOP_RSP;

        writeToExternalSocketInterface(msgBuf, sizeof(fxL3gTxJammerStopRsp));

        L1API_Close(NULL);

        if (isItPrimaryDsp() == TRUE)
        {
            char *argValue[2] = {"dr", "-p"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }
        else
        {
            char *argValue[2] = {"dr", "-s"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }

        modemSetupRequired = 1;

        return;
    }
}

void buildAndSend3gTxJammerStatusInd(fxL3gTxJammerStatus status)
{
    int i;
    fxL3gTxJammerStatusInd *ind = (fxL3gTxJammerStatusInd *)msgBuf;

    ind->hdr.msgLength = sizeof(fxL3gTxJammerStatusInd);
    ind->hdr.msgType = FXL_3G_TX_JAMMER_STATUS_IND;
    ind->hdr.rat = FXL_RAT_3G;
    ind->status = status;
    ind->numOfCell = jammer3gPsc.numOfPsc;
    for (i = 0; i < MAX_NUM_OF_PSC_PER_UARFCN; i++)
    {
        ind->cellPsc[i] = jammer3gPsc.psc[i];
    }

    writeToExternalSocketInterface(msgBuf, sizeof(fxL3gTxJammerStatusInd));

    return;
}
#endif // FXL_3G_TX_JAMMER

#ifdef FXL_4G_TX_JAMMER

int lteJamPCI = -1;

/*
 * autobootLteL1CmdHandler
 */
void autobootLteL1CmdHandler()
{
    sleep(5);
    unsigned int retCode = 0;

    /* Fill the Details */
    char *argValue[3] = {"dr", "-p", "LTE_NATIVE.img"};
    optreset = 1;

    retCode = g_Commands[12]->pfctCallBack(3, argValue);
    if (0 == retCode)
    {
        currentDspImage = FXL_L1_LTE_NATIVE_IMAGE;
    }

    sleep(5);
    if (isItPrimaryDsp() == TRUE)
    {
        if (-1 == system("/home/wgs/scripts/setGPSPri.sh"))
        {
            logPrint(LOG_DEBUG, ": GPS setting failed\n");
        }
    }
    else
    {
        if (-1 == system("/home/wgs/scripts/setGPSSec.sh"))
        {
            logPrint(LOG_DEBUG, ": GPS setting failed\n");
        }
    }
    return;
}

/*
 * lteConfigureJammerParamsHandler
 */
void lteConfigureJammerParamsHandler()
{
    fxL4gConfigureIdCatcherParamsCmd cmd;
    uint8 i = 0, j = 0;
    memset(&cmd, 0, sizeof(fxL4gConfigureIdCatcherParamsCmd));
    lteJamPCI = -1; // initialise the LTE Jamm CELL ID

    // Step 1 : Load LTE L1 NATIVE IMAGE
    bootL1InProgress = 1;
    autobootLteL1CmdHandler();
    bootL1InProgress = 0;
    logPrint(LOG_DEBUG, " currentDspImage = %s \n", currentDspImage == 5 ? "FXL_L1_LTE_NATIVE_IMAGE" : "WRONG_IMAGE_SET");

    // Step 2 : Configure Jammer ID Catcher using the Scan Data
    if (searchLteScanDataToFindJammerConfigParams(&cmd) == TRUE)
    {
        logPrint(LOG_DEBUG, "LTE Jammer Config Chosen EARFCN = %d , BandIndicator = %d , PhyCellId = %d\n", cmd.earfcn, cmd.bandIndicator, cmd.phyCellId);
        logPrint(LOG_DEBUG, "Layer3CellId = %d , TAC = %d , Bandwidth = %d \n", cmd.layer3CellId, cmd.tac, lteSelectedBandwidth);
        lteJamPCI = cmd.phyCellId;

        idCatcherLteBand = cmd.bandIndicator - 1; // Matching the enum value
        idCatcherLteEarfcn = cmd.earfcn;
        if (currentDspImage == FXL_L1_LTE_NATIVE_IMAGE) // First time we are getting configuration
        {
            // Step 2-a : Configure RF Parameters
            lteRfConfig rfConfig = {0};
            rfConfig.earfcn = cmd.earfcn;
            rfConfig.txAttnDb = cmd.txAttndB;
            rfConfig.ulRxGainDb = cmd.ulRxGainDb;
            rfConfig.cellBandWidth = (int)lteSelectedBandwidth;
            rfConfig.f_enodebStartOrStop = TRUE;
            rfConfig.islteTDD = (int)lteDuplxMode;
            rfConfig.relativeD = 0;

            if (lteEnodebConfig(&rfConfig) != 0)
            {
                logPrint(LOG_ERR, "LTE RF Band/Frequency configuration Failed\n");
            }
            else
            {
                if (lteOpenRawSocketInterface() != L1IF_NO_ERROR)
                {
                    logPrint(LOG_ERR, "RAW Socket OPEN Failed\n");
                }
                else
                {
                    if (lastLteIdCatcherConfigCmd.hdr.msgLength != 0) // Not the first time
                    {
                        cmd.tac = ++lastLteIdCatcherConfigCmd.tac;
                    }
                    createAndInit4gContext(&cmd);
                    logPrint(LOG_DEBUG, "LTE ID Catcher Configuration Successful ! \n");
                }
            }

            memcpy((uint8 *)&lastLteIdCatcherConfigCmd, (uint8 *)&cmd, sizeof(fxL4gConfigureIdCatcherParamsCmd));
            logPrint(LOG_DEBUG, "Layer3CellId = %d , TAC = %d , redirectionType = %d\n", cmd.layer3CellId, cmd.tac, cmd.redirectionType);

            // Step 2-a :  Start ID catcher if Cell found
            realNwTac = 0;
            if (createThreadsForLteNativeApp() == -1)
            {
                logPrint(LOG_ERR, "LTE Threads are not created \n");
            }
            else
            {
                printf("\n######################################################\n");
                printf("LTE JAMMER is RUNNING ! \n");
                printf("Number of PLMN = %d\n", lastLteIdCatcherConfigCmd.numOfPlmn);
                lteJamThreadsCreated = TRUE;
                for (i = 0; i < lastLteIdCatcherConfigCmd.numOfPlmn; i++)
                {
                    printf("PLMN[%d] MCC Length = %d\n", i, lastLteIdCatcherConfigCmd.plmn[i].mccLength);
                    for (j = 0; j < lastLteIdCatcherConfigCmd.plmn[i].mccLength; j++)
                    {
                        printf("MCC[%d] = %d ", j, lastLteIdCatcherConfigCmd.plmn[i].mcc[j]);
                    }
                    printf("\n");

                    printf("PLMN[%d] MNC Length = %d\n", i, lastLteIdCatcherConfigCmd.plmn[i].mncLength);
                    for (j = 0; j < lastLteIdCatcherConfigCmd.plmn[i].mncLength; j++)
                    {
                        printf("MNC[%d] = %d ", j, lastLteIdCatcherConfigCmd.plmn[i].mnc[j]);
                    }
                    printf("\n");
                }

                printf("Layer3CellId = %d , TAC = %d , PhyCellId = %d\n", lastLteIdCatcherConfigCmd.layer3CellId, lastLteIdCatcherConfigCmd.tac, lastLteIdCatcherConfigCmd.phyCellId);
                printf("\n######################################################\n");
            }
            buildAndSend4gTxJammerStatusInd(FXL_4G_TX_JAMMER_RUNNING);
        }
    }
    else
    {
        logPrint(LOG_DEBUG, "No LTE Scan cells found for Jammer \n");
    }
    return;
}

/*
 * Start 4G Tx Jammer
 */
void lteStartTxJammer(unsigned char *inMsgBuf)
{
    unsigned int *pEarfcn = NULL;
    fxL4gTxJammerStartCmd *cmd = (fxL4gTxJammerStartCmd *)inMsgBuf;
    fxL4gTxJammerStartRsp *rsp = (fxL4gTxJammerStartRsp *)msgBuf;

    rsp->result = FXL_SUCCESS;

    pEarfcn = (unsigned int *)malloc(sizeof(unsigned int));
    *pEarfcn = cmd->earfcn;
    lteJamPCI = -1;

    if (currentDspImage == FXL_L1_GSM_SLS_IMAGE ||
        currentDspImage == FXL_L1_UMTS_SLS_IMAGE ||
        currentDspImage == FXL_L1_LTE_SLS_IMAGE)
    {
        if (pthread_create(&lteTxJammerThreadId, NULL, lteTxJammer, (void *)pEarfcn))
        {
            logPrint(LOG_ERR, "LTE Tx Jammer Thread creation failed");
            rsp->result = FXL_FAILURE;
        }
        else
        {
            logPrint(LOG_DEBUG, "Starting LTE Jammer -Step 1-Scanner....\n");
            rsp->result = FXL_SUCCESS;
        }
    }

    rsp->hdr.msgLength = sizeof(fxL4gTxJammerStartRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_TX_JAMMER_START_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gTxJammerStartRsp));
    return;
}

void lteStopJamIdCatcherHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL4gStopIdCatcherCmd *cmd = (fxL4gStopIdCatcherCmd *)inMsgBuf;
    lteRfConfig rfConfig = {0};
    rfConfig.earfcn = cmd->dspResetNeeded;
    rfConfig.txAttnDb = 0;
    rfConfig.ulRxGainDb = 0;
    rfConfig.cellBandWidth = (int)lteSelectedBandwidth;
    rfConfig.f_enodebStartOrStop = FALSE;
    rfConfig.islteTDD = (int)lteDuplxMode;
    rfConfig.relativeD = 0;
    if (TRUE == lteJamThreadsCreated)
    {
        destroyThreadsForLteNativeApp();
    }

    buildAndSendPhyStopReq();

    if (lteEnodebConfig(&rfConfig) != 0) // Enodeb cell Stop
    {
        logPrint(LOG_ERR, "LTE ENodeB Stop Failed\n");
    }

    lteCloseRawSocketInterface();

    lteSelectedBandwidth = LTE_BW_N50;
    if (cmd->dspResetNeeded == TRUE)
    {
        if (isItPrimaryDsp() == TRUE)
        {
            char *argValue[2] = {"dr", "-p"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }
        else
        {
            char *argValue[2] = {"dr", "-s"};
            optreset = 1;
            g_Commands[12]->pfctCallBack(2, argValue);
        }
    }
    destroy4gContext();
    exitLteApp = FALSE;
    return;
}

/*
 * Stop 4G Tx Jammer
 */
void lteStopTxJammer(unsigned char *inMsgBuf)
{
    fxL4gTxJammerStopCmd *cmd = (fxL4gTxJammerStopCmd *)inMsgBuf;
    fxL4gTxJammerStopRsp *rsp = (fxL4gTxJammerStopRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));

    rsp->result = FXL_SUCCESS;

    if (1 == bootL1InProgress)
    {
        rsp->result = FXL_FAILURE;
    }
    else
    {
        logPrint(LOG_DEBUG, "lteJamCellFound = %d", lteJamCellFound);
        if (lteJamCellFound)
        {
            deleteLteScanData();

            fxL4gStopIdCatcherCmd msgBuff;
            msgBuff.hdr.msgLength = sizeof(fxL4gStopIdCatcherCmd);
            msgBuff.hdr.msgType = FXL_4G_STOP_IDCATCHER_CMD;
            msgBuff.hdr.rat = FXL_RAT_4G;
            msgBuff.dspResetNeeded = TRUE;

            uint8 *msg = (uint8 *)&msgBuff;
            lteStopJamIdCatcherHandler(msg);

            lteJamPCI = -1;
        }

        lteJamThreadsCreated = FALSE;
        lteJamCellFound = FALSE;
        logPrint(LOG_DEBUG, "lteJamCellFound = %d", lteJamCellFound);
        exitLteTxJammer = 1;

        if ((lteTxJammerThreadId != 0) && (pthread_join(lteTxJammerThreadId, NULL)))
        {
            // logPrint(LOG_ERR , "Listen Mode Thread join failed");
            rsp->result = FXL_FAILURE;
        }
        memset(&lteTxJammerThreadId, 0, sizeof(lteTxJammerThreadId));
    }

    rsp->hdr.msgLength = sizeof(fxL4gTxJammerStopRsp);
    rsp->hdr.rat = FXL_RAT_4G;
    rsp->hdr.msgType = FXL_4G_TX_JAMMER_STOP_RSP;
    lteSelectedBandwidth = LTE_BW_N50;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gTxJammerStopRsp));
    return;
}

void buildAndSend4gTxJammerStatusInd(fxL4gTxJammerStatus status)
{
    fxL4gTxJammerStatusInd *ind = (fxL4gTxJammerStatusInd *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));

    ind->hdr.msgLength = sizeof(fxL4gTxJammerStatusInd);
    ind->hdr.msgType = FXL_4G_TX_JAMMER_STATUS_IND;
    ind->hdr.rat = FXL_RAT_4G;
    ind->status = status;
    ind->pci = lteJamPCI;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gTxJammerStatusInd));

    return;
}
#endif // FXL_4G_TX_JAMMER
int stick_this_thread_to_core(int core_id)
{
#if 0
   int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
   if (core_id < 0 || core_id >= num_cores)
      return EINVAL;

   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
   CPU_SET(core_id, &cpuset);

   pthread_t current_thread = pthread_self();
   return pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset);
#endif
    return 1;
}

void checkAndSetOnBinState(void)
{
    logPrint(LOG_DEBUG, "checkAndSetOnBinState CurrentState = %d\n", currentOneBinState);

    if (gpsStarted == 1)
    {
        memset(stopCmdBuf, 0, 128);
        fxLStopGpsCmd *cmd = (fxLStopGpsCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxLStopGpsCmd);
        cmd->hdr.msgType = FXL_STOP_GPS_CMD;
        cmd->hdr.rat = FXL_RAT_2G;
        stopGpsCmdHandler(cmd);
    }
#if defined(OBM_PA_BTS8000) || defined(OBM_PA_BTS8500_WW) || defined(OBM_PA_BTS8500_NW)
    {
        // Send command to switch off internal PA
        memset(stopCmdBuf, 0, 128);
        fxLObmRaRfCtrlCmd *cmd = (fxLObmRaRfCtrlCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxLObmRaRfCtrlCmd);
        cmd->hdr.msgType = FXL_OBM_RA_RF_CTRL_CMD;
        if ((currentOneBinState == ONEBIN_STATE_2G_SCANNING) || (currentOneBinState == ONEBIN_STATE_2G_IDCATCHING) || (currentOneBinState == ONEBIN_STATE_2G_BASS))
        {
            cmd->hdr.rat = FXL_RAT_2G;
        }
        else if ((currentOneBinState == ONEBIN_STATE_3G_SCANNING) || (currentOneBinState == ONEBIN_STATE_3G_IDCATCHING))
        {
            cmd->hdr.rat = FXL_RAT_3G;
        }
        else if ((currentOneBinState == ONEBIN_STATE_4G_SCANNING) || (currentOneBinState == ONEBIN_STATE_4G_IDCATCHING))
        {
            cmd->hdr.rat = FXL_RAT_4G;
        }
        else
        {
            cmd->hdr.rat = FXL_RAT_2G;
        }
#ifdef OBM_PA_BTS8000
        cmd->raVal = FXL_OBM_RA_OFF;
        obmRaRfCtrlCmdHandler(cmd);
#endif
#ifdef OBM_PA_BTS8500_WW
        cmd->raVal = FXL_OBM_RA_OFF;
        obmRaRfWWCtrlCmdHandler(cmd);
#endif

#ifdef OBM_PA_BTS8500_NW
        cmd->raVal = FXL_OBM_RA_OFF;
        obmRaRfNWCtrlCmdHandler(cmd);
#endif
    }

#endif

    switch (currentOneBinState)
    {
    case ONEBIN_STATE_IDLE:
    {
        // Do Nothing
    }
    break;
    case ONEBIN_STATE_2G_SCANNING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL2gListenModeStopScanCmd *cmd = (fxL2gListenModeStopScanCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL2gListenModeStopScanCmd);
        cmd->hdr.msgType = FXL_2G_LISTEN_MODE_STOP_SCAN_CMD;
        cmd->hdr.rat = FXL_RAT_2G;
        cmd->dspResetNeeded = TRUE;
        listenModeStopScanCmdHandler(cmd);
    }
    break;
    case ONEBIN_STATE_3G_SCANNING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL3gListenModeStartStopScanCmd *cmd = (fxL3gListenModeStartStopScanCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL3gListenModeStartStopScanCmd);
        cmd->hdr.msgType = FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_CMD;
        cmd->hdr.rat = FXL_RAT_3G;
        cmd->startStopScan = FXL_STOP_CONTINUOUS_TRIGGER;
        cmd->dspResetNeeded = TRUE;
        listenModeStartStopHandler(stopCmdBuf);
    }
    break;
    case ONEBIN_STATE_4G_SCANNING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL4gListenModeStopScanCmd *cmd = (fxL4gListenModeStopScanCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL4gListenModeStopScanCmd);
        cmd->hdr.msgType = FXL_4G_LISTEN_MODE_STOP_SCAN_CMD;
        cmd->hdr.rat = FXL_RAT_4G;
        cmd->dspResetNeeded = TRUE;
        listenMode4gStopScanCmdHandler(cmd);
    }
    break;
    case ONEBIN_STATE_2G_IDCATCHING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL2gStopIdCatcherCmd *cmd = (fxL2gStopIdCatcherCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL2gStopIdCatcherCmd);
        cmd->hdr.msgType = FXL_2G_STOP_IDCATCHER_CMD;
        cmd->hdr.rat = FXL_RAT_2G;
        cmd->dspResetNeeded = TRUE;
        stop2gIdcatcherCmdHandler(stopCmdBuf);
    }
    break;
    case ONEBIN_STATE_3G_IDCATCHING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL3gStopIdCatcherCmd *cmd = (fxL3gStopIdCatcherCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL3gStopIdCatcherCmd);
        cmd->hdr.msgType = FXL_3G_STOP_IDCATCHER_CMD;
        cmd->hdr.rat = FXL_RAT_3G;
        cmd->dspResetNeeded = TRUE;
        umtsStopIdCatcher(stopCmdBuf);
    }
    break;
    case ONEBIN_STATE_4G_IDCATCHING:
    {
        memset(stopCmdBuf, 0, 128);
        fxL4gStopIdCatcherCmd *cmd = (fxL4gStopIdCatcherCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL4gStopIdCatcherCmd);
        cmd->hdr.msgType = FXL_4G_STOP_IDCATCHER_CMD;
        cmd->hdr.rat = FXL_RAT_4G;
        cmd->dspResetNeeded = TRUE;
        lteStopIdCatcherHandler(stopCmdBuf);
    }
    break;
    case ONEBIN_STATE_3G_AUTOCONFIG:
    {
        memset(stopCmdBuf, 0, 128);
        fxL3gAutoConfigStopCmd *cmd = (fxL3gAutoConfigStopCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL3gAutoConfigStopCmd);
        cmd->hdr.msgType = FXL_3G_AUTO_CONFIG_STOP_CMD;
        cmd->hdr.rat = FXL_RAT_3G;
        cmd->dspResetNeeded = TRUE;
        umtsAutoConfigStop(stopCmdBuf);
    }
    break;

    case ONEBIN_STATE_2G_BASS:
    {
        memset(stopCmdBuf, 0, 128);
        fxL2gBassModeStopCmd *cmd = (fxL2gBassModeStopCmd *)stopCmdBuf;
        cmd->hdr.msgLength = sizeof(fxL2gBassModeStopCmd);
        cmd->hdr.msgType = FXL_2G_BASS_MODE_STOP_CMD;
        cmd->hdr.rat = FXL_RAT_2G;
        gsmBassModeStopCmdHandler(cmd);
    }
    break;

    default:
    {
        // Do Nothing
    }
    break;
    }

    currentOneBinState = ONEBIN_STATE_IDLE;
}

void lteSysInfoModifyCmdHandler(uint8 *inMsgBuf)
{
    fxL4gSysInfoModifyCmd *cmd = (fxL4gSysInfoModifyCmd *)inMsgBuf;
    fxL4gSysInfoModifyRsp *rsp = (fxL4gSysInfoModifyRsp *)msgBuf;
    memset(msgBuf, 0, sizeof(msgBuf));

    // generateSib1Modify(cmd);
    // generateSibsModify(cmd);

    rsp->result = FXL_SUCCESS;
    rsp->hdr.msgLength = sizeof(fxL4gSysInfoModifyRsp);
    rsp->hdr.msgType = FXL_4G_SYS_INFO_MODIFY_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gSysInfoModifyRsp));
    return;
}

void lteUeMeasurementCfgHndlr(unsigned char *inMsgBuf)
{
    unsigned int idx = 0;
    unsigned int idx1 = 0;
    fxL4gMeasurementCfgCmd *cmd = (fxL4gMeasurementCfgCmd *)inMsgBuf;
    fxL4gMeasurementCfgRsp *rsp = (fxL4gMeasurementCfgRsp *)msgBuf;

    if (generateRrcNeighMeasConfigMsg(cmd) == 0)
        rsp->result = FXL_SUCCESS;
    else
        rsp->result = FXL_FAILURE;

    rsp->hdr.msgLength = sizeof(fxL4gMeasurementCfgRsp);
    rsp->hdr.msgType = FXL_4G_UE_MEASUREMENT_CONFIG_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gMeasurementCfgRsp));
    return;
}

void lteConfigureNeighborCmdHandler(unsigned char *inMsgBuf)
{
    unsigned int totalNoOfNeighbor = 0;

    fxL4gConfigureNeighborCmd *cmd = (fxL4gConfigureNeighborCmd *)inMsgBuf;
    fxL4gConfigureNeighborRsp *rsp = (fxL4gConfigureNeighborRsp *)msgBuf;

    memset((asnLteNeighborConfig *)&gAsnLteNeighConfigData, 0, sizeof(gAsnLteNeighConfigData));

    if (currentOneBinState == ONEBIN_STATE_IDLE)
    {
        totalNoOfNeighbor = cmd->numberOfLteNeighbor + cmd->numberOfUmtsNeighbor + cmd->numberOfGsmNeighbor;

        if (totalNoOfNeighbor <= 3)
        {
            storeNeighborConfiguration(cmd);
            rsp->result = FXL_SUCCESS;
        }
        else
        {
            rsp->result = FXL_FAILURE;
        }
    }
    else
    {
        rsp->result = FXL_FAILURE;
    }

    rsp->hdr.msgLength = sizeof(fxL4gConfigureNeighborRsp);
    rsp->hdr.msgType = FXL_4G_CONFIGURE_NEIGHBOR_RSP;
    rsp->hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL4gConfigureNeighborRsp));
    return;
}

void gsmBassModeConfigureBandsCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gBassModeConfigureBandsCmd *cmd = (fxL2gBassModeConfigureBandsCmd *)inMsgBuf;
    fxL2gBassModeConfigureBandsRsp *rsp = (fxL2gBassModeConfigureBandsRsp *)msgBuf;

    rsp->result = FXL_FAILURE;
    if (currentDspImage == FXL_L1_BASS_IMAGE)
    {
        configureGsmBassParameters(cmd);
        rsp->result = FXL_SUCCESS;
    }
    rsp->hdr.msgLength = sizeof(fxL2gBassModeConfigureBandsRsp);
    rsp->hdr.msgType = FXL_2G_BASS_MODE_CONFIGURE_BANDS_RSP;
    rsp->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gBassModeConfigureBandsRsp));
    return;
}

void gsmBassModeStartCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gBassModeStartRsp *rsp = (fxL2gBassModeStartRsp *)msgBuf;
    rsp->result = FXL_FAILURE;

    if (currentDspImage == FXL_L1_BASS_IMAGE)
    {
        if (createAndStartBassModeThread() == -1)
        {
            rsp->result = FXL_FAILURE;
            logPrint(LOG_ERR, "Threads are not created \n");
        }
        else
        {
            logPrint(LOG_DEBUG, "Starting GSM Bass....\n");
            rsp->result = FXL_SUCCESS;
        }
    }
    rsp->hdr.msgLength = sizeof(fxL2gBassModeStartRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_BASS_MODE_START_RSP;
    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gBassModeStartRsp));
    return;
}

void gsmBassModeStopCmdHandler(tOCT_UINT8 *inMsgBuf)
{
    fxL2gBassModeStopRsp *rsp = (fxL2gBassModeStopRsp *)msgBuf;
    rsp->result = FXL_FAILURE;

    if (currentDspImage == FXL_L1_BASS_IMAGE)
    {
        rsp->result = stopBassModeApplication();

        unsigned int retCode = 0;
        /* Fill the Details */
        if ((isItPrimaryDsp() == TRUE))
        {
            char *argValue[2] = {"dr", "-p"};
            optreset = 1;
            retCode = g_Commands[12]->pfctCallBack(2, argValue);
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "Reset the primary DSP \n");
        }
        else
        {
            char *argValue[2] = {"dr", "-s"};
            optreset = 1;
            retCode = g_Commands[12]->pfctCallBack(2, argValue);
            rsp->result = FXL_SUCCESS;
            logPrint(LOG_DEBUG, "Reset the secondary DSP \n");
        }
    }
    rsp->hdr.msgLength = sizeof(fxL2gBassModeStopRsp);
    rsp->hdr.rat = FXL_RAT_2G;
    rsp->hdr.msgType = FXL_2G_BASS_MODE_STOP_RSP;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gBassModeStopRsp));
    return;
}

void send2gBassModeScanCompInd(void)
{
    fxL2gBassModeCompleteInd *ind = (fxL2gBassModeCompleteInd *)msgBuf;

    ind->hdr.msgLength = sizeof(fxL2gBassModeCompleteInd);
    ind->hdr.msgType = FXL_2G_BASS_MODE_COMPLETE_IND;
    ind->hdr.rat = FXL_RAT_2G;

    writeToExternalSocketInterface(msgBuf, sizeof(fxL2gBassModeCompleteInd));
    return;
}

#ifdef PUMP_REG_DATA
extern unsigned int pumpDataLoad;
tOCT_UINT8 pumpMsgBuf[EXTERNAL_MESSAGE_SIZE];
char randomString[SIZE_OF_IDENTITY_STR];
tOCT_UINT8 continuousPumpData = FALSE;
pthread_t pumDataThread;

char *randstring(int length)
{
    char *string = "0123456789";
    size_t stringLen = 10;
    unsigned int key = 0;

    for (int n = 0; n < length; n++)
    {
        key = rand() % stringLen;
        randomString[n] = string[key];
    }

    randomString[length] = '\0';

    return randomString;
}

void generateGsmData(void)
{
    fxL2gRegistrationAttemptedInd *ind = (fxL2gRegistrationAttemptedInd *)pumpMsgBuf;
    memset(ind, 0, sizeof(fxL2gRegistrationAttemptedInd));
    ind->listType = FXL_WHITEUSERSLIST;

    ind->hdr.msgLength = sizeof(fxL2gRegistrationAttemptedInd);
    ind->hdr.msgType = FXL_2G_REGISTRATION_ATTEMPTED_IND;
    ind->hdr.rat = FXL_RAT_2G;
    // Send these values over socket interface to outside world
    memcpy(ind->imsiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    memcpy(ind->imeiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    memcpy(ind->tmsi, randstring(SIZE_OF_TMSI_IDENTITY - 1), SIZE_OF_TMSI_IDENTITY);
    ind->rssidBm = -60;
    ind->snrdB = 0;
    ind->timingAdvance = 1;
    ind->imeiSv = 1;
    ind->last_lac = 111;

    logPrint(LOG_DEBUG, " PUMP DATA IMSI = %s , IMEI = %s \n", ind->imsiStr, ind->imeiStr);

    writeToExternalSocketInterface((tOCT_UINT8 *)ind, sizeof(fxL2gRegistrationAttemptedInd));
    return;
}

void generateUmtsData(void)
{
    fxL3gRegistrationAttemptedInd *ind = (fxL3gRegistrationAttemptedInd *)pumpMsgBuf;
    memset(ind, 0, sizeof(fxL3gRegistrationAttemptedInd));
    ind->listType = FXL_WHITEUSERSLIST;

    ind->hdr.msgLength = sizeof(fxL3gRegistrationAttemptedInd);
    ind->hdr.msgType = FXL_3G_REGISTRATION_ATTEMPTED_IND;
    ind->hdr.rat = FXL_RAT_3G;
    // Send these values over socket interface to outside world
    memcpy(ind->imsiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    memcpy(ind->imeiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    memcpy(ind->tmsi, randstring(SIZE_OF_TMSI_IDENTITY - 1), SIZE_OF_TMSI_IDENTITY);
    ind->initialRscpVal = -60;
    ind->ulScramblingCode = 100;
    ind->dlChannelizationCode = 200;
	ind->imeiSv = 1;
    ind->last_lac = 111;
    logPrint(LOG_DEBUG, " PUMP DATA IMSI = %s , IMEI = %s \n", ind->imsiStr, ind->imeiStr);

    writeToExternalSocketInterface((tOCT_UINT8 *)ind, sizeof(fxL3gRegistrationAttemptedInd));
    return;
}

void generateLteData(void)
{
    fxL4gRegistrationAttemptedInd *ind = (fxL4gRegistrationAttemptedInd *)pumpMsgBuf;
    memset(ind, 0, sizeof(fxL4gRegistrationAttemptedInd));
    ind->listType = FXL_WHITEUSERSLIST;

    ind->hdr.msgLength = sizeof(fxL4gRegistrationAttemptedInd);
    ind->hdr.msgType = FXL_4G_REGISTRATION_ATTEMPTED_IND;
    ind->hdr.rat = FXL_RAT_4G;
    // Send these values over socket interface to outside world
    memcpy(ind->imsiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    memcpy(ind->imeiStr, randstring(SIZE_OF_IDENTITY_STR - 1), SIZE_OF_IDENTITY_STR);
    ind->timingAdvance = 1;
    ind->lastTac = 200;
    ind->lastLac = 100;
    ind->rsrp = -60;
    ind->rssi = -45;
    ind->rsrq = 0;
    logPrint(LOG_DEBUG, " PUMP DATA IMSI = %s , IMEI = %s \n", ind->imsiStr, ind->imeiStr);
    writeToExternalSocketInterface((tOCT_UINT8 *)ind, sizeof(fxL4gRegistrationAttemptedInd));
    return;
}

void *pumpData(void *nothing)
{
    struct timespec sleepTime;
    if (pumpDataLoad < 20)
    {
        pumpDataLoad = 20;
    }

    while (continuousPumpData == TRUE)
    {
        if (currentOneBinState == ONEBIN_STATE_2G_IDCATCHING)
        {
            generateGsmData();
        }
        else if (currentOneBinState == ONEBIN_STATE_3G_IDCATCHING)
        {
            generateUmtsData();
        }
        else if (currentOneBinState == ONEBIN_STATE_4G_IDCATCHING)
        {
            generateLteData();
        }
        else
        {
        }

        /* Wakeup after each 55 millisec */
        sleepTime.tv_sec = 0;
        sleepTime.tv_nsec = pumpDataLoad * 1000000;
        nanosleep(&sleepTime, NULL);
    }
}
void startPumpData(void)
{
    continuousPumpData = TRUE;

    if (pthread_create(&pumDataThread, NULL, pumpData, (void *)NULL))
    {
        logPrint(LOG_ERR, "createPumpData Thread creation failed");
    }
    else
    {
        logPrint(LOG_DEBUG, "Starting PumpData....\n");
    }
}

void stopPumpData(void)
{
    continuousPumpData = FALSE;
}

#endif

#ifdef FEA_PICSIX_CHANGE
void handleSystemStatusTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{
    logPrint(LOG_DEBUG, "System status timeout \n");
    sendSystemStatusIndication(runningTask, FXL_RUNNING);
}

void sendSystemStatusIndication(fxLCurrentTask currentTask, fxLSystemCurrentState currentState)
{
    fxLSystemStatusInd *systemStatusInd = (fxLSystemStatusInd *)msgBuf;

    systemStatusInd->hdr.msgLength = sizeof(fxLSystemStatusInd);
    systemStatusInd->hdr.msgType = FXL_SYSTEM_STATUS_IND;

    systemStatusInd->runningTask = currentTask;
    systemStatusInd->status = currentState;

    if (currentTask == FXL_2G_IDC)
    {
        systemStatusInd->hdr.rat = FXL_RAT_2G;
        if (currentState == FXL_STARTED)
        {
            runningTask = currentTask;
            timerInit(&systemStatusTimer);
            logPrint(LOG_DEBUG, "Start System Status timer For GSM \n");
            timerStart(&systemStatusTimer, SYSTEM_STATUS_TIMEOUT_FOR_2G, SYSTEM_STATUS_TIMEOUT_FOR_2G,
                       handleSystemStatusTimeout, NULL);
        }
    }
    else if (currentTask == FXL_3G_IDC)
    {
        systemStatusInd->hdr.rat = FXL_RAT_3G;
        if (currentState == FXL_STARTED)
        {
            runningTask = currentTask;
            timerInit(&systemStatusTimer);
            logPrint(LOG_DEBUG, "Start System Status timer for 3G \n");
            timerStart(&systemStatusTimer, SYSTEM_STATUS_TIMEOUT_FOR_3G, SYSTEM_STATUS_TIMEOUT_FOR_3G,
                       handleSystemStatusTimeout, NULL);
        }
    }
    else if (currentTask == FXL_4G_IDC)
    {
        systemStatusInd->hdr.rat = FXL_RAT_4G;
        if (currentState == FXL_STARTED)
        {
            runningTask = currentTask;
            timerInit(&systemStatusTimer);
            logPrint(LOG_DEBUG, "Start System Status timer For LTE \n");
            timerStart(&systemStatusTimer, SYSTEM_STATUS_TIMEOUT_FOR_4G, SYSTEM_STATUS_TIMEOUT_FOR_4G,
                       handleSystemStatusTimeout, NULL);
        }
    }
    else
        systemStatusInd->hdr.rat = FXL_RAT_NONE;

    writeToExternalSocketInterface(msgBuf, sizeof(fxLSystemStatusInd));
    return;
}
#endif // FEA_PICSIX_CHANGE
