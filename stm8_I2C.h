#ifndef STM8_I2C_H
#define STM8_I2C_H

#include <stdint.h>
#include "stm8_REG.h"

// скорость i2c 100кГц
#define F_I2C 100000UL

#define WRITE 0
#define READ 1

void init_I2C(void);
uint8_t start_I2C(void);
void stop_I2C(void);
void clearADDR_I2C(void);
void setACK_I2C(uint8_t state);
uint8_t writeAddr_I2C(uint8_t address, uint8_t mode);
uint8_t writeByte_I2C(uint8_t data);
uint8_t ping_I2C(uint8_t address);
uint8_t writeReg_I2C(uint8_t address, uint8_t reg, uint8_t data);
uint8_t readByte_I2C(uint8_t address, uint8_t *data);
uint8_t readReg_I2C(uint8_t address, uint8_t reg, uint8_t *data);
uint8_t readBuffer2_I2C(uint8_t address, uint8_t reg, uint8_t *buf);
uint8_t readBuffer_I2C(uint8_t address, uint8_t reg, uint8_t *buf, uint8_t size);

#endif
