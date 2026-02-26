#include <q_system.h>


void q_system_empty_q(struct Q_system *q) {
    for (int i = 0; i < 4; i++) {
        q->q_down[i] = 0;
        q->q_up[i] = 0;
    };
}

void q_system_make_q(struct Q_system *q) {
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
    
}
