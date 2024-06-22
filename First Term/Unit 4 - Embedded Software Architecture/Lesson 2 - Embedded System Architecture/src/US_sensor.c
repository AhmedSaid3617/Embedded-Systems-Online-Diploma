#include "US_sensor.h"
#include <stdlib.h>
#include <stdio.h>

int US_get_distance(){
    int distance = 44 + rand()%10;
    printf ("US: distance %d\n", distance);
    return distance;
}

US_state_id ST_US_init(){
    printf("US: State init.\n");
    return US_BUSY;
}

US_state_id ST_US_busy(){
    printf("US: State busy.\n");
    return US_BUSY;
}