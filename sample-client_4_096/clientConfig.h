/*
 * clientConfig.h
 *
 * Header to edit for different client configurations
 *
 */

#ifndef CLIENTCONFIG_H_
#define CLIENTCONFIG_H_

#define FALSE 0
#define TRUE  1

typedef enum{
    NOT_CONFIGURED = 0,
    CONFIG_SCANNER_AND_IDCATCHER_WITH_AUTOCONFIG = 1,
    CONFIG_SCANNER_AND_IDCATCHER_WITHOUT_AUTOCONFIG = 2,
    CONFIG_SCANNER_ONLY = 3,
    CONFIG_IDCATCHER_ONLY = 4
}gsmClientConfigType;

typedef enum{
	PRIMARY = 0,
	SECONDARY = 1
}dspType;

typedef enum{
	BAND_SCAN = 3,
	SELECTIVE_SCAN = 1
}scanType;

typedef enum
{
    EXHAUSTIVE_SCAN,
    RSSI_ONLY_SCAN
}scanCategoryType;

//const unsigned char tcpClientConfig = CONFIG_IDCATCHER_ONLY;
const unsigned char tcpClientConfig = CONFIG_SCANNER_ONLY;
const unsigned char dspInUse = PRIMARY;
const char *ipaddress = "192.168.7.100";
scanType scanInUse = BAND_SCAN;
scanCategoryType scanCategory = EXHAUSTIVE_SCAN;

#endif /* CLIENTCONFIG_H_ */
