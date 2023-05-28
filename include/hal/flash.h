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

typedef enum {
	LATENCY_0,
	LATENCY_1
} flash_latency_t;

typedef enum {
	BOOT_MAIN,
	BOOT_BOOTLOADER
} boot_mode_t;

typedef enum {
	INT_EOP,
	INT_ERR
} flash_int_t;

/**
 * @brief Set flash latency.
 *
 * @param latency New latency.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_set_latency(flash_latency_t latency);

/**
 * @brief Set boot mode.
 *
 * @param mode New boot mode.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_set_boot_mode(boot_mode_t mode);

/**
 * @brief Enable flash interrupt.
 *
 * @param interrupt Interrupt to be enabled.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_enable_int(flash_int_t interrupt);

/**
 * @brief Disable flash interrupt.
 *
 * @param interrupt Interrupt to be disabled.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_disable_int(flash_int_t interrupt);

/**
 * @brief Lock flash controller.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_lock_fpec(void);

/**
 * @brief Unlock flash controller.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_unlock_fpec(void);

/**
 * @brief Read protect flash controller.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
void FLASH_rdpr_fpec(void);

/**
 * @brief Lock option bytes.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_lock_ob(void);

/**
 * @brief Unlock option bytes.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_unlock_ob(void);

/**
 * @brief Lock fast mode.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_lock_fast_mode(void);

/**
 * @brief Unlock fast mode.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_unlock_fast_mode(void);

/**
 * @brief Erase whole chip.
 *
 * @pre The flash controller should be unlocked.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_erase_whole(void);

/**
 * @brief Erase single block.
 *
 * This function performs erasure on 1KB block of flash.
 *
 * @pre The flash controller should be unlocked.
 *
 * @param addr Block aligned address of block to erase.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_erase(void *addr);

/**
 * @brief Program flash.
 *
 * This function performs programming on flash.
 *
 * @pre The flash controller should be unlocked.
 *
 * @param addr Half-word aligned address of flash to program.
 * @param data Half-word aligned address of data to program.
 * @param size Count of half-words to program.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_prog(uint16_t *addr, uint16_t *data, size_t size);

/**
 * @brief Fast erase single page.
 *
 * This function performs erasure on 64 byte pages of flash.
 *
 * @pre The flash controller should be unlocked.
 * @pre The fast mode should be unlocked.
 *
 * @param addr Page aligned address of page to erase.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_erase_fast(void *addr);

/**
 * @brief Fast program flash.
 *
 * This function performs fast programming on 64 byte pages of flash.
 *
 * @pre The flash controller should be unlocked.
 * @pre The fast mode should be unlocked.
 *
 * @param addr Word aligned address of flash to program.
 * @param data Word aligned address of data to program.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err FLASH_prog_fast(uint32_t *addr, uint32_t *data);

/* TODO: Boot lock, unlock - seems unclear in docs */
//HAL_err FLASH_lock_boot(void);
//HAL_err FLASH_unlock_boot(void);

/* Maybe move userwords here ? */

#endif /* _HAL_FLASH_H_ */