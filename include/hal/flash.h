/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_FLASH_H_
#define _HAL_FLASH_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "hal/errno.h"

#define LATENCY_0	0
#define LATENCY_1	1

#define BOOT_MAIN	0
#define BOOT_BOOTLOADER	1

#define INT_EOP		0
#define INT_ERR		1

HAL_err FLASH_set_latency(uint8_t latency);

HAL_err FLASH_set_boot_mode(uint8_t mode);

HAL_err FLASH_enable_int(uint8_t interrupt);

HAL_err FLASH_disable_int(uint8_t interrupt);

HAL_err FLASH_lock_fpec(void);

HAL_err FLASH_unlock_fpec(void);

HAL_err FLASH_rdpr_fpec(void);

HAL_err FLASH_lock_ob(void);

HAL_err FLASH_unlock_ob(void);

HAL_err FLASH_lock_fast_mode(void);

HAL_err FLASH_unlock_fast_mode(void);

HAL_err FLASH_erase_whole(void);

HAL_err FLASH_erase(void *addr);

HAL_err FLASH_prog(uint16_t *addr, uint16_t *data, size_t size);

HAL_err FLASH_erase_fast(void *addr);

HAL_err FLASH_prog_fast(uint32_t *addr, uint32_t *data);

/* TODO: Boot lock, unlock - seems unclear in docs */
//HAL_err FLASH_lock_boot(void);
//HAL_err FLASH_unlock_boot(void);

/* Maybe move userwords here ? */

#endif /* _HAL_FLASH_H_ */