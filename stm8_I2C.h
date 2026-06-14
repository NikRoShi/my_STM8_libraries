#ifndef STM8_I2C_H
#define STM8_I2C_H

#include <stdint.h>
#include "stm8_REG.h"

// скорость i2c 100кГц
#define F_I2C 100000UL

void init_I2C(void);
uint8_t ping_I2C(uint8_t address);

#endif
