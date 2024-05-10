
#ifndef __DLIM_LIB__
#define __DLIM_LIB__

#include "octtypes.h"
#include "octccs.h"

//Scramblingcode 
void FASTCALL Dlim_SpreadScramble_Combine(tCmplx16 *symb,uint32 *code,tCmplx16 *chips,uint32 Spread_factor, uint32 nsymbs);


//Spreading  code
void FASTCALL DLIM_ChipCombine(short int *Inp,short int *Out,unsigned int numChips);
void FASTCALL DLIM_CombineSlotSprdScrCodes(	uint32 *scrcode,	uint32 *sprcode,	uint32 *scrsprcode,	uint8	iSlot);

//Downlink gold code code generation
void FASTCALL Dlim_GoldCodeGenerateFrame(   uint32 *pScrCode, 	uint32 code_number 	);
	
//Modulation
#define DTX_INDCTR			3
#define DL_DTX_BPSK			(1 - 2*DTX_INDCTR)
void FASTCALL Dlim_QPSKModulate( uint8 *pSlotFormattedData,tCmplx16 *pSymbolData,uint16 powerWt, uint16 numSymbolsPerSlot);



//P-SCH
#define DL_SCH_CHIPS_IN_SLOT (256)
void FASTCALL Dlim_CalculatePSC( u16 f_PowerWt, s16 * f_pPSC );
void FASTCALL Dlim_CalculateSSC( s16 * f_pSSC );
void FASTCALL Dlim_GenerateSyncCH( s16 *f_pPscSsc, 
                          s16 *f_pPSC, 
                          s16 *f_pSSC, 
                          s16 *f_pSSCz,
                          s32 f_powerSSch,
                          u32 f_ScrambleCode,
                          u8 f_iSlot);
void FASTCALL Dlim_AddSCH( tCmplx16 *f_pOutData,s16 *f_pPscSsc );



//Power management
void   FASTCALL SetPcpichPower(REGISTER sint16 abspcpichpwr, REGISTER sint16 absmaxpwr);
sint16 FASTCALL GetPcpichPowerWt(void);
sint16 FASTCALL GetPowerWt_Rel2Pcpich(REGISTER sint16 relchpwr);
sint16 FASTCALL GetPowerTabIndex_Rel2Pcpich(REGISTER sint16 relchpwr);


#endif //_VEC_MAXUW_
