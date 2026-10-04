############################################################################### 
# File Name  : Fee_30_FlexNor_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2021 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2007-06-13  visaba  Initial Version of Template (1.0)
# 1.01.00   2017-05-30  vismas  Clean-up
# 1.02.00   2019-01-22  vircbl  Added support of component-based SIP structure
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Chunk.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ChunkFactory.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ChunkMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ChunkSearch.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ChunkSearchMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ConfigInterface.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_CopyBlock.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_CopyBlockMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_DiagnosticHandler.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_ErrorChecks.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_FlashAccess.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_FlashAccessMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_GarbageCollection.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_GarbageCollectionMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Initializer.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Instance.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_InstanceFactory.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_InternalJobs.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_InternalJobsMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_LookupTable.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_LookupTableMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Partition.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_PartitionMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Scheduler.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Sector.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SectorContainer.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SectorMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SecureChunk.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SecureChunkMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SecureInstance.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SecureInstanceMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Shared.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SlimChunk.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SlimChunkMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SlimInstance.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_SlimInstanceMachine.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_Startup.c
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor_StartupMachine.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\Fee_30_FlexNor_Lcfg.c
