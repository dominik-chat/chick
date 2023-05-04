/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/rcc.h"
#include "hal/rcc.h"
#include "hal_internal.h"

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

HAL_err RCC_set_mco(uint8_t clock)
{
	switch (clock) {
		case CLOCK_NONE:
		FIELD_SET(RCC->CFGR, RCC_CFGR_MCO_MASK, RCC_CFGR_MCO_NOCLOCK);
		break;

		case CLOCK_SYSCLK:
		FIELD_SET(RCC->CFGR, RCC_CFGR_MCO_MASK, RCC_CFGR_MCO_SYSCLK);
		break;

		case CLOCK_HSI:
		FIELD_SET(RCC->CFGR, RCC_CFGR_MCO_MASK, RCC_CFGR_MCO_HSI);
		break;

		case CLOCK_HSE:
		FIELD_SET(RCC->CFGR, RCC_CFGR_MCO_MASK, RCC_CFGR_MCO_HSE);
		break;

		case CLOCK_PLL:
		FIELD_SET(RCC->CFGR, RCC_CFGR_MCO_MASK, RCC_CFGR_MCO_PLL);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err	RCC_set_pll_src(uint8_t clock)
{
	switch (clock) {
		case CLOCK_HSI:
		FIELD_SET(RCC->CFGR, RCC_CFGR_PLLSRC_MASK, RCC_CFGR_PLLSRC_HSI);
		break;

		case CLOCK_HSE:
		FIELD_SET(RCC->CFGR, RCC_CFGR_PLLSRC_MASK, RCC_CFGR_PLLSRC_HSE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_set_adc_prescaler(uint8_t prescaler)
{
	switch (prescaler) {
		case 2:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_2);
		break;

		case 4:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_4);
		break;

		case 6:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_6);
		break;

		case 8:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_8);
		break;

		case 12:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_12);
		break;

		case 16:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_16);
		break;

		case 24:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_24);
		break;

		case 32:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_32);
		break;

		case 48:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_48);
		break;

		case 64:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_64);
		break;

		case 96:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_96);
		break;

		case 128:
		FIELD_SET(RCC->CFGR, RCC_CFGR_ADCPRE_MASK, RCC_CFGR_ADCPRE_128);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_set_ahb_prescaler(uint16_t prescaler)
{
	switch (prescaler) {
		case 1:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_OFF);
		break;

		case 2:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_2);
		break;

		case 3:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_3);
		break;

		case 4:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_4);
		break;

		case 5:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_5);
		break;

		case 6:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_6);
		break;

		case 7:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_7);
		break;

		case 8:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_8);
		break;

		case 16:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_16);
		break;

		case 32:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_32);
		break;

		case 64:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_64);
		break;

		case 128:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_128);
		break;

		case 256:
		FIELD_SET(RCC->CFGR, RCC_CFGR_HPRE_MASK, RCC_CFGR_HPRE_256);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_get_sysclk_src(uint8_t *clock)
{
	uint32_t tmp;

	tmp = (RCC->CFGR & RCC_CFGR_SWS_MASK);
	if (tmp == RCC_CFGR_SWS_HSI) {
		*clock = CLOCK_HSI;
	} else if (tmp == RCC_CFGR_SWS_HSE) {
		*clock = CLOCK_HSE;
	} else if (tmp == RCC_CFGR_SWS_PLL) {
		*clock = CLOCK_PLL;
	} else {
		return HAL_EIO;
	}

	return HAL_OK;
}

HAL_err RCC_set_sysclk_src(uint8_t clock)
{
	switch (clock) {
		case CLOCK_HSI:
		FIELD_SET(RCC->CFGR, RCC_CFGR_SW_MASK, RCC_CFGR_SW_HSI);
		break;

		case CLOCK_HSE:
		FIELD_SET(RCC->CFGR, RCC_CFGR_SW_MASK, RCC_CFGR_SW_HSE);
		break;

		case CLOCK_PLL:
		FIELD_SET(RCC->CFGR, RCC_CFGR_SW_MASK, RCC_CFGR_SW_PLL);
		break;

		default:
		return HAL_EINVAL;
	}
}
