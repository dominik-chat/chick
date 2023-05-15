/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_I2C_H_
#define _PERIPHERAL_I2C_H_

#include <stdint.h>

#define I2C_REG_OFFSET			(0x40005400ul)

/* CTLR1 */
#define I2C_CTLR1_SWRST_MASK		(0x01ul << 15)
#define I2C_CTLR1_SWRST			(0x01ul << 15)

#define I2C_CTLR1_PEC_MASK		(0x01ul << 12)
#define I2C_CTLR1_PEC			(0x01ul << 12)

#define I2C_CTLR1_POS_MASK		(0x01ul << 11)
#define I2C_CTLR1_POS			(0x01ul << 11)

#define I2C_CTLR1_ACK_MASK		(0x01ul << 10)
#define I2C_CTLR1_ACK			(0x01ul << 10)

#define I2C_CTLR1_STOP_MASK		(0x01ul << 9)
#define I2C_CTLR1_STOP			(0x01ul << 9)

#define I2C_CTLR1_START_MASK		(0x01ul << 8)
#define I2C_CTLR1_START			(0x01ul << 8)

#define I2C_CTLR1_NOSTRETCH_MASK	(0x01ul << 7)
#define I2C_CTLR1_NOSTRETCH		(0x01ul << 7)

#define I2C_CTLR1_ENGC_MASK		(0x01ul << 6)
#define I2C_CTLR1_ENGC			(0x01ul << 6)

#define I2C_CTLR1_ENPEC_MASK		(0x01ul << 5)
#define I2C_CTLR1_ENPEC			(0x01ul << 5)

#define I2C_CTLR1_PE_MASK		(0x01ul << 0)
#define I2C_CTLR1_PE			(0x01ul << 0)

/* CTLR2 */
#define I2C_CTLR2_LAST_MASK		(0x01ul << 12)
#define I2C_CTLR2_LAST			(0x01ul << 12)

#define I2C_CTLR2_DMAEN_MASK		(0x01ul << 11)
#define I2C_CTLR2_DMAEN			(0x01ul << 11)

#define I2C_CTLR2_ITBUFEN_MASK		(0x01ul << 10)
#define I2C_CTLR2_ITBUFEN		(0x01ul << 10)

#define I2C_CTLR2_ITEVTEN_MASK		(0x01ul << 9)
#define I2C_CTLR2_ITEVTEN		(0x01ul << 9)

#define I2C_CTLR2_ITERREN_MASK		(0x01ul << 8)
#define I2C_CTLR2_ITERREN		(0x01ul << 8)

#define I2C_CTLR2_FREQ_MASK		(0x3Ful << 0)
#define I2C_CTLR2_FREQ(x)		((x) << 0)

/* OADDR1 */
#define I2C_OADDR1_ADDMODE_MASK		(0x01ul << 15)
#define I2C_OADDR1_ADDMODE		(0x01ul << 15)

#define I2C_OADDR1_ADD_10_MASK		(0x03FFul << 0)
#define I2C_OADDR1_ADD_10(x)		((x) << 0)

#define I2C_OADDR1_ADD_7_MASK		(0x7Ful << 1)
#define I2C_OADDR1_ADD_7(x)		((x) << 1)

/* OADDR2 */
#define I2C_OADDR2_ADD2_7_MASK		(0x7Ful << 1)
#define I2C_OADDR2_ADD2_7(x)		((x) << 1)

#define I2C_OADDR2_ENDUAL_MASK		(0x01ul << 0)
#define I2C_OADDR2_ENDUAL		(0x01ul << 0)

/* DATAR */
#define I2C_DATAR_MASK			(0xFFul << 0)
#define I2C_DATAR(x)			((x) << 0)

/* STAR1 */
#define I2C_STAR1_PECERR_MASK		(0x01ul << 12)
#define I2C_STAR1_PECERR		(0x01ul << 12)

#define I2C_STAR1_OVR_MASK		(0x01ul << 11)
#define I2C_STAR1_OVR			(0x01ul << 11)

#define I2C_STAR1_AF_MASK		(0x01ul << 10)
#define I2C_STAR1_AF			(0x01ul << 10)

#define I2C_STAR1_ARLO_MASK		(0x01ul << 9)
#define I2C_STAR1_ARLO			(0x01ul << 9)

#define I2C_STAR1_BERR_MASK		(0x01ul << 8)
#define I2C_STAR1_BERR			(0x01ul << 8)

#define I2C_STAR1_TXE_MASK		(0x01ul << 7)
#define I2C_STAR1_TXE			(0x01ul << 7)

#define I2C_STAR1_RXNE_MASK		(0x01ul << 6)
#define I2C_STAR1_RXNE			(0x01ul << 6)

#define I2C_STAR1_STOPF_MASK		(0x01ul << 4)
#define I2C_STAR1_STOPF			(0x01ul << 4)

#define I2C_STAR1_ADD10_MASK		(0x01ul << 3)
#define I2C_STAR1_ADD10			(0x01ul << 3)

#define I2C_STAR1_BTF_MASK		(0x01ul << 2)
#define I2C_STAR1_BTF			(0x01ul << 2)

#define I2C_STAR1_ADDR_MASK		(0x01ul << 1)
#define I2C_STAR1_ADDR			(0x01ul << 1)

#define I2C_STAR1_SB_MASK		(0x01ul << 0)
#define I2C_STAR1_SB			(0x01ul << 0)

/* STAR2 */
#define I2C_STAR2_PEC_MASK		(0xFFul << 8)
#define I2C_STAR2_PEC_VAL(x)		(((x) >> 8) & I2C_STAR2_PEC_MASK)
#define I2C_STAR2_PEC(x)		((x) << 8)

#define I2C_STAR2_DUALF_MASK		(0x01ul << 7)
#define I2C_STAR2_DUALF			(0x01ul << 7)

#define I2C_STAR2_GENCALL_MASK		(0x01ul << 4)
#define I2C_STAR2_GENCALL		(0x01ul << 4)

#define I2C_STAR2_TRA_MASK		(0x01ul << 2)
#define I2C_STAR2_TRA			(0x01ul << 2)

#define I2C_STAR2_BUSY_MASK		(0x01ul << 1)
#define I2C_STAR2_BUSY			(0x01ul << 1)

#define I2C_STAR2_MSL_MASK		(0x01ul << 0)
#define I2C_STAR2_MSL			(0x01ul << 0)

/* CKCFGR */
#define I2C_CKCFGR_FS_MASK		(0x01ul << 15)
#define I2C_CKCFGR_FS			(0x01ul << 15)

#define I2C_CKCFGR_DUTY_MASK		(0x01ul << 14)
#define I2C_CKCFGR_DUTY			(0x01ul << 14)

#define I2C_CKCFGR_CCR_MASK		(0x0FFFul << 0)
#define I2C_CKCFGR_CCR(x)		((x) << 0)

typedef struct {
	uint16_t CTLR1;			/**< Control 1 */
	uint16_t RESERVED;		/**< RESERVED */
	uint16_t CTLR2;			/**< Control 2 */
	uint16_t RESERVED2;		/**< RESERVED */
	uint16_t OADDR1;		/**< Address 1 */
	uint16_t RESERVED3;		/**< RESERVED */
	uint16_t OADDR2;		/**< Address 2 */
	uint16_t RESERVED4;		/**< RESERVED */
	uint16_t DATAR;			/**< Data */
	uint16_t RESERVED5;		/**< RESERVED */
	uint16_t STAR1;			/**< Status 1 */
	uint16_t RESERVED6;		/**< RESERVED */
	uint16_t STAR2;			/**< Status 2 */
	uint16_t RESERVED7;		/**< RESERVED */
	uint16_t CKCFGR;		/**< Clock */
} per_i2c_t;

extern volatile per_i2c_t *I2C;

#endif /* _PERIPHERAL_I2C_H_ */