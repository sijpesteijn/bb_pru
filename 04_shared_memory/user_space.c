//
// Created by Gijs Sijpesteijn on 2019-04-14.
//

#define PRU_NUM0	  0
// Driver header file
#include <prussdrv.h>
#include <pruss_intc_mapping.h>

int main (void) {
    unsigned int ret;
    tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

    printf("\nINFO: Starting %s example.\r\n", "dmx");
    /* Initialize the PRU */
    prussdrv_init();

    prussdrv_pruintc_init(&pruss_intc_initdata);
}
