#include "stm8_UART.h"

void init_UART(uint16_t baudrate)
{
	uint16_t uartdiv;
	
	PD_DDR |= (1 << TX_PIN);
	PD_CR1 |= (1 << TX_PIN);
	
	uartdiv = F_CPU / baudrate;
	
	UART1_BRR2 = (uartdiv & 0x000F) | ((uartdiv >> 8) & 0x00F0);
	UART1_BRR1 = (uartdiv >> 4) & 0x00FF;
	
	UART1_CR2 |= UART1_CR2_TEN;
}
uint8_t write_UART(uint8_t data)
{
	uint16_t timeout = 50000;
	
	while (!(UART1_SR & UART1_SR_TXE))
	{
		if (--timeout == 0) return 0;
	}
	
	UART1_DR = data;
	return 1;
}
uint8_t print_UART(char *str)
{
	while(*str != 0)
	{
		if(write_UART(*str) == 1)
		{
			str++;
		}
		else return 0;
	}
	return 1;
}
