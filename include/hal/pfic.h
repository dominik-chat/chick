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

typedef enum {
	VECT_NMI	= 2,
	VECT_EXC	= 3,
	VECT_STK	= 12,
	VECT_SWI	= 14,
	VECT_WWDG	= 16,
	VECT_PVD	= 17,
	VECT_FLASH	= 18,
	VECT_RCC	= 19,
	VECT_EXTI	= 20,
	VECT_AWU	= 21,
	VECT_DMA_CH1	= 22,
	VECT_DMA_CH2	= 23,
	VECT_DMA_CH3	= 24,
	VECT_DMA_CH4	= 25,
	VECT_DMA_CH5	= 26,
	VECT_DMA_CH6	= 27,
	VECT_DMA_CH7	= 28,
	VECT_ADC	= 29,
	VECT_I2C_EV	= 30,
	VECT_I2C_ER	= 31,
	VECT_USART	= 32,
	VECT_SPI	= 33,
	VECT_TIM1BRK	= 34,
	VECT_TIM1UP	= 35,
	VECT_TIM1TRG	= 36,
	VECT_TIM1CC	= 37,
	VECT_TIM2	= 38
} pfic_vect_t;

/**
 * @brief Enable interrupt vector.
 *
 * @param vector Interrupt vector.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err	PFIC_enable_int(pfic_vect_t vector);

/**
 * @brief Disable interrupt vector.
 *
 * @param vector Interrupt vector.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err	PFIC_disable_int(pfic_vect_t vector);

/**
 * @brief Get interrupt vector state.
 *
 * @param vector Interrupt vector.
 * @param flag Pointer to interrupt vector state.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PFIC_get_en_int(pfic_vect_t vector, bool *flag);

/**
 * @brief Set pending interrupt vector.
 *
 * @param vector Interrupt vector.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PFIC_set_pend_int(pfic_vect_t vector);

/**
 * @brief Clear pending interrupt vector.
 *
 * @param vector Interrupt vector.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PFIC_clear_pend_int(pfic_vect_t vector);

/**
 * @brief Get interrupt vector pending state.
 *
 * @param vector Interrupt vector.
 * @param flag Pointer to interrupt vector pending state.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PFIC_get_pend_int(pfic_vect_t vector, bool *flag);

/**
 * @brief Get interrupt vector executing state.
 *
 * @param vector Interrupt vector.
 * @param flag Pointer to interrupt vector executing state.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err PFIC_get_exe_int(pfic_vect_t vector, bool *flag);

/**
 * @brief Set interrupt threshold priority.
 *
 * @param prio Priority.
 */
void PFIC_set_threshold_prio(uint8_t prio);

/**
 * @brief Reset the CPU.
 */
void PFIC_reset(void)
	__attribute__((noreturn));

/**
 * @brief Get interrupt state.
 *
 * Get interrupt state if pointer is not NULL.
 *
 * @param pend Pointer to interrupt pending flag.
 * @param exe Pointer to interrupt executing flag.
 * @param nest_lvl Pointer to nest_level value.
 */
void PFIC_get_state(bool *pend, bool *exe, uint8_t *nest_lvl);

/**
 * @brief Enable direct interrupt processing 0.
 *
 * @param vector Interrupt vector.
 * @param isr Pointer to Interrupt Service Routine.
 */
void PFIC_enable_vtf0(pfic_vect_t vector, void *isr);

/**
 * @brief Disable direct interrupt processing 0.
 */
void PFIC_disable_vtf0(void);

/**
 * @brief Enable direct interrupt processing 1.
 *
 * @param vector Interrupt vector.
 * @param isr Pointer to Interrupt Service Routine.
 */
void PFIC_enable_vtf1(pfic_vect_t vector, void *isr);

/**
 * @brief Disable direct interrupt processing 1.
 */
void PFIC_disable_vtf1(void);

/**
 * @brief Set interrupt priority.
 *
 * @param vector Interrupt vector.
 * @param prio Priority.
 */
void PFIC_set_prio(pfic_vect_t vector, uint8_t prio);

/**
 * @brief Set event to wakeup WFE.
 */
void PFIC_set_event(void);

/**
 * @brief Enable all events and interrupt wakeup.
 */
void PFIC_enable_all_wkup(void);

/**
 * @brief Disable all events and interrupt wakeup.
 */
void PFIC_disable_all_wkup(void);

/**
 * @brief Enable treating WFI as WFE.
 */
void PFIC_enable_wfitowfe(void);

/**
 * @brief Disable treating WFI as WFE.
 */
void PFIC_disable_wfitowfe(void);

/**
 * @brief Enable deep sleep.
 */
void PFIC_enable_deepsleep(void);

/**
 * @brief Disable deep sleep.
 */
void PFIC_disable_deepsleep(void);

/**
 * @brief Enable sleep on exit from interrupt.
 */
void PFIC_enable_sleeponexit(void);

/**
 * @brief Disable sleep on exit from interrupt.
 */
void PFIC_disable_sleeponexit(void);

#endif /* _HAL_PFIC_H_ */
