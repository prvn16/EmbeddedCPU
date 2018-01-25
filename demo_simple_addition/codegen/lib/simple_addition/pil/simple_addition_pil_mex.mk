START_DIR = C:\Sumpurn\Project\SEMBED~1\DEMO_S~1

MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2017b
MAKEFILE = simple_addition_pil_mex.mk

include simple_addition_pil_mex.mki


SRC_FILES =  \
	simple_addition_pil.c \
	_coder_simple_addition_info.c \
	_coder_simple_addition_api.c \
	_coder_simple_addition_mex.c \
	c_mexapi_version.c

MEX_FILE_NAME_WO_EXT = simple_addition_pil
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = 


#
#====================================================================
# gmake makefile fragment for building MEX functions using MSVC
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLIST  = $(OBJLISTC:.cpp=.$(OBJEXT))

TARGETMT = $(TARGET).manifest
MEX = $(TARGETMT)
STRICTFP = /fp:strict

target: $(MEX)

MATLAB_INCLUDES = /I "$(MATLAB_ROOT)\simulink\include"
MATLAB_INCLUDES+= /I "$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(MATLAB_INCLUDES)

# Additional includes

SYS_INCLUDE += /I "$(START_DIR)"
SYS_INCLUDE += /I "$(START_DIR)\codegen\lib\simple_addition\interface"
SYS_INCLUDE += /I "$(START_DIR)\codegen\lib\simple_addition"
SYS_INCLUDE += /I "$(MATLAB_ROOT)\rtw\c\src\rtiostream\utils"
SYS_INCLUDE += /I "$(MATLAB_ROOT)\toolbox\coder\profile\src"
SYS_INCLUDE += /I "$(MATLAB_ROOT)\extern\include"
SYS_INCLUDE += /I "."

DIRECTIVES = $(MEX_FILE_NAME_WO_EXT)_mex.arf
COMP_FLAGS = $(COMPFLAGS) $(OMPFLAGS)
LINK_FLAGS = $(filter-out /export:mexFunction, $(LINKFLAGS))
LINK_FLAGS += /NODEFAULTLIB:LIBCMT
ifeq ($(EMC_CONFIG),optim)
  COMP_FLAGS += $(OPTIMFLAGS) $(STRICTFP)
  LINK_FLAGS += $(LINKOPTIMFLAGS)
else
  COMP_FLAGS += $(DEBUGFLAGS)
  LINK_FLAGS += $(LINKDEBUGFLAGS)
endif
LINK_FLAGS += $(OMPLINKFLAGS)
LINK_FLAGS += /OUT:$(TARGET)
LINK_FLAGS +=   $(MATLAB_ROOT)\extern\lib\win64\microsoft\libfixedpoint.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwcoder_CodeInstrHostAppSvc.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwcoder_CoderAssumpHostAppSvc.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwcoder_XILHostAppSvc.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwrtiostreamutils.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwxilcomms_rtiostream.lib  $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwxilutils.lib

CFLAGS = $(COMP_FLAGS)  -DMATLAB_MEX_FILE  $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(COMP_FLAGS)  -DMATLAB_MEX_FILE  $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CC) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\lib\simple_addition\interface/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\lib\simple_addition\pil/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : ..\./%.c
	$(CC) $(CFLAGS) "$<"



%.$(OBJEXT) : /%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\lib\simple_addition\interface/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\lib\simple_addition\pil/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : ..\./%.cpp
	$(CC) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(LINK_FLAGS) $(OBJLIST) $(USER_LIBS) $(SYS_LIBS) @$(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

$(TARGETMT): $(TARGET)
	mt -outputresource:"$(TARGET);2" -manifest "$(TARGET).manifest"

#====================================================================

