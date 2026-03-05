#include "Elevator.h"
#include "elevio.h"
#include <time.h>





void Elevator_set_door(struct Elevator* Elevator, bool value){

    while (1)
    {

    
    if (elevio_obstruction() == false){
        Elevator->door_is_open = value;
        return;
    } else {
        nanosleep(&(struct timespec){0, 3*1e9}, NULL);
    }

    }
    
    
}

struct Elevator* Elevator_init(){
    struct Elevator* Elevator;
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

    //Update Floor button states
    for (int floor = 0; floor < N_FLOORS; floor++){
       switch (floor){
        bool Button_state = elevio_callButton(floor, BUTTON_CAB);
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