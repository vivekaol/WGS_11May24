/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_sprdscramble.h

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "octtypes.h"
#include "octccs.h"
/******************************************************************************
 Function name: DLIM_GenerateGoldCode
 Description  : This function generates scrambling code of 1 frame length 

 Input param  : ScrCode -   Pointer to scrambling code array
                code_number -   scrambling code index

 Output param : NONE
 
 Return       : NONE
******************************************************************************/
void FASTCALL Dlim_GoldCodeGenerateSlot(
    uint32 *pScrCode, 
	uint32 code_number, 
	uint32 slot_number,
	uint32 *previousStateX,
	uint32 *previousStateY
	)
{


}

