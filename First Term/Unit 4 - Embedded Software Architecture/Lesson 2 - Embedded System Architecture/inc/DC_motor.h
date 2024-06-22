#ifndef DC_MOTOR_H
#define DC_MOTOR_H

typedef enum {
    DC_INIT,
    DC_IDLE,
    DC_BUSY
} DC_state_id;

DC_state_id ST_DC_init();
DC_state_id ST_DC_idle();
DC_state_id ST_DC_busy();

void DC_set_speed(int in_speed);

#endif