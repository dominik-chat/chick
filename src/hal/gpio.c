/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/gpio.h"
#include "hal/gpio.h"
#include "hal_internal.h"

HAL_err GPIO_init_in(uint8_t port, uint8_t pin, uint8_t conf)
{
	volatile per_gpio_t *gpio;
	uint32_t mask;
	uint32_t val;

	if (pin > 7) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	mask = GPIO_CFGLR_CNF_MASK(pin);
	switch (conf) {
		case CONF_IN_ANALOG:
		val = GPIO_CFGLR_CNF_ANA(pin);
		break;

		case CONF_IN_FLOATING:
		val = GPIO_CFGLR_CNF_FLT(pin);
		break;

		case CONF_IN_PUSHPULL:
		val = GPIO_CFGLR_CNF_PULL(pin);
		break;

		default:
		return HAL_EINVAL;
	}

	mask |= GPIO_CFGLR_MODE_MASK(pin);
	val |= GPIO_CFGLR_MODE_INP(pin);

	FIELD_SET(gpio->CFGLR, mask, val);

	return HAL_OK;
}

HAL_err GPIO_init_out(uint8_t port, uint8_t pin, uint8_t conf, uint8_t speed)
{
	volatile per_gpio_t *gpio;
	uint32_t mask;
	uint32_t val;

	if (pin > 7) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	mask = GPIO_CFGLR_CNF_MASK(pin);
	switch (conf) {
		case CONF_OUT_PUSHPULL:
		val = GPIO_CFGLR_CNF_PUSH(pin);
		break;

		case CONF_OUT_OPENDRAIN:
		val = GPIO_CFGLR_CNF_OPEN(pin);
		break;

		case CONF_OUT_PUSHPULL_MUL:
		val = GPIO_CFGLR_CNF_MPUSH(pin);
		break;

		case CONF_OUT_OPENDRAIN_MUL:
		val = GPIO_CFGLR_CNF_MOPEN(pin);
		break;

		default:
		return HAL_EINVAL;
	}

	mask |= GPIO_CFGLR_MODE_MASK(pin);
	switch (speed) {
		case SPEED_2:
		val |= GPIO_CFGLR_MODE_2M(pin);
		break;

		case SPEED_10:
		val |= GPIO_CFGLR_MODE_10M(pin);
		break;

		case SPEED_50:
		val |= GPIO_CFGLR_MODE_50M(pin);
		break;

		default:
		return HAL_EINVAL;
	}

	FIELD_SET(gpio->CFGLR, mask, val);

	return HAL_OK;
}

HAL_err GPIO_get_port(uint8_t port, uint8_t *val)
{
	volatile per_gpio_t *gpio;

	if (!val) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	*val = (uint8_t)(gpio->INDR & GPIO_INDR_IDR_MASK);

	return HAL_OK;
}

HAL_err GPIO_get_pin(uint8_t port, uint8_t pin, bool *val)
{
	volatile per_gpio_t *gpio;

	if (pin > 7) {
		return HAL_EINVAL;
	}

	if (!val) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	if ((gpio->INDR & GPIO_INDR_IDR(pin)) != 0) {
		*val = true;
	} else {
		*val = false;
	}

	return HAL_OK;
}

HAL_err GPIO_set_port(uint8_t port, uint8_t val)
{
	volatile per_gpio_t *gpio;

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	FIELD_SET(gpio->OUTDR, GPIO_OUTDR_ODR_MASK, (uint32_t)val);

	return HAL_OK;
}

HAL_err GPIO_set_pin(uint8_t port, uint8_t pin)
{
	volatile per_gpio_t *gpio;

	if (pin > 7) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	BIT_SET(gpio->BSHR, GPIO_BSHR_BS(pin));

	return HAL_OK;
}

HAL_err GPIO_clear_pin(uint8_t port, uint8_t pin)
{
	volatile per_gpio_t *gpio;

	if (pin > 7) {
		return HAL_EINVAL;
	}

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	BIT_SET(gpio->BCR, GPIO_BCR_BR(pin));

	return HAL_OK;
}

HAL_err GPIO_lock_port(uint8_t port, uint8_t mask)
{
	volatile per_gpio_t *gpio;
	volatile uint32_t tmp;

	switch (port) {
		case PORT_A:
		gpio = GPIO_A;
		break;

		case PORT_C:
		gpio = GPIO_C;
		break;

		case PORT_D:
		gpio = GPIO_D;
		break;

		default:
		return HAL_EINVAL;
	}

	FIELD_SET(gpio->LCKR, GPIO_LCKR_LCK_MASK, (uint32_t)mask);

	/* Lock sequence from reference manual */
	gpio->LCKR = GPIO_LCKR_LCKK;
	gpio->LCKR = 0;
	gpio->LCKR = GPIO_LCKR_LCKK;
	tmp = gpio->LCKR;
	tmp = gpio->LCKR;

	if ((tmp & GPIO_LCKR_LCKK_MASK) == 0) {
		return HAL_EIO;
	}

	return HAL_OK;
}
