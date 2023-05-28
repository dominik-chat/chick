/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/stk.h"
#include "hal/stk.h"
#include "hal_internal.h"

void STK_enable_swi(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_SWIE);
}

void STK_disable_swi(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_SWIE);
}

void STK_enable_autoreload(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STRE);
}

void STK_disable_autoreload(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STRE);
}

HAL_err STK_set_prescaler(stk_pre_t prescaler)
{
	switch (prescaler) {
		case STK_PRE_1:
		BIT_SET(STK->CTLR, STK_CTLR_STCLK);
		break;

		case STK_PRE_8:
		BIT_CLEAR(STK->CTLR, STK_CTLR_STCLK);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

void STK_enable_int(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STIE);
}

void STK_disable_int(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STIE);
}

void STK_enable(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STE);
}

void STK_disable(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STE);
}

bool STK_get_intflag(void)
{
	return ((STK->SR & STK_SR_CNTIF_MASK) == STK_SR_CNTIF);
}

void STK_clear_intflag(void)
{
	BIT_CLEAR(STK->SR, STK_SR_CNTIF);
}

uint32_t STK_get_cnt(void)
{
	return STK->CNTL;;
}

void STK_set_cnt(uint32_t cnt)
{
	STK->CNTL = cnt;
}

uint32_t STK_get_cmp(void)
{
	return STK->CMPLR;
}

void STK_set_cmp(uint32_t cmp)
{
	STK->CMPLR = cmp;
}
