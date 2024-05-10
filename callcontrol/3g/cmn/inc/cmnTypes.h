
/* Prevent nested includes */
#ifndef __CMMTYPES_H
#define __CMMTYPES_H


#ifdef __KERNEL__

#include <linux/types.h>  /*>uint32_t, uint16_t, uint8_t, int8_t, int16_t, int32_t, uint64_t, int64_t*/
#include <linux/string.h>/*memcmp, memcpy, string functions*/
#include <linux/vmalloc.h>

#define malloc vmalloc
#define free vfree
#define ASSERT(x)  (void(0))
#else

#include <stdint.h> /*>uint32_t, uint16_t, uint8_t, int8_t, int16_t, int32_t, uint64_t, int64_t*/
#include <stddef.h> /*>NULL, size_t, offsetof()*/
#include <string.h> /*memcmp, memcpy, string functions*/
#include <stdlib.h> /*malloc, free*/
#include <stdio.h>  /*printf, sprintf*/
#include <assert.h>

#define ASSERT(e)  assert(e)
#endif



/* Constants ------------------------------------------------------------- */

#ifndef __cplusplus

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#ifndef __TYPE_BOOL__
#define __TYPE_BOOL__
#ifndef bool
/*typedef enum
{
    false = 0,
    true  = 1
} bool;*/
typedef int bool;
#endif
typedef bool cmmBool;
#endif  /*__TYPE_BOOL__*/
#endif /*__cplusplus*/


#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#ifndef MAX_UINT32_VALUE
#define MAX_UINT32_VALUE  0xFFFFFFFF
#endif

#ifndef MAX_UINT64_VALUE
#define MAX_UINT64_VALUE  0xFFFFFFFFFFFFFFFF
#endif

/*UCHAR-->UINT32*/
#define STATICINLINE  inline
#define EXTERN extern





#ifndef __BYTE_CONVERT_
#define __BYTE_CONVERT_

/*Conve*/
#define UINT8_TO_UINT32(s1, s2, s3, s4) (((uint32_t)(s1)<<24) + ((uint32_t)(s2)<<16) + ((uint32_t)(s3)<<8) + (s4))
#define UINT8_TO_UINT24(s1, s2, s3, s4) ((0<<24) + ((uint32_t)(s1)<<16) + ((uint32_t)(s2)<<8) + (s3))

/*UINT32-->UCHAR*/
#define UINT32_TO_UINT8_HH(u)    ((uint8_t)((u) >>24))
#define UINT32_TO_UINT8_MH(u)    ((uint8_t)((u) >>16))
#define UINT32_TO_UINT8_ML(u)    ((uint8_t)((u) >>8))
#define UINT32_TO_UINT8_LL(u)    ((uint8_t)((u) & 0xFF))

#define UINT8_TO_UINT32_MEM(p) UINT8_TO_UINT32(((p)[0]), ((p)[1]), ((p)[2]), ((p)[3]))
#define UINT8_TO_UINT24_MEM(p) UINT8_TO_UINT24(((p)[0]), ((p)[1]), ((p)[2]), ((p)[3]))

#define GET_MEM_24(p) UINT8_TO_UINT32((0), ((p)[0]), ((p)[1]), ((p)[2]))

#define UINT32_TO_UINT8_MEM(p, u) \
    do{\
          (p)[0] = (u) >> 24;\
          (p)[1] = (u) >> 16;\
          (p)[2] = (u) >> 8;\
          (p)[3] = (u);\
      }while(0)

/*UCHAR-->USHORT*/
#define UINT8_TO_UINT16(s1, s2) (((uint16_t)(s1)<<8) + (s2))
/*USHORT-->UCHAR*/
#define UINT16_TO_UINT8_H(us) ((uint8_t)((us) >>8))
#define UINT16_TO_UINT8_L(us) ((uint8_t)((us) & 0xFF))

#endif /*__BYTE_CONVERT_*/




/*Oct String Types*/

typedef struct
{
    unsigned numOcts;
    uint8_t * data;
}OctString_s;

typedef struct
{
    unsigned numBits;
    uint8_t * data;
}BitString_s;

typedef struct
{
    unsigned numOcts;
    uint8_t data[20];
}OctArray20_s;


typedef struct
{
    unsigned numBits;
    uint8_t data[8];
}BitArray64_s;


typedef union
{
    unsigned  u;
    int i;
    void * data;
}cmmContext_u;

/**
* Structure to construct a byte stream in a buffer.
*/
typedef struct
{
    unsigned numOcts;   /** Total buffer lenth*/
    unsigned offset;    /** Current offset, before the offset, data is valid*/
    uint8_t * data;     /** Pointer to a data*/
}cmmBuf_s;

/**Structure to show the PDU transfter between different modules.
* the PDU means...
*
*/
typedef struct
{
    unsigned numOcts;   /** PDU length in Bytes*/
    unsigned pduType;   /** PDU Type, used in PDU trace, see the types in CMM Trace*/
    uint8_t * data;     /** PDU Bytestream*/
}cmmPdu_s;


#define cmpOctStrArray(a, b) \
   ( ( ((a)->numOcts == ((b)->numOcts))&&(0 == memcmp((a)->data, (b)->data, (a)->numOcts))) ? 0: 1 )

#define cmpBitStrArray(a, b) \
   ( ( ((a)->numBits == ((b)->numBits))&&(0 == memcmp((a)->data, (b)->data, ((a)->numBits + 7)/8))) ? 0: 1 )

#define cpyOctStrArray(tgt, src) \
    do{ \
        (tgt)->numOcts = (src)->numOcts; \
        memcpy((tgt)->data, (src)->data, (src)->numOcts;\
    }while(0)

    
#ifndef ALIGN_4BYTE_ADDR
#define ALIGN_4BYTE_ADDR(addr) (((addr + 3)>>2)<<2)
#endif

#ifndef ALIGN_2BYTE_ADDR
#define ALIGN_2BYTE_ADDR(addr) (((addr + 1)>>1)<<1)
#endif


#endif  /* __CMMTYPES_H */
/* End of cmmTypes.h */

