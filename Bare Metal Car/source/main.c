#include <stdint.h>

#include <rcc.h>
#include <gpio.h>
#include "usart.h"

#define LED_DELAY 500000UL // Ticks, 8MHz clock

int main(void)
{
    USART1_Init();

    uint32_t led_delay_count = 0;

    while (1)
    {
        // Increment count, wrap at LED_DELAY
        led_delay_count = ((led_delay_count + 1) % LED_DELAY);

        if (led_delay_count == 0)
        {
            USART1_SendChar('A');
        }
        else if (led_delay_count == (LED_DELAY / 2))
        {
            USART1_SendChar('B');
        }
    }

    /* Will never reach this return */
    return 0;
}
