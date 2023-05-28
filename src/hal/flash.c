/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/flash.h"
#include "hal/flash.h"
#include "hal_internal.h"

/* FIXME: Deal with this either as esig or compile-time config include */
#define FLASH_SIZE_WORDS	(4096ul)
#define STD_ERASE_SIZE		(1024ul)
#define FAST_ERASE_SIZE		(64ul)
#define FAST_PROG_SIZE		(64ul)

static HAL_err check_status(void)
{
	if ((FLASH->STATR & FLASH_STATR_EOP) == 0) {
		return HAL_EIO;
	}

	if ((FLASH->STATR & FLASH_STATR_WRPRTERR) == 0) {
		BIT_SET(FLASH->STATR, FLASH_STATR_WRPRTERR);
		return HAL_EACCESS;
	}

	BIT_SET(FLASH->STATR, FLASH_STATR_EOP);
	return HAL_OK;
}

HAL_err FLASH_set_latency(flash_latency_t latency)
{
	switch (latency) {
		case 0:
		FLASH->ACTLR = FLASH_ACTLR_LATENCY_0;
		break;

		case 1:
		FLASH->ACTLR = FLASH_ACTLR_LATENCY_1;
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err FLASH_set_boot_mode(boot_mode_t mode)
{
	switch (mode) {
		case BOOT_MAIN:
		BIT_CLEAR(FLASH->STATR, FLASH_STATR_MODE);
		break;

		case BOOT_BOOTLOADER:
		BIT_SET(FLASH->STATR, FLASH_STATR_MODE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err FLASH_enable_int(flash_int_t interrupt)
{
	switch (interrupt) {
		case INT_EOP:
		BIT_SET(FLASH->CTLR, FLASH_CTLR_EOPIE);
		break;

		case INT_ERR:
		BIT_SET(FLASH->CTLR, FLASH_CTLR_ERRIE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err FLASH_disable_int(flash_int_t interrupt)
{
	switch (interrupt) {
		case INT_EOP:
		BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_EOPIE);
		break;

		case INT_ERR:
		BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_ERRIE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err FLASH_lock_fpec(void)
{
	BIT_SET(FLASH->CTLR, FLASH_CTLR_LOCK);

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_OK;
	} else {
		return HAL_EIO;
	}
}

HAL_err FLASH_unlock_fpec(void)
{
	FLASH->KEYR = FLASH_KEYR_KEY1;
	FLASH->KEYR = FLASH_KEYR_KEY2;

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_EIO;
	} else {
		return HAL_OK;
	}
}

void FLASH_rdpr_fpec(void)
{
	FLASH->KEYR = FLASH_KEYR_KEY_RDPRT;
}

HAL_err FLASH_lock_ob(void)
{
	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_OBWRE);

	if (FLASH->CTLR & FLASH_CTLR_OBWRE) {
		return HAL_EIO;
	} else {
		return HAL_OK;
	}
}

HAL_err FLASH_unlock_ob(void)
{
	FLASH->OBKETR = FLASH_OBKETR_KEY1;
	FLASH->OBKETR = FLASH_OBKETR_KEY2;

	if (FLASH->CTLR & FLASH_CTLR_OBWRE) {
		return HAL_OK;
	} else {
		return HAL_EIO;
	}
}

HAL_err FLASH_lock_fast_mode(void)
{
	BIT_SET(FLASH->CTLR, FLASH_CTLR_FLOCK);

	if (FLASH->CTLR & FLASH_CTLR_FLOCK) {
		return HAL_OK;
	} else {
		return HAL_EIO;
	}
}

HAL_err FLASH_unlock_fast_mode(void)
{
	FLASH->MODEKEYR = FLASH_MODEKEYR_KEY1;
	FLASH->MODEKEYR = FLASH_MODEKEYR_KEY2;

	if (FLASH->CTLR & FLASH_CTLR_FLOCK) {
		return HAL_EIO;
	} else {
		return HAL_OK;
	}
}

HAL_err FLASH_erase_whole(void)
{
	HAL_err ret;

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_EACCESS;
	}

	if (FLASH->STATR & FLASH_STATR_BUSY) {
		return HAL_EBUSY;
	}

	BIT_SET(FLASH->CTLR, FLASH_CTLR_MER);

	BIT_SET(FLASH->CTLR, FLASH_CTLR_STRT);

	while (FLASH->STATR & FLASH_STATR_BUSY);
	ret = check_status();

	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_MER);

	return ret;
}

HAL_err FLASH_erase(void *addr)
{
	uint32_t tmp = (uint32_t)addr;
	volatile uint32_t *mem = (volatile uint32_t *)addr;
	HAL_err ret = HAL_OK;
	size_t i;

	if ((tmp % STD_ERASE_SIZE) != 0) {
		return HAL_EINVAL;
	}

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_EACCESS;	
	}

	if (FLASH->STATR & FLASH_STATR_BUSY) {
		return HAL_EBUSY;
	}

	BIT_SET(FLASH->CTLR, FLASH_CTLR_PER);

	FLASH->ADDR = tmp;

	BIT_SET(FLASH->CTLR, FLASH_CTLR_STRT);

	while (FLASH->STATR & FLASH_STATR_BUSY);
	BIT_SET(FLASH->STATR, FLASH_STATR_WRPRTERR);
	BIT_SET(FLASH->STATR, FLASH_STATR_EOP);

	for (i = 0; i < (STD_ERASE_SIZE / 4); i++) {
		if (mem[i] != 0xFFFFFFFFul) {
			ret = HAL_EIO;
		}
	}

	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_PER);

	return ret;
}

HAL_err FLASH_prog(uint16_t *addr, uint16_t *data, size_t size)
{
	volatile uint16_t *mem = (volatile uint16_t *)addr;
	HAL_err ret = HAL_OK;
	size_t i;

	if (((((uint32_t)addr) % 2) != 0) || ((((uint32_t)data) % 2) != 0)) {
		return HAL_EINVAL;
	}

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_EACCESS;	
	}

	if (FLASH->STATR & FLASH_STATR_BUSY) {
		return HAL_EBUSY;
	}

	BIT_SET(FLASH->CTLR, FLASH_CTLR_PG);

	for (i = 0; i < size; i++) {
		mem[i] = data[i];
		while (FLASH->STATR & FLASH_STATR_BUSY);
		ret = check_status();
		if (ret != HAL_OK) {
			break;
		}
	}

	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_PG);

	return ret;
}

HAL_err FLASH_erase_fast(void *addr)
{
	uint32_t tmp = (uint32_t)addr;
	HAL_err ret;

	if ((tmp % FAST_ERASE_SIZE) != 0) {
		return HAL_EINVAL;
	}

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {
		return HAL_EACCESS;	
	}

	if (FLASH->CTLR & FLASH_CTLR_FLOCK) {
		return HAL_EACCESS;
	}

	if (FLASH->STATR & FLASH_STATR_BUSY) {
		return HAL_EBUSY;
	}

	BIT_SET(FLASH->CTLR, FLASH_CTLR_FTER);

	FLASH->ADDR = tmp;

	BIT_SET(FLASH->CTLR, FLASH_CTLR_STRT);

	while (FLASH->STATR & FLASH_STATR_BUSY);
	ret = check_status();

	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_FTER);

	return ret;
}

HAL_err FLASH_prog_fast(uint32_t *addr, uint32_t *data)
{
	uint32_t tmp = (uint32_t)addr;
	volatile uint32_t *mem = (volatile uint32_t *)addr;
	HAL_err ret = HAL_OK;
	size_t i;

	if (((((uint32_t)addr) % 4) != 0) || ((((uint32_t)data) % 4) != 0)) {
		return HAL_EINVAL;
	}

	if ((tmp % FAST_ERASE_SIZE) != 0) {
		return HAL_EINVAL;
	}

	if (FLASH->CTLR & FLASH_CTLR_LOCK) {	/* Step 1 - no implicit unlock */
		return HAL_EACCESS;	
	}

	if (FLASH->STATR & FLASH_STATR_BUSY) {	/* Step 2 */
		return HAL_EBUSY;
	}

	if (FLASH->CTLR & FLASH_CTLR_FLOCK) {	/* Step 3 - no implicit unlock */
		return HAL_EACCESS;
	}

	BIT_SET(FLASH->CTLR, FLASH_CTLR_FTPG);

	BIT_SET(FLASH->CTLR, FLASH_CTLR_BUFRST);

	while (FLASH->STATR & FLASH_STATR_BUSY);
	BIT_SET(FLASH->STATR, FLASH_STATR_EOP);

	for (i = 0; i < (FAST_PROG_SIZE / 4); i++) {
		mem[i] = data[i];
		BIT_SET(FLASH->CTLR, FLASH_CTLR_BUFLOAD);

		while (FLASH->STATR & FLASH_STATR_BUSY);
		BIT_SET(FLASH->STATR, FLASH_STATR_EOP);
	}

	FLASH->ADDR = tmp;

	BIT_SET(FLASH->CTLR, FLASH_CTLR_STRT);

	while (FLASH->STATR & FLASH_STATR_BUSY);
	ret = check_status();

	BIT_CLEAR(FLASH->CTLR, FLASH_CTLR_FTPG);

	return ret;
}
