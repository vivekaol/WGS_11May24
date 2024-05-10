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
* File Name   : cleanChannelSelectionManager.c
*
* Description : Function to select clean channel/ARFCN from the data given by RUS.
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 04/12/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/

/******************************************************************************************
 * Algorithm is
 * 1)Get the PLMN (MCC/MNC) from the user.
 * 2)Get the all cells belonging to that PLMN based on SI-3.
 * 3)For each cell get the neighbour cells from SI-2 of that cell.
 * 4)Find the common cells from all neighbour cells , and select a cell which has least RSSI if it is available.
 * 5)If we could not find one cell which is common in all SI-2 neighbour then select the cell which belongs to maximum cells.
 * 6)Select that ARFCN value to run the BTS.
 */
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "logManager.h"
#include "cleanChannelSelectionManager.h"
#include "linkedlist.h"
#include "fxLSocketInterfaceApi.h"

#define MAX_NO_OF_SERVING_CELLS_PER_PLMN 50 // Assuming maximum 50 cells per PLMN
#define MAX_SIZE_OF_SEARCH (MAX_NO_OF_SERVING_CELLS_PER_PLMN * GERAN_ARFCN_LIST_LENGTH)
typedef struct
{
  tOCT_UINT16 arfcnArr[GERAN_ARFCN_LIST_LENGTH];
  tOCT_UINT16 noOfNeighborCells;
  fxL2gPlmn   plmn;
}neighborCells;

tOCT_UINT16 *storedArfcnArr = NULL;
tOCT_UINT16 neighCellIndex = 0;
tOCT_UINT8 band[2];

tOCT_UINT8 compareGsmScanDataWithUserGivenData(fxL2gPlmn *scanDataPlmn , fxL2gPlmn* configuredPlmn);
void selectDistintLacFromParsedData(tOCT_UINT16 *lArr , tOCT_UINT16* mappedLac);

signed char parseGsmSysInfo(fxL2gPlmn* inPlmn, tOCT_UINT16* Lac)
{
    char *s , *buff;
    neighborCells *nCell;
    tOCT_UINT8 duplicate = FALSE;
    tOCT_UINT16 lacArr[MAX_NO_OF_SERVING_CELLS_PER_PLMN], i , j, servingCellArfcn = END_OF_LIST, \
                inPlmnServingCellArfcn[MAX_NO_OF_SERVING_CELLS_PER_PLMN], inPlmnServingCellArfcnCount = 0, \
                servingArfcnsWoPlmnData[MAX_NO_OF_SERVING_CELLS_PER_PLMN], numOfServingArfcnsWoPlmnData = 0;
    char* path = "/home/wgs/GsmSysInfo.txt";
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
      return -1;
    }

    buff = calloc(256 , sizeof(tOCT_UINT8));
    storedArfcnArr = calloc(MAX_SIZE_OF_SEARCH , sizeof(tOCT_UINT16));
    nCell = (neighborCells *) malloc(sizeof(neighborCells));
    memset(nCell , 0 , sizeof(neighborCells));
    memset(lacArr , 0 , sizeof(tOCT_UINT16)*MAX_NO_OF_SERVING_CELLS_PER_PLMN);

    for(i=0; i<MAX_NO_OF_SERVING_CELLS_PER_PLMN; i++)
    {
        inPlmnServingCellArfcn[i]  = END_OF_LIST;
        servingArfcnsWoPlmnData[i] = END_OF_LIST;
    }

    band[0] = 0xFF;
    band[1] = 0xFF;
    /* Read next line */
    while ((s = fgets (buff, 256 , fp)) != NULL)
    {
        /* Skip blank lines and comments */
        if (buff[0] == '\n' || buff[0] == '#')
          continue;

        /* Parse name/value pair from line */
        char name[128], value[10];
        s = strtok (buff, "=");
        if (s==NULL)
          continue;
        else
          strncpy (name, s, 128);
        s = strtok (NULL, "=");
        if (s==NULL)
          continue;
        else
          strncpy (value, s, 10);
        trim (value);

        /* Copy into correct entry in parameters struct */
        if(strcmp(name, "GSM-ARFCN")==0)
        {
        	// First store the last parsed cells
        	if(nCell->arfcnArr[1] != END_OF_LIST)
        	{
        	    if((nCell->plmn.mccLength == 0)&&(nCell->plmn.mncLength == 0))
                {
                    /* Serving cell for which PLMN data is not available:
                     * Consider adding to the serving cell list anyway 
                     * so that we ignore it during clean channel selection.
                     * And ignore the Neighbor cell data if available for this cell.
                     */
                    if(servingCellArfcn != END_OF_LIST && numOfServingArfcnsWoPlmnData < MAX_NO_OF_SERVING_CELLS_PER_PLMN)
                    {      
                       servingArfcnsWoPlmnData[numOfServingArfcnsWoPlmnData++] = servingCellArfcn;
                       //logPrint(LOG_DEBUG, "PLMN data not found for ARFCN %d, adding it to the ignore list\n", servingCellArfcn);
                    }
                }
        		else if(compareGsmScanDataWithUserGivenData(&(nCell->plmn) , inPlmn) == TRUE)
        		{
        		    if(inPlmnServingCellArfcnCount < MAX_NO_OF_SERVING_CELLS_PER_PLMN)
                    {      
        		        inPlmnServingCellArfcn[inPlmnServingCellArfcnCount++] = servingCellArfcn;

            			for(i = 0; i< nCell->noOfNeighborCells ; i++)
            			{
            				if(neighCellIndex < MAX_SIZE_OF_SEARCH)
                            {
                                storedArfcnArr[neighCellIndex++] = nCell->arfcnArr[i];
                                //logPrint(LOG_DEBUG, "Stored ARFCN = %d\n", nCell->arfcnArr[i]);
                            }
                        }
                    }
        		}
        	}
        	nCell->noOfNeighborCells = 0;
        	memset(nCell , 0 , sizeof(neighborCells));
        	servingCellArfcn = atoi(value) ; //Adding serving cell to a neighbor list.
            nCell->arfcnArr[0] = END_OF_LIST; // Set ARCFN to Invalid ARFCN
        }

        if(strcmp(name, "GSM-BAND")==0)
        {
        	if(band[0] == 0xFF)
        	{
        		band[0] = atoi(value) ;
                //logPrint(LOG_DEBUG, "Added BANDS = %d , %d\n" , band[0] , band[1]);
        	}
        	else if(band[1] == 0xFF)
        	{
        		if(band[0] != atoi(value))
				{
        		    band[1] = atoi(value) ;                
                    //logPrint(LOG_DEBUG, "Added BANDS = %d , %d\n" , band[0] , band[1]);
			    }
        	}
        }

        if(strcmp(name, "SI-3-Serving-Cell-Mcc[0]")==0)
        {
        	nCell->plmn.mcc[0] = atoi(value) ;
            if(nCell->plmn.mcc[0] != 0xF)
              nCell->plmn.mccLength++;
        }
        if(strcmp(name, "SI-3-Serving-Cell-Mcc[1]")==0)
        {
        	nCell->plmn.mcc[1] = atoi(value) ;        
            if(nCell->plmn.mcc[1] != 0xF)
              nCell->plmn.mccLength++;
        }
        if(strcmp(name, "SI-3-Serving-Cell-Mcc[2]")==0)
        {
        	nCell->plmn.mcc[2] = atoi(value) ;        
            if(nCell->plmn.mcc[2] != 0xF)
              nCell->plmn.mccLength++;
        }

        if(strcmp(name, "SI-3-Serving-Cell-Mnc[0]")==0)
        {
        	nCell->plmn.mnc[0] = atoi(value) ;
            if(nCell->plmn.mnc[0] != 0xF)
              nCell->plmn.mncLength++;

        }
        if(strcmp(name, "SI-3-Serving-Cell-Mnc[1]")==0)
        {
        	nCell->plmn.mnc[1] = atoi(value) ;
            if(nCell->plmn.mnc[1] != 0xF)
              nCell->plmn.mncLength++;

        }
        if(strcmp(name, "SI-3-Serving-Cell-Mnc[2]")==0)
        {
        	nCell->plmn.mnc[2] = atoi(value) ;
            if(nCell->plmn.mnc[2] != 0xF)
              nCell->plmn.mncLength++;
        }

        if(strcmp(name, "SI-3-Serving-Cell-Lac")==0)
        {
            if(compareGsmScanDataWithUserGivenData(&(nCell->plmn) , inPlmn) == TRUE)
        	{
        		tOCT_UINT8 dupLac = FALSE;
        		for(i=0; i<MAX_NO_OF_SERVING_CELLS_PER_PLMN ; i++)
        		{
        			if(lacArr[i] == 0)
        			{
        				for(j=0; j<i; j++)
        				{
        					if(atoi(value) == lacArr[j])
        					{
        						dupLac = TRUE;
        						break;
        					}
        				}
        				if(dupLac == TRUE)
        				{
        					lacArr[i] = 0;
        					break;
        				}
        				else
        				{
        					lacArr[i] = atoi(value);
        				}
        			}

        		}
        	}
        	//logPrint(LOG_DEBUG , "Added Serving-Cell-LAC = %d \n" , atoi(value));
        }

        if((strcmp(name, "SI-2-Neighbor-Cell-ARFCN")==0)    ||
           (strcmp(name, "SI-2bis-Neighbor-Cell-ARFCN")==0) ||
           (strcmp(name, "SI-2ter-Neighbor-Cell-ARFCN")==0))
        {
        	if(nCell->noOfNeighborCells < GERAN_ARFCN_LIST_LENGTH)
        	{
        		duplicate = FALSE;
				tOCT_UINT16 tempArfcn;

                tempArfcn = atoi(value);

                // Skip the current serving cell arfcn
                if(servingCellArfcn != tempArfcn)
        		{
        		    // Also skip all other serving cell arfcns of this PLMN and also the arfcns without PLMN data
        		    for(j= 0; j< MAX_NO_OF_SERVING_CELLS_PER_PLMN; j++)
                    {            
                        if((inPlmnServingCellArfcn[j] == tempArfcn) || (servingArfcnsWoPlmnData[j] == tempArfcn) )
                        {
                            duplicate = TRUE;
        			        break;
                        }
                    }
                    if(duplicate == FALSE)
                    {    			
        			    // check if this cell is there in the list or not , don't add duplicate
        			    for(i= 0; i< nCell->noOfNeighborCells; i++ )
            			{
            				if(tempArfcn == nCell->arfcnArr[i])
            				{
                                duplicate = TRUE;
        				        break;
            				}
            			}
        			    if(duplicate == FALSE)// ALready added serving cell
                        {                
                            nCell->arfcnArr[nCell->noOfNeighborCells] = tempArfcn;
        				    nCell->noOfNeighborCells++;
                            //logPrint(LOG_DEBUG , "Added Neighbor-Cell-ARFCN = %d \n" , atoi(value));
                        }
                    }
                }
        	}
        }
    } // End of while loop

	// Now add the last node
	if((nCell->plmn.mccLength != 0)&&(nCell->plmn.mncLength != 0)&&(nCell->arfcnArr[1] != END_OF_LIST))
	{
        if(compareGsmScanDataWithUserGivenData(&(nCell->plmn) , inPlmn) == TRUE)
		{
    		if(inPlmnServingCellArfcnCount < MAX_NO_OF_SERVING_CELLS_PER_PLMN)
            {      
                inPlmnServingCellArfcn[inPlmnServingCellArfcnCount++] = servingCellArfcn;

    			for(i = 0; i< nCell->noOfNeighborCells ; i++)
    			{
    				if(neighCellIndex < MAX_SIZE_OF_SEARCH)
    				storedArfcnArr[neighCellIndex++] = nCell->arfcnArr[i];
    			}
            }
		}
	}

    /* Check the stored array to check if any of the serving cells of the selected PLMN exist */

    duplicate = FALSE;
    for(i = 0; i < neighCellIndex;)
    {
        for(j = 0; j < inPlmnServingCellArfcnCount; j++)
        {
            if (storedArfcnArr[i] == inPlmnServingCellArfcn[j])
            {
                /* Serving cell found in stored array,
                 * Move the last entry in the list to current
                 * entry and decrement the entry count by 1 
                 */
                if(neighCellIndex != 1)
                  storedArfcnArr[i] = storedArfcnArr[neighCellIndex - 1];
                neighCellIndex--;

                duplicate = TRUE;
                break; 
            }
        }
    	
        if(duplicate)
        {
            duplicate = FALSE;
        }
        else
          i++;
    }
    
    duplicate = FALSE;
    for(i = 0; i < neighCellIndex;)
    {
        for(j = 0; j < numOfServingArfcnsWoPlmnData; j++)
        {
            if (storedArfcnArr[i] == servingArfcnsWoPlmnData[j])
            {
                /* Arfcn without PLMN data is found in stored array,
                 * Move the last entry in the list to current
                 * entry and decrement the entry count by 1 
                 */
                if(neighCellIndex != 1)
                  storedArfcnArr[i] = storedArfcnArr[neighCellIndex - 1];
                neighCellIndex--;

                duplicate = TRUE;
                break; 
            }
        }
    	
        if(duplicate)
        {
            duplicate = FALSE;
        }
        else
          i++;
    }

    /* Special Case: Only one cell found in the PLMN with no neighbors, 
     * select the serving cell in this case
     */
    if(neighCellIndex == 0 && inPlmnServingCellArfcn[0] != 0xFFFF)
    {
        storedArfcnArr[neighCellIndex++] = inPlmnServingCellArfcn[0];
    }
    selectDistintLacFromParsedData(lacArr , Lac);
    //logPrint(LOG_DEBUG , "selectDistintLacFromParsedData Selected LAC = %d\n" , *Lac );
  
    /* Close file */
	if (fp)
	{
    	fclose (fp);
		fp = NULL;
	}
	
    free(buff);
    buff = NULL;
    free(nCell);
    nCell = NULL;
    return 0;
}

void selectCleanChannelFromParsedData(tOCT_UINT16 *commonArfcn , tOCT_UINT8* mappedBand)
{
	tOCT_UINT16 i, j , k = 0 , l = 0 , common = 0;
	//logPrint(LOG_DEBUG , "Number of Neighbor cells found = %d\n" , neighCellIndex);
	for(i = 0; i < neighCellIndex; i++)
	{
		for(j = i+1; j < neighCellIndex; j++)
		{
		  if(storedArfcnArr[i] == storedArfcnArr[j])
		  {
			  l++;
		  }
		}
		if(l > k)
		{
			common = i;
			k = l;
		}
		l = 0;

		//logPrint(LOG_DEBUG , "Neighbor ARFCN found = %d\n" , storedArfcnArr[i]);
	}

	*commonArfcn = storedArfcnArr[common];
	if((((storedArfcnArr[common])>=0) && ((storedArfcnArr[common])<=124)) || (((storedArfcnArr[common])>=975) && ((storedArfcnArr[common])<=1023)))
	{
		*mappedBand = E_GSM;
	}
	else if(((storedArfcnArr[common])>=128) && ((storedArfcnArr[common])<=251))
	{
		*mappedBand = GSM_850;
	}
	else if(((storedArfcnArr[common])>=259) && ((storedArfcnArr[common])<=293))
	{
		*mappedBand = GSM_450;
	}
	else if(((storedArfcnArr[common])>=955) && ((storedArfcnArr[common])<=974))
	{
		*mappedBand = R_GSM;
	}
	else if(((storedArfcnArr[common])>=811) && ((storedArfcnArr[common])<=885))
	{
		*mappedBand = DCS_1800;
	}
	else if(((storedArfcnArr[common])>=512) && ((storedArfcnArr[common])<=810))
	{
		//Either FXL_BAND_DCS_1800 or FXL_BAND_PCS_1900

		*mappedBand = DCS_1800;
		if((band[0] == cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_PCS_1900) || 
		   (band[1] == cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_PCS_1900)) // Either of band should match to PCS1900
		*mappedBand = PCS_1900;
	}

	free(storedArfcnArr);
	storedArfcnArr = NULL;
	neighCellIndex = 0;
}

tOCT_UINT8 compareGsmScanDataWithUserGivenData(fxL2gPlmn *scanDataPlmn , fxL2gPlmn* configuredPlmn)
{
	tOCT_UINT8 ret = FALSE;
	if((scanDataPlmn->mcc[0] == configuredPlmn->mcc[0]) && (scanDataPlmn->mcc[1] == configuredPlmn->mcc[1])
	   && (scanDataPlmn->mcc[2] == configuredPlmn->mcc[2])	&& (scanDataPlmn->mnc[0] == configuredPlmn->mnc[0])
	   && (scanDataPlmn->mnc[1] == configuredPlmn->mnc[1]))
	{
		if((scanDataPlmn->mncLength == 3) && (configuredPlmn->mncLength == 3))
		{
			if(scanDataPlmn->mnc[2] == configuredPlmn->mnc[2])
			{
				ret = TRUE;
			}
		}
		else if((scanDataPlmn->mncLength == 2) && (configuredPlmn->mncLength == 2))
		{
			ret = TRUE;
		}
	}
	return ret;

}


void selectDistintLacFromParsedData(tOCT_UINT16 *lArr , tOCT_UINT16* mappedLac)
{
	tOCT_UINT8 i = 0;

	*mappedLac = gsmCommRand(1, 65534); // Generate a random number in the range of LAC
    
	while(i < MAX_NO_OF_SERVING_CELLS_PER_PLMN)
	{
        /* Skip empty values */
        if(lArr[i] == 0)
        {
            i++;
            continue;
        }

        if(lArr[i] != *mappedLac)
		{
			i++;
		}
		else
		{
			*mappedLac = gsmCommRand(1, 65534); // Generate a random number in the range of LAC
			i = 0; // Restart the loop
		}
	}
	return;
}

