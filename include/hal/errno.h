/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _HAL_ERRNO_H_
#define _HAL_ERRNO_H_

typedef enum {
	HAL_OK,
	HAL_EIO,
	HAL_EINVAL,
	HAL_EACCESS,
	HAL_EBUSY,
	HAL_ERR_CNT
} HAL_err;

#endif /* _HAL_ERRNO_H_ */