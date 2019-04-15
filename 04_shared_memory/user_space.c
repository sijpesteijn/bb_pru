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

    printf("\nINFO: Starting %s example.\r\n", "pru_memory");
    /* Initialize the PRU */
    prussdrv_init();

    prussdrv_pruintc_init(&pruss_intc_initdata);

    prussdrv_exec_program (PRU_NUM0, "./example.bin");

    prussdrv_pru_wait_event (PRU_EVTOUT_0);

    prussdrv_pru_clear_event (PRU_EVTOUT0, PRU0_ARM_INTERRUPT);
}
