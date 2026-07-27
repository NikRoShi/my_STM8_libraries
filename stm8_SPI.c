#include "stm8_SPI.h"

void init_SPI(uint8_t mode, uint8_t div, uint8_t firstBit, uint8_t masterSlave)
{
	SPI_CR1 &= ~(1 << 6);
	SPI_CR1 = 0;
	SPI_CR1 |= mode;
	SPI_CR1 |= div;
	SPI_CR1 |= firstBit;
	SPI_CR1 |= masterSlave;
	SPI_CR1 |= (1 << 6);
}
uint8_t exchange_SPI(uint8_t data)
{
	uint16_t timeout = 50000;
	
	while (!(SPI_SR & SPI_SR_TXE))
	{
		if (--timeout == 0) return 0;
	}
	timeout = 50000;
	
	SPI_DR = data;
	
	while (!(SPI_SR & SPI_SR_RXNE))
	{
		if (--timeout == 0) return 0;
	}
	timeout = 50000;
	
	while (!(SPI_SR & SPI_SR_BSY))
	{
		if (--timeout == 0) return 0;
	}
	return SPI_DR;
}
void write_SPI(uint8_t data)
{
	exchange_SPI(data);
}
uint8_t read_SPI(void)
{
	return exchange_SPI(0xFF);
}
