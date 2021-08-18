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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
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
ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
        
        # Defines
	CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        LDFLAGS  = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE)
        CFLAGS   = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -DMSP432
else
    CC = gcc
    CFLAGS = -DHOST
    LDFLAGS = 
    # etc
endif


# Compiler Flags and Defines
BASENAME = c1m2
TARGET   = $(BASENAME).out
GCFLAGS  = -Wall -Werror -g -std=c99 -O0  # General Compiler flags
CPPFLAGS = -E

OBJS = $(SOURCES:.c=.o)

# Obj Output
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(GCFLAGS) $(INCLUDES) -o $@
	@echo ""
	@echo ""


# Preprocessor Output
%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(GCFLAGS) $(INCLUDES) -o $@ $^
	@echo ""
	@echo ""


# Asm Output
%.asm : %.c
	$(CC) -c $^ $(CFLAGS) $(GCFLAGS) $(INCLUDES) -o $@
	@echo ""
	@echo ""

.PHONY: build
build: all

.PHONY: all
all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(OBJS) $(CFLAGS) $(GCFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ 
	@echo ""
	@echo ""


.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map *.asm *.i









