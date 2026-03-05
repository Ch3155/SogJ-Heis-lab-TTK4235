#pragma once
#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"


typedef enum { 
    StartUp   = 0,
    Idle   = 1,
    Moving     = 2,
    EmergencyStop = 3
} States;

struct ElevatorControl{
    struct Elevator* Elevator;
    struct Q_system* q_system;
    struct Floorpanel* floorpanel;
};

struct ElevatorControl* ElevatorControl_init();
void ElevatorControl_update(struct ElevatorControl* elevator_control);