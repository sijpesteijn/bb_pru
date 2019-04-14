// This code accesses GPIO without using R30 and R31
#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

#define GPIO0	0x44e07000			// GPIO Bank 0  See Table 2.2 of TRM <1>
#define GPIO_SETDATAOUT		0x194	// For setting the GPIO registers
#define GPIO_CLEARDATAOUT	0x190	// For clearing the GPIO registers

#define P8_13	(0x1<<23)			// Bit position tied to P8_13
#define P8_14	(0x1<<26)			// Bit position tied to P8_14
#define P8_17	(0x1<<27)			// Bit position tied to P8_17
#define P8_19	(0x1<<22)			// Bit position tied to P8_19

#define P9_11	(0x1<<30)			// Bit position tied to P9_11
#define P9_13	(((uint32_t)0x1)<<31)			// Bit position tied to P9_13
#define P9_17	(0x1<<5)			// Bit position tied to P9_17
#define P9_18	(0x1<<4)			// Bit position tied to P9_18
#define P9_19	(0x1<<13)			// Bit position tied to P9_19
#define P9_20	(0x1<<12)			// Bit position tied to P9_20
#define P9_21	(0x1<<3)			// Bit position tied to P9_21
#define P9_22	(0x1<<2)			// Bit position tied to P9_22
#define P9_24	(0x1<<15)			// Bit position tied to P9_24
#define P9_26	(0x1<<14)			// Bit position tied to P9_26

#define deley   10000000

void leftToRight(uint32_t gpios[]) {
	uint32_t *gpio0 = (uint32_t *)GPIO0;
	gpio0[GPIO_SETDATAOUT/4] = P8_13;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P8_14;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P8_17;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P8_19;
	__delay_cycles(deley);

	gpio0[GPIO_SETDATAOUT/4] = P9_11;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_13;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_17;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_18;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_19;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_20;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_21;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_22;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_24;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = P9_26;
	__delay_cycles(deley);


	gpio0[GPIO_CLEARDATAOUT/4] = P8_13;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P8_14;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P8_17;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P8_19;
	__delay_cycles(deley);

	gpio0[GPIO_CLEARDATAOUT/4] = P9_11;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_13;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_17;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_18;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_19;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_20;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_21;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_22;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_24;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = P9_26;
	__delay_cycles(deley);
//	int i, length = sizeof(gpios)/sizeof(gpios[0]);
//
//	for(i=0; i < length; i++)
//	{
//		gpio0[GPIO_SETDATAOUT / 4] = gpios[i];
//		__delay_cycles(deley);
//	}
//	for(i=0; i < length; i++)
//	{
//		gpio0[GPIO_CLEARDATAOUT / 4] = gpios[i];
//		__delay_cycles(deley);
//	}
}

void wiggle(uint32_t gpios[]) {
	uint32_t *gpio0 = (uint32_t *)GPIO0;
	uint32_t first = P8_13 | P8_17 | P9_11 | P9_17 | P9_19 | P9_21 | P9_24;
	uint32_t second = P8_14 | P8_19 | P9_13 | P9_18 | P9_20 | P9_22 | P9_26;

	gpio0[GPIO_SETDATAOUT/4] = first;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = second;
	__delay_cycles(deley);
	gpio0[GPIO_SETDATAOUT/4] = second;
	__delay_cycles(deley);
	gpio0[GPIO_CLEARDATAOUT/4] = first;
	__delay_cycles(deley);

}

void knightrider(uint32_t gpios[]) {
	uint32_t *gpio0 = (uint32_t *)GPIO0;
	int i = 0;
	for(i=0;i<14;i++) {
		gpio0[GPIO_SETDATAOUT / 4] = gpios[i];
		__delay_cycles(deley);
		gpio0[GPIO_CLEARDATAOUT / 4] = gpios[i];
		__delay_cycles(deley);
	}
}

void main(void)
{
	uint32_t *gpio0 = (uint32_t *)GPIO0;
	uint32_t gpios[] = { P8_13, P8_14, P8_17, P8_19, P9_11, P9_13, P9_17, P9_18, P9_19, P9_20, P9_21, P9_22, P9_24, P9_26 };
	while(1) {
//		wiggle(gpios);
//		leftToRight(gpios);
		knightrider(gpios);
	}
}


