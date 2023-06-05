/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_EXTI_H_
#define _HAL_EXTI_H_

#include <stdbool.h>
#include "hal/errno.h"

typedef enum {
	CHAN_0		= 0,
	CHAN_1		= 1,
	CHAN_2		= 2,
	CHAN_3		= 3,
	CHAN_4		= 4,
	CHAN_5		= 5,
	CHAN_6		= 6,
	CHAN_7		= 7,
	CHAN_PVD	= 8,
	CHAN_AWUP	= 9
} hal_chan_t;

/**
 * @brief Enable interrupt generation.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_enable_int(hal_chan_t channel);

/**
 * @brief Disable interrupt generation.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_disable_int(hal_chan_t channel);

/**
 * @brief Enable event generation.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_enable_event(hal_chan_t channel);

/**
 * @brief Disable event generation.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_disable_event(hal_chan_t channel);

/**
 * @brief Enable rising edge triggering.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_enable_rising(hal_chan_t channel);

/**
 * @brief Disable rising edge triggering.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_disable_rising(hal_chan_t channel);

/**
 * @brief Enable falling edge triggering.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_enable_falling(hal_chan_t channel);

/**
 * @brief Disable falling edge triggering.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_disable_falling(hal_chan_t channel);

/**
 * @brief Enable generating software interrupts.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_enable_soft_int(hal_chan_t channel);

/**
 * @brief Disable generating software interrupts.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_disable_soft_int(hal_chan_t channel);

/**
 * @brief Get interrupt flag of the channel.
 *
 * @param channel EXTI channel.
 * @param flag Pointer to flag.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_get_intflag(hal_chan_t channel, bool *flag);

/**
 * @brief Clear interrupt flag of a channel.
 *
 * @param channel EXTI channel.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err EXTI_clear_intflag(hal_chan_t channel);

#endif /* _HAL_EXTI_H_ */