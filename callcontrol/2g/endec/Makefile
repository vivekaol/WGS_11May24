
ENDEC_ROOT=.
ENDEC_SRC=${ENDEC_ROOT}/src
ENDEC_INC=${ENDEC_ROOT}/inc
CFLAGS=-D_CRT_SECURE_NO_WARNINGS -I. -I${ENDEC_INC}
STRIP=strip
#CPP=g++
CPP=arm-cortexa9-linux-gnueabi-g++
#CC=gcc
CC=arm-cortexa9-linux-gnueabi-gcc
#LD=g++
LD=arm-cortexa9-linux-gnueabi-g++
LDFLAGS=
OEXT=.o
OUTDIR=out
#AR=ar
AR=arm-cortexa9-linux-gnueabi-ar
ARFLAGS=rcs
LINKLIB=${OUTDIR}/libGsmEnDec.a
TEST_EXE=test.exe

OBJS=\
  ${OUTDIR}/bitencode${OEXT}\
  ${OUTDIR}/csn1clib${OEXT}\
  ${OUTDIR}/ed_dump${OEXT}\
  ${OUTDIR}/ed_dump_file${OEXT}\
  ${OUTDIR}/ed_dump_val${OEXT}\
  ${OUTDIR}/ed_dynamic${OEXT}\
  ${OUTDIR}/ed_lib${OEXT}\
  ${OUTDIR}/CM_CP_SMS${OEXT}\
  ${OUTDIR}/MS2MSC_SMS${OEXT}\
  ${OUTDIR}/MS2SC_ACK_SMS${OEXT}\
  ${OUTDIR}/MS2SC_ERR_SMS${OEXT}\
  ${OUTDIR}/MS2SC_SMS${OEXT}\
  ${OUTDIR}/MSC2MS_SMS${OEXT}\
  ${OUTDIR}/SC2MS_ACK_SMS${OEXT}\
  ${OUTDIR}/SC2MS_ERR_SMS${OEXT}\
  ${OUTDIR}/SC2MS_SMS${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_SMS${OEXT}\
  ${OUTDIR}/ed_c_SMS${OEXT}\
  ${OUTDIR}/ed_c_dump_SMS${OEXT}\
  ${OUTDIR}/ed_c_known_ie_SMS${OEXT}\
  ${OUTDIR}/ed_c_recog_SMS${OEXT}\
  ${OUTDIR}/lib_23.040${OEXT}\
  ${OUTDIR}/CSN1DataTypes_L3${OEXT}\
  ${OUTDIR}/L3Downlink_L3${OEXT}\
  ${OUTDIR}/L3Uplink_L3${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_L3${OEXT}\
  ${OUTDIR}/XTIDDownlink_L3${OEXT}\
  ${OUTDIR}/XTIDUplink_L3${OEXT}\
  ${OUTDIR}/ed_c_L3${OEXT}\
  ${OUTDIR}/ed_c_dump_L3${OEXT}\
  ${OUTDIR}/ed_c_known_ie_L3${OEXT}\
  ${OUTDIR}/ed_c_recog_L3${OEXT}\
  ${OUTDIR}/CSN1DataTypes_EPS${OEXT}\
  ${OUTDIR}/EPS_MM_Downlink_EPS${OEXT}\
  ${OUTDIR}/EPS_MM_Uplink_EPS${OEXT}\
  ${OUTDIR}/EPS_SM_Downlink_EPS${OEXT}\
  ${OUTDIR}/EPS_SM_Uplink_EPS${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_EPS${OEXT}\
  ${OUTDIR}/ed_c_EPS${OEXT}\
  ${OUTDIR}/ed_c_dump_EPS${OEXT}\
  ${OUTDIR}/ed_c_known_ie_EPS${OEXT}\
  ${OUTDIR}/ed_c_recog_EPS${OEXT}\
  ${OUTDIR}/CSN1DataTypes_RR${OEXT}\
  ${OUTDIR}/RRDownlink_RR${OEXT}\
  ${OUTDIR}/RRPLENDownlink_RR${OEXT}\
  ${OUTDIR}/RRShortPD_RR${OEXT}\
  ${OUTDIR}/RRUplink_RR${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_RR${OEXT}\
  ${OUTDIR}/ed_c_RR${OEXT}\
  ${OUTDIR}/ed_c_dump_RR${OEXT}\
  ${OUTDIR}/ed_c_known_ie_RR${OEXT}\
  ${OUTDIR}/ed_c_recog_RR${OEXT}\
  ${OUTDIR}/ts44.018_support${OEXT}\
  ${OUTDIR}/CSN1DataTypes_RLCMAC${OEXT}\
  ${OUTDIR}/Downlink_RLC_MAC_RLCMAC${OEXT}\
  ${OUTDIR}/Uplink_RLC_MAC_RLCMAC${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_RLCMAC${OEXT}\
  ${OUTDIR}/ed_c_RLCMAC${OEXT}\
  ${OUTDIR}/ed_c_dump_RLCMAC${OEXT}\
  ${OUTDIR}/ed_c_known_ie_RLCMAC${OEXT}\
  ${OUTDIR}/ed_c_recog_RLCMAC${OEXT}\
  ${OUTDIR}/CSN1DataTypes_EC_PACCH${OEXT}\
  ${OUTDIR}/Downlink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}\
  ${OUTDIR}/Uplink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}\
  ${OUTDIR}/UserDefinedDataTypes_EC_PACCH${OEXT}\
  ${OUTDIR}/ed_c_EC_PACCH${OEXT}\
  ${OUTDIR}/ed_c_dump_EC_PACCH${OEXT}\
  ${OUTDIR}/ed_c_known_ie_EC_PACCH${OEXT}\
  ${OUTDIR}/ed_c_recog_EC_PACCH${OEXT}

CLEAN_OBJS=${OBJS}

${LINKLIB}: ${OUTDIR} ${OBJS}
	${AR} ${ARFLAGS} ${LINKLIB} ${OBJS}

${OUTDIR}:
	mkdir ${OUTDIR}

${OUTDIR}/bitencode${OEXT}: ${ENDEC_SRC}/bitencode.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/bitencode.c -o ${OUTDIR}/bitencode${OEXT}

${OUTDIR}/csn1clib${OEXT}: ${ENDEC_SRC}/csn1clib.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/csn1clib.c -o ${OUTDIR}/csn1clib${OEXT}

${OUTDIR}/ed_dump${OEXT}: ${ENDEC_SRC}/ed_dump.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_dump.c -o ${OUTDIR}/ed_dump${OEXT}

${OUTDIR}/ed_dump_file${OEXT}: ${ENDEC_SRC}/ed_dump_file.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_dump_file.c -o ${OUTDIR}/ed_dump_file${OEXT}

${OUTDIR}/ed_dump_val${OEXT}: ${ENDEC_SRC}/ed_dump_val.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_dump_val.c -o ${OUTDIR}/ed_dump_val${OEXT}

${OUTDIR}/ed_dynamic${OEXT}: ${ENDEC_SRC}/ed_dynamic.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_dynamic.c -o ${OUTDIR}/ed_dynamic${OEXT}

${OUTDIR}/ed_lib${OEXT}: ${ENDEC_SRC}/ed_lib.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_lib.c -o ${OUTDIR}/ed_lib${OEXT}

${OUTDIR}/CM_CP_SMS${OEXT}: ${ENDEC_SRC}/CM_CP_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CM_CP_SMS.c -o ${OUTDIR}/CM_CP_SMS${OEXT}

${OUTDIR}/MS2MSC_SMS${OEXT}: ${ENDEC_SRC}/MS2MSC_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/MS2MSC_SMS.c -o ${OUTDIR}/MS2MSC_SMS${OEXT}

${OUTDIR}/MS2SC_ACK_SMS${OEXT}: ${ENDEC_SRC}/MS2SC_ACK_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/MS2SC_ACK_SMS.c -o ${OUTDIR}/MS2SC_ACK_SMS${OEXT}

${OUTDIR}/MS2SC_ERR_SMS${OEXT}: ${ENDEC_SRC}/MS2SC_ERR_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/MS2SC_ERR_SMS.c -o ${OUTDIR}/MS2SC_ERR_SMS${OEXT}

${OUTDIR}/MS2SC_SMS${OEXT}: ${ENDEC_SRC}/MS2SC_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/MS2SC_SMS.c -o ${OUTDIR}/MS2SC_SMS${OEXT}

${OUTDIR}/MSC2MS_SMS${OEXT}: ${ENDEC_SRC}/MSC2MS_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/MSC2MS_SMS.c -o ${OUTDIR}/MSC2MS_SMS${OEXT}

${OUTDIR}/SC2MS_ACK_SMS${OEXT}: ${ENDEC_SRC}/SC2MS_ACK_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/SC2MS_ACK_SMS.c -o ${OUTDIR}/SC2MS_ACK_SMS${OEXT}

${OUTDIR}/SC2MS_ERR_SMS${OEXT}: ${ENDEC_SRC}/SC2MS_ERR_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/SC2MS_ERR_SMS.c -o ${OUTDIR}/SC2MS_ERR_SMS${OEXT}

${OUTDIR}/SC2MS_SMS${OEXT}: ${ENDEC_SRC}/SC2MS_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/SC2MS_SMS.c -o ${OUTDIR}/SC2MS_SMS${OEXT}

${OUTDIR}/UserDefinedDataTypes_SMS${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_SMS.c -o ${OUTDIR}/UserDefinedDataTypes_SMS${OEXT}

${OUTDIR}/ed_c_SMS${OEXT}: ${ENDEC_SRC}/ed_c_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_SMS.c -o ${OUTDIR}/ed_c_SMS${OEXT}

${OUTDIR}/ed_c_dump_SMS${OEXT}: ${ENDEC_SRC}/ed_c_dump_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_SMS.c -o ${OUTDIR}/ed_c_dump_SMS${OEXT}

${OUTDIR}/ed_c_known_ie_SMS${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_SMS.c -o ${OUTDIR}/ed_c_known_ie_SMS${OEXT}

${OUTDIR}/ed_c_recog_SMS${OEXT}: ${ENDEC_SRC}/ed_c_recog_SMS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_SMS.c -o ${OUTDIR}/ed_c_recog_SMS${OEXT}

${OUTDIR}/lib_23.040${OEXT}: ${ENDEC_SRC}/lib_23.040.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/lib_23.040.c -o ${OUTDIR}/lib_23.040${OEXT}

${OUTDIR}/CSN1DataTypes_L3${OEXT}: ${ENDEC_SRC}/CSN1DataTypes_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CSN1DataTypes_L3.c -o ${OUTDIR}/CSN1DataTypes_L3${OEXT}

${OUTDIR}/L3Downlink_L3${OEXT}: ${ENDEC_SRC}/L3Downlink_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/L3Downlink_L3.c -o ${OUTDIR}/L3Downlink_L3${OEXT}

${OUTDIR}/L3Uplink_L3${OEXT}: ${ENDEC_SRC}/L3Uplink_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/L3Uplink_L3.c -o ${OUTDIR}/L3Uplink_L3${OEXT}

${OUTDIR}/UserDefinedDataTypes_L3${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_L3.c -o ${OUTDIR}/UserDefinedDataTypes_L3${OEXT}

${OUTDIR}/XTIDDownlink_L3${OEXT}: ${ENDEC_SRC}/XTIDDownlink_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/XTIDDownlink_L3.c -o ${OUTDIR}/XTIDDownlink_L3${OEXT}

${OUTDIR}/XTIDUplink_L3${OEXT}: ${ENDEC_SRC}/XTIDUplink_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/XTIDUplink_L3.c -o ${OUTDIR}/XTIDUplink_L3${OEXT}

${OUTDIR}/ed_c_L3${OEXT}: ${ENDEC_SRC}/ed_c_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_L3.c -o ${OUTDIR}/ed_c_L3${OEXT}

${OUTDIR}/ed_c_dump_L3${OEXT}: ${ENDEC_SRC}/ed_c_dump_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_L3.c -o ${OUTDIR}/ed_c_dump_L3${OEXT}

${OUTDIR}/ed_c_known_ie_L3${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_L3.c -o ${OUTDIR}/ed_c_known_ie_L3${OEXT}

${OUTDIR}/ed_c_recog_L3${OEXT}: ${ENDEC_SRC}/ed_c_recog_L3.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_L3.c -o ${OUTDIR}/ed_c_recog_L3${OEXT}

${OUTDIR}/CSN1DataTypes_EPS${OEXT}: ${ENDEC_SRC}/CSN1DataTypes_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CSN1DataTypes_EPS.c -o ${OUTDIR}/CSN1DataTypes_EPS${OEXT}

${OUTDIR}/EPS_MM_Downlink_EPS${OEXT}: ${ENDEC_SRC}/EPS_MM_Downlink_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/EPS_MM_Downlink_EPS.c -o ${OUTDIR}/EPS_MM_Downlink_EPS${OEXT}

${OUTDIR}/EPS_MM_Uplink_EPS${OEXT}: ${ENDEC_SRC}/EPS_MM_Uplink_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/EPS_MM_Uplink_EPS.c -o ${OUTDIR}/EPS_MM_Uplink_EPS${OEXT}

${OUTDIR}/EPS_SM_Downlink_EPS${OEXT}: ${ENDEC_SRC}/EPS_SM_Downlink_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/EPS_SM_Downlink_EPS.c -o ${OUTDIR}/EPS_SM_Downlink_EPS${OEXT}

${OUTDIR}/EPS_SM_Uplink_EPS${OEXT}: ${ENDEC_SRC}/EPS_SM_Uplink_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/EPS_SM_Uplink_EPS.c -o ${OUTDIR}/EPS_SM_Uplink_EPS${OEXT}

${OUTDIR}/UserDefinedDataTypes_EPS${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_EPS.c -o ${OUTDIR}/UserDefinedDataTypes_EPS${OEXT}

${OUTDIR}/ed_c_EPS${OEXT}: ${ENDEC_SRC}/ed_c_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_EPS.c -o ${OUTDIR}/ed_c_EPS${OEXT}

${OUTDIR}/ed_c_dump_EPS${OEXT}: ${ENDEC_SRC}/ed_c_dump_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_EPS.c -o ${OUTDIR}/ed_c_dump_EPS${OEXT}

${OUTDIR}/ed_c_known_ie_EPS${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_EPS.c -o ${OUTDIR}/ed_c_known_ie_EPS${OEXT}

${OUTDIR}/ed_c_recog_EPS${OEXT}: ${ENDEC_SRC}/ed_c_recog_EPS.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_EPS.c -o ${OUTDIR}/ed_c_recog_EPS${OEXT}

${OUTDIR}/CSN1DataTypes_RR${OEXT}: ${ENDEC_SRC}/CSN1DataTypes_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CSN1DataTypes_RR.c -o ${OUTDIR}/CSN1DataTypes_RR${OEXT}

${OUTDIR}/RRDownlink_RR${OEXT}: ${ENDEC_SRC}/RRDownlink_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/RRDownlink_RR.c -o ${OUTDIR}/RRDownlink_RR${OEXT}

${OUTDIR}/RRPLENDownlink_RR${OEXT}: ${ENDEC_SRC}/RRPLENDownlink_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/RRPLENDownlink_RR.c -o ${OUTDIR}/RRPLENDownlink_RR${OEXT}

${OUTDIR}/RRShortPD_RR${OEXT}: ${ENDEC_SRC}/RRShortPD_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/RRShortPD_RR.c -o ${OUTDIR}/RRShortPD_RR${OEXT}

${OUTDIR}/RRUplink_RR${OEXT}: ${ENDEC_SRC}/RRUplink_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/RRUplink_RR.c -o ${OUTDIR}/RRUplink_RR${OEXT}

${OUTDIR}/UserDefinedDataTypes_RR${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_RR.c -o ${OUTDIR}/UserDefinedDataTypes_RR${OEXT}

${OUTDIR}/ed_c_RR${OEXT}: ${ENDEC_SRC}/ed_c_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_RR.c -o ${OUTDIR}/ed_c_RR${OEXT}

${OUTDIR}/ed_c_dump_RR${OEXT}: ${ENDEC_SRC}/ed_c_dump_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_RR.c -o ${OUTDIR}/ed_c_dump_RR${OEXT}

${OUTDIR}/ed_c_known_ie_RR${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_RR.c -o ${OUTDIR}/ed_c_known_ie_RR${OEXT}

${OUTDIR}/ed_c_recog_RR${OEXT}: ${ENDEC_SRC}/ed_c_recog_RR.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_RR.c -o ${OUTDIR}/ed_c_recog_RR${OEXT}

${OUTDIR}/ts44.018_support${OEXT}: ${ENDEC_SRC}/ts44.018_support.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ts44.018_support.c -o ${OUTDIR}/ts44.018_support${OEXT}

${OUTDIR}/CSN1DataTypes_RLCMAC${OEXT}: ${ENDEC_SRC}/CSN1DataTypes_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CSN1DataTypes_RLCMAC.c -o ${OUTDIR}/CSN1DataTypes_RLCMAC${OEXT}

${OUTDIR}/Downlink_RLC_MAC_RLCMAC${OEXT}: ${ENDEC_SRC}/Downlink_RLC_MAC_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/Downlink_RLC_MAC_RLCMAC.c -o ${OUTDIR}/Downlink_RLC_MAC_RLCMAC${OEXT}

${OUTDIR}/Uplink_RLC_MAC_RLCMAC${OEXT}: ${ENDEC_SRC}/Uplink_RLC_MAC_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/Uplink_RLC_MAC_RLCMAC.c -o ${OUTDIR}/Uplink_RLC_MAC_RLCMAC${OEXT}

${OUTDIR}/UserDefinedDataTypes_RLCMAC${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_RLCMAC.c -o ${OUTDIR}/UserDefinedDataTypes_RLCMAC${OEXT}

${OUTDIR}/ed_c_RLCMAC${OEXT}: ${ENDEC_SRC}/ed_c_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_RLCMAC.c -o ${OUTDIR}/ed_c_RLCMAC${OEXT}

${OUTDIR}/ed_c_dump_RLCMAC${OEXT}: ${ENDEC_SRC}/ed_c_dump_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_RLCMAC.c -o ${OUTDIR}/ed_c_dump_RLCMAC${OEXT}

${OUTDIR}/ed_c_known_ie_RLCMAC${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_RLCMAC.c -o ${OUTDIR}/ed_c_known_ie_RLCMAC${OEXT}

${OUTDIR}/ed_c_recog_RLCMAC${OEXT}: ${ENDEC_SRC}/ed_c_recog_RLCMAC.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_RLCMAC.c -o ${OUTDIR}/ed_c_recog_RLCMAC${OEXT}

${OUTDIR}/CSN1DataTypes_EC_PACCH${OEXT}: ${ENDEC_SRC}/CSN1DataTypes_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/CSN1DataTypes_EC_PACCH.c -o ${OUTDIR}/CSN1DataTypes_EC_PACCH${OEXT}

${OUTDIR}/Downlink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}: ${ENDEC_SRC}/Downlink_RLC_MAC_EC_PACCH_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/Downlink_RLC_MAC_EC_PACCH_EC_PACCH.c -o ${OUTDIR}/Downlink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}

${OUTDIR}/Uplink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}: ${ENDEC_SRC}/Uplink_RLC_MAC_EC_PACCH_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/Uplink_RLC_MAC_EC_PACCH_EC_PACCH.c -o ${OUTDIR}/Uplink_RLC_MAC_EC_PACCH_EC_PACCH${OEXT}

${OUTDIR}/UserDefinedDataTypes_EC_PACCH${OEXT}: ${ENDEC_SRC}/UserDefinedDataTypes_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/UserDefinedDataTypes_EC_PACCH.c -o ${OUTDIR}/UserDefinedDataTypes_EC_PACCH${OEXT}

${OUTDIR}/ed_c_EC_PACCH${OEXT}: ${ENDEC_SRC}/ed_c_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_EC_PACCH.c -o ${OUTDIR}/ed_c_EC_PACCH${OEXT}

${OUTDIR}/ed_c_dump_EC_PACCH${OEXT}: ${ENDEC_SRC}/ed_c_dump_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_dump_EC_PACCH.c -o ${OUTDIR}/ed_c_dump_EC_PACCH${OEXT}

${OUTDIR}/ed_c_known_ie_EC_PACCH${OEXT}: ${ENDEC_SRC}/ed_c_known_ie_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_known_ie_EC_PACCH.c -o ${OUTDIR}/ed_c_known_ie_EC_PACCH${OEXT}

${OUTDIR}/ed_c_recog_EC_PACCH${OEXT}: ${ENDEC_SRC}/ed_c_recog_EC_PACCH.c
	${CC} ${CFLAGS} -c ${ENDEC_SRC}/ed_c_recog_EC_PACCH.c -o ${OUTDIR}/ed_c_recog_EC_PACCH${OEXT}


clean:
	rm -f ${CLEAN_OBJS}
	rm -f ${LINKLIB}
	rm -f ${EXENAME}

