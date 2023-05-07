/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_USART_H_
#define _PERIPHERAL_USART_H_

#include <stdint.h>

#define USART_REG_OFFSET		(0x40013800ul)

/* STATR */
#define USART_STATR_CTS_MASK		(0x01ul << 9)
#define USART_STATR_CTS			(0x01ul << 9)

#define USART_STATR_LBD_MASK		(0x01ul << 8)
#define USART_STATR_LBD			(0x01ul << 8)

#define USART_STATR_TXE_MASK		(0x01ul << 7)
#define USART_STATR_TXE			(0x01ul << 7)

#define USART_STATR_TC_MASK		(0x01ul << 6)
#define USART_STATR_TC			(0x01ul << 6)

#define USART_STATR_RXNE_MASK		(0x01ul << 5)
#define USART_STATR_RXNE		(0x01ul << 5)

#define USART_STATR_IDLE_MASK		(0x01ul << 4)
#define USART_STATR_IDLE		(0x01ul << 4)

#define USART_STATR_ORE_MASK		(0x01ul << 3)
#define USART_STATR_ORE			(0x01ul << 3)

#define USART_STATR_NE_MASK		(0x01ul << 2)
#define USART_STATR_NE			(0x01ul << 2)

#define USART_STATR_FE_MASK		(0x01ul << 1)
#define USART_STATR_FE			(0x01ul << 1)

#define USART_STATR_PE_MASK		(0x01ul << 0)
#define USART_STATR_PE			(0x01ul << 0)

/* DATAR */
#define USART_STATR_DR_MASK		(0xFFul << 0)
#define USART_STATR_DR(x)		((x) << 0)

/* BRR */
#define USART_BRR_MANTISSA_MASK		(0x0FFFul << 4)
#define USART_BRR_MANTISSA(x)		((x) << 4)

#define USART_BRR_FRACTION_MASK		(0x0Ful << 0)
#define USART_BRR_FRACTION(x)		((x) << 0)

/* CTRL1 */
#define USART_CTRL1_UE_MASK		(0x01ul << 13)
#define USART_CTRL1_UE			(0x01ul << 13)

#define USART_CTRL1_M_MASK		(0x01ul << 12)
#define USART_CTRL1_M			(0x01ul << 12)

#define USART_CTRL1_WAKE_MASK		(0x01ul << 11)
#define USART_CTRL1_WAKE		(0x01ul << 11)

#define USART_CTRL1_PCE_MASK		(0x01ul << 10)
#define USART_CTRL1_PCE			(0x01ul << 10)

#define USART_CTRL1_PS_MASK		(0x01ul << 9)
#define USART_CTRL1_PS			(0x01ul << 9)

#define USART_CTRL1_PEIE_MASK		(0x01ul << 8)
#define USART_CTRL1_PEIE		(0x01ul << 8)

#define USART_CTRL1_TXEIE_MASK		(0x01ul << 7)
#define USART_CTRL1_TXEIE		(0x01ul << 7)

#define USART_CTRL1_TCIE_MASK		(0x01ul << 6)
#define USART_CTRL1_TCIE		(0x01ul << 6)

#define USART_CTRL1_RXNEIE_MASK		(0x01ul << 5)
#define USART_CTRL1_RXNEIE		(0x01ul << 5)

#define USART_CTRL1_IDLEIE_MASK		(0x01ul << 4)
#define USART_CTRL1_IDLEIE		(0x01ul << 4)

#define USART_CTRL1_TE_MASK		(0x01ul << 3)
#define USART_CTRL1_TE			(0x01ul << 3)

#define USART_CTRL1_RE_MASK		(0x01ul << 2)
#define USART_CTRL1_RE			(0x01ul << 2)

#define USART_CTRL1_RWU_MASK		(0x01ul << 1)
#define USART_CTRL1_RWU			(0x01ul << 1)

#define USART_CTRL1_SBK_MASK		(0x01ul << 0)
#define USART_CTRL1_SBK			(0x01ul << 0)

/* CTRL2 */
#define USART_CTRL2_LINEN_MASK		(0x01ul << 14)
#define USART_CTRL2_LINEN		(0x01ul << 14)

#define USART_CTRL2_STOP_MASK		(0x03ul << 12)
#define USART_CTRL2_STOP_1		(0x00ul << 12)
#define USART_CTRL2_STOP_0_5		(0x01ul << 12)
#define USART_CTRL2_STOP_2		(0x02ul << 12)
#define USART_CTRL2_STOP_1_5		(0x03ul << 12)

#define USART_CTRL2_CLKEN_MASK		(0x01ul << 11)
#define USART_CTRL2_CLKEN		(0x01ul << 11)

#define USART_CTRL2_CPOL_MASK		(0x01ul << 10)
#define USART_CTRL2_CPOL		(0x01ul << 10)

#define USART_CTRL2_CPHA_MASK		(0x01ul << 9)
#define USART_CTRL2_CPHA		(0x01ul << 9)

#define USART_CTRL2_LBCL_MASK		(0x01ul << 8)
#define USART_CTRL2_LBCL		(0x01ul << 8)

#define USART_CTRL2_LBDIE_MASK		(0x01ul << 6)
#define USART_CTRL2_LBDIE		(0x01ul << 6)

#define USART_CTRL2_LBDL_MASK		(0x01ul << 5)
#define USART_CTRL2_LBDL		(0x01ul << 5)

#define USART_CTRL2_ADD_MASK		(0x0Ful << 0)
#define USART_CTRL2_ADD(x)		((x) << 0)

/* CTRL 3 */
#define USART_CTRL3_CTSIE_MASK		(0x01ul << 10)
#define USART_CTRL3_CTSIE		(0x01ul << 10)

#define USART_CTRL3_CTSE_MASK		(0x01ul << 9)
#define USART_CTRL3_CTSE		(0x01ul << 9)

#define USART_CTRL3_RTSE_MASK		(0x01ul << 8)
#define USART_CTRL3_RTSE		(0x01ul << 8)

#define USART_CTRL3_DMAT_MASK		(0x01ul << 7)
#define USART_CTRL3_DMAT		(0x01ul << 7)

#define USART_CTRL3_DMAR_MASK		(0x01ul << 6)
#define USART_CTRL3_DMAR		(0x01ul << 6)

#define USART_CTRL3_SCEN_MASK		(0x01ul << 5)
#define USART_CTRL3_SCEN		(0x01ul << 5)

#define USART_CTRL3_NACK_MASK		(0x01ul << 4)
#define USART_CTRL3_NACK		(0x01ul << 4)

#define USART_CTRL3_HDSEL_MASK		(0x01ul << 3)
#define USART_CTRL3_HDSEL		(0x01ul << 3)

#define USART_CTRL3_IRLP_MASK		(0x01ul << 2)
#define USART_CTRL3_IRLP		(0x01ul << 2)

#define USART_CTRL3_IREN_MASK		(0x01ul << 1)
#define USART_CTRL3_IREN		(0x01ul << 1)

#define USART_CTRL3_EIE_MASK		(0x01ul << 0)
#define USART_CTRL3_EIE			(0x01ul << 0)

/* GPR */
#define USART_GPR_GT_MASK		(0xFFul << 8)
#define USART_GPR_GT(x)			((x) << 8)

#define USART_GPR_PSC_MASK		(0xFFul << 0)
#define USART_GPR_PSC(x)		((x) << 0)

typedef struct {
	uint32_t STATR;			/**< Status */
	uint32_t DATAR;			/**< Data */
	uint32_t BRR;			/**< Baud rate */
	uint32_t CTLR1;			/**< Control 1 */
	uint32_t CTLR2;			/**< Control 2 */
	uint32_t CTLR3;			/**< Control 3 */
	uint32_t GPR;			/**< Protection time and prescaler */
} per_usart_t;

extern volatile per_usart_t *USART;

#endif /* _PERIPHERAL_USART_H_ */