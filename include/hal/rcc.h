/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_RCC_H_
#define _HAL_RCC_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal/errno.h"

#define CLOCK_NONE	0
#define CLOCK_SYSCLK	1
#define CLOCK_HSI	2
#define CLOCK_HSE	3
#define CLOCK_HSE_BYP	4
#define CLOCK_PLL	5
#define CLOCK_LSI	6

#define INT_CSS		0
#define INT_PLLRDY	1
#define INT_HSERDY	2
#define INT_HSIRDY	3
#define INT_LSIRDY	4

#define APB_USART1	0
#define APB_SPI1	1
#define APB_TIM1	2
#define APB_ADC1	3
#define APB_GPIOD	4
#define APB_GPIOC	5
#define APB_GPIOA	6
#define APB_AFIO	7
#define APB_PWR		8
#define APB_I2C1	9
#define APB_WWDG	10
#define APB_TIM2	11
#define AHB_DMA1	12

#define RESET_LOW_POWER	0
#define RESET_WWDG	1
#define RESET_IWDG	2
#define RESET_SOFT	3
#define RESET_POR	4
#define RESET_PIN	5

HAL_err	RCC_init_clock(uint8_t clock);

HAL_err	RCC_deinit_clock(uint8_t clock);

HAL_err RCC_get_hsical(uint8_t *cal);

HAL_err RCC_trim_hsi(int8_t trim);

HAL_err RCC_enable_css(void);

HAL_err RCC_disable_css(void);

HAL_err RCC_set_mco(uint8_t clock);

HAL_err	RCC_set_pll_src(uint8_t clock);

HAL_err RCC_set_adc_prescaler(uint8_t prescaler);

HAL_err RCC_set_ahb_prescaler(uint16_t prescaler);

HAL_err RCC_get_sysclk_src(uint8_t *clock);

HAL_err RCC_set_sysclk_src(uint8_t clock);

HAL_err RCC_get_intflag(uint8_t interrupt, bool *flag);

HAL_err RCC_clear_intflag(uint8_t interrupt);

HAL_err RCC_enable_int(uint8_t interrupt);

HAL_err RCC_disable_int(uint8_t interrupt);

HAL_err RCC_reset_peripherial(uint8_t peripheral);

HAL_err RCC_enable_peripherial(uint8_t peripheral);

HAL_err RCC_disable_peripherial(uint8_t peripheral);

HAL_err RCC_enable_SRAM_sleep(void);

HAL_err RCC_disble_SRAM_sleep(void);

HAL_err RCC_get_reset_flag(uint8_t *flag);

HAL_err RCC_clear_reset_flags(void);

#endif /* _HAL_RCC_H_ */
