#ifndef STM8_UART_H
#define STM8_UART_H

#include <stdint.h>
#include "stm8_REG.h"

#define TX_PIN 5
#define RX_PIN 6

void init_UART(uint16_t baudrate);
void write_UART(uint8_t data);

#endif
