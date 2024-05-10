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
*       (c) FXLynx Technologies Ltd. 2015, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : gsmCommon.c
 *
* Description : Source file for common functions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#include "logManager.h"
#include "gsmCommon.h"
#include "ratSocketItf.h"

//tOCT_UINT8 timerTickReceived = FALSE;
//pthread_cond_t      condTimerTickInd  = PTHREAD_COND_INITIALIZER;
//pthread_mutex_t     mutexTimerTickInd = PTHREAD_MUTEX_INITIALIZER;
extern int exitGsmAppThreads;

/*
 * trim: get rid of trailing and leading whitespace...
 *       ...including the annoying "\n" from fgets()
 */
char * trim (char * s)
{
  /* Initialize start, end pointers */
  char *s1 = s, *s2 = &s[strlen (s) - 1];

  /* Trim and delimit right side */
  while ( (isspace (*s2)) && (s2 >= s1) )
    s2--;
  *(s2+1) = '\0';

  /* Trim left side */
  while ( (isspace (*s1)) && (s1 < s2) )
    s1++;

  /* Copy finished string */
  strcpy (s, s1);
  return s;
}

#if 0
/*
 * parse external parameters file
 *
 * NOTES:
 * - There are millions of ways to do this, depending on your
 *   specific needs.
 *
 * - In general:
 *   a) The client will know which parameters it's expecting
 *      (hence the "struct", with a specific set of parameters).
 *   b) The client should NOT know any specifics about the
 *      configuration file itself (for example, the client
 *      shouldn't know or care about it's name, its location,
 *      its format ... or whether or not the "configuration
 *      file" is even a file ... or a database ... or something
 *      else entirely).
 *   c) The client should initialize the parameters to reasonable
 *      defaults
 *   d) The client is responsible for validating whether the
 *      pararmeters are complete, or correct.
 */
int parseConfig (struct parameters * parms)
{
  errno = 0;
  char *s, buff[256];
  char path[] = "bts.cfg";
  FILE *fp = fopen(path, "r");
  if (fp == NULL)
  {
    return -1;
  }

  /* Read next line */
  while ((s = fgets (buff, sizeof buff, fp)) != NULL)
  {
    /* Skip blank lines and comments */
    if (buff[0] == '\n' || buff[0] == '#')
      continue;

    /* Parse name/value pair from line */
    char name[MAXLEN], value[MAXLEN];
    s = strtok (buff, "=");
    if (s==NULL)
      continue;
    else
      strncpy (name, s, MAXLEN);
    s = strtok (NULL, "=");
    if (s==NULL)
      continue;
    else
      strncpy (value, s, MAXLEN);
    trim (value);

    /* Copy into correct entry in parameters struct */
    if (strcmp(name, "MCC")==0)
      parms->MCC = atoi(value) ;
    else if (strcmp(name, "MNC")==0)
      parms->MNC = atoi(value);
    else if (strcmp(name, "BAND")==0)
      parms->BAND = atoi(value);
    else if (strcmp(name, "ARFCN")==0)
      parms->ARFCN = atoi(value);
    else if (strcmp(name, "CI")==0)
      parms->CI = atoi(value);
    else if (strcmp(name, "LAC")==0)
      parms->LAC = atoi(value);
    else if (strcmp(name, "TSC")==0)
      parms->TSC = atoi(value);
    else if (strcmp(name, "BSIC")==0)
      parms->BSIC = atoi(value);
    else if (strcmp(name, "TRX")==0)
      parms->TRX = atoi(value);
    else if (strcmp(name, "TRX0_TS0")==0)
      strncpy (parms->TRX0_TS0, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS1")==0)
      strncpy (parms->TRX0_TS1, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS2")==0)
      strncpy (parms->TRX0_TS2, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS3")==0)
      strncpy (parms->TRX0_TS3, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS4")==0)
      strncpy (parms->TRX0_TS4, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS5")==0)
      strncpy (parms->TRX0_TS5, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS6")==0)
      strncpy (parms->TRX0_TS6, value, MAXLEN);
    else if (strcmp(name, "TRX0_TS7")==0)
      strncpy (parms->TRX0_TS7, value, MAXLEN);
    else if (strcmp(name, "BTS_TYPE")==0)
    	parms->TYPE = atoi(value);
    else
    {}
  }

  /* Close file */
  fclose (fp);
  return 0;
}
#endif /* #if 0 */

void initializeConfigUeIdList(ConfigList * list)
{
	tOCT_UINT8 *sharedMemPtr  = NULL;    
    ConfigList *tmpConfigList = NULL;

	sharedMemPtr  = getAccessToIdList();
    tmpConfigList = (ConfigList *)(sharedMemPtr);

	list->configId = (IdentityConfigStr *) (sharedMemPtr + CONFIG_DATA_SIZE);

    list->defaultConfig = tmpConfigList->defaultConfig;
    list->numbOfIds     = tmpConfigList->numbOfIds;

	releaseAccessToIdList(sharedMemPtr);
}

#if 0
int parseImsilistConfig(ConfigList * list)
{
  errno = 0;
  char *s, buff[256];
  char path[] = "id.cfg";
  tOCT_UINT8 *sharedMemPtr = NULL;
  FILE *fp = fopen(path, "r");
  if (fp == NULL)
  {
    return -1;
  }

  sharedMemPtr = getAccessToIdList();
  memcpy((tOCT_UINT8*)sharedMemPtr , (tOCT_UINT8*)list , CONFIG_DATA_SIZE); //=4 :-configType(1)+IdentityType(1)+numbOfIds(2)
  list->id = (char (*)[MAX_IDENTITY_LENGTH_STR]) (sharedMemPtr + CONFIG_DATA_SIZE);
  /* Read next line */
  while ((s = fgets (buff, sizeof buff, fp)) != NULL)
  {
    /* Skip blank lines and comments */
    if (buff[0] == '\n' || buff[0] == '#')
      continue;

    /* Parse name/value pair from line */
    char name[MAXLEN], value[MAXLEN];
    s = strtok (buff, "=");
    if (s==NULL)
      continue;
    else
      strncpy (name, s, MAXLEN);
    s = strtok (NULL, "=");
    if (s==NULL)
      continue;
    else
      strncpy (value, s, MAXLEN);
    trim (value);

    /* Copy into correct entry in parameters struct */
    if (strcmp(name, "CONFIGURATION_TYPE")==0)
    {
    	if(strcmp(value, "WHITELIST")==0)
    	{
    		list->configType = WHITELIST;
    	}

    	else if(strcmp(value, "BLACKLIST")==0)
    	  list->configType = BLACKLIST;

    	else
    	{
    	    logPrint(LOG_ERR, "ERROR: Please mention valid Configuration type\n");
    	    return -1;
    	}
    }

    else if (strcmp(name, "TYPE_OF_IDENTITY")==0)
    {
    	if(strcmp(value, "IMSI")==0)
          list->IdentityType = IMSI;

    	else if(strcmp(value, "IMEI")==0)
    	{
			list->IdentityType = IMEI;
		}

    	else
    	{
    	    logPrint(LOG_ERR, "ERROR: Please mention valid Identity type\n");
    	    return -1;
    	}
    }

    else if (strcmp(name, "NUM_OF_IDENTITIES")==0)
      {
    	list->numbOfIds = atoi(value);
    	logPrint(LOG_DEBUG, "No. Of entries in id.cfg file = %d\n",list->numbOfIds );
      }

    else if (strcmp(name, "IDENTITY-1")==0)
    {
      strncpy (&(list->id[0][0]), value, MAX_IDENTITY_LENGTH_STR);
    }
    else if (strcmp(name, "IDENTITY-2")==0)
    {
      strncpy (&(list->id[1][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-3")==0)
    {
      strncpy (&(list->id[2][0]), value, MAX_IDENTITY_LENGTH_STR);
    }
    else if (strcmp(name, "IDENTITY-4")==0)
    {
      strncpy (&(list->id[3][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-5")==0)
    {
      strncpy (&(list->id[4][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-6")==0)
    {
      strncpy (&(list->id[5][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-7")==0)
    {
      strncpy (&(list->id[6][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-8")==0)
    {
      strncpy (&(list->id[7][0]), value, MAX_IDENTITY_LENGTH_STR);
    }
    
    else if (strcmp(name, "IDENTITY-9")==0)
    {
      strncpy (&(list->id[8][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-10")==0)
    {
      strncpy (&(list->id[9][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-11")==0)
    {
      strncpy (&(list->id[10][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-12")==0)
    {
      strncpy (&(list->id[11][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-13")==0)
    {
      strncpy (&(list->id[12][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-14")==0)
    {
      strncpy (&(list->id[13][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-15")==0)
    {
      strncpy (&(list->id[14][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-16")==0)
    {
      strncpy (&(list->id[15][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-17")==0)
    {
      strncpy (&(list->id[16][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-18")==0)
    {
      strncpy (&(list->id[17][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-19")==0)
    {
      strncpy (&(list->id[18][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-20")==0)
    {
      strncpy (&(list->id[19][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-21")==0)
    {
      strncpy (&(list->id[20][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-22")==0)
    {
      strncpy (&(list->id[21][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-23")==0)
    {
      strncpy (&(list->id[22][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-24")==0)
    {
      strncpy (&(list->id[23][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-25")==0)
    {
      strncpy (&(list->id[24][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-26")==0)
    {
      strncpy (&(list->id[25][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-27")==0)
    {
      strncpy (&(list->id[26][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-28")==0)
    {
      strncpy (&(list->id[27][0]), value, MAX_IDENTITY_LENGTH_STR);
    }
    
    else if (strcmp(name, "IDENTITY-29")==0)
    {
      strncpy (&(list->id[28][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-30")==0)
    {
      strncpy (&(list->id[29][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-31")==0)
    {
      strncpy (&(list->id[30][0]), value, MAX_IDENTITY_LENGTH_STR);
    }

    else if (strcmp(name, "IDENTITY-32")==0)
    {
      strncpy (&(list->id[31][0]), value, MAX_IDENTITY_LENGTH_STR);
    }
    else
    {
        if(list->numbOfIds > MAX_NO_OF_IDS)
        {
            logPrint(LOG_ERR, "Number of Identities is Invalid\n");
            return -1;
        }
    }
  }

  logPrint (LOG_DEBUG, "\nParsing done.\n\n");
  logPrint (LOG_INFO, "\nID Catcher Configuration Details...\n");
  logPrint (LOG_INFO, "\nConfiguration Type = %s\n", list->configType == 0 ? "WHITELIST" : "BLACKLIST");
  logPrint (LOG_INFO, "\nIdentity Type = %s\n", list->IdentityType == 0 ? "IMSI" : "IMEI");
  logPrint (LOG_INFO, "\nNumber of Identities configured = %d\n", list->numbOfIds);

  for(int i=0; i<list->numbOfIds; i++)
  {
      logPrint (LOG_INFO, "%d - %s\n", i+1, &(list->id[i][0]));
  }

  /* Close file */
  fclose (fp);
  releaseAccessToIdList(sharedMemPtr);
  return 0;
}

#endif /* #if 0 */

/* Decode and store Mobile Identity
 * We get Mobile Identity in a BCD coded format (two digits / byte and
 * digits in "backwards order". Additionally last four bits of the first
 * byte contain odd/even indication and type of identity.
 * Thus we get IMSI 123456789012345 in the following format:
 * 1x 32 54 76 98 10 32 54, where x is odd/even indication and type of
 * identity.
 */

void bcd2str(tOCT_UINT8* bcd, char* str, tOCT_UINT8 isMsIsdn)
{
    tOCT_UINT8 i = 0, len = 0, maxlen = 0, currIndex = 0;

	if(bcd[0] != 0)
	{
		if(isMsIsdn == TRUE)
		{
			len = bcd[0] - 1;
			currIndex = 2;
		}
		else
		{
			len = bcd[0];
			currIndex = 1;
		}

		maxlen = (((len * 2) -1) < (MAX_IDENTITY_LENGTH_STR -1)) ? (len * 2) : (MAX_IDENTITY_LENGTH_STR -1);

		for (i = 0; i < maxlen; i++)
		{
			if( currIndex <= bcd[0] && (((isMsIsdn == FALSE) && (0 == i % 2)) || ((isMsIsdn == TRUE) && (0 != i % 2))) )
			{
				if((isMsIsdn == TRUE) &&((bcd[currIndex] & 0xF0) == 0xF0) ) // Odd digit MsIsdn
				{
                    str[i] = '\0';
				}
				else
				{
                    str[i] = (((bcd[currIndex] & 0xF0) >> 4) + '0');
				}
				currIndex++;
			}
			else
			{
				str[i] = ((bcd[currIndex] & 0x0F) + '0');
			}
		}
		str[i] = '\0';
	}
    return;
}

tOCT_UINT8 getImeiCheckDigit(char *imeiStr)
{
    int sum = 0, i = 0, alt = 1, curDigit = 0;
    tOCT_UINT8 retVal = 0;

    for (i = strlen(imeiStr) - 2; i >= 0; i--)
    {
        curDigit = imeiStr[i] - '0';

        if (alt)
        {
            curDigit *= 2;
            if (curDigit > 9)
                curDigit -= 9;
            alt = 0;
        }
        else
        {
            alt = 1;
        }
        sum += curDigit;

    }
    if ((sum % 10) == 0 )
    {
    	retVal = 0;
    }
    else
    {
        retVal = (10 - (sum % 10));
    }
    return(retVal + '0');
}

fxlUePositioningError decodeGpsParameters(tOCT_UINT8 * buf, fxlUePositioningInfo * gpsInfo)
{
    fxlUePositioningError retVal = FXL_UE_POS_ERR_UNDEFINED;
	tOCT_UINT8  indx = 0;
	tOCT_UINT16 refFrame = 0;
	tOCT_UINT32 gpsTow = 0;
	tOCT_UINT32 lattitude = 0;
	tOCT_INT32  longitude = 0;

	if((buf[1] & 0x04) == 0x04)
	{
		logPrint(LOG_DEBUG ,"RRLP - Location Error Present");

        tOCT_UINT8 locError = 0;
        locError = (buf[2] & 0x3C) >> 2;

        switch(locError)
        {
            case 2: /* notEnoughSats */
            {
                logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : Location ERROR = Not Enough Satellites");
                retVal = FXL_UE_POS_ERR_NOT_ENOUGH_GPS_SATELLITE;
            }
            break;

            case 5: /* gpsLocCalAssDataMissing */
            case 6: /* gpsAssDataMissing */
            {
                logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : Location ERROR = GPS Assistant Data Missing");
                retVal = FXL_UE_POS_ERR_ASSISTANCE_DATA_MISSING;
            }
            break;

            case 7: /* methodNotSupported */
            {
                logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : Location ERROR = Method Not Supported");
                retVal = FXL_UE_POS_ERR_METHOD_NOT_SUPPORTED;
            }
            break;
            
            default:
            {
                logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : Location ERROR Code = %d" , ((buf[2] & 0x3C) >> 2));
            }
            break;
        }
	}
	else if((buf[1] & 0x10) == 0x10)
	{
		logPrint(LOG_DEBUG ,"RRLP - Location Information Present");

        refFrame = buf[2];
        refFrame = (refFrame << 8) + buf[3];
        logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : RefFrame = %d\n", refFrame);

        if((buf[1]&0x01) != 0)
        {
            logPrint(LOG_INFO ,"RRLP - GpsTow Parameter is present\n");
            gpsTow = buf[4];
            gpsTow = (gpsTow << 8) + buf[5];
            gpsTow = (gpsTow << 8) + buf[6];
            logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : GpsTow = %d\n", gpsTow);
            indx = 7;
        }
        else
        {
            logPrint(LOG_DEBUG ,"RRLP - GpsTow Parameter is NOT present\n");
            indx = 4;
        }

        if((buf[indx]&0x80) != 0)
        {
            logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : FixType = 3D \n");
        }
        else
        {
            logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : FixType = 2D \n");
        }

        lattitude = (buf[indx] & 0x03); // 2 MSB bits
        lattitude = lattitude  << 8;
        lattitude = lattitude + buf[indx+1];
        lattitude = lattitude << 8;
        lattitude = lattitude + buf[indx+2];
        lattitude = lattitude << 8;
        lattitude = lattitude + buf[indx+3];
        lattitude = lattitude << 6;
        lattitude = lattitude + (buf[indx+4] >> 2);
        logPrint(LOG_INFO ,"RRLP - Lattitude = %x \n" , lattitude);

        lattitude = lattitude & 0x007FFFFF;
        gpsInfo->gpsLocation.latitude = (float)((float)lattitude * latconst2 / latconst1);

        if((lattitude & latconst1) != 0 )
        {
            /* Sign of Lattitude is 1(i.e., South), change the sign */            
            gpsInfo->gpsLocation.latitude *= -1;
        }

        logPrint(LOG_DEBUG ,"RRLP - getGpsParameters : Lattitude = %f %c\n" , gpsInfo->gpsLocation.latitude);


        longitude = (buf[indx+4] & 0x03); // 2 MSB bits
        longitude = longitude  << 8;
        longitude = longitude + buf[indx+5];
        longitude = longitude << 8;
        longitude = longitude + buf[indx+6];
        longitude = longitude << 6;
        longitude = longitude + (buf[indx+7] >> 2);

        /* longitude is coded in 2's complement binary on 24 bits, so check for sign */
        if((longitude & 0x00800000) > 0)
            longitude |= 0xFF000000;
        else
            longitude &= 0x00FFFFFF;
        
        gpsInfo->gpsLocation.longitude = (float)((float)longitude * lonconst2 / lonconst1);

        if(gpsInfo->gpsLocation.longitude < 0)
        {
            if(gpsInfo->gpsLocation.longitude < -180)
            {
                gpsInfo->gpsLocation.longitude = (float)(gpsInfo->gpsLocation.longitude + 360);
            }
        }
        else
        {
            if(gpsInfo->gpsLocation.longitude > 180)
            {
                gpsInfo->gpsLocation.longitude = (float)(gpsInfo->gpsLocation.longitude - 360);
            }
        }
        
        logPrint(LOG_DEBUG,"RRLP - getGpsParameters : Longitude = %f\n" , gpsInfo->gpsLocation.longitude);

        gpsInfo->gpsFixType           = FXL_GPS_FIX_2D;
        gpsInfo->gpsLocation.altitude = 0;
        
		retVal = FXL_UE_POS_ERR_NONE;
	}
	else
	{
		logPrint(LOG_DEBUG ,"RRLP - Other GPS Information Present");
        //logPrint(LOG_DEBUG ,"RRLP - Some other ERROR present in the message Error = %d\n" , buf[1]);
	}

    return retVal;
}

/* ========================================================================= */

/*  7.23  */

/* Functional description
 */
/* CONFIDENTIAL
 * Returns a random value in range: [lower - upper]
 * Note: rand() function is defined in
 *       coresw/libraries/nmprtlib.c
 */
/*
 * Parameters
 *
 lower
 upper
 *
 *
 * Return values
 *
 * Random number in specified range.
 */

/* ---------------------------------------------------------------------- */

tOCT_UINT16 gsmCommRand( tOCT_UINT16 lower, tOCT_UINT16 upper )
{
    tOCT_UINT16 return_value;

    if ( upper >= lower )
    {
        return_value = ( ( tOCT_UINT16 )
            ( lower + ( rand() % ( ( upper - lower ) + 1 ) ) ) );
    }
    else
    {
		/*
		 * Faulty input parameters
		 */
		logPrint(LOG_ERR,"gsmCommRand: Improper range\n" );
		return_value = lower;
    }
    return return_value;
}

char l3PduString[(2 * GSM_L3_MSG_MAX_SIZE) + 1];
char * gsmL3PduHexdump(tOCT_UINT8 *l3Pdu, tOCT_UINT8 l3PduLen)
{
    tOCT_UINT8 i;

    if(l3PduLen > GSM_L3_MSG_MAX_SIZE)
    {
        return NULL;
    }
    else
    {
        memset(&l3PduString, 0, GSM_L3_MSG_MAX_SIZE+1);
        for(i = 0; i < l3PduLen; i++)
        {
            sprintf(l3PduString + strlen(l3PduString), "%02X",l3Pdu[i]);            
        }
        return l3PduString;
    }
}

#if 0
void * timerTickHandler(void *nothing)
{
	int ret = 0;
	logPrint(LOG_INFO , "timerTickHandler Thread Initialized\n");
    // main loop
    while(1)
    {
		pthread_mutex_lock(&mutexTimerTickInd);

		while (timerTickReceived != TRUE)
		pthread_cond_wait(&condTimerTickInd, &mutexTimerTickInd);
		
		if(exitGsmAppThreads)
		{
		    timerTickReceived = FALSE;
			pthread_mutex_unlock(&mutexTimerTickInd);
		    pthread_exit(NULL);
		}
		timerTickReceived = FALSE ;
		pthread_mutex_unlock(&mutexTimerTickInd);
		
		timerTick();
    }

    return (void*)ret;

}
#endif
