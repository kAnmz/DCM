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
#include "dual_bank.h"
#endif

#pragma ghs startdata
#pragma ghs section text = default
#pragma ghs section rodata=".ProjectMessage"
const uint8_t SystemMessage[5] = {'M','0','E', 'n', 'd'};
#pragma ghs section rodata=default
#pragma ghs enddata


#if defined (DEEP_SLEEP)


#define USED_IPC_CHANNEL 7
#define IPC_NOTIFY_CPU_IRQ_INDEX    CPUIntIdx7_IRQn
#define IPC_NOTIFY_INT_NUMBER   7

static cy_stc_sysint_irq_t stcSysIntIpcNotifyInt =
{
    .sysIntSrc = (cy_en_intr_t)(cpuss_interrupts_ipc_0_IRQn + USED_IPC_CHANNEL),
    .intIdx    = IPC_NOTIFY_CPU_IRQ_INDEX,
    .isEnabled = true
};

uint32_t Sleep_Notify = 0u;


static void IpcNotifyInt_ISR(void);

#endif

int main(void)
{
#if defined (DEEP_SLEEP)
  uint32_t dual_Mapping = 0u;
  uint32_t workFlash_Addr = 0u;
#endif
	__enable_irq();

#if defined (TVII_BANK_MANAGEMENT)
	workFlash_Addr = (CY_WFLASH_SM_SBM_END - CY_WORK_SES_SIZE_IN_BYTE);/*Last sector of work flash*/
	if (true == Cy_WorkFlashBlankCheck(workFlash_Addr,CY_FLASH_DRIVER_BLOCKING))
	{
	  /*All the scope of this sector are blank*/
      Bank_SwapMapping(CY_FLASH_MAPPING_A);/*default mapping A*/
	}
	else
	{
      if (0xBBBBBBBB == *((uint32_t*)workFlash_Addr))
      {
        /*B mapping*/
        Bank_SwapMapping(CY_FLASH_MAPPING_B);
      }
      else
      {
        /*A mapping*/
        Bank_SwapMapping(CY_FLASH_MAPPING_A);
      }
	}
#endif
    /*SystemInit();*/

    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableApplCore(CY_CORTEX_M4_APPL_ADDR);
#if defined (DEEP_SLEEP)
    Sleep_Notify = 0u;

    Cy_SysInt_InitIRQ(&stcSysIntIpcNotifyInt);

    Cy_SysInt_SetSystemIrqVector((cy_en_intr_t)(cpuss_interrupts_ipc_0_IRQn + USED_IPC_CHANNEL), IpcNotifyInt_ISR);

    NVIC_ClearPendingIRQ(IPC_NOTIFY_CPU_IRQ_INDEX);
    NVIC_EnableIRQ(IPC_NOTIFY_CPU_IRQ_INDEX);

    Cy_IPC_Drv_SetInterruptMask(
                                   Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER),
                                   CY_IPC_NO_NOTIFICATION,
                                   (1uL << USED_IPC_CHANNEL)
    );
    Sleep_Notify = 0u;
#endif
    for(;;)
    {
#if defined (DEEP_SLEEP)
    	/* Wait 0.05 [s]*/
       /*Cy_SysTick_DelayInUs(50000);*/
		if(0xFFFFFFFFUL == Sleep_Notify)
		{
		   //Cy_SysTick_DelayInUs(1000*1000); // wait for M4 Peripherals shutting down
		   NVIC_ClearPendingIRQ(IPC_NOTIFY_CPU_IRQ_INDEX);

			if(0u != _FLD2VAL(SRSS_PWR_CTL_LPM_READY, SRSS->unPWR_CTL.u32Register))
			{
				Sleep_Notify = 0u;
				Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
			}
			else
			{

			}
		}
#endif
    }
    return 0;
}

#if defined (DEEP_SLEEP)
void IpcNotifyInt_ISR(void)
{
    uint32_t intCm4_0_Data = 0u;
    uint32_t interruptMasked =
            Cy_IPC_Drv_ExtractAcquireMask
            (
                Cy_IPC_Drv_GetInterruptStatusMasked
                (
                    Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER)
                )
            );
    Sleep_Notify = 0u;
    /* Check if the interrupt is caused by the notifier channel */
    if (interruptMasked == (1uL << USED_IPC_CHANNEL))
    {
    	/* Clear the interrupt */
        Cy_IPC_Drv_ClearInterrupt
        (
            Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER),
            CY_IPC_NO_NOTIFICATION,
            interruptMasked
        );

        if(CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_ReadMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL), &intCm4_0_Data))
        {
        	Sleep_Notify = intCm4_0_Data;
        }
        /* Finally relase the lock */
        (void)Cy_IPC_Drv_LockRelease(Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL), CY_IPC_NO_NOTIFICATION);
    }
}
#endif
/* [] END OF FILE */
