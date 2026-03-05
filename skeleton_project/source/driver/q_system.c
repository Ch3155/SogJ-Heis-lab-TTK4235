#include "q_system.h"


void q_system_empty_q(struct Q_system *q) {
    for (int i = 0; i < 4; i++) {
        q->q_down[i] = 0;
        q->q_up[i] = 0;
    };
}

void q_system_remove_FLR(struct Q_system *q, struct Elevator *elevator, struct Floorpanel *floorpanel) {
    if (elevator->current_floor == 0) {
        elevator->BTN_1 = 0;
        floorpanel->BTN_FLR_1_UP = 0;
    } else if (elevator->current_floor == 1) {
        elevator->BTN_2 = 0;
        floorpanel->BTN_FLR_2_UP = 0;
        floorpanel->BTN_FLR_2_DWN = 0;
    } else if (elevator->current_floor == 2) {
        elevator->BTN_3 = 0;
        floorpanel->BTN_FLR_3_UP = 0;
        floorpanel->BTN_FLR_3_DWN = 0;
    } else if (elevator->current_floor == 3) {
        elevator->BTN_4 = 0;
        floorpanel->BTN_FLR_4_DWN = 0;
    }
}


void q_system_make_q(struct Q_system *q, struct Elevator elevator, struct Floorpanel floorpanel) {
    //Bestillinger nedover
    if (floorpanel.BTN_FLR_2_DWN == true) {
        q->q_down[1] = 1;
    };
    if (floorpanel.BTN_FLR_3_DWN == true) {
        q->q_down[2] = 1;
    };
    if (floorpanel.BTN_FLR_4_DWN == true) {
        q->q_down[3] = 1;
    };

    //Bestillinger oppover
    if (floorpanel.BTN_FLR_1_UP == true) {
        q->q_down[0] = 1;
    };
    if (floorpanel.BTN_FLR_2_UP == true) {
        q->q_down[1] = 1;
    };
    if (floorpanel.BTN_FLR_3_UP == true) {
        q->q_down[2] = 1;
    };

    //Fiks for knappene inne i heisen
    if (elevator.BTN_4 == true) {
        if (elevator.current_floor < 3) { //Hvis man skal til fjerde etasje fra en lavere etasje
            q->q_up[3] = 1;
        }
    }
    if (elevator.BTN_3 == true) {
        if (elevator.current_floor < 2) { //Hvis man skal til tredje etasje fra en lavere etasje
            q->q_up[2] = 1;
        } else if (elevator.current_floor > 2) { //Hvis man skal til tredje etasje fra en høyere etasje
            q->q_down[2] = 1;
        }
    }
    if (elevator.BTN_2 == true) {
        if (elevator.current_floor < 1) { //Hvis man skal til andre etasje fra en lavere etasje
            q->q_up[1] = 1;
        } else if (elevator.current_floor > 1) { //Hvis man skal til andre etasje fra en høyere etasje
            q->q_down[1] = 1;
        }
    }
    if (elevator.BTN_1 == true) {
        if (elevator.current_floor > 0) { //Hvis man skal til første etasje fra en høyere etasje
            q->q_down[0] = 1;
        }
    }
}


int q_system_get_target_floor(struct Q_system q, struct Elevator elevator) {
    switch (elevator.cur_dir) {
        case -1: //Heisen beveger seg nedover
            //Sjekk hvor vi er og ta neste i rekken som er i kø
            for (int i = elevator.current_floor; i = 0; i--) {
                if (q.q_down[i] == 1) { //Sjekker om etasjen er i heissystemet
                    return i; //Hvis den er der returneres etasjen
                }
            }
            break;
        case 1: //Heisen beveger seg oppover
            for (int i = elevator.current_floor; i = 3; i++) {
                if (q.q_up[i] == 1) {
                    return i;
                }
            }
            break;
        case 0: //Heisen står stille
            //Sjekker køen ned
            for (int i = elevator.current_floor; i = 0; i--) {
                if (q.q_down[i] == 1) { //Sjekker om etasjen er i heissystemet
                    return i; //Hvis den er der returneres etasjen
                }
            }
            //Sjekker køen opp
            for (int i = elevator.current_floor; i = 3; i++) {
                if (q.q_up[i] == 1) {
                    return i;
                }
            }
            break;
    }
    return -1; //Heisen fant ikke noe måletasje 
}