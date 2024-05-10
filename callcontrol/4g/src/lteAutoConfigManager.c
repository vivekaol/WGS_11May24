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
* File Name   : lteAutoConfigManager.h
 *
* Description : Function to support selection of Auto Config data
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 19/05/2015          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#include "lteCmnDef.h"
#include "logManager.h"
#include "fxLSocketInterfaceApi.h"
#include "linkedlist.h"
#include "lteAsn1IntfcHandler.h"

lteWlRedirectInfo redirectInfo ;
eLteBw lteSelectedBandwidth = LTE_BW_N50;
listNode *headForLteScanDataQ = NULL;
listNode *tailForLteScanDataQ = NULL;

uint8 compareLteScanDataWithUserGivenData(fxL4gListenModeSystemInfoInd *scanData , fxL4gConfigureIdCatcherParamsCmd *cmd)
{
	uint8 ret = FALSE;
	uint8 i = 0, j = 0;

	for (i = 0; i < scanData->sib1.noOfPlmns; i++)
	{
	    for (j = 0; j < cmd->numOfPlmn; j++)
	    {
	        if((scanData->sib1.plmn[i].mccLength == cmd->plmn[j].mccLength) &&
			   (scanData->sib1.plmn[i].mcc[0] == cmd->plmn[j].mcc[0])&&
			   (scanData->sib1.plmn[i].mcc[1] == cmd->plmn[j].mcc[1])&&
			   (scanData->sib1.plmn[i].mcc[2] == cmd->plmn[j].mcc[2])&&
			   (scanData->sib1.plmn[i].mncLength == cmd->plmn[j].mncLength) &&
			   (scanData->sib1.plmn[i].mnc[0] == cmd->plmn[j].mnc[0])&&
			   (scanData->sib1.plmn[i].mnc[1] == cmd->plmn[j].mnc[1])&&
			   (scanData->sib1.plmn[i].mnc[2] == cmd->plmn[j].mnc[2]))
	        {
	            ret = TRUE;
				break;
	        }
	    }

		if (ret)
		{
		   break;
		}
	}
	
	
	return ret;
}
#if 0
uint8 isItDuplicateData(fxL4gListenModeSystemInfoInd * lteParams)
{
	uint8 ret = FALSE;
	listNode *current = headForLteScanDataQ;
	fxL4gListenModeSystemInfoInd* scanData = NULL;
	if(current == NULL)
	{
		logPrint(LOG_ERR,"This is first node \n");
	}
	else
	{
		while(current != NULL)
		{
			scanData = (fxL4gListenModeSystemInfoInd*)(current->msg);
			if((scanData != NULL)&&(compareLteScanDataWithUserGivenData(scanData, lteParams) == TRUE) &&
			  (lteParams->earfcn == scanData->earfcn) && (lteParams->sib1.freqBandIndicator == scanData->sib1.freqBandIndicator))
			{
				if(scanData->rsrp < lteParams->rsrp) // New cell has better rsrp , so store new data in the old node
				{
					memcpy((void*)scanData , (void*)lteParams , sizeof(fxL4gListenModeSystemInfoInd));
					logPrint(LOG_ERR,"Copied new contains to old node as it has better rsrp \n");
				}
				break;
			}
			else
			{
			  current = current->next;
			}
		}

		if(current != NULL)
		{
			ret = TRUE;
		}
		else
		{
			logPrint(LOG_ERR,"New Data Node \n");
		}
	}
	return ret;
}
#endif
void addLteScanDataToList(fxL4gListenModeSystemInfoInd * sysInfo)
{
	listNode *tail = tailForLteScanDataQ;
	fxL4gListenModeSystemInfoInd *lteScanData = NULL;
	/*
	if(isItDuplicateData(sysInfo) == TRUE)
	{
		logPrint(LOG_DEBUG, "Duplicate Node\n");
		return;
	}*/
    lteScanData = (fxL4gListenModeSystemInfoInd*)malloc(sizeof(fxL4gListenModeSystemInfoInd));
    assert(lteScanData != NULL);
    memcpy((void*)lteScanData , (void*)sysInfo , sizeof(fxL4gListenModeSystemInfoInd));
    logPrint(LOG_DEBUG, "LTE Cell added ARFCN = %d , PCI = %d , BandWidth = %d \n" ,lteScanData->earfcn, lteScanData->phyCellId , lteScanData->dlBw );
    pushMsgToList(&tail ,(void*)lteScanData);
	if((headForLteScanDataQ == NULL)||(tailForLteScanDataQ == NULL))
	{
		headForLteScanDataQ = tailForLteScanDataQ = tail; // Update for the first time
	}
	else
	{
		tailForLteScanDataQ = tail; // Just update the tail node
	}

	return;
}

uint8 searchLteScanDataToFindAutoConfigParams(fxL4gConfigureIdCatcherParamsCmd* lteParams)
{
    uint8 i = 0, j = 0;
	uint8 ret = FALSE;
	listNode *current = headForLteScanDataQ;
	fxL4gListenModeSystemInfoInd* scanData = NULL , *bestCellParams = NULL;
	if(current == NULL)
	{
		logPrint(LOG_ERR,"Scan Data List is empty \n");
	}
	else
	{
		while(current != NULL)
		{
			scanData = (fxL4gListenModeSystemInfoInd*)(current->msg);
			if((scanData != NULL)&&(compareLteScanDataWithUserGivenData(scanData, lteParams) == TRUE))
			{
				if(bestCellParams == NULL)
				{
					bestCellParams = scanData;
					logPrint(LOG_DEBUG , "First time , BestCell-Rsrp = %f , ScanData-Rsrp = %f\n",bestCellParams->rsrp , scanData->rsrp );
				}
				else
				{
					logPrint(LOG_DEBUG , "Next time , BestCell-Rsrp = %f , ScanData-Rsrp = %f\n",bestCellParams->rsrp , scanData->rsrp );
					if(abs(bestCellParams->rsrp) > abs(scanData->rsrp))
					{
						bestCellParams = scanData;
					}
				}
			}
  		    current = current->next;
		}

		if(bestCellParams != NULL)
		{	
		    lteParams->numOfPlmn = bestCellParams->sib1.noOfPlmns;
			for (i = 0; i < bestCellParams->sib1.noOfPlmns; i++)
			{
			    lteParams->plmn[i].mccLength = bestCellParams->sib1.plmn[i].mccLength;
				for (j = 0; j < bestCellParams->sib1.plmn[i].mccLength; j++)
				{
				   lteParams->plmn[i].mcc[j] = bestCellParams->sib1.plmn[i].mcc[j];
				}
				
			    lteParams->plmn[i].mncLength = bestCellParams->sib1.plmn[i].mncLength;
				for (j = 0; j < bestCellParams->sib1.plmn[i].mncLength; j++)
				{
				   lteParams->plmn[i].mnc[j] = bestCellParams->sib1.plmn[i].mnc[j];
				}
			}
			lteParams->earfcn = bestCellParams->earfcn;
			lteParams->bandIndicator = bestCellParams->sib1.freqBandIndicator;
//			lteParams->layer3CellId = bestCellParams->sib1.l3cellId + 1;
			lteParams->layer3CellId = gsmCommRand(1, 65535);
			if(lteParams->layer3CellId > 0x0FFFFFFF)
			{
				lteParams->layer3CellId = 500;
			}
//			lteParams->phyCellId = bestCellParams->phyCellId + 1;
			lteParams->phyCellId = gsmCommRand(1, 511);
			if(lteParams->phyCellId > 511)
			{
				lteParams->phyCellId = 500;
			}

//			lteParams->tac = bestCellParams->sib1.tac + 1;
			lteParams->tac = gsmCommRand(1, 65535);
			if(lteParams->tac > 0x0000FFFF)
			{
				lteParams->tac = 1;
			}

			redirectInfo.noOfSib5Freq = bestCellParams->sib5.noOfInterFreqNeighbourCells;
			redirectInfo.noOfSib6Freq = bestCellParams->sib6.noOfInterRatUmtsNeighbors;
			redirectInfo.noOfSib7Freq = bestCellParams->sib7.noOfInterRatGsmNeighbors;
			redirectInfo.sib5Earfcn = bestCellParams->sib5.earfcnInterFreqNeighbors[0].dlCarrierFreq;
			redirectInfo.sib6Uarfcn = bestCellParams->sib6.uarfcnInterRatNeighbors[0].umtsCarrierFreq;
			redirectInfo.sib7Arcfn = bestCellParams->sib7.startingArfcnInterRatNeighbors[0];
			redirectInfo.sib7BandIndicator = bestCellParams->sib7.bandIndicator[0];
			redirectInfo.earfcn =bestCellParams->earfcn;

			lteSelectedBandwidth = (uint8)bestCellParams->dlBw;
			/*if(lteSelectedBandwidth < LTE_BW_N25 )
			{
				lteSelectedBandwidth = LTE_BW_N25;
			}*/

#if 0
			if(lteSelectedBandwidth == LTE_BW_N75 ) // Case : 15 Mhz not supported by Octasic
			{
				lteSelectedBandwidth = LTE_BW_N50; // 10 Mhz
			}
#endif
                        /*Relative delay needed in FDD also */
			lteParams->reserved = bestCellParams->relativeD;			
	
			if((lteParams->bandIndicator >= 33) && (lteParams->bandIndicator <= 48)) //only for TDD
			{
				if(lteSelectedBandwidth == LTE_BW_N100 ) // 20 Mhz not supported by octasic
				{
					lteSelectedBandwidth = LTE_BW_N50;
				}
			}
			ret = TRUE;
		}
		else
		{
			logPrint(LOG_ERR,"PLMN Not Found in the scan data List \n");
			lteSelectedBandwidth = LTE_BW_N50;
		}
	}

	return ret;
}

void deleteLteScanData()
{
	listNode *current = headForLteScanDataQ;
	listNode *tmp = NULL;

	while(current != NULL)
	{
		tmp = current;
		if(current != NULL)
		{
			current = current->next;
		}

		if(tmp != NULL)
		{
			if(tmp->msg != NULL)
			{
				free(tmp->msg);
				tmp->msg = NULL;
			}
			free(tmp);
			tmp = NULL;
		}
	}

	headForLteScanDataQ = tailForLteScanDataQ = NULL;
	return;
}

#ifdef FXL_4G_TX_JAMMER

uint8 searchLteScanDataToFindJammerConfigParams(fxL4gConfigureIdCatcherParamsCmd* lteParams)
{
	uint8 ret = FALSE;
	listNode *current = headForLteScanDataQ;
	fxL4gListenModeSystemInfoInd* scanData = NULL , *bestCellParams = NULL ;
	if(current == NULL)
	{
		logPrint(LOG_ERR,"Scan Data List is empty \n");
	}
	else
	{
		while(current != NULL)
		{
			scanData = (fxL4gListenModeSystemInfoInd*)(current->msg);
			if(scanData != NULL)
			{
				if(bestCellParams == NULL)
				{
					bestCellParams = scanData;
					logPrint(LOG_DEBUG , "First time , BestCell-Rsrp = %f , ScanData-Rsrp = %f\n",bestCellParams->rsrp , scanData->rsrp );
				}
				else
				{
					logPrint(LOG_DEBUG , "Next time , BestCell-Rsrp = %f , ScanData-Rsrp = %f\n",bestCellParams->rsrp , scanData->rsrp );
					if(abs(bestCellParams->rsrp) > abs(scanData->rsrp))
					{
						bestCellParams = scanData;
					}
				}
			}
  		    current = current->next;
		}

		if(bestCellParams != NULL)
		{
			lteParams->earfcn = bestCellParams->earfcn;
			lteParams->bandIndicator = bestCellParams->sib1.freqBandIndicator;
			lteParams->layer3CellId = bestCellParams->sib1.l3cellId + 1;
			if(lteParams->layer3CellId > 0x0FFFFFFF)
			{
				lteParams->layer3CellId = 500;
			}
			lteParams->phyCellId = bestCellParams->phyCellId; // Mandatory for Jammer
			lteParams->tac = bestCellParams->sib1.tac + 1;
			if(lteParams->tac > 0x0000FFFF)
			{
				lteParams->tac = 1;
			}

			lteSelectedBandwidth = (uint8)bestCellParams->dlBw;
			if(lteSelectedBandwidth < LTE_BW_N25 )
			{
				lteSelectedBandwidth = LTE_BW_N25;
			}

			if(lteSelectedBandwidth == LTE_BW_N75 )
			{
				lteSelectedBandwidth = LTE_BW_N50;
			}
			ret = TRUE;
		}
		else
		{
			logPrint(LOG_ERR,"No LTE Cells in Jammer Scan Data \n");
			lteSelectedBandwidth = LTE_BW_N50;
		}
	}
	return ret;
}
#endif
