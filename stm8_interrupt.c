#include "stm8_interrupt.h"

static uint8_t modeA = 0;
static uint8_t EXTIPinMaskA = 0;
volatile uint8_t EXTI_FlagA = 0;

static uint8_t modeB = 0;
static uint8_t EXTIPinMaskB = 0;
volatile uint8_t EXTI_FlagB = 0;

static uint8_t modeC = 0;
static uint8_t EXTIPinMaskC = 0;
volatile uint8_t EXTI_FlagC = 0;

static uint8_t modeD = 0;
static uint8_t EXTIPinMaskD = 0;
volatile uint8_t EXTI_FlagD = 0;

void set_EXTI(uint8_t port, uint8_t mode)
{
	EXTI_CR1 &= ~(0b11 << port);
	EXTI_CR1 |= mode << port;
	if (port == EXTI_PORTA) modeA = mode;
	if (port == EXTI_PORTB) modeB = mode;
	if (port == EXTI_PORTC) modeC = mode;
	if (port == EXTI_PORTD) modeD = mode;
}
void set_EXTI_pin(uint8_t port, uint8_t pin)
{
	switch (port)
	{
		case EXTI_PORTA:
			EXTIPinMaskA |= (1 << pin);
			PA_DDR &= ~(1 << pin);
			PA_CR2 |= (1 << pin);
			break;
		case EXTI_PORTB:
			EXTIPinMaskB |= (1 << pin);
			PB_DDR &= ~(1 << pin);
			PB_CR2 |= (1 << pin);
			break;
		case EXTI_PORTC:
			EXTIPinMaskC |= (1 << pin);
			PC_DDR &= ~(1 << pin);
			PC_CR2 |= (1 << pin);
			break;
		case EXTI_PORTD:
			EXTIPinMaskD |= (1 << pin);
			PD_DDR &= ~(1 << pin);
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
void handlerPortA(void)
{
	uint8_t current = PA_IDR;
	uint8_t event = 0;
	if (modeA == FALLING)
	{
		event = (~current) & EXTIPinMaskA;
	}
	if (modeA == RISING)
	{
		event = current & EXTIPinMaskA;
	}
	EXTI_FlagA |= event;
}
void handlerPortB(void)
{
	uint8_t current = PB_IDR;
	uint8_t event = 0;
	if (modeB == FALLING)
	{
		event = (~current) & EXTIPinMaskB;
	}
	if (modeB == RISING)
	{
		event = current & EXTIPinMaskB;
	}
	EXTI_FlagB |= event;
}
void handlerPortC(void)
{
	uint8_t current = PC_IDR;
	uint8_t event = 0;
	if (modeC == FALLING)
	{
		event = (~current) & EXTIPinMaskC;
	}
	if (modeC == RISING)
	{
		event = current & EXTIPinMaskC;
	}
	EXTI_FlagC |= event;
}
void handlerPortD(void)
{
	uint8_t current = PD_IDR;
	uint8_t event = 0;
	if (modeD == FALLING)
	{
		event = (~current) & EXTIPinMaskD;
	}
	if (modeD == RISING)
	{
		event = current & EXTIPinMaskD;
	}
	EXTI_FlagD |= event;
}
