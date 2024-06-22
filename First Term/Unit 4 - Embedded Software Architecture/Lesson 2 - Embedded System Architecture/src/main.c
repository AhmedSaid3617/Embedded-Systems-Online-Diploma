#include "US_sensor.h"

// Current states
US_state_id US_state;
// Pointer to the state function for the current state.
US_state_id (*US_state_func)() = 0x0;
// Array of pointers to US state functions.
US_state_id (*US_state_funcs[])() = {&ST_US_init, &ST_US_busy};


int main(){
    US_state = US_INIT;

    while (1)
    {
        US_state_func = US_state_funcs[US_state];
        US_state = US_state_func();
    }
    

}