/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_AFIO_H_
#define _PERIPHERAL_AFIO_H_

#include <stdint.h>

#define AFIO_REG_OFFSET			(0x40010000ul)

/* PCFR1 */
#define AFIO_PCFR1_SWCFG_MASK		(0x07ul << 24)
#define AFIO_PCFR1_SWCFG_SWD		(0x00ul << 24)
#define AFIO_PCFR1_SWCFG_GPIO		(0x04ul << 24)

#define AFIO_PCFR1_TIM1_IREMAP_MASK	(0x01ul << 23)
#define AFIO_PCFR1_TIM1_IREMAP_EXT	(0x00ul << 23)
#define AFIO_PCFR1_TIM1_IREMAP_LSI	(0x01ul << 23)

#define AFIO_PCFR1_I2C1_REMAP_MASK	((0x01ul << 22) | (0x01ul << 1))
#define AFIO_PCFR1_I2C1_REMAP_DEF	((0x00ul << 22) | (0x00ul << 1))
#define AFIO_PCFR1_I2C1_REMAP_PD10	((0x00ul << 22) | (0x01ul << 1))
#define AFIO_PCFR1_I2C1_REMAP_PC56	((0x01ul << 22) | (0x00ul << 1))

#define AFIO_PCFR1_USART1_REMAP_MASK	((0x01ul << 21) | (0x01ul << 2))
#define AFIO_PCFR1_USART1_REMAP_DEF	((0x00ul << 21) | (0x00ul << 2))
#define AFIO_PCFR1_USART1_REMAP_PD01	((0x00ul << 21) | (0x01ul << 2))
#define AFIO_PCFR1_USART1_REMAP_PD65	((0x01ul << 21) | (0x00ul << 2))
#define AFIO_PCFR1_USART1_REMAP_PC01	((0x01ul << 21) | (0x01ul << 2))

#define AFIO_PCFR1_ADC_ETRGREG_RM_MASK	(0x01ul << 18)
#define AFIO_PCFR1_ADC_ETRGREG_RM_PD3	(0x00ul << 18)
#define AFIO_PCFR1_ADC_ETRGREG_RM_PC2	(0x01ul << 18)
/* Something is wrong here in docs */
#define AFIO_PCFR1_ADC_ETRGINJ_RM_MASK	(0x01ul << 17)
#define AFIO_PCFR1_ADC_ETRGINJ_RM_PD3	(0x00ul << 17)
#define AFIO_PCFR1_ADC_ETRGINJ_RM_PC2	(0x01ul << 17)

#define AFIO_PCFR1_ADC_PA12_RM_MASK	(0x01ul << 15)
#define AFIO_PCFR1_ADC_PA12_RM_GPIO	(0x00ul << 15)
#define AFIO_PCFR1_ADC_PA12_RM_XTAL	(0x01ul << 15)

#define AFIO_PCFR1_TIM2RM_MASK		(0x03ul << 8)
#define AFIO_PCFR1_TIM2RM_DEF		(0x00ul << 8)
#define AFIO_PCFR1_TIM2RM_C5C2D2C1	(0x01ul << 8)
#define AFIO_PCFR1_TIM2RM_C1D3C0D7	(0x02ul << 8)
#define AFIO_PCFR1_TIM2RM_C1C7D6D5	(0x03ul << 8)

#define AFIO_PCFR1_TIM1RM_MASK		(0x03ul << 6)
#define AFIO_PCFR1_TIM1RM_DEF		(0x00ul << 6)
#define AFIO_PCFR1_TIM1RM_C6C7C0D3	(0x01ul << 6)
#define AFIO_PCFR1_TIM1RM_D2A1C3C4	(0x02ul << 6)
#define AFIO_PCFR1_TIM1RM_C4C7C5D4	(0x03ul << 6)

#define AFIO_PCFR1_SPI1_REMAP_MASK	(0x01ul << 0)
#define AFIO_PCFR1_SPI1_REMAP_DEF	(0x00ul << 0)
#define AFIO_PCFR1_SPI1_REMAP_REM	(0x01ul << 0)

/* EXTICR */
#define AFIO_EXTICR_EXTI_MASK(x)	(0x03ul << ((x) * 2))
#define AFIO_EXTICR_EXTI_PA(x)		(0x00ul << ((x) * 2))
#define AFIO_EXTICR_EXTI_PC(x)		(0x02ul << ((x) * 2))
#define AFIO_EXTICR_EXTI_PD(x)		(0x03ul << ((x) * 2))

typedef struct {
	uint32_t RESERVED;		/**< RESERVED */
	uint32_t PCFR1;			/**< Port input data */
	uint32_t EXTICR;		/**< Port output data */
} per_afio_t;

extern volatile per_afio_t *AFIO;

#endif /* _PERIPHERAL_AFIO_H_ */