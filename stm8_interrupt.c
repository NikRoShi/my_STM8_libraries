#include "stm8_interrupt.h"

void set_EXTI(uint8_t port, uint8_t mode) {
	EXTI_CR1 &= ~(0b11 << port);
	EXTI_CR1 |= mode << port;
}
