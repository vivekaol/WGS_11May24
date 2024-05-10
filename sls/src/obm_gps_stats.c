/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm_gps_stats.c

$Octasic_Copyright: $

Description:

Implementation of the GPS stats command

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/***************************  INCLUDE FILES  *********************************/

#include <string.h>
#include <stdio.h>

#include "../inc/obm.h"
#include "../inc/octvc1/obm/octvc1_obm_default.h"
#include "../inc/octvc1/obm/octvc1_obm_api_swap.h"
#include "../inc/octvc1/obm/octvc1_obm_evt_swap.h"
#include "../inc/octvc1/pkt_api/octvc1_pkt_api_default.h"
#include "fxLSocketInterfaceApi.h"

extern fxLGpsLocation idCatcherGpsLoc;
extern fxLGpsFixType  idCatcherGpsFix;

/***************************  PRIVATE FUNCTIONS  *****************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       GpsStatsCommand

Description:    Retrieves statistics for a given gps.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 GpsStatsCommand( int argc, char* argv[] )
{
    tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD	GpsStatsCmd;
    tOCTVC1_OBM_MSG_BOARD_STATS_GPS_RSP	GpsStatsRsp;
    tOCTVC1_PKT_API_CMD_EXECUTE_PARMS	CmdExecuteParms;
    tOCT_UINT32							ulResult = cOCTVC1_RC_OK;
    tOCT_BOOL32							fMonitor = cOCT_FALSE;
    tOCT_BOOL32							fVerbose = cOCT_FALSE;
	int									lOptRetval;
	unsigned 							i;

	/* Options parsing */
	while( (lOptRetval = OctGetOpt(argc, argv, cCOMMON_OPTIONS "mv")) >=0)
	{
		if(lOptRetval == '?') return -1;

		switch(optopt)
		{
			case 'm':
				fMonitor = cOCT_TRUE;
				break;

			case 'v':
				fVerbose = cOCT_TRUE;
				break;

			default:
				if( ProcessCommonOptions() < 0 )
				{
					ulResult = cOCTVC1_GENERIC_RC_BAD_PARAM;
					goto ErrorHandling;
				}
		}
	}

    /*
     * Init the API component we depend on.
     */
	ulResult = InitPktApi();
    if (cOCTVC1_RC_OK != ulResult)
    {
        return ulResult;
    }

    /*
     * Prepare command data.
     */
    mOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD_DEF(&GpsStatsCmd);
	GpsStatsCmd.ulBoardIndex = g_Context.ulBoardId;

	mOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD_SWAP(&GpsStatsCmd);

    /* 
     * Execute the command.
     */
    mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF(&CmdExecuteParms);
    CmdExecuteParms.pCmd           = &GpsStatsCmd;
    CmdExecuteParms.pRsp           = &GpsStatsRsp;
    CmdExecuteParms.ulMaxRspLength = sizeof(GpsStatsRsp);
	while( 1 )
	{
		unsigned ulCursorLineCount = 0;
	ulResult = OctVc1PktApiSessCmdExecute(g_Context.pPktApiSession, &CmdExecuteParms);
    if (cOCTVC1_RC_OK != ulResult)
    {
        goto ErrorHandling;
    }

    /*
     * Swap the command response.
     */
    mOCTVC1_OBM_MSG_BOARD_STATS_GPS_RSP_SWAP(&GpsStatsRsp);

    /*
     * Save the GPS Data.
     */
    if(cOCTVC1_OBM_GPS_FIX_ENUM_NONE == GpsStatsRsp.ulFix)
    {
        idCatcherGpsFix = FXL_GPS_FIX_NONE;
    }
    else if (cOCTVC1_OBM_GPS_FIX_ENUM_2D == GpsStatsRsp.ulFix)
    {
        idCatcherGpsFix = FXL_GPS_FIX_2D;
    }
    else if (cOCTVC1_OBM_GPS_FIX_ENUM_3D == GpsStatsRsp.ulFix)
    {
        idCatcherGpsFix = FXL_GPS_FIX_3D;
    }
    else
    {
        idCatcherGpsFix = FXL_GPS_FIX_NONE;
    }

    /*
     * To calculate decimal degrees, we use the DMS to decimal degree formula below:
     * Decimal Degrees = degrees + (minutes/60) + (seconds/3600)
    */

    idCatcherGpsLoc.latitude   = (float)((GpsStatsRsp.Location.Latitude.ulDegrees) + ((float)((float)GpsStatsRsp.Location.Latitude.ulMinutes/10000) / 60));
    if (cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_SOUTH == GpsStatsRsp.Location.Latitude.ulDirection)
    {
       /* Change sign if direction is South */
       idCatcherGpsLoc.latitude *= -1;
    }

    idCatcherGpsLoc.longitude   = (float)((GpsStatsRsp.Location.Longitude.ulDegrees) + ((float)((float)GpsStatsRsp.Location.Longitude.ulMinutes/10000) / 60));
    if (cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_WEST == GpsStatsRsp.Location.Longitude.ulDirection)
    {
        /* Change sign if direction is West */
        idCatcherGpsLoc.longitude *= -1;
    }

    idCatcherGpsLoc.altitude = GpsStatsRsp.Location.ulAltitude;

    /*
     * Print out the retrieved statsrmation.
     */
		ulCursorLineCount = 11;
	printf("+-- BOARD %u, GPS %u STATISTICS ------------------------------------------------------\n", g_Context.ulBoardId, GpsStatsRsp.ulGpsId );
	printf("| Fix information       : %s\n",	mOCTVC1_OBM_GPS_FIX_TO_STRING(GpsStatsRsp.ulFix) );
	printf("| Date                  : %s %u, %u\n",	mOCTVC1_OBM_MONTHS_TO_STRING(GpsStatsRsp.DateTime.ulMonth), GpsStatsRsp.DateTime.ulDay, GpsStatsRsp.DateTime.ulYear );
	printf("| Time                  : %u:%02u:%02u\n",	GpsStatsRsp.DateTime.ulHour, GpsStatsRsp.DateTime.ulMinutes, GpsStatsRsp.DateTime.ulSeconds );
	printf("| Location\n" );
	printf("|  Latitude             : %u %.4f %s\n",	GpsStatsRsp.Location.Latitude.ulDegrees, (float)GpsStatsRsp.Location.Latitude.ulMinutes/10000, mOCTVC1_OBM_CARDINAL_DIRECTION_TO_STRING(GpsStatsRsp.Location.Latitude.ulDirection) );
	printf("|  Longitude            : %u %.4f %s\n",	GpsStatsRsp.Location.Longitude.ulDegrees, (float)GpsStatsRsp.Location.Longitude.ulMinutes/10000, mOCTVC1_OBM_CARDINAL_DIRECTION_TO_STRING(GpsStatsRsp.Location.Longitude.ulDirection) );
	printf("|  Altitude             : %.1fM\n", (float)GpsStatsRsp.Location.ulAltitude / 10 );
	printf("| Num Active Satellites : %u\n",	GpsStatsRsp.ulNumActiveSatellite );
	if( GpsStatsRsp.ulNumActiveSatellite != 0 )
	{
		printf("| Satellites Id list    : " );
	}
	for( i=0; i<GpsStatsRsp.ulNumActiveSatellite; i++ )
	{
		if( i == GpsStatsRsp.ulNumActiveSatellite - 1 )
		{
			printf("%d\n", GpsStatsRsp.abyActiveSatelliteId[i] );
            ulCursorLineCount++;
		}
		else
		{
			printf("%d, ", GpsStatsRsp.abyActiveSatelliteId[i] );
			}
		}

		printf("|\n");
		printf("| Satellites in view    : %u\n",	GpsStatsRsp.ulSatellitesInView );
		if( GpsStatsRsp.ulSatellitesInView != 0 )
		{
			printf("|\n");
			printf("|    Id    |  SNR (dB)\n" );
			printf("|----------+----------\n" );
			ulCursorLineCount += 3;

			for( i=0; i<GpsStatsRsp.ulSatellitesInView; i++ )
			{
				printf("|   %3d    |    %2d\n",	GpsStatsRsp.SatelliteInViewInfo[i].u8Id,
												GpsStatsRsp.SatelliteInViewInfo[i].u8Snr );
				ulCursorLineCount++;
			}
		}

		printf("|\n\n");
		ulCursorLineCount += 2;

		if( fVerbose == cOCT_FALSE )
		{
			break;
		}

		// Wait for 300 ms
		OctOsalSleepMs(300);

		/* VT100 Cursor control
		- Cursor Home:		\x1B[{ROW};{COLUMN}H	or		\x1B[H
		- Cursor up:		\x1B[{ROW}A
		- Cursor down:		\x1B[{ROW}B
		- Cursor Forward:	\x1B[{COLUMN}C
		- Cursor Backward:	\x1B[{COLUMN}D
		*/
		for( i=0; i<ulCursorLineCount; i++ )
		{
			printf("\x1B[2K");	// Erase Line
			printf("\x1B[A");	// Move cursor up by 1 line.
		}
	}

	if( fMonitor )
	{
		tOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EVT	GpsStateChangeEvent;
		tOCTVC1_PKT_API_INST_RECV_PARMS	InstReceiveParms;
		mOCTVC1_PKT_API_INST_RECV_PARMS_DEF( &InstReceiveParms )

		InstReceiveParms.RcvPktType = cOCTVC1_PKT_API_RCV_MASK_EVENT;
		InstReceiveParms.pPayload = &GpsStateChangeEvent;
		InstReceiveParms.ulMaxPayloadLength = sizeof(GpsStateChangeEvent);

		printf("Waiting for incoming GPS state change events; type ctrl-c to exit.\n" );

		do
		{
			ulResult = OctVc1PktApiInstRecv(g_Context.pPktApiInstance, &InstReceiveParms);

			if(	(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE) &&
				InstReceiveParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT &&
				InstReceiveParms.Info.Evt.ulEvtId == cOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EID )
			{
				mOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EVT_SWAP(&GpsStateChangeEvent)

				printf("+-- BOARD %u, GPS %u STATE CHANGE ------------------------------------------------------\n", g_Context.ulBoardId, GpsStateChangeEvent.ulGpsId );
				printf("| Previous Fix information : %s\n\n",	mOCTVC1_OBM_GPS_FIX_TO_STRING(GpsStateChangeEvent.ulPreviousFix) );
				printf("| New Fix information      : %s\n\n",	mOCTVC1_OBM_GPS_FIX_TO_STRING(GpsStateChangeEvent.ulNewFix) );
			}

		} while(ulResult == cOCTVC1_RC_OK || ulResult == cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE);
	}

    return ulResult;

ErrorHandling:

	ClosePktApi();

    return ulResult;
}

/* Command descriptor exported to the main OBM file */
tOBM_COMMAND_DESCRIPTOR g_GpsStatsCmd =
{	GpsStatsCommand,
	"gps_stats",
	"gs",
	"[-m] ",
	"Display detailed GPS statistics.",
	"\n"
	"Options\n"
	" -m : Monitor mode. Keep monitoring for reported GPS module events.\n"
	"\n"
};
