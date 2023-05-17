/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_PFIC_H_
#define _PERIPHERAL_PFIC_H_

#include <stdint.h>

#define PFIC_REG_OFFSET			(0xE000E000ul)

/* ISR1 */
#define PFIC_ISR1_INTENSTA_16_31_MASK	(0xFFFFul << 16)
#define PFIC_ISR1_INTENSTA_16_31(x)	(0x01ul << (x))

#define PFIC_ISR1_INTENSTA_14_MASK	(0x01ul << 14)
#define PFIC_ISR1_INTENSTA_14		(0x01ul << 14)

#define PFIC_ISR1_INTENSTA_12_MASK	(0x01ul << 12)
#define PFIC_ISR1_INTENSTA_12		(0x01ul << 12)

#define PFIC_ISR1_INTENSTA_2_3_MASK	(0x03ul << 2)
#define PFIC_ISR1_INTENSTA_2_3(x)	(0x01ul << (x))

/* ISR2 */
#define PFIC_ISR2_INTENSTA_32_38_MASK	(0x7Ful << 0)
#define PFIC_ISR2_INTENSTA_32_38(x)	(0x01ul << ((x) - 32))

/* IPR1 */
#define PFIC_IPR1_PENDSTA_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IPR1_PENDSTA_16_31(x)	(0x01ul << (x))

#define PFIC_IPR1_PENDSTA_14_MASK	(0x01ul << 14)
#define PFIC_IPR1_PENDSTA_14		(0x01ul << 14)

#define PFIC_IPR1_PENDSTA_12_MASK	(0x01ul << 12)
#define PFIC_IPR1_PENDSTA_12		(0x01ul << 12)

#define PFIC_IPR1_PENDSTA_2_3_MASK	(0x03ul << 2)
#define PFIC_IPR1_PENDSTA_2_3(x)	(0x01ul << (x))

/* IPR2 */
#define PFIC_IPR2_PENDSTA_32_38_MASK	(0x7Ful << 0)
#define PFIC_IPR2_PENDSTA_32_38(x)	(0x01ul << ((x) - 32))

/* ITHRESDR */
#define PFIC_ITHRESDR_THRESHOLD_MASK	(0x03ul << 6)
#define PFIC_ITHRESDR_THRESHOLD(x)	((x) << 6)

/* CFGR */
#define PFIC_CFGR_KEYCODE_MASK		(0xFFFFul << 16)
#define PFIC_CFGR_KEYCODE(x)		((x) << 16)

#define PFIC_CFGR_RESETSYS_MASK		(0x01ul << 7)
#define PFIC_CFGR_RESETSYS		(0x01ul << 7)

/* GISR */
#define PFIC_GISR_GPENDSTA_MASK		(0x01ul << 9)
#define PFIC_GISR_GPENDSTA		(0x01ul << 9)

#define PFIC_GISR_GACTSTA_MASK		(0x01ul << 9)
#define PFIC_GISR_GACTSTA		(0x01ul << 9)

#define PFIC_GISR_NESTSTA_MASK		(0xFFul << 0)
#define PFIC_GISR_NESTSTA_1		(0x01ul << 0)
#define PFIC_GISR_NESTSTA_2		(0x03ul << 0)

/* VTFIDR */
#define PFIC_VTFIDR_VTFID1_MASK		(0xFFul << 8)
#define PFIC_VTFIDR_VTFID1(x)		((x) << 8)

#define PFIC_VTFIDR_VTFID0_MASK		(0xFFul << 0)
#define PFIC_VTFIDR_VTFID0(x)		((x) << 0)

/* VTFADDRR0 */
#define PFIC_VTFADDRR0_ADDR0_MASK	(0xFFFFFFFEul)
#define PFIC_VTFADDRR0_ADDR0(x)		((x) << 0)

#define PFIC_VTFADDRR0_VTF0EN_MASK	(0x01ul << 0)
#define PFIC_VTFADDRR0_VTF0EN		(0x01ul << 0)

/* VTFADDRR1 */
#define PFIC_VTFADDRR1_ADDR1_MASK	(0xFFFFFFFEul)
#define PFIC_VTFADDRR1_ADDR1(x)		((x) << 0)

#define PFIC_VTFADDRR1_VTF1EN_MASK	(0x01ul << 0)
#define PFIC_VTFADDRR1_VTF1EN		(0x01ul << 0)

/* IENR1 */
#define PFIC_IENR1_INTEN_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IENR1_INTEN_16_31(x)	(0x01ul << (x))

#define PFIC_IENR1_INTEN_14_MASK	(0x01ul << 14)
#define PFIC_IENR1_INTEN_14		(0x01ul << 14)

#define PFIC_IENR1_INTEN_12_MASK	(0x01ul << 12)
#define PFIC_IENR1_INTEN_12		(0x01ul << 12)

#define PFIC_IENR1_INTEN_2_3_MASK	(0x03ul << 2)
#define PFIC_IENR1_INTEN_2_3(x)		(0x01ul << (x))

/* IENR2 */
#define PFIC_IENR2_INTEN_32_38_MASK	(0x7Ful << 0)
#define PFIC_IENR2_INTEN_32_38(x)	(0x01ul << ((x) - 32))

/* IRER1 */
#define PFIC_IRER1_INTRSET_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IRER1_INTRSET_16_31(x)	(0x01ul << (x))

#define PFIC_IRER1_INTRSET_14_MASK	(0x01ul << 14)
#define PFIC_IRER1_INTRSET_14		(0x01ul << 14)

#define PFIC_IRER1_INTRSET_12_MASK	(0x01ul << 12)
#define PFIC_IRER1_INTRSET_12		(0x01ul << 12)

#define PFIC_IRER1_INTRSET_2_3_MASK	(0x03ul << 2)
#define PFIC_IRER1_INTRSET_2_3(x)	(0x01ul << (x))

/* IRER2 */
#define PFIC_IRER2_INTRSET_32_38_MASK	(0x7Ful << 0)
#define PFIC_IRER2_INTRSET_32_38(x)	(0x01ul << ((x) - 32))

/* IPSR1 */
#define PFIC_IPSR1_PENDSET_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IPSR1_PENDSET_16_31(x)	(0x01ul << (x))

#define PFIC_IPSR1_PENDSET_14_MASK	(0x01ul << 14)
#define PFIC_IPSR1_PENDSET_14		(0x01ul << 14)

#define PFIC_IPSR1_PENDSET_12_MASK	(0x01ul << 12)
#define PFIC_IPSR1_PENDSET_12		(0x01ul << 12)

#define PFIC_IPSR1_PENDSET_2_3_MASK	(0x03ul << 2)
#define PFIC_IPSR1_PENDSET_2_3(x)	(0x01ul << (x))

/* IPSR2 */
#define PFIC_IPSR2_PENDSET_32_38_MASK	(0x7Ful << 0)
#define PFIC_IPSR2_PENDSET_32_38(x)	(0x01ul << ((x) - 32))

/* IPRR1 */
#define PFIC_IPRR1_PENDRESET_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IPRR1_PENDRESET_16_31(x)	(0x01ul << (x))

#define PFIC_IPRR1_PENDRESET_14_MASK	(0x01ul << 14)
#define PFIC_IPRR1_PENDRESET_14		(0x01ul << 14)

#define PFIC_IPRR1_PENDRESET_12_MASK	(0x01ul << 12)
#define PFIC_IPRR1_PENDRESET_12		(0x01ul << 12)

#define PFIC_IPRR1_PENDRESET_2_3_MASK	(0x03ul << 2)
#define PFIC_IPRR1_PENDRESET_2_3(x)	(0x01ul << (x))

/* IPRR2 */
#define PFIC_IPRR2_PENDRESET_32_38_MASK	(0x7Ful << 0)
#define PFIC_IPRR2_PENDRESET_32_38(x)	(0x01ul << ((x) - 32))

/* IACTR1 */
#define PFIC_IACTR1_IACTS_16_31_MASK	(0xFFFFul << 16)
#define PFIC_IACTR1_IACTS_16_31(x)	(0x01ul << (x))

#define PFIC_IACTR1_IACTS_14_MASK	(0x01ul << 14)
#define PFIC_IACTR1_IACTS_14		(0x01ul << 14)

#define PFIC_IACTR1_IACTS_12_MASK	(0x01ul << 12)
#define PFIC_IACTR1_IACTS_12		(0x01ul << 12)

#define PFIC_IACTR1_IACTS_2_3_MASK	(0x03ul << 2)
#define PFIC_IACTR1_IACTS_2_3(x)	(0x01ul << (x))

/* IACTR2 */
#define PFIC_IACTR2_IACTS_32_38_MASK	(0x7Ful << 0)
#define PFIC_IACTR2_IACTS_32_38(x)	(0x01ul << ((x) - 32))

/* IPRIOR */
#define PFIC_IPRIOR_IP_MASK(x)		(0xFFul << ((x) % 4))
#define PFIC_IPRIOR_IP_REG(x)		((x) / 4)
#define PFIC_IPRIOR_IP(x, y)		((y) << ((x) % 4))

/* SCTLR */
#define PFIC_SCTLR_SYSRESET_MASK	(0x01ul << 31)
#define PFIC_SCTLR_SYSRESET		(0x01ul << 31)

#define PFIC_SCTLR_SETEVENT_MASK	(0x01ul << 5)
#define PFIC_SCTLR_SETEVENT		(0x01ul << 5)

#define PFIC_SCTLR_SEVONPEND_MASK	(0x01ul << 4)
#define PFIC_SCTLR_SEVONPEND		(0x01ul << 4)

#define PFIC_SCTLR_WFITOWFE_MASK	(0x01ul << 3)
#define PFIC_SCTLR_WFITOWFE		(0x01ul << 3)

#define PFIC_SCTLR_SLEEPDEEP_MASK	(0x01ul << 2)
#define PFIC_SCTLR_SLEEPDEEP		(0x01ul << 2)

#define PFIC_SCTLR_SLEEPONEXIT_MASK	(0x01ul << 1)
#define PFIC_SCTLR_SLEEPONEXIT		(0x01ul << 1)

typedef struct {
	uint32_t ISR1;			/**< Interrupt enable status 1 */
	uint32_t ISR2;			/**< Interrupt enable status 2 */
	uint32_t RESERVED[6];		/**< RESERVED */
	uint32_t IPR1;			/**< Interrupt pending status 1 */
	uint32_t IPR2;			/**< Interrupt pending status 2 */
	uint32_t RESERVED2[6];		/**< RESERVED */
	uint32_t ITHRESDR;		/**< Interrupt priority threshold configuration */
	uint32_t RESERVED3;		/**< RESERVED */
	uint32_t CFGR;			/**< Interrupt configuration */
	uint32_t GISR;			/**< Interrupt global status */
	uint32_t VTFIDR;		/**< VTF interrupt ID configuration */
	uint32_t RESERVED4[3];		/**< RESERVED */
	uint32_t VTFADDRR0;		/**< VTF interrupt 0 offset address */
	uint32_t VTFADDRR1;		/**< VTF interrupt 1 offset address */
	uint32_t RESERVED5[38];		/**< RESERVED */
	uint32_t IENR1;			/**< Interrupt enable setting 1 */
	uint32_t IENR2;			/**< Interrupt enable setting 2 */
	uint32_t RESERVED6[30];		/**< RESERVED */
	uint32_t IRER1;			/**< Interrupt enable clear 1 */
	uint32_t IRER2;			/**< Interrupt enable clear 2 */
	uint32_t RESERVED7[30];		/**< RESERVED */
	uint32_t IPSR1;			/**< Interrupt pending setting 1 */
	uint32_t IPSR2;			/**< Interrupt pending setting 2 */
	uint32_t RESERVED8[30];		/**< RESERVED */
	uint32_t IPRR1;			/**< Interrupt hang clear 1 */
	uint32_t IPRR2;			/**< Interrupt hang clear 2 */
	uint32_t RESERVED9[30];		/**< RESERVED */
	uint32_t IACTR1;		/**< Interrupt activation status 1 */
	uint32_t IACTR2;		/**< Interrupt activation status 2 */
	uint32_t RESERVED10[62];	/**< RESERVED */
	uint32_t IPRIOR[64];		/**< Interrupt priority configuration */
	uint32_t RESERVED11[516];	/**< RESERVED */
	uint32_t SCTLR;			/**< System control register */
} per_pfic_t;

extern volatile per_pfic_t *PFIC;

#endif /* _PERIPHERAL_PFIC_H_ */