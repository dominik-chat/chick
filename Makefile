#
# Copyright 2023 Dominik Chat
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

PRJ = sdk

BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

LD_FILE = core/ch32v003.ld

SRC = $(wildcard $(SRC_DIR)/*/*.c $(SRC_DIR)/*.c)
ASM_SRC = $(wildcard $(SRC_DIR)/*.S)
PRJ_SRC = $(wildcard project/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
ASM_OBJ = $(ASM_SRC:$(SRC_DIR)/%.S=$(BUILD_DIR)/%.o)
PRJ_OBJ = $(PRJ_SRC:project/%.c=$(BUILD_DIR)/project/%.o)
OBJS = $(OBJ) $(ASM_OBJ) $(PRJ_OBJ)

CFLAGS += \
	-O2 -flto \
	-ffunction-sections \
	-static-libgcc \
	-march=rv32ec \
	-mabi=ilp32e \
	-I$(INC_DIR) \
	-nostdlib \
	-Wall

LDFLAGS += \
	-T $(LD_FILE) \
	-Wl,--gc-sections \
	-lgcc

CC = riscv64-elf-gcc
LD = riscv64-elf-gcc
SIZE = riscv64-elf-size
DUMP = riscv64-elf-objdump
COPY = riscv64-elf-objcopy

all: $(OBJ) $(ASM_OBJ) $(PRJ_OBJ) $(PRJ).elf finish

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -e "\e[32mCompiling C object: $<\e[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S
	@echo -e "\e[32mCompiling Assembly object: $<\e[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/project/%.o: project/%.c
	@echo -e "\e[32mCompiling Assembly object: $<\e[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRJ).elf: $(OBJS)
	@echo -e "\e[35mCreating elf binary: $@\e[0m"
	@$(LD) $(LDFLAGS) $(CFLAGS) $(OBJS) -o $(BUILD_DIR)/$@

finish:
	@$(SIZE) $(BUILD_DIR)/$(PRJ).elf
	@$(DUMP) -D $(BUILD_DIR)/$(PRJ).elf > $(BUILD_DIR)/$(PRJ).lst
	@$(COPY) -S -O ihex $(BUILD_DIR)/$(PRJ).elf $(BUILD_DIR)/$(PRJ).hex
	@$(COPY) -S -O binary $(BUILD_DIR)/$(PRJ).elf $(BUILD_DIR)/$(PRJ).bin

clean:
	@rm -rf $(BUILD_DIR)
