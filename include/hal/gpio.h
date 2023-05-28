/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal/errno.h"

typedef enum {
	PORT_A,
	PORT_C,
	PORT_D
} gpio_port_t;

typedef enum {
	IN_ANALOG,
	IN_FLOATING,
	IN_PUSHPULL,
	OUT_PUSHPULL,
	OUT_OPENDRAIN,
	OUT_PUSHPULL_MUL,
	OUT_OPENDRAIN_MUL
} gpio_conf_t;

typedef enum {
	SPEED_2,
	SPEED_10,
	SPEED_50
} gpio_speed_t;

/**
 * @brief Initialize gpio input.
 *
 * This function initializes pin as an input.
 *
 * @param port Port.
 * @param pin Pin number.
 * @param conf Configuration.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_init_in(gpio_port_t port, uint8_t pin, gpio_conf_t conf);

/**
 * @brief Initialize gpio output.
 *
 * This function initializes pin as an output.
 *
 * @param port Port.
 * @param pin Pin number.
 * @param conf Configuration.
 * @param speed Speed setting.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_init_out(gpio_port_t port, uint8_t pin, gpio_conf_t conf, gpio_speed_t speed);

/**
 * @brief Get port states.
 *
 * This function reads whole port states.
 *
 * @param port Port.
 * @param val Pointer to port data buffer.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_get_port(gpio_port_t port, uint8_t *val);

/**
 * @brief Get pin state.
 *
 * This function reads pin state.
 *
 * @param port Port.
 * @param pin Pin number.
 * @param val Pointer to pin data buffer.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_get_pin(gpio_port_t port, uint8_t pin, bool *val);

/**
 * @brief Set port state.
 *
 * This function sets whole port states.
 *
 * @param port Port.
 * @param val Port states.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_set_port(gpio_port_t port, uint8_t val);

/**
 * @brief Set pin state.
 *
 * This function sets pin state to active.
 *
 * @param port Port.
 * @param pin Pin number.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_set_pin(gpio_port_t port, uint8_t pin);

/**
 * @brief Clear pin state.
 *
 * This function sets pin state to inactive.
 *
 * @param port Port.
 * @param pin Pin number.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_clear_pin(gpio_port_t port, uint8_t pin);

/**
 * @brief Lock port configuration.
 *
 * This function locks port configuration according to mask.
 *
 * @param port Port.
 * @param mask Pin bitmask to use with lock.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err GPIO_lock_port(gpio_port_t port, uint8_t mask);

#endif /* _HAL_GPIO_H_ */