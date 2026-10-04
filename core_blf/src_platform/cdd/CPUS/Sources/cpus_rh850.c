/******************************************************************************/
/* @F_NAME :          cpus.c                                                  */
/* @F_PURPOSE :       Processor core set up                                   */
/* @F_CREATED_BY :    S.BOUGUYON                                              */
/* @F_CREATION_DATE : 31/03/2004                                              */
/* @F_LANGUAGE :      C                                                       */
/* @F_MPROC_TYPE:     MC9S08xx , V850 Dx3, Renesas RL78                       */
/*************************************** (C) Copyright 2013 Magneti Marelli ***/

/* _____ I N C L U D E - F I L E S ___________________________________________*/
#if defined(__RH850__)
#ifndef __BOOT_LINK__
#include "targ.h"
#endif
#include "syst.h"
#include "cpus.h"
#ifndef __BOOT_LINK__
#include "wdtd.h"
#include "vers_config.h"
#include "iodc_priv.h"
#include "iodc_config.h"
#include "iodc.h"
#endif
#endif
/*
 * shubin.liang
 * disabled watchdog for porting
 * watchdog will be enabled later, when watchdog module is ported
 * because cpus have to feed watchdog during clock tree init
#include "wdtd.h"
 * */


#if defined(__RH850__)

/* _____ L O C A L - D E F I N E _____________________________________________*/

#define CPUS_RAM_CHECKSUM_1    (0xFFFFC000u)  /*All 1 checksum*/
#define CPUS_RAM_CHECKSUM_0    (0x0)        /*All 0 checksum*/

#ifndef CPUS_ENSUBOSC_TIMEOUT
#define CPUS_ENSUBOSC_TIMEOUT  500000u
#endif
#define  CLK_CONFIG_TIMEOUT  2000u
/* _____ L O C A L - T Y P E S _______________________________________________*/

static bool_t CPUS_EnSubOscTimeoutFlag = FALSE;

/* _____ G L O B A L - D A T A _______________________________________________*/


/* _____ L O C A L - D A T A _________________________________________________*/


/* _____ L O C A L - M A C R O S _____________________________________________*/


/* _____ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/* _____ G L O B A L - F U N C T I O N S _____________________________________*/

#if defined(__RH850_F1x__)

#if (defined(__RH850_F1L__) || defined(__RH850_F1K__))

/*----------------------------------------------------------------------------*/
/* Name : CPUS_ClockSelectorConfig                                            */
/* Role : Set clocks selector for each supported clock domain                 */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*----------------------------------------------------------------------------*/
#ifdef __RH850_F1K__

typedef enum
{
  PPLLCLK_CKS_NULL = 0u,
  PPLLCLK_CKS_EMCLK = 1u,
  PPLLCLK_CKS_MOSC = 2u,
  PPLLCLK_CKS_CPLLCLK  = 3u
}PPLLCLK_Cks_t;

#endif

/* External data *************************************************************/
extern char __ghsbegin_RAMCODERom[], __ghsend_RAMCODERom[];
extern char __ghsbegin_RAMCODE[], __ghsend_RAMCODE[];

extern char __ghsbegin_ApplEndFlag[], __ghsend_ApplEndFlag[];
extern char __ghsbegin_romApplEndFlag[], __ghsend_romApplEndFlag[];

#if !defined(__FBL_UPDATER__)
extern ubyte __ghsbegin_CONST_SW_ID[1], __ghsend_CONST_SW_ID[];
extern char __ghsbegin_romCONST_SW_ID[], __ghsend_romCONST_SW_ID[];
#endif/*__FBL_UPDATER__*/

extern char __ghsbegin_romdata[], __ghsend_romdata[];
extern char __ghsbegin_data[], __ghsend_data[];


/*CPUS_InitRam*/
void CPUS_InitRam(void)
{
  ubyte *RomStart,*RomEnd;
  ubyte *RamStart,*RamEnd;

  /*copy initialized data*/
  RomStart = __ghsbegin_romdata;
  RomEnd   = __ghsend_romdata;

  RamStart = __ghsbegin_data;
  RamEnd = __ghsend_data;

  for(;(RomStart <= RomEnd) && (RamStart <= RamEnd);RomStart ++,RamStart++)
  {
    *RamStart = *RomStart;
  }
#ifdef __BOOT_LINK__
  /*Copy RAM code*/
  RomStart = __ghsbegin_RAMCODERom;
  RomEnd = __ghsend_RAMCODERom;

  RamStart = __ghsbegin_RAMCODE;
  RamEnd = __ghsend_RAMCODE;

  for(;(RomStart <= RomEnd) && (RamStart <= RamEnd);RomStart ++,RamStart++)
  {
    *RamStart = *RomStart;
  }

#ifndef __ENABLE_ICUS__
  /*copy ApplEndFlag*/
  RomStart = __ghsbegin_romApplEndFlag;
  RomEnd = __ghsend_romApplEndFlag;

  RamStart = __ghsbegin_ApplEndFlag;
  RamEnd = __ghsend_ApplEndFlag;

  for(;(RomStart <= RomEnd) && (RamStart <= RamEnd);RomStart ++,RamStart++)
  {
    *RamStart = *RomStart;
  }
#endif

#if !defined(__FBL_UPDATER__)
  /*copy CONST_SW_ID*/
  RomStart = __ghsbegin_romCONST_SW_ID;
  RomEnd = __ghsend_romCONST_SW_ID;

  RamStart = __ghsbegin_CONST_SW_ID;
  RamEnd = __ghsend_CONST_SW_ID;

  for(;(RomStart <= RomEnd) && (RamStart <= RamEnd);RomStart ++,RamStart++)
  {
    *RamStart = *RomStart;
  }
#endif
#endif
}


/*Check RAM checksum*/
void CPUS_CheckRam(void)
{
#ifdef CPUS_ENABLA_RAM_CHECK
  ulong  Checksum1 = 0,Checksum0 = 0;
  SYST_AddressWidth_t   * Address;
  /* Initialization */

  /*set all 1*/
  for (Address = SYST_RAM_START_ADDRESS ; Address < (SYST_RAM_START_ADDRESS + SYST_CPU_RAM_SIZE); Address++)
  {
    *Address = 0xFFFFFFFFu;
    Checksum1 += *(Address);
  }

  /*set all 0*/
  for (Address = SYST_RAM_START_ADDRESS ; Address < (SYST_RAM_START_ADDRESS + SYST_CPU_RAM_SIZE); Address++)
  {
    *Address = 0x00000000u;
    Checksum0 += *(Address);
  }

  if((CPUS_RAM_CHECKSUM_0 != Checksum0)||(CPUS_RAM_CHECKSUM_1 != Checksum1))
  {
    SYST_CPU_ENDRAM = 1;
  }
  else
  {
    SYST_CPU_ENDRAM = 0;
  }
#endif
}



/*For F1K:
 * If MainOSC is selected for a clock domain, disable the setting or select a clock source other than
 * MainOSC
*/
#if defined( __RH850_F1K__)
void CPUS_ClockSelectorDisable(void)
{
  Cpus_SetClockSelectorConfig(PROTCMD0, ATAUJ, F1K_CKS_DISABLE);   /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD0, ARTCA, F1K_CKS_DISABLE);   /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD0, AADCA, F1K_CKS_DISABLE);   /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, F1K_CKS_DISABLE);   /*Disable*/

#if defined( __RH850_F1L__)
  TARG_WriteLong(FOUTDIV, CLO_DIV_FOUT);
  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, CLO_CKS_FOUT);       /*Disable*/
  if(CLO_CKS_FOUT != FOUT_CKS_DISABLE)
  {
    while((TARG_ReadLong(FOUTSTAT)&CLO_MASK_FOUTSTABLE)!=CLO_MASK_FOUTSTABLE);
  }
#elif defined( __RH850_F1K__)
  TARG_WriteLong(CLKCTLFOUTDIV, CLO_DIV_FOUT);
  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, F1K_CKS_DISABLE);       /*Disable*/
  if(F1K_CKS_DISABLE != FOUT_CKS_DISABLE)
  {
     while((TARG_ReadLong(CLKCTLFOUTSTAT)&CLO_MASK_FOUTSTABLE)!=CLO_MASK_FOUTSTABLE);
  }
#endif

  Cpus_SetClockSelectorConfig(PROTCMD1, CPUCLK, F1K_CKS_CPUCLK_DEFAULT);    /*Disable*/
#ifdef __RH850_F1K__
  Cpus_SetClockSelectorConfig(PROTCMD1, PPLLCLK, F1K_CKS_PPLLCLK_DEFAULT);   /*Disable*/
#endif
  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI1, F1K_CKS_DISABLE);    /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI2, F1K_CKS_DISABLE);    /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD1, ILIN, F1K_CKS_DISABLE);      /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD1, IADCA, F1K_CKS_DISABLE);     /*Disable*/
  Cpus_SetClockSelectorConfig(PROTCMD1, ICAN, F1K_CKS_DISABLE);      /*Disable*/
  Cpus_SetClockDividerConfig(PROTCMD1, ICANOSC, F1K_CKS_DISABLE);       /* Disable */
  Cpus_SetClockSelectorConfig(PROTCMD1, ICSI, F1K_CKS_DISABLE);      /*Disable*/

  /* reset MOSCSTPM.MOSCSTPMSK*/
#ifdef CPUS_MASK_MOSC_SLEEP_MODE
  TARG_WriteLong( CLKCTLMOSCSTPM, CLO_MSK_DISTRG);
  while(CLO_MSK_DISTRG != TARG_ReadLong(CLKCTLMOSCSTPM));
#endif /* CPUS_MASK_MOSC_SLEEP_MODE */
}
#endif

void CPUS_ClockSelectorConfig(void)
{
  ulong Cpus_clk_counter =0;
  /* Clock source selection for all macros in AWO power domain */
  Cpus_SetClockDividerConfig(PROTCMD0, AWDTA, CLO_CKS_WDTA0);       /* WDTA0    LS IntOsc*/

  Cpus_SetClockSelectorConfig(PROTCMD0, ATAUJ, CLO_CKS_TAUJS);      /*TAUJ  LS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD0, ATAUJ, CLO_CKS_TAUJD);       /* LS IntOsc/1 */

  if(CPUS_SOBOSC_USED == TRUE)
  {
    //Cpus_SetClockSelectorConfig(PROTCMD0, ARTCA, RTCA_CKS_SOSC);      /*RTCA  RTCA_CKS_SOSC*/
    //Cpus_SetClockDividerConfig(PROTCMD0, ARTCA, RTCA_CKS_T_1);       /* RTCA_CKS_SOSC/1 */
    TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLCKSC_ARTCAS_CTL, (RTCA_CKS_SOSC));
    Cpus_clk_counter = 0;
    while (TARG_ReadLong(CLKCTLCKSC_ARTCAS_ACT) != (RTCA_CKS_SOSC))
    {
      asm("nop");
      if( Cpus_clk_counter >= CLK_CONFIG_TIMEOUT)
      {
        break;
      }
       Cpus_clk_counter++;
       WDTD_Refresh();
    }
    TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLCKSC_ARTCAD_CTL, (RTCA_CKS_T_1));
    Cpus_clk_counter = 0;
    while ( TARG_ReadLong(CLKCTLCKSC_ARTCAD_ACT) != (RTCA_CKS_T_1) )
    {
      asm("nop");
      if( Cpus_clk_counter >= CLK_CONFIG_TIMEOUT)
      {
        break;
      }
       Cpus_clk_counter++;
       WDTD_Refresh();
    }
  }
  else
  {
    //Cpus_SetClockSelectorConfig(PROTCMD0, ARTCA, CLO_CKS_RTCAS);
    //Cpus_SetClockDividerConfig(PROTCMD0, ARTCA, CLO_CKS_RTCAD);
    TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLCKSC_ARTCAS_CTL, (CLO_CKS_RTCAS));
    Cpus_clk_counter = 0;
    while (TARG_ReadLong(CLKCTLCKSC_ARTCAS_ACT) != (CLO_CKS_RTCAS))
    {
      asm("nop");
      if( Cpus_clk_counter >= CLK_CONFIG_TIMEOUT)
      {
        break;
      }
       Cpus_clk_counter++;
       WDTD_Refresh();
    }
    TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLCKSC_ARTCAD_CTL, (CLO_CKS_RTCAD));
    Cpus_clk_counter = 0;
    while ( TARG_ReadLong(CLKCTLCKSC_ARTCAD_ACT) != (CLO_CKS_RTCAD) )
    {
      asm("nop");
      if( Cpus_clk_counter >= CLK_CONFIG_TIMEOUT)
      {
        break;
      }
       Cpus_clk_counter++;
       WDTD_Refresh();
    }
  }

  Cpus_SetClockSelectorConfig(PROTCMD0, AADCA, CLO_CKS_ADCA0S); /*ADCA0  HS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD0, AADCA, CLO_CKS_ADCA0D);      /* HS IntOsc /1 */

  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, FOUT_CKS_DISABLE);       /*Disable*/

#if defined( __RH850_F1L__)
  TARG_WriteLong(FOUTDIV, CLO_DIV_FOUT);
  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, CLO_CKS_FOUT);       /*Disable*/
  if(CLO_CKS_FOUT != FOUT_CKS_DISABLE)
  {
    while((TARG_ReadLong(FOUTSTAT)&CLO_MASK_FOUTSTABLE)!=CLO_MASK_FOUTSTABLE);
  }
#elif defined( __RH850_F1K__)
  TARG_WriteLong(CLKCTLFOUTDIV, CLO_DIV_FOUT);
  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, CLO_CKS_FOUT);       /*Disable*/
  if(CLO_CKS_FOUT != FOUT_CKS_DISABLE)
  {
     while((TARG_ReadLong(CLKCTLFOUTSTAT)&CLO_MASK_FOUTSTABLE)!=CLO_MASK_FOUTSTABLE);
  }
#endif

  Cpus_SetClockSelectorConfig(PROTCMD1, CPUCLK, CLO_CKS_CPUS);      /*CPUCLK  CPLLCLK*/
  Cpus_SetClockDividerConfig(PROTCMD1, CPUCLK, CLO_CKS_CPUD);       /* CPLLCLK/1 */
#ifdef __RH850_F1K__
  Cpus_SetClockSelectorConfig(PROTCMD1, PPLLCLK, PPLLCLK_CKS_CPLLCLK);      /* CPLLCLK*/
#endif
  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI1, CLO_CKS_PERI1S);        /*PERI1  CPUCLK2*/
  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI2, CLO_CKS_PERI2S);        /*PERI2  CPUCLK2*/

  Cpus_SetClockSelectorConfig(PROTCMD1, ILIN, CLO_CKS_ILINS);           /*ILIN  CPUCLK2*/
  Cpus_SetClockDividerConfig(PROTCMD1, ILIN, CLO_CKS_ILIND);            /* CPUCLK2/1 */

  Cpus_SetClockSelectorConfig(PROTCMD1, IADCA, CLO_CKS_ADCA1S);     /*ADCA1  HS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD1, IADCA, CLO_CKS_ADCA1D);      /* HS IntOsc/1 */

  Cpus_SetClockSelectorConfig(PROTCMD1, ICAN, CLO_CKS_RSCANS);      /*RSCAN  CPUCLK*/
  Cpus_SetClockDividerConfig(PROTCMD1, ICANOSC, CLO_CKS_CANOSCD);       /* Disable */

  Cpus_SetClockSelectorConfig(PROTCMD1, ICSI, CLO_CKS_CSIS);            /*CSI  CPUCLK*/
#ifndef __BOOT_LINK__
#ifdef _MCU_DEBUG_
#else
  if( CheckBLFIfSupportHWWDG() == FALSE)
#endif
  {
	  /* init internal watchdog */
	  WDTD_Init();
  }
  /* start internal watchdog */
  WDTD_Start();
#endif
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_ClockSelectorConfigFromSleep                                   */
/* Role : Set clocks selector for each supported clock domain                 */
/*        coming from sleep                                                   */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*----------------------------------------------------------------------------*/
void CPUS_ClockSelectorConfigFromSleep(void)
{
  Cpus_SetClockDividerConfig(PROTCMD0, AWDTA, CLO_CKS_WDTA0);       /* WDTA0    LS IntOsc*/

  Cpus_SetClockSelectorConfig(PROTCMD0, ATAUJ, CLO_CKS_TAUJS);      /*TAUJ  LS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD0, ATAUJ, CLO_CKS_TAUJD);       /* LS IntOsc/1 */

#ifndef RTCA_MASK_SLEEP_MODE
  Cpus_SetClockSelectorConfig(PROTCMD0, ARTCA, CLO_CKS_RTCAS);      /*RTCA  LS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD0, ARTCA, CLO_CKS_RTCAD);       /* LS IntOsc/1 */
#endif

  Cpus_SetClockSelectorConfig(PROTCMD0, AADCA, CLO_CKS_ADCA0S); /*ADCA0  HS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD0, AADCA, CLO_CKS_ADCA0D);      /* HS IntOsc /1 */

  Cpus_SetClockSelectorConfig(PROTCMD0, AFOUT, CLO_CKS_FOUT);       /*Disable*/

  Cpus_SetClockSelectorConfig(PROTCMD1, CPUCLK, CLO_CKS_CPUS);      /*CPUCLK  CPLLCLK*/
  Cpus_SetClockDividerConfig(PROTCMD1, CPUCLK, CLO_CKS_CPUD);       /* CPLLCLK/1 */

  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI1, CLO_CKS_PERI1S);        /*PERI1  CPUCLK2*/
  Cpus_SetClockSelectorConfig(PROTCMD1, IPERI2, CLO_CKS_PERI2S);        /*PERI2  CPUCLK2*/

  Cpus_SetClockSelectorConfig(PROTCMD1, ILIN, CLO_CKS_ILINS);           /*ILIN  CPUCLK2*/
  Cpus_SetClockDividerConfig(PROTCMD1, ILIN, CLO_CKS_ILIND);            /* CPUCLK2/1 */

  Cpus_SetClockSelectorConfig(PROTCMD1, IADCA, CLO_CKS_ADCA1S);     /*ADCA1  HS IntOsc*/
  Cpus_SetClockDividerConfig(PROTCMD1, IADCA, CLO_CKS_ADCA1D);      /* HS IntOsc/1 */

  Cpus_SetClockSelectorConfig(PROTCMD1, ICAN, CLO_CKS_RSCANS);      /*RSCAN  CPUCLK*/
  Cpus_SetClockDividerConfig(PROTCMD1, ICANOSC, CLO_CKS_CANOSCD);       /* Disable */

  Cpus_SetClockSelectorConfig(PROTCMD1, ICSI, CLO_CKS_CSIS);            /*CSI  CPUCLK*/

}

/*----------------------------------------------------------------------------*/
/* Name : CPUS_PrepareClockSelectorBeforeSleep                                */
/* Role : prepare the Clock tree before enter sleep mode                      */
/* Interface : -                                                              */
/* Pre-condition : INT disabled                                               */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [set clock for the module need to work before re-init whole clock tree] */
/*    [set PLLs ]                                                             */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CPUS_PrepareClockSelectorBeforeSleep(void)
{
#if defined( __RH850_F1L__)
  TARG_WriteLong(ROSCSTPM, OFF);
#elif defined( __RH850_F1K__)
  TARG_WriteLong(CLKCTLROSCSTPM, OFF);
#endif

#ifdef WDTA_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(AWDTAD, ON); /*WDTA RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(AWDTAD, OFF); /*WDTA stop in deepstop mode*/
#endif

#ifdef RTCA_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(ARTCAD, ON);     /*RTCA RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(ARTCAD, OFF);     /*RTCA stop in deepstop mode*/
#endif

#ifdef ADCA_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(AADCAD, ON);  /*ADCA RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(AADCAD, OFF);  /*ADCA stop in deepstop mode*/
#endif

#ifdef FOUT_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(AFOUTS, ON);  /*FOUT RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(AFOUTS, OFF);  /*FOUT stop in deepstop mode*/
#endif

#ifdef LIND_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(ILIND, ON);  /*LIN RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(ILIND, OFF);  /*LIN stop in deepstop mode*/
#endif

#ifdef CAN_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(ICANS, ON);  /*CAN RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(ICANS, OFF);  /*CAN stop in deepstop mode*/
#endif

#ifdef CANOSC_MASK_SLEEP_MODE
  Cpus_SetClockInDeepstop(ICANOSCD, ON); /*CANOSC RUN in deepstop mode*/
#else
  Cpus_SetClockInDeepstop(ICANOSCD, OFF);  /*CANOSC stop in deepstop mode*/
#endif

}



/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTreeFromSleep                                        */
/* Role : Start the Clock tree from sleep mode                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/*     - lock-time has to be correctly set before service call.(PLLS reg)     */
/* Constraints :                                                              */
/*     - The service has to called upon wake-up from sleep mode               */
/*     - Main osc must be operating before service call                       */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Start PLL and wait for stabilization]                                  */
/*    [Select PLL output for Fcpu]                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined( __RH850_F1L__)

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                       */
/* Role : to stop PLL                                                        */
/* Interface : -                                                              */
/* Pre-condition : PLL is enabled                                            */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CPUS_StopPll()
{
  volatile ulong regValue;

  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(PLLS,CLO_BIT_CLKACT))
  {
    /* Wait for PLL0 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE) | CLO_MSK_DISTRG;
      TARG_ProtWriteLong(PROTCMD1, PLLE, regValue);
    } while (TARG_ReadBitInLong(PLLS,CLO_BIT_CLKACT));
  }
}

void CPUS_StartClockTreeFromSleep(void)
{
    /* Start the clock tree */
    ulong _RegValue;

    /* PLL configuration */
    /* Make sure that the PLL0 is stopped */
    if (TARG_ReadBitInLong(PLLS, CLO_BIT_CLKACT))
    {
        /* Wait for PLL enable status bit */
        do
        {
            _RegValue = TARG_ReadLong(PLLE) | CLO_MSK_DISTRG;
            TARG_ProtWriteLong(PROTCMD1, PLLE, _RegValue);
        } while (TARG_ReadBitInLong(PLLS,CLO_BIT_CLKACT));
    }

    /* Set PLL mode for PLL      */
    /* Set Mr, Pr and Nr divider values                         */
    TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR + CLO_PLL_PR);
/*
    //for f1k
    //TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR);
*/
    /* Enable PLL */
    _RegValue = TARG_ReadLong(PLLE) | CLO_MSK_ENTRG;
    TARG_ProtWriteLong(PROTCMD1, PLLE, _RegValue);

    /* Wait for PLL0 enable status bit */
    while (!TARG_ReadBitInLong(PLLS,CLO_BIT_CLKACT))
    {
    asm("nop");
    }

    CPUS_ClockSelectorConfigFromSleep();
}

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 */
/* Role : Startup the Clock Tree                                              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [...to be edited...]                                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CPUS_StartClockTree(void)
{
  ulong _RegValue;

 /* Main oscillator not stop after wakeup to prevent RTC precision loss */
#if defined(SYST_F1x_DEEPSTOP_USED)
    if ((TARG_ReadLong(MOSCS) != ( CLO_MSK_nCLKACT))
    || (TARG_ReadLong(MOSCST) != (CLO_MSK_MOST & CLO_STAB_MOSC))
    || (TARG_ReadLong(MOSCC)  != (CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED)))
#endif /* defined(SYST_F1x_DEEPSTOP_USED) */
    {
    /* Make sure that the MainOsc is stopped */
        if (TARG_ReadBitInLong(MOSCS,CLO_BIT_CLKACT))
        {
            /* Wait for MainOsc enable status bit */
            do
            {
                _RegValue = TARG_ReadLong(MOSCE) | CLO_MSK_DISTRG;
                TARG_ProtWriteLong(PROTCMD0, MOSCE, _RegValue);
            } while (TARG_ReadBitInLong(MOSCS, CLO_BIT_CLKACT));
        }

        /* Set MainOsc stabilization time */

        TARG_WriteLong(MOSCST,(CLO_MSK_MOST & CLO_STAB_MOSC_4MS));

    /* Set amplification gain depending on MainOsc frequency */
#ifdef CLO_MOSC_AMPSEL
        TARG_WriteLong(MOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_MOSC_AMPSEL));
#else
        TARG_WriteLong(MOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED));
#endif

        /* Enable MainOsc */
        /* Unmask stop request - MainOsc is stopped in STOP mode */
        /* and is re-started upon wake-up from stand-by mode.    */
        _RegValue = TARG_ReadLong(MOSCE) | CLO_MSK_ENTRG;
        TARG_ProtWriteLong(PROTCMD0, MOSCE, _RegValue);

#ifdef CPUS_MASK_MOSC_SLEEP_MODE
        /* Mask stop request - MainOsc is NOT stopped in STOP mode */
        _RegValue = TARG_ReadLong(MOSCSTPM) | CLO_MSK_STPM;
        TARG_WriteLong( MOSCSTPM, _RegValue);
#endif /* CPUS_MASK_MOSC_SLEEP_MODE */

        /* Wait for MainOsc enable, stabilization and active status bit */
        while (!TARG_ReadBitInLong(MOSCS,CLO_BIT_CLKACT) )
        {
        asm("nop");
        }
    }

    /* Sub Oscillator (32 kHz) configuration                         */
    /* WARNING:                                                      */
    /* The define below must be declared in cpus_conifg.h if SubOsc  */
    /* is not mounted on the board.                                  */

#ifndef CPUS_SOBOSC_NOT_USED
    /* Set SubOsc stabilization time */
    TARG_WriteLong(SOSCST,(CLO_MSK_SOST & CLO_STAB_SOSC_1S));

    /* Enable SubOsc */
    _RegValue = TARG_ReadLong(SOSCE) | CLO_MSK_ENTRG;
    TARG_ProtWriteLong(PROTCMD0, SOSCE, _RegValue);

    /* Wait for SubOsc enable status bit */
    while (!TARG_ReadBitInLong(SOSCS,CLO_BIT_CLKACT))
    {
    asm("nop");
    }
#endif /* CPUS_SOBOSC_NOT_USED */

#ifndef CPUS_MASK_HRNG_SLEEP_MODE
    /*High speed IntOsc configuration*/
    /* Unmask stop request - High Speed IntOsc is stopped in STOP mode */
    /* and is re-started upon wake-up from stand-by mode.              */
    _RegValue = TARG_ReadLong(ROSCSTPM) & ~CLO_MSK_STPM;
    TARG_WriteLong(ROSCSTPM, _RegValue);
#endif

    /* PLL configuration */

    /* Make sure that the PLL is stopped */
    if (TARG_ReadBitInLong(PLLS, CLO_BIT_CLKACT))
    {
        /* Wait for PLL enable status bit */
        do
        {
            _RegValue = TARG_ReadLong(PLLE) | CLO_MSK_DISTRG;
            TARG_ProtWriteLong(PROTCMD1, PLLE, _RegValue);
        } while (TARG_ReadBitInLong(PLLS,CLO_BIT_CLKACT));
    }

    /* Set PLL mode for PLL  */
    /* Set Mr, Pr and Nr divider values                         */
    TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR + CLO_PLL_PR);
/*
    //for f1k
    //TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR);
*/


    /* Enable PLL */
    _RegValue = TARG_ReadLong(PLLE) | CLO_MSK_ENTRG;
    TARG_ProtWriteLong(PROTCMD1, PLLE, _RegValue);

    /* Wait for PLL enable status bit */
    while (!TARG_ReadBitInLong(PLLS, CLO_BIT_CLKACT))
    {
    asm("nop");
    }

    CPUS_ClockSelectorConfig();
}
#elif defined( __RH850_F1K__)

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                       */
/* Role : to stop PLL                                                        */
/* Interface : -                                                              */
/* Pre-condition : PLL is enabled                                            */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CPUS_StopPll(void)
{
  volatile ulong regValue;

  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(CLKCTLPLLS,CLO_BIT_CLKACT))
  {
    /* Wait for PLL0 enable status bit */
    do {
      regValue = TARG_ReadLong(CLKCTLPLLE) | CLO_MSK_DISTRG;
      TARG_ProtWriteLong(WPROTRPROTCMD1, CLKCTLPLLE, regValue);
    } while (TARG_ReadBitInLong(CLKCTLPLLS,CLO_BIT_CLKACT));
  }
}

void CPUS_StartClockTreeFromSleep(void)
{
    /* Start the clock tree */
    ulong _RegValue;

    /* PLL configuration */
    /* Make sure that the PLL0 is stopped */
    if (TARG_ReadBitInLong(CLKCTLPLLS, CLO_BIT_CLKACT))
    {
        /* Wait for PLL enable status bit */
        do
        {
            _RegValue = TARG_ReadLong(CLKCTLPLLE) | CLO_MSK_DISTRG;
            TARG_ProtWriteLong(WPROTRPROTCMD1, CLKCTLPLLE, _RegValue);
        } while (TARG_ReadBitInLong(CLKCTLPLLS,CLO_BIT_CLKACT));
    }

    /* Set PLL mode for PLL      */
    /* Set Mr, Pr and Nr divider values                         */
/*
   // TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR + CLO_PLL_PR);
    //for f1k
*/
    TARG_WriteLong(CLKCTLPLLC, CLO_PLL_MR + CLO_PLL_NR);

    /* Enable PLL */
    _RegValue = TARG_ReadLong(CLKCTLPLLE) | CLO_MSK_ENTRG;
    TARG_ProtWriteLong(WPROTRPROTCMD1, CLKCTLPLLE, _RegValue);

    /* Wait for PLL0 enable status bit */
    while (!TARG_ReadBitInLong(CLKCTLPLLS,CLO_BIT_CLKACT))
    {
    asm("nop");
    }

    CPUS_ClockSelectorConfigFromSleep();
}

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 */
/* Role : Startup the Clock Tree                                              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [...to be edited...]                                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CPUS_StartClockTree(void)
{
  ulong _RegValue;
  ulong CPUS_EnSubOscTimeoutCounter = 0u;
#ifndef __FBL_UPDATER__

#ifndef __BOOT_LINK__
#ifdef _MCU_DEBUG_
#else
  if( CheckBLFIfSupportHWWDG() == FALSE)
#endif
#endif
  {
#if 0
 /* Main oscillator not stop after wakeup to prevent RTC precision loss */
#if defined(SYST_F1x_DEEPSTOP_USED)
    if ((TARG_ReadLong(CLKCTLMOSCS) != ( CLO_MSK_nCLKACT))
    || (TARG_ReadLong(CLKCTLMOSCST) != (CLO_MSK_MOST & CLO_STAB_MOSC))
    || (TARG_ReadLong(CLKCTLMOSCC)  != (CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED)))
#endif /* defined(SYST_F1x_DEEPSTOP_USED) */
    {
    /* Make sure that the MainOsc is stopped */
        if (TARG_ReadBitInLong(CLKCTLMOSCS,CLO_BIT_CLKACT))
        {
           #if defined( __RH850_F1K__)
            /*disable clock selector of all clock domain*/
           CPUS_ClockSelectorDisable();
           #endif

            /* Wait for MainOsc enable status bit */
            do
            {
                _RegValue = TARG_ReadLong(CLKCTLMOSCE) | CLO_MSK_DISTRG;
                TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLMOSCE, _RegValue);
            } while (TARG_ReadBitInLong(CLKCTLMOSCS, CLO_BIT_CLKACT));
        }

#endif
  WDTD_Init();
  if(((TARG_ReadLong(CLKCTLMOSCE)&0x3) == 0) && (TARG_ReadBitInLong(CLKCTLMOSCS,CLO_BIT_CLKACT)== 0))
  {
        /* Set MainOsc stabilization time */

        TARG_WriteLong(CLKCTLMOSCST,(CLO_MSK_MOST & CLO_STAB_MOSC_4MS));

    /* Set amplification gain depending on MainOsc frequency */
#ifdef CLO_MOSC_AMPSEL
        TARG_WriteLong(CLKCTLMOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_MOSC_AMPSEL));
#else
        TARG_WriteLong(CLKCTLMOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED));
#endif

        /* Enable MainOsc */
        /* Unmask stop request - MainOsc is stopped in STOP mode */
        /* and is re-started upon wake-up from stand-by mode.    */
        _RegValue = TARG_ReadLong(CLKCTLMOSCE) | CLO_MSK_ENTRG;
        TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLMOSCE, _RegValue);

#ifdef CPUS_MASK_MOSC_SLEEP_MODE
        /* Mask stop request - MainOsc is NOT stopped in STOP mode */
        _RegValue = TARG_ReadLong(CLKCTLMOSCSTPM) | CLO_MSK_STPM;
        TARG_WriteLong( CLKCTLMOSCSTPM, _RegValue);
#endif /* CPUS_MASK_MOSC_SLEEP_MODE */

        /* Wait for MainOsc enable, stabilization and active status bit */
        while (!TARG_ReadBitInLong(CLKCTLMOSCS,CLO_BIT_CLKACT) )
        {
        asm("nop");
        }
    }

#ifndef CPUS_MASK_HRNG_SLEEP_MODE
    /*High speed IntOsc configuration*/
    /* Unmask stop request - High Speed IntOsc is stopped in STOP mode */
    /* and is re-started upon wake-up from stand-by mode.              */
    _RegValue = TARG_ReadLong(ROSCSTPM) & ~CLO_MSK_STPM;
    TARG_WriteLong(ROSCSTPM, _RegValue);
#endif

    /* PLL configuration */

    /* Make sure that the PLL is stopped */
#ifdef __BOOT_LINK__
#ifndef __ENABLE_ICUS__
     if (TARG_ReadBitInLong(CLKCTLPLLS, CLO_BIT_CLKACT))
      {
          /* Wait for PLL enable status bit */
          do
          {
              _RegValue = TARG_ReadLong(CLKCTLPLLE) | CLO_MSK_DISTRG;
              TARG_ProtWriteLong(WPROTRPROTCMD1, CLKCTLPLLE, _RegValue);
          } while (TARG_ReadBitInLong(CLKCTLPLLS,CLO_BIT_CLKACT));
      }
#endif /*__ENABLE_ICUS__*/
#endif

    /* Set PLL mode for PLL  */
    /* Set Mr, Pr and Nr divider values                         */
/*
    //TARG_WriteLong(PLLC, CLO_PLL_MR + CLO_PLL_NR + CLO_PLL_PR);
    //for f1k
*/
    TARG_WriteLong(CLKCTLPLLC, CLO_PLL_MR + CLO_PLL_NR);

   /* Enable PLL */
    _RegValue = TARG_ReadLong(CLKCTLPLLE) | CLO_MSK_ENTRG;
    TARG_ProtWriteLong(WPROTRPROTCMD1, CLKCTLPLLE, _RegValue);

    /* Wait for PLL enable status bit */
    while (!TARG_ReadBitInLong(CLKCTLPLLS, CLO_BIT_CLKACT))
    {
    asm("nop");
    }

  }
#endif/*__FBL_UPDATER__*/

  /* Sub Oscillator (32 kHz) configuration                         */
  /* WARNING:                                                      */
  /* The define below must be declared in cpus_conifg.h if SubOsc  */
  /* is not mounted on the board.                                  */
  if(CPUS_SOBOSC_USED == TRUE)
  {
    #ifndef CPUS_SOBOSC_NOT_USED
      if(((TARG_ReadLong(CLKCTLSOSCE)&0x3) == 0) && (TARG_ReadBitInLong(CLKCTLSOSCS,CLO_BIT_CLKACT)== 0))
      {
        /* Set SubOsc stabilization time */
        TARG_WriteLong(CLKCTLSOSCST,(CLO_MSK_SOST & CLO_STAB_SOSC_1S));

        /* Enable SubOsc */
        _RegValue = TARG_ReadLong(CLKCTLSOSCE) | CLO_MSK_ENTRG;
        TARG_ProtWriteLong(WPROTRPROTCMD0, CLKCTLSOSCE, _RegValue);

        /* Wait for SubOsc enable status bit */
        while (!TARG_ReadBitInLong(CLKCTLSOSCS,CLO_BIT_CLKACT))
        {
          asm("nop");
          WDTD_Refresh();
          CPUS_EnSubOscTimeoutCounter++;
          if(CPUS_EnSubOscTimeoutCounter >= CPUS_ENSUBOSC_TIMEOUT)
          {
            CPUS_EnSubOscTimeoutFlag= TRUE;
            break;
          }
        }
      }
    #endif /* CPUS_SOBOSC_NOT_USED */
  }
  CPUS_ClockSelectorConfig();
}
#endif

void CPUS_CpuClkSwitchToEmclk(void)
{
  Cpus_SetClockSelectorConfig(PROTCMD1, CPUCLK, CPU_CKS_EMCLK);      /*CPUCLK  CPLLCLK*/
  Cpus_SetClockDividerConfig(PROTCMD1, CPUCLK, CPU_CKS_T_1);       /* CPLLCLK/1 */
}


bool_t CPUS_GetEnSubOscTimeoutFlag(void)
{
  return CPUS_EnSubOscTimeoutFlag;
}
#endif /* __RH850_F1x__*/
#endif /* __RH850__ */

/* _____ L O C A L - F U N C T I O N S _______________________________________*/

#endif /* __RH850__ */
/*______ E N D _____ (cpus_rh850.c) ________________________________________________*/
