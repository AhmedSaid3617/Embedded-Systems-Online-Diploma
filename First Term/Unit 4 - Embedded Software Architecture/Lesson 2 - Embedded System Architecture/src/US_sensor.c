#include "US_sensor.h"
#include <stdlib.h>
#include <stdio.h>

static int distance = 0;

int US_get_distance(){
    distance = 44 + rand()%10;
    printf ("US: distance %d\n", distance);
    return distance;
}

US_state_id ST_US_init(){
    printf("US: State init. Distance: %d\n", distance);
    return US_BUSY;
}

US_state_id ST_US_busy(){
    printf("US: State busy. Distance: %d\n", distance);
    return US_BUSY;
}