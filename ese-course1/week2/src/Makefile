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

TARGET = c1m2

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH =  -mthumb -march=armv7e-m
SPECS = --specs=nosys.specs
OTHER_ARCH = -mfloat-abi=hard -mfpu=fpv4-sp-d16

ifeq ($(PLATFORM), HOST)
	ARCH_FLAGS =
else ifeq ($(PLATFORM), MSP432)
	ARCH_FLAGS = $(CPU) $(ARCH) $(SPECS) $(OTHER_ARCH)
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC = gcc
else
	CC = arm-none-eabi-gcc
endif

LD = ../msp432p401r.lds
# add linker file -L????
ifeq ($(PLATFORM), HOST)
	LDFLAGS = -Wl,-Map=$(TARGET).map
else ifeq ($(PLATFORM), MSP432)
	LDFLAGS = -Wl,-Map=$(TARGET).map -Wl,-T $(LD)
endif

CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -MD

OBJS = $(SOURCES:.c=.o)
PREPROCS = $(SOURCES:.c=.i)
DEPENDS = $(SOURCES:.c=.d)

%.asm: %.c
	$(CC) -S $< -o $@ -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $(ARCH_FLAGS)


%.i: %.c
	$(CC) -E $< -o $@ -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $(ARCH_FLAGS)

# currently manually setting the "HOST" defined macro
%.o : %.c
	$(CC) -c $< -o $@ -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS)

.PHONY : compile-all
compile-all:
	gcc -c $(SOURCES) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS)

.PHONY : build
build : all

.PHONY : all
all : $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ $(ARCH_FLAGS)

.PHONY : clean
clean :
	rm -f $(OBJS) $(PREPROCS) $(DEPENDS) $(TARGET).out
