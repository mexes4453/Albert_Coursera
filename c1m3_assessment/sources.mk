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

# Add your Source files to this variable
SOURCES =                          \
    ./main.c                       \
    ./misc.c                       \
#    ./startup_msp432p401r_gcc.c    \
#    ./system_msp432p401r.c         \
#    ./interrupts_msp432p401r_gcc.c


# Add your include paths to this variable
HEADER_FILE_ROOT_PATH = ./

INCLUDES =                                 \
	-I $(HEADER_FILE_ROOT_PATH)        \
#	-I $(HEADER_FILE_ROOT_PATH)CMSIS   \
#	-I $(HEADER_FILE_ROOT_PATH)common  \
#	-I $(HEADER_FILE_ROOT_PATH)msp432


