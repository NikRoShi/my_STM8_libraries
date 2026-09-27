#ifndef STM8_INTERRUPT_H
#define STM8_INTERRUPT_H

#include <stdint.h>
#include "stm8_REG.h"

#define EXTI_PORTA 0
#define EXTI_PORTB 2
#define EXTI_PORTC 4
#define EXTI_PORTD 6

//#define FALLING_LOW 0
#define RISING 1
#define FALLING 2
//#define RISING_FALLING 3

#define LVL0 2
#define LVL1 1
#define LVL2 0

extern volatile uint8_t EXTI_FlagA;
extern volatile uint8_t EXTI_FlagB;
extern volatile uint8_t EXTI_FlagC;
extern volatile uint8_t EXTI_FlagD;

void set_EXTI(uint8_t port, uint8_t mode);
void set_EXTI_pin(uint8_t port, uint8_t pin);
void clear_EXTI_pin(uint8_t port, uint8_t pin);
void setInterruptPriority(uint8_t interrupt, uint8_t priorityLevel);
void handlerPortA(void);
void handlerPortB(void);
void handlerPortC(void);
void handlerPortD(void);

/*
=============== ШАБЛОН ВНЕШНЕГО ПРЕРЫВАНИЯ ПОРТА A ===============
void EXTI_A_IRQHandler(void) __interrupt(IRQ_EXTI0)
{
	handlerPortA();
}
=============== ШАБЛОН ВНЕШНЕГО ПРЕРЫВАНИЯ ПОРТА B ===============
void EXTI_B_IRQHandler(void) __interrupt(IRQ_EXTI1)
{
	handlerPortB();
}
=============== ШАБЛОН ВНЕШНЕГО ПРЕРЫВАНИЯ ПОРТА C ===============
void EXTI_C_IRQHandler(void) __interrupt(IRQ_EXTI2)
{
	handlerPortC();
}
=============== ШАБЛОН ВНЕШНЕГО ПРЕРЫВАНИЯ ПОРТА D ===============
void EXTI_D_IRQHandler(void) __interrupt(IRQ_EXTI3)
{
    handlerPortD();
}
=============== ШАБЛОН ОБРАБОТЧИКА ПРЕРЫВАНИЯ ПОРТА A ===============
if (EXTI_FlagA & (1 << 0))
{
	EXTI_FlagA &= ~(1 << 0);
	действие();
}
*/

#endif
