#ifndef COLLISION_AVOIDANCE_H
#define COLLISION_AVOIDANCE_H

#include "states.h"
typedef enum {
    CA_WAITING,
    CA_DRIVING
} CA_state_id;

CA_state_id ST_CA_waiting();
CA_state_id ST_CA_driving();

#endif