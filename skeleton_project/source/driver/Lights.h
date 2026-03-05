#pragma once
#include "Elevator.h"
#include "floorpanel.h"

//Trenger vi disse boolsa eller trenger vi bare å sjekke fra floorpanel også sette lysene høyt etter dem?
//Så kan vi skru av lys når vi ankommer etasjer/ stoppknappen trykkes
struct Lights {
    bool BTN_FLR_4_DWN;
    bool BTN_FLR_3_DWN;
    bool BTN_FLR_3_UP;
    bool BTN_FLR_2_DWN;
    bool BTN_FLR_2_UP;
    bool BTN_FLR_1_UP;

    bool doorOpenLamp;
    bool stopLamp;

    bool floorLamp_1;
    bool floorLamp_2;
    bool floorLamp_3;
    bool floorLamp_4;

    bool BTN_1;
    bool BTN_2;
    bool BTN_3;
    bool BTN_4;
};

//Oppdaterer alle lys
struct Lights* Lights_init();

//Skrur på aktuelle lys
void Lights_update(struct Lights* lights, struct Floorpanel floorpanel);

//Fjerner lys i etasjen man ankommer
void Lights_remove_lights(struct Lights* lights, struct Elevator elevator);

//Skrur av alle lys i tilfelle stopp
void Lights_turn_all_lights_off();

