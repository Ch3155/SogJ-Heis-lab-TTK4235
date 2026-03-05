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

    while (1)
    {

    
    switch (Current_state)
    {
    case StartUp:
        
        if (elevator_control->Elevator->is_between_floors==false) {
            Current_state = Idle;
        } else {
            Elevator_set_door(elevator_control->Elevator, false);
            elevio_motorDirection(DIRN_DOWN);
        }
            


        break;


    case Idle:
        Elevator_set_door(elevator_control->Elevator, false);    

        break; 
    
    case Moving:
        
    case EmergencyStop:
        /* code */
        break;  
        
    }
}
}