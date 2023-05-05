/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_EXTEN_H_
#define _PERIPHERAL_EXTEN_H_

#include <stdint.h>

#define EXTEN_REG_OFFSET		(0x40023800ul)

/* CTLR */
#define EXTEN_OPA_PSEL_MASK		(0x01ul << 18)
#define EXTEN_OPA_PSEL_CH0		(0x00ul << 18)
#define EXTEN_OPA_PSEL_CH1		(0x01ul << 18)

#define EXTEN_OPA_NSEL_MASK		(0x01ul << 17)
#define EXTEN_OPA_NSEL_CH0		(0x00ul << 17)
#define EXTEN_OPA_NSEL_CH1		(0x01ul << 17)

#define EXTEN_OPA_EN_MASK		(0x01ul << 16)
#define EXTEN_OPA_EN_CH0		(0x01ul << 16)

#define EXTEN_LDOTRIM_MASK		(0x01ul << 10)
#define EXTEN_LDOTRIM_NORM		(0x00ul << 10)
#define EXTEN_LDOTRIM_BOOST		(0x01ul << 10)

#define EXTEN_LKUPRST_MASK		(0x01ul << 7)
#define EXTEN_LKUPRST			(0x01ul << 7)

#define EXTEN_LKUPEN_MASK		(0x01ul << 6)
#define EXTEN_LKUPEN			(0x01ul << 6)

typedef struct {
	uint32_t CTR;			/**< Configure extended control */
} per_exten_t;

volatile per_exten_t *EXTEN = (volatile per_exten_t *)EXTEN_REG_OFFSET;

#endif /* _PERIPHERAL_EXTEN_H_ */