/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_tables.h

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* Tables file for Inner Modem */

#ifndef _DLIM_SCH_TABLES_H_
#define _DLIM_SCH_TABLES_H_

#include "octtypes.h"


// B.16 Table used for TFCI decoder (for decoding 32-bit TFCI word)
extern const sint8 Hadamard[16][16];

// Table for SyncCH 
extern const uint8 SSCH_CodeGroups[64][15];

extern const sint8 gA_SchTable[16];
extern const sint8 gPatternA_SchTable[16];

extern const sint8 gB_SchTable[16];
extern const sint8 gPatternB_SchTable[16];


#endif //_DLIM_SCH_TABLES_H_