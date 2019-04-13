// This code accesses GPIO without using R30 and R31
#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

#define GPIO0	0x44e07000		// GPIO Bank 0  See Table 2.2 of TRM <1>
#define GPIO_SETDATAOUT		0x194	// For setting the GPIO registers
#define GPIO_CLEARDATAOUT	0x190	// For clearing the GPIO registers
#define P9_11	(0x1<<30)			// Bit position tied to P9_11

void main(void)
{
	uint32_t *gpio0 = (uint32_t *)GPIO0;
	
	while(1) {
		gpio0[GPIO_SETDATAOUT/4] = P9_11;
		__delay_cycles(100000000);
		gpio0[GPIO_CLEARDATAOUT/4] = P9_11;
		__delay_cycles(100000000);
	}
}
