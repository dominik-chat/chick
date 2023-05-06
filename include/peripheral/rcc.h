/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_RCC_H_
#define _PERIPHERAL_RCC_H_

#include <stdint.h>

#define RCC_REG_OFFSET		(0x40021000ul)

/* CTRL */
#define RCC_CTRL_PLLRDY_MASK	(0x01ul << 25)
#define RCC_CTRL_PLLRDY		(0x01ul << 25)

#define RCC_CTRL_PLLON_MASK	(0x01ul << 24)
#define RCC_CTRL_PLLON		(0x01ul << 24)

#define RCC_CTRL_CSSON_MASK	(0x01ul << 19)
#define RCC_CTRL_CSSON		(0x01ul << 19)

#define RCC_CTRL_HSEBYP_MASK	(0x01ul << 18)
#define RCC_CTRL_HSEBYP		(0x01ul << 18)

#define RCC_CTRL_HSERDY_MASK	(0x01ul << 17)
#define RCC_CTRL_HSERDY		(0x01ul << 17)

#define RCC_CTRL_HSEON_MASK	(0x01ul << 16)
#define RCC_CTRL_HSEON		(0x01ul << 16)

#define RCC_CTRL_HSICAL_MASK	(0xFFul << 8)
#define RCC_CTRL_HSICAL_VAL(x)	(((x) & RCC_CTRL_HSICAL_MASK) >> 8)

#define RCC_CTRL_HSITRIM_MASK	(0x1Ful << 3)
#define RCC_CTRL_HSITRIM(x)	((x) << 3)

#define RCC_CTRL_HSIRDY_MASK	(0x01ul << 1)
#define RCC_CTRL_HSIRDY		(0x01ul << 1)

#define RCC_CTRL_HSION_MASK	(0x01ul << 0)
#define RCC_CTRL_HSION		(0x01ul << 0)

/* CFGR */
#define RCC_CFGR_MCO_MASK	(0x07ul << 24)
#define RCC_CFGR_MCO_NOCLOCK	(0x00ul << 24)
#define RCC_CFGR_MCO_SYSCLK	(0x04ul << 24)
#define RCC_CFGR_MCO_HSI	(0x05ul << 24)
#define RCC_CFGR_MCO_HSE	(0x06ul << 24)
#define RCC_CFGR_MCO_PLL	(0x07ul << 24)

#define RCC_CFGR_PLLSRC_MASK	(0x01ul << 16)
#define RCC_CFGR_PLLSRC_HSE	(0x01ul << 16)
#define RCC_CFGR_PLLSRC_HSI	(0x00ul << 16)

#define RCC_CFGR_ADCPRE_MASK	(0x1Ful << 11)
#define RCC_CFGR_ADCPRE_2	(0x00ul << 11)
#define RCC_CFGR_ADCPRE_4	(0x08ul << 11)
#define RCC_CFGR_ADCPRE_6	(0x10ul << 11)
#define RCC_CFGR_ADCPRE_8	(0x18ul << 11)
#define RCC_CFGR_ADCPRE_12	(0x14ul << 11)
#define RCC_CFGR_ADCPRE_16	(0x1Cul << 11)
#define RCC_CFGR_ADCPRE_24	(0x15ul << 11)
#define RCC_CFGR_ADCPRE_32	(0x1Dul << 11)
#define RCC_CFGR_ADCPRE_48	(0x16ul << 11)
#define RCC_CFGR_ADCPRE_64	(0x1Eul << 11)
#define RCC_CFGR_ADCPRE_96	(0x17ul << 11)
#define RCC_CFGR_ADCPRE_128	(0x1Ful << 11)

#define RCC_CFGR_HPRE_MASK	(0x0Ful << 4)
#define RCC_CFGR_HPRE_OFF	(0x00ul << 4)
#define RCC_CFGR_HPRE_2		(0x01ul << 4)
#define RCC_CFGR_HPRE_3		(0x02ul << 4)
#define RCC_CFGR_HPRE_4		(0x03ul << 4)
#define RCC_CFGR_HPRE_5		(0x04ul << 4)
#define RCC_CFGR_HPRE_6		(0x05ul << 4)
#define RCC_CFGR_HPRE_7		(0x06ul << 4)
#define RCC_CFGR_HPRE_8		(0x07ul << 4)
#define RCC_CFGR_HPRE_16	(0x0Bul << 4)
#define RCC_CFGR_HPRE_32	(0x0Cul << 4)
#define RCC_CFGR_HPRE_64	(0x0Dul << 4)
#define RCC_CFGR_HPRE_128	(0x0Eul << 4)
#define RCC_CFGR_HPRE_256	(0x0Ful << 4)

#define RCC_CFGR_SWS_MASK	(0x03ul << 2)
#define RCC_CFGR_SWS_HSI	(0x00ul << 2)
#define RCC_CFGR_SWS_HSE	(0x01ul << 2)
#define RCC_CFGR_SWS_PLL	(0x02ul << 2)

#define RCC_CFGR_SW_MASK	(0x03ul << 0)
#define RCC_CFGR_SW_HSI		(0x00ul << 0)
#define RCC_CFGR_SW_HSE		(0x01ul << 0)
#define RCC_CFGR_SW_PLL		(0x02ul << 0)

/* INTR */
#define RCC_INTR_CSSC_MASK	(0x01ul << 23)
#define RCC_INTR_CSSC		(0x01ul << 23)

#define RCC_INTR_PLLRDYC_MASK	(0x01ul << 20)
#define RCC_INTR_PLLRDYC	(0x01ul << 20)

#define RCC_INTR_HSERDYC_MASK	(0x01ul << 19)
#define RCC_INTR_HSERDYC	(0x01ul << 19)

#define RCC_INTR_HSIRDYC_MASK	(0x01ul << 18)
#define RCC_INTR_HSIRDYC	(0x01ul << 18)

#define RCC_INTR_LSIRDYC_MASK	(0x01ul << 16)
#define RCC_INTR_LSIRDYC	(0x01ul << 16)

#define RCC_INTR_PLLRDYIE_MASK	(0x01ul << 12)
#define RCC_INTR_PLLRDYIE	(0x01ul << 12)

#define RCC_INTR_HSERDYIE_MASK	(0x01ul << 11)
#define RCC_INTR_HSERDYIE	(0x01ul << 11)

#define RCC_INTR_HSIRDYIE_MASK	(0x01ul << 10)
#define RCC_INTR_HSIRDYIE	(0x01ul << 10)

#define RCC_INTR_LSIRDYIE_MASK	(0x01ul << 8)
#define RCC_INTR_LSIRDYIE	(0x01ul << 8)

#define RCC_INTR_CSSF_MASK	(0x01ul << 7)
#define RCC_INTR_CSSF		(0x01ul << 7)

#define RCC_INTR_PLLRDYF_MASK	(0x01ul << 4)
#define RCC_INTR_PLLRDYF	(0x01ul << 4)

#define RCC_INTR_HSERDYF_MASK	(0x01ul << 3)
#define RCC_INTR_HSERDYF	(0x01ul << 3)

#define RCC_INTR_HSIRDYF_MASK	(0x01ul << 2)
#define RCC_INTR_HSIRDYF	(0x01ul << 2)

#define RCC_INTR_LSIRDYF_MASK	(0x01ul << 0)
#define RCC_INTR_LSIRDYF	(0x01ul << 0)

/* APB2PRSTR */
#define RCC_APB2PRSTR_USART1RST_MASK	(0x01ul << 14)
#define RCC_APB2PRSTR_USART1RST		(0x01ul << 14)

#define RCC_APB2PRSTR_SPI1RST_MASK	(0x01ul << 12)
#define RCC_APB2PRSTR_SPI1RST		(0x01ul << 12)

#define RCC_APB2PRSTR_TIM1RST_MASK	(0x01ul << 11)
#define RCC_APB2PRSTR_TIM1RST		(0x01ul << 11)

#define RCC_APB2PRSTR_ADC1RST_MASK	(0x01ul << 9)
#define RCC_APB2PRSTR_ADC1RST		(0x01ul << 9)

#define RCC_APB2PRSTR_IOPDRST_MASK	(0x01ul << 5)
#define RCC_APB2PRSTR_IOPDRST		(0x01ul << 5)

#define RCC_APB2PRSTR_IOPCRST_MASK	(0x01ul << 4)
#define RCC_APB2PRSTR_IOPCRST		(0x01ul << 4)

#define RCC_APB2PRSTR_IOPARST_MASK	(0x01ul << 2)
#define RCC_APB2PRSTR_IOPARST		(0x01ul << 2)

#define RCC_APB2PRSTR_AFIORST_MASK	(0x01ul << 0)
#define RCC_APB2PRSTR_AFIORST		(0x01ul << 0)

/* APB1PRSTR */
#define RCC_APB1PRSTR_PWRRST_MASK	(0x01ul << 28)
#define RCC_APB1PRSTR_PWRRST		(0x01ul << 28)

#define RCC_APB1PRSTR_I2C1RST_MASK	(0x01ul << 21)
#define RCC_APB1PRSTR_I2C1RST		(0x01ul << 21)

#define RCC_APB1PRSTR_WWDGRST_MASK	(0x01ul << 11)
#define RCC_APB1PRSTR_WWDGRST		(0x01ul << 11)

#define RCC_APB1PRSTR_TIM2RST_MASK	(0x01ul << 0)
#define RCC_APB1PRSTR_TIM2RST		(0x01ul << 0)

/* AHBPCENR */
#define RCC_AHBPCENR_SRAMEN_MASK	(0x01ul << 2)
#define RCC_AHBPCENR_SRAMEN		(0x01ul << 2)

#define RCC_AHBPCENR_DMA1EN_MASK	(0x01ul << 0)
#define RCC_AHBPCENR_DMA1EN		(0x01ul << 0)

/* APB2PCENR */
#define RCC_APB2PCENR_USART1EN_MASK	(0x01ul << 14)
#define RCC_APB2PCENR_USART1EN		(0x01ul << 14)

#define RCC_APB2PCENR_SPI1EN_MASK	(0x01ul << 12)
#define RCC_APB2PCENR_SPI1EN		(0x01ul << 12)

#define RCC_APB2PCENR_TIM1EN_MASK	(0x01ul << 11)
#define RCC_APB2PCENR_TIM1EN		(0x01ul << 11)

#define RCC_APB2PCENR_ADC1EN_MASK	(0x01ul << 9)
#define RCC_APB2PCENR_ADC1EN		(0x01ul << 9)

#define RCC_APB2PCENR_IOPDEN_MASK	(0x01ul << 5)
#define RCC_APB2PCENR_IOPDEN		(0x01ul << 5)

#define RCC_APB2PCENR_IOPCEN_MASK	(0x01ul << 4)
#define RCC_APB2PCENR_IOPCEN		(0x01ul << 4)

#define RCC_APB2PCENR_IOPAEN_MASK	(0x01ul << 2)
#define RCC_APB2PCENR_IOPAEN		(0x01ul << 2)

#define RCC_APB2PCENR_AFIOEN_MASK	(0x01ul << 0)
#define RCC_APB2PCENR_AFIOEN		(0x01ul << 0)

/* APB1PCENR */
#define RCC_APB1PCENR_PWREN_MASK	(0x01ul << 28)
#define RCC_APB1PCENR_PWREN		(0x01ul << 28)

#define RCC_APB1PCENR_I2C1EN_MASK	(0x01ul << 21)
#define RCC_APB1PCENR_I2C1EN		(0x01ul << 21)

#define RCC_APB1PCENR_WWDGEN_MASK	(0x01ul << 11)
#define RCC_APB1PCENR_WWDGEN		(0x01ul << 11)

#define RCC_APB1PCENR_TIM2EN_MASK	(0x01ul << 0)
#define RCC_APB1PCENR_TIM2EN		(0x01ul << 0)

/* RSTSCKR */
#define RCC_RSTSCKR_LPWRRSTF_MASK	(0x01ul << 31)
#define RCC_RSTSCKR_LPWRRSTF		(0x01ul << 31)

#define RCC_RSTSCKR_WWDGRSTF_MASK	(0x01ul << 30)
#define RCC_RSTSCKR_WWDGRSTF		(0x01ul << 30)

#define RCC_RSTSCKR_IWDGRSTF_MASK	(0x01ul << 29)
#define RCC_RSTSCKR_IWDGRSTF		(0x01ul << 29)

#define RCC_RSTSCKR_SFTRSTF_MASK	(0x01ul << 28)
#define RCC_RSTSCKR_SFTRSTF		(0x01ul << 28)

#define RCC_RSTSCKR_PORRSTF_MASK	(0x01ul << 27)
#define RCC_RSTSCKR_PORRSTF		(0x01ul << 27)

#define RCC_RSTSCKR_PINRSTF_MASK	(0x01ul << 26)
#define RCC_RSTSCKR_PINRSTF		(0x01ul << 26)

#define RCC_RSTSCKR_RMVF_MASK		(0x01ul << 24)
#define RCC_RSTSCKR_RMVF		(0x01ul << 24)

#define RCC_RSTSCKR_LSIRDY_MASK		(0x01ul << 1)
#define RCC_RSTSCKR_LSIRDY		(0x01ul << 1)

#define RCC_RSTSCKR_LSION_MASK		(0x01ul << 0)
#define RCC_RSTSCKR_LSION		(0x01ul << 0)

typedef struct {
	uint32_t CTRL;		/**< Control */
	uint32_t CFGR;		/**< Configuration */
	uint32_t INTR;		/**< Interrupt */
	uint32_t APB2PRSTR;	/**< APB2 peripheral reset */
	uint32_t APB1PRSTR;	/**< APB1 peripheral reset */
	uint32_t AHBPCENR;	/**< AHB peripheral clock enable */
	uint32_t APB2PCENR;	/**< APB2 peripheral clock enable */
	uint32_t APB1PCENR;	/**< APB1 peripheral clock enable */
	uint32_t RESERVED;	/**< RESERVED */
	uint32_t RSTSCKR;	/**< Control/status */
} per_rcc_t;

volatile per_rcc_t *RCC = (volatile per_rcc_t *)RCC_REG_OFFSET;

#endif /* _PERIPHERAL_RCC_H_ */