/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Traveo2Cyp01_LL_RegAccess_Int.h
 *        \brief  Register access abstraction of vMem driver
 *
 *      \details  Abstraction of vMem driver register access
 *         \unit  vMem_LL_RegAccess
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_LL_REGACCESS_INT_H)
# define VMEM_30_TRAVEO2CYP01_LL_REGACCESS_INT_H
                                                                                                                        /* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Traveo2Cyp01_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL TYPES
 *********************************************************************************************************************/
/*! Address of a regsiter */
typedef vMem_30_Traveo2Cyp01_AddressType                                       vMem_30_Traveo2Cyp01_RegAddressType;

/*! Offset within the register space of the peripheral */
typedef vMem_30_Traveo2Cyp01_AddressType                                       vMem_30_Traveo2Cyp01_RegOffsetType;

/*! Width of a register (32 bit register) */
typedef uint32                                                                 vMem_30_Traveo2Cyp01_RegWidthType;

/*! Register volatile access type */
typedef volatile vMem_30_Traveo2Cyp01_RegWidthType                             vMem_30_Traveo2Cyp01_RegAccessType;

/*! Var pointer to a register with volatile access type to write to the register */
typedef P2VAR(vMem_30_Traveo2Cyp01_RegAccessType, AUTOMATIC, MSR_REGSPACE)     vMem_30_Traveo2Cyp01_RegVarVolatilePtrType;

/*! Const pointer to a register with volatile access to read from the register */
typedef P2CONST(vMem_30_Traveo2Cyp01_RegAccessType, AUTOMATIC, MSR_REGSPACE)   vMem_30_Traveo2Cyp01_RegConstVolatilePtrType;

/*! Var pointer to a register with non-volatile access to write to the register via the os peripheral access api */
typedef P2VAR(vMem_30_Traveo2Cyp01_RegWidthType, AUTOMATIC, MSR_REGSPACE)      vMem_30_Traveo2Cyp01_RegVarNonVolatilePtrType;

/*! Const pointer to a register with non-volatile access to read from the register via the os peripheral access api */
typedef P2CONST(vMem_30_Traveo2Cyp01_RegWidthType, AUTOMATIC, MSR_REGSPACE)    vMem_30_Traveo2Cyp01_RegConstNonVolatilePtrType;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
#  define VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE LOCAL_INLINE
# endif /* VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_GetPeripheralRegionId
 *********************************************************************************************************************/
/*! \brief        Retrieves the peripheral region Id based of the given peripheral base address.
 *  \details      -
 *  \param[in]    baseAddress   Base address of the peripheral.
 *  \return       OsPeripheralId.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_Os_PeripheralIdType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_GetPeripheralRegionId
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr
 *********************************************************************************************************************/
/*! \brief        Returns a variable volatile pointer to the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \return       Variable volatile pointer to the register addressed.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegVarVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr
 *********************************************************************************************************************/
/*! \brief        Returns a constant volatile pointer to the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \return       Constant volatile pointer to the register addressed.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegConstVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr
 *********************************************************************************************************************/
/*! \brief        Returns a variable non-volatile pointer to the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \return       Variable non-volatile pointer to the register addressed.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegVarNonVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr
 *********************************************************************************************************************/
/*! \brief        Returns a constant non-volatile pointer to the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \return       Constant non-volatile pointer to the register addressed.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegConstNonVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_SetBitMask
 *********************************************************************************************************************/
/*! \brief        Sets the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \param[in]    bitMask      Bits to be set.
 *  \context      TASK
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_SetBitMask
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_ClearBitMask
 *********************************************************************************************************************/
/*! \brief        Clears the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \param[in]    bitMask      Bits to be cleared.
 *  \context      TASK
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_ClearBitMask
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_ReadBits
 *********************************************************************************************************************/
/*! \brief        Reads the value of the addressed register and applies bit mask.
 *  \details      -
 *  \param[in]    baseAddress Base address of the peripheral.
 *  \param[in]    regOffset   Offset in bytes into the peripheral register space.
 *  \param[in]    bitMask     Bit mask to apply on register value.
 *  \return       Value of the register.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegWidthType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_ReadBits
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_WriteBits
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the specified bit group.
 *  \details      -
 *  \param[in]    baseAddress   Base address of the peripheral.
 *  \param[in]    regOffset     Offset in bytes into the peripheral register space.
 *  \param[in]    bitMask       Bit mask to apply on register value.
 *  \param[in]    bitsValue     Value to be written to the register.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_WriteBits
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask,
    vMem_30_Traveo2Cyp01_RegWidthType   bitsValue
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_Read
 *********************************************************************************************************************/
/*! \brief        Reads the value of the addressed register
 *  \details      -
 *  \param[in]    baseAddress  Base address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \return       Value of the register.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegWidthType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_Read
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_Write
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the addressed register.
 *  \details      -
 *  \param[in]    baseAddress  Base Address of the peripheral.
 *  \param[in]    regOffset    Offset in bytes into the peripheral register space.
 *  \param[in]    regValue     Value to be written to the register.
 *  \context      TASK
 *  \reentrant    TRUE for different registers
 *  \synchronous  TRUE
 *  \pre          -
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_Write
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   regValue
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
# ifndef VMEM_30_TRAVEO2CYP01_NOUNIT_VMEM_LL_REGACCESS /* COV_VMEM_30_TRAVEO2CYP01_NOUNIT */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_GetPeripheralRegionId
 *********************************************************************************************************************/
/*! \internal
 *  - Retrieve the os peripheral region Id basd of the given peripheral base address.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_Os_PeripheralIdType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_GetPeripheralRegionId /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress
)
{
    /* ----------- Local variables ----------------------------------------------------------------- */
    vMem_30_Traveo2Cyp01_Os_PeripheralIdType osPeripheralId;
    
    /* ----------- Implementation ------------------------------------------------------------------ */
    if(baseAddress == VMEM_30_TRAVEO2CYP01_BASE_FAULT)
    {
        osPeripheralId = VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_FAULT;
    }
    else if(baseAddress == VMEM_30_TRAVEO2CYP01_BASE_IPC)
    {
        osPeripheralId = VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_IPC;
    }
    else if(baseAddress == VMEM_30_TRAVEO2CYP01_BASE_FLASHC)
    {
        osPeripheralId = VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_FLASHC;
    }
    else
    {
        osPeripheralId = VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_FLASHC;
    }
    
    return osPeripheralId;
} /* vMem_30_Traveo2Cyp01_GetPeripheralRegionId() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr
 *********************************************************************************************************************/
/*! \internal
 *  - Create a variable volatile pointer to the register the caller wants to address within the register space of the peripheral.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegVarVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
)
{
  return (vMem_30_Traveo2Cyp01_RegVarVolatilePtrType)(baseAddress + regOffset);                                         /* PRQA S 0303 */ /* MD_vMem_30_Traveo2Cyp01_0303_RegisterVolatileAccess */
} /* vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr
 *********************************************************************************************************************/
/*! \internal
 *  - Create a constant volatile pointer to the register the caller wants to address within the register space of the peripheral.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegConstVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
)
{
  return (vMem_30_Traveo2Cyp01_RegConstVolatilePtrType)(baseAddress + regOffset);                                       /* PRQA S 0303 */ /* MD_vMem_30_Traveo2Cyp01_0303_RegisterVolatileAccess */
} /* vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr
 *********************************************************************************************************************/
/*! \internal
 *  - Create a variable non-volatile pointer to the register the caller wants to address within the register space of the peripheral.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegVarNonVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
)
{
  return (vMem_30_Traveo2Cyp01_RegVarNonVolatilePtrType)(baseAddress + regOffset);                                      /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_RegisterAccess */
} /* vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr
 *********************************************************************************************************************/
/*! \internal
 *  - Create a constant non-volatile pointer to the register the caller wants to address within the register space of the peripheral.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegConstNonVolatilePtrType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
)
{
  return (vMem_30_Traveo2Cyp01_RegConstNonVolatilePtrType)(baseAddress + regOffset);                                    /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_RegisterAccess */
} /* vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_SetBitMask
 *********************************************************************************************************************/
/*! \internal
 *  - Set the given bit mask within the addressed register.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_SetBitMask        /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
)
{
  vMem_30_Traveo2Cyp01_Reg_Write(baseAddress, regOffset, vMem_30_Traveo2Cyp01_Reg_Read(baseAddress, regOffset) | bitMask);
} /* vMem_30_Traveo2Cyp01_Reg_SetBitMask() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_ClearBitMask
 *********************************************************************************************************************/
/*! \internal
 *  - Clear the given bit mask within the addressed register.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_ClearBitMask      /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
)
{
  vMem_30_Traveo2Cyp01_Reg_Write(baseAddress, regOffset, vMem_30_Traveo2Cyp01_Reg_Read(baseAddress, regOffset) & ~bitMask);
} /* vMem_30_Traveo2Cyp01_Reg_ClearBitMask() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_ReadBits
 *********************************************************************************************************************/
/*! \internal
 *  - Read the value of the addressed register, apply bit mask and provide the result to the caller.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegWidthType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_ReadBits /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask
)
{
  return (vMem_30_Traveo2Cyp01_Reg_Read(baseAddress, regOffset) & bitMask);
} /* vMem_30_Traveo2Cyp01_Reg_ReadBits() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_WriteBits
 *********************************************************************************************************************/
/*! \internal
 *  - Clear bit mask and set the given value within the addressed register.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_WriteBits         /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   bitMask,
    vMem_30_Traveo2Cyp01_RegWidthType   bitsValue
)
{
  vMem_30_Traveo2Cyp01_Reg_ClearBitMask(baseAddress, regOffset, bitMask);
  vMem_30_Traveo2Cyp01_Reg_SetBitMask(baseAddress, regOffset, bitsValue);
} /* vMem_30_Traveo2Cyp01_Reg_WriteBits() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_Read
 *********************************************************************************************************************/
/*! \internal
 *  - Read the value of the addressed register and provide the result to the caller.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(vMem_30_Traveo2Cyp01_RegWidthType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_Read /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset
)
{
  vMem_30_Traveo2Cyp01_RegWidthType regValue;

  if(vMem_30_Traveo2Cyp01_IsUsePeripheralAccessApiEnabled()) /* PRQA S 2741, 2742 */ /* MD_vMem_30_Traveo2Cyp01_ConstValue */
  {   
    regValue = vMem_30_Traveo2Cyp01_CallOsReadPeripheral32(vMem_30_Traveo2Cyp01_GetPeripheralRegionId(baseAddress),     /* PRQA S 2880 */ /* MD_MSR_Unreachable */
                                                           vMem_30_Traveo2Cyp01_CreateConstNonVolatileRegPtr(baseAddress, regOffset));
  }
  else
  {
    regValue = *(vMem_30_Traveo2Cyp01_CreateConstVolatileRegPtr(baseAddress, regOffset));                               /* PRQA S 2880 */ /* MD_MSR_Unreachable */
  }
  return regValue;
} /* vMem_30_Traveo2Cyp01_Reg_Read() */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Reg_Write
 *********************************************************************************************************************/
/*! \internal
 *  - Write the given value to the addressed register.
 *  \endinternal
 */
VMEM_30_TRAVEO2CYP01_REG_ACCESS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Reg_Write             /* PRQA S 3219 */ /* MD_vMem_30_Traveo2Cyp01_3219 */
(
    vMem_30_Traveo2Cyp01_RegAddressType baseAddress,
    vMem_30_Traveo2Cyp01_RegOffsetType  regOffset,
    vMem_30_Traveo2Cyp01_RegWidthType   regValue
)
{
  if(vMem_30_Traveo2Cyp01_IsUsePeripheralAccessApiEnabled())                                                            /* PRQA S 2741, 2742 */ /* MD_vMem_30_Traveo2Cyp01_ConstValue */
  {
    vMem_30_Traveo2Cyp01_CallOsWritePeripheral32(vMem_30_Traveo2Cyp01_GetPeripheralRegionId(baseAddress), 
                                                 vMem_30_Traveo2Cyp01_CreateVarNonVolatileRegPtr(baseAddress, regOffset),
                                                 regValue);                                                             /* PRQA S 2880 */ /* MD_MSR_Unreachable */ 
  }
  else
  {
    *(vMem_30_Traveo2Cyp01_CreateVarVolatileRegPtr(baseAddress, regOffset)) = regValue;                                 /* VCA_VMEM_REGACCESS */ /* PRQA S 2880 */ /* MD_MSR_Unreachable */
  }
} /* vMem_30_Traveo2Cyp01_Reg_Write() */

# endif /* VMEM_30_TRAVEO2CYP01_NOUNIT_VMEM_LL_REGACCESS */

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_LL_REGACCESS_INT_H */

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TRAVEO2CYP01_NOUNIT
 \ACCEPT TX
 \REASON This directiv is needed because this logical unit contains only inline functions which are fully implemented in 
         the header. To make it possible to mock this unit when testing other units, this directiv disables the actual 
         implementation.

END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_LL_RegAccess_Int.h
 *********************************************************************************************************************/
