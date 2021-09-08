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



SRC_FILE_PATH = ./src
HEADER_FILE_ROOT_PATH = ./include

ifeq ($(PLATFORM),MSP432)
	# +++ SOURCE AND INCLUDE FOR MSP432 PLATFORM  +++
	# Add your Source files to this variable
	SOURCES =                                         \
	    $(SRC_FILE_PATH)/main.c                       \
	    $(SRC_FILE_PATH)/data.c                       \
	    $(SRC_FILE_PATH)/memory.c                     \
	    $(SRC_FILE_PATH)/course1.c                    \
	    $(SRC_FILE_PATH)/stats.c                      \
	    $(SRC_FILE_PATH)/startup_msp432p401r_gcc.c    \
	    $(SRC_FILE_PATH)/system_msp432p401r.c         \
	    $(SRC_FILE_PATH)/interrupts_msp432p401r_gcc.c

	# Add your include paths to this variable
	INCLUDES =                                  \
		-I $(HEADER_FILE_ROOT_PATH)/CMSIS   \
		-I $(HEADER_FILE_ROOT_PATH)/common  \
		-I $(HEADER_FILE_ROOT_PATH)/msp432  \
                -I $(SRC_FILE_PATH)

else
	# +++ SOURCE AND INCLUDE FOR HOST PLATFORM  +++
        # Add source files to this variable        
	SOURCES =                                         \
	    $(SRC_FILE_PATH)/main.c                       \
	    $(SRC_FILE_PATH)/data.c                       \
	    $(SRC_FILE_PATH)/memory.c                     \
	    $(SRC_FILE_PATH)/course1.c                    \
	    $(SRC_FILE_PATH)/stats.c                      

        # Add your include paths to this variable
	INCLUDES =                                  \
                -I $(HEADER_FILE_ROOT_PATH)/common  \
                -I $(SRC_FILE_PATH)

endif

