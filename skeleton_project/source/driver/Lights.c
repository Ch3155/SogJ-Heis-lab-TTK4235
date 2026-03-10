#include "Lights.h"
#include "Elevator.h"
#include "floorpanel.h"


void Lights_init() {
    //Bestillingsknapp
    elevio_buttonLamp(0, BUTTON_HALL_UP, 0); //Setter bestillingsknapplys i første etasje til 0, altså av
    elevio_buttonLamp(1, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);

    //Etasjelysene settes med elevio_floorIndicator(int floor);

    //Panellysene
    elevio_buttonLamp(0, BUTTON_CAB, 0);
    elevio_buttonLamp(1, BUTTON_CAB, 0);
    elevio_buttonLamp(2, BUTTON_CAB, 0);
    elevio_buttonLamp(3, BUTTON_CAB, 0);

    //Dør åpen lys
    elevio_doorOpenLamp(0);

    //Stopplys
    elevio_stopLamp(0);
}



void Lights_update(struct Floorpanel floorpanel, struct Elevator elevator) {
    //Bestillingsknappene oppover
    if (floorpanel.BTN_FLR_1_UP == true) {
        elevio_buttonLamp(0, BUTTON_HALL_UP, 1);
    }
    if (floorpanel.BTN_FLR_2_UP == true) {
        elevio_buttonLamp(1, BUTTON_HALL_UP, 1);
    }
    if (floorpanel.BTN_FLR_3_UP == true) {
        elevio_buttonLamp(2, BUTTON_HALL_UP, 1);
    }

    //Bestillingsknappene nedover
    if (floorpanel.BTN_FLR_2_DWN == true) {
        elevio_buttonLamp(1, BUTTON_HALL_DOWN, 1);
    }
    if (floorpanel.BTN_FLR_3_DWN == true) {
        elevio_buttonLamp(2, BUTTON_HALL_DOWN, 1);
    }
    if (floorpanel.BTN_FLR_4_DWN == true) {
        elevio_buttonLamp(3, BUTTON_HALL_DOWN, 1);
    }
    
    //Panellysene
    if (elevator.BTN_4 == true) {
        elevio_buttonLamp(3, BUTTON_CAB, 1);
    }
    if (elevator.BTN_3 == true) {
        elevio_buttonLamp(2, BUTTON_CAB, 1);
    }
    if (elevator.BTN_2 == true) {
        elevio_buttonLamp(1, BUTTON_CAB, 1);
    }
    if (elevator.BTN_1 == true) {
        elevio_buttonLamp(0, BUTTON_CAB, 1);
    }

    //Setter etasjeindikator
    elevio_floorIndicator(elevator.current_floor);

    //Dør åpen
    elevio_doorOpenLamp(elevator.door_is_open);

    //Stoppknapp
    elevio_stopLamp(elevator.stop_button_pressed);
}


void Lights_remove_lights(struct Elevator elevator) {
    if (elevator.current_floor == 0) {
        elevio_buttonLamp(0, BUTTON_CAB, 0);
        elevio_buttonLamp(0, BUTTON_HALL_UP, 0);
    } else if (elevator.current_floor == 1) {
        elevio_buttonLamp(1, BUTTON_CAB, 0);
        elevio_buttonLamp(1, BUTTON_HALL_DOWN, 0);
        elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
    } else if (elevator.current_floor == 2) {
        elevio_buttonLamp(2, BUTTON_CAB, 0);
        elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
        elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
    } else if (elevator.current_floor == 3) {
        elevio_buttonLamp(3, BUTTON_CAB, 0);
        elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);
    }
}

void Lights_turn_all_lights_off() {
    //Bestillingsknapp
    elevio_buttonLamp(0, BUTTON_HALL_UP, 0); //Setter bestillingsknapplys i første etasje til 0, altså av
    elevio_buttonLamp(1, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);

    //Etasjelysene settes med elevio_floorIndicator(int floor);

    //Panellysene
    elevio_buttonLamp(0, BUTTON_CAB, 0);
    elevio_buttonLamp(1, BUTTON_CAB, 0);
    elevio_buttonLamp(2, BUTTON_CAB, 0);
    elevio_buttonLamp(3, BUTTON_CAB, 0);

    //Dør åpen lys
    elevio_doorOpenLamp(0);
}
