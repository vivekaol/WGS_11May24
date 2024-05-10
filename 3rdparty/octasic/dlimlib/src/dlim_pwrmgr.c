/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_pwrmgr.c

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "octtypes.h"
#include "dlim_pwrmgr_tables.h"


static sint16  gPcpichpwr;
static sint16  gMaxpwr;
static sint16  gPcpichlookup;

/******************************************************************************
 Function name: GetPcpichPowerWt
 Description  : This function returns the powerwt of pcpich

 Input param  : void
 Output param : void

 Return       : 
******************************************************************************/

void FASTCALL SetPcpichPower(REGISTER sint16 abspcpichpwr, REGISTER sint16 absmaxpwr)
{
	gPcpichpwr    = abspcpichpwr;
    gMaxpwr       = absmaxpwr;
	//gPcpichlookup = DL_POWERTABLE_SIZE - DL_MAXTXPWR_CPICH_RATIO - DL_POWER_ADJUSTMENT_FACTOR -  60 + gPcpichpwr;	
    gPcpichlookup = DL_POWERTABLE_SIZE - DL_POWER_ADJUSTMENT_FACTOR -  60 + (gPcpichpwr - absmaxpwr);	
	mASSERT_CTRAP((gPcpichlookup < 0)||(gPcpichlookup > (DL_POWERTABLE_SIZE+DL_POWER_TABLE_MARGIN)));
}

sint16 FASTCALL GetPcpichPowerWt(void)		
{	
	//P-CPICH powerwt
	return(PowerWeightTab[gPcpichlookup]);
}

sint16 FASTCALL GetPowerWt_Rel2Pcpich(REGISTER sint16 relchpwr)
{
	REGISTER sint16 lookup;
	REGISTER sint16 Powerwt;
	
	lookup = gPcpichlookup + relchpwr;	
	mASSERT_CTRAP((lookup < 0)||(lookup > (DL_POWERTABLE_SIZE+DL_POWER_TABLE_MARGIN)));
	Powerwt  = 	PowerWeightTab[lookup];
	
	return(Powerwt);
}

sint16 FASTCALL GetPowerTabIndex_Rel2Pcpich(REGISTER sint16 relchpwr)
{
	REGISTER sint16 lookup;	
	
	lookup = gPcpichlookup + relchpwr;	
	mASSERT_CTRAP((lookup < 0)||(lookup > (DL_POWERTABLE_SIZE+DL_POWER_TABLE_MARGIN)));
	
	return(lookup);
}
