/***************************************************************************//**
* \file main_cm0plus.c
*
* \brief
* Main file for CM0+
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"
#if defined (TVII_BANK_MANAGEMENT)
#include "dbkm.h"
#endif

#ifdef __POLYSPACE__
int main_cm0plus(void)
#else
int main(void)
#endif
{
	__enable_irq();

#if defined (TVII_BANK_MANAGEMENT)
	DBKM_Management();
#else
    /*SystemInit();*/
    
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);

    for(;;)
    {
    	/* Wait 0.05 [s]*/
       /*Cy_SysTick_DelayInUs(50000);*/
    }
#endif
    return 0;
}



/* [] END OF FILE */
