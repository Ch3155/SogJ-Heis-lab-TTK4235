#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"
#include "ElevatorControl.h"

void ElevatorControl_update(struct ElevatorControl* elevator_control){
    Elevator_update(elevator_control->Elevator);
    Floorpanel_update(elevator_control->floorpanel);

    q_system_make_q(elevator_control->q_system, *elevator_control->Elevator, *elevator_control->floorpanel);
    q_system_get_target_floor(*elevator_control->q_system, *elevator_control->Elevator);

    MotorControl_move_to_floor(elevator_control->Elevator, elevator_control->q_system, elevator_control->q_system->target_floor);
}