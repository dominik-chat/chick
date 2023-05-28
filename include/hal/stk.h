/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_STK_H_
#define _HAL_STK_H_

#include <stdint.h>
#include <stdbool.h>
#include "hal/errno.h"

typedef enum {
	STK_PRE_1,
	STK_PRE_8
} stk_pre_t;

/**
 * @brief Enable Software Interrupt.
 */
void STK_enable_swi(void);

/**
 * @brief Disable Software Interrupt.
 */
void STK_disable_swi(void);

/**
 * @brief Enable auto reload.
 */
void STK_enable_autoreload(void);

/**
 * @brief Disable auto reload.
 */
void STK_disable_autoreload(void);

/**
 * @brief Set prescaler.
 *
 * @param prescaler Prescaler.
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err STK_set_prescaler(stk_pre_t prescaler);

/**
 * @brief Enable compare interrupt.
 */
void STK_enable_int(void);

/**
 * @brief Disable compare interrupt.
 */
void STK_disable_int(void);

/**
 * @brief Enable systick.
 */
void STK_enable(void);

/**
 * @brief Disable systick.
 */
void STK_disable(void);

/**
 * @brief Get interrupt flag.
 *
 * @retval Interrupt flag.
 */
bool STK_get_intflag(void);

/**
 * @brief Clear interrupt flag.
 */
void STK_clear_intflag(void);

/**
 * @brief Get systick count.
 *
 * @retval Current count.
 */
uint32_t STK_get_cnt(void)
	__attribute__((warn_unused_result));

/**
 * @brief Set systick count.
 *
 * @param cnt Count.
 */
void STK_set_cnt(uint32_t cnt);

/**
 * @brief Get systick compare value.
 *
 * @retval Compare value.
 */
uint32_t STK_get_cmp(void)
	__attribute__((warn_unused_result));

/**
 * @brief Set systick compare value.
 *
 * @param cmp Compare value.
 */
void STK_set_cmp(uint32_t cmp);

#endif /* _HAL_STK_H_ */