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
* File Name   : gprsRlcMacEncDec.c
*
* Description : Functions to decode/encode RLC/MAC headers and messages
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/

#include "gprs.h"
#include "l1Constants.h"
#include "linkedlist.h"
#include <pthread.h>
#include <arpa/inet.h>
#include <assert.h>
#include "logManager.h"
#include "gsmCommon.h"

#ifdef FEA_GPRS

#define PAYLOAD_TYPE_OCTET  0                       // Val: ((a[PAYLOAD_TYPE_OCTET ] & 0xC0) >> 6)
#define USF_OCTET           PAYLOAD_TYPE_OCTET      // Val: ((a[PAYLOAD_TYPE_OCTET ] & 0x07)) >> 6)
#define FBI_OCTET           PAYLOAD_TYPE_OCTET+1    // Val: (a[FBI_OCTET] & 0x01)
#define BSN_OCTET           PAYLOAD_TYPE_OCTET+2

const tOCT_UINT8 const uplinkAckNack[GPRS_MACBLOCK_LEN] =
{
    0x40, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

/*const tOCT_UINT8 const pktDownlinkAssign_WO_TLLI[GPRS_MACBLOCK_LEN] =
{
    0x48, 0x08, 0x40, 0x00, 0x04, 0x02, 0x00, 0x02, 0x08, 0x00,
    0x00, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};*/
const tOCT_UINT8 const pktDownlinkAssign[GPRS_MACBLOCK_LEN] =
{
    0x4F, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x40,
    //0x2C, 0x41, 0x00, 0x20, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x00, 0x41, 0x00, 0x20, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

const tOCT_UINT8 const downlinkDataBlock[GPRS_MACBLOCK_LEN] =
{
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

const tOCT_UINT8 const pktControlAck[GPRS_MACBLOCK_LEN] =
{
    0x40, 0x04, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};
extern signed int usf[8];
extern gsm_trx * trx_g;
extern tOCT_UINT8 usf_frame_tmp[GSM_MACBLOCK_LEN];
extern tOCT_UINT8 controlMsg;
extern tOCT_UINT8 proc4Pua;
extern tOCT_UINT32 pcaRcvd;
extern rts_time * rts_time_gprs;

extern void clearGprsContext(gprsInfo* info);
extern void pushGprsReqToTxDataQ(gprsInfo* info , const tOCT_UINT8 * const stdMsgBuf);
tOCT_UINT8* encodeRlcMacPdu(gprsInfo *info, tOCT_UINT8 msg);

void decodeRlcMacPdu(tOCT_UINT8* rlcPdu , gprsInfo* info)
{
	logPrint(LOG_DEBUG,"User : %p :RLC: __cv",info);
	tOCT_UINT8 ebo = 0, isTlli = 1;
	if( (rlcPdu[PAYLOAD_TYPE_OCTET] >> 6) == UL_RLC_DATA_BLOCK)
	{
		logPrint(LOG_DEBUG,"User = %p : Rcvd DATA_BLOCK",info);
		if((info->bufIndex != 0) && (((rlcPdu[CV_OCTET] & 0x3C) >> 2) > info->cv))
		{
				//DISCARD THE MESSAGE || //Send Uplink_ACK/NACK without processing
				return;
		}
		logPrint(LOG_INFO,"User = %p : CV at this point: %d rcvd",info,info->cv);
		if(info->cv == 0xFF)
		{
			//First Message .. Alloc LLCbuf
			info->cv = ((rlcPdu[CV_OCTET] & 0x3C) >> 2);
			info->llcBuf = getGprsDataIndBuffer();		//+2 for tfi and USF
		}
		info->cv = ((rlcPdu[CV_OCTET] & 0x3C) >> 2);
		info->ssn++;
		if((rlcPdu[TI_OCTET]  & 0x01))
		{
			if((rlcPdu[EXT_BIT_OCTET]  & 0x01))
			{
				ebo = 1;
				memcpy(info->userTlli,&rlcPdu[EXT_BIT_OCTET+1],4*sizeof(tOCT_UINT8));
			}
			else if((rlcPdu[MORE_EXT_OCTET]  & 0x01))
			{
				info->morePdu = ((rlcPdu[MORE_EXT_OCTET] & 0x02) >> 1);
				//logPrint(LOG_INFO,"User = %p :rlcPdu[MORE_EXT_OCTET] 0x_%x morePdu %d",info, rlcPdu[MORE_EXT_OCTET],info->morePdu);
				memcpy(info->userTlli,&rlcPdu[MORE_EXT_OCTET+1],4*sizeof(tOCT_UINT8));
			}
			logPrint(LOG_INFO,"User = %p : TLLI: 0x%02x%02x%02x%02x",info, info->userTlli[0],info->userTlli[1],info->userTlli[2],info->userTlli[3]);
		}
		else
		{
			isTlli = 0;
			logPrint(LOG_INFO,"User = %p : TLLI: Absent",info);
			if((rlcPdu[EXT_BIT_OCTET]  & 0x01))
			{
				ebo = 1;
				//memcpy(info->userTlli,&rlcPdu[EXT_BIT_OCTET+1],4*sizeof(tOCT_UINT8));
			}
			else if((rlcPdu[MORE_EXT_OCTET]  & 0x01))
			{
				info->morePdu = ((rlcPdu[MORE_EXT_OCTET] & 0x02) >> 1);
				//logPrint(LOG_INFO,"User = %p :rlcPdu[MORE_EXT_OCTET] 0x_%x morePdu %d",info, rlcPdu[MORE_EXT_OCTET],info->morePdu);
				//memcpy(info->userTlli,&rlcPdu[MORE_EXT_OCTET+1],4*sizeof(tOCT_UINT8));
			}
			//logPrint(LOG_INFO,"User = %p : TLLI: 0x%02x%02x%02x%02x",info, info->userTlli[0],info->userTlli[1],info->userTlli[2],info->userTlli[3]);
		}


		logPrint(LOG_INFO,"User = %p : CV: %d rcvd",info,info->cv);
		if(ebo)
		{
		    logPrint(LOG_DEBUG,"User : %p bufIndx %d: 0x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x",
    											info,info->bufIndex, rlcPdu[0],rlcPdu[1],rlcPdu[2],rlcPdu[3],rlcPdu[4],rlcPdu[5],rlcPdu[6],rlcPdu[7],
    											rlcPdu[8],rlcPdu[9],rlcPdu[10],rlcPdu[11],rlcPdu[12],rlcPdu[13],rlcPdu[14],rlcPdu[15],rlcPdu[16]);
			if(info->bufIndex == 0)
			{
				//info->llcBuf[info->bufIndex++] = info->tfi;
				//info->llcBuf[info->bufIndex++] = info->usf;
			}
			if(isTlli)
				memcpy(&info->llcBuf[info->bufIndex],&rlcPdu[EXT_BIT_OCTET+4+1],GSM_MACBLOCK_LEN - 7);
			else
				memcpy(&info->llcBuf[info->bufIndex],&rlcPdu[EXT_BIT_OCTET+1],GSM_MACBLOCK_LEN - 7);
			info->bufIndex += GSM_MACBLOCK_LEN - 7;
		}
		else
		{
			if(info->bufIndex == 0)
			{
				//info->llcBuf[info->bufIndex++] = info->tfi;
				//info->llcBuf[info->bufIndex++] = info->usf;
			}

			if(isTlli)
				memcpy(&info->llcBuf[info->bufIndex],&rlcPdu[MORE_EXT_OCTET+4+1],GSM_MACBLOCK_LEN - 8);
			else
				memcpy(&info->llcBuf[info->bufIndex],&rlcPdu[MORE_EXT_OCTET+1],GSM_MACBLOCK_LEN - 7);
			info->bufIndex += GSM_MACBLOCK_LEN - 8;
		}
			
	//	logPrint(LOG_DEBUG,"info->llcBuf bufIndx %d: 0x_%x_%x_%x_%x_%x_%x_%x_%x",
    //                      info->bufIndex, info->llcBuf[0],info->llcBuf[1],info->llcBuf[2],info->llcBuf[3],info->llcBuf[4],info->llcBuf[5],info->llcBuf[6],info->llcBuf[7]);

	}	//Data_Block
	else if( (rlcPdu[PAYLOAD_TYPE_OCTET] >> 6) == UL_RLC_MAC_MESSAGE)
	{
		logPrint(LOG_INFO,"User = %p : ControlMsg rcvd",info);
		controlMsg = 2;		//Reset
		proc4Pua = 0;
		if(info->userPrevState == GPRS_L3_REJECT_FOR_UE)
    	clearGprsContext(info);
		//sendMsg = encodeRlcMacPdu(info, PKT_CONTROL_ACK);
		//pushGprsReqToTxDataQ(info , sendMsg);
	  //if( ((rlcPdu[3] & 0x0F) == 0x05) && ((rlcPdu[4] & 0x3F) == 0x08)) // SABM
	}	//Message

	else
		logPrint(LOG_INFO,"!DATA_BLOCK !MESSAGE !!!!");
}



/*	Prepare the downlink Control/Data Message
 *	
 *	Function Name : constructSendMsg(gprsInfo *info, tOCT_UINT8 msg)
 *
 *	Prepare the downlink Control/Data Message
 *	
 *	For data block : Prepares the RLC/MAC header & info and memcpy the LLC instructed
 *	For Messages	 : Prepared the whole message with RLC/MAC header & info
 *
 * */

tOCT_UINT8* encodeRlcMacPdu(gprsInfo *info, tOCT_UINT8 msg)
{
	signed char i,j;
	tOCT_UINT32 tlli=0;

	tOCT_UINT8* tmpGprsBuf = getGprsTxDataBuffer();
	bzero(tmpGprsBuf, GPRS_MACBLOCK_LEN);
	switch(msg)
	{
		case PKT_UPLINK_ACK_NACK:
		{
			memcpy(tmpGprsBuf, uplinkAckNack, GPRS_MACBLOCK_LEN);

			logPrint(LOG_DEBUG,"User = %p : Encode PKT_UPLINK_ACK_NACK 0x_%x",info,tmpGprsBuf[1]);

			//USF
				if(info->cv == 0)
				{
					tmpGprsBuf[0] |= (0x01 << 3);
					tmpGprsBuf[0] |= (info->altUsf & 0x07) ;
					usf_frame_tmp[0] |= (info->altUsf && 0x07) | 0x40;
					//logPrint(LOG_DEBUG,"PUA: Setting USF 0x%x",usf_frame_tmp[0]);
				}
				else
				tmpGprsBuf[0] |= (info->usf & 0x07) ;

			//TFI
				tmpGprsBuf[2] |= ((info->tfi << 1) & 0x3E);

			//FAI
				if(info->morePdu == 0)
				{
					logPrint(LOG_DEBUG,"User = %p : Set FAI = 1",info);
					tmpGprsBuf[3] |= (0x01 << 5);
				}
				else
					tmpGprsBuf[3] |= 0x00;

			//SSN
				tmpGprsBuf[3] |=  (info->ssn >> 2);
				tmpGprsBuf[4] |=  (info->ssn << 6);
				//ssn2Bit = (info->ssn << 6);

			//BitMap
				info->ack |= (0x01 << (info->ssn-1));

				for(i = 0 ,j = 4 ; i< 8; i++,j++)
				{
					tmpGprsBuf[j] |= (tOCT_UINT8)(info->ack >> (64-6-(i*8)));
				}
				tmpGprsBuf[12] |=  (tOCT_UINT8)(info->ack << 6);

			//ContentionResolutionTLLI
				tmpGprsBuf[12] |=  (tOCT_UINT8)(0x01 << 5);

				for(i = 3; i >= 0 ; i--)
				{
					tlli |= (tOCT_UINT32)(info->userTlli[i] << ((3-i)*8));
				}
				for(i = 0 ,j = 12 ; i< 4; i++,j++)
				{
					tmpGprsBuf[j] |= (tOCT_UINT8)(tlli >> (32-5-(i*8)));
				}
				tmpGprsBuf[16] |=  (tOCT_UINT8)(tlli << 5);
				tmpGprsBuf[23] = info->tfi;			// For handling in RTS

		}
		break;

		case PKT_DOWNLINK_ASSGN:
		{
			tOCT_UINT8 usfTmp = 0;
			tOCT_UINT16 arfcn;
			memcpy(tmpGprsBuf, pktDownlinkAssign, GPRS_MACBLOCK_LEN);

			//USF
			for(i = 7 ; i >= 0; i--)
			if(usf[i] == -1)
			{
				usf[i] = 0;
				usfTmp = i;
				break;
			}

			info->altUsf = usfTmp;

			//USF
			tmpGprsBuf[0] |= (usfTmp & 0x07) ;
			usf_frame_tmp[0] = (usfTmp & 0x07) | 0x40;
			//usf_frame_tmp[0] |= 0x07 | 0x40;
			//info->altUsf = 0x07;
			//usfTmp = info->altUsf;
			
			//TFI
			tmpGprsBuf[1] |= ((info->tfi << 1) & 0x3E);
			tmpGprsBuf[23] = info->tfi;			// For handling in RTS

			logPrint(LOG_DEBUG,"User = %p :Encode PKT_DOWNLINK_ASSGN USF = %d",info,usfTmp);
			for(i = 3; i >= 0 ; i--)
			{
				tlli |= (tOCT_UINT32)(info->userTlli[i] << ((3-i)*8));
			}
			for(i = 0 ,j = 2 ; i< 4; i++,j++)
			{
				tmpGprsBuf[j] |= (tOCT_UINT8)(tlli >> (32-5-(i*8)));
			}
				tmpGprsBuf[6] |=  (tOCT_UINT8)(tlli << 5);
				if(pcaRcvd)
				{
					//For CONTROL_ACK = 1, if PCA is already rcvd for earlier TBF
					tmpGprsBuf[6] |= 0x01; 		
					logPrint(LOG_DEBUG,"PCArcvd");
				}
			tmpGprsBuf[9] |=  (trx_g->bts.tsc << 3);
/*
48 0.......     P0/PR_MODE = 0 :Absent
   .1......     Frequency Parameter = 1 :Present
                 Frequency Parameters:
                  (3GPP TS44.060 12.8)
   ..001...       TSC = 1
   .....00.       Frequency Type = 0 :ARFCN
   .......0        ARFCN = 125
3E 00111110
C1 1.......
   .1......     Downlink TFI Assignment = 1 :Present
   ..00000.      DOWNLINK_TFI_ASSIGNMENT = 0
   .......1     Power Control Params = 1 :Present
*/
			//ARFCN
			arfcn = trx_g->arfcn;
			tmpGprsBuf[9] |= (tOCT_UINT8)((arfcn >> 9) & 0x01);
			tmpGprsBuf[10] |= (tOCT_UINT8)((arfcn & 0xFF) >> 1);
			tmpGprsBuf[11] |= (tOCT_UINT8)((arfcn & 0x01) << 7);

#if 0		//WIDOUT_TLLI
			//TimeSlot Number
			tmpGprsBuf[4] |= 0x10;	//TS 6 is hardcoded as of now
			//ARFCN
			arfcn = trx_g->arfcn;
			tmpGprsBuf[6] |= ((arfcn >> 6) & 0x0F);
			tmpGprsBuf[7] |= ((arfcn & 0x3F) << 2);

			//PowerControl Param	//TS 6 is hardcoded as of now
			tmpGprsBuf[9] |= 0x01;
			tmpGprsBuf[10] |= 0x00;
			tmpGprsBuf[11] |= 0x60;	//SpareBit
#endif
			logPrint(LOG_DEBUG,"User = %p :PKT_Dwnl_Assgn 0x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x",info,tmpGprsBuf[0],tmpGprsBuf[1],tmpGprsBuf[2],tmpGprsBuf[3],
																										tmpGprsBuf[4],tmpGprsBuf[5],tmpGprsBuf[6],tmpGprsBuf[7],tmpGprsBuf[8],tmpGprsBuf[9],tmpGprsBuf[10],
																										tmpGprsBuf[11],tmpGprsBuf[12]);
		}
		break;

		case PKT_DATA_BLOCK:
		{
			memcpy(tmpGprsBuf, downlinkDataBlock, GPRS_MACBLOCK_LEN);

			logPrint(LOG_DEBUG,"User = %p : Encode PKT_DATA_BLOCK ",info);

			//USF
			//tmpGprsBuf[USF_OCTET] |= (info->usf & 0x07) ;
			tmpGprsBuf[USF_OCTET] |= (info->altUsf & 0x07) ;
		
			//TFI
			tmpGprsBuf[FBI_OCTET] |= ((info->tfi << 1) & 0x3E);
			tmpGprsBuf[23] = info->tfi;			// For handling in RTS

			//FBI
			tmpGprsBuf[FBI_OCTET] |= (info->fbi & 0x01) ;

			if(info->tmpLlcBuf[0] >= 0x14)			//To Be taken care of while preparing LLCPDU in llcHandler.c
				{
					//BSN
					tmpGprsBuf[BSN_OCTET] |= ((info->bsn++ << 1) & 0xFE);

					//EXT_BIT
					tmpGprsBuf[BSN_OCTET] |= 0x01;				//There is no extension octet

					memcpy(&tmpGprsBuf[3], &info->tmpLlcBuf[1], info->tmpLlcBuf[0]);
				}
			else
				{
					//BSN
					tmpGprsBuf[BSN_OCTET] |= ((info->bsn++ << 1) & 0xFE);

					//EXT_BIT
					tmpGprsBuf[BSN_OCTET] |= 0x00;

					//LEN_IND(1)
					tmpGprsBuf[LEN_IND_OCTET] |= ((info->tmpLlcBuf[0] << 2) & 0xFC);

					//MORE_BIT(1)
					//tmpGprsBuf[LEN_IND_OCTET] |= ((0x01 << 1) & 0x02);		//New LLC PDU starts after current PDU

					tmpGprsBuf[LEN_IND_OCTET] |= 0x01;				//There is no ther extension octet

					//EXT_BIT(1)
					//tmpGprsBuf[LEN_IND_OCTET] |= 0x00;				//There is another extension octet
					
					//LEN_IND(2)
					//tmpGprsBuf[4] |= ( ((info->tmpLlcBuf[0] - (tmpGprsBuf[LEN_IND_OCTET] >> 2)) << 2) & 0xFC);				//There is another extension octet

					//MORE_BIT(2)
					//tmpGprsBuf[4] |= ((0x00 << 1) & 0x02);		//NO LLC PDU starts after current PDU

					//EXT_BIT(2)
					//tmpGprsBuf[4] |= 0x01;				//There is no extension octet


					//memcpy(&tmpGprsBuf[5], &info->tmpLlcBuf[1], info->tmpLlcBuf[0]);
					
					memcpy(&tmpGprsBuf[4], &info->tmpLlcBuf[1], info->tmpLlcBuf[0]);

				}
	
			info->userPrevState = info->userState;
			info->userState = GPRS_L3_REJECT_FOR_UE;
			//info->userAltState = WAIT_FOR_PKT_CNTRL_ACK;

			logPrint(LOG_DEBUG,"User = %p :PKT_DATA_BLOCK 0x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x",info,tmpGprsBuf[0],tmpGprsBuf[1],tmpGprsBuf[2],tmpGprsBuf[3],
																										tmpGprsBuf[4],tmpGprsBuf[5],tmpGprsBuf[6],tmpGprsBuf[7],tmpGprsBuf[8],tmpGprsBuf[9],tmpGprsBuf[10],
																										tmpGprsBuf[11],tmpGprsBuf[12]);
		}
		break;

		case PKT_CONTROL_ACK:
		{
			memcpy(tmpGprsBuf, pktControlAck, GPRS_MACBLOCK_LEN);

			logPrint(LOG_DEBUG,"User = %p : Encode PKT_CONTROL_ACK 0x_%x",info,tmpGprsBuf[1]);

				/*             Uplink RLC/MAC Control Message:
				40 01......   Payload Type = 1 :Uplink RLC/MAC Message
					 ..00000.    Spare bits = 00000b
					 .......0    Retry Bit = 0 :One Channel Request Msg
				05 000001..    Message Type = 1 :Packet Control Acknowledgement
												Packet Control Acknowledgement:
												 (3GPP TS44.060 11.2.2)
					 ......01      TLLI/G-RNTI = 7C42F3DDh
				F1 11110001
				0B 00001011
				CF 11001111
				77 011101..
					 ......11      CTRL_ACK = 3
				2B 0.......      Additions in Rel-5 = 0 :Absent
					 .0101011  Spare Bits = 0101011b
				*/
			for(i = 3; i >= 0 ; i--)
			{
				tlli |= (tOCT_UINT32)(info->userTlli[i] << ((3-i)*8));
			}
			for(i = 0 ,j = 1 ; i< 4; i++,j++)
			{
				tmpGprsBuf[j] |= (tOCT_UINT8)(tlli >> (32-2-(i*8)));
			}
			tmpGprsBuf[5] |=  (tOCT_UINT8)(tlli << 2);
			tmpGprsBuf[5] |=  0x03;
			tmpGprsBuf[23] = info->tfi;			// For handling in RTS

		}
		break;
	}//switch
	//logPrint(LOG_DEBUG,"tmpGprsBuf[1] = 0x_%x",tmpGprsBuf[1]);
	return tmpGprsBuf;
	
}

void updateGprsRtstime(rts_time *time, tOCT_UINT32 fn)
{
    if(time != NULL)
    {
        time->fn = fn;
        time->t1 = time->fn / (26*51);
        time->t2 = time->fn % 26;
        time->t3 = time->fn % 51;
        time->tc = (time->fn / 51) % 8;
    }
}



#endif // FEA_GPRS
