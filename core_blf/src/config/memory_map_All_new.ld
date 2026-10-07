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

/* ==========================================================================
 * memory_map_All_new.ld
 *
 * 相对于 memory_map_All.ld 的改动：
 *
 *   [Q1] CODE_FLASH 长度不再沿用 CM0+ 的 576K，改为止于 VARIANT_DATA 之前。
 *        原值使代码区越出 BLF 段 384K，把 VARIANT_DATA 及尾部标记块包进了
 *        代码区内部。
 *
 *   [Q2] 原尾部标记块（boot 版本、变体标记）的 LENGTH 与 ORIGIN 已随其迁入
 *        Variant_Data（variant_config.c）而一并移除。
 *
 *   命名约定：
 *     - 地址/尺寸变量 <name>_start / _size / _end，_end 表示最后一个有效字节
 *     - 按归属方命名：BLF 侧定义/生产的用 blf_*，APP 侧定义/生产的用 app_*
 * ========================================================================== */

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
// sram_for_srom:   SROM private data during system calls; not accessible to user code.
//                  Location depends on the MCU revision.
// sram_used_by_boot: 上游 SDL 模板的预留声明，针对 RAM 构建 + 调试器场景。
//                  本项目未使用该区域，且无任何消费者；保留仅为与模板一致
//                  并供下方 _LINK_sram_ 检查引用。不要当作 BLF 的 SRAM 边界。
// sram_for_swp1block / sram_for_flashdriver: flash-driver work areas.
// ecc_init_width:  most restrictive native ECC width of all normal memories
//                  (SRAM/DTCM/ITCM), so ECC init code stays generic.


//=======================================================================================
// Following symbol and memory area definitions are used by linker_directives.ld
//=======================================================================================

DEFAULTS
{
    // -----------------------------------------------------------------------------------
    // Device memory
    // -----------------------------------------------------------------------------------
    code_flash_start = 0x10000000
    code_flash_size  = 1088K        // Total size of code flash
    code_flash_end   = 0x1010FFFF

    sram_start = 0x08000000         // Start address of SRAM
    sram_size  = 128K               // Total size of SRAM
    sram_end   = 0x0801FFFF         // End address of SRAM

    // ===================================================================================
    // PROGRAM LAYOUT
    // -----------------------------------------------------------------------------------
    // 三个程序，按【程序】而非【核】命名 —— 因为 CM4 上跑两个程序，核名无法区分：
    //
    //   HSM  CM0+   安全/刷写，启动 CM4，常驻
    //   BLF  CM4    bootloader，跳转到 APP 后不再返回
    //   APP  CM4    应用，BLF 跳转后接管
    //
    // BLF 与 APP 在 CM4 上【分时复用】同一块 SRAM：BLF 经 JUMP_TO_APPLICATION
    // 交接给 APP（见 star_app.arm，从 0x10060000 取 APP 向量表）后不再运行。
    // 任一时刻只有一方占有 SRAM。
    //
    //   CODE FLASH  0x10000000 .. 0x1010FFFF  (1088K)
    //     0x10000000 .. 0x1002FFFF   HSM   192K
    //     0x10030000 .. 0x1005FFFF   BLF   192K
    //     0x10060000 .. 0x1010FFFF   APP   704K
    //
    //   SRAM        0x08000000 .. 0x0801FFFF  (128K)
    //     0x08000000 .. 0x080007FF   SROM private      2K   (not usable)
    //     0x08000800 .. 0x08007FFF   HSM              30K
    //     0x08008000 .. 0x0801E7FF   BLF / APP        ~90K  (time-multiplexed)
    //     0x0801E800 .. 0x0801FFFF   handoff + boot    6K
    // ===================================================================================

    // -----------------------------------------------------------------------------------
    // Global reservations (device-wide, not owned by any program)
    // -----------------------------------------------------------------------------------
    // 上游 SDL 模板的预留声明，本项目完全未使用该区域，也无任何消费者。
    // 保留仅为与 SDL 模板保持一致。不要当作 BLF 的 SRAM 边界。
    sram_used_by_boot_start = sram_start + sram_size - 6K   // = 0x0801E800
    sram_used_by_boot_size  = 6K
    sram_used_by_boot_end   = sram_start + sram_size - 1    // = 0x0801FFFF

    // 注意：SRAM 尾部另有一批 BLF/APP 按绝对地址共用的单元，它们来自源码里的
    // 裸地址，与上面的模板预留无定义关系，调整 SRAM 布局时需避开其中跨跳转存活的：
    //   BootCommand @0x0801F200   (blf: fblm_main.c / app: diag.c)
    //   WDMsg       @0x0801F208   (blf: SbcM.c / app: sbcc_watchdog.c)
    // 另有仅在刷写会话内使用的临时位置（用完即弃，不跨跳转）：
    //   FlashDrv VBT @0x0801F100  (44B 校验块表，见 rsam.c)

    sram_for_srom_start = 0x08000000    // Same for rev_a / rev_b / rev_c
    sram_for_srom_size  = 2K
    sram_for_srom_end   = sram_for_srom_start + sram_for_srom_size - 1

    // 第一个可用 SRAM 地址，紧接 SROM 私有区之后
    sram_for_user_start = 0x08000800

    // Vector table alignment requirements
    // app_intvec_alignment applies to both CM4 programs (BLF and APP).
    app_intvec_alignment = 1024
    ecc_init_width       = 8

    // ===================================================================================
    //                              PROGRAM PARTITION
    // -----------------------------------------------------------------------------------
    // Only BLF is built from this file. HSM and APP are described here purely to record
    // the partition, so read this section as: BLF's own figures plus the neighbours that
    // bound them. Nothing below is placed inside the HSM or APP areas.
    //
    // Only the _size values are meant to be tuned; every _end and derived figure follows.
    // ===================================================================================

    // ---- HSM : CM0+ ----  (boundary reference; HSM has its own linker file)
    hsm_code_flash_start = code_flash_start
    hsm_code_flash_size  = 192K
    hsm_code_flash_end   = hsm_code_flash_start + hsm_code_flash_size - 1

    hsm_sram_start = sram_for_user_start
    hsm_sram_size  = 30K
    hsm_sram_end   = hsm_sram_start + hsm_sram_size - 1

    // ---- BLF : CM4 ----  (this build)
    blf_code_flash_size = 192K
    blf_sram_size       = 55K           // 主 SRAM 区，不含后面 SBCMDRV/SWP1/FLASHDRV

    // BLF 紧接 HSM 之后；不得越出自身 192K，其余归 APP
    blf_code_flash_start = hsm_code_flash_end + 1        // = 0x10030000
    blf_code_flash_end   = blf_code_flash_start + blf_code_flash_size - 1

    // BLF 与 APP 分时复用 SRAM：地址重叠是有意的，两者不同时运行。
    // 二者可用区间相同，故不设人为上界 —— 各 region 由起点依次串联。
    blf_sram_start = hsm_sram_end + 1                    // = 0x08008000

    // ---- APP : CM4 ----  (boundary reference; APP has its own linker file)
    app_code_flash_start = blf_code_flash_end + 1        // = 0x10060000
    app_code_flash_end   = code_flash_end
    app_code_flash_size  = app_code_flash_end - app_code_flash_start + 1   // = 704K

    app_sram_start = hsm_sram_end + 1                    // = 0x08008000 (同 BLF)

    // -----------------------------------------------------------------------------------
    // Stack and heap sizes
    // -----------------------------------------------------------------------------------
    blf_heap_size  = 512
    blf_stack_size = 1K

    // 栈大小需向上对齐到 ECC 宽度
    blf_stack_reserve = (blf_stack_size + (ecc_init_width - 1)) & (~((ecc_init_width - 1)))

    // -----------------------------------------------------------------------------------
    // 标记块尺寸
    // -----------------------------------------------------------------------------------
    // .M4AppEndFlag / app_end_flag：应用结束标记块，**内容由 APP 写入，BLF 只读**。
    //   fblm_config.c 按字节读取，最大下标 31，故必须保持 0x20（下标 0..31）：
    //        [5]=='E' [6]=='F'      版本标记
    //        [13]=='W' [14]=='D'    软硬件版本匹配
    //        [16] [17]              与 BLF 变体标记比较
    //        [25..27]=="End"        结束标记
    //        [28..31] / [28..29]    CRC32 / CRC16 校验和
    //   注：旧名 ProjectMessage_Size 有误导，它与 main_cm0plus.c 的 .ProjectMessage 段无关。
    app_end_flag_size = 0x20

    // 注：BLF 自己的 boot 版本与变体标记已迁入 Variant_Data
    //     （variant_config.c），不再占用独立 region。

    // -----------------------------------------------------------------------------------
    // BLF 段内的子块划分（192K）
    //
    //   0x10030000  1K     blf_ivect      .. 向量表
    //   0x10030400  ...    blf_code       .. 代码 / rodata
    //   0x1005DFFF  4K     VARIANT_DATA   .. 变体数据（含 boot 版本与变体标记）
    //   0x1005EFFF ..      (未使用)
    //   0x1005FFFF         blf_code_flash_end
    //
    // MEMORY{} 只引用符号，不引用 region 名（同块内 region 名参与运算不保证可解析）。
    // -----------------------------------------------------------------------------------

    // Vector table, 1K aligned (app_intvec_alignment = 1024)
    blf_ivect_start = blf_code_flash_start
    blf_ivect_size  = 0x400
    blf_ivect_end   = blf_ivect_start + blf_ivect_size - 1

    // Code region starts right after the vector table
    blf_code_start = blf_ivect_end + 1

    // Variant data, anchored to the END of the BLF region
    blf_variant_size  = 4K
    blf_variant_start = blf_code_flash_end - 8K
    blf_variant_end   = blf_variant_start + blf_variant_size - 1

    // Code region stops right before the variant data
    blf_code_end  = blf_variant_start - 1
    blf_code_size = blf_code_end - blf_code_start + 1

    // Message / EOL blocks, anchored to the END of the device code flash
    // 内容由 APP 写入，BLF 只读
    app_end_flag_start = code_flash_end - 8K - app_end_flag_size + 1
    app_eol_data_start = app_end_flag_start + app_end_flag_size

    // ---- BLF SRAM regions ----
    sram_for_sbcmdrv_start = blf_sram_start + blf_sram_size
    sram_for_sbcmdrv_size  = 4K
    sram_for_sbcmdrv_end   = sram_for_sbcmdrv_start + sram_for_sbcmdrv_size - 1

    sram_for_swp1block_start = sram_for_sbcmdrv_end + 1
    sram_for_swp1block_size  = 1K
    sram_for_swp1block_end   = sram_for_swp1block_start + sram_for_swp1block_size - 1

    sram_for_flashdriver_start = sram_for_swp1block_end + 1
    sram_for_flashdriver_size  = 32K
    sram_for_flashdriver_end   = sram_for_flashdriver_start + sram_for_flashdriver_size - 1
}


//=======================================================================================
// MEMORY
//=======================================================================================

MEMORY
{
    // -----------------------------------------------------------------------------------
    // SRAM regions
    // -----------------------------------------------------------------------------------
    SRAM     : ORIGIN = blf_sram_start,                        LENGTH = blf_sram_size                // BLF(CM4) main SRAM
    SBCMDRV  : ORIGIN = sram_for_sbcmdrv_start,                LENGTH = sram_for_sbcmdrv_size        // BLF(CM4) SBC driver
    SWP1     : ORIGIN = sram_for_swp1block_start,              LENGTH = sram_for_swp1block_size      // BLF(CM4) SWP1 block
    FLASHDRV : ORIGIN = sram_for_flashdriver_start,            LENGTH = sram_for_flashdriver_size    // BLF(CM4) flash driver

    // -----------------------------------------------------------------------------------
    // BLF 代码 flash 区，192K，起点 blf_code_flash_start (0x10030000)
    //
    // ORIGIN/LENGTH 全部引用 DEFAULTS 符号，地址集中在一处可查。
    //
    // [Q3] 原 iCONST_SW_ID 区已删除，1K 并入代码区。经查该区功能上是死的：
    //      .CONST_SW_ID 的 pragma 被注释（syst.c:336-337）；SYST_SwIdentifier 的
    //      初始化被 #if 0 包住只剩 NULL（syst.c:348-366）；SYST_GetSwPartIdent()
    //      因 SYST_SW_IDENT_TABLE_USED 未定义而未编译；SYST_APP_SW_ID_ADDR 无引用。
    //      该删除需配合 C 侧改动，见文件末尾说明。
    //
    // [Q1] CODE_FLASH 以 BLF 段为界，止于 VARIANT_DATA 之前；原文件误用
    //      CM0+ 的 576K（code_flash_reserve）致其越界 384K，覆盖了 VARIANT_DATA
    //      及当时的尾部标记块。
    //      新写法改为由边界反推，故不再需要 code_flash_reserve。
    // -----------------------------------------------------------------------------------
    iVect        : ORIGIN = blf_ivect_start,     LENGTH = blf_ivect_size
    VARIANT_DATA : ORIGIN = blf_variant_start,   LENGTH = blf_variant_size
    CODE_FLASH   : ORIGIN = blf_code_start,      LENGTH = blf_code_size

#if defined(__TVII_FBL__)
    // APP 自有：BLF 只读，内容由 APP 写入
    app_end_flag  : ORIGIN = app_end_flag_start,  LENGTH = app_end_flag_size
    app_eol_data  : ORIGIN = app_eol_data_start,  LENGTH = 8K
#endif

    // -----------------------------------------------------------------------------------
    // Auxiliary flash
    // -----------------------------------------------------------------------------------
    WORK_FLASH : ORIGIN = 0x14000000, LENGTH = 0x00020000    // 128 KB
    SFLASH     : ORIGIN = 0x17000000, LENGTH = 0x00008000    //  32 KB
    SFLASH_ALT : ORIGIN = 0x17800000, LENGTH = 0x00008000    //  32 KB
}


//=======================================================================================
// Program layout
//=======================================================================================
SECTIONS
{
    //====================================================================================
    // ROM type sections
    //------------------------------------------------------------------------------------
  #if   defined(_LINK_flash_)
    #define MEMORY_FOR_ROM_TYPE_SECTIONS     CODE_FLASH
  #elif defined(_LINK_sram_)
    #define MEMORY_FOR_ROM_TYPE_SECTIONS     SRAM
  #endif

    // Note: .intvec must be the first section in ROM in order for
    //       __cmx_vector_base_linker_symbol to be correctly calculated!

    .intvec                                                  : > iVect
    // [Q3] 原 ".romCONST_SW_ID ROM(.CONST_SW_ID) : > iCONST_SW_ID" 随之删除：
    //      源段 .CONST_SW_ID 为空（pragma 被注释），从未产生数据。
    .picbase                                                 : > MEMORY_FOR_ROM_TYPE_SECTIONS
    .text                                                    : > .
    .APWDText        ALIGN(4)                                : > .   /* ApWatchdog Copy Routine */
    .APWDEndText     ALIGN(4)                                : > .   /* ApWatchdog Copy End Routine */
    .WDTextRom       ROM(.WDText)                            : > .   /* Watchdog Copy Routine */
    .RAMCODERom      ROM(.RAMCODE)                           : > .
    .intercall                                               : > .
    .interfunc                                               : > .
    .fixaddr                                                 : > .
    .fixtype                                                 : > .
    .MSR_CONST                                               : > .
    .secinfo                                                 : > .
    .robase                                                  : > .
    .rodata                                                  : > .
    .ROM.syscall     ROM(.syscall)                           : > .
    .ROM.data        ROM(.data)                              : > .

    #if defined(__TVII_FBL__)
    // APP 自有的段：段名保持原样（生产者在 APP 工程），仅 region 名按归属方命名
    .M4AppEndFlag  : > app_end_flag
    .EOLStartFlag  : > app_eol_data

    .variant_data  : > VARIANT_DATA
    #endif

  #if defined(_LINK_sram_)
    // 上游模板自带检查，仅 RAM 构建有意义：调试器把 ROM type sections 载入 SRAM 时，
    // 若与 boot 固件所用区域重叠，复位后可能被覆盖。BLF 为 _LINK_flash_，不生效。
    //
    // !!! This statement should be the last entry in the ROM type sections !!!

    __rom_type_sections_end_address = (. < sram_used_by_boot_start) ? . : error("ROM type sections are overlapping the area used by Cypress boot firmware. Check comment in linker file!");
  #endif

    //====================================================================================
    // RAM type sections
    //------------------------------------------------------------------------------------

    // >>> SRAM <<<
    .sram_base       ALIGN(ecc_init_width)                       : > SRAM
    .pidbase         ALIGN(8)                                    : > .
    .data            ALIGN(8)                                    : > .
    .bss             ALIGN(8)                            CLEAR   : > .   // can be changed to NOCLEAR when RAM ECC initialization is enabled in startup_customize.h to improve startup time
    .intvec_ram      ALIGN(app_intvec_alignment)                 NOCLEAR : > .
    .syscall         ALIGN(8)                                    : > .
    .heap            ALIGN(8)                 PAD(blf_heap_size)      : > .
    .stack           ALIGN(ecc_init_width)    PAD(blf_stack_reserve)  : > .
    .WDText          ALIGN(4)                                    : > .   /* Watchdog Copy Routine */

    /* RAM const */
    .CONST_SW_ID     ALIGN(4)                                    : > .
    .BootKeyZone     ALIGN(4)                                    : > .
    .DataBackup      ALIGN(4)                                    : > .
    .MSR_VAR_NO_INIT ALIGN(4)                                    : > .
    .MSR_VAR_INIT    ALIGN(4)                                    : > .
    .RAMCODE         ALIGN(4)                                    : > .

    .swp1            ALIGN(4)                                    : > SWP1
    .flashdriver     ALIGN(4)                                    : > FLASHDRV    /* Section for Flash driver */

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
    _SBCMDRV_RAM_data_END   = ENDADDR(.SBCMDRV) - 1;
    _SBCMDRV_RAM_data_LIMIT = ENDADDR(.SBCMDRV);

    //====================================================================================
    // These special symbols mark the bounds of RAM and ROM memory.
    // They are used by the MULTI debugger.
    //------------------------------------------------------------------------------------
    __ghs_romstart = MEMADDR(iVect);
    __ghs_romend   = MEMENDADDR(SFLASH_ALT);
    __ghs_ramstart = MEMADDR(SRAM);
    __ghs_ramend   = MEMENDADDR(SRAM);

    //====================================================================================
    // These special symbols help GHS to identify the run type of this build: RAM, ROM, ROM-to-RAM
    //------------------------------------------------------------------------------------
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

    //====================================================================================
    // These symbols will be used by startup.c / startup_customize.h for RAM ECC initialisation
    //------------------------------------------------------------------------------------
  #if defined(_LINK_sram_)
    // If "ROM type" sections are linked to SRAM they shall not be cleared by the startup code
    __ecc_init_sram_start_address = ADDR(.sram_base);   // The empty .sram_base section is a marker for the start of "RAM type" sections in SRAM
  #else
    __ecc_init_sram_start_address = MEMADDR(SRAM);
  #endif
    __ecc_init_sram_end_address   = MEMENDADDR(SRAM) - 1;
}


OPTION("-Lblf/core_blf/src_platform/cdd/TVII_SDL/tviibe1m/src/drivers/crypto/libs")


/* ==========================================================================
 * [Q3] 删除 iCONST_SW_ID 后必须同步的 C 侧改动
 * ==========================================================================
 * 删除 .romCONST_SW_ID 后链接器不再生成 __ghsbegin_romCONST_SW_ID /
 * __ghsend_romCONST_SW_ID，而 cpus_rh850.c 仍引用它们，链接会失败。
 * 需删除该文件以下两处（该循环只拷贝 NULL，从未承载数据）：
 *
 *   blf/core_blf/src_platform/cdd/CPUS/Sources/cpus_rh850.c
 *     第 93-96 行    extern 声明
 *     第 146-158 行  CPUS_InitRam() 内的拷贝循环
 *
 * 注：__ghsbegin_CONST_SW_ID 是 RAM 侧符号。SECTIONS 中 RAM 侧的
 *     ".CONST_SW_ID : > ." 保留即可，去掉上述循环便能正常链接。
 * ========================================================================== */