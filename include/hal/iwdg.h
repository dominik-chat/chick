/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_IWDG_H_
#define _HAL_IWDG_H_

#include <stdbool.h>
#include "hal/errno.h"

/**
 * @brief Feed the watchdog.
 */
void IWDG_feed(void);

/**
 * @brief Start the watchdog.
 *
 * @note The watchdog cannot be disabled once started.
 */
void IWDG_start(void);

/**
 * @brief Set the prescaler.
 *
 * @param prescaler Prescaler.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err IWDG_set_prescaler(uint16_t prescaler);

/**
 * @brief Set the reload value.
 *
 * @param value Reload value.
 */
void IWDG_set_reload_value(uint16_t value);

#endif /* _HAL_IWDG_H_ */