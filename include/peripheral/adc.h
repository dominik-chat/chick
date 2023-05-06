/*
 * Copyright 2023 Dominik Chat
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef _PERIPHERAL_ADC_H_
#define _PERIPHERAL_ADC_H_

#include <stdint.h>

#define ADC_REG_OFFSET			(0x40012400ul)

/* STATR */
#define ADC_STATR_STRT_MASK		(0x01ul << 4)
#define ADC_STATR_STRT			(0x01ul << 4)

#define ADC_STATR_JSTRT_MASK		(0x01ul << 3)
#define ADC_STATR_JSTRT			(0x01ul << 3)

#define ADC_STATR_JEOC_MASK		(0x01ul << 2)
#define ADC_STATR_JEOC			(0x01ul << 2)

#define ADC_STATR_EOC_MASK		(0x01ul << 1)
#define ADC_STATR_EOC			(0x01ul << 1)

#define ADC_STATR_AWD_MASK		(0x01ul << 0)
#define ADC_STATR_AWD			(0x01ul << 0)

/* CTLR1 */
#define ADC_CTLR1_CALVOL_MASK		(0x03ul << 25)
#define ADC_CTLR1_CALVOL_2_4		(0x01ul << 25)
#define ADC_CTLR1_CALVOL_3_4		(0x02ul << 25)

#define ADC_CTLR1_AWDEN_MASK		(0x01ul << 23)
#define ADC_CTLR1_AWDEN			(0x01ul << 23)

#define ADC_CTLR1_JAWDEN_MASK		(0x01ul << 22)
#define ADC_CTLR1_JAWDEN		(0x01ul << 22)

#define ADC_CTLR1_DISCNUM_MASK		(0x07ul << 13)
#define ADC_CTLR1_DISCNUM(x)		((x) << 13)

#define ADC_CTLR1_JDISCEN_MASK		(0x01ul << 12)
#define ADC_CTLR1_JDISCEN		(0x01ul << 12)

#define ADC_CTLR1_DISCEN_MASK		(0x01ul << 11)
#define ADC_CTLR1_DISCEN		(0x01ul << 11)

#define ADC_CTLR1_JAUTO_MASK		(0x01ul << 10)
#define ADC_CTLR1_JAUTO			(0x01ul << 10)

#define ADC_CTLR1_AWDSGL_MASK		(0x01ul << 9)
#define ADC_CTLR1_AWDSGL		(0x01ul << 9)

#define ADC_CTLR1_SCAN_MASK		(0x01ul << 8)
#define ADC_CTLR1_SCAN			(0x01ul << 8)

#define ADC_CTLR1_JEOCIE_MASK		(0x01ul << 7)
#define ADC_CTLR1_JEOCIE		(0x01ul << 7)

#define ADC_CTLR1_AWDIE_MASK		(0x01ul << 6)
#define ADC_CTLR1_AWDIE			(0x01ul << 6)

#define ADC_CTLR1_EOCIE_MASK		(0x01ul << 5)
#define ADC_CTLR1_EOCIE			(0x01ul << 5)

#define ADC_CTLR1_AWDCH_MASK		(0x1Ful << 0)
#define ADC_CTLR1_AWDCH(x)		((x) << 0)

/* CTLR2 */
#define ADC_CTLR2_SWSTART_MASK		(0x01ul << 22)
#define ADC_CTLR2_SWSTART		(0x01ul << 22)

#define ADC_CTLR2_JSWSTART_MASK		(0x01ul << 21)
#define ADC_CTLR2_JSWSTART		(0x01ul << 21)

#define ADC_CTLR2_EXTTRIG_MASK		(0x01ul << 20)
#define ADC_CTLR2_EXTTRIG		(0x01ul << 20)

#define ADC_CTLR2_EXTSEL_MASK		(0x07ul << 17)
#define ADC_CTLR2_EXTSEL_TRGO_T1	(0x00ul << 17)
#define ADC_CTLR2_EXTSEL_CH1_T1		(0x01ul << 17)
#define ADC_CTLR2_EXTSEL_CH2_T1		(0x02ul << 17)
#define ADC_CTLR2_EXTSEL_TRGO_T2	(0x03ul << 17)
#define ADC_CTLR2_EXTSEL_CH1_T2		(0x04ul << 17)
#define ADC_CTLR2_EXTSEL_CH2_T2		(0x05ul << 17)
#define ADC_CTLR2_EXTSEL_PD3_PC2	(0x06ul << 17)
#define ADC_CTLR2_EXTSEL_SWSTART	(0x07ul << 17)

#define ADC_CTLR2_JEXTTRIG_MASK		(0x01ul << 15)
#define ADC_CTLR2_JEXTTRIG		(0x01ul << 15)

#define ADC_CTLR2_JEXTSEL_MASK		(0x07ul << 12)
#define ADC_CTLR2_JEXTSEL_CH3_T1	(0x00ul << 12)
#define ADC_CTLR2_JEXTSEL_CH4_T1	(0x01ul << 12)
#define ADC_CTLR2_JEXTSEL_CH3_T2	(0x02ul << 12)
#define ADC_CTLR2_JEXTSEL_CH4_T2	(0x03ul << 12)
#define ADC_CTLR2_JEXTSEL_PD1_PA2	(0x06ul << 12)
#define ADC_CTLR2_JEXTSEL_JSWSTART	(0x07ul << 12)

#define ADC_CTLR2_ALIGN_MASK		(0x01ul << 11)
#define ADC_CTLR2_ALIGN_R		(0x00ul << 11)
#define ADC_CTLR2_ALIGN_L		(0x01ul << 11)

#define ADC_CTLR2_DMA_MASK		(0x01ul << 8)
#define ADC_CTLR2_DMA			(0x01ul << 8)

#define ADC_CTLR2_RSTCAL_MASK		(0x01ul << 3)
#define ADC_CTLR2_RSTCAL		(0x01ul << 3)

#define ADC_CTLR2_CAL_MASK		(0x01ul << 2)
#define ADC_CTLR2_CAL			(0x01ul << 2)

#define ADC_CTLR2_CONT_MASK		(0x01ul << 1)
#define ADC_CTLR2_CONT			(0x01ul << 1)

#define ADC_CTLR2_ADON_MASK		(0x01ul << 0)
#define ADC_CTLR2_ADON			(0x01ul << 0)

/* SAMPTR1 */
#define ADC_SAMPTR1_SMP_MASK(x)		(0x07ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_3(x)		(0x00ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_9(x)		(0x01ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_15(x)		(0x02ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_30(x)		(0x03ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_43(x)		(0x04ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_57(x)		(0x05ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_73(x)		(0x06ul << (((x) - 10) * 3))
#define ADC_SAMPTR1_SMP_241(x)		(0x07ul << (((x) - 10) * 3))

/* SAMPTR2 */
#define ADC_SAMPTR2_SMP_MASK(x)		(0x07ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_3(x)		(0x00ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_9(x)		(0x01ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_15(x)		(0x02ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_30(x)		(0x03ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_43(x)		(0x04ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_57(x)		(0x05ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_73(x)		(0x06ul << ((x) * 3))
#define ADC_SAMPTR2_SMP_241(x)		(0x07ul << ((x) * 3))

/* IOFR */
#define ADC_IOFR_JOFFSET_MASK		(0x03FFul << 0)
#define ADC_IOFR_JOFFSET(x)		((x) << 0)

/* WDHTR */
#define ADC_WDHTR_HT_MASK		(0x03FFul << 0)
#define ADC_WDHTR_HT(x)			((x) << 0)

/* WDLTR */
#define ADC_WDLTR_LT_MASK		(0x03FFul << 0)
#define ADC_WDLTR_LT(x)			((x) << 0)

/* RSQR1 */
#define ADC_RSQR1_L_MASK		(0x0Ful << 20)
#define ADC_RSQR1_L(x)			(((x) - 1) << 20)

#define ADC_RSQR1_SQ_MASK(x)		(0x1Ful << (((x) - 13) * 5))
#define ADC_RSQR1_SQ(x, y)		((y) << (((x) - 13) * 5))

/* RSQR2 */
#define ADC_RSQR2_SQ_MASK(x)		(0x1Ful << (((x) - 7) * 5))
#define ADC_RSQR2_SQ(x, y)		((y) << (((x) - 7) * 5))

/* RSQR3 */
#define ADC_RSQR3_SQ_MASK(x)		(0x1Ful << (((x) - 1) * 5))
#define ADC_RSQR3_SQ(x, y)		((y) << (((x) - 1) * 5))

/* ISQR */
#define ADC_RSQR1_JL_MASK		(0x03ul << 20)
#define ADC_RSQR1_JL(x)			(((x) - 1) << 20)

#define ADC_ISQR_JSQ_MASK(x)		(0x1Ful << (((x) - 1) * 5))
#define ADC_ISQR_JSQ(x, y)		((y) << (((x) - 1) * 5))

/* IDATAR */
#define ADC_IDATAR_MASK			(0xFFFFul << 0)
#define ADC_IDATAR(x)			((x) << 0)

/* RDATAR */
#define ADC_RDATAR_MASK			(0xFFFFFFFFul << 0)
#define ADC_RDATAR(x)			((x) << 0)

/* DLYR */
#define ADC_DLYR_DLYSRC_MASK		(0x01ul << 9)
#define ADC_DLYR_DLYSRC			(0x01ul << 9)

#define ADC_DLYR_DLYVLU_MASK		(0x01FFul << 0)
#define ADC_DLYR_DLYVLU(x)		((x) << 0)

typedef struct {
	uint32_t STATR;			/**< Status */
	uint32_t CTLR1;			/**< Control 1 */
	uint32_t CTLR2;			/**< Control 2 */
	uint32_t SAMPTR1;		/**< Sample time 1 */
	uint32_t SAMPTR2;		/**< Sample time 2 */
	uint32_t IOFR1;			/**< Injected channel data offset 1 */
	uint32_t IOFR2;			/**< Injected channel data offset 2 */
	uint32_t IOFR3;			/**< Injected channel data offset 3 */
	uint32_t IOFR4;			/**< Injected channel data offset 4 */
	uint32_t WDHTR;			/**< Watchdog high threshold */
	uint32_t WDLTR;			/**< Watchdog low threshold */
	uint32_t RSQR1;			/**< Regular sequence 1  */
	uint32_t RSQR2;			/**< Regular sequence 2  */
	uint32_t RSQR3;			/**< Regular sequence 3  */
	uint32_t ISQR;			/**< Injected sequence */
	uint32_t IDATAR1;		/**< Injected data 1 */
	uint32_t IDATAR2;		/**< Injected data 2 */
	uint32_t IDATAR3;		/**< Injected data 3 */
	uint32_t IDATAR4;		/**< Injected data 4 */
	uint32_t RDATAR;		/**< Regular data */
	uint32_t DLYR;			/**< Delayed data */
} per_adc_t;

volatile per_adc_t *ADC = (volatile per_adc_t *)ADC_REG_OFFSET;

#endif /* _PERIPHERAL_ADC_H_ */