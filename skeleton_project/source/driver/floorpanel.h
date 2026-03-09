#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "elevio.h"
#include "Elevator.h"
#include "MotorControl.h"
#include "Lights.h"
#include "floorpanel.h"
#include "q_system.h"
#include "ElevatorControl.h"

struct Floorpanel {
    bool BTN_FLR_4_DWN;
    bool BTN_FLR_3_DWN;
    bool BTN_FLR_3_UP;
    bool BTN_FLR_2_DWN;
    bool BTN_FLR_2_UP;
    bool BTN_FLR_1_UP;
};

void Floorpanel_update(struct Floorpanel* floorpanel);

struct Floorpanel* Floorpanel_init();
