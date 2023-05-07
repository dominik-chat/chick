/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_FLASH_H_
#define _PERIPHERAL_FLASH_H_

#include <stdint.h>

#define FLASH_REG_OFFSET		(0x40022000ul)

/* ACTLR */
#define FLASH_ACTLR_LATENCY_MASK	(0x03ul << 0)
#define FLASH_ACTLR_LATENCY_0		(0x00ul << 0)
#define FLASH_ACTLR_LATENCY_1		(0x00ul << 0)

/* KEYR */
#define FLASH_KEYR_MASK			(0xFFFFFFFFul << 0)
#define FLASH_KEYR_KEY_RDPRT		(0x000000A5ul)
#define FLASH_KEYR_KEY1			(0x45670123ul)
#define FLASH_KEYR_KEY2			(0xCDEF89ABul)

/* OBKETR */
#define FLASH_OBKETR_MASK		(0xFFFFFFFFul << 0)
#define FLASH_OBKETR_KEY1		(0x45670123ul)
#define FLASH_OBKETR_KEY2		(0xCDEF89ABul)

/* STATR */
#define FLASH_STATR_LOCK_MASK		(0x01ul << 15)
#define FLASH_STATR_LOCK		(0x01ul << 15)

#define FLASH_STATR_MODE_MASK		(0x01ul << 14)
#define FLASH_STATR_MODE		(0x01ul << 14)

#define FLASH_STATR_EOP_MASK		(0x01ul << 5)
#define FLASH_STATR_EOP			(0x01ul << 5)

#define FLASH_STATR_WRPRTERR_MASK	(0x01ul << 4)
#define FLASH_STATR_WRPRTERR		(0x01ul << 4)

#define FLASH_STATR_BUSY_MASK		(0x01ul << 0)
#define FLASH_STATR_BUSY		(0x01ul << 0)

/* CTLR */
#define FLASH_CTLR_BUFRST_MASK		(0x01ul << 19)
#define FLASH_CTLR_BUFRST		(0x01ul << 19)

#define FLASH_CTLR_BUFLOAD_MASK		(0x01ul << 18)
#define FLASH_CTLR_BUFLOAD		(0x01ul << 18)

#define FLASH_CTLR_FTER_MASK		(0x01ul << 17)
#define FLASH_CTLR_FTER			(0x01ul << 17)

#define FLASH_CTLR_FTPG_MASK		(0x01ul << 16)
#define FLASH_CTLR_FTPG			(0x01ul << 16)

#define FLASH_CTLR_FLOCK_MASK		(0x01ul << 15)
#define FLASH_CTLR_FLOCK		(0x01ul << 15)

#define FLASH_CTLR_EOPIE_MASK		(0x01ul << 12)
#define FLASH_CTLR_EOPIE		(0x01ul << 12)

#define FLASH_CTLR_ERRIE_MASK		(0x01ul << 10)
#define FLASH_CTLR_ERRIE		(0x01ul << 10)

#define FLASH_CTLR_OBWRE_MASK		(0x01ul << 9)
#define FLASH_CTLR_OBWRE		(0x01ul << 9)

#define FLASH_CTLR_LOCK_MASK		(0x01ul << 7)
#define FLASH_CTLR_LOCK			(0x01ul << 7)

#define FLASH_CTLR_STRT_MASK		(0x01ul << 6)
#define FLASH_CTLR_STRT			(0x01ul << 6)

#define FLASH_CTLR_OBER_MASK		(0x01ul << 5)
#define FLASH_CTLR_OBER			(0x01ul << 5)

#define FLASH_CTLR_OBG_MASK		(0x01ul << 4)
#define FLASH_CTLR_OBG			(0x01ul << 4)

#define FLASH_CTLR_MER_MASK		(0x01ul << 2)
#define FLASH_CTLR_MER			(0x01ul << 2)

#define FLASH_CTLR_PER_MASK		(0x01ul << 1)
#define FLASH_CTLR_PER			(0x01ul << 1)

#define FLASH_CTLR_PG_MASK		(0x01ul << 0)
#define FLASH_CTLR_PG			(0x01ul << 0)

/* ADDR */
#define FLASH_ADDR_MASK			(0xFFFFFFFFul << 0)
#define FLASH_ADDR(x)			(x)

/* OBR */
#define FLASH_OBR_DATA1_MASK		(0xFFul << 18)
#define FLASH_OBR_DATA1(x)		((x) << 18)

#define FLASH_OBR_DATA0_MASK		(0xFFul << 10)
#define FLASH_OBR_DATA0(x)		((x) << 10)

#define FLASH_OBR_CFGRSTT_MASK		(0x03ul << 5)

#define FLASH_OBR_STANDYRST_MASK	(0x01ul << 4)
#define FLASH_OBR_STANDYRST		(0x01ul << 4)

#define FLASH_OBR_IWDG_SW_MASK		(0x01ul << 2)
#define FLASH_OBR_IWDG_SW		(0x01ul << 2)

#define FLASH_OBR_RDPRT_MASK		(0x01ul << 1)
#define FLASH_OBR_RDPRT			(0x01ul << 1)

#define FLASH_OBR_OBERR_MASK		(0x01ul << 0)
#define FLASH_OBR_OBERR			(0x01ul << 0)

/* WPR */
#define FLASH_WPR_MASK(x)		(0x01ul << x)
#define FLASH_WPR(x)			(0x01ul << x)

/* MODEKEYR */
#define FLASH_MODEKEYR_MASK		(0xFFFFFFFFul << 0)
#define FLASH_MODEKEYR_KEY1		(0x45670123ul)
#define FLASH_MODEKEYR_KEY2		(0xCDEF89ABul)

/* BOOT_MODEKEYR */
#define FLASH_BOOT_MODEKEYR_MASK	(0xFFFFFFFFul << 0)
#define FLASH_BOOT_MODEKEYR_KEY1	(0x45670123ul)
#define FLASH_BOOT_MODEKEYR_KEY2	(0xCDEF89ABul)

typedef struct {
	uint32_t ACTLR;			/**< Control */
	uint32_t KEYR;			/**< FPEC key */
	uint32_t OBKETR;		/**< OBKEY */
	uint32_t STATR;			/**< Status */
	uint32_t CTLR;			/**< Configuration */
	uint32_t ADDR;			/**< Address */
	uint32_t RESERVED;		/**< RESERVED */
	uint32_t OBR;			/**< Select word */
	uint32_t WPR;			/**< Write protection */
	uint32_t MODEKEYR;		/**< Extended key */
	uint32_t BOOT_MODEKEYR;		/**< Unlock BOOT key */
} per_flash_t;

extern volatile per_flash_t *FLASH;

#endif /* _PERIPHERAL_FLASH_H_ */