###########################################################################
## Makefile generated for Simulink model 'arm_cortex_a_gettingstarted'. 
## 
## Makefile     : arm_cortex_a_gettingstarted.mk
## Generated on : Sun Jan 21 09:25:18 2018
## MATLAB Coder version: 3.4 (R2017b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/arm_cortex_a_gettingstarted.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = arm_cortex_a_gettingstarted
MAKEFILE                  = arm_cortex_a_gettingstarted.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2017b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2017b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Sumpurn/Project/sEmbeddedCPU/work/codegen
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
MODELREF_LINK_RSPFILE_NAME = arm_cortex_a_gettingstarted_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Linaro Toolchain v4.8 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2017b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_PKG_INSTALLDIR
# LINARO_TOOLCHAIN_4_8

#-----------
# MACROS
#-----------

SHELL                 = %SystemRoot%/system32/cmd.exe
CCOUTPUTFLAG          = --output_file=
LDOUTPUTFLAG          = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Linaro Toolchain4.8 Assembler
AS_PATH = $(LINARO_TOOLCHAIN_4_8)
AS = $(AS_PATH)/arm-linux-gnueabihf-as

# C Compiler: Linaro Toolchain4.8 C Compiler
CC_PATH = $(LINARO_TOOLCHAIN_4_8)
CC = $(CC_PATH)/arm-linux-gnueabihf-gcc

# Linker: Linaro Toolchain4.8 Linker
LD_PATH = $(LINARO_TOOLCHAIN_4_8)
LD = $(LD_PATH)/arm-linux-gnueabihf-gcc

# C++ Compiler: Linaro Toolchain4.8 C++ Compiler
CPP_PATH = $(LINARO_TOOLCHAIN_4_8)
CPP = $(CPP_PATH)/arm-linux-gnueabihf-g++

# C++ Linker: Linaro Toolchain4.8 C++ Linker
CPP_LD_PATH = $(LINARO_TOOLCHAIN_4_8)
CPP_LD = $(CPP_LD_PATH)/arm-linux-gnueabihf-g++

# Archiver: Linaro Toolchain4.8 Archiver
AR_PATH = $(LINARO_TOOLCHAIN_4_8)
AR = $(AR_PATH)/arm-linux-gnueabihf-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD_PATH = $(TARGET_PKG_INSTALLDIR)
DOWNLOAD = $(DOWNLOAD_PATH)/ssh_download.bat

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -ruvs
ASFLAGS              = -c \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O0
CPPFLAGS             = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O2
CPP_LDFLAGS          = -lm -lrt -lpthread -ldl
CPP_SHAREDLIB_LDFLAGS  = -shared  \
                         -lm -lrt -lpthread -ldl
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
LDFLAGS              = -lm -lrt -lpthread -ldl
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared  \
                       -lm -lrt -lpthread -ldl

#--------------------
# File extensions
#--------------------

ASM_EXT             = .s.dep
ASMOBJ_EXT          = .s.o
ASM_EXT             = .s
C_EXT               = .c.dep
H_EXT               = .h
COBJ_EXT            = .c.o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
CPP_EXT             = .cpp.dep
HPP_EXT             = .hpp
CPPOBJ_EXT          = .pp.o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/arm_cortex_a_gettingstarted.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_ROOT)/simulink/include/sf_runtime -IC:/ProgramData/MATLAB/SupportPackages/R2017b/3P.instrset/ne10library.instrset/Ne10-1.1.2/inc -IC:/ProgramData/MATLAB/SupportPackages/R2017b/3P.instrset/ne10library.instrset/Ne10-1.1.2/common -IC:/ProgramData/MATLAB/SupportPackages/R2017b/toolbox/target/supportpackages/arm_cortex_a_crl/crl -I$(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw -IC:/Sumpurn/Project/sEmbeddedCPU/models -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -IC:/ProgramData/MATLAB/SupportPackages/R2017b/toolbox/target/supportpackages/arm_cortex_a/include -IC:/ProgramData/MATLAB/SupportPackages/R2017b/toolbox/target/supportpackages/arm_cortex_a/blocks/sfcn/include -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=arm_cortex_a_gettingstarted -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DARM_PROJECT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT
DEFINES_BUILD_ARGS = -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DARM_PROJECT -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=arm_cortex_a_gettingstarted -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw/arm_cortex_a_gettingstarted.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c

MAIN_SRC = $(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = arm_cortex_a_gettingstarted.c.o linuxinitialize.c.o

MAIN_OBJ = ert_main.c.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : $(START_DIR)/arm_cortex_a_gettingstarted_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.pp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


linuxinitialize.c.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c
	$(CC) $(CFLAGS) -o $@ $<


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(RM) *.s.dep
	$(ECHO) "### Deleted all derived files."

