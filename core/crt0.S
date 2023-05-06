#
# Copyright 2023 Dominik Chat
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

.section .init, "ax", @progbits
.align 2
.global _start
_start:
	.option norvc;

	j	reset_handler
	.word	0
	.word	IRQ_nmi
	.word	IRQ_hardfault
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	IRQ_systick
	.word	0
	.word	IRQ_software
	.word	0
	.word	IRQ_WWDG
	.word	IRQ_PVD
	.word	IRQ_FLASH
	.word	IRQ_RCC
	.word	IRQ_EXTI
	.word	IRQ_AWU
	.word	IRQ_DMA_CH1
	.word	IRQ_DMA_CH2
	.word	IRQ_DMA_CH3
	.word	IRQ_DMA_CH4
	.word	IRQ_DMA_CH5
	.word	IRQ_DMA_CH6
	.word	IRQ_DMA_CH7
	.word	IRQ_ADC
	.word	IRQ_I2C_EV
	.word	IRQ_I2C_ER
	.word	IRQ_USART
	.word	IRQ_SPI
	.word	IRQ_TIM1BRK
	.word	IRQ_TIM1UP
	.word	IRQ_TIM1TRG
	.word	IRQ_TIM1CC
	.word	IRQ_TIM2

	.option rvc;

.section .text.reset_handler, "ax"
reset_handler:
# Load global pointer
	.option push
	.option norelax
	la gp, __global_pointer$
	.option pop

# Set stack pointer
	la sp, _estack

# Copy data flash -> RAM
	la a0, _sdata_flash
	la a1, _sdata_ram
	la a2, _edata
	beq a1, a2, 2f
1:
	lw t0, (a0)
	sw t0, (a1)
	addi a0, a0, 4
	addi a1, a1, 4
	bltu a1, a2, 1b
2:
# Clear bss
	la a0, _sbss
	la s1, _ebss
	beq a0, a1, 2f
1:
	sw zero (a0)
	addi a0, a0, 4
	bltu a0, a1, 1b
2:
# Enable machine mode interrupts
	li t0, 0x80 # MPIE
	csrw mstatus, t0

# Set trap for vector table, with vendor specific mode
	la t0, _start
	ori t0, t0, 3
	csrw mtvec, t0

# Jump to main in user mode
	la t0, main
	csrw mepc, t0
	mret