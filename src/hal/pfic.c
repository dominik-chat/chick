/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stddef.h>
#include "peripheral/pfic.h"
#include "hal/pfic.h"
#include "hal_internal.h"

HAL_err	PFIC_enable_int(uint8_t vector)
{
	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		BIT_SET(PFIC->IENR1, PFIC_IENR1_INTEN_2_3(vector));
		break;

		case VECT_STK:
		BIT_SET(PFIC->IENR1, PFIC_IENR1_INTEN_12);
		break;

		case VECT_SWI:
		BIT_SET(PFIC->IENR1, PFIC_IENR1_INTEN_14);
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		BIT_SET(PFIC->IENR1, PFIC_IENR1_INTEN_16_31(vector));
		break;

		case VECT_USART ... VECT_TIM2:
		BIT_SET(PFIC->IENR2, PFIC_IENR2_INTEN_32_38(vector));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err	PFIC_disable_int(uint8_t vector)
{
	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		BIT_SET(PFIC->IRER1, PFIC_IRER1_INTRSET_2_3(vector));
		break;

		case VECT_STK:
		BIT_SET(PFIC->IRER1, PFIC_IRER1_INTRSET_12);
		break;

		case VECT_SWI:
		BIT_SET(PFIC->IRER1, PFIC_IRER1_INTRSET_14);
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		BIT_SET(PFIC->IRER1, PFIC_IRER1_INTRSET_16_31(vector));
		break;

		case VECT_USART ... VECT_TIM2:
		BIT_SET(PFIC->IRER2, PFIC_IRER2_INTRSET_32_38(vector));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err PFIC_get_en_int(uint8_t vector, bool *flag)
{
	uint32_t tmp;

	if (!flag) {
		return HAL_EINVAL;
	}

	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		tmp = PFIC->ISR1 & PFIC_ISR1_INTENSTA_2_3(vector);
		break;

		case VECT_STK:
		tmp = PFIC->ISR1 & PFIC_ISR1_INTENSTA_12;
		break;

		case VECT_SWI:
		tmp = PFIC->ISR1 & PFIC_ISR1_INTENSTA_14;
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		tmp = PFIC->ISR1 & PFIC_ISR1_INTENSTA_16_31(vector);
		break;

		case VECT_USART ... VECT_TIM2:
		tmp = PFIC->ISR2 & PFIC_ISR2_INTENSTA_32_38(vector);
		break;

		default:
		return HAL_EINVAL;
	}

	if (tmp != 0) {
		*flag = true;
	}

	return HAL_OK;
}

HAL_err PFIC_set_pend_int(uint8_t vector)
{
	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		BIT_SET(PFIC->IPSR1, PFIC_IPSR1_PENDSET_2_3(vector));
		break;

		case VECT_STK:
		BIT_SET(PFIC->IPSR1, PFIC_IPSR1_PENDSET_12);
		break;

		case VECT_SWI:
		BIT_SET(PFIC->IPSR1, PFIC_IPSR1_PENDSET_14);
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		BIT_SET(PFIC->IPSR1, PFIC_IPSR1_PENDSET_16_31(vector));
		break;

		case VECT_USART ... VECT_TIM2:
		BIT_SET(PFIC->IPSR2, PFIC_IPSR2_PENDSET_32_38(vector));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err PFIC_clear_pend_int(uint8_t vector)
{
	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		BIT_SET(PFIC->IPRR1, PFIC_IPRR1_PENDRESET_2_3(vector));
		break;

		case VECT_STK:
		BIT_SET(PFIC->IPRR1, PFIC_IPRR1_PENDRESET_12);
		break;

		case VECT_SWI:
		BIT_SET(PFIC->IPRR1, PFIC_IPRR1_PENDRESET_14);
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		BIT_SET(PFIC->IPRR1, PFIC_IPRR1_PENDRESET_16_31(vector));
		break;

		case VECT_USART ... VECT_TIM2:
		BIT_SET(PFIC->IPRR2, PFIC_IPRR2_PENDRESET_32_38(vector));
		break;

		default:
		return HAL_EINVAL;
	}

	return HAL_OK;
}

HAL_err PFIC_get_pend_int(uint8_t vector, bool *flag)
{
	uint32_t tmp;

	if (!flag) {
		return HAL_EINVAL;
	}

	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		tmp = PFIC->IPR1 & PFIC_IPR1_PENDSTA_2_3(vector);
		break;

		case VECT_STK:
		tmp = PFIC->IPR1 & PFIC_IPR1_PENDSTA_12;
		break;

		case VECT_SWI:
		tmp = PFIC->IPR1 & PFIC_IPR1_PENDSTA_14;
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		tmp = PFIC->IPR1 & PFIC_IPR1_PENDSTA_16_31(vector);
		break;

		case VECT_USART ... VECT_TIM2:
		tmp = PFIC->IPR2 & PFIC_IPR2_PENDSTA_32_38(vector);
		break;

		default:
		return HAL_EINVAL;
	}

	if (tmp != 0) {
		*flag = true;
	}

	return HAL_OK;
}

HAL_err PFIC_get_exe_int(uint8_t vector, bool *flag)
{
	uint32_t tmp;

	if (!flag) {
		return HAL_EINVAL;
	}

	switch (vector) {
		case VECT_NMI:
		case VECT_EXC:
		tmp = PFIC->IACTR1 & PFIC_IACTR1_IACTS_2_3(vector);
		break;

		case VECT_STK:
		tmp = PFIC->IACTR1 & PFIC_IACTR1_IACTS_12;
		break;

		case VECT_SWI:
		tmp = PFIC->IACTR1 & PFIC_IACTR1_IACTS_14;
		break;

		case VECT_WWDG ... VECT_I2C_ER:
		tmp = PFIC->IACTR1 & PFIC_IACTR1_IACTS_16_31(vector);
		break;

		case VECT_USART ... VECT_TIM2:
		tmp = PFIC->IACTR2 & PFIC_IACTR2_IACTS_32_38(vector);
		break;

		default:
		return HAL_EINVAL;
	}

	if (tmp != 0) {
		*flag = true;
	}

	return HAL_OK;
}

HAL_err PFIC_set_threshold_prio(uint8_t prio)
{
	FIELD_SET(PFIC->ITHRESDR, PFIC_ITHRESDR_THRESHOLD_MASK, PFIC_ITHRESDR_THRESHOLD(prio));
	return HAL_OK;
}

HAL_err PFIC_reset(void)
{
	PFIC->CFGR = (PFIC_CFGR_KEYCODE(0xBEEF) | PFIC_CFGR_RESETSYS);

	/* Should have rebooted by now */
	return HAL_EIO;
}

HAL_err PFIC_get_state(bool *pend, bool *exe, uint8_t *nest_lvl)
{
	uint32_t tmp;

	tmp = PFIC->GISR;

	if (pend) {
		*pend = ((tmp & PFIC_GISR_GPENDSTA_MASK) == PFIC_GISR_GPENDSTA);
	}

	if (exe) {
		*exe = ((tmp & PFIC_GISR_GACTSTA_MASK) == PFIC_GISR_GACTSTA);
	}

	if (nest_lvl) {
		if ((tmp & PFIC_GISR_NESTSTA_MASK) == PFIC_GISR_NESTSTA_1) {
			*nest_lvl = 1;
		} else if ((tmp & PFIC_GISR_NESTSTA_MASK) == PFIC_GISR_NESTSTA_2) {
			*nest_lvl = 2;
		} else {
			*nest_lvl = 0;
		}
	}

	return HAL_OK;
}

HAL_err PFIC_enable_vtf0(uint8_t vector, void *isr)
{
	uint32_t addr;

	addr = (((uint32_t)isr) | PFIC_VTFADDRR0_VTF0EN);

	FIELD_SET(PFIC->VTFIDR, PFIC_VTFIDR_VTFID0_MASK, PFIC_VTFIDR_VTFID0(vector));
	PFIC->VTFADDRR0 = addr;

	return HAL_OK;
}

HAL_err PFIC_disable_vtf0(void)
{
	PFIC->VTFADDRR0 = 0;
	return HAL_OK;
}

HAL_err PFIC_enable_vtf1(uint8_t vector, void *isr)
{
	uint32_t addr;

	addr = (((uint32_t)isr) | PFIC_VTFADDRR1_VTF1EN);

	FIELD_SET(PFIC->VTFIDR, PFIC_VTFIDR_VTFID1_MASK, PFIC_VTFIDR_VTFID1(vector));
	PFIC->VTFADDRR1 = addr;

	return HAL_OK;
}

HAL_err PFIC_disable_vtf1(void)
{
	PFIC->VTFADDRR1 = 0;
	return HAL_OK;
}

HAL_err PFIC_set_prio(uint8_t vector, uint8_t prio)
{
	size_t reg;

	reg = PFIC_IPRIOR_IP_REG(vector);

	FIELD_SET(PFIC->IPRIOR[reg], PFIC_IPRIOR_IP_MASK(vector), PFIC_IPRIOR_IP(vector, prio));
	return HAL_OK;
}

HAL_err PFIC_set_event(void)
{
	BIT_SET(PFIC->SCTLR, PFIC_SCTLR_SETEVENT);
	return HAL_OK;
}

HAL_err PFIC_enable_all_wkup(void)
{
	BIT_SET(PFIC->SCTLR, PFIC_SCTLR_SEVONPEND);
	return HAL_OK;
}

HAL_err PFIC_disable_all_wkup(void)
{
	BIT_CLEAR(PFIC->SCTLR, PFIC_SCTLR_SEVONPEND);
	return HAL_OK;
}

HAL_err PFIC_enable_wfitowfe(void)
{
	BIT_SET(PFIC->SCTLR, PFIC_SCTLR_WFITOWFE);
	return HAL_OK;
}

HAL_err PFIC_disable_wfitowfe(void)
{
	BIT_CLEAR(PFIC->SCTLR, PFIC_SCTLR_WFITOWFE);
	return HAL_OK;
}

HAL_err PFIC_enable_deepsleep(void)
{
	BIT_SET(PFIC->SCTLR, PFIC_SCTLR_SLEEPDEEP);
	return HAL_OK;
}

HAL_err PFIC_disable_deepsleep(void)
{
	BIT_CLEAR(PFIC->SCTLR, PFIC_SCTLR_SLEEPDEEP);
	return HAL_OK;
}

HAL_err PFIC_enable_sleeponexit(void)
{
	BIT_SET(PFIC->SCTLR, PFIC_SCTLR_SLEEPONEXIT);
	return HAL_OK;
}

HAL_err PFIC_disable_sleeponexit(void)
{
	BIT_CLEAR(PFIC->SCTLR, PFIC_SCTLR_SLEEPONEXIT);
	return HAL_OK;
}
