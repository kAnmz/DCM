/******************************************************************************/
/* @F_NAME:           variant_config.h                                        */
/* @F_PURPOSE:        export for variant data module                          */
/* @F_MPROC_TYPE:     RH850                                                   */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifndef VARIANT_CONFIG_H
#define VARIANT_CONFIG_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "Platform_types.h"

/*_____ G L O B A L - D E F I N E ____________________________________________*/

/*
 * Variant data slots, reserved totally 4K (= VARIANT_DATA region size).
 *
 * Slots are fixed size so that a slot can be located directly by its index:
 *     slot N address = base + N * VARIANT_SLOT_SIZE
 * Each slot carries its own valid length, so a reader need not know the
 * payload size of every slot in advance.
 */
#define VARIANT_SLOT_SIZE  (64U)
#define VARIANT_SLOT_COUNT (64U)
#define VARIANT_DATA_MAX   (VARIANT_SLOT_SIZE - 1U)   /* 63 bytes payload + 1 byte len */

/*_____ G L O B A L - T Y P E S ______________________________________________*/

/* Slot index of each entry in Variant_Data[] */
typedef enum {
    VARIANT_DATA_SBL_DIAG_DB_PART_NUMBER = 56,
    VARIANT_DATA_SBL_SW_VERSION_NUMBER = 57,
    VARIANT_DATA_DIAG_PBL_DIAG_DATABASE_PN = 58,
    VARIANT_DATA_DIAG_PBL_SOFT_DIAG_DATABASE_PN = 59,
    VARIANT_DATA_DIAG_ECU_CORE_ASM_PN = 60,
    VARIANT_DATA_DIAG_ECU_DELI_ASM_PN = 61,
    VARIANT_DATA_BOOT_VESRION = 62,
    VARIANT_DATA_BOOT_END_FLAG = 63,
}Variant_Data_Type;

typedef struct
{
    ubyte len;                      /* number of valid bytes in data[] */
    ubyte data[VARIANT_DATA_MAX];   /* payload */
} Variant_Slot_t;                   /* total = VARIANT_SLOT_SIZE = 64 bytes */

/*_____ G L O B A L - D A T A ________________________________________________*/

extern volatile const Variant_Slot_t Variant_Data[VARIANT_SLOT_COUNT];

#endif /* VARIANT_CONFIG_H */