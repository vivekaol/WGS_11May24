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
* File Name   : sys_info.c
 *
* Description : GSM system information messages
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#include "sysInfo.h"
#include "gsmData.h"
#include "l1InterfaceManager.h"
#include "lapdm.h"
#include "logManager.h"
#include "RRUplink_RR.h"
#include <arpa/inet.h>

tOCT_UINT8 tempbuffer[32];
tOCT_UINT8 storedLai[5] = {0};
extern const tOCT_UINT8 fill_frame[GSM_MACBLOCK_LEN];
extern gsm_trx * trx_g ;

extern tOCT_UINT8 maxPdtchChannel;

extern fxL2gBandType convertToFxlBandFromOct(tOCT_UINT32 band);
extern unsigned int getGsmBandFromARFCN(unsigned int gsmArfcn);
extern int arfcn_list_cmp(const void *arfcn_list_param_1, const void *arfcn_list_param_2);

void convert_to_bcd(tOCT_UINT8 *bcd, tOCT_UINT16 val)
{
    bcd[2] = val % 10;
    val = val / 10;
    bcd[1] = val % 10;
    val = val / 10;
    bcd[0] = val % 10;
    val = val / 10;
}

int power_of_two(int i)
{
	int powerOf2 = 1;

	do 
    {
        powerOf2 *= 2;
	} while (powerOf2 <= i);

	return powerOf2 / 2;
}

int mod(int data, int range)
{
	int res = data % range;
	while (res < 0)
		res += range;
	return res;
}

void generate_lai(struct loc_area_id *lai, gsm_network network, tOCT_UINT16 lac)
{    
    lai->digits[0] = network.mcc[0] | (network.mcc[1] << 4);
    lai->digits[1] = network.mcc[2];

    if (network.mnc_length == 3)
    {
        lai->digits[1] |= network.mnc[2] << 4;
        lai->digits[2]  = network.mnc[0] | (network.mnc[1] << 4);
    }
    else
    {
        lai->digits[1] |= 0xf << 4;
        lai->digits[2] = network.mnc[0] | (network.mnc[1] << 4);
    }

    lai->lac = lac;
}

void set_ccch_config(struct ctrl_chan_desc *chan_desc, gsm_trx *trx)
{
    // Set ccch config by looking at ts config
    int i, n;
    for (n=0, i=0; i<8; i++)
    {
    n += trx->ts[i].lchan == FCCH_SCH_BCCH_CCCH ? 1 : 0;
    }

    switch (n)
    {
    case 0:
        chan_desc->ccch_conf = CCCH_CONF_1_C;
        // Limit reserved block to 2 on combined channel
        if (chan_desc->bs_ag_blks_res > 2)
                chan_desc->bs_ag_blks_res = 2;
        break;
    case 1:
        chan_desc->ccch_conf = CCCH_CONF_1_NC;
        break;
    case 2:
        chan_desc->ccch_conf = CCCH_CONF_2_NC;
        break;
    case 3:
        chan_desc->ccch_conf = CCCH_CONF_3_NC;
        break;
    case 4:
        chan_desc->ccch_conf = CCCH_CONF_4_NC;
        break;
    default:
		break;
    }
}

// 3GPP TS 44.018
// refer section 10.5.2.11
void generate_chan_desc(struct ctrl_chan_desc *chan_desc, gsm_trx *trx)
{
    chan_desc->bs_ag_blks_res = trx->bts.blockReservedForAgch; // reserved AGCH blocks
    chan_desc->att = 1; // attachment required
    chan_desc->t3212 = trx->bts.t3212;
    chan_desc->bs_pa_mfrms = trx->bts.pagingPeriodicity - 2; // paging frames
    chan_desc->mscr = 0;
    chan_desc->si22ind = 0;
    chan_desc->cbq3 = 0;
    chan_desc->spare = 0;

    set_ccch_config(chan_desc, trx);
}

// determine power control level for given dBm value, as indicated
// by the tables in chapter 4.1.1 of GSM TS 05.05
int ms_power_control(int band, unsigned int dbm)
{
    switch (band)
    {
    case GSM_450:
    case E_GSM:
    case R_GSM:
    case GSM_900:
    case GSM_850:
        if (dbm >= 39)
            return 0;
        else if (dbm < 5)
            return 19;
        else
        {
            // we are guaranteed to have (5 <= dbm < 39)
            return 2 + ((39 - dbm) / 2);
        }
        break;
    case DCS_1800:
        if (dbm >= 36)
            return 29;
        else if (dbm >= 34)
            return 30;
        else if (dbm >= 32)
            return 31;
        else if (dbm == 31)
            return 0;
        else
        {
            // we are guaranteed to have (0 <= dbm < 31)
            return (30 - dbm) / 2;
        }
        break;
    case PCS_1900:
        if (dbm >= 33)
            return 30;
        else if (dbm >= 32)
            return 31;
        else if (dbm == 31)
            return 0;
        else
        {
            // we are guaranteed to have (0 <= dbm < 31)
            return (30 - dbm) / 2;
        }
        break;
    }
    return -EINVAL;
}

/* 10.5.2.13.2: Bit map 0 format */
int encode_bit_map_0(tOCT_UINT8 *bcch_frequency_list, tOCT_UINT16 arfcn)
{
        tOCT_UINT8 byte, bit;

        if (arfcn > 124 || arfcn < 1)
    {
                logPrint(LOG_ERR, "Invalid ARFCN(%d) for Bitmap 0 \n", arfcn);
                return -1;
        }

        /* bitmask is from 1-124(not 0-123) */
        arfcn--;

        byte = arfcn / 8;
        bit  = arfcn % 8;

        bcch_frequency_list[RR_NEIGHBOUR_CELLS_DESCR_LEN-1-byte] |= (1 << bit);

        return 0;
}

int encode_variable_bitmap(tOCT_UINT8 *bcch_frequency_list, tOCT_UINT16 origArfcn, tOCT_UINT8 nbr_of_arfcns, tOCT_UINT32* arfcns)
{
    int i;
    unsigned int byte, bit, bitNum;

    /* Variable bitmap format */
    bcch_frequency_list[0] = 0x8E;

    bcch_frequency_list[0] |= (origArfcn >> 9) & 1;
    bcch_frequency_list[1]  = (origArfcn >> 1);
    bcch_frequency_list[2]  = (origArfcn & 1) << 7;

    for (i = 0; i < nbr_of_arfcns; i++)
    {
        if (convertToFxlBandFromOct(getGsmBandFromARFCN(arfcns[i])) == trx_g->bts.band)
        {
            if (arfcns[i] == origArfcn) /* Already included */
              continue;

            if (((arfcns[i] - origArfcn) & 1023) > 111)
            {
                logPrint(LOG_ERR, "ARFCN(%u) > OrigArfcn(%u) + 111\n", arfcns[i], origArfcn);
                return -1;
            }

            bitNum = (arfcns[i] - origArfcn) & 1023;
            byte = bitNum / 8;
            bit = bitNum % 8;

            bcch_frequency_list[2 + byte] |= 1 << (7 - bit);
        }
    }

    return 0;
}

int encode_range_find_index(const int range, const int *arfcnList, const int size)
{
	int i, j, n;
	const int rangeDelta = (range - 1) / 2;

	for (i = 0; i < size; ++i) 
    {
		n = 0;
		for (j = 0; j < size; ++j) 
        {
			if (mod(arfcnList[j] - arfcnList[i], range) <= rangeDelta)
            {         
			    n += 1;
            }
		}

		if (n - 1 == (size - 1) / 2)
          return i;
	}

	return -1;
}

int encode_range_arfcns(const int range, const int *arfcnList, int size, int *out, const int index)
{
    int i, pivot;    
    int leftSize, rightSize, leftOrigin, rightOrigin;
    int leftArfcns[size / 2];
    int rightArfcns[size / 2];

    if (size == 0)
      return 0;

    if (size == 1) 
    {
        out[index] = 1 + arfcnList[0];
        return 0;
    }

    pivot = encode_range_find_index(range, arfcnList, size);

    out[index] = 1 + arfcnList[pivot];

    leftOrigin  = mod(arfcnList[pivot] + ((range - 1) / 2) + 1, range);
    rightOrigin = mod(arfcnList[pivot] + 1, range);
    for (i = 0, leftSize = 0, rightSize = 0; i < size; ++i)
    {
        if (mod(arfcnList[i] - leftOrigin, range) < range / 2)
        {
            leftArfcns[leftSize++] = mod(arfcnList[i] - leftOrigin, range);
        }
        if (mod(arfcnList[i] - rightOrigin, range) < range / 2)
        {
            rightArfcns[rightSize++] = mod(arfcnList[i] - rightOrigin, range);
        }
    }

    /* recurse */
    encode_range_arfcns(range / 2, leftArfcns, leftSize, out, index + power_of_two(index + 1));
    encode_range_arfcns((range -1 ) / 2, rightArfcns, rightSize, out, index + (2 * power_of_two(index + 1)));
    return 0;
}

void writeWn(tOCT_UINT8 *chan_list, int bitOffset, int *w, int sizeOfW, int lengthOfW1)
{
    int octetOffset = 0;
    int lengthOfWk = lengthOfW1;
    int k, level = 0, levelLeft = 1;

    for (k = 1; k <= sizeOfW; k++) 
    {
        int wkLeft = lengthOfWk;
        //logPrint(LOG_DEBUG, "k=%d, Wk-Length=%d, Offset=%d:%d, level=%d, level-left=%d\n", k, lengthOfWk, octetOffset, bitOffset, level, levelLeft);

        while (wkLeft > 0) 
        {
            int curBits = 8 - bitOffset;
            int curMask;
            int wkSlice;

            if (curBits > wkLeft)
                curBits = wkLeft;

            curMask = ((1 << curBits) - 1);

            //logPrint(LOG_DEBUG, " wk_left=%d, cur_bits=%d, offs=%d:%d\n", wkLeft, curBits, octetOffset, bitOffset);

            wkLeft -= curBits;
            bitOffset += curBits;

            wkSlice = (w[k-1] >> wkLeft) & curMask;

            //logPrint(LOG_DEBUG, " Wk=%02x, Slice=%02x/%02x, cl=%02x\n", w[k-1], wkSlice, curMask, wkSlice << (8 - bitOffset));

            chan_list[octetOffset] &= ~(curMask << (8 - bitOffset));
            chan_list[octetOffset] |= wkSlice << (8 - bitOffset);

            /* adjust output */
            if (bitOffset == 8) 
            {
                bitOffset = 0;
                octetOffset += 1;
            }
        }

        levelLeft -= 1;
        if (!levelLeft) 
        {
            level += 1;
            levelLeft = 1 << level;
            lengthOfWk -= 1;
        }
    }
}

int encode_range_list(tOCT_UINT8 *bcch_frequency_list, tOCT_UINT8 nbr_of_arfcns, tOCT_UINT32* arfcns)
{
    int arfcnList[MAX_RANGE_ENCODING_ARFCNS];
    int w[MAX_RANGE_ENCODING_ARFCNS];
    int f0Added = 0;
    int arfcnCount = 0;
    int i, j, max = 0, ret, range = ORIG_RANGE_INVALID, f0;

    for (i = 0; i < nbr_of_arfcns; i++) 
    {
        if (arfcnCount > MAX_RANGE_ENCODING_ARFCNS)
        {
            logPrint(LOG_ERR,  "encode_range_list(): arfcnCount > MAX_RANGE_ENCODING_ARFCNS ");            
            return -1;
        }
        arfcnList[arfcnCount++] = arfcns[i];
    }

     /* can the ARFCN list be encoded ? */
     /* arfcns[0] = f0, easier that way  */
     max = arfcnList[arfcnCount - 1] - arfcnList[0];
     f0 = arfcnList[0];
     
     if (max < 128 && arfcnCount <= 29)
         range = ORIG_RANGE_128;
     if (max < 256 && arfcnCount <= 22)
         range = ORIG_RANGE_256;
     if (max < 512 && arfcnCount <= 18)
         range = ORIG_RANGE_512;
     if (max < 1024 && arfcnCount <= 17)
     {
         f0 = 0;
         range = ORIG_RANGE_1024;
     }

     if(range == ORIG_RANGE_INVALID)
     {         
         logPrint(LOG_ERR,  "encode_range_list(): range == ORIG_RANGE_INVALID, max = %d, arfcnCount = %d ", max, arfcnCount);
         return -1;
     }

    /* Apply encoding algorithm on the selected range, 3GPP TS 44.018 Appendix J.4 */
    for (i = 0, j = 0; i < arfcnCount; ++i) 
    {
		if (arfcnList[i] == f0) 
        {
			f0Added = 1;
			continue;
		}

		arfcnList[j++] = (arfcnList[i] - (f0 + 1)) % 1024;
	}
    arfcnCount = j;

    memset(w, 0, sizeof(w));
    ret = encode_range_arfcns(range, arfcnList, arfcnCount, w, 0);
    if (ret != 0)
      return -1;

    /* Select the range and the amount of bits needed */
    switch (range) 
    {
        case ORIG_RANGE_128:
        {
            bcch_frequency_list[0] = 0x8C;
	        bcch_frequency_list[0] |= (f0 >> 9) & 1;
        	bcch_frequency_list[1] = (f0 >> 1);
        	bcch_frequency_list[2] = (f0 & 1) << 7;

        	writeWn(&bcch_frequency_list[2], 1, w, 28, 7);
        	return 0;
        }
            break;
        case ORIG_RANGE_256:
        {
            bcch_frequency_list[0] = 0x8A;
	        bcch_frequency_list[0] |= (f0 >> 9) & 1;
        	bcch_frequency_list[1] = (f0 >> 1);
        	bcch_frequency_list[2] = (f0 & 1) << 7;

        	writeWn(&bcch_frequency_list[2], 1, w, 21, 8);
        	return 0;
        }
            break;
        case ORIG_RANGE_512:
        {
        	bcch_frequency_list[0] = 0x88;
	        bcch_frequency_list[0] |= (f0 >> 9) & 1;
        	bcch_frequency_list[1] = (f0 >> 1);
        	bcch_frequency_list[2] = (f0 & 1) << 7;

        	writeWn(&bcch_frequency_list[2], 1, w, 17, 9);
        	return 0;
        }
            break;
        case ORIG_RANGE_1024:
        {
            bcch_frequency_list[0] = 0x80 | (f0Added << 2);
            
            writeWn(&bcch_frequency_list[0], 6, w, 16, 10);
            return 0;
        }
            break;
        default:
        {
            return -1;
        }
            break;
    }
}

int generate_bcch_frequency_list(tOCT_UINT8* bcch_frequency_list, tOCT_UINT8 nbr_of_arfcns, tOCT_UINT32* arfcns)
{
    int i, ret, origArfcn = -1, arfcnMax = -1, numArfcnsAdded = 0;

    memset(bcch_frequency_list, 0, 16);
    
    /* Sort the List Array */
    qsort( (void *) arfcns, nbr_of_arfcns, sizeof( T_CARRIER_NUMBER ), arfcn_list_cmp );

    if(  ((trx_g->bts.band == GSM_900) 
       && (trx_g->arfcn >= 1 
       &&  trx_g->arfcn <= 124))                /* P-GSM */
       ||((arfcns[0] != 0)
       && (arfcns[nbr_of_arfcns - 1] >= 1 
       &&  arfcns[nbr_of_arfcns - 1] <= 124)))  /* Min ARFCN != 0 && Max ARFCN in the list <= 124 */
    {
        bcch_frequency_list[0] = 0;

        for (i = 0; i < nbr_of_arfcns; i++)
        {
            if (arfcns[i] >= 1 && arfcns[i] <= 124)
            {
                ret = encode_bit_map_0(bcch_frequency_list, arfcns[i]);
                if (ret < 0)
                return ret;
            }
        }
        return 0;
    }

    for (i = 0; i < nbr_of_arfcns; i++)
    {
        /* 955->1023 < 0->885 */

        if (origArfcn < 0)
            origArfcn = arfcns[i];
        if (arfcns[i] >= 955 && origArfcn < 955)
            origArfcn = arfcns[i];
        if (arfcns[i] >= 955 && origArfcn >= 955 && arfcns[i] < origArfcn)
            origArfcn = arfcns[i];
        if (arfcns[i] < 955 && origArfcn < 955 && arfcns[i] < origArfcn)
            origArfcn = arfcns[i];

        if (arfcnMax < 0)
            arfcnMax = arfcns[i];
        if (arfcns[i] < 955 && arfcnMax >= 955)
            arfcnMax = arfcns[i];
        if (arfcns[i] >= 955 && arfcnMax >= 955 && arfcns[i] > arfcnMax)
            arfcnMax = arfcns[i];
        if (arfcns[i] < 955 && arfcnMax < 955 && arfcns[i] > arfcnMax)
            arfcnMax = arfcns[i];
    }

    if (arfcnMax == -1) 
    {
		/* List is empty, use bitmap-0 format */
		bcch_frequency_list[0] = 0;
		return 0;
	}

	if (((arfcnMax - origArfcn) & 1023) <= 111)
    {   
        return encode_variable_bitmap(bcch_frequency_list, origArfcn, nbr_of_arfcns, arfcns);
    }
    
	/* Attempt to do the range encoding */
	ret = encode_range_list(bcch_frequency_list, nbr_of_arfcns, arfcns);
	if (ret == 0)
	  return 0;

	logPrint(LOG_ERR, "Could not generate ARFCN list: origArfcn =%u, arfcnMax =%u, numArfcnsAdded =%d", origArfcn, arfcnMax, numArfcnsAdded);
	return -1;

}

int generate_si1(tOCT_UINT8 *output, gsm_trx * trx)
{
    int i, ret;
    tOCT_UINT16 freqNum = trx->arfcn;
    tOCT_UINT8 arfcn_byte[4];
    arfcn_byte[0] = 0x8A | (tOCT_UINT8)(((freqNum) & 0x0200) >> 9);
    arfcn_byte[1] = (tOCT_UINT8)((freqNum & 0x01FE) >> 1);
    arfcn_byte[2] = ((tOCT_UINT8)((freqNum & 0x0001) << 7)) & 0x80;

    struct sys_info_type_1 *si1 = (struct sys_info_type_1 *) output;

    memset(si1, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);

    si1->header.l2_p_len = (21 << 2) | 1;
    si1->header.rr_proto_disc = PROTO_DISC_RR;
    si1->header.skip_ind = 0;
    si1->header.sys_info = MT_RR_SYSINFO_TYPE_1;

    if(trx_g->bts.neigh_ca_list.nbr_of_arfcns > 0)
    {
        ret = generate_bcch_frequency_list(si1->cell_channel_desc,
                                           trx->bts.neigh_ca_list.nbr_of_arfcns,
                                           trx->bts.neigh_ca_list.arfcns);
        if (ret < 0)
            return ret;
    }
    else
    {
        si1->cell_channel_desc[0] = arfcn_byte[0];
        si1->cell_channel_desc[1] = arfcn_byte[1];
        si1->cell_channel_desc[2] = arfcn_byte[2];

        for(i=3; i<16; i++)
        {
            si1->cell_channel_desc[i] = 0;
        }
    }

    si1->rach_control.re        = trx->bts.rach_ctrl_par.re;
    si1->rach_control.cell_bar  = trx->bts.rach_ctrl_par.cell_bar;
    si1->rach_control.tx_int    = trx->bts.rach_ctrl_par.tx_int;
    si1->rach_control.max_trans = trx->bts.rach_ctrl_par.max_trans;
    
    si1->rach_control.t2        = trx->bts.access_class_list >> 8; 
    si1->rach_control.t3        = trx->bts.access_class_list & 0xFF;

#ifdef FEA_EMER
    if((si1->rach_control.t2 & 0x04) == 0x04)
    {
        si1->rach_control.t2 = si1->rach_control.t2 & 0xFB; //  emergency calls
    }
#else
    si1->rach_control.t2 = si1->rach_control.t2 | 0x04;; //  emergency calls
#endif

    return sizeof(*si1);
}

int generate_si2(tOCT_UINT8 *output, gsm_bts *bts)
{
    int i, ret;
    struct sys_info_type_2 *si2 = (struct sys_info_type_2 *) output;

    memset(si2, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);

    si2->header.l2_p_len = (22 << 2) | 1;
    si2->header.rr_proto_disc = PROTO_DISC_RR;
    si2->header.skip_ind = 0;
    si2->header.sys_info = MT_RR_SYSINFO_TYPE_2;

    if(bts->neigh_list.nbr_of_arfcns > 0)
    {
        ret = generate_bcch_frequency_list(si2->bcch_frequency_list, 
                                           bts->neigh_list.nbr_of_arfcns,
                                           bts->neigh_list.arfcns);
        if (ret < 0)
		  return ret;
    }
    else
    {
        for(i=0; i<16; i++)
        {
            si2->bcch_frequency_list[i] = 0;
        }
    }

    si2->ncc_permitted = 0xff;

    si2->rach_control.re        = bts->rach_ctrl_par.re;
    si2->rach_control.cell_bar  = bts->rach_ctrl_par.cell_bar;
    si2->rach_control.tx_int    = bts->rach_ctrl_par.tx_int;
    si2->rach_control.max_trans = bts->rach_ctrl_par.max_trans;
        
    si2->rach_control.t2 = bts->access_class_list >> 8;
    si2->rach_control.t3 = bts->access_class_list & 0xFF;

#ifdef FEA_EMER
    if((si2->rach_control.t2 & 0x04) == 0x04)
    {
        si2->rach_control.t2 = si2->rach_control.t2 & 0xFB; //  emergency calls
    }
#else
    si2->rach_control.t2 = si2->rach_control.t2 | 0x04;; //  emergency calls
#endif

    return sizeof(*si2);
}


int generate_si3(tOCT_UINT8 *output, gsm_bts *bts)
{
    struct sys_info_type_3 *si3 = (struct sys_info_type_3 *) tempbuffer;

    memset(si3, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);
    memset(output, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);

    si3->header.l2_p_len = (22 << 2) | 1;
    si3->header.rr_proto_disc = PROTO_DISC_RR;
    si3->header.skip_ind = 0;
    si3->header.sys_info = MT_RR_SYSINFO_TYPE_3;
    memcpy(output,&(si3->header),sizeof(struct sys_info_header));
    output = output + sizeof(struct sys_info_header);

    si3->cell_identity = htons(bts->cell_identity);
    memcpy(output,&(si3->cell_identity),sizeof(tOCT_UINT16));
    output = output + sizeof(tOCT_UINT16);

    generate_lai(&si3->lai, bts->network, htons(bts->location_area_code));

    memcpy( &(storedLai[0]), &si3->lai.digits[0], 3);

    storedLai[3] = bts->location_area_code >> 8;
    storedLai[4] = bts->location_area_code & 0xFF;

    memcpy(output,&(si3->lai.digits[0]),3);
    output = output + 3;
    memcpy(output,&(si3->lai.lac),sizeof(tOCT_UINT16));
    output = output + sizeof(tOCT_UINT16);

    generate_chan_desc(&si3->control_channel_desc, trx_g);
    memcpy(output,&(si3->control_channel_desc),sizeof(struct ctrl_chan_desc));
    output = output + sizeof(struct ctrl_chan_desc);

    si3->cell_options.radio_link_timeout = bts->radio_link_timeout;
    si3->cell_options.dtx = 2;
    si3->cell_options.pwrc = 0;
    si3->cell_options.spare = 0;
    memcpy(output,&(si3->cell_options),sizeof(struct cell_options));
    output = output + sizeof(struct cell_options);

    si3->cell_sel_par.rxlev_acc_min = bts->cell_sel_par.rxlev_acc_min;
    si3->cell_sel_par.cell_resel_hyst = bts->cell_sel_par.cell_resel_hyst;
    si3->cell_sel_par.neci = bts->cell_sel_par.neci;
    si3->cell_sel_par.acs = bts->cell_sel_par.acs;
    si3->cell_sel_par.ms_txpwr_max_ccch = bts->cell_sel_par.ms_txpwr_max_ccch;
    memcpy(output,&(si3->cell_sel_par),sizeof(struct cell_select_par));
    output = output + sizeof(struct cell_select_par);

    si3->rach_control.re        = bts->rach_ctrl_par.re;
    si3->rach_control.cell_bar  = bts->rach_ctrl_par.cell_bar;
    si3->rach_control.tx_int    = bts->rach_ctrl_par.tx_int;
    si3->rach_control.max_trans = bts->rach_ctrl_par.max_trans;
    
    si3->rach_control.t2 = bts->access_class_list >> 8;
    si3->rach_control.t3 = bts->access_class_list & 0xFF;

#ifdef FEA_EMER
    if((si3->rach_control.t2 & 0x04) == 0x04)
    {
        si3->rach_control.t2 = si3->rach_control.t2 & 0xFB; //  emergency calls
    }
#else
    si3->rach_control.t2 = si3->rach_control.t2 | 0x04;; //  emergency calls
#endif

    memcpy(output,&si3->rach_control,sizeof(struct rach_ctrl));
    output = output + sizeof(struct rach_ctrl);

    /* Rest Octets */
    /* Optional Selection Parameter Present(1 bit), CBQ(1 bit), CELL_RESELECT_OFFSET(6 bits) */
    si3->rest_octets[0] = (tOCT_UINT8)((bts->opt_cell_sel_par.parameter_present << 7) | (bts->opt_cell_sel_par.cell_bar_qualify<< 6) | (bts->opt_cell_sel_par.cell_reselect_offset)); 

    /* TEMPORARY_OFFSET(3 bits), PENALTY_TIME(5 bits) */
    si3->rest_octets[1] = (tOCT_UINT8)((bts->opt_cell_sel_par.temp_offset<< 5) | (bts->opt_cell_sel_par.penalty_time));

#ifdef FEA_2G_INTER_RAT_MEAS
    si3->rest_octets[2] = (0 << 7) |    /* Optional Power Offset Absent */
                          (0 << 6) |    /* SI2ter Indicator Absent */
                          (1 << 5) |    /* Early Classmark Send Ctrl Absent */
                          (0 << 4) |    /* Scheduling Absent */
                          (1 << 3) |    /* GPRS Indicator Absent */
                          (0 << 2) |    /* 3G Early Classmark Sending Restriction */
                          (0 << 1) |    /* SI2quater Indicator Present */
                          (0 << 0);     /* SI2quater Position Sent on BCCH Norm */

    si3->rest_octets[3] = (1 << 7) |    /* SI13alt Position Sent on BCCH Ext */
                          (0 << 6) |    /* System Information 21 Indicator Absent */
                          (0 << 5) |    /* 6 bits: spare */
                          (0 << 4) | 
                          (0 << 3) | 
                          (0 << 2) | 
                          (0 << 1) | 
                          (0 << 0);
#else
    si3->rest_octets[2] = (0 << 7) |    /* Optional Power Offset Absent */
                          (0 << 6) |    /* SI2ter Indicator Absent */
                          (1 << 5) |    /* Early Classmark Send Ctrl Absent */
                          (0 << 4) |    /* Scheduling Absent */
                          (1 << 3) |    /* GPRS Indicator Absent */
                          (0 << 2) |    /* 3G Early Classmark Sending Restriction */
                          (1 << 1) |    /* SI2quater Indicator Absent*/
                          (1 << 0);     /* SI13alt Position Sent on BCCH Ext */
    
    si3->rest_octets[3] = (0 << 7) |    /* System Information 21 Indicator Absent */
                          (0 << 6) |    /* 7 bits: spare */
                          (0 << 5) | 
                          (0 << 4) | 
                          (0 << 3) | 
                          (0 << 2) | 
                          (0 << 1) | 
                          (0 << 0);
#endif /* FEA_2G_INTER_RAT_MEAS */

#ifdef FEA_GPRS
    if(maxPdtchChannel)
    {
        si3->rest_octets[2] = (0 << 7) |    /* Optional Power Offset Absent */
                              (0 << 6) |    /* SI2ter Indicator Absent */
                              (1 << 5) |    /* Early Classmark Send Ctrl Absent */
                              (0 << 4) |    /* Scheduling Absent */
                              (0 << 3) |    /* GPRS Indicator Present */
                              (0 << 2) |    /* 3 bits: RA_COLOUR = 0 */
                              (0 << 1) |
                              (0 << 0); 
#ifndef FEA_2G_INTER_RAT_MEAS
        si3->rest_octets[3] = (0 << 7) |    /* SI13 Position, sent on BCCH Norm */
                              (0 << 6) |    /* 3G Early Classmark Sending Restriction */
                              (1 << 5) |    /* SI2quater Indicator Absent*/
                              (1 << 4) |    /* SI13alt Position Sent on BCCH Ext */
                              (1 << 3) |    /* System Information 21 Indicator Absent */
                              (0 << 2) |    /* 3 bits: spare */
                              (0 << 1) | 
                              (0 << 0);
#else
        si3->rest_octets[3] = (0 << 7) |    /* SI13 Position, sent on BCCH Norm */
                              (0 << 6) |    /* 3G Early Classmark Sending Restriction */
                              (0 << 5) |    /* SI2quater Indicator Present */
                              (0 << 4) |    /* SI2quater Position Sent on BCCH Norm */
                              (1 << 3) |    /* SI13alt Position Sent on BCCH Ext */
                              (0 << 2) |    /* System Information 21 Indicator Absent */
                              (0 << 1) |    /* 2 bits: spare */
                              (0 << 0);
#endif
    }
#endif

    memcpy(output,&(si3->rest_octets[0]),4);
    output = output + 4;

    return sizeof(*si3);
}


int generate_si4(tOCT_UINT8 *output, gsm_bts *bts)
{
    struct sys_info_type_4 *si4 = (struct sys_info_type_4 *) tempbuffer;

    // length of all IEs present except SI4 rest octets and l2_p_len
    int l2_plen = sizeof(*si4) - 1;

    memset(si4, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);
    memset(output, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);

    si4->header.l2_p_len = (l2_plen << 2) | 1;
    si4->header.rr_proto_disc = PROTO_DISC_RR;
    si4->header.skip_ind = 0;
    si4->header.sys_info = MT_RR_SYSINFO_TYPE_4;
    memcpy(output,&(si4->header),sizeof(struct sys_info_header));
    output = output + sizeof(struct sys_info_header);

    generate_lai(&si4->lai, bts->network, htons(bts->location_area_code));
    memcpy(output,&(si4->lai.digits[0]),3);
    output = output + 3;
    memcpy(output,&(si4->lai.lac),sizeof(tOCT_UINT16));
    output = output + sizeof(tOCT_UINT16);

    si4->cell_sel_par.rxlev_acc_min = bts->cell_sel_par.rxlev_acc_min;
    si4->cell_sel_par.cell_resel_hyst = bts->cell_sel_par.cell_resel_hyst;
    si4->cell_sel_par.neci = bts->cell_sel_par.neci;
    si4->cell_sel_par.acs = bts->cell_sel_par.acs;
    si4->cell_sel_par.ms_txpwr_max_ccch = bts->cell_sel_par.ms_txpwr_max_ccch;
    memcpy(output,&(si4->cell_sel_par),sizeof(struct cell_select_par));
    output = output + sizeof(struct cell_select_par);

    si4->rach_control.re        = bts->rach_ctrl_par.re;
    si4->rach_control.cell_bar  = bts->rach_ctrl_par.cell_bar;
    si4->rach_control.tx_int    = bts->rach_ctrl_par.tx_int;
    si4->rach_control.max_trans = bts->rach_ctrl_par.max_trans;
    
    si4->rach_control.t2 = bts->access_class_list >> 8;
    si4->rach_control.t3 = bts->access_class_list & 0xFF;

#ifdef FEA_EMER
    if((si4->rach_control.t2 & 0x04) == 0x04)
    {
        si4->rach_control.t2 = si4->rach_control.t2 & 0xFB; //  emergency calls
    }
#else
    si4->rach_control.t2 = si4->rach_control.t2 | 0x04;; //  emergency calls
#endif


    memcpy(output,&si4->rach_control,sizeof(struct rach_ctrl));
    output = output + sizeof(struct rach_ctrl);

    // Optional: CBCH Channel Description + CBCH Mobile Allocation

    // Rest Octets:

    //Optional Selection Parameter Present(1 bit), CBQ(1 bit), CELL_RESELECT_OFFSET(6 bits)
    si4->rest_octets[0] = (tOCT_UINT8)((bts->opt_cell_sel_par.parameter_present << 7) | (bts->opt_cell_sel_par.cell_bar_qualify<< 6) | (bts->opt_cell_sel_par.cell_reselect_offset)); 

    //TEMPORARY_OFFSET(3 bits), PENALTY_TIME(5 bits)
    si4->rest_octets[1] = (tOCT_UINT8)((bts->opt_cell_sel_par.temp_offset<< 5) | (bts->opt_cell_sel_par.penalty_time));

    memcpy(output,&(si4->rest_octets[0]),2);
    output = output + 2;

    return sizeof(*si4);
}


#ifdef FEA_GPRS
int generate_si13(tOCT_UINT8 *output, gsm_bts *bts)
{
    struct sys_info_type_13 *si13 = (struct sys_info_type_13 *) tempbuffer;

    memset(si13, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);
    memset(output, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);
    tOCT_UINT8 tmpBuf[20] = {0x90, 0x00, 0x58, 0x62, 0x6F, 0xC9, 0xE0, 0x84, 0x10, 0xAB, 
                             0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B};
    int l2_plen = sizeof(*si13) - 1;
    si13->header.l2_p_len = (l2_plen << 2) | 1;
    si13->header.rr_proto_disc = PROTO_DISC_RR;
    si13->header.skip_ind = 0;
    si13->header.sys_info = MT_RR_SYSINFO_TYPE_13;
    memcpy(output,&(si13->header),sizeof(struct sys_info_header));
    output = output + sizeof(struct sys_info_header);

    memcpy(&(si13->rest_octets), &tmpBuf, sizeof(tmpBuf));
    memcpy(output,&(si13->rest_octets),20*(sizeof(tOCT_UINT8)));
    output = output + 20*(sizeof(tOCT_UINT8));

    return sizeof(*si13);
}
#endif

#ifdef FEA_2G_INTER_RAT_MEAS

int generate_si2q_rest_octets(tOCT_UINT8 *si2q_rest_octets, tOCT_UINT8 instance, tOCT_UINT8 fill3gInfo, tOCT_UINT8 umtsInstance, tOCT_UINT8 lteInstance)
{
    int  Len, i;
    char Buffer [128];
    
    memset(Buffer, GSM_MACBLOCK_PADDING, 128);

    c_SI2quaterRestOctets si2qRestOctets;
    INIT_c_SI2quaterRestOctets(&si2qRestOctets);

    si2qRestOctets.SI2quater_INDEX  = instance;
    si2qRestOctets.SI2quater_COUNT  = trx_g->bts.noOfValidSi2qInstances - 1;

    if(si2qRestOctets.SI2quater_INDEX == 0)
    {
    
        c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description* priorityAndEutranParams = NULL;
        c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description* eutranParamsDescr = NULL;

        /* Fill the Serving Priority and Neighbor Measurement Parameters in Instance 0 */
        si2qRestOctets.BA_IND = 0;
        si2qRestOctets.p3G_BA_IND = 0;
        si2qRestOctets.MP_CHANGE_MARK = 1;

        SETPRESENT_c_SI2quaterRestOctets_p3G_Measurement_Parameters_Description(&(si2qRestOctets), ED_TRUE);
        si2qRestOctets.p3G_Measurement_Parameters_Description->Qsearch_I         = trx_g->bts.interRatInfo.umtsMeasParams.qSearchI;
        si2qRestOctets.p3G_Measurement_Parameters_Description->Qsearch_C_Initial = trx_g->bts.interRatInfo.umtsMeasParams.qSearchCInit;

        SETPRESENT_c_SI2quaterRestOctets_p3G_Measurement_Parameters_Description_FDD_REP_QUANT(si2qRestOctets.p3G_Measurement_Parameters_Description, ED_TRUE);
        si2qRestOctets.p3G_Measurement_Parameters_Description->FDD_REP_QUANT = 0; /* RSCP */
        SETPRESENT_c_SI2quaterRestOctets_p3G_Measurement_Parameters_Description_FDD_MULTIRAT_REPORTING(si2qRestOctets.p3G_Measurement_Parameters_Description, ED_TRUE);
        si2qRestOctets.p3G_Measurement_Parameters_Description->FDD_MULTIRAT_REPORTING = 3;
            
        if(trx_g->bts.interRatInfo.umtsMeasParams.fddParamsPresent)
        {
            SETPRESENT_c_SI2quaterRestOctets_p3G_Measurement_Parameters_Description_FDD_Qoffset(si2qRestOctets.p3G_Measurement_Parameters_Description, ED_TRUE);
            si2qRestOctets.p3G_Measurement_Parameters_Description->FDD_Qoffset = trx_g->bts.interRatInfo.umtsMeasParams.fddParams.fddQoffset;
            si2qRestOctets.p3G_Measurement_Parameters_Description->FDD_MULTIRAT_REPORTING = trx_g->bts.interRatInfo.umtsMeasParams.fddParams.fddMultiratReporting;
            SETPRESENT_c_SI2quaterRestOctets_p3G_Measurement_Parameters_Description_FDD_Qmin(si2qRestOctets.p3G_Measurement_Parameters_Description, ED_TRUE);
            si2qRestOctets.p3G_Measurement_Parameters_Description->FDD_Qmin = trx_g->bts.interRatInfo.umtsMeasParams.fddParams.fddQmin;
        }

        SETPRESENT_c_SI2quaterRestOctets__3G_CCN_ACTIVE(&(si2qRestOctets), ED_TRUE);
        si2qRestOctets._3G_CCN_ACTIVE = 0;
        SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description(&(si2qRestOctets), ED_TRUE);
        priorityAndEutranParams = si2qRestOctets.Priority_and_E_UTRAN_Parameters_Description;

        /* Serving Cell Priority Parameters Description */
        if(trx_g->bts.interRatInfo.servCellPrioParams.scellPrioParamsPresent)
        {
            SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_Serving_Cell_Priority_Parameters_Description(priorityAndEutranParams, ED_TRUE);
            priorityAndEutranParams->Serving_Cell_Priority_Parameters_Description->GERAN_PRIORITY = trx_g->bts.interRatInfo.servCellPrioParams.geranPriority;
            priorityAndEutranParams->Serving_Cell_Priority_Parameters_Description->THRESH_Priority_Search = trx_g->bts.interRatInfo.servCellPrioParams.threshPrioSearch;
            priorityAndEutranParams->Serving_Cell_Priority_Parameters_Description->THRESH_GSM_low = trx_g->bts.interRatInfo.servCellPrioParams.threshGsmLow;
            priorityAndEutranParams->Serving_Cell_Priority_Parameters_Description->H_PRIO = trx_g->bts.interRatInfo.servCellPrioParams.hPrio;
            priorityAndEutranParams->Serving_Cell_Priority_Parameters_Description->T_Reselection = trx_g->bts.interRatInfo.servCellPrioParams.tReselection; 
        }

        /* E-UTRAN Parameters Description */
        SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description(priorityAndEutranParams, ED_TRUE);
        eutranParamsDescr = priorityAndEutranParams->E_UTRAN_Parameters_Description;

        /* E-UTRAN Measurement Parameters Description */
        SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description_E_UTRAN_Measurement_Parameters_Description(eutranParamsDescr, ED_TRUE);

        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->Qsearch_C_E_UTRAN_Initial = 7; /* Always Search EUTRAN Cells */
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_REP_QUANT = 0; /* RSRP */
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_MULTIRAT_REPORTING = 2;
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET_Present = TRUE;
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET = 40;
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET_Present = TRUE;
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET = 40;        
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->REPORTING_GRANULARITY_Present = TRUE;
        eutranParamsDescr->E_UTRAN_Measurement_Parameters_Description->REPORTING_GRANULARITY = 0;

        /* 3G Priority Parameters Description */
        if(trx_g->bts.interRatInfo.umtsDefaultPrioParams.priorityParamsPresent)
        {
            SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description__3G_Priority_Parameters_Description(priorityAndEutranParams, ED_TRUE);
            priorityAndEutranParams->_3G_Priority_Parameters_Description->UTRAN_Start = 0;
            priorityAndEutranParams->_3G_Priority_Parameters_Description->UTRAN_Stop = 0;
            SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description__3G_Priority_Parameters_Description_DEFAULT_UTRAN_PRIORITY(priorityAndEutranParams->_3G_Priority_Parameters_Description, ED_TRUE);
            priorityAndEutranParams->_3G_Priority_Parameters_Description->DEFAULT_UTRAN_PRIORITY = trx_g->bts.interRatInfo.umtsDefaultPrioParams.utranPriority;
            SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description__3G_Priority_Parameters_Description_DEFAULT_THRESH_UTRAN(priorityAndEutranParams->_3G_Priority_Parameters_Description, ED_TRUE);
            priorityAndEutranParams->_3G_Priority_Parameters_Description->DEFAULT_THRESH_UTRAN = trx_g->bts.interRatInfo.umtsDefaultPrioParams.threshUtranDb;
            SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description__3G_Priority_Parameters_Description_DEFAULT_UTRAN_QRXLEVMIN(priorityAndEutranParams->_3G_Priority_Parameters_Description, ED_TRUE);
            priorityAndEutranParams->_3G_Priority_Parameters_Description->DEFAULT_UTRAN_QRXLEVMIN = trx_g->bts.interRatInfo.umtsDefaultPrioParams.utranQrxlevminDbm;
        }
        
        /* Encode SI2Q-Rest Octets */        
        Len = ENCODE_c_SI2quaterRestOctets(Buffer, 0, &si2qRestOctets);
        if(Len > 160)
          logPrint(LOG_ERR, "generate_si2q(): Encoded SI2q rest octets exceeded 160 bits(%d)", Len);

        memcpy(si2q_rest_octets, Buffer, 20);

        /* Free the Allocated memory */
        FREE_c_SI2quaterRestOctets (&si2qRestOctets);        
    }

    else if(fill3gInfo)
    {
        /* 3G Neighbor Info */
        c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description* p3gNeighCellDescr = NULL;
        c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description_UTRAN_FDD_Description* utranFddDescr = NULL;
        c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description_UTRAN_FDD_Description_Repeated_UTRAN_FDD_Neighbour_Cells_data **utranFddNeighbors = NULL;
        
        SETPRESENT_c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description(&(si2qRestOctets), ED_TRUE);        
        p3gNeighCellDescr = si2qRestOctets.p3G_Neighbour_Cell_Description;

        if(umtsInstance == 0)
        {
            p3gNeighCellDescr->Index_Start_3G_Present = TRUE;
            p3gNeighCellDescr->Index_Start_3G = 0;
        }
        
        SETPRESENT_c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description_UTRAN_FDD_Description(si2qRestOctets.p3G_Neighbour_Cell_Description, ED_TRUE);
        utranFddDescr = p3gNeighCellDescr->UTRAN_FDD_Description;        

        /* one SI2Q instance can contain 2 3G neighbor UARFCN info */
        SETITEMS_c_SI2quaterRestOctets_p3G_Neighbour_Cell_Description_UTRAN_FDD_Description_Repeated_UTRAN_FDD_Neighbour_Cells(&(utranFddDescr->Repeated_UTRAN_FDD_Neighbour_Cells), 2);
        utranFddNeighbors = utranFddDescr->Repeated_UTRAN_FDD_Neighbour_Cells.data;

        /* 3G FDD Neighbor - 1 */
        utranFddNeighbors[0]->FDD_ARFCN       = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].uarfcn;
        utranFddNeighbors[0]->FDD_Indic0      = 0;
        if((trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells > 0) && \
           (trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells <= FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN))
          utranFddNeighbors[0]->NR_OF_FDD_CELLS = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells;

        if(utranFddNeighbors[0]->NR_OF_FDD_CELLS > 0)
        {
            SETITEMS_c_FDD_CELL_INFORMATION(&(utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field), utranFddNeighbors[0]->NR_OF_FDD_CELLS);

            for (i = 0; i < utranFddNeighbors[0]->NR_OF_FDD_CELLS; i++)
            {
                utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field.data[i]->ScramblingCode = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].neighFddCell[i].psc;
                utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field.data[i]->Diversity = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].neighFddCell[i].diversityApplied;
            }
        }

        /* 3G FDD Neighbor - 2 */
        utranFddNeighbors[1]->FDD_ARFCN       = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].uarfcn;
        utranFddNeighbors[1]->FDD_Indic0      = 0;
        if((trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells > 0) && \
           (trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells <= FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN))
          utranFddNeighbors[1]->NR_OF_FDD_CELLS = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells;

        if(utranFddNeighbors[1]->NR_OF_FDD_CELLS > 0)
        {    
            SETITEMS_c_FDD_CELL_INFORMATION(&(utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field), utranFddNeighbors[1]->NR_OF_FDD_CELLS);

            for (i = 0; i < utranFddNeighbors[1]->NR_OF_FDD_CELLS; i++)
            {
                utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field.data[i]->ScramblingCode = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].neighFddCell[i].psc;
                utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field.data[i]->Diversity = trx_g->bts.interRatInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].neighFddCell[i].diversityApplied;
            }
        }

        /* Encode SI2Q-Rest Octets */        
        Len = ENCODE_c_SI2quaterRestOctets(Buffer, 0, &si2qRestOctets);
        if(Len > 160)
          logPrint(LOG_ERR, "generate_si2q(): Encoded SI2q rest octets exceeded 20 bytes");

        memcpy(si2q_rest_octets, Buffer, 20);

        /* Free the allocated memory */
        FREE_c_SI2quaterRestOctets(&si2qRestOctets);
    }

    else
    {
        /* 4G Neighbor Info */        
        c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description* priorityAndEutranParams = NULL;
        c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description* eutranParamsDescr = NULL;
        c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells_data** eutranNeighInfo = NULL;

        SETPRESENT_c_SI2quaterRestOctets__3G_CCN_ACTIVE(&(si2qRestOctets), ED_TRUE);
        si2qRestOctets._3G_CCN_ACTIVE = 0;

        SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description(&(si2qRestOctets), ED_TRUE);
        priorityAndEutranParams = si2qRestOctets.Priority_and_E_UTRAN_Parameters_Description;
        
        /* E-UTRAN Parameters Description */
        SETPRESENT_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description(priorityAndEutranParams, ED_TRUE);
        eutranParamsDescr = priorityAndEutranParams->E_UTRAN_Parameters_Description;

        /* one SI2Q instance can contain 2 4G neighbor EARFCN info */
        SETITEMS_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells(&(eutranParamsDescr->Repeated_E_UTRAN_Neighbour_Cells), 2);
        eutranNeighInfo = eutranParamsDescr->Repeated_E_UTRAN_Neighbour_Cells.data;

        tOCT_UINT8 lteNeighIndex = 0;

        if(lteInstance == 0) lteNeighIndex = 0;
        else if(lteInstance == 1) lteNeighIndex = 2;
        else if(lteInstance == 2) lteNeighIndex = 4;
        
        for(i = 0; i < 2; i++)
        {
            SETITEMS_c_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells_data_cell(&(eutranNeighInfo[i]->cell), 1);

            eutranNeighInfo[i]->cell.data[0]->EARFCN                        = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].earfcn;
            eutranNeighInfo[i]->cell.data[0]->Measurement_Bandwidth_Present = TRUE;
            eutranNeighInfo[i]->cell.data[0]->Measurement_Bandwidth         = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranMeasBwNrb;
            eutranNeighInfo[i]->E_UTRAN_PRIORITY                            = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranPriorityInfo.eutranPriority;
            eutranNeighInfo[i]->E_UTRAN_PRIORITY_Present                    = TRUE;
            eutranNeighInfo[i]->THRESH_E_UTRAN_high                         = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranPriorityInfo.threshEutranHighDb; 
            eutranNeighInfo[i]->THRESH_E_UTRAN_low                          = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranPriorityInfo.threshEutranLowDb;
            eutranNeighInfo[i]->THRESH_E_UTRAN_low_Present                  = TRUE;
            eutranNeighInfo[i]->E_UTRAN_QRXLEVMIN                           = trx_g->bts.interRatInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranPriorityInfo.eutranQrxlevminDbm;
            eutranNeighInfo[i]->E_UTRAN_QRXLEVMIN_Present                   = TRUE;
        }

        /* Encode SI2Q-Rest Octets */
        Len = ENCODE_c_SI2quaterRestOctets(Buffer, 0, &si2qRestOctets);

        memcpy(si2q_rest_octets, Buffer, 20);

        if(Len > 160)
          logPrint(LOG_ERR, "generate_si2q(): Encoded SI2q rest octets exceeded 20 bytes");

        /* Free the allocated memory */
        FREE_c_SI2quaterRestOctets(&si2qRestOctets);
    }
    return 1;
}

int generate_si2q()
{
	struct sys_info_type_2q *si2q = NULL;
    tOCT_UINT8 i = 0, noOfSi2qInstancesWith3gInfo = 0, noOfSi2qInstancesWith4gInfo = 0;
    int retVal = 1;
    static tOCT_UINT8 umtsInstance = 0, lteInstance = 0;

    /* SI2Q: Instance 0: Common + Measurement Information */
    trx_g->bts.noOfValidSi2qInstances = 1;
    
    if(trx_g->bts.interRatInfo.umtsNeighbors.noOfFddUarfcns > FXL_2G_MAX_3G_NEIGHBOR_UARFCNS)
    {
        logPrint(LOG_DEBUG, "generate_si2q: Number Of Fdd Uarfcns > FXL_2G_MAX_3G_NEIGHBOR_UARFCNS");
        retVal = -1;
        return retVal;
    }

    if(trx_g->bts.interRatInfo.lteNeighbors.noEutranFreqs > FXL_2G_MAX_4G_NEIGHBOR_EARFCNS)
    {
        logPrint(LOG_DEBUG, "generate_si2q: Number Of Earfcns > FXL_2G_MAX_4G_NEIGHBOR_EARFCNS");
        retVal = -1;
        return retVal;
    }

    /* Each SI2Q Instance can contain 2 3G Neighbor Freq Information or 2 4G Neighbor Freq Information */
    for(i = 0; i < trx_g->bts.interRatInfo.umtsNeighbors.noOfFddUarfcns; i = i+2)
    {
        trx_g->bts.noOfValidSi2qInstances++;
        noOfSi2qInstancesWith3gInfo++;
    }

    for(i = 0; i < trx_g->bts.interRatInfo.lteNeighbors.noEutranFreqs; i = i+2)
    {
        trx_g->bts.noOfValidSi2qInstances++;
        noOfSi2qInstancesWith4gInfo++;
    }

    /* Initialize */
    for(i = 0; i < MAX_SI2Q_INSTANCES; i++)
    {
        si2q = (struct sys_info_type_2q *) &trx_g->bts.si2q_buf[i][0];
	    memset(si2q, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN);
    }

    umtsInstance = 0;
    lteInstance  = 0;
    
    for(i = 0; i < trx_g->bts.noOfValidSi2qInstances; i++)
    {
        si2q = (struct sys_info_type_2q *) &trx_g->bts.si2q_buf[i][0];

        si2q->header.l2_p_len = (22 << 2) | 1;
        si2q->header.rr_proto_disc = PROTO_DISC_RR;
    	si2q->header.skip_ind = 0;
    	si2q->header.sys_info = MT_RR_SYSINFO_TYPE_2quater;

        if(i == 0)
        {
            retVal = generate_si2q_rest_octets(si2q->rest_octets, i, FALSE, umtsInstance, lteInstance);
        }
        else if(i > noOfSi2qInstancesWith3gInfo)
        {
            retVal = generate_si2q_rest_octets(si2q->rest_octets, i, FALSE, umtsInstance, lteInstance);
            lteInstance++;
        }
        else
        {
            retVal = generate_si2q_rest_octets(si2q->rest_octets, i, TRUE, umtsInstance, lteInstance);
            umtsInstance++;
        }

        if(retVal < 0)
          return retVal;
    }
	return retVal;
}
#endif /* FEA_2G_INTER_RAT_MEAS */

void get_sysinfo(gsm_bts *bts, rts_time *g_time, tOCT_UINT8 *si)
{
    static tOCT_UINT8 si2qInstance = 0;

    switch (g_time->tc)
    {
    case 0:
        memcpy(si, bts->si1_buf, GSM_MACBLOCK_LEN);
        break;
    case 1:
        memcpy(si, bts->si2_buf, GSM_MACBLOCK_LEN);
        break;
    case 2:
        memcpy(si, bts->si3_buf, GSM_MACBLOCK_LEN);
        break;
    case 3:
        memcpy(si, bts->si4_buf, GSM_MACBLOCK_LEN);
        break;
#ifdef FEA_GPRS
    case 4:
	{
		if(maxPdtchChannel)
	      memcpy(si, bts->si13_buf, GSM_MACBLOCK_LEN);
		else
	      memcpy(si, bts->si2_buf, GSM_MACBLOCK_LEN);
	}
        break;
#else
    case 4:
        memcpy(si, bts->si2_buf, GSM_MACBLOCK_LEN);
        break;
#endif
    case 5:
    {
#ifdef FEA_2G_INTER_RAT_MEAS
        memcpy(si, &bts->si2q_buf[si2qInstance][0], GSM_MACBLOCK_LEN);
        si2qInstance++;
        if(si2qInstance >= bts->noOfValidSi2qInstances)
          si2qInstance = 0;
#else
        memcpy(si, bts->si2_buf, GSM_MACBLOCK_LEN);
#endif
    }
        break;
    case 6:
        memcpy(si, bts->si3_buf, GSM_MACBLOCK_LEN);
        break;
    case 7:
        memcpy(si, bts->si4_buf, GSM_MACBLOCK_LEN);
        break;
    default:
        memcpy(si, fill_frame, GSM_MACBLOCK_LEN);
        break;
    }
}

tOCT_UINT8* getLaiFromSysInfo()
{
	return &storedLai[0] ;
}
