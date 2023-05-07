/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_PWR_H_
#define _PERIPHERAL_PWR_H_

#include <stdint.h>

#define PWR_REG_OFFSET		(0x40007000ul)

/* CTRL */
#define PWR_CTRL_PLS_MASK	(0x07ul << 5)
#define PWR_CTRL_PLS_285_27	(0x00ul << 5)
#define PWR_CTRL_PLS_305_29	(0x01ul << 5)
#define PWR_CTRL_PLS_33_315	(0x02ul << 5)
#define PWR_CTRL_PLS_35_33	(0x03ul << 5)
#define PWR_CTRL_PLS_37_35	(0x04ul << 5)
#define PWR_CTRL_PLS_39_37	(0x05ul << 5)
#define PWR_CTRL_PLS_41_39	(0x06ul << 5)
#define PWR_CTRL_PLS_44_42	(0x07ul << 5)

#define PWR_CTRL_PVDE_MASK	(0x01ul << 4)
#define PWR_CTRL_PVDE		(0x01ul << 4)

#define PWR_CTRL_PDDS_MASK	(0x01ul << 1)
#define PWR_CTRL_PDDS		(0x01ul << 1)

/* CSR */
#define PWR_CSR_PVD0_MASK	(0x01ul << 2)
#define PWR_CSR_PVD0		(0x01ul << 2)

/* AWUCSR */
#define PWR_AWUCSR_AWUEN_MASK	(0x01ul << 1)
#define PWR_AWUCSR_AWUEN	(0x01ul << 1)

/* AWUWR */
#define PWR_AWUWR_MASK		(0x3Ful << 0)

/* AWUPSC */
#define PWR_AWUPSC_MASK		(0x0Ful << 0)
#define PWR_AWUPSC_OFF		(0x00ul << 0)
#define PWR_AWUPSC_2		(0x02ul << 0)
#define PWR_AWUPSC_4		(0x03ul << 0)
#define PWR_AWUPSC_8		(0x04ul << 0)
#define PWR_AWUPSC_16		(0x05ul << 0)
#define PWR_AWUPSC_32		(0x06ul << 0)
#define PWR_AWUPSC_64		(0x07ul << 0)
#define PWR_AWUPSC_128		(0x08ul << 0)
#define PWR_AWUPSC_256		(0x09ul << 0)
#define PWR_AWUPSC_512		(0x0Aul << 0)
#define PWR_AWUPSC_1024		(0x0Bul << 0)
#define PWR_AWUPSC_2048		(0x0Cul << 0)
#define PWR_AWUPSC_4096		(0x0Dul << 0)
#define PWR_AWUPSC_10240	(0x0Eul << 0)
#define PWR_AWUPSC_61440	(0x0Ful << 0)

typedef struct {
	uint32_t CTRL;		/**< Control */
	uint32_t CSR;		/**< Control/status */
	uint32_t AWUCSR;	/**< Auto-wakeup control/status */
	uint32_t AWUWR;		/**< Auto-wakeup window comparison value */
	uint32_t AWUPSC;	/**< Auto-wakeup crossover factor */
} per_pwr_t;

extern volatile per_pwr_t *PWR;

#endif /* _PERIPHERAL_PWR_H_ */