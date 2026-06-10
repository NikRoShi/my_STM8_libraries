#ifndef STM8_PWM_H
#define STM8_PWM_H

#include <stdint.h>
#include "stm8_REG.h"

#define PD4 1
#define PD3 2
#define PA3 3

void init_PWM(uint16_t period);
void startChannel_PWM(uint8_t channel);
void stopChannel_PWM(uint8_t channel);
void write_PWM(uint8_t channel, uint16_t value);
void writePercent_PWM(uint8_t channel, uint8_t percent);

#endif