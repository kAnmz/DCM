/******************************************************************************/
/* @F_NAME:          syst_kernel.c                                            */
/* @F_PURPOSE:       SYST kernel part for Green Hills Integrity OS            */
/* @F_CREATED_BY:    Olivier DIETLIN                                          */
/* @F_CREATION_DATE: 27/10/2014                                               */
/* @F_LANGUAGE:      C                                                        */
/* @F_MPROC_TYPE:    imx6                                                     */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifdef __GHOS__

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include <INTEGRITY.h>
#include <stdlib.h>
#include <stdio.h>
#include "bsp.h"
#include "bsp_export.h"
#include "modules/ghs/bspsrc/support/buildmemtable.h"
#include "modules/ghs/bspsrc/driver/soc/imx61/imx6-memmap.h"
#include "modules/ghs/bspsrc/driver/soc/imx61/imx6-clocks.h"

#include "syst_priv.h"

#include "vers_config_swid.h" 


/*_____ L O C A L - D E F I N E ______________________________________________*/


/*_____ L O C A L - T Y P E S ________________________________________________*/

/* Date */
typedef struct
{
  UINT1   Day;
  UINT1   Month;
  UINT1   Year;
} SYST_Date_t;

/* SW identifier : Do not change because section defined in link file */
/* example (due to naming rules for project version) :

 freezed state : version tupi_2.0.3

 Project name = xx  xx  xx  xx  xx xx xx xx xx
                't' 'u' 'p' 'i' 00 FF FF FF FF
 Version      = xx  xx  xx  xx  xx  xx xx xx xx
                '2' '.' '0' '.' '3' 00 FF FF FF

 Type         = xx  xx  xx
                'E' 'U' 00

 working : version ownervir_tupi_2.0

 Project name = xx  xx  xx  xx  xx  xx  xx  xx  xx
                'o' 'w' 'n' 'e' 'r' 'v' 'i' 'r' 00
 Version      = xx  xx  xx  xx  xx xx xx xx xx
                't' 'u' 'p' 'i' 00 FF FF FF FF

note :
  - end string = 0x00
  - missing fields are set to 0xFF due to erasing operation.
*/
typedef struct
{
  UINT1       ProjectName[8+1]; /* ASCII, string */
  UINT1       Version[8+1];     /* ASCII, string */
  UINT1       Type[2+1];        /* ASCII, string */
  SYST_Date_t Date;             /* BCD           */
  UINT1       Year;             /* Hex           */
  UINT1       Week;             /* Hex           */
} SYST_SwIdentifier_t;


/*_____ L O C A L - M A C R O S ______________________________________________*/

/* compute SW date (BCD -> binaire) */
#define SYST_SW_YEAR   ( (UINT1)( (((Vers_YEAR  >> 4) & 0x0F) * 10) + (Vers_YEAR  & 0x0F) ) )
#define SYST_SW_MONTH  ( (UINT1)( (((Vers_MONTH >> 4) & 0x0F) * 10) + (Vers_MONTH & 0x0F) ) )
#define SYST_SW_DAY    ( (UINT1)( (((Vers_DAY   >> 4) & 0x0F) * 10) + (Vers_DAY   & 0x0F) ) )

/* internal macros to generate week number as defined in ISO-8601 */
/* Julian day in Gregorian calendar                               */
/* see www.tondering.dk/claus/cal/calendar26.html                 */
#define Syst_Week_A   ((14 - SYST_SW_MONTH) / 12)
#define Syst_Week_Y   (SYST_SW_YEAR + 4800 - Syst_Week_A)
#define Syst_Week_M   (SYST_SW_MONTH + (12*Syst_Week_A) - 3)
#define Syst_Week_J   (SYST_SW_DAY + (((153*Syst_Week_M)+2)/5) + ((ulong)365*Syst_Week_Y) + (Syst_Week_Y/4) - (Syst_Week_Y/100) + (Syst_Week_Y/400) - 32045)

#define Syst_Week_D4  ((((Syst_Week_J + 31741 - (Syst_Week_J % 7)) % 146097) % 36524) % 1461)
#define Syst_Week_L   (Syst_Week_D4 / 1460)
#define Syst_Week_D1  (((Syst_Week_D4 - Syst_Week_L) % 365) + Syst_Week_L)

#define SYST_SW_WEEK  ( (UINT1)((Syst_Week_D1 / 7) + 1) )

#define Syst_VERSION_TYPE    "HL"


/*_____ P R I V A T E - D A T A ______________________________________________*/

extern char __ghsbegin_ramstart[];
extern char __ghsend_ramlimit[];


/*_____ L O C A L - D A T A __________________________________________________*/

/* --- SW identifier statement ---*/

#pragma ghs startdata
#pragma ghs section rodata=".CONST_SW_ID"

const SYST_SwIdentifier_t SYST_SwIdentifier =
{
  Vers_PROJECT_NAME,
  Vers_VERSION,
  Syst_VERSION_TYPE,
  {Vers_DAY, Vers_MONTH, Vers_YEAR}, /* BCD */
  SYST_SW_YEAR,                      /* Hex */
  SYST_SW_WEEK                       /* Hex */
};

#pragma ghs section rodata=default
#pragma ghs enddata


/* --- All SW part Ident table statement ---*/

#pragma ghs startdata
#pragma ghs section bss=".SwIdentArea"

SYST_SwIdentifier_t SYST_SwIdentTable[4];

#pragma ghs section bss=default
#pragma ghs enddata

/* Index of SW part Identification in SYST_SwIdentTable[] */
#define SYST_BL_SW_ID_INDEX        0
#define SYST_FLASHER_SW_ID_INDEX   1
#define SYST_CLIENT_SW_ID_INDEX    2
#define SYST_EOL_SW_ID_INDEX       3


/* IO Devices */
static struct IODeviceVectorStruct SYST_IODeviceStruct;

#ifdef __FSL_IMX6x__
/* Memory reservation to access ANALOG module from a VAS. */
static const MemoryReservation SYST_AnalogMemoryArea =
{
  MEMORY_READ | MEMORY_WRITE | MEMORY_VOLATILE | MEMORY_ARM_STRONGLY_ORDERED,
  0,
  IMX6_CCM_ANALOG_BASE, IMX6_CCM_ANALOG_BASE+0x0FFF,
  Other_MemoryType,
  true, 0xfffff000, 0xfffff000, "SYST_AnalogMemoryArea"
};
#endif /* __FSL_IMX6x__ */

static Address Syst_DataPhysicalAddress;

#if defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".BootKeyZone"
#endif /* C_COMP_GHS_ARM */

UINT2 SYST_BOOT_KEY_RAM;
UINT2 SYST_BOOT_KEY_RAM_COMP;

#if defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_ARM */

static Address Syst_RamAddress;


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/

static Error SYST_IODeviceCreate(IODeviceVector TheIODeviceVector);
static Error SYST_IODeviceReadRegister(IODeviceVector TheIODeviceVector, Value RegisterNb, Value *TheValue);
static Error SYST_IODeviceWriteRegister(IODeviceVector TheIODeviceVector, Value RegisterNb, Value TheValue);
static Error SYST_IODeviceWriteBuffers(IODeviceVector TheIODeviceVector, Value bt, Value bn, Buffer *DataBuff);
static Error SYST_IODeviceReadStatus(IODeviceVector TheIODeviceVector, Value StatusNumber, void *Destination, Address Length);
static Error SYST_IODeviceWriteStatus(IODeviceVector TheIODeviceVector, Value StatusNumber, void *Source, Address Length);
static void SYST_IODeviceReset(IODeviceVector TheIODeviceVector);

static void SYST_BspUserInit(void);


/*_____ G L O B A L - D A T A ________________________________________________*/

void (*__ghsentry_bspuserinit_syst)(void) = SYST_BspUserInit;


/*_____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S ________________*/

extern Address BSP_VirtualToPhysical(Address);


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/


/*_____ P R I V A T E - F U N C T I O N S ____________________________________*/


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

/******************************************************************************/
/* Name: SYST_IODeviceCreate                                                  */
/* Role: System IO Device creation                                            */
/* Interface: IODeviceVector TheIODeviceVector   IN    IO Device structure    */
/*            Error                              OUT   Creation status        */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   [ Do nothing, return Success ]                                           */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceCreate(IODeviceVector TheIODeviceVector)
{
  return Success;
}


/******************************************************************************/
/* Name: SYST_IODeviceReset                                                   */
/* Role: System IO Device reset                                               */
/* Interface: IODeviceVector TheIODeviceVector   IN    IO Device structure    */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   [ Do nothing ]                                                           */
/*  OD                                                                        */
/******************************************************************************/
static void SYST_IODeviceReset(IODeviceVector TheIODeviceVector)
{
}


/******************************************************************************/
/* Name: SYST_IODeviceReadRegister                                            */
/* Role: System IO Device read register                                       */
/*       - Read physical address of a VAS data                                */
/*       - Read Boot Key value                                                */
/*       - Read RAM byte data at previously set RAM address                   */
/* Interface: IODeviceVector TheIODeviceVector  IN   IO Device structure      */
/*            Value RegisterNb                  IN   Register number to write */
/*            Value *TheValue                   OUT  Register value read      */
/*            Error                             OUT  read status              */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   IF RegisterNb is valid                                                   */
/*    [ Set TheValue with requested data specified by RegisterNb ]            */
/*    [ Return Success ]                                                      */
/*  ELSE                                                                      */
/*    [ Return Failure ]                                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceReadRegister(IODeviceVector TheIODeviceVector, Value RegisterNb, Value *TheValue)
{
  Error E = Failure;

  switch(RegisterNb)
  {
    case Syst_PHYSICAL_ADDRESS:
      /* If SYST_IODeviceWriteBuffers service has been well called before */
      if (Syst_DataPhysicalAddress != (Address)NULL)
      {
        /* Return the physical address of the data */
        *TheValue = (Value)Syst_DataPhysicalAddress;
        Syst_DataPhysicalAddress = (Address)NULL;
        E = Success;
      }
      break;
      
    case Syst_BOOT_KEY_RAM:
      /* Return the value of Boot Key in RAM */
      *TheValue = (Value)SYST_BOOT_KEY_RAM;
      E = Success;
      break;
      
    case Syst_READ_RAM:
      if (Syst_RamAddress != (Address)NULL)
      {
        BSP_FlushCaches(Syst_RamAddress, 1);
        /* Return the data pointed by RAM address previously set by SYST_IODeviceWriteRegister service */
        *TheValue = *((UINT1 *)Syst_RamAddress);
        Syst_RamAddress = (Address)NULL;
        E = Success;
      }
      break;
    
    default :
      break;
  }

  return E;
}


/******************************************************************************/
/* Name: SYST_IODeviceWriteRegister                                           */
/* Role: SYST IO Device write register                                        */
/*       - Write BOOT_KEY_RAM value                                           */
/*       - Set RAM address for read/write RAM access                          */
/*         (TheValue is an address relative to start of RAM)                  */
/*       - Write RAM byte data to previously set RAM address                  */
/*       - Print SOC Clocks values                                            */
/* Interface: IODeviceVector TheIODeviceVector  IN   IO Device structure      */
/*            Value RegisterNb                  IN   Register number to write */
/*            Value TheValue                    IN   Register value to write  */
/*            Error                             OUT  Write status             */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   IF RegisterNb is valid                                                   */
/*    [ Store TheValue into requested data specified by RegisterNb ]          */
/*    [ Return Success ]                                                      */
/*  ELSE                                                                      */
/*    [ Return Failure ]                                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceWriteRegister(IODeviceVector TheIODeviceVector, Value RegisterNb, Value TheValue)
{
  Error E = Failure;

  switch(RegisterNb)
  {
    case Syst_BOOT_KEY_RAM:
      /* Store the value of Boot Key in RAM */
      SYST_BOOT_KEY_RAM = (UINT2)TheValue;
      SYST_BOOT_KEY_RAM_COMP = (UINT2)(~TheValue);
      BSP_FlushCaches((Address)&SYST_BOOT_KEY_RAM, 4);
      E = Success;
      break;
      
    case Syst_SET_RAM_ADDRESS:
      /* Store RAM Address of data that will be read by SYST_IODeviceReadRegister service */
      /*                                   or write by SYST_IODeviceWriteRegister service */
      Syst_RamAddress = (Address)__ghsbegin_ramstart + (Address)TheValue;
      E = Success;
      break;
      
    case Syst_WRITE_RAM:
      if (Syst_RamAddress != (Address)NULL)
      {
        /* Write data to previously set RAM address */
        *((UINT1 *)Syst_RamAddress) = (UINT1)TheValue;
        BSP_FlushCaches(Syst_RamAddress, 1);
        Syst_RamAddress = (Address)NULL;
        E = Success;
      }
      break;

    case Syst_PRINT_CLOCKS:
      /* Call BSP service that prints the clocks values */
      ClocksPrint();
      E = Success;
      break;
      
    default:
      break;    
  }

  return E;
}


/******************************************************************************/
/* Name: SYST_IODeviceWriteBuffers                                            */
/* Role: System IO Device write buffer                                        */
/*       - Save physical address of a VAS data                                */
/* Interface: IODeviceVector TheIODeviceVector  IN   IO Device structure      */
/*            Value bt                          IN   Block Type               */
/*            Value bn                          IN   Block Number             */
/*            Buffer *Buff                      IN   Intergity Buffer         */
/*            Error                             OUT  Write status             */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   IF Requested address is valid for RAM area                               */
/*    [ Compute and store corresponding physical address ]                    */
/*    [ Return Success ]                                                      */
/*  ELSE                                                                      */
/*    [ Return Failure ]                                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceWriteBuffers(IODeviceVector TheIODeviceVector, Value bt, Value bn, Buffer *Buff)
{
  Error E = Failure;

  /* DDR RAM */
  if (Buff->TheAddress >= (Address)__ghsbegin_ramstart && Buff->TheAddress < (Address)__ghsend_ramlimit)
  {
    /* Store physical address of the data that will be get by SYST_IODeviceReadRegister service */
    Syst_DataPhysicalAddress = BSP_VirtualToPhysical(Buff->TheAddress);
    E = Success;
  }
  /* On Chip RAM */
  else if (Buff->TheAddress >= OCRAM_BASE && Buff->TheAddress < OCRAM_BASE + OCRAM_SIZE_SOLO)
  {
    /* Store physical address of the data that will be get by SYST_IODeviceReadRegister service */
    Syst_DataPhysicalAddress = Buff->TheAddress - OCRAM_BASE + OCRAM_PHYS_BASE;
    E = Success;
  }

  return E;
}


/******************************************************************************/
/* Name: SYST_IODeviceReadStatus                                              */
/* Role: System IO Device read status                                         */
/*       - Read Sw Part Identification                                        */
/*             Syst_BL_SW_ID_INDEX                                            */
/*             Syst_FLASHER_SW_ID_INDEX                                       */
/*             Syst_CLIENT_SW_ID_INDEX                                        */
/*             Syst_EOL_SW_ID_INDEX                                           */
/* Interface: IODeviceVector TheIODeviceVector  IN   IO Device structure      */
/*            Value StatusNumber                IN   Status Nb to read        */
/*            void *Destination                 IN   Read destination addr    */
/*            Address Length                    IN   Number byte to read      */
/*            Error                             OUT  read status              */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   IF StatusNumber is valid                                                 */
/*    [ Return SW Part Ident requested by StatusNumber ]                      */
/*    [ Return Success ]                                                      */
/*  ELSE                                                                      */
/*    [ Return Failure ]                                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceReadStatus(IODeviceVector TheIODeviceVector, Value StatusNumber, void *Destination, Address Length)
{
  Error E = Failure;

  if (Length == sizeof(SYST_SwIdentifier_t))
  {
    if (StatusNumber == Syst_BL_SW_ID_INDEX)
    {
      memcpy(Destination, (void *)&SYST_SwIdentTable[SYST_BL_SW_ID_INDEX], sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_FLASHER_SW_ID_INDEX)
    {
      memcpy(Destination, (void *)&SYST_SwIdentTable[SYST_FLASHER_SW_ID_INDEX], sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_CLIENT_SW_ID_INDEX)
    {
      memcpy(Destination, (void *)&SYST_SwIdentTable[SYST_CLIENT_SW_ID_INDEX], sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_EOL_SW_ID_INDEX)
    {
      memcpy(Destination, (void *)&SYST_SwIdentTable[SYST_EOL_SW_ID_INDEX], sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
  }

  return E;
}


/******************************************************************************/
/* Name: SYST_IODeviceWriteStatus                                             */
/* Role: System IO Device write status                                        */
/*       - Write Sw Part Identification                                       */
/*             Syst_BL_SW_ID_INDEX                                            */
/*             Syst_FLASHER_SW_ID_INDEX                                       */
/*             Syst_CLIENT_SW_ID_INDEX                                        */
/*             Syst_EOL_SW_ID_INDEX                                           */
/* Interface: IODeviceVector TheIODeviceVector  IN   IO Device structure      */
/*            Value StatusNumber                IN   Status Nb to write       */
/*            void *Source                      IN   Write source addr        */
/*            Address Length                    IN   Number byte to write     */
/*            Error                             OUT  write status             */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   IF StatusNumber is valid                                                 */
/*    [ Write SW Part Ident requested by StatusNumber ]                       */
/*    [ Return Success ]                                                      */
/*  ELSE                                                                      */
/*    [ Return Failure ]                                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/******************************************************************************/
static Error SYST_IODeviceWriteStatus(IODeviceVector TheIODeviceVector, Value StatusNumber, void *Source, Address Length)
{
  Error E = Failure;

  if (Length == sizeof(SYST_SwIdentifier_t))
  {
    if (StatusNumber == Syst_BL_SW_ID_INDEX)
    {
      memcpy((void *)&SYST_SwIdentTable[SYST_BL_SW_ID_INDEX], Source, sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_FLASHER_SW_ID_INDEX)
    {
      memcpy((void *)&SYST_SwIdentTable[SYST_FLASHER_SW_ID_INDEX], Source, sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_CLIENT_SW_ID_INDEX)
    {
      memcpy((void *)&SYST_SwIdentTable[SYST_CLIENT_SW_ID_INDEX], Source, sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
    else if (StatusNumber == Syst_EOL_SW_ID_INDEX)
    {
      memcpy((void *)&SYST_SwIdentTable[SYST_EOL_SW_ID_INDEX], Source, sizeof(SYST_SwIdentifier_t));
      E = Success;
    }
  }

  return E;
}


/******************************************************************************/
/* Name: SYST_BspUserInit                                                     */
/* Role: System Bsp initialization                                            */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*  DO                                                                        */
/*   [ Create IO Device for VAS exchange ]                                    */
/*   [ Add memory reservation to access ANALOG from a VAS ]                   */
/*  OD                                                                        */
/******************************************************************************/
static void SYST_BspUserInit(void)
{
  #ifdef __FSL_IMX6x__
  ExtendedAddress Addr;
  #endif /* __FSL_IMX6x__ */

  Syst_DataPhysicalAddress = (Address)NULL;
  Syst_RamAddress = (Address)NULL;

  /* Create IO Device for VAS data  address translation */
  SYST_IODeviceStruct.Create = SYST_IODeviceCreate;
  SYST_IODeviceStruct.ReadRegister = SYST_IODeviceReadRegister;
  SYST_IODeviceStruct.WriteRegister = SYST_IODeviceWriteRegister;
  SYST_IODeviceStruct.WriteBuffers = SYST_IODeviceWriteBuffers;
  SYST_IODeviceStruct.ReadStatus = SYST_IODeviceReadStatus;
  SYST_IODeviceStruct.WriteStatus = SYST_IODeviceWriteStatus;
  SYST_IODeviceStruct.IOCoherentNotRequired = 1;
  SYST_IODeviceStruct.Reset = SYST_IODeviceReset;
  CheckSuccess(RegisterIODeviceVector(&SYST_IODeviceStruct, "SYST_IODevice"));

  #ifdef __FSL_IMX6x__
  /* Add memory reservation to access ANALOG from a VAS */
  CheckSuccess(BMT_AllocateFromAnonymousMemoryReservation(&SYST_AnalogMemoryArea, &Addr));
  #endif /* __FSL_IMX6x__ */
}


#endif /* __GHOS__ */

/*_____ E N D _____ (syst_kernel.c) _____________________________________*/
