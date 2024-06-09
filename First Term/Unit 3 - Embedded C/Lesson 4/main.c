#include "GPIO.h"

int main(){
    SYSCTL_RCGCGPIO |= 1<<5;

    GPIOF_DEN_R |= 1<<3;
    GPIOF_DIR_R |= 1<<3;

    while (1)
    {
        GPIOF_DATA_R |= 1<<3;
        for (volatile int i = 0; i < 100000; i++);
        GPIOF_DATA_R &= ~(1<<3);
        for (volatile int i = 0; i < 100000; i++);
    }
    
}