// Code for versatile pb arm board.

#include "uart.h"

#define UART0 *((volatile unsigned int*)((unsigned int*)0x101f1000)) // Address of UART0 is at 0x101f1000

void UART_send_string(unsigned char* P_tx_string){
    while (*P_tx_string != '\0')
    {
        UART0 = (unsigned int)*P_tx_string;
        P_tx_string++;
    }
    
}