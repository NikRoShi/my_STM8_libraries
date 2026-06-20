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
	while (*str != 0)
	{
		if (write_UART(*str) == 1)
		{
			str++;
		}
		else return 0;
	}
	return 1;
}
uint8_t printInt_UART(uint16_t num)
{
	char buf[5];
	uint8_t i = 0;
	
	if (num == 0)
	{
		write_UART('0');
		return 1;
	}
	while (num != 0)
	{
		buf[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		if (write_UART(buf[i]) == 0) return 0;
	}
	return 1;
}
uint8_t line_UART(void)
{
	if (write_UART('\r') == 0) return 0;
	if (write_UART('\n') == 0) return 0;
	return 1;
}
static char nibbleToHex(uint8_t nibble)
{
	if (nibble < 10) return nibble + '0';
	else return nibble - 10 + 'A';
}
uint8_t printHex_UART(uint8_t hex)
{
	uint8_t high = hex >> 4;
	uint8_t low = hex & 0x0F;
	
	if (write_UART(nibbleToHex(high)) == 0) return 0;
	if (write_UART(nibbleToHex(low)) == 0) return 0;
	return 1;
}
