/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/pfic.h"

#define __irq 	__attribute__((interrupt))
#define __weak 	__attribute__((weak))

__weak __irq void IRQ_nmi(void)
{
	while(1);
}

__weak __irq void IRQ_hardfault(void)
{
	while(1);
}

__weak __irq void IRQ_systick(void)
{

}

__weak __irq void IRQ_software(void)
{

}

__weak __irq void IRQ_WWDG(void)
{

}

__weak __irq void IRQ_PVD(void)
{

}

__weak __irq void IRQ_FLASH(void)
{

}

__weak __irq void IRQ_RCC(void)
{

}

__weak __irq void IRQ_EXTI(void)
{

}

__weak __irq void IRQ_AWU(void)
{

}

__weak __irq void IRQ_DMA_CH1(void)
{

}

__weak __irq void IRQ_DMA_CH2(void)
{

}

__weak __irq void IRQ_DMA_CH3(void)
{

}

__weak __irq void IRQ_DMA_CH4(void)
{

}

__weak __irq void IRQ_DMA_CH5(void)
{

}

__weak __irq void IRQ_DMA_CH6(void)
{

}

__weak __irq void IRQ_DMA_CH7(void)
{

}

__weak __irq void IRQ_ADC(void)
{

}

__weak __irq void IRQ_I2C_EV(void)
{

}

__weak __irq void IRQ_I2C_ER(void)
{

}

__weak __irq void IRQ_USART(void)
{

}

__weak __irq void IRQ_SPI(void)
{

}

__weak __irq void IRQ_TIM1BRK(void)
{

}

__weak __irq void IRQ_TIM1UP(void)
{

}

__weak __irq void IRQ_TIM1TRG(void)
{

}

__weak __irq void IRQ_TIM1CC(void)
{

}

__weak __irq void IRQ_TIM2(void)
{

}