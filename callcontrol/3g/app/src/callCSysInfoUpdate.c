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
 * File Name   : callCSysInfoUpdate.c 
 *
 * Description : This is System Information Update file of ImsiCatcher 
 *               application. It fills & encodes all type of SIB Messages which
 *               will be sent on BCCH BCH Message. 
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 13/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
 */
#include "stdio.h"
#include "string.h"
#include "asnApi.h"
#include "errorCode.h"
#include "l1capi_datastruct.h"
#include "callCSysInfoUpdate.h"
#include "clSendL1Msg.h"
#include "umtsCfg.h"
#include "cmnDebug.h"
#include "callCDefaultParam.h"

static DbgModule_e  DBG_MODULE = app;

/* -----------------------------------------------------
 *                 Global Variables
 * -----------------------------------------------------
 */
extern UmtsConfigControlBlock  gUmtsConfig;

int     mibEncodedLength   = 0;
char    mibData[100]       = {0};

int     sib1EncodedLength  = 0;
char    sib1Data[100]      = {0};

int     sib2EncodedLength  = 0;
char    sib2Data[100]      = {0};

int     sib3EncodedLength  = 0;
char    sib3Data[100]      = {0};

int     sib5EncodedLength  = 0;
char    sib5Data[100]      = {0};
char    sib5DataSeg1[28]   = {0};
char    sib5DataSeg2[28]   = {0};
char    sib5DataSeg3[28]   = {0};
int     sib5Seg3Length     = 0;

int     sib7EncodedLength  = 0;
char    sib7Data[100]      = {0};

int     sib11EncodedLength = 0;
char    sib11Data[420]     = {0};
char    sib11DataSeg[MAX_SIB11_SEGS][28] = {{0,0}};
int     sib11DataSegLen[MAX_SIB11_SEGS]  = {0};
int     sib11SegCount      = 0;
int     sib11SegIdx        = 0;
int     configureSib5bis   = 0;

BcchBchData_t bcchInputData[MAX_SFN] =
{ 
  {0,  MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {1,  SYSTEM_INFORMATION_TYPE1,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {2,  SYSTEM_INFORMATION_TYPE2,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {3,  SYSTEM_INFORMATION_TYPE3,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {4,  MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {5,  SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_FIRST_SEGMENT,      3, 0, 0, NULL },
  {6,  SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_SUBSEQUENT_SEGMENT, 3, 1, 0, NULL },
  {7,  SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_LAST_SEGMENT_SHORT, 3, 2, 0, NULL },
  {8,  MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {9,  SYSTEM_INFORMATION_TYPE7,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {10, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {11, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {12, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {13, SYSTEM_INFORMATION_TYPE11, BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {14, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {15, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {16, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {17, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {18, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {19, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {20, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {21, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {22, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {23, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {24, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {25, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {26, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {27, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {28, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {29, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {30, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {31, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {32, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {33, SYSTEM_INFORMATION_TYPE1,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {34, SYSTEM_INFORMATION_TYPE2,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {35, SYSTEM_INFORMATION_TYPE3,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {36, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {37, SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_FIRST_SEGMENT,      3, 0, 0, NULL },
  {38, SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_SUBSEQUENT_SEGMENT, 3, 1, 0, NULL },
  {39, SYSTEM_INFORMATION_TYPE5,  BCH_PAYLOAD_LAST_SEGMENT_SHORT, 3, 2, 0, NULL },
  {40, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {41, SYSTEM_INFORMATION_TYPE7,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {42, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {43, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {44, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {45, SYSTEM_INFORMATION_TYPE11, BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {46, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {47, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {48, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {49, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {50, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {51, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {52, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {53, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {54, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {55, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {56, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {57, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {58, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {59, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {60, MASTER_INFORMATION_BLOCK,  BCH_PAYLOAD_COMPLETE_SIB,       1, 0, 0, NULL },
  {61, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {62, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL },
  {63, NONE,                      BCH_PAYLOAD_NO_SEGMENT,         1, 0, 0, NULL }
};

int buildAndSendL1SibMessage (void)
{
    L1CAPI_BCH_SIM_DATA  octL1BchSimData;
    int                  dataIndex       = 0;
    int                  sfnIndex        = 0;
    int                  bcchEncodedLen  = 0;
    char                 bcchEncodedBuf[SIM_SIZE] = {0};
    int                  retCode = ROK;

#if 0
    /* Initialize ASN Context */
    if (ASN_FAILURE == initializeASNContextWithInputFile ("RRC_SIB.txt"))
#else
    /* Initialize ASN Context */
    if (ASN_FAILURE == initializeASNContext ())
#endif
    {
        DEBUG1(("Initializing ASN Context failed \n"))
        return (RFAILED);
    }

#ifdef FXL_3G_TX_JAMMER
    if(TRUE != gUmtsConfig.txJammerEnabled)
    {
#endif
    	/* Fill & Encode all types of SIB messages */
    	if (RFAILED == fillAndEncodeSibMessages ())
    	{
        	/* Clean ASN Context */
        	cleanASNContext ();
        
        	return (RFAILED);
    	}
#ifdef FXL_3G_TX_JAMMER
    }
#endif

    /* Fill BCCH BCH Message */
    memset((unsigned char *)octL1BchSimData.data, 0, MAX_SFN * SIM_SIZE);
    octL1BchSimData.sib7Info.sibPos = 0;
    octL1BchSimData.sib7Info.sibRep = L1CAPI_SIB_INVAL;

    for (sfnIndex = 0; sfnIndex < MAX_SFN; sfnIndex++)
    {
#ifdef FXL_3G_TX_JAMMER
        if (TRUE == gUmtsConfig.txJammerEnabled)
        {
            bcchInputData[sfnIndex].sibType     = NONE;
			bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_NO_SEGMENT;
			bcchInputData[sfnIndex].segCount    = 1;
			bcchInputData[sfnIndex].segIdx      = 0;
			bcchInputData[sfnIndex].payloadLen  = 0;
			bcchInputData[sfnIndex].payload     = NULL;
        }
		else
		{
#endif
        	switch (bcchInputData[sfnIndex].sibType)
        	{
            	case MASTER_INFORMATION_BLOCK:
               		bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
               		bcchInputData[sfnIndex].payload    = mibData;
               		break;

  	            case SYSTEM_INFORMATION_TYPE1:
       		        bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
            	    bcchInputData[sfnIndex].payload    = sib1Data;
               		break;

            	case SYSTEM_INFORMATION_TYPE2:
               		bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
               		bcchInputData[sfnIndex].payload    = sib2Data;
               		break;

            	case SYSTEM_INFORMATION_TYPE3:
               		bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
               		bcchInputData[sfnIndex].payload    = sib3Data;
               		break;

            	case SYSTEM_INFORMATION_TYPE5:
               		switch(bcchInputData[sfnIndex].payloadType)
               		{
                   		case BCH_PAYLOAD_FIRST_SEGMENT:
                      		bcchInputData[sfnIndex].payloadLen = SEGMENTED_SIB_SIZE;
                      		bcchInputData[sfnIndex].payload    = sib5DataSeg1;
                      		break;

                   		case BCH_PAYLOAD_SUBSEQUENT_SEGMENT:
                      		bcchInputData[sfnIndex].payloadLen = SEGMENTED_SIB_SIZE;
                      		bcchInputData[sfnIndex].payload    = sib5DataSeg2;
                      		break;

                   		case BCH_PAYLOAD_LAST_SEGMENT_SHORT:
                      		bcchInputData[sfnIndex].payloadLen = sib5Seg3Length;
                      		bcchInputData[sfnIndex].payload    = sib5DataSeg3;
                      		break;

                   		default:
                      		DEBUG2(("Unknown Payload type \n"));
                      		break; 
               		}
               		break;

            	case SYSTEM_INFORMATION_TYPE7:
               		bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
               		bcchInputData[sfnIndex].payload    = sib7Data;
               		break;

            	case SYSTEM_INFORMATION_TYPE11:
                        if(1 == sib11SegCount)
                        {
                            DEBUGMSG(("SIB11 No Segmentation Required, Sending Complete SIB Message\n"));
                            bcchInputData[sfnIndex].payloadLen = COMPLETE_SIB_SIZE;
                            bcchInputData[sfnIndex].payload    = sib11Data;
                        }
                        else
                        {
                            DEBUGMSG(("SIB11 Segmentation Required, Sending First Segment Message\n"));
                            bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_FIRST_SEGMENT;
                            bcchInputData[sfnIndex].payloadLen  = sib11DataSegLen[sib11SegIdx];
                            bcchInputData[sfnIndex].payload     = sib11DataSeg[sib11SegIdx];
                            bcchInputData[sfnIndex].segCount    = sib11SegCount;
                            bcchInputData[sfnIndex].segIdx      = sib11SegIdx;
                            sib11SegIdx++;
                        }
               		break;
  
            	case NONE:
                        if(((14 == sfnIndex) || (46 == sfnIndex) || (15 == sfnIndex) || (47 == sfnIndex) ||
                            (17 == sfnIndex) || (49 == sfnIndex) || (18 == sfnIndex) || (50 == sfnIndex) ||
                            (19 == sfnIndex) || (51 == sfnIndex) || (21 == sfnIndex) || (53 == sfnIndex) ||
                            (22 == sfnIndex) || (54 == sfnIndex) || (23 == sfnIndex) || (55 == sfnIndex) ||
                            (25 == sfnIndex) || (57 == sfnIndex) || (26 == sfnIndex) || (58 == sfnIndex) ||
                            (27 == sfnIndex) || (59 == sfnIndex) || (29 == sfnIndex) || (61 == sfnIndex) ||
                            (30 == sfnIndex) || (62 == sfnIndex) || (31 == sfnIndex) || (63 == sfnIndex)) && 
                            (sib11SegCount > 1) && (0 != sib11SegIdx) && (sib11SegCount == (sib11SegIdx + 1)))
                        {
                            DEBUGMSG(("SIB11 Segmentation Number(%d) & Segmented Payload Length = %d\n",sib11SegIdx,sib11DataSegLen[sib11SegIdx]));
                            if(sib11DataSegLen[sib11SegIdx] <= 214)
                            {
                                DEBUGMSG(("Sending SIB11 Last Segment Short Message\n"));
                                bcchInputData[sfnIndex].sibType     = SYSTEM_INFORMATION_TYPE11;
                                bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_LAST_SEGMENT_SHORT;
                                bcchInputData[sfnIndex].payloadLen  = sib11DataSegLen[sib11SegIdx];
                                bcchInputData[sfnIndex].payload     = sib11DataSeg[sib11SegIdx];
                                bcchInputData[sfnIndex].segCount    = sib11SegCount;
                                bcchInputData[sfnIndex].segIdx      = sib11SegIdx;
                            }
                            else
                            {
                                DEBUGMSG(("Sending SIB11 Last Segment Message\n"));
                                bcchInputData[sfnIndex].sibType     = SYSTEM_INFORMATION_TYPE11;
                                bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_LAST_SEGMENT;
                                bcchInputData[sfnIndex].payloadLen  = sib11DataSegLen[sib11SegIdx];
                                bcchInputData[sfnIndex].payload     = sib11DataSeg[sib11SegIdx];
                                bcchInputData[sfnIndex].segCount    = sib11SegCount;
                                bcchInputData[sfnIndex].segIdx      = sib11SegIdx;
                            }

                            /* Reset The SIB11 Segmentation Index */
                            sib11SegIdx = 0;
                        }
                        else if(((14 == sfnIndex) || (46 == sfnIndex) || (15 == sfnIndex) || (47 == sfnIndex) ||
                                 (17 == sfnIndex) || (49 == sfnIndex) || (18 == sfnIndex) || (50 == sfnIndex) ||
                                 (19 == sfnIndex) || (51 == sfnIndex) || (21 == sfnIndex) || (53 == sfnIndex) ||
                                 (22 == sfnIndex) || (54 == sfnIndex) || (23 == sfnIndex) || (55 == sfnIndex) ||
                                 (25 == sfnIndex) || (57 == sfnIndex) || (26 == sfnIndex) || (58 == sfnIndex) ||
                                 (27 == sfnIndex) || (59 == sfnIndex) || (29 == sfnIndex) || (61 == sfnIndex) ||
                                 (30 == sfnIndex) || (62 == sfnIndex) || (31 == sfnIndex) || (63 == sfnIndex)) && 
                                 (sib11SegCount > 1) && (0 != sib11SegIdx) && (sib11SegCount > (sib11SegIdx + 1)))
                       {
                            DEBUGMSG(("Sending SIB11 Subsequent Segment Message\n"));
                            bcchInputData[sfnIndex].sibType     = SYSTEM_INFORMATION_TYPE11;
                            bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_SUBSEQUENT_SEGMENT;
                            bcchInputData[sfnIndex].payloadLen  = sib11DataSegLen[sib11SegIdx];
                            bcchInputData[sfnIndex].payload     = sib11DataSeg[sib11SegIdx];
                            bcchInputData[sfnIndex].segCount    = sib11SegCount;
                            bcchInputData[sfnIndex].segIdx      = sib11SegIdx;	
                            sib11SegIdx++;
                       }
                       else
                       {
                            // Do Nothing
                       }
                       break;
            
            	default:
               		DEBUG2(("Unknown SIB type \n"));
               		retCode = RFAILED;
               		break;   
        	}
#ifdef FXL_3G_TX_JAMMER
		}
#endif

        if (ASN_FAILURE == encodeASNBcchBchMessage (&bcchInputData[sfnIndex],
                                                    &bcchEncodedLen,
                                                    bcchEncodedBuf,
                                                    configureSib5bis))
        {
            retCode = RFAILED;
            break;
        }

        /* Copy encoded data to L1 buffer */
        memcpy((unsigned char *)&octL1BchSimData.data[sfnIndex * SIM_SIZE], &bcchEncodedBuf[0], bcchEncodedLen); 
               
        /* Clear the encoded BCCH buffer */
        memset((unsigned char *)&bcchEncodedBuf[0], 0, SIM_SIZE);
        bcchEncodedLen  = 0;
    }

    if (SUCCESS_E != oct_sysInfo_update(&octL1BchSimData))
    {
        retCode = RFAILED;
    }

    /* Clean ASN Context */
    cleanASNContext ();

    /* Reset the SFN Initalization */
    if(sib11SegCount > 1)
    {
        for (sfnIndex = 0; sfnIndex < MAX_SFN; sfnIndex++)
        {
           if((14 == sfnIndex) || (46 == sfnIndex) || (15 == sfnIndex) || (47 == sfnIndex) ||
              (17 == sfnIndex) || (49 == sfnIndex) || (18 == sfnIndex) || (50 == sfnIndex) ||
              (19 == sfnIndex) || (51 == sfnIndex) || (21 == sfnIndex) || (53 == sfnIndex) ||
              (22 == sfnIndex) || (54 == sfnIndex) || (23 == sfnIndex) || (55 == sfnIndex) ||
              (25 == sfnIndex) || (57 == sfnIndex) || (26 == sfnIndex) || (58 == sfnIndex) ||
              (27 == sfnIndex) || (59 == sfnIndex) || (29 == sfnIndex) || (61 == sfnIndex) ||
              (30 == sfnIndex) || (62 == sfnIndex) || (31 == sfnIndex) || (63 == sfnIndex))
           {
               bcchInputData[sfnIndex].sibType	   = NONE;
               bcchInputData[sfnIndex].payloadType = BCH_PAYLOAD_NO_SEGMENT;
               bcchInputData[sfnIndex].payloadLen  = 0;
               bcchInputData[sfnIndex].payload	   = NULL;
               bcchInputData[sfnIndex].segCount    = 1;
               bcchInputData[sfnIndex].segIdx	   = 0;
           }
        }
    }
	
    return (retCode);
}

int fillAndEncodeSibMessages (void)
{
    /* Fill & Encode SIB1 */
    if (RFAILED == fillAndEncodeSIB1 ())
    {
        return (RFAILED);
    }
 
    /* Fill & Encode SIB2 */
    if (RFAILED == fillAndEncodeSIB2 ())
    {
        return (RFAILED);
    }

    /* Fill & Encode SIB3 */
    if (RFAILED == fillAndEncodeSIB3 ())
    {
        return (RFAILED);
    }

    /* Fill & Encode SIB5 */
    if (RFAILED == fillAndEncodeSIB5 ())
    {
        return (RFAILED);
    }

    /* Fill & Encode SIB7 */
    if (RFAILED == fillAndEncodeSIB7 ())
    {
        return (RFAILED);
    }

    /* Fill & Encode SIB11 */
    if (RFAILED == fillAndEncodeSIB11 ())
    {
        return (RFAILED);
    }

    /* Fill & Encode MIB */
    if (RFAILED == fillAndEncodeMIB ()) 
    {
        return (RFAILED);
    }

    return (ROK);
}

int fillAndEncodeSIB11 (void)
{
    int idx  = 0;
	int idx1 = 0;
    int bitLength  = 0;
    int bitOffset  = 0;
    int byteOffset = 0;

    sib11EncodedLength = 0;
	
    for(idx = 0; idx < 420; idx++)
    {
       sib11Data[idx] = 0;
    }

    for(idx = 0; idx < MAX_SIB11_SEGS; idx++)
    {
        for(idx1 = 0; idx1 < 28; idx1++)
        {
            sib11DataSeg[idx][idx1] = 0;
        }
		
        sib11DataSegLen[idx] = 0;
    }
	
    sib11SegCount = 0;
    sib11SegIdx   = 0;

    /* Build SIB11 Value */
    if (ASN_FAILURE == buildASNSIB11Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB11 */
    if (RFAILED == fillSIB11 ()) 
    {
        /* Clean SIB11 Value */
        cleanASNSIB11Value();

        return (RFAILED);
    }

    if (ASN_FAILURE == encodeASNSib11 (&sib11EncodedLength, sib11Data))
    {
        DEBUG1(("Encoding SIB11 failed \n"));

        /* Clean SIB11 Value */
        cleanASNSIB11Value();

        return (RFAILED);
    }
	
    /* Fill SIB11 Segmented Data */
    bitLength = sib11EncodedLength * 8;
	
    sib11SegCount = bitLength / SEGMENTED_SIB_SIZE;

    if(0 != (bitLength % SEGMENTED_SIB_SIZE))
    {
       sib11SegCount++;
    }

    DEBUGMSG(("SIB11 Encoded Buffer Length = %d & SIB11 Segmented Count = %d\n",sib11EncodedLength, sib11SegCount));

    if(sib11SegCount > MAX_SIB11_SEGS)
    {
        DEBUG1(("Encoding SIB11 failed Maximum Segmentation Limit is %d\n", MAX_SIB11_SEGS));

        /* Clean SIB11 Value */
        cleanASNSIB11Value();

        return (RFAILED);
    }

    if (sib11SegCount > 1)
    {
        for (idx = 0; idx < sib11SegCount; idx++)
        {
            if(bitLength == (bitLength % SEGMENTED_SIB_SIZE))
            {
                sib11DataSegLen[idx] = bitLength;
            }
            else
            {
                sib11DataSegLen[idx] = SEGMENTED_SIB_SIZE;
            }

            DEBUGMSG(("SIB11 Segment Index(%d) Payload Length = %d\n",idx, sib11DataSegLen[idx]));

            fillSibSegmentedData(sib11DataSeg[idx], sib11Data, &bitLength, &bitOffset, &byteOffset);
        }
    }

    /* Clean MIB ASN Value */
    cleanASNSIB11Value();

    return (ROK);
}

int fillSIB11 (void)
{ 
    /* Fill SIB12 Indicator */
    fillASNSysInfoType11SIB12Indicator (gUmtsConfig.sib11Info.sib12indicator);

    int idx = 0;
    int interFreqCells = 0;
    int interFreqDlUarfcn[MAX_INTER_FREQ_NEIGHBOURS] = {0};
    int interFreqPSC[MAX_INTER_FREQ_NEIGHBOURS]      = {0};

    int intraFreqPSC[MAX_INTRA_FREQ_NEIGHBOURS] = { 0};
    int intraFreqCells = 1;
    intraFreqPSC[0]    = gUmtsConfig.psc;  // Self PSC as first Neighbour

    if(gUmtsConfig.sib11Info.numIntraFreqNeighbr >  0)
    {
       if(gUmtsConfig.sib11Info.numIntraFreqNeighbr == 32)
       {
          intraFreqCells = 0;
       }
       for(idx = 0; idx < gUmtsConfig.sib11Info.numIntraFreqNeighbr; idx++)
       {
          intraFreqPSC[intraFreqCells] = gUmtsConfig.sib11Info.intraFreqNeighbrList[idx].psc;
          intraFreqCells++;
       }
    }
    if(gUmtsConfig.sib11Info.numInterFreqNeighbr > 0)
    {
       for(idx = 0; idx < gUmtsConfig.sib11Info.numInterFreqNeighbr; idx++)
       {
          interFreqDlUarfcn[idx] = gUmtsConfig.sib11Info.interFreqNeighbrList[idx].dlUarfcn;
          interFreqPSC[idx]      = gUmtsConfig.sib11Info.interFreqNeighbrList[idx].psc;
          interFreqCells++;
       }
    }

    /* Fill Measurement Control Information */
    fillASNSysInfoType11MeasurementControlSystemInfo (interFreqCells,
                                                      interFreqDlUarfcn,
                                                      interFreqPSC,
                                                      intraFreqCells,
                                                      intraFreqPSC);

    return (ROK);
}

int fillAndEncodeSIB7 (void)
{
    /* Build SIB7 Value */
    if (ASN_FAILURE == buildASNSIB7Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB7 */
    if (RFAILED == fillSIB7 ()) 
    {
        /* Clean SIB7 Value */
        cleanASNSIB7Value();

        return (RFAILED);
    }

    if (ASN_FAILURE == encodeASNSib7 (&sib7EncodedLength, sib7Data))
    {
        DEBUG1(("Encoding SIB7 failed \n"));

        /* Clean SIB7 Value */
        cleanASNSIB7Value();

        return (RFAILED);
    }

    /* Clean MIB ASN Value */
    cleanASNSIB7Value();

    return (ROK);
}

int fillSIB7 (void)
{ 
    int ulInterference = gUmtsConfig.sib7Info.ulInterference;
    int sib5Info       = 1;

    fillASNSysInfoType7 (ulInterference,
                         1,
                         &sib5Info); 

    return (ROK);
}

int fillAndEncodeSIB5 (void)
{
    int bitLength  = 0;
    int bitOffset  = 0;
    int byteOffset = 0;

    /* Build SIB5 Value */
    if (ASN_FAILURE == buildASNSIB5Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB5 */
    if (RFAILED == fillSIB5 ()) 
    {
        /* Clean SIB5 Value */
        cleanASNSIB5Value();

        return (RFAILED);
    }

    if (((gUmtsConfig.dlUarfcn >= 1537) && (gUmtsConfig.dlUarfcn <= 1738)) ||
        ((gUmtsConfig.dlUarfcn >= 9237) && (gUmtsConfig.dlUarfcn <= 9387)) ||
        ((gUmtsConfig.dlUarfcn >= 3112) && (gUmtsConfig.dlUarfcn <= 3388)))
    {
        configureSib5bis = 1;
        if (ASN_FAILURE == encodeASNSib5bis (&sib5EncodedLength, sib5Data))
        {
                DEBUG1(("Encoding SIB5bis failed \n"));
        
                /* Clean SIB5 Value */
                cleanASNSIB5bisValue();
    
                return (RFAILED);
        }
    }
    else
    {
        configureSib5bis = 0;
    	if (ASN_FAILURE == encodeASNSib5 (&sib5EncodedLength, sib5Data))
    	{
        	DEBUG1(("Encoding SIB5 failed \n"));

	        /* Clean SIB5 Value */
        	cleanASNSIB5Value();

	        return (RFAILED);
    	}
    }

    /* Fill SIB5 Segmented Data */
    bitLength = sib5EncodedLength * 8;
    
    fillSibSegmentedData(sib5DataSeg1, sib5Data, &bitLength, &bitOffset, &byteOffset); 

    fillSibSegmentedData(sib5DataSeg2, sib5Data, &bitLength, &bitOffset, &byteOffset); 

    sib5Seg3Length = bitLength;
    fillSibSegmentedData(sib5DataSeg3, sib5Data, &bitLength, &bitOffset, &byteOffset); 

    /* Clean MIB ASN Value */
    cleanASNSIB5Value();

    return (ROK);
}

void fillSibSegmentedData (char *pSibSegData,
                              char *pSibData,
                              int  *pBitLength,
                              int  *pBitOffset,
                              int  *pByteOffset)
{
    int leftOver      = *pBitOffset;
    int byteCount     = *pByteOffset;
    int packBitLength = (*pBitLength <= SEGMENTED_SIB_SIZE) ?  *pBitLength : SEGMENTED_SIB_SIZE;
    int bitCount      = 0;

    for (bitCount = 0; bitCount < packBitLength; bitCount++)  
    {
       if(0 == (bitCount % 8))
       {
           pSibSegData[(bitCount >> 3)] = 0;
       }

       setBit (pSibSegData,  (bitCount >> 3), (7 - (bitCount % 8)),
               (pSibData[byteCount] >> ((7 - leftOver)) & 0x1)); 
        
       leftOver++;
       if (8 == leftOver)
       {
           leftOver = 0;
           byteCount++;
       }
    }
 
    *pBitOffset  = leftOver;
    *pBitLength  = *pBitLength - packBitLength;
    *pByteOffset = byteCount;
}

void setBit (char *pSibSegData, int idx, int bitPos, int value)
{
   if (value)
   {
       pSibSegData[idx] |= (0x01 << bitPos);
   }
   else
   {
       pSibSegData[idx] &= ~(0x01 << bitPos);
   }
}

int fillSIB5 (void)
{ 
    /* Fill SIB6 Indicator */
    fillASNSysInfoType5SIB6Indicator (gUmtsConfig.sib5Info.sib6indicator);

    /* Fill PICH Power Offset */
    //fillASNSysInfoType5PICHPowerOffset (DEF_PICH_Power);
    fillASNSysInfoType5PICHPowerOffset (gUmtsConfig.sib5Info.pichPwr);

    /* Fill AICH Power Offset */
    //fillASNSysInfoType5ModeSpecificInfo (DEF_AICH_Power);
    fillASNSysInfoType5ModeSpecificInfo (gUmtsConfig.sib5Info.aichPwr);

    /* Fill Primary CCPCH Info */ 
    fillASNSysInfoType5PrimaryCCPCHInfo(0);

    int prachPreambleSignature       = 0xFFFF;
    int prachSpreadingFactor         = SIB_TYPE5_PRACH_RACH_AVAILABLE_SF_PR64;
    int prachScramblingCode          = 0;
    int prachPuncturingLimit         = SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL1;
    int prachSubChannelNumber        = 0xFFF;
    int prachTransportChannelId      = 4;
    int commonTransportChTtiType     = SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_20_MS;
    int rlcSizeOctetModeType         = SIB_TYPE5_OCTET_MODE_RLC_SIZE_INFO_TYPE2_TYPE2;
    int rlcSizeOctetModeValue        = 3;
    int numberOfTransportBlock       = SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ONE;
    int logicalChannelType           = SIB_TYPE5_LOGICAL_CHANNEL_LIST_CONFIGURED;
    int channelCodingType            = SIB_TYPE5_LOGICAL_CHANNEL_CODING_TYPE_CONVOLUTIONAL;
    int codingRate                   = SIB_TYPE5_CHANNEL_CODING_RATE_HALF;
    int rateMatchingAttribute        = 150;
    int crcSize                      = SIB_TYPE5_CRC_SIZE_CRC16;
    int tfcsConfigurationType        = SIB_TYPE5_TFCS_CONFIGURATION_TYPE_COMPLETE;
    int ctfcSize                     = SIB_TYPE5_CTFC_SIZE_2BIT;
    int ctfc2                        = 0;
    int gainFactor                   = SIB_TYPE5_GAIN_FACTOR_SIGNALLED;
    int gainFactorBetaC              = 15;
    int gainFactorBetaD              = 10;
    int powerOffsetPpm               = 0;
    int availableSignatureStartIndex = 0;
    int availableSignatureEndIndex   = 2;
    char assignedSubChanNumber       = 0x70;
    int constantValue                = -11;
    //int powerRampStep                = 1;
    //int preambleRetransMax           = 30;
    int mMax                         = 10;
    int nb01Min                      = 3;
    int nb01Max                      = 10;
    int channelisationCode256        = 0x3;
    int sttdIndicator                = 0;
    int aichTransmissionTiming       = 1;

    /* Fill PRACH System Information */
    if( ASN_FAILURE == fillASNSysInfoType5PRACHSystemInformationList (1,
                                                                      prachPreambleSignature,
                                                                      prachSpreadingFactor, 
                                                                      prachScramblingCode,
                                                                      prachPuncturingLimit,
                                                                      prachSubChannelNumber,
                                                                      prachTransportChannelId,
                                                                      commonTransportChTtiType,
                                                                      1,
                                                                      rlcSizeOctetModeType,
                                                                      rlcSizeOctetModeValue,
                                                                      1,
                                                                      &numberOfTransportBlock, 
                                                                      logicalChannelType,
                                                                      channelCodingType,
                                                                      codingRate,
                                                                      rateMatchingAttribute,
                                                                      crcSize, 
                                                                      tfcsConfigurationType,
                                                                      ctfcSize,
                                                                      1,
                                                                      &ctfc2,
                                                                      &gainFactor,
                                                                      &gainFactorBetaC,
                                                                      &gainFactorBetaD,
                                                                      &powerOffsetPpm,
                                                                      1,
                                                                      &availableSignatureStartIndex,
                                                                      &availableSignatureEndIndex, 
                                                                      assignedSubChanNumber,
                                                                      gUmtsConfig.cpichTxPwr,
                                                                      constantValue,
                                                                      gUmtsConfig.sib5Info.prachPowerRampStep,
                                                                      gUmtsConfig.sib5Info.prachpreambleRetransMax,
                                                                      mMax,
                                                                      nb01Min,
                                                                      nb01Max,
                                                                      channelisationCode256,
                                                                      sttdIndicator,
                                                                      aichTransmissionTiming)) 
    {
        return (RFAILED);
    }

    int sccpchSttdIndicator             = 0;
    int sccpchSfCodeType                = SIB_TYPE5_SF_256_CODE_NUMBER_SF64;
    int sccpchSfCodeValue               = 1;
    int sccpchPilotSymbolExistence      = 0;
    int sccpchTfciExistence             = 1;
    int sccpchPositionFixedOrFlexible   = SIB_TYPE5_SCCPCH_POSITION_FLEXIBLE;
    int sccpchCtfcSizeType              = SIB_TYPE5_CTFC_SIZE_4BIT;
    int sccpchTimingOffset              = 0;
    int sccpchCtfc4[6]                  = {0, 1, 2, 3, 4, 6};
    int rlcSizeType[3]                  = { SIB_TYPE5_RLC_SIZE_TYPE2,
                                            SIB_TYPE5_RLC_SIZE_TYPE1,
                                            SIB_TYPE5_RLC_SIZE_TYPE1 };
    int rlcSizeTypeValue[3]             = { 3, 15, 24 };
    int tbSizeList[3]                   = { 2, 3, 2 };

    int tbSize[3][3]                    = { { SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ZERO,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ONE,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_SMALL 
                                            },
                                            { SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ZERO,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ONE,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_SMALL 
                                            },
                                            { SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ZERO,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ONE,
                                              SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_SMALL 
                                            }
                                          }; 

    int sccpchRateMatchingAttribute[3]  = { 129, 219, 229 };
    int sccpchTransportChannelId[3]     = { 3, 2, 1 };
    int sccpchChannelCodingType[3]      = { 2, 1, 1 };
    int sccpchChannelisationCode256     = 2;

    /* Fill SCCPCH System Information */
    fillASNSysInfoType5SCCPCHSysInfo (1,
                                      sccpchSttdIndicator,
                                      sccpchSfCodeType,
                                      sccpchSfCodeValue, 
                                      sccpchPilotSymbolExistence,
                                      sccpchTfciExistence,
                                      sccpchPositionFixedOrFlexible,
                                      sccpchCtfcSizeType, 
                                      sccpchTimingOffset,                              
                                      6,
                                      sccpchCtfc4, 
                                      3,
                                      1,
                                      rlcSizeType,
                                      rlcSizeTypeValue,
                                      tbSizeList,
                                      tbSize,
                                      sccpchRateMatchingAttribute, 
                                      sccpchTransportChannelId,
                                      sccpchChannelisationCode256,
                                      sccpchChannelCodingType);

    return (ROK);
}
  
int fillAndEncodeSIB3 (void)
{
    /* Build SIB3 Value */
    if (ASN_FAILURE == buildASNSIB3Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB3 */
    if (RFAILED == fillSIB3 ()) 
    {
        /* Clean SIB3 Value */
        cleanASNSIB3Value();

        return (RFAILED);
    }

    if (ASN_FAILURE == encodeASNSib3 (&sib3EncodedLength, sib3Data))
    {
        DEBUG1(("Encoding SIB3 failed \n"));

        /* Clean SIB3 Value */
        cleanASNSIB3Value();

        return (RFAILED);
    }

    /* Clean MIB ASN Value */
    cleanASNSIB3Value();

    return (ROK);
}

int fillSIB3 (void)
{ 
    unsigned int cellIdStr = 0;
    /* Fill SIB4 Indicator */
    fillASNSysInfoType3SIB4Indicator (0);

    cellIdStr = gUmtsConfig.cellId & 0xFF;
    cellIdStr = (cellIdStr << 8) | ((gUmtsConfig.cellId >> 8) &0xFF);
    /* Fill Cell Identity */
    if (ASN_FAILURE == 
        fillASNSysInfoType3CellIdentity (cellIdStr))
    {
        return (RFAILED);
    }

    /* Fill Cell Select Reselect Qual Meas */
    fillASNSysInfoType3CellSelectReselectQualMeas (gUmtsConfig.cellSelQualMeas,
                                                   gUmtsConfig.qHyst2S);

    /* Fill Cell Select Reselect Mode Specific Info */
    fillASNSysInfoType3CellSelectReselectModeSpecificInfo ( gUmtsConfig.sib3Info.sIntraSearch,
                                                            gUmtsConfig.sib3Info.sInterSearch,
                                                            gUmtsConfig.sib3Info.sSearchHCS,
                                                            gUmtsConfig.sib3Info.ratSearch,
                                                            gUmtsConfig.sib3Info.sLimitSearchRAT,
                                                            gUmtsConfig.qQualMin,
                                                            gUmtsConfig.qRxLevMin);

    fillASNSysInfoType3CellSelectReselectQHystLS (gUmtsConfig.qHystLS);

    fillASNSysInfoType3CellSelectReselectTReselectionS (gUmtsConfig.tReselec);

    fillASNSysInfoType3CellSelectReselectULTxPower (gUmtsConfig.maxUlTxPwr);

    fillASNSysInfoType3CellAccessRestrictionCell (gUmtsConfig.sib3Info.cellBarredInfo.status, 
                                                  gUmtsConfig.sib3Info.cellBarredInfo.intraFreqCellReselectionInd,
                                                  gUmtsConfig.sib3Info.cellBarredInfo.T_Barred);

    fillASNSysInfoType3CellReservedForOperatorUse (gUmtsConfig.sib3Info.cellReservedForOperatiorUse);

    fillASNSysInfoType3CellReservationExtension (gUmtsConfig.sib3Info.cellReservationExtention);
   
#if 0
    int sib3AccClassRestrict[16] = { ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED,
                                     ACCESS_CLASS_NOT_BARRED, ACCESS_CLASS_NOT_BARRED };
    fillASNSysInfoType3AccessClassBarredList (16,
                                              sib3AccClassRestrict);
#endif

    fillASNSysInfoType3AccessClassBarredList (16,
                                              gUmtsConfig.sib3Info.accessClassBarredLst);

    return (ROK);
}

int fillAndEncodeSIB2 (void)
{
    /* Build SIB2 Value */
    if (ASN_FAILURE == buildASNSIB2Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB2 */
    if (RFAILED == fillSIB2 ()) 
    {
        /* Clean SIB2 Value */
        cleanASNSIB2Value();

        return (RFAILED);
    }

    if (ASN_FAILURE == encodeASNSib2 (&sib2EncodedLength, sib2Data))
    {
        DEBUG1(("Encoding SIB2 failed \n"));

        /* Clean SIB1 Value */
        cleanASNSIB2Value();

        return (RFAILED);
    }

    /* Clean MIB ASN Value */
    cleanASNSIB2Value();

    return (ROK);
}

int fillSIB2 (void)
{ 
    //unsigned int uraIdentity[1] = {0xd071};

    if(ASN_FAILURE == fillASNSysInfoType2URAIdentity (gUmtsConfig.sib2Info.numUraIdentity, gUmtsConfig.sib2Info.uraIdentityLst))
    {
        return (RFAILED);
    } 

    return (ROK);
}

int fillAndEncodeSIB1 (void)
{
    /* Build SIB1 Value */
    if (ASN_FAILURE == buildASNSIB1Value ())
    {
        return (RFAILED);
    }

    /* Fill SIB1 */
    if (RFAILED == fillSIB1 ()) 
    {
        /* Clean SIB1 Value */
        cleanASNSIB1Value();

        return (RFAILED);
    }

    if (ASN_FAILURE == encodeASNSib1 (&sib1EncodedLength, sib1Data))
    {
        DEBUG1(("Encoding SIB1 failed \n"));

        /* Clean SIB1 Value */
        cleanASNSIB1Value();

        return (RFAILED);
    }
 
    /* Clean MIB ASN Value */
    cleanASNSIB1Value();

    return (ROK);
}

int fillSIB1 (void)
{
#if 0
    unsigned int cnDomainList[2] = { CN_DOMAIN_IDENTITY_CS,
                                     CN_DOMAIN_IDENTITY_PS
                                   };
#endif
    unsigned int cnDomainType[2] = { SIB_TYPE1_CN_TYPE_GSM_MAP,
                                     SIB_TYPE1_CN_TYPE_GSM_MAP
                                   };
    
    unsigned int dRxCycleLengthCoeff[2] = { UTRAN_DRX_CYCLE_LENGTH_COEFF, UTRAN_DRX_CYCLE_LENGTH_COEFF }; 

#if 0
    unsigned char gsmMapValue1[2] = {0x01, 0x01};
    unsigned char gsmMapValue2[2] = {0x56, 0x01};
#endif
    unsigned char gsmMapValue1[2] = {0};
    unsigned char gsmMapValue2[2] = {0};

    unsigned int  lac = 0;

    /* Assign 1st Byte of LAC */
    lac = lac | (gUmtsConfig.lac[0] << 8);

    /* Assign 2nd Byte of LAC */
    lac = lac | gUmtsConfig.lac[1];

    /* Fill LAC */
    if (ASN_FAILURE == fillASNSysInfoType1LAC (&lac))
    {
        return (RFAILED);
    }
   
    /* Fill T3212 and ATT */
    gsmMapValue1[0] = gUmtsConfig.t3212;
    gsmMapValue1[1] = (gUmtsConfig.att & 0x01);

    /* Fill RAC */
    gsmMapValue2[0] = gUmtsConfig.rac;
    gsmMapValue2[1] = (gUmtsConfig.nmo & 0x01);
     

    /* Fill CN Domain */
    if (ASN_FAILURE == fillASNSysInfoType1CNDomainSystemInfo (2, 
                                                              gUmtsConfig.sib1Info.cnDomainList,
                                                              cnDomainType,
                                                              gsmMapValue1,  
                                                              gsmMapValue2,  
                                                              dRxCycleLengthCoeff))
    {
        return (RFAILED);
    }

    /* Fill UE Idle Timers */
    fillASNSysInfoType1UeIdleTimers (gUmtsConfig.sib1Info.N300,
                                     gUmtsConfig.sib1Info.T300,
                                     gUmtsConfig.sib1Info.T312,
                                     gUmtsConfig.sib1Info.N312);

    /* Fill UE Connected Timers */
    fillASNSysInfoType1ConnTimer ();

    fillASNSysInfoType1ConnTimerT301 (gUmtsConfig.sib1Info.T301);
    fillASNSysInfoType1ConnTimerT302 (gUmtsConfig.sib1Info.T302);
    fillASNSysInfoType1ConnTimerT304 (gUmtsConfig.sib1Info.T304);
    fillASNSysInfoType1ConnTimerT305 (gUmtsConfig.sib1Info.T305);
    fillASNSysInfoType1ConnTimerT307 (gUmtsConfig.sib1Info.T307);
    fillASNSysInfoType1ConnTimerT308 (gUmtsConfig.sib1Info.T308);
    fillASNSysInfoType1ConnTimerT310 (gUmtsConfig.sib1Info.T310);
    fillASNSysInfoType1ConnTimerT311 (gUmtsConfig.sib1Info.T311);
    fillASNSysInfoType1ConnTimerT312 (gUmtsConfig.sib1Info.T312);
    fillASNSysInfoType1ConnTimerN312 (gUmtsConfig.sib1Info.N312);
    fillASNSysInfoType1ConnTimerN313 (gUmtsConfig.sib1Info.N313);
    fillASNSysInfoType1ConnTimerT314 (gUmtsConfig.sib1Info.T314);
    fillASNSysInfoType1ConnTimerT315 (gUmtsConfig.sib1Info.T315);
    fillASNSysInfoType1ConnTimerN315 (gUmtsConfig.sib1Info.N315);
    fillASNSysInfoType1ConnTimerT316 (gUmtsConfig.sib1Info.T316);
    fillASNSysInfoType1ConnTimerT317 (gUmtsConfig.sib1Info.T317);

    return (ROK);
}

int fillAndEncodeMIB (void)
{
    /* Build MIB Value */
    if (ASN_FAILURE == buildASNMIBValue ())
    {
        DEBUG1(("Building MIB Value failed \n"));
        return (RFAILED);
    }

    /* Fill MIB */
    fillMIB ();

    /* ASN encode the MIB */
    if (ASN_FAILURE == encodeASNMib (&mibEncodedLength, mibData))
    {
        /* Clean MIB ASN Value */
        cleanASNMIBValue();

        DEBUG1(("Encoding MIB Value failed \n"));
        return (RFAILED);
    }


    /* Clean MIB ASN Value */
    cleanASNMIBValue();

    return (ROK);
}

void fillMIB (void)
{
    int index = 0;

    unsigned int sibRefList[MAX_SIB]     = { SIB_TYPEANDTAG_SYSINFOTYPE1,
                                             SIB_TYPEANDTAG_SYSINFOTYPE2,
                                             SIB_TYPEANDTAG_SYSINFOTYPE3,
                                             SIB_TYPEANDTAG_SYSINFOTYPE5,
                                             SIB_TYPEANDTAG_SYSINFOTYPE7,
                                             SIB_TYPEANDTAG_SYSINFOTYPE11
                                           };

    unsigned int sibRepPos[MAX_SIB]      = { SIB_SCHEDULING_POS_REP64,
                                             SIB_SCHEDULING_POS_REP64,
                                             SIB_SCHEDULING_POS_REP64,
                                             SIB_SCHEDULING_POS_REP64,
                                             SIB_SCHEDULING_POS_REP64,
                                             SIB_SCHEDULING_POS_REP64
                                           };

    unsigned int sibRepPosValue[MAX_SIB] = { 1, 2, 3, 5, 9, 13 };

    /* Fill MIB Tag Value */
    fillASNMIBValueTag (gUmtsConfig.mibValueTag); 
 
    /* Fill PLMN Type */
    fillASNMIBPLMNType (0); 

    fillASNMIBPLMNIdentityMCC (gUmtsConfig.plmn[0].mccLength, gUmtsConfig.plmn[0].mcc); 

    fillASNMIBPLMNIdentityMNC (gUmtsConfig.plmn[0].mncLength, gUmtsConfig.plmn[0].mnc);

    /* Fill SIB Reference List */
    fillASNMIBSIBReferenceList (MAX_SIB, sibRefList, sibRepPos, 
                                sibRepPosValue, gUmtsConfig.mibValueTag, sib11SegCount, configureSib5bis);

    if(gUmtsConfig.numOfPlmn > 1)
    {
       fillASNMIBMultiPLMNIdentity(gUmtsConfig.numOfPlmn,gUmtsConfig.plmn,gUmtsConfig.mibPlmnIdentity); 
    }
}

