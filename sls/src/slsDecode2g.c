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
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : slsDecode.c
 *
* Description : System information decoder for GSM messages.
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------
* 11/10/2014          					Anand Kashikar            Initial File Creation
*######################################################################################
*/
#include "slsDecode2g.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "ratSocketItf.h"
#include "fxLSocketInterfaceApi.h"
#include "logManager.h"
#include "feaConfig.h"

typedef signed char         sint8;
typedef signed short        sint16;

/*
 * GSM400/850/900 Power control levels in dBm: 45.005 - 4.1.1
 */
const tOCT_INT8 power_gsm_ctrl_level_dbm[ 32 ] =
{
    39, 39, 39, 37, 35, 33, 31, 29,
    27, 25, 23, 21, 19, 17, 15, 13,
    11, 9, 7, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5
};

/*
 * DCS1800 Power control levels in dBm: 45.005 - 4.1.1
 */
const tOCT_INT8 power_dcs1800_ctrl_level_dbm[ 32 ] =
{
    30, 28, 26, 24, 22, 20, 18, 16,
    14, 12, 10, 8, 6, 4, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 36, 34, 32
};

/*
 * PCS1900 Power control levels in dBm: 45.005 - 4.1.1
 */
const tOCT_INT8 power_dcs1900_ctrl_level_dbm[ 32 ] =
{
    30, 28, 26, 24, 22, 20, 18, 16,
    14, 12, 10, 8, 6, 4, 2, 0,
    0, 0, 0, 0, 0, 0, 33, 33,
    33, 33, 33, 33, 33, 33, 33, 32
};


#define GET_ORIGIN_ARFCN \
		{ origin_arfcn = ((tOCT_UINT32)(description[0] & 0x01) << 8) +  \
						  (tOCT_UINT32)(description[1]);                \
		  origin_arfcn <<= 1;                                    \
		  if (description[2] & 0x80) origin_arfcn |= 1; }

#define MAX(a, b)       ((a) > (b)) ? (a) : (b)
#define MIN(a, b)       ((a) < (b)) ? (a) : (b)

void freqlist_init_allocation( type_of_freq_allocation type,
                            L1_ALLOCATION_UNION_STR *alloc );
void sort_hopping_list( L1_CELL_ALLOCATION_STR *alloc);

tOCT_UINT8 sndMsgBuf[1024 * 6] = {0};

int si1Cell    = 0xFFFFFFF0;
int si2Cell    = 0xFFFFFFF1;
int si2qCell   = 0xFFFFFFF2;
int si2bisCell = 0xFFFFFFF3;
int si2terCell = 0xFFFFFFF4;
int si3Cell    = 0xFFFFFFF5;
int si4Cell    = 0xFFFFFFF6;


/* Data structure for SI2quater reception book-keeping */
static RR_SI2QUATER_RCPTN_STATUS_STR     rr_si2quater;
extern fxL3gBandType CalculateBandUsingUarfcn(unsigned int dlUarfcn);

#if 0
/************************************************************************************************************/

tOCT_UINT8 gsm_lib_three_digits_country( tOCT_UINT8* mcc )
{
	tOCT_UINT8  three_digits;
    tOCT_UINT16 country_code = 0;

    country_code = ((mcc[0] * 100) + (mcc[1] * 10) + mcc[2]);

	switch (country_code)
	{
		case 302: /* Canada */
		case 310: /* USA */
		case 311: /* USA */
		case 312: /* USA */
		case 313: /* USA */
		case 314: /* USA */
		case 315: /* USA */
		case 316: /* USA */
		case 732: /*Columbia*/
			three_digits = TRUE;
			break;
		default:
			three_digits = FALSE;
			break;
	}
	return three_digits;
}


/************************************************************************************************************/

void convert_lai_to_bcd(T_LAI_INFO_STR *lai_si , T_LAI_BCD *lai_bcd)
{
	tOCT_UINT8 third_mnc_digit = 0;
	memset(lai_bcd , 0 , sizeof(T_LAI_BCD));
	lai_bcd->lac = lai_si->lac[0] & 0xFF;
	lai_bcd->lac <<= 8 ;
	lai_bcd->lac |= lai_si->lac[1] & 0xFF;

	lai_bcd->mcc = (lai_si->mcc2_mcc1 >> 4) *10 +
					(lai_si->mcc2_mcc1 & 0x0F) * 100 +
					(lai_si->mnc3_mcc3 & 0x0F);

	third_mnc_digit = (lai_si->mnc3_mcc3 >> 4);

	if ( (third_mnc_digit != 0xF ) ||
		(gsm_lib_three_digits_country(lai_bcd->mcc) == TRUE))
		{
		if (third_mnc_digit > 9)
			{
			third_mnc_digit = 0;
			}
		lai_bcd->mnc = third_mnc_digit +
						(lai_si->mnc2_mnc1 >> 4) * 10 +
						(lai_si->mnc2_mnc1 & 0x0F) * 100;
		}
	else
		{
		lai_bcd->mnc = (lai_si->mnc2_mnc1 >> 4) +
						(lai_si->mnc2_mnc1 & 0x0F) * 10;
		}
	if ((lai_bcd->mcc > 999) || (lai_bcd->mnc > 999))
		{
		lai_bcd->mcc = 999;
		lai_bcd->mnc = 999;
		}
}
#endif
/************************************************************************************************************/

tOCT_UINT8 gsm_lib_csn1_field_read( tOCT_UINT8 **ptr, sint8 *bit_index,
							   tOCT_UINT8 length, tOCT_UINT8 padding )
{
	static const tOCT_UINT8 gsm_lib_mask[9] = { 0x00, 0x01, 0x03,
									   0x07, 0x0F, 0x1F,
									   0x3F, 0x7F, 0xFF };
	tOCT_UINT8 work1;
	tOCT_UINT8 work2;
	tOCT_UINT8 return_value;
	sint8 shift;

	work1 = **ptr ^ padding;
	shift = *bit_index - (sint8)length;
	if (shift >= 0)
	   {
		   return_value = (work1 >> shift) & gsm_lib_mask[length];
	   }
	else
	   {
		   shift = -shift;
		   work2 = *(*ptr + 1) ^ padding;

		   return_value =
			   ((work1 & gsm_lib_mask[*bit_index]) << shift) +
			   ((work2 >> (8 - shift)) & gsm_lib_mask[shift]);
	   }

	*bit_index -= (sint8)length;

	if (*bit_index <= 0)
	   {
		   *bit_index += 8;
		   (*ptr)++;
	   }
	return return_value;
}

/************************************************************************************************************/

void decode( tOCT_UINT32 w[], tOCT_UINT32 f[],
                   tOCT_UINT32 original_range, tOCT_UINT16 origin_arfcn)
{
	tOCT_UINT32 w_size;
	register tOCT_UINT16 index;      /* 1...size of w */
	register tOCT_UINT32 k;
	tOCT_UINT32 range, n, p_of_two_result;

	w_size = w[0]; /* number of values in list */
	for (k=1; (k<=w_size) && (w[k]!=0); k++)
	{
		index = k;
		GREATEST_PWR_OF_2_LESS_OR_EQ_TO(index, p_of_two_result);
		range = original_range / p_of_two_result;
		n = w[index] - 1;

		while (index > 1)
			{
				range = (tOCT_UINT32)(2*range + 1);
				GREATEST_PWR_OF_2_LESS_OR_EQ_TO(index, p_of_two_result);
				if (2*index < 3*p_of_two_result)
					{
						/* left child */
						index -= (p_of_two_result / 2);
						n = (n + w[index] + (range-1)/2) % range;
					}
				else
					{
						/* right child */
						index -= p_of_two_result;
						n = (n + w[index]) % range;
					}
			 } /* end of while */

		f[k-1] = (n + origin_arfcn + 1) % 1024; /* + 1 is correction! */
	} /* end of for */
	f[k-1] = END_OF_LIST; /* end of list */
}

/************************************************************************************************************/

void unpack_range_n_description ( tOCT_UINT8 description[],
									tOCT_UINT32 f[],
									tOCT_UINT32 length_of_descr,
									tOCT_UINT32 original_range)
{
	tOCT_UINT32 i, descr_index;       /* indexes for w and description */
	tOCT_UINT8 bit_cntr;             /* counts the bits in w[i] of description */
	tOCT_UINT8 nr_of_bits;           /* number of bits in w[i] of descr. (10,9,8,..)*/
	tOCT_UINT8 shift_cntr;           /* counts the bits in a tOCT_UINT8 (0..7) */
	tOCT_UINT8 tmp_byte, ready_flag; /* temporary byte */
	tOCT_UINT32 next_pwr_of_two;      /* the power of two (2,4,8,16,32,..) to define
								  the nr_of_bits */
	tOCT_UINT16 origin_arfcn;       /* see ranges 512, 256 and 128 */
	tOCT_UINT32 *w;                   /* pointer to the array for coded frequencies */
	w = (tOCT_UINT32 *) malloc((4 * GERAN_ARFCN_LIST_LENGTH)); /* 4 bytes for each 32 Neighbour cells. */
	assert(w!= NULL);

	i = 1;
	w[i] = 0; f[0] = 0;
	shift_cntr = 0;
	next_pwr_of_two = 2;
	origin_arfcn = 0;
	if (original_range == ORIG_RANGE_1024)
	{
		descr_index = 0;    /*points a byte where decoding will be start*/
		w[i] = (tOCT_UINT32) (description[descr_index++] & 0x03); /*2 high bits */
		bit_cntr = 2;
		nr_of_bits = 10;
	}
	else
	{
		GET_ORIGIN_ARFCN;
		descr_index = 2;  /* points a byte where unpacking will be start */
		w[i] = (tOCT_UINT32) (description[descr_index++] & 0x7F); /* 7 low bits */
		bit_cntr = 7;

		if (original_range == ORIG_RANGE_512)
			{
			nr_of_bits = 9;
			}
		else if (original_range == ORIG_RANGE_256)
			{
			nr_of_bits = 8;
			}
		else if (original_range == ORIG_RANGE_128)
			{
			nr_of_bits = 7;
			}
		else
			{
				nr_of_bits = 0;
			}
	}

	if (nr_of_bits != 0)
	{
		tmp_byte = description[descr_index];
		ready_flag = FALSE;
		while (descr_index < length_of_descr)
		{
			while (bit_cntr < nr_of_bits)
				{
					w[i] <<= 1;
					if (tmp_byte & 0x80)
					{
						w[i] |= 1;    /* & is really right */
					}
					tmp_byte <<= 1;
					bit_cntr++;
					shift_cntr++;

					if (shift_cntr == 8)
					{
						shift_cntr = 0;
						descr_index++;

					if (descr_index < length_of_descr)
						{
							tmp_byte = description[ descr_index ];
						}
					else
						{
							ready_flag = TRUE;
							break; /* jump out from 2. while */
						}
					}

				} /* end of 2. while */
			if (ready_flag == TRUE) break; /* jump out from 1. while */

			w[++i] = 0;

			if (i == next_pwr_of_two)
				{
					next_pwr_of_two *= 2;
					nr_of_bits--;
				}

			bit_cntr = 0;
		} /* end of 1. while */
	if (bit_cntr < nr_of_bits)
		{
			i--; /* last value is not the real one */
		}
	w[0] = i;                       /* number of values */

	if ((original_range == ORIG_RANGE_1024) &&
		!(description[0] & F0_MASK))
		{
			decode( w, &f[0], original_range, origin_arfcn);
		}
	else
		{
			f[0] = origin_arfcn;
			decode( w, &f[1], original_range, origin_arfcn);
		}

	}
	free(w);
}

/************************************************************************************************************/

int fdd_cell_info_params_cmp(const void *fdd_cell_info_param_1,
const void *fdd_cell_info_param_2)
{
if (*(const tOCT_UINT32 *)(fdd_cell_info_param_1) <
	*(const tOCT_UINT32 *)(fdd_cell_info_param_2))
	{
		return -1;
	}
else if (*(const tOCT_UINT32 *)(fdd_cell_info_param_1) ==
	*(const tOCT_UINT32 *) (fdd_cell_info_param_2))
	{
		return 0;
	}
else
	{
		return 1;
	}
}

/************************************************************************************************************/

tOCT_UINT8 form_freq_result( tOCT_UINT32 f[],
						 L1_ALLOCATION_UNION_STR *alloc,
						 type_of_freq_allocation type,
						 tOCT_UINT8 init_allocation_flag)
{
	tOCT_UINT32 i;
	i = 0;
	if (init_allocation_flag == TRUE)
	 {
		freqlist_init_allocation( type, alloc );
	 }

	switch (type)
	 {
	 case BCCH_ALLOCATION:
		 while ((f[i] != END_OF_LIST) &&
			 (i < GERAN_ARFCN_LIST_LENGTH))
			 {
				 alloc->ba.arfcns[i] = f[i];
				 alloc->ba.nbr_of_arfcns++;
				 i++;
			 }
		 break;
	 case CELL_ALLOCATION:
		 while ((f[i] != END_OF_LIST) &&
				 (i < SIZE_OF_HOPPING_LIST))
			 {
				 alloc->ca.hopping_list[i] = f[i];
				 i++;
			 }
		 sort_hopping_list( (L1_CELL_ALLOCATION_STR *) &alloc->ca );
		 break;

	 case FDD_CELL_INFO_PARAMS:
				 while ((f[i] != END_OF_LIST) &&
					 (i < MAX_NO_OF_FDD_CELL_INFO_PARAMS))
					 {
						 alloc->fdd_cell_info_params.params[i] = f[i];
						 i++;
					 }
				 alloc->fdd_cell_info_params.no_of_params = (tOCT_UINT8) i;
				 qsort(alloc->fdd_cell_info_params.params,
					 alloc->fdd_cell_info_params.no_of_params,
					 sizeof(tOCT_UINT32),
					 fdd_cell_info_params_cmp);
				 break;
		}
	return( FREQLIST_DECODING_OK );
}

/************************************************************************************************************/

tOCT_UINT8 decode_bit_map_0 ( tOCT_UINT8 description[],
						  tOCT_UINT32 length_of_descr,
						  L1_ALLOCATION_UNION_STR *alloc,
						  type_of_freq_allocation type,
						  tOCT_UINT8 init_allocation_flag)
{
	 sint16 descr_index;
	 tOCT_UINT32 rec_no_of_freq;
	 tOCT_UINT32 rrfcn_cntr;
	 tOCT_UINT32 rec_no_of_neigh;
	 tOCT_UINT8 tmp_byte;
	 tOCT_UINT8 shift_cntr;

	if ( init_allocation_flag == TRUE )
	 {
	 	freqlist_init_allocation( type, alloc );
	 }

	switch (type)
	 {
		 case BCCH_ALLOCATION:
			 rec_no_of_neigh = 0;
			 rrfcn_cntr  = 128;
			 descr_index = 0;
			 tmp_byte    = description[descr_index];
			 tmp_byte    &= 0x0F;
			 shift_cntr  = 0;
			 while (descr_index < length_of_descr)
				 {
				 while (shift_cntr < 8)
					 {
					 if (tmp_byte & 0x80)
						 {
						 rec_no_of_neigh++;
						 if (rec_no_of_neigh > GERAN_ARFCN_LIST_LENGTH)
							 {
							 return( FREQLIST_DECODING_OK );
							 }
						 alloc->ba.arfcns[rec_no_of_neigh-1] = rrfcn_cntr;
						 alloc->ba.nbr_of_arfcns++;
						 }
					 tmp_byte <<= 1;
					 shift_cntr++;
					 rrfcn_cntr--;
					 }
				 ++descr_index;
				 if (descr_index < length_of_descr )
					 {
					 tmp_byte = description[descr_index];
					 }
				 shift_cntr = 0;
				 }
			 break;

		 case CELL_ALLOCATION:
			 rec_no_of_freq = 0;
			 rrfcn_cntr = 1;
			 descr_index = (sint16)(length_of_descr - 1);
			 description[0] &= 0x0F;
			 shift_cntr = 0;
			 while (descr_index >= 0)
				 {
				 tmp_byte = description[descr_index--];
				 while (shift_cntr < 8)
					 {
					 if (tmp_byte & 0x01)
						 {
						 rec_no_of_freq++;
						 if (rec_no_of_freq > SIZE_OF_HOPPING_LIST)
							 {
							 return( FREQLIST_DECODING_OK );
							 }
						 alloc->ca.hopping_list[rec_no_of_freq-1] =
															   rrfcn_cntr;
						 }
					 tmp_byte >>= 1;
					 shift_cntr++;
					 rrfcn_cntr++;
					 }
				 shift_cntr = 0;
				 }

			 break;

		 default:
			 break;
	 }
	return( FREQLIST_DECODING_OK );
}

/************************************************************************************************************/

int arfcn_list_cmp(const void *arfcn_list_param_1,
const void *arfcn_list_param_2)
{

	if( ((*(const tOCT_UINT32 *) (arfcn_list_param_1)) >= 0 ) &&
		((*(const tOCT_UINT32 *) (arfcn_list_param_2)) >= 0 ) )
		{
		return( *(const tOCT_UINT32 *) arfcn_list_param_1 - *(const tOCT_UINT32 *) arfcn_list_param_2 );
		}
	else
		{
		return( *(const tOCT_UINT32 *) arfcn_list_param_2 - *(const tOCT_UINT32 *) arfcn_list_param_1 );
		}
}

/************************************************************************************************************/

void sort_hopping_list( L1_CELL_ALLOCATION_STR *alloc)
{

	tOCT_UINT8              no_of_received_arfcns = 0;
	while (no_of_received_arfcns < SIZE_OF_HOPPING_LIST &&
				alloc->hopping_list[no_of_received_arfcns] !=
					END_OF_HOPPING_LIST)
			 {
				no_of_received_arfcns++;
			 }

	 qsort( alloc->hopping_list,
			no_of_received_arfcns,
			sizeof( T_CARRIER_NUMBER ),
			arfcn_list_cmp );

}

/************************************************************************************************************/

void freqlist_init_allocation( type_of_freq_allocation type,
					L1_ALLOCATION_UNION_STR *alloc )
{
	tOCT_UINT8 i;

	switch (type)
	{
		case BCCH_ALLOCATION:
		(void) memset( (void *) &alloc->ba, 0x00,
			sizeof( GERAN_ARFCN_LIST_STR ) );
		break;

		case CELL_ALLOCATION:
		(void) memset( (void *) &alloc->ca, 0x00,
					   sizeof( L1_CELL_ALLOCATION_STR ) );
		for (i = 0; i < SIZE_OF_HOPPING_LIST; i++)
			{
				alloc->ca.hopping_list[i] = END_OF_HOPPING_LIST;
			}
		break;

		case FDD_CELL_INFO_PARAMS:
		 (void) memset( (void *) &alloc->fdd_cell_info_params,
			 0x00, sizeof( FDD_CELL_INFO_PARAMS_STR ) );
		 break;
	}
}

/************************************************************************************************************/

tOCT_UINT8 decode_variable_bit_map ( tOCT_UINT8 description[],
								 tOCT_UINT32 length_of_descr,
								 L1_ALLOCATION_UNION_STR *alloc,
								 type_of_freq_allocation type,
								 tOCT_UINT8 init_allocation_flag)
{
	tOCT_UINT32 origin_arfcn;
	tOCT_UINT32 freq;
	tOCT_UINT32 descr_index;
	tOCT_UINT32 rrfcn_cntr;
	tOCT_UINT32 i;
	tOCT_UINT8 tmp_byte;
	tOCT_UINT8 shift_cntr;

	if ( init_allocation_flag == TRUE )
	 {
		freqlist_init_allocation( type, alloc );
	 }
	GET_ORIGIN_ARFCN;
	i = 0;
	freq = origin_arfcn;
	if (type == BCCH_ALLOCATION)
	 {
		 alloc->ba.arfcns[i] = freq;
		 alloc->ba.nbr_of_arfcns++;
		 i++;
	 }
	else
	 {
		 alloc->ca.hopping_list[i] = freq;
		 i++;
	 }
	rrfcn_cntr = 1;
	descr_index = 2;
	tmp_byte = (tOCT_UINT8)(description[descr_index] << 1);
	shift_cntr = 1;
	while (descr_index < length_of_descr)
	 {
	 if (descr_index != 2)
		 {
		 tmp_byte = description[descr_index];
		 }
	 descr_index++;
	 while (shift_cntr < 8)
		 {
		 if (tmp_byte & 0x80)
			 {
			 freq = (rrfcn_cntr + origin_arfcn) % 1024;
			 if (type == BCCH_ALLOCATION)
				 {
				 if (i < GERAN_ARFCN_LIST_LENGTH)
					 {
					 alloc->ba.arfcns[i] = freq;
					 alloc->ba.nbr_of_arfcns++;
					 i++;
					 }
				 }
			 else
				 {
				 if (i < SIZE_OF_HOPPING_LIST)
					 {
					 alloc->ca.hopping_list[i] = freq;
					 i++;
					 }
				 }
			 }
		 tmp_byte <<= 1;
		 shift_cntr++;
		 rrfcn_cntr++;
		 }
	 shift_cntr = 0;
	 }

	if (type == CELL_ALLOCATION)
	 {
		sort_hopping_list( (L1_CELL_ALLOCATION_STR *) &alloc->ca );
	 }

	return( FREQLIST_DECODING_OK );
}

/************************************************************************************************************/

tOCT_UINT8 frequency_list_decode ( tOCT_UINT8 description[],
                             tOCT_UINT32 length_of_descr,
                             L1_ALLOCATION_UNION_STR *alloc,
                             type_of_freq_allocation type,
                             tOCT_UINT8 init_allocation_flag,
                             type_of_frequency_ie ie_type)

{
	tOCT_UINT8  tmp_byte;
	tOCT_UINT8  status;
	tOCT_UINT32 original_range;
	tOCT_UINT32 *freqs;     /* pointer to the array for decoded (abs.) frequencies. */
	status = FREQLIST_DECODING_OK;
	switch (ie_type)
	 {
		 case CELL_CHANNEL_DESCR:
		 case FREQUENCY_LIST:
		 case FREQUENCY_SHORT_LIST:
		 case NEIGHBOUR_CELL_DESCR:
		 case UMTS_NCELL_DESCR:
			tmp_byte = description[0] & FORMAT_ID_MASK_2;
			break;
		case NEIGHBOUR_CELL_DESCR_2:
			tmp_byte = description[0] & FORMAT_ID_MASK_1;
			break;
		default:
			return( FREQLIST_FORMAT_ID_UNKNOWN );
	}
	if (tmp_byte == VAR_BIT_MAP)
	{
		status = decode_variable_bit_map( description,
										  length_of_descr, alloc, type,
										  init_allocation_flag );
	}
	else if ((tmp_byte & BIT_MAP_0_MASK) == BIT_MAP_0)
	{
		status = decode_bit_map_0( description, length_of_descr,
								   alloc, type, init_allocation_flag );
	}
	else
	{
		if ((tmp_byte & RANGE_1024_MASK) == RANGE_1024)
			{
				original_range = ORIG_RANGE_1024;
			}
		else if (tmp_byte == RANGE_512)
			{
				original_range = ORIG_RANGE_512;
			}
		else if (tmp_byte == RANGE_256)
			{
				original_range = ORIG_RANGE_256;
			}
		else if (tmp_byte == RANGE_128)
			{
				original_range = ORIG_RANGE_128;
			}
		else
			{
				return(FREQLIST_FORMAT_ID_UNKNOWN);
			}

		freqs = (tOCT_UINT32 *) malloc(4*GERAN_ARFCN_LIST_LENGTH); /* 4 bytes for each 32 Neighbour cells. */
		assert(freqs!= NULL);

		unpack_range_n_description(description, freqs,
								   length_of_descr, original_range);
		status =  form_freq_result( freqs, alloc, type,
									init_allocation_flag );
		free(freqs);
	}


	return (status);

}

/************************************************************************************************************/

tOCT_UINT8 rmcp_csn1_field_read(
RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

	assert( rmcp_csn1_field_read_params_ptr != NULL &&
		rmcp_csn1_field_read_params_ptr->decoding_position != NULL &&
		rmcp_csn1_field_read_params_ptr->length <= 8 );

    if ( rmcp_csn1_field_read_params_ptr->bits_left < rmcp_csn1_field_read_params_ptr->length )
    {
        /* We don't have enough bits so we longjmp to error handling
         */
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_OUT_OF_BITS );
    }

	rmcp_csn1_field_read_params_ptr->bits_left -=
		rmcp_csn1_field_read_params_ptr->length;

	return ( gsm_lib_csn1_field_read
				(
				&rmcp_csn1_field_read_params_ptr->decoding_position,
				&rmcp_csn1_field_read_params_ptr->bit_index,
				rmcp_csn1_field_read_params_ptr->length,
				rmcp_csn1_field_read_params_ptr->padding
				)
		   );
}

/************************************************************************************************************/

void rmcp_bits_skip(
	RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr,
	tOCT_UINT16 no_of_bits_to_skip)
{
	tOCT_UINT16 temp;
	tOCT_UINT8 temp2;
	assert( rmcp_csn1_field_read_params_ptr != NULL &&
			rmcp_csn1_field_read_params_ptr->decoding_position != NULL );

	temp = no_of_bits_to_skip;

	while (temp > 0)
		{
			temp2 = temp < 8 ? (tOCT_UINT8) temp : 8;

			rmcp_csn1_field_read_params_ptr->length = temp2;
			(void) rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

			temp -= temp2;
		}
}

/************************************************************************************************************/

void rr_si_decoded_si1_dealloc(RR_DECODED_SI1_STR* decoded_si1)
{
	assert(decoded_si1 != NULL);

	if (decoded_si1->cell_allocation != NULL)
		{
			free(decoded_si1->cell_allocation);
			decoded_si1->cell_allocation = NULL;
		}
}

/************************************************************************************************************/

RR_DECODED_SI1_STR* rr_si_si1_decode(const tOCT_UINT8* byte_stream)
{
	RR_DECODED_SI1_STR* ret_val;    
    jmp_buf* err_buf;
	ret_val = (RR_DECODED_SI1_STR *) malloc(sizeof(RR_DECODED_SI1_STR));
	assert(ret_val!= NULL);

    /* for CSN.1 decoding;
     * Unfortunately we need to cast away the constness of byte_stream to
     * be able to use CSN.1 decoding functions...
     */
    err_buf = (jmp_buf *) malloc(sizeof(jmp_buf));
    assert(err_buf != NULL);

	tOCT_UINT8* decoding_position = (tOCT_UINT8*) byte_stream;

	sint8      bit_index;
    tOCT_UINT8 error_status;

	bit_index = 8;
	assert( decoding_position != NULL );

    /* prepare for decoding error
     */
    if ((error_status = (tOCT_UINT8) setjmp( *err_buf )) != 0)
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:

                /* flow-through */

            case RMCP_CSN1_ERROR_SYNTAX:

                logPrint(LOG_DEBUG, "Syntactically incorrect SI1");
                break;

            case RMCP_CSN1_ERROR_SEMANTIC:

                logPrint(LOG_DEBUG, "Semantically incorrect SI1");
                break;

            default:

                logPrint(LOG_DEBUG, "Unhandled situation in SI reception");
                break;
        }
        rr_si_decoded_si1_dealloc(ret_val);
        free(ret_val);
        ret_val = NULL;
    }
    else
    {
    	/* Cell Channel Description IE
    	 */
    	ret_val->cell_allocation = malloc(sizeof(L1_ALLOCATION_UNION_STR));
    	assert(ret_val->cell_allocation != NULL);

    	if (frequency_list_decode(
    		decoding_position,
    		RR_CELL_CHANNEL_DESCR_LEN,
    		ret_val->cell_allocation,
    		CELL_ALLOCATION,
    		TRUE,
    		CELL_CHANNEL_DESCR ) != FREQLIST_DECODING_OK)
        {
    			longjmp( *err_buf, RMCP_CSN1_ERROR_SYNTAX );
        }

        /* RACH Control Parameter IE is ignored.
         */

    	/* SI1 Rest Octets IE
    	 */
    	decoding_position += RR_CELL_CHANNEL_DESCR_LEN + RR_RACH_CTRL_PARAMS_LEN;

    	// Optional NCH position is omitted

    	if (gsm_lib_csn1_field_read(&decoding_position, &bit_index, 1, RR_SI_PADDING) == 1)
        {
    		(void) gsm_lib_csn1_field_read(&decoding_position, &bit_index, 5, 0);
        }
    	/* Band indicator
    	 */
    	ret_val->band_indicator = gsm_lib_csn1_field_read(&decoding_position, &bit_index, 1, RR_SI_PADDING);
    }
    free(err_buf);
    err_buf = NULL;
	return ret_val;
}

/************************************************************************************************************/

tOCT_UINT8 rr_si_si1_handle(const tOCT_UINT8* si1_ptr, FILE * fp, cellParams *params)
{
	RR_DECODED_SI1_STR* decoded_si1 = NULL;
	assert(NULL != si1_ptr);

	decoded_si1 = rr_si_si1_decode(si1_ptr);
	logPrint(LOG_DEBUG,"rr_si_si1_handle si1Cell = %d , params->cellId = %d \n", si1Cell, params->cellId);

	if(si1Cell != params->cellId && decoded_si1 != NULL)
    {   
        fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
        combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

        si1Cell = params->cellId;
    	fprintf(fp, "System Information-1 Elements\n");
    	fprintf(fp , "SI-1 Band Indicator = %d\n", decoded_si1->band_indicator );

        ind->noOfHoppingArfcns = 0;
        while (ind->noOfHoppingArfcns < SIZE_OF_HOPPING_LIST &&
               decoded_si1->cell_allocation->ca.hopping_list[ind->noOfHoppingArfcns] !=END_OF_HOPPING_LIST)
        {
            fprintf(fp , "SI-1-Hopping-List-ARFCN = %d\n", decoded_si1->cell_allocation->ca.hopping_list[ind->noOfHoppingArfcns] );
            ind->hoppingList[ind->noOfHoppingArfcns] = (tOCT_UINT16) decoded_si1->cell_allocation->ca.hopping_list[ind->noOfHoppingArfcns];
            ind->noOfHoppingArfcns++;
        }
        fprintf(fp , "##-------------------------------------------------------------##\n");

        sendReady->servingCellId = si1Cell;
        sendReady->siRcvd |= RR_SI1_MASK;
    }
	rr_si_decoded_si1_dealloc(decoded_si1);
	free(decoded_si1);
	decoded_si1 = NULL;

	return TRUE;
}

/************************************************************************************************************/

RR_DECODED_SI_HDR_STR* rr_si_bcch_header_decode(const char* msg)
{
	RR_DECODED_SI_HDR_STR* ret_val = NULL;
	assert(NULL != msg);
	 /* check Skip Indicator and Protocol Discriminator
	 */
	if ((0x00 == (msg[RR_BCCH_SI_L2_HDR_OFFSET + 1] & B1111_0000)) &&
		(RR_PROTOCOL_DISCRIMINATOR == (msg[RR_BCCH_SI_L2_HDR_OFFSET + 1] &
		B0000_1111)))
		{
		    ret_val = malloc(sizeof(RR_DECODED_SI_HDR_STR));
		    assert(ret_val!= NULL);
			ret_val->message_type = msg[RR_BCCH_SI_L2_HDR_OFFSET + 2];
			ret_val->l2_pseudo_length = 0;
			ret_val->l3_data_index = RR_BCCH_SI_HDR_LEN;
		}

	return ret_val;
}

/************************************************************************************************************/

RR_DECODED_SI2_STR* rr_si_si2_decode(const tOCT_UINT8* byte_stream)
{
	RR_DECODED_SI2_STR* ret_val;
    ret_val = (RR_DECODED_SI2_STR *) malloc(sizeof(RR_DECODED_SI2_STR));
    assert(ret_val!= NULL);

	assert(byte_stream != NULL);

	(void) memcpy(ret_val->neighbor_cell_description,
		byte_stream + RR_SI2_FREQ_LIST_IE_OFFSET,
		RR_NEIGHBOUR_CELLS_DESCR_LEN);

	ret_val->si2bis_expected =
		((*(byte_stream + RR_SI2_FREQ_LIST_IE_OFFSET)) >> 5) & B0000_0001;

	ret_val->ncc_permitted = *(byte_stream + RR_SI2_NCC_PERMITTED_IE_OFFSET);

	return ret_val;
}

void updateAndSortGsmNeighbourList(fxL2gListenModeSystemInfoInd* ind, GERAN_ARFCN_LIST_STR* temp_ba)
{

    T_CARRIER_NUMBER temp_arfcn;
    T_CARRIER_NUMBER already_used_arfcn = 0xFFFD;
    tOCT_UINT8 i;
    tOCT_UINT8 j;

    for (i = 0; i < temp_ba->nbr_of_arfcns; i++)
    {
        temp_arfcn = temp_ba->arfcns[i];
        for (j = 0; j < ind->noOfNeighbors; j++)
        {
            if (temp_arfcn == ind->arfcnNeighbors[j])
            {
                temp_arfcn = already_used_arfcn;
            }
        }
        if (temp_arfcn != already_used_arfcn && ind->noOfNeighbors < GERAN_ARFCN_LIST_LENGTH)
        {
            ind->arfcnNeighbors[ind->noOfNeighbors] = temp_arfcn;
            ind->noOfNeighbors++;
        }
    }
    // Sort
    qsort( (void *) ind->arfcnNeighbors, ind->noOfNeighbors, sizeof( T_CARRIER_NUMBER ), arfcn_list_cmp );

}


/************************************************************************************************************/

tOCT_UINT8 rr_si_si2_handle(const tOCT_UINT8* si2_data , FILE * fp, cellParams *params)
{
	RR_DECODED_SI2_STR* decoded_buffer = NULL;
	assert(NULL != si2_data);
	decoded_buffer = rr_si_si2_decode(si2_data);
	logPrint(LOG_DEBUG,"rr_si_si2_handle si2Cell = %d , params->cellId = %d \n", si2Cell, params->cellId);

	if(si2Cell != params->cellId && decoded_buffer != NULL)
	{
		tOCT_UINT8 i = 0;
		L1_ALLOCATION_UNION_STR* ba_list;
		si2Cell = params->cellId;
		fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
		combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

		ba_list = (L1_ALLOCATION_UNION_STR *) malloc(sizeof(L1_ALLOCATION_UNION_STR));
	    assert(ba_list!= NULL);

		if(FREQLIST_DECODING_OK == frequency_list_decode(
						decoded_buffer->neighbor_cell_description,
						RR_NEIGHBOUR_CELLS_DESCR_LEN,
						ba_list,
						BCCH_ALLOCATION,
						TRUE,
						NEIGHBOUR_CELL_DESCR))
		{
			fprintf(fp , "System Information-2 Elements\n");
			fprintf(fp , "SI-2 NCC Permitted = %d\n",decoded_buffer->ncc_permitted);
			fprintf(fp , "SI-2 SI2-BIS Expected = %d\n",decoded_buffer->si2bis_expected);

            /* Set SI2Bis flag as received if it is not expected*/
            if (FALSE == decoded_buffer->si2bis_expected)
            {
                sendReady->siRcvd |= RR_SI2BIS_MASK;
            }

            for(i=0; i< ba_list->ba.nbr_of_arfcns;i++)
			{
					fprintf(fp , "SI-2-Neighbor-Cell-ARFCN=%d\n",ba_list->ba.arfcns[i]);
			}
			fprintf(fp , "##-------------------------------------------------------------##\n");

            updateAndSortGsmNeighbourList(ind, &ba_list->ba);
			
            sendReady->servingCellId = si2Cell;
            sendReady->siRcvd |= RR_SI2_MASK;

		}
		free(ba_list);
        ba_list = NULL;
	}
	free(decoded_buffer);
	decoded_buffer = NULL;
	return TRUE;
}


tOCT_UINT8 rr_si_si2bis_handle(const tOCT_UINT8* si2bis_data , FILE * fp, cellParams *params)
{
	assert(NULL != si2bis_data);
	logPrint(LOG_DEBUG,"rr_si_si2bis_handle si2bisCell = %d , params->cellId = %d \n", si2bisCell, params->cellId);

    if(si2bisCell != params->cellId)
    {
		tOCT_UINT8  i = 0;
        tOCT_UINT8* si2bis_ext_bcch_freq_list_ie;
		L1_ALLOCATION_UNION_STR* ba_list;
        
		si2bisCell = params->cellId;
		fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
		combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

		ba_list = (L1_ALLOCATION_UNION_STR *) malloc(sizeof(L1_ALLOCATION_UNION_STR));
	    assert(ba_list!= NULL);

        si2bis_ext_bcch_freq_list_ie  = (tOCT_UINT8 *) malloc(RR_NEIGHBOUR_CELLS_DESCR_LEN);
        assert(si2bis_ext_bcch_freq_list_ie != NULL);
        memcpy(si2bis_ext_bcch_freq_list_ie, si2bis_data + RR_SI2BIS_FREQ_LIST_IE_OFFSET, RR_NEIGHBOUR_CELLS_DESCR_LEN);

        if(FREQLIST_DECODING_OK == frequency_list_decode(
						si2bis_ext_bcch_freq_list_ie,
						RR_NEIGHBOUR_CELLS_DESCR_LEN,
						ba_list,
						BCCH_ALLOCATION,
						TRUE,
						NEIGHBOUR_CELL_DESCR))
		{
		    for(i=0; i< ba_list->ba.nbr_of_arfcns;i++)
			{
					fprintf(fp , "SI-2bis-Neighbor-Cell-ARFCN=%d\n",ba_list->ba.arfcns[i]);
			}
			fprintf(fp , "##-------------------------------------------------------------##\n");

            updateAndSortGsmNeighbourList(ind, &ba_list->ba);

            sendReady->servingCellId = si2bisCell;
            sendReady->siRcvd |= RR_SI2BIS_MASK;
        }
        free(ba_list);
        ba_list = NULL;
    }

    return TRUE;
}


RR_DECODED_SI2TER_REST_OCTS_STR* rr_si_si2ter_rest_octs_decode(const tOCT_UINT8* byte_stream)
{

    RR_DECODED_SI2TER_REST_OCTS_STR* ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr;
    tOCT_UINT8 error_status;

    tOCT_UINT8 temp;

    ret_val = (RR_DECODED_SI2TER_REST_OCTS_STR *) malloc(sizeof(RR_DECODED_SI2TER_REST_OCTS_STR));
    assert(ret_val!= NULL);

    rmcp_csn1_field_read_params_ptr = (RMCP_CSN1_FIELD_READ_PARAMS_STR *) malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_csn1_field_read_params_ptr!= NULL);


    assert( byte_stream != NULL );

    rmcp_csn1_field_read_params_ptr->decoding_position = (tOCT_UINT8*) byte_stream;
    rmcp_csn1_field_read_params_ptr->bit_index = 8;
    rmcp_csn1_field_read_params_ptr->bits_left = RR_SI2TER_REST_OCTS_LEN * 8;
    rmcp_csn1_field_read_params_ptr->padding = 0x00;

    /* prepare for decoding error
     */
    if (( error_status = ( tOCT_UINT8) setjmp( rmcp_csn1_field_read_params_ptr->err_buf)) != 0 )
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:

                /* flow-through */

            case RMCP_CSN1_ERROR_SYNTAX:

                logPrint(LOG_DEBUG, "Syntactically incorrect SI2ter Rest Octs");
                break;

            case RMCP_CSN1_ERROR_SEMANTIC:

                logPrint(LOG_DEBUG, "Semantically incorrect SI2ter Rest Octs");
                break;

            default:

                logPrint(LOG_DEBUG, "Unhandled situation in SI reception");
                break;
        }
        free(ret_val);
        ret_val = NULL;
    }
    else
    {
        /* Skip H-bit
         */
        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );

        /* SI2ter_MP_CHANGE_MARK, SI2ter_3G_CHANGE_MARK, SI2ter_INDEX and
         * SI2ter_COUNT
         */
        rmcp_csn1_field_read_params_ptr->length = 1;
        ret_val->si2ter_mp_change_mark = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        ret_val->si2ter_3g_change_mark = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        rmcp_csn1_field_read_params_ptr->length = 3;
        ret_val->si2ter_index = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        ret_val->si2ter_count = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

        if (ret_val->si2ter_index > ret_val->si2ter_count)
        {
            longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SEMANTIC );
        }

        /* UTRAN FDD Description
         */
        rmcp_csn1_field_read_params_ptr->length = 1;
        ret_val->utran_fdd_descr_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        if (ret_val->utran_fdd_descr_present)
        {
            /* FDD-ARFCN
             */
            rmcp_csn1_field_read_params_ptr->length = 2;
            if ( B0000_0001 != rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX );
            }
            rmcp_csn1_field_read_params_ptr->length = 8;
            temp = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            rmcp_csn1_field_read_params_ptr->length = 6;
            ret_val->utran_fdd_descr.fdd_arfcn = (((tOCT_UINT16) temp) << 6) |
                ((tOCT_UINT16) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ));

            /* Bandwidth_FDD
             */
            rmcp_csn1_field_read_params_ptr->length = 1;
            ret_val->utran_fdd_descr.bandwidth_fdd_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            if (ret_val->utran_fdd_descr.bandwidth_fdd_present)
            {
                rmcp_csn1_field_read_params_ptr->length = 3;
                ret_val->utran_fdd_descr.bandwidth_fdd = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            }
        } /* end of UTRAN FDD Description */

        /* UTRAN TDD Description
         */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            /* TDD-ARFCN
             */
            rmcp_csn1_field_read_params_ptr->length = 2;
            if ( B0000_0001 != rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX );
            }
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 14 );

            /* Bandwidth_TDD
             */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
            }
        } /* end of UTRAN TDD Description */

        /* 3G Measurement Parameters Description
         */
        rmcp_csn1_field_read_params_ptr->length = 1;
        ret_val->umts_meas_pars_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        if (ret_val->umts_meas_pars_present)
        {
            /* Qsearch_I
             */
            rmcp_csn1_field_read_params_ptr->length = 4;
            ret_val->umts_meas_pars.qsearch_i = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

            /* FDD_Qoffset and FDD_Qmin
             */
            rmcp_csn1_field_read_params_ptr->length = 1;
            ret_val->umts_meas_pars.fdd_params_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            if (ret_val->umts_meas_pars.fdd_params_present)
            {
                rmcp_csn1_field_read_params_ptr->length = 4;
                ret_val->umts_meas_pars.fdd_params.fdd_qoffset = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                rmcp_csn1_field_read_params_ptr->length = 3;
                ret_val->umts_meas_pars.fdd_params.fdd_qmin = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            }

            /* TDD_Qoffset
             */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 4 );
            }
        } /* end of 3G Measurement Parameters Description */

        /* Rel 5 extension
         */
        ret_val->umts_addition_meas_pars_present = FALSE;

        if ( rmcp_csn1_field_read_params_ptr->bits_left > 0)
        {
            rmcp_csn1_field_read_params_ptr->length = 1;
            rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                /* 3G Additional Measurement Parameters Description
                 */
                rmcp_csn1_field_read_params_ptr->padding = 0x00;
                ret_val->umts_addition_meas_pars_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                if (ret_val->umts_addition_meas_pars_present)
                {
                    /* FDD_Qmin_Offset
                     */
                    rmcp_csn1_field_read_params_ptr->length = 3;
                    ret_val->umts_additional_meas_pars.fdd_qmin_offset = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

                    /* FDD_RSCPmin
                     */
                    rmcp_csn1_field_read_params_ptr->length = 4;
                    ret_val->umts_additional_meas_pars.fdd_rscpmin = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                }
            }
        }
    }

    free( rmcp_csn1_field_read_params_ptr );
    rmcp_csn1_field_read_params_ptr = NULL;

    return ret_val;
}

void rr_si_si2ter_rest_octs_delete(void)
{
    tOCT_UINT8 i;

    if (rr_si2ter_rest_octs.instances != NULL)
    {
        for (i = 0; i < rr_si2ter_rest_octs.si2ter_count + 1; i++)
        {
            if (rr_si2ter_rest_octs.instances[i] != NULL)
            {
                free(rr_si2ter_rest_octs.instances[i]);
                rr_si2ter_rest_octs.instances[i] = NULL;
            }
        }
        free(rr_si2ter_rest_octs.instances);
        rr_si2ter_rest_octs.instances = NULL;
    }
}

void rr_si_si2ter_rest_octs_store(void)
{
    tOCT_UINT16* fdd_arfcns = NULL;

    /* At the time the instances are gone through, following pointer is turned
     * to point to the same dynamically allocated SI2ter Rest Octets instance
     * as the pointer in "instance store" points to. Therefore, as there is
     * temporarily two pointers pointing to the same memory block, FOLLOWING
     * POINTER SHALL NOT BE USED FOR MEMORY DEALLOCATION.
     */
    tOCT_UINT32 tmp_band;

    tOCT_UINT8 no_of_fdd_arfcns = 0;
    tOCT_UINT8 i;
    tOCT_UINT8 storing_void_si2ter_rest_octs = TRUE;

    if (NULL != rr_si2ter_rest_octs.instances)
    {
        storing_void_si2ter_rest_octs = FALSE;

        for (i = 0; i < rr_si2ter_rest_octs.si2ter_count + 1; i++)
        {
            if (rr_si2ter_rest_octs.instances[i]->utran_fdd_descr_present)
            {
                tmp_band = CalculateBandUsingUarfcn(rr_si2ter_rest_octs.instances[i]->utran_fdd_descr.fdd_arfcn);

                if (FXL_UMTS_MAX_BAND_SUPPORTED != tmp_band)
                {
                    if (0 == no_of_fdd_arfcns)
                    {
                        fdd_arfcns = malloc(RR_SI2TER_REST_OCTS_MAX_AMOUNT * sizeof(tOCT_UINT16));
                    }

                    fdd_arfcns[no_of_fdd_arfcns++] = rr_si2ter_rest_octs.instances[i]->utran_fdd_descr.fdd_arfcn;
                }
            }
        }
    }

    if (storing_void_si2ter_rest_octs)
    {
        logPrint(LOG_DEBUG, "Void SI2ter Rest Octs -> SI-store");
    }
    else
    {
        logPrint(LOG_DEBUG, "SI2ter Rest Octs -> SI-store");
    }

    if (fdd_arfcns != NULL)
    {
        free(fdd_arfcns);
        fdd_arfcns = NULL;
    }
}


void rr_si_si2ter_rest_octs_handle(const tOCT_UINT8* rest_octets)
{
    RR_DECODED_SI2TER_REST_OCTS_STR* temp = NULL;
    tOCT_UINT8 instance_set_updated = FALSE;
    tOCT_UINT8 i;

    combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

    /* Decode received IE if it is present, i.e. first bit is H.*/
     
    // Otherwise we assume that the NW does not send SI2ter Rest Octets.
     
    if ((rest_octets[0] ^ RR_SI_PADDING) & B1000_0000)
    {
        temp = rr_si_si2ter_rest_octs_decode(rest_octets);

        /* erroneous instance causes restarting the reception
         */
        if (NULL == temp)
        {
            rr_si_si2ter_rest_octs_delete();
            sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2TER_MASK));
            return;
        }

        /* if this instance is the first one received or if the change marks
         * changed, reception is restarted and this instance's SI2ter_COUNT
         * and change marks are stored
         */
        if (NULL == rr_si2ter_rest_octs.instances ||
            temp->si2ter_mp_change_mark != rr_si2ter_rest_octs.si2ter_mp_change_mark ||
            temp->si2ter_3g_change_mark != rr_si2ter_rest_octs.si2ter_3g_change_mark)
        {
            rr_si_si2ter_rest_octs_delete();
            sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2TER_MASK));

            rr_si2ter_rest_octs.si2ter_count = temp->si2ter_count;
            rr_si2ter_rest_octs.si2ter_mp_change_mark = temp->si2ter_mp_change_mark;
            rr_si2ter_rest_octs.si2ter_3g_change_mark = temp->si2ter_3g_change_mark;

            rr_si2ter_rest_octs.instances = malloc((rr_si2ter_rest_octs.si2ter_count + 1) * sizeof(RR_DECODED_SI2TER_REST_OCTS_STR*));
            assert(rr_si2ter_rest_octs.instances != NULL);
            for (i = 0; i < rr_si2ter_rest_octs.si2ter_count + 1; i++)
            {
                rr_si2ter_rest_octs.instances[i] = NULL;
            }
        }
        else
        {
            /* check correctness of received SI2ter_COUNT; erroneous instance
             * causes restarting the reception
             */
            if (temp->si2ter_count != rr_si2ter_rest_octs.si2ter_count)
            {
                logPrint(LOG_DEBUG, "Semantically incorrect SI2ter Rest Octs");

                rr_si_si2ter_rest_octs_delete();
                sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2TER_MASK));

                free(temp);
                temp = NULL;
                return;
            }
        }

        /* received instance is stored if it hasn't been received earlier
         */
        if (NULL == rr_si2ter_rest_octs.instances[temp->si2ter_index])
        {
            rr_si2ter_rest_octs.instances[temp->si2ter_index] = temp;
            temp = NULL;
            instance_set_updated = TRUE;
        }
        else
        {
            free(temp);
            temp = NULL;
        }

        /* SI2ter is marked as received if all instances have been received
         */
        sendReady->siRcvd |= RR_SI2TER_MASK;
        for (i = 0; i < rr_si2ter_rest_octs.si2ter_count + 1; i++)
        {
            if (NULL == rr_si2ter_rest_octs.instances[i])
            {
                sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2TER_MASK));
                break;
            }
        }
    }
    else
    {
        /* if SI2ter Rest Octets are no longer used or if this was the
         * first received SI2ter message in the cell
         */
        if (NULL != rr_si2ter_rest_octs.instances ||
            (NULL == rr_si2ter_rest_octs.instances &&
            ((RR_SI2TER_MASK != sendReady->siRcvd) & RR_SI2TER_MASK)))
        {
            rr_si_si2ter_rest_octs_delete();
            sendReady->siRcvd |= RR_SI2TER_MASK;
            instance_set_updated = TRUE;
        }
    }

    if (instance_set_updated && ((RR_SI2TER_MASK == sendReady->siRcvd) & RR_SI2TER_MASK))
    {
        rr_si_si2ter_rest_octs_store();
    }
}


tOCT_UINT8 rr_si_si2ter_handle(const tOCT_UINT8* si2ter_data , FILE * fp, cellParams *params)
{
	assert(NULL != si2ter_data);
	logPrint(LOG_DEBUG,"rr_si_si2ter_handle si2bisCell = %d , params->cellId = %d \n", si2terCell, params->cellId);

    // rr_si_si2ter_rest_octs_handle(si2ter_data + RR_SI2TER_REST_OCTETS_IE_OFFSET);
    
    if(si2terCell != params->cellId)
    {
		tOCT_UINT8  i = 0;
        tOCT_UINT8* si2ter_ext_bcch_freq_list_ie;
		L1_ALLOCATION_UNION_STR* ba_list;
        
		si2terCell = params->cellId;
		fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
		combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

		ba_list = (L1_ALLOCATION_UNION_STR *) malloc(sizeof(L1_ALLOCATION_UNION_STR));
	    assert(ba_list!= NULL);

        si2ter_ext_bcch_freq_list_ie  = (tOCT_UINT8 *) malloc(RR_NEIGHBOUR_CELLS_DESCR_LEN);
        assert(si2ter_ext_bcch_freq_list_ie != NULL);
        memcpy(si2ter_ext_bcch_freq_list_ie, si2ter_data + RR_SI2TER_FREQ_LIST_IE_OFFSET, RR_NEIGHBOUR_CELLS_DESCR_LEN);

        if(FREQLIST_DECODING_OK == frequency_list_decode(
						si2ter_ext_bcch_freq_list_ie,
						RR_NEIGHBOUR_CELLS_DESCR_LEN,
						ba_list,
						BCCH_ALLOCATION,
						TRUE,
						NEIGHBOUR_CELL_DESCR_2))
		{
		    for(i=0; i< ba_list->ba.nbr_of_arfcns;i++)
			{
					fprintf(fp , "SI-2ter-Neighbor-Cell-ARFCN=%d\n",ba_list->ba.arfcns[i]);
			}
			fprintf(fp , "##-------------------------------------------------------------##\n");
            
            updateAndSortGsmNeighbourList(ind, &ba_list->ba);

            sendReady->servingCellId = si2terCell;
            sendReady->siRcvd |= RR_SI2TER_MASK;
        }
        free(ba_list);
        ba_list = NULL;
    }

    return TRUE;

}


void rmcp_utran_fdd_descr_dealloc(SI_UTRAN_FDD_DESCR_STR* const ptr)
{

    SI_REP_UTRAN_FDD_NCELLS_STR* temp_1 = NULL;
    SI_REP_UTRAN_FDD_NCELLS_STR* temp_2 = NULL;

    if (ptr != NULL)
    {
        temp_1 = ptr->rep_utran_fdd_ncells;

        while (temp_1 != NULL)
        {
            temp_2 = temp_1->next_ptr;
            free(temp_1);
            temp_1 = temp_2;
        }
        ptr->rep_utran_fdd_ncells = NULL;
    }
}

void rmcp_3g_ncell_descr_dealloc(SI_3G_NCELL_DESCR_STR* const ptr)
{
    if (ptr != NULL)
    {
        if (ptr->utran_fdd_descr != NULL)
        {
            rmcp_utran_fdd_descr_dealloc(ptr->utran_fdd_descr);
            free(ptr->utran_fdd_descr);
            ptr->utran_fdd_descr = NULL;
        }
    }
}

void rmcp_sysinfo_linked_list_free(S_SYSINFO_LINKED_LIST_STR* list_ptr)
{
    S_SYSINFO_LINKED_LIST_STR *help_ptr = NULL;

    while (list_ptr != NULL)
    {
        help_ptr = list_ptr->next_ptr;
        free(list_ptr );
        list_ptr = help_ptr;
    }
}

void rmcp_rep_utran_prio_dealloc(SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_ptr)
    {
    SI_REP_UTRAN_PRIORITY_PARAMS_STR* temp_1 = NULL;
    SI_REP_UTRAN_PRIORITY_PARAMS_STR* temp_2 = NULL;

    if (rep_utran_prio_ptr != NULL)
    {
        temp_1 = rep_utran_prio_ptr;

        while (temp_1 != NULL)
        {
            rmcp_sysinfo_linked_list_free((S_SYSINFO_LINKED_LIST_STR*) temp_1->rep_utran_freq_index);
            temp_2 = temp_1->next_ptr;
            free(temp_1);
            temp_1 = temp_2;
        }
        rep_utran_prio_ptr = NULL;
    }
}

void rmcp_rep_eutran_ncell_dealloc(SI_REP_EUTRAN_NCELL_STR* ptr)
{
    SI_REP_EUTRAN_NCELL_STR* temp_1 = NULL;
    SI_REP_EUTRAN_NCELL_STR* temp_2 = NULL;

    if (ptr != NULL)
    {
        temp_1 = ptr;

        while (temp_1 != NULL)
        {
            rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->rep_earfcn_meas_bandwidth_ptr);
            temp_2 = temp_1->next_ptr;
            free(temp_1);
            temp_1 = temp_2;
        }
        ptr = NULL;
    }
}

void rmcp_rep_eutran_na_cells_dealloc(SI_REP_EUTRAN_NA_CELLS_STR* ptr)
{
    SI_REP_EUTRAN_NA_CELLS_STR* temp_1 = NULL;
    SI_REP_EUTRAN_NA_CELLS_STR* temp_2 = NULL;

    if (ptr != NULL)
    {
        temp_1 = ptr;

        while (temp_1 != NULL)
        {
            /* Deallocate PCID group structure
                       */
            if (NULL != temp_1->not_allowed_cells.rep_explicit_pcid_ptr)
            {
                rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->not_allowed_cells.rep_explicit_pcid_ptr);
                temp_1->not_allowed_cells.rep_explicit_pcid_ptr = NULL;
            }

            if (NULL != temp_1->not_allowed_cells.rep_pcid_pattern_ptr)
            {
                rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->not_allowed_cells.rep_pcid_pattern_ptr);
                temp_1->not_allowed_cells.rep_pcid_pattern_ptr = NULL;
            }

            /* Deallocate repeated EUTRAN NA cells structure
                       */
            rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->rep_eutran_freq_index_ptr);
            temp_2 = temp_1->next_ptr;
            free(temp_1);
            temp_1 = temp_2;
        }
        ptr = NULL;
    }
}

void rmcp_rep_pcid_ta_mapping_dealloc(SI_REP_EUTRAN_PCID_TO_TA_STR* ptr)
{
    SI_REP_EUTRAN_PCID_TO_TA_STR* temp_1 = NULL;
    SI_REP_EUTRAN_PCID_TO_TA_STR* temp_2 = NULL;
    SI_REP_PCIDS_TA_STR* rep_pcid_ta_group_temp_ptr = NULL;

    if (ptr != NULL)
    {
        temp_1 = ptr;

        while (NULL != temp_1)
        {
            /* Deallocate repeated EUTRAN PCID to TA group structure
                       */

            while (NULL != temp_1->rep_pcid_ta_group_ptr)
            {
                if (NULL != temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_explicit_pcid_ptr)
                {
                    rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_explicit_pcid_ptr);
                    temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_explicit_pcid_ptr = NULL;
                }

                if (NULL != temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_pcid_pattern_ptr)
                {
                    rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_pcid_pattern_ptr);
                    temp_1->rep_pcid_ta_group_ptr->pcid_group.rep_pcid_pattern_ptr = NULL;
                }
                rep_pcid_ta_group_temp_ptr = temp_1->rep_pcid_ta_group_ptr->next_ptr;
                free(temp_1->rep_pcid_ta_group_ptr);
                temp_1->rep_pcid_ta_group_ptr = rep_pcid_ta_group_temp_ptr;
            }

            /* Deallocate repeated EUTRAN frequency index structure
                       */
            rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*)temp_1->rep_eutran_freq_index_ptr);
            temp_2 = temp_1->next_ptr;
            free(temp_1);
            temp_1 = temp_2;
        }
        ptr = NULL;
    }
}

/* ========================================================================= */

/* Functional description
 *
 * Function deallocates contents of decoded SI2quater.
 *
 * Notes
 *
 * Function does not deallocate structure pointed by 'decoded_si2quater',
 * thus the function can be used also for statically allocated structures of
 * type RR_DECODED_SI2QUATER_STR.
 */

/* ---------------------------------------------------------------------- */


void rr_si_decoded_si2quater_dealloc( RR_DECODED_SI2QUATER_STR* decoded_si2quater)
    {

    assert(decoded_si2quater != NULL);

    if (decoded_si2quater->gsm_3g_params != NULL)
    {
        free(decoded_si2quater->gsm_3g_params);
        decoded_si2quater->gsm_3g_params = NULL;
    }

    if (decoded_si2quater->umts_ncell_descr != NULL)
    {
        rmcp_3g_ncell_descr_dealloc(decoded_si2quater->umts_ncell_descr);
        free(decoded_si2quater->umts_ncell_descr);
        decoded_si2quater->umts_ncell_descr = NULL;
    }

    if (decoded_si2quater->nc_meas_params != NULL)
    {
        free(decoded_si2quater->nc_meas_params);
        decoded_si2quater->nc_meas_params = NULL;
    }

    if (NULL != decoded_si2quater->servcell_prio_params)
    {
        free(decoded_si2quater->servcell_prio_params);
        decoded_si2quater->servcell_prio_params = NULL;
    }

    if (NULL != decoded_si2quater->utran_prio_params)
    {
        if (NULL != decoded_si2quater->utran_prio_params->rep_utran_params_store)
        {
            rmcp_rep_utran_prio_dealloc(decoded_si2quater->utran_prio_params->rep_utran_params_store);
            decoded_si2quater->utran_prio_params->rep_utran_params_store = NULL;
        }
        free(decoded_si2quater->utran_prio_params);
        decoded_si2quater->utran_prio_params = NULL;
    }

    if (NULL != decoded_si2quater->rep_eutran_ncells_ptr)
    {
        rmcp_rep_eutran_ncell_dealloc(decoded_si2quater->rep_eutran_ncells_ptr);
    }    
            
    if (NULL != decoded_si2quater->rep_eutran_na_cells_ptr)
    {
        rmcp_rep_eutran_na_cells_dealloc(decoded_si2quater->rep_eutran_na_cells_ptr);
    }
    
    if  (NULL != decoded_si2quater->rep_pcid_to_ta_map_ptr)
    {
        rmcp_rep_pcid_ta_mapping_dealloc( decoded_si2quater->rep_pcid_to_ta_map_ptr);
    }            
}

void rmcp_func_pars_copy( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_pars_ptr_1, RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_pars_ptr_2 )
{
    rmcp_pars_ptr_2->padding = 0x00;
    rmcp_pars_ptr_1->decoding_position = rmcp_pars_ptr_2->decoding_position;
    rmcp_pars_ptr_1->bit_index = rmcp_pars_ptr_2->bit_index;
    rmcp_pars_ptr_1->bits_left = rmcp_pars_ptr_2->bits_left;
    rmcp_pars_ptr_1->padding = rmcp_pars_ptr_2->padding;
}

/************************************************************************************************************/
SI_NC_MEAS_PARS_STR* rmcp_nc_meas_pars_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr)
{

    SI_NC_MEAS_PARS_STR* ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_nc_meas_pars_decode_local_ptr;
    tOCT_UINT8 error_status;

    ret_val = malloc(sizeof(SI_NC_MEAS_PARS_STR));
    assert(ret_val != NULL);

	rmcp_nc_meas_pars_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_nc_meas_pars_decode_local_ptr != NULL);

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );

    rmcp_func_pars_copy( rmcp_nc_meas_pars_decode_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if (( error_status = (tOCT_UINT8)(setjmp(rmcp_nc_meas_pars_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_nc_meas_pars_decode_local_ptr );
        rmcp_nc_meas_pars_decode_local_ptr = NULL;
        free(ret_val);
        ret_val = NULL;
        longjmp(rmcp_csn1_field_read_params_ptr->err_buf, error_status);
    }
    else
    {
        /* NETWORK_CONTROL_ORDER
                */
        rmcp_nc_meas_pars_decode_local_ptr->length = 2;
        ret_val->nw_ctrl_order = rmcp_csn1_field_read(rmcp_nc_meas_pars_decode_local_ptr);

        /* check for reserved NETWORK_CONTROL_ORDER value
         */
        if (3 == ret_val->nw_ctrl_order)
        {
            longjmp( rmcp_nc_meas_pars_decode_local_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX);
        }

        /* NC_NON_DRX_PERIOD, NC_REPORTING_PERIOD_I and NC_REPORTING_PERIOD_T
                */
        rmcp_nc_meas_pars_decode_local_ptr->length = 1;
        ret_val->nc_params_present = rmcp_csn1_field_read( rmcp_nc_meas_pars_decode_local_ptr );
        if (ret_val->nc_params_present)
        {
            rmcp_nc_meas_pars_decode_local_ptr->length = 3;
            ret_val->nc_non_drx_period = rmcp_csn1_field_read(rmcp_nc_meas_pars_decode_local_ptr);
            ret_val->nc_reporting_period_i = rmcp_csn1_field_read(rmcp_nc_meas_pars_decode_local_ptr);
            ret_val->nc_reporting_period_t = rmcp_csn1_field_read(rmcp_nc_meas_pars_decode_local_ptr);
        }
    }

    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_nc_meas_pars_decode_local_ptr);

    free( rmcp_nc_meas_pars_decode_local_ptr );
    rmcp_nc_meas_pars_decode_local_ptr = NULL;

    return ret_val;
}

/* 
 * This function calculates length of FDD_CELL_INFORMATION according to
 * NR_OF_FDD_CELLS.
 *
 */

/* ---------------------------------------------------------------------- */


tOCT_UINT8 rmcp_fdd_cell_info_length_calc(tOCT_UINT8 nr_of_fdd_cells)
{
    /* this table is defined in 3GPP TS 04.18 (R99) / Table 9.1.54.1 */
    static const tOCT_UINT8 fdd_cell_info_lengths[] =
    {
        10,     /* nr_of_fdd_cells == 1 */
        19,     /* nr_of_fdd_cells == 2 */
        28,     /* nr_of_fdd_cells == 3 */
        36,     /* nr_of_fdd_cells == 4 */
        44,     /* nr_of_fdd_cells == 5 */
        52,     /* nr_of_fdd_cells == 6 */
        60,     /* nr_of_fdd_cells == 7 */
        67,     /* nr_of_fdd_cells == 8 */
        74,     /* nr_of_fdd_cells == 9 */
        81,     /* nr_of_fdd_cells == 10 */
        88,     /* nr_of_fdd_cells == 11 */
        95,     /* nr_of_fdd_cells == 12 */
        102,    /* nr_of_fdd_cells == 13 */
        109,    /* nr_of_fdd_cells == 14 */
        116,    /* nr_of_fdd_cells == 15 */
        122     /* nr_of_fdd_cells == 16 */
    };

    tOCT_UINT8 length = 0;

    if (nr_of_fdd_cells >= 1 && nr_of_fdd_cells <= 16)
    {
        length = fdd_cell_info_lengths[nr_of_fdd_cells - 1];
    }

    return length;
}

/************************************************************************************************************/
SI_UTRAN_FDD_DESCR_STR* rmcp_utran_fdd_descr_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr)
{
    /* Data Structures */

    SI_UTRAN_FDD_DESCR_STR* ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_utran_fdd_descr_decode_local_ptr;

    ret_val = malloc(sizeof(SI_UTRAN_FDD_DESCR_STR));
	assert(ret_val != NULL);

    SI_REP_UTRAN_FDD_NCELLS_STR** rep_utran_fdd_ncells_ptr = &ret_val->rep_utran_fdd_ncells;

    rmcp_utran_fdd_descr_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_utran_fdd_descr_decode_local_ptr != NULL);

    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;
    tOCT_UINT8 no_of_fdd_cell_information_bits;
    tOCT_UINT8 temp;
    tOCT_UINT8 i;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );

    rmcp_func_pars_copy( rmcp_utran_fdd_descr_decode_local_ptr, rmcp_csn1_field_read_params_ptr );
    ret_val->rep_utran_fdd_ncells = NULL;

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_utran_fdd_descr_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_utran_fdd_descr_decode_local_ptr );
        rmcp_utran_fdd_descr_decode_local_ptr = NULL;
        rmcp_utran_fdd_descr_dealloc(ret_val);
        free(ret_val);
        ret_val = NULL;
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {

        /* Bandwidth_FDD */
        rmcp_utran_fdd_descr_decode_local_ptr->length = 1;
        ret_val->bandwidth_fdd_present = rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr );
        if (ret_val->bandwidth_fdd_present)
        {
            rmcp_utran_fdd_descr_decode_local_ptr->length = 3;
            ret_val->bandwidth_fdd = rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr );
        }

        /* Repeated UTRAN FDD Neighbour Cells */
        rmcp_utran_fdd_descr_decode_local_ptr->length = 1;
        while ( rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr ))
        {
            *rep_utran_fdd_ncells_ptr = malloc(sizeof(SI_REP_UTRAN_FDD_NCELLS_STR));
            assert((*rep_utran_fdd_ncells_ptr) != NULL);
            (*rep_utran_fdd_ncells_ptr)->next_ptr = NULL;

            /* FDD_ARFCN or FDD_ARFCN_INDEX */
            if (0 == rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr ))
            {
                rmcp_utran_fdd_descr_decode_local_ptr->length = 8;
                temp =  rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr );
                rmcp_utran_fdd_descr_decode_local_ptr->length = 6;
                (*rep_utran_fdd_ncells_ptr)->explicit_fdd_arfcn = (((tOCT_UINT16) temp) << 6) | (tOCT_UINT16) rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr);

                if (FXL_UMTS_MAX_BAND_SUPPORTED == CalculateBandUsingUarfcn( (*rep_utran_fdd_ncells_ptr)->explicit_fdd_arfcn))
                {
                        (*rep_utran_fdd_ncells_ptr)->explicit_fdd_arfcn = UNSUPPORTED_NEIGHBOUR_ARFCN;
                }
            }
            else
            {
                longjmp(rmcp_utran_fdd_descr_decode_local_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX);
            }

            /* FDD_Indic0 */
            rmcp_utran_fdd_descr_decode_local_ptr->length = 1;
            (*rep_utran_fdd_ncells_ptr)->fdd_indic0 = rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr);

            /* NR_OF_FDD_CELLS */
            rmcp_utran_fdd_descr_decode_local_ptr->length = 5;
            (*rep_utran_fdd_ncells_ptr)->no_of_fdd_cells = rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr);

            /* FDD_CELL_INFORMATION Field */
            no_of_fdd_cell_information_bits = rmcp_fdd_cell_info_length_calc((*rep_utran_fdd_ncells_ptr)->no_of_fdd_cells);
            (void) memset((*rep_utran_fdd_ncells_ptr)->fdd_cell_information_field, 0x00,SI_FDD_CELL_INFO_FIELD_LENGTH);

            i = 0;
            while (no_of_fdd_cell_information_bits > 0)
            {
                /* MIN(no_of_fdd_cell_information_bits, 8) */
                temp = no_of_fdd_cell_information_bits < 8 ? no_of_fdd_cell_information_bits : 8;

                assert(i < SI_FDD_CELL_INFO_FIELD_LENGTH);

                rmcp_utran_fdd_descr_decode_local_ptr->length = temp;
                (*rep_utran_fdd_ncells_ptr)->fdd_cell_information_field[i++] = (rmcp_csn1_field_read(rmcp_utran_fdd_descr_decode_local_ptr)<<(8 - temp));
                no_of_fdd_cell_information_bits -= temp;
            }

            /* prepare for next Repeated UTRAN FDD Neighbour Cells struct */
            rep_utran_fdd_ncells_ptr = &(*rep_utran_fdd_ncells_ptr)->next_ptr;
            rmcp_utran_fdd_descr_decode_local_ptr->length = 1; /* For while-loop */
        }
    }

    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_utran_fdd_descr_decode_local_ptr);

    free( rmcp_utran_fdd_descr_decode_local_ptr );
    rmcp_utran_fdd_descr_decode_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
/* 
 * This function calculates length of TDD_CELL_INFORMATION according to
 * NR_OF_TDD_CELLS.
 *
 */
tOCT_UINT8 rmcp_tdd_cell_info_length_calc(tOCT_UINT8 nr_of_tdd_cells)
{

    /* this table is defined in 3GPP TS 04.18 (R99) / Table 9.1.54.1
     */
    static const tOCT_UINT8 tdd_cell_info_lengths[] =
    {
        9,   /* NR_OF_TDD_CELLS = 1 */
        17,  /* NR_OF_TDD_CELLS = 2 */
        25,  /* NR_OF_TDD_CELLS = 3 */
        32,  /* NR_OF_TDD_CELLS = 4 */
        39,  /* NR_OF_TDD_CELLS = 5 */
        46,  /* NR_OF_TDD_CELLS = 6 */
        53,  /* NR_OF_TDD_CELLS = 7 */
        59,  /* NR_OF_TDD_CELLS = 8 */
        65,  /* NR_OF_TDD_CELLS = 9 */
        71,  /* NR_OF_TDD_CELLS = 10 */
        77,  /* NR_OF_TDD_CELLS = 11 */
        83,  /* NR_OF_TDD_CELLS = 12 */
        89,  /* NR_OF_TDD_CELLS = 13 */
        95,  /* NR_OF_TDD_CELLS = 14 */
        101, /* NR_OF_TDD_CELLS = 15 */
        106, /* NR_OF_TDD_CELLS = 16 */
        111, /* NR_OF_TDD_CELLS = 17 */
        116, /* NR_OF_TDD_CELLS = 18 */
        121, /* NR_OF_TDD_CELLS = 19 */
        126  /* NR_OF_TDD_CELLS = 20 */
    };

    tOCT_UINT8 length = 0;

    if (nr_of_tdd_cells >= 1 && nr_of_tdd_cells <= 20)
    {
        length = tdd_cell_info_lengths[nr_of_tdd_cells - 1];
    }

    return length;
}

/************************************************************************************************************/
tOCT_UINT8 rmcp_utran_tdd_descr_skip( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{
    tOCT_UINT8 temp;
    tOCT_UINT8 tdd_indic0;
    tOCT_UINT8 no_of_tdd_cells;

    tdd_indic0= 0xff;
    no_of_tdd_cells = 0;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );

    /* Bandwidth_TDD*/
    rmcp_csn1_field_read_params_ptr->length = 1;
    if ( rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
    {
        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
    }

    /* Repeated UTRAN TDD Neighbour Cells */
    rmcp_csn1_field_read_params_ptr->length = 1;
    while ( rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
    {
        if (0 ==  rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
        {
            /* TDD_ARFCN */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 14 );
        }
        else
        {
            longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX);
        }

        /* TDD_Indic0 */
        rmcp_csn1_field_read_params_ptr->length = 1;
        tdd_indic0 = rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);
        no_of_tdd_cells += tdd_indic0;

        /* NR_OF_TDD_CELLS */
        rmcp_csn1_field_read_params_ptr->length = 5;
        temp = rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        /* TDD_CELL_INFORMATION Field */
        /* Values 21-31 of NR_OF_TDD_CELLS handled as no cells */
        if (temp < 21)
        {
            rmcp_bits_skip(rmcp_csn1_field_read_params_ptr, rmcp_tdd_cell_info_length_calc(temp) );

            no_of_tdd_cells += temp;
         }

        if (tdd_indic0 == 0 && (temp == 0 || temp >= 21))
        {
            no_of_tdd_cells++;
        }
        rmcp_csn1_field_read_params_ptr->length = 1;
    }

    return no_of_tdd_cells;
}

/************************************************************************************************************/
SI_REP_EUTRAN_NCELL_STR* rmcp_rep_eutran_ncell_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_REP_EUTRAN_NCELL_STR* ret_val = NULL;
    SI_REP_EUTRAN_NCELL_STR** rep_eutran_ncell_ptr = &ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_eu_ncell_decode_local_ptr;

    rmcp_eu_ncell_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_eu_ncell_decode_local_ptr != NULL);
    SI_REP_EARFCN_MEAS_BW_STR **temp_rep_earfcn_meas_bw_ptr = NULL;

    tOCT_UINT16 temp_earfcn;
    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_eu_ncell_decode_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_eu_ncell_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_eu_ncell_decode_local_ptr );
        rmcp_eu_ncell_decode_local_ptr = NULL;
        rmcp_rep_eutran_ncell_dealloc(ret_val);
        ret_val = NULL;
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {
        /* Repeated E-UTRAN Neighbour Cells */
        do
        {
            (*rep_eutran_ncell_ptr) = malloc(sizeof(SI_REP_EUTRAN_NCELL_STR));
    		assert((*rep_eutran_ncell_ptr) != NULL);

            (*rep_eutran_ncell_ptr)->next_ptr = NULL;
            (*rep_eutran_ncell_ptr)->rep_earfcn_meas_bandwidth_ptr = NULL;
            temp_rep_earfcn_meas_bw_ptr = &(*rep_eutran_ncell_ptr)->rep_earfcn_meas_bandwidth_ptr;

            /* Repeated EARFCN and Measurement bandwidth */
            rmcp_eu_ncell_decode_local_ptr->length = 1;
            rmcp_eu_ncell_decode_local_ptr->padding = 0x00;

            if (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr))
            {
                do
                {
                    (*temp_rep_earfcn_meas_bw_ptr) = malloc(sizeof(SI_REP_EARFCN_MEAS_BW_STR));
    		        assert((*temp_rep_earfcn_meas_bw_ptr) != NULL);

                    (*temp_rep_earfcn_meas_bw_ptr)->next_ptr = NULL;

                    rmcp_eu_ncell_decode_local_ptr->length = 8;
                    temp_earfcn = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr );
                    rmcp_eu_ncell_decode_local_ptr->length = 8;
                    (*temp_rep_earfcn_meas_bw_ptr)->earfcn = (((tOCT_UINT16) temp_earfcn) << 8) | (tOCT_UINT16) rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);

                    /* Measurement Bandwidth */
                    rmcp_eu_ncell_decode_local_ptr->length = 1;

                    /* Default value for Measurement Bandwidth */
                    (*temp_rep_earfcn_meas_bw_ptr)->meas_bandwidth = SI_EUTRAN_MEAS_BW_DEFAULT_VAL;

                    if (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr))
                    {
                        rmcp_eu_ncell_decode_local_ptr->length = 3;
                        (*temp_rep_earfcn_meas_bw_ptr)->meas_bandwidth = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);

                        if((*temp_rep_earfcn_meas_bw_ptr)->meas_bandwidth > 5)
                        {
                            (*temp_rep_earfcn_meas_bw_ptr)->meas_bandwidth = 5;
                        }
                    }

                    temp_rep_earfcn_meas_bw_ptr = &(*temp_rep_earfcn_meas_bw_ptr)->next_ptr;
                    rmcp_eu_ncell_decode_local_ptr->length = 1;
                } while (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr));
            }
            else
            {
                logPrint(LOG_ERR, "EARFCN-Measurement bandwidth field not present");
                longjmp( rmcp_eu_ncell_decode_local_ptr->err_buf, RMCP_CSN1_ERROR_SYNTAX );
            }

            /* EUTRAN_PRIORITY */
            rmcp_eu_ncell_decode_local_ptr->length = 1;

            /* Fill with Invalid EUTRAN priority value when not present */
            (*rep_eutran_ncell_ptr)->eutran_priority = SI_INVALID_EUTRAN_PRIORITY;

            if (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr))
            {
                rmcp_eu_ncell_decode_local_ptr->length = 3;
                (*rep_eutran_ncell_ptr)->eutran_priority = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);
            }

            /* THRESH_EUTRAN_high */
            rmcp_eu_ncell_decode_local_ptr->length = 5;
            (*rep_eutran_ncell_ptr)->thresh_eutran_high = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);

            /* THRESH_EUTRAN_low */
            rmcp_eu_ncell_decode_local_ptr->length = 1;

            /* If THRESH_E-UTRAN_low is not present, then THRESH_E-UTRAN_low
                       * shall take on the same value as THRESH_E-UTRAN_high. */
            (*rep_eutran_ncell_ptr)->thresh_eutran_low = (*rep_eutran_ncell_ptr)->thresh_eutran_high;

            if (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr))
            {
                rmcp_eu_ncell_decode_local_ptr->length = 5;
                (*rep_eutran_ncell_ptr)->thresh_eutran_low = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);
            }

            /* EUTRAN_QRXLEVMIN */
            rmcp_eu_ncell_decode_local_ptr->length = 1;

            /* Default value for EUTRAN_QRXLEVMIN */
            (*rep_eutran_ncell_ptr)->eutran_qrxlevmin = SI_EUTRAN_QRXLEVMIN_DEFAULT_VAL;

            if (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr))
            {
                rmcp_eu_ncell_decode_local_ptr->length = 5;
                (*rep_eutran_ncell_ptr)->eutran_qrxlevmin = rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr);
            }

            /* prepare for next Repeated E-UTRAN Neighbour Cells struct */
            rep_eutran_ncell_ptr = &(*rep_eutran_ncell_ptr)->next_ptr;
            rmcp_eu_ncell_decode_local_ptr->length = 1;
        } while (rmcp_csn1_field_read(rmcp_eu_ncell_decode_local_ptr));
    }    

    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_eu_ncell_decode_local_ptr);

    free( rmcp_eu_ncell_decode_local_ptr );
    rmcp_eu_ncell_decode_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
SI_PCID_GROUP_STR rmcp_pcid_group_ie_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_PCID_GROUP_STR ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_pcid_group_decode_local_ptr;

    rmcp_pcid_group_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_pcid_group_decode_local_ptr != NULL);

    SI_REP_PCID_STR **temp_rep_explicit_pcid_ptr = NULL;
    SI_REP_PCID_PATTERN_STR **temp_rep_pcid_pattern_ptr = NULL;
    tOCT_UINT16 temp_explicit_pcid;

    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;
    ret_val.rep_explicit_pcid_ptr = NULL;
    ret_val.rep_pcid_pattern_ptr = NULL;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_pcid_group_decode_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_pcid_group_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_pcid_group_decode_local_ptr );
        rmcp_pcid_group_decode_local_ptr = NULL;

        if(ret_val.rep_explicit_pcid_ptr != NULL )
        {
            rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*) ret_val.rep_explicit_pcid_ptr);
            ret_val.rep_explicit_pcid_ptr = NULL;
        }

        if( ret_val.rep_pcid_pattern_ptr != NULL)
        {
            rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*) ret_val.rep_pcid_pattern_ptr);
            ret_val.rep_pcid_pattern_ptr = NULL;
        }

        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {

        /* Repeated Explicit PCID */
        ret_val.rep_explicit_pcid_ptr = NULL;
        temp_rep_explicit_pcid_ptr = &ret_val.rep_explicit_pcid_ptr;

        rmcp_pcid_group_decode_local_ptr->length = 1;
        rmcp_pcid_group_decode_local_ptr->padding = 0x00;

        while (rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr))
        {
            *temp_rep_explicit_pcid_ptr = malloc(sizeof(SI_REP_PCID_STR));
            assert((*temp_rep_explicit_pcid_ptr) != NULL);

            (*temp_rep_explicit_pcid_ptr)->next_ptr = NULL;

            rmcp_pcid_group_decode_local_ptr->length = 8;
            temp_explicit_pcid = rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr );
            rmcp_pcid_group_decode_local_ptr->length = 1;
            (*temp_rep_explicit_pcid_ptr)->pcid = (((tOCT_UINT16) temp_explicit_pcid) << 1) | (tOCT_UINT16) rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr);

            temp_rep_explicit_pcid_ptr = &(*temp_rep_explicit_pcid_ptr)->next_ptr;
            rmcp_pcid_group_decode_local_ptr->length = 1;
        } 

        /* PCID_BITMAP_GROUP */
        rmcp_pcid_group_decode_local_ptr->length = 1;

        /* Fill pcid bitmap group present as FALSE */
        ret_val.pcid_bitmap_group_present = FALSE;

        if (rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr))
        {
            ret_val.pcid_bitmap_group_present = TRUE;
            rmcp_pcid_group_decode_local_ptr->length = 6;
            ret_val.pcid_bitmap_group = rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr);
        }

        /* Repeated PCID pattern */
        ret_val.rep_pcid_pattern_ptr = NULL;
        temp_rep_pcid_pattern_ptr = &ret_val.rep_pcid_pattern_ptr;

        rmcp_pcid_group_decode_local_ptr->length = 1;

        while (rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr))
        {
            *temp_rep_pcid_pattern_ptr = malloc(sizeof(SI_REP_PCID_PATTERN_STR));
            assert((*temp_rep_pcid_pattern_ptr) != NULL);

            (*temp_rep_pcid_pattern_ptr)->next_ptr = NULL;

            rmcp_pcid_group_decode_local_ptr->length = 3;
            (*temp_rep_pcid_pattern_ptr)->pcid_pattern_length = rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr );

            rmcp_pcid_group_decode_local_ptr->length = (*temp_rep_pcid_pattern_ptr)->pcid_pattern_length + 1;
            (*temp_rep_pcid_pattern_ptr)->pcid_pattern = rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr );

            rmcp_pcid_group_decode_local_ptr->length = 1;
            (*temp_rep_pcid_pattern_ptr)->pcid_pattern_sense = rmcp_csn1_field_read(rmcp_pcid_group_decode_local_ptr );

            temp_rep_pcid_pattern_ptr = &(*temp_rep_pcid_pattern_ptr)->next_ptr;
            rmcp_pcid_group_decode_local_ptr->length = 1;
        }
    }
    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_pcid_group_decode_local_ptr);

    free( rmcp_pcid_group_decode_local_ptr );
    rmcp_pcid_group_decode_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
SI_REP_EUTRAN_FREQ_INDEX_STR* rmcp_rep_eu_freq_index_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_REP_EUTRAN_FREQ_INDEX_STR* ret_val = NULL;
    SI_REP_EUTRAN_FREQ_INDEX_STR** rep_eu_freq_index_ptr = &ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_eu_freq_ind_dec_local_ptr;    
    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    rmcp_eu_freq_ind_dec_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_eu_freq_ind_dec_local_ptr != NULL);

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_eu_freq_ind_dec_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_eu_freq_ind_dec_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_eu_freq_ind_dec_local_ptr );
        rmcp_eu_freq_ind_dec_local_ptr = NULL;
        rmcp_sysinfo_linked_list_free( (S_SYSINFO_LINKED_LIST_STR*) ret_val);
        ret_val = NULL;
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {

        /* Repeated E-UTRAN frequency index */
        do
        {
            (*rep_eu_freq_index_ptr) = malloc(sizeof(SI_REP_EUTRAN_FREQ_INDEX_STR));
            assert((*rep_eu_freq_index_ptr) != NULL);

            (*rep_eu_freq_index_ptr)->next_ptr = NULL;

            /* E-UTRAN frequency index */
            rmcp_eu_freq_ind_dec_local_ptr->length = 3;
            rmcp_eu_freq_ind_dec_local_ptr->padding = 0x00;

            (*rep_eu_freq_index_ptr)->eutran_freq_index = rmcp_csn1_field_read(rmcp_eu_freq_ind_dec_local_ptr);

            /* prepare for next E-UTRAN frequency index struct */
            rep_eu_freq_index_ptr = &(*rep_eu_freq_index_ptr)->next_ptr;
            rmcp_eu_freq_ind_dec_local_ptr->length = 1;
        } while (rmcp_csn1_field_read(rmcp_eu_freq_ind_dec_local_ptr));
    }
    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_eu_freq_ind_dec_local_ptr);

    free( rmcp_eu_freq_ind_dec_local_ptr );
    rmcp_eu_freq_ind_dec_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
SI_REP_EUTRAN_NA_CELLS_STR* rmcp_rep_eutran_na_cells_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_REP_EUTRAN_NA_CELLS_STR* ret_val = NULL;
    SI_REP_EUTRAN_NA_CELLS_STR** rep_eutran_na_cells_ptr = &ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_eu_na_cells_dec_local_ptr;
    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    rmcp_eu_na_cells_dec_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_eu_na_cells_dec_local_ptr != NULL);

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_eu_na_cells_dec_local_ptr,rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_eu_na_cells_dec_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_eu_na_cells_dec_local_ptr );
        rmcp_eu_na_cells_dec_local_ptr = NULL;
        if(NULL != ret_val)
        {
            rmcp_rep_eutran_na_cells_dealloc(ret_val);
            ret_val = NULL;
        }
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {
        /* Repeated E-UTRAN Not Allowed Cells */
        do
        {
            (*rep_eutran_na_cells_ptr) = malloc(sizeof(SI_REP_EUTRAN_NA_CELLS_STR));
            assert((*rep_eutran_na_cells_ptr) != NULL);

            (*rep_eutran_na_cells_ptr)->next_ptr = NULL;
            (*rep_eutran_na_cells_ptr)->not_allowed_cells.rep_explicit_pcid_ptr = NULL;
            (*rep_eutran_na_cells_ptr)->not_allowed_cells.rep_pcid_pattern_ptr = NULL;
            (*rep_eutran_na_cells_ptr)->rep_eutran_freq_index_ptr = NULL;

            /* Not Allowed Cells */
            (*rep_eutran_na_cells_ptr)->not_allowed_cells = rmcp_pcid_group_ie_decode(rmcp_eu_na_cells_dec_local_ptr);

            /* Repeated E-UTRAN_FREQUENCY_INDEX */
            rmcp_eu_na_cells_dec_local_ptr->length = 1;
            rmcp_eu_na_cells_dec_local_ptr->padding = 0x00;

            if (rmcp_csn1_field_read(rmcp_eu_na_cells_dec_local_ptr))
            {
                (*rep_eutran_na_cells_ptr)->rep_eutran_freq_index_ptr = rmcp_rep_eu_freq_index_decode(rmcp_eu_na_cells_dec_local_ptr);
            }

            /* prepare for next Repeated E-UTRAN Not Allowed Cells struct */
            rep_eutran_na_cells_ptr = &(*rep_eutran_na_cells_ptr)->next_ptr;
            rmcp_eu_na_cells_dec_local_ptr->length = 1;
        } while (rmcp_csn1_field_read(rmcp_eu_na_cells_dec_local_ptr));
    }

    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_eu_na_cells_dec_local_ptr);

    free( rmcp_eu_na_cells_dec_local_ptr );
    rmcp_eu_na_cells_dec_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
SI_REP_EUTRAN_PCID_TO_TA_STR* rmcp_rep_pcid_ta_mapping_decode(RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_REP_EUTRAN_PCID_TO_TA_STR* ret_val = NULL;
    SI_REP_EUTRAN_PCID_TO_TA_STR** rep_eutran_pcid_to_ta_ptr = &ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_pcid_to_ta_dec_local_ptr;
    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    rmcp_pcid_to_ta_dec_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_pcid_to_ta_dec_local_ptr != NULL);

    SI_REP_PCIDS_TA_STR** temp_rep_pcid_ta_group_ptr = NULL;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_pcid_to_ta_dec_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_pcid_to_ta_dec_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_pcid_to_ta_dec_local_ptr );
        rmcp_pcid_to_ta_dec_local_ptr = NULL;
        rmcp_rep_pcid_ta_mapping_dealloc(ret_val);
        ret_val = NULL;
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {
        /* Repeated E-UTRAN PCID to TA mapping */
        do
        {
            (*rep_eutran_pcid_to_ta_ptr) = malloc(sizeof(SI_REP_EUTRAN_PCID_TO_TA_STR));
            assert((*rep_eutran_pcid_to_ta_ptr) != NULL);

            (*rep_eutran_pcid_to_ta_ptr)->next_ptr = NULL;
            (*rep_eutran_pcid_to_ta_ptr)->rep_pcid_ta_group_ptr=NULL;
            (*rep_eutran_pcid_to_ta_ptr)->rep_eutran_freq_index_ptr = NULL;

            /* Repeated Not Allowed Cells */
            (*rep_eutran_pcid_to_ta_ptr)->rep_pcid_ta_group_ptr = NULL;
            temp_rep_pcid_ta_group_ptr = &(*rep_eutran_pcid_to_ta_ptr)->rep_pcid_ta_group_ptr;

            rmcp_pcid_to_ta_dec_local_ptr->length = 1;
            rmcp_pcid_to_ta_dec_local_ptr->padding = 0x00;

            while (rmcp_csn1_field_read(rmcp_pcid_to_ta_dec_local_ptr))
            {
                
    			(*temp_rep_pcid_ta_group_ptr) = malloc(sizeof(SI_REP_PCIDS_TA_STR));
    			assert((*temp_rep_pcid_ta_group_ptr) != NULL);

                (*temp_rep_pcid_ta_group_ptr)->next_ptr = NULL;
                (*temp_rep_pcid_ta_group_ptr)->pcid_group.rep_explicit_pcid_ptr=NULL;
                (*temp_rep_pcid_ta_group_ptr)->pcid_group.rep_pcid_pattern_ptr=NULL;
               
                (*temp_rep_pcid_ta_group_ptr)->pcid_group = rmcp_pcid_group_ie_decode(rmcp_pcid_to_ta_dec_local_ptr);

                temp_rep_pcid_ta_group_ptr = &(*temp_rep_pcid_ta_group_ptr)->next_ptr;
                rmcp_pcid_to_ta_dec_local_ptr->length = 1;
            } 
                
            /* Repeated E-UTRAN_FREQUENCY_INDEX */
                rmcp_pcid_to_ta_dec_local_ptr->length = 1;  
            if (rmcp_csn1_field_read(rmcp_pcid_to_ta_dec_local_ptr))
            {
                (*rep_eutran_pcid_to_ta_ptr)->rep_eutran_freq_index_ptr = rmcp_rep_eu_freq_index_decode( rmcp_pcid_to_ta_dec_local_ptr);
            }

            /* prepare for next Repeated E-UTRAN PCID to TA mapping struct */
         
            rep_eutran_pcid_to_ta_ptr = &(*rep_eutran_pcid_to_ta_ptr)->next_ptr;
            rmcp_pcid_to_ta_dec_local_ptr->length = 1;
        } while (rmcp_csn1_field_read(rmcp_pcid_to_ta_dec_local_ptr));
    }
    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_pcid_to_ta_dec_local_ptr);

    free( rmcp_pcid_to_ta_dec_local_ptr );
    rmcp_pcid_to_ta_dec_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
SI_REP_UTRAN_PRIORITY_PARAMS_STR* rmcp_rep_utran_prio_para_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{

    SI_REP_UTRAN_PRIORITY_PARAMS_STR* ret_val = NULL;

    SI_REP_UTRAN_PRIORITY_PARAMS_STR** rep_utran_prio_params_ptr = &ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_utran_prio_decode_local_ptr;

    rmcp_utran_prio_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_utran_prio_decode_local_ptr != NULL);
    
    SI_REP_UTRAN_FREQ_INDEX_STR** temp_utran_freq_index_ptr = NULL;
    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    assert( rmcp_csn1_field_read_params_ptr != NULL && rmcp_csn1_field_read_params_ptr->decoding_position != NULL );
    rmcp_func_pars_copy( rmcp_utran_prio_decode_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if ((error_status = (tOCT_UINT8)(setjmp(rmcp_utran_prio_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_utran_prio_decode_local_ptr );
        rmcp_utran_prio_decode_local_ptr = NULL;
        rmcp_rep_utran_prio_dealloc(ret_val);
        ret_val = NULL;
        longjmp( rmcp_csn1_field_read_params_ptr->err_buf, error_status );
    }
    else
    {
        /* Repeated UTRAN Priority Parameters */
        do
        {               
            /* Repeated UTRAN Frequency Index */
            rmcp_utran_prio_decode_local_ptr->length = 1;
            rmcp_utran_prio_decode_local_ptr->padding = 0x00;

            if (rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr))
            {
            
                (*rep_utran_prio_params_ptr) = malloc(sizeof(SI_REP_UTRAN_PRIORITY_PARAMS_STR));
                assert((*rep_utran_prio_params_ptr) != NULL);

                (*rep_utran_prio_params_ptr)->next_ptr = NULL;
                (*rep_utran_prio_params_ptr)->rep_utran_freq_index = NULL;
                temp_utran_freq_index_ptr = &(*rep_utran_prio_params_ptr)->rep_utran_freq_index;

                do
                {
                    (*temp_utran_freq_index_ptr) = malloc(sizeof(SI_REP_UTRAN_FREQ_INDEX_STR));
                    assert((*temp_utran_freq_index_ptr) != NULL);

                    (*temp_utran_freq_index_ptr)->next_ptr = NULL;

                    rmcp_utran_prio_decode_local_ptr->length = 5;
                    (*temp_utran_freq_index_ptr)->utran_freq_index = rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr);
                    temp_utran_freq_index_ptr = &(*temp_utran_freq_index_ptr)->next_ptr;
                    rmcp_utran_prio_decode_local_ptr->length = 1;
                } while (rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr));
            
                /* UTRAN_PRIORITY */
                (*rep_utran_prio_params_ptr)->utran_priority = SI_INVALID_UTRAN_PRIORITY;
                rmcp_utran_prio_decode_local_ptr->length = 1;
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    rmcp_utran_prio_decode_local_ptr->length = 3;
                    (*rep_utran_prio_params_ptr)->utran_priority = rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr);
                }

                /* THRESH_UTRAN_high */
                (*rep_utran_prio_params_ptr)->thresh_utran_high = SI_INVALID_THRESH_UTRAN;
                rmcp_utran_prio_decode_local_ptr->length = 5;
                (*rep_utran_prio_params_ptr)->thresh_utran_high = rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr);

                /* THRESH_UTRAN_low */

                /* If THRESH_UTRAN_low is not present, then THRESH_UTRAN_low shall
                          * take on the same value as THRESH_UTRAN_high.
                          */
                (*rep_utran_prio_params_ptr)->thresh_utran_low = (*rep_utran_prio_params_ptr)->thresh_utran_high;
                rmcp_utran_prio_decode_local_ptr->length = 1;
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    rmcp_utran_prio_decode_local_ptr->length = 5;
                    (*rep_utran_prio_params_ptr)->thresh_utran_low = rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr);
                }

                 /* UTRAN_QRXLEVMIN */

                /* Fill the default value for UTRAN_QRXLEVMIN. */
                (*rep_utran_prio_params_ptr)->utran_qrxlevmin = SI_UTRAN_QRXLEVMIN_DEFAULT_VAL;
                rmcp_utran_prio_decode_local_ptr->length = 1;
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    rmcp_utran_prio_decode_local_ptr->length = 5;
                    (*rep_utran_prio_params_ptr)->utran_qrxlevmin = rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr);
                }

                rep_utran_prio_params_ptr = &(*rep_utran_prio_params_ptr)->next_ptr;
            }
            else
            {
                logPrint(LOG_ERR, "Incorrect SI2quater Repeated UTRAN Priority Parameter Ignored");
                rmcp_utran_prio_decode_local_ptr->length  = 1;
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    /* Skip over UTRAN_PRIORITY */
                    rmcp_bits_skip( rmcp_utran_prio_decode_local_ptr, 3 ); 
                }
                /* Skip over THRESH_UTRAN_high */ 
                rmcp_bits_skip( rmcp_utran_prio_decode_local_ptr, 5 );

                rmcp_utran_prio_decode_local_ptr->length = 1; 
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    /* Skip over THRESH_UTRAN_low */
                    rmcp_bits_skip( rmcp_utran_prio_decode_local_ptr, 5 );
                }
                rmcp_utran_prio_decode_local_ptr->length = 1;
                if ( rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr ))
                {
                    /* Skip over UTRAN_QRXLEVMIN */
                    rmcp_bits_skip( rmcp_utran_prio_decode_local_ptr, 5 ); 
                }

            }
            /* prepare for next Repeated UTRAN priority parameters struct */
            rmcp_utran_prio_decode_local_ptr->length = 1;
        } while (rmcp_csn1_field_read(rmcp_utran_prio_decode_local_ptr));
        /* end of Repeated UTRAN Priority Parameters */

    }
    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_utran_prio_decode_local_ptr);

    free( rmcp_utran_prio_decode_local_ptr );
    rmcp_utran_prio_decode_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
static void rr_si_si2quater_delete(void)
{
    tOCT_UINT8 i;

    if (rr_si2quater.instances != NULL)
    {
        for (i = 0; i < rr_si2quater.si2quater_count + 1; i++)
        {
            if (rr_si2quater.instances[i] != NULL)
            {
                rr_si_decoded_si2quater_dealloc(rr_si2quater.instances[i]);
                free(rr_si2quater.instances[i]);
                rr_si2quater.instances[i] = NULL;
            }
        }
        free(rr_si2quater.instances);
        rr_si2quater.instances = NULL;
    }

    rr_si2quater.fast_acq_utran_start_index = SI2QUATER_INVALID_INDEX;
    rr_si2quater.fast_acq_utran_stop_index  = SI2QUATER_INVALID_INDEX;
    rr_si2quater.fast_acq_utran_status = RR_FAST_ACQ_INCOMPLETE;

    rr_si2quater.fast_acq_eutran_start_index = SI2QUATER_INVALID_INDEX; 
    rr_si2quater.fast_acq_eutran_stop_index = SI2QUATER_INVALID_INDEX;
    rr_si2quater.fast_acq_eutran_status = RR_FAST_ACQ_INCOMPLETE;
}

void rmcp_si_ncell_list_bitmap_write( SI_NCELL_LIST_BITMAP_STR* bitmap_ptr, tOCT_UINT8 cell_index, tOCT_UINT8 bit_value)
{
    assert(bitmap_ptr != NULL && cell_index < SI_NCELL_LIST_SIZE);

    if (bit_value)
    {
        bitmap_ptr->bits[(tOCT_UINT8) cell_index / 8] |= (B0000_0001 << (7 - ((tOCT_UINT8) cell_index % 8)));
    }
    else
    {
        bitmap_ptr->bits[(tOCT_UINT8) cell_index / 8] &= ~((tOCT_UINT8) (B0000_0001 << (7 - ((tOCT_UINT8) cell_index % 8))));
    }
}

SI_NCELL_LIST_BITMAP_STR* rmcp_ccn_supported_decode( RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr )
{
    SI_NCELL_LIST_BITMAP_STR* ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_ccn_supported_decode_local_ptr;

    ret_val = malloc( sizeof(SI_NCELL_LIST_BITMAP_STR));
    assert(ret_val != NULL);

    rmcp_ccn_supported_decode_local_ptr = malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_ccn_supported_decode_local_ptr != NULL);

    /* for handling errors in CSN.1 coding
     */
    tOCT_UINT8 error_status;

    tOCT_UINT8 temp;
    tOCT_UINT8 i;
    tOCT_UINT8 no_of_cells;

    assert( rmcp_csn1_field_read_params_ptr != NULL &&
            rmcp_csn1_field_read_params_ptr->decoding_position != NULL );

    no_of_cells = 0;

    rmcp_csn1_field_read_params_ptr->padding = 0x00;

    rmcp_func_pars_copy(rmcp_ccn_supported_decode_local_ptr, rmcp_csn1_field_read_params_ptr );

    /* prepare for error handling
     */
    if (( error_status = ( tOCT_UINT8)(setjmp( rmcp_ccn_supported_decode_local_ptr->err_buf))) != 0)
    {
        /* decoding error has occurred; we deallocate all dynamically allocated
         * memory and signal error to caller
         */
        free( rmcp_ccn_supported_decode_local_ptr );
        rmcp_ccn_supported_decode_local_ptr = NULL;
        free(ret_val);
        ret_val = NULL;
        longjmp(rmcp_csn1_field_read_params_ptr->err_buf, error_status);
    }
    else
    {
        /* Number_Cells
         */
        rmcp_ccn_supported_decode_local_ptr->length = 7;
        no_of_cells =  rmcp_csn1_field_read( rmcp_ccn_supported_decode_local_ptr );

        /* fill bitmap
         */
        (void) memset(ret_val, 0x00, sizeof(SI_NCELL_LIST_BITMAP_STR));

        rmcp_ccn_supported_decode_local_ptr->length = 1;
        rmcp_ccn_supported_decode_local_ptr->padding = 0xFF;

        for (i = 0; i < SI_NCELL_LIST_SIZE; i++)
        {
            if (no_of_cells > 0)
            {
                --no_of_cells;
                temp = rmcp_csn1_field_read(
                    rmcp_ccn_supported_decode_local_ptr );
                rmcp_si_ncell_list_bitmap_write(ret_val, i, (tOCT_UINT8) temp);
            }
            else
            {
                rmcp_si_ncell_list_bitmap_write(ret_val, i, TRUE);
            }
        }

        rmcp_ccn_supported_decode_local_ptr->padding = 0x00;
        rmcp_bits_skip( rmcp_ccn_supported_decode_local_ptr, no_of_cells );
    }

    rmcp_func_pars_copy( rmcp_csn1_field_read_params_ptr, rmcp_ccn_supported_decode_local_ptr);

    free( rmcp_ccn_supported_decode_local_ptr );
    rmcp_ccn_supported_decode_local_ptr = NULL;

    return ret_val;
}

/************************************************************************************************************/
RR_DECODED_SI2QUATER_STR* rr_si_si2quater_decode(const tOCT_UINT8* byte_stream)
{
    tOCT_UINT8 i;
    RR_DECODED_SI2QUATER_STR* decoded_si2q_ptr;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr;

    decoded_si2q_ptr = (RR_DECODED_SI2QUATER_STR *) malloc(sizeof(RR_DECODED_SI2QUATER_STR));
    assert(decoded_si2q_ptr!= NULL);

    rmcp_csn1_field_read_params_ptr = (RMCP_CSN1_FIELD_READ_PARAMS_STR *) malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
	assert(rmcp_csn1_field_read_params_ptr!= NULL);

    /* for CSN.1 decoding
     */
    tOCT_UINT8 error_status;
	tOCT_UINT16 temp;
    tOCT_UINT16 temp_bits_left = 0;

    assert( byte_stream != NULL );

    rmcp_csn1_field_read_params_ptr->decoding_position = (tOCT_UINT8*) byte_stream;
    rmcp_csn1_field_read_params_ptr->bit_index = 8;
    rmcp_csn1_field_read_params_ptr->bits_left = RR_SI2QUATER_REST_OCTS_LEN * 8;
    rmcp_csn1_field_read_params_ptr->padding = 0x00;

    /* initialize all information to be not-present */
    memset(decoded_si2q_ptr, 0x00, sizeof(RR_DECODED_SI2QUATER_STR));
	
    decoded_si2q_ptr->gsm_3g_params = NULL;
    decoded_si2q_ptr->umts_ncell_descr = NULL;
    decoded_si2q_ptr->nc_meas_params = NULL;
    decoded_si2q_ptr->servcell_prio_params = NULL;
    decoded_si2q_ptr->utran_prio_params = NULL;
    decoded_si2q_ptr->utran_start = 0;
    decoded_si2q_ptr->utran_stop = 0;
    decoded_si2q_ptr->rep_eutran_ncells_ptr = NULL;
    decoded_si2q_ptr->rep_eutran_na_cells_ptr= NULL;
    decoded_si2q_ptr->rep_pcid_to_ta_map_ptr= NULL;
    decoded_si2q_ptr->eutran_start =0;
    decoded_si2q_ptr->eutran_stop =0;
    decoded_si2q_ptr->gsm_reporting_params_present = FALSE;

    /* prepare for decoding error
     */
    if (( error_status = ( tOCT_UINT8 ) setjmp( rmcp_csn1_field_read_params_ptr->err_buf )) != 0 )
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:

                /* flow-through */

            case RMCP_CSN1_ERROR_SYNTAX:

                logPrint(LOG_DEBUG, "Syntactically incorrect SI2quater\n");
                break;

            case RMCP_CSN1_ERROR_SEMANTIC:

                logPrint(LOG_DEBUG, "Semantically incorrect SI2quater\n");
                break;

            default:

                logPrint(LOG_DEBUG, "Unhandled situation in SI reception\n");
                break;
        }
        rr_si_decoded_si2quater_dealloc(decoded_si2q_ptr);
        free(decoded_si2q_ptr);
        decoded_si2q_ptr = NULL;
        free( rmcp_csn1_field_read_params_ptr );
        rmcp_csn1_field_read_params_ptr = NULL;

        return NULL;
    }
    else
    {
        /* BA_IND, 3G_BA_IND, MP_CHANGE_MARK, SI2QUATER_INDEX and SI2QUATER_COUNT */
        rmcp_csn1_field_read_params_ptr->length = 1;

        decoded_si2q_ptr->ba_ind = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        decoded_si2q_ptr->umts_ba_ind = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        decoded_si2q_ptr->mp_change_mark = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

        rmcp_csn1_field_read_params_ptr->length = 4;
    	
        decoded_si2q_ptr->si2quater_index = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        decoded_si2q_ptr->si2quater_count = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

        if (decoded_si2q_ptr->si2quater_index > decoded_si2q_ptr->si2quater_count)
        {
            logPrint(LOG_ERR, "si2quater_index > si2quater_count, not decoding this instance of SI2-Q");
            longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SEMANTIC );
        }

        /* Measurement Parameters Description */
        rmcp_csn1_field_read_params_ptr->length = 1;
        decoded_si2q_ptr->gsm_reporting_params_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        if (decoded_si2q_ptr->gsm_reporting_params_present)
        {
            decoded_si2q_ptr->gsm_reporting_params.report_type = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

            rmcp_csn1_field_read_params_ptr->length = 2;
            decoded_si2q_ptr->gsm_reporting_params.serving_band_reporting = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
        }

        /* GPRS Real Time Difference Description  - Complete structure is Ignored */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            /* first iteration is for 6-bit RTDs and second iteration is for 12-bit RTDs */
            for (i = 0; i < 2; i++)
            {
                rmcp_csn1_field_read_params_ptr->length = 1;
                if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                {
                    /* BA_Index_Start_RTD / Cell_Index_Start_RTD */
                    if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                    {
                        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 5 );
                    }

                    /* RTDs; loop until there is no more BA(list) / GSM Neighbour Cell list indexes */
                    do
                    {
                        rmcp_csn1_field_read_params_ptr->length = 1;
                        while ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) == 0 )
                        {
                            if(i == 0) /* 6-bit RTDs */
    						  rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
    						else      /* 12-bit RTDs */
                              rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 12 );

                            rmcp_csn1_field_read_params_ptr->padding = 0x00;
                            rmcp_csn1_field_read_params_ptr->length = 1;
                        }

                        rmcp_csn1_field_read_params_ptr->length = 1;
                    } while ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) == 0 );
                }
            }
        }

        /* GPRS BSIC Description - Complete structure is Ignored */
        if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            tOCT_UINT8 no_remaining_bsic;

            /* BA_Index_Start_BSIC and first BSIC
                    */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 5 );
            }
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );

            /* Number_Remaining_BSIC */
            rmcp_csn1_field_read_params_ptr->length = 7;
            no_remaining_bsic = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

            /* Frequency_Scrolling and BSIC */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, (7 * no_remaining_bsic) );
        }

        /* GPRS Report Priority Description - Complete structure is Ignored */
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            tOCT_UINT8 no_of_cells;

            /* Number_Cells */
            rmcp_csn1_field_read_params_ptr->length = 7;
            no_of_cells = rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

            /* REP_PRIORITY */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, no_of_cells );
        }

        /* GPRS Measurement Parameters Description - Complete structure is Ignored */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            /* REPORT_TYPE */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );

            /* REPORTING_RATE */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );

            /* INVALID_BSIC_REPORTING */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );

            /* MULTIBAND_REPORTING */
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );
            }

            /* SERVING_BAND_REPORTING  */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );
            }

            /* SCALE_ORD */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );

            /* REPORTING_OFFSET and REPORTING_THRESHOLD parameters for 2G-bands */
            for(int i = 0; i < 5; i++)
            {
                rmcp_csn1_field_read_params_ptr->length = 1;
                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                {
                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                }
            }
        }

        /* NC Measurement Parameters */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            decoded_si2q_ptr->nc_meas_params = rmcp_nc_meas_pars_decode( rmcp_csn1_field_read_params_ptr );
        }

        /* extension of 2G parameters */

        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            rmcp_csn1_field_read_params_ptr->length = 8;
            temp = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) + 1;
            temp_bits_left = rmcp_csn1_field_read_params_ptr->bits_left;

            /* CCN Support Description */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                decoded_si2q_ptr->ccn_supported = rmcp_ccn_supported_decode( rmcp_csn1_field_read_params_ptr );
            }

            if (( temp_bits_left - rmcp_csn1_field_read_params_ptr->bits_left) > temp )
            {
                longjmp( rmcp_csn1_field_read_params_ptr->err_buf, RMCP_CSN1_ERROR_SEMANTIC );
            }
            else
            {
                temp -= ( temp_bits_left - rmcp_csn1_field_read_params_ptr->bits_left );
            }

            /* skip spare bits */
            rmcp_csn1_field_read_params_ptr->length = 1;
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, temp );
        } /* end of extension of 2G parameters */


        /* 3G Neighbour Cell Description */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            decoded_si2q_ptr->umts_ncell_descr = malloc(sizeof(SI_3G_NCELL_DESCR_STR));
    		assert(decoded_si2q_ptr->umts_ncell_descr != NULL);
            decoded_si2q_ptr->umts_ncell_descr->utran_fdd_descr = NULL;

            /* Index_Start_3G */
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_csn1_field_read_params_ptr->length = 7;
                decoded_si2q_ptr->umts_ncell_descr->index_start_3g = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            }
            else
            {
                decoded_si2q_ptr->umts_ncell_descr->index_start_3g = 0;
            }

            /* Absolute_Index_Start_EMR */
            rmcp_csn1_field_read_params_ptr->length = 1;
            decoded_si2q_ptr->umts_ncell_descr->absolute_index_start_emr_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            if (decoded_si2q_ptr->umts_ncell_descr->absolute_index_start_emr_present)
            {
                rmcp_csn1_field_read_params_ptr->length = 7;
                decoded_si2q_ptr->umts_ncell_descr->absolute_index_start_emr = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            }

            /* UTRAN FDD Description */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                     decoded_si2q_ptr->umts_ncell_descr->utran_fdd_descr = rmcp_utran_fdd_descr_decode( rmcp_csn1_field_read_params_ptr);
            }

            /* skip UTRAN TDD Description  */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                decoded_si2q_ptr->umts_ncell_descr->no_of_tdd_cells = rmcp_utran_tdd_descr_skip( rmcp_csn1_field_read_params_ptr );
            }
            else
            {
                decoded_si2q_ptr->umts_ncell_descr->no_of_tdd_cells = 0;
            }

            decoded_si2q_ptr->umts_ncell_descr->no_of_cdma2000_cells = 0;
        }

        /* 3G Measurement Parameters Description */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            decoded_si2q_ptr->gsm_3g_params = malloc(sizeof(RR_SI2QUATER_GSM_3G_PARS_STR));
    		assert(decoded_si2q_ptr->gsm_3g_params != NULL);

            /* Qsearch_I and Qsearch_C_Initial */
            rmcp_csn1_field_read_params_ptr->length = 4;
            decoded_si2q_ptr->gsm_3g_params->qsearch_i = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            rmcp_csn1_field_read_params_ptr->length = 1;
            decoded_si2q_ptr->gsm_3g_params->qsearch_c_initial = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

            /* FDD parameters */
            decoded_si2q_ptr->gsm_3g_params->fdd_params_present = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            if (decoded_si2q_ptr->gsm_3g_params->fdd_params_present)
            {
                /* FDD_Qoffset, FDD_REP_QUANT, FDD_MULTIRAT_REPORTING and FDD_Qmin */
                rmcp_csn1_field_read_params_ptr->length = 4;
                decoded_si2q_ptr->gsm_3g_params->fdd_params.fdd_qoffset = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                rmcp_csn1_field_read_params_ptr->length = 1;
                decoded_si2q_ptr->gsm_3g_params->fdd_params.fdd_rep_quant = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                rmcp_csn1_field_read_params_ptr->length = 2;
                decoded_si2q_ptr->gsm_3g_params->fdd_params.fdd_multirat_reporting = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                rmcp_csn1_field_read_params_ptr->length = 3;
                decoded_si2q_ptr->gsm_3g_params->fdd_params.fdd_qmin = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
            }

            /* Skip TDD parameters */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
            }
        } /* end of 3G Measurement Parameters Description */

        /* GPRS 3G Measurement Parameters Description - Complete structure is ignored */
        rmcp_csn1_field_read_params_ptr->length = 1;
        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
        {
            /* Qsearch_P and 3G_SEARCH_PRIO */
            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 5 );

            /* FDD_REP_QUANT and FDD_MULTIRAT_REPORTING */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
            }

            /* FDD_REPORTING_OFFSET and FDD_REPORTING_THRESHOLD */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
            }

            /* TDD_MULTIRAT_REPORTING */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );
            }

            /* TDD_REPORTING_OFFSET and TDD_REPORTING_THRESHOLD */
            rmcp_csn1_field_read_params_ptr->length = 1;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
            }

        }

        /* Rel 5 extension*/
        decoded_si2q_ptr->rel6_params_present = FALSE;
        decoded_si2q_ptr->rel8_params_present = FALSE;

        if ( rmcp_csn1_field_read_params_ptr->bits_left > 0 )
        {
            rmcp_csn1_field_read_params_ptr->length = 1;
            rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
            {
                /* 3G Additional Measurement Parameters Description - Ignore*/
                rmcp_csn1_field_read_params_ptr->padding = 0x00;
                if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) )
                {
                    /* FDD_Qmin_Offset */
                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );

                    /* FDD_RSCPmin */
                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 4 );
                }
                /* 3G Additional Measurement Parameters Description 2 */
                rmcp_csn1_field_read_params_ptr->length = 1;
                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                {
                    if ( rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) )
                    {
                        /* FDD_REPORTING_THRESHOLD_2 */
                        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                    }
                }
                /* Rel 6 extension */
                decoded_si2q_ptr->umts_ccn_active = FALSE;

                if ( rmcp_csn1_field_read_params_ptr->bits_left > 0 )
                {
                    rmcp_csn1_field_read_params_ptr->length = 1;
                    rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
                    if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                    {
                        decoded_si2q_ptr->rel6_params_present = TRUE;
                        rmcp_csn1_field_read_params_ptr->padding = 0x00;
                        decoded_si2q_ptr->umts_ccn_active = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    					/* Rel 7 extension parameters are ignored */
                        if ( rmcp_csn1_field_read_params_ptr->bits_left > 0 )
                        {
                            rmcp_csn1_field_read_params_ptr->length = 1;
                            rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                            {
                                rmcp_csn1_field_read_params_ptr->padding = 0x00;
                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                {
                                    /* 700 REPORTING OFFSET */
                                    rmcp_csn1_field_read_params_ptr->length = 3;
                                    (void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

                                    /* 700 REPORTING THRESHOLD */
                                    rmcp_csn1_field_read_params_ptr->length = 3;
                                    (void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                }

                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                {
                                    /* 810 REPORTING OFFSET */
                                    rmcp_csn1_field_read_params_ptr->length = 3;
                                    (void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

                                    /* 810 REPORTING THRESHOLD */
                                    rmcp_csn1_field_read_params_ptr->length = 3;
                                    (void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                }
                                /* Rel 8 extension  */
                                if ( rmcp_csn1_field_read_params_ptr->bits_left > 0 )
                                {
                                    rmcp_csn1_field_read_params_ptr->length = 1;
                                    rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
                                    if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                    {
                                        /* Priority and E-UTRAN Parameters Description */
                                        decoded_si2q_ptr->rel8_params_present = TRUE;
                                        rmcp_csn1_field_read_params_ptr->padding = 0x00;
                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                        {
                                            /* Serving Cell Priority Parameters Description */
                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                            {
                                                decoded_si2q_ptr->servcell_prio_params = malloc(sizeof(SI_SERVCELL_PRIO_PARAMS_STR));
                								assert(decoded_si2q_ptr->servcell_prio_params != NULL);
                                                decoded_si2q_ptr->servcell_prio_params->scell_prio_params_present = TRUE;
                
                                                /* GERAN PRIORITY */
                                                rmcp_csn1_field_read_params_ptr->length = 3;
                                                decoded_si2q_ptr->servcell_prio_params->geran_priority = rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr );
                                                /* THRESH Priority Search */
                                                rmcp_csn1_field_read_params_ptr->length = 4;
                                                decoded_si2q_ptr->servcell_prio_params->thresh_priority_search = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                                /* THRESH GSM low */
                                                rmcp_csn1_field_read_params_ptr->length = 4;
                                                decoded_si2q_ptr->servcell_prio_params->thresh_gsm_low = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                                /* H PRIO */
                                                rmcp_csn1_field_read_params_ptr->length = 2;
                                                decoded_si2q_ptr->servcell_prio_params->h_prio = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                                /* T_Reselection */
                                                rmcp_csn1_field_read_params_ptr->length = 2;
                                                decoded_si2q_ptr->servcell_prio_params->t_reselection = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                            }
                
                                            /* 3G Priority Parameters Description */
                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                            {
                                                decoded_si2q_ptr->utran_prio_params = malloc(sizeof(SI_UTRAN_PRIORITY_PARAMS_STR));
                								assert(decoded_si2q_ptr->utran_prio_params != NULL);
                
                                                decoded_si2q_ptr->utran_prio_params->rep_utran_params_store = NULL;
                
                                                decoded_si2q_ptr->utran_prio_params->utran_priority_params_present = TRUE;
                
                                                /* UTRAN Start */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                decoded_si2q_ptr->utran_start = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                
                                                /* UTRAN Stop */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                decoded_si2q_ptr->utran_stop = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                
                                                /* 3G Default Priority Parameters */
                                                decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_utran_priority = SI_INVALID_UTRAN_PRIORITY;
                                                decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_thresh_utran = SI_INVALID_THRESH_UTRAN;
                                                decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_utran_qrxlevmin = SI_INVALID_UTRAN_QRXLEVMIN;
                                                decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.def_3g_priority_params_present = FALSE;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.def_3g_priority_params_present = TRUE;
                
                                                    /* DEFAULT UTRAN PRIORITY */
                                                    rmcp_csn1_field_read_params_ptr->length = 3;
                                                    decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_utran_priority = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                
                                                    /* DEFAULT THRESH UTRAN */
                                                    rmcp_csn1_field_read_params_ptr->length = 5;
                                                    decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_thresh_utran = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                
                                                    /* DEFAULT UTRAN QRXLEVMIN */
                                                    rmcp_csn1_field_read_params_ptr->length = 5;
                                                    decoded_si2q_ptr->utran_prio_params->default_3g_prio_params_store.default_utran_qrxlevmin = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                
                                                }
                
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                /* Repeated UTRAN Priority Parameters */
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    decoded_si2q_ptr->utran_prio_params->rep_utran_params_store = rmcp_rep_utran_prio_para_decode(rmcp_csn1_field_read_params_ptr );
                                                }
                 
                                            }
                
                                            /* E-UTRAN Parameters Description */
                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                            {
                                                /* E-UTRAN_CCN_ACTIVE: Ignored */
                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );
                                        
                                                /* E-UTRAN_START */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                decoded_si2q_ptr->eutran_start = rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                        
                                                /* E-UTRAN_STOP */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                decoded_si2q_ptr->eutran_stop= rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
                                        
                                                /* E-UTRAN Measurement Parameters Description: Complete Stucture is Ignored */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    /* Qsearch_C_E-UTRAN_Initial */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 4 );
                                        
                                                    /* E-UTRAN_REP_QUANT */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );
                                        
                                                    /* E-UTRAN_MULTIRAT_REPORTING */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );
                                        
                                                    rmcp_csn1_field_read_params_ptr->length = 1;
                                                    if (0 == rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                    {
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_FDD_REPORTING_THRESHOLD */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_FDD_REPORTING_THRESHOLD_2 */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                            }
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_FDD_REPORTING_OFFSET */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                            }
                                                        }
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_TDD_REPORTING_THRESHOLD */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_TDD_REPORTING_THRESHOLD_2 */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                            }
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_TDD_REPORTING_OFFSET */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_FDD_MEASUREMENT_REPORT_OFFSET */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_FDD_REPORTING_THRESHOLD_2 */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                            }
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_FDD_REPORTING_OFFSET */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                            }
                                                        }
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_TDD_MEASUREMENT_REPORT_OFFSET */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_TDD_REPORTING_THRESHOLD_2  */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                            }
                                        
                                                            rmcp_csn1_field_read_params_ptr->length = 1;
                                                            if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                            {
                                                                /* E-UTRAN_TDD_REPORTING_OFFSET */
                                                                rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                            }
                                                        }
                                        
                                                        /* REPORTING_GRANULARITY  */
                                                        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );
                                                    }
                                                } /* E-UTRAN Measurement Parameters Description - END */
                                        
                                        
                                                /* GPRS E-UTRAN Measurement Parameters Description: Complete structure is ignored */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    /* Qsearch_P_E-UTRAN */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 4 );
                                        
                                                    /* E-UTRAN_REP_QUANT */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 1 );
                                        
                                                    /* E-UTRAN_MULTIRAT_REPORTING */
                                                    rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 2 );
                                        
                                                    rmcp_csn1_field_read_params_ptr->length = 1;
                                                    if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                    {
                                                        /* E-UTRAN_FDD_REPORTING_THRESHOLD */
                                                        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_FDD_REPORTING_THRESHOLD_2 */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                        }
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_FDD_REPORTING_OFFSET */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                        }
                                                    }
                                        
                                                    rmcp_csn1_field_read_params_ptr->length = 1;
                                                    if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                    {
                                                        /* E-UTRAN_TDD_REPORTING_THRESHOLD */
                                                        rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_TDD_REPORTING_THRESHOLD_2 */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 6 );
                                                        }
                                        
                                                        rmcp_csn1_field_read_params_ptr->length = 1;
                                                        if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                        {
                                                            /* E-UTRAN_TDD_REPORTING_OFFSET */
                                                            rmcp_bits_skip( rmcp_csn1_field_read_params_ptr, 3 );
                                                        }
                                                    }
                                                } /* GPRS E-UTRAN Measurement Parameters Description - END */
                                        
                                                /* Repeated E-UTRAN Neighbour Cells */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    decoded_si2q_ptr->rep_eutran_ncells_ptr = rmcp_rep_eutran_ncell_decode(rmcp_csn1_field_read_params_ptr );
                                                }
                                        
                                                /* Repeated E-UTRAN Not Allowed Cells */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    decoded_si2q_ptr->rep_eutran_na_cells_ptr = rmcp_rep_eutran_na_cells_decode( rmcp_csn1_field_read_params_ptr );
                                                }
                                        
                                        
                                                /* Repeated E-UTRAN PCID to TA mapping */
                                                rmcp_csn1_field_read_params_ptr->length = 1;
                                                if (rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ))
                                                {
                                                    decoded_si2q_ptr->rep_pcid_to_ta_map_ptr = rmcp_rep_pcid_ta_mapping_decode( rmcp_csn1_field_read_params_ptr );
                                                }
                                            }
                
                                        } /* end of Priority and E-UTRAN Parameters Description */
                                    }
                                } /* end of Rel 8 extension */

                            }
                        }
                    }
                }

            }
                rmcp_csn1_field_read_params_ptr->padding = 0x00;
        }

        free( rmcp_csn1_field_read_params_ptr );
        rmcp_csn1_field_read_params_ptr = NULL;

        return decoded_si2q_ptr;
    }
}

FDD_CELL_INFO_PARAMS_STR* rmcp_rep_fdd_struct_decode( const SI_REP_UTRAN_FDD_NCELLS_STR* rep_fdd_ncells)
{

    FDD_CELL_INFO_PARAMS_STR* ret_value;
    L1_ALLOCATION_UNION_STR* decoded_fdd_info;

    tOCT_UINT8 fdd_description[RMCP_RANGE_1024_VALUE_PART_LEN];
    tOCT_UINT8 j;
    tOCT_UINT8 read_bits_cnt;
    tOCT_UINT8 fdd_cell_info_field_length;
    
    ret_value = malloc(sizeof(FDD_CELL_INFO_PARAMS_STR));
    assert(ret_value != NULL);

    decoded_fdd_info = malloc(sizeof(L1_ALLOCATION_UNION_STR));    
    assert(decoded_fdd_info != NULL);

    assert(rep_fdd_ncells != NULL);

    (void) memset(fdd_description, 0x00, RMCP_RANGE_1024_VALUE_PART_LEN);
    ret_value->no_of_params = 0;

    /* FORMAT-ID */
    fdd_description[0] |= 0x80;

    /* F0 */
    if (rep_fdd_ncells->fdd_indic0)
    {
        fdd_description[0] |= 0x04;
    }

    /* W-values */

    j = 1;
    fdd_cell_info_field_length = rmcp_fdd_cell_info_length_calc(rep_fdd_ncells->no_of_fdd_cells);

    if (fdd_cell_info_field_length > 0)
    {
        fdd_description[0] |= rep_fdd_ncells->fdd_cell_information_field[0] >> 6;
        read_bits_cnt = 2;

        while (read_bits_cnt < fdd_cell_info_field_length)
        {
            assert(j < SI_FDD_CELL_INFO_FIELD_LENGTH && (j < RMCP_RANGE_1024_VALUE_PART_LEN));

            fdd_description[j] = (tOCT_UINT8) (rep_fdd_ncells->fdd_cell_information_field[j - 1] << 2) |
                (rep_fdd_ncells->fdd_cell_information_field[j] >> 6);
            j++;
            read_bits_cnt += 8;
        }
    }

    if (frequency_list_decode(fdd_description, j,
        decoded_fdd_info, FDD_CELL_INFO_PARAMS, TRUE, UMTS_NCELL_DESCR) == FREQLIST_DECODING_OK)
    {
        (void) memcpy(ret_value, &decoded_fdd_info->fdd_cell_info_params, sizeof(FDD_CELL_INFO_PARAMS_STR));
    }

    free(decoded_fdd_info);
    decoded_fdd_info = NULL;

    return ret_value;
}

/************************************************************************************************************
  * This function constructs (partial) 3G Neighbour Cell list from one
  * 3G Neighbour Cell description. 
  ************************************************************************************************************/

static SI_3G_NCELL_LIST_STR* sysinfo_3g_ncell_list_construct( const SI_3G_NCELL_DESCR_STR* ncell_descr, tOCT_UINT8 resel_freq_valid)
{

    SI_3G_NCELL_LIST_STR* ret_value = NULL;
    SI_REP_UTRAN_FDD_NCELLS_STR* rep_utran_fdd_ptr = NULL;
    FDD_CELL_INFO_PARAMS_STR* fdd_cell_info_params_ptr = NULL;
    tOCT_UINT8 i;

    assert(ncell_descr != NULL);
          
    /* Allocate maximum number of cells for the partial 3G Neighbour Cell list.
     * This is easier than first calculating the actual number of cells.
     */
    ret_value = malloc(sizeof(SI_3G_NCELL_LIST_STR));
    assert(ret_value != NULL);

    ret_value->cells = malloc(sizeof(FDD_CELL_STR) * SI_NCELL_LIST_SIZE);
    assert(ret_value->cells != NULL);

    ret_value->fdd_priority = NULL;
    ret_value->no_of_cells = 0;
    
    /* Beginning of the list (according to Index_Start_3G) is marked with
        * special value ("missing index") to enable combining of partial lists
        * at later stage.
        */
    for (i = 0; i < ncell_descr->index_start_3g; i++)
    {
        if (ret_value->no_of_cells < SI_NCELL_LIST_SIZE)
        {
            (ret_value->cells + ret_value->no_of_cells)->freq = SI_MISSING_3G_NCELL_LIST_INDEX;
            (ret_value->cells + ret_value->no_of_cells)->psc = SYSINFO_INVALID_SCRAMBLING_CODE;
            ++ret_value->no_of_cells;
        }
    }

    /* 3G Neighbour Cell list elements from UTRAN FDD Description are added
        * to the list.
        */
    if (NULL != ncell_descr->utran_fdd_descr)
    {
        /* handle each Repeated UTRAN FDD Neighbour Cells struct */
        rep_utran_fdd_ptr = ncell_descr->utran_fdd_descr->rep_utran_fdd_ncells;
        
        while (NULL != rep_utran_fdd_ptr)
        {
            /* if there are elements for 3G Neighbour Cell list */
            if (!(31 == rep_utran_fdd_ptr->no_of_fdd_cells && resel_freq_valid))
            {
                /* frequency for RSSI reporting */
                if (FALSE == rep_utran_fdd_ptr->fdd_indic0 && 0 == rep_utran_fdd_ptr->no_of_fdd_cells)
                {
                    if (ret_value->no_of_cells < SI_NCELL_LIST_SIZE)
                    {
                        (ret_value->cells + ret_value->no_of_cells)->freq = rep_utran_fdd_ptr->explicit_fdd_arfcn;
                        (ret_value->cells + ret_value->no_of_cells)->psc  = SYSINFO_INVALID_SCRAMBLING_CODE;
                        ++ret_value->no_of_cells;
                    }
                }
                /* no valid list element, but index shall be allocated, see 04.18 table 9.1.54.1 */
                else if (rep_utran_fdd_ptr->no_of_fdd_cells > 16)
                {
                    if (ret_value->no_of_cells < SI_NCELL_LIST_SIZE)
                    {
                        (ret_value->cells + ret_value->no_of_cells)->freq = SI_MISSING_3G_NCELL_LIST_INDEX;
                        (ret_value->cells + ret_value->no_of_cells)->psc  = SYSINFO_INVALID_SCRAMBLING_CODE;
                        ++ret_value->no_of_cells;
                    }
                }
                /* there are FDD_CELL_INFORMATION parameters */
                else
                {
                    fdd_cell_info_params_ptr = rmcp_rep_fdd_struct_decode(rep_utran_fdd_ptr);

                    for (i = 0; i < fdd_cell_info_params_ptr->no_of_params; i++)
                    {
                        if (ret_value->no_of_cells < SI_NCELL_LIST_SIZE)
                        {
                            (ret_value->cells + ret_value->no_of_cells)->freq = rep_utran_fdd_ptr->explicit_fdd_arfcn;
                            if (UNSUPPORTED_NEIGHBOUR_ARFCN == rep_utran_fdd_ptr->explicit_fdd_arfcn)
                            {
                                (ret_value->cells + ret_value->no_of_cells)->psc = SYSINFO_INVALID_SCRAMBLING_CODE;
                            }
                            else
                            {
                                (ret_value->cells + ret_value->no_of_cells)->psc = fdd_cell_info_params_ptr->params[i] & FDD_CELL_INFO_PARAM_PSC_MASK;
                            }

                            if (fdd_cell_info_params_ptr->params[i] & FDD_CELL_INFO_PARAM_DIV_MASK)
                            {
                                (ret_value->cells + ret_value->no_of_cells)->diversity_applied = TRUE;
                            }
                            else
                            {
                                (ret_value->cells + ret_value->no_of_cells)->diversity_applied = FALSE;
                            }

                            ++ret_value->no_of_cells;
                        }
                    }
                    
                    free(fdd_cell_info_params_ptr);
                    fdd_cell_info_params_ptr = NULL;
                }
            }

            rep_utran_fdd_ptr = rep_utran_fdd_ptr->next_ptr;
        }
    }


    /* TDD and/or CDMA2000 cells are presented by unsupported frequency
        * and invalid primary scrambling code.
        */
    for (i = 0; i < ncell_descr->no_of_tdd_cells + ncell_descr->no_of_cdma2000_cells; i++)
    {
        if (ret_value->no_of_cells < SI_NCELL_LIST_SIZE)
        {
            (ret_value->cells + ret_value->no_of_cells)->freq = UNSUPPORTED_NEIGHBOUR_ARFCN;
            (ret_value->cells + ret_value->no_of_cells)->psc  = SYSINFO_INVALID_SCRAMBLING_CODE;
            ++ret_value->no_of_cells;
        }
    }    

    return ret_value;
}

static void sysinfo_3g_ncell_list_enlarge(SI_3G_NCELL_LIST_STR* const ncell_list, tOCT_UINT8 no_of_cells)
{

    FDD_CELL_STR* temp_ptr = NULL;
    tOCT_UINT8 i;
    
    assert(ncell_list != NULL && no_of_cells <= SI_NCELL_LIST_SIZE);

    if (no_of_cells > ncell_list->no_of_cells)
    {
        temp_ptr = malloc(no_of_cells * sizeof(FDD_CELL_STR));
        assert(temp_ptr != NULL);
    
        /* The number of new allocated elements shall be initialized to default value to the temporary variable */
        for (i = ncell_list->no_of_cells; i < no_of_cells ; i++)
        {
            (temp_ptr + i)->freq = UNSUPPORTED_NEIGHBOUR_ARFCN;
            (temp_ptr + i)->psc = SYSINFO_INVALID_SCRAMBLING_CODE;
            (temp_ptr + i)->diversity_applied = FALSE;
        }

        if (ncell_list->cells != NULL && (0 != ncell_list->no_of_cells))
        {
            (void) memcpy(temp_ptr, ncell_list->cells,(ncell_list->no_of_cells * sizeof(FDD_CELL_STR)));
            free(ncell_list->cells);
        }
        ncell_list->cells = temp_ptr;
        ncell_list->no_of_cells = no_of_cells;
        temp_ptr = NULL;
    }
}


/************************************************************************************************************
  * This function adds cells/frequencies from a (partial) 3G Neighbour Cell list
  * to a (non-partial) 3G Neighbour Cell list.
  ************************************************************************************************************/
static void sysinfo_3g_ncell_list_append(SI_3G_NCELL_LIST_STR* const ncell_list, const SI_3G_NCELL_LIST_STR* partial_ncell_list)
{

    tOCT_UINT8 i;
    tOCT_UINT8 partial_length;
    
    assert(ncell_list != NULL && partial_ncell_list != NULL && partial_ncell_list->no_of_cells <= SI_NCELL_LIST_SIZE);
    
    
    /* If 'ncell_list' does not have enough space for cells/frequencies to
        * be added, 'ncell_list' is enlargened.
        */
    partial_length = partial_ncell_list->no_of_cells;
    
    if (partial_ncell_list->cells != NULL)
    {
        while (partial_length > 0 && SI_MISSING_3G_NCELL_LIST_INDEX == (partial_ncell_list->cells + partial_length - 1)->freq)
        {
            partial_length--;
        }
    }

    if (partial_length > ncell_list->no_of_cells)
    {    
        sysinfo_3g_ncell_list_enlarge(ncell_list, partial_length);
    }
    
    /* The non-missing elements of the 'partial_ncell_list' are written to the 'ncell_list'. */
    for (i = 0; i < partial_length; i++)
    {        
        if ((partial_ncell_list->cells + i)->freq != SI_MISSING_3G_NCELL_LIST_INDEX)
        {
            (void) memcpy((ncell_list->cells + i), (partial_ncell_list->cells + i), sizeof(FDD_CELL_STR));    
        }
    }
}

static void sysinfo_3g_ncell_list_dupl_chk(SI_3G_NCELL_LIST_STR* const ncell_list)
{
    tOCT_UINT8 i;
    tOCT_UINT8 j;
    
    assert(ncell_list != NULL);
    
    if (ncell_list->cells != NULL)
    {
        for (i = 0; i < ncell_list->no_of_cells - 1; i++)
        {
            if ((ncell_list->cells + i)->freq != UNSUPPORTED_NEIGHBOUR_ARFCN)
            {
                for (j = i + 1; j < ncell_list->no_of_cells; j++)
                {
                    if (/* same frequency for RSSI reporting*/
                        (((ncell_list->cells + j)->psc == SYSINFO_INVALID_SCRAMBLING_CODE) &&
                        ((ncell_list->cells + j)->freq == (ncell_list->cells + i)->freq) &&
                        ((ncell_list->cells + j)->psc ==  (ncell_list->cells + i)->psc)) ||

                        /* same cell */
                        (((ncell_list->cells + j)->psc != SYSINFO_INVALID_SCRAMBLING_CODE) &&
                        ((ncell_list->cells + j)->freq == (ncell_list->cells + i)->freq) &&
                        ((ncell_list->cells + j)->psc ==  (ncell_list->cells + i)->psc) &&
                        ((ncell_list->cells + j)->diversity_applied == (ncell_list->cells + i)->diversity_applied)))
                    {
                        (ncell_list->cells + i)->freq = UNSUPPORTED_NEIGHBOUR_ARFCN;
                        (ncell_list->cells + i)->psc =  SYSINFO_INVALID_SCRAMBLING_CODE;
                        break;
                    }
                }
            }
        }
    }
}

/************************************************************************************************************
  * This function checks and removes element(s) with UNSUPPORTED_NEIGHBOUR_ARFCN
  * frequency from the end of the 3G neighbour cell list given as input.
  ************************************************************************************************************/
static void sysinfo_3g_ncell_list_end_chk(SI_3G_NCELL_LIST_STR* const ncell_list)
{

    tOCT_UINT8 valid_list_length;
    
    assert(ncell_list != NULL);
    
    /* It is checked whether there are unsupported frequencies in the end of the list */

    valid_list_length = ncell_list->no_of_cells;
    
    if ((ncell_list->cells != NULL) && (valid_list_length != 0))
    {
        while ((valid_list_length > 0) && ((ncell_list->cells + valid_list_length - 1)->freq == UNSUPPORTED_NEIGHBOUR_ARFCN))
        {
            valid_list_length--;
        }      
        
        /* List size shall be updated if unsupported frequencies were found */
        if (valid_list_length < ncell_list->no_of_cells)
        {
            ncell_list->no_of_cells = valid_list_length;
        
            if (0 == ncell_list->no_of_cells)
            {        
                free(ncell_list->cells); 
                ncell_list->cells = NULL;
            }
        }
    }                      
}


void sysinfo_3g_ncell_list_dealloc(SI_3G_NCELL_LIST_STR* const ptr)
{
    if (NULL != ptr)
    {
        if (NULL != ptr->cells)
        {
            free(ptr->cells);
            ptr->cells = NULL;
            ptr->no_of_cells = 0;        
        }

        if (NULL != ptr->fdd_priority)
        {
            free(ptr->fdd_priority);
            ptr->fdd_priority = NULL;
        }
    }
}

/************************************************************************************************************/
void sysinfo_3g_ncell_list_update(SI_3G_NCELL_DESCRS_WITH_ID_STR* umts_ncell_descrs)
{   
    SI_3G_NCELL_LIST_STR* new_list = NULL;
    SI_3G_NCELL_LIST_STR* temp = NULL;
    
    tOCT_UINT8 i;
    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    new_list = malloc(sizeof(SI_3G_NCELL_LIST_STR));
    assert(new_list != NULL);
    new_list->cells = NULL;
    
    new_list->fdd_priority = NULL;
    new_list->no_of_cells = 0;

    /* Each 3G Neighbour Cell Description is converted into a partial
        * 3G Neighbour list. Each partial list is then merged into the
        * final list.
        */
    for (i = 0; (i < umts_ncell_descrs->nbr_of_3g_ncell_descr && (umts_ncell_descrs->umts_ncells_descr[i] != NULL)); i++)
    {   
        temp = sysinfo_3g_ncell_list_construct(umts_ncell_descrs->umts_ncells_descr[i],umts_ncell_descrs->val_31_indicates_resel_list_freq);
        sysinfo_3g_ncell_list_append(new_list, temp);
        sysinfo_3g_ncell_list_dealloc(temp);
        free(temp);
        temp = NULL;
    }

    sysinfo_3g_ncell_list_dupl_chk(new_list);
    sysinfo_3g_ncell_list_end_chk(new_list); 

    if(new_list != NULL)
    {
        ind->si2qInfo.umtsNeighbors.noNeighUmtsCells = new_list->no_of_cells;
        for(i = 0; i < new_list->no_of_cells; i++)
        {
            if((new_list->cells + i) != NULL)
            {
                ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn               = (new_list->cells + i)->freq;
                ind->si2qInfo.umtsNeighbors.neighFddCell[i].psc                  = (new_list->cells + i)->psc;                
                ind->si2qInfo.umtsNeighbors.neighFddCell[i].diversityApplied     = (new_list->cells + i)->diversity_applied;
            }
        }
        sysinfo_3g_ncell_list_dealloc(new_list);
        free(new_list);
        new_list = NULL;
    }
}

#if 0
static void sysinfo_3g_ncell_store_clear( SI_3G_NCELL_DESCRS_WITH_ID_STR* umts_ncell_descrs )
{   
    tOCT_UINT8 i;

    if (umts_ncell_descrs->umts_ncells_descr != NULL)
    {
        for (i = 0; i < umts_ncell_descrs->nbr_of_3g_ncell_descr; i++)
        {
            rmcp_3g_ncell_descr_dealloc(umts_ncell_descrs->umts_ncells_descr[i]);
            if(umts_ncell_descrs->umts_ncells_descr[i] != NULL)
            {
                free(umts_ncell_descrs->umts_ncells_descr[i]);
                umts_ncell_descrs->umts_ncells_descr[i] = NULL;
            }
        }
        free(umts_ncell_descrs->umts_ncells_descr);
        umts_ncell_descrs->umts_ncells_descr = NULL;
    }
    umts_ncell_descrs->nbr_of_3g_ncell_descr = 0;
}
#endif

void sysinfo_3g_ncell_descrs_store( const SI_3G_NCELL_DESCRS_WITH_ID_STR *umts_ncells)
{
    SI_REP_UTRAN_FDD_NCELLS_STR    *from_utran_ptr = NULL;
    SI_REP_UTRAN_FDD_NCELLS_STR    **to_utran_ptr = NULL;
    SI_3G_NCELL_DESCRS_WITH_ID_STR params_store_str;

    tOCT_UINT8 nbr_of_3g_ncell_descr = 0;
    tOCT_UINT8 j = 0;
    tOCT_UINT8 i;

    assert(NULL != umts_ncells);

    params_store_str.umts_ncells_descr = NULL;
    params_store_str.nbr_of_3g_ncell_descr = 0;
    params_store_str.val_31_indicates_resel_list_freq = umts_ncells->val_31_indicates_resel_list_freq;
    params_store_str.umts_id = umts_ncells->umts_id;    

    for (i = 0; i < umts_ncells->nbr_of_3g_ncell_descr; i++)
    {
        if (umts_ncells->umts_ncells_descr[i] != NULL)
        {
            nbr_of_3g_ncell_descr++;
        }
    }

    if (nbr_of_3g_ncell_descr > 0)
    {
        params_store_str.nbr_of_3g_ncell_descr = nbr_of_3g_ncell_descr;

        params_store_str.umts_ncells_descr = malloc(sizeof(SI_3G_NCELL_DESCR_STR*) * nbr_of_3g_ncell_descr);
        assert(params_store_str.umts_ncells_descr != NULL);

        for (i = 0; i < umts_ncells->nbr_of_3g_ncell_descr; i++)
        {
            if (umts_ncells->umts_ncells_descr[i] != NULL)
            {
                params_store_str.umts_ncells_descr[j] = umts_ncells->umts_ncells_descr[i];

                if (umts_ncells->umts_ncells_descr[i]->utran_fdd_descr != NULL)
                {
                    params_store_str.umts_ncells_descr[j]->utran_fdd_descr = umts_ncells->umts_ncells_descr[i]->utran_fdd_descr;

                    from_utran_ptr = umts_ncells->umts_ncells_descr[i]->utran_fdd_descr->rep_utran_fdd_ncells;
                    to_utran_ptr = &params_store_str.umts_ncells_descr[j]->utran_fdd_descr->rep_utran_fdd_ncells;

                    while(from_utran_ptr != NULL)
                    {
                        *to_utran_ptr = from_utran_ptr;
                        from_utran_ptr = from_utran_ptr->next_ptr;
                        to_utran_ptr = &((*to_utran_ptr)->next_ptr);
                    }
                }
                j++;
            }
        }
    }

    sysinfo_3g_ncell_list_update(&params_store_str);

    if(params_store_str.umts_ncells_descr != NULL)
    {
        free(params_store_str.umts_ncells_descr);
        params_store_str.umts_ncells_descr = NULL;
    }
}

void sysinfo_3g_ncell_list_prio_upd(SI_3G_DEFAULT_PRIO_PARAMS_STR* default_3g_prio_params, tOCT_UINT16 utran_freq_list[], FDD_PRIORITY_STR utran_priority_list[] )
{
    tOCT_UINT8 i=0;
    tOCT_UINT8 j=0;
    tOCT_UINT8 utran_frequency_exists = FALSE;

    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    /* Exit the function if 3G neighbour cell list is empty or UTRAN priority information is not available */
    if (FALSE == ind->si2qInfo.umtsNeighbors.priorityParamsPresent || ind->si2qInfo.umtsNeighbors.noNeighUmtsCells == 0)
    {
        return;
    }
    
    /* Copy the UTRAN priority information to 3G neighbour cell list if the  frequency matches */
    for(j = 0; j < ind->si2qInfo.umtsNeighbors.noNeighUmtsCells; j++)
    {
		/* Fill the default/invalid values for 3G neighbour cell. This shall be
		 * overwritten by actual priority values if available.
		 */
        ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranPriority = default_3g_prio_params->default_utran_priority;
		
        if( ((ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb = default_3g_prio_params->default_thresh_utran) != 0) &&
            (SI_INVALID_THRESH_UTRAN != ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb) )
        {
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb *= 2;
        }

        ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranLowDb = ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb;
		
        if((ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranQrxlevminDbm = (tOCT_INT8) default_3g_prio_params->default_utran_qrxlevmin) != SI_INVALID_UTRAN_QRXLEVMIN )
        {
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranQrxlevminDbm = -119 + (tOCT_INT8) ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranQrxlevminDbm * 2;
        }

		for(i = 0; i < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
        {
            if(ind->si2qInfo.umtsNeighbors.neighFddCell[j].uarfcn == utran_freq_list[i])
            {
                ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranPriority     = utran_priority_list[i].utran_priority;
                ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb = utran_priority_list[i].thresh_utran_high_db;
                ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranLowDb  = utran_priority_list[i].thresh_utran_low_db;
                ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranQrxlevminDbm = utran_priority_list[i].utran_qrxlevmin_dbm;

                utran_frequency_exists = TRUE;
            }
        }

        /* If the UTRAN frequency does not exist in the 3G frequency list then
               * invalid values shall be assigned for UTRAN priority information.
               */
        if ( FALSE == utran_frequency_exists ) 
        {
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranPriority     = SI_INVALID_UTRAN_PRIORITY;
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranHighDb = SI_INVALID_THRESH_UTRAN;
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].threshUtranLowDb  = SI_INVALID_THRESH_UTRAN;
            ind->si2qInfo.umtsNeighbors.neighFddCell[j].utranQrxlevminDbm = SI_INVALID_UTRAN_QRXLEVMIN;
        }
        utran_frequency_exists = FALSE;
    }
}

tOCT_UINT8 sysinfo_3g_freq_exists( tOCT_UINT16 fdd_arfcn, tOCT_UINT16 utran_freq_list[])
{

    tOCT_UINT8 fdd_freq_found = FALSE;
    tOCT_UINT8 i;

    for (i= 0; i < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
    {
        if (fdd_arfcn == utran_freq_list[i])
        {
            fdd_freq_found = TRUE;
            break;
        }
    }
    return fdd_freq_found;
}

void sysinfo_copy_3g_prio_to_prio_arr(FDD_PRIORITY_STR  utran_prio[], SI_REP_UTRAN_PRIORITY_PARAMS_STR* utran_prio_para_ptr)
{
    SI_REP_UTRAN_FREQ_INDEX_STR* rep_utran_freq_index_ptr = NULL;
    tOCT_UINT8 i;
	
    assert(NULL != utran_prio_para_ptr);
	
    rep_utran_freq_index_ptr = utran_prio_para_ptr->rep_utran_freq_index;
	
    /* Copy UTRAN priority information from UTRAN priority structure which
        * contains repeated UTRAN Frequency Index.
        */
    while (NULL != rep_utran_freq_index_ptr)
    {
        for (i = 0; i < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
	    {
            if (rep_utran_freq_index_ptr->utran_freq_index == i)
			{
                utran_prio[i].utran_priority = utran_prio_para_ptr->utran_priority;
                
                if (((utran_prio[i].thresh_utran_high_db = utran_prio_para_ptr->thresh_utran_high) != 0) && \
                     (utran_prio[i].thresh_utran_high_db != SI_INVALID_THRESH_UTRAN))
                {
                    utran_prio[i].thresh_utran_high_db *= 2;
                }
    
                if (((utran_prio[i].thresh_utran_low_db = utran_prio_para_ptr->thresh_utran_low) != 0) && \
                     (utran_prio[i].thresh_utran_low_db != SI_INVALID_THRESH_UTRAN))
                {
                    utran_prio[i].thresh_utran_low_db *= 2;
                }
    
                if ((utran_prio[i].utran_qrxlevmin_dbm = (tOCT_INT8) utran_prio_para_ptr->utran_qrxlevmin) != SI_INVALID_UTRAN_QRXLEVMIN)
                {
                    utran_prio[i].utran_qrxlevmin_dbm = -119 + 2 * utran_prio[i].utran_qrxlevmin_dbm;
                }
            }
        }
             rep_utran_freq_index_ptr = rep_utran_freq_index_ptr->next_ptr;
    }
}


void sysinfo_3g_priority_list_update( SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_params, SI_3G_DEFAULT_PRIO_PARAMS_STR* default_3g_prio_params, FDD_PRIORITY_STR utran_priority_list[] )
{
    tOCT_UINT8 i;

    /* Fill the default/invalid values for 3G priority list */
    for (i = 0; i < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
    {
        utran_priority_list[i].utran_priority = default_3g_prio_params->default_utran_priority;
		
        if( ((utran_priority_list[i].thresh_utran_high_db = default_3g_prio_params->default_thresh_utran) != 0) && \
            (SI_INVALID_THRESH_UTRAN != utran_priority_list[i].thresh_utran_high_db ) )
        {
            utran_priority_list[i].thresh_utran_high_db *= 2;
        }

        utran_priority_list[i].thresh_utran_low_db = utran_priority_list[i].thresh_utran_high_db;
		
        if((utran_priority_list[i].utran_qrxlevmin_dbm = (tOCT_INT8) default_3g_prio_params->default_utran_qrxlevmin) != SI_INVALID_UTRAN_QRXLEVMIN )
        {
            utran_priority_list[i].utran_qrxlevmin_dbm= -119 + (tOCT_INT8) utran_priority_list[i].utran_qrxlevmin_dbm * 2;
        }
    }

    /* Copy UTRAN priority information for corresponding frequency from
        * repeated UTRAN priority store.
        */
    while (rep_utran_prio_params != NULL)
    {
        sysinfo_copy_3g_prio_to_prio_arr(utran_priority_list, rep_utran_prio_params);
        rep_utran_prio_params = rep_utran_prio_params->next_ptr;
    } /* end of while rep_utran_prio_para_ptr is not NULL */
}


void sysinfo_3g_freq_list_update(SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_params, SI_3G_DEFAULT_PRIO_PARAMS_STR* default_3g_prio_params, 
                                     tOCT_UINT16 utran_freq_list[], FDD_PRIORITY_STR utran_priority_list[] )
{
    tOCT_UINT8 i;
    tOCT_UINT8 no_of_freqs = 0;

    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    for(i = 0; i < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
    {
        utran_freq_list[i] = SI_INVALID_UTRAN_FREQ;
    }

    /* Update the 3G frequency list for neighbour cell frequencies */
    /* Extract FDD frequncy list from the FDD cells */
    for(i = 0; i < ind->si2qInfo.umtsNeighbors.noNeighUmtsCells && no_of_freqs < MAX_NR_OF_FDD_ARFCN_INDEX; i++)
    {
        /* Frequency Index is allocated to SI_MISSING_3G_NCELL_LIST_INDEX
                * and UNSUPPORTED_NEIGHBOUR_ARFCN. If the frequency correspodning
                * to SI_MISSING_3G_NCELL_LIST_INDEX or UNSUPPORTED_NEIGHBOUR_ARFCN
                * is repeated then it is not handled in the current 3G priority
                * list implementation.
                */
        if ( ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn == SI_MISSING_3G_NCELL_LIST_INDEX || \
             ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn == UNSUPPORTED_NEIGHBOUR_ARFCN )
        {
            utran_freq_list[no_of_freqs++] = ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn;
        }
        /* If a frequency for RSSI reporting is included in the 3G Neighbour
               * Cell list and for that frequency no cell is included in the list
               * then no index shall be assigned for that frequency.
               * see 44.18, chapter 3.4.1.2.1.7c.
               */
        else if (ind->si2qInfo.umtsNeighbors.neighFddCell[i].psc == SYSINFO_INVALID_SCRAMBLING_CODE)
        {
            continue;
        }
        /* Check if the frequency is already there in utran_freq_list. Consider
               * priority of the lowest FDD frequncy index to repeated frequencies. 
               */
        else if (!sysinfo_3g_freq_exists(ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn, utran_freq_list))
        {
            utran_freq_list[no_of_freqs++] = ind->si2qInfo.umtsNeighbors.neighFddCell[i].uarfcn;
        }
    }

	/* WARNING: Number of frequencies in 3G neighbour cell is greater than
	 * MAX_NR_OF_FDD_ARFCN_INDEX. UTRAN priorities can not be assigned to
	 * frequencies which has index > MAX_NR_OF_FDD_ARFCN_INDEX.
	 */
	if (no_of_freqs > MAX_NR_OF_FDD_ARFCN_INDEX)
    {
		logPrint(LOG_DEBUG, "No of freqs in 3G ncell list(%d) > MAX_NR_OF_FDD_ARFCN_INDEX", no_of_freqs);
	}

    /* Update 3G priority list */
    sysinfo_3g_priority_list_update( rep_utran_prio_params, default_3g_prio_params, utran_priority_list );

}

void sysinfo_3g_def_prio_para_clear(SI_3G_DEFAULT_PRIO_PARAMS_STR *def_3g_prio_params_ptr)
{   
    def_3g_prio_params_ptr->default_utran_priority = SI_INVALID_UTRAN_PRIORITY;
    def_3g_prio_params_ptr->default_thresh_utran = SI_INVALID_THRESH_UTRAN;
    def_3g_prio_params_ptr->default_utran_qrxlevmin = SI_INVALID_UTRAN_QRXLEVMIN;
    def_3g_prio_params_ptr->def_3g_priority_params_present = FALSE;
}

SI_3G_DEFAULT_PRIO_PARAMS_STR sysinfo_3g_def_prio_para_store(const SI_3G_DEFAULT_PRIO_PARAMS_STR *def_3g_prio_params_ptr)    
{
    SI_3G_DEFAULT_PRIO_PARAMS_STR def_3g_prio_params;

    sysinfo_3g_def_prio_para_clear(&def_3g_prio_params);

    if (NULL != def_3g_prio_params_ptr &&
        TRUE == def_3g_prio_params_ptr->def_3g_priority_params_present)
    {
        (void) memcpy( &def_3g_prio_params, def_3g_prio_params_ptr, sizeof(SI_3G_DEFAULT_PRIO_PARAMS_STR) );
    }

    return def_3g_prio_params;
}

void sysinfo_rep_utra_prio_par_clear(SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_params_store_ptr )
{
    if (NULL != rep_utran_prio_params_store_ptr)
    {
        rmcp_rep_utran_prio_dealloc( rep_utran_prio_params_store_ptr );
        rep_utran_prio_params_store_ptr = NULL;
    }
}

void sysinfo_rep_utra_prio_par_store(SI_REP_UTRAN_PRIORITY_PARAMS_STR** rep_utran_params_store, SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_params, tOCT_UINT8 no_of_rep_utran_prio_para)
{    
    SI_REP_UTRAN_PRIORITY_PARAMS_STR  *from_utran_prio_ptr = NULL;
    SI_REP_UTRAN_PRIORITY_PARAMS_STR  **to_utran_prio_ptr = NULL;
    SI_REP_UTRAN_FREQ_INDEX_STR** from_utran_freq_index_ptr;
    SI_REP_UTRAN_FREQ_INDEX_STR** to_utran_freq_index_ptr;
    tOCT_UINT8 i = 0;

    sysinfo_rep_utra_prio_par_clear(rep_utran_prio_params);

    /* Stores the repeated UTRAN priority parameters received from different SI2quater instances */
    if (NULL != rep_utran_params_store && no_of_rep_utran_prio_para > 0)
    {
        to_utran_prio_ptr = &rep_utran_prio_params;

        for(i=0; i<no_of_rep_utran_prio_para; i++)
        {
            /* Pointer to the repeated UTRAN priority structure of SI2quater instance i */
            from_utran_prio_ptr = rep_utran_params_store[i];

            /* Copy the repeated UTRAN priority structure */
            while(from_utran_prio_ptr != NULL)
            {
                *to_utran_prio_ptr = from_utran_prio_ptr;

                assert(NULL != from_utran_prio_ptr->rep_utran_freq_index);

                from_utran_freq_index_ptr = &(from_utran_prio_ptr->rep_utran_freq_index);
                to_utran_freq_index_ptr = &((*to_utran_prio_ptr)->rep_utran_freq_index);

                /* Copy the repeated UTRAN frequency index */
                while(*from_utran_freq_index_ptr != NULL)
                {
                    *to_utran_freq_index_ptr = *from_utran_freq_index_ptr;

                    from_utran_freq_index_ptr =	&(*from_utran_freq_index_ptr)->next_ptr;
                    to_utran_freq_index_ptr = &(*to_utran_freq_index_ptr)->next_ptr;
                }

                from_utran_prio_ptr = from_utran_prio_ptr->next_ptr;
                to_utran_prio_ptr = &((*to_utran_prio_ptr)->next_ptr);
            }
        }
    }
}

void sysinfo_utran_params_store( SI_UTRAN_PRIORITY_PARAMS_STR** utran_priority_params, tOCT_UINT8 no_of_utran_prio_params)
{   
    SI_REP_UTRAN_PRIORITY_PARAMS_STR** rep_utran_prio_params_ptr = NULL;
    SI_REP_UTRAN_PRIORITY_PARAMS_STR* rep_utran_prio_params = NULL;
    SI_3G_DEFAULT_PRIO_PARAMS_STR* default_3g_prio_params_ptr = NULL;
    SI_3G_DEFAULT_PRIO_PARAMS_STR  default_3g_prio_params;
    tOCT_UINT8 i;
    tOCT_UINT8 utran_priority_params_present = FALSE;

    tOCT_UINT16 utran_freq_list[MAX_NR_OF_FDD_ARFCN_INDEX];
    FDD_PRIORITY_STR utran_priority_list[MAX_NR_OF_FDD_ARFCN_INDEX];

    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    if (NULL != utran_priority_params)
    {
        rep_utran_prio_params_ptr = malloc(no_of_utran_prio_params * sizeof(SI_REP_UTRAN_PRIORITY_PARAMS_STR*) );
        assert(rep_utran_prio_params_ptr != NULL);

        for(i=0; i < no_of_utran_prio_params; i++)
        {
            rep_utran_prio_params_ptr[i] = NULL;
            if (NULL != utran_priority_params[i] && (utran_priority_params[i])->utran_priority_params_present)
            {
                utran_priority_params_present = TRUE;
                if ((utran_priority_params[i])->default_3g_prio_params_store.def_3g_priority_params_present)
                {
                    default_3g_prio_params_ptr = &(utran_priority_params[i])->default_3g_prio_params_store;
                }
                rep_utran_prio_params_ptr[i] = (utran_priority_params[i])->rep_utran_params_store;
            }
        }
    }

    /* Store 3G default priority prameters */
    default_3g_prio_params = sysinfo_3g_def_prio_para_store(default_3g_prio_params_ptr);

    /* Store repeated UTRAN priority prameters */
    sysinfo_rep_utra_prio_par_store(rep_utran_prio_params_ptr, rep_utran_prio_params, no_of_utran_prio_params);

    /* Store UTRAN priority prameters present information */
    ind->si2qInfo.umtsNeighbors.priorityParamsPresent = utran_priority_params_present;  

    /* Create 3G frequency list */
    sysinfo_3g_freq_list_update(rep_utran_prio_params, &default_3g_prio_params, utran_freq_list, utran_priority_list);

    /* Update 3G neighbour cell list priority */
    sysinfo_3g_ncell_list_prio_upd(&default_3g_prio_params, utran_freq_list, utran_priority_list );

    if (NULL != rep_utran_prio_params_ptr)
    {
        free(rep_utran_prio_params_ptr);
        rep_utran_prio_params_ptr = NULL;
    }
}


void rr_si_rep_eutran_ncells_clear(SI_REP_EUTRAN_NCELL_STR** rep_eutran_ncell_store_ptr)
{
    if (NULL != *rep_eutran_ncell_store_ptr)
    {
        rmcp_rep_eutran_ncell_dealloc( *rep_eutran_ncell_store_ptr );
        *rep_eutran_ncell_store_ptr = NULL;
    }
}

void sysinfo_rep_eutran_ncell_store(SI_REP_EUTRAN_NCELL_STR **rep_eutran_ncell_params_store, SI_REP_EUTRAN_NCELL_STR** combined_rep_eutran_ncell_ptr, tOCT_UINT8 no_of_rep_eutran_ncell_para)
{
    SI_REP_EUTRAN_NCELL_STR  *from_eutran_ncell_ptr = NULL;
    SI_REP_EUTRAN_NCELL_STR  **to_eutran_ncell_ptr = NULL;
    SI_REP_EARFCN_MEAS_BW_STR** from_eutran_meas_bw_ptr;
    SI_REP_EARFCN_MEAS_BW_STR** to_eutran_meas_bw_ptr;
    tOCT_UINT8 i=0;

    //rr_si_rep_eutran_ncells_clear(combined_rep_eutran_ncell_ptr);

    /* Stores the repeated EUTRAN neighbour cell parameters received from different  SI2quater instances */
    if (NULL != rep_eutran_ncell_params_store && no_of_rep_eutran_ncell_para > 0)
    {
        to_eutran_ncell_ptr = combined_rep_eutran_ncell_ptr;

        for(i=0; i<no_of_rep_eutran_ncell_para; i++)
        {
            /* Pointer to the repeated EUTRAN neighbour cell structure of SI2quater instance i */
            from_eutran_ncell_ptr = rep_eutran_ncell_params_store[i];

            /* Copy the repeated EUTRAN neighbour cell structure */
            while(from_eutran_ncell_ptr != NULL)
            {
                *to_eutran_ncell_ptr = from_eutran_ncell_ptr;

                assert(NULL != from_eutran_ncell_ptr->rep_earfcn_meas_bandwidth_ptr);

                from_eutran_meas_bw_ptr = &(from_eutran_ncell_ptr->rep_earfcn_meas_bandwidth_ptr);
                to_eutran_meas_bw_ptr = &((*to_eutran_ncell_ptr)->rep_earfcn_meas_bandwidth_ptr);

                /* Copy the repeated measurement bandwidth */
                while(*from_eutran_meas_bw_ptr != NULL)
                {
                    *to_eutran_meas_bw_ptr = *from_eutran_meas_bw_ptr;

                    from_eutran_meas_bw_ptr = &(*from_eutran_meas_bw_ptr)->next_ptr;
                    to_eutran_meas_bw_ptr = &(*to_eutran_meas_bw_ptr)->next_ptr;
                }

                from_eutran_ncell_ptr = from_eutran_ncell_ptr->next_ptr;
                to_eutran_ncell_ptr = &((*to_eutran_ncell_ptr)->next_ptr);
            }
        }
    }
}

void rr_si_rep_eutran_na_cells_clear(SI_REP_EUTRAN_NA_CELLS_STR** rep_eutran_na_cells_store_ptr)
{    
    if (NULL != *rep_eutran_na_cells_store_ptr)
    {
        rmcp_rep_eutran_na_cells_dealloc( *rep_eutran_na_cells_store_ptr );
        *rep_eutran_na_cells_store_ptr = NULL;
    }
}

void sysinfo_rep_eutran_na_cells_store(SI_REP_EUTRAN_NA_CELLS_STR **rep_eutran_na_cells_store, SI_REP_EUTRAN_NCELL_STR **rep_eutran_ncell_params_store, SI_REP_EUTRAN_NA_CELLS_STR  **combined_rep_eutran_na_cells_ptr, tOCT_UINT8 no_of_rep_eutran_na_cells)                
{
    SI_REP_EUTRAN_NA_CELLS_STR  *from_eutran_na_cells_ptr = NULL;
    SI_REP_EUTRAN_NA_CELLS_STR  **to_eutran_na_cells_ptr = NULL;
    SI_REP_EUTRAN_FREQ_INDEX_STR** from_eutran_freq_indx_ptr;
    SI_REP_EUTRAN_FREQ_INDEX_STR** to_eutran_freq_indx_ptr;
    SI_REP_EUTRAN_NCELL_STR  *temp_eutran_ncell_ptr = NULL;
    SI_REP_EARFCN_MEAS_BW_STR* temp_eutran_meas_bw_ptr = NULL;
    tOCT_UINT8 freq_index_num=0;    
    tOCT_UINT8 i=0;
    tOCT_UINT8 j=0;

    //rr_si_rep_eutran_na_cells_clear(combined_rep_eutran_na_cells_ptr);

    /* Stores the repeated EUTRAN NA cells received from different SI2quater instances */

    if (NULL != rep_eutran_na_cells_store && no_of_rep_eutran_na_cells > 0)
    {
        to_eutran_na_cells_ptr = combined_rep_eutran_na_cells_ptr;

        for(i=0; i<no_of_rep_eutran_na_cells; i++)
        {
            /* Pointer to the repeated EUTRAN NA cells structure of SI2quater instance i */
            from_eutran_na_cells_ptr = rep_eutran_na_cells_store[i];

            /* Copy the repeated EUTRAN NA cells structure */
            while(from_eutran_na_cells_ptr != NULL)
            {
                *to_eutran_na_cells_ptr = from_eutran_na_cells_ptr;
                (*to_eutran_na_cells_ptr)->not_allowed_cells = from_eutran_na_cells_ptr->not_allowed_cells;

                from_eutran_freq_indx_ptr = &(from_eutran_na_cells_ptr->rep_eutran_freq_index_ptr);
                to_eutran_freq_indx_ptr = &((*to_eutran_na_cells_ptr)->rep_eutran_freq_index_ptr);

                /* If no E-UTRAN_FREQUENCY_INDEX is present, then EUTRAN Not Allowed
                              * Cells IE  is applicable to all E-UTRAN
                              * frequencies specified in the Repeated E-UTRAN Neighbour
                              * Cells struct(s)
                              */
                if(NULL == *from_eutran_freq_indx_ptr)
                {
                    for( j=0; j < no_of_rep_eutran_na_cells; j++ )
                    {
                        temp_eutran_ncell_ptr = rep_eutran_ncell_params_store[j];
                        while( NULL != temp_eutran_ncell_ptr )
                        {
                            temp_eutran_meas_bw_ptr = (temp_eutran_ncell_ptr)->rep_earfcn_meas_bandwidth_ptr;
                            while( NULL != temp_eutran_meas_bw_ptr )
                            {
                                *to_eutran_freq_indx_ptr = malloc(sizeof(SI_REP_EUTRAN_FREQ_INDEX_STR) );
                                assert(*to_eutran_freq_indx_ptr != NULL);
                                
                                (*to_eutran_freq_indx_ptr)->next_ptr = NULL;
                                (*to_eutran_freq_indx_ptr)->eutran_freq_index = freq_index_num;
                                freq_index_num++;				
                                to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                                temp_eutran_meas_bw_ptr = temp_eutran_meas_bw_ptr->next_ptr;
                            }
                            temp_eutran_ncell_ptr = temp_eutran_ncell_ptr->next_ptr;
                        }
                    }
                }   

                /* Copy the repeated EUTRAN frequency index */
                while(*from_eutran_freq_indx_ptr != NULL)
                {
                    *to_eutran_freq_indx_ptr = *from_eutran_freq_indx_ptr;

                    from_eutran_freq_indx_ptr =	&(*from_eutran_freq_indx_ptr)->next_ptr;
                    to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                }

                /* For automatically freeing the memory taken above for *to_eutran_freq_indx_ptr in case when *from_eutran_freq_indx_ptr == NULL */
                if(NULL == *from_eutran_freq_indx_ptr)
                {
                    while(*to_eutran_freq_indx_ptr != NULL)
                    {
                        *from_eutran_freq_indx_ptr = *to_eutran_freq_indx_ptr;
    
                        to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                        from_eutran_freq_indx_ptr = &(*from_eutran_freq_indx_ptr)->next_ptr;
                    }
                }

                from_eutran_na_cells_ptr = from_eutran_na_cells_ptr->next_ptr;
                to_eutran_na_cells_ptr = &((*to_eutran_na_cells_ptr)->next_ptr);
            }
        }
    }
}


void rr_si_rep_eutran_pcid_ta_clear(SI_REP_EUTRAN_PCID_TO_TA_STR** rep_eutran_pcid_to_ta_ptr)
{
    if (NULL != *rep_eutran_pcid_to_ta_ptr)
    {
        rmcp_rep_pcid_ta_mapping_dealloc( *rep_eutran_pcid_to_ta_ptr );
        *rep_eutran_pcid_to_ta_ptr = NULL;
    }
}
void sysinfo_rep_eutra_pcid_to_ta_store(SI_REP_EUTRAN_PCID_TO_TA_STR **rep_eutran_pcid_to_ta_store, SI_REP_EUTRAN_NCELL_STR **rep_eutran_ncell_params_store, SI_REP_EUTRAN_PCID_TO_TA_STR  **combined_rep_eutran_pcid_to_ta_ptr, tOCT_UINT8 no_of_rep_eutran_pcid_to_ta)     
{
    SI_REP_EUTRAN_PCID_TO_TA_STR  *from_eutran_pcid_to_ta_ptr = NULL;
    SI_REP_EUTRAN_PCID_TO_TA_STR  **to_eutran_pcid_to_ta_ptr = NULL;
    SI_REP_PCIDS_TA_STR           **from_eutran_pcid_group_ptr;
    SI_REP_PCIDS_TA_STR           **to_eutran_pcid_group_ptr;
    SI_REP_EUTRAN_FREQ_INDEX_STR  **from_eutran_freq_indx_ptr;
    SI_REP_EUTRAN_FREQ_INDEX_STR  **to_eutran_freq_indx_ptr;
    SI_REP_EUTRAN_NCELL_STR  *temp_eutran_ncell_ptr = NULL;
    SI_REP_EARFCN_MEAS_BW_STR* temp_eutran_meas_bw_ptr = NULL;
    tOCT_UINT8 freq_index_num=0;
    tOCT_UINT8 i=0; 
    tOCT_UINT8 j=0;

    //rr_si_rep_eutran_pcid_ta_clear(combined_rep_eutran_pcid_to_ta_ptr);

    /* Stores the repeated EUTRAN PCID to TA received from different SI2quater instances */

    if (NULL != rep_eutran_pcid_to_ta_store && no_of_rep_eutran_pcid_to_ta > 0)
    {
        to_eutran_pcid_to_ta_ptr = combined_rep_eutran_pcid_to_ta_ptr;

        for(i=0; i<no_of_rep_eutran_pcid_to_ta; i++)
        {
            /* Pointer to the repeated PCID to TA mapping structure of SI2quater instance i */
            from_eutran_pcid_to_ta_ptr = rep_eutran_pcid_to_ta_store[i];

            /* Copy the repeated EUTRAN PCID to TA mapping structure */
            while(from_eutran_pcid_to_ta_ptr != NULL)
            {
                *to_eutran_pcid_to_ta_ptr = from_eutran_pcid_to_ta_ptr;

                /* Copy the repeated PCID group */

                from_eutran_pcid_group_ptr = &(from_eutran_pcid_to_ta_ptr->rep_pcid_ta_group_ptr);
                to_eutran_pcid_group_ptr = &((*to_eutran_pcid_to_ta_ptr)->rep_pcid_ta_group_ptr);

                while(*from_eutran_pcid_group_ptr != NULL)
                {
                    *to_eutran_pcid_group_ptr = *from_eutran_pcid_group_ptr;
                    (*from_eutran_pcid_group_ptr)->pcid_group = (*to_eutran_pcid_group_ptr)->pcid_group;

                    from_eutran_pcid_group_ptr = &(*from_eutran_pcid_group_ptr)->next_ptr;
                    to_eutran_pcid_group_ptr = &(*to_eutran_pcid_group_ptr)->next_ptr;
                }

                /* Copy the repeated EUTRAN frequency index */

                from_eutran_freq_indx_ptr = &(from_eutran_pcid_to_ta_ptr->rep_eutran_freq_index_ptr);
                to_eutran_freq_indx_ptr = &((*to_eutran_pcid_to_ta_ptr)->rep_eutran_freq_index_ptr);
      
                /* If no E-UTRAN_FREQUENCY_INDEX is present, then EUTRAN 
                              *  Repeated PCID to TA Mapping is applicable to all E-UTRAN
                              * frequencies specified in the Repeated E-UTRAN Neighbour
                              * Cells struct(s)
                              */
                if(NULL == *from_eutran_freq_indx_ptr)
                {
                    for( j=0; j < no_of_rep_eutran_pcid_to_ta; j++ )
                    {
                        temp_eutran_ncell_ptr = rep_eutran_ncell_params_store[j];
                        while( NULL != temp_eutran_ncell_ptr )
                        {
                            temp_eutran_meas_bw_ptr = (temp_eutran_ncell_ptr)->rep_earfcn_meas_bandwidth_ptr;
                            while( NULL != temp_eutran_meas_bw_ptr )
                            {
                                *to_eutran_freq_indx_ptr = malloc(sizeof(SI_REP_EUTRAN_FREQ_INDEX_STR) );
                                assert(*to_eutran_freq_indx_ptr != NULL);
                                (*to_eutran_freq_indx_ptr)->next_ptr = NULL;
                                (*to_eutran_freq_indx_ptr)->eutran_freq_index = freq_index_num;
                                freq_index_num++;				
                                to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                                temp_eutran_meas_bw_ptr = temp_eutran_meas_bw_ptr->next_ptr;	 
                            }
                            temp_eutran_ncell_ptr = temp_eutran_ncell_ptr->next_ptr;
                        }
                    }
                } 

                while(*from_eutran_freq_indx_ptr != NULL)
                {
                    *to_eutran_freq_indx_ptr = *from_eutran_freq_indx_ptr;

                    from_eutran_freq_indx_ptr =	&(*from_eutran_freq_indx_ptr)->next_ptr;
                    to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                }

                /* For automatically freeing the memory taken above for *to_eutran_freq_indx_ptr in case when *from_eutran_freq_indx_ptr == NULL */
                if(NULL == *from_eutran_freq_indx_ptr)
                {
                    while(*to_eutran_freq_indx_ptr != NULL)
                    {
                        *from_eutran_freq_indx_ptr = *to_eutran_freq_indx_ptr;
    
                        to_eutran_freq_indx_ptr = &(*to_eutran_freq_indx_ptr)->next_ptr;
                        from_eutran_freq_indx_ptr = &(*from_eutran_freq_indx_ptr)->next_ptr;
                    }
                }

                from_eutran_pcid_to_ta_ptr = from_eutran_pcid_to_ta_ptr->next_ptr;
                to_eutran_pcid_to_ta_ptr = &((*to_eutran_pcid_to_ta_ptr)->next_ptr);
            }
        }
    }
#if 0
    if( NULL != to_eutran_pcid_to_ta_ptr && NULL != *to_eutran_pcid_to_ta_ptr )
    {
        rr_si_rep_eutra_pcid_to_ta_print( *to_eutran_pcid_to_ta_ptr );
    }
#endif
}

void sysinfo_create_eu_ncell_list ( SI_REP_EUTRAN_NCELL_STR* rep_eutran_ncells_ptr, SI_EUTRAN_NA_CELL_LIST_STR* eutran_na_cells_ptr )
{

    SI_REP_EARFCN_MEAS_BW_STR* temp_meas_bw_earfcn_ptr;
    EUTRAN_FREQ_STR* temp_eutran_freq;
    SI_REP_EUTRAN_NCELL_STR* temp_rep_eutran_ncells_ptr;
    tOCT_UINT8 temp_no_of_eutran_freq;


    static const tOCT_UINT8 eutran_meas_bw_nrb_values[] =
    {
        6,         /* Measurement Bandwidth bits value 000 */
        15,        /* Measurement Bandwidth bits value 001 */
        25,        /* Measurement Bandwidth bits value 010 */
        50,        /* Measurement Bandwidth bits value 011 */
        75,        /* Measurement Bandwidth bits value 100 */
        100,       /* Measurement Bandwidth bits value 101 */
        100,       /* Measurement Bandwidth bits value 110 */
        100        /* Measurement Bandwidth bits value 111 */
    };

    temp_rep_eutran_ncells_ptr = rep_eutran_ncells_ptr;
    temp_no_of_eutran_freq = 0;

    /* Calculate the number of EUTRAN frequencies in EUTRAN NEIGHBOUR CELL LIST */
    while( NULL != temp_rep_eutran_ncells_ptr )
    {
        temp_meas_bw_earfcn_ptr = temp_rep_eutran_ncells_ptr->rep_earfcn_meas_bandwidth_ptr;

        while( NULL != temp_meas_bw_earfcn_ptr )
        {                                      
            temp_no_of_eutran_freq = temp_no_of_eutran_freq + 1;

            temp_meas_bw_earfcn_ptr = temp_meas_bw_earfcn_ptr->next_ptr;
        }
        temp_rep_eutran_ncells_ptr = temp_rep_eutran_ncells_ptr->next_ptr;
    }
          
    /* Allocate memory of EUTRAN frqeuencies in EUTRAN NOT ALLOWED CELL LIST */
    eutran_na_cells_ptr->eutran_freq = malloc(temp_no_of_eutran_freq * sizeof (EUTRAN_FREQ_STR));
    assert(eutran_na_cells_ptr->eutran_freq != NULL);

    /* Add the EUTRAN frequencies and corresponding priorities to EUTRAN not allowed cell list */
    eutran_na_cells_ptr->no_of_eutran_freqs = 0;

    while( NULL != rep_eutran_ncells_ptr )
    {
        temp_meas_bw_earfcn_ptr = rep_eutran_ncells_ptr->rep_earfcn_meas_bandwidth_ptr;

        while( NULL != temp_meas_bw_earfcn_ptr )
        {
            if( eutran_na_cells_ptr->no_of_eutran_freqs < temp_no_of_eutran_freq )
            {
                temp_eutran_freq = &eutran_na_cells_ptr->eutran_freq[eutran_na_cells_ptr->no_of_eutran_freqs];

                temp_eutran_freq->eutran_arfcn = temp_meas_bw_earfcn_ptr->earfcn;
                (void) memset(temp_eutran_freq->eutran_pcid_bitmap, 0x00, E_MAX_PCID_BITMAP);
                temp_eutran_freq->eutran_meas_bw_nrb = eutran_meas_bw_nrb_values[temp_meas_bw_earfcn_ptr->meas_bandwidth];
                temp_eutran_freq->eutran_priority_info.eutran_priority = rep_eutran_ncells_ptr->eutran_priority;
                temp_eutran_freq->eutran_priority_info.thresh_eutran_high_db = 2 * rep_eutran_ncells_ptr->thresh_eutran_high;
                temp_eutran_freq->eutran_priority_info.thresh_eutran_low_db = 2 * rep_eutran_ncells_ptr->thresh_eutran_low;
                temp_eutran_freq->eutran_priority_info.eutran_qrxlevmin_dbm = -140 +( 2 * rep_eutran_ncells_ptr->eutran_qrxlevmin);
            }
                                                  
            eutran_na_cells_ptr->no_of_eutran_freqs = eutran_na_cells_ptr->no_of_eutran_freqs + 1;

            temp_meas_bw_earfcn_ptr = temp_meas_bw_earfcn_ptr->next_ptr;
        }
        rep_eutran_ncells_ptr = rep_eutran_ncells_ptr->next_ptr;
    }
}

void sysinfo_add_pcid_to_bitmap (tOCT_UINT8 pcid_bitmap[], tOCT_UINT16 pcid)
{
    if ( pcid <= E_MAX_ALLOWED_PCID_NUM)
    {
        pcid_bitmap[pcid >> 3] |= 1 << (pcid & 7);
    }
    else
    {
        logPrint(LOG_DEBUG, "OUT OF RANGE PCID VALUE IGNORED"); 
    }
}


void sysinfo_add_pcid_list_to_bm( SI_REP_PCID_STR* rep_pcid_list_ptr , tOCT_UINT8 pcid_bitmap[] )
{
    SI_REP_PCID_STR* temp_rep_pcid_list_ptr;

    temp_rep_pcid_list_ptr = rep_pcid_list_ptr;

    while ( NULL != temp_rep_pcid_list_ptr )
    {
        sysinfo_add_pcid_to_bitmap( pcid_bitmap, temp_rep_pcid_list_ptr->pcid );
        temp_rep_pcid_list_ptr = temp_rep_pcid_list_ptr->next_ptr;
    }
}

void sysinfo_add_pcid_range_to_bm( tOCT_UINT8 pcid_bitmap[], tOCT_UINT16 range_start, tOCT_UINT16 range_end )
{
    tOCT_UINT16 i;
    tOCT_UINT8 range_start_row;
    tOCT_UINT8 range_end_row;

    assert( range_start <= range_end );

    range_start_row = range_start / 8;
    range_end_row = range_end / 8;

    if(range_start_row == range_end_row)
    {
        for ( i = range_start; i <= range_end; i++ )
        {
            sysinfo_add_pcid_to_bitmap(pcid_bitmap, i);
        }
    }
    else
    {
        pcid_bitmap[range_start_row] = pcid_bitmap[range_start_row] | ((tOCT_UINT8) 0xFF) << ( range_start % 8 );

        pcid_bitmap[range_end_row] = pcid_bitmap[range_end_row] | ((tOCT_UINT8) 0xFF) >> ( 8 - ((range_end%8)+1) );

        if((range_end_row - range_start_row) >= 2)
        {
            (void) memset(&pcid_bitmap[range_start_row + 1], 0xFF, (range_end_row - range_start_row) - 1);
        }
    }
}

void sysinfo_add_pcid_bm_grp_to_bm( tOCT_UINT8 pcid_bitmap[], tOCT_UINT8 pcid_bitmap_group )
{
    tOCT_UINT8 i;

    for ( i = 1; i <= 6; i++ )
    {
        if(pcid_bitmap_group & 0x01)
        {
            sysinfo_add_pcid_range_to_bm(pcid_bitmap, (i-1)*84, (i*84)-1);
        }
        pcid_bitmap_group = pcid_bitmap_group >> 1;
    }
}

void sysinfo_add_pcid_pattern_to_bm( tOCT_UINT8 pcid_bitmap[], SI_REP_PCID_PATTERN_STR *rep_pcid_pattern_ptr )
{
    SI_REP_PCID_PATTERN_STR *temp_rep_pcid_pattern_ptr;
    tOCT_UINT16 pattern_test_word = 0x1FF;
    tOCT_UINT16 pcid_pattern_begin = 0;
    tOCT_UINT16 pcid_pattern_end = 0;
    tOCT_UINT8  pcid_pattern_ignore = FALSE;

    temp_rep_pcid_pattern_ptr = rep_pcid_pattern_ptr;

    while ( NULL != temp_rep_pcid_pattern_ptr )
    {
        pattern_test_word = pattern_test_word >> ( temp_rep_pcid_pattern_ptr->pcid_pattern_length + 1 );
            
        if(temp_rep_pcid_pattern_ptr->pcid_pattern!=0)
        {  
            pcid_pattern_begin = temp_rep_pcid_pattern_ptr->pcid_pattern << ( 9 - (temp_rep_pcid_pattern_ptr->pcid_pattern_length + 1));
                
            if ( pcid_pattern_begin > E_MAX_ALLOWED_PCID_NUM  )
            {
                pcid_pattern_ignore = TRUE;
                logPrint(LOG_DEBUG, "OUT OF RANGE PCID PATTERN IGNORED"); 
            }
        }
        else
        {
            pcid_pattern_begin = 0;
        }

        if ( TRUE != pcid_pattern_ignore ) 
        {
            pcid_pattern_end = ( temp_rep_pcid_pattern_ptr->pcid_pattern << ( 9 - (temp_rep_pcid_pattern_ptr->pcid_pattern_length + 1) )) | pattern_test_word;
        
            if( pcid_pattern_end > E_MAX_ALLOWED_PCID_NUM  )
            {
                pcid_pattern_end= E_MAX_ALLOWED_PCID_NUM ;
            }
            
            if( 0 == temp_rep_pcid_pattern_ptr->pcid_pattern_sense )
            {
                sysinfo_add_pcid_range_to_bm( pcid_bitmap, pcid_pattern_begin, pcid_pattern_end );
            }
            else
            {
                if (pcid_pattern_begin ==0)
                {
                    sysinfo_add_pcid_to_bitmap ( pcid_bitmap,0);
                }
                else
                {
                    sysinfo_add_pcid_range_to_bm( pcid_bitmap, 0, pcid_pattern_begin - 1 );
                }    

                if( pcid_pattern_end + 1 <= E_MAX_ALLOWED_PCID_NUM )
                {
                    sysinfo_add_pcid_range_to_bm( pcid_bitmap, pcid_pattern_end + 1, E_MAX_ALLOWED_PCID_NUM );
                }
            }
        }
        pcid_pattern_ignore = FALSE;
        temp_rep_pcid_pattern_ptr = temp_rep_pcid_pattern_ptr->next_ptr;
    }
}


void sysinfo_add_pcid_group_to_bm( const SI_PCID_GROUP_STR* pcid_group_ptr, tOCT_UINT8 pcid_bitmap[] )
{
    sysinfo_add_pcid_list_to_bm( pcid_group_ptr->rep_explicit_pcid_ptr, pcid_bitmap );
                
    if( TRUE == pcid_group_ptr->pcid_bitmap_group_present )
    {
        sysinfo_add_pcid_bm_grp_to_bm( pcid_bitmap, pcid_group_ptr->pcid_bitmap_group );
    }

    sysinfo_add_pcid_pattern_to_bm( pcid_bitmap, pcid_group_ptr->rep_pcid_pattern_ptr );
}

void sysinfo_copy_pcid_to_eu_ncells ( SI_REP_EUTRAN_NA_CELLS_STR* rep_eutran_na_cells_ptr, SI_EUTRAN_NA_CELL_LIST_STR* eutran_na_cells_ptr )
{
    tOCT_UINT8 temp_eutran_freq_index;
    SI_REP_EUTRAN_NA_CELLS_STR* temp_rep_eutran_na_cells_ptr;
    SI_REP_EUTRAN_FREQ_INDEX_STR *temp_eutran_freq_index_ptr;

    temp_rep_eutran_na_cells_ptr = rep_eutran_na_cells_ptr;

    while( NULL != temp_rep_eutran_na_cells_ptr )
    {
        temp_eutran_freq_index_ptr=temp_rep_eutran_na_cells_ptr->rep_eutran_freq_index_ptr;
        while( NULL != temp_eutran_freq_index_ptr )
        {
            temp_eutran_freq_index = temp_eutran_freq_index_ptr->eutran_freq_index;
   
            if(temp_eutran_freq_index < eutran_na_cells_ptr->no_of_eutran_freqs)
            {
                sysinfo_add_pcid_group_to_bm ( &temp_rep_eutran_na_cells_ptr->not_allowed_cells, eutran_na_cells_ptr->eutran_freq[temp_eutran_freq_index].eutran_pcid_bitmap);
            }

            temp_eutran_freq_index_ptr = temp_eutran_freq_index_ptr->next_ptr;
        }
        temp_rep_eutran_na_cells_ptr = temp_rep_eutran_na_cells_ptr->next_ptr;
    }
}

void sysinfo_eu_na_cell_list_clear( SI_EUTRAN_NA_CELL_LIST_STR* eutran_na_cells_ptr )
{
    if( NULL != eutran_na_cells_ptr )
    {
        if( NULL != eutran_na_cells_ptr->eutran_freq )
        {
            free(eutran_na_cells_ptr->eutran_freq);
            eutran_na_cells_ptr->eutran_freq = NULL;
        }        
        free(eutran_na_cells_ptr);
    }
    eutran_na_cells_ptr = NULL;
}


void sysinfo_eu_na_cell_list_update(SI_REP_EUTRAN_NCELL_STR **rep_eutran_ncell_ptr, SI_REP_EUTRAN_NA_CELLS_STR **rep_eutran_na_cells_ptr  )
{
    tOCT_UINT8 i;
    SI_EUTRAN_NA_CELL_LIST_STR* temp_eutran_na_cells_ptr = NULL;
    
    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    if( NULL == *rep_eutran_ncell_ptr && NULL == *rep_eutran_na_cells_ptr) 
    {        
        return;
    }

    if( NULL != *rep_eutran_ncell_ptr)
    {
        temp_eutran_na_cells_ptr = malloc(sizeof (SI_EUTRAN_NA_CELL_LIST_STR));
        assert(temp_eutran_na_cells_ptr != NULL);

        sysinfo_create_eu_ncell_list( *rep_eutran_ncell_ptr, temp_eutran_na_cells_ptr );
    }
    else
    {
        logPrint( LOG_DEBUG, "SYSINFO_EUTRAN_IDLE_NCELL_LIST_EMPTY");        
    }
	 
    if( NULL != *rep_eutran_na_cells_ptr && NULL != *rep_eutran_ncell_ptr )
    {
        sysinfo_copy_pcid_to_eu_ncells( *rep_eutran_na_cells_ptr, temp_eutran_na_cells_ptr );
    }
    else
    {
        logPrint( LOG_DEBUG, "SYSINFO_EUTRAN_IDLE_NCELL_OR_NACELL_LIST_EMPTY");
    }

    if( NULL != temp_eutran_na_cells_ptr )
    {
        ind->si2qInfo.lteNeighbors.noEutranFreqs = temp_eutran_na_cells_ptr->no_of_eutran_freqs;
        for(i = 0; i < ind->si2qInfo.lteNeighbors.noEutranFreqs; i++)
        {
            ind->si2qInfo.lteNeighbors.eutranFreq[i].earfcn = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_arfcn;
            memcpy(ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranPcidBitmap, (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_pcid_bitmap, E_MAX_PCID_BITMAP); 
            ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranMeasBwNrb = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_meas_bw_nrb;
            ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.eutranPriority = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_priority_info.eutran_priority;
            ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.threshEutranHighDb = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_priority_info.thresh_eutran_high_db;
            ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.threshEutranLowDb = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_priority_info.thresh_eutran_low_db;
            ind->si2qInfo.lteNeighbors.eutranFreq[i].eutranPriorityInfo.eutranQrxlevminDbm = (temp_eutran_na_cells_ptr->eutran_freq + i)->eutran_priority_info.eutran_qrxlevmin_dbm;
        }
        sysinfo_eu_na_cell_list_clear( temp_eutran_na_cells_ptr );  
        temp_eutran_na_cells_ptr = NULL;
    }
}

S_SYSINFO_LINKED_LIST_STR* rmcp_sysinfo_linked_list_append( S_SYSINFO_LINKED_LIST_STR *list_ptr, S_SYSINFO_LINKED_LIST_STR *new_node_ptr)
{
    S_SYSINFO_LINKED_LIST_STR *tmp_ptr=list_ptr;
    if(tmp_ptr ==  NULL)
    {
        return new_node_ptr;
    }
    while( tmp_ptr->next_ptr != NULL )
    {
        tmp_ptr = tmp_ptr->next_ptr;
    } 

    tmp_ptr->next_ptr = new_node_ptr;
    return list_ptr;
}

SI_REP_EUTRAN_FREQ_STR* sysinfo_eutran_convert_freq_idx( SI_REP_EUTRAN_FREQ_INDEX_STR *rep_freq_index_ptr )
{
    SI_REP_EUTRAN_FREQ_STR *rep_freq_ptr=NULL; /* ptr to be returned */
    SI_REP_EUTRAN_FREQ_STR *tmp_ptr; 

    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    if( ind->si2qInfo.lteNeighbors.noEutranFreqs == 0 )
    {
        return NULL;
    } 
    while(rep_freq_index_ptr != NULL)
    {
        tmp_ptr = malloc(sizeof(SI_REP_EUTRAN_FREQ_STR));
        assert(tmp_ptr != NULL);
        tmp_ptr->next_ptr = NULL;

        if( (rep_freq_index_ptr->eutran_freq_index) >= ind->si2qInfo.lteNeighbors.noEutranFreqs )
        {
            /* given freq_index is not present in the list of eutran ncells */
            tmp_ptr->eutran_arfcn = SI_INVALID_EUTRAN_FREQ;
        }
        else
        {
            tmp_ptr->eutran_arfcn = ind->si2qInfo.lteNeighbors.eutranFreq[rep_freq_index_ptr->eutran_freq_index].earfcn;
        }

        rep_freq_ptr = (SI_REP_EUTRAN_FREQ_STR*) rmcp_sysinfo_linked_list_append((S_SYSINFO_LINKED_LIST_STR*) rep_freq_ptr,(S_SYSINFO_LINKED_LIST_STR*) tmp_ptr);

        rep_freq_index_ptr = rep_freq_index_ptr->next_ptr;
    }

    return rep_freq_ptr;
}

SI_REP_EUTRAN_TA_STR* sysinfo_eutran_ta_list_create( SI_REP_EUTRAN_PCID_TO_TA_STR **rep_pcid_to_ta_map_ptr )
{   
    SI_REP_EUTRAN_TA_STR *rep_ta_list_ptr=NULL; /* pointer to be returned */
    SI_REP_EUTRAN_TA_STR *tmp_ptr = NULL;
    SI_REP_PCIDS_TA_STR *tmp_ptr2 = NULL;
    SI_REP_EUTRAN_FREQ_STR *tmp_freq_list_ptr;
      
      
    while( (*rep_pcid_to_ta_map_ptr) != NULL )
    {
        if( (*rep_pcid_to_ta_map_ptr)->rep_eutran_freq_index_ptr == NULL )
        {
            /* If FREQ_INDEX IE is not present, as per the present understanding
                      * sysinfo should have copied all EUTRAN ncells to this list while
                      * creating the PCID_TO_TA store. So, being NULL is not expected.
                      * Error in sysinfo code 
                      */
            logPrint(LOG_ERR, "EUTRAN PCID to TA LIST is not filled properly");
            return NULL;
        }

        tmp_freq_list_ptr = sysinfo_eutran_convert_freq_idx( (*rep_pcid_to_ta_map_ptr)->rep_eutran_freq_index_ptr);

        if( (*rep_pcid_to_ta_map_ptr)->rep_pcid_ta_group_ptr == NULL )
        {
            /* i.e all pcids in the relevant list of freqs belong to same TA*/
            tmp_ptr = malloc(sizeof(SI_REP_EUTRAN_TA_STR));
            assert(tmp_ptr != NULL);
            tmp_ptr->next_ptr = NULL;
            memset(tmp_ptr->eutran_pcid_bm, 0x00, E_MAX_PCID_BITMAP);
            tmp_ptr->rep_eutran_freq_ptr = tmp_freq_list_ptr;
            tmp_ptr->all_pcids_same_ta = TRUE;
            rep_ta_list_ptr = (SI_REP_EUTRAN_TA_STR*) rmcp_sysinfo_linked_list_append((S_SYSINFO_LINKED_LIST_STR*) rep_ta_list_ptr,(S_SYSINFO_LINKED_LIST_STR*) tmp_ptr);
        }
        else
        {
            /* 
                      * 1) PCID group IE could be repeated for the same list of freqs.
                      * For eg: In Freqs {x,y}, PCIDS {1,2,3} belong to one TA and
                      * PCIDS {4,5,6} belong to different TA
                      *
                      * 2) In EUTRAN TA list being created here, each linked list node
                      * represents different TA. i.e {1,2.3} and {4,5,6} are placed in
                      * seperate nodes, but both nodes points to same list of freqs {x,y}.
                      */
             
            for( tmp_ptr2 = (*rep_pcid_to_ta_map_ptr)->rep_pcid_ta_group_ptr; tmp_ptr2 != NULL; tmp_ptr2 = tmp_ptr2->next_ptr )
            {
                tmp_ptr = malloc(sizeof(SI_REP_EUTRAN_TA_STR));
                assert(tmp_ptr != NULL);
                tmp_ptr->next_ptr = NULL;
                memset(tmp_ptr->eutran_pcid_bm, 0x00, E_MAX_PCID_BITMAP);
                tmp_ptr->rep_eutran_freq_ptr = tmp_freq_list_ptr;
                tmp_ptr->all_pcids_same_ta = FALSE;
                sysinfo_add_pcid_group_to_bm(&(tmp_ptr2->pcid_group),tmp_ptr->eutran_pcid_bm);
                rep_ta_list_ptr = (SI_REP_EUTRAN_TA_STR*) rmcp_sysinfo_linked_list_append( (S_SYSINFO_LINKED_LIST_STR*) rep_ta_list_ptr, (S_SYSINFO_LINKED_LIST_STR*) tmp_ptr);
            }
        }
        *rep_pcid_to_ta_map_ptr = (*rep_pcid_to_ta_map_ptr)->next_ptr;
    }

    return rep_ta_list_ptr;
}

void sysinfo_eutran_ta_list_update( SI_REP_EUTRAN_PCID_TO_TA_STR **rep_eutran_pcid_to_ta_store )
{
    /* Data structures */
    SI_REP_EUTRAN_TA_STR *tmp_eutran_ta_list_ptr=NULL;

    /* Create the new EUTRAN TA LIST from new EUTRAN PCID TO TA LIST */
    tmp_eutran_ta_list_ptr = sysinfo_eutran_ta_list_create( rep_eutran_pcid_to_ta_store );

    
    // si_store.rep_eutran_ta_list_ptr = tmp_eutran_ta_list_ptr;

    if(tmp_eutran_ta_list_ptr != NULL)
    {
        free(tmp_eutran_ta_list_ptr);
        tmp_eutran_ta_list_ptr = NULL;
    }

}


/************************************************************************************************************/

/* Function stores parameters from decoded SI2quater instances to SI-store.
 *
 * Function shall not be called before all needed SI2quater instances
 * have been received. Note that if SI2quater is not used by the NW,
 * we have received all needed instances when we have 0 instances.
 */
/************************************************************************************************************/

static void rr_si_si2quater_store(void)
{
    combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];    
    fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;

    //RR_SI2QUATER_GSM_REP_PARS_STR meas_params_descr;

    /* At the time the instances are gone through, 3G Neighbour Cell Description
    * pointers inside following structure are turned to point to the same
    * dynamically allocated descriptions as the pointers in SI2quater
    * instances point to. Therefore, as there is temporarily two pointers
    * pointing to the same memory block, 3G NEIGHBOUR CELL DESCRIPTION POINTERS
    * INSIDE FOLLOWING STRUCTURE SHALL NOT BE USED FOR MEMORY DEALLOCATION.
    */
    SI_3G_NCELL_DESCRS_WITH_ID_STR umts_ncell_descrs;


    /* At the time the instances are gone through, NC Measurement Parameters are copied from SI2quater instances.
        * Note: NETWORK_CONTROL_ORDER is copied from SI-store (broadcast).
        */
    SI_NC_MEAS_PARS_STR nc_meas_params;

   /* At the time the instances are gone through, following temp pointers are
     * turned to point to the same (dynamically allocated) descriptions as
     * the pointers in SI2quater instances point to. Therefore, as there is
     * temporarily two pointers pointing to the same memory block, THESE
     * TEMP POINTERS SHALL NOT BE USED FOR MEMORY DEALLOCATION.
     */
    const RR_SI2QUATER_GSM_3G_PARS_STR* umts_meas_params_descr = NULL;

    tOCT_UINT8 all_instances_received = ((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK);
    SI_SERVCELL_PRIO_PARAMS_STR* servcell_prio_params        = NULL;
    SI_UTRAN_PRIORITY_PARAMS_STR** utran_prio_params         = NULL;

    SI_REP_EUTRAN_NCELL_STR **rep_eutran_ncell_params_store = NULL;
    SI_REP_EUTRAN_NCELL_STR **combined_rep_eutran_ncell_ptr = NULL;
    SI_REP_EUTRAN_NA_CELLS_STR **rep_eutran_na_cells_store = NULL;
    SI_REP_EUTRAN_NA_CELLS_STR **combined_rep_eutran_na_cells_ptr = NULL;
    SI_REP_EUTRAN_PCID_TO_TA_STR **rep_eutran_pcid_to_ta_store = NULL;
    SI_REP_EUTRAN_PCID_TO_TA_STR **combined_rep_eutran_pcid_to_ta_ptr = NULL;
    tOCT_UINT8 eutran_supported = FALSE;

    tOCT_UINT8 i;
#if 0
    tOCT_UINT8 umts_ccn_active = FALSE;
    
    SI_NCELL_LIST_IDENTIFIER_STR gsm_id;
    SI_NCELL_LIST_IDENTIFIER_STR umts_id;

    gsm_id.identifier_is_psi3_change_mark = FALSE;
    gsm_id.identifier = SI_INVALID_LIST_ID;
    umts_id.identifier_is_psi3_change_mark = FALSE;
    umts_id.identifier = SI_INVALID_LIST_ID;


    //meas_params_descr.report_type = SI_REP_TYPE_DEFAULT_VAL;
    //meas_params_descr.serving_band_reporting = SI_SERVING_BAND_REP_DEFAULT_VAL;
#endif

    umts_ncell_descrs.umts_ncells_descr = NULL;
    umts_ncell_descrs.nbr_of_3g_ncell_descr = 0;
    umts_ncell_descrs.umts_id.identifier_is_psi3_change_mark = FALSE;
    umts_ncell_descrs.umts_id.identifier = SI_INVALID_LIST_ID;
    umts_ncell_descrs.val_31_indicates_resel_list_freq = TRUE;

    nc_meas_params.nc_params_present = FALSE;

    if (rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED)
    {
        logPrint(LOG_INFO, "SI2quater: UTRAN Fast Acq param stored");
    }

    if (all_instances_received)
    {
        logPrint(LOG_INFO, "SI2quater: All instances stored, UTRAN Fast Acq Status = %d", rr_si2quater.fast_acq_utran_status);
    }

    eutran_supported = TRUE;

    if (rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED)
    {
        logPrint(LOG_INFO, "SI2quater: EUTRAN Fast Acq param stored");
    }

    if (NULL != rr_si2quater.instances)
    {
#if 0
        gsm_id.identifier = rr_si2quater.ba_ind;
        umts_id.identifier = rr_si2quater.umts_ba_ind;
#endif

        /* Allocate memory for 3G neighbour cell description when either fast acquisition or full acquisition is done. */
        if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
             rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED ) )
        { 
            umts_ncell_descrs.nbr_of_3g_ncell_descr = rr_si2quater.si2quater_count + 1;

            umts_ncell_descrs.umts_ncells_descr = malloc(sizeof(SI_3G_NCELL_DESCR_STR*) * umts_ncell_descrs.nbr_of_3g_ncell_descr);
            assert(umts_ncell_descrs.umts_ncells_descr != NULL);
            umts_ncell_descrs.umts_id.identifier = rr_si2quater.umts_ba_ind;
        }

        /* Initialize the 3G neighbour cell description and UTRAN priority
               * params when either fast acquisition or full acquisition is done.
               */
        if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
             rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED ) )
        {
            utran_prio_params = malloc(sizeof(SI_UTRAN_PRIORITY_PARAMS_STR*) * (rr_si2quater.si2quater_count + 1));
            assert(utran_prio_params != NULL);

            for (i = 0; i < (rr_si2quater.si2quater_count + 1); i++)
            {
                umts_ncell_descrs.umts_ncells_descr[i] = NULL;
                utran_prio_params[i]= NULL;
            }
        }

        /* Initialize the EUTRAN neighbour cell description, EUTRAN NA cells
               * and EUTRAN PCID to TA mapping when either EUTRAN fast acquisition or
               * full acquisition is done.
               */
        if (((rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
              rr_si2quater.fast_acq_eutran_status != RR_FAST_ACQ_STORED)) && TRUE == eutran_supported )
        { 
            rep_eutran_ncell_params_store = malloc(sizeof(SI_REP_EUTRAN_NCELL_STR*) * (rr_si2quater.si2quater_count + 1));
            assert(rep_eutran_ncell_params_store != NULL);

            rep_eutran_na_cells_store = malloc(sizeof(SI_REP_EUTRAN_NA_CELLS_STR*) * (rr_si2quater.si2quater_count + 1));
            assert(rep_eutran_na_cells_store != NULL);
          
            rep_eutran_pcid_to_ta_store = malloc(sizeof(SI_REP_EUTRAN_PCID_TO_TA_STR*) * (rr_si2quater.si2quater_count + 1));
            assert(rep_eutran_pcid_to_ta_store != NULL);

            for (i = 0; i < (rr_si2quater.si2quater_count + 1); i++)
            {
                rep_eutran_ncell_params_store[i]= NULL;
                rep_eutran_na_cells_store[i]= NULL;
                rep_eutran_pcid_to_ta_store[i]= NULL;
            }
        }

        for (i = 0; i < (rr_si2quater.si2quater_count + 1); i++)
        {
            /* When fast acquistion instances are being stored and some
                       * instances are not received (which is outside the fast
                       * acquistion boundary) skip those instances.
                       */
            if (NULL == rr_si2quater.instances[i])
            {
                logPrint( LOG_INFO, "SI2q Store: Index(%d) Skip", i);
                continue;
            }

            /* Non-3G parameters are stored only when all instances are received. */
            if (all_instances_received)
            {
#if 0
                /* Measurement Parameters Description */
                if (rr_si2quater.instances[i]->gsm_reporting_params_present)
                {
                    meas_params_descr = rr_si2quater.instances[i]->gsm_reporting_params;
                }
#endif
                /* NC Measurement Parameters */
                if (NULL != rr_si2quater.instances[i]->nc_meas_params)
                {
                    (void) memcpy(&nc_meas_params, rr_si2quater.instances[i]->nc_meas_params, sizeof(SI_NC_MEAS_PARS_STR));
                }
            }

            /* 3G parameters are stored when either fast acquisition or full acquisition is done. */
            if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
                 rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED ) )
 	       {
                /* 3G Neighbour Cell Description */
                umts_ncell_descrs.umts_ncells_descr[i] = rr_si2quater.instances[i]->umts_ncell_descr;
 
                /* 3G Measurement Parameters Description */
                if (NULL != rr_si2quater.instances[i]->gsm_3g_params)
                {
                    umts_meas_params_descr = rr_si2quater.instances[i]->gsm_3g_params;
                }
             }
#if 0 
            /* 3G parameters are stored when either fast acquisition or full acquisition is done. */
            if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
                 rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED) )
 	        {
                if (rr_si2quater.instances[i]->rel6_params_present)
                {
                    umts_ccn_active = rr_si2quater.instances[i]->umts_ccn_active;
                }
            }
#endif
 
            /* Serving cell priority are stored when UTRAN/EUTRAN fast acquisition or full acquisition is done. */
            if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || \
             (rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED)|| all_instances_received )
            {
                if (NULL != rr_si2quater.instances[i]->servcell_prio_params)
                {
                    servcell_prio_params = rr_si2quater.instances[i]->servcell_prio_params;
                }
            }
 
            /* 3G parameters are stored when either fast acquisition or full  acquisition is done. */
            if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
                 rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED) )
            {
                utran_prio_params[i] = (rr_si2quater.instances[i])->utran_prio_params;
            }
 
            if (((rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
                  rr_si2quater.fast_acq_eutran_status != RR_FAST_ACQ_STORED)) && TRUE == eutran_supported )
            {
                rep_eutran_ncell_params_store[i] = (rr_si2quater.instances[i])->rep_eutran_ncells_ptr;
                rep_eutran_na_cells_store[i] = (rr_si2quater.instances[i])->rep_eutran_na_cells_ptr;
                rep_eutran_pcid_to_ta_store[i] = (rr_si2quater.instances[i])->rep_pcid_to_ta_map_ptr;
            }
        } /* end of for */
	} /*end of NULL != instances */

    if( (rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
         rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED) )
	{
        /* 3G Neighbour Cell Descriptions */

        sysinfo_3g_ncell_descrs_store(&umts_ncell_descrs);

        if (NULL != umts_ncell_descrs.umts_ncells_descr)
        {
            free(umts_ncell_descrs.umts_ncells_descr);
            umts_ncell_descrs.umts_ncells_descr = NULL;
        }

        /* 3G Measurement Parameters Description */

        if (NULL != umts_meas_params_descr)
        {
            ind->si2qInfo.umtsMeasParams.qSearchI = umts_meas_params_descr->qsearch_i;
            ind->si2qInfo.umtsMeasParams.qSearchCInit = umts_meas_params_descr->qsearch_c_initial;
            ind->si2qInfo.umtsMeasParams.fddParamsPresent = umts_meas_params_descr->fdd_params_present;
        }

        if (NULL != umts_meas_params_descr && umts_meas_params_descr->fdd_params_present)
        {
            ind->si2qInfo.umtsMeasParams.fddParams.fddQoffset  = umts_meas_params_descr->fdd_params.fdd_qoffset;
            ind->si2qInfo.umtsMeasParams.fddParams.fddRepQuant = umts_meas_params_descr->fdd_params.fdd_rep_quant;
            ind->si2qInfo.umtsMeasParams.fddParams.fddMultiratReporting  = umts_meas_params_descr->fdd_params.fdd_multirat_reporting;            
            ind->si2qInfo.umtsMeasParams.fddParams.fddQmin  = umts_meas_params_descr->fdd_params.fdd_qmin;
        }
        else
        {
            ind->si2qInfo.umtsMeasParams.fddParams.fddQoffset = SI_QOFFSET_DEFAULT_VAL;
            ind->si2qInfo.umtsMeasParams.fddParams.fddQmin = SI_FDD_QMIN_DEFAULT_VAL;
        }

    }

   if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || \
       (rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED)|| all_instances_received )
   {
       /* Serving Cell Priority Parameters Description */
       if (NULL != servcell_prio_params)
       {
           ind->si2qInfo.servCellPrioParams.scellPrioParamsPresent = servcell_prio_params->scell_prio_params_present;
           if(TRUE == servcell_prio_params->scell_prio_params_present)
           {
               ind->si2qInfo.servCellPrioParams.geranPriority = servcell_prio_params->geran_priority;
               ind->si2qInfo.servCellPrioParams.threshPrioSearch = servcell_prio_params->thresh_priority_search;
               ind->si2qInfo.servCellPrioParams.threshGsmLow = servcell_prio_params->thresh_gsm_low;
               ind->si2qInfo.servCellPrioParams.hPrio = servcell_prio_params->h_prio;
               ind->si2qInfo.servCellPrioParams.tReselection = servcell_prio_params->t_reselection;
           }
       }
   }

    if ((rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && 
         rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED) )
    {
        /* 3G Default Priority Parameters and 3G Repeated UTRAN Priority Parameters Description */
        sysinfo_utran_params_store(utran_prio_params,rr_si2quater.si2quater_count + 1);

        if ( NULL != utran_prio_params)
        {
            free(utran_prio_params);
            utran_prio_params = NULL;
        }
        
        if( ((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK) || rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED )
        {
            rr_si2quater.fast_acq_utran_status = RR_FAST_ACQ_STORED;   
        }
    }

    if (((rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED) || (all_instances_received && \
          rr_si2quater.fast_acq_eutran_status != RR_FAST_ACQ_STORED)) && TRUE == eutran_supported )
    {

        combined_rep_eutran_ncell_ptr = malloc(sizeof(SI_REP_EUTRAN_NCELL_STR*) * (rr_si2quater.si2quater_count + 1));
        assert(combined_rep_eutran_ncell_ptr != NULL);
        
        combined_rep_eutran_na_cells_ptr = malloc(sizeof(SI_REP_EUTRAN_NA_CELLS_STR*) * (rr_si2quater.si2quater_count + 1));
        assert(combined_rep_eutran_na_cells_ptr != NULL);
        
        combined_rep_eutran_pcid_to_ta_ptr = malloc(sizeof(SI_REP_EUTRAN_PCID_TO_TA_STR*) * (rr_si2quater.si2quater_count + 1));
        assert(combined_rep_eutran_pcid_to_ta_ptr != NULL);

        for (i = 0; i < (rr_si2quater.si2quater_count + 1); i++)
        {
            combined_rep_eutran_ncell_ptr[i]= NULL;
            combined_rep_eutran_na_cells_ptr[i]= NULL;
            combined_rep_eutran_pcid_to_ta_ptr[i]= NULL;
        }

        /* Store EUTRAN neighbour cells  to SYSINFO */
        if(rep_eutran_ncell_params_store != NULL && *rep_eutran_ncell_params_store != NULL)
          sysinfo_rep_eutran_ncell_store(rep_eutran_ncell_params_store, combined_rep_eutran_ncell_ptr, rr_si2quater.si2quater_count + 1);

        /* Store EUTRAN not allowed cells to SYSINFO*/
        if(rep_eutran_na_cells_store != NULL && *rep_eutran_na_cells_store != NULL)
          sysinfo_rep_eutran_na_cells_store(rep_eutran_na_cells_store, rep_eutran_ncell_params_store, combined_rep_eutran_na_cells_ptr, rr_si2quater.si2quater_count + 1);

        /* Store EUTRAN PCID to TA mapping to SYSINFO*/
        if(rep_eutran_pcid_to_ta_store != NULL && *rep_eutran_pcid_to_ta_store != NULL)
          sysinfo_rep_eutra_pcid_to_ta_store(rep_eutran_pcid_to_ta_store, rep_eutran_ncell_params_store,combined_rep_eutran_pcid_to_ta_ptr, rr_si2quater.si2quater_count + 1);

        if(combined_rep_eutran_ncell_ptr != NULL && *combined_rep_eutran_ncell_ptr != NULL && \
           combined_rep_eutran_na_cells_ptr != NULL && *combined_rep_eutran_na_cells_ptr != NULL )
          sysinfo_eu_na_cell_list_update(combined_rep_eutran_ncell_ptr, combined_rep_eutran_na_cells_ptr );

        if(combined_rep_eutran_pcid_to_ta_ptr != NULL && *combined_rep_eutran_pcid_to_ta_ptr != NULL)
          sysinfo_eutran_ta_list_update( combined_rep_eutran_pcid_to_ta_ptr );
        
        if ( NULL != rep_eutran_na_cells_store)
        {
            free(rep_eutran_na_cells_store);
            rep_eutran_na_cells_store = NULL;
        }

        if ( NULL != rep_eutran_pcid_to_ta_store)
        {
            free(rep_eutran_pcid_to_ta_store);
            rep_eutran_pcid_to_ta_store = NULL;
        }
        
        if ( NULL != rep_eutran_ncell_params_store)
        {
            free(rep_eutran_ncell_params_store);
            rep_eutran_ncell_params_store = NULL;
        }

        if ( NULL != combined_rep_eutran_na_cells_ptr)
        {
            free(combined_rep_eutran_na_cells_ptr);
            combined_rep_eutran_na_cells_ptr = NULL;
        }

        if ( NULL != combined_rep_eutran_pcid_to_ta_ptr)
        {
            free(combined_rep_eutran_pcid_to_ta_ptr);
            combined_rep_eutran_pcid_to_ta_ptr = NULL;
        }
        
        if ( NULL != combined_rep_eutran_ncell_ptr)
        {
            free(combined_rep_eutran_ncell_ptr);
            combined_rep_eutran_ncell_ptr = NULL;
        }

        if( ((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK) || rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED )
        {
            rr_si2quater.fast_acq_eutran_status = RR_FAST_ACQ_STORED;   
        }
    }
}


/************************************************************************************************************/
tOCT_UINT8 rr_si_si2quater_handle(const tOCT_UINT8* si2quater_data, FILE * fp, cellParams *params)
{

	RR_DECODED_SI2QUATER_STR* decoded_buffer = NULL;
    tOCT_UINT8 instance_set_updated = FALSE;
    tOCT_UINT8 umts_ncell_info_present = FALSE;
    
	assert(NULL != si2quater_data);
	decoded_buffer = rr_si_si2quater_decode(si2quater_data);
    
	logPrint(LOG_DEBUG,"rr_si_si2quater_handle si2qCell = %d , params->cellId = %d \n", si2qCell, params->cellId);

	if(si2qCell != params->cellId)
	{
		tOCT_UINT8 i = 0;
		combinedSIs *sendReady = (combinedSIs *) &sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];

        /* erroneous instance */
        if (NULL == decoded_buffer)
        {
            sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2QUATER_MASK));
            rr_si_si2quater_delete();
            logPrint(LOG_ERR, "Erroneous SI2-q Instance");
            return FALSE;
        }

        if (NULL == rr_si2quater.instances || decoded_buffer->mp_change_mark != rr_si2quater.mp_change_mark ||
            decoded_buffer->ba_ind != rr_si2quater.ba_ind || decoded_buffer->umts_ba_ind != rr_si2quater.umts_ba_ind )
        {
            rr_si_si2quater_delete();
            sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2QUATER_MASK));
    
            rr_si2quater.si2quater_count = decoded_buffer->si2quater_count;
            rr_si2quater.mp_change_mark = decoded_buffer->mp_change_mark;
            rr_si2quater.ba_ind = decoded_buffer->ba_ind;
            rr_si2quater.umts_ba_ind = decoded_buffer->umts_ba_ind;
    
            rr_si2quater.instances = malloc((rr_si2quater.si2quater_count + 1) * sizeof(RR_DECODED_SI2QUATER_STR*));
            assert(rr_si2quater.instances != NULL);
    
            for (i = 0; i < rr_si2quater.si2quater_count + 1; i++)
            {
                rr_si2quater.instances[i] = NULL;
            }
        }

        else
        {
            /* check correctness of received SI2quater_COUNT; erroneous instance
                       * causes restarting the reception
                       */
            if (decoded_buffer->si2quater_count != rr_si2quater.si2quater_count)
            {
                logPrint(LOG_ERR, "Semantically incorrect SI2quater");

                rr_si_si2quater_delete();
                sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2QUATER_MASK));

                rr_si_decoded_si2quater_dealloc(decoded_buffer);
                free(decoded_buffer);
                decoded_buffer = NULL;
                return FALSE;
            }
        }

        /* received instance is stored if it hasn't been received earlier */
        if (NULL == rr_si2quater.instances[decoded_buffer->si2quater_index])
        {
            rr_si2quater.instances[decoded_buffer->si2quater_index] = decoded_buffer;
            instance_set_updated = TRUE;

            /* Fast acquisition: UTRAN */
            if (rr_si2quater.fast_acq_utran_status != RR_FAST_ACQ_STORED)
            {
                if (decoded_buffer->utran_start == 1)
                {
                    rr_si2quater.fast_acq_utran_start_index = decoded_buffer->si2quater_index;
                }

                if (decoded_buffer->utran_stop == 1)
                {
                    rr_si2quater.fast_acq_utran_stop_index = decoded_buffer->si2quater_index;
                }
           
                if (rr_si2quater.fast_acq_utran_start_index != SI2QUATER_INVALID_INDEX && \
                    rr_si2quater.fast_acq_utran_stop_index  != SI2QUATER_INVALID_INDEX )
                {
                    logPrint( LOG_INFO, "SI2-Q: UTRAN start index = %d", rr_si2quater.fast_acq_utran_start_index);
                    logPrint( LOG_INFO, "SI2-Q: UTRAN stop index = %d", rr_si2quater.fast_acq_utran_stop_index);
       
                    if (rr_si2quater.fast_acq_utran_start_index <= rr_si2quater.fast_acq_utran_stop_index)
                    {
                        rr_si2quater.fast_acq_utran_status = RR_FAST_ACQ_COMPLETED;
                        for (i = rr_si2quater.fast_acq_utran_start_index;i <= rr_si2quater.fast_acq_utran_stop_index; i++)
                        {
                            if (NULL == rr_si2quater.instances[i])
                            {
                                rr_si2quater.fast_acq_utran_status = RR_FAST_ACQ_INCOMPLETE;
                            }
                            else
                            {
                                /* check if any of the instances with the UTRAN Start/Stop range has some valid 3G NCell Parameters */
                                if ( NULL != rr_si2quater.instances[i]->umts_ncell_descr)
                                {
                                   umts_ncell_info_present = TRUE;
                                }
                            }
                        }
                        /* If UTRAN Start/Stop bit is set, it's always checked
                                            * whether any of the instances within the Start/Stop range
                                            * contains any 3G NCell Information, if no Fast Acquisition
                                            * is ignored and goes for complete acquisition.
                                            */
                        if (umts_ncell_info_present == FALSE)
                        {
                            rr_si2quater.fast_acq_utran_status = RR_FAST_ACQ_INCOMPLETE;
                            /* Warning: instances within the Start/Stop range doesn't
                                                   * contain any 3G NCell Information. In this case only 
                                                   * full acquisition shall be done.
                                                   */
                            logPrint(LOG_INFO, "Intances indicated by UTRAN START/STOP doesn't contain any 3G NCELL Info");
                        }
                    }
                    else
                    {
                        /* Warning: UTRAN_Stop index arrives before UTRAN_start
                                            * index. In this case only full acquisition shall be done.
                                            */
                        logPrint(LOG_INFO, "Incorrect SI2quater UTRAN_Start and UTRAN_Stop indexes");
                    }
                } /* if != SI2QUATER_INVALID_INDEX */            
            } /* if fast acq utran != RR_FAST_ACQ_STORED */   
     
            /*  Fast acquisition: EUTRAN */
            if (rr_si2quater.fast_acq_eutran_status != RR_FAST_ACQ_STORED )
            {
                if (decoded_buffer->eutran_start == 1)
                {
                    rr_si2quater.fast_acq_eutran_start_index = decoded_buffer->si2quater_index;
                }
            
                if (decoded_buffer->eutran_stop == 1)
                {
                    rr_si2quater.fast_acq_eutran_stop_index = decoded_buffer->si2quater_index;
                }

                if (rr_si2quater.fast_acq_eutran_start_index != SI2QUATER_INVALID_INDEX &&\
                    rr_si2quater.fast_acq_eutran_stop_index != SI2QUATER_INVALID_INDEX )
                {
                    logPrint( LOG_INFO, "SI2-Q: UTRAN start index = %d", rr_si2quater.fast_acq_eutran_start_index);
                    logPrint( LOG_INFO, "SI2-Q: UTRAN stop index = %d", rr_si2quater.fast_acq_eutran_stop_index);

                    if (rr_si2quater.fast_acq_eutran_start_index <= rr_si2quater.fast_acq_eutran_stop_index)
                    {
                        rr_si2quater.fast_acq_eutran_status = RR_FAST_ACQ_COMPLETED;

                        for (i = rr_si2quater.fast_acq_eutran_start_index; i <= rr_si2quater.fast_acq_eutran_stop_index; i++)
                        {
                            if (NULL == rr_si2quater.instances[i])
                            {
                                rr_si2quater.fast_acq_eutran_status = RR_FAST_ACQ_INCOMPLETE;
                            }
                        }                     
                    }
                    else
                    {
                      /* Warning: EUTRAN_Stop index arrives before EUTRAN_start index
                                        * In this case only full acquisition shall be done.
                                        */
                      logPrint(LOG_INFO, "Incorrect SI2quater EUTRAN_Start and EUTRAN_Stop indexes");  
                    }
                } /* if != SI2QUATER_INVALID_INDEX */           
            } /* if Fast acq EUTRAN != RR_FAST_ACQ_STORED */

            decoded_buffer = NULL;
        } /* current stored instance == NULL */
        else
        {
            rr_si_decoded_si2quater_dealloc(decoded_buffer);
            free(decoded_buffer);
            decoded_buffer = NULL;
        }

        /* SI2quater is marked as received if all instances have been received */
        sendReady->siRcvd |= RR_SI2QUATER_MASK;
        for (i = 0; i < rr_si2quater.si2quater_count + 1; i++)
        {
            if (NULL == rr_si2quater.instances[i])
            {
                sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2QUATER_MASK));
                break;
            }
        }

        if((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK)
        {
            si2qCell = params->cellId;
            sendReady->servingCellId = si2qCell;
        }

        /* Store the SI2quater instances if either full acquisition or fast acquisition is complted. */
        if (( instance_set_updated && \
           (((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK) && (RR_SI2QUATER_NOT_SENT != rr_si2quater.si2quater_indicator)))   && \
           (((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK) || (rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_COMPLETED) || \
             (rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_COMPLETED)))
        {
            rr_si_si2quater_store();
        }

        /* Delete the stored SI2quater once the Sys Info Ind for client is filled */
        if(((sendReady->siRcvd & RR_SI2QUATER_MASK) == RR_SI2QUATER_MASK) && \
            (rr_si2quater.fast_acq_utran_status == RR_FAST_ACQ_STORED) && \
            (rr_si2quater.fast_acq_eutran_status == RR_FAST_ACQ_STORED) )
        {
            sendReady->siRcvd &= ~((tOCT_UINT16)(RR_SI2QUATER_MASK));
            rr_si_si2quater_delete();
        }
    }

	return TRUE;
}

/************************************************************************************************************/

SI_DECODED_SI3_STR* rr_si_si3_decode(const tOCT_UINT8* byte_stream)
{
	SI_DECODED_SI3_STR* decoded_si3_ptr;
	RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr;

	decoded_si3_ptr = (SI_DECODED_SI3_STR *) malloc(sizeof(SI_DECODED_SI3_STR));
    assert(decoded_si3_ptr!= NULL);

    rmcp_csn1_field_read_params_ptr = (RMCP_CSN1_FIELD_READ_PARAMS_STR *) malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_csn1_field_read_params_ptr!= NULL);
    
    tOCT_UINT8 error_status;

	assert( byte_stream != NULL );

    /* Unfortunately we need to cast away the constness of byte_stream to
     * be able to use CSN.1 decoding functions...
     */
	rmcp_csn1_field_read_params_ptr->decoding_position = (tOCT_UINT8*) byte_stream;
	rmcp_csn1_field_read_params_ptr->bit_index = 8;
	rmcp_csn1_field_read_params_ptr->bits_left = RR_SI3_DATA_LEN * 8;
	rmcp_csn1_field_read_params_ptr->padding = 0x00;

	memset(decoded_si3_ptr, 0x00, sizeof(SI_DECODED_SI3_STR));

    /* prepare for decoding error
     */
    if (( error_status = ( tOCT_UINT8 ) setjmp( rmcp_csn1_field_read_params_ptr->err_buf)) != 0 )
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:
                break;

            default:
                break;
        }

        free( rmcp_csn1_field_read_params_ptr );
        rmcp_csn1_field_read_params_ptr = NULL;

        free(decoded_si3_ptr);
        decoded_si3_ptr = NULL;

        return NULL;
    }
    else
    {
    	/* Cell Identity
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 8;
    	decoded_si3_ptr->cell_id.ci_value[0] =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->cell_id.ci_value[1] =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	/* Location Area Identification
    	 */
    	decoded_si3_ptr->lai.mcc2_mcc1 =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->lai.mnc3_mcc3 =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->lai.mnc2_mnc1 =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->lai.lac[0] =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->lai.lac[1] =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	/* Control Channel Description
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->ctrl_channel_desc.mscr =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.att_allowed =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 3;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.bs_ag_blks_res =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 2;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.bs_cc_chans =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.sdcch_ccch_cmb_flag =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	/* Skip spares
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 5;
    	(void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 3;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.bs_pa_mfrms =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 8;
    	decoded_si3_ptr->ctrl_channel_desc.ctrl_ch_descr.t3212_value =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	/* BCCH cell Options
    	 */
    	/* Skips dn_ind
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	(void) rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->bcch_cell_options.pwrc_set =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 2;
    	decoded_si3_ptr->bcch_cell_options.dtx =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 4;
    	decoded_si3_ptr->bcch_cell_options.radio_link_timeout =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	/* Cell Selection Parameters
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 3;
    	decoded_si3_ptr->cell_select_parameters.cell_reselect_hysteresis =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 5;
    	decoded_si3_ptr->cell_select_parameters.ms_txpwr_max_cch =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->cell_select_parameters.acs =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->cell_select_parameters.neci =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 6;
    	decoded_si3_ptr->cell_select_parameters.rxlev_access_min =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	/* RACH Control Parameters
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 2;
    	decoded_si3_ptr->rach_control_parameters.rach_ctrl_params.max_retrans =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 4;
    	decoded_si3_ptr->rach_control_parameters.rach_ctrl_params.tx_integer =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->rach_control_parameters.rach_ctrl_params.
    		cell_bar_access =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->rach_control_parameters.rach_ctrl_params.re_disabled =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->length = 8;
    	decoded_si3_ptr->rach_control_parameters.access_control_class =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr ) << 8;
    	decoded_si3_ptr->rach_control_parameters.access_control_class +=
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	decoded_si3_ptr->rach_control_parameters.rach_ctrl_params.ec_disabled =
    		((tOCT_UINT8)(decoded_si3_ptr->rach_control_parameters.
    		access_control_class >> 10)) & B0000_0001;

    	/* SI3 Rest Octets
    	 */
    	rmcp_csn1_field_read_params_ptr->length = 1;
    	rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    	decoded_si3_ptr->si3_rest_octets.opt_selection_params.present =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	if (decoded_si3_ptr->si3_rest_octets.opt_selection_params.present)
    		{
    		rmcp_csn1_field_read_params_ptr->padding = 0x00;
    		decoded_si3_ptr->si3_rest_octets.opt_selection_params.cbq =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->length = 6;
    		decoded_si3_ptr->si3_rest_octets.opt_selection_params.
    			cell_reselect_offset =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->length = 3;
    		decoded_si3_ptr->si3_rest_octets.opt_selection_params.
    			temporary_offset =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->length = 5;
    		decoded_si3_ptr->si3_rest_octets.opt_selection_params.
    			penalty_time =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		}

    	rmcp_csn1_field_read_params_ptr->length = 1;
    	rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    	decoded_si3_ptr->si3_rest_octets.opt_power_offset.present =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr->padding = 0x00;
    	if (decoded_si3_ptr->si3_rest_octets.opt_power_offset.present)
    		{
    		rmcp_csn1_field_read_params_ptr->length = 2;
    		decoded_si3_ptr->si3_rest_octets.opt_power_offset.
    			opt_power_offset =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		}

    	rmcp_csn1_field_read_params_ptr->length = 1;
    	rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    	decoded_si3_ptr->si3_rest_octets.si2ter_indicator =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	decoded_si3_ptr->si3_rest_octets.early_clm_sending_ctrl =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	decoded_si3_ptr->si3_rest_octets.if_and_where.present =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	if (decoded_si3_ptr->si3_rest_octets.if_and_where.present)
    		{
    		rmcp_csn1_field_read_params_ptr->padding = 0x00;
    		rmcp_csn1_field_read_params_ptr->length = 3;
    		decoded_si3_ptr->si3_rest_octets.if_and_where.where =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    		}

    	rmcp_csn1_field_read_params_ptr->length = 1;
    	decoded_si3_ptr->si3_rest_octets.gprs_indicator.gprs_supported =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	if (decoded_si3_ptr->si3_rest_octets.gprs_indicator.gprs_supported)
    		{
    		rmcp_csn1_field_read_params_ptr->length = 3;
    		rmcp_csn1_field_read_params_ptr->padding = 0x00;
    		decoded_si3_ptr->si3_rest_octets.gprs_indicator.ra_colour =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->length = 1;
    		decoded_si3_ptr->si3_rest_octets.gprs_indicator.si13_position =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    		}

    	rmcp_csn1_field_read_params_ptr->length = 1;
    	rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
    	decoded_si3_ptr->si3_rest_octets.early_3g_clm_sending_restrict =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );

    	decoded_si3_ptr->si3_rest_octets.si2quater_indicator.present =
    		rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    	if (decoded_si3_ptr->si3_rest_octets.si2quater_indicator.present)
    		{
    		rmcp_csn1_field_read_params_ptr->padding = 0x00;
    		decoded_si3_ptr->si3_rest_octets.si2quater_indicator.
    			si2quater_position =
    			rmcp_csn1_field_read( rmcp_csn1_field_read_params_ptr );
    		}

    	free( rmcp_csn1_field_read_params_ptr );
    	rmcp_csn1_field_read_params_ptr = NULL;

    	return decoded_si3_ptr;
    	}
}

/************************************************************************************************************/

static const tOCT_INT8* power_conversion_table_get( int band )
{
    const tOCT_INT8* table_ptr = NULL;

  /*
     * Get table according to band
     */
    switch( band )
    {
        case FXL_BAND_GSM_900:        
        case FXL_BAND_E_GSM  :
        case FXL_BAND_R_GSM  :
        case FXL_BAND_GSM_450:
            /* flowthrough */
        case FXL_BAND_GSM_850:
            /* flowthrough */
            table_ptr = power_gsm_ctrl_level_dbm;
            break;

        case FXL_BAND_DCS_1800:
            table_ptr = power_dcs1800_ctrl_level_dbm;
            break;

        case FXL_BAND_PCS_1900:
            table_ptr = power_dcs1900_ctrl_level_dbm;
            break;

        default:
            logPrint(LOG_DEBUG, "Invalid Band(%d)", band );
            break;

    }
    return table_ptr;

}

/************************************************************************************************************/

tOCT_INT8 power_level_dbm_get( int band, tOCT_UINT8 power_level )
{

    const tOCT_INT8* power_table = NULL;

    /* Table index check for boundaries */
    if( power_level >= POWER_TXPWR_TABLE_INDEX_COUNT )
    {
        power_level = 0;
    }

    /* Read dBm value from band specific table */
    power_table = power_conversion_table_get( band );
    
    return( power_table[ power_level ] );
}

/************************************************************************************************************/

tOCT_UINT8 ms_par_txpwr_max_read( int band )
{

    tOCT_UINT8       txpwr_max = 0;

    switch (band)
    {
        case FXL_BAND_GSM_450:
        case FXL_BAND_GSM_900:
        case FXL_BAND_E_GSM  :
        case FXL_BAND_R_GSM  :
        case FXL_BAND_GSM_850:
            /* 5=33 dBm, assuming lower band MS power class : 4 */
            txpwr_max = 5;
            break;

        case FXL_BAND_DCS_1800:
        case FXL_BAND_PCS_1900:
            /* 0=30 dBm, assuming lower band MS power class : 1 */
            txpwr_max = 0;
            break;

        default:
            logPrint(LOG_DEBUG, "Invalid Band(%d)", band );
            break;
    }

    return txpwr_max;
}

/************************************************************************************************************/

tOCT_INT16  calculateC1( int band, sint8 rxlev_dbm, tOCT_INT16 rxlev_access_min_dbm, tOCT_INT16 ms_txpwr_max_cch )
{
    tOCT_INT16 ms_txpwr_max_cch_dbm;
    tOCT_INT16 a, b, p;
    tOCT_INT16 c1;

    ms_txpwr_max_cch_dbm = power_level_dbm_get( band, ( tOCT_UINT8 ) ms_txpwr_max_cch );

    p = power_level_dbm_get( band, ms_par_txpwr_max_read( band ) );

    b = ms_txpwr_max_cch_dbm - p;

    a = rxlev_dbm - rxlev_access_min_dbm;

    c1 = ( a - ( tOCT_INT16 ) (MAX( b, 0 ) ));

    return( c1 );
}

/************************************************************************************************************/

tOCT_UINT8 rr_si_si3_handle(
RR_BYTE_BASED_SI_UNION_STR* sysinfo_union_ptr,FILE * fp , cellParams *params)
{
	SI_DECODED_SI3_STR *decoded_si3 = NULL;
	tOCT_UINT16 CellId = 0;
    tOCT_UINT16 Lac = 0;
    tOCT_UINT16 i = 0;    
    tOCT_INT16 rxlev_access_min_dbm;
    tOCT_INT8  resel_offset;
    sint8 rxlev_dbm;

	assert(NULL != sysinfo_union_ptr);
	decoded_si3 = rr_si_si3_decode((tOCT_UINT8*)&sysinfo_union_ptr->bcch_data);
	logPrint(LOG_DEBUG,"rr_si_si3_handle si3Cell = %d , params->cellId = %d \n", si3Cell, params->cellId);
	if(si3Cell != params->cellId && decoded_si3 != NULL)
	{
		fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
		combinedSIs *sendReady = (combinedSIs *)&sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];
		si3Cell = params->cellId;

		fprintf(fp , "System Information-3 Elements\n");
		CellId = (decoded_si3->cell_id.ci_value[0]<<8)|(decoded_si3->cell_id.ci_value[1]);
		fprintf(fp, "SI-3-Serving-Cell-ID=%d\n",CellId);

		//fprintf(fp , "SI-3 LAI Lac = %d  Mcc = %d  Mnc = %d\n",lai_bcd.lac , lai_bcd.mcc , lai_bcd.mnc );
		fprintf(fp , "SI-3-Serving-Cell-Mcc[0]=%d  \n",(decoded_si3->lai.mcc2_mcc1 & 0x0F));
		fprintf(fp , "SI-3-Serving-Cell-Mcc[1]=%d  \n",(decoded_si3->lai.mcc2_mcc1 >> 4));
		fprintf(fp , "SI-3-Serving-Cell-Mcc[2]=%d  \n",(decoded_si3->lai.mnc3_mcc3 & 0x0F));

		fprintf(fp , "SI-3-Serving-Cell-Mnc[0]=%d  \n",(decoded_si3->lai.mnc2_mnc1 & 0x0F));
		fprintf(fp , "SI-3-Serving-Cell-Mnc[1]=%d  \n",(decoded_si3->lai.mnc2_mnc1 >> 4));
		fprintf(fp , "SI-3-Serving-Cell-Mnc[2]=%d  \n",(decoded_si3->lai.mnc3_mcc3 >> 4));

        Lac = (decoded_si3->lai.lac[0]<<8) | (decoded_si3->lai.lac[1]);
		fprintf(fp , "SI-3-Serving-Cell-Lac=%d  \n",Lac);
		fprintf(fp , "##-------------------------------------------------------------##\n");

        
        /* SI2quater Indicator*/
        if (FALSE == decoded_si3->si3_rest_octets.si2quater_indicator.present)
        {
            rr_si2quater.si2quater_indicator = RR_SI2QUATER_NOT_SENT;
            sendReady->siRcvd |= RR_SI2QUATER_MASK;
        }
        else
        {
            if (0x00 == decoded_si3->si3_rest_octets.si2quater_indicator.si2quater_position)
            {
                rr_si2quater.si2quater_indicator = RR_SI2QUATER_SENT_ON_BCCH_NORM;
            }
            else
            {
                rr_si2quater.si2quater_indicator = RR_SI2QUATER_SENT_ON_BCCH_EXT;
            }
        }

        /* Set SI2ter flag as received if it is not expected */
        if (FALSE == decoded_si3->si3_rest_octets.si2ter_indicator)
        {
            sendReady->siRcvd |= RR_SI2TER_MASK;
        }
        
		// Populate the SYS-INFO-IND structure to send it to client later.
		ind->arfcn  = params->arfcn;
		ind->band   = params->band;
		ind->ncc    = params->ncc;
        ind->bcc    = params->bcc;
		ind->cellId = CellId;
		ind->lac    = Lac;
       
                // Fill T3212 timer
                ind->t3212 = decoded_si3->ctrl_channel_desc.ctrl_ch_descr.t3212_value;
                
		ind->plmn.mcc[0] = (decoded_si3->lai.mcc2_mcc1 & 0x0F);
		ind->plmn.mcc[1] = (decoded_si3->lai.mcc2_mcc1 >> 4);
		ind->plmn.mcc[2] = (decoded_si3->lai.mnc3_mcc3 & 0x0F);

        ind->plmn.mccLength = 0;
        for( i = 0; i < GSM_MAX_MCC_LENGTH; i++)
        {
            if(ind->plmn.mcc[i] != 0xF)
              ind->plmn.mccLength++;
        }

        ind->plmn.mnc[0] = (decoded_si3->lai.mnc2_mnc1 & 0x0F);
		ind->plmn.mnc[1] = (decoded_si3->lai.mnc2_mnc1 >> 4);
		ind->plmn.mnc[2] = (decoded_si3->lai.mnc3_mcc3 >> 4);

        ind->plmn.mncLength = 0;
        for( i = 0; i < GSM_MAX_MNC_LENGTH; i++)
        {
            if(ind->plmn.mnc[i] != 0xF)
              ind->plmn.mncLength++;
        }

		ind->rssi   = params->rssi;
		ind->snr    = params->snr;

        
        rxlev_access_min_dbm = decoded_si3->cell_select_parameters.rxlev_access_min - 111;

        if( (sint8)params->rssi == 0 )
        {
            rxlev_dbm = -128;
        }
        else
        {
            rxlev_dbm = (sint8)params->rssi;
        }

        ind->c1 = calculateC1( params->band, rxlev_dbm, rxlev_access_min_dbm, decoded_si3->cell_select_parameters.ms_txpwr_max_cch );

        ind->c2 = ind->c1;
        
        if(decoded_si3->si3_rest_octets.opt_selection_params.present)
        {
            resel_offset = decoded_si3->si3_rest_octets.opt_selection_params.cell_reselect_offset * 2;
            if(decoded_si3->si3_rest_octets.opt_selection_params.penalty_time == SPECIAL_PENALTY_TIME)
            {
                ind->c2 = ind->c2 - resel_offset;
            }
            else
            {
                ind->c2 = ind->c2 + resel_offset;
            }
        }
        ind->rxlevAccMin = decoded_si3->cell_select_parameters.rxlev_access_min;    
        ind->msTxpwrMaxCcch = decoded_si3->cell_select_parameters.ms_txpwr_max_cch;
        ind->cro = decoded_si3->si3_rest_octets.opt_selection_params.cell_reselect_offset;
        ind->tempOffset = decoded_si3->si3_rest_octets.opt_selection_params.temporary_offset;
        ind->penaltyTime = decoded_si3->si3_rest_octets.opt_selection_params.penalty_time;

		sendReady->servingCellId = si3Cell;
        sendReady->siRcvd |= RR_SI3_MASK;

	}

	free(decoded_si3);
	decoded_si3 = NULL;

	return TRUE;
}

/************************************************************************************************************/

RR_DECODED_SI4_REST_OCTS_STR* rr_si_si4_rest_octs_decode(
    const tOCT_UINT8* byte_stream, sint16 bits_left)
	{

	/* Data Structures */

	RR_DECODED_SI4_REST_OCTS_STR* ret_val;
	RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr;

	ret_val = (RR_DECODED_SI4_REST_OCTS_STR *) malloc(sizeof(RR_DECODED_SI4_REST_OCTS_STR));
    assert(ret_val != NULL);

    rmcp_csn1_field_read_params_ptr = (RMCP_CSN1_FIELD_READ_PARAMS_STR *) malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_csn1_field_read_params_ptr != NULL);

    tOCT_UINT8 error_status;

	/* Code */

	assert(NULL != byte_stream );

	rmcp_csn1_field_read_params_ptr->decoding_position = (tOCT_UINT8*) byte_stream;
	rmcp_csn1_field_read_params_ptr->bit_index = 8;
	rmcp_csn1_field_read_params_ptr->bits_left = bits_left;

	memset(ret_val, 0x00, sizeof(RR_DECODED_SI4_REST_OCTS_STR));

    /* prepare for decoding error
     */
    if (( error_status = ( tOCT_UINT8 ) setjmp( rmcp_csn1_field_read_params_ptr->err_buf )) != 0 )
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:
                break;

            default:
                break;
        }
        free(ret_val);
        ret_val = NULL;
    }
    else
    {
		if (rmcp_csn1_field_read_params_ptr->bits_left > 0)
			{
			/* Optional Selection Parameters
			 */
			rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
			rmcp_csn1_field_read_params_ptr->length = 1;

			if (rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
				{

				ret_val->opt_selection_pars.valid = TRUE;

				if (rmcp_csn1_field_read_params_ptr->bits_left > 14)
					{
					ret_val->opt_selection_pars.selection_pars.present = TRUE;

					rmcp_csn1_field_read_params_ptr->padding = 0x00;
					rmcp_csn1_field_read_params_ptr->length = 1;
					ret_val->opt_selection_pars.selection_pars.cbq =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

					rmcp_csn1_field_read_params_ptr->length = 6;
					ret_val->opt_selection_pars.selection_pars.
						cell_reselect_offset =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

					rmcp_csn1_field_read_params_ptr->length = 3;
					ret_val->opt_selection_pars.selection_pars.
						temporary_offset =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

					rmcp_csn1_field_read_params_ptr->length = 5;
					ret_val->opt_selection_pars.selection_pars.penalty_time =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);
					}
				else
					{
					rmcp_csn1_field_read_params_ptr->bits_left = 0;
					ret_val->opt_selection_pars.valid = FALSE;
					}
				}
			}

		if (rmcp_csn1_field_read_params_ptr->bits_left > 0)
			{
			/* Optional Power Offset
			 */
			rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
			rmcp_csn1_field_read_params_ptr->length = 1;

			if (rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
				{
				if (rmcp_csn1_field_read_params_ptr->bits_left > 1)
					{
					rmcp_bits_skip(rmcp_csn1_field_read_params_ptr, 2);
					}
				else
					{
					rmcp_csn1_field_read_params_ptr->bits_left = 0;
					}
				}
			}

		if (rmcp_csn1_field_read_params_ptr->bits_left > 0)
			{
			/* GPRS Indicator
			 */
			rmcp_csn1_field_read_params_ptr->padding = RR_SI_PADDING;
			rmcp_csn1_field_read_params_ptr->length = 1;

			if (rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr))
				{
				ret_val->gprs_pars.valid = TRUE;

				if (rmcp_csn1_field_read_params_ptr->bits_left > 3)
					{
					ret_val->gprs_pars.gprs_indicator.gprs_supported = TRUE;

					rmcp_csn1_field_read_params_ptr->padding = 0x00;
					rmcp_csn1_field_read_params_ptr->length = 3;
					ret_val->gprs_pars.gprs_indicator.ra_colour =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

					rmcp_csn1_field_read_params_ptr->length = 1;
					ret_val->gprs_pars.gprs_indicator.si13_position =
						rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);
					}
				else
					{
					rmcp_csn1_field_read_params_ptr->bits_left = 0;
					ret_val->gprs_pars.valid = FALSE;
					}
				}
			}
    }
	free( rmcp_csn1_field_read_params_ptr );
	rmcp_csn1_field_read_params_ptr = NULL;

	return ret_val;
}

/************************************************************************************************************/

void rr_si_decoded_si4_dealloc(RR_DECODED_SI4_STR* decoded_si4)
{
	assert(decoded_si4 != NULL);

	if (decoded_si4->rest_octets != NULL)
	{
		free(decoded_si4->rest_octets);
		decoded_si4->rest_octets = NULL;
	}
}

/************************************************************************************************************/

RR_DECODED_SI4_STR* rr_si_si4_decode(const tOCT_UINT8* byte_stream)
{
    RR_DECODED_SI4_STR* ret_val;
    RMCP_CSN1_FIELD_READ_PARAMS_STR* rmcp_csn1_field_read_params_ptr;
    
    ret_val = (RR_DECODED_SI4_STR *) malloc(sizeof(RR_DECODED_SI4_STR));
    assert(ret_val != NULL);

    rmcp_csn1_field_read_params_ptr = (RMCP_CSN1_FIELD_READ_PARAMS_STR *) malloc(sizeof(RMCP_CSN1_FIELD_READ_PARAMS_STR));
    assert(rmcp_csn1_field_read_params_ptr != NULL);

    tOCT_UINT8 error_status;
    tOCT_UINT8 i;
    tOCT_UINT8 temp_byte;

    assert(NULL != byte_stream );

    rmcp_csn1_field_read_params_ptr->decoding_position = (tOCT_UINT8*) byte_stream;
    rmcp_csn1_field_read_params_ptr->bit_index = 8;
    rmcp_csn1_field_read_params_ptr->bits_left = RR_SI4_DATA_LEN * 8;
    rmcp_csn1_field_read_params_ptr->padding = 0x00;

    memset(ret_val, 0x00, sizeof(RR_DECODED_SI4_STR));

    /* prepare for decoding error
     */
    if (( error_status = ( tOCT_UINT8 ) setjmp( rmcp_csn1_field_read_params_ptr->err_buf )) != 0 )
    {
        switch (error_status)
        {
            case RMCP_CSN1_ERROR_OUT_OF_BITS:
                break;
    
            default:
                break;
        }
        rr_si_decoded_si4_dealloc(ret_val);
        free(ret_val);
        ret_val = NULL;
    }
    else
    {
        /* Location Area Identification
         */
        rmcp_csn1_field_read_params_ptr->length = 8;
        ret_val->lai.mcc2_mcc1 = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->lai.mnc3_mcc3 = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->lai.mnc2_mnc1 = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->lai.lac[0] = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->lai.lac[1] = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        /* Cell Selection Parameters
         */
        rmcp_csn1_field_read_params_ptr->length = 3;
        ret_val->cell_selection_parameters.cell_reselect_hysteresis =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 5;
        ret_val->cell_selection_parameters.ms_txpwr_max_cch =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 1;
        ret_val->cell_selection_parameters.acs = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->cell_selection_parameters.neci = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 6;
        ret_val->cell_selection_parameters.rxlev_access_min =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        /* RACH Control Parameters
         */
        rmcp_csn1_field_read_params_ptr->length = 2;
        ret_val->rach_control_parameters.rach_ctrl_params.max_retrans =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 4;
        ret_val->rach_control_parameters.rach_ctrl_params.tx_integer =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 1;
        ret_val->rach_control_parameters.rach_ctrl_params.cell_bar_access = 
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->rach_control_parameters.rach_ctrl_params.re_disabled =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        rmcp_csn1_field_read_params_ptr->length = 8;
        ret_val->rach_control_parameters.access_control_class =
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr) << 8;

        ret_val->rach_control_parameters.access_control_class +=
            rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

        ret_val->rach_control_parameters.rach_ctrl_params.ec_disabled =
            ((tOCT_UINT8)(ret_val->rach_control_parameters.
            access_control_class >> 10)) & B0000_0001;

        /* CONFIDENTIAL
         * CBCH Channel Description
         * Assumption: IEI starts from byte border and is 8 bits long
         */
        if (RR_IEI_CELL_CHANNEL_DESCR == 
            *rmcp_csn1_field_read_params_ptr->decoding_position)
            {
            rmcp_bits_skip(rmcp_csn1_field_read_params_ptr, 8 );

            rmcp_csn1_field_read_params_ptr->length = 8;
            ret_val->cbch_pars.ch_descr.cbch_ch_parameter =
                rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

            ret_val->cbch_pars.ch_descr.hopping_on_parameter_1 =
                rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

            ret_val->cbch_pars.ch_descr.hopping_on_parameter_2 =
                rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

            /* Check the validity of channel type.
             */
            temp_byte = (ret_val->cbch_pars.ch_descr.cbch_ch_parameter &
                B1111_1000) >> 3;

            if (temp_byte != 0 && temp_byte < B0001_0000)
                {
                ret_val->cbch_pars.valid = TRUE;
                }
            else
                {
                ret_val->cbch_pars.valid = FALSE;
                }
            }

        /* CBCH Mobile Allocation
         * Assumption: IEI starts from byte border and is 8 bits long
         */
        if (RR_IEI_MOBILE_ALLOCATION == 
            *rmcp_csn1_field_read_params_ptr->decoding_position)
            {
            rmcp_bits_skip(rmcp_csn1_field_read_params_ptr, 8 );

            rmcp_csn1_field_read_params_ptr->length = 8;
            ret_val->cbch_pars.mobile_allocation.length =
                rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

            for (i = 0; i < ret_val->cbch_pars.mobile_allocation.length; i++)
                {
                temp_byte = 
                    rmcp_csn1_field_read(rmcp_csn1_field_read_params_ptr);

                if (i < CBCH_MOBILE_ALLOCATION_LENGTH)
                    {
                    ret_val->cbch_pars.mobile_allocation.mobile_allocation[i] =
                        temp_byte;
                    }
                }

            if (i > CBCH_MOBILE_ALLOCATION_LENGTH)
                {
                /* Too long CBCH Mobile Allocation!
                 */
                ret_val->cbch_pars.valid = FALSE;
                }
            }

        /* SI4 Rest Octets
         */
        ret_val->rest_octets = rr_si_si4_rest_octs_decode(
            rmcp_csn1_field_read_params_ptr->decoding_position, 
            rmcp_csn1_field_read_params_ptr->bits_left);
    }
    free( rmcp_csn1_field_read_params_ptr );
    rmcp_csn1_field_read_params_ptr = NULL;

    return ret_val;
}
/************************************************************************************************************/

tOCT_UINT8 rr_si_si4_handle(const tOCT_UINT8* si4_data , FILE * fp, cellParams *params)
{
	//T_LAI_BCD  lai_bcd;
    tOCT_INT16 rxlev_access_min_dbm;
    tOCT_INT8  resel_offset;
    sint8 rxlev_dbm;
	RR_DECODED_SI4_STR* decoded_si4_ptr = NULL;

	assert(NULL != si4_data);

	decoded_si4_ptr = rr_si_si4_decode(si4_data);
	logPrint(LOG_DEBUG,"rr_si_si4_handle si4Cell = %d , params->cellId = %d \n", si4Cell, params->cellId);

	if(si4Cell != params->cellId && decoded_si4_ptr != NULL)
	{
        fxL2gListenModeSystemInfoInd *ind = (fxL2gListenModeSystemInfoInd*)sndMsgBuf;
        combinedSIs *sendReady = (combinedSIs *)&sndMsgBuf[sizeof(fxL2gListenModeSystemInfoInd)];
        si4Cell = params->cellId;

        rxlev_access_min_dbm = decoded_si4_ptr->cell_selection_parameters.rxlev_access_min - 111;

        if( (sint8)params->rssi == 0 )
        {
            rxlev_dbm = -128;
        }
        else
        {
            rxlev_dbm = (sint8)params->rssi;
        }

        ind->c1 = calculateC1( params->band, rxlev_dbm, rxlev_access_min_dbm, decoded_si4_ptr->cell_selection_parameters.ms_txpwr_max_cch );

        ind->c2 = ind->c1;
        
        if((decoded_si4_ptr->rest_octets != NULL) && (decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.present))
        {
            resel_offset = decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.cell_reselect_offset * 2;
            if(decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.penalty_time == SPECIAL_PENALTY_TIME)
            {
                ind->c2 = ind->c2 - resel_offset;
            }
            else
            {
                ind->c2 = ind->c2 + resel_offset;
            }
        }
        ind->rxlevAccMin = decoded_si4_ptr->cell_selection_parameters.rxlev_access_min;
        ind->msTxpwrMaxCcch = decoded_si4_ptr->cell_selection_parameters.ms_txpwr_max_cch;
        ind->cro = decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.cell_reselect_offset;
        ind->tempOffset = decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.temporary_offset;
        ind->penaltyTime = decoded_si4_ptr->rest_octets->opt_selection_pars.selection_pars.penalty_time;

        sendReady->servingCellId = si4Cell;
        sendReady->siRcvd |= RR_SI4_MASK;
    }
    rr_si_decoded_si4_dealloc(decoded_si4_ptr);
    free(decoded_si4_ptr);
    decoded_si4_ptr = NULL;

	return TRUE;
}

/************************************************************************************************************/

void rr_si_servcell_bcch_si_handle(const char* si_ptr , FILE * fp , cellParams *params)
{
	RR_BYTE_BASED_SI_UNION_STR* sysinfo_union_ptr = NULL;
	RR_DECODED_SI_HDR_STR* hdr = NULL;

	if (si_ptr != NULL)
		{
		 //fprintf(fp , "Decoding BCCH header \n");
		 hdr = rr_si_bcch_header_decode(si_ptr);
		}

	if (NULL != hdr)
		{
		sysinfo_union_ptr = malloc(sizeof(RR_BYTE_BASED_SI_UNION_STR));
	    assert(sysinfo_union_ptr != NULL);

		(void) memcpy(sysinfo_union_ptr, si_ptr + hdr->l3_data_index,
			sizeof(RR_BYTE_BASED_SI_UNION_STR));
		switch (hdr->message_type)
        {
			case RR_SI1_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 1 is decoded correctly \n");
				rr_si_si1_handle(sysinfo_union_ptr->bcch_data, fp, params);
			}
				break;

			case RR_SI2_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 2 is decoded correctly \n");
				rr_si_si2_handle(sysinfo_union_ptr->bcch_data , fp , params);
			}
				break;

            case RR_SI2BIS_MSG_TYPE:
            {
				//fprintf(fp , "Header for System-Info 2 is decoded correctly \n");
				rr_si_si2bis_handle(sysinfo_union_ptr->bcch_data , fp , params);
			}
                break;

			case RR_SI2TER_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 2-ter is decoded correctly \n");
				rr_si_si2ter_handle(sysinfo_union_ptr->bcch_data , fp , params);
			}
				break;

			case RR_SI2QUATER_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 2-quater is decoded correctly \n");
#ifdef FEA_SI2QUATER_DECODE
				rr_si_si2quater_handle(sysinfo_union_ptr->bcch_data , fp , params);
#endif
			}
				break;

			case RR_SI3_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 3 is decoded correctly \n");
				rr_si_si3_handle(sysinfo_union_ptr,fp , params);
			}
				break;

			case RR_SI4_MSG_TYPE:
			{
				//fprintf(fp , "Header for System-Info 4 is decoded correctly \n");
				rr_si_si4_handle(sysinfo_union_ptr->bcch_data , fp, params);
			}
				break;

			default:
				//fprintf(fp , "Not able to decode this Block of Information \n");
				break;
        } /* end of switch */
		free(sysinfo_union_ptr);
		sysinfo_union_ptr = NULL;
	
		free(hdr);
		hdr = NULL;
		}
	return;
}

/************************************************************************************************************/


