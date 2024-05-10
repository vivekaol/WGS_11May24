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
* File Name   : feaConfig.h
*
* Description : Config file for feature definitions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 18/02/2015          Shivashankar V     File Creation
*############################################################################
*/

#ifndef FEACONFIG_H_
#define FEACONFIG_H_

/*
    #define FEA_VOICE_CALL_TO_TARGET

    Description : Voice call to targeted Blacklisted User
                  is supported under this flag.
*/
#define FEA_VOICE_CALL_TO_TARGET

/*
    #define FEA_SILENT_CALL

    Description    : This flag enables SILENT CALL feature in GSM, which is
                     used to establish constant communication with the phone
                     without its knowledge.
					 Currently we support 2 types of silent calls:
					 1. SDCCH Silent Call - The communication channel between
					    phone and BTS is SDCCH channel.
					 2. TCH Silent Call - The communication channel between
					    phone and BTS is TCH channel.
					 
*/

/*
    #define MM_INFO

    Description : Option to customise the Network Name of the BTS
                  is supported under this flag.
*/
//#define MM_INFO

#define FEA_SILENT_CALL
#define	FEA_ALERT
//#define FEA_2G_RELEASE_BL_USER
#define FXL_3G_UE_TX_PWR
#define FXL_3G_SILENT_CALL
#define FXL_3G_UE_BASED_GPS
//#define FXL_3G_TX_JAMMER
#define FXL_3G_UE_BASED_REDIRECT
#define FXL_4G_RELEASE_BL_USER
#define FXL_4G_UE_BASED_REDIRECT
#define FEA_4G_SILENT_CALL
#define FEA_4G_TDDLTE
#define CELL_ANTENNA_CHANGE
//#define IOCOM_MULTI_BOARD
//#define OBM_PA_BTS8500_NW
//#define OBM_PA_BTS8500_WW
//#define OBM_PA_BTS8000
#define OBM_BOARD_OFF
#define OBM_GPS_STATUS
//#define OBM_BATTERY_STATUS
//#define FXL_BOARD_STATUS      // Disabled in 3.7 as long as GUI design for TCP Socket is not changed
//#define LTE_TX_JAMMER_ENABLED
//#define FXL_4G_TX_JAMMER
//#define OBM_TEMPERATURE_STATUS
//#define FEA_ENABLE_ID_CATCHER
#define CDMA_SCAN
#define RSSI_SCAN
#define FXL_4G_NEIGH_CELL_MEAS

#ifdef FEA_ALERT
#define FEA_SILENT_CALL
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET
#define FEA_SILENT_CALL
#endif
#define	FEA_EMER

/*
    #define FEA_MT_SMS

    Description    : This flag enables MT SMS feature in GSM.
					 
*/
#define FEA_MT_SMS

/*
    #define FEA_DECODE_MO_SMS

    Description    : This flag enables MO SMS Decoding feature in GSM.
					 
*/
#ifdef FEA_MT_SMS
#define FEA_DECODE_MO_SMS
#endif

/*
    #define FEA_REJECT_CAUSE_CONTROL

    Description    : This flag allows the user to control the LAU reject cause sent for Whitelisted Users.
					 
*/
#define FEA_REJECT_CAUSE_CONTROL

/*
    #define EVAL_RLS_PACKAGE

    Description    : This flag is used to limit the s/w capability and should be 
	                 enabled while building evaluation packages for customers or
					 for demo purposes.
					 Currently following limitations are under this flag
					 1. Whitelist support for maximum of 16 Identities.
					 2. Blacklist support for maximum of 3 Identities. 
					 
*/
//#define EVAL_RLS_PACKAGE

/*
    #define DISABLE_GPS_RSSI_FEA

    Description    : This flag disables GPS-RSSI feature in GSM.
*/
#ifdef EVAL_RLS_PACKAGE
#define DISABLE_GPS_RSSI_FEA
//#define EVAL_RLS_PACKAGE_HARD_CODED_BANDS
//#define HARDCODE_MAC_ADDRESS
#endif

#ifdef EVAL_RLS_PACKAGE

// Enable only one customer at a time
//#define EVAL_RLS_DIGITRO
//#define EVAL_RLS_IOCOM
//#define EVAL_RLS_DNATRACKER

//#define DEMO_PLMN_LOCK

//#define SEC_DSP_CAN_ONLY_READ_SHARED_MEMORY
#endif

/*
    #define FEA_SI2QUATER_DECODE

    Description    : SI-2 Quater System Information decoding is gaurded under this flag.
					 
*/
#define FEA_SI2QUATER_DECODE

/*
    #define FEA_2G_ENH_TCH_SILENT_CALL

    Description    : Some Enhancements in TCH Silent Call are made under this flag.

*/
#ifdef FEA_SILENT_CALL
#define FEA_2G_ENH_TCH_SILENT_CALL
#endif

/*
    #define FEA_2G_DYNAMIC_SYS_INFO_CONFIG

    Description : Dynamic configuration of System Information parameters in 2G 
                  is supported under this flag.

*/
#define FEA_2G_DYNAMIC_SYS_INFO_CONFIG
#define FEA_3G_DYNAMIC_SYS_INFO_CONFIG
#define FEA_4G_DYNAMIC_SYS_INFO_CONFIG

/*
    #define FXL_BL_UE_POWER_OFF

    Description : Faster reporting of UE switch off, RL Failure
                  and Out of coverage is supported under this flag.

*/
#define FXL_BL_UE_POWER_OFF
//#define ENABLE_FLEXERA
//#define FEA_GPRS

/*
    #define FEA_2G_SEND_SMS_DURING_REGISTRATION

    Description : Under this flag, Blacklist Users will be sent with the 
                  pre-configured SMS during registration.
*/
//#define FEA_2G_SEND_SMS_DURING_REGISTRATION

/*
    #define FEA_BL_VAL_CHK_BY_PERIODIC_PAGING

    Description : Under this flag, Blacklist Users will be periodically 
                  paged to know if they are still in the range of BTS.

    Dependency  : Should be disabled if FEA_2G_SEND_SMS_DURING_REGISTRATION 
                  is enabled.

    Note: It is good idea to disable this flag, if the BTS is operating in 
          a mode where large number of blacklist users will be captured.
*/
#ifndef FEA_2G_SEND_SMS_DURING_REGISTRATION
#define FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
#endif
/*
    #define FEA_2G_INTER_RAT_MEAS

    Description : 3G/4G Neighbor cells configuration and measurements
                  are supported under this flag.
*/
//#define FEA_2G_INTER_RAT_MEAS

#endif /* FEACONFIG_H_ */
