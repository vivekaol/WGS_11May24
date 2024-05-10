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
    cmd->hdr.rat = FXL_RAT_2G;
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

void loadCdmaRusDspImage(int sock)
{
    fxLBootL1Cmd *cmd = (fxLBootL1Cmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLBootL1Cmd);
    cmd->hdr.msgType = FXL_BOOT_L1_CMD;
    cmd->hdr.rat = FXL_RAT_CDMA;

    if(dspInUse == PRIMARY)
      cmd->dspType = FXL_PRIMARY_DSP;
    else
      cmd->dspType = FXL_SECONDARY_DSP;

    cmd->l1ImageType = FXL_L1_UMTS_SLS_IMAGE;

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

void configBaseStationForRus(int sock)
{
    fxLCdmaListenModeConfigureBandsCmd *cmd = (fxLCdmaListenModeConfigureBandsCmd*)sendMsgBuf;
    cmd->noOfBandsToScan = 1;
    cmd->band[0] = FXL_CDMA_BAND_0;
    cmd->noOfScanIterations = 1;

    cmd->hdr.msgLength = sizeof(fxLCdmaListenModeConfigureBandsCmd);
    cmd->hdr.msgType = FXL_CDMA_LISTEN_MODE_CONFIGURE_BANDS_CMD;
    cmd->hdr.rat = FXL_RAT_CDMA;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLCdmaListenModeConfigureBandsCmd) , 0) < 0)
    {
        printf("TcpClient : CDMA Listen Mode Configure Bands send message failed\n");
    }
    else
    {
        printf("TcpClient : CDMA Listen Mode Configure Bands sent....\n");
    }

}

void configBaseStationForSelectiveScanRus(int sock)
{
    fxLCdmaListenModeConfigureSelectiveFreqCmd *cmd = (fxLCdmaListenModeConfigureSelectiveFreqCmd*)sendMsgBuf;
    cmd->noOfChannelConfigured = 2;

    cmd->bandChannel[0].channel = 42;
    cmd->bandChannel[0].band  = FXL_CDMA_BAND_0;
    cmd->bandChannel[1].channel = 226;
    cmd->bandChannel[1].band  = FXL_CDMA_BAND_0;

#if 0
    cmd->bandArfcn[2].arfcn = 23;
    cmd->bandArfcn[2].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[3].arfcn = 27;
    cmd->bandArfcn[3].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[4].arfcn = 29;
    cmd->bandArfcn[4].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[5].arfcn = 68;
    cmd->bandArfcn[5].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[6].arfcn = 71;
    cmd->bandArfcn[6].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[7].arfcn = 73;
    cmd->bandArfcn[7].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[8].arfcn = 75;
    cmd->bandArfcn[8].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[9].arfcn = 78;
    cmd->bandArfcn[9].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[10].arfcn = 80;
    cmd->bandArfcn[10].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[11].arfcn = 82;
    cmd->bandArfcn[11].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[12].arfcn = 103;
    cmd->bandArfcn[12].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[13].arfcn = 107;
    cmd->bandArfcn[13].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[14].arfcn = 109;
    cmd->bandArfcn[14].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[15].arfcn = 108;
    cmd->bandArfcn[15].band  = FXL_BAND_E_GSM;
    cmd->bandArfcn[16].arfcn = 514;
    cmd->bandArfcn[16].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[17].arfcn = 520;
    cmd->bandArfcn[17].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[18].arfcn = 537;
    cmd->bandArfcn[18].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[19].arfcn = 540;
    cmd->bandArfcn[19].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[20].arfcn = 542;
    cmd->bandArfcn[20].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[21].arfcn = 543;
    cmd->bandArfcn[21].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[22].arfcn = 546;
    cmd->bandArfcn[22].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[23].arfcn = 555;
    cmd->bandArfcn[23].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[24].arfcn = 557;
    cmd->bandArfcn[24].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[25].arfcn = 560;
    cmd->bandArfcn[25].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[26].arfcn = 706;
    cmd->bandArfcn[26].band  = FXL_BAND_DCS_1800;
    cmd->bandArfcn[27].arfcn = 708;
    cmd->bandArfcn[27].band  = FXL_BAND_PCS_1900;
    cmd->bandArfcn[28].arfcn = 712;
    cmd->bandArfcn[28].band  = FXL_BAND_PCS_1900;
    cmd->bandArfcn[29].arfcn = 715;
    cmd->bandArfcn[29].band  = FXL_BAND_PCS_1900;
    cmd->bandArfcn[30].arfcn = 707;
    cmd->bandArfcn[30].band  = FXL_BAND_PCS_1900;
    cmd->bandArfcn[31].arfcn = 709;
    cmd->bandArfcn[31].band  = FXL_BAND_PCS_1900;
#endif

    cmd->noOfScanIterations = 1;


    cmd->hdr.msgLength = sizeof(fxLCdmaListenModeConfigureSelectiveFreqCmd);
    cmd->hdr.msgType = FXL_CDMA_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD;
    cmd->hdr.rat = FXL_RAT_CDMA;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLCdmaListenModeConfigureSelectiveFreqCmd) , 0) < 0)
    {
        printf("TcpClient : CDMA Listen Mode Configure Selective Frequencies send message failed\n");
    }
    else
    {
        printf("TcpClient : CDMA Listen Mode Configure Selective Frequencies sent....\n");
    }

}

void startBaseStationForRus(int sock)
{
    fxLCdmaListenModeStartStopScanCmd *cmd = (fxLCdmaListenModeStartStopScanCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLCdmaListenModeStartStopScanCmd);
    cmd->hdr.msgType = FXL_CDMA_LISTEN_MODE_STARTSTOP_SCAN_CMD;
    cmd->hdr.rat = FXL_RAT_CDMA;
    cmd->scanType = scanCategory;
    cmd->startStopScan = FXL_START_CONTINUOUS_TRIGGER;
    cmd->dspResetNeeded = 0;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLCdmaListenModeStartStopScanCmd) , 0) < 0)
    {
        printf("TcpClient : CDMA Listen Mode Start Command send message failed\n");
    }
    else
    {
        printf("TcpClient : CDMA Listen Mode Start Command sent....\n");
    }
}

void stopBaseStationForRus(int sock)
{
    fxLCdmaListenModeStartStopScanCmd *cmd = (fxLCdmaListenModeStartStopScanCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLCdmaListenModeStartStopScanCmd);
    cmd->hdr.msgType = FXL_CDMA_LISTEN_MODE_STARTSTOP_SCAN_CMD;
    cmd->hdr.rat = FXL_RAT_CDMA;
    cmd->scanType = scanCategory;
    cmd->startStopScan = FXL_STOP_CONTINUOUS_TRIGGER;
    cmd->dspResetNeeded = 1;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL2gListenModeStopScanCmd) , 0) < 0)
    {
        printf("TcpClient : 2G Listen Mode Stop Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 2G Listen Mode Stop Command sent....\n");
    }
}

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    fxLHeader *hdr = NULL;
    int enable = 1024*32;
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
                printf("TcpClient : Handshake Response received with result(%ld)\n", rsp->result);
                l1ImageLoaded = L1_SCANNER_IMAGE;
                loadCdmaRusDspImage(sock);
            }
            break;

            case FXL_BOOT_L1_RSP:
            {
                fxLBootL1Rsp *rsp = (fxLBootL1Rsp*)server_reply;
                printf("TcpClient : Boot L1 Response received with result(%ld)\n",rsp->result);

               	if(scanInUse == SELECTIVE_SCAN)
            	   	configBaseStationForSelectiveScanRus(sock) ;
                else
                	configBaseStationForRus(sock);
            }
            break;

            case FXL_CDMA_LISTEN_MODE_CONFIGURE_BANDS_RSP:
            {
                fxLCdmaListenModeConfigureBandsRsp *rsp = (fxLCdmaListenModeConfigureBandsRsp*)server_reply;
                printf("TcpClient : Listen Mode Configure Bands Response received with result(%ld)\n",rsp->result);
                startBaseStationForRus(sock);
            }
            break;

            case FXL_CDMA_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP:
            {
            	fxLCdmaListenModeConfigureSelectiveFreqRsp *rsp = (fxLCdmaListenModeConfigureSelectiveFreqRsp*)server_reply;
                printf("TcpClient : Listen Mode Configure CDMA Selective Frequencies Response received with result(%ld)\n",rsp->result);
                startBaseStationForRus(sock);
            }
            break;

            case FXL_CDMA_LISTEN_MODE_STARTSTOP_SCAN_RSP:
            {
                fxLCdmaListenModeStartStopScanRsp *rsp= (fxLCdmaListenModeStartStopScanRsp*)server_reply;
                printf("TcpClient : Start Scan Command Response received with result(%ld)\n",rsp->result);
            }
            break;

            case FXL_CDMA_LISTEN_MODE_SYSTEM_INFO_IND:
            {
                fxLCdmaListenModeSystemInfoInd *ind = (fxLCdmaListenModeSystemInfoInd*)server_reply;

                printf("============================================================\n");
		        printf("      TcpClient : CDMA Listen Mode Sys Info Ind received\n");
		        printf("============================================================\n");

                printf("\n");
            }
            break;

            case FXL_CDMA_LISTEN_MODE_SCAN_COMP_IND:
            {
            	fxLCdmaListenModeScanCompleteInd *rsp= (fxLCdmaListenModeScanCompleteInd*)server_reply;
            	printf("TcpClient : Listen Mode scan Complete Indication received\n");
                printf("#########################################################\n");
                printf("\n");
                
                stopBaseStationForRus(sock);
            }
            break;

            default:
            {
                printf("TcpClient : Unknown message received msgType(%ld)\n", hdr->msgType);
            }
            break;
        }
    }
     
    return 0;
}
