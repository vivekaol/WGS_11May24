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
void FASTCALL Dlim_GoldCodeGenerateFrame(   uint32 *pScrCode, 	uint32 code_number 	)
{
    sint32 i,j, Wordcnt;
    uint32 X ,Y,TempI=0, TempQ=0, T=0;

    // Initialize X and Y for initial 18 values index 0 to 17.
    X = 0x00000001;
    Y = 0x0003FFFF;

    for(i=0;i<(sint32)code_number;i++)
    {
        X |= ((((X>>7) + X)&0x1)<<18);
        X >>= 1;
    }

    // Get the value for I and Q.
    for(Wordcnt=0;Wordcnt<2400;Wordcnt++)
    {
        TempI = 0;
        TempQ = 0;

        for(j=31;j>15;j--)
        {           
            TempI |= (((X + Y) & 0x1) << j);

            T = ((Y >> 5) + (Y >> 6) + (Y >> 8) + (Y>>9) + (Y>>10) + (Y>>11) + (Y>>12) + (Y>>13) + (Y>>14) + (Y>>15)) & 0x1;

            TempQ |= ((((X>>4) + (X>>6) + (X>>15) + T) & 0x1) << (j-16));

            X |= ((((X>>7) + X)&0x1)<<18);

            Y |= (((Y + (Y>>5) + (Y>>7) + (Y>>10))&0x1)<<18);

            // Shift X and Y right by 1.
            X >>= 1;
            Y >>= 1;
        }
		
        //Store one word
        pScrCode[Wordcnt] = (TempI ^ TempQ);
		//mOCTSDR_PRINT("Wordcnt=%d:%d\n",Wordcnt,ScrCode[Wordcnt]);
    }    
}

