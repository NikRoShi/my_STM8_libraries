#ifndef STM8_SPI_H
#define STM8_SPI_H

#include <stdint.h>
#include "stm8_REG.h"

#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3

#define SPI_DIV2 (0 << 3)
#define SPI_DIV4 (1 << 3)
#define SPI_DIV8 (2 << 3)
#define SPI_DIV16 (3 << 3)
#define SPI_DIV32 (4 << 3)
#define SPI_DIV64 (5 << 3)
#define SPI_DIV128 (6 << 3)
#define SPI_DIV256 (7 << 3)

#define SPI_MSB (0 << 7)
#define SPI_LSB (1 << 7)

#define SPI_MST (1 << 2)
#define SPI_SLV (0 << 2)

void init_SPI(uint8_t mode, uint8_t div, uint8_t firstBit, uint8_t masterSlave);

#endif
