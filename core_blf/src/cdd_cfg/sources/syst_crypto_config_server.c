/***********************************************************************************/
/* @F_NAME :      syst_crypto_config_server.c                                      */
/* @F_PURPOSE :                                                                    */
/* @F_CREATED_BY :   F32422C                                                       */
/* @F_CREATION_DATE : Dec 23, 2020                                                 */
/* @F_LANGUAGE :      ANSI C                                                       */
/* @F_MPROC_TYPE :    target independent                                           */
/*************************************** (C) Copyright 2020 Magneti Marelli ********/


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "syst_crypto_config_server.h"
/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ P R I V A T E - D A T A _____________________________________________*/

/*______ L O C A L - D A T A _________________________________________________*/
/* For CRYPTO server that runs on the CM0+ */
cy_stc_crypto_server_context_t cryptoServerCtx;
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

/*______ G L O B A L - F U N C T I O N S _____________________________________*/
void SYST_CryptoServerCongfig(void)
{
#if 0 /*For Bootloader IMC */
    /* Start crypto server */
    {
        Cy_Crypto_Server_Start(&cryptoConfig, &cryptoServerCtx);

        /* Enable CRYPTO regarding IRQn */
        /* In this examle 2 of crypto regarding interrupt uses same number,
            so just one invoking NVIC setting is needed.
                CY_CRYPTO_NOTIFY_INTR_NR    ==
                CY_CRYPTO_ERROR_INTR_NR
        */
        NVIC_SetPriority(CY_CRYPTO_NOTIFY_CPU_INT_IDX, 0);
        NVIC_ClearPendingIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);
        NVIC_EnableIRQ(CY_CRYPTO_NOTIFY_CPU_INT_IDX);

    }
#endif
}
/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (syst_crypto_config_server.c) _______________________________________*/



