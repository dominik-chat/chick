/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/adc.h"
#include "peripheral/adtm.h"
#include "peripheral/afio.h"
#include "peripheral/dma.h"
#include "peripheral/esig.h"
#include "peripheral/exten.h"
#include "peripheral/exti.h"
#include "peripheral/flash.h"
#include "peripheral/gpio.h"
#include "peripheral/gptm.h"
#include "peripheral/i2c.h"
#include "peripheral/iwdg.h"
#include "peripheral/pfic.h"
#include "peripheral/pwr.h"
#include "peripheral/rcc.h"
#include "peripheral/spi.h"
#include "peripheral/stk.h"
#include "peripheral/usart.h"
#include "peripheral/user_words.h"
#include "peripheral/wwdg.h"

volatile per_adc_t *ADC = (volatile per_adc_t *)ADC_REG_OFFSET;
volatile per_adtm_t *ADTM = (volatile per_adtm_t *)ADTM_REG_OFFSET;
volatile per_afio_t *AFIO = (volatile per_afio_t *)AFIO_REG_OFFSET;
volatile per_dma_t *DMA = (volatile per_dma_t *)DMA_REG_OFFSET;
volatile per_esig_t *ESIG = (volatile per_esig_t *)ESIG_REG_OFFSET;
volatile per_exten_t *EXTEN = (volatile per_exten_t *)EXTEN_REG_OFFSET;
volatile per_exti_t *EXTI = (volatile per_exti_t *)EXTI_REG_OFFSET;
volatile per_flash_t *FLASH = (volatile per_flash_t *)FLASH_REG_OFFSET;
volatile per_gpio_t *GPIO_A = (volatile per_gpio_t *)GPIO_A_REG_OFFSET;
volatile per_gpio_t *GPIO_C = (volatile per_gpio_t *)GPIO_C_REG_OFFSET;
volatile per_gpio_t *GPIO_D = (volatile per_gpio_t *)GPIO_D_REG_OFFSET;
volatile per_gptm_t *GPTM = (volatile per_gptm_t *)GPTM_REG_OFFSET;
volatile per_i2c_t *I2C = (volatile per_i2c_t *)I2C_REG_OFFSET;
volatile per_iwdg_t *IWDG = (volatile per_iwdg_t *)IWDG_REG_OFFSET;
volatile per_pfic_t *PFIC = (volatile per_pfic_t *)PFIC_REG_OFFSET;
volatile per_pwr_t *PWR = (volatile per_pwr_t *)PWR_REG_OFFSET;
volatile per_rcc_t *RCC = (volatile per_rcc_t *)RCC_REG_OFFSET;
volatile per_spi_t *SPI = (volatile per_spi_t *)SPI_REG_OFFSET;
volatile per_stk_t *STK = (volatile per_stk_t *)STK_REG_OFFSET;
volatile per_usart_t *USART = (volatile per_usart_t *)USART_REG_OFFSET;
volatile per_userw_t *USERW = (volatile per_userw_t *)USER_WORDS_REG_OFFSET;
volatile per_wwdg_t *WWDG = (volatile per_wwdg_t *)WWDG_REG_OFFSET;
