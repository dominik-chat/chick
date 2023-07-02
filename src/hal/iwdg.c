/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/iwdg.h"
#include "hal/iwdg.h"
#include "hal_internal.h"

void IWDG_feed(void)
{
	IWDG->CTRL = IWDG_CTRL_KEY_FEED;
}

void IWDG_start(void)
{
	IWDG->CTRL = IWDG_CTRL_KEY_START;
}

HAL_err IWDG_set_prescaler(uint16_t prescaler)
{
	uint16_t tmp;

	switch (prescaler) {
		case 4:
		tmp = IWDG_PSCR_PR_4;
		break;

		case 8:
		tmp = IWDG_PSCR_PR_8;
		break;

		case 16:
		tmp = IWDG_PSCR_PR_16;
		break;

		case 32:
		tmp = IWDG_PSCR_PR_32;
		break;

		case 64:
		tmp = IWDG_PSCR_PR_64;
		break;

		case 128:
		tmp = IWDG_PSCR_PR_128;
		break;

		case 256:
		tmp = IWDG_PSCR_PR_256;
		break;

		default:
		return HAL_EINVAL;
	}

	IWDG->CTRL = IWDG_CTRL_KEY_MOD;
	while (IWDG->STATR & IWDG_STATR_PVU_MASK);
	IWDG->PSCR = tmp;

	return HAL_OK;
}

void IWDG_set_reload_value(uint16_t value)
{
	IWDG->CTRL = IWDG_CTRL_KEY_MOD;
	while (IWDG->STATR & IWDG_STATR_RVU_MASK);

	IWDG->RLDR = value & IWDG_RLDR_RL_MASK;
}
