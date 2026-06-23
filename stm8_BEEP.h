#ifndef STM8_BEEP_H
#define STM8_BEEP_H

#include <stdint.h>
#include "stm8_REG.h"

#define BEEP_1KHZ 0
#define BEEP_2KHZ 1
#define BEEP_4KHZ 2

void init_BEEP(uint8_t freq);
void beep(uint8_t state);

#endif
