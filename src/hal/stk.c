/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/stk.h"
#include "hal/stk.h"
#include "hal_internal.h"

HAL_err STK_enable_swi(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_SWIE);
	return HAL_OK;
}

HAL_err STK_disable_swi(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_SWIE);
	return HAL_OK;
}

HAL_err STK_enable_autoreload(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STRE);
	return HAL_OK;
}

HAL_err STK_disable_autoreload(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STRE);
	return HAL_OK;
}

HAL_err STK_set_prescaler(uint8_t prescaler)
{
	switch (prescaler) {
		case 1:
		BIT_SET(STK->CTLR, STK_CTLR_STCLK);
		break;

		case 8:
		BIT_CLEAR(STK->CTLR, STK_CTLR_STCLK);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err STK_enable_int(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STIE);
	return HAL_OK;
}

HAL_err STK_disable_int(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STIE);
	return HAL_OK;
}

HAL_err STK_enable(void)
{
	BIT_SET(STK->CTLR, STK_CTLR_STE);
	return HAL_OK;
}

HAL_err STK_disable(void)
{
	BIT_CLEAR(STK->CTLR, STK_CTLR_STE);
	return HAL_OK;
}

HAL_err STK_get_intflag(bool *flag)
{
	if (!flag) {
		return HAL_EINVAL;
	}

	*flag = ((STK->SR & STK_SR_CNTIF_MASK) == STK_SR_CNTIF);

	return HAL_OK;
}

HAL_err STK_clear_intflag(void)
{
	BIT_CLEAR(STK->SR, STK_SR_CNTIF);
	return HAL_OK;
}

HAL_err STK_get_cnt(uint32_t *cnt)
{
	if (!cnt) {
		return HAL_EINVAL;
	}

	*cnt = STK->CNTL;

	return HAL_OK;
}

HAL_err STK_set_cnt(uint32_t cnt)
{
	STK->CNTL = cnt;
	return HAL_OK;
}

HAL_err STK_get_cmp(uint32_t *cmp)
{
	if (!cmp) {
		return HAL_EINVAL;
	}

	*cmp = STK->CMPLR;

	return HAL_OK;
}

HAL_err STK_set_cmp(uint32_t cmp)
{
	STK->CMPLR = cmp;
	return HAL_OK;
}
