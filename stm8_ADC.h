#ifndef STM8_ADC_H
#define STM8_ADC_H

#include <stdint.h>
#include "stm8_REG.h"

#define AIN2 2
#define AIN3 3
#define AIN4 4
#define AIN5 5
#define AIN6 6

void init_ADC(uint8_t channel);
void start_ADC(void);
uint8_t isReady_ADC(void);
uint16_t getValue_ADC (void);

#endif