#include "stm8_interrupt.h"

volatile uint8_t previousStateA = 0;
volatile uint8_t EXTIPinMaskA = 0;
volatile uint8_t EXTI_FlagA = 0;

volatile uint8_t previousStateB = 0;
volatile uint8_t EXTIPinMaskB = 0;
volatile uint8_t EXTI_FlagB = 0;

volatile uint8_t previousStateC = 0;
volatile uint8_t EXTIPinMaskC = 0;
volatile uint8_t EXTI_FlagC = 0;

volatile uint8_t previousStateD = 0;
volatile uint8_t EXTIPinMaskD = 0;
volatile uint8_t EXTI_FlagD = 0;

void set_EXTI(uint8_t port, uint8_t mode)
{
	EXTI_CR1 &= ~(0b11 << port);
	EXTI_CR1 |= mode << port;
}
void set_EXTI_pin(uint8_t port, uint8_t pin)
{
	switch (port)
	{
		case EXTI_PORTA:
			if (EXTIPinMaskA == 0) previousStateA = PA_IDR;
			EXTIPinMaskA |= (1 << pin);
			PA_DDR |= (1 << pin);
			PA_CR2 |= (1 << pin);
			break;
		case EXTI_PORTB:
			if (EXTIPinMaskB == 0) previousStateB = PB_IDR;
			EXTIPinMaskB |= (1 << pin);
			PB_DDR |= (1 << pin);
			PB_CR2 |= (1 << pin);
			break;
		case EXTI_PORTC:
			if (EXTIPinMaskC == 0) previousStateC = PC_IDR;
			EXTIPinMaskC |= (1 << pin);
			PC_DDR |= (1 << pin);
			PC_CR2 |= (1 << pin);
			break;
		case EXTI_PORTD:
			if (EXTIPinMaskD == 0) previousStateD = PD_IDR;
			EXTIPinMaskD |= (1 << pin);
			PD_DDR |= (1 << pin);
			PD_CR2 |= (1 << pin);
			break;
	}
}
void clear_EXTI_pin(uint8_t port, uint8_t pin)
{
	switch (port)
	{
		case EXTI_PORTA:
			EXTIPinMaskA &= ~(1 << pin);
			PA_DDR &= ~(1 << pin);
			PA_CR2 &= ~(1 << pin);
			break;
		case EXTI_PORTB:
			EXTIPinMaskB &= ~(1 << pin);
			PB_DDR &= ~(1 << pin);
			PB_CR2 &= ~(1 << pin);
			break;
		case EXTI_PORTC:
			EXTIPinMaskC &= ~(1 << pin);
			PC_DDR &= ~(1 << pin);
			PC_CR2 &= ~(1 << pin);
			break;
		case EXTI_PORTD:
			EXTIPinMaskD &= ~(1 << pin);
			PD_DDR &= ~(1 << pin);
			PD_CR2 &= ~(1 << pin);
			break;
	}
}
void setInterruptPriority(uint8_t interrupt, uint8_t priorityLevel)
{
	volatile uint8_t *priorityReg = &ITC_SPR1 + (interrupt >> 2);
	*priorityReg &= ~(3 << ((interrupt & 3) << 1));
	*priorityReg |= (priorityLevel << ((interrupt & 3) << 1));
}
