#ifndef __RCC_H_
#define __RCC_H_

#include <stdint.h>

// RCC address definition
#define RCC (0x40021000)

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos (0U)
#define RCC_CR_HSION_Msk (0x1U << RCC_CR_HSION_Pos) /*!< 0x00000001 */
#define RCC_CR_HSION RCC_CR_HSION_Msk               /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos (1U)
#define RCC_CR_HSIRDY_Msk (0x1U << RCC_CR_HSIRDY_Pos) /*!< 0x00000002 */
#define RCC_CR_HSIRDY RCC_CR_HSIRDY_Msk               /*!< Internal High Speed clock ready flag */
#define RCC_CR_HSITRIM_Pos (3U)
#define RCC_CR_HSITRIM_Msk (0x1FU << RCC_CR_HSITRIM_Pos) /*!< 0x000000F8 */
#define RCC_CR_HSITRIM RCC_CR_HSITRIM_Msk                /*!< Internal High Speed clock trimming */
#define RCC_CR_HSICAL_Pos (8U)
#define RCC_CR_HSICAL_Msk (0xFFU << RCC_CR_HSICAL_Pos) /*!< 0x0000FF00 */
#define RCC_CR_HSICAL RCC_CR_HSICAL_Msk                /*!< Internal High Speed clock Calibration */
#define RCC_CR_HSEON_Pos (16U)
#define RCC_CR_HSEON_Msk (0x1U << RCC_CR_HSEON_Pos) /*!< 0x00010000 */
#define RCC_CR_HSEON RCC_CR_HSEON_Msk               /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos (17U)
#define RCC_CR_HSERDY_Msk (0x1U << RCC_CR_HSERDY_Pos) /*!< 0x00020000 */
#define RCC_CR_HSERDY RCC_CR_HSERDY_Msk               /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos (18U)
#define RCC_CR_HSEBYP_Msk (0x1U << RCC_CR_HSEBYP_Pos) /*!< 0x00040000 */
#define RCC_CR_HSEBYP RCC_CR_HSEBYP_Msk               /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON_Pos (19U)
#define RCC_CR_CSSON_Msk (0x1U << RCC_CR_CSSON_Pos) /*!< 0x00080000 */
#define RCC_CR_CSSON RCC_CR_CSSON_Msk               /*!< Clock Security System enable */
#define RCC_CR_PLLON_Pos (24U)
#define RCC_CR_PLLON_Msk (0x1U << RCC_CR_PLLON_Pos) /*!< 0x01000000 */
#define RCC_CR_PLLON RCC_CR_PLLON_Msk               /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos (25U)
#define RCC_CR_PLLRDY_Msk (0x1U << RCC_CR_PLLRDY_Pos) /*!< 0x02000000 */
#define RCC_CR_PLLRDY RCC_CR_PLLRDY_Msk               /*!< PLL clock ready flag */

/*******************  Bit definition for RCC_CFGR register  *******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos (0U)
#define RCC_CFGR_SW_Msk (0x3U << RCC_CFGR_SW_Pos) /*!< 0x00000003 */
#define RCC_CFGR_SW RCC_CFGR_SW_Msk               /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0 (0x1U << RCC_CFGR_SW_Pos)   /*!< 0x00000001 */
#define RCC_CFGR_SW_1 (0x2U << RCC_CFGR_SW_Pos)   /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI 0x00000000U /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE 0x00000001U /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL 0x00000002U /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos (2U)
#define RCC_CFGR_SWS_Msk (0x3U << RCC_CFGR_SWS_Pos) /*!< 0x0000000C */
#define RCC_CFGR_SWS RCC_CFGR_SWS_Msk               /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0 (0x1U << RCC_CFGR_SWS_Pos)   /*!< 0x00000004 */
#define RCC_CFGR_SWS_1 (0x2U << RCC_CFGR_SWS_Pos)   /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI 0x00000000U /*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE 0x00000004U /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL 0x00000008U /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos (4U)
#define RCC_CFGR_HPRE_Msk (0xFU << RCC_CFGR_HPRE_Pos) /*!< 0x000000F0 */
#define RCC_CFGR_HPRE RCC_CFGR_HPRE_Msk               /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0 (0x1U << RCC_CFGR_HPRE_Pos)   /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1 (0x2U << RCC_CFGR_HPRE_Pos)   /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2 (0x4U << RCC_CFGR_HPRE_Pos)   /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3 (0x8U << RCC_CFGR_HPRE_Pos)   /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1 0x00000000U   /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2 0x00000080U   /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4 0x00000090U   /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8 0x000000A0U   /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16 0x000000B0U  /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64 0x000000C0U  /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128 0x000000D0U /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256 0x000000E0U /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512 0x000000F0U /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos (8U)
#define RCC_CFGR_PPRE1_Msk (0x7U << RCC_CFGR_PPRE1_Pos) /*!< 0x00000700 */
#define RCC_CFGR_PPRE1 RCC_CFGR_PPRE1_Msk               /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0 (0x1U << RCC_CFGR_PPRE1_Pos)   /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1 (0x2U << RCC_CFGR_PPRE1_Pos)   /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2 (0x4U << RCC_CFGR_PPRE1_Pos)   /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1 0x00000000U  /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2 0x00000400U  /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4 0x00000500U  /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8 0x00000600U  /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16 0x00000700U /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos (11U)
#define RCC_CFGR_PPRE2_Msk (0x7U << RCC_CFGR_PPRE2_Pos) /*!< 0x00003800 */
#define RCC_CFGR_PPRE2 RCC_CFGR_PPRE2_Msk               /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0 (0x1U << RCC_CFGR_PPRE2_Pos)   /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1 (0x2U << RCC_CFGR_PPRE2_Pos)   /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2 (0x4U << RCC_CFGR_PPRE2_Pos)   /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1 0x00000000U  /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2 0x00002000U  /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4 0x00002800U  /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8 0x00003000U  /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16 0x00003800U /*!< HCLK divided by 16 */

/*!< ADCPPRE configuration */
#define RCC_CFGR_ADCPRE_Pos (14U)
#define RCC_CFGR_ADCPRE_Msk (0x3U << RCC_CFGR_ADCPRE_Pos) /*!< 0x0000C000 */
#define RCC_CFGR_ADCPRE RCC_CFGR_ADCPRE_Msk               /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define RCC_CFGR_ADCPRE_0 (0x1U << RCC_CFGR_ADCPRE_Pos)   /*!< 0x00004000 */
#define RCC_CFGR_ADCPRE_1 (0x2U << RCC_CFGR_ADCPRE_Pos)   /*!< 0x00008000 */

#define RCC_CFGR_ADCPRE_DIV2 0x00000000U /*!< PCLK2 divided by 2 */
#define RCC_CFGR_ADCPRE_DIV4 0x00004000U /*!< PCLK2 divided by 4 */
#define RCC_CFGR_ADCPRE_DIV6 0x00008000U /*!< PCLK2 divided by 6 */
#define RCC_CFGR_ADCPRE_DIV8 0x0000C000U /*!< PCLK2 divided by 8 */

#define RCC_CFGR_PLLSRC_Pos (16U)
#define RCC_CFGR_PLLSRC_Msk (0x1U << RCC_CFGR_PLLSRC_Pos) /*!< 0x00010000 */
#define RCC_CFGR_PLLSRC RCC_CFGR_PLLSRC_Msk               /*!< PLL entry clock source */

#define RCC_CFGR_PLLXTPRE_Pos (17U)
#define RCC_CFGR_PLLXTPRE_Msk (0x1U << RCC_CFGR_PLLXTPRE_Pos) /*!< 0x00020000 */
#define RCC_CFGR_PLLXTPRE RCC_CFGR_PLLXTPRE_Msk               /*!< HSE divider for PLL entry */

/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMULL_Pos (18U)
#define RCC_CFGR_PLLMULL_Msk (0xFU << RCC_CFGR_PLLMULL_Pos) /*!< 0x003C0000 */
#define RCC_CFGR_PLLMULL RCC_CFGR_PLLMULL_Msk               /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_PLLMULL_0 (0x1U << RCC_CFGR_PLLMULL_Pos)   /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL_1 (0x2U << RCC_CFGR_PLLMULL_Pos)   /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL_2 (0x4U << RCC_CFGR_PLLMULL_Pos)   /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL_3 (0x8U << RCC_CFGR_PLLMULL_Pos)   /*!< 0x00200000 */

#define RCC_CFGR_PLLXTPRE_HSE 0x00000000U      /*!< HSE clock not divided for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE_DIV2 0x00020000U /*!< HSE clock divided by 2 for PLL entry */

#define RCC_CFGR_PLLMULL2 0x00000000U /*!< PLL input clock*2 */
#define RCC_CFGR_PLLMULL3_Pos (18U)
#define RCC_CFGR_PLLMULL3_Msk (0x1U << RCC_CFGR_PLLMULL3_Pos) /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL3 RCC_CFGR_PLLMULL3_Msk               /*!< PLL input clock*3 */
#define RCC_CFGR_PLLMULL4_Pos (19U)
#define RCC_CFGR_PLLMULL4_Msk (0x1U << RCC_CFGR_PLLMULL4_Pos) /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL4 RCC_CFGR_PLLMULL4_Msk               /*!< PLL input clock*4 */
#define RCC_CFGR_PLLMULL5_Pos (18U)
#define RCC_CFGR_PLLMULL5_Msk (0x3U << RCC_CFGR_PLLMULL5_Pos) /*!< 0x000C0000 */
#define RCC_CFGR_PLLMULL5 RCC_CFGR_PLLMULL5_Msk               /*!< PLL input clock*5 */
#define RCC_CFGR_PLLMULL6_Pos (20U)
#define RCC_CFGR_PLLMULL6_Msk (0x1U << RCC_CFGR_PLLMULL6_Pos) /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL6 RCC_CFGR_PLLMULL6_Msk               /*!< PLL input clock*6 */
#define RCC_CFGR_PLLMULL7_Pos (18U)
#define RCC_CFGR_PLLMULL7_Msk (0x5U << RCC_CFGR_PLLMULL7_Pos) /*!< 0x00140000 */
#define RCC_CFGR_PLLMULL7 RCC_CFGR_PLLMULL7_Msk               /*!< PLL input clock*7 */
#define RCC_CFGR_PLLMULL8_Pos (19U)
#define RCC_CFGR_PLLMULL8_Msk (0x3U << RCC_CFGR_PLLMULL8_Pos) /*!< 0x00180000 */
#define RCC_CFGR_PLLMULL8 RCC_CFGR_PLLMULL8_Msk               /*!< PLL input clock*8 */
#define RCC_CFGR_PLLMULL9_Pos (18U)
#define RCC_CFGR_PLLMULL9_Msk (0x7U << RCC_CFGR_PLLMULL9_Pos) /*!< 0x001C0000 */
#define RCC_CFGR_PLLMULL9 RCC_CFGR_PLLMULL9_Msk               /*!< PLL input clock*9 */
#define RCC_CFGR_PLLMULL10_Pos (21U)
#define RCC_CFGR_PLLMULL10_Msk (0x1U << RCC_CFGR_PLLMULL10_Pos) /*!< 0x00200000 */
#define RCC_CFGR_PLLMULL10 RCC_CFGR_PLLMULL10_Msk               /*!< PLL input clock10 */
#define RCC_CFGR_PLLMULL11_Pos (18U)
#define RCC_CFGR_PLLMULL11_Msk (0x9U << RCC_CFGR_PLLMULL11_Pos) /*!< 0x00240000 */
#define RCC_CFGR_PLLMULL11 RCC_CFGR_PLLMULL11_Msk               /*!< PLL input clock*11 */
#define RCC_CFGR_PLLMULL12_Pos (19U)
#define RCC_CFGR_PLLMULL12_Msk (0x5U << RCC_CFGR_PLLMULL12_Pos) /*!< 0x00280000 */
#define RCC_CFGR_PLLMULL12 RCC_CFGR_PLLMULL12_Msk               /*!< PLL input clock*12 */
#define RCC_CFGR_PLLMULL13_Pos (18U)
#define RCC_CFGR_PLLMULL13_Msk (0xBU << RCC_CFGR_PLLMULL13_Pos) /*!< 0x002C0000 */
#define RCC_CFGR_PLLMULL13 RCC_CFGR_PLLMULL13_Msk               /*!< PLL input clock*13 */
#define RCC_CFGR_PLLMULL14_Pos (20U)
#define RCC_CFGR_PLLMULL14_Msk (0x3U << RCC_CFGR_PLLMULL14_Pos) /*!< 0x00300000 */
#define RCC_CFGR_PLLMULL14 RCC_CFGR_PLLMULL14_Msk               /*!< PLL input clock*14 */
#define RCC_CFGR_PLLMULL15_Pos (18U)
#define RCC_CFGR_PLLMULL15_Msk (0xDU << RCC_CFGR_PLLMULL15_Pos) /*!< 0x00340000 */
#define RCC_CFGR_PLLMULL15 RCC_CFGR_PLLMULL15_Msk               /*!< PLL input clock*15 */
#define RCC_CFGR_PLLMULL16_Pos (19U)
#define RCC_CFGR_PLLMULL16_Msk (0x7U << RCC_CFGR_PLLMULL16_Pos) /*!< 0x00380000 */
#define RCC_CFGR_PLLMULL16 RCC_CFGR_PLLMULL16_Msk               /*!< PLL input clock*16 */
#define RCC_CFGR_USBPRE_Pos (22U)
#define RCC_CFGR_USBPRE_Msk (0x1U << RCC_CFGR_USBPRE_Pos) /*!< 0x00400000 */
#define RCC_CFGR_USBPRE RCC_CFGR_USBPRE_Msk               /*!< USB Device prescaler */

/*!< MCO configuration */
#define RCC_CFGR_MCO_Pos (24U)
#define RCC_CFGR_MCO_Msk (0x7U << RCC_CFGR_MCO_Pos) /*!< 0x07000000 */
#define RCC_CFGR_MCO RCC_CFGR_MCO_Msk               /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_0 (0x1U << RCC_CFGR_MCO_Pos)   /*!< 0x01000000 */
#define RCC_CFGR_MCO_1 (0x2U << RCC_CFGR_MCO_Pos)   /*!< 0x02000000 */
#define RCC_CFGR_MCO_2 (0x4U << RCC_CFGR_MCO_Pos)   /*!< 0x04000000 */

#define RCC_CFGR_MCO_NOCLOCK 0x00000000U     /*!< No clock */
#define RCC_CFGR_MCO_SYSCLK 0x04000000U      /*!< System clock selected as MCO source */
#define RCC_CFGR_MCO_HSI 0x05000000U         /*!< HSI clock selected as MCO source */
#define RCC_CFGR_MCO_HSE 0x06000000U         /*!< HSE clock selected as MCO source  */
#define RCC_CFGR_MCO_PLLCLK_DIV2 0x07000000U /*!< PLL clock divided by 2 selected as MCO source */

/* Reference defines */
#define RCC_CFGR_MCOSEL RCC_CFGR_MCO
#define RCC_CFGR_MCOSEL_0 RCC_CFGR_MCO_0
#define RCC_CFGR_MCOSEL_1 RCC_CFGR_MCO_1
#define RCC_CFGR_MCOSEL_2 RCC_CFGR_MCO_2
#define RCC_CFGR_MCOSEL_NOCLOCK RCC_CFGR_MCO_NOCLOCK
#define RCC_CFGR_MCOSEL_SYSCLK RCC_CFGR_MCO_SYSCLK
#define RCC_CFGR_MCOSEL_HSI RCC_CFGR_MCO_HSI
#define RCC_CFGR_MCOSEL_HSE RCC_CFGR_MCO_HSE
#define RCC_CFGR_MCOSEL_PLL_DIV2 RCC_CFGR_MCO_PLLCLK_DIV2

/*!<******************  Bit definition for RCC_CIR register  ********************/
#define RCC_CIR_LSIRDYF_Pos (0U)
#define RCC_CIR_LSIRDYF_Msk (0x1U << RCC_CIR_LSIRDYF_Pos) /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF RCC_CIR_LSIRDYF_Msk               /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF_Pos (1U)
#define RCC_CIR_LSERDYF_Msk (0x1U << RCC_CIR_LSERDYF_Pos) /*!< 0x00000002 */
#define RCC_CIR_LSERDYF RCC_CIR_LSERDYF_Msk               /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF_Pos (2U)
#define RCC_CIR_HSIRDYF_Msk (0x1U << RCC_CIR_HSIRDYF_Pos) /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF RCC_CIR_HSIRDYF_Msk               /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos (3U)
#define RCC_CIR_HSERDYF_Msk (0x1U << RCC_CIR_HSERDYF_Pos) /*!< 0x00000008 */
#define RCC_CIR_HSERDYF RCC_CIR_HSERDYF_Msk               /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF_Pos (4U)
#define RCC_CIR_PLLRDYF_Msk (0x1U << RCC_CIR_PLLRDYF_Pos) /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF RCC_CIR_PLLRDYF_Msk               /*!< PLL Ready Interrupt flag */
#define RCC_CIR_CSSF_Pos (7U)
#define RCC_CIR_CSSF_Msk (0x1U << RCC_CIR_CSSF_Pos) /*!< 0x00000080 */
#define RCC_CIR_CSSF RCC_CIR_CSSF_Msk               /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE_Pos (8U)
#define RCC_CIR_LSIRDYIE_Msk (0x1U << RCC_CIR_LSIRDYIE_Pos) /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE RCC_CIR_LSIRDYIE_Msk               /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE_Pos (9U)
#define RCC_CIR_LSERDYIE_Msk (0x1U << RCC_CIR_LSERDYIE_Pos) /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE RCC_CIR_LSERDYIE_Msk               /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE_Pos (10U)
#define RCC_CIR_HSIRDYIE_Msk (0x1U << RCC_CIR_HSIRDYIE_Pos) /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE RCC_CIR_HSIRDYIE_Msk               /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos (11U)
#define RCC_CIR_HSERDYIE_Msk (0x1U << RCC_CIR_HSERDYIE_Pos) /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE RCC_CIR_HSERDYIE_Msk               /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE_Pos (12U)
#define RCC_CIR_PLLRDYIE_Msk (0x1U << RCC_CIR_PLLRDYIE_Pos) /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE RCC_CIR_PLLRDYIE_Msk               /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_LSIRDYC_Pos (16U)
#define RCC_CIR_LSIRDYC_Msk (0x1U << RCC_CIR_LSIRDYC_Pos) /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC RCC_CIR_LSIRDYC_Msk               /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC_Pos (17U)
#define RCC_CIR_LSERDYC_Msk (0x1U << RCC_CIR_LSERDYC_Pos) /*!< 0x00020000 */
#define RCC_CIR_LSERDYC RCC_CIR_LSERDYC_Msk               /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC_Pos (18U)
#define RCC_CIR_HSIRDYC_Msk (0x1U << RCC_CIR_HSIRDYC_Pos) /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC RCC_CIR_HSIRDYC_Msk               /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos (19U)
#define RCC_CIR_HSERDYC_Msk (0x1U << RCC_CIR_HSERDYC_Pos) /*!< 0x00080000 */
#define RCC_CIR_HSERDYC RCC_CIR_HSERDYC_Msk               /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC_Pos (20U)
#define RCC_CIR_PLLRDYC_Msk (0x1U << RCC_CIR_PLLRDYC_Pos) /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC RCC_CIR_PLLRDYC_Msk               /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_CSSC_Pos (23U)
#define RCC_CIR_CSSC_Msk (0x1U << RCC_CIR_CSSC_Pos) /*!< 0x00800000 */
#define RCC_CIR_CSSC RCC_CIR_CSSC_Msk               /*!< Clock Security System Interrupt Clear */

/*****************  Bit definition for RCC_APB2RSTR register  *****************/
#define RCC_APB2RSTR_AFIORST_Pos (0U)
#define RCC_APB2RSTR_AFIORST_Msk (0x1U << RCC_APB2RSTR_AFIORST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_AFIORST RCC_APB2RSTR_AFIORST_Msk               /*!< Alternate Function I/O reset */
#define RCC_APB2RSTR_IOPARST_Pos (2U)
#define RCC_APB2RSTR_IOPARST_Msk (0x1U << RCC_APB2RSTR_IOPARST_Pos) /*!< 0x00000004 */
#define RCC_APB2RSTR_IOPARST RCC_APB2RSTR_IOPARST_Msk               /*!< I/O port A reset */
#define RCC_APB2RSTR_IOPBRST_Pos (3U)
#define RCC_APB2RSTR_IOPBRST_Msk (0x1U << RCC_APB2RSTR_IOPBRST_Pos) /*!< 0x00000008 */
#define RCC_APB2RSTR_IOPBRST RCC_APB2RSTR_IOPBRST_Msk               /*!< I/O port B reset */
#define RCC_APB2RSTR_IOPCRST_Pos (4U)
#define RCC_APB2RSTR_IOPCRST_Msk (0x1U << RCC_APB2RSTR_IOPCRST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_IOPCRST RCC_APB2RSTR_IOPCRST_Msk               /*!< I/O port C reset */
#define RCC_APB2RSTR_IOPDRST_Pos (5U)
#define RCC_APB2RSTR_IOPDRST_Msk (0x1U << RCC_APB2RSTR_IOPDRST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_IOPDRST RCC_APB2RSTR_IOPDRST_Msk               /*!< I/O port D reset */
#define RCC_APB2RSTR_ADC1RST_Pos (9U)
#define RCC_APB2RSTR_ADC1RST_Msk (0x1U << RCC_APB2RSTR_ADC1RST_Pos) /*!< 0x00000200 */
#define RCC_APB2RSTR_ADC1RST RCC_APB2RSTR_ADC1RST_Msk               /*!< ADC 1 interface reset */

#define RCC_APB2RSTR_ADC2RST_Pos (10U)
#define RCC_APB2RSTR_ADC2RST_Msk (0x1U << RCC_APB2RSTR_ADC2RST_Pos) /*!< 0x00000400 */
#define RCC_APB2RSTR_ADC2RST RCC_APB2RSTR_ADC2RST_Msk               /*!< ADC 2 interface reset */

#define RCC_APB2RSTR_TIM1RST_Pos (11U)
#define RCC_APB2RSTR_TIM1RST_Msk (0x1U << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST RCC_APB2RSTR_TIM1RST_Msk               /*!< TIM1 Timer reset */
#define RCC_APB2RSTR_SPI1RST_Pos (12U)
#define RCC_APB2RSTR_SPI1RST_Msk (0x1U << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST RCC_APB2RSTR_SPI1RST_Msk               /*!< SPI 1 reset */
#define RCC_APB2RSTR_USART1RST_Pos (14U)
#define RCC_APB2RSTR_USART1RST_Msk (0x1U << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST RCC_APB2RSTR_USART1RST_Msk               /*!< USART1 reset */

/*****************  Bit definition for RCC_APB1RSTR register  *****************/
#define RCC_APB1RSTR_TIM2RST_Pos (0U)
#define RCC_APB1RSTR_TIM2RST_Msk (0x1U << RCC_APB1RSTR_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST RCC_APB1RSTR_TIM2RST_Msk               /*!< Timer 2 reset */
#define RCC_APB1RSTR_TIM3RST_Pos (1U)
#define RCC_APB1RSTR_TIM3RST_Msk (0x1U << RCC_APB1RSTR_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST RCC_APB1RSTR_TIM3RST_Msk               /*!< Timer 3 reset */
#define RCC_APB1RSTR_WWDGRST_Pos (11U)
#define RCC_APB1RSTR_WWDGRST_Msk (0x1U << RCC_APB1RSTR_WWDGRST_Pos) /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST RCC_APB1RSTR_WWDGRST_Msk               /*!< Window Watchdog reset */
#define RCC_APB1RSTR_USART2RST_Pos (17U)
#define RCC_APB1RSTR_USART2RST_Msk (0x1U << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST RCC_APB1RSTR_USART2RST_Msk               /*!< USART 2 reset */
#define RCC_APB1RSTR_I2C1RST_Pos (21U)
#define RCC_APB1RSTR_I2C1RST_Msk (0x1U << RCC_APB1RSTR_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST RCC_APB1RSTR_I2C1RST_Msk               /*!< I2C 1 reset */

#define RCC_APB1RSTR_CAN1RST_Pos (25U)
#define RCC_APB1RSTR_CAN1RST_Msk (0x1U << RCC_APB1RSTR_CAN1RST_Pos) /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST RCC_APB1RSTR_CAN1RST_Msk               /*!< CAN1 reset */

#define RCC_APB1RSTR_BKPRST_Pos (27U)
#define RCC_APB1RSTR_BKPRST_Msk (0x1U << RCC_APB1RSTR_BKPRST_Pos) /*!< 0x08000000 */
#define RCC_APB1RSTR_BKPRST RCC_APB1RSTR_BKPRST_Msk               /*!< Backup interface reset */
#define RCC_APB1RSTR_PWRRST_Pos (28U)
#define RCC_APB1RSTR_PWRRST_Msk (0x1U << RCC_APB1RSTR_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST RCC_APB1RSTR_PWRRST_Msk               /*!< Power interface reset */

#define RCC_APB1RSTR_USBRST_Pos (23U)
#define RCC_APB1RSTR_USBRST_Msk (0x1U << RCC_APB1RSTR_USBRST_Pos) /*!< 0x00800000 */
#define RCC_APB1RSTR_USBRST RCC_APB1RSTR_USBRST_Msk               /*!< USB Device reset */

/******************  Bit definition for RCC_AHBENR register  ******************/
#define RCC_AHBENR_DMA1EN_Pos (0U)
#define RCC_AHBENR_DMA1EN_Msk (0x1U << RCC_AHBENR_DMA1EN_Pos) /*!< 0x00000001 */
#define RCC_AHBENR_DMA1EN RCC_AHBENR_DMA1EN_Msk               /*!< DMA1 clock enable */
#define RCC_AHBENR_SRAMEN_Pos (2U)
#define RCC_AHBENR_SRAMEN_Msk (0x1U << RCC_AHBENR_SRAMEN_Pos) /*!< 0x00000004 */
#define RCC_AHBENR_SRAMEN RCC_AHBENR_SRAMEN_Msk               /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN_Pos (4U)
#define RCC_AHBENR_FLITFEN_Msk (0x1U << RCC_AHBENR_FLITFEN_Pos) /*!< 0x00000010 */
#define RCC_AHBENR_FLITFEN RCC_AHBENR_FLITFEN_Msk               /*!< FLITF clock enable */
#define RCC_AHBENR_CRCEN_Pos (6U)
#define RCC_AHBENR_CRCEN_Msk (0x1U << RCC_AHBENR_CRCEN_Pos) /*!< 0x00000040 */
#define RCC_AHBENR_CRCEN RCC_AHBENR_CRCEN_Msk               /*!< CRC clock enable */

/******************  Bit definition for RCC_APB2ENR register  *****************/
#define RCC_APB2ENR_AFIOEN_Pos (0U)
#define RCC_APB2ENR_AFIOEN_Msk (0x1U << RCC_APB2ENR_AFIOEN_Pos) /*!< 0x00000001 */
#define RCC_APB2ENR_AFIOEN RCC_APB2ENR_AFIOEN_Msk               /*!< Alternate Function I/O clock enable */
#define RCC_APB2ENR_IOPAEN_Pos (2U)
#define RCC_APB2ENR_IOPAEN_Msk (0x1U << RCC_APB2ENR_IOPAEN_Pos) /*!< 0x00000004 */
#define RCC_APB2ENR_IOPAEN RCC_APB2ENR_IOPAEN_Msk               /*!< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN_Pos (3U)
#define RCC_APB2ENR_IOPBEN_Msk (0x1U << RCC_APB2ENR_IOPBEN_Pos) /*!< 0x00000008 */
#define RCC_APB2ENR_IOPBEN RCC_APB2ENR_IOPBEN_Msk               /*!< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN_Pos (4U)
#define RCC_APB2ENR_IOPCEN_Msk (0x1U << RCC_APB2ENR_IOPCEN_Pos) /*!< 0x00000010 */
#define RCC_APB2ENR_IOPCEN RCC_APB2ENR_IOPCEN_Msk               /*!< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN_Pos (5U)
#define RCC_APB2ENR_IOPDEN_Msk (0x1U << RCC_APB2ENR_IOPDEN_Pos) /*!< 0x00000020 */
#define RCC_APB2ENR_IOPDEN RCC_APB2ENR_IOPDEN_Msk               /*!< I/O port D clock enable */
#define RCC_APB2ENR_ADC1EN_Pos (9U)
#define RCC_APB2ENR_ADC1EN_Msk (0x1U << RCC_APB2ENR_ADC1EN_Pos) /*!< 0x00000200 */
#define RCC_APB2ENR_ADC1EN RCC_APB2ENR_ADC1EN_Msk               /*!< ADC 1 interface clock enable */

#define RCC_APB2ENR_ADC2EN_Pos (10U)
#define RCC_APB2ENR_ADC2EN_Msk (0x1U << RCC_APB2ENR_ADC2EN_Pos) /*!< 0x00000400 */
#define RCC_APB2ENR_ADC2EN RCC_APB2ENR_ADC2EN_Msk               /*!< ADC 2 interface clock enable */

#define RCC_APB2ENR_TIM1EN_Pos (11U)
#define RCC_APB2ENR_TIM1EN_Msk (0x1U << RCC_APB2ENR_TIM1EN_Pos) /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN RCC_APB2ENR_TIM1EN_Msk               /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1EN_Pos (12U)
#define RCC_APB2ENR_SPI1EN_Msk (0x1U << RCC_APB2ENR_SPI1EN_Pos) /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN RCC_APB2ENR_SPI1EN_Msk               /*!< SPI 1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos (14U)
#define RCC_APB2ENR_USART1EN_Msk (0x1U << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN RCC_APB2ENR_USART1EN_Msk               /*!< USART1 clock enable */

/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define RCC_APB1ENR_TIM2EN_Pos (0U)
#define RCC_APB1ENR_TIM2EN_Msk (0x1U << RCC_APB1ENR_TIM2EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN RCC_APB1ENR_TIM2EN_Msk               /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN_Pos (1U)
#define RCC_APB1ENR_TIM3EN_Msk (0x1U << RCC_APB1ENR_TIM3EN_Pos) /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN RCC_APB1ENR_TIM3EN_Msk               /*!< Timer 3 clock enable */
#define RCC_APB1ENR_WWDGEN_Pos (11U)
#define RCC_APB1ENR_WWDGEN_Msk (0x1U << RCC_APB1ENR_WWDGEN_Pos) /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN RCC_APB1ENR_WWDGEN_Msk               /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_USART2EN_Pos (17U)
#define RCC_APB1ENR_USART2EN_Msk (0x1U << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN RCC_APB1ENR_USART2EN_Msk               /*!< USART 2 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos (21U)
#define RCC_APB1ENR_I2C1EN_Msk (0x1U << RCC_APB1ENR_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN RCC_APB1ENR_I2C1EN_Msk               /*!< I2C 1 clock enable */

#define RCC_APB1ENR_CAN1EN_Pos (25U)
#define RCC_APB1ENR_CAN1EN_Msk (0x1U << RCC_APB1ENR_CAN1EN_Pos) /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN RCC_APB1ENR_CAN1EN_Msk               /*!< CAN1 clock enable */

#define RCC_APB1ENR_BKPEN_Pos (27U)
#define RCC_APB1ENR_BKPEN_Msk (0x1U << RCC_APB1ENR_BKPEN_Pos) /*!< 0x08000000 */
#define RCC_APB1ENR_BKPEN RCC_APB1ENR_BKPEN_Msk               /*!< Backup interface clock enable */
#define RCC_APB1ENR_PWREN_Pos (28U)
#define RCC_APB1ENR_PWREN_Msk (0x1U << RCC_APB1ENR_PWREN_Pos) /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN RCC_APB1ENR_PWREN_Msk               /*!< Power interface clock enable */

#define RCC_APB1ENR_USBEN_Pos (23U)
#define RCC_APB1ENR_USBEN_Msk (0x1U << RCC_APB1ENR_USBEN_Pos) /*!< 0x00800000 */
#define RCC_APB1ENR_USBEN RCC_APB1ENR_USBEN_Msk               /*!< USB Device clock enable */

/*******************  Bit definition for RCC_BDCR register  *******************/
#define RCC_BDCR_LSEON_Pos (0U)
#define RCC_BDCR_LSEON_Msk (0x1U << RCC_BDCR_LSEON_Pos) /*!< 0x00000001 */
#define RCC_BDCR_LSEON RCC_BDCR_LSEON_Msk               /*!< External Low Speed oscillator enable */
#define RCC_BDCR_LSERDY_Pos (1U)
#define RCC_BDCR_LSERDY_Msk (0x1U << RCC_BDCR_LSERDY_Pos) /*!< 0x00000002 */
#define RCC_BDCR_LSERDY RCC_BDCR_LSERDY_Msk               /*!< External Low Speed oscillator Ready */
#define RCC_BDCR_LSEBYP_Pos (2U)
#define RCC_BDCR_LSEBYP_Msk (0x1U << RCC_BDCR_LSEBYP_Pos) /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP RCC_BDCR_LSEBYP_Msk               /*!< External Low Speed oscillator Bypass */

#define RCC_BDCR_RTCSEL_Pos (8U)
#define RCC_BDCR_RTCSEL_Msk (0x3U << RCC_BDCR_RTCSEL_Pos) /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL RCC_BDCR_RTCSEL_Msk               /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_BDCR_RTCSEL_0 (0x1U << RCC_BDCR_RTCSEL_Pos)   /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1 (0x2U << RCC_BDCR_RTCSEL_Pos)   /*!< 0x00000200 */

/*!< RTC congiguration */
#define RCC_BDCR_RTCSEL_NOCLOCK 0x00000000U /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE 0x00000100U     /*!< LSE oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI 0x00000200U     /*!< LSI oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE 0x00000300U     /*!< HSE oscillator clock divided by 128 used as RTC clock */

#define RCC_BDCR_RTCEN_Pos (15U)
#define RCC_BDCR_RTCEN_Msk (0x1U << RCC_BDCR_RTCEN_Pos) /*!< 0x00008000 */
#define RCC_BDCR_RTCEN RCC_BDCR_RTCEN_Msk               /*!< RTC clock enable */
#define RCC_BDCR_BDRST_Pos (16U)
#define RCC_BDCR_BDRST_Msk (0x1U << RCC_BDCR_BDRST_Pos) /*!< 0x00010000 */
#define RCC_BDCR_BDRST RCC_BDCR_BDRST_Msk               /*!< Backup domain software reset  */

/*******************  Bit definition for RCC_CSR register  ********************/
#define RCC_CSR_LSION_Pos (0U)
#define RCC_CSR_LSION_Msk (0x1U << RCC_CSR_LSION_Pos) /*!< 0x00000001 */
#define RCC_CSR_LSION RCC_CSR_LSION_Msk               /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos (1U)
#define RCC_CSR_LSIRDY_Msk (0x1U << RCC_CSR_LSIRDY_Pos) /*!< 0x00000002 */
#define RCC_CSR_LSIRDY RCC_CSR_LSIRDY_Msk               /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_RMVF_Pos (24U)
#define RCC_CSR_RMVF_Msk (0x1U << RCC_CSR_RMVF_Pos) /*!< 0x01000000 */
#define RCC_CSR_RMVF RCC_CSR_RMVF_Msk               /*!< Remove reset flag */
#define RCC_CSR_PINRSTF_Pos (26U)
#define RCC_CSR_PINRSTF_Msk (0x1U << RCC_CSR_PINRSTF_Pos) /*!< 0x04000000 */
#define RCC_CSR_PINRSTF RCC_CSR_PINRSTF_Msk               /*!< PIN reset flag */
#define RCC_CSR_PORRSTF_Pos (27U)
#define RCC_CSR_PORRSTF_Msk (0x1U << RCC_CSR_PORRSTF_Pos) /*!< 0x08000000 */
#define RCC_CSR_PORRSTF RCC_CSR_PORRSTF_Msk               /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF_Pos (28U)
#define RCC_CSR_SFTRSTF_Msk (0x1U << RCC_CSR_SFTRSTF_Pos) /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF RCC_CSR_SFTRSTF_Msk               /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF_Pos (29U)
#define RCC_CSR_IWDGRSTF_Msk (0x1U << RCC_CSR_IWDGRSTF_Pos) /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF RCC_CSR_IWDGRSTF_Msk               /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos (30U)
#define RCC_CSR_WWDGRSTF_Msk (0x1U << RCC_CSR_WWDGRSTF_Pos) /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF RCC_CSR_WWDGRSTF_Msk               /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos (31U)
#define RCC_CSR_LPWRRSTF_Msk (0x1U << RCC_CSR_LPWRRSTF_Pos) /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF RCC_CSR_LPWRRSTF_Msk               /*!< Low-Power reset flag */

// RCC registers access structure
typedef struct
{

    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;

} RCCR;

// RCC registers access macro
#define _RCCRA(x) ((RCCR *)x)

#endif /* __RCC_H_ */