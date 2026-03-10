#include "Elevator.h"
#include "MotorControl.h"
#include "q_system.h"
#include "elevio.h"
#include <stdbool.h>
#include "floorpanel.h"
#include "ElevatorControl.h"
#include "Lights.h"
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
    bool reverse_motor = false;
    while (1)
    {
/* 
    if(elevio_stopButton() ){
        elevio_motorDirection(DIRN_STOP);
        break;
    } */



    
    
    switch (Current_state)
    {
    case StartUp:
        printf("Starting up...\n");
        int temp_counter=0;

        if (elevio_obstruction() == true && elevator_control->Elevator->door_is_open == true){
            while (1){
            
            if (elevio_obstruction() == false){
                temp_counter++;
            } else {
                temp_counter=0;
            }

            if (temp_counter >= 300){
                break;
            }
            nanosleep(&(struct timespec){0, 10*1000*1000}, NULL);
            }
        }
        elevator_control->Elevator->door_is_open = false;
        elevio_doorOpenLamp(false);
        Lights_turn_all_lights_off();   
        while (elevator_control->Elevator->is_between_floors==true)
        {
            elevio_motorDirection(DIRN_DOWN);
            Elevator_update(elevator_control->Elevator);
        }
        elevio_motorDirection(DIRN_STOP);
        
        Current_state = Idle;

        break;


    case Idle:
        printf("Idle... Target_floor = %d\n", target_floor);

        if (elevio_stopButton()){
            Current_state = EmergencyStop;
            break;
        }

        Elevator_update(elevator_control->Elevator);
        Floorpanel_update(elevator_control->floorpanel);
        Lights_update(*elevator_control->floorpanel, *elevator_control->Elevator);
        q_system_make_q(elevator_control->q_system, *elevator_control->Elevator, *elevator_control->floorpanel);
        target_floor = q_system_get_target_floor(*elevator_control->q_system, *elevator_control->Elevator);
        if (target_floor != -1) {
            Current_state = Moving;
        }
    

        break; 
    
    case Moving:
        printf("Moving...\n");

        if (elevio_stopButton()){
            Current_state = EmergencyStop;
            break;
        }

        Elevator_update(elevator_control->Elevator);
        Floorpanel_update(elevator_control->floorpanel);
        Lights_update(*elevator_control->floorpanel, *elevator_control->Elevator);
        q_system_make_q(elevator_control->q_system, *elevator_control->Elevator, *elevator_control->floorpanel);
        target_floor = q_system_get_target_floor(*elevator_control->q_system, *elevator_control->Elevator);
        printf("Target floor: %d\n", target_floor);


        if (target_floor > elevator_control->Elevator->current_floor || (reverse_motor == true && target_floor == elevator_control->Elevator->current_floor && elevator_control->Elevator->cur_dir == DIRN_DOWN)){
            printf("Going up...\n");
            elevator_control->Elevator->cur_dir = DIRN_UP;
            elevator_control->Elevator->is_moving = true;
            elevio_motorDirection(elevator_control->Elevator->cur_dir);
            reverse_motor = false;
        } else if (target_floor < elevator_control->Elevator->current_floor || (reverse_motor == true && target_floor == elevator_control->Elevator->current_floor && elevator_control->Elevator->cur_dir == DIRN_UP)){
            printf("Going down...\n");
            elevator_control->Elevator->cur_dir = DIRN_DOWN;
            elevator_control->Elevator->is_moving = true;
            elevio_motorDirection(elevator_control->Elevator->cur_dir);
            reverse_motor = false;
        } else if (target_floor == elevator_control->Elevator->current_floor && elevator_control->Elevator->is_between_floors == false){
            printf("Arrived at target floor...\n");
            MotorControl_stop_elevator(elevator_control->Elevator);
            elevator_control->Elevator->is_moving = false;

            q_system_remove_FLR(elevator_control->q_system, elevator_control->Elevator);
            Lights_remove_lights(*elevator_control->Elevator);
            Elevator_update(elevator_control->Elevator);
            Floorpanel_update(elevator_control->floorpanel);
            Lights_remove_lights(*elevator_control->Elevator);

            Elevator_set_door(elevator_control->Elevator, true, elevator_control->floorpanel, elevator_control->q_system);
            Lights_update(*elevator_control->floorpanel, *elevator_control->Elevator);
            Elevator_set_door(elevator_control->Elevator, false, elevator_control->floorpanel, elevator_control->q_system);
            Lights_update(*elevator_control->floorpanel, *elevator_control->Elevator);
            Lights_remove_lights(*elevator_control->Elevator);
            Current_state = Idle;
        } else if (target_floor == elevator_control->Elevator->current_floor && elevator_control->Elevator->cur_dir == DIRN_DOWN) {
            printf("Going up... (after emergency)\n");
            elevator_control->Elevator->cur_dir = DIRN_UP;
            elevator_control->Elevator->is_moving = true;
            elevio_motorDirection(elevator_control->Elevator->cur_dir);
        } else if (target_floor == elevator_control->Elevator->current_floor && elevator_control->Elevator->cur_dir == DIRN_UP) {
            printf("Going down... (after emergency)\n");
            elevator_control->Elevator->cur_dir = DIRN_DOWN;
            elevator_control->Elevator->is_moving = true;
            elevio_motorDirection(elevator_control->Elevator->cur_dir);
        }
        
        


        break;
        
    case EmergencyStop:
        printf("Emergency stop...\n");
        reverse_motor = true;
        MotorControl_stop_elevator(elevator_control->Elevator);
        q_system_empty_q(elevator_control->q_system);
        Lights_turn_all_lights_off();

        if (elevator_control->Elevator->is_between_floors == false){
            elevator_control->Elevator->door_is_open = true;
            elevio_doorOpenLamp(true);
        }

        while (elevio_stopButton())
        {
            nanosleep(&(struct timespec){0, 300*1000*1000}, NULL);
        }

        Elevator_set_door(elevator_control->Elevator, false, elevator_control->floorpanel, elevator_control->q_system);


        Current_state=Idle;
        
        break;  
        
    }
    nanosleep(&(struct timespec){0, 10*1000*1000}, NULL);
}

ElevatorControl_destroy(elevator_control);
}