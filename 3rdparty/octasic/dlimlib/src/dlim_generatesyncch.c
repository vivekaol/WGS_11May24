/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_generatesyncch.c

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include "dlimlib.h"

#include "dlim_sch_tables.h"
void FASTCALL Dlim_GenerateSyncCH( s16 *f_pPscSsc, 
                          s16 *f_pPSC, 
                          s16 *f_pSSC, 
                          s16 *f_pSSCz,
                          s32 f_powerSSch,
                          u32 f_ScrambleCode,
                          u8 f_iSlot)
{
    s32 iChip,k,index;
    u8 Row_index_in_Code_Group = f_ScrambleCode>>7; //divide by 128
	
	index = SSCH_CodeGroups[Row_index_in_Code_Group][f_iSlot] ;
	index = index -1;
    for(iChip=0;iChip<DL_SCH_CHIPS_IN_SLOT;iChip++)
    {
		k = iChip >> 4;
		f_pSSC[iChip] = Hadamard[k][index]* f_pSSCz[iChip]* f_powerSSch;
	    f_pPscSsc[iChip] = f_pSSC[iChip] + f_pPSC[iChip];
		//mOCTSDR_PRINT("%d:%d\n",iChip+1,pSSC[iChip]);
    }
}
