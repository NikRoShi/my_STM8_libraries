#ifndef STM8_I2C_H
#define STM8_I2C_H

#include <stdint.h>
#include "stm8_REG.h"

void init_I2C(void);
uint8_t start_I2C(void);
uint8_t sendAddress_I2C(uint8_t addr);
uint8_t write_I2C(uint8_t data);
uint8_t readAck_I2C(void);
uint8_t readNack_I2C(void);
void stop_I2C(void);

#endif