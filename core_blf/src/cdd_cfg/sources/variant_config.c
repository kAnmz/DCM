/******************************************************************************/
/* @F_NAME :          variant_config.c                                        */
/* @F_PURPOSE :       Variant data slot table                                 */
/* @F_LANGUAGE :      ANSI - C                                                */
/* @F_MPROC_TYPE :    RH850                                                   */
/*************************************** (C) Copyright 2009 Magneti Marelli ***/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "variant_config.h"

/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
/*
 * Variant payload.
 *
 * This file is deliberately variant-agnostic: no DCU_FL / DCU_FR / DCU_RL /
 * DCU_RR conditional appears here, and every slot is built with a zero
 * placeholder. The content that differs per variant is written into the
 * .variant_data region when the binaries are merged, so a single build output
 * serves as the base for all variants.
 *
 * Slot map (index -> meaning -> length written by the merge step):
 *   56  SBL diagnostic database part number   8
 *   57  SBL software version number           7
 *   58  PBL diagnostic database part number   5
 *   59  PBL software diagnostic DB part no.   5
 *   60  ECU core ASM part number              5
 *   61  ECU delivery ASM part number          5
 *   62  BLF boot version                       3
 *   63  BLF variant tag / boot end flag        2
 *
 * Only the len field has to match the payload the merge step writes; keep the
 * table and the merge tool in sync when a slot is added or resized.
 */
#pragma ghs section rodata=".variant_data"
#pragma ghs startdata
volatile const Variant_Slot_t Variant_Data[VARIANT_SLOT_COUNT] =
{
    [VARIANT_DATA_SBL_DIAG_DB_PART_NUMBER]       = { .len = 0U, .data = {0} },
    [VARIANT_DATA_SBL_SW_VERSION_NUMBER]         = { .len = 0U, .data = {0} },
    [VARIANT_DATA_DIAG_PBL_DIAG_DATABASE_PN]     = { .len = 0U, .data = {0} },
    [VARIANT_DATA_DIAG_PBL_SOFT_DIAG_DATABASE_PN]= { .len = 0U, .data = {0} },
    [VARIANT_DATA_DIAG_ECU_CORE_ASM_PN]          = { .len = 0U, .data = {0} },
    [VARIANT_DATA_DIAG_ECU_DELI_ASM_PN]          = { .len = 0U, .data = {0} },
    [VARIANT_DATA_BOOT_VESRION]                  = { .len = 0U, .data = {0} },
    [VARIANT_DATA_BOOT_END_FLAG]                 = { .len = 0U, .data = {0} },
};
#pragma ghs enddata
#pragma ghs section

/*______ P R I V A T E - D A T A _____________________________________________*/

/*______ L O C A L - D A T A _________________________________________________*/

/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (variant_config.c) ______________________________________*/