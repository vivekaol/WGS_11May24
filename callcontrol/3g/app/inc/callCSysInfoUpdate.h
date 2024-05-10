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
 * File Name   : callCSysInfoUpdate.h 
 *
 * Description : This is System Information Update file of ImsiCatcher 
 *               application. It fills & encodes all type of SIB Messages which
 *               will be sent on BCCH BCH Message. 
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 13/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _CALL_C_SYS_INFO_UPDATE_H
#define _CALL_C_SYS_INFO_UPDATE_H

#define     SIM_SIZE                        32
#define     ROK                             0
#define     RFAILED                         1
#define     MAX_MCC_LEN                     3
#define     MAX_MNC_LEN                     3
#define     MAX_SIB                         6
#define     MAX_INTER_FREQ_NEIGHBOURS       32
#define     MAX_INTRA_FREQ_NEIGHBOURS       32
#define     COMPLETE_SIB_SIZE               226
#define     SEGMENTED_SIB_SIZE              222
#define     MAX_SIB11_SEGS                  15

extern int buildAndSendL1SibMessage (void);
extern int fillAndEncodeSibMessages (void);

extern int fillAndEncodeMIB (void);
extern void fillMIB (void);

extern int fillAndEncodeSIB1 (void);
extern int fillSIB1 (void);

extern int fillAndEncodeSIB2 (void);
extern int fillSIB2 (void);

extern int fillAndEncodeSIB3 (void);
extern int fillSIB3 (void);

extern int fillAndEncodeSIB5 (void);
extern int fillSIB5 (void);

extern int fillAndEncodeSIB7 (void);
extern int fillSIB7 (void);

extern int fillAndEncodeSIB11 (void);
extern int fillSIB11 (void);

extern void setBit (char *pSib5SegData, int idx, 
                    int bitPos, int value);
extern void fillSibSegmentedData 
                   (char *pSib5SegData,
                    char *pSib5Data,
                    int  *pBitLength,
                    int  *pBitOffset,
                    int  *pByteOffset);
#endif
