#include <q_system.h>


void q_system_empty_q(struct Q_system *q) {
    for (int i = 0; i < 4; i++) {
        q->q_down[i] = 0;
        q->q_up[i] = 0;
    };
}

void q_system_remove_FLR(struct Q_system *q, struct Elevator *elevator) {
    if (elevator->current_floor == 0) {
        elevator.BTN_1 = 0;
        BTN_FLR_4_DWN = 0;
    }
}


void q_system_make_q(struct Q_system *q, struct Elevator elevator) {
    //Bestillinger nedover
    if (BTN_FLR_2_DWN == true) {
        q->q_down[1] = 1;
    };
    if (BTN_FLR_3_DWN == true) {
        q->q_down[2] = 1;
    };
    if (BTN_FLR_4_DWN == true) {
        q->q_down[3] = 1;
    };

    //Bestillinger oppover
    if (BTN_FLR_1_UP == true) {
        q->q_down[0] = 1;
    };
    if (BTN_FLR_2_UP == true) {
        q->q_down[1] = 1;
    };
    if (BTN_FLR_3_UP == true) {
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
