/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_DataIntegrityRecalcQueue.c
 *        \brief  NvM_DataIntegrityRecalcQueue source file
 *      \details  Implementation of the queue unit of the NvM.
 *         \unit  NvM_DataIntegrityRecalcQueue
 *
 *
 * This unit stores IDs of blocks that require background recalculation of the DataIntegrityRecord.
 * IDs for this unit must be references of NvM_BlockDescriptor[], therefore are bound to the related type definition of
 * NvM_BlockDescriptorLookupTableIdType.
 *
 * The implementation is based on a bit-string that stores the IDs as a position in a bitmask.
 * This allows to store 32 IDs per stored entry and therefore saves a lot of footprint.
 *
 * It is not designed to function in any queue principle such as FIFO or similar.
 * It simply stores all relevant recalculations and provides it in a fixed order that is defined by the POP mechanism.
 *
 * Example: Calling following sequence ...
 *   Push(1);
 *   Push(10);
 *   Push(31);
 *   Push(42);
 *
 * ... leads to a stored (BINARY) data representation of:
 *   0b10000000 00000000 00000100 00000010 IDs    1  -   31
 *   0b00000000 00000000 00000100 00000000 IDs   32  -   63
 *   0b00000000 00000000 00000000 00000000 IDs   64  -   95
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATAINTEGRITYRECALCQUEUE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityRecalcQueue.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_DataIntegrityRecalcQueue_CountTrailingZeroes()
 *********************************************************************************************************************/
/*! \brief           Counts number of trailing zeroes.
 *  \details         -
 *  \param[in]       word               Word to count trailing zeroes. Must not be 0.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Number of counted trailing zeroes.
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(uint8, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_CountTrailingZeroes(
  const NvM_DataIntegrityRecalcQueueEntryType word);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

 /**********************************************************************************************************************
  * NvM_DataIntegrityRecalcQueue_CountTrailingZeroes()
  *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
NVM_LOCAL_INLINE FUNC(uint8, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_CountTrailingZeroes(
  const NvM_DataIntegrityRecalcQueueEntryType word)
{
  /*
    This code computes the number of trailing zeroes by the idea of a binary search.

    It checks the lower 16 bits for being zero. If so, it adds 16 to the result count and shifts the temporary word for the 16 bits.
    Then the same for the next 8 bits, 4, bits, etc.
   */

  uint8 trailingZeroes = 0u;

  NvM_DataIntegrityRecalcQueueEntryType currWord = word;

  /* is none of the lower 16 bits set? */
  if ((currWord & 0xFFFFu) == 0u)
  {
    trailingZeroes |= 0x10u;
    currWord >>= 16u;
  }

  /* is none of the lower 8bits set? */
  if ((currWord & 0xFFu) == 0u)
  {
    trailingZeroes |= 0x08u;
    currWord >>= 8u;
  }

  /* is none of the lower 4 bits set?*/
  if ((currWord & 0x0Fu) == 0u)
  {
    trailingZeroes |= 0x04u;
    currWord >>= 4u;
  }

  /* is none of the lower 2 bits set? */
  if ((currWord & 0x03u) == 0u)
  {
    trailingZeroes |= 2u;
    currWord >>= 2u;
  }

  /* Process remaining least 2 bits; one of the bits must be set as checked in the above code.
   *  IF the LSB is set, add nothing as no trailing zeroes exist
   *  ELSE add 1.
   */
  trailingZeroes |= (uint8)((currWord & 1u) ^ 1u);

  return trailingZeroes;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_DataIntegrityRecalcQueue_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Init(NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr)
{
  for (uint16 i = 0u; i < NVM_DATAINTEGRITYRECALCQUEUE_ELEMENTCOUNT; i++)
  {
    queuePtr->entries[i] = 0u;
  }
}

/**********************************************************************************************************************
 *  NvM_DataIntegrityRecalcQueue_Push
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Push(
    NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr,
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId
)
{
  /* Each entry can store 32 ID per entry, find the entry for the requested ID
     Because the VCA tool does currently not support the shift operator, there are two options:
     1. Use a mathematical operation instead
     2. Introduce a justification
     Because there exists a solution without justification, this was the preferred option
     event if the first one would be a bit faster. */
  const uint16 queueEntryPosition = blockDescriptorLookupTableId / NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_BITS;
  const NvM_DataIntegrityRecalcQueueEntryPtrType queueEntryPtr = &queuePtr->entries[queueEntryPosition];

  /* Execute modulo(32) on ID, shift bit for the given result to left to store the ID as a bitposition */
  const NvM_DataIntegrityRecalcQueueEntryType bitmaskRelativeIdStorage =
      (((NvM_DataIntegrityRecalcQueueEntryType)1u) << (blockDescriptorLookupTableId & NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_BITMASK));

  *queueEntryPtr |= bitmaskRelativeIdStorage;
}

/**********************************************************************************************************************
 *  NvM_DataIntegrityRecalcQueue_Pop
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Pop(
    NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr,
    NvM_BlockDescriptorLookupTableIdType* blockDescriptorLookupTableIdPtr
)
{
  Std_ReturnType retVal = E_NOT_OK;

  for (uint16 i = 0u; i < NVM_DATAINTEGRITYRECALCQUEUE_ELEMENTCOUNT; i++)
  {
    const NvM_DataIntegrityRecalcQueueEntryType currentEntry = queuePtr->entries[i];

    if (currentEntry != 0u)
    {
      const uint8 trailingZeroes = NvM_DataIntegrityRecalcQueue_CountTrailingZeroes(currentEntry);

      /* Set correct base for word index */
      const NvM_BlockDescriptorLookupTableIdType baseId = (i << NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_SHIFT);

      /* Calculate real block ID taking trailing zeroes into account */
      const NvM_BlockDescriptorLookupTableIdType poppedId = (baseId | trailingZeroes);                                                /* PRQA S 2986 */ /* MD_NvM_DataIntegrityRecalcQueue_RedundantOperand */

      /* Assign out-pointer value */
      *blockDescriptorLookupTableIdPtr = poppedId;

      /* Clear queue entry */
      queuePtr->entries[i] ^= (((NvM_DataIntegrityRecalcQueueEntryType)1u) << (trailingZeroes));

      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_NvM_DataIntegrityRecalcQueue_RedundantOperand
  Reason:     Currently the NvM configurations do not have more than 32 blocks, which has as consequence that the macro
              NVM_DATAINTEGRITYRECALCQUEUE_ELEMENTCOUNT is evaluated to 1. Therefore the for loop within the function
              NvM_DataIntegrityRecalcQueue_Pop() is entered only once. This leads to the warning that the result of
              calculating the poppedId is independent of the left hand operand. This is because the baseId is both 0
              and the left hand operand in case the loop is only entered once.
  Risk:       None.
  Prevention: The configuration CfgSinglePartition was adapted to contain more that 32 blocks. This allows to proof
              that the code is correct. To avoid manually adapting all configurations, this will be skipped until
              MEMSLP-10340 is implemented. As soon as this is available, all configurations can be easily extended
              and this justification can be removed.

*/
/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityRecalcQueue.c
 *********************************************************************************************************************/
