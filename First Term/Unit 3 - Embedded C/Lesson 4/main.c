#include "GPIO.h"

int main(){
    SYSCTL_RCGC2_R = 0x20;

    for (volatile int i = 0; i < 200; i++);

    GPIOF_DEN_R |= 1<<3;
    GPIOF_DIR_R |= 1<<3;

    while (1)
    {
        GPIOF_DATA_R |= 1<<3;
        for (volatile int i = 0; i < 1000000; i++);
        GPIOF_DATA_R &= ~(1<<3);
        for (volatile int i = 0; i < 1000000; i++);
    }
    
}