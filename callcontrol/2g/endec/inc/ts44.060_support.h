/*******************************************************************************
  ts44.060_support.c  Developed by DAFOCUS
*******************************************************************************/
#ifndef __44060_SUPPORT_H
#define __44060_SUPPORT_H
#ifdef __cplusplus
extern "C" {
#endif

extern unsigned DECODE_FDD_CELL_INFORMATION_p (unsigned n);
extern unsigned DECODE_TDD_CELL_INFORMATION_q (unsigned n);

/*
	EXTERNAL DECODING WITHIN CSN.1
	
	These macro allow using an external variable size decoder as a normal CSN.1 field.
	
	Example: instead of:
	
		< Frequency Parameters : < Frequency Parameters IE > >
	
	use:	
		ENCODE: %{}% DECODE: %{TS44060_EXT_DECODE_BEGIN(Frequency_Parameters_IE)}%
		< Frequency Parameters {Frequency_Parameters_IE}: bit*ENCODECO_EXPR:%{TS44060_EXT_DECODE_LEN}% = bit**>
		ENCODE: %{}% DECODE: %{TS44060_EXT_DECODE_END}%
	
*/
#define TS44060_EXT_DECODE_BEGIN(typ) \
	c_##typ msg;\
	int len;\
	INIT_c_##typ (&msg);\
	len = DECODE_c_##typ (Context->Buffer, Context->CurrOfs, &msg, Context->FinalOffset-Context->CurrOfs);\
	FREE_c_##typ (&msg);\
	if (len < 0) len = 0;\
	PUSH_TAG(223, len);

#define TS44060_EXT_DECODE_LEN TAGZ(223)
#define TS44060_EXT_DECODE_END POP_TAGS(223);

#ifdef __cplusplus
}
#endif
#endif
