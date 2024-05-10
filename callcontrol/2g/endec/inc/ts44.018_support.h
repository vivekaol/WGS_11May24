/*******************************************************************************
  ts44.018_support.h - (c) by Dafocus
*******************************************************************************/
#ifndef __TS44018_SUPPORT_H
#define __TS44018_SUPPORT_H

#ifdef __cplusplus
	extern "C" {
#endif

#define ENCODE_AnnexJ_ERROR_OUTPUT_TOO_SMALL     (-19101)
#define ENCODE_AnnexJ_ERROR_TEMPORARY_TOO_SMALL  (-19102)
#define ENCODE_AnnexJ_ERROR_VALUE_OUT_OF_RANGE   (-19103)

extern const unsigned AnnexJ_R1024 [16];
extern const unsigned AnnexJ_R512 [20];

/*------------------------------------------------------------------------------
	TS 44.018 Table 9.1.54.1a - p-function
------------------------------------------------------------------------------*/
extern unsigned DECODE_FDD_CELL_INFORMATION_p (unsigned n);

/*------------------------------------------------------------------------------
	TS 44.018 Table 9.1.54.1b - q-function
------------------------------------------------------------------------------*/
extern unsigned DECODE_TDD_CELL_INFORMATION_q (unsigned n);

/*------------------------------------------------------------------------------
	Decodes 44.018 Annex J compression
	The "hasZero" is set to !=0 if the zero value is included in the set.
	This value has to be takne from the "F0" field (for example in TS44.018 10.5.2.13.3
	Range 1024 format), or FDD_Indic0/TDD_Indic0 in TS 44.018, 10.5.2.1e.
	Returns the number of items added to outputValues or <0 in case of error.
------------------------------------------------------------------------------*/
extern int DECODE_AnnexJ (const unsigned* inputValues, unsigned noOfInputItems, unsigned* outputValues, unsigned maxNoOfOutputValues, unsigned originalRange, int hasZero);

/*------------------------------------------------------------------------------
	Encodes 44.018 Annex J compression
	The "hasZero" is set to !=0 if the zero value is included in the set.
	This value has to go in the "F0" field (for example in TS44.018 10.5.2.13.3
	Range 1024 format), or in FDD_Indic0/TDD_Indic0 in TS 44.018, 10.5.2.1e.
	Returns the number of items added to outputValues or <0 in case of error.
------------------------------------------------------------------------------*/
extern int ENCODE_AnnexJ (const unsigned* inputValues, unsigned noOfInputValues, unsigned* outputValues, unsigned maxNoOfOutputValues, unsigned RANGE, int* hasZero);


#ifdef __cplusplus
	}
#endif

#endif

