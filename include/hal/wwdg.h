/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_WWDG_H_
#define _HAL_WWDG_H_

#include <stdbool.h>
#include "hal/errno.h"

/**
 * @brief Feed the watchdog.
 */
void WWDG_feed(void);

/**
 * @brief Start the watchdog.
 *
 * @note The watchdog cannot be disabled once started.
 */
void WWDG_start(void);

/**
 * @brief Enable early interrupt.
 *
 * @note The early interrupt cannot be disabled once enabled.
 */
void WWDG_enable_early_int(void);

/**
 * @brief Clear early interrupt flag.
 */
void WWDG_clear_early_int_flag(void);

/**
 * @brief Set the prescaler.
 *
 * @param prescaler Prescaler.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err WWDG_set_prescaler(uint8_t prescaler);

/**
 * @brief Set the window value.
 *
 * @param value Window value.
 */
void WWDG_set_window_value(uint8_t value);

#endif /* _HAL_WWDG_H_ */