/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_GPTM_H_
#define _PERIPHERAL_GPTM_H_

#include <stdint.h>

#define GPTM_REG_OFFSET			(0x40000000ul)

/* CTLR1 */
#define GPTM_CTLR1_CAPLVL_MASK		(0x01ul << 15)
#define GPTM_CTLR1_CAPLVL		(0x01ul << 15)

#define GPTM_CTLR1_CAPOV_MASK		(0x01ul << 14)
#define GPTM_CTLR1_CAPOV		(0x01ul << 14)

#define GPTM_CTLR1_CKD_MASK		(0x03ul << 8)
#define GPTM_CTLR1_CKD_1x		(0x00ul << 8)
#define GPTM_CTLR1_CKD_2x		(0x01ul << 8)
#define GPTM_CTLR1_CKD_4x		(0x02ul << 8)

#define GPTM_CTLR1_ARPE_MASK		(0x01ul << 7)
#define GPTM_CTLR1_ARPE			(0x01ul << 7)

#define GPTM_CTLR1_CMS_MASK		(0x03ul << 5)
#define GPTM_CTLR1_CMS_EDGE		(0x00ul << 5)
#define GPTM_CTLR1_CMS_CEN1		(0x01ul << 5)
#define GPTM_CTLR1_CMS_CEN2		(0x02ul << 5)
#define GPTM_CTLR1_CMS_CEN3		(0x03ul << 5)

#define GPTM_CTLR1_DIR_MASK		(0x01ul << 4)
#define GPTM_CTLR1_DIR			(0x01ul << 4)

#define GPTM_CTLR1_OPM_MASK		(0x01ul << 3)
#define GPTM_CTLR1_OPM			(0x01ul << 3)

#define GPTM_CTLR1_URS_MASK		(0x01ul << 2)
#define GPTM_CTLR1_URS			(0x01ul << 2)

#define GPTM_CTLR1_UDIS_MASK		(0x01ul << 1)
#define GPTM_CTLR1_UDIS			(0x01ul << 1)

#define GPTM_CTLR1_CEN_MASK		(0x01ul << 0)
#define GPTM_CTLR1_CEN			(0x01ul << 0)

/* CTLR2 */
#define GPTM_CTLR2_TI1S_MASK		(0x01ul << 7)
#define GPTM_CTLR2_TI1S			(0x01ul << 7)

#define GPTM_CTLR2_MMS_MASK		(0x07ul << 4)
#define GPTM_CTLR2_MMS_UG		(0x00ul << 4)
#define GPTM_CTLR2_CNT_EN		(0x01ul << 4)
#define GPTM_CTLR2_MMS_UPDATE		(0x02ul << 4)
#define GPTM_CTLR2_MMS_CC1IF		(0x03ul << 4)
#define GPTM_CTLR2_MMS_OC1REF		(0x04ul << 4)
#define GPTM_CTLR2_MMS_OC2REF		(0x05ul << 4)
#define GPTM_CTLR2_MMS_OC3REF		(0x06ul << 4)
#define GPTM_CTLR2_MMS_OC4REF		(0x07ul << 4)

#define GPTM_CTLR2_CCDS_MASK		(0x01ul << 3)
#define GPTM_CTLR2_CCDS			(0x01ul << 3)

/* SMCFGR */
#define GPTM_SMCFGR_ETP_MASK		(0x01ul << 15)
#define GPTM_SMCFGR_ETP			(0x01ul << 15)

#define GPTM_SMCFGR_ECE_MASK		(0x01ul << 15)
#define GPTM_SMCFGR_ECE			(0x01ul << 15)

#define GPTM_SMCFGR_ETPS_MASK		(0x03ul << 12)
#define GPTM_SMCFGR_ETPS_1		(0x00ul << 12)
#define GPTM_SMCFGR_ETPS_2		(0x01ul << 12)
#define GPTM_SMCFGR_ETPS_4		(0x02ul << 12)
#define GPTM_SMCFGR_ETPS_8		(0x03ul << 12)

#define GPTM_SMCFGR_ETF_MASK		(0x0Ful << 8)
#define GPTM_SMCFGR_ETF_FCK_N2		(0x01ul << 8)
#define GPTM_SMCFGR_ETF_FCK_N4		(0x02ul << 8)
#define GPTM_SMCFGR_ETF_FCK_N8		(0x03ul << 8)
#define GPTM_SMCFGR_ETF_2_N6		(0x04ul << 8)
#define GPTM_SMCFGR_ETF_2_N8		(0x05ul << 8)
#define GPTM_SMCFGR_ETF_4_N6		(0x06ul << 8)
#define GPTM_SMCFGR_ETF_4_N8		(0x07ul << 8)
#define GPTM_SMCFGR_ETF_8_N6		(0x08ul << 8)
#define GPTM_SMCFGR_ETF_8_N8		(0x09ul << 8)
#define GPTM_SMCFGR_ETF_16_N5		(0x0Aul << 8)
#define GPTM_SMCFGR_ETF_16_N6		(0x0Bul << 8)
#define GPTM_SMCFGR_ETF_16_N8		(0x0Cul << 8)
#define GPTM_SMCFGR_ETF_32_N5		(0x0Dul << 8)
#define GPTM_SMCFGR_ETF_32_N6		(0x0Eul << 8)
#define GPTM_SMCFGR_ETF_32_N8		(0x0Ful << 8)

#define GPTM_SMCFGR_MSM_MASK		(0x01ul << 7)
#define GPTM_SMCFGR_MSM			(0x01ul << 7)

#define GPTM_SMCFGR_TS_MASK		(0x07ul << 4)
#define GPTM_SMCFGR_TS_ITR0		(0x00ul << 4)
#define GPTM_SMCFGR_TS_ITR1		(0x01ul << 4)
#define GPTM_SMCFGR_TS_ITR2		(0x02ul << 4)
#define GPTM_SMCFGR_TS_ITR3		(0x03ul << 4)
#define GPTM_SMCFGR_TS_TI1F_ED		(0x04ul << 4)
#define GPTM_SMCFGR_TS_TI1FP1		(0x05ul << 4)
#define GPTM_SMCFGR_TS_TI2FP2		(0x06ul << 4)
#define GPTM_SMCFGR_TS_ETRF		(0x07ul << 4)

#define GPTM_SMCFGR_SMS_MASK		(0x07ul << 0)
#define GPTM_SMCFGR_SMS_CK_INT		(0x00ul << 0)
#define GPTM_SMCFGR_SMS_ENC1		(0x01ul << 0)
#define GPTM_SMCFGR_SMS_ENC2		(0x02ul << 0)
#define GPTM_SMCFGR_SMS_ENC3		(0x03ul << 0)
#define GPTM_SMCFGR_SMS_RST		(0x04ul << 0)
#define GPTM_SMCFGR_SMS_GATE		(0x05ul << 0)
#define GPTM_SMCFGR_SMS_TRGI		(0x06ul << 0)
#define GPTM_SMCFGR_SMS_EXT_CLK		(0x07ul << 0)

/* DMAINTENR */
#define GPTM_DMAINTENR_TDE_MASK		(0x01ul << 14)
#define GPTM_DMAINTENR_TDE		(0x01ul << 14)

#define GPTM_DMAINTENR_CC4DE_MASK	(0x01ul << 12)
#define GPTM_DMAINTENR_CC4DE		(0x01ul << 12)

#define GPTM_DMAINTENR_CC3DE_MASK	(0x01ul << 11)
#define GPTM_DMAINTENR_CC3DE		(0x01ul << 11)

#define GPTM_DMAINTENR_CC2DE_MASK	(0x01ul << 10)
#define GPTM_DMAINTENR_CC2DE		(0x01ul << 10)

#define GPTM_DMAINTENR_CC1DE_MASK	(0x01ul << 9)
#define GPTM_DMAINTENR_CC1DE		(0x01ul << 9)

#define GPTM_DMAINTENR_UDE_MASK		(0x01ul << 8)
#define GPTM_DMAINTENR_UDE		(0x01ul << 8)

#define GPTM_DMAINTENR_TIE_MASK		(0x01ul << 6)
#define GPTM_DMAINTENR_TIE		(0x01ul << 6)

#define GPTM_DMAINTENR_CC4IE_MASK	(0x01ul << 4)
#define GPTM_DMAINTENR_CC4IE		(0x01ul << 4)

#define GPTM_DMAINTENR_CC3IE_MASK	(0x01ul << 3)
#define GPTM_DMAINTENR_CC3IE		(0x01ul << 3)

#define GPTM_DMAINTENR_CC2IE_MASK	(0x01ul << 2)
#define GPTM_DMAINTENR_CC2IE		(0x01ul << 2)

#define GPTM_DMAINTENR_CC1IE_MASK	(0x01ul << 1)
#define GPTM_DMAINTENR_CC1IE		(0x01ul << 1)

#define GPTM_DMAINTENR_UIE_MASK		(0x01ul << 0)
#define GPTM_DMAINTENR_UIE		(0x01ul << 0)

/* INTFR */
#define GPTM_INTFR_CC4OF_MASK		(0x01ul << 12)
#define GPTM_INTFR_CC4OF		(0x01ul << 12)

#define GPTM_INTFR_CC3OF_MASK		(0x01ul << 11)
#define GPTM_INTFR_CC3OF		(0x01ul << 11)

#define GPTM_INTFR_CC2OF_MASK		(0x01ul << 10)
#define GPTM_INTFR_CC2OF		(0x01ul << 10)

#define GPTM_INTFR_CC1OF_MASK		(0x01ul << 9)
#define GPTM_INTFR_CC1OF		(0x01ul << 9)

#define GPTM_INTFR_TIF_MASK		(0x01ul << 6)
#define GPTM_INTFR_TIF			(0x01ul << 6)

#define GPTM_INTFR_CC4IF_MASK		(0x01ul << 4)
#define GPTM_INTFR_CC4IF		(0x01ul << 4)

#define GPTM_INTFR_CC3IF_MASK		(0x01ul << 3)
#define GPTM_INTFR_CC3IF		(0x01ul << 3)

#define GPTM_INTFR_CC2IF_MASK		(0x01ul << 2)
#define GPTM_INTFR_CC2IF		(0x01ul << 2)

#define GPTM_INTFR_CC1IF_MASK		(0x01ul << 1)
#define GPTM_INTFR_CC1IF		(0x01ul << 1)

#define GPTM_INTFR_UIF_MASK		(0x01ul << 0)
#define GPTM_INTFR_UIF			(0x01ul << 0)

/* SWEVGR */
#define GPTM_SWEVGR_TG_MASK		(0x01ul << 6)
#define GPTM_SWEVGR_TG			(0x01ul << 6)

#define GPTM_SWEVGR_CC4G_MASK		(0x01ul << 4)
#define GPTM_SWEVGR_CC4G		(0x01ul << 4)

#define GPTM_SWEVGR_CC3G_MASK		(0x01ul << 3)
#define GPTM_SWEVGR_CC3G		(0x01ul << 3)

#define GPTM_SWEVGR_CC2G_MASK		(0x01ul << 2)
#define GPTM_SWEVGR_CC2G		(0x01ul << 2)

#define GPTM_SWEVGR_CC1G_MASK		(0x01ul << 1)
#define GPTM_SWEVGR_CC1G		(0x01ul << 1)

#define GPTM_SWEVGR_UG_MASK		(0x01ul << 0)
#define GPTM_SWEVGR_UG			(0x01ul << 0)

/* CHCTLR1 - common */
#define GPTM_CHCTLR1_CC2S_MASK		(0x03ul << 8)
#define GPTM_CHCTLR1_CC2S_OUT		(0x00ul << 8)
#define GPTM_CHCTLR1_CC2S_IN_TI2	(0x01ul << 8)
#define GPTM_CHCTLR1_CC2S_IN_TI1	(0x02ul << 8)
#define GPTM_CHCTLR1_CC2S_IN_TRC	(0x03ul << 8)

#define GPTM_CHCTLR1_CC1S_MASK		(0x03ul << 0)
#define GPTM_CHCTLR1_CC1S_OUT		(0x00ul << 0)
#define GPTM_CHCTLR1_CC1S_IN_TI2	(0x01ul << 0)
#define GPTM_CHCTLR1_CC1S_IN_TI1	(0x02ul << 0)
#define GPTM_CHCTLR1_CC1S_IN_TRC	(0x03ul << 0)

/* CHCTLR1 - comparison mode */
#define GPTM_CHCTLR1_OC2CE_MASK		(0x01ul << 15)
#define GPTM_CHCTLR1_OC2CE		(0x01ul << 15)

#define GPTM_CHCTLR1_OC2M_MASK		(0x07ul << 12)
#define GPTM_CHCTLR1_OC2M_FRZ		(0x00ul << 12)
#define GPTM_CHCTLR1_OC2M_VLD		(0x01ul << 12)
#define GPTM_CHCTLR1_OC2M_IVLD		(0x02ul << 12)
#define GPTM_CHCTLR1_OC2M_FLIP		(0x03ul << 12)
#define GPTM_CHCTLR1_OC2M_IVLD_L	(0x04ul << 12)
#define GPTM_CHCTLR1_OC2M_VLD_H		(0x05ul << 12)
#define GPTM_CHCTLR1_OC2M_PWM1		(0x06ul << 12)
#define GPTM_CHCTLR1_OC2M_PWM2		(0x07ul << 12)

#define GPTM_CHCTLR1_OC2PE_MASK		(0x01ul << 11)
#define GPTM_CHCTLR1_OC2PE		(0x01ul << 11)

#define GPTM_CHCTLR1_OC2FE_MASK		(0x01ul << 10)
#define GPTM_CHCTLR1_OC2FE		(0x01ul << 10)

#define GPTM_CHCTLR1_OC1CE_MASK		(0x01ul << 7)
#define GPTM_CHCTLR1_OC1CE		(0x01ul << 7)

#define GPTM_CHCTLR1_OC1M_MASK		(0x07ul << 4)
#define GPTM_CHCTLR1_OC1M_FRZ		(0x00ul << 4)
#define GPTM_CHCTLR1_OC1M_VLD		(0x01ul << 4)
#define GPTM_CHCTLR1_OC1M_IVLD		(0x02ul << 4)
#define GPTM_CHCTLR1_OC1M_FLIP		(0x03ul << 4)
#define GPTM_CHCTLR1_OC1M_IVLD_L	(0x04ul << 4)
#define GPTM_CHCTLR1_OC1M_VLD_H		(0x05ul << 4)
#define GPTM_CHCTLR1_OC1M_PWM1		(0x06ul << 4)
#define GPTM_CHCTLR1_OC1M_PWM2		(0x07ul << 4)

#define GPTM_CHCTLR1_OC1PE_MASK		(0x01ul << 3)
#define GPTM_CHCTLR1_OC1PE		(0x01ul << 3)

#define GPTM_CHCTLR1_OC1FE_MASK		(0x01ul << 2)
#define GPTM_CHCTLR1_OC1FE		(0x01ul << 2)

/* CHCTLR1 - capture mode */
#define GPTM_CHCTLR1_IC2F_MASK		(0x0Ful << 12)
#define GPTM_CHCTLR1_IC2F_NONE		(0x00ul << 12)
#define GPTM_CHCTLR1_IC2F_INT_N2	(0x01ul << 12)
#define GPTM_CHCTLR1_IC2F_INT_N4	(0x02ul << 12)
#define GPTM_CHCTLR1_IC2F_INT_N8	(0x03ul << 12)
#define GPTM_CHCTLR1_IC2F_2_N6		(0x04ul << 12)
#define GPTM_CHCTLR1_IC2F_2_N8		(0x05ul << 12)
#define GPTM_CHCTLR1_IC2F_4_N6		(0x06ul << 12)
#define GPTM_CHCTLR1_IC2F_4_N8		(0x07ul << 12)
#define GPTM_CHCTLR1_IC2F_8_N6		(0x08ul << 12)
#define GPTM_CHCTLR1_IC2F_8_N8		(0x09ul << 12)
#define GPTM_CHCTLR1_IC2F_16_N5		(0x0Aul << 12)
#define GPTM_CHCTLR1_IC2F_16_N6		(0x0Bul << 12)
#define GPTM_CHCTLR1_IC2F_16_N8		(0x0Cul << 12)
#define GPTM_CHCTLR1_IC2F_32_N5		(0x0Dul << 12)
#define GPTM_CHCTLR1_IC2F_32_N6		(0x0Eul << 12)
#define GPTM_CHCTLR1_IC2F_32_N8		(0x0Ful << 12)

#define GPTM_CHCTLR1_IC2PSC_MASK	(0x03ul << 10)
#define GPTM_CHCTLR1_IC2PSC_1		(0x00ul << 10)
#define GPTM_CHCTLR1_IC2PSC_2		(0x01ul << 10)
#define GPTM_CHCTLR1_IC2PSC_4		(0x02ul << 10)
#define GPTM_CHCTLR1_IC2PSC_8		(0x03ul << 10)

#define GPTM_CHCTLR1_IC1F_MASK		(0x0Ful << 4)
#define GPTM_CHCTLR1_IC1F_NONE		(0x00ul << 4)
#define GPTM_CHCTLR1_IC1F_INT_N2	(0x01ul << 4)
#define GPTM_CHCTLR1_IC1F_INT_N4	(0x02ul << 4)
#define GPTM_CHCTLR1_IC1F_INT_N8	(0x03ul << 4)
#define GPTM_CHCTLR1_IC1F_2_N6		(0x04ul << 4)
#define GPTM_CHCTLR1_IC1F_2_N8		(0x05ul << 4)
#define GPTM_CHCTLR1_IC1F_4_N6		(0x06ul << 4)
#define GPTM_CHCTLR1_IC1F_4_N8		(0x07ul << 4)
#define GPTM_CHCTLR1_IC1F_8_N6		(0x08ul << 4)
#define GPTM_CHCTLR1_IC1F_8_N8		(0x09ul << 4)
#define GPTM_CHCTLR1_IC1F_16_N5		(0x0Aul << 4)
#define GPTM_CHCTLR1_IC1F_16_N6		(0x0Bul << 4)
#define GPTM_CHCTLR1_IC1F_16_N8		(0x0Cul << 4)
#define GPTM_CHCTLR1_IC1F_32_N5		(0x0Dul << 4)
#define GPTM_CHCTLR1_IC1F_32_N6		(0x0Eul << 4)
#define GPTM_CHCTLR1_IC1F_32_N8		(0x0Ful << 4)

#define GPTM_CHCTLR1_IC1PSC_MASK	(0x03ul << 2)
#define GPTM_CHCTLR1_IC1PSC_1		(0x00ul << 2)
#define GPTM_CHCTLR1_IC1PSC_2		(0x01ul << 2)
#define GPTM_CHCTLR1_IC1PSC_4		(0x02ul << 2)
#define GPTM_CHCTLR1_IC1PSC_8		(0x03ul << 2)

/* CHCTLR2 - common */
#define GPTM_CHCTLR2_CC4S_MASK		(0x03ul << 8)
#define GPTM_CHCTLR2_CC4S_OUT		(0x00ul << 8)
#define GPTM_CHCTLR2_CC4S_IN_TI2	(0x01ul << 8)
#define GPTM_CHCTLR2_CC4S_IN_TI1	(0x02ul << 8)
#define GPTM_CHCTLR2_CC4S_IN_TRC	(0x03ul << 8)

#define GPTM_CHCTLR2_CC3S_MASK		(0x03ul << 0)
#define GPTM_CHCTLR2_CC3S_OUT		(0x00ul << 0)
#define GPTM_CHCTLR2_CC3S_IN_TI2	(0x01ul << 0)
#define GPTM_CHCTLR2_CC3S_IN_TI1	(0x02ul << 0)
#define GPTM_CHCTLR2_CC3S_IN_TRC	(0x03ul << 0)

/* CHCTLR2 - comparison mode */
#define GPTM_CHCTLR2_OC4CE_MASK		(0x01ul << 15)
#define GPTM_CHCTLR2_OC4CE		(0x01ul << 15)

#define GPTM_CHCTLR2_OC4M_MASK		(0x07ul << 12)
#define GPTM_CHCTLR2_OC4M_FRZ		(0x00ul << 12)
#define GPTM_CHCTLR2_OC4M_VLD		(0x01ul << 12)
#define GPTM_CHCTLR2_OC4M_IVLD		(0x02ul << 12)
#define GPTM_CHCTLR2_OC4M_FLIP		(0x03ul << 12)
#define GPTM_CHCTLR2_OC4M_IVLD_L	(0x04ul << 12)
#define GPTM_CHCTLR2_OC4M_VLD_H		(0x05ul << 12)
#define GPTM_CHCTLR2_OC4M_PWM1		(0x06ul << 12)
#define GPTM_CHCTLR2_OC4M_PWM2		(0x07ul << 12)

#define GPTM_CHCTLR2_OC4PE_MASK		(0x01ul << 11)
#define GPTM_CHCTLR2_OC4PE		(0x01ul << 11)

#define GPTM_CHCTLR2_OC4FE_MASK		(0x01ul << 10)
#define GPTM_CHCTLR2_OC4FE		(0x01ul << 10)

#define GPTM_CHCTLR2_OC3CE_MASK		(0x01ul << 7)
#define GPTM_CHCTLR2_OC3CE		(0x01ul << 7)

#define GPTM_CHCTLR2_OC3M_MASK		(0x07ul << 4)
#define GPTM_CHCTLR2_OC3M_FRZ		(0x00ul << 4)
#define GPTM_CHCTLR2_OC3M_VLD		(0x01ul << 4)
#define GPTM_CHCTLR2_OC3M_IVLD		(0x02ul << 4)
#define GPTM_CHCTLR2_OC3M_FLIP		(0x03ul << 4)
#define GPTM_CHCTLR2_OC3M_IVLD_L	(0x04ul << 4)
#define GPTM_CHCTLR2_OC3M_VLD_H		(0x05ul << 4)
#define GPTM_CHCTLR2_OC3M_PWM1		(0x06ul << 4)
#define GPTM_CHCTLR2_OC3M_PWM2		(0x07ul << 4)

#define GPTM_CHCTLR2_OC3PE_MASK		(0x01ul << 3)
#define GPTM_CHCTLR2_OC3PE		(0x01ul << 3)

#define GPTM_CHCTLR2_OC3FE_MASK		(0x01ul << 2)
#define GPTM_CHCTLR2_OC3FE		(0x01ul << 2)

/* CHCTLR2 - capture mode */
#define GPTM_CHCTLR2_IC4F_MASK		(0x0Ful << 12)
#define GPTM_CHCTLR2_IC4F_NONE		(0x00ul << 12)
#define GPTM_CHCTLR2_IC4F_INT_N2	(0x01ul << 12)
#define GPTM_CHCTLR2_IC4F_INT_N4	(0x02ul << 12)
#define GPTM_CHCTLR2_IC4F_INT_N8	(0x03ul << 12)
#define GPTM_CHCTLR2_IC4F_2_N6		(0x04ul << 12)
#define GPTM_CHCTLR2_IC4F_2_N8		(0x05ul << 12)
#define GPTM_CHCTLR2_IC4F_4_N6		(0x06ul << 12)
#define GPTM_CHCTLR2_IC4F_4_N8		(0x07ul << 12)
#define GPTM_CHCTLR2_IC4F_8_N6		(0x08ul << 12)
#define GPTM_CHCTLR2_IC4F_8_N8		(0x09ul << 12)
#define GPTM_CHCTLR2_IC4F_16_N5		(0x0Aul << 12)
#define GPTM_CHCTLR2_IC4F_16_N6		(0x0Bul << 12)
#define GPTM_CHCTLR2_IC4F_16_N8		(0x0Cul << 12)
#define GPTM_CHCTLR2_IC4F_32_N5		(0x0Dul << 12)
#define GPTM_CHCTLR2_IC4F_32_N6		(0x0Eul << 12)
#define GPTM_CHCTLR2_IC4F_32_N8		(0x0Ful << 12)

#define GPTM_CHCTLR2_IC4PSC_MASK	(0x03ul << 10)
#define GPTM_CHCTLR2_IC4PSC_1		(0x00ul << 10)
#define GPTM_CHCTLR2_IC4PSC_2		(0x01ul << 10)
#define GPTM_CHCTLR2_IC4PSC_4		(0x02ul << 10)
#define GPTM_CHCTLR2_IC4PSC_8		(0x03ul << 10)

#define GPTM_CHCTLR2_IC3F_MASK		(0x0Ful << 4)
#define GPTM_CHCTLR2_IC3F_NONE		(0x00ul << 4)
#define GPTM_CHCTLR2_IC3F_INT_N2	(0x01ul << 4)
#define GPTM_CHCTLR2_IC3F_INT_N4	(0x02ul << 4)
#define GPTM_CHCTLR2_IC3F_INT_N8	(0x03ul << 4)
#define GPTM_CHCTLR2_IC3F_2_N6		(0x04ul << 4)
#define GPTM_CHCTLR2_IC3F_2_N8		(0x05ul << 4)
#define GPTM_CHCTLR2_IC3F_4_N6		(0x06ul << 4)
#define GPTM_CHCTLR2_IC3F_4_N8		(0x07ul << 4)
#define GPTM_CHCTLR2_IC3F_8_N6		(0x08ul << 4)
#define GPTM_CHCTLR2_IC3F_8_N8		(0x09ul << 4)
#define GPTM_CHCTLR2_IC3F_16_N5		(0x0Aul << 4)
#define GPTM_CHCTLR2_IC3F_16_N6		(0x0Bul << 4)
#define GPTM_CHCTLR2_IC3F_16_N8		(0x0Cul << 4)
#define GPTM_CHCTLR2_IC3F_32_N5		(0x0Dul << 4)
#define GPTM_CHCTLR2_IC3F_32_N6		(0x0Eul << 4)
#define GPTM_CHCTLR2_IC3F_32_N8		(0x0Ful << 4)

#define GPTM_CHCTLR2_IC3PSC_MASK	(0x03ul << 2)
#define GPTM_CHCTLR2_IC3PSC_1		(0x00ul << 2)
#define GPTM_CHCTLR2_IC3PSC_2		(0x01ul << 2)
#define GPTM_CHCTLR2_IC3PSC_4		(0x02ul << 2)
#define GPTM_CHCTLR2_IC3PSC_8		(0x03ul << 2)

/* CCER */
#define GPTM_CCER_CC4P_MASK		(0x01ul << 13)
#define GPTM_CCER_CC4P			(0x01ul << 13)

#define GPTM_CCER_CC4E_MASK		(0x01ul << 12)
#define GPTM_CCER_CC4E			(0x01ul << 12)

#define GPTM_CCER_CC3P_MASK		(0x01ul << 9)
#define GPTM_CCER_CC3P			(0x01ul << 9)

#define GPTM_CCER_CC3E_MASK		(0x01ul << 8)
#define GPTM_CCER_CC3E			(0x01ul << 8)

#define GPTM_CCER_CC2P_MASK		(0x01ul << 5)
#define GPTM_CCER_CC2P			(0x01ul << 5)

#define GPTM_CCER_CC2E_MASK		(0x01ul << 4)
#define GPTM_CCER_CC2E			(0x01ul << 4)

#define GPTM_CCER_CC1P_MASK		(0x01ul << 1)
#define GPTM_CCER_CC1P			(0x01ul << 1)

#define GPTM_CCER_CC1E_MASK		(0x01ul << 0)
#define GPTM_CCER_CC1E			(0x01ul << 0)

/* CNT */
#define GPTM_CNT_MASK			(0xFFFFul << 0)
#define GPTM_CNT(x)			(x)

/* PSC */
#define GPTM_PSC_MASK			(0xFFFFul << 0)
#define GPTM_PSC(x)			(x)

/* ATRLR */
#define GPTM_ATRLR_MASK			(0xFFFFul << 0)
#define GPTM_ATRLR(x)			(x)

/* CH1CVR */
#define GPTM_CH1CVR_MASK		(0xFFFFul << 0)
#define GPTM_CH1CVR(x)			(x)

/* CH2CVR */
#define GPTM_CH2CVR_MASK		(0xFFFFul << 0)
#define GPTM_CH2CVR(x)			(x)

/* CH3CVR */
#define GPTM_CH3CVR_MASK		(0xFFFFul << 0)
#define GPTM_CH3CVR(x)			(x)

/* CH4CVR */
#define GPTM_CH4CVR_MASK		(0xFFFFul << 0)
#define GPTM_CH4CVR(x)			(x)

/* DMACFGR */
#define GPTM_DMACFGR_DBL_MASK		(0x1Ful << 8)
#define GPTM_DMACFGR_DBL		((x) << 8)

#define GPTM_DMACFGR_DBA_MASK		(0x1Ful << 8)
#define GPTM_DMACFGR_DBA		((x) << 8)

/* DMAADR */
#define GPTM_DMAADR_MASK		(0xFFFFul << 0)
#define GPTM_DMAADR(x)			(x)

typedef struct {
	uint16_t CTLR1;			/**< Control 1 */
	uint16_t RESERVED;		/**< RESERVED */
	uint16_t CTLR2;			/**< Control 2 */
	uint16_t RESERVED2;		/**< RESERVED */
	uint16_t SMCFGR;		/**< Slave mode control */
	uint16_t RESERVED3;		/**< RESERVED */
	uint16_t DMAINTENR;		/**< DMA/interrupt enable */
	uint16_t RESERVED4;		/**< RESERVED */
	uint16_t INTFR;			/**< Interrupt status */
	uint16_t RESERVED5;		/**< RESERVED */
	uint16_t SWEVGR;		/**< Event generation */
	uint16_t RESERVED6;		/**< RESERVED */
	uint16_t CHCTLR1;		/**< Compare/capture control 1 */
	uint16_t RESERVED7;		/**< RESERVED */
	uint16_t CHCTLR2;		/**< Compare/capture control 2 */
	uint16_t RESERVED8;		/**< RESERVED */
	uint16_t CCER;			/**< Compare/capture enable */
	uint16_t RESERVED9;		/**< RESERVED */
	uint16_t CNT;			/**< Counters */
	uint16_t RESERVED10;		/**< RESERVED */
	uint16_t PSC;			/**< Counting clock prescaler */
	uint16_t RESERVED11;		/**< RESERVED */
	uint16_t ATRLR;			/**< Auto-reload value */
	uint16_t RESERVED12[3];		/**< RESERVED */
	uint16_t CH1CVR;		/**< Compare/capture 1 */
	uint16_t RESERVED13;		/**< RESERVED */
	uint16_t CH2CVR;		/**< Compare/capture 2 */
	uint16_t RESERVED14;		/**< RESERVED */
	uint16_t CH3CVR;		/**< Compare/capture 3 */
	uint16_t RESERVED15;		/**< RESERVED */
	uint16_t CH4CVR;		/**< Compare/capture 4 */
	uint16_t RESERVED16[3];		/**< RESERVED */
	uint16_t DMACFGR;		/**< DMA control */
	uint16_t RESERVED17;		/**< RESERVED */
	uint16_t DMAADR;		/**< DMA address for continuous mode */
} per_gptm_t;

extern volatile per_gptm_t *GPTM;

#endif /* _PERIPHERAL_GPTM_H_ */