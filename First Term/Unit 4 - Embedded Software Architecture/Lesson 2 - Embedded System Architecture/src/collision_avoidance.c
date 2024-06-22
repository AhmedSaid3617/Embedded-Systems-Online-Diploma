#include "collision_avoidance.h"
#include "US_sensor.h"
#include "DC_motor.h"
#include <stdio.h>

#define THRESHOLD 50

int distance = 0;
int speed = 0;


CA_state_id ST_CA_waiting(){
    DC_set_speed(speed);
    distance = US_get_distance();
    printf("CA state: waiting, distance = %d, speed = %d.\n", distance, speed);
    if (distance > THRESHOLD)
    {
        speed = 50;
        return CA_DRIVING;
    }
    else {
        speed = 0;
        return CA_WAITING;
    }
    
}

CA_state_id ST_CA_driving(){
    DC_set_speed(speed);
    distance = US_get_distance();
    printf("CA state: driving, distance = %d, speed = %d.\n", distance, speed);
    if (distance > THRESHOLD)
    {
        speed = 50;
        return CA_DRIVING;
    }
    else {
        speed = 0;
        return CA_WAITING;
    }
    
}
