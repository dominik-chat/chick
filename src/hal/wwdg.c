/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/wwdg.h"
#include "hal/wwdg.h"
#include "hal_internal.h"

void WWDG_feed(void)
{
	FIELD_SET(WWDG->CTRL, WWDG_CTRL_T_MASK, WWDG_CTRL_T_MASK);
}

void WWDG_start(void)
{
	BIT_SET(WWDG->CTRL, WWDG_CTRL_WDGA);
}

void WWDG_enable_early_int(void)
{
	BIT_SET(WWDG->CFGR, WWDG_CFGR_EWI);
}

void WWDG_clear_early_int_flag(void)
{
	BIT_CLEAR(WWDG->STATR, WWDG_STATR_EWIF);
}

HAL_err WWDG_set_prescaler(uint8_t prescaler)
{
	uint16_t tmp;

	switch (prescaler) {
		case 1:
		tmp = WWDG_CFGR_WDGTB_1;
		break;

		case 2:
		tmp = WWDG_CFGR_WDGTB_2;
		break;

		case 4:
		tmp = WWDG_CFGR_WDGTB_4;
		break;

		case 8:
		tmp = WWDG_CFGR_WDGTB_8;
		break;

		default:
		return HAL_EINVAL;
	}

	FIELD_SET(WWDG->CFGR, WWDG_CFGR_WDGTB_MASK, tmp);

	return HAL_OK;
}

void WWDG_set_window_value(uint8_t value)
{
	FIELD_SET(WWDG->CFGR, WWDG_CFGR_W_MASK, value);
}