#ifndef US_SENSOR
#define US_SENSOR

#include "states.h"

typedef enum {
    US_INIT,
    US_BUSY
} US_state_id;

int US_get_distance();

US_state_id ST_US_init();
US_state_id ST_US_busy();

#endif