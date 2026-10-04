
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* (c) 2014-2017, Cypress Semiconductor Corporation
* or a subsidiary of Cypress Semiconductor Corporation. All rights
* reserved.
*
* This software, including source code, documentation and related
* materials ( "Software" ), is owned by Cypress Semiconductor
* Corporation or one of its subsidiaries ( "Cypress" ) and is protected by
* and subject to worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ( "EULA" ).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the
* Software source code solely for use in connection with Cypress' s
* integrated circuit products. Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. Cypress reserves the right to make
* changes to the Software without notice. Cypress does not assume any
* liability arising out of the application or use of the Software or any
* product or circuit described in the Software. Cypress does not
* authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ( "High Risk Product" ). By
* including Cypress' s product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/

// Check that necessary definitions are available

#if (!defined(_LINK_flash_)) && (!defined(_LINK_sram_))
  #error "Link location not defined or not supported!"
#endif

#if (!defined(_CORE_cm0plus_)) && (!defined(_CORE_cm4_))
  #error "Target core not defined or not supported!"
#endif

#if (!defined(CY_MCU_rev_a)) && (!defined(CY_MCU_rev_b)) && (!defined(CY_MCU_rev_c))
  #error "MCU revision is not defined or not supported!"
#endif


//=======================================================================================
// Description of special symbols
//=======================================================================================
// sram_private_for_srom:
//     The SROM code needs an area for private data during system call processing. It will
//     not be accessible by user software in protection state NORMAL and beyond.
//     So it needs to be excluded from the total SRAM available to the user. The location of
//     this RAM depends on the MCU revision.
// 
// sram_used_by_boot_base:
//     Cypress (ROM and Flash) boot firmware needs an area in SRAM (e.g. for stack). This may cause issues in case of
//     RAM build configurations when code/const sections are loaded there by the debugger, but may get overwritten
//     if reset is triggered by the debug script later on. So in case of RAM build configurations the linker should
//     check if the area of ROM type sections overlaps the boot area.
// 
// sram_can_lin_boot_reserve:
//     Cypress CAN/LIN Bootloader is entered only if several conditions apply (refer Architecture TRM, "Flash Boot" chapter).
//     It will then use an area of SRAM for its data.
//     This may cause issues in case of RAM build configurations when code/const sections are loaded there by the debugger,
//     but may get overwritten if reset is triggered by the debug script later on. Therefore, this area shall be reserved.
//
// ecc_init_width:
//     Defines the most restrictive native ECC width (in bytes) of all "normal" memories (SRAM, DTCM, ITCM) in any
//     Traveo II derivate in order to keep the startup code dealing with ECC initialization generic


//=======================================================================================
// Following symbol and memory area definitions are used by linker_directives.ld
//=======================================================================================

DEFAULTS
{
    // Constants
    code_flash_start	 = 0x10000000
    code_flash_size      = 1088K       	//Total size of code flash
    code_flash_end		 = 0x1010FFFF 
    ProjectMessage_Size        = 0x20
    
    sram_start = 0x08000000		//Start address of SRAM
    sram_size = 128K			//Total size of SRAM
    sram_end = 0x0801FFFF		//End address of SRAM
    
    sram_used_by_boot_start     = sram_start + sram_size - 6K //0x803E800  Reserve 6K for ROM and FLASH BOOT
    sram_used_by_boot_size 		= 6K
    sram_used_by_boot_end	 	= 0x0801FFFF //End address of SRAM
    
    sram_for_srom_start = 0x08000000			//Regardless of the rev_a/rev_b/rev_c
    sram_for_srom_size  = 2K
    sram_for_srom_END   = sram_for_srom_start + sram_for_srom_size - 1
    
    sram_for_user_start = 0x08000800
    sram_for_user_size  = sram_size - sram_used_by_boot_size - sram_for_srom_size   //120KB
    sram_for_user_end   = 0x801E7FF
        
    cm0plus_intvec_alignment   = 256   // CPU specific vector table alignment requirement
    cm4_intvec_alignment       = 1024  // CPU specific vector table alignment requirement
    ecc_init_width             = 8     
    
    //===================================================================================
    //                              USER CONFIGURATION
    //===================================================================================
  
    // Specify how much SRAM and CODE_FLASH shall be used by CM0+ application,
    // the rest of the memory will be automatically assigned to CM4 application
    cm0plus_sram_start = sram_for_user_start
    cm0plus_sram_size  = 87K - sram_for_srom_size   //85KB for M0,both bootloader and M0 APP
    cm0plus_sram_end   = sram_for_user_start + cm0plus_sram_size - 1	//
    
	
    cm4_sram_start = cm0plus_sram_end + 1  //0x08016000
    cm4_sram_size  = 40K      //no use on bootloader
    cm4_sram_end   = cm4_sram_start + cm4_sram_size -1  ////no use on bootloader

    #if defined(__TVII_FBL__)
    cm0plus_code_flash_start = code_flash_start
    cm0plus_code_flash_size  = 192K //128K->,Just for M0 Bootloader
    cm0plus_code_flash_end   = cm0plus_code_flash_start + cm0plus_code_flash_size - 1  //0x1001FFFF->0x1002 7FFF
    #else
    cm0plus_code_flash_start = code_flash_start + 192K - 1    //0x10020000->0x10028000,reserve 160KB to M0 Bootloader
    cm0plus_code_flash_size  = 576K   //For M0 Updater + M0 APP
    cm0plus_code_flash_end   = cm0plus_code_flash_start + cm0plus_code_flash_size - 1  //0x100BFFFF
    #endif
    
    cm4_code_flash_start = 0x100C0000  //code_flash_start + M0 code
    cm4_code_flash_size  = 192K   //
    cm4_code_flash_end   = cm4_code_flash_start + cm4_code_flash_size - 1  //0x1020FFFF
    
    //-----------------------------------------------------------------------------------

    // Specify stack and heap sizes for CM0+ and CM4 application independently
    cm0plus_heap_size    = 2K//512
    cm0plus_stack_size   = 4K//2K
    
    cm4_heap_size        = 512
    cm4_stack_size       = 1K    
    
    //===================================================================================
    // Map core dependent definition to generic name for memory and section definition
  #if defined(_CORE_cm0plus_)
    heap_reserve               = cm0plus_heap_size
    stack_reserve              = (cm0plus_stack_size + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm0plus_sram_start - sram_start    //start offset address
    sram_reserve               = cm0plus_sram_size     
    code_flash_offset          = cm0plus_code_flash_start - code_flash_start  
    code_flash_reserve         = cm0plus_code_flash_size
    intvec_alignment           = cm0plus_intvec_alignment 

    sram_for_swp1block_start = cm0plus_sram_end + 1	//reserver for the flashdriver
    sram_for_swp1block_size  = 1K
    sram_for_swp1block_END   = sram_for_swp1block_start + sram_for_swp1block_size - 1
	
	  sram_for_flashdriver_start = sram_for_swp1block_END + 1	//reserver for the flashdriver
    sram_for_flashdriver_size  = 36K
    sram_for_flashdriver_END   = sram_for_flashdriver_start + sram_for_flashdriver_size - 1  
  #else // CM4
    heap_reserve               = cm4_heap_size
    stack_reserve              = (cm4_stack_size + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
    sram_offset                = cm4_sram_start - sram_start    //start offset address  
    sram_reserve               = 55K 
    code_flash_offset          = cm4_code_flash_start - code_flash_start   
    code_flash_reserve         = cm4_code_flash_size
    intvec_alignment           = cm4_intvec_alignment

    /* offset, due to BLF porting to CM4 */
    blf_sram_offset             = 30K

    blf_code_flash_offset       = 192K

    sram_for_sbcmdrv_start   = sram_for_user_start + blf_sram_offset + sram_reserve	//reserver for the flashdriver
    sram_for_sbcmdrv_size    = 4K
    sram_for_sbcmdrv_END     = sram_for_sbcmdrv_start + sram_for_sbcmdrv_size - 1

    sram_for_swp1block_start   = sram_for_sbcmdrv_END + 1	//reserver for the flashdriver
    sram_for_swp1block_size    = 1K
    sram_for_swp1block_END     = sram_for_swp1block_start + sram_for_swp1block_size - 1
	
	  sram_for_flashdriver_start = sram_for_swp1block_END + 1	//reserver for the flashdriver
    sram_for_flashdriver_size  = 32K
    sram_for_flashdriver_END   = sram_for_flashdriver_start + sram_for_flashdriver_size - 1
  #endif
    iM0BootEndFlag_size         = 0x10  //define the size of iM0BootEndFlag
    iM0BootVers_size            = 0x30   //Reserver for  Boot Version size
}

// + code_flash_offsets
MEMORY
{
  SRAM                  : ORIGIN = sram_for_user_start + blf_sram_offset,     LENGTH = sram_reserve     //user SRAM
  SBCMDRV               : ORIGIN = sram_for_sbcmdrv_start,                    LENGTH = sram_for_sbcmdrv_size     //user SBCMDRV
  SWP1                  : ORIGIN = sram_for_swp1block_start,      			      LENGTH = sram_for_swp1block_size     //use to SWP1
  FLASHDRV              : ORIGIN = sram_for_flashdriver_start,      			    LENGTH = sram_for_flashdriver_size     //use to flashdrive
	iVect		  		        : ORIGIN = 0x10000000 + blf_code_flash_offset,		    LENGTH = 0x400	//At the start address of user code flash
	iCONST_SW_ID  		    : ORIGIN = 0x10000400 + blf_code_flash_offset, 				LENGTH = 0x400  //MEMENDADDR(iVect) - 1,Current SW's SW ID,after iVect
  CODE_FLASH            : ORIGIN = 0x10000800 + blf_code_flash_offset, 				LENGTH = code_flash_reserve - 0x400 - 0x400 - 16 - 64 - 8K//- iM0BootEndFlag_size - iM0BootVers_size
  VARIANT_DATA          : ORIGIN = 0x1002FFFF + blf_code_flash_offset - 8K, 	LENGTH = 4K //0x100 is reserved for BootEndFlag and BootVers
#if defined(__TVII_FBL__)   
  iM0BootVers           : ORIGIN = 0x1002FFFF + blf_code_flash_offset - iM0BootEndFlag_size - iM0BootVers_size + 1,   LENGTH = iM0BootVers_size
	iM0BootEndFlag		    : ORIGIN = 0x1002FFFF + blf_code_flash_offset- iM0BootEndFlag_size +1,  			                LENGTH = 0x04	//Virtual variable for M0BootEndFlag's address  
	iM4AppEndFlag		      : ORIGIN = 0x1010FFFF - 8K - 0x20 + 1,  			      LENGTH = ProjectMessage_Size //Virtual variable for jump,M4AppEndFlag's address
  iEOLStartFlag		      : ORIGIN = 0x1010FFFF - 8K - 0x20 + 1 + ProjectMessage_Size,  			      LENGTH = 8K
#endif	
	iM0BootEnd			      : ORIGIN = cm0plus_code_flash_end,  		    LENGTH = 0x00	//Must define this
  WORK_FLASH            : ORIGIN = 0x14000000,                      LENGTH = 0x00020000         //  128 KB
  SFLASH                : ORIGIN = 0x17000000,                      LENGTH = 0x00008000         //   32 KB
  SFLASH_ALT            : ORIGIN = 0x17800000,                      LENGTH = 0x00008000         //   32 KB
}


/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* (c) 2014-2017, Cypress Semiconductor Corporation
* or a subsidiary of Cypress Semiconductor Corporation. All rights
* reserved.
*
* This software, including source code, documentation and related
* materials ( "Software" ), is owned by Cypress Semiconductor
* Corporation or one of its subsidiaries ( "Cypress" ) and is protected by
* and subject to worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ( "EULA" ).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the
* Software source code solely for use in connection with Cypress' s
* integrated circuit products. Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. Cypress reserves the right to make
* changes to the Software without notice. Cypress does not assume any
* liability arising out of the application or use of the Software or any
* product or circuit described in the Software. Cypress does not
* authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ( "High Risk Product" ). By
* including Cypress' s product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/

// Check that necessary definitions are available
#if (!defined(_LINK_flash_)) && (!defined(_LINK_sram_))
  #error "Link location not defined or not supported!"
#endif

#if (!defined(_CORE_cm0plus_)) && (!defined(_CORE_cm4_))
  #error "Target core not defined or not supported!"
#endif

//=======================================================================================
// memory_map.ld contains symbol and memory area definitions used by this linker file
//=======================================================================================

//
// Program layout
//
SECTIONS
{

    //============================================================================================================
    // ROM type sections
    //------------------------------------------------------------------------------------------------------------
    
  #if   defined(_LINK_flash_)
    #define MEMORY_FOR_ROM_TYPE_SECTIONS     CODE_FLASH
  #elif defined(_LINK_sram_)
    #define MEMORY_FOR_ROM_TYPE_SECTIONS     SRAM
  #endif  
    

    // Note: .intvec must be the first section in ROM in order for __cmx_vector_base_linker_symbol to be correctly calculated!

    .intvec          ALIGN(intvec_alignment)                     : > iVect
   	.romCONST_SW_ID ROM(.CONST_SW_ID)   						             : > iCONST_SW_ID /* SW configuration header */ 
    .picbase                                                     : > MEMORY_FOR_ROM_TYPE_SECTIONS
    .text                                                        : > .
	  .APWDText       align(4)            						             : > .     /* ApWatchdog Copy Routine */                                                     
	  .APWDEndText    align(4)            						             : > .     /* ApWatchdog Copy End Routine */                                                 
	  .WDTextRom      ROM(.WDText)        						             : > .     /* Watchdog Copy Routine */
	  .RAMCODERom     ROM(.RAMCODE )      						             : > .
    .intercall                                                   : > .
    .interfunc                                                   : > .
    .fixaddr                                                     : > .
    .fixtype                                                     : > .
    .MSR_CONST                                                   : > .
    .secinfo                                                     : > .
    .robase                                                      : > .
    .rodata                                                      : > .
    .ROM.syscall     ROM(.syscall)                               : > .
    .ROM.data        ROM(.data)                                  : > .
    #if defined(__TVII_FBL__)   
    .M0BootVers                                                  :>iM0BootVers 
    .ApplEndFlag 	 		              						                 :>iM0BootEndFlag  /*Current project's end flag*/
    //.M0AppConf													                       :>iM0AppConf 
	  //.M0AppEndFlag 	 		              						             :>iM0AppEndFlag
    //.M4AppConf													                       :>iM4AppConf 
	  .M4AppEndFlag 	 		              						               :>iM4AppEndFlag
    .EOLStartFlag                                                :>iEOLStartFlag
    .variant_data                                                :>VARIANT_DATA
	#endif
  #if defined(_LINK_sram_)
    // Cypress (ROM and Flash) boot firmware needs an area in SRAM (e.g. for stack). This may cause issues in case of
    // RAM build configurations when code/const sections are loaded there by the debugger, but may get overwritten
    // if reset is triggered by the debug script later on. So in case of RAM build configurations the following
    // statement checks if the area of ROM type sections overlaps the boot area.
    // Comment the statement if the sections shall be linked there anyway.
    //
    // A simple check is sufficient because the boot area is from SRAM_MAX-6KB to SRAM_MAX-2KB and it is unlikely that the ROM sections would only
    // start in the last 2KB (which are anyway not accessible in early MCU revisions because of private SROM RAM area)
    //
    // !!! This statement should be the last entry in the ROM type sections !!! (Note: The symbol will not be used, it is just used to implement the error check)
    
    __rom_type_sections_end_address = (. < sram_used_by_boot_base) ? . : error("ROM type sections are overlapping the area used by Cypress boot firmware. Check comment in linker file!");    
  #endif

    //============================================================================================================
    // RAM type sections
    //------------------------------------------------------------------------------------------------------------
    
    // >>> SRAM <<<
    .sram_base       ALIGN(ecc_init_width)                       : > SRAM  
    .pidbase         ALIGN(8)                                    : > .
    .data            ALIGN(8)                                    : > .
    .bss             ALIGN(8)                            CLEAR   : > . // can be changed to NOCLEAR when RAM ECC initialization is enabled in startup_customize.h to improve startup time
    .intvec_ram      ALIGN(intvec_alignment)             NOCLEAR : > .
    .syscall         ALIGN(8)                                    : > .
    .heap            ALIGN(8)                 PAD(heap_reserve)  : > .
    .stack           ALIGN(ecc_init_width)    PAD(stack_reserve) : > .
	  .WDText      	   align(4)            						             : > .     /* Watchdog Copy Routine */
	  /*RAM const*/						                                         
	  .CONST_SW_ID 	   align(4)            						             : > .
	  .BootKeyZone     align(4)            						             : > .
	  .DataBackup      align(4)            						             : > .
	  .MSR_VAR_NO_INIT align(4)            						             : > .
	  .MSR_VAR_INIT    align(4)            						             : > .
	  .RAMCODE         align(4)            						             : > .
    .swp1            ALIGN(4)                                    : > SWP1 
    .flashdriver     ALIGN(4)                                    :  > FLASHDRV  /* Section for Flash driver */

    .SBCMDRV_data_ROM ROM_NOCOPY(.SBCMDRV) : > CODE_FLASH
	  _SBCMDRV_data_ROM_START = ADDR(.SBCMDRV_data_ROM);
	  _SBCMDRV_data_ROM_LIMIT = ENDADDR(.SBCMDRV_data_ROM);
  
	  .SBCMDRV ALIGN(4) :
	  {
	  	. = ALIGN(4);
	  	SbcM.o(.text)
	  	. = ALIGN(4);
	  	spid_tv2.o(.text)
      . = ALIGN(4);
	  	cy_scb_spi.o(.text)
      . = ALIGN(4);
	  	cy_scb_common.o(.text)
	  } > SBCMDRV
  
	  _SBCMDRV_RAM_data_START = ADDR(.SBCMDRV);
	  _SBCMDRV_RAM_data_END = ENDADDR(.SBCMDRV) - 1;
	  _SBCMDRV_RAM_data_LIMIT = ENDADDR(.SBCMDRV);
     
    //============================================================================================================
    // These special symbols mark the bounds of RAM and ROM memory.
    // They are used by the MULTI debugger.
    //------------------------------------------------------------------------------------------------------------
    __ghs_romstart = MEMADDR(iVect);
    __ghs_romend   = MEMENDADDR(SFLASH_ALT);
    __ghs_ramstart = MEMADDR(SRAM);
    __ghs_ramend   = MEMENDADDR(SRAM);

    //============================================================================================================
    // These special symbols help GHS to identify the run type of this build: RAM, ROM, ROM-to-RAM
    //------------------------------------------------------------------------------------------------------------
  #if   defined(_LINK_flash_)
    __ghs_rombootcodestart = 0;
    __ghs_rombootcodeend   = 0;
    __ghs_rambootcodestart = 0;
    __ghs_rambootcodeend   = 0;
  #elif defined(_LINK_sram_)
    __ghs_rombootcodestart = 0;
    __ghs_rombootcodeend   = 0;
    __ghs_rambootcodestart = 0;
    __ghs_rambootcodeend   = 0;
  #endif

    //============================================================================================================
    // The start of CM4 vector table is required by CM0+ application to correctly
    // set CPUSS->CM4_VECTOR_TABLE_BASE register before releasing CM4 from reset
    // Following statements also ensure that the created symbol has the correct alignment
    //------------------------------------------------------------------------------------------------------------
  #ifdef _CORE_cm0plus_
      #if   defined(_LINK_flash_)
        __cm4_rom_start = cm4_code_flash_start;
      #elif defined(_LINK_sram_)
        __cm4_rom_start = MEMADDR(SRAM)       - cm0plus_sram_offset       + cm4_sram_offset;
      #endif
   // __cm4_vector_base_linker_symbol = (__cm4_rom_start + cm4_intvec_alignment - 1) & ~(cm4_intvec_alignment - 1);      
  #endif

    //============================================================================================================
    // These symbols will be used by startup.c / startup_customize.h for RAM ECC initialisation
    //------------------------------------------------------------------------------------------------------------
  #if defined(_LINK_sram_)
    // If "ROM type" sections are linked to SRAM they shall not be cleared by the startup code
    __ecc_init_sram_start_address = ADDR(.sram_base); // The empty .sram_base section is a marker for the start of "RAM type" sections in SRAM
  #else
    __ecc_init_sram_start_address = MEMADDR(SRAM);
  #endif
    __ecc_init_sram_end_address   = MEMENDADDR(SRAM) - 1;
    

}


OPTION("-Lblf/core_blf/src_platform/cdd/TVII_SDL/tviibe1m/src/drivers/crypto/libs")
#ifdef _CORE_cm0plus_
OPTION("-lcrypto_server_cm0plus_ghs")
#endif
#ifdef _CORE_cm4_
//OPTION("-lcrypto_client_cm4_ghs")
#endif




