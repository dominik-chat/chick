/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

ENTRY(_start)

__stack_size = 512;

MEMORY
{
	FLASH(rx)	: ORIGIN = 0x00000000, LENGTH = 1920
	FLASH(rwx)	: ORIGIN = 0x20000000, LENGTH = 2K
}

SECTIONS
{
	.init : 
	{
		KEEP(*(SORT_NONE(.init)))
	} >FLASH

	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4)
		PROVIDE(_sdata_flash = .);
	} >FLASH

	.data :
	{
		. = ALIGN(4);
		PROVIDE(_sdata_ram = .);
		PROVIDE(__global_pointer$ = .);
		*(.data .data.*)
		*(.rodata .rodata.*)
		. = ALIGN(4)
		PROVIDE(edata_ram = .);
	} >RAM AT>FLASH

	.bss (NOLOAD) :
	{
		. = ALIGN(4)
		PROVIDE(_sbss = .);
		*(.bss*)
		*(COMMON*)
		. = ALIGN(4)
		PROVIDE(ebss = .);
	} >RAM

	.stack : ORIGIN(RAM) + LENGTH(RAM) - __stack_size :
	{
		. = . + __stack_size;
		PROVIDE(_estack = .);
	} >RAM
}
