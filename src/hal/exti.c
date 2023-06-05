/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "peripheral/exti.h"
#include "hal/exti.h"
#include "hal_internal.h"

HAL_err EXTI_enable_int(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->INTENR, EXTI_INTENR_MR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_disable_int(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_CLEAR(EXTI->INTENR, EXTI_INTENR_MR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_enable_event(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->EVENR, EXTI_EVENR_MR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_disable_event(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_CLEAR(EXTI->EVENR, EXTI_EVENR_MR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_enable_rising(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->RTENR, EXTI_RTENR_TR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_disable_rising(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_CLEAR(EXTI->RTENR, EXTI_RTENR_TR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_enable_falling(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->FTENR, EXTI_FTENR_TR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_disable_falling(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_CLEAR(EXTI->FTENR, EXTI_FTENR_TR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_enable_soft_int(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->SWIEVR, EXTI_SWIEVR_SWIEVR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_disable_soft_int(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_CLEAR(EXTI->SWIEVR, EXTI_SWIEVR_SWIEVR(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_get_intflag(hal_chan_t channel, bool *flag)
{
	if (!flag) {
		return HAL_EINVAL;
	}

	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		*flag = ((EXTI->INTFR & EXTI_INTFR_IF(channel)) != 0);
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err EXTI_clear_intflag(hal_chan_t channel)
{
	switch (channel) {
		case CHAN_0 ... CHAN_AWUP:
		BIT_SET(EXTI->INTFR, EXTI_INTFR_IF(channel));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}
