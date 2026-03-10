#pragma once
//#include "Elevator.h"
#include <stdbool.h>

struct Elevator;
struct Floorpanel;

struct Q_system {
    int q_up[4]; //Liste over bestillinger opp
    int q_down[4]; //Liste over bestillinger ned
};

//Funksjon som initialiserer tomme køer
void q_system_initialize_q(struct Q_system *q);

//Funksjon som setter alle bestillinger til 0
//For når stopp-knapp trykkes
void q_system_empty_q(struct Q_system *q);

//Funksjon som setter alle bestillinger i en etasje til 0
//For når heisen ankommer en etasje
void q_system_remove_FLR(struct Q_system *q, struct Elevator *elevator);

//Funksjon som setter bestillinger til 1
void q_system_make_q(struct Q_system *q, struct Elevator elevator, struct Floorpanel floorpanel);

//Funksjon som ser på køen og gir ut neste måletasje
int q_system_get_target_floor(struct Q_system q, struct Elevator elevator);