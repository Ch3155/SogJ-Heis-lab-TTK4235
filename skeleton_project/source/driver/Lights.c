#include "Lights.h"


struct Lights* Lights_init() {
    struct Lights* lights;
    //Initialiserer alle verdiene
    
    //Bestillingsknappene
    lights->BTN_FLR_1_UP = 0;
    lights->BTN_FLR_2_UP = 0;
    lights->BTN_FLR_2_DWN = 0;
    lights->BTN_FLR_3_UP = 0;
    lights->BTN_FLR_3_DWN = 0;
    lights->BTN_FLR_4_DWN = 0;

    //Etasjelysene
    lights->floorLamp_1 = 0;
    lights->floorLamp_2 = 0;
    lights->floorLamp_3 = 0;
    lights->floorLamp_4 = 0;

    //Panellysene
    lights->BTN_1 = 0;
    lights->BTN_2 = 0;
    lights->BTN_3 = 0;
    lights->BTN_4 = 0;

    //Dør åpen lys
    lights->doorOpenLamp = 0;

    //Stopplys
    lights->stopLamp = 0;

    return lights;
}



void Lights_update(struct Lights* lights, struct Floorpanel floorpanel) {
    if (floorpanel.BTN_FLR_1_UP == 1) {
        lights->BTN_FLR_1_UP =
    }
}


void Lights_remove_lights(struct Lights* lights, struct Elevator elevator) {
    if (elevator.current_floor == 0) {
        lights->BTN_FLR_1_UP = 0;
        lights->BTN_1 = 0;
    } else if (elevator.current_floor == 1) {
        lights->BTN_2 = 0;
        lights->BTN_FLR_2_UP = 0;
        lights->BTN_FLR_2_DWN = 0;
    } else if (elevator.current_floor == 2) {
        lights->BTN_3 = 0;
        lights->BTN_FLR_3_UP = 0;
        lights->BTN_FLR_3_DWN = 0;
    } else if (elevator.current_floor == 3) {
        lights->BTN_4 = 0;
        lights->BTN_FLR_4_DWN = 0;
    }
}
