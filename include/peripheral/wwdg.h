/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_WWDG_H_
#define _PERIPHERAL_WWDG_H_

#include <stdint.h>

#define WWDG_REG_OFFSET		(0x40002C00ul)

/* CTRL */
#define WWDG_CTRL_WDGA_MASK	(0x01ul << 7)
#define WWDG_CTRL_WDGA		(0x01ul << 7)

#define WWDG_CTRL_T_MASK	(0x7Ful << 0)

/* CFGR */
#define WWDG_CFGR_EWI_MASK	(0x01ul << 9)
#define WWDG_CFGR_EWI		(0x01ul << 9)

#define WWDG_CFGR_WDGTB_MASK	(0x03ul << 7)
#define WWDG_CFGR_WDGTB_1	(0x00ul << 7)
#define WWDG_CFGR_WDGTB_2	(0x01ul << 7)
#define WWDG_CFGR_WDGTB_4	(0x02ul << 7)
#define WWDG_CFGR_WDGTB_8	(0x03ul << 7)

#define WWDG_CFGR_W_MASK	(0x7Ful << 0)

/* STATR */
#define WWDG_STATR_EWIF_MASK	(0x01ul << 0)
#define WWDG_STATR_EWIF		(0x01ul << 0)

typedef struct {
	uint16_t CTRL;		/**< Control */
	uint16_t PADDING;
	uint16_t CFGR;		/**< Configuration */
	uint16_t PADDING2;
	uint16_t STATR;		/**< Status */
} per_wwdg_t;

extern volatile per_wwdg_t *WWDG;

#endif /* _PERIPHERAL_WWDG_H_ */