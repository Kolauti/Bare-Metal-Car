/*
 * USART2
 * APB CLOCK: 8MHz
 * BAUD RATE: 9600
 * TX       : PA9
 * RX       : PA10
 */

#include "usart.h"
#include <rcc.h>
#include <gpio.h>
#include <interupt.h>

volatile char usart2_buffer[USART2_BUFFER_SIZE] = {0};
volatile char usart2_last_char = '0';
volatile uint8_t usart2_index = 0;
volatile uint8_t usart2_read_ready = 0;

// -----------------------------------------------
// USART2 Init
// -----------------------------------------------
void USART2_Init()
{

	_RCCRA(RCC)->APB1ENR |= RCC_APB1ENR_USART2EN; // 1: USART2 clock enabled
	_RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_IOPAEN;	  // 1: I/O port A clock enabled
	_RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_AFIOEN;	  // 1: Alternate Function I/O clock enabled

	// TX alternative push-pull (PA9)
	_GPIOPRA(GPIO_P_A)->CRL |= GPIO_CRL_MODE2;	// 11 Output mode, max speed 50 MHz.
	_GPIOPRA(GPIO_P_A)->CRL &= ~GPIO_CRL_CNF2;	// 00 CNF2 reset
	_GPIOPRA(GPIO_P_A)->CRL |= GPIO_CRL_CNF2_1; // 10 Alternate function output Push-pull

	// RX float input (PA10)
	_GPIOPRA(GPIO_P_A)->CRL &= ~GPIO_CRL_MODE3; // 00 Input mode (reset state)
	_GPIOPRA(GPIO_P_A)->CRL &= ~GPIO_CRL_CNF3;	// 00 CNF3 reset
	_GPIOPRA(GPIO_P_A)->CRL |= GPIO_CRL_CNF3_0; // 01 Floating input (reset state)

	// uint32_t uartdiv = APB2_CLK / USART2_BAUD_RATE;
	uint32_t uartdiv = SYSTEM_CLOCK / USART2_BAUD_RATE;

	__USARTRA(USART_2)->BRR = (((uartdiv / 16) << USART_BRR_DIV_Mantissa_Pos) | ((uartdiv % 16) << USART_BRR_DIV_Fraction_Pos)); // USARTx_BRR = Fck / (16*USARTDIV)
	__USARTRA(USART_2)->CR1 |= USART_CR1_UE;																					 // USART enable
	__USARTRA(USART_2)->CR1 |= USART_CR1_TE;																					 // Transmitter enable
	__USARTRA(USART_2)->CR1 |= USART_CR1_RE;																					 // Receiver enable

	__USARTRA(USART_2)->CR1 |= USART_CR1_RXNEIE; // RXNE interrupt enable
	NVIC_EnableIRQ(USART2_IRQn);				 // USART2 global Interrupt
}

// -----------------------------------------------
// USART2 Send Char
// -----------------------------------------------
void USART2_SendChar(char ch)
{
	// Wait for data to be transfered to Transmit Data Register
	//  0: Data is not transferred to the shift register; 1: Data is transferred to the shift register
	while (!(__USARTRA(USART_2)->SR & USART_SR_TXE))
		;

	__USARTRA(USART_2)->DR = ch;
}

// -----------------------------------------------
// USART2 Send String
// -----------------------------------------------
void USART2_SendString(char *str)
{

	while (*str)
	{
		USART2_SendChar(*str++);
	}
}

// -----------------------------------------------
// USART2 Read Last Char
// -----------------------------------------------
char USART2_ReadLastChar()
{
	if (usart2_read_ready)
	{
		return usart2_last_char;
	}

	return '0';
}

// -----------------------------------------------
// USART2 Read String, copy buffer
// -----------------------------------------------
uint8_t USART2_ReadString(char *str)
{

	if (usart2_read_ready)
	{

		uint8_t i = 0;

		while (usart2_buffer[i] != 0)
		{
			str[i] = usart2_buffer[i]; // Copy volatile buffer to external buffer
			i++;
		}

		str[i] = 0;			   // Add terminating NULL to external buffer
		usart2_read_ready = 0; // Read usart buffer only once

		return 1;
	}

	return 0;
}

// -----------------------------------------------
// USART2 Reset last char
// -----------------------------------------------
void USART2_ResetLastChar()
{
	usart2_last_char = '0';
}

// -----------------------------------------------
// USART2 IRQHandler
// -----------------------------------------------
void USART2_IRQHandler()
{

	if (__USARTRA(USART_2)->SR & USART_SR_RXNE) // 1: Received data is ready to be read
	{
		// USART_SR_RXNE clear.
		// This clearing sequence is recommended only for multibuffer communication.
		// Used for variable lenght input (more than one byte).
		__USARTRA(USART_2)->SR &= ~USART_SR_RXNE;

		char rx = (char)__USARTRA(USART_2)->DR;

		if ((rx == '\r') || (rx == '\n'))
		{
			usart2_buffer[usart2_index] = 0; // Add terminating NULL
			usart2_last_char = usart2_buffer[usart2_index - 1];
			usart2_index = 0;
			usart2_read_ready = 1;
		}
		else
		{
			if (usart2_index == USART2_BUFFER_SIZE - 1) // If overflows, reset index
				usart2_index = 0;

			usart2_buffer[usart2_index++] = rx;
			usart2_read_ready = 0; // New data, reset ready flag
		}
	}
}
