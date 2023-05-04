/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/rcc.h"
#include "hal/rcc.h"

#define BIT_SET(reg, bit)	reg ^= bit
#define BIT_CLEAR(reg, bit)	reg &= (~bit)

HAL_err RCC_init_pll(void)
{
	BIT_SET(RCC->CTRL, RCC_CTRL_PLLON);
	while ((RCC->CTRL & RCC_CTRL_PLLRDY_MASK) != RCC_CTRL_PLLRDY);
	return HAL_OK;
}

HAL_err RCC_uninit_pll(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_PLLON);
	while ((RCC->CTRL & RCC_CTRL_PLLRDY_MASK) == RCC_CTRL_PLLRDY);
	return HAL_OK;
}

HAL_err RCC_init_hse_xtal(void)
{
	BIT_SET(RCC->CTRL, RCC_CTRL_HSEON);
	while ((RCC->CTRL & RCC_CTRL_HSEON_MASK) != RCC_CTRL_HSEON);
	return HAL_OK;
}

HAL_err RCC_uninit_hse_xtal(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEON);
	while ((RCC->CTRL & RCC_CTRL_HSEON_MASK) == RCC_CTRL_HSEON);
	return HAL_OK;
}

HAL_err RCC_init_hse_byp(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEON);
	BIT_SET(RCC->CTRL, RCC_CTRL_HSEBYP);
	return HAL_OK;
}

HAL_err RCC_uninit_hse_byp(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEBYP);
	return HAL_OK;
}

HAL_err RCC_init_hsi(void)
{
	BIT_SET(RCC->CTRL, RCC_CTRL_HSION);
	while ((RCC->CTRL & RCC_CTRL_HSIRDY_MASK) != RCC_CTRL_HSIRDY);
	return HAL_OK;
}

HAL_err RCC_uninit_hsi(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSION);
	while ((RCC->CTRL & RCC_CTRL_HSIRDY_MASK) == RCC_CTRL_HSIRDY);
	return HAL_OK;
}

HAL_err RCC_get_hsical(uint8_t *cal)
{
	if (!cal) {
		return HAL_EINVAL;
	}

	*cal = RCC_CTRL_HSICAL_VAL(RCC->CTRL);
	return HAL_OK;
}

HAL_err RCC_trim_hsi(int8_t trim)
{
	uint32_t tmp;

	if ((trim > 15) || (trim < -16)) {
		return HAL_EINVAL;
	}

	tmp = (uint32_t)(trim + 16);
	RCC->CTRL = RCC_CTRL_HSITRIM(tmp);

	return HAL_OK;
}

HAL_err RCC_enable_css(void)
{
	BIT_SET(RCC->CTRL, RCC_CTRL_CSSON);
	return HAL_OK;
}

HAL_err RCC_disable_css(void)
{
	BIT_CLEAR(RCC->CTRL, RCC_CTRL_CSSON);
	return HAL_OK;
}
