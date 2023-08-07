#include <stdint.h>

#include <rcc.h>
#include <gpio.h>
#include "usart.h"
#include "carMotorCtrl.h"

#define LED_DELAY 500000UL // Ticks, 8MHz clock

int main(void)
{
    USART2_Init();
    motorCtrlInit();

    _RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_IOPCEN;

    _GPIOPRA(GPIO_P_C)->CRH &= ~GPIO_CRH_MODE13;
    _GPIOPRA(GPIO_P_C)->CRH |= GPIO_CRH_MODE13_1;
    _GPIOPRA(GPIO_P_C)->CRH &= ~GPIO_CRH_CNF13;

    uint32_t led_delay_count = 0;

    motorEnable();

    while (1)
    {
        char USART2_LastChar = USART2_ReadLastChar();

        // Increment count, wrap at LED_DELAY
        led_delay_count = ((led_delay_count + 1) % LED_DELAY);

        if (led_delay_count == 0)
        {
            _GPIOPRA(GPIO_P_C)->ODR |= GPIO_ODR_ODR13;
        }
        else if (led_delay_count == (LED_DELAY / 2))
        {
            _GPIOPRA(GPIO_P_C)->ODR &= ~GPIO_ODR_ODR13;
        }

        switch (USART2_LastChar)
        {
        case 'R':
            USART2_SendChar('R');
            motorEnable();
            break;
        case 'O':
            USART2_SendChar('O');
            motorDisable();
            break;
        case 'W':
            USART2_SendChar('W');
            carForward();
            break;
        case 'A':
            USART2_SendChar('A');
            carTurnLeft();
            break;
        case 'S':
            USART2_SendChar('S');
            carBackward();
            break;
        case 'D':
            USART2_SendChar('D');
            carTurnRight();
            break;
        }
    }

    /* Will never reach this return */
    return 0;
}
