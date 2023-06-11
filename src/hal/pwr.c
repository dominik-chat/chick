/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/pwr.h"
#include "hal/pwr.h"
#include "hal_internal.h"

HAL_err PWR_enable_pvd(pwr_pvd_t threshold)
{
	switch (threshold) {
		case THRESHOLD_285_27:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_285_27);
		break;

		case THRESHOLD_305_29:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_305_29);
		break;

		case THRESHOLD_33_315:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_33_315);
		break;

		case THRESHOLD_35_33:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_35_33);
		break;

		case THRESHOLD_37_35:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_37_35);
		break;

		case THRESHOLD_39_37:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_39_37);
		break;

		case THRESHOLD_41_39:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_41_39);
		break;

		case THRESHOLD_44_42:
		FIELD_SET(PWR->CTRL, PWR_CTRL_PLS_MASK, PWR_CTRL_PLS_44_42);
		break;

		default:
		return HAL_EINVAL;
	}

	BIT_SET(PWR->CTRL, PWR_CTRL_PVDE);

	return HAL_OK;
}

void PWR_disable_pvd(void)
{
	BIT_CLEAR(PWR->CTRL, PWR_CTRL_PVDE);
}

void PWR_set_deepsleep_standby(void)
{
	BIT_SET(PWR->CTRL, PWR_CTRL_PDDS);
}

void PWR_set_deepsleep_sleep(void)
{
	BIT_CLEAR(PWR->CTRL, PWR_CTRL_PDDS);
}

HAL_err PWR_get_pvd_flag(pwr_pvd_flag_t *flag)
{
	if (!flag) {
		return HAL_EINVAL;
	}

	if ((PWR->CTRL & PWR_CTRL_PVDE) == 0) {
		return HAL_EIO;
	}

	if ((PWR->CSR & PWR_CSR_PVD0) != 0) {
		*flag = BELOW_THRESH;
	} else {
		*flag = ABOVE_THRESH;
	}

	return HAL_OK;
}

void PWR_enable_awu(void)
{
	BIT_SET(PWR->AWUCSR, PWR_AWUCSR_AWUEN);
}

void PWR_disable_awu(void)
{
	BIT_CLEAR(PWR->AWUCSR, PWR_AWUCSR_AWUEN);
}

void PWR_set_awu_window_val(uint8_t val)
{
	FIELD_SET(PWR->AWUWR, PWR_AWUWR_MASK, val);
}

HAL_err PWR_set_awu_prescaler(uint16_t prescaler)
{
	switch (prescaler) {
		case 0:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_OFF);
		break;

		case 2:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_2);
		break;

		case 4:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_4);
		break;

		case 8:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_8);
		break;

		case 16:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_16);
		break;

		case 32:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_32);
		break;

		case 64:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_64);
		break;

		case 128:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_128);
		break;

		case 256:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_256);
		break;

		case 512:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_512);
		break;

		case 1024:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_1024);
		break;

		case 2048:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_2048);
		break;

		case 4096:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_4096);
		break;

		case 0x2800:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_10240);
		break;

		case 0xf000:
		FIELD_SET(PWR->AWUPSC, PWR_AWUPSC_MASK, PWR_AWUPSC_61440);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}