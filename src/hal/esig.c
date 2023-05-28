/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/esig.h"
#include "hal/esig.h"
#include "hal_internal.h"

uint32_t ESIG_get_flash_size(void)
{
	return ((uint32_t)ESIG->FLACAP)*ESIG_FLACAP_MUL;
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
