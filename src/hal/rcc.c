/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/rcc.h"
#include "hal/rcc.h"
#include "hal_internal.h"

HAL_err	RCC_init_clock(uint8_t clock)
{
	switch (clock) {
		case CLOCK_LSI:
		BIT_SET(RCC->RSTSCKR, RCC_RSTSCKR_LSION);
		while ((RCC->RSTSCKR & RCC_RSTSCKR_LSIRDY_MASK) != RCC_RSTSCKR_LSIRDY);
		break;

		case CLOCK_HSI:
		BIT_SET(RCC->CTRL, RCC_CTRL_HSION);
		while ((RCC->CTRL & RCC_CTRL_HSIRDY_MASK) != RCC_CTRL_HSIRDY);
		break;

		case CLOCK_HSE_BYP:
		BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEON);
		BIT_SET(RCC->CTRL, RCC_CTRL_HSEBYP);
		break;

		case CLOCK_HSE:
		BIT_SET(RCC->CTRL, RCC_CTRL_HSEON);
		while ((RCC->CTRL & RCC_CTRL_HSEON_MASK) != RCC_CTRL_HSEON);
		break;

		case CLOCK_PLL:
		BIT_SET(RCC->CTRL, RCC_CTRL_PLLON);
		while ((RCC->CTRL & RCC_CTRL_PLLRDY_MASK) != RCC_CTRL_PLLRDY);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err	RCC_deinit_clock(uint8_t clock)
{
	switch (clock) {
		case CLOCK_LSI:
		BIT_CLEAR(RCC->RSTSCKR, RCC_RSTSCKR_LSION);
		while ((RCC->RSTSCKR & RCC_RSTSCKR_LSIRDY_MASK) == RCC_RSTSCKR_LSIRDY);
		break;

		case CLOCK_HSI:
		BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSION);
		while ((RCC->CTRL & RCC_CTRL_HSIRDY_MASK) == RCC_CTRL_HSIRDY);
		break;

		case CLOCK_HSE_BYP:
		BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEBYP);
		break;

		case CLOCK_HSE:
		BIT_CLEAR(RCC->CTRL, RCC_CTRL_HSEON);
		while ((RCC->CTRL & RCC_CTRL_HSEON_MASK) == RCC_CTRL_HSEON);
		break;

		case CLOCK_PLL:
		BIT_CLEAR(RCC->CTRL, RCC_CTRL_PLLON);
		while ((RCC->CTRL & RCC_CTRL_PLLRDY_MASK) == RCC_CTRL_PLLRDY);
		break;

		default:
		return HAL_EINVAL;
	}

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

		case CLOCK_HSE_BYP:
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

HAL_err RCC_get_intflag(uint8_t interrupt, bool *flag)
{
	if (!flag) {
		return HAL_EINVAL;
	}

	switch (interrupt) {
		case INT_CSS:
		*flag = ((RCC->INTR & RCC_INTR_CSSF_MASK) == RCC_INTR_CSSF);
		break;

		case INT_PLLRDY:
		*flag = ((RCC->INTR & RCC_INTR_PLLRDYF_MASK) == RCC_INTR_PLLRDYF);
		break;

		case INT_HSERDY:
		*flag = ((RCC->INTR & RCC_INTR_HSERDYF_MASK) == RCC_INTR_HSERDYF);
		break;

		case INT_HSIRDY:
		*flag = ((RCC->INTR & RCC_INTR_HSIRDYF_MASK) == RCC_INTR_HSIRDYF);
		break;

		case INT_LSIRDY:
		*flag = ((RCC->INTR & RCC_INTR_LSIRDYF_MASK) == RCC_INTR_LSIRDYF);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_clear_intflag(uint8_t interrupt)
{
	switch (interrupt) {
		case INT_CSS:
		BIT_SET(RCC->INTR, RCC_INTR_CSSC);
		break;

		case INT_PLLRDY:
		BIT_SET(RCC->INTR, RCC_INTR_PLLRDYC);
		break;

		case INT_HSERDY:
		BIT_SET(RCC->INTR, RCC_INTR_HSERDYC);
		break;

		case INT_HSIRDY:
		BIT_SET(RCC->INTR, RCC_INTR_HSIRDYC);
		break;

		case INT_LSIRDY:
		BIT_SET(RCC->INTR, RCC_INTR_LSIRDYC);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_enable_int(uint8_t interrupt)
{
	switch (interrupt) {
		case INT_PLLRDY:
		BIT_SET(RCC->INTR, RCC_INTR_PLLRDYIE);
		break;

		case INT_HSERDY:
		BIT_SET(RCC->INTR, RCC_INTR_HSERDYIE);
		break;

		case INT_HSIRDY:
		BIT_SET(RCC->INTR, RCC_INTR_HSIRDYIE);
		break;

		case INT_LSIRDY:
		BIT_SET(RCC->INTR, RCC_INTR_LSIRDYIE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_disable_int(uint8_t interrupt)
{
	switch (interrupt) {
		case INT_PLLRDY:
		BIT_CLEAR(RCC->INTR, RCC_INTR_PLLRDYIE);
		break;

		case INT_HSERDY:
		BIT_CLEAR(RCC->INTR, RCC_INTR_HSERDYIE);
		break;

		case INT_HSIRDY:
		BIT_CLEAR(RCC->INTR, RCC_INTR_HSIRDYIE);
		break;

		case INT_LSIRDY:
		BIT_CLEAR(RCC->INTR, RCC_INTR_LSIRDYIE);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_reset_peripherial(uint8_t peripheral)
{
	switch (peripheral) {
		case APB_USART1:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_USART1RST);
		break;

		case APB_SPI1:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_SPI1RST);
		break;

		case APB_TIM1:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_TIM1RST);
		break;

		case APB_ADC1:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_ADC1RST);
		break;

		case APB_GPIOD:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_IOPDRST);
		break;

		case APB_GPIOC:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_IOPCRST);
		break;

		case APB_GPIOA:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_IOPARST);
		break;

		case APB_AFIO:
		BIT_SET(RCC->APB2PRSTR, RCC_APB2PRSTR_AFIORST);
		break;

		case APB_PWR:
		BIT_SET(RCC->APB1PRSTR, RCC_APB1PRSTR_PWRRST);
		break;

		case APB_I2C1:
		BIT_SET(RCC->APB1PRSTR, RCC_APB1PRSTR_I2C1RST);
		break;

		case APB_WWDG:
		BIT_SET(RCC->APB1PRSTR, RCC_APB1PRSTR_WWDGRST);
		break;

		case APB_TIM2:
		BIT_SET(RCC->APB1PRSTR, RCC_APB1PRSTR_TIM2RST);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_enable_peripherial(uint8_t peripheral)
{
	switch (peripheral) {
		case APB_USART1:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_USART1EN);
		break;

		case APB_SPI1:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_SPI1EN);
		break;

		case APB_TIM1:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_TIM1EN);
		break;

		case APB_ADC1:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_ADC1EN);
		break;

		case APB_GPIOD:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_IOPDEN);
		break;

		case APB_GPIOC:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_IOPCEN);
		break;

		case APB_GPIOA:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_IOPAEN);
		break;

		case APB_AFIO:
		BIT_SET(RCC->APB2PCENR, RCC_APB2PCENR_AFIOEN);
		break;

		case APB_PWR:
		BIT_SET(RCC->APB1PCENR, RCC_APB1PCENR_PWREN);
		break;

		case APB_I2C1:
		BIT_SET(RCC->APB1PCENR, RCC_APB1PCENR_I2C1EN);
		break;

		case APB_WWDG:
		BIT_SET(RCC->APB1PCENR, RCC_APB1PCENR_WWDGEN);
		break;

		case APB_TIM2:
		BIT_SET(RCC->APB1PCENR, RCC_APB1PCENR_TIM2EN);
		break;

		case AHB_DMA1:
		BIT_SET(RCC->AHBPCENR, RCC_AHBPCENR_DMA1EN);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_disable_peripherial(uint8_t peripheral)
{
	switch (peripheral) {
		case APB_USART1:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_USART1EN);
		break;

		case APB_SPI1:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_SPI1EN);
		break;

		case APB_TIM1:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_TIM1EN);
		break;

		case APB_ADC1:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_ADC1EN);
		break;

		case APB_GPIOD:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_IOPDEN);
		break;

		case APB_GPIOC:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_IOPCEN);
		break;

		case APB_GPIOA:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_IOPAEN);
		break;

		case APB_AFIO:
		BIT_CLEAR(RCC->APB2PCENR, RCC_APB2PCENR_AFIOEN);
		break;

		case APB_PWR:
		BIT_CLEAR(RCC->APB1PCENR, RCC_APB1PCENR_PWREN);
		break;

		case APB_I2C1:
		BIT_CLEAR(RCC->APB1PCENR, RCC_APB1PCENR_I2C1EN);
		break;

		case APB_WWDG:
		BIT_CLEAR(RCC->APB1PCENR, RCC_APB1PCENR_WWDGEN);
		break;

		case APB_TIM2:
		BIT_CLEAR(RCC->APB1PCENR, RCC_APB1PCENR_TIM2EN);
		break;

		case AHB_DMA1:
		BIT_CLEAR(RCC->AHBPCENR, RCC_AHBPCENR_DMA1EN);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err RCC_enable_SRAM_sleep(void)
{
	BIT_SET(RCC->AHBPCENR, RCC_AHBPCENR_SRAMEN);
	return HAL_OK;
}

HAL_err RCC_disable_SRAM_sleep(void)
{
	BIT_CLEAR(RCC->AHBPCENR, RCC_AHBPCENR_SRAMEN);
	return HAL_OK;
}

HAL_err RCC_get_reset_flag(uint8_t *flag)
{
	if (!flag) {
		return HAL_EINVAL;
	}

	if ((RCC->RSTSCKR & RCC_RSTSCKR_LPWRRSTF_MASK) == RCC_RSTSCKR_LPWRRSTF) {
		*flag = RESET_LOW_POWER;
	} else if ((RCC->RSTSCKR & RCC_RSTSCKR_WWDGRSTF_MASK) == RCC_RSTSCKR_WWDGRSTF) {
		*flag = RESET_WWDG;
	} else if ((RCC->RSTSCKR & RCC_RSTSCKR_IWDGRSTF_MASK) == RCC_RSTSCKR_IWDGRSTF) {
		*flag = RESET_IWDG;
	} else if ((RCC->RSTSCKR & RCC_RSTSCKR_SFTRSTF_MASK) == RCC_RSTSCKR_SFTRSTF) {
		*flag = RESET_SOFT;
	} else if ((RCC->RSTSCKR & RCC_RSTSCKR_PORRSTF_MASK) == RCC_RSTSCKR_PORRSTF) {
		*flag = RESET_POR;
	} else if ((RCC->RSTSCKR & RCC_RSTSCKR_PINRSTF_MASK) == RCC_RSTSCKR_PINRSTF) {
		*flag = RESET_PIN;
	} else {
		return HAL_EIO;
	}

	return HAL_OK;
}

HAL_err RCC_clear_reset_flags(void)
{
	BIT_SET(RCC->RSTSCKR, RCC_RSTSCKR_RMVF);
	return HAL_OK;
}
