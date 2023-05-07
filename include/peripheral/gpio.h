/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_GPIO_H_
#define _PERIPHERAL_GPIO_H_

#include <stdint.h>

#define GPIO_A_REG_OFFSET	(0x40010800ul)
#define GPIO_C_REG_OFFSET	(0x40011000ul)
#define GPIO_D_REG_OFFSET	(0x40011400ul)

/* CFGLR */
#define GPIO_CFGLR_CNF_MASK(x)	(0x03ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_ANA(x)	(0x00ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_FLT(x)	(0x01ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_PULL(x)	(0x02ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_PUSH(x)	(0x00ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_OPEN(x)	(0x01ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_MPUSH(x)	(0x02ul << (((x) * 4) + 2))
#define GPIO_CFGLR_CNF_MOPEN(x)	(0x03ul << (((x) * 4) + 2))

#define GPIO_CFGLR_MODE_MASK(x)	(0x03ul << ((x) * 4))
#define GPIO_CFGLR_MODE_INP(x)	(0x00ul << ((x) * 4))
#define GPIO_CFGLR_MODE_10M(x)	(0x01ul << ((x) * 4))
#define GPIO_CFGLR_MODE_2M(x)	(0x02ul << ((x) * 4))
#define GPIO_CFGLR_MODE_50M(x)	(0x03ul << ((x) * 4))

/* INDR */
#define GPIO_INDR_IDR_MASK	(0xFFul << 0)
#define GPIO_INDR_IDR(x)	(0x01ul << (x))

/* OUTDR */
#define GPIO_OUTDR_ODR_MASK	(0xFFul << 0)
#define GPIO_OUTDR_ODR(x)	(0x01ul << (x))

/* BSHR */
#define GPIO_BSHR_BR_MASK	(0xFFul << 16)
#define GPIO_BSHR_BR(x)		(0x01ul << ((x) + 16))

#define GPIO_BSHR_BS_MASK	(0xFFul << 0)
#define GPIO_BSHR_BS(x)		(0x01ul << (x))

/* BCR */
#define GPIO_BCR_BR_MASK	(0xFFul << 0)
#define GPIO_BCR_BR(x)		(0x01ul << (x))

/* LCKR */
#define GPIO_LCKR_LCKK_MASK	(0x01ul << 8)
#define GPIO_LCKR_LCKK		(0x01ul << 8)

#define GPIO_LCKR_LCK_MASK	(0xFFul << 0)
#define GPIO_LCKR_LCK(x)	(0x01ul << (x))

typedef struct {
	uint32_t CFGLR;		/**< Port configuration low */
	uint32_t RESERVED;	/**< RESERVED */
	uint32_t INDR;		/**< Port input data */
	uint32_t OUTDR;		/**< Port output data */
	uint32_t BSHR;		/**< Port set/reset */
	uint32_t BCR;		/**< Port reset */
	uint32_t LCKR;		/**< Port configuration lock */
} per_gpio_t;

extern volatile per_gpio_t *GPIO_A;
extern volatile per_gpio_t *GPIO_C;
extern volatile per_gpio_t *GPIO_D;

#endif /* _PERIPHERAL_GPIO_H_ */