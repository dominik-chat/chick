/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_STK_H_
#define _HAL_STK_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal/errno.h"

HAL_err STK_enable_swi(void);

HAL_err STK_disable_swi(void);

HAL_err STK_enable_autoreload(void);

HAL_err STK_disable_autoreload(void);

HAL_err STK_set_prescaler(uint8_t prescaler);

HAL_err STK_enable_int(void);

HAL_err STK_disable_int(void);

HAL_err STK_enable(void);

HAL_err STK_disable(void);

HAL_err STK_get_intflag(bool *flag);

HAL_err STK_clear_intflag(void);

HAL_err STK_get_cnt(uint32_t *cnt);

HAL_err STK_set_cnt(uint32_t cnt);

HAL_err STK_get_cmp(uint32_t *cmp);

HAL_err STK_set_cmp(uint32_t cmp);

#endif /* _HAL_STK_H_ */