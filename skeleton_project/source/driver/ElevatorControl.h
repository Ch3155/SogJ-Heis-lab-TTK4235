#pragma once
#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>


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
void ElevatorControl_run(struct ElevatorControl* elevator_control);
void ElevatorControl_destroy(struct ElevatorControl* elevator_control);