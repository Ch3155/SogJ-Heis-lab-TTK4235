#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"
#include "ElevatorControl.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct ElevatorControl* ElevatorControl_init(){
    struct ElevatorControl* elevator_control = malloc(sizeof(struct ElevatorControl));
    
    elevator_control->Elevator = Elevator_init();
    elevator_control->floorpanel = Floorpanel_init();
    elevator_control->q_system = malloc(sizeof(struct Q_system));
    q_system_empty_q(elevator_control->q_system);
    return elevator_control;
}

void ElevatorControl_destroy(struct ElevatorControl* elevator_control){
    free(elevator_control->Elevator);
    free(elevator_control->floorpanel);
    free(elevator_control->q_system);
    free(elevator_control);
}

void ElevatorControl_run(struct ElevatorControl* elevator_control){
    
    Elevator_update(elevator_control->Elevator);
    Floorpanel_update(elevator_control->floorpanel);
    q_system_make_q(elevator_control->q_system, *elevator_control->Elevator, *elevator_control->floorpanel);



    States Current_state = StartUp;
    int target_floor=-1;
    while (1)
    {

    if(elevio_stopButton()){
        elevio_motorDirection(DIRN_STOP);
        break;
    }



    
    
    switch (Current_state)
    {
    case StartUp:
        printf("Starting up...\n");
        Elevator_set_door(elevator_control->Elevator, false);    
        while (elevator_control->Elevator->is_between_floors==true)
        {
            elevio_motorDirection(DIRN_DOWN);
            Elevator_update(elevator_control->Elevator);
        }
        elevio_motorDirection(DIRN_STOP);
        Current_state = Idle;
        
            


        break;


    case Idle:
           

        break; 
    
    case Moving:
        printf("Moving...\n");

        break;
        
    case EmergencyStop:
        /* code */
        break;  
        
    }
}

ElevatorControl_destroy(elevator_control);
}