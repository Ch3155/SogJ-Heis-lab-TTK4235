#pragma once
#include "elevio.h"

struct Floorpanel;
struct Elevator;
//Trenger vi disse boolsa eller trenger vi bare å sjekke fra floorpanel også sette lysene høyt etter dem?
//Så kan vi skru av lys når vi ankommer etasjer/ stoppknappen trykkes

//Oppdaterer alle lys
void Lights_init();

//Skrur på aktuelle lys
void Lights_update(struct Floorpanel floorpanel, struct Elevator elevator);

//Fjerner lys i etasjen man ankommer
void Lights_remove_lights(struct Elevator elevator);

//Skrur av alle lys i tilfelle stopp (untatt stoppknappen)
void Lights_turn_all_lights_off();

