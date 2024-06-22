#include "DC_motor.h"
#include <stdio.h>

static int speed = 0;

DC_state_id ST_DC_init(){
    printf("DC state: init.\n");
    return DC_IDLE;
}

DC_state_id ST_DC_idle(){
    printf("DC state: idle. Speed: %d\n", speed);
    return DC_BUSY;
}

DC_state_id ST_DC_busy(){
    printf("DC state: busy. Speed: %d\n", speed);
    return DC_IDLE;
}

void DC_set_speed(int in_speed){
    speed = in_speed;
    printf("DC motor set speed = %d\n", speed);
}