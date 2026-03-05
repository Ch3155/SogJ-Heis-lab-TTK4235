#include "Lights.h"

struct Lights* Lights_init(){
    struct Lights* lights;
    lights->BTN_FLR_4_DWN = false;
    lights->BTN_FLR_3_DWN = false;
    lights->BTN_FLR_3_UP = false;
    lights->BTN_FLR_2_DWN = false;
    lights->BTN_FLR_2_UP = false;
    lights->BTN_FLR_1_UP = false;

    lights->doorOpenLamp = false;
    lights->stopLamp = false;

    lights->floor1Lamp = false;
    lights->floor2Lamp = false;
    lights->floor3Lamp = false;
    lights->floor4Lamp = false;

    lights->btn1Lamp = false;
    lights->btn2Lamp = false;
    lights->btn3Lamp = false;
    lights->btn4Lamp = false;

    return lights;
}

void Lights_update(struct Lights* lights, struct Elevator elevator, struct Floorpanel floorpanel) {

}