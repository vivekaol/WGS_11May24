/*############################################################################
 *
 *                   *** FXLynx Technologies Ltd. ***
 *
 *     The information contained in this file is the property of FXLynx
 *     Technologies Ltd. Except as specifically authorized in writing by
 *     FXLynx Technologies Ltd. The user of this file shall keep information
 *     contained herein confidential and shall protect same in whole or in
 *     part from disclosure and dissemination to third parties.
 *
 *     Without prior written consent of FXLynx Technologies Ltd. you may not
 *     reproduce, represent, or download through any means, the information 
 *     contained herein in any way or in any form.
 *
 *       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
 *
 ############################################################################*/

/*############################################################################
 * File Name   : lteCmn.c
 *
 * Description : This file has common handler functions used across different
 *               modules in LTE
 *
 * History     :
 *
 * Date	        Author                  Details
 * ---------------------------------------------------------------------------
 * 06/04/2015   Anand Kashikar      File Creation
 ############################################################################*/
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "lteCmnDef.h"

/* ----------------------------------------------------- */
void  SetBit( uint8 A[],  uint32 k )
{
  A[k/8] |= 1 << (7 - (k%8));  // Set the bit at the k-th position in A[i]
}

void  ClearBit(  uint8 A[], uint32 k )
{
  A[k/8] &= ~(1 << (7 - (k%8)));
}

uint8 TestBit(uint8 A[], uint32 k )
{
  if( (A[k/8] & (1 << (7-(k%8)) )) != 0 )
	  return 1;
  else
	  return 0;
}

void setIE(uint32   value,
                  uint8 *bits,
                  uint32 N_bits,
                  uint32 *startPos)
{
    uint32 i, tmp;
	tmp = value << (32 - N_bits); //
    for(i=0; i<N_bits; i++)
    {
    	if((tmp & 0x80000000) == 0x80000000)
    	{
    		SetBit(bits , (*startPos)+i);
    	}
		tmp = tmp << 1;
    }
    *startPos += N_bits;
}

uint32 getIE(uint8  *bits,
                    uint32   N_bits,
                    uint32 *startPos)
{
    uint32 value = 0;
    uint32 i;

    for(i=0; i<N_bits; i++)
    {
    	value = value << 1;
    	value |=  TestBit(bits, *startPos+i);
    }
    *startPos += N_bits;
    return(value);
}

