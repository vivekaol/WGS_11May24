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


typedef struct ThreadArgs 
{
    char imsi[SIZE_OF_IDENTITY_STR];
    int sock;
}threadArgs;


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

void loadGsmBassDspImage(int sock)
{
    fxLBootL1Cmd *cmd = (fxLBootL1Cmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxLBootL1Cmd);
    cmd->hdr.msgType = FXL_BOOT_L1_CMD;
    cmd->hdr.rat = FXL_RAT_2G;

    if(dspInUse == PRIMARY)
      cmd->dspType = FXL_PRIMARY_DSP;
    else
      cmd->dspType = FXL_SECONDARY_DSP;

    cmd->l1ImageType = FXL_L1_BASS_IMAGE;

    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxLBootL1Cmd) , 0) < 0)
    {
    	printf("TcpClient : Sending Boot L1 Command for Bass failed\n");
    }
    else
    {
    	printf("TcpClient : Boot L1 Command for Bass sent....\n");
    }
}

void configBaseStationForBass(int sock)
{
    fxL2gBassModeConfigureBandsCmd *cmd = (fxL2gBassModeConfigureBandsCmd*)sendMsgBuf;
    cmd->noOfBandsToScan = 1;
    cmd->band[0] = FXL_BAND_E_GSM;
    cmd->band[1] = FXL_BAND_DCS_1800;

    cmd->hdr.msgLength = sizeof(fxL2gBassModeConfigureBandsCmd);
    cmd->hdr.msgType = FXL_2G_BASS_MODE_CONFIGURE_BANDS_CMD;
    cmd->hdr.rat = FXL_RAT_2G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL2gBassModeConfigureBandsCmd) , 0) < 0)
    {
        printf("TcpClient : 2G Bass Mode Configure Bands send message failed\n");
    }
    else
    {
        printf("TcpClient : 2G Bass Mode Configure Bands sent....\n");
    }
}

void startBaseStationForBass(int sock)
{
    fxL2gBassModeStartCmd *cmd = (fxL2gBassModeStartCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL2gBassModeStartCmd);
    cmd->hdr.msgType = FXL_2G_BASS_MODE_START_CMD;
    cmd->hdr.rat = FXL_RAT_2G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL2gBassModeStartCmd) , 0) < 0)
    {
        printf("TcpClient : 2G Bass Mode Start Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 2G Bass Mode Start Command sent....\n");
    }
}

void stopBaseStationForBass(int sock)
{
    fxL2gBassModeStopCmd *cmd = (fxL2gBassModeStopCmd *)sendMsgBuf;
    cmd->hdr.msgLength = sizeof(fxL2gBassModeStopCmd);
    cmd->hdr.msgType = FXL_2G_BASS_MODE_STOP_CMD;
    cmd->hdr.rat = FXL_RAT_2G;
    //Send some data
    if( send(sock , sendMsgBuf , sizeof(fxL2gBassModeStopCmd) , 0) < 0)
    {
        printf("TcpClient : 2G Bass Mode Stop Command send message failed\n");
    }
    else
    {
        printf("TcpClient : 2G Bass Mode Stop Command sent....\n");
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
                loadGsmBassDspImage(sock);
            }
            break;

            case FXL_BOOT_L1_RSP:
            {
                fxLBootL1Rsp *rsp = (fxLBootL1Rsp*)server_reply;
                printf("TcpClient : Boot L1 Response received with result(%ld)\n",rsp->result);
                configBaseStationForBass(sock);
            }
            break;

            case FXL_2G_BASS_MODE_CONFIGURE_BANDS_RSP:
            {
                fxL2gBassModeConfigureBandsRsp *rsp = (fxL2gBassModeConfigureBandsRsp*)server_reply;
                printf("TcpClient : Bass Mode Configure Bands Response received with result(%ld)\n",rsp->result);
                startBaseStationForBass(sock);
            }
            break;

            case FXL_2G_BASS_MODE_START_RSP:
            {
                fxL2gBassModeStartRsp *rsp= (fxL2gBassModeStartRsp*)server_reply;
                printf("TcpClient : Start Bass Command Response received with result(%ld)\n",rsp->result);
            }
            break;

            case FXL_2G_BASS_MODE_SYNC_CELL_INFO_IND:
            {
                fxL2gBassModeSyncCellInfoInd *ind = (fxL2gBassModeSyncCellInfoInd*)server_reply;

                printf("============================================================\n");
		        printf("      TcpClient : 2G Bass Mode Sync Info Ind received\n");
		        printf("============================================================\n");
		        printf("ARFCN\t\t\t\t\t\t:\t%ld\n", ind->arfcn);
		        printf("Band\t\t\t\t\t\t:\t%ld\n", ind->band);
		        printf("SNR\t\t\t\t\t\t:\t%f\n", ind->snr);
            }
            break;

            case FXL_2G_BASS_MODE_COMPLETE_IND:
            {
            	fxL2gBassModeCompleteInd *rsp= (fxL2gBassModeCompleteInd*)server_reply;
            	printf("TcpClient : Bass Mode scan Complete Indication received\n");
                printf("#########################################################\n");
                printf("\n");
                
                stopBaseStationForBass(sock);
            }
            break;

            case FXL_2G_BASS_MODE_STOP_RSP:
            {
                fxL2gBassModeStopRsp *rsp= (fxL2gBassModeStopRsp*)server_reply;
                printf("TcpClient : 2G Bass Mode Stop Response received with result(%ld)\n",rsp->result);
               	exit(1);
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
