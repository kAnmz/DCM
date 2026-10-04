############################################################################### 
# File Name  : vMem_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2025 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD        += vMem_30_Traveo2Cyp01$(BSW_SRC_DIR)\vMem_30_Traveo2Cyp01.c     \
                            vMem_30_Traveo2Cyp01$(BSW_SRC_DIR)\vMem_30_Traveo2Cyp01_DetChecks.c  \
                            vMem_30_Traveo2Cyp01$(BSW_SRC_DIR)\vMem_30_Traveo2Cyp01_LL.c  \
                            vMem_30_Traveo2Cyp01$(BSW_SRC_DIR)\vMem_30_Traveo2Cyp01_LL_Ipc.c \
                            vMem_30_Traveo2Cyp01$(BSW_SRC_DIR)\vMem_30_Traveo2Cyp01_LL_FlashMgtLib.c
GENERATED_SOURCE_FILES   += $(GENDATA_DIR)\vMem_30_Traveo2Cyp01_Lcfg.c

