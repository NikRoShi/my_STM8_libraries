#include "stm8_interrupt.h"

void set_EXTI(uint8_t port, uint8_t mode)
{
	EXTI_CR1 &= ~(0b11 << port);
	EXTI_CR1 |= mode << port;
}
void setInterruptPriority(uint8_t interrupt, uint8_t priorityLevel)
{
	volatile uint8_t *priorityReg = &ITC_SPR1 + (interrupt >> 2);
	*priorityReg &= ~(3 << ((interrupt & 3) << 1));
	*priorityReg |= (priorityLevel << ((interrupt & 3) << 1));
}
