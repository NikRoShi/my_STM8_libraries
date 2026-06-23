#include <stdint.h>
#include "stm8_BEEP.h"

void init_BEEP(uint8_t freq)
{
	BEEP_CSR &= ~BEEP_CSR_BEEPEN;
	
	BEEP_CSR &= ~(0x1F << BEEP_CSR_BEEPDIV);
	BEEP_CSR |= (0x1E << BEEP_CSR_BEEPDIV);
	
	BEEP_CSR |= (freq << BEEP_CSR_BEEPSEL);
}
void beep(uint8_t state)
{
	if (state == HIGH) BEEP_CSR |= BEEP_CSR_BEEPEN;
	if (state == LOW) BEEP_CSR &= ~BEEP_CSR_BEEPEN;
}
