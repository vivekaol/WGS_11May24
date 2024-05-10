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
* File Name   : lteUserManager.h
 *
* Description : Function to support add/delete/find user
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 09/02/2015          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#include <assert.h>
#include <string.h>
#include "logManager.h"
#include "lteUserManager.h"
#include "lteRlcEncDec.h"

static sint8 currentNoOfLteUsers = 0;
static lteUserInfo*  userDb[LTE_MAX_USER_SUPPORTED] = {NULL} ;
static lteUserInfo* srUserContext[LTE_MAX_USER_SUPPORTED] = {NULL};
lteUserInfo lteUsrContxts[LTE_MAX_USER_SUPPORTED];

extern uint16 bwToPrb[MAX_BANDWIDTH];
extern eLteBw lteSelectedBandwidth;
extern elteDupMode lteDuplxMode ;
//uint16 bwTophichgroups[MAX_BANDWIDTH] = {1,1,1,2,2,3}; // For Ng= 1/6th only
uint16 bwTophichgroups[MAX_BANDWIDTH] = {1,1,2,4,5,7}; // For Ng= 1/2th only


void lteUserManagerInit()
{
	uint8 j = 0;
	for ( j = 0; j < LTE_MAX_USER_SUPPORTED; j++ )
	{
	  userDb[j] = NULL;
	  srUserContext[j] = NULL;
	}
	currentNoOfLteUsers = 0;
	memset(lteUsrContxts , 0 , (sizeof(lteUserInfo)*LTE_MAX_USER_SUPPORTED));

        /* Set MAC State to LTE_NULL_STATE */
        for (j = 0; j < LTE_MAX_USER_SUPPORTED; j++)
        {
            lteUsrContxts[j].macLayerState = LTE_NULL_STATE;
            timerInit(&lteUsrContxts[j].tmr);
        }
}

void getNoOfUsers(uint8 *noOfActiveContext)
{
	*noOfActiveContext = currentNoOfLteUsers;
	return;
}

lteUserInfo* lteUserAdd()
{
	lteUserInfo* userInfo = NULL ;
    int crntiIdx = 0;
	unsigned char found = FALSE;
	
	if(currentNoOfLteUsers < LTE_MAX_USER_SUPPORTED)
	{
		for(crntiIdx = 0; crntiIdx < LTE_MAX_USER_SUPPORTED ; crntiIdx++)
		{
			if(lteUsrContxts[crntiIdx].inUse == FALSE)
			{
				userInfo = &lteUsrContxts[crntiIdx];
				userInfo->inUse = TRUE;
				found = TRUE;
				break;
			}
		}

		if (TRUE == found)
		{
			currentNoOfLteUsers++;

			userInfo->crnti = LTE_C_RNTI_START + crntiIdx;
			userInfo->macLayerState = LTE_RACH_RECEIVED;
			userInfo->ulHandle = LTE_C_RNTI_END - crntiIdx; // Generate some number

       		memset(&userInfo->cceIndex[0] , 0 , sizeof(uint8)*LTE_MAX_SUB_FRAME_NUMBER);
			userInfo->rlc_vrr              = 0;
			userInfo->rlc_vrmr             = userInfo->rlc_vrr + LTE_RLC_AM_WINDOW_SIZE;
			userInfo->rlc_vrh              = 0;
			userInfo->rlc_vta              = 0;
			userInfo->rlc_vtms             = userInfo->rlc_vta + LTE_RLC_AM_WINDOW_SIZE;
			userInfo->rlc_vts              = 0;
			userInfo->srConfigIndex	   	 = LTE_INVALID_SR_CONFIG_INDEX;
			userInfo->rssiIndex = 0;
			userInfo->phr_ulRssi = 0;
			memset(&userInfo->ulRssiArr[0] , 0 , sizeof(uint8)*LTE_MAX_SUB_FRAME_NUMBER);
			// Add to the user DB
			userDb[crntiIdx] = userInfo;
			//logPrint(LOG_INFO,"Lte User Added to List with CRNTI = %d \n" , userInfo->crnti);
		}
		else
		{
			logPrint(LOG_ERR, "All User Context is used, ENODEB is FULL = %d users\n", currentNoOfLteUsers);
			return NULL;
		}
	}
	else
	{
		logPrint(LOG_ERR, "No available CRNTI, ENODEB is FULL = %d users\n", currentNoOfLteUsers);
		return NULL;
	}

	return userInfo;
}

lteUserInfo* userFindUsingCrnti(uint16 crnti)
{
	lteUserInfo *info = NULL;
	if (( crnti - LTE_C_RNTI_START >= 0) && ((crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
	{
		info = userDb[(crnti - LTE_C_RNTI_START)];
	}
	return info;
}

lteUserInfo* getUserContext(uint8 index)
{
	lteUserInfo *info = NULL;
	if (index < LTE_MAX_USER_SUPPORTED)
	{
		info = userDb[index];
	}

	return info;
}

void userDeleteUsingCrnti(uint16 crnti , uint8 isiIFromSameThread)
{
	lteUserInfo *info = NULL;
	if (( crnti - LTE_C_RNTI_START >= 0) && ((crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
	{
		info = userDb[(crnti - LTE_C_RNTI_START)];
		if((info != NULL)&&(info->inUse == TRUE))
		{
			if(isiIFromSameThread == TRUE)
			{
				if((isTimerRunning(&info->tmr) == TRUE))
				{
					timerStop(&info->tmr);
				}
			}
#ifdef LTE_USE_SR
			if(info->srConfigIndex != LTE_INVALID_SR_CONFIG_INDEX)//SR started
			{
				assert(info->srConfigIndex < LTE_MAX_USER_SUPPORTED);
				srUserContext[info->srConfigIndex] = NULL;
			}
			info->srConfigIndex = LTE_INVALID_SR_CONFIG_INDEX;
#endif
			memset(info , 0 , sizeof(lteUserInfo));
			info->inUse = FALSE;
			userDb[(crnti - LTE_C_RNTI_START)] = NULL;
			currentNoOfLteUsers--;
			if(currentNoOfLteUsers <= 0)
			{
				currentNoOfLteUsers = 0;
		    }
		}
		//logPrint(LOG_DEBUG,"User Deleted for Crnti = %d \n" , crnti);
	}
	else
	{
		logPrint(LOG_ERR,"User Not Found for Crnti = %d\n" , crnti);
	}
	return;
}
#if 0
void populateCceIndex(lteUserInfo *userInfo)
{
	/*
	   CCE index = L*{(Yk + m')mod(Ncce/L)} + i
	   L = aggregation level
	   i = 0 to (Aggregation Level - 1)
	   Ncce = Number of CCE's available for PDCCH
	   m' = 0 to ( Number of PDCCH canditates -1 ) // PDCCH candidates NO_OF_PDCCH_CANDIDATES_FOR_AGG_LEVEL4 = 2

	   Yk = (A * Yk-1 ) mod D
		k = subframe number
	   Yk-1 = RNTI value for that UE, lets suppose its 100.

	   PHICH RE= PHICH Group *3*4
	   PHICH Group Calculation:

	   Number of PHICH groups = Mi * NPHICHgroup for TDD
	   Number of PHICH groups = NPHICHgroup  for FDD
	   NPHICHgroup = Integer (Ng * (Number of DL RBs/8)
	   where Ng {1/6,1/2,1,2} is provided by higher layers

	   Number of RS in 1-PRB = 4 so for 50 PRBS = 50*4
	 */

	uint8 idx = 0;
	/*uint16 Ncce = ((LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH * bwToPrb[lteSelectedBandwidth] * 12)  -
					(4*50 + 16 + 2*3*4)) / LTE_NO_OF_RE_IN_CCE ; //16 = No of RE for PCFICH // 2*3*4 = Ng = 1/6th and 3 bits for 4 REG //eFAPI_TX_ANTENNA_PORT_1
	Ncce = 43; // for 10Mhz */
	uint16 Ncce = ((LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH * (bwToPrb[lteSelectedBandwidth]) * 12)  -
					(LTE_NUMBER_OF_RS_IN_ONE_PRB*(bwToPrb[lteSelectedBandwidth]) + LTE_NUMBER_OF_RE_IN_PCFICH + (bwTophichgroups[lteSelectedBandwidth])*3*4)) / LTE_NO_OF_RE_IN_CCE ; //16 = No of RE for PCFICH // 2*3*4 = Ng = 1/6th and 3 bits for 4 REG //eFAPI_TX_ANTENNA_PORT_1
	uint32 Yk[11] = {0};

	Yk[0] = userInfo->crnti; // Yk-1 , subframe 0 = index 1
	for(idx = 1 ; idx < 11 ; idx++)
	{
		Yk[idx] = (CONSTAT_A_FOR_CALCULATING_CCE_INDEX * Yk[idx-1])%CONSTAT_D_FOR_CALCULATING_CCE_INDEX;
	}
	for(idx = 0 ; idx < 10 ; idx++)
	{
		userInfo->cceIndex[idx] = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU * ((Yk[idx+1] + (LTE_NO_OF_PDCCH_CANDIDATES_FOR_AGG_LVL_8 - 1))%(Ncce/LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU));
								 // + (LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU - 1); // this is first cce index
		//logPrint(LOG_DEBUG , "CceIndex = %d for Subframe No = %d\n" , userInfo->cceIndex[idx] , idx);
	}
}
#endif

#ifdef LTE_USE_SR
/*
 * SR configuration table is given below (Table 10.1.5-1 from 3GPP TS 36.213). SR transmission instances are
 * the uplink subframes satisfying (10*SFN + subframe ‒ Noffset,SR) mod SRperiodicity = 0.
 *
 * SR configuration Index(ISR) 		SR Periodicity(ms)(SRperiodicity)  		SR subframe offset (Noffset,SR)
 * 	0 - 4 									5										Isr
 * 	5 - 14									10										Isr - 5
 *  15 - 34									20										ISr - 15
 *  35 - 74									40										Isr - 35
 *  75 - 154								80										Isr - 75
 *  155 - 156								2										Isr - 155
 *  157										1										Isr - 157
 *
 */
uint8 checkIfSrSubframe(uint16 sfn , uint8 sbfn , uint8 srConfigIdx)
{
	uint8 srOpp = FALSE;
	if(((10*sfn+sbfn - (srConfigIdx - LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START))%LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY) == 0) // configured sr config index = 76
	srOpp = TRUE;

	return srOpp;
}
uint8 convertToRealSrConfigIndex(uint8 srConfigIndex)
{
	if(srConfigIndex >= 30) // 30 to 31
	{
		return (srConfigIndex - 30);
	}
	else if((srConfigIndex >= 20)&&(srConfigIndex < 30))//20 to 29
	{
		return (srConfigIndex - 20);
	}
	else if((srConfigIndex >= 10)&&(srConfigIndex < 20))//10 to 19
	{
		return (srConfigIndex - 10);
	}
	else //0 to 9
	{
		return srConfigIndex;
	}
}


void getLteSrConfigIndex(lteUserInfo *userInfo)
{
	uint8 i = 0;
	for(i =0 ; i<LTE_MAX_USER_SUPPORTED; i++)
	{
		if(srUserContext[i] == NULL)
		{
			break;
	    }
	}

	if(i == LTE_MAX_USER_SUPPORTED)
	{
		userInfo->srConfigIndex = LTE_INVALID_SR_CONFIG_INDEX;
	}
	else
	{
		userInfo->srConfigIndex = i ;
		srUserContext[i] = userInfo;
    }
	return;
}

lteUserInfo * getUserContextForSchedulingRequest(uint8 sbfn)
{
	assert(sbfn < LTE_MAX_USER_SUPPORTED);
	return (srUserContext[sbfn]);
}
uint8 convertToRealSrTddConfigIndex(uint8 srConfigIndex)
{
    if (srConfigIndex <4)
    {
	    return srConfigIndex*10 ;
    }
   else
    {
		 uint8 rem = srConfigIndex %4;
		 srConfigIndex = rem*10 ;

	     if (srConfigIndex >= LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY)
		 {
			srConfigIndex = srConfigIndex-LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY ;
		 }
	     return srConfigIndex;
	}

  
}
#endif

#define DLIM_PDCCH_NREG_ALLOC_TABLE_SIZE (4*3)
extern uint8 lteCheckTDDsubframe( uint16 sbfn );
//#define L1_COMMON_AGG_LEVEL (8)
//#define L1_UE_AGG_LEVEL (8)

uint8 dl_association_set[13][4] =
{
    {0x04, 0x0F, 0x0F,0x0F}, /* 0 [4]           */
    {0x07, 0x06, 0x0F,0x0F}, /* 1 [7,6]         */
    {0x08, 0x07, 0x04,0x06}, /* 2 [8,7,4,6]     */
    {0x07, 0x06, 0x0B,0x0F}, /* 3 [7,6,11]      */
    {0x06, 0x05, 0x0F,0x0F}, /* 4 [6,5]         */
    {0x05, 0x04, 0x0F,0x0F}, /* 5 [5,4]         */
    {0x0C, 0x08, 0x07,0x0B}, /* 6 [12,8,7,11]   */
    {0x06, 0x05, 0x04,0x07}, /* 7 [6,5,4,7]     */
    {0x0D, 0x0C, 0x09,0x08}, /* 8 [13,12,9,8]   */
    {0x07, 0x05, 0x04,0x0B}, /* 9 [7,5,4,11]    */
    {0x06, 0x0F, 0x0F,0x0F}, /* A [6]           */
    {0x07, 0x0F, 0x0F,0x0F}, /* B [7]           */
    {0x05, 0x0F, 0x0F,0x0F}, /* C [5]           */
};


const uint16 M_table[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] = {   
     {0xFF,0xFF,0xA1,0xFF,0x01,0xFF,0xFF,0xA1,0xFF,0x01},/* TDD CONFIG 0*/
     {0xFF,0xFF,0x12,0x01,0xFF,0xFF,0xFF,0x12,0x01,0xFF},/* TDD CONFIG 1*/
     {0xFF,0xFF,0x24,0xFF,0xFF,0xFF,0xFF,0x24,0xFF,0xFF},/* TDD CONFIG 2*/
     {0xFF,0xFF,0x33,0x42,0x52,0xFF,0xFF,0xFF,0xFF,0xFF},/* TDD CONFIG 3*/
     {0xFF,0xFF,0x64,0x74,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},/* TDD CONFIG 4*/
     {0xFF,0xFF,0x89,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},/* TDD CONFIG 5*/
     {0xFF,0xFF,0xB1,0xB1,0xC1,0xFF,0xFF,0xB1,0xB1,0xFF},/* TDD CONFIG 6*/
};

uint16 CalculateTddPucchIndex(lteUserInfo* userInfo , uint16 sfNsf)
{
	int Np = 0;
	int Npnext = 0;
	uint16 BW = bwToPrb[lteSelectedBandwidth];
	uint16 Ncce = 0;//userInfo->cceIndex[((LTE_MAX_SUB_FRAME_NUMBER + (sfNsf & 0x000F) - 4) % LTE_MAX_SUB_FRAME_NUMBER)];
	uint16 Npucch;
	uint8 sbf = (sfNsf & 0x000F);
	uint16 no_of_dl_subframe , starting_index, M ,m;
	uint8 dl_temp_index =0xFF;
	uint8 i , small_m , dl_alloc_idx;

	no_of_dl_subframe = M_table[LTE_TDD_UD_CONFIG][sbf]& 0x0F;
	starting_index = (M_table[LTE_TDD_UD_CONFIG][sbf] & 0xF0)>>4;    // Starting index is the first 4bits in M_table( Eg: for UD:2   starting index is : 2 so, from dl_association_set you will refer to second row)
	small_m = 2;
	Ncce = userInfo->cceIndex[((LTE_MAX_SUB_FRAME_NUMBER + (sfNsf & 0x000F) - userInfo->pucch_k) % LTE_MAX_SUB_FRAME_NUMBER)];
	for(i =0 ;i<no_of_dl_subframe;i++)
	{
		 dl_alloc_idx = (LTE_MAX_SUB_FRAME_NUMBER + sbf - dl_association_set[starting_index][i]) % LTE_MAX_SUB_FRAME_NUMBER;
		if(userInfo->dl_allocation[dl_alloc_idx])
		{
				// logPrint(LOG_DEBUG ,"userInfo->dl_allocation[%d] TRUE  \n", dl_alloc_idx);
		   if(dl_association_set[starting_index][i] < dl_temp_index)
			{
				Ncce = userInfo->cceIndex[((LTE_MAX_SUB_FRAME_NUMBER + (sfNsf & 0x000F) - userInfo->pucch_k) % LTE_MAX_SUB_FRAME_NUMBER)];
				small_m = i;
				dl_temp_index = dl_association_set[starting_index][i];
			}
		   userInfo->dl_allocation[dl_alloc_idx] = 0;
		}
	}
	
	M = no_of_dl_subframe;
	m = small_m;

	for(int p =0;p<=3;p++)
	{
		Npnext = (BW*((12*(p)) -4))/36;
		if(Npnext < 0)
			Npnext = 0;
		if((Np <= Ncce) && (Ncce < Npnext ))
		 break;
		Np = Npnext;
	}
	Npucch = (M-m-1)*Np + (m*Npnext)+Ncce+LTE_PUCCH_AN_TDD;
	//logPrint(LOG_DEBUG ,"m = %d , M = %d\n", m , M);
	//logPrint(LOG_DEBUG , "TDD PUCCH Index  = %d, Np = %d , Npnext = %d , NCCE = %d , orgin Ncce = %d , sfnsf = %04x \n",Npucch , Np , Npnext , Ncce , userInfo->cceIndex[(sfNsf & 0x000F)] , sfNsf );

	return Npucch;
}

//########### LTE CCE INDEX code ###############//

uint8  cce_map[LTE_MAX_SUB_FRAME_NUMBER][LTE_MAX_CCE_IDX];
void deallocateCceMap(uint8 subfn)
{
	memset(&cce_map[subfn], 0, sizeof(cce_map[0][0])*LTE_MAX_CCE_IDX);
	//logPrint(LOG_DEBUG ,"Deallocate of CCEMAP[%d] done \n", subfn);
	return;
}

const int l1cNregValues[6][DLIM_PDCCH_NREG_ALLOC_TABLE_SIZE] =
{
	{23,41,59,23,41,59,23,41,59,20,38,56}, //BW 1.4
	{23,68,113,23,68,113,20,65,110,14,59,104}, //BW 3
	{43,118,193,40,115,190,34,109,184,25,100,175},//BW 5
	{90,240,390,84,234,384,75,225,375,57,207,357},//BW 10
    {140,365,590,131,356,581,116,341,566,89,314,539}, //BW 15
	{187,487,787,175,475,775,157,457,757,121,421,721} //BW 20

};

const uint8 LteTDDPHICHMiTable[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] = 
{
	{2,	1,	0xFF,	0xFF,	0xFF,	2,	1,	0xFF,	0xFF,	0xFF},
	{0,	1,	0xFF,	0xFF,	1,		0,	1,	0xFF,	0xFF,	1},
	{0,	0,	0xFF,	1,		0,		0,	0,	0xFF,	1,		0},
	{1,	0,	0xFF,	0xFF,	0xFF,	0,	0,	0,		1,		1},
	{0,	0,	0xFF,	0xFF,	0,		0,	0,	0,		1,		1},
	{0,	0,	0xFF,	0,		0,		0,	0,	0,		1,		0},
	{1,	1,	0xFF,	0xFF,	0xFF,	1,	1,	0xFF,	0xFF,	1}
};

uint8 getFreeCceIndex(uint8 common_flag, uint16 rnti, uint16 sfnSf )
{
	uint32  Y_k , temp, cst, m;
	uint8   free_index, i, found_flag = FALSE, cnt;
	uint8   aggLevel , subframe_index =  (sfnSf & 0x000F);
	uint16  numreg;
	uint8   numcce;
	uint8 	current_cfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH;

	numreg = l1cNregValues[lteSelectedBandwidth][current_cfi-1];

	if(lteDuplxMode)
	{
		if (LTE_TDD_SSUBFRAME == lteCheckTDDsubframe(subframe_index))
			current_cfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH_TDD;
		if(0x0 == LteTDDPHICHMiTable[LTE_TDD_UD_CONFIG][subframe_index])
		{
			//only for Ng=1/6 , it should be extended for other Ng
			numreg += (3 * (bwTophichgroups[lteSelectedBandwidth]));
		}
		else if(0x2 == LteTDDPHICHMiTable[LTE_TDD_UD_CONFIG][subframe_index])
		{
			numreg -= (3 * (bwTophichgroups[lteSelectedBandwidth]));
		}
	}
	numcce = numreg/9;   

	if (common_flag == TRUE)
	{
		Y_k=0;
		if(lteSelectedBandwidth > LTE_BW_N15)
		{
			aggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS;
		}
		else
		{
			aggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS/2;
		}
		cst = numcce/aggLevel;
	}
	else
	{
		// First compute current Y_k value
		Y_k = rnti;
		for (i=0; i<(subframe_index+1); i++)
		{
			temp = (Y_k * CONSTAT_A_FOR_CALCULATING_CCE_INDEX);
			Y_k = (temp % CONSTAT_D_FOR_CALCULATING_CCE_INDEX);
		}
		if(lteSelectedBandwidth > LTE_BW_N15)
		{
			aggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
		}
		else
		{
			aggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
		}
		cst = (numcce/aggLevel);
	}
	assert(cst != 0);
	m = 0;
	found_flag = FALSE;
	if((lteSelectedBandwidth != LTE_BW_N6) &&
	  ((((((sfnSf>>4) & 0x0FFF) % LTE_SIB1_REPITION_FRAMES) == 0)&&(subframe_index == 5)) ||
	  (((((sfnSf>>4) & 0x0FFF) % LTE_SIBS_REPITITION_FRAMES) == 0)&&(subframe_index == 0))))
	{
		if(common_flag == FALSE)
		{
			m = 1; // Keep first slot for the SIB1 or SIBS in Cce map
		}
	}

	do
	{
		temp = (m+Y_k)%cst;
		free_index = temp*aggLevel;
		cnt = 0;
		for (i=free_index; i<free_index+aggLevel;i++)
		{
			if(cce_map[subframe_index][i] == 0)
			{
				cnt++;
			}
		}
		if (cnt == aggLevel)
		{
			found_flag = TRUE;
		}
		m = m+1;
		/////////////////////////////////////////////////////////////////////////
		if((lteSelectedBandwidth == LTE_BW_N6)&&(m > aggLevel))
		{
			logPrint(LOG_DEBUG ,"getFreeCceIndex Count =%d Value_M=%d FreeIndex=%d\n", cnt,m,free_index );
			return 0;
		}

                if(m >= 255)
                {
                        return 0;
                }
		/////////////////////////////////////////////////////////////////////////
	}while(found_flag == FALSE);

	if(found_flag == TRUE)
	{
		for (i = free_index; i<(free_index+aggLevel); i++)
		{
			cce_map[subframe_index][i] = 1;
		}
		return(free_index);
	}
	return(free_index);
}


uint8 CalculateLteCceIdx (uint8 isCmnSpace, uint16 rnti , uint16 sfnSf)
{
	return getFreeCceIndex(isCmnSpace,rnti,sfnSf);
}

