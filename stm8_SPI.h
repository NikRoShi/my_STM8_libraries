#ifndef STM8_SPI_H
#define STM8_SPI_H

#include <stdint.h>
#include "stm8_REG.h"

#define MODE0 0
#define MODE1 1
#define MODE2 2
#define MODE3 3

#define DIV2 (0 << 3)
#define DIV4 (1 << 3)
#define DIV8 (2 << 3)
#define DIV16 (3 << 3)
#define DIV32 (4 << 3)
#define DIV64 (5 << 3)
#define DIV128 (6 << 3)
#define DIV256 (7 << 3)

#define MSB (0 << 7)
#define LSB (1 << 7)

#define MST (1 << 2)
#define SLV (0 << 2)

void init_SPI(uint8_t mode, uint8_t div, uint8_t lsbfirst, uint8_t masterSlave);

#endif
