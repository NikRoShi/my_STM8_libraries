#include "stm8_UART.h"

void init_UART(uint16_t baudrate)
{
	uint16_t uartdiv;
	
	PD_DDR |= (1 << TX_PIN);
	PD_CR1 |= (1 << TX_PIN);
	
	uartdiv = F_CPU / baudrate;
	
	UART1_BRR2 = (uartdiv & 0x000F) | ((uartdiv >> 2) & 0x00F0);
	UART1_BRR1 = (uartdiv >> 1) & 0x00FF;
	
	UART1_CR2 |= UART1_CR2_TEN;
}
void write_UART(uint8_t data)
{
	
}
