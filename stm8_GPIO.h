#ifndef STM8_GPIO_H
#define STM8_GPIO_H

#include <stdint.h>
#include "stm8_REG.h"

#define PORTA &PA_ODR
#define PORTB &PB_ODR
#define PORTC &PC_ODR
#define PORTD &PD_ODR

#define OUTPUT 0
#define OUTPUT_FAST 1
#define INPUT 2
#define INPUT_PULLUP 3
#define OUTPUT_OD 4 

void pinMode(volatile uint8_t* port, uint8_t pin, uint8_t mode);
void writePin(volatile uint8_t* port, uint8_t pin, uint8_t state);
void togglePin(volatile uint8_t* port, uint8_t pin);
uint8_t readPin(volatile uint8_t* port, uint8_t pin);

#endif
