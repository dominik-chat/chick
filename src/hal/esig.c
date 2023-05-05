/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/gpio.h"
#include "hal/gpio.h"
#include "hal_internal.h"

HAL_err ESIG_get_flash_size(uint32_t *size)
{
	if (!size) {
		return HAL_EINVAL;
	}

	*size = ((uint32_t)ESIG->FLACAP)*ESIG_FLACAP_MUL;
	return HAL_OK;
}

HAL_err ESIG_get_uid(uint32_t *uid)
{
	if (!uid) {
		return HAL_EINVAL;
	}

	uid[0] = ESIG->UNIID1;
	uid[1] = ESIG->UNIID2;
	uid[2] = ESIG->UNIID3;

	return HAL_OK;
}
