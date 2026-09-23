#ifndef STM8_INTERRUPT_H
#define STM8_INTERRUPT_H

#include <stdint.h>
#include "stm8_REG.h"

#define EXTI_PORTA 0
#define EXTI_PORTB 2
#define EXTI_PORTC 4
#define EXTI_PORTD 6

#define FALLING_LOW 0
#define RISING 1
#define FALLING 2
#define RISING_FALLING 3

#define LVL0 2
#define LVL1 1
#define LVL2 0

void set_EXTI(uint8_t port, uint8_t mode);
void setInterruptPriority(uint8_t interrupt, uint8_t level);

#endif
