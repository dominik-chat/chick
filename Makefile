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
	-O2 -g -flto \
	-ffunction-sections \
	-ffreestanding \
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

#riscv64-unknown-elf
CC_PREFIX = riscv64-elf
CC = $(CC_PREFIX)-gcc
LD = $(CC_PREFIX)-gcc
SIZE = $(CC_PREFIX)-size
DUMP = $(CC_PREFIX)-objdump
COPY = $(CC_PREFIX)-objcopy

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
	@$(DUMP) -d -S $(BUILD_DIR)/$(PRJ).elf > $(BUILD_DIR)/$(PRJ).lst
	@$(DUMP) -t $(BUILD_DIR)/$(PRJ).elf > $(BUILD_DIR)/$(PRJ).map
	@$(COPY) -S -O ihex $(BUILD_DIR)/$(PRJ).elf $(BUILD_DIR)/$(PRJ).hex
	@$(COPY) -S -O binary $(BUILD_DIR)/$(PRJ).elf $(BUILD_DIR)/$(PRJ).bin

clean:
	@rm -rf $(BUILD_DIR)
