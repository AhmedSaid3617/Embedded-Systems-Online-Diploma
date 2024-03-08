#include "uart.h"

unsigned char buffer[100] = "Learn in depth Ahmed Said";

void main(){

    UART_send_string(buffer);
    
}