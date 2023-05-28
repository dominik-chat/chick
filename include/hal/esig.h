/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_ESIG_H_
#define _HAL_ESIG_H_

#include <stdint.h>
#include "hal/errno.h"

/**
 * @brief Get flash size in bytes.
 *
 * @retval Flash size in bytes.
 */
uint32_t ESIG_get_flash_size(void)
	__attribute__((warn_unused_result));

/**
 * @brief Get UID words.
 *
 * @param uid Pointer to 3 word storage for UID
 *
 * @retval HAL_OK Success.
 * @retval Otherwise errno code.
 */
HAL_err ESIG_get_uid(uint32_t *uid);

#endif /* _HAL_ESIG_H_ */