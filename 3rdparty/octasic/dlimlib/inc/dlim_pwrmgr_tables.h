/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_pwrmgr.c

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "octtypes.h"
#include "octccs.h"


#define DL_POWERTABLE_SIZE			   (500)
#define DL_POWERTABLE_STEP_SIZE        (0.1f)
#define DL_MAXTXPWR_CPICH_RATIO         (100)
#define DL_POWER_ADJUSTMENT_FACTOR      (41)
#define DL_CPICH_CAL_FACTOR             (0)//39
#define DL_POWER_TABLE_MARGIN           (10)

//WARNING: Power Weight Table Updated
// 0.1 dB Step Size
// Dyanmic Range = 50 dB
extern const sint16 PowerWeightTab[DL_POWERTABLE_SIZE+DL_POWER_TABLE_MARGIN+1];
    // Power Offset Table in Q.15 
    // Used for Power Offsetting of DPCCH and control part of SCCPCH (according to PO1, PO2, PO3) 
    // Range [0.0 dB, 6.0 dB], Step Size = 0.25 dB 
extern const uint16 gPowerOffsetTable[25];










