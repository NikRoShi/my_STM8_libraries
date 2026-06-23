#ifndef STM8_BEEP_H
#define STM8_BEEP_H

#include <stdint.h>
#include "stm8_REG.h"

#define KHZ1 0
#define KHZ2 1
#define KHZ4 2

void init_BEEP(uint8_t freq);
void beep(uint8_t state);

#endif
