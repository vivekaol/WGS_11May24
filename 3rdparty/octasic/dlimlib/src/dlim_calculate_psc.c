/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_sprdscramble.h

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include "dlimlib.h"

#include "dlim_sch_tables.h"

void FASTCALL Dlim_CalculatePSC( u16 f_PowerWt, s16 * f_pPSC )
ATTRIBUTE((optimize("O2")))
{
    s32 i,j;
    s32 PowerWt = (s32)f_PowerWt;
    for(i=0;i<16;i++)
    {
		mPRAGMA_UNROLL(16)
        for(j=0;j<16;j++)
        {
            f_pPSC[16*i+j] = gA_SchTable[j]*gPatternA_SchTable[i]* PowerWt;
        }
    }
}
