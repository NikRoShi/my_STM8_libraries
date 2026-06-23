#include <stdint.h>
#include "stm8_BEEP.h"

void init_BEEP(uint8_t freq)
{
	if (freq != BEEP_1KHZ && freq != BEEP_2KHZ && freq != BEEP_4KHZ) freq = BEEP_1KHZ;
	BEEP_CSR &= ~BEEP_CSR_BEEPEN;
	
	BEEP_CSR &= ~(0x1F << BEEP_CSR_BEEPDIV);
	BEEP_CSR |= (0x0E << BEEP_CSR_BEEPDIV);
	
	BEEP_CSR &= ~(0x03 << BEEP_CSR_BEEPSEL);
	BEEP_CSR |= (freq << BEEP_CSR_BEEPSEL);
}
void beep(uint8_t state)
{
	if (state == HIGH) BEEP_CSR |= BEEP_CSR_BEEPEN;
	if (state == LOW) BEEP_CSR &= ~BEEP_CSR_BEEPEN;
}
