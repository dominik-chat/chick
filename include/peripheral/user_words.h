/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_USERW_H_
#define _PERIPHERAL_USERW_H_

#include <stdint.h>

#define USER_WORDS_REG_OFFSET		(0x1FFFF800ul)

/* RDPR */
#define USERW_RDPR_MASK			(0xFFul << 0)
#define USERW_RDPR_PROT			(0xFFul << 0)
#define USERW_RDPR_NOT_PROT		(0xA5ul << 0)

/* USER */
#define USERW_USER_RST_MODE_MASK	(0x03ul << 3)
#define USERW_USER_RST_MODE_128u	(0x00ul << 3)
#define USERW_USER_RST_MODE_1m		(0x01ul << 3)
#define USERW_USER_RST_MODE_12m		(0x02ul << 3)
#define USERW_USER_RST_MODE_off		(0x03ul << 3)

#define USERW_USER_STANDBY_RST_MASK	(0x01ul << 2)
#define USERW_USER_STANDBY_RST		(0x01ul << 2)

#define USERW_USER_IWDG_SW_MASK		(0x01ul << 0)
#define USERW_USER_IWDG_SW		(0x01ul << 0)

/* WRPR */ /* FIXME: The doc is not very clear here */
#define USERW_WRPR0_MASK(x)		(0x01ul << (x))
#define USERW_WRPR0(x)			(0x01ul << (x))

#define USERW_WRPR1_MASK(x)		(0x01ul << ((x) - 8))
#define USERW_WRPR1(x)			(0x01ul << ((x) - 8))

#define USERW_WRPR2_MASK(x)		(0x01ul << ((x) - 16))
#define USERW_WRPR2(x)			(0x01ul << ((x) - 16))

#define USERW_WRPR3_MASK(x)		(0x01ul << ((x) - 24))
#define USERW_WRPR3(x)			(0x01ul << ((x) - 24))

typedef struct {
	uint8_t RDPR;			/**< Read protection control */
	uint8_t nRDPR;
	uint8_t USER;			/**< User configuration */
	uint8_t nUSER;
	uint8_t DATA0;			/**< User data byte 0 */
	uint8_t nDATA0;
	uint8_t DATA1;			/**< User data byte 1 */
	uint8_t nDATA1;
	uint8_t WRPR0;			/**< Write-protect control bits 0 */
	uint8_t nWRPR0;
	uint8_t WRPR1;			/**< Write-protect control bits 1 */
	uint8_t nWRPR1;
	uint8_t WRPR2;			/**< Write-protect control bits 2 */
	uint8_t nWRPR2;
	uint8_t WRPR3;			/**< Write-protect control bits 3 */
	uint8_t nWRPR3;
} per_userbw_t;

volatile per_userw_t *USERW = (volatile per_userw_t *)USER_WORDS_REG_OFFSET;

#endif /* _PERIPHERAL_USERW_H_ */