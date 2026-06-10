#include "stm8_GPIO.h"

void pinMode(volatile uint8_t* port, uint8_t pin, uint8_t mode) {
	if (mode == OUTPUT) {
		*(port + 2) |= (1 << pin);
		*(port + 3) |= (1 << pin);
	}
	else if (mode == OUTPUT_FAST) {
		*(port + 2) |= (1 << pin);
		*(port + 3) |= (1 << pin);
		*(port + 4) |= (1 << pin);
	}
	else if (mode == INPUT) {
		*(port + 2) &= ~(1 << pin);
		*(port + 3) &= ~(1 << pin);
	}
	else if (mode == INPUT_PULLUP) {
		*(port + 2) &= ~(1 << pin);
		*(port + 3) |= (1 << pin);
	}
	else if (mode == OUTPUT_OD) {
		*(port + 2) |= (1 << pin);  // DDR = 1 (Выход)
		*(port + 3) &= ~(1 << pin); // CR1 = 0 (Open Drain)
	}
}

void writePin(volatile uint8_t* port, uint8_t pin, uint8_t state) {
	if (state == HIGH) {
		*port |= (1 << pin);
	}
	else {*port &= ~(1 << pin);}
}

void togglePin(volatile uint8_t* port, uint8_t pin) {
	*port ^= (1 << pin);
}

uint8_t readPin(volatile uint8_t* port, uint8_t pin) {
	if (*(port +1) & (1 << pin)) {
		return 1;
	}
	return 0;
}