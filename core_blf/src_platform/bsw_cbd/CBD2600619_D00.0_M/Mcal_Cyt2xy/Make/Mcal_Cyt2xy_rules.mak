###############################################################################
# File Name  : Mcal_Cyt2xy_rules.mak                                          #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2022 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign    Description                                   #
# ----------   -------  ------  ----------------------------------------------#
# 2018-08-27   1.00.00	virova	CYT2xy - Initial Revision			          #
# 2019-03-29   1.01.00	virgki	CYT2xy - Add the mak path to                  # 
#                       compile the library files of spi 			          #
# 2019-04-17   1.01.00  virgki	Defaults for component switches               # 
#                                has been added for all modules               # 
# 2019-07-18   1.01.01  virnid	Integration of								  #
#							  BetaRel_WW1912_MCAL_IARSupport_TraveoII_v1e.0.0 #
# 2019-09-16   1.02.00	virgaj	Integration of                                #
#								ProdRel_WW1929_SW-MCAL-TraveoII_v1.2.4 and    #
#								BetaRel_WW1934_SW-MCAL-TraveoII_v1e.3.0		  #
# 2020-10-06   1.03.00  virnid	Integration of 								  #
#			   					BetaRel_WW2038_SW-MCAL-TraveoII_v1e.8.0		  #
# 2022-03-14   1.04.00	virnid	Integration of								  #
#								ProdRel_WW2210_SW-MCAL-TraveoII_v1.14.0		  #
# 2022-03-21   1.04.01	virnid	Change Wdg Assembler file handling			  #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#


#Defaults for component switches
#Can be overwritten in Makefile.Project.Part.Defines
ifeq ($(MCAL_EXCLUDE_ADC),)
MCAL_EXCLUDE_ADC = 0
endif
ifeq ($(MCAL_EXCLUDE_DIO),)
MCAL_EXCLUDE_DIO = 0
endif
ifeq ($(MCAL_EXCLUDE_FLS),)
MCAL_EXCLUDE_FLS = 0
endif
ifeq ($(MCAL_EXCLUDE_GPT),)
MCAL_EXCLUDE_GPT = 0
endif
ifeq ($(MCAL_EXCLUDE_ICU),)
MCAL_EXCLUDE_ICU = 0
endif
ifeq ($(MCAL_EXCLUDE_MCU),)
MCAL_EXCLUDE_MCU = 0
endif
ifeq ($(MCAL_EXCLUDE_OCU),)
MCAL_EXCLUDE_OCU = 0
endif
ifeq ($(MCAL_EXCLUDE_PORT),)
MCAL_EXCLUDE_PORT = 0
endif
ifeq ($(MCAL_EXCLUDE_PWM),)
MCAL_EXCLUDE_PWM = 0
endif
ifeq ($(MCAL_EXCLUDE_SPI),)
MCAL_EXCLUDE_SPI = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG),)
MCAL_EXCLUDE_WDG = 0
endif

#default compiler version if none is set in make file
ifeq ($(COMPILER_MANUFACTURER),)
COMPILER_MANUFACTURER = GHS
endif

#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_canlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      +=

# e.g.: CC_FILES_TO_BUILD       += drv\can_drv.c

#Path to Mcal source and include files
MCAL_PATH = ..\ThirdParty\Mcal_Cyt2xy\Supply\Tresos26_2_0

MCAL_DERIVATIVE = CYT2B94CAE

ADC_PLUGIN = Adc_TS_T40D13M1I0R0
BASE_PLUGIN = Base_TS_T40D13M1I0R0
DIO_PLUGIN = Dio_TS_T40D13M1I0R0
FLS_PLUGIN = Fls_TS_T40D13M1I0R0
GPT_PLUGIN = Gpt_TS_T40D13M1I0R0
ICU_PLUGIN = Icu_TS_T40D13M1I0R0
MCU_PLUGIN = Mcu_TS_T40D13M1I0R0
OCU_PLUGIN = Ocu_TS_T40D13M1I0R0
PORT_PLUGIN = Port_TS_T40D13M1I0R0
PWM_PLUGIN = Pwm_TS_T40D13M1I0R0
SPI_PLUGIN = Spi_TS_T40D13M1I0R0
WDG_PLUGIN = Wdg_TS_T40D13M1I0R0

BASE_PATH = $(MCAL_PATH)\plugins

CC_INCLUDE_PATH  += $(BASE_PATH)\$(BASE_PLUGIN)\include
#CC_INCLUDE_PATH  += $(BASE_PATH)\$(BASE_PLUGIN)\lib_include
#CC_INCLUDE_PATH  += $(BASE_PATH)\$(BASE_PLUGIN)\lib_include\CYT2

#ASM_FILES_TO_BUILD += $(BASE_PATH)\$(BASE_PLUGIN)\lib_src\CYT2\TSAtomic_Lib_Arch_Asm_GHS.s

ifneq ($(MCAL_EXCLUDE_ADC),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(ADC_PLUGIN)\src\Adc*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(ADC_PLUGIN)\lib_src\Adc*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(ADC_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(ADC_PLUGIN)\include
# temporary solution, because the *.h should not be stored in source Folder!
CC_INCLUDE_PATH  += $(BASE_PATH)\$(ADC_PLUGIN)\lib_src
endif

ifneq ($(MCAL_EXCLUDE_DIO),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(DIO_PLUGIN)\src\Dio*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(DIO_PLUGIN)\lib_src\Dio*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(DIO_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(DIO_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(FLS_PLUGIN)\src\Fls*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(FLS_PLUGIN)\lib_src\Fls*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(FLS_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(FLS_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(GPT_PLUGIN)\src\Gpt*.c 
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(GPT_PLUGIN)\lib_src\Gpt*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(GPT_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(GPT_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(ICU_PLUGIN)\src\Icu*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(ICU_PLUGIN)\lib_src\Icu*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(ICU_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(ICU_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(MCU_PLUGIN)\src\Mcu*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(MCU_PLUGIN)\lib_src\Mcu*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(MCU_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(MCU_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_OCU),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(OCU_PLUGIN)\src\Ocu*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(OCU_PLUGIN)\lib_src\Ocu*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(OCU_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(OCU_PLUGIN)\lib_src
CC_INCLUDE_PATH  += $(BASE_PATH)\$(OCU_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_PORT),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(PORT_PLUGIN)\src\Port*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(PORT_PLUGIN)\lib_src\Port*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(PORT_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(PORT_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_PWM),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(PWM_PLUGIN)\src\Pwm*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(PWM_PLUGIN)\lib_src\Pwm*c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(PWM_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(PWM_PLUGIN)\lib_src
CC_INCLUDE_PATH  += $(BASE_PATH)\$(PWM_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(SPI_PLUGIN)\src\Spi*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(SPI_PLUGIN)\lib_src\Spi*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(SPI_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(SPI_PLUGIN)\lib_src
CC_INCLUDE_PATH  += $(BASE_PATH)\$(SPI_PLUGIN)\include
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(WDG_PLUGIN)\src\Wdg*.c
CC_FILES_TO_BUILD  += $(BASE_PATH)\$(WDG_PLUGIN)\lib_src\Wdg*.c
CC_INCLUDE_PATH  += $(BASE_PATH)\$(WDG_PLUGIN)\lib_include
CC_INCLUDE_PATH  += $(BASE_PATH)\$(WDG_PLUGIN)\include
endif


CPP_FILES_TO_BUILD +=
ASM_FILES_TO_BUILD +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c

ifneq ($(MCAL_EXCLUDE_ADC),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Adc*.c
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fls*.c
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gpt*.c
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Icu*.c
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Mcu*.c
endif

ifneq ($(MCAL_EXCLUDE_OCU),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Ocu*.c
endif

ifneq ($(MCAL_EXCLUDE_PORT),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Port*.c
endif

ifneq ($(MCAL_EXCLUDE_PWM),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Pwm*.c
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Spi*.c
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg*.c
ifeq ($(COMPILER_MANUFACTURER),GHS)
ASM_GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_66_IA_Trigger_Asm_GHS.s
endif
ifeq ($(COMPILER_MANUFACTURER),IAR)
ASM_GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_66_IA_Trigger_Asm_IAR.s
endif
endif

ADDITIONAL_INCLUDES     += $(GENDATA_DIR)\include

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automatically.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


 
