/******************************************************************************/
/*@F_NAME:          wdtd.c                                                    */
/*@F_PURPOSE:       Watchdog driver module                                    */
/*@F_CREATED_BY:    Olivier DIETLIN                                           */
/*@F_CREATION_DATE: 16/06/2014                                                */
/*@F_MPROC_TYPE:    IMX6x                                                     */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#if 1/*defined(__FSL_IMX6x__)*/



/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
/*ZeeKr TestCODE*/
#if 0 /*def __GHOS__*/
#include "wdtd.h"


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

MemoryRegion WDTD_MemoryRegion;
MemoryRegion WDTD_VirtualMemoryRegion;
MemoryRegion WDTD_SrcMemoryRegion;
MemoryRegion WDTD_SrcVirtualMemoryRegion;


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/*Name : WDTD_Init                                                            */
/*Role : this function initialises the WDOG driver                            */
/*Interface :     void                                                        */
/*Pre-condition : none                                                        */
/*Constraints :   none                                                        */
/*Behaviour :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/******************************************************************************/
void WDTD_Init(void)
{
#if 0
  Value Attr;
  Address Start;
  Address Last;

  /* Map in WDOG1 registers */
  CheckSuccess(RequestResource((Object*)&WDTD_MemoryRegion, "WDTD_MemoryArea", "!systempassword"));
  CheckSuccess(GetMemoryRegionAddresses(WDTD_MemoryRegion, &Start, &Last));
  /* Request a virtual memory region at the same address as the physical one */
  CheckSuccess(AllocateMemoryRegion(__ghs_VirtualMemoryRegionPool, WDOG1_BASE_ADDR_ASM, WDOG1_BASE_ADDR_ASM + Last - Start, &WDTD_VirtualMemoryRegion));
  CheckSuccess(GetMemoryRegionAttributes(WDTD_MemoryRegion, &Attr));
  CheckSuccess(SetMemoryRegionAttributes(WDTD_VirtualMemoryRegion, Attr));
  CheckSuccess(MapMemoryRegion(WDTD_VirtualMemoryRegion, WDTD_MemoryRegion));

  /* Map in SRC registers */
  CheckSuccess(RequestResource((Object*)&WDTD_SrcMemoryRegion, "WDTD_SrcMemoryArea", "!systempassword"));
  CheckSuccess(GetMemoryRegionAddresses(WDTD_SrcMemoryRegion, &Start, &Last));
  /* Request a virtual memory region at the same address as the physical one */
  CheckSuccess(AllocateMemoryRegion(__ghs_VirtualMemoryRegionPool, SRC_BASE_ADDR_ASM, SRC_BASE_ADDR_ASM + Last - Start, &WDTD_SrcVirtualMemoryRegion));
  CheckSuccess(GetMemoryRegionAttributes(WDTD_SrcMemoryRegion, &Attr));
  CheckSuccess(SetMemoryRegionAttributes(WDTD_SrcVirtualMemoryRegion, Attr));
  CheckSuccess(MapMemoryRegion(WDTD_SrcVirtualMemoryRegion, WDTD_SrcMemoryRegion));

  TARG_WriteShort(WDOG1_WMCR, 0x0000);
  TARG_WriteShort(WDOG1_WCR,  WDOG_WCR_CONFIG);
  TARG_WriteShort(WDOG1_WICR, WDOG_MSK_WICR_WTIS);

  TARG_WriteLong(SRC_SCR,    (TARG_ReadLong(SRC_SCR)     |
                              SRC_MSK_SRC_MASK_WDOG_RST1 |
                              SRC_MSK_SRC_MASK_WDOG_RST3  ) );
#endif
}

#endif /* __GHOS__ */

#endif /* __FSL_IMX6x__ */

/* _____ E N D _____ (wdtd.c) ________________________________________________*/
