/******************************************************************************/
/* @F_NAME :          nvmm_config.h                                           */
/* @F_PURPOSE :       Ram block data                                          */
/* @F_CREATED_BY :    name of the file creator                                */
/* @F_CREATION_DATE : 2022/01/19                                              */
/* @F_LANGUAGE :      C                                                       */
/* @F_MPROC_TYPE :    target independent                                      */
/*************************************** (C) Copyright 2022 Marelli ***********/
#ifndef NVMM_CONFIG_H
#define NVMM_CONFIG_H
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "Platform_Types.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*----------------Ram Block Data------------------------*/
extern uint8 NVMM_SecurityConsLevel_Ram[5];
extern uint8 NVMM_BootSwIdentDidF180_Ram[14];
extern uint8 NVMM_AppliSwIdentDidF181_Ram[14];
extern uint8 NVMM_AppliDataIdentDidF182_Ram[14];
extern uint8 NVMM_BootSwFingerprintDidF183_Ram[14];
extern uint8 NVMM_AppliSwFingerprintDidF184_Ram[14];
extern uint8 NVMM_AppliDataFingerprintDidF185_Ram[14];
extern uint8 NVMM_ProgrammingAttempsDid2003_Ram[1];
extern uint8 NVMM_AppSwUpdateAttemptCounterDid201A_Ram[12];
extern uint8 NVMM_AppDataUpdateAttemptCounterDid201B_Ram[4];
extern uint8 NVMM_BootSwHashDidD000_Ram[32];
extern uint8 NVMM_AppSwHashDidD003_Ram[32];
extern uint8 NVMM_AppDataHashDidD004_Ram[32];
extern uint8 NVMM_ProgrammingStatusDid2010_Ram[2];
extern uint8 NVMM_EcuLifeTimeDid1008_Ram[3];
extern uint8 NVMM_EcuLifeTimeDid2008_Ram[3];
extern uint8 NVMM_EcuTimeStampsFromOnKeyDid2009_Ram[2];
extern uint8 NVMM_KeyOnCounterDid200A_Ram[2];
extern uint8 NVMM_EcuTimeFirstDtcDetectionDid200B_Ram[3];
extern uint8 NVMM_EcuTimeFromKeyOnFirstDtcDetectionDid200C_Ram[2];
extern uint8 NVMM_KeyOnCounterStatusDid200F_Ram[1];
extern uint8 NVMM_ProgrammingStatusDid2010_Ram[2];
extern uint8 NVMM_CurrentOdometerDid2001_Ram[2];
extern uint8 NVMM_OdometerWhenSystemUpdatedDid2002_Ram[2];
extern uint8 NVMM_VinCurrDidF1B0_Ram[17];
extern uint8 NVMM_VinOriginDidF190_Ram[17];
extern uint8 NVMM_SwPartNbDidF122_Ram[40];
extern uint8 NVMM_HwPartNbDidF112_Ram[10];
extern uint8 NVMM_AlgoIdNumberDidF1A4_Ram[2];
extern uint8 NVMM_DiagSpecInfoDidF10D_Ram[4];
extern uint8 NVMM_SwSupplierIdentDidF155_Ram[2];
extern uint8 NVMM_HwSupplierIdentDidF154_Ram[2];
extern uint8 NVMM_CodepPartNbDidF187_Ram[11];
extern uint8 NVMM_VhcManufEcuSwCalNbDidF18A_Ram[10];
extern uint8 NVMM_VhcManufEcuSwAppNbDidF18B_Ram[10];
extern uint8 NVMM_EcuSerialNbDidF18C_Ram[15];
extern uint8 NVMM_VhcManufEcuSwNbDidF188_Ram[11];
extern uint8 NVMM_VhcManufEcuHwNbDidF191_Ram[11];
extern uint8 NVMM_EcuHwNbDidF192_Ram[11];
extern uint8 NVMM_SupplierEcuHwVersNbDidF193_Ram[1];
extern uint8 NVMM_EcuSwNbDidF194_Ram[11];
extern uint8 NVMM_EcuSwVersNbDidF195_Ram[2];
extern uint8 NVMM_EcuQualificationDidF10B_Ram[1];
extern uint8 NVMM_EbomEcuPartNumberDidF132_Ram[10];
extern uint8 NVMM_EbomAssemblyPartNumberDidF133_Ram[10];
extern uint8 NVMM_CodepAssemblyPartNumberDidF134_Ram[11];
extern uint8 NVMM_OdoLastClearDtcDid200D_Ram[2];

/*----------------Rom Block Data------------------------*/
extern const uint8 NVMM_SecurityConsLevel_Rom[5];
extern const uint8 NVMM_BootSwIdentDidF180_Rom[14];
extern const uint8 NVMM_AppliSwIdentDidF181_Rom[14];
extern const uint8 NVMM_AppliDataIdentDidF182_Rom[14];
extern const uint8 NVMM_BootSwFingerprintDidF183_Rom[14];
extern const uint8 NVMM_AppliSwFingerprintDidF184_Rom[14];
extern const uint8 NVMM_AppliDataFingerprintDidF185_Rom[14];
extern const uint8 NVMM_ProgrammingAttempsDid2003_Rom[1];
extern const uint8 NVMM_AppSwUpdateAttemptCounterDid201A_Rom[12];
extern const uint8 NVMM_AppDataUpdateAttemptCounterDid201B_Rom[4];
extern const uint8 NVMM_BootSwHashDidD000_Rom[32];
extern const uint8 NVMM_AppSwHashDidD003_Rom[32];
extern const uint8 NVMM_AppDataHashDidD004_Rom[32];
extern const uint8 NVMM_ProgrammingStatusDid2010_Rom[2];
extern const uint8 NVMM_SecurityConsLevel_Rom[5];
extern const uint8 NVMM_BootSwIdentDidF180_Rom[14];
extern const uint8 NVMM_AppliSwIdentDidF181_Rom[14];
extern const uint8 NVMM_AppliDataIdentDidF182_Rom[14];
extern const uint8 NVMM_BootSwFingerprintDidF183_Rom[14];
extern const uint8 NVMM_AppliSwFingerprintDidF184_Rom[14];
extern const uint8 NVMM_AppliDataFingerprintDidF185_Rom[14];
extern const uint8 NVMM_ProgRommingAttempsDid2003_Rom[1];
extern const uint8 NVMM_AppSwUpdateAttemptCounterDid201A_Rom[12];
extern const uint8 NVMM_AppDataUpdateAttemptCounterDid201B_Rom[4];
extern const uint8 NVMM_BootSwHashDidD000_Rom[32];
extern const uint8 NVMM_AppSwHashDidD003_Rom[32];
extern const uint8 NVMM_AppDataHashDidD004_Rom[32];
extern const uint8 NVMM_ProgRommingStatusDid2010_Rom[2];
extern const uint8 NVMM_EcuLifeTimeDid1008_Rom[3];
extern const uint8 NVMM_EcuLifeTimeDid2008_Rom[3];
extern const uint8 NVMM_EcuTimeStampsFromOnKeyDid2009_Rom[2];
extern const uint8 NVMM_KeyOnCounterDid200A_Rom[2];
extern const uint8 NVMM_EcuTimeFirstDtcDetectionDid200B_Rom[3];
extern const uint8 NVMM_EcuTimeFromKeyOnFirstDtcDetectionDid200C_Rom[2];
extern const uint8 NVMM_KeyOnCounterStatusDid200F_Rom[1];
extern const uint8 NVMM_ProgRommingStatusDid2010_Rom[2];
extern const uint8 NVMM_CurrentOdometerDid2001_Rom[2];
extern const uint8 NVMM_OdometerWhenSystemUpdatedDid2002_Rom[2];
extern const uint8 NVMM_VinCurrDidF1B0_Rom[17];
extern const uint8 NVMM_VinOriginDidF190_Rom[17];
extern const uint8 NVMM_SwPartNbDidF122_Rom[40];
extern const uint8 NVMM_HwPartNbDidF112_Rom[10];
extern const uint8 NVMM_AlgoIdNumberDidF1A4_Rom[2];
extern const uint8 NVMM_DiagSpecInfoDidF10D_Rom[4];
extern const uint8 NVMM_SwSupplierIdentDidF155_Rom[2];
extern const uint8 NVMM_HwSupplierIdentDidF154_Rom[2];
extern const uint8 NVMM_CodepPartNbDidF187_Rom[11];
extern const uint8 NVMM_VhcManufEcuSwCalNbDidF18A_Rom[10];
extern const uint8 NVMM_VhcManufEcuSwAppNbDidF18B_Rom[10];
extern const uint8 NVMM_EcuSerialNbDidF18C_Rom[15];
extern const uint8 NVMM_VhcManufEcuSwNbDidF188_Rom[11];
extern const uint8 NVMM_VhcManufEcuHwNbDidF191_Rom[11];
extern const uint8 NVMM_EcuHwNbDidF192_Rom[11];
extern const uint8 NVMM_SupplierEcuHwVersNbDidF193_Rom[1];
extern const uint8 NVMM_EcuSwNbDidF194_Rom[11];
extern const uint8 NVMM_EcuSwVersNbDidF195_Rom[2];
extern const uint8 NVMM_EcuQualificationDidF10B_Rom[1];
extern const uint8 NVMM_EbomEcuPartNumberDidF132_Rom[10];
extern const uint8 NVMM_EbomAssemblyPartNumberDidF133_Rom[10];
extern const uint8 NVMM_CodepAssemblyPartNumberDidF134_Rom[11];
extern const uint8 NVMM_OdoLastClearDtcDid200D_Rom[2];
/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern boolean NVMM_Get_ReadAllFlag(void);
extern void NVMM_Set_ReadAllFlag(boolean flag);
#endif /* NVMM_CONFIG_H */

/* _____ E N D _____ (NVMM_CONFIG_H) _________________________________________*/
