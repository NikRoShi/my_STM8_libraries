#ifndef STM8_UART_H
#define STM8_UART_H

#include <stdint.h>
#include "stm8_REG.h"

void init_UART(uint16_t baudrate, uint8_t rxInterrupt);
uint8_t write_UART(uint8_t data);
uint8_t print_UART(char *str);
uint8_t printInt_UART(uint16_t data);
uint8_t line_UART(void);
uint8_t printHex_UART(uint8_t data);
uint8_t isDataReceived_UART(void);
uint8_t getData_UART(void);

/* прерывание UART
void UART1_RX_IRQHandler(void) __interrupt(IRQ_UART1_RX) {
    
}
*/

#endif
