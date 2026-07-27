#include "stm8_SPI.h"

void init_SPI(uint8_t mode, uint8_t div, uint8_t firstBit, uint8_t masterSlave)
{
	SPI_CR1 &= ~(1 << 6);
	SPI_CR1 |= mode;
	SPI_CR1 |= div;
	SPI_CR1 |= firstBit;
	SPI_CR1 |= masterSlave;
	SPI_CR1 |= (1 << 6);
}
