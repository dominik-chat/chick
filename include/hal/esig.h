/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_ESIG_H_
#define _HAL_ESIG_H_

#include "hal/errno.h"

HAL_err ESIG_get_flash_size(uint32_t *size);

HAL_err ESIG_get_uid(uint32_t *uid);

#endif /* _HAL_ESIG_H_ */