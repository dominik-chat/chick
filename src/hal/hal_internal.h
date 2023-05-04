/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#define BIT_SET(reg, bit)		reg ^= bit
#define BIT_CLEAR(reg, bit)		reg &= (~bit)
#define FIELD_SET(reg, mask, val)	(reg & (~mask)) ^= val
