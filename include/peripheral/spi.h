/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_SPI_H_
#define _PERIPHERAL_SPI_H_

#include <stdint.h>

#define SPI_REG_OFFSET			(0x40013000ul)

/* CTLR1 */
#define SPI_CTLR1_BIDIMODE_MASK		(0x01ul << 15)
#define SPI_CTLR1_BIDIMODE		(0x01ul << 15)

#define SPI_CTLR1_BIDIOE_MASK		(0x01ul << 14)
#define SPI_CTLR1_BIDIOE		(0x01ul << 14)

#define SPI_CTLR1_CRCEN_MASK		(0x01ul << 13)
#define SPI_CTLR1_CRCEN			(0x01ul << 13)

#define SPI_CTLR1_CRCNEXT_MASK		(0x01ul << 12)
#define SPI_CTLR1_CRCNEXT		(0x01ul << 12)

#define SPI_CTLR1_DFF_MASK		(0x01ul << 11)
#define SPI_CTLR1_DFF			(0x01ul << 11)

#define SPI_CTLR1_RXONLY_MASK		(0x01ul << 10)
#define SPI_CTLR1_RXONLY		(0x01ul << 10)

#define SPI_CTLR1_SSM_MASK		(0x01ul << 9)
#define SPI_CTLR1_SSM			(0x01ul << 9)

#define SPI_CTLR1_SSI_MASK		(0x01ul << 8)
#define SPI_CTLR1_SSI			(0x01ul << 8)

#define SPI_CTLR1_SPE_MASK		(0x01ul << 6)
#define SPI_CTLR1_SPE			(0x01ul << 6)

#define SPI_CTLR1_BR_MASK		(0x07ul << 3)
#define SPI_CTLR1_BR_2			(0x00ul << 3)
#define SPI_CTLR1_BR_4			(0x01ul << 3)
#define SPI_CTLR1_BR_8			(0x02ul << 3)
#define SPI_CTLR1_BR_16			(0x03ul << 3)
#define SPI_CTLR1_BR_32			(0x04ul << 3)
#define SPI_CTLR1_BR_64			(0x05ul << 3)
#define SPI_CTLR1_BR_128		(0x06ul << 3)
#define SPI_CTLR1_BR_256		(0x07ul << 3)

#define SPI_CTLR1_MSTR_MASK		(0x01ul << 2)
#define SPI_CTLR1_MSTR			(0x01ul << 2)

#define SPI_CTLR1_CPOL_MASK		(0x01ul << 1)
#define SPI_CTLR1_CPOL			(0x01ul << 1)

#define SPI_CTLR1_CPHA_MASK		(0x01ul << 0)
#define SPI_CTLR1_CPHA			(0x01ul << 0)

/* CTLR2 */
#define SPI_CTLR2_TXEIE_MASK		(0x01ul << 7)
#define SPI_CTLR2_TXEIE			(0x01ul << 7)

#define SPI_CTLR2_RXNEIE_MASK		(0x01ul << 6)
#define SPI_CTLR2_RXNEIE		(0x01ul << 6)

#define SPI_CTLR2_ERRIE_MASK		(0x01ul << 5)
#define SPI_CTLR2_ERRIE			(0x01ul << 5)

#define SPI_CTLR2_SSOE_MASK		(0x01ul << 2)
#define SPI_CTLR2_SSOE			(0x01ul << 2)

#define SPI_CTLR2_TXDMAEN_MASK		(0x01ul << 1)
#define SPI_CTLR2_TXDMAEN		(0x01ul << 1)

#define SPI_CTLR2_RXDMAEN_MASK		(0x01ul << 0)
#define SPI_CTLR2_RXDMAEN		(0x01ul << 0)

/* STATR */
#define SPI_STATR_BSY_MASK		(0x01ul << 7)
#define SPI_STATR_BSY			(0x01ul << 7)

#define SPI_STATR_OVR_MASK		(0x01ul << 6)
#define SPI_STATR_OVR			(0x01ul << 6)

#define SPI_STATR_MODF_MASK		(0x01ul << 5)
#define SPI_STATR_MODF			(0x01ul << 5)

#define SPI_STATR_CRCERR_MASK		(0x01ul << 4)
#define SPI_STATR_CRCERR		(0x01ul << 4)

#define SPI_STATR_UDR_MASK		(0x01ul << 3)
#define SPI_STATR_UDR			(0x01ul << 3)

#define SPI_STATR_CHSID_MASK		(0x01ul << 2)
#define SPI_STATR_CHSID			(0x01ul << 2)

#define SPI_STATR_TXE_MASK		(0x01ul << 1)
#define SPI_STATR_TXE			(0x01ul << 1)

#define SPI_STATR_RXNE_MASK		(0x01ul << 0)
#define SPI_STATR_RXNE			(0x01ul << 0)

/* DATAR */
#define SPI_DATAR_MASK			(0xFFFFul << 0)
#define SPI_DATAR_VAL(x)		((x) & SPI_DATAR_MASK)
#define SPI_DATAR(x)			((x) << 0)

/* CRCR */
#define SPI_CRCR_MASK			(0xFFFFul << 0)
#define SPI_CRCR_VAL(x)			((x) & SPI_CRCR_MASK)
#define SPI_CRCR(x)			((x) << 0)

/* RCRCR */
#define SPI_RCRCR_MASK			(0xFFFFul << 0)
#define SPI_RCRCR_VAL(x)		((x) & SPI_RCRCR_MASK)
#define SPI_RCRCR(x)			((x) << 0)

/* TCRCR */
#define SPI_TCRCR_MASK			(0xFFFFul << 0)
#define SPI_TCRCR_VAL(x)		((x) & SPI_TCRCR_MASK)
#define SPI_TCRCR(x)			((x) << 0)

/* HSCR */
#define SPI_HSCR_HSRXEN_MASK		(0x01ul << 0)
#define SPI_HSCR_HSRXEN			(0x01ul << 0)

typedef struct {
	uint16_t CTLR1;			/**< Control 1 */
	uint16_t RESERVED;		/**< RESERVED */
	uint16_t CTLR2;			/**< Control 2 */
	uint16_t RESERVED2;		/**< RESERVED */
	uint16_t STATR;			/**< Status */
	uint16_t RESERVED3;		/**< RESERVED */
	uint16_t DATAR;			/**< Data */
	uint16_t RESERVED4;		/**< RESERVED */
	uint16_t CRCR;			/**< Polynomial */
	uint16_t RESERVED5;		/**< RESERVED */
	uint16_t RCRCR;			/**< Receive CRC */
	uint16_t RESERVED6;		/**< RESERVED */
	uint16_t TCRCR;			/**< Transmit CRC */
	uint16_t RESERVED7[5];		/**< RESERVED */
	uint16_t HSCR;			/**< High-speed control */
} per_spi_t;

extern volatile per_spi_t *SPI;

#endif /* _PERIPHERAL_SPI_H_ */