/*
 *############################################################################
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
 *       (c) FXLynx Technologies Ltd. 2016, All Rights Reserved
 *
 *############################################################################
 */

/*
 *############################################################################
 * File Name   : multiplebuffergen.c
 *
 * Description : This file provides main functionality for multiple 3g Tx Buffer 
 *               Generator.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 07/01/2016	        Ashutosh Samal              File Creation
 *############################################################################
 */
#include "multiplebuffergen.h"

#define PACKW(a, b) ((a)<<16 | (b)&0xFFFF)
#define _hil(a) ((a)>>16)
#define _lol(a) ((a)&0xFFFF)

char atGainLog2[401]={
-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,

};
short atGain[401]={
52429,53036,53650,54271,54900,55535,56178,56829,57487,58153,58826,59507,60196,60893,61598,62312,63033,63763,64502,65248,33002,33384,33771,34162,34557,34957,35362,35772,36186,36605,37029,37458,37891,38330,38774,39223,39677,40137,40601,41071,41547,42028,42515,43007,43505,44009,44518,45034,45555,46083,46617,47156,47702,48255,48813,49379,49951,50529,51114,51706,52305,52910,53523,54143,54770,55404,56045,56694,57351,58015,58687,59366,60054,60749,61453,62164,62884,63612,64349,65094,32924,
33305,33691,34081,34475,34875,35278,35687,36100,36518,36941,37369,37802,38239,38682,39130,39583,40041,40505,40974,41449,41929,42414,42905,43402,43905,44413,44927,45447,45974,46506,47045,47589,48140,48698,49262,49832,50409,50993,51583,52181,52785,53396,54014,54640,55273,55913,56560,57215,57878,58548,59226,59911,60605,61307,62017,62735,63461,64196,64940,32846,33226,33611,34000,34394,34792,35195,35602,36015,36432,36854,37280,37712,38149,38590,39037,39489,39947,40409,40877,41350,
41829,42314,42804,43299,43801,44308,44821,45340,45865,46396,46933,47477,48026,48583,49145,49714,50290,50872,51461,52057,52660,53270,53886,54510,55142,55780,56426,57079,57740,58409,59085,59770,60462,61162,61870,62586,63311,64044,64786,32768,33147,33531,33920,34312,34710,35112,35518,35929,36345,36766,37192,37623,38058,38499,38945,39396,39852,40313,40780,41252,41730,42213,42702,43197,43697,44203,44715,45232,45756,46286,46822,47364,47913,48467,49029,49596,50171,50752,51339,51934,
52535,53143,53759,54381,55011,55648,56292,56944,57604,58271,58945,59628,60318,61017,61723,62438,63161,63893,64632,65381,33069,33452,33839,34231,34627,35028,35434,35844,36259,36679,37104,37534,37968,38408,38853,39302,39758,40218,40684,41155,41631,42113,42601,43094,43593,44098,44609,45125,45648,46176,46711,47252,47799,48353,48913,49479,50052,50631,51218,51811,52411,53018,53631,54253,54881,55516,56159,56809,57467,58133,58806,59487,60176,60872,61577,62290,63012,63741,64479,65226,
32991,33373,33759,34150,34545,34945,35350,35759,36173,36592,37016,37445,37878,38317,38761,39209,39663,40123,40587,41057,41533,42014,42500,42992,43490,43994,44503,45018,45540,46067,46600,47140,47686,48238,48797,49362,49933,50511,51096,51688,52287,52892,53504,54124,54751,55385,56026,56675,57331,57995,58666,59346,60033,60728,61431,62143,62862,63590,64327,65071,32912,33294,33679,34069,34464,34863,35266,35675,36088,36506,36928,37356,37789,38226,38669,39116,39569,40028,40491,40960,

};
unsigned bIntinSaturate=0;

static  unsigned _pmulhuww(unsigned s0, unsigned s1)
{
	unsigned hi, lo;
	hi = _hil(s0) * _hil((int)s1);
	lo = (unsigned short)_lol(s0)*(short)_lol(s1);
    return(PACKW(_hil(hi),_hil(lo) ));
}

static  unsigned _pshvlws(unsigned s0, unsigned s1)
{
	int shift_left;
	long long barrel_result;
	unsigned  d2;

	shift_left = (((int)s1 >> 27) & ~0x0F) | (s1 & 0x0F);

	// Process the high part of the dword.
	if(shift_left < 0)
		barrel_result = (((long long)(int)(s0 & 0xFFFF0000)) >> (-shift_left & 0x1F));
	else
		barrel_result = (((long long)(int)(s0 & 0xFFFF0000)) << (shift_left & 0x1F));

	if ((barrel_result & 0xFFFFFFFF80000000LL) != 0 && (barrel_result & 0xFFFFFFFF80000000LL) != 0xFFFFFFFF80000000LL)
	{
		barrel_result = (barrel_result < 0) ? 0x80000000 : 0x7FFF0000;
		bIntinSaturate=1;
	}

	d2 = (unsigned int)barrel_result & 0xFFFF0000;

	// Process the low part of the dword.
	if(shift_left < 0)
		barrel_result = (((long long)(short)(s0 & 0x0000FFFF)) >> (-shift_left & 0x1F));
	else
		barrel_result = (((long long)(short)(s0 & 0x0000FFFF)) << (shift_left & 0x1F));

	if ((barrel_result & 0xFFFFFFFFFFFF8000LL) != 0 && (barrel_result & 0xFFFFFFFFFFFF8000LL) != 0xFFFFFFFFFFFF8000LL)
	{
		barrel_result = (barrel_result < 0) ? 0x00008000 : 0x00007FFF;
		bIntinSaturate=1;

	}

	d2 |= (unsigned)barrel_result & 0x0000FFFF;
	return(d2);
}

static unsigned _min(unsigned s0, unsigned  s1)
{
    return(((int)s0 < (int)s1) ? s0 : s1);
}
static unsigned _max(unsigned s0, unsigned s1)
{
    return(((int)s0 > (int)s1) ? s0 : s1);
}


void VecGain( short * f_pVec, unsigned f_N, short f_GaindB )
{
	unsigned i;
	unsigned	* pSrc = (unsigned*)f_pVec;
	unsigned	* pDst = (unsigned*)f_pVec;
	unsigned	pGain;
	int			GainIdx;
	short		Gain,GainLog2;	
	
	GainIdx = _min(f_GaindB+ 201,401 );
	GainIdx = _max(GainIdx, 0 );
	Gain	=atGain[GainIdx];
	GainLog2=atGainLog2[GainIdx];
	pGain = ((unsigned) (unsigned short) Gain) | (((unsigned)(unsigned short) Gain)<<16);
	
	f_N /=2; 

	for(i = 0; i <f_N;  i++ )
	{
		unsigned vin,vl2,vo;
		vin  = pSrc[i];
		vl2  = _pmulhuww(pGain,vin);
		vo   = _pshvlws(vl2,GainLog2);
		pDst[i] = vo;
	}

}
void VecAdd( short * f_pVecIn, unsigned f_N, short * f_pVecOut )
{
    unsigned i;
    f_N/=2;
	for(i = 0; i<f_N;i++)
	{
		f_pVecOut[2*i+0] += f_pVecIn[2*i+0];
		f_pVecOut[2*i+1] += f_pVecIn[2*i+1];
	}
}
int VecShift( short * f_pVecIn, unsigned f_N, unsigned f_TS,  short * f_pVecOut )
{
    unsigned i;
    if(f_TS > (f_N/2))
        return(-1);

    for(i=0; i <f_N-f_TS*2; i++ )
    {
        f_pVecOut[i+f_TS*2] = f_pVecIn[i];
    }

    for(i=0; i <f_TS*2; i++ )
    {
        f_pVecOut[i] = f_pVecIn[i+f_N-f_TS*2];
    }


    return(0);
}

void nGenerator( unsigned f_NumCell, tCellPrm * f_ptPrm,  short * f_Chips )
{
    unsigned i;
    short Chips[cRADIOFRAME_SIZE]={0};	    
    short ChipsShifted[cRADIOFRAME_SIZE]={0};	    
    short Mixed[cRADIOFRAME_SIZE]={0};	    
        
    for(i=0;  i < f_NumCell; i++ )
    {
        //Generate The bufer
        GenerateUsgBuffer(  Chips, 100, f_ptPrm[i].CpichdBm, f_ptPrm[i].PSchPowerdB, f_ptPrm[i].SSchPowerdB, f_ptPrm[i].PSC );
        
        //Apply Gain (in place)
        VecGain(Chips,cRADIOFRAME_SIZE, f_ptPrm[i].Gain);

        //Apply time Shift
        VecShift(Chips,cRADIOFRAME_SIZE, f_ptPrm[i].TS , ChipsShifted);
        
        //Mixing
        VecAdd(ChipsShifted,cRADIOFRAME_SIZE, Mixed);

    }
}
