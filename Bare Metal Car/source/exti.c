#include "exti.h"
#include "gpio.h"
#include "rcc.h"
#include "interupt.h"
#include "carMotorCtrl.h"
#include "usart.h"

void EXTI_Init()
{

    _RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_IOPBEN; // IOPBEN: IO port B clock enable
    _RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_AFIOEN; // AFIOEN: Alternate function IO clock enable

    // ECHO pin Input
    _GPIOPRA(GPIO_P_B)->CRL &= ~GPIO_CRL_MODE0; // 00: Input mode (reset state)
    _GPIOPRA(GPIO_P_B)->CRL &= ~GPIO_CRL_CNF0;  // Reset
    _GPIOPRA(GPIO_P_B)->CRL |= GPIO_CRL_CNF0_1; // 10: Input with pull-up / pull-down
    _GPIOPRA(GPIO_P_B)->ODR &= ~GPIO_ODR_ODR0;  // ODR -> PB0 -> 0 -> pull-down mode

    // External interrupt on ECHO pin
    _AFIORA(AFIO)->AFIO_EXTICR1 = 0;                      // Reset
    _AFIORA(AFIO)->AFIO_EXTICR1 |= AFIO_EXTICR1_EXTI0_PB; // EXTIx[3:0]: EXTI x configuration (x= 0 to 3), 0001: PB[x] pin
    _EXTIRA(EXTI)->EXTI_IMR |= EXTI_IMR_MR0;              // MRx: Interrupt Mask on line x, 1: Interrupt request from Line x is not masked
    _EXTIRA(EXTI)->EXTI_FTSR |= EXTI_FTSR_TR0;            // 1: Falling trigger enabled (for Event and Interrupt) for input line.
    NVIC_EnableIRQ(EXTI0_IRQn);                           // Enable External Interrupt, External Line[0] Interrupt
}

void EXTI0_IRQHandler()
{

    _EXTIRA(EXTI)->EXTI_PR |= EXTI_PR_PR0; // 1: selected trigger request occurred. This bit is cleared by writing a �1� into the bit.

    if ((_GPIOPRA(GPIO_P_B)->IDR & GPIO_IDR_IDR0) == 0)
    {
        motorDisable();
    }
}