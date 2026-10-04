/****************************************************************************
| Project Name: Security Module
|    File Name: SecM_def.H
|
|  Description: Global definitions for security module
|
|-----------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------
| Copyright (c) 2006-2009 by Vector Informatik GmbH, all rights reserved
|-----------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   ---------------------------
|  Cb            Christian Baeuerle    Vector Informatik GmbH
|  Hp            Armin Happel          Vector Informatik GmbH
|  Ls            Konrad Lazarus        Vector Informatik GmbH
|  WM            Marco Wierer          Vector Informatik GmbH
|-----------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------
| Date        Ver   Author   Description
| ----------  ---   ------   -------------------------------------
|
|*****************************************************************************/

#ifndef __SECM_DEF_H_
#define __SECM_DEF_H_

/* Includes ******************************************************************/

/* Defines *******************************************************************/
#define SECM_OK      0x00
#define SECM_NOT_OK  0xFF

#define SECM_CALL_TYPE
/* Typedefs ******************************************************************/
typedef vuint8  SecM_StatusType;
typedef vuint32 SecM_WordType;
typedef vuint16 SecM_LengthType;

typedef vuint32 SecM_AddrType;
typedef vuint32 SecM_SizeType;

/* FL_SegmentInfoType describes a download segment */
typedef struct tagFL_SegmentInfoType
{
   SecM_AddrType transferredAddress;
   SecM_AddrType targetAddress;
   SecM_SizeType length;
}FL_SegmentInfoType;

/* List of downloaded segments */
typedef struct tagFL_SegmentListType
{
   vuint8                nrOfSegments;
   FL_SegmentInfoType*   segmentInfo;
}FL_SegmentListType;


typedef vuint8 (* FL_WDTriggerFctType)(void);
typedef SecM_SizeType (*FL_ReadMemoryFctType)(SecM_AddrType, vuint8 *, SecM_SizeType);



#endif
/******************************************************************************
*******************************************************************************/
