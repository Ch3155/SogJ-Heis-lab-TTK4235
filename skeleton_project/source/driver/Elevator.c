#include "Elevator.h"
#include "elevio.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "floorpanel.h"



void Elevator_set_door(struct Elevator* Elevator, bool value, struct Floorpanel* floorpanel, struct Q_system* q_system){
    int temp_counter=0;

    if (value == false) {
        while (1){
        
        if (elevio_obstruction() == false){
            temp_counter++;
        } else {
            temp_counter=0;
        }

        if (temp_counter >= 300){
            break;
        }
        Floorpanel_update(floorpanel);
        Elevator_update(Elevator);
        q_system_make_q(q_system, *Elevator, *floorpanel);
        Lights_update(*floorpanel, *Elevator);
        nanosleep(&(struct timespec){0, 10*1000*1000}, NULL);
        }
    }
    Elevator->door_is_open = value;
    elevio_doorOpenLamp(value);

    }    



struct Elevator* Elevator_init(){
    struct Elevator* Elevator = malloc(sizeof(struct Elevator));
    //Initialize the elevator state
    elevio_doorOpenLamp(0);
    Elevator->door_is_open = false;
    Elevator->current_floor = elevio_floorSensor();
    if (Elevator->current_floor == -1){
        Elevator->is_between_floors = true;
    } else {
        Elevator->is_between_floors = false;
    }

    Elevator->stop_button_pressed=elevio_stopButton();
    Elevator->cur_dir=DIRN_STOP;
    return Elevator;
}

void Elevator_update(struct Elevator* Elevator){
    //Update current floor and between floors status
    if (elevio_floorSensor() != -1){
        Elevator->current_floor = elevio_floorSensor();
        Elevator->is_between_floors = false;
    } else {
        Elevator->is_between_floors = true;
    }


    Elevator->stop_button_pressed = elevio_stopButton();
    bool Button_state = 0;
    //Update Floor button states
    for (int floor = 0; floor < N_FLOORS; floor++){
        Button_state = elevio_callButton(floor, BUTTON_CAB);
       switch (floor){
        
                    case 0:
                        Elevator->BTN_1 = Button_state;
                        break;
                    case 1:
                        Elevator->BTN_2 = Button_state;
                        break;
                    case 2:
                        Elevator->BTN_3 = Button_state;
                        break;
                    case 3:
                        Elevator->BTN_4 = Button_state;
                        break;
        }
    }

    Elevator->stop_button_pressed = elevio_stopButton();

}