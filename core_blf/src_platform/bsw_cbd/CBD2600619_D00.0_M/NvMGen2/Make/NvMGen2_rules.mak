###############################################################################
# File Name  : NvMGen2_rules.mak
# Description: Rules makefile
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2026 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2007-06-13  visaba  Initial Version of Template (1.0)
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_BackgroundCrcRecalcFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataIntegrityCrc.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataIntegrityFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataIntegrityMac.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataIntegrityRecalcQueue.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataIntegrityService.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_DataSync.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ErrorCheck.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_FsmLib.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_GlobalUtilityLib.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_MasterCom.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_MultiBlockJobFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_MultiBlockProcessorFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_Notification.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_NvJobDispatcherFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_NvJobFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_NvServiceProcessorFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_Queue.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ReadAllFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ReadBlockFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ReadNvBlockFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ResetNvBlockFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_SatelliteCom.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ServiceProcessorFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_SingleBlockJobFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_ValidateAllFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_WriteAllFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_WriteBlockFsm.c
CC_FILES_TO_BUILD       += NvMGen2$(BSW_SRC_DIR)\NvM_WriteNvBlockFsm.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\NvM*.c

# Library Settings
LIBRARIES_TO_BUILD      += NvMGen2
NVMGEN2_FILES 			= NvMGen2$(BSW_SRC_DIR)\NvM*.c
