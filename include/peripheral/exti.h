/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_EXTI_H_
#define _PERIPHERAL_EXTI_H_

#include <stdint.h>

#define EXTI_REG_OFFSET		(0x40010400ul)

/* INTENR */
#define EXTI_INTENR_MRx_MASK	(0x03FFul << 0)
#define EXTI_INTENR_MR(x)	(0x01ul << (x))

/* EVENR */
#define EXTI_EVENR_MRx_MASK	(0x03FFul << 0)
#define EXTI_EVENR_MR(x)	(0x01ul << (x))

/* RTENR */
#define EXTI_RTENR_TRx_MASK	(0x03FFul << 0)
#define EXTI_RTENR_TR(x)	(0x01ul << (x))

/* FTENR */
#define EXTI_FTENR_TRx_MASK	(0x03FFul << 0)
#define EXTI_FTENR_TR(x)	(0x01ul << (x))

/* FTENR */
#define EXTI_FTENR_SWIEVRx_MASK	(0x03FFul << 0)
#define EXTI_FTENR_SWIEVR(x)	(0x01ul << (x))

/* INTFR */
#define EXTI_INTFR_IFx_MASK	(0x03FFul << 0)
#define EXTI_INTFR_IF(x)	(0x01ul << (x))

typedef struct {
	uint32_t INTENR;	/**< Interrupt enable */
	uint32_t EVENR;		/**< Event enable */
	uint32_t RTENR;		/**< Rising edge trigger enable */
	uint32_t FTENR;		/**< Falling edge trigger enable */
	uint32_t SWIEVR;	/**< Soft interrupt event */
	uint32_t INTFR;		/**< Interrupt flag */
} per_exti_t;

volatile per_exti_t *EXTI = (volatile per_exti_t *)EXTI_REG_OFFSET;

#endif /* _PERIPHERAL_EXTI_H_ */