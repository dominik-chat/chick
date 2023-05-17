/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_PFIC_H_
#define _HAL_PFIC_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal/errno.h"

#define VECT_NMI	2
#define VECT_EXC	3
#define VECT_STK	12
#define VECT_SWI	14
#define VECT_WWDG	16
#define VECT_PVD	17
#define VECT_FLASH	18
#define VECT_RCC	19
#define VECT_EXTI	20
#define VECT_AWU	21
#define VECT_DMA_CH1	22
#define VECT_DMA_CH2	23
#define VECT_DMA_CH3	24
#define VECT_DMA_CH4	25
#define VECT_DMA_CH5	26
#define VECT_DMA_CH6	27
#define VECT_DMA_CH7	28
#define VECT_ADC	29
#define VECT_I2C_EV	30
#define VECT_I2C_ER	31
#define VECT_USART	32
#define VECT_SPI	33
#define VECT_TIM1BRK	34
#define VECT_TIM1UP	35
#define VECT_TIM1TRG	36
#define VECT_TIM1CC	37
#define VECT_TIM2	38

HAL_err	PFIC_enable_int(uint8_t vector);

HAL_err	PFIC_disable_int(uint8_t vector);

HAL_err PFIC_get_en_int(uint8_t vector, bool *flag);

HAL_err PFIC_set_pend_int(uint8_t vector);

HAL_err PFIC_clear_pend_int(uint8_t vector);

HAL_err PFIC_get_pend_int(uint8_t vector, bool *flag);

HAL_err PFIC_get_exe_int(uint8_t vector, bool *flag);

HAL_err PFIC_set_threshold_prio(uint8_t prio);

HAL_err PFIC_reset(void);

HAL_err PFIC_get_state(bool *pend, bool *exe, uint8_t *nest_lvl);

HAL_err PFIC_enable_vtf0(uint8_t vector, void *isr);

HAL_err PFIC_disable_vtf0(void);

HAL_err PFIC_enable_vtf1(uint8_t vector, void *isr);

HAL_err PFIC_disable_vtf1(void);

HAL_err PFIC_set_prio(uint8_t vector, uint8_t prio);

HAL_err PFIC_set_event(void);

HAL_err PFIC_enable_all_wkup(void);

HAL_err PFIC_disable_all_wkup(void);

HAL_err PFIC_enable_wfitowfe(void);

HAL_err PFIC_disable_wfitowfe(void);

HAL_err PFIC_enable_deepsleep(void);

HAL_err PFIC_disable_deepsleep(void);

HAL_err PFIC_enable_sleeponexit(void);

HAL_err PFIC_disable_sleeponexit(void);

#endif /* _HAL_PFIC_H_ */
