#include "MotorControl.h"
#include "Elevator.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"


void MotorControl_move_to_floor(struct Elevator* Elevator, int floor){

    if (floor > Elevator->current_floor){
        Elevator->cur_dir = DIRN_UP;
        Elevator->is_moving = true;
    } else if (floor < Elevator->current_floor){
        Elevator->cur_dir = DIRN_DOWN;
        Elevator->is_moving = true;
    } else {
        MotorControl_stop_elevator(Elevator);
    }
    while(Elevator->current_floor != floor && !Elevator->stop_button_pressed){
        elevio_motorDirection(Elevator->cur_dir);
        Elevator_update(Elevator);
        nanosleep(&(struct timespec){0, 0.5*1000*1000}, NULL);
    }

    elevio_motorDirection(DIRN_STOP);
    Elevator->is_moving = false;
    
}



void MotorControl_stop_elevator(struct Elevator* Elevator){
    elevio_motorDirection(DIRN_STOP);
    Elevator->is_moving = false;
}