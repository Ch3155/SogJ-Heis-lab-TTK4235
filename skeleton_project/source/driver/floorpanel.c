#include "floorpanel.h"
#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"

void Floorpanel_update(struct Floorpanel* floorpanel){
    floorpanel->BTN_FLR_4_DWN = elevio_callButton(3, BUTTON_HALL_DOWN);
    floorpanel->BTN_FLR_3_DWN = elevio_callButton(2, BUTTON_HALL_DOWN);
    floorpanel->BTN_FLR_3_UP   = elevio_callButton(2, BUTTON_HALL_UP);
    floorpanel->BTN_FLR_2_DWN = elevio_callButton(1, BUTTON_HALL_DOWN);
    floorpanel->BTN_FLR_2_UP   = elevio_callButton(1, BUTTON_HALL_UP);
    floorpanel->BTN_FLR_1_UP   = elevio_callButton(0, BUTTON_HALL_UP);
}