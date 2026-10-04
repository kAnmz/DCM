###############################################################################
# File Name  : MemAcc_rules.mak
# Description: Rules makefile
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2025 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2022-12-13  vireno  Initial version.
# main-1    2023-11-07  smacht  MEMSLP-7953 Change history is maintained in
#                               the global ChangeHistory.txt file starting with
#                               this release.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_BBM.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_BBMJobManager.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_ErrorCheck.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_JobProcessing.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_MainFsm.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_MemAb.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_MemAccessControl.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_MultiBinary.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_Queue.c
CC_FILES_TO_BUILD       += MemAcc$(BSW_SRC_DIR)\MemAcc_Utils.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\MemAcc_Lcfg.c


