/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_sprdscramble.h

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include "dlimlib.h"

#include "dlim_sch_tables.h"

void FASTCALL Dlim_CalculateSSC( s16 * f_pSSC )
ATTRIBUTE((optimize("O2")))
{
    s32 i,j;
    for(i=0;i<16;i++)
    {
		mPRAGMA_UNROLL(16)
		for(j=0;j<16;j++)
        {
            f_pSSC[16*i+j] = gB_SchTable[j]*gPatternB_SchTable[i];
        }
    }
}


