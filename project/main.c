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
#include "hal/rcc.h"

int main(void)
{
	RCC_init_clock(CLOCK_HSE);
}