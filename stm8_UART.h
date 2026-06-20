#ifndef STM8_UART_H
#define STM8_UART_H

#include <stdint.h>
#include "stm8_REG.h"

#define TX_PIN 5
#define RX_PIN 6

void init_UART(uint16_t baudrate);
uint8_t write_UART(uint8_t data);
uint8_t print_UART(char *str);
uint8_t printInt_UART(uint16_t data);
uint8_t line_UART(void);
uint8_t printHex_UART(uint8_t data);

#endif
