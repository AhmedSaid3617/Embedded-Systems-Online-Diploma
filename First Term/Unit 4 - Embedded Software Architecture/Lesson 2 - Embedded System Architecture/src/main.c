#include "US_sensor.h"
#include "DC_motor.h"
#include "collision_avoidance.h"

// Current states
US_state_id US_state;
DC_state_id DC_state;
CA_state_id CA_state;

// Pointer to the state function for the current state.
US_state_id (*US_state_func)() = 0x0;
DC_state_id (*DC_state_func)() = 0x0;
CA_state_id (*CA_state_func)() = 0x0;

// Array of pointers to US state functions.
US_state_id (*US_state_funcs[])() = {&ST_US_init, &ST_US_busy};
DC_state_id (*DC_state_funcs[])() = {&ST_DC_init, &ST_DC_idle, &ST_DC_busy};
CA_state_id (*CA_state_funcs[])() = {&ST_CA_waiting, &ST_CA_driving};

int main(){
    US_state = US_INIT;
    DC_state = DC_INIT;
    CA_state = CA_WAITING;

    while (1)
    {
        US_state_func = US_state_funcs[US_state];
        US_state = US_state_func();

        DC_state_func = DC_state_funcs[DC_state];
        DC_state = DC_state_func();

        CA_state_func = CA_state_funcs[CA_state];
        CA_state = CA_state_func();
    }
    

}