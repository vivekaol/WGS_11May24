/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_sprdscramble.h

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include "dlimlib.h"

#include "dlim_sch_tables.h"

void FASTCALL Dlim_AddSCH( tCmplx16 *f_pOutData,s16 *f_pPscSsc )
{
    s32 i;
	for(i = 0; i<DL_SCH_CHIPS_IN_SLOT;i++)
	{
        s16 Tmp;
		Tmp = f_pPscSsc[i];
		f_pOutData[i].Real += Tmp;
		f_pOutData[i].Imag += Tmp;
	}

}