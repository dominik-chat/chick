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

typedef enum {
	CLOCK_NONE,
	CLOCK_SYSCLK,
	CLOCK_HSI,
	CLOCK_HSE,
	CLOCK_HSE_BYP,
	CLOCK_PLL,
	CLOCK_LSI
} rcc_clock_t;

typedef enum {
	INT_CSS,
	INT_PLLRDY,
	INT_HSERDY,
	INT_HSIRDY,
	INT_LSIRDY
} rcc_int_t;

typedef enum {
	APB_USART1,
	APB_SPI1,
	APB_TIM1,
	APB_ADC1,
	APB_GPIOD,
	APB_GPIOC,
	APB_GPIOA,
	APB_AFIO,
	APB_PWR,
	APB_I2C1,
	APB_WWDG,
	APB_TIM2,
	AHB_DMA1
} rcc_per_t;

typedef enum {
	RESET_LOW_POWER,
	RESET_WWDG,
	RESET_IWDG,
	RESET_SOFT,
	RESET_POR,
	RESET_PIN
} rcc_rst_t;

/**
 * @brief Initialize clock.
 *
 * @param clock Clock selection.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err	RCC_init_clock(rcc_clock_t clock);

/**
 * @brief Deinitialize clock.
 *
 * @param clock Clock selection.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err	RCC_deinit_clock(rcc_clock_t clock);

/**
 * @brief Get HSI calibration value.
 *
 * @retval Calibration value.
 */
uint8_t RCC_get_hsical(void)
	__attribute__((warn_unused_result));

/**
 * @brief Trim HSI clock.
 *
 * @param trim Trim value.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_trim_hsi(int8_t trim);

/**
 * @brief Enable Clock Security System.
 */
void RCC_enable_css(void);

/**
 * @brief Disable Clock Security System.
 */
void RCC_disable_css(void);

/**
 * @brief Tie master clock output pin to clock.
 *
 * @param clock Clock.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_set_mco(rcc_clock_t clock);

/**
 * @brief Set PLL clock source.
 *
 * @param clock Clock.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err	RCC_set_pll_src(rcc_clock_t clock);

/**
 * @brief Set ADC prescaler divisor.
 *
 * @param prescaler Divisor.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_set_adc_prescaler(uint8_t prescaler);

/**
 * @brief Set AHB prescaler divisor.
 *
 * @param prescaler Divisor.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_set_ahb_prescaler(uint16_t prescaler);

/**
 * @brief Get current system clock.
 *
 * @param clock Pointer to clock.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_get_sysclk_src(rcc_clock_t *clock);

/**
 * @brief Set current system clock.
 *
 * @param clock Clock.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_set_sysclk_src(rcc_clock_t clock);

/**
 * @brief Get interrupt flag.
 *
 * @param interrupt Interrupt.
 * @param flag pointer to flag.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_get_intflag(rcc_int_t interrupt, bool *flag);

/**
 * @brief Clear interrupt flag.
 *
 * @param interrupt Interrupt.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_clear_intflag(rcc_int_t interrupt);

/**
 * @brief Enable interrupt.
 *
 * @param interrupt Interrupt.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_enable_int(rcc_int_t interrupt);

/**
 * @brief Disable interrupt.
 *
 * @param interrupt Interrupt.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_disable_int(rcc_int_t interrupt);

/**
 * @brief Reset peripheral.
 *
 * @param peripheral Peripheral.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_reset_peripherial(rcc_per_t peripheral);

/**
 * @brief Enable clock for peripheral.
 *
 * @param peripheral Peripheral.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_enable_peripherial(rcc_per_t peripheral);

/**
 * @brief Disable clock for peripheral.
 *
 * @param peripheral Peripheral.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_disable_peripherial(rcc_per_t peripheral);

/**
 * @brief Enable SRAM clock in sleep mode.
 */
void RCC_enable_SRAM_sleep(void);

/**
 * @brief Disable SRAM clock in sleep mode.
 */
void RCC_disable_SRAM_sleep(void);

/**
 * @brief Enable DMA clock in sleep mode.
 */
void RCC_enable_DMA_sleep(void);

/**
 * @brief Disable DMA clock in sleep mode.
 */
void RCC_disable_DMA_sleep(void);

/**
 * @brief Get reset flag.
 *
 * @param flag Pointer to flag.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err RCC_get_reset_flag(rcc_rst_t *flag);

/**
 * @brief Clear reset flags.
 */
void RCC_clear_reset_flags(void);

#endif /* _HAL_RCC_H_ */
