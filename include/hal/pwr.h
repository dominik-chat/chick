/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_PWR_H_
#define _HAL_PWR_H_

#include "hal/errno.h"

typedef enum {
	THRESHOLD_285_27,
	THRESHOLD_305_29,
	THRESHOLD_33_315,
	THRESHOLD_35_33,
	THRESHOLD_37_35,
	THRESHOLD_39_37,
	THRESHOLD_41_39,
	THRESHOLD_44_42
} pwr_pvd_t;

typedef enum {
	BELOW_THRESH,
	ABOVE_THRESH,
} pwr_pvd_flag_t;

/**
 * @brief Enable programmable voltage detector.
 *
 * @param threshold Detector threshold.
 *
 * @note The associated register is reset after 
 * waking up from Standby mode.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PWR_enable_pvd(pwr_pvd_t threshold);

/**
 * @brief Disable programmable voltage detector.
 *
 * @note The associated register is reset after 
 * waking up from Standby mode.
 */
void PWR_disable_pvd(void);

/**
 * @brief Set standby mode as deep sleep.
 *
 * @note The associated register is reset after 
 * waking up from Standby mode.
 */
void PWR_set_deepsleep_standby(void);

/**
 * @brief Set sleep mode as deep sleep.
 *
 * @note The associated register is reset after 
 * waking up from Standby mode.
 */
void PWR_set_deepsleep_sleep(void);

/**
 * @brief Enable programmable voltage detector.
 *
 * @param flag Pointer to a PVD flag.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PWR_get_pvd_flag(pwr_pvd_flag_t *flag);

/**
 * @brief Enable Auto-wakeup.
 */
void PWR_enable_awu(void);

/**
 * @brief Disable Auto-wakeup.
 */
void PWR_disable_awu(void);

/**
 * @brief Set Auto-wakeup window value.
 *
 * @param val Window value.
 */
void PWR_set_awu_window_val(uint8_t val);

/**
 * @brief Set Auto-wakeup prescaler value.
 *
 * @param prescaler Prescaler value.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PWR_set_awu_prescaler(uint16_t prescaler);

#endif /* _HAL_PWR_H_ */