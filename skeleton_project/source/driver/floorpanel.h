#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/Elevator.h"
#include "driver/MotorControl.h"
#include "driver/Lights.h"
#include "driver/floorpanel.h"
#include "driver/q_system.h"
#include "driver/ElevatorControl.h"

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
