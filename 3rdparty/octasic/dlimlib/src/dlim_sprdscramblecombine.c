/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_sprdscramble.c

$Octasic_Copyright: $

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "dlimlib.h"


/******************************************************************************
 Function name: DLIM_SpreadScramble
 Description  : This function implements the Spreding and Scrambling.

 Input param  : in - Pointer to complex input data
                code - Pointer to spreding code
                Code_size - Length of code
                Slot_size - Slot length
                scr_code - Pointer to srambling code

 Output param : out - Pointer to complex output data

 Globals/Tables Accessed:
                    NONE

 Return       : NONE
******************************************************************************/
static void DLIM_SpreadScramble(tCmplx16* Input, 
                         uint32 *scrspr_code,
					     tCmplx16* Output, 
                         uint16 Code_size, 
                         uint16 Slot_size)
{
    uint32 i,j=0,k2=0,TempCode=0,mask=0;
    sint32 Temp1,Temp2,Temp3,Temp4,Temp_R,Temp_I;


    for(i=0;i<Slot_size;i++) 
    {
		Temp1 = (Input[i].Real - Input[i].Imag);
        Temp2 = (Input[i].Real + Input[i].Imag);
	    Temp3 = -Temp1;
		Temp4 = -Temp2;
		
        for(j=0;j<Code_size;j++)
        {
			if( (k2 & 0x0F) == 0)
				TempCode = *scrspr_code++;

			mask = TempCode & 0x80008000;

            // extract last two bits
            if(mask == 0)
            {
                Temp_R = Temp1;
                Temp_I = Temp2;
            }

            if(mask == 0x8000)
            {
                Temp_R = Temp2;
                Temp_I = Temp3;
            }

            if(mask == 0x80000000)
            {
                Temp_R = Temp4;
                Temp_I = Temp1;
            }

            if(mask == 0x80008000)
            {
                Temp_R = Temp3;
                Temp_I = Temp4;
            }

			if(Temp_R > 32767)
				Temp_R = 32767;
			if(Temp_R < -32768)
				Temp_R = -32768;
			
            Output[i*Code_size + j].Real  = Temp_R;

            if(Temp_I > 32767)
				Temp_I = 32767;
			if(Temp_I < -32768)
				Temp_I = -32768;

			Output[i*Code_size + j].Imag  = Temp_I;

            TempCode <<=1;
            k2++;
        }
    }
}



void FASTCALL Dlim_SpreadScramble_Combine(
                         tCmplx16   * symb, 
                         uint32     *code,
					     tCmplx16   * chips, 
                         uint32     Spread_factor, 
                         uint32     nsymbs)
{
    s32 i;
    tCmplx16 tmp[2560];
     DLIM_SpreadScramble(symb, 
                         code,
					     tmp, 
                         Spread_factor, 
                         nsymbs);
     for(i=0; i < 2560; i++)
     {
         chips[i].Real += tmp[i].Real;
         chips[i].Imag += tmp[i].Imag;
     }
}
