/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_IWDG_H_
#define _PERIPHERAL_IWDG_H_

#include <stdint.h>

#define IWDG_REG_OFFSET		(0x40003000ul)

/* CTRL */
#define IWDG_CTRL_KEY_MASK	(0xFFFFul << 0)
#define IWDG_CTRL_KEY_FEED	(0xAAAAul << 0)
#define IWDG_CTRL_KEY_MOD	(0x5555ul << 0)
#define IWDG_CTRL_KEY_START	(0xCCCCul << 0)

/* PSCR */
#define IWDG_PSCR_PR_MASK	(0x07ul << 0)
#define IWDG_PSCR_PR_4		(0x00ul << 0)
#define IWDG_PSCR_PR_8		(0x01ul << 0)
#define IWDG_PSCR_PR_16		(0x02ul << 0)
#define IWDG_PSCR_PR_32		(0x03ul << 0)
#define IWDG_PSCR_PR_64		(0x04ul << 0)
#define IWDG_PSCR_PR_128	(0x05ul << 0)
#define IWDG_PSCR_PR_256	(0x06ul << 0)

/* RLDR */
#define IWDG_RLDR_RL_MASK	(0x0FFFul << 0)

/* STATR */
#define IWDG_STATR_RVU_MASK	(0x01ul << 1)
#define IWDG_STATR_RVU		(0x01ul << 1)

#define IWDG_STATR_PVU_MASK	(0x01ul << 1)
#define IWDG_STATR_PVU		(0x01ul << 1)

typedef struct {
	uint16_t CTRL;		/**< Control */
	uint16_t PADDING;
	uint16_t PSCR;		/**< Prescaler */
	uint16_t PADDING2;
	uint16_t RLDR;		/**< Reload */
	uint16_t PADDING3;
	uint16_t STATR;		/**< Status */
} per_iwdg_t;

volatile per_iwdg_t *IWDG = (volatile per_iwdg_t *)IWDG_REG_OFFSET;

#endif /* _PERIPHERAL_IWDG_H_ */