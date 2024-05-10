/*
    C ECHO client example using sockets
*/
#include <stdio.h> //printf
#include <stdlib.h>
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include "fxLSocketInterfaceApi.h"
#include "clientConfig.h"

#define MAX_RECV_DATA_LEN  (1024 * 32)

typedef enum{
	NO_IMAGE = 0,
	L1_SCANNER_IMAGE = 1,
	L1_IDCATCHER_IMAGE = 2
}l1imageType;

unsigned char l1ImageLoaded = NO_IMAGE;
unsigned char server_reply[MAX_RECV_DATA_LEN] = {0};
unsigned char sendMsgBuf[MAX_RECV_DATA_LEN] = {0};

void sendHandshakeCmd(int sock)
{
    fxLHandShakeCmd *cmd = (fxLHandShakeCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLHandShakeCmd);
    cmd->hdr.msgType = FXL_HANDSHAKE_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    cmd->clientSocketApiVersion = FXL_SOCKETINTERFACEAPI_VERSION;

    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLHandShakeCmd) , 0) < 0)
    {
    	printf ("TcpClient : Error : Send Handshake Message failed\n");
    }
    else
    {
    	printf ("TcpClient : Handshake Message sent....\n");
    }
}

void loadLteRusDspImage(int sock)
{
    fxLBootL1Cmd *cmd = (fxLBootL1Cmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLBootL1Cmd);
    cmd->hdr.msgType = FXL_BOOT_L1_CMD;
    cmd->hdr.rat = FXL_RAT_4G;

    if(dspInUse == PRIMARY)
      cmd->dspType = FXL_PRIMARY_DSP;
    else
      cmd->dspType = FXL_SECONDARY_DSP;

    cmd->l1ImageType = FXL_L1_LTE_SLS_IMAGE;

    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLBootL1Cmd) , 0) < 0)
    {
    	printf("TcpClient : Sending Boot L1 Command for Scanner failed\n");
    }
    else
    {
    	printf("TcpClient : Boot L1 Command for Scanner sent....\n");
    }
}

void loadLteNativeDspImage(int sock)
{
     fxLBootL1Cmd *cmd = (fxLBootL1Cmd *)sendMsgBuf;
     cmd->hdr.msgLength = sizeof(fxLBootL1Cmd);
     cmd->hdr.msgType = FXL_BOOT_L1_CMD;
     cmd->hdr.rat = FXL_RAT_4G;

     if( dspInUse == PRIMARY )
       cmd->dspType = FXL_PRIMARY_DSP;
     else
       cmd->dspType = FXL_SECONDARY_DSP;

     cmd->l1ImageType = FXL_L1_LTE_NATIVE_IMAGE;

     //Send some data
     if( send(sock , sendMsgBuf , sizeof(fxLBootL1Cmd) , 0) < 0)
     {
     	printf("TcpClient : Sending Boot L1 Command for IdCatcher failed\n");
     }
     else
     {
     	printf("TcpClient : Boot L1 Command for IdCatcher sent....\n");
     }
}

void configBaseStationForRus(int sock)
{
    fxL4gListenModeConfigureBandsCmd *cmd = (fxL4gListenModeConfigureBandsCmd*)sendMsgBuf;
    cmd->noOfBandsToScan = 1;
    cmd->band[0] = FXL_BAND_LTE_3;
    cmd->band[1] = FXL_BAND_LTE_5;
    cmd->band[2] = FXL_BAND_LTE_20;
    cmd->band[3] = FXL_BAND_LTE_7;

    cmd->noOfInterationsToScan = 1;

    cmd->hdr.msgLength = sizeof(fxL4gListenModeConfigureBandsCmd);
    cmd->hdr.msgType = FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gListenModeConfigureBandsCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Listen Mode Configure Bands send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Listen Mode Configure Bands sent....\n");
    }

}


void startBaseStationForRus(int sock)
{
    fxL4gListenModeStartScanCmd *cmd = (fxL4gListenModeStartScanCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gListenModeStartScanCmd);
    cmd->hdr.msgType = FXL_4G_LISTEN_MODE_START_SCAN_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    cmd->scanType = scanCategory;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gListenModeStartScanCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Listen Mode Start Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Listen Mode Start Command sent....\n");
    }
}

void stopBaseStationForRus(int sock)
{
	fxL4gListenModeStopScanCmd *cmd = (fxL4gListenModeStopScanCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gListenModeStopScanCmd);
    cmd->hdr.msgType = FXL_4G_LISTEN_MODE_STOP_SCAN_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gListenModeStopScanCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Listen Mode Stop Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Listen Mode Stop Command sent....\n");
    }
}

void changeTxRxAntennaId(int sock)
{
    fxLChangeTxRxAntennaIdCmd *cmd = (fxLChangeTxRxAntennaIdCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLChangeTxRxAntennaIdCmd);
    cmd->hdr.msgType   = FXL_CHANGE_TX_RX_ANTENNA_ID_CMD;
    cmd->hdr.rat       = FXL_RAT_4G;
    cmd->dspType       = FXL_PRIMARY_DSP;
    cmd->txAntennaId   = FXL_TX_RX_ANTENNA_ID_0;
    cmd->rxAntennaId   = FXL_TX_RX_ANTENNA_ID_0;

    //Send 
    if( send(sock , sendMsgBuf , sizeof(fxLChangeTxRxAntennaIdCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Change Tx Rx Antenna Id Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Change Tx Rx Antenna Id Command sent....\n");
    }
}

void configBaseStationForLteIdCatcher(int sock)
{
	fxL4gConfigureIdCatcherParamsCmd *cmd = (fxL4gConfigureIdCatcherParamsCmd*)sendMsgBuf;
	cmd->bandIndicator = FXL_BAND_LTE_40;
	cmd->earfcn = 39000;
	cmd->layer3CellId = 120;
	cmd->phyCellId = 500;
	cmd->tac = 500;
	cmd->numOfPlmn = 1;
	
	cmd->plmn[0].mccLength = 3;
	cmd->plmn[0].mcc[0] = 0;
	cmd->plmn[0].mcc[1] = 0;
	cmd->plmn[0].mcc[2] = 1;
	cmd->plmn[0].mncLength = 2;
	cmd->plmn[0].mnc[0] = 0;
	cmd->plmn[0].mnc[1] = 1;
	cmd->plmn[0].mnc[2] = 0;
	
	cmd->plmn[1].mccLength = 3;
	cmd->plmn[1].mcc[0] = 1;
	cmd->plmn[1].mcc[1] = 1;
	cmd->plmn[1].mcc[2] = 1;
	cmd->plmn[1].mncLength = 3;
	cmd->plmn[1].mnc[0] = 1;
	cmd->plmn[1].mnc[1] = 1;
	cmd->plmn[1].mnc[2] = 1;

	cmd->plmn[2].mccLength = 3;
	cmd->plmn[2].mcc[0] = 2;
	cmd->plmn[2].mcc[1] = 2;
	cmd->plmn[2].mcc[2] = 2;
	cmd->plmn[2].mncLength = 3;
	cmd->plmn[2].mnc[0] = 2;
	cmd->plmn[2].mnc[1] = 2;
	cmd->plmn[2].mnc[2] = 2;

	cmd->plmn[3].mccLength = 3;
	cmd->plmn[3].mcc[0] = 3;
	cmd->plmn[3].mcc[1] = 3;
	cmd->plmn[3].mcc[2] = 3;
	cmd->plmn[3].mncLength = 3;
	cmd->plmn[3].mnc[0] = 3;
	cmd->plmn[3].mnc[1] = 3;
	cmd->plmn[3].mnc[2] = 3;

	cmd->plmn[4].mccLength = 3;
	cmd->plmn[4].mcc[0] = 4;
	cmd->plmn[4].mcc[1] = 4;
	cmd->plmn[4].mcc[2] = 4;
	cmd->plmn[4].mncLength = 3;
	cmd->plmn[4].mnc[0] = 4;
	cmd->plmn[4].mnc[1] = 4;
	cmd->plmn[4].mnc[2] = 4;

	cmd->plmn[5].mccLength = 3;
	cmd->plmn[5].mcc[0] = 5;
	cmd->plmn[5].mcc[1] = 5;
	cmd->plmn[5].mcc[2] = 5;
	cmd->plmn[5].mncLength = 3;
	cmd->plmn[5].mnc[0] = 5;
	cmd->plmn[5].mnc[1] = 5;
	cmd->plmn[5].mnc[2] = 5;

	cmd->txAttndB = 0; // Added this value for API requirement
	cmd->enableAttRejCause = 0; // Reject Cause control
	cmd->attRejCause = 0;       // Fill values as per specs
	cmd->ulRxGainDb = 56; //change as per octasic recommendation range [0,73]
	if(tcpClientConfig == CONFIG_SCANNER_AND_IDCATCHER_WITH_AUTOCONFIG)
	  cmd->AutoConfigureEnabled = 1;
	else
	  cmd->AutoConfigureEnabled = 0;

	cmd->enablePrmredirectCfg = FALSE ; // FALSE : Normal Redirect(release) , TRUE : Permanent Redirect (Reject+ release)

	cmd->redirectionType = NO_REDIRECTION;
	if (cmd->redirectionType == REDIRECTION_TO_2G)
	{
	cmd->redirectionInfo.gsmRedirectinfo.bandIndicator = DCS1800;
	cmd->redirectionInfo.gsmRedirectinfo.startingarfcn = 590;
	}
	else if (cmd->redirectionType == REDIRECTION_TO_3G)
	{
		cmd->redirectionInfo.utraFDDUARFCN = 10833;
	}
	else if (cmd->redirectionType == REDIRECTION_TO_4G)
	{
		cmd->redirectionInfo.eutraEARFCN = cmd->earfcn ;
	}
	else if (cmd->redirectionType == REDIRECTION_TO_CDMA)
	{
		cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator = 1 ;
		cmd->redirectionInfo.cdmaRedirectinfo.startingarfcn = 877 ;
		cmd->redirectionInfo.cdmaRedirectinfo.phyCellId = 213 ;
	}

    cmd->lteBandwidth = 3; //LTE_BW_N25:2 ,  LTE_BW_N50 :3 , LTE_BW_N100 :5
    //cmd ->taValue = 15; //LTE_RACH_TA_DEFAULT:15 ; // 0-63
    cmd->pilot_boost_enable = 1;
    cmd->wlRedirectEarfcn = 39000;

    cmd->hdr.msgLength = sizeof(fxL4gConfigureIdCatcherParamsCmd);
    cmd->hdr.msgType = FXL_4G_CONFIGURE_IDCATCHER_PARAMS_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
   
    if( send(sock , sendMsgBuf , sizeof(fxL4gConfigureIdCatcherParamsCmd) , 0) < 0)
    {
        printf("TcpClient : 4G ID Catcher Config Params send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G ID Catcher Config Params sent....\n");
    }

}

void startBaseStationForIdCatcher(int sock)
{
	fxL4gStartIdCatcherCmd *cmd = (fxL4gStartIdCatcherCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gStartIdCatcherCmd);
    cmd->hdr.msgType = FXL_4G_START_IDCATCHER_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gStartIdCatcherCmd) , 0) < 0)
    {
        printf("TcpClient : 4G ID Catcher Start Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G ID Catcher Start Command sent....\n");
    }
}

void stopBaseStationForIdCatcher(int sock)
{
	fxL4gStopIdCatcherCmd *cmd = (fxL4gStopIdCatcherCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gStopIdCatcherCmd);
    cmd->hdr.msgType = FXL_4G_STOP_IDCATCHER_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
	cmd->dspResetNeeded = TRUE;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gStopIdCatcherCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Id Catcher Stop Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Id Catcher Stop Command sent....\n");
    }
}


void enableTxCalibarion(int sock)
{
    fxLEnableTxCalibrationCmd *cmd = (fxLEnableTxCalibrationCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLEnableTxCalibrationCmd);
    cmd->hdr.msgType = FXL_ENABLE_TX_CALIBRATION_CMD;
    cmd->hdr.rat = FXL_RAT_4G;

    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLEnableTxCalibrationCmd) , 0) < 0)
    {
       printf("TcpClient : TX Calibration Command send message failed\n");
    }
    else
    {
       printf("TcpClient : TX Calibration Command sent....\n");
    }
}

void configIdentityList(int sock)
{
    fxLConfigureIdentityListCmd *cmd = (fxLConfigureIdentityListCmd*)sendMsgBuf;
    cmd->defaultListConfig = FXL_WHITEUSERSLIST ;
    cmd->configList[0].idType = FXL_IDENTITY_IMSI ;
    cmd->configList[0].listType = FXL_BLACKUSERSLIST;
    memcpy(&cmd->configList[0].identity, "001012345678936",SIZE_OF_IDENTITY_STR) ;

    cmd->noOfEntries = 1;
    cmd->hdr.msgLength = sizeof(fxLConfigureIdentityListCmd);
    cmd->hdr.msgType = FXL_CONFIGURE_IDENTITY_LIST_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLConfigureIdentityListCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Configure Identity List Command send message failed\n");
    }
    else
    {

        printf("TcpClient : 4G Configure Identity List Command sent....\n");
    }

}

void configLteBaseStationForSelectiveScanRus(int sock)
{
	fxL4gListenModeConfigureSelectiveFreqCmd *cmd = (fxL4gListenModeConfigureSelectiveFreqCmd*)sendMsgBuf;
    cmd->noOfEarfcnConfigured = 10;

    cmd->earfcn[0] = 1570;
    cmd->earfcn[1] = 1575;
    cmd->earfcn[2] = 1580;
    cmd->earfcn[3] = 3095;
    cmd->earfcn[4] = 3100;
    cmd->earfcn[5] = 3105;
    cmd->earfcn[6] = 6301;
    cmd->earfcn[7] = 6300;
    cmd->earfcn[8] = 6302;
    cmd->earfcn[9] = 6303;

    cmd->noOfInterationsToScan = 1;


    cmd->hdr.msgLength = sizeof(fxL4gListenModeConfigureSelectiveFreqCmd);
    cmd->hdr.msgType = FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gListenModeConfigureSelectiveFreqCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Listen Mode Configure Selective Frequencies send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Listen Mode Configure Selective Frequencies sent....\n");
    }

    return;
}

void blUeRedirect(int sock , char* imsi)
{
    fxL4gBLUeRedirectCmd *cmd = (fxL4gBLUeRedirectCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gBLUeRedirectCmd);
    cmd->hdr.msgType = FXL_4G_BL_UE_REDIRECT_CMD;
    cmd->hdr.rat = FXL_RAT_4G;

    cmd->redirectionType = REDIRECTION_TO_CDMA;
    cmd->redirectionInfo.cdmaRedirectinfo.startingarfcn = 887;
    cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator = 1;
    memcpy(cmd->imsiStr , imsi , SIZE_OF_IDENTITY_STR);

    if( send(sock , sendMsgBuf , sizeof(fxL4gBLUeRedirectCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Id Catcher BL UE Redirect send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Id Catcher BL UE Redirect Command sent....\n");
    }

}


void start4GSilentCall(int sock , char* imsi)
{
	fxL4gStartSilentCallCmd *cmd = (fxL4gStartSilentCallCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gStartSilentCallCmd);
    cmd->hdr.msgType = FXL_4G_START_SILENT_CALL_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    memcpy(cmd->imsiStr , imsi , SIZE_OF_IDENTITY_STR);
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gStartSilentCallCmd) , 0) < 0)
    {
        printf("TcpClient : 4G Id Catcher Start Silent Call send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G Id Catcher Start Silent Call Command sent....\n");
    }
}

#if 0
void changeTxAttenuation(int sock , int attn)
{
	fxL4gIdCatcherRfModifyCmd *cmd = (fxL4gIdCatcherRfModifyCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL4gIdCatcherRfModifyCmd);
    cmd->hdr.msgType = FXL_4G_IDCATCHER_RF_MODIFY_CMD;
    cmd->hdr.rat = FXL_RAT_4G;
    cmd->TxAttenuationInDb = attn;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL4gIdCatcherRfModifyCmd) , 0) < 0)
    {
        printf("TcpClient : 4G RF Modify Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 4G RF Modify Stop Command sent....\n");
    }
}

#ifdef FXL_4G_TX_JAMMER
void start4gTxJammer (int sock)
{
     fxL4gTxJammerStartCmd *cmd = (fxL4gTxJammerStartCmd *)sendMsgBuf;
     cmd->hdr.msgLength = sizeof(fxL4gTxJammerStartCmd);
     cmd->hdr.msgType = FXL_4G_TX_JAMMER_START_CMD;
     cmd->hdr.rat = FXL_RAT_4G;
     cmd->earfcn = 1725;

     if( send(sock , sendMsgBuf , sizeof(fxL4gTxJammerStartCmd) , 0) < 0)
     {
         printf("TcpClient : 4G start 4g Tx Jammer Command send message failed\n");
     }
     else
     {
         printf("TcpClient : 4G start 4g Tx Jammer Command sent....\n");
     }
}

void stop4gTxJammer (int sock)
{
     fxL4gTxJammerStopCmd *cmd = (fxL4gTxJammerStopCmd *)sendMsgBuf;
     cmd->hdr.msgLength = sizeof(fxL4gTxJammerStopCmd);
     cmd->hdr.msgType = FXL_4G_TX_JAMMER_STOP_CMD;
     cmd->hdr.rat = FXL_RAT_4G;

     if( send(sock , sendMsgBuf , sizeof(fxL4gTxJammerStopCmd) , 0) < 0)
     {
         printf("TcpClient : 4G stop 4g Tx Jammer Command send message failed\n");
     }
     else
     {
         printf("TcpClient : 4G stop 4g Tx Jammer Command sent....\n");
     }
}
#endif //FXL_4G_TX_JAMMER

void ltesystemInfoModify(int sock)
{
   fxL4gSysInfoModifyCmd *cmd = (fxL4gSysInfoModifyCmd *)sendMsgBuf;
   cmd->hdr.msgLength = sizeof(fxL4gSysInfoModifyCmd);
   cmd->hdr.msgType = FXL_4G_SYS_INFO_MODIFY_CMD;
   cmd->hdr.rat = FXL_RAT_4G;

    cmd->sibMask = 0;//SIB1_MASK | SIB2_MASK |SIB3_MASK ; 
    // NOTE : Please read properly below points before using sib modification feature	
    // SIB2_MASK 1 ,SIB3_MASK 2,SIB4_MASK 4,SIB5_MASK 8,SIB6_MASK 16,SIB7_MASK 32,SIB8_MASK 64,SIB1_MASK 128 
    // if suppose sib1 to modify , set cmd->sibMask to sib1_mask   
    // if sib1 , sib2 and sib3 to modify , set cmd->sibMask to sib1_mask | sib2_mask | sib3_mask ;
    // Send some data
    if((cmd->sibMask & SIB1_MASK) == SIB1_MASK)
    	{
    			// Set parameters you need to modify here by checking the fxL4gSib1_lte structure.
    			// by default set to -1 by using memset 
			memset(&(cmd->sib1) , -1, sizeof(fxL4gSib1_lte));

			// Value -1 may be valid for few parameters , so update them with invalid value
			cmd->sib1.qRxLevMin = -71;
			cmd->sib1.pMax = -31;

				//Add Parameters which need to be changed
			//cmd->sib1.systemValueTag = 1;
			//cmd->sib1.tac = 1111;
			//cmd->sib1.pMax = 15;                //not working                    
                      //  cmd->sib1.isIntraFreqSelectionAllowed = FALSE;   // fine FALSE=1 ,default=0
                      //  cmd->sib1.isCellBarred = FALSE ;                 //FALSE=0-default
                       // cmd->sib1.qRxLevMin = -55;             //fine
                        //cmd->sib1.qRxLevMinOffset = 3;          //fine default=1
                     //   cmd->sib1.systemValueTag = 1;
	}

    if((cmd->sibMask & SIB2_MASK) == SIB2_MASK)
	{
		    	printf("SIB2_MASK was set to configure SIB1 parameters \n");
	   		// Set parameters you need to modify here by checking the fxL4gSib1_lte structure.
    			// by default set to -1 by using memset 
			memset(&(cmd->sib2), -1, sizeof(fxL4gSib2_lte));
			
			// Value -1 may be valid for few parameters , so update them with invalid value
			cmd->sib2.refSignalPower = 61;
			cmd->sib2.deltaPreambleMsg3 = -2;
			cmd->sib2.p0NominalPUCCH = -128;
			cmd->sib2.p0NominalPUSCH = -127;

			//Add Parameters which need to be changed
			//cmd->sib2.maxHARQMsg3Tx= 3;
	}

    if((cmd->sibMask & SIB3_MASK) == SIB3_MASK)
	{
		    	printf("SIB3_MASK was set to configure SIB1 parameters \n");
	   		// Set parameters you need to modify here by checking the fxL4gSib1_lte structure.
    			// by default set to -1 by using memset 
			memset(&(cmd->sib3) , -1 ,sizeof(fxL4gSib3_lte));
			
			// Value -1 may be valid for few parameters , so update them with invalid value
			cmd->sib3.qRxLevMin = -71;

			//Add Parameters which need to be changed
			//cmd->sib3.cellReselectionPriority = 1;
	}

   if( send(sock , sendMsgBuf , sizeof(fxL4gSysInfoModifyCmd) , 0) < 0)
   {
       printf("TcpClient : 4G Modify System Info Command send message failed\n");
   }
   else
   {
       printf("TcpClient : 4G Modify System Info Command sent....\n");
   }
}
#endif

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    fxLHeader *hdr = NULL;
    int enable = 1024*32;
    static int startSilentCall = 0;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
    	printf("TcpClient : Error : Socket creation failed\n");
    	exit (0);
    }
    printf("TcpClient : Socket created....\n");

    /* Reuse the address */
	if (setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
	   printf("TcpClient : Error : failed to set socket option for reuse\n");
	   return 1;
	}

	/* Set Send Buffer Size */
	enable = 1024*32;
	if (setsockopt (sock, SOL_SOCKET, SO_SNDBUF, &enable, sizeof(int)) < 0)
	{
	   printf("TcpClient : Error : failed to set socket option for send buffer size\n");
	   return 1;
	}

	/* Set Recv Buffer Size */
	enable = 1024*32;
	if (setsockopt (sock, SOL_SOCKET, SO_RCVBUF, &enable, sizeof(int)) < 0)
	{
	   printf("TcpClient : Error : failed to set socket option for recv buffer size\n");
	   return 1;
	}

    server.sin_addr.s_addr = inet_addr(ipaddress);
    server.sin_family = AF_INET;

    if(dspInUse == PRIMARY)
      server.sin_port = htons( SERVER_PORT_FOR_PRI );
    else
      server.sin_port = htons( SERVER_PORT_FOR_SEC );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
    	printf("TcpClient : Error : Connection failed to PORT = %d \n" , server.sin_port);
    	exit (0);
    }

    printf("TcpClient : Connected.....\n");
    sendHandshakeCmd(sock);
     
    //keep communicating with server
    while(1)
    {       
        //Receive a reply from the server
        if( recv(sock , server_reply , MAX_RECV_DATA_LEN , 0) < 0)
        {
        	puts("TcpClient : Error : Receive failed");
        }
        hdr = (fxLHeader*)server_reply;

        switch(hdr->msgType)
        {
            case FXL_HANDSHAKE_RSP:
            {
                fxLHandShakeRsp *rsp = (fxLHandShakeRsp*)server_reply;
                printf("TcpClient : Handshake Response received with result(%d)\n", rsp->result);
                if( tcpClientConfig == CONFIG_IDCATCHER_ONLY )
                {
                    configIdentityList(sock);
                }
                else
                {
                	l1ImageLoaded = L1_SCANNER_IMAGE;
                	loadLteRusDspImage(sock);
                }
            }
            break;

            case FXL_BOOT_L1_RSP:
            {
                fxLBootL1Rsp *rsp = (fxLBootL1Rsp*)server_reply;
                printf("TcpClient : Boot L1 Response received with result(%d)\n",rsp->result);

                if( l1ImageLoaded == L1_SCANNER_IMAGE )
                {
                	if(scanInUse == SELECTIVE_SCAN)
                	{
                		configLteBaseStationForSelectiveScanRus(sock);
                         //start4gTxJammer(sock);
                	}
                	else
                	{
                		configBaseStationForRus(sock);
                	}
                }
                else
                	configBaseStationForLteIdCatcher(sock);

            }
            break;

            case FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_RSP:
            {
            	fxL4gListenModeConfigureBandsRsp *rsp = (fxL4gListenModeConfigureBandsRsp*)server_reply;
                printf("TcpClient : Listen Mode Configure Bands Response received with result(%d)\n",rsp->result);
                startBaseStationForRus(sock);
            }
            break;

            case FXL_4G_LISTEN_MODE_SYSTEM_INFO_IND:
            {
            	fxL4gListenModeSystemInfoInd *ind = (fxL4gListenModeSystemInfoInd*)server_reply;
                int i = 0 , j = 0;

                printf("================================================\n");
				printf("TcpClient : 4G Listen Mode Sys Info Ind received\n");
				printf("================================================\n");
				printf("MCC-0\t\t\t:\t%d\n", ind->sib1.plmn[0].mcc[0]);
				printf("MCC-1\t\t\t:\t%d\n", ind->sib1.plmn[0].mcc[1]);
				printf("MCC-2\t\t\t:\t%d\n", ind->sib1.plmn[0].mcc[2]);
				printf("MNC-0\t\t\t:\t%d\n", ind->sib1.plmn[0].mnc[0]);
				printf("MNC-1\t\t\t:\t%d\n", ind->sib1.plmn[0].mnc[1]);
				printf("MNC-2\t\t\t:\t%d\n", ind->sib1.plmn[0].mnc[2]);
				printf("EARFCN\t\t\t:\t%d\n", ind->earfcn);
				printf("Bandwidth\t\t\t:\t%d\n", ind->dlBw);
				printf("TAC\t\t\t:\t%d\n", ind->sib1.tac);
				printf("Phy CELL-ID\t\t\t:\t%d\n", ind->phyCellId);
				printf("freqBandIndicator\t\t\t:\t%d\n", ind->sib1.freqBandIndicator);
				printf("noOfTxAntPorts\t\t\t:\t%d\n", ind->noOfTxAntPorts);
				printf("phichDuration\t\t\t:\t%d\n", ind->phichDuration);
				printf("phichResource\t\t\t:\t%d\n", ind->phichResource);
				printf("l3cellId\t\t\t:\t%d\n", ind->sib1.l3cellId);
				printf("rsrp\t\t\t:\t%lf\n", ind->rsrp);
				printf("rssi\t\t\t:\t%lf\n", ind->rssi);
				printf("rsrq\t\t\t:\t%lf\n", ind->rsrq);
				printf("noOfIntraFreqNeighbors\t\t\t:\t%d\n", ind->sib4.noOfIntraFreqNeighbors);
				/*for(j=0; j< ind->sib4.noOfIntraFreqNeighbors; j++)
				{
					//printf("LTE-IntraFreq-Neighbor-CellID\t\t\t:\t%d\n", ind->sib4.intraFreqNeighborCells[j]);
				}*/
				printf("noOfInterFreqNeighbors\t\t\t:\t%d\n", ind->sib5.noOfInterFreqNeighbourCells);
				for(j=0; j< ind->sib5.noOfInterFreqNeighbourCells; j++)
				{
					printf("LTE-InterFreq-Neighbor-Cell-EARFCN\t\t\t:\t%d\n", ind->sib5.earfcnInterFreqNeighbors[j]);
				}
				printf("noOfInterRatUmtsNeighbors\t\t\t:\t%d\n", ind->sib6.noOfInterRatUmtsNeighbors);
				for(j=0; j < ind->sib6.noOfInterRatUmtsNeighbors; j++)
				{
					printf("LTE-InterRat-UMTS-Neighbor-Cell-UARFCN\t\t\t:\t%d\n", ind->sib6.uarfcnInterRatNeighbors[j]);
				}
				printf("noOfInterRatGsmNeighbors\t\t\t:\t%d\n", ind->sib7.noOfInterRatGsmNeighbors);
				for(j=0; j < ind->sib7.noOfInterRatGsmNeighbors; j++)
				{
					printf("LTE-InterRat-GSM-Neighbor-Cell-Starting-ARFCN\t\t\t:\t%d\n", ind->sib7.startingArfcnInterRatNeighbors[j]);
				}
                printf("\n");
            }
            break;

            case FXL_4G_LISTEN_MODE_SCAN_COMPLETE_IND:
            {
            	fxL4gListenModeScanCompleteInd *rsp= (fxL4gListenModeScanCompleteInd*)server_reply;
            	printf("TcpClient : Listen Mode scan Complete Indication received\n");
                printf("#########################################################\n");
                printf("\n");

                stopBaseStationForRus(sock);
            }
            break;

            case FXL_4G_LISTEN_MODE_STOP_SCAN_RSP:
            {
            	fxL4gListenModeStopScanRsp *rsp= (fxL4gListenModeStopScanRsp*)server_reply;
                printf("TcpClient : 4G Listen Mode Stop Scan Response received with result(%d)\n",rsp->result);

                if( tcpClientConfig == CONFIG_SCANNER_ONLY )
                {
                	exit(1);
                }
                else
                {
                	configIdentityList(sock);
                }

            }
            break;

            case FXL_CONFIGURE_IDENTITY_LIST_RSP:
            {
                fxLConfigureIdentityListRsp *rsp = (fxLConfigureIdentityListRsp*)server_reply;
                printf("TcpClient : 4G Identity List Configure Response received with result(%ld)\n", rsp->result);
                changeTxRxAntennaId(sock);
            }
            break;

            case FXL_CHANGE_TX_RX_ANTENNA_ID_RSP:
			{
		        fxLConfigureIdentityListRsp *rsp = (fxLConfigureIdentityListRsp*)server_reply;
		        printf("TcpClient : 4G Change Tx Rx Antenna Id Response received with result(%ld)\n", rsp->result);
				l1ImageLoaded = L1_IDCATCHER_IMAGE;
				loadLteNativeDspImage(sock);
			}
			break;

            case FXL_4G_LISTEN_MODE_START_SCAN_RSP:
            {
            	fxL4gListenModeStartScanRsp *rsp= (fxL4gListenModeStartScanRsp*)server_reply;
                printf("TcpClient : 4G Listen Mode Start Scan Response received with result(%d)\n",rsp->result);

            }
            break;

			case FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP:
            {
            	fxL4gListenModeConfigureSelectiveFreqRsp *rsp= (fxL4gListenModeConfigureSelectiveFreqRsp*)server_reply;
                printf("TcpClient : 4G Configure Selective Freq Response received with result(%d)\n",rsp->result);
                startBaseStationForRus(sock);
            }
            break;

            case FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP:
            {
            	fxL4gConfigureIdCatcherParamsRsp *rsp= (fxL4gConfigureIdCatcherParamsRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher Configure Response received with result(%d)\n",rsp->result);
                startBaseStationForIdCatcher(sock);
              // ltesystemInfoModify(sock); 

            }
            break;

            case FXL_4G_REGISTRATION_ATTEMPTED_IND:
            {
            	fxL4gRegistrationAttemptedInd *ind = (fxL4gRegistrationAttemptedInd*) server_reply;
                printf("#################################################################################################\n");

				if (ind->listType == FXL_WHITEUSERSLIST)
				{
					printf("\t\tWhite Listed UE Details\n");
				}
				else if (ind->listType == FXL_BLACKUSERSLIST)
				{
					printf("\t\tBlack Listed UE Details\n");
					if(startSilentCall == 0)
					{
						sleep(20);
						start4GSilentCall(sock , ind->imsiStr);
						startSilentCall = 1;
					}
					//changeTxAttenuation(sock , startSilentCall++);
				}
				printf("IMSI = %s, IMEI = %s , Timing Advance = %d\n", ind->imsiStr, ind->imeiStr, ind->timingAdvance);
				printf("GUTI DETAILS:- MMECODE = %d , MMEGRPID = %d , MTMSI(Hex-Value) = %08x \n" , ind->guti.mmecode , ind->guti.mmegrpID , ind->guti.mtmsi);
				printf("PLMN DETAILS-MCC:- MCC-1 = %d , MCC-2 = %d , MCC-3 = %d \n" , ind->guti.plmn.mcc[0] , ind->guti.plmn.mcc[1] , ind->guti.plmn.mcc[2]);
				printf("PLMN DETAILS-MNC:- MNC-1 = %d , MNC-2 = %d , MNC-3 = %d \n" , ind->guti.plmn.mnc[0] , ind->guti.plmn.mnc[1] , ind->guti.plmn.mnc[2]);

	            printf("#################################################################################################\n");
	            //sleep(10);
	            //stopBaseStationForIdCatcher(sock);
            }
            break;

            case FXL_4G_START_IDCATCHER_RSP:
            {
            	fxL4gStartIdCatcherRsp *rsp= (fxL4gStartIdCatcherRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher Start Response received with result(%d)\n",rsp->result);
                sleep(5);
                enableTxCalibarion(sock);
                   // ltesystemInfoModify(sock); 
            }
            break;

            case FXL_ENABLE_TX_CALIBRATION_RSP:
            {
                fxLEnableTxCalibrationRsp *rsp= (fxLEnableTxCalibrationRsp*)server_reply;
                printf("TcpClient : TX Calibration Response received with result(%d) and cause (%d)\n",rsp->result,rsp->failureCause);
            }
            break;

            case FXL_4G_START_SILENT_CALL_RSP:
            {
            	fxL4gStartSilentCallRsp *rsp= (fxL4gStartSilentCallRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher Start Silent Call Response received with result(%d)\n",rsp->result);
            }
            break;

            case FXL_4G_MEASUREMENT_REPORT_IND:
            {
            	fxL4gMeasurementReportInd *ind= (fxL4gMeasurementReportInd*)server_reply;
                printf("Measurement Report From IMSI = %s , RSRP = %d dBm, RSRQ = %f dB\n", ind->imsiStr , ind->rsrp , ind->rsrq);
            }
            break;

            case FXL_4G_STOP_IDCATCHER_RSP:
            {
            	fxL4gStopIdCatcherRsp *rsp= (fxL4gStopIdCatcherRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher Stop Response received with result(%d)\n",rsp->result);
                configIdentityList(sock);
            }
            break;

            case FXL_4G_IDCATCHER_RF_MODIFY_RSP:
            {
            	fxL4gIdCatcherRfModifyRsp* rsp = (fxL4gIdCatcherRfModifyRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher RF Modify Response received with result(%d)\n",rsp->result);
            }
            break;

            case FXL_4G_BL_UE_REDIRECT_RSP:
            {
                fxL4gBLUeRedirectRsp* rsp = (fxL4gBLUeRedirectRsp*)server_reply;
                printf("TcpClient : 4G ID Catcher BL UE Redirect Response received with result(%d)\n",rsp->result);
            }
            break;

#ifdef FXL_4G_TX_JAMMER
		case FXL_4G_TX_JAMMER_STATUS_IND:
			{
			    fxL4gTxJammerStatusInd* rsp = (fxL4gTxJammerStatusInd*)server_reply;
                       printf("TcpClient : 4G TX jammer Status Ind received with result(%d)\n",rsp->status);
					   if (rsp->status == FXL_4G_TX_JAMMER_NO_CELL_FOUND)
					   	stop4gTxJammer(sock);
			}
		  break;
#endif // FXL_4G_TX_JAMMER
		case FXL_BL_UE_POWER_OFF_IND:
           		 {
	            	fxLBlUePowerOffInd *ind = (fxLBlUePowerOffInd*) server_reply;
	                printf("#################################################################################################\n");
					printf("USER (IMSI = %s) SWITCH OFF (UE INITIATED)\n", ind->imsiStr);
		            printf("#################################################################################################\n");
		            //sleep(10);
		            //stopBaseStationForIdCatcher(sock);
           		}
	        break;
	      case FXL_4G_SYS_INFO_MODIFY_RSP:
	            {
	                fxL4gSysInfoModifyRsp *rsp= (fxL4gSysInfoModifyRsp*)server_reply;
	                printf("TcpClient : 4G Modify System Info Response received with result(%ld)\n", rsp->result);
			   //startBaseStationForIdCatcher(sock);
	            }
            break;

            case FXL_LISTEN_MODE_RSSI_SCAN_RESULT_IND:
            {
               int i;
               fxLListenModeRssiScanResultInd *ind = (fxLListenModeRssiScanResultInd *)server_reply;
               printf("TcpClient : fxLListenModeRssiScanResultInd received\n");
               printf("TcpClinet : Band = %d, Number of Channels = %d\n", ind->band3g, ind->numOfChannels);
               for (i = 0; i < ind->numOfChannels; i++)
               {
                   printf("UARFCN = %d & RSSI = %6.3f\n", 
                   ind->channelInfo[i].channelNum, ind->channelInfo[i].rssi);
               }
               printf("\n");
            }
            break;

            default:
            {
            	printf("TcpClient : Unknown message received msgType(%d)\n", hdr->msgType);
            }
            break;
        }
    }
     
    return 0;
}
