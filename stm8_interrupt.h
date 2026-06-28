#ifndef STM8_INTERRUPT_H
#define STM8_INTERRUPT_H

#include <stdint.h>
#include "stm8_REG.h"

#define PORTA 0
#define PORTB 2
#define PORTC 4
#define PORTD 6

#define FALLING_LOW 0
#define RISING 1
#define FALLING 2
#define RISING_FALLING 3

#define LVL0 0
#define LVL1 1
#define LVL2 2
#define LVL3 3

void setMode(uint8_t port, uint8_t mode);
void setPriority(uint8_t interrupt, uint8_t level);

/*	шаблон для обработчика перывания exti
PORTA 3
PORTB 4
PORTC 5
PORTD 6

ЗАМЕНИТЬ ВОПРОСЫ НА БУКВУ ПОРТА

void EXTI_PORT?_IRQHandler(void) __interrupt(?)
{
    uint8_t port = GPIO?_IDR;

    if (!(port & (1 << 0)))
    {
        //P?1
    }
    if (!(port & (1 << 1)))
    {
        //P?2
    }
    if (!(port & (1 << 2)))
    {
        //P?3
    }
}
*/

#endif
