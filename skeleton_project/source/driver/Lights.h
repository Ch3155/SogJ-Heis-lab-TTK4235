struct Lights {
    bool BTN_FLR_4_DWN;
    bool BTN_FLR_3_DWN;
    bool BTN_FLR_3_UP;
    bool BTN_FLR_2_DWN;
    bool BTN_FLR_2_UP;
    bool BTN_FLR_1_UP;

    bool doorOpenLamp;
    bool stopLamp;

    bool floorLamp;
};


struct Lights* Lights_init();
void Lights_update(struct Lights* lights);










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