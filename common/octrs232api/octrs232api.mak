#------------------------------- Relative utility path ---------------------------------#
#
# Specify the relative path ... where Makefile utilities are located
#
#---------------------------------------------------------------------------------------#
BUILD = ../../build

#---------------------------------- Application type -----------------------------------#
#
# Specify the application type: Exe, archive (.a) or dynamic lib (.so)
#
# APP_TYPE= exe, lib or dll
# APP_EXT=	# Allow to specify application extension (not use for librarie)
#
#---------------------------------------------------------------------------------------#
#APP_EXT=
APP_TYPE=lib


#------------------------------ Application or lib name --------------------------------#
#
# Specify the target file base name
#
#---------------------------------------------------------------------------------------#
APP_NAME = octrs232api


#----------------------------------- Makefile name -------------------------------------#
#
# Predefined in Makefile.pre 
# Default is $(APP_NAME).mak
# May be overrided
#
#---------------------------------------------------------------------------------------#
#MAKEFILENAME = 


#------------------------------------ Config name --------------------------------------#
#
# To use when same application may have various configurations
# Affect object path directory name: (see OBJPath )
# 	
#---------------------------------------------------------------------------------------#
#CONFIGNAME = 

#------------------------------- Object path definition --------------------------------#
#
# Predefined in Makefile.pre
# May be overrided
# Default is OBJPATH = $(CONFIGNAME_)$(BUILD_DIR)$(OBJ_PATH_SUFFIX)
#
#---------------------------------------------------------------------------------------#
#OBJPATH = 

#---------------------------- Application or lib full name -----------------------------#
#
# Predefined in Makefile.pre
# May be overrided
#
# where $(APP_FULL_NAME) = $(FILE_PREFIX)$(APP_NAME)$(CONFIGNAME)$(TGT_SUFFIX)$(FILE_EXT)
#---------------------------------------------------------------------------------------#
#APP_FULL_NAME = 

#-----------------------------------  Make utility -------------------------------------#
#
# Utility for target system and cross platform related utilities
#
#---------------------------------------------------------------------------------------#
include $(BUILD)/Makefile.pre


#----------------------------  Source file sub directory -------------------------------#
# 
# Directory where source file are located. (Related to this make file path )
#
#---------------------------------------------------------------------------------------#
SRC_DIR = source


#-----------------------------------  Source files -------------------------------------#
# 
# List of source files.
#
#---------------------------------------------------------------------------------------#
SRC_FILES = rs232.c io_porting.c

#-------------------------------- Library Dependencies ---------------------------------#
# 
# List of depended libraries ... automatically rebuild by make 'all' rules
#
#---------------------------------------------------------------------------------------#
#OCTLIB_DEP = 

#------------------------------------- Other libs --------------------------------------#
# 
# Other libs to link with
#
#---------------------------------------------------------------------------------------#
OCTLIBS +=

#--------------------------------  Post build command ----------------------------------#
# 
# Normally use to copy and remove libs to default path $(BUILD)../lib
#
#---------------------------------------------------------------------------------------#
POSTBUILD = $(COPY) $@ $(BUILD)/../$(PRJ_LIB_PATH)
POSTBUILD_CLEAN = $(RM) $(BUILD)/../$(PRJ_LIB_PATH)/$(APP_FULL_NAME)

#----------------------  List of application specific includes -------------------------#
# 
#---------------------------------------------------------------------------------------#
INC +=

#------------------------- List of application specific flags --------------------------#
# 
#---------------------------------------------------------------------------------------#
CCFLAGS +=

#-------------------------------- Defaults make rules ----------------------------------#
# 
#---------------------------------------------------------------------------------------#
include $(BUILD)/Makefile.rules
