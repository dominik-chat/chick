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

#define PORT_A			0
#define PORT_C			2
#define PORT_D			3

#define CONF_IN_ANALOG		0
#define CONF_IN_FLOATING	1
#define CONF_IN_PUSHPULL	2

#define CONF_OUT_PUSHPULL	0
#define CONF_OUT_OPENDRAIN	1
#define CONF_OUT_PUSHPULL_MUL	2
#define CONF_OUT_OPENDRAIN_MUL	3

#define SPEED_2			0
#define SPEED_10		1
#define SPEED_50		2

HAL_err GPIO_init_in(uint8_t port, uint8_t pin, uint8_t conf);

HAL_err GPIO_init_out(uint8_t port, uint8_t pin, uint8_t conf, uint8_t speed);

HAL_err GPIO_get_port(uint8_t port, uint8_t *val);

HAL_err GPIO_get_pin(uint8_t port, uint8_t pin, bool *val);

HAL_err GPIO_set_port(uint8_t port, uint8_t val);

HAL_err GPIO_set_pin(uint8_t port, uint8_t pin);

HAL_err GPIO_clear_pin(uint8_t port, uint8_t pin);

HAL_err GPIO_lock_port(uint8_t port, uint8_t mask);

#endif /* _HAL_GPIO_H_ */