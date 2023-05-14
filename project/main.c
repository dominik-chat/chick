/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

/* This is just a temporary main.c for buildsystem testing */

#include "peripheral/adc.h"
#include "peripheral/afio.h"
#include "peripheral/dma.h"
#include "peripheral/esig.h"
#include "peripheral/exten.h"
#include "peripheral/exti.h"
#include "peripheral/flash.h"
#include "peripheral/gpio.h"
#include "peripheral/iwdg.h"
#include "peripheral/pfic.h"
#include "peripheral/pwr.h"
#include "peripheral/rcc.h"
#include "peripheral/stk.h"
#include "peripheral/usart.h"
#include "peripheral/user_words.h"
#include "peripheral/wwdg.h"

#include "hal/esig.h"
#include "hal/gpio.h"
#include "hal/rcc.h"

void delay(void)
{
	volatile uint32_t i;

	for (i = 0; i < 400000ul; i++) {

	}
}

int main(void)
{
	RCC_init_clock(CLOCK_HSE);
	RCC_set_pll_src(CLOCK_HSE);
	RCC_init_clock(CLOCK_PLL);
	FLASH->ACTLR = FLASH_ACTLR_LATENCY_1;
	RCC_set_sysclk_src(CLOCK_PLL);

	RCC_enable_peripherial(APB_GPIOD);

	GPIO_init_out(PORT_D, 4, CONF_OUT_PUSHPULL, SPEED_10);

	while(1) {
		delay();
		GPIO_set_pin(PORT_D, 4);
		delay();
		GPIO_clear_pin(PORT_D, 4);
	}
}
