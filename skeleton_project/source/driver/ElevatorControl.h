#pragma once
#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"

struct ElevatorControl{
    struct Elevator* Elevator;
    struct Q_system* q_system;
    struct Floorpanel* floorpanel;
};

void ElevatorControl_update(struct ElevatorControl* elevator_control);