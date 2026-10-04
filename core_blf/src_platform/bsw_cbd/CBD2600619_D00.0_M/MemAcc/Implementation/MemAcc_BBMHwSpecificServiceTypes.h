/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  MemAcc_BBMHwSpecificServiceTypes.h
 *        \brief  MemAcc types header file
 *      \details  Defines HwSpecificService types to call on Mem.
 *         \unit  MemAcc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_BBMHWSPECIFICSERVICETYPES_H)
# define MEMACC_BBMHWSPECIFICSERVICETYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_GeneralTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*!< ID for the synchronous HwSpecifcService to get the last error of the Mem.
  dataPtr:   Pointer to a variable of type MemAcc_MemLastErrorJobDataType
  lengthPtr: Pointer to size of MemAcc_MemLastErrorJobDataType.
  return: E_OK if job accepted; E_NOT_OK if job rejected;
*/
# define MEMACC_MEMHWSID_GETLASTERROR   ((MemAcc_MemHwServiceIdType) 0u)

/*!< ID for the asynchronous HwSpecifcService to recover data of a specific length from one sector to another.
  dataPtr:   Pointer to a variable of type MemAcc_MemRecoverDataJobDataType
  lengthPtr: Pointer to size of MemAcc_MemRecoverDataJobDataType.
  return: E_OK if job accepted; E_NOT_OK if job rejected;
*/
# define MEMACC_MEMHWSID_RECOVERDATA     ((MemAcc_MemHwServiceIdType) 1u)

/*!< ID for the asynchronous HwSpecifcService to write the BB Marker into a block.
  dataPtr:   Pointer to a variable of type MemAcc_MemWriteBBMarkerJobDataType
  lengthPtr: Pointer to size of MemAcc_MemWriteBBMarkerJobDataType.
  return: E_OK if job accepted; E_NOT_OK if job rejected;
*/
# define MEMACC_MEMHWSID_WRITEBBMARKER  ((MemAcc_MemHwServiceIdType) 2u)

/*!< ID for the asynchronous HwSpecifcService to read wether a BB Marker is written in a block.
  dataPtr:   Pointer to a variable of type MemAcc_MemReadBBMarkerJobDataType
  lengthPtr: Pointer to size of MemAcc_MemReadBBMarkerJobDataType.
  return: E_OK if job accepted; E_NOT_OK if job rejected;
*/
#define MEMACC_MEMHWSID_READBBMARKER    ((MemAcc_MemHwServiceIdType) 3u)

typedef enum
{
  MEMACC_MEMERRORTYPE_NONE = 0,                                   /*!< Indicates that no error occurred during the last job. */
  MEMACC_MEMERRORTYPE_P_FAIL,                                     /*!< Indicates that a P-Fail (Write/Programming Failed) occurred during the last job. This can happen during a Write job or during a HwSpecific job that writes internally. */
  MEMACC_MEMERRORTYPE_E_FAIL,                                     /*!< Indicates that an E-Fail (Erase Failed) occurred during the last job. This can happen during a Erase job or during a HwSpecific job that erases internally. */
  MEMACC_MEMERRORTYPE_UNKNOWN                                     /*!< Indicates that another fail than a P- or E-Fail occurred during the last job. */
} MemAcc_MemErrorType;                                            /*!< Type that indicates the type of error that occurred on the Mem. */

typedef struct
{
  MemAcc_AddressType    LastErrorSectorAddress;                  /*!< [out] Startaddress of the sector where the error occurred during the last job. */
  MemAcc_MemErrorType   LastErrorType;                           /*!< [out] Type of error that occurred. */
} MemAcc_MemLastErrorJobDataType;                                /*!< DataType for the HwSpecifcService MEMACC_MEMHWSID_GETLASTERROR. */

typedef struct
{
  MemAcc_AddressType SourceSectorAddress;                        /*!< [in] Startaddress of the sector from which data should be recovered. */
  MemAcc_AddressType TargetSectorAddress;                        /*!< [in] Startaddress of the sector where the data should be recovered to. */
  MemAcc_LengthType  Length;                                     /*!< [in] Length of the data to be recovered. */
} MemAcc_MemRecoverDataJobDataType;                              /*!< DataType for the HwSpecifcService MEMACC_MEMHWSID_RECOVERDATA. */

typedef MemAcc_AddressType MemAcc_MemWriteBBMarkerJobDataType;   /*!< [in] Startaddress of the sector which has to be marked as BB. DataType for the HwSpecifcService MEMACC_MEMHWSID_WRITEBBMARKER. */

typedef enum
{
  MEMACC_MEMBBMARKERSTATUS_SET = 0,                              /*!< Indicates that a bad block marker is set. */
  MEMACC_MEMBBMARKERSTATUS_NOT_SET                               /*!< Indicates that a bad block marker is not set. */
} MemAcc_MemBBMarkerStatusType;                                  /*!< Type that indicates if a bad block marker is set. */

typedef struct
{
  MemAcc_AddressType           BbSourceAddress;                  /*!< [in]  Startaddress of the block where the bad block marker should be read from. */
  MemAcc_MemBBMarkerStatusType IsBbMarkerSet;                    /*!< [out] Indicates if the bad block marker is set. */
} MemAcc_MemReadBBMarkerJobDataType;                             /*!< DataType for the HwSpecifcService MEMACC_MEMHWSID_READBBMARKER. */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* MEMACC_BBMHWSPECIFICSERVICETYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_BBMHwSpecificServiceTypes.h
 *********************************************************************************************************************/
