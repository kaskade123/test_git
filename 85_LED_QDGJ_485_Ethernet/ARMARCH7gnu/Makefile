# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = ARMARCH7gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /home/builder/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/85_LED_QDGJ_485_Ethernet



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = arm
CPU = ARMARCH7
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin
DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin
DEBUGFLAGS_Linker =  -O2  -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = 85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet.out \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage.o


#Rules

# 85_LED_QDGJ_485_Ethernet
ifeq ($(DEBUG_MODE),1)
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : IDE_LIBRARIES = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : PROJECT_TYPE = DKM
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : DEFINES = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : EXPAND_DBG = 0
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : CPU = ARMARCH7
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : TOOL_FAMILY = gnu
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : TOOL = gnu
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : TOOL_PATH = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : LIBPATH = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : LIBS = 
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/% : OBJ_DIR := 85_LED_QDGJ_485_Ethernet/$(MODE_DIR)

OBJECTS_85_LED_QDGJ_485_Ethernet = 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage.o

ifeq ($(TARGET_JOBS),1)
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet.out : $(OBJECTS_85_LED_QDGJ_485_Ethernet)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmarm $(OBJECTS_85_LED_QDGJ_485_Ethernet) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c arm -tags $(VSB_DIR)/tags/arm/ARMARCH7/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall   $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_85_LED_QDGJ_485_Ethernet) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet.out : 85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet.out_jobs

endif
85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_compile_file : $(FILE) ;

_clean :: 85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_clean

85_LED_QDGJ_485_Ethernet/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_clean : 
	$(TRACE_FLAG)if [ -d "85_LED_QDGJ_485_Ethernet" ]; then cd "85_LED_QDGJ_485_Ethernet"; rm -rf $(MODE_DIR); fi


# 85_LED_QDGJ_485_Ethernet_partialImage
ifeq ($(DEBUG_MODE),1)
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : DEFINES = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : CPU = ARMARCH7
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : TOOL = gnu
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : LIBPATH = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : LIBS = 
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/% : OBJ_DIR := 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)

85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/485_routine.o : $(PRJ_ROOT_DIR)/485_routine.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/85_LED_485_Eth_MAIN.o : $(PRJ_ROOT_DIR)/85_LED_485_Eth_MAIN.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Allprint_routine.o : $(PRJ_ROOT_DIR)/Allprint_routine.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Ethernet_routine.o : $(PRJ_ROOT_DIR)/Ethernet_routine.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/LED_routine.o : $(PRJ_ROOT_DIR)/LED_routine.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Lib.o : $(PRJ_ROOT_DIR)/Lib.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/QDGJ_routine.o : $(PRJ_ROOT_DIR)/QDGJ_routine.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/print_error_lib.o : $(PRJ_ROOT_DIR)/print_error_lib.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/taskSpawn_Eth.o : $(PRJ_ROOT_DIR)/taskSpawn_Eth.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/xd_globals.o : $(PRJ_ROOT_DIR)/xd_globals.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_85_LED_QDGJ_485_Ethernet_partialImage = 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/485_routine.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/85_LED_485_Eth_MAIN.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Allprint_routine.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Ethernet_routine.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/LED_routine.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Lib.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/QDGJ_routine.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/print_error_lib.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/taskSpawn_Eth.o \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/xd_globals.o

ifeq ($(TARGET_JOBS),1)
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage.o : $(OBJECTS_85_LED_QDGJ_485_Ethernet_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL  -o "$@" $(OBJECTS_85_LED_QDGJ_485_Ethernet_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage.o : 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage.o_jobs

endif
85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage_compile_file : $(FILE) ;

_clean :: 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage_clean

85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/85_LED_QDGJ_485_Ethernet_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "85_LED_QDGJ_485_Ethernet_partialImage" ]; then cd "85_LED_QDGJ_485_Ethernet_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/485_routine.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/85_LED_485_Eth_MAIN.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Allprint_routine.d \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Ethernet_routine.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/LED_routine.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/Lib.d \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/QDGJ_routine.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/print_error_lib.d 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/taskSpawn_Eth.d \
	 85_LED_QDGJ_485_Ethernet_partialImage/$(MODE_DIR)/Objects/85_LED_QDGJ_485_Ethernet/xd_globals.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
