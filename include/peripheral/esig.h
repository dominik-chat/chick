/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_ESIG_H_
#define _PERIPHERAL_ESIG_H_

#include <stdint.h>

#define ESIG_REG_OFFSET			(0x1FFFF7E0ul)

/* FLACAP */
#define ESIG_FLACAP_MASK		(0xFFFFul << 0)
#define ESIG_FLACAP_MUL			(1024ul)

/* FLACAP */
#define ESIG_FLACAP_MASK		(0xFFFFul << 0)

/* UNIID */
#define ESIG_UNIID_MASK			(0xFFFFFFFFul << 0)

typedef struct {
	uint16_t FLACAP;		/**< Flash capacity (KiB) */
	uint16_t RESERVED[3];		/**< RESERVED */
	uint32_t UNIID1;		/**< UID 1 */
	uint32_t UNIID2;		/**< UID 2 */
	uint32_t UNIID3;		/**< UID 3 */
} per_esig_t;

volatile per_esig_t *ESIG = (volatile per_esig_t *)ESIG_REG_OFFSET;

#endif /* _PERIPHERAL_ESIG_H_ */