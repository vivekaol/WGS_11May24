/*############################################################################
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
 ############################################################################ */

/*############################################################################
 * File Name   : rrcRcvMsg.c
 *
 * Description : This file provides main functionality of Radio Resource Control
 *               (RRC) stack for ImsiCatcher application.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 26/09/2014	        Ashutosh Samal              File Creation
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rrc.h"
#include "rrcProto.h"
#include "cmnDs.h"
#include "taskHndlr.h"
#include "msgQue.h"
#include "cmnPf.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rrc;

/* -----------------------------------------------------
 *                 Global Variables
 * -----------------------------------------------------*/
extern RrcUeControlBlock ueControlBlock;

/*
 * UMTS Config Control Block
 */
extern UmtsConfigControlBlock gUmtsConfig;

/*
 * Client File Descriptor for sending indication to external client
 */
extern int clientFd;

/*############################################################################
 * Method Name : rrcHandleRlcDataIndication
 *
 * Description : This procedure handles received message from RLC layer
 *
 * Parameters  : 
 *   pRrcId           RRC Id to distinguish between UL CCCH & UL DCCH message
 *   rbId             Radio Bearer Id
 *   pRrcPdu          RRC PDU   
 *
 * Returns     : 
 *   RRC_SUCCESS      Success Case
 *   RRC_FAILURE      Failure Case
 ############################################################################*/
int rrcHandleRlcDataIndication (RrcDataReq *pRlcDataInd)
{
    int retCode = RRC_SUCCESS;

    DEBUGMSG(("Logical Channel Type(%ld)\n", pRlcDataInd->logicalChType));

    switch (pRlcDataInd->logicalChType)
    {
        case LOG_CH_CCCH_E:
           DEBUGMSG(("UL CCCH Message received from RLC Layer \n"));
           retCode = rrcHandleULCCCHMessage (pRlcDataInd);
           break;

        case LOG_CH_DCCH_E:
           DEBUGMSG(("UL DCCH Message received from RLC Layer \n"));
           retCode = rrcHandleULDCCHMessage (pRlcDataInd);
           break;

        default:
           DEBUG2(("RRC : Unknown Logical Channel Type received from RLC Layer \n"));
           retCode = RRC_FAILURE;
           break;
    }

    /* Free RRC PDU */
    free (pRlcDataInd->rrcPdu);
    free (pRlcDataInd);

    return (retCode);
}

/*############################################################################
 * Method Name : rrcHandleULDCCHMessage
 *
 * Description : This procedure handles received UL DCCH message from RLC layer
 *
 * Parameters  : 
 *   pRlcDataInd      RLC Data Indication   
 *
 * Returns     : 
 *   RRC_SUCCESS      Success Case
 *   RRC_FAILURE      Failure Case
 ############################################################################*/
int rrcHandleULDCCHMessage (RrcDataReq *pRlcDataInd)
{
    int retCode = RRC_SUCCESS;
    unsigned int idx = 0;
    unsigned char identityRespRecvd = 0;
    unsigned int emergencyCall = 0;        

    /* Get UE Index */
    unsigned int ueIndex = pRlcDataInd->cellOrUeId.u.ueId;

    RrcUlDCCHData *pUlDcch = &ueControlBlock.ueSpecificData[ueIndex].ulDcchData;

    /* Initialize ASN Context */
//    if(ASN_SUCCESS == initializeASNContext ())
    if(ASN_SUCCESS == initializeASNContextWithInputFile ("UL_DCCH.txt"))
    {
        if(ASN_SUCCESS == decodeASNULDCCHMessage (pRlcDataInd->rrcPdu,
                                                  pRlcDataInd->rrcPduLen,
                                                  pUlDcch,
                                                  &emergencyCall))
        {
            /* Clean ASN Context */
            //cleanASNContext ();
            cleanASNContextWithInputFile();

            switch (pUlDcch->msgType)
            {
                case UL_DCCH_MSG_TYPE_RRC_CONN_SETUP_COMP:
                   DEBUGMSG(("RRC Connection Setup Complete received from UE Id(%ld)\n", 
                          ueIndex)); 
                   DEBUGMSG(("Network Assisted GPS Value(%ld)\n", pUlDcch->ueBasedGpsEnabled));

                   /* copy gps supported type */
                   ueControlBlock.ueSpecificData[ueIndex].networkAssistedGpsSupport = pUlDcch->ueBasedGpsEnabled;
                   
                   /* copy UMTS Supported Bands */
                   ueControlBlock.ueSpecificData[ueIndex].numberOfBandSupported = pUlDcch->numberOfBandSupported;
                   for(idx = 0; idx < pUlDcch->numberOfBandSupported; idx++)
                   {
                      ueControlBlock.ueSpecificData[ueIndex].supportedBand[idx] = pUlDcch->supportedBand[idx];
                   }

                   /* Handle RRC Connection Setup Complete */
                   handleUeEvents (ueIndex, UE_RRC_CON_SETUP_COMP_RCVD);
                   break;

                case UL_DCCH_MSG_TYPE_RRC_CONN_REL_COMP:
                   DEBUGMSG(("RRC Connection Release Complete received from UE Id(%ld)\n", 
                          ueIndex));

                   /* Handle RRC Connection Release Complete */
                   handleUeEvents (ueIndex, UE_RRC_CON_REL_COMP_RCVD);
                   break;

                case UL_DCCH_MSG_TYPE_IDT:
                   DEBUGMSG(("Initial Direct Transfer Message received from UE Id(%ld)\n", 
                          ueIndex));
#ifdef FXL_BL_UE_POWER_OFF
                   /* Checking for IMSI detach and GMM Detach request */
                   if((pUlDcch->pNasMsg != NULL)&&
                      (pUlDcch->nasMsgLen != 0))
                   {
                     if (((pUlDcch->pNasMsg[1] == 0x05) &&
                          ((pUlDcch->pNasMsg[2] & 0x08) == 0x08) &&
                          (ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend == 0)) ||
                         (((pUlDcch->pNasMsg[0] & 0x0F) == 0x05) &&
                          ((pUlDcch->pNasMsg[1] & 0x0F) == 0x01) &&
                          (ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend == 0)))
                    {
                         ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend = 1;
                         sendBlUePowerOffInd(ueIndex);
                    }
                  }
#endif

                   if(emergencyCall == 1)
                   {
                       sendEmergencyCallInd(ueIndex);
                       /*Check Emergency call reject flag */
                       if(gUmtsConfig.enableEmergencyCallRejection)
                       {
                           buildAndSendRrcConnectionReleaseForEmergencyCall(ueIndex); 
                       }
                       else
                       {
                           /* Handle IDT Message */
                           handleUeEvents (ueIndex, UE_IDT_RCVD);
                       }
                   }
                   else
                   {
                      /* Handle IDT Message */
                      handleUeEvents (ueIndex, UE_IDT_RCVD);
                   }
                   break;

                case UL_DCCH_MSG_TYPE_PHY_CH_RECONF_COMP:
                   DEBUGMSG(("Physical Channel Reconfigure Complete received from UE Id(%ld)\n", 
                          ueIndex));
                   handleUeEvents (ueIndex, UE_RRC_PHY_CH_RECONF_COMP_RCVD);
                   break;

                case UL_DCCH_MSG_TYPE_PHY_CH_RECONF_FAIL:
                   DEBUGMSG(("Physical Channel Reconfigure Failure received from UE Id(%ld)\n", 
                          ueIndex));
                   handleUeEvents (ueIndex, UE_RRC_PHY_CH_RECONF_FAIL_RCVD);
                   break;

                case UL_DCCH_MSG_TYPE_MEAS_CONTROL_FAILURE:
                   DEBUGMSG(("Measurement Control Failure received from UE Id(%ld)\n", 
                          ueIndex));
                   handleUeEvents (ueIndex, UE_RRC_GPS_MEAS_CNTRL_FAILURE);
                   break;

                case UL_DCCH_MSG_TYPE_MEAS_CONTROL_REPORT:
                   DEBUGMSG(("Measurement Control Report received from UE Id(%ld)\n", 
                          ueIndex));
                   handleUeEvents (ueIndex, UE_RRC_GPS_MEAS_CNTRL_REPORT);
                   break;

                case UL_DCCH_MSG_TYPE_UL_DIRECT_TRANSFER:
                {
                   DEBUGMSG(("UL Direct Transfer received from UE Id(%ld)\n", 
                          ueIndex));

#ifdef FXL_BL_UE_POWER_OFF
                   /* Checking for IMSI detach and GMM Detach request */
                   if((pUlDcch->pNasMsg != NULL)&&
                      (pUlDcch->nasMsgLen != 0))
                   {
                       if (((pUlDcch->pNasMsg[1] == 0x05) &&
                            ((pUlDcch->pNasMsg[2] & 0x08) == 0x08) &&
                            (ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend == 0)) ||
                           (((pUlDcch->pNasMsg[0] & 0x0F) == 0x05) &&
                            ((pUlDcch->pNasMsg[1] & 0x0F) == 0x01) &&
                            (ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend == 0)))
                       {
                             ueControlBlock.ueSpecificData[ueIndex].powerOffIndSend = 1;
                             sendBlUePowerOffInd(ueIndex);
                       }
                   }
#endif
		   switch (pUlDcch->cnDomainType)
                   {
                       case CN_DOMAIN_IDENTITY_CS:
                          if (((pUlDcch->pNasMsg[0] & 0x0F) == 0x05) && 
                              ((pUlDcch->pNasMsg[1] & 0x1F) == 0x19) &&
                              (UE_WAIT_FOR_IDENTITY_RESP == ueControlBlock.ueSpecificData[ueIndex].ueState)) 
                          {
                              DEBUGMSG(("Identity Response received for CS Domain from UE Id(%ld)\n",
                                     ueIndex));
                              identityRespRecvd = 1;
                          }
                          else
                          {
                              DEBUGMSG(("UL Direct Transfer other than Identity Response is not handled\n"));
                          }
                          break;

                       case CN_DOMAIN_IDENTITY_PS:
                          if (((pUlDcch->pNasMsg[0] & 0x0F) == 0x08) && 
                              ((pUlDcch->pNasMsg[1] & 0x1F) == 0x16) &&
                              (UE_WAIT_FOR_IDENTITY_RESP == ueControlBlock.ueSpecificData[ueIndex].ueState)) 
                          {
                              DEBUGMSG(("Identity Response received for PS Domain from UE Id(%ld)\n", 
                                     ueIndex));
                              identityRespRecvd = 1;
                          }
                          else
                          {
                              DEBUGMSG(("UL Direct Transfer other than Identity Response is not handled\n"));
                          }
                          break;
 
                       default:
                          /* Free the memory allocated for NAS Message */
                          if (NULL != pUlDcch->pNasMsg)
                          {
                              free (pUlDcch->pNasMsg);
                              pUlDcch->pNasMsg = NULL;
                          } 

                          DEBUG2(("Wrong Domain Type received in UL DT Message from UE Id(%ld)\n", 
                                 ueIndex));
                          break;
                   }

                   if (1 == identityRespRecvd)
                   {
                       /* Handle Identity Response Message */
                       handleUeEvents (ueIndex, UE_IDENTITY_RESP_RCVD);
                   }
                }
                break;

                default:
                   DEBUG2(("Unsupported UL DCCH Message(%ld) received from UE Id(%ld)\n",
                          pUlDcch->msgType, ueIndex));
                   break;
            }
        }
        else
        {
            /* Clean ASN Context */
            //cleanASNContext ();
            cleanASNContextWithInputFile();

            DEBUG1(("Decoding of UL DCCH Message failed\n"));
            retCode = RRC_FAILURE;
        }   
    }
    else
    {
       DEBUG1(("ASN context initialization failed for UL DCCH Message\n"));
       retCode = RRC_FAILURE;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : rrcHandleULCCCHMessage
 *
 * Description : This procedure handles received UL CCCH message from RLC layer
 *
 * Parameters  : 
 *   pRlcDataInd      RLC Data Indication   
 *
 * Returns     : 
 *   RRC_SUCCESS      Success Case
 *   RRC_FAILURE      Failure Case
 ############################################################################*/
int rrcHandleULCCCHMessage (RrcDataReq *pRlcDataInd)
{
    int retCode          = RRC_SUCCESS;
    int ulCcchMsgType    = UL_CCCH_MSG_TYPE_NONE;
    unsigned int ueIndex = 0;
    RrcInitialUEIdentity initialUeIdentity;
    unsigned int emergencyCall = 0;        

    memset ((RrcInitialUEIdentity *)&initialUeIdentity, 0, sizeof(RrcInitialUEIdentity));

    /* Initialize ASN Context */
    if(ASN_SUCCESS == initializeASNContext ())
    {
        /* Decode UL CCCH Message */
        if(ASN_SUCCESS == decodeASNULCCCHMessage (pRlcDataInd->rrcPdu, 
                                                  pRlcDataInd->rrcPduLen, 
                                                  &ulCcchMsgType,
                                                  &initialUeIdentity,
                                                  &emergencyCall))
        {
            /* Clean ASN Context */
            cleanASNContext ();

            if(UL_CCCH_MSG_TYPE_RRC_CONNECTION_REQ == ulCcchMsgType)
            {
            	if(emergencyCall == 1)
            	{                
                    unsigned int idx = 0;
                    fxL3gEmergencyCallAttemptedInd emeCallAttemptedInd;
 
                    emeCallAttemptedInd.hdr.msgLength = sizeof(fxL3gEmergencyCallAttemptedInd);
                    emeCallAttemptedInd.hdr.msgType   = FXL_3G_EMERGENCY_CALL_ATTEMPTED_IND;
                    emeCallAttemptedInd.hdr.rat       = FXL_RAT_3G;                                      

                    emeCallAttemptedInd.initialIdentityType = initialUeIdentity.initialUEIdentityType;

                    if(initialUeIdentity.initialUEIdentityType == UE_IDENTITY_IMSI)
                    {
                        for (idx = 0; idx < initialUeIdentity.imsiLength; idx++)
                        {
                           emeCallAttemptedInd.u.imsiStr[idx] = initialUeIdentity.imsi[idx] + '0';
                        }
                        emeCallAttemptedInd.u.imsiStr[initialUeIdentity.imsiLength] = '\0';
                    }
                    else if(initialUeIdentity.initialUEIdentityType == UE_IDENTITY_IMEI)
                    {
                        unsigned int lastDigit       = 0;
                        unsigned int imeiCount       = 0;
			unsigned int sumOfOddDigits  = 0;
		        unsigned int sumOfEvenDigits = 0;

                        for (idx = 0; idx < initialUeIdentity.imeiLength; idx++)
                        {
                           emeCallAttemptedInd.u.imeiStr[idx] = initialUeIdentity.imei[idx] + '0';
                        }

                        /* Calculate Sum of Digits at Odd index */
                        for (imeiCount = 1; imeiCount < initialUeIdentity.imeiLength;
                             imeiCount = imeiCount + 2)
                        {
                            if (((initialUeIdentity.imei[imeiCount]) * 2) >= 10)
                            {
                                sumOfOddDigits = sumOfOddDigits +
                                                 ((((initialUeIdentity.imei[imeiCount]) * 2) % 10) + 1);
                            }
                            else
                            {
                                sumOfOddDigits = sumOfOddDigits +
                                     ((initialUeIdentity.imei[imeiCount]) * 2);
                            }
                        }

                        /* Calculate Sum of Digits at Even index */
                        for (imeiCount = 0; imeiCount < initialUeIdentity.imeiLength;
                             imeiCount = imeiCount + 2)
                        {
                            sumOfEvenDigits = sumOfEvenDigits + (initialUeIdentity.imei[imeiCount]);
                        }

                        if (0 == ((sumOfOddDigits + sumOfEvenDigits) % 10))
			{
                            lastDigit = 0;
                        }
                        else
                        {
                            lastDigit = 10 - ((sumOfOddDigits + sumOfEvenDigits) % 10);
                        }

                        /* Store the last digit of IMEI */
                        emeCallAttemptedInd.u.imeiStr[initialUeIdentity.imeiLength - 1] = lastDigit + '0';

                        emeCallAttemptedInd.u.imeiStr[initialUeIdentity.imeiLength] = '\0';
                    }
                    else if(initialUeIdentity.initialUEIdentityType == UE_IDENTITY_TMSI_AND_LAI)
                    {
                        /* Fill TMSI */
			for (idx = 0; idx < SIZE_OF_TMSI_IDENTITY; idx++)
    			{
			    emeCallAttemptedInd.u.tmsi[idx] =  initialUeIdentity.tmsi[idx];
    			}
                    }
                    else if(initialUeIdentity.initialUEIdentityType == UE_IDENTITY_PTMSI_AND_RAI)
                    {
                        /* Fill PTMSI */
                        for (idx = 0; idx < SIZE_OF_TMSI_IDENTITY; idx++)
                        {
                            emeCallAttemptedInd.u.ptmsi[idx] =  initialUeIdentity.ptmsi[idx];
                        }
                    }                   
                    else
                    {
                        emeCallAttemptedInd.initialIdentityType = 4;
                    } 
                    
                    if (-1 != clientFd)
    		    {
     		        if (send(clientFd, &emeCallAttemptedInd, sizeof(emeCallAttemptedInd), 0) < 0)
		        {
            		    DEBUG1(("Unable to send Emergency Call Attempted Message to External Client\n"));
        	        }
	                else
                        {
	                    DEBUGMSG(("Emergency Call Attempted Indication is sent to External Client\n"));
                        }
                    }
                    else
                    {
                        DEBUG1(("Unable to send message to External Client, clientFd = -1\n"));
                    }

                    /*Check Emergency call reject flag */
                    if(gUmtsConfig.enableEmergencyCallRejection)
                    {
                          RrcConnectionRejectData rrcConnRejData;
                          memset ((RrcConnectionRejectData *)&rrcConnRejData, 0, sizeof(RrcConnectionRejectData));

                          /* copy Initial UE identity */
                          memcpy((RrcInitialUEIdentity *)&rrcConnRejData.ueInitialIdentity,
                                  (RrcInitialUEIdentity *)&initialUeIdentity,
                                   sizeof(RrcInitialUEIdentity));

                         /* Fill Redirection info */
                	 if (FXL_UMTS_REDIRECTION_TO_2G == gUmtsConfig.emergencyCallRedirectionType)
	                 {
        	              rrcConnRejData.redirectionType  = REDIRECTION_INFO_INTER_RAT;
        	         }
	                 else if (FXL_UMTS_REDIRECTION_TO_3G == gUmtsConfig.emergencyCallRedirectionType)
        	         {
                	      rrcConnRejData.redirectionType = REDIRECTION_INFO_INTER_FREQUENCY;
	                      rrcConnRejData.dlUarfcn        = gUmtsConfig.emergencyCallRedirectionInfo.dlUarfcn;
        	         }
                         else
                         {
                              rrcConnRejData.redirectionType = 2;
                         }

                         buildAndSendRrcConnectionReject(rrcConnRejData);
                         /* Check the BL UE index from Initial UE Identity */
                         ueIndex = findUeIndexInUeControlBlock(&initialUeIdentity);

                         if(0xFFFF != ueIndex)
	                 {
         	            ueControlBlock.ueSpecificData[ueIndex].emergencyCallAttempted = 1;
                    	 }
                         return (retCode);
                    }
            	}

                if ((initialUeIdentity.initialUEIdentityType == UE_IDENTITY_IMSI) ||
                    (initialUeIdentity.initialUEIdentityType == UE_IDENTITY_IMEI) ||
                    (initialUeIdentity.initialUEIdentityType == UE_IDENTITY_TMSI_AND_LAI) ||
                    (initialUeIdentity.initialUEIdentityType == UE_IDENTITY_PTMSI_AND_RAI))
                {
                    /* Get UE index from Initial UE Identity */
                    ueIndex = getUeIndexInUeControlBlock (&initialUeIdentity);
                    DEBUGMSG(("RRC Connection Request received from UE Id(%ld)\n", 
                            ueIndex));

                    if(0xFFFF != ueIndex)
                    {
                        ueControlBlock.ueSpecificData[ueIndex].propagationDelay = pRlcDataInd->propDelay;
         	        ueControlBlock.ueSpecificData[ueIndex].emergencyCallAttempted = 0;
                        ueControlBlock.ueSpecificData[ueIndex].ueAccessSpectrumReleaseIndicator = initialUeIdentity.ueRelease;
                    	/* Handle the RRC_CON_REQ received from UE */
                    	handleUeEvents (ueIndex, UE_RRC_CON_REQ);
                    }
					else
					{
					    DEBUGMSG(("RRC Connection Request dropped due to Maximum Number of UE Supported = %d\n", 
                                  MAX_UE_SUPPORTED));
					}
                }
                else
                {
                    DEBUG3(("Discarding RRC Connection Request\n"));
                    DEBUG3(("Initial Identity Type(%ld) is not supported\n",
                           initialUeIdentity.initialUEIdentityType));
                }
            }
            else if (UL_CCCH_MSG_TYPE_CELL_UPDATE == ulCcchMsgType)
            {
                DEBUG3(("Discarding UL CCCH Cell Update Message\n"));
            }
            else if (UL_CCCH_MSG_TYPE_URA_UPDATE == ulCcchMsgType)
            {
                DEBUG3(("Discarding UL CCCH URA Update Message\n"));
            }
            else
            {
                DEBUG3(("Discarding UL CCCH Message Type(%ld)\n", ulCcchMsgType));
            }
        }
        else
        {
           /* Clean ASN Context */
           cleanASNContext ();

           DEBUG1(("Decoding of UL CCCH Message failed\n"));
           retCode = RRC_FAILURE;
        }
    }
    else
    {
       DEBUG1(("ASN context initialization failed for UL DCCH Message\n"));
       retCode = RRC_FAILURE;
    }

    return (retCode);
}
