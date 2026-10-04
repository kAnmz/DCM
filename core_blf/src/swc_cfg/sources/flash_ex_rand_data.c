/******************************************************************************/
/* @F_NAME:          flash_ex_rand_data.c                                     */
/* @F_PURPOSE:       flash_ex_rand_data                                       */
/* @F_CREATED_BY:                                                             */
/* @F_CREATION_DATE: 22/06/2004                                               */
/* @F_LANGUAGE:      ANSI C                                                   */
/* @F_MPROC_TYPE:    target dependent                                         */
/************************************** (C) Copyright 2004 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_flash.h"
#include "cy_mw_flash.h"
#include "flash_ex_rand_data.h"


/*______ L O C A L - D E F I N E S ___________________________________________*/


/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/



/*______ L O C A L - F U N C T I O N S _______________________________________*/
// In this routine, whole one sector erased/written/read/verified
void BasicWorkFlashBlockingTest(uint32_t SectorAddr, uint32_t SectorSizeInByte)
{
    uint32_t* p_TestFlsTop = (uint32_t*)SectorAddr;

    uint32_t SectorSizeInWord = SectorSizeInByte / 4ul;

    /** Erasing **/
    // Erase
    Cy_FlashSectorErase(SectorAddr, CY_FLASH_DRIVER_BLOCKING);

    // Verify
    Cy_WorkFlashBlankCheck(SectorAddr, CY_FLASH_DRIVER_BLOCKING);

    /** Programming **/
    for(uint32_t i_addr = SectorAddr, i_addrOffset = 0; i_addr < SectorAddr + SectorSizeInByte; i_addr+=4, i_addrOffset+=4)
    {
        uint32_t i_dataPos = i_addrOffset % PROGRAM_DATA_SIZE_IN_BYTE;

        // Flash
        Cy_FlashWriteWork(i_addr, (uint32_t*)&programData[i_dataPos], CY_FLASH_DRIVER_BLOCKING);
    }

    // Verify
    uint32_t* pProgramData = (uint32_t*)programData;
    for(uint32_t i_wordId = 0; i_wordId < SectorSizeInWord; i_wordId++)
    {
        uint32_t i_dataPos = i_wordId % PROGRAM_DATA_SIZE_IN_WORD;
        CY_ASSERT(p_TestFlsTop[i_wordId] == pProgramData[i_dataPos]);
    }

    /** Erasing Again **/
    // Erase
    Cy_FlashSectorErase(SectorAddr, CY_FLASH_DRIVER_BLOCKING);

    // Verify
    Cy_WorkFlashBlankCheck(SectorAddr, CY_FLASH_DRIVER_BLOCKING);
}

/*______ E N D _____ (flash_ex_rand_data.c) _________________________________________*/
