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
void set_EXTI_pin(uint8_t port, uint8_t pin);
void clear_EXTI_pin(uint8_t port, uint8_t pin);
void setInterruptPriority(uint8_t interrupt, uint8_t priorityLevel);

/*
=============== ШАБЛОН ВНЕШНЕГО ПРЕРЫВАНИЯ ПОРТА D ===============
void EXTI_D_IRQHandler(void) __interrupt(IRQ_EXTI3)
{
    uint8_t currentStateD = 0;
	uint8_t changedD = 0;
	
	currentStateD = PD_IDR;
	changedD = previousStateD ^ currentStateD;
	changedD &= EXTIPinMaskD;
	EXTI_FlagD |= changedD;
	previousStateD = currentStateD;
}
=============== ШАБЛОН ОБРАБОТЧИКА ПРЕРЫВАНИЯ ПОРТА D ===============
if (EXTI_FlagD & (1 << 0))
{
	EXTI_FlagD &= ~(1 << 0);
	
}
if (EXTI_FlagD & (1 << 1))
{
	EXTI_FlagD &= ~(1 << 1);
	
}
if (EXTI_FlagD & (1 << 2))
{
	EXTI_FlagD &= ~(1 << 2);
	
}
if (EXTI_FlagD & (1 << 3))
{
	EXTI_FlagD &= ~(1 << 3);
	
}
if (EXTI_FlagD & (1 << 4))
{
	EXTI_FlagD &= ~(1 << 4);
	
}
if (EXTI_FlagD & (1 << 5))
{
	EXTI_FlagD &= ~(1 << 5);
	
}
if (EXTI_FlagD & (1 << 6))
{
	EXTI_FlagD &= ~(1 << 6);
	
}
if (EXTI_FlagD & (1 << 7))
{
	EXTI_FlagD &= ~(1 << 7);
	
}
*/

#endif
