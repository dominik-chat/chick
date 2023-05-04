/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_RCC_H_
#define _HAL_RCC_H_

#include <stdint.h>
#include "hal/errno.h"

HAL_err RCC_init_pll(void);

HAL_err RCC_uninit_pll(void);

HAL_err RCC_init_hse_xtal(void);

HAL_err RCC_uninit_hse_xtal(void);

HAL_err RCC_init_hse_byp(void);

HAL_err RCC_uninit_hse_byp(void);

HAL_err RCC_init_hsi(void);

HAL_err RCC_uninit_hsi(void);

HAL_err RCC_get_hsical(uint8_t *cal);

HAL_err RCC_trim_hsi(int8_t trim);

HAL_err RCC_enable_css(void);

HAL_err RCC_disable_css(void);

/* TODO: Other register HALs */

#endif /* _HAL_RCC_H_ */