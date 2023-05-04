/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_STK_H_
#define _PERIPHERAL_STK_H_

#include <stdint.h>

#define STK_REG_OFFSET		(0xE000F000ul)

/* CTLR */
#define STK_CTLR_SWIE_MASK	(0x01ul << 31)
#define STK_CTLR_SWIE		(0x01ul << 31)

#define STK_CTLR_STRE_MASK	(0x01ul << 3)
#define STK_CTLR_STRE		(0x01ul << 3)

#define STK_CTLR_STCLK_MASK	(0x01ul << 2)
#define STK_CTLR_STCLK		(0x01ul << 2)

#define STK_CTLR_STIE_MASK	(0x01ul << 1)
#define STK_CTLR_STIE		(0x01ul << 1)

#define STK_CTLR_STE_MASK	(0x01ul << 0)
#define STK_CTLR_STE		(0x01ul << 0)

/* SR */
#define STK_SR_CNTIF_MASK	(0x01ul << 0)
#define STK_SR_CNTIF		(0x01ul << 0)

/* CNTL */
#define STK_CNTL_CNT_MASK	(0xFFFFFFFFul << 0)
#define STK_CNTL_CNT		((x) << 0)

/* CMPLR */
#define STK_CMPLR_CMP_MASK	(0xFFFFFFFFul << 0)
#define STK_CMPLR_CMP		((x) << 0)

typedef struct {
	uint32_t CTLR;		/**< System count control */
	uint32_t SR;		/**< System count status */
	uint32_t CNTL;		/**< System counter low */
	uint32_t CMPLR;		/**< Counting comparison low */
} per_stk_t;

volatile per_stk_t *STK = (volatile per_stk_t *)STK_REG_OFFSET;

#endif /* _PERIPHERAL_STK_H_ */