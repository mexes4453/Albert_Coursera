# -*- Makefile -*-
#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <This makefile is used to compile object files required to build target programs>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Native Compile - HOST
#       Cross Compile  - MSP432>
#
# Platform Overrides:
#      <The following flags are overriden for the build targets
#          -> CFLAGS
#          -> CC
#          -> OBJDUMP
#          -> LDFLAGS
#          -> SOURCES 
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Defines
CC = 
LD = 
LDFLAGS = 
CFLAGS = 
OBJDUMP = 

ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ./msp432p401r.lds
	CPU   = cortex-m4
	ARCH  = thumb
	SPECS = nosys.specs
	MARCH = armv7e-m
	FLOAT = hard
	FPU   = fpv4-sp-d16
        
        # Defines
	OBJDUMP = arm-none-eabi-objdump
	TARGET_SIZE = arm-none-eabi-size
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS  = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE)
	CFLAGS   = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(MARCH) \
                   -mfloat-abi=$(FLOAT) -mfpu=$(FPU) -DMSP432 -DCOURSE1 -DVERBOSE

else    # define overriding for PLATFORM - HOST
	OBJDUMP = objdump
	TARGET_SIZE = size
	CC = gcc
	CFLAGS = -DHOST -DCOURSE1 #-DVERBOSE
	LDFLAGS = -Wl,-Map=$(BASENAME).map
	#SOURCES = ./main.c   \
	#          ./memory.c 
    # etc
endif


# Compiler Flags and Defines
BASENAME = c1m3
TARGET   = $(BASENAME).out
GCFLAGS  = -Wall -Werror -g -std=c99 -O0  # General Compiler flags
CPPFLAGS = -E 
OBJS = $(SOURCES:.c=.o)

# ------ Dependency flags ---------------
# -MT -> Name of the target
# -MMD -> List user header files
# -MP  -> Add phony targets
# -MF  -> Name of the file
# ---------------------------------------
#DEPS = $(patsubst %.o,%.dep, $(OBJS))
DEPS = $(SOURCES:.c=.d)
#-include $(DEPS)
DEPFLAGS = -MM #-MT -MMD -MP -MF


# Compile-all
.PHONY: compile-all
compile-all: $(OBJS)
	@echo ""


# Build and all
.PHONY: build
build: all 

.PHONY: all
all:$(TARGET)


$(TARGET): $(OBJS)
	$(CC)  $(OBJS) $(CFLAGS) $(GCFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ 
	$(TARGET_SIZE) $@
	@echo ""
	@echo ""


# Obj Output
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(GCFLAGS) $(INCLUDES) -o $@
	$(CC) $(INCLUDES) $(CFLAGS) $(DEPFLAGS)  $^ > $(patsubst %.c,%.dep,$<)
	@echo ""
	@echo ""

# Preprocessor Output
%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(GCFLAGS) $(INCLUDES) -o $@ $^
	@echo ""
	@echo ""

# asm Output
%.asm : %.o
	$(OBJDUMP) -S $< > $@
	@echo ""
	@echo ""



.PHONY: clean
clean:
	rm -rf $(OBJS) $(TARGET) $(BASENAME).map *.s *.i *.dep *.o *.d *.asm


