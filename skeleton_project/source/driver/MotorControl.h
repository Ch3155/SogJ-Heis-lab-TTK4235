#pragma once
#include "elevio.h"
#include "Elevator.h"
#include "q_system.h"



void MotorControl_move_to_floor(struct Elevator* Elevator, int floor);
void MotorControl_stop_elevator(struct Elevator* Elevator);
