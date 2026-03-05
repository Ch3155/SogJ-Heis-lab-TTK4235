#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"
#include "ElevatorControl.h"
#include <time.h>

struct ElevatorControl* ElevatorControl_init(){
    struct ElevatorControl* elevator_control;
    elevator_control->Elevator = Elevator_init();
    Floorpanel_update(elevator_control->floorpanel);;
    q_system_empty_q(elevator_control->q_system);
    return elevator_control;
}

void ElevatorControl_run(struct ElevatorControl* elevator_control){
    
    Elevator_update(elevator_control->Elevator);
    Floorpanel_update(elevator_control->floorpanel);
    q_system_make_q(elevator_control->q_system, *elevator_control->Elevator, *elevator_control->floorpanel);



    States Current_state = StartUp;

    switch (Current_state)
    {
    case StartUp:
        if (elevator_control->Elevator->current_floor == -1) {
            Current_state = Idle;
        } else {
            Current_state = Moving;
        }    


        break;
    case Idle:
        /* code */
        break; 
    case Moving:
        /* code */
    case EmergencyStop:
        /* code */
        break;  
        
    }