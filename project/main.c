/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

/* This is just a temporary main.c for buildsystem testing */

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

#include "hal/esig.h"
#include "hal/gpio.h"
#include "hal/pfic.h"
#include "hal/rcc.h"
#include "hal/stk.h"

volatile uint32_t time = 0;

__attribute__((interrupt)) void IRQ_systick(void)
{
	time++;
	STK_clear_intflag();
}

void delay(void)
{
	uint32_t tmp;

	tmp = time + 250;

	while (time != tmp);
}

int main(void)
{
	/* Clock init */
	RCC_init_clock(CLOCK_HSE);
	RCC_set_pll_src(CLOCK_HSE);
	RCC_init_clock(CLOCK_PLL);
	FLASH->ACTLR = FLASH_ACTLR_LATENCY_1;
	RCC_set_sysclk_src(CLOCK_PLL);
	RCC_set_ahb_prescaler(1);

	/* GPIO init */
	RCC_enable_peripherial(APB_GPIOD);
	GPIO_init_out(PORT_D, 4, CONF_OUT_PUSHPULL, SPEED_50);
	PFIC_enable_int(VECT_STK);

	/* Systick init */
	STK_set_cnt(0);
	STK_set_prescaler(1);
	STK_enable_autoreload();
	STK_set_cmp(48000);	/* 1ms */
	STK_enable_int();
	STK_enable();

	while(1) {
		delay();
		GPIO_set_pin(PORT_D, 4);
		delay();
		GPIO_clear_pin(PORT_D, 4);
	}
}
