###############################################################################
# File Name  : Mem_30_LegacyAdapter_rules.mak
# Description: Rules makefile
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2025 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += Mem_30_LegacyAdapter$(BSW_SRC_DIR)\Mem_30_LegacyAdapter.c
CC_FILES_TO_BUILD       += Mem_30_LegacyAdapter$(BSW_SRC_DIR)\Mem_30_LegacyAdapter_LLAdapter.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\Mem_30_LegacyAdapter_Lcfg.c

# Library Settings
LIBRARIES_TO_BUILD      += Mem_30_LegacyAdapter

