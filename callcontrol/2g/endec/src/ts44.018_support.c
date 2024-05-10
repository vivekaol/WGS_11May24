/*******************************************************************************
  ts44.018_support.c - (c) by Dafocus
*******************************************************************************/
#include "ed_user.h"
#include <assert.h>

const unsigned AnnexJ_R1024 [16] = {10, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6};
const unsigned AnnexJ_R512 [20] = {9, 8, 8, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5};

/*==============================================================================
	Executes a quicksort of the given array "qsarr".
	The array must have the [] operator.
	The elements of the array must have a type "T" that:
	- can be instanced
	- supports the standard = operator
	
	Example:

	struct TValue {
		int n;
	};
		

	TValue MyArr [ELEMS];
	...

	#define CMP_GEQ(a,b) a.n>=b.n
	#define CMP_LEQ(a,b) a.n<=b.n
	PCASORT_ENV(SortEnv)
	PCASORT(SortEnv,MyArr,ELEMS,TValue,CMP_GEQ,CMP_LEQ)
	
	Note that the ENV can be reused in the same function.
==============================================================================*/
#define PCASort_MAX_LEVELS 32
#define PCASORT_ENV(qsenv) int qsenv##QSbeg[PCASort_MAX_LEVELS], qsenv##QSend[PCASort_MAX_LEVELS], qsenv##QSidx, qsenv##QSleft, qsenv##QSright, qsenv##QSswap;
#define PCASORT(qsenv,qsarr,qscnt,qstyp,qsgeq,qsleq)\
	{\
		qstyp piv;\
		qsenv##QSidx=0;\
	  qsenv##QSbeg[0]=0;\
		qsenv##QSend[0]=(qscnt);\
		while (qsenv##QSidx>=0) {\
			qsenv##QSleft=qsenv##QSbeg[qsenv##QSidx]; qsenv##QSright=qsenv##QSend[qsenv##QSidx]-1;\
			if (qsenv##QSleft<qsenv##QSright) {\
				piv=(qsarr)[qsenv##QSleft];\
				while (qsenv##QSleft<qsenv##QSright) {\
					while (qsgeq (((qsarr)[qsenv##QSright]), piv) && qsenv##QSleft<qsenv##QSright) qsenv##QSright--;\
					if (qsenv##QSleft<qsenv##QSright) (qsarr)[qsenv##QSleft++]=(qsarr)[qsenv##QSright];\
					while (qsleq (((qsarr)[qsenv##QSleft]), piv) && qsenv##QSleft<qsenv##QSright) qsenv##QSleft++; \
					if (qsenv##QSleft<qsenv##QSright) (qsarr)[qsenv##QSright--]=(qsarr)[qsenv##QSleft]; \
				} \
				(qsarr)[qsenv##QSleft]=piv; \
				qsenv##QSbeg[qsenv##QSidx+1]=qsenv##QSleft+1; \
				qsenv##QSend[qsenv##QSidx+1]=qsenv##QSend[qsenv##QSidx]; \
				qsenv##QSend[qsenv##QSidx++]=qsenv##QSleft;\
				if (qsenv##QSend[qsenv##QSidx]-qsenv##QSbeg[qsenv##QSidx]>qsenv##QSend[qsenv##QSidx-1]-qsenv##QSbeg[qsenv##QSidx-1]) {\
					qsenv##QSswap=qsenv##QSbeg[qsenv##QSidx]; \
					qsenv##QSbeg[qsenv##QSidx]=qsenv##QSbeg[qsenv##QSidx-1]; \
					qsenv##QSbeg[qsenv##QSidx-1]=qsenv##QSswap;\
					qsenv##QSswap=qsenv##QSend[qsenv##QSidx]; \
					qsenv##QSend[qsenv##QSidx]=qsenv##QSend[qsenv##QSidx-1]; \
					qsenv##QSend[qsenv##QSidx-1]=qsenv##QSswap; \
				}\
			}\
			else {\
				qsenv##QSidx--; \
			}\
		}\
	}

/*------------------------------------------------------------------------------
	TS 44.018 Table 9.1.54.1a - p-function
------------------------------------------------------------------------------*/
unsigned DECODE_FDD_CELL_INFORMATION_p (unsigned n)
{
	switch (n) {
		case     0: return     0;
		case     1: return    10;
		case     2: return    19;
		case     3: return    28;
		case     4: return    36;
		case     5: return    44;
		case     6: return    52;
		case     7: return    60;
		case     8: return    67;
		case     9: return    74;
		case    10: return    81;
		case    11: return    88;
		case    12: return    95;
		case    13: return   102;
		case    14: return   109;
		case    15: return   116;
		case    16: return   122;
		default   : return     0;
	}
}


/*------------------------------------------------------------------------------
	TS 44.018 Table 9.1.54.1b - q-function
------------------------------------------------------------------------------*/
unsigned DECODE_TDD_CELL_INFORMATION_q (unsigned n)
{
	switch (n) {
		case     0: return     0;
		case     1: return     9;
		case     2: return    17;
		case     3: return    25;
		case     4: return    32;
		case     5: return    39;
		case     6: return    46;
		case     7: return    53;
		case     8: return    59;
		case     9: return    65;
		case    10: return    71;
		case    11: return    77;
		case    12: return    83;
		case    13: return    89;
		case    14: return    95;
		case    15: return   101;
		case    16: return   106;
		case    17: return   111;
		case    18: return   116;
		case    19: return   121;
		case    20: return   126;
		default   : return     0;
	}
}


/*------------------------------------------------------------------------------
	Used by Annex.J
------------------------------------------------------------------------------*/
static unsigned greatestPowerOf2LesserOrEqualTo (unsigned n)
{
	unsigned ret;
	ret = 0x8000000;
	
	while (ret > n) ret >>= 1;
	
	return ret;
}

/*------------------------------------------------------------------------------
	Decodes 44.018 Annex J compression
------------------------------------------------------------------------------*/
int DECODE_AnnexJ (const unsigned* inputValues, unsigned noOfInputValues, unsigned* outputValues, unsigned maxNoOfOutputValues, unsigned originalRange, int hasZero)
{
	unsigned INDEX;
	int RANGE;
	int N;
	unsigned K;
	unsigned noOfReturnedItems = 0;
	
	if (hasZero) {
		if (maxNoOfOutputValues < 1) return ENCODE_AnnexJ_ERROR_OUTPUT_TOO_SMALL;
		outputValues[0] = 0;
		noOfReturnedItems++;
	}

	for (K=1; K<=noOfInputValues; K++) {

		/* The next loop follows the tree from child to parent, from the node */
		/* of index K to the root (index 1). For each iteration the node of   */
		/* index INDEX is tackled. The corresponding range is RANGE, and N is */
		/* the value of the element in the range defined by the node.         */
		/* The data are set to their initial values :                         */
		
		INDEX = K;
		RANGE = originalRange / greatestPowerOf2LesserOrEqualTo(INDEX);
		N = inputValues [INDEX-1] - 1;
		
		while (INDEX>1) {

			/* Due to the assumption that the original range is a power of two  */
			/* minus one, the range for the parent node can be easily computed, */ 
			/* and does not depend upon whether the current node is a left or   */
			/* right child:                                                     */
			RANGE = 2*RANGE + 1;

			/* Let us note J = 2g-1, g being the generation of node INDEX.   */
			/* We have J = greatestPowerOf2LesserOrEqualTo(INDEX).     */
			/* The numbering used in the tree is such that the nodes of index */
			/* J to J + J/2 - 1 are left children, and the nodes of index J/2 */
			/* to J+J-1 are right children. Hence an easy test to distinguish */
			/* left and right children:                                       */
			if (2*INDEX < 3*greatestPowerOf2LesserOrEqualTo(INDEX)) { /* left child */

				/* The next computation gives the index of the parent node of the */
				/* node of index INDEX, for a left child: */
 				INDEX = INDEX - greatestPowerOf2LesserOrEqualTo(INDEX)/2;

				/* The next formula is the inverse of the renumbering appearing in the encoding */
				/* for a left child. It gives the value of the parent node in the range defined */
				/* by the grand-parent node: */
				N = (N + inputValues [INDEX-1] - 1 + (RANGE-1)/2 + 1)	% RANGE;
			}
			else { /* right child */

				/* The next computation gives the index of the parent node of the node */
				/* of index INDEX, for a right child: */
 				INDEX = INDEX - greatestPowerOf2LesserOrEqualTo(INDEX);

				/* The next formula is the inverse of the renumbering appearing in the */
				/* encoding for a right child: */
	 			N = (N + inputValues [INDEX-1] - 1 + 1) % RANGE;
	 		}
		}
		if (noOfReturnedItems < maxNoOfOutputValues) {
			outputValues [noOfReturnedItems] = N + 1;
		}
		else return ENCODE_AnnexJ_ERROR_OUTPUT_TOO_SMALL;
		noOfReturnedItems++;
	}

	#ifndef ENCODIX_ANNEXJ_DISABLE_SORTING
	#define CMP_GEQ(a,b) a>=b
	#define CMP_LEQ(a,b) a<=b
	{
		PCASORT_ENV(SortEnv)
		PCASORT(SortEnv,outputValues,noOfReturnedItems,unsigned,CMP_GEQ,CMP_LEQ)
	}
	#undef CMP_GEQ
	#undef CMP_LEQ
	#endif
	
	return (int)noOfReturnedItems;
}

#ifndef ENCODIX_ANNEXJ_MAXSUBSET
#define ENCODIX_ANNEXJ_MAXSUBSET 32
#endif

#ifndef ENCODIX_ANNEXJ_EXTENSIVE_DEBUG
#define ENCODIX_ANNEXJ_EXTENSIVE_DEBUG 0
#endif

#if ENCODIX_ANNEXJ_EXTENSIVE_DEBUG
#define ENCODIX_ANNEXJ_EXTENSIVE_ASSERT(n) assert(n);
#else
#define ENCODIX_ANNEXJ_EXTENSIVE_ASSERT(n)
#endif
#define ENCODIX_ANNEXJ_INVALID 0xFFFFFFFF

/*------------------------------------------------------------------------------
	Encodes 44.018 Annex J compression subtree
------------------------------------------------------------------------------*/
static int ENCODE_AnnexJ_subtree (const unsigned* inputValues, unsigned noOfInputValues, unsigned* outputValues, unsigned maxNoOfOutputValues, unsigned INDEX, unsigned RANGE)
{
	#define W(x) (*(assert ((x) >= 0 && (x) <= maxNoOfOutputValues), outputValues+(x)-1))
	#define SET(n) (assert ((n)>=1 && (n)<= noOfInputValues), inputValues[(n)-1])
	#define SUBSET(n) (*(assert ((n)>=1 && (n)<= ENCODIX_ANNEXJ_MAXSUBSET), Subset+(n)-1))
	#define mod %

	int ret;
	int usedItems = 0;
	unsigned N, J, I, INDEX_IN_SET;
	unsigned Subset [ENCODIX_ANNEXJ_MAXSUBSET];
	unsigned SUBSET_INDEX;
	unsigned ORIGIN_VALUE;
	unsigned VAL;

	/* First the program tests the leaf conditions */
	if (noOfInputValues==0) {
		/*W(INDEX) = 0;*/
		return 0;
	}
	else if (noOfInputValues==1) {
		if (INDEX >= maxNoOfOutputValues) return ENCODE_AnnexJ_ERROR_OUTPUT_TOO_SMALL;
		W(INDEX) = 1 + SET(1);
		return INDEX;
	}
	
	/* The following program finds a value in the set such that exactly 
		(SET'SIZE-1)/2 values from the set are between this value plus 1 and 
		this value plus half the range */
	INDEX_IN_SET = ENCODIX_ANNEXJ_INVALID;
	for (I=1; I<=noOfInputValues; I++) {
		N = 0;
		for (J=1; J<=noOfInputValues; J++) {
			VAL = (SET(J) < SET(I) ? SET(J)+RANGE : SET(J)) - SET(I);
			if (VAL <= ((RANGE-1)/2)) {
				N = N+1;
			}
		}
		/* The test compares N-1 because the possible pivot value is counted. */
		if (N-1 == (noOfInputValues-1)/2) {
			INDEX_IN_SET = I;
			break;
		}
	}

	/* INDEX_IN_SET is then the index in the list of the pivot value. */
	if (INDEX >= maxNoOfOutputValues) return ENCODE_AnnexJ_ERROR_OUTPUT_TOO_SMALL;
	W(INDEX) = SET(INDEX_IN_SET) + 1;
	if ((int)(INDEX-1) > usedItems) usedItems = (int)(INDEX);

	/* Then the program does the same thing for the two halves of 
	the range delimited by W(INDEX) and W(INDEX)+RANGE/2. First the left subset: */
	#if ENCODIX_ANNEXJ_EXTENSIVE_DEBUG
	{
		unsigned i;
		for (i=0; i<ENCODIX_ANNEXJ_MAXSUBSET; i++) {
			Subset[i] = ENCODIX_ANNEXJ_INVALID;
		}
	}
	#endif

	ORIGIN_VALUE = (SET(INDEX_IN_SET) + (RANGE-1)/2+ 1) mod RANGE;
	SUBSET_INDEX = 1;
	for (I=1; I<=noOfInputValues; I++) {
		VAL = (((SET(I) < ORIGIN_VALUE ? SET(I)+RANGE : SET(I)) - ORIGIN_VALUE) % RANGE);
	
		if (VAL < RANGE/2) {
			if (SUBSET_INDEX >= ENCODIX_ANNEXJ_MAXSUBSET) return ENCODE_AnnexJ_ERROR_TEMPORARY_TOO_SMALL;
			ENCODIX_ANNEXJ_EXTENSIVE_ASSERT(Subset[SUBSET_INDEX-1] == ENCODIX_ANNEXJ_INVALID)
			SUBSET(SUBSET_INDEX) = VAL;
			SUBSET_INDEX = SUBSET_INDEX + 1;
		}
	}
		
	ret = ENCODE_AnnexJ_subtree (Subset, SUBSET_INDEX-1, outputValues, maxNoOfOutputValues, INDEX + greatestPowerOf2LesserOrEqualTo(INDEX), RANGE/2);
	if (ret<0) return ret;
	if (ret > usedItems) usedItems = ret;

	/* Then the right subset */
	#if ENCODIX_ANNEXJ_EXTENSIVE_DEBUG
	{
		unsigned i;
		for (i=0; i<ENCODIX_ANNEXJ_MAXSUBSET; i++) {
			Subset[i] = ENCODIX_ANNEXJ_INVALID;
		}
	}
	#endif
	ORIGIN_VALUE = (SET(INDEX_IN_SET) + 1) mod RANGE;
	SUBSET_INDEX = 1;
	for (I=1; I<=noOfInputValues; I++) {
		VAL = (((SET(I) < ORIGIN_VALUE ? SET(I)+RANGE : SET(I)) - ORIGIN_VALUE) % RANGE);

		if (VAL < RANGE/2) {
			if (SUBSET_INDEX >= ENCODIX_ANNEXJ_MAXSUBSET) return ENCODE_AnnexJ_ERROR_TEMPORARY_TOO_SMALL;
			ENCODIX_ANNEXJ_EXTENSIVE_ASSERT(Subset[SUBSET_INDEX-1] == ENCODIX_ANNEXJ_INVALID)
			SUBSET(SUBSET_INDEX) = VAL;
			SUBSET_INDEX = SUBSET_INDEX + 1;
		}
	}
	ret = ENCODE_AnnexJ_subtree (Subset, SUBSET_INDEX-1, outputValues, maxNoOfOutputValues, INDEX + 2*greatestPowerOf2LesserOrEqualTo(INDEX), RANGE = (RANGE-1)/2);
	if (ret<0) return ret;
	if (ret > usedItems) usedItems = ret;

	#undef mod	
	#undef W
	#undef SET
	
	return usedItems;
}

/*------------------------------------------------------------------------------
	Encodes 44.018 Annex J compression.
	The "hasZero" is set to !=0 if the zero value is included in the set.
	This value has to go in the "F0" field (for example in TS44.018 10.5.2.13.3
	Range 1024 format), or in FDD_Indic0/TDD_Indic0 in TS 44.018, 10.5.2.1e.
	Returns the number of items added to outputValues or <0 in case of error.
------------------------------------------------------------------------------*/
int ENCODE_AnnexJ (const unsigned* inputValues, unsigned noOfInputValues, unsigned* outputValues, unsigned maxNoOfOutputValues, unsigned RANGE, int* hasZero)
{
	int ret;
	unsigned subset [ENCODIX_ANNEXJ_MAXSUBSET];
	unsigned i;
	unsigned subsetLen;
	
	if (noOfInputValues >= ENCODIX_ANNEXJ_MAXSUBSET) return ENCODE_AnnexJ_ERROR_TEMPORARY_TOO_SMALL;
	
	/* Create the subset containing all values - 1 and without the zero (if present) */
	(*hasZero) = 0;
	for (i=0, subsetLen=0; i<noOfInputValues; i++) {
		if (inputValues[i] > RANGE) return ENCODE_AnnexJ_ERROR_VALUE_OUT_OF_RANGE;
		if (inputValues[i] == 0) {
			(*hasZero) = 1;
		}
		else {
			subset[subsetLen] = inputValues[i]-1;
			subsetLen++;
		}
	}
	
	ret = ENCODE_AnnexJ_subtree (subset, subsetLen, outputValues, maxNoOfOutputValues, 1, RANGE);
	
	return ret;
}
