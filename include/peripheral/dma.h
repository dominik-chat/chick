/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_DMA_H_
#define _PERIPHERAL_DMA_H_

#include <stdint.h>

#define DMA_REG_OFFSET			(0x40020000ul)

/* INTFR */
#define DMA_INTFR_TEIF_MASK(x)		(0x01ul << (((x) * 4) - 1))
#define DMA_INTFR_TEIF(x)		(0x01ul << (((x) * 4) - 1))

#define DMA_INTFR_HTIF_MASK(x)		(0x01ul << (((x) * 4) - 2))
#define DMA_INTFR_HTIF(x)		(0x01ul << (((x) * 4) - 2))

#define DMA_INTFR_TCIF_MASK(x)		(0x01ul << (((x) * 4) - 3))
#define DMA_INTFR_TCIF(x)		(0x01ul << (((x) * 4) - 3))

#define DMA_INTFR_GIF_MASK(x)		(0x01ul << (((x) * 4) - 4))
#define DMA_INTFR_GIF(x)		(0x01ul << (((x) * 4) - 4))

/* INTFCR */
#define DMA_INTFCR_CTEIF_MASK(x)	(0x01ul << (((x) * 4) - 1))
#define DMA_INTFCR_CTEIF(x)		(0x01ul << (((x) * 4) - 1))

#define DMA_INTFCR_CHTIF_MASK(x)	(0x01ul << (((x) * 4) - 2))
#define DMA_INTFCR_CHTIF(x)		(0x01ul << (((x) * 4) - 2))

#define DMA_INTFCR_CTCIF_MASK(x)	(0x01ul << (((x) * 4) - 3))
#define DMA_INTFCR_CTCIF(x)		(0x01ul << (((x) * 4) - 3))

#define DMA_INTFCR_CGIF_MASK(x)		(0x01ul << (((x) * 4) - 4))
#define DMA_INTFCR_CGIF(x)		(0x01ul << (((x) * 4) - 4))

/* CFGR */
#define DMA_CFGR_MEM2MEM_MASK		(0x01ul << 14)
#define DMA_CFGR_MEM2MEM		(0x01ul << 14)

#define DMA_CFGR_PL_MASK		(0x03ul << 12)
#define DMA_CFGR_PL_LOW			(0x00ul << 12)
#define DMA_CFGR_PL_MED			(0x01ul << 12)
#define DMA_CFGR_PL_HIGH		(0x02ul << 12)
#define DMA_CFGR_PL_VHIGH		(0x03ul << 12)

#define DMA_CFGR_MSIZE_MASK		(0x03ul << 10)
#define DMA_CFGR_MSIZE_8		(0x00ul << 10)
#define DMA_CFGR_MSIZE_16		(0x01ul << 10)
#define DMA_CFGR_MSIZE_32		(0x02ul << 10)

#define DMA_CFGR_PSIZE_MASK		(0x03ul << 8)
#define DMA_CFGR_PSIZE_8		(0x00ul << 8)
#define DMA_CFGR_PSIZE_16		(0x01ul << 8)
#define DMA_CFGR_PSIZE_32		(0x02ul << 8)

#define DMA_CFGR_MINC_MASK		(0x01ul << 7)
#define DMA_CFGR_MINC			(0x01ul << 7)

#define DMA_CFGR_PINC_MASK		(0x01ul << 6)
#define DMA_CFGR_PINC			(0x01ul << 6)

#define DMA_CFGR_CIRC_MASK		(0x01ul << 5)
#define DMA_CFGR_CIRC			(0x01ul << 5)

#define DMA_CFGR_DIR_MASK		(0x01ul << 4)
#define DMA_CFGR_DIR			(0x01ul << 4)

#define DMA_CFGR_TEIE_MASK		(0x01ul << 3)
#define DMA_CFGR_TEIE			(0x01ul << 3)

#define DMA_CFGR_HTIE_MASK		(0x01ul << 2)
#define DMA_CFGR_HTIE			(0x01ul << 2)

#define DMA_CFGR_TCIE_MASK		(0x01ul << 1)
#define DMA_CFGR_TCIE			(0x01ul << 1)

#define DMA_CFGR_EN_MASK		(0x01ul << 0)
#define DMA_CFGR_EN			(0x01ul << 0)

/* CNTR */
#define DMA_CNTR_MASK			(0xFFFFul << 0)
#define DMA_CNTR(x)			((x) << 0)

/* PADDR */
#define DMA_PADDR_MASK			(0xFFFFFFFFul << 0)
#define DMA_PADDR(x)			((x) << 0)

/* MADDR */
#define DMA_MADDR_MASK			(0xFFFFFFFFul << 0)
#define DMA_MADDR(x)			((x) << 0)

typedef struct {
	uint32_t INTFR;			/**< DMA interrupt status */
	uint32_t INTFCR;		/**< DMA interrupt flag clear */
	uint32_t CFGR1;			/**< DMA channel 1 configuration */
	uint32_t CNTR1;			/**< DMA channel 1 number of data */
	uint32_t PADDR1;		/**< DMA channel 1 peripheral address */
	uint32_t MADDR1;		/**< DMA channel 1 memory address */
	uint32_t RESERVED;		/**< RESERVED */
	uint32_t CFGR2;			/**< DMA channel 2 configuration */
	uint32_t CNTR2;			/**< DMA channel 2 number of data */
	uint32_t PADDR2;		/**< DMA channel 2 peripheral address */
	uint32_t MADDR2;		/**< DMA channel 2 memory address */
	uint32_t RESERVED2;		/**< RESERVED */
	uint32_t CFGR3;			/**< DMA channel 3 configuration */
	uint32_t CNTR3;			/**< DMA channel 3 number of data */
	uint32_t PADDR3;		/**< DMA channel 3 peripheral address */
	uint32_t MADDR3;		/**< DMA channel 3 memory address */
	uint32_t RESERVED3;		/**< RESERVED */
	uint32_t CFGR4;			/**< DMA channel 4 configuration */
	uint32_t CNTR4;			/**< DMA channel 4 number of data */
	uint32_t PADDR4;		/**< DMA channel 4 peripheral address */
	uint32_t MADDR4;		/**< DMA channel 4 memory address */
	uint32_t RESERVED4;		/**< RESERVED */
	uint32_t CFGR5;			/**< DMA channel 5 configuration */
	uint32_t CNTR5;			/**< DMA channel 5 number of data */
	uint32_t PADDR5;		/**< DMA channel 5 peripheral address */
	uint32_t MADDR5;		/**< DMA channel 5 memory address */
	uint32_t RESERVED5;		/**< RESERVED */
	uint32_t CFGR6;			/**< DMA channel 6 configuration */
	uint32_t CNTR6;			/**< DMA channel 6 number of data */
	uint32_t PADDR6;		/**< DMA channel 6 peripheral address */
	uint32_t MADDR6;		/**< DMA channel 6 memory address */
	uint32_t RESERVED6;		/**< RESERVED */
	uint32_t CFGR7;			/**< DMA channel 7 configuration */
	uint32_t CNTR7;			/**< DMA channel 7 number of data */
	uint32_t PADDR7;		/**< DMA channel 7 peripheral address */
	uint32_t MADDR7;		/**< DMA channel 7 memory address */
} per_dma_t;

extern volatile per_dma_t *DMA;

#endif /* _PERIPHERAL_DMA_H_ */